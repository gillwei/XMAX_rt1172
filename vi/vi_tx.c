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
#include "EW_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define UNIX_TIME_BYTES     ( 5 )

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
static dll_frm_index_t heater_frm_index;

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
    case EnumPressureSettingItemKGF_PER_CM2:
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
* send_tcs_status
*
* Send tcs status to meter
*
* @param tcs_status TCS mode
*
*********************************************************************/
static void send_tcs_status
    (
    uint8_t tcs_status
    )
{
mid_msg_tcs_t   tcs_change_req = 0;

switch( tcs_status )
    {
    case 0:
        tcs_change_req = MID_MSG_PROCDTL_TCS_ON_TO_OFF;
        break;
    case 1:
        tcs_change_req = MID_MSG_PROCDTL_TCS_OFF_TO_ON;
        break;
    default:
        break;
    }

if( 0 != tcs_change_req )
    {
    /* H'584 */
    can_mid_req( TX0_REQ_MT_FUNC_CNT_CAN0_ID, IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_LEN, MID_MSG_SID_TCS_SWITCH, tcs_change_req );
    PRINTF( "%s 0x%x\r\n", __FUNCTION__, tcs_change_req );
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
* send_meter_heater_operation
*
* Send meter seat heater/grip warmer operation
*
* @param operation_code Seat heater operation code of
*                       IL_VT_HEATER_LVL_BTN_STAT_AUD_DOWN
*                       IL_VT_HEATER_LVL_BTN_STAT_AUD_UP
*
*********************************************************************/
static void send_meter_heater_operation
    (
    uint8_t operation_code
    )
{
can_mid_sig_set( &heater_frm_index, IL_CAN0_HEATER_LVL_BTN_STAT_HEATER_TXSIG_HANDLE, IL_CAN0_HEATER_LVL_BTN_STAT_HEATER_TXSIG_NBYTES, &operation_code );
can_mid_frm_send( heater_frm_index );

// Reset heater_frm_index to 0.
heater_frm_index = 0;
PRINTF( "%s %d\r\n", __FUNCTION__, operation_code );
}

/*********************************************************************
*
* @private
* set_meter_heater_level
*
* Set meter seat heater/grip warmer level
*
* @param heater_level Seat heater/Grip warmer level of
*                     IL_VT_HEATER_LVL_LV_LO
*                     IL_VT_HEATER_LVL_LV_MID
*                     IL_VT_HEATER_LVL_LV_HI
*
*********************************************************************/
static void set_meter_heater_level
    (
    uint8_t heater_level
    )
{
can_mid_sig_set( &heater_frm_index, IL_CAN0_HEATER_LVL_LV_TXSIG_HANDLE, IL_CAN0_HEATER_LVL_LV_TXSIG_NBYTES, &heater_level );
PRINTF( "%s %d\r\n", __FUNCTION__, heater_level );
}

/*********************************************************************
*
* @private
* set_meter_heater_select
*
* Set meter the selected heater
*
* @param heater_code The selected heater code of
*                    IL_VT_HEATER_LVL_SLECT_GRIP_WARNER
*                    IL_VT_HEATER_LVL_SLECT_RIDER_SEAT_HEATER
*                    IL_VT_HEATER_LVL_SLECT_PASSENGER_SEAT_HEATER
*
*********************************************************************/
static void set_meter_heater_select
    (
    uint8_t heater_code
    )
{
can_mid_sig_set( &heater_frm_index, IL_CAN0_HEATER_LVL_SLECT_TXSIG_HANDLE, IL_CAN0_HEATER_LVL_SLECT_TXSIG_NBYTES, &heater_code );
PRINTF( "%s %d\r\n", __FUNCTION__, heater_code );
}

/*********************************************************************
*
* @private
* send_meter_seat_heater_change_level
*
* Send meter seat heater needs to change level
*
* @param level Seat heater level code of
*              IL_VT_DEV_CTRL_SEAT_HEATER_NT,
*              IL_VT_DEV_CTRL_SEAT_HEATER_DOWN,
*              IL_VT_DEV_CTRL_SEAT_HEATER_UP
*
*********************************************************************/
static void send_meter_seat_heater_change_level
    (
    const uint8_t level
    )
{
dll_frm_index_t l_frm_index;
can_mid_sig_set( &l_frm_index, IL_CAN0_DEV_CTRL_SEAT_HEATER_TXSIG_HANDLE, IL_CAN0_DEV_CTRL_SEAT_HEATER_TXSIG_NBYTES, &level );
can_mid_frm_send( l_frm_index );
PRINTF( "%s %d\r\n", __FUNCTION__, level );
}

/*********************************************************************
*
* @private
* send_meter_grip_warmer_change_level
*
* Send meter grip warmer needs to change level
*
* @param level Grip warmer level code of
*              IL_VT_DEV_CTRL_GRIP_WARM_NT,
*              IL_VT_DEV_CTRL_GRIP_WARM_DOWN,
*              IL_VT_DEV_CTRL_GRIP_WARM_UP
*
*********************************************************************/
static void send_meter_grip_warmer_change_level
    (
    const uint8_t level
    )
{
dll_frm_index_t l_frm_index;
can_mid_sig_set( &l_frm_index, IL_CAN0_DEV_CTRL_GRIP_WARM_TXSIG_HANDLE, IL_CAN0_DEV_CTRL_GRIP_WARM_TXSIG_NBYTES, &level );
can_mid_frm_send( l_frm_index );
PRINTF( "%s %d\r\n", __FUNCTION__, level );
}

/*********************************************************************
*
* @private
* change_meter_info
*
* Change meter info (ODO/TRIP1/TRIP2/TRIP-F)
*
* @param meter_info Meter info to change
*
*********************************************************************/
static void change_meter_info
    (
    const EnumMeterInfo meter_info
    )
{
uint8_t procdtl = 0;
uint8_t odo_trip_type = 0;

switch( meter_info )
    {
    case EnumMeterInfoODO:
        procdtl = MID_MSG_PROCDTL_VC_INFO_CHNG_TO_ODO;
        odo_trip_type = IL_VT_DEV_CTRL_CHG_METER_ODO;
        break;
    case EnumMeterInfoTRIP1:
        procdtl = MID_MSG_PROCDTL_VC_INFO_RST_CHNG_TO_TRIP1;
        odo_trip_type = IL_VT_DEV_CTRL_CHG_METER_TRIP1;
        break;
    case EnumMeterInfoTRIP2:
        procdtl = MID_MSG_PROCDTL_VC_INFO_RST_CHNG_TO_TRIP2;
        odo_trip_type = IL_VT_DEV_CTRL_CHG_METER_TRIP2;
        break;
    case EnumMeterInfoTRIP_F:
        procdtl = MID_MSG_PROCDTL_VC_INFO_RST_CHNG_TO_TRIPF;
        odo_trip_type = IL_VT_DEV_CTRL_CHG_METER_TRIPF;
        break;
    default:
        break;
    }

if( 0 != procdtl )
    {
    /* H'584 */
    can_mid_req( TX0_REQ_MT_FUNC_CNT_CAN0_ID, IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_LEN, MID_MSG_SID_VC_INFO_CHNG_MT_LCD, procdtl );

    /* H'5CA */
    dll_frm_index_t l_frm_index2;
    can_mid_sig_set( &l_frm_index2, IL_CAN0_DEV_CTRL_CHG_METER_TXSIG_HANDLE, IL_CAN0_DEV_CTRL_CHG_METER_TXSIG_NBYTES, &odo_trip_type );
    can_mid_frm_send( l_frm_index2 );

    PRINTF( "%s %d 0x%x\r\n", __FUNCTION__, odo_trip_type, procdtl );
    }
}

/*********************************************************************
*
* @private
* send_meter_windscreen_operation
*
* Send meter wind screen operation
*
* @param operation_code Wind screen operation code of
*                       IL_VT_DEV_CTRL_WINDSCRN_NT,
*                       IL_VT_DEV_CTRL_WINDSCRN_DOWN,
*                       IL_VT_DEV_CTRL_WINDSCRN_UP
*
*********************************************************************/
static void send_meter_windscreen_operation
    (
    const uint8_t operation_code
    )
{
dll_frm_index_t l_frm_index;
can_mid_sig_set( &l_frm_index, IL_CAN0_DEV_CTRL_WINDSCRN_TXSIG_HANDLE, IL_CAN0_DEV_CTRL_WINDSCRN_TXSIG_NBYTES, &operation_code );
can_mid_frm_send( l_frm_index );
PRINTF( "%s %d\r\n", __FUNCTION__, operation_code );
}

/*********************************************************************
*
* @private
* send_meter_time
*
* Send meter current time
*
* @param cur_time Current time
*
*********************************************************************/
static void send_meter_time
    (
    const uint64_t cur_time
    )
{
uint8_t unix_time[UNIX_TIME_BYTES];
unix_time[0] = ( cur_time >> 32 ) & 0xFF;
unix_time[1] = ( cur_time >> 24 ) & 0xFF;
unix_time[2] = ( cur_time >> 16 ) & 0xFF;
unix_time[3] = ( cur_time >> 8 ) & 0xFF;
unix_time[4] = cur_time & 0xFF;

dll_frm_index_t l_frm_index;
can_mid_sig_set( &l_frm_index, IL_CAN0_CLK_DATE_RESP_DATA_TXSIG_HANDLE, IL_CAN0_CLK_DATE_RESP_DATA_TXSIG_NBYTES, unix_time );
can_mid_frm_send( l_frm_index );
}

/*********************************************************************
*
* @public
* VI_send_inspection_response
*
* Send inspection response H'60B
*
* @param mode Inspection mode
* @param fainsres FAINSRES in the CAN signal H'60B
*
*********************************************************************/
void VI_send_inspection_response
    (
    const EnumInspectionMode mode,
    const uint8_t fainsres
    )
{
PRINTF( "%s %d %d\r\n", __FUNCTION__, mode, fainsres );
dll_frm_index_t l_frm_index;
can_mid_sig_set( &l_frm_index, IL_CAN0_FACT_INSP_NS_RES_TXSIG_HANDLE, IL_CAN0_FACT_INSP_NS_RES_TXSIG_NBYTES, &mode );
can_mid_sig_set( &l_frm_index, IL_CAN0_FACT_INSP_NS_RESCODE_TXSIG_HANDLE, IL_CAN0_FACT_INSP_NS_RESCODE_TXSIG_NBYTES, &fainsres );
can_mid_frm_send( l_frm_index );
}

/*********************************************************************
*
* @private
* reset_meter
*
* Reset meter info (TRIP1/TRIP2/TRIP-F)
*
* @param meter_info Meter info to reset
*
*********************************************************************/
static void reset_meter
    (
    const EnumMeterInfo meter_info
    )
{
uint8_t procdtl = 0;

switch( meter_info )
    {
    case EnumMeterInfoTRIP1:
        procdtl = MID_MSG_PROCDTL_VC_INFO_RST_CHNG_TO_TRIP1;
        break;
    case EnumMeterInfoTRIP2:
        procdtl = MID_MSG_PROCDTL_VC_INFO_RST_CHNG_TO_TRIP2;
        break;
    case EnumMeterInfoTRIP_F:
        procdtl = MID_MSG_PROCDTL_VC_INFO_RST_CHNG_TO_TRIPF;
        break;
    case EnumMeterInfoAVG_SPEED:
        procdtl = MID_MSG_PROCDTL_VC_INFO_RST_AVG_SPEED;
        break;
    case EnumMeterInfoAVG_FUEL:
        procdtl = MID_MSG_PROCDTL_VC_INFO_RST_AVG_FUEL;
        break;
    case EnumMeterInfoFUEL_CONSUMPTION:
        procdtl = MID_MSG_PROCDTL_VC_INFO_RST_FUEL_CONS;
        break;
    case EnumMeterInfoMAINTENANCE_TRIP1:
        procdtl = MID_MSG_PROCDTL_MAINT_INFO_RST_AT_TOP;
        break;
    case EnumMeterInfoMAINTENANCE_TRIP2:
        procdtl = MID_MSG_PROCDTL_MAINT_INFO_RST_AT_MID;
        break;
    case EnumMeterInfoMAINTENANCE_TRIP3:
        procdtl = MID_MSG_PROCDTL_MAINT_INFO_RST_AT_BOT;
        break;
    case EnumMeterInfoTRIP_TIME:
        /* trip time is kept in LinkCard, not in meter, so no need to send CAN message to meter */
        vi_trip_time_reset();
        EW_notify_vi_data_received( EnumVehicleRxTypeTRIP_TIME );
        break;
    default:
        break;
    }

if( 0 != procdtl )
    {
    /* H'584 */
    can_mid_req( TX0_REQ_MT_FUNC_CNT_CAN0_ID, IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_LEN, MID_MSG_SID_VC_INFO_RST, procdtl );
    PRINTF( "%s 0x%x\r\n", __FUNCTION__, procdtl );
    }
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
        set_meter_heater_select( (uint8_t)data );
        break;
    case EnumVehicleTxTypeHEATER_LEVEL:
        set_meter_heater_level( (uint8_t)data );
        break;
    case EnumVehicleTxTypeBUTTON_STATUS_AUDIO:
        send_meter_heater_operation( (uint8_t)data );
        break;
    case EnumVehicleTxTypeCLOCK_DATE:
        send_meter_time( data );
        break;
    case EnumVehicleTxTypeWIND_SCREEN_OPERATION:
        send_meter_windscreen_operation( (uint8_t)data );
        break;
    case EnumVehicleTxTypeMETER_BRIGHTNESS_OPERATION:
        send_meter_brightness_operation( (uint8_t)data );
        break;
    case EnumVehicleTxTypeGRIP_WARMER_CHANGE_LEVEL:
        send_meter_grip_warmer_change_level( (uint8_t)data );
        break;
    case EnumVehicleTxTypeSEAT_HEATER_CHANGE_LEVEL:
        send_meter_seat_heater_change_level( (uint8_t)data );
        break;
    case EnumVehicleTxTypeCHG_METER_INFO:
        change_meter_info( (EnumMeterInfo)data );
        break;
    case EnumVehicleTxTypeTFT_BRIGHTNESS_OPERATION:
        send_tft_brightness_operation( (uint8_t)data );
        break;
    case EnumVehicleTxTypeTCS:
        send_tcs_status( (uint8_t)data );
        break;
    case EnumVehicleTxTypeRESET_METER:
        reset_meter( (EnumMeterInfo)data );
        break;
    default:
        PRINTF( "Err: %s invalid tx type %d\r\n", __FUNCTION__, tx_type );
        break;
    }
}
