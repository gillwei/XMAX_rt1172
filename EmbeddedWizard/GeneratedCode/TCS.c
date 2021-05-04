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

/* Initializer for the class 'TCS::TCS01_Main' */
void TCSTCS01_Main__Init( TCSTCS01_Main _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( TCSTCS01_Main );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( TCSTCS01_Main );

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
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'TCS::TCS01_Main' */
void TCSTCS01_Main__Done( TCSTCS01_Main _this )
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
void TCSTCS01_Main_Init( TCSTCS01_Main _this, XHandle aArg )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeTC_MODE );

  if ( VehicleData != 0 )
  {
    _this->IsTCSEnabled = !!VehicleData->DataUInt32;
  }
}

/* 'C' function for method : 'TCS::TCS01_Main.LoadItemClass()' */
XClass TCSTCS01_Main_LoadItemClass( TCSTCS01_Main _this, XInt32 aItemNo )
{
  XClass ClassType = 0;

  if ( aItemNo < _this->Super1.Menu.NoOfItems )
  {
    ClassType = EW_CLASS( MenuItemCheckbox );
  }

  return ClassType;
}

/* 'C' function for method : 'TCS::TCS01_Main.LoadItemTitle()' */
XString TCSTCS01_Main_LoadItemTitle( TCSTCS01_Main _this, XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < _this->Super1.Menu.NoOfItems )
  {
    title = EwLoadString( &StringsTCS01_TCS );
  }

  return title;
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
  XBool IsChecked = 0;

  if ( aItemNo < _this->Super1.Menu.NoOfItems )
  {
    IsChecked = _this->IsTCSEnabled;
  }

  return IsChecked;
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

  if (( VehicleData != 0 ) && ( EnumVehicleRxTypeTC_MODE == VehicleData->RxType ))
  {
    VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
    DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeTC_MODE );

    if ( 1 == VehicleData->DataUInt32 )
    {
      _this->IsTCSEnabled = 1;
      MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 0 );
    }
    else
      if ( 0 == VehicleData->DataUInt32 )
      {
        _this->IsTCSEnabled = 0;
        MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 0 );
      }
      else
        ;
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
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemBaseValue,
  MenuBaseMenuView_LoadItemMessage,
  MenuBaseMenuView_LoadItemReceivedTime,
  MenuBaseMenuView_LoadItemCategory,
  MenuBaseMenuView_LoadItemUid,
  TCSTCS01_Main_LoadItemToggle,
  MenuBaseMenuView_LoadItemUnit,
  MenuBaseMenuView_LoadItemValue,
  MenuBaseMenuView_OnItemLongEnterKeyActivate,
EW_END_OF_CLASS( TCSTCS01_Main )

/* Embedded Wizard */
