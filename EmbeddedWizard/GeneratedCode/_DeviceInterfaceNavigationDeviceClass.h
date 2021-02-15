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

#ifndef _DeviceInterfaceNavigationDeviceClass_H
#define _DeviceInterfaceNavigationDeviceClass_H

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

/* Forward declaration of the class DeviceInterface::NaviDataClass */
#ifndef _DeviceInterfaceNaviDataClass_
  EW_DECLARE_CLASS( DeviceInterfaceNaviDataClass )
#define _DeviceInterfaceNaviDataClass_
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

#ifdef __cplusplus
  }
#endif

#endif /* _DeviceInterfaceNavigationDeviceClass_H */

/* Embedded Wizard */
