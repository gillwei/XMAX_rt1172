/*********************************************************************
* @file hci_le_gatt.c
*
* @brief
* Handle BLE gatt data and events.
*
* Copyright 2020-2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                          GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "projdefs.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "error_code.h"
#include "fsl_debug_console.h"
#include "hci_control_api.h"
#include "HCI_pub.h"
#include "hci_prv.h"
#include "cycfg_gatt_db.h"
#include "BTM_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define GATT_WRITE_REQUEST_QUEUE_LENGTH   ( 16 )
#define GATT_WRITE_REQUEST_HEADER_LENGTH  ( 4 ) /* connection handle 2 bytes, characteristic handle 2 bytes */

#define ENABLE_BLE_DEBUG_LOG    ( 1 )
#if( ENABLE_BLE_DEBUG_LOG )
    #define BLE_PRINTF  PRINTF
    #define BLE_READ_WRITE_DEBUG_ENABLE  0
    #define BLE_NOTIFY_DEBUG_ENABLE      0
#else
    #define BLE_PRINTF(fmt, ...)
#endif

#define CCCD_DATA_FIRST_BYTE_NUM   8
#define CCCD_DATA_SECOND_BYTE_NUM  9
#define WRITE_REQUEST_HEADER_NUM   8

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/
typedef struct
    {
    uint16_t start_handle;
    uint16_t end_handle;
    bool     is_discovered;
    const ble_client_callback* callback;
    } ble_client_struct;

typedef struct
    {
    uint16_t start_handle;
    uint16_t end_handle;
    ble_server_callback* callback;
    uint16_t connection_id;
    } ble_server_struct;

typedef struct
    {
    uint16_t handle;
    uint8_t  data[BLE_GATT_WRITE_REQUEST_DATA_MAX_LEN];
    uint16_t data_len;
    } ble_gatt_write_request_struct;

typedef enum
    {
    GATT_WRITE_REQUEST_STATE_IDLE,
    GATT_WRITE_REQUEST_STATE_WAIT_FOR_RESPONSE
    } gatt_write_request_state_struct;

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
/* BLE service client UUID in little endian */
static const char BLE_CLIENT_UUID_TABLE[BLE_CLIENT_TOTAL][UUID_128BIT_LEN] =
    {
    {0xDC, 0xF8, 0x55, 0xAD, 0x02, 0xC5, 0xF4, 0x8E, 0x3A, 0x43, 0x36, 0x0F, 0x2B, 0x50, 0xD3, 0x89}, // AMS
    {0xD0, 0x00, 0x2D, 0x12, 0x1E, 0x4B, 0x0F, 0xA4, 0x99, 0x4E, 0xCE, 0xB5, 0x31, 0xF4, 0x05, 0x79}  // ANCS
    };

ble_client_struct                ble_clients[BLE_CLIENT_TOTAL];
ble_server_struct                ble_servers[BLE_SERVER_TOTAL];
static uint16_t                  ble_connection_handle = 0;
static bool                      is_ble_connected = false;
gatt_write_request_state_struct  gatt_write_request_state = GATT_WRITE_REQUEST_STATE_IDLE;
static QueueHandle_t             gatt_write_quest_queue_handle;

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
/*********************************************************************
*
* @private
* find_ble_client_having_handle
*
* Lookup the index of the BLE service clients.
*
* @param handle The BLE service client handle.
* @return The client index of the BLE client in ble_clients
*
*********************************************************************/
static int find_ble_client_having_handle
    (
    const uint16_t handle
    )
{
int client_idx = -1;
for( int i = 0; i < BLE_CLIENT_TOTAL; i++ )
    {
    if( handle >= ble_clients[i].start_handle &&
        handle <= ble_clients[i].end_handle )
        {
        client_idx = i;
        break;
        }
    }
return client_idx;
}

/*********************************************************************
*
* @private
* clear_status
*
* Clear BLE connection status
*
*********************************************************************/
static int clear_status
    (
    void
    )
{
BLE_PRINTF( "%s\r\n", __FUNCTION__ );

// clear characteristic handles
ble_connection_handle = 0;
for( int i = 0; i < BLE_CLIENT_TOTAL; i++ )
    {
    ble_clients[i].start_handle  = 0;
    ble_clients[i].end_handle    = 0;
    ble_clients[i].is_discovered = false;
    }

// clear write request queue
xQueueReset( gatt_write_quest_queue_handle );

// clear write request state
gatt_write_request_state = GATT_WRITE_REQUEST_STATE_IDLE;

return ERR_NONE;
}

/*********************************************************************
*
* @private
* notify_ble_connected
*
* Notify the registered BLE application that BLE is connected
*
*********************************************************************/
static void notify_ble_connected
    (
    void
    )
{
for( int i = 0; i < BLE_CLIENT_TOTAL; i++ )
    {
    if( NULL != ble_clients[i].callback &&
        NULL != ble_clients[i].callback->ble_connected_callback )
        {
        ble_clients[i].callback->ble_connected_callback();
        }
    }

if( NULL != ble_servers[0].callback &&
    NULL != ble_servers[0].callback->ble_connected_callback )
    {
    ble_servers[0].callback->ble_connected_callback();
    }
}

/*********************************************************************
*
* @private
* notify_ble_disconnected
*
* Notify the registered BLE application that BLE is disconnected
*
*********************************************************************/
static void notify_ble_disconnected
    (
    void
    )
{
for( int i = 0; i < BLE_CLIENT_TOTAL; i++ )
    {
    if( NULL != ble_clients[i].callback &&
        NULL != ble_clients[i].callback->ble_disconnected_callback )
        {
        ble_clients[i].callback->ble_disconnected_callback();
        }
    }

if( NULL != ble_servers[0].callback &&
    NULL != ble_servers[0].callback->ble_disconnected_callback )
    {
    ble_servers[0].callback->ble_disconnected_callback();
    }
}

/*********************************************************************
*
* @public
* HCI_le_disconnect_ble
*
* If the BLE authentication error or encounter other errors, BLE disconnect
*
*********************************************************************/
void HCI_le_disconnect_ble
    (
    void
    )
{
uint8_t ble_conn_handle_arry[2] = { 0 };
ble_conn_handle_arry[0] = (uint8_t)ble_connection_handle;
ble_conn_handle_arry[1] = (uint8_t)( ble_connection_handle >> 8 );
HCI_wiced_send_command( HCI_CONTROL_LE_COMMAND_DISCONNECT, ble_conn_handle_arry, sizeof( ble_conn_handle_arry ) );
hci_set_wait_command_status( true );  // Wait for command status
HCI_wait_for_resp_start( RESPONSE_CHECK_COMMAND_STATUS );
}

/*********************************************************************
*
* @private
* hci_le_event_received
*
* Process the HCI LE event data
*
* @param opcode HCI operation code
* @param data The pointer to the data byte array
* @param length The length of the data byte array
* @return The result of success/error.
*
*********************************************************************/
int hci_le_event_received
    (
    const uint16_t opcode,
    const uint8_t* data,
    const uint16_t length
    )
{
uint16_t discon_connection_handle = 0;
uint8_t  discon_reason = 0;

switch( opcode )
    {
    case HCI_CONTROL_LE_EVENT_CONNECTED:
        is_ble_connected = true;
        ble_connection_handle = WORD_LITTLE( data[BT_DEVICE_ADDRESS_LEN + 1], data[BT_DEVICE_ADDRESS_LEN + 2] );
        BLE_PRINTF( "LE_EVENT_CONNECTED, conn handle: 0x%04x\r\n", ble_connection_handle );
        notify_ble_connected();
        break;

    case HCI_CONTROL_LE_EVENT_DISCONNECTED:
        discon_connection_handle = WORD_LITTLE( data[0], data[1] );
        discon_reason = data[2];
        BLE_PRINTF( "LE_EVENT_DISCONNECTED: conn handle:%04x discon reason:%d\r\n", discon_connection_handle, discon_reason );
        if( discon_connection_handle == ble_connection_handle )
            {
            ble_connection_handle = 0;
            }
        else
            {
            BLE_PRINTF( "ERROR return disconnection handle:0x%04x connection handle:%04x\r\n", discon_connection_handle, ble_connection_handle );
            }
        is_ble_connected = false;
        clear_status();
        notify_ble_disconnected();
        break;

    case HCI_CONTROL_LE_EVENT_ADVERTISEMENT_STATE:
        BTM_receive_ble_advertising_state( (const uint8_t)data[0] );
        break;

    default:
        BLE_PRINTF( "other le opcode 0x%x\r\n", opcode );
        break;
    }
return ERR_NONE;
}

/*********************************************************************
*
* @private
* hci_gatt_event_received
*
* Process the HCI GATT event data
*
* @param opcode HCI operation code
* @param data The pointer to the data byte array
* @param length The length of the data byte array
* @return The result of success/error.
*
*********************************************************************/
int hci_gatt_event_received
    (
    const uint16_t opcode,
    const uint8_t* data,
    const uint16_t length
    )
{
uint16_t connection_id = 0;
uint16_t handle = 0; // attribute handle
int service_idx = 0;
const char device_name_data[8] = { 'L', 'I', 'N', 'K', 'C', 'A', 'R', 'D' };

switch( opcode )
    {
    case HCI_CONTROL_GATT_EVENT_COMMAND_STATUS:
        hci_gatt_receive_command_status( data[0] );
        #if BLE_READ_WRITE_DEBUG_ENABLE
            BLE_PRINTF( "GATT_EVENT_COMMAND_STATUS: %d\r\n", data[0] );
        #endif
        break;

    case HCI_CONTROL_GATT_EVENT_DISCOVERY_COMPLETE:
        BLE_PRINTF( "GATT_EVENT_DISCOVERY_COMPLETE\r\n" );
        for( int i = 0; i < BLE_CLIENT_TOTAL; i++ )
            {
            if( ble_clients[i].is_discovered )
                {
                if( NULL != ble_clients[i].callback &&
                    NULL != ble_clients[i].callback->discovery_complete_callback )
                    {
                    ble_clients[i].callback->discovery_complete_callback();
                    }
                }
            }
        break;

    case HCI_CONTROL_GATT_EVENT_SERVICE_DISCOVERED:
        BLE_PRINTF( "GATT_EVENT_SERVICE_DISCOVERED, conn handle: %x\r\n", WORD_LITTLE( data[0], data[1] ) );
        BLE_PRINTF( "UUID: %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x\r\n",
                data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9],
                data[10], data[11], data[12], data[13], data[14], data[15], data[16], data[17] );
        BLE_PRINTF( "start handle: 0x%x, end handle: 0x%x\r\n",
                WORD_LITTLE( data[18], data[19] ), WORD_LITTLE( data[20], data[21] ) );

        for( service_idx = 0; service_idx < BLE_CLIENT_TOTAL; service_idx++ )
            {
            if( 0 == memcmp( &data[2], BLE_CLIENT_UUID_TABLE[service_idx], UUID_128BIT_LEN ) )
                {
                ble_clients[service_idx].is_discovered = true;
                ble_clients[service_idx].start_handle  = WORD_LITTLE( data[18], data[19] );
                ble_clients[service_idx].end_handle    = WORD_LITTLE( data[20], data[21] );
                if( NULL != ble_clients[service_idx].callback &&
                    NULL != ble_clients[service_idx].callback->service_discovered_callback )
                    {
                    ble_clients[service_idx].callback->service_discovered_callback(
                            WORD_LITTLE( data[18], data[19] ),
                            WORD_LITTLE( data[20], data[21] ) );
                    }
                }
            }
        break;

    case HCI_CONTROL_GATT_EVENT_CHARACTERISTIC_DISCOVERED:
        BLE_PRINTF( "GATT_EVENT_CHARACTERISTIC_DISCOVERED, conn handle: %x\r\n", WORD_LITTLE( data[0], data[1] ) );
        BLE_PRINTF( "characteristic handle: 0x%x %x\r\n", data[2], data[3] );
        BLE_PRINTF( "UUID: %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x\r\n",
                data[4], data[5], data[6], data[7], data[8], data[9], data[10], data[11],
                data[12], data[13], data[14], data[15], data[16], data[17], data[18], data[19] );
        BLE_PRINTF( "characteristic property: 0x%x\r\n", data[20] );
        BLE_PRINTF( "value handle: 0x%x %x\r\n", data[21], data[22] );

        handle = WORD_LITTLE( data[21], data[22] );
        service_idx = find_ble_client_having_handle( handle );
        if( service_idx >= 0 )
            {
            if( NULL != ble_clients[service_idx].callback &&
                NULL != ble_clients[service_idx].callback->characteristic_discovered_callback )
                {
                ble_clients[service_idx].callback->characteristic_discovered_callback( &data[4], handle );
                }
            }
        else
            {
            PRINTF( "err: not found service containing handle 0x%x\r\n", handle );
            }
        break;

    case HCI_CONTROL_GATT_EVENT_DESCRIPTOR_DISCOVERED:
        BLE_PRINTF( "GATT_EVENT_DESCRIPTOR_DISCOVERED, conn handle: 0x%x\r\n", WORD_LITTLE( data[0], data[1] ) );
        BLE_PRINTF( "descriptor UUID: %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x\r\n",
                data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9],
                data[10], data[11], data[12], data[13], data[14], data[15], data[16], data[17] );
        BLE_PRINTF( "descriptor handle: 0x%x %x\r\n", data[18], data[19] );

        handle = WORD_LITTLE( data[18], data[19] );
        service_idx = find_ble_client_having_handle( handle );
        if( service_idx >= 0 )
            {
            if( NULL != ble_clients[service_idx].callback &&
                NULL != ble_clients[service_idx].callback->descriptor_discovered_callback )
                {
                ble_clients[service_idx].callback->descriptor_discovered_callback( handle );
                }
            }
        else
            {
            PRINTF( "err: not found service containing handle 0x%x\r\n", handle );
            }
        break;

    case HCI_CONTROL_GATT_EVENT_READ_REQUEST:
        connection_id = WORD_LITTLE( data[0], data[1] );
        handle = WORD_LITTLE( data[2], data[3] );
        #if BLE_READ_WRITE_DEBUG_ENABLE
            BLE_PRINTF( "GATT EVENT_READ_REQUEST, conn:%x, attr handle:%x\r\n", connection_id, handle );
        #endif
        if( handle >= ble_servers[0].start_handle &&
            handle <= ble_servers[0].end_handle )
            {
            if( handle == HDLC_GAP_DEVICE_NAME_VALUE )
                {
                HCI_le_send_gatt_server_data( HCI_CONTROL_GATT_COMMAND_READ_RESPONSE, HDLC_GAP_DEVICE_NAME_VALUE, (uint8_t *)device_name_data, 8 );
                }
            else if( NULL != ble_servers[0].callback &&
                NULL != ble_servers[0].callback->read_request_received_callback )
                {
                ble_servers[0].callback->read_request_received_callback( handle );
                break;
                }
            }
        else
            {
            BLE_PRINTF( "ERROR:Can't find Attribute handle\r\n");
            }
        break;
        break;

    case HCI_CONTROL_GATT_EVENT_READ_RESPONSE:
        BLE_PRINTF( "GATT_EVENT_READ_RESPONSE\r\n");
        break;

    case HCI_CONTROL_GATT_EVENT_WRITE_REQUEST:
        connection_id = WORD_LITTLE( data[0], data[1] );
        handle = WORD_LITTLE( data[2], data[3] );
        #if BLE_READ_WRITE_DEBUG_ENABLE
            BLE_PRINTF( "GATT EVENT_WRITE_REQUEST, conn:%x, attr handle:%x, len: %d\r\n", connection_id, handle, length );
        #endif
        if( handle >= ble_servers[0].start_handle &&
            handle <= ble_servers[0].end_handle )
            {
            // TODO connection ID judgement
            // Since we can not identify the LE connection as AMS/ANCS or Motocon, here we judge the connection ID
            // When the APP open CCCD
            if( ( HDLD_MOTOCONSDK_NOTIFY_CLIENT_CHAR_CONFIG == handle ) && ( 1 == data[CCCD_DATA_FIRST_BYTE_NUM] ) )
                {
                ble_servers[0].connection_id = connection_id;
                BLE_PRINTF( "Connection ID update:%d\r\n", connection_id );
                }

            if( NULL != ble_servers[0].callback &&
                NULL != ble_servers[0].callback->write_request_received_callback )
                {
                ble_servers[0].callback->write_request_received_callback( handle, &data[WRITE_REQUEST_HEADER_NUM], length - WRITE_REQUEST_HEADER_NUM );
                break;
                }
            }
        else
            {
            BLE_PRINTF( "ERROR:Can't find Attribute handle\r\n");
            }
        break;

    case HCI_CONTROL_GATT_EVENT_WRITE_RESPONSE:
        #if BLE_READ_WRITE_DEBUG_ENABLE
            BLE_PRINTF( "GATT_EVENT_WRITE_RESPONSE, conn handle: 0x%x, result: 0x%x\r\n", WORD_LITTLE( data[0], data[1] ), data[2] );
        #endif
        gatt_write_request_state = GATT_WRITE_REQUEST_STATE_IDLE;
        if( GATT_WRITE_REQUEST_QUEUE_LENGTH > uxQueueSpacesAvailable( gatt_write_quest_queue_handle ) )
            {
            hci_notify_gatt_write_request_queued();
            }
        break;

    case HCI_CONTROL_GATT_EVENT_INDICATION:
        BLE_PRINTF( "GATT_EVENT_INDICATION\r\n" );
        break;

    case HCI_CONTROL_GATT_EVENT_NOTIFICATION:
        handle = WORD_LITTLE( data[2], data[3] );
        #if BLE_NOTIFY_DEBUG_ENABLE
            BLE_PRINTF( "GATT_EVENT_NOTIFICATION, conn: 0x%x, handle: 0x%x, len: %d\r\n", WORD_LITTLE( data[0], data[1] ), handle, length );
        #endif
        for( service_idx = 0; service_idx < BLE_CLIENT_TOTAL; service_idx++ )
            {
            if( handle >= ble_clients[service_idx].start_handle &&
                handle <= ble_clients[service_idx].end_handle )
                {
                ble_clients[service_idx].callback->notification_received_callback( handle, &data[4], length - 4 );
                break;
                }
            }
        break;

    case HCI_CONTROL_GATT_EVENT_READ_ERROR:
        BLE_PRINTF( "GATT_EVENT_READ_ERROR\r\n");
        break;

    case HCI_CONTROL_GATT_EVENT_WRITE_ERROR:
        BLE_PRINTF( "GATT_EVENT_WRITE_ERROR\r\n");
        break;

    default:
        BLE_PRINTF( "invalid gatt opcode %x\r\n", opcode );
        break;
    }
return ERR_NONE;
}

/*********************************************************************
*
* @private
* send_gatt_write_request
*
* Send BLE GATT write request
*
* @param handle The service client handle
* @param data The pointer to the data buffer
* @param length Length of the data to write
* @return The result of success/error.
*
*********************************************************************/
static int send_gatt_write_request
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint16_t length
    )
{
int result = ERR_NONE;
uint8_t send_data[GATT_WRITE_REQUEST_HEADER_LENGTH + BLE_GATT_WRITE_REQUEST_DATA_MAX_LEN];
#if BLE_READ_WRITE_DEBUG_ENABLE
    BLE_PRINTF( "%s handle: 0x%x, len: %d\r\n", __FUNCTION__, handle, length );
#endif
if( BLE_GATT_WRITE_REQUEST_DATA_MAX_LEN >= length )
    {
    send_data[0] = ble_connection_handle & 0xff;
    send_data[1] = ( ble_connection_handle >> 8 ) & 0xff;
    send_data[2] = handle & 0xff;
    send_data[3] = ( handle >> 8 )& 0xff;
    memcpy( &send_data[GATT_WRITE_REQUEST_HEADER_LENGTH], data, length );

    if( pdFALSE == HCI_wiced_send_command( HCI_CONTROL_GATT_COMMAND_WRITE_REQUEST, send_data, GATT_WRITE_REQUEST_HEADER_LENGTH + length ) )
        {
        result = ERR_BLE_WRITE;
        }
    }
else
    {
    result = ERR_BLE_WRITE;
    }
return result;
}

/*********************************************************************
*
* @private
* HCI_le_send_gatt_server_data
*
* Send BLE GATT SERVER read response or notification data
*
* @param opcode HCI opcode
* @param handle The service server handle
* @param data The pointer to the data buffer
* @param length The length of the data to send
* @return The result of success/error.
*
*********************************************************************/
int HCI_le_send_gatt_server_data
    (
    const uint16_t opcode,
    const uint16_t handle,
    const uint8_t* data,
    const uint16_t length
    )
{
int result = ERR_NONE;
uint8_t send_data[4 + length];
#if BLE_READ_WRITE_DEBUG_ENABLE
    BLE_PRINTF( "%s handle: %x, len: %d\r\n", __FUNCTION__, handle, length );
#endif
if( ( HCI_CONTROL_GATT_COMMAND_READ_RESPONSE != opcode ) && ( HCI_CONTROL_GATT_COMMAND_NOTIFY != opcode ) )
    {
    BLE_PRINTF( "ERROR opcode 0x%x\r\n", opcode );
    return ERR_BLE_API;
    }

send_data[0] = ble_servers[0].connection_id & 0xff;
send_data[1] = ( ble_servers[0].connection_id >> 8 ) & 0xff;
send_data[2] = handle & 0xff;
send_data[3] = ( handle >> 8 )& 0xff;
memcpy( &send_data[4], data, length );

if( pdFALSE == HCI_wiced_send_command( opcode, send_data, 4 + length ) )
    {
    result = ERR_BLE_WRITE;
    }
return result;
}

/*********************************************************************
*
* @private
* hci_le_proc_gatt_write_request
*
* Get the GATT write request from queue and
* call send_gatt_write_request() to send to the peer device.
*
*********************************************************************/
void hci_le_proc_gatt_write_request
    (
    void
    )
{
ble_gatt_write_request_struct gatt_write_request;

if( GATT_WRITE_REQUEST_STATE_IDLE == gatt_write_request_state )
    {
    if( pdTRUE == xQueueReceive( gatt_write_quest_queue_handle, &gatt_write_request, 0 ) )
        {
        gatt_write_request_state = GATT_WRITE_REQUEST_STATE_WAIT_FOR_RESPONSE;
        send_gatt_write_request( gatt_write_request.handle, gatt_write_request.data, gatt_write_request.data_len );
        }
    else
        {
        PRINTF( "%s false\r\n", __FUNCTION__ );
        }
    }
}

/*********************************************************************
*
* @public
* HCI_le_enqueue_gatt_write_request
*
* Enqueue the BLE GATT write request
*
* @param handle The service client handle
* @param data The pointer to the data buffer
* @param length Length of the data to write
* @return The result of success/error.
*
*********************************************************************/
int HCI_le_enqueue_gatt_write_request
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint16_t length
    )
{
int result = ERR_NONE;

if( length <= BLE_GATT_WRITE_REQUEST_DATA_MAX_LEN )
    {
    ble_gatt_write_request_struct gatt_write_request;
    gatt_write_request.handle   = handle;
    gatt_write_request.data_len = length;
    memcpy( gatt_write_request.data, data, length );

    if( pdTRUE == xQueueSend( gatt_write_quest_queue_handle, &gatt_write_request, 0 ) )
        {
        hci_notify_gatt_write_request_queued();
        }
    else
        {
        result = ERR_BUF_OVERFLOW;
        PRINTF( "Err: %s queue full\r\n", __FUNCTION__ );
        }
    }
else
    {
    result = ERR_BUF_OPERATION;
    PRINTF( "Err: %s data too long\r\n", __FUNCTION__ );
    }

return result;
}

/*********************************************************************
*
* @public
* HCI_le_register_client_callback
*
* Register the callback function of the BLE GATT service client
*
* @param client_type The BLE GATT client of ble_client_type
* @param callback The pointer of the callback struct of ble_client_callback
* @return The result of success/error.
*
*********************************************************************/
int HCI_le_register_client_callback
    (
    const ble_client_type      client_type,
    const ble_client_callback* callback
    )
{
ble_clients[client_type].callback = callback;
return ERR_NONE;
}

/*********************************************************************
*
* @public
* HCI_le_register_server_callback
*
* Register the callback function of the BLE GATT SERVER service
*
* @param service_type The BLE GATT SERVER service of ble_service_type
* @param callback The pointer of the callback struct of ble_service_callback
*
*********************************************************************/
int HCI_le_register_server_callback
    (
    ble_server_type service_type,
    ble_server_callback* callback
    )
{
ble_servers[service_type].callback = callback;
return ERR_NONE;
}

/*********************************************************************
*
* @public
* HCI_le_is_connected
*
* Get the BLE connection status
*
* @return The state of BLE connection.
* @retval True if BLE is connected.
* @retval False if BLE is not connected.
*
*********************************************************************/
bool HCI_le_is_connected
    (
    void
    )
{
return is_ble_connected;
}

/*********************************************************************
*
* @private
* hci_init_server_service
*
* Initialize all Server Service variable
*
*********************************************************************/
void hci_init_server_service
    (
    void
    )
{
ble_servers[0].start_handle = HDLS_GAP;
ble_servers[0].end_handle = HDLD_MOTOCONSDK_DDT_CAN_DATA_CLIENT_CHAR_CONFIG;
}

/*********************************************************************
*
* @private
* hci_le_init
*
* Init HCI LE group and GATT group
*
*********************************************************************/
void hci_le_init
    (
    void
    )
{
gatt_write_quest_queue_handle = xQueueCreate( GATT_WRITE_REQUEST_QUEUE_LENGTH, sizeof( ble_gatt_write_request_struct ) );
configASSERT( NULL != gatt_write_quest_queue_handle );

hci_init_server_service();
}
