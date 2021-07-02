/*********************************************************************
* @file  bt_types.h
* @brief Defines the Bluetooth Manager specific types used for public
*        interface.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _BT_TYPES_H_
#define _BT_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define BT_DEVICE_ADDRESS_LEN    ( 6 )
#define BT_DEVICE_NAME_LEN       ( 20 )
#define BT_SW_VERSION_LEN        ( 2 )
#define BT_CONNECTION_HANDLE_LEN ( 2 )

// Note: MAX_TRANSPORT_DATA_SIZE is the maximum size of HCI payload defined by Cypress in wiced_app.h.
//       Its value is 240 bytes, we define the same value here for MCU to use.
#define HCI_HEADER_LEN       ( 5 )
#define HCI_PAYLOAD_MAX_SIZE ( 240 )
#define HCI_COMMAND_MAX_SIZE ( HCI_HEADER_LEN + HCI_PAYLOAD_MAX_SIZE )
#define HCI_EVENT_MAX_SIZE   ( HCI_HEADER_LEN + HCI_PAYLOAD_MAX_SIZE )

#define SPP_APP_TYPE_LEN                     ( 1 )
#define SPP_DATA_MAX_SIZE                    ( HCI_PAYLOAD_MAX_SIZE - BT_CONNECTION_HANDLE_LEN - SPP_APP_TYPE_LEN )
#define SPP_APP_CONNECTION_STATUS_CB_MAX_NUM ( 3 ) // For each SPP app
#define SPP_APP_DATA_RECEIVED_CB_MAX_NUM     ( 3 ) // For each SPP app

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef void ( *BT_spp_connection_status_callback )( const bool connected, const uint8_t* bd_addr );

typedef void ( *BT_spp_data_received_callback )( const uint8_t* data, const uint8_t data_len );

// Note: The detailed connection status of Bluetooth profile is for Bluetooth Manager internal use only
typedef enum BT_connection_status
    {
    BT_CONNECTION_DISCONNECTED = 0,
    BT_CONNECTION_CONNECTING,
    BT_CONNECTION_CONNECTED,
    BT_CONNECTION_DISCONNECTING,

    BT_CONNECTION_STATUS_CNT,
    BT_CONNECTION_STATUS_INVALID = BT_CONNECTION_STATUS_CNT
    } BT_connection_status_e;

// Note: This is a copy of wiced_bt_device_type_t defined by Cypress in wiced_bt_types.h
typedef enum BT_device_type
    {
    BT_DEVICE_BREDR = 1,
    BT_DEVICE_LE,
    BT_DEVICE_BREDR_LE,

    BT_DEVICE_TYPE_CNT,
    BT_DEVICE_TYPE_INVALID = BT_DEVICE_TYPE_CNT
    } BT_device_type_e;

typedef enum BT_log_severity
    {
    BT_LOG_FATAL = 0,
    BT_LOG_ERROR,
    BT_LOG_WARNING,
    BT_LOG_INFO,
    BT_LOG_DEBUG,
    BT_LOG_VERBOSE,

    BT_LOG_SEVERITY_CNT,
    BT_LOG_SEVERITY_INVALID = BT_LOG_SEVERITY_CNT
    } BT_log_severity_e;

typedef enum BT_tx_channel_type
    {
    BT_TX_CH_LOW = 0,
    BT_TX_CH_MID,
    BT_TX_CH_HIGH,

    BT_TX_CH_TYPE_CNT,
    BT_TX_CH_TYPE_INVALID = BT_TX_CH_TYPE_CNT
    } BT_tx_channel_type_e;

typedef enum BT_spp_app_type
    {
    BT_SPP_APP_NAVILITE = 0,
    BT_SPP_APP_MOTOCON,

    BT_SPP_APP_TYPE_CNT,
    BT_SPP_APP_TYPE_INVALID = BT_SPP_APP_TYPE_CNT
    } BT_spp_app_type_e;

typedef enum BT_status
    {
    BT_STATUS_OK = 0,
    BT_STATUS_BUSY,              // The same request is still under processing
    BT_STATUS_INVALID_PARAMETER, // Invalid parameter input
    BT_STATUS_NO_CONNECTION,     // No device is connected yet
    BT_STATUS_NOT_READY,         // Bluetooth Manager is not initialized yet
    BT_STATUS_NOT_ALLOWED,       // Operation is not allowed
    BT_STATUS_AUTH_LOST,         // The remote device has lost its authentication data
    BT_STATUS_QUEUE_FULL,        // Bluetooth Manager's request queue is full

    BT_STATUS_CNT,
    BT_STATUS_INVALID = BT_STATUS_CNT
    } BT_status_e;

// Note: This is a copy of wiced_bt_transport_t defined by Cypress in wiced_bt_types.h
typedef enum BT_transport_type
    {
    BT_TRANSPORT_BREDR = 1,
    BT_TRANSPORT_LE    = 2,

    BT_TRANSPORT_TYPE_CNT,
    BT_TRANSPORT_TYPE_INVALID = BT_TRANSPORT_TYPE_CNT
    } BT_transport_type_e;

// Note:
//   1. The struct used to store paired device info MUST be synchronous between MCU and Cypress
//      module. Do NOT modify the content without informing another side.
//   2. Since Cypress module will send the paired device list in ONE hci event. The struct size
//      is limited to HCI_PAYLOAD_MAX_SIZE. Do NOT increase the struct size.
typedef struct BT_device_info
    {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    uint8_t device_name[BT_DEVICE_NAME_LEN];
    BT_device_type_e device_type;
    bool auth_lost;
    bool iap_support;
    } BT_device_info_t;

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
                        MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // _BT_TYPES_H_
