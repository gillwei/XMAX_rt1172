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
void eep_set_ESN_number
    (
    uint32_t* number_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

void eep_get_ESN_number
    (
    uint32_t* number_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

void eep_set_id_page_lock
    (
    uint8_t* is_lock,
    void ( *callback_func_ptr ) ( status_t )
    );

void eep_set_BT_en
    (
    uint8_t* is_en_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

void eep_get_BT_en
    (
    uint8_t* is_en_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

void eep_set_BT_auto_conn
    (
    uint8_t* is_auto_conn_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

void eep_get_BT_auto_conn
    (
    uint8_t* is_auto_conn_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

void eep_set_last_page
    (
    uint8_t* page_num_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

void eep_get_last_page
    (
    uint8_t* page_num_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

void eep_set_language
    (
    uint8_t* language_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

void eep_get_language
    (
    uint8_t* language_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

void eep_set_start_burn_in
    (
    uint8_t* start_burn_in_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

void eep_get_start_burn_in
    (
    uint8_t* start_burn_in_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

void eep_set_burn_in_result
    (
    uint8_t* burn_in_result_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

void eep_get_burn_in_result
    (
    uint8_t* burn_in_result_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

void eep_set_bd_address
    (
    uint8_t* bd_address_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

void eep_get_bd_address
    (
    uint8_t* bd_address_ptr,
    void ( *callback_func_ptr ) ( status_t )
    );

#ifdef __cplusplus
}
#endif

#endif /*EEP_PRV_H*/


