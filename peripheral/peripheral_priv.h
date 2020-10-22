/*********************************************************************
* @file  peripheral_priv.h
* @brief peripheral Interface private header file
*
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef PERIPHERAL_PRIV_H
#define PERIPHERAL_PRIV_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "board.h"
#include "fsl_lpuart_edma.h"
#if defined(FSL_FEATURE_SOC_DMAMUX_COUNT) && FSL_FEATURE_SOC_DMAMUX_COUNT
    #include "fsl_dmamux.h"
#endif
#include "pin_mux.h"
#include "clock_config.h"

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/

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
void uart_init
    (
    void
    );

void adc_init
    (
    void
    );

void i2c_init
    (
    void
    );

void pwm_init
    (
    void
    );

#ifdef __cplusplus
}
#endif


#endif /*PERIPHERAL_PRIV_H*/
