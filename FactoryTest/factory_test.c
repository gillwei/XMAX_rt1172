/*********************************************************************
* @file
* factory_test.c
*
* Brief factory test application
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "board.h"
#include "MIMXRT1176_cm7.h"
#include "clock_config.h"
#include "FreeRTOS.h"
#include "pin_mux.h"
#include "task.h"

#include "fsl_debug_console.h"
#include "PERIPHERAL_pub.h"
#include "GRM_pub_prj.h"
#include "EW_pub.h"
#include "EEPM_pub.h"
#include "RTC_pub.h"

#include "can_cfg.h"
#include "can_drv.h"
#include "can_dll_prv_par.h"
// #include "CAN_nim_ctrl.h"
#include "fsl_flexcan.h"
#include "IOP_pub_inst.h"
#include "IOP_pub_cmnd.h"
#include "IOP_pub_vim_inst_prj.h"

#include "factory_test.h"
// #include "HCI_pub.h"
// #include "BTM_pub.h"
// #include "hci_control_api.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define IOP_VIM_MAX_DATA_SIZE       (200)

#define FT_CAN_DLC         ( 8 )

#define E_OK               ( 0 )
#define E_NOT_OK           ( 1 )

#define STD_HIGH           ( 1u ) /* Physical state 5V or 3.3V */
#define STD_LOW            ( 0u ) /* Physical state 0V */

#define DATA_INVALID       ( 0xFFFF )
#define DATA_INVALID_BYTE  ( 0xFF )

#define BIT_32_DATA_LEN    ( 4 )
#define BIT_24_DATA_LEN    ( 3 )
#define BIT_16_DATA_LEN    ( 2 )
#define BIT_8_DATA_LEN     ( 1 )
#define BURN_IN_TASK_TIME  ( 500 )
#define BURN_IN_QUAL_TIME  ( 8 * 60 * 60 )
#define BURN_IN_QUAL_TEMP  ( 60 * 1000 )

#define IOP_MAX_QUEUE_SIZE ( 100 )
#define IOP_QUEUE_INVALID  ( -1 )

#define ESN_REWRITE_ID     ( 0xFFFFFFFF )
#define ASCII_BYTE_OFFSET  ( 0x30 )
#define LOW_BYTE_MASK      ( 0x00FF )
#define MAX_PIN_NUM        ( 32 )

#define IOP_PRODUCT_HW_ID  ( 0 )
#define IOP_PRODUCT_SKU_ID ( 1 )

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
static uint16_t const product_id = 0x0F70;
static char const product_string[] = { "IXWW22 v Board Version:  006-B3952-00 " };


static uint8_t  recordSequenceId;
static uint8_t  recordDataSize;
static uint8_t  recordData[IOP_VIM_MAX_DATA_SIZE];
static uint8_t  iopDataQueue[IOP_MAX_QUEUE_SIZE][8];
static int8_t   iopDataHead = IOP_QUEUE_INVALID;
static int8_t   iopDataTail = IOP_QUEUE_INVALID;


//IOP proc
static uint16_t       IOPInstId           = 0;
static uint16_t       IOPSubId            = 0;
static uint16_t       IOPCaseId           = 0;
static bool           IOPDone             = TRUE;

//esn
static uint32_t       esn_id              = 0;
static uint32_t       EEPM_esn_id         = 0;
static IOP_esn_op     esn_operation       = IOP_ESN_OP_INVALID;


//temp RX data
static uint8_t      canRxData[8];
static bool         canRxFlag = FALSE;
/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
static void storeCanData
    (
    uint8_t*  canData
    );

static void sendCanData
    (
    void
    );

static void iopToCanData
    (
    uint16_t  iopid,
    uint8_t*  iopRawData,
    uint8_t   iopDataSize
    );

static void packageIopToCanData
    (
    void*  data_ptr,
    uint16_t data_len
    );

static void iopProcInstCmd
    (
    uint16_t  inst_id,
    uint8_t*  data,
    uint16_t  size
    );

static void iopProcVIMCaseCmd
    (
    uint16_t case_id,
    uint8_t* data,
    uint16_t size
    );

static void packageIopData
    (
    uint8_t* rawData
    );

static void CanToIopParser
    (
    const uint8_t* canRawData
    );

static uint8_t setGPIOValue
    (
    uint8_t     port,
    uint8_t     pin,
    uint8_t     val
    );

static uint8_t getGPIOValue
    (
    uint8_t     port,
    uint8_t     pin,
    uint8_t   * output_lvl
    );

static void factory_create_task
    (
    void
    );

static void factory_test_task
    (
    void* arg
    );

static void esn_read_cb
    (
    bool    status,
    void*   data
    );

static void esn_write_cb
    (
    bool    status,
    void*   data
    );

/*********************************************************************
*
* @public
* FACTORY_init
*
* @brief Initial function to public to create factory test task.
*
*
*********************************************************************/

void FACTORY_init
    (
    void
    )
{
factory_create_task();
}

/*********************************************************************
*
* @public
* factory_create_task
*
* @brief function to create factory task
*
*
*********************************************************************/
static void factory_create_task
    (
    void
    )
{
if( pdPASS == xTaskCreate( factory_test_task, "factory_test_task", configMINIMAL_STACK_SIZE*2, NULL, ( tskIDLE_PRIORITY + 4 ), NULL ) )
    {
    PRINTF("%s ok\r\n", __FUNCTION__ );
    }
else
    {
    PRINTF("%s fail\r\n", __FUNCTION__ );
    }
}


/*********************************************************************
*
* @private
* getGPIOValue
*
* @brief function to get GPIO value on given port and pin
*
* @param port gpio port
* @param pin  gpio pin
*
*********************************************************************/
static uint8_t getGPIOValue
    (
    uint8_t     port,
    uint8_t     pin,
    uint8_t   * output_lvl
    )
{
GPIO_Type * gpio;

if( port >= PORT_1 && port <= PORT_6 )
    {
    gpio = ( GPIO_Type * )( GPIO1_BASE + 0x4000 * ( port - PORT_1 ) );
    }
else if( port >= PORT_7 && port <= PORT_12 )
    {
    gpio = ( GPIO_Type * )( GPIO7_BASE + 0x4000 * ( port - PORT_7 ) );
    }
else if( port == PORT_13 )
    {
    gpio = ( GPIO_Type * )( GPIO13_BASE );
    }
else
    {
    return E_NOT_OK;;
    }
if( pin <= MAX_PIN_NUM )
    {
    *output_lvl = ( uint8_t )GPIO_PinRead( gpio, pin );
    return E_OK;
    }
return E_NOT_OK;;
}

/*********************************************************************
*
* @private
* setGPIOValue
*
* @brief function to set GPIO value on given port and pin
*
* @param port gpio port
* @param pin  gpio pin
* @param val  target value to set
*
*********************************************************************/
static uint8_t setGPIOValue
    (
    uint8_t     port,
    uint8_t     pin,
    uint8_t     val
    )
{
GPIO_Type * gpio;

if( port >= PORT_1 && port <= PORT_6 )
    {
    gpio = ( GPIO_Type * )( GPIO1_BASE + 0x4000 * ( port - PORT_1 ) );
    }
else if( port >= PORT_7 && port <= PORT_12 )
    {
    gpio = ( GPIO_Type * )( GPIO7_BASE + 0x4000 * ( port - PORT_7 ) );
    }
else if( port == PORT_13 )
    {
    gpio = ( GPIO_Type * )( GPIO13_BASE );
    }
else
    {
    return E_NOT_OK;;
    }
if( pin <= MAX_PIN_NUM )
    {
    GPIO_PinWrite( gpio, pin, val );
    return E_OK;
    }
return E_NOT_OK;
}

/*********************************************************************
*
* @private
* queueIsFull
*
* @brief function use to check if iop data queue is full or not
*
*********************************************************************/
int queueIsFull
    (
    void
    )
{
if( ( iopDataHead == iopDataTail + 1 ) ||
    ( iopDataHead == 0 && iopDataTail == IOP_MAX_QUEUE_SIZE - 1 ) )
    {
    return true;
    }
return false;
}

/*********************************************************************
*
* @private
* queueIsFull
*
* @brief function use to check if iop data queue is empty or not
*
*********************************************************************/
int queueIsEmpty
    (
    void
    )
{
if( iopDataHead == IOP_QUEUE_INVALID )
    {
    return true;
    }
return false;
}

/*********************************************************************
*
* @private
* storeCanData
*
* @brief function to store CAN data into an queue per request.
*
*********************************************************************/
void storeCanData
    (
    uint8_t*  canData
    )
{
if( !queueIsFull() )
    {
    if( iopDataHead == IOP_QUEUE_INVALID )
        {
        iopDataHead = 0;
        }
    iopDataTail = ( iopDataTail + 1 ) % IOP_MAX_QUEUE_SIZE;
    memcpy( &iopDataQueue[iopDataTail][0], &canData[0], 8 );
    }
}

/*********************************************************************
*
* @private
* sendCanData
*
* @brief function to send CAN data out through CAN bus.
*
*********************************************************************/
void sendCanData
    (
    void
    )
{
flexcan_frame_t frame;
uint8_t temp_can_data[8] = { 0 };

frame.id     = FLEXCAN_ID_STD( FT_REP_CAN_ID );
frame.format = ( uint8_t )kFLEXCAN_FrameFormatStandard;
frame.type   = ( uint8_t )kFLEXCAN_FrameTypeData;
frame.length = ( uint8_t )8;

if( !queueIsEmpty() )
    {
    memcpy( &temp_can_data, &iopDataQueue[iopDataHead], 8 );
    frame.dataByte0 = temp_can_data[0];
    frame.dataByte1 = temp_can_data[1];
    frame.dataByte2 = temp_can_data[2];
    frame.dataByte3 = temp_can_data[3];
    frame.dataByte4 = temp_can_data[4];
    frame.dataByte5 = temp_can_data[5];
    frame.dataByte6 = temp_can_data[6];
    frame.dataByte7 = temp_can_data[7];
    FLEXCAN_TransferSendBlocking( CAN2, 8, &frame );
    if( iopDataHead == iopDataTail )
        {
        iopDataHead = IOP_QUEUE_INVALID;
        iopDataTail = IOP_QUEUE_INVALID;
        }
    else
        {
        iopDataHead = ( iopDataHead + 1 ) % IOP_MAX_QUEUE_SIZE;
        }
    }
}

/*********************************************************************
*
* @private
* packageIopToCanData
*
* @brief function to package iop to CAN data
*
*********************************************************************/
static void packageIopToCanData
    (
    void*  data_ptr,
    uint16_t data_len
    )
{
uint8_t iopData[128];
switch ( IOPInstId )
    {
    case IOP_CMND_DATA:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_CMND_DATA, iopData, data_len );
        break;

    case IOP_HWM_TIME_DATA:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_HWM_TIME_DATA, iopData, data_len );
        break;

    case IOP_UNIT_ID_DATA:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_UNIT_ID_DATA, iopData, data_len );
        break;

    case IOP_PGM_DATA:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_PGM_DATA, iopData, data_len );
        break;

    case IOP_PRODUCT_RQST_EXTEND:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_PRODUCT_DATA, iopData, data_len );
        break;

    case IOP_BT_ADDR_DATA:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_BT_ADDR_DATA, iopData, data_len );
        break;

    default:
        iopToCanData( IOP_INV_INST_ID, iopData, 0 );
        break;
    }
IOPDone = true;
}

/*********************************************************************
*
* @private
* iopProcInstCmd
*
* @brief function to process instument id command
*
*********************************************************************/
static void iopProcInstCmd
    (
    uint16_t  inst_id,
    uint8_t*  data,
    uint16_t  size
    )
{
//Irregular IOP
IOPInstId = inst_id;
IOPSubId  = 0;
IOPCaseId = 0;
IOPDone   = false;

switch( inst_id )
    {
    case IOP_CMND_DATA:
        {
        uint16_t cmd_id = 0;
        memcpy( &cmd_id, &data[0], sizeof( uint16_t ) );
        switch( cmd_id )
            {
            case IOP_DOWN_LOAD_TIME:
                {
                snvs_lp_srtc_datetime_t datetime;
                uint8_t iop_data[8];

                RTC_get_DateTime( &datetime );

                iop_data[0] = datetime.month;
                iop_data[1] = datetime.day;
                iop_data[2] = ( datetime.year & LOW_BYTE_MASK );
                iop_data[3] = ( datetime.year >> SHIFT_ONE_BYTE );
                iop_data[4] = ( datetime.hour & LOW_BYTE_MASK ) ;
                iop_data[5] = ( datetime.hour >> SHIFT_ONE_BYTE );
                iop_data[6] = datetime.minute;
                iop_data[7] = datetime.second;

                IOPInstId = IOP_HWM_TIME_DATA;
                packageIopToCanData( &iop_data, sizeof( iop_data ) );
                }
                break;

            case IOP_DOWN_LOAD_ID:
                {
                if( EEPM_get_ESN( esn_read_cb ) == pdFALSE )
                    {
                    PRINTF("EEPM_get_ESN fail\n\r");
                    }
                esn_operation = IOP_ESN_OP_INVALID;
                IOPDone = true;
                }
                break;

            case IOP_CLR_NONVOL_UNPROTECTED_ONLY:
                {

                IOPDone = true;
                }
                break;

            case IOP_PREP_POWER_OFF:
                {

                IOPDone = true;
                break;
                }

            case IOP_BT_GET_BDADDR:
                {
                // uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN] = {0};

                // BTM_IOP_read_local_device_address();
                // IOPInstId = IOP_BT_ADDR_DATA;
                // BTM_get_local_device_address( &(bd_addr[0]) );
                // packageIopToCanData( &bd_addr, sizeof( bd_addr ) );
                }
                break;

            case IOP_BT_POWER_ON:
                {

                IOPDone = true;
                }
                break;

            case IOP_BT_POWER_OFF:
                {

                IOPDone = true;
                }
                break;

            case IOP_BT_SET_TEST_MODE:
                {

                IOPDone = true;
                }
                break;

            case IOP_BT_GET_TEST_MODE:
                {

                IOPDone = true;
                }
                break;

            case IOP_BT_CLEAR_PAIRINGS:
                {

                IOPDone = true;
                }
                break;

            default:
                IOPDone = true;
                break;
            }
        }
        break;

    case IOP_HWM_TIME_DATA:
        {
        snvs_lp_srtc_datetime_t datetime;

        datetime.month  = data[0];
        datetime.day    = data[1];
        datetime.year   = data[2] + ( data[3] << SHIFT_ONE_BYTE );
        datetime.hour   = data[4] + ( data[5] << SHIFT_ONE_BYTE );
        datetime.minute = data[6];
        datetime.second = data[7];

        RTC_set_DateTime( &datetime );
        IOPDone = true;
        }
        break;

    case IOP_UNIT_ID_DATA:
        {
        memcpy( &esn_id, &data[0], sizeof( uint32_t ) );
        if( esn_id == ESN_REWRITE_ID )
            {
            if( EEPM_set_ESN( esn_id, esn_write_cb ) == pdFALSE )
                {
                PRINTF("EEPM_set_ESN fail\n\r");
                }
            }
        else
            {
            esn_operation = IOP_ESN_OP_WRITE;
            if( EEPM_get_ESN( esn_read_cb ) == pdFALSE )
                {
                PRINTF("EEPM_get_ESN fail\n\r");
                }
            }
        }
        break;
    case IOP_SYC_MODE_DATA:
        {
        uint8_t iopSubId = data[0];
        switch( iopSubId )
            {
            case SYC_MODE_NORMAL:
                {

                }
                break;
            case SYC_MODE_TEST:
                {

                }
                break;
            }
        IOPDone = true;
        break;
        }
    case IOP_PRODUCT_RQST_EXTEND:
        {
        uint8_t   iop_Data[48];
        uint16_t  sw_version;
        uint8_t   sw_version_ascii[5];
        uint8_t   hw_version;

        sw_version          = SW_VERSION;
        sw_version_ascii[0] = ASCII_BYTE_OFFSET + ( SW_VERSION / 1000 );
        sw_version_ascii[1] = ASCII_BYTE_OFFSET + ( SW_VERSION % 1000 / 100 );
        sw_version_ascii[2] = 0x2E; // .
        sw_version_ascii[3] = ASCII_BYTE_OFFSET + ( SW_VERSION % 100 / 10 );
        sw_version_ascii[4] = ASCII_BYTE_OFFSET + ( SW_VERSION % 10 );
        hw_version          = ASCII_BYTE_OFFSET + 1; //TODO: Change to get function in 1172.

        memcpy( &iop_Data[0],  &product_id, sizeof( product_id ) );
        memcpy( &iop_Data[2],  &sw_version, sizeof( sw_version ) );
        memcpy( &iop_Data[4],  &product_string[0], 8 );
        memcpy( &iop_Data[12], &sw_version_ascii, sizeof( sw_version_ascii ) );
        memcpy( &iop_Data[17], &product_string[8], 16 );
        memcpy( &iop_Data[33], &hw_version, sizeof( hw_version ) );
        memcpy( &iop_Data[34], &product_string[24], 14 );

        packageIopToCanData( &iop_Data[0], 48 );
        }
        break;

    case IOP_BT_SET_BDADDR:
        {
        // if( BT_DEVICE_ADDRESS_LEN == size )
        //     {
        //     BTM_IOP_set_local_device_address( data );
        //     }
        // IOPDone = true;
        }
        break;

    case IOP_BT_TX_CARRIER_FREQ:
        {

        IOPDone = true;
        }
        break;

    case IOP_TEST_MODE_SWITCH_PAGE:
        {
        if( data[0] == 0 )
            {
            // EW_quit_test();
            }
        else
            {
            // EW_test_display_pattern( data[0] );
            }
        IOPDone = true;
        }
        break;

    default:
        IOPDone = true;
        break;
    }
}

/*********************************************************************
*
* @private
* iopProcInstCmd
*
* @brief function to process VIM id command
*
*********************************************************************/
static void iopProcVIMCaseCmd
    (
    uint16_t case_id,
    uint8_t* data,
    uint16_t size
    )
{
//Regular IOP
IOPInstId  = IOP_PGM_DATA;
IOPSubId = ( case_id >> SHIFT_ONE_BYTE ) | ( case_id & LOW_BYTE_MASK ) << SHIFT_ONE_BYTE ;
IOPDone    = false;

switch( IOPSubId )
    {
    case IOP_VIM_PKT_GPIO_CMD:
        {
        uint8 rtn_arry[6] = { 0, IOP_VIM_PKT_GPIO_CMD, data[0], data[1], data[2], E_NOT_OK };
        rtn_arry[5] = setGPIOValue( data[0], data[1], data[2] );
        packageIopToCanData( &rtn_arry, sizeof( rtn_arry ) );
        }
        break;

    case IOP_VIM_PKT_ADC_CHANNEL_CMD:
        {
        uint16_t voltage = 0;
        uint8_t  adc_instance = data[0];
        uint8_t  adc_channel  = data[1];
        uint8_t  rtn_arry[6]  = { 0, IOP_VIM_PKT_ADC_CHANNEL_DATA, data[0], data[1], 0, 0 };

        if( adc_instance == 1 ) // ADC1
            {
            switch( adc_channel )
                {
                case ADC_CHANNEL_NUM_VBATT_SEN:
                    voltage = PERIPHERAL_adc_get_vbatt();
                    break;
                case ADC_CHANNEL_NUM_PCBA_TEMP:
                    voltage = PERIPHERAL_adc_get_pcba_ntc();
                    break;
                case ADC_CHANNEL_NUM_TFT_TEMP:
                    voltage = PERIPHERAL_adc_get_tft_ntc();
                    break;
                default:
                    voltage = DATA_INVALID;
                    break;
                }
            }
        else
            {
            voltage = DATA_INVALID;
            }
        rtn_arry[4] = voltage >> SHIFT_ONE_BYTE;
        rtn_arry[5] = voltage & LOW_BYTE_MASK;
        packageIopToCanData( &rtn_arry, sizeof( rtn_arry ) );
        }
        break;

    case IOP_VIM_PKT_PWM_OUTPUT_CMD:
        {
        uint8_t rtn_arry[2] = { data[0], data[1] };
        PERIPHERAL_pwm_set_display_dutycycle( data[1] );
        packageIopToCanData( &rtn_arry, sizeof( rtn_arry ) );
        }
        break;

    /* GPIO read command for Factory test */
    case IOP_VIM_PKT_GPIO_STATUS_CMD:
        {
        uint8 rtn_arry[6] = { 0, IOP_VIM_PKT_GPIO_STATUS_DATA, data[0], data[1], STD_LOW, E_NOT_OK };
        rtn_arry[5] = getGPIOValue( data[0], data[1], &rtn_arry[4] );
        packageIopToCanData( &rtn_arry, sizeof( rtn_arry ) );
        }
        break;

    case IOP_VIM_PKT_PRODUCT_SKU_CMD:
        {
        uint8 type = data[0];
        uint8 rtn_arry[7];
        memset( &rtn_arry, DATA_INVALID_BYTE, sizeof( rtn_arry ) );
        rtn_arry[0] = 0;
        rtn_arry[1] = IOP_VIM_PKT_PRODUCT_SKU_DATA;
        rtn_arry[2] = type;
        switch( type )
            {
            case IOP_PRODUCT_HW_ID:
                {
                getGPIOValue( PORT_8, 18, &rtn_arry[3] ); // HW_ID3
                getGPIOValue( PORT_8, 15, &rtn_arry[4] ); // HW_ID2
                getGPIOValue( PORT_8, 14, &rtn_arry[5] ); // HW_ID1
                getGPIOValue( PORT_8, 13, &rtn_arry[6] ); // HW_ID0
                packageIopToCanData( &rtn_arry, sizeof( rtn_arry ) );
                }
                break;

            case IOP_PRODUCT_SKU_ID:
                {
                getGPIOValue( PORT_8, 26, &rtn_arry[3] ); // SKU_ID3
                getGPIOValue( PORT_8, 22, &rtn_arry[4] ); // SKU_ID2
                getGPIOValue( PORT_8, 20, &rtn_arry[5] ); // SKU_ID1
                getGPIOValue( PORT_8, 19, &rtn_arry[6] ); // SKU_ID0
                packageIopToCanData( &rtn_arry, sizeof( rtn_arry ) );
                }
                break;
            default:
                {
                packageIopToCanData( &rtn_arry, sizeof( rtn_arry ) );
                IOPDone = true;
                }
                break;
            }
        }
        break;

    case IOP_BT_ACCEPT_NEXT_PAIR_REQUEST:
        {

        IOPDone = true;
        }
        break;

    case IOP_BT_SET_TO_ACTIVE:
        {
        // BTM_set_discoverable_state( true );
        // IOPDone = true;
        }
        break;

    default:
        IOPDone = true;
        break;
    }
}

/*********************************************************************
*
* @private
* packageIopData
*
* @brief Package function to transfer the Marine N2K raw data to IOP format
* data. This function is called in CanToIopParser when the parsing is done.
*
*********************************************************************/
static void packageIopData
    (
    uint8_t* rawData
    )
{
uint16_t  iop_InstID;
uint16_t  iop_SubID;

memcpy( &iop_InstID, &rawData[IOP_VIM_COMM_INST_ID_MSB_POS], sizeof( uint16_t ) );

// Handle by MCU
if( iop_InstID == IOP_PGM_DATA )
    {
    if( IOPDone == true )
        {
        memcpy( &iop_SubID, &rawData[IOP_VIM_COMM_SUB_ID_MSB_POS], sizeof( uint16_t ) );
        iopProcVIMCaseCmd( iop_SubID, &rawData[IOP_VIM_COMM_CASE_ID_MSB_POS], recordDataSize -  8 );
        }
    }
else
    {
    if( IOPDone == true )
        {
        iopProcInstCmd( iop_InstID, &rawData[IOP_VIM_COMM_SUB_ID_MSB_POS], recordDataSize - 6  );
        }
    }
}

/*********************************************************************
*
* @private
* CanToIopParser
*
* @brief Parser function to transfer the specific CAN format data from GND10
* and send it to A12.
*
* This function is called in ft_hook_receive when there's CAN data
* with Factory's CAN ID comes in.
*
*********************************************************************/
static void CanToIopParser
    (
    const uint8_t* canRawData
    )
{
uint8_t sequenceId;
uint8_t dataSize;

sequenceId = canRawData[0];
// If this is the first packet
if( sequenceId == 0 )
    {
    dataSize = firstCanDataLength;
    recordSequenceId = sequenceId + 1;
    recordDataSize = canRawData[1];

    memcpy( &recordData[0], &canRawData[2], dataSize );
    if( recordDataSize <= dataSize )
        {
        packageIopData( &recordData[0] );
        recordSequenceId = 0;
        }
    }
else
    {
    if( sequenceId == recordSequenceId )
        {
        dataSize = otherCanDataLength;
        recordSequenceId = sequenceId + 1;

        memcpy( &recordData[firstCanDataLength + ( sequenceId - 1 ) * otherCanDataLength], &canRawData[1], dataSize );
        if( ( firstCanDataLength + otherCanDataLength * sequenceId ) >= recordDataSize )
            {
            packageIopData( &recordData[0] );
            recordSequenceId = 0;
            }
        }
    }
}


/*********************************************************************
*
* @private
* iopToCanData
*
* @brief Package function to package IOP raw data to specific CAN message.
* data.
*
* This function is called in packageIopData if the factory related command
* needs to send back iop data.
*
*********************************************************************/
void iopToCanData
    (
    uint16_t  iopid,
    uint8_t*  iopRawData,
    uint8_t   iopDataSize
    )
{
uint8_t firstCanData[8];
uint8_t otherCanData[8];

firstCanData[0] = 0x00;
firstCanData[1] = iopDataSize + firstCanDataLength;    // Total Date Size
firstCanData[2] = 0xE5;
firstCanData[3] = 0x98;
firstCanData[4] = ( iopid & LOW_BYTE_MASK );
firstCanData[5] = ( iopid >> 8 );
firstCanData[6] = 0x02;
firstCanData[7] = 0x02;

storeCanData( &firstCanData[0] );

if( iopDataSize > 0 )
    {
    uint8_t totalRound = ( iopDataSize / otherCanDataLength ) + 1;
    uint8_t remainByte = otherCanDataLength - ( iopDataSize % otherCanDataLength );
    for( int i = 0; i < totalRound; i++ )
        {
        otherCanData[0] = i + 1;
        memcpy( &otherCanData[1], &iopRawData[0 + i * otherCanDataLength] , otherCanDataLength );
        if( i == ( totalRound - 1 ) )
            {
            memset( &otherCanData[8 - remainByte], 0xFF, remainByte );
            }
        storeCanData( &otherCanData[0] );
        }
    }
}

/*********************************************************************
*
* @private
* esn_read_cb
*
* @brief callback function for ESN read operation.
*
*********************************************************************/
static void esn_read_cb
    (
    bool    status,
    void*   data
    )
{
memcpy( &EEPM_esn_id, data, BIT_32_DATA_LEN );

if( status == pdTRUE )
    {
    if( esn_operation == IOP_ESN_OP_WRITE )
        {
        IOPInstId = IOP_UNIT_ID_DATA;
        if( EEPM_esn_id == ESN_REWRITE_ID )
            {
            if( EEPM_set_ESN( esn_id, esn_write_cb ) == pdFALSE )
                {
                PRINTF("EEPM_set_ESN fail\n\r");
                }
            esn_operation = IOP_ESN_OP_INVALID;
            }
        else
            {
            packageIopToCanData( &EEPM_esn_id, BIT_32_DATA_LEN );
            }
        }
    else
        {
        IOPInstId = IOP_UNIT_ID_DATA;
        packageIopToCanData( &EEPM_esn_id, BIT_32_DATA_LEN );
        }
    }
}

/*********************************************************************
*
* @private
* esn_write_cb
*
* @brief callback function for ESN write operation.
*
*********************************************************************/
static void esn_write_cb
    (
    bool    status,
    void*   data
    )
{
IOPInstId = IOP_UNIT_ID_DATA;
packageIopToCanData( &esn_id, BIT_32_DATA_LEN );
}

/*********************************************************************
*
* @private
* factory_test_task
*
* @brief This task scans for the CAN message that stored in the queue
* if available and send out in the period of 10ms
*
*********************************************************************/
static void factory_test_task
    (
    void* arg
    )
{
while( true )
    {
    if( canRxFlag )
        {
        CanToIopParser( (uint8_t *)&canRxData );
        canRxFlag = FALSE;
        }

    /* Periodically send CAN data that stored in the queue */
    sendCanData();

    vTaskDelay( pdMS_TO_TICKS( 10 ) );
    }
vTaskDelete( NULL );
}

/*********************************************************************
*
* @private
* ft_hook_receive
*
* @brief hook function to receive data from can dll layer
*
*********************************************************************/
void ft_hook_receive
    (
    can_rmd_t   const * const p_rmd    //!< [in] pointer to received message
    )
{
memcpy( &canRxData, &p_rmd->data[0], 8 );
canRxFlag = TRUE;
}

#ifdef __cplusplus
}
#endif
