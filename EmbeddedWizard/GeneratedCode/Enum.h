/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This file was generated automatically by Embedded Wizard Studio.
*
* Please do not make any modifications of this file! The modifications are lost
* when the file is generated again by Embedded Wizard Studio!
*
* The template of this heading text can be found in the file 'head.ewt' in the
* directory 'Platforms' of your Embedded Wizard installation directory. If you
* wish to adapt this text, please copy the template file 'head.ewt' into your
* project directory and edit the copy only. Please avoid any modifications of
* the original template file!
*
* Version  : 11.00
* Profile  : iMX_RT
* Platform : NXP.iMX_RT_VGLite.RGBA8888
*
*******************************************************************************/

#ifndef Enum_H
#define Enum_H

#ifdef __cplusplus
  extern "C"
  {
#endif

#include "ewrte.h"
#if EW_RTE_VERSION != 0x000B0000
  #error Wrong version of Embedded Wizard Runtime Environment.
#endif

#include "ewgfx.h"
#if EW_GFX_VERSION != 0x000B0000
  #error Wrong version of Embedded Wizard Graphics Engine.
#endif

/* User defined enumeration: 'Enum::FactoryTest' */
typedef enum
{
  EnumFactoryTestQuit                   = 0,
  EnumFactoryTestDisplay                = 1,
  EnumFactoryTestBurnInStart            = 2,
  EnumFactoryTestBurnInTimeUpdate       = 3,
  EnumFactoryTestBurnInResult           = 4
} EnumFactoryTest;

/* User defined enumeration: 'Enum::MusicControlType' */
typedef enum
{
  EnumMusicControlTypePlay              = 0,
  EnumMusicControlTypePause             = 1,
  EnumMusicControlTypeNextTrack         = 2,
  EnumMusicControlTypePrevTrack         = 3,
  EnumMusicControlTypeVolumeUp          = 4,
  EnumMusicControlTypeVolumeDown        = 5
} EnumMusicControlType;

/* User defined enumeration: 'Enum::BtDeviceConnectionResult' */
typedef enum
{
  EnumBtDeviceConnectionResultSUCCESS   = 0,
  EnumBtDeviceConnectionResultFAIL      = 1,
  EnumBtDeviceConnectionResultAUTHENTICATION_ERR = 2
} EnumBtDeviceConnectionResult;

/* User defined enumeration: 'Enum::BtFwStatus' */
typedef enum
{
  EnumBtFwStatusNO_UPDATE               = 0,
  EnumBtFwStatusUPDATE_START            = 1,
  EnumBtFwStatusUPDATE_ABORT            = 2,
  EnumBtFwStatusUPDATE_FINISH           = 3
} EnumBtFwStatus;

/* User defined enumeration: 'Enum::RotationDirection' */
typedef enum
{
  EnumRotationDirectionCOUNTER_CLOCKWISE = 0,
  EnumRotationDirectionCLOCKWISE        = 1
} EnumRotationDirection;

/* User defined enumeration: 'Enum::LauncherItem' */
typedef enum
{
  EnumLauncherItemPHONE                 = 0,
  EnumLauncherItemMUSIC                 = 1,
  EnumLauncherItemODO_TRIP              = 2,
  EnumLauncherItemMETER_DISPLAY         = 3,
  EnumLauncherItemNAVIGATION            = 4,
  EnumLauncherItemNOTIFICATION          = 5,
  EnumLauncherItemWEATHER               = 6,
  EnumLauncherItemSETTINGS              = 7,
  EnumLauncherItemSEAT_HEATER           = 8,
  EnumLauncherItemGRIP_WARMER           = 9,
  EnumLauncherItemWIND_SCREEN           = 10,
  EnumLauncherItemTOTAL                 = 11
} EnumLauncherItem;

/* User defined enumeration: 'Enum::KeyTriggerMode' */
typedef enum
{
  EnumKeyTriggerModeON                  = 0,
  EnumKeyTriggerModeOFF                 = 1
} EnumKeyTriggerMode;

/* User defined enumeration: 'Enum::MainSettingItem' */
typedef enum
{
  EnumMainSettingItemTRACTION_CONTROL   = 0,
  EnumMainSettingItemCONNECTION         = 1,
  EnumMainSettingItemINFORMATION_RESET  = 2,
  EnumMainSettingItemCLOCK              = 3,
  EnumMainSettingItemBRIGHTNESS         = 4,
  EnumMainSettingItemUNIT               = 5,
  EnumMainSettingItemGRIP_WARMER        = 6,
  EnumMainSettingItemSEAT_HEATER        = 7,
  EnumMainSettingItemSYSTEM_INFO        = 8,
  EnumMainSettingItemLEGAL_INFO         = 9,
  EnumMainSettingItemTOTAL              = 10
} EnumMainSettingItem;

/* User defined enumeration: 'Enum::NaviSettingItem' */
typedef enum
{
  EnumNaviSettingItemStopNavigation     = 0,
  EnumNaviSettingItemSkipNextStop       = 1,
  EnumNaviSettingItemGoHome             = 2,
  EnumNaviSettingItemGoToWork           = 3,
  EnumNaviSettingItemFavorites          = 4,
  EnumNaviSettingItemNearbyGasStations  = 5,
  EnumNaviSettingItemChangeView         = 6,
  EnumNaviSettingItemTOTAL              = 7
} EnumNaviSettingItem;

/* User defined enumeration: 'Enum::MotoConTest' */
typedef enum
{
  EnumMotoConTestSTART_BLE_ADVERTISING  = 0,
  EnumMotoConTestSTOP_BLE_ADVERTISING   = 1,
  EnumMotoConTestLIBRATY_VERSION        = 2,
  EnumMotoConTestWEATHER_REQ            = 3,
  EnumMotoConTestVEHICLE_INFO           = 4,
  EnumMotoConTestVEHICLE_SETTING_REQ    = 5,
  EnumMotoConTestLANG_TYPE_REQ          = 6,
  EnumMotoConTestCAN_RELATED_DATA       = 7,
  EnumMotoConTestCAN_RESPONSE           = 8,
  EnumMotoConTestINJECTION_QUALITY      = 9,
  EnumMotoConTestMUSIC_CONTROL_PLAY     = 10,
  EnumMotoConTestMUSIC_CONTROL_PAUSE    = 11,
  EnumMotoConTestMUSIC_CONTROL_PREVIOUS = 12,
  EnumMotoConTestMUSIC_CONTROL_NEXT     = 13,
  EnumMotoConTestINCOMING_CALL_ANSWER   = 14,
  EnumMotoConTestINCOMING_CALL_DECLINE  = 15,
  EnumMotoConTestHEADSET_STATE_REQ      = 16,
  EnumMotoConTestVOLUME_CONTROL_UP      = 17,
  EnumMotoConTestVOLUME_CONTROL_DOWN    = 18,
  EnumMotoConTestMUTE_MICROPHONE        = 19,
  EnumMotoConTestMUTE_SPEAKER           = 20,
  EnumMotoConTestMEDIA_VOLUME_UP        = 21,
  EnumMotoConTestMEDIA_VOLUME_DOWN      = 22,
  EnumMotoConTestVOLUME_CONTROLLABLE_REQ = 23,
  EnumMotoConTestCREATE_OTA_REQ         = 24,
  EnumMotoConTestOTA_LINKCARD_INFO      = 25,
  EnumMotoConTestCCUID_RESPONSE         = 26,
  EnumMotoConTestPHONE_CELL_SIGNAL_LEVEL_REQ = 27
} EnumMotoConTest;

/* User defined enumeration: 'Enum::VehicleSupportedFunction' */
typedef enum
{
  EnumVehicleSupportedFunctionTRIP1     = 0,
  EnumVehicleSupportedFunctionTRIP2     = 1,
  EnumVehicleSupportedFunctionF_TRIP    = 2,
  EnumVehicleSupportedFunctionMETER_BRIGHTNESS_ADJ = 3,
  EnumVehicleSupportedFunctionCLOCK     = 4,
  EnumVehicleSupportedFunctionTCS       = 5,
  EnumVehicleSupportedFunctionGRIP_WARMER = 6,
  EnumVehicleSupportedFunctionSEAT_HEATER = 7,
  EnumVehicleSupportedFunctionWIND_SCREEN = 8,
  EnumVehicleSupportedFunctionOIL_TRIP  = 9,
  EnumVehicleSupportedFunctionV_BELT_TRIP = 10,
  EnumVehicleSupportedFunctionFREE_1    = 11,
  EnumVehicleSupportedFunctionFREE_2    = 12,
  EnumVehicleSupportedFunctionAVG_SPEED = 13,
  EnumVehicleSupportedFunctionCURRENT_FUEL = 14,
  EnumVehicleSupportedFunctionAVG_FUEL  = 15,
  EnumVehicleSupportedFunctionFUEL_CONSUMPTION = 16,
  EnumVehicleSupportedFunctionAIR_TEMPERATURE = 17,
  EnumVehicleSupportedFunctionBATTERY_VOLTAGE = 18,
  EnumVehicleSupportedFunctionCOOLANT   = 19,
  EnumVehicleSupportedFunctionRANGE_DISTANCE = 20,
  EnumVehicleSupportedFunctionTIRE_FRONT = 21,
  EnumVehicleSupportedFunctionTIRE_FRONT_RIGHT = 22,
  EnumVehicleSupportedFunctionTIRE_FRONT_LEFT = 23,
  EnumVehicleSupportedFunctionTIRE_REAR = 24,
  EnumVehicleSupportedFunctionTRIP_TIME = 25,
  EnumVehicleSupportedFunctionCRUISE    = 26,
  EnumVehicleSupportedFunctionTOTAL     = 27
} EnumVehicleSupportedFunction;

/* User defined enumeration: 'Enum::VehicleRxType' */
typedef enum
{
  EnumVehicleRxTypeENGINE_SPEED         = 0,
  EnumVehicleRxTypeTC_MODE              = 1,
  EnumVehicleRxTypeVVA_INDICATOR        = 2,
  EnumVehicleRxTypeTFT_BRIGHTNESS_LEVEL = 3,
  EnumVehicleRxTypeMETER_BRIGHTNESS_LEVEL = 4,
  EnumVehicleRxTypeMILEAGE_UNIT         = 5,
  EnumVehicleRxTypePRESSURE_UNIT        = 6,
  EnumVehicleRxTypeTEMPERATURE_UNIT     = 7,
  EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT = 8,
  EnumVehicleRxTypeFUEL_RATE_INSTANT    = 9,
  EnumVehicleRxTypeFUEL_RATE_AVERAGE    = 10,
  EnumVehicleRxTypeRANGE_DISTANCE       = 11,
  EnumVehicleRxTypeAVERAGE_SPEED        = 12,
  EnumVehicleRxTypeODOMETER_VALUE       = 13,
  EnumVehicleRxTypeTRIP1_VALUE          = 14,
  EnumVehicleRxTypeTRIP2_VALUE          = 15,
  EnumVehicleRxTypeAPS_ANGLE            = 16,
  EnumVehicleRxTypeVEHICLE_SPEED_REAL   = 17,
  EnumVehicleRxTypeVEHICLE_SPEED_METER  = 18,
  EnumVehicleRxTypeFUEL_CONSUMPTION     = 19,
  EnumVehicleRxTypeCLOCK_ADJUSTMENT_STATUS = 20,
  EnumVehicleRxTypeAIR_TEMPERATURE      = 21,
  EnumVehicleRxTypeCOOLANT_TEMPERATURE  = 22,
  EnumVehicleRxTypeBATTERY_VOLTAGE      = 23,
  EnumVehicleRxTypeCRUISE_SPEED         = 24,
  EnumVehicleRxTypeTRIP_F_VALUE         = 25,
  EnumVehicleRxTypeLOW_FUEL_WARNING     = 26,
  EnumVehicleRxTypeFUEL_RESERVE         = 27,
  EnumVehicleRxTypeODO_TRIP_DISPLAY     = 28,
  EnumVehicleRxTypeF_TRIP_HARD_RESET    = 29,
  EnumVehicleRxTypeMAINTENANCE_TRIP1    = 30,
  EnumVehicleRxTypeMAINTENANCE_TRIP2    = 31,
  EnumVehicleRxTypeMAINTENANCE_TRIP3    = 32,
  EnumVehicleRxTypeGRIP_WARMER_VALUE_LOW = 33,
  EnumVehicleRxTypeGRIP_WARMER_VALUE_MIDDLE = 34,
  EnumVehicleRxTypeGRIP_WARMER_VALUE_HIGH = 35,
  EnumVehicleRxTypeSEAT_HEATER_VALUE_LOW = 36,
  EnumVehicleRxTypeSEAT_HEATER_VALUE_MIDDLE = 37,
  EnumVehicleRxTypeSEAT_HEATER_VALUE_HIGH = 38,
  EnumVehicleRxTypeGRIP_WARMER_STATUS   = 39,
  EnumVehicleRxTypeSEAT_HEATER_STATUS   = 40,
  EnumVehicleRxTypeSUPPORT_FUNC_CLOCK   = 41,
  EnumVehicleRxTypeSUPPORT_FUNC_GRIP_WARMER = 42,
  EnumVehicleRxTypeSUPPORT_FUNC_SEAT_HEATER = 43,
  EnumVehicleRxTypeSUPPORT_FUNC_WIND_SCREEN = 44,
  EnumVehicleRxTypeSUPPORT_FUNC_AIR_TEMPERATURE = 45,
  EnumVehicleRxTypeYDT_DETECTED         = 46,
  EnumVehicleRxTypeTRIP_TIME            = 47,
  EnumVehicleRxTypeTIRE_FRONT           = 48,
  EnumVehicleRxTypeTIRE_REAR            = 49,
  EnumVehicleRxTypeTIRE_FRONT_RIGHT     = 50,
  EnumVehicleRxTypeTIRE_FRONT_LEFT      = 51,
  EnumVehicleRxTypeTIRE_SENSOR_EQUIPPED = 52,
  EnumVehicleRxTypeTFT_DUTY             = 53,
  EnumVehicleRxTypeTIMEOUT_ERROR2_DETECTED = 54,
  EnumVehicleRxTypeTIMEOUT_ERROR2_RECOVERED = 55,
  EnumVehicleRxTypeTOTAL                = 56
} EnumVehicleRxType;

/* User defined enumeration: 'Enum::VehicleTxType' */
typedef enum
{
  EnumVehicleTxTypeLANGUAGE             = 0,
  EnumVehicleTxTypeMILEAGE_UNIT         = 1,
  EnumVehicleTxTypeVEHICLE_SPEED_UNIT   = 2,
  EnumVehicleTxTypePRESSURE_UNIT        = 3,
  EnumVehicleTxTypeTEMPERATURE_UNIT     = 4,
  EnumVehicleTxTypeFUEL_CONSUMPTION_UNIT = 5,
  EnumVehicleTxTypeFUEL_UNIT            = 6,
  EnumVehicleTxTypeHEATER_SELECT        = 7,
  EnumVehicleTxTypeHEATER_LEVEL         = 8,
  EnumVehicleTxTypeBUTTON_STATUS_AUDIO  = 9,
  EnumVehicleTxTypeCLOCK_DATE           = 10,
  EnumVehicleTxTypeWIND_SCREEN_OPERATION = 11,
  EnumVehicleTxTypeMETER_BRIGHTNESS_OPERATION = 12,
  EnumVehicleTxTypeGRIP_WARMER_CHANGE_LEVEL = 13,
  EnumVehicleTxTypeSEAT_HEATER_CHANGE_LEVEL = 14,
  EnumVehicleTxTypeCHG_METER_INFO       = 15,
  EnumVehicleTxTypeTFT_BRIGHTNESS_OPERATION = 16,
  EnumVehicleTxTypeTCS                  = 17,
  EnumVehicleTxTypeRESET_METER          = 18,
  EnumVehicleTxTypeREQUEST_REPROGRAM    = 19,
  EnumVehicleTxTypeREBOOT_REQUEST       = 20,
  EnumVehicleTxTypeTOTAL                = 21
} EnumVehicleTxType;

/* User defined enumeration: 'Enum::DataType' */
typedef enum
{
  EnumDataTypeUINT32                    = 0,
  EnumDataTypeFLOAT                     = 1
} EnumDataType;

/* User defined enumeration: 'Enum::MeterDisplay' */
typedef enum
{
  EnumMeterDisplayTACHOMETER            = 0,
  EnumMeterDisplayECHO_METER            = 1,
  EnumMeterDisplaySPEED_METER           = 2
} EnumMeterDisplay;

/* User defined enumeration: 'Enum::HomeType' */
typedef enum
{
  EnumHomeTypeTACHO_VISUALIZER          = 0,
  EnumHomeTypeECO_VISUALIZER            = 1,
  EnumHomeTypeSPEED_VISUALIZER          = 2,
  EnumHomeTypeNAVI_DEFAULT_VIEW         = 3,
  EnumHomeTypeNAVI_TURN_BY_TURN         = 4,
  EnumHomeTypeNAVI_NEXT_TURN            = 5,
  EnumHomeTypeVEHICLE_INFO              = 6,
  EnumHomeTypeTOTAL                     = 7
} EnumHomeType;

/* User defined enumeration: 'Enum::BlePairingState' */
typedef enum
{
  EnumBlePairingStateIDLE               = 0,
  EnumBlePairingStateADVERTISING        = 1,
  EnumBlePairingStateSUCCESSFUL         = 2,
  EnumBlePairingStateTIMEOUT            = 3,
  EnumBlePairingStateFAIL               = 4,
  EnumBlePairingStatePINCODE_GENERATED  = 5
} EnumBlePairingState;

/* User defined enumeration: 'Enum::NaviDataType' */
typedef enum
{
  EnumNaviDataTypeCURRENT_ROAD          = 0,
  EnumNaviDataTypeETA                   = 1,
  EnumNaviDataTypeSPEED_LIMIT           = 2,
  EnumNaviDataTypeDAYNIGHT              = 3,
  EnumNaviDataTypeNAVI_EVENT            = 4,
  EnumNaviDataTypeNAVI_ROUTE_CAL_PROGRESS = 5,
  EnumNaviDataTypeDIALOG_EVENT          = 6,
  EnumNaviDataTypeVIA_POINT             = 7,
  EnumNaviDataTypeHOME                  = 8,
  EnumNaviDataTypeOFFICE                = 9,
  EnumNaviDataTypeNAVI_TBT_LIST         = 10,
  EnumNaviDataTypeNAVI_TBT_ACTIVE_TBT   = 11
} EnumNaviDataType;

/* User defined enumeration: 'Enum::NaviAlertType' */
typedef enum
{
  EnumNaviAlertTypeTRAFFIC              = 0,
  EnumNaviAlertTypeSPEED                = 1,
  EnumNaviAlertTypeCAMERA               = 2,
  EnumNaviAlertTypeBORDER               = 3,
  EnumNaviAlertTypeSCHOOL               = 4
} EnumNaviAlertType;

/* User defined enumeration: 'Enum::NaviAlertAnimationType' */
typedef enum
{
  EnumNaviAlertAnimationTypeShrink      = 0,
  EnumNaviAlertAnimationTypeDismiss     = 1
} EnumNaviAlertAnimationType;

/* User defined enumeration: 'Enum::MotoConRxEvent' */
typedef enum
{
  EnumMotoConRxEventCONNECTION_STATUS   = 0,
  EnumMotoConRxEventPHONE_BATTERY       = 1,
  EnumMotoConRxEventPHONE_LANGUAGE      = 2,
  EnumMotoConRxEventPHONE_THERMAL       = 3,
  EnumMotoConRxEventPHONE_HEADSET       = 4,
  EnumMotoConRxEventPHONE_CELL_SIGNAL_LEVEL = 5
} EnumMotoConRxEvent;

/* User defined enumeration: 'Enum::TemperatureSettingItem' */
typedef enum
{
  EnumTemperatureSettingItemTEMP_C      = 0,
  EnumTemperatureSettingItemTEMP_F      = 1
} EnumTemperatureSettingItem;

/* User defined enumeration: 'Enum::WeatherTimeType' */
typedef enum
{
  EnumWeatherTimeTypeWEATHER_CURRENT    = 0,
  EnumWeatherTimeTypeWEATHER_AFTER_1DAY = 1,
  EnumWeatherTimeTypeWEATHER_AFTER_2DAY = 2,
  EnumWeatherTimeTypeWEATHER_AFTER_3DAY = 3,
  EnumWeatherTimeTypeWEATHER_AFTER_4DAY = 4,
  EnumWeatherTimeTypeWEATHER_AFTER_5DAY = 5,
  EnumWeatherTimeTypeWEATHER_AFTER_1HOUR = 6,
  EnumWeatherTimeTypeWEATHER_AFTER_2HOUR = 7,
  EnumWeatherTimeTypeWEATHER_AFTER_3HOUR = 8,
  EnumWeatherTimeTypeWEATHER_AFTER_6DAY = 9
} EnumWeatherTimeType;

/* User defined enumeration: 'Enum::MileageSettingItem' */
typedef enum
{
  EnumMileageSettingItemKM              = 0,
  EnumMileageSettingItemMILE            = 1
} EnumMileageSettingItem;

/* User defined enumeration: 'Enum::FuelSettingItem' */
typedef enum
{
  EnumFuelSettingItemKM_L               = 0,
  EnumFuelSettingItemMPG                = 1,
  EnumFuelSettingItemL_PER_HUNDRED_KM   = 2,
  EnumFuelSettingItemTOTAL              = 3
} EnumFuelSettingItem;

/* User defined enumeration: 'Enum::PressureSettingItem' */
typedef enum
{
  EnumPressureSettingItemPSI            = 0,
  EnumPressureSettingItemKPA            = 1,
  EnumPressureSettingItemKGF_PER_CM2    = 2
} EnumPressureSettingItem;

/* User defined enumeration: 'Enum::BtcPairingState' */
typedef enum
{
  EnumBtcPairingStateIDLE               = 0,
  EnumBtcPairingStateDISCOVERABLE       = 1,
  EnumBtcPairingStateSUCCESSFUL         = 2,
  EnumBtcPairingStateTIMEOUT            = 3,
  EnumBtcPairingStateFAIL               = 4,
  EnumBtcPairingStatePASSKEY_GENERATED  = 5
} EnumBtcPairingState;

/* User defined enumeration: 'Enum::ReceptionStatus' */
typedef enum
{
  EnumReceptionStatusSUCCESS            = 0,
  EnumReceptionStatusERROR              = 1
} EnumReceptionStatus;

/* User defined enumeration: 'Enum::OperationMode' */
typedef enum
{
  EnumOperationModeNORMAL               = 0,
  EnumOperationModeFACTORY              = 1,
  EnumOperationModeINSPECTION           = 2,
  EnumOperationModePRODUCTION_TEST      = 3,
  EnumOperationModeTOTAL                = 4
} EnumOperationMode;

/* User defined enumeration: 'Enum::NaviTurnStatusType' */
typedef enum
{
  EnumNaviTurnStatusTypeDEST_FLAG       = 0,
  EnumNaviTurnStatusTypeARRVIAL_LEFT    = 1,
  EnumNaviTurnStatusTypeARRIVAL_RIGHT   = 2,
  EnumNaviTurnStatusTypeDEST_VIA_FLAG   = 3,
  EnumNaviTurnStatusTypeARRIVAL_VIA_LEFT = 4,
  EnumNaviTurnStatusTypeARRIVAL_VIA_RIGHT = 5,
  EnumNaviTurnStatusTypeKEEP_LEFT       = 6,
  EnumNaviTurnStatusTypeKEEP_RIGHT      = 7,
  EnumNaviTurnStatusTypeCONTINUE        = 8,
  EnumNaviTurnStatusTypeDRIVETO         = 9,
  EnumNaviTurnStatusTypeEXIT_LEFT       = 10,
  EnumNaviTurnStatusTypeEXIT_RIGHT      = 11,
  EnumNaviTurnStatusTypeEXIT_UNSPEC     = 12,
  EnumNaviTurnStatusTypeFERRY           = 13,
  EnumNaviTurnStatusTypeROUNDABOUT_GEN  = 14,
  EnumNaviTurnStatusTypeROUNDABOUT_45   = 15,
  EnumNaviTurnStatusTypeROUNDABOUT_90   = 16,
  EnumNaviTurnStatusTypeROUNDABOUT_135  = 17,
  EnumNaviTurnStatusTypeROUNDABOUT_180  = 18,
  EnumNaviTurnStatusTypeROUNDABOUT_225  = 19,
  EnumNaviTurnStatusTypeROUNDABOUT_270  = 20,
  EnumNaviTurnStatusTypeROUNDABOUT_315  = 21,
  EnumNaviTurnStatusTypeROUNDABOUT_360  = 22,
  EnumNaviTurnStatusTypeROUNDABOUT_EU_GEN = 23,
  EnumNaviTurnStatusTypeROUNDABOUT_EU_45 = 24,
  EnumNaviTurnStatusTypeROUNDABOUT_EU_90 = 25,
  EnumNaviTurnStatusTypeROUNDABOUT_EU_135 = 26,
  EnumNaviTurnStatusTypeROUNDABOUT_EU_180 = 27,
  EnumNaviTurnStatusTypeROUNDABOUT_EU_225 = 28,
  EnumNaviTurnStatusTypeROUNDABOUT_EU_270 = 29,
  EnumNaviTurnStatusTypeROUNDABOUT_EU_315 = 30,
  EnumNaviTurnStatusTypeROUNDABOUT_EU_360 = 31,
  EnumNaviTurnStatusTypeSHARP_TURN_LEFT = 32,
  EnumNaviTurnStatusTypeSHARP_TURN_RIGHT = 33,
  EnumNaviTurnStatusTypeTURN_LEFT       = 34,
  EnumNaviTurnStatusTypeTURN_RIGHT      = 35,
  EnumNaviTurnStatusTypeUTURN_LEFT      = 36,
  EnumNaviTurnStatusTypeUTURN_RIGHT     = 37
} EnumNaviTurnStatusType;

/* User defined enumeration: 'Enum::SeatHeaterGripWarmerLevelType' */
typedef enum
{
  EnumSeatHeaterGripWarmerLevelTypeLOW  = 0,
  EnumSeatHeaterGripWarmerLevelTypeMID  = 1,
  EnumSeatHeaterGripWarmerLevelTypeHIGH = 2
} EnumSeatHeaterGripWarmerLevelType;

/* User defined enumeration: 'Enum::NotificationCategory' */
typedef enum
{
  EnumNotificationCategoryMESSAGE       = 0,
  EnumNotificationCategoryMISSED_CALL   = 1,
  EnumNotificationCategoryTOTAL         = 2
} EnumNotificationCategory;

/* User defined enumeration: 'Enum::PhoneCallState' */
typedef enum
{
  EnumPhoneCallStateIDLE                = 0,
  EnumPhoneCallStateINCOMING_STARTED    = 1,
  EnumPhoneCallStateINCOMING_STOPPED    = 2,
  EnumPhoneCallStateACTIVE              = 3,
  EnumPhoneCallStateTOTAL               = 4
} EnumPhoneCallState;

/* User defined enumeration: 'Enum::VolumeControl' */
typedef enum
{
  EnumVolumeControlUP                   = 0,
  EnumVolumeControlDOWN                 = 1,
  EnumVolumeControlTOTAL                = 2
} EnumVolumeControl;

/* User defined enumeration: 'Enum::HeaterSettingStatusType' */
typedef enum
{
  EnumHeaterSettingStatusTypeOFF        = 0,
  EnumHeaterSettingStatusTypeLOW        = 1,
  EnumHeaterSettingStatusTypeMID        = 2,
  EnumHeaterSettingStatusTypeHIGH       = 3
} EnumHeaterSettingStatusType;

/* User defined enumeration: 'Enum::InspectionDisplay' */
typedef enum
{
  EnumInspectionDisplayKEEP_CURRENT     = 0,
  EnumInspectionDisplayCOLOR_GRADIENT   = 1,
  EnumInspectionDisplayFULL_BLACK       = 2,
  EnumInspectionDisplayFULL_WHITE       = 3,
  EnumInspectionDisplayFULL_RED         = 4,
  EnumInspectionDisplayFULL_GREEN       = 5,
  EnumInspectionDisplayFULL_BLUE        = 6,
  EnumInspectionDisplayFLICKER          = 7,
  EnumInspectionDisplayCROSSTALK        = 8,
  EnumInspectionDisplayTOTAL            = 9
} EnumInspectionDisplay;

/* User defined enumeration: 'Enum::InspectionMode' */
typedef enum
{
  EnumInspectionModeNONE                = 0,
  EnumInspectionModeDISPLAY             = 1,
  EnumInspectionModeBLUETOOTH           = 2,
  EnumInspectionModeEND                 = 3
} EnumInspectionMode;

/* User defined enumeration: 'Enum::HomeGroup' */
typedef enum
{
  EnumHomeGroupNONE                     = 0,
  EnumHomeGroupMETER                    = 1,
  EnumHomeGroupNAVIGATION               = 2,
  EnumHomeGroupVEHICLE_INFO             = 3
} EnumHomeGroup;

/* User defined enumeration: 'Enum::NavigationView' */
typedef enum
{
  EnumNavigationViewDEFAULT_VIEW        = 0,
  EnumNavigationViewTURN_BY_TURN        = 1,
  EnumNavigationViewNEXT_TURN           = 2
} EnumNavigationView;

/* User defined enumeration: 'Enum::EEPROMTest' */
typedef enum
{
  EnumEEPROMTestWRITE_LAST_PAGE_FF      = 0,
  EnumEEPROMTestREAD_LAST_PAGE          = 1,
  EnumEEPROMTestWRITE_TEST_UNIT_ID      = 2,
  EnumEEPROMTestREAD_UNIT_ID            = 3,
  EnumEEPROMTestCLEAR_UNIT_ID           = 4,
  EnumEEPROMTestTOTAL                   = 5
} EnumEEPROMTest;

/* User defined enumeration: 'Enum::Language' */
typedef enum
{
  EnumLanguageENGLISH                   = 0,
  EnumLanguageFRENCH                    = 1,
  EnumLanguageGERMAN                    = 2,
  EnumLanguageITALIAN                   = 3,
  EnumLanguageJAPANESE                  = 4,
  EnumLanguageSPANISH                   = 5,
  EnumLanguageTRADITIONAL_CHINESE       = 6,
  EnumLanguageSIMPLIFIED_CHINESE        = 7,
  EnumLanguageGREEK                     = 8,
  EnumLanguageFINNISH                   = 9,
  EnumLanguageHINDI                     = 10,
  EnumLanguageINDONESIAN                = 11,
  EnumLanguagePOLISH                    = 12,
  EnumLanguagePORTUGUESE                = 13,
  EnumLanguageTHAI                      = 14,
  EnumLanguageVIETNAMESE                = 15,
  EnumLanguageKOREAN                    = 16,
  EnumLanguageMALAY                     = 17,
  EnumLanguageTOTAL                     = 18
} EnumLanguage;

/* User defined enumeration: 'Enum::NaviCameraType' */
typedef enum
{
  EnumNaviCameraTypeCHECK_FIXED         = 0,
  EnumNaviCameraTypeCHECK_TEMPORARY     = 1,
  EnumNaviCameraTypeMOBILE              = 2,
  EnumNaviCameraTypeAVERAGE             = 3,
  EnumNaviCameraTypeVARIABLE            = 4,
  EnumNaviCameraTypeRED_LIGHT           = 5,
  EnumNaviCameraTypeUSER                = 6,
  EnumNaviCameraTypeMOBILE_ZONE         = 7,
  EnumNaviCameraTypeDANGEROUS_ZONE      = 8,
  EnumNaviCameraTypeDANGEROUS_POINT     = 9,
  EnumNaviCameraTypeRISK_ZONE           = 10,
  EnumNaviCameraTypeUNKNOWN             = 11
} EnumNaviCameraType;

/* User defined enumeration: 'Enum::TimeType' */
typedef enum
{
  EnumTimeTypeYEAR                      = 0,
  EnumTimeTypeMONTH                     = 1,
  EnumTimeTypeDAY                       = 2,
  EnumTimeTypeFORMAT                    = 3,
  EnumTimeTypeHOUR                      = 4,
  EnumTimeTypeMINUTE                    = 5
} EnumTimeType;

/* User defined enumeration: 'Enum::MeterInfo' */
typedef enum
{
  EnumMeterInfoODO                      = 0,
  EnumMeterInfoTRIP1                    = 1,
  EnumMeterInfoTRIP2                    = 2,
  EnumMeterInfoTRIP_F                   = 3,
  EnumMeterInfoAVG_SPEED                = 4,
  EnumMeterInfoAVG_FUEL                 = 5,
  EnumMeterInfoFUEL_CONSUMPTION         = 6,
  EnumMeterInfoMAINTENANCE_TRIP1        = 7,
  EnumMeterInfoMAINTENANCE_TRIP2        = 8,
  EnumMeterInfoMAINTENANCE_TRIP3        = 9,
  EnumMeterInfoTRIP_TIME                = 10,
  EnumMeterInfoTOTAL                    = 11
} EnumMeterInfo;

/* User defined enumeration: 'Enum::OdoTripSettingItem' */
typedef enum
{
  EnumOdoTripSettingItemODO             = 0,
  EnumOdoTripSettingItemTRIP1           = 1,
  EnumOdoTripSettingItemTRIP2           = 2,
  EnumOdoTripSettingItemTRIP_F          = 3,
  EnumOdoTripSettingItemTOTAL           = 4
} EnumOdoTripSettingItem;

/* User defined enumeration: 'Enum::MaintenanceResetMenuItem' */
typedef enum
{
  EnumMaintenanceResetMenuItemOIL       = 0,
  EnumMaintenanceResetMenuItemV_BELT    = 1,
  EnumMaintenanceResetMenuItemFREE1     = 2,
  EnumMaintenanceResetMenuItemFREE2     = 3,
  EnumMaintenanceResetMenuItemTOTAL     = 4
} EnumMaintenanceResetMenuItem;

/* Meter fuel consumption unit defined in CAN H'5A0 */
typedef enum
{
  EnumMeterFuelConsumptionUnitKM_PER_LITER = 0,
  EnumMeterFuelConsumptionUnitMILE_PER_US_GAL = 1,
  EnumMeterFuelConsumptionUnitMILE_PER_IMPERIAL_GAL = 2,
  EnumMeterFuelConsumptionUnitL_PER_100KM = 3,
  EnumMeterFuelConsumptionUnitTOTAL     = 4
} EnumMeterFuelConsumptionUnit;

/* User defined enumeration: 'Enum::NaviDialogType' */
typedef enum
{
  EnumNaviDialogTypeDIALOG_OK           = 0,
  EnumNaviDialogTypeDIALOG_OK_CANCEL    = 1,
  EnumNaviDialogTypeDIALOG_YES_NO       = 2,
  EnumNaviDialogTypeDIALOG_YES_NO_CANCEL = 3,
  EnumNaviDialogTypeDIALOG_DISMISS      = 4,
  EnumNaviDialogTypeDIALOG_TOTAL        = 5
} EnumNaviDialogType;

/* User defined enumeration: 'Enum::NaviButtonType' */
typedef enum
{
  EnumNaviButtonTypeOK                  = 0,
  EnumNaviButtonTypeCANCEL              = 1,
  EnumNaviButtonTypeYES                 = 2,
  EnumNaviButtonTypeNO                  = 3,
  EnumNaviButtonTypeTOTAL               = 4
} EnumNaviButtonType;

/* User defined enumeration: 'Enum::VehicleInfoMenuItem' */
typedef enum
{
  EnumVehicleInfoMenuItemAVG_SPEED      = 0,
  EnumVehicleInfoMenuItemAVG_FUEL       = 1,
  EnumVehicleInfoMenuItemINST_FUEL      = 2,
  EnumVehicleInfoMenuItemTRIP_TIME      = 3,
  EnumVehicleInfoMenuItemRANGE          = 4,
  EnumVehicleInfoMenuItemFUEL_CONSUMPTION = 5,
  EnumVehicleInfoMenuItemAIR_TEMPERATURE = 6,
  EnumVehicleInfoMenuItemCOOLANT_TEMPERATURE = 7,
  EnumVehicleInfoMenuItemBATTERY        = 8,
  EnumVehicleInfoMenuItemTIRE_FRONT_RIGHT = 9,
  EnumVehicleInfoMenuItemTIRE_FRONT_LEFT = 10,
  EnumVehicleInfoMenuItemTIRE_FRONT     = 11,
  EnumVehicleInfoMenuItemTIRE_REAR      = 12,
  EnumVehicleInfoMenuItemCRUISE         = 13,
  EnumVehicleInfoMenuItemTOTAL          = 14
} EnumVehicleInfoMenuItem;

/* User defined enumeration: 'Enum::NaviZoomInOutStatusType' */
typedef enum
{
  EnumNaviZoomInOutStatusTypeREACH_MAXIMUM = 0,
  EnumNaviZoomInOutStatusTypeREACH_MINIMUM = 1,
  EnumNaviZoomInOutStatusTypeNORMAL     = 2
} EnumNaviZoomInOutStatusType;

/* User defined enumeration: 'Enum::SystemRxEvent' */
typedef enum
{
  EnumSystemRxEventSW_UPDATE_ENABLE     = 0,
  EnumSystemRxEventSW_UPDATE_DISABLE    = 1,
  EnumSystemRxEventREPROGRAM_ACCEPTED   = 2,
  EnumSystemRxEventREPROGRAM_REJECTED   = 3,
  EnumSystemRxEventFACTORY_RESET_COMPLETED = 4,
  EnumSystemRxEventREBOOT_ACCEPTED      = 5,
  EnumSystemRxEventREBOOT_REJECTED      = 6,
  EnumSystemRxEventTFT_DERATING_ON      = 7,
  EnumSystemRxEventTFT_DERATING_OFF     = 8,
  EnumSystemRxEventUNIT_ID_UPDATED      = 9,
  EnumSystemRxEventUNIT_ID_READ_OK      = 10,
  EnumSystemRxEventQRCODE_READY         = 11,
  EnumSystemRxEventTOTAL                = 12
} EnumSystemRxEvent;

/* User defined enumeration: 'Enum::MotoConTx' */
typedef enum
{
  EnumMotoConTxCREATE_OTA_CONNECTION    = 0,
  EnumMotoConTxTOTAL                    = 1
} EnumMotoConTx;

/* User defined enumeration: 'Enum::WeatherIconType' */
typedef enum
{
  EnumWeatherIconTypeSUNNY              = 0,
  EnumWeatherIconTypePARTLY_CLOUDY_DAY  = 1,
  EnumWeatherIconTypeCLOUDY_DAY         = 2,
  EnumWeatherIconTypeRAIN               = 3,
  EnumWeatherIconTypeSNOW               = 4,
  EnumWeatherIconTypeWIND               = 5,
  EnumWeatherIconTypeRAIN_STORM_MIX     = 6,
  EnumWeatherIconTypeRAIN_SNOW_MIX      = 7,
  EnumWeatherIconTypeFOG                = 8,
  EnumWeatherIconTypeSMOG               = 9,
  EnumWeatherIconTypeHAIL               = 10,
  EnumWeatherIconTypeSCATTERED_SHOWERS_DAY = 11,
  EnumWeatherIconTypeSCATTERED_STORM_DAY = 12,
  EnumWeatherIconTypeNO_DATA            = 13,
  EnumWeatherIconTypeRAIN_LIGHT         = 14,
  EnumWeatherIconTypeRAIN_HEAVY         = 15,
  EnumWeatherIconTypeSNOW_LIGHT         = 16,
  EnumWeatherIconTypeSNOW_HEAVY         = 17,
  EnumWeatherIconTypeRAIN_SNOW_MIX_LIGHT = 18,
  EnumWeatherIconTypeRAIN_SNOW_MIX_HEAVY = 19,
  EnumWeatherIconTypeCLOUDY             = 20,
  EnumWeatherIconTypeCLEAR              = 21,
  EnumWeatherIconTypePARTLY_CLOUDY_NIGHT = 22,
  EnumWeatherIconTypeCLOUDY_NIGHT       = 23,
  EnumWeatherIconTypeSCATTERED_SHOWERS_NIGHT = 24,
  EnumWeatherIconTypeSCATTERED_STORM_NIGHT = 25
} EnumWeatherIconType;

/* User defined enumeration: 'Enum::SystemTxCmd' */
typedef enum
{
  EnumSystemTxCmdENABLE_TFT_BRIGHTNESS_MANUAL_ADJ = 0,
  EnumSystemTxCmdDISABLE_TFT_BRIGHTNESS_MANUAL_ADJ = 1,
  EnumSystemTxCmdADJ_TFT_BRIGHTNESS_LEVEL_UP = 2,
  EnumSystemTxCmdADJ_TFT_BRIGHTNESS_LEVEL_DOWN = 3,
  EnumSystemTxCmdTOTAL                  = 4
} EnumSystemTxCmd;

/* User defined enumeration: 'Enum::SystemStatus' */
typedef enum
{
  EnumSystemStatusIS_TFT_BRIGHTNESS_LEVEL_MAX = 0,
  EnumSystemStatusIS_TFT_BRIGHTNESS_LEVEL_MIN = 1,
  EnumSystemStatusIS_TFT_DERATING_ON    = 2,
  EnumSystemStatusIS_QRCODE_READY       = 3,
  EnumSystemStatusTOTAL                 = 4
} EnumSystemStatus;

/* User defined enumeration: 'Enum::NotificationNativeCall' */
typedef enum
{
  EnumNotificationNativeCallMOVE_SELECTED_IDX = 0,
  EnumNotificationNativeCallGET_SELECTED_IDX = 1,
  EnumNotificationNativeCallDELETE_SELECTED_NOTIFICATION = 2,
  EnumNotificationNativeCallTOTAL       = 3
} EnumNotificationNativeCall;

#ifdef __cplusplus
  }
#endif

#endif /* Enum_H */

/* Embedded Wizard */
