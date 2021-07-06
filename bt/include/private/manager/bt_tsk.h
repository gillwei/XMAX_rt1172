/*********************************************************************
* @file  bt_tsk.h
* @brief Bluetooth Manager Main Task interface declaration.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _BT_TSK_H_
#define _BT_TSK_H_

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "bt_types.h"

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef enum BT_request_type
    {
    BT_REQUEST_ACCEPT_PAIRING = 0,
    BT_REQUEST_DELETE_PAIRED_DEVICE,
    BT_REQUEST_FACTORY_RESET,
    BT_REQUEST_INIT_MODULE,
    BT_REQUEST_SEND_STANDARD_HCI_COMMAND,
    BT_REQUEST_SET_DISCOVERABLE_STATE,
    BT_REQUEST_SET_ENABLE_STATE,
    BT_REQUEST_SET_LOCAL_DEVICE_ADDRESS,
    BT_REQUEST_SET_TEST_MODE,
    BT_REQUEST_SET_TX_CARRIER_MODE,
    BT_REQUEST_UPDATE_FIRMWARE,
    // SPP
    BT_REQUEST_SPP_CONNECT,
    BT_REQUEST_SPP_DISCONNECT,
    BT_REQUEST_SPP_READ_MFI_AUTH_CHIP_INFO,
    BT_REQUEST_SPP_SEND_DATA,
    // LE Client
    BT_REQUEST_LE_CLIENT_WRITE_REQUEST,
    // LE Server
    BT_REQUEST_LE_SERVER_NOTIFY,
    BT_REQUEST_LE_SERVER_READ_RESPONSE,
    BT_REQUEST_LE_SERVER_SET_ADVERTISING_MODE,

    BT_REQUEST_TYPE_CNT,
    BT_REQUEST_TYPE_INVALID = BT_REQUEST_TYPE_CNT
    } BT_request_type_e;

typedef struct BT_accept_pairing_request
    {
    bool accept;
    } BT_accept_pairing_request_t;

typedef struct BT_delete_paired_device_request
    {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    } BT_delete_paired_device_request_t;

typedef struct BT_send_standard_hci_command_request
    {
    uint16_t op_code;
    uint8_t payload[HCI_PAYLOAD_MAX_SIZE];
    uint8_t payload_len;
    } BT_send_standard_hci_command_request_t;

typedef struct BT_set_discoverable_state_request
    {
    bool enable;
    } BT_set_discoverable_state_request_t;

typedef struct BT_set_enable_state_request
    {
    bool enable;
    } BT_set_enable_state_request_t;

typedef struct BT_set_local_device_address_request
    {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    } BT_set_local_device_address_request_t;

typedef struct BT_set_test_mode_request
    {
    bool enable;
    } BT_set_test_mode_request_t;

typedef struct BT_set_tx_carrier_mode_request
    {
    bool enable;
    BT_tx_channel_type_e channel_type;
    } BT_set_tx_carrier_mode_request_t;

// SPP
typedef struct BT_spp_connect_request
    {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    BT_spp_app_type_e app_type;
    } BT_spp_connect_request_t;

typedef struct BT_spp_disconnect_request
    {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    BT_spp_app_type_e app_type;
    } BT_spp_disconnect_request_t;

typedef struct BT_spp_send_data_request
    {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    BT_spp_app_type_e app_type;
    uint8_t data[SPP_DATA_MAX_SIZE];
    uint8_t data_len;
    } BT_spp_send_data_request_t;

// LE Client
typedef struct BLE_client_write_request_request
    {
    uint16_t handle;
    uint8_t data[GATT_DATA_MAX_SIZE];
    uint8_t data_len;
    } BLE_client_write_request_request_t;

// LE Server
typedef struct BLE_server_notify_request
    {
    uint16_t handle;
    uint8_t data[GATT_DATA_MAX_SIZE];
    uint8_t data_len;
    } BLE_server_notify_request_t;

typedef struct BLE_server_read_response_request
    {
    uint16_t handle;
    uint8_t data[GATT_DATA_MAX_SIZE];
    uint8_t data_len;
    } BLE_server_read_response_request_t;

typedef struct BLE_server_set_advertising_mode_request
    {
    BLE_advertising_mode_e advertising_mode;
    BLE_advertising_data_type_e data_type;
    uint8_t data[BLE_ADVERTISING_DATA_MAX_SIZE];
    uint8_t data_len;
    } BLE_server_set_advertising_mode_request_t;

typedef struct BT_request
    {
    BT_request_type_e type;
    union
        {
        BT_accept_pairing_request_t               accept_pairing;
        BT_delete_paired_device_request_t         delete_paired_device;
        BT_send_standard_hci_command_request_t    send_standard_hci_command;
        BT_set_discoverable_state_request_t       set_discoverable_state;
        BT_set_enable_state_request_t             set_enable_state;
        BT_set_local_device_address_request_t     set_local_device_address;
        BT_set_test_mode_request_t                set_test_mode;
        BT_set_tx_carrier_mode_request_t          set_tx_carrier_mode;
        // SPP
        BT_spp_connect_request_t                  spp_connect;
        BT_spp_disconnect_request_t               spp_disconnect;
        BT_spp_send_data_request_t                spp_send_data;
        // LE Client
        BLE_client_write_request_request_t        le_client_write_request;
        // LE Server
        BLE_server_notify_request_t               le_server_notify;
        BLE_server_read_response_request_t        le_server_read_response;
        BLE_server_set_advertising_mode_request_t le_server_set_advertising_mode;
        } param_u;
    } BT_request_t;

// Sync event
typedef enum BT_sync_event_type
    {
    BT_SYNC_EVENT_DEVICE_STARTED = 0,
    BT_SYNC_EVENT_PAIRED_DEVICE_DELETED,

    BT_SYNC_EVENT_TYPE_CNT,
    BT_SYNC_EVENT_TYPE_INVALID = BT_SYNC_EVENT_TYPE_CNT
    } BT_sync_event_type_e;

typedef struct BT_sync_device_started_event
    {
    uint8_t major_ver;
    uint8_t minor_ver;
    } BT_sync_device_started_event_t;

typedef struct BT_sync_paired_device_deleted_event
    {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    } BT_sync_paired_device_deleted_event_t;

typedef struct BT_sync_event
    {
    BT_sync_event_type_e type;
    union
        {
        BT_sync_device_started_event_t        device_started;
        BT_sync_paired_device_deleted_event_t paired_device_deleted;
        } param_u;
    } BT_sync_event_t;

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
void BT_tsk_clear_requests( void );

void BT_tsk_init( void );

bool BT_tsk_send_request
    (
    const BT_request_t* request
    );

void BT_tsk_sync_gatt_send_signal( void );

bool BT_tsk_sync_gatt_send_wait( void );

void BT_tsk_sync_signal
    (
    const BT_sync_event_t* event
    );

bool BT_tsk_sync_wait
    (
    BT_sync_event_t* event,
    const uint32_t timeout_ms
    );

#ifdef __cplusplus
}
#endif

#endif // _BT_TSK_H_
