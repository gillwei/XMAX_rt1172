/*!*******************************************************************
* @file can_tp.c
* @brief CAN Stack Transport Protocol Layer
*
* This file represents the middleware implementation of the Garmin
* ISO15765-2 compliant Transport Protocol Layer. This implementation
* assumes use of a low level CAN protocol for the frame transfers.
*
* @defgroup can_tp CAN Stack Transport Protocol Layer
* @ingroup can_stack
* @{
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <string.h>
#include "can_defs.h"
#include "can_cfg.h"
#include "can_nim_cfg.h"
#include "can_drv.h"
#include "can_svcs.h"
#include "can_dll.h"
#include "can_dll_prv_par.h"
#include "can_tp_cfg.h"
#include "can_tp.h"
#include "fsl_debug_console.h"/*for debug*/
#include "client_dcm.h"


#define CANTP_DEBUG  FALSE
/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/
/*------------------------------------------------------
Convert Wait To Send (WTS) Flow Control Timer Ratio
in Milliseconds.
------------------------------------------------------*/
#define TP_N_Bs_WFT_TIMEOUT ( (uint16) ( ( ( (float) TP_N_Bs_WFT_RATIO ) * ( (float) TP_N_Bs ) ) + 0.5 ) )

/*------------------------------------------------------
Maximum Consecutive Frame Sequence Number Mask and
Maximum Value
------------------------------------------------------*/
#define TP_SN_MASK                  (0x0Fu)
#define TP_CF_SN_MAX_VALUE          (0x0Fu)

/*------------------------------------------------------
Maximum STmin Value in mS
------------------------------------------------------*/
#define TP_MAX_STMIN_VALUE_IN_MS    (0x7Fu)

/*------------------------------------------------------
Minimum and Maximum STmin Values for 100uS increments.
------------------------------------------------------*/
#define TP_MIN_STMIN_VALUE_IN_US    (0xF1u)
#define TP_MAX_STMIN_VALUE_IN_US    (0xF9u)

/*------------------------------------------------------
Maximum Useable Data Bytes by Frame Type
------------------------------------------------------*/
#define TP_SF_MAX_DATA_BYTES        (0x07u)
#define TP_FF_MAX_DATA_BYTES        (0x06u)
#define TP_CF_MAX_DATA_BYTES        (0x07u)

/*------------------------------------------------------
Flow Control Frame Number of Data Bytes
------------------------------------------------------*/
#define TP_FCF_NUM_BYTES            (0x08u)

/*------------------------------------------------------
Macros Used for Byte Masks and Other Manipulations
------------------------------------------------------*/
#define TP_GPNUM_FF                 (0xFFu)
#define TP_GPNUM_0F                 (0x0Fu)
#define TP_GPNUM_F0                 (0xF0u)

#define TP_GPNUM_2                  (2)
#define TP_GPNUM_6                  (6)
#define TP_GPNUM_7                  (7)
#define TP_GPNUM_8                  (8)

/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/
/*------------------------------------------------------
TP Network Frame Type
------------------------------------------------------*/
typedef enum tagTP_N_FRAME_TYPE     //!< Transport Protocol Frame Type Definition
    {
    TP_NF_SF,                       //!< Single Frame
    TP_NF_FF,                       //!< First Frame
    TP_NF_CF,                       //!< Consecutive Frame
    TP_NF_FCF_CTS,                  //!< Flow Control Frame Clear To Send
    TP_NF_FCF_WTS,                  //!< Flow Control Frame Wait To Send
    TP_NF_FCF_OVFLW,                //!< Flow Control Frame Overflow

    TP_NF_UNDEFINED

    } tp_n_frame_t;

/*------------------------------------------------------
TP Frame PCI Byte Values

Following are the actual ISO15765-2 Frame PCI byte
values that correspond to the different frame types.
------------------------------------------------------*/
typedef uint8   tp_n_pci_t;

#define TP_NP_SF_PCI                (0x00u)
#define TP_NP_FF_PCI                (0x10u)
#define TP_NP_CF_PCI                (0x20u)
#define TP_NP_FCF_PCI               (0x30u)
#define TP_NP_FCF_CTS_PCI           (0x30u)
#define TP_NP_FCF_WTS_PCI           (0x31u)
#define TP_NP_FCF_OVFLW_PCI         (0x32u)

/*------------------------------------------------------
TP Send State Type Definition
------------------------------------------------------*/
typedef enum tagTP_N_SEND_STATE_TYPE            //!< TP Send State Type Definition
    {
    TP_NS_SEND_IDLE,                            //!< Send State Machine is Idle
    TP_NS_SEND_WSFTXC,                          //!< Wait for SF Tx Complete
    TP_NS_SEND_WFFTXC,                          //!< Wait for FF Tx Complete
    TP_NS_SEND_WFCFRX,                          //!< Wait for FCF Reception
    TP_NS_SEND_WSTMIN,                          //!< Wait for STmin Timer to Elapse
    TP_NS_SEND_WCFTXC,                          //!< Wait for CF Tx Complete

    TP_NS_NUM_SEND_STATES

    } tp_n_send_state_t;

/*------------------------------------------------------
TP Send Transfer Data Structure
------------------------------------------------------*/
typedef struct tagTP_N_SEND_XFR_TYPE            //!< TP Send Transfer Type Definition
    {
    tp_n_send_state_t       state;              //!< Send transfer state
    uint8                   status;             //!< send status
    uint8           const * p_data;             //!< pointer to client data to send
    uint16                  num_sent;           //!< number of bytes sent
    uint16                  num_total;          //!< total number of bytes to send
    uint8                   seq_num;            //!< current Consecutive Frame sequence number
    uint8                   block_num;          //!< current block number
    uint8                   block_size;         //!< block size sent by the receiver
    uint8                   st_min;             //!< STmin sent by the receiver
    uint8                   num_wtfcf_rcvd;     //!< number of Wait Flow Control Frames received
    uint16                  n_as_timeout;       //!< N_As timeout (in milliseconds)
    uint16                  timer;              //!< timeout counter (in task timer ticks)
    } tp_n_send_xfr_t;

/*------------------------------------------------------
TP Send Transfer Status Bit Field Definitions
------------------------------------------------------*/
#define TP_NB_SEND_FCF_RXC_PNDG             (0x1u << 0)     //!< Pending FCF reception
#define TP_NB_SEND_OK_TO_UPDATE_BS_ST       (0x1u << 1)     //!< OK to update Block Size and STmin

/*------------------------------------------------------
TP Receive Transfer State Type Definition
------------------------------------------------------*/
typedef enum tagTP_N_RECEIVE_STATE_TYPE         //!< TP Receive State Type Definition
    {
    TP_NS_RECV_IDLE,                            //!< Receive State Machine is Idle
    TP_NS_RECV_WCTSTXC,                         //!< Wait for CTS FC Transmit Complete
    TP_NS_RECV_WCFRX,                           //!< Wait for CF Reception
    TP_NS_RECV_WOVFTXC,                         //!< Wait for Overflow FCF Tx Complete
    TP_NS_RECV_WWTSTXC,                         //!< Wait for WTS FCF Tx Complete
    TP_NS_RECV_SUSPEND,                         //!< Receive Suspended

    TP_NS_NUM_RECEIVE_STATES

    } tp_n_receive_state_t;

/*------------------------------------------------------
TP Receive Transfer Data Structure
------------------------------------------------------*/
typedef struct tagTP_N_RECV_XFR_TYPE            //!< TP Receive Transfer Type Definition
    {
    tp_n_receive_state_t    state;              //!< Receive transfer state
    uint8                   status;             //!< status flags
    uint8                   seq_num;            //!< sequence number
    uint8                   block_num;          //!< block number
    uint8                   block_size;         //!< block size sent in a Flow Control Frame
    uint8                   st_min;             //!< STmin sent in Flow Control Frame
    uint16                  num_rcvd;           //!< number of bytes received
    uint16                  num_total;          //!< total number of receive bytes expected
    uint8                   num_wtfcf_txd;      //!< number of Wait To Send Flow Control Frames transmitted
    uint16                  n_ar_timeout;       //!< N_Ar timeout (in milliseconds)
    uint16                  timer;              //!< timeout counter (in task timer ticks)

    } tp_n_recv_xfr_t;

/*------------------------------------------------------
TP Receive Transfer Status Bit Field Definitions
------------------------------------------------------*/
#define TP_NB_RECV_SFFFCF_RXC_PNDG          (0x1 << 0)      //!< Pending SF, FF or CF reception
#define TP_NB_RECV_FRAME_QUEUE_OVERFLOW     (0x1 << 1)      //!< Receive Frame Queue Overflow occurred
#define TP_NB_RECV_SUSPEND_PNDG             (0x1 << 2)      //!< Suspend request pending
#define TP_NB_RECV_RESUME_PNDG              (0x1 << 3)      //!< Resume request pending

/*------------------------------------------------------
TP Receive Frame Data Structure
------------------------------------------------------*/
typedef struct tagTP_N_STORE_FRAME_TYPE     //!< TP Store Received Frame Type Definition
    {
    can_rmd_t       rmd;                    //!< CAN receive frame
    tp_n_frame_t    frame_type;             //!< TP frame type

    } tp_n_store_frame_t;

/*------------------------------------------------------
TP Receive Data Packet Info Structure
------------------------------------------------------*/
typedef struct tagTP_RECV_PKT_INFO_TYPE     //!< TP Receive Packet Info Type Definition
    {
    uint8         * p_pkt_buffer;           //!< ptr to Receive packet buffer
    uint16  const   buffer_size;            //!< packet buffer size

    } tp_recv_pkt_info_t;

/*------------------------------------------------------
TP Channel Info Type
------------------------------------------------------*/
typedef struct tagTP_CHAN_INFO_TYPE                         //!< TP Channel Info Type
    {
    tp_n_send_xfr_t           * p_send_xfr;                 //!< ptr to Send transfer info
    tp_n_store_frame_t        * p_send_xfr_fcf;             //!< ptr to stored Send transfer received FCF
    can_tmd_t                 * p_send_tmd;                 //!< ptr to Send transfer CAN TMD's
    uint8                     * p_send_tmd_data;            //!< ptr to writable Send transfer SF, FF, or CF CAN TMD data
    can_tmd_t           const * p_send_ref_tmd;             //!< ptr to Send transfer reference CAN TMD's
    uint8               const   send_cf_timer_index;        //!< h/w timer index for precisely timed CF transmissions
    tp_n_recv_xfr_t           * p_recv_xfr;                 //!< ptr to Receive transfer info
    tp_n_store_frame_t        * p_recv_xfr_sfffcf;          //!< ptr to stored Receive transfer received Data frame FIFO
    uint8                     * p_recv_xfr_sfffcf_q_cnt;    //!< ptr to Receive transfer received Data frame FIFO count
    uint8               const   recv_xfr_sfffcf_q_size;     //!< size of the Receive transfer receive FIFO (all channels)
    can_tmd_t           const * p_fcf_tmd;                  //!< ptr to Receive transfer CAN FCF TMD's
    uint8                     * p_fcf_tmd_data;             //!< ptr to writable Receive transfer FCF CAN TMD data
    uint8                       num_recv_canids;            //!< number of receive CAN ID's that qualify a TP channel reception
    uint32              const * p_recv_canid;               //!< ptr to qualifying CAN receive ID's
    uint8                     * p_recv_canid_index;         //!< ptr to qualifying CAN receive ID index
    tp_recv_pkt_info_t  const * p_recv_pkt_info;            //!< ptr to Receive transfer packet info
    uint8                       wts_max;                    //!< maximum WTS FCF's for this channel
    boolean                     send_ignore_wts_max;        //!< sender ignore maximum WTS FCF's (wait forever if need be)

} tp_chan_info_t;

/*------------------------------------------------------
TP CAN Hardware Instance Channel Info Type
------------------------------------------------------*/
typedef struct tagTP_HW_INST_INFO_TYPE
    {
    uint8                           num_channels;       //!< number of H/W instance TP channels
    tp_chan_info_t  const * const   p_tp_chan_info;     //!< ptr to TP channel information

    } tp_hw_inst_info_t;

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
/*------------------------------------------------------
TP Channel Data

Note that the following data structures are defined to
support up to 5 TP channel definitions (both Send and
Receive) for each CAN hardware instance (physical
network connection) and up to 2 separate hardware
instances. If there are more than 5 TP channels defined
for any given hardware instance, these data structures
will need to be expanded. Also if more than 2 CAN
hardware instances need to be supported, these data
structures would also need to be expanded.
------------------------------------------------------*/
/*------------------------------------------------------
CAN0 Hardware Instance TP Channel Data
------------------------------------------------------*/

/*------------------------------------------------------
CAN0 Send Transfer Data Structures
------------------------------------------------------*/
static tp_n_send_xfr_t
tp_can0_send_xfr[TP_CAN0_NUM_CHANNELS];

/*------------------------------------------------------
CAN0 store a Send Transfer received Flow Control Frame
and frame type until it can be processed.
------------------------------------------------------*/
static tp_n_store_frame_t
tp_can0_send_xfr_fcf[TP_CAN0_NUM_CHANNELS];

/*------------------------------------------------------
CAN0 Data Frame Buffers (SF, FF, or CF)
------------------------------------------------------*/
static uint8
tp_can0_sf_ff_cf_data[TP_CAN0_NUM_CHANNELS][CAN_MAX_DATA_LENGTH];

/*------------------------------------------------------
CAN0 Send Transfer CAN Transmit Data Structures (Needed
to Transmit SF, FF, CF Frames).
------------------------------------------------------*/
static can_tmd_t
tp_can0_send_tmd[TP_CAN0_NUM_CHANNELS];

/*------------------------------------------------------
Send Transfer Reference CAN TMD's Used to Initialize the
Send TMD's.
------------------------------------------------------*/
static can_tmd_t const
tp_can0_send_ref_tmd[TP_CAN0_NUM_CHANNELS] =
    {
        {
        TP_CAN0_CHN0_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN0_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN0_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN1_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN1_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN1_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN2_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN2_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN2_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN3_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN3_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN3_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN4_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN4_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN4_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN5_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN5_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN5_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN6_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN6_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN6_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN7_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN7_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN7_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN8_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN8_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN8_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN9_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN9_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN9_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN10_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN10_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN10_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN11_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN11_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN11_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN12_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN12_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN12_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN13_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN13_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN13_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN14_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN14_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN14_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN15_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN15_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN15_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN16_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN16_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN16_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN17_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN17_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN17_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN18_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN18_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN18_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN19_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN19_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN19_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN20_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN20_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN20_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN21_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN21_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN21_TX_DATA_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN22_SEND_CAN_ID,
        tp_can0_sf_ff_cf_data[TP_CHN_FUNC_INDEX],
        CAN_MAX_DATA_LENGTH,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN22_TX_DATA_FRAME_HANDLE
        }
    };

/*------------------------------------------------------
CAN0 Receive Transfer Data Structures
------------------------------------------------------*/
static tp_n_recv_xfr_t
tp_can0_recv_xfr[TP_CAN0_NUM_CHANNELS];

/*------------------------------------------------------
CAN0 Store Receive Transfer SF, FF and CF frames until
they can be processed. A FIFO is provided to prevent
receive overflow. Each channel can define its own
FIFO queue size.
------------------------------------------------------*/
static tp_n_store_frame_t
tp_can0_recv_xfr_sfffcf[TP_CAN0_NUM_CHANNELS][TP_CAN0_CHN0_RECV_XFR_QUEUE_SIZE];

static uint8
tp_can0_recv_xfr_sfffcf_q_cnt[TP_CAN0_NUM_CHANNELS];

/*------------------------------------------------------
CAN0 Receive Transfer Flow Control Frame Data Buffers
------------------------------------------------------*/
static uint8
tp_can0_fcf_data[TP_CAN0_NUM_CHANNELS][TP_FCF_NUM_BYTES];

/*------------------------------------------------------
CAN0 Receive Transfer Flow Control Frame CAN TMD's
------------------------------------------------------*/
static can_tmd_t const
tp_can0_fcf_tmd[TP_CAN0_NUM_CHANNELS] =
    {
        {
        TP_CAN0_CHN0_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN0_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN0_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN1_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN1_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN1_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN2_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN2_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN2_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN3_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN3_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN3_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN4_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN4_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN4_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN5_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN5_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN5_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN6_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN6_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN6_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN7_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN7_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN7_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN8_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN8_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN8_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN9_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN9_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN9_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN10_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN10_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN10_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN11_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN11_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN11_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN12_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN12_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN12_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN13_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN13_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN13_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN14_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN14_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN14_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN15_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN15_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN15_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN16_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN16_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN16_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN17_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN17_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN17_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN18_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN18_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN18_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN19_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN19_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN19_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN20_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN20_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN20_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN21_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN21_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN21_TX_FCF_FRAME_HANDLE
        },
        {
        TP_CAN0_CHN22_SEND_CAN_ID,
        tp_can0_fcf_data[TP_CHN22_INDEX],
        TP_FCF_NUM_BYTES,
        TP_CAN0_STD_EXT_MSG_TYPE,
        TP_CAN0_CHN22_TX_FCF_FRAME_HANDLE
        },
    };

/*------------------------------------------------------
CAN0 Receive Packet Data Buffers. Each channel has its
own defined maximum packet size.
------------------------------------------------------*/
static uint8
tp_can0_receive_packet_data[TP_CAN0_NUM_CHANNELS][TP_CAN0_CHN0_MAX_RPS];


static tp_recv_pkt_info_t const
tp_can0_recv_pkt_info[TP_CAN0_NUM_CHANNELS] =
    {
        {
        tp_can0_receive_packet_data[TP_CHN0_INDEX],
        TP_CAN0_CHN0_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN1_INDEX],
        TP_CAN0_CHN1_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN2_INDEX],
        TP_CAN0_CHN2_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN3_INDEX],
        TP_CAN0_CHN3_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN4_INDEX],
        TP_CAN0_CHN4_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN5_INDEX],
        TP_CAN0_CHN5_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN6_INDEX],
        TP_CAN0_CHN6_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN7_INDEX],
        TP_CAN0_CHN7_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN8_INDEX],
        TP_CAN0_CHN8_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN9_INDEX],
        TP_CAN0_CHN9_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN10_INDEX],
        TP_CAN0_CHN10_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN11_INDEX],
        TP_CAN0_CHN11_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN12_INDEX],
        TP_CAN0_CHN12_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN13_INDEX],
        TP_CAN0_CHN13_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN14_INDEX],
        TP_CAN0_CHN14_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN15_INDEX],
        TP_CAN0_CHN15_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN16_INDEX],
        TP_CAN0_CHN16_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN17_INDEX],
        TP_CAN0_CHN17_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN18_INDEX],
        TP_CAN0_CHN18_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN19_INDEX],
        TP_CAN0_CHN19_MAX_RPS
        },
         {
        tp_can0_receive_packet_data[TP_CHN20_INDEX],
        TP_CAN0_CHN20_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN21_INDEX],
        TP_CAN0_CHN21_MAX_RPS
        },
        {
        tp_can0_receive_packet_data[TP_CHN22_INDEX],
        TP_CAN0_CHN22_MAX_RPS
        }
    };

/*------------------------------------------------------
CAN0 TP Channel Receive CAN ID's. In order to support
Diagnostics, TP Channels can qualify more than one
receive CAN ID to support physical and functional
addressing.
------------------------------------------------------*/
static uint8
tp_can0_recv_can_id_index[TP_CAN0_NUM_CHANNELS];

static const uint32
tp_can0_recv_can_id[TP_CAN0_NUM_CHANNELS][TP_CAN0_CHN0_NUM_RECV_CAN_IDS] =
{
    {TP_CAN0_CHN0_RECV_CAN_ID0},
    {TP_CAN0_CHN1_RECV_CAN_ID0},
    {TP_CAN0_CHN2_RECV_CAN_ID0},
    {TP_CAN0_CHN3_RECV_CAN_ID0},
    {TP_CAN0_CHN4_RECV_CAN_ID0},
    {TP_CAN0_CHN5_RECV_CAN_ID0},
    {TP_CAN0_CHN6_RECV_CAN_ID0},
    {TP_CAN0_CHN7_RECV_CAN_ID0},
    {TP_CAN0_CHN8_RECV_CAN_ID0},
    {TP_CAN0_CHN9_RECV_CAN_ID0},
    {TP_CAN0_CHN10_RECV_CAN_ID0},
    {TP_CAN0_CHN11_RECV_CAN_ID0},
    {TP_CAN0_CHN12_RECV_CAN_ID0},
    {TP_CAN0_CHN13_RECV_CAN_ID0},
    {TP_CAN0_CHN14_RECV_CAN_ID0},
    {TP_CAN0_CHN15_RECV_CAN_ID0},
    {TP_CAN0_CHN16_RECV_CAN_ID0},
    {TP_CAN0_CHN17_RECV_CAN_ID0},
    {TP_CAN0_CHN18_RECV_CAN_ID0},
    {TP_CAN0_CHN19_RECV_CAN_ID0},
    {TP_CAN0_CHN20_RECV_CAN_ID0},
    {TP_CAN0_CHN21_RECV_CAN_ID0},
    {TP_CAN0_CHN22_RECV_CAN_ID0}
};


/*------------------------------------------------------
CAN0 Hardware Instance TP Channel Info
------------------------------------------------------*/
tp_chan_info_t const
tp_can0_chan_info[TP_CAN0_NUM_CHANNELS] =
    {
        {
        &( tp_can0_send_xfr[TP_CHN0_INDEX] ),
        &( tp_can0_send_xfr_fcf[TP_CHN0_INDEX] ),
        &( tp_can0_send_tmd[TP_CHN0_INDEX] ),
        tp_can0_sf_ff_cf_data[TP_CHN0_INDEX],
        &( tp_can0_send_ref_tmd[TP_CHN0_INDEX] ),
        TP_CHN0_INDEX,
        &( tp_can0_recv_xfr[TP_CHN0_INDEX] ),
        tp_can0_recv_xfr_sfffcf[TP_CHN0_INDEX],
        &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN0_INDEX] ),
        TP_CAN0_CHN0_RECV_XFR_QUEUE_SIZE,
        &( tp_can0_fcf_tmd[TP_CHN0_INDEX] ),
        tp_can0_fcf_data[TP_CHN0_INDEX],
        TP_CAN0_CHN0_NUM_RECV_CAN_IDS,
        tp_can0_recv_can_id[TP_CHN0_INDEX],
        &( tp_can0_recv_can_id_index[TP_CHN0_INDEX] ),
        &( tp_can0_recv_pkt_info[TP_CHN0_INDEX] ),
        TP_CAN0_CHN0_MAX_WTS,
        TP_CAN0_CHN0_IGNORE_MAX_WTS
        },
        {
        &( tp_can0_send_xfr[TP_CHN1_INDEX] ),
        &( tp_can0_send_xfr_fcf[TP_CHN1_INDEX] ),
        &( tp_can0_send_tmd[TP_CHN1_INDEX] ),
        tp_can0_sf_ff_cf_data[TP_CHN1_INDEX],
        &( tp_can0_send_ref_tmd[TP_CHN1_INDEX] ),
        TP_CHN1_INDEX,
        &( tp_can0_recv_xfr[TP_CHN1_INDEX] ),
        tp_can0_recv_xfr_sfffcf[TP_CHN1_INDEX],
        &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN1_INDEX] ),
        TP_CAN0_CHN1_RECV_XFR_QUEUE_SIZE,
        &( tp_can0_fcf_tmd[TP_CHN1_INDEX] ),
        tp_can0_fcf_data[TP_CHN1_INDEX],
        TP_CAN0_CHN1_NUM_RECV_CAN_IDS,
        tp_can0_recv_can_id[TP_CHN1_INDEX],
        &( tp_can0_recv_can_id_index[TP_CHN1_INDEX] ),
        &( tp_can0_recv_pkt_info[TP_CHN1_INDEX] ),
        TP_CAN0_CHN1_MAX_WTS,
        TP_CAN0_CHN1_IGNORE_MAX_WTS
        },
         {
         &( tp_can0_send_xfr[TP_CHN2_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN2_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN2_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN2_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN2_INDEX] ),
         TP_CHN2_INDEX,
         &( tp_can0_recv_xfr[TP_CHN2_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN2_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN2_INDEX] ),
         TP_CAN0_CHN2_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN2_INDEX] ),
         tp_can0_fcf_data[TP_CHN2_INDEX],
         TP_CAN0_CHN2_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN2_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN2_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN2_INDEX] ),
         TP_CAN0_CHN2_MAX_WTS,
         TP_CAN0_CHN2_IGNORE_MAX_WTS
         },
         {
         &( tp_can0_send_xfr[TP_CHN3_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN3_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN3_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN3_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN3_INDEX] ),
         TP_CHN3_INDEX,
         &( tp_can0_recv_xfr[TP_CHN3_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN3_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN3_INDEX] ),
         TP_CAN0_CHN3_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN3_INDEX] ),
         tp_can0_fcf_data[TP_CHN3_INDEX],
         TP_CAN0_CHN3_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN3_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN3_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN3_INDEX] ),
         TP_CAN0_CHN3_MAX_WTS,
         TP_CAN0_CHN3_IGNORE_MAX_WTS
         },
         {
         &( tp_can0_send_xfr[TP_CHN4_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN4_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN4_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN4_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN4_INDEX] ),
         TP_CHN4_INDEX,
         &( tp_can0_recv_xfr[TP_CHN4_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN4_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN4_INDEX] ),
         TP_CAN0_CHN4_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN4_INDEX] ),
         tp_can0_fcf_data[TP_CHN4_INDEX],
         TP_CAN0_CHN4_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN4_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN4_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN4_INDEX] ),
         TP_CAN0_CHN4_MAX_WTS,
         TP_CAN0_CHN4_IGNORE_MAX_WTS
         },
         {
         &( tp_can0_send_xfr[TP_CHN5_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN5_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN5_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN5_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN5_INDEX] ),
         TP_CHN5_INDEX,
         &( tp_can0_recv_xfr[TP_CHN5_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN5_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN5_INDEX] ),
         TP_CAN0_CHN5_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN5_INDEX] ),
         tp_can0_fcf_data[TP_CHN5_INDEX],
         TP_CAN0_CHN5_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN5_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN5_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN5_INDEX] ),
         TP_CAN0_CHN5_MAX_WTS,
         TP_CAN0_CHN5_IGNORE_MAX_WTS
         },
         {
         &( tp_can0_send_xfr[TP_CHN6_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN6_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN6_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN6_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN6_INDEX] ),
         TP_CHN6_INDEX,
         &( tp_can0_recv_xfr[TP_CHN6_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN6_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN6_INDEX] ),
         TP_CAN0_CHN6_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN6_INDEX] ),
         tp_can0_fcf_data[TP_CHN6_INDEX],
         TP_CAN0_CHN6_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN6_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN6_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN6_INDEX] ),
         TP_CAN0_CHN6_MAX_WTS,
         TP_CAN0_CHN6_IGNORE_MAX_WTS
         },
         {
         &( tp_can0_send_xfr[TP_CHN7_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN7_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN7_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN7_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN7_INDEX] ),
         TP_CHN7_INDEX,
         &( tp_can0_recv_xfr[TP_CHN7_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN7_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN7_INDEX] ),
         TP_CAN0_CHN7_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN7_INDEX] ),
         tp_can0_fcf_data[TP_CHN7_INDEX],
         TP_CAN0_CHN7_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN7_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN7_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN7_INDEX] ),
         TP_CAN0_CHN7_MAX_WTS,
         TP_CAN0_CHN7_IGNORE_MAX_WTS
         },
         {
         &( tp_can0_send_xfr[TP_CHN8_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN8_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN8_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN8_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN8_INDEX] ),
         TP_CHN8_INDEX,
         &( tp_can0_recv_xfr[TP_CHN8_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN8_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN8_INDEX] ),
         TP_CAN0_CHN8_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN8_INDEX] ),
         tp_can0_fcf_data[TP_CHN8_INDEX],
         TP_CAN0_CHN8_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN8_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN8_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN8_INDEX] ),
         TP_CAN0_CHN8_MAX_WTS,
         TP_CAN0_CHN8_IGNORE_MAX_WTS
         },
         {
         &( tp_can0_send_xfr[TP_CHN9_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN9_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN9_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN9_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN9_INDEX] ),
         TP_CHN9_INDEX,
         &( tp_can0_recv_xfr[TP_CHN9_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN9_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN9_INDEX] ),
         TP_CAN0_CHN9_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN9_INDEX] ),
         tp_can0_fcf_data[TP_CHN9_INDEX],
         TP_CAN0_CHN9_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN9_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN9_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN9_INDEX] ),
         TP_CAN0_CHN9_MAX_WTS,
         TP_CAN0_CHN9_IGNORE_MAX_WTS
         },
         {
        &( tp_can0_send_xfr[TP_CHN10_INDEX] ),
        &( tp_can0_send_xfr_fcf[TP_CHN10_INDEX] ),
        &( tp_can0_send_tmd[TP_CHN10_INDEX] ),
        tp_can0_sf_ff_cf_data[TP_CHN10_INDEX],
        &( tp_can0_send_ref_tmd[TP_CHN10_INDEX] ),
        TP_CHN10_INDEX,
        &( tp_can0_recv_xfr[TP_CHN10_INDEX] ),
        tp_can0_recv_xfr_sfffcf[TP_CHN10_INDEX],
        &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN10_INDEX] ),
        TP_CAN0_CHN10_RECV_XFR_QUEUE_SIZE,
        &( tp_can0_fcf_tmd[TP_CHN10_INDEX] ),
        tp_can0_fcf_data[TP_CHN10_INDEX],
        TP_CAN0_CHN10_NUM_RECV_CAN_IDS,
        tp_can0_recv_can_id[TP_CHN10_INDEX],
        &( tp_can0_recv_can_id_index[TP_CHN10_INDEX] ),
        &( tp_can0_recv_pkt_info[TP_CHN10_INDEX] ),
        TP_CAN0_CHN10_MAX_WTS,
        TP_CAN0_CHN10_IGNORE_MAX_WTS
        },
        {
         &( tp_can0_send_xfr[TP_CHN11_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN11_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN11_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN11_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN11_INDEX] ),
         TP_CHN11_INDEX,
         &( tp_can0_recv_xfr[TP_CHN11_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN11_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN11_INDEX] ),
         TP_CAN0_CHN11_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN11_INDEX] ),
         tp_can0_fcf_data[TP_CHN11_INDEX],
         TP_CAN0_CHN11_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN11_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN11_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN11_INDEX] ),
         TP_CAN0_CHN11_MAX_WTS,
         TP_CAN0_CHN11_IGNORE_MAX_WTS
         },
         {
         &( tp_can0_send_xfr[TP_CHN12_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN12_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN12_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN12_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN12_INDEX] ),
         TP_CHN12_INDEX,
         &( tp_can0_recv_xfr[TP_CHN12_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN12_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN12_INDEX] ),
         TP_CAN0_CHN12_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN12_INDEX] ),
         tp_can0_fcf_data[TP_CHN12_INDEX],
         TP_CAN0_CHN12_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN12_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN12_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN12_INDEX] ),
         TP_CAN0_CHN12_MAX_WTS,
         TP_CAN0_CHN12_IGNORE_MAX_WTS
         },
         {
         &( tp_can0_send_xfr[TP_CHN13_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN13_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN13_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN13_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN13_INDEX] ),
         TP_CHN13_INDEX,
         &( tp_can0_recv_xfr[TP_CHN13_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN13_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN13_INDEX] ),
         TP_CAN0_CHN13_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN13_INDEX] ),
         tp_can0_fcf_data[TP_CHN13_INDEX],
         TP_CAN0_CHN13_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN13_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN13_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN13_INDEX] ),
         TP_CAN0_CHN13_MAX_WTS,
         TP_CAN0_CHN13_IGNORE_MAX_WTS
         },
         {
         &( tp_can0_send_xfr[TP_CHN14_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN14_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN14_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN14_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN14_INDEX] ),
         TP_CHN14_INDEX,
         &( tp_can0_recv_xfr[TP_CHN14_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN14_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN14_INDEX] ),
         TP_CAN0_CHN14_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN14_INDEX] ),
         tp_can0_fcf_data[TP_CHN14_INDEX],
         TP_CAN0_CHN14_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN14_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN14_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN14_INDEX] ),
         TP_CAN0_CHN14_MAX_WTS,
         TP_CAN0_CHN14_IGNORE_MAX_WTS
         },
         {
         &( tp_can0_send_xfr[TP_CHN15_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN15_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN15_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN15_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN15_INDEX] ),
         TP_CHN15_INDEX,
         &( tp_can0_recv_xfr[TP_CHN15_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN15_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN15_INDEX] ),
         TP_CAN0_CHN15_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN15_INDEX] ),
         tp_can0_fcf_data[TP_CHN15_INDEX],
         TP_CAN0_CHN15_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN15_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN15_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN15_INDEX] ),
         TP_CAN0_CHN15_MAX_WTS,
         TP_CAN0_CHN15_IGNORE_MAX_WTS
         },
         {
         &( tp_can0_send_xfr[TP_CHN16_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN16_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN16_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN16_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN16_INDEX] ),
         TP_CHN16_INDEX,
         &( tp_can0_recv_xfr[TP_CHN16_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN16_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN16_INDEX] ),
         TP_CAN0_CHN16_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN16_INDEX] ),
         tp_can0_fcf_data[TP_CHN16_INDEX],
         TP_CAN0_CHN16_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN16_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN16_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN16_INDEX] ),
         TP_CAN0_CHN16_MAX_WTS,
         TP_CAN0_CHN16_IGNORE_MAX_WTS
         },
         {
         &( tp_can0_send_xfr[TP_CHN17_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN17_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN17_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN17_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN17_INDEX] ),
         TP_CHN17_INDEX,
         &( tp_can0_recv_xfr[TP_CHN17_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN17_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN17_INDEX] ),
         TP_CAN0_CHN17_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN17_INDEX] ),
         tp_can0_fcf_data[TP_CHN17_INDEX],
         TP_CAN0_CHN17_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN17_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN17_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN17_INDEX] ),
         TP_CAN0_CHN17_MAX_WTS,
         TP_CAN0_CHN17_IGNORE_MAX_WTS
         },
         {
         &( tp_can0_send_xfr[TP_CHN18_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN18_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN18_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN18_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN18_INDEX] ),
         TP_CHN18_INDEX,
         &( tp_can0_recv_xfr[TP_CHN18_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN18_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN18_INDEX] ),
         TP_CAN0_CHN18_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN18_INDEX] ),
         tp_can0_fcf_data[TP_CHN18_INDEX],
         TP_CAN0_CHN18_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN18_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN18_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN18_INDEX] ),
         TP_CAN0_CHN18_MAX_WTS,
         TP_CAN0_CHN18_IGNORE_MAX_WTS
         },
         {
         &( tp_can0_send_xfr[TP_CHN19_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN19_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN19_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN19_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN19_INDEX] ),
         TP_CHN19_INDEX,
         &( tp_can0_recv_xfr[TP_CHN19_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN19_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN19_INDEX] ),
         TP_CAN0_CHN19_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN19_INDEX] ),
         tp_can0_fcf_data[TP_CHN19_INDEX],
         TP_CAN0_CHN19_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN19_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN19_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN19_INDEX] ),
         TP_CAN0_CHN19_MAX_WTS,
         TP_CAN0_CHN19_IGNORE_MAX_WTS
         },
         {
        &( tp_can0_send_xfr[TP_CHN20_INDEX] ),
        &( tp_can0_send_xfr_fcf[TP_CHN20_INDEX] ),
        &( tp_can0_send_tmd[TP_CHN20_INDEX] ),
        tp_can0_sf_ff_cf_data[TP_CHN20_INDEX],
        &( tp_can0_send_ref_tmd[TP_CHN20_INDEX] ),
        TP_CHN20_INDEX,
        &( tp_can0_recv_xfr[TP_CHN20_INDEX] ),
        tp_can0_recv_xfr_sfffcf[TP_CHN20_INDEX],
        &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN20_INDEX] ),
        TP_CAN0_CHN20_RECV_XFR_QUEUE_SIZE,
        &( tp_can0_fcf_tmd[TP_CHN20_INDEX] ),
        tp_can0_fcf_data[TP_CHN20_INDEX],
        TP_CAN0_CHN20_NUM_RECV_CAN_IDS,
        tp_can0_recv_can_id[TP_CHN20_INDEX],
        &( tp_can0_recv_can_id_index[TP_CHN20_INDEX] ),
        &( tp_can0_recv_pkt_info[TP_CHN20_INDEX] ),
        TP_CAN0_CHN20_MAX_WTS,
        TP_CAN0_CHN20_IGNORE_MAX_WTS
        },
        {
         &( tp_can0_send_xfr[TP_CHN21_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN21_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN21_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN21_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN21_INDEX] ),
         TP_CHN21_INDEX,
         &( tp_can0_recv_xfr[TP_CHN21_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN21_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN21_INDEX] ),
         TP_CAN0_CHN21_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN21_INDEX] ),
         tp_can0_fcf_data[TP_CHN21_INDEX],
         TP_CAN0_CHN21_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN21_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN21_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN21_INDEX] ),
         TP_CAN0_CHN21_MAX_WTS,
         TP_CAN0_CHN21_IGNORE_MAX_WTS
         },
         {
         &( tp_can0_send_xfr[TP_CHN22_INDEX] ),
         &( tp_can0_send_xfr_fcf[TP_CHN22_INDEX] ),
         &( tp_can0_send_tmd[TP_CHN22_INDEX] ),
         tp_can0_sf_ff_cf_data[TP_CHN22_INDEX],
         &( tp_can0_send_ref_tmd[TP_CHN22_INDEX] ),
         TP_CHN22_INDEX,
         &( tp_can0_recv_xfr[TP_CHN22_INDEX] ),
         tp_can0_recv_xfr_sfffcf[TP_CHN22_INDEX],
         &( tp_can0_recv_xfr_sfffcf_q_cnt[TP_CHN22_INDEX] ),
         TP_CAN0_CHN22_RECV_XFR_QUEUE_SIZE,
         &( tp_can0_fcf_tmd[TP_CHN22_INDEX] ),
         tp_can0_fcf_data[TP_CHN22_INDEX],
         TP_CAN0_CHN22_NUM_RECV_CAN_IDS,
         tp_can0_recv_can_id[TP_CHN22_INDEX],
         &( tp_can0_recv_can_id_index[TP_CHN22_INDEX] ),
         &( tp_can0_recv_pkt_info[TP_CHN22_INDEX] ),
         TP_CAN0_CHN22_MAX_WTS,
         TP_CAN0_CHN22_IGNORE_MAX_WTS
         },
    };

/*------------------------------------------------------
TP CAN Hardware Instance Channel Info
------------------------------------------------------*/
tp_hw_inst_info_t   const
tp_hw_inst_info[CAN_NUM_INSTANCES] =
    {
        {
        TP_CAN0_NUM_CHANNELS,
        tp_can0_chan_info
        }
    };

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
static void
process_receive_complete_events
    (
    tp_chan_index_t             const ch_index,
    can_hw_inst_t               const hw_inst
    );

static void
process_send_sf_ff_cf_tx_complete_event
    (
    tp_chan_info_t      const * const p_tp_chan_info,
    tp_chan_index_t             const ch_index,
    can_hw_inst_t               const hw_inst
    );

static void
process_send_fcf_rx_complete_event
    (
    tp_chan_info_t      const * const p_tp_chan_info,
    tp_n_frame_t                const frame_type,
    can_rmd_t           const * const p_rmd,
    tp_chan_index_t             const ch_index,
    can_hw_inst_t               const hw_inst
    );

static void
process_send_tick_event
    (
    tp_chan_index_t             const ch_index,
    can_hw_inst_t               const hw_inst
    );

static void
process_send_timeout_event
    (
    tp_chan_info_t      const * const p_tp_chan_info,
    tp_chan_index_t             const ch_index,
    can_hw_inst_t               const hw_inst
    );

static void
process_receive_fcf_tx_complete_event
    (
    tp_chan_info_t      const * const p_tp_chan_info,
    tp_chan_index_t             const ch_index,
    can_hw_inst_t               const hw_inst
    );

static void
process_receive_sf_ff_cf_rx_complete_event
    (
    tp_chan_info_t      const * const p_tp_chan_info,
    tp_n_frame_t                const frame_type,
    can_rmd_t           const * const p_rmd,
    tp_chan_index_t             const ch_index,
    can_hw_inst_t               const hw_inst
    );

static TP_RC
check_cf_sequence_number
    (
    tp_chan_info_t      const * const p_tp_chan_info,
    uint8                       const pci_byte,
    tp_chan_index_t             const ch_index,
    can_hw_inst_t               const hw_inst
    );

static void
process_receive_tick_event
    (
    tp_chan_index_t             const ch_index,
    can_hw_inst_t               const hw_inst
    );

static void
process_receive_timeout_event
    (
    tp_chan_info_t      const * const p_tp_chan_info,
    tp_chan_index_t             const ch_index,
    can_hw_inst_t               const hw_inst
    );

static void
schedule_send_cf_transmit
    (
    tp_chan_info_t      const * const p_tp_chan_info,
    uint16                    * const p_timer,
    uint8                       const st_min
    );

static void
schedule_transfer_timeout
    (
    uint16                      const timeout_ms,
    uint16                    * const p_timer
    );

static void
cancel_transfer_timeout
    (
    uint16                    * const p_timer
    );

static void
process_send_transfer_complete
    (
    tp_chan_info_t      const * const p_tp_chan_info,
    tp_n_result_t               const result,
    tp_chan_index_t             const ch_index,
    can_hw_inst_t               const hw_inst
    );

static void
process_receive_transfer_complete
    (
    tp_chan_info_t      const * const p_tp_chan_info,
    uint8               const * const p_data,
    uint16                      const num_bytes,
    tp_n_result_t               const result,
    tp_chan_index_t             const ch_index,
    can_hw_inst_t               const hw_inst
    );

/*!*******************************************************************
*
* @public
* initialize the Transport Protocol Layer
*
* This function performs start up initialization of the Transport
* Protocol Layer for the specified CAN hardware instance.
*
*********************************************************************/
void tp_init
    (
    can_hw_inst_t       const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_chan_info_t  const * l_p_tp_chan_info;
uint8                   l_num_ch;
uint8                   l_ch_index;

/*------------------------------------------------------
Get the number of channels for this hardware instance
and initialize all of the channels. This includes
initialization of all of the channel state and status
information.
------------------------------------------------------*/
l_num_ch = tp_hw_inst_info[hw_inst].num_channels;

for( l_ch_index = 0; l_ch_index < l_num_ch; l_ch_index++ )
    {
    /*------------------------------------------------------
    Get ptr to TP channel info for this index.
    ------------------------------------------------------*/
    l_p_tp_chan_info = &( tp_hw_inst_info[hw_inst].p_tp_chan_info[l_ch_index] );

    /*------------------------------------------------------
    First zero init all the Send and Receive transfer data.
    ------------------------------------------------------*/
    (void) memset( l_p_tp_chan_info->p_send_xfr, 0, sizeof( tp_n_send_xfr_t ) );
    (void) memset( l_p_tp_chan_info->p_recv_xfr, 0, sizeof( tp_n_recv_xfr_t ) );

    /*------------------------------------------------------
    Initialize the Send and Receive transmit timeouts and
    Flow Control STmin and Block Size parameter values.
    ------------------------------------------------------*/
    l_p_tp_chan_info->p_send_xfr->n_as_timeout = TP_N_As;
    l_p_tp_chan_info->p_recv_xfr->n_ar_timeout = TP_N_Ar;
    l_p_tp_chan_info->p_recv_xfr->st_min       = TP_N_STMIN_DEFAULT;
    l_p_tp_chan_info->p_recv_xfr->block_size   = TP_N_BLOCKSIZE_DEFAULT;

    /*------------------------------------------------------
    Initialize the Receive queue count.
    ------------------------------------------------------*/
    *( l_p_tp_chan_info->p_recv_xfr_sfffcf_q_cnt ) = 0;
    }
}

/*!*******************************************************************
*
* @public
* periodic Transport Protocol task
*
* This function is the periodic Transport Protocol task that must be
* called for each active CAN hardware instance. This task manages
* timeouts as well as any pending frame reception or transmit
* complete notifications.
*
*********************************************************************/
#if(CANTP_DEBUG == TRUE)
uint16 g_global_runtime = 0;
#endif
void tp_task
    (
    can_hw_inst_t       const hw_inst           //!< [in] CAN hardware instance
    )
{
uint8   l_num_ch;
uint8   l_ch_index;

 #if(CANTP_DEBUG == TRUE)
    g_global_runtime ++;
if( g_global_runtime >= 0xFFFFFFF0)
    {
    g_global_runtime = 0;
    }
#endif

/*------------------------------------------------------
Get the number of TP channels for this CAN hardware
instance and service all the channel events.
------------------------------------------------------*/
l_num_ch = tp_hw_inst_info[hw_inst].num_channels;

for( l_ch_index = 0; l_ch_index < l_num_ch; l_ch_index++ )
    {
    /*------------------------------------------------------
    Check for and process any Send or Receive transfer
    frame reception events.
    ------------------------------------------------------*/
    process_receive_complete_events( l_ch_index, hw_inst );

    /*------------------------------------------------------
    Update Send and Receive timers and process timer events.
    ------------------------------------------------------*/
    process_send_tick_event( l_ch_index, hw_inst );
    process_receive_tick_event( l_ch_index, hw_inst );
    }
}

/*!*******************************************************************
*
* @public
* transmit a Transport Protocol message
*
* This function is called to initiate the transfer of a data packet
* using the Transport Protocol. Note that if this function is called
* while a segmented transfer is already in progress, this function
* call will disrupt the transfer in progress and start a new transfer.
*
*********************************************************************/
void tp_transmit
    (
    uint8       const * const p_tp_data,        //!< [in] ptr to TP data to send
    uint16              const num_tp_bytes,     //!< [in] number of bytes to send
    tp_chan_index_t     const ch_index,         //!< [in] TP channel index
    can_hw_inst_t       const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_chan_info_t  const * l_p_tp_chan_info;
tp_n_send_xfr_t       * l_p_send_xfr;
can_tmd_t             * l_p_tmd;
uint8                 * l_p_tmd_data;
uint8                   l_num_ch;

uint8 temp;
const uint8 standard_send_length = 8;
/*------------------------------------------------------
Get the number of TP channels for this hardware instance
and the pointer to the TP channel info and check if
they are valid.
------------------------------------------------------*/
l_num_ch = tp_hw_inst_info[hw_inst].num_channels;
l_p_tp_chan_info = &( tp_hw_inst_info[hw_inst].p_tp_chan_info[ch_index] );

if( ( l_p_tp_chan_info != NULL )    &&
    ( l_num_ch != 0 ) )
    {
    /*------------------------------------------------------
    Initialize the send transfer information for this
    channel, including the status, the pointer to the frame
    data and the CAN Transmit Data structure.
    ------------------------------------------------------*/
    l_p_send_xfr = l_p_tp_chan_info->p_send_xfr;
    l_p_send_xfr->status = 0;

    l_p_tmd  = l_p_tp_chan_info->p_send_tmd;
    *l_p_tmd = *( l_p_tp_chan_info->p_send_ref_tmd );
    l_p_tmd_data = l_p_tp_chan_info->p_send_tmd_data;

    /*------------------------------------------------------
    Schedule the transmit timeout. Determine, depending on
    the size of the transferred data, whether the data can
    all be sent in a single TP or if multiple segmented
    frames are required to send all the data.
    ------------------------------------------------------*/
    schedule_transfer_timeout( l_p_send_xfr->n_as_timeout, &( l_p_send_xfr->timer ) );

    if( num_tp_bytes > TP_SF_MAX_DATA_BYTES )
        {
        /*------------------------------------------------------
        Initialize for a segmented transfer. The First Frame is
        sent first.
        ------------------------------------------------------*/
        l_p_send_xfr->p_data    = p_tp_data;
        l_p_send_xfr->num_total = num_tp_bytes;
        l_p_send_xfr->num_wtfcf_rcvd = l_p_tp_chan_info->wts_max;

        /*------------------------------------------------------
        Set the First Frame PCI for frame type and data size and
        load the First Frame data (6 bytes).
        ------------------------------------------------------*/
        l_p_tmd_data[0] = (uint8) ( TP_NP_FF_PCI | ( TP_GPNUM_0F & ( num_tp_bytes >> TP_GPNUM_8 ) ) );
        l_p_tmd_data[1] = (uint8) num_tp_bytes;
        (void) memcpy( &( l_p_tmd_data[TP_GPNUM_2] ), p_tp_data, TP_GPNUM_6 );

        /*------------------------------------------------------
        Next state waits for FF transmit completion.
        ------------------------------------------------------*/
        l_p_send_xfr->state = TP_NS_SEND_WFFTXC;
        }
    else
        {
        /*------------------------------------------------------
        The data fits into a Single Frame. Set the SF PCI and
        data size and load the data.
        ------------------------------------------------------*/
        l_p_tmd_data[0] = TP_NP_SF_PCI | ( ( ( tp_n_pci_t) num_tp_bytes ) & TP_GPNUM_0F );
        (void) memcpy( &( l_p_tmd_data[1] ), p_tp_data, num_tp_bytes );
        /*data pending in transport layer*/
        for( temp = (uint8)( num_tp_bytes + 1); temp < standard_send_length; temp++ )
            {
            l_p_tmd_data[temp] = 0x55;
            }
        l_p_tmd->dlc = standard_send_length;

        /*------------------------------------------------------
        Next state waits for SF transmit completion.
        ------------------------------------------------------*/
        l_p_send_xfr->state = TP_NS_SEND_WSFTXC;
        }

    /*------------------------------------------------------
    Transmit the starting frame (SF or FF). The return value
    is ignored. If the CAN driver is not able to transmit
    the frame, the timeout waiting for transmit completion
    will become set.
    ------------------------------------------------------*/
    /*TEMP_TEST*/
    //PRINTF("tp transmit send:%x\r\n",l_p_tmd->identifier);
    //PRINTF("%x,%x,%x\r\n",l_p_tmd->p_data[0],l_p_tmd->p_data[1],l_p_tmd->p_data[2]);
    (void)can_transmit( hw_inst, l_p_tmd );
    }
}


static uint8 send_data[8] = {0};
static can_tmd_t send_tmd = {0};
void tp_transmit_direct
(
   uint8       const * const p_tp_data,        //!< [in] ptr to TP data to send
   uint16              const num_tp_bytes,     //!< [in] number of bytes to send
   tp_chan_index_t     const ch_index,         //!< [in] TP channel index
   can_hw_inst_t       const hw_inst           //!< [in] CAN hardware instance
   )
{
tp_chan_info_t  const * l_p_tp_chan_info;
uint8                   l_num_ch;

uint8 temp;
const uint8 standard_send_length = 8;
/*------------------------------------------------------
Get the number of TP channels for this hardware instance
and the pointer to the TP channel info and check if
they are valid.
------------------------------------------------------*/
l_num_ch = tp_hw_inst_info[hw_inst].num_channels;
l_p_tp_chan_info = &( tp_hw_inst_info[hw_inst].p_tp_chan_info[ch_index] );

if( ( l_p_tp_chan_info != NULL )    &&
    ( l_num_ch != 0 ) )
    {
    send_tmd.p_data = send_data;
    send_tmd.identifier = tp_hw_inst_info[hw_inst].p_tp_chan_info[ch_index].p_send_ref_tmd->identifier;
    send_data[0] = TP_NP_SF_PCI | ( ( ( tp_n_pci_t) num_tp_bytes ) & TP_GPNUM_0F );
    (void) memcpy( &( send_data[1] ), p_tp_data, num_tp_bytes );
    /*data pending in transport layer*/
    for( temp = (uint8)( num_tp_bytes + 1); temp < standard_send_length; temp++ )
        {
        send_data[temp] = 0x55;
        }
    send_tmd.dlc = standard_send_length;
    (void)can_transmit( hw_inst, &send_tmd );
    }
}


/*!*******************************************************************
*
* @public
* send CF timer interrupt handler
*
* This function is called by the CAN services routine to notify the
* TP layer that a timer event has occurred that allows for precise
* scheduling of Consecutive Frame transmissions to meet accurate
* STmin inter-frame interval control requirements.
*
*********************************************************************/
void tp_cf_send_timer_event
    (
   uint8            const tp_send_cf_index      //!< [in] tp channel send CF timer index
    )
{
tp_chan_info_t  const * l_p_tp_chan_info;
tp_chan_index_t         l_chan_index;
can_hw_inst_t           l_hw_inst;
boolean                 l_valid_timer_index;

/*------------------------------------------------------
Initially assume a valid timer index that corresponds to
a valid TP channel. Determine the CAN hardware instance
and the TP channel associated with the send CF timer
interrupt.
------------------------------------------------------*/
l_hw_inst           = 0;
l_chan_index        = 0;
l_valid_timer_index = TRUE;

if( tp_send_cf_index < TP_CAN0_NUM_CHANNELS )
    {
    l_chan_index = tp_send_cf_index;
    }
#if( CAN_NUM_INSTANCES > 1 )
else if ( tp_send_cf_index < TP_CAN1_NUM_CHANNELS )
    {
    l_hw_inst    = 1;
    l_chan_index = tp_send_cf_index - TP_CAN0_NUM_CHANNELS;
    }
#endif
else
    {
    l_valid_timer_index = FALSE;
    }

if( l_valid_timer_index != FALSE )
    {
    l_p_tp_chan_info = &( tp_hw_inst_info[l_hw_inst].p_tp_chan_info[l_chan_index] ) ;
    process_send_timeout_event( l_p_tp_chan_info, l_chan_index, l_hw_inst );
    }
}

/*!*******************************************************************
*
* @public
* change TP channel parameter
*
* This function is called to request a change to a TP channel
* parameter value.
*
* @return tp_n_chng_result_t
* change result code
*
*********************************************************************/
tp_n_chng_result_t
tp_change_parameter
    (
    tp_n_param_t        const param,            //!< [in] parameter to change
    uint16              const param_value,      //!< [in] parameter value
    tp_chan_index_t     const ch_index,         //!< [in] TP channel index
    can_hw_inst_t       const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_chan_info_t  const * l_p_tp_chan_info;
tp_n_recv_xfr_t       * l_p_recv_xfr;
tp_n_chng_result_t      l_result;
uint8                   l_num_ch;

/*------------------------------------------------------
Initialize the returned result.
------------------------------------------------------*/
l_result = TP_NC_OK;

/*------------------------------------------------------
Get the number of TP channels for this hardware instance
and the pointer to the TP channel info and check if
they are valid.
------------------------------------------------------*/
l_num_ch = tp_hw_inst_info[hw_inst].num_channels;
l_p_tp_chan_info = &( tp_hw_inst_info[hw_inst].p_tp_chan_info[ch_index] ) ;

if( ( l_p_tp_chan_info != NULL )    &&
    ( l_num_ch != 0 ) )
    {
    /*------------------------------------------------------
    Get the pointer to the Receive transfer info.
    ------------------------------------------------------*/
    l_p_recv_xfr = l_p_tp_chan_info->p_recv_xfr;

    /*------------------------------------------------------
    Service the requested parameter change.
    ------------------------------------------------------*/
    switch( param )
        {
        case TP_NP_STMIN:
            /*------------------------------------------------------
            The STmin parameter is associated with the TP receive
            packet process and is sent in a Flow Control Frame to
            the transmitter when receiving a TP packet. This
            parameter specifies the time between transmitted frames
            that must be used by the transmitter of the packet.
            Check that the specified STmin value is range.
            ------------------------------------------------------*/
            if( param_value < (uint16) TP_GPNUM_FF )
                {
                l_p_recv_xfr->st_min = (uint8) param_value;
                }
            else
                {
                l_result = TP_NC_WRONG_VALUE;
                }
            break;

        case TP_NP_BLOCKSIZE:
            /*------------------------------------------------------
            The BS (Block Size) value is associated with the TP
            receive packet process and is sent in a Flow Control
            frame to the transmitter when receiving a TP packet.
            This parameter specifies the maximum number of frames
            the transmitter can send before it needs to wait for
            reception of another Flow Control Frame before
            continuing its transmission. Check that the specified
            STmin value is range.
            ------------------------------------------------------*/
            if( param_value < TP_GPNUM_FF )
                {
                l_p_recv_xfr->block_size = param_value;
                }
            else
                {
                l_result = TP_NC_WRONG_VALUE;
                }
            break;

        case TP_NP_RCV_SUSPEND:
            /*------------------------------------------------------
            This request causes a receiver to send WTS (Wait To
            Send) Flow Control Frames to the transmitter to force
            the transmitter to wait until it receives a CTS
            (Clear To Send) Flow Control Frame that allows the
            transmitter to continue its transmission. Check that
            the specified channel is not currently suspended.
            ------------------------------------------------------*/
            if( l_p_recv_xfr->state != TP_NS_RECV_SUSPEND )
                {
                l_p_recv_xfr->status |= TP_NB_RECV_SUSPEND_PNDG;
                }
            else
                {
                l_result = TP_NC_WRONG_PARAMETER;
                }
            break;

        case TP_NP_RCV_RESUME:
            /*------------------------------------------------------
            This request causes a receiver to send a CTS (Clear To
            Send) Flow Control Frame to the transmitter to allow
            the transmitter to resume its data transmission. Check
            that the specified receive channel is currently
            suspended.
            ------------------------------------------------------*/
            if( TP_NS_RECV_SUSPEND == l_p_recv_xfr->state  )
                {
                l_p_recv_xfr->status |= TP_NB_RECV_RESUME_PNDG;
                }
            else
                {
                l_result = TP_NC_WRONG_PARAMETER;
                }
            break;

        default:
            l_result = TP_NC_WRONG_PARAMETER;
            break;
        }
    }

return l_result ;
}

/*!*******************************************************************
*
* @private
* notification callback for TP frame transmit completion
*
* This function is a callback from the CAN stack Dispatch layer to
* notify the Transport Protocol layer that a TP CAN frame
* transmission has completed.
*
*********************************************************************/
void tp_hook_transmit
    (
    can_tmh_t           const tmh,              //!< [in] transmit message handle
    can_hw_inst_t       const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_chan_info_t  const * l_p_tp_chan_info;
can_tmh_t               l_tmh_offset;
uint8                   l_num_ch;
tp_chan_index_t         l_ch_index;

/*------------------------------------------------------
Determine the Transmit Message Handle offset from the
base value for TP transmissions and check that it is in
range. Assuming a valid value, determine the Channel
Index and the Frame Type (Data or Flow Control Frame)
from the l_tmh_offset. With the format for assigning
frame ID's in this implementation, the channel index is
simply the l_tmh_offset value divided by 2, and the
Frame Type is determined by whether the l_tmh_offset is
EVEN (Data Frame) or ODD (Flow Control Frame).

Note that the Send state machine only needs to know
that a Data frame (SF, FF, or CF) transmission has
completed and the Receive state machine only needs to
know that a Flow Control (FC) frame transmission has
completed.
------------------------------------------------------*/

/*------------------------------------------------------
Extract the transmitted frame handle offset from the
transmit message handle and use that to determine the
TP channel index. Get the number of TP channels for this
hardware instance and make sure the index is consistent
with the number of defined TP channels.
------------------------------------------------------*/
l_tmh_offset = DLL_GET_INDEX_FROM_FRAME_HANDLE( tmh );
l_ch_index   = l_tmh_offset >> 1;

l_num_ch = tp_hw_inst_info[hw_inst].num_channels;

if( l_ch_index < l_num_ch )
    {
    /*------------------------------------------------------
    Get the pointer to the TP channel info.
    ------------------------------------------------------*/
    l_p_tp_chan_info = &( tp_hw_inst_info[hw_inst].p_tp_chan_info[l_ch_index] );

    if( ( l_tmh_offset & ( (can_tmh_t) 0x1u ) ) != 0 )
        {
        /*------------------------------------------------------
        Process the receive FCF transmit complete event.
        ------------------------------------------------------*/
        process_receive_fcf_tx_complete_event( l_p_tp_chan_info, l_ch_index, hw_inst );
        }
    else
        {
        /*------------------------------------------------------
        Process the send SF, FF or CF transmit complete event.
        ------------------------------------------------------*/
        process_send_sf_ff_cf_tx_complete_event( l_p_tp_chan_info, l_ch_index, hw_inst );
        }
    }
}

/*!*******************************************************************
*
* @private
* notification callback for TP frame transmit timeout
*
* This function is a callback from the CAN stack Dispatch layer to
* notify the Transport Protocol layer that a TP CAN frame
* transmission has timed out. This function stops any transfer in
* progress in which a transmit timeout occurs.
*
*********************************************************************/
void tp_hook_transmit_timeout
    (
    can_tmh_t               const tmh,
    can_hw_inst_t           const hw_inst
    )
{
tp_chan_info_t  const * l_p_tp_chan_info;
can_tmh_t               l_tmh_offset;
uint8                   l_num_ch;
tp_chan_index_t         l_ch_index;

/*------------------------------------------------------
Extract the transmitted frame handle offset from the
transmit message handle and use that to determine the
TP channel index. Get the number of TP channels for this
hardware instance and make sure the index is consistent
with the number of defined TP channels.
------------------------------------------------------*/
l_tmh_offset = DLL_GET_INDEX_FROM_FRAME_HANDLE( tmh );
l_ch_index   = l_tmh_offset >> 1;
l_num_ch     = tp_hw_inst_info[hw_inst].num_channels;

if( l_ch_index < l_num_ch )
    {
    /*------------------------------------------------------
    Get the pointer to the TP channel info.
    ------------------------------------------------------*/
    l_p_tp_chan_info = &( tp_hw_inst_info[hw_inst].p_tp_chan_info[l_ch_index] );

    if( ( l_tmh_offset & ( (can_tmh_t) 0x1u ) ) != 0 )
        {
        /*------------------------------------------------------
        Stop the receive transfer and notify the error.
        ------------------------------------------------------*/
        process_receive_transfer_complete( l_p_tp_chan_info, NULL, 0, TP_N_TIMEOUT_A, l_ch_index, hw_inst );
        }
    else
        {
        /*------------------------------------------------------
        Stop the send transfer and notify the error.
        ------------------------------------------------------*/
        process_send_transfer_complete( l_p_tp_chan_info, TP_N_TIMEOUT_A, l_ch_index, hw_inst );
        }
    }
}

/*!*******************************************************************
*
* @private
* notification callback for TP frame reception
*
* This function is a callback from the CAN stack Dispatch layer to
* notify the Transport Protocol layer that a TP CAN frame reception
* has completed.
*
*********************************************************************/
void tp_hook_receive
    (
    can_rmd_t   const * const p_rmd,            //!< [in] ptr to received frame
    can_hw_inst_t       const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_chan_info_t  const * l_p_tp_chan_info;
uint8                   l_num_ch;
tp_n_send_xfr_t       * l_p_send_xfr;
tp_n_recv_xfr_t       * l_p_recv_xfr;
tp_n_store_frame_t    * l_p_store_frame;
uint8                 * l_p_queue_count;
uint8                   l_queue_size;
tp_chan_index_t         l_ch_index;
uint8                   l_ch_can_id;
tp_n_frame_t            l_frame_type;
tp_n_pci_t              l_pci_byte;
tp_n_pci_t              l_pci_msnibble;
boolean                 l_ch_match;


//uint32 rx_id = p_rmd->identifier;
/*------------------------------------------------------
Initialize the channel match and channel index values.
------------------------------------------------------*/
l_ch_match = FALSE;
l_p_tp_chan_info = NULL;

/*------------------------------------------------------
Get the number of TP channels for this H/W instance.
------------------------------------------------------*/
l_num_ch = tp_hw_inst_info[hw_inst].num_channels;

/*------------------------------------------------------
Initialize the channel index and search the TP channel
information for this CAN Hardware index for a match.
------------------------------------------------------*/
for( l_ch_index = 0;
     ( ( l_ch_index < l_num_ch ) && ( FALSE == l_ch_match ) );
     l_ch_index++ )
    {
    l_p_tp_chan_info = &( tp_hw_inst_info[hw_inst].p_tp_chan_info[l_ch_index] );

    for( l_ch_can_id = 0;
         ( ( l_ch_can_id < l_p_tp_chan_info->num_recv_canids ) &&  ( FALSE == l_ch_match ) );
         l_ch_can_id++ )
        {
        if( p_rmd->identifier == l_p_tp_chan_info->p_recv_canid[l_ch_can_id] )
            {
            /*------------------------------------------------------
            Save the qualifying CAN ID index for this channel.
            ------------------------------------------------------*/
            *( l_p_tp_chan_info->p_recv_canid_index ) = l_ch_can_id;
            l_ch_match = TRUE;
            }
        }
    }

/*------------------------------------------------------
Check for a valid TP channel id
------------------------------------------------------*/
if( ( l_ch_match != FALSE ) &&
    ( l_p_tp_chan_info != NULL ) )
    {
    /*------------------------------------------------------
    Get the PCI byte and the msnibble of the PCI byte to
    determine the TP frame type.
    ------------------------------------------------------*/
    l_pci_byte     = p_rmd->data[0];
    l_pci_msnibble = l_pci_byte & TP_GPNUM_F0;

    if( l_pci_msnibble == TP_NP_SF_PCI )
        {
        l_frame_type = TP_NF_SF;
        }
    else if( l_pci_msnibble == TP_NP_FF_PCI )
        {
        l_frame_type = TP_NF_FF;
        }
    else if( l_pci_msnibble == TP_NP_CF_PCI )
        {
        l_frame_type = TP_NF_CF;
        }
    else if( l_pci_byte == TP_NP_FCF_CTS_PCI )
        {
        l_frame_type = TP_NF_FCF_CTS;
        }
    else if( l_pci_byte == TP_NP_FCF_WTS_PCI )
        {
        l_frame_type = TP_NF_FCF_WTS;
        }
    else if( l_pci_byte == TP_NP_FCF_OVFLW_PCI )
        {
        l_frame_type = TP_NF_FCF_OVFLW;
        }
    else
        {
        l_frame_type = TP_NF_UNDEFINED;
        }

    /*------------------------------------------------------
    Check for data frame (SF, FF or CF) received.
    ------------------------------------------------------*/
    if( ( TP_NF_SF == l_frame_type )    ||
        ( TP_NF_FF == l_frame_type )    ||
        ( TP_NF_CF == l_frame_type ) )
        {
        /*------------------------------------------------------
        Get the Receive transfer information for this channel and
        check for an available slot in the frame receive queue.
        ------------------------------------------------------*/
        l_p_recv_xfr    = l_p_tp_chan_info->p_recv_xfr;
        l_p_queue_count = l_p_tp_chan_info->p_recv_xfr_sfffcf_q_cnt;/*p_recv_xfr_sfffcf_q_cnt always be 0*/
        l_queue_size    = l_p_tp_chan_info->recv_xfr_sfffcf_q_size;/*always be 10*/

        if( *( l_p_queue_count ) < l_queue_size )
            {
            /*------------------------------------------------------
            Store the frame and set the data received status bit.
            ------------------------------------------------------*/
            l_p_store_frame = &( l_p_tp_chan_info->p_recv_xfr_sfffcf[*( l_p_queue_count )] );/*A buffer with lenth equal 10*/
            l_p_store_frame->rmd = *( p_rmd );
            l_p_store_frame->frame_type = l_frame_type;
            (*l_p_queue_count) += 1;
            l_p_recv_xfr->status |= TP_NB_RECV_SFFFCF_RXC_PNDG;
            }
        else
            {
            /*------------------------------------------------------
            Store status indicating a received frame was lost. The
            receive frame queue should be sized sufficiently large
            such that this never happens as long as the periodic
            task runs reliably. Recover by clearing the queue
            count.
            ------------------------------------------------------*/
            l_p_recv_xfr->status |= TP_NB_RECV_FRAME_QUEUE_OVERFLOW;
            *l_p_queue_count = 0;
            }
        }

    /*------------------------------------------------------
    Check for Flow Control Frame received.
    ------------------------------------------------------*/
    else if( ( TP_NF_FCF_CTS   == l_frame_type )    ||
             ( TP_NF_FCF_WTS   == l_frame_type )    ||
             ( TP_NF_FCF_OVFLW == l_frame_type ) )
        {
        /*------------------------------------------------------
        Get the store pointer for the received Flow Control
        Frame and the frame type.
        ------------------------------------------------------*/
        l_p_store_frame = l_p_tp_chan_info->p_send_xfr_fcf;
        l_p_store_frame->rmd = *( p_rmd );
        l_p_store_frame->frame_type = l_frame_type;

        /*------------------------------------------------------
        Get the Send transfer information and set the flag for
        notification of a received Flow Control Frame.
        ------------------------------------------------------*/
        l_p_send_xfr = l_p_tp_chan_info->p_send_xfr;
        l_p_send_xfr->status |= TP_NB_SEND_FCF_RXC_PNDG;
        }
    else
        {
        /*------------------------------------------------------
        Invalid frame type, do nothing.
        ------------------------------------------------------*/
        ;
        }
    }
}

/*!*******************************************************************
*
* process send and receive transfer receive frame events.
*
* This function checks for and processes any pending frame receive
* events for both the send and receive transfers associated with a
* given TP channel.
*
*********************************************************************/
static void
process_receive_complete_events
    (
    tp_chan_index_t     const ch_index,         //!< [in] TP channel index
    can_hw_inst_t       const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_chan_info_t  const * l_p_tp_chan_info;
tp_n_send_xfr_t       * l_p_send_xfr;
tp_n_recv_xfr_t       * l_p_recv_xfr;
tp_n_store_frame_t    * l_p_store_frame;
can_rmd_t               l_rmd;
tp_n_frame_t            l_frame;
uint8                 * l_p_queue_count;
uint8                   l_q_index;

/*------------------------------------------------------
Get the pointer to the TP channel info.
------------------------------------------------------*/
l_p_tp_chan_info = &( tp_hw_inst_info[hw_inst].p_tp_chan_info[ch_index] );

/*------------------------------------------------------
Get the Send transfer information for this channel and
check the Flow Control Frame receive notification flag.
------------------------------------------------------*/
l_p_send_xfr = l_p_tp_chan_info->p_send_xfr;

if( ( l_p_send_xfr->status & TP_NB_SEND_FCF_RXC_PNDG ) != 0 )
    {
    /*------------------------------------------------------
    Get the received Flow Control Frame and the frame type
    and process it. Clear the receive pending flag.
    ------------------------------------------------------*/
    l_p_store_frame = l_p_tp_chan_info->p_send_xfr_fcf;
    l_rmd = l_p_store_frame->rmd;
    l_frame = l_p_store_frame->frame_type;

    process_send_fcf_rx_complete_event( l_p_tp_chan_info, l_frame, &l_rmd, ch_index, hw_inst );

    l_p_send_xfr->status &= ( TP_GPNUM_FF ^ TP_NB_SEND_FCF_RXC_PNDG );
    }

/*------------------------------------------------------
Get the Receive transfer information for this channel
and check the receive complete notification flag.
------------------------------------------------------*/
l_p_recv_xfr = l_p_tp_chan_info->p_recv_xfr;

if( ( l_p_recv_xfr->status & TP_NB_RECV_SFFFCF_RXC_PNDG ) != 0 )
    {
    /*------------------------------------------------------
    Get the receive queue count and initialize the queue
    index. The receive queue is a FIFO so take the first
    received frame out first.
    ------------------------------------------------------*/
    l_p_queue_count = l_p_tp_chan_info->p_recv_xfr_sfffcf_q_cnt;
    l_q_index = 0;

    do
        {
        /*------------------------------------------------------
        Get the next received SF, FF or CF frame and process it.
        Increment the queue index and decrement the count.
        ------------------------------------------------------*/
        l_p_store_frame = &( l_p_tp_chan_info->p_recv_xfr_sfffcf[l_q_index] );
        l_rmd = l_p_store_frame->rmd;
        l_frame = l_p_store_frame->frame_type;

        process_receive_sf_ff_cf_rx_complete_event( l_p_tp_chan_info, l_frame, &l_rmd, ch_index, hw_inst );

        l_q_index++;
        *l_p_queue_count -= 1;

        } while( *l_p_queue_count != 0 );

    /*------------------------------------------------------
    Clear the receive complete status flag.
    ------------------------------------------------------*/
    l_p_recv_xfr->status &= ( TP_GPNUM_FF ^ TP_NB_RECV_SFFFCF_RXC_PNDG );
    }
}


/*!*******************************************************************
*
* process TP data frame transmit completion
*
* This function processes successful transmit completion of a data
* frame (SF, FF or CF) from a TP channel.
*
*********************************************************************/
static void
process_send_sf_ff_cf_tx_complete_event
    (
    tp_chan_info_t  const * const p_tp_chan_info,   //!< [in] ptr to TP channel info
    tp_chan_index_t         const ch_index,         //!< [in] TP channel index
    can_hw_inst_t           const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_n_send_xfr_t   * l_p_send_xfr;
can_tmd_t         * l_p_tmd;
uint8             * l_p_tmd_data;
uint8               l_num_store;
uint16              l_num_bytes_unsent;

/*------------------------------------------------------
Get the Send state and status information for this
channel and process the data frame transmit completion
event according to the current send transfer state.
------------------------------------------------------*/
l_p_send_xfr = p_tp_chan_info->p_send_xfr;

switch( l_p_send_xfr->state )
    {
    case TP_NS_SEND_WSFTXC:
        /*------------------------------------------------------
        Single Frame transmission completes the transfer.
        ------------------------------------------------------*/
        process_send_transfer_complete( p_tp_chan_info, TP_N_OK, ch_index, hw_inst );
        break;

    case TP_NS_SEND_WFFTXC:
        /*------------------------------------------------------
        Process completion of the First Frame Transmission.
        Initialize the values for subsequent Consecutive Frame
        Transmissions.
        ------------------------------------------------------*/
        l_p_send_xfr->num_sent  = TP_FF_MAX_DATA_BYTES;
        l_p_send_xfr->seq_num   = 1;
        l_p_send_xfr->block_num = 0;

        /*------------------------------------------------------
        Allow update of STmin and BS in the next Flow Control
        Frame Clear To Send frame reception. Set state to wait
        for reception of the next Flow Control Frame. Schedule
        the timeout waiting for reception of the Flow Control
        Frame from the receiver.
        ------------------------------------------------------*/
        l_p_send_xfr->status |= TP_NB_SEND_OK_TO_UPDATE_BS_ST;
        l_p_send_xfr->state   = TP_NS_SEND_WFCFRX;
        schedule_transfer_timeout( TP_N_Bs, &( l_p_send_xfr->timer ) );
        break;

    case TP_NS_SEND_WCFTXC:
        /*------------------------------------------------------
        Process completion of Consecutive Frame Transmission.
        Check if all bytes in the packet have been sent.
        ------------------------------------------------------*/
        l_p_send_xfr->num_sent += TP_CF_MAX_DATA_BYTES;

        if( l_p_send_xfr->num_sent < l_p_send_xfr->num_total )
            {
            /*------------------------------------------------------
            More bytes to send, update the CF sequence number check
            for wraparound.
            ------------------------------------------------------*/
            l_p_send_xfr->seq_num++;

            if( l_p_send_xfr->seq_num > TP_CF_SN_MAX_VALUE )
                {
                l_p_send_xfr->seq_num = 0;
                }

            /*------------------------------------------------------
            Increment the Block Number and check for Block Size
            requirement set to 0 (transmit all data in one block) or
            that the Block Size specified by the receiver has been
            reached and another block needs to be sent.
            ------------------------------------------------------*/
            l_p_send_xfr->block_num++;

            if( ( l_p_send_xfr->block_size != 0 )    &&
                ( l_p_send_xfr->block_num  >= l_p_send_xfr->block_size ) )
                {
                /*------------------------------------------------------
                Complete block has been sent. Reset the Block Number,
                set the Send state to wait for a Flow Control Frame, and
                schedule a timeout waiting for the FCF.
                ------------------------------------------------------*/
                l_p_send_xfr->block_num = 0;
                l_p_send_xfr->state = TP_NS_SEND_WFCFRX;
                schedule_transfer_timeout( TP_N_Bs, &( l_p_send_xfr->timer ) );
                }
            else
                {
                /*------------------------------------------------------
                More Consecutive Frames are required to complete the
                block transmission. Get the CAN Transmit Data structure
                for this channel and initialize it.
                ------------------------------------------------------*/
                l_p_tmd  = p_tp_chan_info->p_send_tmd;
                *l_p_tmd = *( p_tp_chan_info->p_send_ref_tmd );

                /*------------------------------------------------------
                Formulate the CAN frame data contents. Get the pointer
                to the TMD data and load the CF PCI nibble and the
                sequence number.
                ------------------------------------------------------*/
                l_p_tmd_data = p_tp_chan_info->p_send_tmd_data;
                l_p_tmd_data[0] = TP_NP_CF_PCI | (l_p_send_xfr->seq_num & TP_SN_MASK );

                /*------------------------------------------------------
                Get the number of bytes sent and the number left to
                send. Determine the number of data bytes that need to
                be stored in this frame and set the CAN frame data
                length if it's less than the default length of 8 bytes.
                Copy the frame data into the CAN frame data buffer.
                ------------------------------------------------------*/
                l_num_bytes_unsent = l_p_send_xfr->num_total - l_p_send_xfr->num_sent;

                if( l_num_bytes_unsent >= TP_CF_MAX_DATA_BYTES )
                    {
                    l_num_store = TP_CF_MAX_DATA_BYTES;
                    }
                else
                    {
                    l_num_store  = (uint8) l_num_bytes_unsent;
                    l_p_tmd->dlc = l_num_store + 1;
                    }

                (void) memcpy( &l_p_tmd_data[1], &l_p_send_xfr->p_data[l_p_send_xfr->num_sent], l_num_store );

                /*------------------------------------------------------
                Check the STmin value to determine if the CF needs to be
                transmitted immediately or scheduled.
                ------------------------------------------------------*/
                if( 0 == l_p_send_xfr->st_min )
                    {
                    /*------------------------------------------------------
                    The CF needs to be sent immediately. Set the state to
                    wait for the CF transmit complete and set the timeout.
                    ------------------------------------------------------*/
                    l_p_send_xfr->state = TP_NS_SEND_WCFTXC;

                    schedule_transfer_timeout( l_p_send_xfr->n_as_timeout, &( l_p_send_xfr->timer ) );
                    /*TEMP_TEST*/
                     PRINTF("SF_FF_CF send:%x\r\n",l_p_tmd->identifier);
                     PRINTF("%x,%x,%x\r\n",l_p_tmd->p_data[0],l_p_tmd->p_data[1],l_p_tmd->p_data[2]);
                    (void) can_transmit( hw_inst, l_p_tmd );
                    }
                else
                    {
                    /*------------------------------------------------------
                    Set the timer to schedule the next CF transmission
                    according to the STmin value. Set the state to wait for
                    the timer to elapse to send the CF.
                    ------------------------------------------------------*/
                    l_p_send_xfr->state = TP_NS_SEND_WSTMIN;

                    schedule_send_cf_transmit( p_tp_chan_info, &( l_p_send_xfr->timer ), l_p_send_xfr->st_min );
                    }
                }
            }
        else
            {
            /*------------------------------------------------------
            Process completion of the send message transfer.
            ------------------------------------------------------*/
            process_send_transfer_complete( p_tp_chan_info, TP_N_OK, ch_index, hw_inst );
            }

        break;

    default:
        break;
    }
}

/*!*******************************************************************
*
* process TP Flow Control Frame reception
*
* This function processes reception of a Flow Control Frame by a TP
* channel Send transfer. Note there are different possible Flow Control
* Frame types including Clear To Send (CTS), Wait To Send (WTS) and
* Overflow (OVFLW).
*
*********************************************************************/
static void
process_send_fcf_rx_complete_event
    (
    tp_chan_info_t  const * const p_tp_chan_info,   //!< [in] ptr to TP channel info
    tp_n_frame_t            const frame_type,       //!< [in] TP frame type
    can_rmd_t       const * const p_rmd,            //!< [in] ptr to received Flow Control Frame
    tp_chan_index_t         const ch_index,         //!< [in] TP channel index
    can_hw_inst_t           const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_n_send_xfr_t   * l_p_send_xfr;
can_tmd_t         * l_p_tmd;
uint8             * l_p_tmd_data;
uint8               l_num_store;
uint8               l_block_size;
boolean             l_fcf_ok;
uint8               l_st_min;
uint16              l_num_bytes_unsent;

/*------------------------------------------------------
Initialize the FCF OK flag.
------------------------------------------------------*/
l_fcf_ok = TRUE;

#if(CANTP_DEBUG)
//PRINTF("CANTP receive a FC message----Time:%d\r\n",g_global_runtime);
#endif
/*------------------------------------------------------
Get the Send process state and status information from
the TP channel info. Check that the Send TP channel
state expects a Flow Control Frame reception and that
the frame is valid.
------------------------------------------------------*/
l_p_send_xfr = p_tp_chan_info->p_send_xfr;

if( TP_NS_SEND_WFCFRX == l_p_send_xfr->state )
    {
    if( p_rmd->dlc > TP_GPNUM_2 )
        {
        /*------------------------------------------------------
        Process the Flow Control Frame based on its type. First
        check for a Clear To Send frame.
        ------------------------------------------------------*/
        if( TP_NF_FCF_CTS == frame_type )
            {
            /*------------------------------------------------------
            Extract the BS (Block Size) and ST_MIN from the FCF. Set
            Flow Control Frame OK to TRUE;
            ------------------------------------------------------*/
            l_block_size = p_rmd->data[1];
            l_st_min = p_rmd->data[2];

            /*------------------------------------------------------
            Check for a valid STmin value.
            ------------------------------------------------------*/
            if(   ( l_st_min <= TP_MAX_STMIN_VALUE_IN_MS ) ||
                ( ( l_st_min >= TP_MIN_STMIN_VALUE_IN_US ) &&
                  ( l_st_min <= TP_MAX_STMIN_VALUE_IN_US ) ) )
                {
                /*------------------------------------------------------
                Do nothing, the STmin value is valid.
                ------------------------------------------------------*/
                ;
                }
            else
                {
                /*------------------------------------------------------
                The transfer has failed due to reception of an invalid
                STmin value.
                ------------------------------------------------------*/
                process_send_transfer_complete( p_tp_chan_info, TP_N_INVALID_STMIN, ch_index, hw_inst );
                l_fcf_ok = FALSE;
                }

            /*------------------------------------------------------
            Check that FCF is still OK.
            ------------------------------------------------------*/
            if( l_fcf_ok != FALSE )
                {
                /*------------------------------------------------------
                Check if this is the first FCF CTS reception in the
                transfer.
                ------------------------------------------------------*/
                if( ( l_p_send_xfr->status & TP_NB_SEND_OK_TO_UPDATE_BS_ST ) != 0 )
                    {
                    /*------------------------------------------------------
                    Don't allow any more updates during this transfer and
                    save the Block Size and STmin parameter values.
                    ------------------------------------------------------*/
                    l_p_send_xfr->status &= ( TP_GPNUM_FF ^ TP_NB_SEND_OK_TO_UPDATE_BS_ST );
                    l_p_send_xfr->block_size = l_block_size;
                    l_p_send_xfr->st_min = l_st_min;
                    }
                else
                    {
                    /*------------------------------------------------------
                    Not the first Flow Control Frame received in a multiple
                    block transfer. Check that the received STmin and BS
                    values match what was received in the first block
                    transfer.
                    ------------------------------------------------------*/
                    if( ( l_block_size != l_p_send_xfr->block_size ) ||
                        ( l_st_min != l_p_send_xfr->st_min ) )
                        {
                        /*------------------------------------------------------
                        The transfer has failed due to reception of a Flow
                        Control Frame with parameters that don't match the
                        parameters received in the first block.
                        ------------------------------------------------------*/
                        process_send_transfer_complete( p_tp_chan_info, TP_N_INVALID_FS, ch_index, hw_inst );
                        l_fcf_ok = FALSE;
                        }
                    }
                }

            if( l_fcf_ok != FALSE )
                {
                /*------------------------------------------------------
                More Consecutive Frames are required to complete the
                block transmission. Get the CAN Transmit Data structure
                for this channel and initialize it.
                ------------------------------------------------------*/
                l_p_tmd = p_tp_chan_info->p_send_tmd;
                *l_p_tmd = *( p_tp_chan_info->p_send_ref_tmd );

                /*------------------------------------------------------
                Formulate the CAN frame data contents. Load the CF PCI
                nibble and the sequence number.
                ------------------------------------------------------*/
                l_p_tmd_data = p_tp_chan_info->p_send_tmd_data;
                l_p_tmd_data[0] = ( TP_NP_CF_PCI | ( l_p_send_xfr->seq_num & TP_SN_MASK ) );

                /*------------------------------------------------------
                Get the number of bytes sent and the number left to
                send. Determine the number of data bytes that need to
                be stored in this frame and set the CAN frame data
                length if it's less than the default length of 8 bytes.
                Copy the frame data into the CAN frame data buffer.
                ------------------------------------------------------*/
                l_num_bytes_unsent = l_p_send_xfr->num_total - l_p_send_xfr->num_sent;

                if( l_num_bytes_unsent >= TP_CF_MAX_DATA_BYTES )
                    {
                    l_num_store = TP_CF_MAX_DATA_BYTES;
                    }
                else
                    {
                    l_num_store = (uint8) l_num_bytes_unsent;
                    l_p_tmd->dlc = l_num_store + 1;
                    }

                (void) memcpy( &l_p_tmd_data[1], &l_p_send_xfr->p_data[l_p_send_xfr->num_sent], l_num_store );

                /*------------------------------------------------------
                Check the STmin value to determine if the CF needs to be
                transmitted immediately or scheduled.
                ------------------------------------------------------*/
                if( 0 == l_p_send_xfr->st_min )
                    {
                    /*------------------------------------------------------
                    The CF needs to be sent immediately. Set the state to
                    wait for the CF transmit complete and set the timeout.
                    ------------------------------------------------------*/
                    l_p_send_xfr->state = TP_NS_SEND_WCFTXC;

                    schedule_transfer_timeout( l_p_send_xfr->n_as_timeout, &( l_p_send_xfr->timer ) );
                    /*TEMP_TEST*/
    PRINTF("FC send:%x\r\n",l_p_tmd->identifier);
    PRINTF("%x,%x,%x\r\n",l_p_tmd->p_data[0],l_p_tmd->p_data[1],l_p_tmd->p_data[2]);
                    (void)can_transmit( hw_inst, l_p_tmd );
                    }
                else
                    {
                    /*------------------------------------------------------
                    Set the timer to schedule the next CF transmission
                    according to the STmin value. Set the state to wait for
                    the timer to elapse to send the CF.
                    ------------------------------------------------------*/
                    l_p_send_xfr->state = TP_NS_SEND_WSTMIN;

                   schedule_send_cf_transmit( p_tp_chan_info, &( l_p_send_xfr->timer ), l_p_send_xfr->st_min );
                    }
                }
            }
        else if( TP_NF_FCF_WTS == frame_type )
            {
            /*------------------------------------------------------
            Check if the maximum number of WTS frames applies to
            this TP channel.
            ------------------------------------------------------*/
            if( FALSE == p_tp_chan_info->send_ignore_wts_max )
                {
                /*------------------------------------------------------
                Check for valid number of Wait FCF's received.
                ------------------------------------------------------*/
                if( l_p_send_xfr->num_wtfcf_rcvd <= p_tp_chan_info->wts_max )
                    {
                    /*------------------------------------------------------
                    Check for received Wait FCF overrun.
                    ------------------------------------------------------*/
                    if( 0 == l_p_send_xfr->num_wtfcf_rcvd )
                        {
                        process_send_transfer_complete( p_tp_chan_info, TP_N_WFT_OVRN, ch_index, hw_inst );
                        }
                    else
                        {
                        /*------------------------------------------------------
                        Decrement the Wait FCF count and reschedule the TP_N_Bs
                        timeout.
                        ------------------------------------------------------*/
                        l_p_send_xfr->num_wtfcf_rcvd--;
                        schedule_transfer_timeout( TP_N_Bs, &( l_p_send_xfr->timer ) );
                        }
                    }
                else
                    {
                    /*------------------------------------------------------
                    Unexpected value for Wait FCF's received, reset it.
                    ------------------------------------------------------*/
                    l_p_send_xfr->num_wtfcf_rcvd = p_tp_chan_info->wts_max;
                    }
                }
            else
                {
                /*------------------------------------------------------
                Reschedule the TP_N_Bs timeout.
                ------------------------------------------------------*/
                schedule_transfer_timeout( TP_N_Bs, &( l_p_send_xfr->timer ) );
                }
            }
        else if( TP_NF_FCF_OVFLW == frame_type )
            {
            /*------------------------------------------------------
            Overflow Frame received. The transfer has failed due to
            receive buffer overflow.
            ------------------------------------------------------*/
            process_send_transfer_complete( p_tp_chan_info, TP_N_BUFFER_OVFLW, ch_index, hw_inst );
            }
        else
            {
            /*------------------------------------------------------
            The transfer has failed due to reception of an undefined
            Flow Control Frame.
            ------------------------------------------------------*/
            process_send_transfer_complete( p_tp_chan_info, TP_N_INVALID_FS, ch_index, hw_inst );
            }
        }
    else
        {
        /*------------------------------------------------------
        The transfer has failed due to reception of an invalid
        Flow Control Frame (invalid length).
        ------------------------------------------------------*/
        process_send_transfer_complete( p_tp_chan_info, TP_N_UNEXP_PDU, ch_index, hw_inst );
        }
    }
else
    {
    /*------------------------------------------------------
    The transfer has failed due to reception of an
    unexpected Flow Control Frame.
    ------------------------------------------------------*/
    process_send_transfer_complete( p_tp_chan_info, TP_N_UNEXP_PDU, ch_index, hw_inst );
    }
}


/*!*******************************************************************
*
* process Send transfer timer tick event
*
* This function processes a Send transfer process timer tick event.
* This primarily involves updating the channel timer and looking for
* a timeout.
*
*********************************************************************/
static void
process_send_tick_event
    (
    tp_chan_index_t     const ch_index,         //!< [in] TP channel index
    can_hw_inst_t       const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_chan_info_t  const * l_p_tp_chan_info;
tp_n_send_xfr_t       * l_p_send_xfr;

/*------------------------------------------------------
Get the pointer to the TP channel info and the Send
process state and status info.
------------------------------------------------------*/
l_p_tp_chan_info = &( tp_hw_inst_info[hw_inst].p_tp_chan_info[ch_index] ) ;
l_p_send_xfr = l_p_tp_chan_info->p_send_xfr;

/*------------------------------------------------------
Check if the timeout timer is active. If so, decrement
the timer and check for a timeout event and process it.
------------------------------------------------------*/
if( l_p_send_xfr->timer != 0 )
    {
    l_p_send_xfr->timer--;

    if( 0 == l_p_send_xfr->timer )
        {
        process_send_timeout_event( l_p_tp_chan_info, ch_index, hw_inst );
        }
    }
}

/*!*******************************************************************
*
* process Send transfer timer tick event
*
* This function processes a Send transfer timeout event. Under normal
* (non-error) conditions this timeout is due to scheduling the
* transmission of a Consecutive Frame in a segmented transfer
* according to the STmin (minimum time between Consecutive Frames)
* value provided by the receiver in a received Flow Control Frame.
* The timeout may be due to not having received notification of a
* pending transmitted frame completion (SF, FF or CF) or it may be due
* to a timeout waiting for the receiver to transmit a Flow Control
* Frame in response to a successful First Frame transmission.
*
*********************************************************************/
static void
process_send_timeout_event
    (
    tp_chan_info_t  const * const p_tp_chan_info,   //!< [in] ptr to TP channel info
    tp_chan_index_t         const ch_index,         //!< [in] TP channel index
    can_hw_inst_t           const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_n_send_xfr_t   * l_p_send_msg;
can_tmd_t         * l_p_tmd;
tp_n_result_t       l_result;

/*------------------------------------------------------
Get the Send state and status information for this
channel. Process the send timeout event according to the
current send transfer state.
------------------------------------------------------*/
l_p_send_msg = p_tp_chan_info->p_send_xfr;

switch ( l_p_send_msg->state )
    {
    case TP_NS_SEND_WSFTXC:
    case TP_NS_SEND_WFCFRX:
    case TP_NS_SEND_WFFTXC:
    case TP_NS_SEND_WCFTXC:
        /*------------------------------------------------------
        Timeout waiting for a frame transmission to complete or
        to receive an expected  Flow Control Frame. Determine
        the exact failure depending on the current Send state
        and report the Send transfer failure to the application.
        ------------------------------------------------------*/
        if( l_p_send_msg->state == TP_NS_SEND_WFCFRX )
            {
            l_result = TP_N_TIMEOUT_Bs;
            #if(CANTP_DEBUG)
            //PRINTF("Send error:TP_N_TIMEOUT_Bs error----Time:%d\r\n",g_global_runtime);
            #endif
            }
        else
            {
            l_result = TP_N_TIMEOUT_A;
            #if(CANTP_DEBUG)
            //PRINTF("Send error:TP_N_TIMEOUT_A error----Time:%d\r\n",g_global_runtime);
            #endif
            }
        process_send_transfer_complete( p_tp_chan_info, l_result, ch_index, hw_inst );

        break;

    case TP_NS_SEND_WSTMIN:
        /*------------------------------------------------------
        Timeout waiting for the STmin period to transmit a
        pending Consecutive Frame. Assume that all of the frame
        data has been loaded and is ready to transmit. Set the
        state to waiting for the transmit to complete and
        schedule the transmit complete timeout.
        ------------------------------------------------------*/
        l_p_send_msg->state = TP_NS_SEND_WCFTXC;
        schedule_transfer_timeout( l_p_send_msg->n_as_timeout, &( l_p_send_msg->timer ) );

        l_p_tmd = p_tp_chan_info->p_send_tmd;
        /*TEMP_TEST*/
    PRINTF("TIMEOUT send:%x\r\n",l_p_tmd->identifier);
    PRINTF("%x,%x,%x\r\n",l_p_tmd->p_data[0],l_p_tmd->p_data[1],l_p_tmd->p_data[2]);
        (void) can_transmit( hw_inst, l_p_tmd );
        break;

    default:
        break;
    }
}

/*!*******************************************************************
*
* process Receive Flow Control Frame transmit complete event
*
* This function checks for and processes a Receive transfer Flow
* Control Frame transmit complete notification event. When a TP
* channel receives a First Frame at the start of a reception transfer,
* it must send a Flow Control Frame to the transmitter to allow the
* the transmitter to continue sending the data frames according to the
* STmin and Block Size parameters included in the Flow Control Frame.
*
*********************************************************************/
static void
process_receive_fcf_tx_complete_event
    (
    tp_chan_info_t  const * const p_tp_chan_info,   //!< [in] ptr to TP channel info
    tp_chan_index_t         const ch_index,         //!< [in] TP channel index
    can_hw_inst_t           const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_n_recv_xfr_t   * l_p_recv_xfr;

/*------------------------------------------------------
Get the Receive process information. Cancel the Receive
process timeout and process the Flow Control Frame
transmit complete event.
------------------------------------------------------*/
l_p_recv_xfr = p_tp_chan_info->p_recv_xfr;
cancel_transfer_timeout( &( l_p_recv_xfr->timer ) );

switch ( l_p_recv_xfr->state )
    {
    case TP_NS_RECV_WCTSTXC:
        /*------------------------------------------------------
        A Clear To Send FCF was sent so the next state waits for
        a Consecutive Frame reception. Set the timer to the
        timeout waiting for the Consecutive Frame reception.
        ------------------------------------------------------*/
        l_p_recv_xfr->state = TP_NS_RECV_WCFRX;
        schedule_transfer_timeout( TP_N_Cr, &( l_p_recv_xfr->timer ) );
        break;

    case TP_NS_RECV_WOVFTXC:
        /*------------------------------------------------------
        An Overflow FCF was sent last. Return the Receive
        process state to Idle.
        ------------------------------------------------------*/
        l_p_recv_xfr->state = TP_NS_RECV_IDLE;
        break;

    case TP_NS_RECV_WWTSTXC:
        /*------------------------------------------------------
        Currently in Wait To Send state. Check that the number
        of Wait to Send Flow Control frames sent is in range. If
        not, reset the value, otherwise decrement the number of
        WTS Flow Control frames sent and check if the maximum
        number has been reached. If so, return to the Idle
        state. If not, send another WTS FCF and schedule a
        transmit complete timeout for WTS FCF transmission
        notification.
        ------------------------------------------------------*/
        if( l_p_recv_xfr->num_wtfcf_txd > p_tp_chan_info->wts_max )
            {
            /*------------------------------------------------------
            Unexpected out of range condition (reset the count).
            ------------------------------------------------------*/
            l_p_recv_xfr->num_wtfcf_txd = p_tp_chan_info->wts_max;
            }
        /*------------------------------------------------------
        Don't underflow if the value is zero.
        ------------------------------------------------------*/
        else if( l_p_recv_xfr->num_wtfcf_txd != 0 )
            {
            /*------------------------------------------------------
            This is the expected execution path.
            ------------------------------------------------------*/
            l_p_recv_xfr->num_wtfcf_txd--;
            }
        else
            {
            /*------------------------------------------------------
            Count is already zero, do nothing.
            ------------------------------------------------------*/
            ;
            }

        /*------------------------------------------------------
        Check for maximum WTS FCF count reached.
        ------------------------------------------------------*/
        if( 0 == l_p_recv_xfr->num_wtfcf_txd )
            {
            l_p_recv_xfr->state = TP_NS_RECV_IDLE;
            }
        else
            {
            l_p_recv_xfr->state = TP_NS_RECV_SUSPEND;
            schedule_transfer_timeout( TP_N_Bs_WFT_TIMEOUT, &( l_p_recv_xfr->timer ) );
            }
        break;

    default:
        break;
    }
}

/*!*******************************************************************
*
* process Receive TP data frame event
*
* This function processes reception of a Transport Protocol data
* frame, including a Single Frame, First Frame or Consecutive Frame.
* Processing of the frame event depends on the current state of the
* TP channel receive transfer.
*
*********************************************************************/
static void
process_receive_sf_ff_cf_rx_complete_event
    (
    tp_chan_info_t  const * const p_tp_chan_info,   //!< [in] ptr to TP channel info
    tp_n_frame_t            const frame_type,       //!< [in] received TP data frame type (SF, FF or CF)
    can_rmd_t       const * const p_rmd,            //!< [in] ptr to receive CAN Transmit Data structure
    tp_chan_index_t         const ch_index,         //!< [in] TP channel index
    can_hw_inst_t           const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_n_recv_xfr_t       * l_p_recv_xfr;
can_tmd_t       const * l_p_tmd;
uint8                 * l_p_tmd_data;
uint8                 * l_p_rcv_pkt;
uint16                  l_rcv_pkt_size;
uint16                  l_num_bytes;
TP_RC                  l_return_code;
uint8                   index;
/*------------------------------------------------------
Get the Receive process state and status information
from the TP channel info. Process the Receive data frame
event according to the received frame type (SF, FF, CF).
------------------------------------------------------*/
l_p_recv_xfr = p_tp_chan_info->p_recv_xfr;

switch( frame_type )
    {
    case TP_NF_SF:
        /*------------------------------------------------------
        Process Single Frame reception. First check if the SF
        has at least one data byte.
        ------------------------------------------------------*/
        if( p_rmd->dlc > 0 )
            {
            /*------------------------------------------------------
            Extract the SF payload size and check that it is
            consistent with the reported CAN frame DLC.
            ------------------------------------------------------*/
            l_num_bytes = (uint16) ( p_rmd->data[0] & TP_GPNUM_0F );

            if( ( l_num_bytes > 0 )                     &&
                ( l_num_bytes < CAN_MAX_DATA_LENGTH )   &&
                ( p_rmd->dlc  > l_num_bytes ) )
                {
                /*------------------------------------------------------
                Check for an unexpected frame. A Single Frame reception
                is only expected in the Idle state. Report an unexpected
                frame reception to the application.
                ------------------------------------------------------*/
                if( TP_NS_RECV_IDLE != l_p_recv_xfr->state )
                    {
                    process_receive_transfer_complete( p_tp_chan_info, NULL, 0, TP_N_UNEXP_PDU, ch_index, hw_inst );
                    }

                /*------------------------------------------------------
                Pass the received payload to the Application.
                ------------------------------------------------------*/
                process_receive_transfer_complete( p_tp_chan_info, &p_rmd->data[1], l_num_bytes, TP_N_OK, ch_index, hw_inst );
                }
            }
        break;

    case TP_NF_FF:
        /*------------------------------------------------------
        Process First Frame reception. First get the number of
        bytes in the transfer and check for consistency with
        the CAN Data Length Code, which should be 8 for a FF.
        ------------------------------------------------------*/
        l_num_bytes = (uint16) ( ( ( ( p_rmd->data[0] & TP_GPNUM_0F ) ) << TP_GPNUM_8 ) | ( p_rmd->data[1] ) );

        if( ( CAN_MAX_DATA_LENGTH == p_rmd->dlc ) &&
            ( l_num_bytes > (uint16) ( CAN_MAX_DATA_LENGTH - 1 ) ) )
            {
            /*------------------------------------------------------
            Get pointer to the CAN Transmit Data structure and to
            the TMD data buffer to send a Flow Control Frame.
            ------------------------------------------------------*/
            l_p_tmd = p_tp_chan_info->p_fcf_tmd;
            l_p_tmd_data = p_tp_chan_info->p_fcf_tmd_data;

            /*------------------------------------------------------
            Get the of the receive packet buffer and check if the
            transfer size is too large for the buffer to hold the
            receive transfer data.
            ------------------------------------------------------*/
            l_rcv_pkt_size = p_tp_chan_info->p_recv_pkt_info->buffer_size;

            if( l_num_bytes > l_rcv_pkt_size )
                {
                /*------------------------------------------------------
                Too large, prepare to send the Overflow FCF. Set the
                state for expecting FCF transmit complete and set the
                timer for the transmit complete timeout.
                ------------------------------------------------------*/
                l_p_tmd_data[0] = TP_NP_FCF_OVFLW_PCI;
                l_p_tmd_data[1] = l_p_recv_xfr->block_size;
                l_p_tmd_data[2] = l_p_recv_xfr->st_min;
                for( index = 3; index < TP_FCF_NUM_BYTES; index++ )
                    {
                    l_p_tmd_data[index] = 0x55;
                    }
                l_p_recv_xfr->state = TP_NS_RECV_WOVFTXC;
                schedule_transfer_timeout( l_p_recv_xfr->n_ar_timeout, &( l_p_recv_xfr->timer ) );
                (void) can_transmit( hw_inst, l_p_tmd );
                }
            else
                {
                /*------------------------------------------------------
                Check if the First Frame reception is expected (in the
                Idle state). If a transfer was already in progress,
                notify the application of an unexpected frame.
                ------------------------------------------------------*/
                if( l_p_recv_xfr->state == TP_NS_RECV_IDLE )
                    {
                    client_dcm_SOM_indication( TP_N_OK, p_rmd->data, *( p_tp_chan_info->p_recv_canid_index ), hw_inst, ch_index );
                    }
                else
                    {
                    client_dcm_SOM_indication( TP_N_UNEXP_PDU, p_rmd->data, *( p_tp_chan_info->p_recv_canid_index ), hw_inst, ch_index );
                    //can_diag_hook_receive_complete( NULL, 0, TP_N_UNEXP_PDU, DIAGNOSTICS_TP_CHANNEL_INDEX, hw_inst );
                    }
                /*------------------------------------------------------
                If there is a pending request to suspend reception,
                clear the request and change the state to Suspend.
                ------------------------------------------------------*/
                if( ( l_p_recv_xfr->status & TP_NB_RECV_SUSPEND_PNDG ) != 0 )
                    {
                    l_p_recv_xfr->status &= ( TP_GPNUM_FF ^ TP_NB_RECV_SUSPEND_PNDG );
                    l_p_recv_xfr->state = TP_NS_RECV_SUSPEND;
                    }

                /*------------------------------------------------------
                Initialize the Receive transfer variables for a new
                transfer and store the First Frame data bytes.
                ------------------------------------------------------*/
                l_p_recv_xfr->block_num = 0;
                l_p_recv_xfr->seq_num   = 0;
                l_p_recv_xfr->num_rcvd  = (uint16) TP_FF_MAX_DATA_BYTES;
                l_p_recv_xfr->num_total = l_num_bytes;
                l_p_recv_xfr->num_wtfcf_txd = p_tp_chan_info->wts_max;

                l_p_rcv_pkt = p_tp_chan_info->p_recv_pkt_info->p_pkt_buffer;

                (void) memcpy( l_p_rcv_pkt, &p_rmd->data[TP_GPNUM_2], TP_FF_MAX_DATA_BYTES );

                /*------------------------------------------------------
                If in Suspend mode, set the timeout to transmit the next
                Wait To Send frame (interval of 0.9 x TP_N_Bs). If not
                in Suspend mode, send the Clear To Send Flow Control
                Frame, set the state expecting its transmit completion,
                and set the timeout for transmit completion.
                ------------------------------------------------------*/
                if( TP_NS_RECV_SUSPEND == l_p_recv_xfr->state )
                    {
                    schedule_transfer_timeout( TP_N_Bs_WFT_TIMEOUT, &( l_p_recv_xfr->timer ) );
                    }
                else
                    {
                    l_p_tmd_data[0] = TP_NP_FCF_CTS_PCI;
                    l_p_tmd_data[1] = l_p_recv_xfr->block_size;
                    l_p_tmd_data[TP_GPNUM_2] = l_p_recv_xfr->st_min;
                    for( index = 3; index < TP_FCF_NUM_BYTES; index++ )
                        {
                        l_p_tmd_data[index] = 0x55;
                        }
                    l_p_recv_xfr->state = TP_NS_RECV_WCTSTXC;
                    schedule_transfer_timeout( l_p_recv_xfr->n_ar_timeout, &( l_p_recv_xfr->timer ) );
                    (void) can_transmit( hw_inst, l_p_tmd );
                    }
                }
            }
        break;

    case TP_NF_CF:
        /*------------------------------------------------------
        Process Consecutive Frame reception. First get the
        number of bytes in the frame and check for consistency
        with the CAN Data Length Code.
        ------------------------------------------------------*/
        if( ( TP_NS_RECV_WCFRX == l_p_recv_xfr->state ) && ( p_rmd->dlc > 1 ) )
            {
            /*------------------------------------------------------
            Determine the number of data bytes in this frame and if
            all bytes in the transfer are not yet received. If not
            yet complete, this frame must have 7 data bytes.
            ------------------------------------------------------*/
            l_num_bytes = (uint16) ( p_rmd->dlc - 1 );

            if( ( l_num_bytes + l_p_recv_xfr->num_rcvd ) < l_p_recv_xfr->num_total )
                {
                if( TP_CF_MAX_DATA_BYTES == l_num_bytes )
                    {
                    /*------------------------------------------------------
                    Check for the expected CF sequence number.
                    ------------------------------------------------------*/
                    l_return_code = check_cf_sequence_number( p_tp_chan_info, p_rmd->data[0], ch_index, hw_inst );

                    if( TP_RC_OK == l_return_code )
                        {
                        /*------------------------------------------------------
                        Increment the block number and store the data bytes.
                        ------------------------------------------------------*/
                        if( 0xf > l_p_recv_xfr->block_num )
                            {
                            l_p_recv_xfr->block_num++;
                            }
                        else
                            {
                            l_p_recv_xfr->block_num = 0x00;
                            }
                        l_p_rcv_pkt = &( p_tp_chan_info->p_recv_pkt_info->p_pkt_buffer[l_p_recv_xfr->num_rcvd] );

                        (void) memcpy ( l_p_rcv_pkt, &( p_rmd->data[1] ), l_num_bytes );

                        l_p_recv_xfr->num_rcvd += l_num_bytes;

                        /*------------------------------------------------------
                        Check for the end of a block of frames.
                        ------------------------------------------------------*/
                        if( ( l_p_recv_xfr->block_size != 0 ) &&
                            ( l_p_recv_xfr->block_num  >= l_p_recv_xfr->block_size ) )
                            {
                            /*------------------------------------------------------
                            Send the Flow Control Frame at the end of a received
                            block. Set the state and the timeout waiting for the
                            Flow Control Frame transmission to complete.
                            ------------------------------------------------------*/
                            l_p_tmd  = p_tp_chan_info->p_fcf_tmd;
                            l_p_tmd_data = p_tp_chan_info->p_fcf_tmd_data;
                            l_p_tmd_data[0] = TP_NP_FCF_CTS_PCI;
                            l_p_tmd_data[1] = l_p_recv_xfr->block_size;
                            l_p_tmd_data[2] = l_p_recv_xfr->st_min;
                            for( index = 3; index < TP_FCF_NUM_BYTES; index++ )
                                {
                                l_p_tmd_data[index] = 0x55;
                                }
                            l_p_recv_xfr->state = TP_NS_RECV_WCTSTXC;
                            schedule_transfer_timeout( l_p_recv_xfr->n_ar_timeout, &( l_p_recv_xfr->timer ) );
                            (void) can_transmit( hw_inst, l_p_tmd );
                            }
                        else
                            {
                            /*------------------------------------------------------
                            Set timeout waiting for next CF (stay in same state).
                            ------------------------------------------------------*/
                            schedule_transfer_timeout( TP_N_Cr, &( l_p_recv_xfr->timer ) );
                            }
                        }
                    }
                }
            else
                {
                /*------------------------------------------------------
                This Consecutive Frame must be the last one in the
                transfer. Compute the number of bytes needed to complete
                the transfer and make sure this CF is large enough.
                ------------------------------------------------------*/
                l_num_bytes = ( l_p_recv_xfr->num_total - l_p_recv_xfr->num_rcvd );

                if( p_rmd->dlc > l_num_bytes )
                    {
                    /*------------------------------------------------------
                    Check for the expected CF sequence number.
                    ------------------------------------------------------*/
                    l_return_code = check_cf_sequence_number( p_tp_chan_info, p_rmd->data[0], ch_index, hw_inst );

                    if( l_return_code == TP_RC_OK )
                        {
                        /*------------------------------------------------------
                        Store the final bytes in the transfer and notify the
                        application of a successful TP reception transfer.
                        ------------------------------------------------------*/
                        l_p_rcv_pkt = &( p_tp_chan_info->p_recv_pkt_info->p_pkt_buffer[l_p_recv_xfr->num_rcvd] );

                        (void) memcpy( l_p_rcv_pkt, &p_rmd->data[1], l_num_bytes );

                        process_receive_transfer_complete( p_tp_chan_info,
                                                           p_tp_chan_info->p_recv_pkt_info->p_pkt_buffer,
                                                           l_p_recv_xfr->num_total,
                                                           TP_N_OK,
                                                           ch_index,
                                                           hw_inst );
                        }
                    }
                }
            }
        break;

    default:
        break;
    }
}

/*!*******************************************************************
*
* check a received Consecutive Frame sequence number
*
* This function extracts the sequence number from the PCI byte of a
* received Consecutive Frame and checks it against the expected SN
* for the channel receive transfer. If the SN is not correct, the
* application is notified of the error.
*
* @return TP_RC
* returns communication error code
*
*********************************************************************/
static TP_RC
check_cf_sequence_number
    (
    tp_chan_info_t  const * const p_tp_chan_info,   //!< [in] ptr to TP channel info
    uint8                   const pci_byte,         //!< [in] CF PCI byte value
    tp_chan_index_t         const ch_index,         //!< [in] TP channel index
    can_hw_inst_t           const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_n_recv_xfr_t   * l_p_recv_xfr;
TP_RC              l_return_code;

/*------------------------------------------------------
Initialize the return code. Get the Receive process
info from the TP channel info.
------------------------------------------------------*/
l_return_code = TP_RC_OK;
l_p_recv_xfr  = p_tp_chan_info->p_recv_xfr;

/*------------------------------------------------------
Increment the channel Receive transfer Sequence Number
and wrap around if needed. Extract the SN from the PCI
byte and check if it matches the expected value.
------------------------------------------------------*/
l_p_recv_xfr->seq_num++;

if( l_p_recv_xfr->seq_num > TP_CF_SN_MAX_VALUE )
    {
    l_p_recv_xfr->seq_num = 0;
    }

if( ( pci_byte & TP_SN_MASK ) != l_p_recv_xfr->seq_num )
    {
    l_return_code = TP_RC_FAIL;
    process_receive_transfer_complete( p_tp_chan_info, NULL, 0, TP_N_WRONG_SN, ch_index, hw_inst );
    }

return l_return_code;
}

/*!*******************************************************************
*
* process Receive transfer timer tick event
*
* This function processes a Receive transfer timer tick event. This
* primarily involves updating the channel timer and looking for a
* timeout.
*
*********************************************************************/
static void
process_receive_tick_event
    (
    tp_chan_index_t     const ch_index,         //!< [in] TP channel index
    can_hw_inst_t       const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_chan_info_t  const * l_p_tp_chan_info;
tp_n_recv_xfr_t       * l_p_recv_xfr;

/*------------------------------------------------------
Get the pointer to the TP channel info and the Receive
process state and status info.
------------------------------------------------------*/
l_p_tp_chan_info = &( tp_hw_inst_info[hw_inst].p_tp_chan_info[ch_index] ) ;
l_p_recv_xfr = l_p_tp_chan_info->p_recv_xfr;

/*------------------------------------------------------
Check if the timeout timer is active. If it is,
decrement the timer and check for a timeout event.
Process any timeout events.
------------------------------------------------------*/
if( l_p_recv_xfr->timer != 0 )
    {
    l_p_recv_xfr->timer--;

    if( 0 == l_p_recv_xfr->timer )
        {
        process_receive_timeout_event( l_p_tp_chan_info, ch_index, hw_inst );
        }
    }
}

/*!*******************************************************************
*
* process Receive transfer timeout event
*
* This function processes a Receive transfer timeout event. The
* timeout event may either be due to not having received notification
* of completion of a Flow Control Frame transmission or it may be due
* to a receive timeout waiting for reception of a Consecutive Frame.
* This timeout is also used to transmit Wait To Send Flow Control
* Frames when in the Receive Suspend state.
*
*********************************************************************/
static void
process_receive_timeout_event
    (
    tp_chan_info_t  const * const p_tp_chan_info,   //!< [in] ptr to TP channel info
    tp_chan_index_t         const ch_index,         //!< [in] TP channel index
    can_hw_inst_t           const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_n_recv_xfr_t     * l_p_recv_xfr;
can_tmd_t const       * l_p_tmd;
uint8                 * l_p_tmd_data;
tp_n_result_t         l_result;
tp_n_pci_t            l_pci_byte;
tp_n_receive_state_t  l_recv_state;

/*------------------------------------------------------
Get the channel Receive transfer state information.
Process the Receive transfer timeout event according to
the current state.
------------------------------------------------------*/
l_p_recv_xfr = p_tp_chan_info->p_recv_xfr;

switch( l_p_recv_xfr->state )
    {
    case TP_NS_RECV_WCTSTXC:
    case TP_NS_RECV_WCFRX:
    case TP_NS_RECV_WOVFTXC:
    case TP_NS_RECV_WWTSTXC:
        /*------------------------------------------------------
        Timeout waiting for a Flow Control Frame transmission
        notification or waiting for a Consecutive Frame
        reception. Check if waiting for a Consecutive Frame.
        ------------------------------------------------------*/
        if( TP_NS_RECV_WCFRX == l_p_recv_xfr->state )
            {
            l_result = TP_N_TIMEOUT_Cr;
            #if(CANTP_DEBUG)
            PRINTF("Received error:TP_N_TIMEOUT_Cr error\r\n");
            #endif
            }
        else
            {
            l_result = TP_N_TIMEOUT_A;
            #if(CANTP_DEBUG)
            PRINTF("Received error:TP_N_TIMEOUT_A error\r\n");
            #endif
            }

        /*------------------------------------------------------
        Process the transfer completion and notify the error.
        ------------------------------------------------------*/
        process_receive_transfer_complete( p_tp_chan_info, NULL, 0, l_result, ch_index, hw_inst );
        break;

    case TP_NS_RECV_SUSPEND:
        /*------------------------------------------------------
        Timeout in the Suspend state. Check for a pending Resume
        request.
        ------------------------------------------------------*/
        if( ( l_p_recv_xfr->status & TP_NB_RECV_RESUME_PNDG ) != 0 )
            {
            /*------------------------------------------------------
            Clear the pending Resume request. Prepare to send a
            CTS FCF and set the state to wait for transmit complete.
            ------------------------------------------------------*/
            l_p_recv_xfr->status &= ( TP_GPNUM_FF ^ TP_NB_RECV_RESUME_PNDG );
            l_pci_byte   = TP_NP_FCF_CTS_PCI;
            l_recv_state = TP_NS_RECV_WCTSTXC;
            }
        else
            {
            /*------------------------------------------------------
            Prepare to send a Wait To Send Flow Control Frame.
            ------------------------------------------------------*/
            l_pci_byte   = TP_NP_FCF_WTS_PCI;
            l_recv_state = TP_NS_RECV_WWTSTXC;
            }

        /*------------------------------------------------------
        Set up the CAN TMD structure and transmit the FCF.
        ------------------------------------------------------*/
        l_p_tmd  = p_tp_chan_info->p_fcf_tmd;
        l_p_tmd_data = p_tp_chan_info->p_fcf_tmd_data;

        l_p_tmd_data[0] = l_pci_byte;
        l_p_tmd_data[1] = l_p_recv_xfr->block_size;
        l_p_tmd_data[TP_GPNUM_2] = l_p_recv_xfr->st_min;

        l_p_recv_xfr->state = l_recv_state;
        schedule_transfer_timeout( l_p_recv_xfr->n_ar_timeout, &( l_p_recv_xfr->timer ) );

        (void) can_transmit( hw_inst, l_p_tmd );
        break;

    default:
        break;
    }
}

/*!*******************************************************************
*
* schedule a consecutive frame transmission
*
* This function schedules a Consecutive Frame transmission. This
* calls a function in CAN services that implements a hardware timer
* for precise control of the N_Cs inter-frame timing. This function
* assumes the st_min value passed in has already been confirmed as
* being a valid value in the range of 0x01 to 0x7F or 0xF1 to 0xF9.
* An STmin value of 0 is not expected as a passed in value because
* there is no need to schedule a delayed CF transmission for this
* case (transmit the CF immediately).
*
*********************************************************************/
#if( CAN_TP_USE_HW_TIMER_FOR_CF_TRANSMIT != FALSE )
static void
schedule_send_cf_transmit
    (
    tp_chan_info_t  const * const p_tp_chan_info,   //!< [in] ptr to TP channel info
    uint16                * const p_timer,          //!< [in, out] ptr to software timer to cancel
    uint8                   const st_min            //!< [in] STmin value
    )
{
uint16  l_cf_send_timer_tics;
boolean l_valid_st_min;

/*------------------------------------------------------
Initially assume a valid value of STmin. Cancel the task
tic timer event currently scheduled and get the CAN
services hardware timer index for this CAN hardware
instance and TP channel index. Schedule the CF send
timer event.
------------------------------------------------------*/
l_valid_st_min = TRUE;
cancel_transfer_timeout( p_timer );

/*------------------------------------------------------
Compute the number of 100 us timer tics in the specified
STmin value. The hardware timer is assumed to have a
timer tic time of 100 us. For values of 0x01 to 0x7F,
multiply the st_min value times 10.
------------------------------------------------------*/
if( ( st_min >= 0x01 ) && ( st_min <= 0x7F ) )
    {
    l_cf_send_timer_tics  =  st_min << 3;
    l_cf_send_timer_tics += (st_min << 1);
    }
else if( ( st_min >= 0xF0 ) && ( st_min <= 0xF9 ) )
    {
    l_cf_send_timer_tics  =  st_min - 0xF0;
    }
else
    {
    l_valid_st_min = FALSE;
    }

if( l_valid_st_min != FALSE )
    {
    can_start_send_cf_timer( l_cf_send_timer_tics, p_tp_chan_info->send_cf_timer_index );
    }
}

#else
static void
schedule_send_cf_transmit
    (
    tp_chan_info_t  const * const p_tp_chan_info,   //!< [in] ptr to TP channel info
    uint16                * const p_timer,          //!< [in, out] ptr to software timer to cancel
    uint8                   const st_min            //!< [in] STmin value
    )
{
uint8   l_st_min_ms;
boolean l_valid_st_min;

/*------------------------------------------------------
Initially assume a valid value of STmin.
------------------------------------------------------*/
l_valid_st_min = TRUE;

/*------------------------------------------------------
For STmin values from 0xF0 to 0xF1, set the STmin value
to 1 millisecond.
------------------------------------------------------*/
if( ( st_min >= 0x01 ) && ( st_min <= 0x7F ) )
    {
    /*------------------------------------------------------
    STmin value is already in milliseconds.
    ------------------------------------------------------*/
    l_st_min_ms = st_min;
    }
else if( ( st_min >= 0xF0 ) && ( st_min <= 0xF9 ) )
    {
    l_st_min_ms  =  1;
    }
else
    {
    l_valid_st_min = FALSE;
    }

if( l_valid_st_min != FALSE )
    {
    schedule_transfer_timeout( l_st_min_ms + TP_TASK_PERIOD_MS, p_timer );
    }
}
#endif

/*!*******************************************************************
*
* schedule a transfer timeout
*
* This function schedules a TP channel timeout. The timeout value is
* specified in milliseconds and is converted to task timer ticks. The
* specified timer is set to the timeout value, represented in periodic
* task timer ticks.
*
*********************************************************************/
static void
schedule_transfer_timeout
    (
    uint16              const timeout_ms,       //!< [in] timeout in milliseconds
    uint16            * const p_timer           //!< [in, out] ptr to timer to set
    )
{
uint16  l_task_tics;

/*------------------------------------------------------
Convert the timeout value in milliseconds to periodic
task timer ticks and set the timer.
------------------------------------------------------*/
#if(CANTP_DEBUG == TRUE)
//PRINTF("set timer value to %d,And time:%d\r\n",timeout_ms, g_global_runtime);
#endif
l_task_tics = (uint16) ( ( ( (float) timeout_ms ) / ( (float) TP_TASK_PERIOD_MS ) ) + 0.5 );

*p_timer = l_task_tics;
}

/*!*******************************************************************
*
* cancel a transfer timeout
*
* This function cancels a TP channel transfer timeout.
*
*********************************************************************/
static void
cancel_transfer_timeout
    (
    uint16            * const p_timer           //!< [in, out] ptr to timer to cancel
    )
{
/*------------------------------------------------------
Zero the timer.
------------------------------------------------------*/
#if(CANTP_DEBUG == TRUE)
//PRINTF("Canel timer----Time:%d\r\n",g_global_runtime);
#endif

*p_timer = 0;
}

/*!*******************************************************************
*
* process Send transfer completion
*
* This function processes completion of a TP channel Send transfer.
* The transfer may have completed successfully or unsuccessfully, as
* indicated by the result parameter. This function reverts the process
* state to Idle and notifies the application, regardless of the manner
* in which the transfer ended.
*
*********************************************************************/
static void
process_send_transfer_complete
    (
    tp_chan_info_t  const * const p_tp_chan_info,   //!< [in] ptr to TP channel info
    tp_n_result_t           const result,           //!< [in] Send transfer result
    tp_chan_index_t         const ch_index,         //!< [in] TP channel index
    can_hw_inst_t           const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_n_send_xfr_t * l_p_send_xfr;

/*------------------------------------------------------
Get the Send process data from the TP channel info.
Cancel a timeout if pending and revert the Send transfer
state to Idle.Notify the application of the Send
Transfer completion result.
------------------------------------------------------*/
l_p_send_xfr = p_tp_chan_info->p_send_xfr;
cancel_transfer_timeout( &( l_p_send_xfr->timer ) );
l_p_send_xfr->state = TP_NS_SEND_IDLE;

client_diag_tx_complete(result,hw_inst,ch_index);

#if 0
#ifdef DIAGNOSTICS_TP_CHANNEL_INDEX

if( DIAGNOSTICS_TP_CHANNEL_INDEX == ch_index )
    {
    can_diag_hook_transmit_complete( result,  *( p_tp_chan_info->p_recv_canid_index ), hw_inst );
    }
#endif

#ifdef LINKCARD_LIST_TP_CHANNEL_INDEX
else
    {
    /*need consider wehter function address*/
    client_diag_tx_complete(result,hw_inst,ch_index);
    //tp_app_hook_transmit_complete( result, ch_index, hw_inst );
    }
#else

//TBD tp_app_hook_transmit_complete( result, ch_index, hw_inst );

#endif
#endif
}

/*!*******************************************************************
*
* process Receive transfer completion
*
* This function processes completion of a TP channel Receive transfer.
* The transfer may have completed successfully or unsuccessfully, as
* indicated by the result parameter. This function reverts the process
* state to Idle and notifies the application, regardless of the manner
* in which the transfer ended. A pointer to the received data and the
* size of the data in bytes is passed to the application for the case
* of a successful transfer.
*
*********************************************************************/
static void
process_receive_transfer_complete
    (
    tp_chan_info_t  const * const p_tp_chan_info,   //!< [in] ptr to TP channel info
    uint8           const * const p_data,           //!< [in] ptr to TP message data
    uint16                  const num_bytes,        //!< [in] number of bytes in the payload
    tp_n_result_t           const result,           //!< [in] Receive transfer transfer result
    tp_chan_index_t         const ch_index,         //!< [in] TP channel index
    can_hw_inst_t           const hw_inst           //!< [in] CAN hardware instance
    )
{
tp_n_recv_xfr_t * l_p_recv_xfr;

/*------------------------------------------------------
Get the Receive state and status information for this
channel. Cancel any pending timeouts. Reset the receive
state to Idle. Notify the application of the Receiver
transfer completion result including passing the
received data for the case of a successful transfer.
------------------------------------------------------*/
l_p_recv_xfr = p_tp_chan_info->p_recv_xfr;
cancel_transfer_timeout( &( l_p_recv_xfr->timer ) );
l_p_recv_xfr->state = TP_NS_RECV_IDLE;

client_diag_rx_wrapper( result, p_data, num_bytes, ch_index );
}

