/*********************************************************************
* @file  bt_spp_core.h
* @brief Bluetooth Manager SPP Core interface declaration.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _BT_SPP_CORE_H_
#define _BT_SPP_CORE_H_

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
typedef enum BT_spp_connection_type
    {
    BT_SPP_CONNECTION_SPP = 0,
    BT_SPP_CONNECTION_IAP,

    BT_SPP_CONNECTION_TYPE_CNT,
    BT_SPP_CONNECTION_TYPE_INVALID = BT_SPP_CONNECTION_TYPE_CNT
    } BT_spp_connection_type_e;

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
bool BT_core_spp_add_connection_status_callback
    (
    const BT_spp_app_type_e app_type,
    BT_spp_connection_status_callback callback
    );

bool BT_core_spp_add_data_received_callback
    (
    const BT_spp_app_type_e app_type,
    BT_spp_data_received_callback callback
    );

bool BT_core_spp_connect
    (
    const uint8_t* bd_addr,
    const BT_spp_app_type_e app_type
    );

bool BT_core_spp_disconnect
    (
    const uint8_t* bd_addr,
    const BT_spp_app_type_e app_type
    );

BT_connection_status_e BT_core_spp_get_connection_status
    (
    const BT_spp_app_type_e app_type,
    uint8_t* bd_addr
    );

void BT_core_spp_init( void );

bool BT_core_spp_read_mfi_auth_chip_info( void );

void BT_core_spp_reset( void );

bool BT_core_spp_send_data
    (
    const uint8_t* bd_addr,
    const BT_spp_app_type_e app_type,
    const uint8_t* data,
    const uint8_t data_len
    );

// HCI event handler
void BT_core_spp_handle_event_connected
    (
    const BT_spp_connection_type_e connection_type,
    const uint8_t* bd_addr,
    const uint16_t connection_handle,
    const BT_spp_app_type_e app_type
    );

void BT_core_spp_handle_event_connection_failed
    (
    const BT_spp_connection_type_e connection_type,
    const BT_spp_app_type_e app_type
    );

void BT_core_spp_handle_event_disconnected
    (
    const BT_spp_connection_type_e connection_type,
    const uint16_t connection_handle,
    const BT_spp_app_type_e app_type
    );

void BT_core_spp_handle_event_rx_data
    (
    const BT_spp_connection_type_e connection_type,
    const uint16_t connection_handle,
    const BT_spp_app_type_e app_type,
    const uint8_t* data,
    const uint8_t data_len
    );

void BT_core_spp_handle_iap_event_auth_chip_info
    (
    const uint8_t device_version,
    const uint8_t firmware_version,
    const uint8_t protocol_major_version,
    const uint8_t protocol_minor_version,
    const uint32_t device_id
    );

#ifdef __cplusplus
}
#endif

#endif // _BT_SPP_CORE_H_
