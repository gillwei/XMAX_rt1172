/*********************************************************************
* @file  bt_core.h
* @brief Bluetooth Manager General Core interface declaration.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _BT_CORE_H_
#define _BT_CORE_H_

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
typedef enum BT_pairing_status
    {
    BT_PAIRING_NONE = 0,
    BT_PAIRING_USER_CONFIRMING,
    BT_PAIRING_CONFIRMED_WAITING,

    BT_PAIRING_STATUS_CNT,
    BT_PAIRING_STATUS_INVALID = BT_PAIRING_STATUS_CNT
    } BT_pairing_status_e;

typedef enum BT_power_status
    {
    BT_POWER_OFF,
    BT_POWER_ON,
    BT_POWER_ON_UPDATING,
    BT_POWER_ON_READY,

    BT_POWER_STATUS_CNT,
    BT_POWER_STATUS_INVALID = BT_POWER_STATUS_CNT
    } BT_power_status_e;

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
bool BT_core_accept_pairing
    (
    const bool accept
    );

bool BT_core_delete_paired_device
    (
    const uint8_t* bd_addr
    );

bool BT_core_factory_reset( void );

bool BT_core_get_discoverable_state( void );

const uint8_t* BT_core_get_local_device_address( void );

const uint8_t* BT_core_get_local_device_name( void );

uint8_t BT_core_get_num_paired_devices( void );

const BT_device_info_t* BT_core_get_paired_device_info
    (
    const uint8_t device_idx
    );

BT_pairing_status_e BT_core_get_pairing_status( void );

BT_power_status_e BT_core_get_power_status( void );

const uint8_t* BT_core_get_sw_version( void );

bool BT_core_get_test_mode( void );

void BT_core_init( void );

bool BT_core_init_module( void );

bool BT_core_is_paired_device
    (
    const uint8_t* bd_addr
    );

bool BT_core_is_paired_device_auth_lost
    (
    const uint8_t* bd_addr
    );

bool BT_core_is_paired_device_max_num_reached( void );

bool BT_core_send_standard_hci_command
    (
    const uint16_t op_code,
    const uint8_t* payload,
    const uint8_t payload_len
    );

bool BT_core_set_discoverable_state
    (
    const bool enable
    );

bool BT_core_set_enable_state
    (
    const bool enable,
    const bool store
    );

bool BT_core_set_local_device_address
    (
    const uint8_t* bd_addr
    );

void BT_core_set_log_level
    (
    const BT_log_severity_e severity
    );

bool BT_core_set_test_mode
    (
    const bool enable
    );

bool BT_core_set_tx_carrier_mode
    (
    const bool enable,
    const BT_tx_channel_type_e channel_type
    );

bool BT_core_update_firmware( void );

// HCI event handler
void BT_core_handle_device_event_connection_status
    (
    const uint8_t* bd_addr,
    const BT_transport_type_e transport_type,
    const bool connected,
    const uint8_t reason
    );

void BT_core_handle_device_event_device_started
    (
    const uint8_t major_version,
    const uint8_t minor_version
    );

void BT_core_handle_device_event_paired_device_deleted
    (
    const uint8_t* bd_addr
    );

void BT_core_handle_device_event_paired_device_list
    (
    const uint8_t* raw_device_list
    );

void BT_core_handle_device_event_pairing_complete
    (
    const uint8_t result
    );

void BT_core_handle_device_event_user_confirmation
    (
    const uint8_t* bd_addr,
    const uint32_t passkey
    );

void BT_core_handle_standard_event_chip_erase_complete
    (
    const uint8_t error_code
    );

void BT_core_handle_standard_event_launch_ram_complete
    (
    const uint8_t error_code
    );

void BT_core_handle_standard_event_write_ram_complete
    (
    const uint8_t error_code
    );

#ifdef __cplusplus
}
#endif

#endif // _BT_CORE_H_
