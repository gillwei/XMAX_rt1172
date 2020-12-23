/*!*******************************************************************
* @file can_il_par.c
* @brief Interaction Layer LYWW20 Application Configuration
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
* This file contains the signal definitions and data structures
* needed by the Interaction Layer to transact on a CAN bus that
* supports the Garmin OSEK CAN Stack. This file is generated using
* a separate Network "Gen" tool based on the CAN database supplied
* by the OEM along with user configuration inputs.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @defgroup can_stack_il_cfg Interaction Layer LYWW20 Application Configuration
* @ingroup can_stack_il
* @{
*
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "can_defs.h"
#include "can_cfg.h"
#include "can_dll.h"
#include "can_dll_par.h"
#include "can_dll_prv_par.h"
#include "can_il.h"
#include "can_il_prv.h"
#include "can_il_par.h"
#include "can_il_prv_par.h"
#include "can_nim_cfg.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*------------------------------------------------------
CAN0 Periodic TX Frame Intervals (milliseconds)
------------------------------------------------------*/
#define     IL_CAN0_TX1_SYS_INFO_TXFRM_PER_MS                   (100)
#define     IL_CAN0_TX6_DEV_CTRL_TXFRM_PER_MS                   (100)


/*------------------------------------------------------
CAN0 Periodic TX Frame Initial Start Delays
(milliseconds). This distributes the timing of periodic
messages so that fewer messages are transmitted
simultaneously
------------------------------------------------------*/
#define     IL_CAN0_TX1_SYS_INFO_TXFRM_START_DELAY_MS           (0)
#define     IL_CAN0_TX6_DEV_CTRL_TXFRM_START_DELAY_MS           (0)


/*------------------------------------------------------
CAN0 Transmitted Frame Minimum Delay Between Frames
(milliseconds). This prevents back to back frame
transmissions
------------------------------------------------------*/
#define     IL_CAN0_TX_DIAG_RELATED_TXFRM_MIN_DELAY_MS          (10)
#define     IL_CAN0_TX_NM_AND_LP_BK_TXFRM_MIN_DELAY_MS          (10)
#define     IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_MIN_DELAY_MS      (10)
#define     IL_CAN0_TX1_SYS_INFO_TXFRM_MIN_DELAY_MS             (10)
#define     IL_CAN0_TX2_REQ_SUPPORT_TXFRM_MIN_DELAY_MS          (10)
#define     IL_CAN0_TX3_HEATER_LEVEL_TXFRM_MIN_DELAY_MS         (10)
#define     IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_MIN_DELAY_MS     (10)
#define     IL_CAN0_TX5_CLK_DATA_RES_TXFRM_MIN_DELAY_MS         (10)
#define     IL_CAN0_TX6_DEV_CTRL_TXFRM_MIN_DELAY_MS             (10)
#define     IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_MIN_DELAY_MS        (10)




/*------------------------------------------------------
CAN0 Periodic TX Frame Timeout (milliseconds)
------------------------------------------------------*/
#define     IL_CAN0_TX1_SYS_INFO_TXFRM_TIMEOUTTX_MS             (100)
#define     IL_CAN0_TX6_DEV_CTRL_TXFRM_TIMEOUTTX_MS             (100)


/*------------------------------------------------------
CAN0 Periodic RX Frame Period (milliseconds)
------------------------------------------------------*/
#define     IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_PER_MS             (10)
#define     IL_CAN0_RX1_ECU_COM_DATA_RXFRM_PER_MS               (100)
#define     IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_PER_MS              (50)
#define     IL_CAN0_RX5_VEHICLE_INFO_RXFRM_PER_MS               (100)
#define     IL_CAN0_RX6_FUNCSW_STAT_RXFRM_PER_MS                (10)
#define     IL_CAN0_RX7_FUEL_RATE_RXFRM_PER_MS                  (100)
#define     IL_CAN0_RX8_ODO_TRIP_RXFRM_PER_MS                   (100)
#define     IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_PER_MS             (100)
#define     IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_PER_MS             (100)
#define     IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_PER_MS             (100)
#define     IL_CAN0_RXD_MAINT_TRIP_RXFRM_PER_MS                 (100)
#define     IL_CAN0_RXE_HEATER_STAT_RXFRM_PER_MS                (100)


/*------------------------------------------------------
CAN0 Periodic RX Frame Timeout1 (milliseconds)
------------------------------------------------------*/
#define     IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_TIMEOUT1_MS        (20)
#define     IL_CAN0_RX1_ECU_COM_DATA_RXFRM_TIMEOUT1_MS          (200)
#define     IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_TIMEOUT1_MS         (100)
#define     IL_CAN0_RX5_VEHICLE_INFO_RXFRM_TIMEOUT1_MS          (200)
#define     IL_CAN0_RX6_FUNCSW_STAT_RXFRM_TIMEOUT1_MS           (20)
#define     IL_CAN0_RX7_FUEL_RATE_RXFRM_TIMEOUT1_MS             (200)
#define     IL_CAN0_RX8_ODO_TRIP_RXFRM_TIMEOUT1_MS              (200)
#define     IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_TIMEOUT1_MS        (200)
#define     IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_TIMEOUT1_MS        (200)
#define     IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_TIMEOUT1_MS        (200)
#define     IL_CAN0_RXD_MAINT_TRIP_RXFRM_TIMEOUT1_MS            (200)
#define     IL_CAN0_RXE_HEATER_STAT_RXFRM_TIMEOUT1_MS           (200)


/*------------------------------------------------------
CAN0 Periodic RX Frame TimeoutErr1 recovery (milliseconds)
------------------------------------------------------*/
#define     IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_TERR1_RCVRY_MS     (10)
#define     IL_CAN0_RX1_ECU_COM_DATA_RXFRM_TERR1_RCVRY_MS       (100)
#define     IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_TERR1_RCVRY_MS      (50)
#define     IL_CAN0_RX5_VEHICLE_INFO_RXFRM_TERR1_RCVRY_MS       (100)
#define     IL_CAN0_RX6_FUNCSW_STAT_RXFRM_TERR1_RCVRY_MS        (10)
#define     IL_CAN0_RX7_FUEL_RATE_RXFRM_TERR1_RCVRY_MS          (100)
#define     IL_CAN0_RX8_ODO_TRIP_RXFRM_TERR1_RCVRY_MS           (100)
#define     IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_TERR1_RCVRY_MS     (100)
#define     IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_TERR1_RCVRY_MS     (100)
#define     IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_TERR1_RCVRY_MS     (100)
#define     IL_CAN0_RXD_MAINT_TRIP_RXFRM_TERR1_RCVRY_MS         (100)
#define     IL_CAN0_RXE_HEATER_STAT_RXFRM_TERR1_RCVRY_MS        (100)


/*------------------------------------------------------
CAN0 Periodic RX Frame Timeout2 (milliseconds)
------------------------------------------------------*/
#define     IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_TIMEOUT2_MS        (0)
#define     IL_CAN0_RX1_ECU_COM_DATA_RXFRM_TIMEOUT2_MS          (0)
#define     IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_TIMEOUT2_MS         (0)
#define     IL_CAN0_RX5_VEHICLE_INFO_RXFRM_TIMEOUT2_MS          (0)
#define     IL_CAN0_RX6_FUNCSW_STAT_RXFRM_TIMEOUT2_MS           (1000)
#define     IL_CAN0_RX7_FUEL_RATE_RXFRM_TIMEOUT2_MS             (0)
#define     IL_CAN0_RX8_ODO_TRIP_RXFRM_TIMEOUT2_MS              (0)
#define     IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_TIMEOUT2_MS        (0)
#define     IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_TIMEOUT2_MS        (0)
#define     IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_TIMEOUT2_MS        (0)
#define     IL_CAN0_RXD_MAINT_TRIP_RXFRM_TIMEOUT2_MS            (0)
#define     IL_CAN0_RXE_HEATER_STAT_RXFRM_TIMEOUT2_MS           (0)


/*------------------------------------------------------
CAN0 Periodic RX Frame TimeoutErr2 recovery (milliseconds)
------------------------------------------------------*/
#define     IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_TERR2_RCVRY_MS     (0)
#define     IL_CAN0_RX1_ECU_COM_DATA_RXFRM_TERR2_RCVRY_MS       (0)
#define     IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_TERR2_RCVRY_MS      (0)
#define     IL_CAN0_RX5_VEHICLE_INFO_RXFRM_TERR2_RCVRY_MS       (0)
#define     IL_CAN0_RX6_FUNCSW_STAT_RXFRM_TERR2_RCVRY_MS        (1000)
#define     IL_CAN0_RX7_FUEL_RATE_RXFRM_TERR2_RCVRY_MS          (0)
#define     IL_CAN0_RX8_ODO_TRIP_RXFRM_TERR2_RCVRY_MS           (0)
#define     IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_TERR2_RCVRY_MS     (0)
#define     IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_TERR2_RCVRY_MS     (0)
#define     IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_TERR2_RCVRY_MS     (0)
#define     IL_CAN0_RXD_MAINT_TRIP_RXFRM_TERR2_RCVRY_MS         (0)
#define     IL_CAN0_RXE_HEATER_STAT_RXFRM_TERR2_RCVRY_MS        (0)


/*------------------------------------------------------
CAN0 Transmit Signal Table

This table specifies each transmitted signal with the
following information:
    1) The index of the frame it resides in
    2) The "start bit" (LSBit location in the payload)
    3) The signal size in bits
------------------------------------------------------*/
static il_txsig_t const
il_can0_txsig_table[IL_CAN0_TX_NUM_SIGNALS] =
    {
        { IL_CAN0_TX_DIAG_RELATED_TXFRM_INDEX,                 56, 64 },    //  Daig_seg_data_tx
        { IL_CAN0_TX_NM_AND_LP_BK_TXFRM_INDEX,                 56, 64 },    //  Nm_and_lpbk_tx
        { IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_INDEX,             8,  8  },    //  Req_MT_func_cnt_data_1
        { IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_INDEX,             16, 8  },    //  Req_MT_func_cnt_data_2
        { IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_INDEX,             0,  8  },    //  Req_MT_func_cnt_svc_ID
        { IL_CAN0_TX1_SYS_INFO_TXFRM_INDEX,                    10, 1  },    //  Sys_info_fuel_con_unit
        { IL_CAN0_TX1_SYS_INFO_TXFRM_INDEX,                    8,  2  },    //  Sys_info_fuel_unit
        { IL_CAN0_TX1_SYS_INFO_TXFRM_INDEX,                    2,  5  },    //  Sys_info_lang
        { IL_CAN0_TX1_SYS_INFO_TXFRM_INDEX,                    7,  1  },    //  Sys_info_LC_sys_stat
        { IL_CAN0_TX1_SYS_INFO_TXFRM_INDEX,                    15, 1  },    //  Sys_info_mileage_unit
        { IL_CAN0_TX1_SYS_INFO_TXFRM_INDEX,                    12, 2  },    //  Sys_info_pressure_unit
        { IL_CAN0_TX1_SYS_INFO_TXFRM_INDEX,                    11, 1  },    //  Sys_info_temp_unit
        { IL_CAN0_TX1_SYS_INFO_TXFRM_INDEX,                    14, 1  },    //  Sys_info_VH_speed_unit
        { IL_CAN0_TX2_REQ_SUPPORT_TXFRM_INDEX,                 0,  8  },    //  Req_support_REQGSFL
        { IL_CAN0_TX3_HEATER_LEVEL_TXFRM_INDEX,                2,  1  },    //  Heater_lvl_btn_stat_aud
        { IL_CAN0_TX3_HEATER_LEVEL_TXFRM_INDEX,                3,  2  },    //  Heater_lvl_Lv
        { IL_CAN0_TX3_HEATER_LEVEL_TXFRM_INDEX,                5,  3  },    //  Heater_lvl_slect
        { IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_INDEX,            0,  8  },    //  Req_reprgrm_LBREPREQ
        { IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_INDEX,            8,  8  },    //  Req_reprgrm_PRGSTS
        { IL_CAN0_TX5_CLK_DATA_RES_TXFRM_INDEX,                32, 40 },    //  Clk_Date_Resp_data
        { IL_CAN0_TX6_DEV_CTRL_TXFRM_INDEX,                    14, 2  },    //  Dev_ctrl_CHG_Meter
        { IL_CAN0_TX6_DEV_CTRL_TXFRM_INDEX,                    2,  2  },    //  Dev_ctrl_grip_warm
        { IL_CAN0_TX6_DEV_CTRL_TXFRM_INDEX,                    4,  2  },    //  Dev_ctrl_lcd_brghtnss
        { IL_CAN0_TX6_DEV_CTRL_TXFRM_INDEX,                    0,  2  },    //  Dev_ctrl_seat_heater
        { IL_CAN0_TX6_DEV_CTRL_TXFRM_INDEX,                    12, 2  },    //  Dev_ctrl_TFT_brghtnss
        { IL_CAN0_TX6_DEV_CTRL_TXFRM_INDEX,                    6,  2  },    //  Dev_ctrl_windscrn
        { IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_INDEX,               56, 64 }     //  Fact_insp1_ga_tx
    };


static il_txsig_info_t const
il_can0_txsig_info =
    {
    &il_can0_txsig_table[0],
    IL_CAN0_TX_NUM_SIGNALS
    };


/*------------------------------------------------------
CAN0 Transmit Frame Signal Mappings

These data structures identify the signals contained
within each transmitted CAN frame
------------------------------------------------------*/

/*------------------------------------------------------
TX_DIAG_RELATED
------------------------------------------------------*/
static il_sig_index_t const
il_can0_tx_diag_related_txfrm_sig_list[] =
    {
    IL_CAN0_DAIG_SEG_DATA_TX_TXSIG_INDEX
    };

#define     IL_CAN0_TX_DIAG_RELATED_TXFRM_NSIG_BYTES            ( IL_CAN0_DAIG_SEG_DATA_TX_TXSIG_NBYTES )

#define     IL_CAN0_TX_DIAG_RELATED_TXFRM_NSIGS                 ( sizeof( il_can0_tx_diag_related_txfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
TX_NM_AND_LP_BK
------------------------------------------------------*/
static il_sig_index_t const
il_can0_tx_nm_and_lp_bk_txfrm_sig_list[] =
    {
    IL_CAN0_NM_AND_LPBK_TX_TXSIG_INDEX
    };

#define     IL_CAN0_TX_NM_AND_LP_BK_TXFRM_NSIG_BYTES            ( IL_CAN0_NM_AND_LPBK_TX_TXSIG_NBYTES )

#define     IL_CAN0_TX_NM_AND_LP_BK_TXFRM_NSIGS                 ( sizeof( il_can0_tx_nm_and_lp_bk_txfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
TX0_REQ_MT_FUNC_CNT
------------------------------------------------------*/
static il_sig_index_t const
il_can0_tx0_req_mt_func_cnt_txfrm_sig_list[] =
    {
    IL_CAN0_REQ_MT_FUNC_CNT_DATA_1_TXSIG_INDEX,
    IL_CAN0_REQ_MT_FUNC_CNT_DATA_2_TXSIG_INDEX,
    IL_CAN0_REQ_MT_FUNC_CNT_SVC_ID_TXSIG_INDEX
    };

#define     IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_NSIG_BYTES        ( IL_CAN0_REQ_MT_FUNC_CNT_DATA_1_TXSIG_NBYTES       + \
                                                                  IL_CAN0_REQ_MT_FUNC_CNT_DATA_2_TXSIG_NBYTES       + \
                                                                  IL_CAN0_REQ_MT_FUNC_CNT_SVC_ID_TXSIG_NBYTES )

#define     IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_NSIGS             ( sizeof( il_can0_tx0_req_mt_func_cnt_txfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
TX1_SYS_INFO
------------------------------------------------------*/
static il_sig_index_t const
il_can0_tx1_sys_info_txfrm_sig_list[] =
    {
    IL_CAN0_SYS_INFO_FUEL_CON_UNIT_TXSIG_INDEX,
    IL_CAN0_SYS_INFO_FUEL_UNIT_TXSIG_INDEX,
    IL_CAN0_SYS_INFO_LANG_TXSIG_INDEX,
    IL_CAN0_SYS_INFO_LC_SYS_STAT_TXSIG_INDEX,
    IL_CAN0_SYS_INFO_MILEAGE_UNIT_TXSIG_INDEX,
    IL_CAN0_SYS_INFO_PRESSURE_UNIT_TXSIG_INDEX,
    IL_CAN0_SYS_INFO_TEMP_UNIT_TXSIG_INDEX,
    IL_CAN0_SYS_INFO_VH_SPEED_UNIT_TXSIG_INDEX
    };

#define     IL_CAN0_TX1_SYS_INFO_TXFRM_NSIG_BYTES               ( IL_CAN0_SYS_INFO_FUEL_CON_UNIT_TXSIG_NBYTES       + \
                                                                  IL_CAN0_SYS_INFO_FUEL_UNIT_TXSIG_NBYTES           + \
                                                                  IL_CAN0_SYS_INFO_LANG_TXSIG_NBYTES                + \
                                                                  IL_CAN0_SYS_INFO_LC_SYS_STAT_TXSIG_NBYTES         + \
                                                                  IL_CAN0_SYS_INFO_MILEAGE_UNIT_TXSIG_NBYTES        + \
                                                                  IL_CAN0_SYS_INFO_PRESSURE_UNIT_TXSIG_NBYTES       + \
                                                                  IL_CAN0_SYS_INFO_TEMP_UNIT_TXSIG_NBYTES           + \
                                                                  IL_CAN0_SYS_INFO_VH_SPEED_UNIT_TXSIG_NBYTES )

#define     IL_CAN0_TX1_SYS_INFO_TXFRM_NSIGS                    ( sizeof( il_can0_tx1_sys_info_txfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
TX2_REQ_SUPPORT
------------------------------------------------------*/
static il_sig_index_t const
il_can0_tx2_req_support_txfrm_sig_list[] =
    {
    IL_CAN0_REQ_SUPPORT_REQGSFL_TXSIG_INDEX
    };

#define     IL_CAN0_TX2_REQ_SUPPORT_TXFRM_NSIG_BYTES            ( IL_CAN0_REQ_SUPPORT_REQGSFL_TXSIG_NBYTES )

#define     IL_CAN0_TX2_REQ_SUPPORT_TXFRM_NSIGS                 ( sizeof( il_can0_tx2_req_support_txfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
TX3_HEATER_LEVEL
------------------------------------------------------*/
static il_sig_index_t const
il_can0_tx3_heater_level_txfrm_sig_list[] =
    {
    IL_CAN0_HEATER_LVL_BTN_STAT_AUD_TXSIG_INDEX,
    IL_CAN0_HEATER_LVL_LV_TXSIG_INDEX,
    IL_CAN0_HEATER_LVL_SLECT_TXSIG_INDEX
    };

#define     IL_CAN0_TX3_HEATER_LEVEL_TXFRM_NSIG_BYTES           ( IL_CAN0_HEATER_LVL_BTN_STAT_AUD_TXSIG_NBYTES      + \
                                                                  IL_CAN0_HEATER_LVL_LV_TXSIG_NBYTES                + \
                                                                  IL_CAN0_HEATER_LVL_SLECT_TXSIG_NBYTES )

#define     IL_CAN0_TX3_HEATER_LEVEL_TXFRM_NSIGS                ( sizeof( il_can0_tx3_heater_level_txfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
TX4_REQ_REPRGRM_INFO
------------------------------------------------------*/
static il_sig_index_t const
il_can0_tx4_req_reprgrm_info_txfrm_sig_list[] =
    {
    IL_CAN0_REQ_REPRGRM_LBREPREQ_TXSIG_INDEX,
    IL_CAN0_REQ_REPRGRM_PRGSTS_TXSIG_INDEX
    };

#define     IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_NSIG_BYTES       ( IL_CAN0_REQ_REPRGRM_LBREPREQ_TXSIG_NBYTES         + \
                                                                  IL_CAN0_REQ_REPRGRM_PRGSTS_TXSIG_NBYTES )

#define     IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_NSIGS            ( sizeof( il_can0_tx4_req_reprgrm_info_txfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
TX5_CLK_DATA_RES
------------------------------------------------------*/
static il_sig_index_t const
il_can0_tx5_clk_data_res_txfrm_sig_list[] =
    {
    IL_CAN0_CLK_DATE_RESP_DATA_TXSIG_INDEX
    };

#define     IL_CAN0_TX5_CLK_DATA_RES_TXFRM_NSIG_BYTES           ( IL_CAN0_CLK_DATE_RESP_DATA_TXSIG_NBYTES )

#define     IL_CAN0_TX5_CLK_DATA_RES_TXFRM_NSIGS                ( sizeof( il_can0_tx5_clk_data_res_txfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
TX6_DEV_CTRL
------------------------------------------------------*/
static il_sig_index_t const
il_can0_tx6_dev_ctrl_txfrm_sig_list[] =
    {
    IL_CAN0_DEV_CTRL_CHG_METER_TXSIG_INDEX,
    IL_CAN0_DEV_CTRL_GRIP_WARM_TXSIG_INDEX,
    IL_CAN0_DEV_CTRL_LCD_BRGHTNSS_TXSIG_INDEX,
    IL_CAN0_DEV_CTRL_SEAT_HEATER_TXSIG_INDEX,
    IL_CAN0_DEV_CTRL_TFT_BRGHTNSS_TXSIG_INDEX,
    IL_CAN0_DEV_CTRL_WINDSCRN_TXSIG_INDEX
    };

#define     IL_CAN0_TX6_DEV_CTRL_TXFRM_NSIG_BYTES               ( IL_CAN0_DEV_CTRL_CHG_METER_TXSIG_NBYTES           + \
                                                                  IL_CAN0_DEV_CTRL_GRIP_WARM_TXSIG_NBYTES           + \
                                                                  IL_CAN0_DEV_CTRL_LCD_BRGHTNSS_TXSIG_NBYTES        + \
                                                                  IL_CAN0_DEV_CTRL_SEAT_HEATER_TXSIG_NBYTES         + \
                                                                  IL_CAN0_DEV_CTRL_TFT_BRGHTNSS_TXSIG_NBYTES        + \
                                                                  IL_CAN0_DEV_CTRL_WINDSCRN_TXSIG_NBYTES )

#define     IL_CAN0_TX6_DEV_CTRL_TXFRM_NSIGS                    ( sizeof( il_can0_tx6_dev_ctrl_txfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
TX7_FACT_INSP1_GA
------------------------------------------------------*/
static il_sig_index_t const
il_can0_tx7_fact_insp1_ga_txfrm_sig_list[] =
    {
    IL_CAN0_FACT_INSP1_GA_TX_TXSIG_INDEX
    };

#define     IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_NSIG_BYTES          ( IL_CAN0_FACT_INSP1_GA_TX_TXSIG_NBYTES )

#define     IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_NSIGS               ( sizeof( il_can0_tx7_fact_insp1_ga_txfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
CAN0 Transmit Frame Data
------------------------------------------------------*/
static uint8
il_can0_tx_diag_related_txfrm_data[IL_CAN0_TX_DIAG_RELATED_TXFRM_LEN];

static uint8
il_can0_tx_nm_and_lp_bk_txfrm_data[IL_CAN0_TX_NM_AND_LP_BK_TXFRM_LEN];

static uint8
il_can0_tx0_req_mt_func_cnt_txfrm_data[IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_LEN];

static uint8
il_can0_tx1_sys_info_txfrm_data[IL_CAN0_TX1_SYS_INFO_TXFRM_LEN];

static uint8
il_can0_tx2_req_support_txfrm_data[IL_CAN0_TX2_REQ_SUPPORT_TXFRM_LEN];

static uint8
il_can0_tx3_heater_level_txfrm_data[IL_CAN0_TX3_HEATER_LEVEL_TXFRM_LEN];

static uint8
il_can0_tx4_req_reprgrm_info_txfrm_data[IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_LEN];

static uint8
il_can0_tx5_clk_data_res_txfrm_data[IL_CAN0_TX5_CLK_DATA_RES_TXFRM_LEN];

static uint8
il_can0_tx6_dev_ctrl_txfrm_data[IL_CAN0_TX6_DEV_CTRL_TXFRM_LEN];

static uint8
il_can0_tx7_fact_insp1_ga_txfrm_data[IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_LEN];


/*------------------------------------------------------
CAN0 Transmit Frame Initialization Data
------------------------------------------------------*/
static uint8 const
il_can0_tx_diag_related_txfrm_init_data[IL_CAN0_TX_DIAG_RELATED_TXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_tx_nm_and_lp_bk_txfrm_init_data[IL_CAN0_TX_NM_AND_LP_BK_TXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_tx0_req_mt_func_cnt_txfrm_init_data[IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_LEN] =
    { 0x00,  0x00,  0x00 };

static uint8 const
il_can0_tx1_sys_info_txfrm_init_data[IL_CAN0_TX1_SYS_INFO_TXFRM_LEN] =
    { 0x00,  0x00 };

static uint8 const
il_can0_tx2_req_support_txfrm_init_data[IL_CAN0_TX2_REQ_SUPPORT_TXFRM_LEN] =
    { 0x00 };

static uint8 const
il_can0_tx3_heater_level_txfrm_init_data[IL_CAN0_TX3_HEATER_LEVEL_TXFRM_LEN] =
    { 0x00 };

static uint8 const
il_can0_tx4_req_reprgrm_info_txfrm_init_data[IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_LEN] =
    { 0x00,  0x00 };

static uint8 const
il_can0_tx5_clk_data_res_txfrm_init_data[IL_CAN0_TX5_CLK_DATA_RES_TXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_tx6_dev_ctrl_txfrm_init_data[IL_CAN0_TX6_DEV_CTRL_TXFRM_LEN] =
    { 0x00,  0x00 };

static uint8 const
il_can0_tx7_fact_insp1_ga_txfrm_init_data[IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };


/*------------------------------------------------------
CAN0 Transmit Message Data Structures
------------------------------------------------------*/
static can_tmd_t const
il_can0_tmd_table[IL_CAN0_TX_NUM_FRAMES] =
    {
        {
        TX_DIAG_RELATED_CAN0_ID,
        &il_can0_tx_diag_related_txfrm_data[0],
        IL_CAN0_TX_DIAG_RELATED_TXFRM_LEN,
        CAN_TXMSG_STANDARD,
        IL_CAN0_TX_DIAG_RELATED_TXFRM_HANDLE
        },
        {
        TX_NM_AND_LP_BK_CAN0_ID,
        &il_can0_tx_nm_and_lp_bk_txfrm_data[0],
        IL_CAN0_TX_NM_AND_LP_BK_TXFRM_LEN,
        CAN_TXMSG_STANDARD,
        IL_CAN0_TX_NM_AND_LP_BK_TXFRM_HANDLE
        },
        {
        TX0_REQ_MT_FUNC_CNT_CAN0_ID,
        &il_can0_tx0_req_mt_func_cnt_txfrm_data[0],
        IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_LEN,
        CAN_TXMSG_STANDARD,
        IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_HANDLE
        },
        {
        TX1_SYS_INFO_CAN0_ID,
        &il_can0_tx1_sys_info_txfrm_data[0],
        IL_CAN0_TX1_SYS_INFO_TXFRM_LEN,
        CAN_TXMSG_STANDARD,
        IL_CAN0_TX1_SYS_INFO_TXFRM_HANDLE
        },
        {
        TX2_REQ_SUPPORT_CAN0_ID,
        &il_can0_tx2_req_support_txfrm_data[0],
        IL_CAN0_TX2_REQ_SUPPORT_TXFRM_LEN,
        CAN_TXMSG_STANDARD,
        IL_CAN0_TX2_REQ_SUPPORT_TXFRM_HANDLE
        },
        {
        TX3_HEATER_LEVEL_CAN0_ID,
        &il_can0_tx3_heater_level_txfrm_data[0],
        IL_CAN0_TX3_HEATER_LEVEL_TXFRM_LEN,
        CAN_TXMSG_STANDARD,
        IL_CAN0_TX3_HEATER_LEVEL_TXFRM_HANDLE
        },
        {
        TX4_REQ_REPRGRM_INFO_CAN0_ID,
        &il_can0_tx4_req_reprgrm_info_txfrm_data[0],
        IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_LEN,
        CAN_TXMSG_STANDARD,
        IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_HANDLE
        },
        {
        TX5_CLK_DATA_RES_CAN0_ID,
        &il_can0_tx5_clk_data_res_txfrm_data[0],
        IL_CAN0_TX5_CLK_DATA_RES_TXFRM_LEN,
        CAN_TXMSG_STANDARD,
        IL_CAN0_TX5_CLK_DATA_RES_TXFRM_HANDLE
        },
        {
        TX6_DEV_CTRL_CAN0_ID,
        &il_can0_tx6_dev_ctrl_txfrm_data[0],
        IL_CAN0_TX6_DEV_CTRL_TXFRM_LEN,
        CAN_TXMSG_STANDARD,
        IL_CAN0_TX6_DEV_CTRL_TXFRM_HANDLE
        },
        {
        TX7_FACT_INSP1_GA_CAN0_ID,
        &il_can0_tx7_fact_insp1_ga_txfrm_data[0],
        IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_LEN,
        CAN_TXMSG_STANDARD,
        IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_HANDLE
        }
    };


/*------------------------------------------------------
CAN0 Periodic Transmit Frame Timeout Counters (Timers)
------------------------------------------------------*/
static uint16
il_can0_tx1_sys_info_txfrm_per_cnt;

static uint16
il_can0_tx6_dev_ctrl_txfrm_per_cnt;

/*------------------------------------------------------
CAN0 Periodic Transmit Timeout Counters
------------------------------------------------------*/
static uint16
il_can0_tx1_sys_info_txfrm_timeout_cnt;

static uint16
il_can0_tx6_dev_ctrl_txfrm_timeout_cnt;

/*------------------------------------------------------
CAN0 Periodic Transmit Frame Information
------------------------------------------------------*/
static il_tx_per_info_t const
il_can0_tx1_sys_info_txfrm_per_info =
    {
    IL_TIME_IN_TASK_TICS( IL_CAN0_TX1_SYS_INFO_TXFRM_PER_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_TX1_SYS_INFO_TXFRM_START_DELAY_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_TX1_SYS_INFO_TXFRM_TIMEOUTTX_MS ),
    &il_can0_tx1_sys_info_txfrm_per_cnt,
    &il_can0_tx1_sys_info_txfrm_timeout_cnt
    };

static il_tx_per_info_t const
il_can0_tx6_dev_ctrl_txfrm_per_info =
    {
    IL_TIME_IN_TASK_TICS( IL_CAN0_TX6_DEV_CTRL_TXFRM_PER_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_TX6_DEV_CTRL_TXFRM_START_DELAY_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_TX6_DEV_CTRL_TXFRM_TIMEOUTTX_MS ),
    &il_can0_tx6_dev_ctrl_txfrm_per_cnt,
    &il_can0_tx6_dev_ctrl_txfrm_timeout_cnt
    };


/*------------------------------------------------------
CAN0 Transmit Frame Table
------------------------------------------------------*/
static il_txfrm_t const
il_can0_txfrm_table[IL_CAN0_TX_NUM_FRAMES] =
    {
        {
        ( IL_TX_FRM_ATTR_EVENT | IL_TX_FRM_ATTR_MIN_DELAY | IL_TX_FRM_ATTR_MUTE_NOTIFY ),
        &il_can0_tx_diag_related_txfrm_data[0],
        &il_can0_tx_diag_related_txfrm_init_data[0],
        &il_can0_tx_diag_related_txfrm_sig_list[0],
        IL_CAN0_TX_DIAG_RELATED_TXFRM_NSIGS,
        IL_CAN0_TX_DIAG_RELATED_TXFRM_NSIG_BYTES,
        IL_TIME_IN_TASK_TICS( IL_CAN0_TX_DIAG_RELATED_TXFRM_MIN_DELAY_MS ),
        NULL
        },
        {
        ( IL_TX_FRM_ATTR_EVENT | IL_TX_FRM_ATTR_MIN_DELAY | IL_TX_FRM_ATTR_MUTE_NOTIFY ),
        &il_can0_tx_nm_and_lp_bk_txfrm_data[0],
        &il_can0_tx_nm_and_lp_bk_txfrm_init_data[0],
        &il_can0_tx_nm_and_lp_bk_txfrm_sig_list[0],
        IL_CAN0_TX_NM_AND_LP_BK_TXFRM_NSIGS,
        IL_CAN0_TX_NM_AND_LP_BK_TXFRM_NSIG_BYTES,
        IL_TIME_IN_TASK_TICS( IL_CAN0_TX_NM_AND_LP_BK_TXFRM_MIN_DELAY_MS ),
        NULL
        },
        {
        ( IL_TX_FRM_ATTR_EVENT | IL_TX_FRM_ATTR_MIN_DELAY | IL_TX_FRM_ATTR_MUTE_NOTIFY ),
        &il_can0_tx0_req_mt_func_cnt_txfrm_data[0],
        &il_can0_tx0_req_mt_func_cnt_txfrm_init_data[0],
        &il_can0_tx0_req_mt_func_cnt_txfrm_sig_list[0],
        IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_NSIGS,
        IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_NSIG_BYTES,
        IL_TIME_IN_TASK_TICS( IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_MIN_DELAY_MS ),
        NULL
        },
        {
        ( IL_TX_FRM_ATTR_PERIODIC | IL_TX_FRM_ATTR_MIN_DELAY | IL_TX_FRM_ATTR_MUTE_NOTIFY ),
        &il_can0_tx1_sys_info_txfrm_data[0],
        &il_can0_tx1_sys_info_txfrm_init_data[0],
        &il_can0_tx1_sys_info_txfrm_sig_list[0],
        IL_CAN0_TX1_SYS_INFO_TXFRM_NSIGS,
        IL_CAN0_TX1_SYS_INFO_TXFRM_NSIG_BYTES,
        IL_TIME_IN_TASK_TICS( IL_CAN0_TX1_SYS_INFO_TXFRM_MIN_DELAY_MS ),
        &il_can0_tx1_sys_info_txfrm_per_info
        },
        {
        ( IL_TX_FRM_ATTR_EVENT | IL_TX_FRM_ATTR_MIN_DELAY | IL_TX_FRM_ATTR_MUTE_NOTIFY ),
        &il_can0_tx2_req_support_txfrm_data[0],
        &il_can0_tx2_req_support_txfrm_init_data[0],
        &il_can0_tx2_req_support_txfrm_sig_list[0],
        IL_CAN0_TX2_REQ_SUPPORT_TXFRM_NSIGS,
        IL_CAN0_TX2_REQ_SUPPORT_TXFRM_NSIG_BYTES,
        IL_TIME_IN_TASK_TICS( IL_CAN0_TX2_REQ_SUPPORT_TXFRM_MIN_DELAY_MS ),
        NULL
        },
        {
        ( IL_TX_FRM_ATTR_EVENT | IL_TX_FRM_ATTR_MIN_DELAY | IL_TX_FRM_ATTR_MUTE_NOTIFY ),
        &il_can0_tx3_heater_level_txfrm_data[0],
        &il_can0_tx3_heater_level_txfrm_init_data[0],
        &il_can0_tx3_heater_level_txfrm_sig_list[0],
        IL_CAN0_TX3_HEATER_LEVEL_TXFRM_NSIGS,
        IL_CAN0_TX3_HEATER_LEVEL_TXFRM_NSIG_BYTES,
        IL_TIME_IN_TASK_TICS( IL_CAN0_TX3_HEATER_LEVEL_TXFRM_MIN_DELAY_MS ),
        NULL
        },
        {
        ( IL_TX_FRM_ATTR_EVENT | IL_TX_FRM_ATTR_MIN_DELAY | IL_TX_FRM_ATTR_MUTE_NOTIFY ),
        &il_can0_tx4_req_reprgrm_info_txfrm_data[0],
        &il_can0_tx4_req_reprgrm_info_txfrm_init_data[0],
        &il_can0_tx4_req_reprgrm_info_txfrm_sig_list[0],
        IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_NSIGS,
        IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_NSIG_BYTES,
        IL_TIME_IN_TASK_TICS( IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_MIN_DELAY_MS ),
        NULL
        },
        {
        ( IL_TX_FRM_ATTR_EVENT | IL_TX_FRM_ATTR_MIN_DELAY | IL_TX_FRM_ATTR_MUTE_NOTIFY ),
        &il_can0_tx5_clk_data_res_txfrm_data[0],
        &il_can0_tx5_clk_data_res_txfrm_init_data[0],
        &il_can0_tx5_clk_data_res_txfrm_sig_list[0],
        IL_CAN0_TX5_CLK_DATA_RES_TXFRM_NSIGS,
        IL_CAN0_TX5_CLK_DATA_RES_TXFRM_NSIG_BYTES,
        IL_TIME_IN_TASK_TICS( IL_CAN0_TX5_CLK_DATA_RES_TXFRM_MIN_DELAY_MS ),
        NULL
        },
        {
        ( IL_TX_FRM_ATTR_PERIODIC | IL_TX_FRM_ATTR_MIN_DELAY | IL_TX_FRM_ATTR_MUTE_NOTIFY ),
        &il_can0_tx6_dev_ctrl_txfrm_data[0],
        &il_can0_tx6_dev_ctrl_txfrm_init_data[0],
        &il_can0_tx6_dev_ctrl_txfrm_sig_list[0],
        IL_CAN0_TX6_DEV_CTRL_TXFRM_NSIGS,
        IL_CAN0_TX6_DEV_CTRL_TXFRM_NSIG_BYTES,
        IL_TIME_IN_TASK_TICS( IL_CAN0_TX6_DEV_CTRL_TXFRM_MIN_DELAY_MS ),
        &il_can0_tx6_dev_ctrl_txfrm_per_info
        },
        {
        ( IL_TX_FRM_ATTR_EVENT | IL_TX_FRM_ATTR_MIN_DELAY | IL_TX_FRM_ATTR_MUTE_NOTIFY ),
        &il_can0_tx7_fact_insp1_ga_txfrm_data[0],
        &il_can0_tx7_fact_insp1_ga_txfrm_init_data[0],
        &il_can0_tx7_fact_insp1_ga_txfrm_sig_list[0],
        IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_NSIGS,
        IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_NSIG_BYTES,
        IL_TIME_IN_TASK_TICS( IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_MIN_DELAY_MS ),
        NULL
        }
    };


/*------------------------------------------------------
CAN0 Transmit Frame Status and Delay Count
------------------------------------------------------*/
static uint8
il_can0_txfrm_status[IL_CAN0_TX_NUM_FRAMES];

static uint16
il_can0_txfrm_delay_cnt[IL_CAN0_TX_NUM_FRAMES];


static il_txfrm_info_t const
il_can0_txfrm_info =
    {
    &il_can0_txfrm_table[0],
    &il_can0_txfrm_status[0],
    &il_can0_txfrm_delay_cnt[0],
    &il_can0_tmd_table[0],
    IL_CAN0_TX_NUM_FRAMES
    };


/*------------------------------------------------------
CAN0 Receive Signal Status
------------------------------------------------------*/
static uint8
il_can0_rxsig_status[IL_CAN0_RX_NUM_SIGNALS];


/*------------------------------------------------------
CAN0 Receive Signal Data
------------------------------------------------------*/
static uint8
il_can0_daig_seg1_data_rxsig_data[IL_CAN0_DAIG_SEG1_DATA_RXSIG_NBYTES];

static uint8
il_can0_daig_seg2_data_rxsig_data[IL_CAN0_DAIG_SEG2_DATA_RXSIG_NBYTES];

static uint8
il_can0_daig_seg3_data_rxsig_data[IL_CAN0_DAIG_SEG3_DATA_RXSIG_NBYTES];

static uint8
il_can0_daig_seg4_data_rxsig_data[IL_CAN0_DAIG_SEG4_DATA_RXSIG_NBYTES];

static uint8
il_can0_daig_seg5_data_rxsig_data[IL_CAN0_DAIG_SEG5_DATA_RXSIG_NBYTES];

static uint8
il_can0_daig_seg6_data_rxsig_data[IL_CAN0_DAIG_SEG6_DATA_RXSIG_NBYTES];

static uint8
il_can0_daig_seg7_data_rxsig_data[IL_CAN0_DAIG_SEG7_DATA_RXSIG_NBYTES];

static uint8
il_can0_nm_and_lpbk_rx_rxsig_data[IL_CAN0_NM_AND_LPBK_RX_RXSIG_NBYTES];

static uint8
il_can0_ecu_indct_eg_spd_rxsig_data[IL_CAN0_ECU_INDCT_EG_SPD_RXSIG_NBYTES];

static uint8
il_can0_ecu_indct_tc_mode_rxsig_data[IL_CAN0_ECU_INDCT_TC_MODE_RXSIG_NBYTES];

static uint8
il_can0_ecu_com_data_rxsig_data[IL_CAN0_ECU_COM_DATA_RXSIG_NBYTES];

static uint8
il_can0_res_suppt_data_1_rxsig_data[IL_CAN0_RES_SUPPT_DATA_1_RXSIG_NBYTES];

static uint8
il_can0_res_suppt_data_2_rxsig_data[IL_CAN0_RES_SUPPT_DATA_2_RXSIG_NBYTES];

static uint8
il_can0_res_suppt_data_3_rxsig_data[IL_CAN0_RES_SUPPT_DATA_3_RXSIG_NBYTES];

static uint8
il_can0_res_suppt_data_4_rxsig_data[IL_CAN0_RES_SUPPT_DATA_4_RXSIG_NBYTES];

static uint8
il_can0_res_suppt_data_5_rxsig_data[IL_CAN0_RES_SUPPT_DATA_5_RXSIG_NBYTES];

static uint8
il_can0_res_suppt_data_6_rxsig_data[IL_CAN0_RES_SUPPT_DATA_6_RXSIG_NBYTES];

static uint8
il_can0_res_suppt_data_7_rxsig_data[IL_CAN0_RES_SUPPT_DATA_7_RXSIG_NBYTES];

static uint8
il_can0_res_suppt_svc_id_rxsig_data[IL_CAN0_RES_SUPPT_SVC_ID_RXSIG_NBYTES];

static uint8
il_can0_brtnss_ctrl_lcd_lv_rxsig_data[IL_CAN0_BRTNSS_CTRL_LCD_LV_RXSIG_NBYTES];

static uint8
il_can0_brtnss_ctrl_mt_tft_duty_rxsig_data[IL_CAN0_BRTNSS_CTRL_MT_TFT_DUTY_RXSIG_NBYTES];

static uint8
il_can0_res_mt_func_cnt_data_1_rxsig_data[IL_CAN0_RES_MT_FUNC_CNT_DATA_1_RXSIG_NBYTES];

static uint8
il_can0_res_mt_func_cnt_data_2_rxsig_data[IL_CAN0_RES_MT_FUNC_CNT_DATA_2_RXSIG_NBYTES];

static uint8
il_can0_res_mt_func_cnt_svc_id_rxsig_data[IL_CAN0_RES_MT_FUNC_CNT_SVC_ID_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_fuel_con_unit_rxsig_data[IL_CAN0_VEHICLE_INFO_FUEL_CON_UNIT_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_mile_unit_rxsig_data[IL_CAN0_VEHICLE_INFO_MILE_UNIT_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_press_unit_rxsig_data[IL_CAN0_VEHICLE_INFO_PRESS_UNIT_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_temp_unit_rxsig_data[IL_CAN0_VEHICLE_INFO_TEMP_UNIT_RXSIG_NBYTES];

static uint8
il_can0_func_sw_1_rxsig_data[IL_CAN0_FUNC_SW_1_RXSIG_NBYTES];

static uint8
il_can0_func_sw_2_rxsig_data[IL_CAN0_FUNC_SW_2_RXSIG_NBYTES];

static uint8
il_can0_func_sw_5_rxsig_data[IL_CAN0_FUNC_SW_5_RXSIG_NBYTES];

static uint8
il_can0_func_sw_6_rxsig_data[IL_CAN0_FUNC_SW_6_RXSIG_NBYTES];

static uint8
il_can0_func_sw_scrn_layer_rxsig_data[IL_CAN0_FUNC_SW_SCRN_LAYER_RXSIG_NBYTES];

static uint8
il_can0_fuel_rate_ave_rxsig_data[IL_CAN0_FUEL_RATE_AVE_RXSIG_NBYTES];

static uint8
il_can0_fuel_rate_avg_spd_rxsig_data[IL_CAN0_FUEL_RATE_AVG_SPD_RXSIG_NBYTES];

static uint8
il_can0_fuel_rate_inst_rxsig_data[IL_CAN0_FUEL_RATE_INST_RXSIG_NBYTES];

static uint8
il_can0_fuel_rate_range_dist_rxsig_data[IL_CAN0_FUEL_RATE_RANGE_DIST_RXSIG_NBYTES];

static uint8
il_can0_odo_trip_odometer_rxsig_data[IL_CAN0_ODO_TRIP_ODOMETER_RXSIG_NBYTES];

static uint8
il_can0_odo_trip1_meter_rxsig_data[IL_CAN0_ODO_TRIP1_METER_RXSIG_NBYTES];

static uint8
il_can0_odo_trip2_meter_rxsig_data[IL_CAN0_ODO_TRIP2_METER_RXSIG_NBYTES];

static uint8
il_can0_res_reprgrm_data_1_rxsig_data[IL_CAN0_RES_REPRGRM_DATA_1_RXSIG_NBYTES];

static uint8
il_can0_res_reprgrm_data_2_rxsig_data[IL_CAN0_RES_REPRGRM_DATA_2_RXSIG_NBYTES];

static uint8
il_can0_res_reprgrm_svc_id_rxsig_data[IL_CAN0_RES_REPRGRM_SVC_ID_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_2_aps_ang_tran_rxsig_data[IL_CAN0_VEHICLE_INFO_2_APS_ANG_TRAN_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_2_spd_real_rxsig_data[IL_CAN0_VEHICLE_INFO_2_SPD_REAL_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_2_spd_real_mt_rxsig_data[IL_CAN0_VEHICLE_INFO_2_SPD_REAL_MT_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_3_air_rxsig_data[IL_CAN0_VEHICLE_INFO_3_AIR_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_3_bat_rxsig_data[IL_CAN0_VEHICLE_INFO_3_BAT_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_3_clk_adjst_rxsig_data[IL_CAN0_VEHICLE_INFO_3_CLK_ADJST_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_3_coolant_rxsig_data[IL_CAN0_VEHICLE_INFO_3_COOLANT_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_3_cruise_rxsig_data[IL_CAN0_VEHICLE_INFO_3_CRUISE_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_3_fuel_con_rxsig_data[IL_CAN0_VEHICLE_INFO_3_FUEL_CON_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_4_ftrip_rxsig_data[IL_CAN0_VEHICLE_INFO_4_FTRIP_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_4_ftrip_hrd_rst_rxsig_data[IL_CAN0_VEHICLE_INFO_4_FTRIP_HRD_RST_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_4_fuel_rsv_rxsig_data[IL_CAN0_VEHICLE_INFO_4_FUEL_RSV_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_4_low_fuel_wrn_rxsig_data[IL_CAN0_VEHICLE_INFO_4_LOW_FUEL_WRN_RXSIG_NBYTES];

static uint8
il_can0_vehicle_info_4_odo_trip_dis_rxsig_data[IL_CAN0_VEHICLE_INFO_4_ODO_TRIP_DIS_RXSIG_NBYTES];

static uint8
il_can0_maint_trip_1_rxsig_data[IL_CAN0_MAINT_TRIP_1_RXSIG_NBYTES];

static uint8
il_can0_maint_trip_2_rxsig_data[IL_CAN0_MAINT_TRIP_2_RXSIG_NBYTES];

static uint8
il_can0_maint_trip_3_rxsig_data[IL_CAN0_MAINT_TRIP_3_RXSIG_NBYTES];

static uint8
il_can0_heater_stat_crnt_gw_stat_rxsig_data[IL_CAN0_HEATER_STAT_CRNT_GW_STAT_RXSIG_NBYTES];

static uint8
il_can0_heater_stat_crnt_sh_stat_rxsig_data[IL_CAN0_HEATER_STAT_CRNT_SH_STAT_RXSIG_NBYTES];

static uint8
il_can0_heater_stat_grip_warm_hi_rxsig_data[IL_CAN0_HEATER_STAT_GRIP_WARM_HI_RXSIG_NBYTES];

static uint8
il_can0_heater_stat_grip_warm_lo_rxsig_data[IL_CAN0_HEATER_STAT_GRIP_WARM_LO_RXSIG_NBYTES];

static uint8
il_can0_heater_stat_grip_warm_mid_rxsig_data[IL_CAN0_HEATER_STAT_GRIP_WARM_MID_RXSIG_NBYTES];

static uint8
il_can0_heater_stat_rider_seat_warm_hi_rxsig_data[IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_HI_RXSIG_NBYTES];

static uint8
il_can0_heater_stat_rider_seat_warm_lo_rxsig_data[IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_LO_RXSIG_NBYTES];

static uint8
il_can0_heater_stat_rider_seat_warm_mid_rxsig_data[IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_MID_RXSIG_NBYTES];

static uint8
il_can0_fact_insp_ns1_rxsig_data[IL_CAN0_FACT_INSP_NS1_RXSIG_NBYTES];

static uint8
il_can0_fact_insp2_ga_rx_rxsig_data[IL_CAN0_FACT_INSP2_GA_RX_RXSIG_NBYTES];


/*------------------------------------------------------
CAN0 Receive Signal Definitions
------------------------------------------------------*/
static il_rxsig_t const
il_can0_rxsig_table[IL_CAN0_RX_NUM_SIGNALS] =
    {
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        56,     64,
        &il_can0_daig_seg1_data_rxsig_data[0],
        IL_CAN0_DAIG_SEG1_DATA_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        56,     64,
        &il_can0_daig_seg2_data_rxsig_data[0],
        IL_CAN0_DAIG_SEG2_DATA_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        56,     64,
        &il_can0_daig_seg3_data_rxsig_data[0],
        IL_CAN0_DAIG_SEG3_DATA_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        56,     64,
        &il_can0_daig_seg4_data_rxsig_data[0],
        IL_CAN0_DAIG_SEG4_DATA_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        56,     64,
        &il_can0_daig_seg5_data_rxsig_data[0],
        IL_CAN0_DAIG_SEG5_DATA_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        56,     64,
        &il_can0_daig_seg6_data_rxsig_data[0],
        IL_CAN0_DAIG_SEG6_DATA_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        56,     64,
        &il_can0_daig_seg7_data_rxsig_data[0],
        IL_CAN0_DAIG_SEG7_DATA_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        56,     64,
        &il_can0_nm_and_lpbk_rx_rxsig_data[0],
        IL_CAN0_NM_AND_LPBK_RX_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        8,      16,
        &il_can0_ecu_indct_eg_spd_rxsig_data[0],
        IL_CAN0_ECU_INDCT_EG_SPD_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        25,     4,
        &il_can0_ecu_indct_tc_mode_rxsig_data[0],
        IL_CAN0_ECU_INDCT_TC_MODE_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        12,     2,
        &il_can0_ecu_com_data_rxsig_data[0],
        IL_CAN0_ECU_COM_DATA_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        8,      8,
        &il_can0_res_suppt_data_1_rxsig_data[0],
        IL_CAN0_RES_SUPPT_DATA_1_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        16,     8,
        &il_can0_res_suppt_data_2_rxsig_data[0],
        IL_CAN0_RES_SUPPT_DATA_2_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        24,     8,
        &il_can0_res_suppt_data_3_rxsig_data[0],
        IL_CAN0_RES_SUPPT_DATA_3_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        32,     8,
        &il_can0_res_suppt_data_4_rxsig_data[0],
        IL_CAN0_RES_SUPPT_DATA_4_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        40,     8,
        &il_can0_res_suppt_data_5_rxsig_data[0],
        IL_CAN0_RES_SUPPT_DATA_5_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        48,     8,
        &il_can0_res_suppt_data_6_rxsig_data[0],
        IL_CAN0_RES_SUPPT_DATA_6_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        56,     8,
        &il_can0_res_suppt_data_7_rxsig_data[0],
        IL_CAN0_RES_SUPPT_DATA_7_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        0,      8,
        &il_can0_res_suppt_svc_id_rxsig_data[0],
        IL_CAN0_RES_SUPPT_SVC_ID_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        11,     3,
        &il_can0_brtnss_ctrl_lcd_lv_rxsig_data[0],
        IL_CAN0_BRTNSS_CTRL_LCD_LV_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        14,     10,
        &il_can0_brtnss_ctrl_mt_tft_duty_rxsig_data[0],
        IL_CAN0_BRTNSS_CTRL_MT_TFT_DUTY_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        8,      8,
        &il_can0_res_mt_func_cnt_data_1_rxsig_data[0],
        IL_CAN0_RES_MT_FUNC_CNT_DATA_1_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        16,     8,
        &il_can0_res_mt_func_cnt_data_2_rxsig_data[0],
        IL_CAN0_RES_MT_FUNC_CNT_DATA_2_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        0,      8,
        &il_can0_res_mt_func_cnt_svc_id_rxsig_data[0],
        IL_CAN0_RES_MT_FUNC_CNT_SVC_ID_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        17,     2,
        &il_can0_vehicle_info_fuel_con_unit_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_FUEL_CON_UNIT_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        23,     1,
        &il_can0_vehicle_info_mile_unit_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_MILE_UNIT_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        20,     2,
        &il_can0_vehicle_info_press_unit_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_PRESS_UNIT_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        19,     1,
        &il_can0_vehicle_info_temp_unit_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_TEMP_UNIT_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        7,      1,
        &il_can0_func_sw_1_rxsig_data[0],
        IL_CAN0_FUNC_SW_1_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        6,      1,
        &il_can0_func_sw_2_rxsig_data[0],
        IL_CAN0_FUNC_SW_2_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        3,      1,
        &il_can0_func_sw_5_rxsig_data[0],
        IL_CAN0_FUNC_SW_5_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        2,      1,
        &il_can0_func_sw_6_rxsig_data[0],
        IL_CAN0_FUNC_SW_6_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        16,     1,
        &il_can0_func_sw_scrn_layer_rxsig_data[0],
        IL_CAN0_FUNC_SW_SCRN_LAYER_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        30,     10,
        &il_can0_fuel_rate_ave_rxsig_data[0],
        IL_CAN0_FUEL_RATE_AVE_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        62,     10,
        &il_can0_fuel_rate_avg_spd_rxsig_data[0],
        IL_CAN0_FUEL_RATE_AVG_SPD_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        14,     10,
        &il_can0_fuel_rate_inst_rxsig_data[0],
        IL_CAN0_FUEL_RATE_INST_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        46,     10,
        &il_can0_fuel_rate_range_dist_rxsig_data[0],
        IL_CAN0_FUEL_RATE_RANGE_DIST_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        16,     24,
        &il_can0_odo_trip_odometer_rxsig_data[0],
        IL_CAN0_ODO_TRIP_ODOMETER_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        44,     20,
        &il_can0_odo_trip1_meter_rxsig_data[0],
        IL_CAN0_ODO_TRIP1_METER_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        56,     20,
        &il_can0_odo_trip2_meter_rxsig_data[0],
        IL_CAN0_ODO_TRIP2_METER_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        8,      8,
        &il_can0_res_reprgrm_data_1_rxsig_data[0],
        IL_CAN0_RES_REPRGRM_DATA_1_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        16,     8,
        &il_can0_res_reprgrm_data_2_rxsig_data[0],
        IL_CAN0_RES_REPRGRM_DATA_2_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        0,      8,
        &il_can0_res_reprgrm_svc_id_rxsig_data[0],
        IL_CAN0_RES_REPRGRM_SVC_ID_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        8,      16,
        &il_can0_vehicle_info_2_aps_ang_tran_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_2_APS_ANG_TRAN_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        24,     9,
        &il_can0_vehicle_info_2_spd_real_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_2_SPD_REAL_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        40,     9,
        &il_can0_vehicle_info_2_spd_real_mt_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_2_SPD_REAL_MT_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        16,     8,
        &il_can0_vehicle_info_3_air_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_3_AIR_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        32,     8,
        &il_can0_vehicle_info_3_bat_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_3_BAT_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        10,     1,
        &il_can0_vehicle_info_3_clk_adjst_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_3_CLK_ADJST_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        24,     8,
        &il_can0_vehicle_info_3_coolant_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_3_COOLANT_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        40,     8,
        &il_can0_vehicle_info_3_cruise_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_3_CRUISE_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        11,     13,
        &il_can0_vehicle_info_3_fuel_con_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_3_FUEL_CON_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        10,     14,
        &il_can0_vehicle_info_4_ftrip_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_4_FTRIP_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        20,     1,
        &il_can0_vehicle_info_4_ftrip_hrd_rst_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_4_FTRIP_HRD_RST_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        8,      1,
        &il_can0_vehicle_info_4_fuel_rsv_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_4_FUEL_RSV_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        9,      1,
        &il_can0_vehicle_info_4_low_fuel_wrn_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_4_LOW_FUEL_WRN_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        21,     3,
        &il_can0_vehicle_info_4_odo_trip_dis_rxsig_data[0],
        IL_CAN0_VEHICLE_INFO_4_ODO_TRIP_DIS_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        22,     18,
        &il_can0_maint_trip_1_rxsig_data[0],
        IL_CAN0_MAINT_TRIP_1_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        36,     18,
        &il_can0_maint_trip_2_rxsig_data[0],
        IL_CAN0_MAINT_TRIP_2_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        50,     18,
        &il_can0_maint_trip_3_rxsig_data[0],
        IL_CAN0_MAINT_TRIP_3_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        30,     2,
        &il_can0_heater_stat_crnt_gw_stat_rxsig_data[0],
        IL_CAN0_HEATER_STAT_CRNT_GW_STAT_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        28,     2,
        &il_can0_heater_stat_crnt_sh_stat_rxsig_data[0],
        IL_CAN0_HEATER_STAT_CRNT_SH_STAT_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        12,     4,
        &il_can0_heater_stat_grip_warm_hi_rxsig_data[0],
        IL_CAN0_HEATER_STAT_GRIP_WARM_HI_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        4,      4,
        &il_can0_heater_stat_grip_warm_lo_rxsig_data[0],
        IL_CAN0_HEATER_STAT_GRIP_WARM_LO_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        0,      4,
        &il_can0_heater_stat_grip_warm_mid_rxsig_data[0],
        IL_CAN0_HEATER_STAT_GRIP_WARM_MID_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        16,     4,
        &il_can0_heater_stat_rider_seat_warm_hi_rxsig_data[0],
        IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_HI_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        8,      4,
        &il_can0_heater_stat_rider_seat_warm_lo_rxsig_data[0],
        IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_LO_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        20,     4,
        &il_can0_heater_stat_rider_seat_warm_mid_rxsig_data[0],
        IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_MID_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        4,      4,
        &il_can0_fact_insp_ns1_rxsig_data[0],
        IL_CAN0_FACT_INSP_NS1_RXSIG_NBYTES
        },
        {
        ( IL_RX_SIG_ATTR_NOTIFY | IL_RX_SIG_ATTR_NOTIFY_CHANGE ),
        56,     64,
        &il_can0_fact_insp2_ga_rx_rxsig_data[0],
        IL_CAN0_FACT_INSP2_GA_RX_RXSIG_NBYTES
        }
    };


static il_rxsig_info_t const
il_can0_rxsig_info =
    {
    &il_can0_rxsig_table[0],
    &il_can0_rxsig_status[0],
    IL_CAN0_RX_NUM_SIGNALS
    };


/*------------------------------------------------------
CAN0 Receive Frame Signal Mappings

These data structures identify the signals contained
within each received CAN frame
------------------------------------------------------*/

/*------------------------------------------------------
RX_DAIG_SEG1
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx_daig_seg1_rxfrm_sig_list[] =
    {
    IL_CAN0_DAIG_SEG1_DATA_RXSIG_INDEX
    };

#define     IL_CAN0_RX_DAIG_SEG1_RXFRM_NSIG_BYTES               ( IL_CAN0_DAIG_SEG1_DATA_RXSIG_NBYTES )

#define     IL_CAN0_RX_DAIG_SEG1_RXFRM_NSIGS                    ( sizeof( il_can0_rx_daig_seg1_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX_DAIG_SEG2
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx_daig_seg2_rxfrm_sig_list[] =
    {
    IL_CAN0_DAIG_SEG2_DATA_RXSIG_INDEX
    };

#define     IL_CAN0_RX_DAIG_SEG2_RXFRM_NSIG_BYTES               ( IL_CAN0_DAIG_SEG2_DATA_RXSIG_NBYTES )

#define     IL_CAN0_RX_DAIG_SEG2_RXFRM_NSIGS                    ( sizeof( il_can0_rx_daig_seg2_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX_DAIG_SEG3
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx_daig_seg3_rxfrm_sig_list[] =
    {
    IL_CAN0_DAIG_SEG3_DATA_RXSIG_INDEX
    };

#define     IL_CAN0_RX_DAIG_SEG3_RXFRM_NSIG_BYTES               ( IL_CAN0_DAIG_SEG3_DATA_RXSIG_NBYTES )

#define     IL_CAN0_RX_DAIG_SEG3_RXFRM_NSIGS                    ( sizeof( il_can0_rx_daig_seg3_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX_DAIG_SEG4
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx_daig_seg4_rxfrm_sig_list[] =
    {
    IL_CAN0_DAIG_SEG4_DATA_RXSIG_INDEX
    };

#define     IL_CAN0_RX_DAIG_SEG4_RXFRM_NSIG_BYTES               ( IL_CAN0_DAIG_SEG4_DATA_RXSIG_NBYTES )

#define     IL_CAN0_RX_DAIG_SEG4_RXFRM_NSIGS                    ( sizeof( il_can0_rx_daig_seg4_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX_DAIG_SEG5_YDT
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx_daig_seg5_ydt_rxfrm_sig_list[] =
    {
    IL_CAN0_DAIG_SEG5_DATA_RXSIG_INDEX
    };

#define     IL_CAN0_RX_DAIG_SEG5_YDT_RXFRM_NSIG_BYTES           ( IL_CAN0_DAIG_SEG5_DATA_RXSIG_NBYTES )

#define     IL_CAN0_RX_DAIG_SEG5_YDT_RXFRM_NSIGS                ( sizeof( il_can0_rx_daig_seg5_ydt_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX_DAIG_SEG6_YDT
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx_daig_seg6_ydt_rxfrm_sig_list[] =
    {
    IL_CAN0_DAIG_SEG6_DATA_RXSIG_INDEX
    };

#define     IL_CAN0_RX_DAIG_SEG6_YDT_RXFRM_NSIG_BYTES           ( IL_CAN0_DAIG_SEG6_DATA_RXSIG_NBYTES )

#define     IL_CAN0_RX_DAIG_SEG6_YDT_RXFRM_NSIGS                ( sizeof( il_can0_rx_daig_seg6_ydt_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX_DAIG_SEG7_YDT
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx_daig_seg7_ydt_rxfrm_sig_list[] =
    {
    IL_CAN0_DAIG_SEG7_DATA_RXSIG_INDEX
    };

#define     IL_CAN0_RX_DAIG_SEG7_YDT_RXFRM_NSIG_BYTES           ( IL_CAN0_DAIG_SEG7_DATA_RXSIG_NBYTES )

#define     IL_CAN0_RX_DAIG_SEG7_YDT_RXFRM_NSIGS                ( sizeof( il_can0_rx_daig_seg7_ydt_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX_NM_AND_LP_BK
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx_nm_and_lp_bk_rxfrm_sig_list[] =
    {
    IL_CAN0_NM_AND_LPBK_RX_RXSIG_INDEX
    };

#define     IL_CAN0_RX_NM_AND_LP_BK_RXFRM_NSIG_BYTES            ( IL_CAN0_NM_AND_LPBK_RX_RXSIG_NBYTES )

#define     IL_CAN0_RX_NM_AND_LP_BK_RXFRM_NSIGS                 ( sizeof( il_can0_rx_nm_and_lp_bk_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX0_ECU_INDCT_STAT
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx0_ecu_indct_stat_rxfrm_sig_list[] =
    {
    IL_CAN0_ECU_INDCT_EG_SPD_RXSIG_INDEX,
    IL_CAN0_ECU_INDCT_TC_MODE_RXSIG_INDEX
    };

#define     IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_NSIG_BYTES         ( IL_CAN0_ECU_INDCT_EG_SPD_RXSIG_NBYTES             + \
                                                                  IL_CAN0_ECU_INDCT_TC_MODE_RXSIG_NBYTES )

#define     IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_NSIGS              ( sizeof( il_can0_rx0_ecu_indct_stat_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX1_ECU_COM_DATA
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx1_ecu_com_data_rxfrm_sig_list[] =
    {
    IL_CAN0_ECU_COM_DATA_RXSIG_INDEX
    };

#define     IL_CAN0_RX1_ECU_COM_DATA_RXFRM_NSIG_BYTES           ( IL_CAN0_ECU_COM_DATA_RXSIG_NBYTES )

#define     IL_CAN0_RX1_ECU_COM_DATA_RXFRM_NSIGS                ( sizeof( il_can0_rx1_ecu_com_data_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX2_RES_SUPPORT
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx2_res_support_rxfrm_sig_list[] =
    {
    IL_CAN0_RES_SUPPT_DATA_1_RXSIG_INDEX,
    IL_CAN0_RES_SUPPT_DATA_2_RXSIG_INDEX,
    IL_CAN0_RES_SUPPT_DATA_3_RXSIG_INDEX,
    IL_CAN0_RES_SUPPT_DATA_4_RXSIG_INDEX,
    IL_CAN0_RES_SUPPT_DATA_5_RXSIG_INDEX,
    IL_CAN0_RES_SUPPT_DATA_6_RXSIG_INDEX,
    IL_CAN0_RES_SUPPT_DATA_7_RXSIG_INDEX,
    IL_CAN0_RES_SUPPT_SVC_ID_RXSIG_INDEX
    };

#define     IL_CAN0_RX2_RES_SUPPORT_RXFRM_NSIG_BYTES            ( IL_CAN0_RES_SUPPT_DATA_1_RXSIG_NBYTES             + \
                                                                  IL_CAN0_RES_SUPPT_DATA_2_RXSIG_NBYTES             + \
                                                                  IL_CAN0_RES_SUPPT_DATA_3_RXSIG_NBYTES             + \
                                                                  IL_CAN0_RES_SUPPT_DATA_4_RXSIG_NBYTES             + \
                                                                  IL_CAN0_RES_SUPPT_DATA_5_RXSIG_NBYTES             + \
                                                                  IL_CAN0_RES_SUPPT_DATA_6_RXSIG_NBYTES             + \
                                                                  IL_CAN0_RES_SUPPT_DATA_7_RXSIG_NBYTES             + \
                                                                  IL_CAN0_RES_SUPPT_SVC_ID_RXSIG_NBYTES )

#define     IL_CAN0_RX2_RES_SUPPORT_RXFRM_NSIGS                 ( sizeof( il_can0_rx2_res_support_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX3_BRGTHNSS_CTRL
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx3_brgthnss_ctrl_rxfrm_sig_list[] =
    {
    IL_CAN0_BRTNSS_CTRL_LCD_LV_RXSIG_INDEX,
    IL_CAN0_BRTNSS_CTRL_MT_TFT_DUTY_RXSIG_INDEX
    };

#define     IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_NSIG_BYTES          ( IL_CAN0_BRTNSS_CTRL_LCD_LV_RXSIG_NBYTES           + \
                                                                  IL_CAN0_BRTNSS_CTRL_MT_TFT_DUTY_RXSIG_NBYTES )

#define     IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_NSIGS               ( sizeof( il_can0_rx3_brgthnss_ctrl_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX4_RES_MT_FUNC_CNT
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx4_res_mt_func_cnt_rxfrm_sig_list[] =
    {
    IL_CAN0_RES_MT_FUNC_CNT_DATA_1_RXSIG_INDEX,
    IL_CAN0_RES_MT_FUNC_CNT_DATA_2_RXSIG_INDEX,
    IL_CAN0_RES_MT_FUNC_CNT_SVC_ID_RXSIG_INDEX
    };

#define     IL_CAN0_RX4_RES_MT_FUNC_CNT_RXFRM_NSIG_BYTES        ( IL_CAN0_RES_MT_FUNC_CNT_DATA_1_RXSIG_NBYTES       + \
                                                                  IL_CAN0_RES_MT_FUNC_CNT_DATA_2_RXSIG_NBYTES       + \
                                                                  IL_CAN0_RES_MT_FUNC_CNT_SVC_ID_RXSIG_NBYTES )

#define     IL_CAN0_RX4_RES_MT_FUNC_CNT_RXFRM_NSIGS             ( sizeof( il_can0_rx4_res_mt_func_cnt_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX5_VEHICLE_INFO
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx5_vehicle_info_rxfrm_sig_list[] =
    {
    IL_CAN0_VEHICLE_INFO_FUEL_CON_UNIT_RXSIG_INDEX,
    IL_CAN0_VEHICLE_INFO_MILE_UNIT_RXSIG_INDEX,
    IL_CAN0_VEHICLE_INFO_PRESS_UNIT_RXSIG_INDEX,
    IL_CAN0_VEHICLE_INFO_TEMP_UNIT_RXSIG_INDEX
    };

#define     IL_CAN0_RX5_VEHICLE_INFO_RXFRM_NSIG_BYTES           ( IL_CAN0_VEHICLE_INFO_FUEL_CON_UNIT_RXSIG_NBYTES   + \
                                                                  IL_CAN0_VEHICLE_INFO_MILE_UNIT_RXSIG_NBYTES       + \
                                                                  IL_CAN0_VEHICLE_INFO_PRESS_UNIT_RXSIG_NBYTES      + \
                                                                  IL_CAN0_VEHICLE_INFO_TEMP_UNIT_RXSIG_NBYTES )

#define     IL_CAN0_RX5_VEHICLE_INFO_RXFRM_NSIGS                ( sizeof( il_can0_rx5_vehicle_info_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX6_FUNCSW_STAT
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx6_funcsw_stat_rxfrm_sig_list[] =
    {
    IL_CAN0_FUNC_SW_1_RXSIG_INDEX,
    IL_CAN0_FUNC_SW_2_RXSIG_INDEX,
    IL_CAN0_FUNC_SW_5_RXSIG_INDEX,
    IL_CAN0_FUNC_SW_6_RXSIG_INDEX,
    IL_CAN0_FUNC_SW_SCRN_LAYER_RXSIG_INDEX
    };

#define     IL_CAN0_RX6_FUNCSW_STAT_RXFRM_NSIG_BYTES            ( IL_CAN0_FUNC_SW_1_RXSIG_NBYTES                    + \
                                                                  IL_CAN0_FUNC_SW_2_RXSIG_NBYTES                    + \
                                                                  IL_CAN0_FUNC_SW_5_RXSIG_NBYTES                    + \
                                                                  IL_CAN0_FUNC_SW_6_RXSIG_NBYTES                    + \
                                                                  IL_CAN0_FUNC_SW_SCRN_LAYER_RXSIG_NBYTES )

#define     IL_CAN0_RX6_FUNCSW_STAT_RXFRM_NSIGS                 ( sizeof( il_can0_rx6_funcsw_stat_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX7_FUEL_RATE
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx7_fuel_rate_rxfrm_sig_list[] =
    {
    IL_CAN0_FUEL_RATE_AVE_RXSIG_INDEX,
    IL_CAN0_FUEL_RATE_AVG_SPD_RXSIG_INDEX,
    IL_CAN0_FUEL_RATE_INST_RXSIG_INDEX,
    IL_CAN0_FUEL_RATE_RANGE_DIST_RXSIG_INDEX
    };

#define     IL_CAN0_RX7_FUEL_RATE_RXFRM_NSIG_BYTES              ( IL_CAN0_FUEL_RATE_AVE_RXSIG_NBYTES                + \
                                                                  IL_CAN0_FUEL_RATE_AVG_SPD_RXSIG_NBYTES            + \
                                                                  IL_CAN0_FUEL_RATE_INST_RXSIG_NBYTES               + \
                                                                  IL_CAN0_FUEL_RATE_RANGE_DIST_RXSIG_NBYTES )

#define     IL_CAN0_RX7_FUEL_RATE_RXFRM_NSIGS                   ( sizeof( il_can0_rx7_fuel_rate_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX8_ODO_TRIP
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx8_odo_trip_rxfrm_sig_list[] =
    {
    IL_CAN0_ODO_TRIP_ODOMETER_RXSIG_INDEX,
    IL_CAN0_ODO_TRIP1_METER_RXSIG_INDEX,
    IL_CAN0_ODO_TRIP2_METER_RXSIG_INDEX
    };

#define     IL_CAN0_RX8_ODO_TRIP_RXFRM_NSIG_BYTES               ( IL_CAN0_ODO_TRIP_ODOMETER_RXSIG_NBYTES            + \
                                                                  IL_CAN0_ODO_TRIP1_METER_RXSIG_NBYTES              + \
                                                                  IL_CAN0_ODO_TRIP2_METER_RXSIG_NBYTES )

#define     IL_CAN0_RX8_ODO_TRIP_RXFRM_NSIGS                    ( sizeof( il_can0_rx8_odo_trip_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RX9_RES_RPRGRM_INFO
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rx9_res_rprgrm_info_rxfrm_sig_list[] =
    {
    IL_CAN0_RES_REPRGRM_DATA_1_RXSIG_INDEX,
    IL_CAN0_RES_REPRGRM_DATA_2_RXSIG_INDEX,
    IL_CAN0_RES_REPRGRM_SVC_ID_RXSIG_INDEX
    };

#define     IL_CAN0_RX9_RES_RPRGRM_INFO_RXFRM_NSIG_BYTES        ( IL_CAN0_RES_REPRGRM_DATA_1_RXSIG_NBYTES           + \
                                                                  IL_CAN0_RES_REPRGRM_DATA_2_RXSIG_NBYTES           + \
                                                                  IL_CAN0_RES_REPRGRM_SVC_ID_RXSIG_NBYTES )

#define     IL_CAN0_RX9_RES_RPRGRM_INFO_RXFRM_NSIGS             ( sizeof( il_can0_rx9_res_rprgrm_info_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RXA_VEHICLE_INFO_2
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rxa_vehicle_info_2_rxfrm_sig_list[] =
    {
    IL_CAN0_VEHICLE_INFO_2_APS_ANG_TRAN_RXSIG_INDEX,
    IL_CAN0_VEHICLE_INFO_2_SPD_REAL_RXSIG_INDEX,
    IL_CAN0_VEHICLE_INFO_2_SPD_REAL_MT_RXSIG_INDEX
    };

#define     IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_NSIG_BYTES         ( IL_CAN0_VEHICLE_INFO_2_APS_ANG_TRAN_RXSIG_NBYTES  + \
                                                                  IL_CAN0_VEHICLE_INFO_2_SPD_REAL_RXSIG_NBYTES      + \
                                                                  IL_CAN0_VEHICLE_INFO_2_SPD_REAL_MT_RXSIG_NBYTES )

#define     IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_NSIGS              ( sizeof( il_can0_rxa_vehicle_info_2_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RXB_VEHICLE_INFO_3
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rxb_vehicle_info_3_rxfrm_sig_list[] =
    {
    IL_CAN0_VEHICLE_INFO_3_AIR_RXSIG_INDEX,
    IL_CAN0_VEHICLE_INFO_3_BAT_RXSIG_INDEX,
    IL_CAN0_VEHICLE_INFO_3_CLK_ADJST_RXSIG_INDEX,
    IL_CAN0_VEHICLE_INFO_3_COOLANT_RXSIG_INDEX,
    IL_CAN0_VEHICLE_INFO_3_CRUISE_RXSIG_INDEX,
    IL_CAN0_VEHICLE_INFO_3_FUEL_CON_RXSIG_INDEX
    };

#define     IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_NSIG_BYTES         ( IL_CAN0_VEHICLE_INFO_3_AIR_RXSIG_NBYTES           + \
                                                                  IL_CAN0_VEHICLE_INFO_3_BAT_RXSIG_NBYTES           + \
                                                                  IL_CAN0_VEHICLE_INFO_3_CLK_ADJST_RXSIG_NBYTES     + \
                                                                  IL_CAN0_VEHICLE_INFO_3_COOLANT_RXSIG_NBYTES       + \
                                                                  IL_CAN0_VEHICLE_INFO_3_CRUISE_RXSIG_NBYTES        + \
                                                                  IL_CAN0_VEHICLE_INFO_3_FUEL_CON_RXSIG_NBYTES )

#define     IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_NSIGS              ( sizeof( il_can0_rxb_vehicle_info_3_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RXC_VEHICLE_INFO_4
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rxc_vehicle_info_4_rxfrm_sig_list[] =
    {
    IL_CAN0_VEHICLE_INFO_4_FTRIP_RXSIG_INDEX,
    IL_CAN0_VEHICLE_INFO_4_FTRIP_HRD_RST_RXSIG_INDEX,
    IL_CAN0_VEHICLE_INFO_4_FUEL_RSV_RXSIG_INDEX,
    IL_CAN0_VEHICLE_INFO_4_LOW_FUEL_WRN_RXSIG_INDEX,
    IL_CAN0_VEHICLE_INFO_4_ODO_TRIP_DIS_RXSIG_INDEX
    };

#define     IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_NSIG_BYTES         ( IL_CAN0_VEHICLE_INFO_4_FTRIP_RXSIG_NBYTES         + \
                                                                  IL_CAN0_VEHICLE_INFO_4_FTRIP_HRD_RST_RXSIG_NBYTES + \
                                                                  IL_CAN0_VEHICLE_INFO_4_FUEL_RSV_RXSIG_NBYTES      + \
                                                                  IL_CAN0_VEHICLE_INFO_4_LOW_FUEL_WRN_RXSIG_NBYTES  + \
                                                                  IL_CAN0_VEHICLE_INFO_4_ODO_TRIP_DIS_RXSIG_NBYTES )

#define     IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_NSIGS              ( sizeof( il_can0_rxc_vehicle_info_4_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RXD_MAINT_TRIP
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rxd_maint_trip_rxfrm_sig_list[] =
    {
    IL_CAN0_MAINT_TRIP_1_RXSIG_INDEX,
    IL_CAN0_MAINT_TRIP_2_RXSIG_INDEX,
    IL_CAN0_MAINT_TRIP_3_RXSIG_INDEX
    };

#define     IL_CAN0_RXD_MAINT_TRIP_RXFRM_NSIG_BYTES             ( IL_CAN0_MAINT_TRIP_1_RXSIG_NBYTES                 + \
                                                                  IL_CAN0_MAINT_TRIP_2_RXSIG_NBYTES                 + \
                                                                  IL_CAN0_MAINT_TRIP_3_RXSIG_NBYTES )

#define     IL_CAN0_RXD_MAINT_TRIP_RXFRM_NSIGS                  ( sizeof( il_can0_rxd_maint_trip_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RXE_HEATER_STAT
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rxe_heater_stat_rxfrm_sig_list[] =
    {
    IL_CAN0_HEATER_STAT_CRNT_GW_STAT_RXSIG_INDEX,
    IL_CAN0_HEATER_STAT_CRNT_SH_STAT_RXSIG_INDEX,
    IL_CAN0_HEATER_STAT_GRIP_WARM_HI_RXSIG_INDEX,
    IL_CAN0_HEATER_STAT_GRIP_WARM_LO_RXSIG_INDEX,
    IL_CAN0_HEATER_STAT_GRIP_WARM_MID_RXSIG_INDEX,
    IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_HI_RXSIG_INDEX,
    IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_LO_RXSIG_INDEX,
    IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_MID_RXSIG_INDEX
    };

#define     IL_CAN0_RXE_HEATER_STAT_RXFRM_NSIG_BYTES            ( IL_CAN0_HEATER_STAT_CRNT_GW_STAT_RXSIG_NBYTES     + \
                                                                  IL_CAN0_HEATER_STAT_CRNT_SH_STAT_RXSIG_NBYTES     + \
                                                                  IL_CAN0_HEATER_STAT_GRIP_WARM_HI_RXSIG_NBYTES     + \
                                                                  IL_CAN0_HEATER_STAT_GRIP_WARM_LO_RXSIG_NBYTES     + \
                                                                  IL_CAN0_HEATER_STAT_GRIP_WARM_MID_RXSIG_NBYTES    + \
                                                                  IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_HI_RXSIG_NBYTES+ \
                                                                  IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_LO_RXSIG_NBYTES+ \
                                                                  IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_MID_RXSIG_NBYTES )

#define     IL_CAN0_RXE_HEATER_STAT_RXFRM_NSIGS                 ( sizeof( il_can0_rxe_heater_stat_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RXF_FACT_INSP_NS
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rxf_fact_insp_ns_rxfrm_sig_list[] =
    {
    IL_CAN0_FACT_INSP_NS1_RXSIG_INDEX
    };

#define     IL_CAN0_RXF_FACT_INSP_NS_RXFRM_NSIG_BYTES           ( IL_CAN0_FACT_INSP_NS1_RXSIG_NBYTES )

#define     IL_CAN0_RXF_FACT_INSP_NS_RXFRM_NSIGS                ( sizeof( il_can0_rxf_fact_insp_ns_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
RXF_FACT_INSP2_GA
------------------------------------------------------*/
static il_sig_index_t const
il_can0_rxf_fact_insp2_ga_rxfrm_sig_list[] =
    {
    IL_CAN0_FACT_INSP2_GA_RX_RXSIG_INDEX
    };

#define     IL_CAN0_RXF_FACT_INSP2_GA_RXFRM_NSIG_BYTES          ( IL_CAN0_FACT_INSP2_GA_RX_RXSIG_NBYTES )

#define     IL_CAN0_RXF_FACT_INSP2_GA_RXFRM_NSIGS               ( sizeof( il_can0_rxf_fact_insp2_ga_rxfrm_sig_list ) / sizeof( il_sig_index_t ) )


/*------------------------------------------------------
CAN0 Receive Frame Data
------------------------------------------------------*/
static uint8
il_can0_rx_daig_seg1_rxfrm_data[IL_CAN0_RX_DAIG_SEG1_RXFRM_LEN];

static uint8
il_can0_rx_daig_seg2_rxfrm_data[IL_CAN0_RX_DAIG_SEG2_RXFRM_LEN];

static uint8
il_can0_rx_daig_seg3_rxfrm_data[IL_CAN0_RX_DAIG_SEG3_RXFRM_LEN];

static uint8
il_can0_rx_daig_seg4_rxfrm_data[IL_CAN0_RX_DAIG_SEG4_RXFRM_LEN];

static uint8
il_can0_rx_daig_seg5_ydt_rxfrm_data[IL_CAN0_RX_DAIG_SEG5_YDT_RXFRM_LEN];

static uint8
il_can0_rx_daig_seg6_ydt_rxfrm_data[IL_CAN0_RX_DAIG_SEG6_YDT_RXFRM_LEN];

static uint8
il_can0_rx_daig_seg7_ydt_rxfrm_data[IL_CAN0_RX_DAIG_SEG7_YDT_RXFRM_LEN];

static uint8
il_can0_rx_nm_and_lp_bk_rxfrm_data[IL_CAN0_RX_NM_AND_LP_BK_RXFRM_LEN];

static uint8
il_can0_rx0_ecu_indct_stat_rxfrm_data[IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_LEN];

static uint8
il_can0_rx1_ecu_com_data_rxfrm_data[IL_CAN0_RX1_ECU_COM_DATA_RXFRM_LEN];

static uint8
il_can0_rx2_res_support_rxfrm_data[IL_CAN0_RX2_RES_SUPPORT_RXFRM_LEN];

static uint8
il_can0_rx3_brgthnss_ctrl_rxfrm_data[IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_LEN];

static uint8
il_can0_rx4_res_mt_func_cnt_rxfrm_data[IL_CAN0_RX4_RES_MT_FUNC_CNT_RXFRM_LEN];

static uint8
il_can0_rx5_vehicle_info_rxfrm_data[IL_CAN0_RX5_VEHICLE_INFO_RXFRM_LEN];

static uint8
il_can0_rx6_funcsw_stat_rxfrm_data[IL_CAN0_RX6_FUNCSW_STAT_RXFRM_LEN];

static uint8
il_can0_rx7_fuel_rate_rxfrm_data[IL_CAN0_RX7_FUEL_RATE_RXFRM_LEN];

static uint8
il_can0_rx8_odo_trip_rxfrm_data[IL_CAN0_RX8_ODO_TRIP_RXFRM_LEN];

static uint8
il_can0_rx9_res_rprgrm_info_rxfrm_data[IL_CAN0_RX9_RES_RPRGRM_INFO_RXFRM_LEN];

static uint8
il_can0_rxa_vehicle_info_2_rxfrm_data[IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_LEN];

static uint8
il_can0_rxb_vehicle_info_3_rxfrm_data[IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_LEN];

static uint8
il_can0_rxc_vehicle_info_4_rxfrm_data[IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_LEN];

static uint8
il_can0_rxd_maint_trip_rxfrm_data[IL_CAN0_RXD_MAINT_TRIP_RXFRM_LEN];

static uint8
il_can0_rxe_heater_stat_rxfrm_data[IL_CAN0_RXE_HEATER_STAT_RXFRM_LEN];

static uint8
il_can0_rxf_fact_insp_ns_rxfrm_data[IL_CAN0_RXF_FACT_INSP_NS_RXFRM_LEN];

static uint8
il_can0_rxf_fact_insp2_ga_rxfrm_data[IL_CAN0_RXF_FACT_INSP2_GA_RXFRM_LEN];


/*------------------------------------------------------
CAN0 Receive Frame Initialization Data
------------------------------------------------------*/
static uint8 const
il_can0_rx_daig_seg1_rxfrm_init_data[IL_CAN0_RX_DAIG_SEG1_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx_daig_seg2_rxfrm_init_data[IL_CAN0_RX_DAIG_SEG2_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx_daig_seg3_rxfrm_init_data[IL_CAN0_RX_DAIG_SEG3_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx_daig_seg4_rxfrm_init_data[IL_CAN0_RX_DAIG_SEG4_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx_daig_seg5_ydt_rxfrm_init_data[IL_CAN0_RX_DAIG_SEG5_YDT_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx_daig_seg6_ydt_rxfrm_init_data[IL_CAN0_RX_DAIG_SEG6_YDT_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx_daig_seg7_ydt_rxfrm_init_data[IL_CAN0_RX_DAIG_SEG7_YDT_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx_nm_and_lp_bk_rxfrm_init_data[IL_CAN0_RX_NM_AND_LP_BK_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx0_ecu_indct_stat_rxfrm_init_data[IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx1_ecu_com_data_rxfrm_init_data[IL_CAN0_RX1_ECU_COM_DATA_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx2_res_support_rxfrm_init_data[IL_CAN0_RX2_RES_SUPPORT_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx3_brgthnss_ctrl_rxfrm_init_data[IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_LEN] =
    { 0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx4_res_mt_func_cnt_rxfrm_init_data[IL_CAN0_RX4_RES_MT_FUNC_CNT_RXFRM_LEN] =
    { 0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx5_vehicle_info_rxfrm_init_data[IL_CAN0_RX5_VEHICLE_INFO_RXFRM_LEN] =
    { 0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx6_funcsw_stat_rxfrm_init_data[IL_CAN0_RX6_FUNCSW_STAT_RXFRM_LEN] =
    { 0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx7_fuel_rate_rxfrm_init_data[IL_CAN0_RX7_FUEL_RATE_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx8_odo_trip_rxfrm_init_data[IL_CAN0_RX8_ODO_TRIP_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rx9_res_rprgrm_info_rxfrm_init_data[IL_CAN0_RX9_RES_RPRGRM_INFO_RXFRM_LEN] =
    { 0x00,  0x00,  0x00 };

static uint8 const
il_can0_rxa_vehicle_info_2_rxfrm_init_data[IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rxb_vehicle_info_3_rxfrm_init_data[IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rxc_vehicle_info_4_rxfrm_init_data[IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_LEN] =
    { 0x00,  0x00,  0x00 };

static uint8 const
il_can0_rxd_maint_trip_rxfrm_init_data[IL_CAN0_RXD_MAINT_TRIP_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rxe_heater_stat_rxfrm_init_data[IL_CAN0_RXE_HEATER_STAT_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00 };

static uint8 const
il_can0_rxf_fact_insp_ns_rxfrm_init_data[IL_CAN0_RXF_FACT_INSP_NS_RXFRM_LEN] =
    { 0x00 };

static uint8 const
il_can0_rxf_fact_insp2_ga_rxfrm_init_data[IL_CAN0_RXF_FACT_INSP2_GA_RXFRM_LEN] =
    { 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };

/*------------------------------------------------------
CAN0 Periodic Receive Frame Periodic Counters (Timers)
------------------------------------------------------*/
static uint16
il_can0_rx0_ecu_indct_stat_rxfrm_per_cnt;

static uint16
il_can0_rx1_ecu_com_data_rxfrm_per_cnt;

static uint16
il_can0_rx3_brgthnss_ctrl_rxfrm_per_cnt;

static uint16
il_can0_rx5_vehicle_info_rxfrm_per_cnt;

static uint16
il_can0_rx6_funcsw_stat_rxfrm_per_cnt;

static uint16
il_can0_rx7_fuel_rate_rxfrm_per_cnt;

static uint16
il_can0_rx8_odo_trip_rxfrm_per_cnt;

static uint16
il_can0_rxa_vehicle_info_2_rxfrm_per_cnt;

static uint16
il_can0_rxb_vehicle_info_3_rxfrm_per_cnt;

static uint16
il_can0_rxc_vehicle_info_4_rxfrm_per_cnt;

static uint16
il_can0_rxd_maint_trip_rxfrm_per_cnt;

static uint16
il_can0_rxe_heater_stat_rxfrm_per_cnt;

/*------------------------------------------------------
CAN0 Periodic Receive Frame Timeout Counters (Timers)
------------------------------------------------------*/
static uint16
il_can0_rx0_ecu_indct_stat_rxfrm_timeout_cnt;

static uint16
il_can0_rx1_ecu_com_data_rxfrm_timeout_cnt;

static uint16
il_can0_rx3_brgthnss_ctrl_rxfrm_timeout_cnt;

static uint16
il_can0_rx5_vehicle_info_rxfrm_timeout_cnt;

static uint16
il_can0_rx6_funcsw_stat_rxfrm_timeout_cnt;

static uint16
il_can0_rx7_fuel_rate_rxfrm_timeout_cnt;

static uint16
il_can0_rx8_odo_trip_rxfrm_timeout_cnt;

static uint16
il_can0_rxa_vehicle_info_2_rxfrm_timeout_cnt;

static uint16
il_can0_rxb_vehicle_info_3_rxfrm_timeout_cnt;

static uint16
il_can0_rxc_vehicle_info_4_rxfrm_timeout_cnt;

static uint16
il_can0_rxd_maint_trip_rxfrm_timeout_cnt;

static uint16
il_can0_rxe_heater_stat_rxfrm_timeout_cnt;


/*------------------------------------------------------
CAN0 Periodic Receive Frame Timeout error recovery Count
------------------------------------------------------*/
static uint16
il_can0_rx0_ecu_indct_stat_rxfrm_terr_rcvry_cnt;

static uint16
il_can0_rx1_ecu_com_data_rxfrm_terr_rcvry_cnt;

static uint16
il_can0_rx3_brgthnss_ctrl_rxfrm_terr_rcvry_cnt;

static uint16
il_can0_rx5_vehicle_info_rxfrm_terr_rcvry_cnt;

static uint16
il_can0_rx6_funcsw_stat_rxfrm_terr_rcvry_cnt;

static uint16
il_can0_rx7_fuel_rate_rxfrm_terr_rcvry_cnt;

static uint16
il_can0_rx8_odo_trip_rxfrm_terr_rcvry_cnt;

static uint16
il_can0_rxa_vehicle_info_2_rxfrm_terr_rcvry_cnt;

static uint16
il_can0_rxb_vehicle_info_3_rxfrm_terr_rcvry_cnt;

static uint16
il_can0_rxc_vehicle_info_4_rxfrm_terr_rcvry_cnt;

static uint16
il_can0_rxd_maint_trip_rxfrm_terr_rcvry_cnt;

static uint16
il_can0_rxe_heater_stat_rxfrm_terr_rcvry_cnt;


/*------------------------------------------------------
CAN0 Periodic Receive Frame Information
------------------------------------------------------*/
static il_rx_per_info_t const
il_can0_rx0_ecu_indct_stat_rxfrm_per_info =
    {
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_PER_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_TIMEOUT1_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_TIMEOUT2_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_TERR1_RCVRY_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_TERR2_RCVRY_MS ),
    &il_can0_rx0_ecu_indct_stat_rxfrm_per_cnt,
    &il_can0_rx0_ecu_indct_stat_rxfrm_timeout_cnt,
    &il_can0_rx0_ecu_indct_stat_rxfrm_terr_rcvry_cnt
    };

static il_rx_per_info_t const
il_can0_rx1_ecu_com_data_rxfrm_per_info =
    {
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX1_ECU_COM_DATA_RXFRM_PER_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX1_ECU_COM_DATA_RXFRM_TIMEOUT1_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX1_ECU_COM_DATA_RXFRM_TIMEOUT2_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX1_ECU_COM_DATA_RXFRM_TERR1_RCVRY_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX1_ECU_COM_DATA_RXFRM_TERR2_RCVRY_MS ),
    &il_can0_rx1_ecu_com_data_rxfrm_per_cnt,
    &il_can0_rx1_ecu_com_data_rxfrm_timeout_cnt,
    &il_can0_rx1_ecu_com_data_rxfrm_terr_rcvry_cnt
    };

static il_rx_per_info_t const
il_can0_rx3_brgthnss_ctrl_rxfrm_per_info =
    {
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_PER_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_TIMEOUT1_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_TIMEOUT2_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_TERR1_RCVRY_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_TERR2_RCVRY_MS ),
    &il_can0_rx3_brgthnss_ctrl_rxfrm_per_cnt,
    &il_can0_rx3_brgthnss_ctrl_rxfrm_timeout_cnt,
    &il_can0_rx3_brgthnss_ctrl_rxfrm_terr_rcvry_cnt
    };

static il_rx_per_info_t const
il_can0_rx5_vehicle_info_rxfrm_per_info =
    {
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX5_VEHICLE_INFO_RXFRM_PER_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX5_VEHICLE_INFO_RXFRM_TIMEOUT1_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX5_VEHICLE_INFO_RXFRM_TIMEOUT2_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX5_VEHICLE_INFO_RXFRM_TERR1_RCVRY_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX5_VEHICLE_INFO_RXFRM_TERR2_RCVRY_MS ),
    &il_can0_rx5_vehicle_info_rxfrm_per_cnt,
    &il_can0_rx5_vehicle_info_rxfrm_timeout_cnt,
    &il_can0_rx5_vehicle_info_rxfrm_terr_rcvry_cnt
    };

static il_rx_per_info_t const
il_can0_rx6_funcsw_stat_rxfrm_per_info =
    {
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX6_FUNCSW_STAT_RXFRM_PER_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX6_FUNCSW_STAT_RXFRM_TIMEOUT1_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX6_FUNCSW_STAT_RXFRM_TIMEOUT2_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX6_FUNCSW_STAT_RXFRM_TERR1_RCVRY_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX6_FUNCSW_STAT_RXFRM_TERR2_RCVRY_MS ),
    &il_can0_rx6_funcsw_stat_rxfrm_per_cnt,
    &il_can0_rx6_funcsw_stat_rxfrm_timeout_cnt,
    &il_can0_rx6_funcsw_stat_rxfrm_terr_rcvry_cnt
    };

static il_rx_per_info_t const
il_can0_rx7_fuel_rate_rxfrm_per_info =
    {
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX7_FUEL_RATE_RXFRM_PER_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX7_FUEL_RATE_RXFRM_TIMEOUT1_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX7_FUEL_RATE_RXFRM_TIMEOUT2_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX7_FUEL_RATE_RXFRM_TERR1_RCVRY_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX7_FUEL_RATE_RXFRM_TERR2_RCVRY_MS ),
    &il_can0_rx7_fuel_rate_rxfrm_per_cnt,
    &il_can0_rx7_fuel_rate_rxfrm_timeout_cnt,
    &il_can0_rx7_fuel_rate_rxfrm_terr_rcvry_cnt
    };

static il_rx_per_info_t const
il_can0_rx8_odo_trip_rxfrm_per_info =
    {
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX8_ODO_TRIP_RXFRM_PER_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX8_ODO_TRIP_RXFRM_TIMEOUT1_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX8_ODO_TRIP_RXFRM_TIMEOUT2_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX8_ODO_TRIP_RXFRM_TERR1_RCVRY_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RX8_ODO_TRIP_RXFRM_TERR2_RCVRY_MS ),
    &il_can0_rx8_odo_trip_rxfrm_per_cnt,
    &il_can0_rx8_odo_trip_rxfrm_timeout_cnt,
    &il_can0_rx8_odo_trip_rxfrm_terr_rcvry_cnt
    };

static il_rx_per_info_t const
il_can0_rxa_vehicle_info_2_rxfrm_per_info =
    {
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_PER_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_TIMEOUT1_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_TIMEOUT2_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_TERR1_RCVRY_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_TERR2_RCVRY_MS ),
    &il_can0_rxa_vehicle_info_2_rxfrm_per_cnt,
    &il_can0_rxa_vehicle_info_2_rxfrm_timeout_cnt,
    &il_can0_rxa_vehicle_info_2_rxfrm_terr_rcvry_cnt
    };

static il_rx_per_info_t const
il_can0_rxb_vehicle_info_3_rxfrm_per_info =
    {
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_PER_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_TIMEOUT1_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_TIMEOUT2_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_TERR1_RCVRY_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_TERR2_RCVRY_MS ),
    &il_can0_rxb_vehicle_info_3_rxfrm_per_cnt,
    &il_can0_rxb_vehicle_info_3_rxfrm_timeout_cnt,
    &il_can0_rxb_vehicle_info_3_rxfrm_terr_rcvry_cnt
    };

static il_rx_per_info_t const
il_can0_rxc_vehicle_info_4_rxfrm_per_info =
    {
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_PER_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_TIMEOUT1_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_TIMEOUT2_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_TERR1_RCVRY_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_TERR2_RCVRY_MS ),
    &il_can0_rxc_vehicle_info_4_rxfrm_per_cnt,
    &il_can0_rxc_vehicle_info_4_rxfrm_timeout_cnt,
    &il_can0_rxc_vehicle_info_4_rxfrm_terr_rcvry_cnt
    };

static il_rx_per_info_t const
il_can0_rxd_maint_trip_rxfrm_per_info =
    {
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXD_MAINT_TRIP_RXFRM_PER_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXD_MAINT_TRIP_RXFRM_TIMEOUT1_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXD_MAINT_TRIP_RXFRM_TIMEOUT2_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXD_MAINT_TRIP_RXFRM_TERR1_RCVRY_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXD_MAINT_TRIP_RXFRM_TERR2_RCVRY_MS ),
    &il_can0_rxd_maint_trip_rxfrm_per_cnt,
    &il_can0_rxd_maint_trip_rxfrm_timeout_cnt,
    &il_can0_rxd_maint_trip_rxfrm_terr_rcvry_cnt
    };

static il_rx_per_info_t const
il_can0_rxe_heater_stat_rxfrm_per_info =
    {
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXE_HEATER_STAT_RXFRM_PER_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXE_HEATER_STAT_RXFRM_TIMEOUT1_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXE_HEATER_STAT_RXFRM_TIMEOUT2_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXE_HEATER_STAT_RXFRM_TERR1_RCVRY_MS ),
    IL_TIME_IN_TASK_TICS( IL_CAN0_RXE_HEATER_STAT_RXFRM_TERR2_RCVRY_MS ),
    &il_can0_rxe_heater_stat_rxfrm_per_cnt,
    &il_can0_rxe_heater_stat_rxfrm_timeout_cnt,
    &il_can0_rxe_heater_stat_rxfrm_terr_rcvry_cnt
    };


/*------------------------------------------------------
CAN0 Receive Frame Table
------------------------------------------------------*/
static il_rxfrm_t const
il_can0_rxfrm_table[IL_CAN0_RX_NUM_FRAMES] =
    {
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT | IL_RX_FRM_ATTR_ABSENT_NOTIFY ),
        IL_CAN0_RX_DAIG_SEG1_RXFRM_LEN,
        IL_CAN0_RX_DAIG_SEG1_RXFRM_MIN_LEN,
        &il_can0_rx_daig_seg1_rxfrm_init_data[0],
        &il_can0_rx_daig_seg1_rxfrm_sig_list[0],
        IL_CAN0_RX_DAIG_SEG1_RXFRM_NSIGS,
        IL_CAN0_RX_DAIG_SEG1_RXFRM_NSIG_BYTES,
        &il_can0_rx_daig_seg1_rxfrm_data[0],
        NULL
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT | IL_RX_FRM_ATTR_ABSENT_NOTIFY ),
        IL_CAN0_RX_DAIG_SEG2_RXFRM_LEN,
        IL_CAN0_RX_DAIG_SEG2_RXFRM_MIN_LEN,
        &il_can0_rx_daig_seg2_rxfrm_init_data[0],
        &il_can0_rx_daig_seg2_rxfrm_sig_list[0],
        IL_CAN0_RX_DAIG_SEG2_RXFRM_NSIGS,
        IL_CAN0_RX_DAIG_SEG2_RXFRM_NSIG_BYTES,
        &il_can0_rx_daig_seg2_rxfrm_data[0],
        NULL
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT | IL_RX_FRM_ATTR_ABSENT_NOTIFY ),
        IL_CAN0_RX_DAIG_SEG3_RXFRM_LEN,
        IL_CAN0_RX_DAIG_SEG3_RXFRM_MIN_LEN,
        &il_can0_rx_daig_seg3_rxfrm_init_data[0],
        &il_can0_rx_daig_seg3_rxfrm_sig_list[0],
        IL_CAN0_RX_DAIG_SEG3_RXFRM_NSIGS,
        IL_CAN0_RX_DAIG_SEG3_RXFRM_NSIG_BYTES,
        &il_can0_rx_daig_seg3_rxfrm_data[0],
        NULL
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT | IL_RX_FRM_ATTR_ABSENT_NOTIFY ),
        IL_CAN0_RX_DAIG_SEG4_RXFRM_LEN,
        IL_CAN0_RX_DAIG_SEG4_RXFRM_MIN_LEN,
        &il_can0_rx_daig_seg4_rxfrm_init_data[0],
        &il_can0_rx_daig_seg4_rxfrm_sig_list[0],
        IL_CAN0_RX_DAIG_SEG4_RXFRM_NSIGS,
        IL_CAN0_RX_DAIG_SEG4_RXFRM_NSIG_BYTES,
        &il_can0_rx_daig_seg4_rxfrm_data[0],
        NULL
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT | IL_RX_FRM_ATTR_ABSENT_NOTIFY ),
        IL_CAN0_RX_DAIG_SEG5_YDT_RXFRM_LEN,
        IL_CAN0_RX_DAIG_SEG5_YDT_RXFRM_MIN_LEN,
        &il_can0_rx_daig_seg5_ydt_rxfrm_init_data[0],
        &il_can0_rx_daig_seg5_ydt_rxfrm_sig_list[0],
        IL_CAN0_RX_DAIG_SEG5_YDT_RXFRM_NSIGS,
        IL_CAN0_RX_DAIG_SEG5_YDT_RXFRM_NSIG_BYTES,
        &il_can0_rx_daig_seg5_ydt_rxfrm_data[0],
        NULL
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT | IL_RX_FRM_ATTR_ABSENT_NOTIFY ),
        IL_CAN0_RX_DAIG_SEG6_YDT_RXFRM_LEN,
        IL_CAN0_RX_DAIG_SEG6_YDT_RXFRM_MIN_LEN,
        &il_can0_rx_daig_seg6_ydt_rxfrm_init_data[0],
        &il_can0_rx_daig_seg6_ydt_rxfrm_sig_list[0],
        IL_CAN0_RX_DAIG_SEG6_YDT_RXFRM_NSIGS,
        IL_CAN0_RX_DAIG_SEG6_YDT_RXFRM_NSIG_BYTES,
        &il_can0_rx_daig_seg6_ydt_rxfrm_data[0],
        NULL
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT | IL_RX_FRM_ATTR_ABSENT_NOTIFY ),
        IL_CAN0_RX_DAIG_SEG7_YDT_RXFRM_LEN,
        IL_CAN0_RX_DAIG_SEG7_YDT_RXFRM_MIN_LEN,
        &il_can0_rx_daig_seg7_ydt_rxfrm_init_data[0],
        &il_can0_rx_daig_seg7_ydt_rxfrm_sig_list[0],
        IL_CAN0_RX_DAIG_SEG7_YDT_RXFRM_NSIGS,
        IL_CAN0_RX_DAIG_SEG7_YDT_RXFRM_NSIG_BYTES,
        &il_can0_rx_daig_seg7_ydt_rxfrm_data[0],
        NULL
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT | IL_RX_FRM_ATTR_ABSENT_NOTIFY ),
        IL_CAN0_RX_NM_AND_LP_BK_RXFRM_LEN,
        IL_CAN0_RX_NM_AND_LP_BK_RXFRM_MIN_LEN,
        &il_can0_rx_nm_and_lp_bk_rxfrm_init_data[0],
        &il_can0_rx_nm_and_lp_bk_rxfrm_sig_list[0],
        IL_CAN0_RX_NM_AND_LP_BK_RXFRM_NSIGS,
        IL_CAN0_RX_NM_AND_LP_BK_RXFRM_NSIG_BYTES,
        &il_can0_rx_nm_and_lp_bk_rxfrm_data[0],
        NULL
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT | IL_RX_FRM_ATTR_ABSENT_NOTIFY ),
        IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_LEN,
        IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_MIN_LEN,
        &il_can0_rx0_ecu_indct_stat_rxfrm_init_data[0],
        &il_can0_rx0_ecu_indct_stat_rxfrm_sig_list[0],
        IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_NSIGS,
        IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_NSIG_BYTES,
        &il_can0_rx0_ecu_indct_stat_rxfrm_data[0],
        &il_can0_rx0_ecu_indct_stat_rxfrm_per_info
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT | IL_RX_FRM_ATTR_ABSENT_NOTIFY ),
        IL_CAN0_RX1_ECU_COM_DATA_RXFRM_LEN,
        IL_CAN0_RX1_ECU_COM_DATA_RXFRM_MIN_LEN,
        &il_can0_rx1_ecu_com_data_rxfrm_init_data[0],
        &il_can0_rx1_ecu_com_data_rxfrm_sig_list[0],
        IL_CAN0_RX1_ECU_COM_DATA_RXFRM_NSIGS,
        IL_CAN0_RX1_ECU_COM_DATA_RXFRM_NSIG_BYTES,
        &il_can0_rx1_ecu_com_data_rxfrm_data[0],
        &il_can0_rx1_ecu_com_data_rxfrm_per_info
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT | IL_RX_FRM_ATTR_ABSENT_NOTIFY ),
        IL_CAN0_RX2_RES_SUPPORT_RXFRM_LEN,
        IL_CAN0_RX2_RES_SUPPORT_RXFRM_MIN_LEN,
        &il_can0_rx2_res_support_rxfrm_init_data[0],
        &il_can0_rx2_res_support_rxfrm_sig_list[0],
        IL_CAN0_RX2_RES_SUPPORT_RXFRM_NSIGS,
        IL_CAN0_RX2_RES_SUPPORT_RXFRM_NSIG_BYTES,
        &il_can0_rx2_res_support_rxfrm_data[0],
        NULL
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT | IL_RX_FRM_ATTR_ABSENT_NOTIFY ),
        IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_LEN,
        IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_MIN_LEN,
        &il_can0_rx3_brgthnss_ctrl_rxfrm_init_data[0],
        &il_can0_rx3_brgthnss_ctrl_rxfrm_sig_list[0],
        IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_NSIGS,
        IL_CAN0_RX3_BRGTHNSS_CTRL_RXFRM_NSIG_BYTES,
        &il_can0_rx3_brgthnss_ctrl_rxfrm_data[0],
        &il_can0_rx3_brgthnss_ctrl_rxfrm_per_info
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT ),
        IL_CAN0_RX4_RES_MT_FUNC_CNT_RXFRM_LEN,
        IL_CAN0_RX4_RES_MT_FUNC_CNT_RXFRM_MIN_LEN,
        &il_can0_rx4_res_mt_func_cnt_rxfrm_init_data[0],
        &il_can0_rx4_res_mt_func_cnt_rxfrm_sig_list[0],
        IL_CAN0_RX4_RES_MT_FUNC_CNT_RXFRM_NSIGS,
        IL_CAN0_RX4_RES_MT_FUNC_CNT_RXFRM_NSIG_BYTES,
        &il_can0_rx4_res_mt_func_cnt_rxfrm_data[0],
        NULL
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT ),
        IL_CAN0_RX5_VEHICLE_INFO_RXFRM_LEN,
        IL_CAN0_RX5_VEHICLE_INFO_RXFRM_MIN_LEN,
        &il_can0_rx5_vehicle_info_rxfrm_init_data[0],
        &il_can0_rx5_vehicle_info_rxfrm_sig_list[0],
        IL_CAN0_RX5_VEHICLE_INFO_RXFRM_NSIGS,
        IL_CAN0_RX5_VEHICLE_INFO_RXFRM_NSIG_BYTES,
        &il_can0_rx5_vehicle_info_rxfrm_data[0],
        &il_can0_rx5_vehicle_info_rxfrm_per_info
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT ),
        IL_CAN0_RX6_FUNCSW_STAT_RXFRM_LEN,
        IL_CAN0_RX6_FUNCSW_STAT_RXFRM_MIN_LEN,
        &il_can0_rx6_funcsw_stat_rxfrm_init_data[0],
        &il_can0_rx6_funcsw_stat_rxfrm_sig_list[0],
        IL_CAN0_RX6_FUNCSW_STAT_RXFRM_NSIGS,
        IL_CAN0_RX6_FUNCSW_STAT_RXFRM_NSIG_BYTES,
        &il_can0_rx6_funcsw_stat_rxfrm_data[0],
        &il_can0_rx6_funcsw_stat_rxfrm_per_info
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT ),
        IL_CAN0_RX7_FUEL_RATE_RXFRM_LEN,
        IL_CAN0_RX7_FUEL_RATE_RXFRM_MIN_LEN,
        &il_can0_rx7_fuel_rate_rxfrm_init_data[0],
        &il_can0_rx7_fuel_rate_rxfrm_sig_list[0],
        IL_CAN0_RX7_FUEL_RATE_RXFRM_NSIGS,
        IL_CAN0_RX7_FUEL_RATE_RXFRM_NSIG_BYTES,
        &il_can0_rx7_fuel_rate_rxfrm_data[0],
        &il_can0_rx7_fuel_rate_rxfrm_per_info
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT ),
        IL_CAN0_RX8_ODO_TRIP_RXFRM_LEN,
        IL_CAN0_RX8_ODO_TRIP_RXFRM_MIN_LEN,
        &il_can0_rx8_odo_trip_rxfrm_init_data[0],
        &il_can0_rx8_odo_trip_rxfrm_sig_list[0],
        IL_CAN0_RX8_ODO_TRIP_RXFRM_NSIGS,
        IL_CAN0_RX8_ODO_TRIP_RXFRM_NSIG_BYTES,
        &il_can0_rx8_odo_trip_rxfrm_data[0],
        &il_can0_rx8_odo_trip_rxfrm_per_info
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT ),
        IL_CAN0_RX9_RES_RPRGRM_INFO_RXFRM_LEN,
        IL_CAN0_RX9_RES_RPRGRM_INFO_RXFRM_MIN_LEN,
        &il_can0_rx9_res_rprgrm_info_rxfrm_init_data[0],
        &il_can0_rx9_res_rprgrm_info_rxfrm_sig_list[0],
        IL_CAN0_RX9_RES_RPRGRM_INFO_RXFRM_NSIGS,
        IL_CAN0_RX9_RES_RPRGRM_INFO_RXFRM_NSIG_BYTES,
        &il_can0_rx9_res_rprgrm_info_rxfrm_data[0],
        NULL
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT ),
        IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_LEN,
        IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_MIN_LEN,
        &il_can0_rxa_vehicle_info_2_rxfrm_init_data[0],
        &il_can0_rxa_vehicle_info_2_rxfrm_sig_list[0],
        IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_NSIGS,
        IL_CAN0_RXA_VEHICLE_INFO_2_RXFRM_NSIG_BYTES,
        &il_can0_rxa_vehicle_info_2_rxfrm_data[0],
        &il_can0_rxa_vehicle_info_2_rxfrm_per_info
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT ),
        IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_LEN,
        IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_MIN_LEN,
        &il_can0_rxb_vehicle_info_3_rxfrm_init_data[0],
        &il_can0_rxb_vehicle_info_3_rxfrm_sig_list[0],
        IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_NSIGS,
        IL_CAN0_RXB_VEHICLE_INFO_3_RXFRM_NSIG_BYTES,
        &il_can0_rxb_vehicle_info_3_rxfrm_data[0],
        &il_can0_rxb_vehicle_info_3_rxfrm_per_info
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT ),
        IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_LEN,
        IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_MIN_LEN,
        &il_can0_rxc_vehicle_info_4_rxfrm_init_data[0],
        &il_can0_rxc_vehicle_info_4_rxfrm_sig_list[0],
        IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_NSIGS,
        IL_CAN0_RXC_VEHICLE_INFO_4_RXFRM_NSIG_BYTES,
        &il_can0_rxc_vehicle_info_4_rxfrm_data[0],
        &il_can0_rxc_vehicle_info_4_rxfrm_per_info
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT ),
        IL_CAN0_RXD_MAINT_TRIP_RXFRM_LEN,
        IL_CAN0_RXD_MAINT_TRIP_RXFRM_MIN_LEN,
        &il_can0_rxd_maint_trip_rxfrm_init_data[0],
        &il_can0_rxd_maint_trip_rxfrm_sig_list[0],
        IL_CAN0_RXD_MAINT_TRIP_RXFRM_NSIGS,
        IL_CAN0_RXD_MAINT_TRIP_RXFRM_NSIG_BYTES,
        &il_can0_rxd_maint_trip_rxfrm_data[0],
        &il_can0_rxd_maint_trip_rxfrm_per_info
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT ),
        IL_CAN0_RXE_HEATER_STAT_RXFRM_LEN,
        IL_CAN0_RXE_HEATER_STAT_RXFRM_MIN_LEN,
        &il_can0_rxe_heater_stat_rxfrm_init_data[0],
        &il_can0_rxe_heater_stat_rxfrm_sig_list[0],
        IL_CAN0_RXE_HEATER_STAT_RXFRM_NSIGS,
        IL_CAN0_RXE_HEATER_STAT_RXFRM_NSIG_BYTES,
        &il_can0_rxe_heater_stat_rxfrm_data[0],
        &il_can0_rxe_heater_stat_rxfrm_per_info
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT ),
        IL_CAN0_RXF_FACT_INSP_NS_RXFRM_LEN,
        IL_CAN0_RXF_FACT_INSP_NS_RXFRM_MIN_LEN,
        &il_can0_rxf_fact_insp_ns_rxfrm_init_data[0],
        &il_can0_rxf_fact_insp_ns_rxfrm_sig_list[0],
        IL_CAN0_RXF_FACT_INSP_NS_RXFRM_NSIGS,
        IL_CAN0_RXF_FACT_INSP_NS_RXFRM_NSIG_BYTES,
        &il_can0_rxf_fact_insp_ns_rxfrm_data[0],
        NULL
        },
        {
        ( IL_RX_FRM_ATTR_NOTIFY | IL_RX_FRM_ATTR_TIMEOUT ),
        IL_CAN0_RXF_FACT_INSP2_GA_RXFRM_LEN,
        IL_CAN0_RXF_FACT_INSP2_GA_RXFRM_MIN_LEN,
        &il_can0_rxf_fact_insp2_ga_rxfrm_init_data[0],
        &il_can0_rxf_fact_insp2_ga_rxfrm_sig_list[0],
        IL_CAN0_RXF_FACT_INSP2_GA_RXFRM_NSIGS,
        IL_CAN0_RXF_FACT_INSP2_GA_RXFRM_NSIG_BYTES,
        &il_can0_rxf_fact_insp2_ga_rxfrm_data[0],
        NULL
        }
    };


/*------------------------------------------------------
CAN0 Receive Frame Status
------------------------------------------------------*/
static uint8
il_can0_rxfrm_status[IL_CAN0_RX_NUM_FRAMES];


static il_rxfrm_info_t const
il_can0_rxfrm_info =
    {
    &il_can0_rxfrm_table[0],
    &il_can0_rxfrm_status[0],
    IL_CAN0_RX_NUM_FRAMES
    };


/*------------------------------------------------------
Table pointers for external access to transmitted and
received signal and frame information
------------------------------------------------------*/
static il_txsig_info_t const * const
il_can_txsig_info_ptr[CAN_NUM_INSTANCES] =
    {
    &il_can0_txsig_info
    };

static il_txfrm_info_t const * const
il_can_txfrm_info_ptr[CAN_NUM_INSTANCES] =
    {
    &il_can0_txfrm_info
    };

static il_rxsig_info_t const * const
il_can_rxsig_info_ptr[CAN_NUM_INSTANCES] =
    {
    &il_can0_rxsig_info
    };

static il_rxfrm_info_t const * const
il_can_rxfrm_info_ptr[CAN_NUM_INSTANCES] =
    {
    &il_can0_rxfrm_info
    };

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/


/*!*******************************************************************
*
* @private
* get transmit signal information
*
* This function returns a pointer to application transmit signal
* information that is included in the data structures in this file.
*
* @return il_txsig_info_t const *
* pointer to transmit signal information
*********************************************************************/

il_txsig_info_t const *
il_get_txsig_info_ptr
    (
    can_hw_inst_t   const hw_inst           //!< [in] CAN hardware instance
    )
{
return  il_can_txsig_info_ptr[hw_inst];
}


/*!*******************************************************************
*
* @private
* get transmit frame information
*
* This function returns a pointer to application transmit frame
* information that is included in the data structures in this file.
*
* @return il_txfrm_info_t const *
* pointer to transmit frame information
*********************************************************************/

il_txfrm_info_t const *
il_get_txfrm_info_ptr
    (
    can_hw_inst_t   const hw_inst           //!< [in] CAN hardware instance
    )
{
return  il_can_txfrm_info_ptr[hw_inst];
}


/*!*******************************************************************
*
* @private
* get receive signal information
*
* This function returns a pointer to application receive signal
* information that is included in the data structures in this file.
*
* @return il_rxsig_info_t const *
* pointer to receive signal information
*********************************************************************/

il_rxsig_info_t const *
il_get_rxsig_info_ptr
    (
    can_hw_inst_t   const hw_inst           //!< [in] CAN hardware instance
    )
{
return  il_can_rxsig_info_ptr[hw_inst];
}


/*!*******************************************************************
*
* @private
* get receive frame information
*
* This function returns a pointer to application receive frame
* information that is included in the data structures in this file.
*
* @return il_rxfrm_info_t const *
* pointer to receive frame information
*********************************************************************/

il_rxfrm_info_t const *
il_get_rxfrm_info_ptr
    (
    can_hw_inst_t   const hw_inst           //!< [in] CAN hardware instance
    )
{
return  il_can_rxfrm_info_ptr[hw_inst];
}

/*!*******************************************************************
*
* @}
*
*********************************************************************/
