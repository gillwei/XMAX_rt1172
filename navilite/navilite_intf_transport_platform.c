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
uint8_t navilite_send_buffer[512];

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
    NAVILITE_PRINTF( "\r\n#NAVILITE-DEBUG# (NAVILITE_send MTU:%d, payload: %d, service: %d, data_type: %s) >> ", FIELD_PAYLOADDATA_OFFSET + frame->payload_size, frame->payload_size, frame->service_type, (frame->payload_data_type == 0) ? "V":"P" );
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
