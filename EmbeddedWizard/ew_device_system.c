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
#include "EEPM_pub.h"
#include "GRM_pub_prj.h"
#include "RTC_pub.h"
#include "PM_pub.h"
#include "QR_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#ifdef _DeviceInterfaceSystemDeviceClass_
    typedef int system_device_function( void );
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

#define ESN_STR_MAX_LEN             ( 10 )
#define INVALID_ESN                 ( 0xFFFFFFFF )

#define FACTORY_TEST_EVENT_DISP_PATTERN         ( 1 << 0 )
#define FACTORY_TEST_EVENT_DISP_QUIT            ( 1 << 1 )
#define FACTORY_TEST_EVENT_BURNIN_START         ( 1 << 2 )
#define FACTORY_TEST_EVENT_BURNIN_TIME_UPDATE   ( 1 << 3 )
#define FACTORY_TEST_EVENT_BURNIN_RESULT        ( 1 << 4 )

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
#ifdef _DeviceInterfaceSystemDeviceClass_
    static DeviceInterfaceSystemDeviceClass device_object = 0;
    system_device_function* const system_function_lookup_table[] =
        {
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
            ew_qrcode_ready
        #endif
        };
    const int num_of_system_func = sizeof( system_function_lookup_table )/sizeof( system_device_function* );

    static int      factory_test_event = 0;
    static int      factory_test_disp_pattern_idx = 0;
    static bool     factory_test_burn_in_result = false;
    static uint32_t factory_test_burn_in_time_sec = 0;

    static int is_esn_read = 0;
    static int is_factory_reset_complete = 0;
    static int is_qrcode_ready = 0;
#endif

static uint32_t esn;

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
* read_esn_callback
*
* Callback of ESN read
*
* @param result True if read success. False if read fail.
* @param value The pointer to the ESN of uint32_t* type.
*
*********************************************************************/
static void read_esn_callback
    (
    bool  result,
    void* value
    )
{
esn = *( uint32_t* )value;
if( INVALID_ESN != esn )
    {
    is_esn_read = 1;
    }
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
if( pdFALSE == EEPM_get_ESN( &read_esn_callback ) )
    {
    EwPrint( "%s false\r\n", __FUNCTION__ );
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
* @param datetime The pointer to the char array of datetime.
*
*********************************************************************/
void ew_get_rtc_time
    (
    char* datetime
    )
{
snvs_lp_srtc_datetime_t rtc_time;
RTC_get_DateTime( &rtc_time );
sprintf( datetime, "%02d:%02d", rtc_time.hour, rtc_time.minute );
}

/*********************************************************************
*
* @private
* ew_is_debug_build
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
    if( is_qrcode_ready )
        {
        is_qrcode_ready = 0;
        DeviceInterfaceSystemDeviceClass__NotifyQrCodeReady( device_object );
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
    void
    )
{
#ifdef _DeviceInterfaceSystemDeviceClass_
    is_qrcode_ready = 1;
    EwBspEventTrigger();
#endif
}