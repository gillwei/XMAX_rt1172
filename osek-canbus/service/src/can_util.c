/*!*******************************************************************
* @file can_util.c
* @brief OSEK CAN Stack General Purpose Utilities
*
* This file includes general utilities that are used by a variety of
* components in the Garmin OSEK CAN Stack. Included are utilities to
* perform buffer transfers, in either a thread unprotected or
* protected (i.e. in a critical section) fashion. Also included are
* utilities for setting and clearing status bits atomically (again in
* a thread safe critical section).
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @defgroup can_stack_util Utilities
* @ingroup can_stack
* @{
*
*********************************************************************/

/*----------------------------------------------------------------
                            GENERAL INCLUDES
----------------------------------------------------------------*/
#include "can_defs.h"
#include "can_cfg.h"
#include "can_util.h"

#include "FreeRTOS.h"
#include "task.h"

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/

/*!*******************************************************************
*
* @private
* copy a byte buffer atomically (in a critical section)
*
* This function copies bytes from one memory location to another
* within a critical section for thread safety
*
*********************************************************************/
void can_util_copy_bytes_atomic
    (
    uint8   const * const p_from,       //!< [in] from pointer
    uint8         * const p_to,         //!< [in] to pointer
    uint8           const n_bytes       //!< [in] number of bytes to copy
    )
{
taskENTER_CRITICAL( );

can_util_copy_bytes( p_from, p_to, n_bytes );

taskEXIT_CRITICAL( );
}

/*!*******************************************************************
*
* @private
* copy a byte buffer
*
* This function copies bytes from one memory location to another.
* This function is not guaranteed to be thread safe in the data
* involved in the transfer is accessed in a preemptive context.
*
*********************************************************************/
void can_util_copy_bytes
    (
    uint8   const * const p_from,       //!< [in] from pointer
    uint8         * const p_to,         //!< [in] to pointer
    uint8           const n_bytes       //!< [in] number of bytes to copy
    )
{
uint8   l_ibyte;

taskENTER_CRITICAL( );

for( l_ibyte = 0; l_ibyte < n_bytes; l_ibyte++ )
    {
    p_to[l_ibyte] = p_from[l_ibyte];
    }

taskEXIT_CRITICAL( );
}

/*!*******************************************************************
*
* @private
* set uint8 status bits atomically
*
* This function sets bits in the specified uint8 status register in
* an atomic, thread safe manner (i.e. in a critical section). The bits
* that are set are specified by the "bit_mask" parameter.
*
*********************************************************************/
void can_util_set_status_bits
    (
    uint8     * const p_status,         //!< [out] pointer to status register
    uint8       const bit_mask          //!< [in] bit mask (bits to be set)
    )
{
*( p_status ) |= bit_mask;
}

/*!*******************************************************************
*
* @private
* clear uint8 status bits atomically
*
* This function clears bits in the specified uint8 status register in
* an atomic, thread safe manner (i.e. in a critical section). The bits
* that are cleared are specified by the "bit_mask" parameter.
*
*********************************************************************/
void can_util_clear_status_bits
    (
    uint8     * const p_status,         //!< [out] pointer to status register
    uint8       const bit_mask          //!< [in] bit mask (bits to be cleared)
    )
{
*( p_status ) &= SYS_MASK8_COMPLEMENT( bit_mask );
}

/*!*******************************************************************
*
* @private
* set uint16 status bits atomically
*
* This function sets bits in the specified uint8 status register in
* an atomic, thread safe manner (i.e. in a critical section). The bits
* that are set are specified by the "bit_mask" parameter.
*
*********************************************************************/
void can_util_set_status16_bits
    (
    uint16    * const p_status,         //!< [out] pointer to status register
    uint16      const bit_mask          //!< [in] bit mask (bits to be set)
    )
{
*( p_status ) |= bit_mask;
}

/*!*******************************************************************
*
* @private
* clear uint16 status bits atomically
*
* This function clears bits in the specified uint16 status register in
* an atomic, thread safe manner (i.e. in a critical section). The bits
* that are cleared are specified by the "bit_mask" parameter.
*
*********************************************************************/
void can_util_clear_status16_bits
    (
    uint16    * const p_status,         //!< [out] pointer to status register
    uint16      const bit_mask          //!< [in] bit mask (bits to be set)
    )
{
*( p_status ) &= SYS_MASK16_COMPLEMENT( bit_mask );
}

