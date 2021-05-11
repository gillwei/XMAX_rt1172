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

#ifndef _DeviceInterfaceNavigationDeviceClass_H
#define _DeviceInterfaceNavigationDeviceClass_H

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

/* Forward declaration of the class DeviceInterface::NaviDataClass */
#ifndef _DeviceInterfaceNaviDataClass_
  EW_DECLARE_CLASS( DeviceInterfaceNaviDataClass )
#define _DeviceInterfaceNaviDataClass_
#endif

/* Forward declaration of the class DeviceInterface::NaviTbtDataClass */
#ifndef _DeviceInterfaceNaviTbtDataClass_
  EW_DECLARE_CLASS( DeviceInterfaceNaviTbtDataClass )
#define _DeviceInterfaceNaviTbtDataClass_
#endif

/* Forward declaration of the class DeviceInterface::NavigationDeviceClass */
#ifndef _DeviceInterfaceNavigationDeviceClass_
  EW_DECLARE_CLASS( DeviceInterfaceNavigationDeviceClass )
#define _DeviceInterfaceNavigationDeviceClass_
#endif


/* Deklaration of class : 'DeviceInterface::NavigationDeviceClass' */
EW_DEFINE_FIELDS( DeviceInterfaceNavigationDeviceClass, TemplatesDeviceClass )
  EW_OBJECT  ( MapUpdateEvent,  CoreSystemEvent )
  EW_OBJECT  ( CurRdUpdateEvent, CoreSystemEvent )
  EW_OBJECT  ( ETAUpdateEvent,  CoreSystemEvent )
  EW_OBJECT  ( DayNightModeUpdateEvent, CoreSystemEvent )
  EW_OBJECT  ( SpeedLimitUpdateEvent, CoreSystemEvent )
  EW_OBJECT  ( NaviIncidentUpdateEvent, CoreSystemEvent )
  EW_OBJECT  ( NavigatingStatusUpdateEvent, CoreSystemEvent )
  EW_OBJECT  ( TbtListUpdateEvent, CoreSystemEvent )
  EW_OBJECT  ( RouteCalProgressUpdateEvent, CoreSystemEvent )
  EW_OBJECT  ( ZoomLevelUpdateEventHandler, CoreSystemEvent )
  EW_OBJECT  ( DialogEventUpdateEvent, CoreSystemEvent )
  EW_OBJECT  ( ViaPointUpdateEvent, CoreSystemEvent )
  EW_OBJECT  ( HomeSettingUpdateEvent, CoreSystemEvent )
  EW_OBJECT  ( OfficeSettingUpdateEvent, CoreSystemEvent )
  EW_OBJECT  ( AlertDistanceUpdateEvent, CoreSystemEvent )
  EW_VARIABLE( CurrentHome,     XEnum )
  EW_VARIABLE( IsZoomInOutStatusReceived, XBool )
EW_END_OF_FIELDS( DeviceInterfaceNavigationDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::NavigationDeviceClass' */
EW_DEFINE_METHODS( DeviceInterfaceNavigationDeviceClass, TemplatesDeviceClass )
EW_END_OF_METHODS( DeviceInterfaceNavigationDeviceClass )

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyMapUpdate( DeviceInterfaceNavigationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyMapUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyMapUpdate( void* _this );

/* The following define announces the presence of the method DeviceInterface::NavigationDeviceClass.NotifyMapUpdate(). */
#define _DeviceInterfaceNavigationDeviceClass__NotifyMapUpdate_

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.IsMapFrameReady()' */
XBool DeviceInterfaceNavigationDeviceClass_IsMapFrameReady( DeviceInterfaceNavigationDeviceClass _this );

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyCurRdUpdate( DeviceInterfaceNavigationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyCurRdUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyCurRdUpdate( void* _this );

/* The following define announces the presence of the method DeviceInterface::NavigationDeviceClass.NotifyCurRdUpdate(). */
#define _DeviceInterfaceNavigationDeviceClass__NotifyCurRdUpdate_

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyETAUpdate( DeviceInterfaceNavigationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyETAUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyETAUpdate( void* _this );

/* The following define announces the presence of the method DeviceInterface::NavigationDeviceClass.NotifyETAUpdate(). */
#define _DeviceInterfaceNavigationDeviceClass__NotifyETAUpdate_

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyDayNightModeUpdate( DeviceInterfaceNavigationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyDayNightModeUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyDayNightModeUpdate( void* _this );

/* The following define announces the presence of the method DeviceInterface::NavigationDeviceClass.NotifyDayNightModeUpdate(). */
#define _DeviceInterfaceNavigationDeviceClass__NotifyDayNightModeUpdate_

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifySpeedLimitUpdate( DeviceInterfaceNavigationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifySpeedLimitUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifySpeedLimitUpdate( void* _this );

/* The following define announces the presence of the method DeviceInterface::NavigationDeviceClass.NotifySpeedLimitUpdate(). */
#define _DeviceInterfaceNavigationDeviceClass__NotifySpeedLimitUpdate_

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyNaviEventUpdate( DeviceInterfaceNavigationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyNaviEventUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyNaviEventUpdate( void* _this );

/* The following define announces the presence of the method DeviceInterface::NavigationDeviceClass.NotifyNaviEventUpdate(). */
#define _DeviceInterfaceNavigationDeviceClass__NotifyNaviEventUpdate_

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetNaviData()' */
DeviceInterfaceNaviDataClass DeviceInterfaceNavigationDeviceClass_GetNaviData( DeviceInterfaceNavigationDeviceClass _this, 
  XEnum aDataType );

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.IsRouteGuidanceStarted()' */
XBool DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( DeviceInterfaceNavigationDeviceClass _this );

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyNavigatingStatusUpdate( DeviceInterfaceNavigationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyNavigatingStatusUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyNavigatingStatusUpdate( void* _this );

/* The following define announces the presence of the method DeviceInterface::NavigationDeviceClass.NotifyNavigatingStatusUpdate(). */
#define _DeviceInterfaceNavigationDeviceClass__NotifyNavigatingStatusUpdate_

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyTbtListUpdate( DeviceInterfaceNavigationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyTbtListUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyTbtListUpdate( void* _this );

/* The following define announces the presence of the method DeviceInterface::NavigationDeviceClass.NotifyTbtListUpdate(). */
#define _DeviceInterfaceNavigationDeviceClass__NotifyTbtListUpdate_

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetNaviTbtData()' */
DeviceInterfaceNaviTbtDataClass DeviceInterfaceNavigationDeviceClass_GetNaviTbtData( DeviceInterfaceNavigationDeviceClass _this, 
  XInt32 aTbtItemIdx );

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.StopMapFrameRequest()' */
void DeviceInterfaceNavigationDeviceClass_StopMapFrameRequest( DeviceInterfaceNavigationDeviceClass _this );

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyRouteCalProgressUpdate( DeviceInterfaceNavigationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyRouteCalProgressUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyRouteCalProgressUpdate( void* _this );

/* The following define announces the presence of the method DeviceInterface::NavigationDeviceClass.NotifyRouteCalProgressUpdate(). */
#define _DeviceInterfaceNavigationDeviceClass__NotifyRouteCalProgressUpdate_

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyZoomLevelUpdate( DeviceInterfaceNavigationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyZoomLevelUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyZoomLevelUpdate( void* _this );

/* The following define announces the presence of the method DeviceInterface::NavigationDeviceClass.NotifyZoomLevelUpdate(). */
#define _DeviceInterfaceNavigationDeviceClass__NotifyZoomLevelUpdate_

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyDialogEventUpdate( DeviceInterfaceNavigationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyDialogEventUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyDialogEventUpdate( void* _this );

/* The following define announces the presence of the method DeviceInterface::NavigationDeviceClass.NotifyDialogEventUpdate(). */
#define _DeviceInterfaceNavigationDeviceClass__NotifyDialogEventUpdate_

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetNaviDialogType()' */
XEnum DeviceInterfaceNavigationDeviceClass_GetNaviDialogType( DeviceInterfaceNavigationDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetNaviDialogMessage()' */
XString DeviceInterfaceNavigationDeviceClass_GetNaviDialogMessage( DeviceInterfaceNavigationDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.SendSelectedDialog()' */
void DeviceInterfaceNavigationDeviceClass_SendSelectedDialog( DeviceInterfaceNavigationDeviceClass _this, 
  XEnum aNewButtonType );

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyViaPointUpdate( DeviceInterfaceNavigationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyViaPointUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyViaPointUpdate( void* _this );

/* The following define announces the presence of the method DeviceInterface::NavigationDeviceClass.NotifyViaPointUpdate(). */
#define _DeviceInterfaceNavigationDeviceClass__NotifyViaPointUpdate_

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetNaviConnectStatus()' */
XBool DeviceInterfaceNavigationDeviceClass_GetNaviConnectStatus( DeviceInterfaceNavigationDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetNaviAppInitSettingStatus()' */
XBool DeviceInterfaceNavigationDeviceClass_GetNaviAppInitSettingStatus( DeviceInterfaceNavigationDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.StopRoute()' */
void DeviceInterfaceNavigationDeviceClass_StopRoute( DeviceInterfaceNavigationDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.SkipNextStop()' */
void DeviceInterfaceNavigationDeviceClass_SkipNextStop( DeviceInterfaceNavigationDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GoHome()' */
void DeviceInterfaceNavigationDeviceClass_GoHome( DeviceInterfaceNavigationDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GoOffice()' */
void DeviceInterfaceNavigationDeviceClass_GoOffice( DeviceInterfaceNavigationDeviceClass _this );

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyHomeSettingUpdate( DeviceInterfaceNavigationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyHomeSettingUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyHomeSettingUpdate( void* _this );

/* The following define announces the presence of the method DeviceInterface::NavigationDeviceClass.NotifyHomeSettingUpdate(). */
#define _DeviceInterfaceNavigationDeviceClass__NotifyHomeSettingUpdate_

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyOfficeSettingUpdate( DeviceInterfaceNavigationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyOfficeSettingUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyOfficeSettingUpdate( void* _this );

/* The following define announces the presence of the method DeviceInterface::NavigationDeviceClass.NotifyOfficeSettingUpdate(). */
#define _DeviceInterfaceNavigationDeviceClass__NotifyOfficeSettingUpdate_

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.ZoomInRequest()' */
void DeviceInterfaceNavigationDeviceClass_ZoomInRequest( DeviceInterfaceNavigationDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.ZoomOutRequest()' */
void DeviceInterfaceNavigationDeviceClass_ZoomOutRequest( DeviceInterfaceNavigationDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetZoomInOutStatus()' */
XEnum DeviceInterfaceNavigationDeviceClass_GetZoomInOutStatus( DeviceInterfaceNavigationDeviceClass _this );

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyAlertDistanceUpdate( DeviceInterfaceNavigationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyAlertDistanceUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyAlertDistanceUpdate( void* _this );

/* The following define announces the presence of the method DeviceInterface::NavigationDeviceClass.NotifyAlertDistanceUpdate(). */
#define _DeviceInterfaceNavigationDeviceClass__NotifyAlertDistanceUpdate_

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetAlertDistance()' */
XString DeviceInterfaceNavigationDeviceClass_GetAlertDistance( DeviceInterfaceNavigationDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.IsTbtMessageDisplayed()' */
XBool DeviceInterfaceNavigationDeviceClass_IsTbtMessageDisplayed( DeviceInterfaceNavigationDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.GetTbtListSize()' */
XInt32 DeviceInterfaceNavigationDeviceClass_GetTbtListSize( DeviceInterfaceNavigationDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::NavigationDeviceClass.ResetTbtBuffer()' */
void DeviceInterfaceNavigationDeviceClass_ResetTbtBuffer( DeviceInterfaceNavigationDeviceClass _this );

#ifdef __cplusplus
  }
#endif

#endif /* _DeviceInterfaceNavigationDeviceClass_H */

/* Embedded Wizard */
