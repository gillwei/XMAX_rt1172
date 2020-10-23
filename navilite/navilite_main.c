/*********************************************************************
* @file
* navilite_main.c
*
* @brief
* NAVILITE module - main
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "limits.h"
#include "task.h"
#include "semphr.h"
#include "stream_buffer.h"
#include "ewrte.h"
#include "fsl_debug_console.h"
#include "GRM_pub_prj.h"
#include "NAVILITE_pub_protocol.h"
#include "EW_pub.h"
#include "navilite_prv.h"
#include "BTM_pub.h"
#include "NAVILITE_pub.h"
#include "navilite_util.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define NAVILITE_TASK_PRIORITY   ( TASK_PRIO_NAVILITE_PROTOCOL )
#define NAVILITE_TASK_STACK_SIZE ( configMINIMAL_STACK_SIZE * 5 )
#define NAVILITE_TASK_NAME       "navilite_task"
#define EVENT_NAVILITE_CONNECT ( 1 << 0 )
#define EVENT_NAVILITE_DISCONNECT ( 1 << 1 )
#define EVENT_NAVILITE_QUEUE_AVAIL ( 1 << 2 )
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
AT_BOARDSDRAM_SECTION( uint8_t navilite_buffer[1024 * 4] );
AT_BOARDSDRAM_SECTION( uint8_t navilite_jpg_buffer[NAVILITE_JPEG_BUFFER_MAX_SIZE] );
AT_BOARDSDRAM_SECTION( uint8_t navilite_queue_buffer[NAVILITE_QUEUE_BUFFER_SIZE] );
AT_BOARDSDRAM_SECTION( uint8_t navilite_queue_buffer_unused_alignment[256 - NAVILITE_QUEUE_BUFFER_SIZE] );

static TaskHandle_t xTaskNaviLite;
static StreamBufferHandle_t xQueueBuffer = NULL;
static navilite_conn_mode_type conn_mode = 0;
navilite_content_update_callbacks_type navilite_content_update_callbacks;
navilite_ack_table_type navilite_connection_ack_status;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/
#define NAVILITE_DEBUG false

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* init_ack_status
*
* Initialize ack status
*
*********************************************************************/
static void init_ack_status
    (
    void
    )
{
navilite_connection_ack_status.esn_ack = 0;
navilite_connection_ack_status.frame_ack = 0;
}

/*********************************************************************
*
* @private
* navilite_bt_connection_info_handler
*
* navilite defined callback for handling the bt connection change
*
* @param connection_is_up true when connected, false disconnected
* @param connection_info data pointer of bt connection info data
* @param conn_path path for bt spp or iap
*
*********************************************************************/
static void navilite_bt_connection_info_handler
    (
    const bool connection_is_up,
    const uint8_t* connection_info,
    const bt_connection_path_type conn_path
    )
{
PRINTF(" \r\n#### BT STATUS PATH changed: %d ####\r\n", conn_path );
if( connection_is_up )
    {
    NAVILITE_connect( conn_path );
    }
else
    {
    NAVILITE_disconnect();
    }
}

/*********************************************************************
*
* @private
* task_main
*
* Main loop of the navilite service task
*
*********************************************************************/
static void task_main
    (
    void* arg
    )
{
uint32_t notifiy_events;

init_ack_status();
navilite_hmi_init_setup();

for( ;; )
    {
    xTaskNotifyWait( 0x00,      /* Don't clear any notification bits on entry. */
                     ULONG_MAX, /* Reset the notification value to 0 on exit. */
                     &notifiy_events, /* Notified value pass out in ulNotifiedValue. */
                     portMAX_DELAY ); /* Block indefinitely. */

    if( ( notifiy_events & EVENT_NAVILITE_CONNECT ) != 0 )
        {
        PRINTF( "BT is connected, NAVILITE TASK switch to ready mode\r\n" );
        if( navilite_content_update_callbacks.callback_func_connected )
            {
            navilite_content_update_callbacks.callback_func_connected( 0 );
            }
        }
    if( ( notifiy_events & EVENT_NAVILITE_DISCONNECT ) != 0 )
        {
        PRINTF( "BT is disconnected, NAVILITE TASK switch to close mode\r\n" );
        navilite_content_update_callbacks.callback_func_disconnected( 0 );
        init_ack_status();
        }
    if( ( notifiy_events & EVENT_NAVILITE_QUEUE_AVAIL ) != 0 )
        {
        navilite_receive_buffer_and_parse( xQueueBuffer );
        }
    }
vTaskDelete( NULL );
}

/*********************************************************************
*
* @private
* create_task
*
* Create navilite task
*
*********************************************************************/
static void create_task
    (
    void
    )
{
BaseType_t result = xTaskCreate( task_main, NAVILITE_TASK_NAME, NAVILITE_TASK_STACK_SIZE, NULL, NAVILITE_TASK_PRIORITY, &xTaskNaviLite );
configASSERT( pdPASS == result );
}

/*********************************************************************
*
* @private
* navilite_setup
*
* Setup the mode of navilite
*
* @param mode initial mode to setup
*
*********************************************************************/
void navilite_setup
    (
    navilite_init_mode_type mode
    )
{
PRINTF( "navilite_setup \r\n" );

if( mode == NAVILITE_INIT_FAKE_DATA )
    {
    PRINTF( "NAVILITE API Simulation Mode enabled!\r\n" );
    NAVILITE_connect( NAVILITE_CONN_TBD ); // assume the bt is connected, then begin the task loop for simulation
    }
else
    {
    PRINTF( "NAVILITE API normal mode\r\n" );
    }
}

/*********************************************************************
*
* @public
* NAVILITE_init
*
* Init NAVILITE module
*
*
*********************************************************************/
void NAVILITE_init
    (
    void
    )
{
PRINTF( "NAVILITE_init - create task\r\n" );

// initialize callback pointers to be null
#if( !UNIT_TEST_NAVILITE )
    navilite_content_update_callbacks.callback_func_connected = NULL;
    navilite_content_update_callbacks.callback_func_disconnected = NULL;
#endif
navilite_content_update_callbacks.callback_func_imageframe = NULL;
navilite_content_update_callbacks.callback_func_eta = NULL;
navilite_content_update_callbacks.callback_func_currentroadname = NULL;
navilite_content_update_callbacks.callback_func_nextturndistance = NULL;
navilite_content_update_callbacks.callback_func_nexttbtist = NULL;
navilite_content_update_callbacks.callback_func_activetbtitem = NULL;
navilite_content_update_callbacks.callback_func_navieventtext = NULL;
navilite_content_update_callbacks.callback_func_homelocationsetting = NULL;
navilite_content_update_callbacks.callback_func_officelocationsetting = NULL;
navilite_content_update_callbacks.callback_func_zoomlevel = NULL;
navilite_content_update_callbacks.callback_func_routecalcprogress = NULL;
navilite_content_update_callbacks.callback_func_daynightmode = NULL;
navilite_content_update_callbacks.callback_func_tbtmodestatus = NULL;
navilite_content_update_callbacks.callback_func_speedlimit = NULL;
navilite_content_update_callbacks.callback_func_viapointcount = NULL;

// Setup queue buffer
navilite_setup_queue_buffer();

// Add a navilite callback to BT status changed
BTM_add_connection_info_callback( navilite_bt_connection_info_handler );

// HMI setup
NAVILITE_hmi_integration_setup();

// Setup HCI data callback
HCI_spp_iap2_add_data_callback( ( spp_iap2_data_callback )NAVILITE_queue_hci_buffer );

create_task();

#if( NAVILITE_LOCAL_HMI_TEST_MODE == 1 )
    navilite_setup( NAVILITE_INIT_FAKE_DATA );
    PRINTF( "#HMI local test mode setting detected! run fake data test mode!\r\n" );
#else
    navilite_setup( NAVILITE_INIT_NORMAL );
#endif
}

/*********************************************************************
*
* @public
* NAVILITE_connect
*
* begin to connect process
*
* @param mode  the mode choose to connect
*
*********************************************************************/
void NAVILITE_connect
    (
    navilite_conn_mode_type mode
    )
{
PRINTF( "NAVILITE_connect()\r\n" );
conn_mode = mode;
xTaskNotify( xTaskNaviLite, EVENT_NAVILITE_CONNECT, eSetBits );
}

/*********************************************************************
*
* @public
* NAVILITE_get_connect_mode
*
* Get current NAVILITE connect mode
*
*********************************************************************/
navilite_conn_mode_type NAVILITE_get_connect_mode
    (
    void
    )
{
return conn_mode;
}

/*********************************************************************
*
* @public
* NAVILITE_disconnect()
*
* Issue disconnect event to NAVILITE module
*
*********************************************************************/
void NAVILITE_disconnect
    (
    void
    )
{
PRINTF( "NAVILITE_disconnect()\r\n" );
xTaskNotify( xTaskNaviLite, EVENT_NAVILITE_DISCONNECT, eSetBits );
}

/*********************************************************************
*
* @private
* navilite_setup_queue_buffer
*
* Create HCI buffer to NAVILITE internal queue buffer
*
*********************************************************************/
void navilite_setup_queue_buffer
    (
    void
    )
{
if( xQueueBuffer == NULL)
    {
    xQueueBuffer = xStreamBufferCreate( NAVILITE_QUEUE_BUFFER_SIZE, 1 );
    xStreamBufferReset( xQueueBuffer );
    PRINTF( "[NaviLite-Buffer] Create buffer for queuing HCI buffer: %d, free: %d\r\n", NAVILITE_QUEUE_BUFFER_SIZE, xStreamBufferSpacesAvailable( xQueueBuffer ) );
    }
}

/*********************************************************************
*
* @public
* NAVILITE_queue_hci_buffer
*
* Queue HCI buffer to NAVILITE internal queue buffer
*
* @param data data pointer of HCI data stream
* @param data_len data length of the data pointer received
*
*********************************************************************/
void NAVILITE_queue_hci_buffer
    (
    uint8_t *data,
    uint32_t data_len
    )
{
size_t buffer_write = 0;
buffer_write = xStreamBufferSend( xQueueBuffer, data, data_len, pdMS_TO_TICKS( NAVILITE_QUEUE_BUFFER_TIMEOUT ) );

if( buffer_write != data_len )
    {
    PRINTF( "![NaviLite-Buffer]  HCI buffer send failed!! %d != %d(Abort!), Free:%d, current task:%d\r\n", buffer_write, data_len, xStreamBufferSpacesAvailable( xQueueBuffer ), xTaskGetCurrentTaskHandle() );
    }
else
    {
    // notify the navilite event that the hci buffer is available on stream buffer
    xTaskNotify( xTaskNaviLite, EVENT_NAVILITE_QUEUE_AVAIL, eSetBits );
    }
}

/*********************************************************************
*
* @private
* navilite_receive_buffer_and_parse
*
* Receive buffer and parse the buffer from message queue
*
* @param StreamBuffer_t buffer handle to receive and parse
*
*********************************************************************/
void navilite_receive_buffer_and_parse
    (
    StreamBufferHandle_t buffer_handle
    )
{
size_t received_bytes;
int buffer_remained = 0;

while( ( buffer_remained = xStreamBufferBytesAvailable( buffer_handle ) > 0 ) )
    {
    received_bytes = xStreamBufferReceive( buffer_handle,
            ( void * ) navilite_queue_buffer,
            sizeof( navilite_queue_buffer ),
            portMAX_DELAY );

    #if( NAVILITE_DEBUG )
        PRINTF( "Parse Data:[%d], Buffer Remained:%d\r\n", received_bytes, buffer_remained );
    #endif
    NAVILITE_parse_data( navilite_queue_buffer, received_bytes );
    }
}

/*********************************************************************
 *
 * @private
 * navilite_ack_reply
 *
 * ack reply for image frame callback
 *
 *********************************************************************/
static void navilite_ack_reply
    (
    void
    )
{
bool ret = false;
int try_count = 3;

// response ACK when receive a image frame and try resend if failed
while( !ret && try_count-- )
    {
    ret = NAVILITE_report_app_service_ack( NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE_ACK );
    if( !ret ) PRINTF( "# ERROR: SENDING failed, and resend # try:%d\r\n", try_count );
    }
}

/*********************************************************************
*
* @public
* NAVILITE_parse_data
*
* Parse NAVILITE protocol
*
* @param data data pointer of NAVILITE protocol stream
* @param data_len data length of the data pointer received
*
*********************************************************************/
void NAVILITE_parse_data
    (
    uint8_t *data,
    uint32_t data_len
    )
{
uint32_t idx = 0;
navilite_message navilite_packet;
static uint8_t is_jpeg_mode = 0;
static int image_frame_update_payload_size = 0;
static int jpg_current_size = 0;

#if( NAVILITE_LOCAL_HMI_TEST_MODE == 1 && !UNIT_TEST_ENABLE )
    // force into HMI local test mode without handling BT transfer even if the BT is connected
    PRINTF( "exit parse data under hmi test mode\r\n" );
    return;
#endif

// parse magic code
// when frame request come with a full header, then check if the header has nAl@.
// if no, in general. it wll be map update frame request because it will have fragmented data

if( data_len >= 4 && strncmp( (char*)data , MAGIC_CODE, 4 ) == 0 )
    {
    // print the frame information for debug
#if( NAVILITE_DEBUG )
    PRINTF( "\r\n======= FRAME DEBUG (MTU size:%d) ========\r\n", data_len);
    PRINTF("\r\nRAW TEXT:");
    for( i=0; i < sizeof( navilite_message );i++ )
        {
        PRINTF("[%c]", data[i] );
        }
    PRINTF("\r\nASCII:");
    for( i=0; i < sizeof( navilite_message );i++ )
        {
        PRINTF("[%d]", data[i] );
        }
    PRINTF("\r\n");
#endif
    strncpy( (char*)data, (char*)navilite_packet.magic_code, 4 );

    // magic code
    idx += 4;

    // navilite version
    navilite_packet.version = data[idx++];
#if( NAVILITE_DEBUG )
    PRINTF( "version:%d\r\n", navilite_packet.version );
#endif
    // navlite frame type
    navilite_packet.frame_type = data[idx++];
#if( NAVILITE_DEBUG )
    PRINTF( "frame type:%d\r\n", navilite_packet.frame_type );
#endif
    // navlite service type
    navilite_packet.service_type = data[idx++];
#if( NAVILITE_DEBUG )
    PRINTF( "service type:%d\r\n", navilite_packet.service_type );
#endif

    // navlite payload size ; little-endian format
    navilite_packet.payload_size =(uint32_t)(
            (data[idx + 3] << 24)| (data[idx + 2] << 16) | (data[idx + 1] << 8) | (data[idx + 0] << 0));

    idx += 4;
#if( NAVILITE_DEBUG )
    PRINTF( "!payload size: [%d]\r\n", navilite_packet.payload_size );
#endif
    // navilite payload type (value/ptr)
    navilite_packet.payload_data_type = data[idx++];
#if( NAVILITE_DEBUG )
    PRINTF( "payload data type:%s\r\n", navilite_packet.payload_data_type == NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER
            ? "pointer":"value" );
#endif
    if( navilite_packet.payload_data_type == NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE )
        {
        // read the data value of the packet (not payload part)
        navilite_packet.data_value = (uint16_t)( data[idx + 1] << 8 ) | ( data[idx + 0] << 0 );
#if( NAVILITE_DEBUG )
        PRINTF( ">>%d %d ; Value (uint16_t) = %d\r\n", data[idx + 1], data[idx + 0], navilite_packet.data_value );
#endif
        idx += 2;
        }

    // NOTE: in frame payload itself, no uint8_t* pointer/uint16_t exists, but  payload data is carried.
    //       if payload type is pointer, and size > 0 => idx += sizeof( uint8_t* );
    // the final effect is like this:
    // union {
    //    uint16_t      data_value;
    //    uint8_t*      data_pointer;
    // }

    // NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type ==  NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE )
        {
        if( data_len <= 240 && navilite_packet.payload_size > 0 )
            {
            if( is_jpeg_mode == 0 )
                {
                image_frame_update_payload_size = navilite_packet.payload_size;
                is_jpeg_mode = 1;
                }
            jpg_current_size = 0;
            memcpy( navilite_jpg_buffer, data + idx, data_len );
            jpg_current_size += ( data_len - idx );
            idx += data_len;
            }
        }

    // NAVILITE_SERVICETYPE_CURROADNAME_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type ==  NAVILITE_SERVICETYPE_CURROADNAME_UPDATE )
        {
        // complete frame request contains ALL in one!!!
        if( data_len <= 240 && navilite_packet.payload_size > 0 )
            {
            memcpy( navilite_buffer, data + idx, data_len );
            idx += data_len;
            navilite_buffer[idx] = 0;

            if( navilite_content_update_callbacks.callback_func_currentroadname )
                {
                // Callback API for RoadName notification update
                navilite_content_update_callbacks.callback_func_currentroadname( navilite_buffer, navilite_packet.payload_size );
                }
            }
        }

    // NAVILITE_SERVICETYPE_ETA_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type ==  NAVILITE_SERVICETYPE_ETA_UPDATE )
        {
        uint32_t eta_value = 0; // this value will be calculated in HMI for proper absolute time
        if( data_len <= 240 && navilite_packet.payload_size > 0 )
            {
            eta_value = (uint32_t)( ( data[idx + 3] << 24 ) | ( data[idx + 2] << 16 ) | ( data[idx + 1] << 8 ) | ( data[idx + 0] << 0 ) );
            }

        if( navilite_content_update_callbacks.callback_func_eta )
            {
            // Callback API for ETA notification update
            navilite_content_update_callbacks.callback_func_eta( eta_value );
            }
        }

    // Non image frame update operations
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type !=  NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE )
        {
        is_jpeg_mode = 0;
        }

    }
else if( is_jpeg_mode )
    {
    for( idx = 0; idx < data_len; idx++ )
        {
        if( jpg_current_size < NAVILITE_JPEG_BUFFER_MAX_SIZE )
            {
            navilite_jpg_buffer[jpg_current_size++] = (uint8_t)data[idx];
            }

        if( ( ( image_frame_update_payload_size == jpg_current_size ) ) &&
            navilite_content_update_callbacks.callback_func_imageframe != NULL &&
            jpg_current_size <= NAVILITE_JPEG_BUFFER_MAX_SIZE )
            {
            navilite_ack_reply();
            navilite_content_update_callbacks.callback_func_imageframe( navilite_jpg_buffer, image_frame_update_payload_size, NAVILITE_IMAGE_NAVIGATION );
            is_jpeg_mode = 0;
            jpg_current_size = 0;
            }

        if( ( ( image_frame_update_payload_size == jpg_current_size ) ) &&
            image_frame_update_payload_size > NAVILITE_JPEG_BUFFER_MAX_SIZE )
            {
            is_jpeg_mode = 0;
            image_frame_update_payload_size = 0;
            PRINTF( "WARNING: exceeds %d jpeg max buffer size, skip this jpeg image", image_frame_update_payload_size );
            navilite_ack_reply();
            }
        }
    // Otherwise, the map frame update's payload data is parsing until next frame request!
    }
}
