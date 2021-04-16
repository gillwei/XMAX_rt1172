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
#include "_ComponentsBaseMainBG.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreVerticalList.h"
#include "_DeviceInterfaceVehicleDataClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_MenuItemBaseValue.h"
#include "_MenuItemCheckMark.h"
#include "_MenuVerticalMenu.h"
#include "_UnitUNT01_UnitSettingMenu.h"
#include "_UnitUNT02_MileageSettingMenu.h"
#include "_UnitUNT03_FuelSettingMenu.h"
#include "_UnitUNT04_PressureSettingMenu.h"
#include "_UnitUNT05_TemperatureSettingMenu.h"
#include "_UnitUnitValueClass.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Strings.h"
#include "Unit.h"

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};

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

/* Initializer for the class 'Unit::UNT01_UnitSettingMenu' */
void UnitUNT01_UnitSettingMenu__Init( UnitUNT01_UnitSettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( UnitUNT01_UnitSettingMenu );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( UnitUNT01_UnitSettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 4 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsUNT01_UNIT_MILEAGE ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsUNT01_UNIT_FUEL ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &StringsUNT01_UNIT_PRESSURE ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &StringsUNT01_UNIT_TEMPERATURE ));
  _this->ItemVehicleRxTypeArray[ 0 ] = EnumVehicleRxTypeMILEAGE_UNIT;
  _this->ItemVehicleRxTypeArray[ 1 ] = EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT;
  _this->ItemVehicleRxTypeArray[ 2 ] = EnumVehicleRxTypePRESSURE_UNIT;
  _this->ItemVehicleRxTypeArray[ 3 ] = EnumVehicleRxTypeTEMPERATURE_UNIT;
  _this->IsFuelEnabled = 1;
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, UnitUNT01_UnitSettingMenu_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );

  /* Call the user defined constructor */
  UnitUNT01_UnitSettingMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Unit::UNT01_UnitSettingMenu' */
void UnitUNT01_UnitSettingMenu__ReInit( UnitUNT01_UnitSettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'Unit::UNT01_UnitSettingMenu' */
void UnitUNT01_UnitSettingMenu__Done( UnitUNT01_UnitSettingMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void UnitUNT01_UnitSettingMenu_Init( UnitUNT01_UnitSettingMenu _this, XHandle aArg )
{
  XInt32 NoOfItems;
  XInt32 ItemIdx;
  XInt32 i;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  NoOfItems = 3;
  ItemIdx = 2;

  if ( UnitUNT01_UnitSettingMenu_OnGetPressureEnabled( _this ))
  {
    NoOfItems++;
    _this->PressureMenu = EwNewObject( UnitUNT04_PressureSettingMenu, 0 );
  }

  if ( NoOfItems < 4 )
  {
    _this->ItemVehicleRxTypeArray[ EwCheckIndex( ItemIdx, 4 )] = _this->ItemVehicleRxTypeArray[ 
    3 ];
  }

  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, NoOfItems );
  _this->UnitItemValue = EwNewObject( UnitUnitValueClass, 0 );
  _this->MileageMenu = EwNewObject( UnitUNT02_MileageSettingMenu, 0 );
  _this->FuelMenu = EwNewObject( UnitUNT03_FuelSettingMenu, 0 );
  _this->TempMenu = EwNewObject( UnitUNT05_TemperatureSettingMenu, 0 );

  for ( i = 0; i < NoOfItems; i++ )
  {
    UnitUNT01_UnitSettingMenu_UpdateUnitValue( _this, _this->ItemVehicleRxTypeArray[ 
    EwCheckIndex( i, 4 )]);
  }
}

/* 'C' function for method : 'Unit::UNT01_UnitSettingMenu.LoadItemClass()' */
XClass UnitUNT01_UnitSettingMenu_LoadItemClass( UnitUNT01_UnitSettingMenu _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( !!aItemNo )
    ;

  return EW_CLASS( MenuItemBaseValue );
}

/* 'C' function for method : 'Unit::UNT01_UnitSettingMenu.LoadItemTitle()' */
XString UnitUNT01_UnitSettingMenu_LoadItemTitle( UnitUNT01_UnitSettingMenu _this, 
  XInt32 aItemNo )
{
  XString title = 0;

  switch ( _this->ItemVehicleRxTypeArray[ EwCheckIndex( aItemNo, 4 )])
  {
    case EnumVehicleRxTypeMILEAGE_UNIT :
      title = EwLoadString( &StringsUNT01_UNIT_MILEAGE );
    break;

    case EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT :
      title = EwLoadString( &StringsUNT01_UNIT_FUEL );
    break;

    case EnumVehicleRxTypePRESSURE_UNIT :
      title = EwLoadString( &StringsUNT01_UNIT_PRESSURE );
    break;

    case EnumVehicleRxTypeTEMPERATURE_UNIT :
      title = EwLoadString( &StringsUNT01_UNIT_TEMPERATURE );
    break;

    default : 
      ;
  }

  return title;
}

/* 'C' function for method : 'Unit::UNT01_UnitSettingMenu.OnItemActivate()' */
void UnitUNT01_UnitSettingMenu_OnItemActivate( UnitUNT01_UnitSettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  switch ( _this->ItemVehicleRxTypeArray[ EwCheckIndex( aItemNo, 4 )])
  {
    case EnumVehicleRxTypeMILEAGE_UNIT :
    {
      if ( _this->MileageMenu != 0 )
      {
        _this->MileageMenu->MileageUpdateSignal = EwNewSlot( _this, UnitUNT01_UnitSettingMenu_OnUnitValueUpdateSlot );
        ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)_this->MileageMenu ));
      }
    }
    break;

    case EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT :
    {
      if ( _this->FuelMenu != 0 )
      {
        _this->FuelMenu->FuelUpdateSignal = EwNewSlot( _this, UnitUNT01_UnitSettingMenu_OnUnitValueUpdateSlot );

        if ( EnumMileageSettingItemKM == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
            DeviceInterfaceVehicleDeviceClass )->CurrentMileageSetting )
        {
          _this->FuelMenu->ItemEnabledArray[ 0 ] = 1;
          _this->FuelMenu->ItemEnabledArray[ 1 ] = 0;
          _this->FuelMenu->ItemEnabledArray[ 2 ] = 1;
        }
        else
        {
          _this->FuelMenu->ItemEnabledArray[ 0 ] = 0;
          _this->FuelMenu->ItemEnabledArray[ 1 ] = 1;
          _this->FuelMenu->ItemEnabledArray[ 2 ] = 0;
        }

        MenuVerticalMenu_InvalidateItems( &_this->FuelMenu->Super1.Menu, 0, 2 );
        ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)_this->FuelMenu ));
      }
    }
    break;

    case EnumVehicleRxTypePRESSURE_UNIT :
    {
      if ( _this->PressureMenu != 0 )
      {
        _this->PressureMenu->PressureUpdateSignal = EwNewSlot( _this, UnitUNT01_UnitSettingMenu_OnUnitValueUpdateSlot );
        ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)_this->PressureMenu ));
      }
    }
    break;

    case EnumVehicleRxTypeTEMPERATURE_UNIT :
    {
      if ( _this->TempMenu != 0 )
      {
        _this->TempMenu->TempUpdateSignal = EwNewSlot( _this, UnitUNT01_UnitSettingMenu_OnUnitValueUpdateSlot );
        ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)_this->TempMenu ));
      }
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Unit::UNT01_UnitSettingMenu.LoadItemEnabled()' */
XBool UnitUNT01_UnitSettingMenu_LoadItemEnabled( UnitUNT01_UnitSettingMenu _this, 
  XInt32 aItemNo )
{
  XBool ItemEnabled = 1;

  if ( aItemNo == 1 )
  {
    ItemEnabled = _this->IsFuelEnabled;
  }

  return ItemEnabled;
}

/* 'C' function for method : 'Unit::UNT01_UnitSettingMenu.LoadItemBaseValue()' */
XString UnitUNT01_UnitSettingMenu_LoadItemBaseValue( UnitUNT01_UnitSettingMenu _this, 
  XInt32 aItemNo )
{
  XString val = 0;

  if ( aItemNo < 4 )
  {
    val = _this->ItemValueArray[ EwCheckIndex( aItemNo, 4 )];
  }

  return val;
}

/* 'C' function for method : 'Unit::UNT01_UnitSettingMenu.OnUnitValueUpdateSlot()' */
void UnitUNT01_UnitSettingMenu_OnUnitValueUpdateSlot( UnitUNT01_UnitSettingMenu _this, 
  XObject sender )
{
  if ( sender == (XObject)_this->MileageMenu )
  {
    UnitUNT01_UnitSettingMenu_UpdateUnitValue( _this, EnumVehicleRxTypeMILEAGE_UNIT );
  }
  else
    if ( sender == (XObject)_this->FuelMenu )
    {
      UnitUNT01_UnitSettingMenu_UpdateUnitValue( _this, EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT );
    }
    else
      if ( sender == (XObject)_this->PressureMenu )
      {
        UnitUNT01_UnitSettingMenu_UpdateUnitValue( _this, EnumVehicleRxTypePRESSURE_UNIT );
      }
      else
        if ( sender == (XObject)_this->TempMenu )
        {
          UnitUNT01_UnitSettingMenu_UpdateUnitValue( _this, EnumVehicleRxTypeTEMPERATURE_UNIT );
        }

  if ( UnitUNT01_UnitSettingMenu_OnGetPressureEnabled( _this ))
  {
    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 3 );
  }
  else
  {
    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 2 );
  }
}

/* 'C' function for method : 'Unit::UNT01_UnitSettingMenu.OnGetPressureEnabled()' */
XBool UnitUNT01_UnitSettingMenu_OnGetPressureEnabled( UnitUNT01_UnitSettingMenu _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  return (XBool)((( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleSupportedFunctionTIRE_FRONT ) || DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleSupportedFunctionTIRE_FRONT_LEFT )) || DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleSupportedFunctionTIRE_FRONT_RIGHT )) || DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleSupportedFunctionTIRE_REAR ));
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void UnitUNT01_UnitSettingMenu_OnVehicleDataReceivedSlot( UnitUNT01_UnitSettingMenu _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;
  XBool IsVehicleUnitDataReceived;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );
  IsVehicleUnitDataReceived = (XBool)(((( EnumVehicleRxTypeMILEAGE_UNIT == VehicleData->RxType ) 
  || ( EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT == VehicleData->RxType )) || ( EnumVehicleRxTypePRESSURE_UNIT 
  == VehicleData->RxType )) || ( EnumVehicleRxTypeTEMPERATURE_UNIT == VehicleData->RxType ));

  if (( VehicleData != 0 ) && IsVehicleUnitDataReceived )
  {
    UnitUNT01_UnitSettingMenu_UpdateUnitValue( _this, VehicleData->RxType );

    if ( UnitUNT01_UnitSettingMenu_OnGetPressureEnabled( _this ))
    {
      MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 3 );
    }
    else
    {
      MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 2 );
    }
  }
}

/* 'C' function for method : 'Unit::UNT01_UnitSettingMenu.UpdateUnitValue()' */
void UnitUNT01_UnitSettingMenu_UpdateUnitValue( UnitUNT01_UnitSettingMenu _this, 
  XEnum aReceivedUnitType )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  switch ( aReceivedUnitType )
  {
    case EnumVehicleRxTypeMILEAGE_UNIT :
    {
      VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeMILEAGE_UNIT );

      if (( VehicleData != 0 ) && ( 2 > (XInt32)VehicleData->DataUInt32 ))
      {
        _this->ItemValueArray[ 0 ] = EwShareString( _this->UnitItemValue->ItemMileageUnitArray[ 
        EwCheckIndex((XInt32)VehicleData->DataUInt32, 2 )]);
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentMileageSetting 
        = (XEnum)VehicleData->DataUInt32;
      }
    }
    break;

    case EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT :
    {
      _this->IsFuelEnabled = 1;
      VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT );

      if ( VehicleData != 0 )
      {
        switch ( VehicleData->DataUInt32 )
        {
          case 0 :
          {
            _this->ItemValueArray[ 1 ] = EwShareString( _this->UnitItemValue->ItemFuelUnitArray[ 
            0 ]);
            EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentFuelSetting 
            = EnumFuelSettingItemKM_L;
          }
          break;

          case 1 :
          case 2 :
          {
            _this->IsFuelEnabled = 0;
            _this->ItemValueArray[ 1 ] = EwShareString( _this->UnitItemValue->ItemFuelUnitArray[ 
            1 ]);
            EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentFuelSetting 
            = EnumFuelSettingItemMPG;
          }
          break;

          case 3 :
          {
            _this->ItemValueArray[ 1 ] = EwShareString( _this->UnitItemValue->ItemFuelUnitArray[ 
            2 ]);
            EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentFuelSetting 
            = EnumFuelSettingItemL_PER_HUNDRED_KM;
          }
          break;

          default : 
            ;
        }
      }
    }
    break;

    case EnumVehicleRxTypePRESSURE_UNIT :
    {
      VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypePRESSURE_UNIT );

      if (( VehicleData != 0 ) && ( 3 > (XInt32)VehicleData->DataUInt32 ))
      {
        _this->ItemValueArray[ 2 ] = EwShareString( _this->UnitItemValue->ItemPressureUnitArray[ 
        EwCheckIndex((XInt32)VehicleData->DataUInt32, 3 )]);
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentPressureSetting 
        = (XEnum)VehicleData->DataUInt32;
      }
    }
    break;

    case EnumVehicleRxTypeTEMPERATURE_UNIT :
    {
      VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeTEMPERATURE_UNIT );

      if (( VehicleData != 0 ) && ( 2 > (XInt32)VehicleData->DataUInt32 ))
      {
        if ( UnitUNT01_UnitSettingMenu_OnGetPressureEnabled( _this ))
        {
          _this->ItemValueArray[ 3 ] = EwShareString( _this->UnitItemValue->ItemTemperatureUnitArray[ 
          EwCheckIndex((XInt32)VehicleData->DataUInt32, 2 )]);
        }
        else
        {
          _this->ItemValueArray[ 2 ] = EwShareString( _this->UnitItemValue->ItemTemperatureUnitArray[ 
          EwCheckIndex((XInt32)VehicleData->DataUInt32, 2 )]);
        }

        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentTempSetting 
        = (XEnum)VehicleData->DataUInt32;
      }
    }
    break;

    default : 
      ;
  }
}

/* Variants derived from the class : 'Unit::UNT01_UnitSettingMenu' */
EW_DEFINE_CLASS_VARIANTS( UnitUNT01_UnitSettingMenu )
EW_END_OF_CLASS_VARIANTS( UnitUNT01_UnitSettingMenu )

/* Virtual Method Table (VMT) for the class : 'Unit::UNT01_UnitSettingMenu' */
EW_DEFINE_CLASS( UnitUNT01_UnitSettingMenu, MenuBaseMenuView, UnitItemValue, VehicleDataReceivedEventHandler, 
                 VehicleDataReceivedEventHandler, VehicleDataReceivedEventHandler, 
                 ItemTitleArray, ItemVehicleRxTypeArray, "Unit::UNT01_UnitSettingMenu" )
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
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  UnitUNT01_UnitSettingMenu_LoadItemClass,
  UnitUNT01_UnitSettingMenu_LoadItemTitle,
  UnitUNT01_UnitSettingMenu_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  UnitUNT01_UnitSettingMenu_LoadItemEnabled,
  UnitUNT01_UnitSettingMenu_LoadItemBaseValue,
  MenuBaseMenuView_LoadItemMessage,
  MenuBaseMenuView_LoadItemReceivedTime,
  MenuBaseMenuView_LoadItemCategory,
  MenuBaseMenuView_LoadItemUid,
  MenuBaseMenuView_LoadItemToggle,
EW_END_OF_CLASS( UnitUNT01_UnitSettingMenu )

/* Initializer for the class 'Unit::UNT02_MileageSettingMenu' */
void UnitUNT02_MileageSettingMenu__Init( UnitUNT02_MileageSettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( UnitUNT02_MileageSettingMenu );

  /* ... then construct all embedded objects */
  CoreTimer__Init( &_this->CheckMarkUpdateTimer, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( UnitUNT02_MileageSettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 2 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 2 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsUNT02_UNIT_MILEAGE_KILOMETER ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsUNT02_UNIT_MILEAGE_MILE ));
  CoreTimer_OnSetPeriod( &_this->CheckMarkUpdateTimer, 450 );
  _this->CheckMarkUpdateTimer.OnTrigger = EwNewSlot( _this, UnitUNT02_MileageSettingMenu_OnCheckMarkUpdateSlot );
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, UnitUNT02_MileageSettingMenu_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );
}

/* Re-Initializer for the class 'Unit::UNT02_MileageSettingMenu' */
void UnitUNT02_MileageSettingMenu__ReInit( UnitUNT02_MileageSettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreTimer__ReInit( &_this->CheckMarkUpdateTimer );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'Unit::UNT02_MileageSettingMenu' */
void UnitUNT02_MileageSettingMenu__Done( UnitUNT02_MileageSettingMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CoreTimer__Done( &_this->CheckMarkUpdateTimer );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Unit::UNT02_MileageSettingMenu.LoadItemClass()' */
XClass UnitUNT02_MileageSettingMenu_LoadItemClass( UnitUNT02_MileageSettingMenu _this, 
  XInt32 aItemNo )
{
  XClass ItemClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemClass = 0;

  if ( aItemNo >= 0 )
  {
    ItemClass = EW_CLASS( MenuItemCheckMark );
  }

  return ItemClass;
}

/* 'C' function for method : 'Unit::UNT02_MileageSettingMenu.LoadItemTitle()' */
XString UnitUNT02_MileageSettingMenu_LoadItemTitle( UnitUNT02_MileageSettingMenu _this, 
  XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < 2 )
  {
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 2 )];
  }

  return title;
}

/* 'C' function for method : 'Unit::UNT02_MileageSettingMenu.OnItemActivate()' */
void UnitUNT02_MileageSettingMenu_OnItemActivate( UnitUNT02_MileageSettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  switch ( aItemNo )
  {
    case 0 :
    {
      if ( EnumMileageSettingItemKM == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentMileageSetting )
      {
        CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
      }
      else
      {
        DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeMILEAGE_UNIT, 0 );
      }
    }
    break;

    case 1 :
    {
      if ( EnumMileageSettingItemMILE == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentMileageSetting )
      {
        CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
      }
      else
      {
        DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeMILEAGE_UNIT, 1 );
      }
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Unit::UNT02_MileageSettingMenu.LoadItemChecked()' */
XBool UnitUNT02_MileageSettingMenu_LoadItemChecked( UnitUNT02_MileageSettingMenu _this, 
  XInt32 aItemNo )
{
  XBool IsChecked;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsChecked = 0;

  switch ( aItemNo )
  {
    case 0 :
    {
      if ( EnumMileageSettingItemKM == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentMileageSetting )
      {
        IsChecked = 1;
      }
    }
    break;

    case 1 :
    {
      if ( EnumMileageSettingItemMILE == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentMileageSetting )
      {
        IsChecked = 1;
      }
    }
    break;

    default : 
      ;
  }

  return IsChecked;
}

/* 'C' function for method : 'Unit::UNT02_MileageSettingMenu.OnCheckMarkUpdateSlot()' */
void UnitUNT02_MileageSettingMenu_OnCheckMarkUpdateSlot( UnitUNT02_MileageSettingMenu _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 0 );
  EwSignal( _this->MileageUpdateSignal, ((XObject)_this ));
  CoreVerticalList_OnSetSelectedItem( &_this->Super1.Menu.MenuList, 0 );
  MenuVerticalMenu_MoveFocusFrame( &_this->Super1.Menu );
  ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void UnitUNT02_MileageSettingMenu_OnVehicleDataReceivedSlot( UnitUNT02_MileageSettingMenu _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if (( VehicleData != 0 ) && ( EnumVehicleRxTypeMILEAGE_UNIT == VehicleData->RxType ))
  {
    VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
    DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeMILEAGE_UNIT );

    switch ( VehicleData->DataUInt32 )
    {
      case 0 :
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentMileageSetting 
        = EnumMileageSettingItemKM;
      break;

      case 1 :
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentMileageSetting 
        = EnumMileageSettingItemMILE;
      break;

      default : 
        ;
    }

    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 1 );
    CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
  }
}

/* Variants derived from the class : 'Unit::UNT02_MileageSettingMenu' */
EW_DEFINE_CLASS_VARIANTS( UnitUNT02_MileageSettingMenu )
EW_END_OF_CLASS_VARIANTS( UnitUNT02_MileageSettingMenu )

/* Virtual Method Table (VMT) for the class : 'Unit::UNT02_MileageSettingMenu' */
EW_DEFINE_CLASS( UnitUNT02_MileageSettingMenu, MenuBaseMenuView, MileageUpdateSignal, 
                 MileageUpdateSignal, CheckMarkUpdateTimer, CheckMarkUpdateTimer, 
                 ItemTitleArray, _None, "Unit::UNT02_MileageSettingMenu" )
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
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  UnitUNT02_MileageSettingMenu_LoadItemClass,
  UnitUNT02_MileageSettingMenu_LoadItemTitle,
  UnitUNT02_MileageSettingMenu_OnItemActivate,
  UnitUNT02_MileageSettingMenu_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemBaseValue,
  MenuBaseMenuView_LoadItemMessage,
  MenuBaseMenuView_LoadItemReceivedTime,
  MenuBaseMenuView_LoadItemCategory,
  MenuBaseMenuView_LoadItemUid,
  MenuBaseMenuView_LoadItemToggle,
EW_END_OF_CLASS( UnitUNT02_MileageSettingMenu )

/* Initializer for the class 'Unit::UnitValueClass' */
void UnitUnitValueClass__Init( UnitUnitValueClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( UnitUnitValueClass );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( UnitUnitValueClass );

  /* ... and initialize objects, variables, properties, etc. */
  _this->ItemMileageUnitArray[ 0 ] = EwShareString( EwLoadString( &StringsUNT02_UNIT_MILEAGE_KILOMETER ));
  _this->ItemMileageUnitArray[ 1 ] = EwShareString( EwLoadString( &StringsUNT02_UNIT_MILEAGE_MILE ));
  _this->ItemFuelUnitArray[ 0 ] = EwShareString( EwLoadString( &StringsUNT03_UNIT_FUEL_KM_PER_LITER ));
  _this->ItemFuelUnitArray[ 1 ] = EwShareString( EwLoadString( &StringsUNT03_UNIT_FUEL_MILE_PER_GALLON ));
  _this->ItemFuelUnitArray[ 2 ] = EwShareString( EwLoadString( &StringsUNT03_UNIT_FUEL_LITER_PER_HUNDRED_KM ));
  _this->ItemPressureUnitArray[ 0 ] = EwShareString( EwLoadString( &StringsUNT04_UNIT_PRESSURE_PSI ));
  _this->ItemPressureUnitArray[ 1 ] = EwShareString( EwLoadString( &StringsUNT04_UNIT_PRESSURE_KPA ));
  _this->ItemPressureUnitArray[ 2 ] = EwShareString( EwLoadString( &StringsUNT04_UNIT_PRESSURE_KGF ));
  _this->ItemTemperatureUnitArray[ 0 ] = EwShareString( EwLoadString( &StringsUNT05_UNIT_TEMPERATURE_C ));
  _this->ItemTemperatureUnitArray[ 1 ] = EwShareString( EwLoadString( &StringsUNT05_UNIT_TEMPERATURE_F ));
}

/* Re-Initializer for the class 'Unit::UnitValueClass' */
void UnitUnitValueClass__ReInit( UnitUnitValueClass _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Unit::UnitValueClass' */
void UnitUnitValueClass__Done( UnitUnitValueClass _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_Super );
}

/* Variants derived from the class : 'Unit::UnitValueClass' */
EW_DEFINE_CLASS_VARIANTS( UnitUnitValueClass )
EW_END_OF_CLASS_VARIANTS( UnitUnitValueClass )

/* Virtual Method Table (VMT) for the class : 'Unit::UnitValueClass' */
EW_DEFINE_CLASS( UnitUnitValueClass, XObject, ItemMileageUnitArray, ItemMileageUnitArray, 
                 ItemMileageUnitArray, ItemMileageUnitArray, ItemMileageUnitArray, 
                 _None, "Unit::UnitValueClass" )
EW_END_OF_CLASS( UnitUnitValueClass )

/* Initializer for the class 'Unit::UNT03_FuelSettingMenu' */
void UnitUNT03_FuelSettingMenu__Init( UnitUNT03_FuelSettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( UnitUNT03_FuelSettingMenu );

  /* ... then construct all embedded objects */
  CoreTimer__Init( &_this->CheckMarkUpdateTimer, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( UnitUNT03_FuelSettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 3 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsUNT03_UNIT_FUEL_KM_PER_LITER ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsUNT03_UNIT_FUEL_LITER_PER_HUNDRED_KM ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &StringsUNT03_UNIT_FUEL_MILE_PER_GALLON ));
  CoreTimer_OnSetPeriod( &_this->CheckMarkUpdateTimer, 450 );
  _this->CheckMarkUpdateTimer.OnTrigger = EwNewSlot( _this, UnitUNT03_FuelSettingMenu_OnCheckMarkUpdateSlot );
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, UnitUNT03_FuelSettingMenu_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );
}

/* Re-Initializer for the class 'Unit::UNT03_FuelSettingMenu' */
void UnitUNT03_FuelSettingMenu__ReInit( UnitUNT03_FuelSettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreTimer__ReInit( &_this->CheckMarkUpdateTimer );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'Unit::UNT03_FuelSettingMenu' */
void UnitUNT03_FuelSettingMenu__Done( UnitUNT03_FuelSettingMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CoreTimer__Done( &_this->CheckMarkUpdateTimer );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Unit::UNT03_FuelSettingMenu.LoadItemClass()' */
XClass UnitUNT03_FuelSettingMenu_LoadItemClass( UnitUNT03_FuelSettingMenu _this, 
  XInt32 aItemNo )
{
  XClass ItemClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemClass = 0;

  if ( aItemNo >= 0 )
  {
    ItemClass = EW_CLASS( MenuItemCheckMark );
  }

  return ItemClass;
}

/* 'C' function for method : 'Unit::UNT03_FuelSettingMenu.LoadItemTitle()' */
XString UnitUNT03_FuelSettingMenu_LoadItemTitle( UnitUNT03_FuelSettingMenu _this, 
  XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < 3 )
  {
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 3 )];
  }

  return title;
}

/* 'C' function for method : 'Unit::UNT03_FuelSettingMenu.OnItemActivate()' */
void UnitUNT03_FuelSettingMenu_OnItemActivate( UnitUNT03_FuelSettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  switch ( aItemNo )
  {
    case 0 :
    {
      if ( EnumFuelSettingItemKM_L == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentFuelSetting )
      {
        CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
      }
      else
      {
        DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeFUEL_CONSUMPTION_UNIT, 
        0 );
      }
    }
    break;

    case 1 :
    {
      if ( EnumFuelSettingItemL_PER_HUNDRED_KM == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentFuelSetting )
      {
        CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
      }
      else
      {
        DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeFUEL_CONSUMPTION_UNIT, 
        2 );
      }
    }
    break;

    case 2 :
    {
      if ( EnumFuelSettingItemMPG == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentFuelSetting )
      {
        CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
      }
      else
      {
        DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeFUEL_CONSUMPTION_UNIT, 
        1 );
      }
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Unit::UNT03_FuelSettingMenu.LoadItemChecked()' */
XBool UnitUNT03_FuelSettingMenu_LoadItemChecked( UnitUNT03_FuelSettingMenu _this, 
  XInt32 aItemNo )
{
  XBool IsChecked;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsChecked = 0;

  switch ( aItemNo )
  {
    case 0 :
    {
      if ( EnumFuelSettingItemKM_L == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentFuelSetting )
      {
        IsChecked = 1;
      }
    }
    break;

    case 1 :
    {
      if ( EnumFuelSettingItemL_PER_HUNDRED_KM == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentFuelSetting )
      {
        IsChecked = 1;
      }
    }
    break;

    case 2 :
    {
      if ( EnumFuelSettingItemMPG == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentFuelSetting )
      {
        IsChecked = 1;
      }
    }
    break;

    default : 
      ;
  }

  return IsChecked;
}

/* 'C' function for method : 'Unit::UNT03_FuelSettingMenu.LoadItemEnabled()' */
XBool UnitUNT03_FuelSettingMenu_LoadItemEnabled( UnitUNT03_FuelSettingMenu _this, 
  XInt32 aItemNo )
{
  XBool ItemEnabled = 1;

  switch ( aItemNo )
  {
    case 0 :
      ItemEnabled = _this->ItemEnabledArray[ 0 ];
    break;

    case 1 :
      ItemEnabled = _this->ItemEnabledArray[ 2 ];
    break;

    case 2 :
      ItemEnabled = _this->ItemEnabledArray[ 1 ];
    break;

    default : 
      ;
  }

  return ItemEnabled;
}

/* 'C' function for method : 'Unit::UNT03_FuelSettingMenu.OnCheckMarkUpdateSlot()' */
void UnitUNT03_FuelSettingMenu_OnCheckMarkUpdateSlot( UnitUNT03_FuelSettingMenu _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 0 );
  EwSignal( _this->FuelUpdateSignal, ((XObject)_this ));
  CoreVerticalList_OnSetSelectedItem( &_this->Super1.Menu.MenuList, 0 );
  MenuVerticalMenu_MoveFocusFrame( &_this->Super1.Menu );
  ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void UnitUNT03_FuelSettingMenu_OnVehicleDataReceivedSlot( UnitUNT03_FuelSettingMenu _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if (( VehicleData != 0 ) && ( EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT == VehicleData->RxType ))
  {
    VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
    DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT );

    switch ( VehicleData->DataUInt32 )
    {
      case 0 :
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentFuelSetting 
        = EnumFuelSettingItemKM_L;
      break;

      case 1 :
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentFuelSetting 
        = EnumFuelSettingItemMPG;
      break;

      case 2 :
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentFuelSetting 
        = EnumFuelSettingItemL_PER_HUNDRED_KM;
      break;

      default : 
        ;
    }

    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 2 );
    CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
  }
}

/* Variants derived from the class : 'Unit::UNT03_FuelSettingMenu' */
EW_DEFINE_CLASS_VARIANTS( UnitUNT03_FuelSettingMenu )
EW_END_OF_CLASS_VARIANTS( UnitUNT03_FuelSettingMenu )

/* Virtual Method Table (VMT) for the class : 'Unit::UNT03_FuelSettingMenu' */
EW_DEFINE_CLASS( UnitUNT03_FuelSettingMenu, MenuBaseMenuView, FuelUpdateSignal, 
                 FuelUpdateSignal, CheckMarkUpdateTimer, CheckMarkUpdateTimer, ItemTitleArray, 
                 ItemEnabledArray, "Unit::UNT03_FuelSettingMenu" )
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
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  UnitUNT03_FuelSettingMenu_LoadItemClass,
  UnitUNT03_FuelSettingMenu_LoadItemTitle,
  UnitUNT03_FuelSettingMenu_OnItemActivate,
  UnitUNT03_FuelSettingMenu_LoadItemChecked,
  UnitUNT03_FuelSettingMenu_LoadItemEnabled,
  MenuBaseMenuView_LoadItemBaseValue,
  MenuBaseMenuView_LoadItemMessage,
  MenuBaseMenuView_LoadItemReceivedTime,
  MenuBaseMenuView_LoadItemCategory,
  MenuBaseMenuView_LoadItemUid,
  MenuBaseMenuView_LoadItemToggle,
EW_END_OF_CLASS( UnitUNT03_FuelSettingMenu )

/* Initializer for the class 'Unit::UNT04_PressureSettingMenu' */
void UnitUNT04_PressureSettingMenu__Init( UnitUNT04_PressureSettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( UnitUNT04_PressureSettingMenu );

  /* ... then construct all embedded objects */
  CoreTimer__Init( &_this->CheckMarkUpdateTimer, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( UnitUNT04_PressureSettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 3 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsUNT04_UNIT_PRESSURE_KPA ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsUNT04_UNIT_PRESSURE_PSI ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &StringsUNT04_UNIT_PRESSURE_KGF ));
  CoreTimer_OnSetPeriod( &_this->CheckMarkUpdateTimer, 450 );
  _this->CheckMarkUpdateTimer.OnTrigger = EwNewSlot( _this, UnitUNT04_PressureSettingMenu_OnCheckMarkUpdateSlot );
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, UnitUNT04_PressureSettingMenu_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );
}

/* Re-Initializer for the class 'Unit::UNT04_PressureSettingMenu' */
void UnitUNT04_PressureSettingMenu__ReInit( UnitUNT04_PressureSettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreTimer__ReInit( &_this->CheckMarkUpdateTimer );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'Unit::UNT04_PressureSettingMenu' */
void UnitUNT04_PressureSettingMenu__Done( UnitUNT04_PressureSettingMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CoreTimer__Done( &_this->CheckMarkUpdateTimer );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Unit::UNT04_PressureSettingMenu.LoadItemClass()' */
XClass UnitUNT04_PressureSettingMenu_LoadItemClass( UnitUNT04_PressureSettingMenu _this, 
  XInt32 aItemNo )
{
  XClass ItemClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemClass = 0;

  if ( aItemNo >= 0 )
  {
    ItemClass = EW_CLASS( MenuItemCheckMark );
  }

  return ItemClass;
}

/* 'C' function for method : 'Unit::UNT04_PressureSettingMenu.LoadItemTitle()' */
XString UnitUNT04_PressureSettingMenu_LoadItemTitle( UnitUNT04_PressureSettingMenu _this, 
  XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < 3 )
  {
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 3 )];
  }

  return title;
}

/* 'C' function for method : 'Unit::UNT04_PressureSettingMenu.OnItemActivate()' */
void UnitUNT04_PressureSettingMenu_OnItemActivate( UnitUNT04_PressureSettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  switch ( aItemNo )
  {
    case 0 :
    {
      if ( EnumPressureSettingItemKPA == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentPressureSetting )
      {
        CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
      }
      else
      {
        DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypePRESSURE_UNIT, 1 );
      }
    }
    break;

    case 1 :
    {
      if ( EnumPressureSettingItemPSI == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentPressureSetting )
      {
        CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
      }
      else
      {
        DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypePRESSURE_UNIT, 0 );
      }
    }
    break;

    case 2 :
    {
      if ( EnumPressureSettingItemKGF == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentPressureSetting )
      {
        CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
      }
      else
      {
        DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypePRESSURE_UNIT, 2 );
      }
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Unit::UNT04_PressureSettingMenu.LoadItemChecked()' */
XBool UnitUNT04_PressureSettingMenu_LoadItemChecked( UnitUNT04_PressureSettingMenu _this, 
  XInt32 aItemNo )
{
  XBool IsChecked;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsChecked = 0;

  switch ( aItemNo )
  {
    case 0 :
    {
      if ( EnumPressureSettingItemKPA == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentPressureSetting )
      {
        IsChecked = 1;
      }
    }
    break;

    case 1 :
    {
      if ( EnumPressureSettingItemPSI == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentPressureSetting )
      {
        IsChecked = 1;
      }
    }
    break;

    case 2 :
    {
      if ( EnumPressureSettingItemKGF == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentPressureSetting )
      {
        IsChecked = 1;
      }
    }
    break;

    default : 
      ;
  }

  return IsChecked;
}

/* 'C' function for method : 'Unit::UNT04_PressureSettingMenu.OnCheckMarkUpdateSlot()' */
void UnitUNT04_PressureSettingMenu_OnCheckMarkUpdateSlot( UnitUNT04_PressureSettingMenu _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 0 );
  EwSignal( _this->PressureUpdateSignal, ((XObject)_this ));
  CoreVerticalList_OnSetSelectedItem( &_this->Super1.Menu.MenuList, 0 );
  MenuVerticalMenu_MoveFocusFrame( &_this->Super1.Menu );
  ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void UnitUNT04_PressureSettingMenu_OnVehicleDataReceivedSlot( UnitUNT04_PressureSettingMenu _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if (( VehicleData != 0 ) && ( EnumVehicleRxTypePRESSURE_UNIT == VehicleData->RxType ))
  {
    VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
    DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypePRESSURE_UNIT );

    switch ( VehicleData->DataUInt32 )
    {
      case 0 :
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentPressureSetting 
        = EnumPressureSettingItemPSI;
      break;

      case 1 :
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentPressureSetting 
        = EnumPressureSettingItemKPA;
      break;

      case 2 :
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentPressureSetting 
        = EnumPressureSettingItemKGF;
      break;

      default : 
        ;
    }

    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 2 );
    CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
  }
}

/* Variants derived from the class : 'Unit::UNT04_PressureSettingMenu' */
EW_DEFINE_CLASS_VARIANTS( UnitUNT04_PressureSettingMenu )
EW_END_OF_CLASS_VARIANTS( UnitUNT04_PressureSettingMenu )

/* Virtual Method Table (VMT) for the class : 'Unit::UNT04_PressureSettingMenu' */
EW_DEFINE_CLASS( UnitUNT04_PressureSettingMenu, MenuBaseMenuView, PressureUpdateSignal, 
                 PressureUpdateSignal, CheckMarkUpdateTimer, CheckMarkUpdateTimer, 
                 ItemTitleArray, _None, "Unit::UNT04_PressureSettingMenu" )
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
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  UnitUNT04_PressureSettingMenu_LoadItemClass,
  UnitUNT04_PressureSettingMenu_LoadItemTitle,
  UnitUNT04_PressureSettingMenu_OnItemActivate,
  UnitUNT04_PressureSettingMenu_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemBaseValue,
  MenuBaseMenuView_LoadItemMessage,
  MenuBaseMenuView_LoadItemReceivedTime,
  MenuBaseMenuView_LoadItemCategory,
  MenuBaseMenuView_LoadItemUid,
  MenuBaseMenuView_LoadItemToggle,
EW_END_OF_CLASS( UnitUNT04_PressureSettingMenu )

/* Initializer for the class 'Unit::UNT05_TemperatureSettingMenu' */
void UnitUNT05_TemperatureSettingMenu__Init( UnitUNT05_TemperatureSettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( UnitUNT05_TemperatureSettingMenu );

  /* ... then construct all embedded objects */
  CoreTimer__Init( &_this->CheckMarkUpdateTimer, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( UnitUNT05_TemperatureSettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 2 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 2 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsUNT05_UNIT_TEMPERATURE_C ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsUNT05_UNIT_TEMPERATURE_F ));
  CoreTimer_OnSetPeriod( &_this->CheckMarkUpdateTimer, 450 );
  _this->CheckMarkUpdateTimer.OnTrigger = EwNewSlot( _this, UnitUNT05_TemperatureSettingMenu_OnCheckMarkUpdateSlot );
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, UnitUNT05_TemperatureSettingMenu_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );
}

/* Re-Initializer for the class 'Unit::UNT05_TemperatureSettingMenu' */
void UnitUNT05_TemperatureSettingMenu__ReInit( UnitUNT05_TemperatureSettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreTimer__ReInit( &_this->CheckMarkUpdateTimer );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'Unit::UNT05_TemperatureSettingMenu' */
void UnitUNT05_TemperatureSettingMenu__Done( UnitUNT05_TemperatureSettingMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CoreTimer__Done( &_this->CheckMarkUpdateTimer );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Unit::UNT05_TemperatureSettingMenu.LoadItemClass()' */
XClass UnitUNT05_TemperatureSettingMenu_LoadItemClass( UnitUNT05_TemperatureSettingMenu _this, 
  XInt32 aItemNo )
{
  XClass ItemClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemClass = 0;

  if ( aItemNo >= 0 )
  {
    ItemClass = EW_CLASS( MenuItemCheckMark );
  }

  return ItemClass;
}

/* 'C' function for method : 'Unit::UNT05_TemperatureSettingMenu.LoadItemTitle()' */
XString UnitUNT05_TemperatureSettingMenu_LoadItemTitle( UnitUNT05_TemperatureSettingMenu _this, 
  XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < 2 )
  {
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 2 )];
  }

  return title;
}

/* 'C' function for method : 'Unit::UNT05_TemperatureSettingMenu.OnItemActivate()' */
void UnitUNT05_TemperatureSettingMenu_OnItemActivate( UnitUNT05_TemperatureSettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  switch ( aItemNo )
  {
    case 0 :
    {
      if ( EnumTemperatureSettingItemTEMP_C == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentTempSetting )
      {
        CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
      }
      else
      {
        DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeTEMPERATURE_UNIT, 
        0 );
      }
    }
    break;

    case 1 :
    {
      if ( EnumTemperatureSettingItemTEMP_F == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentTempSetting )
      {
        CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
      }
      else
      {
        DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeTEMPERATURE_UNIT, 
        1 );
      }
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Unit::UNT05_TemperatureSettingMenu.LoadItemChecked()' */
XBool UnitUNT05_TemperatureSettingMenu_LoadItemChecked( UnitUNT05_TemperatureSettingMenu _this, 
  XInt32 aItemNo )
{
  XBool IsChecked;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsChecked = 0;

  switch ( aItemNo )
  {
    case 0 :
    {
      if ( EnumTemperatureSettingItemTEMP_C == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentTempSetting )
      {
        IsChecked = 1;
      }
    }
    break;

    case 1 :
    {
      if ( EnumTemperatureSettingItemTEMP_F == EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
          DeviceInterfaceVehicleDeviceClass )->CurrentTempSetting )
      {
        IsChecked = 1;
      }
    }
    break;

    default : 
      ;
  }

  return IsChecked;
}

/* 'C' function for method : 'Unit::UNT05_TemperatureSettingMenu.OnCheckMarkUpdateSlot()' */
void UnitUNT05_TemperatureSettingMenu_OnCheckMarkUpdateSlot( UnitUNT05_TemperatureSettingMenu _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 0 );
  EwSignal( _this->TempUpdateSignal, ((XObject)_this ));
  CoreVerticalList_OnSetSelectedItem( &_this->Super1.Menu.MenuList, 0 );
  MenuVerticalMenu_MoveFocusFrame( &_this->Super1.Menu );
  ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void UnitUNT05_TemperatureSettingMenu_OnVehicleDataReceivedSlot( UnitUNT05_TemperatureSettingMenu _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if (( VehicleData != 0 ) && ( EnumVehicleRxTypeTEMPERATURE_UNIT == VehicleData->RxType ))
  {
    VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
    DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeTEMPERATURE_UNIT );

    switch ( VehicleData->DataUInt32 )
    {
      case 0 :
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentTempSetting 
        = EnumTemperatureSettingItemTEMP_C;
      break;

      case 1 :
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentTempSetting 
        = EnumTemperatureSettingItemTEMP_F;
      break;

      default : 
        ;
    }

    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 1 );
    CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
  }
}

/* Variants derived from the class : 'Unit::UNT05_TemperatureSettingMenu' */
EW_DEFINE_CLASS_VARIANTS( UnitUNT05_TemperatureSettingMenu )
EW_END_OF_CLASS_VARIANTS( UnitUNT05_TemperatureSettingMenu )

/* Virtual Method Table (VMT) for the class : 'Unit::UNT05_TemperatureSettingMenu' */
EW_DEFINE_CLASS( UnitUNT05_TemperatureSettingMenu, MenuBaseMenuView, TempUpdateSignal, 
                 TempUpdateSignal, CheckMarkUpdateTimer, CheckMarkUpdateTimer, ItemTitleArray, 
                 _None, "Unit::UNT05_TemperatureSettingMenu" )
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
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  UnitUNT05_TemperatureSettingMenu_LoadItemClass,
  UnitUNT05_TemperatureSettingMenu_LoadItemTitle,
  UnitUNT05_TemperatureSettingMenu_OnItemActivate,
  UnitUNT05_TemperatureSettingMenu_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemBaseValue,
  MenuBaseMenuView_LoadItemMessage,
  MenuBaseMenuView_LoadItemReceivedTime,
  MenuBaseMenuView_LoadItemCategory,
  MenuBaseMenuView_LoadItemUid,
  MenuBaseMenuView_LoadItemToggle,
EW_END_OF_CLASS( UnitUNT05_TemperatureSettingMenu )

/* Embedded Wizard */
