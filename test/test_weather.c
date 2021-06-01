/*********************************************************************
* @file
* test_weather.c
*
* @brief
* Test module - weather
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
#include "TEST_pub.h"
#include "BC_motocon_pub.h"
#include "test_priv.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define NUM_WEA_ITEM                                ( 10 )
#define TEST_WEA_PERIOD_MS                          ( 1000 )
#define MAX_WEA_LOC_LEN                             ( 64 )
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
#if( UNIT_TEST_WEA )
    static bc_motocon_weather_info_t weather_info_obj[NUM_WEA_ITEM];
    static const int TEST_WEA_TICK_COUNT = ( TEST_WEA_PERIOD_MS / TEST_TICK_PERIOD_MS );
    static int test_weather_tick = 0;
    static bool is_wea_info_ready = 0;
    static char weather_location[MAX_WEA_LOC_LEN] = "New York";
    static int weather_weekday = 3;
#endif
/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

#if( UNIT_TEST_WEA )

    /*********************************************************************
    *
    * @public
    * TEST_weather_location
    *
    * Return received weather location.
    *
    * @return weather location.
    *
    *********************************************************************/
    void TEST_weather_location
        (
        char** wea_loc
        )
    {
    *wea_loc = weather_location;
    }

    /*********************************************************************
    *
    * @public
    * TEST_weather_weekday
    *
    * Return received weather weekday.
    *
    * @return weather weekday.
    *
    *********************************************************************/
    int TEST_weather_weekday
        (
        void
        )
    {
    return weather_weekday;
    }

    /*********************************************************************
    *
    * @public
    * test_get_weather_obj
    *
    * Test weather info delivery
    *
    *********************************************************************/
    bc_motocon_weather_info_t* TEST_get_weather_obj
        (
        const int index
        )
    {
    return &weather_info_obj[index];
    }


    /*********************************************************************
    *
    * @private
    * test_wea_proc
    *
    * Test module - weather test procedure
    *
    *********************************************************************/
    void test_wea_proc
        (
        void
        )
    {
    if( test_weather_tick == 0 )
        {
        test_weather_tick = TEST_WEA_TICK_COUNT;
        if( !is_wea_info_ready )
            {
            for( int i = 0; i < NUM_WEA_ITEM; i++ )
                {
                weather_info_obj[i].time = i;
                // Test different weather type and check if correct weather icon can be displayed on the UI.
                switch( i )
                    {
                    case 0:
                        weather_info_obj[i].type = BC_MOTOCON_WEATHER_SMOG;
                        break;
                    case 1:
                        weather_info_obj[i].type = BC_MOTOCON_WEATHER_SCATTERED_STORM_DAY;
                        break;
                    case 2:
                        weather_info_obj[i].type = BC_MOTOCON_WEATHER_SCATTERED_SHOWERS_NIGHT;
                        break;
                    case 3:
                        weather_info_obj[i].type = BC_MOTOCON_WEATHER_SNOW_HEAVY;
                        break;
                    case 4:
                        weather_info_obj[i].type = BC_MOTOCON_WEATHER_CLOUDY;
                        break;
                    case 5:
                        weather_info_obj[i].type = BC_MOTOCON_WEATHER_HAIL;
                        break;
                    case 6:
                        weather_info_obj[i].type = BC_MOTOCON_WEATHER_RAIN_HEAVY;
                        break;
                    case 7:
                        weather_info_obj[i].type = BC_MOTOCON_WEATHER_NO_DATA;
                        break;
                    case 8:
                        weather_info_obj[i].type = BC_MOTOCON_WEATHER_CLEAR;
                        break;
                    case 9:
                        weather_info_obj[i].type = BC_MOTOCON_WEATHER_CLOUDY_NIGHT;
                        break;
                    default:
                        // Set Sunny type to default weather type.
                        weather_info_obj[i].type = BC_MOTOCON_WEATHER_SUNNY;
                        break;
                    }
                weather_info_obj[i].temperature = 32.2;
                weather_info_obj[i].temperature_max = 36.5;
                weather_info_obj[i].temperature_min = 28.7;
                weather_info_obj[i].rain_probability = 70;
                }
            is_wea_info_ready = 1;
            EW_notify_weather_info_update();
            }
        }
    test_weather_tick--;
    }

    /*********************************************************************
    *
    * @public
    * test_wea_int
    *
    * Test module - init weather test
    *
    *********************************************************************/
    void test_wea_int
        (
        void
        )
    {
    PRINTF( "%s \r\n", __FUNCTION__ );
    }
#endif
