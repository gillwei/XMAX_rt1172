/*********************************************************************
* @file  bt_hw.h
* @brief Bluetooth Manager Hardware control interface declaration.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _BT_HW_H_
#define _BT_HW_H_

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "bt_types.h"

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef enum BT_hw_mode
    {
    BT_HW_MODE_NORMAL = 0,
    BT_HW_MODE_DOWNLOAD,

    BT_HW_MODE_CNT,
    BT_HW_MODE_INVALID = BT_HW_MODE_CNT
    } BT_hw_mode_e;

typedef enum BT_uart_baudrate
    {
    BT_UART_BAUDRATE_115200 = 0,
    BT_UART_BAUDRATE_3M,

    BT_UART_BAUDRATE_CNT,
    BT_UART_BAUDRATE_INVALID = BT_UART_BAUDRATE_CNT
    } BT_uart_baudrate_e;

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
bool BT_hw_config_uart
    (
    const bool flow_control,
    const BT_uart_baudrate_e baudrate
    );

bool BT_hw_off( void );

bool BT_hw_on
    (
    const BT_hw_mode_e mode
    );

#ifdef __cplusplus
}
#endif

#endif // _BT_HW_H_
