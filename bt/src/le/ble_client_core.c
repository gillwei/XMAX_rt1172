/*********************************************************************
* @file  ble_client_core.c
* @brief Bluetooth Manager LE Client Core interface definition.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <FreeRTOS.h>
#include <task.h>
#include <string.h>

#include "bt_log.h"
#include "bt_tsk.h"
#include "bt_utils.h"
#include "ble_client_core.h"
#include "hci_cmd.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef struct BLE_client_service
    {
    bool discovered;
    uint16_t start_handle;
    uint16_t end_handle;
    BLE_client_callback_t callbacks;
    } BLE_client_service_t;

typedef struct BLE_client_core
    {
    bool initialized;
    bool acl_connected;
    uint16_t connection_handle;
    BLE_client_service_t clients[BLE_CLIENT_TYPE_CNT];
    } BLE_client_core_t;

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/
static const uint8_t s_le_client_service_uuids[BLE_CLIENT_TYPE_CNT][GATT_UUID_128BIT_LEN] =
    {
    /* BLE_CLIENT_ANCS */ { 0xD0, 0x00, 0x2D, 0x12, 0x1E, 0x4B, 0x0F, 0xA4, 0x99, 0x4E, 0xCE, 0xB5, 0x31, 0xF4, 0x05, 0x79 },
    /* BLE_CLIENT_AMS  */ { 0xDC, 0xF8, 0x55, 0xAD, 0x02, 0xC5, 0xF4, 0x8E, 0x3A, 0x43, 0x36, 0x0F, 0x2B, 0x50, 0xD3, 0x89 }
    };

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
static BLE_client_core_t s_core = { 0 };

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/
static BLE_client_type_e BLE_core_client_find_service_uuid_owner
    (
    const uint8_t* service_uuid
    );

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Find out the LE Client who owns the attribute handle
@details Find out the LE Client who owns the attribute handle
@return  None
@retval  The LE Client who owns the attribute handle
================================================================================================*/
BLE_client_type_e BLE_core_client_find_handle_owner
    (
    const uint16_t handle
    )
{
for( BLE_client_type_e client_type = 0; client_type < BLE_CLIENT_TYPE_CNT; ++client_type )
    {
    if( ( handle >= s_core.clients[client_type].start_handle ) &&
        ( handle <= s_core.clients[client_type].end_handle ) )
        {
        return client_type;
        }
    }
return BLE_CLIENT_TYPE_INVALID;
}

/*================================================================================================
@brief   Find out the LE Client who owns the service uuid
@details Find out the LE Client who owns the service uuid
@return  None
@retval  The LE Client who owns the service uuid
================================================================================================*/
static BLE_client_type_e BLE_core_client_find_service_uuid_owner
    (
    const uint8_t* service_uuid
    )
{
for( BLE_client_type_e client_type = 0; client_type < BLE_CLIENT_TYPE_CNT; ++client_type )
    {
    if( 0 == memcmp( s_le_client_service_uuids[client_type], service_uuid, GATT_UUID_128BIT_LEN ) )
        {
        return client_type;
        }
    }
return BLE_CLIENT_TYPE_INVALID;
}

/*================================================================================================
@brief   Bluetooth Manager LE Client Core initialization
@details Bluetooth Manager LE Client Core initialization
@return  None
@retval  None
================================================================================================*/
void BLE_core_client_init( void )
{
if( false == s_core.initialized )
    {
    int32_t num_service_uuids = sizeof( s_le_client_service_uuids ) / sizeof( s_le_client_service_uuids[0] );
    configASSERT( BLE_CLIENT_TYPE_CNT == num_service_uuids );

    BLE_core_client_reset();

    s_core.initialized = true;
    }
}

/*================================================================================================
@brief   Register the callbacks to listen the LE Client's updates
@details Register the callbacks to listen the LE Client's updates
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BLE_core_client_register_callback
    (
    const BLE_client_type_e client_type,
    const BLE_client_callback_t* callbacks
    )
{
bool ret = false;

if( ( client_type < 0 ) || ( client_type >= BLE_CLIENT_TYPE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid client type: %d", client_type );
    }
else if( NULL == callbacks )
    {
    BT_LOG_DEBUG( "NULL callbacks" );
    }
else
    {
    memcpy( &( s_core.clients[client_type].callbacks ), callbacks, sizeof( BLE_client_callback_t ) );
    ret = true;
    }
return ret;
}

/*================================================================================================
@brief   Reset Bluetooth Manager LE Client Core's data
@details Reset Bluetooth Manager LE Client Core's data
@return  None
@retval  None
================================================================================================*/
void BLE_core_client_reset( void )
{
for( BLE_client_type_e client_type = 0; client_type < BLE_CLIENT_TYPE_CNT; ++client_type )
    {
    s_core.clients[client_type].discovered = false;
    s_core.clients[client_type].start_handle = 0;
    s_core.clients[client_type].end_handle = 0;

    if( s_core.acl_connected )
        {
        if( NULL != s_core.clients[client_type].callbacks.le_disconnected_callback )
            {
            s_core.clients[client_type].callbacks.le_disconnected_callback();
            }
        }
    }

s_core.acl_connected = false;
s_core.connection_handle = 0;
}

/*================================================================================================
@brief   Send the LE Client's write request to the server
@details Send the HCI command of sending the LE Client's write request to the server to Cypress
         module. The data length should not exceed the limit specified in GATT_DATA_MAX_SIZE
@return  None
@retval  Whether or not the HCI command is sent to Cypress module successfully
================================================================================================*/
bool BLE_core_client_write_request
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint8_t data_len
    )
{
bool ret = false;
uint8_t param[BT_CONNECTION_HANDLE_LEN + GATT_ATTR_HANDLE_LEN + data_len];

if( ( NULL == data ) || ( 0 == data_len ) || ( data_len > GATT_DATA_MAX_SIZE ) )
    {
    BT_LOG_DEBUG( "Invalid data" );
    }
else if( BLE_CLIENT_TYPE_INVALID == BLE_core_client_find_handle_owner( handle ) )
    {
    BT_LOG_DEBUG( "No LE client owning this handle: 0x%x", handle );
    }
else
    {
    if( BT_tsk_sync_gatt_send_wait() )
        {
        memset( param, 0, sizeof( param ) );
        INT16_TO_LITTLE_ENDIAN( s_core.connection_handle, &( param[0] ) );
        INT16_TO_LITTLE_ENDIAN( handle, &( param[2] ) );
        memcpy( &( param[4] ), data, data_len );

        ret = HCI_send_wiced_command( HCI_CONTROL_GATT_COMMAND_WRITE_REQUEST, param, sizeof( param ) );
        }
    }
return ret;
}

// HCI event handler

/*================================================================================================
@brief   Handle the GATT event that the characteristic is discovered
@details Handle the GATT event that the characteristic is discovered
@return  None
@retval  None
================================================================================================*/
void BLE_core_client_handle_gatt_event_characteristic_discovered
    (
    const uint16_t connection_handle,
    const uint8_t* uuid,
    const uint16_t value_handle
    )
{
BLE_client_type_e client_type = BLE_core_client_find_handle_owner( value_handle );

if( BLE_CLIENT_TYPE_INVALID == client_type )
    {
    BT_LOG_ERROR( "No LE client owning this handle: 0x%x", value_handle );
    }
else
    {
    if( NULL != s_core.clients[client_type].callbacks.characteristic_discovered_callback )
        {
        s_core.clients[client_type].callbacks.characteristic_discovered_callback( uuid, value_handle );
        }
    }
}

/*================================================================================================
@brief   Handle the GATT event that the descriptor is discovered
@details Handle the GATT event that the descriptor is discovered
@return  None
@retval  None
================================================================================================*/
void BLE_core_client_handle_gatt_event_descriptor_discovered
    (
    const uint16_t connection_handle,
    const uint16_t descriptor_handle
    )
{
BLE_client_type_e client_type = BLE_core_client_find_handle_owner( descriptor_handle );

if( BLE_CLIENT_TYPE_INVALID == client_type )
    {
    BT_LOG_ERROR( "No LE client owning this handle: 0x%x", descriptor_handle );
    }
else
    {
    if( NULL != s_core.clients[client_type].callbacks.descriptor_discovered_callback )
        {
        s_core.clients[client_type].callbacks.descriptor_discovered_callback( descriptor_handle );
        }
    }
}

/*================================================================================================
@brief   Handle the GATT event that the whole discovery process is completed
@details Handle the GATT event that the whole discovery process is completed
@return  None
@retval  None
================================================================================================*/
void BLE_core_client_handle_gatt_event_discovery_complete
    (
    const uint16_t connection_handle
    )
{
for( BLE_client_type_e client_type = 0; client_type < BLE_CLIENT_TYPE_CNT; ++client_type )
    {
    if( s_core.clients[client_type].discovered )
        {
        if( NULL != s_core.clients[client_type].callbacks.discovery_complete_callback )
            {
            s_core.clients[client_type].callbacks.discovery_complete_callback();
            }
        }
    }
}

/*================================================================================================
@brief   Handle the GATT event that the notification from the server is received
@details Handle the GATT event that the notification from the server is received
@return  None
@retval  None
================================================================================================*/
void BLE_core_client_handle_gatt_event_notification
    (
    const uint16_t connection_handle,
    const uint16_t handle,
    const uint8_t* data,
    const uint8_t data_len
    )
{
BLE_client_type_e client_type = BLE_core_client_find_handle_owner( handle );

if( BLE_CLIENT_TYPE_INVALID == client_type )
    {
    BT_LOG_ERROR( "No LE client owning this handle: 0x%x", handle );
    }
else
    {
    if( NULL != s_core.clients[client_type].callbacks.notification_received_callback )
        {
        s_core.clients[client_type].callbacks.notification_received_callback( handle, data, data_len );
        }
    }
}

/*================================================================================================
@brief   Handle the GATT event that the service is discovered
@details Handle the GATT event that the service is discovered
@return  None
@retval  None
================================================================================================*/
void BLE_core_client_handle_gatt_event_service_discovered
    (
    const uint16_t connection_handle,
    const uint8_t* uuid,
    const uint16_t start_handle,
    const uint16_t end_handle
    )
{
BLE_client_type_e client_type = BLE_core_client_find_service_uuid_owner( uuid );

if( BLE_CLIENT_TYPE_INVALID == client_type )
    {
    BT_LOG_ERROR( "No LE client owning this service uuid" );
    }
else
    {
    s_core.clients[client_type].discovered = true;
    s_core.clients[client_type].start_handle = start_handle;
    s_core.clients[client_type].end_handle = end_handle;
    }
}

/*================================================================================================
@brief   Handle the LE event that LE is connected to the remote device
@details Handle the LE event that LE is connected to the remote device
@return  None
@retval  None
================================================================================================*/
void BLE_core_client_handle_le_event_connected
    (
    const uint16_t connection_handle
    )
{
s_core.acl_connected = true;
s_core.connection_handle = connection_handle;

for( BLE_client_type_e client_type = 0; client_type < BLE_CLIENT_TYPE_CNT; ++client_type )
    {
    if( NULL != s_core.clients[client_type].callbacks.le_connected_callback )
        {
        s_core.clients[client_type].callbacks.le_connected_callback();
        }
    }
}

/*================================================================================================
@brief   Handle the LE event that LE is disconnected from the remote device
@details Handle the LE event that LE is disconnected from the remote device
@return  None
@retval  None
================================================================================================*/
void BLE_core_client_handle_le_event_disconnected
    (
    const uint16_t connection_handle
    )
{
BLE_core_client_reset();
}

#ifdef __cplusplus
}
#endif
