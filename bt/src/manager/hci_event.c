/*********************************************************************
* @file  hci_event.c
* @brief Bluetooth Manager HCI General Event handler interface definition.
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

#include "bt_core.h"
#include "bt_log.h"
#include "bt_utils.h"
#include "hci_control_api_ex.h"
#include "hci_event.h"

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
@brief   Handle HCI event - group DEVICE
@details Handle HCI event - group DEVICE
@return  None
@retval  None
================================================================================================*/
void HCI_handle_device_event
    (
    uint8_t group_code,
    uint8_t event_code,
    uint8_t* param,
    uint16_t param_len
    )
{
switch( GROUP_EVENT_CODE( group_code, event_code ) )
    {
    case HCI_CONTROL_EVENT_COMMAND_STATUS:
        {
        uint8_t status = param[0];

        BT_LOG_DEBUG( "Command status event: status=%u", status );
        } break;
    case HCI_CONTROL_EVENT_AUTH_LOST_GARMIN:
        {
        uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };
        REVERSE_BD_ADDR( &( param[0] ), bd_addr );

        BT_LOG_DEBUG( "Auth lost event: bd_addr=%02x:%02x:%02x:%02x:%02x:%02x", BD_ADDR_PRINT( bd_addr ) );
        } break;
    case HCI_CONTROL_EVENT_CONNECTION_STATUS_GARMIN:
        {
        uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };
        REVERSE_BD_ADDR( &( param[0] ), bd_addr );
        BT_transport_type_e transport_type = param[6];
        bool connected = param[7];
        uint8_t reason = param[8];

        BT_LOG_DEBUG( "Connection status event: bd_addr=%02x:%02x:%02x:%02x:%02x:%02x,\
                       transport_type=%d, connected=%d, reason=%u",
                       BD_ADDR_PRINT( bd_addr ),
                       transport_type,
                       connected,
                       reason );

        BT_core_handle_device_event_connection_status( bd_addr, transport_type, connected, reason );
        } break;
    case HCI_CONTROL_EVENT_DEVICE_STARTED_GARMIN:
        {
        uint8_t major_version = param[0];
        uint8_t minor_version = param[1];

        BT_LOG_DEBUG( "Device started event: major_version=%u, minor_version=%u",
                      major_version,
                      minor_version );

        BT_core_handle_device_event_device_started( major_version, minor_version );
        } break;
    case HCI_CONTROL_EVENT_PAIRED_DEVICE_DELETED_GARMIN:
        {
        uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };
        REVERSE_BD_ADDR( &( param[0] ), bd_addr );

        BT_LOG_DEBUG( "Paired device deleted event: bd_addr=%02x:%02x:%02x:%02x:%02x:%02x",
                      BD_ADDR_PRINT( bd_addr ) );

        BT_core_handle_device_event_paired_device_deleted( bd_addr );
        } break;
    case HCI_CONTROL_EVENT_PAIRED_DEVICE_LIST_GARMIN:
        {
        uint8_t num_devices = param[0];
        uint8_t device_num = param[1];
        uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };
        REVERSE_BD_ADDR( &( param[2] ), bd_addr );
        uint8_t* device_name = &( param[8] );
        BT_device_type_e device_type = param[40];
        bool auth_lost = param[41];
        bool iap_support = param[42];

        BT_LOG_DEBUG( "Paired device list event: number=%u of %u, bd_addr=%02x:%02x:%02x:%02x:%02x:%02x, \
                      device_name=%s, device_type=%s, auth_lost=%d, iap_support=%d",
                      device_num,
                      num_devices,
                      BD_ADDR_PRINT( bd_addr ),
                      device_name,
                      BT_util_get_device_type_string( device_type ),
                      auth_lost,
                      iap_support );

        BT_core_handle_device_event_paired_device_list( num_devices,
                                                        device_num,
                                                        bd_addr,
                                                        device_name,
                                                        device_type,
                                                        auth_lost,
                                                        iap_support );
        } break;
    case HCI_CONTROL_EVENT_PAIRING_COMPLETE_GARMIN:
        {
        uint8_t result = param[0];
        BT_transport_type_e transport_type = param[1];
        uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };
        REVERSE_BD_ADDR( &( param[2] ), bd_addr );

        BT_LOG_DEBUG( "Pairing complete event: result=%u, bd_addr=%02x:%02x:%02x:%02x:%02x:%02x, transport_type=%s",
                      result,
                      BD_ADDR_PRINT( bd_addr ),
                      BT_util_get_transport_type_string( transport_type ) );

        BT_core_handle_device_event_pairing_complete( result, bd_addr, transport_type );
        } break;
    case HCI_CONTROL_EVENT_USER_CONFIRMATION_GARMIN:
        {
        uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };
        REVERSE_BD_ADDR( &( param[0] ), bd_addr );
        uint32_t passkey = LITTLE_ENDIAN_TO_INT32( &( param[6] ) );
        uint8_t device_name[BT_DEVICE_NAME_LEN] = { 0 };

        memcpy( device_name, &( param[10] ), BT_DEVICE_NAME_LEN );

        BT_LOG_DEBUG( "User confirmation request event: bd_addr=%02x:%02x:%02x:%02x:%02x:%02x, device_name=%s, passkey=%u",
                       BD_ADDR_PRINT( bd_addr ),
                       device_name,
                       passkey );

        BT_core_handle_device_event_user_confirmation( bd_addr, device_name, passkey );
        } break;
    default:
        {
        BT_LOG_DEBUG( "Unhandled Device event code: 0x%02x", event_code );
        } break;
    }
}

/*================================================================================================
@brief   Handle HCI event - group STANDARD
@details Handle HCI event - group STANDARD. The events to be handled here are standard HCI events.
@return  None
@retval  None
================================================================================================*/
void HCI_handle_standard_event
    (
    uint8_t group_code,
    uint8_t event_code,
    uint8_t* param,
    uint16_t param_len
    )
{
switch( event_code )
    {
    case HCI_STANDARD_EVENT_COMMAND_COMPLETE:
        {
        uint8_t num_hci_command_packets = param[0];
        uint16_t op_code = LITTLE_ENDIAN_TO_INT16( &( param[1] ) );

        BT_LOG_DEBUG( "Command complete event: num_hci_command_packets=%u, op_code=0x%04x",
                      num_hci_command_packets,
                      op_code );

        switch( op_code )
            {
            case HCI_STANDARD_COMMAND_RESET:
                {
                uint8_t error_code = param[3];

                BT_LOG_DEBUG( "Reset complete event: error_code=0x%02x", error_code );

                BT_core_handle_standard_event_reset_complete( error_code );
                } break;
            case HCI_STANDARD_COMMAND_DUT_MODE:
                {
                uint8_t error_code = param[3];

                BT_LOG_DEBUG( "DUT mode complete event: error_code=0x%02x", error_code );
                } break;
            case HCI_STANDARD_COMMAND_TX_CARRIER:
                {
                uint8_t error_code = param[3];

                BT_LOG_DEBUG( "Tx carrier complete event: error_code=0x%02x", error_code );
                } break;
            case HCI_STANDARD_COMMAND_UPDATE_BAUDRATE:
                {
                uint8_t error_code = param[3];

                BT_LOG_DEBUG( "Update baudrate complete event: error_code=0x%02x", error_code );

                BT_core_handle_standard_event_update_baudrate_complete( error_code );
                } break;
            case HCI_STANDARD_COMMAND_WRITE_RAM:
                {
                uint8_t error_code = param[3];

                BT_LOG_DEBUG( "Write RAM complete event: error_code=0x%02x", error_code );

                BT_core_handle_standard_event_write_ram_complete( error_code );
                } break;
            case HCI_STANDARD_COMMAND_READ_RAM:
                {
                uint8_t error_code = param[3];
                uint8_t* data = &( param[4] );
                uint8_t data_len = param_len - 4;

                BT_LOG_DEBUG( "Read RAM complete event: error_code=0x%02x, data_len=%u", error_code, data_len );

                BT_core_handle_standard_event_read_ram_complete( error_code, data, data_len );
                } break;
            case HCI_STANDARD_COMMAND_LAUNCH_RAM:
                {
                uint8_t error_code = param[3];

                BT_LOG_DEBUG( "Launch RAM complete event: error_code=0x%02x", error_code );

                BT_core_handle_standard_event_launch_ram_complete( error_code );
                } break;
            case HCI_STANDARD_COMMAND_CHIP_ERASE:
                {
                uint8_t error_code = param[3];

                BT_LOG_DEBUG( "Chip erase complete event: error_code=0x%02x", error_code );

                BT_core_handle_standard_event_chip_erase_complete( error_code );
                } break;
            default:
                {
                BT_LOG_DEBUG( "Unhandled op code: 0x%04x", op_code );
                } break;
            }
        } break;
    default:
        {
        BT_LOG_DEBUG( "Unhandled Standard event code: 0x%02x", event_code );
        } break;
    }
}

#ifdef __cplusplus
}
#endif
