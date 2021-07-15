/*********************************************************************
* @file  bt_spp_core.c
* @brief Bluetooth Manager SPP Core interface definition.
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
#include <semphr.h>
#include <task.h>
#include <string.h>

#include "factory_test.h"

#include "bt_device.h"
#include "bt_log.h"
#include "bt_spp_core.h"
#include "bt_utils.h"
#include "hci_cmd.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define MUTEX_LOCK_MS ( 5000 )

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef struct BT_mfi_auth_chip_info
    {
    uint8_t device_version;
    uint8_t firmware_version;
    uint8_t protocol_major_version;
    uint8_t protocol_minor_version;
    uint32_t device_id;
    } BT_mfi_auth_chip_info_t;

typedef struct BT_spp_connection_info
    {
    BT_connection_status_e connection_status;
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    uint16_t connection_handle;
    BT_spp_connection_type_e connection_type;
    SemaphoreHandle_t mutex;
    } BT_spp_connection_info_t;

typedef struct BT_spp_core
    {
    bool initialized;
    BT_spp_connection_info_t connection_info;
    BT_spp_connection_status_callback connection_status_callbacks[SPP_APP_CONNECTION_STATUS_CB_MAX_NUM];
    BT_spp_data_received_callback data_received_callbacks[SPP_APP_DATA_RECEIVED_CB_MAX_NUM];
    } BT_spp_core_t;

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/
static const BT_mfi_auth_chip_info_t s_default_mfi_auth_chip_info =
    {
    .device_version = 0x07,
    .firmware_version = 0x01,
    .protocol_major_version = 0x03,
    .protocol_minor_version = 0x00,
    .device_id = 0x00000300
    };

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
static BT_spp_core_t s_core[BT_SPP_APP_TYPE_CNT] = { 0 };

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/
static uint16_t BT_core_spp_get_connection_handle
    (
    const BT_spp_app_type_e app_type
    );

static BT_spp_connection_type_e BT_core_spp_get_connection_type
    (
    const BT_spp_app_type_e app_type
    );

static bool BT_core_spp_set_connection_handle
    (
    const BT_spp_app_type_e app_type,
    const uint16_t connection_handle
    );

static bool BT_core_spp_set_connection_type
    (
    const BT_spp_app_type_e app_type,
    const BT_spp_connection_type_e connection_type
    );

static bool BT_core_spp_set_connection_status
    (
    const BT_spp_app_type_e app_type,
    const BT_connection_status_e connection_status,
    const uint8_t* bd_addr
    );

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Add the callback to listen the SPP app's connection status change
@details Add the callback to listen the SPP app's connection status change. The limit number of
         registered callbacks for each SPP app is specified in SPP_APP_CONNECTION_STATUS_CB_MAX_NUM
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_core_spp_add_connection_status_callback
    (
    const BT_spp_app_type_e app_type,
    BT_spp_connection_status_callback callback
    )
{
bool ret = false;

if( ( app_type < 0 ) || ( app_type >= BT_SPP_APP_TYPE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid app type: %d", app_type );
    }
else if( NULL == callback )
    {
    BT_LOG_DEBUG( "NULL callback" );
    }
else
    {
    for( int8_t i = 0; i < SPP_APP_CONNECTION_STATUS_CB_MAX_NUM; ++i )
        {
        if( NULL == s_core[app_type].connection_status_callbacks[i] )
            {
            s_core[app_type].connection_status_callbacks[i] = callback;
            ret = true;
            break;
            }
        }

    if( false == ret )
        {
        BT_LOG_DEBUG( "Available callback not found" );
        }
    }
return ret;
}

/*================================================================================================
@brief   Add the callback to listen the SPP app's received data
@details Add the callback to listen the SPP app's received data. The limit number of registered
         callbacks for each SPP app is specified in SPP_APP_DATA_RECEIVED_CB_MAX_NUM
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_core_spp_add_data_received_callback
    (
    const BT_spp_app_type_e app_type,
    BT_spp_data_received_callback callback
    )
{
bool ret = false;

if( ( app_type < 0 ) || ( app_type >= BT_SPP_APP_TYPE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid app type: %d", app_type );
    }
else if( NULL == callback )
    {
    BT_LOG_DEBUG( "NULL callback" );
    }
else
    {
    for( int8_t i = 0; i < SPP_APP_DATA_RECEIVED_CB_MAX_NUM; ++i )
        {
        if( NULL == s_core[app_type].data_received_callbacks[i] )
            {
            s_core[app_type].data_received_callbacks[i] = callback;
            ret = true;
            break;
            }
        }

    if( false == ret )
        {
        BT_LOG_DEBUG( "Available callback not found" );
        }
    }
return ret;
}

/*================================================================================================
@brief   Connect the SPP app to the remote device
@details Send the HCI command of connecting the SPP app to the remote device to Cypress module
@return  None
@retval  Whether or not the HCI command is sent to Cypress module successfully
================================================================================================*/
bool BT_core_spp_connect
    (
    const uint8_t* bd_addr,
    const BT_spp_app_type_e app_type
    )
{
bool ret = false;
uint8_t param[BT_DEVICE_ADDRESS_LEN + SPP_APP_TYPE_LEN] = { 0 };
BT_connection_status_e connection_status = BT_core_spp_get_connection_status( app_type, NULL );

if( ( app_type < 0 ) || ( app_type >= BT_SPP_APP_TYPE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid app type: %d", app_type );
    }
else if( ( NULL == bd_addr ) || ( strlen( (const char*)bd_addr ) != BT_DEVICE_ADDRESS_LEN ) )
    {
    BT_LOG_DEBUG( "Invalid BD address" );
    }
else if( false == BT_device_is_existed( bd_addr ) )
    {
    BT_LOG_DEBUG( "Not paired device: %02x:%02x:%02x:%02x:%02x:%02x", BD_ADDR_PRINT( bd_addr ) );
    }
else if( BT_CONNECTION_DISCONNECTED != connection_status )
    {
    BT_LOG_DEBUG( "Not allowed in connection status:", BT_util_get_connection_status_string( connection_status ) );
    }
else
    {
    memcpy( &( param[0] ), bd_addr, BT_DEVICE_ADDRESS_LEN );
    param[6] = app_type;

    if( BT_device_is_iap_support( bd_addr ) )
        {
        ret = HCI_send_wiced_command( HCI_CONTROL_IAP2_COMMAND_CONNECT_GARMIN, param, sizeof( param ) );
        }
    else
        {
        ret = HCI_send_wiced_command( HCI_CONTROL_SPP_COMMAND_CONNECT_GARMIN, param, sizeof( param ) );
        }

    if( ret )
        {
        BT_core_spp_set_connection_status( app_type, BT_CONNECTION_CONNECTING, bd_addr );
        }
    }
return ret;
}

/*================================================================================================
@brief   Disconnect the SPP app from the remote device
@details Send the HCI command of disconnecting the SPP app from the remote device to Cypress module
@return  None
@retval  Whether or not the HCI command is sent to Cypress module successfully
================================================================================================*/
bool BT_core_spp_disconnect
    (
    const uint8_t* bd_addr,
    const BT_spp_app_type_e app_type
    )
{
bool ret = false;
uint8_t cur_bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };
uint8_t param[BT_CONNECTION_HANDLE_LEN + SPP_APP_TYPE_LEN] = { 0 };
uint16_t connection_handle = BT_core_spp_get_connection_handle( app_type );
BT_connection_status_e connection_status = BT_core_spp_get_connection_status( app_type, cur_bd_addr );

if( ( app_type < 0 ) || ( app_type >= BT_SPP_APP_TYPE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid app type: %d", app_type );
    }
else if( ( NULL == bd_addr ) || ( strlen( (const char*)bd_addr ) != BT_DEVICE_ADDRESS_LEN ) )
    {
    BT_LOG_DEBUG( "Invalid BD address" );
    }
else if( BT_CONNECTION_CONNECTED != connection_status )
    {
    BT_LOG_DEBUG( "Not allowed in connection status:", BT_util_get_connection_status_string( connection_status ) );
    }
else if( 0 != memcmp( cur_bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN ) )
    {
    BT_LOG_DEBUG( "Not connected device: %02x:%02x:%02x:%02x:%02x:%02x", BD_ADDR_PRINT( bd_addr ) );
    }
else
    {
    INT16_TO_LITTLE_ENDIAN( connection_handle, &( param[0] ) );
    param[2] = app_type;

    if( BT_SPP_CONNECTION_IAP == BT_core_spp_get_connection_type( app_type ) )
        {
        ret = HCI_send_wiced_command( HCI_CONTROL_IAP2_COMMAND_DISCONNECT_GARMIN, param, sizeof( param ) );
        }
    else
        {
        ret = HCI_send_wiced_command( HCI_CONTROL_SPP_COMMAND_DISCONNECT_GARMIN, param, sizeof( param ) );
        }

    if( ret )
        {
        BT_core_spp_set_connection_status( app_type, BT_CONNECTION_DISCONNECTING, bd_addr );
        }
    }
return ret;
}

/*================================================================================================
@brief   Get the SPP app's connection handle
@details Get the SPP app's connection handle
@return  None
@retval  The SPP app's connection handle
================================================================================================*/
static uint16_t BT_core_spp_get_connection_handle
    (
    const BT_spp_app_type_e app_type
    )
{
uint16_t connection_handle = 0;

if( ( app_type < 0 ) || ( app_type >= BT_SPP_APP_TYPE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid app type: %d", app_type );
    }
else
    {
    if( false == xSemaphoreTake( s_core[app_type].connection_info.mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
        {
        BT_LOG_ERROR( "Mutex lock timeout" );
        }
    else
        {
        connection_handle = s_core[app_type].connection_info.connection_handle;
        xSemaphoreGive( s_core[app_type].connection_info.mutex );
        }
    }
return connection_handle;
}

/*================================================================================================
@brief   Get the SPP app's connection type
@details Get the SPP app's connection type
@return  None
@retval  The SPP app's connection type
================================================================================================*/
static BT_spp_connection_type_e BT_core_spp_get_connection_type
    (
    const BT_spp_app_type_e app_type
    )
{
BT_spp_connection_type_e connection_type = BT_SPP_CONNECTION_TYPE_INVALID;

if( ( app_type < 0 ) || ( app_type >= BT_SPP_APP_TYPE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid app type: %d", app_type );
    }
else
    {
    if( false == xSemaphoreTake( s_core[app_type].connection_info.mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
        {
        BT_LOG_ERROR( "Mutex lock timeout" );
        }
    else
        {
        connection_type = s_core[app_type].connection_info.connection_type;
        xSemaphoreGive( s_core[app_type].connection_info.mutex );
        }
    }
return connection_type;
}

/*================================================================================================
@brief   Get the SPP app's connection status
@details Get the SPP app's connection status
@return  bd_addr: remote device address
@retval  The SPP app's connection status
================================================================================================*/
BT_connection_status_e BT_core_spp_get_connection_status
    (
    const BT_spp_app_type_e app_type,
    uint8_t* bd_addr
    )
{
BT_connection_status_e connection_status = BT_CONNECTION_DISCONNECTED;

if( ( app_type < 0 ) || ( app_type >= BT_SPP_APP_TYPE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid app type: %d", app_type );
    }
else
    {
    if( false == xSemaphoreTake( s_core[app_type].connection_info.mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
        {
        BT_LOG_ERROR( "Mutex lock timeout" );
        }
    else
        {
        connection_status = s_core[app_type].connection_info.connection_status;
        if( NULL != bd_addr )
            {
            memcpy( bd_addr, s_core[app_type].connection_info.bd_addr, BT_DEVICE_ADDRESS_LEN );
            }
        xSemaphoreGive( s_core[app_type].connection_info.mutex );
        }
    }
return connection_status;
}

/*================================================================================================
@brief   Bluetooth Manager SPP Core initialization
@details Bluetooth Manager SPP Core initialization
@return  None
@retval  None
================================================================================================*/
void BT_core_spp_init( void )
{
bool reset_required = false;

for( BT_spp_app_type_e app_type = 0; app_type < BT_SPP_APP_TYPE_CNT; ++app_type )
    {
    if( false == s_core[app_type].initialized )
        {
        s_core[app_type].connection_info.mutex = xSemaphoreCreateMutex();
        configASSERT( NULL != s_core[app_type].connection_info.mutex );

        s_core[app_type].initialized = true;
        reset_required = true;
        }
    }

if( reset_required )
    {
    BT_core_spp_reset();
    }
}

/*================================================================================================
@brief   Read MFi authentication chip info and report the received info to IOP
@details Send the HCI command of reading MFI authentication chip info to Cypress module. When the
         info is received report it back to IOP
@return  None
@retval  Whether or not the HCI command is sent to Cypress module successfully
================================================================================================*/
bool BT_core_spp_read_mfi_auth_chip_info( void )
{
return HCI_send_wiced_command( HCI_CONTROL_IAP2_COMMAND_GET_AUTH_CHIP_INFO, NULL, 0 );
}

/*================================================================================================
@brief   Reset Bluetooth Manager SPP Core's data
@details Reset Bluetooth Manager SPP Core's data
@return  None
@retval  None
================================================================================================*/
void BT_core_spp_reset( void )
{
for( BT_spp_app_type_e app_type = 0; app_type < BT_SPP_APP_TYPE_CNT; ++app_type )
    {
    if( BT_CONNECTION_DISCONNECTED != BT_core_spp_get_connection_status( app_type, NULL ) )
        {
        BT_core_spp_set_connection_type( app_type, BT_SPP_CONNECTION_TYPE_INVALID );
        BT_core_spp_set_connection_handle( app_type, 0 );
        BT_core_spp_set_connection_status( app_type, BT_CONNECTION_DISCONNECTED, NULL );
        }
    }
}

/*================================================================================================
@brief   Send the SPP app data to the remote device
@details Send the HCI command of sending the SPP app data to the remote device to Cypress module
         The length of data to send should not exceed the limit specified in SPP_DATA_MAX_SIZE
@return  None
@retval  Whether or not the HCI command is sent to Cypress module successfully
================================================================================================*/
bool BT_core_spp_send_data
    (
    const uint8_t* bd_addr,
    const BT_spp_app_type_e app_type,
    const uint8_t* data,
    const uint8_t data_len
    )
{
bool ret = false;
uint8_t cur_bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };
uint8_t param[BT_CONNECTION_HANDLE_LEN + SPP_APP_TYPE_LEN + data_len];
uint16_t connection_handle = BT_core_spp_get_connection_handle( app_type );
BT_connection_status_e connection_status = BT_core_spp_get_connection_status( app_type, cur_bd_addr );

if( ( app_type < 0 ) || ( app_type >= BT_SPP_APP_TYPE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid app type: %d", app_type );
    }
else if( ( NULL == bd_addr ) || ( strlen( (const char*)bd_addr ) != BT_DEVICE_ADDRESS_LEN ) )
    {
    BT_LOG_DEBUG( "Invalid BD address" );
    }
else if( ( NULL == data ) || ( 0 == data_len ) || ( data_len > SPP_DATA_MAX_SIZE ) )
    {
    BT_LOG_DEBUG( "Invalid data" );
    }
else if( BT_CONNECTION_CONNECTED != connection_status )
    {
    BT_LOG_DEBUG( "Not allowed in connection status:", BT_util_get_connection_status_string( connection_status ) );
    }
else if( 0 != memcmp( cur_bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN ) )
    {
    BT_LOG_DEBUG( "Not connected device: %02x:%02x:%02x:%02x:%02x:%02x", BD_ADDR_PRINT( bd_addr ) );
    }
else
    {
    memset( param, 0, sizeof( param ) );
    INT16_TO_LITTLE_ENDIAN( connection_handle, &( param[0] ) );
    param[2] = app_type;
    memcpy( &( param[3] ), data, data_len );

    if( BT_SPP_CONNECTION_IAP == BT_core_spp_get_connection_type( app_type ) )
        {
        ret = HCI_send_wiced_command( HCI_CONTROL_IAP2_COMMAND_DATA_GARMIN, param, sizeof( param ) );
        }
    else
        {
        ret = HCI_send_wiced_command( HCI_CONTROL_SPP_COMMAND_DATA_GARMIN, param, sizeof( param ) );
        }
    }
return ret;
}

/*================================================================================================
@brief   Set the SPP app's connection handle
@details Set the SPP app's connection handle
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool BT_core_spp_set_connection_handle
    (
    const BT_spp_app_type_e app_type,
    const uint16_t connection_handle
    )
{
bool ret = false;

if( ( app_type < 0 ) || ( app_type >= BT_SPP_APP_TYPE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid app type: %d", app_type );
    }
else
    {
    if( false == xSemaphoreTake( s_core[app_type].connection_info.mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
        {
        BT_LOG_ERROR( "Mutex lock timeout" );
        }
    else
        {
        BT_LOG_DEBUG( "%s: Connection handle: 0x%x -> 0x%x",
                      BT_util_get_spp_app_type_string( app_type ),
                      s_core[app_type].connection_info.connection_handle,
                      connection_handle );

        s_core[app_type].connection_info.connection_handle = connection_handle;

        ret = true;
        xSemaphoreGive( s_core[app_type].connection_info.mutex );
        }
    }
return ret;
}

/*================================================================================================
@brief   Set the SPP app's connection type
@details Set the SPP app's connection type
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool BT_core_spp_set_connection_type
    (
    const BT_spp_app_type_e app_type,
    const BT_spp_connection_type_e connection_type
    )
{
bool ret = false;

if( ( app_type < 0 ) || ( app_type >= BT_SPP_APP_TYPE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid app type: %d", app_type );
    }
else if( ( connection_type < 0 ) || ( connection_type >= BT_SPP_CONNECTION_TYPE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid connection type: %d", connection_type );
    }
else
    {
    if( false == xSemaphoreTake( s_core[app_type].connection_info.mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
        {
        BT_LOG_ERROR( "Mutex lock timeout" );
        }
    else
        {
        BT_LOG_DEBUG( "%s: Connection type: %s -> %s",
                      BT_util_get_spp_app_type_string( app_type ),
                      BT_util_get_spp_connection_type_string( s_core[app_type].connection_info.connection_type ),
                      BT_util_get_spp_connection_type_string( connection_type ) );

        s_core[app_type].connection_info.connection_type = connection_type;

        ret = true;
        xSemaphoreGive( s_core[app_type].connection_info.mutex );
        }
    }
return ret;
}

/*================================================================================================
@brief   Set the SPP app's connection status
@details Set the SPP app's connection status
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool BT_core_spp_set_connection_status
    (
    const BT_spp_app_type_e app_type,
    const BT_connection_status_e connection_status,
    const uint8_t* bd_addr
    )
{
bool ret = false;
BT_connection_status_e prev_connection_status = BT_CONNECTION_STATUS_INVALID;

if( ( app_type < 0 ) || ( app_type >= BT_SPP_APP_TYPE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid app type: %d", app_type );
    }
else if( ( connection_status < 0 ) || ( connection_status >= BT_CONNECTION_STATUS_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid connection status: %d", connection_status );
    }
else
    {
    if( false == xSemaphoreTake( s_core[app_type].connection_info.mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
        {
        BT_LOG_ERROR( "Mutex lock timeout" );
        }
    else
        {
        BT_LOG_DEBUG( "%s: %s[%02x:%02x:%02x:%02x:%02x:%02x] -> %s[%02x:%02x:%02x:%02x:%02x:%02x]",
                      BT_util_get_spp_app_type_string( app_type ),
                      BT_util_get_connection_status_string( s_core[app_type].connection_info.connection_status ),
                      BD_ADDR_PRINT( s_core[app_type].connection_info.bd_addr ),
                      BT_util_get_connection_status_string( connection_status ),
                      BD_ADDR_PRINT( ( NULL == bd_addr ? s_core[app_type].connection_info.bd_addr : bd_addr ) ) );

        prev_connection_status = s_core[app_type].connection_info.connection_status;
        s_core[app_type].connection_info.connection_status = connection_status;

        if( BT_CONNECTION_DISCONNECTED == connection_status )
            {
            memset( s_core[app_type].connection_info.bd_addr, 0, BT_DEVICE_ADDRESS_LEN );
            }
        else
            {
            memcpy( s_core[app_type].connection_info.bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN );
            }

        ret = true;
        xSemaphoreGive( s_core[app_type].connection_info.mutex );
        }
    }

if( ret )
    {
    if( BT_CONNECTION_CONNECTED == connection_status )
        {
        for( int8_t i = 0; i < SPP_APP_CONNECTION_STATUS_CB_MAX_NUM; ++i )
            {
            if( NULL != s_core[app_type].connection_status_callbacks[i] )
                {
                s_core[app_type].connection_status_callbacks[i]( true, bd_addr );
                }
            }

        // TODO: Notify CM that the SPP app is connected
        }
    else if( BT_CONNECTION_DISCONNECTED == connection_status )
        {
        if( BT_CONNECTION_CONNECTING != prev_connection_status ) // Not connection failed
            {
            for( int8_t i = 0; i < SPP_APP_CONNECTION_STATUS_CB_MAX_NUM; ++i )
                {
                if( NULL != s_core[app_type].connection_status_callbacks[i] )
                    {
                    s_core[app_type].connection_status_callbacks[i]( false, bd_addr );
                    }
                }
            }

        // TODO: Notify CM that the SPP app is connection failed or disconnected
        }
    }
return ret;
}

// HCI event handler

/*================================================================================================
@brief   Handle the SPP/iAP event that the SPP app is connected to the remote device
@details Handle the SPP/iAP event that the SPP app is connected to the remote device
@return  None
@retval  None
================================================================================================*/
void BT_core_spp_handle_event_connected
    (
    const BT_spp_connection_type_e connection_type,
    const uint8_t* bd_addr,
    const uint16_t connection_handle,
    const BT_spp_app_type_e app_type
    )
{
uint8_t cur_bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };
BT_connection_status_e connection_status = BT_core_spp_get_connection_status( app_type, cur_bd_addr );

if( BT_CONNECTION_CONNECTED == connection_status )
    {
    BT_LOG_ERROR( "%s: Duplicate connection", BT_util_get_spp_app_type_string( app_type ) );
    }
else if( ( BT_CONNECTION_CONNECTING == connection_status ) &&
         ( 0 != memcmp( cur_bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN ) ) )
    {
    BT_LOG_DEBUG( "%s: Non-target device connected", BT_util_get_spp_app_type_string( app_type ) );
    }

BT_core_spp_set_connection_type( app_type, connection_type );
BT_core_spp_set_connection_handle( app_type, connection_handle );
BT_core_spp_set_connection_status( app_type, BT_CONNECTION_CONNECTED, bd_addr );
}

/*================================================================================================
@brief   Handle the SPP/iAP event that the SPP app's connection request to the remote device is failed
@details Handle the SPP/iAP event that the SPP app's connection request to the remote device is failed
@return  None
@retval  None
================================================================================================*/
void BT_core_spp_handle_event_connection_failed
    (
    const BT_spp_connection_type_e connection_type,
    const BT_spp_app_type_e app_type
    )
{
BT_core_spp_set_connection_status( app_type, BT_CONNECTION_DISCONNECTED, NULL );
}

/*================================================================================================
@brief   Handle the SPP/iAP event that the SPP app is disconnected from the remote device
@details Handle the SPP/iAP event that the SPP app is disconnected from the remote device
@return  None
@retval  None
================================================================================================*/
void BT_core_spp_handle_event_disconnected
    (
    const BT_spp_connection_type_e connection_type,
    const uint16_t connection_handle,
    const BT_spp_app_type_e app_type
    )
{
BT_core_spp_set_connection_type( app_type, BT_SPP_CONNECTION_TYPE_INVALID );
BT_core_spp_set_connection_handle( app_type, 0 );
BT_core_spp_set_connection_status( app_type, BT_CONNECTION_DISCONNECTED, NULL );
}

/*================================================================================================
@brief   Handle the SPP/iAP event that the SPP app's data from the remote device is received
@details Handle the SPP/iAP event that the SPP app's data from the remote device is received
@return  None
@retval  None
================================================================================================*/
void BT_core_spp_handle_event_rx_data
    (
    const BT_spp_connection_type_e connection_type,
    const uint16_t connection_handle,
    const BT_spp_app_type_e app_type,
    const uint8_t* data,
    const uint8_t data_len
    )
{
for( int8_t i = 0; i < SPP_APP_DATA_RECEIVED_CB_MAX_NUM; ++i )
    {
    if( NULL != s_core[app_type].data_received_callbacks[i] )
        {
        s_core[app_type].data_received_callbacks[i]( data, data_len );
        }
    }
}

/*================================================================================================
@brief   Handle the iAP event that the MFi authentication chip info is received
@details Handle the iAP event that the MFi authentication chip info is received
@return  None
@retval  None
================================================================================================*/
void BT_core_spp_handle_iap_event_auth_chip_info
    (
    const uint8_t device_version,
    const uint8_t firmware_version,
    const uint8_t protocol_major_version,
    const uint8_t protocol_minor_version,
    const uint32_t device_id
    )
{
BT_mfi_auth_chip_info_t mfi_auth_chip_info =
    {
    .device_version = device_version,
    .firmware_version = firmware_version,
    .protocol_major_version = protocol_major_version,
    .protocol_minor_version = protocol_minor_version,
    .device_id = device_id
    };
bool ret = ( 0 == memcmp( &s_default_mfi_auth_chip_info, &mfi_auth_chip_info, sizeof( BT_mfi_auth_chip_info_t ) ) );

BT_LOG_INFO( "MFi auth chip info check result: %s", ( ret ? "OK" : "Failed" ) );

FACTORY_handle_mfi_auth_chip_diag_result( ret );
}

#ifdef __cplusplus
}
#endif
