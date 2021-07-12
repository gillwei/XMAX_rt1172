/*********************************************************************
* @file  bt_hw.c
* @brief Bluetooth Manager Hardware control interface definition.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <FreeRTOS.h>
#include <task.h>

#include "fsl_gpio.h"
#include "fsl_iomuxc.h"
#include "GRM_pub_prj.h"
#include "PERIPHERAL_pub.h"
#include "pin_mux.h"

#include "bt_hw.h"
#include "bt_log.h"
#include "bt_utils.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define HW_ON_OFF_OPERATION_MS ( 50 )

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/
static const uint32_t s_uart_baudrate_values[] =
    {
    /* BT_UART_BAUDRATE_115200 */ 115200,
    /* BT_UART_BAUDRATE_3M     */ 3000000
    };

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Configure BT UART settings including flow control and baudrate
@details Configure BT UART settings including flow control and baudrate
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_hw_config_uart
    (
    const bool flow_control,
    const BT_uart_baudrate_e baudrate
    )
{
if( ( baudrate < 0 ) || ( baudrate >= BT_UART_BAUDRATE_INVALID ) )
    {
    BT_LOG_ERROR( "Invalid uart baudrate: %d", baudrate );
    return false;
    }

if( flow_control )
    {
    PERIPHERAL_uart_port_reconfig( true, true, s_uart_baudrate_values[baudrate] );
    }
else
    {
    PERIPHERAL_uart_port_reconfig( false, false, s_uart_baudrate_values[baudrate] );
    }

BT_LOG_INFO( "UART config: flow_control=%d, baudrate=%u", flow_control, s_uart_baudrate_values[baudrate] );
return true;
}

/*================================================================================================
@brief   Pull BT_RST_N pin low to turn the BT hardware off
@details Pull BT_RST_N pin low to turn the BT hardware off
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_hw_off( void )
{
uint8_t hw_id = PERIPHERAL_get_hw_id();

if( hw_id < HW_ID_2_RT1172 )
    {
    GPIO_PinWrite( BOARD_INITPINS_BT_RST_N_PERIPHERAL, BOARD_INITPINS_BT_RST_N_CHANNEL, 0 );
    }
else
    {
    GPIO_PinWrite( BOARD_INITPINS_BT_RST_N_2_PERIPHERAL, BOARD_INITPINS_BT_RST_N_2_CHANNEL, 0 );
    }
vTaskDelay( pdMS_TO_TICKS( HW_ON_OFF_OPERATION_MS ) );

BT_LOG_INFO( "Powered off" );
return true;
}

/*================================================================================================
@brief   Pull BT_RST_N pin high to turn the BT hardware on in normal or download mode
@details Pull BT_RST_N pin high to turn the BT hardware on, before this:
           - Pull MCU's BT_UART_RTS pin high to run in normal mode
           - Pull MCU's BT_UART_RTS pin low to run in download mode
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_hw_on
    (
    const BT_hw_mode_e mode
    )
{
uint8_t hw_id = PERIPHERAL_get_hw_id();
gpio_pin_config_t pin_config = { kGPIO_DigitalOutput, 0, kGPIO_NoIntmode };

if( ( mode < 0 ) || ( mode >= BT_HW_MODE_INVALID ) )
    {
    BT_LOG_ERROR( "Invalid HW mode: %d", mode );
    return false;
    }

// Configure GPIO_AD_03 to GPIO
IOMUXC_SetPinMux( IOMUXC_GPIO_AD_03_GPIO9_IO02, 0 );
GPIO_PinInit( GPIO9, 2, &pin_config );

if( BT_HW_MODE_NORMAL == mode )
    {
    BT_hw_config_uart( false, BT_UART_BAUDRATE_3M );
    GPIO_PinWrite( GPIO9, 2, 1 );
    }
else if( BT_HW_MODE_DOWNLOAD == mode )
    {
    BT_hw_config_uart( false, BT_UART_BAUDRATE_115200 );
    GPIO_PinWrite( GPIO9, 2, 0 );
    }

if( hw_id < HW_ID_2_RT1172 )
    {
    GPIO_PinWrite( BOARD_INITPINS_BT_RST_N_PERIPHERAL, BOARD_INITPINS_BT_RST_N_CHANNEL, 1 );
    }
else
    {
    GPIO_PinWrite( BOARD_INITPINS_BT_RST_N_2_PERIPHERAL, BOARD_INITPINS_BT_RST_N_2_CHANNEL, 1 );
    }
vTaskDelay( pdMS_TO_TICKS( HW_ON_OFF_OPERATION_MS ) );

if( BT_HW_MODE_DOWNLOAD == mode )
    {
    GPIO_PinWrite( GPIO9, 2, 1 );
    }

// Configure GPIO_AD_03 to UART RTS
IOMUXC_SetPinMux( IOMUXC_GPIO_AD_03_LPUART7_RTS_B, 0 );

if( BT_HW_MODE_NORMAL == mode )
    {
    BT_hw_config_uart( true, BT_UART_BAUDRATE_3M );
    }
else if( BT_HW_MODE_DOWNLOAD == mode )
    {
    BT_hw_config_uart( true, BT_UART_BAUDRATE_115200 );
    }

BT_LOG_INFO( "Powered on: mode=%s", BT_util_get_hw_mode_string( mode ) );
return true;
}

#ifdef __cplusplus
}
#endif
