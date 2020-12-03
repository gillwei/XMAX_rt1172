/*!*******************************************************************
* @file can_flexcan.h
* @brief RT1170 FlexCAN Specific Header File
*
* This file contains RT1170 FlexCAN CAN controller specific type
* definitions and macros that facilitate the implementation of
* the FlexCAN hardware layer driver.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @defgroup can_hw_drv RT1170 FlexCAN Controller Hardware Driver
* @ingroup can_drv
* @{
*
*********************************************************************/
#ifndef _CAN_FLEXCAN_H_
#define _CAN_FLEXCAN_H_

/*----------------------------------------------------------------
                            GENERAL INCLUDES
----------------------------------------------------------------*/
#include "can_defs.h"

#include "fsl_common.h"

/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/
/*----------------------------------------------------------
FlexCAN Tx and Rx Max Number
----------------------------------------------------------*/
#define MAX_HW_OBJECTS  CAN_HMB_ALL
#define MAX_TX_OBJECTS  CAN_HMB_TX_ALL
#define MAX_RX_OBJECTS  CAN_HMB_RX_ALL

/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/
/*------------------------------------------------------
FlexCAN Register Struct
------------------------------------------------------*/
typedef CAN_Type flexcan_regs_t;

/*------------------------------------------------------
FlexCAN clock source.
------------------------------------------------------*/
typedef enum tagFLEXCAN_CLOCK_SOURCE_TYPE
    {
    FLEXCAN_CLKSRC_OSC  = 0x0U, //!<FlexCAN Protocol Engine clock from Oscillator.
    FLEXCAN_CLKSRC_PERI = 0x1U, //!<FlexCAN Protocol Engine clock from Peripheral Clock.
    FLEXCAN_CLKSRC0     = 0x0U, //!<FlexCAN Protocol Engine clock selected by user as SRC == 0.
    FLEXCAN_CLKSRC1     = 0x1U, //!<FlexCAN Protocol Engine clock selected by user as SRC == 1.

    } flexcan_clock_source_t;

/*------------------------------------------------------
FlexCAN wake up source.
------------------------------------------------------*/
typedef enum tagFLEXCAN_WAKE_UP_SOURCE_TYPE
    {
    FLEXCAN_WAKEUP_SRC_UNFILTERED = 0x0U, //!<FlexCAN uses unfiltered Rx input to detect edge.
    FLEXCAN_WAKEUP_SRC_FILTERED   = 0x1U, //!<FlexCAN uses filtered Rx input to detect edge.

    } flexcan_wake_up_source_t;

/*------------------------------------------------------
FlexCAN interrupt configuration structure, default settings all disabled.
------------------------------------------------------*/
typedef enum tagFLEXCAN_INT_EN_TYPE
    {
    FLEXCAN_BUSOFF_INT_EN    = CAN_CTRL1_BOFFMSK_MASK, //!<Bus Off interrupt.
    FLEXCAN_ERROR_INT_EN     = CAN_CTRL1_ERRMSK_MASK,  //!<Error interrupt.
    FLEXCAN_RXWARNING_INT_EN = CAN_CTRL1_RWRNMSK_MASK, //!<Rx Warning interrupt.
    FLEXCAN_TXWARNING_INT_EN = CAN_CTRL1_TWRNMSK_MASK, //!<Tx Warning interrupt.
    FLEXCAN_WAKEUP_INT_EN    = CAN_MCR_WAKMSK_MASK,    //!<Wake Up interrupt.

    } flexcan_int_en_t;

/*------------------------------------------------------
FlexCAN error and status flags.
------------------------------------------------------*/
typedef enum tagFLEXCAN_ERROR_STATUS_FLAGS_TYPE
    {
    FLEXCAN_SYNCH_FLAG              = CAN_ESR1_SYNCH_MASK,   //!<CAN Synchronization Status.
    FLEXCAN_TXWARNING_INT_FLAG      = CAN_ESR1_TWRNINT_MASK, //!<Tx Warning Interrupt Flag.
    FLEXCAN_RXWARNING_INT_FLAG      = CAN_ESR1_RWRNINT_MASK, //!<Rx Warning Interrupt Flag.
    FLEXCAN_TXERRORWARNING_FLAG     = CAN_ESR1_TXWRN_MASK,   //!<Tx Error Warning Status.
    FLEXCAN_RXERRORWARNING_FLAG     = CAN_ESR1_RXWRN_MASK,   //!<Rx Error Warning Status.
    FLEXCAN_IDLE_FLAG               = CAN_ESR1_IDLE_MASK,    //!<CAN IDLE Status Flag.
    FLEXCAN_FAULTCONFINEMENT_FLAG   = CAN_ESR1_FLTCONF_MASK, //!<Fault Confinement State Flag.
    FLEXCAN_TRANSMITTING_FLAG       = CAN_ESR1_TX_MASK,      //!<FlexCAN In Transmission Status.
    FLEXCAN_RECEIVING_FLAG          = CAN_ESR1_RX_MASK,      //!<FlexCAN In Reception Status.
    FLEXCAN_BUSOFF_INT_FLAG         = CAN_ESR1_BOFFINT_MASK, //!<Bus Off Interrupt Flag.
    FLEXCAN_ERROR_INT_FLAG          = CAN_ESR1_ERRINT_MASK,  //!<Error Interrupt Flag.
    FLEXCAN_WAKEUP_INT_FLAG         = CAN_ESR1_WAKINT_MASK,  //!<Wake-Up Interrupt Flag.
    FLEXCAN_ERROR_FLAG              = (int)(CAN_ESR1_BIT1ERR_MASK | CAN_ESR1_BIT0ERR_MASK | CAN_ESR1_ACKERR_MASK | CAN_ESR1_CRCERR_MASK | CAN_ESR1_FRMERR_MASK | CAN_ESR1_STFERR_MASK), //!<All FlexCAN Error Status.

    } flexcan_error_status_flags_t;

/*------------------------------------------------------
FlexCAN error flags.
------------------------------------------------------*/
typedef enum tagFLEXCAN_ERROR_FLAGS_TYPE
    {
    FLEXCAN_STUFFING_ERR_FLAG = CAN_ESR1_STFERR_MASK,  //!<Stuffing Error.
    FLEXCAN_FORM_ERR_FLAG     = CAN_ESR1_FRMERR_MASK,  //!<Form Error.
    FLEXCAN_CRC_ERR_FLAG      = CAN_ESR1_CRCERR_MASK,  //!<Cyclic Redundancy Check Error.
    FLEXCAN_ACK_ERR_FLAG      = CAN_ESR1_ACKERR_MASK,  //!<Received no ACK on transmission.
    FLEXCAN_BIT0_ERR_FLAG     = CAN_ESR1_BIT0ERR_MASK, //!<Unable to send dominant bit.
    FLEXCAN_BIT1_ERR_FLAG     = CAN_ESR1_BIT1ERR_MASK, //!<Unable to send recessive bit.

    } flexcan_error_flags_t;

/*------------------------------------------------------
FlexCAN message frame structure.
------------------------------------------------------*/
typedef struct tagFLEXCAN_TYPE
    {
    struct
        {
        uint32_t timestamp : 16; //!<FlexCAN internal Free-Running Counter Time Stamp.
        uint32_t length : 4;     //!<CAN frame payload length in bytes(Range: 0~8).
        uint32_t type : 1;       ///!<CAN Frame Type(DATA or REMOTE).
        uint32_t format : 1;     //!<CAN Frame Identifier(STD or EXT format).
        uint32_t : 1;            //!<Reserved.
        uint32_t idhit : 9;      //!<CAN Rx FIFO filter hit id(This value is only used in Rx FIFO receive mode).
        };
    struct
        {
        uint32_t id : 29;        //!<CAN Frame Identifier, should be set using FLEXCAN_ID_EXT() or FLEXCAN_ID_STD() macro.
        uint32_t : 3;            //!<Reserved.
        };
    union
        {
        struct
            {
            uint32_t dataWord0; //!<CAN Frame payload word0.
            uint32_t dataWord1; //!<CAN Frame payload word1.
            };
        struct
            {
            uint8_t dataByte3; //!<CAN Frame payload byte3.
            uint8_t dataByte2; //!<CAN Frame payload byte2.
            uint8_t dataByte1; //!<CAN Frame payload byte1.
            uint8_t dataByte0; //!<CAN Frame payload byte0.
            uint8_t dataByte7; //!<CAN Frame payload byte7.
            uint8_t dataByte6; //!<CAN Frame payload byte6.
            uint8_t dataByte5; //!<CAN Frame payload byte5.
            uint8_t dataByte4; //!<CAN Frame payload byte4.
            };
        };

    } flexcan_frame_t;

/*------------------------------------------------------
FlexCAN protocol timing characteristic configuration structure.
------------------------------------------------------*/
typedef struct tagFLEXCAN_TIMING_CONFIG_TYPE
    {
    uint16_t preDivider; //!<Clock Pre-scaler Division Factor.
    uint8_t  rJumpwidth;  //!<Re-sync Jump Width.
    uint8_t  phaseSeg1;   //!<Phase Segment 1.
    uint8_t  phaseSeg2;   //!<Phase Segment 2.
    uint8_t  propSeg;     //!<Propagation Segment.

    } flexcan_timing_config_t;

/*------------------------------------------------------
FlexCAN module configuration structure.
------------------------------------------------------*/
typedef struct tagFLEXCAN_CONFIG_TYPE
    {
    uint32_t source_clk;                  //!<FlexCAN soutce clock.
    uint32_t baudRate;                    //!<FlexCAN baud rate in bps.
    flexcan_clock_source_t   clkSrc;      //!<Clock source for FlexCAN Protocol Engine.
    flexcan_wake_up_source_t wakeupSrc;   //!<Wake up source selection.
    uint8_t maxMbNum;                     //!<The maximum number of Message Buffers used by user.
    bool enableLoopBack;                  //!<Enable or Disable Loop Back Self Test Mode.
    bool enableTimerSync;                 //!<Enable or Disable Timer Synchronization.
    bool enableSelfWakeup;                //!<Enable or Disable Self Wakeup Mode.
    bool enableIndividMask;               //!<Enable or Disable Rx Individual Mask.
    bool disableSelfReception;            //!<Enable or Disable Self Reflection.
    bool enableListenOnlyMode;            //!<Enable or Disable Listen Only Mode.
    bool enableDoze;                      //!<Enable or Disable Doze Mode.
    flexcan_timing_config_t timingConfig; //!<Protocol timing .

    } flexcan_config_t;

/*------------------------------------------------------
FlexCAN Transmit Message Buffer configuration structure
------------------------------------------------------*/
typedef struct tagFLEXCAN_TX_MB_CONFIG_TYPE
    {
    uint8            can_tx_mb_start_idx;
    uint8            can_tx_mb_num;

    } flexcan_tx_mb_config_t;

/*------------------------------------------------------
FlexCAN Receive Message Buffer configuration structure
------------------------------------------------------*/
typedef struct tagFLEXCAN_RX_MB_CONFIG_TYPE
    {
    uint32_t id;                   //!<CAN Message Buffer Frame Identifier, should be set using FLEXCAN_ID_EXT() or FLEXCAN_ID_STD() macro.
    uint32_t idmsk;                //!<CAN Message Buffer Frame Identifier filter,
    flexcan_frame_format_t format; //!<CAN Frame Identifier format(Standard of Extend).
    flexcan_frame_type_t   type;   //!<CAN Frame Type(Data or Remote).

    } flexcan_rx_mb_config_t;

/*------------------------------------------------------
FlexCAN Message Buffer transfer.
------------------------------------------------------*/
typedef struct tagFLEXCAN_MB_TRANSFER_TYPE
    {
    flexcan_frame_t *frame; //!<The buffer of CAN Message to be transfer.
    uint8_t mbIdx;          //!<The index of Message buffer used to transfer Message.

    } flexcan_mb_transfer_t;

/*----------------------------------------------------------
FlexCAN Hardware Initialization
----------------------------------------------------------*/
typedef struct tagCCAN_HW_INIT_T
    {
    flexcan_tx_mb_config_t  mb_tx_config;
    flexcan_rx_mb_config_t  mb_rx_config[CAN_HMB_RX_ALL];

    } flexcan_hw_init_t;

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
#if defined(__cplusplus)
extern "C" {
#endif

static inline uint32_t flexcan_GetStatusFlags
    (
    flexcan_regs_t      *p_flexcan_regs
    )
{
return p_flexcan_regs->ESR1;
}

static inline void flexcan_ClearStatusFlags
    (
    flexcan_regs_t      *p_flexcan_regs,
    uint32_t             mask
    )
{
/*------------------------------------------------------
Write 1 to clear status flag.
------------------------------------------------------*/
p_flexcan_regs->ESR1 = mask;
}

static inline void flexcan_GetBusErrCount
    (
    flexcan_regs_t      *p_flexcan_regs,
    uint8_t             *txErrBuf,
    uint8_t             *rxErrBuf
    )
{
if(NULL != txErrBuf)
    {
    *txErrBuf = (uint8_t)( ( p_flexcan_regs->ECR & CAN_ECR_TXERRCNT_MASK ) >> CAN_ECR_TXERRCNT_SHIFT );
    }

if(NULL != rxErrBuf)
    {
    *rxErrBuf = (uint8_t)( ( p_flexcan_regs->ECR & CAN_ECR_RXERRCNT_MASK ) >> CAN_ECR_RXERRCNT_SHIFT );
    }
}

static inline void flexcan_EnableInterrupts
    (
    flexcan_regs_t      *p_flexcan_regs,
    uint32_t             mask
    )
{
if( (uint32_t)FLEXCAN_WAKEUP_INT_EN == ( mask & (uint32_t)FLEXCAN_WAKEUP_INT_EN ) )
    {
    p_flexcan_regs->MCR |= CAN_MCR_WAKMSK_MASK;
    }
/*------------------------------------------------------
Solve others.
------------------------------------------------------*/
p_flexcan_regs->CTRL1 |= ( mask & ( ~( (uint32_t)FLEXCAN_WAKEUP_INT_EN ) ) );
}

static inline void flexcan_DisableInterrupts
    (
    flexcan_regs_t      *p_flexcan_regs,
    uint32_t             mask
    )
{
/*------------------------------------------------------
Solve Wake Up Interrupt.
------------------------------------------------------*/
if((uint32_t)FLEXCAN_WAKEUP_INT_EN == ( mask & (uint32_t)FLEXCAN_WAKEUP_INT_EN ) )
    {
    p_flexcan_regs->MCR &= ~CAN_MCR_WAKMSK_MASK;
    }

/*------------------------------------------------------
Solve others.
------------------------------------------------------*/
p_flexcan_regs->CTRL1 &= ~( mask & ( ~( (uint32_t)FLEXCAN_WAKEUP_INT_EN ) ) );
}

static inline uint64_t flexcan_GetMbStatus
    (
    flexcan_regs_t      *p_flexcan_regs
    )
{
uint64_t tempflag = (uint64_t)p_flexcan_regs->IFLAG1;
return ( tempflag | ( ( (uint64_t)p_flexcan_regs->IFLAG2 ) << 32 ) );
}

static inline uint64_t flexcan_GetMbStatusFlags
    (
    flexcan_regs_t      *p_flexcan_regs,
    can_hmb_mask_t       mask
    )
{
uint64_t tempflag = (uint64_t)p_flexcan_regs->IFLAG1;
return ( tempflag | ( ( (uint64_t)p_flexcan_regs->IFLAG2 ) << 32 ) ) & mask;
}

static inline void flexcan_ClearMbStatusFlags
    (
    flexcan_regs_t      *p_flexcan_regs,
    can_hmb_mask_t       mask
    )
{
p_flexcan_regs->IFLAG1 = (uint32_t)( mask & CAN_HEX_32_FF );
p_flexcan_regs->IFLAG2 = (uint32_t)( mask >> 32 );
}

static inline void flexcan_EnableMbInterrupts
    (
    flexcan_regs_t      *p_flexcan_regs,
    can_hmb_mask_t       mask
    )
{
p_flexcan_regs->IMASK1 |= (uint32_t)( mask & CAN_HEX_32_FF );
p_flexcan_regs->IMASK2 |= (uint32_t)( mask >> 32 );
}

static inline void flexcan_DisableMbInterrupts
    (
    flexcan_regs_t      *p_flexcan_regs,
    can_hmb_mask_t       mask
    )
{
p_flexcan_regs->IMASK1 &= ~( (uint32_t)( mask & CAN_HEX_32_FF ) );
p_flexcan_regs->IMASK2 &= ~( (uint32_t)( mask >> 32 ) );
}

static inline void flexcan_Enable
    (
    flexcan_regs_t      *p_flexcan_regs,
    bool                 enable
    )
{
if( enable )
    {
    p_flexcan_regs->MCR &= ~CAN_MCR_MDIS_MASK;

    /*------------------------------------------------------
    Wait FlexCAN exit from low-power mode.
    ------------------------------------------------------*/
    while( 0U != ( p_flexcan_regs->MCR & CAN_MCR_LPMACK_MASK ) )
        {
        }
    }
else
    {
    p_flexcan_regs->MCR |= CAN_MCR_MDIS_MASK;

    /*------------------------------------------------------
    Wait FlexCAN enter low-power mode.
    ------------------------------------------------------*/
    while( 0U == ( p_flexcan_regs->MCR & CAN_MCR_LPMACK_MASK ) )
        {
        }
    }
}

#if defined(__cplusplus)
}
#endif

#endif /* _FSL_FLEXCAN_H_ */
