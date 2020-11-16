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
* @defgroup can_stack_nim_cfg CAN Stack NIM Layer IXWW22 Application Configuration
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
                            MACROS
--------------------------------------------------------------------*/
/*------------------------------------------------------
Network Interface Manager Task initial Period
------------------------------------------------------*/
#define CAN_NIM_TASK_PERIOD_MS                  (5)

/*------------------------------------------------------
Interaction Layer Task Period
------------------------------------------------------*/
#define IL_TASK_PERIOD_MS                       (10)

/*------------------------------------------------------
Network Management Layer Task Period
------------------------------------------------------*/
#define NM_TASK_PERIOD_MS                       (10)

/*------------------------------------------------------
Transport Layer Task Period
------------------------------------------------------*/
#define TP_TASK_PERIOD_MS                       (5)

/*------------------------------------------------------
Diagnostic Layer Task Period
------------------------------------------------------*/
#define DIAG_TASK_PERIOD_MS                     (5)

#ifdef __cplusplus
}
#endif

#endif /* _CAN_NIM_CFG_H */

/*!*******************************************************************
*
* @}
*
*********************************************************************/
