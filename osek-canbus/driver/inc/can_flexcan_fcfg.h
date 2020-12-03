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
Message Buffer Receive IDs
----------------------------------------------------------*/
#define RX_MB_DEF_MSK                   0x3FFFFFFF
#define RX_MB_DEF_MSK_BIT(x)            ( ~( 1 << ( CAN_ID_STD_SHIFT + (x) ) ) )

#define RX0_ECU_INDCT_STAT              0x209
#define CAN0_RX0_ECU_INDCT_STAT_STD     FLEXCAN_ID_STD(RX0_ECU_INDCT_STAT)

#define RX1_ECU_COM_DATA                0x350
#define CAN0_RX1_ECU_COM_DATA_STD       FLEXCAN_ID_STD(RX1_ECU_COM_DATA)

#define RX2_RES_SUPPORT                 0x582
#define CAN0_RX2_RES_SUPPORT_STD        FLEXCAN_ID_STD(RX2_RES_SUPPORT)

#define RX3_BRGTHNSS_CTRL               0x583
#define CAN0_RX3_BRGTHNSS_CTRL_STD      FLEXCAN_ID_STD(RX3_BRGTHNSS_CTRL)

#define RX4_RES_MT_FUNC_CNT             0x585
#define CAN0_RX4_RES_MT_FUNC_CNT_STD    FLEXCAN_ID_STD(RX4_RES_MT_FUNC_CNT)

#define RX5_VEHICLE_INFO                0x5A0
#define CAN0_RX5_VEHICLE_INFO_STD       FLEXCAN_ID_STD(RX5_VEHICLE_INFO)

#define RX6_FUNCSW_STAT                 0x5A1
#define CAN0_RX6_FUNCSW_STAT_STD        FLEXCAN_ID_STD(RX6_FUNCSW_STAT)

#define RX7_FUEL_RATE                   0x5A6
#define CAN0_RX7_FUEL_RATE_STD          FLEXCAN_ID_STD(RX7_FUEL_RATE)

#define RX8_ODO_TRIP                    0x5A7
#define CAN0_RX8_ODO_TRIP_STD           FLEXCAN_ID_STD(RX8_ODO_TRIP)

#define RX9_RES_RPRGRM_INFO             0x5AF
#define CAN0_RX9_RES_RPRGRM_INFO_STD    FLEXCAN_ID_STD(RX9_RES_RPRGRM_INFO)

#define RXA_VEHICLE_INFO_2              0x5BA
#define CAN0_RXA_VEHICLE_INFO_2_STD     FLEXCAN_ID_STD(RXA_VEHICLE_INFO_2)

#define RXB_VEHICLE_INFO_3              0x5BB
#define CAN0_RXB_VEHICLE_INFO_3_STD     FLEXCAN_ID_STD(RXB_VEHICLE_INFO_3)

#define RXC_VEHICLE_INFO_4              0x5BC
#define CAN0_RXC_VEHICLE_INFO_4_STD     FLEXCAN_ID_STD(RXC_VEHICLE_INFO_4)

#define RXD_MAINT_TRIP                  0x5BD
#define CAN0_RXD_MAINT_TRIP_STD         FLEXCAN_ID_STD(RXD_MAINT_TRIP)

#define RXE_HEATER_STAT                 0x5BE
#define CAN0_RXE_HEATER_STAT_STD        FLEXCAN_ID_STD(RXE_HEATER_STAT)

#define RXF_FACT_INSP_NS                0x5D5
#define CAN0_RXF_FACT_INSP_NS_STD       FLEXCAN_ID_STD(RXF_FACT_INSP_NS)

#define RXF_FACT_INSP2_GA               0x691
#define CAN0_RXF_FACT_INSP2_GA_STD      FLEXCAN_ID_STD(RXF_FACT_INSP2_GA)

#define RX_NM_AND_LP_BK                 0x226
#define CAN0_RX_NM_AND_LP_BK_STD        FLEXCAN_ID_STD(RX_NM_AND_LP_BK)

#define RX_DAIG_SEG1_MSK0               (RX_MB_DEF_MSK     & RX_MB_DEF_MSK_BIT(0) )
#define RX_DAIG_SEG1_MSK1               (RX_DAIG_SEG1_MSK0 & RX_MB_DEF_MSK_BIT(1) )
#define RX_DAIG_SEG1_MSK                (RX_DAIG_SEG1_MSK1 & RX_MB_DEF_MSK_BIT(2) )
#define RX_DAIG_SEG1                    0x4C8
#define CAN0_RX_DAIG_SEG1_STD           FLEXCAN_ID_STD(RX_DAIG_SEG1)

#define RX_DAIG_SEG2_MSK0               (RX_MB_DEF_MSK     & RX_MB_DEF_MSK_BIT(0) )
#define RX_DAIG_SEG2_MSK1               (RX_DAIG_SEG2_MSK0 & RX_MB_DEF_MSK_BIT(1) )
#define RX_DAIG_SEG2_MSK                (RX_DAIG_SEG2_MSK1 & RX_MB_DEF_MSK_BIT(2) )
#define RX_DAIG_SEG2                    0x4E8
#define CAN0_RX_DAIG_SEG2_STD           FLEXCAN_ID_STD(RX_DAIG_SEG2)

#define RX_DAIG_SEG3_MSK1               (RX_MB_DEF_MSK     & RX_MB_DEF_MSK_BIT(1) )
#define RX_DAIG_SEG3_MSK                (RX_DAIG_SEG3_MSK1 & RX_MB_DEF_MSK_BIT(2) )
#define RX_DAIG_SEG3                    0x4D9
#define CAN0_RX_DAIG_SEG3_STD           FLEXCAN_ID_STD(RX_DAIG_SEG3)

#define RX_DAIG_SEG4_MSK1               (RX_MB_DEF_MSK     & RX_MB_DEF_MSK_BIT(1) )
#define RX_DAIG_SEG4_MSK                (RX_DAIG_SEG4_MSK1 & RX_MB_DEF_MSK_BIT(2) )
#define RX_DAIG_SEG4                    0x4DA
#define CAN0_RX_DAIG_SEG4_STD           FLEXCAN_ID_STD(RX_DAIG_SEG4)

#define RX_DAIG_SEG5_MSK0               (RX_MB_DEF_MSK     & RX_MB_DEF_MSK_BIT(0) )
#define RX_DAIG_SEG5_MSK1               (RX_DAIG_SEG5_MSK0 & RX_MB_DEF_MSK_BIT(1) )
#define RX_DAIG_SEG5_MSK2               (RX_DAIG_SEG5_MSK1 & RX_MB_DEF_MSK_BIT(2) )
#define RX_DAIG_SEG5_MSK                (RX_DAIG_SEG5_MSK2 & RX_MB_DEF_MSK_BIT(3) )
#define RX_DAIG_SEG5_YDT                0x7C0
#define CAN0_RX_DAIG_SEG5_YDT_STD       FLEXCAN_ID_STD(RX_DAIG_SEG5_YDT)

#define RX_DAIG_SEG6_MSK0               (RX_MB_DEF_MSK     & RX_MB_DEF_MSK_BIT(0) )
#define RX_DAIG_SEG6_MSK1               (RX_DAIG_SEG6_MSK0 & RX_MB_DEF_MSK_BIT(1) )
#define RX_DAIG_SEG6_MSK2               (RX_DAIG_SEG6_MSK1 & RX_MB_DEF_MSK_BIT(2) )
#define RX_DAIG_SEG6_MSK                (RX_DAIG_SEG6_MSK2 & RX_MB_DEF_MSK_BIT(3) )
#define RX_DAIG_SEG6_YDT                0x7D0
#define CAN0_RX_DAIG_SEG6_YDT_STD       FLEXCAN_ID_STD(RX_DAIG_SEG6_YDT)

#define RX_DAIG_SEG7_MSK0               (RX_MB_DEF_MSK     & RX_MB_DEF_MSK_BIT(0) )
#define RX_DAIG_SEG7_MSK1               (RX_DAIG_SEG7_MSK0 & RX_MB_DEF_MSK_BIT(1) )
#define RX_DAIG_SEG7_MSK2               (RX_DAIG_SEG7_MSK1 & RX_MB_DEF_MSK_BIT(2) )
#define RX_DAIG_SEG7_MSK                (RX_DAIG_SEG7_MSK2 & RX_MB_DEF_MSK_BIT(3) )
#define RX_DAIG_SEG7_YDT                0x7E0
#define CAN0_RX_DAIG_SEG7_YDT_STD       FLEXCAN_ID_STD(RX_DAIG_SEG7_YDT)

/*----------------------------------------------------------
Message Buffer Transmit IDs
----------------------------------------------------------*/
#define TX0_REQ_MT_FUNC_CNT             0x584
#define CAN0_TX0_REQ_MT_FUNC_CNT_STD    FLEXCAN_ID_STD(TX0_REQ_MT_FUNC_CNT)

#define TX_DIAG_RELATED                 0x4D1
#define CAN0_TX_DIAG_RELATED_STD        FLEXCAN_ID_STD(TX_DIAG_RELATED)

#define TX_NM_AND_LP_BK                 0x226
#define CAN0_TX_NM_AND_LP_BK_STD        FLEXCAN_ID_STD(TX_NM_AND_LP_BK)

#ifdef __cplusplus
}
#endif

#endif
