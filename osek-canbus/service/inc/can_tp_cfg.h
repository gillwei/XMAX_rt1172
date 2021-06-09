/*!*******************************************************************
* @file can_tp_cfg.h
* @brief Garmin CAN Stack Transport Protocol Layer Configuration
*
* This file contains configuration macros for the Garmin CAN Stack
* Transport Protocol Layer.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @defgroup can_tp_cfg CAN Stack Transport Protocol Configuration
* @ingroup can_tp
* @{
*
*********************************************************************/
#ifndef _CAN_TP_CFG_H
#define _CAN_TP_CFG_H
#include "can_dll_prv_par.h"
#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/
/*------------------------------------------------------
TP Channel Definition Macros
------------------------------------------------------*/
#define DIAGNOSTICS_TP_CHANNEL_INDEX                (0)
#define LINKCARD_LIST_TP_CHANNEL_INDEX              (1)

/*------------------------------------------------------
TP Channel Definition Macros
------------------------------------------------------*/
//#define DIAGNOSTICS_TP_PHYSICAL_CAN_ID_INDEX        (0)/*not use*/
//#define DIAGNOSTICS_TP_FUNCTIONAL_CAN_ID_INDEX      (1)/*not use*/

/*------------------------------------------------------
CAN0 Message Types (CAN Standard 11 Bit or Extended 29
Bit Identifiers)
------------------------------------------------------*/
#define TP_CAN0_STD_EXT_MSG_TYPE            CAN_STANDARD_MSG_TYPE

/*------------------------------------------------------
CAN0 Number of TP Channels
------------------------------------------------------*/
#define TP_CAN0_NUM_CHANNELS                ( TP_DIAG_ID_CAN0_NUM_TX_FRAMES )/*23 channels*/

/*------------------------------------------------------
CAN0 Channel 0  (Diagnostics)
------------------------------------------------------*/
#define TP_CAN0_CHN0_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN0_CAN_ID
#define TP_CAN0_CHN0_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN0_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN0_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN0_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN0_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN0_MAX_RPS                (255)
#define TP_CAN0_CHN0_MAX_WTS                (3)
#define TP_CAN0_CHN0_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN0_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN0_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN0_CAN_ID
//#define TP_CAN0_CHN0_RECV_CAN_ID1           TP_DIAG_ID_REQ_DIAG_FUNCTIONAL_CAN_ID


/*------------------------------------------------------
CAN0 Channel 1  (LINKCARD_LIST)
------------------------------------------------------*/
#define TP_CAN0_CHN1_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN1_CAN_ID
#define TP_CAN0_CHN1_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN1_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN1_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN1_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN1_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN1_MAX_RPS                (255)
#define TP_CAN0_CHN1_MAX_WTS                (3)
#define TP_CAN0_CHN1_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN1_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN1_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN1_CAN_ID

/*------------------------------------------------------
CAN0 Channel 2  (FI_ECU)
------------------------------------------------------*/
#define TP_CAN0_CHN2_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN2_CAN_ID
#define TP_CAN0_CHN2_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN2_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN2_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN2_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN2_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN2_MAX_RPS                (255)
#define TP_CAN0_CHN2_MAX_WTS                (3)
#define TP_CAN0_CHN2_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN2_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN2_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN2_CAN_ID

/*------------------------------------------------------
CAN0 Channel 3  (FI_ECU)
------------------------------------------------------*/
#define TP_CAN0_CHN3_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN3_CAN_ID
#define TP_CAN0_CHN3_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN3_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN3_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN3_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN3_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN3_MAX_RPS                (255)
#define TP_CAN0_CHN3_MAX_WTS                (3)
#define TP_CAN0_CHN3_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN3_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN3_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN3_CAN_ID

/*------------------------------------------------------
CAN0 Channel 4  (IDVR_LIST) Qualified Receive ID's
------------------------------------------------------*/
#define TP_CAN0_CHN4_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN4_CAN_ID
#define TP_CAN0_CHN4_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN4_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN4_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN4_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN4_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN4_MAX_RPS                (255)
#define TP_CAN0_CHN4_MAX_WTS                (3)
#define TP_CAN0_CHN4_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN4_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN4_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN4_CAN_ID


/*------------------------------------------------------
CAN0 Channel 5  (IDVR_LIST) Qualified Receive ID's
------------------------------------------------------*/
#define TP_CAN0_CHN5_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN5_CAN_ID
#define TP_CAN0_CHN5_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN5_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN5_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN5_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN5_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN5_MAX_RPS                (255)
#define TP_CAN0_CHN5_MAX_WTS                (3)
#define TP_CAN0_CHN5_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN5_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN5_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN5_CAN_ID

/*------------------------------------------------------
CAN0 Channel 6
------------------------------------------------------*/
#define TP_CAN0_CHN6_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN6_CAN_ID
#define TP_CAN0_CHN6_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN6_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN6_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN6_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN6_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN6_MAX_RPS                (255)
#define TP_CAN0_CHN6_MAX_WTS                (3)
#define TP_CAN0_CHN6_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN6_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN6_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN6_CAN_ID

/*------------------------------------------------------
CAN0 Channel 7
------------------------------------------------------*/
#define TP_CAN0_CHN7_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN7_CAN_ID
#define TP_CAN0_CHN7_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN7_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN7_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN7_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN7_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN7_MAX_RPS                (255)
#define TP_CAN0_CHN7_MAX_WTS                (3)
#define TP_CAN0_CHN7_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN7_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN7_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN7_CAN_ID

/*------------------------------------------------------
CAN0 Channel 8
------------------------------------------------------*/
#define TP_CAN0_CHN8_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN8_CAN_ID
#define TP_CAN0_CHN8_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN8_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN8_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN8_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN8_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN8_MAX_RPS                (255)
#define TP_CAN0_CHN8_MAX_WTS                (3)
#define TP_CAN0_CHN8_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN8_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN8_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN8_CAN_ID

/*------------------------------------------------------
CAN0 Channel 9
------------------------------------------------------*/
#define TP_CAN0_CHN9_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN9_CAN_ID
#define TP_CAN0_CHN9_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN9_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN9_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN9_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN9_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN9_MAX_RPS                (255)
#define TP_CAN0_CHN9_MAX_WTS                (3)
#define TP_CAN0_CHN9_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN9_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN9_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN9_CAN_ID

/*------------------------------------------------------
CAN0 Channel 10
------------------------------------------------------*/
#define TP_CAN0_CHN10_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN10_CAN_ID
#define TP_CAN0_CHN10_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN10_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN10_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN10_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN10_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN10_MAX_RPS                (255)
#define TP_CAN0_CHN10_MAX_WTS                (3)
#define TP_CAN0_CHN10_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN10_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN10_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN10_CAN_ID

/*------------------------------------------------------
CAN0 Channel 11
------------------------------------------------------*/
#define TP_CAN0_CHN11_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN11_CAN_ID
#define TP_CAN0_CHN11_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN11_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN11_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN11_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN11_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN11_MAX_RPS                (255)
#define TP_CAN0_CHN11_MAX_WTS                (3)
#define TP_CAN0_CHN11_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN11_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN11_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN11_CAN_ID

/*------------------------------------------------------
CAN0 Channel 12
------------------------------------------------------*/
#define TP_CAN0_CHN12_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN12_CAN_ID
#define TP_CAN0_CHN12_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN12_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN12_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN12_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN12_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN12_MAX_RPS                (255)
#define TP_CAN0_CHN12_MAX_WTS                (3)
#define TP_CAN0_CHN12_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN12_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN12_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN12_CAN_ID

/*------------------------------------------------------
CAN0 Channel 13
------------------------------------------------------*/
#define TP_CAN0_CHN13_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN13_CAN_ID
#define TP_CAN0_CHN13_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN13_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN13_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN13_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN13_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN13_MAX_RPS                (255)
#define TP_CAN0_CHN13_MAX_WTS                (3)
#define TP_CAN0_CHN13_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN13_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN13_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN13_CAN_ID

/*------------------------------------------------------
CAN0 Channel 14
------------------------------------------------------*/
#define TP_CAN0_CHN14_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN14_CAN_ID
#define TP_CAN0_CHN14_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN14_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN14_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN14_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN14_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN14_MAX_RPS                (255)
#define TP_CAN0_CHN14_MAX_WTS                (3)
#define TP_CAN0_CHN14_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN14_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN14_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN14_CAN_ID

/*------------------------------------------------------
CAN0 Channel 14
------------------------------------------------------*/
#define TP_CAN0_CHN15_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN15_CAN_ID
#define TP_CAN0_CHN15_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN15_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN15_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN15_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN15_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN15_MAX_RPS                (255)
#define TP_CAN0_CHN15_MAX_WTS                (3)
#define TP_CAN0_CHN15_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN15_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN15_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN15_CAN_ID

/*------------------------------------------------------
CAN0 Channel 16
------------------------------------------------------*/
#define TP_CAN0_CHN16_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN16_CAN_ID
#define TP_CAN0_CHN16_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN16_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN16_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN16_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN16_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN16_MAX_RPS                (255)
#define TP_CAN0_CHN16_MAX_WTS                (3)
#define TP_CAN0_CHN16_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN16_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN16_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN16_CAN_ID

/*------------------------------------------------------
CAN0 Channel 17
------------------------------------------------------*/
#define TP_CAN0_CHN17_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN17_CAN_ID
#define TP_CAN0_CHN17_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN17_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN17_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN17_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN17_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN17_MAX_RPS                (255)
#define TP_CAN0_CHN17_MAX_WTS                (3)
#define TP_CAN0_CHN17_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN17_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN17_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN17_CAN_ID

/*------------------------------------------------------
CAN0 Channel 18
------------------------------------------------------*/
#define TP_CAN0_CHN18_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN18_CAN_ID
#define TP_CAN0_CHN18_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN18_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN18_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN18_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN18_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN18_MAX_RPS                (255)
#define TP_CAN0_CHN18_MAX_WTS                (3)
#define TP_CAN0_CHN18_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN18_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN18_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN18_CAN_ID

/*------------------------------------------------------
CAN0 Channel 19
------------------------------------------------------*/
#define TP_CAN0_CHN19_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN19_CAN_ID
#define TP_CAN0_CHN19_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN19_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN19_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN19_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN19_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN19_MAX_RPS                (255)
#define TP_CAN0_CHN19_MAX_WTS                (3)
#define TP_CAN0_CHN19_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN19_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN19_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN19_CAN_ID

/*------------------------------------------------------
CAN0 Channel 20
------------------------------------------------------*/
#define TP_CAN0_CHN20_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN20_CAN_ID
#define TP_CAN0_CHN20_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN20_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN20_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN20_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN20_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN20_MAX_RPS                (255)
#define TP_CAN0_CHN20_MAX_WTS                (3)
#define TP_CAN0_CHN20_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN20_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN20_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN20_CAN_ID

/*------------------------------------------------------
CAN0 Channel 21
------------------------------------------------------*/
#define TP_CAN0_CHN21_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN21_CAN_ID
#define TP_CAN0_CHN21_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN21_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN21_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN21_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN21_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN21_MAX_RPS                (255)
#define TP_CAN0_CHN21_MAX_WTS                (3)
#define TP_CAN0_CHN21_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN21_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN21_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN21_CAN_ID


/*------------------------------------------------------
CAN0 Channel 22
------------------------------------------------------*/
#define TP_CAN0_CHN22_SEND_CAN_ID            TP_DIAG_ID_REP_CAN0_CHN22_CAN_ID
#define TP_CAN0_CHN22_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_CAN0_CHN22_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN22_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_CAN0_CHN22_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN22_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN22_MAX_RPS                (255)
#define TP_CAN0_CHN22_MAX_WTS                (3)
#define TP_CAN0_CHN22_IGNORE_MAX_WTS         FALSE

#define TP_CAN0_CHN22_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN22_RECV_CAN_ID0           TP_DIAG_ID_REQ_CAN0_CHN22_CAN_ID

/*--------------------------------------------------------------------
General Transport Protocol Parameters
--------------------------------------------------------------------*/

/*------------------------------------------------------
Enable H/W Timer for Precise CF STmin Timing Control
------------------------------------------------------*/
#define CAN_TP_USE_HW_TIMER_FOR_CF_TRANSMIT FALSE

/*------------------------------------------------------
STmin default value defines default Consecutive Frame
separation time in units of milliseconds.
------------------------------------------------------*/
#define TP_N_STMIN_DEFAULT          (10)

/*------------------------------------------------------
Block Size default value defines default maximum number
of frames between Flow Control frames that can be sent
in a segmented transfer. Note that a value of 0
requires sending all of the data in a single block
regardless of the number of frames required to transfer
all of the data.
------------------------------------------------------*/
#define TP_N_BLOCKSIZE_DEFAULT      (15)

/*------------------------------------------------------
Transmission timeout for any frame transmitted by a
sender, measured from request time to transmit complete
notification, in units of milliseconds.
------------------------------------------------------*/
#define TP_N_As                     (1000)

/*------------------------------------------------------
Transmission timeout for any frame transmitted by a
receiver, measured from request time to transmit complete
notification, in units of milliseconds.
------------------------------------------------------*/
#define TP_N_Ar                     (1000)

/*------------------------------------------------------
Flow control reception timeout for any sender, measured
from first frame transmit complete notification until
reception of the corresponding flow control frame, in
units of milliseconds.
------------------------------------------------------*/
#define TP_N_Bs                     (1000)
//#define TP_N_Bs                     (400)
/*------------------------------------------------------
Consecutive frame timeout for any receiver, measured
from the time that a consecutive frame is received until
the next expected consecutive frame is received, in
units of milliseconds.
------------------------------------------------------*/
#define TP_N_Cr                     (1000)

/*------------------------------------------------------
Wait frame transmit threshold ratio for any receiver
enabled for transmission of wait frames. Typically this
value is 0.9 and is multiplied by tp_n_bs to determine
the timeout for a receiver to transmit a wait frame.
------------------------------------------------------*/
#define TP_N_Bs_WFT_RATIO           (0.9)

/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/



/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/


/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/



#ifdef __cplusplus
}
#endif

#endif /* CAN_TP_CFG_H */

