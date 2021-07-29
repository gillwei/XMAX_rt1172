/*********************************************************************
* @file  bt_spp_intf.c
* @brief Bluetooth Manager Public SPP interface definition.
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
#include "bt_spp_core.h"
#include "bt_tsk.h"
#include "bt_utils.h"

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
@brief   Add the callback to listen the SPP app's connection status change
@details Directly register the callback in Bluetooth Manager SPP Core to listen the SPP app's
         connection status change. The limit number of registered callbacks for each SPP app is
         specified in SPP_APP_CONNECTION_STATUS_CB_MAX_NUM
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_spp_add_connection_status_callback
    (
    const BT_spp_app_type_e app_type,
    BT_spp_connection_status_callback callback
    )
{
FUNC_ENTRY_PRINT( "( app=%s )", BT_util_get_spp_app_type_string( app_type ) );

if( ( app_type < 0 ) || ( app_type >= BT_SPP_APP_TYPE_INVALID ) || ( NULL == callback ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

if( false == BT_core_spp_add_connection_status_callback( app_type, callback ) )
    {
    FUNC_NOT_ALLOWED_PRINT();
    return BT_STATUS_NOT_ALLOWED;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Add the callback to listen the SPP app's received data
@details Directly register the callback in Bluetooth Manager SPP Core to listen the SPP app's
         received data. The limit number of registered callbacks for each SPP app is specified
         in SPP_APP_DATA_RECEIVED_CB_MAX_NUM
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_spp_add_data_received_callback
    (
    const BT_spp_app_type_e app_type,
    BT_spp_data_received_callback callback
    )
{
FUNC_ENTRY_PRINT( "( app=%s )", BT_util_get_spp_app_type_string( app_type ) );

if( ( app_type < 0 ) || ( app_type >= BT_SPP_APP_TYPE_INVALID ) || ( NULL == callback ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

if( false == BT_core_spp_add_data_received_callback( app_type, callback ) )
    {
    FUNC_NOT_ALLOWED_PRINT();
    return BT_STATUS_NOT_ALLOWED;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Connect the SPP app to the remote device
@details Send the request of connecting the SPP app to the remote device to Bluetooth Manager
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_spp_connect
    (
    const uint8_t* bd_addr,
    const BT_spp_app_type_e app_type
    )
{
BT_request_t request = { 0 };
BT_connection_status_e connection_status = BT_core_spp_get_connection_status( app_type, NULL );

FUNC_ENTRY_PRINT();

if( ( NULL == bd_addr ) || ( app_type < 0 ) || ( app_type >= BT_SPP_APP_TYPE_INVALID ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

FUNC_ENTRY_PRINT( "( bd_addr=%02x:%02x:%02x:%02x:%02x:%02x, app=%s )",
                  BD_ADDR_PRINT( bd_addr ),
                  BT_util_get_spp_app_type_string( app_type ) );

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

if( false == BT_core_is_paired_device( bd_addr ) )
    {
    FUNC_NOT_ALLOWED_PRINT();
    return BT_STATUS_NOT_ALLOWED;
    }

if( BT_core_is_paired_device_auth_lost( bd_addr ) )
    {
    FUNC_AUTH_LOST_PRINT();
    return BT_STATUS_AUTH_LOST;
    }

if( BT_CONNECTION_CONNECTED == connection_status )
    {
    FUNC_NOT_ALLOWED_PRINT();
    return BT_STATUS_NOT_ALLOWED;
    }
else if( BT_CONNECTION_DISCONNECTED != connection_status )
    {
    FUNC_BUSY_PRINT();
    return BT_STATUS_BUSY;
    }

request.type = BT_REQUEST_SPP_CONNECT;
request.param_u.spp_connect.app_type = app_type;
memcpy( request.param_u.spp_connect.bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN );
if( false == BT_tsk_send_request( &request ) )
    {
    FUNC_QUEUE_FULL_PRINT();
    return BT_STATUS_QUEUE_FULL;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Disconnect the SPP app from the remote device
@details Send the request of disconnecting the SPP app from the remote device to Bluetooth Manager
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_spp_disconnect
    (
    const uint8_t* bd_addr,
    const BT_spp_app_type_e app_type
    )
{
BT_request_t request = { 0 };
uint8_t cur_bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };
BT_connection_status_e connection_status = BT_core_spp_get_connection_status( app_type, cur_bd_addr );

FUNC_ENTRY_PRINT();

if( ( NULL == bd_addr ) || ( app_type < 0 ) || ( app_type >= BT_SPP_APP_TYPE_INVALID ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

FUNC_ENTRY_PRINT( "( bd_addr=%02x:%02x:%02x:%02x:%02x:%02x, app=%s )",
                  BD_ADDR_PRINT( bd_addr ),
                  BT_util_get_spp_app_type_string( app_type ) );

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

if( BT_CONNECTION_DISCONNECTED == connection_status )
    {
    FUNC_NO_CONNECTION_PRINT();
    return BT_STATUS_NO_CONNECTION;
    }
else if( BT_CONNECTION_CONNECTED != connection_status )
    {
    FUNC_BUSY_PRINT();
    return BT_STATUS_BUSY;
    }
else if( 0 != memcmp( cur_bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN ) )
    {
    FUNC_NO_CONNECTION_PRINT();
    return BT_STATUS_NO_CONNECTION;
    }

request.type = BT_REQUEST_SPP_DISCONNECT;
request.param_u.spp_disconnect.app_type = app_type;
memcpy( request.param_u.spp_disconnect.bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN );
if( false == BT_tsk_send_request( &request ) )
    {
    FUNC_QUEUE_FULL_PRINT();
    return BT_STATUS_QUEUE_FULL;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Read MFi authentication chip info and report the received info to IOP
@details Send the request of reading MFI authentication chip info to Bluetooth Manager. When the
         info is received report it back to IOP
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_spp_read_mfi_auth_chip_info( void )
{
BT_request_t request = { 0 };

FUNC_ENTRY_PRINT();

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

request.type = BT_REQUEST_SPP_READ_MFI_AUTH_CHIP_INFO;
if( false == BT_tsk_send_request( &request ) )
    {
    FUNC_QUEUE_FULL_PRINT();
    return BT_STATUS_QUEUE_FULL;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Send the SPP app data to the remote device
@details Send the request of sending the SPP app data to the remote device to Bluetooth Manager.
         The length of data to send should not exceed the limit specified in SPP_DATA_MAX_SIZE
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_spp_send_data
    (
    const uint8_t* bd_addr,
    const BT_spp_app_type_e app_type,
    const uint8_t* data,
    const uint8_t data_len
    )
{
BT_request_t request = { 0 };
uint8_t cur_bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };
BT_connection_status_e connection_status = BT_core_spp_get_connection_status( app_type, cur_bd_addr );

FUNC_ENTRY_PRINT();

if( ( NULL == bd_addr ) ||
    ( app_type < 0 ) || ( app_type >= BT_SPP_APP_TYPE_INVALID ) ||
    ( NULL == data ) || ( 0 == data_len ) || ( data_len > SPP_DATA_MAX_SIZE ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

FUNC_ENTRY_PRINT( "( bd_addr=%02x:%02x:%02x:%02x:%02x:%02x, app=%s, data_len=%u )",
                  BD_ADDR_PRINT( bd_addr ),
                  BT_util_get_spp_app_type_string( app_type ),
                  data_len );

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

if( ( BT_CONNECTION_CONNECTED != connection_status ) ||
    ( 0 != memcmp( cur_bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN ) ) )
    {
    FUNC_NO_CONNECTION_PRINT();
    return BT_STATUS_NO_CONNECTION;
    }

request.type = BT_REQUEST_SPP_SEND_DATA;
request.param_u.spp_send_data.app_type = app_type;
request.param_u.spp_send_data.data_len = data_len;
memcpy( request.param_u.spp_send_data.bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN );
memcpy( request.param_u.spp_send_data.data, data, data_len );
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
