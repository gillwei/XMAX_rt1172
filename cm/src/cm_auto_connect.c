/*********************************************************************
* @file  cm_auto_connect.c
* @brief Connection Manager Auto-Connect interface definition.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <FreeRTOS.h>
#include <timers.h>
#include <string.h>

#include "BT_pub.h"
#include "PM_pub.h"

#include "cm_auto_connect.h"
#include "cm_auto_connect_db.h"
#include "cm_log.h"
#include "cm_prv.h"
#include "cm_utils.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define TIME_INTERVAL_FIRST_TIME_MS ( 100 )
#define TIME_INTERVAL_SHORT_MS      ( 3000 )

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef struct CMA_device_node
    {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    struct CMA_device_node* prev;
    struct CMA_device_node* next;
    } CMA_device_node_t;

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
static bool s_bt_enabled = false;
static bool s_user_disconnected = false;

static bool s_cma_enabled = false;

static uint32_t s_cma_time_interval_get_cnt = 0;
static TimerHandle_t s_cma_connect_timer = NULL;

static CMA_device_node_t* s_cma_device_list = NULL;
static CMA_device_node_t* s_cma_current_device = NULL;
static CMA_device_node_t* s_cma_target_device = NULL;

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/
static bool CMA_device_list_add
    (
    const uint8_t* bd_addr
    );

static void CMA_device_list_clear( void );

static void CMA_device_list_delete
    (
    CMA_device_node_t* device
    );

static CMA_device_node_t* CMA_device_list_find
    (
    const uint8_t* bd_addr
    );

static void CMA_device_list_sync_from_db( void );

static void CMA_device_list_sync_to_db( void );

static void CMA_do_connect
    (
    TimerHandle_t timer_handle
    );

static CMA_device_node_t* CMA_get_next_device( void );

static uint32_t CMA_get_next_time_interval( void );

static void CMA_handle_pm_ign_status_changed
    (
    const bool ign_status
    );

static bool CMA_is_allowed_to_connect( void );

static void CMA_prepare_to_connect( void );

static void CMA_reset( void );

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Add the device to the auto-connect device list at the first position
@details Add the device to the auto-connect device list at the first position
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool CMA_device_list_add
    (
    const uint8_t* bd_addr
    )
{
bool ret = false;
CMA_device_node_t* old_device = NULL;
CMA_device_node_t* new_device = NULL;

if( NULL == bd_addr )
    {
    CM_LOG_ERROR( "NULL BD address" );
    }
else
    {
    old_device = CMA_device_list_find( bd_addr );
    if( old_device )
        {
        CMA_device_list_delete( old_device );
        }

    new_device = pvPortMalloc( sizeof( CMA_device_node_t ) );
    if( NULL == new_device )
        {
        CM_LOG_ERROR( "pvPortMalloc() error" );
        }
    else
        {
        memcpy( new_device->bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN );

        new_device->next = s_cma_device_list;
        new_device->prev = NULL;
        if( s_cma_device_list )
            {
            s_cma_device_list->prev = new_device;
            }
        s_cma_device_list = new_device;

        CM_LOG_DEBUG( "Device added to list: bd_addr=%02x:%02x:%02x:%02x:%02x:%02x", BD_ADDR_PRINT( bd_addr ) );
        ret = true;
        }
    }
return ret;
}

/*================================================================================================
@brief   Clear the auto-connect device list
@details Clear the auto-connect device list
@return  None
@retval  None
================================================================================================*/
static void CMA_device_list_clear( void )
{
CMA_device_node_t* head_device = s_cma_device_list;
CMA_device_node_t* tmp_device = NULL;

while( head_device )
    {
    tmp_device = head_device;
    head_device = head_device->next;
    vPortFree( tmp_device );
    }

s_cma_device_list = NULL;
CM_LOG_DEBUG( "Device list cleared" );
}

/*================================================================================================
@brief   Delete the device from the auto-connect device list
@details Delete the device from the auto-connect device list
@return  None
@retval  None
================================================================================================*/
static void CMA_device_list_delete
    (
    CMA_device_node_t* device
    )
{
if( NULL == device )
    {
    CM_LOG_ERROR( "NULL device" );
    }
else
    {
    if( device == s_cma_device_list )
        {
        s_cma_device_list = device->next;
        }
    if( device->next )
        {
        device->next->prev = device->prev;
        }
    if( device->prev )
        {
        device->prev->next = device->next;
        }

    CM_LOG_DEBUG( "Device removed from list: bd_addr=%02x:%02x:%02x:%02x:%02x:%02x", BD_ADDR_PRINT( device->bd_addr ) );
    vPortFree( device );
    }
}

/*================================================================================================
@brief   Find the device from the auto-connect device list by Bluetooth device address
@details Find the device from the auto-connect device list by Bluetooth device address
@return  None
@retval  The found device
================================================================================================*/
static CMA_device_node_t* CMA_device_list_find
    (
    const uint8_t* bd_addr
    )
{
CMA_device_node_t* found_device = NULL;
CMA_device_node_t* head_device = s_cma_device_list;

if( NULL == bd_addr )
    {
    CM_LOG_ERROR( "NULL BD address" );
    }
else
    {
    while( head_device )
        {
        if( 0 == memcmp( head_device->bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN ) )
            {
            found_device = head_device;
            break;
            }
        head_device = head_device->next;
        }
    }
return found_device;
}

/*================================================================================================
@brief   Sync the auto-connect device list from the Connection Manager Auto-Connect database
@details Sync the auto-connect device list from the Connection Manager Auto-Connect database
@return  None
@retval  None
================================================================================================*/
static void CMA_device_list_sync_from_db( void )
{
uint8_t* bd_addr = NULL;
uint8_t device_count = CMA_db_get_device_count();

CMA_device_list_clear();

for( uint8_t i = 0; i < device_count; ++i )
    {
    bd_addr = CMA_db_get_device_by_index( i );
    if( NULL == bd_addr )
        {
        CM_LOG_ERROR( "NULL BD address returned from database" );
        }
    else
        {
        CMA_device_list_add( bd_addr );
        }
    }
CM_LOG_INFO( "Device list synced from database" );
}

/*================================================================================================
@brief   Sync the auto-connect device list to the Connection Manager Auto-Connect database
@details Sync the auto-connect device list to the Connection Manager Auto-Connect database
@return  None
@retval  None
================================================================================================*/
static void CMA_device_list_sync_to_db( void )
{
CMA_device_node_t* head_device = s_cma_device_list;
uint8_t device_count = 0;

while( head_device )
    {
    CMA_db_set_device_by_index( device_count, head_device->bd_addr );
    ++device_count;
    head_device = head_device->next;
    }
CMA_db_set_device_count( device_count );

CM_LOG_INFO( "Device list synced to database" );
}

/*================================================================================================
@brief   Start connecting the target device choosed from the auto-connect device list
@details Start connecting the target device choosed from the auto-connect device list
@return  None
@retval  None
================================================================================================*/
static void CMA_do_connect
    (
    TimerHandle_t timer_handle
    )
{
CM_LOG_INFO( "Connect: bd_addr=%02x:%02x:%02x:%02x:%02x:%02x", BD_ADDR_PRINT( s_cma_target_device->bd_addr ) );

if( CMA_is_allowed_to_connect() )
    {
    if( false == CM_core_spp_connect( s_cma_target_device->bd_addr ) )
        {
        CM_LOG_INFO( "Failed to connect. Retry" );
        CMA_prepare_to_connect();
        }
    }
}

/*================================================================================================
@brief   Reset to factory default
@details Clear the auto-connect device list and enable auto-connect
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool CMA_factory_reset( void )
{
CMA_reset();

CMA_device_list_clear();
CMA_device_list_sync_to_db();

if( false == CMA_get_enable_state() )
    {
    CMA_set_enable_state( true );
    }
return true;
}

/*================================================================================================
@brief   Get whether or not auto-connect is enabled
@details Get whether or not auto-connect is enabled
@return  None
@retval  Whether or not auto-connect is enabled
================================================================================================*/
bool CMA_get_enable_state( void )
{
return s_cma_enabled;
}

/*================================================================================================
@brief   Get the device from the auto-connect device list for the next connection
@details Get the device from the auto-connect device list for the next connection
@return  None
@retval  The device from the auto-connect device list for the next connection
================================================================================================*/
static CMA_device_node_t* CMA_get_next_device( void )
{
bool paired = false;
bool auth_lost = false;
bool remove_needed = false;
uint8_t try_count = 0;
uint8_t device_count = 0;
CMA_device_node_t* found_device = NULL;
CMA_device_node_t* tmp_device = s_cma_device_list;

while( tmp_device )
    {
    ++device_count;
    tmp_device = tmp_device->next;
    }

while( ( NULL == found_device ) && ( try_count++ < device_count ) )
    {
    remove_needed = false;

    BT_is_paired_device( s_cma_current_device->bd_addr, &paired )
    BT_is_paired_device_auth_lost( s_cma_current_device->bd_addr, &auth_lost );

    if( false == paired )
        {
        CM_LOG_DEBUG( "Remove non-paired device: bd_addr=%02x:%02x:%02x:%02x:%02x:%02x",
                      BD_ADDR_PRINT( s_cma_current_device->bd_addr ) );
        remove_needed = true;
        }
    else if( auth_lost )
        {
        CM_LOG_DEBUG( "Remove auth-lost device: bd_addr=%02x:%02x:%02x:%02x:%02x:%02x",
                      BD_ADDR_PRINT( s_cma_current_device->bd_addr ) );
        remove_needed = true;
        }
    else
        {
        found_device = s_cma_current_device;
        }

    if( false == remove_needed )
        {
        s_cma_current_device = s_cma_current_device->next;
        }
    else
        {
        tmp_device = s_cma_current_device;
        s_cma_current_device = s_cma_current_device->next;
        CMA_device_list_delete( tmp_device );
        }
    if( NULL == s_cma_current_device )
        {
        s_cma_current_device = s_cma_device_list;
        }
    }
return found_device;
}

/*================================================================================================
@brief   Get the time interval for the next connection
@details Get the time interval for the next connection
@return  None
@retval  The time interval for the next connection
================================================================================================*/
static uint32_t CMA_get_next_time_interval( void )
{
return ( 0 == s_cma_time_interval_get_cnt++ ? TIME_INTERVAL_FIRST_TIME_MS : TIME_INTERVAL_SHORT_MS );
}

/*================================================================================================
@brief   Handle the BtMgr event that the ACL link to the remote device is disconnected
@details Handle the BtMgr event that the ACL link to the remote device is disconnected
@return  None
@retval  None
================================================================================================*/
void CMA_handle_btmgr_acl_link_disconnected
    (
    const uint8_t* bd_addr,
    const bool user_requested
    )
{
CM_LOG_DEBUG( "ACL link disconnected: bd_addr=%02x:%02x:%02x:%02x:%02x:%02x, user_requested=%d",
              BD_ADDR_PRINT( bd_addr ),
              user_requested );

s_user_disconnected = user_requested;
if( false == s_user_disconnected )
    {
    CMA_reset();
    CMA_prepare_to_connect();
    }
}

/*================================================================================================
@brief   Handle the BtMgr event that a SPP app is connected/disconnected to/from the remote device
@details Handle the BtMgr event that a SPP app is connected/disconnected to/from the remote device
@return  None
@retval  None
================================================================================================*/
void CMA_handle_btmgr_spp_connection_status_changed
    (
    const bool connected,
    const uint8_t* bd_addr
    )
{
CM_LOG_DEBUG( "SPP connection status changed: connected=%d, bd_addr=%02x:%02x:%02x:%02x:%02x:%02x",
              connected,
              BD_ADDR_PRINT( bd_addr ) );

if( s_cma_target_device && ( 0 == memcmp( s_cma_target_device->bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN ) ) )
    {
    if( connected )
        {
        CM_LOG_INFO( "Connection succeeded" );
        }
    else
        {
        CM_LOG_INFO( "Connection failed. Retry" );
        CMA_prepare_to_connect();
        }
    }
}

/*================================================================================================
@brief   Handle the BtMgr event that BT is enabled or disabled
@details Handle the BtMgr event that BT is enabled or disabled
@return  None
@retval  None
================================================================================================*/
void CMA_handle_btmgr_enable_state_changed
    (
    const bool enable_state
    )
{
CM_LOG_DEBUG( "BT enable state changed: enable_state=%d", enable_state );

s_bt_enabled = enable_state;

CMA_reset();
if( s_bt_enabled )
    {
    CMA_prepare_to_connect();
    }
}

/*================================================================================================
@brief   Handle the Power Manager event that the ignition status is changed
@details Handle the Power Manager event that the ignition status is changed
@return  None
@retval  None
================================================================================================*/
static void CMA_handle_pm_ign_status_changed
    (
    const bool ign_status
    )
{
CM_LOG_DEBUG( "PM ign status changed: ign_status=%s", ( PM_IGN_ON == ign_status ? "On" : "Off" ) );

if( PM_IGN_OFF == ign_status )
    {
    CMA_device_list_sync_to_db();
    }
}

/*================================================================================================
@brief   Connection Manager Auto-Connect initialization
@details Connection Manager Auto-Connect initialization
@return  None
@retval  None
================================================================================================*/
void CMA_init( void )
{
uint8_t connect_timer_id = 0;

s_cma_connect_timer = xTimerCreate( "cm_auto_connect", 0, pdFALSE, (void*)&connect_timer_id, CMA_do_connect );
configASSERT( NULL != s_cma_connect_timer );

CMA_db_init();
CMA_device_list_sync_from_db();
s_cma_enabled = CMA_db_get_enable_state();

PM_register_callback( "cm_auto_connect", CMA_handle_pm_ign_status_changed );
}

/*================================================================================================
@brief   Check whether or not the current conditions are OK to connect
@details Check whether or not the current conditions are OK to connect
@return  None
@retval  Whether or not the current conditions are OK to connect
================================================================================================*/
static bool CMA_is_allowed_to_connect( void )
{
bool allowed = false;

if( false == s_cma_enabled )
    {
    CM_LOG_INFO( "Not allowed: Auto-Connect disabled" );
    }
else if( false == s_bt_enabled )
    {
    CM_LOG_INFO( "Not allowed: BT disabled" );
    }
else if( false == s_user_disconnected )
    {
    CM_LOG_INFO( "Not allowed: User disconnected" );
    }
else
    {
    allowed = true;
    }
return allowed;
}

/*================================================================================================
@brief   Check and prepare to connect
@details Check and prepare to connect
@return  None
@retval  None
================================================================================================*/
static void CMA_prepare_to_connect( void )
{
uint32_t time_interval = 0;

CM_LOG_INFO( "Prepare to connect" );
s_cma_target_device = NULL;

if( CMA_is_allowed_to_connect() )
    {
    time_interval = CMA_get_next_time_interval();
    s_cma_target_device = CMA_get_next_device();
    if( ( time_interval > 0 ) && s_cma_target_device )
        {
        CM_LOG_INFO( "Connect info: time_interval=%u ms, target_device=%02x:%02x:%02x:%02x:%02x:%02x",
                     time_interval,
                     BD_ADDR_PRINT( s_cma_target_device->bd_addr ) );

        if( pdTRUE != xTimerStop( s_cma_connect_timer, 0 ) )
            {
            CM_LOG_ERROR( "xTimerStop() error" );
            }
        if( pdTRUE != xTimerChangePeriod( s_cma_connect_timer, pdMS_TO_TICKS( time_interval ), 0 ) )
            {
            CM_LOG_ERROR( "xTimerChangePeriod() error" );
            }
        if( pdTRUE != xTimerStart( s_cma_connect_timer, 0 ) )
            {
            CM_LOG_ERROR( "xTimerStart() error" );
            }
        }
    }
}

/*================================================================================================
@brief   Reset the auto-connect session info
@details Reset the auto-connect session info
@return  None
@retval  None
================================================================================================*/
static void CMA_reset( void )
{
s_cma_time_interval_get_cnt = 0;
if( pdTRUE != xTimerStop( s_cma_connect_timer, 0 ) )
    {
    CM_LOG_ERROR( "xTimerStop() error" );
    }

s_cma_current_device = s_cma_device_list;
s_cma_target_device = NULL;
}

/*================================================================================================
@brief   Enable or disable auto-connect
@details Enable or disable auto-connect
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool CMA_set_enable_state
    (
    const bool enable
    )
{
if( s_cma_enabled != enable )
    {
    CM_LOG_INFO( "Auto-Connect enabled: %d", enable );
    s_cma_enabled = enable;

    CMA_db_set_enable_state( s_cma_enabled );

    if( s_cma_enabled )
        {
        CMA_prepare_to_connect();
        }
    else
        {
        if( pdTRUE != xTimerStop( s_cma_connect_timer, 0 ) )
            {
            CM_LOG_ERROR( "xTimerStop() error" );
            }
        }
    }
return true;
}

#ifdef __cplusplus
}
#endif
