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
#include "_CoreGroup.h"
#include "_CoreSystemEventHandler.h"
#include "_DeviceInterfaceVehicleDataClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_MaintenanceMNT01_MaintenanceReset.h"
#include "_MenuItemValueUnit.h"
#include "_MenuVerticalMenu.h"
#include "_PopPOP04_Reset.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Maintenance.h"
#include "Strings.h"

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault0[] =
{
  0x0000001E, /* ratio 133.33 % */
  0xB8001B00, 0x00092452, 0x00D20037, 0x040003A0, 0x9C002680, 0x0002A000, 0x00188006,
  0x10046A32, 0x00000010, 0x00000000
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

/* Initializer for the class 'Maintenance::MNT01_MaintenanceReset' */
void MaintenanceMNT01_MaintenanceReset__Init( MaintenanceMNT01_MaintenanceReset _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MaintenanceMNT01_MaintenanceReset );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MaintenanceMNT01_MaintenanceReset );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 74 );
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, MaintenanceMNT01_MaintenanceReset_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );

  /* Call the user defined constructor */
  MaintenanceMNT01_MaintenanceReset_Init( _this, aArg );
}

/* Re-Initializer for the class 'Maintenance::MNT01_MaintenanceReset' */
void MaintenanceMNT01_MaintenanceReset__ReInit( MaintenanceMNT01_MaintenanceReset _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'Maintenance::MNT01_MaintenanceReset' */
void MaintenanceMNT01_MaintenanceReset__Done( MaintenanceMNT01_MaintenanceReset _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void MaintenanceMNT01_MaintenanceReset_Init( MaintenanceMNT01_MaintenanceReset _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0000 ));
  MaintenanceMNT01_MaintenanceReset_SetNoOfMenuItems( _this );
  MaintenanceMNT01_MaintenanceReset_GetMileageSetting( _this );
}

/* 'C' function for method : 'Maintenance::MNT01_MaintenanceReset.LoadItemClass()' */
XClass MaintenanceMNT01_MaintenanceReset_LoadItemClass( MaintenanceMNT01_MaintenanceReset _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemValueUnit );
}

/* 'C' function for method : 'Maintenance::MNT01_MaintenanceReset.LoadItemTitle()' */
XString MaintenanceMNT01_MaintenanceReset_LoadItemTitle( MaintenanceMNT01_MaintenanceReset _this, 
  XInt32 aItemNo )
{
  XString Title = 0;

  switch ( _this->SupportedSetting[ EwCheckIndex( aItemNo, 3 )])
  {
    case EnumMaintenanceResetMenuItemOIL :
      Title = EwLoadString( &StringsMNT01_OIL );
    break;

    case EnumMaintenanceResetMenuItemV_BELT :
      Title = EwLoadString( &StringsMNT01_V_BELT );
    break;

    case EnumMaintenanceResetMenuItemFREE1 :
      Title = EwLoadString( &StringsMNT01_FREE1 );
    break;

    case EnumMaintenanceResetMenuItemFREE2 :
      Title = EwLoadString( &StringsMNT01_FREE2 );
    break;

    default :; 
  }

  return Title;
}

/* 'C' function for method : 'Maintenance::MNT01_MaintenanceReset.OnItemActivate()' */
void MaintenanceMNT01_MaintenanceReset_OnItemActivate( MaintenanceMNT01_MaintenanceReset _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  if ( 0 < _this->NoOfSupportedItem )
  {
    PopPOP04_Reset ResetDialog = EwNewObject( PopPOP04_Reset, 0 );
    ResetDialog->SelectedMeterInfo = EnumMeterInfoTOTAL;

    switch ( aItemNo )
    {
      case 0 :
        ResetDialog->SelectedMeterInfo = EnumMeterInfoMAINTENANCE_TRIP1;
      break;

      case 1 :
        ResetDialog->SelectedMeterInfo = EnumMeterInfoMAINTENANCE_TRIP2;
      break;

      case 2 :
        ResetDialog->SelectedMeterInfo = EnumMeterInfoMAINTENANCE_TRIP3;
      break;

      default :; 
    }

    if ( EnumMeterInfoTOTAL != ResetDialog->SelectedMeterInfo )
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)ResetDialog ), 0, 0, 
      0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* 'C' function for method : 'Maintenance::MNT01_MaintenanceReset.LoadItemUnit()' */
XString MaintenanceMNT01_MaintenanceReset_LoadItemUnit( MaintenanceMNT01_MaintenanceReset _this, 
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

/* 'C' function for method : 'Maintenance::MNT01_MaintenanceReset.LoadItemValue()' */
XString MaintenanceMNT01_MaintenanceReset_LoadItemValue( MaintenanceMNT01_MaintenanceReset _this, 
  XInt32 aItemNo )
{
  XString Value;
  DeviceInterfaceVehicleDataClass VehicleData = 0;
  XBool IsDataValid;

  if ( 0 < _this->NoOfSupportedItem )
  {
    VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
    DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeTIMEOUT_ERROR2_DETECTED );

    if ( 0 == VehicleData->DataUInt32 )
    {
      switch ( aItemNo )
      {
        case 0 :
          VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
          &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeMAINTENANCE_TRIP1 );
        break;

        case 1 :
          VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
          &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeMAINTENANCE_TRIP2 );
        break;

        case 2 :
          VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
          &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeMAINTENANCE_TRIP3 );
        break;

        default : 
          VehicleData->Valid = 0;
      }

      IsDataValid = VehicleData->Valid;
    }
    else
      IsDataValid = 0;
  }
  else
    IsDataValid = 0;

  if ( IsDataValid )
  {
    if ( EnumMileageSettingItemMILE == _this->MileageSetting )
      VehicleData->DataUInt32 = (XInt32)( VehicleData->DataUInt32 * 0.625000f );

    VehicleData->DataUInt32 = DeviceInterfaceVehicleDeviceClass_ClampDataUInt32( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    VehicleData->DataUInt32, 0, 99999 );
    Value = EwNewStringUInt( VehicleData->DataUInt32, 0, 0 );
  }
  else
    Value = EwLoadString( &StringsGEN_THREE_HYPHENS );

  return Value;
}

/* 'C' function for method : 'Maintenance::MNT01_MaintenanceReset.GetMileageSetting()' */
void MaintenanceMNT01_MaintenanceReset_GetMileageSetting( MaintenanceMNT01_MaintenanceReset _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeMILEAGE_UNIT );

  if ( 1 == VehicleData->DataUInt32 )
    _this->MileageSetting = EnumMileageSettingItemMILE;
  else
    _this->MileageSetting = EnumMileageSettingItemKM;
}

/* 'C' function for method : 'Maintenance::MNT01_MaintenanceReset.SetNoOfMenuItems()' */
void MaintenanceMNT01_MaintenanceReset_SetNoOfMenuItems( MaintenanceMNT01_MaintenanceReset _this )
{
  XInt32 i;
  XEnum SettingItem;

  _this->NoOfSupportedItem = 0;

  for ( i = 0; i < 4; i++ )
  {
    SettingItem = (XEnum)i;

    switch ( SettingItem )
    {
      case EnumMaintenanceResetMenuItemOIL :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionOIL_TRIP ))
        {
          _this->SupportedSetting[ EwCheckIndex( _this->NoOfSupportedItem, 3 )] 
          = SettingItem;
          _this->NoOfSupportedItem++;
        }
      break;

      case EnumMaintenanceResetMenuItemV_BELT :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionV_BELT_TRIP ))
        {
          _this->SupportedSetting[ EwCheckIndex( _this->NoOfSupportedItem, 3 )] 
          = SettingItem;
          _this->NoOfSupportedItem++;
        }
      break;

      case EnumMaintenanceResetMenuItemFREE1 :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionFREE_1 ))
        {
          _this->SupportedSetting[ EwCheckIndex( _this->NoOfSupportedItem, 3 )] 
          = SettingItem;
          _this->NoOfSupportedItem++;
        }
      break;

      case EnumMaintenanceResetMenuItemFREE2 :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionFREE_2 ))
        {
          _this->SupportedSetting[ EwCheckIndex( _this->NoOfSupportedItem, 3 )] 
          = SettingItem;
          _this->NoOfSupportedItem++;
        }
      break;

      default :; 
    }

    if ( 3 <= _this->NoOfSupportedItem )
      goto _EXIT_LOOP_1;
  }

  _EXIT_LOOP_1:

  if ( 0 == _this->NoOfSupportedItem )
  {
    _this->SupportedSetting[ EwCheckIndex( _this->NoOfSupportedItem, 3 )] = EnumMaintenanceResetMenuItemOIL;
    MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 1 );
  }
  else
    MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, _this->NoOfSupportedItem );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void MaintenanceMNT01_MaintenanceReset_OnVehicleDataReceivedSlot( MaintenanceMNT01_MaintenanceReset _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if ( VehicleData != 0 )
    switch ( VehicleData->RxType )
    {
      case EnumVehicleRxTypeMAINTENANCE_TRIP1 :
        MaintenanceMNT01_MaintenanceReset_ReloadItem( _this, 0 );
      break;

      case EnumVehicleRxTypeMAINTENANCE_TRIP2 :
        MaintenanceMNT01_MaintenanceReset_ReloadItem( _this, 1 );
      break;

      case EnumVehicleRxTypeMAINTENANCE_TRIP3 :
        MaintenanceMNT01_MaintenanceReset_ReloadItem( _this, 2 );
      break;

      case EnumVehicleRxTypeTIMEOUT_ERROR2_DETECTED :
      case EnumVehicleRxTypeTIMEOUT_ERROR2_RECOVERED :
        MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, _this->Super1.Menu.NoOfItems 
        - 1 );
      break;

      default :; 
    }
}

/* 'C' function for method : 'Maintenance::MNT01_MaintenanceReset.ReloadItem()' */
void MaintenanceMNT01_MaintenanceReset_ReloadItem( MaintenanceMNT01_MaintenanceReset _this, 
  XInt32 aItemNo )
{
  if ( aItemNo < _this->Super1.Menu.NoOfItems )
    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, aItemNo, aItemNo );
}

/* Variants derived from the class : 'Maintenance::MNT01_MaintenanceReset' */
EW_DEFINE_CLASS_VARIANTS( MaintenanceMNT01_MaintenanceReset )
EW_END_OF_CLASS_VARIANTS( MaintenanceMNT01_MaintenanceReset )

/* Virtual Method Table (VMT) for the class : 'Maintenance::MNT01_MaintenanceReset' */
EW_DEFINE_CLASS( MaintenanceMNT01_MaintenanceReset, MenuBaseMenuView, VehicleDataReceivedEventHandler, 
                 VehicleDataReceivedEventHandler, VehicleDataReceivedEventHandler, 
                 VehicleDataReceivedEventHandler, NoOfSupportedItem, NoOfSupportedItem, 
                 "Maintenance::MNT01_MaintenanceReset" )
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
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  MenuBaseMenuView_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  MaintenanceMNT01_MaintenanceReset_LoadItemClass,
  MaintenanceMNT01_MaintenanceReset_LoadItemTitle,
  MaintenanceMNT01_MaintenanceReset_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemBaseValue,
  MenuBaseMenuView_LoadItemMessage,
  MenuBaseMenuView_LoadItemReceivedTime,
  MenuBaseMenuView_LoadItemCategory,
  MenuBaseMenuView_LoadItemUid,
  MenuBaseMenuView_LoadItemToggle,
  MaintenanceMNT01_MaintenanceReset_LoadItemUnit,
  MaintenanceMNT01_MaintenanceReset_LoadItemValue,
  MenuBaseMenuView_OnItemLongEnterKeyActivate,
  MenuBaseMenuView_LoadItemHour,
  MenuBaseMenuView_LoadItemMinute,
  MenuBaseMenuView_LoadPoiListItemValue,
  MenuBaseMenuView_LoadPoiListItemUnit,
EW_END_OF_CLASS( MaintenanceMNT01_MaintenanceReset )

/* Embedded Wizard */
