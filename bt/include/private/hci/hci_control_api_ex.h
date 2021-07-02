/*********************************************************************
* @file  hci_control_api_ex.h
* @brief Extended HCI control api defined by Garmin.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _HCI_CONTROL_API_EX_H_
#define _HCI_CONTROL_API_EX_H_

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
/*====================================================================
@note: Cypress defines the values used for Wiced HCI protocol in file
       hci_control_api.h. Based on that Garmin adds required values
       with following types in this extended file to use:
         - NEW: A new value defined by Garmin. For easier to identify
                add the suffix - GARMIN.
         - REDECLARED: A value is already defined by Cypress but is
                       not declared in hci_control_api.h
       Make sure that the values added here are not conflicted with
       hci_control_api.h.
====================================================================*/
#include "hci_control_api.h"

/*--------------------------------------------------------------------
                        HCI ERROR CODES
--------------------------------------------------------------------*/
/*====================================================================
@type: REDECLARED
====================================================================*/
#define HCI_ERR_PEER_USER             ( 0x13 )
#define HCI_ERR_CONN_CAUSE_LOCAL_HOST ( 0x16 )

/*--------------------------------------------------------------------
                        PACKET TYPES
--------------------------------------------------------------------*/
/*====================================================================
@type: REDECLARED
====================================================================*/
#define HCI_STANDARD_COMMAND_PKT ( 0x01 )
#define HCI_STANDARD_EVENT_PKT   ( 0x04 )

/*--------------------------------------------------------------------
                        GROUP CODES
--------------------------------------------------------------------*/
/*====================================================================
@type: NEW
====================================================================*/
#define HCI_CONTROL_GROUP_STANDARD_GARMIN ( 0xFE )

/*--------------------------------------------------------------------
                        GENERAL COMMANDS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        STANDARD HCI COMMANDS
--------------------------------------------------------------------*/
/*====================================================================
@type: REDECLARED
====================================================================*/
#define HCI_STANDARD_COMMAND_DUT_MODE   ( 0x1803 )
#define HCI_STANDARD_COMMAND_TX_CARRIER ( 0xFC14 )
#define HCI_STANDARD_COMMAND_WRITE_RAM  ( 0xFC4C )
#define HCI_STANDARD_COMMAND_READ_RAM   ( 0xFC4D )
#define HCI_STANDARD_COMMAND_LAUNCH_RAM ( 0xFC4E )
#define HCI_STANDARD_COMMAND_CHIP_ERASE ( 0xFFCE )

/*--------------------------------------------------------------------
                        SPP COMMANDS
--------------------------------------------------------------------*/
/*====================================================================
@type: NEW
@data: Byte[0]: (6-bytes) Bluetooth device address
       Byte[6]: (1-byte) SPP application type specified in BT_spp_app_type_e
====================================================================*/
#define HCI_CONTROL_SPP_COMMAND_CONNECT_GARMIN ( ( HCI_CONTROL_GROUP_SPP << 8 ) | 0xFF )

/*====================================================================
@type: NEW
@data: Byte[0]: (2-bytes) Connection handle
       Byte[2]: (1-byte) SPP application type specified in BT_spp_app_type_e
====================================================================*/
#define HCI_CONTROL_SPP_COMMAND_DISCONNECT_GARMIN ( ( HCI_CONTROL_GROUP_SPP << 8 ) | 0xFE )

/*====================================================================
@type: NEW
@data: Byte[0]: (2-bytes) Connection handle
       Byte[2]: (1-byte) SPP application type specified in BT_spp_app_type_e
       Byte[3]: (n-bytes) Data to remote device, where n <= SPP_DATA_MAX_SIZE
====================================================================*/
#define HCI_CONTROL_SPP_COMMAND_DATA_GARMIN ( ( HCI_CONTROL_GROUP_SPP << 8 ) | 0xFD )

/*--------------------------------------------------------------------
                        IAP2 COMMANDS
--------------------------------------------------------------------*/
/*====================================================================
@type: NEW
@data: Byte[0]: (6-bytes) Bluetooth device address
====================================================================*/
#define HCI_CONTROL_IAP2_COMMAND_CONNECT_GARMIN ( ( HCI_CONTROL_GROUP_IAP2 << 8 ) | 0xFF )

/*====================================================================
@type: NEW
@data: Byte[0]: (2-bytes) Connection handle
====================================================================*/
#define HCI_CONTROL_IAP2_COMMAND_DISCONNECT_GARMIN ( ( HCI_CONTROL_GROUP_IAP2 << 8 ) | 0xFE )

/*====================================================================
@type: NEW
@data: Byte[0]: (2-bytes) Connection handle
       Byte[2]: (1-byte) SPP application type specified in BT_spp_app_type_e
       Byte[3]: (n-bytes) Data to remote device, where n <= SPP_DATA_MAX_SIZE
====================================================================*/
#define HCI_CONTROL_IAP2_COMMAND_DATA_GARMIN ( ( HCI_CONTROL_GROUP_IAP2 << 8 ) | 0xFD )

/*--------------------------------------------------------------------
                        GENERAL EVENTS
--------------------------------------------------------------------*/
/*====================================================================
@type: NEW
@data: Byte[0]: (6-bytes) Bluetooth device address
====================================================================*/
#define HCI_CONTROL_EVENT_AUTH_LOST_GARMIN ( ( HCI_CONTROL_GROUP_DEVICE << 8 ) | 0xFF )

/*====================================================================
@type: NEW
@data: Byte[0]: (6-bytes) Bluetooth device address
       Byte[6]: (1-byte) Transport type
       Byte[7]: (1-byte) Connected or not
       Byte[8]: (1-byte) Reason
====================================================================*/
#define HCI_CONTROL_EVENT_CONNECTION_STATUS_GARMIN ( ( HCI_CONTROL_GROUP_DEVICE << 8 ) | 0xFE )

/*====================================================================
@type: NEW
@data: Byte[0]: (1-byte) Software major version
       Byte[1]: (1-byte) Software minor version
====================================================================*/
#define HCI_CONTROL_EVENT_DEVICE_STARTED_GARMIN ( ( HCI_CONTROL_GROUP_DEVICE << 8 ) | 0xFD )

/*====================================================================
@type: NEW
@data: Byte[0]: (6-bytes) Bluetooth device address
====================================================================*/
#define HCI_CONTROL_EVENT_PAIRED_DEVICE_DELETED_GARMIN ( ( HCI_CONTROL_GROUP_DEVICE << 8 ) | 0xFC )

/*====================================================================
@type: NEW
@data: Byte[0]: (1-byte) Number of paired devices in the list
       Byte[1]: (n-bytes) Data of paired devices stored as format as BT_device_info_t, where n <= ( HCI_PAYLOAD_MAX_SIZE - 1 )
====================================================================*/
#define HCI_CONTROL_EVENT_PAIRED_DEVICE_LIST_GARMIN ( ( HCI_CONTROL_GROUP_DEVICE << 8 ) | 0xFB )

/*--------------------------------------------------------------------
                        STANDARD HCI EVENTS
--------------------------------------------------------------------*/
/*====================================================================
@type: REDECLARED
====================================================================*/
#define HCI_STANDARD_EVENT_COMMAND_COMPLETE ( 0x0E )

/*--------------------------------------------------------------------
                        SPP EVENTS
--------------------------------------------------------------------*/
/*====================================================================
@type: NEW
@data: Byte[0]: (6-bytes) Bluetooth device address
       Byte[6]: (2-bytes) Connection handle
       Byte[8]: (1-byte) SPP application type specified in BT_spp_app_type_e
====================================================================*/
#define HCI_CONTROL_SPP_EVENT_CONNECTED_GARMIN ( ( HCI_CONTROL_GROUP_SPP << 8 ) | 0xFF )

/*====================================================================
@type: NEW
@data: Byte[0]: (1-byte) SPP application type specified in BT_spp_app_type_e
====================================================================*/
#define HCI_CONTROL_SPP_EVENT_CONNECTION_FAILED_GARMIN ( ( HCI_CONTROL_GROUP_SPP << 8 ) | 0xFE )

/*====================================================================
@type: NEW
@data: Byte[0]: (2-bytes) Connection handle
       Byte[2]: (1-byte) SPP application type specified in BT_spp_app_type_e
====================================================================*/
#define HCI_CONTROL_SPP_EVENT_DISCONNECTED_GARMIN ( ( HCI_CONTROL_GROUP_SPP << 8 ) | 0xFD )

/*====================================================================
@type: NEW
@data: Byte[0]: (2-bytes) Connection handle
       Byte[2]: (1-byte) SPP application type specified in BT_spp_app_type_e
       Byte[3]: (n-bytes) Data from remote device, where n <= SPP_DATA_MAX_SIZE
====================================================================*/
#define HCI_CONTROL_SPP_EVENT_RX_DATA_GARMIN ( ( HCI_CONTROL_GROUP_SPP << 8 ) | 0xFC )

/*--------------------------------------------------------------------
                        IAP2 EVENTS
--------------------------------------------------------------------*/
/*====================================================================
@type: NEW
@data: Byte[0]: (6-bytes) Bluetooth device address
       Byte[6]: (2-bytes) Connection handle
       Byte[8]: (1-byte) SPP application type specified in BT_spp_app_type_e
====================================================================*/
#define HCI_CONTROL_IAP2_EVENT_CONNECTED_GARMIN ( ( HCI_CONTROL_GROUP_IAP2 << 8 ) | 0xFF )

/*====================================================================
@type: NEW
@data: Byte[0]: (1-byte) SPP application type specified in BT_spp_app_type_e
====================================================================*/
#define HCI_CONTROL_IAP2_EVENT_CONNECTION_FAILED_GARMIN ( ( HCI_CONTROL_GROUP_IAP2 << 8 ) | 0xFE )

/*====================================================================
@type: NEW
@data: Byte[0]: (2-bytes) Connection handle
       Byte[2]: (1-byte) SPP application type specified in BT_spp_app_type_e
====================================================================*/
#define HCI_CONTROL_IAP2_EVENT_DISCONNECTED_GARMIN ( ( HCI_CONTROL_GROUP_IAP2 << 8 ) | 0xFD )

/*====================================================================
@type: NEW
@data: Byte[0]: (2-bytes) Connection handle
       Byte[2]: (1-byte) SPP application type specified in BT_spp_app_type_e
       Byte[3]: (n-bytes) Data from remote device, where n <= SPP_DATA_MAX_SIZE
====================================================================*/
#define HCI_CONTROL_IAP2_EVENT_RX_DATA_GARMIN ( ( HCI_CONTROL_GROUP_IAP2 << 8 ) | 0xFC )

#ifdef __cplusplus
}
#endif

#endif // _HCI_CONTROL_API_EX_H_
