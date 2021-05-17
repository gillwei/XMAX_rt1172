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

#ifndef _DeviceInterfaceVehicleDeviceClass_H
#define _DeviceInterfaceVehicleDeviceClass_H

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

#include "_CoreSystemEvent.h"
#include "_TemplatesDeviceClass.h"

/* Forward declaration of the class DeviceInterface::VehicleDataClass */
#ifndef _DeviceInterfaceVehicleDataClass_
  EW_DECLARE_CLASS( DeviceInterfaceVehicleDataClass )
#define _DeviceInterfaceVehicleDataClass_
#endif

/* Forward declaration of the class DeviceInterface::VehicleDeviceClass */
#ifndef _DeviceInterfaceVehicleDeviceClass_
  EW_DECLARE_CLASS( DeviceInterfaceVehicleDeviceClass )
#define _DeviceInterfaceVehicleDeviceClass_
#endif


/* Deklaration of class : 'DeviceInterface::VehicleDeviceClass' */
EW_DEFINE_FIELDS( DeviceInterfaceVehicleDeviceClass, TemplatesDeviceClass )
  EW_OBJECT  ( DDModeStateChangedSystemEvent, CoreSystemEvent )
  EW_OBJECT  ( VehicleDataReceivedSystemEvent, CoreSystemEvent )
  EW_PROPERTY( AvgSpeedStr,     XString )
  EW_PROPERTY( AvgFuelRateStr,  XString )
  EW_PROPERTY( FuelConStr,      XString )
  EW_PROPERTY( TripTimeHourStr, XString )
  EW_PROPERTY( TripTimeMinuteStr, XString )
  EW_PROPERTY( CoolantTemperatureStr, XString )
  EW_PROPERTY( InstantFuelRateStr, XString )
  EW_PROPERTY( RangeStr,        XString )
  EW_PROPERTY( BatteryStr,      XString )
  EW_PROPERTY( AirTemperatureStr, XString )
  EW_PROPERTY( CruiseSpeedStr,  XString )
  EW_PROPERTY( PressureUnit,    XEnum )
  EW_PROPERTY( TemperatureUnit, XEnum )
  EW_PROPERTY( FuelConsumptionUnit, XEnum )
  EW_PROPERTY( MileageUnit,     XEnum )
  EW_VARIABLE( CurrentVehicleFunction, XEnum )
  EW_VARIABLE( CurrentTempSetting, XEnum )
  EW_VARIABLE( CurrentPressureSetting, XEnum )
  EW_VARIABLE( CurrentFuelSetting, XEnum )
  EW_VARIABLE( CurrentMileageSetting, XEnum )
  EW_VARIABLE( CurrentMeterDisplay, XEnum )
  EW_PROPERTY( DDModeActivated, XBool )
EW_END_OF_FIELDS( DeviceInterfaceVehicleDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::VehicleDeviceClass' */
EW_DEFINE_METHODS( DeviceInterfaceVehicleDeviceClass, TemplatesDeviceClass )
EW_END_OF_METHODS( DeviceInterfaceVehicleDeviceClass )

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceVehicleDeviceClass_NotifyDDModeStateChanged( DeviceInterfaceVehicleDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::VehicleDeviceClass.NotifyDDModeStateChanged()' */
void DeviceInterfaceVehicleDeviceClass__NotifyDDModeStateChanged( void* _this );

/* The following define announces the presence of the method DeviceInterface::VehicleDeviceClass.NotifyDDModeStateChanged(). */
#define _DeviceInterfaceVehicleDeviceClass__NotifyDDModeStateChanged_

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetDDModeActivated()' */
XBool DeviceInterfaceVehicleDeviceClass_OnGetDDModeActivated( DeviceInterfaceVehicleDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.IsVehicleFunctionSupported()' */
XBool DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( DeviceInterfaceVehicleDeviceClass _this, 
  XEnum aVehicleFeature );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.SetData()' */
void DeviceInterfaceVehicleDeviceClass_SetData( DeviceInterfaceVehicleDeviceClass _this, 
  XEnum aVehicleTxType, XUInt32 aData );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.GetData()' */
DeviceInterfaceVehicleDataClass DeviceInterfaceVehicleDeviceClass_GetData( DeviceInterfaceVehicleDeviceClass _this, 
  XEnum aVehicleRxType );

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceVehicleDeviceClass_NotifyDataReceived( DeviceInterfaceVehicleDeviceClass _this, 
  XEnum aRxType );

/* Wrapper function for the non virtual method : 'DeviceInterface::VehicleDeviceClass.NotifyDataReceived()' */
void DeviceInterfaceVehicleDeviceClass__NotifyDataReceived( void* _this, XEnum aRxType );

/* The following define announces the presence of the method DeviceInterface::VehicleDeviceClass.NotifyDataReceived(). */
#define _DeviceInterfaceVehicleDeviceClass__NotifyDataReceived_

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.ClampDataUInt32()' */
XUInt32 DeviceInterfaceVehicleDeviceClass_ClampDataUInt32( DeviceInterfaceVehicleDeviceClass _this, 
  XUInt32 aData, XUInt32 aMin, XUInt32 aMax );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.ClampDataFloat()' */
XFloat DeviceInterfaceVehicleDeviceClass_ClampDataFloat( DeviceInterfaceVehicleDeviceClass _this, 
  XFloat aData, XFloat aMin, XFloat aMax );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.RoundDownDataFloat()' */
XFloat DeviceInterfaceVehicleDeviceClass_RoundDownDataFloat( DeviceInterfaceVehicleDeviceClass _this, 
  XFloat aData, XFloat aResolution );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetMileageUnit()' */
XEnum DeviceInterfaceVehicleDeviceClass_OnGetMileageUnit( DeviceInterfaceVehicleDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetFuelConsumptionUnit()' */
XEnum DeviceInterfaceVehicleDeviceClass_OnGetFuelConsumptionUnit( DeviceInterfaceVehicleDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetAvgSpeedStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetAvgSpeedStr( DeviceInterfaceVehicleDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetAvgFuelRateStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetAvgFuelRateStr( DeviceInterfaceVehicleDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetFuelConStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetFuelConStr( DeviceInterfaceVehicleDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetTripTimeHourStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetTripTimeHourStr( DeviceInterfaceVehicleDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetTripTimeMinuteStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetTripTimeMinuteStr( DeviceInterfaceVehicleDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetTemperatureUnit()' */
XEnum DeviceInterfaceVehicleDeviceClass_OnGetTemperatureUnit( DeviceInterfaceVehicleDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetCoolantTemperatureStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetCoolantTemperatureStr( DeviceInterfaceVehicleDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetInstantFuelRateStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetInstantFuelRateStr( DeviceInterfaceVehicleDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.ConvertFuelCons()' */
XFloat DeviceInterfaceVehicleDeviceClass_ConvertFuelCons( DeviceInterfaceVehicleDeviceClass _this, 
  XFloat aFuelCons );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetRangeStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetRangeStr( DeviceInterfaceVehicleDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetBatteryStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetBatteryStr( DeviceInterfaceVehicleDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetPressureUnit()' */
XEnum DeviceInterfaceVehicleDeviceClass_OnGetPressureUnit( DeviceInterfaceVehicleDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.ConvertFuelRate()' */
XFloat DeviceInterfaceVehicleDeviceClass_ConvertFuelRate( DeviceInterfaceVehicleDeviceClass _this, 
  XFloat aFuelRate );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetAirTemperatureStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetAirTemperatureStr( DeviceInterfaceVehicleDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::VehicleDeviceClass.OnGetCruiseSpeedStr()' */
XString DeviceInterfaceVehicleDeviceClass_OnGetCruiseSpeedStr( DeviceInterfaceVehicleDeviceClass _this );

#ifdef __cplusplus
  }
#endif

#endif /* _DeviceInterfaceVehicleDeviceClass_H */

/* Embedded Wizard */
