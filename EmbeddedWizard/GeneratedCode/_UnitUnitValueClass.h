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

#ifndef _UnitUnitValueClass_H
#define _UnitUnitValueClass_H

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

/* Forward declaration of the class Unit::UnitValueClass */
#ifndef _UnitUnitValueClass_
  EW_DECLARE_CLASS( UnitUnitValueClass )
#define _UnitUnitValueClass_
#endif


/* Deklaration of class : 'Unit::UnitValueClass' */
EW_DEFINE_FIELDS( UnitUnitValueClass, XObject )
  EW_ARRAY   ( ItemMileageUnitArray, XString, [2])
  EW_ARRAY   ( ItemFuelUnitArray, XString, [3])
  EW_ARRAY   ( ItemPressureUnitArray, XString, [3])
  EW_ARRAY   ( ItemTemperatureUnitArray, XString, [2])
EW_END_OF_FIELDS( UnitUnitValueClass )

/* Virtual Method Table (VMT) for the class : 'Unit::UnitValueClass' */
EW_DEFINE_METHODS( UnitUnitValueClass, XObject )
EW_END_OF_METHODS( UnitUnitValueClass )

#ifdef __cplusplus
  }
#endif

#endif /* _UnitUnitValueClass_H */

/* Embedded Wizard */
