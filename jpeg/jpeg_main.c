/*********************************************************************
* @file
* jpeg_main.c
*
* @brief
* JPEG module
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "semphr.h"
#include "ewrte.h"
#include "ewconfig.h"
#include "fsl_debug_console.h"
#include "fsl_common.h"
#include "jpeglib.h"
#include "JPEG_pub.h"
#include "jpeg_priv.h"
#include "GRM_pub_prj.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define JPEG_TASK_STACK_SIZE ( configMINIMAL_STACK_SIZE * 6 )
#define JPEG_TASK_NAME       "jpeg_task"

#define EVENT_JPEG_DATA_RECEIVED ( 1 << 0 )

#define BYTE_PER_PIXEL      ( 3 )
#define DEFAULT_SCALE_NUM   ( 8 )

#define JPEG_BUFFER_SIZE_BYTE ( 64 * 1024 )
#define JPEG_BUFFER_NUM       ( 2 )
#define JPEG_WIDTH_MAX        ( 480 )
#define JPEG_HEIGHT_MAX       ( 234 )
#define RGB_BUFFER_SIZE_BYTE  ( JPEG_WIDTH_MAX * JPEG_HEIGHT_MAX * BYTE_PER_PIXEL )
#define RGB_BUF_TAKE_SEMAPHORE_TIMEOUT_MS ( 1000 )

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef struct
{
uint32_t    size_byte;     /**< JPEG size (byte) */
buffer_info buf_info; /**< JPEG buffer info */
void        ( *callback_func_ptr ) ( int ); /**< callback function when JPEG decode is finished */
} jpeg_object;

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
static EventGroupHandle_t event_group = NULL;
static jpeg_object jpeg_objs[JPEG_BUFFER_NUM];
static buffer_info rgb_buf_info;
static SemaphoreHandle_t rgb_buf_semaphore;
static int writing_buffer_idx = 0;
static QueueHandle_t queue_written_buffer;

AT_NONCACHEABLE_SECTION_ALIGN( uint8_t jpeg_buffer[JPEG_BUFFER_NUM * JPEG_BUFFER_SIZE_BYTE], 32 );
AT_NONCACHEABLE_SECTION_ALIGN( uint8_t rgb_buffer[RGB_BUFFER_SIZE_BYTE], 32 );

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* decode_with_libjpeg
*
* JPEG decode with libjpeg
*
* @param jpeg_obj jpeg info structure
* @return The result of JPEG decode with libjpeg.
*
*********************************************************************/
static int decode_with_libjpeg
    (
    jpeg_object* jpeg_obj
    )
{
static struct jpeg_decompress_struct cinfo;
static struct jpeg_error_mgr jerr;
uint8_t*      jpg_buffer_aligned;
uint8_t*      rgb_buffer = rgb_buf_info.addr;
JSAMPROW      row_pointer[1] = {0}; /* Output row rgb_buffer */
uint32_t      row_stride     = 0;   /* physical row width in image rgb_buffer */
int           result = RESULT_SUCCESS;
uint32_t      start_tick = xTaskGetTickCount();

cinfo.err = jpeg_std_error( &jerr );
jpeg_create_decompress( &cinfo );

jpg_buffer_aligned = ( uint8_t* ) jpeg_obj->buf_info.addr;
jpeg_mem_src( &cinfo, jpg_buffer_aligned, jpeg_obj->size_byte );

jpeg_read_header( &cinfo, true );
if( JPEG_WIDTH_MAX  >= cinfo.image_width  && 0 < cinfo.image_width &&
    JPEG_HEIGHT_MAX >= cinfo.image_height && 0 < cinfo.image_height )
    {
    jpeg_obj->buf_info.image_width  = cinfo.image_width;
    jpeg_obj->buf_info.image_height = cinfo.image_height;

    cinfo.dct_method = JDCT_FLOAT;
    cinfo.scale_num = 8;

    jpeg_start_decompress( &cinfo );

    row_stride = cinfo.image_width * BYTE_PER_PIXEL;

    while( cinfo.output_scanline < cinfo.output_height )
        {
        row_pointer[0] = &rgb_buffer[cinfo.output_scanline * row_stride];
        jpeg_read_scanlines( &cinfo, row_pointer, 1 );
        }

    jpeg_finish_decompress( &cinfo );
    jpeg_destroy_decompress( &cinfo );

    PRINTF( "decode jpg %d ms\r\n", ( xTaskGetTickCount() - start_tick ) );
    }
else
    {
    PRINTF( "%s: size (%d, %d) err\r\n", __FUNCTION__, cinfo.image_width, cinfo.image_height );
    result = RESULT_ERR;
    }
return result;
}

/*********************************************************************
*
* @private
* jpeg_decode_proc
*
* Decode JPEG when RGB buffer is available
*
* @param buffer_idx The index to the buffer with JPEG data
*
* @return The result of JPEG decode.
* @retval RESULT_SUCCESS if JPEG decode sucesses.
* @retval RESULT_ERR_BUFFER_NOT_AVAILABLE if RGB buffer is occupied
*
*********************************************************************/
static int jpeg_decode_proc
    (
    int buffer_idx
    )
{
JPEG_PRINTF( "%s, buf idx %d\r\n", __FUNCTION__, buffer_idx );
int result = RESULT_SUCCESS;
jpeg_object* jpeg_obj = &jpeg_objs[buffer_idx];

if( NULL != rgb_buf_semaphore )
    {
    if( pdTRUE == xSemaphoreTake( rgb_buf_semaphore, RGB_BUF_TAKE_SEMAPHORE_TIMEOUT_MS ) )
        {
        result = decode_with_libjpeg( jpeg_obj );
        if( RESULT_SUCCESS == result )
            {
            rgb_buf_info.image_width  = jpeg_obj->buf_info.image_width;
            rgb_buf_info.image_height = jpeg_obj->buf_info.image_height;
            rgb_buf_info.is_buffer_available = false;
            }
        xSemaphoreGive( rgb_buf_semaphore );
        }
    else
        {
        result = RESULT_ERR_BUFFER_NOT_AVAILABLE;
        PRINTF( "rgb buf not available\r\n" );
        }
    }

jpeg_obj->callback_func_ptr( result );
jpeg_obj->buf_info.is_buffer_available = true;
return result;
}

/*********************************************************************
*
* @private
* task_main
*
* Main loop of the jpeg task
*
*********************************************************************/
static void task_main
    (
    void* arg
    )
{
EventBits_t event_bits;
int         buffer_idx;

while( true )
    {
    event_bits = xEventGroupWaitBits
                    (
                    event_group,    /* The event group handle. */
                    EVENT_JPEG_DATA_RECEIVED,
                    pdTRUE,         /* clear on exit */
                    pdFALSE,        /* Don't wait for both bits, either bit unblock task. */
                    portMAX_DELAY   /* Block indefinitely to wait for the condition to be met. */
                    );

    if( EVENT_JPEG_DATA_RECEIVED == ( event_bits & EVENT_JPEG_DATA_RECEIVED ) )
        {
        while( pdPASS == xQueueReceive( queue_written_buffer, &buffer_idx, 0 ) )
            {
            jpeg_decode_proc( buffer_idx );
            if( 0 < uxQueueMessagesWaiting( queue_written_buffer ) )
                {
                // rgb buffer is occupied, wait 50ms for Embedded Wizard loading to UI and release rgb buffer
                vTaskDelay( pdMS_TO_TICKS( 50 ) );
                }
            }
        }
    }

vTaskDelete( NULL );
}

/*********************************************************************
*
* @private
* create_task
*
* Create jpeg task
*
*********************************************************************/
static void create_task
    (
    void
    )
{
event_group = xEventGroupCreate();
BaseType_t result = xTaskCreate( task_main, JPEG_TASK_NAME, JPEG_TASK_STACK_SIZE, NULL, TASK_PRIO_JPEG, NULL );
configASSERT( pdPASS == result );
}

/*********************************************************************
*
* @private
* create_written_buffer_idx_queue
*
* Create a queue to keep the index of written buffers
*
*********************************************************************/
static void create_written_buffer_idx_queue
    (
    void
    )
{
queue_written_buffer = xQueueCreate( JPEG_BUFFER_NUM, sizeof( int ) );
configASSERT( NULL != queue_written_buffer );
}

/*********************************************************************
*
* @public
* JPEG_init
*
* JPEG module initialization
*
* @return The result of JPEG module initialization.
*
*********************************************************************/
void JPEG_init
    (
    void
    )
{
for( int i = 0; i < JPEG_BUFFER_NUM; i++ )
    {
    jpeg_objs[i].buf_info.is_buffer_available = true;
    jpeg_objs[i].buf_info.buffer_size         = JPEG_BUFFER_SIZE_BYTE;
    jpeg_objs[i].buf_info.addr                = (void*)( jpeg_buffer + i * JPEG_BUFFER_SIZE_BYTE );
    }

memset( &rgb_buf_info, 0, sizeof( rgb_buf_info ) );
rgb_buf_info.is_buffer_available = true;
rgb_buf_info.buffer_size         = RGB_BUFFER_SIZE_BYTE;
rgb_buf_info.addr                = ( void* ) rgb_buffer;

rgb_buf_semaphore = xSemaphoreCreateBinary();
configASSERT( NULL != rgb_buf_semaphore );
xSemaphoreGive( rgb_buf_semaphore );

create_written_buffer_idx_queue();
create_task();
}

/*********************************************************************
*
* @public
* JPEG_get_jpeg_buffer
*
* Return the address to the available JPEG buffer
*
* @return the address to the available JPEG buffer if available
* @retval non-zero value, buffer address
* @retval null, no availabe buffer
*
*********************************************************************/
uint8_t* JPEG_get_jpeg_buffer
    (
    void
    )
{
uint8_t* buffer_addr = NULL;

if( jpeg_objs[writing_buffer_idx].buf_info.is_buffer_available )
    {
    buffer_addr = jpeg_objs[writing_buffer_idx].buf_info.addr;
    jpeg_objs[writing_buffer_idx].buf_info.is_buffer_available = false;

    writing_buffer_idx++;
    if( writing_buffer_idx >= JPEG_BUFFER_NUM )
        {
        writing_buffer_idx = 0;
        }
    }

return buffer_addr;
}

/*********************************************************************
*
* @public
* JPEG_get_jpeg_buffer_size
*
* Get the size of JPEG buffer.
*
* @return size of the JPEG buffer in byte.
*********************************************************************/
uint32_t JPEG_get_jpeg_buffer_size
    (
    void
    )
{
return JPEG_BUFFER_SIZE_BYTE;
}

/*********************************************************************
*
* @public
* JPEG_is_valid
*
* Simple check if data content is valid JPEG format with less effort
* @param data data pointer of image
* @param size size of image
* @return true if data content is valid JPEG format
*         false if not valid JPEG format
*********************************************************************/
bool JPEG_is_valid
    (
    uint8_t* data,
    uint16_t size
    )
{
int soi_check =  ( data[0] == 0xff && data[1] == 0xd8 );
int eoi_check = ( data[size - 2] == 0xff && data[size - 1] == 0xd9 );
return ( soi_check && eoi_check );
}

/*********************************************************************
*
* @public
* JPEG_notify_received
*
* Notify jpeg task when JPEG data is ready in the JPEG buffer.
*
* @param jpeg_size_byte JPEG size in byte
* @param buffer_addr address of the JPEG buffer with data
* @param *callback_func_ptr The pointer of the function to call after decode is finished
*
*********************************************************************/
void JPEG_notify_received
    (
    uint32_t jpeg_size_byte,
    uint8_t* buffer_addr,
    void     ( *callback_func_ptr )( int )
    )
{
JPEG_PRINTF( "%s, 0x%x\r\n", __FUNCTION__, buffer_addr );
configASSERT( NULL != callback_func_ptr );

for( int i = 0; i < JPEG_BUFFER_NUM; i++ )
    {
    if( jpeg_objs[i].buf_info.addr == buffer_addr )
        {
        jpeg_objs[i].size_byte = jpeg_size_byte;
        jpeg_objs[i].callback_func_ptr = callback_func_ptr;
        if( pdTRUE == xQueueSend( queue_written_buffer, &i, 0 ) )
            {
            xEventGroupSetBits( event_group, EVENT_JPEG_DATA_RECEIVED );
            }
        else
            {
            PRINTF( "JPEG xQueueSend err\r\n" );
            }
        break;
        }
    }
}

/*********************************************************************
*
* @public
* JPEG_notify_rgb_loaded
*
* Notify jpeg task when UI loaded RGB data from the RGB buffer.
*
*********************************************************************/
void JPEG_notify_rgb_loaded
    (
    void
    )
{
rgb_buf_info.is_buffer_available = true;
}

/*********************************************************************
*
* @public
* JPEG_take_rgb
*
* Take RGB buffer without waiting for the semaphore
*
* @retVal The pointer to the RGB buffer handle if not occupied.
* @retVal NULL if the RGB buffer is occupied.
*
*********************************************************************/
buffer_info* JPEG_take_rgb
    (
    void
    )
{
buffer_info* get_rgb_buffer_handle = NULL;
if( pdTRUE == xSemaphoreTake( rgb_buf_semaphore, 0 ) )
    {
    get_rgb_buffer_handle = &rgb_buf_info;
    }
JPEG_PRINTF( "%s 0x%x\r\n", __FUNCTION__, get_rgb_buffer_handle );
return get_rgb_buffer_handle;
}

/*********************************************************************
*
* @public
* JPEG_give_rgb
*
* Give RGB buffer
*
*********************************************************************/
void JPEG_give_rgb
    (
    void
    )
{
JPEG_PRINTF( "%s\r\n", __FUNCTION__ );
xSemaphoreGive( rgb_buf_semaphore );
}

/*********************************************************************
*
* @public
* JPEG_is_rgb_ready
*
* Get RGB data.
*
* @return True if rgb data is ready. False if no rgb data.
*********************************************************************/
bool JPEG_is_rgb_ready
    (
    void
    )
{
return !rgb_buf_info.is_buffer_available;
}

