/*********************************************************************
* @file  bt_device.h
* @brief Bluetooth Manager Device management interface declaration.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _BT_DEVICE_H_
#define _BT_DEVICE_H_

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "bt_types.h"

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
bool BT_device_add
    (
    const uint8_t idx,
    const uint8_t* bd_addr,
    const uint8_t* device_name,
    const BT_device_type_e device_type,
    const bool auth_lost,
    const bool iap_support
    );

void BT_device_clear( void );

const BT_device_info_t* BT_device_get
    (
    const uint8_t idx
    );

uint8_t BT_device_get_total_num( void );

BT_device_type_e BT_device_get_type
    (
    const uint8_t* bd_addr
    );

void BT_device_init( void );

bool BT_device_is_auth_lost
    (
    const uint8_t* bd_addr
    );

bool BT_device_is_iap_support
    (
    const uint8_t* bd_addr
    );

bool BT_device_is_max_num_reached( void );

#ifdef __cplusplus
}
#endif

#endif // _BT_DEVICE_H_
