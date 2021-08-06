/*********************************************************************
* @file
* bc_ams_main.c
*
* @brief
* Bluetooth Connectivity - AMS parser
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "semphr.h"
#include "fsl_debug_console.h"
#include "EW_pub.h"
#include "BT_pub.h"
#include "MM_pub.h"
#include "bc_ams_priv.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define GATT_AMS_NOTIFICATION_DATA_MAX_LEN                  ( 64 )

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef enum
    {
    AMS_CHARACTERISTIC_REMOTE_CONTROL,
    AMS_CHARACTERISTIC_ENTITY_UPDATE,
    AMS_CHARACTERISTIC_ENTITY_ATTRIBUTE,
    AMS_CHARACTERISTIC_TOTAL
    } ams_characteristic_enum;

typedef struct
    {
    ams_characteristic_enum characteristic;
    uint16_t value_handle;
    uint16_t cccd_handle;
    bool     is_discovered;
    } ams_characteristic_type;

typedef struct
    {
    uint16_t handle;
    uint8_t  data[GATT_AMS_NOTIFICATION_DATA_MAX_LEN];
    uint16_t data_len;
    } gatt_ams_notification_struct;

void BC_ams_ble_connected_callback( void );
void BC_ams_ble_disconnected_callback( void );
void BC_ams_service_discovered_callback( const uint16_t start_handle, const uint16_t end_handle );
void BC_ams_characteristic_discovered_callback( const uint8_t* uuid, const uint16_t value_handle );
void BC_ams_descriptor_discovered_callback( const uint16_t descriptor_handle );
void BC_ams_discovery_complete_callback( void );
void BC_ams_notification_received_callback( const uint16_t handle, const uint8_t* data, const uint8_t length );

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
/* AMS characteristic UUID in little endian */
static const char AMS_CHARACTERISTIC_UUID[AMS_CHARACTERISTIC_TOTAL][GATT_UUID_128BIT_LEN] =
    {
    {0xC2, 0x51, 0xCA, 0xF7, 0x56, 0x0E, 0xDF, 0xB8, 0x8A, 0x4A, 0xB1, 0x57, 0xD8, 0x81, 0x3C, 0x9B}, // remote control
    {0x02, 0xC1, 0x96, 0xBA, 0x92, 0xBB, 0x0C, 0x9A, 0x1F, 0x41, 0x8D, 0x80, 0xCE, 0xAB, 0x7C, 0x2F}, // entity update
    {0xD7, 0xD5, 0xBB, 0x70, 0xA8, 0xA3, 0xAB, 0xA6, 0xD8, 0x46, 0xAB, 0x23, 0x8C, 0xF3, 0xB2, 0xC6}  // entity attribute
    };
static ams_characteristic_type ams_characteristics[AMS_CHARACTERISTIC_TOTAL];
static uint16_t ams_start_handle;
static uint16_t ams_end_handle;
static bool     is_ble_connected;
static bool     ams_is_discovered;
static int      ams_characteristic_discovered_count;
static uint8_t  ams_index_table[AMS_CHARACTERISTIC_TOTAL];
static gatt_ams_notification_struct gatt_ams_notification_data;

static BLE_client_callback_t ams_client_callback =
    {
    BC_ams_ble_connected_callback,
    BC_ams_ble_disconnected_callback,
    BC_ams_service_discovered_callback,
    BC_ams_characteristic_discovered_callback,
    BC_ams_descriptor_discovered_callback,
    BC_ams_discovery_complete_callback,
    BC_ams_notification_received_callback
    };
/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*********************************************************************
*
* @private
* register_notification
*
* Registser AMS notification
*
*********************************************************************/
static void register_notification
    (
    void
    )
{
uint8_t entity_update_idx = ams_index_table[AMS_CHARACTERISTIC_ENTITY_UPDATE];
if( ams_characteristics[entity_update_idx].cccd_handle > 0 )
    {
    // write cccd to enable notification
    PRINTF( "write entity update cccd %x\r\n", ams_characteristics[entity_update_idx].cccd_handle );
    uint8_t data[8];
    data[0] = GATT_CLIENT_CONFIG_NOTIFICATION & 0xff;
    data[1] = ( GATT_CLIENT_CONFIG_NOTIFICATION >> 8 ) & 0xff;
    BLE_client_write_request( ams_characteristics[entity_update_idx].cccd_handle, data, 2 );

    // register for notification of player
    data[0] = AMS_ENTITY_ID_PLAYER;
    data[1] = AMS_PLAYER_ATTRIBUTE_ID_NAME;
    data[2] = AMS_PLAYER_ATTRIBUTE_ID_PLAYBACK_INFO;
    data[3] = AMS_PLAYER_ATTRIBUTE_ID_VOLUME;
    BLE_client_write_request( ams_characteristics[entity_update_idx].value_handle, data, 4 );

    // register for notification of track
    data[0] = AMS_ENTITY_ID_TRACK;
    data[1] = AMS_TRACK_ATTRIBUTE_ID_ARTIST;
    data[2] = AMS_TRACK_ATTRIBUTE_ID_ALBUM;
    data[3] = AMS_TRACK_ATTRIBUTE_ID_TITLE;
    data[4] = AMS_TRACK_ATTRIBUTE_ID_DURATION;
    BLE_client_write_request( ams_characteristics[entity_update_idx].value_handle, data, 5 );
    }
else
    {
    BC_AMS_PRINTF( "ams %s err, invalid cccd\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @public
* BC_ams_ble_connected_callback
*
* Callback function when BLE is connected
*
*********************************************************************/
void BC_ams_ble_connected_callback
    (
    void
    )
{
BC_AMS_PRINTF( "%s\r\n", __FUNCTION__ );
is_ble_connected = true;
MM_update_playback_status( is_ble_connected );
}

/*********************************************************************
*
* @public
* BC_ams_ble_disconnected_callback
*
* Callback function when BLE is disconnected
*
*********************************************************************/
void BC_ams_ble_disconnected_callback
    (
    void
    )
{
BC_AMS_PRINTF( "%s\r\n", __FUNCTION__ );
is_ble_connected  = false;
ams_is_discovered = false;
ams_start_handle  = 0;
ams_end_handle    = 0;
ams_characteristic_discovered_count = 0;
memset( ams_characteristics, 0, sizeof( ams_characteristics ) );
MM_update_playback_status( is_ble_connected );
}

/*********************************************************************
*
* @public
* BC_ams_service_discovered_callback
*
* Callback function when AMS is discovered
*
* @param start_handle The start handle of AMS service
* @param end_handle The end handle of AMS service
*
*********************************************************************/
void BC_ams_service_discovered_callback
    (
    const uint16_t start_handle,
    const uint16_t end_handle
    )
{
BC_AMS_PRINTF( "%s start %x, end %x\r\n", __FUNCTION__, start_handle, end_handle );
ams_is_discovered = true;
ams_start_handle  = start_handle;
ams_end_handle    = end_handle;
}

/*********************************************************************
*
* @public
* BC_ams_characteristic_discovered_callback
*
* Callback function when characteristic is discovered
*
* @param descriptor_handle The handle of the discovered descriptor
*
*********************************************************************/
void BC_ams_characteristic_discovered_callback
    (
    const uint8_t* uuid,
    const uint16_t value_handle
    )
{
BC_AMS_PRINTF( "%s, handle: %x\r\n", __FUNCTION__, value_handle );

/**
 * The characteristics are discovered in the order of ascending handle value.
 * The ams_characteristics array has to maintain this nature
 * ( ams_characteristics[x].value_handle < ams_characteristics[x+1].value_handle )
 * to map the descriptor to the corresponding characteristic later in
 * the MM_ams_gatt_descriptor_discovered_callback.
 *
 * For AMS, it could be risky to assume that the characteristics are always discovered
 * in the sequence of REMOTE_CONTROL, ENTITY_UPDATE, and ENTITY_ATTRIBUTE.
 * So a lookup table, "ams_index_table" is used for converting from the characteristic
 * to the index of "ams_characteristics" array.
 *
 */

if( AMS_CHARACTERISTIC_TOTAL > ams_characteristic_discovered_count )
    {
    for( int i = 0; i < AMS_CHARACTERISTIC_TOTAL; i++ )
        {
        if( 0 == memcmp( uuid, AMS_CHARACTERISTIC_UUID[i], GATT_UUID_128BIT_LEN ) )
            {
            BC_AMS_PRINTF( "%s, found: %d\r\n", __FUNCTION__, i );
            ams_characteristics[ams_characteristic_discovered_count].characteristic = i;
            ams_characteristics[ams_characteristic_discovered_count].is_discovered  = true;
            ams_characteristics[ams_characteristic_discovered_count].value_handle   = value_handle;
            ams_index_table[i] = ams_characteristic_discovered_count;
            ams_characteristic_discovered_count++;
            break;
            }
        }
    }
else
    {
    BC_AMS_PRINTF( "%s err\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @public
* BC_ams_descriptor_discovered_callback
*
* Callback function when descriptor is discovered
*
* @param descriptor_handle The handle of the discovered descriptor
*
*********************************************************************/
void BC_ams_descriptor_discovered_callback
    (
    const uint16_t descriptor_handle
    )
{
uint16_t end_handle = 0;

BC_AMS_PRINTF( "%s, %04x\r\n", __FUNCTION__, descriptor_handle );

for( int i = 0; i < AMS_CHARACTERISTIC_TOTAL; i++ )
    {
    if( AMS_CHARACTERISTIC_TOTAL == ( i + 1 ) )
        {
        end_handle = ams_end_handle;
        }
    else
        {
        end_handle = ams_characteristics[i+1].value_handle - 1;
        }

    if( descriptor_handle > ams_characteristics[i].value_handle &&
        descriptor_handle <= end_handle )
        {
        ams_characteristics[i].cccd_handle = descriptor_handle;
        BC_AMS_PRINTF( "found cccd handle of ams service %d\r\n", i );
        break;
        }
    }
}

/*********************************************************************
*
* @public
* BC_ams_discovery_complete_callback
*
* Callback function when the discovery of all the characteristics
* are completed
*
*********************************************************************/
void BC_ams_discovery_complete_callback
    (
    void
    )
{
BC_AMS_PRINTF( "%s\r\n", __FUNCTION__ );
register_notification();
}

/*********************************************************************
*
* @public
* BC_ams_notification_received_callback
*
* Callback function when AMS notification is received
*
* @param handle The handle of characteristic
* @param data The pointer to the data byte array
* @param length The length of the data byte array
*
*********************************************************************/
void BC_ams_notification_received_callback
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint8_t  length
    )
{
BC_AMS_PRINTF( "%s, handle: 0x%x, len: %d\r\n", __FUNCTION__, handle, length );
uint8_t i = ams_index_table[AMS_CHARACTERISTIC_ENTITY_UPDATE];
if( ams_characteristics[i].value_handle == handle )
    {
    gatt_ams_notification_data.handle   = handle;
    if( length > GATT_AMS_NOTIFICATION_DATA_MAX_LEN + 4 )
        {
        gatt_ams_notification_data.data_len = GATT_AMS_NOTIFICATION_DATA_MAX_LEN;
        }
    else
        {
        gatt_ams_notification_data.data_len = length - 4;
        }

    // Ignore total length and data index (4 bytes) which are designed for ANCS.
    memcpy( gatt_ams_notification_data.data, &data[4], gatt_ams_notification_data.data_len );
    MM_ams_handler_entity_update_received( gatt_ams_notification_data.data, gatt_ams_notification_data.data_len );
    }
else
    {
    PRINTF( "Err: %s %d \r\n", __FUNCTION__, length );
    }
}

/*********************************************************************
*
* @public
* BC_ams_send_remote_control
*
* Send remote control command
*
*********************************************************************/
void BC_ams_send_remote_control
    (
    const uint8_t re_ctrl_cmd
    )
{
uint8_t  remote_control_idx = ams_index_table[AMS_CHARACTERISTIC_REMOTE_CONTROL];
uint16_t handle             = ams_characteristics[remote_control_idx].value_handle;

if( ams_characteristics[remote_control_idx].is_discovered &&
    ( handle > 0 ) )
    {
    BC_AMS_PRINTF( "%s %d\r\n", __FUNCTION__, re_ctrl_cmd );
    BLE_client_write_request( handle, &re_ctrl_cmd, 1 );
    }
}

/*********************************************************************
*
* @public
* BC_ams_is_ams_connected
*
* Return ams connected status.
*
*********************************************************************/
bool BC_ams_is_ams_connected
    (
    void
    )
{
return( ams_is_discovered && is_ble_connected );
}

/*********************************************************************
*
* @private
* bc_ams_init
*
* Init AMS in Bluetooth Connectivity
*
*********************************************************************/
void bc_ams_init
    (
    void
    )
{
BLE_client_register_callback( BLE_CLIENT_AMS, &ams_client_callback );
}

