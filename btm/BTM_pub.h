/*********************************************************************
* @file
* BTM_pub.h
*
* @brief
* Bluetooth Manager - public API
*
* Copyright 2020-2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef BTM_PUB_H
#define BTM_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>
#include "HCI_pub.h"
#include "hci_prv.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define BT_DEVICE_NAME_LEN          ( 32 )
#define BT_DEVICE_ADDRESS_LEN       ( 6 )
#define BT_PIN_CODE_LEN             ( 6 )
#define BT_SW_VERSION_LEN           ( 2 )
#define BT_INFO_CB_MAX_NUM          ( 20 )
#define SW_MODULE_DISABLE_FUNCTION  FALSE

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef enum
    {
    BT_CONNECTION_SUCCESS,
    BT_CONNECTION_FAIL,
    BT_CONNECTION_AUTHENTICATION_ERR
    } bt_connection_result_type;

typedef void ( *bt_connection_info_update_cb )( const bool connection_is_up,
        const uint8_t* connection_info, bt_connection_path_type conn_path );


/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
void BTM_init
    (
    void
    );

void BTM_notify_EW_connection_status
    (
    bt_connection_result_type bt_connection_type
    );

void BTM_reset_factory_default
    (
    void ( *callback_func_ptr )( int )
    );

int BTM_set_enable_state
    (
    bool state
    );

bool BTM_get_enable_state
    (
    void
    );

int BTM_set_autoconnect_state
    (
    bool state
    );

bool BTM_get_autoconnect_state
    (
    void
    );

int BTM_set_discoverable_state
    (
    bool state
    );

bool BTM_get_discoverable_state
    (
    void
    );

bool BTM_add_connection_info_callback
    (
    bt_connection_info_update_cb bt_info_callback
    );

#if SW_MODULE_DISABLE_FUNCTION
    bool BTM_remove_connection_info_callback
        (
        bt_connection_info_update_cb bt_info_callback
        );
#endif

bool BTM_is_max_paired_device_num
    (
    void
    );

int BTM_get_paired_device_num
    (
    void
    );

int BTM_get_paired_device_addr
    (
    const int paired_device_idx,
    uint8_t*  device_addr
    );

int BTM_get_paired_device_info
    (
    const int paired_device_idx,
    uint8_t** device_name,
    bool*     is_connected
    );

int BTM_get_local_device_name
    (
    uint8_t** device_name
    );

int BTM_get_local_device_address
    (
    uint8_t* device_address
    );

int BTM_set_local_device_address
    (
    uint8_t* device_address
    );

int BTM_IOP_set_local_device_address
    (
    uint8_t* bd_addr
    );

int BTM_IOP_read_local_device_address
    (
    void
    );

int BTM_connect_paired_device
    (
    const int paired_device_idx
    );

int BTM_disconnect_paired_device
    (
    const int paired_device_idx
    );

int BTM_unpair_paired_device
    (
    const int paired_device_idx
    );

int BTM_update_sw_version
    (
    uint8_t* update_bt_sw_version
    );

int BTM_get_sw_version
    (
    uint8_t* return_bt_sw_version
    );

void BTM_pairing_info_update
    (
    const uint8_t pair_dev_index,
    const uint8_t *pairing_info
    );

void BTM_connection_info_update
    (
    const bool     connection_is_up,
    const uint32_t  connection_info_length,
    const uint8_t* connection_info,
    const bt_connection_path_type connection_path
    );

void BTM_get_connection_info
    (
    bool*     current_connection_status,
    uint16_t* connection_handle
    );

void BTM_pairing_dev_num_update
    (
    const uint8_t input_pair_dev_num
    );

int BTM_get_connect_request_bd_addrress_rev
    (
    uint8_t* return_connect_bd_addr_rev
    );

int BTM_set_ble_advertisement
    (
    bool enable_ble_adv
    );

int BTM_get_ble_pairing_fail_count
    (
    void
    );

void BTM_receive_user_confirm_evt
    (
    const uint8_t* p_data,
    const uint32_t data_len
    );

void BTM_receive_pairing_clt_evt
    (
    const uint8_t* p_data,
    const uint32_t data_len
    );

bool BTM_is_bt_connected
    (
    void
    );

void BTM_get_ble_connected_device_name
    (
    uint8_t** p_data
    );

int BTM_btc_confirm_passkey
    (
    bool match_result
    );

bool BTM_is_ble_paired_device
    (
    const int paired_device_index
    );

void BTM_receive_btc_paired_fail
    (
    const uint8_t* p_data,
    const uint32_t data_len
    );

#ifdef __cplusplus
}
#endif

#endif /* BTM_PUB_H */

