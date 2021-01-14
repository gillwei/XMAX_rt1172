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
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
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
TX1_SYS_INFO Enumerations
------------------------------------------------------*/

#define     IL_VT_SYS_INFO_VH_SPEED_UNIT_KMPH                           0
#define     IL_VT_SYS_INFO_VH_SPEED_UNIT_MPH                            1

#define     IL_VT_SYS_INFO_TEMP_UNIT_C_DEGREE                           0
#define     IL_VT_SYS_INFO_TEMP_UNIT_F_DEGREE                           1

#define     IL_VT_SYS_INFO_PRESSURE_UNIT_PSI                            0
#define     IL_VT_SYS_INFO_PRESSURE_UNIT_KPA                            1
#define     IL_VT_SYS_INFO_PRESSURE_UNIT_KGFPCM2                        2

#define     IL_VT_SYS_INFO_MILEAGE_UNIT_KM                              0
#define     IL_VT_SYS_INFO_MILEAGE_UNIT_MILE                            1

#define     IL_VT_SYS_INFO_LC_SYS_STAT_NOT_READY                        0
#define     IL_VT_SYS_INFO_LC_SYS_STAT_READY                            1

#define     IL_VT_SYS_INFO_LANG_NONE                                    0
#define     IL_VT_SYS_INFO_LANG_DEUTSCH                                 1
#define     IL_VT_SYS_INFO_LANG_ENGLISH                                 2
#define     IL_VT_SYS_INFO_LANG_FRENCH                                  3
#define     IL_VT_SYS_INFO_LANG_ITALIAN                                 4
#define     IL_VT_SYS_INFO_LANG_JAPANESE                                5
#define     IL_VT_SYS_INFO_LANG_SPANISH                                 6
#define     IL_VT_SYS_INFO_LANG_TRADITIONAL_CHINESE                     7
#define     IL_VT_SYS_INFO_LANG_SIMPLIFIED_CHINESE                      8
#define     IL_VT_SYS_INFO_LANG_GREEK                                   9
#define     IL_VT_SYS_INFO_LANG_FINNISH                                 10
#define     IL_VT_SYS_INFO_LANG_HINDI                                   11
#define     IL_VT_SYS_INFO_LANG_INDONESIAN                              12
#define     IL_VT_SYS_INFO_LANG_POLISH                                  13
#define     IL_VT_SYS_INFO_LANG_PORTUGUESE_BRAZIL                       14
#define     IL_VT_SYS_INFO_LANG_THAI                                    15
#define     IL_VT_SYS_INFO_LANG_VIETNAMESE                              16
#define     IL_VT_SYS_INFO_LANG_KOREAN                                  17
#define     IL_VT_SYS_INFO_LANG_MALAY                                   18

#define     IL_VT_SYS_INFO_FUEL_UNIT_L                                  0
#define     IL_VT_SYS_INFO_FUEL_UNIT_GALLON                             1

#define     IL_VT_SYS_INFO_FUEL_CON_UNIT_KMPL                           0
#define     IL_VT_SYS_INFO_FUEL_CON_UNIT_MGP                            1
#define     IL_VT_SYS_INFO_FUEL_CON_UNIT_LP100KM                        2


/*------------------------------------------------------
TX3_HEATER_LEVEL Enumerations
------------------------------------------------------*/

#define     IL_VT_HEATER_LVL_SLECT_GRIP_WARNER                          0
#define     IL_VT_HEATER_LVL_SLECT_RIDER_SEAT_HEATER                    1
#define     IL_VT_HEATER_LVL_SLECT_PASSENGER_SEAT_HEATER                2

#define     IL_VT_HEATER_LVL_LV_LO                                      0
#define     IL_VT_HEATER_LVL_LV_MID                                     1
#define     IL_VT_HEATER_LVL_LV_HI                                      2

#define     IL_VT_HEATER_LVL_BTN_STAT_AUD_DOWN                          0
#define     IL_VT_HEATER_LVL_BTN_STAT_AUD_UP                            1


/*------------------------------------------------------
TX6_DEV_CTRL Enumerations
------------------------------------------------------*/

#define     IL_VT_DEV_CTRL_TFT_BRGHTNSS_NT                              0
#define     IL_VT_DEV_CTRL_TFT_BRGHTNSS_DOWN                            1
#define     IL_VT_DEV_CTRL_TFT_BRGHTNSS_UP                              2

#define     IL_VT_DEV_CTRL_WINDSCRN_NT                                  0
#define     IL_VT_DEV_CTRL_WINDSCRN_DOWN                                1
#define     IL_VT_DEV_CTRL_WINDSCRN_UP                                  2

#define     IL_VT_DEV_CTRL_SEAT_HEATER_NT                               0
#define     IL_VT_DEV_CTRL_SEAT_HEATER_DOWN                             1
#define     IL_VT_DEV_CTRL_SEAT_HEATER_UP                               2

#define     IL_VT_DEV_CTRL_LCD_BRGHTNSS_NT                              0
#define     IL_VT_DEV_CTRL_LCD_BRGHTNSS_DOWN                            1
#define     IL_VT_DEV_CTRL_LCD_BRGHTNSS_UP                              2

#define     IL_VT_DEV_CTRL_GRIP_WARM_NT                                 0
#define     IL_VT_DEV_CTRL_GRIP_WARM_DOWN                               1
#define     IL_VT_DEV_CTRL_GRIP_WARM_UP                                 2

#define     IL_VT_DEV_CTRL_CHG_METER_ODO                                0
#define     IL_VT_DEV_CTRL_CHG_METER_TRIP1                              1
#define     IL_VT_DEV_CTRL_CHG_METER_TRIP2                              2
#define     IL_VT_DEV_CTRL_CHG_METER_TRIPF                              3


/*------------------------------------------------------
Receive Enumerations
------------------------------------------------------*/

/*------------------------------------------------------
RX5_VEHICLE_INFO Enumerations
------------------------------------------------------*/

#define     IL_VT_VEHICLE_INFO_FUEL_CON_UNIT_KMPL                       0
#define     IL_VT_VEHICLE_INFO_FUEL_CON_UNIT_MPG                        1
#define     IL_VT_VEHICLE_INFO_FUEL_CON_UNIT_MP1MPGAL                   2
#define     IL_VT_VEHICLE_INFO_FUEL_CON_UNIT_LP100KM                    3

#define     IL_VT_VEHICLE_INFO_MILE_UNIT_KM                             0
#define     IL_VT_VEHICLE_INFO_MILE_UNIT_MILE                           1

#define     IL_VT_VEHICLE_INFO_PRESS_UNIT_PSI                           0
#define     IL_VT_VEHICLE_INFO_PRESS_UNIT_KPA                           1
#define     IL_VT_VEHICLE_INFO_PRESS_UNIT_KGFPCM2                       2
#define     IL_VT_VEHICLE_INFO_PRESS_UNIT_BAR                           3


/*------------------------------------------------------
RX6_FUNCSW_STAT Enumerations
------------------------------------------------------*/

#define     IL_VT_FUNC_SW_1_OFF                                         0
#define     IL_VT_FUNC_SW_1_ON                                          1

#define     IL_VT_FUNC_SW_2_OFF                                         0
#define     IL_VT_FUNC_SW_2_ON                                          1

#define     IL_VT_FUNC_SW_5_OFF                                         0
#define     IL_VT_FUNC_SW_5_ON                                          1

#define     IL_VT_FUNC_SW_6_OFF                                         0
#define     IL_VT_FUNC_SW_6_ON                                          1

#define     IL_VT_FUNC_SW_SCRN_LAYER_FOREGROUND                         0
#define     IL_VT_FUNC_SW_SCRN_LAYER_BACKGROUND                         1


/*------------------------------------------------------
RXB_VEHICLE_INFO_3 Enumerations
------------------------------------------------------*/

#define     IL_VT_VEHICLE_INFO_3_CLK_ADJST_NONE                         0
#define     IL_VT_VEHICLE_INFO_3_CLK_ADJST_ADJUSTED                     1


/*------------------------------------------------------
RXC_VEHICLE_INFO_4 Enumerations
------------------------------------------------------*/

#define     IL_VT_VEHICLE_INFO_4_FTRIP_HRD_RST_NOT_YET                  0
#define     IL_VT_VEHICLE_INFO_4_FTRIP_HRD_RST_DONE                     1

#define     IL_VT_VEHICLE_INFO_4_FUEL_RSV_FALSE                         0
#define     IL_VT_VEHICLE_INFO_4_FUEL_RSV_TRUE                          1

#define     IL_VT_VEHICLE_INFO_4_LOW_FUEL_WRN_FALSE                     0
#define     IL_VT_VEHICLE_INFO_4_LOW_FUEL_WRN_TRUE                      1

#define     IL_VT_VEHICLE_INFO_4_ODO_TRIP_DIS_ODO                       0
#define     IL_VT_VEHICLE_INFO_4_ODO_TRIP_DIS_TRIP1                     1
#define     IL_VT_VEHICLE_INFO_4_ODO_TRIP_DIS_TRIP2                     2
#define     IL_VT_VEHICLE_INFO_4_ODO_TRIP_DIS_TRIPF                     3


/*------------------------------------------------------
RXE_HEATER_STAT Enumerations
------------------------------------------------------*/

#define     IL_VT_HEATER_STAT_CRNT_GW_STAT_OFF                          0
#define     IL_VT_HEATER_STAT_CRNT_GW_STAT_LO                           1
#define     IL_VT_HEATER_STAT_CRNT_GW_STAT_MID                          2
#define     IL_VT_HEATER_STAT_CRNT_GW_STAT_HI                           3

#define     IL_VT_HEATER_STAT_CRNT_SH_STAT_OFF                          0
#define     IL_VT_HEATER_STAT_CRNT_SH_STAT_LO                           1
#define     IL_VT_HEATER_STAT_CRNT_SH_STAT_MID                          2
#define     IL_VT_HEATER_STAT_CRNT_SH_STAT_HI                           3

#ifdef __cplusplus
}
#endif

#endif /* _CAN_IL_ENUM_H */

/*!*******************************************************************
*
* @}
*
*********************************************************************/