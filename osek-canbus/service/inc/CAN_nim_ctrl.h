/*!*******************************************************************
* @file CAN_nim_ctrl.h
* @brief CAN Stack Network Interface Control Manager API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack_nim_ctrl
* @{
*
*********************************************************************/
#ifndef _CAN_NIM_CTRL_H
#define _CAN_NIM_CTRL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "MIMXRT1176_cm7.h"

/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/
#define EXAMPLE_CAN CAN2

#define RX_MESSAGE_BUFFER_NUM (9)
#define TX_MESSAGE_BUFFER_NUM (8)
#define DLC (8)
#define USE_IMPROVED_TIMING_CONFIG (1)
#define DEMO_FORCE_CAN_SRC_OSC (1)

#define SET_CAN_QUANTUM 0
#define PSEG1 3
#define PSEG2 2
#define PROPSEG 1

/* Select OSC24Mhz as master flexcan clock source */
#define FLEXCAN_CLOCK_SOURCE_SELECT (1U)
/* Clock divider for master flexcan clock source */
#define FLEXCAN_CLOCK_SOURCE_DIVIDER (1U)
/* Get frequency of flexcan clock */
#define EXAMPLE_CAN_CLK_FREQ ((CLOCK_GetRootClockFreq(kCLOCK_Root_Can2) / 100000U) * 100000U)
/* Fix MISRA_C-2012 Rule 17.7. */
#define LOG_INFO (void)PRINTF

/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/
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
typedef unsigned long long    uint64;
typedef uint64                uint64_t;

/*------------------------------------------------------
FlexCAN frame format.
Standard <=> 11 Bit CAN Identifier
Extended <=> 29 Bit CAN Identifier
------------------------------------------------------*/
typedef enum tagFLEXCAN_FRAME_FORMAT_TYPE
    {
    CAN_STANDARD_MSG_TYPE = 0x0U, //!<Standard frame format attribute.
    CAN_EXTENDED_MSG_TYPE = 0x1U, //!<Extend frame format attribute.

    } flexcan_frame_frmt_t;

/*------------------------------------------------------
FlexCAN message buffer CODE FOR Rx buffers.
------------------------------------------------------*/
typedef enum tagFLEXCAN_MB_CODE_RX_TYPE
    {
    FLEXCAN_RXMB_INACTIVE = 0x0, //!<MB is not active.
    FLEXCAN_RXMB_FULL     = 0x2, //!<MB is full.
    FLEXCAN_RXMB_EMPTY    = 0x4, //!<MB is active and empty.
    FLEXCAN_RXMB_OVERRUN  = 0x6, //!<MB is overwritten into a full buffer.
    FLEXCAN_RXMB_BUSY     = 0x8, //!<FlexCAN is updating the contents of the MB.The CPU must not access the MB.
    FLEXCAN_RXMB_RANSWER  = 0xA, //!<A frame was configured to recognize a Remote Request Frame and transmit a Response Frame in return.
    FLEXCAN_RXMB_NOTUSED  = 0xF, //!<Not used.

    } flexcan_mb_code_rx_t;

/*------------------------------------------------------
FlexCAN frame type.
------------------------------------------------------*/
typedef enum tagFLEXCAN_FRAME_TYPE
    {
    CAN_DATA_MSG_TYPE   = 0x0U, //!<Data frame type attribute.
    CAN_REMOTE_MSG_TYPE = 0x1U, //!<Remote frame type attribute.

    } flexcan_frm_type_t;

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

typedef struct tagCAN_RMD_TYPE                  //<! receive message data structure
    {
    uint32          identifier;                 //<! frame Identifier
    uint8           data[8];                    //<! payload data
    uint8           dlc;                        //<! Data Length Code (number of bytes)
    uint8           format;                     //<! format (e.g. standard, extended, data, remote)
    uint8           type;                       //<! type   (e.g. data, remote)
    uint8           vector;                     //<! receive filter vector
    uint32          timestamp;                 //<! Received message time stamp

    } can_rmd_t;

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
void vCAN_nim_create_task
    (
    void
    );

can_ret_code_t
can_hw_receive_rx_mb
    (
    CAN_Type              * const p_flexcan_hw_regs, //!< [in] ptr to FlexCAN H/W registers
    can_rmd_t             * const p_rmd,             //!< [in, out] ptr to receive message write buffer
    uint8                   const rx_mb_index        //!< [in] Index of FlexCAN receive Message Buffer
    );

#ifdef __cplusplus
}
#endif

#endif /* _CAN_NIM_CTRL_H */
