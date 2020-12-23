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
#define     IL_CAN0_HEATER_LVL_BTN_STAT_AUD_TXSIG_INDEX         (0x000E)
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

#define     IL_CAN0_TX_NUM_SIGNALS                              (0x001B)


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
#define     IL_CAN0_ECU_INDCT_EG_SPD_RXSIG_INDEX                (0x0008)
#define     IL_CAN0_ECU_INDCT_TC_MODE_RXSIG_INDEX               (0x0009)
#define     IL_CAN0_ECU_COM_DATA_RXSIG_INDEX                    (0x000A)
#define     IL_CAN0_RES_SUPPT_DATA_1_RXSIG_INDEX                (0x000B)
#define     IL_CAN0_RES_SUPPT_DATA_2_RXSIG_INDEX                (0x000C)
#define     IL_CAN0_RES_SUPPT_DATA_3_RXSIG_INDEX                (0x000D)
#define     IL_CAN0_RES_SUPPT_DATA_4_RXSIG_INDEX                (0x000E)
#define     IL_CAN0_RES_SUPPT_DATA_5_RXSIG_INDEX                (0x000F)
#define     IL_CAN0_RES_SUPPT_DATA_6_RXSIG_INDEX                (0x0010)
#define     IL_CAN0_RES_SUPPT_DATA_7_RXSIG_INDEX                (0x0011)
#define     IL_CAN0_RES_SUPPT_SVC_ID_RXSIG_INDEX                (0x0012)
#define     IL_CAN0_BRTNSS_CTRL_LCD_LV_RXSIG_INDEX              (0x0013)
#define     IL_CAN0_BRTNSS_CTRL_MT_TFT_DUTY_RXSIG_INDEX         (0x0014)
#define     IL_CAN0_RES_MT_FUNC_CNT_DATA_1_RXSIG_INDEX          (0x0015)
#define     IL_CAN0_RES_MT_FUNC_CNT_DATA_2_RXSIG_INDEX          (0x0016)
#define     IL_CAN0_RES_MT_FUNC_CNT_SVC_ID_RXSIG_INDEX          (0x0017)
#define     IL_CAN0_VEHICLE_INFO_FUEL_CON_UNIT_RXSIG_INDEX      (0x0018)
#define     IL_CAN0_VEHICLE_INFO_MILE_UNIT_RXSIG_INDEX          (0x0019)
#define     IL_CAN0_VEHICLE_INFO_PRESS_UNIT_RXSIG_INDEX         (0x001A)
#define     IL_CAN0_VEHICLE_INFO_TEMP_UNIT_RXSIG_INDEX          (0x001B)
#define     IL_CAN0_FUNC_SW_1_RXSIG_INDEX                       (0x001C)
#define     IL_CAN0_FUNC_SW_2_RXSIG_INDEX                       (0x001D)
#define     IL_CAN0_FUNC_SW_5_RXSIG_INDEX                       (0x001E)
#define     IL_CAN0_FUNC_SW_6_RXSIG_INDEX                       (0x001F)
#define     IL_CAN0_FUNC_SW_SCRN_LAYER_RXSIG_INDEX              (0x0020)
#define     IL_CAN0_FUEL_RATE_AVE_RXSIG_INDEX                   (0x0021)
#define     IL_CAN0_FUEL_RATE_AVG_SPD_RXSIG_INDEX               (0x0022)
#define     IL_CAN0_FUEL_RATE_INST_RXSIG_INDEX                  (0x0023)
#define     IL_CAN0_FUEL_RATE_RANGE_DIST_RXSIG_INDEX            (0x0024)
#define     IL_CAN0_ODO_TRIP_ODOMETER_RXSIG_INDEX               (0x0025)
#define     IL_CAN0_ODO_TRIP1_METER_RXSIG_INDEX                 (0x0026)
#define     IL_CAN0_ODO_TRIP2_METER_RXSIG_INDEX                 (0x0027)
#define     IL_CAN0_RES_REPRGRM_DATA_1_RXSIG_INDEX              (0x0028)
#define     IL_CAN0_RES_REPRGRM_DATA_2_RXSIG_INDEX              (0x0029)
#define     IL_CAN0_RES_REPRGRM_SVC_ID_RXSIG_INDEX              (0x002A)
#define     IL_CAN0_VEHICLE_INFO_2_APS_ANG_TRAN_RXSIG_INDEX     (0x002B)
#define     IL_CAN0_VEHICLE_INFO_2_SPD_REAL_RXSIG_INDEX         (0x002C)
#define     IL_CAN0_VEHICLE_INFO_2_SPD_REAL_MT_RXSIG_INDEX      (0x002D)
#define     IL_CAN0_VEHICLE_INFO_3_AIR_RXSIG_INDEX              (0x002E)
#define     IL_CAN0_VEHICLE_INFO_3_BAT_RXSIG_INDEX              (0x002F)
#define     IL_CAN0_VEHICLE_INFO_3_CLK_ADJST_RXSIG_INDEX        (0x0030)
#define     IL_CAN0_VEHICLE_INFO_3_COOLANT_RXSIG_INDEX          (0x0031)
#define     IL_CAN0_VEHICLE_INFO_3_CRUISE_RXSIG_INDEX           (0x0032)
#define     IL_CAN0_VEHICLE_INFO_3_FUEL_CON_RXSIG_INDEX         (0x0033)
#define     IL_CAN0_VEHICLE_INFO_4_FTRIP_RXSIG_INDEX            (0x0034)
#define     IL_CAN0_VEHICLE_INFO_4_FTRIP_HRD_RST_RXSIG_INDEX    (0x0035)
#define     IL_CAN0_VEHICLE_INFO_4_FUEL_RSV_RXSIG_INDEX         (0x0036)
#define     IL_CAN0_VEHICLE_INFO_4_LOW_FUEL_WRN_RXSIG_INDEX     (0x0037)
#define     IL_CAN0_VEHICLE_INFO_4_ODO_TRIP_DIS_RXSIG_INDEX     (0x0038)
#define     IL_CAN0_MAINT_TRIP_1_RXSIG_INDEX                    (0x0039)
#define     IL_CAN0_MAINT_TRIP_2_RXSIG_INDEX                    (0x003A)
#define     IL_CAN0_MAINT_TRIP_3_RXSIG_INDEX                    (0x003B)
#define     IL_CAN0_HEATER_STAT_CRNT_GW_STAT_RXSIG_INDEX        (0x003C)
#define     IL_CAN0_HEATER_STAT_CRNT_SH_STAT_RXSIG_INDEX        (0x003D)
#define     IL_CAN0_HEATER_STAT_GRIP_WARM_HI_RXSIG_INDEX        (0x003E)
#define     IL_CAN0_HEATER_STAT_GRIP_WARM_LO_RXSIG_INDEX        (0x003F)
#define     IL_CAN0_HEATER_STAT_GRIP_WARM_MID_RXSIG_INDEX       (0x0040)
#define     IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_HI_RXSIG_INDEX  (0x0041)
#define     IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_LO_RXSIG_INDEX  (0x0042)
#define     IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_MID_RXSIG_INDEX (0x0043)
#define     IL_CAN0_FACT_INSP_NS1_RXSIG_INDEX                   (0x0044)
#define     IL_CAN0_FACT_INSP2_GA_RX_RXSIG_INDEX                (0x0045)

#define     IL_CAN0_RX_NUM_SIGNALS                              (0x0046)

/*------------------------------------------------------
CAN 0 Receive Frame Enumerations (Indexes)
------------------------------------------------------*/

#define IL_CAN0_RX_DAIG_SEG1_INDEX                        (0)
#define IL_CAN0_RX_DAIG_SEG2_INDEX                        (1)
#define IL_CAN0_RX_DAIG_SEG3_INDEX                        (2)
#define IL_CAN0_RX_DAIG_SEG4_INDEX                        (3)
#define IL_CAN0_RX_DAIG_SEG5_YDT_INDEX                    (4)
#define IL_CAN0_RX_DAIG_SEG6_YDT_INDEX                    (5)
#define IL_CAN0_RX_DAIG_SEG7_YDT_INDEX                    (6)
#define IL_CAN0_RX_NM_AND_LP_BK_INDEX                     (7)
#define IL_CAN0_RX0_ECU_INDCT_STAT_INDEX                  (8)
#define IL_CAN0_RX1_ECU_COM_DATA_INDEX                    (9)
#define IL_CAN0_RX2_RES_SUPPORT_INDEX                     (10)
#define IL_CAN0_RX3_BRGTHNSS_CTRL_INDEX                   (11)
#define IL_CAN0_RX4_RES_MT_FUNC_CNT_INDEX                 (12)
#define IL_CAN0_RX5_VEHICLE_INFO_INDEX                    (13)
#define IL_CAN0_RX6_FUNCSW_STAT_INDEX                     (14)
#define IL_CAN0_RX7_FUEL_RATE_INDEX                       (15)
#define IL_CAN0_RX8_ODO_TRIP_INDEX                        (16)
#define IL_CAN0_RX9_RES_RPRGRM_INFO_INDEX                 (17)
#define IL_CAN0_RXA_VEHICLE_INFO_2_INDEX                  (18)
#define IL_CAN0_RXB_VEHICLE_INFO_3_INDEX                  (19)
#define IL_CAN0_RXC_VEHICLE_INFO_4_INDEX                  (20)
#define IL_CAN0_RXD_MAINT_TRIP_INDEX                      (21)
#define IL_CAN0_RXE_HEATER_STAT_INDEX                     (22)
#define IL_CAN0_RXF_FACT_INSP_NS_INDEX                    (23)
#define IL_CAN0_RXF_FACT_INSP2_GA_INDEX                   (24)

#ifdef __cplusplus
}
#endif

#endif /* _CAN_IL_PRV_PAR_H */

/*!*******************************************************************
*
* @}
*
*********************************************************************/
