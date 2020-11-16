/*!*******************************************************************
* @file can_il_par.h
* @brief OSEK CAN Stack Interaction Layer Public Signal Handles
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
* This file contains the Interaction Layer transmit and receive
* signal handle definitions needed for managing the transmission and
* reception of CAN application signals in the Garmin OSEK CAN Stack.
* This file is generated using a separate Network "Gen" tool based
* on the CAN database supplied by the OEM along with user
* configuration inputs.
*
* Copyright 2018 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack_il_cfg
* @{
*
*********************************************************************/

#ifndef _CAN_IL_PAR_H
#define _CAN_IL_PAR_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*------------------------------------------------------
CAN 0 Transmit Signal Application Handles

These signal handles have the CAN hardware instance
encoded in the Most Significant Nibble of the value.
------------------------------------------------------*/

#define     IL_CAN0_MEDIA_VOL_LV_TXSIG_HANDLE                   (0x0000)
#define     IL_CAN0_MUSIC_STATUS_TXSIG_HANDLE                   (0x0001)
#define     IL_CAN0_PHONECALL_VOL_LV_TXSIG_HANDLE               (0x0002)
#define     IL_CAN0_RINGTONE_VOL_LV_TXSIG_HANDLE                (0x0003)
#define     IL_CAN0_LBREPREQ_TXSIG_HANDLE                       (0x0004)
#define     IL_CAN0_PROGSTS_TXSIG_HANDLE                        (0x0005)
#define     IL_CAN0_RESP_DATA_1_SCRNTRANS_TXSIG_HANDLE          (0x0006)
#define     IL_CAN0_RESP_DATA_2_SCRNTRANS_TXSIG_HANDLE          (0x0007)
#define     IL_CAN0_RESP_SERVICE_ID_SCRNTRANS_TXSIG_HANDLE      (0x0008)
#define     IL_CAN0_LANGUAGE_TXSIG_HANDLE                       (0x0009)
#define     IL_CAN0_LB_LAYER_TXSIG_HANDLE                       (0x000A)
#define     IL_CAN0_LB_SYS_STATUS_TXSIG_HANDLE                  (0x000B)
#define     IL_CAN0_FRAME_COUNTER_TXSIG_HANDLE                  (0x000C)
#define     IL_CAN0_NO_OF_FRAME_TXSIG_HANDLE                    (0x000D)
#define     IL_CAN0_UNICODE_1_TXSIG_HANDLE                      (0x000E)
#define     IL_CAN0_UNICODE_2_TXSIG_HANDLE                      (0x000F)
#define     IL_CAN0_UNICODE_3_TXSIG_HANDLE                      (0x0010)
#define     IL_CAN0_BT_PHONE_STATUS_TXSIG_HANDLE                (0x0011)
#define     IL_CAN0_BT_PSSNGER_HDSET_STATUS_TXSIG_HANDLE        (0x0012)
#define     IL_CAN0_BT_RIDER_HDSET_STATUS_TXSIG_HANDLE          (0x0013)
#define     IL_CAN0_MUTE_STATUS_TXSIG_HANDLE                    (0x0014)
#define     IL_CAN0_NOTIFICATION_STATUS_TXSIG_HANDLE            (0x0015)
#define     IL_CAN0_PHONE_BATTERY_STATUS_TXSIG_HANDLE           (0x0016)
#define     IL_CAN0_PHONE_MISSED_CALL_TXSIG_HANDLE              (0x0017)
#define     IL_CAN0_PHONE_SIG_SENSITIVITY_TXSIG_HANDLE          (0x0018)
#define     IL_CAN0_PHONE_STATUS_TXSIG_HANDLE                   (0x0019)
#define     IL_CAN0_WIFI_SIG_SENSITIVITY_TXSIG_HANDLE           (0x001A)
#define     IL_CAN0_YAPP_LAUNCH_STATUS_TXSIG_HANDLE             (0x001B)
#define     IL_CAN0_RESP_DATA_1_CLKDATA_TXSIG_HANDLE            (0x001C)
#define     IL_CAN0_RESP_DATA_2_CLKDATA_TXSIG_HANDLE            (0x001D)
#define     IL_CAN0_RESP_DATA_3_CLKDATA_TXSIG_HANDLE            (0x001E)
#define     IL_CAN0_RESP_DATA_4_CLKDATA_TXSIG_HANDLE            (0x001F)
#define     IL_CAN0_RESP_DATA_5_CLKDATA_TXSIG_HANDLE            (0x0020)
#define     IL_CAN0_RESP_SERVICE_ID_CLKDATA_TXSIG_HANDLE        (0x0021)
#define     IL_CAN0_LBREQST_TXSIG_HANDLE                        (0x0022)
#define     IL_CAN0_MSCRNO_TXSIG_HANDLE                         (0x0023)


/*------------------------------------------------------
CAN 0 Transmit Signal Sizes in Bytes
------------------------------------------------------*/

#define     IL_CAN0_MEDIA_VOL_LV_TXSIG_NBYTES                   (1)
#define     IL_CAN0_MUSIC_STATUS_TXSIG_NBYTES                   (1)
#define     IL_CAN0_PHONECALL_VOL_LV_TXSIG_NBYTES               (1)
#define     IL_CAN0_RINGTONE_VOL_LV_TXSIG_NBYTES                (1)
#define     IL_CAN0_LBREPREQ_TXSIG_NBYTES                       (1)
#define     IL_CAN0_PROGSTS_TXSIG_NBYTES                        (1)
#define     IL_CAN0_RESP_DATA_1_SCRNTRANS_TXSIG_NBYTES          (1)
#define     IL_CAN0_RESP_DATA_2_SCRNTRANS_TXSIG_NBYTES          (1)
#define     IL_CAN0_RESP_SERVICE_ID_SCRNTRANS_TXSIG_NBYTES      (1)
#define     IL_CAN0_LANGUAGE_TXSIG_NBYTES                       (1)
#define     IL_CAN0_LB_LAYER_TXSIG_NBYTES                       (1)
#define     IL_CAN0_LB_SYS_STATUS_TXSIG_NBYTES                  (1)
#define     IL_CAN0_FRAME_COUNTER_TXSIG_NBYTES                  (1)
#define     IL_CAN0_NO_OF_FRAME_TXSIG_NBYTES                    (1)
#define     IL_CAN0_UNICODE_1_TXSIG_NBYTES                      (2)
#define     IL_CAN0_UNICODE_2_TXSIG_NBYTES                      (2)
#define     IL_CAN0_UNICODE_3_TXSIG_NBYTES                      (2)
#define     IL_CAN0_BT_PHONE_STATUS_TXSIG_NBYTES                (1)
#define     IL_CAN0_BT_PSSNGER_HDSET_STATUS_TXSIG_NBYTES        (1)
#define     IL_CAN0_BT_RIDER_HDSET_STATUS_TXSIG_NBYTES          (1)
#define     IL_CAN0_MUTE_STATUS_TXSIG_NBYTES                    (1)
#define     IL_CAN0_NOTIFICATION_STATUS_TXSIG_NBYTES            (1)
#define     IL_CAN0_PHONE_BATTERY_STATUS_TXSIG_NBYTES           (1)
#define     IL_CAN0_PHONE_MISSED_CALL_TXSIG_NBYTES              (1)
#define     IL_CAN0_PHONE_SIG_SENSITIVITY_TXSIG_NBYTES          (1)
#define     IL_CAN0_PHONE_STATUS_TXSIG_NBYTES                   (1)
#define     IL_CAN0_WIFI_SIG_SENSITIVITY_TXSIG_NBYTES           (1)
#define     IL_CAN0_YAPP_LAUNCH_STATUS_TXSIG_NBYTES             (1)
#define     IL_CAN0_RESP_DATA_1_CLKDATA_TXSIG_NBYTES            (1)
#define     IL_CAN0_RESP_DATA_2_CLKDATA_TXSIG_NBYTES            (1)
#define     IL_CAN0_RESP_DATA_3_CLKDATA_TXSIG_NBYTES            (1)
#define     IL_CAN0_RESP_DATA_4_CLKDATA_TXSIG_NBYTES            (1)
#define     IL_CAN0_RESP_DATA_5_CLKDATA_TXSIG_NBYTES            (1)
#define     IL_CAN0_RESP_SERVICE_ID_CLKDATA_TXSIG_NBYTES        (1)
#define     IL_CAN0_LBREQST_TXSIG_NBYTES                        (1)
#define     IL_CAN0_MSCRNO_TXSIG_NBYTES                         (1)


/*------------------------------------------------------
CAN 0 Receive Signal Application Handles

These signal handles have the CAN hardware instance
encoded in the Most Significant Nibble of the value.
------------------------------------------------------*/

#define     IL_CAN0_FUNC_SW_1_RXSIG_HANDLE                      (0x0000)
#define     IL_CAN0_FUNC_SW_10_RXSIG_HANDLE                     (0x0001)
#define     IL_CAN0_FUNC_SW_11_RXSIG_HANDLE                     (0x0002)
#define     IL_CAN0_FUNC_SW_12_RXSIG_HANDLE                     (0x0003)
#define     IL_CAN0_FUNC_SW_13_RXSIG_HANDLE                     (0x0004)
#define     IL_CAN0_FUNC_SW_14_RXSIG_HANDLE                     (0x0005)
#define     IL_CAN0_FUNC_SW_15_RXSIG_HANDLE                     (0x0006)
#define     IL_CAN0_FUNC_SW_16_RXSIG_HANDLE                     (0x0007)
#define     IL_CAN0_FUNC_SW_17_RXSIG_HANDLE                     (0x0008)
#define     IL_CAN0_FUNC_SW_18_RXSIG_HANDLE                     (0x0009)
#define     IL_CAN0_FUNC_SW_2_RXSIG_HANDLE                      (0x000A)
#define     IL_CAN0_FUNC_SW_3_RXSIG_HANDLE                      (0x000B)
#define     IL_CAN0_FUNC_SW_4_RXSIG_HANDLE                      (0x000C)
#define     IL_CAN0_FUNC_SW_5_RXSIG_HANDLE                      (0x000D)
#define     IL_CAN0_FUNC_SW_6_RXSIG_HANDLE                      (0x000E)
#define     IL_CAN0_FUNC_SW_7_RXSIG_HANDLE                      (0x000F)
#define     IL_CAN0_FUNC_SW_8_RXSIG_HANDLE                      (0x0010)
#define     IL_CAN0_FUNC_SW_9_RXSIG_HANDLE                      (0x0011)
#define     IL_CAN0_SCREEN_LAYER_RXSIG_HANDLE                   (0x0012)
#define     IL_CAN0_FUEL_RANGE_RXSIG_HANDLE                     (0x0013)
#define     IL_CAN0_LOW_FUEL_WARN_RXSIG_HANDLE                  (0x0014)
#define     IL_CAN0_VEHICLE_SPEED_RXSIG_HANDLE                  (0x0015)
#define     IL_CAN0_MEDIA_VOL_DOWN_RXSIG_HANDLE                 (0x0016)
#define     IL_CAN0_MEDIA_VOL_UP_RXSIG_HANDLE                   (0x0017)
#define     IL_CAN0_NEXT_TRACK_RXSIG_HANDLE                     (0x0018)
#define     IL_CAN0_PAUSE_RXSIG_HANDLE                          (0x0019)
#define     IL_CAN0_PHONE_OFF_HOOK_RXSIG_HANDLE                 (0x001A)
#define     IL_CAN0_PHONE_ON_HOOK_RXSIG_HANDLE                  (0x001B)
#define     IL_CAN0_PHONE_VOL_DOWN_RXSIG_HANDLE                 (0x001C)
#define     IL_CAN0_PHONE_VOL_UP_RXSIG_HANDLE                   (0x001D)
#define     IL_CAN0_PLAY_RXSIG_HANDLE                           (0x001E)
#define     IL_CAN0_PREVIOUSE_TRACK_RXSIG_HANDLE                (0x001F)
#define     IL_CAN0_RINGTONE_VOL_DOWN_RXSIG_HANDLE              (0x0020)
#define     IL_CAN0_RINGTONE_VOL_UP_RXSIG_HANDLE                (0x0021)
#define     IL_CAN0_STOP_RXSIG_HANDLE                           (0x0022)
#define     IL_CAN0_MREQ_RXSIG_HANDLE                           (0x0023)
#define     IL_CAN0_UTM_RXSIG_HANDLE                            (0x0024)
#define     IL_CAN0_FUEL_CON_UNIT_RXSIG_HANDLE                  (0x0025)
#define     IL_CAN0_MILEAGE_UNIT_RXSIG_HANDLE                   (0x0026)
#define     IL_CAN0_PRESSURE_UNIT_RXSIG_HANDLE                  (0x0027)
#define     IL_CAN0_TEMP_UNIT_RXSIG_HANDLE                      (0x0028)
#define     IL_CAN0_VH_SPEED_UNIT_RXSIG_HANDLE                  (0x0029)
#define     IL_CAN0_LBSCRNO_RXSIG_HANDLE                        (0x002A)
#define     IL_CAN0_MREQST_RXSIG_HANDLE                         (0x002B)
#define     IL_CAN0_RESP_DATA_1_REPGRINFO_RXSIG_HANDLE          (0x002C)
#define     IL_CAN0_RESP_DATA_2_REPGRINFO_RXSIG_HANDLE          (0x002D)
#define     IL_CAN0_RESP_SERVICE_ID_REPGRINFO_RXSIG_HANDLE      (0x002E)
#define     IL_CAN0_RESP_DATA_1_SCRNTRANS2_RXSIG_HANDLE         (0x002F)
#define     IL_CAN0_RESP_DATA_2_SCRNTRANS2_RXSIG_HANDLE         (0x0030)
#define     IL_CAN0_RESP_SERVICE_ID_SCRNTRANS2_RXSIG_HANDLE     (0x0031)


/*------------------------------------------------------
CAN 0 Receive Signal Sizes in Bytes
------------------------------------------------------*/

#define     IL_CAN0_FUNC_SW_1_RXSIG_NBYTES                      (1)
#define     IL_CAN0_FUNC_SW_10_RXSIG_NBYTES                     (1)
#define     IL_CAN0_FUNC_SW_11_RXSIG_NBYTES                     (1)
#define     IL_CAN0_FUNC_SW_12_RXSIG_NBYTES                     (1)
#define     IL_CAN0_FUNC_SW_13_RXSIG_NBYTES                     (1)
#define     IL_CAN0_FUNC_SW_14_RXSIG_NBYTES                     (1)
#define     IL_CAN0_FUNC_SW_15_RXSIG_NBYTES                     (1)
#define     IL_CAN0_FUNC_SW_16_RXSIG_NBYTES                     (1)
#define     IL_CAN0_FUNC_SW_17_RXSIG_NBYTES                     (1)
#define     IL_CAN0_FUNC_SW_18_RXSIG_NBYTES                     (1)
#define     IL_CAN0_FUNC_SW_2_RXSIG_NBYTES                      (1)
#define     IL_CAN0_FUNC_SW_3_RXSIG_NBYTES                      (1)
#define     IL_CAN0_FUNC_SW_4_RXSIG_NBYTES                      (1)
#define     IL_CAN0_FUNC_SW_5_RXSIG_NBYTES                      (1)
#define     IL_CAN0_FUNC_SW_6_RXSIG_NBYTES                      (1)
#define     IL_CAN0_FUNC_SW_7_RXSIG_NBYTES                      (1)
#define     IL_CAN0_FUNC_SW_8_RXSIG_NBYTES                      (1)
#define     IL_CAN0_FUNC_SW_9_RXSIG_NBYTES                      (1)
#define     IL_CAN0_SCREEN_LAYER_RXSIG_NBYTES                   (1)
#define     IL_CAN0_FUEL_RANGE_RXSIG_NBYTES                     (2)
#define     IL_CAN0_LOW_FUEL_WARN_RXSIG_NBYTES                  (1)
#define     IL_CAN0_VEHICLE_SPEED_RXSIG_NBYTES                  (2)
#define     IL_CAN0_MEDIA_VOL_DOWN_RXSIG_NBYTES                 (1)
#define     IL_CAN0_MEDIA_VOL_UP_RXSIG_NBYTES                   (1)
#define     IL_CAN0_NEXT_TRACK_RXSIG_NBYTES                     (1)
#define     IL_CAN0_PAUSE_RXSIG_NBYTES                          (1)
#define     IL_CAN0_PHONE_OFF_HOOK_RXSIG_NBYTES                 (1)
#define     IL_CAN0_PHONE_ON_HOOK_RXSIG_NBYTES                  (1)
#define     IL_CAN0_PHONE_VOL_DOWN_RXSIG_NBYTES                 (1)
#define     IL_CAN0_PHONE_VOL_UP_RXSIG_NBYTES                   (1)
#define     IL_CAN0_PLAY_RXSIG_NBYTES                           (1)
#define     IL_CAN0_PREVIOUSE_TRACK_RXSIG_NBYTES                (1)
#define     IL_CAN0_RINGTONE_VOL_DOWN_RXSIG_NBYTES              (1)
#define     IL_CAN0_RINGTONE_VOL_UP_RXSIG_NBYTES                (1)
#define     IL_CAN0_STOP_RXSIG_NBYTES                           (1)
#define     IL_CAN0_MREQ_RXSIG_NBYTES                           (1)
#define     IL_CAN0_UTM_RXSIG_NBYTES                            (5)
#define     IL_CAN0_FUEL_CON_UNIT_RXSIG_NBYTES                  (1)
#define     IL_CAN0_MILEAGE_UNIT_RXSIG_NBYTES                   (1)
#define     IL_CAN0_PRESSURE_UNIT_RXSIG_NBYTES                  (1)
#define     IL_CAN0_TEMP_UNIT_RXSIG_NBYTES                      (1)
#define     IL_CAN0_VH_SPEED_UNIT_RXSIG_NBYTES                  (1)
#define     IL_CAN0_LBSCRNO_RXSIG_NBYTES                        (1)
#define     IL_CAN0_MREQST_RXSIG_NBYTES                         (1)
#define     IL_CAN0_RESP_DATA_1_REPGRINFO_RXSIG_NBYTES          (1)
#define     IL_CAN0_RESP_DATA_2_REPGRINFO_RXSIG_NBYTES          (1)
#define     IL_CAN0_RESP_SERVICE_ID_REPGRINFO_RXSIG_NBYTES      (1)
#define     IL_CAN0_RESP_DATA_1_SCRNTRANS2_RXSIG_NBYTES         (1)
#define     IL_CAN0_RESP_DATA_2_SCRNTRANS2_RXSIG_NBYTES         (1)
#define     IL_CAN0_RESP_SERVICE_ID_SCRNTRANS2_RXSIG_NBYTES     (1)

#ifdef __cplusplus
}
#endif

#endif /* _CAN_IL_PAR_H */

/*!*******************************************************************
*
* @}
*
*********************************************************************/