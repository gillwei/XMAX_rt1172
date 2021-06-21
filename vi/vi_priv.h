/*********************************************************************
* @file
* vi_priv.h
*
* @brief
* Vehicle information module - private API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef VI_PRIV_H
#define VI_PRIV_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Core.h"

#define RESET_VEHICLE_INFO_REQUEST_ID               ( 0x10 )
#define RESET_VEHICLE_INFO_RESPONSE_ID              ( 0x50 )

#define CHANGE_ODO_TRIP_REQUEST_ID                  ( 0x15 )
#define CHANGE_ODO_TRIP_RESPONSE_ID                 ( 0x55 )

#define VEHICLE_FEATURE_LIST_POSITIVE_RESPONSE_ID   ( 0x50 )
#define VEHICLE_NEGATIVE_RESPONSE_ID                ( 0xEE )

typedef enum
    {
    VVA_INDICATOR_OFF      = 0,
    VVA_INDICATOR_ON       = 1,
    VVA_INDICATOR_RESERVE1 = 2,
    VVA_INDICATOR_RESERVE2 = 3,
    VVA_INDICATOR_TOTAL
    } vva_indicator_enum;

typedef enum
    {
    MILEAGE_UNIT_KM   = 0,
    MILEAGE_UNIT_MILE = 1,
    MILEAGE_UNIT_TOTAL
    } mileage_unit_enum;

typedef enum
    {
    PRESSURE_UNIT_PSI     = 0,
    PRESSURE_UNIT_KPA     = 1,
    PRESSURE_UNIT_KGF_CM2 = 2,
    PRESSURE_UNIT_BAR     = 3,
    PRESSURE_UNIT_TOTAL
    } pressure_unit_enum;

typedef enum
    {
    TEMPERATURE_UNIT_DEG_C = 0,
    TEMPERATURE_UNIT_DEG_F = 1,
    TEMPERATURE_UNIT_TOTAL
    } temperature_unit_enum;

typedef enum
    {
    FUEL_CONSUMPTION_UNIT_KM_L        = 0,
    FUEL_CONSUMPTION_UNIT_MILE_GAL    = 1,
    FUEL_CONSUMPTION_UNIT_MILE_LMPGAL = 2,
    FUEL_CONSUMPTION_UNIT_L_100KM     = 3,
    FUEL_CONSUMPTION_UNIT_TOTAL
    } fuel_consumption_unit_enum;

typedef enum
    {
    HEATER_SETTING_OFF    = 0,
    HEATER_SETTING_LOW    = 1,
    HEATER_SETTING_MIDDLE = 2,
    HEATER_SETTING_HIGH   = 3,
    HEATER_SETTING_TOTAL
    } heater_setting_enum;

typedef enum
    {
    ODO_TRIP_DISPLAY_ODO   = 0,
    ODO_TRIP_DISPLAY_TRIP1 = 1,
    ODO_TRIP_DISPLAY_TRIP2 = 2,
    ODO_TRIP_DISPLAY_TRIPF = 3,
    ODO_TRIP_DISPLAY_TOTAL
    } odo_trip_display_enum;

typedef struct
    {
    uint16_t           engine_speed;    /**< engine speed (rpm) */
    uint8_t            tc_mode;         /**< TCS mode */
    vva_indicator_enum vva_indicator;   /**< VVA indicator */
    } rx_ecu_info_struct;

typedef struct
    {
    uint16_t tft_duty;              /**< LinkCard TFT pwm duty cycle */
    uint8_t  lcd_brightness_level;  /**< digital meter LCD brightness level*/
    uint8_t  tft_brightness_level;  /**< LinkCard TFT brightness level */
    } rx_brightness_control_struct;

typedef struct
    {
    mileage_unit_enum     mileage_unit;     /**< mileage unit */
    pressure_unit_enum    pressure_unit;    /**< pressure unit */
    temperature_unit_enum temperature_unit; /**< temperature unit */
    fuel_consumption_unit_enum fuel_consumption_unit; /**< fuel consumption unit */
    } rx_unit_setting_struct;

typedef struct
    {
    uint16_t instant_consumption;   /**< instant fuel consumption (km/L) */
    uint16_t average_consumption;   /**< average fuel consumption (km/L) */
    uint16_t range_distance_km;     /**< estimate traveling range (km) */
    uint16_t average_speed_km;      /**< average speed (km) */
    } rx_fuel_rate_struct;

typedef struct
    {
    uint32_t odo_value_km;      /**< ODO meter value (km) */
    uint32_t trip1_value_km;    /**< tripmeter1 value (km) */
    uint32_t trip2_value_km;    /**< tripmeter2 value (km) */
    } rx_odo_trip_struct;

typedef struct
    {
    uint16_t aps_angle_deg;         /**< APS or TPS angle (degree) */
    uint16_t vehicle_speed_real;    /**< actual vehicle speed for navigation (km/h) */
    uint16_t vehicle_speed_meter;   /**< actual vehicle speed */
    uint16_t fuel_cons;             /**< fuel usage volume (L) */
    bool     clock_adj_status;      /**< clock adjustment status */
    uint8_t  air_temperature;       /**< intake air temperature or outside temperature (degC), H'FF: "---" */
    uint8_t  coolant_temperature;   /**< coolant temperature (degC), H'00:"Lo", H'FE:"Hi", H'FF:"---" */
    uint8_t  battery_voltage;       /**< battery voltage (Volt) */
    uint8_t  cruise_speed;          /**< cruise speed (km/h) */
    uint16_t fuel_tripmeter_km;     /**< fuel trip meter value (km) */
    bool     low_fuel_warning;      /**< low fuel warning */
    bool     fuel_reserve;          /**< fuel reserve judgement */
    odo_trip_display_enum odo_trip_display; /**< ODO/trip display */
    bool     fuel_trip_hard_reset;  /**< fuel trip meter hard reset */
    } rx_vehicle_info_struct;

typedef struct
    {
    uint32_t trip1_km;      /**< maintenance trip1 value (km) H'FF: "---" */
    uint32_t trip2_km;      /**< maintenance trip2 value (km) H'FF: "---" */
    uint32_t trip3_km;      /**< maintenance trip3 value (km) H'FF: "---" */
    } rx_maintenance_trip_struct;

typedef struct
    {
    uint8_t value_low;              /**< value of setting low */
    uint8_t value_middle;           /**< value of setting middle */
    uint8_t value_high;             /**< value of setting high */
    heater_setting_enum setting;    /**< setting of off / low / middle / high */
    } rx_heater_status_struct;

typedef struct
    {
    uint8_t fullscale;      /**< tachometer fullscale (100rpm) */
    uint8_t redzone;        /**< tachometer red zone start (100rpm) */
    } rx_tacho_setting_struct;

typedef struct
    {
    uint8_t front;              /**< front tire pressure (psi) */
    uint8_t rear;               /**< rear tire pressure (psi) */
    bool    sensor_equipped;    /**< pressure sensor equipped */
    } rx_tire_pressure_struct;

typedef enum
    {
    SUPPORTED_FUNCTION_DATA_SOURCE_UI,
    SUPPORTED_FUNCTION_DATA_SOURCE_CAN,
    SUPPORTED_FUNCTION_DATA_SOURCE_EEPROM
    } supported_func_data_src_enum;

void vi_key_init( void );
void vi_key_status_changed( const CoreKeyCode key_code, const int key_status );
void vi_key_proc( void );
void vi_rx_init( void );
void vi_trip_time_init( void );
bool vi_trip_time_get_current( uint32_t* current_trip_time_sec );
void vi_trip_time_reset( void );
void vi_clock_init( void );
void vi_clock_notify_meter_clk_adj_status_changed( const uint32_t clock_adj_status );
uint8_t vi_get_progsts( void );
void vi_clear_progsts( void );
bool vi_is_timeout_error2_detected( void );

#ifdef __cplusplus
}
#endif

#endif /* VI_PRIV_H */

