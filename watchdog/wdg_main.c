/*********************************************************************
* @file
* wdg_main.c
*
* Brief watchdog application
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "fsl_debug_console.h"
#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "pin_mux.h"

#include "WDG_pub.h"
#include "GRM_pub_prj.h"
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
static bool watchdog_enable_flag = true;
/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
static void watchdog_create_task
    (
    void
    );

static void watchdog_task
    (
    void* arg
    );

/*********************************************************************
*
* @public
* WDG_init
*
* @brief Initial function to public to create watchdog timer task.
*
*********************************************************************/
void WDG_init
    (
    void
    )
{
watchdog_create_task();
}

/*********************************************************************
*
* @public
* WDG_switch
*
* @brief switch if we need to generate the pulse
*
*********************************************************************/
void WDG_switch
    (
    bool wdg_flag
    )
{
watchdog_enable_flag = wdg_flag;
}


/*********************************************************************
*
* @private
* watchdog_create_task
*
* @brief function to create watchdog timer task
*
*
*********************************************************************/
static void watchdog_create_task
    (
    void
    )
{
if( pdPASS == xTaskCreate( watchdog_task, "watchdog_task", configMINIMAL_STACK_SIZE, NULL, TASK_PRIO_WATCH_DOG, NULL ) )
    {
    PRINTF("%s ok\r\n", __FUNCTION__ );
    }
else
    {
    PRINTF("%s fail\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @private
* watchdog_task
*
* @brief This task generates a 1s pulse to kick watchdog timer module.
*
*********************************************************************/
static void watchdog_task
    (
    void* arg
    )
{
while( true )
    {
    if( watchdog_enable_flag )
        {
        GPIO_PortToggle( BOARD_INITPINS_WDOG_B_GPIO, BOARD_INITPINS_WDOG_B_GPIO_PIN_MASK );
        }
    vTaskDelay( pdMS_TO_TICKS( 1000 ) );
    }
vTaskDelete( NULL );
}