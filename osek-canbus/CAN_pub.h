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
#include "CAN_nim_ctrl.h"

typedef enum tagIL_RX_FRM_INDEX_TYPE //!< Interaction Layer receive frames index
    {
    IL_RX_FRM_INDEX_FUNC_SW_STATUS,
    IL_RX_FRM_INDEX_VEHICLE_INFO,
    IL_RX_FRM_INDEX_FUNC_CNTRL,
    IL_RX_FRM_INDEX_CLK_DATE_REQ,
    IL_RX_FRM_INDEX_UNIT_INFO,
    IL_RX_FRM_INDEX_REQ_SCREEN_TRANS,
    IL_RX_FRM_INDEX_RES_REPROGRAM_INFO,
    IL_RX_FRM_INDEX_REQ_SCREEN_TRANS2,

    IL_RX_FRM_INDEX_ERRORS
    }il_rx_frm_index_t;

#ifdef __cplusplus
}
#endif

#endif /* _CAN_PUB_H */


