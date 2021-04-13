/*********************************************************************
* @file
* test_notification.c
*
* @brief
* Test module - Factory test
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <stdio.h>
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "fsl_debug_console.h"
#include "EW_pub.h"
#include "TEST_pub.h"
#include "test_priv.h"
#include "NTF_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define TEST_NOTIFICATION_PERIOD_MS              ( 120*1000 )

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
#if( UNIT_TEST_NOTIFICATION )
    static const int TEST_NOTIFICATION_TICK_COUNT = ( TEST_NOTIFICATION_PERIOD_MS / TEST_TICK_PERIOD_MS );
    static int test_notification_tick = TEST_NOTIFICATION_TICK_COUNT;
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
#if( UNIT_TEST_NOTIFICATION )
    /*********************************************************************
    *
    * @public
    * test_notification_proc
    *
    * Test module - proc unit test for notification test
    *
    *********************************************************************/
    void test_notification_proc
        (
        void
        )
    {
    uint8_t  title[32];
    uint8_t  subtitle[32];
    uint8_t  message[32];
    notification_time_t received_time;

    if( test_notification_tick == 0 )
        {
        received_time.year   = 2021;
        received_time.month  = 4;
        received_time.day    = 13;
        received_time.hour   = 8;
        received_time.minute = 0;
        received_time.second = 0;
        for( int i = 1; i <= NOTIFICATION_MAX_NUM; i++ )
            {
            sprintf( (char*)title, "title%03d", i );
            sprintf( (char*)subtitle, "subtitle%03d", i );
            sprintf( (char*)message, "message %03d", i );

            NTF_add_notification( i, title, subtitle, message, EnumNotificationCategoryMESSAGE, received_time );

            received_time.minute++;
            if( 60 == received_time.minute )
                {
                received_time.minute = 0;
                received_time.hour++;
                }
            }
        }
    test_notification_tick--;
    }

    /*********************************************************************
    *
    * @public
    * test_notification_int
    *
    * Test module - init unit test for notification test
    *
    *********************************************************************/
    void test_notification_int
        (
        void
        )
    {
    return;
    }
#endif


