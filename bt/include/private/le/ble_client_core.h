/*********************************************************************
* @file  ble_client_core.h
* @brief Bluetooth Manager LE Client Core interface declaration.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _BLE_CLIENT_CORE_H_
#define _BLE_CLIENT_CORE_H_

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
BLE_client_type_e BLE_core_client_find_handle_owner
    (
    const uint16_t handle
    );

void BLE_core_client_init( void );

bool BLE_core_client_register_callback
    (
    const BLE_client_type_e client_type,
    const BLE_client_callback_t* callbacks
    );

void BLE_core_client_reset( void );

bool BLE_core_client_write_request
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint8_t data_len
    );

// HCI event handler
void BLE_core_client_handle_gatt_event_characteristic_discovered
    (
    const uint16_t connection_handle,
    const uint8_t* uuid,
    const uint16_t value_handle
    );

void BLE_core_client_handle_gatt_event_descriptor_discovered
    (
    const uint16_t connection_handle,
    const uint16_t descriptor_handle
    );

void BLE_core_client_handle_gatt_event_discovery_complete
    (
    const uint16_t connection_handle
    );

void BLE_core_client_handle_gatt_event_notification
    (
    const uint16_t connection_handle,
    const uint16_t handle,
    const uint8_t* data,
    const uint8_t data_len
    );

void BLE_core_client_handle_gatt_event_service_discovered
    (
    const uint16_t connection_handle,
    const uint8_t* uuid,
    const uint16_t start_handle,
    const uint16_t end_handle
    );

void BLE_core_client_handle_le_event_connected
    (
    const uint16_t connection_handle
    );

void BLE_core_client_handle_le_event_disconnected
    (
    const uint16_t connection_handle
    );

#ifdef __cplusplus
}
#endif

#endif // _BLE_CLIENT_CORE_H_
