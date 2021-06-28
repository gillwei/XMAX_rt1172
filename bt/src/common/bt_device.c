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
@brief   Get the paired device's info by index
@details Get the paired device's info by index
@return  None
@retval  Constant pointer to the paired device's info
================================================================================================*/
const BT_device_info_t* BT_device_get_info
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

if( ( NULL == bd_addr ) || ( BT_DEVICE_ADDRESS_LEN != strlen( (const char*)bd_addr ) ) )
    {
    BT_LOG_DEBUG( "Invalid BD address" );
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
@brief   Check whether or not this is a paired device
@details Check whether or not this is a paired device
@return  None
@retval  Whether or not this is a paired device
================================================================================================*/
bool BT_device_is_existed
    (
    const uint8_t* bd_addr
    )
{
bool existed = false;

if( ( NULL == bd_addr ) || ( BT_DEVICE_ADDRESS_LEN != strlen( (const char*)bd_addr ) ) )
    {
    BT_LOG_DEBUG( "Invalid BD address" );
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
                existed = true;
                break;
                }
            }
        xSemaphoreGive( s_mutex );
        }
    }
return existed;
}

/*================================================================================================
@brief   Update the local paired device list using the paired device list sent from Cypress module
@details Update the local paired device list using the devices extracted from the paired device
         list sent from Cypress module.
         For easier to sync paired device info between MCU and Cypress module, we ask the module
         to send paired device list in ONE hci event. The buffer size of hci payload defined in
         Cypress module is 240 bytes(defined in HCI_PAYLOAD_MAX_SIZE), and we need to store at
         most 8 paired devices(defined in MAX_PAIRED_DEVICES). It turns out that the size of the
         struct that Cypress module uses to store paired device info(defined in BT_device_info_t)
         is limited as below:
           - bd_addr:      6 bytes (BT_DEVICE_ADDRESS_LEN)
           - device_name: 20 bytes (BT_DEVICE_NAME_LEN)
           - device type:  1 byte
           - auth_lost:    1 byte
           - iap_support:  1 byte
         And the format of the paired device list sent by Cypress module is as below:
           - Byte[0]: Number of paired devices
           - Byte[n]: Info of paired devices, where n <= ( HCI_PAYLOAD_MAX_SIZE - 1 )
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_device_update
    (
    const uint8_t* raw_device_list
    )
{
bool ret = false;
uint8_t cur_pos = 0;

if( NULL == raw_device_list )
    {
    BT_LOG_ERROR( "NULL device list" );
    }
else
    {
    if( false == xSemaphoreTake( s_mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
        {
        BT_LOG_ERROR( "Mutex lock timeout" );
        }
    else
        {
        memset( s_paired_devices, 0, sizeof( s_paired_devices ) );

        s_num_paired_devices = raw_device_list[cur_pos++];

        for( uint8_t i = 0; i < s_num_paired_devices; ++i )
            {
            memcpy( &( s_paired_devices[i] ), &( raw_device_list[cur_pos] ), sizeof( BT_device_info_t ) );
            cur_pos += sizeof( BT_device_info_t );

            BT_LOG_DEBUG( "Device[%u]: %02x:%02x:%02x:%02x:%02x:%02x, name=%s, type=%s, auth_lost=%d, iAP_support=%d",
                          i,
                          BD_ADDR_PRINT( s_paired_devices[i].bd_addr ),
                          s_paired_devices[i].device_name,
                          BT_util_get_device_type_string( s_paired_devices[i].device_type ),
                          s_paired_devices[i].auth_lost,
                          s_paired_devices[i].iap_support );
            }
        ret = true;
        }
    xSemaphoreGive( s_mutex );
    }
return ret;
}

#ifdef __cplusplus
}
#endif
