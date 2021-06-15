/*********************************************************************
* @file  EEP_prv.h
* @brief EEPROM Interface private header file
*
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef EEP_PRV_H
#define EEP_PRV_H

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
BaseType_t eep_set_ESN_number
    (
    uint32_t* number_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_ESN_number
    (
    uint32_t* number_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_id_page_lock
    (
    uint8_t* is_lock,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_BT_en
    (
    uint8_t* is_en_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_BT_en
    (
    uint8_t* is_en_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_BT_auto_conn
    (
    uint8_t* is_auto_conn_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_BT_auto_conn
    (
    uint8_t* is_auto_conn_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_last_page
    (
    uint8_t* page_num_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_last_page
    (
    uint8_t* page_num_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_language
    (
    uint8_t* language_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_language
    (
    uint8_t* language_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_start_burn_in
    (
    uint8_t* start_burn_in_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_start_burn_in
    (
    uint8_t* start_burn_in_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_burn_in_result
    (
    uint8_t* burn_in_result_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_burn_in_result
    (
    uint8_t* burn_in_result_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_bd_address
    (
    uint8_t* bd_address_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_bd_address
    (
    uint8_t* bd_address_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_burn_in_time
    (
    uint32_t* burn_in_time_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_burn_in_time
    (
    uint32_t* burn_in_time_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_burn_in_target_time
    (
    uint32_t* burn_in_target_time_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_burn_in_target_time
    (
    uint32_t* burn_in_target_time_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_ccu_id
    (
    uint8_t* ccu_id_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_ccu_id
    (
    uint8_t* ccu_id_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_passkey
    (
    uint32_t* pass_key_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_passkey
    (
    uint32_t* pass_key_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_dummy
    (
    uint16_t* dummy_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_dummy
    (
    uint16_t* dummy_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_trip_time
    (
    uint32_t* trip_time_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_trip_time
    (
    uint32_t* trip_time_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_mode
    (
    uint8_t* operation_mode_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_mode
    (
    uint8_t* operation_mode_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_supported_function
    (
    uint8_t* sup_func_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_supported_function
    (
    uint8_t* sup_func_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_clk_auto_adjustment
    (
    uint8_t* auto_adjustment_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_clk_auto_adjustment
    (
    uint8_t* auto_adjustment_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );
BaseType_t eep_set_auto_connect_sequence
    (
    uint8_t* auto_connect_seq_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_auto_connect_sequence
    (
    uint8_t* auto_connect_seq_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_fuel_consumption
    (
    uint32_t* fuel_consumption_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_fuel_consumption
    (
    uint32_t* fuel_consumption_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_qrcode_fused_1
    (
    uint8_t* fused_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_qrcode_fused_1
    (
    uint8_t* fused_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_qrcode_fused_2
    (
    uint8_t* fused_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_qrcode_fused_2
    (
    uint8_t* fused_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_set_qrcode_fused_3
    (
    uint8_t* fused_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

BaseType_t eep_get_qrcode_fused_3
    (
    uint8_t* fused_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

#ifdef __cplusplus
}
#endif

#endif /*EEP_PRV_H*/


