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
#include <task.h>
#include <string.h>

#include "GRM_pub_prj.h"

#include "bt_db.h"
#include "bt_device.h"
#include "bt_log.h"
#include "bt_tsk.h"
#include "bt_utils.h"
#include "hci_tsk.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define BT_TSK_NAME       ( "bt_task" )
#define BT_TSK_PRIORITY   ( TASK_PRIO_BT_MNGR )
#define BT_TSK_STACK_SIZE ( configMINIMAL_STACK_SIZE * 15 )

#define REQUEST_QUEUE_MAX_ITEMS    ( 10 )
#define SYNC_EVENT_QUEUE_MAX_ITEMS ( 1 )

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

// Init HCI task
HCI_tsk_init();

// Init Main task
s_request_queue = xQueueCreate( REQUEST_QUEUE_MAX_ITEMS, sizeof( BT_request_t ) );
configASSERT( NULL != s_request_queue );

s_sync_event_queue = xQueueCreate( SYNC_EVENT_QUEUE_MAX_ITEMS, sizeof( BT_sync_event_t ) );
configASSERT( NULL != s_sync_event_queue );

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
BT_request_t request = { BT_REQUEST_TYPE_INVALID, { { 0 } } };

BT_LOG_INFO( "BT task started" );
BT_LOG_INFO( "Local device name: %s", local_device_name );
BT_LOG_INFO( "Local device address: %02x:%02x:%02x:%02x:%02x:%02x", BD_ADDR_PRINT( local_bd_addr ) );
BT_LOG_INFO( "Enable state: %d", enable_state );

while( 1 )
    {
    if( pdTRUE == xQueueReceive( s_request_queue, &request, portMAX_DELAY ) )
        {
        BT_LOG_VERBOSE( "Request received: %d", request.type );
        // TODO: Handle request in Core functions
        switch( request.type )
            {
            case BT_REQUEST_ACCEPT_PAIRING:
                {
                } break;
            case BT_REQUEST_DELETE_PAIRED_DEVICE:
                {
                } break;
            case BT_REQUEST_FACTORY_RESET:
                {
                } break;
            case BT_REQUEST_INIT_MODULE:
                {
                } break;
            case BT_REQUEST_SEND_STANDARD_HCI_COMMAND:
                {
                } break;
            case BT_REQUEST_SET_DISCOVERABLE_STATE:
                {
                } break;
            case BT_REQUEST_SET_ENABLE_STATE:
                {
                } break;
            case BT_REQUEST_SET_LOCAL_DEVICE_ADDRESS:
                {
                } break;
            case BT_REQUEST_SET_TEST_MODE:
                {
                } break;
            case BT_REQUEST_SET_TX_CARRIER_MODE:
                {
                } break;
            case BT_REQUEST_UPDATE_FIRMWARE:
                {
                } break;
            case BT_REQUEST_SPP_CONNECT:
                {
                } break;
            case BT_REQUEST_SPP_DISCONNECT:
                {
                } break;
            case BT_REQUEST_SPP_SEND_DATA:
                {
                } break;
            case BT_REQUEST_LE_GATT_NOTIFY:
                {
                } break;
            case BT_REQUEST_LE_GATT_READ_RESPONSE:
                {
                } break;
            case BT_REQUEST_LE_GATT_WRITE_REQUEST:
                {
                } break;
            case BT_REQUEST_LE_SET_ADVERTISEMENT_STATE:
                {
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

if( pdTRUE != xQueueSend( s_request_queue, request, 0 ) )
    {
    BT_LOG_ERROR( "Request sent failed due to Queue Full: %d", request->type );
    return false;
    }

BT_LOG_VERBOSE( "Request sent: %d", request->type );
return true;
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
        BT_LOG_ERROR( "Timed out on waiting sync event: %d", sync_event->type );
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
