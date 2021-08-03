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
#include "_CoreSystemEventHandler.h"
#include "_DeviceInterfaceVehicleDataClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_MenuItemCheckbox.h"
#include "_MenuVerticalMenu.h"
#include "_TCSTCS01_Main.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Strings.h"
#include "TCS.h"

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault0[] =
{
  0x00000014, /* ratio 140.00 % */
  0xB8001100, 0x800A8452, 0x00A60021, 0x06200180, 0x01108780, 0x00000404, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XStringRes _Const0000 = { _StringsDefault0, 0x0002 };

/* Initializer for the class 'TCS::TCS01_Main' */
void TCSTCS01_Main__Init( TCSTCS01_Main _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( TCSTCS01_Main );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( TCSTCS01_Main );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 1 );
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, TCSTCS01_Main_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );

  /* Call the user defined constructor */
  TCSTCS01_Main_Init( _this, aArg );
}

/* Re-Initializer for the class 'TCS::TCS01_Main' */
void TCSTCS01_Main__ReInit( TCSTCS01_Main _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'TCS::TCS01_Main' */
void TCSTCS01_Main__Done( TCSTCS01_Main _this )
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
void TCSTCS01_Main_Init( TCSTCS01_Main _this, XHandle aArg )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0000 ));
  VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeTC_MODE );

  if ( VehicleData != 0 )
    _this->IsTCSEnabled = !!VehicleData->DataUInt32;
}

/* 'C' function for method : 'TCS::TCS01_Main.LoadItemClass()' */
XClass TCSTCS01_Main_LoadItemClass( TCSTCS01_Main _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemCheckbox );
}

/* 'C' function for method : 'TCS::TCS01_Main.LoadItemTitle()' */
XString TCSTCS01_Main_LoadItemTitle( TCSTCS01_Main _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EwGetVariantOfString( &StringsTCS01_TCS );
}

/* 'C' function for method : 'TCS::TCS01_Main.OnItemActivate()' */
void TCSTCS01_Main_OnItemActivate( TCSTCS01_Main _this, XInt32 aItemNo, MenuItemBase 
  aMenuItem )
{
  MenuItemCheckbox CheckBoxItem;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aItemNo );

  CheckBoxItem = EwCastObject( aMenuItem, MenuItemCheckbox );

  if ( CheckBoxItem != 0 )
  {
    if ( CheckBoxItem->Checked )
    {
      _this->IsTCSEnabled = 0;
      DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
      DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeTCS, 0 );
    }
    else
    {
      _this->IsTCSEnabled = 1;
      DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
      DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeTCS, 1 );
    }
  }
}

/* 'C' function for method : 'TCS::TCS01_Main.LoadItemChecked()' */
XBool TCSTCS01_Main_LoadItemChecked( TCSTCS01_Main _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aItemNo );

  return _this->IsTCSEnabled;
}

/* 'C' function for method : 'TCS::TCS01_Main.LoadItemEnabled()' */
XBool TCSTCS01_Main_LoadItemEnabled( TCSTCS01_Main _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return (XBool)!DeviceInterfaceVehicleDeviceClass_OnGetIsTimeoutError2Detected( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
}

/* 'C' function for method : 'TCS::TCS01_Main.LoadItemToggle()' */
XBool TCSTCS01_Main_LoadItemToggle( TCSTCS01_Main _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return 0;
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void TCSTCS01_Main_OnVehicleDataReceivedSlot( TCSTCS01_Main _this, XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if ( VehicleData != 0 )
    switch ( VehicleData->RxType )
    {
      case EnumVehicleRxTypeTC_MODE :
      {
        VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
        &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeTC_MODE );

        if ( 1 == VehicleData->DataUInt32 )
          _this->IsTCSEnabled = 1;
        else
          if ( 0 == VehicleData->DataUInt32 )
            _this->IsTCSEnabled = 0;

        MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 0 );
      }
      break;

      case EnumVehicleRxTypeTIMEOUT_ERROR2_UPDATED :
        MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 0 );
      break;

      default :; 
    }
}

/* Variants derived from the class : 'TCS::TCS01_Main' */
EW_DEFINE_CLASS_VARIANTS( TCSTCS01_Main )
EW_END_OF_CLASS_VARIANTS( TCSTCS01_Main )

/* Virtual Method Table (VMT) for the class : 'TCS::TCS01_Main' */
EW_DEFINE_CLASS( TCSTCS01_Main, MenuBaseMenuView, VehicleDataReceivedEventHandler, 
                 VehicleDataReceivedEventHandler, VehicleDataReceivedEventHandler, 
                 VehicleDataReceivedEventHandler, IsTCSEnabled, IsTCSEnabled, "TCS::TCS01_Main" )
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
  TCSTCS01_Main_LoadItemClass,
  TCSTCS01_Main_LoadItemTitle,
  TCSTCS01_Main_OnItemActivate,
  TCSTCS01_Main_LoadItemChecked,
  TCSTCS01_Main_LoadItemEnabled,
  MenuBaseMenuView_LoadItemBaseValue,
  MenuBaseMenuView_LoadItemMessage,
  MenuBaseMenuView_LoadItemReceivedTime,
  MenuBaseMenuView_LoadItemCategory,
  MenuBaseMenuView_LoadItemUid,
  TCSTCS01_Main_LoadItemToggle,
  MenuBaseMenuView_LoadItemUnit,
  MenuBaseMenuView_LoadItemValue,
  MenuBaseMenuView_OnItemLongEnterKeyActivate,
  MenuBaseMenuView_LoadItemHour,
  MenuBaseMenuView_LoadItemMinute,
  MenuBaseMenuView_LoadPoiListItemValue,
  MenuBaseMenuView_LoadPoiListItemUnit,
  MenuBaseMenuView_LoadItemIcon1Visible,
  MenuBaseMenuView_LoadItemIcon2Visible,
  MenuBaseMenuView_LoadItemDeviceAddress,
EW_END_OF_CLASS( TCSTCS01_Main )

/* Embedded Wizard */
