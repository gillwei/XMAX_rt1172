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

#ifndef _DeviceInterfaceSystemDeviceClass_H
#define _DeviceInterfaceSystemDeviceClass_H

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

/* Forward declaration of the class DeviceInterface::RtcTime */
#ifndef _DeviceInterfaceRtcTime_
  EW_DECLARE_CLASS( DeviceInterfaceRtcTime )
#define _DeviceInterfaceRtcTime_
#endif

/* Forward declaration of the class DeviceInterface::SystemDeviceClass */
#ifndef _DeviceInterfaceSystemDeviceClass_
  EW_DECLARE_CLASS( DeviceInterfaceSystemDeviceClass )
#define _DeviceInterfaceSystemDeviceClass_
#endif


/* Deklaration of class : 'DeviceInterface::SystemDeviceClass' */
EW_DEFINE_FIELDS( DeviceInterfaceSystemDeviceClass, TemplatesDeviceClass )
  EW_VARIABLE( CurrentAdjustTime, DeviceInterfaceRtcTime )
  EW_OBJECT  ( FactoryTestSystemEvent, CoreSystemEvent )
  EW_OBJECT  ( QrCodeSystemEvent, CoreSystemEvent )
  EW_OBJECT  ( OpeningSystemEvent, CoreSystemEvent )
  EW_OBJECT  ( InspectionDisplaySystemEvent, CoreSystemEvent )
  EW_OBJECT  ( InspectionModeSystemEvent, CoreSystemEvent )
  EW_OBJECT  ( SystemDataReceivedSystemEvent, CoreSystemEvent )
  EW_PROPERTY( SoftwareVersion, XString )
  EW_PROPERTY( ESN,             XString )
  EW_PROPERTY( BtSoftwareVersion, XString )
  EW_PROPERTY( BrightnessLevel, XInt32 )
  EW_PROPERTY( HomeType,        XEnum )
  EW_PROPERTY( InspectionDisplayPattern, XEnum )
  EW_PROPERTY( InspectionMode,  XEnum )
  EW_PROPERTY( OperationMode,   XEnum )
  EW_PROPERTY( IsRunningFactoryReset, XBool )
  EW_PROPERTY( IsSoftwareUpdateEnabled, XBool )
  EW_PROPERTY( IsClockAutoAdj,  XBool )
  EW_VARIABLE( IsHopperTestMode, XBool )
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

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.ResetToFactoryDefault()' */
void DeviceInterfaceSystemDeviceClass_ResetToFactoryDefault( DeviceInterfaceSystemDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.RebootSystem()' */
void DeviceInterfaceSystemDeviceClass_RebootSystem( DeviceInterfaceSystemDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SetTFTDutyCycle()' */
void DeviceInterfaceSystemDeviceClass_SetTFTDutyCycle( DeviceInterfaceSystemDeviceClass _this, 
  XInt32 aDutyCycle );

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

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceSystemDeviceClass_NotifyQrCodeReady( DeviceInterfaceSystemDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.NotifyQrCodeReady()' */
void DeviceInterfaceSystemDeviceClass__NotifyQrCodeReady( void* _this );

/* The following define announces the presence of the method DeviceInterface::SystemDeviceClass.NotifyQrCodeReady(). */
#define _DeviceInterfaceSystemDeviceClass__NotifyQrCodeReady_

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.GetQrCode()' */
void DeviceInterfaceSystemDeviceClass_GetQrCode( DeviceInterfaceSystemDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.GetLocalTime()' */
DeviceInterfaceRtcTime DeviceInterfaceSystemDeviceClass_GetLocalTime( DeviceInterfaceSystemDeviceClass _this );

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceSystemDeviceClass_StartOpening( DeviceInterfaceSystemDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.StartOpening()' */
void DeviceInterfaceSystemDeviceClass__StartOpening( void* _this );

/* The following define announces the presence of the method DeviceInterface::SystemDeviceClass.StartOpening(). */
#define _DeviceInterfaceSystemDeviceClass__StartOpening_

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.IsKeyStateValid()' */
XBool DeviceInterfaceSystemDeviceClass_IsKeyStateValid( DeviceInterfaceSystemDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.IsTFTBacklightOn()' */
XBool DeviceInterfaceSystemDeviceClass_IsTFTBacklightOn( DeviceInterfaceSystemDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnSetOperationMode()' */
void DeviceInterfaceSystemDeviceClass_OnSetOperationMode( DeviceInterfaceSystemDeviceClass _this, 
  XEnum value );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnGetOperationMode()' */
XEnum DeviceInterfaceSystemDeviceClass_OnGetOperationMode( DeviceInterfaceSystemDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.IsOperationModeReady()' */
XBool DeviceInterfaceSystemDeviceClass_IsOperationModeReady( DeviceInterfaceSystemDeviceClass _this );

/* Notifiy the inspection display pattern to test */
void DeviceInterfaceSystemDeviceClass_NotifyInspectionRequest( DeviceInterfaceSystemDeviceClass _this, 
  XEnum aMode, XEnum aDisplayPattern );

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.NotifyInspectionRequest()' */
void DeviceInterfaceSystemDeviceClass__NotifyInspectionRequest( void* _this, XEnum 
  aMode, XEnum aDisplayPattern );

/* The following define announces the presence of the method DeviceInterface::SystemDeviceClass.NotifyInspectionRequest(). */
#define _DeviceInterfaceSystemDeviceClass__NotifyInspectionRequest_

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnSetInspectionMode()' */
void DeviceInterfaceSystemDeviceClass_OnSetInspectionMode( DeviceInterfaceSystemDeviceClass _this, 
  XEnum value );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnSetInspectionDisplayPattern()' */
void DeviceInterfaceSystemDeviceClass_OnSetInspectionDisplayPattern( DeviceInterfaceSystemDeviceClass _this, 
  XEnum value );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SendInspectionResponse()' */
void DeviceInterfaceSystemDeviceClass_SendInspectionResponse( DeviceInterfaceSystemDeviceClass _this, 
  XEnum aMode, XUInt8 aRes );

/* Get current home type from UI */
void DeviceInterfaceSystemDeviceClass_NotifyLastPageRead( DeviceInterfaceSystemDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.NotifyLastPageRead()' */
void DeviceInterfaceSystemDeviceClass__NotifyLastPageRead( void* _this );

/* The following define announces the presence of the method DeviceInterface::SystemDeviceClass.NotifyLastPageRead(). */
#define _DeviceInterfaceSystemDeviceClass__NotifyLastPageRead_

/* Get current home type from UI */
void DeviceInterfaceSystemDeviceClass_UpdateLastPage( DeviceInterfaceSystemDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.UpdateLastPage()' */
void DeviceInterfaceSystemDeviceClass__UpdateLastPage( void* _this );

/* The following define announces the presence of the method DeviceInterface::SystemDeviceClass.UpdateLastPage(). */
#define _DeviceInterfaceSystemDeviceClass__UpdateLastPage_

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnSetHomeType()' */
void DeviceInterfaceSystemDeviceClass_OnSetHomeType( DeviceInterfaceSystemDeviceClass _this, 
  XEnum value );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SetKeyTriggerMode()' */
void DeviceInterfaceSystemDeviceClass_SetKeyTriggerMode( DeviceInterfaceSystemDeviceClass _this, 
  XEnum aKey, XEnum aMode );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SetMagicKeyEnabled()' */
void DeviceInterfaceSystemDeviceClass_SetMagicKeyEnabled( DeviceInterfaceSystemDeviceClass _this, 
  XBool aEnabled );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.IsQrCodeReady()' */
XBool DeviceInterfaceSystemDeviceClass_IsQrCodeReady( DeviceInterfaceSystemDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.NotifyTimeRequest()' */
void DeviceInterfaceSystemDeviceClass_NotifyTimeRequest( DeviceInterfaceSystemDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SetRtcTime()' */
void DeviceInterfaceSystemDeviceClass_SetRtcTime( DeviceInterfaceSystemDeviceClass _this, 
  DeviceInterfaceRtcTime aNewTime );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SendManualAdjTimeToMeter()' */
void DeviceInterfaceSystemDeviceClass_SendManualAdjTimeToMeter( DeviceInterfaceSystemDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnSetIsClockAutoAdj()' */
void DeviceInterfaceSystemDeviceClass_OnSetIsClockAutoAdj( DeviceInterfaceSystemDeviceClass _this, 
  XBool value );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnGetIsClockAutoAdj()' */
XBool DeviceInterfaceSystemDeviceClass_OnGetIsClockAutoAdj( DeviceInterfaceSystemDeviceClass _this );

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceSystemDeviceClass_NotifySystemEventReceived( DeviceInterfaceSystemDeviceClass _this, 
  XEnum aSystemRxEvent );

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.NotifySystemEventReceived()' */
void DeviceInterfaceSystemDeviceClass__NotifySystemEventReceived( void* _this, XEnum 
  aSystemRxEvent );

/* The following define announces the presence of the method DeviceInterface::SystemDeviceClass.NotifySystemEventReceived(). */
#define _DeviceInterfaceSystemDeviceClass__NotifySystemEventReceived_

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.StartOTA()' */
void DeviceInterfaceSystemDeviceClass_StartOTA( DeviceInterfaceSystemDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnGetIsSoftwareUpdateEnabled()' */
XBool DeviceInterfaceSystemDeviceClass_OnGetIsSoftwareUpdateEnabled( DeviceInterfaceSystemDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SaveLastStatus()' */
void DeviceInterfaceSystemDeviceClass_SaveLastStatus( DeviceInterfaceSystemDeviceClass _this );

#ifdef __cplusplus
  }
#endif

#endif /* _DeviceInterfaceSystemDeviceClass_H */

/* Embedded Wizard */
