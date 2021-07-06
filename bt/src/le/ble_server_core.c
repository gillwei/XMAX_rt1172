/*********************************************************************
* @file  ble_server_core.c
* @brief Bluetooth Manager LE Server Core interface definition.
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
#include <string.h>

#include "bt_core.h"
#include "bt_log.h"
#include "bt_tsk.h"
#include "bt_utils.h"
#include "ble_server_core.h"
#include "hci_cmd.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef struct BLE_server_service
    {
    uint16_t start_handle;
    uint16_t end_handle;
    BLE_server_callback_t callbacks;
    } BLE_server_service_t;

typedef struct BLE_server_core
    {
    bool initialized;
    BLE_advertising_mode_e advertising_mode;
    bool acl_connected;
    uint16_t connection_handle;
    BLE_server_service_t servers[BLE_SERVER_TYPE_CNT];
    } BLE_server_core_t;

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
static BLE_server_core_t s_core = { 0 };

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Find out the LE Server who owns the attribute handle
@details Find out the LE Server who owns the attribute handle
@return  None
@retval  The LE Server who owns the attribute handle
================================================================================================*/
BLE_server_type_e BLE_core_server_find_handle_owner
    (
    const uint16_t handle
    )
{
for( BLE_server_type_e server_type = 0; server_type < BLE_SERVER_TYPE_CNT; ++server_type )
    {
    if( ( handle >= s_core.servers[server_type].start_handle ) &&
        ( handle <= s_core.servers[server_type].end_handle ) )
        {
        return server_type;
        }
    }
return BLE_SERVER_TYPE_INVALID;
}

/*================================================================================================
@brief   Get the LE Server's advertising mode
@details Get the LE Server's advertising mode
@return  None
@retval  The LE Server's advertising mode
================================================================================================*/
BLE_advertising_mode_e BLE_core_server_get_advertising_mode( void )
{
return s_core.advertising_mode;
}

/*================================================================================================
@brief   Get the LE Server's connection status
@details Get the LE Server's connection status
@return  None
@retval  The LE Server's connection status
================================================================================================*/
bool BLE_core_server_get_connection_status( void )
{
return s_core.acl_connected;
}

/*================================================================================================
@brief   Bluetooth Manager LE Server Core initialization
@details Bluetooth Manager LE Server Core initialization
@return  None
@retval  None
================================================================================================*/
void BLE_core_server_init( void )
{
if( false == s_core.initialized )
    {
    for( BLE_server_type_e server_type = 0; server_type < BLE_SERVER_TYPE_CNT; ++server_type )
        {
        if( BLE_SERVER_MOTOCON == server_type )
            {
            s_core.servers[server_type].start_handle = HDLS_GAP;
            s_core.servers[server_type].end_handle = HDLD_MOTOCONSDK_DDT_CAN_DATA_CLIENT_CHAR_CONFIG;
            }
        }

    BLE_core_server_reset();

    s_core.initialized = true;
    }
}

/*================================================================================================
@brief   Send the LE Server's notification to the client
@details Send the HCI command of sending the LE Server's notification to the client to Cypress
         module. The data length should not exceed the limit specified in GATT_DATA_MAX_SIZE
@return  None
@retval  Whether or not the HCI command is sent to Cypress module successfully
================================================================================================*/
bool BLE_core_server_notify
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint8_t data_len
    )
{
bool ret = false;
uint8_t param[BT_CONNECTION_HANDLE_LEN + GATT_ATTR_HANDLE_LEN + data_len];

if( ( NULL == data ) || ( 0 == data_len ) || ( data_len > GATT_DATA_MAX_SIZE ) )
    {
    BT_LOG_DEBUG( "Invalid data" );
    }
else if( BLE_SERVER_TYPE_INVALID == BLE_core_server_find_handle_owner( handle ) )
    {
    BT_LOG_DEBUG( "No LE server owning this handle: 0x%x", handle );
    }
else if( false ==  BLE_core_server_get_connection_status() )
    {
    BT_LOG_DEBUG( "No connection" );
    }
else
    {
    if( BT_tsk_sync_gatt_send_wait() )
        {
        memset( param, 0, sizeof( param ) );
        INT16_TO_LITTLE_ENDIAN( s_core.connection_handle, &( param[0] ) );
        INT16_TO_LITTLE_ENDIAN( handle, &( param[2] ) );
        memcpy( &( param[4] ), data, data_len );

        ret = HCI_send_wiced_command( HCI_CONTROL_GATT_COMMAND_NOTIFY, param, sizeof( param ) );
        }
    }
return ret;
}

/*================================================================================================
@brief   Send the LE Server's response to the read request sent from the client
@details Send the HCI command of sending the LE Server's response to the read request sent from
         the client to Cypress module. The data length should not exceed the limit specified in
         GATT_DATA_MAX_SIZE
@return  None
@retval  Whether or not the HCI command is sent to Cypress module successfully
================================================================================================*/
bool BLE_core_server_read_response
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint8_t data_len
    )
{
bool ret = false;
uint8_t param[BT_CONNECTION_HANDLE_LEN + GATT_ATTR_HANDLE_LEN + data_len];

if( ( NULL == data ) || ( 0 == data_len ) || ( data_len > GATT_DATA_MAX_SIZE ) )
    {
    BT_LOG_DEBUG( "Invalid data" );
    }
else if( BLE_SERVER_TYPE_INVALID == BLE_core_server_find_handle_owner( handle ) )
    {
    BT_LOG_DEBUG( "No server owning the handle: 0x%x", handle );
    }
else if( false ==  BLE_core_server_get_connection_status() )
    {
    BT_LOG_DEBUG( "No connection" );
    }
else
    {
    memset( param, 0, sizeof( param ) );
    INT16_TO_LITTLE_ENDIAN( s_core.connection_handle, &( param[0] ) );
    INT16_TO_LITTLE_ENDIAN( handle, &( param[2] ) );
    memcpy( &( param[4] ), data, data_len );

    ret = HCI_send_wiced_command( HCI_CONTROL_GATT_COMMAND_READ_RESPONSE, param, sizeof( param ) );
    }
return ret;
}

/*================================================================================================
@brief   Register the callbacks to listen the LE Server's updates
@details Register the callbacks to listen the LE Server's updates
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BLE_core_server_register_callback
    (
    const BLE_server_type_e server_type,
    const BLE_server_callback_t* callbacks
    )
{
bool ret = false;

if( ( server_type < 0 ) || ( server_type >= BLE_SERVER_TYPE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid server type: %d", server_type );
    }
else if( NULL == callbacks )
    {
    BT_LOG_DEBUG( "NULL callbacks" );
    }
else
    {
    memcpy( &( s_core.servers[server_type].callbacks ), callbacks, sizeof( BLE_server_callback_t ) );
    ret = true;
    }
return ret;
}

/*================================================================================================
@brief   Reset Bluetooth Manager LE Server Core's data
@details Reset Bluetooth Manager LE Server Core's data
@return  None
@retval  None
================================================================================================*/
void BLE_core_server_reset( void )
{
for( BLE_server_type_e server_type = 0; server_type < BLE_SERVER_TYPE_CNT; ++server_type )
    {
    if( s_core.acl_connected )
        {
        if( NULL != s_core.servers[server_type].callbacks.le_disconnected_callback )
            {
            s_core.servers[server_type].callbacks.le_disconnected_callback();
            }
        }
    }

s_core.advertising_mode = BLE_ADVERTISING_OFF;
s_core.acl_connected = false;
s_core.connection_handle = 0;
}

/*================================================================================================
@brief   Set the LE Server's advertising mode to start or stop LE advertising
@details Send the HCI command of starting or stopping LE advertising to Cypress module. The maximum
         data length should not exceed the limit specified in BLE_ADVERTISING_DATA_MAX_SIZE
@return  None
@retval  Whether or not the HCI command is sent to Cypress module successfully
================================================================================================*/
bool BLE_core_server_set_advertising_mode
    (
    const BLE_advertising_mode_e advertising_mode,
    const BLE_advertising_data_type_e data_type,
    const uint8_t* data,
    const uint8_t data_len
    )
{
bool ret = false;
uint8_t param[1 + 1 + 1 + data_len];

if( ( advertising_mode < 0 ) || ( advertising_mode >= BLE_ADVERTISING_MODE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid advertising mode: %d", advertising_mode );
    }
else if( ( data_type < 0 ) || ( data_type >= BLE_ADVERTISING_DATA_TYPE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid data type: %d", data_type );
    }
else if( ( NULL == data ) || ( 0 == data_len ) || ( data_len > BLE_ADVERTISING_DATA_MAX_SIZE ) )
    {
    BT_LOG_DEBUG( "Invalid data" );
    }
else if( advertising_mode == s_core.advertising_mode )
    {
    BT_LOG_DEBUG( "Duplicate request: %s", BLE_util_get_advertising_mode_string( advertising_mode ) );
    }
else
    {
    memset( param, 0, sizeof( param ) );
    param[0] = advertising_mode;
    param[1] = data_type;
    param[2] = data_len;
    memcpy( &( param[3] ), data, data_len );

    ret = HCI_send_wiced_command( HCI_CONTROL_LE_COMMAND_ADVERTISE_GARMIN, param, sizeof( param ) );
    if( ret )
        {
        BT_LOG_DEBUG( "Advertising mode: %s -> %s",
                      BLE_util_get_advertising_mode_string( s_core.advertising_mode ),
                      BLE_util_get_advertising_mode_string( advertising_mode ) );
        s_core.advertising_mode = advertising_mode ;
        }
    }
return ret;
}

// HCI event handler

/*================================================================================================
@brief   Handle the GATT event that the read request from the client is received
@details Handle the GATT event that the read request from the client is received
@return  None
@retval  None
================================================================================================*/
void BLE_core_server_handle_gatt_event_read_request
    (
    const uint16_t connection_handle,
    const uint16_t handle
    )
{
BT_request_t request = { 0 };
uint8_t device_name_len = 0;
const uint8_t* local_device_name;
BLE_server_type_e server_type = BLE_core_server_find_handle_owner( handle );

if( BLE_SERVER_TYPE_INVALID == server_type )
    {
    BT_LOG_ERROR( "No LE server owning this handle: 0x%x", handle );
    }
else
    {
    if( HDLC_GAP_DEVICE_NAME_VALUE == handle )
        {
        local_device_name = BT_core_get_local_device_name();
        device_name_len = strlen( (const char*)local_device_name );

        request.type = BT_REQUEST_LE_SERVER_READ_RESPONSE;
        request.param_u.le_server_read_response.handle = handle;
        request.param_u.le_server_read_response.data_len = device_name_len;
        memcpy( request.param_u.le_server_read_response.data, local_device_name, device_name_len );
        BT_tsk_send_request( &request );
        }
    else
        {
        if( NULL != s_core.servers[server_type].callbacks.read_request_received_callback )
            {
            s_core.servers[server_type].callbacks.read_request_received_callback( handle );
            }
        }
    }
}

/*================================================================================================
@brief   Handle the GATT event that the write request from the client is received
@details Handle the GATT event that the write request from the client is received
@return  None
@retval  None
================================================================================================*/
void BLE_core_server_handle_gatt_event_write_request
    (
    const uint16_t connection_handle,
    const uint16_t handle,
    const uint8_t* data,
    const uint8_t data_len
    )
{
BLE_server_type_e server_type = BLE_core_server_find_handle_owner( handle );

if( BLE_SERVER_TYPE_INVALID == server_type )
    {
    BT_LOG_ERROR( "No LE server owning this handle: 0x%x", handle );
    }
else
    {
    if( NULL != s_core.servers[server_type].callbacks.write_request_received_callback )
        {
        s_core.servers[server_type].callbacks.write_request_received_callback( handle, data, data_len );
        }
    }
}

/*================================================================================================
@brief   Handle the LE event that LE is connected to the remote device
@details Handle the LE event that LE is connected to the remote device
@return  None
@retval  None
================================================================================================*/
void BLE_core_server_handle_le_event_connected
    (
    const uint16_t connection_handle
    )
{
s_core.acl_connected = true;
s_core.connection_handle = connection_handle;

for( BLE_server_type_e server_type = 0; server_type < BLE_SERVER_TYPE_CNT; ++server_type )
    {
    if( NULL != s_core.servers[server_type].callbacks.le_connected_callback )
        {
        s_core.servers[server_type].callbacks.le_connected_callback();
        }
    }
}

/*================================================================================================
@brief   Handle the LE event that LE is disconnected from the remote device
@details Handle the LE event that LE is disconnected from the remote device
@return  None
@retval  None
================================================================================================*/
void BLE_core_server_handle_le_event_disconnected
    (
    const uint16_t connection_handle
    )
{
s_core.acl_connected = false;
s_core.connection_handle = 0;

for( BLE_server_type_e server_type = 0; server_type < BLE_SERVER_TYPE_CNT; ++server_type )
    {
    if( NULL != s_core.servers[server_type].callbacks.le_disconnected_callback )
        {
        s_core.servers[server_type].callbacks.le_disconnected_callback();
        }
    }
}

#ifdef __cplusplus
}
#endif
