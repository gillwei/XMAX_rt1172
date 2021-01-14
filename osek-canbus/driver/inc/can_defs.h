/*!*******************************************************************
* @file CAN_defs.h
* @brief CAN Driver General Type and Bit Field Definitions
*
* This file contains general CAN Hardware layer and Driver layer type
* definitions, status definitions and bit field definitions that are
* used to implement CAN Stack software independent of the actual CAN
* controller hardware implementation. These definitions are used
* by all of the components in the OSEK CAN stack and by application
* clients as well in order to properly transact with the CAN stack.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
/*!*******************************************************************
*
* @ingroup can_drv
* @{
*
*********************************************************************/
#ifndef _CAN_DEFS_H
#define _CAN_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                            General use
--------------------------------------------------------------------*/
/*------------------------------------------------------
Macro to Ignore Passed Parameters that are not Used
------------------------------------------------------*/
#define CAN_IGNORE_PARAMETER( _param )      ( (void) ( !( _param ) ) )

/*------------------------------------------------------
Nop definition
------------------------------------------------------*/
#define  __nop()

/*------------------------------------------------------
Data Type Definition
------------------------------------------------------*/
typedef unsigned char         uint8;
typedef uint8                 uint8_t;
typedef uint8                 boolean;
typedef signed char           sint8;
typedef sint8                 sint8_t;
typedef unsigned short        uint16;
typedef uint16                uint16_t;
typedef unsigned int          uint32;
typedef uint32                uint32_t;
typedef unsigned long long    uint64;
typedef uint64                uint64_t;

/*------------------------------------------------------
General macros that may not be defined for the system
------------------------------------------------------*/
#ifndef TRUE
    #define TRUE    (1)
#endif

#ifndef FALSE
    #define FALSE   (0)
#endif

#ifndef NULL
    #define NULL    (0)
#endif

#ifndef NBITS_IN_BYTE
    #define NBITS_IN_BYTE           (8)
#endif

#ifndef SHIFT_ONE_BYTE
    #define SHIFT_ONE_BYTE          (8)
#endif

#ifndef SHIFT_TWO_BYTES
    #define SHIFT_TWO_BYTES         (16)
#endif

#ifndef SHIFT_THREE_BYTES
    #define SHIFT_THREE_BYTES       (24)
#endif

/*------------------------------------------------------
MISRA Compatible Mask Inversion
------------------------------------------------------*/
#ifndef SYS_MASK8_COMPLEMENT
    #define SYS_MASK8_COMPLEMENT( _mask )   ( (uint8)  ( ( _mask ) ^ 0xFF ) )
#endif

#ifndef SYS_MASK16_COMPLEMENT
    #define SYS_MASK16_COMPLEMENT( _mask )  ( (uint16) ( ( _mask ) ^ 0xFFFF ) )
#endif

#ifndef SYS_MASK32_COMPLEMENT
    #define SYS_MASK32_COMPLEMENT( _mask )  ( (uint32) ( ( _mask ) ^ 0xFFFFFFFF ) )
#endif

#ifndef SYS_MASK64_COMPLEMENT
    #define SYS_MASK64_COMPLEMENT( _mask )  ( (uint32) ( ( _mask ) ^ 0xFFFFFFFFFFFFFFFF ) )
#endif

/*------------------------------------------------------
Compatible Mask Inversion
------------------------------------------------------*/
#ifndef SYS_MASK8_BIT
    #define SYS_MASK8_BIT( bit )   ( (uint8)  ( ( bit ) & 0xFF ) )
#endif

#ifndef SYS_MASK16_BIT
    #define SYS_MASK16_BIT( bit )  ( (uint16) ( ( bit ) & 0xFFFF ) )
#endif

#ifndef SYS_MASK32_BIT
    #define SYS_MASK32_BIT( bit )  ( (uint32) ( ( bit ) & 0xFFFFFFFF ) )
#endif

#ifndef SYS_MASK64_BIT
    #define SYS_MASK64_BIT( bit )  ( (uint32) ( ( bit ) & 0xFFFFFFFFFFFFFFFF ) )
#endif

/*------------------------------------------------------
General CAN Constants
------------------------------------------------------*/
#define CAN_8BITS                       (8)
#define CAN_16BITS                      (16)
#define CAN_HEX_0F                      (0x0Fu)
#define CAN_HEX_F0                      (0xF0u)
#define CAN_HEX_FF                      (0xFFu)
#define CAN_HEX_00FF                    (0x00FFu)
#define CAN_HEX_16FF                    (0xFFFFu)
#define CAN_HEX_32_FF                   (0xFFFFFFFFu)
#define CAN_HEX_64_FF                   (0xFFFFFFFFFFFFFFFFu)

/*------------------------------------------------------
CAN Return Codes
------------------------------------------------------*/
typedef sint8   can_ret_code_t;
#define CAN_RC_OK                       ( (can_ret_code_t)  1 )
#define CAN_RC_SUCCESS                  ( (can_ret_code_t)  1 )
#define CAN_RC_TRUE                     ( (can_ret_code_t)  1 )
#define CAN_RC_FALSE                    ( (can_ret_code_t)  0 )
#define CAN_RC_NULL                     ( (can_ret_code_t)  0 )
#define CAN_RC_FAIL                     ( (can_ret_code_t)  0 )
#define CAN_RC_EMPTY                    ( (can_ret_code_t)  0 )
#define CAN_RC_ERROR                    ( (can_ret_code_t) -1 )
#define CAN_RC_INVALID_PARAM            ( (can_ret_code_t) -2 )
#define CAN_RC_INVALID_HANDLE           ( (can_ret_code_t) -3 )
#define CAN_RC_NULL_PTR                 ( (can_ret_code_t) -4 )
#define CAN_RC_INVALID_SERVICE          ( (can_ret_code_t) -5 )
#define CAN_RC_NOT_AVAILABLE            ( (can_ret_code_t) -6 )
#define CAN_RC_RX_OVERRUN               ( (can_ret_code_t) -7 )
#define CAN_RC_RXQ_OVERRUN              ( (can_ret_code_t) -7 )
#define CAN_RC_TXQ_OVERRUN              ( (can_ret_code_t) -8 )
#define CAN_RC_TMDQ_OVERRUN             ( (can_ret_code_t) -9 )
#define CAN_RC_BUSOFF_INIT_PNDG         ( (can_ret_code_t) -10 )

/*--------------------------------------------------------------------
                            Hardware Driver Layer
--------------------------------------------------------------------*/
/*------------------------------------------------------
Maximum CAN Frame Data Length (per the protocol)
------------------------------------------------------*/
#define CAN_MAX_DATA_LENGTH             (8)

/*------------------------------------------------------
Message Buffer
------------------------------------------------------*/

#define CAN_HMB_RX_APP                  (18 + 1)
#define CAN_HMB_RX_DIAG_START           (0)
#define CAN_HMB_RX_DIAG_ALL             (7)
#define CAN_HMB_RX_ALL                  (18 + 1 + 7)                    //!<For CAN frame receiving(18 for App,5 for Diag and one for NM)
#define CAN_HMB_TX_ALL                  (CAN_HMB_ALL - CAN_HMB_RX_ALL)  //!<For CAN frame transmitting,others except Rx MBs

#define CAN_HMB_ALL                     (64)                            //!<The total MBs is 64
#define CAN_HMB_TX_START                CAN_HMB_RX_ALL                  //!<Tx Message Buffers flows Rx Message Boxes
#define CAN_HMB_TX_MAX                  CAN_HMB_ALL

#define CAN_RXMSG_FIFO_1                (0x80u)
#define CAN_RXMSG_REMOTE                (0x02u)
#define CAN_RXMSG_EXTENDED              (0x01u)

#define CAN_RXMSG_DATA                  (0x00u)
#define CAN_RXMSG_FIFO_0                (0x00u)
#define CAN_RXMSG_STANDARD              (0x00u)

#define CAN_RXMSG_STD_EXT_BIT           (0x01u)
#define CAN_RXMSG_DAT_REM_BIT           (0x02u)
#define CAN_RXMSG_FIFO_0_1_BIT          (0x04u)

/*------------------------------------------------------
CAN Protocol Error Warning and Error Passive Counts
------------------------------------------------------*/
#define CAN_ERROR_WARNING_COUNT         (96)
#define CAN_ERROR_ACTIVE_COUNT          (127)
#define CAN_ERROR_PASSIVE_COUNT         (128)

/*------------------------------------------------------
Hardware Layer Status Bit Field Definitions
------------------------------------------------------*/
#define CAN_HW_NORMAL_MODE              (0x00000001u)
#define CAN_HW_FREEZE_MODE              (0x00000002u)
#define CAN_HW_LISTEN_ONLY_MODE         (0x00000004u)
#define CAN_HW_LOOP_BACK_MODE           (0x00000008u)
#define CAN_HW_MODULE_DISABLE_MODE      (0x00000010u)
#define CAN_HW_STOP_MODE                (0x00000020u)

#define CAN_HW_ONLINE                   (0x00000040u)
#define CAN_HW_INITOK                   (0x00000080u)
#define CAN_HW_ERROR_STATUS             (0x00000100u)
#define CAN_HW_WAKEUP                   (0x00000200u)
#define CAN_HW_BUS_ACTIVE               (0x00000400u)

/*------------------------------------------------------
Hardware Layer Error Status Bit Field Definitions
------------------------------------------------------*/
#define CAN_HW_ERR_BUSOFF               (0x00000001u)
#define CAN_HW_ERR_RX_OVERRUN           (0x00000002u)
#define CAN_HW_ERR_RXQ_OVERRUN          (0x00000004u)
#define CAN_HW_ERR_TXQ_OVERRUN          (0x00000008u)
#define CAN_HW_ERR_TX_PASSIVE           (0x00000010u)
#define CAN_HW_ERR_RX_PASSIVE           (0x00000020u)
#define CAN_HW_ERR_TX_ACTIVE            (0x00000040u)
#define CAN_HW_ERR_RX_ACTIVE            (0x00000080u)
#define CAN_HW_ERR_TX_WARNING           (0x00000100u)
#define CAN_HW_ERR_RX_WARNING           (0x00000200u)

/*------------------------------------------------------
CAN Hardware Instance
------------------------------------------------------*/
typedef uint8                           can_hw_inst_t;

/*------------------------------------------------------
Just use CAN2
------------------------------------------------------*/
#define CAN_CONTROLLER_2                (can_hw_inst_t)(0)

/*------------------------------------------------------
CAN Hardware Message Buffer
------------------------------------------------------*/
typedef uint8                           can_hmb_t;

/*------------------------------------------------------
CAN Hardware Message Buffer
------------------------------------------------------*/
typedef uint32                          can_status_t;

/*------------------------------------------------------
CAN Hardware Message Buffer Mask
------------------------------------------------------*/
typedef uint64                          can_hmb_mask_t;

/*!-----------------------------------------------------
The can_rmd_t data structure is used to store a received
CAN protocol message, including its CAN ID, data payload
(8 bytes maximum), Data Length Code, format,type (e.g.
frame type, CAN ID type, etc) as well as the CAN
controller receive filter vector that qualified the
received CAN frame.
------------------------------------------------------*/
typedef struct tagCAN_RMD_TYPE                  //<! receive message data structure
    {
    uint32          identifier;                 //<! frame Identifier
    uint8           data[CAN_MAX_DATA_LENGTH];  //<! payload data
    uint8           dlc;                        //<! Data Length Code (number of bytes)
    uint8           format;                     //<! format (e.g. standard, extended, data, remote)
    uint8           type;                       //<! type   (e.g. data, remote)
    uint8           vector;                     //<! receive filter vector
    uint32          timestamp;                 //<! Received message time stamp

    } can_rmd_t;

/*------------------------------------------------------
FlexCAN frame type.
------------------------------------------------------*/
typedef enum tagFLEXCAN_FRAME_TYPE
    {
    CAN_DATA_MSG_TYPE   = 0x0U, //!<Data frame type attribute.
    CAN_REMOTE_MSG_TYPE = 0x1U, //!<Remote frame type attribute.

    } flexcan_frame_type_t;

/*------------------------------------------------------
FlexCAN frame format.
Standard <=> 11 Bit CAN Identifier
Extended <=> 29 Bit CAN Identifier
------------------------------------------------------*/
typedef enum tagFLEXCAN_FRAME_FORMAT_TYPE
    {
    CAN_STANDARD_MSG_TYPE = 0x0U, //!<Standard frame format attribute.
    CAN_EXTENDED_MSG_TYPE = 0x1U, //!<Extend frame format attribute.

    } flexcan_frame_format_t;

/*--------------------------------------------------------------------
                            Software Driver Layer
--------------------------------------------------------------------*/
/*------------------------------------------------------
Driver Layer Status Bit Field Definitions
------------------------------------------------------*/
#define CAN_DRV_TX_SUSPEND              (0x02u)
#define CAN_DRV_RX_SUSPEND              (0x01u)

/*------------------------------------------------------
CAN Ignore Transmit Frame Handle
------------------------------------------------------*/
#define CAN_IGNORE_TMD_FRAME_HANDLE     (0xFFFF)

/*------------------------------------------------------
Driver Layer Error Status Bit Field Definitions
------------------------------------------------------*/
#define CAN_DRV_ERR_TMDQ                (0x20u)
#define CAN_DRV_ERR_TMDQ_OVERRUN        (0x10u)
#define CAN_DRV_ERR_TXQ                 (0x08u)
#define CAN_DRV_ERR_TXQ_OVERRUN         (0x04u)
#define CAN_DRV_ERR_RXQ                 (0x02u)
#define CAN_DRV_ERR_RXQ_OVERRUN         (0x01u)

#define CAN_DRV_ERRORS (CAN_DRV_ERR_TMDQ            |   \
                        CAN_DRV_ERR_TMDQ_OVERRUN    |   \
                        CAN_DRV_ERR_TXQ             |   \
                        CAN_DRV_ERR_TXQ_OVERRUN     |   \
                        CAN_DRV_ERR_RXQ             |   \
                        CAN_DRV_ERR_RXQ_OVERRUN)

/*------------------------------------------------------
CAN Service
------------------------------------------------------*/
typedef uint16   can_svc_t;
#define CAN_SVC_ONLINE                  ( 0)
#define CAN_SVC_OFFLINE                 ( 1)
#define CAN_SVC_POWER_DOWN              ( 2)
#define CAN_SVC_SLEEP                   ( 3)
#define CAN_SVC_WAKEUP                  ( 4)
#define CAN_SVC_BUS_IS_ACTIVE           ( 5)
#define CAN_SVC_BUS_IS_SLEEPING         ( 6)
#define CAN_SVC_HW_IS_SLEEPING          ( 7)
#define CAN_SVC_BUS_IS_OPEN             ( 8)
#define CAN_SVC_TX_IS_PENDING           ( 9)
#define CAN_SVC_TX_FLUSH                (10)
#define CAN_SVC_RX_FLUSH                (11)
#define CAN_SVC_ENABLE_TX_TIMEOUT       (12)
#define CAN_SVC_DISABLE_TX_TIMEOUT      (13)
#define CAN_SVC_SUSPEND_ALL             (14)
#define CAN_SVC_SUSPEND_TX              (15)
#define CAN_SVC_SUSPEND_RX              (16)
#define CAN_SVC_RESUME_ALL              (17)
#define CAN_SVC_RESUME_TX               (18)
#define CAN_SVC_RESUME_RX               (19)
#define CAN_SVC_ENABLE_RX_INT           (20)
#define CAN_SVC_DISABLE_RX_INT          (21)
#define CAN_SVC_ENABLE_INTS             (22)
#define CAN_SVC_DISABLE_INTS            (23)
#define CAN_SVC_ENABLE_TX_PRI_MODE      (24)
#define CAN_SVC_DISABLE_TX_PRI_MODE     (25)
#define CAN_SVC_ENABLE_LOOPBACK         (26)
#define CAN_SVC_DISABLE_LOOPBACK        (27)
#define CAN_SVC_ENABLE_SILENTMODE       (28)
#define CAN_SVC_DISABLE_SILENTMODE      (29)
#define CAN_SVC_ENABLE_AUTOTX           (30)
#define CAN_SVC_DISABLE_AUTOTX          (31)
#define CAN_SVC_ENABLE_TX_INT           (32)
#define CAN_SVC_DISABLE_TX_INT          (33)

/*------------------------------------------------------
CAN Initialization Mode
------------------------------------------------------*/
typedef uint8   can_init_mode_t;
#define CAN_INIT_MODE_COLD              (0x00)
#define CAN_INIT_MODE_WARM              (0x01)
#define CAN_INIT_MODE_VERIFY            (0x02)

/*------------------------------------------------------
CAN Get Status Mode Type
------------------------------------------------------*/
typedef uint8   can_get_stat_mode_t;
#define CAN_GET_DRVR_STATUS             (0x0)
#define CAN_GET_DRVR_ERROR_STATUS       (0x1)
#define CAN_GET_HW_STATUS               (0x2)
#define CAN_GET_HW_ERROR_STATUS         (0x3)
#define CAN_GET_HW_INT_CFG_STATUS       (0x4)
#define CAN_GET_CLEAR_DRVR_ERROR_STATUS (0x5)
#define CAN_GET_CLEAR_HW_ERROR_STATUS   (0x6)

/*------------------------------------------------------
CAN Exception
------------------------------------------------------*/
typedef uint8   can_exception_t;
#define CAN_EX_BUSOFF                   (0)
#define CAN_EX_RX_OVERRUN               (1)
#define CAN_EX_RXQ_OVERRUN              (2)
#define CAN_EX_TXQ_ERROR                (3)
#define CAN_EX_TMDQ_ERROR               (4)
#define CAN_EX_RXQ_ERROR                (5)
#define CAN_EX_TX_ERROR_PASSIVE         (6)
#define CAN_EX_RX_ERROR_PASSIVE         (7)
#define CAN_EX_TX_ERROR_ACTIVE          (8)
#define CAN_EX_RX_ERROR_ACTIVE          (9)
#define CAN_EX_TX_ERROR_WARNING         (10)
#define CAN_EX_RX_ERROR_WARNING         (11)

/*------------------------------------------------------
CAN Frame Trasmission option
------------------------------------------------------*/
typedef uint8   can_frame_format_type_t;
#define CAN_TXMSG_QUEUED_TMD            (0x04u)
#define CAN_TXMSG_REMOTE                (0x02u)
#define CAN_TXMSG_EXTENDED              (0x01u)
#define CAN_TXMSG_STANDARD              (0x00u)

/*------------------------------------------------------
CAN Operational Mode
------------------------------------------------------*/
typedef uint8   can_op_mode_t;
#define CAN_OP_MODE_ONLINE              ( 0)
#define CAN_OP_MODE_OFFLINE             ( 1)
#define CAN_OP_MODE_DEFERRED_INIT_PNDG  ( 2)
#define CAN_OP_MODE_POWER_DOWN          ( 3)
#define CAN_OP_MODE_SLEEP               ( 4)
#define CAN_OP_MODE_WAKEUP              ( 5)
#define CAN_OP_MODE_SUSPEND_ALL         ( 6)
#define CAN_OP_MODE_SUSPEND_TX          ( 7)
#define CAN_OP_MODE_SUSPEND_RX          ( 8)
#define CAN_OP_MODE_RESUME_ALL          ( 9)
#define CAN_OP_MODE_RESUME_TX           (10)
#define CAN_OP_MODE_RESUME_RX           (11)
#define CAN_OP_MODE_ENABLE_INTS         (12)
#define CAN_OP_MODE_DISABLE_INTS        (13)
#define CAN_OP_MODE_ENABLE_RX_INT       (14)
#define CAN_OP_MODE_DISABLE_RX_INT      (15)
#define CAN_OP_MODE_ENABLE_LOOPBACK     (16)
#define CAN_OP_MODE_DISABLE_LOOPBACK    (17)
#define CAN_OP_MODE_ENABLE_SILENTMODE   (18)
#define CAN_OP_MODE_DISABLE_SILENTMODE  (19)

/*------------------------------------------------------
CAN Initialization Mode
------------------------------------------------------*/
typedef uint8   can_init_mode_t;
#define CAN_INIT_MODE_COLD              (0x00)
#define CAN_INIT_MODE_WARM              (0x01)
#define CAN_INIT_MODE_VERIFY            (0x02)

/*------------------------------------------------------
CAN Transmit Message Handle
------------------------------------------------------*/
typedef uint16  can_tmh_t;

/*!-----------------------------------------------------
The can_tmd_t data structure is used to define a CAN
protocol message for transmission. The transmit
information includes the CAN ID, pointer to the data
payload (8 bytes maximum), Data Length Code, qualifiers
(e.g. frame type (data or remote), CAN ID type (standard
or extended, etc)) and a transmit message handle for
frame identification when a message transmission
completes successfully.
------------------------------------------------------*/
typedef struct tagCAN_TMD_TYPE                  //!< transmit message data structure
    {
    uint32          identifier;                 //!< frame Identifier
    uint8   const * p_data;                     //!< pointer to frame data
    uint8           dlc;                        //!< Data Length Code (number of bytes)
    uint8           options;                    //!< frame transmission options
    can_tmh_t       handle;                     //!< transmit message handler

    } can_tmd_t;

/*------------------------------------------------------
CAN Queued Transmit Message Data Structure
------------------------------------------------------*/
typedef struct tagCAN_QTMD_TYPE                     //!< transmit data queue obeject
    {
    can_tmd_t       tmd;                            //!< transmit message data
    uint8           data[CAN_MAX_DATA_LENGTH];      //!< transmit data payload

    } can_qtmd_t;

/*------------------------------------------------------
CAN Queue Status Structure
------------------------------------------------------*/
typedef struct tagCAN_QSTATUS_TYPE                  //!< queue status (FIFO queue)
    {
    volatile uint8          next_in;                //!< next in index
    volatile uint8          next_out;               //!< next out index
    volatile uint8          qnum;                   //!< number in the queue
    volatile uint8          qmax_num;               //!< queue high water mark

    } can_qstatus_t;

/*------------------------------------------------------
CAN Transmit Queue Info
------------------------------------------------------*/
typedef struct tagCAN_TXQ_INFO_TYPE                 //!< transmit queue info
    {
    can_tmd_t     const * * const pp_tmd;           //!< pointer to pointer to Transmit Data object
    can_qstatus_t         * const p_txq_status;     //!< pointer to queue status
    uint8                   const txq_size;         //!< size of the queue

    } can_txq_info_t;

/*------------------------------------------------------
CAN TMD Queue Info
------------------------------------------------------*/
typedef struct tagCAN_TMDQ_INFO_TYPE                //!< transmit data queue info
    {
    can_qtmd_t            * const p_tmd;            //!< pointer to Transmit Data object
    can_qstatus_t         * const p_tmdq_status;    //!< pointer to queue status
    uint8                   const tmdq_size;        //!< size of the queue

    } can_tmdq_info_t;

/*------------------------------------------------------
CAN Rx Queue Info
------------------------------------------------------*/
typedef struct tagCAN_RXQ_INFO_TYPE                 //!< receive queue info
    {
    can_rmd_t             * const p_rxq;            //!< pointer to receive queue
    can_qstatus_t         * const p_rxq_status;     //!< pointer to queue status
    uint8                   const rxq_size;         //!< size of the queue

    } can_rxq_info_t;

/*------------------------------------------------------
CAN Queue Info Pointers
------------------------------------------------------*/
typedef struct tagCAN_QINFO_PTRS_TYPE               //!< pointers to all queue info
    {
    can_txq_info_t  const * const p_txq_info;       //!< pointer transmit queue info
    can_tmdq_info_t const * const p_tmdq_info;      //!< pointer to transmit data queue info
    can_rxq_info_t  const * const p_rxq_info;       //!< pointer to receive queue info

    } can_qinfo_ptrs_t;

/*------------------------------------------------------
CAN frame ID
------------------------------------------------------*/
typedef uint32                  can_msg_id_t;

/*------------------------------------------------------
CAN frame size
------------------------------------------------------*/
typedef uint32                  can_msg_size_t;

/*------------------------------------------------------
CAN frame data
------------------------------------------------------*/
typedef uint8                   can_msg_data_t;

/*------------------------------------------------------
can message type
------------------------------------------------------*/
typedef struct
    {
    can_msg_id_t      id;
    can_msg_size_t    size;
    can_msg_data_t    data[CAN_MAX_DATA_LENGTH];
    }__attribute__ ( ( packed ) )can_msg_t;

#ifdef __cplusplus
}
#endif

#endif /* _CAN_DEFS_H */
