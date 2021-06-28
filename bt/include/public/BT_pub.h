/*********************************************************************
* @file  BT_pub.h
* @brief Bluetooth Manager Public interface declaration.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _BT_PUB_H_
#define _BT_PUB_H_

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
BT_status_e BT_accept_pairing
    (
    const bool accept
    );

BT_status_e BT_delete_paired_device
    (
    const uint8_t* bd_addr
    );

bool BT_get_discoverable_state( void );

bool BT_get_enable_state( void );

BT_status_e BT_factory_reset( void );

const uint8_t* BT_get_local_device_address( void );

const uint8_t* BT_get_local_device_name( void );

BT_status_e BT_get_num_paired_devices
    (
    uint8_t* num_devices
    );

BT_status_e BT_get_paired_device_info
    (
    const uint8_t device_idx,
    BT_device_info_t* device_info
    );

const uint8_t* BT_get_sw_version( void );

bool BT_get_test_mode( void );

BT_status_e BT_init( void );

BT_status_e BT_is_paired_device_auth_lost
    (
    const uint8_t* bd_addr,
    bool* auth_lost
    );

BT_status_e BT_is_paired_device_max_num_reached
    (
    bool* max_num_reached
    );

BT_status_e BT_set_discoverable_state
    (
    const bool enable
    );

BT_status_e BT_set_enable_state
    (
    const bool enable
    );

BT_status_e BT_set_local_device_address
    (
    const uint8_t* bd_addr
    );

void BT_set_log_level
    (
    const BT_log_severity_e severity
    );

BT_status_e BT_set_test_mode
    (
    const bool enable
    );

BT_status_e BT_set_tx_carrier_mode
    (
    const bool enable,
    const BT_tx_channel_type_e channel_type
    );

#if 0
// SPP
BT_status_e BT_spp_add_connection_status_callback
    (
    const BT_spp_app_type_e app_type,
    BT_spp_connection_status_callback callback
    );

BT_status_e BT_spp_add_data_received_callback
    (
    const BT_spp_app_type_e app_type,
    BT_spp_data_received_callback callback
    );

BT_status_e BT_spp_connect
    (
    const uint8_t* bd_addr,
    const BT_spp_app_type_e app_type
    );

BT_status_e BT_spp_disconnect
    (
    const uint8_t* bd_addr,
    const BT_spp_app_type_e app_type
    );

BT_status_e BT_spp_read_mfi_auth_chip_info( void );

BT_status_e BT_spp_send_data
    (
    const uint8_t* bd_addr,
    const BT_spp_app_type_e app_type,
    const uint8_t* data,
    const uint8_t data_len
    );

// LE
BT_status_e BT_le_gatt_notify
    (
    const uint16_t attr_handle,
    const uint8_t* data,
    const uint8_t data_len
    );

BT_status_e BT_le_gatt_read_response
    (
    const uint16_t attr_handle,
    const uint8_t* data,
    const uint8_t data_len
    );

BT_status_e BT_le_gatt_write_request
    (
    const uint16_t attr_handle,
    const uint8_t* data,
    const uint8_t data_len
    );

bool BT_le_get_advertisement_state( void );

BT_status_e BT_le_register_client_callback
    (
    const BT_LE_client_type_e client_type,
    const BT_LE_client_callback_t* callbacks
    );

BT_status_e BT_le_register_server_callback
    (
    const BT_LE_server_type_e server_type,
    const BT_LE_server_callback_t* callbacks
    );

BT_status_e BT_le_set_advertisement_state
    (
    const bool enable
    );
#endif

#ifdef __cplusplus
}
#endif

#endif // _BT_PUB_H_
