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

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
flexcan_handle_t flexcanHandle;
volatile bool txComplete = false;
volatile bool rxComplete = false;
volatile bool wakenUp    = false;
flexcan_mb_transfer_t txXfer, rxXfer;
flexcan_frame_t frame;

uint32_t txIdentifier = 0x5B2;
uint32_t rxIdentifier = 0x5A1;

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/

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

FLEXCAN_Init( CAN2, &flexcanConfig, EXAMPLE_CAN_CLK_FREQ);

/* Create FlexCAN handle structure and set call back function. */
FLEXCAN_TransferCreateHandle(EXAMPLE_CAN, &flexcanHandle, flexcan_callback, NULL);

/* Set Rx Masking mechanism. */
FLEXCAN_SetRxMbGlobalMask(EXAMPLE_CAN, FLEXCAN_RX_MB_STD_MASK(rxIdentifier, 0, 0));

/* Setup Rx Message Buffer. */
mbConfig.format = kFLEXCAN_FrameFormatStandard;
mbConfig.type   = kFLEXCAN_FrameTypeData;
mbConfig.id     = FLEXCAN_ID_STD(rxIdentifier);
FLEXCAN_SetRxMbConfig(EXAMPLE_CAN, RX_MESSAGE_BUFFER_NUM, &mbConfig, true);
FLEXCAN_SetTxMbConfig(EXAMPLE_CAN, TX_MESSAGE_BUFFER_NUM, true);
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
    FLEXCAN_TransferSendBlocking(EXAMPLE_CAN, 8, &frame);

    /* Start receive data through Rx Message Buffer. */
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
if( pdPASS == xTaskCreate( (TaskFunction_t)CAN_nim_task, "CAN nim task", 256, NULL, tskIDLE_PRIORITY + 5, NULL ) )
    {
    PRINTF("Create LinkCard CAN Stack thread...                        [OK]\r\n");
    }
else
    {
    PRINTF("Create LinkCard CAN Stack thread...                        [FAIL]\r\n");
    }
}

