/*******************************************************************************
*@ File eepm.c
*@ Brief eeprom management
*
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
********************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "EEPM_pub.h"
#include "eep_prv.h"
#include "FreeRTOS.h"
#include "semphr.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef struct
    {
    bool       cb_write;
    bool       need_verified;
    uint32_t   write_val;
    uint32_t   read_val;
    void (*callback_ptr)(bool, void*);
    SemaphoreHandle_t semaphore;
    }eepm_data_type;

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
static eepm_data_type eepm_data[EEPM_BLOCK_CONFIG_CNT];
static const uint8_t page_id_lock = 0x02;
static uint8_t write_bd_address[BD_ADDRESS_LENGTH]; // Use for store compare bd address value
static uint8_t read_bd_address[BD_ADDRESS_LENGTH];  // Use for store compare bd address value

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
static void eepm_w_callback
    (
    EEPM_block_config_type eepm_cfg,
    status_t status
    );

static void eepm_r_callback
    (
    EEPM_block_config_type eepm_cfg,
    status_t status
    );

static void eepm_ESN_w_callback
    (
    status_t status
    );

static void eepm_ESN_r_callback
    (
    status_t status
    );

static void eepm_BT_en_w_callback
    (
    status_t status
    );

static void eepm_BT_en_r_callback
    (
    status_t status
    );

static void eepm_BT_autoconn_w_callback
    (
    status_t status
    );

static void eepm_BT_autoconn_r_callback
    (
    status_t status
    );

static void eepm_last_page_w_callback
    (
    status_t status
    );

static void eepm_last_page_r_callback
    (
    status_t status
    );

static void eepm_id_page_lock_callback
    (
    status_t status
    );

static void eepm_language_w_callback
    (
    status_t status
    );

static void eepm_language_r_callback
    (
    status_t status
    );

static void eepm_start_burn_in_w_callback
    (
    status_t status
    );

static void eepm_start_burn_in_r_callback
    (
    status_t status
    );

static void eepm_burn_in_result_w_callback
    (
    status_t status
    );

static void eepm_burn_in_result_r_callback
    (
    status_t status
    );

/*================================================================================================*/
/**
@brief   eepm_w_callback
@details eepm_w_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_w_callback
    (
    EEPM_block_config_type eepm_cfg,
    status_t status
    )
{
if( kStatus_Success == status )
    {
    eepm_data[eepm_cfg].cb_write = true;
    }
else
    {
    eepm_data[eepm_cfg].cb_write = false;
    }
}

/*================================================================================================*/
/**
@brief   eepm_r_callback
@details eepm_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_r_callback
    (
    EEPM_block_config_type eepm_cfg,
    status_t status
    )
{
bool rtn = false;
xSemaphoreGive( eepm_data[eepm_cfg].semaphore );
if( kStatus_Success == status )
    {
    if( eepm_data[eepm_cfg].need_verified )
        {
        if( eepm_data[eepm_cfg].cb_write )
            {
            if( eepm_data[eepm_cfg].write_val == eepm_data[eepm_cfg].read_val )
                {
                rtn = true;
                }
            }
        }
    else
        {
        rtn = true;
        }
    }
if( NULL != eepm_data[eepm_cfg].callback_ptr )
    {
    eepm_data[eepm_cfg].callback_ptr( rtn, &(eepm_data[eepm_cfg].read_val) );
    }
}

/*================================================================================================*/
/**
@brief   eepm_ESN_w_callback
@details eepm_ESN_w_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_ESN_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_ESN, status );
}

/*================================================================================================*/
/**
@brief   eepm_ESN_r_callback
@details eepm_ESN_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_ESN_r_callback
    (
    status_t status
    )
{
eepm_r_callback( EEPM_BLOCK_CONFIG_ESN, status );
}

/*================================================================================================*/
/**
@brief   eepm_BT_en_w_callback
@details eepm_BT_en_w_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_BT_en_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_BT_EN, status );
}

/*================================================================================================*/
/**
@brief   eepm_BT_en_r_callback
@details eepm_BT_en_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_BT_en_r_callback
    (
    status_t status
    )
{
eepm_r_callback( EEPM_BLOCK_CONFIG_BT_EN, status );
}

/*================================================================================================*/
/**
@brief   eepm_BT_autoconn_w_callback
@details eepm_BT_autoconn_w_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_BT_autoconn_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_BT_AUTO_CONN, status );
}

/*================================================================================================*/
/**
@brief   eepm_BT_autoconn_r_callback
@details eepm_BT_autoconn_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_BT_autoconn_r_callback
    (
    status_t status
    )
{
eepm_r_callback( EEPM_BLOCK_CONFIG_BT_AUTO_CONN, status );
}

/*================================================================================================*/
/**
@brief   eepm_last_page_w_callback
@details eepm_last_page_w_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_last_page_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_LAST_PAGE, status );
}

/*================================================================================================*/
/**
@brief   eepm_last_page_r_callback
@details eepm_last_page_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_last_page_r_callback
    (
    status_t status
    )
{
eepm_r_callback( EEPM_BLOCK_CONFIG_LAST_PAGE, status );
}

/*================================================================================================*/
/**
@brief   eepm_id_page_lock_callback
@details eepm_id_page_lock_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_id_page_lock_callback
    (
    status_t status
    )
{
bool rtn = ( ( kStatus_Success == status ) ? true : false );
eepm_data[EEPM_BLOCK_CONFIG_ID_PAGE_LOCK].callback_ptr( rtn, NULL );
}

/*================================================================================================*/
/**
@brief   eepm_language_w_callback
@details eepm_language_w_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_language_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_LANGUAGE, status );
}

/*================================================================================================*/
/**
@brief   eepm_language_r_callback
@details eepm_language_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_language_r_callback
    (
    status_t status
    )
{
eepm_r_callback( EEPM_BLOCK_CONFIG_LANGUAGE, status );
}

/*================================================================================================*/
/**
@brief   eepm_start_burn_in_w_callback
@details eepm_start_burn_in_w_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_start_burn_in_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_START_BURN_IN, status );
}

/*================================================================================================*/
/**
@brief   eepm_start_burn_in_r_callback
@details eepm_start_burn_in_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_start_burn_in_r_callback
    (
    status_t status
    )
{
eepm_r_callback( EEPM_BLOCK_CONFIG_START_BURN_IN, status );
}

/*================================================================================================*/
/**
@brief   eepm_start_burn_in_w_callback
@details eepm_start_burn_in_w_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_burn_in_result_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_BURN_IN_RESULT, status );
}

/*================================================================================================*/
/**
@brief   eepm_start_burn_in_r_callback
@details eepm_start_burn_in_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_burn_in_result_r_callback
    (
    status_t status
    )
{
eepm_r_callback( EEPM_BLOCK_CONFIG_BURN_IN_RESULT, status );
}

/*================================================================================================*/
/**
@brief   eepm_bd_addr_w_callback
@details eepm_bd_addr_w_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_bd_addr_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_BD_ADDRESS, status );
}

/*================================================================================================*/
/**
@brief   eepm_bd_addr_r_callback
@details eepm_bd_addr_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_bd_addr_r_callback
    (
    status_t status
    )
{
bool rtn = false;

xSemaphoreGive( eepm_data[EEPM_BLOCK_CONFIG_BD_ADDRESS].semaphore );
if( kStatus_Success == status )
    {
    if( eepm_data[EEPM_BLOCK_CONFIG_BD_ADDRESS].need_verified )
        {
        if( eepm_data[EEPM_BLOCK_CONFIG_BD_ADDRESS].cb_write )
            {
            if( 0 == memcmp( write_bd_address, read_bd_address, BD_ADDRESS_LENGTH ) )
                {
                rtn = true;
                }
            }
        }
    else
        {
        rtn = true;
        }
    }

if( NULL != eepm_data[EEPM_BLOCK_CONFIG_BD_ADDRESS].callback_ptr )
    {
    eepm_data[EEPM_BLOCK_CONFIG_BD_ADDRESS].callback_ptr( rtn, read_bd_address );
    }
}

/*================================================================================================*/
/**
@brief   eepm_burn_in_time_w_callback
@details eepm_burn_in_time_w_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_burn_in_time_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_BURN_IN_TIME, status );
}

/*================================================================================================*/
/**
@brief   eepm_burn_in_time_r_callback
@details eepm_burn_in_time_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_burn_in_time_r_callback
    (
    status_t status
    )
{
eepm_r_callback( EEPM_BLOCK_CONFIG_BURN_IN_TIME, status );
}

/*================================================================================================*/
/**
@brief   eepm_burn_in_target_time_w_callback
@details eepm_burn_in_target_time_w_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_burn_in_target_time_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME, status );
}

/*================================================================================================*/
/**
@brief   eepm_burn_in_target_time_r_callback
@details eepm_burn_in_target_time_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_burn_in_target_time_r_callback
    (
    status_t status
    )
{
eepm_r_callback( EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME, status );
}

/*================================================================================================*/
/**
@brief   EEPM_init
@details EEPM_init

@return None
@retval None
*/
/*================================================================================================*/

void EEPM_init
    (
    void
    )
{
uint8_t idx = 0;
for ( idx= 0; idx < EEPM_BLOCK_CONFIG_CNT ; idx++ )
    {
    eepm_data[idx].semaphore = xSemaphoreCreateBinary();
    if( eepm_data[idx].semaphore != NULL )
        {
        xSemaphoreGive( eepm_data[idx].semaphore );
        }
    }
}

/*================================================================================================*/
/**
@brief   EEPM_set_ESN
@details EEPM_set_ESN

@return None
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_ESN
    (
    uint32_t num,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_ESN].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_ESN].write_val = num;
    eepm_data[EEPM_BLOCK_CONFIG_ESN].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_ESN].callback_ptr = callback_ptr;
    eep_set_ESN_number( &( eepm_data[EEPM_BLOCK_CONFIG_ESN].write_val ), eepm_ESN_w_callback );
    eep_get_ESN_number( &( eepm_data[EEPM_BLOCK_CONFIG_ESN].read_val ), eepm_ESN_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_get_ESN
@details EEPM_get_ESN

@return None
@retval None
*/
/*================================================================================================*/

BaseType_t EEPM_get_ESN
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_ESN].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_ESN].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_ESN].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_ESN].callback_ptr = callback_ptr;
    eep_get_ESN_number( &( eepm_data[EEPM_BLOCK_CONFIG_ESN].read_val ), eepm_ESN_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_lock_id_page
@details EEPM_lock_id_page

@return None
@retval None
*/
/*================================================================================================*/

BaseType_t EEPM_lock_id_page
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_ID_PAGE_LOCK].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_ID_PAGE_LOCK].write_val = page_id_lock;
    eepm_data[EEPM_BLOCK_CONFIG_ID_PAGE_LOCK].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_ID_PAGE_LOCK].callback_ptr = callback_ptr;
    eep_set_id_page_lock( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_ID_PAGE_LOCK].write_val ), eepm_id_page_lock_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_BT_en
@details EEPM_set_BT_en

@return None
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_BT_en
    (
    bool is_enable,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_BT_EN].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_BT_EN].write_val = (uint32_t)is_enable;
    eepm_data[EEPM_BLOCK_CONFIG_BT_EN].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_BT_EN].callback_ptr = callback_ptr;
    eep_set_BT_en( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_BT_EN].write_val ), eepm_BT_en_w_callback );
    eep_get_BT_en( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_BT_EN].read_val ), eepm_BT_en_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_get_BT_en
@details EEPM_get_BT_en

@return None
@retval None
*/
/*================================================================================================*/

BaseType_t EEPM_get_BT_en
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_BT_EN].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_BT_EN].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_BT_EN].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_BT_EN].callback_ptr = callback_ptr;
    eep_get_BT_en( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_BT_EN].read_val ), eepm_BT_en_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}


/*================================================================================================*/
/**
@brief   EEPM_set_BT_autoconn
@details EEPM_set_BT_autoconn

@return None
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_BT_autoconn
    (
    bool is_auto,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].write_val= (uint32_t)is_auto;
    eepm_data[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].callback_ptr = callback_ptr;
    eep_set_BT_auto_conn( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].write_val ), eepm_BT_autoconn_w_callback );
    eep_get_BT_auto_conn( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].read_val ), eepm_BT_autoconn_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_get_BT_autoconn
@details EEPM_get_BT_autoconn

@return None
@retval None
*/
/*================================================================================================*/

BaseType_t EEPM_get_BT_autoconn
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].need_verified= false;
    eepm_data[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].callback_ptr = callback_ptr;
    eep_get_BT_auto_conn( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].read_val ), eepm_BT_autoconn_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_last_page
@details EEPM_set_last_page

@return None
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_last_page
    (
    uint8_t page_num,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_LAST_PAGE].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_LAST_PAGE].write_val= (uint32_t)page_num;
    eepm_data[EEPM_BLOCK_CONFIG_LAST_PAGE].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_LAST_PAGE].callback_ptr = callback_ptr;
    eep_set_last_page( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_LAST_PAGE].write_val ), eepm_last_page_w_callback );
    eep_get_last_page( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_LAST_PAGE].read_val ), eepm_last_page_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_get_last_page
@details EEPM_get_last_page

@return None
@retval None
*/
/*================================================================================================*/

BaseType_t EEPM_get_last_page
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_LAST_PAGE].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_LAST_PAGE].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_LAST_PAGE].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_LAST_PAGE].callback_ptr = callback_ptr;
    eep_get_last_page( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_LAST_PAGE].read_val ), eepm_last_page_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_language
@details EEPM_set_language

@return None
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_language
    (
    uint8_t language,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_LANGUAGE].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_LANGUAGE].write_val = (uint32_t)language;
    eepm_data[EEPM_BLOCK_CONFIG_LANGUAGE].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_LANGUAGE].callback_ptr = callback_ptr;
    eep_set_language( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_LANGUAGE].write_val ), eepm_language_w_callback );
    eep_get_language( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_LANGUAGE].read_val ), eepm_language_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_get_language
@details EEPM_get_language

@return None
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_get_language
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_LANGUAGE].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_LANGUAGE].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_LANGUAGE].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_LANGUAGE].callback_ptr = callback_ptr;
    eep_get_language( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_LANGUAGE].read_val ), eepm_language_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_start_burn_in
@details EEPM_set_start_burn_in

@return None
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_start_burn_in
    (
    bool is_start,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_START_BURN_IN].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_START_BURN_IN].write_val = (uint32_t)is_start;
    eepm_data[EEPM_BLOCK_CONFIG_START_BURN_IN].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_START_BURN_IN].callback_ptr = callback_ptr;
    eep_set_start_burn_in( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_START_BURN_IN].write_val ), eepm_start_burn_in_w_callback );
    eep_get_start_burn_in( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_START_BURN_IN].read_val ), eepm_start_burn_in_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_get_start_burn_in
@details EEPM_get_start_burn_in

@return None
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_get_start_burn_in
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_START_BURN_IN].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_START_BURN_IN].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_START_BURN_IN].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_START_BURN_IN].callback_ptr = callback_ptr;
    eep_get_start_burn_in( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_START_BURN_IN].read_val ), eepm_start_burn_in_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_burn_in_result
@details EEPM_set_burn_in_result

@return None
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_burn_in_result
    (
    uint8_t burn_in_result,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].write_val = (uint32_t)burn_in_result;
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].callback_ptr = callback_ptr;
    eep_set_burn_in_result( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].write_val ), eepm_burn_in_result_w_callback );
    eep_get_burn_in_result( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].read_val ), eepm_burn_in_result_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_get_burn_in_result
@details EEPM_get_burn_in_result

@return None
@retval None
*/
/*================================================================================================*/

BaseType_t EEPM_get_burn_in_result
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].callback_ptr = callback_ptr;
    eep_get_burn_in_result( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].read_val ), eepm_burn_in_result_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_bd_address
@details EEPM_set_bd_address

@return None
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_bd_address
    (
    uint8_t *bd_addr,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;

if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_BD_ADDRESS].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_BD_ADDRESS].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_BD_ADDRESS].callback_ptr = callback_ptr;
    memcpy( write_bd_address, bd_addr, BD_ADDRESS_LENGTH );
    eep_set_bd_address( bd_addr, eepm_bd_addr_w_callback );
    eep_get_bd_address( read_bd_address, eepm_bd_addr_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_get_bd_address
@details EEPM_get_bd_address

@return None
@retval None
*/
/*================================================================================================*/

BaseType_t EEPM_get_bd_address
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_BD_ADDRESS].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_BD_ADDRESS].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_BD_ADDRESS].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_BD_ADDRESS].callback_ptr = callback_ptr;
    eep_get_bd_address( read_bd_address, eepm_bd_addr_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}


/*================================================================================================*/
/**
@brief   EEPM_set_burn_in_time
@details EEPM_set_burn_in_time

@return None
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_burn_in_time
    (
    uint32_t burn_in_time,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TIME].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TIME].write_val = burn_in_time;
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TIME].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TIME].callback_ptr = callback_ptr;
    eep_set_burn_in_time( &( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TIME].write_val ), eepm_burn_in_time_w_callback );
    eep_get_burn_in_time( &( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TIME].read_val ), eepm_burn_in_time_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}


/*================================================================================================*/
/**
@brief   EEPM_get_burn_in_time
@details EEPM_get_burn_in_time

@return None
@retval None
*/
/*================================================================================================*/

BaseType_t EEPM_get_burn_in_time
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TIME].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TIME].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TIME].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TIME].callback_ptr = callback_ptr;
    eep_get_burn_in_time( &( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TIME].read_val ), eepm_burn_in_time_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}



/*================================================================================================*/
/**
@brief   EEPM_set_burn_in_time
@details EEPM_set_burn_in_time

@return None
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_burn_in_target_time
    (
    uint32_t burn_in_target_time,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].write_val = burn_in_target_time;
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].callback_ptr = callback_ptr;
    eep_set_burn_in_target_time( &( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].write_val ), eepm_burn_in_target_time_w_callback );
    eep_get_burn_in_target_time( &( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].read_val ), eepm_burn_in_target_time_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}


/*================================================================================================*/
/**
@brief   EEPM_get_burn_in_time
@details EEPM_get_burn_in_time

@return None
@retval None
*/
/*================================================================================================*/

BaseType_t EEPM_get_burn_in_target_time
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].callback_ptr = callback_ptr;
    eep_get_burn_in_target_time( &( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].read_val ), eepm_burn_in_target_time_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}