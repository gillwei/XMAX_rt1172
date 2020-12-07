/*********************************************************************
* @file
* pm_main.c
*
* @brief
* power management module
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
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
/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/
#define GPC_CPU_MODE_CTRL GPC_CPU_MODE_CTRL_0

#define WAKEUP_GPIO                     GPIO13
#define WAKEUP_GPIO_PIN                 ( 0U )
#define WAKEUP_IRQ                      GPIO13_Combined_0_31_IRQn
#define WAKEUP_IRQ_HANDLER              GPIO13_Combined_0_31_IRQHandler

#define TASK_TIME_DELAY                 ( 10 )
#define GO_TO_SLEEP_TIME_MS             ( 40 )
#define GO_TO_SLEEP_COUNTER             ( GO_TO_SLEEP_TIME_MS / TASK_TIME_DELAY )
#define FORCE_SLEEP_TIME_MS             ( 100 )
#define FORCE_SLEEP_COUNTER             ( FORCE_SLEEP_TIME_MS / TASK_TIME_DELAY )

#define MAX_MODULE_NUMBER               ( 10 )
#define MAX_MODULE_NAME                 ( 32 )
/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/

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
static TickType_t       task_delay           = pdMS_TO_TICKS( TASK_TIME_DELAY );
static pm_callback_type module_cb[MAX_MODULE_NUMBER];
static bool             start_snvs    = false;

/*--------------------------------------------------------------------
                        PROTOTYPES
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

/*================================================================================================*/
/**
@brief   disable_wakeup_source
@details

@return None
@retval None
*/
/*================================================================================================*/

static void disable_wakeup_source
    (
    uint32_t irq
    )
{
GPC_CM_EnableIrqWakeup( GPC_CPU_MODE_CTRL, irq, false );
}
/*================================================================================================*/
/**
@brief   WAKEUP_IRQ_HANDLER
@details

@return None
@retval None
*/
/*================================================================================================*/

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

/*================================================================================================*/
/**
@brief   PM_init
@details

@return None
@retval None
*/
/*================================================================================================*/

void PM_init
    (
    void
    )
{
pm_create_task();
}

/*================================================================================================*/
/**
@brief   PM_register_callback
@details

@return None
@retval None
*/
/*================================================================================================*/
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

/*================================================================================================*/
/**
@brief   PM_unregister_callback
@details

@return None
@retval None
*/
/*================================================================================================*/
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

/*================================================================================================*/
/**
@brief   PM_system_reset
@details

@return None
@retval None
*/
/*================================================================================================*/

void PM_system_reset
    (
    void
    )
{
NVIC_SystemReset();
}

/*================================================================================================*/
/**
@brief   pm_create_task
@details

@return None
@retval None
*/
/*================================================================================================*/
static void pm_create_task
    (
    void
    )
{
if( pdPASS == xTaskCreate( pm_main, "pm_main", ( configMINIMAL_STACK_SIZE ), NULL, TASK_PRIO_PM, NULL ) )
    {
    PRINTF("%s ok\r\n", __FUNCTION__ );
    }
else
    {
    PRINTF("%s fail\r\n", __FUNCTION__ );
    }
}

/*================================================================================================*/
/**
@brief   notify_pm_callback
@detail

@return None
@retval None
*/
/*================================================================================================*/

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

/*================================================================================================*/
/**
@brief   go_to_snvs_timeout
@detail

@return None
@retval None
*/
/*================================================================================================*/
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

/*================================================================================================*/
/**
@brief   force_snvs_timeout
@details

@return None
@retval None
*/
/*================================================================================================*/
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

/*================================================================================================*/
/**
@brief   pm_main
@details

@return None
@retval None
*/
/*================================================================================================*/
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
            set_wakeup_config();
            snvs_pre_handler();
            enter_snvs();
            }
        }
    vTaskDelay( task_delay );
    }
vTaskDelete( NULL );
}

/*================================================================================================*/
/**
@brief   disable_all_wakeup_source
@details

@return None
@retval None
*/
/*================================================================================================*/
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
/*================================================================================================*/
/**
@brief   set_wakeup_config
@details

@return None
@retval None
*/
/*================================================================================================*/

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

/*================================================================================================*/
/**
@brief   snvs_pre_handler
@details

@return None
@retval None
*/
/*================================================================================================*/

static void snvs_pre_handler
    (
    void
    )
{
PRINTF("Now shutting down the system...\r\n");
}

/*================================================================================================*/
/**
@brief   enter_snvs
@details

@return None
@retval None
*/
/*================================================================================================*/

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

#ifdef __cplusplus
}
#endif
