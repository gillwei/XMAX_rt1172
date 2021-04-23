/*********************************************************************
* @file
* peripheral_gpio.c
*
* Brief peripheral gpio interface for some simple gpio operation
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "pin_mux.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"

#include "PERIPHERAL_pub.h"
#include "peripheral_priv.h"
#include "GRM_pub_prj.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define BIT_24_DATA_LEN         ( 3 )
#define BIT_16_DATA_LEN         ( 2 )
#define BIT_8_DATA_LEN          ( 1 )

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
static uint8_t board_hw_id      = HW_ID_DEFAULT;
static uint8_t board_sku_id     = SKU_ID_DEFAULT;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*********************************************************************
*
* @public
* gpio_init
*
* @brief Initialization of the gpio related function.
*
*********************************************************************/
void gpio_init
    (
    void
    )
{
uint8_t hw_id_dec[4]    = { 0 };
uint8_t sku_id_dec[4]   = { 0 };

hw_id_dec[0] = GPIO_PinRead( BOARD_INITPINS_HW_ID3_GPIO, BOARD_INITPINS_HW_ID3_GPIO_PIN );
hw_id_dec[1] = GPIO_PinRead( BOARD_INITPINS_HW_ID2_GPIO, BOARD_INITPINS_HW_ID2_GPIO_PIN );
hw_id_dec[2] = GPIO_PinRead( BOARD_INITPINS_HW_ID1_GPIO, BOARD_INITPINS_HW_ID1_GPIO_PIN );
hw_id_dec[3] = GPIO_PinRead( BOARD_INITPINS_HW_ID0_GPIO, BOARD_INITPINS_HW_ID0_GPIO_PIN );

sku_id_dec[0] = GPIO_PinRead( BOARD_INITPINS_SKU_ID3_GPIO, BOARD_INITPINS_SKU_ID3_GPIO_PIN );
sku_id_dec[1] = GPIO_PinRead( BOARD_INITPINS_SKU_ID2_GPIO, BOARD_INITPINS_SKU_ID2_GPIO_PIN );
sku_id_dec[2] = GPIO_PinRead( BOARD_INITPINS_SKU_ID1_GPIO, BOARD_INITPINS_SKU_ID1_GPIO_PIN );
sku_id_dec[3] = GPIO_PinRead( BOARD_INITPINS_SKU_ID0_GPIO, BOARD_INITPINS_SKU_ID0_GPIO_PIN );


board_hw_id  = ( hw_id_dec[0] << BIT_24_DATA_LEN ) +
               ( hw_id_dec[1] << BIT_16_DATA_LEN ) +
               ( hw_id_dec[2] << BIT_8_DATA_LEN  ) +
               ( hw_id_dec[3] );

board_sku_id = ( sku_id_dec[0] << BIT_24_DATA_LEN ) +
               ( sku_id_dec[1] << BIT_16_DATA_LEN ) +
               ( sku_id_dec[2] << BIT_8_DATA_LEN  ) +
               ( sku_id_dec[3] );

PRINTF( "Board HW ID = %d, SKU ID = %d\n\r", board_hw_id, board_sku_id );
}

/*********************************************************************
*
* @public
* PERIPHERAL_get_hw_id
*
* @brief public function to get hw id in decimal
*
*********************************************************************/
uint8_t PERIPHERAL_get_hw_id
    (
    void
    )
{
return board_hw_id;
}

/*********************************************************************
*
* @public
* PERIPHERAL_get_sku_id
*
* @brief public function to get sku id in decimal
*
*********************************************************************/
uint8_t PERIPHERAL_get_sku_id
    (
    void
    )
{
return board_sku_id;
}
