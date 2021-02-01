/*********************************************************************
* @file
* bc_main.c
*
* @brief
* Bluetooth Connectivity - Main
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "fsl_debug_console.h"
#include "task.h"
#include "event_groups.h"
#include "GRM_pub_prj.h"
#include <stdlib.h>
#include <stdint.h>
#include "bc_ancs_priv.h"
#include "bc_ams_priv.h"
/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define BC_TASK_PRIORITY    ( TASK_PRIO_BT_CONNECTIVITY )
#define BC_TASK_STACK_SIZE  ( configMINIMAL_STACK_SIZE * 10 )
#define BC_TASK_NAME        "bc_task"

#define EVENT_ANCS_GATT_NOTIFICATION_RECEIVED       ( 1 << 0 )

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
static EventGroupHandle_t event_group = NULL;

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
* The running loop
*
* @param arg The pointer to the task argument
*
*********************************************************************/
static void task_main
    (
    void* arg
    )
{
EventBits_t event_bits;

while( true )
    {
    event_bits = xEventGroupWaitBits
                    (
                    event_group,    /* The event group handle. */
                    EVENT_ANCS_GATT_NOTIFICATION_RECEIVED,
                    pdTRUE,         /* clear on exit */
                    pdFALSE,        /* Don't wait for both bits, either bit unblock task. */
                    portMAX_DELAY   /* Block indefinitely to wait for the condition to be met. */
                    );

    if( EVENT_ANCS_GATT_NOTIFICATION_RECEIVED == ( event_bits & EVENT_ANCS_GATT_NOTIFICATION_RECEIVED ) )
        {
        bc_ancs_process_gatt_notification();
        }
    }

vTaskDelete( NULL );
}

/*********************************************************************
*
* @private
* bc_notify_ancs_gatt_notification_received
*
* Notify BC task to process the ANCS GATT notification
*
*********************************************************************/
void bc_notify_ancs_gatt_notification_received
    (
    void
    )
{
xEventGroupSetBits( event_group, EVENT_ANCS_GATT_NOTIFICATION_RECEIVED );
}

/*********************************************************************
*
* @public
* BC_init
*
* Init Bluetooth Connectivity
*
*********************************************************************/
void BC_init
    (
    void
    )
{
event_group = xEventGroupCreate();
configASSERT( NULL != event_group );

BaseType_t result = xTaskCreate( task_main, BC_TASK_NAME, BC_TASK_STACK_SIZE, NULL, BC_TASK_PRIORITY, NULL );
configASSERT( pdPASS == result );

bc_ancs_init();
bc_ams_init();
}
