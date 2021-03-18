/*********************************************************************
* @file
* vi_tx.c
*
* @brief
* Vehicle information module - process tx data
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "semphr.h"
#include "ewrte.h"
#include "fsl_debug_console.h"
#include "vi_priv.h"
#include "VI_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*********************************************************************
*
* @private
* send_mileage_unit
*
* Send mileage unit setting to meter
*
* @param mileage_setting mileage setting of EnumMileageSettingItem type
*
*********************************************************************/
void send_mileage_unit
    (
    uint8_t mileage_setting
    )
{
dll_frm_index_t l_frm_index;
mid_msg_unit_t  unit_change_req = 0;
uint8_t         unit_val = 0;

switch( mileage_setting )
    {
    case EnumMileageSettingItemKM:
        unit_change_req = MID_MSG_PROCDTL_CHNG_DIST_UNIT_TO_KM;
        unit_val = IL_VT_VEHICLE_INFO_MILE_UNIT_KM;
        break;
    case EnumMileageSettingItemMILE:
        unit_change_req = MID_MSG_PROCDTL_CHNG_DIST_UNIT_TO_MILE;
        unit_val = IL_VT_VEHICLE_INFO_MILE_UNIT_MILE;
        break;
    default:
        break;
    }

if( 0 != unit_change_req )
    {
    /* H'57A */
    can_mid_sig_set( &l_frm_index, IL_CAN0_SYS_INFO_MILEAGE_UNIT_TXSIG_HANDLE, IL_CAN0_SYS_INFO_MILEAGE_UNIT_TXSIG_NBYTES, &unit_val );
    can_mid_frm_send( l_frm_index );

    /* H'584 */
    can_mid_req( TX0_REQ_MT_FUNC_CNT_CAN0_ID, IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_LEN, MID_MSG_SID_UNIT_CHNG, unit_change_req );
    PRINTF( "%s 0x%x\r\n", __FUNCTION__, unit_change_req );
    }
}

/*********************************************************************
*
* @private
* send_fuel_unit
*
* Send fuel unit setting to meter
*
* @param fuel_setting mileage setting of EnumFuelSettingItem type
*
*********************************************************************/
void send_fuel_unit
    (
    uint8_t fuel_setting
    )
{
dll_frm_index_t l_frm_index;
mid_msg_unit_t  unit_change_req = 0;
uint8_t         unit_val = 0;

switch( fuel_setting )
    {
    case EnumFuelSettingItemKM_L:
        unit_change_req = MID_MSG_PROCDTL_CHNG_FUEL_UNIT_TO_KML;
        unit_val = IL_VT_VEHICLE_INFO_FUEL_CON_UNIT_KMPL;
        break;
    case EnumFuelSettingItemMPG:
        unit_change_req = MID_MSG_PROCDTL_CHNG_FUEL_UNIT_TO_MPG;
        unit_val = IL_VT_VEHICLE_INFO_FUEL_CON_UNIT_MPG;
        break;
    case EnumFuelSettingItemL_PER_HUNDRED_KM:
        unit_change_req = MID_MSG_PROCDTL_CHNG_FUEL_UNIT_TO_L100KM;
        unit_val = IL_VT_VEHICLE_INFO_FUEL_CON_UNIT_LP100KM;
        break;
    default:
        break;
    }

if( 0 != unit_change_req )
    {
    /* H'57A */
    can_mid_sig_set( &l_frm_index, IL_CAN0_SYS_INFO_FUEL_CON_UNIT_TXSIG_HANDLE, IL_CAN0_SYS_INFO_FUEL_CON_UNIT_TXSIG_NBYTES, &unit_val );
    can_mid_frm_send( l_frm_index );

    /* H'584 */
    can_mid_req( TX0_REQ_MT_FUNC_CNT_CAN0_ID, IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_LEN, MID_MSG_SID_UNIT_CHNG, unit_change_req );
    PRINTF( "%s 0x%x\r\n", __FUNCTION__, unit_change_req );
    }
}

/*********************************************************************
*
* @private
* send_pressure_unit
*
* Send fuel unit setting to meter
*
* @param pressure_setting Pressure setting of EnumPressureSettingItem type
*
*********************************************************************/
static void send_pressure_unit
    (
    const uint8_t pressure_setting
    )
{
dll_frm_index_t l_frm_index;
mid_msg_unit_t  unit_change_req = 0;
uint8_t         unit_val = 0;

switch( pressure_setting )
    {
    case EnumPressureSettingItemPSI:
        unit_change_req = MID_MSG_PROCDTL_CHNG_PRSS_UNIT_TO_PSI;
        unit_val = IL_VT_VEHICLE_INFO_PRESS_UNIT_PSI;
        break;
    case EnumPressureSettingItemKPA:
        unit_change_req = MID_MSG_PROCDTL_CHNG_PRSS_UNIT_TO_KPA;
        unit_val = IL_VT_VEHICLE_INFO_PRESS_UNIT_KPA;
        break;
    case EnumPressureSettingItemKGF:
        unit_change_req = MID_MSG_PROCDTL_CHNG_PRSS_UNIT_TO_GKGFPSCM;
        unit_val = IL_VT_VEHICLE_INFO_PRESS_UNIT_KGFPCM2;
        break;
    default:
        break;
    }

if( 0 != unit_change_req )
    {
    /* H'57A */
    can_mid_sig_set( &l_frm_index, IL_CAN0_SYS_INFO_PRESSURE_UNIT_TXSIG_HANDLE, IL_CAN0_SYS_INFO_PRESSURE_UNIT_TXSIG_NBYTES, &unit_val );
    can_mid_frm_send( l_frm_index );

    /* H'584 */
    can_mid_req( TX0_REQ_MT_FUNC_CNT_CAN0_ID, IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_LEN, MID_MSG_SID_UNIT_CHNG, unit_change_req );
    PRINTF( "%s 0x%x\r\n", __FUNCTION__, unit_change_req );
    }
}

/*********************************************************************
*
* @private
* send_temperature_unit
*
* Send temperature unit setting to meter
*
* @param temperature_setting temperature setting of EnumTemperatureSettingItem type
*
*********************************************************************/
static void send_temperature_unit
    (
    const uint8_t temperature_setting
    )
{
dll_frm_index_t l_frm_index;
mid_msg_unit_t  unit_change_req = 0;
uint8_t         unit_val = 0;

switch( temperature_setting )
    {
    case EnumTemperatureSettingItemTEMP_C:
        unit_change_req = MID_MSG_PROCDTL_CHNG_TEMP_UNIT_TO_DEGC;
        unit_val = IL_VT_SYS_INFO_TEMP_UNIT_C_DEGREE;
        break;
    case EnumTemperatureSettingItemTEMP_F:
        unit_change_req = MID_MSG_PROCDTL_CHNG_TEMP_UNIT_TO_DEGF;
        unit_val = IL_VT_SYS_INFO_TEMP_UNIT_F_DEGREE;
        break;
    default:
        break;
    }

if( 0 != unit_change_req )
    {
    /* H'57A */
    can_mid_sig_set( &l_frm_index, IL_CAN0_SYS_INFO_TEMP_UNIT_TXSIG_HANDLE, IL_CAN0_SYS_INFO_TEMP_UNIT_TXSIG_NBYTES, &unit_val );
    can_mid_frm_send( l_frm_index );

    /* H'584 */
    can_mid_req( TX0_REQ_MT_FUNC_CNT_CAN0_ID, IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_LEN, MID_MSG_SID_UNIT_CHNG, unit_change_req );
    PRINTF( "%s 0x%x\r\n", __FUNCTION__, unit_change_req );
    }
}

/*********************************************************************
*
* @private
* send_meter_brightness_operation
*
* Send meter brightness operation
*
* @param operation_code Brightness operation code of
*                       IL_VT_DEV_CTRL_LCD_BRGHTNSS_NT,
*                       IL_VT_DEV_CTRL_LCD_BRGHTNSS_DOWN,
*                       IL_VT_DEV_CTRL_LCD_BRGHTNSS_UP
*
*********************************************************************/
static void send_meter_brightness_operation
    (
    const uint8_t operation_code
    )
{
dll_frm_index_t l_frm_index;
can_mid_sig_set( &l_frm_index, IL_CAN0_DEV_CTRL_LCD_BRGHTNSS_TXSIG_HANDLE, IL_CAN0_DEV_CTRL_LCD_BRGHTNSS_TXSIG_NBYTES, &operation_code );
can_mid_frm_send( l_frm_index );
PRINTF( "%s %d\r\n", __FUNCTION__, operation_code );
}

/*********************************************************************
*
* @private
* send_tft_brightness_operation
*
* Send TFT brightness operation
*
* @param operation_code Brightness operation code of
*                       IL_VT_DEV_CTRL_TFT_BRGHTNSS_NT,
*                       IL_VT_DEV_CTRL_TFT_BRGHTNSS_DOWN,
*                       IL_VT_DEV_CTRL_TFT_BRGHTNSS_UP
*
*********************************************************************/
static void send_tft_brightness_operation
    (
    const uint8_t operation_code
    )
{
dll_frm_index_t l_frm_index;
can_mid_sig_set( &l_frm_index, IL_CAN0_DEV_CTRL_TFT_BRGHTNSS_TXSIG_HANDLE, IL_CAN0_DEV_CTRL_TFT_BRGHTNSS_TXSIG_NBYTES, &operation_code );
can_mid_frm_send( l_frm_index );
PRINTF( "%s %d\r\n", __FUNCTION__, operation_code );
}

/*********************************************************************
*
* @private
* VI_set_tx_data
*
* Send data from UI to CAN stack
*
* @param tx_type Tx data of EnumVehicleTxType type
* @param data Tx data
*
*********************************************************************/
void VI_set_tx_data
    (
    int      tx_type,
    uint64_t data
    )
{
PRINTF( "%s 0x%x, 0x%x\r\n", __FUNCTION__, tx_type, data );

switch( tx_type )
    {
    case EnumVehicleTxTypeLANGUAGE:
        break;
    case EnumVehicleTxTypeMILEAGE_UNIT:
        send_mileage_unit( (uint8_t)data );
        break;
    case EnumVehicleTxTypeVEHICLE_SPEED_UNIT:
        break;
    case EnumVehicleTxTypePRESSURE_UNIT:
        send_pressure_unit( (uint8_t)data );
        break;
    case EnumVehicleTxTypeTEMPERATURE_UNIT:
        send_temperature_unit( (uint8_t)data );
        break;
    case EnumVehicleTxTypeFUEL_CONSUMPTION_UNIT:
        send_fuel_unit( (uint8_t)data );
        break;
    case EnumVehicleTxTypeFUEL_UNIT:
        break;
    case EnumVehicleTxTypeHEATER_SELECT:
        break;
    case EnumVehicleTxTypeHEATER_LEVEL:
        break;
    case EnumVehicleTxTypeBUTTON_STATUS_AUDIO:
        break;
    case EnumVehicleTxTypeWIND_SCREEN_OPERATION:
        break;
    case EnumVehicleTxTypeMETER_BRIGHTNESS_OPERATION:
        send_meter_brightness_operation( (uint8_t)data );
        break;
    case EnumVehicleTxTypeGRIP_WARMER_CHANGE_LEVEL:
        break;
    case EnumVehicleTxTypeHEAT_SEATER_CHANGE_LEVEL:
        break;
    case EnumVehicleTxTypeCHG_METER_INFO:
        break;
    case EnumVehicleTxTypeTFT_BRIGHTNESS_OPERATION:
        send_tft_brightness_operation( (uint8_t)data );
        break;
    default:
        PRINTF( "Err: %s invalid tx type %d\r\n", __FUNCTION__, tx_type );
        break;
    }
}
