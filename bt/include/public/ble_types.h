/*********************************************************************
* @file  ble_types.h
* @brief Defines the Bluetooth Manager specific types used for public
*        LE interface.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _BLE_TYPES_H_
#define _BLE_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "cycfg_gatt_db.h"

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
// Note: The maximum size of advertising data defined by BT v4.2 is 31 bytes. Since Cypress module needs
//       to reserve some space for necessary data hence we define the limit as 24 bytes to use
#define BLE_ADVERTISING_DATA_MAX_SIZE ( 24 )

// Note: We now will NOT increase the ATT_MTU after connected. To be backward compatible with BT v4.0
//       that has small ATT_MTU as 23 bytes the phone app and MCU all use the limit as 28 bytes for
//       GATT data size. Once ATT_MTU will be increased after connected, we will have a variable limit
//       depending on ATT_MTU
#define GATT_DATA_MAX_SIZE ( 28 )

#define GATT_ATTR_HANDLE_LEN          ( 2 )
#define GATT_UUID_128BIT_LEN          ( 16 )
#define GATT_WRITE_REQUEST_HEADER_LEN ( 8 )

#define GATT_CLIENT_CONFIG_NONE         ( 0x0000 )
#define GATT_CLIENT_CONFIG_NOTIFICATION ( 0x0001 )
#define GATT_CLIENT_CONFIG_INDICATION   ( 0x0002 )

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
// Note: This is a copy of wiced_bt_ble_advert_type_t defined by Cypress in wiced_bt_ble.h
typedef enum BLE_advertising_data_type
    {
    BLE_ADVERTISING_DATA_FLAG                     = 0x01, // Advertisement flags
    BLE_ADVERTISING_DATA_16SRV_PARTIAL            = 0x02, // List of supported services - 16 bit UUIDs (partial)
    BLE_ADVERTISING_DATA_16SRV_COMPLETE           = 0x03, // List of supported services - 16 bit UUIDs (complete)
    BLE_ADVERTISING_DATA_32SRV_PARTIAL            = 0x04, // List of supported services - 32 bit UUIDs (partial)
    BLE_ADVERTISING_DATA_32SRV_COMPLETE           = 0x05, // List of supported services - 32 bit UUIDs (complete)
    BLE_ADVERTISING_DATA_128SRV_PARTIAL           = 0x06, // List of supported services - 128 bit UUIDs (partial)
    BLE_ADVERTISING_DATA_128SRV_COMPLETE          = 0x07, // List of supported services - 128 bit UUIDs (complete)
    BLE_ADVERTISING_DATA_NAME_SHORT               = 0x08, // Short name
    BLE_ADVERTISING_DATA_NAME_COMPLETE            = 0x09, // Complete name
    BLE_ADVERTISING_DATA_TX_POWER                 = 0x0A, // TX Power level
    BLE_ADVERTISING_DATA_DEV_CLASS                = 0x0D, // Device Class
    BLE_ADVERTISING_DATA_SIMPLE_PAIRING_HASH_C    = 0x0E, // Simple Pairing Hash C
    BLE_ADVERTISING_DATA_SIMPLE_PAIRING_RAND_C    = 0x0F, // Simple Pairing Randomizer R
    BLE_ADVERTISING_DATA_SM_TK                    = 0x10, // Security manager TK value
    BLE_ADVERTISING_DATA_SM_OOB_FLAG              = 0x11, // Security manager Out-of-Band data
    BLE_ADVERTISING_DATA_INTERVAL_RANGE           = 0x12, // Slave connection interval range
    BLE_ADVERTISING_DATA_SOLICITATION_SRV_UUID    = 0x14, // List of solicitated services - 16 bit UUIDs
    BLE_ADVERTISING_DATA_128SOLICITATION_SRV_UUID = 0x15, // List of solicitated services - 128 bit UUIDs
    BLE_ADVERTISING_DATA_SERVICE_DATA             = 0x16, // Service data - 16 bit UUID
    BLE_ADVERTISING_DATA_PUBLIC_TARGET            = 0x17, // Public target address
    BLE_ADVERTISING_DATA_RANDOM_TARGET            = 0x18, // Random target address
    BLE_ADVERTISING_DATA_APPEARANCE               = 0x19, // Appearance
    BLE_ADVERTISING_DATA_ADVERT_INTERVAL          = 0x1a, // Advertising interval
    BLE_ADVERTISING_DATA_LE_BD_ADDR               = 0x1b, // LE device bluetooth address
    BLE_ADVERTISING_DATA_LE_ROLE                  = 0x1c, // LE role
    BLE_ADVERTISING_DATA_256SIMPLE_PAIRING_HASH   = 0x1d, // Simple Pairing Hash C-256
    BLE_ADVERTISING_DATA_256SIMPLE_PAIRING_RAND   = 0x1e, // Simple Pairing Randomizer R-256
    BLE_ADVERTISING_DATA_32SOLICITATION_SRV_UUID  = 0x1f, // List of solicitated services - 32 bit UUIDs
    BLE_ADVERTISING_DATA_32SERVICE_DATA           = 0x20, // Service data - 32 bit UUID
    BLE_ADVERTISING_DATA_128SERVICE_DATA          = 0x21, // Service data - 128 bit UUID
    BLE_ADVERTISING_DATA_CONN_CONFIRM_VAL         = 0x22, // LE Secure Connections Confirmation Value
    BLE_ADVERTISING_DATA_CONN_RAND_VAL            = 0x23, // LE Secure Connections Random Value
    BLE_ADVERTISING_DATA_URI                      = 0x24, // URI
    BLE_ADVERTISING_DATA_INDOOR_POS               = 0x25, // Indoor Positioning
    BLE_ADVERTISING_DATA_TRANS_DISCOVER_DATA      = 0x26, // Transport Discovery Data
    BLE_ADVERTISING_DATA_SUPPORTED_FEATURES       = 0x27, // LE Supported Features
    BLE_ADVERTISING_DATA_UPDATE_CH_MAP_IND        = 0x28, // Channel Map Update Indication
    BLE_ADVERTISING_DATA_PB_ADV                   = 0x29, // PB-ADV
    BLE_ADVERTISING_DATA_MESH_MSG                 = 0x2A, // Mesh Message
    BLE_ADVERTISING_DATA_MESH_BEACON              = 0x2B, // Mesh Beacon
    BLE_ADVERTISING_DATA_3D_INFO_DATA             = 0x3D, // 3D Information Data
    BLE_ADVERTISING_DATA_MANUFACTURER             = 0xFF, // Manufacturer data

    BLE_ADVERTISING_DATA_TYPE_CNT,
    BLE_ADVERTISING_DATA_TYPE_INVALID = BLE_ADVERTISING_DATA_TYPE_CNT
    } BLE_advertising_data_type_e;

typedef enum BLE_advertising_mode
    {
    BLE_ADVERTISING_OFF = 0,
    BLE_ADVERTISING_NON_CONNECTABLE,
    BLE_ADVERTISING_CONNECTABLE,

    BLE_ADVERTISING_MODE_CNT,
    BLE_ADVERTISING_MODE_INVALID = BLE_ADVERTISING_MODE_CNT
    } BLE_advertising_mode_e;

// Note: This is a copy of wiced_bt_ble_address_type_t defined by Cypress in wiced_bt_types.h
typedef enum BLE_bd_addr_type
    {
    BLE_BD_ADDR_PUBLIC = 0,
    BLE_BD_ADDR_RANDOM,

    BLE_BD_ADDR_TYPE_CNT,
    BLE_BD_ADDR_TYPE_INVALID = BLE_BD_ADDR_TYPE_CNT
    } BLE_bd_addr_type_e;

typedef enum BLE_client_type
    {
    BLE_CLIENT_ANCS = 0,
    BLE_CLIENT_AMS,

    BLE_CLIENT_TYPE_CNT,
    BLE_CLIENT_TYPE_INVALID = BLE_CLIENT_TYPE_CNT
    } BLE_client_type_e;

typedef enum BLE_server_type
    {
    BLE_SERVER_MOTOCON = 0,

    BLE_SERVER_TYPE_CNT,
    BLE_SERVER_TYPE_INVALID = BLE_SERVER_TYPE_CNT
    } BLE_server_type_e;

typedef struct BLE_client_callback
    {
    void ( *le_connected_callback )( void );
    void ( *le_disconnected_callback )( void );
    void ( *service_discovered_callback )( const uint16_t start_handle, const uint16_t end_handle );
    void ( *characteristic_discovered_callback )( const uint8_t* uuid, const uint16_t value_handle );
    void ( *descriptor_discovered_callback )( const uint16_t descriptor_handle );
    void ( *discovery_complete_callback )( void );
    void ( *notification_received_callback )( const uint16_t handle, const uint8_t* data, const uint8_t data_len );
    } BLE_client_callback_t;

typedef struct BLE_server_callback
    {
    void ( *le_connected_callback )( void );
    void ( *le_disconnected_callback )( void );
    void ( *read_request_received_callback )( const uint16_t handle );
    void ( *write_request_received_callback )( const uint16_t handle, const uint8_t* data, const uint8_t data_len );
    } BLE_server_callback_t;

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

#endif // _BLE_TYPES_H_
