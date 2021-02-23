/*********************************************************************
* @file
* BC_motocon_pub_type.h
*
* @brief
* MotoConSDK module - public type
*
* Copyright 2020-2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef BC_MOTOCON_PUB_TYPE_H
#define BC_MOTOCON_PUB_TYPE_H

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "fsl_debug_console.h"
#include <stdbool.h>

/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define BC_MOTOCON_NOTIFICATION_TITLE  ( 64 )
#define BC_MOTOCON_NOTIFICATION_DETAIL ( 512 )

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/
typedef uint16_t bc_motocon_command_code_t; enum
    {
    /*------------------------------------------------------
    V1
    ------------------------------------------------------*/
    BC_MOTOCON_COMMAND_CODE_LIB_VERSION                            = 0x0001,
    BC_MOTOCON_COMMAND_CODE_CONNECT_APP_ID                         = 0x0002,
    BC_MOTOCON_COMMAND_CODE_WEATHER_REQUEST                        = 0x0003,
    BC_MOTOCON_COMMAND_CODE_WEATHER_LOCATION                       = 0x0004,
    BC_MOTOCON_COMMAND_CODE_WEATHER_INFO                           = 0x0005,
    BC_MOTOCON_COMMAND_CODE_VEHICLE_INFORMATION_SUBSCRIBE_INTERVAL = 0x0006,
    BC_MOTOCON_COMMAND_CODE_VEHICLE_INFORMATION                    = 0x0007,
    BC_MOTOCON_COMMAND_CODE_DATETIME_CHANGE_NOTIFICATION           = 0x0008,
    BC_MOTOCON_COMMAND_CODE_VEHICLE_SETTING_REQUEST                = 0x0009,
    BC_MOTOCON_COMMAND_CODE_VEHICLE_SETTING_DATETIME               = 0x000A,
    BC_MOTOCON_COMMAND_CODE_LANGUAGE_TYPE_REQUEST                  = 0x000B,
    BC_MOTOCON_COMMAND_CODE_LANGUAGE_TYPE_RESPONSE                 = 0x000C,
    BC_MOTOCON_COMMAND_CODE_ICON_ARRANGEMENT_LIST_REQUEST          = 0x000D,
    BC_MOTOCON_COMMAND_CODE_ICON_ARRANGEMENT_LIST_RESPONSE         = 0x000E,
    BC_MOTOCON_COMMAND_CODE_DEVICE_NAME                            = 0x000F,
    BC_MOTOCON_COMMAND_CODE_ADD_NOTIFICATION                       = 0x0010,
    BC_MOTOCON_COMMAND_CODE_UPDATE_NOTIFICATION                    = 0x0011,
    BC_MOTOCON_COMMAND_CODE_REMOVE_NOTIFICATION                    = 0x0012,
    BC_MOTOCON_COMMAND_CODE_NOTIFICATION_REMOVED_NOTIFICATION      = 0x0013,
    BC_MOTOCON_COMMAND_CODE_NOTIFICATION_DATA                      = 0x0014,
    BC_MOTOCON_COMMAND_CODE_AUTHENTICATION                         = 0x0015,
    BC_MOTOCON_COMMAND_CODE_WIFI_HOST                              = 0x0016,
    /*----------------------------------------------------------
    V2
    ----------------------------------------------------------*/
    BC_MOTOCON_COMMAND_CODE_AUTHENTICATION_V2_REQUEST                      = 0x0101,
    BC_MOTOCON_COMMAND_CODE_AUTHENTICATION_V2_RESPONSE                     = 0x0102,
    BC_MOTOCON_COMMAND_CODE_CONNECT_SERVER_LIST_REQUEST                    = 0x0103,
    BC_MOTOCON_COMMAND_CODE_CONNECT_SERVER_LIST_RESPONSE                   = 0x0104,
    BC_MOTOCON_COMMAND_CODE_MALFUNCTION_REQUEST                            = 0x0105,
    BC_MOTOCON_COMMAND_CODE_MALFUNCTION_RESPONSE                           = 0x0106,
    BC_MOTOCON_COMMAND_CODE_MALFUNCTION_SERVER_SETTING_REQUEST             = 0x0107,
    BC_MOTOCON_COMMAND_CODE_MALFUNCTION_STATUS_SETTING_REQUEST             = 0x0108,
    BC_MOTOCON_COMMAND_CODE_MALFUNCTION_INTERVAL_SETTING_REQUEST           = 0x0109,
    BC_MOTOCON_COMMAND_CODE_VEHICLE_IDENTIFICATION_REQUEST                 = 0x010A,
    BC_MOTOCON_COMMAND_CODE_VEHICLE_IDENTIFICATION_RESPONSE                = 0x010B,
    BC_MOTOCON_COMMAND_CODE_MARKET_DATA_REQUEST                            = 0x010C,
    BC_MOTOCON_COMMAND_CODE_MARKET_DATA_RESPONSE                           = 0x010D,
    BC_MOTOCON_COMMAND_CODE_VEHICLE_INFORMATION_SUPPORT_ID_LIST_REQUEST    = 0x0126,
    BC_MOTOCON_COMMAND_CODE_VEHICLE_INFORMATION_SUPPORT_ID_LIST_RESPONSE   = 0x0127,
    BC_MOTOCON_COMMAND_CODE_VEHICLE_INFORMATION_REQUEST                    = 0x010E,
    BC_MOTOCON_COMMAND_CODE_VEHICLE_INFORMATION_RESPONSE                   = 0x010F,
    BC_MOTOCON_COMMAND_CODE_VEHICLE_INFORMATION_INTERVAL_SETTING_REQUEST   = 0x0110,
    BC_MOTOCON_COMMAND_CODE_FFD_REQUEST                                    = 0x0111,
    BC_MOTOCON_COMMAND_CODE_FFD_RESPONSE                                   = 0x0112,
    BC_MOTOCON_COMMAND_CODE_CAN_REQUEST                                    = 0x0113,
    BC_MOTOCON_COMMAND_CODE_CAN_RESPONSE                                   = 0x0114,
    BC_MOTOCON_COMMAND_CODE_CUMULATIVE_INJECTION_QUANTITY_REQUEST          = 0x011F,
    BC_MOTOCON_COMMAND_CODE_CUMULATIVE_INJECTION_QUANTITY                  = 0x0120,
    BC_MOTOCON_COMMAND_CODE_PHONE_BATTERY                                  = 0x0115,
    BC_MOTOCON_COMMAND_CODE_BLUETOOTH_MUSIC_META_DATA                      = 0x0116,
    BC_MOTOCON_COMMAND_CODE_BLUETOOTH_MUSIC_CONTROL                        = 0x0117,
    BC_MOTOCON_COMMAND_CODE_INCOMING_CALL_INFORMATION                      = 0x0118,
    BC_MOTOCON_COMMAND_CODE_INCOMING_CALL_CONTROL                          = 0x0119,
    BC_MOTOCON_COMMAND_CODE_PHONE_THERMAL_STATE                            = 0x011A,
    BC_MOTOCON_COMMAND_CODE_BLUETOOTH_HEADSET_STATE_REQUEST                = 0x011B,
    BC_MOTOCON_COMMAND_CODE_BLUETOOTH_HEADSET_STATE_RESPONSE               = 0x011C,
    BC_MOTOCON_COMMAND_CODE_PHONE_VOLUME_CONTROL                           = 0x011D,
    BC_MOTOCON_COMMAND_CODE_PHONE_VOLUME_LEVEL                             = 0x011E,
    BC_MOTOCON_COMMAND_CODE_NOTIFICATION_CATEGORY                          = 0x0128,
    BC_MOTOCON_COMMAND_CODE_PHONE_VOLUME_CONTROLLABLE_REQUEST              = 0x0129,
    BC_MOTOCON_COMMAND_CODE_PHONE_VOLUME_CONTROLLABLE_RESPONSE             = 0x012A,
    BC_MOTOCON_COMMAND_CODE_CREATE_OTA_CONNECTION_REQUEST                  = 0x012C,
    BC_MOTOCON_COMMAND_CODE_OTA_LINKCARD_INFORMATION                       = 0x0121,
    BC_MOTOCON_COMMAND_CODE_OTA_UPDATE_INFORMATION                         = 0x0122,
    BC_MOTOCON_COMMAND_CODE_NOTIFICATION_DATA_V2                           = 0x012F
    };/* end of bc_motocon_command_code_t */

typedef struct
    {
    uint8_t time;
    uint8_t type;
    float   temperature;
    float   temperature_max;
    float   temperature_min;
    uint8_t rain_probability;
    } bc_motocon_weather_info_t;

typedef struct
    {
    uint16_t front_speed;
    uint16_t rear_speed;
    uint16_t safe_mode_speed;
    bool     ignition_on;
    bool     speed_unit_miles;
    } bc_motocon_vehicle_info_t;

typedef struct
    {
    uint16_t year;
    uint8_t  month;
    uint8_t  day;
    uint8_t  hour;
    uint8_t  minute;
    uint8_t  second;
    } bc_motocon_time_t;

typedef enum
    {
    BC_MOTOCON_BATTERY_NOT_CHARGING,
    BC_MOTOCON_BATTERY_CHARGING
    } bc_motocon_battery_t;

typedef struct
    {
    const uint8_t* artist;
    uint8_t        artist_len;
    const uint8_t* album;
    uint8_t        album_len;
    const uint8_t* song;
    uint8_t        song_len;
    uint32_t       duration_time;
    } bc_motocon_bt_music_meta_data_t;

typedef enum
    {
    BC_MOTOCON_MUSIC_NEXT_TRACK = 1,
    BC_MOTOCON_MUSIC_PREVIOUS_TRACK,
    BC_MOTOCON_MUSIC_PLAY,
    BC_MOTOCON_MUSIC_PAUSE
    } bc_motocon_bt_music_control_t;

typedef struct
    {
    const uint8_t* name;
    uint8_t        name_len;
    const uint8_t* phone_number;
    uint8_t        phone_number_len;
    } bc_motocon_incoming_call_info_t;

typedef enum
    {
    BC_MOTOCON_CALL_REJECT,
    BC_MOTOCON_CALL_ANSWER
    } bc_motocon_incoming_call_control_t;

typedef enum
    {
    BC_MOTOCON_THERMAL_LOW,
    BC_MOTOCON_THERMAL_MIDDLE,
    BC_MOTOCON_THERMAL_HIGH
    } bc_motocon_thermal_state_t;

typedef enum
    {
    BC_MOTOCON_HEADSET_DISCONNECTED,
    BC_MOTOCON_HEADSET_CONNECTED
    } bc_motocon_bt_headset_state_t;

typedef enum
    {
    BC_MOTOCON_VOLUME_UP = 1,
    BC_MOTOCON_VOLUME_DOWN,
    BC_MOTOCON_VOLUME_MUTE_MIC,
    BC_MOTOCON_VOLUME_MUTE_SPEAKER
    } bc_motocon_volume_control_t;

typedef struct
    {
    bool incoming_call;
    bool missed_call;
    bool voice_mail;
    bool social;
    bool schedule;
    bool email;
    bool news;
    } bc_motocon_notification_category_t;

typedef struct
    {
    uint16_t current_firmware_ver;
    uint8_t  linkcard_model;
    uint8_t  serial_number[8];
    uint8_t  new_program_position;
    } bc_motocon_ota_linkcard_info_t;

typedef struct
    {
    bool     enable;
    uint16_t new_firmware_ver;
    uint32_t total_size;
    uint32_t number_of_packages;
    } bc_motocon_ota_update_info_t;

typedef struct
    {
    uint32_t          uid;
    uint8_t           category;
    bc_motocon_time_t time;
    char              title[BC_MOTOCON_NOTIFICATION_TITLE + 1];
    char              subtitle[BC_MOTOCON_NOTIFICATION_TITLE + 1];
    char              detail[BC_MOTOCON_NOTIFICATION_DETAIL + 1];
    } bc_motocon_notification_v2_t;

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* BC_MOTOCON_PUB_TYPE_H */

