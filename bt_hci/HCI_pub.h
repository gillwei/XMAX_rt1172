/*******************************************************************************
*@ File HCI_pub.h
*@ Brief HCI driver public header file
*
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
********************************************************************************/
#ifndef HCI_PUB_H
#define HCI_PUB_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "fsl_common.h"
#include "PERIPHERAL_pub.h"

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define OPCODE_RESET             0x0C03
#define OPCODE_COMMIT_ADDR       0xFC10
#define COMMON_CMD_WAIT_MS       30
#define BT_MIN_WAIT_DELAY        50
#define BT_RESET_RECONFIG_DELAY  100
#define BT_RESET_GPIO_DELAY      50
#define BT_AFTER_RESET_DELAY     1000

#define HCI_MAX_DATA_SIZE        240

#define UUID_128BIT_LEN                     ( 16 )
#define BLE_GATT_CLIENT_CONFIG_NONOE        ( 0x0000 )
#define BLE_GATT_CLIENT_CONFIG_NOTIFICATION ( 0x0001 )
#define BLE_GATT_CLIENT_CONFIG_INDICATION   ( 0x0002 )
#define BLE_GATT_WRITE_REQUEST_DATA_MAX_LEN ( 28 )

#define CCUID_LENGTH                        ( 14 )
#define TEST_CCUID    (const char [])       { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e'  }

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef enum tagBT_PARSER_TYPE                  //!< HCI receive state machine states
    {
    PARSER_WICED_HCI,
    PARSER_STANDARD_HCI
    } bt_parser_t;

typedef enum
    {
    BT_CONN_TYPE_BT_OTHERS,
    BT_CONN_TYPE_BT_IAP2,
    BT_CONN_TYPE_BT_SPP,
    BT_CONN_TYPE_BT_IAP2_YAPP
    } bt_connection_path_type;

typedef enum
    {
    BLE_CLIENT_AMS,
    BLE_CLIENT_ANCS,
    BLE_CLIENT_TOTAL
    } ble_client_type;

typedef enum
    {
    BLE_SERVER_MOTOCONSDK,
    BLE_SERVER_TOTAL
    } ble_server_type;

typedef enum BLE_ADVERTISING_TYPE
    {
    BLE_ADV_OFF,
    BLE_ADV_NON_CONNECTABLE,
    BLE_ADV_CONNECTABLE
    } ble_advertising_type_t;

typedef struct
    {
    void ( *ble_connected_callback ) ( void );
    void ( *ble_disconnected_callback ) ( void );
    void ( *service_discovered_callback ) ( const uint16_t start_handle, const uint16_t end_handle );
    void ( *characteristic_discovered_callback ) ( const uint8_t* uuid, const uint16_t value_handle );
    void ( *descriptor_discovered_callback ) ( const uint16_t descriptor_handle );
    void ( *discovery_complete_callback ) ( void );
    void ( *notification_received_callback ) ( const uint16_t handle, const uint8_t* data, const uint16_t length );
    } ble_client_callback;

typedef struct
    {
    void ( *ble_connected_callback ) ( void );
    void ( *ble_disconnected_callback ) ( void );
    void ( *read_request_received_callback ) ( const uint16_t handle );
    void ( *write_request_received_callback ) ( const uint16_t handle, const uint8_t* data, const uint16_t length );
    } ble_server_callback;

typedef enum HCI_RESPONSE_TYPE
    {
    RESPONSE_NO_EVENT,
    RESPONSE_MFI_CHIP_VER,
    RESPONSE_RECONFIG_WAIT_BT_MODULE,
    RESPONSE_RESET_DOWNLOAD_FINISH,
    RESPONSE_RESET_RECONFIG_UART,
    RESPONSE_TX_CARRIER_CMD,
    RESPONSE_RESET_TX_CARRIER_CMD,
    RESPONSE_CHECK_COMMAND_STATUS
    } hci_resp_type_t;

typedef void ( *spp_iap2_data_callback ) ( const uint8_t* data, const uint16_t length );

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
/* combine two bytes of little endian order to one word */
#define WORD_LITTLE( byte0, byte1 )                     ( ( byte1 << 8 ) | byte0 )

/* combine four bytes of little endian order to double word */
#define DWORD_LITTLE( byte0, byte1, byte2, byte3 )      ( ( byte3 << 24 ) | ( byte2 << 16 ) | ( byte1 << 8 ) | byte0 )

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
bool HCI_spp_iap2_add_data_callback
    (
    spp_iap2_data_callback data_callback
    );

void HCI_init
    (
    void
    );

void HCI_normal_reset_BT
    (
    hci_resp_type_t resp_event
    );

void HCI_notify_received
    (
    uint8_t* data,
    uint32_t size
    );

#if HCI_TX_QUEUE_ENABLE
void HCI_notify_transmit
    (
    uint16_t tx_command_type,
    uint8_t* data,
    uint32_t size
    );
#endif

BaseType_t HCI_wiced_send_command
    (
    const uint16_t command,
    const uint8_t* payload,
    const uint16_t len
    );

int HCI_le_send_gatt_server_data
    (
    const uint16_t opcode,
    const uint16_t handle,
    const uint8_t* data,
    const uint16_t length
    );

int HCI_le_register_client_callback
    (
    const ble_client_type      client_type,
    const ble_client_callback* callback
    );

int HCI_le_register_server_callback
    (
    ble_server_type service_type,
    ble_server_callback*   callback
    );

int HCI_le_enqueue_gatt_write_request
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint16_t length
    );

bool HCI_le_is_connected
    (
    void
    );

void HCI_BT_off
    (
    void
    );

void HCI_BT_on
    (
    void
    );

void HCI_set_test_mode
    (
    void
    );

bool HCI_get_test_mode_state
    (
    void
    );

void HCI_tx_carrier_cmd
    (
    uint8_t data
    );

void HCI_wait_for_resp_start
    (
    hci_resp_type_t
    );

void HCI_le_disconnect_ble
    (
    void
    );

BaseType_t HCI_LE_send_advertising_cmd
    (
    ble_advertising_type_t ble_advertising_type
    );

#ifdef __cplusplus
}
#endif


#endif /*HCI_PUB_H */
