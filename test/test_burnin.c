/*********************************************************************
* @file
* test_burnin.c
*
* @brief
* Test module - Unit test for burn-in UI flow
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
#define TEST_BURN_IN_PROC_MS                ( 1000 )
#define TEST_BURN_IN_INIT_DELAY_SEC         ( 3 )    // time to wait before start burn-in
#define TEST_BURN_IN_START_SEC              ( 1810 ) // start time of burning
#define TEST_BURN_IN_DURATION_SEC           ( 25 )   // duration of burn-in test
#define TEST_BURN_IN_SHOW_RESULT_SEC        ( 3 )
#define TEST_BURN_IN_RESULT                 ( true )

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
#if( UNIT_TEST_BURNIN )
    static const int TEST_BURN_IN_TICK_COUNT = ( TEST_BURN_IN_PROC_MS / TEST_TICK_PERIOD_MS );
    static uint32_t test_burn_in_tick = 0;
    static uint32_t test_burn_in_time_sec = 0;
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
#if( UNIT_TEST_BURNIN )
    /*********************************************************************
    *
    * @private
    * test_burnin_flow
    *
    * Test factory display pattern
    *
    *********************************************************************/
    void test_burnin_flow
        (
        void
        )
    {
    test_burn_in_time_sec++;
    if( TEST_BURN_IN_INIT_DELAY_SEC == test_burn_in_time_sec )
        {
        EW_start_burn_in();
        test_burn_in_time_sec = TEST_BURN_IN_START_SEC;
        }
    else if( ( TEST_BURN_IN_START_SEC + TEST_BURN_IN_DURATION_SEC ) > test_burn_in_time_sec )
        {
        EW_update_burn_in_time( test_burn_in_time_sec - TEST_BURN_IN_INIT_DELAY_SEC );
        }
    else if( ( TEST_BURN_IN_START_SEC + TEST_BURN_IN_DURATION_SEC ) == test_burn_in_time_sec )
        {
        EW_show_burn_in_result( TEST_BURN_IN_RESULT );
        }
    else if( ( TEST_BURN_IN_START_SEC + TEST_BURN_IN_DURATION_SEC + TEST_BURN_IN_SHOW_RESULT_SEC ) == test_burn_in_time_sec )
        {
        EW_quit_test();
        }
    else
        {
        // empty
        }
    }

    /*********************************************************************
    *
    * @private
    * test_burnin_proc
    *
    * Test module - proc unit test for factory test
    *
    *********************************************************************/
    void test_burnin_proc
        (
        void
        )
    {
    if( test_burn_in_tick == 0 )
        {
        test_burn_in_tick = TEST_BURN_IN_TICK_COUNT;
        test_burnin_flow();
        }
    test_burn_in_tick--;
    }

    /*********************************************************************
    *
    * @private
    * test_burnin_int
    *
    * Test module - init unit test for factory test
    *
    *********************************************************************/
    void test_burnin_int
        (
        void
        )
    {
    return;
    }
#endif


