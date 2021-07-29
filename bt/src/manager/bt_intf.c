/*********************************************************************
* @file  bt_intf.c
* @brief Bluetooth Manager Public General interface definition.
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
@brief   Accept or reject current pairing request
@details Send the request of accepting or rejecting current pairing request to Bluetooth Manager
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_accept_pairing
    (
    const bool accept
    )
{
BT_request_t request = { 0 };
BT_pairing_status_e pairing_status = BT_core_get_pairing_status();

FUNC_ENTRY_PRINT( "( accept=%d )", accept );

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

if( BT_PAIRING_NONE == pairing_status )
    {
    FUNC_NOT_ALLOWED_PRINT();
    return BT_STATUS_NOT_ALLOWED;
    }

if( BT_PAIRING_CONFIRMED_WAITING == pairing_status )
    {
    FUNC_BUSY_PRINT();
    return BT_STATUS_BUSY;
    }

request.type = BT_REQUEST_ACCEPT_PAIRING;
request.param_u.accept_pairing.accept = accept;
if( false == BT_tsk_send_request( &request ) )
    {
    FUNC_QUEUE_FULL_PRINT();
    return BT_STATUS_QUEUE_FULL;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Delete the paired device
@details Send the request of deleting the paired device to Bluetooth Manager
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_delete_paired_device
    (
    const uint8_t* bd_addr
    )
{
BT_request_t request = { 0 };

FUNC_ENTRY_PRINT();

if( NULL == bd_addr )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

FUNC_ENTRY_PRINT( "( bd_addr=%02x:%02x:%02x:%02x:%02x:%02x )", BD_ADDR_PRINT( bd_addr ) );

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

request.type = BT_REQUEST_DELETE_PAIRED_DEVICE;
memcpy( request.param_u.delete_paired_device.bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN );
if( false == BT_tsk_send_request( &request ) )
    {
    FUNC_QUEUE_FULL_PRINT();
    return BT_STATUS_QUEUE_FULL;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Reset to factory default
@details Send the request of factory reset to Bluetooth Manager
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_factory_reset( void )
{
BT_request_t request = { 0 };

FUNC_ENTRY_PRINT();

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

request.type = BT_REQUEST_FACTORY_RESET;
if( false == BT_tsk_send_request( &request ) )
    {
    FUNC_QUEUE_FULL_PRINT();
    return BT_STATUS_QUEUE_FULL;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Get whether or not the discoverable mode is enabled
@details Directly get the info of whether or not the discoverable mode is enabled
@return  None
@retval  Whether or not the discoverable mode is enabled
================================================================================================*/
bool BT_get_discoverable_state( void )
{
FUNC_ENTRY_PRINT();

return BT_core_get_discoverable_state();
}

/*================================================================================================
@brief   Get whether or not Bluetooth is enabled and ready to use
@details Directly get the info of whether or not BT is enabled and ready to use
@return  None
@retval  Whether or not Bluetooth is enabled and ready to use
================================================================================================*/
bool BT_get_enable_state( void )
{
FUNC_ENTRY_PRINT();

return ( BT_POWER_ON_READY == BT_core_get_power_status() );
}

/*================================================================================================
@brief   Get local Bluetooth device address
@details Directly get the info of local Bluetooth device address
@return  None
@retval  Local Bluetooth device address
================================================================================================*/
const uint8_t* BT_get_local_device_address( void )
{
FUNC_ENTRY_PRINT();

return BT_core_get_local_device_address();
}

/*================================================================================================
@brief   Get local Bluetooth device name
@details Directly get the info of local Bluetooth device name
@return  None
@retval  Local Bluetooth device name
================================================================================================*/
const uint8_t* BT_get_local_device_name( void )
{
FUNC_ENTRY_PRINT();

return BT_core_get_local_device_name();
}

/*================================================================================================
@brief   Get the number of paired devices
@details Directly get the info of number of paired devices
@return  num_devices: the number of paired devices
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_get_num_paired_devices
    (
    uint8_t* num_devices
    )
{
FUNC_ENTRY_PRINT();

if( NULL == num_devices )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

*num_devices = 0;

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

*num_devices = BT_core_get_num_paired_devices();

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Get info of the paired device
@details Directly get the info of paired device
@return  device_info: info of the paired device
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_get_paired_device_info
    (
    const uint8_t device_idx,
    BT_device_info_t* device_info
    )
{
FUNC_ENTRY_PRINT( "( device_idx=%u )", device_idx );

if( ( NULL == device_info ) || ( device_idx >= BT_core_get_num_paired_devices() ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

memset( device_info, 0, sizeof( BT_device_info_t ) );

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

const BT_device_info_t* core_device_info = BT_core_get_paired_device_info( device_idx );
memcpy( device_info, core_device_info, sizeof( BT_device_info_t ) );

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Get Bluetooth Manager's software version
@details Directly get the info of Bluetooth Manager's software version
@return  major_version: The major version
         minor_version: The minor version
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_get_sw_version
    (
    uint8_t* major_version,
    uint8_t* minor_version
    )
{
FUNC_ENTRY_PRINT();

if( ( NULL == major_version ) || ( NULL == minor_version ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

*major_version = 0;
*minor_version = 0;

if( false == BT_core_get_sw_version( major_version, minor_version ) )
    {
    FUNC_NOT_ALLOWED_PRINT();
    return BT_STATUS_NOT_ALLOWED;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Get whether or not the Bluetooth hardware's test mode is enabled
@details Directly get the info of whether or not the Bluetooth hardware's test mode is enabled
@return  None
@retval  Whether or not the Bluetooth hardware's test mode is enabled
================================================================================================*/
bool BT_get_test_mode( void )
{
FUNC_ENTRY_PRINT();

return BT_core_get_test_mode();
}

/*================================================================================================
@brief   Bluetooth Manager initialization
@details Create Bluetooth Manager Main and HCI tasks then continue the initialization process
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_init( void )
{
FUNC_ENTRY_PRINT();

BT_tsk_init();

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Check whether or not this is a paired BR/EDR device
@details Directly get the info of whether or not this is a paired BR/EDR device
@return  paired: whether or not this is a paired BR/EDR device
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_is_paired_device
    (
    const uint8_t* bd_addr,
    bool* paired
    )
{
FUNC_ENTRY_PRINT();

if( ( NULL == bd_addr ) || ( NULL == paired ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

FUNC_ENTRY_PRINT( "( bd_addr=%02x:%02x:%02x:%02x:%02x:%02x )", BD_ADDR_PRINT( bd_addr ) );
*paired = false;

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

*paired = BT_core_is_paired_device( bd_addr );

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Check whether or not the paired device has lost its authentication data
@details Directly get the info of whether or not the paired device has lost its authentication data
@return  auth_lost: whether or not the paired device has lost its authentication data
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_is_paired_device_auth_lost
    (
    const uint8_t* bd_addr,
    bool* auth_lost
    )
{
FUNC_ENTRY_PRINT();

if( ( NULL == bd_addr ) || ( NULL == auth_lost ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

FUNC_ENTRY_PRINT( "( bd_addr=%02x:%02x:%02x:%02x:%02x:%02x )", BD_ADDR_PRINT( bd_addr ) );
*auth_lost = false;

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

*auth_lost = BT_core_is_paired_device_auth_lost( bd_addr );

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Check whether or not the number of paired devices reached the limit
@details Directly get the info of whether or not the number of paired devices reached the limit
@return  max_num_reached: whether or not the number of paired devices reached the limit
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_is_paired_device_max_num_reached
    (
    bool* max_num_reached
    )
{
FUNC_ENTRY_PRINT();

if( NULL == max_num_reached )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

*max_num_reached = false;

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

*max_num_reached = BT_core_is_paired_device_max_num_reached();

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Check whether or not this is a paired LE device
@details Directly get the info of whether or not this is a paired LE device
@return  paired: whether or not this is a paired LE device
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_is_paired_le_device
    (
    const uint8_t* bd_addr,
    bool* paired
    )
{
FUNC_ENTRY_PRINT();

if( ( NULL == bd_addr ) || ( NULL == paired ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

FUNC_ENTRY_PRINT( "( bd_addr=%02x:%02x:%02x:%02x:%02x:%02x )", BD_ADDR_PRINT( bd_addr ) );
*paired = false;

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

*paired = BT_core_is_paired_le_device( bd_addr );

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Set Bluetooth Manager to automatically accept pairing request once
@details Directly set Bluetooth Manager to automatically accept pairing request once
@return  None
@retval  None
================================================================================================*/
void BT_set_auto_pairing_once( void )
{
FUNC_ENTRY_PRINT();

BT_core_set_auto_pairing_once();
}

/*================================================================================================
@brief   Enable or Disable the discoverable mode
@details Send the request of enabling or disabling the discoverable mode to Bluetooth Manager
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_set_discoverable_state
    (
    const bool enable
    )
{
BT_request_t request = { 0 };

FUNC_ENTRY_PRINT( "( enable=%d )", enable );

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

if( enable == BT_core_get_discoverable_state() )
    {
    FUNC_NOT_ALLOWED_PRINT();
    return BT_STATUS_NOT_ALLOWED;
    }

request.type = BT_REQUEST_SET_DISCOVERABLE_STATE;
request.param_u.set_discoverable_state.enable = enable;
if( false == BT_tsk_send_request( &request ) )
    {
    FUNC_QUEUE_FULL_PRINT();
    return BT_STATUS_QUEUE_FULL;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Enable or Disable Bluetooth by powering on or off the Bluetooth hardware
@details Send the request of enabling or disabling Bluetooth by powering on or off the Bluetooth
         hardware to Bluetooth Manager
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_set_enable_state
    (
    const bool enable
    )
{
BT_request_t request = { 0 };
BT_power_status_e power_status = BT_core_get_power_status();

FUNC_ENTRY_PRINT( "( enable=%d )", enable );

if( enable )
    {
    if( ( BT_POWER_ON == power_status ) || ( BT_POWER_ON_UPDATING == power_status ) )
        {
        FUNC_BUSY_PRINT();
        return BT_STATUS_BUSY;
        }
    else if( BT_POWER_ON_READY == power_status )
        {
        FUNC_NOT_ALLOWED_PRINT();
        return BT_STATUS_NOT_ALLOWED;
        }
    }
else
    {
    if( ( BT_POWER_OFF == power_status ) || ( BT_POWER_ON_UPDATING == power_status ) )
        {
        FUNC_NOT_ALLOWED_PRINT();
        return BT_STATUS_NOT_ALLOWED;
        }
    }

BT_tsk_clear_requests();

request.type = BT_REQUEST_SET_ENABLE_STATE;
request.param_u.set_enable_state.enable = enable;
if( false == BT_tsk_send_request( &request ) )
    {
    FUNC_QUEUE_FULL_PRINT();
    return BT_STATUS_QUEUE_FULL;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Set local Bluetooth device address
@details Send the request of setting local Bluetooth device address to Bluetooth Manager
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_set_local_device_address
    (
    const uint8_t* bd_addr
    )
{
BT_request_t request = { 0 };
const uint8_t* cur_bd_addr = BT_core_get_local_device_address();

FUNC_ENTRY_PRINT();

if( NULL == bd_addr )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

FUNC_ENTRY_PRINT( "( bd_addr=%02x:%02x:%02x:%02x:%02x:%02x )", BD_ADDR_PRINT( bd_addr ) );

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

if( 0 == memcmp( cur_bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN ) )
    {
    FUNC_NOT_ALLOWED_PRINT();
    return BT_STATUS_NOT_ALLOWED;
    }

request.type = BT_REQUEST_SET_LOCAL_DEVICE_ADDRESS;
memcpy( request.param_u.set_local_device_address.bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN );
if( false == BT_tsk_send_request( &request ) )
    {
    FUNC_QUEUE_FULL_PRINT();
    return BT_STATUS_QUEUE_FULL;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Set Bluetooth Manager's log level
@details Directly set Bluetooth Manager's log level
@return  None
@retval  None
================================================================================================*/
void BT_set_log_level
    (
    const BT_log_severity_e severity
    )
{
FUNC_ENTRY_PRINT( "( severity=%d )", severity );

if( ( severity < 0 ) || ( severity >= BT_LOG_SEVERITY_INVALID ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return;
    }

BT_core_set_log_level( severity );
}

/*================================================================================================
@brief   Enable or disable the Bluetooth hardware's test mode
@details Send the request of enabling or disabling the Bluetooth hardware's test mode to Bluetooth
         Manager
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_set_test_mode
    (
    const bool enable
    )
{
BT_request_t request = { 0 };

FUNC_ENTRY_PRINT( "( enable=%d )", enable );

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

if( enable == BT_core_get_test_mode() )
    {
    FUNC_NOT_ALLOWED_PRINT();
    return BT_STATUS_NOT_ALLOWED;
    }

request.type = BT_REQUEST_SET_TEST_MODE;
request.param_u.set_test_mode.enable = enable;
if( false == BT_tsk_send_request( &request ) )
    {
    FUNC_QUEUE_FULL_PRINT();
    return BT_STATUS_QUEUE_FULL;
    }

return BT_STATUS_OK;
}

/*================================================================================================
@brief   Start or stop the Bluetooth hardware's Tx carrier test
@details Send the request of starting or stopping the Bluetooth hardware's Tx carrier test to
         Bluetooth Manager
@return  None
@retval  The error code specified in BT_status_e
================================================================================================*/
BT_status_e BT_set_tx_carrier_mode
    (
    const bool enable,
    const BT_tx_channel_type_e channel_type
    )
{
BT_request_t request = { 0 };

FUNC_ENTRY_PRINT( "( enable=%d, channel_type=%d )", enable, channel_type );

if( ( channel_type < 0 ) || ( channel_type >= BT_TX_CH_TYPE_INVALID ) )
    {
    FUNC_INVALID_PARAM_PRINT();
    return BT_STATUS_INVALID_PARAMETER;
    }

if( BT_POWER_ON_READY != BT_core_get_power_status() )
    {
    FUNC_NOT_READY_PRINT();
    return BT_STATUS_NOT_READY;
    }

request.type = BT_REQUEST_SET_TX_CARRIER_MODE;
request.param_u.set_tx_carrier_mode.enable = enable;
request.param_u.set_tx_carrier_mode.channel_type = channel_type;
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
