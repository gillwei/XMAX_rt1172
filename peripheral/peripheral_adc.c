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
#include "adc_param.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
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

#define ADC_MAX_VOLTAGE               ( 1.8 )
#define ADC_MAX_VALUE                 ( 4095 )
#define ADC_1000_MULTIPLIER           ( 1000 )
#define ADC_10000_MULTIPLIER          ( 10000 )
#define ADC_REF_VOLTAGE_TIMES_1000    ( ADC_MAX_VOLTAGE * ADC_1000_MULTIPLIER )
#define ADC_REF_VOLTAGE_TIMES_10000   ( ADC_MAX_VOLTAGE * ADC_10000_MULTIPLIER )
#define ADC_BATT_MULTIPLIER           ( 18.7936 ) // 105.62/5.62
#define ADC_TEMP_OFFSET               ( 0 )
#define ADC_TEMP_FINETUNE_VALUE       ( 1.00 )

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
                                MACROS
--------------------------------------------------------------------*/
#define cnt_of_array(n)  ( sizeof(n)/sizeof( (n)[0] ) )

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
/*********************************************************************
*
* @public
* ADC_ETC_DONE0_Handler
*
* @brief
*
*********************************************************************/
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

/*********************************************************************
*
* @public
* adc_init
*
* @brief
*
*********************************************************************/
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

/*********************************************************************
*
* @public
* PERIPHERAL_adc_get_tft_ntc
*
* @brief return the tft ntc ADC value
*
*********************************************************************/
int PERIPHERAL_adc_get_tft_ntc
    (
    void
    )
{
return adc_conversion_value[ADC_CHANNEL_TFT_NTC_IDX];
}

/*********************************************************************
*
* @public
* PERIPHERAL_adc_get_tft_ntc_converted
*
* @brief return the tft ntc temperature depends on the ADC value
*
*********************************************************************/
int PERIPHERAL_adc_get_tft_ntc_converted
    (
    void
    )
{
int16_t     index       = 0;
uint16_t    found_index = 0;
int32_t     temperature = 0;
bool        is_found    = false;
uint32_t    adc_voltage = 0;

adc_voltage = ( ( PERIPHERAL_adc_get_tft_ntc() * ADC_REF_VOLTAGE_TIMES_10000 ) / ADC_MAX_VALUE );
adc_voltage = adc_voltage + ADC_TEMP_OFFSET;

for( index = 0; index < ( cnt_of_array( adc_vol2temperature_tft ) - 1 ); index++ )
    {
    uint32_t upper = adc_vol2temperature_tft[index].adc_vol * ADC_10000_MULTIPLIER;
    uint32_t lower = adc_vol2temperature_tft[index + 1].adc_vol * ADC_10000_MULTIPLIER;
    if( ( adc_voltage <= upper ) && ( adc_voltage >= lower ) )
        {
        is_found = true;
        found_index = index;
        break;
        }
    }

if( is_found )
    {
    // linear interpolation
    temperature = (int32_t)( ( ( ( adc_vol2temperature_tft[found_index].adc_vol * ADC_10000_MULTIPLIER - adc_voltage ) / ( adc_vol2temperature_tft[found_index].adc_vol * ADC_10000_MULTIPLIER - adc_vol2temperature_tft[found_index + 1].adc_vol * ADC_10000_MULTIPLIER ) ) + adc_vol2temperature_tft[index].adc_temp ) * ADC_1000_MULTIPLIER );
    }
else
    {
    // the lowest voltage
    temperature = (int32_t)( adc_vol2temperature_tft[(cnt_of_array( adc_vol2temperature_tft ) - 1 )].adc_temp * ADC_1000_MULTIPLIER );
    }

return temperature;
}
/*********************************************************************
*
* @public
* PERIPHERAL_adc_get_pcba_ntc
*
* @brief return the pcba ntc ADC value
*
*********************************************************************/
int PERIPHERAL_adc_get_pcba_ntc
    (
    void
    )
{
return adc_conversion_value[ADC_CHANNEL_PCBA_NTC_IDX];
}

/*********************************************************************
*
* @public
* PERIPHERAL_adc_get_pcba_ntc_converted
*
* @brief return the pcba ntc temperature depends on the ADC value
*
*********************************************************************/
int PERIPHERAL_adc_get_pcba_ntc_converted
    (
    void
    )
{
int16_t     index       = 0;
uint16_t    found_index = 0;
int32_t     temperature = 0;
bool        is_found    = false;
uint32_t    adc_voltage = 0;

adc_voltage = ( ( PERIPHERAL_adc_get_pcba_ntc() * ADC_REF_VOLTAGE_TIMES_10000 ) / ADC_MAX_VALUE );
adc_voltage = adc_voltage + ADC_TEMP_OFFSET;

for( index = 0; index < ( cnt_of_array( adc_vol2temperature_pcb ) - 1 ); index++ )
    {
    uint32_t upper = adc_vol2temperature_pcb[index].adc_vol * ADC_10000_MULTIPLIER;
    uint32_t lower = adc_vol2temperature_pcb[index + 1].adc_vol * ADC_10000_MULTIPLIER;
    if( ( adc_voltage <= upper ) && ( adc_voltage >= lower ) )
        {
        is_found = true;
        found_index = index;
        break;
        }
    }

if( is_found )
    {
    // linear interpolation
    temperature = (int32_t)( ( ( ( adc_vol2temperature_pcb[found_index].adc_vol * ADC_10000_MULTIPLIER - adc_voltage ) / (  adc_vol2temperature_pcb[found_index].adc_vol * ADC_10000_MULTIPLIER -  adc_vol2temperature_pcb[found_index + 1].adc_vol * ADC_10000_MULTIPLIER ) ) + adc_vol2temperature_pcb[index].adc_temp ) * ADC_1000_MULTIPLIER );
    }
else
    {
    // the lowest voltage
    temperature = (int32_t)( adc_vol2temperature_pcb[(cnt_of_array( adc_vol2temperature_pcb ) - 1 )].adc_temp * ADC_1000_MULTIPLIER );
    }

return temperature;
}

/*********************************************************************
*
* @public
* PERIPHERAL_adc_get_vbatt
*
* @brief return the pcba ntc temperature depends on the ADC value
*
*********************************************************************/
int PERIPHERAL_adc_get_vbatt
    (
    void
    )
{
return adc_conversion_value[ADC_CHANNEL_VBATT_IDX];
}

/*********************************************************************
*
* @public
* PERIPHERAL_adc_get_vbatt_converted
*
* @brief return the vbatt voltage value depends on the ADC value
*
*********************************************************************/
int PERIPHERAL_adc_get_vbatt_converted
    (
    void
    )
{
uint32_t temp_value = 0; //12 bits value 0 ~ 4095 ( 0 ~ 1.8V )

temp_value = ( ( ( PERIPHERAL_adc_get_vbatt() * ADC_REF_VOLTAGE_TIMES_1000 ) / ADC_MAX_VALUE ) * ADC_BATT_MULTIPLIER );

return temp_value;
}

/*********************************************************************
*
* @private
* adc_config
*
* @brief
*
*********************************************************************/
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

/*********************************************************************
*
* @private
* xbara_config
*
* @brief
*
*********************************************************************/
static void xbara_config
    (
    void
    )
{
XBARA_Init( XBARA_BASE );
XBARA_SetSignalsConnection( XBARA_BASE, XBARA_INPUT_PITCH0, XBARA_OUTPUT_ADC_ETC );
}

/*********************************************************************
*
* @private
* pit_config
*
* @brief
*
*********************************************************************/
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

/*********************************************************************
*
* @public
* adcetc_config
*
* @brief
*
*********************************************************************/
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
