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

#ifndef _DeviceInterfaceBluetoothDeviceClass_H
#define _DeviceInterfaceBluetoothDeviceClass_H

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
#include "_DeviceInterfaceBluetoothPairedDeviceInfo.h"
#include "_TemplatesDeviceClass.h"

/* Forward declaration of the class DeviceInterface::BluetoothDeviceClass */
#ifndef _DeviceInterfaceBluetoothDeviceClass_
  EW_DECLARE_CLASS( DeviceInterfaceBluetoothDeviceClass )
#define _DeviceInterfaceBluetoothDeviceClass_
#endif


/* Deklaration of class : 'DeviceInterface::BluetoothDeviceClass' */
EW_DEFINE_FIELDS( DeviceInterfaceBluetoothDeviceClass, TemplatesDeviceClass )
  EW_OBJECT  ( PasskeyGeneratedSystemEvent, CoreSystemEvent )
  EW_OBJECT  ( ConnectionResultSystemEvent, CoreSystemEvent )
  EW_OBJECT  ( PairedDeviceObj, DeviceInterfaceBluetoothPairedDeviceInfo )
  EW_VARIABLE( Passkey,         XString )
  EW_PROPERTY( BtFwStatus,      XEnum )
  EW_PROPERTY( ConnectionResult, XEnum )
  EW_PROPERTY( RefreshPairedDeviceList, XBool )
  EW_PROPERTY( AutoConnect,     XBool )
  EW_PROPERTY( BluetoothEnable, XBool )
  EW_PROPERTY( Discoverable,    XBool )
EW_END_OF_FIELDS( DeviceInterfaceBluetoothDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::BluetoothDeviceClass' */
EW_DEFINE_METHODS( DeviceInterfaceBluetoothDeviceClass, TemplatesDeviceClass )
EW_END_OF_METHODS( DeviceInterfaceBluetoothDeviceClass )

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetPairedDeviceAtItem()' */
void DeviceInterfaceBluetoothDeviceClass_GetPairedDeviceAtItem( DeviceInterfaceBluetoothDeviceClass _this, 
  XInt32 aItemNo );

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceBluetoothDeviceClass_NotifyPasskeyGenerated( DeviceInterfaceBluetoothDeviceClass _this, 
  XString aPasskey );

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyPasskeyGenerated()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyPasskeyGenerated( void* _this, XString 
  aPasskey );

/* The following define announces the presence of the method DeviceInterface::BluetoothDeviceClass.NotifyPasskeyGenerated(). */
#define _DeviceInterfaceBluetoothDeviceClass__NotifyPasskeyGenerated_

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceBluetoothDeviceClass_NotifyConnectionResult( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum aResult );

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyConnectionResult()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyConnectionResult( void* _this, XEnum 
  aResult );

/* The following define announces the presence of the method DeviceInterface::BluetoothDeviceClass.NotifyConnectionResult(). */
#define _DeviceInterfaceBluetoothDeviceClass__NotifyConnectionResult_

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetDiscoverable()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetDiscoverable( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool value );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetBluetoothEnable()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetBluetoothEnable( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool value );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetAutoConnect()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetAutoConnect( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool value );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetAutoConnect()' */
XBool DeviceInterfaceBluetoothDeviceClass_OnGetAutoConnect( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetPairedDeviceNum()' */
XInt32 DeviceInterfaceBluetoothDeviceClass_OnGetPairedDeviceNum( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.UnpairDevice()' */
void DeviceInterfaceBluetoothDeviceClass_UnpairDevice( DeviceInterfaceBluetoothDeviceClass _this, 
  XInt32 aPairedDeviceIndex );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetBluetoothEnable()' */
void DeviceInterfaceBluetoothDeviceClass_GetBluetoothEnable( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetLocalDeviceName()' */
XString DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceName( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.ConnectPairedDevice()' */
void DeviceInterfaceBluetoothDeviceClass_ConnectPairedDevice( DeviceInterfaceBluetoothDeviceClass _this, 
  XInt32 aPairedDeviceIndex );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.IsBlePairedDevice()' */
XBool DeviceInterfaceBluetoothDeviceClass_IsBlePairedDevice( DeviceInterfaceBluetoothDeviceClass _this, 
  XInt32 aPairedDeviceIndex );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.DisconnectPairedDevice()' */
void DeviceInterfaceBluetoothDeviceClass_DisconnectPairedDevice( DeviceInterfaceBluetoothDeviceClass _this, 
  XInt32 aPairedDeviceIndex );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetIsMaxPairedDevice()' */
XBool DeviceInterfaceBluetoothDeviceClass_OnGetIsMaxPairedDevice( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetBtFwStatus()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetBtFwStatus( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum value );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.NotifyBtFwStatus()' */
void DeviceInterfaceBluetoothDeviceClass_NotifyBtFwStatus( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum status, XString version );

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyBtFwStatus()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyBtFwStatus( void* _this, XEnum status, 
  XString version );

/* The following define announces the presence of the method DeviceInterface::BluetoothDeviceClass.NotifyBtFwStatus(). */
#define _DeviceInterfaceBluetoothDeviceClass__NotifyBtFwStatus_

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetRefreshPairedDeviceList()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetRefreshPairedDeviceList( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool value );

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceBluetoothDeviceClass_NotifyPairedDeviceConnectionStatusUpdated( DeviceInterfaceBluetoothDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyPairedDeviceConnectionStatusUpdated()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyPairedDeviceConnectionStatusUpdated( void* _this );

/* The following define announces the presence of the method DeviceInterface::BluetoothDeviceClass.NotifyPairedDeviceConnectionStatusUpdated(). */
#define _DeviceInterfaceBluetoothDeviceClass__NotifyPairedDeviceConnectionStatusUpdated_

/* Default onget method for the property 'BtFwStatus' */
XEnum DeviceInterfaceBluetoothDeviceClass_OnGetBtFwStatus( DeviceInterfaceBluetoothDeviceClass _this );

/* Default onget method for the property 'RefreshPairedDeviceList' */
XBool DeviceInterfaceBluetoothDeviceClass_OnGetRefreshPairedDeviceList( DeviceInterfaceBluetoothDeviceClass _this );

#ifdef __cplusplus
  }
#endif

#endif /* _DeviceInterfaceBluetoothDeviceClass_H */

/* Embedded Wizard */
