/*!*******************************************************************
* @file CAN_app.h
* @brief CAN Stack Application API
*
* This file contains header files needed for initialization of the
* CAN stack application layer.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_app
* @{
*
*********************************************************************/
#ifndef _CAN_APP_H
#define _CAN_APP_H

#ifdef __cplusplus
extern "C" {
#endif

can_ret_code_t
il_app_frm_put
    (
    can_msg_t const * const can_msg_tx_p
    );

void app_init
    (
    can_hw_inst_t   const hw_inst
    );

void app_task
    (
    can_hw_inst_t   const hw_inst
    );

#ifdef __cplusplus
}
#endif

#endif /* _CAN_APP_H */

