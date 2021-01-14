/*!*******************************************************************
* @file can_dll_prv_par.h
* @brief Dispatch Lower Layer Frame Handle Defintions
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
* This file contains the Dispatch Layer CAN message frame definitions,
* including the CAN Identifiers and the message length definitions
* that are needed to support transmission and reception of CAN frames.
* This file is generated using a separate Network "Gen" tool based on
* the CAN database supplied by the OEM along with user configuration
* inputs.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack_dll_cfg
* @{
*
*********************************************************************/

#ifndef _CAN_DLL_PRV_PAR_H
#define _CAN_DLL_PRV_PAR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "can_dll_par.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*------------------------------------------------------
INTERACTION LAYER FRAME DEFINITIONS
------------------------------------------------------*/

/*------------------------------------------------------
IL CAN0 Transmitted Frame ID's
------------------------------------------------------*/

#define     TX_DIAG_RELATED_CAN0_ID                             (0x4D1)
#define     TX_NM_AND_LP_BK_CAN0_ID                             (0x227)
#define     TX0_REQ_MT_FUNC_CNT_CAN0_ID                         (0x584)
#define     TX1_SYS_INFO_CAN0_ID                                (0x57A)
#define     TX2_REQ_SUPPORT_CAN0_ID                             (0x581)
#define     TX3_HEATER_LEVEL_CAN0_ID                            (0x5B1)
#define     TX4_REQ_REPRGRM_INFO_CAN0_ID                        (0x5B3)
#define     TX5_CLK_DATA_RES_CAN0_ID                            (0x5BF)
#define     TX6_DEV_CTRL_CAN0_ID                                (0x5CA)
#define     TX7_FACT_INSP1_GA_CAN0_ID                           (0x690)


/*------------------------------------------------------
IL CAN0 Transmitted Frame Length (in Bytes) Definitions
------------------------------------------------------*/

#define     IL_CAN0_TX_DIAG_RELATED_TXFRM_LEN                   (8)
#define     IL_CAN0_TX_NM_AND_LP_BK_TXFRM_LEN                   (8)
#define     IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_LEN               (3)
#define     IL_CAN0_TX1_SYS_INFO_TXFRM_LEN                      (2)
#define     IL_CAN0_TX2_REQ_SUPPORT_TXFRM_LEN                   (1)
#define     IL_CAN0_TX3_HEATER_LEVEL_TXFRM_LEN                  (1)
#define     IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_LEN              (2)
#define     IL_CAN0_TX5_CLK_DATA_RES_TXFRM_LEN                  (5)
#define     IL_CAN0_TX6_DEV_CTRL_TXFRM_LEN                      (2)
#define     IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_LEN                 (8)


/*------------------------------------------------------
IL CAN0 Transmitted Frame Index Definitions
------------------------------------------------------*/

#define     IL_CAN0_TX_DIAG_RELATED_TXFRM_INDEX                 DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_TX_DIAG_RELATED_TXFRM_HANDLE )
#define     IL_CAN0_TX_NM_AND_LP_BK_TXFRM_INDEX                 DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_TX_NM_AND_LP_BK_TXFRM_HANDLE )
#define     IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_INDEX             DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_HANDLE )
#define     IL_CAN0_TX1_SYS_INFO_TXFRM_INDEX                    DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_TX1_SYS_INFO_TXFRM_HANDLE )
#define     IL_CAN0_TX2_REQ_SUPPORT_TXFRM_INDEX                 DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_TX2_REQ_SUPPORT_TXFRM_HANDLE )
#define     IL_CAN0_TX3_HEATER_LEVEL_TXFRM_INDEX                DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_TX3_HEATER_LEVEL_TXFRM_HANDLE )
#define     IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_INDEX            DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_HANDLE )
#define     IL_CAN0_TX5_CLK_DATA_RES_TXFRM_INDEX                DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_TX5_CLK_DATA_RES_TXFRM_HANDLE )
#define     IL_CAN0_TX6_DEV_CTRL_TXFRM_INDEX                    DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_TX6_DEV_CTRL_TXFRM_HANDLE )
#define     IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_INDEX               DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_HANDLE )

#define     IL_CAN0_TX_NUM_FRAMES                               (0x000A)


/*------------------------------------------------------
IL CAN0 Received Frame ID's
------------------------------------------------------*/

#define     RX_DAIG_SEG1_CAN0_ID                                (0x4C8)
#define     RX_DAIG_SEG2_CAN0_ID                                (0x4E8)
#define     RX_DAIG_SEG3_CAN0_ID                                (0x4D9)
#define     RX_DAIG_SEG4_CAN0_ID                                (0x4DA)
#define     RX_DAIG_SEG5_YDT_CAN0_ID                            (0x7C0)
#define     RX_DAIG_SEG6_YDT_CAN0_ID                            (0x7D0)
#define     RX_DAIG_SEG7_YDT_CAN0_ID                            (0x7E0)
#define     RX_NM_AND_LP_BK_CAN0_ID                             (0x226)
#define     RX0_ECU_INDCT_STAT_CAN0_ID                          (0x209)
#define     RX1_ECU_COM_DATA_CAN0_ID                            (0x350)
#define     RX2_RES_SUPPORT_CAN0_ID                             (0x582)
#define     RX3_BRGTHNSS_CTRL_CAN0_ID                           (0x583)
#define     RX4_RES_MT_FUNC_CNT_CAN0_ID                         (0x585)
#define     RX5_VEHICLE_INFO_CAN0_ID                            (0x5A0)
#define     RX6_FUNCSW_STAT_CAN0_ID                             (0x5A1)
#define     RX7_FUEL_RATE_CAN0_ID                               (0x5A6)
#define     RX8_ODO_TRIP_CAN0_ID                                (0x5A7)
#define     RX9_RES_RPRGRM_INFO_CAN0_ID                         (0x5AF)
#define     RXA_VEHICLE_INFO_2_CAN0_ID                          (0x5BA)
#define     RXB_VEHICLE_INFO_3_CAN0_ID                          (0x5BB)
#define     RXC_VEHICLE_INFO_4_CAN0_ID                          (0x5BC)
#define     RXD_MAINT_TRIP_CAN0_ID                              (0x5BD)
#define     RXE_HEATER_STAT_CAN0_ID                             (0x5BE)
#define     RXF_FACT_INSP_NS_CAN0_ID                            (0x5D5)
#define     RXF_FACT_INSP2_GA_CAN0_ID                           (0x691)
#define     RXG_ECU_INDCT_STAT1_CAN0_ID                         (0x20A)


/*------------------------------------------------------
IL CAN0 Received Frame Length (in Bytes) Definitions
------------------------------------------------------*/

#define     IL_CAN0_RX_DAIG_SEG1_RXFRM_LEN                      (8)
#define     IL_CAN0_RX_DAIG_SEG2_RXFRM_LEN                      (8)
#define     IL_CAN0_RX_DAIG_SEG3_RXFRM_LEN                      (8)
#define     IL_CAN0_RX_DAIG_SEG4_RXFRM_LEN                      (8)
#define     IL_CAN0_RX_DAIG_SEG5_YDT_RXFRM_LEN                  (8)
#define     IL_CAN0_RX_DAIG_SEG6_YDT_RXFRM_LEN                  (8)
#define     IL_CAN0_RX_DAIG_SEG7_YDT_RXFRM_LEN                  (8)
#define     IL_CAN0_RX_NM_AND_LP_BK_RXFRM_LEN                   (8)
#define     IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_LEN                (6)
#define     IL_CAN0_RX1_ECU_COM_DATA_RXFRM_LEN                  (8)
#define     IL_CAN0_RX2_RES_SUPPORT_RXFRM_LEN                   (8)
#define     IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_LEN                 (3)
#define     IL_CAN0_RX4_RES_MT_FUNC_CNT_RXFRM_LEN               (3)
#define     IL_CAN0_RX5_VEHICLE_INFO_RXFRM_LEN                  (3)
#define     IL_CAN0_RX6_FUNCSW_STAT_RXFRM_LEN                   (3)
#define     IL_CAN0_RX7_FUEL_RATE_RXFRM_LEN                     (8)
#define     IL_CAN0_RX8_ODO_TRIP_RXFRM_LEN                      (8)
#define     IL_CAN0_RX9_RES_RPRGRM_INFO_RXFRM_LEN               (3)
#define     IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_LEN                (8)
#define     IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_LEN                (8)
#define     IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_LEN                (3)
#define     IL_CAN0_RXD_MAINT_TRIP_RXFRM_LEN                    (8)
#define     IL_CAN0_RXE_HEATER_STAT_RXFRM_LEN                   (4)
#define     IL_CAN0_RXF_FACT_INSP_NS_RXFRM_LEN                  (1)
#define     IL_CAN0_RXF_FACT_INSP2_GA_RXFRM_LEN                 (8)
#define     IL_CAN0_RXG_ECU_INDCT_STAT1_RXFRM_LEN               (6)


/*------------------------------------------------------
IL CAN0 Received Minimum Frame Length (in Bytes)
------------------------------------------------------*/

#define     IL_CAN0_RX_DAIG_SEG1_RXFRM_MIN_LEN                  (8)
#define     IL_CAN0_RX_DAIG_SEG2_RXFRM_MIN_LEN                  (8)
#define     IL_CAN0_RX_DAIG_SEG3_RXFRM_MIN_LEN                  (8)
#define     IL_CAN0_RX_DAIG_SEG4_RXFRM_MIN_LEN                  (8)
#define     IL_CAN0_RX_DAIG_SEG5_YDT_RXFRM_MIN_LEN              (8)
#define     IL_CAN0_RX_DAIG_SEG6_YDT_RXFRM_MIN_LEN              (8)
#define     IL_CAN0_RX_DAIG_SEG7_YDT_RXFRM_MIN_LEN              (8)
#define     IL_CAN0_RX_NM_AND_LP_BK_RXFRM_MIN_LEN               (8)
#define     IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_MIN_LEN            (6)
#define     IL_CAN0_RX1_ECU_COM_DATA_RXFRM_MIN_LEN              (8)
#define     IL_CAN0_RX2_RES_SUPPORT_RXFRM_MIN_LEN               (8)
#define     IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_MIN_LEN             (3)
#define     IL_CAN0_RX4_RES_MT_FUNC_CNT_RXFRM_MIN_LEN           (3)
#define     IL_CAN0_RX5_VEHICLE_INFO_RXFRM_MIN_LEN              (3)
#define     IL_CAN0_RX6_FUNCSW_STAT_RXFRM_MIN_LEN               (3)
#define     IL_CAN0_RX7_FUEL_RATE_RXFRM_MIN_LEN                 (8)
#define     IL_CAN0_RX8_ODO_TRIP_RXFRM_MIN_LEN                  (8)
#define     IL_CAN0_RX9_RES_RPRGRM_INFO_RXFRM_MIN_LEN           (3)
#define     IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_MIN_LEN            (8)
#define     IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_MIN_LEN            (8)
#define     IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_MIN_LEN            (3)
#define     IL_CAN0_RXD_MAINT_TRIP_RXFRM_MIN_LEN                (8)
#define     IL_CAN0_RXE_HEATER_STAT_RXFRM_MIN_LEN               (4)
#define     IL_CAN0_RXF_FACT_INSP_NS_RXFRM_MIN_LEN              (1)
#define     IL_CAN0_RXF_FACT_INSP2_GA_RXFRM_MIN_LEN             (8)
#define     IL_CAN0_RXG_ECU_INDCT_STAT1_RXFRM_MIN_LEN           (6)


/*------------------------------------------------------
IL CAN0 Received Frame Index Definitions
------------------------------------------------------*/

#define     IL_CAN0_RX_DAIG_SEG1_RXFRM_INDEX                    DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX_DAIG_SEG1_RXFRM_HANDLE )
#define     IL_CAN0_RX_DAIG_SEG2_RXFRM_INDEX                    DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX_DAIG_SEG2_RXFRM_HANDLE )
#define     IL_CAN0_RX_DAIG_SEG3_RXFRM_INDEX                    DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX_DAIG_SEG3_RXFRM_HANDLE )
#define     IL_CAN0_RX_DAIG_SEG4_RXFRM_INDEX                    DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX_DAIG_SEG4_RXFRM_HANDLE )
#define     IL_CAN0_RX_DAIG_SEG5_YDT_RXFRM_INDEX                DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX_DAIG_SEG5_YDT_RXFRM_HANDLE )
#define     IL_CAN0_RX_DAIG_SEG6_YDT_RXFRM_INDEX                DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX_DAIG_SEG6_YDT_RXFRM_HANDLE )
#define     IL_CAN0_RX_DAIG_SEG7_YDT_RXFRM_INDEX                DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX_DAIG_SEG7_YDT_RXFRM_HANDLE )
#define     IL_CAN0_RX_NM_AND_LP_BK_RXFRM_INDEX                 DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX_NM_AND_LP_BK_RXFRM_HANDLE )
#define     IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_INDEX              DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_HANDLE )
#define     IL_CAN0_RX1_ECU_COM_DATA_RXFRM_INDEX                DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX1_ECU_COM_DATA_RXFRM_HANDLE )
#define     IL_CAN0_RX2_RES_SUPPORT_RXFRM_INDEX                 DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX2_RES_SUPPORT_RXFRM_HANDLE )
#define     IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_INDEX               DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_HANDLE )
#define     IL_CAN0_RX4_RES_MT_FUNC_CNT_RXFRM_INDEX             DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX4_RES_MT_FUNC_CNT_RXFRM_HANDLE )
#define     IL_CAN0_RX5_VEHICLE_INFO_RXFRM_INDEX                DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX5_VEHICLE_INFO_RXFRM_HANDLE )
#define     IL_CAN0_RX6_FUNCSW_STAT_RXFRM_INDEX                 DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX6_FUNCSW_STAT_RXFRM_HANDLE )
#define     IL_CAN0_RX7_FUEL_RATE_RXFRM_INDEX                   DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX7_FUEL_RATE_RXFRM_HANDLE )
#define     IL_CAN0_RX8_ODO_TRIP_RXFRM_INDEX                    DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX8_ODO_TRIP_RXFRM_HANDLE )
#define     IL_CAN0_RX9_RES_RPRGRM_INFO_RXFRM_INDEX             DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX9_RES_RPRGRM_INFO_RXFRM_HANDLE )
#define     IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_INDEX              DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_HANDLE )
#define     IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_INDEX              DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_HANDLE )
#define     IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_INDEX              DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_HANDLE )
#define     IL_CAN0_RXD_MAINT_TRIP_RXFRM_INDEX                  DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RXD_MAINT_TRIP_RXFRM_HANDLE )
#define     IL_CAN0_RXE_HEATER_STAT_RXFRM_INDEX                 DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RXE_HEATER_STAT_RXFRM_HANDLE )
#define     IL_CAN0_RXF_FACT_INSP_NS_RXFRM_INDEX                DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RXF_FACT_INSP_NS_RXFRM_HANDLE )
#define     IL_CAN0_RXF_FACT_INSP2_GA_RXFRM_INDEX               DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RXF_FACT_INSP2_GA_RXFRM_HANDLE )
#define     IL_CAN0_RXG_ECU_INDCT_STAT1_RXFRM_INDEX             DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RXG_ECU_INDCT_STAT1_RXFRM_HANDLE )

#define     IL_CAN0_RX_NUM_FRAMES                               (0x001A)

/*------------------------------------------------------
TRANSPORT PROTOCOL LAYER TX FRAME DEFINITIONS
------------------------------------------------------*/
#define     TP_MIN_FRAME_HANDLE                                 (0xF000)
#define     TP_MAX_FRAME_HANDLE                                 (0xF100)

/*------------------------------------------------------
Transmit Complete Queue Sizes
------------------------------------------------------*/
#define     DLL_CAN0_TXC_QUEUE_SIZE                             ( ( IL_CAN0_TX_NUM_FRAMES ) * 2 )


/*------------------------------------------------------
FILTER ASSIGNMENT MACRO's
------------------------------------------------------*/

/*------------------------------------------------------
CAN0 Receive Filter Assignment Macro's
------------------------------------------------------*/

#define     DLL_CAN0_VCTR0_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR1_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR2_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR3_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR4_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR5_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR6_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR7_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR8_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR9_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR10_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR11_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR12_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR13_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR14_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR15_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR16_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR17_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR18_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR19_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR20_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR21_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR22_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR23_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR24_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR25_NUM_IDS                             (1)

#define     DLL_CAN0_NUM_FILT_VCTRS                             (26)

#ifdef __cplusplus
}
#endif

#endif /* _CAN_DLL_PRV_PAR_H */

/*!*******************************************************************
*
* @}
*
*********************************************************************/