/*!*******************************************************************
* @file can_dll_par.h
* @brief Dispatch Lower Layer Frame Handles for LYWW20 Application
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
* This file contains the Dispatch Layer transmit and receive frame
* handle definitions needed for managing CAN frame transmission and
* reception in the Garmin OSEK CAN Stack. This file is generated
* using a separate Network "Gen" tool based on the CAN database
* supplied by the OEM along with user configuration inputs.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack_dll_cfg
* @{
*
*********************************************************************/

#ifndef _CAN_DLL_PAR_H
#define _CAN_DLL_PAR_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*------------------------------------------------------
INTERACTION LAYER FRAME DEFINITIONS
------------------------------------------------------*/

/*------------------------------------------------------
IL CAN0 Transmitted Frame Application Handles
------------------------------------------------------*/

#define     IL_CAN0_TX_DIAG_RELATED_TXFRM_HANDLE                (0x0000)
#define     IL_CAN0_TX_NM_AND_LP_BK_TXFRM_HANDLE                (0x0001)
#define     IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_HANDLE            (0x0002)
#define     IL_CAN0_TX1_SYS_INFO_TXFRM_HANDLE                   (0x0003)
#define     IL_CAN0_TX2_REQ_SUPPORT_TXFRM_HANDLE                (0x0004)
#define     IL_CAN0_TX3_HEATER_LEVEL_TXFRM_HANDLE               (0x0005)
#define     IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_HANDLE           (0x0006)
#define     IL_CAN0_TX5_CLK_DATA_RES_TXFRM_HANDLE               (0x0007)
#define     IL_CAN0_TX6_DEV_CTRL_TXFRM_HANDLE                   (0x0008)
#define     IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_HANDLE              (0x0009)


/*------------------------------------------------------
IL CAN0 Received Frame Application Handles
------------------------------------------------------*/

#define     IL_CAN0_RX_DAIG_SEG1_RXFRM_HANDLE                   (0x0000)
#define     IL_CAN0_RX_DAIG_SEG2_RXFRM_HANDLE                   (0x0001)
#define     IL_CAN0_RX_DAIG_SEG3_RXFRM_HANDLE                   (0x0002)
#define     IL_CAN0_RX_DAIG_SEG4_RXFRM_HANDLE                   (0x0003)
#define     IL_CAN0_RX_DAIG_SEG5_YDT_RXFRM_HANDLE               (0x0004)
#define     IL_CAN0_RX_DAIG_SEG6_YDT_RXFRM_HANDLE               (0x0005)
#define     IL_CAN0_RX_DAIG_SEG7_YDT_RXFRM_HANDLE               (0x0006)
#define     IL_CAN0_RX_NM_AND_LP_BK_RXFRM_HANDLE                (0x0007)
#define     IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_HANDLE             (0x0008)
#define     IL_CAN0_RX1_ECU_COM_DATA_RXFRM_HANDLE               (0x0009)
#define     IL_CAN0_RX2_RES_SUPPORT_RXFRM_HANDLE                (0x000A)
#define     IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_HANDLE              (0x000B)
#define     IL_CAN0_RX4_RES_MT_FUNC_CNT_RXFRM_HANDLE            (0x000C)
#define     IL_CAN0_RX5_VEHICLE_INFO_RXFRM_HANDLE               (0x000D)
#define     IL_CAN0_RX6_FUNCSW_STAT_RXFRM_HANDLE                (0x000E)
#define     IL_CAN0_RX7_FUEL_RATE_RXFRM_HANDLE                  (0x000F)
#define     IL_CAN0_RX8_ODO_TRIP_RXFRM_HANDLE                   (0x0010)
#define     IL_CAN0_RX9_RES_RPRGRM_INFO_RXFRM_HANDLE            (0x0011)
#define     IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_HANDLE             (0x0012)
#define     IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_HANDLE             (0x0013)
#define     IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_HANDLE             (0x0014)
#define     IL_CAN0_RXD_MAINT_TRIP_RXFRM_HANDLE                 (0x0015)
#define     IL_CAN0_RXE_HEATER_STAT_RXFRM_HANDLE                (0x0016)
#define     IL_CAN0_RXF_FACT_INSP_NS_RXFRM_HANDLE               (0x0017)
#define     IL_CAN0_RXF_FACT_INSP2_GA_RXFRM_HANDLE              (0x0018)
#define     IL_CAN0_RXG_ECU_INDCT_STAT1_RXFRM_HANDLE            (0x0019)

#ifdef __cplusplus
}
#endif

#endif /* CAN_DLL_PAR_H */

/*!*******************************************************************
*
* @}
*
*********************************************************************/