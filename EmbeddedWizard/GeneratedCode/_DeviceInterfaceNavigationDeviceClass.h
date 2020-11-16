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

/* Forward declaration of the class DeviceInterface::NavigationDeviceClass */
#ifndef _DeviceInterfaceNavigationDeviceClass_
  EW_DECLARE_CLASS( DeviceInterfaceNavigationDeviceClass )
#define _DeviceInterfaceNavigationDeviceClass_
#endif


/* Deklaration of class : 'DeviceInterface::NavigationDeviceClass' */
EW_DEFINE_FIELDS( DeviceInterfaceNavigationDeviceClass, TemplatesDeviceClass )
  EW_OBJECT  ( MapUpdateEvent,  CoreSystemEvent )
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

#ifdef __cplusplus
  }
#endif

#endif /* _DeviceInterfaceNavigationDeviceClass_H */

/* Embedded Wizard */
