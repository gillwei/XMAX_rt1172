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

#ifndef _DeviceInterfaceDateTime_H
#define _DeviceInterfaceDateTime_H

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

/* Forward declaration of the class DeviceInterface::DateTime */
#ifndef _DeviceInterfaceDateTime_
  EW_DECLARE_CLASS( DeviceInterfaceDateTime )
#define _DeviceInterfaceDateTime_
#endif


/* Deklaration of class : 'DeviceInterface::DateTime' */
EW_DEFINE_FIELDS( DeviceInterfaceDateTime, XObject )
  EW_VARIABLE( Hour,            XString )
  EW_VARIABLE( Minute,          XString )
EW_END_OF_FIELDS( DeviceInterfaceDateTime )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::DateTime' */
EW_DEFINE_METHODS( DeviceInterfaceDateTime, XObject )
EW_END_OF_METHODS( DeviceInterfaceDateTime )

#ifdef __cplusplus
  }
#endif

#endif /* _DeviceInterfaceDateTime_H */

/* Embedded Wizard */
