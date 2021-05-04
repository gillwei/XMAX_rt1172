/*********************************************************************
* @file
* ew_device_system.c
*
* @brief
* EW module - system related device interface implementation
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "ewrte.h"
#include "ew_bsp_inout.h"
#include "ew_bsp_clock.h"
#include "ew_bsp_event.h"
#include "ew_priv.h"
#include "DeviceInterface.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "EEPM_pub.h"
#include "GRM_pub_prj.h"
#include "RTC_pub.h"
#include "PM_pub.h"
#include "QR_pub.h"
#include "VI_pub.h"
#include "client_dcm_appl.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#ifdef _DeviceInterfaceSystemDeviceClass_
    typedef int system_device_function( void );
#endif

#ifdef _DeviceInterfaceSystemDeviceClass__NotifyUpdateLocalTime_
    static int ew_system_update_local_time( void );
#endif

#ifdef _DeviceInterfaceSystemDeviceClass__TestDisplayPattern_
    static int ew_sytem_test_display_pattern( void );
#endif

#ifdef _DeviceInterfaceSystemDeviceClass__QuitTest_
    static int ew_system_quit_test( void );
#endif

#ifdef _DeviceInterfaceSystemDeviceClass__NotifyEsnRead_
    static int ew_system_notify_esn( void );
#endif

#ifdef _DeviceInterfaceSystemDeviceClass__NotifyFactoryResetComplete_
    static int ew_notify_factory_reset_complete( void );
#endif

#ifdef _DeviceInterfaceSystemDeviceClass__StartBurnInTest_
    static int ew_start_burn_in_test( void );
#endif

#ifdef _DeviceInterfaceSystemDeviceClass__UpdateBurnInTestTime_
    static int ew_update_burn_in_test_time( void );
#endif

#ifdef _DeviceInterfaceSystemDeviceClass__ShowBurnInTestResult_
    static int ew_show_burn_in_test_result( void );
#endif

#ifdef _DeviceInterfaceSystemDeviceClass__NotifyQrCodeReady_
    static int ew_qrcode_ready( void );
#endif

#ifdef _DeviceInterfaceSystemDeviceClass__NotifyInspectionRequest_
    static int ew_notify_inspection_mode_request( void );
#endif

#ifdef _DeviceInterfaceSystemDeviceClass__NotifyLastPageRead_
    static int ew_notify_last_page_read( void );
#endif

#define UPDATE_TIME_TASK_PRIORITY       ( tskIDLE_PRIORITY )
#define UPDATE_TIME_TASK_NAME           "time_task"
#define UPDATE_TIME_TASK_STACK_SIZE     ( configMINIMAL_STACK_SIZE )

#define EW_STRING_LEN               ( 1024 )

#define ESN_STR_MAX_LEN             ( 10 )
#define UNIT_ID_LEN                 ( 24 )

#define FACTORY_TEST_EVENT_DISP_PATTERN         ( 1 << 0 )
#define FACTORY_TEST_EVENT_DISP_QUIT            ( 1 << 1 )
#define FACTORY_TEST_EVENT_BURNIN_START         ( 1 << 2 )
#define FACTORY_TEST_EVENT_BURNIN_TIME_UPDATE   ( 1 << 3 )
#define FACTORY_TEST_EVENT_BURNIN_RESULT        ( 1 << 4 )

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
static void update_time_task_main( void* arg );
static void ew_get_info_from_eeprom( void );

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
#ifdef _DeviceInterfaceSystemDeviceClass_
    static DeviceInterfaceSystemDeviceClass device_object = 0;
    system_device_function* const system_function_lookup_table[] =
        {
        #ifdef _DeviceInterfaceSystemDeviceClass__NotifyUpdateLocalTime_
            ew_system_update_local_time,
        #endif
        #ifdef _DeviceInterfaceSystemDeviceClass__TestDisplayPattern_
            ew_sytem_test_display_pattern,
        #endif
        #ifdef _DeviceInterfaceSystemDeviceClass__QuitTest_
            ew_system_quit_test,
        #endif
        #ifdef _DeviceInterfaceSystemDeviceClass__NotifyEsnRead_
            ew_system_notify_esn,
        #endif
        #ifdef _DeviceInterfaceSystemDeviceClass__NotifyFactoryResetComplete_
            ew_notify_factory_reset_complete,
        #endif
        #ifdef _DeviceInterfaceSystemDeviceClass__StartBurnInTest_
            ew_start_burn_in_test,
        #endif
        #ifdef _DeviceInterfaceSystemDeviceClass__UpdateBurnInTestTime_
            ew_update_burn_in_test_time,
        #endif
        #ifdef _DeviceInterfaceSystemDeviceClass__ShowBurnInTestResult_
            ew_show_burn_in_test_result,
        #endif
        #ifdef _DeviceInterfaceSystemDeviceClass__NotifyQrCodeReady_
            ew_qrcode_ready,
        #endif
        #ifdef _DeviceInterfaceSystemDeviceClass__NotifyInspectionRequest_
            ew_notify_inspection_mode_request,
        #endif
        #ifdef _DeviceInterfaceSystemDeviceClass__NotifyLastPageRead_
            ew_notify_last_page_read
        #endif
        };
    const int num_of_system_func = sizeof( system_function_lookup_table )/sizeof( system_device_function* );

    static EnumHomeGroup      home_group;
    static EnumMeterDisplay   meter_display_setting;
    static EnumNavigationView navigation_view_setting;
    static int      factory_test_event = 0;
    static int      factory_test_disp_pattern_idx = 0;
    static bool     factory_test_burn_in_result = false;
    static uint32_t factory_test_burn_in_time_sec = 0;
    static int      is_update_time = 0;
    static TickType_t update_time_period_ticks = pdMS_TO_TICKS( UPDATE_TIME_PERIOD_MS );

    static bool     is_inspection_request_received = false;
    static EnumInspectionMode inspection_mode = 0;
    static EnumInspectionDisplay inspection_display_pattern = 0;

    static int is_esn_read = 0;
    static int is_factory_reset_complete = 0;
    static int is_qrcode_ready = 0;
    static bool notify_qrcode_ready;
    static uint32_t ccuid;
    static uint32_t qrcode_passkey;
    static uint16_t qrcode_dummy;
    static EnumOperationMode operation_mode = EnumOperationModeNORMAL;
    static EnumOperationMode operation_mode_in_eep = EnumOperationModeNORMAL;
    static bool     is_running_production_test;
    static bool     is_tft_backlight_on;
    static bool     is_op_mode_ready;
    static bool     is_ccuid_ready;
    static bool     is_qrcode_passkey_ready;
    static bool     is_qrcode_dummy_ready;
    static bool     is_last_page_read;
#endif

static uint32_t esn;
static char qr_code[UNIT_ID_LEN + 1];

AT_BOARDSDRAM_SECTION( uint8_t ew_string[EW_STRING_LEN] );

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* ew_device_system_init
*
* Embedded Wizard system device interface initialization
*
*********************************************************************/
void ew_device_system_init
    (
    void
    )
{
#ifdef _DeviceInterfaceSystemDeviceClass_
     /*
       Get access to the counterpart of this device driver: get access to the
       device class that is created as autoobject within your Embedded Wizard
       project. For this purpose you can call the function EwGetAutoObject().
       This function contains two paramters: The pointer to the autoobject and
       the class of the autoobject.
       Assuming you have implemented the class 'DeviceClass' within the unit
       'Application' and you have an autoobject with the name 'Device', make
       the following call:
       EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass );
    */
    device_object = EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass );
    /*
       Once you have the access to the autoobject, lock it as long as you need
       the access (typically, until your device driver is closed). By locking
       the autoobject, you can ensure that the object of the device class will
       be kept within the memory and not freed by the Garbage Collector.
       Once the device class is locked, you can easily store it within a static
       variable to access the driver class during the runtime.
    */
    EwLockObject( device_object );

    // In order to blink the colon mark in the clock of the status bar,
    // create a task to notify EW with the accurate period of 500ms.
    BaseType_t result = xTaskCreate( update_time_task_main, UPDATE_TIME_TASK_NAME, UPDATE_TIME_TASK_STACK_SIZE, NULL, UPDATE_TIME_TASK_PRIORITY, NULL );
    configASSERT( pdPASS == result );

    ew_get_info_from_eeprom();
#endif
}

/*********************************************************************
*
* @private
* ew_device_system_deinit
*
* Embedded Wizard system device interface de-initialization
*
*********************************************************************/
void ew_device_system_deinit
    (
    void
    )
{
#ifdef _DeviceInterfaceSystemDeviceClass_
    if( device_object )
        {
        EwUnlockObject( device_object );
        }
    device_object = 0;
#endif
}

/*********************************************************************
*
* @private
* ew_device_system_proc
*
* Select the function from system function table and execute it.
*
*********************************************************************/
int ew_device_system_proc
    (
    void
    )
{
int need_update = 0;

#ifdef _DeviceInterfaceSystemDeviceClass_
    if( device_object == 0 ||
        num_of_system_func == 0 )
        {
        return 0;
        }

    for( int i = 0; i < num_of_system_func; i++ )
        {
        if( system_function_lookup_table[i]() )
            {
            need_update = 1;
            }
        }
#endif
return need_update;
}

/*********************************************************************
*
* @private
* update_time_task_main
*
* Main loop of the update time task
*
*********************************************************************/
static void update_time_task_main
    (
    void* arg
    )
{
TickType_t last_wake_ticks = xTaskGetTickCount();
static bool is_one_second = false;

while( 1 )
    {
    is_update_time = 1;
    EwBspEventTrigger();

    /* count in 500ms */
    NTF_update_active_call_duration();

    /* count in 1s */
    if( is_one_second )
        {
        VI_trip_time_count();
        }
    is_one_second = !is_one_second;

    vTaskDelayUntil( &last_wake_ticks, update_time_period_ticks );
    }
vTaskDelete( NULL );
}

/*********************************************************************
*
* @private
* ew_get_software_version
*
* Get software version
*
* @param version The pointer to the char buffer storing software version
*
*********************************************************************/
void ew_get_software_version
    (
    char* version
    )
{
int i = 0;
if( ( SW_VERSION / 1000 ) > 0 )
    {
    version[i++] = '0' + ( SW_VERSION / 1000 );
    }
version[i++] = '0' + ( SW_VERSION / 100 % 10 );
version[i++] = '.';
version[i++] = '0' + ( SW_VERSION % 100 / 10 );
version[i++] = '0' + ( SW_VERSION % 100 % 10 );
version[i]   = 0;
}

/*********************************************************************
*
* @private
* ew_get_bt_software_version
*
* Get BT software version
*
* @param version The pointer to the char buffer storing software version
*
*********************************************************************/
void ew_get_bt_software_version
    (
    char* version
    )
{
version[0] = '\0';
uint8_t bt_sw_ver[BT_SW_VERSION_LEN];
BTM_get_sw_version( bt_sw_ver );
sprintf( version, "%d.%02d", bt_sw_ver[0], bt_sw_ver[1] );
}

/*********************************************************************
*
* @private
* ew_set_last_page
*
* Set last page
*
* @param version The pointer to the char buffer storing software version
*
*********************************************************************/
void ew_set_last_page
    (
    const EnumHomeGroup      group,
    const EnumMeterDisplay   meter_disp_setting,
    const EnumNavigationView navi_view_setting
    )
{
PRINTF( "%s %d %d %d\r\n", __FUNCTION__, group, meter_disp_setting, navi_view_setting );
home_group = group;
meter_display_setting   = meter_disp_setting;
navigation_view_setting = navi_view_setting;
}

/*********************************************************************
*
* @private
* ew_get_last_home_group
*
* Get last home group
*
* @return Last page of uint8_t type
*
*********************************************************************/
EnumHomeGroup ew_get_last_home_group
    (
    void
    )
{
return home_group;
}

/*********************************************************************
*
* @private
* ew_get_meter_display_setting
*
* Get meter display setting
*
* @return Meter display setting
*
*********************************************************************/
EnumMeterDisplay ew_get_meter_display_setting
    (
    void
    )
{
return meter_display_setting;
}

/*********************************************************************
*
* @private
* ew_get_navigation_view_setting
*
* Get navigation view setting
*
* @return Navigation view setting
*
*********************************************************************/
EnumNavigationView ew_get_navigation_view_setting
    (
    void
    )
{
return navigation_view_setting;
}

/*********************************************************************
*
* @private
* start_factory_qrcode_generation
*
* Start QR code generation for factory mode
*
*********************************************************************/
static void start_factory_qrcode_generation
    (
    void
    )
{
QR_generate_qrcode( esn, 4 );
//TODO:
//QR_generate_qrcode( ccuid, qrcode_passkey, qrcode_dummy );
}

/*********************************************************************
*
* @private
* EW_read_esn_callback
*
* Callback of reading ESN
*
* @param result True if read success. False if read fail.
* @param value The pointer to the ESN of uint32_t* type.
*
*********************************************************************/
void EW_read_esn_callback
    (
    bool  result,
    void* value
    )
{
esn = *(uint32_t*)value;
if( EEPROM_INVALID_VAL_4_BYTE != esn )
    {
    is_esn_read = 1;
    }
}

/*********************************************************************
*
* @public
* EW_read_qrcode_ccuid_callback
*
* Callback of reading CCUID from EEPROM
*
* @param result True if read success. False if read fail.
* @param value The pointer to the CCUID of uint32_t* type
*
*********************************************************************/
void EW_read_qrcode_ccuid_callback
    (
    bool  result,
    void* value
    )
{
if( result )
    {
    ccuid = *(uint32_t*)value;
    PRINTF( "rd ccuid 0x%x\r\n", ccuid );
    }
else
    {
    PRINTF( "rd ccuid fail\r\n" );
    }

is_ccuid_ready = true;
}

/*********************************************************************
*
* @public
* EW_read_passkey_callback
*
* Callback of reading passkey from EEPROM
*
* @param result True if read success. False if read fail.
* @param value The pointer to the passkey of uint32_t* type
*
*********************************************************************/
void EW_read_passkey_callback
    (
    bool  result,
    void* value
    )
{
if( result )
    {
    qrcode_passkey = *(uint32_t*)value;
    PRINTF( "rd passkey %u\r\n", qrcode_passkey );
    if( EEPROM_INVALID_VAL_4_BYTE == qrcode_passkey )
        {
        qrcode_passkey = 0;
        }
    }
else
    {
    PRINTF( "rd passkey fail\r\n" );
    }

is_qrcode_passkey_ready = true;
}

/*********************************************************************
*
* @public
* EW_read_qrcode_dummy_callback
*
* Callback of reading qrcode dummy from EEPROM
*
* @param result True if read success. False if read fail.
* @param value The pointer to the QR code dummy of uint16_t* type
*
*********************************************************************/
void EW_read_qrcode_dummy_callback
    (
    bool  result,
    void* value
    )
{
if( result )
    {
    qrcode_dummy = *(uint16_t*)value;
    PRINTF( "rd qrcode dummy 0x%x\r\n", qrcode_dummy );
    }
else
    {
    PRINTF( "rd qrcode dummy fail\r\n" );
    }

is_qrcode_dummy_ready = true;
start_factory_qrcode_generation();
}

/*********************************************************************
*
* @public
* EW_get_last_page_callback
*
* Callback of reading last page from EEPROM
*
* @param result True if read success. False if read fail.
* @param value Pointer to the last page of uint8_t* type
*
*********************************************************************/
void EW_get_last_page_callback
    (
    bool  result,
    void* value
    )
{
if( result )
    {
    uint8_t last_page = *(uint8_t*)value;
    PRINTF( "rd last page 0x%x\r\n", last_page );
    if( EEPROM_INVALID_VAL_1_BYTE != last_page )
        {
        home_group = ( last_page >> LAST_PAGE_HOME_GROUP_SHIFT ) & LAST_PAGE_HOME_GROUP_MASK;
        navigation_view_setting = ( last_page >> LAST_PAGE_NAVI_SETTING_SHIFT ) & LAST_PAGE_NAVIGATION_SETTING_MASK;
        meter_display_setting   = last_page & LAST_PAGE_METER_DISP_SETTING_MASK;
        is_last_page_read = true;
        }
    }
else
    {
    PRINTF( "rd last page fail\r\n" );
    }
}

/*********************************************************************
*
* @public
* EW_read_operation_mode_callback
*
* Callback of reading operation mode from EEPROM
*
* @param result True if read success. False if read fail.
* @param value The pointer to the operation of uint8_t* type
*
*********************************************************************/
void EW_read_operation_mode_callback
    (
    bool  result,
    void* value
    )
{
if( result )
    {
    operation_mode_in_eep = *(uint8_t*)value;
    PRINTF( "rd op mode 0x%x\r\n", operation_mode_in_eep );

    if( EEPROM_INVALID_VAL_1_BYTE == operation_mode_in_eep )
        {
        operation_mode_in_eep = EnumOperationModeFACTORY;
        }
    else if( EnumOperationModeTOTAL <= operation_mode_in_eep )
        {
        operation_mode_in_eep = EnumOperationModeNORMAL;
        }
    else
        {
        // empty
        }
    }
else
    {
    PRINTF( "rd op mode fail\r\n" );
    }

ew_set_operation_mode( operation_mode_in_eep );
is_op_mode_ready = true;
}

/*********************************************************************
*
* @private
* ew_get_esn
*
* Get ESN from EEPROM.
*
*********************************************************************/
void ew_get_esn
    (
    void
    )
{
#ifdef _DeviceInterfaceSystemDeviceClass_
if( pdFALSE == EEPM_get_ESN( &EW_read_esn_callback ) )
    {
    EwPrint( "%s false\r\n", __FUNCTION__ );
    }
#endif
}

/*********************************************************************
*
* @private
* ew_get_info_from_eeprom
*
* Get info from EEPROM
*
*********************************************************************/
static void ew_get_info_from_eeprom
    (
    void
    )
{
#ifdef _DeviceInterfaceSystemDeviceClass_
if( pdFALSE == EEPM_get_operation_mode( &EW_read_operation_mode_callback ) )
    {
    EwPrint( "get op mode fail\r\n" );
    }
if( pdFALSE == EEPM_get_ESN( &EW_read_esn_callback ) )
    {
    EwPrint( "get esn fail\r\n" );
    }
if( pdFALSE == EEPM_get_qrcode_ccuid( &EW_read_qrcode_ccuid_callback ) )
    {
    EwPrint( "get ccuid fail\r\n" );
    }
if( pdFALSE == EEPM_get_qrcode_passkey( &EW_read_passkey_callback ) )
    {
    EwPrint( "get passkey fail\r\n" );
    }
if( pdFALSE == EEPM_get_qrcode_dummy( &EW_read_qrcode_dummy_callback ) )
    {
    EwPrint( "get dummy fail\r\n" );
    }
if( pdFALSE == EEPM_get_last_page( &EW_get_last_page_callback ) )
    {
    EwPrint( "get last page err\r\n" );
    }
#endif
}

/*********************************************************************
*
* @private
* ew_get_rtc_time
*
* Get RTC time
*
* @param srtc_datetime The pointer to the rtc datetime
*
*********************************************************************/
void ew_get_rtc_time
    (
    snvs_lp_srtc_datetime_t* srtc_datetime
    )
{
RTC_get_DateTime( srtc_datetime );
}

/*********************************************************************
*
* @private
* ew_set_rtc_time
*
* Set RTC time
*
* @param srtc_datetime The pointer to the rtc datetime
*
*********************************************************************/
void ew_set_rtc_time
    (
    snvs_lp_srtc_datetime_t* srtc_datetime
    )
{
RTC_set_DateTime( srtc_datetime );
}

/*********************************************************************
*
* @private
* ew_is_debug_build
*
* Return if the current build is debug build
*
* @retVal true if debug build; false if release build
*
*********************************************************************/
XBool ew_is_debug_build
    (
    void
    )
{
#ifdef NDEBUG
    return false;
#else
    return true;
#endif
}

/*********************************************************************
*
* @private
* ew_handle_special_characters
*
* Stuff '%' before '%', '^', '~'
*
* @param in_str Pointer to input string
* @param out Pointer to output string
* @return Length of the output string
*
*********************************************************************/
int ew_handle_special_characters
    (
    const uint8_t* in_str,
    uint8_t**      out_str
    )
{
int i = 0;
int ew_str_idx = 0;

while( 1 )
    {
    if( '\0' == in_str[i] )
        {
        break;
        }

    if( ( '%' == in_str[i] ) ||
        ( '^' == in_str[i] ) ||
        ( '~' == in_str[i] ) )
        {
        ew_string[ew_str_idx++] = '%';
        }
    ew_string[ew_str_idx++] = in_str[i++];

    if( EW_STRING_LEN == ew_str_idx )
        {
        ew_string[EW_STRING_LEN - 1] = '\0';
        break;
        }
    }

if( 0 < ew_str_idx )
    {
    *out_str = ew_string;
    }

return ew_str_idx;
}

/*********************************************************************
*
* @private
* ew_system_update_local_time
*
* Notify EW GUI to update time
*
*********************************************************************/
#ifdef _DeviceInterfaceSystemDeviceClass__NotifyUpdateLocalTime_
    static int ew_system_update_local_time
        (
        void
        )
    {
    int need_update = 0;
    if( is_update_time )
        {
        is_update_time = 0;
        DeviceInterfaceSystemDeviceClass_NotifyUpdateLocalTime( device_object );
        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @private
* ew_sytem_test_display_pattern
*
* Notify EW GUI to show display test pattern
*
*********************************************************************/
#ifdef _DeviceInterfaceSystemDeviceClass__TestDisplayPattern_
    static int ew_sytem_test_display_pattern
        (
        void
        )
    {
    int need_update = 0;
    if( factory_test_event & FACTORY_TEST_EVENT_DISP_PATTERN )
        {
        factory_test_event &= ~FACTORY_TEST_EVENT_DISP_PATTERN;
        DeviceInterfaceSystemDeviceClass__TestDisplayPattern( device_object, factory_test_disp_pattern_idx );
        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @private
* ew_system_quit_test
*
* Notify EW GUI to quit test
*
*********************************************************************/
#ifdef _DeviceInterfaceSystemDeviceClass__QuitTest_
    static int ew_system_quit_test
        (
        void
        )
    {
    int need_update = 0;
    if( factory_test_event & FACTORY_TEST_EVENT_DISP_QUIT )
        {
        factory_test_event &= ~FACTORY_TEST_EVENT_DISP_QUIT;
        DeviceInterfaceSystemDeviceClass_QuitTest( device_object );

        is_running_production_test = false;
        ew_set_operation_mode( operation_mode_in_eep );

        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @private
* ew_start_burn_in_test
*
* Notify EW GUI to start burn in test
*
*********************************************************************/
#ifdef _DeviceInterfaceSystemDeviceClass__StartBurnInTest_
    static int ew_start_burn_in_test
        (
        void
        )
    {
    int need_update = 0;
    if( factory_test_event & FACTORY_TEST_EVENT_BURNIN_START )
        {
        factory_test_event &= ~FACTORY_TEST_EVENT_BURNIN_START;
        DeviceInterfaceSystemDeviceClass_StartBurnInTest( device_object );
        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @private
* ew_start_burn_in_test
*
* Notify EW GUI to update burn in test time
*
*********************************************************************/
#ifdef _DeviceInterfaceSystemDeviceClass__UpdateBurnInTestTime_
    static int ew_update_burn_in_test_time
        (
        void
        )
    {
    int need_update = 0;
    if( factory_test_event & FACTORY_TEST_EVENT_BURNIN_TIME_UPDATE )
        {
        factory_test_event &= ~FACTORY_TEST_EVENT_BURNIN_TIME_UPDATE;
        DeviceInterfaceSystemDeviceClass_UpdateBurnInTestTime( device_object, factory_test_burn_in_time_sec );
        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @private
* ew_start_burn_in_test
*
* Notify EW GUI to update burn in test time
*
*********************************************************************/
#ifdef _DeviceInterfaceSystemDeviceClass__ShowBurnInTestResult_
    static int ew_show_burn_in_test_result
        (
        void
        )
    {
    int need_update = 0;
    if( factory_test_event & FACTORY_TEST_EVENT_BURNIN_RESULT )
        {
        factory_test_event &= ~FACTORY_TEST_EVENT_BURNIN_RESULT;
        DeviceInterfaceSystemDeviceClass_ShowBurnInTestResult( device_object, factory_test_burn_in_result );
        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @private
* ew_system_notify_esn
*
* Notify EW GUI to quit test
*
*********************************************************************/
#ifdef _DeviceInterfaceSystemDeviceClass__NotifyEsnRead_
    static int ew_system_notify_esn
        (
        void
        )
    {
    int need_update = 0;
    if( is_esn_read )
        {
        is_esn_read = 0;
        char esn_decimal[ESN_STR_MAX_LEN + 1];
        sprintf( esn_decimal, "%u", esn );
        XString esn_str = EwNewStringAnsi( esn_decimal );
        DeviceInterfaceSystemDeviceClass__NotifyEsnRead( device_object, esn_str );
        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @private
* ew_notify_factory_reset_complete
*
* Notify the factory reset result to EW
*
*********************************************************************/
#ifdef _DeviceInterfaceSystemDeviceClass__NotifyFactoryResetComplete_
    static int ew_notify_factory_reset_complete
        (
        void
        )
    {
    int need_update = 0;
    if( is_factory_reset_complete )
        {
        is_factory_reset_complete = 0;
        DeviceInterfaceSystemDeviceClass_NotifyFactoryResetComplete( device_object );
        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @private
* ew_done_factory_reset
*
* Set the flag is_factory_reset_complete when data is reset
*
*********************************************************************/
void ew_done_factory_reset
    (
    void
    )
{
is_factory_reset_complete = 1;
}

/*********************************************************************
*
* @private
* ew_reboot_system
*
* Device interface to trigger system reboot
*
*********************************************************************/
void ew_reboot_system
    (
    void
    )
{
PM_system_reset();
}

/*********************************************************************
*
* @private
* ew_request_qrcode
*
* Request to generate QR code
*
* @param pixel_per_mod Pixel per QR code module
*
*********************************************************************/
void ew_request_qrcode
    (
    int pixel_per_mod
    )
{
QR_generate_qrcode( esn, pixel_per_mod );
//TODO:
//QR_generate_qrcode( ccuid, qrcode_passkey, qrcode_dummy );
}

/*********************************************************************
*
* @private
* ew_set_operation_mode
*
* Set operation mode
*
* @param mode Operation mode of EnumOperationMode type
*
*********************************************************************/
void ew_set_operation_mode
    (
    EnumOperationMode mode
    )
{
PRINTF( "%s %d\r\n", __FUNCTION__, mode );
EnumOperationMode last_operation_mode = operation_mode;

switch( mode )
    {
    case EnumOperationModeNORMAL:
    case EnumOperationModeFACTORY:
        if( operation_mode_in_eep != mode )
            {
            EEPM_set_operation_mode( mode, NULL );
            }

        if( !is_running_production_test )
            {
            operation_mode = mode;
            if( EnumOperationModePRODUCTION_TEST == last_operation_mode )
                {
                EW_notify_opening_event( OPENING_EVENT_OP_MODE_READY );
                }
            }
        break;

    case EnumOperationModeINSPECTION:
        if( EnumOperationModeFACTORY == operation_mode )
            {
            operation_mode = mode;
            }
        break;

    case EnumOperationModePRODUCTION_TEST:
        is_running_production_test = true;
        operation_mode = mode;
        break;

    default:
        PRINTF( "%s invalid %d\r\n", __FUNCTION__, mode );
        break;
    }

if( last_operation_mode != operation_mode )
    {
    client_appl_operation_mode_switch();
    }
}

/*********************************************************************
*
* @private
* EW_get_operation_mode
*
* Get current operation mode
*
* @param mode Pointer to operation mode
* @return True if operation mode from EEPROM is ready
*
*********************************************************************/
bool EW_get_operation_mode
    (
    EnumOperationMode* mode
    )
{
*mode = operation_mode;
return is_op_mode_ready;
}

/*********************************************************************
*
* @private
* ew_is_operation_mode_ready
*
* Check if the operation mode is read from EEPROM
*
* @return True if the operation mode is read from EEPROM
*
*********************************************************************/
bool ew_is_operation_mode_ready
    (
    void
    )
{
PRINTF( "%s %d\r\n", __FUNCTION__, operation_mode );
return is_op_mode_ready;
}

/*********************************************************************
*
* @private
* EW_get_ccuid
*
* Get CCUID
*
* @return CCUID
*
*********************************************************************/
uint32_t EW_get_ccuid
    (
    void
    )
{
PRINTF( "%s %d\r\n", __FUNCTION__, ccuid );
return ccuid;
}

/*********************************************************************
*
* @private
* EW_get_qrcode_dummy
*
* Get QR code dummy
*
* @return QR code dummy
*
*********************************************************************/
uint16_t EW_get_qrcode_dummy
    (
    void
    )
{
PRINTF( "%s %d\r\n", __FUNCTION__, qrcode_dummy );
return qrcode_dummy;
}

/*********************************************************************
*
* @private
* EW_get_qrcode_passkey
*
* Get QR code passkey
*
* @return QR code passkey
*
*********************************************************************/
uint32_t EW_get_qrcode_passkey
    (
    void
    )
{
PRINTF( "%s %d\r\n", __FUNCTION__, qrcode_passkey );
return qrcode_passkey;
}

/*********************************************************************
*
* @private
* ew_qrcode_ready
*
* Notify EW GUI that ESN QR code is ready
*
*********************************************************************/
#ifdef _DeviceInterfaceSystemDeviceClass__NotifyQrCodeReady_
    static int ew_qrcode_ready
        (
        void
        )
    {
    int need_update = 0;
    if( notify_qrcode_ready )
        {
        notify_qrcode_ready = false;
        XString qrcode_str = EwNewStringAnsi( qr_code );
        DeviceInterfaceSystemDeviceClass__NotifyQrCodeReady( device_object, qrcode_str );
        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @private
* ew_notify_vi_dd_mode_state_changed
*
* Notify EW GUI the inspection mode request
*
*********************************************************************/
#ifdef _DeviceInterfaceSystemDeviceClass__NotifyInspectionRequest_
    static int ew_notify_inspection_mode_request
        (
        void
        )
    {
    int need_update = 0;
    if( is_inspection_request_received )
        {
        is_inspection_request_received = false;
        DeviceInterfaceSystemDeviceClass__NotifyInspectionRequest( device_object, inspection_mode, inspection_display_pattern );
        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @private
* ew_notify_last_page_read
*
* Notify EW UI the last page has been read from EEPROM
*
*********************************************************************/
#ifdef _DeviceInterfaceSystemDeviceClass__NotifyLastPageRead_
    static int ew_notify_last_page_read
        (
        void
        )
    {
    int need_update = 0;
    if( is_last_page_read )
        {
        is_last_page_read = false;
        DeviceInterfaceSystemDeviceClass__NotifyLastPageRead( device_object );
        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @public
* EW_test_display_pattern
*
* Request Embedded Wizard to show display pattern
*
* @param index The display test pattern index
*
*********************************************************************/
void EW_test_display_pattern
    (
    int index
    )
{
#ifdef _DeviceInterfaceSystemDeviceClass_
    ew_set_operation_mode( EnumOperationModePRODUCTION_TEST );
    factory_test_disp_pattern_idx = index;
    factory_test_event |= FACTORY_TEST_EVENT_DISP_PATTERN;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @public
* EW_quit_test
*
* Request Embedded Wizard to quit test
*
*********************************************************************/
void EW_quit_test
    (
    void
    )
{
#ifdef _DeviceInterfaceSystemDeviceClass_
    factory_test_event |= FACTORY_TEST_EVENT_DISP_QUIT;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @public
* EW_start_burn_in
*
* Start Embedded Wizard burn-in UI
*
*********************************************************************/
void EW_start_burn_in
    (
    void
    )
{
#ifdef _DeviceInterfaceSystemDeviceClass_
    PRINTF( "%s\r\n", __FUNCTION__ );
    ew_set_operation_mode( EnumOperationModePRODUCTION_TEST );
    factory_test_event |= FACTORY_TEST_EVENT_BURNIN_START;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @public
* EW_update_burn_in_time
*
* Update burn in test time
*
* @param time_sec The burn-in time in second
*
*********************************************************************/
void EW_update_burn_in_time
    (
    const uint32_t time_sec
    )
{
#ifdef _DeviceInterfaceSystemDeviceClass_
    factory_test_burn_in_time_sec = time_sec;
    factory_test_event |= FACTORY_TEST_EVENT_BURNIN_TIME_UPDATE;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @public
* EW_show_burn_in_result
*
* Show burn-in test result
*
* @param result The burn-in test result
*
*********************************************************************/
void EW_show_burn_in_result
    (
    const bool result
    )
{
#ifdef _DeviceInterfaceSystemDeviceClass_
    factory_test_burn_in_result = result;
    factory_test_event |= FACTORY_TEST_EVENT_BURNIN_RESULT;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @public
* EW_notify_qrcode_ready
*
* Notify Embedded Wizard QR code is ready.
*
*********************************************************************/
void EW_notify_qrcode_ready
    (
    const char* qr_code_text
    )
{
#ifdef _DeviceInterfaceSystemDeviceClass_
    is_qrcode_ready = 1;
    notify_qrcode_ready = true;
    strncpy( qr_code, qr_code_text, sizeof( qr_code ) );
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @private
* ew_is_qrcode_ready
*
* Get if QR code is ready
*
*********************************************************************/
bool ew_is_qrcode_ready
    (
    void
    )
{
return is_qrcode_ready;
}

/*********************************************************************
*
* @private
* start_opening
*
* Start opening
*
*********************************************************************/
static void start_opening
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
#ifdef _DeviceInterfaceSystemDeviceClass__StartOpening_
    DeviceInterfaceSystemDeviceClass__StartOpening( device_object );
#endif
}

/*********************************************************************
*
* @public
* EW_notify_opening_event
*
* Start opening if both TFT backlight is on and operation mode is ready
*
* @param event TFT backlight on or operation mode ready event
*
*********************************************************************/
void EW_notify_opening_event
    (
    const opening_event event
    )
{
PRINTF( "%s %d\r\n", __FUNCTION__, event );
if( OPENING_EVENT_TFT_BACKLIGHT_ON == event )
    {
    is_tft_backlight_on = true;
    }

if( is_tft_backlight_on && is_op_mode_ready )
    {
    start_opening();
    }
}

/*********************************************************************
*
* @public
* EW_notify_inspection_request
*
* Notify Embedded Wizard inspection request
* @param mode Inspection mode
* @param display_pattern Inspection display pattern
*
*********************************************************************/
void EW_notify_inspection_request
    (
    EnumInspectionMode    mode,
    EnumInspectionDisplay display_pattern
    )
{
#ifdef _DeviceInterfaceSystemDeviceClass_
    inspection_mode = mode;
    inspection_display_pattern = display_pattern;
    is_inspection_request_received = true;
    EwBspEventTrigger();
#endif
}
