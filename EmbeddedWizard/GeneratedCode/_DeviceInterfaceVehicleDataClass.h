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

#ifndef _DeviceInterfaceVehicleDataClass_H
#define _DeviceInterfaceVehicleDataClass_H

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

/* Forward declaration of the class DeviceInterface::VehicleDataClass */
#ifndef _DeviceInterfaceVehicleDataClass_
  EW_DECLARE_CLASS( DeviceInterfaceVehicleDataClass )
#define _DeviceInterfaceVehicleDataClass_
#endif


/* Deklaration of class : 'DeviceInterface::VehicleDataClass' */
EW_DEFINE_FIELDS( DeviceInterfaceVehicleDataClass, XObject )
  EW_VARIABLE( DataFloat,       XFloat )
  EW_VARIABLE( DataUInt32,      XUInt32 )
  EW_VARIABLE( RxType,          XEnum )
  EW_VARIABLE( DataType,        XEnum )
  EW_VARIABLE( Validity,        XBool )
EW_END_OF_FIELDS( DeviceInterfaceVehicleDataClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::VehicleDataClass' */
EW_DEFINE_METHODS( DeviceInterfaceVehicleDataClass, XObject )
EW_END_OF_METHODS( DeviceInterfaceVehicleDataClass )

#ifdef __cplusplus
  }
#endif

#endif /* _DeviceInterfaceVehicleDataClass_H */

/* Embedded Wizard */
