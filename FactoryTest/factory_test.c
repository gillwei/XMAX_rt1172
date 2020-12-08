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
#include "WDG_pub.h"

#include "can_cfg.h"
#include "can_drv.h"
#include "can_hw.h"
#include "can_dll_par.h"
#include "can_dll_prv_par.h"

#include "IOP_pub_inst.h"
#include "IOP_pub_cmnd.h"
#include "IOP_pub_vim_inst_prj.h"

#include "factory_test.h"
#include "HCI_pub.h"
#include "BTM_pub.h"
#include "hci_control_api.h"
#include "BT_UPDATE_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define FACTORY_TASK_PERIOD_MS  ( 10 )
#define NULL_PTR                ( ( void * ) 0 )

#define E_OK                    ( 0 )
#define E_NOT_OK                ( 1 )

#define STD_HIGH                ( 1u ) /* Physical state 5V or 3.3V */
#define STD_LOW                 ( 0u ) /* Physical state 0V */

#define DATA_INVALID_BYTE       ( 0xFF )
#define DATA_INVALID_2BYTES     ( 0xFFFF )
#define DATA_INVALID_4BYTES     ( 0xFFFFFFFF )

#define BIT_32_DATA_LEN         ( 4 )
#define BIT_24_DATA_LEN         ( 3 )
#define BIT_16_DATA_LEN         ( 2 )
#define BIT_8_DATA_LEN          ( 1 )

#define IOP_VIM_MAX_DATA_SIZE   ( 200 )
#define IOP_MAX_QUEUE_SIZE      ( 100 )
#define IOP_QUEUE_INVALID       ( -1 )

#define ESN_REWRITE_ID          ( 0xFFFFFFFF )
#define ASCII_BYTE_OFFSET       ( 0x30 )
#define ASCII_BYTE_DOT          ( 0x2E ) // .
#define LOW_BYTE_MASK           ( 0x00FF )
#define MAX_PIN_NUM             ( 32 )

#define IOP_PRODUCT_HW_ID       ( 0 )
#define IOP_PRODUCT_SKU_ID      ( 1 )

#define BURN_IN_TASK_TIME       ( 1000 )
#define BURN_IN_QUAL_DFT_TIME   ( 8 * 60 * 60 )
#define BURN_IN_QUAL_TEMP       ( 60 * 1000 )
#define BURN_IN_QUAL_MIN_TIME   ( 1 * 60 * 60 )
#define BURN_IN_QUAL_MAX_TIME   ( BURN_IN_QUAL_DFT_TIME )
#define BURN_IN_SUCCESS         ( 0 )
#define BURN_IN_FAIL            ( 1 )

#define CANID_TEST_SEND_MS      ( 500 )
#define CANID_TEST_SEND_CNT     ( CANID_TEST_SEND_MS / FACTORY_TASK_PERIOD_MS )
#define CANID_TEST_MAX_TIME_MS  ( CANID_TEST_SEND_MS * ( sizeof( CAN_test_ID ) / sizeof( CAN_test_ID[0] ) ) )
#define CANID_TEST_MAX_TIME_CNT ( CANID_TEST_MAX_TIME_MS / FACTORY_TASK_PERIOD_MS )

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
static char const product_string[] = { "IXWW22 v Board Version:   006-B3952-00 " };


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

//Burn-in
IOP_BurnIn_op_stage_type            burnInStage            = IOP_BURNIN_STAGE_NOT_START;
static boolean                      burnInResult           = BURN_IN_FAIL;
static uint32_t                     burnInTime             = 0;
static uint32_t                     burnInTargetTime       = BURN_IN_QUAL_DFT_TIME;
static IOP_set_BurnIn_state_type    burnInState            = IOP_BURNIN_STATE_NONE;

static const uint8_t default_bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

//CAN ID test
static boolean CAN_ID_test_flag = FALSE;
static uint32_t CAN_test_ID[]   = { 0x4C0, 0x100, 0x200, 0x400, 0x110, 0x220, 0x440, 0x480, 0x111, 0x222, 0x444, 0x488, 0x4C7 };

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

static void IOP_BurnIn_Task
    (
    void* arg
    );

static void sendCanTestData
    (
    void
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

static uint8 get_hw_id
    (
    uint8 * hw_id_data
    );

static void get_sku_id
    (
    uint8 * sku_id_data
    );

static void burnin_result_read_cb
    (
    bool    status,
    void*   data
    );

static void burnin_result_write_cb
    (
    bool    status,
    void*   data
    );

static void burnin_start_write_cb
    (
    bool    status,
    void*   data
    );

static void burnin_start_read_cb
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
if( EEPM_get_start_burn_in( burnin_start_read_cb ) == pdFALSE )
    {
    PRINTF("EEPM_get_start_burn_in fail\n\r");
    }
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
if( pdPASS == xTaskCreate( factory_test_task, "factory_test_task", configMINIMAL_STACK_SIZE * 2, NULL, TASK_PRIO_FAC_TEST, NULL ) )
    {
    PRINTF("%s ok\r\n", "factory_test_task" );
    }
else
    {
    PRINTF("%s fail\r\n", "factory_test_task" );
    }
if( pdPASS == xTaskCreate( IOP_BurnIn_Task, "IOP_BurnIn_Task", configMINIMAL_STACK_SIZE * 2, NULL, TASK_PRIO_BURN_IN, NULL ) )
    {
    PRINTF("%s ok\r\n", "IOP_BurnIn_Task" );
    }
else
    {
    PRINTF("%s fail\r\n", "IOP_BurnIn_Task" );
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
static can_tmd_t l_p_tmd =
    {
    .identifier = TX7_FACT_INSP1_GA_CAN0_ID,
    .dlc        = IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_LEN,
    .handle     = IL_CAN0_TX7_FACT_INSP1_GA_TXFRM_HANDLE,
    .options    = CAN_TXMSG_STANDARD
    };

if( !queueIsEmpty() )
    {
    l_p_tmd.p_data = (uint8_t *)&iopDataQueue[iopDataHead];
    can_transmit( CAN_CONTROLLER_2, &l_p_tmd );
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

    case IOP_EVNT_DATA:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_EVNT_DATA, iopData, data_len );
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

    case IOP_AUTO_BURN_IN:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_AUTO_BURN_IN, iopData, data_len );
        break;

    case IOP_MFI_INST_RESPONSE:
        memcpy( &iopData[0], data_ptr, data_len );
        iopToCanData( IOP_MFI_INST_RESPONSE, iopData, data_len );
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

            case IOP_TEST_CAN:
                {
                CAN_ID_test_flag = data[2];
                packageIopToCanData( &data[0], BIT_24_DATA_LEN );
                }
                break;

            case IOP_PREP_POWER_OFF:
                {

                IOPDone = true;
                break;
                }

            case IOP_BT_GET_BDADDR:
                {
                uint8_t dummy_bd_address[BT_DEVICE_ADDRESS_LEN] = {0};
                if( BT_UPDATE_get_BT_update_status() )
                    {
                    IOPInstId = IOP_BT_ADDR_DATA;
                    packageIopToCanData( &dummy_bd_address, sizeof( dummy_bd_address ) );
                    }
                else
                    {
                    BTM_IOP_read_local_device_address();
                    }
                IOPDone = true;
                }
                break;

            case IOP_BT_POWER_ON:
                {
                HCI_BT_on();
                IOPDone = true;
                }
                break;

            case IOP_BT_POWER_OFF:
                {
                HCI_BT_off();
                IOPDone = true;
                }
                break;

            case IOP_BT_SET_TEST_MODE:
                {
                HCI_set_test_mode();
                IOPDone = true;
                }
                break;

            case IOP_BT_GET_TEST_MODE:
                {
                uint8_t resp_data[8] = { 0x8C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  };
                bool bt_test_mode = false;
                bt_test_mode = HCI_get_test_mode_state();
                IOPInstId = IOP_EVNT_DATA;
                resp_data[2] =  bt_test_mode;
                packageIopToCanData( &resp_data, sizeof( resp_data ) );
                }
                break;

            case IOP_BT_CLEAR_PAIRINGS:
                {
                BTM_unpair_paired_device( 0 );
                IOPDone = true;
                }
                break;

            case IOP_REQ_AUTO_BURN_IN:
                {
                uint8_t iop_data[2] = { data[2], E_NOT_OK };
                switch( data[2] ) // Request type
                    {
                    case IOP_REQ_AUTO_BURN_IN_MODE: // set mode
                        {
                        if( EEPM_set_start_burn_in( data[3], burnin_start_write_cb ) == pdFALSE )
                            {
                            PRINTF("EEPM_set_start_burn_in fail\n\r");
                            }
                        else
                            {
                            burnInResult = BURN_IN_FAIL;
                            EEPM_set_burn_in_result( burnInResult, burnin_result_write_cb );
                            }
                        }
                        break;

                    case IOP_REQ_AUTO_BURN_IN_TIME: // set time
                        {
                        uint32_t req_burnin_time = 0;

                        req_burnin_time = ( data[3] ) +
                                          ( data[4] << SHIFT_ONE_BYTE ) +
                                          ( data[5] << SHIFT_TWO_BYTES ) +
                                          ( data[6] << SHIFT_THREE_BYTES );

                        if( req_burnin_time >= BURN_IN_QUAL_MIN_TIME && req_burnin_time <= BURN_IN_QUAL_MAX_TIME )
                            {
                            burnInTargetTime = req_burnin_time;
                            iop_data[1] = E_OK;
                            }
                        packageIopToCanData( &iop_data, sizeof( iop_data ) );
                        }
                        break;

                    default:
                        packageIopToCanData( &iop_data, sizeof( iop_data ) );
                        break;
                    }
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
                WDG_switch( false ); // Disable WDG pulse, this will result to hardware reset
                }
                break;
            }
        IOPDone = true;
        break;
        }
    case IOP_PRODUCT_RQST_EXTEND:
        {
        uint8_t   iop_Data[49];
        uint16_t  sw_version;
        uint8_t   sw_version_ascii[5];
        uint8_t   hw_version[2];

        sw_version          = SW_VERSION;
        sw_version_ascii[0] = ASCII_BYTE_OFFSET + ( SW_VERSION / 1000 );
        sw_version_ascii[1] = ASCII_BYTE_OFFSET + ( SW_VERSION % 1000 / 100 );
        sw_version_ascii[2] = ASCII_BYTE_DOT;
        sw_version_ascii[3] = ASCII_BYTE_OFFSET + ( SW_VERSION % 100 / 10 );
        sw_version_ascii[4] = ASCII_BYTE_OFFSET + ( SW_VERSION % 10 );
        hw_version[0]       = ASCII_BYTE_OFFSET + ( get_hw_id( NULL_PTR ) / 10 );
        hw_version[1]       = ASCII_BYTE_OFFSET + ( get_hw_id( NULL_PTR ) % 10 );

        memcpy( &iop_Data[0],  &product_id, sizeof( product_id ) );
        memcpy( &iop_Data[2],  &sw_version, sizeof( sw_version ) );
        memcpy( &iop_Data[4],  &product_string[0], 8 );
        memcpy( &iop_Data[12], &sw_version_ascii, sizeof( sw_version_ascii ) );
        memcpy( &iop_Data[17], &product_string[8], 16 );
        memcpy( &iop_Data[33], &hw_version[0], sizeof( hw_version[0] ) );
        memcpy( &iop_Data[34], &hw_version[1], sizeof( hw_version[1] ) );
        memcpy( &iop_Data[35], &product_string[25], 14 );

        packageIopToCanData( &iop_Data[0], sizeof( iop_Data ) );
        }
        break;

    case IOP_BT_SET_BDADDR:
        {
        uint8_t temp_bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };
        BTM_get_local_device_address( temp_bd_addr );
        // Check the BD address have not been set, or set bd address are default address
        if( ( BT_DEVICE_ADDRESS_LEN == size ) && ( 0 == memcmp( default_bd_addr, temp_bd_addr, BT_DEVICE_ADDRESS_LEN ) ) )
            {
            BTM_IOP_set_local_device_address( data );
            }
        else if ( ( BT_DEVICE_ADDRESS_LEN == size ) && ( 0 == memcmp( default_bd_addr, data, BT_DEVICE_ADDRESS_LEN ) ) )
            {
            BTM_IOP_set_local_device_address( data );
            }
        IOPDone = true;
        }
        break;

    case IOP_BT_TX_CARRIER_FREQ:
        {
        HCI_LE_transmit_cmd( data );
        IOPDone = true;
        }
        break;

    case IOP_MFI_START_COPROCESSOR_TEST:
        {
        HCI_wiced_send_command( HCI_CONTROL_IAP2_COMMAND_GET_AUTH_CHIP_INFO, NULL, 0 );
        HCI_wait_for_resp_start();
        IOPDone = true;
        }
        break;

    // Check burn in state
    case IOP_AUTO_BURN_IN:
        {
        if( EEPM_get_burn_in_result( burnin_result_read_cb ) == pdFALSE )
            {
            PRINTF("EEPM_get_burn_in_result fail\n\r");
            }
        }
        break;

    case IOP_TEST_MODE_SWITCH_PAGE:
        {
        if( data[0] == 0 )
            {
            EW_quit_test();
            }
        else
            {
            EW_test_display_pattern( data[0] );
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
        uint16_t voltage = DATA_INVALID_2BYTES;
        int32_t  temperature = DATA_INVALID_4BYTES;
        uint8_t  adc_instance = data[0];
        uint8_t  adc_channel  = data[1];
        uint8_t  rtn_arry[8]  = { 0, IOP_VIM_PKT_ADC_CHANNEL_DATA, data[0], data[1], 0, 0, 0, 0 };

        if( adc_instance == 1 ) // ADC1
            {
            switch( adc_channel )
                {
                case ADC_CHANNEL_NUM_VBATT_SEN:
                    voltage = PERIPHERAL_adc_get_vbatt();
                    break;
                case ADC_CHANNEL_NUM_PCBA_TEMP:
                    temperature = PERIPHERAL_adc_get_pcba_ntc_converted();
                    break;
                case ADC_CHANNEL_NUM_TFT_TEMP:
                    temperature = PERIPHERAL_adc_get_tft_ntc_converted();
                    break;
                default:
                    break;
                }
            }
        if( voltage != DATA_INVALID_2BYTES )
            {
            rtn_arry[4] = voltage & LOW_BYTE_MASK;
            rtn_arry[5] = voltage >> SHIFT_ONE_BYTE;
            }
        else if( temperature != DATA_INVALID_4BYTES )
            {
            rtn_arry[4] = ( temperature & 0x000000FF );
            rtn_arry[5] = ( temperature & 0x0000FF00 ) >> SHIFT_ONE_BYTE;
            rtn_arry[6] = ( temperature & 0x00FF0000 ) >> SHIFT_TWO_BYTES;
            rtn_arry[7] = ( temperature & 0xFF000000 ) >> SHIFT_THREE_BYTES;
            }
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
                get_hw_id( &rtn_arry[3] );
                packageIopToCanData( &rtn_arry, sizeof( rtn_arry ) );
                }
                break;

            case IOP_PRODUCT_SKU_ID:
                {
                get_sku_id( &rtn_arry[3] );
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
        BTM_set_discoverable_state( true );
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
* get_hw_id
*
* @brief get HW_ID depends on the gpio input
*
*********************************************************************/
static uint8 get_hw_id
    (
    uint8 * hw_id_data
    )
{
uint8 hw_id_dec = 0;

getGPIOValue( PORT_8, 18, &hw_id_data[0] ); // HW_ID3
getGPIOValue( PORT_8, 15, &hw_id_data[1] ); // HW_ID2
getGPIOValue( PORT_8, 14, &hw_id_data[2] ); // HW_ID1
getGPIOValue( PORT_8, 13, &hw_id_data[3] ); // HW_ID0

hw_id_dec = ( hw_id_data[0] << BIT_24_DATA_LEN ) +
            ( hw_id_data[1] << BIT_16_DATA_LEN ) +
            ( hw_id_data[2] << BIT_8_DATA_LEN  ) +
            ( hw_id_data[3] );

return hw_id_dec;
}

/*********************************************************************
*
* @private
* get_sku_id
*
* @brief get SKU_ID depends on the gpio input
*
*********************************************************************/
static void get_sku_id
    (
    uint8 * sku_id_data
    )
{
getGPIOValue( PORT_8, 26, &sku_id_data[0] ); // SKU_ID3
getGPIOValue( PORT_8, 22, &sku_id_data[1] ); // SKU_ID2
getGPIOValue( PORT_8, 20, &sku_id_data[2] ); // SKU_ID1
getGPIOValue( PORT_8, 19, &sku_id_data[3] ); // SKU_ID0
}

/*********************************************************************
*
* @private
* burnin_result_read_cb
*
* @brief callback function for burn in result read operation.
*
*********************************************************************/
static void burnin_result_read_cb
    (
    bool    status,
    void*   data
    )
{
if( status == TRUE )
    {
    memcpy( &burnInResult, data, BIT_8_DATA_LEN );
    packageIopToCanData( &burnInResult, BIT_8_DATA_LEN );
    }
}

/*********************************************************************
*
* @private
* burnin_result_write_cb
*
* @brief callback function for burn in result read operation.
*
*********************************************************************/
static void burnin_result_write_cb
    (
    bool    status,
    void*   data
    )
{
if( status == TRUE )
    {
    PRINTF( "write burninresult = %d\r\n", (uint8 *)data );
    }
}

/*********************************************************************
*
* @private
* burnin_start_read_cb
*
* @brief callback function for burn in start flags read operation.
*
*********************************************************************/
static void burnin_start_read_cb
    (
    bool    status,
    void*   data
    )
{
if( status == TRUE )
    {
    memcpy( &burnInState, data, BIT_8_DATA_LEN );
    }
}

/*********************************************************************
*
* @private
* burnin_start_write_cb
*
* @brief callback function for burn in start flags write operation.
*
*********************************************************************/
static void burnin_start_write_cb
    (
    bool    status,
    void*   data
    )
{
if( status == TRUE )
    {
    uint8_t iop_data[2] ;
    memcpy( &burnInState, data, BIT_8_DATA_LEN );
    PRINTF( "write burnin start flag = %d\r\n", burnInState );

    iop_data[0] = IOP_REQ_AUTO_BURN_IN_MODE;
    iop_data[1] = burnInState;
    packageIopToCanData( &iop_data, sizeof( iop_data ) );
    }
}




/*********************************************************************
*
* @private
* IOP_BurnIn_Task
*
* @brief This task manages the burn in related operation and write/read
* burn in parameter to control the overall burn in stage in factory
*
*********************************************************************/
static void IOP_BurnIn_Task
    (
    void* arg
    )

{
static int32_t curr_burnInVimTemp = 0;

while( TRUE )
    {
    if( IOP_BURNIN_STATE_SET == burnInState )
        {
        burnInStage = IOP_BURNIN_STAGE_START;
        burnInState = IOP_BURNIN_STATE_VALID;
        EW_start_burn_in();
        }
    else if( IOP_BURNIN_STATE_NONE == burnInState )
        {
        burnInStage = IOP_BURNIN_STAGE_NOT_START;
        }

    switch( burnInStage )
        {
        case IOP_BURNIN_STAGE_NOT_START:
            {
            }
            break;
        case IOP_BURNIN_STAGE_START:
            {
            curr_burnInVimTemp = PERIPHERAL_adc_get_pcba_ntc_converted();
            if( curr_burnInVimTemp >= BURN_IN_QUAL_TEMP )
                {
                burnInStage = IOP_BURNIN_STAGE_RUNNING;
                }
            }
            break;
        case IOP_BURNIN_STAGE_RUNNING:
            {
            curr_burnInVimTemp = PERIPHERAL_adc_get_pcba_ntc_converted();
            if( curr_burnInVimTemp >= BURN_IN_QUAL_TEMP )
                {
                burnInTime++;
                EW_update_burn_in_time( burnInTime );
                if( burnInTime >= burnInTargetTime )
                    {
                    burnInResult = BURN_IN_SUCCESS;
                    EEPM_set_burn_in_result( burnInResult, burnin_result_write_cb );
                    burnInState = IOP_BURNIN_STATE_NONE;
                    EEPM_set_start_burn_in( FALSE, burnin_start_write_cb );
                    burnInStage = IOP_BURNIN_STAGE_PASS;
                    EW_show_burn_in_result( true );
                    }
                }
            else
                {
                burnInTime = 0;
                }
            }
            break;
        case IOP_BURNIN_STAGE_FAIL:
        case IOP_BURNIN_STAGE_PASS:
            {

            }
            break;

        }
    vTaskDelay( pdMS_TO_TICKS( BURN_IN_TASK_TIME ) );
    }
vTaskDelete( NULL );
}

static void sendCanTestData
    (
    void
    )
{
static uint8_t test_count   = 0;
static uint16_t test_period_counter = 0;
static uint8_t l_tx_data[8] = { 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55 };
static can_tmd_t l_p_tmd =
    {
    .dlc        = IL_CAN0_TX_DIAG_RELATED_TXFRM_LEN,
    .handle     = IL_CAN0_TX_DIAG_RELATED_TXFRM_HANDLE,
    .options    = CAN_TXMSG_STANDARD,
    .p_data     = l_tx_data,
    };

if( CAN_ID_test_flag )
    {
    l_p_tmd.identifier = CAN_test_ID[test_count];
    if( test_period_counter % CANID_TEST_SEND_CNT == 0 )
        {
        test_count ++;
        if( test_period_counter < CANID_TEST_MAX_TIME_CNT )
            {
            can_transmit( CAN_CONTROLLER_2, &l_p_tmd );
            }
        else
            {
            CAN_ID_test_flag = false;
            test_period_counter = 0;
            }
        }
    if( test_count == ( sizeof( CAN_test_ID ) / sizeof( CAN_test_ID[0] ) ) )
        {
        test_count = 0;
        }
    test_period_counter ++;
    }
else
    {
    test_count = 0;
    test_period_counter = 0;
    }
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
    /* Periodically send CAN data that stored in the queue */
    sendCanData();

    sendCanTestData();

    vTaskDelay( pdMS_TO_TICKS( FACTORY_TASK_PERIOD_MS ) );
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
CanToIopParser( &p_rmd->data[0] );
}

/*********************************************************************
*
* @public
* receive_auth_chip_ver
*
* @brief receive authenticate chip information result and send IOP
*
*********************************************************************/
void receive_auth_chip_ver
    (
    uint8_t result
    )
{
IOPInstId = IOP_MFI_INST_RESPONSE;
packageIopToCanData( &result, sizeof( uint8_t ) );
}


/*********************************************************************
*
* @public
* sent_iop_bd_address
*
* @brief receive bd address result from BT chip and send IOP
*
*********************************************************************/
void sent_iop_bd_address
    (
    void
    )
{
uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN] = {0};
uint8_t bd_addr_rev[BT_DEVICE_ADDRESS_LEN] = {0};

BTM_get_local_device_address( &(bd_addr[0]) );
for( uint8_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
    {
    bd_addr_rev[i] = bd_addr[BT_DEVICE_ADDRESS_LEN - 1 - i];
    }

IOPInstId = IOP_BT_ADDR_DATA;
packageIopToCanData( &bd_addr_rev, sizeof( bd_addr_rev ) );
}

#ifdef __cplusplus
}
#endif
