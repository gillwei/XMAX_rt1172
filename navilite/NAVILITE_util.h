/*********************************************************************
* @file
* NAVILITE_util.h
*
* @brief
* NaviLight module - utility header
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef NAVILITE_UTIL_H
#define NAVILITE_UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <stdint.h>  // for uint8_t etc
#include <stdbool.h> // for bool
#include <stddef.h>  // for NULL
#include <string.h>  // for memset()

#include "NAVILITE_pub.h"

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define ENABLE_NAVILITE_DEBUG_LOG ( 0 )

#if( ENABLE_NAVILITE_DEBUG_LOG )
    #define NAVILITE_PRINTF PRINTF
#else
    #define NAVILITE_PRINTF(fmt,...)
#endif

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

float NAVILITE_bytes_to_float
    (
    uint32_t bytes_value
    );

uint32_t NAVILITE_float_to_bytes
    (
    float float_value
    );

void NAVILITE_print_utf8
    (
    uint8_t* str,
    uint16_t str_size
    );

void NAVILITE_print_frame
    (
    navilite_message* msg
    );

#ifdef __cplusplus
}
#endif

#endif /*NAVILITE_UTIL_H */
