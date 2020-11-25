/*********************************************************************
* @file
* test_factory.c
*
* @brief
* Test module - Factory test
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
#define TEST_FACTORY_PERIOD_MS              ( 1000 )
#define TEST_FACTORY_DISPLAY_PATTERN_NUM    ( 17 )

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
#if( UNIT_TEST_FACTORY )
    static const int TEST_FACTORY_TICK_COUNT = ( TEST_FACTORY_PERIOD_MS / TEST_TICK_PERIOD_MS );
    static int test_factory_tick = 0;
    static int test_factory_display_pattern_idx = 1;
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
#if( UNIT_TEST_FACTORY )
    /*********************************************************************
    *
    * @private
    * test_factory_display
    *
    * Test factory display pattern
    *
    *********************************************************************/
    void test_factory_display
        (
        void
        )
    {
    PRINTF( "%s %d\r\n", __FUNCTION__, test_factory_display_pattern_idx );

    if( test_factory_display_pattern_idx <= TEST_FACTORY_DISPLAY_PATTERN_NUM )
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
    * test_factory_proc
    *
    * Test module - proc unit test for factory test
    *
    *********************************************************************/
    void test_factory_proc
        (
        void
        )
    {
    if( test_factory_tick == 0 )
        {
        test_factory_tick = TEST_FACTORY_TICK_COUNT;
        test_factory_display();
        }
    test_factory_tick--;
    }

    /*********************************************************************
    *
    * @public
    * test_factory_int
    *
    * Test module - init unit test for factory test
    *
    *********************************************************************/
    void test_factory_int
        (
        void
        )
    {
    return;
    }
#endif


