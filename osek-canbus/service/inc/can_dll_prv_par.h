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
#define     TX8_FACT_INSP_NS_RES_CAN0_ID                        (0x60B)


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
#define     IL_CAN0_TX8_FACT_INSP_NS_RES_TXFRM_LEN              (8)


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
#define     IL_CAN0_TX8_FACT_INSP_NS_RES_TXFRM_INDEX            DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_TX8_FACT_INSP_NS_RES_TXFRM_HANDLE )

#define     IL_CAN0_TX_NUM_FRAMES                               (0x000B)


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
#define     RXF_FACT_INSP_NS_CAN0_ID                            (0x60A)
#define     RXG_FACT_INSP2_GA_CAN0_ID                           (0x691)
#define     RXH_ECU_INDCT_STAT1_CAN0_ID                         (0x20A)


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
#define     IL_CAN0_RXF_FACT_INSP_NS_RXFRM_LEN                  (8)
#define     IL_CAN0_RXG_FACT_INSP2_GA_RXFRM_LEN                 (8)
#define     IL_CAN0_RXH_ECU_INDCT_STAT1_RXFRM_LEN               (6)


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
#define     IL_CAN0_RXG_FACT_INSP2_GA_RXFRM_MIN_LEN             (8)
#define     IL_CAN0_RXH_ECU_INDCT_STAT1_RXFRM_MIN_LEN           (6)


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
#define     IL_CAN0_RXG_FACT_INSP2_GA_RXFRM_INDEX               DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RXG_FACT_INSP2_GA_RXFRM_HANDLE )
#define     IL_CAN0_RXH_ECU_INDCT_STAT1_RXFRM_INDEX             DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RXH_ECU_INDCT_STAT1_RXFRM_HANDLE )

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
Diagnostic Request and Reply CAN ID and Frame Number
Definitions

The ECU always receives a REQuest from an external
Diagnostic test tool and sends a REPly back to the
tool using the Transport Protocol. These CAN ID's and
frame definitions apply to all CAN hardware instances.
The Diagnostic TP channel is always assigned to TP
Index 0.
------------------------------------------------------*/
/*CAN0-CHANNEL 0*/
#define     TP_DIAG_ID_CAN0_NUM_TX_FRAMES                    (0x17)
#define     TP_DIAG_ID_CAN0_NUM_RX_FRAMES                    (0x16)

/*For send  client -> server_0*/
#define     TP_DIAG_ID_REP_CAN0_CHN0_CAN_ID                  (0x04E0)
#define     TP_DIAG_ID_REP_CAN0_CHN0_SFFFFC_TXFRM_HANDLE     (0xF000)
#define     TP_DIAG_ID_REP_CAN0_CHN0_FCF_TXFRM_HANDLE        (0xF001)
#define     TTP_DIAG_ID_REP_CAN0_CHN0NUM_TX_FRAMES           (0x0001)
/*For receive  server_0 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN0_CAN_ID                  (0x04E8)
#define     TP_DIAG_ID_REQ_CAN0_CHN0_SFFFFC_TXFRM_HANDLE     (0xF000)
#define     TP_DIAG_ID_REQ_CAN0_CHN0_NUM_RX_FRAMES           (0x0001)


/*CAN0-CHANNEL 1*/
/*For send  client -> server_1*/
#define     TP_DIAG_ID_REP_CAN0_CHN1_CAN_ID                  (0x04E1)
#define     TP_DIAG_ID_REP_CAN0_CHN1_SFFFFC_TXFRM_HANDLE     (0xF002)
#define     TP_DIAG_ID_REP_CAN0_CHN1_FCF_TXFRM_HANDLE        (0xF003)
#define     TP_DIAG_ID_REP_CAN0_CHN1_NUM_TX_FRAMES           (0x0001)
/*For receive  server_1 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN1_CAN_ID                  (0x04E9)
#define     TP_DIAG_ID_REQ_CAN0_CHN1_SFFFFC_TXFRM_HANDLE     (0xF001)
#define     TP_DIAG_ID_REQ_CAN0_CHN1_NUM_RX_FRAMES           (0x0001)


/*CAN0-CHANNEL 2*/
/*For send  client -> server_2*/
#define     TP_DIAG_ID_REP_CAN0_CHN2_CAN_ID                  (0x04E2)
#define     TP_DIAG_ID_REP_CAN0_CHN2_SFFFFC_TXFRM_HANDLE     (0xF004)
#define     TP_DIAG_ID_REP_CAN0_CHN2_FCF_TXFRM_HANDLE        (0xF005)
#define     TP_DIAG_ID_REP_CAN0_CHN2_NUM_TX_FRAMES           (0x0001)
/*For receive  server_2 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN2_CAN_ID                  (0x04EA)
#define     TP_DIAG_ID_REQ_CAN0_CHN2_SFFFFC_TXFRM_HANDLE     (0xF002)
#define     TP_DIAG_ID_REQ_CAN0_CHN2_NUM_RX_FRAMES           (0x0001)

/*CAN0-CHANNEL 3*/
/*For send  client -> server_3*/
#define     TP_DIAG_ID_REP_CAN0_CHN3_CAN_ID                  (0x04E3)
#define     TP_DIAG_ID_REP_CAN0_CHN3_SFFFFC_TXFRM_HANDLE     (0xF006)
#define     TP_DIAG_ID_REP_CAN0_CHN3_FCF_TXFRM_HANDLE        (0xF007)
#define     TP_DIAG_ID_REP_CAN0_CHN3_NUM_TX_FRAMES           (0x0001)
/*For receive  server_3 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN3_CAN_ID                  (0x04EB)
#define     TP_DIAG_ID_REQ_CAN0_CHN3_SFFFFC_TXFRM_HANDLE     (0xF003)
#define     TP_DIAG_ID_REQ_CAN0_CHN3_NUM_RX_FRAMES           (0x0001)

/*CAN0-CHANNEL 4*/
/*For send  client -> server_4*/
#define     TP_DIAG_ID_REP_CAN0_CHN4_CAN_ID                  (0x04E4)
#define     TP_DIAG_ID_REP_CAN0_CHN4_SFFFFC_TXFRM_HANDLE     (0xF008)
#define     TP_DIAG_ID_REP_CAN0_CHN4_FCF_TXFRM_HANDLE        (0xF009)
#define     TP_DIAG_ID_REP_CAN0_CHN4_NUM_TX_FRAMES           (0x0001)
/*For receive  server_4 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN4_CAN_ID                  (0x04EC)
#define     TP_DIAG_ID_REQ_CAN0_CHN4_SFFFFC_TXFRM_HANDLE     (0xF004)
#define     TP_DIAG_ID_REQ_CAN0_CHN4_NUM_RX_FRAMES           (0x0001)

/*CAN0-CHANNEL 5*/
/*For send  client -> server_5*/
#define     TP_DIAG_ID_REP_CAN0_CHN5_CAN_ID                  (0x04E5)
#define     TP_DIAG_ID_REP_CAN0_CHN5_SFFFFC_TXFRM_HANDLE     (0xF00A)
#define     TP_DIAG_ID_REP_CAN0_CHN5_FCF_TXFRM_HANDLE        (0xF00B)
#define     TP_DIAG_ID_REP_CAN0_CHN5_NUM_TX_FRAMES           (0x0001)
/*For receive  server_5 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN5_CAN_ID                  (0x04ED)
#define     TP_DIAG_ID_REQ_CAN0_CHN5_SFFFFC_TXFRM_HANDLE     (0xF005)
#define     TP_DIAG_ID_REQ_CAN0_CHN5_NUM_RX_FRAMES           (0x0001)


/*CAN0-CHANNEL 6*/
/*For send  client -> server_6*/
#define     TP_DIAG_ID_REP_CAN0_CHN6_CAN_ID                  (0x04E6)
#define     TP_DIAG_ID_REP_CAN0_CHN6_SFFFFC_TXFRM_HANDLE     (0xF00C)
#define     TP_DIAG_ID_REP_CAN0_CHN6_FCF_TXFRM_HANDLE        (0xF00D)
#define     TP_DIAG_ID_REP_CAN0_CHN6_NUM_TX_FRAMES           (0x0001)
/*For receive  server_6 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN6_CAN_ID                  (0x04EE)
#define     TP_DIAG_ID_REQ_CAN0_CHN6_SFFFFC_TXFRM_HANDLE     (0xF006)
#define     TP_DIAG_ID_REQ_CAN0_CHN6_NUM_RX_FRAMES           (0x0001)

/*CAN0-CHANNEL 7*/
/*For send  client -> server_7*/
#define     TP_DIAG_ID_REP_CAN0_CHN7_CAN_ID                  (0x04E7)
#define     TP_DIAG_ID_REP_CAN0_CHN7_SFFFFC_TXFRM_HANDLE     (0xF00E)
#define     TP_DIAG_ID_REP_CAN0_CHN7_FCF_TXFRM_HANDLE        (0xF00F)
#define     TP_DIAG_ID_REP_CAN0_CHN7_NUM_TX_FRAMES           (0x0001)
/*For receive  server_7 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN7_CAN_ID                  (0x04EF)
#define     TP_DIAG_ID_REQ_CAN0_CHN7_SFFFFC_TXFRM_HANDLE     (0xF007)
#define     TP_DIAG_ID_REQ_CAN0_CHN7_NUM_RX_FRAMES           (0x0001)


/*CAN0-CHANNEL 8*/
/*For send  client -> server_8*/
#define     TP_DIAG_ID_REP_CAN0_CHN8_CAN_ID                  (0x04D1)
#define     TP_DIAG_ID_REP_CAN0_CHN8_SFFFFC_TXFRM_HANDLE     (0xF010)
#define     TP_DIAG_ID_REP_CAN0_CHN8_FCF_TXFRM_HANDLE        (0xF011)
#define     TP_DIAG_ID_REP_CAN0_CHN8_NUM_TX_FRAMES           (0x0001)
/*For receive  server_8 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN8_CAN_ID                  (0x04D9)
#define     TP_DIAG_ID_REQ_CAN0_CHN8_SFFFFC_TXFRM_HANDLE     (0xF008)
#define     TP_DIAG_ID_REQ_CAN0_CHN8_NUM_RX_FRAMES           (0x0001)

/*CAN0-CHANNEL 9*/
/*For send  client -> server_9*/
#define     TP_DIAG_ID_REP_CAN0_CHN9_CAN_ID                  (0x04D2)
#define     TP_DIAG_ID_REP_CAN0_CHN9_SFFFFC_TXFRM_HANDLE     (0xF012)
#define     TP_DIAG_ID_REP_CAN0_CHN9_FCF_TXFRM_HANDLE        (0xF013)
#define     TP_DIAG_ID_REP_CAN0_CHN9_NUM_TX_FRAMES           (0x0001)
/*For receive  server_9 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN9_CAN_ID                  (0x04DA)
#define     TP_DIAG_ID_REQ_CAN0_CHN9_SFFFFC_TXFRM_HANDLE     (0xF009)
#define     TP_DIAG_ID_REQ_CAN0_CHN9_NUM_RX_FRAMES           (0x0001)

/*CAN0-CHANNEL 10*/
/*For send  client -> server_10*/
#define     TP_DIAG_ID_REP_CAN0_CHN10_CAN_ID                  (0x04D3)
#define     TP_DIAG_ID_REP_CAN0_CHN10_SFFFFC_TXFRM_HANDLE     (0xF014)
#define     TP_DIAG_ID_REP_CAN0_CHN10_FCF_TXFRM_HANDLE        (0xF015)
#define     TP_DIAG_ID_REP_CAN0_CHN10_NUM_TX_FRAMES           (0x0001)
/*For receive  server_A -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN10_CAN_ID                  (0x04DB)
#define     TP_DIAG_ID_REQ_CAN0_CHN10_SFFFFC_TXFRM_HANDLE     (0xF00A)
#define     TP_DIAG_ID_REQ_CAN0_CHN10_NUM_RX_FRAMES           (0x0001)

/*CAN0-CHANNEL 11*/
/*For send  client -> server_11*/
#define     TP_DIAG_ID_REP_CAN0_CHN11_CAN_ID                  (0x04D4)
#define     TP_DIAG_ID_REP_CAN0_CHN11_SFFFFC_TXFRM_HANDLE     (0xF016)
#define     TP_DIAG_ID_REP_CAN0_CHN11_FCF_TXFRM_HANDLE        (0xF017)
#define     TP_DIAG_ID_REP_CAN0_CHN11_NUM_TX_FRAMES           (0x0001)
/*For receive  server_11 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN11_CAN_ID                  (0x04DC)
#define     TP_DIAG_ID_REQ_CAN0_CHN11_SFFFFC_TXFRM_HANDLE     (0xF00B)
#define     TP_DIAG_ID_REQ_CAN0_CHN11_NUM_RX_FRAMES           (0x0001)


/*CAN0-CHANNEL 12*/
/*For send  client -> server_C*/
#define     TP_DIAG_ID_REP_CAN0_CHN12_CAN_ID                  (0x04D5)
#define     TP_DIAG_ID_REP_CAN0_CHN12_SFFFFC_TXFRM_HANDLE     (0xF018)
#define     TP_DIAG_ID_REP_CAN0_CHN12_FCF_TXFRM_HANDLE        (0xF019)
#define     TP_DIAG_ID_REP_CAN0_CHN12_NUM_TX_FRAMES           (0x0001)
/*For receive  server_C -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN12_CAN_ID                  (0x04DD)
#define     TP_DIAG_ID_REQ_CAN0_CHN12_SFFFFC_TXFRM_HANDLE     (0xF00C)
#define     TP_DIAG_ID_REQ_CAN0_CHN12_NUM_RX_FRAMES           (0x0001)

/*CAN0-CHANNEL 13*/
/*For send  client -> server_13*/
#define     TP_DIAG_ID_REP_CAN0_CHN13_CAN_ID                  (0x04D6)
#define     TP_DIAG_ID_REP_CAN0_CHN13_SFFFFC_TXFRM_HANDLE     (0xF01A)
#define     TP_DIAG_ID_REP_CAN0_CHN13_FCF_TXFRM_HANDLE        (0xF01B)
#define     TP_DIAG_ID_REP_CAN0_CHN13_NUM_TX_FRAMES           (0x0001)
/*For receive  server_13 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN13_CAN_ID                  (0x04DE)
#define     TP_DIAG_ID_REQ_CAN0_CHN13_SFFFFC_TXFRM_HANDLE     (0xF00D)
#define     TP_DIAG_ID_REQ_CAN0_CHN13_NUM_RX_FRAMES           (0x0001)


/*CAN0-CHANNEL 14*/
/*For send  client -> server_14*/
#define     TP_DIAG_ID_REP_CAN0_CHN14_CAN_ID                  (0x04C0)
#define     TP_DIAG_ID_REP_CAN0_CHN14_SFFFFC_TXFRM_HANDLE     (0xF01C)
#define     TP_DIAG_ID_REP_CAN0_CHN14_FCF_TXFRM_HANDLE        (0xF01D)
#define     TP_DIAG_ID_REP_CAN0_CHN14_NUM_TX_FRAMES           (0x0001)
/*For receive  server_14 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN14_CAN_ID                  (0x04C8)
#define     TP_DIAG_ID_REQ_CAN0_CHN14_SFFFFC_TXFRM_HANDLE     (0xF00E)
#define     TP_DIAG_ID_REQ_CAN0_CHN14_NUM_RX_FRAMES           (0x0001)

/*CAN0-CHANNEL 15*/
/*For send  client -> server_15*/
#define     TP_DIAG_ID_REP_CAN0_CHN15_CAN_ID                  (0x04C1)
#define     TP_DIAG_ID_REP_CAN0_CHN15_SFFFFC_TXFRM_HANDLE     (0xF01E)
#define     TP_DIAG_ID_REP_CAN0_CHN15_FCF_TXFRM_HANDLE        (0xF01F)
#define     TP_DIAG_ID_REP_CAN0_CHN15_NUM_TX_FRAMES           (0x0001)
/*For receive  server_15 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN15_CAN_ID                  (0x04C9)
#define     TP_DIAG_ID_REQ_CAN0_CHN15_SFFFFC_TXFRM_HANDLE     (0xF00F)
#define     TP_DIAG_ID_REQ_CAN0_CHN15_NUM_RX_FRAMES           (0x0001)

/*CAN0-CHANNEL 16*/
/*For send  client -> server_15*/
#define     TP_DIAG_ID_REP_CAN0_CHN16_CAN_ID                  (0x04C2)
#define     TP_DIAG_ID_REP_CAN0_CHN16_SFFFFC_TXFRM_HANDLE     (0xF020)
#define     TP_DIAG_ID_REP_CAN0_CHN16_FCF_TXFRM_HANDLE        (0xF021)
#define     TP_DIAG_ID_REP_CAN0_CHN16_NUM_TX_FRAMES           (0x0001)
/*For receive  server_16 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN16_CAN_ID                  (0x04CA)
#define     TP_DIAG_ID_REQ_CAN0_CHN16_SFFFFC_TXFRM_HANDLE     (0xF010)
#define     TP_DIAG_ID_REQ_CAN0_CHN16_NUM_RX_FRAMES           (0x0001)

/*CAN0-CHANNEL 17*/
/*For send  client -> server_17*/
#define     TP_DIAG_ID_REP_CAN0_CHN17_CAN_ID                  (0x04C3)
#define     TP_DIAG_ID_REP_CAN0_CHN17_SFFFFC_TXFRM_HANDLE     (0xF022)
#define     TP_DIAG_ID_REP_CAN0_CHN17_FCF_TXFRM_HANDLE        (0xF023)
#define     TP_DIAG_ID_REP_CAN0_CHN17_NUM_TX_FRAMES           (0x0001)
/*For receive  server_17 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN17_CAN_ID                  (0x04CB)
#define     TP_DIAG_ID_REQ_CAN0_CHN17_SFFFFC_TXFRM_HANDLE     (0xF011)
#define     TP_DIAG_ID_REQ_CAN0_CHN17_NUM_RX_FRAMES           (0x0001)

/*CAN0-CHANNEL 18*/
/*For send  client -> server_18*/
#define     TP_DIAG_ID_REP_CAN0_CHN18_CAN_ID                  (0x04C4)
#define     TP_DIAG_ID_REP_CAN0_CHN18_SFFFFC_TXFRM_HANDLE     (0xF024)
#define     TP_DIAG_ID_REP_CAN0_CHN18_FCF_TXFRM_HANDLE        (0xF025)
#define     TP_DIAG_ID_REP_CAN0_CHN18_NUM_TX_FRAMES           (0x0001)
/*For receive  server_18 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN18_CAN_ID                  (0x04CC)
#define     TP_DIAG_ID_REQ_CAN0_CHN18_SFFFFC_TXFRM_HANDLE     (0xF012)
#define     TP_DIAG_ID_REQ_CAN0_CHN18_NUM_RX_FRAMES           (0x0001)

/*CAN0-CHANNEL 19*/
/*For send  client -> server_19*/
#define     TP_DIAG_ID_REP_CAN0_CHN19_CAN_ID                  (0x04C5)
#define     TP_DIAG_ID_REP_CAN0_CHN19_SFFFFC_TXFRM_HANDLE     (0xF026)
#define     TP_DIAG_ID_REP_CAN0_CHN19_FCF_TXFRM_HANDLE        (0xF027)
#define     TP_DIAG_ID_REP_CAN0_CHN19_NUM_TX_FRAMES           (0x0001)
/*For receive  server_19 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN19_CAN_ID                  (0x04CD)
#define     TP_DIAG_ID_REQ_CAN0_CHN19_SFFFFC_TXFRM_HANDLE     (0xF013)
#define     TP_DIAG_ID_REQ_CAN0_CHN19_NUM_RX_FRAMES           (0x0001)

/*CAN0-CHANNEL 20*/
/*For send  client -> server_20*/
#define     TP_DIAG_ID_REP_CAN0_CHN20_CAN_ID                  (0x04C6)
#define     TP_DIAG_ID_REP_CAN0_CHN20_SFFFFC_TXFRM_HANDLE     (0xF028)
#define     TP_DIAG_ID_REP_CAN0_CHN20_FCF_TXFRM_HANDLE        (0xF029)
#define     TP_DIAG_ID_REP_CAN0_CHN20_NUM_TX_FRAMES           (0x0001)
/*For receive  server_20 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN20_CAN_ID                  (0x04CE)
#define     TP_DIAG_ID_REQ_CAN0_CHN20_SFFFFC_TXFRM_HANDLE     (0xF014)
#define     TP_DIAG_ID_REQ_CAN0_CHN20_NUM_RX_FRAMES           (0x0001)

/*CAN0-CHANNEL 21*/
/*For send  client -> server_21*/
#define     TP_DIAG_ID_REP_CAN0_CHN21_CAN_ID                  (0x04C7)
#define     TP_DIAG_ID_REP_CAN0_CHN21_SFFFFC_TXFRM_HANDLE     (0xF02A)
#define     TP_DIAG_ID_REP_CAN0_CHN21_FCF_TXFRM_HANDLE        (0xF02B)
#define     TP_DIAG_ID_REP_CAN0_CHN21_NUM_TX_FRAMES           (0x0001)
/*For receive  server_20 -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN21_CAN_ID                  (0x04CF)
#define     TP_DIAG_ID_REQ_CAN0_CHN21_SFFFFC_TXFRM_HANDLE     (0xF015)
#define     TP_DIAG_ID_REQ_CAN0_CHN21_NUM_RX_FRAMES           (0x0001)


/*CAN0-CHANNEL Functional address*/
/*For send  client -> all server*/
#define     TP_DIAG_ID_REP_CAN0_CHN22_CAN_ID                  (0x04DF)
#define     TP_DIAG_ID_REP_CAN0_CHN22_SFFFFC_TXFRM_HANDLE     (0xF02C)
#define     TP_DIAG_ID_REP_CAN0_CHN22_FCF_TXFRM_HANDLE        (0xF02D)
#define     TP_DIAG_ID_REP_CAN0_CHN22_NUM_TX_FRAMES           (0x0001)
/*For receive  server -> client*/
#define     TP_DIAG_ID_REQ_CAN0_CHN22_CAN_ID                  (0x04DF)
#define     TP_DIAG_ID_REQ_CAN0_CHN22_SFFFFC_TXFRM_HANDLE     (0xF016)
#define     TP_DIAG_ID_REQ_CAN0_CHN22_NUM_RX_FRAMES           (0x0001)
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
