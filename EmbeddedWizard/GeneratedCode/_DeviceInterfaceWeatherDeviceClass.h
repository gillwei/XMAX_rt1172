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

#ifndef _DeviceInterfaceWeatherDeviceClass_H
#define _DeviceInterfaceWeatherDeviceClass_H

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

#include "_TemplatesDeviceClass.h"

/* Forward declaration of the class DeviceInterface::WeatherDeviceClass */
#ifndef _DeviceInterfaceWeatherDeviceClass_
  EW_DECLARE_CLASS( DeviceInterfaceWeatherDeviceClass )
#define _DeviceInterfaceWeatherDeviceClass_
#endif


/* Deklaration of class : 'DeviceInterface::WeatherDeviceClass' */
EW_DEFINE_FIELDS( DeviceInterfaceWeatherDeviceClass, TemplatesDeviceClass )
  EW_VARIABLE( WeatherLocation, XString )
  EW_PROPERTY( IsWeatherInfoReceived, XInt32 )
  EW_PROPERTY( IsWeatherLocReceived, XInt32 )
  EW_VARIABLE( WeatherTime,     XInt32 )
  EW_VARIABLE( Temperature,     XInt32 )
  EW_VARIABLE( MaxTemperature,  XInt32 )
  EW_VARIABLE( WeatherType,     XInt32 )
  EW_VARIABLE( MinTemperature,  XInt32 )
  EW_VARIABLE( RainProbability, XInt32 )
EW_END_OF_FIELDS( DeviceInterfaceWeatherDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::WeatherDeviceClass' */
EW_DEFINE_METHODS( DeviceInterfaceWeatherDeviceClass, TemplatesDeviceClass )
EW_END_OF_METHODS( DeviceInterfaceWeatherDeviceClass )

/* 'C' function for method : 'DeviceInterface::WeatherDeviceClass.GetWeatherInfo()' */
void DeviceInterfaceWeatherDeviceClass_GetWeatherInfo( DeviceInterfaceWeatherDeviceClass _this, 
  XInt32 aWeaItemIdx );

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceWeatherDeviceClass_NotifyWeatherInfoUpdated( DeviceInterfaceWeatherDeviceClass _this, 
  XInt32 aWeatherTime, XInt32 aWeatherType, XInt32 aTemp, XInt32 aMaxTemp, XInt32 
  aMinTemp, XInt32 aRainProb );

/* Wrapper function for the non virtual method : 'DeviceInterface::WeatherDeviceClass.NotifyWeatherInfoUpdated()' */
void DeviceInterfaceWeatherDeviceClass__NotifyWeatherInfoUpdated( void* _this, XInt32 
  aWeatherTime, XInt32 aWeatherType, XInt32 aTemp, XInt32 aMaxTemp, XInt32 aMinTemp, 
  XInt32 aRainProb );

/* The following define announces the presence of the method DeviceInterface::WeatherDeviceClass.NotifyWeatherInfoUpdated(). */
#define _DeviceInterfaceWeatherDeviceClass__NotifyWeatherInfoUpdated_

/* 'C' function for method : 'DeviceInterface::WeatherDeviceClass.NotifyWeatherLocationUpdated()' */
void DeviceInterfaceWeatherDeviceClass_NotifyWeatherLocationUpdated( DeviceInterfaceWeatherDeviceClass _this, 
  XString aWeatherLoc );

/* Wrapper function for the non virtual method : 'DeviceInterface::WeatherDeviceClass.NotifyWeatherLocationUpdated()' */
void DeviceInterfaceWeatherDeviceClass__NotifyWeatherLocationUpdated( void* _this, 
  XString aWeatherLoc );

/* The following define announces the presence of the method DeviceInterface::WeatherDeviceClass.NotifyWeatherLocationUpdated(). */
#define _DeviceInterfaceWeatherDeviceClass__NotifyWeatherLocationUpdated_

/* 'C' function for method : 'DeviceInterface::WeatherDeviceClass.OnSetIsWeatherInfoReceived()' */
void DeviceInterfaceWeatherDeviceClass_OnSetIsWeatherInfoReceived( DeviceInterfaceWeatherDeviceClass _this, 
  XInt32 value );

/* 'C' function for method : 'DeviceInterface::WeatherDeviceClass.GetWeatherLoc()' */
void DeviceInterfaceWeatherDeviceClass_GetWeatherLoc( DeviceInterfaceWeatherDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::WeatherDeviceClass.OnSetIsWeatherLocReceived()' */
void DeviceInterfaceWeatherDeviceClass_OnSetIsWeatherLocReceived( DeviceInterfaceWeatherDeviceClass _this, 
  XInt32 value );

/* Default onget method for the property 'IsWeatherInfoReceived' */
XInt32 DeviceInterfaceWeatherDeviceClass_OnGetIsWeatherInfoReceived( DeviceInterfaceWeatherDeviceClass _this );

/* Default onget method for the property 'IsWeatherLocReceived' */
XInt32 DeviceInterfaceWeatherDeviceClass_OnGetIsWeatherLocReceived( DeviceInterfaceWeatherDeviceClass _this );

#ifdef __cplusplus
  }
#endif

#endif /* _DeviceInterfaceWeatherDeviceClass_H */

/* Embedded Wizard */
