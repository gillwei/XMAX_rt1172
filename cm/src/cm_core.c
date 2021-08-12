/*********************************************************************
* @file  cm_core.c
* @brief Connection Manager General Core interface definition.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <stdarg.h>
#include <stdio.h>
#include <FreeRTOS.h>
#include <timers.h>
#include "fsl_debug_console.h"

#include "cm_types.h"
#include "CM_pub.h"
#include "cm_prv.h"
#include "cm_log.h"
#include "cm_auto_connect.h"

#include "BT_pub.h"
#include "bt_types.h"
#include "EW_pub.h"
#include "Enum.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/
#define CM_LOG_BUF_SIZE ( 150 )

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define CM_CORE_TIMER_PERIOD_MS            1000
#define CM_CORE_TICK_PERIOD_MS             pdMS_TO_TICKS( CM_CORE_TIMER_PERIOD_MS )
#define CONNECTION_FAIL_TIMEOUT_PERIOD_MS  ( 20000 / CM_CORE_TICK_PERIOD_MS )

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/


/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/


/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
static CM_connect_device_status_t     cm_connect_device;
static CM_connect_result_t            CM_connect_result;
static uint8_t                        cm_connecting_request_count = 0;
static bool                           connecting_notify_ready = false;
static uint16_t                       cm_core_timeout_count = 0;
static cm_core_timeout_type_t         cm_core_timeout_type = CM_CORE_TIMEOUT_IDLE;
static TimerHandle_t                  cm_core_timeout_timer_handle;
static uint8_t                        cm_stored_ccuid[CCUID_LENGTH + 1] = { 0 };

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/
static void CM_core_start_timeout_timer
    (
    cm_core_timeout_type_t  input_cm_core_timeout_type
    );

static void CM_core_stop_timeout_timer
    (
    void
    );

static void CM_core_timeout_timer_callback
    (
    TimerHandle_t timer_handle
    );

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Connection Manager variable initialization
@details Connection Manager variable initialization
@return  None
@retval  None
================================================================================================*/
void CM_core_init( void )
{
// Initialize CM core variable
memset( cm_connect_device.bd_addr, BT_DEVICE_NAME_LEN, 0 );
cm_connect_device.navi_app_connection_status = CM_NAVI_APP_CONNECTION_DISCONNECTED;
cm_connect_device.yconnect_app_connection_status = CM_YCONNECT_APP_CONNECTION_DISCONNECTED;

CM_connect_result.can_notify_UI = false;
CM_connect_result.navi_connect_result = false;
CM_connect_result.yconnect_connect_result = false;

memcpy( cm_stored_ccuid, TEST_CCUID, CCUID_LENGTH );

cm_core_timeout_timer_handle = xTimerCreate( "cm_core_timeout_timer", CM_CORE_TICK_PERIOD_MS, pdTRUE, ( void * ) 0, CM_core_timeout_timer_callback );
configASSERT( NULL != cm_core_timeout_timer_handle );
}

/*================================================================================================
@brief   CM core start timeout timer
@details CM core start timeout timer
@return  None
@retval  None
================================================================================================*/
void CM_core_start_timeout_timer
    (
    cm_core_timeout_type_t  input_cm_core_timeout_type
    )
{
cm_core_timeout_type = input_cm_core_timeout_type;
BaseType_t result = xTimerStart( cm_core_timeout_timer_handle, 0 );
configASSERT( result == pdPASS );
}

/*================================================================================================
@brief   CM core stop timeout timer
@details CM core stop timeout timer
@return  None
@retval  None
================================================================================================*/
void CM_core_stop_timeout_timer
    (
    void
    )
{
BaseType_t result = xTimerStop( cm_core_timeout_timer_handle, 0 );
cm_core_timeout_count = 0;
cm_core_timeout_type = CM_CORE_TIMEOUT_IDLE;
configASSERT( result == pdPASS );
}

/*================================================================================================
@brief   CM core timeout callback
@details Count CM core timer and trigger event timeout
@return  None
@retval  None
================================================================================================*/
void CM_core_timeout_timer_callback
    (
    TimerHandle_t timer_handle
    )
{
switch( cm_core_timeout_type )
    {
    /* Connection fail timeout event  */
    case CM_CORE_TIMEOUT_CONNECTION_FAIL:
        if( cm_core_timeout_count > CONNECTION_FAIL_TIMEOUT_PERIOD_MS )
            {
            CM_LOG_DEBUG( "CM_CORE_TIMEOUT_CONNECTION_FAIL" );
            CM_core_stop_timeout_timer();
            EW_notify_connection_status( EnumConnectionStatusCONNECTION_FAILED );
            }
        break;

    default:
        break;
    }
cm_core_timeout_count ++;
}

/*================================================================================================
@brief   Connection Manager variable initialization
@details Connection Manager variable initialization
@return  None
@retval  None
================================================================================================*/
bool CM_core_spp_connect
    (
    const uint8_t* bd_addr
    )
{
BT_status_e BT_navi_connect_result;
BT_status_e BT_yconnect_connect_result;

CM_LOG_DEBUG( "bd_addr:" );
for( int i=0;i<6;i++ )
{
CM_LOG_DEBUG( "%02x", bd_addr[i] );
}

// Trigger only when navi spp disconnected and motocon spp disconnected
if( ( CM_NAVI_APP_CONNECTION_DISCONNECTED == cm_connect_device.navi_app_connection_status ) && ( CM_YCONNECT_APP_CONNECTION_DISCONNECTED == cm_connect_device.yconnect_app_connection_status ) )
    {
    // Connect Navi APP
    BT_navi_connect_result = BT_spp_connect( bd_addr, BT_SPP_APP_NAVILITE);
    if( BT_STATUS_OK == BT_navi_connect_result )
        {
        // Start connection fail timeout event
        CM_core_start_timeout_timer( CM_CORE_TIMEOUT_CONNECTION_FAIL );

        cm_connect_device.navi_app_connection_status = CM_NAVI_APP_CONNECTION_CONNECTING;
        cm_connecting_request_count++;
        // Connect Yconnect APP
        BT_yconnect_connect_result = BT_spp_connect( bd_addr, BT_SPP_APP_MOTOCON);
        if( BT_STATUS_OK ==  BT_yconnect_connect_result )
            {
            cm_connect_device.yconnect_app_connection_status = CM_YCONNECT_APP_CONNECTION_CONNECTING;
            cm_connecting_request_count++;
            }
        else if( BT_STATUS_AUTH_LOST ==  BT_yconnect_connect_result )
            {
            EW_notify_connection_status(EnumConnectionStatusAUTHENTICATION_ERR );
            }
        else
            {
            }

        }
    // Connect navi is authentication error
    else if( BT_STATUS_AUTH_LOST == BT_navi_connect_result )
        {
        EW_notify_connection_status(EnumConnectionStatusAUTHENTICATION_ERR );
        }
    // BT manager return other error
    else
        {
        }
    // If send any connect request, return true
    return true;
    }
return false;
}

/*================================================================================================
@brief   Disconnect the SPP app from the remote device
@details Send the HCI command of disconnecting the SPP app from the remote device to Cypress module
@return  None
@retval  None
================================================================================================*/
bool CM_core_spp_disconnect
    (
    const uint8_t* bd_addr
    )
{
CM_LOG_DEBUG( "disconnect bd_addr:" );
    for( int i=0;i<6;i++ )
    {
    CM_LOG_DEBUG( "%02x", bd_addr[i] );
    }
if( CM_NAVI_APP_CONNECTION_CONNECTED == cm_connect_device.navi_app_connection_status )
    {
    BT_spp_disconnect( bd_addr, BT_SPP_APP_NAVILITE );
    }
if( CM_YCONNECT_APP_CONNECTION_CONNECTED == cm_connect_device.yconnect_app_connection_status || CM_YCONNECT_APP_CONNECTION_AUTHENTICATED == cm_connect_device.yconnect_app_connection_status )
    {
    BT_spp_disconnect( bd_addr, BT_SPP_APP_MOTOCON );
    }

return true;
}

/*================================================================================================
@brief   Get SPP connection status
@details For HMI get spp connection status
@return  None
@retval  Return SPP connection status for different APP
================================================================================================*/
bool CM_core_get_spp_connection_status
    (
    const CM_app_type_e app_type
    )
{
if( CM_APP_NAVILITE == app_type )
    {
    if( CM_NAVI_APP_CONNECTION_CONNECTED == cm_connect_device.navi_app_connection_status )
        {
        return true;
        }
    else
        {
        return false;
        }
    }
if( CM_APP_YCONNECT == app_type )
    {
    if( CM_YCONNECT_APP_CONNECTION_CONNECTED == cm_connect_device.yconnect_app_connection_status || CM_YCONNECT_APP_CONNECTION_AUTHENTICATED == cm_connect_device.yconnect_app_connection_status )
        {
        return true;
        }
    else
        {
        return false;
        }
    }
return false;
}

/*================================================================================================
@brief   Handle the HMI notify CCUID
@details Handle the HMI notify CCUID
@return  None
@retval  None
================================================================================================*/
void CM_core_handle_hmi_ccuid_ready
    (
    const uint8_t *ccuid
    )
{
memcpy( cm_stored_ccuid, ccuid, CCUID_LENGTH );
}

/*================================================================================================
@brief   Get APP connection status
@details For HMI get app connection status, return true only if the yconnect authentication is done
@return  None
@retval  Return APP connection status for different APP
================================================================================================*/
bool CM_core_get_app_connection_status
    (
    const CM_app_type_e app_type,
    const uint8_t* bd_addr
    )
{
// Request device status is differ from connected device
if( memcmp( cm_connect_device.bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN ) )
    {
    return false;
    }

if( CM_APP_NAVILITE == app_type )
    {
    // Since the Navi APP authentication is not ready
    if( CM_NAVI_APP_CONNECTION_CONNECTED == cm_connect_device.navi_app_connection_status || CM_NAVI_APP_CONNECTION_AUTHENTICATED == cm_connect_device.navi_app_connection_status )
        {
        return true;
        }
    else
        {
        return false;
        }
    }
if( CM_APP_YCONNECT == app_type )
    {
    if( CM_YCONNECT_APP_CONNECTION_AUTHENTICATED == cm_connect_device.yconnect_app_connection_status )
        {
        return true;
        }
    else
        {
        return false;
        }
    }
return false;
}

/*================================================================================================
@brief   Core handle pairing result
@details Get the btmgr pairing result
@return  None
@retval  None
================================================================================================*/
void CM_core_handle_btmgr_pairing_result
    (
    const CM_btmgr_pairing_result_t *CM_btmgr_pairing_result
    )
{
if( false == CM_btmgr_pairing_result->pairing_result )
    {
    EW_notify_connection_status(EnumConnectionStatusPAIRING_FAILED );
    }
}

/*================================================================================================
@brief   Core handle handle spp connection status
@details For APP connect to LC case,  notify HMI directly
         For LC connect APP case, after receive the second APP connection result, notify to HMI
@return  None
@retval
================================================================================================*/
void CM_core_handle_btmgr_spp_connection_status_changed
    (
    const CM_connection_status_change_t *CM_connection_status_change
    )
{
// If connected device changed, modify address and reset connection status
if( memcmp( cm_connect_device.bd_addr, CM_connection_status_change->bd_addr, BT_DEVICE_ADDRESS_LEN ) )
    {
    CM_LOG_DEBUG( "connected device changed" );
    memcpy( cm_connect_device.bd_addr, CM_connection_status_change->bd_addr, BT_DEVICE_ADDRESS_LEN );
    cm_connect_device.navi_app_connection_status = CM_NAVI_APP_CONNECTION_DISCONNECTED;
    cm_connect_device.yconnect_app_connection_status = CM_YCONNECT_APP_CONNECTION_DISCONNECTED;
    }

// Disconnected event handling
if( false == CM_connection_status_change->connected )
    {
    if( CM_APP_NAVILITE == CM_connection_status_change->app_type )
        {
        cm_connect_device.navi_app_connection_status = CM_NAVI_APP_CONNECTION_DISCONNECTED;
        // Check if CM need to notify the connection result now
        if( 1 == cm_connecting_request_count )
            {
            CM_core_stop_timeout_timer();
            EW_notify_connection_status( EnumConnectionStatusNAVI_APP_CONNECTED );
            }
        }
    else if( CM_APP_YCONNECT == CM_connection_status_change->app_type )
        {
        cm_connect_device.yconnect_app_connection_status = CM_YCONNECT_APP_CONNECTION_DISCONNECTED;
        }
    if( ( CM_YCONNECT_APP_CONNECTION_DISCONNECTED == cm_connect_device.yconnect_app_connection_status ) && ( CM_NAVI_APP_CONNECTION_DISCONNECTED == cm_connect_device.navi_app_connection_status ) )
        {
        memset( cm_connect_device.bd_addr, BT_DEVICE_ADDRESS_LEN, 0 );
        }
    }
// Connected event handling
else
    {
    // LC is Connecting to APP
    // Since the YCONNECT is connect after NAVI, if Yconnect status is from YCONNECT_CONNECTING to YCONNECT_CONNECTED

    if( ( CM_NAVI_APP_CONNECTION_CONNECTING == cm_connect_device.navi_app_connection_status || CM_YCONNECT_APP_CONNECTION_CONNECTING == cm_connect_device.yconnect_app_connection_status ) )
        {
        if( CM_APP_NAVILITE == CM_connection_status_change->app_type )
            {
            cm_connect_device.navi_app_connection_status = CM_NAVI_APP_CONNECTION_CONNECTED;
            // Check if CM need to notify the connection result now
            if( 1 == cm_connecting_request_count )
                {
                CM_core_stop_timeout_timer();
                EW_notify_connection_status( EnumConnectionStatusNAVI_APP_CONNECTED );
                }
            }
        else if( CM_APP_YCONNECT == CM_connection_status_change->app_type  )
            {
            BLE_server_set_advertising_mode( BLE_ADVERTISING_CONNECTABLE, BLE_ADVERTISING_DATA_NAME_COMPLETE, cm_stored_ccuid, CCUID_LENGTH + 1 );
            cm_connect_device.yconnect_app_connection_status = CM_YCONNECT_APP_CONNECTION_CONNECTED;
            connecting_notify_ready = true;
            }
        }
    // APP connect to LC
    else if( ( CM_NAVI_APP_CONNECTION_DISCONNECTED == cm_connect_device.navi_app_connection_status || CM_YCONNECT_APP_CONNECTION_DISCONNECTED == cm_connect_device.yconnect_app_connection_status ) )
        {
        if( CM_APP_NAVILITE == CM_connection_status_change->app_type )
            {
            cm_connect_device.navi_app_connection_status = CM_NAVI_APP_CONNECTION_CONNECTED;
            EW_notify_connection_status(EnumConnectionStatusNAVI_APP_CONNECTED );
            }
        else if( CM_APP_YCONNECT == CM_connection_status_change->app_type  )
            {
            BLE_server_set_advertising_mode( BLE_ADVERTISING_CONNECTABLE, BLE_ADVERTISING_DATA_NAME_COMPLETE, cm_stored_ccuid, CCUID_LENGTH + 1 );
            cm_connect_device.yconnect_app_connection_status = CM_YCONNECT_APP_CONNECTION_CONNECTED;
            EW_notify_connection_status( EnumConnectionStatusYAMAHA_APP_BLE_CONNECTED );
            }
        }
    }

cm_connecting_request_count = 0;  // Clear the connecting request at all cases
EW_notify_connection_status( EnumConnectionStatusCONNECTED_APP_CHANGED );
}

/*================================================================================================
@brief   Core handle application authentication result
@details For Motocon SDK or Navillite, need to handle the authentication result
@return  None
@retval  None
================================================================================================*/
void CM_core_handle_app_auth_result
    (
    const CM_auth_result_t *CM_auth_result
    )
{
bool is_LE_paired_device = false;

// Currently only handle the authentication success case
if( true == CM_auth_result->result )
    {
    if( CM_APP_YCONNECT == CM_auth_result->app_type )
        {
        cm_connect_device.yconnect_app_connection_status = CM_YCONNECT_APP_CONNECTION_AUTHENTICATED;
        // Check if the LC is connecting BT module, and need to notify HMI
        if( false == connecting_notify_ready )
            {
            EW_notify_connection_status( EnumConnectionStatusYAMAHA_APP_CONNECTED );
            }
        else
            {
            BT_is_paired_le_device( cm_connect_device.bd_addr, &is_LE_paired_device );
            if( false == is_LE_paired_device )
                {
                CM_core_stop_timeout_timer();
                EW_notify_connection_status( EnumConnectionStatusYAMAHA_APP_BLE_NOT_CONNECTED );
                }

            if( CM_NAVI_APP_CONNECTION_DISCONNECTED == cm_connect_device.navi_app_connection_status )
                {
                CM_core_stop_timeout_timer();
                EW_notify_connection_status( EnumConnectionStatusYAMAHA_APP_CONNECTED );
                connecting_notify_ready = false;
                }
            else if( CM_NAVI_APP_CONNECTION_CONNECTED == cm_connect_device.navi_app_connection_status || CM_NAVI_APP_CONNECTION_AUTHENTICATED == cm_connect_device.navi_app_connection_status )
                {
                CM_core_stop_timeout_timer();
                EW_notify_connection_status( EnumConnectionStatusBOTH_APP_CONNECTED );
                connecting_notify_ready = false;
                }

            }
        }
    // Reserved
    else if( CM_APP_NAVILITE == CM_auth_result->app_type )
        {
        cm_connect_device.navi_app_connection_status = CM_NAVI_APP_CONNECTION_AUTHENTICATED;
        }
    }
EW_notify_connection_status( EnumConnectionStatusCONNECTED_APP_CHANGED );
}

/*================================================================================================
@brief   CM core handle BT manager ACL link disconnected
@details CM core handle BT manager ACL link disconnected
@return  None
@retval  None
================================================================================================*/
void CM_core_handle_btmgr_acl_link_disconnected
    (
    const CM_acl_disconnected_t *CM_acl_disconnected
    )
{
// Reset cm connect device status
memset( cm_connect_device.bd_addr, BT_DEVICE_ADDRESS_LEN, 0 );
cm_connect_device.yconnect_app_connection_status = CM_YCONNECT_APP_CONNECTION_DISCONNECTED;
cm_connect_device.navi_app_connection_status = CM_NAVI_APP_CONNECTION_DISCONNECTED;


// Update to Auto connect
CMA_handle_btmgr_acl_link_disconnected( CM_acl_disconnected->bd_addr, CM_acl_disconnected->user_request );

EW_notify_connection_status( EnumConnectionStatusCONNECTED_APP_CHANGED );
}

/*================================================================================================
@brief   CM core set auto connect state
@details CM core set auto connect state
@return  None
@retval  None
================================================================================================*/
void CM_core_set_auto_connect_state
    (
    const CM_set_auto_connect_state_t *CM_set_auto_connect_state
    )
{
if( !CMA_set_enable_state( CM_set_auto_connect_state->auto_connect_state ) )
    {
    CM_LOG_ERROR( "CMA_set_enable_state FALSE" );
    }
}

/*================================================================================================
@brief   CM core handle BT enable state change
@details Send bt enable state to CM auto connect
@return  None
@retval  None
================================================================================================*/
void CM_core_handle_btmgr_enable_state_changed
    (
    const bool enable_state
    )
{
CMA_handle_btmgr_enable_state_changed( enable_state );

if( true == enable_state )
    {
    // The CM haven't get CCUID yet, use Test CCUID
    BLE_server_set_advertising_mode( BLE_ADVERTISING_NON_CONNECTABLE, BLE_ADVERTISING_DATA_NAME_COMPLETE, cm_stored_ccuid, CCUID_LENGTH + 1 );
    }
}

#ifdef __cplusplus
}
#endif
