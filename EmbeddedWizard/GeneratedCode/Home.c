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
#include "_ApplicationApplication.h"
#include "_CoreGroup.h"
#include "_CoreKeyPressHandler.h"
#include "_CoreRoot.h"
#include "_CoreView.h"
#include "_DeviceInterfaceNavigationDeviceClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_HomeBaseHome.h"
#include "_HomeHOM03_VehicleInfo.h"
#include "_HomeHOM11_TachoVisualizer.h"
#include "_HomeHOM12_EcoVisualizer.h"
#include "_HomeHOM13_SpeedVisualizer.h"
#include "_InfoINF01_MeterDisplaySettingMenu.h"
#include "_LauncherLNC_Main.h"
#include "_MenuBaseMenuView.h"
#include "_ResourcesFont.h"
#include "_ViewsText.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Fonts.h"
#include "Home.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000082, /* ratio 67.69 % */
  0xB8001B00, 0x00092452, 0x00D20037, 0x040003A0, 0x9E002400, 0x20026800, 0x18004546,
  0x88341205, 0x87432150, 0xB4522510, 0x00230328, 0x260F058D, 0x61F0D85C, 0x671789C4,
  0xB0305C98, 0x229716C8, 0x2000C25B, 0x94498BB3, 0xC47E571C, 0x4CA77309, 0x02032693,
  0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 72, 113 }, { 403, 156 }};
static const XStringRes _Const0001 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0002 = { _StringsDefault0, 0x000F };
static const XStringRes _Const0003 = { _StringsDefault0, 0x001C };
static const XStringRes _Const0004 = { _StringsDefault0, 0x0029 };
static const XStringRes _Const0005 = { _StringsDefault0, 0x0034 };

/* Initializer for the class 'Home::HOM11_TachoVisualizer' */
void HomeHOM11_TachoVisualizer__Init( HomeHOM11_TachoVisualizer _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  HomeBaseHome__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( HomeHOM11_TachoVisualizer );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Title, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( HomeHOM11_TachoVisualizer );

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
  HomeBaseHome__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Title );
}

/* Finalizer method for the class 'Home::HOM11_TachoVisualizer' */
void HomeHOM11_TachoVisualizer__Done( HomeHOM11_TachoVisualizer _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Title );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_Super );
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
  {
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( InfoINF01_MeterDisplaySettingMenu, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* Variants derived from the class : 'Home::HOM11_TachoVisualizer' */
EW_DEFINE_CLASS_VARIANTS( HomeHOM11_TachoVisualizer )
EW_END_OF_CLASS_VARIANTS( HomeHOM11_TachoVisualizer )

/* Virtual Method Table (VMT) for the class : 'Home::HOM11_TachoVisualizer' */
EW_DEFINE_CLASS( HomeHOM11_TachoVisualizer, HomeBaseHome, Title, Title, Title, Title, 
                 _None, _None, "Home::HOM11_TachoVisualizer" )
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
EW_END_OF_CLASS( HomeHOM11_TachoVisualizer )

/* Initializer for the class 'Home::HOM12_EcoVisualizer' */
void HomeHOM12_EcoVisualizer__Init( HomeHOM12_EcoVisualizer _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  HomeBaseHome__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( HomeHOM12_EcoVisualizer );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Title, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( HomeHOM12_EcoVisualizer );

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
  HomeBaseHome__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Title );
}

/* Finalizer method for the class 'Home::HOM12_EcoVisualizer' */
void HomeHOM12_EcoVisualizer__Done( HomeHOM12_EcoVisualizer _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Title );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_Super );
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
  {
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( InfoINF01_MeterDisplaySettingMenu, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* Variants derived from the class : 'Home::HOM12_EcoVisualizer' */
EW_DEFINE_CLASS_VARIANTS( HomeHOM12_EcoVisualizer )
EW_END_OF_CLASS_VARIANTS( HomeHOM12_EcoVisualizer )

/* Virtual Method Table (VMT) for the class : 'Home::HOM12_EcoVisualizer' */
EW_DEFINE_CLASS( HomeHOM12_EcoVisualizer, HomeBaseHome, Title, Title, Title, Title, 
                 _None, _None, "Home::HOM12_EcoVisualizer" )
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
EW_END_OF_CLASS( HomeHOM12_EcoVisualizer )

/* Initializer for the class 'Home::HOM13_SpeedVisualizer' */
void HomeHOM13_SpeedVisualizer__Init( HomeHOM13_SpeedVisualizer _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  HomeBaseHome__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( HomeHOM13_SpeedVisualizer );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Title, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( HomeHOM13_SpeedVisualizer );

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
  HomeBaseHome__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Title );
}

/* Finalizer method for the class 'Home::HOM13_SpeedVisualizer' */
void HomeHOM13_SpeedVisualizer__Done( HomeHOM13_SpeedVisualizer _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Title );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_Super );
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
  {
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( InfoINF01_MeterDisplaySettingMenu, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* Variants derived from the class : 'Home::HOM13_SpeedVisualizer' */
EW_DEFINE_CLASS_VARIANTS( HomeHOM13_SpeedVisualizer )
EW_END_OF_CLASS_VARIANTS( HomeHOM13_SpeedVisualizer )

/* Virtual Method Table (VMT) for the class : 'Home::HOM13_SpeedVisualizer' */
EW_DEFINE_CLASS( HomeHOM13_SpeedVisualizer, HomeBaseHome, Title, Title, Title, Title, 
                 _None, _None, "Home::HOM13_SpeedVisualizer" )
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
EW_END_OF_CLASS( HomeHOM13_SpeedVisualizer )

/* Initializer for the class 'Home::BaseHome' */
void HomeBaseHome__Init( HomeBaseHome _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( HomeBaseHome );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( HomeBaseHome );
}

/* Re-Initializer for the class 'Home::BaseHome' */
void HomeBaseHome__ReInit( HomeBaseHome _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Home::BaseHome' */
void HomeBaseHome__Done( HomeBaseHome _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* 'C' function for method : 'Home::BaseHome.OnShortEnterKeyActivated()' */
void HomeBaseHome_OnShortEnterKeyActivated( HomeBaseHome _this )
{
  CoreGroup_PresentDialog((CoreGroup)CoreView__GetRoot( _this ), ((CoreGroup)EwNewObject( 
  LauncherLNC_Main, 0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Home::BaseHome.OnShortHomeKeyActivated()' */
void HomeBaseHome_OnShortHomeKeyActivated( HomeBaseHome _this )
{
  XEnum NextHomeType = HomeBaseHome_GetNextHomeType( _this, _this->HomeType );
  ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
  {
    switch ( NextHomeType )
    {
      case EnumHomeTypeTACHO_VISUALIZER :
      case EnumHomeTypeSPEED_VISUALIZER :
      case EnumHomeTypeECO_VISUALIZER :
      {
        ApplicationApplication_SlideInHome( App, NextHomeType );
      }
      break;

      case EnumHomeTypeNAVI_DEFAULT_VIEW :
      case EnumHomeTypeNAVI_NEXT_TURN :
      case EnumHomeTypeNAVI_TURN_BY_TURN :
      {
        ApplicationApplication_SwitchToHome( App, NextHomeType );
      }
      break;

      case EnumHomeTypeVEHICLE_INFO :
        ApplicationApplication_SlideInHome( App, NextHomeType );
      break;

      default : 
        ;
    }
  }
}

/* 'C' function for method : 'Home::BaseHome.ReturnToHome()' */
void HomeBaseHome_ReturnToHome( HomeBaseHome _this )
{
  MenuBaseMenuView MenuDialog = EwCastObject( CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
    0 ), MenuBaseMenuView );

  if ( MenuDialog != 0 )
  {
    CoreGroup__DismissDialog( _this, ((CoreGroup)MenuDialog ), 0, 0, 0, EwNullSlot, 
    EwNullSlot, 0 );
  }
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
    {
      NextHomeType = EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome;
    }
    break;

    case EnumHomeTypeNAVI_DEFAULT_VIEW :
    case EnumHomeTypeNAVI_NEXT_TURN :
    case EnumHomeTypeNAVI_TURN_BY_TURN :
      NextHomeType = EnumHomeTypeVEHICLE_INFO;
    break;

    case EnumHomeTypeVEHICLE_INFO :
    {
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

        default : 
          ;
      }
    }
    break;

    default : 
      ;
  }

  return NextHomeType;
}

/* Variants derived from the class : 'Home::BaseHome' */
EW_DEFINE_CLASS_VARIANTS( HomeBaseHome )
EW_END_OF_CLASS_VARIANTS( HomeBaseHome )

/* Virtual Method Table (VMT) for the class : 'Home::BaseHome' */
EW_DEFINE_CLASS( HomeBaseHome, ComponentsBaseMainBG, _None, _None, _None, _None, 
                 _None, _None, "Home::BaseHome" )
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
EW_END_OF_CLASS( HomeBaseHome )

/* Initializer for the class 'Home::HOM03_VehicleInfo' */
void HomeHOM03_VehicleInfo__Init( HomeHOM03_VehicleInfo _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  HomeBaseHome__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( HomeHOM03_VehicleInfo );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Title, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( HomeHOM03_VehicleInfo );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super1.HomeType = EnumHomeTypeVEHICLE_INFO;
  CoreRectView__OnSetBounds( &_this->Title, _Const0000 );
  ViewsText_OnSetAlignment( &_this->Title, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Title, EwLoadString( &_Const0004 ));
  CoreGroup__Add( _this, ((CoreView)&_this->Title ), 0 );
  ViewsText_OnSetFont( &_this->Title, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));

  /* Call the user defined constructor */
  HomeHOM03_VehicleInfo_Init( _this, aArg );
}

/* Re-Initializer for the class 'Home::HOM03_VehicleInfo' */
void HomeHOM03_VehicleInfo__ReInit( HomeHOM03_VehicleInfo _this )
{
  /* At first re-initialize the super class ... */
  HomeBaseHome__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Title );
}

/* Finalizer method for the class 'Home::HOM03_VehicleInfo' */
void HomeHOM03_VehicleInfo__Done( HomeHOM03_VehicleInfo _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Title );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void HomeHOM03_VehicleInfo_Init( HomeHOM03_VehicleInfo _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0005 ));
}

/* Variants derived from the class : 'Home::HOM03_VehicleInfo' */
EW_DEFINE_CLASS_VARIANTS( HomeHOM03_VehicleInfo )
EW_END_OF_CLASS_VARIANTS( HomeHOM03_VehicleInfo )

/* Virtual Method Table (VMT) for the class : 'Home::HOM03_VehicleInfo' */
EW_DEFINE_CLASS( HomeHOM03_VehicleInfo, HomeBaseHome, Title, Title, Title, Title, 
                 _None, _None, "Home::HOM03_VehicleInfo" )
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
EW_END_OF_CLASS( HomeHOM03_VehicleInfo )

/* Embedded Wizard */
