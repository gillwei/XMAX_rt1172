/*********************************************************************
* @file
* test_display.c
*
* @brief
* Test module - display test
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
#include "EW_pub.h"
#include "TEST_pub.h"
#include "test_priv.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define TEST_PRODUCTION_PERIOD_MS               ( 1000 )
#define TEST_PRODUCTION_DISPLAY_PATTERN_NUM     ( 17 )

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
#if( UNIT_TEST_PRODUCTION )
    static const int TEST_PRODUCTION_TICK_COUNT = ( TEST_PRODUCTION_PERIOD_MS / TEST_TICK_PERIOD_MS );
    static int test_production_tick = 0;
    static int test_factory_display_pattern_idx = 1;
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
#if( UNIT_TEST_PRODUCTION )
    /*********************************************************************
    *
    * @private
    * test_production_display
    *
    * Test factory display pattern
    *
    *********************************************************************/
    void test_production_display
        (
        void
        )
    {
    PRINTF( "%s %d\r\n", __FUNCTION__, test_factory_display_pattern_idx );

    if( test_factory_display_pattern_idx <= TEST_PRODUCTION_DISPLAY_PATTERN_NUM )
        {
        EW_test_display_pattern( test_factory_display_pattern_idx );
        test_factory_display_pattern_idx++;
        }
    else
        {
        EW_quit_test();
        test_factory_display_pattern_idx = 1;
        }
    }

    /*********************************************************************
    *
    * @public
    * test_production_proc
    *
    * Test module - proc unit test for production test
    *
    *********************************************************************/
    void test_production_proc
        (
        void
        )
    {
    if( test_production_tick == 0 )
        {
        test_production_tick = TEST_PRODUCTION_TICK_COUNT;
        test_production_display();
        }
    test_production_tick--;
    }

    /*********************************************************************
    *
    * @public
    * test_production_int
    *
    * Test module - init unit test for production test
    *
    *********************************************************************/
    void test_production_int
        (
        void
        )
    {
    return;
    }
#endif
