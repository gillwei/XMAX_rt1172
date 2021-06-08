/*********************************************************************
* @file
* test_tacho_speed.c
*
* @brief
* Test module - tacho visualizer & speed visualizer
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "fsl_debug_console.h"
#include "TEST_pub.h"
#include "test_priv.h"
#include "test_meter_bbw_yc.h"
#include "CAN_pub.h"
#include "VI_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define TEST_ENGINE_SPEED_MAX           ( 16000 )
#define ENGINE_SPEED_STEP               ( 23 )
#define ENGINE_SPEED_FACTOR             256 / 100
#define APS_ANGLE_MAX                   ( 125 )
#define APS_ANGLE_STEP                  ( 1 )
#define APS_ANGLE_FACTOR                1024 / 125
#define VVA_INDICATOR_VAL               ( 1 )

/* generate test data if no real meter data not defined */
#if( UNIT_TEST_TACHO_SPEED )
    #if( 0 == TEST_METER_DATA_BBW_YC )
        #define TEST_METER_DATA_GENERATOR   ( 1 )
    #endif
#endif

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef enum
    {
    TEST_DATA_TREND_INCREASING,
    TEST_DATA_TREND_DECREASING
    } test_data_trend_e;

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
#if( UNIT_TEST_TACHO_SPEED )
    #if( TEST_METER_DATA_GENERATOR )
        static uint32_t  vva_indicator = 0;
        static int32_t   engine_speed = 0;   /* CAN message H'20A, factor 100/256   range 0 - 25600 */
        static uint32_t  aps_angle = 0;      /* CAN message H'5BA, factor 125/1024, range 0 - 125 */
        static bool      engine_speed_trend = TEST_DATA_TREND_INCREASING;
    #elif( TEST_METER_DATA_BBW_YC )
        static int32_t   meter_data_idx;
    #endif
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
#if( UNIT_TEST_TACHO_SPEED )
    /*********************************************************************
    *
    * @public
    * test_tacho_speed_proc
    *
    * Test module - tacho/speed visualizer test process
    *
    *********************************************************************/
    void test_tacho_speed_proc
        (
        void
        )
    {
    #if( TEST_METER_DATA_GENERATOR )
        VI_notify_vehicle_cyc_frm_changed( IL_CAN0_RX0_ECU_INDCT_STAT_IDX, IL_CAN0_ECU_INDCT_EG_SPD_RXSIG_HANDLE, engine_speed * ENGINE_SPEED_FACTOR );
        VI_notify_vehicle_cyc_frm_changed( IL_CAN0_RXA_VEHICLE_INFO_2_IDX, IL_CAN0_VEHICLE_INFO_2_APS_ANG_TRAN_RXSIG_HANDLE, aps_angle * APS_ANGLE_FACTOR );

        if( TEST_DATA_TREND_INCREASING == engine_speed_trend )
            {
            engine_speed += ENGINE_SPEED_STEP;
            if( TEST_ENGINE_SPEED_MAX < engine_speed )
                {
                engine_speed = TEST_ENGINE_SPEED_MAX;
                engine_speed_trend = TEST_DATA_TREND_DECREASING;

                /* toggle VVA indicator */
                if( VVA_INDICATOR_VAL == vva_indicator )
                    {
                    vva_indicator = 0;
                    }
                else
                    {
                    vva_indicator = VVA_INDICATOR_VAL;
                    }
                VI_notify_vehicle_cyc_frm_changed( IL_CAN0_RX1_ECU_COM_DATA_IDX, IL_CAN0_ECU_COM_DATA_RXSIG_HANDLE, vva_indicator );
                }
            }
        else
            {
            engine_speed -= ENGINE_SPEED_STEP;
            if( engine_speed < 0 )
                {
                engine_speed = 0;
                engine_speed_trend = TEST_DATA_TREND_INCREASING;
                }
            }

        aps_angle += APS_ANGLE_STEP;
        if( APS_ANGLE_MAX < aps_angle )
            {
            aps_angle -= APS_ANGLE_MAX;
            }
    #elif( TEST_METER_DATA_BBW_YC )
        VI_notify_vehicle_cyc_frm_changed( IL_CAN0_RX0_ECU_INDCT_STAT_IDX,
                                           IL_CAN0_ECU_INDCT_EG_SPD_RXSIG_HANDLE,
                                           meter_data_bbw_yc[meter_data_idx].engine_speed );
        VI_notify_vehicle_cyc_frm_changed( IL_CAN0_RXA_VEHICLE_INFO_2_IDX,
                                           IL_CAN0_VEHICLE_INFO_2_APS_ANG_TRAN_RXSIG_HANDLE,
                                           meter_data_bbw_yc[meter_data_idx].aps_angle );
        VI_notify_vehicle_cyc_frm_changed( IL_CAN0_RXA_VEHICLE_INFO_2_IDX,
                                           IL_CAN0_VEHICLE_INFO_2_SPD_REAL_RXSIG_HANDLE,
                                           meter_data_bbw_yc[meter_data_idx].vehicle_speed );
        VI_notify_vehicle_cyc_frm_changed( IL_CAN0_RXA_VEHICLE_INFO_2_IDX,
                                           IL_CAN0_VEHICLE_INFO_2_SPD_REAL_MT_RXSIG_HANDLE,
                                           meter_data_bbw_yc[meter_data_idx].vehicle_speed );

        meter_data_idx++;
        if( TEST_METER_DATA_BBW_YC_NUM <= meter_data_idx )
            {
            meter_data_idx = 0;
            }
    #else
        /* empty */
    #endif
    }

    /*********************************************************************
    *
    * @public
    * test_tacho_speed_int
    *
    * Test module - init tacho/speed visualizer test
    *
    *********************************************************************/
    void test_tacho_speed_int
        (
        void
        )
    {
    /* empty */
    }
#endif
