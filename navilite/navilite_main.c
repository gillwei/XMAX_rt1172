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
#include "NAVI_pub.h"
#include "TEST_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define NAVILITE_TASK_PRIORITY   ( TASK_PRIO_NAVILITE_PROTOCOL )
#define NAVILITE_TASK_STACK_SIZE ( configMINIMAL_STACK_SIZE * 6 )
#define NAVILITE_TASK_NAME       "navilite_task"
#define EVENT_NAVILITE_CONNECT ( 1 << 0 )
#define EVENT_NAVILITE_DISCONNECT ( 1 << 1 )
#define EVENT_NAVILITE_QUEUE_AVAIL ( 1 << 2 )

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef enum
    {
    NAVILITE_SESSION_INDEX_TBTLIST = 0,
    NAVILITE_SESSION_INDEX_FAVLIST = 1,
    NAVILITE_SESSION_INDEX_GASLIST = 2,
    NAVILITE_SESSION_INDEX_SIZE = 3
    } navilite_session_list_index_type;

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
AT_BOARDSDRAM_SECTION( uint8_t navilite_command_buffer[NAVILITE_QUEUE_BUFFER_SIZE * 2] );
AT_BOARDSDRAM_SECTION( uint8_t navilite_command_buffer_unused_alignment[256 * 2 - NAVILITE_QUEUE_BUFFER_SIZE * 2] );
AT_BOARDSDRAM_SECTION( uint8_t navilite_buffer[1024 * 4] );
AT_BOARDSDRAM_SECTION( uint8_t navilite_jpg_buffer[NAVILITE_JPEG_BUFFER_MAX_SIZE] );
AT_BOARDSDRAM_SECTION( uint8_t navilite_queue_buffer[NAVILITE_QUEUE_BUFFER_SIZE] );
AT_BOARDSDRAM_SECTION( uint8_t navilite_queue_buffer_unused_alignment[256 - NAVILITE_QUEUE_BUFFER_SIZE] );

navilite_content_update_callbacks_type navilite_content_update_callbacks;

static TaskHandle_t xTaskNaviLite;
static StreamBufferHandle_t xQueueBuffer = NULL;
static navilite_conn_mode_type conn_mode = 0;
static navilite_session_status_type navilite_session_status;

// generic poi list (tbt/fav/gas)
static uint32_t session_list_size_total[NAVILITE_SESSION_INDEX_SIZE] = { 0 };
static uint32_t session_list_size_last_total[NAVILITE_SESSION_INDEX_SIZE] = { 0 };
static uint32_t session_list_size_counter[NAVILITE_SESSION_INDEX_SIZE] = { 0 };
static uint32_t session_list_item_counter[NAVILITE_SESSION_INDEX_SIZE]= { 0 };  // used for counting list items under same list index
static navilite_tbt_list_type session_tbt_list_data[NAVILITE_SESSION_INDEX_SIZE] = { 0 };
static navilite_poi_list_type session_poi_list_data[NAVILITE_SESSION_INDEX_SIZE] = { 0 };


/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/
#define NAVILITE_DEBUG false
#define NAVILITE_DEBUG_DETAIL false

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* init_session_status
*
* Initialize session status
*
*********************************************************************/
static void init_session_status
    (
    void
    )
{
navilite_session_status.inited = 0; // reset inited status
navilite_session_status.navigation_status = 0; // reset navigating status
navilite_session_status.home_status = 0; // home setting
navilite_session_status.office_status = 0; // office setting
}

/*********************************************************************
*
* @public
* NAVILITE_is_app_navigating
*
* Check if app is now navigating
* @return true if it is navigating
*         false if it is not navigating
*
*********************************************************************/
bool NAVILITE_is_app_navigating
    (
    void
    )
{
return navilite_session_status.navigation_status == 1;
}

/*********************************************************************
*
* @public
* NAVILITE_is_app_home_setting_set
*
* Check if home setting is set
* @return true if it is set
*         false if it is not set
*
*********************************************************************/
bool NAVILITE_is_app_home_setting_set
    (
    void
    )
{
return navilite_session_status.home_status == 1;
}

/*********************************************************************
*
* @public
* NAVILITE_is_app_office_setting_set
*
* Check if office setting is set
* @return true if it is set
*         false if it is not set
*
*********************************************************************/
bool NAVILITE_is_app_office_setting_set
    (
    void
    )
{
return navilite_session_status.office_status == 1;
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
        init_session_status();
        navilite_content_update_callbacks.callback_func_preconnected( 0 );
        }
    if( ( notifiy_events & EVENT_NAVILITE_DISCONNECT ) != 0 )
        {
        PRINTF( "BT is disconnected, NAVILITE TASK switch to close mode\r\n" );
        navilite_content_update_callbacks.callback_func_disconnected( 0 );
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

// ESN sent & acked notification callback
navilite_content_update_callbacks.callback_func_esn_sent = NULL;
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
navilite_content_update_callbacks.callback_func_navigationstatus = NULL;

// Session variables init (TBT/FAV/GAS)
for( int i = 0; i < NAVILITE_SESSION_INDEX_SIZE; i++ )
    {
    session_list_size_total[i] = 0;
    session_list_size_last_total[i] = 0;
    session_list_size_counter[i] = 0;
    }

// Setup queue buffer
navilite_setup_queue_buffer();

// Add a navilite callback to BT status changed
BTM_add_connection_info_callback( navilite_bt_connection_info_handler );

// HMI setup
#if( UNIT_TEST_NAVILITE )
    NAVILITE_hmi_integration_setup();
#else
    NAVI_init();
#endif

// Setup HCI data callback
HCI_spp_iap2_add_data_callback( ( spp_iap2_data_callback )NAVILITE_queue_hci_buffer );

create_task();

#if( NAVILITE_LOCAL_HMI_TEST_MODE == 1 || UNIT_TEST_NAVILITE )
    navilite_setup( NAVILITE_INIT_FAKE_DATA );
    PRINTF( "#test mode setting detected! run fake data test mode!\r\n" );
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
* navilite_frame_count
*
* Count the head protocol
*
* @return return the counts of protocol heads
*
*********************************************************************/
int navilite_frame_count
    (
    uint8_t* data,
    uint8_t data_len
    )
{
int counter = 0;

if( data_len < 5 )
    {
     return -1;
    }
for( int i = 0; ( data_len >= 5 ) && ( i < data_len ); i++ )
    {
        if( ( data[i] == 110 ) && ( data[i+1] == 65 ) && ( data[i+2] == 108 ) && ( data[i+3] == 64 ) )
            {
            counter++;
            }
    }
return counter;
}

/*********************************************************************
*
* @private
* navilite_find_next_pos
*
* Find next protocol head
*
* @return return the next position of protocol head
*
*********************************************************************/
int navilite_find_next_pos
    (
    uint8_t* data,
    uint8_t data_len
    )
{
if( data_len < 5 )
    {
     return -1;
    }

for( int i = 0; (data_len >= 5) && (i < data_len); i++ )
    {
        if( ( data[i] == 110 ) && ( data[i + 1] == 65 ) && ( data[i + 2] == 108 ) && ( data[i + 3] == 64 ) )
            {
            return i;
            }
    }
return -1;
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
int token_start_frame = 0;
int buffer_remained = 0;
int token_char = 0;
int token_index = 0;
static int token_next = 110;
static int token_level = 0;
static int jpeg_mode = 0;


while( ( buffer_remained = xStreamBufferBytesAvailable( buffer_handle ) > 0 ) )
    {
    received_bytes = xStreamBufferReceive( buffer_handle,
            ( void * ) navilite_queue_buffer,
            sizeof( navilite_queue_buffer ),
            portMAX_DELAY );

    for( int i = 0; i < received_bytes; i++ )
        {
        token_char = navilite_queue_buffer[i];

        if( token_char == token_next && token_level == 0 )
            {
            token_next = 65;
            token_level = 1;
            }
        else if( token_char == token_next && token_level == 1 )
            {
            token_next = 108;
            token_level = 2;
            }
        else if( token_char == token_next && token_level == 2 )
            {
            token_next = 64;
            token_level = 3;
            }
        else if( token_char == token_next && token_level == 3 )
            {
            token_next = 110;
            token_level = 0;
            token_start_frame++;
            }

        navilite_command_buffer[token_index++] = token_char;

        if( token_start_frame == 1 )
            {
            token_start_frame = 0;
            token_index -= 4;
            jpeg_mode = NAVILITE_parse_data( navilite_command_buffer, token_index );
            token_index = 0;
            token_index += 4;
            strncpy( (char*)navilite_command_buffer, MAGIC_CODE, 4 );
            token_start_frame = 0;
            }
        else if( token_start_frame > 1 )
            {
            token_start_frame = 0;
            token_index -= 4;
            jpeg_mode = NAVILITE_parse_data( navilite_command_buffer, token_index );

            token_index = 0;
            token_index += 4;
            strncpy( (char*)navilite_command_buffer, MAGIC_CODE, 4 );
            token_start_frame = 1;
            }
        else if( token_index >= received_bytes )
            {
            jpeg_mode = NAVILITE_parse_data( navilite_command_buffer, token_index );
            token_index = 0;
            }

        if( jpeg_mode )
            {
            token_level = 0;
            }

        }

    if( received_bytes < NAVILITE_QUEUE_BUFFER_SIZE )
        {
        jpeg_mode = NAVILITE_parse_data( navilite_command_buffer, token_index );
        }
}
}

/*********************************************************************
*
* @private
* navilite_extra_parse
*
*  Parse the buffer with data pointer, and data length for extra
*  purpose
*
* @param data data pointer to parse
* @param data_len data length of the data pointer
*
*********************************************************************/
void navilite_extra_parse
    (
    uint8_t* data,
    uint8_t data_len
    )
{
int pos = 0;
int t1 = 0;
int t2 = 0;
int fc = 0;
int step = 0;
bool is_jpeg_mode = false;

fc = navilite_frame_count( data, data_len );

if( fc <= 1 )
    {
    t1 = ( navilite_find_next_pos( data, data_len ) );

    if( is_jpeg_mode && ( t1 > 0 ) )
        {
        is_jpeg_mode = navilite_parse_data_inner( data, t1 );
        is_jpeg_mode = navilite_parse_data_inner( data + t1, data_len - t1 );
        }
    else
        {
        is_jpeg_mode = navilite_parse_data_inner( data, data_len );
        }
    }

if( fc > 1 )
    {
    t2 = navilite_find_next_pos( data + 1, data_len );
    t1 = ( navilite_find_next_pos( data, data_len ) );
    step = 0;

    if( !is_jpeg_mode && ( t1 > t2 ) )
        {
        is_jpeg_mode = navilite_parse_data_inner( data, t1 );
        }

    if( is_jpeg_mode && ( t1 > 0 ) )
        {
        is_jpeg_mode = navilite_parse_data_inner( data, t1 );
        }

    while ( ( step <= fc ) )
        {
        if( t1 >= 0 )
            {
            int hc = navilite_frame_count( data + t1, data_len - t1 );
            if( hc <= 0 ) {
                break;
            }

            is_jpeg_mode = navilite_parse_data_inner( data + t1, t2 - t1 + 1 );

            t1 = t2 + 1;
            pos = navilite_find_next_pos( data + t1 + 1, data_len - t1 ) ;
            t2 = t1 + ( ( pos < 0 ) ? ( data_len - t1 ) : pos );
            }
        step++;
        }
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
#if( NAVILITE_SESSION_ACK_SUPPORT )
    bool ret = false;
    int try_count = 3;

    // response ACK when receive a image frame and try resend if failed
    while( !ret && try_count-- )
        {
        ret = NAVILITE_report_app_service_ack( NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE_ACK );
        if( !ret ) PRINTF( "# ERROR: SENDING failed, and resend # try:%d\r\n", try_count );
        }
#else
   PRINTF( "# WARNING: image frame update ack reply is disabled!\r\n" );
#endif
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
* @return return true if jpeg mode is available
*                false if jpeg not available
*********************************************************************/
bool NAVILITE_parse_data
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
    // check connection
    if( navilite_session_status.inited == 0 &&
    navilite_content_update_callbacks.callback_func_connected )
        {
        navilite_session_status.inited = 1;
        navilite_content_update_callbacks.callback_func_connected( 0 );
        }
    // print the frame information for debug
#if( NAVILITE_DEBUG )
    int i;
    PRINTF( "\r\n======= FRAME DEBUG (MTU size:%d) ========\r\n", data_len);
    PRINTF("\r\nRAW TEXT:");
    for( i = 0; i < sizeof( navilite_message ); i++ )
        {
        PRINTF("[%c]", data[i] );
        }
#endif

#if( NAVILITE_DEBUG && NAVILITE_DEBUG_DETAIL )
    PRINTF("\r\nASCII(%d-%d):", d_counter++, data_len );
    PRINTF("\r\n{");
    for( i = 0; i < data_len; i++ )
        {
        PRINTF("%d,", data[i] );
        }
    PRINTF("}\r\n");
#endif

    // magic code
    idx += 4;

    // navilite version
    navilite_packet.version = data[idx++];
#if( NAVILITE_DEBUG )
    PRINTF( "\r\nversion:%d\r\n", navilite_packet.version );
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
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE )
        {
        if( is_jpeg_mode == 0 )
            {
            image_frame_update_payload_size = navilite_packet.payload_size;
            is_jpeg_mode = 1;
            }
        jpg_current_size = 0;
        memcpy( navilite_jpg_buffer, data + idx, data_len - idx );
        jpg_current_size += ( data_len - idx );
        idx += ( data_len - idx );
        }

    // NAVILITE_SERVICETYPE_CURROADNAME_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_CURROADNAME_UPDATE )
        {
        // complete frame request contains ALL in one!!!
        memcpy( navilite_buffer, data + idx, data_len );
        idx += data_len;
        navilite_buffer[idx] = 0;

        if( navilite_content_update_callbacks.callback_func_currentroadname )
            {
            // Callback API for RoadName notification update
            navilite_content_update_callbacks.callback_func_currentroadname( navilite_buffer, navilite_packet.payload_size );
            }
        }
    else if( navilite_packet.payload_size == 0 && navilite_content_update_callbacks.callback_func_currentroadname )
        {
            // Used for clearing the road name on HMI
            navilite_content_update_callbacks.callback_func_currentroadname( NULL, 0 );
        }

    // NAVILITE_SERVICETYPE_ETA_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_ETA_UPDATE )
        {
        uint32_t value = (uint32_t)( ( data[idx + 3] << 24 ) | ( data[idx + 2] << 16 ) | ( data[idx + 1] << 8 ) | ( data[idx + 0] << 0 ) );

        if( navilite_content_update_callbacks.callback_func_eta )
            {
            // Callback API for ETA notification update
            navilite_content_update_callbacks.callback_func_eta( value );
            }
        }

    // NAVILITE_SERVICETYPE_BT_THROUGHPUT_TIMEOUT_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_BT_THROUGHPUT_TIMEOUT_UPDATE )
        {
        uint8_t value = navilite_packet.data_value; // this value will be calculated in HMI for proper absolute time

        if( navilite_content_update_callbacks.callback_func_bt_timeout )
            {
            // Callback API for BT timeout notification update
            navilite_content_update_callbacks.callback_func_bt_timeout( value );
            }
        }

    // NAVILITE_SERVICETYPE_ROUTE_CALC_PROGRESS_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_ROUTE_CALC_PROGRESS_UPDATE )
        {
        uint8_t progress = 0;
        progress = (uint8_t)navilite_packet.data_value;

        if( navilite_content_update_callbacks.callback_func_routecalcprogress )
            {
            navilite_content_update_callbacks.callback_func_routecalcprogress( progress );
            }
        }

    // NAVILITE_SERVICETYPE_DAYNIGHT_MODE_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_DAYNIGHT_MODE_UPDATE )
        {
        uint8_t mode = 0;
        mode = (uint8_t)navilite_packet.data_value;

        if( navilite_content_update_callbacks.callback_func_daynightmode )
            {
            navilite_content_update_callbacks.callback_func_daynightmode( mode );
            }
        }

    // NAVILITE_SERVICETYPE_MAP_ZOOM_LEVEL_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_MAP_ZOOM_LEVEL_UPDATE )
        {
        uint8_t currentLevel = 0;
        uint8_t maxLevel = 0;

        currentLevel = (uint8_t)data[idx++];
        maxLevel = (uint8_t)data[idx++];

        if( navilite_content_update_callbacks.callback_func_zoomlevel )
            {
            // Callback API for zoom level update
            navilite_content_update_callbacks.callback_func_zoomlevel( currentLevel, maxLevel );
            }
        }

    // NAVILITE_SERVICETYPE_HOMESETTING_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_HOMESETTING_UPDATE )
        {
        uint8_t value = navilite_packet.data_value;

        if( navilite_content_update_callbacks.callback_func_homelocationsetting )
            {
            // Callback API for home setting notification update
            navilite_content_update_callbacks.callback_func_homelocationsetting( value );
            // Update the session status for home setting status, used for blocking type API
            navilite_session_status.home_status = value;
            }
        }

    // NAVILITE_SERVICETYPE_OFFICESETTING_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_OFFICESETTING_UPDATE )
        {
        uint8_t setting_value = navilite_packet.data_value;

        if( navilite_content_update_callbacks.callback_func_officelocationsetting )
            {
            // Callback API for home setting notification update
            navilite_content_update_callbacks.callback_func_officelocationsetting( setting_value );
            // Update the session status for office setting status, used for blocking type API
            navilite_session_status.office_status = setting_value;
            }
        }

    // NAVILITE_SERVICETYPE_VIA_POINT_COUNT_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_VIA_POINT_COUNT_UPDATE )
        {
        uint8_t value = navilite_packet.data_value;

        if( navilite_content_update_callbacks.callback_func_viapointcount )
            {
            // Callback API for via point count notification update
            navilite_content_update_callbacks.callback_func_viapointcount( value );
            }
        }

    // NAVILITE_SERVICETYPE_SPEED_LIMIT_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_SPEED_LIMIT_UPDATE )
        {
        uint16_t value = navilite_packet.data_value;

        if( navilite_content_update_callbacks.callback_func_speedlimit )
            {
            // Callback API for speed limit notification update
            navilite_content_update_callbacks.callback_func_speedlimit( value );
            }
        }

    // NAVILITE_SERVICETYPE_NAVIEVENTTEXTUPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_NAVIEVENTTEXTUPDATE )
        {
        uint8_t event_type;
        uint8_t event_extra_subtype;
        uint8_t visibilty;
        uint8_t event_str_size;
        int i = 0;
        // parsing the navi text packet
        // read one byte for event type
        event_type = (uint8_t)data[idx++];
        // read one byte for extra subtype
        event_extra_subtype = (uint8_t)data[idx++];
        // read one byte for visibility
        visibilty = (uint8_t)data[idx++];
        // read one byte for navi text string size
        event_str_size = (uint8_t)data[idx++];
        // read the str size bytes for navi text
        for ( i = 0; i < event_str_size; i++ )
            {
            navilite_buffer[i] = (uint8_t)data[idx++];
            }
        navilite_buffer[i++] = 0; // store the navi text on navilite buffer
        if( navilite_content_update_callbacks.callback_func_navieventtext )
            {
            // Callback API for navi event text notification update
            navilite_content_update_callbacks.callback_func_navieventtext( (uint8_t*)navilite_buffer, event_str_size, event_type, event_extra_subtype, visibilty );
            }
        }

    // NAVILITE_SERVICETYPE_NEXTTURNDIST_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_NEXTTURNDIST_UPDATE )
        {
        uint8_t icon_index = 0;
        uint32_t distance = 0;
        uint8_t dist_unit_str_size = 0;

        int i = 0;
        // parsing the icon index
        // read one byte for icon index
        icon_index = (uint8_t)data[idx++];
        // distance
        distance = (uint32_t)( ( data[idx + 3] << 24 ) | ( data[idx + 2] << 16 ) | ( data[idx + 1] << 8 ) | ( data[idx + 0] << 0 ) );
        idx+=4;
        // unit string size
        dist_unit_str_size = (uint8_t)data[idx++];

        // read the str bytes for distance
        for ( i = 0; i < dist_unit_str_size; i++ )
            {
            navilite_buffer[i] = (uint8_t)data[idx++];
            }
        navilite_buffer[i++] = 0; // store the navi text on navilite buffer
        if( navilite_content_update_callbacks.callback_func_nextturndistance )
            {
            // Callback API for next turn distance notification update
            navilite_content_update_callbacks.callback_func_nextturndistance( icon_index, distance, (uint8_t*)navilite_buffer, dist_unit_str_size );
            }
        }

    // NAVILITE_SERVICETYPE_ACTIVETURBLIST_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_ACTIVETURBLIST_UPDATE )
        {
        uint16_t active_tbt_index = 0; // app will inform current active tbt list to let HMI know what tbt list should be shown
        active_tbt_index = (uint16_t)navilite_packet.data_value;
        // fire callback when available
        if( navilite_content_update_callbacks.callback_func_activetbtitem )
            {
            // Callback API for next turn distance notification update
            navilite_content_update_callbacks.callback_func_activetbtitem( active_tbt_index );
            }
        }

    // NAVILITE_SERVICETYPE_TBTLIST_UPDATE  (list SIZE/hasMoreData notify)
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_TBTLIST_UPDATE )
        {
        uint16_t list_item_count = 0;
        uint8_t has_more_items = 0;
        // list item count extraction
        for( ; idx < data_len; idx++ )
            {
            list_item_count = (uint16_t)( ( data[idx + 1] << 8 ) | ( data[idx + 0] << 0 ) );
            // has more data in next request for UI to show more data on item lists(> 50);
            idx += 2;
            has_more_items = data[idx++];
            }
        session_list_size_total[NAVILITE_SESSION_INDEX_TBTLIST] = list_item_count;
        session_list_item_counter[NAVILITE_SESSION_INDEX_TBTLIST] = 0; // reset the counter when this command is received
        PRINTF( "[NAVILITE_BEGIN TBT LIST ITEM SIZE: %d, reset session_tbtlist_item_counter = 0]\r\n", session_list_size_total[NAVILITE_SESSION_INDEX_TBTLIST] );

        if( session_list_size_last_total[NAVILITE_SESSION_INDEX_TBTLIST] != session_list_size_counter[NAVILITE_SESSION_INDEX_TBTLIST] )
            {
            session_list_size_last_total[NAVILITE_SESSION_INDEX_TBTLIST] = session_list_size_total[NAVILITE_SESSION_INDEX_TBTLIST];
            PRINTF( "#WARNING: previous tbtlist is not completely received! SHOULD HAVE %d lists but only %d lists received\r\n", session_list_size_last_total[NAVILITE_SESSION_INDEX_TBTLIST], session_list_size_counter[NAVILITE_SESSION_INDEX_TBTLIST] );
            }
        if( navilite_content_update_callbacks.callback_func_nexttbtist )
            {
            navilite_content_update_callbacks.callback_func_nexttbtist
                (
                NAVILITE_TBTLIST_ACTION_LISTSIZE,
                NULL,
                0,
                session_list_size_total[NAVILITE_SESSION_INDEX_TBTLIST],  // total items will be updated later by NAVILITE_SERVICETYPE_TBTLIST_DATA_UPDATE
                0,
                has_more_items // has more item on next request?
                );
            }
        }

    // NAVILITE_SERVICETYPE_TBTLIST_DATA_UPDATE  // list item data notify
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_TBTLIST_DATA_UPDATE )
        {

        if( session_list_size_total[NAVILITE_SESSION_INDEX_TBTLIST] == 0 )
            {
            PRINTF( "#ERROR: session_tbtlist_size_total = 0 ; NAVILITE_SERVICETYPE_TBTLIST_UPDATE request need to be issued first from app!\r\n" );
            }

            session_list_size_counter[NAVILITE_SESSION_INDEX_TBTLIST]++;
            uint16_t list_item_index = 0;
            uint8_t icon_index = 0;
            uint8_t desc_str_size;
            uint8_t dist_unit_str_size;
            uint32_t distance = 0;
            uint8_t* desc_str = NULL;
            uint8_t* dist_unit_str = NULL;

            for( ; idx < data_len; idx++ )
                {
                // list index
                list_item_index = (uint16_t)( ( data[idx + 1] << 8 ) | ( data[idx + 0] << 0 ) );
                idx += 2;
                // icon index
                icon_index = (uint8_t)data[idx++];
                // desc_size
                desc_str_size = (uint8_t)data[idx++];
                // dist_unit_size;
                dist_unit_str_size = (uint8_t)data[idx++];
                // distance
                distance = (uint32_t)( ( data[idx + 3] << 24 ) | ( data[idx + 2] << 16 ) | ( data[idx + 1] << 8 ) | ( data[idx + 0] << 0 ) );
                idx += sizeof( distance ); // now point to distance unit string portion
                // store the distance unit string
                dist_unit_str = navilite_buffer;
                // copy the unit string to buffer
                memcpy( navilite_buffer, data + idx, dist_unit_str_size );
                idx += dist_unit_str_size;
                // store the desc string pointer
                desc_str = navilite_buffer + idx;
                // copy the desc string to buffer
                memcpy( navilite_buffer + idx, data + idx , desc_str_size );
                idx += data_len;
                if( navilite_content_update_callbacks.callback_func_nexttbtist )
                    {
                    // prepare list item data
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_TBTLIST].list_item_index = list_item_index;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_TBTLIST].icon_index = icon_index;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_TBTLIST].desc_size = desc_str_size;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_TBTLIST].dist_unit_size = dist_unit_str_size;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_TBTLIST].distance = distance;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_TBTLIST].distance_unit = dist_unit_str;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_TBTLIST].desc = desc_str;
                    // Callback API for turn by turn list update and increase the session_tbtlist_item_counter from 0
                    navilite_content_update_callbacks.callback_func_nexttbtist( NAVILITE_TBTLIST_ACTION_ITEMADD, &session_tbt_list_data[NAVILITE_SESSION_INDEX_TBTLIST], list_item_index, session_list_size_total[NAVILITE_SESSION_INDEX_TBTLIST], ++session_list_item_counter[NAVILITE_SESSION_INDEX_TBTLIST], 0 );
                    }
                }
        }

    // NAVILITE_SERVICETYPE_MCU_ESN_UPDATE_ACK
    if( navilite_packet.service_type == NAVILITE_SERVICETYPE_MCU_ESN_UPDATE_ACK )
        {
        if( navilite_content_update_callbacks.callback_func_esn_sent )
            {
            navilite_content_update_callbacks.callback_func_esn_sent();
            }

        // Once ESN is acked, the navilite session is established
        if( navilite_content_update_callbacks.callback_func_connected )
            {
            navilite_content_update_callbacks.callback_func_connected( 0 );
            }
        }

    // NAVILITE_SERVICETYPE_DIALOG_EVENT_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_DIALOG_EVENT_UPDATE )
        {
        uint8_t dialog_id;
        navilite_dialog_type dialog_type;
        uint8_t message_size;
        uint8_t timeout; // second
        uint8_t default_choice;
        int i = 0;

        dialog_id = (uint8_t)( data[idx++] );
        dialog_type = (uint8_t)( data[idx++] );
        message_size = (uint8_t)( data[idx++] );
        timeout = (uint8_t)( data[idx++] );
        default_choice = (uint8_t)( data[idx++] );
        // read the str size bytes for dialog text
        for ( i = 0; i < message_size; i++ )
            {
            navilite_buffer[i] = (uint8_t)data[idx++];
            }
        navilite_buffer[i++] = 0;

        if( navilite_content_update_callbacks.callback_func_dialogevent )
            {
            // Callback API for dialog prompt
            navilite_content_update_callbacks.callback_func_dialogevent( dialog_id, dialog_type, navilite_buffer, message_size, timeout, default_choice );
            }
        }

    // NAVILITE_SERVICETYPE_NAVIGATION_STATUS_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_NAVIGATION_STATUS_UPDATE )
        {
        uint16_t status = navilite_packet.data_value;

        if( navilite_content_update_callbacks.callback_func_navigationstatus )
            {
            // Callback API for navigation status notification update
            navilite_content_update_callbacks.callback_func_navigationstatus( status );
            // Update the session status for navigation status, used for blocking type API
            navilite_session_status.navigation_status = status;
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
    for( idx = 0; ( idx < data_len ) && is_jpeg_mode; idx++ )
        {
        if( jpg_current_size < NAVILITE_JPEG_BUFFER_MAX_SIZE )
            {
            navilite_jpg_buffer[jpg_current_size] = (uint8_t)data[idx];
            }

        if( ( ( ( image_frame_update_payload_size - 1 ) == jpg_current_size ) ) &&
            navilite_content_update_callbacks.callback_func_imageframe != NULL &&
            jpg_current_size <= NAVILITE_JPEG_BUFFER_MAX_SIZE )
            {
            navilite_ack_reply();
            navilite_content_update_callbacks.callback_func_imageframe( navilite_jpg_buffer, image_frame_update_payload_size, NAVILITE_IMAGE_NAVIGATION );
            is_jpeg_mode = 0;
            jpg_current_size = 0;
            break; // check if any left bytes in the MTU for non-jpeg data
            }

        if( ( ( ( image_frame_update_payload_size - 1 ) == jpg_current_size ) ) &&
            image_frame_update_payload_size > NAVILITE_JPEG_BUFFER_MAX_SIZE )
            {
            is_jpeg_mode = 0;
            image_frame_update_payload_size = 0;
            PRINTF( "WARNING: exceeds %d jpeg max buffer size, skip this jpeg image", image_frame_update_payload_size );
            navilite_ack_reply();
            }
        jpg_current_size++;
        }
    if( !is_jpeg_mode && ( data_len - idx - 1 ) > 0 )
        {
        navilite_extra_parse( &data[idx + 1], data_len - idx - 1 );
        }
    // Otherwise, the map frame update's payload data is parsing until next frame request!
    }
return is_jpeg_mode;
}

/*********************************************************************
*
* @private
* navilite_parse_data_inner
*
* Parse NAVILITE protocol for inner use
*
* @param data data pointer of NAVILITE protocol stream
* @param data_len data length of the data pointer received
* @return return true if jpeg mode is available
*                false if jpeg not available
*********************************************************************/
bool navilite_parse_data_inner
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

if( data_len >= 4 && strncmp( (char*)data , MAGIC_CODE, 4 ) == 0 )
    {
    // check connection
    if( navilite_session_status.inited == 0 &&
    navilite_content_update_callbacks.callback_func_connected )
        {
        navilite_session_status.inited = 1;
        navilite_content_update_callbacks.callback_func_connected( 0 );
        }

    // magic code
    idx += 4;

    // navilite version
    navilite_packet.version = data[idx++];
#if( NAVILITE_DEBUG )
    PRINTF( "\r\nversion:%d\r\n", navilite_packet.version );
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

    // NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE )
        {
        if( is_jpeg_mode == 0 )
            {
            image_frame_update_payload_size = navilite_packet.payload_size;
            is_jpeg_mode = 1;
            }
        jpg_current_size = 0;
        memcpy( navilite_jpg_buffer, data + idx, data_len - idx );
        jpg_current_size += ( data_len - idx );
        idx += ( data_len - idx );
        }

    // NAVILITE_SERVICETYPE_CURROADNAME_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_CURROADNAME_UPDATE )
        {
        // complete frame request contains ALL in one!!!
        memcpy( navilite_buffer, data + idx, data_len );
        idx += data_len;
        navilite_buffer[idx] = 0;

        if( navilite_content_update_callbacks.callback_func_currentroadname )
            {
            // Callback API for RoadName notification update
            navilite_content_update_callbacks.callback_func_currentroadname( navilite_buffer, navilite_packet.payload_size );
            }
        }
    else if( navilite_packet.payload_size == 0 && navilite_content_update_callbacks.callback_func_currentroadname )
        {
            // Used for clearing the road name on HMI
            navilite_content_update_callbacks.callback_func_currentroadname( NULL, 0 );
        }

    // NAVILITE_SERVICETYPE_ETA_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_ETA_UPDATE )
        {
        uint32_t value = (uint32_t)( ( data[idx + 3] << 24 ) | ( data[idx + 2] << 16 ) | ( data[idx + 1] << 8 ) | ( data[idx + 0] << 0 ) );

        if( navilite_content_update_callbacks.callback_func_eta )
            {
            // Callback API for ETA notification update
            navilite_content_update_callbacks.callback_func_eta( value );
            }
        }

    // NAVILITE_SERVICETYPE_BT_THROUGHPUT_TIMEOUT_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_BT_THROUGHPUT_TIMEOUT_UPDATE )
        {
        uint8_t value = navilite_packet.data_value; // this value will be calculated in HMI for proper absolute time

        if( navilite_content_update_callbacks.callback_func_bt_timeout )
            {
            // Callback API for BT timeout notification update
            navilite_content_update_callbacks.callback_func_bt_timeout( value );
            }
        }

    // NAVILITE_SERVICETYPE_ROUTE_CALC_PROGRESS_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_ROUTE_CALC_PROGRESS_UPDATE )
        {
        uint8_t progress = 0;
        progress = (uint8_t)navilite_packet.data_value;

        if( navilite_content_update_callbacks.callback_func_routecalcprogress )
            {
            navilite_content_update_callbacks.callback_func_routecalcprogress( progress );
            }
        }

    // NAVILITE_SERVICETYPE_DAYNIGHT_MODE_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_DAYNIGHT_MODE_UPDATE )
        {
        uint8_t mode = 0;
        mode = (uint8_t)navilite_packet.data_value;

        if( navilite_content_update_callbacks.callback_func_daynightmode )
            {
            navilite_content_update_callbacks.callback_func_daynightmode( mode );
            }
        }

    // NAVILITE_SERVICETYPE_MAP_ZOOM_LEVEL_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_MAP_ZOOM_LEVEL_UPDATE )
        {
        uint8_t currentLevel = 0;
        uint8_t maxLevel = 0;

        currentLevel = (uint8_t)data[idx++];
        maxLevel = (uint8_t)data[idx++];

        if( navilite_content_update_callbacks.callback_func_zoomlevel )
            {
            // Callback API for zoom level update
            navilite_content_update_callbacks.callback_func_zoomlevel( currentLevel, maxLevel );
            }
        }

    // NAVILITE_SERVICETYPE_HOMESETTING_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_HOMESETTING_UPDATE )
        {
        uint8_t value = navilite_packet.data_value;

        if( navilite_content_update_callbacks.callback_func_homelocationsetting )
            {
            // Callback API for home setting notification update
            navilite_content_update_callbacks.callback_func_homelocationsetting( value );
            // Update the session status for home setting status, used for blocking type API
            navilite_session_status.home_status = value;
            }
        }

    // NAVILITE_SERVICETYPE_OFFICESETTING_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_OFFICESETTING_UPDATE )
        {
        uint8_t setting_value = navilite_packet.data_value;

        if( navilite_content_update_callbacks.callback_func_officelocationsetting )
            {
            // Callback API for home setting notification update
            navilite_content_update_callbacks.callback_func_officelocationsetting( setting_value );
            // Update the session status for office setting status, used for blocking type API
            navilite_session_status.office_status = setting_value;
            }
        }

    // NAVILITE_SERVICETYPE_VIA_POINT_COUNT_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_VIA_POINT_COUNT_UPDATE )
        {
        uint8_t value = navilite_packet.data_value;

        if( navilite_content_update_callbacks.callback_func_viapointcount )
            {
            // Callback API for via point count notification update
            navilite_content_update_callbacks.callback_func_viapointcount( value );
            }
        }

    // NAVILITE_SERVICETYPE_SPEED_LIMIT_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_SPEED_LIMIT_UPDATE )
        {
        uint16_t value = navilite_packet.data_value;

        if( navilite_content_update_callbacks.callback_func_speedlimit )
            {
            // Callback API for speed limit notification update
            navilite_content_update_callbacks.callback_func_speedlimit( value );
            }
        }

    // NAVILITE_SERVICETYPE_NAVIEVENTTEXTUPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_NAVIEVENTTEXTUPDATE )
        {
        uint8_t event_type;
        uint8_t event_extra_subtype;
        uint8_t visibilty;
        uint8_t event_str_size;
        int i = 0;
        // parsing the navi text packet
        // read one byte for event type
        event_type = (uint8_t)data[idx++];
        // read one byte for extra subtype
        event_extra_subtype = (uint8_t)data[idx++];
        // read one byte for visibility
        visibilty = (uint8_t)data[idx++];
        // read one byte for navi text string size
        event_str_size = (uint8_t)data[idx++];
        // read the str size bytes for navi text
        for ( i = 0; i < event_str_size; i++ )
            {
            navilite_buffer[i] = (uint8_t)data[idx++];
            }
        navilite_buffer[i++] = 0; // store the navi text on navilite buffer
        if( navilite_content_update_callbacks.callback_func_navieventtext )
            {
            // Callback API for navi event text notification update
            navilite_content_update_callbacks.callback_func_navieventtext( (uint8_t*)navilite_buffer, event_str_size, event_type, event_extra_subtype, visibilty );
            }
        }

    // NAVILITE_SERVICETYPE_NEXTTURNDIST_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_NEXTTURNDIST_UPDATE )
        {
        uint8_t icon_index = 0;
        uint32_t distance = 0;
        uint8_t dist_unit_str_size = 0;

        int i = 0;
        // parsing the icon index
        // read one byte for icon index
        icon_index = (uint8_t)data[idx++];
        // distance
        distance = (uint32_t)( ( data[idx + 3] << 24 ) | ( data[idx + 2] << 16 ) | ( data[idx + 1] << 8 ) | ( data[idx + 0] << 0 ) );
        idx+=4;
        // unit string size
        dist_unit_str_size = (uint8_t)data[idx++];

        // read the str bytes for distance
        for ( i = 0; i < dist_unit_str_size; i++ )
            {
            navilite_buffer[i] = (uint8_t)data[idx++];
            }
        navilite_buffer[i++] = 0; // store the navi text on navilite buffer
        if( navilite_content_update_callbacks.callback_func_nextturndistance )
            {
            // Callback API for next turn distance notification update
            navilite_content_update_callbacks.callback_func_nextturndistance( icon_index, distance, (uint8_t*)navilite_buffer, dist_unit_str_size );
            }
        }

    // NAVILITE_SERVICETYPE_ACTIVETURBLIST_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_ACTIVETURBLIST_UPDATE )
        {
        uint16_t active_tbt_index = 0; // app will inform current active tbt list to let HMI know what tbt list should be shown
        active_tbt_index = (uint16_t)navilite_packet.data_value;
        // fire callback when available
        if( navilite_content_update_callbacks.callback_func_activetbtitem )
            {
            // Callback API for next turn distance notification update
            navilite_content_update_callbacks.callback_func_activetbtitem( active_tbt_index );
            }
        }

    // NAVILITE_SERVICETYPE_TBTLIST_UPDATE  (list SIZE/hasMoreData notify)
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_TBTLIST_UPDATE )
        {
        uint16_t list_item_count = 0;
        uint8_t has_more_items = 0;
        // list item count extraction
        for( ; idx < data_len; idx++ )
            {
            list_item_count = (uint16_t)( ( data[idx + 1] << 8 ) | ( data[idx + 0] << 0 ) );
            // has more data in next request for UI to show more data on item lists(> 50);
            idx += 2;
            has_more_items = data[idx++];
            }
        session_list_size_total[NAVILITE_SESSION_INDEX_TBTLIST] = list_item_count;
        session_list_item_counter[NAVILITE_SESSION_INDEX_TBTLIST] = 0; // reset the counter when this command is received
        PRINTF( "[NAVILITE_BEGIN TBT LIST ITEM SIZE: %d, reset session_tbtlist_item_counter = 0]\r\n", session_list_size_total[NAVILITE_SESSION_INDEX_TBTLIST] );

        if( session_list_size_last_total[NAVILITE_SESSION_INDEX_TBTLIST] != session_list_size_counter[NAVILITE_SESSION_INDEX_TBTLIST] )
            {
            session_list_size_last_total[NAVILITE_SESSION_INDEX_TBTLIST] = session_list_size_total[NAVILITE_SESSION_INDEX_TBTLIST];
            PRINTF( "#WARNING: previous tbtlist is not completely received! SHOULD HAVE %d lists but only %d lists received\r\n", session_list_size_last_total[NAVILITE_SESSION_INDEX_TBTLIST], session_list_size_counter[NAVILITE_SESSION_INDEX_TBTLIST] );
            }
        if( navilite_content_update_callbacks.callback_func_nexttbtist )
            {
            navilite_content_update_callbacks.callback_func_nexttbtist
                (
                NAVILITE_TBTLIST_ACTION_LISTSIZE,
                NULL,
                0,
                session_list_size_total[NAVILITE_SESSION_INDEX_TBTLIST],  // total items will be updated later by NAVILITE_SERVICETYPE_TBTLIST_DATA_UPDATE
                0,
                has_more_items // has more item on next request?
                );
            }
        }

    // NAVILITE_SERVICETYPE_TBTLIST_DATA_UPDATE  // list item data notify
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_TBTLIST_DATA_UPDATE )
        {

        if( session_list_size_total[NAVILITE_SESSION_INDEX_TBTLIST] == 0 )
            {
            PRINTF( "#ERROR: session_tbtlist_size_total = 0 ; NAVILITE_SERVICETYPE_TBTLIST_UPDATE request need to be issued first from app!\r\n" );
            }

            session_list_size_counter[NAVILITE_SESSION_INDEX_TBTLIST]++;
            uint16_t list_item_index = 0;
            uint8_t icon_index = 0;
            uint8_t desc_str_size;
            uint8_t dist_unit_str_size;
            uint32_t distance = 0;
            uint8_t* desc_str = NULL;
            uint8_t* dist_unit_str = NULL;

            for( ; idx < data_len; idx++ )
                {
                // list index
                list_item_index = (uint16_t)( ( data[idx + 1] << 8 ) | ( data[idx + 0] << 0 ) );
                idx += 2;
                // icon index
                icon_index = (uint8_t)data[idx++];
                // desc_size
                desc_str_size = (uint8_t)data[idx++];
                // dist_unit_size;
                dist_unit_str_size = (uint8_t)data[idx++];
                // distance
                distance = (uint32_t)( ( data[idx + 3] << 24 ) | ( data[idx + 2] << 16 ) | ( data[idx + 1] << 8 ) | ( data[idx + 0] << 0 ) );
                idx += sizeof( distance ); // now point to distance unit string portion
                // store the distance unit string
                dist_unit_str = navilite_buffer;
                // copy the unit string to buffer
                memcpy( navilite_buffer, data + idx, dist_unit_str_size );
                idx += dist_unit_str_size;
                // store the desc string pointer
                desc_str = navilite_buffer + idx;
                // copy the desc string to buffer
                memcpy( navilite_buffer + idx, data + idx , desc_str_size );
                idx += data_len;
                if( navilite_content_update_callbacks.callback_func_nexttbtist )
                    {
                    // prepare list item data
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_TBTLIST].list_item_index = list_item_index;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_TBTLIST].icon_index = icon_index;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_TBTLIST].desc_size = desc_str_size;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_TBTLIST].dist_unit_size = dist_unit_str_size;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_TBTLIST].distance = distance;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_TBTLIST].distance_unit = dist_unit_str;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_TBTLIST].desc = desc_str;
                    // Callback API for turn by turn list update and increase the session_tbtlist_item_counter from 0
                    navilite_content_update_callbacks.callback_func_nexttbtist( NAVILITE_TBTLIST_ACTION_ITEMADD, &session_tbt_list_data[NAVILITE_SESSION_INDEX_TBTLIST], list_item_index, session_list_size_total[NAVILITE_SESSION_INDEX_TBTLIST], ++session_list_item_counter[NAVILITE_SESSION_INDEX_TBTLIST], 0 );
                    }
                }
        }

    // NAVILITE_SERVICETYPE_FAVPOILIST_UPDATE  // list SIZE notify
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_FAVPOILIST_UPDATE )
        {
        // list item count
        uint16_t list_item_count = (uint16_t)( ( data[idx + 1] << 8 ) | ( data[idx + 0] << 0 ) );
        idx += 3;
        // has more data in next request for UI to show more data on item lists(> 50)
        uint8_t has_more_items = data[idx];
        session_list_size_total[NAVILITE_SESSION_INDEX_FAVLIST] = list_item_count;
        session_list_item_counter[NAVILITE_SESSION_INDEX_FAVLIST] = 0; // reset the counter when this command is received
        PRINTF( "[NAVILITE_BEGIN FAV LIST ITEM SIZE: %d, reset session_list_item_counter[NAVILITE_SESSION_INDEX_FAVLIST] = 0]\r\n", session_list_size_total[NAVILITE_SESSION_INDEX_FAVLIST] );

        if( session_list_size_last_total[NAVILITE_SESSION_INDEX_FAVLIST] != session_list_size_counter[NAVILITE_SESSION_INDEX_FAVLIST] )
            {
            session_list_size_last_total[NAVILITE_SESSION_INDEX_FAVLIST] = session_list_size_total[NAVILITE_SESSION_INDEX_FAVLIST];
            PRINTF( "#WARNING: previous fav list is not completely received! SHOULD HAVE %d lists but only %d lists received\r\n", session_list_size_last_total[NAVILITE_SESSION_INDEX_FAVLIST], session_list_size_counter[NAVILITE_SESSION_INDEX_FAVLIST] );
            }
        if( navilite_content_update_callbacks.callback_func_nextfavlist )
            {
            navilite_content_update_callbacks.callback_func_nextfavlist
                (
                NAVILITE_POILIST_ACTION_LISTSIZE,
                NULL,
                0,
                session_list_size_total[NAVILITE_SESSION_INDEX_FAVLIST],  // total items will be updated later by NAVILITE_SERVICETYPE_TBTLIST_DATA_UPDATE
                0,
                has_more_items // has more item on next request?
                );
            }
        }

    // NAVILITE_SERVICETYPE_FAVLIST_DATA_UPDATE  // list item data notify
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_FAVPOILIST_DATA_UPDATE )
        {

        if( session_list_size_total[NAVILITE_SESSION_INDEX_FAVLIST] == 0 )
            {
            PRINTF( "#ERROR: session_list_size_total[NAVILITE_SESSION_INDEX_FAVLIST] = 0 ; NAVILITE_SERVICETYPE_FAVLIST_UPDATE request need to be issued first from app!\r\n" );
            }

            session_list_size_counter[NAVILITE_SESSION_INDEX_FAVLIST]++;
            uint32_t list_item_index = 0;
            uint8_t desc_str_size;
            uint8_t dist_unit_str_size;
            uint32_t distance = 0;
            uint8_t* desc_str = NULL;
            uint8_t* dist_unit_str = NULL;

            for( ; idx < data_len; idx++ )
                {
                // list index
                list_item_index = (uint32_t)( ( data[idx + 3] << 24 ) | ( data[idx + 2] << 16 ) | ( data[idx + 1] << 8 ) | ( data[idx + 0] << 0 ) );
                idx += sizeof( list_item_index );
                desc_str_size = (uint8_t)data[idx++];
                // dist_unit_size;
                dist_unit_str_size = (uint8_t)data[idx++];
                // distance
                distance = (uint32_t)( ( data[idx + 3] << 24 ) | ( data[idx + 2] << 16 ) | ( data[idx + 1] << 8 ) | ( data[idx + 0] << 0 ) );
                idx += sizeof( distance ); // now point to distance unit string portion
                // store the distance unit string
                dist_unit_str = navilite_buffer;
                // copy the unit string to buffer
                memcpy( navilite_buffer, data + idx, dist_unit_str_size );
                idx += dist_unit_str_size;
                // store the desc string pointer
                desc_str = navilite_buffer + idx;
                // copy the desc string to buffer
                memcpy( navilite_buffer + idx, data + idx, desc_str_size );
                idx += data_len;
                if( navilite_content_update_callbacks.callback_func_nexttbtist )
                    {
                    // prepare list item data
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_FAVLIST].list_item_index = list_item_index;
                    // session_list_data_ptr[NAVILITE_SESSION_INDEX_FAVLIST].icon_index = icon_index;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_FAVLIST].desc_size = desc_str_size;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_FAVLIST].dist_unit_size = dist_unit_str_size;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_FAVLIST].distance = distance;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_FAVLIST].distance_unit = dist_unit_str;
                    session_tbt_list_data[NAVILITE_SESSION_INDEX_FAVLIST].desc = desc_str;
                    // Callback API for turn by turn list update and increase the session_tbtlist_item_counter from 0
                    navilite_content_update_callbacks.callback_func_nextfavlist( NAVILITE_POILIST_ACTION_ITEMADD, &session_poi_list_data[NAVILITE_SESSION_INDEX_FAVLIST], list_item_index, session_list_size_total[NAVILITE_SESSION_INDEX_FAVLIST], ++session_list_item_counter[NAVILITE_SESSION_INDEX_FAVLIST], 0 );
                    }
                }
        }

    // NAVILITE_SERVICETYPE_MCU_ESN_UPDATE_ACK
    if( navilite_packet.service_type == NAVILITE_SERVICETYPE_MCU_ESN_UPDATE_ACK )
        {
        if( navilite_content_update_callbacks.callback_func_esn_sent )
            {
            navilite_content_update_callbacks.callback_func_esn_sent();
            }

        // Once ESN is acked, the navilite session is established
        if( navilite_content_update_callbacks.callback_func_connected )
            {
            navilite_content_update_callbacks.callback_func_connected( 0 );
            }
        }

    // NAVILITE_SERVICETYPE_DIALOG_EVENT_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_DIALOG_EVENT_UPDATE )
        {
        uint8_t dialog_id;
        navilite_dialog_type dialog_type;
        uint8_t message_size;
        uint8_t timeout; // second
        uint8_t default_choice;

        int i = 0;

        dialog_id = (uint8_t)( data[idx++] );
        dialog_type = (uint8_t)( data[idx++] );
        message_size = (uint8_t)( data[idx++] );
        timeout = (uint8_t)( data[idx++] );
        default_choice = (uint8_t)( data[idx++] );
        // read the str size bytes for dialog text
        for ( i = 0; i < message_size; i++ )
            {
            navilite_buffer[i] = (uint8_t)data[idx++];
            }
        navilite_buffer[i++] = 0;

        if( navilite_content_update_callbacks.callback_func_dialogevent )
            {
            // Callback API for dialog prompt
            navilite_content_update_callbacks.callback_func_dialogevent( dialog_id, dialog_type, navilite_buffer, message_size, timeout, default_choice );
            }
        }

    // NAVILITE_SERVICETYPE_NAVIGATION_STATUS_UPDATE
    if( navilite_packet.payload_size > 0 && navilite_packet.service_type == NAVILITE_SERVICETYPE_NAVIGATION_STATUS_UPDATE )
        {
        uint16_t status = navilite_packet.data_value;

        if( navilite_content_update_callbacks.callback_func_navigationstatus )
            {
            // Callback API for navigation status notification update
            navilite_content_update_callbacks.callback_func_navigationstatus( status );
            // Update the session status for navigation status, used for blocking type API
            navilite_session_status.navigation_status = status;
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
    for( idx = 0; ( idx < data_len ) && is_jpeg_mode; idx++ )
        {
        if( jpg_current_size < NAVILITE_JPEG_BUFFER_MAX_SIZE )
            {
            navilite_jpg_buffer[jpg_current_size] = (uint8_t)data[idx];
            }

        if( ( ( ( image_frame_update_payload_size - 1 ) == jpg_current_size ) ) &&
            navilite_content_update_callbacks.callback_func_imageframe != NULL &&
            jpg_current_size <= NAVILITE_JPEG_BUFFER_MAX_SIZE )
            {
            navilite_ack_reply();
            navilite_content_update_callbacks.callback_func_imageframe( navilite_jpg_buffer, image_frame_update_payload_size, NAVILITE_IMAGE_NAVIGATION );
            is_jpeg_mode = 0;
            jpg_current_size = 0;
            break; // check if any left bytes in the MTU for non-jpeg data
            }

        if( ( ( ( image_frame_update_payload_size - 1 ) == jpg_current_size ) ) &&
            image_frame_update_payload_size > NAVILITE_JPEG_BUFFER_MAX_SIZE )
            {
            is_jpeg_mode = 0;
            image_frame_update_payload_size = 0;
            PRINTF( "WARNING: exceeds %d jpeg max buffer size, skip this jpeg image", image_frame_update_payload_size );
            navilite_ack_reply();
            }
        jpg_current_size++;
        }
   }
return is_jpeg_mode;
}
