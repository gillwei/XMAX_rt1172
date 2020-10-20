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

typedef uint8_t EEPM_block_config_type; enum
    {
    EEPM_BLOCK_CONFIG_ESN            = 0,
    EEPM_BLOCK_CONFIG_BT_EN          = 1,
    EEPM_BLOCK_CONFIG_BT_AUTO_CONN   = 2,
    EEPM_BLOCK_CONFIG_LAST_PAGE      = 3,
    EEPM_BLOCK_CONFIG_ID_PAGE_LOCK   = 4,
    EEPM_BLOCK_CONFIG_LANGUAGE       = 5,
    EEPM_BLOCK_CONFIG_START_BURN_IN  = 6,
    EEPM_BLOCK_CONFIG_BURN_IN_RESULT = 7,
    EEPM_BLOCK_CONFIG_BD_ADDRESS     = 8,

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

#ifdef __cplusplus
}
#endif


#endif /*EEPM_PUB_H*/

