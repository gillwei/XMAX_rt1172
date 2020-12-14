/*********************************************************************
* @file
* display_support.c
*
* Display related functions
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "board.h"
#include "pin_mux.h"
#include "FreeRTOS.h"
#include "task.h"

#include "fsl_dc_fb_lcdifv2.h"
#include "fsl_debug_console.h"
#include "fsl_display.h"
#include "fsl_gpio.h"

#include "display_support.h"
#include "GRM_pub_prj.h"
#include "PM_pub.h"
#include "PERIPHERAL_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define DEMO_HSW    32
#define DEMO_HFP    5
#define DEMO_HBP    8
#define DEMO_VSW    1
#define DEMO_VFP    8
#define DEMO_VBP    7

#define DEMO_LCDIF_POL_FLAGS                                                             \
    (kLCDIFV2_DataEnableActiveHigh | kLCDIFV2_VsyncActiveLow | kLCDIFV2_HsyncActiveLow | \
     kLCDIFV2_DriveDataOnRisingClkEdge)

#define DEMO_LCDIF LCDIFV2

#define STD_HIGH                ( 1u ) /* Physical state 5V or 3.3V */
#define STD_LOW                 ( 0u ) /* Physical state 0V */

#define MIN_DELAY_START_TIME    ( 2000 )
#define T4_TIMEOUT_AFTER_RESET  ( 200 )
#define FAULT_MONITOR_DURATION  ( 10 )

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
static dc_fb_lcdifv2_handle_t s_dcFbLcdifv2Handle = { 0 };

static const dc_fb_lcdifv2_config_t s_dcFbLcdifv2Config = {
    .lcdifv2       = DEMO_LCDIF,
    .width         = DEMO_PANEL_WIDTH,
    .height        = DEMO_PANEL_HEIGHT,
    .hsw           = DEMO_HSW,
    .hfp           = DEMO_HFP,
    .hbp           = DEMO_HBP,
    .vsw           = DEMO_VSW,
    .vfp           = DEMO_VFP,
    .vbp           = DEMO_VBP,
    .polarityFlags = DEMO_LCDIF_POL_FLAGS,
    .lineOrder     = kLCDIFV2_LineOrderRGB,
/* CM4 is domain 1, CM7 is domain 0. */
#if (__CORTEX_M <= 4)
    .domain = 1,
#else
    .domain = 0,
#endif
};

const dc_fb_t g_dc = {
    .ops     = &g_dcFbOpsLcdifv2,
    .prvData = &s_dcFbLcdifv2Handle,
    .config  = &s_dcFbLcdifv2Config,
};

static bool pm_status = PM_IGN_ON;
/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
static void BOARD_InitLcdifClock
    (
    void
    );

static void display_monitor_create_task
    (
    void
    );

static void display_monitor_task
    (
    void* arg
    );

static void display_pm_handler
    (
    bool ign_status
    );

static void control_TFT_BL_EN
    (
    uint8_t on_off
    );

/*********************************************************************
*
* @private
* BOARD_InitLcdifClock
*
* @brief Configures the lcdif clcok source, div and the mux.
*        This may changed when clock tool is available.
*
*********************************************************************/
static void BOARD_InitLcdifClock
    (
    void
    )
{
/*
 * The pixel clock is (height + VSW + VFP + VBP) * (width + HSW + HFP + HBP) * frame rate.
 */

CLOCK_InitVideoPllWithFreq( 89 );

const clock_root_config_t lcdifv2ClockConfig = {
    .clockOff = false,
    .mfn      = 0,
    .mfd      = 0,
    .mux      = kCLOCK_LCDIFV2_ClockRoot_MuxVideoPllOut, /*!< PLL_528. */
    .div      = 10,
};

CLOCK_SetRootClock(kCLOCK_Root_Lcdifv2, &lcdifv2ClockConfig);
}

/*********************************************************************
*
* @private
* BOARD_InitDisplayInterface
*
* @brief Initial procedure for display interface.
*
*********************************************************************/
status_t BOARD_InitDisplayInterface
    (
    void
    )
{
/* LCDIF v2 output to PARA_LCD. */
CLOCK_EnableClock( kCLOCK_Video_Mux );
VIDEO_MUX->VID_MUX_CTRL.SET = VIDEO_MUX_VID_MUX_CTRL_PARA_LCD_SEL_MASK;

/* Power on and isolation off. */
PGMC_BPC4->BPC_POWER_CTRL |= ( PGMC_BPC_BPC_POWER_CTRL_PSW_ON_SOFT_MASK | PGMC_BPC_BPC_POWER_CTRL_ISO_OFF_SOFT_MASK );

return kStatus_Success;
}

/*********************************************************************
*
* @private
* LCDIF2_IRQHandler
*
* @brief Interrupt handler for lcdifv2
*
*********************************************************************/
void LCDIF2_IRQHandler
    (
    void
    )
{
DC_FB_LCDIFV2_IRQHandler( &g_dc );
}

/*********************************************************************
*
* @private
* BOARD_VerifyDisplayClockSource
*
* @brief Verfiy if the configuration of the clock source is correct.
*
*********************************************************************/
status_t BOARD_VerifyDisplayClockSource
    (
    void
    )
{
status_t status;
uint32_t srcClkFreq;

/*
    * In this implementation, the SYSPLL2 (528M) clock is used as the source
    * of LCDIFV2 pixel clock and MIPI DSI ESC clock. The OSC24M clock is used
    * as the MIPI DSI DPHY PLL reference clock. This function checks the clock
    * source are valid. OSC24M is always valid, so only verify the SYSPLL2.
    */
srcClkFreq = CLOCK_GetPllFreq( kCLOCK_PllSys2 );
if( 528 != ( srcClkFreq / 1000000 ) )
    {
    status = kStatus_Fail;
    }
else
    {
    status = kStatus_Success;
    }

return status;
}

/*********************************************************************
*
* @public
* BOARD_PrepareDisplayController
*
* @brief public function for ew_bsp_display to call for general
*        initialization procedure.
*
*********************************************************************/
status_t BOARD_PrepareDisplayController
    (
    void
    )
{
status_t status;

status = BOARD_VerifyDisplayClockSource();

if( status != kStatus_Success )
    {
    PRINTF( "Error: Invalid display clock source.\r\n" );
    return status;
    }

BOARD_InitLcdifClock();

status = BOARD_InitDisplayInterface();

if( kStatus_Success == status )
    {
    NVIC_SetPriority( LCDIF2_IRQn, 3 );
    EnableIRQ( LCDIF2_IRQn );
    }
return kStatus_Success;
}

/*********************************************************************
*
* @public
* BOARD_is_tft_connected
*
* @brief check if the tft is connected, if not connected, we don't wish
*        to setup all the display signal.
*
*********************************************************************/
uint32_t BOARD_is_tft_connected
    (
    void
    )
{
if( GPIO_PinRead( BOARD_INITPINS_TFT_CONNECTED_GPIO, BOARD_INITPINS_TFT_CONNECTED_GPIO_PIN ) == STD_LOW )
    {
    return TFT_CONNECTED;
    }
return TFT_NOT_CONNECTED;
}

/*********************************************************************
*
* @public
* display_monitor_init
*
* @brief Initial function to public to create display monitor task.
*
*********************************************************************/
void display_monitor_init
    (
    void
    )
{
PM_register_callback( "display", display_pm_handler );
display_monitor_create_task();
}

/*********************************************************************
*
* @private
* display_pm_handler
*
* @brief registed callback for listening the pm status change
*
*********************************************************************/
static void display_pm_handler
    (
    bool ign_status
    )
{
if( ign_status == PM_IGN_ON ) // IGN_ON
    {
    PERIPHERAL_pwm_set_display_dutycycle( 50 ); // TODO: set to current dutycycle in EEPROM in the future
    control_TFT_BL_EN( STD_HIGH );
    }
else // IGN_OFF
    {
    PERIPHERAL_pwm_set_display_dutycycle( 0 );
    control_TFT_BL_EN( STD_LOW );
    }
pm_status = ign_status;
}

/*********************************************************************
*
* @private
* display_monitor_create_task
*
* @brief function to create display monitor task
*
*
*********************************************************************/
static void display_monitor_create_task
    (
    void
    )
{
if( pdPASS == xTaskCreate( display_monitor_task, "display_monitor_task", configMINIMAL_STACK_SIZE, NULL, TASK_PRIO_DISPLAY, NULL ) )
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
* display_monitor_task
*
* @brief This task monitors if the asil pin is abnormal and perform reset
*
*********************************************************************/
static void display_monitor_task
    (
    void* arg
    )
{
static uint32_t asil_pin_status = 0;

vTaskDelay( T4_TIMEOUT_AFTER_RESET );
control_TFT_BL_EN( STD_HIGH );

/* Wait until display initialization done */
vTaskDelay( MIN_DELAY_START_TIME );
while( true )
    {
    if( pm_status == PM_IGN_ON )
        {
        asil_pin_status = GPIO_PinRead( BOARD_INITPINS_TFT_ASIL_GPIO, BOARD_INITPINS_TFT_ASIL_GPIO_PIN );
        if( asil_pin_status == STD_HIGH )
            {
            /* Perform system reset */
            PRINTF( "ASIL fault detected, perfrom system reset\r\n" );
            NVIC_SystemReset();
            }
        }
    vTaskDelay( FAULT_MONITOR_DURATION );
    }
vTaskDelete( NULL );
}

/*********************************************************************
*
* @private
* control_TFT_BL_EN
*
* @brief Function to control the TFT_BL_EN pin.
*        0: LED off
*        1: LED on
*
*********************************************************************/
static void control_TFT_BL_EN
    (
    uint8_t on_off
    )
{
GPIO_WritePinOutput( BOARD_INITPINS_TFT_BL_EN_GPIO, BOARD_INITPINS_TFT_BL_EN_GPIO_PIN, !on_off );
}

/*********************************************************************
*
* @public
* display_pre_handler
*
* @brief handle display related pins
*
*********************************************************************/
void display_pre_handler
    (
    void
    )
{
GPIO_WritePinOutput( BOARD_INITPINS_TFT_RESET_GPIO, BOARD_INITPINS_TFT_RESET_GPIO_PIN, STD_HIGH );  // RESET off
}
