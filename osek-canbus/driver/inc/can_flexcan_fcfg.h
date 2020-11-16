/*!*******************************************************************
* @file can_flexcan_fcfg.h
* @brief RT1170 FlexCAN Filter Configuration File
*
* This file contains the receive message filter configuration
* parameters for the RT1170 FlexCAN controller. The filter
* configuration is defined in terms of individual Message Buffer
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_drv
* @{
*
*********************************************************************/
#ifndef _CAN_CCAN_FCFG_H
#define _CAN_CCAN_FCFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/
#define FLEXCAN_WAIT_TIMEOUT (1000U)//!<Define to 1000 means keep waiting 1000 times until the flag is assert/deassert.

/*------------------------------------------------------
FlexCAN Frame ID helper macro.
------------------------------------------------------*/
#define FLEXCAN_ID_STD(id)              (((uint32_t)(((uint32_t)(id)) << CAN_ID_STD_SHIFT)) & CAN_ID_STD_MASK) //!<Standard Frame ID helper macro.
#define FLEXCAN_ID_EXT(id)              (((uint32_t)(((uint32_t)(id)) << CAN_ID_EXT_SHIFT)) & (CAN_ID_EXT_MASK | CAN_ID_STD_MASK)) //!<Extend Frame ID helper macro.

/*------------------------------------------------------
FlexCAN Rx Message Buffer Mask helper macro.
------------------------------------------------------*/
#define FLEXCAN_RX_MB_STD_MASK(id, rtr, ide)    (((uint32_t)((uint32_t)(rtr) << 31) | (uint32_t)((uint32_t)(ide) << 30)) | FLEXCAN_ID_STD(id)) //!<Standard Rx Message Buffer Mask helper macro.
#define FLEXCAN_RX_MB_EXT_MASK(id, rtr, ide)    (((uint32_t)((uint32_t)(rtr) << 31) | (uint32_t)((uint32_t)(ide) << 30)) | FLEXCAN_ID_EXT(id)) //!<Extend   Rx Message Buffer Mask helper macro.

/*------------------------------------------------------
FlexCAN Rx FIFO Mask helper macro.
------------------------------------------------------*/
#define FLEXCAN_RX_FIFO_STD_MASK_TYPE_A(id, rtr, ide)           (((uint32_t)((uint32_t)(rtr) << 31) | (uint32_t)((uint32_t)(ide) << 30)) | (FLEXCAN_ID_STD(id) << 1))      //!<Standard Rx FIFO Mask helper macro Type A helper macro.
#define FLEXCAN_RX_FIFO_STD_MASK_TYPE_B_HIGH(id, rtr, ide)      (((uint32_t)((uint32_t)(rtr) << 31) | (uint32_t)((uint32_t)(ide) << 30)) | (((uint32_t)(id)&0x7FF) << 19)) //!<Standard Rx FIFO Mask helper macro Type B upper part helper macro.
#define FLEXCAN_RX_FIFO_STD_MASK_TYPE_B_LOW(id, rtr, ide)       (((uint32_t)((uint32_t)(rtr) << 15) | (uint32_t)((uint32_t)(ide) << 14)) | (((uint32_t)(id)&0x7FF) << 3))  //!<Standard Rx FIFO Mask helper macro Type B lower part helper macro.
#define FLEXCAN_RX_FIFO_STD_MASK_TYPE_C_HIGH(id)                (((uint32_t)(id)&0x7F8) << 21) //!<Standard Rx FIFO Mask helper macro Type C upper part helper macro.
#define FLEXCAN_RX_FIFO_STD_MASK_TYPE_C_MID_HIGH(id)            (((uint32_t)(id)&0x7F8) << 13) //!<Standard Rx FIFO Mask helper macro Type C mid-upper part helper macro.
#define FLEXCAN_RX_FIFO_STD_MASK_TYPE_C_MID_LOW(id)             (((uint32_t)(id)&0x7F8) << 5)  //!<Standard Rx FIFO Mask helper macro Type C mid-lower part helper macro.
#define FLEXCAN_RX_FIFO_STD_MASK_TYPE_C_LOW(id)                 (((uint32_t)(id)&0x7F8) >> 3)  //!<Standard Rx FIFO Mask helper macro Type C lower part helper macro.
#define FLEXCAN_RX_FIFO_EXT_MASK_TYPE_A(id, rtr, ide)           (((uint32_t)((uint32_t)(rtr) << 31) | (uint32_t)((uint32_t)(ide) << 30)) | (FLEXCAN_ID_EXT(id) << 1)) //!<Extend Rx FIFO Mask helper macro Type A helper macro.
#define FLEXCAN_RX_FIFO_EXT_MASK_TYPE_B_HIGH(id, rtr, ide)      (((uint32_t)((uint32_t)(rtr) << 31) | (uint32_t)((uint32_t)(ide) << 30)) | ((FLEXCAN_ID_EXT(id) & 0x1FFF8000) << 1)) //!<Extend Rx FIFO Mask helper macro Type B upper part helper macro.
#define FLEXCAN_RX_FIFO_EXT_MASK_TYPE_B_LOW(id, rtr, ide)       (((uint32_t)((uint32_t)(rtr) << 15) | (uint32_t)((uint32_t)(ide) << 14)) | ((FLEXCAN_ID_EXT(id) & 0x1FFF8000) >> 15))//!<Extend Rx FIFO Mask helper macro Type B lower part helper macro.
#define FLEXCAN_RX_FIFO_EXT_MASK_TYPE_C_HIGH(id)                ((FLEXCAN_ID_EXT(id) & 0x1FE00000) << 3) //!<Extend Rx FIFO Mask helper macro Type C upper part helper macro.
#define FLEXCAN_RX_FIFO_EXT_MASK_TYPE_C_MID_HIGH(id)            ((FLEXCAN_ID_EXT(id) & 0x1FE00000) >> 5) //!<Extend Rx FIFO Mask helper macro Type C mid-upper part helper macro.
#define FLEXCAN_RX_FIFO_EXT_MASK_TYPE_C_MID_LOW(id)             ((FLEXCAN_ID_EXT(id) & 0x1FE00000) >> 13)//!<Extend Rx FIFO Mask helper macro Type C mid-lower part helper macro.
#define FLEXCAN_RX_FIFO_EXT_MASK_TYPE_C_LOW(id)                 ((FLEXCAN_ID_EXT(id) & 0x1FE00000) >> 21)//!<Extend Rx FIFO Mask helper macro Type C lower part helper macro.

/*------------------------------------------------------
FlexCAN Rx FIFO Filter helper macro.
------------------------------------------------------*/
#define FLEXCAN_RX_FIFO_STD_FILTER_TYPE_A(id, rtr, ide)         FLEXCAN_RX_FIFO_STD_MASK_TYPE_A(id, rtr, ide)       //!<Standard Rx FIFO Filter helper macro Type A helper macro.
#define FLEXCAN_RX_FIFO_STD_FILTER_TYPE_B_HIGH(id, rtr, ide)    FLEXCAN_RX_FIFO_STD_MASK_TYPE_B_HIGH(id, rtr, ide)  //!<Standard Rx FIFO Filter helper macro Type B upper part helper macro.
#define FLEXCAN_RX_FIFO_STD_FILTER_TYPE_B_LOW(id, rtr, ide)     FLEXCAN_RX_FIFO_STD_MASK_TYPE_B_LOW(id, rtr, ide)   //!<Standard Rx FIFO Filter helper macro Type B lower part helper macro.
#define FLEXCAN_RX_FIFO_STD_FILTER_TYPE_C_HIGH(id)              FLEXCAN_RX_FIFO_STD_MASK_TYPE_C_HIGH(id)     //!<Standard Rx FIFO Filter helper macro Type C upper part helper macro.
#define FLEXCAN_RX_FIFO_STD_FILTER_TYPE_C_MID_HIGH(id)          FLEXCAN_RX_FIFO_STD_MASK_TYPE_C_MID_HIGH(id) //!<Standard Rx FIFO Filter helper macro Type C mid-upper part helper macro.
#define FLEXCAN_RX_FIFO_STD_FILTER_TYPE_C_MID_LOW(id)           FLEXCAN_RX_FIFO_STD_MASK_TYPE_C_MID_LOW(id)  //!<Standard Rx FIFO Filter helper macro Type C mid-lower part helper macro.
#define FLEXCAN_RX_FIFO_STD_FILTER_TYPE_C_LOW(id)               FLEXCAN_RX_FIFO_STD_MASK_TYPE_C_LOW(id)      //!<Standard Rx FIFO Filter helper macro Type C lower part helper macro.
#define FLEXCAN_RX_FIFO_EXT_FILTER_TYPE_A(id, rtr, ide)         FLEXCAN_RX_FIFO_EXT_MASK_TYPE_A(id, rtr, ide)//!<Extend Rx FIFO Filter helper macro Type A helper macro.
#define FLEXCAN_RX_FIFO_EXT_FILTER_TYPE_B_HIGH(id, rtr, ide)    FLEXCAN_RX_FIFO_EXT_MASK_TYPE_B_HIGH(id, rtr, ide) //!<Extend Rx FIFO Filter helper macro Type B upper part helper macro.
#define FLEXCAN_RX_FIFO_EXT_FILTER_TYPE_B_LOW(id, rtr, ide)     FLEXCAN_RX_FIFO_EXT_MASK_TYPE_B_LOW(id, rtr, ide)  //!<Extend Rx FIFO Filter helper macro Type B lower part helper macro.
#define FLEXCAN_RX_FIFO_EXT_FILTER_TYPE_C_HIGH(id)              FLEXCAN_RX_FIFO_EXT_MASK_TYPE_C_HIGH(id)           //!<Extend Rx FIFO Filter helper macro Type C upper part helper macro.
#define FLEXCAN_RX_FIFO_EXT_FILTER_TYPE_C_MID_HIGH(id)          FLEXCAN_RX_FIFO_EXT_MASK_TYPE_C_MID_HIGH(id)       //!<Extend Rx FIFO Filter helper macro Type C mid-upper part helper macro.
#define FLEXCAN_RX_FIFO_EXT_FILTER_TYPE_C_MID_LOW(id)           FLEXCAN_RX_FIFO_EXT_MASK_TYPE_C_MID_LOW(id)        //!<Extend Rx FIFO Filter helper macro Type C mid-lower part helper macro.
#define FLEXCAN_RX_FIFO_EXT_FILTER_TYPE_C_LOW(id)               FLEXCAN_RX_FIFO_EXT_MASK_TYPE_C_LOW(id)            //!<Extend Rx FIFO Filter helper macro Type C lower part helper macro.

/*----------------------------------------------------------
Message Buffer Receive ID
----------------------------------------------------------*/
#define ID0_FUNCSW_STATUS_CAN0_ID       0x5A1
#define CAN0_RX0_ID_STANDARD            FLEXCAN_ID_STD(ID0_FUNCSW_STATUS_CAN0_ID)

#define ID1_VEHICLE_INFO_CAN0_ID        0x5AA
#define CAN0_RX1_ID_STANDARD            FLEXCAN_ID_STD(ID1_VEHICLE_INFO_CAN0_ID)

#define ID2_FUNC_CNTRL_CAN0_ID          0x5AB
#define CAN0_RX2_ID_STANDARD            FLEXCAN_ID_STD(ID2_FUNC_CNTRL_CAN0_ID)

#define ID3_CLK_DATE_REQ_CAN0_ID        0x5AC
#define CAN0_RX3_ID_STANDARD            FLEXCAN_ID_STD(ID3_CLK_DATE_REQ_CAN0_ID)

#define ID4_UNIT_INFO_CAN0_ID           0x5AD
#define CAN0_RX4_ID_STANDARD            FLEXCAN_ID_STD(ID4_UNIT_INFO_CAN0_ID)

#define ID5_REQ_SCRN_TRNSTN_CAN0_ID     0x5AE
#define CAN0_RX5_ID_STANDARD            FLEXCAN_ID_STD(ID5_REQ_SCRN_TRNSTN_CAN0_ID)

#define ID6_RES_REPRGRM_INFO_CAN0_ID    0x5AF
#define CAN0_RX6_ID_STANDARD            FLEXCAN_ID_STD(ID6_RES_REPRGRM_INFO_CAN0_ID)

#define ID7_RES_SCRN_TRNSTN2_CAN0_ID    0x5B1
#define CAN0_RX7_ID_STANDARD            FLEXCAN_ID_STD(ID7_RES_SCRN_TRNSTN2_CAN0_ID)

#define NM_LOOP_BACK_RX_CAN_ID          0x226
#define CAN0_RX8_ID_STANDARD            FLEXCAN_ID_STD(NM_LOOP_BACK_RX_CAN_ID)

#define TP_DIAG_ID_REQ_LINKCARD_CAN_ID  0x763
#define CAN0_RX9_ID_STANDARD            FLEXCAN_ID_STD(TP_DIAG_ID_REQ_LINKCARD_CAN_ID)

#define TP_DIAG_ID_REQ_FUNC_CAN_ID      0x7FF
#define CAN0_RX10_ID_STANDARD           FLEXCAN_ID_STD(TP_DIAG_ID_REQ_FUNC_CAN_ID)

#define TP_CAN0_ID_LINKCARD_FCF_CAN_ID  0x2C5
#define CAN0_RX11_ID_STANDARD           FLEXCAN_ID_STD(TP_CAN0_ID_LINKCARD_FCF_CAN_ID)

#define FT_REQ_LINKCARD_CAN_ID          0x691
#define CAN0_RX12_ID_STANDARD           FLEXCAN_ID_STD(FT_REQ_LINKCARD_CAN_ID)

/*----------------------------------------------------------
Message Buffer Transmit ID
----------------------------------------------------------*/
#define ID0_FUNC_INFO_CAN0_ID           0x5B2
#define CAN0_TX0_ID_STANDARD            FLEXCAN_ID_STD(ID0_FUNC_INFO_CAN0_ID)

#define ID1_REQ_REPRGRM_INFO_CAN0_ID    0x5B3
#define CAN0_TX1_ID_STANDARD            FLEXCAN_ID_STD(ID1_REQ_REPRGRM_INFO_CAN0_ID)

#define ID2_RES_SCRN_TRNSTN_CAN0_ID     0x5B4
#define CAN0_TX2_ID_STANDARD            FLEXCAN_ID_STD(ID2_RES_SCRN_TRNSTN_CAN0_ID)

#define ID3_SYS_INFO_CAN0_ID            0x5B5
#define CAN0_TX3_ID_STANDARD            FLEXCAN_ID_STD(ID3_SYS_INFO_CAN0_ID)

#define ID4_PHONE_INFO_CAN0_ID          0x5B6
#define CAN0_TX4_ID_STANDARD            FLEXCAN_ID_STD(ID4_PHONE_INFO_CAN0_ID)

#define ID5_INDICTR_STATUS_CAN0_ID      0x5B7
#define CAN0_TX5_ID_STANDARD            FLEXCAN_ID_STD(ID5_INDICTR_STATUS_CAN0_ID)

#define ID6_CLK_DATE_RES_CAN0_ID        0x5B8
#define CAN0_TX6_ID_STANDARD            FLEXCAN_ID_STD(ID6_CLK_DATE_RES_CAN0_ID)

#define ID7_REQ_SCRN_TRNSTN2_CAN0_ID    0x5B9
#define CAN0_TX7_ID_STANDARD            FLEXCAN_ID_STD(ID7_REQ_SCRN_TRNSTN2_CAN0_ID)

#define NM_LOOP_BACK_TX_CAN_ID          0x226
#define CAN0_TX8_ID_STANDARD            FLEXCAN_ID_STD(NM_LOOP_BACK_TX_CAN_ID)

#define TP_DIAG_ID_REP_CAN_ID           0x663
#define CAN0_TX9_ID_STANDARD            FLEXCAN_ID_STD(TP_DIAG_ID_REP_CAN_ID)

#define TP_CAN0_ID_SFFFFCF_CAN_ID       0x305
#define CAN0_TX10_ID_STANDARD           FLEXCAN_ID_STD(TP_CAN0_ID_SFFFFCF_CAN_ID)

#define FT_RESP_LINKCARD_CAN_ID         0x690
#define CAN0_TX11_ID_STANDARD           FLEXCAN_ID_STD(FT_RESP_LINKCARD_CAN_ID)

#ifdef __cplusplus
}
#endif

#endif
