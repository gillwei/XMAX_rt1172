/*********************************************************************
* @file  hci_spp_event.c
* @brief Bluetooth Manager HCI SPP Event handler interface definition.
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
#include "bt_spp_core.h"
#include "bt_utils.h"
#include "hci_control_api_ex.h"
#include "hci_spp_event.h"

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
@brief   Handle HCI event - group iAP
@details Handle HCI event - group iAP
@return  None
@retval  None
================================================================================================*/
void HCI_handle_iap_event
    (
    uint8_t group_code,
    uint8_t event_code,
    uint8_t* param,
    uint16_t param_len
    )
{
switch( GROUP_EVENT_CODE( group_code, event_code ) )
    {
    case HCI_CONTROL_IAP2_EVENT_AUTH_CHIP_INFO:
        {
        uint8_t device_version = param[0];
        uint8_t firmware_version = param[1];
        uint8_t protocol_major_version = param[2];
        uint8_t protocol_minor_version = param[3];
        uint32_t device_id = LITTLE_ENDIAN_TO_INT32( &( param[4] ) );

        BT_LOG_DEBUG( "Auth chip info event: device_version=%u, firmware_version=%u, protocol_major_version=%u, protocol_minor_version=%u, device_id=%u",
                      device_version,
                      firmware_version,
                      protocol_major_version,
                      protocol_minor_version,
                      device_id );

        BT_core_spp_handle_iap_event_auth_chip_info( device_version,
                                                     firmware_version,
                                                     protocol_major_version,
                                                     protocol_minor_version,
                                                     device_id );
        } break;
    case HCI_CONTROL_IAP2_EVENT_CONNECTED_GARMIN:
        {
        uint8_t* bd_addr = &( param[0] );
        uint16_t connection_handle = LITTLE_ENDIAN_TO_INT16( &( param[6] ) );
        BT_spp_app_type_e app_type = param[8];

        BT_LOG_DEBUG( "Connected event: bd_addr=%02x:%02x:%02x:%02x:%02x:%02x, connection_handle=0x%x, app=%s",
                      BD_ADDR_PRINT( bd_addr ),
                      connection_handle,
                      BT_util_get_spp_app_type_string( app_type ) );

        BT_core_spp_handle_event_connected( BT_SPP_CONNECTION_IAP, bd_addr, connection_handle, app_type );
        } break;
    case HCI_CONTROL_IAP2_EVENT_CONNECTION_FAILED_GARMIN:
        {
        BT_spp_app_type_e app_type = param[0];

        BT_LOG_DEBUG( "Connection failed event: app=%s", BT_util_get_spp_app_type_string( app_type ) );

        BT_core_spp_handle_event_connection_failed( BT_SPP_CONNECTION_IAP, app_type );
        } break;
    case HCI_CONTROL_IAP2_EVENT_DISCONNECTED_GARMIN:
        {
        uint16_t connection_handle = LITTLE_ENDIAN_TO_INT16( &( param[0] ) );
        BT_spp_app_type_e app_type = param[2];

        BT_LOG_DEBUG( "Disconnected event: connection_handle=0x%x, app=%s",
                      connection_handle,
                      BT_util_get_spp_app_type_string( app_type ) );

        BT_core_spp_handle_event_disconnected( BT_SPP_CONNECTION_IAP, connection_handle, app_type );
        } break;
    case HCI_CONTROL_IAP2_EVENT_RX_DATA_GARMIN:
        {
        uint16_t connection_handle = LITTLE_ENDIAN_TO_INT16( &( param[0] ) );
        BT_spp_app_type_e app_type = param[2];
        uint8_t* data = &( param[3] );
        uint8_t data_len = param_len - BT_CONNECTION_HANDLE_LEN - SPP_APP_TYPE_LEN;

        BT_LOG_DEBUG( "Rx data event: connection_handle=0x%x, app=%s, data_len=%u",
                      connection_handle,
                      BT_util_get_spp_app_type_string( app_type ),
                      data_len );

        BT_core_spp_handle_event_rx_data( BT_SPP_CONNECTION_IAP, connection_handle, app_type, data, data_len );
        } break;
    default:
        {
        BT_LOG_DEBUG( "Unhandled iAP event code: 0x%02x", event_code );
        } break;
    }
}

/*================================================================================================
@brief   Handle HCI event - group SPP
@details Handle HCI event - group SPP
@return  None
@retval  None
================================================================================================*/
void HCI_handle_spp_event
    (
    uint8_t group_code,
    uint8_t event_code,
    uint8_t* param,
    uint16_t param_len
    )
{
switch( GROUP_EVENT_CODE( group_code, event_code ) )
    {
    case HCI_CONTROL_SPP_EVENT_CONNECTED_GARMIN:
        {
        uint8_t* bd_addr = &( param[0] );
        uint16_t connection_handle = LITTLE_ENDIAN_TO_INT16( &( param[6] ) );
        BT_spp_app_type_e app_type = param[8];

        BT_LOG_DEBUG( "Connected event: bd_addr=%02x:%02x:%02x:%02x:%02x:%02x, connection_handle=0x%x, app=%s",
                      BD_ADDR_PRINT( bd_addr ),
                      connection_handle,
                      BT_util_get_spp_app_type_string( app_type ) );

        BT_core_spp_handle_event_connected( BT_SPP_CONNECTION_SPP, bd_addr, connection_handle, app_type );
        } break;
    case HCI_CONTROL_SPP_EVENT_CONNECTION_FAILED_GARMIN:
        {
        BT_spp_app_type_e app_type = param[0];

        BT_LOG_DEBUG( "Connection failed event: app=%s", BT_util_get_spp_app_type_string( app_type ) );

        BT_core_spp_handle_event_connection_failed( BT_SPP_CONNECTION_SPP, app_type );
        } break;
    case HCI_CONTROL_SPP_EVENT_DISCONNECTED_GARMIN:
        {
        uint16_t connection_handle = LITTLE_ENDIAN_TO_INT16( &( param[0] ) );
        BT_spp_app_type_e app_type = param[2];

        BT_LOG_DEBUG( "Disconnected event: connection_handle=0x%x, app=%s",
                      connection_handle,
                      BT_util_get_spp_app_type_string( app_type ) );

        BT_core_spp_handle_event_disconnected( BT_SPP_CONNECTION_SPP, connection_handle, app_type );
        } break;
    case HCI_CONTROL_SPP_EVENT_RX_DATA_GARMIN:
        {
        uint16_t connection_handle = LITTLE_ENDIAN_TO_INT16( &( param[0] ) );
        BT_spp_app_type_e app_type = param[2];
        uint8_t* data = &( param[3] );
        uint8_t data_len = param_len - BT_CONNECTION_HANDLE_LEN - SPP_APP_TYPE_LEN;

        BT_LOG_DEBUG( "Rx data event: connection_handle=0x%x, app=%s, data_len=%u",
                      connection_handle,
                      BT_util_get_spp_app_type_string( app_type ),
                      data_len );

        BT_core_spp_handle_event_rx_data( BT_SPP_CONNECTION_SPP, connection_handle, app_type, data, data_len );
        } break;
    default:
        {
        BT_LOG_DEBUG( "Unhandled SPP event code: 0x%02x", event_code );
        } break;
    }
}

#ifdef __cplusplus
}
#endif
