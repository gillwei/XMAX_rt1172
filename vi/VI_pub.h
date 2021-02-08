/*********************************************************************
* @file
* VI_pub.h
*
* @brief
* Vehicle information module - public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef VI_PUB_H
#define VI_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>
#include <stdint.h>
#include "CAN_pub.h"

#define CAN_TIMEOUT_ERROR_1     ( 1 )
#define CAN_TIMEOUT_ERROR_2     ( 2 )

#define TCS_MODE_OFF            ( 0 )
#define TCS_MODE_ON             ( 1 )

#define INVALID_INSTANT_CONSUMPTION         ( 0x3FF )
#define INVALID_AVERAGE_CONSUMPTION         ( 0x3FF )
#define INVALID_RANGE_DISTANCE              ( 0x3FF )
#define INVALID_AVERAGE_SPEED               ( 0x3FF )

#define INVALID_ODO_VALUE                   ( 0xFFFFFF )
#define INVALID_TRIP1_VALUE                 ( 0xFFFFF )
#define INVALID_TRIP2_VALUE                 ( 0xFFFFF )

#define INVALID_FUEL_CONS                   ( 0x1FF )
#define INVALID_AIR_TEMPERATURE             ( 0xFF )
#define INVALID_COOLANT_TEMPERATURE         ( 0xFF )
#define INVALID_BATTERY_VOLTAGE             ( 0xFF )
#define INVALID_CRUISE_SPEED                ( 0xFF )
#define INVALID_FUEL_TRIPMETER              ( 0x3FFF )

#define INVALID_MAINTENANCE_TRIP            ( 0x3FFFF )

#define DEFAULT_GRIP_WARMER_LOW_VALUE       ( 0x1 )
#define DEFAULT_GRIP_WARMER_MIDDLE_VALUE    ( 0x5 )
#define DEFAULT_GRIP_WARMER_HIGH_VALUE      ( 0xA )

#define DEFAULT_SEAT_HEATER_LOW_VALUE       ( 0x1 )
#define DEFAULT_SEAT_HEATER_MIDDLE_VALUE    ( 0x5 )
#define DEFAULT_SEAT_HEATER_HIGH_VALUE      ( 0xA )

#define DEFALUT_LCD_BRIGHTNESS_LEVEL        ( 0x0 )
#define DEFALUT_TFT_BRIGHTNESS_LEVEL        ( 0x3 )
#define DEFALUT_TFT_DUTY                    ( 0x3FF )

#define DEFAULT_TACHO_FULLSCALE             ( 0xFF )
#define DEFAULT_TACHO_REDZONE               ( 0xFF )

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
    FUEL_UNIT_KM_L        = 0,
    FUEL_UNIT_MILE_GAL    = 1,
    FUEL_UNIT_MILE_LMPGAL = 2,
    FUEL_UNIT_L_100KM     = 3,
    FUEL_UNIT_TOTAL
    } fuel_unit_enum;

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
    fuel_unit_enum        fuel_unit;        /**< fuel unit */
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
    int8_t   air_temperature;       /**< intake air temperature or outside temperature (degC), H'FF: "---" */
    int8_t   coolant_temperature;   /**< coolant temperature (degC), H'00:"Lo", H'FE:"Hi", H'FF:"---" */
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

/* note: this define should be consistent with EnumVehicleFeature in Enum.h */
typedef enum
    {
    VEHICLE_FEATURE_TRIP1            = 0,
    VEHICLE_FEATURE_TRIP2            = 1,
    VEHICLE_FEATURE_F_TRIP           = 2,
    VEHICLE_FEATURE_METER_BRIGHTNESS_ADJ = 3,
    VEHICLE_FEATURE_CLOCK            = 4,
    VEHICLE_FEATURE_TCS              = 5,
    VEHICLE_FEATURE_GRIP_HEATER      = 6,
    VEHICLE_FEATURE_SEAT_HEATER      = 7,
    VEHICLE_FEATURE_WIND_SCREEN      = 8,
    VEHICLE_FEATURE_OIL_TRIP         = 9,    /**< maintenance oil trip */
    VEHICLE_FEATURE_V_BELT_TRIP      = 10,   /**< maintenance V-Belt trip */
    VEHICLE_FEATURE_FREE1            = 11,   /**< maintenance trip1 */
    VEHICLE_FEATURE_FREE2            = 12,   /**< maintenance trip2 */
    VEHICLE_FEATURE_AVG_SPEED        = 13,
    VEHICLE_FEATURE_CURRENT_FUEL     = 14,
    VEHICLE_FEATURE_AVG_FUEL         = 15,
    VEHICLE_FEATURE_FUEL_CONSUMPTION = 16,
    VEHICLE_FEATURE_AIR_TEMPERATURE  = 17,
    VEHICLE_FEATURE_BATTERY_VOLTAGE  = 18,
    VEHICLE_FEATURE_COOLANT          = 19,
    VEHICLE_FEATURE_DRIVING_RANGE    = 20,
    VEHICLE_FEATURE_TIRE_FRONT       = 21,   /**< front tire pressure */
    VEHICLE_FEATURE_TIRE_FRONT_RIGHT = 22,   /**< front right tire pressure */
    VEHICLE_FEATURE_TIRE_FRONT_LEFT  = 23,   /**< front left tire pressure */
    VEHICLE_FEATURE_TIRE_REAR        = 24,   /**< rear tire pressure */
    VEHICLE_FEATURE_TRIP_TIME        = 25,
    VEHICLE_FEATURE_CRUISE           = 26
    } vehicle_feature_enum;

void VI_init( void );
void VI_notify_vehicle_data_changed( const il_rx_frm_index_t message_frame, const uint16_t signal_id, const uint32_t data );
bool VI_is_dd_mode_activated( void );
bool VI_is_feature_supported( vehicle_feature_enum feature );
void VI_set_feature_supported( vehicle_feature_enum feature, bool supported );

#ifdef __cplusplus
}
#endif

#endif /* VI_PUB_H */

