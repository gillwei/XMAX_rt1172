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
    case EnumEEPROMTestWRITE_CCUID: /* 8 alphanumeric (0-9, A-F) */
        EEPM_set_qrcode_ccuid( (uint8_t*)"1234CDEF", eepm_test_write_cb );
        break;
    case EnumEEPROMTestWRITE_PASSKEY: /* 6 digits */
        EEPM_set_qrcode_passkey( 987654, eepm_test_write_cb );
        break;
    case EnumEEPROMTestWRITE_DUMMY: /* 4 digits */
        EEPM_set_qrcode_dummy( 928, eepm_test_write_cb );
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
