/*********************************************************************
* @file  bt_db.c
* @brief Bluetooth Manager Database interface definition.
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
#include <stdio.h>
#include <string.h>

#include "EEPM_pub.h"

#include "bt_db.h"
#include "bt_log.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define EEPROM_CALLBACK_MS ( 3000 )

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef void ( *EEPROM_callback )( bool result, void* data );

typedef struct BT_db_enable_state
    {
    bool sync;
    EEPROM_callback callback;
    bool enable_state;
    } BT_db_enable_state_t;

typedef struct BT_db_local_device_address
    {
    bool sync;
    EEPROM_callback callback;
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    } BT_db_local_device_address_t;

typedef struct BT_db_local_device_name
    {
    bool sync;
    EEPROM_callback callback;
    uint8_t device_name[BT_DEVICE_NAME_LEN];
    } BT_db_local_device_name_t;

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/
static void BT_db_eeprom_enable_state_callback
    (
    bool result,
    void* data
    );

static void BT_db_eeprom_local_device_address_callback
    (
    bool result,
    void* data
    );

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
static BT_db_enable_state_t s_db_enable_state_info =
    {
    .sync = false,
    .callback = BT_db_eeprom_enable_state_callback,
    .enable_state = false
    };

static BT_db_local_device_address_t s_db_local_device_address_info =
    {
    .sync = false,
    .callback = BT_db_eeprom_local_device_address_callback,
    .bd_addr = { 0 }
    };

static BT_db_local_device_name_t s_db_local_device_name_info =
    {
    .sync = false,
    .callback = NULL,
    .device_name = "LINKCARD"
    };

static SemaphoreHandle_t s_binary_semaphore = NULL;

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   EEPROM callback of setting or getting the BT enable state
@details EEPROM callback of setting or getting the BT enable state
@return  None
@retval  None
================================================================================================*/
static void BT_db_eeprom_enable_state_callback
    (
    bool result,
    void* data
    )
{
if( result )
    {
    s_db_enable_state_info.sync = true;
    s_db_enable_state_info.enable_state = ( 0 == *( (uint8_t*)data ) ? false : true );
    }
else
    {
    s_db_enable_state_info.sync = false;
    s_db_enable_state_info.enable_state = false;
    }
xSemaphoreGive( s_binary_semaphore );
}


/*================================================================================================
@brief   EEPROM callback of setting or getting the local device address
@details EEPROM callback of setting or getting the local device address
@return  None
@retval  None
================================================================================================*/
static void BT_db_eeprom_local_device_address_callback
    (
    bool result,
    void* data
    )
{
if( result )
    {
    s_db_local_device_address_info.sync = true;
    memcpy( s_db_local_device_address_info.bd_addr, (uint8_t*)data, BT_DEVICE_ADDRESS_LEN );
    }
else
    {
    s_db_local_device_address_info.sync = false;
    memset( s_db_local_device_address_info.bd_addr, 0, BT_DEVICE_ADDRESS_LEN );
    }
xSemaphoreGive( s_binary_semaphore );
}

/*================================================================================================
@brief   Get the BT enable state from EEPROM
@details Get the BT enable state from EEPROM
@return  None
@retval  Whether or not the BT state is enabled
================================================================================================*/
bool BT_db_get_enable_state( void )
{
if( false == s_db_enable_state_info.sync )
    {
    if( pdTRUE != EEPM_get_BT_en( s_db_enable_state_info.callback ) )
        {
        BT_LOG_ERROR( "EEPROM operation error" );
        return false;
        }

    if( pdTRUE != xSemaphoreTake( s_binary_semaphore, pdMS_TO_TICKS( EEPROM_CALLBACK_MS ) ) )
        {
        BT_LOG_ERROR( "EEPROM timeout" );
        return false;
        }

    if( false == s_db_enable_state_info.sync )
        {
        BT_LOG_ERROR( "EEPROM result error" );
        return false;
        }
    }
return s_db_enable_state_info.enable_state;
}

/*================================================================================================
@brief   Get the local device address from EEPROM
@details Get the local device address from EEPROM
@return  None
@retval  Constant pointer to the local device address
================================================================================================*/
const uint8_t* BT_db_get_local_device_address( void )
{
if( false == s_db_local_device_address_info.sync )
    {
    if( pdTRUE != EEPM_get_bd_address( s_db_local_device_address_info.callback ) )
        {
        BT_LOG_ERROR( "EEPROM operation error" );
        return false;
        }

    if( pdTRUE != xSemaphoreTake( s_binary_semaphore, pdMS_TO_TICKS( EEPROM_CALLBACK_MS ) ) )
        {
        BT_LOG_ERROR( "EEPROM timeout" );
        return false;
        }

    if( false == s_db_local_device_address_info.sync )
        {
        BT_LOG_ERROR( "EEPROM result error" );
        return false;
        }
    }
return s_db_local_device_address_info.bd_addr;
}

/*================================================================================================
@brief   Get the local device name from EEPROM
@details Get the local device name from EEPROM
@return  None
@retval  Constant pointer to the local device name
================================================================================================*/
const uint8_t* BT_db_get_local_device_name( void )
{
return s_db_local_device_name_info.device_name;
}

/*================================================================================================
@brief   Bluetooth Manager Database initialization
@details Bluetooth Manager Database initialization
@return  None
@retval  None
================================================================================================*/
void BT_db_init( void )
{
if( NULL == s_binary_semaphore )
    {
    // The binary semaphore created using xSemaphoreCreateBinary is created in Taken state
    s_binary_semaphore = xSemaphoreCreateBinary();
    configASSERT( NULL != s_binary_semaphore );
    }
}

/*================================================================================================
@brief   Set the BT enable state to EEPROM
@details Set the BT enable state to EEPROM
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_db_set_enable_state
    (
    const bool enable
    )
{
if( pdTRUE != EEPM_set_BT_en( enable, s_db_enable_state_info.callback ) )
    {
    BT_LOG_ERROR( "EEPROM operation error" );
    return false;
    }

if( pdTRUE != xSemaphoreTake( s_binary_semaphore, pdMS_TO_TICKS( EEPROM_CALLBACK_MS ) ) )
    {
    BT_LOG_ERROR( "EEPROM timeout" );
    return false;
    }

if( false == s_db_enable_state_info.sync )
    {
    BT_LOG_ERROR( "EEPROM result error" );
    return false;
    }

return true;
}

/*================================================================================================
@brief   Set the local device address to EEPROM
@details Set the local device address to EEPROM
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_db_set_local_device_address
    (
    const uint8_t* bd_addr
    )
{
if( ( NULL == bd_addr ) || ( BT_DEVICE_ADDRESS_LEN != strlen( (const char*)bd_addr ) ) )
    {
    BT_LOG_ERROR( "Invalid BD address" );
    return false;
    }

if( pdTRUE != EEPM_set_bd_address( (uint8_t*)bd_addr, s_db_local_device_address_info.callback ) )
    {
    BT_LOG_ERROR( "EEPROM operation error" );
    return false;
    }

if( pdTRUE != xSemaphoreTake( s_binary_semaphore, pdMS_TO_TICKS( EEPROM_CALLBACK_MS ) ) )
    {
    BT_LOG_ERROR( "EEPROM timeout" );
    return false;
    }

if( false == s_db_local_device_address_info.sync )
    {
    BT_LOG_ERROR( "EEPROM result error" );
    return false;
    }

return true;
}

/*================================================================================================
@brief   Set the local device name to EEPROM
@details Set the local device name to EEPROM
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_db_set_local_device_name
    (
    const uint8_t* device_name
    )
{
if( NULL == device_name )
    {
    BT_LOG_ERROR( "NULL device name" );
    return false;
    }

if( strlen( (const char*)device_name ) > BT_DEVICE_NAME_LEN )
    {
    BT_LOG_WARNING( "Truncated device name stored" );
    }

// TODO: Support storing local device name in EEPROM

snprintf( (char*)( s_db_local_device_name_info.device_name ), BT_DEVICE_NAME_LEN, "%s", device_name );
return true;
}

#ifdef __cplusplus
}
#endif
