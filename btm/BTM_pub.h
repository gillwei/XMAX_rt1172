/*********************************************************************
* @file
* BTM_pub.h
*
* @brief
* Bluetooth Manager - public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef BTM_PUB_H
#define BTM_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>
#include <stdint.h>

#define BT_DEVICE_NAME_LEN          ( 32 )
#define BT_DEVICE_ADDRESS_LEN       ( 6 )
#define BT_PIN_CODE_LEN             ( 6 )
#define BT_SW_VERSION_LEN           ( 2 )

typedef enum
    {
    BT_CONNECTION_SUCCESS,
    BT_CONNECTION_FAIL,
    BT_CONNECTION_TIMEOUT,
    BT_CONNECTION_LOST,
    } bt_connection_result_type;

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
    const uint8_t *pairing_info
    );

void BTM_connection_info_update
    (
    const bool     connection_is_up,
    const uint8_t* connection_info
    );

void BTM_get_connection_info
    (
    bool*     current_connection_status,
    uint16_t* connection_handle
    );

#ifdef __cplusplus
}
#endif

#endif /* BTM_PUB_H */

