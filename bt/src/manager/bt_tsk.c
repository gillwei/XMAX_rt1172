/*********************************************************************
* @file  bt_tsk.c
* @brief Bluetooth Manager Main Task interface definition.
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
#include <queue.h>
#include <semphr.h>
#include <task.h>
#include <string.h>

#include "GRM_pub_prj.h"

#include "bt_core.h"
#include "bt_db.h"
#include "bt_device.h"
#include "bt_log.h"
#include "bt_spp_core.h"
#include "bt_tsk.h"
#include "bt_utils.h"
#include "ble_client_core.h"
#include "ble_server_core.h"
#include "hci_tsk.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define BT_TSK_NAME       ( "bt_task" )
#define BT_TSK_PRIORITY   ( TASK_PRIO_BT_MNGR )
#define BT_TSK_STACK_SIZE ( configMINIMAL_STACK_SIZE * 5 )

#define REQUEST_QUEUE_MAX_ITEMS    ( 10 )
#define SYNC_EVENT_QUEUE_MAX_ITEMS ( 1 )

#define GATT_SEND_COMPLETED_MS ( 3000 )

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
static QueueHandle_t s_request_queue = NULL;
static QueueHandle_t s_sync_event_queue = NULL;
static SemaphoreHandle_t s_gatt_binary_semaphore = NULL;

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/
static void BT_tsk_main
    (
    void* data
    );

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Clear all the requests of Bluetooth Manager Main task
@details Clear all the requests of Bluetooth Manager Main task
@return  None
@retval  None
================================================================================================*/
void BT_tsk_clear_requests( void )
{
BT_LOG_DEBUG( "Clear all requests" );
xQueueReset( s_request_queue );
}

/*================================================================================================
@brief   Bluetooth Manager Main task initialization
@details Bluetooth Manager Main task initialization
@return  None
@retval  None
================================================================================================*/
void BT_tsk_init( void )
{
// Init base modules
BT_db_init();
BT_device_init();
BT_core_init();
BT_core_spp_init();
BLE_core_server_init();
BLE_core_client_init();

// Init HCI task
HCI_tsk_init();

// Init Main task
s_request_queue = xQueueCreate( REQUEST_QUEUE_MAX_ITEMS, sizeof( BT_request_t ) );
configASSERT( NULL != s_request_queue );

s_sync_event_queue = xQueueCreate( SYNC_EVENT_QUEUE_MAX_ITEMS, sizeof( BT_sync_event_t ) );
configASSERT( NULL != s_sync_event_queue );

// The binary semaphore created using vSemaphoreCreateBinary is created in Given state
vSemaphoreCreateBinary( s_gatt_binary_semaphore );
configASSERT( NULL != s_gatt_binary_semaphore );

BaseType_t ret = xTaskCreate( BT_tsk_main, BT_TSK_NAME, BT_TSK_STACK_SIZE, NULL, BT_TSK_PRIORITY, NULL );
configASSERT( pdPASS == ret );
}

/*================================================================================================
@brief   Bluetooth Manager Main task execution loop
@details Bluetooth Manager Main task will wait on the request queue and be waked up to handle the
         received request.
@return  None
@retval  None
================================================================================================*/
static void BT_tsk_main
    (
    void* data
    )
{
const uint8_t* local_device_name = BT_db_get_local_device_name();
const uint8_t* local_bd_addr = BT_db_get_local_device_address();
bool enable_state = BT_db_get_enable_state();
uint8_t sw_major_version = 0;
uint8_t sw_minor_version = 0;
BT_request_t request = { BT_REQUEST_TYPE_INVALID, { { 0 } } };

BT_core_get_sw_version( &sw_major_version, &sw_minor_version );
BT_LOG_INFO( "BT task started" );
BT_LOG_INFO( "Local device name: %s", local_device_name );
BT_LOG_INFO( "Local device address: %02x:%02x:%02x:%02x:%02x:%02x", BD_ADDR_PRINT( local_bd_addr ) );
BT_LOG_INFO( "SW version: %u.%02u", sw_major_version, sw_minor_version );
BT_LOG_INFO( "Enable state: %d", enable_state );

vTaskDelay( pdMS_TO_TICKS( BT_HW_POWER_SEQUENCE_MS ) );
BT_core_set_enable_state( false, false );
if( enable_state )
    {
    BT_core_set_enable_state( true, false );
    }

while( 1 )
    {
    if( pdTRUE == xQueueReceive( s_request_queue, &request, portMAX_DELAY ) )
        {
        BT_LOG_VERBOSE( "Request received: %d", request.type );
        switch( request.type )
            {
            case BT_REQUEST_ACCEPT_PAIRING:
                {
                BT_core_accept_pairing( request.param_u.accept_pairing.accept );
                } break;
            case BT_REQUEST_DELETE_PAIRED_DEVICE:
                {
                BT_core_delete_paired_device( request.param_u.delete_paired_device.bd_addr );
                } break;
            case BT_REQUEST_FACTORY_RESET:
                {
                BT_core_factory_reset();
                } break;
            case BT_REQUEST_INIT_MODULE:
                {
                BT_core_init_module();
                } break;
            case BT_REQUEST_SEND_STANDARD_HCI_COMMAND:
                {
                BT_core_send_standard_hci_command( request.param_u.send_standard_hci_command.op_code,
                                                   request.param_u.send_standard_hci_command.payload,
                                                   request.param_u.send_standard_hci_command.payload_len );
                } break;
            case BT_REQUEST_SET_DISCOVERABLE_STATE:
                {
                BT_core_set_discoverable_state( request.param_u.set_discoverable_state.enable );
                } break;
            case BT_REQUEST_SET_ENABLE_STATE:
                {
                BT_core_set_enable_state( request.param_u.set_enable_state.enable, true );
                } break;
            case BT_REQUEST_SET_LOCAL_DEVICE_ADDRESS:
                {
                BT_core_set_local_device_address( request.param_u.set_local_device_address.bd_addr );
                } break;
            case BT_REQUEST_SET_TEST_MODE:
                {
                BT_core_set_test_mode( request.param_u.set_test_mode.enable );
                } break;
            case BT_REQUEST_SET_TX_CARRIER_MODE:
                {
                BT_core_set_tx_carrier_mode( request.param_u.set_tx_carrier_mode.enable,
                                             request.param_u.set_tx_carrier_mode.channel_type );
                } break;
            case BT_REQUEST_UPDATE_FIRMWARE:
                {
                BT_core_update_firmware();
                } break;
            // SPP
            case BT_REQUEST_SPP_CONNECT:
                {
                BT_core_spp_connect( request.param_u.spp_connect.bd_addr, request.param_u.spp_connect.app_type );
                } break;
            case BT_REQUEST_SPP_DISCONNECT:
                {
                BT_core_spp_disconnect( request.param_u.spp_disconnect.bd_addr, request.param_u.spp_disconnect.app_type );
                } break;
            case BT_REQUEST_SPP_SEND_DATA:
                {
                BT_core_spp_send_data( request.param_u.spp_send_data.bd_addr,
                                       request.param_u.spp_send_data.app_type,
                                       request.param_u.spp_send_data.data,
                                       request.param_u.spp_send_data.data_len );
                } break;
            // LE Client
            case BT_REQUEST_LE_CLIENT_WRITE_REQUEST:
                {
                BLE_core_client_write_request( request.param_u.le_client_write_request.handle,
                                               request.param_u.le_client_write_request.data,
                                               request.param_u.le_client_write_request.data_len );
                } break;
            // LE Server
            case BT_REQUEST_LE_SERVER_DISCONNECT:
                {
                BLE_core_server_disconnect();
                } break;
            case BT_REQUEST_LE_SERVER_NOTIFY:
                {
                BLE_core_server_notify( request.param_u.le_server_notify.handle,
                                        request.param_u.le_server_notify.data,
                                        request.param_u.le_server_notify.data_len );
                } break;
            case BT_REQUEST_LE_SERVER_READ_RESPONSE:
                {
                BLE_core_server_read_response( request.param_u.le_server_read_response.handle,
                                               request.param_u.le_server_read_response.data,
                                               request.param_u.le_server_read_response.data_len );
                } break;
            case BT_REQUEST_LE_SERVER_SET_ADVERTISING_MODE:
                {
                BLE_core_server_set_advertising_mode( request.param_u.le_server_set_advertising_mode.advertising_mode,
                                                      request.param_u.le_server_set_advertising_mode.data_type,
                                                      request.param_u.le_server_set_advertising_mode.data,
                                                      request.param_u.le_server_set_advertising_mode.data_len );
                } break;
            default:
                {
                BT_LOG_ERROR( "Invalid request type: %d", request.type );
                } break;
            }
        }
    }
}

/*================================================================================================
@brief   Send the request to Bluetooth Manager Main task
@details Send the request to Bluetooth Manager Main task
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_tsk_send_request
    (
    const BT_request_t* request
    )
{
if( NULL == request )
    {
    BT_LOG_ERROR( "NULL request" );
    return false;
    }

if( pdTRUE != xQueueSend( s_request_queue, request, portMAX_DELAY ) )
    {
    BT_LOG_ERROR( "Request sent failed due to Queue Full: %d", request->type );
    return false;
    }

BT_LOG_VERBOSE( "Request sent: %d", request->type );
return true;
}

/*================================================================================================
@brief   The function is used by Bluetooth Manager HCI task to inform the last GATT send completed
@details When the GATT write response received Bluetooth Manager HCI task uses this function to
         inform the last GATT send is completed
@return  None
@retval  None
================================================================================================*/
void BT_tsk_sync_gatt_send_signal( void )
{
xSemaphoreGive( s_gatt_binary_semaphore );
}

/*================================================================================================
@brief   The function is used by Bluetooth Manager Main task to wait for the last GATT send completed
@details According to Wiced HCI protocol after issuing a GATT write/write request/notify/indicate,
         we are not able to issue a new one until the GATT write response event is received as the
         last GATT send is completed. Hence this function is for Bluetooth Manager Main task to
         check and wait for the last GATT send completed then continue issuing the new GATT send
@return  None
@retval  Whether or not the last GATT send completed in the expected time period
================================================================================================*/
bool BT_tsk_sync_gatt_send_wait( void )
{
BaseType_t ret = xSemaphoreTake( s_gatt_binary_semaphore, pdMS_TO_TICKS( GATT_SEND_COMPLETED_MS ) );
if( pdTRUE == ret )
    {
    BT_LOG_VERBOSE( "GATT send is OK to issue" );
    }
else
    {
    BT_LOG_ERROR( "Timeout on waiting last GATT send completed" );
    }
return ( pdTRUE == ret );
}

/*================================================================================================
@brief   The function is used by Bluetooth Manager HCI task to inform the sync event happened
@details The function is used by Bluetooth Manager HCI task to inform the sync event happened
@return  None
@retval  None
================================================================================================*/
void BT_tsk_sync_signal
    (
    const BT_sync_event_t* sync_event
    )
{
if( NULL == sync_event )
    {
    BT_LOG_ERROR( "NULL sync event" );
    return;
    }

xQueueReset( s_sync_event_queue );

if( pdTRUE != xQueueSend( s_sync_event_queue, sync_event, 0 ) )
    {
    BT_LOG_ERROR( "Sync event sent failed due to Queue Full: %d", sync_event->type );
    return;
    }

BT_LOG_DEBUG( "Sync event sent: %d", sync_event->type );
}

/*================================================================================================
@brief   The function is used by Bluetooth Manager Main task to wait for the sync event happened
@details The function is used by Bluetooth Manager Main task to wait for the sync event happened
@return  None
@retval  Whether or not the expected sync event received in the expected time period
================================================================================================*/
bool BT_tsk_sync_wait
    (
    BT_sync_event_t* sync_event,
    const uint32_t timeout_ms
    )
{
TickType_t tick_start = xTaskGetTickCount();
TickType_t tick_elapsed = 0;
TickType_t tick_remained = 0;
BT_sync_event_t received_sync_event = { BT_SYNC_EVENT_TYPE_INVALID, { { 0 } } };

while( 1 )
    {
    BT_LOG_DEBUG( "Start waiting for sync event: %d", sync_event->type );
    xQueueReset( s_sync_event_queue );

    tick_elapsed = xTaskGetTickCount() - tick_start;
    if( pdMS_TO_TICKS( timeout_ms ) > tick_elapsed )
        {
        tick_remained = pdMS_TO_TICKS( timeout_ms ) - tick_elapsed;
        }
    else
        {
        tick_remained = 0;
        }

    if( ( 0 == tick_remained ) ||
        ( pdTRUE != xQueueReceive( s_sync_event_queue, &received_sync_event, tick_remained ) ) )
        {
        BT_LOG_ERROR( "Timeout on waiting sync event: %d", sync_event->type );
        return false;
        }

    if( sync_event->type == received_sync_event.type )
        {
        break;
        }
    else
        {
        BT_LOG_DEBUG( "Unexpected sync event received: %d -> %d", sync_event->type, received_sync_event.type );
        }
    }

BT_LOG_DEBUG( "Sync event received: %d", sync_event->type );
if( NULL != sync_event )
    {
    memcpy( &( sync_event->param_u ), &( received_sync_event.param_u ), sizeof( sync_event->param_u ) );
    }
return true;
}

#ifdef __cplusplus
}
#endif
