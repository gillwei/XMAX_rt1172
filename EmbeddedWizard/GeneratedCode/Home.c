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

#include "ewlocale.h"
#include "_ApplicationApplication.h"
#include "_CoreGroup.h"
#include "_CoreKeyPressHandler.h"
#include "_CoreRoot.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreVerticalList.h"
#include "_CoreView.h"
#include "_DeviceInterfaceNavigationDeviceClass.h"
#include "_DeviceInterfaceVehicleDataClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_EffectsInt32Effect.h"
#include "_HomeBaseHome.h"
#include "_HomeHOM03_VehicleInfo.h"
#include "_HomeHOM11_TachoVisualizer.h"
#include "_HomeHOM12_EcoVisualizer.h"
#include "_HomeHOM13_SpeedVisualizer.h"
#include "_HomeItemVehicleInfo.h"
#include "_HomeVehicleInfoMenu.h"
#include "_InfoINF01_MeterDisplaySettingMenu.h"
#include "_LauncherLNC_Main.h"
#include "_MenuBaseMenuView.h"
#include "_PopPOP02_ConnectionError.h"
#include "_PopPOP16_NaviLoadingUI.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_SettingsSET46_VehicleInfoReset.h"
#include "_ViewsImage.h"
#include "_ViewsText.h"
#include "Core.h"
#include "DeviceInterface.h"
#include "Effects.h"
#include "Enum.h"
#include "Fonts.h"
#include "Home.h"
#include "Resource.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault0[] =
{
  0x0000006C, /* ratio 70.37 % */
  0xB8001B00, 0x00092452, 0x00D20037, 0x040003A0, 0x9E002400, 0x20026800, 0x18004546,
  0x88341205, 0x87432150, 0xB4522510, 0x00230328, 0x260F058D, 0x61F0D85C, 0x671789C4,
  0x71C94498, 0x229747E5, 0x2000C001, 0x80C9A4D3, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 72, 113 }, { 403, 156 }};
static const XStringRes _Const0001 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0002 = { _StringsDefault0, 0x000F };
static const XStringRes _Const0003 = { _StringsDefault0, 0x001C };
static const XRect _Const0004 = {{ 0, 38 }, { 480, 272 }};
static const XRect _Const0005 = {{ 17, 51 }, { 67, 101 }};
static const XRect _Const0006 = {{ 78, 40 }, { 480, 268 }};
static const XStringRes _Const0007 = { _StringsDefault0, 0x0029 };
static const XRect _Const0008 = {{ 0, 0 }, { 402, 228 }};
static const XRect _Const0009 = {{ 0, 70 }, { 359, 77 }};
static const XRect _Const000A = {{ 0, 146 }, { 359, 153 }};
static const XRect _Const000B = {{ 363, 1 }, { 395, 33 }};
static const XRect _Const000C = {{ 363, 185 }, { 395, 217 }};
static const XRect _Const000D = {{ 0, 0 }, { 400, 76 }};
static const XRect _Const000E = {{ 7, 19 }, { 144, 52 }};
static const XColor _Const000F = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const0010 = {{ 288, 15 }, { 346, 57 }};
static const XRect _Const0011 = {{ 149, 7 }, { 281, 64 }};
static const XRect _Const0012 = {{ 232, 7 }, { 282, 64 }};
static const XRect _Const0013 = {{ 147, 7 }, { 197, 64 }};
static const XRect _Const0014 = {{ 204, 15 }, { 231, 57 }};

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

/* Initializer for the class 'Home::HOM11_TachoVisualizer' */
void HomeHOM11_TachoVisualizer__Init( HomeHOM11_TachoVisualizer _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  HomeBaseHome__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeHOM11_TachoVisualizer );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Title, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeHOM11_TachoVisualizer );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super1.HomeType = EnumHomeTypeTACHO_VISUALIZER;
  CoreRectView__OnSetBounds( &_this->Title, _Const0000 );
  ViewsText_OnSetAlignment( &_this->Title, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Title, EwLoadString( &StringsINF01_TACHO_VISUALIZER ));
  CoreGroup__Add( _this, ((CoreView)&_this->Title ), 0 );
  ViewsText_OnSetFont( &_this->Title, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));

  /* Call the user defined constructor */
  HomeHOM11_TachoVisualizer_Init( _this, aArg );
}

/* Re-Initializer for the class 'Home::HOM11_TachoVisualizer' */
void HomeHOM11_TachoVisualizer__ReInit( HomeHOM11_TachoVisualizer _this )
{
  /* At first re-initialize the super class ... */
  HomeBaseHome__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Title );
}

/* Finalizer method for the class 'Home::HOM11_TachoVisualizer' */
void HomeHOM11_TachoVisualizer__Done( HomeHOM11_TachoVisualizer _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Title );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void HomeHOM11_TachoVisualizer_Init( HomeHOM11_TachoVisualizer _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0001 ));
}

/* 'C' function for method : 'Home::HOM11_TachoVisualizer.OnLongEnterKeyActivated()' */
void HomeHOM11_TachoVisualizer_OnLongEnterKeyActivated( HomeHOM11_TachoVisualizer _this )
{
  if ( 1 == _this->Super3.KeyHandler.RepetitionCount )
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( InfoINF01_MeterDisplaySettingMenu, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* Variants derived from the class : 'Home::HOM11_TachoVisualizer' */
EW_DEFINE_CLASS_VARIANTS( HomeHOM11_TachoVisualizer )
EW_END_OF_CLASS_VARIANTS( HomeHOM11_TachoVisualizer )

/* Virtual Method Table (VMT) for the class : 'Home::HOM11_TachoVisualizer' */
EW_DEFINE_CLASS( HomeHOM11_TachoVisualizer, HomeBaseHome, Title, Title, Title, Title, 
                 _.VMT, _.VMT, "Home::HOM11_TachoVisualizer" )
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
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
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  HomeBaseHome_OnShortEnterKeyActivated,
  HomeBaseHome_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  HomeHOM11_TachoVisualizer_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  HomeBaseHome_ReturnToHome,
EW_END_OF_CLASS( HomeHOM11_TachoVisualizer )

/* Initializer for the class 'Home::HOM12_EcoVisualizer' */
void HomeHOM12_EcoVisualizer__Init( HomeHOM12_EcoVisualizer _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  HomeBaseHome__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeHOM12_EcoVisualizer );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Title, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeHOM12_EcoVisualizer );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super1.HomeType = EnumHomeTypeECO_VISUALIZER;
  CoreRectView__OnSetBounds( &_this->Title, _Const0000 );
  ViewsText_OnSetAlignment( &_this->Title, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Title, EwLoadString( &StringsINF01_ECHO_VISUALIZER ));
  CoreGroup__Add( _this, ((CoreView)&_this->Title ), 0 );
  ViewsText_OnSetFont( &_this->Title, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));

  /* Call the user defined constructor */
  HomeHOM12_EcoVisualizer_Init( _this, aArg );
}

/* Re-Initializer for the class 'Home::HOM12_EcoVisualizer' */
void HomeHOM12_EcoVisualizer__ReInit( HomeHOM12_EcoVisualizer _this )
{
  /* At first re-initialize the super class ... */
  HomeBaseHome__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Title );
}

/* Finalizer method for the class 'Home::HOM12_EcoVisualizer' */
void HomeHOM12_EcoVisualizer__Done( HomeHOM12_EcoVisualizer _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Title );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void HomeHOM12_EcoVisualizer_Init( HomeHOM12_EcoVisualizer _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0002 ));
}

/* 'C' function for method : 'Home::HOM12_EcoVisualizer.OnLongEnterKeyActivated()' */
void HomeHOM12_EcoVisualizer_OnLongEnterKeyActivated( HomeHOM12_EcoVisualizer _this )
{
  if ( 1 == _this->Super3.KeyHandler.RepetitionCount )
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( InfoINF01_MeterDisplaySettingMenu, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* Variants derived from the class : 'Home::HOM12_EcoVisualizer' */
EW_DEFINE_CLASS_VARIANTS( HomeHOM12_EcoVisualizer )
EW_END_OF_CLASS_VARIANTS( HomeHOM12_EcoVisualizer )

/* Virtual Method Table (VMT) for the class : 'Home::HOM12_EcoVisualizer' */
EW_DEFINE_CLASS( HomeHOM12_EcoVisualizer, HomeBaseHome, Title, Title, Title, Title, 
                 _.VMT, _.VMT, "Home::HOM12_EcoVisualizer" )
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
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
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  HomeBaseHome_OnShortEnterKeyActivated,
  HomeBaseHome_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  HomeHOM12_EcoVisualizer_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  HomeBaseHome_ReturnToHome,
EW_END_OF_CLASS( HomeHOM12_EcoVisualizer )

/* Initializer for the class 'Home::HOM13_SpeedVisualizer' */
void HomeHOM13_SpeedVisualizer__Init( HomeHOM13_SpeedVisualizer _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  HomeBaseHome__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeHOM13_SpeedVisualizer );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Title, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeHOM13_SpeedVisualizer );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super1.HomeType = EnumHomeTypeSPEED_VISUALIZER;
  CoreRectView__OnSetBounds( &_this->Title, _Const0000 );
  ViewsText_OnSetAlignment( &_this->Title, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Title, EwLoadString( &StringsINF01_SPEED_VISUALIZER ));
  CoreGroup__Add( _this, ((CoreView)&_this->Title ), 0 );
  ViewsText_OnSetFont( &_this->Title, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));

  /* Call the user defined constructor */
  HomeHOM13_SpeedVisualizer_Init( _this, aArg );
}

/* Re-Initializer for the class 'Home::HOM13_SpeedVisualizer' */
void HomeHOM13_SpeedVisualizer__ReInit( HomeHOM13_SpeedVisualizer _this )
{
  /* At first re-initialize the super class ... */
  HomeBaseHome__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Title );
}

/* Finalizer method for the class 'Home::HOM13_SpeedVisualizer' */
void HomeHOM13_SpeedVisualizer__Done( HomeHOM13_SpeedVisualizer _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Title );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void HomeHOM13_SpeedVisualizer_Init( HomeHOM13_SpeedVisualizer _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0003 ));
}

/* 'C' function for method : 'Home::HOM13_SpeedVisualizer.OnLongEnterKeyActivated()' */
void HomeHOM13_SpeedVisualizer_OnLongEnterKeyActivated( HomeHOM13_SpeedVisualizer _this )
{
  if ( 1 == _this->Super3.KeyHandler.RepetitionCount )
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( InfoINF01_MeterDisplaySettingMenu, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* Variants derived from the class : 'Home::HOM13_SpeedVisualizer' */
EW_DEFINE_CLASS_VARIANTS( HomeHOM13_SpeedVisualizer )
EW_END_OF_CLASS_VARIANTS( HomeHOM13_SpeedVisualizer )

/* Virtual Method Table (VMT) for the class : 'Home::HOM13_SpeedVisualizer' */
EW_DEFINE_CLASS( HomeHOM13_SpeedVisualizer, HomeBaseHome, Title, Title, Title, Title, 
                 _.VMT, _.VMT, "Home::HOM13_SpeedVisualizer" )
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
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
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  HomeBaseHome_OnShortEnterKeyActivated,
  HomeBaseHome_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  HomeHOM13_SpeedVisualizer_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  HomeBaseHome_ReturnToHome,
EW_END_OF_CLASS( HomeHOM13_SpeedVisualizer )

/* Initializer for the class 'Home::BaseHome' */
void HomeBaseHome__Init( HomeBaseHome _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeBaseHome );

  /* ... then construct all embedded objects */
  CoreTimer__Init( &_this->NaviConnectFailedTimer, &_this->_.XObject, 0 );
  PopPOP16_NaviLoadingUI__Init( &_this->LoadingAnimation, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeBaseHome );

  /* ... and initialize objects, variables, properties, etc. */
  CoreTimer_OnSetPeriod( &_this->NaviConnectFailedTimer, 3000 );
  CoreRectView__OnSetBounds( &_this->LoadingAnimation, _Const0004 );
  CoreGroup__OnSetVisible( &_this->LoadingAnimation, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LoadingAnimation ), 0 );
  _this->NaviConnectFailedTimer.OnTrigger = EwNewSlot( _this, HomeBaseHome_OnNaviConnectFailedSlot );
}

/* Re-Initializer for the class 'Home::BaseHome' */
void HomeBaseHome__ReInit( HomeBaseHome _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreTimer__ReInit( &_this->NaviConnectFailedTimer );
  PopPOP16_NaviLoadingUI__ReInit( &_this->LoadingAnimation );
}

/* Finalizer method for the class 'Home::BaseHome' */
void HomeBaseHome__Done( HomeBaseHome _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  CoreTimer__Done( &_this->NaviConnectFailedTimer );
  PopPOP16_NaviLoadingUI__Done( &_this->LoadingAnimation );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* 'C' function for method : 'Home::BaseHome.OnShortEnterKeyActivated()' */
void HomeBaseHome_OnShortEnterKeyActivated( HomeBaseHome _this )
{
  if ( !_this->NaviConnectFailedTimer.Enabled )
    CoreGroup_PresentDialog((CoreGroup)CoreView__GetRoot( _this ), ((CoreGroup)EwNewObject( 
    LauncherLNC_Main, 0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Home::BaseHome.OnShortHomeKeyActivated()' */
void HomeBaseHome_OnShortHomeKeyActivated( HomeBaseHome _this )
{
  if ( !_this->NaviConnectFailedTimer.Enabled )
  {
    XEnum NextHomeType = HomeBaseHome_GetNextHomeType( _this, _this->HomeType );
    ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

    if ( App != 0 )
      switch ( NextHomeType )
      {
        case EnumHomeTypeTACHO_VISUALIZER :
        case EnumHomeTypeSPEED_VISUALIZER :
        case EnumHomeTypeECO_VISUALIZER :
          ApplicationApplication_SlideInHome( App, NextHomeType );
        break;

        case EnumHomeTypeNAVI_DEFAULT_VIEW :
        case EnumHomeTypeNAVI_NEXT_TURN :
        case EnumHomeTypeNAVI_TURN_BY_TURN :
          ApplicationApplication_SwitchToHome( App, EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
          DeviceInterfaceNavigationDeviceClass )->CurrentHome );
        break;

        case EnumHomeTypeVEHICLE_INFO :
          ApplicationApplication_SlideInHome( App, NextHomeType );
        break;

        default :; 
      }
  }
}

/* 'C' function for method : 'Home::BaseHome.ReturnToHome()' */
void HomeBaseHome_ReturnToHome( HomeBaseHome _this )
{
  MenuBaseMenuView MenuDialog = EwCastObject( CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
    0 ), MenuBaseMenuView );

  if ( MenuDialog != 0 )
    CoreGroup_DismissDialog((CoreGroup)_this, ((CoreGroup)MenuDialog ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 0 );
}

/* Wrapper function for the virtual method : 'Home::BaseHome.ReturnToHome()' */
void HomeBaseHome__ReturnToHome( void* _this )
{
  ((HomeBaseHome)_this)->_.VMT->ReturnToHome((HomeBaseHome)_this );
}

/* 'C' function for method : 'Home::BaseHome.GetNextHomeType()' */
XEnum HomeBaseHome_GetNextHomeType( HomeBaseHome _this, XEnum aCurrentHomeType )
{
  XEnum NextHomeType;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NextHomeType = EnumHomeTypeTOTAL;

  switch ( aCurrentHomeType )
  {
    case EnumHomeTypeTACHO_VISUALIZER :
    case EnumHomeTypeECO_VISUALIZER :
    case EnumHomeTypeSPEED_VISUALIZER :
      if ( !DeviceInterfaceNavigationDeviceClass_GetNaviConnectStatus( EwGetAutoObject( 
          &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
        NextHomeType = EnumHomeTypeVEHICLE_INFO;
      else
        if ( !DeviceInterfaceNavigationDeviceClass_GetNaviAppInitSettingStatus( 
            EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
          NextHomeType = EnumHomeTypeVEHICLE_INFO;
        else
          NextHomeType = EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome;
    break;

    case EnumHomeTypeNAVI_DEFAULT_VIEW :
    case EnumHomeTypeNAVI_NEXT_TURN :
    case EnumHomeTypeNAVI_TURN_BY_TURN :
    {
      DeviceInterfaceNavigationDeviceClass_StopMapFrameRequest( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));
      NextHomeType = EnumHomeTypeVEHICLE_INFO;
    }
    break;

    case EnumHomeTypeVEHICLE_INFO :
      switch ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay )
      {
        case EnumMeterDisplayTACHOMETER :
          NextHomeType = EnumHomeTypeTACHO_VISUALIZER;
        break;

        case EnumMeterDisplayECHO_METER :
          NextHomeType = EnumHomeTypeECO_VISUALIZER;
        break;

        case EnumMeterDisplaySPEED_METER :
          NextHomeType = EnumHomeTypeSPEED_VISUALIZER;
        break;

        default :; 
      }
    break;

    default :; 
  }

  return NextHomeType;
}

/* 'C' function for method : 'Home::BaseHome.OnSetAccessNaviView()' */
void HomeBaseHome_OnSetAccessNaviView( HomeBaseHome _this, XBool value )
{
  _this->AccessNaviView = value;
  CoreTimer_OnSetEnabled( &_this->NaviConnectFailedTimer, value );
  CoreGroup__OnSetVisible( &_this->LoadingAnimation, value );
}

/* 'C' function for method : 'Home::BaseHome.OnNaviConnectFailedSlot()' */
void HomeBaseHome_OnNaviConnectFailedSlot( HomeBaseHome _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  HomeBaseHome_OnSetAccessNaviView( _this, 0 );
  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( PopPOP02_ConnectionError, 
  0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* Variants derived from the class : 'Home::BaseHome' */
EW_DEFINE_CLASS_VARIANTS( HomeBaseHome )
EW_END_OF_CLASS_VARIANTS( HomeBaseHome )

/* Virtual Method Table (VMT) for the class : 'Home::BaseHome' */
EW_DEFINE_CLASS( HomeBaseHome, ComponentsBaseMainBG, NaviConnectFailedTimer, NaviConnectFailedTimer, 
                 NaviConnectFailedTimer, NaviConnectFailedTimer, HomeType, HomeType, 
                 "Home::BaseHome" )
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
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
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  HomeBaseHome_OnShortEnterKeyActivated,
  HomeBaseHome_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  HomeBaseHome_ReturnToHome,
EW_END_OF_CLASS( HomeBaseHome )

/* Initializer for the class 'Home::HOM03_VehicleInfo' */
void HomeHOM03_VehicleInfo__Init( HomeHOM03_VehicleInfo _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  HomeBaseHome__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeHOM03_VehicleInfo );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->IconInfo, &_this->_.XObject, 0 );
  HomeVehicleInfoMenu__Init( &_this->VehicleInfoMenu, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeHOM03_VehicleInfo );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super1.HomeType = EnumHomeTypeVEHICLE_INFO;
  CoreRectView__OnSetBounds( &_this->IconInfo, _Const0005 );
  CoreRectView__OnSetBounds( &_this->VehicleInfoMenu, _Const0006 );
  CoreGroup__Add( _this, ((CoreView)&_this->IconInfo ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->VehicleInfoMenu ), 0 );
  ViewsImage_OnSetBitmap( &_this->IconInfo, EwLoadResource( &ResourceIconInfo, ResourcesBitmap ));

  /* Call the user defined constructor */
  HomeHOM03_VehicleInfo_Init( _this, aArg );
}

/* Re-Initializer for the class 'Home::HOM03_VehicleInfo' */
void HomeHOM03_VehicleInfo__ReInit( HomeHOM03_VehicleInfo _this )
{
  /* At first re-initialize the super class ... */
  HomeBaseHome__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->IconInfo );
  HomeVehicleInfoMenu__ReInit( &_this->VehicleInfoMenu );
}

/* Finalizer method for the class 'Home::HOM03_VehicleInfo' */
void HomeHOM03_VehicleInfo__Done( HomeHOM03_VehicleInfo _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->IconInfo );
  HomeVehicleInfoMenu__Done( &_this->VehicleInfoMenu );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void HomeHOM03_VehicleInfo_Init( HomeHOM03_VehicleInfo _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0007 ));
}

/* 'C' function for method : 'Home::HOM03_VehicleInfo.OnShortDownKeyActivated()' */
void HomeHOM03_VehicleInfo_OnShortDownKeyActivated( HomeHOM03_VehicleInfo _this )
{
  HomeVehicleInfoMenu_ScrollUp( &_this->VehicleInfoMenu );
}

/* 'C' function for method : 'Home::HOM03_VehicleInfo.OnShortUpKeyActivated()' */
void HomeHOM03_VehicleInfo_OnShortUpKeyActivated( HomeHOM03_VehicleInfo _this )
{
  HomeVehicleInfoMenu_ScrollDown( &_this->VehicleInfoMenu );
}

/* 'C' function for method : 'Home::HOM03_VehicleInfo.OnLongEnterKeyActivated()' */
void HomeHOM03_VehicleInfo_OnLongEnterKeyActivated( HomeHOM03_VehicleInfo _this )
{
  if ( 1 == _this->Super3.KeyHandler.RepetitionCount )
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsSET46_VehicleInfoReset, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* Variants derived from the class : 'Home::HOM03_VehicleInfo' */
EW_DEFINE_CLASS_VARIANTS( HomeHOM03_VehicleInfo )
EW_END_OF_CLASS_VARIANTS( HomeHOM03_VehicleInfo )

/* Virtual Method Table (VMT) for the class : 'Home::HOM03_VehicleInfo' */
EW_DEFINE_CLASS( HomeHOM03_VehicleInfo, HomeBaseHome, IconInfo, IconInfo, IconInfo, 
                 IconInfo, _.VMT, _.VMT, "Home::HOM03_VehicleInfo" )
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
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
  HomeHOM03_VehicleInfo_OnShortDownKeyActivated,
  HomeHOM03_VehicleInfo_OnShortUpKeyActivated,
  HomeBaseHome_OnShortEnterKeyActivated,
  HomeBaseHome_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  HomeHOM03_VehicleInfo_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  HomeBaseHome_ReturnToHome,
EW_END_OF_CLASS( HomeHOM03_VehicleInfo )

/* Initializer for the class 'Home::VehicleInfoMenu' */
void HomeVehicleInfoMenu__Init( HomeVehicleInfoMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeVehicleInfoMenu );

  /* ... then construct all embedded objects */
  CoreVerticalList__Init( &_this->VerticalList, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Divider1, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Divider2, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->UpArrowIcon, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->DownArrowIcon, &_this->_.XObject, 0 );
  EffectsInt32Effect__Init( &_this->RowScrollEffect, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeVehicleInfoMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0008 );
  CoreRectView__OnSetBounds( &_this->VerticalList, _Const0008 );
  CoreVerticalList_OnSetEndless( &_this->VerticalList, 1 );
  CoreVerticalList_OnSetItemHeight( &_this->VerticalList, 76 );
  CoreVerticalList_OnSetItemClass( &_this->VerticalList, EW_CLASS( HomeItemVehicleInfo ));
  CoreRectView__OnSetBounds( &_this->Divider1, _Const0009 );
  CoreRectView__OnSetBounds( &_this->Divider2, _Const000A );
  CoreRectView__OnSetBounds( &_this->UpArrowIcon, _Const000B );
  CoreRectView__OnSetBounds( &_this->DownArrowIcon, _Const000C );
  ViewsImage_OnSetFrameNumber( &_this->DownArrowIcon, 1 );
  EffectsEffect_OnSetExponent((EffectsEffect)&_this->RowScrollEffect, 4.190000f );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->RowScrollEffect, EffectsTimingExp_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->RowScrollEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->RowScrollEffect, 200 );
  EffectsEffect_OnSetInitialDelay((EffectsEffect)&_this->RowScrollEffect, 50 );
  CoreGroup__Add( _this, ((CoreView)&_this->VerticalList ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider1 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider2 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UpArrowIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DownArrowIcon ), 0 );
  _this->VerticalList.OnLoadItem = EwNewSlot( _this, HomeVehicleInfoMenu_OnLoadItem );
  ViewsImage_OnSetBitmap( &_this->Divider1, EwLoadResource( &ResourceInfoDivider, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Divider2, EwLoadResource( &ResourceInfoDivider, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->UpArrowIcon, EwLoadResource( &ResourcePageUpDown, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->DownArrowIcon, EwLoadResource( &ResourcePageUpDown, 
  ResourcesBitmap ));
  _this->RowScrollEffect.Outlet = EwNewRef( &_this->VerticalList, CoreVerticalList_OnGetScrollOffset, 
  CoreVerticalList_OnSetScrollOffset );
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, HomeVehicleInfoMenu_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );

  /* Call the user defined constructor */
  HomeVehicleInfoMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Home::VehicleInfoMenu' */
void HomeVehicleInfoMenu__ReInit( HomeVehicleInfoMenu _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreVerticalList__ReInit( &_this->VerticalList );
  ViewsImage__ReInit( &_this->Divider1 );
  ViewsImage__ReInit( &_this->Divider2 );
  ViewsImage__ReInit( &_this->UpArrowIcon );
  ViewsImage__ReInit( &_this->DownArrowIcon );
  EffectsInt32Effect__ReInit( &_this->RowScrollEffect );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'Home::VehicleInfoMenu' */
void HomeVehicleInfoMenu__Done( HomeVehicleInfoMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  CoreVerticalList__Done( &_this->VerticalList );
  ViewsImage__Done( &_this->Divider1 );
  ViewsImage__Done( &_this->Divider2 );
  ViewsImage__Done( &_this->UpArrowIcon );
  ViewsImage__Done( &_this->DownArrowIcon );
  EffectsInt32Effect__Done( &_this->RowScrollEffect );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void HomeVehicleInfoMenu_Init( HomeVehicleInfoMenu _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  HomeVehicleInfoMenu_InitItems( _this );
  HomeVehicleInfoMenu_SetDividers( _this );
  HomeVehicleInfoMenu_SetArrowIcons( _this );

  if ( _this->VerticalList.NoOfItems < 3 )
    CoreRectView__OnSetBounds( &_this->VerticalList, EwSetRectH( _this->VerticalList.Super2.Bounds, 
    _this->VerticalList.ItemHeight * _this->VerticalList.NoOfItems ));
  else
    CoreRectView__OnSetBounds( &_this->VerticalList, EwSetRectH( _this->VerticalList.Super2.Bounds, 
    EwGetRectH( _this->Super2.Bounds )));
}

/* This method is called by 'VerticalList' every time the list loads or updates 
   an item. */
void HomeVehicleInfoMenu_OnLoadItem( HomeVehicleInfoMenu _this, XObject sender )
{
  XInt32 ItemNo;
  HomeItemVehicleInfo MenuItem;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ItemNo = _this->VerticalList.Item;
  MenuItem = EwCastObject( _this->VerticalList.View, HomeItemVehicleInfo );

  if ( MenuItem != 0 )
  {
    ViewsText_OnSetString( &MenuItem->Title, HomeVehicleInfoMenu_LoadItemTitle( 
    _this, ItemNo ));
    ViewsImage_OnSetBitmap( &MenuItem->IconUnit, HomeVehicleInfoMenu_LoadItemUnitIconBmp( 
    _this, ItemNo ));

    if ( EnumVehicleInfoMenuItemTRIP_TIME == _this->Items[ EwCheckIndex( ItemNo, 
        14 )])
    {
      ViewsText_OnSetString( &MenuItem->HourText, HomeVehicleInfoMenu_LoadItemHour( 
      _this, ItemNo ));
      ViewsText_OnSetVisible( &MenuItem->HourText, 1 );
      ViewsText_OnSetString( &MenuItem->MinuteText, HomeVehicleInfoMenu_LoadItemMinute( 
      _this, ItemNo ));
      ViewsText_OnSetVisible( &MenuItem->MinuteText, 1 );
      ViewsImage_OnSetVisible( &MenuItem->HourIcon, 1 );
      ViewsText_OnSetVisible( &MenuItem->ValueText, 0 );
    }
    else
    {
      ViewsText_OnSetString( &MenuItem->ValueText, HomeVehicleInfoMenu_LoadItemValue( 
      _this, ItemNo ));
      ViewsText_OnSetVisible( &MenuItem->ValueText, 1 );
      HomeItemVehicleInfo_OnSetValueTextBlink( MenuItem, HomeVehicleInfoMenu_LoadItemValueBlink( 
      _this, ItemNo ));
      ViewsText_OnSetVisible( &MenuItem->HourText, 0 );
      ViewsText_OnSetVisible( &MenuItem->MinuteText, 0 );
      ViewsImage_OnSetVisible( &MenuItem->HourIcon, 0 );
    }
  }
}

/* 'C' function for method : 'Home::VehicleInfoMenu.InitItems()' */
void HomeVehicleInfoMenu_InitItems( HomeVehicleInfoMenu _this )
{
  XInt32 i;
  XInt32 NoOfItems = 0;
  XEnum MenuItem;

  for ( i = 0; i < 14; i++ )
  {
    MenuItem = (XEnum)i;

    switch ( MenuItem )
    {
      case EnumVehicleInfoMenuItemAVG_SPEED :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionAVG_SPEED ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemAVG_FUEL :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionAVG_FUEL ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemINST_FUEL :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionCURRENT_FUEL ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemRANGE :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionRANGE_DISTANCE ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemFUEL_CONSUMPTION :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionFUEL_CONSUMPTION ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemAIR_TEMPERATURE :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionAIR_TEMPERATURE ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemCOOLANT_TEMPERATURE :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionCOOLANT ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemBATTERY :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionBATTERY_VOLTAGE ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemTIRE_FRONT :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionTIRE_FRONT ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemTIRE_REAR :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionTIRE_REAR ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemTIRE_FRONT_RIGHT :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionTIRE_FRONT_RIGHT ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemTIRE_FRONT_LEFT :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionTIRE_FRONT_LEFT ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      default : 
      {
        _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
        NoOfItems++;
      }
    }
  }

  CoreVerticalList_OnSetNoOfItems( &_this->VerticalList, NoOfItems );
}

/* 'C' function for method : 'Home::VehicleInfoMenu.LoadItemTitle()' */
XString HomeVehicleInfoMenu_LoadItemTitle( HomeVehicleInfoMenu _this, XInt32 aItemNo )
{
  XString Title = 0;

  switch ( _this->Items[ EwCheckIndex( aItemNo, 14 )])
  {
    case EnumVehicleInfoMenuItemAVG_SPEED :
      Title = EwLoadString( &StringsHOM03_AVG_SPEED );
    break;

    case EnumVehicleInfoMenuItemAVG_FUEL :
      Title = EwLoadString( &StringsHOM03_AVG_FUEL );
    break;

    case EnumVehicleInfoMenuItemINST_FUEL :
      Title = EwLoadString( &StringsHOM03_INST_FUEL );
    break;

    case EnumVehicleInfoMenuItemTRIP_TIME :
      Title = EwLoadString( &StringsHOM03_TRIP_TIME );
    break;

    case EnumVehicleInfoMenuItemRANGE :
      Title = EwLoadString( &StringsHOM03_RANGE );
    break;

    case EnumVehicleInfoMenuItemFUEL_CONSUMPTION :
      Title = EwLoadString( &StringsHOM03_FUEL_CONSUMPTION );
    break;

    case EnumVehicleInfoMenuItemAIR_TEMPERATURE :
      Title = EwLoadString( &StringsHOM03_AIR );
    break;

    case EnumVehicleInfoMenuItemCOOLANT_TEMPERATURE :
      Title = EwLoadString( &StringsHOM03_COOLANT );
    break;

    case EnumVehicleInfoMenuItemBATTERY :
      Title = EwLoadString( &StringsHOM03_BATTERY );
    break;

    case EnumVehicleInfoMenuItemTIRE_FRONT_RIGHT :
      Title = EwLoadString( &StringsHOM03_FRONT_R );
    break;

    case EnumVehicleInfoMenuItemTIRE_FRONT_LEFT :
      Title = EwLoadString( &StringsHOM03_FRONT_L );
    break;

    case EnumVehicleInfoMenuItemTIRE_FRONT :
      Title = EwLoadString( &StringsHOM03_FRONT );
    break;

    case EnumVehicleInfoMenuItemTIRE_REAR :
      Title = EwLoadString( &StringsHOM03_REAR );
    break;

    case EnumVehicleInfoMenuItemCRUISE :
      Title = EwLoadString( &StringsHOM03_CRUISE );
    break;

    default :; 
  }

  return Title;
}

/* 'C' function for method : 'Home::VehicleInfoMenu.SetDividers()' */
void HomeVehicleInfoMenu_SetDividers( HomeVehicleInfoMenu _this )
{
  if ( 1 <= _this->VerticalList.NoOfItems )
    ViewsImage_OnSetVisible( &_this->Divider1, 1 );
  else
    ViewsImage_OnSetVisible( &_this->Divider1, 0 );

  if ( 2 <= _this->VerticalList.NoOfItems )
    ViewsImage_OnSetVisible( &_this->Divider2, 1 );
  else
    ViewsImage_OnSetVisible( &_this->Divider2, 0 );
}

/* 'C' function for method : 'Home::VehicleInfoMenu.LoadItemUnitIconBmp()' */
ResourcesBitmap HomeVehicleInfoMenu_LoadItemUnitIconBmp( HomeVehicleInfoMenu _this, 
  XInt32 aItemNo )
{
  ResourcesBitmap IconBitmap = 0;

  switch ( _this->Items[ EwCheckIndex( aItemNo, 14 )])
  {
    case EnumVehicleInfoMenuItemAVG_SPEED :
    case EnumVehicleInfoMenuItemRANGE :
    case EnumVehicleInfoMenuItemCRUISE :
      if ( EnumMileageSettingItemKM == DeviceInterfaceVehicleDeviceClass_OnGetMileageUnit( 
          EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
        IconBitmap = EwLoadResource( &ResourceIconUnitKM, ResourcesBitmap );
      else
        IconBitmap = EwLoadResource( &ResourceIconUnitMile, ResourcesBitmap );
    break;

    case EnumVehicleInfoMenuItemAVG_FUEL :
    case EnumVehicleInfoMenuItemINST_FUEL :
      switch ( DeviceInterfaceVehicleDeviceClass_OnGetFuelConsumptionUnit( EwGetAutoObject( 
              &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
      {
        case EnumMeterFuelConsumptionUnitKM_PER_LITER :
          IconBitmap = EwLoadResource( &ResourceIconUnitKM_L, ResourcesBitmap );
        break;

        case EnumMeterFuelConsumptionUnitL_PER_100KM :
          IconBitmap = EwLoadResource( &ResourceIconUnitL_100KM, ResourcesBitmap );
        break;

        case EnumMeterFuelConsumptionUnitMILE_PER_IMPERIAL_GAL :
        case EnumMeterFuelConsumptionUnitMILE_PER_US_GAL :
          IconBitmap = EwLoadResource( &ResourceIconUnitMPG, ResourcesBitmap );
        break;

        default :; 
      }
    break;

    case EnumVehicleInfoMenuItemTRIP_TIME :
      IconBitmap = EwLoadResource( &ResourceIconUnitMinute, ResourcesBitmap );
    break;

    case EnumVehicleInfoMenuItemFUEL_CONSUMPTION :
      switch ( DeviceInterfaceVehicleDeviceClass_OnGetFuelConsumptionUnit( EwGetAutoObject( 
              &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
      {
        case EnumMeterFuelConsumptionUnitKM_PER_LITER :
        case EnumMeterFuelConsumptionUnitL_PER_100KM :
          IconBitmap = EwLoadResource( &ResourceIconUnitL, ResourcesBitmap );
        break;

        case EnumMeterFuelConsumptionUnitMILE_PER_US_GAL :
        case EnumMeterFuelConsumptionUnitMILE_PER_IMPERIAL_GAL :
          IconBitmap = EwLoadResource( &ResourceIconUnitGal, ResourcesBitmap );
        break;

        default :; 
      }
    break;

    case EnumVehicleInfoMenuItemAIR_TEMPERATURE :
    case EnumVehicleInfoMenuItemCOOLANT_TEMPERATURE :
      if ( EnumTemperatureSettingItemTEMP_C == DeviceInterfaceVehicleDeviceClass_OnGetTemperatureUnit( 
          EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
        IconBitmap = EwLoadResource( &ResourceIconUnitDegC, ResourcesBitmap );
      else
        IconBitmap = EwLoadResource( &ResourceIconUnitDegF, ResourcesBitmap );
    break;

    case EnumVehicleInfoMenuItemBATTERY :
      IconBitmap = EwLoadResource( &ResourceIconUnitVolt, ResourcesBitmap );
    break;

    case EnumVehicleInfoMenuItemTIRE_FRONT :
    case EnumVehicleInfoMenuItemTIRE_REAR :
    case EnumVehicleInfoMenuItemTIRE_FRONT_RIGHT :
    case EnumVehicleInfoMenuItemTIRE_FRONT_LEFT :
      switch ( DeviceInterfaceVehicleDeviceClass_OnGetPressureUnit( EwGetAutoObject( 
              &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
      {
        case EnumPressureSettingItemKGF_PER_CM2 :
          IconBitmap = EwLoadResource( &ResourceIconUnitKGF_CM2, ResourcesBitmap );
        break;

        case EnumPressureSettingItemKPA :
          IconBitmap = EwLoadResource( &ResourceIconUnitKPA, ResourcesBitmap );
        break;

        case EnumPressureSettingItemPSI :
          IconBitmap = EwLoadResource( &ResourceIconUnitPSI, ResourcesBitmap );
        break;

        default :; 
      }
    break;

    default :; 
  }

  return IconBitmap;
}

/* 'C' function for method : 'Home::VehicleInfoMenu.LoadItemValue()' */
XString HomeVehicleInfoMenu_LoadItemValue( HomeVehicleInfoMenu _this, XInt32 aItemNo )
{
  XString ValueStr = 0;

  switch ( _this->Items[ EwCheckIndex( aItemNo, 14 )])
  {
    case EnumVehicleInfoMenuItemAVG_SPEED :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetAvgSpeedStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemAVG_FUEL :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetAvgFuelRateStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemINST_FUEL :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetInstantFuelRateStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemRANGE :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetRangeStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemFUEL_CONSUMPTION :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetFuelConStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemAIR_TEMPERATURE :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetAirTemperatureStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemCOOLANT_TEMPERATURE :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetCoolantTemperatureStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemBATTERY :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetBatteryStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemTIRE_FRONT :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetTireFrontPressureStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemTIRE_REAR :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetTireRearPressureStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemTIRE_FRONT_RIGHT :
      ValueStr = EwLoadString( &StringsGEN_THREE_HYPHENS );
    break;

    case EnumVehicleInfoMenuItemTIRE_FRONT_LEFT :
      ValueStr = EwLoadString( &StringsGEN_THREE_HYPHENS );
    break;

    case EnumVehicleInfoMenuItemCRUISE :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetCruiseSpeedStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    default :; 
  }

  return ValueStr;
}

/* 'C' function for method : 'Home::VehicleInfoMenu.ScrollUp()' */
void HomeVehicleInfoMenu_ScrollUp( HomeVehicleInfoMenu _this )
{
  if ( !_this->RowScrollEffect.Super1.Enabled && ( 1 < _this->VerticalList.NoOfItems ))
  {
    _this->RowScrollEffect.Value1 = _this->VerticalList.ScrollOffset;
    _this->RowScrollEffect.Value2 = _this->VerticalList.ScrollOffset - 76;
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->RowScrollEffect, 1 );
  }
}

/* 'C' function for method : 'Home::VehicleInfoMenu.ScrollDown()' */
void HomeVehicleInfoMenu_ScrollDown( HomeVehicleInfoMenu _this )
{
  if ( !_this->RowScrollEffect.Super1.Enabled && ( 1 < _this->VerticalList.NoOfItems ))
  {
    _this->RowScrollEffect.Value1 = _this->VerticalList.ScrollOffset;
    _this->RowScrollEffect.Value2 = _this->VerticalList.ScrollOffset + 76;
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->RowScrollEffect, 1 );
  }
}

/* 'C' function for method : 'Home::VehicleInfoMenu.SetArrowIcons()' */
void HomeVehicleInfoMenu_SetArrowIcons( HomeVehicleInfoMenu _this )
{
  if ( 1 < _this->VerticalList.NoOfItems )
  {
    ViewsImage_OnSetVisible( &_this->UpArrowIcon, 1 );
    ViewsImage_OnSetVisible( &_this->DownArrowIcon, 1 );
  }
  else
  {
    ViewsImage_OnSetVisible( &_this->UpArrowIcon, 0 );
    ViewsImage_OnSetVisible( &_this->DownArrowIcon, 0 );
  }
}

/* 'C' function for method : 'Home::VehicleInfoMenu.LoadItemHour()' */
XString HomeVehicleInfoMenu_LoadItemHour( HomeVehicleInfoMenu _this, XInt32 aItemNo )
{
  XString HourString = 0;

  if ( EnumVehicleInfoMenuItemTRIP_TIME == _this->Items[ EwCheckIndex( aItemNo, 
      14 )])
    HourString = DeviceInterfaceVehicleDeviceClass_OnGetTripTimeHourStr( EwGetAutoObject( 
    &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));

  return HourString;
}

/* 'C' function for method : 'Home::VehicleInfoMenu.LoadItemMinute()' */
XString HomeVehicleInfoMenu_LoadItemMinute( HomeVehicleInfoMenu _this, XInt32 aItemNo )
{
  XString MinuteString = 0;

  if ( EnumVehicleInfoMenuItemTRIP_TIME == _this->Items[ EwCheckIndex( aItemNo, 
      14 )])
    MinuteString = DeviceInterfaceVehicleDeviceClass_OnGetTripTimeMinuteStr( EwGetAutoObject( 
    &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));

  return MinuteString;
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void HomeVehicleInfoMenu_OnVehicleDataReceivedSlot( HomeVehicleInfoMenu _this, XObject 
  sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if ( VehicleData != 0 )
    switch ( VehicleData->RxType )
    {
      case EnumVehicleRxTypeTEMPERATURE_UNIT :
      {
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemAIR_TEMPERATURE );
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemCOOLANT_TEMPERATURE );
      }
      break;

      case EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT :
      {
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemAVG_FUEL );
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemINST_FUEL );
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemFUEL_CONSUMPTION );
      }
      break;

      case EnumVehicleRxTypeMILEAGE_UNIT :
      {
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemAVG_SPEED );
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemRANGE );
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemCRUISE );
      }
      break;

      case EnumVehicleRxTypePRESSURE_UNIT :
      case EnumVehicleRxTypeTIRE_SENSOR_EQUIPPED :
      {
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTIRE_FRONT );
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTIRE_REAR );
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTIRE_FRONT_LEFT );
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTIRE_FRONT_RIGHT );
      }
      break;

      case EnumVehicleRxTypeAVERAGE_SPEED :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemAVG_SPEED );
      break;

      case EnumVehicleRxTypeFUEL_RATE_AVERAGE :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemAVG_FUEL );
      break;

      case EnumVehicleRxTypeFUEL_RATE_INSTANT :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemINST_FUEL );
      break;

      case EnumVehicleRxTypeTRIP_TIME :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTRIP_TIME );
      break;

      case EnumVehicleRxTypeRANGE_DISTANCE :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemRANGE );
      break;

      case EnumVehicleRxTypeFUEL_CONSUMPTION :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemFUEL_CONSUMPTION );
      break;

      case EnumVehicleRxTypeAIR_TEMPERATURE :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemAIR_TEMPERATURE );
      break;

      case EnumVehicleRxTypeCOOLANT_TEMPERATURE :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemCOOLANT_TEMPERATURE );
      break;

      case EnumVehicleRxTypeBATTERY_VOLTAGE :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemBATTERY );
      break;

      case EnumVehicleRxTypeTIRE_FRONT :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTIRE_FRONT );
      break;

      case EnumVehicleRxTypeTIRE_REAR :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTIRE_REAR );
      break;

      case EnumVehicleRxTypeTIRE_FRONT_LEFT :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTIRE_FRONT_LEFT );
      break;

      case EnumVehicleRxTypeTIRE_FRONT_RIGHT :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTIRE_FRONT_RIGHT );
      break;

      case EnumVehicleRxTypeCRUISE_SPEED :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemCRUISE );
      break;

      default :; 
    }
}

/* 'C' function for method : 'Home::VehicleInfoMenu.ReloadItem()' */
void HomeVehicleInfoMenu_ReloadItem( HomeVehicleInfoMenu _this, XEnum aVehicleInfoItem )
{
  XInt32 i;

  for ( i = 0; i < _this->VerticalList.NoOfItems; i++ )
    if (( i < 14 ) && ( aVehicleInfoItem == _this->Items[ EwCheckIndex( i, 14 )]))
    {
      CoreVerticalList_InvalidateItems( &_this->VerticalList, i, i );
      break;
    }
}

/* 'C' function for method : 'Home::VehicleInfoMenu.LoadItemValueBlink()' */
XBool HomeVehicleInfoMenu_LoadItemValueBlink( HomeVehicleInfoMenu _this, XInt32 
  aItemNo )
{
  XBool blink = 0;

  switch ( _this->Items[ EwCheckIndex( aItemNo, 14 )])
  {
    case EnumVehicleInfoMenuItemCOOLANT_TEMPERATURE :
    {
      DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        EnumVehicleRxTypeCOOLANT_TEMPERATURE );

      if ( VehicleData->Valid && ( 128.750000f == VehicleData->DataFloat ))
        blink = 1;
    }
    break;

    default :; 
  }

  return blink;
}

/* Variants derived from the class : 'Home::VehicleInfoMenu' */
EW_DEFINE_CLASS_VARIANTS( HomeVehicleInfoMenu )
EW_END_OF_CLASS_VARIANTS( HomeVehicleInfoMenu )

/* Virtual Method Table (VMT) for the class : 'Home::VehicleInfoMenu' */
EW_DEFINE_CLASS( HomeVehicleInfoMenu, CoreGroup, VerticalList, VerticalList, VerticalList, 
                 VerticalList, Items, Items, "Home::VehicleInfoMenu" )
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
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
EW_END_OF_CLASS( HomeVehicleInfoMenu )

/* Initializer for the class 'Home::ItemVehicleInfo' */
void HomeItemVehicleInfo__Init( HomeItemVehicleInfo _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeItemVehicleInfo );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Title, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->IconUnit, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->ValueText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->MinuteText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->HourText, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->HourIcon, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->ValueTextBlinkTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeItemVehicleInfo );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const000D );
  _this->Super1.PassUpKey = 1;
  _this->Super1.PassDownKey = 1;
  CoreView_OnSetLayout((CoreView)&_this->Title, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->Title, _Const000E );
  ViewsText_OnSetEllipsis( &_this->Title, 1 );
  ViewsText_OnSetAlignment( &_this->Title, ViewsTextAlignmentAlignHorzLeft | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Title, 0 );
  ViewsText_OnSetColor( &_this->Title, _Const000F );
  CoreRectView__OnSetBounds( &_this->IconUnit, _Const0010 );
  CoreView_OnSetLayout((CoreView)&_this->ValueText, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->ValueText, _Const0011 );
  ViewsText_OnSetEllipsis( &_this->ValueText, 1 );
  ViewsText_OnSetAlignment( &_this->ValueText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ValueText, 0 );
  ViewsText_OnSetColor( &_this->ValueText, _Const000F );
  CoreView_OnSetLayout((CoreView)&_this->MinuteText, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->MinuteText, _Const0012 );
  ViewsText_OnSetEllipsis( &_this->MinuteText, 1 );
  ViewsText_OnSetAlignment( &_this->MinuteText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->MinuteText, 0 );
  ViewsText_OnSetColor( &_this->MinuteText, _Const000F );
  CoreView_OnSetLayout((CoreView)&_this->HourText, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->HourText, _Const0013 );
  ViewsText_OnSetEllipsis( &_this->HourText, 1 );
  ViewsText_OnSetAlignment( &_this->HourText, ViewsTextAlignmentAlignHorzRight | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->HourText, 0 );
  ViewsText_OnSetColor( &_this->HourText, _Const000F );
  CoreRectView__OnSetBounds( &_this->HourIcon, _Const0014 );
  ViewsImage_OnSetVisible( &_this->HourIcon, 0 );
  CoreTimer_OnSetPeriod( &_this->ValueTextBlinkTimer, 500 );
  CoreGroup__Add( _this, ((CoreView)&_this->Title ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->IconUnit ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ValueText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MinuteText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->HourText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->HourIcon ), 0 );
  ViewsText_OnSetFont( &_this->Title, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->IconUnit, EwLoadResource( &ResourceIconUnitKM_L, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->ValueText, EwLoadResource( &FontsNotoSansMedium40pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->MinuteText, EwLoadResource( &FontsNotoSansMedium40pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->HourText, EwLoadResource( &FontsNotoSansMedium40pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->HourIcon, EwLoadResource( &ResourceIconUnitHour, 
  ResourcesBitmap ));
  _this->ValueTextBlinkTimer.OnTrigger = EwNewSlot( _this, HomeItemVehicleInfo_OnValueTextBlinkText );
}

/* Re-Initializer for the class 'Home::ItemVehicleInfo' */
void HomeItemVehicleInfo__ReInit( HomeItemVehicleInfo _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Title );
  ViewsImage__ReInit( &_this->IconUnit );
  ViewsText__ReInit( &_this->ValueText );
  ViewsText__ReInit( &_this->MinuteText );
  ViewsText__ReInit( &_this->HourText );
  ViewsImage__ReInit( &_this->HourIcon );
  CoreTimer__ReInit( &_this->ValueTextBlinkTimer );
}

/* Finalizer method for the class 'Home::ItemVehicleInfo' */
void HomeItemVehicleInfo__Done( HomeItemVehicleInfo _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Title );
  ViewsImage__Done( &_this->IconUnit );
  ViewsText__Done( &_this->ValueText );
  ViewsText__Done( &_this->MinuteText );
  ViewsText__Done( &_this->HourText );
  ViewsImage__Done( &_this->HourIcon );
  CoreTimer__Done( &_this->ValueTextBlinkTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_.Super );
}

/* 'C' function for method : 'Home::ItemVehicleInfo.OnValueTextBlinkText()' */
void HomeItemVehicleInfo_OnValueTextBlinkText( HomeItemVehicleInfo _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsText_OnSetVisible( &_this->ValueText, (XBool)!ViewsText_OnGetVisible( &_this->ValueText ));
}

/* 'C' function for method : 'Home::ItemVehicleInfo.OnSetValueTextBlink()' */
void HomeItemVehicleInfo_OnSetValueTextBlink( HomeItemVehicleInfo _this, XBool value )
{
  if ( _this->ValueTextBlink != value )
  {
    _this->ValueTextBlink = value;
    CoreTimer_OnSetEnabled( &_this->ValueTextBlinkTimer, value );
  }
}

/* Variants derived from the class : 'Home::ItemVehicleInfo' */
EW_DEFINE_CLASS_VARIANTS( HomeItemVehicleInfo )
EW_END_OF_CLASS_VARIANTS( HomeItemVehicleInfo )

/* Virtual Method Table (VMT) for the class : 'Home::ItemVehicleInfo' */
EW_DEFINE_CLASS( HomeItemVehicleInfo, ComponentsBaseComponent, Title, Title, Title, 
                 Title, ValueTextBlink, ValueTextBlink, "Home::ItemVehicleInfo" )
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
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
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( HomeItemVehicleInfo )

/* Embedded Wizard */
