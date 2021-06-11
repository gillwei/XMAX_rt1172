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

#ifndef Navigation_H
#define Navigation_H

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

#include "_NavigationNAV01_DefaultView.h"
#include "_NavigationNAV03_TBTListView.h"
#include "_NavigationNAV05_TBTView.h"
#include "_NavigationNAV06_NaviSettingMenu.h"
#include "_NavigationNAV08_NaviChageViewMenu.h"
#include "_NavigationNAV09_NAV10_PoiList.h"
#include "_NavigationNAV11_RouteOptionMenu.h"
#include "_NavigationNaviAlert.h"
#include "_NavigationNaviAlertMessage.h"
#include "_NavigationNaviCurrentRoad.h"
#include "_NavigationNaviDialog.h"
#include "_NavigationNaviETA.h"
#include "_NavigationNaviTbtListDataEmptyDialog.h"
#include "_NavigationNaviZoomToast.h"
#include "_NavigationReRoute.h"
#include "_NavigationTbtInfoItem.h"
#include "_NavigationTbtListMenu.h"

/* User defined constant: 'Navigation::TIMETEXT_W_NAVI_BOUNDS' */
extern const XRect NavigationTIMETEXT_W_NAVI_BOUNDS;

/* User defined constant: 'Navigation::NAVIFLAG_W_NAVI_BOUNDS' */
extern const XRect NavigationNAVIFLAG_W_NAVI_BOUNDS;

/* User defined constant: 'Navigation::ZOOMIN_W_NAVI_BOUNDS' */
extern const XRect NavigationZOOMIN_W_NAVI_BOUNDS;

/* User defined constant: 'Navigation::ZOOMOUT_W_NAVI_BOUNDS' */
extern const XRect NavigationZOOMOUT_W_NAVI_BOUNDS;

/* User defined constant: 'Navigation::ZOOMIN_WO_NAVI_BOUNDS' */
extern const XRect NavigationZOOMIN_WO_NAVI_BOUNDS;

/* User defined constant: 'Navigation::ZOOMOUT_WO_NAVI_BOUNDS' */
extern const XRect NavigationZOOMOUT_WO_NAVI_BOUNDS;

/* User defined constant: 'Navigation::CURRENT_ROAD_W_NAVI_BOUNDS' */
extern const XRect NavigationCURRENT_ROAD_W_NAVI_BOUNDS;

/* User defined constant: 'Navigation::CURRENT_ROAD_WO_NAVI_BOUNDS' */
extern const XRect NavigationCURRENT_ROAD_WO_NAVI_BOUNDS;

/* User defined constant: 'Navigation::ROAD_BG_W_NAVI_BOUNDS' */
extern const XRect NavigationROAD_BG_W_NAVI_BOUNDS;

/* User defined constant: 'Navigation::ROAD_BG_WO_NAVI_BOUNDS' */
extern const XRect NavigationROAD_BG_WO_NAVI_BOUNDS;

/* User defined constant: 'Navigation::ROADNAME_W_NAVI_BOUNDS' */
extern const XRect NavigationROADNAME_W_NAVI_BOUNDS;

/* User defined constant: 'Navigation::ROADNAME_WO_NAVI_BOUNDS' */
extern const XRect NavigationROADNAME_WO_NAVI_BOUNDS;

/* User defined constant: 'Navigation::CURRENT_ROAD_SHRINK_ALERT' */
extern const XRect NavigationCURRENT_ROAD_SHRINK_ALERT;

/* User defined constant: 'Navigation::ALERT_MESSAGE_BOUNDS' */
extern const XRect NavigationALERT_MESSAGE_BOUNDS;

/* User defined constant: 'Navigation::TURN_ICON_BOUNDS_W_DIST' */
extern const XRect NavigationTURN_ICON_BOUNDS_W_DIST;

/* User defined constant: 'Navigation::TURN_ICON_BOUNDS_WO_DIST' */
extern const XRect NavigationTURN_ICON_BOUNDS_WO_DIST;

#ifdef __cplusplus
  }
#endif

#endif /* Navigation_H */

/* Embedded Wizard */
