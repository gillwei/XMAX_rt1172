/*!*******************************************************************
* @file can_dll_par.h
* @brief Dispatch Lower Layer Frame Handles for IXWW22 Application
*
*                         !!! WARNING !!!
*                 !!! COMPUTER GENERATED FILE !!!
*                    !!! DO NOT HAND MODIFY !!!
*
* The contents of this file were computer generated. Manual editing
* of this file is discouraged as it is likely to cause compilation
* errors and/or errors in run time functionalities that are dependent
* upon the contents of this file.
*
* This file contains the Dispatch Layer transmit and receive frame
* handle definitions needed for managing CAN frame transmission and
* reception in the Garmin OSEK CAN Stack. This file is generated
* using a separate Network "Gen" tool based on the CAN database
* supplied by the OEM along with user configuration inputs.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack_dll_cfg
* @{
*
*********************************************************************/

#ifndef _CAN_DLL_PAR_H
#define _CAN_DLL_PAR_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*------------------------------------------------------
INTERACTION LAYER FRAME DEFINITIONS
------------------------------------------------------*/

/*------------------------------------------------------
IL CAN0 Transmitted Frame Application Handles
------------------------------------------------------*/

#define     IL_CAN0_ID0_FUNC_INFO_TXFRM_HANDLE                  (0x0000)
#define     IL_CAN0_ID1_REQ_REPRGRM_INFO_TXFRM_HANDLE           (0x0001)
#define     IL_CAN0_ID2_RES_SCRN_TRNSTN_TXFRM_HANDLE            (0x0002)
#define     IL_CAN0_ID3_SYS_INFO_TXFRM_HANDLE                   (0x0003)
#define     IL_CAN0_ID4_PHONE_INFO_TXFRM_HANDLE                 (0x0004)
#define     IL_CAN0_ID5_INDICTR_STATUS_TXFRM_HANDLE             (0x0005)
#define     IL_CAN0_ID6_CLK_DATE_RES_TXFRM_HANDLE               (0x0006)
#define     IL_CAN0_ID7_REQ_SCRN_TRNSTN2_TXFRM_HANDLE           (0x0007)


/*------------------------------------------------------
IL CAN0 Received Frame Application Handles
------------------------------------------------------*/

#define     IL_CAN0_ID0_FUNCSW_STATUS_RXFRM_HANDLE              (0x0000)
#define     IL_CAN0_ID1_VEHICLE_INFO_RXFRM_HANDLE               (0x0001)
#define     IL_CAN0_ID2_FUNC_CNTRL_RXFRM_HANDLE                 (0x0002)
#define     IL_CAN0_ID3_CLK_DATE_REQ_RXFRM_HANDLE               (0x0003)
#define     IL_CAN0_ID4_UNIT_INFO_RXFRM_HANDLE                  (0x0004)
#define     IL_CAN0_ID5_REQ_SCRN_TRNSTN_RXFRM_HANDLE            (0x0005)
#define     IL_CAN0_ID6_RES_REPRGRM_INFO_RXFRM_HANDLE           (0x0006)
#define     IL_CAN0_ID7_RES_SCRN_TRNSTN2_RXFRM_HANDLE           (0x0007)

#ifdef __cplusplus
}
#endif

#endif /* CAN_DLL_PAR_H */
