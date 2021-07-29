/*********************************************************************
* @file  bt_device.c
* @brief Bluetooth Manager Device management interface definition.
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
#include <semphr.h>
#include <task.h>
#include <string.h>

#include "bt_device.h"
#include "bt_log.h"
#include "bt_utils.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define MAX_PAIRED_DEVICES ( 8 )

#define MUTEX_LOCK_MS ( 5000 )

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
static BT_device_info_t s_paired_devices[MAX_PAIRED_DEVICES] = { 0 };
static uint8_t s_num_paired_devices = 0;
static SemaphoreHandle_t s_mutex = NULL;

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Store the paired device info for further use
@details Store the paired device info for further use
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_device_add
    (
    const uint8_t idx,
    const uint8_t* bd_addr,
    const uint8_t* device_name,
    const BT_device_type_e device_type,
    const bool auth_lost,
    const bool iap_support
    )
{
bool ret = false;

if( false == xSemaphoreTake( s_mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
    {
    BT_LOG_ERROR( "Mutex lock timeout" );
    }
else
    {
    if( idx != s_num_paired_devices )
        {
        BT_LOG_ERROR( "Invalid paired device adding sequence: idx=%u, total_number=%u", idx, s_num_paired_devices );
        }
    else if( idx >= MAX_PAIRED_DEVICES )
        {
        BT_LOG_ERROR( "Maximum number of paired devices exceeded: %u (> %d)", idx, MAX_PAIRED_DEVICES );
        }
    else
        {
        memset( &( s_paired_devices[idx] ), 0, sizeof( BT_device_info_t ) );
        memcpy( s_paired_devices[idx].bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN );
        memcpy( s_paired_devices[idx].device_name, device_name, BT_DEVICE_NAME_LEN );
        s_paired_devices[idx].device_type = device_type;
        s_paired_devices[idx].auth_lost = auth_lost;
        s_paired_devices[idx].iap_support = iap_support;

        ++s_num_paired_devices;

        ret = true;
        BT_LOG_INFO( "Paired device added: idx=%u, bd_addr=%02x:%02x:%02x:%02x:%02x:%02x, total_number=%u",
                     idx,
                     BD_ADDR_PRINT( bd_addr ),
                     s_num_paired_devices );
        }
    xSemaphoreGive( s_mutex );
    }
return ret;
}

/*================================================================================================
@brief   Clear all the stored paired device info
@details Clear all the stored paired device info
@return  None
@retval  None
================================================================================================*/
void BT_device_clear( void )
{
if( false == xSemaphoreTake( s_mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
    {
    BT_LOG_ERROR( "Mutex lock timeout" );
    }
else
    {
    BT_LOG_DEBUG( "Paired devices all cleared" );
    s_num_paired_devices = 0;
    xSemaphoreGive( s_mutex );
    }
}

/*================================================================================================
@brief   Get the paired device's info by index
@details Get the paired device's info by index
@return  None
@retval  Constant pointer to the paired device's info
================================================================================================*/
const BT_device_info_t* BT_device_get
    (
    const uint8_t idx
    )
{
const BT_device_info_t* device_info;

if( false == xSemaphoreTake( s_mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
    {
    BT_LOG_ERROR( "Mutex lock timeout" );
    device_info = NULL;
    }
else
    {
    if( ( idx < 0 ) || ( idx >= s_num_paired_devices ) )
        {
        BT_LOG_WARNING( "Invalid index" );
        device_info = NULL;
        }
    else
        {
        device_info = &( s_paired_devices[idx] );
        }
    xSemaphoreGive( s_mutex );
    }
return device_info;
}

/*================================================================================================
@brief   Get the number of paired devices
@details Get the number of paired devices
@return  None
@retval  The number of paired devices
================================================================================================*/
uint8_t BT_device_get_total_num( void )
{
uint8_t num_devices = 0;

if( false == xSemaphoreTake( s_mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
    {
    BT_LOG_ERROR( "Mutex lock timeout" );
    }
else
    {
    num_devices = s_num_paired_devices;
    xSemaphoreGive( s_mutex );
    }
return num_devices;
}

/*================================================================================================
@brief   Get device type of the paired device
@details Get device type of the paired device
@return  None
@retval  Device type of the paired device
================================================================================================*/
BT_device_type_e BT_device_get_type
    (
    const uint8_t* bd_addr
    )
{
BT_device_type_e device_type = BT_DEVICE_TYPE_INVALID;

if( NULL == bd_addr )
    {
    BT_LOG_DEBUG( "NULL BD address" );
    }
else
    {
    if( false == xSemaphoreTake( s_mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
        {
        BT_LOG_ERROR( "Mutex lock timeout" );
        }
    else
        {
        for( uint8_t i = 0; i < s_num_paired_devices; ++i )
            {
            if( 0 == memcmp( s_paired_devices[i].bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN ) )
                {
                device_type = s_paired_devices[i].device_type;
                break;
                }
            }
        xSemaphoreGive( s_mutex );
        }
    }
return device_type;
}

/*================================================================================================
@brief   Bluetooth Manager Device management initialization
@details Bluetooth Manager Device management initialization
@return  None
@retval  None
================================================================================================*/
void BT_device_init( void )
{
if( NULL == s_mutex )
    {
    s_mutex = xSemaphoreCreateMutex();
    configASSERT( NULL != s_mutex );
    }
}

/*================================================================================================
@brief   Check whether or not the paired device has lost its authentication data
@details Check whether or not the paired device has lost its authentication data
@return  None
@retval  Whether or not the paired device has lost its authentication data
================================================================================================*/
bool BT_device_is_auth_lost
    (
    const uint8_t* bd_addr
    )
{
bool auth_lost = false;

if( NULL == bd_addr )
    {
    BT_LOG_DEBUG( "NULL BD address" );
    }
else
    {
    if( false == xSemaphoreTake( s_mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
        {
        BT_LOG_ERROR( "Mutex lock timeout" );
        }
    else
        {
        for( uint8_t i = 0; i < s_num_paired_devices; ++i )
            {
            if( 0 == memcmp( s_paired_devices[i].bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN ) )
                {
                auth_lost = s_paired_devices[i].auth_lost;
                break;
                }
            }
        xSemaphoreGive( s_mutex );
        }
    }
return auth_lost;
}

/*================================================================================================
@brief   Check whether or not the number of paired devices reached the limit
@details Check whether or not the number of paired devices reached the limit
@return  None
@retval  Whether or not the number of paired devices reached the limit
================================================================================================*/
bool BT_device_is_max_num_reached( void )
{
bool max_num_reached = false;

if( false == xSemaphoreTake( s_mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
    {
    BT_LOG_ERROR( "Mutex lock timeout" );
    }
else
    {
    max_num_reached = ( s_num_paired_devices >= MAX_PAIRED_DEVICES );
    xSemaphoreGive( s_mutex );
    }
return max_num_reached;
}

/*================================================================================================
@brief   Check whether or not the paired device supports iAP connection
@details Check whether or not the paired device supports iAP connection
@return  None
@retval  Whether or not the paired device supports iAP connection
================================================================================================*/
bool BT_device_is_iap_support
    (
    const uint8_t* bd_addr
    )
{
bool iap_support = false;

if( NULL == bd_addr )
    {
    BT_LOG_DEBUG( "NULL BD address" );
    }
else
    {
    if( false == xSemaphoreTake( s_mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
        {
        BT_LOG_ERROR( "Mutex lock timeout" );
        }
    else
        {
        for( uint8_t i = 0; i < s_num_paired_devices; ++i )
            {
            if( 0 == memcmp( s_paired_devices[i].bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN ) )
                {
                iap_support = s_paired_devices[i].iap_support;
                break;
                }
            }
        xSemaphoreGive( s_mutex );
        }
    }
return iap_support;
}

#ifdef __cplusplus
}
#endif
