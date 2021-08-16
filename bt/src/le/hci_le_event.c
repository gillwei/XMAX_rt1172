/*********************************************************************
* @file  hci_le_event.c
* @brief Bluetooth Manager HCI LE Event handler interface definition.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "bt_log.h"
#include "bt_tsk.h"
#include "bt_utils.h"
#include "ble_client_core.h"
#include "ble_server_core.h"
#include "hci_control_api_ex.h"
#include "hci_le_event.h"

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
@brief   Handle HCI event - group GATT
@details Handle HCI event - group GATT
@return  None
@retval  None
================================================================================================*/
void HCI_handle_gatt_event
    (
    uint8_t group_code,
    uint8_t event_code,
    uint8_t* param,
    uint16_t param_len
    )
{
switch( GROUP_EVENT_CODE( group_code, event_code ) )
    {
    case HCI_CONTROL_GATT_EVENT_COMMAND_STATUS:
        {
        uint8_t status = param[0];

        BT_LOG_DEBUG( "Command status event: status=%u", status );
        } break;
    case HCI_CONTROL_GATT_EVENT_SERVICE_DISCOVERED:
        {
        uint16_t connection_handle = LITTLE_ENDIAN_TO_INT16( &( param[0] ) );
        uint8_t* uuid = &( param[2] );
        uint16_t start_handle = LITTLE_ENDIAN_TO_INT16( &( param[18] ) );
        uint16_t end_handle = LITTLE_ENDIAN_TO_INT16( &( param[20] ) );

        BT_LOG_DEBUG( "Service discovered event: connection_handle=0x%x, start_handle=0x%x, end_handle=0x%x",
                      connection_handle,
                      start_handle,
                      end_handle );
        BT_LOG_DEBUG( "(cont.) uuid=0x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
                      UUID_PRINT( uuid ) );

        BLE_core_client_handle_gatt_event_service_discovered( connection_handle,
                                                              uuid,
                                                              start_handle,
                                                              end_handle );
        } break;
    case HCI_CONTROL_GATT_EVENT_CHARACTERISTIC_DISCOVERED:
        {
        uint16_t connection_handle = LITTLE_ENDIAN_TO_INT16( &( param[0] ) );
        uint16_t characteristic_handle = LITTLE_ENDIAN_TO_INT16( &( param[2] ) );
        uint8_t* uuid = &( param[4] );
        uint8_t characteristic_properties = param[20];
        uint16_t value_handle = LITTLE_ENDIAN_TO_INT16( &( param[21] ) );

        BT_LOG_DEBUG( "Characteristic discovered event: connection_handle=0x%x, characteristic_handle=0x%x, \
                      characteristic_properties=%u, value_handle=0x%x",
                      connection_handle,
                      characteristic_handle,
                      characteristic_properties,
                      value_handle );
        BT_LOG_DEBUG( "(cont.) uuid=0x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
                      UUID_PRINT( uuid ) );

        BLE_core_client_handle_gatt_event_characteristic_discovered( connection_handle, uuid, value_handle );
        } break;
    case HCI_CONTROL_GATT_EVENT_DESCRIPTOR_DISCOVERED:
        {
        uint16_t connection_handle = LITTLE_ENDIAN_TO_INT16( &( param[0] ) );
        uint8_t* uuid = &( param[2] );
        uint16_t descriptor_handle = LITTLE_ENDIAN_TO_INT16( &( param[18] ) );

        BT_LOG_DEBUG( "Descriptor discovered event: connection_handle=0x%x, descriptor_handle=0x%x",
                      connection_handle,
                      descriptor_handle );
        BT_LOG_DEBUG( "(cont.) uuid=0x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
                      UUID_PRINT( uuid ) );

        BLE_core_client_handle_gatt_event_descriptor_discovered( connection_handle, descriptor_handle );
        } break;
    case HCI_CONTROL_GATT_EVENT_DISCOVERY_COMPLETE:
        {
        uint16_t connection_handle = LITTLE_ENDIAN_TO_INT16( &( param[0] ) );

        BT_LOG_DEBUG( "Discovery complete event: connection_handle=0x%x", connection_handle );

        BLE_core_client_handle_gatt_event_discovery_complete( connection_handle );
        } break;
    case HCI_CONTROL_GATT_EVENT_READ_REQUEST:
        {
        uint16_t connection_handle = LITTLE_ENDIAN_TO_INT16( &( param[0] ) );
        uint16_t handle = LITTLE_ENDIAN_TO_INT16( &( param[2] ) );

        BT_LOG_DEBUG( "Read request event: connection_handle=0x%x, handle=0x%x", connection_handle, handle );

        BLE_core_server_handle_gatt_event_read_request( connection_handle, handle );
        } break;
    case HCI_CONTROL_GATT_EVENT_WRITE_REQUEST:
        {
        uint16_t connection_handle = LITTLE_ENDIAN_TO_INT16( &( param[0] ) );
        uint16_t handle = LITTLE_ENDIAN_TO_INT16( &( param[2] ) );
        uint8_t* data = &( param[GATT_WRITE_REQUEST_HEADER_LEN] );
        uint8_t data_len = param_len - GATT_WRITE_REQUEST_HEADER_LEN;

        BT_LOG_DEBUG( "Write request event: connection_handle=0x%x, handle=0x%x, data_len=%u",
                      connection_handle,
                      handle,
                      data_len );

        BLE_core_server_handle_gatt_event_write_request( connection_handle, handle, data, data_len );
        } break;
    case HCI_CONTROL_GATT_EVENT_WRITE_RESPONSE:
        {
        uint16_t connection_handle = LITTLE_ENDIAN_TO_INT16( &( param[0] ) );
        uint8_t result = param[2];

        BT_LOG_DEBUG( "Write response event: connection_handle=0x%x, result=%u", connection_handle, result );

        BT_tsk_sync_gatt_send_signal();
        } break;
    case HCI_CONTROL_GATT_EVENT_NOTIFICATION:
        {
        uint16_t connection_handle = LITTLE_ENDIAN_TO_INT16( &( param[0] ) );
        uint16_t handle = LITTLE_ENDIAN_TO_INT16( &( param[2] ) );
        uint8_t* data = &( param[4] );
        uint8_t data_len = param_len - 4;

        BT_LOG_DEBUG( "Notification event: connection_handle=0x%x, handle=0x%x, data_len=%u",
                      connection_handle,
                      handle,
                      data_len );

        BLE_core_client_handle_gatt_event_notification( connection_handle, handle, data, data_len );
        } break;
    default:
        {
        BT_LOG_DEBUG( "Unhandled GATT event code: 0x%02x", event_code );
        } break;
    }
}

/*================================================================================================
@brief   Handle HCI event - group LE
@details Handle HCI event - group LE
@return  None
@retval  None
================================================================================================*/
void HCI_handle_le_event
    (
    uint8_t group_code,
    uint8_t event_code,
    uint8_t* param,
    uint16_t param_len
    )
{
switch( GROUP_EVENT_CODE( group_code, event_code ) )
    {
    case HCI_CONTROL_LE_EVENT_ADVERTISEMENT_STATE:
        {
        uint8_t state = param[0];

        BT_LOG_DEBUG( "Advertisement state event: state=%u", state );
        } break;
    case HCI_CONTROL_LE_EVENT_CONNECTED:
        {
        BLE_bd_addr_type_e bd_addr_type = param[0];
        uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };
        REVERSE_BD_ADDR( &( param[1] ), bd_addr );
        uint16_t connection_handle = LITTLE_ENDIAN_TO_INT16( &( param[7] ) );
        BT_hci_role_e role = param[9];

        BT_LOG_DEBUG( "Connected event: bd_addr[%s]=%02x%02x%02x%02x%02x%02x, connection_handle=0x%x, role=%s",
                      BLE_util_get_bd_addr_type_string( bd_addr_type ),
                      BD_ADDR_PRINT( bd_addr ),
                      connection_handle,
                      BT_util_get_hci_role_string( role ) );

        BLE_core_server_handle_le_event_connected( connection_handle );
        BLE_core_client_handle_le_event_connected( connection_handle );
        } break;
    case HCI_CONTROL_LE_EVENT_DISCONNECTED:
        {
        uint16_t connection_handle = LITTLE_ENDIAN_TO_INT16( &( param[0] ) );
        uint8_t reason = param[2];

        BT_LOG_DEBUG( "Disconnected event: connection_handle=0x%x, reason=%u", connection_handle, reason );

        BLE_core_server_handle_le_event_disconnected( connection_handle );
        BLE_core_client_handle_le_event_disconnected( connection_handle );
        } break;
    case HCI_CONTROL_LE_EVENT_IDENTITY_ADDRESS:
        {
        uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };
        REVERSE_BD_ADDR( &( param[0] ), bd_addr );

        BT_LOG_DEBUG( "Identity address event: bd_addr=%02x%02x%02x%02x%02x%02x", BD_ADDR_PRINT( bd_addr ) );
        } break;
    default:
        {
        BT_LOG_DEBUG( "Unhandled LE event code: 0x%02x", event_code );
        } break;
    }
}

#ifdef __cplusplus
}
#endif
