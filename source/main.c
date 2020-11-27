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
#include "semphr.h"

#include "pin_mux.h"
#include "clock_config.h"

#include "EW_pub.h"
#include "PERIPHERAL_pub.h"
#include "EEPM_pub.h"
#include "CAN_nim_ctrl.h"
#include "RTC_pub.h"
#include "WDG_pub.h"
#include "display_support.h"
#include "PM_pub.h"
#include "factory_test.h"
#include "VI_pub.h"
#include "NAVI_pub.h"
#include "JPEG_pub.h"
#include "TEST_pub.h"
#include "HCI_pub.h"
#include "BTM_pub.h"
#include "MM_pub.h"

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

if( BOARD_is_tft_connected() == TFT_CONNECTED )
    {
    EW_init();
    display_monitor_init();
    }
else
    {
    PRINTF( "TFT is not connected, EW will not be initialized \r\n" );
    }
PERIPHERAL_init();
PM_init();
EEPM_init();
RTC_init();
WDG_init();
HCI_init();
FACTORY_init();
BTM_init();
VI_init();
JPEG_init();
NAVI_init();
MM_init();

#if( UNIT_TEST_ENABLE )
    TEST_init();
#endif

vCAN_nim_create_task();

vTaskStartScheduler();

return 0;
}
