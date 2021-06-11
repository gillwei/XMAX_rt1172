/*********************************************************************
* @file
* test_navilite.c
*
* @brief
* Test module - navilite
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
#include "EW_pub.h"
#include "JPEG_pub.h"
#include "NAVILITE_pub.h"
#include "TEST_pub.h"
#include "test_priv.h"
#include "test_navilite.h"

#include "navilite_prv_packframe.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define TEST_NAVILITE_PERIOD_MS     ( 1000 )
// Turn TEST_SEND_FROM_MOBILE on to emulate the mobile sending requests to MCU
// and check if the protocols are working via callbacks
#define TEST_SEND_FROM_MOBILE 1
// Turn TEST_SEND_FROM_MCU on to send navilite requests to mobile
#define TEST_SEND_FROM_MCU 0
// Compiler Check
#if TEST_SEND_FROM_MOBILE && TEST_SEND_FROM_MCU
#error "TEST_SEND_FROM_MCU and TEST_SEND_FROM_MOBILE cannot be set 1 at the same time!! "
#endif

// Turn this on to see free memory status
#define TEST_NAVILITE_PRINT_FREEMEM 0

// Run forever or once
#define TEST_NAVILITE_RUN_FOREVER 1


// NOTE: Turn specific test function on for testing purpose
// aka: Simulate App requests -> LC
// TEST_SEND_FROM_MOBILE test units group
#define TEST_NAVILITE_SERVICETYPE_RAW_SEND_TBT_TEST_CASE 0
#define TEST_NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_ETA_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_NAVIGATION_STATUS_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_CURROADNAME_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_NEXTTURNDIST_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_TBTLIST_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_TBTLIST_UPDATE_ITEM_DATA 0
#define TEST_NAVILITE_SERVICETYPE_ACTIVETURBLIST_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_FAVPOILIST_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_FAVPOILIST_UPDATE_ITEM_DATA 0
#define TEST_NAVILITE_SERVICETYPE_GASPOITURNLIST_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_GASPOITURNLIST_UPDATE_ITEM_DATA 0
#define TEST_NAVILITE_SERVICETYPE_NAVIEVENTTEXTUPDATE 0
#define TEST_NAVILITE_SERVICETYPE_HOMESETTING_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_OFFICESETTING_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_MAP_ZOOM_LEVEL_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_ROUTE_CALC_PROGRESS_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_DAYNIGHT_MODE_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_BT_THROUGHTPUT_TIMEOUT_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_SPEED_LIMIT_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_VIA_POINT_COUNT_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_DIALOG_EVENT_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE_ACK 0
#define TEST_NAVILITE_SERVICETYPE_MCU_ESN_UPDATE_ACK 0

// ####################################################
// ## TEST_SEND_FROM_MCU  test units   group         ##
// ## aka: Send navilite app requests from LC to App ##
// ####################################################

// MCU INFO REPORT command from MCU
#define TEST_NAVILITE_SERVICETYPE_MCU_ESN_UPDATE 0
#define TEST_NAVILITE_SERVICETYPE_MCU_SYSINFO_UPDATE 0

// APP request command from MCU
#define TEST_NAVILITE_SERVICETYPE_APP_START_ROUTE_REQUEST 0
#define TEST_NAVILITE_SERVICETYPE_APP_STOP_ROUTE_REQUEST 0
#define TEST_NAVILITE_SERVICETYPE_APP_SKIP_NEXT_WAYPOINT_REQUEST 0
#define TEST_NAVILITE_SERVICETYPE_APP_MAP_ZOOM_IN_REQUEST 0
#define TEST_NAVILITE_SERVICETYPE_APP_MAP_ZOOM_OUT_REQUEST 0
#define TEST_NAVILITE_SERVICETYPE_APP_GO_HOME_REQUEST 0
#define TEST_NAVILITE_SERVICETYPE_APP_GO_OFFICE_REQUEST 0
#define TEST_NAVILITE_SERVICETYPE_APP_GET_FAVORITE_LIST_REQUEST 0
#define TEST_NAVILITE_SERVICETYPE_APP_GET_STATION_LIST_REQUEST 0
#define TEST_NAVILITE_SERVICETYPE_APP_START_IMAGE_FRAME_REQUEST 0
#define TEST_NAVILITE_SERVICETYPE_APP_STOP_IMAGE_FRAME_REQUEST 0
#define TEST_NAVILITE_SERVICETYPE_APP_GET_RECENT_LIST_REQUEST 0

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
#if( UNIT_TEST_NAVILITE )
    static const int TEST_NAVILITE_TICK_COUNT = ( TEST_NAVILITE_PERIOD_MS / TEST_TICK_PERIOD_MS );
    static int test_NAVILITE_tick = 0;
    static int test_NAVILITE_mobile_requests_send = 0;
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

#if( UNIT_TEST_NAVILITE )
    void test_navilite_update_callback_connected
        (
        uint8_t mode
        )
    {
        PRINTF( "[test] navilite session connected\r\n" );
        test_NAVILITE_mobile_requests_send = 1;
    }

    void test_navilite_update_callback_disconnected
         (
         uint8_t mode
         )
    {
        PRINTF( "[test] navilite session disconnected\r\n" );
        test_NAVILITE_mobile_requests_send = 0;
    }
#endif

#if( UNIT_TEST_NAVILITE && TEST_SEND_FROM_MOBILE )
    /*********************************************************************
    *
    * @private
    * test_NAVILITE_send_requests
    *
    * send navilite request from app for testing purpose
    *
    *********************************************************************/
    void test_NAVILITE_send_requests_from_mobile
        (
        void
        )
    {
    static int i = 0;
    navilite_message frame = { 0 };
    PRINTF( "\r\n ---- NAVILITE UNIT TESTS (%d) ----\r\n", i++ );
    vTaskDelay(  1500 / portTICK_PERIOD_MS );

    #if( TEST_NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE )
        PRINTF( "[NAVILITE-TESTUNIT] - NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE\r\n" );
        frame = NAVILITE_pack_frame_update_imageframe( (uint8_t*)&navilite_jpeg_test_data[0], NAVILITE_JPG_DATA_SIZE, NAVILITE_IMAGE_NAVIGATION );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_ETA_UPDATE )
        PRINTF( "[NAVILITE-TESTUNIT] - NAVILITE_SERVICETYPE_ETA_UPDATE\r\n" );
        frame = NAVILITE_pack_frame_update_eta( 965530 );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_NAVIGATION_STATUS_UPDATE )
        PRINTF( "[NAVILITE-TESTUNIT] - NAVILITE_SERVICETYPE_NAVIGATION_STATUS_UPDATE\r\n" );
        frame = NAVILITE_pack_frame_update_navigationstatus( 1 );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_CURROADNAME_UPDATE )
        frame = NAVILITE_pack_frame_update_currentroadname( (uint8_t*)"ChungHua ROAD", strlen( "ChungHua ROAD" ) );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_NEXTTURNDIST_UPDATE )
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_TBTLIST_UPDATE )
        PRINTF( "\r\n[NAVILITE-TESTUNIT] - TEST_NAVILITE_SERVICETYPE_TBTLIST_UPDATE(SIZE NOTIFY)\r\n" );
        frame = NAVILITE_pack_frame_update_nexttbtlist( 49, 1 ); // prepare a list of 3 item
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_RAW_SEND_IMAGEFRAME_TEST_CASE )
         PRINTF( "[NAVILITE-TESTUNIT] - TEST_NAVILITE_SERVICETYPE_RAW_SEND_IMAGEFRAME_TEST_CASE\r\n" );
         NAVILITE_send_as_mobile_raw( (uint8_t*)navilite_jpeg_cmd_data, NAVILITE_JPG_CMD_SIZE );
         NAVILITE_send_as_mobile_raw( (uint8_t*)navilite_jpeg_test_data, NAVILITE_JPG_DATA_SIZE );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_RAW_SEND_TBT_TEST_CASE )

        PRINTF( "\r\nPerforming TBT test cases\r\n" );
        uint8_t raw_msg_list_size[] =
            {
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x05 ,0x03 ,0x00 ,0x00 ,0x00 ,0x01 ,0x11 ,0x00 ,0x00
            };

        uint8_t raw_msg_list_data[] =
            {
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x19 ,0x00 ,0x00 ,0x00 ,0x01 ,0x01 ,0x00 ,0x23 ,0x0f ,0x01 ,0x00 ,0x00 ,0xa0 ,0x41 ,0x6d ,0xe5 ,0x8f ,0xb3 ,0xe8 ,0xbd ,0x89 ,0xe5 ,0xbb ,0xba ,0xe6 ,0x88 ,0x90 ,0xe8 ,0xb7 ,0xaf ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x1f ,0x00 ,0x00 ,0x00 ,0x01 ,0x02 ,0x00 ,0x22 ,0x15 ,0x01 ,0x00 ,0x00 ,0xaf ,0x43 ,0x6d ,0xe5 ,0xb7 ,0xa6 ,0xe8 ,0xbd ,0x89 ,0xe5 ,0xa4 ,0xa7 ,0xe5 ,0x90 ,0x8c ,0xe8 ,0xb7 ,0xaf ,0xe4 ,0xba ,0x8c ,0xe6 ,0xae ,0xb5 ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x1a ,0x00 ,0x00 ,0x00 ,0x01 ,0x03 ,0x00 ,0x23 ,0x0f ,0x02 ,0x00 ,0x00 ,0x20 ,0x41 ,0x6b ,0x6d ,0xe5 ,0x8f ,0xb3 ,0xe8 ,0xbd ,0x89 ,0xe6 ,0xba ,0x90 ,0xe9 ,0x81 ,0xa0 ,0xe8 ,0xb7 ,0xaf ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x22 ,0x00 ,0x00 ,0x00 ,0x01 ,0x04 ,0x00 ,0x08 ,0x18 ,0x01 ,0x00 ,0x00 ,0xfa ,0x43 ,0x6d ,0xe7 ,0xb9 ,0xbc ,0xe7 ,0xba ,0x8c ,0xe8 ,0xa1 ,0x8c ,0xe9 ,0xa7 ,0x9b ,0xe6 ,0xb2 ,0xbf ,0xe6 ,0xb0 ,0xb4 ,0xe6 ,0xba ,0x90 ,0xe8 ,0xb7 ,0xaf ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x48 ,0x00 ,0x00 ,0x00 ,0x01 ,0x05 ,0x00 ,0x07 ,0x3e ,0x01 ,0x00 ,0x00 ,0x16 ,0x43 ,0x6d ,0xe4 ,0xbf ,0x9d ,0xe6 ,0x8c ,0x81 ,0xe5 ,0x8f ,0xb3 ,0xe5 ,0x81 ,0xb4 ,0xe9 ,0x80 ,0xb2 ,0xe5 ,0x85 ,0xa5 ,0xe5 ,0x88 ,0xb0 ,0xe5 ,0x8f ,0xb0 ,0x36 ,0x32 ,0xe8 ,0x90 ,0xac ,0xe9 ,0x87 ,0x8c ,0xe7 ,0x91 ,0x9e ,0xe6 ,0xbf ,0xb1 ,0xe7 ,0xb7 ,0x9a ,0xe5 ,0x89 ,0x8d ,0xe5 ,0xbe ,0x80 ,0xe7 ,0x91 ,0x9e ,0xe8 ,0x8a ,0xb3 ,0xe3 ,0x80 ,0x81 ,0xe7 ,0x91 ,0x9e ,0xe6 ,0xbf ,0xb1 ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x44 ,0x00 ,0x00 ,0x00 ,0x01 ,0x06 ,0x00 ,0x07 ,0x39 ,0x02 ,0x00 ,0x00 ,0x20 ,0x41 ,0x6b ,0x6d ,0xe4 ,0xbf ,0x9d ,0xe6 ,0x8c ,0x81 ,0xe5 ,0x8f ,0xb3 ,0xe5 ,0x81 ,0xb4 ,0xe9 ,0x80 ,0xb2 ,0xe5 ,0x85 ,0xa5 ,0xe5 ,0x88 ,0xb0 ,0xe7 ,0x91 ,0x9e ,0xe8 ,0x8a ,0xb3 ,0xe7 ,0x91 ,0x9e ,0xe6 ,0xbf ,0xb1 ,0xe7 ,0xab ,0xaf ,0xe4 ,0xba ,0xa4 ,0xe6 ,0xb5 ,0x81 ,0xe9 ,0x81 ,0x93 ,0xe5 ,0x89 ,0x8d ,0xe5 ,0xbe ,0x80 ,0xe8 ,0xb2 ,0xa2 ,0xe5 ,0xaf ,0xae ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x2f ,0x00 ,0x00 ,0x00 ,0x01 ,0x07 ,0x00 ,0x06 ,0x24 ,0x02 ,0x00 ,0x00 ,0xd8 ,0x41 ,0x6b ,0x6d ,0xe4 ,0xbf ,0x9d ,0xe6 ,0x8c ,0x81 ,0xe5 ,0xb7 ,0xa6 ,0xe5 ,0x81 ,0xb4 ,0xe6 ,0xb2 ,0xbf ,0xe8 ,0x88 ,0x88 ,0xe9 ,0x9a ,0x86 ,0xe8 ,0xa1 ,0x97 ,0xe7 ,0xb9 ,0xbc ,0xe7 ,0xba ,0x8c ,0xe8 ,0xa1 ,0x8c ,0xe9 ,0xa7 ,0x9b ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x26 ,0x00 ,0x00 ,0x00 ,0x01 ,0x08 ,0x00 ,0x08 ,0x1b ,0x02 ,0x00 ,0x00 ,0x10 ,0x42 ,0x6b ,0x6d ,0xe7 ,0xb9 ,0xbc ,0xe7 ,0xba ,0x8c ,0xe8 ,0xa1 ,0x8c ,0xe9 ,0xa7 ,0x9b ,0xe6 ,0xb2 ,0xbf ,0xe9 ,0xa0 ,0xad ,0xe5 ,0x9f ,0x8e ,0xe5 ,0xa4 ,0xa7 ,0xe6 ,0xa9 ,0x8b ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x1a ,0x00 ,0x00 ,0x00 ,0x01 ,0x09 ,0x00 ,0x23 ,0x0f ,0x02 ,0x00 ,0x00 ,0x50 ,0x41 ,0x6b ,0x6d ,0xe5 ,0x8f ,0xb3 ,0xe8 ,0xbd ,0x89 ,0xe7 ,0x92 ,0xb0 ,0xe6 ,0xb2 ,0xb3 ,0xe8 ,0xb7 ,0xaf ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x23 ,0x00 ,0x00 ,0x00 ,0x01 ,0x0a ,0x00 ,0x06 ,0x18 ,0x02 ,0x00 ,0x00 ,0x98 ,0x41 ,0x6b ,0x6d ,0xe9 ,0x9d ,0xa0 ,0xe5 ,0xb7 ,0xa6 ,0xe6 ,0xb2 ,0xbf ,0xe5 ,0x93 ,0xa1 ,0xe5 ,0xb1 ,0xb1 ,0xe8 ,0xb7 ,0xaf ,0xe4 ,0xb8 ,0x89 ,0xe6 ,0xae ,0xb5 ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x20 ,0x00 ,0x00 ,0x00 ,0x01 ,0x0b ,0x00 ,0x23 ,0x15 ,0x02 ,0x00 ,0x00 ,0x60 ,0x41 ,0x6b ,0x6d ,0xe5 ,0x8f ,0xb3 ,0xe8 ,0xbd ,0x89 ,0xe6 ,0xb3 ,0xb0 ,0xe9 ,0x9b ,0x85 ,0xe8 ,0xb7 ,0xaf ,0xe4 ,0xb8 ,0x89 ,0xe6 ,0xae ,0xb5 ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x19 ,0x00 ,0x00 ,0x00 ,0x01 ,0x0c ,0x00 ,0x22 ,0x0f ,0x01 ,0x00 ,0x00 ,0x0c ,0x43 ,0x6d ,0xe5 ,0xb7 ,0xa6 ,0xe8 ,0xbd ,0x89 ,0xe8 ,0x8b ,0xb1 ,0xe5 ,0xa3 ,0xab ,0xe6 ,0xa9 ,0x8b ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x20 ,0x00 ,0x00 ,0x00 ,0x01 ,0x0d ,0x00 ,0x23 ,0x15 ,0x02 ,0x00 ,0x00 ,0x04 ,0x42 ,0x6b ,0x6d ,0xe5 ,0x8f ,0xb3 ,0xe8 ,0xbd ,0x89 ,0xe6 ,0xb3 ,0xb0 ,0xe9 ,0x9b ,0x85 ,0xe8 ,0xb7 ,0xaf ,0xe4 ,0xb8 ,0x83 ,0xe6 ,0xae ,0xb5 ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x20 ,0x00 ,0x00 ,0x00 ,0x01 ,0x0e ,0x00 ,0x23 ,0x15 ,0x02 ,0x00 ,0x00 ,0x30 ,0x41 ,0x6b ,0x6d ,0xe5 ,0x8f ,0xb3 ,0xe8 ,0xbd ,0x89 ,0xe6 ,0xb3 ,0xb0 ,0xe9 ,0x9b ,0x85 ,0xe8 ,0xb7 ,0xaf ,0xe4 ,0xb8 ,0x83 ,0xe6 ,0xae ,0xb5 ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x20 ,0x00 ,0x00 ,0x00 ,0x01 ,0x0f ,0x00 ,0x23 ,0x15 ,0x02 ,0x9a ,0x99 ,0xd9 ,0x3f ,0x6b ,0x6d ,0xe5 ,0x8f ,0xb3 ,0xe8 ,0xbd ,0x89 ,0xe6 ,0xb3 ,0xb0 ,0xe9 ,0x9b ,0x85 ,0xe8 ,0xb7 ,0xaf ,0xe4 ,0xb8 ,0x83 ,0xe6 ,0xae ,0xb5 ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x20 ,0x00 ,0x00 ,0x00 ,0x01 ,0x10 ,0x00 ,0x23 ,0x15 ,0x02 ,0x00 ,0x00 ,0xd0 ,0x40 ,0x6b ,0x6d ,0xe5 ,0x8f ,0xb3 ,0xe8 ,0xbd ,0x89 ,0xe4 ,0xb8 ,0xad ,0xe8 ,0x88 ,0x88 ,0xe8 ,0xb7 ,0xaf ,0xe4 ,0xb8 ,0x80 ,0xe6 ,0xae ,0xb5 ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x1a ,0x00 ,0x00 ,0x00 ,0x01 ,0x11 ,0x00 ,0x23 ,0x0f ,0x02 ,0x9a ,0x99 ,0x79 ,0x40 ,0x6b ,0x6d ,0xe5 ,0x8f ,0xb3 ,0xe8 ,0xbd ,0x89 ,0xe6 ,0xad ,0xa6 ,0xe9 ,0x99 ,0xb5 ,0xe8 ,0xb7 ,0xaf ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x1a ,0x00 ,0x00 ,0x00 ,0x01 ,0x12 ,0x00 ,0x23 ,0x0f ,0x02 ,0x66 ,0x66 ,0x26 ,0x40 ,0x6b ,0x6d ,0xe5 ,0x8f ,0xb3 ,0xe8 ,0xbd ,0x89 ,0xe6 ,0xad ,0xa6 ,0xe9 ,0x99 ,0xb5 ,0xe8 ,0xb7 ,0xaf ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x20 ,0x00 ,0x00 ,0x00 ,0x01 ,0x13 ,0x00 ,0x22 ,0x15 ,0x02 ,0xcd ,0xcc ,0xbc ,0x40 ,0x6b ,0x6d ,0xe5 ,0xb7 ,0xa6 ,0xe8 ,0xbd ,0x89 ,0xe9 ,0x9b ,0xa2 ,0xe9 ,0x96 ,0x8b ,0xe6 ,0xad ,0xa6 ,0xe9 ,0x99 ,0xb5 ,0xe8 ,0xb7 ,0xaf ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x17 ,0x00 ,0x00 ,0x00 ,0x01 ,0x14 ,0x00 ,0x00 ,0x0c ,0x02 ,0x00 ,0x00 ,0x40 ,0x41 ,0x6b ,0x6d ,0xe6 ,0x8a ,0xb5 ,0xe9 ,0x81 ,0x94 ,0xe6 ,0xb2 ,0xb3 ,0xe6 ,0xb5 ,0x81 ,
            0x6e ,0x41 ,0x6c ,0x40 ,0x01 ,0x06 ,0x61 ,0x17 ,0x00 ,0x00 ,0x00 ,0x01 ,0x14 ,0x00 ,0x00 ,0x0c ,0x02 ,0x00 ,0x00 ,0x40 ,0x41 ,0x6b ,0x6d ,0xe6 ,0x8a ,0xb5 ,0xe9 ,0x81 ,0x94 ,0xe6 ,0xb2 ,0xb3 ,0xe6 ,0xb5 ,0x81
            };

        NAVILITE_send_as_mobile_raw( raw_msg_list_size, sizeof( raw_msg_list_size ) / sizeof(uint8_t) );
        NAVILITE_send_as_mobile_raw( raw_msg_list_data, sizeof( raw_msg_list_data ) / sizeof(uint8_t) );
        vTaskDelay(  1000 / portTICK_PERIOD_MS );

    #endif

    #if( TEST_NAVILITE_SERVICETYPE_TBTLIST_UPDATE_ITEM_DATA )
        navilite_tbt_list_type list_item;

        uint8_t* item_desc_demo[3] = {
            (uint8_t*)"That is item 1",
            (uint8_t*)"This is item 2",
            (uint8_t*)"This is item 3"
        };
        uint8_t* item_unit_demo[3] = {
            (uint8_t*)"km1",
            (uint8_t*)"km2",
            (uint8_t*)"km3",
        };


        // demo 1st data item
        list_item.list_item_index = 0;
        list_item.icon_index = 11;
        list_item.desc_size = (uint8_t)strlen( (char*)item_desc_demo[0] );
        list_item.dist_unit_size = (uint8_t)strlen( (char*)item_unit_demo[0] );
        list_item.distance = NAVILITE_float_to_bytes( 123.4 );
        list_item.distance_unit = item_unit_demo[0];
        list_item.desc = item_desc_demo[0];
        frame = NAVILITE_pack_frame_update_nexttbtlist_itemdata( &list_item );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );

        // demo 2nd data item
        list_item.list_item_index = 1;
        list_item.icon_index = 33;
        list_item.desc_size = (uint8_t)strlen( (char*)item_desc_demo[1] );
        list_item.dist_unit_size = (uint8_t)strlen( (char*)item_unit_demo[1] );
        list_item.distance = NAVILITE_float_to_bytes( 123.4 );
        list_item.distance_unit = item_unit_demo[1];
        list_item.desc = item_desc_demo[1];
        frame = NAVILITE_pack_frame_update_nexttbtlist_itemdata( &list_item );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
        // demo 3rd data item
        list_item.list_item_index = 2;
        list_item.icon_index = (uint32_t)44;
        list_item.desc_size = (uint8_t)strlen( (char*)item_desc_demo[2] );
        list_item.dist_unit_size = (uint8_t)strlen( (char*)item_unit_demo[2] );
        list_item.distance = NAVILITE_float_to_bytes( 123.4 );
        list_item.distance_unit = item_unit_demo[2];
        list_item.desc = item_desc_demo[2];
        frame = NAVILITE_pack_frame_update_nexttbtlist_itemdata( &list_item );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_ACTIVETURBLIST_UPDATE )
        PRINTF( "\r\n[NAVILITE-TESTUNIT--] - TEST_NAVILITE_SERVICETYPE_ACTIVETURBLIST_UPDATE\r\n" );
        static int active_idx = 0;
        active_idx++;
        frame = NAVILITE_pack_frame_update_activetbtitem( 22 );
        PRINTF("data value:%d\r\n", frame.data_value );
        PRINTF("data value:%c%c%c%c\r\n", frame.magic_code[0],frame.magic_code[1],frame.magic_code[2],frame.magic_code[3] );
        PRINTF("frame type:%d\r\n", frame.frame_type );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_FAVPOILIST_UPDATE )


        PRINTF( "\r\n[NAVILITE-TESTUNIT] - TEST_NAVILITE_SERVICETYPE_FAVLIST_UPDATE(SIZE NOTIFY)\r\n" );

        frame = NAVILITE_pack_frame_update_nextfavlist( 3, 0 ); // prepare a list of 3 item
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_FAVPOILIST_UPDATE_ITEM_DATA )
        navilite_fav_list_type fav_list_item;

        uint8_t* fav_item_desc_demo[3] =
        {
            (uint8_t*)"That is item 1",
            (uint8_t*)"This is item 2",
            (uint8_t*)"This is item 3"
        };
        uint8_t* fav_item_unit_demo[3] =
        {
             (uint8_t*)"km1",
             (uint8_t*)"km2",
             (uint8_t*)"km3",
        };

        // demo 1st data item
        fav_list_item.list_item_index = 0;
        // list_item.icon_index = 11;
        fav_list_item.desc_size = (uint8_t)strlen( (char*)fav_item_desc_demo[0] );
        fav_list_item.dist_unit_size = (uint8_t)strlen( (char*)fav_item_unit_demo[0] );
        fav_list_item.distance = NAVILITE_float_to_bytes( 123.4 );
        fav_list_item.distance_unit = fav_item_unit_demo[0];
        fav_list_item.desc = fav_item_desc_demo[0];
        frame = NAVILITE_pack_frame_update_nextfavlist_itemdata( &fav_list_item );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );

        // demo 2nd data item
        fav_list_item.list_item_index = 1;
        // list_item.icon_index = 33;
        fav_list_item.desc_size = (uint8_t)strlen( (char*)fav_item_desc_demo[1] );
        fav_list_item.dist_unit_size = (uint8_t)strlen( (char*)fav_item_unit_demo[1] );
        fav_list_item.distance = NAVILITE_float_to_bytes( 123.4 );
        fav_list_item.distance_unit = fav_item_unit_demo[1];
        fav_list_item.desc = fav_item_desc_demo[1];
        frame = NAVILITE_pack_frame_update_nextfavlist_itemdata( &fav_list_item );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );

        // demo 3rd data item
        fav_list_item.list_item_index = 2;
        // list_item.icon_index = (uint32_t)44;
        fav_list_item.desc_size = (uint8_t)strlen( (char*)fav_item_desc_demo[2] );
        fav_list_item.dist_unit_size = (uint8_t)strlen( (char*)fav_item_unit_demo[2] );
        fav_list_item.distance = NAVILITE_float_to_bytes( 123.4 );
        fav_list_item.distance_unit = fav_item_unit_demo[2];
        fav_list_item.desc = fav_item_desc_demo[2];
        frame = NAVILITE_pack_frame_update_nextfavlist_itemdata( &fav_list_item );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_GASPOITURNLIST_UPDATE )
        PRINTF( "\r\n[NAVILITE-TESTUNIT] - TEST_NAVILITE_SERVICETYPE_GASPOILIST_UPDATE(SIZE NOTIFY)\r\n" );

        frame = NAVILITE_pack_frame_update_nextgaslist( 3, 0 ); // prepare a list of 3 item
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_GASPOITURNLIST_UPDATE_ITEM_DATA )
        navilite_gas_list_type gas_list_item;

        uint8_t* gas_item_desc_demo[3] =
        {
            (uint8_t*)"That is gas item 1",
            (uint8_t*)"This is gas item 2",
            (uint8_t*)"This is gas item 3"
        };
        uint8_t* gas_item_unit_demo[3] =
        {
            (uint8_t*)"km1",
            (uint8_t*)"km2",
            (uint8_t*)"km3",
        };

        // demo 1st data item
        gas_list_item.list_item_index = 0;
        // list_item.icon_index = 11;
        gas_list_item.desc_size = (uint8_t)strlen( (char*)gas_item_desc_demo[0] );
        gas_list_item.dist_unit_size = (uint8_t)strlen( (char*)gas_item_unit_demo[0] );
        gas_list_item.distance = NAVILITE_float_to_bytes( 123.4 );
        gas_list_item.distance_unit = gas_item_unit_demo[0];
        gas_list_item.desc = gas_item_desc_demo[0];
        frame = NAVILITE_pack_frame_update_nextgaslist_itemdata( &gas_list_item );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
        // demo 2nd data item
        gas_list_item.list_item_index = 1;
        // list_item.icon_index = 33;
        gas_list_item.desc_size = (uint8_t)strlen( (char*)gas_item_desc_demo[1] );
        gas_list_item.dist_unit_size = (uint8_t)strlen( (char*)gas_item_unit_demo[1] );
        gas_list_item.distance = NAVILITE_float_to_bytes( 123.4 );
        gas_list_item.distance_unit = gas_item_unit_demo[1];
        gas_list_item.desc = gas_item_desc_demo[1];
        frame = NAVILITE_pack_frame_update_nextgaslist_itemdata( &gas_list_item );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
        // demo 3rd data item
        gas_list_item.list_item_index = 2;
        // list_item.icon_index = (uint32_t)44;
        gas_list_item.desc_size = (uint8_t)strlen( (char*)gas_item_desc_demo[2] );
        gas_list_item.dist_unit_size = (uint8_t)strlen( (char*)gas_item_unit_demo[2] );
        gas_list_item.distance = NAVILITE_float_to_bytes( 123.4 );
        gas_list_item.distance_unit = gas_item_unit_demo[2];
        gas_list_item.desc = gas_item_desc_demo[2];
        frame = NAVILITE_pack_frame_update_nextgaslist_itemdata( &gas_list_item );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_NAVIEVENTTEXTUPDATE )
        frame = NAVILITE_pack_frame_update_navieventtext( "Alarm Test", 10, 1, 1 );
        NAVILITE_send_as_mobile( &frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_HOMESETTING_UPDATE )
        frame = NAVILITE_pack_frame_update_homelocationsetting( 1 );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_OFFICESETTING_UPDATE )
        frame = NAVILITE_pack_frame_update_officelocationsetting( 1 );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_MAP_ZOOM_LEVEL_UPDATE )
        frame = NAVILITE_pack_frame_update_zoomlevel( 12, 20 );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_ROUTE_CALC_PROGRESS_UPDATE )
        int progress = 0;
        for( progress = 0; progress <= 100; progress += 20 )
            {
            frame = NAVILITE_pack_frame_update_routecalcprogress( progress );
            PRINTF("[NAVILITE-MOBILE-SIM] SIMULATE CALC PROGRESS = %d\r\n", frame.data_value );
            NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
            vTaskDelay(  1600 / portTICK_PERIOD_MS );
            }
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_DAYNIGHT_MODE_UPDATE )
        frame = NAVILITE_pack_frame_update_daynightmode( NAVILITE_DAYNIGHT_NIGHT_MODE );
         NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_BT_THROUGHTPUT_TIMEOUT_UPDATE )
         frame = NAVILITE_pack_frame_update_bttimeout( 5 );
         NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_SPEED_LIMIT_UPDATE )
        frame = NAVILITE_pack_frame_update_speedlimit( 123 );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_VIA_POINT_COUNT_UPDATE )
        frame = NAVILITE_pack_frame_update_viapointcount( 4 );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_DIALOG_EVENT_UPDATE )
        PRINTF( "[NAVILITE-TESTUNIT] - NAVILITE_SERVICETYPE_DIALOG_EVENT_UPDATE\r\n" );
        frame = NAVILITE_pack_frame_update_dialog_event( 123, NAVILITE_DIALOGTYPE_OK, (uint8_t*)"Choose a route", 14, 5, 100 );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
        vTaskDelay(  1500 / portTICK_PERIOD_MS );
        PRINTF( "[NAVILITE-TESTUNIT] - NAVILITE_SERVICETYPE_DIALOG_DISMISS_UPDATE\r\n" );
        frame = NAVILITE_pack_frame_update_dialog_dismiss( 123 );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE_ACK )
        frame = NAVILITE_pack_frame_app_report_service_ack( NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE_ACK );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_MCU_ESN_UPDATE_ACK )
        PRINTF( "[NAVILITE-TESTUNIT] - NAVILITE_SERVICETYPE_MCU_ESN_UPDATE_ACK\r\n" );
        frame = NAVILITE_pack_frame_update_serviceack( NAVILITE_SERVICETYPE_MCU_ESN_UPDATE_ACK );
        NAVILITE_send_as_mobile( (uint8_t*)&frame, sizeof( frame ) );
    #endif

    #if( TEST_NAVILITE_PRINT_FREEMEM )
        const size_t freeHeap = xPortGetFreeHeapSize();
        PRINTF( "[MEMORY FREE]:%d KB\r\n", freeHeap );
    #endif

    #if( !TEST_NAVILITE_RUN_FOREVER )
        PRINTF( "\r\n== End of TEST ==\r\n" );
	    while( 1 ) ;
    #endif
    }

#endif

#if( UNIT_TEST_NAVILITE && TEST_SEND_FROM_MCU )
    /*********************************************************************
    *
    * @private
    * test_NAVILITE_send_requests_from_mcu
    *
    * send navilite requests from mcu to mobile for testing purpose
    *
    *********************************************************************/
    void test_NAVILITE_send_requests_from_mcu
        (
        void
        )
    {
    static int i = 0;
    navilite_message frame = { 0 };
    PRINTF( "NAVILITE UNIT TESTS from mcu to mobile(%d)\r\n", i++ );

    #if( TEST_NAVILITE_SERVICETYPE_MCU_ESN_UPDATE )
        PRINTF( "Wait 15s to begin\r\n ");
        vTaskDelay(  15000 / portTICK_PERIOD_MS );
        PRINTF( "[TEST_NAVILITE_SERVICETYPE_MCU_ESN_UPDATE]\r\n" );
        NAVILITE_report_app_esn( "012345678" );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_MCU_SYSINFO_UPDATE )
        PRINTF( "Wait 15s to begin\r\n ");
        vTaskDelay(  15000 / portTICK_PERIOD_MS );
        PRINTF( "[TEST_NAVILITE_SERVICETYPE_MCU_SYSINFO_UPDATE]\r\n" );
        NAVILITE_report_app_sysinfo( "SYSINFO: NaviLite ver 1.0 / LinkCard Demo Test" );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_APP_START_ROUTE_REQUEST )
        PRINTF( "Wait 15s to begin\r\n ");
        vTaskDelay(  15000 / portTICK_PERIOD_MS );
        PRINTF( "[NAVILITE_SERVICETYPE_APP_START_ROUTE_REQUEST]\r\n" );
        NAVILITE_request_app_startroute( 0 );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_APP_STOP_ROUTE_REQUEST )
        PRINTF( "wait 15s ...\r\n");
        vTaskDelay(  15000 / portTICK_PERIOD_MS );
        PRINTF( "[NAVILITE_SERVICETYPE_APP_STOP_ROUTE_REQUEST]\r\n" );
        NAVILITE_request_app_stoproute();
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_APP_SKIP_NEXT_WAYPOINT_REQUEST )
        PRINTF( "wait 15s ...\r\n");
        vTaskDelay(  15000 / portTICK_PERIOD_MS );
        PRINTF( "[NAVILITE_SERVICETYPE_APP_SKIP_NEXT_WAYPOINT_REQUEST]\r\n" );
        NAVILITE_request_app_skip_nextwaypoint();
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_APP_MAP_ZOOM_IN_REQUEST )
        PRINTF( "[NAVILITE_SERVICETYPE_APP_MAP_ZOOM_IN_REQUEST]\r\n" );
        NAVILITE_request_app_zoomin();
        PRINTF( "wait 15s ...\r\n");
        vTaskDelay(  15000 / portTICK_PERIOD_MS );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_APP_MAP_ZOOM_OUT_REQUEST )
        PRINTF( "[NAVILITE_SERVICETYPE_APP_MAP_ZOOM_OUT_REQUEST]\r\n" );
        NAVILITE_request_app_zoomout();
        PRINTF( "wait 15s ...\r\n");
        vTaskDelay(  15000 / portTICK_PERIOD_MS );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_APP_GO_HOME_REQUEST )
        PRINTF( "[NAVILITE_SERVICETYPE_APP_GO_HOME_REQUEST]\r\n" );
        PRINTF( "send with with NAVILITE_ROUTE_NEW_ROUTE\r\n" );
        NAVILITE_request_app_gohome( NAVILITE_ROUTE_NEW_ROUTE );
        PRINTF( "send with with NAVILITE_ROUTE_NEXT_STOP\r\n" );
        NAVILITE_request_app_gohome( NAVILITE_ROUTE_NEXT_STOP );
        PRINTF( "send with with NAVILITE_ROUTE_LAST_STOP\r\n" );
        NAVILITE_request_app_gohome( NAVILITE_ROUTE_LAST_STOP );
        PRINTF( "wait 15s ...\r\n");
        vTaskDelay(  15000 / portTICK_PERIOD_MS );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_APP_GO_OFFICE_REQUEST )
        PRINTF( "[NAVILITE_SERVICETYPE_APP_GO_OFFICE_REQUEST]\r\n" );
        PRINTF( "send with with NAVILITE_ROUTE_NEW_ROUTE\r\n" );
        NAVILITE_request_app_gooffice( NAVILITE_ROUTE_NEW_ROUTE );
        PRINTF( "send with with NAVILITE_ROUTE_NEXT_STOP\r\n" );
        NAVILITE_request_app_gooffice( NAVILITE_ROUTE_NEXT_STOP );
        PRINTF( "send with with NAVILITE_ROUTE_LAST_STOP\r\n" );
        NAVILITE_request_app_gooffice( NAVILITE_ROUTE_LAST_STOP );
        PRINTF( "wait 15s ...\r\n");
        vTaskDelay(  15000 / portTICK_PERIOD_MS );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_APP_GET_FAVORITE_LIST_REQUEST )
        PRINTF( "[NAVILITE_SERVICETYPE_APP_GET_FAVORITE_LIST_REQUEST]\r\n" );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_APP_GET_STATION_LIST_REQUEST )
        PRINTF( "[NAVILITE_SERVICETYPE_APP_GET_STATION_LIST_REQUEST]\r\n" );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_APP_START_IMAGE_FRAME_REQUEST )
        PRINTF( "[NAVILITE_SERVICETYPE_APP_START_IMAGE_FRAME_REQUEST]\r\n" );
        NAVILITE_request_app_start_imageframe_update();
        PRINTF( "wait 15s ...\r\n");
        vTaskDelay(  15000 / portTICK_PERIOD_MS );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_APP_STOP_IMAGE_FRAME_REQUEST )
        PRINTF( "[NAVILITE_SERVICETYPE_APP_STOP_IMAGE_FRAME_REQUEST]\r\n" );
        NAVILITE_request_app_stop_imageframe_update();
        PRINTF( "wait 15s ...\r\n");
        vTaskDelay(  15000 / portTICK_PERIOD_MS );
    #endif

    #if( TEST_NAVILITE_SERVICETYPE_APP_GET_RECENT_LIST_REQUEST )
        PRINTF( "[NAVILITE_SERVICETYPE_APP_GET_RECENT_LIST_REQUEST]\r\n" );
    #endif

        }
    #endif


#if( UNIT_TEST_NAVILITE )
    /*********************************************************************
    *
    * @public
    * test_NAVILITE_proc
    *
    * Test module - proc jpeg test
    *
    *********************************************************************/
    void test_navilite_proc
        (
        void
        )
    {
    if( test_NAVILITE_tick == 0 )
        {
        test_NAVILITE_tick = TEST_NAVILITE_TICK_COUNT;

    #if( TEST_SEND_FROM_MOBILE )
        if( test_NAVILITE_mobile_requests_send )
            {
            test_NAVILITE_send_requests_from_mobile();
            }
    #endif

    #if( TEST_SEND_FROM_MCU )
        PRINTF( "test navilite connection status: %d\r\n", test_NAVILITE_mobile_requests_send );
        if( test_NAVILITE_mobile_requests_send )
            {
            test_NAVILITE_send_requests_from_mcu();
            }
    #endif
        }
    test_NAVILITE_tick--;
    }
#endif

#if( UNIT_TEST_NAVILITE )
    /*********************************************************************
    *
    * @public
    * test_NAVILITE_int
    *
    * Test module - init navilite test
    *
    *********************************************************************/
    void test_navilite_int
        (
        void
        )
    {
    PRINTF( "[NAVILITE-TEST] INIT\r\n" );
    NAVILITE_register_update_callback_preconnected( test_navilite_update_callback_connected );
    NAVILITE_register_update_callback_connected( test_navilite_update_callback_connected );
    NAVILITE_register_update_callback_disconnected( test_navilite_update_callback_disconnected );
    return;
    }
#endif
