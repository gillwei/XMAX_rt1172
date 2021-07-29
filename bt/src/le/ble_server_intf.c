/*********************************************************************
* @file  ble_server_intf.c
* @brief Bluetooth Manager Public LE Server interface definition.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <string.h>

#include "BT_pub.h"
#include "bt_core.h"
#include "bt_tsk.h"
#include "bt_utils.h"
#include "ble_server_core.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/

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

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Disconnect the LE Server from the client
@details Send the request of disconnecting the LE Server from the client to Bluetooth Manager.
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BLE_server_disconnect( void )
{
BT_request_t request = { 0 };

FUNC_ENTRY_PRINT();

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

if( false == BLE_core_server_get_connection_status() )
    {
    FUNC_NO_CONNECTION_PRINT();
    return BT_STATUS_NO_CONNECTION;
    }

request.type = BT_REQUEST_LE_SERVER_DISCONNECT;
if( false == BT_tsk_send_request( &request ) )
    {
    FUNC_QUEUE_FULL_PRINT();
    return BT_STATUS_QUEUE_FULL;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Get the LE Server's advertising mode
@details Directly get the LE Server's advertising mode
@return  None
@retval  The LE Server's advertising mode
================================================================================================*/
BLE_advertising_mode_e BLE_server_get_advertising_mode( void )
{
FUNC_ENTRY_PRINT();

return BLE_core_server_get_advertising_mode();
}

/*================================================================================================
@brief   Send the LE Server's notification to the client
@details Send the request of sending the LE Server's notification to the client to Bluetooth Manager.
         The data length should not exceed the limit specified in GATT_DATA_MAX_SIZE
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BLE_server_notify
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint8_t data_len
    )
{
BT_request_t request = { 0 };

FUNC_ENTRY_PRINT( "( handle=0x%x, data_len=%u )", handle, data_len );

if( ( NULL == data ) || ( 0 == data_len ) || ( data_len > GATT_DATA_MAX_SIZE ) ||
    ( BLE_SERVER_TYPE_INVALID == BLE_core_server_find_handle_owner( handle ) ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

if( false == BLE_core_server_get_connection_status() )
    {
    FUNC_NO_CONNECTION_PRINT();
    return BT_STATUS_NO_CONNECTION;
    }

request.type = BT_REQUEST_LE_SERVER_NOTIFY;
request.param_u.le_server_notify.handle = handle;
request.param_u.le_server_notify.data_len = data_len;
memcpy( request.param_u.le_server_notify.data, data, data_len );
if( false == BT_tsk_send_request( &request ) )
    {
    FUNC_QUEUE_FULL_PRINT();
    return BT_STATUS_QUEUE_FULL;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Send the LE Server's response to the read request sent from the client
@details Send the request of sending the LE Server's response to the read request sent from the
         client to Bluetooth Manager. The data length should not exceed the limit specified in
         GATT_DATA_MAX_SIZE
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BLE_server_read_response
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint8_t data_len
    )
{
BT_request_t request = { 0 };

FUNC_ENTRY_PRINT( "( handle=0x%x, data_len=%u )", handle, data_len );

if( ( NULL == data ) || ( 0 == data_len ) || ( data_len > GATT_DATA_MAX_SIZE ) ||
    ( BLE_SERVER_TYPE_INVALID == BLE_core_server_find_handle_owner( handle ) ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

if( false == BLE_core_server_get_connection_status() )
    {
    FUNC_NO_CONNECTION_PRINT();
    return BT_STATUS_NO_CONNECTION;
    }

request.type = BT_REQUEST_LE_SERVER_READ_RESPONSE;
request.param_u.le_server_read_response.handle = handle;
request.param_u.le_server_read_response.data_len = data_len;
memcpy( request.param_u.le_server_read_response.data, data, data_len );
if( false == BT_tsk_send_request( &request ) )
    {
    FUNC_QUEUE_FULL_PRINT();
    return BT_STATUS_QUEUE_FULL;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Register the callbacks to listen the LE Server's updates
@details Directly register the callbacks in Bluetooth Manager LE Server Core to listen the LE
         Server's updates
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BLE_server_register_callback
    (
    const BLE_server_type_e server_type,
    const BLE_server_callback_t* callbacks
    )
{
FUNC_ENTRY_PRINT( "( server=%s )", BLE_util_get_server_type_string( server_type ) );

if( ( server_type < 0 ) || ( server_type >= BLE_SERVER_TYPE_INVALID ) || ( NULL == callbacks ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

if( false == BLE_core_server_register_callback( server_type, callbacks ) )
    {
    FUNC_NOT_ALLOWED_PRINT();
    return BT_STATUS_NOT_ALLOWED;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Set the LE Server's advertising mode to start or stop LE advertising
@details Send the request of starting or stopping LE advertising to Bluetooth Manager. The data
         length should not exceed the limit specified in BLE_ADVERTISING_DATA_MAX_SIZE
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BLE_server_set_advertising_mode
    (
    const BLE_advertising_mode_e advertising_mode,
    const BLE_advertising_data_type_e data_type,
    const uint8_t* data,
    const uint8_t data_len
    )
{
BT_request_t request = { 0 };

FUNC_ENTRY_PRINT( "( advertising_mode=%s, data_type=%d, data_len=%u )",
                  BLE_util_get_advertising_mode_string( advertising_mode ),
                  data_type,
                  data_len );

if( ( advertising_mode < 0 ) || ( advertising_mode >= BLE_ADVERTISING_MODE_INVALID ) ||
    ( data_type < 0 ) || ( data_type >= BLE_ADVERTISING_DATA_TYPE_INVALID ) ||
    ( NULL == data ) || ( 0 == data_len ) || ( data_len > BLE_ADVERTISING_DATA_MAX_SIZE ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

if( advertising_mode == BLE_core_server_get_advertising_mode() )
    {
    FUNC_NOT_ALLOWED_PRINT();
    return BT_STATUS_NOT_ALLOWED;
    }

request.type = BT_REQUEST_LE_SERVER_SET_ADVERTISING_MODE;
request.param_u.le_server_set_advertising_mode.advertising_mode = advertising_mode;
request.param_u.le_server_set_advertising_mode.data_type = data_type;
request.param_u.le_server_set_advertising_mode.data_len = data_len;
memcpy( request.param_u.le_server_set_advertising_mode.data, data, data_len );
if( false == BT_tsk_send_request( &request ) )
    {
    FUNC_QUEUE_FULL_PRINT();
    return BT_STATUS_QUEUE_FULL;
    }

return BT_STATUS_OK;
}

#ifdef __cplusplus
}
#endif
