/*********************************************************************
* @file
* bc_motocon_parser.c
*
* @brief
* MotoConSDK module - parser
*
* Copyright 2020-2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <bc_motocon_priv.h>
#include <pb_decode.h>
#include "BleServiceStructure.pb.h"
#include <time.h>
#include "client_ble_cmd.h"
#include "can_mid.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

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
extern bc_motocon_callback_t* bc_motocon_callbacks[BC_MOTOCON_CALLBACK_MAX];
static bc_motocon_notification_v2_t notification_v2;
#if( ENABLE_MOTOCON_DEBUG_LOG )
    static char c64[65];
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*********************************************************************
*
* @private
* bc_motocon_parser_write_received
*
* Handle write data.
*
*********************************************************************/
void bc_motocon_parser_write_received
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
bc_motocon_parse_result_t ret = BC_MOTOCON_PARSE_INVALID_COMMAND_CODE;
const bc_motocon_command_code_t command_code = TWO_BYTE_BIG( bytes, 0 );
switch( command_code )
    {
    case BC_MOTOCON_COMMAND_CODE_CONNECT_APP_ID:
        ret = BC_MOTOCON_PARSE_SUCCESS;
        break;

    case BC_MOTOCON_COMMAND_CODE_WEATHER_LOCATION:
        ret = bc_motocon_parser_weather_location( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_WEATHER_INFO:
        ret = bc_motocon_parser_weather_info( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_VEHICLE_INFORMATION_SUBSCRIBE_INTERVAL:
        ret = bc_motocon_parser_vehicle_info_subscribe( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_DATETIME_CHANGE_NOTIFICATION:
        ret = bc_motocon_parser_datetime_changed( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_VEHICLE_SETTING_DATETIME:
        ret = bc_motocon_parser_vehicle_datetime( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_LANGUAGE_TYPE_RESPONSE:
        ret = bc_motocon_parser_language_type( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_DEVICE_NAME:
        ret = bc_motocon_parser_device_name( bytes, length );;
        break;

    case BC_MOTOCON_COMMAND_CODE_CONNECT_SERVER_LIST_REQUEST:
    case BC_MOTOCON_COMMAND_CODE_VEHICLE_INFORMATION_SUPPORT_ID_LIST_REQUEST:
    case BC_MOTOCON_COMMAND_CODE_FFD_REQUEST:
        ret = bc_motocon_parser_short_data_to_can( command_code, bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_CAN_REQUEST:
        ret = bc_motocon_parser_can_request();
        break;

    case BC_MOTOCON_COMMAND_CODE_CUMULATIVE_INJECTION_QUANTITY_REQUEST:
        ret = bc_motocon_parser_injection_request();
        break;

    case BC_MOTOCON_COMMAND_CODE_PHONE_BATTERY:
        ret = bc_motocon_parser_battery( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_PHONE_THERMAL_STATE:
        ret = bc_motocon_parser_thermal( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_BLUETOOTH_HEADSET_STATE_RESPONSE:
        ret = bc_motocon_parser_bt_headset_state( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_PHONE_VOLUME_LEVEL:
        ret = bc_motocon_parser_volume_level( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_NOTIFICATION_CATEGORY:
        ret = bc_motocon_parser_notification_category( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_PHONE_VOLUME_CONTROLLABLE_RESPONSE:
        ret = bc_motocon_parser_volume_controllable( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_OTA_UPDATE_INFORMATION:
        ret = bc_motocon_parser_ota_update_info( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_CCUID_REQUEST:
        ret = bc_motocon_parser_ccuid_request();
        break;

    case BC_MOTOCON_COMMAND_CODE_PHONE_CELL_SIGNAL_LEVEL_RESPONSE:
        ret = bc_motocon_parser_cell_signal( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_CALL_CHANGE_NOTIFICATION:
        ret = bc_motocon_parser_call_changed( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_ALIVE_CHECK_RESPONSE:
        ret = bc_motocon_parser_alive_response( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_IGNITION_STATE_REQUEST:
        ret = bc_motocon_parser_ignition_state_request();
        break;

    default:
        break;
    }
if( ret != BC_MOTOCON_PARSE_SUCCESS )
    {
    bc_motocon_parse_error_handler( command_code, ret, "" );
    }
}

/*********************************************************************
*
* @private
* bc_motocon_parser_ddt_to_vehicle_received
*
* Handle ddt to vehicle data.
*
*********************************************************************/
void bc_motocon_parser_ddt_to_vehicle_received
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
bc_motocon_parse_result_t ret = BC_MOTOCON_PARSE_INVALID_COMMAND_CODE;
const bc_motocon_command_code_t command_code = TWO_BYTE_BIG( bytes, 0 );
switch( command_code )
    {
    case BC_MOTOCON_COMMAND_CODE_AUTHENTICATION_V2_REQUEST:
        bc_motocon_parser_authenticationv2( bytes, length );
        ret = BC_MOTOCON_PARSE_SUCCESS;
        break;

    case BC_MOTOCON_COMMAND_CODE_MALFUNCTION_REQUEST:
    case BC_MOTOCON_COMMAND_CODE_MALFUNCTION_INTERVAL_SETTING_REQUEST:
    case BC_MOTOCON_COMMAND_CODE_VEHICLE_IDENTIFICATION_REQUEST:
    case BC_MOTOCON_COMMAND_CODE_MARKET_DATA_REQUEST:
    case BC_MOTOCON_COMMAND_CODE_VEHICLE_INFORMATION_REQUEST:
    case BC_MOTOCON_COMMAND_CODE_VEHICLE_INFORMATION_INTERVAL_REQUEST:
        ret = bc_motocon_parser_protobuf_to_can( command_code, bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_BLUETOOTH_MUSIC_META_DATA:
        ret = bc_motocon_parser_bt_music_meta_data( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_INCOMING_CALL_INFORMATION:
        ret = bc_motocon_parser_incoming_call_info( bytes, length );
        break;

    case BC_MOTOCON_COMMAND_CODE_NOTIFICATION_DATA_V2:
        ret = bc_motocon_parser_notification_v2( bytes, length );
        break;

    default:
        break;
    }
if( ret != BC_MOTOCON_PARSE_SUCCESS )
    {
    bc_motocon_parse_error_handler( command_code, ret, "" );
    }
}

/*********************************************************************
*
* @private
* bc_motocon_parser_weather_location
*
* Parse weather and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_weather_location
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
int8_t location_length = length - 3;
if( location_length >= 0 )
    {
    const uint8_t* location_content = bytes + 3;
    BC_MOTOCON_PRINTF( "%s, length = %d\r\n", __FUNCTION__, location_length );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->weather_location_callback )
            {
            bc_motocon_callbacks[i]->weather_location_callback( location_length, location_length ? location_content : NULL );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* get_weather_temperature
*
* Get signed float with factor 0.1 from uint16_t.
*
*********************************************************************/
static float get_weather_temperature
    (
    const uint16_t value
    )
{
return (int16_t)( (int32_t)value - 0x10000u ) / 10.0;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_weather_info
*
* Parse weather and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_weather_info
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
bc_motocon_weather_info_t weather_info;
if( length == 12 )
    {
    weather_info.time = bytes[3];
    weather_info.type = bytes[4];
    weather_info.temperature = get_weather_temperature( TWO_BYTE_BIG( bytes, 5 ) );
    weather_info.temperature_max = get_weather_temperature( TWO_BYTE_BIG( bytes, 7 ) );
    weather_info.temperature_min = get_weather_temperature( TWO_BYTE_BIG( bytes, 9 ) );
    weather_info.rain_probability = bytes[11] * 5;
    BC_MOTOCON_PRINTF( "%s, time: %d, type: %d, t: %f, tmax: %f, tmin: %f, rain: %d\r\n", __FUNCTION__,
        weather_info.time, weather_info.type, weather_info.temperature, weather_info.temperature_max, weather_info.temperature_min, weather_info.rain_probability );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->weather_info_callback )
            {
            bc_motocon_callbacks[i]->weather_info_callback( &weather_info );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_vehicle_info_subscribe
*
* Parse vehicle info subscribe interval and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_vehicle_info_subscribe
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
if( length == 5 )
    {
    BC_MOTOCON_PRINTF( "%s, interval = %d\r\n", __FUNCTION__, TWO_BYTE_BIG( bytes, 3 ) );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->vehicle_info_subscribe_callback )
            {
            bc_motocon_callbacks[i]->vehicle_info_subscribe_callback( TWO_BYTE_BIG( bytes, 3 ) );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_datetime_changed
*
* Parse datetime changed notification and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_datetime_changed
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
if( length == 3 )
    {
    BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->datetime_changed_callback )
            {
            bc_motocon_callbacks[i]->datetime_changed_callback();
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_vehicle_datetime
*
* Parse datetime and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_vehicle_datetime
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
if( length == 11 )
    {
    bc_motocon_time_t time;
    time_t unixtime = FOUR_BYTE_BIG( bytes, 7 );
    struct tm* tm_time = gmtime( &unixtime );
    if( tm_time != NULL )
        {
        time.sec = tm_time->tm_sec;
        time.min = tm_time->tm_min;
        time.hour = tm_time->tm_hour;
        time.day = tm_time->tm_mday;
        time.mon = tm_time->tm_mon;
        time.year = tm_time->tm_year + 1900;
        time.day_of_week = tm_time->tm_wday;
        BC_MOTOCON_PRINTF( "%s, %d.%02d.%02d W%01d %02d:%02d:%02d\r\n", __FUNCTION__, time.year, time.mon, time.day,
            time.day_of_week, time.hour, time.min, time.sec );
        }
    else
        {
        BC_MOTOCON_PRINTF( "%s, gmtime() failed\r\n", __FUNCTION__ );
        return BC_MOTOCON_PARSE_INVALID_INPUT;
        }
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->vehicle_datetime_callback )
            {
            bc_motocon_callbacks[i]->vehicle_datetime_callback( &time );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_language_type
*
* Parse language and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_language_type
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
if( length == 4 )
    {
    BC_MOTOCON_PRINTF( "%s, %d\r\n", __FUNCTION__, bytes[3] );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->language_type_callback )
            {
            bc_motocon_callbacks[i]->language_type_callback( bytes[3] );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_device_name
*
* Parse weather and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_device_name
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
int8_t name_length = length - 3;
if( name_length >= 0 )
    {
    const uint8_t* name_content = bytes + 3;
    BC_MOTOCON_PRINTF( "%s, length = %d\r\n", __FUNCTION__, name_length );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->device_name_callback )
            {
            bc_motocon_callbacks[i]->device_name_callback( name_length, name_length ? name_content : NULL );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_authenticationv2
*
* Parse authenticationv2 data and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_authenticationv2
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
if( length >= 22 )
    {
    BC_MOTOCON_PRINTF( "%s, ccuid: ", __FUNCTION__ );
    for( int i = 2; i < 16; i++ )
        {
        BC_MOTOCON_PRINTF( "%02X", bytes[i] );
        }
    BC_MOTOCON_PRINTF( ", passkey: " );
    for( int i = 16; i < 22; i++ )
        {
        BC_MOTOCON_PRINTF( "%02X", bytes[i] );
        }
    BC_MOTOCON_PRINTF( "\r\n" );
    if( bc_motocon_authentication_verify_data( bytes + 2, bytes + 16 ) )
        {
        BC_motocon_send_authenticationv2_result( true );
        bc_motocon_set_connected( true );
        return BC_MOTOCON_PARSE_SUCCESS;
        }
    }
BC_motocon_send_authenticationv2_result( false );
bc_motocon_set_connected( false );
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_short_data_to_can
*
* Parse data and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_short_data_to_can
    (
    const bc_motocon_command_code_t command_code,
    const uint8_t*                  bytes,
    const uint32_t                  length
    )
{
if( length >= 2 )
    {
    const uint32_t data_length = length - 2;
    BC_MOTOCON_PRINTF( "%s, command_code: %d, content length: %d\r\n", __FUNCTION__, command_code, data_length );
    client_ble_cmd_enter_queue( command_code, data_length, data_length ? bytes + 2 : NULL );
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_protobuf_to_can
*
* Parse protobuf and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_protobuf_to_can
    (
    const bc_motocon_command_code_t command_code,
    const uint8_t*                  bytes,
    const uint32_t                  length
    )
{
if( length >= 5 )
    {
    const uint32_t data_length = length - 5;
    BC_MOTOCON_PRINTF( "%s, command_code: %d, content length: %d\r\n", __FUNCTION__, command_code, data_length );
    client_ble_cmd_enter_queue( command_code, THREE_BYTE_BIG( bytes, 2 ), data_length ? bytes + 5 : NULL );
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_can_request
*
* Post can request callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_can_request
    (
    void
    )
{
BC_MOTOCON_PERIODIC_PRINTF( "%s\r\n", __FUNCTION__ );
for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
    {
    if( NULL != bc_motocon_callbacks[i] &&
        NULL != bc_motocon_callbacks[i]->can_request_callback )
        {
        bc_motocon_callbacks[i]->can_request_callback();
        }
    }
return BC_MOTOCON_PARSE_SUCCESS;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_injection_request
*
* Post cumulative injection quantity request callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_injection_request
    (
    void
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
const uint32_t fuel = can_mid_fuel_cons_get();
BC_motocon_send_injection_quantity( (uint8*)&fuel );
return BC_MOTOCON_PARSE_SUCCESS;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_battery
*
* Parse battery and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_battery
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
if( length == 4 )
    {
    BC_MOTOCON_PRINTF( "%s, %d, type: %d\r\n", __FUNCTION__, bytes[2], bytes[3] );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->battery_callback )
            {
            bc_motocon_callbacks[i]->battery_callback( bytes[2], bytes[3] );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

#if( ENABLE_MOTOCON_DEBUG_LOG )
    /*********************************************************************
    *
    * @private
    * print_char
    *
    * Fill '\0' at end of char array. Maximum size is 64.
    *
    *********************************************************************/
    static char* print_char64
        (
        const uint8_t* bytes,
        const uint32_t length
        )
    {
    memcpy( c64, bytes, MIN( length, 64 ) );
    c64[MIN( length, 64 )] = 0;
    return c64;
    }
#endif

/*********************************************************************
*
* @private
* bc_motocon_parser_bt_music_meta_data
*
* Parse bt music and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_bt_music_meta_data
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
bc_motocon_bt_music_meta_data_t music;
uint32_t pt = 2;
if( pt + 1 > length )
    {
    return BC_MOTOCON_PARSE_INVALID_INPUT;
    }
music.artist_len = bytes[pt];
pt += 1;

if( pt + music.artist_len > length )
    {
    return BC_MOTOCON_PARSE_INVALID_INPUT;
    }
music.artist = bytes + pt;
pt += music.artist_len;

if( pt + 1 > length )
    {
    return BC_MOTOCON_PARSE_INVALID_INPUT;
    }
music.album_len = bytes[pt];
pt += 1;

if( pt + music.album_len > length )
    {
    return BC_MOTOCON_PARSE_INVALID_INPUT;
    }
music.album = bytes + pt;
pt += music.album_len;

if( pt + 1 > length )
    {
    return BC_MOTOCON_PARSE_INVALID_INPUT;
    }
music.song_len = bytes[pt];
pt += 1;

if( pt + music.song_len > length )
    {
    return BC_MOTOCON_PARSE_INVALID_INPUT;
    }
music.song = bytes + pt;
pt += music.song_len;

if( pt + 3 > length )
    {
    return BC_MOTOCON_PARSE_INVALID_INPUT;
    }
music.duration_time = THREE_BYTE_BIG( bytes, pt );
pt += 3;

if( pt + 1 > length )
    {
    return BC_MOTOCON_PARSE_INVALID_INPUT;
    }
music.state = bytes[pt];
pt += 1;

if( pt + 2 > length )
    {
    return BC_MOTOCON_PARSE_INVALID_INPUT;
    }
music.rate = ((float)TWO_BYTE_BIG( bytes, pt ))/10;
pt += 2;

if( pt + 3 > length )
    {
    return BC_MOTOCON_PARSE_INVALID_INPUT;
    }
music.elapsed_time = THREE_BYTE_BIG( bytes, pt );
pt += 3;

if( pt == length )
    {
    BC_MOTOCON_PRINTF( "%s, artist: %d, album: %d, song: %d, duration: %d, state: %d, rate: %f, elapsed: %d\r\n", __FUNCTION__,
            music.artist_len, music.album_len, music.song_len, music.duration_time, music.state, music.rate, music.elapsed_time);
    BC_MOTOCON_PRINTF( "artist: %s\r\n", print_char64( music.artist, music.artist_len ) );
    BC_MOTOCON_PRINTF( "album : %s\r\n", print_char64( music.album, music.album_len ) );
    BC_MOTOCON_PRINTF( "song  : %s\r\n", print_char64( music.song, music.song_len ) );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->bt_music_meta_data_callback )
            {
            bc_motocon_callbacks[i]->bt_music_meta_data_callback( &music );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_incoming_call_info
*
* Parse incoming call and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_incoming_call_info
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
bc_motocon_incoming_call_info_t call;
uint32_t pt = 2;
if( pt + 1 > length )
    {
    return BC_MOTOCON_PARSE_INVALID_INPUT;
    }
call.name_len = bytes[pt];
pt += 1;

if( pt + call.name_len > length )
    {
    return BC_MOTOCON_PARSE_INVALID_INPUT;
    }
call.name = bytes + pt;
pt += call.name_len;

if( pt + 1 > length )
    {
    return BC_MOTOCON_PARSE_INVALID_INPUT;
    }
call.phone_number_len = bytes[pt];
pt += 1;

if( pt + call.phone_number_len > length )
    {
    return BC_MOTOCON_PARSE_INVALID_INPUT;
    }
call.phone_number = bytes + pt;
pt += call.phone_number_len;

if( pt == length )
    {
    BC_MOTOCON_PRINTF( "%s, name: %d, number: %d\r\n", __FUNCTION__, call.name_len, call.phone_number_len );
    BC_MOTOCON_PRINTF( "name  : %s\r\n", print_char64( call.name, call.name_len ) );
    BC_MOTOCON_PRINTF( "number: %s\r\n", print_char64( call.phone_number, call.phone_number_len ) );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->incoming_call_info_callback )
            {
            bc_motocon_callbacks[i]->incoming_call_info_callback( &call );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_thermal
*
* Parse thermal and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_thermal
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
if( length == 3 )
    {
    BC_MOTOCON_PRINTF( "%s, %d\r\n", __FUNCTION__, bytes[2] );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->thermal_callback )
            {
            bc_motocon_callbacks[i]->thermal_callback( bytes[2] );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_bt_headset_state
*
* Parse bt headset state and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_bt_headset_state
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
if( length == 3 )
    {
    BC_MOTOCON_PRINTF( "%s, %d\r\n", __FUNCTION__, bytes[2] );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->bt_headset_state_callback )
            {
            bc_motocon_callbacks[i]->bt_headset_state_callback( bytes[2] );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_volume_level
*
* Parse volume level state and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_volume_level
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
if( length == 4 )
    {
    BC_MOTOCON_PRINTF( "%s, %d type: %d\r\n", __FUNCTION__, bytes[2], bytes[3] );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->volume_level_callback )
            {
            bc_motocon_callbacks[i]->volume_level_callback( bytes[2], bytes[3] );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_notification_category
*
* Parse notification category state and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_notification_category
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
if( length == 14 )
    {
    bc_motocon_notification_category_t category;
    category.other = bytes[2];
    category.incoming_call = bytes[3];
    category.missed_call = bytes[4];
    category.voice_mail = bytes[5];
    category.social = bytes[6];
    category.schedule = bytes[7];
    category.email = bytes[8];
    category.news = bytes[9];
    category.healthAndFitness = bytes[10];
    category.businessAndFinance = bytes[11];
    category.location = bytes[12];
    category.entertainment = bytes[13];
    BC_MOTOCON_PRINTF( "%s, other: %d, incoming_call: %d, missed_call: %d, voice_mail: %d, social: %d, schedule: %d, email: %d\r\n", __FUNCTION__,
        category.other, category.incoming_call, category.missed_call, category.voice_mail, category.social, category.schedule, category.email );
    BC_MOTOCON_PRINTF( "%s, news: %d, healthAndFitness: %d, businessAndFinance: %d, location: %d, entertainment: %d\r\n", __FUNCTION__,
        category.news, category.healthAndFitness, category.businessAndFinance, category.location, category.entertainment );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->notification_category_callback )
            {
            bc_motocon_callbacks[i]->notification_category_callback( &category );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_volume_controllable
*
* Parse volume controllable state and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_volume_controllable
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
if( length == 3 )
    {
    BC_MOTOCON_PRINTF( "%s, %d\r\n", __FUNCTION__, bytes[2] );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->volume_controllable_callback )
            {
            bc_motocon_callbacks[i]->volume_controllable_callback( bytes[2] );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_ota_update_info
*
* Parse ota update info and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_ota_update_info
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
if( length == 13 )
    {
    bc_motocon_ota_update_info_t info;
    info.enable = bytes[2];
    info.new_firmware_ver = TWO_BYTE_BIG( bytes, 3 );
    info.total_size = FOUR_BYTE_BIG( bytes, 5 );
    info.number_of_packages = FOUR_BYTE_BIG( bytes, 9 );
    BC_MOTOCON_PRINTF( "%s, enable: %d, new firmware: %d, size: %d, #: %d\r\n", __FUNCTION__,
        info.enable, info.new_firmware_ver, info.total_size, info.number_of_packages );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->ota_update_info_callback )
            {
            bc_motocon_callbacks[i]->ota_update_info_callback( &info );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* get_title
*
* Get title from notification protobuf.
*
*********************************************************************/
static bool get_title
    (
    pb_istream_t*     stream,
    const pb_field_t* field,
    void**            arg
    )
{
uint32_t length = MIN( BC_MOTOCON_NOTIFICATION_TITLE, stream->bytes_left );
((uint8_t*)*arg)[length] = 0;
return pb_read( stream, (uint8_t*)*arg, stream->bytes_left );
}

/*********************************************************************
*
* @private
* get_detail
*
* Get detail from notification protobuf.
*
*********************************************************************/
static bool get_detail
    (
    pb_istream_t*     stream,
    const pb_field_t* field,
    void**            arg
    )
{
uint32_t length = MIN( BC_MOTOCON_NOTIFICATION_DETAIL, stream->bytes_left );
((uint8_t*)*arg)[length] = 0;
return pb_read( stream, (uint8_t*)*arg, stream->bytes_left );
}

/*********************************************************************
*
* @private
* bc_motocon_parser_notification_v2
*
* Parse notification data v2 and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_notification_v2
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
if( length >= 5 )
    {
    BC_MOTOCON_PRINTF( "%s, length: %d\r\n", __FUNCTION__, length );

    McNotificationDataV2 notification = McNotificationDataV2_init_zero;
    pb_istream_t stream = pb_istream_from_buffer( bytes + 5, THREE_BYTE_BIG( bytes, 2 ) );

    notification.title.funcs.decode = &get_title;
    notification.title.arg = notification_v2.title;
    notification.sub_title.funcs.decode = &get_title;
    notification.sub_title.arg = notification_v2.subtitle;
    notification.detail.funcs.decode = &get_detail;
    notification.detail.arg = notification_v2.detail;

    if( pb_decode( &stream, McNotificationDataV2_fields, &notification ) )
        {
        BC_MOTOCON_PRINTF( "Decoding Success!!\r\n");
        notification_v2.uid = notification.notification_id;
        notification_v2.category = notification.category;
        notification_v2.time.year =  notification.year;
        notification_v2.time.mon = notification.month;
        notification_v2.time.day = notification.day;
        notification_v2.time.hour = notification.hour;
        notification_v2.time.min = notification.minutes;
        notification_v2.time.sec = notification.second;
        notification_v2.time.day_of_week = BC_MOTOCON_WEEK_UNKOWN;

        BC_MOTOCON_PRINTF( "Id      : %d\r\n", notification_v2.uid );
        BC_MOTOCON_PRINTF( "Category: %d\r\n", notification_v2.category );
        BC_MOTOCON_PRINTF( "Time    : %d.%02d.%02d %02d:%02d:%02d\r\n",notification_v2.time.year, notification_v2.time.mon, notification_v2.time.day,
            notification_v2.time.hour, notification_v2.time.min, notification_v2.time.sec );
        BC_MOTOCON_PRINTF( "Title   : %s\r\n", notification_v2.title );
        BC_MOTOCON_PRINTF( "Subtitle: %s\r\n", notification_v2.subtitle );
        BC_MOTOCON_PRINTF( "Detail  : %s\r\n", notification_v2.detail );

        for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
            {
            if( NULL != bc_motocon_callbacks[i] &&
                NULL != bc_motocon_callbacks[i]->notification_callback )
                {
                bc_motocon_callbacks[i]->notification_callback( &notification_v2 );
                }
            }
        }
    else
        {
        BC_MOTOCON_PRINTF( "Decoding failed: %s\r\n", PB_GET_ERROR( &stream ) );
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_ccuid_request
*
* Parse ccuid request and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_ccuid_request
    (
    void
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
    {
    if( NULL != bc_motocon_callbacks[i] &&
        NULL != bc_motocon_callbacks[i]->ccuid_request_callback )
        {
        bc_motocon_callbacks[i]->ccuid_request_callback();
        }
    }
return BC_MOTOCON_PARSE_SUCCESS;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_cell_signal
*
* Parse ota update info and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_cell_signal
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
if( length == 3 )
    {
    BC_MOTOCON_PRINTF( "%s, level: %d\r\n", __FUNCTION__, bytes[2] );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->cell_signal_callback )
            {
            bc_motocon_callbacks[i]->cell_signal_callback( bytes[2] );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_call_changed
*
* Parse ota update info and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_call_changed
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
if( length == 3 )
    {
    BC_MOTOCON_PRINTF( "%s, state: %d\r\n", __FUNCTION__, bytes[2] );
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->call_changed_callback )
            {
            bc_motocon_callbacks[i]->call_changed_callback( bytes[2] );
            }
        }
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_alive_response
*
* Parse alive signal and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_alive_response
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
if( length == 3 )
    {
    BC_MOTOCON_PERIODIC_PRINTF( "%s, id: %d\r\n", __FUNCTION__, bytes[2] );
    return BC_MOTOCON_PARSE_SUCCESS;
    }
return BC_MOTOCON_PARSE_INVALID_INPUT;
}

/*********************************************************************
*
* @private
* bc_motocon_parser_ignition_state_request
*
* Parse ignition state and post callback.
*
*********************************************************************/
bc_motocon_parse_result_t bc_motocon_parser_ignition_state_request
    (
    void
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
    {
    if( NULL != bc_motocon_callbacks[i] &&
        NULL != bc_motocon_callbacks[i]->ignition_state_request_callback )
        {
        bc_motocon_callbacks[i]->ignition_state_request_callback();
        }
    }
return BC_MOTOCON_PARSE_SUCCESS;
}
