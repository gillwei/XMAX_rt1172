/*********************************************************************
* @file
* pm_main.c
*
* @brief
* power management module
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "PM_pub.h"
#include "FreeRTOS.h"
#include "task.h"
#include "fsl_iomuxc.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"
#include "fsl_soc_src.h"
#include "timers.h"
#include "fsl_gpc.h"
#include "pin_mux.h"
#include "GRM_pub_prj.h"
#include "display_support.h"
#include "PERIPHERAL_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define GPC_CPU_MODE_CTRL               GPC_CPU_MODE_CTRL_0

#define WAKEUP_GPIO                     BOARD_INITPINS_IGN_WAKE_GPIO
#define WAKEUP_GPIO_PIN                 BOARD_INITPINS_IGN_WAKE_GPIO_PIN
#define WAKEUP_IRQ                      GPIO13_Combined_0_31_IRQn
#define WAKEUP_IRQ_HANDLER              GPIO13_Combined_0_31_IRQHandler

#define PM_TASK_TIME_DELAY              ( 10 )
#define PM_MONITOR_TIME_DELAY           ( 1000 )
#define GO_TO_SLEEP_TIME_MS             ( 40 )
#define GO_TO_SLEEP_COUNTER             ( GO_TO_SLEEP_TIME_MS / PM_TASK_TIME_DELAY )
#define FORCE_SLEEP_TIME_MS             ( 100 )
#define FORCE_SLEEP_COUNTER             ( FORCE_SLEEP_TIME_MS / PM_TASK_TIME_DELAY )

#define MAX_MODULE_NUMBER               ( 10 )
#define MAX_MODULE_NAME                 ( 32 )

#define MAX_OPERATION_VOLTAGE           ( 16500 )
#define MIN_OPERATION_VOLTAGE           ( 7500 )
#define SHUTDOWN_CONFIRM_COUNT          ( 5 )

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef struct
    {
    char name[MAX_MODULE_NAME];
    void ( *callback_func_ptr ) ( bool );
    bool is_registered;
    }pm_callback_type;

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
static int              register_cb_index    = 0;
static int              unregister_cb_number = 0;
static TickType_t       pm_task_delay        = pdMS_TO_TICKS( PM_TASK_TIME_DELAY );
static TickType_t       pm_monitor_delay     = pdMS_TO_TICKS( PM_MONITOR_TIME_DELAY );
static pm_callback_type module_cb[MAX_MODULE_NUMBER];
static bool             start_snvs           = false;

static uint8_t          shut_down_counter    = 0;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
static void set_wakeup_config
    (
    void
    );

static void enter_snvs
    (
    void
    );

static void snvs_pre_handler
    (
    void
    );

static void pm_main
    (
    void* arg
    );

static void pm_monitor
    (
    void* arg
    );

static void pm_create_task
    (
    void
    );

static bool go_to_snvs_timeout
    (
    volatile bool
    );

static bool force_snvs_timeout
    (
    void
    );

static void go_to_snvs_mode
    (
    void
    );

static void disable_all_wakeup_source
    (
    GPC_CPU_MODE_CTRL_Type *base
    );

static void enable_wakeup_source
    (
    uint32_t irq
    );

static void disable_wakeup_source
    (
    uint32_t irq
    );

static void notify_pm_callback
    (
    bool is_ign_on
    );

/*================================================================================================*/
/**
@brief   enable_wakeup_source
@details

@return None
@retval None
*/
/*================================================================================================*/

static void enable_wakeup_source
    (
    uint32_t irq
    )
{
GPC_CM_EnableIrqWakeup( GPC_CPU_MODE_CTRL, irq, true );
}

/*********************************************************************
*
* @private
* disable_wakeup_source
*
* @brief disable wakeup irq
*
*********************************************************************/
static void disable_wakeup_source
    (
    uint32_t irq
    )
{
GPC_CM_EnableIrqWakeup( GPC_CPU_MODE_CTRL, irq, false );
}

/*********************************************************************
*
* @private
* WAKEUP_IRQ_HANDLER
*
* @brief IRQ handler for wakeup source
*
*********************************************************************/
void WAKEUP_IRQ_HANDLER
    (
    void
    )
{
if( ( 1U << WAKEUP_GPIO_PIN ) & GPIO_GetPinsInterruptFlags( WAKEUP_GPIO ) )
    {
    GPIO_DisableInterrupts( WAKEUP_GPIO, 1U << WAKEUP_GPIO_PIN );
    GPIO_ClearPinsInterruptFlags( WAKEUP_GPIO, 1U << WAKEUP_GPIO_PIN );
    disable_wakeup_source( WAKEUP_IRQ );
    }
SDK_ISR_EXIT_BARRIER;
}

/*********************************************************************
*
* @public
* PM_init
*
* @brief initial function to create pm related task
*
*********************************************************************/
void PM_init
    (
    void
    )
{
pm_create_task();
}

/*********************************************************************
*
* @public
* PM_register_callback
*
* @brief the function for other task to register a pm notification callback
*
*********************************************************************/
void PM_register_callback
    (
    const char* const    name,
    void ( *func_ptr ) ( bool )
    )
{
strcpy( module_cb[register_cb_index].name , name );
module_cb[register_cb_index].callback_func_ptr = func_ptr;
module_cb[register_cb_index].is_registered = true;
register_cb_index++;
}

/*********************************************************************
*
* @public
* PM_register_callback
*
* @brief the function for other task to unregister a pm notification callback
*
*********************************************************************/
void PM_unregister_callback
    (
    const char* const    moduleName
    )
{
for( int idx = 0; idx < register_cb_index; idx++ )
    {
    if( !strcmp( moduleName, module_cb[idx].name ) )
        {
        if( module_cb[idx].is_registered  )
            {
            taskENTER_CRITICAL();
            module_cb[idx].is_registered = false;
            unregister_cb_number++;
            taskEXIT_CRITICAL();
            }
        }
    }
}

/*********************************************************************
*
* @public
* PM_system_reset
*
* @brief the function to perform system reset
*
*********************************************************************/
void PM_system_reset
    (
    void
    )
{
NVIC_SystemReset();
}

/*********************************************************************
*
* @private
* pm_create_task
*
* @brief The function to create PM related freeRTOS task
*
*********************************************************************/
static void pm_create_task
    (
    void
    )
{
if( pdPASS == xTaskCreate( pm_main, "pm_main", configMINIMAL_STACK_SIZE, NULL, TASK_PRIO_PM, NULL ) )
    {
    PRINTF( "pm_main create ok\r\n" );
    }
else
    {
    PRINTF( "pm_main create fail\r\n" );
    }

if( pdPASS == xTaskCreate( pm_monitor, "pm_monitor", configMINIMAL_STACK_SIZE * 2, NULL, TASK_PRIO_PM, NULL ) )
    {
    PRINTF( "pm_monitor create ok\r\n" );
    }
else
    {
    PRINTF( "pm_monitor create fail\r\n" );
    }
}

/*********************************************************************
*
* @private
* notify_pm_callback
*
* @brief The function to notifty all registered module with ACC status
*
*********************************************************************/
static void notify_pm_callback
    (
    volatile bool ign_status
    )
{
for( int idx = 0; idx < register_cb_index; idx++ )
    {
    module_cb[idx].callback_func_ptr( ign_status );
    }
}

/*********************************************************************
*
* @private
* go_to_snvs_timeout
*
* @brief The function is to check whether the SNVS timeout condition
*        is fulfill
*
*********************************************************************/
static bool go_to_snvs_timeout
    (
    volatile bool ign_status
    )
{
static int count          = 0;
if( !start_snvs )
    {
    if( ign_status == PM_IGN_ON )
        {
        count = 0;
        start_snvs = false;
        }
    else
        {
        count++;
        if( GO_TO_SLEEP_COUNTER == count )
            {
            count = 0;
            start_snvs = true;
            }
        }
    }
return start_snvs;
}

/*********************************************************************
*
* @private
* force_snvs_timeout
*
* @brief The function is to check whether the SNVS force timeout
*        condition is fulfill
*
*********************************************************************/
static bool force_snvs_timeout
    (
    void
    )
{
static int count = 0;
static bool force_snvs    = false;
if( !force_snvs )
    {
    count++;
    if( FORCE_SLEEP_COUNTER == count )
        {
        count = 0;
        force_snvs = true;
        }
    }
return force_snvs;
}

/*********************************************************************
*
* @private
* pm_main
*
* @brief This task checks the ign state and decide to go to SNVS or not.
*
*********************************************************************/
static void pm_main
    (
    void* arg
    )
{
volatile bool ign_status;
static bool pm_notified = false;

while( true )
    {
    ign_status = GPIO_ReadPinInput( WAKEUP_GPIO, WAKEUP_GPIO_PIN );

    if( go_to_snvs_timeout( ign_status ) )
        {
        if( pm_notified == false )
            {
            notify_pm_callback( ign_status );
            pm_notified = true;
            }
        if( force_snvs_timeout() )
            {
            go_to_snvs_mode();
            }
        }
    vTaskDelay( pm_task_delay );
    }
vTaskDelete( NULL );
}

/*********************************************************************
*
* @private
* pm_monitor
*
* @brief This task monitors if the voltage is in range or not.
*
*********************************************************************/
static void pm_monitor
    (
    void* arg
    )
{
static uint16_t vbatt_voltage = 0;

while( true )
    {
    vbatt_voltage = PERIPHERAL_adc_get_vbatt_converted();

    if( ( vbatt_voltage >= MAX_OPERATION_VOLTAGE ) || ( vbatt_voltage <= MIN_OPERATION_VOLTAGE ) )
        {
        if( ++shut_down_counter == SHUTDOWN_CONFIRM_COUNT )
            {
            go_to_snvs_mode();
            }
        }
    else
        {
        shut_down_counter = 0;
        }

    vTaskDelay( pm_monitor_delay );
    }
vTaskDelete( NULL );
}

/*********************************************************************
*
* @private
* go_to_snvs_mode
*
* @brief This function control the MCU to go into SNVS mode
*
*********************************************************************/
static void go_to_snvs_mode
    (
    void
    )
{
set_wakeup_config();
snvs_pre_handler();
enter_snvs();
}

/*********************************************************************
*
* @private
* disable_all_wakeup_source
*
* @brief This function disable all the wakeup source
*
*********************************************************************/
static void disable_all_wakeup_source
    (
    GPC_CPU_MODE_CTRL_Type *base
    )
{
uint8_t i;
for( i = 0; i < GPC_CPU_MODE_CTRL_CM_IRQ_WAKEUP_MASK_COUNT; i++ )
    {
    base->CM_IRQ_WAKEUP_MASK[i] |= 0xFFFFFFFF;
    }
}

/*********************************************************************
*
* @private
* set_wakeup_config
*
* @brief This function setup wakeup source config
*
*********************************************************************/
static void set_wakeup_config
    (
    void
    )
{
GPIO_ClearPinsInterruptFlags( WAKEUP_GPIO, 1U << WAKEUP_GPIO_PIN );
GPIO_EnableInterrupts( WAKEUP_GPIO, 1U << WAKEUP_GPIO_PIN );
EnableIRQ( WAKEUP_IRQ );
disable_all_wakeup_source( GPC_CPU_MODE_CTRL );
enable_wakeup_source( WAKEUP_IRQ );
}

/*********************************************************************
*
* @private
* snvs_pre_handler
*
* @brief This function do the function before we shutdown the system
*
*********************************************************************/
static void snvs_pre_handler
    (
    void
    )
{
PRINTF("Now shutting down the system...\r\n");
display_pre_handler();
}

/*********************************************************************
*
* @private
* enter_snvs
*
* @brief This function set the register for MCU to go into SNVS
*
*********************************************************************/
static void enter_snvs
    (
    void
    )
{
/* set SNVS flag on SNVS_GPR32 bit 1 for future check */
IOMUXC_SNVS_GPR->GPR32 |= IOMUXC_SNVS_GPR_GPR32_GPR( 1 << 1 );
IOMUXC_SNVS_GPR->GPR37 |= IOMUXC_SNVS_GPR_GPR37_SNVS_TAMPER_PUE_MASK;
SNVS->LPCR |= SNVS_LPCR_TOP(1);
while( true )
    {
    }
}

/*********************************************************************
*
* @public
* PM_get_ign_status
*
* @brief return the current IGN status PM_IGN_ON or PM_IGN_OFF
*
*********************************************************************/
bool PM_get_ign_status
    (
    void
    )
{
return GPIO_PinRead( BOARD_INITPINS_IGN_WAKE_GPIO, BOARD_INITPINS_IGN_WAKE_GPIO_PIN );
}

#ifdef __cplusplus
}
#endif
