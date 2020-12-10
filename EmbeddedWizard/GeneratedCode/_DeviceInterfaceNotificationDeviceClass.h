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

#ifndef _DeviceInterfaceNotificationDeviceClass_H
#define _DeviceInterfaceNotificationDeviceClass_H

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

/* Forward declaration of the class DeviceInterface::NotificationContext */
#ifndef _DeviceInterfaceNotificationContext_
  EW_DECLARE_CLASS( DeviceInterfaceNotificationContext )
#define _DeviceInterfaceNotificationContext_
#endif

/* Forward declaration of the class DeviceInterface::NotificationDeviceClass */
#ifndef _DeviceInterfaceNotificationDeviceClass_
  EW_DECLARE_CLASS( DeviceInterfaceNotificationDeviceClass )
#define _DeviceInterfaceNotificationDeviceClass_
#endif


/* Deklaration of class : 'DeviceInterface::NotificationDeviceClass' */
EW_DEFINE_FIELDS( DeviceInterfaceNotificationDeviceClass, TemplatesDeviceClass )
  EW_OBJECT  ( NotificationListUpdatedSystemEvent, CoreSystemEvent )
  EW_OBJECT  ( PhoneCallStateChangedSystemEvent, CoreSystemEvent )
  EW_PROPERTY( NotificationNum, XUInt32 )
EW_END_OF_FIELDS( DeviceInterfaceNotificationDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::NotificationDeviceClass' */
EW_DEFINE_METHODS( DeviceInterfaceNotificationDeviceClass, TemplatesDeviceClass )
EW_END_OF_METHODS( DeviceInterfaceNotificationDeviceClass )

/* This method is intended to be called by the device to notify the GUI application 
   about an alternation of its setting or state value. */
XBool DeviceInterfaceNotificationDeviceClass_IsPhoneCallStateActive( DeviceInterfaceNotificationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NotificationDeviceClass.IsPhoneCallStateActive()' */
XBool DeviceInterfaceNotificationDeviceClass__IsPhoneCallStateActive( void* _this );

/* The following define announces the presence of the method DeviceInterface::NotificationDeviceClass.IsPhoneCallStateActive(). */
#define _DeviceInterfaceNotificationDeviceClass__IsPhoneCallStateActive_

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNotificationDeviceClass_NotifyPhoneCallStateChanged( DeviceInterfaceNotificationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NotificationDeviceClass.NotifyPhoneCallStateChanged()' */
void DeviceInterfaceNotificationDeviceClass__NotifyPhoneCallStateChanged( void* _this );

/* The following define announces the presence of the method DeviceInterface::NotificationDeviceClass.NotifyPhoneCallStateChanged(). */
#define _DeviceInterfaceNotificationDeviceClass__NotifyPhoneCallStateChanged_

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNotificationDeviceClass_NotifyListUpdated( DeviceInterfaceNotificationDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::NotificationDeviceClass.NotifyListUpdated()' */
void DeviceInterfaceNotificationDeviceClass__NotifyListUpdated( void* _this );

/* The following define announces the presence of the method DeviceInterface::NotificationDeviceClass.NotifyListUpdated(). */
#define _DeviceInterfaceNotificationDeviceClass__NotifyListUpdated_

/* 'C' function for method : 'DeviceInterface::NotificationDeviceClass.GetNotificationAtItem()' */
DeviceInterfaceNotificationContext DeviceInterfaceNotificationDeviceClass_GetNotificationAtItem( DeviceInterfaceNotificationDeviceClass _this, 
  XUInt32 aItemNo );

/* 'C' function for method : 'DeviceInterface::NotificationDeviceClass.OnGetNotificationNum()' */
XUInt32 DeviceInterfaceNotificationDeviceClass_OnGetNotificationNum( DeviceInterfaceNotificationDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::NotificationDeviceClass.DeleteNotificationOfUid()' */
void DeviceInterfaceNotificationDeviceClass_DeleteNotificationOfUid( DeviceInterfaceNotificationDeviceClass _this, 
  XUInt32 Uid );

/* 'C' function for method : 'DeviceInterface::NotificationDeviceClass.GetBufferIdxOfNotificationUID()' */
XInt32 DeviceInterfaceNotificationDeviceClass_GetBufferIdxOfNotificationUID( DeviceInterfaceNotificationDeviceClass _this, 
  XUInt32 Uid );

#ifdef __cplusplus
  }
#endif

#endif /* _DeviceInterfaceNotificationDeviceClass_H */

/* Embedded Wizard */
