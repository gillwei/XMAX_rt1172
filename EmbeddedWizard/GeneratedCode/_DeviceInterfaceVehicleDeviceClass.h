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
* Version  : 10.00
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
#if EW_RTE_VERSION != 0x000A0000
  #error Wrong version of Embedded Wizard Runtime Environment.
#endif

#include "ewgfx.h"
#if EW_GFX_VERSION != 0x000A0000
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

#ifdef __cplusplus
  }
#endif

#endif /* _DeviceInterfaceVehicleDeviceClass_H */

/* Embedded Wizard */
