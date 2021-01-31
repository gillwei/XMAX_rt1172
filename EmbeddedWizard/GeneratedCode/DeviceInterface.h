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

#ifndef DeviceInterface_H
#define DeviceInterface_H

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

#include "_DeviceInterfaceBluetoothDeviceClass.h"
#include "_DeviceInterfaceBluetoothPairedDeviceInfo.h"
#include "_DeviceInterfaceMediaManagerDeviceClass.h"
#include "_DeviceInterfaceNavigationDeviceClass.h"
#include "_DeviceInterfaceRtcTime.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"

/* User defined auto object: 'DeviceInterface::SystemDevice' */
EW_DECLARE_AUTOOBJECT( DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )

/* User defined auto object: 'DeviceInterface::NavigationDevice' */
EW_DECLARE_AUTOOBJECT( DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )

/* User defined auto object: 'DeviceInterface::MediaManagerDevice' */
EW_DECLARE_AUTOOBJECT( DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )

/* User defined auto object: 'DeviceInterface::BluetoothDevice' */
EW_DECLARE_AUTOOBJECT( DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )

/* User defined auto object: 'DeviceInterface::VehicleDevice' */
EW_DECLARE_AUTOOBJECT( DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )

#ifdef __cplusplus
  }
#endif

#endif /* DeviceInterface_H */

/* Embedded Wizard */
