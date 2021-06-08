/*********************************************************************
* @file
* test_vi.c
*
* @brief
* Test module - Vehicle info
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
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
#include "CAN_pub.h"
#include "VI_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define TEST_VI_PERIOD_MS                   ( 3000 )
#define VEHICLE_SPEED_DRIVER_DISTRACTION    ( 5 )

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
#if( UNIT_TEST_VI )
    static const int TEST_VI_TICK_COUNT = ( TEST_VI_PERIOD_MS / TEST_TICK_PERIOD_MS );
    static int       test_vi_tick = 0;
    static uint16_t  vehicle_speed = 0;
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
#if( UNIT_TEST_VI )
    /*********************************************************************
    *
    * @public
    * test_vi_proc
    *
    * Test module - vehicle info test process
    *
    *********************************************************************/
    void test_vi_proc
        (
        void
        )
    {
    if( test_vi_tick == 0 )
        {
        test_vi_tick = TEST_VI_TICK_COUNT;

        // toggle dd mode
        VI_notify_vehicle_data_changed( IL_CAN0_RXA_VEHICLE_INFO_2_IDX, IL_CAN0_VEHICLE_INFO_2_SPD_REAL_RXSIG_HANDLE, vehicle_speed );
        if( vehicle_speed == 0 )
            {
            vehicle_speed = VEHICLE_SPEED_DRIVER_DISTRACTION;
            }
        else
            {
            vehicle_speed = 0;
            }
        }
    test_vi_tick--;
    }

    /*********************************************************************
    *
    * @public
    * test_vi_int
    *
    * Test module - init vehicle info test
    *
    *********************************************************************/
    void test_vi_int
        (
        void
        )
    {
    }
#endif
