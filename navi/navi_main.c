/*********************************************************************
* @file
* navi_main.c
*
* @brief
* Navigation module - main
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
#include "fsl_debug_console.h"
#include "JPEG_pub.h"
#include "EW_pub.h"

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

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @public
* NAVI_jpeg_decode_finished
*
* The callback function receiving the JPEG decode finished status
* from the JPEG module.
*
* @param result The result of JPEG decode.
*
*********************************************************************/
void NAVI_jpeg_decode_finished
    (
    int result
    )
{
PRINTF( "%s: %d\r\n", __FUNCTION__, result );
if( RESULT_SUCCESS == result )
    {
    EW_notify_navi_map_update();
    }
}

/*********************************************************************
*
* @public
* NAVI_jpeg_data_received
*
* Notify navigation module that JPEG data is received
*
* @param size_byte JPEG file size in byte
* @param *buffer_addr JPEG buffer address
*
*********************************************************************/
void NAVI_jpeg_data_received
    (
    uint32_t size_byte,
    uint8_t* buffer_addr
    )
{
JPEG_notify_received( size_byte, buffer_addr, &NAVI_jpeg_decode_finished );
}

/*********************************************************************
*
* @public
* NAVI_init
*
* Initialize navigation module
*
*********************************************************************/
void NAVI_init
    (
    void
    )
{
}

