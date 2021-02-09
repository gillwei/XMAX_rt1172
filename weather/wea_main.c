/*********************************************************************
* @file
* wea_main.c
*
* @brief
* Weather module - main
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
#include "BC_motocon_pub.h"
#include "WEA_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define NUM_WEA_ITEM                                10

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
void WEA_receive_wea_info( const bc_motocon_weather_info_t* weather_info );
void WEA_receive_wea_location( const uint8_t length, const uint8_t* content );

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
static bc_motocon_weather_info_t weather_info_obj[NUM_WEA_ITEM];
static bc_motocon_callback_t weather_callback =
    {
    NULL,
    WEA_receive_wea_location,
    WEA_receive_wea_info
    };

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @public
* WEA_get_weather_obj
*
* Obtain weather object.
*
* @param index the index of weather item.
* @return weather item.
*
*********************************************************************/
bc_motocon_weather_info_t* WEA_get_weather_obj
    (
    const int index
    )
{
return &weather_info_obj[index];
}

/*********************************************************************
*
* @public
* WEA_receive_wea_info
*
* Receive weather info from MotoCon library, store weather
* information in a static array and update weather item to EW UI.
*
* @param weather_info the weather_info object contains series of
* weather information.
*
*********************************************************************/
void WEA_receive_wea_info
    (
    const bc_motocon_weather_info_t* weather_info
    )
{
PRINTF( "%s, Wea info is received\r\n", __FUNCTION__ );

if( NUM_WEA_ITEM > weather_info->time )
    {
    weather_info_obj[weather_info->time].time = weather_info->time;
    weather_info_obj[weather_info->time].type = weather_info->time;
    weather_info_obj[weather_info->time].temperature = weather_info->temperature;
    weather_info_obj[weather_info->time].temperature_max = weather_info->temperature_max;
    weather_info_obj[weather_info->time].temperature_min = weather_info->temperature_min;
    weather_info_obj[weather_info->time].rain_probability = weather_info->rain_probability;
    EW_notify_weather_info_update( weather_info->time );
    }
else
    {
    PRINTF( "%s, Unexpected weather time is received\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @public
* WEA_receive_wea_location
*
* Receive weather location from MotoCon library and update weather
* location to EW UI.
*
* @param length the length of location content.
* @param content the content of location data.
*
*********************************************************************/
void WEA_receive_wea_location
    (
    const uint8_t length,
    const uint8_t* content
    )
{
char wea_loc[MAX_LOC_LEN];
if( MAX_LOC_LEN > ( length - 1 ) )
    {
    memset( wea_loc, 0, sizeof( wea_loc ) );
    memcpy( wea_loc, content, sizeof( wea_loc ) );
    wea_loc[length] = '\0';
    PRINTF( "LOC: %s\r\n", wea_loc );

    EW_notify_weather_loc_update( wea_loc );
    }
else
    {
    PRINTF( "Unexpected length of location name: %d\r\n", length );
    }
}

/*********************************************************************
*
* @public
* WEA_init
*
* Weather module - Init.
*
*********************************************************************/
void WEA_init
    (
    void
    )
{
BC_motocon_register_callback( &weather_callback );
}