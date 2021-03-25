/*******************************************************************************
*@ File eep_intf.c
*@ Brief eeprom interface
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
#include "EEP_prv.h"
#include "EEPM_pub.h"
#include "PERIPHERAL_pub.h"
#include "fsl_debug_console.h"
/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/
#define EEPROM_SUB_ADDR_SIZE                 ( 0x02 )

//id page
#define EEPROM_ID_PAGE_I2C_DEV_ADDR          ( 0x58 )

//id page lock
#define EEPROM_ID_PAGE_LOCK_SUB_ADDR         ( 0x0400 )

//mem page
#define EEPROM_MEM_PAGE_I2C_DEV_ADDR         ( 0x50 )
#define ESN_START_SUB_ADDR                   ( 0x0000 )
#define BT_EN_START_SUB_ADDR                 ( ESN_START_SUB_ADDR                   + ESN_LENGTH                    )
#define BT_AUTO_CONN_START_SUB_ADDR          ( BT_EN_START_SUB_ADDR                 + BT_EN_LENGTH                  )
#define LAST_PAGE_START_SUB_ADDR             ( BT_AUTO_CONN_START_SUB_ADDR          + BT_AUTO_CONN_LENGTH           )
#define LANGUAGE_START_SUB_ADDR              ( LAST_PAGE_START_SUB_ADDR             + LAST_PAGE_LENGTH              )
#define START_BURN_IN_START_SUB_ADDR         ( LANGUAGE_START_SUB_ADDR              + LANGUAGE_LENGTH               )
#define BURN_IN_RESULT_START_SUB_ADDR        ( START_BURN_IN_START_SUB_ADDR         + START_BURN_IN_LENGTH          )
#define BD_ADDRESS_START_SUB_ADDR            ( BURN_IN_RESULT_START_SUB_ADDR        + BURN_IN_RESULT_LENGTH         )
#define BURN_IN_TIME_START_SUB_ADDR          ( BD_ADDRESS_START_SUB_ADDR            + BD_ADDRESS_LENGTH             )
#define BURN_IN_TARGET_TIME_START_SUB_ADDR   ( BURN_IN_TIME_START_SUB_ADDR          + BURN_IN_TIME_LENGTH           )
#define QRCODE_CCUID_START_SUB_ADDR          ( BURN_IN_TARGET_TIME_START_SUB_ADDR   + BURN_IN_TARGET_TIME_LENGTH    )
#define QRCODE_PASSKEY_START_SUB_ADDR        ( QRCODE_CCUID_START_SUB_ADDR          + QRCODE_CCUID_LENGTH           )
#define QRCODE_DUMMY_START_SUB_ADDR          ( QRCODE_PASSKEY_START_SUB_ADDR        + QRCODE_PASSKEY_LENGTH         )
#define TRIP_TIME_START_SUB_ADDR             ( QRCODE_DUMMY_START_SUB_ADDR          + QRCODE_DUMMY_LENGTH           )
#define OPERATION_MODE_START_SUB_ADDR        ( TRIP_TIME_START_SUB_ADDR             + TRIP_TIME_LENGTH              )
#define SUPPORTED_FUNCTION_START_SUB_ADDR    ( OPERATION_MODE_START_SUB_ADDR        + OPERATION_MODE_LENGTH         )

// reserved for future newly add data..
#define NEXT_START_SUB_ADDR                  ( SUPPORTED_FUNCTION_START_SUB_ADDR    + SUPPORTED_FUNCTION_LENGTH     )

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef struct
    {
    uint16_t start_addr;
    uint16_t length;
    }eeprom_block_config_type;

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
eeprom_block_config_type block_config_list[EEPM_BLOCK_CONFIG_CNT] = \
{
    { ESN_START_SUB_ADDR,                   ESN_LENGTH                         }, //EEPM_BLOCK_CONFIG_ESN
    { BT_EN_START_SUB_ADDR,                 BT_EN_LENGTH                       }, //EEPM_BLOCK_CONFIG_BT_EN
    { BT_AUTO_CONN_START_SUB_ADDR,          BT_AUTO_CONN_LENGTH                }, //EEPM_BLOCK_CONFIG_BT_AUTO_CONN
    { LAST_PAGE_START_SUB_ADDR,             LAST_PAGE_LENGTH                   }, //EEPM_BLOCK_CONFIG_LAST_PAGE
    { EEPROM_ID_PAGE_LOCK_SUB_ADDR,         EEPROM_ID_PAGE_LOCK_DATA_LENGTH    }, //EEPM_BLOCK_CONFIG_ID_PAGE_LOCK
    { LANGUAGE_START_SUB_ADDR,              LANGUAGE_LENGTH                    }, //EEPM_BLOCK_CONFIG_LANGUAGE
    { START_BURN_IN_START_SUB_ADDR,         START_BURN_IN_LENGTH               }, //EEPM_BLOCK_CONFIG_START_BURN_IN
    { BURN_IN_RESULT_START_SUB_ADDR,        BURN_IN_RESULT_LENGTH              }, //EEPM_BLOCK_CONFIG_BURN_IN_RESULT
    { BD_ADDRESS_START_SUB_ADDR,            BD_ADDRESS_LENGTH                  }, //EEPM_BLOCK_CONFIG_BD_ADDRESS
    { BURN_IN_TIME_START_SUB_ADDR,          BURN_IN_TIME_LENGTH                }, //EEPM_BLOCK_CONFIG_BURN_IN_TIME
    { BURN_IN_TARGET_TIME_START_SUB_ADDR,   BURN_IN_TARGET_TIME_LENGTH         }, //EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME
    { QRCODE_CCUID_START_SUB_ADDR,          QRCODE_CCUID_LENGTH                }, //EEPM_BLOCK_CONFIG_QRCODE_CCUID
    { QRCODE_PASSKEY_START_SUB_ADDR,        QRCODE_PASSKEY_LENGTH              }, //EEPM_BLOCK_CONFIG_QRCODE_PASSKEY
    { QRCODE_DUMMY_START_SUB_ADDR,          QRCODE_DUMMY_LENGTH                }, //EEPM_BLOCK_CONFIG_QRCODE_DUMMY
    { TRIP_TIME_START_SUB_ADDR,             TRIP_TIME_LENGTH                   }, //EEPM_BLOCK_CONFIG_TRIP_TIME
    { OPERATION_MODE_START_SUB_ADDR,        OPERATION_MODE_LENGTH              }, //EEPM_BLOCK_CONFIG_OPERATION_MODE
    { SUPPORTED_FUNCTION_START_SUB_ADDR,    SUPPORTED_FUNCTION_LENGTH          }, //EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION
};


/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/


/*================================================================================================*/
/**
@brief   eep_set_ESN_number
@details eep_set_ESN_number

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_ESN_number
    (
    uint32_t* number_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                           (uint8_t*)number_ptr,
                           block_config_list[EEPM_BLOCK_CONFIG_ESN].length,
                           block_config_list[EEPM_BLOCK_CONFIG_ESN].start_addr,
                           EEPROM_SUB_ADDR_SIZE,
                           callback_func_ptr );

}

/*================================================================================================*/
/**
@brief   eep_get_ESN_number
@details eep_get_ESN_number

@return None
@retval None
*/
/*================================================================================================*/
void eep_get_ESN_number
    (
    uint32_t* number_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_read_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          (uint8_t*)number_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_ESN].length,
                          block_config_list[EEPM_BLOCK_CONFIG_ESN].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_set_id_page_lock
@details eep_set_id_page_lock

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_id_page_lock
    (
    uint8_t* is_lock,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_ID_PAGE_I2C_DEV_ADDR,
                           (uint8_t*)is_lock,
                           block_config_list[EEPM_BLOCK_CONFIG_ID_PAGE_LOCK].length,
                           block_config_list[EEPM_BLOCK_CONFIG_ID_PAGE_LOCK].start_addr,
                           EEPROM_SUB_ADDR_SIZE,
                           callback_func_ptr );
}
/*================================================================================================*/
/**
@brief   eep_set_BT_en
@details eep_set_BT_en

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_BT_en
    (
    uint8_t* is_en_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                           is_en_ptr,
                           block_config_list[EEPM_BLOCK_CONFIG_BT_EN].length,
                           block_config_list[EEPM_BLOCK_CONFIG_BT_EN].start_addr,
                           EEPROM_SUB_ADDR_SIZE,
                           callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_get_BT_en
@details eep_get_BT_en

@return None
@retval None
*/
/*================================================================================================*/
void eep_get_BT_en
    (
    uint8_t* is_en_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_read_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          is_en_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_BT_EN].length,
                          block_config_list[EEPM_BLOCK_CONFIG_BT_EN].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_set_BT_auto_conn
@details eep_set_BT_auto_conn

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_BT_auto_conn
    (
    uint8_t* is_auto_conn_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                           is_auto_conn_ptr,
                           block_config_list[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].length,
                           block_config_list[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].start_addr,
                           EEPROM_SUB_ADDR_SIZE,
                           callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_get_BT_auto_conn
@details eep_get_BT_auto_conn

@return None
@retval None
*/
/*================================================================================================*/
void eep_get_BT_auto_conn
    (
    uint8_t* is_auto_conn_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_read_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          is_auto_conn_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].length,
                          block_config_list[EEPM_BLOCK_CONFIG_BT_AUTO_CONN].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}
/*================================================================================================*/
/**
@brief   eep_set_last_page
@details eep_set_last_page

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_last_page
    (
    uint8_t* page_num_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                           page_num_ptr,
                           block_config_list[EEPM_BLOCK_CONFIG_LAST_PAGE].length,
                           block_config_list[EEPM_BLOCK_CONFIG_LAST_PAGE].start_addr,
                           EEPROM_SUB_ADDR_SIZE,
                           callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_get_last_page
@details eep_get_last_page

@return None
@retval None
*/
/*================================================================================================*/
void eep_get_last_page
    (
    uint8_t* page_num_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_read_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          page_num_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_LAST_PAGE].length,
                          block_config_list[EEPM_BLOCK_CONFIG_LAST_PAGE].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_set_language
@details eep_set_language

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_language
    (
    uint8_t* language_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          language_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_LANGUAGE].length,
                          block_config_list[EEPM_BLOCK_CONFIG_LANGUAGE].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_get_language
@details eep_get_language

@return None
@retval None
*/
/*================================================================================================*/
void eep_get_language
    (
    uint8_t* language_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_read_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          language_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_LANGUAGE].length,
                          block_config_list[EEPM_BLOCK_CONFIG_LANGUAGE].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_set_start_burn_in
@details eep_set_start_burn_in

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_start_burn_in
    (
    uint8_t* start_burn_in_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          start_burn_in_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_START_BURN_IN].length,
                          block_config_list[EEPM_BLOCK_CONFIG_START_BURN_IN].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_get_start_burn_in
@details eep_get_start_burn_in

@return None
@retval None
*/
/*================================================================================================*/
void eep_get_start_burn_in
    (
    uint8_t* start_burn_in_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_read_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          start_burn_in_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_START_BURN_IN].length,
                          block_config_list[EEPM_BLOCK_CONFIG_START_BURN_IN].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_set_burn_in_result
@details eep_set_burn_in_result

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_burn_in_result
    (
    uint8_t* burn_in_result_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          burn_in_result_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].length,
                          block_config_list[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_get_burn_in_result
@details eep_get_burn_in_result

@return None
@retval None
*/
/*================================================================================================*/
void eep_get_burn_in_result
    (
    uint8_t* burn_in_result_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_read_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          burn_in_result_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].length,
                          block_config_list[EEPM_BLOCK_CONFIG_BURN_IN_RESULT].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_set_bd_address
@details eep_set_bd_address

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_bd_address
    (
    uint8_t* bd_addr_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                           bd_addr_ptr,
                           block_config_list[EEPM_BLOCK_CONFIG_BD_ADDRESS].length,
                           block_config_list[EEPM_BLOCK_CONFIG_BD_ADDRESS].start_addr,
                           EEPROM_SUB_ADDR_SIZE,
                           callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_get_bd_address
@details eep_get_bd_address

@return None
@retval None
*/
/*================================================================================================*/
void eep_get_bd_address
    (
    uint8_t* bd_addr_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_read_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          bd_addr_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_BD_ADDRESS].length,
                          block_config_list[EEPM_BLOCK_CONFIG_BD_ADDRESS].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}


/*================================================================================================*/
/**
@brief   eep_set_burn_in_time
@details eep_set_burn_in_time

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_burn_in_time
    (
    uint32_t* burn_in_time_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                           (uint8_t *)burn_in_time_ptr,
                           block_config_list[EEPM_BLOCK_CONFIG_BURN_IN_TIME].length,
                           block_config_list[EEPM_BLOCK_CONFIG_BURN_IN_TIME].start_addr,
                           EEPROM_SUB_ADDR_SIZE,
                           callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_get_burn_in_time
@details eep_get_burn_in_time

@return None
@retval None
*/
/*================================================================================================*/
void eep_get_burn_in_time
    (
    uint32_t* burn_in_time_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_read_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          (uint8_t *)burn_in_time_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_BURN_IN_TIME].length,
                          block_config_list[EEPM_BLOCK_CONFIG_BURN_IN_TIME].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_set_burn_in_time
@details eep_set_burn_in_time

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_burn_in_target_time
    (
    uint32_t* burn_in_target_time_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                           (uint8_t *)burn_in_target_time_ptr,
                           block_config_list[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].length,
                           block_config_list[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].start_addr,
                           EEPROM_SUB_ADDR_SIZE,
                           callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_get_burn_in_time
@details eep_get_burn_in_time

@return None
@retval None
*/
/*================================================================================================*/
void eep_get_burn_in_target_time
    (
    uint32_t* burn_in_target_time_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_read_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          (uint8_t *)burn_in_target_time_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].length,
                          block_config_list[EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}


/*================================================================================================*/
/**
@brief   eep_set_ccu_id
@details eep_set_ccu_id

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_ccu_id
    (
    uint32_t* ccu_id_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                           (uint8_t *)ccu_id_ptr,
                           block_config_list[EEPM_BLOCK_CONFIG_QRCODE_CCUID].length,
                           block_config_list[EEPM_BLOCK_CONFIG_QRCODE_CCUID].start_addr,
                           EEPROM_SUB_ADDR_SIZE,
                           callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_get_ccu_id
@details eep_get_ccu_id

@return None
@retval None
*/
/*================================================================================================*/
void eep_get_ccu_id
    (
    uint32_t* ccu_id_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_read_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          (uint8_t *)ccu_id_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_QRCODE_CCUID].length,
                          block_config_list[EEPM_BLOCK_CONFIG_QRCODE_CCUID].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_set_passkey
@details eep_set_passkey

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_passkey
    (
    uint32_t* pass_key_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                           (uint8_t *)pass_key_ptr,
                           block_config_list[EEPM_BLOCK_CONFIG_QRCODE_PASSKEY].length,
                           block_config_list[EEPM_BLOCK_CONFIG_QRCODE_PASSKEY].start_addr,
                           EEPROM_SUB_ADDR_SIZE,
                           callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_get_passkey
@details eep_get_passkey

@return None
@retval None
*/
/*================================================================================================*/
void eep_get_passkey
    (
    uint32_t* pass_key_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_read_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          (uint8_t *)pass_key_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_QRCODE_PASSKEY].length,
                          block_config_list[EEPM_BLOCK_CONFIG_QRCODE_PASSKEY].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_set_dummy
@details eep_set_dummy

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_dummy
    (
    uint16_t* dummy_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                           (uint8_t *)dummy_ptr,
                           block_config_list[EEPM_BLOCK_CONFIG_QRCODE_DUMMY].length,
                           block_config_list[EEPM_BLOCK_CONFIG_QRCODE_DUMMY].start_addr,
                           EEPROM_SUB_ADDR_SIZE,
                           callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_get_dummy
@details eep_get_dummy

@return None
@retval None
*/
/*================================================================================================*/
void eep_get_dummy
    (
    uint16_t* dummy_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_read_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          (uint8_t *)dummy_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_QRCODE_DUMMY].length,
                          block_config_list[EEPM_BLOCK_CONFIG_QRCODE_DUMMY].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_set_trip_time
@details eep_set_trip_time

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_trip_time
    (
    uint32_t* trip_time_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                           (uint8_t *)trip_time_ptr,
                           block_config_list[EEPM_BLOCK_CONFIG_TRIP_TIME].length,
                           block_config_list[EEPM_BLOCK_CONFIG_TRIP_TIME].start_addr,
                           EEPROM_SUB_ADDR_SIZE,
                           callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_get_trip_time
@details eep_get_trip_time

@return None
@retval None
*/
/*================================================================================================*/
void eep_get_trip_time
    (
    uint32_t* trip_time_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_read_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          (uint8_t *)trip_time_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_TRIP_TIME].length,
                          block_config_list[EEPM_BLOCK_CONFIG_TRIP_TIME].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_set_mode
@details eep_set_mode

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_mode
    (
    uint8_t* operation_mode_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                           operation_mode_ptr,
                           block_config_list[EEPM_BLOCK_CONFIG_OPERATION_MODE].length,
                           block_config_list[EEPM_BLOCK_CONFIG_OPERATION_MODE].start_addr,
                           EEPROM_SUB_ADDR_SIZE,
                           callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_get_mode
@details eep_get_mode

@return None
@retval None
*/
/*================================================================================================*/
void eep_get_mode
    (
    uint8_t* operation_mode_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_read_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          operation_mode_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_OPERATION_MODE].length,
                          block_config_list[EEPM_BLOCK_CONFIG_OPERATION_MODE].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}


/*================================================================================================*/
/**
@brief   eep_set_supported_function
@details eep_set_supported_function

@return None
@retval None
*/
/*================================================================================================*/
void eep_set_supported_function
    (
    uint8_t* sup_func_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_write_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                           sup_func_ptr,
                           block_config_list[EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION].length,
                           block_config_list[EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION].start_addr,
                           EEPROM_SUB_ADDR_SIZE,
                           callback_func_ptr );
}

/*================================================================================================*/
/**
@brief   eep_get_supported_function
@details eep_get_supported_function

@return None
@retval None
*/
/*================================================================================================*/
void eep_get_supported_function
    (
    uint8_t* sup_func_ptr,
    void ( *callback_func_ptr ) ( status_t )
    )
{
PERIPHERAL_i2c_read_data( EEPROM_MEM_PAGE_I2C_DEV_ADDR,
                          sup_func_ptr,
                          block_config_list[EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION].length,
                          block_config_list[EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION].start_addr,
                          EEPROM_SUB_ADDR_SIZE,
                          callback_func_ptr );
}


#ifdef __cplusplus
}
#endif

