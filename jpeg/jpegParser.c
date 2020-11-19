
/*******************************************************************************
*@ File jpegParser.c
*@ Brief Jpeg Parser
*
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
********************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "JPEGPARSER_pub.h"
#include "FreeRTOS.h"
#include "task.h"
#include "fsl_debug_console.h"
#include "JPEG_pub.h"
#include "NAVI_pub.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

#define ESCAPE_CODE ( 0xFF )
/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/


/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef enum
    {
    JPEG_RX_STATE_IDLE,
    JPEG_RX_STATE_STARTED,
    JPEG_RX_STATE_BUF_OVER
    } jpeg_rx_state_type;

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/


/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
static uint8_t*         jpeg_data = NULL;
static uint32_t         jpeg_buffer_size = 0;
static uint32_t         jpeg_idx = 0;
static jpeg_rx_state_type jpeg_rx_state = JPEG_RX_STATE_IDLE;

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/


/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/

static inline void parseJpegSerData
    (
    uint8_t const data
    );

/*================================================================================================*/
/**
@brief   parseJpegSerData
@details

@return None
@retval None

@pre None
@post None
*/
/*================================================================================================*/
static inline void parseJpegSerData
    (
    uint8_t const data
    )
{
static uint8_t  curr_data = 0;
static uint8_t  prev_data = 0;
static bool     isJpegBufAvailable = false;
static uint32_t start_tick = 0;

curr_data = data;

if( JPEG_RX_STATE_STARTED == jpeg_rx_state &&
    isJpegBufAvailable )
    {
    jpeg_data[jpeg_idx] = data;
    }

if( ( curr_data == 0xD9 ) && ( prev_data == ESCAPE_CODE ) )
    {
    PRINTF( "Done, %d ms, size: %d\r\n\n", ( xTaskGetTickCount() - start_tick ), jpeg_idx );

    switch( jpeg_rx_state )
        {
        case JPEG_RX_STATE_STARTED:
            if( isJpegBufAvailable )
                {
                NAVI_jpeg_data_received( jpeg_idx + 1, jpeg_data );
                }
            else
                {
                PRINTF( "drop jpeg (no buf)\r\n" );
                }
            jpeg_rx_state = JPEG_RX_STATE_IDLE;
            break;

        case JPEG_RX_STATE_BUF_OVER:
            PRINTF( "drop jpeg (buf over)\r\n" );
            break;

        default:
            PRINTF( "invalid jpeg rx state: %d\r\n", jpeg_rx_state );
            break;
        }

    curr_data = 0;
    prev_data = 0;
    jpeg_idx = 0;
    }
else
    {
    if( ( curr_data == 0xD8 ) && ( prev_data == ESCAPE_CODE ) )
        {
        start_tick = xTaskGetTickCount();
        PRINTF( "Start, %d\r\n", start_tick );

        if( JPEG_RX_STATE_IDLE == jpeg_rx_state )
            {
            jpeg_data = JPEG_get_jpeg_buffer();
            jpeg_buffer_size = JPEG_get_jpeg_buffer_size();
            jpeg_rx_state = JPEG_RX_STATE_STARTED;
            }
        else if( JPEG_RX_STATE_STARTED == jpeg_rx_state )
            {
            PRINTF( "already in start state, reuse jpeg buf\r\n" );
            }
        else if( JPEG_RX_STATE_BUF_OVER == jpeg_rx_state )
            {
            if( NULL != jpeg_data )
                {
                PRINTF( "buf over, reuse jpeg buf\r\n" );
                }
            else
                {
                jpeg_data = JPEG_get_jpeg_buffer();
                jpeg_buffer_size = JPEG_get_jpeg_buffer_size();
                }
            jpeg_rx_state = JPEG_RX_STATE_STARTED;
            }

        isJpegBufAvailable = ( NULL != jpeg_data );
        if( isJpegBufAvailable )
            {
            jpeg_data[0] = ESCAPE_CODE;
            jpeg_data[1] = 0xD8;
            jpeg_idx     = 1;
            }
        else
            {
            PRINTF( "Err: jpeg buf not available\r\n" );
            }
        }

    if( JPEG_RX_STATE_STARTED == jpeg_rx_state )
        {
        if( jpeg_idx < jpeg_buffer_size )
            {
            jpeg_idx++;
            }
        else
            {
            jpeg_rx_state = JPEG_RX_STATE_BUF_OVER;
            PRINTF( "Err: received jpeg size is larger than %d\r\n", jpeg_buffer_size );
            }
        }

    prev_data = curr_data;
    }
}

/*================================================================================================*/
/**
@brief   get Uart Jpeg Data
@details

@return None
@retval None

@pre None
@post None
*/
/*================================================================================================*/
void getUartJpegData
    (
    uint8_t* data,
    uint32_t data_size
    )
{
uint16_t idx = 0;

for( idx=0; idx < data_size; idx++ )
    {
    parseJpegSerData(data[idx]);
    }
}

#ifdef __cplusplus
}
#endif
