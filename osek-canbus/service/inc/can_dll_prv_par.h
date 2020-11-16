/*!*******************************************************************
* @file can_dll_prv_par.h
* @brief Dispatch Lower Layer Frame Handle Defintions
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
* This file contains the Dispatch Layer CAN message frame definitions,
* including the CAN Identifiers and the message length definitions
* that are needed to support transmission and reception of CAN frames.
* This file is generated using a separate Network "Gen" tool based on
* the CAN database supplied by the OEM along with user configuration
* inputs.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack_dll_cfg
* @{
*
*********************************************************************/

#ifndef _CAN_DLL_PRV_PAR_H
#define _CAN_DLL_PRV_PAR_H

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
IL CAN0 Transmitted Frame ID's
------------------------------------------------------*/

#define     ID0_FUNC_INFO_CAN0_ID                               (0x5B2)
#define     ID1_REQ_REPRGRM_INFO_CAN0_ID                        (0x5B3)
#define     ID2_RES_SCRN_TRNSTN_CAN0_ID                         (0x5B4)
#define     ID3_SYS_INFO_CAN0_ID                                (0x5B5)
#define     ID4_PHONE_INFO_CAN0_ID                              (0x5B6)
#define     ID5_INDICTR_STATUS_CAN0_ID                          (0x5B7)
#define     ID6_CLK_DATE_RES_CAN0_ID                            (0x5B8)
#define     ID7_REQ_SCRN_TRNSTN2_CAN0_ID                        (0x5B9)


/*------------------------------------------------------
IL CAN0 Transmitted Frame Length (in Bytes) Definitions
------------------------------------------------------*/

#define     IL_CAN0_ID0_FUNC_INFO_TXFRM_LEN                     (4)
#define     IL_CAN0_ID1_REQ_REPRGRM_INFO_TXFRM_LEN              (2)
#define     IL_CAN0_ID2_RES_SCRN_TRNSTN_TXFRM_LEN               (3)
#define     IL_CAN0_ID3_SYS_INFO_TXFRM_LEN                      (1)
#define     IL_CAN0_ID4_PHONE_INFO_TXFRM_LEN                    (7)
#define     IL_CAN0_ID5_INDICTR_STATUS_TXFRM_LEN                (4)
#define     IL_CAN0_ID6_CLK_DATE_RES_TXFRM_LEN                  (6)
#define     IL_CAN0_ID7_REQ_SCRN_TRNSTN2_TXFRM_LEN              (2)


/*------------------------------------------------------
IL CAN0 Transmitted Frame Index Definitions
------------------------------------------------------*/

#define     IL_CAN0_ID0_FUNC_INFO_TXFRM_INDEX                   DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_ID0_FUNC_INFO_TXFRM_HANDLE )
#define     IL_CAN0_ID1_REQ_REPRGRM_INFO_TXFRM_INDEX            DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_ID1_REQ_REPRGRM_INFO_TXFRM_HANDLE )
#define     IL_CAN0_ID2_RES_SCRN_TRNSTN_TXFRM_INDEX             DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_ID2_RES_SCRN_TRNSTN_TXFRM_HANDLE )
#define     IL_CAN0_ID3_SYS_INFO_TXFRM_INDEX                    DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_ID3_SYS_INFO_TXFRM_HANDLE )
#define     IL_CAN0_ID4_PHONE_INFO_TXFRM_INDEX                  DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_ID4_PHONE_INFO_TXFRM_HANDLE )
#define     IL_CAN0_ID5_INDICTR_STATUS_TXFRM_INDEX              DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_ID5_INDICTR_STATUS_TXFRM_HANDLE )
#define     IL_CAN0_ID6_CLK_DATE_RES_TXFRM_INDEX                DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_ID6_CLK_DATE_RES_TXFRM_HANDLE )
#define     IL_CAN0_ID7_REQ_SCRN_TRNSTN2_TXFRM_INDEX            DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_ID7_REQ_SCRN_TRNSTN2_TXFRM_HANDLE )

#define     IL_CAN0_TX_NUM_FRAMES                               (0x0008)


/*------------------------------------------------------
IL CAN0 Received Frame ID's
------------------------------------------------------*/

#define     ID0_FUNCSW_STATUS_CAN0_ID                           (0x5A1)
#define     ID1_VEHICLE_INFO_CAN0_ID                            (0x5AA)
#define     ID2_FUNC_CNTRL_CAN0_ID                              (0x5AB)
#define     ID3_CLK_DATE_REQ_CAN0_ID                            (0x5AC)
#define     ID4_UNIT_INFO_CAN0_ID                               (0x5AD)
#define     ID5_REQ_SCRN_TRNSTN_CAN0_ID                         (0x5AE)
#define     ID6_RES_REPRGRM_INFO_CAN0_ID                        (0x5AF)
#define     ID7_RES_SCRN_TRNSTN2_CAN0_ID                        (0x5B1)


/*------------------------------------------------------
IL CAN0 Received Frame Length (in Bytes) Definitions
------------------------------------------------------*/

#define     IL_CAN0_ID0_FUNCSW_STATUS_RXFRM_LEN                 (3)
#define     IL_CAN0_ID1_VEHICLE_INFO_RXFRM_LEN                  (8)
#define     IL_CAN0_ID2_FUNC_CNTRL_RXFRM_LEN                    (2)
#define     IL_CAN0_ID3_CLK_DATE_REQ_RXFRM_LEN                  (6)
#define     IL_CAN0_ID4_UNIT_INFO_RXFRM_LEN                     (1)
#define     IL_CAN0_ID5_REQ_SCRN_TRNSTN_RXFRM_LEN               (2)
#define     IL_CAN0_ID6_RES_REPRGRM_INFO_RXFRM_LEN              (3)
#define     IL_CAN0_ID7_RES_SCRN_TRNSTN2_RXFRM_LEN              (3)


/*------------------------------------------------------
IL CAN0 Received Minimum Frame Length (in Bytes)
------------------------------------------------------*/

#define     IL_CAN0_ID0_FUNCSW_STATUS_RXFRM_MIN_LEN             (3)
#define     IL_CAN0_ID1_VEHICLE_INFO_RXFRM_MIN_LEN              (8)
#define     IL_CAN0_ID2_FUNC_CNTRL_RXFRM_MIN_LEN                (2)
#define     IL_CAN0_ID3_CLK_DATE_REQ_RXFRM_MIN_LEN              (6)
#define     IL_CAN0_ID4_UNIT_INFO_RXFRM_MIN_LEN                 (1)
#define     IL_CAN0_ID5_REQ_SCRN_TRNSTN_RXFRM_MIN_LEN           (2)
#define     IL_CAN0_ID6_RES_REPRGRM_INFO_RXFRM_MIN_LEN          (3)
#define     IL_CAN0_ID7_RES_SCRN_TRNSTN2_RXFRM_MIN_LEN          (3)


/*------------------------------------------------------
IL CAN0 Received Frame Index Definitions
------------------------------------------------------*/

#define     IL_CAN0_ID0_FUNCSW_STATUS_RXFRM_INDEX               DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_ID0_FUNCSW_STATUS_RXFRM_HANDLE )
#define     IL_CAN0_ID1_VEHICLE_INFO_RXFRM_INDEX                DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_ID1_VEHICLE_INFO_RXFRM_HANDLE )
#define     IL_CAN0_ID2_FUNC_CNTRL_RXFRM_INDEX                  DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_ID2_FUNC_CNTRL_RXFRM_HANDLE )
#define     IL_CAN0_ID3_CLK_DATE_REQ_RXFRM_INDEX                DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_ID3_CLK_DATE_REQ_RXFRM_HANDLE )
#define     IL_CAN0_ID4_UNIT_INFO_RXFRM_INDEX                   DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_ID4_UNIT_INFO_RXFRM_HANDLE )
#define     IL_CAN0_ID5_REQ_SCRN_TRNSTN_RXFRM_INDEX             DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_ID5_REQ_SCRN_TRNSTN_RXFRM_HANDLE )
#define     IL_CAN0_ID6_RES_REPRGRM_INFO_RXFRM_INDEX            DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_ID6_RES_REPRGRM_INFO_RXFRM_HANDLE )
#define     IL_CAN0_ID7_RES_SCRN_TRNSTN2_RXFRM_INDEX            DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_ID7_RES_SCRN_TRNSTN2_RXFRM_HANDLE )

#define     IL_CAN0_RX_NUM_FRAMES                               (0x0008)


/*------------------------------------------------------
NETWORK MANAGEMENT LAYER FRAME DEFINITIONS
These Definitions Apply to IXWW22 CAN test
------------------------------------------------------*/

/*------------------------------------------------------
NM Transmitted CAN ID's and Frame Number Definitions
------------------------------------------------------*/
#define     NM_LOOP_BACK_CAN_ID                                 (0x226)
#define     NM_LOOP_BACK_CAN_FRAME_MIN_LEN                      (1)

#define     NM_LOOP_BACK_TX_HANDLE                              (0xE000)
#define     NM_TX_NUM_FRAMES                                    (0x0001)

/*------------------------------------------------------
NM Receive Frame Number Definitions
------------------------------------------------------*/
#define     NM_LOOP_BACK_RX_HANDLE                              (0xE000)
#define     NM_RX_NUM_FRAMES                                    (0x0001)

/*------------------------------------------------------
FACTORY TEST LAYER TX and RX FRAME DEFINITIONS
------------------------------------------------------*/
#define     FT_REQ_CAN_ID                                       (0x691)
#define     FT_REQ_RXFRM_HANDLE                                 (0xD000)

#define     FT_REP_CAN_ID                                       (0x690)
#define     FT_REP_TXFRM_HANDLE                                 (0xC000)
#define     FT_TX_NUM_FRAMES                                    (0x0001)

/*------------------------------------------------------
TRANSPORT PROTOCOL LAYER TX FRAME DEFINITIONS
------------------------------------------------------*/
#define     TP_MIN_FRAME_HANDLE                                 (0xF000)
#define     TP_MAX_FRAME_HANDLE                                 (0xF100)

/*------------------------------------------------------
Diagnostic Request and Reply CAN ID and Frame Number
Definitions

The ECU always receives a REQuest from an external
Diagnostic test tool and sends a REPly back to the
tool using the Transport Protocol. These CAN ID's and
frame definitions apply to all CAN hardware instances.
The Diagnostic TP channel is always assigned to TP
Index 0.
------------------------------------------------------*/

#define     TP_DIAG_ID_REP_DIAG_LINKCARD_CAN_ID              (0x663)
#define     TP_DIAG_ID_REP_DIAG_LINKCARD_SFFFFC_TXFRM_HANDLE (0xF000)
#define     TP_DIAG_ID_REP_DIAG_LINKCARD_FCF_TXFRM_HANDLE    (0xF001)
#define     TP_DIAG_NUM_TX_FRAMES                            (0x0001)

#define     TP_DIAG_ID_REQ_DIAG_LINKCARD_CAN_ID              (0x763)
#define     TP_DIAG_ID_REQ_DIAG_LINKCARD_RXFRM_HANDLE        (0xF000)
#define     TP_DIAG_ID_REQ_DIAG_FUNCTIONAL_CAN_ID            (0x7FF)
#define     TP_DIAG_ID_REQ_DIAG_FUNCTIONAL_RXFRM_HANDLE      (0xF001)
#define     TP_DIAG_NUM_RX_FRAMES                            (0x0002)

/*------------------------------------------------------
CAN0 Application TP Channel Definitions
Note that transmitted TP data frames (SF, FF, CF) always
have an even numbered transmit handle and the
transmitted Flow Control Frames are odd numbered (data
frame handle + 1)
------------------------------------------------------*/
#define     TP_CAN0_ID_LINKCARD_LIST_SFFFCF_CAN_ID          (0x305)
#define     TP_CAN0_ID_LINKCARD_LIST_SFFFCF_TXFRM_HANDLE    (0xF002)
#define     TP_CAN0_ID_LINKCARD_LIST_FCF_TXFRM_HANDLE       (0xF003)

#define     TP_CAN0_NUM_TX_FRAMES                           (0x0001)

#define     TP_CAN0_ID_LINKCARD_LIST_FCF_CAN_ID             (0x2C5)
#define     TP_CAN0_ID_LINKCARD_LIST_FCF_RXFRM_HANDLE       (0xF001)

#define     TP_CAN0_NUM_RX_FRAMES                           (0x0001)

/*------------------------------------------------------
CAN0 DLL TMH Queue Size Definitions
------------------------------------------------------*/
#define     DLL_CAN0_TXC_QUEUE_SIZE     ( ( IL_CAN0_TX_NUM_FRAMES + NM_TX_NUM_FRAMES + TP_DIAG_NUM_TX_FRAMES + TP_CAN0_NUM_TX_FRAMES + FT_TX_NUM_FRAMES ) * 2 )

/*------------------------------------------------------
FILTER ASSIGNMENT MACRO's
------------------------------------------------------*/

/*------------------------------------------------------
CAN0 Receive Filter Assignment Macro's
------------------------------------------------------*/

#define     DLL_CAN0_VCTR0_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR1_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR2_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR3_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR4_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR5_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR6_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR7_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR8_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR9_NUM_IDS                              (1)
#define     DLL_CAN0_VCTR10_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR11_NUM_IDS                             (1)
#define     DLL_CAN0_VCTR12_NUM_IDS                             (1)

#define     DLL_CAN0_NUM_FILT_VCTRS                             (13)

#ifdef __cplusplus
}
#endif

#endif /* _CAN_DLL_PRV_PAR_H */

