/*********************************************************************
* @file
* peripheral_adc.c
*
* @brief
* adc module
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "PERIPHERAL_pub.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "fsl_lpadc.h"
#include "fsl_adc_etc.h"
#include "fsl_pit.h"
#include "fsl_xbara.h"
#include "fsl_common.h"
#include "pin_mux.h"
#include "clock_config.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/
#define ADC_BASE                      ( LPADC1 )
#define ADC_ETC_DONE0_Handler         ADC_ETC_IRQ0_IRQHandler

#define ADC_ETC_TRIGGER_GROUP         ( 0U )
#define ADC_ETC_CHAIN_LENGTH          ( 2U )                       //Chain Length is ( 2 + 1 )

#define ADC_CHANNEL_NUM_TFT_TEMP      ( 5U )                       // ADC1_CH5A TFT TEMP
#define ADC_CHANNEL_NUM_PCBA_TEMP     ( 3U )                       // ADC1_CH3A PCBA TEMP
#define ADC_CHANNEL_NUM_VBATT_SEN     ( 0U )                       // ADC1_CH0B VBATT SENSE

#define ADC_CMD_ID_TFT_TEMP           ( 1U )
#define ADC_CMD_ID_PCBA_TEMP          ( ADC_CMD_ID_TFT_TEMP + 1 )
#define ADC_CMD_ID_VBATT_SEN          ( ADC_CMD_ID_PCBA_TEMP + 1 )

#define ADC_TRIGGER_ID_TFT_TMP        ( 0U )
#define ADC_TRIGGER_ID_PCBA_TEMP      ( ADC_TRIGGER_ID_TFT_TMP + 1 )
#define ADC_TRIGGER_ID_VBATT_SEN      ( ADC_TRIGGER_ID_PCBA_TEMP + 1 )

#define ADC_ETC_TFT_HW_TGR_GROUP      ( 0 )
#define ADC_ETC_PCBA_HW_TGR_GROUP     ( 1 )
#define ADC_ETC_VATT_HW_TGR_GROUP     ( 2 )

#define ADC_ETC_TFT_CHANNEL           ( 0 )
#define ADC_ETC_PCBA_CHANNEL          ( 1 )
#define ADC_ETC_VBATT_CHANNEL         ( 2 )

#define XBARA_BASE                    XBARA1
#define XBARA_INPUT_PITCH0            kXBARA1_InputPitTrigger0
#define XBARA_OUTPUT_ADC_ETC          kXBARA1_OutputAdcEtcXbar0Trig0

#define PIT_SOURCE_CLOCK              CLOCK_GetFreq( kCLOCK_OscRc48M )
#define PIT_PERIOD_uS                 ( 1000000U )
/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef enum
    {
    ADC_CHANNEL_TFT_NTC_IDX   = 0,
    ADC_CHANNEL_PCBA_NTC_IDX  = 1,
    ADC_CHANNEL_VBATT_IDX     = 2,


    ADC_CHANNNEL_NUMBER_CNT
    }adc_channel_idx_type;
/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
volatile unsigned int adc_conversion_value[ADC_CHANNNEL_NUMBER_CNT];
/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/
static void adc_config
    (
    void
    );

static void xbara_config
    (
    void
    );

static void pit_config
    (
    void
    );

static void adcetc_config
    (
    void
    );

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================*/
/**
@brief   ADC_ETC_DONE0_Handler
@details

@return None
@retval None
*/
/*================================================================================================*/

void ADC_ETC_DONE0_Handler
    (
    void
    )
{
ADC_ETC_ClearInterruptStatusFlags( ADC_ETC, kADC_ETC_Trg0TriggerSource, kADC_ETC_Done0StatusFlagMask );
adc_conversion_value[ADC_CHANNEL_TFT_NTC_IDX]   = ADC_ETC_GetADCConversionValue( ADC_ETC, ADC_ETC_TRIGGER_GROUP, 0U );
adc_conversion_value[ADC_CHANNEL_PCBA_NTC_IDX]  = ADC_ETC_GetADCConversionValue( ADC_ETC, ADC_ETC_TRIGGER_GROUP, 1U );
adc_conversion_value[ADC_CHANNEL_VBATT_IDX]     = ADC_ETC_GetADCConversionValue( ADC_ETC, ADC_ETC_TRIGGER_GROUP, 2U );
__DSB();
}

/*================================================================================================*/
/**
@brief   adc_init
@details

@return None
@retval None
*/
/*================================================================================================*/
void adc_init
    (
    void
    )
{
adc_config();
xbara_config();
pit_config();
adcetc_config();
}

/*================================================================================================*/
/**
@brief   PERIPHERAL_adc_get_pcba_ntc
@details

@return None
@retval int
*/
/*================================================================================================*/

int PERIPHERAL_adc_get_pcba_ntc
    (
    void
    )
{
return adc_conversion_value[ADC_CHANNEL_PCBA_NTC_IDX];
}

/*================================================================================================*/
/**
@brief   PERIPHERAL_adc_get_vbatt
@details

@return None
@retval int
*/
/*================================================================================================*/

int PERIPHERAL_adc_get_vbatt
    (
    void
    )
{
return adc_conversion_value[ADC_CHANNEL_VBATT_IDX];
}

/*================================================================================================*/
/**
@brief   PERIPHERAL_adc_get_tft_ntc
@details

@return None
@retval int
*/
/*================================================================================================*/

int PERIPHERAL_adc_get_tft_ntc
    (
    void
    )
{
return adc_conversion_value[ADC_CHANNEL_TFT_NTC_IDX];
}

/*================================================================================================*/
/**
@brief   ADC_config
@details

@return None
@retval None
*/
/*================================================================================================*/
static void adc_config
    (
    void
    )
{
lpadc_config_t              lpadcConfig;
lpadc_conv_command_config_t lpadcCommandConfig;
lpadc_conv_trigger_config_t lpadcTriggerConfig;


LPADC_GetDefaultConfig( &lpadcConfig );
LPADC_Init( ADC_BASE, &lpadcConfig );

//TFT TEMP
LPADC_GetDefaultConvCommandConfig( &lpadcCommandConfig );
lpadcCommandConfig.channelNumber = ADC_CHANNEL_NUM_TFT_TEMP;
LPADC_SetConvCommandConfig( ADC_BASE, ADC_CMD_ID_TFT_TEMP, &lpadcCommandConfig );

LPADC_GetDefaultConvTriggerConfig( &lpadcTriggerConfig );
lpadcTriggerConfig.targetCommandId       = ADC_CMD_ID_TFT_TEMP;
lpadcTriggerConfig.enableHardwareTrigger = true;
LPADC_SetConvTriggerConfig( ADC_BASE, ADC_TRIGGER_ID_TFT_TMP, &lpadcTriggerConfig );

//PCBA TEMP
LPADC_GetDefaultConvCommandConfig( &lpadcCommandConfig );
lpadcCommandConfig.channelNumber = ADC_CHANNEL_NUM_PCBA_TEMP;
LPADC_SetConvCommandConfig( ADC_BASE, ADC_CMD_ID_PCBA_TEMP, &lpadcCommandConfig );

LPADC_GetDefaultConvTriggerConfig( &lpadcTriggerConfig );
lpadcTriggerConfig.targetCommandId       = ADC_CMD_ID_PCBA_TEMP;
lpadcTriggerConfig.enableHardwareTrigger = true;
LPADC_SetConvTriggerConfig( ADC_BASE, ADC_TRIGGER_ID_PCBA_TEMP, &lpadcTriggerConfig );

//VBATT SENSE
LPADC_GetDefaultConvCommandConfig( &lpadcCommandConfig );
lpadcCommandConfig.channelNumber = ADC_CHANNEL_NUM_VBATT_SEN;
lpadcCommandConfig.sampleChannelMode = kLPADC_SampleChannelSingleEndSideB;
LPADC_SetConvCommandConfig( ADC_BASE, ADC_CMD_ID_VBATT_SEN, &lpadcCommandConfig );

LPADC_GetDefaultConvTriggerConfig( &lpadcTriggerConfig );
lpadcTriggerConfig.targetCommandId       = ADC_CMD_ID_VBATT_SEN;
lpadcTriggerConfig.enableHardwareTrigger = true;
LPADC_SetConvTriggerConfig( ADC_BASE, ADC_TRIGGER_ID_VBATT_SEN, &lpadcTriggerConfig );
}

/*================================================================================================*/
/**
@brief   xbara_config
@details

@return None
@retval None
*/
/*================================================================================================*/
static void xbara_config
    (
    void
    )
{
XBARA_Init( XBARA_BASE );
XBARA_SetSignalsConnection( XBARA_BASE, XBARA_INPUT_PITCH0, XBARA_OUTPUT_ADC_ETC );
}

/*================================================================================================*/
/**
@brief   pit_config
@details

@return None
@retval None
*/
/*================================================================================================*/
static void pit_config
    (
    void
    )
{
pit_config_t pitConfig;
PIT_GetDefaultConfig( &pitConfig );
PIT_Init( PIT1, &pitConfig );
PIT_SetTimerPeriod( PIT1, kPIT_Chnl_0, USEC_TO_COUNT( PIT_PERIOD_uS, PIT_SOURCE_CLOCK ) );
}

/*================================================================================================*/
/**
@brief   adcetc_config
@details

@return None
@retval None
*/
/*================================================================================================*/
void adcetc_config
    (
    void
    )
{
adc_etc_config_t               adcEtcConfig;
adc_etc_trigger_config_t       adcEtcTriggerConfig;
adc_etc_trigger_chain_config_t adcEtcTriggerChainConfig;

ADC_ETC_GetDefaultConfig( &adcEtcConfig );
adcEtcConfig.XBARtriggerMask = 1U;
ADC_ETC_Init( ADC_ETC, &adcEtcConfig );

adcEtcTriggerConfig.enableSyncMode      = false;
adcEtcTriggerConfig.enableSWTriggerMode = false;
adcEtcTriggerConfig.triggerChainLength  = ADC_ETC_CHAIN_LENGTH;
adcEtcTriggerConfig.triggerPriority     = 0U;
adcEtcTriggerConfig.sampleIntervalDelay = 0;
adcEtcTriggerConfig.initialDelay        = 0;
ADC_ETC_SetTriggerConfig( ADC_ETC, 0U, &adcEtcTriggerConfig );

/* Set the external XBAR trigger0 chain configuration. */
adcEtcTriggerChainConfig.enableB2BMode       = true;

//trigger 0 chain 0
adcEtcTriggerChainConfig.ADCHCRegisterSelect = 1U << ADC_ETC_TFT_HW_TGR_GROUP;
adcEtcTriggerChainConfig.ADCChannelSelect    = ADC_ETC_TFT_CHANNEL;
adcEtcTriggerChainConfig.InterruptEnable     = kADC_ETC_Done0InterruptEnable;
ADC_ETC_SetTriggerChainConfig( ADC_ETC, ADC_ETC_TRIGGER_GROUP, 0U, &adcEtcTriggerChainConfig );

//trigger 0 chain 1
adcEtcTriggerChainConfig.ADCHCRegisterSelect = 1U << ADC_ETC_PCBA_HW_TGR_GROUP;
adcEtcTriggerChainConfig.ADCChannelSelect = ADC_ETC_PCBA_CHANNEL;
adcEtcTriggerChainConfig.InterruptEnable = kADC_ETC_Done0InterruptEnable;
ADC_ETC_SetTriggerChainConfig( ADC_ETC, ADC_ETC_TRIGGER_GROUP, 1U, &adcEtcTriggerChainConfig );

//trigger 0 chain 2
adcEtcTriggerChainConfig.ADCHCRegisterSelect = 1U << ADC_ETC_VATT_HW_TGR_GROUP;
adcEtcTriggerChainConfig.ADCChannelSelect = ADC_ETC_VBATT_CHANNEL;
adcEtcTriggerChainConfig.InterruptEnable = kADC_ETC_Done0InterruptEnable;
ADC_ETC_SetTriggerChainConfig( ADC_ETC, ADC_ETC_TRIGGER_GROUP, 2U, &adcEtcTriggerChainConfig );

EnableIRQ( ADC_ETC_IRQ0_IRQn );
PIT_StartTimer( PIT1, kPIT_Chnl_0 );
}

#ifdef __cplusplus
}
#endif
