/*!*******************************************************************
* @file can_util.h
* @brief General OSEK CAN Stack Utilities API
*
* This file includes the function prototypes for general CAN utilities
* used by the Garmin OSEK CAN Stack components.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack_util
* @{
*
*********************************************************************/

#ifndef _CAN_UTIL_H
#define _CAN_UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
void can_util_copy_bytes_atomic
    (
    uint8       const * const p_from,
    uint8             * const p_to,
    uint8               const n_bytes
    );

void can_util_copy_bytes
    (
    uint8       const * const p_from,
    uint8             * const p_to,
    uint8               const n_bytes
    );

void can_util_set_status_bits
    (
    uint8             * const p_status,
    uint8               const bit_mask
    );

void can_util_clear_status_bits
    (
    uint8             * const p_status,
    uint8               const bit_mask
    );

void can_util_set_status16_bits
    (
    uint16             * const p_status,
    uint16               const bit_mask
    );

void can_util_clear_status16_bits
    (
    uint16            * const p_status,
    uint16              const bit_mask
    );

#ifdef __cplusplus
}
#endif

#endif /* _CAN_UTIL_H */

