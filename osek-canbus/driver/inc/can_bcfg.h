/*!*******************************************************************
* @file can_bcfg.h
* @brief RT1170 FlexCAN Hardware Configuration Build File
*
* This file checks the configuration definitions (macros) in the
* "can_cfg.h" file to make sure that all required definitions are
* included and are properly specified. Missing or improper definitions
* will break the compilation. Assuming all the configuration
* parameters in the can_cfg.h file are in place and correct, this file
* is used to define specific register bit values and assemble an
* initialization data structure that comprehends and includes all of
* the required behavioral configurations and translates them to a set
* of initialization register values.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_hw_drv
* @{
*
*********************************************************************/

#ifndef _CAN_BCFG_H
#define _CAN_BCFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "can_cfg.h"

/*--------------------------------------------------------------------
General Configuration Definitions (Applies to All Instantiations)
--------------------------------------------------------------------*/
/*------------------------------------------------------
CAN bus support
------------------------------------------------------*/
#define SYC_CAN_SUPPORT     TRUE

/*------------------------------------------------------
CAN bus Debug
------------------------------------------------------*/
#define DEBUG_CAN_SUPPORT   FALSE

/*------------------------------------------------------
CAN Hardware N_As Transmit Timeout
------------------------------------------------------*/
#define CAN_HW_N_AS_TIMEOUT_TICS    ( (uint16)                                          \
                                    ( ( ( (float) CAN_HW_N_AS_TRANSMIT_TIMEOUT_MS ) /   \
                                        ( (float) CAN_HW_TASK_PERIOD_MS ) ) + 0.5 ) )

#ifdef __cplusplus
}
#endif

#endif /* _CAN_BCFG_H */
