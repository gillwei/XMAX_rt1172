/*********************************************************************
* @file  ble_client_intf.c
* @brief Bluetooth Manager Public LE Client interface definition.
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
#include "ble_client_core.h"

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
@brief   Register the callbacks to listen the LE Client's updates
@details Directly register the callbacks in Bluetooth Manager LE Client Core to listen the LE
         Client's updates
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BLE_client_register_callback
    (
    const BLE_client_type_e client_type,
    const BLE_client_callback_t* callbacks
    )
{
FUNC_ENTRY_PRINT( "( client=%s )", BLE_util_get_client_type_string( client_type ) );

if( ( client_type < 0 ) || ( client_type >= BLE_CLIENT_TYPE_INVALID ) || ( NULL == callbacks ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

if( false == BLE_core_client_register_callback( client_type, callbacks ) )
    {
    FUNC_NOT_ALLOWED_PRINT();
    return BT_STATUS_NOT_ALLOWED;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Send the LE Client's write request to the server
@details Send the request of sending the LE Client's write request to the server to Bluetooth
         Manager. The data length should not exceed the limit specified in GATT_DATA_MAX_SIZE
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BLE_client_write_request
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint8_t data_len
    )
{
BT_request_t request = { 0 };

FUNC_ENTRY_PRINT( "( handle=0x%x, data_len=%u )", handle, data_len );

if( ( NULL == data ) || ( 0 == data_len ) || ( data_len > GATT_DATA_MAX_SIZE ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

if( BLE_CLIENT_TYPE_INVALID == BLE_core_client_find_handle_owner( handle ) )
    {
    FUNC_NO_CONNECTION_PRINT();
    return BT_STATUS_NO_CONNECTION;
    }

request.type = BT_REQUEST_LE_CLIENT_WRITE_REQUEST;
request.param_u.le_client_write_request.handle = handle;
request.param_u.le_client_write_request.data_len = data_len;
memcpy( request.param_u.le_client_write_request.data, data, data_len );
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
