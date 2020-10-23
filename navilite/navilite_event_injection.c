/*********************************************************************
* @file
* navilite_event_injection.c
*
* @brief
* NAVILITE module - event injection
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
#include "ewrte.h"
#include "fsl_debug_console.h"
#include "NAVILITE_pub_protocol.h"
#include "EW_pub.h"
#include "navilite_prv.h"
#include "NAVILITE_pub.h"

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
extern navilite_content_update_callbacks_type navilite_content_update_callbacks;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @public
* NAVILITE_event_injection for fake data mode
*
*********************************************************************/
void NAVILITE_event_injection
    (
    void
    )
{
// Sample Data for 4 cycles
static int timer_counter = 0;
static uint8_t* sample_road_name[] = { (uint8_t*)"新台五路一段", (uint8_t*)"東麻布1丁目8番", (uint8_t*)"中油林口工三加油站(24)(自助)", (uint8_t*)"Eastern Wood Road" };
static uint32_t sample_eta_value[] = { (uint32_t)140, (uint32_t)160, (uint32_t)170, (uint32_t)190 };
uint32_t tmp_eta_val = 0;
uint8_t* tmp_str = NULL;

timer_counter++;

PRINTF( "\r\nDemo Events Injection Run\r\n" );
tmp_str = sample_road_name[timer_counter % 4];

if( navilite_content_update_callbacks.callback_func_currentroadname )
    {
    navilite_content_update_callbacks.callback_func_currentroadname( tmp_str, strlen( (const char*)tmp_str ) );
    }

tmp_eta_val = (uint32_t)sample_eta_value[timer_counter % 4];

if( navilite_content_update_callbacks.callback_func_eta )
    {
    navilite_content_update_callbacks.callback_func_eta( tmp_eta_val );
    }

if( timer_counter > 1024 )
    {
    timer_counter = 0;
    }

// @TODO: image update due to large image will occupy the ROM size
//        we can make this work when HOP is enabled to use the prebuilt image data
}
