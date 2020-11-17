/*********************************************************************
* @file  PERIPHERAL_pub.h
* @brief peripheral Interface public header file
*
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef PERIPHERAL_PUB_H
#define PERIPHERAL_PUB_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "fsl_common.h"
#include "FreeRTOSConfig.h"
#include "projdefs.h"
#include "portmacro.h"


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
BaseType_t PERIPHERAL_uart_tx_data
    (
    uint32_t const len,
    uint8_t  const* const data_ptr
    );

void PERIPHERAL_uart_port_reconfig
    (
    bool enable_cts,
    bool enable_rts,
    uint32_t baud_rate
    );

int PERIPHERAL_adc_get_tft_ntc
    (
    void
    );

int PERIPHERAL_adc_get_tft_ntc_converted
    (
    void
    );

int PERIPHERAL_adc_get_pcba_ntc
    (
    void
    );

int PERIPHERAL_adc_get_pcba_ntc_converted
    (
    void
    );

int PERIPHERAL_adc_get_vbatt
    (
    void
    );

int PERIPHERAL_adc_get_vbatt_converted
    (
    void
    );

void PERIPHERAL_pwm_set_display_dutycycle
    (
    uint8_t duty_cycle
    );

void PERIPHERAL_init
    (
    void
    );

void PERIPHERAL_i2c_write_data
    (
    uint8_t  device_addr,
    uint8_t* data,
    uint16_t size,
    uint16_t sub_addr,
    uint16_t subaddr_size,
    void ( *callback_func_ptr ) ( status_t )
    );

void PERIPHERAL_i2c_read_data
    (
    uint8_t  device_addr,
    uint8_t* data,
    uint16_t size,
    uint16_t sub_addr,
    uint16_t subaddr_size,
    void ( *callback_func_ptr ) ( status_t )
    );

#ifdef __cplusplus
}
#endif


#endif /*PERIPHERAL_PUB_H*/
