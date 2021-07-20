/*********************************************************************
* @file
* test_eeprom.c
*
* @brief
* Test module - Unit test for eeprom read/write operation
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "fsl_debug_console.h"
#include "TEST_pub.h"
#include "test_priv.h"
#include "PERIPHERAL_pub.h"
#include "EEPM_pub.h"
#include "EW_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define TEST_EEPROM_PROC_MS                ( 1000 )
#define TEST_EEPM_STEP_WRITE               ( 0 )
#define TEST_EEPM_STEP_READ                ( 1 )

#define TEST_EEPM_DATA_NONE                ( 0 )
#define TEST_EEPM_DATA_QRCODE_CCUID        ( 1 )
#define TEST_EEPM_DATA_QRCODE_PASSKEY      ( 2 )
#define TEST_EEPM_DATA_QRCODE_DUMMY        ( 3 )
#define TEST_EEPM_DATA_TRIP_TIME           ( 4 )
#define TEST_EEPM_DATA_MODE                ( 5 )
#define TEST_EEPM_DATA_SUP_FUNC            ( 6 )
#define TEST_EEPM_DATA_CLK_AUTO_ADJUSTMENT ( 7 )
#define TEST_EEPM_DATA_FUEL_CONSUMPTION    ( 8 )
#define TEST_EEPM_DATA_QRCODE_FUSED_DATA   ( 9 )

#define TEST_EEPM_DATA_ID                  ( TEST_EEPM_DATA_NONE )

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
#if( UNIT_TEST_EEPROM )
    static const int TEST_EEPROM_TICK_COUNT = ( TEST_EEPROM_PROC_MS / TEST_TICK_PERIOD_MS );
    static uint32_t test_eeprom_tick = 0;
    static uint8_t test_eepm_flag = 0;
    #if( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_QRCODE_CCUID )
        uint8_t ccuid[QRCODE_CCUID_LENGTH] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };
    #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_QRCODE_PASSKEY )
        uint32_t pass_key = 0x12345678;
    #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_QRCODE_DUMMY )
        uint16_t dummy = 0xABCD;
    #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_TRIP_TIME )
        uint32_t trip_time = 0x11223344;
    #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_MODE )
        uint8_t mode = 123;
    #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_SUP_FUNC )
        uint8_t sup_func[SUPPORTED_FUNCTION_LENGTH] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 };
    #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_CLK_AUTO_ADJUSTMENT )
        uint8_t auto_adj = 10;
    #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_FUEL_CONSUMPTION )
        uint32_t fuel_consumption = 0x12345678;
    #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_QRCODE_FUSED_DATA )
        uint8_t qrcode_fused1[QRCODE_FUSED_DATA_LENGTH] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };
        uint8_t qrcode_fused2[QRCODE_FUSED_DATA_LENGTH] = { 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18 };
        uint8_t qrcode_fused3[QRCODE_FUSED_DATA_LENGTH] = { 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28 };
    #else
        //Do nothing
    #endif
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*********************************************************************
*
* @private
* eepm_test_write_cb
*
* test eeprom write callback function
*
* @param status Write status
* @param data Pointer to read back data
*
*********************************************************************/
static void eepm_test_write_cb
    (
    bool    status,
    void*   data
    )
{
PRINTF( "write status = %d\r\n", status );
if( status == pdFALSE )
    {
    PRINTF( "EEPROM write test Error!\r\n" );
    }
}

/*********************************************************************
*
* @private
* read_1byte_cb
*
* Read callback
*
* @param status Read status
* @param data Pointer to read data
*
*********************************************************************/
static void read_1byte_cb
    (
    bool  status,
    void* data
    )
{
PRINTF( "rd %d 0x%x\r\n", status, *(uint8_t*)data );
}

/*********************************************************************
*
* @private
* write_test_unit_id
*
* Write test UNIT ID
*
*********************************************************************/
static void write_test_unit_id
    (
    void
    )
{
/* unit id plaintext: 0006031234CDEF 987654 0000 */
uint8_t unit_id_ciphertext[24] = {'6', 'D', '3', '4', '0', '6', '1', '0', '9', '0',
                                  'C', '0', '0', '4', '0', '5', 'E', '3', '0', 'F',
                                  '0', '8', '2', '7'};

EEPM_set_qrcode_fused_data_1( &unit_id_ciphertext[0],  eepm_test_write_cb );
EEPM_set_qrcode_fused_data_2( &unit_id_ciphertext[8],  eepm_test_write_cb );
EEPM_set_qrcode_fused_data_3( &unit_id_ciphertext[16], eepm_test_write_cb );
}

/*********************************************************************
*
* @public
* TEST_read_unit_id_callback
*
* Callback of read unit id
*
* @param result True if read success. False if read fail.
* @param value The pointer to the 1-8 digits of unit id
*
*********************************************************************/
void TEST_read_unit_id_callback
    (
    bool  result,
    void* value
    )
{
uint8_t* unit_id = (uint8_t*)value;
PRINTF( "read unit id: %d\r\n0x", result );
for( int32_t i = 0; i < QRCODE_FUSED_DATA_LENGTH; i++ )
    {
    PRINTF( "%02x ", unit_id[i] );
    }
PRINTF( "\r\n" );

result = EW_get_unit_id_ccuid( &unit_id );
PRINTF( "result: %d, ccuid: %s\r\n", result, unit_id );

result = EW_get_unit_id_dummy( &unit_id );
PRINTF( "result: %d, dummy: %s\r\n", result, unit_id );

result = EW_get_unit_id_passkey( &unit_id );
PRINTF( "result: %d, passkey: %s\r\n", result, unit_id );
}

/*********************************************************************
*
* @private
* clear_unit_id
*
* Clear unit id by writing 0xFF
*
*********************************************************************/
static void clear_unit_id
    (
    void
    )
{
uint8_t empty_unit_id[QRCODE_FUSED_DATA_LENGTH] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
EEPM_set_qrcode_fused_data_1( empty_unit_id, eepm_test_write_cb );
EEPM_set_qrcode_fused_data_2( empty_unit_id, eepm_test_write_cb );
EEPM_set_qrcode_fused_data_3( empty_unit_id, eepm_test_write_cb );
}

/*********************************************************************
*
* @public
* TEST_eeprom
*
* Test eeprom read/write
*
* @param test_item Test item of EnumEEPROMTest type
*
*********************************************************************/
void TEST_eeprom
    (
    const EnumEEPROMTest test_item
    )
{
switch( test_item )
    {
    case EnumEEPROMTestWRITE_LAST_PAGE_FF:
        EEPM_set_last_page( 0xFF, eepm_test_write_cb );
        break;
    case EnumEEPROMTestREAD_LAST_PAGE:
        EEPM_get_last_page( &read_1byte_cb );
        break;
    case EnumEEPROMTestWRITE_TEST_UNIT_ID:
        write_test_unit_id();
        break;
    case EnumEEPROMTestREAD_UNIT_ID:
        EEPM_get_qrcode_fused_data_1( &TEST_read_unit_id_callback );
        EEPM_get_qrcode_fused_data_2( &TEST_read_unit_id_callback );
        EEPM_get_qrcode_fused_data_3( &TEST_read_unit_id_callback );
        break;
    case EnumEEPROMTestCLEAR_UNIT_ID:
        clear_unit_id();
        break;
    default:
        break;
    }
}

#if( UNIT_TEST_EEPROM )
    static void eepm_test_read_cb
        (
        bool    status,
        void*   data
        );

    /*********************************************************************
    *
    * @private
    * test_eeprom_flow
    *
    * Test eeprom read and write function
    *
    *********************************************************************/
    void test_eeprom_flow
        (
        void
        )
    {
    if( test_eepm_flag == TEST_EEPM_STEP_WRITE )
        {
        #if( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_QRCODE_CCUID )
            EEPM_set_qrcode_ccuid( ccuid, eepm_test_write_cb );
        #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_QRCODE_PASSKEY )
            EEPM_set_qrcode_passkey( pass_key, eepm_test_write_cb );
        #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_QRCODE_DUMMY )
            EEPM_set_qrcode_dummy( dummy, eepm_test_write_cb );
        #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_TRIP_TIME )
            EEPM_set_trip_time( trip_time, eepm_test_write_cb );
        #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_MODE )
            EEPM_set_operation_mode( mode, eepm_test_write_cb );
        #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_SUP_FUNC )
            EEPM_set_supported_function( sup_func, eepm_test_write_cb );
        #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_CLK_AUTO_ADJUSTMENT )
            EEPM_set_clk_auto_adjustment( auto_adj, eepm_test_write_cb );
        #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_FUEL_CONSUMPTION )
            EEPM_set_fuel_consumption( fuel_consumption, eepm_test_write_cb );
        #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_QRCODE_FUSED_DATA )
            EEPM_set_qrcode_fused_data_1( qrcode_fused1, eepm_test_write_cb );
            vTaskDelay( 100 );
            EEPM_set_qrcode_fused_data_2( qrcode_fused2, eepm_test_write_cb );
            vTaskDelay( 100 );
            EEPM_set_qrcode_fused_data_3( qrcode_fused3, eepm_test_write_cb );
        #else
            //Do nothing
        #endif
        test_eepm_flag = TEST_EEPM_STEP_READ;
        }
    else
        {
        #if( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_QRCODE_CCUID )
            EEPM_get_qrcode_ccuid( eepm_test_read_cb );
        #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_QRCODE_PASSKEY )
            EEPM_get_qrcode_passkey( eepm_test_read_cb );
        #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_QRCODE_DUMMY )
            EEPM_get_qrcode_dummy( eepm_test_read_cb );
        #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_TRIP_TIME )
            EEPM_get_trip_time( eepm_test_read_cb );
        #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_MODE )
            EEPM_get_operation_mode( eepm_test_read_cb );
        #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_SUP_FUNC )
            EEPM_get_supported_function( eepm_test_read_cb );
        #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_CLK_AUTO_ADJUSTMENT )
            EEPM_get_clk_auto_adjustment( eepm_test_read_cb );
        #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_FUEL_CONSUMPTION )
            EEPM_get_fuel_consumption( eepm_test_read_cb );
        #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_QRCODE_FUSED_DATA )
            EEPM_get_qrcode_fused_data_1( eepm_test_read_cb );
            vTaskDelay( 100 );
            EEPM_get_qrcode_fused_data_2( eepm_test_read_cb );
            vTaskDelay( 100 );
            EEPM_get_qrcode_fused_data_3( eepm_test_read_cb );
        #else
            //Do nothing
        #endif
        test_eepm_flag = TEST_EEPM_STEP_WRITE;
        }
    }

    /*********************************************************************
    *
    * @private
    * test_eeprom_proc
    *
    * Test module - proc unit test for test_eeprom_proc test
    *
    *********************************************************************/
    void test_eeprom_proc
        (
        void
        )
    {
    if( test_eeprom_tick == 0 )
        {
        test_eeprom_tick = TEST_EEPROM_TICK_COUNT;
        test_eeprom_flow();
        }
    test_eeprom_tick--;
    }

    /*********************************************************************
    *
    * @private
    * test_eeprom_int
    *
    * Test module - init unit test for eeprom test
    *
    *********************************************************************/
    void test_eeprom_int
        (
        void
        )
    {
    return;
    }

    /*********************************************************************
    *
    * @private
    * eepm_test_read_cb
    *
    * test eeprom read callback function
    *
    *********************************************************************/
    static void eepm_test_read_cb
        (
        bool    status,
        void*   data
        )
    {
    #if( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_QRCODE_CCUID )
        uint8_t eepm_data[QRCODE_CCUID_LENGTH] = { 0 };
    #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_QRCODE_PASSKEY )
        uint8_t eepm_data[QRCODE_PASSKEY_LENGTH] = { 0 };
    #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_QRCODE_DUMMY )
        uint8_t eepm_data[QRCODE_DUMMY_LENGTH] = { 0 };
    #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_TRIP_TIME )
        uint8_t eepm_data[TRIP_TIME_LENGTH] = { 0 };
    #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_MODE )
        uint8_t eepm_data[OPERATION_MODE_LENGTH] = { 0 };
    #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_SUP_FUNC )
        uint8_t eepm_data[SUPPORTED_FUNCTION_LENGTH] = { 0 };
    #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_CLK_AUTO_ADJUSTMENT )
        uint8_t eepm_data[CLOCK_AUTO_ADJUSTMENT_LENGTH] = { 0 };
    #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_FUEL_CONSUMPTION )
        uint8_t eepm_data[FUEL_CONSUMPTION_LENGTH] = { 0 };
    #elif( TEST_EEPM_DATA_ID == TEST_EEPM_DATA_QRCODE_FUSED_DATA )
        uint8_t eepm_data[QRCODE_FUSED_DATA_LENGTH] = { 0 };
    #else
        uint8_t eepm_data[4] = { 0 };
    #endif
    PRINTF( "read status = %d\r\n", status );
    if( status == pdTRUE )
        {
        memcpy( eepm_data, (uint8_t *)data, sizeof( eepm_data ) );
        for( int i = 0; i < sizeof( eepm_data ); i++ )
            {
            PRINTF( "%02X ", eepm_data[i] );
            }
        PRINTF( "\r\n" );
        }
    }

#endif
