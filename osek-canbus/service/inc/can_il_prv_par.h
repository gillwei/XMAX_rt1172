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
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
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

#define     IL_CAN0_DAIG_SEG_DATA_TX_TXSIG_INDEX                (0x0000)
#define     IL_CAN0_NM_AND_LPBK_TX_TXSIG_INDEX                  (0x0001)
#define     IL_CAN0_REQ_MT_FUNC_CNT_DATA_1_TXSIG_INDEX          (0x0002)
#define     IL_CAN0_REQ_MT_FUNC_CNT_DATA_2_TXSIG_INDEX          (0x0003)
#define     IL_CAN0_REQ_MT_FUNC_CNT_SVC_ID_TXSIG_INDEX          (0x0004)
#define     IL_CAN0_SYS_INFO_FUEL_CON_UNIT_TXSIG_INDEX          (0x0005)
#define     IL_CAN0_SYS_INFO_FUEL_UNIT_TXSIG_INDEX              (0x0006)
#define     IL_CAN0_SYS_INFO_LANG_TXSIG_INDEX                   (0x0007)
#define     IL_CAN0_SYS_INFO_LC_SYS_STAT_TXSIG_INDEX            (0x0008)
#define     IL_CAN0_SYS_INFO_MILEAGE_UNIT_TXSIG_INDEX           (0x0009)
#define     IL_CAN0_SYS_INFO_PRESSURE_UNIT_TXSIG_INDEX          (0x000A)
#define     IL_CAN0_SYS_INFO_TEMP_UNIT_TXSIG_INDEX              (0x000B)
#define     IL_CAN0_SYS_INFO_VH_SPEED_UNIT_TXSIG_INDEX          (0x000C)
#define     IL_CAN0_REQ_SUPPORT_REQGSFL_TXSIG_INDEX             (0x000D)
#define     IL_CAN0_HEATER_LVL_BTN_STAT_HEATER_TXSIG_INDEX      (0x000E)
#define     IL_CAN0_HEATER_LVL_LV_TXSIG_INDEX                   (0x000F)
#define     IL_CAN0_HEATER_LVL_SLECT_TXSIG_INDEX                (0x0010)
#define     IL_CAN0_REQ_REPRGRM_LBREPREQ_TXSIG_INDEX            (0x0011)
#define     IL_CAN0_REQ_REPRGRM_PRGSTS_TXSIG_INDEX              (0x0012)
#define     IL_CAN0_CLK_DATE_RESP_DATA_TXSIG_INDEX              (0x0013)
#define     IL_CAN0_DEV_CTRL_CHG_METER_TXSIG_INDEX              (0x0014)
#define     IL_CAN0_DEV_CTRL_GRIP_WARM_TXSIG_INDEX              (0x0015)
#define     IL_CAN0_DEV_CTRL_LCD_BRGHTNSS_TXSIG_INDEX           (0x0016)
#define     IL_CAN0_DEV_CTRL_SEAT_HEATER_TXSIG_INDEX            (0x0017)
#define     IL_CAN0_DEV_CTRL_TFT_BRGHTNSS_TXSIG_INDEX           (0x0018)
#define     IL_CAN0_DEV_CTRL_WINDSCRN_TXSIG_INDEX               (0x0019)
#define     IL_CAN0_FACT_INSP1_GA_TX_TXSIG_INDEX                (0x001A)
#define     IL_CAN0_FACT_INSP_NS_RES_TXSIG_INDEX                (0x001B)
#define     IL_CAN0_FACT_INSP_NS_RES_RSV1_TXSIG_INDEX           (0x001C)
#define     IL_CAN0_FACT_INSP_NS_RES_RSV2_TXSIG_INDEX           (0x001D)
#define     IL_CAN0_FACT_INSP_NS_RES_RSV3_TXSIG_INDEX           (0x001E)
#define     IL_CAN0_FACT_INSP_NS_RES_RSV4_TXSIG_INDEX           (0x001F)
#define     IL_CAN0_FACT_INSP_NS_RES_RSV5_TXSIG_INDEX           (0x0020)
#define     IL_CAN0_FACT_INSP_NS_RES_RSV6_TXSIG_INDEX           (0x0021)
#define     IL_CAN0_FACT_INSP_NS_RESCODE_TXSIG_INDEX            (0x0022)

#define     IL_CAN0_TX_NUM_SIGNALS                              (0x0023)


/*------------------------------------------------------
CAN 0 Receive Signal Enumerations (Indexes)
------------------------------------------------------*/

#define     IL_CAN0_DAIG_SEG1_DATA_RXSIG_INDEX                  (0x0000)
#define     IL_CAN0_DAIG_SEG2_DATA_RXSIG_INDEX                  (0x0001)
#define     IL_CAN0_DAIG_SEG3_DATA_RXSIG_INDEX                  (0x0002)
#define     IL_CAN0_DAIG_SEG4_DATA_RXSIG_INDEX                  (0x0003)
#define     IL_CAN0_DAIG_SEG5_DATA_RXSIG_INDEX                  (0x0004)
#define     IL_CAN0_DAIG_SEG6_DATA_RXSIG_INDEX                  (0x0005)
#define     IL_CAN0_DAIG_SEG7_DATA_RXSIG_INDEX                  (0x0006)
#define     IL_CAN0_NM_AND_LPBK_RX_RXSIG_INDEX                  (0x0007)
#define     IL_CAN0_ECU_INDCT_CAUSTION_LAMP_RXSIG_INDEX         (0x0008)
#define     IL_CAN0_ECU_INDCT_E_LAMP_RXSIG_INDEX                (0x0009)
#define     IL_CAN0_ECU_INDCT_EG_MODE_RXSIG_INDEX               (0x000A)
#define     IL_CAN0_ECU_INDCT_EG_SPD_RXSIG_INDEX                (0x000B)
#define     IL_CAN0_ECU_INDCT_GEAR_POS4_RXSIG_INDEX             (0x000C)
#define     IL_CAN0_ECU_INDCT_GEAR_POS5_RXSIG_INDEX             (0x000D)
#define     IL_CAN0_ECU_INDCT_START_SW_STAT_RXSIG_INDEX         (0x000E)
#define     IL_CAN0_ECU_INDCT_TC_INDCT_RXSIG_INDEX              (0x000F)
#define     IL_CAN0_ECU_INDCT_TC_MODE_RXSIG_INDEX               (0x0010)
#define     IL_CAN0_ECU_COM_DATA_RXSIG_INDEX                    (0x0011)
#define     IL_CAN0_RES_SUPPT_DATA_1_RXSIG_INDEX                (0x0012)
#define     IL_CAN0_RES_SUPPT_DATA_2_RXSIG_INDEX                (0x0013)
#define     IL_CAN0_RES_SUPPT_DATA_3_RXSIG_INDEX                (0x0014)
#define     IL_CAN0_RES_SUPPT_DATA_4_RXSIG_INDEX                (0x0015)
#define     IL_CAN0_RES_SUPPT_DATA_5_RXSIG_INDEX                (0x0016)
#define     IL_CAN0_RES_SUPPT_DATA_6_RXSIG_INDEX                (0x0017)
#define     IL_CAN0_RES_SUPPT_DATA_7_RXSIG_INDEX                (0x0018)
#define     IL_CAN0_RES_SUPPT_SVC_ID_RXSIG_INDEX                (0x0019)
#define     IL_CAN0_BRTNSS_CTRL_LCD_LV_RXSIG_INDEX              (0x001A)
#define     IL_CAN0_BRTNSS_CTRL_MT_TFT_DUTY_RXSIG_INDEX         (0x001B)
#define     IL_CAN0_BRTNSS_CTRL_RSV1_RXSIG_INDEX                (0x001C)
#define     IL_CAN0_BRTNSS_CTRL_TFT_LV_RXSIG_INDEX              (0x001D)
#define     IL_CAN0_RES_MT_FUNC_CNT_DATA_1_RXSIG_INDEX          (0x001E)
#define     IL_CAN0_RES_MT_FUNC_CNT_DATA_2_RXSIG_INDEX          (0x001F)
#define     IL_CAN0_RES_MT_FUNC_CNT_SVC_ID_RXSIG_INDEX          (0x0020)
#define     IL_CAN0_VEHICLE_INFO_FUEL_CON_UNIT_RXSIG_INDEX      (0x0021)
#define     IL_CAN0_VEHICLE_INFO_MILE_UNIT_RXSIG_INDEX          (0x0022)
#define     IL_CAN0_VEHICLE_INFO_PRESS_UNIT_RXSIG_INDEX         (0x0023)
#define     IL_CAN0_VEHICLE_INFO_RSV1_RXSIG_INDEX               (0x0024)
#define     IL_CAN0_VEHICLE_INFO_RSV2_RXSIG_INDEX               (0x0025)
#define     IL_CAN0_VEHICLE_INFO_RSV3_RXSIG_INDEX               (0x0026)
#define     IL_CAN0_VEHICLE_INFO_RSV4_RXSIG_INDEX               (0x0027)
#define     IL_CAN0_VEHICLE_INFO_TEMP_UNIT_RXSIG_INDEX          (0x0028)
#define     IL_CAN0_FUNC_SW_1_RXSIG_INDEX                       (0x0029)
#define     IL_CAN0_FUNC_SW_2_RXSIG_INDEX                       (0x002A)
#define     IL_CAN0_FUNC_SW_5_RXSIG_INDEX                       (0x002B)
#define     IL_CAN0_FUNC_SW_6_RXSIG_INDEX                       (0x002C)
#define     IL_CAN0_FUNC_SW_SCRN_LAYER_RXSIG_INDEX              (0x002D)
#define     IL_CAN0_FUEL_RATE_AVE_RXSIG_INDEX                   (0x002E)
#define     IL_CAN0_FUEL_RATE_AVG_SPD_RXSIG_INDEX               (0x002F)
#define     IL_CAN0_FUEL_RATE_INST_RXSIG_INDEX                  (0x0030)
#define     IL_CAN0_FUEL_RATE_RANGE_DIST_RXSIG_INDEX            (0x0031)
#define     IL_CAN0_ODO_TRIP_ODOMETER_RXSIG_INDEX               (0x0032)
#define     IL_CAN0_ODO_TRIP1_METER_RXSIG_INDEX                 (0x0033)
#define     IL_CAN0_ODO_TRIP2_METER_RXSIG_INDEX                 (0x0034)
#define     IL_CAN0_RES_REPRGRM_DATA_1_RXSIG_INDEX              (0x0035)
#define     IL_CAN0_RES_REPRGRM_DATA_2_RXSIG_INDEX              (0x0036)
#define     IL_CAN0_RES_REPRGRM_SVC_ID_RXSIG_INDEX              (0x0037)
#define     IL_CAN0_VEHICLE_INFO_2_APS_ANG_TRAN_RXSIG_INDEX     (0x0038)
#define     IL_CAN0_VEHICLE_INFO_2_SPD_REAL_RXSIG_INDEX         (0x0039)
#define     IL_CAN0_VEHICLE_INFO_2_SPD_REAL_MT_RXSIG_INDEX      (0x003A)
#define     IL_CAN0_VEHICLE_INFO_3_AIR_RXSIG_INDEX              (0x003B)
#define     IL_CAN0_VEHICLE_INFO_3_BAT_RXSIG_INDEX              (0x003C)
#define     IL_CAN0_VEHICLE_INFO_3_CLK_ADJST_RXSIG_INDEX        (0x003D)
#define     IL_CAN0_VEHICLE_INFO_3_COOLANT_RXSIG_INDEX          (0x003E)
#define     IL_CAN0_VEHICLE_INFO_3_CRUISE_RXSIG_INDEX           (0x003F)
#define     IL_CAN0_VEHICLE_INFO_3_FUEL_CON_RXSIG_INDEX         (0x0040)
#define     IL_CAN0_VEHICLE_INFO_4_FTRIP_RXSIG_INDEX            (0x0041)
#define     IL_CAN0_VEHICLE_INFO_4_FTRIP_HRD_RST_RXSIG_INDEX    (0x0042)
#define     IL_CAN0_VEHICLE_INFO_4_FUEL_RSV_RXSIG_INDEX         (0x0043)
#define     IL_CAN0_VEHICLE_INFO_4_LOW_FUEL_WRN_RXSIG_INDEX     (0x0044)
#define     IL_CAN0_VEHICLE_INFO_4_ODO_TRIP_DIS_RXSIG_INDEX     (0x0045)
#define     IL_CAN0_MAINT_TRIP_1_RXSIG_INDEX                    (0x0046)
#define     IL_CAN0_MAINT_TRIP_2_RXSIG_INDEX                    (0x0047)
#define     IL_CAN0_MAINT_TRIP_3_RXSIG_INDEX                    (0x0048)
#define     IL_CAN0_MAINT_TRIP_RSV1_RXSIG_INDEX                 (0x0049)
#define     IL_CAN0_MAINT_TRIP_RSV2_RXSIG_INDEX                 (0x004A)
#define     IL_CAN0_HEATER_STAT_CRNT_GW_STAT_RXSIG_INDEX        (0x004B)
#define     IL_CAN0_HEATER_STAT_CRNT_SH_STAT_RXSIG_INDEX        (0x004C)
#define     IL_CAN0_HEATER_STAT_GRIP_WARM_HI_RXSIG_INDEX        (0x004D)
#define     IL_CAN0_HEATER_STAT_GRIP_WARM_LO_RXSIG_INDEX        (0x004E)
#define     IL_CAN0_HEATER_STAT_GRIP_WARM_MID_RXSIG_INDEX       (0x004F)
#define     IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_HI_RXSIG_INDEX  (0x0050)
#define     IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_LO_RXSIG_INDEX  (0x0051)
#define     IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_MID_RXSIG_INDEX (0x0052)
#define     IL_CAN0_FACT_INSP_NS_REQ_RXSIG_INDEX                (0x0053)
#define     IL_CAN0_FACT_INSP_NS_REQ_RSV1_RXSIG_INDEX           (0x0054)
#define     IL_CAN0_FACT_INSP_NS_REQ_RSV2_RXSIG_INDEX           (0x0055)
#define     IL_CAN0_FACT_INSP_NS_REQ_RSV3_RXSIG_INDEX           (0x0056)
#define     IL_CAN0_FACT_INSP_NS_REQ_RSV4_RXSIG_INDEX           (0x0057)
#define     IL_CAN0_FACT_INSP_NS_REQ_RSV5_RXSIG_INDEX           (0x0058)
#define     IL_CAN0_FACT_INSP_NS_REQ_RSV6_RXSIG_INDEX           (0x0059)
#define     IL_CAN0_FACT_INSP_NS_REQCODE_RXSIG_INDEX            (0x005A)
#define     IL_CAN0_FACT_INSP2_GA_RX_RXSIG_INDEX                (0x005B)
#define     IL_CAN0_VH_EG_SPD_CC_OPER_STAT_RXSIG_INDEX          (0x005C)
#define     IL_CAN0_VH_EG_SPD_DON_FLG_RXSIG_INDEX               (0x005D)
#define     IL_CAN0_VH_EG_SPD_E_LAMP_RXSIG_INDEX                (0x005E)
#define     IL_CAN0_VH_EG_SPD_ECU_RPLG_STAT_RXSIG_INDEX         (0x005F)
#define     IL_CAN0_VH_EG_SPD_EG_MODE_RXSIG_INDEX               (0x0060)
#define     IL_CAN0_VH_EG_SPD_EG_SPD_RXSIG_INDEX                (0x0061)
#define     IL_CAN0_VH_EG_SPD_START_SW_STAT_RXSIG_INDEX         (0x0062)
#define     IL_CAN0_VH_EG_SPD_TC_STAT_RXSIG_INDEX               (0x0063)
#define     IL_CAN0_TPMS_SENSOR_EQUIP_FLG_RXSIG_INDEX           (0x0064)
#define     IL_CAN0_TPMS_STAT_TIRE_PRESS_FR_RXSIG_INDEX         (0x0065)
#define     IL_CAN0_TPMS_STAT_TIRE_PRESS_RR_RXSIG_INDEX         (0x0066)
#define     IL_CAN0_MT_SYS_MOD_EG_MOD_TRGT_RXSIG_INDEX          (0x0067)
#define     IL_CAN0_MT_SYS_MOD_SYS_MOD_RXSIG_INDEX              (0x0068)
#define     IL_CAN0_MT_SYS_MOD_TC_MOD_TRGT_RXSIG_INDEX          (0x0069)
#define     IL_CAN0_GRIP_W_BTN_STAT_MOD_RXSIG_INDEX             (0x006A)
#define     IL_CAN0_GRIP_W_BTN_STAT_RST_RXSIG_INDEX             (0x006B)
#define     IL_CAN0_GRIP_W_BTN_STAT_SLCT_RXSIG_INDEX            (0x006C)
#define     IL_CAN0_GRIP_W_BTN_STAT_WARM_TEMP_RXSIG_INDEX       (0x006D)
#define     IL_CAN0_MT_GEAR_POS2_RXSIG_INDEX                    (0x006E)
#define     IL_CAN0_ODO_TRIP_VAL_ODO_METER_RXSIG_INDEX          (0x006F)
#define     IL_CAN0_ODO_TRIP_VAL_TRIP1_RXSIG_INDEX              (0x0070)
#define     IL_CAN0_ODO_TRIP_VAL_TRIP2_RXSIG_INDEX              (0x0071)
#define     IL_CAN0_MT_SET_INFO_SPD_UNIT_RXSIG_INDEX            (0x0072)
#define     IL_CAN0_ECU_SYS_MOD_APS_FAIL_FLG_RXSIG_INDEX        (0x0073)
#define     IL_CAN0_ECU_SYS_MOD_EB_MOD_RXSIG_INDEX              (0x0074)
#define     IL_CAN0_ECU_SYS_MOD_EG_MOD_RXSIG_INDEX              (0x0075)
#define     IL_CAN0_ECU_SYS_MOD_FLG1_RXSIG_INDEX                (0x0076)
#define     IL_CAN0_ECU_SYS_MOD_FLG2_RXSIG_INDEX                (0x0077)
#define     IL_CAN0_ECU_SYS_MOD_FLG3_RXSIG_INDEX                (0x0078)
#define     IL_CAN0_ECU_SYS_MOD_FLG4_RXSIG_INDEX                (0x0079)
#define     IL_CAN0_ECU_SYS_MOD_FUP_EXE_RXSIG_INDEX             (0x007A)
#define     IL_CAN0_ECU_SYS_MOD_LAUNCH_INDICT_RXSIG_INDEX       (0x007B)
#define     IL_CAN0_ECU_SYS_MOD_LAUNCH_MOD_RXSIG_INDEX          (0x007C)
#define     IL_CAN0_ECU_SYS_MOD_NEUTRL_FLG_RXSIG_INDEX          (0x007D)
#define     IL_CAN0_ECU_SYS_MOD_SCS_EXE_RXSIG_INDEX             (0x007E)
#define     IL_CAN0_ECU_SYS_MOD_TC_MOD_RXSIG_INDEX              (0x007F)
#define     IL_CAN0_ECU_SYS_MOD_TCS_EXE_RXSIG_INDEX             (0x0080)
#define     IL_CAN0_ECU_SYS_MOD_WHEELIE_MOD_RXSIG_INDEX         (0x0081)
#define     IL_CAN0_ECU_SYS_MOD_YSC_FAIL_FLG_RXSIG_INDEX        (0x0082)
#define     IL_CAN0_APS_ETV_ETV_MOTO_STAT_RXSIG_INDEX           (0x0083)
#define     IL_CAN0_APS_ETV_ISC_TARGET_REV_RXSIG_INDEX          (0x0084)
#define     IL_CAN0_APS_ETV_TC_INDICT_RXSIG_INDEX               (0x0085)
#define     IL_CAN0_APS_ETV_TC_MOD_RXSIG_INDEX                  (0x0086)
#define     IL_CAN0_DIAG_EGMOD_FI_MOD_RXSIG_INDEX               (0x0087)
#define     IL_CAN0_DIAG_EGMOD_FI_WRN_LMP_RXSIG_INDEX           (0x0088)
#define     IL_CAN0_DIAG_EGMOD_FI_WRN_LMP_BLNK_RXSIG_INDEX      (0x0089)
#define     IL_CAN0_DIAG_EGMOD_ON_MOD_RXSIG_INDEX               (0x008A)
#define     IL_CAN0_EG_STAT_INJECT_RXSIG_INDEX                  (0x008B)
#define     IL_CAN0_ECU_GEAR_POS_GRIP_WARM_STAT_RXSIG_INDEX     (0x008C)
#define     IL_CAN0_ECU_GEAR_POS_PARK_BRAKE_RXSIG_INDEX         (0x008D)
#define     IL_CAN0_ECU_GEAR_POS_PARK_GEAR_POS_RXSIG_INDEX      (0x008E)
#define     IL_CAN0_ECU_GEAR_POS_REVS_RXSIG_INDEX               (0x008F)
#define     IL_CAN0_ECU_GEAR_POS_WATER_TEMP_STAT_RXSIG_INDEX    (0x0090)
#define     IL_CAN0_ECU_GEAR_POS3_RXSIG_INDEX                   (0x0091)
#define     IL_CAN0_ECU_STAT_TCU_ACTV_TST_STAT_RXSIG_INDEX      (0x0092)
#define     IL_CAN0_ECU_STAT_TCU_BLOWUP_CNTRL_STAT_RXSIG_INDEX  (0x0093)
#define     IL_CAN0_ECU_STAT_TCU_EG_SPD_RXSIG_INDEX             (0x0094)
#define     IL_CAN0_ECU_STAT_TCU_EG_STOP_FLG_RXSIG_INDEX        (0x0095)
#define     IL_CAN0_ECU_STAT_TCU_LEARN_PROHIBIT_RXSIG_INDEX     (0x0096)
#define     IL_CAN0_ECU_STAT_TCU_THROTTLE_POS_RXSIG_INDEX       (0x0097)
#define     IL_CAN0_ECU_STAT_TCU_VC_SPD_RXSIG_INDEX             (0x0098)
#define     IL_CAN0_ECVT_STAT_TCU_CVT_RATIO_RXSIG_INDEX         (0x0099)
#define     IL_CAN0_ECVT_STAT_TCU_KD_CNTRL_STAT_RXSIG_INDEX     (0x009A)
#define     IL_CAN0_ECVT_STAT_TCU_KD_ECVT_MOD_RXSIG_INDEX       (0x009B)
#define     IL_CAN0_ECVT_STAT_TCU_KD_MOD_SW_RXSIG_INDEX         (0x009C)
#define     IL_CAN0_ECVT_STAT_TCU_KD_RELAY_STAT_RXSIG_INDEX     (0x009D)
#define     IL_CAN0_ECVT_STAT_TCU_KD_STAT_RXSIG_INDEX           (0x009E)
#define     IL_CAN0_ECVT_STAT_TCU_KD_SW_RXSIG_INDEX             (0x009F)
#define     IL_CAN0_ECVT_STAT_TCU_KD_SYS_STABLE_RXSIG_INDEX     (0x00A0)
#define     IL_CAN0_ABS_PRESS_FR_C_RXSIG_INDEX                  (0x00A1)
#define     IL_CAN0_ABS_PRESS_FR_M_RXSIG_INDEX                  (0x00A2)
#define     IL_CAN0_ABS_PRESS_RR_C_RXSIG_INDEX                  (0x00A3)
#define     IL_CAN0_ABS_PRESS_RR_M_RXSIG_INDEX                  (0x00A4)
#define     IL_CAN0_ABS_STAT_BCS_MOD_RXSIG_INDEX                (0x00A5)
#define     IL_CAN0_ABS_STAT_BRK_INPUT_FLG_RXSIG_INDEX          (0x00A6)
#define     IL_CAN0_ABS_STAT_DIS_STAT_RXSIG_INDEX               (0x00A7)
#define     IL_CAN0_ABS_STAT_ERROR_RXSIG_INDEX                  (0x00A8)
#define     IL_CAN0_ABS_STAT_EXE_FLG_FR_RXSIG_INDEX             (0x00A9)
#define     IL_CAN0_ABS_STAT_EXE_FLG_RR_RXSIG_INDEX             (0x00AA)
#define     IL_CAN0_ABS_STAT_OFF_INDCT_RXSIG_INDEX              (0x00AB)
#define     IL_CAN0_ABS_STAT_OFFROAD_MOD_RXSIG_INDEX            (0x00AC)
#define     IL_CAN0_SMT_STAT_ANSB_FUNC_STAT_RXSIG_INDEX         (0x00AD)
#define     IL_CAN0_SMT_STAT_ANSB_SLCT_MOD_RXSIG_INDEX          (0x00AE)
#define     IL_CAN0_SMT_STAT_BUZZ_FUNC_STAT_RXSIG_INDEX         (0x00AF)
#define     IL_CAN0_SMT_STAT_BUZZ_SLCT_MOD_RXSIG_INDEX          (0x00B0)
#define     IL_CAN0_SMT_STAT_FOB_DRP_RXSIG_INDEX                (0x00B1)
#define     IL_CAN0_SMT_STAT_FOB_LOW_BAT_RXSIG_INDEX            (0x00B2)
#define     IL_CAN0_TLCU_COM_DATA_TX_STOP_RXSIG_INDEX           (0x00B3)
#define     IL_CAN0_TLCU_SIG_EG_LMT_REQ_RXSIG_INDEX             (0x00B4)
#define     IL_CAN0_TLCU_SIG_TILT_MOD_RXSIG_INDEX               (0x00B5)
#define     IL_CAN0_TCU_STAT_ECVT_FAIL_RXSIG_INDEX              (0x00B6)
#define     IL_CAN0_TCU_STAT_ECVT_INIT_STAT_RXSIG_INDEX         (0x00B7)
#define     IL_CAN0_TCU_STAT_ECVT_IS_PERMIT_RXSIG_INDEX         (0x00B8)
#define     IL_CAN0_TCU_STAT_ECVT_MODE_PROH_RXSIG_INDEX         (0x00B9)
#define     IL_CAN0_TCU_STAT_ECVT_START_PROH_RXSIG_INDEX        (0x00BA)
#define     IL_CAN0_TCU_STAT_ECVT_SYS_FAIL_STAT_RXSIG_INDEX     (0x00BB)
#define     IL_CAN0_TCU_STAT_SEC_SHEAV_FAIL_RXSIG_INDEX         (0x00BC)
#define     IL_CAN0_TCU_STAT_SEC_SHEAV_SPD_RXSIG_INDEX          (0x00BD)

#define     IL_CAN0_RX_NUM_SIGNALS                              (0x00BE)

#ifdef __cplusplus
}
#endif

#endif /* _CAN_IL_PRV_PAR_H */

/*!*******************************************************************
*
* @}
*
*********************************************************************/