/*********************************************************************
* @file  ble_server_core.h
* @brief Bluetooth Manager LE Server Core interface declaration.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _BLE_SERVER_CORE_H_
#define _BLE_SERVER_CORE_H_

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
BLE_server_type_e BLE_core_server_find_handle_owner
    (
    const uint16_t handle
    );

BLE_advertising_mode_e BLE_core_server_get_advertising_mode( void );

bool BLE_core_server_get_connection_status( void );

void BLE_core_server_init( void );

bool BLE_core_server_notify
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint8_t data_len
    );

bool BLE_core_server_read_response
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint8_t data_len
    );

bool BLE_core_server_register_callback
    (
    const BLE_server_type_e server_type,
    const BLE_server_callback_t* callbacks
    );

void BLE_core_server_reset( void );

bool BLE_core_server_set_advertising_mode
    (
    const BLE_advertising_mode_e advertising_mode,
    const BLE_advertising_data_type_e data_type,
    const uint8_t* data,
    const uint8_t data_len
    );

// HCI event handler
void BLE_core_server_handle_gatt_event_read_request
    (
    const uint16_t connection_handle,
    const uint16_t handle
    );

void BLE_core_server_handle_gatt_event_write_request
    (
    const uint16_t connection_handle,
    const uint16_t handle,
    const uint8_t* data,
    const uint8_t data_len
    );

void BLE_core_server_handle_le_event_connected
    (
    const uint16_t connection_handle
    );

void BLE_core_server_handle_le_event_disconnected
    (
    const uint16_t connection_handle
    );

#ifdef __cplusplus
}
#endif

#endif // _BLE_SERVER_CORE_H_
