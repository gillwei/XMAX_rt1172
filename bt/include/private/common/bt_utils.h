/*********************************************************************
* @file  bt_utils.h
* @brief Bluetooth Manager Utility interface declaration.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _BT_UTILS_H_
#define _BT_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "bt_hw.h"
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
// This is used to expand 6-bytes BD address in printf() only, use carefully
#define BD_ADDR_PRINT( x ) x[5],x[4],x[3],x[2],x[1],x[0]

#define INT16_TO_LITTLE_ENDIAN( int16, p_buf ) {\
    ( p_buf )[0] = ( int16 >> 0 ) & 0xff;       \
    ( p_buf )[1] = ( int16 >> 8 ) & 0xff;       \
    }

#define INT32_TO_LITTLE_ENDIAN( int32, p_buf ) {\
    ( p_buf )[0] = ( int32 >>  0 ) & 0xff;      \
    ( p_buf )[1] = ( int32 >>  8 ) & 0xff;      \
    ( p_buf )[2] = ( int32 >> 16 ) & 0xff;      \
    ( p_buf )[3] = ( int32 >> 24 ) & 0xff;      \
    }

#define LITTLE_ENDIAN_TO_INT16( p_buf ) (\
    ( ( ( p_buf )[0] & 0xff ) << 0 ) |   \
    ( ( ( p_buf )[1] & 0xff ) << 8 )     \
    )

#define LITTLE_ENDIAN_TO_INT32( p_buf ) (\
    ( ( ( p_buf )[0] & 0xff ) <<  0 ) |  \
    ( ( ( p_buf )[1] & 0xff ) <<  8 ) |  \
    ( ( ( p_buf )[2] & 0xff ) << 16 ) |  \
    ( ( ( p_buf )[3] & 0xff ) << 24 )    \
    )

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
const char* BT_util_get_device_type_string
    (
    const BT_device_type_e device_type
    );

const char* BT_util_get_hw_mode_string
    (
    const BT_hw_mode_e hw_mode
    );

#ifdef __cplusplus
}
#endif

#endif // _BT_UTILS_H_
