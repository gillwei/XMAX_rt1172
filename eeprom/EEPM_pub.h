/*********************************************************************
* @file  EEPM_pub.h
* @brief EEPROM Interface public header file
*
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef EEPM_PUB_H
#define EEPM_PUB_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "fsl_common.h"
#include "FreeRTOSConfig.h"
#include "projdefs.h"
#include "portmacro.h"

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define ESN_LENGTH                           ( 4 )
#define BT_EN_LENGTH                         ( 1 )
#define BT_AUTO_CONN_LENGTH                  ( 1 )
#define LAST_PAGE_LENGTH                     ( 1 )
#define EEPROM_ID_PAGE_LOCK_DATA_LENGTH      ( 1 )
#define LANGUAGE_LENGTH                      ( 1 )
#define START_BURN_IN_LENGTH                 ( 1 )
#define BURN_IN_RESULT_LENGTH                ( 1 )
#define BD_ADDRESS_LENGTH                    ( 6 )
#define BURN_IN_TIME_LENGTH                  ( 4 )
#define BURN_IN_TARGET_TIME_LENGTH           ( 4 )
#define QRCODE_CCUID_LENGTH                  ( 4 )
#define QRCODE_PASSKEY_LENGTH                ( 4 )
#define QRCODE_DUMMY_LENGTH                  ( 2 )
#define TRIP_TIME_LENGTH                     ( 4 )
#define OPERATION_MODE_LENGTH                ( 1 )
#define SUPPORTED_FUNCTION_LENGTH            ( 6 )
#define CLOCK_AUTO_ADJUSTMENT_LENGTH         ( 1 )

#define EEPROM_INVALID_VAL_1_BYTE            ( 0xFF )
#define EEPROM_INVALID_VAL_2_BYTE            ( 0xFFFF )
#define EEPROM_INVALID_VAL_4_BYTE            ( 0xFFFFFFFF )

typedef uint8_t EEPM_block_config_type; enum
    {
    EEPM_BLOCK_CONFIG_ESN,
    EEPM_BLOCK_CONFIG_BT_EN,
    EEPM_BLOCK_CONFIG_BT_AUTO_CONN,
    EEPM_BLOCK_CONFIG_LAST_PAGE,
    EEPM_BLOCK_CONFIG_ID_PAGE_LOCK,
    EEPM_BLOCK_CONFIG_LANGUAGE,
    EEPM_BLOCK_CONFIG_START_BURN_IN,
    EEPM_BLOCK_CONFIG_BURN_IN_RESULT,
    EEPM_BLOCK_CONFIG_BD_ADDRESS,
    EEPM_BLOCK_CONFIG_BURN_IN_TIME,
    EEPM_BLOCK_CONFIG_BURN_IN_TARGET_TIME,
    EEPM_BLOCK_CONFIG_QRCODE_CCUID,
    EEPM_BLOCK_CONFIG_QRCODE_PASSKEY,
    EEPM_BLOCK_CONFIG_QRCODE_DUMMY,
    EEPM_BLOCK_CONFIG_TRIP_TIME,
    EEPM_BLOCK_CONFIG_OPERATION_MODE,
    EEPM_BLOCK_CONFIG_SUPPORTED_FUNCTION,
    EEPM_BLOCK_CONFIG_CLK_AUTO_ADJUSTMENT,

    EEPM_BLOCK_CONFIG_CNT
    };

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

/*--------------------------------------------------------------------
                        MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
void EEPM_init
    (
    void
    );

BaseType_t EEPM_set_ESN
    (
    uint32_t num,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_ESN
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_lock_id_page
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_set_BT_en
    (
    bool is_enable,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_BT_en
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_set_BT_autoconn
    (
    bool is_auto,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_BT_autoconn
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_set_last_page
    (
    uint8_t page_num,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_last_page
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_set_language
    (
    uint8_t language,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_language
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_set_start_burn_in
    (
    bool is_start,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_start_burn_in
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_set_burn_in_result
    (
    uint8_t burn_in_result,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_burn_in_result
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_set_bd_address
    (
    uint8_t *bd_addr,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_bd_address
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_set_burn_in_time
    (
    uint32_t burn_in_time,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_burn_in_time
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_set_burn_in_target_time
    (
    uint32_t burn_in_target_time,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_burn_in_target_time
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_set_qrcode_ccuid
    (
    uint32_t ccuid,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_qrcode_ccuid
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_set_qrcode_passkey
    (
    uint32_t passkey,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_qrcode_passkey
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_set_qrcode_dummy
    (
    uint16_t dummy,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_qrcode_dummy
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_set_trip_time
    (
    uint32_t triptime,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_trip_time
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_set_operation_mode
    (
    uint8_t mode,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_operation_mode
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_set_supported_function
    (
    uint8_t *sup_func,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_supported_function
    (
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_set_clk_auto_adjustment
    (
    uint8_t auto_adjustment,
    void (*callback_ptr)(bool, void*)
    );

BaseType_t EEPM_get_clk_auto_adjustment
    (
    void (*callback_ptr)(bool, void*)
    );
#ifdef __cplusplus
}
#endif


#endif /*EEPM_PUB_H*/

