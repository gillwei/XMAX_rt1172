/*********************************************************************
* @file
* test_jpeg.c
*
* @brief
* Test module - JPEG
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
#include "JPEG_pub.h"
#include "TEST_pub.h"
#include "test_priv.h"
#include "test_jpeg.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define TEST_JPEG_PERIOD_MS     ( 1000 )


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
#if( UNIT_TEST_JPEG )
    static const int TEST_JPEG_TICK_COUNT = ( TEST_JPEG_PERIOD_MS / TEST_TICK_PERIOD_MS );
    static int test_jpeg_tick = 0;
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
#if( UNIT_TEST_JPEG )
    /*********************************************************************
    *
    * @public
    * TEST_jpeg_decode_done
    *
    * Callback from JPEG module when JPEG decode is done
    *
    *********************************************************************/
    void TEST_jpeg_decode_done
        (
        int result
        )
    {
    if( RESULT_SUCCESS == result )
        {
        EW_notify_navi_map_update();
        }
    else
        {
        PRINTF( "%s fail %d\r\n", __FUNCTION__, result );
        }
    }

    /*********************************************************************
    *
    * @private
    * test_jpeg_test_decode
    *
    * Test JPEG decode with the jpeg data in the flash
    *
    *********************************************************************/
    void test_jpeg_test_decode
        (
        void
        )
    {
    PRINTF( "%s\r\n", __FUNCTION__ );
    uint8_t* jpeg_buf = JPEG_get_jpeg_buffer();
    if( NULL != jpeg_buf )
        {
        memcpy( jpeg_buf, jpeg_test_data, JPEG_TEST_DATA_SIZE );
        JPEG_notify_received( JPEG_TEST_DATA_SIZE, jpeg_buf, &TEST_jpeg_decode_done );
        }
    else
        {
        PRINTF( "JPEG buffer not available\r\n" );
        }
    }

    /*********************************************************************
    *
    * @public
    * test_jpeg_proc
    *
    * Test module - proc jpeg test
    *
    *********************************************************************/
    void test_jpeg_proc
        (
        void
        )
    {
    if( test_jpeg_tick == 0 )
        {
        test_jpeg_tick = TEST_JPEG_TICK_COUNT;
        test_jpeg_test_decode();
        }
    test_jpeg_tick--;
    }

    /*********************************************************************
    *
    * @public
    * test_jpeg_int
    *
    * Test module - init jpeg test
    *
    *********************************************************************/
    void test_jpeg_int
        (
        void
        )
    {
    return;
    }
#endif


