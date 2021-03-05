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
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_HomeBaseHome.h"
#include "_InfoINF01_MeterDisplaySettingMenu.h"
#include "_MenuItemCheckMark.h"
#include "_MenuVerticalMenu.h"
#include "Core.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Info.h"
#include "Strings.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x0000001E, /* ratio 120.00 % */
  0xB8001B00, 0x00092452, 0x00D20037, 0x040003A0, 0x004E8300, 0x03000118, 0x18000C40,
  0x08080233, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XStringRes _Const0000 = { _StringsDefault0, 0x0002 };

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

/* Initializer for the class 'Info::INF01_MeterDisplaySettingMenu' */
void InfoINF01_MeterDisplaySettingMenu__Init( InfoINF01_MeterDisplaySettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( InfoINF01_MeterDisplaySettingMenu );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( InfoINF01_MeterDisplaySettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 3 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsINF01_TACHO_VISUALIZER ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsINF01_ECHO_VISUALIZER ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &StringsINF01_SPEED_VISUALIZER ));

  /* Call the user defined constructor */
  InfoINF01_MeterDisplaySettingMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Info::INF01_MeterDisplaySettingMenu' */
void InfoINF01_MeterDisplaySettingMenu__ReInit( InfoINF01_MeterDisplaySettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Info::INF01_MeterDisplaySettingMenu' */
void InfoINF01_MeterDisplaySettingMenu__Done( InfoINF01_MeterDisplaySettingMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void InfoINF01_MeterDisplaySettingMenu_Init( InfoINF01_MeterDisplaySettingMenu _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0000 ));
}

/* The method UpdateViewState() is invoked automatically after the state of the 
   component has been changed. This method can be overridden and filled with logic 
   to ensure the visual aspect of the component does reflect its current state. 
   For example, the 'enabled' state of the component can affect its colors (disabled 
   components may appear pale). In this case the logic of the method should modify 
   the respective color properties accordingly to the current 'enabled' state. 
   The current state of the component is passed as a set in the parameter aState. 
   It reflects the very basic component state like its visibility or the ability 
   to react to user inputs. Beside this common state, the method can also involve 
   any other variables used in the component as long as they reflect its current 
   state. For example, the toggle switch component can take in account its toggle 
   state 'on' or 'off' and change accordingly the location of the slider, etc.
   Usually, this method will be invoked automatically by the framework. Optionally 
   you can request its invocation by using the method @InvalidateViewState(). */
void InfoINF01_MeterDisplaySettingMenu_UpdateViewState( InfoINF01_MeterDisplaySettingMenu _this, 
  XSet aState )
{
  CoreGroup_UpdateViewState((CoreGroup)_this, aState );

  if ((( aState & CoreViewStateVisible ) == CoreViewStateVisible ))
  {
    HomeBaseHome HomeDialog = EwCastObject( _this->Super6.Owner, HomeBaseHome );

    if ( HomeDialog != 0 )
    {
      _this->Super2.SlideOutEffectEnabled = 0;
    }
  }
}

/* 'C' function for method : 'Info::INF01_MeterDisplaySettingMenu.LoadItemClass()' */
XClass InfoINF01_MeterDisplaySettingMenu_LoadItemClass( InfoINF01_MeterDisplaySettingMenu _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( !!aItemNo )
    ;

  return EW_CLASS( MenuItemCheckMark );
}

/* 'C' function for method : 'Info::INF01_MeterDisplaySettingMenu.LoadItemTitle()' */
XString InfoINF01_MeterDisplaySettingMenu_LoadItemTitle( InfoINF01_MeterDisplaySettingMenu _this, 
  XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < 3 )
  {
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 3 )];
  }

  return title;
}

/* 'C' function for method : 'Info::INF01_MeterDisplaySettingMenu.OnItemActivate()' */
void InfoINF01_MeterDisplaySettingMenu_OnItemActivate( InfoINF01_MeterDisplaySettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  XEnum HomeType;

  if ( aMenuItem == 0 )
    ;

  HomeType = EnumHomeTypeTOTAL;

  switch ( aItemNo )
  {
    case 0 :
    {
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay 
      = EnumMeterDisplayTACHOMETER;
      HomeType = EnumHomeTypeTACHO_VISUALIZER;
    }
    break;

    case 1 :
    {
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay 
      = EnumMeterDisplayECHO_METER;
      HomeType = EnumHomeTypeECO_VISUALIZER;
    }
    break;

    case 2 :
    {
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay 
      = EnumMeterDisplaySPEED_METER;
      HomeType = EnumHomeTypeSPEED_VISUALIZER;
    }
    break;

    default : 
      ;
  }

  if ( HomeType != EnumHomeTypeTOTAL )
  {
    ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

    if ( App != 0 )
    {
      ApplicationApplication_SwitchToHome( App, HomeType );
    }
  }
}

/* 'C' function for method : 'Info::INF01_MeterDisplaySettingMenu.LoadItemChecked()' */
XBool InfoINF01_MeterDisplaySettingMenu_LoadItemChecked( InfoINF01_MeterDisplaySettingMenu _this, 
  XInt32 aItemNo )
{
  XBool checked;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  checked = 0;

  switch ( aItemNo )
  {
    case 0 :
    {
      if ( EnumMeterDisplayTACHOMETER == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay )
      {
        checked = 1;
      }
    }
    break;

    case 1 :
    {
      if ( EnumMeterDisplayECHO_METER == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay )
      {
        checked = 1;
      }
    }
    break;

    case 2 :
    {
      if ( EnumMeterDisplaySPEED_METER == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay )
      {
        checked = 1;
      }
    }
    break;

    default : 
      ;
  }

  return checked;
}

/* Variants derived from the class : 'Info::INF01_MeterDisplaySettingMenu' */
EW_DEFINE_CLASS_VARIANTS( InfoINF01_MeterDisplaySettingMenu )
EW_END_OF_CLASS_VARIANTS( InfoINF01_MeterDisplaySettingMenu )

/* Virtual Method Table (VMT) for the class : 'Info::INF01_MeterDisplaySettingMenu' */
EW_DEFINE_CLASS( InfoINF01_MeterDisplaySettingMenu, MenuBaseMenuView, ItemTitleArray, 
                 ItemTitleArray, ItemTitleArray, ItemTitleArray, ItemTitleArray, 
                 _None, "Info::INF01_MeterDisplaySettingMenu" )
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
  InfoINF01_MeterDisplaySettingMenu_UpdateViewState,
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
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  InfoINF01_MeterDisplaySettingMenu_LoadItemClass,
  InfoINF01_MeterDisplaySettingMenu_LoadItemTitle,
  InfoINF01_MeterDisplaySettingMenu_OnItemActivate,
  InfoINF01_MeterDisplaySettingMenu_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemUnitValue,
EW_END_OF_CLASS( InfoINF01_MeterDisplaySettingMenu )

/* Embedded Wizard */