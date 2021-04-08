/*********************************************************************
* @file
* test_inspection.c
*
* @brief
* Test module - Inspection test
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
#include "VI_pub.h"
#include "CAN_pub.h"
#include "test_priv.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define TEST_INSPECTION_PERIOD_MS               ( 1000 )
#define TEST_INSPECTION_DISPLAY_TOTAL           ( 10 )

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
#if( UNIT_TEST_INSPECTION )
    static const int TEST_INSPECTION_TICK_COUNT = ( TEST_INSPECTION_PERIOD_MS / TEST_TICK_PERIOD_MS );
    static uint32_t test_inspection_tick = 0;
    static uint32_t display_pattern_idx = 1;
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
#if( UNIT_TEST_INSPECTION )
    /*********************************************************************
    *
    * @private
    * test_inspection_display
    *
    * Test inspection display pattern
    *
    *********************************************************************/
    void test_inspection_display
        (
        void
        )
    {
    PRINTF( "%s %d\r\n", __FUNCTION__, display_pattern_idx );

    if( display_pattern_idx < TEST_INSPECTION_DISPLAY_TOTAL )
        {
        VI_notify_vehicle_data_changed( IL_CAN0_RXF_FACT_INSP_NS_REQ_IDX, IL_CAN0_FACT_INSP_NS_REQ_RXSIG_HANDLE, 1 );
        VI_notify_vehicle_data_changed( IL_CAN0_RXF_FACT_INSP_NS_REQ_IDX, IL_CAN0_FACT_INSP_NS_REQCODE_RXSIG_HANDLE, display_pattern_idx );
        display_pattern_idx++;
        }
    else
        {
        display_pattern_idx = 0;
        VI_notify_vehicle_data_changed( IL_CAN0_RXF_FACT_INSP_NS_REQ_IDX, IL_CAN0_FACT_INSP_NS_REQ_RXSIG_HANDLE, 3 );
        VI_notify_vehicle_data_changed( IL_CAN0_RXF_FACT_INSP_NS_REQ_IDX, IL_CAN0_FACT_INSP_NS_REQCODE_RXSIG_HANDLE, 0 );
        }
    }

    /*********************************************************************
    *
    * @public
    * test_inspection_proc
    *
    * Test module - proc unit test for inspection test
    *
    *********************************************************************/
    void test_inspection_proc
        (
        void
        )
    {
    if( test_inspection_tick == 0 )
        {
        test_inspection_tick = TEST_INSPECTION_TICK_COUNT;
        test_inspection_display();
        }
    test_inspection_tick--;
    }

    /*********************************************************************
    *
    * @public
    * test_inspection_int
    *
    * Test module - init unit test for inspection test
    *
    *********************************************************************/
    void test_inspection_int
        (
        void
        )
    {
    return;
    }
#endif


