/*********************************************************************
* @file  cm_auto_connect_db.c
* @brief Connection Manager Auto-Connect Database interface definition.
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
#include <string.h>

#include "BT_pub.h"
#include "EEPM_pub.h"

#include "cm_auto_connect_db.h"
#include "cm_log.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define CMA_DEVICE_MAX_NUM ( 8 )

#define EEPROM_CALLBACK_MS ( 3000 )

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef BaseType_t ( *EEPM_get_auto_connect_device_func )( void ( *callback )(bool, void*) );
typedef BaseType_t ( *EEPM_set_auto_connect_device_func )( uint8_t* bd_addr, void ( *callback )(bool, void*) );

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
static SemaphoreHandle_t s_binary_semaphore = NULL;

static bool s_eepm_result = false;
static bool s_enable_state = false;
static uint8_t s_device_count = 0;
static uint8_t s_device_by_index[BT_DEVICE_ADDRESS_LEN] = { 0 };

static EEPM_get_auto_connect_device_func s_eepm_get_auto_connect_device_funcs[CMA_DEVICE_MAX_NUM] =
    {
    EEPM_get_auto_connect_device_1,
    EEPM_get_auto_connect_device_2,
    EEPM_get_auto_connect_device_3,
    EEPM_get_auto_connect_device_4,
    EEPM_get_auto_connect_device_5,
    EEPM_get_auto_connect_device_6,
    EEPM_get_auto_connect_device_7,
    EEPM_get_auto_connect_device_8
    };

static EEPM_set_auto_connect_device_func s_eepm_set_auto_connect_device_funcs[CMA_DEVICE_MAX_NUM] =
    {
    EEPM_set_auto_connect_device_1,
    EEPM_set_auto_connect_device_2,
    EEPM_set_auto_connect_device_3,
    EEPM_set_auto_connect_device_4,
    EEPM_set_auto_connect_device_5,
    EEPM_set_auto_connect_device_6,
    EEPM_set_auto_connect_device_7,
    EEPM_set_auto_connect_device_8
    };

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/
static void CMA_db_eepm_device_by_index_callback
    (
    bool result,
    void* data
    );

static void CMA_db_eepm_device_count_callback
    (
    bool result,
    void* data
    );

static void CMA_db_eepm_enable_state_callback
    (
    bool result,
    void* data
    );

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   EEPROM callback of setting or getting the auto-connect device by index
@details EEPROM callback of setting or getting the auto-connect device by index
@return  None
@retval  None
================================================================================================*/
static void CMA_db_eepm_device_by_index_callback
    (
    bool result,
    void* data
    )
{
s_eepm_result = result;
if( s_eepm_result )
    {
    memcpy( s_device_by_index, (uint8_t*)data, BT_DEVICE_ADDRESS_LEN );
    }
xSemaphoreGive( s_binary_semaphore );
}

/*================================================================================================
@brief   EEPROM callback of setting or getting the auto-connect device count
@details EEPROM callback of setting or getting the auto-connect device count
@return  None
@retval  None
================================================================================================*/
static void CMA_db_eepm_device_count_callback
    (
    bool result,
    void* data
    )
{
s_eepm_result = result;
if( s_eepm_result )
    {
    s_device_count = ( EEPROM_INVALID_VAL_1_BYTE == *( (uint8_t*)data ) ? 0 : *( (uint8_t*)data ) );
    }
xSemaphoreGive( s_binary_semaphore );
}

/*================================================================================================
@brief   EEPROM callback of setting or getting the auto-connect enable state
@details EEPROM callback of setting or getting the auto-connect enable state
@return  None
@retval  None
================================================================================================*/
static void CMA_db_eepm_enable_state_callback
    (
    bool result,
    void* data
    )
{
s_eepm_result = result;
if( s_eepm_result )
    {
    s_enable_state = ( 0 == *( (uint8_t*)data ) ? false : true );
    }
xSemaphoreGive( s_binary_semaphore );
}

/*================================================================================================
@brief   Get the auto-connect device from EEPROM by index
@details Get the auto-connect device from EEPROM by index
@return  None
@retval  The auto-connect device
================================================================================================*/
uint8_t* CMA_db_get_device_by_index
    (
    const uint8_t index
    )
{
BaseType_t ret = pdFALSE;

if( index >= CMA_DEVICE_MAX_NUM )
    {
    CM_LOG_ERROR( "Index exceeded maximum number of devices: %u (> %d)", index, CMA_DEVICE_MAX_NUM );
    }
else
    {
    ret = s_eepm_get_auto_connect_device_funcs[index]( CMA_db_eepm_device_by_index_callback );
    if( pdTRUE != ret )
        {
        CM_LOG_ERROR( "EEPROM operation error" );
        }
    else
        {
        ret = xSemaphoreTake( s_binary_semaphore, pdMS_TO_TICKS( EEPROM_CALLBACK_MS ) );
        if( pdTRUE != ret )
            {
            CM_LOG_ERROR( "EEPROM timeout" );
            }
        else
            {
            if( false == s_eepm_result )
                {
                CM_LOG_ERROR( "EEPROM result error" );
                ret = pdFALSE;
                }
            }
        }
    }
return ( pdTRUE == ret ? s_device_by_index : NULL );
}

/*================================================================================================
@brief   Get the auto-connect device count from EEPROM
@details Get the auto-connect device count from EEPROM
@return  None
@retval  The auto-connect device count
================================================================================================*/
uint8_t CMA_db_get_device_count( void )
{
BaseType_t ret = EEPM_get_auto_connect_device_count( CMA_db_eepm_device_count_callback );

if( pdTRUE != ret )
    {
    CM_LOG_ERROR( "EEPROM operation error" );
    }
else
    {
    ret = xSemaphoreTake( s_binary_semaphore, pdMS_TO_TICKS( EEPROM_CALLBACK_MS ) );
    if( pdTRUE != ret )
        {
        CM_LOG_ERROR( "EEPROM timeout" );
        }
    else
        {
        if( false == s_eepm_result )
            {
            CM_LOG_ERROR( "EEPROM result error" );
            ret = pdFALSE;
            }
        }
    }
return ( pdTRUE == ret ? s_device_count : 0 );
}

/*================================================================================================
@brief   Get the auto-connect enable state from EEPROM
@details Get the auto-connect enable state from EEPROM
@return  None
@retval  The auto-connect enable state
================================================================================================*/
bool CMA_db_get_enable_state( void )
{
BaseType_t ret = EEPM_get_auto_connect_en( CMA_db_eepm_enable_state_callback );

if( pdTRUE != ret )
    {
    CM_LOG_ERROR( "EEPROM operation error" );
    }
else
    {
    ret = xSemaphoreTake( s_binary_semaphore, pdMS_TO_TICKS( EEPROM_CALLBACK_MS ) );
    if( pdTRUE != ret )
        {
        CM_LOG_ERROR( "EEPROM timeout" );
        }
    else
        {
        if( false == s_eepm_result )
            {
            CM_LOG_ERROR( "EEPROM result error" );
            ret = pdFALSE;
            }
        }
    }
return ( pdTRUE == ret ? s_enable_state : false );
}

/*================================================================================================
@brief   Connection Manager Auto-Connect Database initialization
@details Connection Manager Auto-Connect Database initialization
@return  None
@retval  None
================================================================================================*/
void CMA_db_init( void )
{
if( NULL == s_binary_semaphore )
    {
    // The binary semaphore created using xSemaphoreCreateBinary is created in Taken state
    s_binary_semaphore = xSemaphoreCreateBinary();
    configASSERT( NULL != s_binary_semaphore );

    configASSERT( CMA_DEVICE_MAX_NUM ==
                  ( sizeof( s_eepm_get_auto_connect_device_funcs ) / sizeof( EEPM_get_auto_connect_device_func ) ) );

    configASSERT( CMA_DEVICE_MAX_NUM ==
                  ( sizeof( s_eepm_set_auto_connect_device_funcs ) / sizeof( EEPM_set_auto_connect_device_func ) ) );
    }
}

/*================================================================================================
@brief   Set the auto-connect device to EEPROM by index
@details Set the auto-connect device to EEPROM by index
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool CMA_db_set_device_by_index
    (
    const uint8_t index,
    const uint8_t* bd_addr
    )
{
BaseType_t ret = pdFALSE;

if( index >= CMA_DEVICE_MAX_NUM )
    {
    CM_LOG_ERROR( "Index exceeded maximum number of devices: %u (> %d)", index, CMA_DEVICE_MAX_NUM );
    }
else
    {
    ret = s_eepm_set_auto_connect_device_funcs[index]( bd_addr, CMA_db_eepm_device_by_index_callback );
    if( pdTRUE != ret )
        {
        CM_LOG_ERROR( "EEPROM operation error" );
        }
    else
        {
        ret = xSemaphoreTake( s_binary_semaphore, pdMS_TO_TICKS( EEPROM_CALLBACK_MS ) );
        if( pdTRUE != ret )
            {
            CM_LOG_ERROR( "EEPROM timeout" );
            }
        else
            {
            if( false == s_eepm_result )
                {
                CM_LOG_ERROR( "EEPROM result error" );
                ret = pdFALSE;
                }
            }
        }
    }
return ( pdTRUE == ret );
}

/*================================================================================================
@brief   Set the auto-connect device count to EEPROM
@details Set the auto-connect device count to EEPROM
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool CMA_db_set_device_count
    (
    const uint8_t device_count
    )
{
BaseType_t ret = EEPM_set_auto_connect_device_count( device_count, CMA_db_eepm_device_count_callback );

if( pdTRUE != ret )
    {
    CM_LOG_ERROR( "EEPROM operation error" );
    }
else
    {
    ret = xSemaphoreTake( s_binary_semaphore, pdMS_TO_TICKS( EEPROM_CALLBACK_MS ) );
    if( pdTRUE != ret )
        {
        CM_LOG_ERROR( "EEPROM timeout" );
        }
    else
        {
        if( false == s_eepm_result )
            {
            CM_LOG_ERROR( "EEPROM result error" );
            ret = pdFALSE;
            }
        }
    }
return ( pdTRUE == ret );
}

/*================================================================================================
@brief   Set the auto-connect enable state to EEPROM
@details Set the auto-connect enable state to EEPROM
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool CMA_db_set_enable_state
    (
    const bool enable
    )
{
BaseType_t ret = EEPM_set_auto_connect_en( enable, CMA_db_eepm_enable_state_callback );

if( pdTRUE != ret )
    {
    CM_LOG_ERROR( "EEPROM operation error" );
    }
else
    {
    ret = xSemaphoreTake( s_binary_semaphore, pdMS_TO_TICKS( EEPROM_CALLBACK_MS ) );
    if( pdTRUE != ret )
        {
        CM_LOG_ERROR( "EEPROM timeout" );
        }
    else
        {
        if( false == s_eepm_result )
            {
            CM_LOG_ERROR( "EEPROM result error" );
            ret = pdFALSE;
            }
        }
    }
return ( pdTRUE == ret );
}

#ifdef __cplusplus
}
#endif
