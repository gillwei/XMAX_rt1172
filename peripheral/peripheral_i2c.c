/*******************************************************************************
*@ File peripheral_i2c.c
*@ Brief Uart interface for i2c Application
*
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
********************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "fsl_lpi2c.h"
#include "fsl_debug_console.h"
#include "PERIPHERAL_pub.h"
#include "peripheral_priv.h"
#include "GRM_pub_prj.h"
/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/
#define LPI2C_MASTER_BASEADDR   ( LPI2C1 )
#define LPI2C_BAUDRATE          ( 100000U )
#define LPI2C_CLOCK             ( BOARD_BOOTCLOCKRUN_LPI2C1_CLK_ROOT )
#define LPI2C_SIZE_OF_QUEUE     ( 8 )
/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef struct
    {
    lpi2c_master_transfer_t masterXfer;
    void ( *callback_func_ptr ) ( status_t );
    } i2c_xfter_data_type;

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/


/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
static QueueHandle_t            i2c_queue;
static TickType_t               i2c_task_delay            = pdMS_TO_TICKS( 5 );
/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/
static void i2c_create_task
    (
    void
    );

static void i2c_main
    (
    void* arg
    );

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/

/*================================================================================================*/
/**
@brief   PERIPHERAL_i2c_write_data
@details

PERIPHERAL_i2c_write_data

@return None
*/
/*================================================================================================*/
void PERIPHERAL_i2c_write_data
    (
    uint8_t  device_addr,
    uint8_t* data,
    uint16_t size,
    uint16_t sub_addr,
    uint16_t subaddr_size,
    void ( *callback_func_ptr ) ( status_t )
    )
{
i2c_xfter_data_type xfer_data = {0};

xfer_data.masterXfer.slaveAddress = device_addr;
xfer_data.masterXfer.direction = kLPI2C_Write;
xfer_data.masterXfer.subaddress = sub_addr;
xfer_data.masterXfer.subaddressSize = subaddr_size;
xfer_data.masterXfer.data = data;
xfer_data.masterXfer.dataSize = size;
xfer_data.masterXfer.flags = kLPI2C_TransferDefaultFlag;
xfer_data.callback_func_ptr = callback_func_ptr;

xQueueSend( i2c_queue, &xfer_data, 0 );
}

/*================================================================================================*/
/**
@brief   PERIPHERAL_i2c_read_data
@details

PERIPHERAL_i2c_read_data

@return None
*/
/*================================================================================================*/
void PERIPHERAL_i2c_read_data
    (
    uint8_t  device_addr,
    uint8_t* data,
    uint16_t size,
    uint16_t sub_addr,
    uint16_t subaddr_size,
    void ( *callback_func_ptr ) ( status_t )
    )
{
i2c_xfter_data_type xfer_data = {0};

xfer_data.masterXfer.slaveAddress = device_addr;
xfer_data.masterXfer.direction = kLPI2C_Read;
xfer_data.masterXfer.subaddress = sub_addr;
xfer_data.masterXfer.subaddressSize = subaddr_size;
xfer_data.masterXfer.data = data;
xfer_data.masterXfer.dataSize = size;
xfer_data.masterXfer.flags = kLPI2C_TransferDefaultFlag;
xfer_data.callback_func_ptr = callback_func_ptr;

xQueueSend( i2c_queue, &xfer_data, 0 );
}

/*================================================================================================*/
/**
@brief   i2c_init
@details

Setup I2C module

@return None
*/
/*================================================================================================*/

void i2c_init
    (
    void
    )
{
lpi2c_master_config_t masterConfig = {0};

LPI2C_MasterGetDefaultConfig( &masterConfig );
masterConfig.baudRate_Hz = LPI2C_BAUDRATE;
LPI2C_MasterInit( LPI2C_MASTER_BASEADDR, &masterConfig, LPI2C_CLOCK );
i2c_queue = xQueueCreate( LPI2C_SIZE_OF_QUEUE, sizeof( i2c_xfter_data_type ) );
i2c_create_task();
}

/*================================================================================================*/
/**
@brief   i2c_create_task
@details Create iic  main task for tx rx iic data

@return None
@retval None
*/
/*================================================================================================*/
static void i2c_create_task
    (
    void
    )
{
if( pdPASS == xTaskCreate( i2c_main, "i2c_main", ( configMINIMAL_STACK_SIZE * 4 ), NULL, TASK_PRIO_I2C, NULL ) )
    {
    PRINTF("%s ok\r\n", __FUNCTION__ );
    }
else
    {
    PRINTF("%s fail\r\n", __FUNCTION__ );
    }
}
/*================================================================================================*/
/**
@brief   i2c_main
@details i2c_main

@return None
@retval None
*/
/*================================================================================================*/
static void i2c_main
    (
    void* arg
    )
{
i2c_xfter_data_type xfer_data = {0};
status_t rtn_val = kStatus_Fail;

while( true )
    {
    if( pdPASS == xQueueReceive( i2c_queue, (void *)&xfer_data, 0 ) )
       {
        rtn_val = LPI2C_MasterTransferBlocking( LPI2C_MASTER_BASEADDR, &( xfer_data.masterXfer ) );
        xfer_data.callback_func_ptr( rtn_val );
        }
    vTaskDelay( i2c_task_delay );
    }
vTaskDelete( NULL );
}

#ifdef __cplusplus
}
#endif

