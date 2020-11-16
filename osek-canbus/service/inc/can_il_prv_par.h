/*!*******************************************************************
* @file can_il_prv_par.h
* @brief Interaction Layer Transmit and Receive Signal Index Definitions
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
* signal index definitions. This file is generated using a separate
* Network "Gen" tool based on the CAN database supplied by the OEM
* along with user configuration inputs.
*
* Copyright 2018 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack_il_cfg
* @{
*
*********************************************************************/

#ifndef _CAN_IL_PRV_PAR_H
#define _CAN_IL_PRV_PAR_H

#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------------------
CAN 0 Transmit Signal Enumerations (Indexes)
------------------------------------------------------*/

#define     IL_CAN0_MEDIA_VOL_LV_TXSIG_INDEX                    (0x0000)
#define     IL_CAN0_MUSIC_STATUS_TXSIG_INDEX                    (0x0001)
#define     IL_CAN0_PHONECALL_VOL_LV_TXSIG_INDEX                (0x0002)
#define     IL_CAN0_RINGTONE_VOL_LV_TXSIG_INDEX                 (0x0003)
#define     IL_CAN0_LBREPREQ_TXSIG_INDEX                        (0x0004)
#define     IL_CAN0_PROGSTS_TXSIG_INDEX                         (0x0005)
#define     IL_CAN0_RESP_DATA_1_SCRNTRANS_TXSIG_INDEX           (0x0006)
#define     IL_CAN0_RESP_DATA_2_SCRNTRANS_TXSIG_INDEX           (0x0007)
#define     IL_CAN0_RESP_SERVICE_ID_SCRNTRANS_TXSIG_INDEX       (0x0008)
#define     IL_CAN0_LANGUAGE_TXSIG_INDEX                        (0x0009)
#define     IL_CAN0_LB_LAYER_TXSIG_INDEX                        (0x000A)
#define     IL_CAN0_LB_SYS_STATUS_TXSIG_INDEX                   (0x000B)
#define     IL_CAN0_FRAME_COUNTER_TXSIG_INDEX                   (0x000C)
#define     IL_CAN0_NO_OF_FRAME_TXSIG_INDEX                     (0x000D)
#define     IL_CAN0_UNICODE_1_TXSIG_INDEX                       (0x000E)
#define     IL_CAN0_UNICODE_2_TXSIG_INDEX                       (0x000F)
#define     IL_CAN0_UNICODE_3_TXSIG_INDEX                       (0x0010)
#define     IL_CAN0_BT_PHONE_STATUS_TXSIG_INDEX                 (0x0011)
#define     IL_CAN0_BT_PSSNGER_HDSET_STATUS_TXSIG_INDEX         (0x0012)
#define     IL_CAN0_BT_RIDER_HDSET_STATUS_TXSIG_INDEX           (0x0013)
#define     IL_CAN0_MUTE_STATUS_TXSIG_INDEX                     (0x0014)
#define     IL_CAN0_NOTIFICATION_STATUS_TXSIG_INDEX             (0x0015)
#define     IL_CAN0_PHONE_BATTERY_STATUS_TXSIG_INDEX            (0x0016)
#define     IL_CAN0_PHONE_MISSED_CALL_TXSIG_INDEX               (0x0017)
#define     IL_CAN0_PHONE_SIG_SENSITIVITY_TXSIG_INDEX           (0x0018)
#define     IL_CAN0_PHONE_STATUS_TXSIG_INDEX                    (0x0019)
#define     IL_CAN0_WIFI_SIG_SENSITIVITY_TXSIG_INDEX            (0x001A)
#define     IL_CAN0_YAPP_LAUNCH_STATUS_TXSIG_INDEX              (0x001B)
#define     IL_CAN0_RESP_DATA_1_CLKDATA_TXSIG_INDEX             (0x001C)
#define     IL_CAN0_RESP_DATA_2_CLKDATA_TXSIG_INDEX             (0x001D)
#define     IL_CAN0_RESP_DATA_3_CLKDATA_TXSIG_INDEX             (0x001E)
#define     IL_CAN0_RESP_DATA_4_CLKDATA_TXSIG_INDEX             (0x001F)
#define     IL_CAN0_RESP_DATA_5_CLKDATA_TXSIG_INDEX             (0x0020)
#define     IL_CAN0_RESP_SERVICE_ID_CLKDATA_TXSIG_INDEX         (0x0021)
#define     IL_CAN0_LBREQST_TXSIG_INDEX                         (0x0022)
#define     IL_CAN0_MSCRNO_TXSIG_INDEX                          (0x0023)

#define     IL_CAN0_TX_NUM_SIGNALS                              (0x0024)


/*------------------------------------------------------
CAN 0 Receive Signal Enumerations (Indexes)
------------------------------------------------------*/

#define     IL_CAN0_FUNC_SW_1_RXSIG_INDEX                       (0x0000)
#define     IL_CAN0_FUNC_SW_10_RXSIG_INDEX                      (0x0001)
#define     IL_CAN0_FUNC_SW_11_RXSIG_INDEX                      (0x0002)
#define     IL_CAN0_FUNC_SW_12_RXSIG_INDEX                      (0x0003)
#define     IL_CAN0_FUNC_SW_13_RXSIG_INDEX                      (0x0004)
#define     IL_CAN0_FUNC_SW_14_RXSIG_INDEX                      (0x0005)
#define     IL_CAN0_FUNC_SW_15_RXSIG_INDEX                      (0x0006)
#define     IL_CAN0_FUNC_SW_16_RXSIG_INDEX                      (0x0007)
#define     IL_CAN0_FUNC_SW_17_RXSIG_INDEX                      (0x0008)
#define     IL_CAN0_FUNC_SW_18_RXSIG_INDEX                      (0x0009)
#define     IL_CAN0_FUNC_SW_2_RXSIG_INDEX                       (0x000A)
#define     IL_CAN0_FUNC_SW_3_RXSIG_INDEX                       (0x000B)
#define     IL_CAN0_FUNC_SW_4_RXSIG_INDEX                       (0x000C)
#define     IL_CAN0_FUNC_SW_5_RXSIG_INDEX                       (0x000D)
#define     IL_CAN0_FUNC_SW_6_RXSIG_INDEX                       (0x000E)
#define     IL_CAN0_FUNC_SW_7_RXSIG_INDEX                       (0x000F)
#define     IL_CAN0_FUNC_SW_8_RXSIG_INDEX                       (0x0010)
#define     IL_CAN0_FUNC_SW_9_RXSIG_INDEX                       (0x0011)
#define     IL_CAN0_SCREEN_LAYER_RXSIG_INDEX                    (0x0012)
#define     IL_CAN0_FUEL_RANGE_RXSIG_INDEX                      (0x0013)
#define     IL_CAN0_LOW_FUEL_WARN_RXSIG_INDEX                   (0x0014)
#define     IL_CAN0_VEHICLE_SPEED_RXSIG_INDEX                   (0x0015)
#define     IL_CAN0_MEDIA_VOL_DOWN_RXSIG_INDEX                  (0x0016)
#define     IL_CAN0_MEDIA_VOL_UP_RXSIG_INDEX                    (0x0017)
#define     IL_CAN0_NEXT_TRACK_RXSIG_INDEX                      (0x0018)
#define     IL_CAN0_PAUSE_RXSIG_INDEX                           (0x0019)
#define     IL_CAN0_PHONE_OFF_HOOK_RXSIG_INDEX                  (0x001A)
#define     IL_CAN0_PHONE_ON_HOOK_RXSIG_INDEX                   (0x001B)
#define     IL_CAN0_PHONE_VOL_DOWN_RXSIG_INDEX                  (0x001C)
#define     IL_CAN0_PHONE_VOL_UP_RXSIG_INDEX                    (0x001D)
#define     IL_CAN0_PLAY_RXSIG_INDEX                            (0x001E)
#define     IL_CAN0_PREVIOUSE_TRACK_RXSIG_INDEX                 (0x001F)
#define     IL_CAN0_RINGTONE_VOL_DOWN_RXSIG_INDEX               (0x0020)
#define     IL_CAN0_RINGTONE_VOL_UP_RXSIG_INDEX                 (0x0021)
#define     IL_CAN0_STOP_RXSIG_INDEX                            (0x0022)
#define     IL_CAN0_MREQ_RXSIG_INDEX                            (0x0023)
#define     IL_CAN0_UTM_RXSIG_INDEX                             (0x0024)
#define     IL_CAN0_FUEL_CON_UNIT_RXSIG_INDEX                   (0x0025)
#define     IL_CAN0_MILEAGE_UNIT_RXSIG_INDEX                    (0x0026)
#define     IL_CAN0_PRESSURE_UNIT_RXSIG_INDEX                   (0x0027)
#define     IL_CAN0_TEMP_UNIT_RXSIG_INDEX                       (0x0028)
#define     IL_CAN0_VH_SPEED_UNIT_RXSIG_INDEX                   (0x0029)
#define     IL_CAN0_LBSCRNO_RXSIG_INDEX                         (0x002A)
#define     IL_CAN0_MREQST_RXSIG_INDEX                          (0x002B)
#define     IL_CAN0_RESP_DATA_1_REPGRINFO_RXSIG_INDEX           (0x002C)
#define     IL_CAN0_RESP_DATA_2_REPGRINFO_RXSIG_INDEX           (0x002D)
#define     IL_CAN0_RESP_SERVICE_ID_REPGRINFO_RXSIG_INDEX       (0x002E)
#define     IL_CAN0_RESP_DATA_1_SCRNTRANS2_RXSIG_INDEX          (0x002F)
#define     IL_CAN0_RESP_DATA_2_SCRNTRANS2_RXSIG_INDEX          (0x0030)
#define     IL_CAN0_RESP_SERVICE_ID_SCRNTRANS2_RXSIG_INDEX      (0x0031)

#define     IL_CAN0_RX_NUM_SIGNALS                              (0x0032)


/*------------------------------------------------------
CAN 0 Receive Frame Enumerations (Indexes)
------------------------------------------------------*/

#define IL_CAN0_ID0_FUNCSW_STATUS_INDEX                         (0)
#define IL_CAN0_ID1_VEHICLE_INFO_INDEX                          (1)
#define IL_CAN0_ID2_FUNC_CNTRL_INDEX                            (2)
#define IL_CAN0_ID3_CLK_DATE_REQ_INDEX                          (3)
#define IL_CAN0_ID4_UNIT_INFO_INDEX                             (4)
#define IL_CAN0_ID5_REQ_SCRN_TRNSTN_INDEX                       (5)
#define IL_CAN0_ID6_RES_REPRGRM_INFO_INDEX                      (6)
#define IL_CAN0_ID7_RES_SCRN_TRNSTN2_INDEX                      (7)



#ifdef __cplusplus
}
#endif

#endif /* _CAN_IL_PRV_PAR_H */

/*!*******************************************************************
*
* @}
*
*********************************************************************/