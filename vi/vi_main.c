/*********************************************************************
* @file
* vi_main.c
*
* @brief
* Vehicle information module - main
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
#include "GRM_pub_prj.h"
#include "EW_pub.h"
#include "VI_pub.h"
#include "vi_priv.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define VEHICLE_INFO_TASK_PRIORITY          ( TASK_PRIO_VEHICLE_INFO_MNGR )
#define VEHICLE_INFO_TASK_STACK_SIZE        ( configMINIMAL_STACK_SIZE * 2 )
#define VEHICLE_INFO_TASK_NAME              "vi_task"

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
static const int VEHICLE_INFO_TASK_POLLING_TIME = pdMS_TO_TICKS( 50 );

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* task_main
*
* Main loop of the vehicle information task
*
* @param arg The pointer to the argument of the task
*
*********************************************************************/
static void task_main
    (
    void* arg
    )
{
while( true )
    {
    vi_key_proc();
    vTaskDelay( VEHICLE_INFO_TASK_POLLING_TIME );
    }

vTaskDelete( NULL );
}

/*********************************************************************
*
* @private
* create_task
*
* Create vehicle information task
*
*********************************************************************/
static void create_task
    (
    void
    )
{
BaseType_t result = xTaskCreate( task_main, VEHICLE_INFO_TASK_NAME, VEHICLE_INFO_TASK_STACK_SIZE, NULL, VEHICLE_INFO_TASK_PRIORITY, NULL );
configASSERT( pdPASS == result );
}

/*********************************************************************
*
* @public
* VI_init
*
* Initialize vehicle information module
*
*********************************************************************/
void VI_init
    (
    void
    )
{
create_task();
vi_rx_init();
vi_key_init();
vi_trip_time_init();
vi_clock_init();
}
