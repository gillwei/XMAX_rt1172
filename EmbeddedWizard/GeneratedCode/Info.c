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
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_DeviceInterfaceVehicleDataClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_HomeBaseHome.h"
#include "_InfoINF01_MeterDisplaySettingMenu.h"
#include "_InfoINF26_ODO_TRIP_SettingMenu.h"
#include "_MenuItemCheckMark.h"
#include "_MenuItemValueUnitCheckmark.h"
#include "_MenuVerticalMenu.h"
#include "_PopPOP04_Reset.h"
#include "Core.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Info.h"
#include "Strings.h"

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault0[] =
{
  0x00000038, /* ratio 92.86 % */
  0xB8001B00, 0x00092452, 0x00D20037, 0x040003A0, 0x004E8300, 0x03000118, 0x18000C40,
  0x88341205, 0x87432150, 0x90022510, 0xC606C001, 0x02031893, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XStringRes _Const0000 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0001 = { _StringsDefault0, 0x000F };

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
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( InfoINF01_MeterDisplaySettingMenu );

  /* ... then construct all embedded objects */
  CoreTimer__Init( &_this->CheckMarkUpdateTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( InfoINF01_MeterDisplaySettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super2.SlideOutEffectEnabled = 1;
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 3 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsINF01_TACHO_VISUALIZER ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsINF01_ECHO_VISUALIZER ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &StringsINF01_SPEED_VISUALIZER ));
  CoreTimer_OnSetPeriod( &_this->CheckMarkUpdateTimer, 0 );
  CoreTimer_OnSetBegin( &_this->CheckMarkUpdateTimer, 450 );
  _this->CheckMarkUpdateTimer.OnTrigger = EwNewSlot( _this, InfoINF01_MeterDisplaySettingMenu_OnCheckMarkUpdateSlot );

  /* Call the user defined constructor */
  InfoINF01_MeterDisplaySettingMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Info::INF01_MeterDisplaySettingMenu' */
void InfoINF01_MeterDisplaySettingMenu__ReInit( InfoINF01_MeterDisplaySettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreTimer__ReInit( &_this->CheckMarkUpdateTimer );
}

/* Finalizer method for the class 'Info::INF01_MeterDisplaySettingMenu' */
void InfoINF01_MeterDisplaySettingMenu__Done( InfoINF01_MeterDisplaySettingMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CoreTimer__Done( &_this->CheckMarkUpdateTimer );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
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
      _this->Super2.SlideOutEffectEnabled = 0;
  }
}

/* 'C' function for method : 'Info::INF01_MeterDisplaySettingMenu.LoadItemClass()' */
XClass InfoINF01_MeterDisplaySettingMenu_LoadItemClass( InfoINF01_MeterDisplaySettingMenu _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemCheckMark );
}

/* 'C' function for method : 'Info::INF01_MeterDisplaySettingMenu.LoadItemTitle()' */
XString InfoINF01_MeterDisplaySettingMenu_LoadItemTitle( InfoINF01_MeterDisplaySettingMenu _this, 
  XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < 3 )
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 3 )];

  return title;
}

/* 'C' function for method : 'Info::INF01_MeterDisplaySettingMenu.OnItemActivate()' */
void InfoINF01_MeterDisplaySettingMenu_OnItemActivate( InfoINF01_MeterDisplaySettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  _this->SelectedHomeType = EnumHomeTypeTOTAL;

  switch ( aItemNo )
  {
    case 0 :
    {
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay 
      = EnumMeterDisplayTACHOMETER;
      _this->SelectedHomeType = EnumHomeTypeTACHO_VISUALIZER;
    }
    break;

    case 1 :
    {
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay 
      = EnumMeterDisplayECHO_METER;
      _this->SelectedHomeType = EnumHomeTypeECO_VISUALIZER;
    }
    break;

    case 2 :
    {
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay 
      = EnumMeterDisplaySPEED_METER;
      _this->SelectedHomeType = EnumHomeTypeSPEED_VISUALIZER;
    }
    break;

    default :; 
  }

  MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, _this->Super1.Menu.NoOfItems 
  - 1 );
  CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
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
      if ( EnumMeterDisplayTACHOMETER == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay )
        checked = 1;
    break;

    case 1 :
      if ( EnumMeterDisplayECHO_METER == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay )
        checked = 1;
    break;

    case 2 :
      if ( EnumMeterDisplaySPEED_METER == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay )
        checked = 1;
    break;

    default :; 
  }

  return checked;
}

/* 'C' function for method : 'Info::INF01_MeterDisplaySettingMenu.OnCheckMarkUpdateSlot()' */
void InfoINF01_MeterDisplaySettingMenu_OnCheckMarkUpdateSlot( InfoINF01_MeterDisplaySettingMenu _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->SelectedHomeType != EnumHomeTypeTOTAL )
  {
    ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

    if ( App != 0 )
      ApplicationApplication_SwitchToHome( App, _this->SelectedHomeType );
  }
}

/* Variants derived from the class : 'Info::INF01_MeterDisplaySettingMenu' */
EW_DEFINE_CLASS_VARIANTS( InfoINF01_MeterDisplaySettingMenu )
EW_END_OF_CLASS_VARIANTS( InfoINF01_MeterDisplaySettingMenu )

/* Virtual Method Table (VMT) for the class : 'Info::INF01_MeterDisplaySettingMenu' */
EW_DEFINE_CLASS( InfoINF01_MeterDisplaySettingMenu, MenuBaseMenuView, CheckMarkUpdateTimer, 
                 CheckMarkUpdateTimer, CheckMarkUpdateTimer, CheckMarkUpdateTimer, 
                 ItemTitleArray, SelectedHomeType, "Info::INF01_MeterDisplaySettingMenu" )
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
  InfoINF01_MeterDisplaySettingMenu_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  MenuBaseMenuView_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  InfoINF01_MeterDisplaySettingMenu_LoadItemClass,
  InfoINF01_MeterDisplaySettingMenu_LoadItemTitle,
  InfoINF01_MeterDisplaySettingMenu_OnItemActivate,
  InfoINF01_MeterDisplaySettingMenu_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemBaseValue,
  MenuBaseMenuView_LoadItemMessage,
  MenuBaseMenuView_LoadItemReceivedTime,
  MenuBaseMenuView_LoadItemCategory,
  MenuBaseMenuView_LoadItemUid,
  MenuBaseMenuView_LoadItemToggle,
  MenuBaseMenuView_LoadItemUnit,
  MenuBaseMenuView_LoadItemValue,
  MenuBaseMenuView_OnItemLongEnterKeyActivate,
  MenuBaseMenuView_LoadItemHour,
  MenuBaseMenuView_LoadItemMinute,
  MenuBaseMenuView_LoadPoiListItemValue,
  MenuBaseMenuView_LoadPoiListItemUnit,
EW_END_OF_CLASS( InfoINF01_MeterDisplaySettingMenu )

/* Initializer for the class 'Info::INF26_ODO_TRIP_SettingMenu' */
void InfoINF26_ODO_TRIP_SettingMenu__Init( InfoINF26_ODO_TRIP_SettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( InfoINF26_ODO_TRIP_SettingMenu );

  /* ... then construct all embedded objects */
  CoreTimer__Init( &_this->CheckMarkUpdateTimer, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( InfoINF26_ODO_TRIP_SettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  CoreTimer_OnSetPeriod( &_this->CheckMarkUpdateTimer, 0 );
  CoreTimer_OnSetBegin( &_this->CheckMarkUpdateTimer, 450 );
  _this->SelectedItem = EnumMeterInfoTOTAL;
  _this->AllSettings[ 0 ] = EnumMeterInfoODO;
  _this->AllSettings[ 1 ] = EnumMeterInfoTRIP1;
  _this->AllSettings[ 2 ] = EnumMeterInfoTRIP2;
  _this->AllSettings[ 3 ] = EnumMeterInfoTRIP_F;
  _this->CheckMarkUpdateTimer.OnTrigger = EwNewSlot( _this, InfoINF26_ODO_TRIP_SettingMenu_OnCheckMarkUpdateSlot );
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, InfoINF26_ODO_TRIP_SettingMenu_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );

  /* Call the user defined constructor */
  InfoINF26_ODO_TRIP_SettingMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Info::INF26_ODO_TRIP_SettingMenu' */
void InfoINF26_ODO_TRIP_SettingMenu__ReInit( InfoINF26_ODO_TRIP_SettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreTimer__ReInit( &_this->CheckMarkUpdateTimer );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'Info::INF26_ODO_TRIP_SettingMenu' */
void InfoINF26_ODO_TRIP_SettingMenu__Done( InfoINF26_ODO_TRIP_SettingMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CoreTimer__Done( &_this->CheckMarkUpdateTimer );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void InfoINF26_ODO_TRIP_SettingMenu_Init( InfoINF26_ODO_TRIP_SettingMenu _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0001 ));
  InfoINF26_ODO_TRIP_SettingMenu_SetNoOfMenuItems( _this );
  InfoINF26_ODO_TRIP_SettingMenu_GetMileageSetting( _this );
  InfoINF26_ODO_TRIP_SettingMenu_GetSelectedOdoTrip( _this );
}

/* 'C' function for method : 'Info::INF26_ODO_TRIP_SettingMenu.LoadItemClass()' */
XClass InfoINF26_ODO_TRIP_SettingMenu_LoadItemClass( InfoINF26_ODO_TRIP_SettingMenu _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemValueUnitCheckmark );
}

/* 'C' function for method : 'Info::INF26_ODO_TRIP_SettingMenu.LoadItemTitle()' */
XString InfoINF26_ODO_TRIP_SettingMenu_LoadItemTitle( InfoINF26_ODO_TRIP_SettingMenu _this, 
  XInt32 aItemNo )
{
  XString Title = 0;

  switch ( _this->SupportedSetting[ EwCheckIndex( aItemNo, 4 )])
  {
    case EnumMeterInfoODO :
      Title = EwLoadString( &StringsINF26_ODO );
    break;

    case EnumMeterInfoTRIP1 :
      Title = EwLoadString( &StringsINF26_TRIP_1 );
    break;

    case EnumMeterInfoTRIP2 :
      Title = EwLoadString( &StringsINF26_TRIP_2 );
    break;

    case EnumMeterInfoTRIP_F :
      Title = EwLoadString( &StringsINF26_TRIP_F );
    break;

    default :; 
  }

  return Title;
}

/* 'C' function for method : 'Info::INF26_ODO_TRIP_SettingMenu.OnItemActivate()' */
void InfoINF26_ODO_TRIP_SettingMenu_OnItemActivate( InfoINF26_ODO_TRIP_SettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  if ( _this->SelectedItem == _this->SupportedSetting[ EwCheckIndex( aItemNo, 4 )])
    CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
  else
  {
    _this->IsWaitingForResponse = 1;
    DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
    DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeCHG_METER_INFO, (XUInt32)_this->SupportedSetting[ 
    EwCheckIndex( aItemNo, 4 )]);
  }
}

/* 'C' function for method : 'Info::INF26_ODO_TRIP_SettingMenu.LoadItemChecked()' */
XBool InfoINF26_ODO_TRIP_SettingMenu_LoadItemChecked( InfoINF26_ODO_TRIP_SettingMenu _this, 
  XInt32 aItemNo )
{
  XBool checked = 0;

  if ( _this->SelectedItem == _this->SupportedSetting[ EwCheckIndex( aItemNo, 4 )])
    checked = 1;

  return checked;
}

/* 'C' function for method : 'Info::INF26_ODO_TRIP_SettingMenu.LoadItemEnabled()' */
XBool InfoINF26_ODO_TRIP_SettingMenu_LoadItemEnabled( InfoINF26_ODO_TRIP_SettingMenu _this, 
  XInt32 aItemNo )
{
  XBool ItemEnabled = 1;

  if ( EnumMeterInfoTRIP_F == _this->SupportedSetting[ EwCheckIndex( aItemNo, 4 )])
  {
    DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
      EnumVehicleRxTypeLOW_FUEL_WARNING );

    if ( VehicleData->Valid && ( 0 == !!VehicleData->DataUInt32 ))
      ItemEnabled = 0;
  }

  return ItemEnabled;
}

/* 'C' function for method : 'Info::INF26_ODO_TRIP_SettingMenu.LoadItemUnit()' */
XString InfoINF26_ODO_TRIP_SettingMenu_LoadItemUnit( InfoINF26_ODO_TRIP_SettingMenu _this, 
  XInt32 aItemNo )
{
  XString UnitString;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aItemNo );

  UnitString = 0;

  switch ( _this->MileageSetting )
  {
    case EnumMileageSettingItemKM :
      UnitString = EwLoadString( &StringsUNT02_UNIT_MILEAGE_KILOMETER );
    break;

    case EnumMileageSettingItemMILE :
      UnitString = EwLoadString( &StringsUNT02_UNIT_MILEAGE_MILE );
    break;

    default :; 
  }

  return UnitString;
}

/* 'C' function for method : 'Info::INF26_ODO_TRIP_SettingMenu.LoadItemValue()' */
XString InfoINF26_ODO_TRIP_SettingMenu_LoadItemValue( InfoINF26_ODO_TRIP_SettingMenu _this, 
  XInt32 aItemNo )
{
  XString Value;
  DeviceInterfaceVehicleDataClass VehicleData = 0;
  XInt32 NumOfDecimalDigits = 1;

  switch ( _this->SupportedSetting[ EwCheckIndex( aItemNo, 4 )])
  {
    case EnumMeterInfoODO :
      VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeODOMETER_VALUE );
    break;

    case EnumMeterInfoTRIP1 :
      VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeTRIP1_VALUE );
    break;

    case EnumMeterInfoTRIP2 :
      VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeTRIP2_VALUE );
    break;

    case EnumMeterInfoTRIP_F :
      if ( DeviceInterfaceVehicleDeviceClass_OnGetLowFuelWarning( EwGetAutoObject( 
          &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
        VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
        &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeTRIP_F_VALUE );
      else
      {
        VehicleData = EwNewObject( DeviceInterfaceVehicleDataClass, 0 );
        VehicleData->Valid = 0;
      }
    break;

    default : 
      VehicleData->Valid = 0;
  }

  if ( VehicleData->Valid )
  {
    if ( EnumMileageSettingItemMILE == _this->MileageSetting )
      VehicleData->DataFloat *= 0.625000f;

    switch ( _this->SupportedSetting[ EwCheckIndex( aItemNo, 4 )])
    {
      case EnumMeterInfoODO :
      {
        VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_ClampDataFloat( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        VehicleData->DataFloat, 0.000000f, 999999.000000f );
        NumOfDecimalDigits = 0;
      }
      break;

      case EnumMeterInfoTRIP1 :
        VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_ClampDataFloat( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        VehicleData->DataFloat, 0.000000f, 9999.900391f );
      break;

      case EnumMeterInfoTRIP2 :
        VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_ClampDataFloat( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        VehicleData->DataFloat, 0.000000f, 9999.900391f );
      break;

      case EnumMeterInfoTRIP_F :
        VehicleData->DataFloat = DeviceInterfaceVehicleDeviceClass_ClampDataFloat( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        VehicleData->DataFloat, 0.000000f, 999.900024f );
      break;

      default :; 
    }

    Value = EwNewStringFloat( VehicleData->DataFloat, 0, NumOfDecimalDigits );
  }
  else
    Value = EwLoadString( &StringsGEN_THREE_HYPHENS );

  return Value;
}

/* 'C' function for method : 'Info::INF26_ODO_TRIP_SettingMenu.OnItemLongEnterKeyActivate()' */
void InfoINF26_ODO_TRIP_SettingMenu_OnItemLongEnterKeyActivate( InfoINF26_ODO_TRIP_SettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  if ((( EnumMeterInfoTRIP1 == _this->SupportedSetting[ EwCheckIndex( aItemNo, 4 )]) 
      || ( EnumMeterInfoTRIP2 == _this->SupportedSetting[ EwCheckIndex( aItemNo, 
      4 )])) || ( EnumMeterInfoTRIP_F == _this->SupportedSetting[ EwCheckIndex( 
      aItemNo, 4 )]))
  {
    PopPOP04_Reset ResetDialog = EwNewObject( PopPOP04_Reset, 0 );
    ResetDialog->SelectedMeterInfo = _this->SupportedSetting[ EwCheckIndex( aItemNo, 
    4 )];
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)ResetDialog ), 0, 0, 0, 
    0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* 'C' function for method : 'Info::INF26_ODO_TRIP_SettingMenu.OnCheckMarkUpdateSlot()' */
void InfoINF26_ODO_TRIP_SettingMenu_OnCheckMarkUpdateSlot( InfoINF26_ODO_TRIP_SettingMenu _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ComponentsBaseMainBG_DismissThisDialog((ComponentsBaseMainBG)_this );
}

/* 'C' function for method : 'Info::INF26_ODO_TRIP_SettingMenu.GetMileageSetting()' */
void InfoINF26_ODO_TRIP_SettingMenu_GetMileageSetting( InfoINF26_ODO_TRIP_SettingMenu _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeMILEAGE_UNIT );

  if ( 1 == VehicleData->DataUInt32 )
    _this->MileageSetting = EnumMileageSettingItemMILE;
  else
    _this->MileageSetting = EnumMileageSettingItemKM;
}

/* 'C' function for method : 'Info::INF26_ODO_TRIP_SettingMenu.SetNoOfMenuItems()' */
void InfoINF26_ODO_TRIP_SettingMenu_SetNoOfMenuItems( InfoINF26_ODO_TRIP_SettingMenu _this )
{
  XInt32 i;
  XInt32 NoOfItems = 0;
  XEnum SettingItem;

  for ( i = 0; i < 4; i++ )
  {
    SettingItem = _this->AllSettings[ EwCheckIndex( i, 4 )];

    switch ( SettingItem )
    {
      case EnumMeterInfoTRIP1 :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionTRIP1 ))
        {
          _this->SupportedSetting[ EwCheckIndex( NoOfItems, 4 )] = SettingItem;
          NoOfItems++;
        }
      break;

      case EnumMeterInfoTRIP2 :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionTRIP2 ))
        {
          _this->SupportedSetting[ EwCheckIndex( NoOfItems, 4 )] = SettingItem;
          NoOfItems++;
        }
      break;

      case EnumMeterInfoTRIP_F :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionF_TRIP ))
        {
          _this->SupportedSetting[ EwCheckIndex( NoOfItems, 4 )] = SettingItem;
          NoOfItems++;
        }
      break;

      default : 
      {
        _this->SupportedSetting[ EwCheckIndex( NoOfItems, 4 )] = SettingItem;
        NoOfItems++;
      }
    }
  }

  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, NoOfItems );
}

/* 'C' function for method : 'Info::INF26_ODO_TRIP_SettingMenu.GetSelectedOdoTrip()' */
void InfoINF26_ODO_TRIP_SettingMenu_GetSelectedOdoTrip( InfoINF26_ODO_TRIP_SettingMenu _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeODO_TRIP_DISPLAY );

  if ( 4 > VehicleData->DataUInt32 )
  {
    XEnum SettingItem = (XEnum)VehicleData->DataUInt32;

    switch ( SettingItem )
    {
      case EnumOdoTripSettingItemODO :
        _this->SelectedItem = EnumMeterInfoODO;
      break;

      case EnumOdoTripSettingItemTRIP1 :
        _this->SelectedItem = EnumMeterInfoTRIP1;
      break;

      case EnumOdoTripSettingItemTRIP2 :
        _this->SelectedItem = EnumMeterInfoTRIP2;
      break;

      case EnumOdoTripSettingItemTRIP_F :
        _this->SelectedItem = EnumMeterInfoTRIP_F;
      break;

      default :; 
    }
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void InfoINF26_ODO_TRIP_SettingMenu_OnVehicleDataReceivedSlot( InfoINF26_ODO_TRIP_SettingMenu _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if ( VehicleData != 0 )
    switch ( VehicleData->RxType )
    {
      case EnumVehicleRxTypeODO_TRIP_DISPLAY :
        if ( _this->IsWaitingForResponse )
        {
          InfoINF26_ODO_TRIP_SettingMenu_GetSelectedOdoTrip( _this );
          MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, _this->Super1.Menu.NoOfItems 
          - 1 );
          CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
        }
      break;

      case EnumVehicleRxTypeODOMETER_VALUE :
      case EnumVehicleRxTypeTRIP1_VALUE :
      case EnumVehicleRxTypeTRIP2_VALUE :
      case EnumVehicleRxTypeTRIP_F_VALUE :
      case EnumVehicleRxTypeLOW_FUEL_WARNING :
        MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, _this->Super1.Menu.NoOfItems 
        - 1 );
      break;

      default :; 
    }
}

/* Variants derived from the class : 'Info::INF26_ODO_TRIP_SettingMenu' */
EW_DEFINE_CLASS_VARIANTS( InfoINF26_ODO_TRIP_SettingMenu )
EW_END_OF_CLASS_VARIANTS( InfoINF26_ODO_TRIP_SettingMenu )

/* Virtual Method Table (VMT) for the class : 'Info::INF26_ODO_TRIP_SettingMenu' */
EW_DEFINE_CLASS( InfoINF26_ODO_TRIP_SettingMenu, MenuBaseMenuView, CheckMarkUpdateTimer, 
                 CheckMarkUpdateTimer, CheckMarkUpdateTimer, CheckMarkUpdateTimer, 
                 AllSettings, AllSettings, "Info::INF26_ODO_TRIP_SettingMenu" )
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
  CoreGroup_GetViewAtIndex,
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
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  MenuBaseMenuView_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  InfoINF26_ODO_TRIP_SettingMenu_LoadItemClass,
  InfoINF26_ODO_TRIP_SettingMenu_LoadItemTitle,
  InfoINF26_ODO_TRIP_SettingMenu_OnItemActivate,
  InfoINF26_ODO_TRIP_SettingMenu_LoadItemChecked,
  InfoINF26_ODO_TRIP_SettingMenu_LoadItemEnabled,
  MenuBaseMenuView_LoadItemBaseValue,
  MenuBaseMenuView_LoadItemMessage,
  MenuBaseMenuView_LoadItemReceivedTime,
  MenuBaseMenuView_LoadItemCategory,
  MenuBaseMenuView_LoadItemUid,
  MenuBaseMenuView_LoadItemToggle,
  InfoINF26_ODO_TRIP_SettingMenu_LoadItemUnit,
  InfoINF26_ODO_TRIP_SettingMenu_LoadItemValue,
  InfoINF26_ODO_TRIP_SettingMenu_OnItemLongEnterKeyActivate,
  MenuBaseMenuView_LoadItemHour,
  MenuBaseMenuView_LoadItemMinute,
  MenuBaseMenuView_LoadPoiListItemValue,
  MenuBaseMenuView_LoadPoiListItemUnit,
EW_END_OF_CLASS( InfoINF26_ODO_TRIP_SettingMenu )

/* Embedded Wizard */
