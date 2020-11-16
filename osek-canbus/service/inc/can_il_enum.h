/*!*******************************************************************
* @file CAN_il_enum.h
* @brief OSEK CAN Stack IL Enumerated Signal Definitions
*
*                         !!! WARNING !!!
*                 !!! COMPUTER GENERATED FILE !!!
*                    !!! DO NOT HAND MODIFY !!!
*
* The contents of this file were computer generated. Manual editing
* of this file is discouraged as it is likely to cause compilation
* errors and/or errors in run time functionalities that are dependent
* upon the contents of this file.
*
* This file contains signal definitions for the enumerated signals
* defined in the CAN Stack Interaction Layer as specified in the OEM
* CAN database file.
*
* Copyright 2018 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack_il_cfg
* @{
*
*********************************************************************/

#ifndef _CAN_IL_ENUM_H
#define _CAN_IL_ENUM_H

#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------------------
CAN0
------------------------------------------------------*/

/*------------------------------------------------------
Transmit Enumerations
------------------------------------------------------*/

/*------------------------------------------------------
ID0_FUNC_INFO Enumerations
------------------------------------------------------*/

#define     IL_VT_MUSIC_STATUS_PAUSE                                    0
#define     IL_VT_MUSIC_STATUS_PLAY                                     1
#define     IL_VT_MUSIC_STATUS_STOP                                     2
#define     IL_VT_MUSIC_STATUS_RESERVE                                  3


/*------------------------------------------------------
ID3_SYS_INFO Enumerations
------------------------------------------------------*/

#define     IL_VT_LANGUAGE_ENGLISH                                      0
#define     IL_VT_LANGUAGE_FRENCH_FRA                                   1
#define     IL_VT_LANGUAGE_GERMAN                                       2
#define     IL_VT_LANGUAGE_ITALIAN                                      3
#define     IL_VT_LANGUAGE_JAPANESE                                     4
#define     IL_VT_LANGUAGE_SPANISH_INTL                                 5
#define     IL_VT_LANGUAGE_TRADITIONAL_CHINESE                          6
#define     IL_VT_LANGUAGE_OTHERS                                       31

#define     IL_VT_LB_SYS_STATUS_NOT_READY                               0
#define     IL_VT_LB_SYS_STATUS_READY                                   1

#define     IL_VT_LB_LAYER_GARMIN_NAVI_TOP                              0
#define     IL_VT_LB_LAYER_GARMIN_NAVI_LOWER_LAYER                      1
#define     IL_VT_LB_LAYER_OTHER_THAN_GARMIN_NAVI                       2
#define     IL_VT_LB_LAYER_APP_LAUNCHER                                 3


/*------------------------------------------------------
ID5_INDICTR_STATUS Enumerations
------------------------------------------------------*/

#define     IL_VT_PHONE_SIG_SENSITIVITY_NO_CONNECTION                   0
#define     IL_VT_PHONE_SIG_SENSITIVITY_NO_SERVICE                      1
#define     IL_VT_PHONE_SIG_SENSITIVITY_LV_0                            2
#define     IL_VT_PHONE_SIG_SENSITIVITY_LV_1                            3
#define     IL_VT_PHONE_SIG_SENSITIVITY_LV_2                            4
#define     IL_VT_PHONE_SIG_SENSITIVITY_LV_3                            5
#define     IL_VT_PHONE_SIG_SENSITIVITY_LV_4                            6
#define     IL_VT_PHONE_SIG_SENSITIVITY_LV_5                            7

#define     IL_VT_MUTE_STATUS_UNMUTE                                    0
#define     IL_VT_MUTE_STATUS_MUTE                                      1

#define     IL_VT_YAPP_LAUNCH_STATUS_NO_CONNECTION                      0
#define     IL_VT_YAPP_LAUNCH_STATUS_CONNECTED                          1

#define     IL_VT_PHONE_BATTERY_STATUS_NO_CONNECTION                    0
#define     IL_VT_PHONE_BATTERY_STATUS_CHARGING                         1
#define     IL_VT_PHONE_BATTERY_STATUS_NO_BATTERY                       2
#define     IL_VT_PHONE_BATTERY_STATUS_LV_1                             3
#define     IL_VT_PHONE_BATTERY_STATUS_LV_2                             4
#define     IL_VT_PHONE_BATTERY_STATUS_LV_3                             5
#define     IL_VT_PHONE_BATTERY_STATUS_LV_4                             6
#define     IL_VT_PHONE_BATTERY_STATUS_LV_5                             7

#define     IL_VT_WIFI_SIG_SENSITIVITY_WIFI_SETTING_IF_OFF              0
#define     IL_VT_WIFI_SIG_SENSITIVITY_WIFI_IS_READY                    1
#define     IL_VT_WIFI_SIG_SENSITIVITY_LV_1                             2
#define     IL_VT_WIFI_SIG_SENSITIVITY_LV_2                             3
#define     IL_VT_WIFI_SIG_SENSITIVITY_LV_3                             4
#define     IL_VT_WIFI_SIG_SENSITIVITY_LV_4                             5

#define     IL_VT_BT_PSSNGER_HDSET_STATUS_NO_CONNECTION                 0
#define     IL_VT_BT_PSSNGER_HDSET_STATUS_CONNECTED                     1

#define     IL_VT_BT_RIDER_HDSET_STATUS_NO_CONNECTION                   0
#define     IL_VT_BT_RIDER_HDSET_STATUS_CONNECTED                       1

#define     IL_VT_BT_PHONE_STATUS_BT_SETTING_OFF                        0
#define     IL_VT_BT_PHONE_STATUS_BT_IS_READY                           1
#define     IL_VT_BT_PHONE_STATUS_BT_PHONE_IS_CONNECTED                 2
#define     IL_VT_BT_PHONE_STATUS_RESERVE                               3

#define     IL_VT_NOTIFICATION_STATUS_NO_EVENT                          0
#define     IL_VT_NOTIFICATION_STATUS_EXIST_NOTIFICATION                1

#define     IL_VT_PHONE_MISSED_CALL_NO_EVENT                            0
#define     IL_VT_PHONE_MISSED_CALL_MISSED_CALL                         1

#define     IL_VT_PHONE_STATUS_NO_EVENT                                 0
#define     IL_VT_PHONE_STATUS_INCOMING_CALL                            1
#define     IL_VT_PHONE_STATUS_DURING_CALL                              2
#define     IL_VT_PHONE_STATUS_OUTGOING_CALL                            3


/*------------------------------------------------------
Receive Enumerations
------------------------------------------------------*/

/*------------------------------------------------------
ID0_FUNCSW_STATUS Enumerations
------------------------------------------------------*/

#define     IL_VT_FUNC_SW_1_OFF                                         0
#define     IL_VT_FUNC_SW_1_ON                                          1

#define     IL_VT_FUNC_SW_10_OFF                                        0
#define     IL_VT_FUNC_SW_10_ON                                         1

#define     IL_VT_FUNC_SW_11_OFF                                        0
#define     IL_VT_FUNC_SW_11_ON                                         1

#define     IL_VT_FUNC_SW_12_OFF                                        0
#define     IL_VT_FUNC_SW_12_ON                                         1

#define     IL_VT_FUNC_SW_13_OFF                                        0
#define     IL_VT_FUNC_SW_13_ON                                         1

#define     IL_VT_FUNC_SW_14_OFF                                        0
#define     IL_VT_FUNC_SW_14_ON                                         1

#define     IL_VT_FUNC_SW_15_OFF                                        0
#define     IL_VT_FUNC_SW_15_ON                                         1

#define     IL_VT_FUNC_SW_16_OFF                                        0
#define     IL_VT_FUNC_SW_16_ON                                         1

#define     IL_VT_FUNC_SW_17_OFF                                        0
#define     IL_VT_FUNC_SW_17_ON                                         1

#define     IL_VT_FUNC_SW_18_OFF                                        0
#define     IL_VT_FUNC_SW_18_ON                                         1

#define     IL_VT_FUNC_SW_2_OFF                                         0
#define     IL_VT_FUNC_SW_2_ON                                          1

#define     IL_VT_FUNC_SW_3_OFF                                         0
#define     IL_VT_FUNC_SW_3_ON                                          1

#define     IL_VT_FUNC_SW_4_OFF                                         0
#define     IL_VT_FUNC_SW_4_ON                                          1

#define     IL_VT_FUNC_SW_5_OFF                                         0
#define     IL_VT_FUNC_SW_5_ON                                          1

#define     IL_VT_FUNC_SW_6_OFF                                         0
#define     IL_VT_FUNC_SW_6_ON                                          1

#define     IL_VT_FUNC_SW_7_OFF                                         0
#define     IL_VT_FUNC_SW_7_ON                                          1

#define     IL_VT_FUNC_SW_8_OFF                                         0
#define     IL_VT_FUNC_SW_8_ON                                          1

#define     IL_VT_FUNC_SW_9_OFF                                         0
#define     IL_VT_FUNC_SW_9_ON                                          1

#define     IL_VT_SCREEN_LAYER_METER_IS_FOREGROUND                      0
#define     IL_VT_SCREEN_LAYER_METER_IS_BACKGROUND                      1


/*------------------------------------------------------
ID1_VEHICLE_INFO Enumerations
------------------------------------------------------*/

#define     IL_VT_LOW_FUEL_WARN_NORMAL                                  0
#define     IL_VT_LOW_FUEL_WARN_LOW_FUEL                                1


/*------------------------------------------------------
ID2_FUNC_CNTRL Enumerations
------------------------------------------------------*/

#define     IL_VT_MEDIA_VOL_DOWN_SWITCH_RELEASE                         0
#define     IL_VT_MEDIA_VOL_DOWN_SWITCH_ON                              1

#define     IL_VT_MEDIA_VOL_UP_SWITCH_RELEASE                           0
#define     IL_VT_MEDIA_VOL_UP_SWITCH_ON                                1

#define     IL_VT_NEXT_TRACK_SWITCH_RELEASE                             0
#define     IL_VT_NEXT_TRACK_SWITCH_ON                                  1

#define     IL_VT_PAUSE_SWITCH_RELEASE                                  0
#define     IL_VT_PAUSE_SWITCH_ON                                       1

#define     IL_VT_PHONE_OFF_HOOK_SWITCH_RELEASE                         0
#define     IL_VT_PHONE_OFF_HOOK_SWITCH_ON                              1

#define     IL_VT_PHONE_ON_HOOK_SWITCH_RELEASE                          0
#define     IL_VT_PHONE_ON_HOOK_SWITCH_ON                               1

#define     IL_VT_PHONE_VOL_DOWN_SWITCH_RELEASE                         0
#define     IL_VT_PHONE_VOL_DOWN_SWITCH_ON                              1

#define     IL_VT_PHONE_VOL_UP_SWITCH_RELEASE                           0
#define     IL_VT_PHONE_VOL_UP_SWITCH_ON                                1

#define     IL_VT_PLAY_SWITCH_RELEASE                                   0
#define     IL_VT_PLAY_SWITCH_ON                                        1

#define     IL_VT_PREVIOUSE_TRACK_SWITCH_RELEASE                        0
#define     IL_VT_PREVIOUSE_TRACK_SWITCH_ON                             1

#define     IL_VT_RINGTONE_VOL_DOWN_SWITCH_RELEASE                      0
#define     IL_VT_RINGTONE_VOL_DOWN_SWITCH_ON                           1

#define     IL_VT_RINGTONE_VOL_UP_SWITCH_RELEASE                        0
#define     IL_VT_RINGTONE_VOL_UP_SWITCH_ON                             1

#define     IL_VT_STOP_SWITCH_RELEASE                                   0
#define     IL_VT_STOP_SWITCH_ON                                        1


/*------------------------------------------------------
ID4_UNIT_INFO Enumerations
------------------------------------------------------*/

#define     IL_VT_FUEL_CON_UNIT_KM_L                                    0
#define     IL_VT_FUEL_CON_UNIT_MILE_US_GAL                             1
#define     IL_VT_FUEL_CON_UNIT_MILE_IMP_GAL                            2
#define     IL_VT_FUEL_CON_UNIT_L_100KM                                 3

#define     IL_VT_MILEAGE_UNIT_KM                                       0
#define     IL_VT_MILEAGE_UNIT_MILE                                     1

#define     IL_VT_PRESSURE_UNIT_PSI                                     0
#define     IL_VT_PRESSURE_UNIT_KPA                                     1
#define     IL_VT_PRESSURE_UNIT_KGF_CM_SQUARE                           2
#define     IL_VT_PRESSURE_UNIT_BAR                                     3

#define     IL_VT_TEMP_UNIT_C_DEGREE                                    0
#define     IL_VT_TEMP_UNIT_F_DEGREE                                    1

#define     IL_VT_VH_SPEED_UNIT_KMPH                                    0
#define     IL_VT_VH_SPEED_UNIT_MPH                                     1

#ifdef __cplusplus
}
#endif

#endif /* _CAN_IL_ENUM_H */

/*!*******************************************************************
*
* @}
*
*********************************************************************/