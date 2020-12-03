/*!*******************************************************************
* @file can_nim_cfg.h
* @brief CAN Stack NIM Layer IXWW22 Application Configuration
*
* This file contains configuration parameters for the CAN Network
* Interface Manager and for other component layers in the Garmin
* OSEK CAN Stack design and implementation.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @defgroup can_stack_nim_cfg CAN Stack NIM Layer IXWW22 Application
* Configuration
*
* @ingroup  can_stack_nim
* @{
*
*********************************************************************/

#ifndef _CAN_NIM_CFG_H
#define _CAN_NIM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*------------------------------------------------------
Interaction Layer Task Period
------------------------------------------------------*/
#define IL_TASK_PERIOD_MS                       (10)

/*------------------------------------------------------
Network Management Layer Task Period
------------------------------------------------------*/
#define NM_TASK_PERIOD_MS                       (10)

/*------------------------------------------------------
CAN Task Container Tick Divide
/------------------------------------------------------*/
#define  CAN_NIM_TASK_COUNT_INIT                (2)

#ifdef __cplusplus
}
#endif

#endif /* _CAN_NIM_CFG_H */

/*!*******************************************************************
*
* @}
*
*********************************************************************/

