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

// TODO: Adjust value of WEA_INFO_RECEIVED when after 6 day type is ready.
#define WEA_INFO_RECEIVED                           0x7FF

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
// TODO: ADD after 6 day type when MotoCon SDK is ready.
typedef enum
    {
    WEATHER_CURRENT                  = 0,
    WEATHER_AFTER_1DAY               = 1,
    WEATHER_AFTER_2DAY               = 2,
    WEATHER_AFTER_3DAY               = 3,
    WEATHER_AFTER_4DAY               = 4,
    WEATHER_AFTER_5DAY               = 5,
    WEATHER_AFTER_1HOUR              = 6,
    WEATHER_AFTER_2HOUR              = 7,
    WEATHER_AFTER_3HOUR              = 8,
    WEATHER_LOCATION                 = 9,
    WEATHER_WEEKDAY                  = 10
    } weather_type;

void WEA_receive_wea_info( const bc_motocon_weather_info_t* weather_info );
void WEA_receive_wea_location( const uint8_t length, const uint8_t* content );
void WEA_receive_weekday( const bc_motocon_time_t* time );

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
static char weather_location[MAX_LOC_LEN];
static int weather_weekday;
static bc_motocon_callback_t weather_callback =
    {
    NULL,
    WEA_receive_wea_location,
    WEA_receive_wea_info,
    NULL,
    NULL,
    WEA_receive_weekday
    };
static int weather_info_received = 0;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/
#define set_bit( data, offset )   ( ( data ) |=  ( 1 << ( offset ) ) )

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
* WEA_get_weather_location
*
* Return received weather location.
*
* @return weather location.
*
*********************************************************************/
char* WEA_get_weather_location
    (
    void
    )
{
return weather_location;
}

/*********************************************************************
*
* @public
* WEA_get_weather_weekday
*
* Return received weather weekday.
*
* @return weather weekday.
*
*********************************************************************/
int WEA_get_weather_weekday
    (
    void
    )
{
return weather_weekday;
}

/*********************************************************************
*
* @public
* WEA_reset_weather_info_threshold
*
* Reset the weather info threshold value.
*
*********************************************************************/
void WEA_reset_weather_info_threshold
    (
    void
    )
{
weather_info_received = 0;
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
    set_bit( weather_info_received, weather_info->time );

    if( WEA_INFO_RECEIVED == weather_info_received )
        {
        weather_info_received = 0;
        EW_notify_weather_info_update();
        }
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
if( MAX_LOC_LEN > ( length - 1 ) )
    {
    memset( weather_location, 0, sizeof( weather_location ) );
    memcpy( weather_location, content, sizeof( weather_location ) );
    weather_location[length] = '\0';
    PRINTF( "%s, Weather Location: %s\r\n", __FUNCTION__, weather_location );

    set_bit( weather_info_received, WEATHER_LOCATION );
    if( WEA_INFO_RECEIVED == weather_info_received )
        {
        weather_info_received = 0;
        EW_notify_weather_info_update();
        }
    }
else
    {
    PRINTF( "Unexpected length of location name: %d\r\n", length );
    }
}

/*********************************************************************
*
* @public
* WEA_receive_weekday
*
* Receive week day from MotoCon library and update it to EW UI.
*
*********************************************************************/
void WEA_receive_weekday
    (
    const bc_motocon_time_t* time
    )
{
// TODO: in terms of weather, the assumption is that parameter should be a integer which indicates the week day:
// Sunday = 0, Monday = 1... Saturday = 6
// Assign 3 ( Wednesday ) for testing only. Will change code when weekday parsing is done in the MotoCon parser.
weather_weekday = 3;
set_bit( weather_info_received, WEATHER_WEEKDAY );
if( WEA_INFO_RECEIVED == weather_info_received )
    {
    weather_info_received = 0;
    EW_notify_weather_info_update();
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
