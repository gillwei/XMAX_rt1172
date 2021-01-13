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

#include "ewlocale.h"
#include "_ComponentsBaseComponent.h"
#include "_CoreGroup.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_EffectsRectEffect.h"
#include "_LauncherLNC_Base.h"
#include "_LauncherLNC_Main.h"
#include "_LauncherLNC_RotaryPlate.h"
#include "_MediaMED01_MediaUI.h"
#include "_NavigationNAV06_NaviSettingMenu.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_SettingsSET01_MainSettingMenu.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "_ViewsWallpaper.h"
#include "Core.h"
#include "Effects.h"
#include "Enum.h"
#include "Fonts.h"
#include "Launcher.h"
#include "Resource.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000098, /* ratio 76.32 % */
  0xB8001F00, 0x80098452, 0x00EA0030, 0x0C600370, 0xCA003400, 0x20039000, 0x690042C9,
  0xC001D000, 0x22C0C3B1, 0x490E2E4F, 0x44A4B138, 0x6E2D1B86, 0xC006D894, 0x19088848,
  0x8008899E, 0x0029800C, 0xA37800D8, 0x000E8011, 0xF0023820, 0xCECA51F0, 0xE629089E,
  0xE802C001, 0x7B299A4D, 0xC73004B2, 0x0A91D3A7, 0xD93C5229, 0xA15067F3, 0x00020342,
  0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0001 = {{ 0, 38 }, { 480, 272 }};
static const XRect _Const0002 = {{ -480, 38 }, { 0, 272 }};
static const XRect _Const0003 = {{ 0, 38 }, { 134, 272 }};
static const XRect _Const0004 = {{ -134, 38 }, { 0, 272 }};
static const XRect _Const0005 = {{ 0, 38 }, { 480, 49 }};
static const XStringRes _Const0006 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0007 = { _StringsDefault0, 0x0011 };
static const XRect _Const0008 = {{ 0, 0 }, { 134, 234 }};
static const XRect _Const0009 = {{ -81, -143 }, { -31, -93 }};
static const XRect _Const000A = {{ 9, 10 }, { 59, 60 }};
static const XRect _Const000B = {{ 27, 88 }, { 77, 138 }};
static const XRect _Const000C = {{ 9, 166 }, { 59, 216 }};
static const XRect _Const000D = {{ -81, 231 }, { -31, 281 }};
static const XRect _Const000E = {{ 0, 0 }, { 0, 0 }};
static const XRect _Const000F = {{ -1, 249 }, { 41, 291 }};
static const XRect _Const0010 = {{ 13, 74 }, { 91, 152 }};
static const XRect _Const0011 = {{ 0, 70 }, { 122, 156 }};
static const XStringRes _Const0012 = { _StringsDefault0, 0x002E };
static const XRect _Const0013 = {{ 0, 0 }, { 480, 234 }};
static const XColor _Const0014 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0015 = {{ 0, 58 }, { 480, 168 }};
static const XRect _Const0016 = {{ 138, 94 }, { 469, 137 }};
static const XRect _Const0017 = {{ 121, 19 }, { 439, 52 }};
static const XColor _Const0018 = { 0x6B, 0x6B, 0x6B, 0xFF };
static const XRect _Const0019 = {{ 121, 174 }, { 439, 207 }};

#ifndef EW_DONT_CHECK_INDEX
  /* This function is used to check the indices when accessing an array.
     If you don't want this verification add the define EW_DONT_CHECK_INDEX
     to your Makefile or project settings. */
  static int EwCheckIndex( int aIndex, int aRange, const char* aFile, int aLine )
  {
    if (( aIndex < 0 ) || ( aIndex >= aRange ))
    {
      EwPrint( "[FATAL ERROR in %s:%d] Array index %d out of bounds %d",
                aFile, aLine, aIndex, aRange );
      EwPanic();
    }
    return aIndex;
  }

  #define EwCheckIndex( aIndex, aRange ) \
    EwCheckIndex( aIndex, aRange, __FILE__, __LINE__ )
#else
  #define EwCheckIndex( aIndex, aRange ) aIndex
#endif

/* Initializer for the class 'Launcher::LNC_Main' */
void LauncherLNC_Main__Init( LauncherLNC_Main _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( LauncherLNC_Main );

  /* ... then construct all embedded objects */
  EffectsRectEffect__Init( &_this->BaseSlideInEffect, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->BaseSlideOutEffect, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->RotaryPlateSlideInEffect, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->RotaryPlateSlideOutEffect, &_this->_XObject, 0 );
  LauncherLNC_Base__Init( &_this->LNC_Base, &_this->_XObject, 0 );
  LauncherLNC_RotaryPlate__Init( &_this->LNC_RotaryPlate, &_this->_XObject, 0 );
  ViewsWallpaper__Init( &_this->StatusBarShadowImage, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( LauncherLNC_Main );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  EffectsEffect_OnSetExponent((EffectsEffect)&_this->BaseSlideInEffect, 4.380000f );
  EffectsEffect_OnSetTimingCustom1((EffectsEffect)&_this->BaseSlideInEffect, 0.000000f );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->BaseSlideInEffect, EffectsTimingExp_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->BaseSlideInEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->BaseSlideInEffect, 300 );
  _this->BaseSlideInEffect.Value2 = _Const0001;
  _this->BaseSlideInEffect.Value1 = _Const0002;
  EffectsEffect_OnSetExponent((EffectsEffect)&_this->BaseSlideOutEffect, 4.380000f );
  EffectsEffect_OnSetTimingCustom1((EffectsEffect)&_this->BaseSlideOutEffect, 0.000000f );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->BaseSlideOutEffect, EffectsTimingExp_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->BaseSlideOutEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->BaseSlideOutEffect, 300 );
  _this->BaseSlideOutEffect.Value2 = _Const0002;
  _this->BaseSlideOutEffect.Value1 = _Const0001;
  EffectsEffect_OnSetExponent((EffectsEffect)&_this->RotaryPlateSlideInEffect, 4.490000f );
  EffectsEffect_OnSetTimingCustom1((EffectsEffect)&_this->RotaryPlateSlideInEffect, 
  0.000000f );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->RotaryPlateSlideInEffect, EffectsTimingExp_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->RotaryPlateSlideInEffect, 
  1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->RotaryPlateSlideInEffect, 
  300 );
  _this->RotaryPlateSlideInEffect.Value2 = _Const0003;
  _this->RotaryPlateSlideInEffect.Value1 = _Const0004;
  EffectsEffect_OnSetExponent((EffectsEffect)&_this->RotaryPlateSlideOutEffect, 
  4.490000f );
  EffectsEffect_OnSetTimingCustom1((EffectsEffect)&_this->RotaryPlateSlideOutEffect, 
  0.000000f );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->RotaryPlateSlideOutEffect, EffectsTimingExp_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->RotaryPlateSlideOutEffect, 
  1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->RotaryPlateSlideOutEffect, 
  300 );
  _this->RotaryPlateSlideOutEffect.Value2 = _Const0004;
  _this->RotaryPlateSlideOutEffect.Value1 = _Const0003;
  CoreRectView__OnSetBounds( &_this->LNC_Base, _Const0002 );
  CoreRectView__OnSetBounds( &_this->LNC_RotaryPlate, _Const0004 );
  CoreRectView__OnSetBounds( &_this->StatusBarShadowImage, _Const0005 );
  CoreGroup__Add( _this, ((CoreView)&_this->LNC_Base ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LNC_RotaryPlate ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->StatusBarShadowImage ), 0 );
  _this->BaseSlideInEffect.Outlet = EwNewRef( &_this->LNC_Base, CoreRectView_OnGetBounds, 
  CoreRectView__OnSetBounds );
  _this->BaseSlideOutEffect.Super1.OnFinished = EwNewSlot( _this, LauncherLNC_Main_OnSlideOutFinishedSlot );
  _this->BaseSlideOutEffect.Outlet = EwNewRef( &_this->LNC_Base, CoreRectView_OnGetBounds, 
  CoreRectView__OnSetBounds );
  _this->RotaryPlateSlideInEffect.Outlet = EwNewRef( &_this->LNC_RotaryPlate, CoreRectView_OnGetBounds, 
  CoreRectView__OnSetBounds );
  _this->RotaryPlateSlideOutEffect.Super1.OnFinished = EwNewSlot( _this, LauncherLNC_Main_OnSlideOutFinishedSlot );
  _this->RotaryPlateSlideOutEffect.Outlet = EwNewRef( &_this->LNC_RotaryPlate, CoreRectView_OnGetBounds, 
  CoreRectView__OnSetBounds );
  _this->LNC_RotaryPlate.OnIconsRotated = EwNewSlot( _this, LauncherLNC_Main_OnCurrentItemChangedSlot );
  _this->LNC_RotaryPlate.OnSelectedAnimationFinished = EwNewSlot( _this, LauncherLNC_Main_OnSelectedAnimationFinishedSlot );
  ViewsWallpaper_OnSetBitmap( &_this->StatusBarShadowImage, EwLoadResource( &ResourceStatusBarShadow, 
  ResourcesBitmap ));

  /* Call the user defined constructor */
  LauncherLNC_Main_Init( _this, aArg );
}

/* Re-Initializer for the class 'Launcher::LNC_Main' */
void LauncherLNC_Main__ReInit( LauncherLNC_Main _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  EffectsRectEffect__ReInit( &_this->BaseSlideInEffect );
  EffectsRectEffect__ReInit( &_this->BaseSlideOutEffect );
  EffectsRectEffect__ReInit( &_this->RotaryPlateSlideInEffect );
  EffectsRectEffect__ReInit( &_this->RotaryPlateSlideOutEffect );
  LauncherLNC_Base__ReInit( &_this->LNC_Base );
  LauncherLNC_RotaryPlate__ReInit( &_this->LNC_RotaryPlate );
  ViewsWallpaper__ReInit( &_this->StatusBarShadowImage );
}

/* Finalizer method for the class 'Launcher::LNC_Main' */
void LauncherLNC_Main__Done( LauncherLNC_Main _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  EffectsRectEffect__Done( &_this->BaseSlideInEffect );
  EffectsRectEffect__Done( &_this->BaseSlideOutEffect );
  EffectsRectEffect__Done( &_this->RotaryPlateSlideInEffect );
  EffectsRectEffect__Done( &_this->RotaryPlateSlideOutEffect );
  LauncherLNC_Base__Done( &_this->LNC_Base );
  LauncherLNC_RotaryPlate__Done( &_this->LNC_RotaryPlate );
  ViewsWallpaper__Done( &_this->StatusBarShadowImage );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void LauncherLNC_Main_Init( LauncherLNC_Main _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0006 ));
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->RotaryPlateSlideInEffect, 1 );
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->BaseSlideInEffect, 1 );
  _this->CurrentItem = LauncherLNC_Main_GetInitialSelectedItem( _this );
  _this->NextItem = LauncherLNC_Main_GetNextItem( _this, _this->CurrentItem );
  _this->PreviousItem = LauncherLNC_Main_GetPreviousItem( _this, _this->CurrentItem );
  LauncherLNC_Base_SetItems( &_this->LNC_Base, _this->PreviousItem, _this->CurrentItem, 
  _this->NextItem );
  LauncherLNC_RotaryPlate_SetItems( &_this->LNC_RotaryPlate, _this->PreviousItem, 
  _this->CurrentItem, _this->NextItem );
}

/* 'C' function for method : 'Launcher::LNC_Main.OnShortDownKeyActivated()' */
void LauncherLNC_Main_OnShortDownKeyActivated( LauncherLNC_Main _this )
{
  ComponentsBaseComponent__OnShortDownKeyActivated( &_this->LNC_RotaryPlate );
}

/* 'C' function for method : 'Launcher::LNC_Main.OnShortUpKeyActivated()' */
void LauncherLNC_Main_OnShortUpKeyActivated( LauncherLNC_Main _this )
{
  ComponentsBaseComponent__OnShortUpKeyActivated( &_this->LNC_RotaryPlate );
}

/* 'C' function for method : 'Launcher::LNC_Main.OnShortEnterKeyActivated()' */
void LauncherLNC_Main_OnShortEnterKeyActivated( LauncherLNC_Main _this )
{
  LauncherLNC_RotaryPlate_StartSelectedAnimation( &_this->LNC_RotaryPlate );
}

/* 'C' function for method : 'Launcher::LNC_Main.OnShortHomeKeyActivated()' */
void LauncherLNC_Main_OnShortHomeKeyActivated( LauncherLNC_Main _this )
{
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->BaseSlideOutEffect, 1 );
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->RotaryPlateSlideOutEffect, 1 );
}

/* 'C' function for method : 'Launcher::LNC_Main.OnCurrentItemChangedSlot()' */
void LauncherLNC_Main_OnCurrentItemChangedSlot( LauncherLNC_Main _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwTrace( "%s%e", EwLoadString( &_Const0007 ), _this->LNC_RotaryPlate.CurrentItem );
  _this->PreviousItem = _this->LNC_RotaryPlate.PreviousItem;
  _this->CurrentItem = _this->LNC_RotaryPlate.CurrentItem;
  _this->NextItem = _this->LNC_RotaryPlate.NextItem;
  LauncherLNC_Base_SetItems( &_this->LNC_Base, _this->PreviousItem, _this->CurrentItem, 
  _this->NextItem );
}

/* 'C' function for method : 'Launcher::LNC_Main.GetInitialSelectedItem()' */
XEnum LauncherLNC_Main_GetInitialSelectedItem( LauncherLNC_Main _this )
{
  XBool is_phone_call_active;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  is_phone_call_active = 0;

  if ( is_phone_call_active )
    return EnumLauncherItemPHONE;
  else
    return EnumLauncherItemMUSIC;
}

/* 'C' function for method : 'Launcher::LNC_Main.GetNextItem()' */
XEnum LauncherLNC_Main_GetNextItem( LauncherLNC_Main _this, XEnum aBaseItem )
{
  XUInt32 TotalItemNum = 12;
  XEnum BaseItemNext = aBaseItem;
  XBool bypass = 0;

  do
  {
    BaseItemNext = (XEnum)(((XUInt32)BaseItemNext + 1 ) % TotalItemNum );

    if ((((( EnumLauncherItemTRACTION_CONTROL == BaseItemNext ) && !_this->TCSEnabled ) 
        || (( EnumLauncherItemSEAT_HEATER == BaseItemNext ) && !_this->SeatHeaterEnabled )) 
        || (( EnumLauncherItemGRIP_WARMER == BaseItemNext ) && !_this->GripWarmerEnabled )) 
        || (( EnumLauncherItemWIND_SCREEN == BaseItemNext ) && !_this->WindScreenEnabled ))
    {
      bypass = 1;
    }
    else
    {
      bypass = 0;
    }
  }
  while ( bypass );

  return BaseItemNext;
}

/* 'C' function for method : 'Launcher::LNC_Main.GetPreviousItem()' */
XEnum LauncherLNC_Main_GetPreviousItem( LauncherLNC_Main _this, XEnum aBaseItem )
{
  XUInt32 TotalItemNum = 12;
  XEnum BaseItemPrevious = aBaseItem;
  XBool bypass = 0;

  do
  {
    BaseItemPrevious = (XEnum)((((XUInt32)BaseItemPrevious + TotalItemNum ) - 1 ) 
    % TotalItemNum );

    if ((((( EnumLauncherItemTRACTION_CONTROL == BaseItemPrevious ) && !_this->TCSEnabled ) 
        || (( EnumLauncherItemSEAT_HEATER == BaseItemPrevious ) && !_this->SeatHeaterEnabled )) 
        || (( EnumLauncherItemGRIP_WARMER == BaseItemPrevious ) && !_this->GripWarmerEnabled )) 
        || (( EnumLauncherItemWIND_SCREEN == BaseItemPrevious ) && !_this->WindScreenEnabled ))
    {
      bypass = 1;
    }
    else
    {
      bypass = 0;
    }
  }
  while ( bypass );

  return BaseItemPrevious;
}

/* 'C' function for method : 'Launcher::LNC_Main.OnSelectedAnimationFinishedSlot()' */
void LauncherLNC_Main_OnSelectedAnimationFinishedSlot( LauncherLNC_Main _this, XObject 
  sender )
{
  ComponentsBaseComponent ItemDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ItemDialog = 0;

  switch ( _this->CurrentItem )
  {
    case EnumLauncherItemPHONE :
      ;
    break;

    case EnumLauncherItemMUSIC :
    {
      ItemDialog = ((ComponentsBaseComponent)EwNewObject( MediaMED01_MediaUI, 0 ));
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)ItemDialog ), 0, 0, 
      0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
    break;

    case EnumLauncherItemODO_TRIP :
      ;
    break;

    case EnumLauncherItemTHEME :
      ;
    break;

    case EnumLauncherItemNAVIGATION :
    {
      ItemDialog = ((ComponentsBaseComponent)EwNewObject( NavigationNAV06_NaviSettingMenu, 
      0 ));
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)ItemDialog ), 0, 0, 
      0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
    break;

    case EnumLauncherItemNOTIFICATION :
      ;
    break;

    case EnumLauncherItemWEATHER :
      ;
    break;

    case EnumLauncherItemSETTINGS :
    {
      ItemDialog = ((ComponentsBaseComponent)EwNewObject( SettingsSET01_MainSettingMenu, 
      0 ));
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)ItemDialog ), 0, 0, 
      0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
    break;

    case EnumLauncherItemTRACTION_CONTROL :
      ;
    break;

    case EnumLauncherItemSEAT_HEATER :
      ;
    break;

    case EnumLauncherItemGRIP_WARMER :
      ;
    break;

    case EnumLauncherItemWIND_SCREEN :
      ;
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Launcher::LNC_Main.OnSlideOutFinishedSlot()' */
void LauncherLNC_Main_OnSlideOutFinishedSlot( LauncherLNC_Main _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( !_this->BaseSlideOutEffect.Super1.Enabled && !_this->RotaryPlateSlideOutEffect.Super1.Enabled )
  {
    CoreGroup__DismissDialog( _this->Super4.Owner, ((CoreGroup)_this ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 0 );
  }
}

/* Variants derived from the class : 'Launcher::LNC_Main' */
EW_DEFINE_CLASS_VARIANTS( LauncherLNC_Main )
EW_END_OF_CLASS_VARIANTS( LauncherLNC_Main )

/* Virtual Method Table (VMT) for the class : 'Launcher::LNC_Main' */
EW_DEFINE_CLASS( LauncherLNC_Main, ComponentsBaseComponent, BaseSlideInEffect, BaseSlideInEffect, 
                 BaseSlideInEffect, BaseSlideInEffect, NextItem, NextItem, "Launcher::LNC_Main" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetBuffered,
  CoreGroup_OnGetEnabled,
  CoreGroup_OnSetEnabled,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DismissDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateLayout,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  LauncherLNC_Main_OnShortDownKeyActivated,
  LauncherLNC_Main_OnShortUpKeyActivated,
  LauncherLNC_Main_OnShortEnterKeyActivated,
  LauncherLNC_Main_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
EW_END_OF_CLASS( LauncherLNC_Main )

/* Initializer for the class 'Launcher::LNC_RotaryPlate' */
void LauncherLNC_RotaryPlate__Init( LauncherLNC_RotaryPlate _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( LauncherLNC_RotaryPlate );

  /* ... then construct all embedded objects */
  EffectsRectEffect__Init( &_this->RectEffect0, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->RectEffect1, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->RectEffect2, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->RectEffect3, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->SelectedAnimationTimer, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->BaseImage, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Icon0, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Icon1, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Icon2, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Icon3, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->IconSelectedLarge, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->HighlightImage, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( LauncherLNC_RotaryPlate );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0008 );
  _this->RotationDirection = EnumRotationDirectionCLOCKWISE;
  _this->IconPositions[ 0 ] = _Const0009;
  _this->IconPositions[ 1 ] = _Const000A;
  _this->IconPositions[ 2 ] = _Const000B;
  _this->IconPositions[ 3 ] = _Const000C;
  _this->IconPositions[ 4 ] = _Const000D;
  _this->SelectedIconIdx = 1;
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->RectEffect0, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->RectEffect0, 150 );
  _this->RectEffect0.Value2 = _Const000E;
  _this->RectEffect0.Value1 = _Const000E;
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->RectEffect1, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->RectEffect1, 150 );
  _this->RectEffect1.Value2 = _Const000E;
  _this->RectEffect1.Value1 = _Const000E;
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->RectEffect2, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->RectEffect2, 150 );
  _this->RectEffect2.Value2 = _Const000E;
  _this->RectEffect2.Value1 = _Const000E;
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->RectEffect3, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->RectEffect3, 150 );
  _this->RectEffect3.Value2 = _Const000E;
  _this->RectEffect3.Value1 = _Const000E;
  CoreTimer_OnSetPeriod( &_this->SelectedAnimationTimer, 100 );
  CoreRectView__OnSetBounds( &_this->BaseImage, _Const0008 );
  CoreView_OnSetLayout((CoreView)&_this->Icon0, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->Icon0, _Const000A );
  ViewsImage_OnSetFrameNumber( &_this->Icon0, 1 );
  CoreView_OnSetLayout((CoreView)&_this->Icon1, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->Icon1, _Const000B );
  ViewsImage_OnSetFrameNumber( &_this->Icon1, 1 );
  ViewsImage_OnSetVisible( &_this->Icon1, 0 );
  CoreView_OnSetLayout((CoreView)&_this->Icon2, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->Icon2, _Const000C );
  ViewsImage_OnSetFrameNumber( &_this->Icon2, 1 );
  CoreView_OnSetLayout((CoreView)&_this->Icon3, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->Icon3, _Const000F );
  ViewsImage_OnSetFrameNumber( &_this->Icon3, 1 );
  CoreView_OnSetLayout((CoreView)&_this->IconSelectedLarge, CoreLayoutAlignToLeft 
  | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->IconSelectedLarge, _Const0010 );
  ViewsImage_OnSetFrameNumber( &_this->IconSelectedLarge, 1 );
  ViewsImage_OnSetVisible( &_this->IconSelectedLarge, 1 );
  CoreRectView__OnSetBounds( &_this->HighlightImage, _Const0011 );
  ViewsImage_OnSetVisible( &_this->HighlightImage, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BaseImage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Icon0 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Icon1 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Icon2 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Icon3 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->IconSelectedLarge ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->HighlightImage ), 0 );
  _this->Icons[ 0 ] = &_this->Icon0;
  _this->Icons[ 1 ] = &_this->Icon1;
  _this->Icons[ 2 ] = &_this->Icon2;
  _this->Icons[ 3 ] = &_this->Icon3;
  _this->RectEffectArray[ 0 ] = &_this->RectEffect0;
  _this->RectEffectArray[ 1 ] = &_this->RectEffect1;
  _this->RectEffectArray[ 2 ] = &_this->RectEffect2;
  _this->RectEffectArray[ 3 ] = &_this->RectEffect3;
  _this->SelectedAnimationTimer.OnTrigger = EwNewSlot( _this, LauncherLNC_RotaryPlate_OnSelectedAnimationFinishedSlot );
  ViewsImage_OnSetBitmap( &_this->BaseImage, EwLoadResource( &ResourceLCBase, ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Icon0, EwLoadResource( &ResourceIconMusicSmall, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Icon1, EwLoadResource( &ResourceIconTcsSmall, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Icon2, EwLoadResource( &ResourceIconPhoneSmall, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Icon3, EwLoadResource( &ResourceIconSettingSmall, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->IconSelectedLarge, EwLoadResource( &ResourceIconTcsLarge, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->HighlightImage, EwLoadResource( &ResourceLCHighlight, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'Launcher::LNC_RotaryPlate' */
void LauncherLNC_RotaryPlate__ReInit( LauncherLNC_RotaryPlate _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  EffectsRectEffect__ReInit( &_this->RectEffect0 );
  EffectsRectEffect__ReInit( &_this->RectEffect1 );
  EffectsRectEffect__ReInit( &_this->RectEffect2 );
  EffectsRectEffect__ReInit( &_this->RectEffect3 );
  CoreTimer__ReInit( &_this->SelectedAnimationTimer );
  ViewsImage__ReInit( &_this->BaseImage );
  ViewsImage__ReInit( &_this->Icon0 );
  ViewsImage__ReInit( &_this->Icon1 );
  ViewsImage__ReInit( &_this->Icon2 );
  ViewsImage__ReInit( &_this->Icon3 );
  ViewsImage__ReInit( &_this->IconSelectedLarge );
  ViewsImage__ReInit( &_this->HighlightImage );
}

/* Finalizer method for the class 'Launcher::LNC_RotaryPlate' */
void LauncherLNC_RotaryPlate__Done( LauncherLNC_RotaryPlate _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  EffectsRectEffect__Done( &_this->RectEffect0 );
  EffectsRectEffect__Done( &_this->RectEffect1 );
  EffectsRectEffect__Done( &_this->RectEffect2 );
  EffectsRectEffect__Done( &_this->RectEffect3 );
  CoreTimer__Done( &_this->SelectedAnimationTimer );
  ViewsImage__Done( &_this->BaseImage );
  ViewsImage__Done( &_this->Icon0 );
  ViewsImage__Done( &_this->Icon1 );
  ViewsImage__Done( &_this->Icon2 );
  ViewsImage__Done( &_this->Icon3 );
  ViewsImage__Done( &_this->IconSelectedLarge );
  ViewsImage__Done( &_this->HighlightImage );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.OnShortDownKeyActivated()' */
void LauncherLNC_RotaryPlate_OnShortDownKeyActivated( LauncherLNC_RotaryPlate _this )
{
  LauncherLNC_RotaryPlate_StartIconRotation( _this, EnumRotationDirectionCOUNTER_CLOCKWISE );
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.OnShortUpKeyActivated()' */
void LauncherLNC_RotaryPlate_OnShortUpKeyActivated( LauncherLNC_RotaryPlate _this )
{
  LauncherLNC_RotaryPlate_StartIconRotation( _this, EnumRotationDirectionCLOCKWISE );
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.StartIconRotation()' */
void LauncherLNC_RotaryPlate_StartIconRotation( LauncherLNC_RotaryPlate _this, XEnum 
  aDirection )
{
  LauncherLNC_Main LNCMainDialog;
  XInt32 HiddenIconIdx;
  XInt32 IconIdx;
  XInt32 i;

  _this->RotationDirection = aDirection;
  LNCMainDialog = EwCastObject( _this->Super4.Owner, LauncherLNC_Main );

  if ( EnumRotationDirectionCLOCKWISE == aDirection )
  {
    _this->HiddenItem = LauncherLNC_Main_GetPreviousItem( LNCMainDialog, _this->PreviousItem );
  }
  else
  {
    _this->HiddenItem = LauncherLNC_Main_GetNextItem( LNCMainDialog, _this->NextItem );
  }

  HiddenIconIdx = ( _this->SelectedIconIdx + 2 ) % 4;
  ViewsImage_OnSetBitmap( _this->Icons[ EwCheckIndex( HiddenIconIdx, 4 )], LauncherLNC_RotaryPlate_GetSmallIconResourceOfItem( 
  _this, _this->HiddenItem ));
  ViewsImage_OnSetVisible( &_this->IconSelectedLarge, 0 );
  ViewsImage_OnSetVisible( _this->Icons[ EwCheckIndex( _this->SelectedIconIdx, 4 )], 
  1 );
  IconIdx = 0;
  i = 0;

  for ( i = 0; i < 4; i = i + 1 )
  {
    EffectsRectEffect Effect = _this->RectEffectArray[ EwCheckIndex( i, 4 )];

    if ( EnumRotationDirectionCLOCKWISE == aDirection )
    {
      IconIdx = ((( _this->SelectedIconIdx - 2 ) + i ) + 4 ) % 4;
      Effect->Value1 = _this->IconPositions[ EwCheckIndex( i, 5 )];
      Effect->Value2 = _this->IconPositions[ EwCheckIndex( i + 1, 5 )];
    }
    else
    {
      IconIdx = ((( _this->SelectedIconIdx - 1 ) + i ) + 4 ) % 4;
      Effect->Value1 = _this->IconPositions[ EwCheckIndex( i + 1, 5 )];
      Effect->Value2 = _this->IconPositions[ EwCheckIndex( i, 5 )];
    }

    if ( _this->SelectedIconIdx == IconIdx )
    {
      Effect->Super1.OnFinished = EwNewSlot( _this, LauncherLNC_RotaryPlate_OnIconRotationFinished );
    }
    else
    {
      Effect->Super1.OnFinished = EwNullSlot;
    }

    Effect->Outlet = EwNewRef( _this->Icons[ EwCheckIndex( IconIdx, 4 )], CoreRectView_OnGetBounds, 
    CoreRectView__OnSetBounds );
    EffectsEffect_OnSetEnabled((EffectsEffect)Effect, 1 );
  }
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.OnIconRotationFinished()' */
void LauncherLNC_RotaryPlate_OnIconRotationFinished( LauncherLNC_RotaryPlate _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EnumRotationDirectionCLOCKWISE == _this->RotationDirection )
  {
    _this->SelectedIconIdx = (( _this->SelectedIconIdx - 1 ) + 4 ) % 4;
    _this->NextItem = _this->CurrentItem;
    _this->CurrentItem = _this->PreviousItem;
    _this->PreviousItem = _this->HiddenItem;
  }
  else
  {
    _this->SelectedIconIdx = ( _this->SelectedIconIdx + 1 ) % 4;
    _this->PreviousItem = _this->CurrentItem;
    _this->CurrentItem = _this->NextItem;
    _this->NextItem = _this->HiddenItem;
  }

  ViewsImage_OnSetBitmap( &_this->IconSelectedLarge, LauncherLNC_RotaryPlate_GetLargeIconResourceOfItem( 
  _this, _this->CurrentItem ));
  ViewsImage_OnSetVisible( _this->Icons[ EwCheckIndex( _this->SelectedIconIdx, 4 )], 
  0 );
  ViewsImage_OnSetVisible( &_this->IconSelectedLarge, 1 );
  EwPostSignal( _this->OnIconsRotated, ((XObject)_this ));
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.SetItems()' */
void LauncherLNC_RotaryPlate_SetItems( LauncherLNC_RotaryPlate _this, XEnum aPreviousItem, 
  XEnum aCurrentItem, XEnum aNextItem )
{
  XInt32 PeviousIconIdx;
  XInt32 NextIconIdx;

  EwTrace( "%s%e", EwLoadString( &_Const0012 ), aCurrentItem );
  _this->PreviousItem = aPreviousItem;
  _this->CurrentItem = aCurrentItem;
  _this->NextItem = aNextItem;
  ViewsImage_OnSetBitmap( _this->Icons[ EwCheckIndex( _this->SelectedIconIdx, 4 )], 
  LauncherLNC_RotaryPlate_GetSmallIconResourceOfItem( _this, _this->CurrentItem ));
  ViewsImage_OnSetBitmap( &_this->IconSelectedLarge, LauncherLNC_RotaryPlate_GetLargeIconResourceOfItem( 
  _this, _this->CurrentItem ));
  PeviousIconIdx = (( _this->SelectedIconIdx - 1 ) + 4 ) % 4;
  ViewsImage_OnSetBitmap( _this->Icons[ EwCheckIndex( PeviousIconIdx, 4 )], LauncherLNC_RotaryPlate_GetSmallIconResourceOfItem( 
  _this, _this->PreviousItem ));
  NextIconIdx = ( _this->SelectedIconIdx + 1 ) % 4;
  ViewsImage_OnSetBitmap( _this->Icons[ EwCheckIndex( NextIconIdx, 4 )], LauncherLNC_RotaryPlate_GetSmallIconResourceOfItem( 
  _this, _this->NextItem ));
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.GetSmallIconResourceOfItem()' */
ResourcesBitmap LauncherLNC_RotaryPlate_GetSmallIconResourceOfItem( LauncherLNC_RotaryPlate _this, 
  XEnum aItem )
{
  ResourcesBitmap IconBitmap;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IconBitmap = 0;

  switch ( aItem )
  {
    case EnumLauncherItemPHONE :
      IconBitmap = EwLoadResource( &ResourceIconPhoneSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemMUSIC :
      IconBitmap = EwLoadResource( &ResourceIconMusicSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemODO_TRIP :
      IconBitmap = EwLoadResource( &ResourceIconOdoTripSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemTHEME :
      IconBitmap = EwLoadResource( &ResourceIconThemeSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemNAVIGATION :
      IconBitmap = EwLoadResource( &ResourceIconNavigationSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemNOTIFICATION :
      IconBitmap = EwLoadResource( &ResourceIconNotificationSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemWEATHER :
      IconBitmap = EwLoadResource( &ResourceIconWeatherSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemSETTINGS :
      IconBitmap = EwLoadResource( &ResourceIconSettingSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemTRACTION_CONTROL :
      IconBitmap = EwLoadResource( &ResourceIconTcsSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemSEAT_HEATER :
    {
      IconBitmap = EwLoadResource( &ResourceIconSeatHeater0Small, ResourcesBitmap );
    }
    break;

    case EnumLauncherItemGRIP_WARMER :
    {
      IconBitmap = EwLoadResource( &ResourceIconGripWarmer0Small, ResourcesBitmap );
    }
    break;

    case EnumLauncherItemWIND_SCREEN :
      IconBitmap = EwLoadResource( &ResourceIconWindScreenSmall, ResourcesBitmap );
    break;

    default : 
      ;
  }

  return IconBitmap;
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.GetLargeIconResourceOfItem()' */
ResourcesBitmap LauncherLNC_RotaryPlate_GetLargeIconResourceOfItem( LauncherLNC_RotaryPlate _this, 
  XEnum aItem )
{
  ResourcesBitmap IconBitmap;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IconBitmap = 0;

  switch ( aItem )
  {
    case EnumLauncherItemPHONE :
      IconBitmap = EwLoadResource( &ResourceIconPhoneLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemMUSIC :
      IconBitmap = EwLoadResource( &ResourceIconMusicLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemODO_TRIP :
      IconBitmap = EwLoadResource( &ResourceIconOdoTripLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemTHEME :
      IconBitmap = EwLoadResource( &ResourceIconThemeLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemNAVIGATION :
      IconBitmap = EwLoadResource( &ResourceIconNavigationLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemNOTIFICATION :
      IconBitmap = EwLoadResource( &ResourceIconNotificationLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemWEATHER :
      IconBitmap = EwLoadResource( &ResourceIconWeatherLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemSETTINGS :
      IconBitmap = EwLoadResource( &ResourceIconSettingLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemTRACTION_CONTROL :
      IconBitmap = EwLoadResource( &ResourceIconTcsLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemSEAT_HEATER :
    {
      IconBitmap = EwLoadResource( &ResourceIconSeatHeater0Large, ResourcesBitmap );
    }
    break;

    case EnumLauncherItemGRIP_WARMER :
    {
      IconBitmap = EwLoadResource( &ResourceIconGripWarmer0Large, ResourcesBitmap );
    }
    break;

    case EnumLauncherItemWIND_SCREEN :
      IconBitmap = EwLoadResource( &ResourceIconWindScreenLarge, ResourcesBitmap );
    break;

    default : 
      ;
  }

  return IconBitmap;
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.StartSelectedAnimation()' */
void LauncherLNC_RotaryPlate_StartSelectedAnimation( LauncherLNC_RotaryPlate _this )
{
  ViewsImage_OnSetVisible( &_this->HighlightImage, 1 );
  CoreTimer_OnSetEnabled( &_this->SelectedAnimationTimer, 1 );
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.OnSelectedAnimationFinishedSlot()' */
void LauncherLNC_RotaryPlate_OnSelectedAnimationFinishedSlot( LauncherLNC_RotaryPlate _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsImage_OnSetVisible( &_this->HighlightImage, 0 );
  CoreTimer_OnSetEnabled( &_this->SelectedAnimationTimer, 0 );
  EwPostSignal( _this->OnSelectedAnimationFinished, ((XObject)_this ));
}

/* Variants derived from the class : 'Launcher::LNC_RotaryPlate' */
EW_DEFINE_CLASS_VARIANTS( LauncherLNC_RotaryPlate )
EW_END_OF_CLASS_VARIANTS( LauncherLNC_RotaryPlate )

/* Virtual Method Table (VMT) for the class : 'Launcher::LNC_RotaryPlate' */
EW_DEFINE_CLASS( LauncherLNC_RotaryPlate, ComponentsBaseComponent, Icons, OnIconsRotated, 
                 RectEffect0, RectEffect0, IconPositions, IconPositions, "Launcher::LNC_RotaryPlate" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetBuffered,
  CoreGroup_OnGetEnabled,
  CoreGroup_OnSetEnabled,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DismissDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateLayout,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  LauncherLNC_RotaryPlate_OnShortDownKeyActivated,
  LauncherLNC_RotaryPlate_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
EW_END_OF_CLASS( LauncherLNC_RotaryPlate )

/* Initializer for the class 'Launcher::LNC_Base' */
void LauncherLNC_Base__Init( LauncherLNC_Base _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( LauncherLNC_Base );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->BlackBG, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ImgLCBlueline, &_this->_XObject, 0 );
  ViewsText__Init( &_this->CurrentItemTitleText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->PreviousItemTitleText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NextItemTitleText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( LauncherLNC_Base );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0001 );
  CoreRectView__OnSetBounds( &_this->BlackBG, _Const0013 );
  ViewsRectangle_OnSetColor( &_this->BlackBG, _Const0014 );
  CoreRectView__OnSetBounds( &_this->ImgLCBlueline, _Const0015 );
  CoreRectView__OnSetBounds( &_this->CurrentItemTitleText, _Const0016 );
  ViewsText_OnSetAlignment( &_this->CurrentItemTitleText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  CoreRectView__OnSetBounds( &_this->PreviousItemTitleText, _Const0017 );
  ViewsText_OnSetAlignment( &_this->PreviousItemTitleText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->PreviousItemTitleText, 0 );
  ViewsText_OnSetColor( &_this->PreviousItemTitleText, _Const0018 );
  CoreRectView__OnSetBounds( &_this->NextItemTitleText, _Const0019 );
  ViewsText_OnSetAlignment( &_this->NextItemTitleText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->NextItemTitleText, 0 );
  ViewsText_OnSetColor( &_this->NextItemTitleText, _Const0018 );
  CoreGroup__Add( _this, ((CoreView)&_this->BlackBG ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ImgLCBlueline ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CurrentItemTitleText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PreviousItemTitleText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextItemTitleText ), 0 );
  ViewsImage_OnSetBitmap( &_this->ImgLCBlueline, EwLoadResource( &ResourceLCBlueline, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->CurrentItemTitleText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->PreviousItemTitleText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->NextItemTitleText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Launcher::LNC_Base' */
void LauncherLNC_Base__ReInit( LauncherLNC_Base _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->BlackBG );
  ViewsImage__ReInit( &_this->ImgLCBlueline );
  ViewsText__ReInit( &_this->CurrentItemTitleText );
  ViewsText__ReInit( &_this->PreviousItemTitleText );
  ViewsText__ReInit( &_this->NextItemTitleText );
}

/* Finalizer method for the class 'Launcher::LNC_Base' */
void LauncherLNC_Base__Done( LauncherLNC_Base _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->BlackBG );
  ViewsImage__Done( &_this->ImgLCBlueline );
  ViewsText__Done( &_this->CurrentItemTitleText );
  ViewsText__Done( &_this->PreviousItemTitleText );
  ViewsText__Done( &_this->NextItemTitleText );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* 'C' function for method : 'Launcher::LNC_Base.GetStringOfLauncherItem()' */
XString LauncherLNC_Base_GetStringOfLauncherItem( LauncherLNC_Base _this, XEnum 
  aLauncherItem )
{
  XString Title;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Title = 0;

  switch ( aLauncherItem )
  {
    case EnumLauncherItemPHONE :
      Title = EwLoadString( &StringsLNC_phone );
    break;

    case EnumLauncherItemMUSIC :
      Title = EwLoadString( &StringsLNC_music );
    break;

    case EnumLauncherItemODO_TRIP :
      Title = EwLoadString( &StringsLNC_odo_trip );
    break;

    case EnumLauncherItemTHEME :
      Title = EwLoadString( &StringsLNC_theme );
    break;

    case EnumLauncherItemNAVIGATION :
      Title = EwLoadString( &StringsLNC_navigation );
    break;

    case EnumLauncherItemNOTIFICATION :
      Title = EwLoadString( &StringsLNC_notification );
    break;

    case EnumLauncherItemWEATHER :
      Title = EwLoadString( &StringsLNC_weather );
    break;

    case EnumLauncherItemSETTINGS :
      Title = EwLoadString( &StringsLNC_settings );
    break;

    case EnumLauncherItemTRACTION_CONTROL :
      Title = EwLoadString( &StringsLNC_traction_control );
    break;

    case EnumLauncherItemSEAT_HEATER :
      Title = EwLoadString( &StringsLNC_seat_heater );
    break;

    case EnumLauncherItemGRIP_WARMER :
      Title = EwLoadString( &StringsGPW01_grip_warmer );
    break;

    case EnumLauncherItemWIND_SCREEN :
      Title = EwLoadString( &StringsWSC01_wind_screen );
    break;

    default : 
      ;
  }

  return Title;
}

/* 'C' function for method : 'Launcher::LNC_Base.SetItems()' */
void LauncherLNC_Base_SetItems( LauncherLNC_Base _this, XEnum aPreviousItem, XEnum 
  aCurrentItem, XEnum aNextItem )
{
  ViewsText_OnSetString( &_this->PreviousItemTitleText, LauncherLNC_Base_GetStringOfLauncherItem( 
  _this, aPreviousItem ));
  ViewsText_OnSetString( &_this->CurrentItemTitleText, LauncherLNC_Base_GetStringOfLauncherItem( 
  _this, aCurrentItem ));
  ViewsText_OnSetString( &_this->NextItemTitleText, LauncherLNC_Base_GetStringOfLauncherItem( 
  _this, aNextItem ));
}

/* Variants derived from the class : 'Launcher::LNC_Base' */
EW_DEFINE_CLASS_VARIANTS( LauncherLNC_Base )
EW_END_OF_CLASS_VARIANTS( LauncherLNC_Base )

/* Virtual Method Table (VMT) for the class : 'Launcher::LNC_Base' */
EW_DEFINE_CLASS( LauncherLNC_Base, CoreGroup, BlackBG, BlackBG, BlackBG, BlackBG, 
                 _None, _None, "Launcher::LNC_Base" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetBuffered,
  CoreGroup_OnGetEnabled,
  CoreGroup_OnSetEnabled,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DismissDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateLayout,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
EW_END_OF_CLASS( LauncherLNC_Base )

/* Embedded Wizard */
