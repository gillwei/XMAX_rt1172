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

#ifndef _DeviceInterfaceBluetoothDeviceClass_H
#define _DeviceInterfaceBluetoothDeviceClass_H

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

/* Forward declaration of the class DeviceInterface::BluetoothDeviceClass */
#ifndef _DeviceInterfaceBluetoothDeviceClass_
  EW_DECLARE_CLASS( DeviceInterfaceBluetoothDeviceClass )
#define _DeviceInterfaceBluetoothDeviceClass_
#endif

/* Forward declaration of the class DeviceInterface::BtPairedDeviceInfo */
#ifndef _DeviceInterfaceBtPairedDeviceInfo_
  EW_DECLARE_CLASS( DeviceInterfaceBtPairedDeviceInfo )
#define _DeviceInterfaceBtPairedDeviceInfo_
#endif


/* Deklaration of class : 'DeviceInterface::BluetoothDeviceClass' */
EW_DEFINE_FIELDS( DeviceInterfaceBluetoothDeviceClass, TemplatesDeviceClass )
  EW_ARRAY   ( PairedDeviceList, DeviceInterfaceBtPairedDeviceInfo, [8])
  EW_OBJECT  ( MotoConSystemEvent, CoreSystemEvent )
  EW_OBJECT  ( BtmStatusEvent,  CoreSystemEvent )
  EW_OBJECT  ( ConnectionStatusEvent, CoreSystemEvent )
  EW_PROPERTY( LocalDeviceAddress, XString )
  EW_PROPERTY( BtSoftwareVersion, XString )
  EW_VARIABLE( PairedDeviceNum, XInt32 )
  EW_PROPERTY( LogLevel,        XInt32 )
  EW_PROPERTY( PairingFailCount, XInt32 )
  EW_PROPERTY( IsPairedDeviceNumMax, XBool )
  EW_PROPERTY( AutoConnect,     XBool )
  EW_PROPERTY( BluetoothEnabled, XBool )
  EW_PROPERTY( Discoverable,    XBool )
EW_END_OF_FIELDS( DeviceInterfaceBluetoothDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::BluetoothDeviceClass' */
EW_DEFINE_METHODS( DeviceInterfaceBluetoothDeviceClass, TemplatesDeviceClass )
EW_END_OF_METHODS( DeviceInterfaceBluetoothDeviceClass )

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetPairedDeviceList()' */
void DeviceInterfaceBluetoothDeviceClass_GetPairedDeviceList( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetDiscoverable()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetDiscoverable( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool value );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetBluetoothEnabled()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetBluetoothEnabled( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool value );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetBluetoothEnabled()' */
XBool DeviceInterfaceBluetoothDeviceClass_OnGetBluetoothEnabled( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetAutoConnect()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetAutoConnect( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool value );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetAutoConnect()' */
XBool DeviceInterfaceBluetoothDeviceClass_OnGetAutoConnect( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.UnpairDevice()' */
void DeviceInterfaceBluetoothDeviceClass_UnpairDevice( DeviceInterfaceBluetoothDeviceClass _this, 
  XUInt64 aDeviceAddress );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetLocalDeviceName()' */
XString DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceName( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetLocalDeviceAddress()' */
XString DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceAddress( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.ConnectPairedDevice()' */
void DeviceInterfaceBluetoothDeviceClass_ConnectPairedDevice( DeviceInterfaceBluetoothDeviceClass _this, 
  XUInt64 aDeviceAddress );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.DisconnectPairedDevice()' */
void DeviceInterfaceBluetoothDeviceClass_DisconnectPairedDevice( DeviceInterfaceBluetoothDeviceClass _this, 
  XUInt64 aDeviceAddress );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetIsPairedDeviceNumMax()' */
XBool DeviceInterfaceBluetoothDeviceClass_OnGetIsPairedDeviceNumMax( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.IsMotoconConnected()' */
XBool DeviceInterfaceBluetoothDeviceClass_IsMotoconConnected( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.NotifyMotoConEventReceived()' */
void DeviceInterfaceBluetoothDeviceClass_NotifyMotoConEventReceived( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum aEvent );

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyMotoConEventReceived()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyMotoConEventReceived( void* _this, 
  XEnum aEvent );

/* The following define announces the presence of the method DeviceInterface::BluetoothDeviceClass.NotifyMotoConEventReceived(). */
#define _DeviceInterfaceBluetoothDeviceClass__NotifyMotoConEventReceived_

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetBtcPasskey()' */
XUInt32 DeviceInterfaceBluetoothDeviceClass_GetBtcPasskey( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetBtcPairingDeviceName()' */
XString DeviceInterfaceBluetoothDeviceClass_GetBtcPairingDeviceName( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.SendMotoConCommand()' */
void DeviceInterfaceBluetoothDeviceClass_SendMotoConCommand( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum aTxCmd );

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.SendMotoConCommand()' */
void DeviceInterfaceBluetoothDeviceClass__SendMotoConCommand( void* _this, XEnum 
  aTxCmd );

/* The following define announces the presence of the method DeviceInterface::BluetoothDeviceClass.SendMotoConCommand(). */
#define _DeviceInterfaceBluetoothDeviceClass__SendMotoConCommand_

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.NotifyBtmStatus()' */
void DeviceInterfaceBluetoothDeviceClass_NotifyBtmStatus( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum aStatus );

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyBtmStatus()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyBtmStatus( void* _this, XEnum aStatus );

/* The following define announces the presence of the method DeviceInterface::BluetoothDeviceClass.NotifyBtmStatus(). */
#define _DeviceInterfaceBluetoothDeviceClass__NotifyBtmStatus_

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.NotifyConnectionStatus()' */
void DeviceInterfaceBluetoothDeviceClass_NotifyConnectionStatus( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum aStatus );

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyConnectionStatus()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyConnectionStatus( void* _this, XEnum 
  aStatus );

/* The following define announces the presence of the method DeviceInterface::BluetoothDeviceClass.NotifyConnectionStatus(). */
#define _DeviceInterfaceBluetoothDeviceClass__NotifyConnectionStatus_

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.IsPairingDeviceYamahaAppSPPConnected()' */
XBool DeviceInterfaceBluetoothDeviceClass_IsPairingDeviceYamahaAppSPPConnected( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.TriggerConnectionTimeoutTimer()' */
void DeviceInterfaceBluetoothDeviceClass_TriggerConnectionTimeoutTimer( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnPairedDeviceListUpdatedSlot()' */
void DeviceInterfaceBluetoothDeviceClass_OnPairedDeviceListUpdatedSlot( DeviceInterfaceBluetoothDeviceClass _this, 
  XObject sender );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnConnectedAppStatusUpdatedSlot()' */
void DeviceInterfaceBluetoothDeviceClass_OnConnectedAppStatusUpdatedSlot( DeviceInterfaceBluetoothDeviceClass _this, 
  XObject sender );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetPairedDeviceNum()' */
XInt32 DeviceInterfaceBluetoothDeviceClass_GetPairedDeviceNum( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetNaviAppStatus()' */
XBool DeviceInterfaceBluetoothDeviceClass_GetNaviAppStatus( DeviceInterfaceBluetoothDeviceClass _this, 
  XUInt64 aAddress );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetYamahaAppStatus()' */
XBool DeviceInterfaceBluetoothDeviceClass_GetYamahaAppStatus( DeviceInterfaceBluetoothDeviceClass _this, 
  XUInt64 aAddress );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.ConfirmPasskey()' */
void DeviceInterfaceBluetoothDeviceClass_ConfirmPasskey( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool aResult );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetBtSoftwareVersion()' */
XString DeviceInterfaceBluetoothDeviceClass_OnGetBtSoftwareVersion( DeviceInterfaceBluetoothDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetLogLevel()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetLogLevel( DeviceInterfaceBluetoothDeviceClass _this, 
  XInt32 value );

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.DeleteFromPairedDeviceList()' */
void DeviceInterfaceBluetoothDeviceClass_DeleteFromPairedDeviceList( DeviceInterfaceBluetoothDeviceClass _this, 
  XUInt64 aDeviceAddress );

#ifdef __cplusplus
  }
#endif

#endif /* _DeviceInterfaceBluetoothDeviceClass_H */

/* Embedded Wizard */
