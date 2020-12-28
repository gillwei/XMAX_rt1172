/*!*******************************************************************
* @file can_pub.h
* @brief OSEK CAN Stack public header file
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack
* @{
*
*********************************************************************/

#ifndef _CAN_PUB_H
#define _CAN_PUB_H

#ifdef __cplusplus
extern "C" {
#endif
#include "can_il_par.h"
#include "can_il.h"

void il_app_sig_put
    (
    il_sig_handle_t         const sig_handle,
    uint8_t                 const num_bytes,
    uint64_t                      sig_val
    );

void il_app_sig_get
    (
    il_sig_handle_t         const sig_handle,
    uint8_t                 const num_bytes,
    uint32_t                     *p_sig_val
    );

#ifdef __cplusplus
}
#endif

#endif /* _CAN_PUB_H */


