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
#define DIAGNOSTICS_TP_PHYSICAL_CAN_ID_INDEX        (0)
#define DIAGNOSTICS_TP_FUNCTIONAL_CAN_ID_INDEX      (1)

/*------------------------------------------------------
CAN0 Message Types (CAN Standard 11 Bit or Extended 29
Bit Identifiers)
------------------------------------------------------*/
#define TP_CAN0_STD_EXT_MSG_TYPE            CAN_STANDARD_MSG_TYPE

/*------------------------------------------------------
CAN0 Number of TP Channels
------------------------------------------------------*/
#define TP_CAN0_NUM_CHANNELS                (TP_DIAG_NUM_TX_FRAMES + TP_CAN0_NUM_TX_FRAMES)

/*------------------------------------------------------
CAN0 Channel 0  (Diagnostics)
------------------------------------------------------*/
#define TP_CAN0_CHN0_SEND_CAN_ID            TP_DIAG_ID_REP_DIAG_LINKCARD_CAN_ID
#define TP_CAN0_CHN0_TX_DATA_FRAME_HANDLE   TP_DIAG_ID_REP_DIAG_LINKCARD_SFFFFC_TXFRM_HANDLE
#define TP_CAN0_CHN0_TX_FCF_FRAME_HANDLE    TP_DIAG_ID_REP_DIAG_LINKCARD_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN0_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN0_MAX_RPS                (200)
#define TP_CAN0_CHN0_MAX_WTS                (3)
#define TP_CAN0_CHN0_IGNORE_MAX_WTS         TRUE

/*------------------------------------------------------
CAN0 Channel 0  (Diagnostics) Qualified Receive ID's
------------------------------------------------------*/
#define TP_CAN0_CHN0_NUM_RECV_CAN_IDS       (2)
#define TP_CAN0_CHN0_RECV_CAN_ID0           TP_DIAG_ID_REQ_DIAG_LINKCARD_CAN_ID
#define TP_CAN0_CHN0_RECV_CAN_ID1           TP_DIAG_ID_REQ_DIAG_FUNCTIONAL_CAN_ID

/*------------------------------------------------------
CAN0 Channel 1  (LINKCARD_LIST)
------------------------------------------------------*/
#define TP_CAN0_CHN1_SEND_CAN_ID            TP_CAN0_ID_LINKCARD_LIST_SFFFCF_CAN_ID
#define TP_CAN0_CHN1_TX_DATA_FRAME_HANDLE   TP_CAN0_ID_LINKCARD_LIST_SFFFCF_TXFRM_HANDLE
#define TP_CAN0_CHN1_TX_FCF_FRAME_HANDLE    TP_CAN0_ID_LINKCARD_LIST_FCF_TXFRM_HANDLE
#define TP_CAN0_CHN1_RECV_XFR_QUEUE_SIZE    (10)
#define TP_CAN0_CHN1_MAX_RPS                (100)
#define TP_CAN0_CHN1_MAX_WTS                (3)
#define TP_CAN0_CHN1_IGNORE_MAX_WTS         FALSE

/*------------------------------------------------------
CAN0 Channel 1  (IDVR_LIST) Qualified Receive ID's
------------------------------------------------------*/
#define TP_CAN0_CHN1_NUM_RECV_CAN_IDS       (1)
#define TP_CAN0_CHN1_RECV_CAN_ID0           TP_CAN0_ID_LINKCARD_LIST_FCF_CAN_ID

/*--------------------------------------------------------------------
General Transport Protocol Parameters
--------------------------------------------------------------------*/

/*------------------------------------------------------
Enable H/W Timer for Precise CF STmin Timing Control
------------------------------------------------------*/
#define CAN_TP_USE_HW_TIMER_FOR_CF_TRANSMIT TRUE

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
#define TP_N_BLOCKSIZE_DEFAULT      (0)

/*------------------------------------------------------
Transmission timeout for any frame transmitted by a
sender, measured from request time to transmit complete
notification, in units of milliseconds.
------------------------------------------------------*/
#define TP_N_As                     (20)

/*------------------------------------------------------
Transmission timeout for any frame transmitted by a
receiver, measured from request time to transmit complete
notification, in units of milliseconds.
------------------------------------------------------*/
#define TP_N_Ar                     (20)

/*------------------------------------------------------
Flow control reception timeout for any sender, measured
from first frame transmit complete notification until
reception of the corresponding flow control frame, in
units of milliseconds.
------------------------------------------------------*/
#define TP_N_Bs                     (250)

/*------------------------------------------------------
Consecutive frame timeout for any receiver, measured
from the time that a consecutive frame is received until
the next expected consecutive frame is received, in
units of milliseconds.
------------------------------------------------------*/
#define TP_N_Cr                     (250)

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

