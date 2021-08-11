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
#include <semphr.h>
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
#define CONNECT_CALLBACK_TIMEOUT   20000

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
static SemaphoreHandle_t              s_binary_semaphore = NULL;
static CM_connect_device_status_t     cm_connect_device;
static CM_connect_result_t            CM_connect_result;

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/


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

// The binary semaphore created using vSemaphoreCreateBinary is created in Given state
if( NULL == s_binary_semaphore )
    {
    // The binary semaphore created using xSemaphoreCreateBinary is created in Taken state
    s_binary_semaphore = xSemaphoreCreateBinary();
    configASSERT( NULL != s_binary_semaphore );
    }
}

/*================================================================================================
@brief   Connect the SPP app to the remote device
@details Send the HCI command of connecting the SPP app to the remote device to Cypress module
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
        cm_connect_device.navi_app_connection_status = CM_NAVI_APP_CONNECTION_CONNECTING;
        if( pdTRUE != xSemaphoreTake( s_binary_semaphore, pdMS_TO_TICKS( CONNECT_CALLBACK_TIMEOUT ) ) )
            {
            CM_LOG_ERROR( "connect BT_SPP_Navi timeout");
            cm_connect_device.navi_app_connection_status = CM_NAVI_APP_CONNECTION_DISCONNECTED;
            }

        // Connect Yconnect APP
        BT_yconnect_connect_result = BT_spp_connect( bd_addr, BT_SPP_APP_MOTOCON);
        if( BT_STATUS_OK ==  BT_yconnect_connect_result )
            {
            cm_connect_device.yconnect_app_connection_status = CM_YCONNECT_APP_CONNECTION_CONNECTING;
            if( pdTRUE != xSemaphoreTake( s_binary_semaphore, pdMS_TO_TICKS( CONNECT_CALLBACK_TIMEOUT ) ) )
               {
                cm_connect_device.yconnect_app_connection_status = CM_YCONNECT_APP_CONNECTION_DISCONNECTED;
                CM_LOG_ERROR( "connect BT_SPP_Yconnect timeout" );
               }
            }
        else if( BT_STATUS_AUTH_LOST ==  BT_yconnect_connect_result )
            {
            EW_notify_connection_status(EnumConnectionStatusAUTHENTICATION_ERR, 0);
            }
        else
            {
            }

        }
    // Connect navi is authentication error
    else if( BT_STATUS_AUTH_LOST == BT_navi_connect_result )
        {
        EW_notify_connection_status(EnumConnectionStatusAUTHENTICATION_ERR, 0);
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
    EW_notify_connection_status(EnumConnectionStatusPAIRING_FAILED, 0);
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
    if( ( CM_NAVI_APP_CONNECTION_CONNECTING == cm_connect_device.navi_app_connection_status || CM_YCONNECT_APP_CONNECTION_CONNECTING == cm_connect_device.yconnect_app_connection_status ) )
        {
        xSemaphoreGive( s_binary_semaphore );
        if( CM_APP_NAVILITE == CM_connection_status_change->app_type )
            {
            cm_connect_device.navi_app_connection_status = CM_NAVI_APP_CONNECTION_CONNECTED;
            }
        else if( CM_APP_YCONNECT == CM_connection_status_change->app_type  )
            {
            cm_connect_device.yconnect_app_connection_status = CM_YCONNECT_APP_CONNECTION_CONNECTED;
            }
        }
    // APP connect to LC
    else if( ( CM_NAVI_APP_CONNECTION_DISCONNECTED == cm_connect_device.navi_app_connection_status || CM_YCONNECT_APP_CONNECTION_DISCONNECTED == cm_connect_device.yconnect_app_connection_status ) )
        {
        if( CM_APP_NAVILITE == CM_connection_status_change->app_type )
            {
            cm_connect_device.navi_app_connection_status = CM_NAVI_APP_CONNECTION_CONNECTED;
            EW_notify_connection_status(EnumConnectionStatusNAVI_APP_CONNECTED, 0);
            }
        else if(  CM_APP_YCONNECT == CM_connection_status_change->app_type  )
            {
            cm_connect_device.yconnect_app_connection_status = CM_YCONNECT_APP_CONNECTION_CONNECTED;
            //EW_notify_connection_status(EnumConnectionStatusYAMAHA_BLE_CONNECTED, 0);
            }
        }
    }
EW_notify_connection_status( EnumConnectionStatusCONNECTED_APP_CHANGED, 0 );
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
// Currently only handle the authentication success case
if( true == CM_auth_result->result )
    {
    if( CM_APP_YCONNECT == CM_auth_result->app_type )
        {
        cm_connect_device.yconnect_app_connection_status = CM_YCONNECT_APP_CONNECTION_AUTHENTICATED;
        EW_notify_connection_status( EnumConnectionStatusYAMAHA_APP_CONNECTED, 0 );
        }
    else if( CM_APP_NAVILITE == CM_auth_result->app_type )
        {
        cm_connect_device.navi_app_connection_status = CM_NAVI_APP_CONNECTION_AUTHENTICATED;
        }
    }
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
    }

#ifdef __cplusplus
}
#endif
