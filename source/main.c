/*********************************************************************
* @file
* main.c
*
* The main file of LinkCard mcu application.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/

#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "pin_mux.h"
#include "clock_config.h"

#include "EW_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#ifdef NDEBUG
    #define BUILD_TYPE "release"
#else
    #define BUILD_TYPE "debug"
#endif

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
static void led_task( void* arg );

/*********************************************************************
*
* @public
* main
*
* The main function of the LinkCard mcu application.
*
*********************************************************************/
int main
    (
    void
    )
{
/* Board pin, clock, debug console init */
BOARD_ConfigMPU();
BOARD_InitBootPins();
BOARD_BootClockRUN();
BOARD_InitDebugConsole();

PRINTF( "%s %s %s\r\n", __DATE__, __TIME__, BUILD_TYPE );

EW_init();

xTaskCreate( led_task, "led_task", configMINIMAL_STACK_SIZE * 2, NULL, ( tskIDLE_PRIORITY + 4 ), NULL );

vTaskStartScheduler();

return 0;
}

static void led_task
    (
    void* arg
    )
{
while( true )
    {
    GPIO_PortToggle( BOARD_USER_LED_GPIO, 1u << BOARD_USER_LED_GPIO_PIN );
    PRINTF("The LED is blinking.\r\n");
    vTaskDelay( pdMS_TO_TICKS( 500 ) );
    }
vTaskDelete( NULL );
}
