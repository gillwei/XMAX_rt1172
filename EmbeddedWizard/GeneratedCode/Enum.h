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

#ifndef Enum_H
#define Enum_H

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

/* User defined enumeration: 'Enum::FactoryTest' */
typedef enum
{
  EnumFactoryTestQuit                   = 0,
  EnumFactoryTestDisplay                = 1,
  EnumFactoryTestBurnInStart            = 2,
  EnumFactoryTestBurnInTimeUpdate       = 3,
  EnumFactoryTestBurnInResult           = 4
} EnumFactoryTest;

/* User defined enumeration: 'Enum::CommandType' */
typedef enum
{
  EnumCommandTypePlay                   = 0,
  EnumCommandTypePause                  = 1,
  EnumCommandTypeNextTrack              = 2,
  EnumCommandTypePrevTrack              = 3
} EnumCommandType;

/* User defined enumeration: 'Enum::BtResult' */
typedef enum
{
  EnumBtResultSUCCESS                   = 0,
  EnumBtResultFAIL                      = 1,
  EnumBtResultTIMEOUT                   = 2,
  EnumBtResultLOST                      = 3
} EnumBtResult;

/* User defined enumeration: 'Enum::BtFwStatus' */
typedef enum
{
  EnumBtFwStatusNO_UPDATE               = 0,
  EnumBtFwStatusUPDATE_START            = 1,
  EnumBtFwStatusUPDATE_ABORT            = 2,
  EnumBtFwStatusUPDATE_FINISH           = 3
} EnumBtFwStatus;

/* User defined enumeration: 'Enum::RotationDirection' */
typedef enum
{
  EnumRotationDirectionCOUNTER_CLOCKWISE = 0,
  EnumRotationDirectionCLOCKWISE        = 1
} EnumRotationDirection;

/* User defined enumeration: 'Enum::LauncherItem' */
typedef enum
{
  EnumLauncherItemPHONE                 = 0,
  EnumLauncherItemMUSIC                 = 1,
  EnumLauncherItemODO_TRIP              = 2,
  EnumLauncherItemTHEME                 = 3,
  EnumLauncherItemNAVIGATION            = 4,
  EnumLauncherItemNOTIFICATION          = 5,
  EnumLauncherItemWEATHER               = 6,
  EnumLauncherItemSETTINGS              = 7,
  EnumLauncherItemTRACTION_CONTROL      = 8,
  EnumLauncherItemSEAT_HEATER           = 9,
  EnumLauncherItemGRIP_WARMER           = 10,
  EnumLauncherItemWIND_SCREEN           = 11,
  EnumLauncherItemTOTAL                 = 12
} EnumLauncherItem;

/* User defined enumeration: 'Enum::KeyTriggerMode' */
typedef enum
{
  EnumKeyTriggerModeON                  = 0,
  EnumKeyTriggerModeOFF                 = 1
} EnumKeyTriggerMode;

/* User defined enumeration: 'Enum::MainSettingItem' */
typedef enum
{
  EnumMainSettingItemConnection         = 0,
  EnumMainSettingItemClock              = 1,
  EnumMainSettingItemBrightness         = 2,
  EnumMainSettingItemUnit               = 3,
  EnumMainSettingItemGripWarmerSettings = 4,
  EnumMainSettingItemSeatHeaterSettings = 5,
  EnumMainSettingItemSystemInfo         = 6,
  EnumMainSettingItemLegalInfo          = 7,
  EnumMainSettingItemReset              = 8
} EnumMainSettingItem;

/* User defined enumeration: 'Enum::NaviSettingItem' */
typedef enum
{
  EnumNaviSettingItemStopNavigation     = 0,
  EnumNaviSettingItemSkipNextStop       = 1,
  EnumNaviSettingItemGoHome             = 2,
  EnumNaviSettingItemGoToWork           = 3,
  EnumNaviSettingItemFavorites          = 4,
  EnumNaviSettingItemNearbyGasStations  = 5,
  EnumNaviSettingItemChangeView         = 6
} EnumNaviSettingItem;

#ifdef __cplusplus
  }
#endif

#endif /* Enum_H */

/* Embedded Wizard */
