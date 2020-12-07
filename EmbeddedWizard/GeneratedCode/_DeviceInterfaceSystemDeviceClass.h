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

#ifndef _DeviceInterfaceSystemDeviceClass_H
#define _DeviceInterfaceSystemDeviceClass_H

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
#include "_CoreTimer.h"
#include "_TemplatesDeviceClass.h"

/* Forward declaration of the class DeviceInterface::SystemDeviceClass */
#ifndef _DeviceInterfaceSystemDeviceClass_
  EW_DECLARE_CLASS( DeviceInterfaceSystemDeviceClass )
#define _DeviceInterfaceSystemDeviceClass_
#endif


/* Deklaration of class : 'DeviceInterface::SystemDeviceClass' */
EW_DEFINE_FIELDS( DeviceInterfaceSystemDeviceClass, TemplatesDeviceClass )
  EW_OBJECT  ( FactoryTestSystemEvent, CoreSystemEvent )
  EW_OBJECT  ( FactoryResetTimer, CoreTimer )
  EW_PROPERTY( SoftwareVersion, XString )
  EW_PROPERTY( ESN,             XString )
  EW_PROPERTY( BtSoftwareVersion, XString )
  EW_PROPERTY( BrightnessLevel, XInt32 )
  EW_VARIABLE( IsHopperTestMode, XBool )
  EW_PROPERTY( FactoryResetComplete, XBool )
EW_END_OF_FIELDS( DeviceInterfaceSystemDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::SystemDeviceClass' */
EW_DEFINE_METHODS( DeviceInterfaceSystemDeviceClass, TemplatesDeviceClass )
EW_END_OF_METHODS( DeviceInterfaceSystemDeviceClass )

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.QuitTest()' */
void DeviceInterfaceSystemDeviceClass_QuitTest( DeviceInterfaceSystemDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.QuitTest()' */
void DeviceInterfaceSystemDeviceClass__QuitTest( void* _this );

/* The following define announces the presence of the method DeviceInterface::SystemDeviceClass.QuitTest(). */
#define _DeviceInterfaceSystemDeviceClass__QuitTest_

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceSystemDeviceClass_TestDisplayPattern( DeviceInterfaceSystemDeviceClass _this, 
  XInt32 aIdx );

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.TestDisplayPattern()' */
void DeviceInterfaceSystemDeviceClass__TestDisplayPattern( void* _this, XInt32 aIdx );

/* The following define announces the presence of the method DeviceInterface::SystemDeviceClass.TestDisplayPattern(). */
#define _DeviceInterfaceSystemDeviceClass__TestDisplayPattern_

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.NotifyEsnRead()' */
void DeviceInterfaceSystemDeviceClass_NotifyEsnRead( DeviceInterfaceSystemDeviceClass _this, 
  XString aESN );

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.NotifyEsnRead()' */
void DeviceInterfaceSystemDeviceClass__NotifyEsnRead( void* _this, XString aESN );

/* The following define announces the presence of the method DeviceInterface::SystemDeviceClass.NotifyEsnRead(). */
#define _DeviceInterfaceSystemDeviceClass__NotifyEsnRead_

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnSetESN()' */
void DeviceInterfaceSystemDeviceClass_OnSetESN( DeviceInterfaceSystemDeviceClass _this, 
  XString value );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnGetESN()' */
XString DeviceInterfaceSystemDeviceClass_OnGetESN( DeviceInterfaceSystemDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnGetSoftwareVersion()' */
XString DeviceInterfaceSystemDeviceClass_OnGetSoftwareVersion( DeviceInterfaceSystemDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnGetRtcTime()' */
XString DeviceInterfaceSystemDeviceClass_OnGetRtcTime( DeviceInterfaceSystemDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.ResetToFactoryDefault()' */
void DeviceInterfaceSystemDeviceClass_ResetToFactoryDefault( DeviceInterfaceSystemDeviceClass _this );

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceSystemDeviceClass_NotifyFactoryResetComplete( DeviceInterfaceSystemDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.NotifyFactoryResetComplete()' */
void DeviceInterfaceSystemDeviceClass__NotifyFactoryResetComplete( void* _this );

/* The following define announces the presence of the method DeviceInterface::SystemDeviceClass.NotifyFactoryResetComplete(). */
#define _DeviceInterfaceSystemDeviceClass__NotifyFactoryResetComplete_

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnFactoryResetTimeoutSlot()' */
void DeviceInterfaceSystemDeviceClass_OnFactoryResetTimeoutSlot( DeviceInterfaceSystemDeviceClass _this, 
  XObject sender );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.RebootSystem()' */
void DeviceInterfaceSystemDeviceClass_RebootSystem( DeviceInterfaceSystemDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SetBrightness()' */
void DeviceInterfaceSystemDeviceClass_SetBrightness( DeviceInterfaceSystemDeviceClass _this, 
  XInt32 aBrightness );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnGetBtSoftwareVersion()' */
XString DeviceInterfaceSystemDeviceClass_OnGetBtSoftwareVersion( DeviceInterfaceSystemDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.StartBurnInTest()' */
void DeviceInterfaceSystemDeviceClass_StartBurnInTest( DeviceInterfaceSystemDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.StartBurnInTest()' */
void DeviceInterfaceSystemDeviceClass__StartBurnInTest( void* _this );

/* The following define announces the presence of the method DeviceInterface::SystemDeviceClass.StartBurnInTest(). */
#define _DeviceInterfaceSystemDeviceClass__StartBurnInTest_

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.UpdateBurnInTestTime()' */
void DeviceInterfaceSystemDeviceClass_UpdateBurnInTestTime( DeviceInterfaceSystemDeviceClass _this, 
  XUInt32 aTimeSec );

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.UpdateBurnInTestTime()' */
void DeviceInterfaceSystemDeviceClass__UpdateBurnInTestTime( void* _this, XUInt32 
  aTimeSec );

/* The following define announces the presence of the method DeviceInterface::SystemDeviceClass.UpdateBurnInTestTime(). */
#define _DeviceInterfaceSystemDeviceClass__UpdateBurnInTestTime_

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.ShowBurnInTestResult()' */
void DeviceInterfaceSystemDeviceClass_ShowBurnInTestResult( DeviceInterfaceSystemDeviceClass _this, 
  XBool aResult );

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.ShowBurnInTestResult()' */
void DeviceInterfaceSystemDeviceClass__ShowBurnInTestResult( void* _this, XBool 
  aResult );

/* The following define announces the presence of the method DeviceInterface::SystemDeviceClass.ShowBurnInTestResult(). */
#define _DeviceInterfaceSystemDeviceClass__ShowBurnInTestResult_

/* Default onget method for the property 'FactoryResetComplete' */
XBool DeviceInterfaceSystemDeviceClass_OnGetFactoryResetComplete( DeviceInterfaceSystemDeviceClass _this );

/* Default onset method for the property 'FactoryResetComplete' */
void DeviceInterfaceSystemDeviceClass_OnSetFactoryResetComplete( DeviceInterfaceSystemDeviceClass _this, 
  XBool value );

#ifdef __cplusplus
  }
#endif

#endif /* _DeviceInterfaceSystemDeviceClass_H */

/* Embedded Wizard */
