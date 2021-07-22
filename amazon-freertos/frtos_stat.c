/*********************************************************************
* @file
* frtos_stat.c
*
* @brief
* FreeRTOS run-time statistics
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
#include "fsl_debug_console_conf.h"
#include "fsl_gpt.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define STAT_GPT                GPT2
#define STAT_PRINT_PERIOD_MS    ( 2000 )
#define STAT_PRINT_BUFFER_SIZE  ( 1024 )

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
#if( RTOS_STAT_ENABLE == 1)
    static gpt_config_t gpt_config;
    AT_NONCACHEABLE_SECTION( static char stat_buffer[STAT_PRINT_BUFFER_SIZE] );
    AT_NONCACHEABLE_SECTION( static char print_buffer[DEBUG_CONSOLE_PRINTF_MAX_LOG_LEN] );
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @public
* FRTOS_print_task_status
*
* Print the task state, priority, stack base and remaining size
*
* @param task_handle Task handle
*
*********************************************************************/
void FRTOS_print_task_status
    (
    const TaskHandle_t task_handle
    )
{
#if( configUSE_TRACE_FACILITY == 1 )
    if( NULL != task_handle )
        {
        TaskStatus_t task_details;
        vTaskGetInfo( task_handle, &task_details, pdTRUE, eInvalid );

        PRINTF( "task name:         %s\r\n", task_details.pcTaskName );
        PRINTF( "task state:        %d\r\n", task_details.eCurrentState );
        PRINTF( "task priority:     %d\r\n", task_details.uxCurrentPriority );
        PRINTF( "task stack base:   0x%x\r\n", task_details.pxStackBase );
        PRINTF( "task stack remain: %d byte\r\n", task_details.usStackHighWaterMark );
        }
#else
    PRINTF( "vTaskGetInfo() not available\r\n" );
#endif
}

#if( RTOS_STAT_ENABLE == 1 )
    /*********************************************************************
    *
    * @private
    * frtos_stat_timer_count
    *
    * Return the counter of the timer for FreeRTOS run time statistics
    *
    * @return the counter of the timer
    *
    *********************************************************************/
    int FRTOS_stat_timer_count
        (
        void
        )
    {
    return GPT_GetCurrentTimerCount( STAT_GPT );
    }

    /*********************************************************************
    *
    * @private
    * frtos_stat_timer_config
    *
    * Config and start the timer for FreeRTOS run-time statistics
    *
    *********************************************************************/
    void FRTOS_stat_timer_config
        (
        void
        )
    {
    GPT_GetDefaultConfig( &gpt_config );
    gpt_config.clockSource = kGPT_ClockSource_LowFreq;
    GPT_Init( STAT_GPT, &gpt_config );
    GPT_StartTimer( STAT_GPT );
    }

    /*********************************************************************
    *
    * @private
    * stat_print
    *
    * Print the statistics of FreeRTOS tasks and the remain heap size
    *
    *********************************************************************/
    static void stat_print
        (
        void
        )
    {
    vTaskGetRunTimeStats( stat_buffer );
    int stat_len  = strlen( stat_buffer );
    int print_len = sizeof( print_buffer ) - 1;
    int i = 0;
    while( i < stat_len )
        {
        if( ( i + print_len ) < stat_len )
            {
            memcpy( print_buffer, &stat_buffer[i], print_len );
            print_buffer[print_len] = '\0';
            PRINTF( "%s", print_buffer );
            }
        else
            {
            PRINTF( "%s", &stat_buffer[i] );
            }
        i += print_len;
        }
    PRINTF( "remain FreeRTOS heap: %d / %d (KB)\r\n\r\n", xPortGetFreeHeapSize(), configTOTAL_HEAP_SIZE );
    }

    /*********************************************************************
    *
    * @private
    * timer_callback
    *
    * Timer callback of FreeRTOS run-time statistics
    *
    *********************************************************************/
    static void timer_callback
        (
        TimerHandle_t timer_handle
        )
    {
    stat_print();
    }

    /*********************************************************************
    *
    * @private
    * timer_create
    *
    * Create timer to print FreeRTOS run-time statistics
    *
    * @param cycle_time timer cycle time (ms)
    *
    *********************************************************************/
    static void timer_create
        (
        int cycle_time
        )
    {
    TimerHandle_t timer_handle = xTimerCreate( "stat_timer", pdMS_TO_TICKS( cycle_time ), pdTRUE, ( void* ) 0, timer_callback );
    configASSERT( NULL != timer_handle );

    BaseType_t result = xTimerStart( timer_handle, 0 );
    configASSERT( pdPASS == result );
    }

    /*********************************************************************
    *
    * @public
    * FRTOS_stat_init
    *
    * Init FreeRTOS run-time statistics
    *
    *********************************************************************/
    void FRTOS_stat_init
        (
        void
        )
    {
    timer_create( STAT_PRINT_PERIOD_MS );
    }
#endif

