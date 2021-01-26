/*********************************************************************
* @file
* test_adc.c
*
* @brief
* Test module - Unit test for outputing ADC value and converted value
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "fsl_debug_console.h"
#include "TEST_pub.h"
#include "test_priv.h"
#include "PERIPHERAL_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define TEST_ADC_PROC_MS                ( 500 )

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
#if( UNIT_TEST_ADC )
    static const int TEST_ADC_TICK_COUNT = ( TEST_ADC_PROC_MS / TEST_TICK_PERIOD_MS );
    static uint32_t test_adc_tick = 0;
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
#if( UNIT_TEST_ADC )

    /*********************************************************************
    *
    * @private
    * test_adc_flow
    *
    * Test adc value and converted value
    *
    *********************************************************************/
    void test_adc_flow
        (
        void
        )
    {
    PRINTF( "TFT NTC : ADC raw = %04d, temp value = %d \n\r", PERIPHERAL_adc_get_tft_ntc(), PERIPHERAL_adc_get_tft_ntc_converted() );
    PRINTF( "PCBA NTC: ADC raw = %04d, temp value = %d \n\r", PERIPHERAL_adc_get_pcba_ntc(), PERIPHERAL_adc_get_pcba_ntc_converted() );
    PRINTF( "VBATT   : ADC raw = %04d, voltage value = %d \n\r", PERIPHERAL_adc_get_vbatt(), PERIPHERAL_adc_get_vbatt_converted() );
    PRINTF( "\n\r" );
    }

    /*********************************************************************
    *
    * @private
    * test_adc_proc
    *
    * Test module - proc unit test for adc test
    *
    *********************************************************************/
    void test_adc_proc
        (
        void
        )
    {
    if( test_adc_tick == 0 )
        {
        test_adc_tick = TEST_ADC_TICK_COUNT;
        test_adc_flow();
        }
    test_adc_tick--;
    }

    /*********************************************************************
    *
    * @private
    * test_adc_int
    *
    * Test module - init unit test for adc test
    *
    *********************************************************************/
    void test_adc_int
        (
        void
        )
    {
    return;
    }
#endif


