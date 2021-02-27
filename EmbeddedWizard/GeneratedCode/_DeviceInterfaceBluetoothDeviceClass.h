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
  EW_OBJECT  ( BtcPairingChangedSystemEvent, CoreSystemEvent )
  EW_OBJECT  ( PairedDeviceObj, DeviceInterfaceBluetoothPairedDeviceInfo )
  EW_OBJECT  ( BlePairingStateChangedEvent, CoreSystemEvent )
  EW_OBJECT  ( MotoConSystemEvent, CoreSystemEvent )
  EW_OBJECT  ( PairedDeviceUpdatedSystemEvent, CoreSystemEvent )
  EW_OBJECT  ( BtcConnectionResultSystemEvent, CoreSystemEvent )
  EW_PROPERTY( ConnectPairedDeviceResult, XEnum )
  EW_PROPERTY( BtFwStatus,      XEnum )
  EW_PROPERTY( BtcPairingState, XEnum )
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
void DeviceInterfaceBluetoothDeviceClass_NotifyBtcPairingStateChanged( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum aState );

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyBtcPairingStateChanged()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyBtcPairingStateChanged( void* _this, 
  XEnum aState );

/* The following define announces the presence of the method DeviceInterface::BluetoothDeviceClass.NotifyBtcPairingStateChanged(). */
#define _DeviceInterfaceBluetoothDeviceClass__NotifyBtcPairingStateChanged_

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetDiscoverable()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetDiscoverable( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool value );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetBluetoothEnable()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetBluetoothEnable( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool value );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetBluetoothEnable()' */
XBool DeviceInterfaceBluetoothDeviceClass_OnGetBluetoothEnable( DeviceInterfaceBluetoothDeviceClass _this );

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

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceBluetoothDeviceClass_NotifyBlePairingStateChanged( DeviceInterfaceBluetoothDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyBlePairingStateChanged()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyBlePairingStateChanged( void* _this );

/* The following define announces the presence of the method DeviceInterface::BluetoothDeviceClass.NotifyBlePairingStateChanged(). */
#define _DeviceInterfaceBluetoothDeviceClass__NotifyBlePairingStateChanged_

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.SetBleAdvertisement()' */
void DeviceInterfaceBluetoothDeviceClass_SetBleAdvertisement( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool aEnable );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.IsBtConnected()' */
XBool DeviceInterfaceBluetoothDeviceClass_IsBtConnected( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetBlePairingFailCount()' */
XInt32 DeviceInterfaceBluetoothDeviceClass_GetBlePairingFailCount( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.IsMotoconConnected()' */
XBool DeviceInterfaceBluetoothDeviceClass_IsMotoconConnected( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetBleConnectedDeviceName()' */
XString DeviceInterfaceBluetoothDeviceClass_GetBleConnectedDeviceName( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetBlePairingState()' */
XEnum DeviceInterfaceBluetoothDeviceClass_OnGetBlePairingState( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetBlePincode()' */
XUInt32 DeviceInterfaceBluetoothDeviceClass_OnGetBlePincode( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.NotifyMotoConEventReceived()' */
void DeviceInterfaceBluetoothDeviceClass_NotifyMotoConEventReceived( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum aEvent );

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyMotoConEventReceived()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyMotoConEventReceived( void* _this, 
  XEnum aEvent );

/* The following define announces the presence of the method DeviceInterface::BluetoothDeviceClass.NotifyMotoConEventReceived(). */
#define _DeviceInterfaceBluetoothDeviceClass__NotifyMotoConEventReceived_

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceBluetoothDeviceClass_NotifyBtcConnectionResult( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum aResult );

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyBtcConnectionResult()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyBtcConnectionResult( void* _this, 
  XEnum aResult );

/* The following define announces the presence of the method DeviceInterface::BluetoothDeviceClass.NotifyBtcConnectionResult(). */
#define _DeviceInterfaceBluetoothDeviceClass__NotifyBtcConnectionResult_

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetBtcPasskey()' */
XUInt32 DeviceInterfaceBluetoothDeviceClass_GetBtcPasskey( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetBtcPairingDeviceName()' */
XString DeviceInterfaceBluetoothDeviceClass_GetBtcPairingDeviceName( DeviceInterfaceBluetoothDeviceClass _this );

/* Default onget method for the property 'BtFwStatus' */
XEnum DeviceInterfaceBluetoothDeviceClass_OnGetBtFwStatus( DeviceInterfaceBluetoothDeviceClass _this );

/* Default onget method for the property 'RefreshPairedDeviceList' */
XBool DeviceInterfaceBluetoothDeviceClass_OnGetRefreshPairedDeviceList( DeviceInterfaceBluetoothDeviceClass _this );

#ifdef __cplusplus
  }
#endif

#endif /* _DeviceInterfaceBluetoothDeviceClass_H */

/* Embedded Wizard */
