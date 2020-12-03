/*********************************************************************
* @file
* factory_test.h
*
* @brief
* factory test - public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef FACTORY_TEST_H
#define FACTORY_TEST_H

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "can_defs.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define firstCanDataLength  6
#define otherCanDataLength  7

#define ADC_CHANNEL_NUM_TFT_TEMP      ( 5U )                       // ADC1_CH5A TFT TEMP
#define ADC_CHANNEL_NUM_PCBA_TEMP     ( 3U )                       // ADC1_CH3A PCBA TEMP
#define ADC_CHANNEL_NUM_VBATT_SEN     ( 0U )                       // ADC1_CH0B VBATT SENSE

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/

typedef uint8 IOP_set_BurnIn_state_type; enum
    {
    IOP_BURNIN_STATE_NONE,
    IOP_BURNIN_STATE_SET,
    IOP_BURNIN_STATE_VALID,

    IOP_BURNIN_STATE_CNT
    };

typedef uint8 IOP_BurnIn_op_stage_type; enum
    {
    IOP_BURNIN_STAGE_NOT_START,
    IOP_BURNIN_STAGE_START,
    IOP_BURNIN_STAGE_RUNNING,
    IOP_BURNIN_STAGE_FAIL,
    IOP_BURNIN_STAGE_PASS,

    IOP_BURNIN_STAGE_CNT
    };

typedef uint8 IOP_esn_op; enum
    {
    IOP_ESN_OP_WRITE,
    IOP_ESN_OP_READ,

    IOP_ESN_OP_INVALID,
    IOP_ESN_OP_CNT = IOP_ESN_OP_INVALID,
    };

typedef enum
    {
    PORT_0,
    PORT_1,
    PORT_2,
    PORT_3,
    PORT_4,
    PORT_5,
    PORT_6,
    PORT_7,
    PORT_8,
    PORT_9,
    PORT_10,
    PORT_11,
    PORT_12,
    PORT_13,

    PORT_MAX,
    } t_Port;

typedef uint8 IOP_SYC_MODE_TYPE; enum
    {
    SYC_MODE_NORMAL = 0,
    SYC_MODE_TEST   = 3,

    SYC_MODE_INVALID,
    SYC_MODE_CNT = SYC_MODE_INVALID,
    };

typedef uint8 IOP_REQ_AUTO_BURN_IN_TYPE; enum
    {
    IOP_REQ_AUTO_BURN_IN_MODE,
    IOP_REQ_AUTO_BURN_IN_TIME,

    IOP_REQ_AUTO_BURN_IN_INVALID,
    IOP_REQ_AUTO_BURN_IN_CNT = IOP_REQ_AUTO_BURN_IN_INVALID,
    };

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

void ft_hook_receive
    (
    // can_hw_inst_t       const hw_inst, //!< [in] CAN hardware instance
    can_rmd_t   const * const p_rmd    //!< [in] pointer to received message
    );

void FACTORY_init
    (
    void
    );

#ifdef __cplusplus
}
#endif

#endif /* FACTORY_TEST_H */

