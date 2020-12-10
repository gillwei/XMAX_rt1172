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
#include "NAVILITE_pub.h"
#include "NAVI_pub.h"
#include "JPEG_pub.h"
#include "TEST_pub.h"
#include "HCI_pub.h"
#include "BTM_pub.h"
#include "BC_pub.h"
#include "MM_pub.h"
#include "QR_pub.h"
#include "WEA_pub.h"
#include "NTF_pub.h"

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
#define GET_BOOT_RESET_FLAGS ( IOMUXC_SNVS_GPR->GPR32 )
#define Enter_SNVS_Mode_Flag ( 1 << 1 ) // use bit 1 of GPR32

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

if( GET_BOOT_RESET_FLAGS & IOMUXC_SNVS_GPR_GPR32_GPR( Enter_SNVS_Mode_Flag ) )
    {
    PRINTF( "Boot from SNVS\r\n" );
    IOMUXC_SNVS_GPR->GPR32 &= ~IOMUXC_SNVS_GPR_GPR32_GPR( Enter_SNVS_Mode_Flag );
    SNVS_LP_SRTC_StartTimer( SNVS );
    }
else
    {
    PRINTF( "Boot from Power on\r\n" );
    RTC_init();
    }

if( BOARD_is_tft_connected() == TFT_CONNECTED )
    {
    BOARD_InitLcdifPins();
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
WDG_init();
HCI_init();
FACTORY_init();
BTM_init();
BC_init();
VI_init();
JPEG_init();
NAVI_init();
MM_init();
QR_init();
WEA_init();
NTF_init();

#if( UNIT_TEST_ENABLE )
    TEST_init();
#endif

vCAN_nim_create_task();

NAVILITE_init();

vTaskStartScheduler();

return 0;
}
