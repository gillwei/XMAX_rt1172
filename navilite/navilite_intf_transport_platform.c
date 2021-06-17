/*********************************************************************
* @file
* navilite_intf_apprequest.c
*
* @brief
* NAVILITE module - BT/IAP2 transport interface APIs
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "NAVILITE_pub.h"
#include "NAVILITE_util.h"
#include "TEST_pub.h"

#if( NAVILITE_BUILD_ROLE == NAVILITE_TARGET_MCU )
#include "FreeRTOS.h"
#include "event_groups.h"
#include "limits.h"
#include "task.h"
#include "semphr.h"
#include "ewrte.h"
#include "fsl_debug_console.h"

#define NAVILITE_DEBUG true
#define NAVILITE_DEBUG_DETAIL false

#if( NAVILITE_SERIAL_SEND_SUPPORT == 1 )
#include "bt_spp_iap2.h"
#endif

#endif

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define TEST_JPEG_SIZE 27126

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
#if( UNIT_TEST_NAVILITE )
    // include jpeg sample data when performing test unit
    uint8_t navilite_send_buffer[TEST_JPEG_SIZE];
#else
    uint8_t navilite_send_buffer[512];
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @public
* NAVILITE_send
*
* Send data to BT module via SPP or IAP2
*
* @param data data pointer
* @param data_size data size to send
* @return  meter speed
*
*********************************************************************/
bool NAVILITE_send
    (
    uint8_t* data,
    uint32_t data_size
    )
{
#if( NAVILITE_SERIAL_SEND_SUPPORT == 0 )
    NAVILITE_PRINTF( "\r\n*** NAVILITE_send() not enabled or implemented! ***\r\n" );
    return false;
#endif

// implement the platform send here
bool ret = false;
int i = 0;
int dataoffset = 0;
navilite_message* frame = (navilite_message*)data;

#if( NAVILITE_DEBUG )
    NAVILITE_PRINTF( "\r\n#NAVILITE-DEBUG# (NAVILITE_send MTU:%d, payload: %d, service: %d, data_type: %s) >> ", FIELD_PAYLOADDATA_OFFSET + frame->payload_size, frame->payload_size, frame->service_type, ( frame->payload_data_type == 0 ) ? "V":"P" );
#endif

// copy the frame header except the payload to temp buffer
memcpy( (char*)navilite_send_buffer, (char*)frame, dataoffset = sizeof( navilite_message ) - sizeof( uint8_t* ) );

// copy the data content on buffer if data type is pointer
if ( frame->payload_data_type == NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER )
    {
    memcpy( (char*)navilite_send_buffer + FIELD_PAYLOADDATA_OFFSET, (char*)frame->data_pointer, frame->payload_size );
#if( NAVILITE_DEBUG )
    NAVILITE_PRINTF( "\r\n++ Data as follows:\r\n++ " );
    // print the payload frame content
    for( i = 0; i < frame->payload_size; i++ )
        {
        NAVILITE_PRINTF( "[0x%x]", navilite_send_buffer[FIELD_PAYLOADDATA_OFFSET + i] );
        }
    NAVILITE_PRINTF( "\r\n" );
#endif
    }
else
    {
#if( NAVILITE_DEBUG && NAVILITE_DEBUG_DETAIL )
    NAVILITE_PRINTF( "\r\n++ Value is: 0x%x\r\n", navilite_send_buffer[FIELD_PAYLOADDATA_OFFSET] );
#endif
    }

#if( NAVILITE_DEBUG && NAVILITE_DEBUG_DETAIL )
    NAVILITE_print_frame( frame );
#endif

#if( NAVILITE_SERIAL_SEND_SUPPORT == 1 )
    // Note: full frame header size - payload pointer filed + real data size = actual data frame to be sent!!

    if( NAVILITE_get_connect_mode() == NAVILITE_CONN_BT_IAP2 )
        {
        #if( NAVILITE_DEBUG && NAVILITE_DEBUG_DETAIL )
            NAVILITE_PRINTF( "\r\n++ Sent via IAP2\r\n" );
        #endif
        ret = BT_IAP2_send( FIELD_PAYLOADDATA_OFFSET + frame->payload_size, navilite_send_buffer );
        }
    else
        {
        #if( NAVILITE_DEBUG && NAVILITE_DEBUG_DETAIL )
            NAVILITE_PRINTF( "\r\n++ Sent via SPP\r\n" );
        #endif
        ret = BT_SPP_send( FIELD_PAYLOADDATA_OFFSET + frame->payload_size, navilite_send_buffer );
        }
#endif

return ret;
}

#if( UNIT_TEST_NAVILITE )
    // only compile when test unit is enabled
    /*********************************************************************
    *
    * @public
    * NAVILITE_send_as_mobile
    *
    * Send data as mobile for testing purpose
    *
    * @param data data pointer
    * @param data_size data size to send
    * @return true if success
    *         false if failed
    *
    *********************************************************************/

#if( UNIT_TEST_NAVILITE )
    // only compile when test unit is enabled
    /*********************************************************************
    *
    * @public
    * NAVILITE_send_as_mobile
    *
    * Send data as mobile for testing purpose
    *
    * @param data data pointer
    * @param data_size data size to send
    * @return true if success
    *         false if failed
    *
    *********************************************************************/
    bool NAVILITE_send_as_mobile
        (
        uint8_t* data,
        uint32_t data_size
        )
    {
    bool ret = false;
    int dataoffset = 0;
    uint8_t uart_buffer[NAVILITE_QUEUE_BUFFER_SIZE];

    navilite_message* frame = (navilite_message*)data;

    #if( NAVILTE_DEBUG )
        PRINTF( "\r\n#NAVILITE-DEBUG# (NAVILITE_send MTU:%d, payload: %d, service: %d, data_type: %s) >> ", FIELD_PAYLOADDATA_OFFSET + frame->payload_size, frame->payload_size, frame->service_type, (frame->payload_data_type == 0) ? "V":"P" );
    #endif

    // copy the frame header except the payload to temp buffer
    memcpy( (char*)navilite_send_buffer, (char*)frame, dataoffset = sizeof( navilite_message ) - sizeof( uint8_t* ) );

    // copy the data content on buffer if data type is pointer
    if ( frame->payload_data_type == NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER )
        {
        memcpy( (char*)navilite_send_buffer + FIELD_PAYLOADDATA_OFFSET, (char*)frame->data_pointer, frame->payload_size );
    #if( NAVILITE_DEBUG && NAVILITE_DEBUG_DETAIL )
        PRINTF( "\r\n++ Data as follows:\r\n++ " );
        // print the payload frame content
        for( i = 0; i < frame->payload_size; i++ )
            {
            PRINTF( "[0x%x]", navilite_send_buffer[FIELD_PAYLOADDATA_OFFSET + i] );
            }
        PRINTF( "\r\n" );
    #endif
        }
    else
        {
    #if( NAVILITE_DEBUG && NAVILITE_DEBUG_DETAIL )
        PRINTF( "\r\n++ Value is: 0x%x", navilite_send_buffer[FIELD_PAYLOADDATA_OFFSET] );
    #endif
        }

    #if( NAVILITE_SERIAL_SEND_SUPPORT == 1 )
        if( NAVILITE_get_connect_mode() == NAVILITE_CONN_TBD )
            {
            #if( NAVILITE_DEBUG && NAVILITE_DEBUG_DETAIL )
            PRINTF( "sent: frame header:%d + payload:%d\r\n", sizeof( navilite_message ) - sizeof( uint16_t ) - sizeof( uint8_t* ) , frame->payload_size );
            #endif
            int frame_head_size = sizeof( navilite_message ) - sizeof( uint16_t ) - sizeof( uint8_t* );
            int left_data_size = frame_head_size + frame->payload_size;
            int sent_index = 0;
            bool process_frame = true;
            int frame_no = 0;

            while( process_frame )
                {
                if ( left_data_size >= NAVILITE_QUEUE_BUFFER_SIZE )
                    {
                    #if( NAVILITE_DEBUG && NAVILITE_DEBUG_DETAIL )
                        PRINTF("%d) Sending %d left PKT:%d\r\n", NAVILITE_QUEUE_BUFFER_SIZE, frame_no++, left_data_size );
                    #endif
                    memcpy( uart_buffer, navilite_send_buffer + sent_index, NAVILITE_QUEUE_BUFFER_SIZE );
                    left_data_size -= NAVILITE_QUEUE_BUFFER_SIZE;
                    sent_index += NAVILITE_QUEUE_BUFFER_SIZE;
                    NAVILITE_parse_data( (uint8_t*)uart_buffer, NAVILITE_QUEUE_BUFFER_SIZE );
                    if ( frame_no == 0 )
                        {
                        #if( NAVILITE_DEBUG && NAVILITE_DEBUG_DETAIL )
                            PRINTF( "NOTE: This is FIRST HEADER!\r\n" );
                            NAVILITE_print_frame( (navilite_message*)uart_buffer );
                        #endif
                        }
                    }
                else
                    {
                    #if( NAVILITE_DEBUG && NAVILITE_DEBUG_DETAIL )
                        PRINTF("# final send left PKT:%d\r\n", left_data_size );
                    #endif
                    memcpy( uart_buffer, navilite_send_buffer + sent_index, left_data_size );
                    NAVILITE_parse_data( (uint8_t*)uart_buffer, left_data_size );
                    process_frame = false;
                    }
                }
            }
    #endif
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_send_as_mobile_raw
    *
    * Send raw data as mobile for testing purpose
    *
    * @param data data pointer
    * @param data_size data size to send
    * @return true if success
    *         false if failed
    *
    *********************************************************************/
    bool NAVILITE_send_as_mobile_raw
        (
        uint8_t* data,
        uint32_t data_size
        )
    {
    bool ret = false;
    static uint8_t uart_buffer[NAVILITE_QUEUE_BUFFER_SIZE];

    navilite_message* frame = (navilite_message*)data;

    if( NAVILITE_get_connect_mode() != NAVILITE_CONN_TBD )
        {
        PRINTF( "\r\nWARNING! Please turn off BT connection on phone during test case mode and restart LC again\r\n" );
        while( 1 ) ;
        }

    #if( NAVILITE_DEBUG && NAVILITE_DEBUG_DETAIL )
        PRINTF( "\r\n#NAVILITE-DEBUG-RAW# (NAVILITE_send MTU:%d, payload: %d, service: %d, data_type: %s) >> ", FIELD_PAYLOADDATA_OFFSET + frame->payload_size, frame->payload_size, frame->service_type, (frame->payload_data_type == 0) ? "V":"P" );
    #endif

    memcpy( (char*)navilite_send_buffer, (char*)frame, data_size );

    #if( NAVILITE_SERIAL_SEND_SUPPORT == 1 )
        if( NAVILITE_get_connect_mode() == NAVILITE_CONN_TBD )
            {
            int frame_head_size = sizeof( navilite_message ) - sizeof( uint16_t ) - sizeof( uint8_t* );
            int left_data_size = data_size; // frame_head_size + frame->payload_size;
            int sent_index = 0;
            bool process_frame = true;
            int frame_no = 0;
            int total_sent = 0;

            // Send every NAVILITE_QUEUE_BUFFER_SIZE bytes
            while( process_frame )
                {
                if ( left_data_size >= NAVILITE_QUEUE_BUFFER_SIZE )
                    {
                    #if( NAVILITE_DEBUG && NAVILITE_DEBUG_DETAIL )
                        PRINTF("\r\n%d) Sending frame(%d) left PKT:%d\r\n", NAVILITE_QUEUE_BUFFER_SIZE, frame_no++, left_data_size );
                    #endif
                    memcpy( uart_buffer, navilite_send_buffer + sent_index, NAVILITE_QUEUE_BUFFER_SIZE );
                    left_data_size -= NAVILITE_QUEUE_BUFFER_SIZE;
                    sent_index += NAVILITE_QUEUE_BUFFER_SIZE;
                    NAVILITE_queue_hci_buffer( (uint8_t*)uart_buffer, NAVILITE_QUEUE_BUFFER_SIZE );
                    total_sent += NAVILITE_QUEUE_BUFFER_SIZE;
                    if ( frame_no == 1 )
                        {
                        #if( NAVILITE_DEBUG && NAVILITE_DEBUG_DETAIL )
                            PRINTF( "NOTE: This is FIRST HEADER!\r\n" );
                            NAVILITE_print_frame( (navilite_message*)uart_buffer );
                        #endif
                        }
                    }
                else
                    {
                    // Send the non-NAVILITE_QUEUE_BUFFER_SIZE bytes
                    #if( NAVILITE_DEBUG && NAVILITE_DEBUG_DETAIL )
                        PRINTF("# final send left PKT:%d\r\n", left_data_size );
                    #endif
                    memcpy( uart_buffer, navilite_send_buffer + sent_index, left_data_size );
                    NAVILITE_queue_hci_buffer( (uint8_t*)uart_buffer, left_data_size );
                    total_sent += left_data_size;
                    process_frame = false;
                    }
                #if( NAVILITE_DEBUG && NAVILITE_DEBUG_DETAIL )
                    PRINTF( "\r\n### %s: Summary total sent! = %d\r\n", __FUNCTION__, total_sent );
                #endif
                }
            }
    #endif
    return ret;
    }
    #endif

#endif

/*********************************************************************
*
* @public
* NAVILITE_receive
*
* Receive data from BT module via SPP or IAP2
*
* @param data data pointer to receive
* @param data_size data size to receive
* @return  true if success, otherwise false
*
*********************************************************************/
bool NAVILITE_receive
    (
    uint8_t* data,
    uint32_t data_size
    )
{
bool ret = false;
NAVILITE_PRINTF( "@TODO:  NAVILITE_receive(%s,%d)" , data, data_size );
// @TODO: implement a queue buffer to handling serial receive if available
return ret;
}
