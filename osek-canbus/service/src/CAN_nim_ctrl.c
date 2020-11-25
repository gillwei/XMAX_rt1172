/*!*******************************************************************
* @file CAN_nim_ctrl.c
* @brief CAN Stack Network Interface Control Manager
*
* This file includes the functions that implement the portion of the
* public API of the Garmin OSEK CAN Stack that deals with controlling
* the overall state of the CAN Stack. The functions in this file allow
* the application to initialize, start up Interface Manager. This file
* also includes the primary periodic task for the CAN Stack that in
* turn manages the periodic task calls for the invidiual layers of the
* CAN Stack, including the Network Management Layer, the Interaction Layer
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_flexcan.h"
#include "fsl_debug_console.h"

#include "FreeRTOS.h"
#include "task.h"
#include "CAN_nim_ctrl.h"
#include "GRM_pub_prj.h"
/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
flexcan_handle_t flexcanHandle;
volatile bool txComplete = false;
volatile bool rxComplete = false;
volatile bool wakenUp    = false;
flexcan_mb_transfer_t txXfer, rxXfer;
flexcan_frame_t frame;

uint32_t txIdentifier = 0x690;
uint32_t rxIdentifier = 0x691;
uint32_t hk_rxIdentifier = 0x5A1;

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
uint64_t flexcan_GetMbStatus
    (
    CAN_Type      *p_flexcan_regs
    )
{
uint64_t tempflag = (uint64_t)p_flexcan_regs->IFLAG1;
return ( tempflag | ( ( (uint64_t)p_flexcan_regs->IFLAG2 ) << 32 ) );
}

can_ret_code_t
can_hw_receive_rx_mb
    (
    CAN_Type              * const p_flexcan_hw_regs, //!< [in] ptr to FlexCAN H/W registers
    can_rmd_t             * const p_rmd,             //!< [in, out] ptr to receive message write buffer
    uint8                   const rx_mb_index        //!< [in] Index of FlexCAN receive Message Buffer
    )
{
can_ret_code_t       l_ret_code       = CAN_RC_EMPTY;
uint32               cs_temp          = 0;
uint32               rx_code          = 0;
uint8                l_dlc_data       = 0;
uint8                l_index          = 0;
uint64               l_mask           = 0;

/*------------------------------------------------------
Read CS field of Rx Message Buffer to lock Message Buffer.
------------------------------------------------------*/
cs_temp = p_flexcan_hw_regs->MB[rx_mb_index].CS;

/*------------------------------------------------------
Get Rx Message Buffer Code field.
------------------------------------------------------*/
rx_code = ( cs_temp & CAN_CS_CODE_MASK ) >> CAN_CS_CODE_SHIFT;

/*------------------------------------------------------
Check to see if Rx Message Buffer is full.
------------------------------------------------------*/
if( ( (uint32)FLEXCAN_RXMB_FULL == rx_code ) || ( (uint32)FLEXCAN_RXMB_OVERRUN == rx_code ) )
    {
    /*------------------------------------------------------
    Store Message ID.
    ------------------------------------------------------*/
    p_rmd->identifier   = p_flexcan_hw_regs->MB[rx_mb_index].ID & ( CAN_ID_EXT_MASK | CAN_ID_STD_MASK );
    p_rmd->identifier   = (( p_rmd->identifier ) >> CAN_ID_STD_SHIFT );

    /*------------------------------------------------------
    Get the message ID format
    ------------------------------------------------------*/
    p_rmd->format       = ( cs_temp & CAN_CS_IDE_MASK ) != 0U ? (uint8)CAN_EXTENDED_MSG_TYPE : (uint8)CAN_STANDARD_MSG_TYPE;

    /*------------------------------------------------------
    Get the message type.
    ------------------------------------------------------*/
    p_rmd->type         = ( cs_temp & CAN_CS_RTR_MASK ) != 0U ? (uint8)CAN_REMOTE_MSG_TYPE : (uint8)CAN_DATA_MSG_TYPE;

    /*------------------------------------------------------
    Get the message length.
    ------------------------------------------------------*/
    p_rmd->dlc          = (uint8)( ( cs_temp & CAN_CS_DLC_MASK ) >> CAN_CS_DLC_SHIFT );

    /*------------------------------------------------------
    Get the time stamp.
    ------------------------------------------------------*/
    p_rmd->timestamp    = (uint16)( ( cs_temp & CAN_CS_TIME_STAMP_MASK ) >> CAN_CS_TIME_STAMP_SHIFT );

    /*------------------------------------------------------
    Store Message Buffer Number
    ------------------------------------------------------*/
    p_rmd->vector       = rx_mb_index;

    /*------------------------------------------------------
    Store Message Payload.
    ------------------------------------------------------*/
    l_dlc_data = p_rmd->dlc;
    l_index    = l_dlc_data;
    switch( l_dlc_data )
        {
        case 8: p_rmd->data[--l_index] = (uint8)( p_flexcan_hw_regs->MB[rx_mb_index].WORD1 );
        case 7: p_rmd->data[--l_index] = (uint8)( p_flexcan_hw_regs->MB[rx_mb_index].WORD1 >> SHIFT_ONE_BYTE    );
        case 6: p_rmd->data[--l_index] = (uint8)( p_flexcan_hw_regs->MB[rx_mb_index].WORD1 >> SHIFT_TWO_BYTES   );
        case 5: p_rmd->data[--l_index] = (uint8)( p_flexcan_hw_regs->MB[rx_mb_index].WORD1 >> SHIFT_THREE_BYTES );
        case 4: p_rmd->data[--l_index] = (uint8)( p_flexcan_hw_regs->MB[rx_mb_index].WORD0 );
        case 3: p_rmd->data[--l_index] = (uint8)( p_flexcan_hw_regs->MB[rx_mb_index].WORD0 >> SHIFT_ONE_BYTE    );
        case 2: p_rmd->data[--l_index] = (uint8)( p_flexcan_hw_regs->MB[rx_mb_index].WORD0 >> SHIFT_TWO_BYTES   );
        case 1: p_rmd->data[--l_index] = (uint8)( p_flexcan_hw_regs->MB[rx_mb_index].WORD0 >> SHIFT_THREE_BYTES );

        default:
            break;
        }

    /*------------------------------------------------------
    Read free-running timer to unlock Rx Message Buffer.
    ------------------------------------------------------*/
    (void)p_flexcan_hw_regs->TIMER;

    l_ret_code = CAN_RC_SUCCESS;
    }
else
    {
    (void)p_flexcan_hw_regs->TIMER;

    l_ret_code = CAN_RC_FAIL;
    }

l_mask = ( 1 << rx_mb_index );

p_flexcan_hw_regs->IFLAG1 = (uint32)( l_mask & CAN_HEX_32_FF );
p_flexcan_hw_regs->IFLAG2 = (uint32)( l_mask >> 32 );

return l_ret_code ;
}

static void flexcan_callback(CAN_Type *base, flexcan_handle_t *handle, status_t status, uint32_t result, void *userData)
{
    switch (status)
    {
        case kStatus_FLEXCAN_RxIdle:
            if (RX_MESSAGE_BUFFER_NUM == result)
            {
                rxComplete = true;
            }
            break;

        case kStatus_FLEXCAN_TxIdle:
            if (TX_MESSAGE_BUFFER_NUM == result)
            {
                txComplete = true;
            }
            break;

        case kStatus_FLEXCAN_WakeUp:
            wakenUp = true;
            break;

        default:
            break;
    }
}

/*!*******************************************************************
*
* @public
* Network Interace Manager initialization
*
* Initialize the Network Management Layer which in turn initializes
* the Network Management Layer and theremaining layers of the Garmin
* OSEK CAN Stack implementation.
*
*********************************************************************/
void CAN_nim_init
    (
    void
    )
{
flexcan_config_t        flexcanConfig;
flexcan_rx_mb_config_t  mbConfig;
flexcan_rx_mb_config_t  hk_mbConfig;


FLEXCAN_EnterFreezeMode(EXAMPLE_CAN);

/*Clock setting for FLEXCAN*/
clock_root_config_t rootCfg = {0};
rootCfg.mux                 = FLEXCAN_CLOCK_SOURCE_SELECT;
rootCfg.div                 = FLEXCAN_CLOCK_SOURCE_DIVIDER;
CLOCK_SetRootClock(kCLOCK_Root_Can2, &rootCfg);

FLEXCAN_GetDefaultConfig(&flexcanConfig);

flexcanConfig.timingConfig.phaseSeg1 = PSEG1;
flexcanConfig.timingConfig.phaseSeg2 = PSEG2;
flexcanConfig.timingConfig.propSeg   = PROPSEG;

flexcan_timing_config_t timing_config;
memset(&timing_config, 0, sizeof(flexcan_timing_config_t));

if (FLEXCAN_CalculateImprovedTimingValues(flexcanConfig.baudRate, EXAMPLE_CAN_CLK_FREQ, &timing_config))
    {
    /* Update the improved timing configuration*/
    memcpy(&(flexcanConfig.timingConfig), &timing_config, sizeof(flexcan_timing_config_t));
    }
else
    {
    LOG_INFO("No found Improved Timing Configuration. Just used default configuration\r\n\r\n");
    }

FLEXCAN_Init( CAN2, &flexcanConfig, EXAMPLE_CAN_CLK_FREQ );

/* Create FlexCAN handle structure and set call back function. */
FLEXCAN_TransferCreateHandle(EXAMPLE_CAN, &flexcanHandle, flexcan_callback, NULL);
FLEXCAN_SetTxMbConfig(EXAMPLE_CAN, TX_MESSAGE_BUFFER_NUM, true);

/* Setup Rx Message Buffer. */
mbConfig.format = kFLEXCAN_FrameFormatStandard;
mbConfig.type   = kFLEXCAN_FrameTypeData;
mbConfig.id     = FLEXCAN_ID_STD(rxIdentifier);
FLEXCAN_SetRxMbConfig(EXAMPLE_CAN, RX_MESSAGE_BUFFER_NUM, &mbConfig, true);
FLEXCAN_EnableMbInterrupts( EXAMPLE_CAN, ( 1 << RX_MESSAGE_BUFFER_NUM ) );

/* Setup Rx Message Buffer. */
hk_mbConfig.format = kFLEXCAN_FrameFormatStandard;
hk_mbConfig.type   = kFLEXCAN_FrameTypeData;
hk_mbConfig.id     = FLEXCAN_ID_STD(hk_rxIdentifier);
FLEXCAN_SetRxMbConfig(EXAMPLE_CAN, HK_RX_MESSAGE_BUFFER_NUM, &hk_mbConfig, true);
FLEXCAN_EnableMbInterrupts( EXAMPLE_CAN, ( 1 << HK_RX_MESSAGE_BUFFER_NUM ) );

FLEXCAN_ExitFreezeMode(EXAMPLE_CAN);
}

/*!*******************************************************************
*
* @public
* start up the Network Interace Manager
*
* This function performs start up initialization of the Network
* Interace Manager. Included in this function of the ancillary CAN
* services that are needed by the CAN controller and the low level
* driver as well as initialization of all layers of the Garmin OSEK
* CAN Stack.
*
*********************************************************************/
void CAN_nim_start_up
    (
    void
    )
{
CAN_nim_init();
}

/*!*******************************************************************
*
* @public
* periodic Network Interace Manager task
*
* This function represents the periodic task that must be called at
* the specific rate by the OS or Task Manager needed to guarantee
* proper timing for all of the Garmin OSEK CAN Stack component
* behaviors, including timing of periodic message transmissions,
* receive message timeouts, Network Management message timeouts, etc.
*
*********************************************************************/
static void
CAN_nim_task
    (
    void
    )
{
uint32_t  last_time = xTaskGetTickCount();

frame.id     = FLEXCAN_ID_STD(txIdentifier);
frame.format = (uint8_t)kFLEXCAN_FrameFormatStandard;
frame.type   = (uint8_t)kFLEXCAN_FrameTypeData;
frame.length = (uint8_t)DLC;

/*------------------------------------------------------
Starup the CAN hardware and services
------------------------------------------------------*/
CAN_nim_start_up();

while(1)
    {
    rxXfer.mbIdx = (uint8_t)RX_MESSAGE_BUFFER_NUM;
    rxXfer.frame = &frame;

    frame.dataByte0 = 0xaa;
    frame.dataByte1 = 0xaa;
    frame.dataByte2 = 0xaa;
    frame.dataByte3 = 0xaa;
    frame.dataByte4 = 0x55;
    frame.dataByte5 = 0x55;
    frame.dataByte6 = 0x55;
    frame.dataByte7 = 0x55;

    /*--------------------------------------------------
    Use this api to send Factory test frames....
    --------------------------------------------------*/
    FLEXCAN_TransferSendBlocking(EXAMPLE_CAN, 8, &frame);

    vTaskDelayUntil( &last_time, 1000 );
    }

vTaskDelete(NULL);
}

/*------------------------------------------------------
Create the CAN stack task NIM
------------------------------------------------------*/
void vCAN_nim_create_task
    (
    void
    )
{
if( pdPASS == xTaskCreate( (TaskFunction_t)CAN_nim_task, "CAN nim task", 256, NULL, TASK_PRIO_CAN, NULL ) )
    {
    PRINTF("Create LinkCard CAN Stack thread...                        [OK]\r\n");
    }
else
    {
    PRINTF("Create LinkCard CAN Stack thread...                        [FAIL]\r\n");
    }
}

