/*********************************************************************
* @file
* peripheral_pwm.c
*
* Brief peripheral pwm interface for display pwm use.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "board.h"
#include "clock_config.h"
#include "FreeRTOS.h"
#include "pin_mux.h"
#include "task.h"

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "fsl_lpuart.h"
#include "fsl_flexio.h"

#include "PERIPHERAL_pub.h"
#include "peripheral_priv.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define DISPLAY_FLEXIO_BASEADDR                 FLEXIO2
#define DISPLAY_FLEXIO_OUTPUTPIN                ( 29U )     /* Select FXIO2_D29 as PWM output */
#define DISPLAY_FLEXIO_TIMER_CH                 ( 0U )      /* Flexio timer0 used */

#define DISPLAY_FLEXIO_CLOCK_FREQUENCY          ( CLOCK_GetRootClockFreq(kCLOCK_Root_Flexio2) )
/* FLEXIO output PWM frequency */
#define DISPLAY_FLEXIO_FREQUENCY                ( 20000U )

#define MIN_DUTY_CYCLE_VALUE                    ( 0 )
#define MAX_DUTY_CYCLE_VALUE                    ( 100 )

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
static void flexio_pwm_init
    (
    uint32_t freq_Hz,
    uint32_t duty
    );

static void flexio_pwm_start
    (
    void
    );

static void flexio_pwm_set_logic
    (
    uint32_t duty
    );

/*********************************************************************
*
* @private
* flexio_pwm_init
*
* @brief Configures the timer as a 8-bits PWM mode to generate the PWM waveform
*
* @param freq_Hz PWM frequency in hertz
* @param duty Specified duty in unit of %, with a range of [1, 99]
*
*********************************************************************/
static void flexio_pwm_init
    (
    uint32_t freq_Hz,
    uint32_t duty
    )
{
uint32_t lowerValue = 0; /* Number of clock cycles in high logic state in one period */
uint32_t upperValue = 0; /* Number of clock cycles in low logic state in one period */
uint32_t sum        = 0; /* Number of clock cycles in one period */
flexio_timer_config_t fxioTimerConfig;

/* Configure the timer DISPLAY_FLEXIO_TIMER_CH for generating PWM */
fxioTimerConfig.triggerSelect   = FLEXIO_TIMER_TRIGGER_SEL_SHIFTnSTAT(0U);
fxioTimerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceInternal;
fxioTimerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveLow;
fxioTimerConfig.pinConfig       = kFLEXIO_PinConfigOutput;
fxioTimerConfig.pinPolarity     = kFLEXIO_PinActiveHigh;
fxioTimerConfig.pinSelect       = DISPLAY_FLEXIO_OUTPUTPIN; /* Set pwm output */
fxioTimerConfig.timerMode       = kFLEXIO_TimerModeDisabled;
fxioTimerConfig.timerOutput     = kFLEXIO_TimerOutputOneNotAffectedByReset;
fxioTimerConfig.timerDecrement  = kFLEXIO_TimerDecSrcOnFlexIOClockShiftTimerOutput;
fxioTimerConfig.timerDisable    = kFLEXIO_TimerDisableNever;
fxioTimerConfig.timerEnable     = kFLEXIO_TimerEnabledAlways;
fxioTimerConfig.timerReset      = kFLEXIO_TimerResetNever;
fxioTimerConfig.timerStart      = kFLEXIO_TimerStartBitDisabled;
fxioTimerConfig.timerStop       = kFLEXIO_TimerStopBitDisabled;

/* Calculate timer lower and upper values of TIMCMP */
/* Calculate the nearest integer value for sum, using formula round(x) = (2 * floor(x) + 1) / 2 */
sum = ( DISPLAY_FLEXIO_CLOCK_FREQUENCY * 2 / freq_Hz + 1 ) / 2;

/* Calculate the nearest integer value for lowerValue, the high period of the pwm output */
lowerValue = ( sum * duty / 50 + 1 ) / 2;

/* Calculate upper value, the low period of the pwm output */
upperValue                   = sum - lowerValue;
fxioTimerConfig.timerCompare = ( ( upperValue - 1 ) << 8U ) | ( lowerValue - 1 );

FLEXIO_SetTimerConfig( DISPLAY_FLEXIO_BASEADDR, DISPLAY_FLEXIO_TIMER_CH, &fxioTimerConfig );
} /* flexio_pwm_init() */

/*********************************************************************
*
* @private
* flexio_pwm_start
*
* @brief Enables the timer by setting TIMOD to 8-bits PWM and start
*        generating the PWM
*
*********************************************************************/
static void flexio_pwm_start
    (
    void
    )
{
/* Set Timer mode to kFLEXIO_TimerModeDual8BitPWM to start timer */
DISPLAY_FLEXIO_BASEADDR->TIMCTL[DISPLAY_FLEXIO_TIMER_CH] |= FLEXIO_TIMCTL_TIMOD( kFLEXIO_TimerModeDual8BitPWM );
} /* flexio_pwm_start() */

/*********************************************************************
*
* @private
* flexio_pwm_set_logic
*
* @brief Disable pwm mode, and transfer to logic mode
*
* @param duty Specified duty in unit of %, with a range of [1, 99]
*
*********************************************************************/
static void flexio_pwm_set_logic
    (
    uint32_t duty
    )
{
flexio_timer_config_t fxioTimerConfig;

/* Configure the timer DISPLAY_FLEXIO_TIMER_CH for generating PWM */
fxioTimerConfig.triggerSelect   = FLEXIO_TIMER_TRIGGER_SEL_SHIFTnSTAT(0U);
fxioTimerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceInternal;
fxioTimerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveLow;
fxioTimerConfig.pinConfig       = kFLEXIO_PinConfigOutput;
fxioTimerConfig.pinSelect       = DISPLAY_FLEXIO_OUTPUTPIN; /* Set pwm output */
fxioTimerConfig.pinPolarity     = ( duty == MIN_DUTY_CYCLE_VALUE ) ? kFLEXIO_PinActiveHigh : kFLEXIO_PinActiveLow;
fxioTimerConfig.timerMode       = kFLEXIO_TimerModeDisabled;
fxioTimerConfig.timerOutput     = kFLEXIO_TimerOutputOneNotAffectedByReset;
fxioTimerConfig.timerDecrement  = kFLEXIO_TimerDecSrcOnFlexIOClockShiftTimerOutput;
fxioTimerConfig.timerDisable    = kFLEXIO_TimerDisableNever;
fxioTimerConfig.timerEnable     = kFLEXIO_TimerEnabledAlways;
fxioTimerConfig.timerReset      = kFLEXIO_TimerResetNever;
fxioTimerConfig.timerStart      = kFLEXIO_TimerStartBitDisabled;
fxioTimerConfig.timerStop       = kFLEXIO_TimerStopBitDisabled;
fxioTimerConfig.timerCompare    = 0x0000FFFF; /* Never Compare */

FLEXIO_SetTimerConfig( DISPLAY_FLEXIO_BASEADDR, DISPLAY_FLEXIO_TIMER_CH, &fxioTimerConfig );
} /* flexio_pwm_set_logic() */

/*********************************************************************
*
* @public
* pwm_init
*
* @brief Initialization of the flexio pwm modulem and set to default 50% duty cycle
*
*********************************************************************/
void pwm_init
    (
    void
    )
{
flexio_config_t fxioUserConfig;

/* Init flexio, use default configure
 * Disable doze and fast access mode
 * Enable in debug mode
 */
FLEXIO_GetDefaultConfig( &fxioUserConfig );
FLEXIO_Init( DISPLAY_FLEXIO_BASEADDR, &fxioUserConfig );
} /* pwm_init() */

/*********************************************************************
*
* @public
* PERIPHERAL_pwm_set_display_dutycycle
*
* @brief An public interface for application to change duty cycle of display.
*
*********************************************************************/
void PERIPHERAL_pwm_set_display_dutycycle
    (
    uint8_t duty_cycle
    )
{
// Handle duty cycle 1~99% as PWM mode
if( duty_cycle > MIN_DUTY_CYCLE_VALUE && duty_cycle < MAX_DUTY_CYCLE_VALUE )
    {
    flexio_pwm_init( DISPLAY_FLEXIO_FREQUENCY, duty_cycle );
    flexio_pwm_start();
    }
// Handle duty cycle 0% and 100% as pure logic mode
else if( duty_cycle == MIN_DUTY_CYCLE_VALUE || duty_cycle == MAX_DUTY_CYCLE_VALUE )
    {
    flexio_pwm_set_logic( duty_cycle );
    }
else
    {
    PRINTF("Invalid dutycycle %d, range 0 ~ 100 \r\n", duty_cycle );
    }
} /* PERIPHERAL_pwm_set_display_dutycycle() */
