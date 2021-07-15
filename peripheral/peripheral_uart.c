/*******************************************************************************
*@ File peripheral_uart.c
*@ Brief Uart interface for Uart Application
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
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
//#include "JPEGPARSER_pub.h"
#include "PERIPHERAL_pub.h"
#include "peripheral_priv.h"
#include "GRM_pub_prj.h"
#include "hci_tsk.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/
#define UART_IRQ_handler  LPUART7_IRQHandler
#define UART_PORT         ( LPUART7 )
#define UART_IRQ          ( LPUART7_IRQn )
/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define UART_DMAMUX_BASEADDR      ( DMAMUX0 )
#define UART_DMA_BASEADDR         ( DMA0 )

#define UART_PORT_BAUDRATE       ( 3000000 )
#define UART_TX_DMA_CHANNEL      ( 0U )
#define UART_TX_DMA_REQUEST      ( kDmaRequestMuxLPUART7Tx )

/* UART RX buffer */
#define UART_RX_BUFFER_NOM_SIZE   ( 1024 * 64 )
#define UART_RX_BUFFER_SIZE       ( UART_RX_BUFFER_NOM_SIZE - 1 )
#define UART_RX_CYCLE_CALC(x)     ( (x) & UART_RX_BUFFER_SIZE )

/* UART TX buffer */
#define UART_TX_BUFFER_NOM_SIZE   ( 1024 * 8 )
#define UART_TX_BUFFER_SIZE       ( UART_TX_BUFFER_NOM_SIZE - 1 )
#define UART_TX_CYCLE_CALC(x)     ( (x) & UART_TX_BUFFER_SIZE )
/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef struct
    {
    edma_handle_t        tx_edmaHandle;
    lpuart_edma_handle_t edma_Handle;
    } uart_edma_data_type;

typedef struct
    {
    uint8_t*             rx_buffer_ptr;
    uint32_t             rxHead;
    uint32_t             rxTail;

    uint8_t*             tx_buffer_ptr;
    uint32_t             txHead;
    uint32_t             txTail;
    } uart_data_type;
/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/


/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
static uart_data_type           uart_data;
static uart_edma_data_type      uart_edma_data;
static BaseType_t               tx_on_going = pdFALSE;
static TickType_t               task_delay   = pdMS_TO_TICKS( 10 );
static TaskHandle_t             uartTaskHandle;

AT_NONCACHEABLE_SECTION(uint8_t rx_Buffer[UART_RX_BUFFER_NOM_SIZE]);
AT_NONCACHEABLE_SECTION(uint8_t tx_Buffer[UART_TX_BUFFER_NOM_SIZE]);
AT_NONCACHEABLE_SECTION(uint8_t rx_temp[UART_TX_BUFFER_NOM_SIZE]);
AT_NONCACHEABLE_SECTION(uint8_t tx_temp[UART_TX_BUFFER_NOM_SIZE]);

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/
static void uart_main
    (
    void* arg
    );

static void uart_create_task
    (
    void
    );

static void uart_data_init
    (
    void
    );

static void uart_port_init
    (
    void
    );

static void uart_dma_mux_init
    (
    void
    );

static void uart_edma_init
    (
    void
    );

static uint16_t get_tx_empty_size
    (
    void
    );

static void uart_edma_callback
    (
    LPUART_Type* base,
    lpuart_edma_handle_t* handle,
    status_t status,
    void* data
    );

static void uart_send
    (
    lpuart_edma_handle_t* handle,
    uint8_t* data_ptr,
    size_t data_size
    );

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/

/*================================================================================================*/
/**
@brief   uart_create_task
@details Create BT uart main task for tx rx BT module data

@return None
@retval None
*/
/*================================================================================================*/
void uart_create_task
    (
    void
    )
{
if( pdPASS == xTaskCreate( uart_main, "uart_main", ( configMINIMAL_STACK_SIZE * 4 ), NULL, TASK_PRIO_UART, &uartTaskHandle ) )
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
@brief   Get Tx empty size
@details

@return None
@retval None

@pre None
@post None
*/
/*================================================================================================*/
static uint16_t get_tx_empty_size
    (
    void
    )
{
return ( UART_TX_BUFFER_SIZE - UART_TX_CYCLE_CALC( uart_data.txTail - uart_data.txHead ) );
}

/*================================================================================================*/
/**
@brief    UART IRQ handler
@details

@return None
@retval None

@pre None
@post None
*/
/*================================================================================================*/
void UART_IRQ_handler
    (
    void
    )
{
if( ( kLPUART_RxDataRegFullFlag ) & LPUART_GetStatusFlags( UART_PORT ) )
    {
    uint32_t rxSize = UART_RX_CYCLE_CALC( uart_data.rxTail - uart_data.rxHead );
    if( rxSize == UART_RX_BUFFER_SIZE )
        {
        PRINTF( "ERROR OVERFLOW, %d >= %d, hd: %d, tail:%d\r\n", rxSize, UART_RX_BUFFER_SIZE, uart_data.rxHead, uart_data.rxTail );
        }
    uart_data.rx_buffer_ptr[uart_data.rxTail] = LPUART_ReadByte( UART_PORT );
    uart_data.rxTail = UART_RX_CYCLE_CALC( uart_data.rxTail + 1 );
    }
}

/*================================================================================================*/
/**
@brief   Setup BT UART ports
@details

Setup UART port8 parameters for BT module

@return None
*/
/*================================================================================================*/

void uart_init
    (
    void
    )
{
uart_data_init();
uart_port_init();
uart_dma_mux_init();
uart_edma_init();
uart_create_task();
}

/*================================================================================================*/
/**
@brief   Init UART data
@details

@return None
@retval None
*/
/*================================================================================================*/
static void uart_data_init
    (
    void
    )
{
memset( &uart_data, 0, sizeof( uart_data_type ) );
uart_data.rx_buffer_ptr = rx_Buffer;
uart_data.tx_buffer_ptr = tx_Buffer;
}

/*================================================================================================*/
/**
@brief   Setup UART config and baud rate
@details

@return None
@retval None
*/
/*================================================================================================*/

static void uart_port_init
    (
    void
    )
{
lpuart_config_t lpuartConfig;
LPUART_GetDefaultConfig( &lpuartConfig );

lpuartConfig.baudRate_Bps = UART_PORT_BAUDRATE;
lpuartConfig.enableTx = true;
lpuartConfig.enableRx = true;
lpuartConfig.stopBitCount = kLPUART_OneStopBit;
lpuartConfig.enableRxRTS = true;
lpuartConfig.enableTxCTS = true;
LPUART_Init( UART_PORT, &lpuartConfig, BOARD_DebugConsoleSrcFreq() );
LPUART_EnableInterrupts( UART_PORT, kLPUART_RxDataRegFullInterruptEnable );
EnableIRQ( UART_IRQ );
}

/*================================================================================================*/
/**
@brief   Setup UART dma mux init
@details

@return None
@retval None

@pre None
@post None
*/
/*================================================================================================*/

static void uart_dma_mux_init
    (
    void
    )
{
#if defined(FSL_FEATURE_SOC_DMAMUX_COUNT) && FSL_FEATURE_SOC_DMAMUX_COUNT
    DMAMUX_Init( UART_DMAMUX_BASEADDR );
    DMAMUX_SetSource( UART_DMAMUX_BASEADDR, UART_TX_DMA_CHANNEL, UART_TX_DMA_REQUEST );
    DMAMUX_EnableChannel( UART_DMAMUX_BASEADDR, UART_TX_DMA_CHANNEL );
#endif
}

/*================================================================================================*/
/**
@brief   Setup UART edma init
@details

@return None
@retval None

@pre None
@post None
*/
/*================================================================================================*/

static void uart_edma_init
    (
    void
    )
{
edma_config_t config;
EDMA_GetDefaultConfig( &config );
EDMA_Init( UART_DMA_BASEADDR, &config );
EDMA_CreateHandle( &(uart_edma_data.tx_edmaHandle), UART_DMA_BASEADDR, UART_TX_DMA_CHANNEL );
LPUART_TransferCreateHandleEDMA( UART_PORT, &(uart_edma_data.edma_Handle), uart_edma_callback, &tx_on_going, &(uart_edma_data.tx_edmaHandle), NULL );
}

/*================================================================================================*/
/**
@brief   edma tx call back function
@details
        call after tx edma complete
@return None
@retval None

@pre None
@post None
*/
/*================================================================================================*/

static void uart_edma_callback
    (
    LPUART_Type* base,
    lpuart_edma_handle_t* handle,
    status_t status,
    void* data
    )
{
if ( kStatus_LPUART_TxIdle == status )
    {
    (*(BaseType_t*)data) = pdFALSE;
    }
}

/*================================================================================================*/
/**
@brief   Send UART data
@details

@return None
@retval None

@pre None
@post None
*/
/*================================================================================================*/

static void uart_send
    (
    lpuart_edma_handle_t* handle,
    uint8_t* data_ptr,
    size_t data_size
    )
{
static lpuart_transfer_t xfer;

xfer.data = data_ptr;
xfer.dataSize = data_size;
LPUART_SendEDMA( UART_PORT, handle, &xfer);
}


/*================================================================================================*/
/**
@brief   uart_main
@details

@return None
@retval None
*/
/*================================================================================================*/
static void uart_main
    (
    void* arg
    )
{
while( true )
    {
    uint32_t tmpTail = 0;
    uint32_t rxDataSize = 0;
    uint32_t txDataSize = 0;

    /* Process RX */
    tmpTail = uart_data.rxTail;
    if( uart_data.rxHead != tmpTail )
        {
        if( tmpTail > uart_data.rxHead )
            {
            rxDataSize = tmpTail - uart_data.rxHead;
            HCI_tsk_send_event( &uart_data.rx_buffer_ptr[uart_data.rxHead], rxDataSize );
            }
        else
            {
            rxDataSize = UART_RX_BUFFER_NOM_SIZE - uart_data.rxHead;
            memcpy( rx_temp, &(uart_data.rx_buffer_ptr[uart_data.rxHead]), rxDataSize );

            memcpy( &(rx_temp[rxDataSize]), uart_data.rx_buffer_ptr, tmpTail );
            rxDataSize += tmpTail;

            HCI_tsk_send_event( rx_temp, rxDataSize );
            }
        uart_data.rxHead = tmpTail;
        }

    /* process TX */
    tmpTail = uart_data.txTail;
    if( !tx_on_going )
        {
        if( uart_data.txHead != tmpTail )
            {
            tx_on_going = pdTRUE;
            if( tmpTail > uart_data.txHead )
                {
                txDataSize = tmpTail - uart_data.txHead;
                uart_send( &(uart_edma_data.edma_Handle), &(uart_data.tx_buffer_ptr[uart_data.txHead]), txDataSize );
                }
            else
                {
                txDataSize = UART_TX_BUFFER_NOM_SIZE - uart_data.txHead;
                memcpy( tx_temp, &(uart_data.tx_buffer_ptr[uart_data.txHead]), txDataSize );

                memcpy( &(tx_temp[txDataSize]), uart_data.tx_buffer_ptr, tmpTail );
                txDataSize += tmpTail;

                uart_send( &(uart_edma_data.edma_Handle), tx_temp, txDataSize );
                }
            uart_data.txHead = tmpTail;
            }
        }
    vTaskDelay( task_delay );
    }

vTaskDelete( NULL );
}

/*================================================================================================*/
/**
@brief   UART_tx_data
@details

@return None
@retval None

@pre None
@post None
*/
/*================================================================================================*/

BaseType_t PERIPHERAL_uart_tx_data
    (
    uint32_t const len,
    uint8_t  const* const data_ptr
    )
{
uint32_t idx = 0;
BaseType_t rtn = false;

if( data_ptr )
    {
    if( get_tx_empty_size() > len )
        {
        for( idx=0; idx < len; idx++ )
            {
            uart_data.tx_buffer_ptr[uart_data.txTail] = data_ptr[idx];
            uart_data.txTail = UART_TX_CYCLE_CALC( uart_data.txTail + 1 );
            }
        rtn = true;
        }
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   PERIPHERAL_uart_port_reconfig
@details

@return None
@retval None

@pre None
@post None
*/
/*================================================================================================*/
void PERIPHERAL_uart_port_reconfig
    (
    bool enable_cts,
    bool enable_rts,
    uint32_t baud_rate
    )
{
lpuart_config_t lpuartConfig;

//Clean up
vTaskSuspend( uartTaskHandle );
DisableIRQ( UART_IRQ );
LPUART_DisableInterrupts( UART_PORT, kLPUART_RxDataRegFullInterruptEnable );
uart_data_init();

LPUART_GetDefaultConfig( &lpuartConfig );
lpuartConfig.baudRate_Bps = baud_rate;
lpuartConfig.enableTx = true;
lpuartConfig.enableRx = true;
lpuartConfig.stopBitCount = kLPUART_OneStopBit;
lpuartConfig.enableRxRTS = enable_rts;
lpuartConfig.enableTxCTS = enable_cts;
LPUART_Init( UART_PORT, &lpuartConfig, BOARD_DebugConsoleSrcFreq() );
LPUART_EnableInterrupts( UART_PORT, kLPUART_RxDataRegFullInterruptEnable );
EnableIRQ( UART_IRQ );
vTaskResume( uartTaskHandle );
}
#ifdef __cplusplus
}
#endif
