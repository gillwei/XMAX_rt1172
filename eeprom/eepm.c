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
static uint8_t write_sup_func[SUPPORTED_FUNCTION_LENGTH];
static uint8_t read_sup_func[SUPPORTED_FUNCTION_LENGTH];
static uint8_t write_ccuid[QRCODE_CCUID_LENGTH];
static uint8_t read_ccuid[QRCODE_CCUID_LENGTH];
static uint8_t write_auto_connect_sequence[AUTO_CONNECT_SEQUENCE_LENGTH]; // Use for store auto connect sequence
static uint8_t read_auto_connect_sequence[AUTO_CONNECT_SEQUENCE_LENGTH]; // Use for store auto connect sequence

static uint8_t write_qrcode_fused_1[QRCODE_FUSED_DATA_LENGTH];
static uint8_t read_qrcode_fused_1[QRCODE_FUSED_DATA_LENGTH];
static uint8_t write_qrcode_fused_2[QRCODE_FUSED_DATA_LENGTH];
static uint8_t read_qrcode_fused_2[QRCODE_FUSED_DATA_LENGTH];
static uint8_t write_qrcode_fused_3[QRCODE_FUSED_DATA_LENGTH];
static uint8_t read_qrcode_fused_3[QRCODE_FUSED_DATA_LENGTH];

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
@brief   eepm_qrcode_ccuid_w_callback
@details eepm_qrcode_ccuid_w_callback

@return None
@retval None
*/
/*================================================================================================*/
static void eepm_qrcode_ccuid_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_QRCODE_CCUID, status );
}

/*================================================================================================*/
/**
@brief   eepm_qrcode_ccuid_r_callback
@details eepm_qrcode_ccuid_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_qrcode_ccuid_r_callback
    (
    status_t status
    )
{
bool rtn = false;

xSemaphoreGive( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_CCUID].semaphore );
if( kStatus_Success == status )
    {
    if( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_CCUID].need_verified )
        {
        if( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_CCUID].cb_write )
            {
            if( 0 == memcmp( write_ccuid, read_ccuid, QRCODE_CCUID_LENGTH ) )
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

if( NULL != eepm_data[EEPM_BLOCK_CONFIG_QRCODE_CCUID].callback_ptr )
    {
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_CCUID].callback_ptr( rtn, read_ccuid );
    }
}

/*================================================================================================*/
/**
@brief   eepm_qrcode_passkey_w_callback
@details eepm_qrcode_passkey_w_callback

@return None
@retval None
*/
/*================================================================================================*/
static void eepm_qrcode_passkey_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_QRCODE_PASSKEY, status );
}

/*================================================================================================*/
/**
@brief   eepm_qrcode_passkey_r_callback
@details eepm_qrcode_passkey_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_qrcode_passkey_r_callback
    (
    status_t status
    )
{
eepm_r_callback( EEPM_BLOCK_CONFIG_QRCODE_PASSKEY, status );
}

/*================================================================================================*/
/**
@brief   eepm_qrcode_dummy_w_callback
@details eepm_qrcode_dummy_w_callback

@return None
@retval None
*/
/*================================================================================================*/
static void eepm_qrcode_dummy_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_QRCODE_DUMMY, status );
}

/*================================================================================================*/
/**
@brief   eepm_qrcode_dummy_r_callback
@details eepm_qrcode_dummy_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_qrcode_dummy_r_callback
    (
    status_t status
    )
{
eepm_r_callback( EEPM_BLOCK_CONFIG_QRCODE_DUMMY, status );
}

/*================================================================================================*/
/**
@brief   eepm_trip_time_w_callback
@details eepm_trip_time_w_callback

@return None
@retval None
*/
/*================================================================================================*/
static void eepm_trip_time_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_TRIP_TIME, status );
}

/*================================================================================================*/
/**
@brief   eepm_trip_time_r_callback
@details eepm_trip_time_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_trip_time_r_callback
    (
    status_t status
    )
{
eepm_r_callback( EEPM_BLOCK_CONFIG_TRIP_TIME, status );
}

/*================================================================================================*/
/**
@brief   eepm_mode_w_callback
@details eepm_mode_w_callback

@return None
@retval None
*/
/*================================================================================================*/
static void eepm_mode_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_OPERATION_MODE, status );
}

/*================================================================================================*/
/**
@brief   eepm_mode_r_callback
@details eepm_mode_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_mode_r_callback
    (
    status_t status
    )
{
eepm_r_callback( EEPM_BLOCK_CONFIG_OPERATION_MODE, status );
}

/*================================================================================================*/
/**
@brief   eepm_sup_func_w_callback
@details eepm_sup_func_w_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_sup_func_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION, status );
}

/*================================================================================================*/
/**
@brief   eepm_bd_addr_r_callback
@details eepm_bd_addr_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_sup_func_r_callback
    (
    status_t status
    )
{
bool rtn = false;

xSemaphoreGive( eepm_data[EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION].semaphore );
if( kStatus_Success == status )
    {
    if( eepm_data[EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION].need_verified )
        {
        if( eepm_data[EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION].cb_write )
            {
            if( 0 == memcmp( write_sup_func, read_sup_func, SUPPORTED_FUNCTION_LENGTH ) )
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

if( NULL != eepm_data[EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION].callback_ptr )
    {
    eepm_data[EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION].callback_ptr( rtn, read_sup_func );
    }
}

/*================================================================================================*/
/**
@brief   eepm_auto_adjustment_w_callback
@details eepm_auto_adjustment_w_callback

@return None
@retval None
*/
/*================================================================================================*/
static void eepm_auto_adjustment_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_CLK_AUTO_ADJUSTMENT, status );
}

/*================================================================================================*/
/**
@brief   eepm_auto_adjustment_r_callback
@details eepm_auto_adjustment_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_auto_adjustment_r_callback
    (
    status_t status
    )
{
eepm_r_callback( EEPM_BLOCK_CONFIG_CLK_AUTO_ADJUSTMENT, status );
}

/*================================================================================================*/
/**
@brief   eepm_fuel_consumption_w_callback
@details eepm_fuel_consumption_w_callback

@return None
@retval None
*/
/*================================================================================================*/
static void eepm_fuel_consumption_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_FUEL_CONSUMPTION, status );
}

/*================================================================================================*/
/**
@brief   eepm_fuel_consumption_r_callback
@details eepm_fuel_consumption_r_callback

@return None
@retval None
*/
/*================================================================================================*/
static void eepm_fuel_consumption_r_callback
    (
    status_t status
    )
{
eepm_r_callback( EEPM_BLOCK_CONFIG_FUEL_CONSUMPTION, status );
}

/*================================================================================================*/
/**
@brief   eepm_auto_con_seq_w_callback
@details eepm_auto_con_seq_w_callback

@return None
@retval None
*/
/*================================================================================================*/
static void eepm_auto_con_seq_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_AUTO_CONNECT_SEQUENCE, status );
}

/*================================================================================================*/
/**
@brief   eepm_auto_con_seq_r_callback
@details eepm_auto_con_seq_r_callback

@return None
@retval None
*/
/*================================================================================================*/
static void eepm_auto_con_seq_r_callback
    (
    status_t status
    )
{
bool rtn = false;

xSemaphoreGive( eepm_data[EEPM_BLOCK_CONFIG_AUTO_CONNECT_SEQUENCE].semaphore );
if( kStatus_Success == status )
    {
    if( eepm_data[EEPM_BLOCK_CONFIG_AUTO_CONNECT_SEQUENCE].need_verified )
        {
        if( eepm_data[EEPM_BLOCK_CONFIG_AUTO_CONNECT_SEQUENCE].cb_write )
            {
            if( 0 == memcmp( write_auto_connect_sequence, read_auto_connect_sequence, AUTO_CONNECT_SEQUENCE_LENGTH ) )
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

if( NULL != eepm_data[EEPM_BLOCK_CONFIG_AUTO_CONNECT_SEQUENCE].callback_ptr )
    {
    eepm_data[EEPM_BLOCK_CONFIG_AUTO_CONNECT_SEQUENCE].callback_ptr( rtn, read_auto_connect_sequence );
    }
}

/*================================================================================================*/
/**
@brief   eepm_qrcode_fused_1_w_callback
@details eepm_qrcode_fused_1_w_callback

@return None
@retval None
*/
/*================================================================================================*/
static void eepm_qrcode_fused_1_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_1, status );
}

/*================================================================================================*/
/**
@brief   eepm_qrcode_fused_1_r_callback
@details eepm_qrcode_fused_1_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_qrcode_fused_1_r_callback
    (
    status_t status
    )
{
bool rtn = false;

xSemaphoreGive( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_1].semaphore );
if( kStatus_Success == status )
    {
    if( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_1].need_verified )
        {
        if( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_1].cb_write )
            {
            if( 0 == memcmp( write_qrcode_fused_1, read_qrcode_fused_1, QRCODE_FUSED_DATA_LENGTH ) )
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

if( NULL != eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_1].callback_ptr )
    {
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_1].callback_ptr( rtn, read_qrcode_fused_1 );
    }
}

/*================================================================================================*/
/**
@brief   eepm_qrcode_fused_2_w_callback
@details eepm_qrcode_fused_2_w_callback

@return None
@retval None
*/
/*================================================================================================*/
static void eepm_qrcode_fused_2_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_2, status );
}

/*================================================================================================*/
/**
@brief   eepm_qrcode_fused_2_r_callback
@details eepm_qrcode_fused_2_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_qrcode_fused_2_r_callback
    (
    status_t status
    )
{
bool rtn = false;

xSemaphoreGive( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_2].semaphore );
if( kStatus_Success == status )
    {
    if( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_2].need_verified )
        {
        if( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_2].cb_write )
            {
            if( 0 == memcmp( write_qrcode_fused_2, read_qrcode_fused_2, QRCODE_FUSED_DATA_LENGTH ) )
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

if( NULL != eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_2].callback_ptr )
    {
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_2].callback_ptr( rtn, read_qrcode_fused_2 );
    }
}

/*================================================================================================*/
/**
@brief   eepm_qrcode_fused_3_w_callback
@details eepm_qrcode_fused_3_w_callback

@return None
@retval None
*/
/*================================================================================================*/
static void eepm_qrcode_fused_3_w_callback
    (
    status_t status
    )
{
eepm_w_callback( EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_3, status );
}

/*================================================================================================*/
/**
@brief   eepm_qrcode_fused_3_r_callback
@details eepm_qrcode_fused_3_r_callback

@return None
@retval None
*/
/*================================================================================================*/

static void eepm_qrcode_fused_3_r_callback
    (
    status_t status
    )
{
bool rtn = false;

xSemaphoreGive( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_3].semaphore );
if( kStatus_Success == status )
    {
    if( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_3].need_verified )
        {
        if( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_3].cb_write )
            {
            if( 0 == memcmp( write_qrcode_fused_3, read_qrcode_fused_3, QRCODE_FUSED_DATA_LENGTH ) )
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

if( NULL != eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_3].callback_ptr )
    {
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_3].callback_ptr( rtn, read_qrcode_fused_3 );
    }
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
    rtn = eep_set_ESN_number( &( eepm_data[EEPM_BLOCK_CONFIG_ESN].write_val ), eepm_ESN_w_callback );
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

@return Result of enqueue get ESN operation
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
    rtn = eep_get_ESN_number( &( eepm_data[EEPM_BLOCK_CONFIG_ESN].read_val ), eepm_ESN_r_callback );
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

@return Result of enqueue set lock id page operation
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
    rtn = eep_set_id_page_lock( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_ID_PAGE_LOCK].write_val ), eepm_id_page_lock_callback );
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

@return Result of enqueue set BT enable operation
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
    rtn = eep_set_BT_en( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_BT_EN].write_val ), eepm_BT_en_w_callback );
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

@return Result of enqueue get BT enable operation
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
    rtn = eep_get_BT_en( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_BT_EN].read_val ), eepm_BT_en_r_callback );
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

@return Result of enqueue set BT auto connection operation
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
    rtn = eep_set_BT_auto_conn( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].write_val ), eepm_BT_autoconn_w_callback );
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

@return Result of enqueue get BT auto connection operation
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
    rtn = eep_get_BT_auto_conn( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].read_val ), eepm_BT_autoconn_r_callback );
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

@return Result of enqueue set last page operation
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
    rtn = eep_set_last_page( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_LAST_PAGE].write_val ), eepm_last_page_w_callback );
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

@return Result of enqueue get last page operation
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
    rtn = eep_get_last_page( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_LAST_PAGE].read_val ), eepm_last_page_r_callback );
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

@return Result of enqueue set language operation
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
    rtn = eep_set_language( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_LANGUAGE].write_val ), eepm_language_w_callback );
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

@return Result of enqueue get language operation
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
    rtn = eep_get_language( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_LANGUAGE].read_val ), eepm_language_r_callback );
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

@return Result of enqueue set start bun-in operation
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
    rtn = eep_set_start_burn_in( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_START_BURN_IN].write_val ), eepm_start_burn_in_w_callback );
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

@return Result of enqueue get start bun-in operation
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
    rtn = eep_get_start_burn_in( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_START_BURN_IN].read_val ), eepm_start_burn_in_r_callback );
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

@return Result of enqueue set bun-in result operation
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
    rtn = eep_set_burn_in_result( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].write_val ), eepm_burn_in_result_w_callback );
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

@return Result of enqueue get bun-in result operation
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
    rtn = eep_get_burn_in_result( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].read_val ), eepm_burn_in_result_r_callback );
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

@return Result of enqueue set bd address operation
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
    rtn = eep_set_bd_address( bd_addr, eepm_bd_addr_w_callback );
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

@return Result of enqueue get bd address operation
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
    rtn = eep_get_bd_address( read_bd_address, eepm_bd_addr_r_callback );
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

@return Result of enqueue set burn-in time operation
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
    rtn = eep_set_burn_in_time( &( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TIME].write_val ), eepm_burn_in_time_w_callback );
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

@return Result of enqueue get burn-in time operation
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
    rtn = eep_get_burn_in_time( &( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TIME].read_val ), eepm_burn_in_time_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_burn_in_target_time
@details EEPM_set_burn_in_target_time

@return Result of enqueue set burn-in target time operation
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
    rtn = eep_set_burn_in_target_time( &( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].write_val ), eepm_burn_in_target_time_w_callback );
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
@brief   EEPM_get_burn_in_target_time
@details EEPM_get_burn_in_target_time

@return Result of enqueue get burn-in target time operation
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
    rtn = eep_get_burn_in_target_time( &( eepm_data[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].read_val ), eepm_burn_in_target_time_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_qrcode_ccuid
@details EEPM_set_qrcode_ccuid

@return Result of enqueue set QR code ccuid operation
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_qrcode_ccuid
    (
    uint8_t * ccuid,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_CCUID].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_CCUID].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_CCUID].callback_ptr = callback_ptr;
    memcpy( write_ccuid, ccuid, QRCODE_CCUID_LENGTH );
    rtn = eep_set_ccu_id( write_ccuid, eepm_qrcode_ccuid_w_callback );
    eep_get_ccu_id( read_ccuid, eepm_qrcode_ccuid_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}


/*================================================================================================*/
/**
@brief   EEPM_get_qrcode_ccuid
@details EEPM_get_qrcode_ccuid

@return Result of enqueue get QR code ccuid operation
@retval None
*/
/*================================================================================================*/

BaseType_t EEPM_get_qrcode_ccuid
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_CCUID].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_CCUID].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_CCUID].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_CCUID].callback_ptr = callback_ptr;
    eep_get_ccu_id( read_ccuid, eepm_qrcode_ccuid_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_qrcode_passkey
@details EEPM_set_qrcode_passkey

@return Result of enqueue set QR code passkey operation
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_qrcode_passkey
    (
    uint32_t passkey,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_PASSKEY].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_PASSKEY].write_val = passkey;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_PASSKEY].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_PASSKEY].callback_ptr = callback_ptr;
    rtn = eep_set_passkey( &( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_PASSKEY].write_val ), eepm_qrcode_passkey_w_callback );
    eep_get_passkey( &( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_PASSKEY].read_val ), eepm_qrcode_passkey_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}


/*================================================================================================*/
/**
@brief   EEPM_get_qrcode_passkey
@details EEPM_get_qrcode_passkey

@return Result of enqueue get QR code passkey operation
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_get_qrcode_passkey
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_PASSKEY].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_PASSKEY].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_PASSKEY].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_PASSKEY].callback_ptr = callback_ptr;
    rtn = eep_get_passkey( &( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_PASSKEY].read_val ), eepm_qrcode_passkey_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_qrcode_dummy
@details EEPM_set_qrcode_dummy

@return Result of enqueue set QR code dummy operation
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_qrcode_dummy
    (
    uint16_t dummy,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_DUMMY].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_DUMMY].write_val = (uint32_t)dummy;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_DUMMY].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_DUMMY].callback_ptr = callback_ptr;
    rtn = eep_set_dummy( (uint16_t*)&( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_DUMMY].write_val ), eepm_qrcode_dummy_w_callback );
    eep_get_dummy( (uint16_t*)&( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_DUMMY].read_val ), eepm_qrcode_dummy_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}


/*================================================================================================*/
/**
@brief   EEPM_get_qrcode_dummy
@details EEPM_get_qrcode_dummy

@return Result of enqueue get QR code dummy operation
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_get_qrcode_dummy
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_DUMMY].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_DUMMY].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_DUMMY].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_DUMMY].callback_ptr = callback_ptr;
    rtn = eep_get_dummy( (uint16_t*)&( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_DUMMY].read_val ), eepm_qrcode_dummy_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_trip_time
@details EEPM_set_trip_time

@return Result of enqueue set trip time operation
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_trip_time
    (
    uint32_t triptime,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_TRIP_TIME].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_TRIP_TIME].write_val = triptime;
    eepm_data[EEPM_BLOCK_CONFIG_TRIP_TIME].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_TRIP_TIME].callback_ptr = callback_ptr;
    rtn = eep_set_trip_time( &( eepm_data[EEPM_BLOCK_CONFIG_TRIP_TIME].write_val ), eepm_trip_time_w_callback );
    eep_get_trip_time( &( eepm_data[EEPM_BLOCK_CONFIG_TRIP_TIME].read_val ), eepm_trip_time_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}


/*================================================================================================*/
/**
@brief   EEPM_get_trip_time
@details EEPM_get_trip_time

@return Result of enqueue get trip time operation
@retval None
*/
/*================================================================================================*/

BaseType_t EEPM_get_trip_time
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_TRIP_TIME].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_TRIP_TIME].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_TRIP_TIME].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_TRIP_TIME].callback_ptr = callback_ptr;
    rtn = eep_get_trip_time( &( eepm_data[EEPM_BLOCK_CONFIG_TRIP_TIME].read_val ), eepm_trip_time_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}


/*================================================================================================*/
/**
@brief   EEPM_set_operation_mode
@details EEPM_set_operation_mode

@return Result of enqueue set operation mode operation
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_operation_mode
    (
    uint8_t mode,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_OPERATION_MODE].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_OPERATION_MODE].write_val = (uint32_t)mode;
    eepm_data[EEPM_BLOCK_CONFIG_OPERATION_MODE].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_OPERATION_MODE].callback_ptr = callback_ptr;
    rtn = eep_set_mode( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_OPERATION_MODE].write_val ), eepm_mode_w_callback );
    eep_get_mode( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_OPERATION_MODE].read_val ), eepm_mode_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_get_operation_mode
@details EEPM_get_operation_mode

@return Result of enqueue get operation mode operation
@retval None
*/
/*================================================================================================*/

BaseType_t EEPM_get_operation_mode
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_OPERATION_MODE].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_OPERATION_MODE].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_OPERATION_MODE].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_OPERATION_MODE].callback_ptr = callback_ptr;
    rtn = eep_get_mode( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_OPERATION_MODE].read_val ), eepm_mode_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}


/*================================================================================================*/
/**
@brief   EEPM_set_supported_function
@details EEPM_set_supported_function

@return Result of enqueue set supported function operation
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_supported_function
    (
    uint8_t *sup_func,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION].callback_ptr = callback_ptr;
    memcpy( write_sup_func, sup_func, SUPPORTED_FUNCTION_LENGTH );
    rtn = eep_set_supported_function( write_sup_func, eepm_sup_func_w_callback );
    eep_get_supported_function( read_sup_func, eepm_sup_func_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}


/*================================================================================================*/
/**
@brief   EEPM_get_supported_function
@details EEPM_get_supported_function

@return Result of enqueue get supported function operation
@retval None
*/
/*================================================================================================*/

BaseType_t EEPM_get_supported_function
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION].callback_ptr = callback_ptr;
    rtn = eep_get_supported_function( read_sup_func, eepm_sup_func_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_clk_auto_adjustment
@details EEPM_set_clk_auto_adjustment

@return Result of enqueue set clock auto adjustment operation
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_clk_auto_adjustment
    (
    uint8_t auto_adjustment,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_CLK_AUTO_ADJUSTMENT].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_CLK_AUTO_ADJUSTMENT].write_val = (uint32_t)auto_adjustment;
    eepm_data[EEPM_BLOCK_CONFIG_CLK_AUTO_ADJUSTMENT].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_CLK_AUTO_ADJUSTMENT].callback_ptr = callback_ptr;
    rtn = eep_set_clk_auto_adjustment( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_CLK_AUTO_ADJUSTMENT].write_val ), eepm_auto_adjustment_w_callback );
    eep_get_clk_auto_adjustment( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_CLK_AUTO_ADJUSTMENT].read_val ), eepm_auto_adjustment_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_get_clk_auto_adjustment
@details EEPM_get_clk_auto_adjustment

@return Result of enqueue get clock auto adjustment operation
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_get_clk_auto_adjustment
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_CLK_AUTO_ADJUSTMENT].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_CLK_AUTO_ADJUSTMENT].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_CLK_AUTO_ADJUSTMENT].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_CLK_AUTO_ADJUSTMENT].callback_ptr = callback_ptr;
    rtn = eep_get_clk_auto_adjustment( (uint8_t*)&( eepm_data[EEPM_BLOCK_CONFIG_CLK_AUTO_ADJUSTMENT].read_val ), eepm_auto_adjustment_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_fuel_consumption
@details EEPM_set_fuel_consumption

@return Result of enqueue set fuel consumption operation
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_fuel_consumption
    (
    uint32_t fuelconsumption,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_FUEL_CONSUMPTION].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_FUEL_CONSUMPTION].write_val = fuelconsumption;
    eepm_data[EEPM_BLOCK_CONFIG_FUEL_CONSUMPTION].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_FUEL_CONSUMPTION].callback_ptr = callback_ptr;
    rtn = eep_set_fuel_consumption( &( eepm_data[EEPM_BLOCK_CONFIG_FUEL_CONSUMPTION].write_val ), eepm_fuel_consumption_w_callback );
    eep_get_fuel_consumption( &( eepm_data[EEPM_BLOCK_CONFIG_FUEL_CONSUMPTION].read_val ), eepm_fuel_consumption_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_get_fuel_consumption
@details EEPM_get_fuel_consumption

@return Result of enqueue get fuel consumption operation
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_get_fuel_consumption
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_FUEL_CONSUMPTION].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_FUEL_CONSUMPTION].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_FUEL_CONSUMPTION].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_FUEL_CONSUMPTION].callback_ptr = callback_ptr;
    rtn = eep_get_fuel_consumption( &( eepm_data[EEPM_BLOCK_CONFIG_FUEL_CONSUMPTION].read_val ), eepm_fuel_consumption_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_auto_connect_sequence
@details EEPM_set_auto_connect_sequence

@return Result of enqueue set auto connection sequence
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_auto_connect_sequence
    (
    uint8_t *auto_connect_sequence,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;

if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_AUTO_CONNECT_SEQUENCE].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_AUTO_CONNECT_SEQUENCE].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_AUTO_CONNECT_SEQUENCE].callback_ptr = callback_ptr;
    memcpy( write_auto_connect_sequence, auto_connect_sequence, AUTO_CONNECT_SEQUENCE_LENGTH );
    rtn = eep_set_auto_connect_sequence( write_auto_connect_sequence, eepm_auto_con_seq_w_callback );
    eep_get_auto_connect_sequence( read_auto_connect_sequence, eepm_auto_con_seq_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_get_auto_connect_sequence
@details EEPM_get_auto_connect_sequence

@return Result of enqueue get auto connection sequence
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_get_auto_connect_sequence
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_AUTO_CONNECT_SEQUENCE].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_AUTO_CONNECT_SEQUENCE].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_AUTO_CONNECT_SEQUENCE].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_AUTO_CONNECT_SEQUENCE].callback_ptr = callback_ptr;
    rtn = eep_get_auto_connect_sequence( read_auto_connect_sequence, eepm_auto_con_seq_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_qrcode_fused_data_1
@details EEPM_set_qrcode_fused_data_1

@return Result of enqueue set QR code fused data 1 operation
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_qrcode_fused_data_1
    (
    uint8_t * qrcode_fused,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_1].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_1].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_1].callback_ptr = callback_ptr;
    memcpy( write_qrcode_fused_1, qrcode_fused, QRCODE_FUSED_DATA_LENGTH );
    rtn = eep_set_qrcode_fused_1( write_qrcode_fused_1, eepm_qrcode_fused_1_w_callback );
    eep_get_qrcode_fused_1( read_qrcode_fused_1, eepm_qrcode_fused_1_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}


/*================================================================================================*/
/**
@brief   EEPM_get_qrcode_fused_data_1
@details EEPM_get_qrcode_fused_data_1

@return Result of enqueue get QR code fused data 1 operation
@retval None
*/
/*================================================================================================*/

BaseType_t EEPM_get_qrcode_fused_data_1
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_1].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_1].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_1].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_1].callback_ptr = callback_ptr;
    eep_get_qrcode_fused_1( read_qrcode_fused_1, eepm_qrcode_fused_1_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_qrcode_fused_data_2
@details EEPM_set_qrcode_fused_data_2

@return Result of enqueue set QR code fused data 1 operation
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_qrcode_fused_data_2
    (
    uint8_t * qrcode_fused,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_2].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_2].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_2].callback_ptr = callback_ptr;
    memcpy( write_qrcode_fused_2, qrcode_fused, QRCODE_FUSED_DATA_LENGTH );
    rtn = eep_set_qrcode_fused_2( write_qrcode_fused_2, eepm_qrcode_fused_2_w_callback );
    eep_get_qrcode_fused_2( read_qrcode_fused_2, eepm_qrcode_fused_2_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}


/*================================================================================================*/
/**
@brief   EEPM_get_qrcode_fused_data_2
@details EEPM_get_qrcode_fused_data_2

@return Result of enqueue get QR code fused data 22 operation
@retval None
*/
/*================================================================================================*/

BaseType_t EEPM_get_qrcode_fused_data_2
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_2].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_2].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_2].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_2].callback_ptr = callback_ptr;
    eep_get_qrcode_fused_2( read_qrcode_fused_2, eepm_qrcode_fused_2_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}

/*================================================================================================*/
/**
@brief   EEPM_set_qrcode_fused_data_3
@details EEPM_set_qrcode_fused_data_3

@return Result of enqueue set QR code fused data 3 operation
@retval None
*/
/*================================================================================================*/
BaseType_t EEPM_set_qrcode_fused_data_3
    (
    uint8_t * qrcode_fused,
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_3].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_3].need_verified = true;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_3].callback_ptr = callback_ptr;
    memcpy( write_qrcode_fused_3, qrcode_fused, QRCODE_FUSED_DATA_LENGTH );
    rtn = eep_set_qrcode_fused_3( write_qrcode_fused_3, eepm_qrcode_fused_3_w_callback );
    eep_get_qrcode_fused_3( read_qrcode_fused_3, eepm_qrcode_fused_3_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}


/*================================================================================================*/
/**
@brief   EEPM_get_qrcode_fused_data_3
@details EEPM_get_qrcode_fused_data_3

@return Result of enqueue get QR code fused data 1 operation
@retval None
*/
/*================================================================================================*/

BaseType_t EEPM_get_qrcode_fused_data_3
    (
    void (*callback_ptr)(bool, void*)
    )
{
BaseType_t rtn = pdTRUE;
if( xSemaphoreTake( eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_3].semaphore, ( TickType_t ) 0 ) == pdTRUE )
    {
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_3].write_val = 0;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_3].need_verified = false;
    eepm_data[EEPM_BLOCK_CONFIG_QRCODE_FUSED_DATA_3].callback_ptr = callback_ptr;
    eep_get_qrcode_fused_3( read_qrcode_fused_3, eepm_qrcode_fused_3_r_callback );
    }
else
    {
    rtn = pdFALSE;
    }
return rtn;
}