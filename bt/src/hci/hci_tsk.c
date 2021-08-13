/*********************************************************************
* @file  hci_tsk.c
* @brief Bluetooth Manager HCI Task interface definition.
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

#include "fsl_debug_console.h"
#include "GRM_pub_prj.h"

#include "bt_core.h"
#include "bt_log.h"
#include "bt_utils.h"
#include "hci_control_api_ex.h"
#include "hci_event.h"
#include "hci_le_event.h"
#include "hci_spp_event.h"
#include "hci_tsk.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define HCI_TSK_NAME       ( "hci_task" )
#define HCI_TSK_PRIORITY   ( TASK_PRIO_BT_HCI )
#define HCI_TSK_STACK_SIZE ( configMINIMAL_STACK_SIZE * 5 )

#define HCI_EVENT_QUEUE_MAX_ITEMS ( 10 )

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef struct HCI_event
    {
    uint8_t data[HCI_EVENT_MAX_SIZE];
    uint8_t data_len;
    } HCI_event_t;

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
static QueueHandle_t s_hci_event_queue = NULL;

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/
static void HCI_tsk_main
    (
    void* data
    );

static bool HCI_tsk_parse_event
    (
    const HCI_event_t* hci_event,
    uint8_t* group_code,
    uint8_t* event_code,
    uint8_t* param_pos,
    uint16_t* param_len
    );

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Bluetooth Manager HCI task initialization
@details Bluetooth Manager HCI task initialization
@return  None
@retval  None
================================================================================================*/
void HCI_tsk_init( void )
{
s_hci_event_queue = xQueueCreate( HCI_EVENT_QUEUE_MAX_ITEMS, sizeof( HCI_event_t ) );
configASSERT( NULL != s_hci_event_queue );

BaseType_t ret = xTaskCreate( HCI_tsk_main, HCI_TSK_NAME, HCI_TSK_STACK_SIZE, NULL, HCI_TSK_PRIORITY, NULL );
configASSERT( pdPASS == ret );
}

/*================================================================================================
@brief   Bluetooth Manager HCI task execution loop
@details Bluetooth Manager HCI task will wait on the HCI event queue and be waked up to handle the
         received HCI event.
@return  None
@retval  None
================================================================================================*/
static void HCI_tsk_main
    (
    void* data
    )
{
uint8_t group_code = 0;
uint8_t event_code = 0;
uint8_t param_pos = 0;
uint16_t param_len = 0;
HCI_event_t hci_event = { 0 };

BT_LOG_INFO( "HCI task started" );

while( 1 )
    {
    if( pdTRUE == xQueueReceive( s_hci_event_queue, &hci_event, portMAX_DELAY ) )
        {
        BT_LOG_VERBOSE( "HCI event received: len=%u", hci_event.data_len );

        if( BT_POWER_OFF == BT_core_get_power_status() )
            {
            BT_LOG_DEBUG( "Ignore HCI events when Powered Off" );
            continue;
            }

        if( false == HCI_tsk_parse_event( &hci_event, &group_code, &event_code, &param_pos, &param_len ) )
            {
            continue;
            }

        switch( group_code )
            {
            case HCI_CONTROL_GROUP_DEVICE:
                {
                HCI_handle_device_event( group_code, event_code, &( hci_event.data[param_pos] ), param_len );
                } break;
            case HCI_CONTROL_GROUP_STANDARD_GARMIN:
                {
                HCI_handle_standard_event( group_code, event_code, &( hci_event.data[param_pos] ), param_len );
                } break;
            case HCI_CONTROL_GROUP_SPP:
                {
                HCI_handle_spp_event( group_code, event_code, &( hci_event.data[param_pos] ), param_len );
                } break;
            case HCI_CONTROL_GROUP_IAP2:
                {
                HCI_handle_iap_event( group_code, event_code, &( hci_event.data[param_pos] ), param_len );
                } break;
            case HCI_CONTROL_GROUP_LE:
                {
                HCI_handle_le_event( group_code, event_code, &( hci_event.data[param_pos] ), param_len );
                } break;
            case HCI_CONTROL_GROUP_GATT:
                {
                HCI_handle_gatt_event( group_code, event_code, &( hci_event.data[param_pos] ), param_len );
                } break;
            default:
                {
                BT_LOG_DEBUG( "Unhandled HCI event group code: 0x%02x", group_code );
                } break;
            }
        }
    }
}

/*================================================================================================
@brief   Parse the received HCI event
@details Follow the format below to parse the received HCI event:
           - Wiced HCI event: 1-byte(packet_type) +
                              1-byte(event_code) + 1-byte(group_code) +
                              2-bytes(parameter_len) + n-bytes(parameter)
           - Standard HCI event: 1-byte(packet_type) +
                                 1-byte(event_code) +
                                 1-byte(parameter_len) + n-bytes(parameter)
         Since the standard HCI event has no group code. To process it like a Wiced HCI event we
         manually give it a Garmin defined group code - HCI_CONTROL_GROUP_STANDARD_GARMIN.
@return  group_code: group code of the HCI event
         event_code: event code of the HCI event
         param_pos: the parameter start position in the HCI event
         param_len: length of the HCI event's parameter
@retval  Whether or not the operation is successful
================================================================================================*/
static bool HCI_tsk_parse_event
    (
    const HCI_event_t* hci_event,
    uint8_t* group_code,
    uint8_t* event_code,
    uint8_t* param_pos,
    uint16_t* param_len
    )
{
uint8_t cur_pos = 0;
uint8_t header_len = 0;

if( ( NULL == hci_event  ) || ( NULL == hci_event->data ) || ( 0 == hci_event->data_len ) )
    {
    BT_LOG_ERROR( "NULL/Empty HCI event" );
    return false;
    }

if( HCI_WICED_PKT == hci_event->data[cur_pos] )
    {
    header_len = 5;
    ++cur_pos;
    *event_code = hci_event->data[cur_pos++];
    *group_code = hci_event->data[cur_pos++];
    *param_len = LITTLE_ENDIAN_TO_INT16( &( hci_event->data[cur_pos] ) );
    cur_pos += 2;
    *param_pos = cur_pos;
    }
else if( HCI_STANDARD_EVENT_PKT == hci_event->data[cur_pos] )
    {
    header_len = 3;
    ++cur_pos;
    *event_code = hci_event->data[cur_pos++];
    *group_code = HCI_CONTROL_GROUP_STANDARD_GARMIN;
    *param_len = hci_event->data[cur_pos++];
    *param_pos = cur_pos;
    }
else
    {
    BT_LOG_DEBUG( "Unhandled HCI packet type: 0x%02x", hci_event->data[cur_pos] );
    return false;
    }

if( hci_event->data_len != ( header_len + *param_len ) )
    {
    BT_LOG_ERROR( "Invalid HCI event length" );
    return false;
    }

return true;
}

/*================================================================================================
@brief   Send the HCI event to Bluetooth Manager HCI task
@details Send the HCI event to Bluetooth Manager HCI task
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool HCI_tsk_send_event
    (
    const uint8_t* uart_rx_data,
    const uint32_t rx_data_len
    )
{
HCI_event_t hci_event = { 0 };

if( ( NULL == uart_rx_data ) || ( 0 == rx_data_len ) )
    {
    BT_LOG_ERROR( "NULL/Empty UART Rx data" );
    return false;
    }

#if( HCI_DEBUG_ENABLED )
    {
    PRINTF( "[BT]HCI Rx[%u]: ", rx_data_len );
    for( uint32_t i = 0; i < rx_data_len; ++i )
        {
        PRINTF( "%02x ", uart_rx_data[i] );
        }
    PRINTF( "\r\n" );
    }
#endif

if( rx_data_len > HCI_EVENT_MAX_SIZE )
    {
    BT_LOG_ERROR( "Maximum HCI event size exceeded: %u (> %d)", rx_data_len, HCI_EVENT_MAX_SIZE );
    return false;
    }

memcpy( hci_event.data, uart_rx_data, rx_data_len );
hci_event.data_len = rx_data_len;

if( pdTRUE != xQueueSend( s_hci_event_queue, &hci_event, 0 ) )
    {
    BT_LOG_ERROR( "HCI event sent failed due to Queue Full" );
    return false;
    }

BT_LOG_VERBOSE( "HCI event sent: len=%u", hci_event.data_len );
return true;
}

#ifdef __cplusplus
}
#endif
