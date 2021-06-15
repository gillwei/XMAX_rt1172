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

#ifndef Home_H
#define Home_H

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

#include "_HomeBaseHome.h"
#include "_HomeEcoMeterChart.h"
#include "_HomeEcoMeterComponent.h"
#include "_HomeHOM03_VehicleInfo.h"
#include "_HomeHOM11_TachoVisualizer.h"
#include "_HomeHOM12_EcoVisualizer.h"
#include "_HomeHOM13_SpeedVisualizer.h"
#include "_HomeItemVehicleInfo.h"
#include "_HomeRecord.h"
#include "_HomeRecordList.h"
#include "_HomeSpeedCircle.h"
#include "_HomeTachoBaseline.h"
#include "_HomeTachoColor.h"
#include "_HomeTachoScale.h"
#include "_HomeVehicleInfoMenu.h"

/* User defined constant: 'Home::SV_WITHOUT_SPEED_LIMIT' */
extern const XColor HomeSV_WITHOUT_SPEED_LIMIT;

/* User defined constant: 'Home::SV_WITH_SPEED_LIMIT' */
extern const XColor HomeSV_WITH_SPEED_LIMIT;

/* User defined constant: 'Home::SV_OVER_SPEED_LIMIT' */
extern const XColor HomeSV_OVER_SPEED_LIMIT;

/* User defined constant: 'Home::CIRCLE_CENTER_POS' */
extern const XPoint HomeCIRCLE_CENTER_POS;

#ifdef __cplusplus
  }
#endif

#endif /* Home_H */

/* Embedded Wizard */
