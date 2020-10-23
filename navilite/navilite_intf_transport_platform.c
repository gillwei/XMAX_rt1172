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
    PRINTF( "\r\n*** NAVILITE_send() not enabled or implemented! ***\r\n" );
    return false;
#endif

// implement the platform send here
bool ret = false;
int i = 0;
int dataoffset = 0;
navilite_message* frame = (navilite_message*)data;

// copy the frame header except the payload to temp buffer
memcpy( (char*)navilite_send_buffer, (char*)frame, dataoffset = sizeof( navilite_message ) - sizeof( uint8_t* ) );

// copy the data content on buffer if data type is pointer
if ( frame->payload_data_type == NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER )
    {
    memcpy( (char*)navilite_send_buffer + FIELD_PAYLOADDATA_OFFSET, (char*)frame->data_pointer, frame->payload_size );
    PRINTF( "# payload data retrieved from pointer:%p", frame->data_pointer );

    // print the payload frame content
    for( i = 0; i < frame->payload_size; i++ )
        {
        PRINTF( "[0x%x]", navilite_send_buffer[FIELD_PAYLOADDATA_OFFSET + i] );
        }
    PRINTF( "\r\n" );
    }
else
    {
    PRINTF( "data value: 0x%x from value type", navilite_send_buffer[FIELD_PAYLOADDATA_OFFSET] );
    }

// @TODO: implement a queue buffer to handling serial send if available

#if( NAVILITE_SERIAL_SEND_SUPPORT == 1 )
    // Note: full frame header size - payload pointer filed + real data size = actual data frame to be sent!!
    PRINTF( "# SEND SIZE:%d", FIELD_PAYLOADDATA_OFFSET + frame->payload_size );

    // print the payload frame content
    NAVILITE_print_frame( frame );

    if( NAVILITE_get_connect_mode() == NAVILITE_CONN_BT_IAP2 )
        {
        ret = BT_IAP2_send( FIELD_PAYLOADDATA_OFFSET + frame->payload_size, navilite_send_buffer );
        }
    else
        {
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
PRINTF( "@TODO:  NAVILITE_receive(%s,%d)" , data, data_size );
// @TODO: implement a queue buffer to handling serial receive if available
return ret;
}

