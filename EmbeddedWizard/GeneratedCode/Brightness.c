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
#include "_BrightnessBRT01_BrightnessSettingMenu.h"
#include "_BrightnessBRT02_TFTBrightness.h"
#include "_BrightnessBRT03_MeterBrightness.h"
#include "_ComponentsBaseMainBG.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreView.h"
#include "_DeviceInterfaceSystemData.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_DeviceInterfaceVehicleDataClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_MenuItemBase.h"
#include "_MenuVerticalMenu.h"
#include "_ResourcesBitmap.h"
#include "_ViewsImage.h"
#include "Brightness.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Resource.h"
#include "Strings.h"

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0001 = {{ 45, 60 }, { 435, 231 }};
static const XRect _Const0002 = {{ 173, 205 }, { 307, 224 }};
static const XRect _Const0003 = {{ 173, 135 }, { 307, 154 }};
static const XRect _Const0004 = {{ 173, 65 }, { 307, 84 }};
static const XRect _Const0005 = {{ 179, 83 }, { 301, 205 }};
static const XRect _Const0006 = {{ 173, 177 }, { 307, 193 }};
static const XRect _Const0007 = {{ 173, 149 }, { 307, 168 }};
static const XRect _Const0008 = {{ 173, 121 }, { 307, 141 }};
static const XRect _Const0009 = {{ 173, 93 }, { 307, 112 }};

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

/* Initializer for the class 'Brightness::BRT01_BrightnessSettingMenu' */
void BrightnessBRT01_BrightnessSettingMenu__Init( BrightnessBRT01_BrightnessSettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( BrightnessBRT01_BrightnessSettingMenu );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( BrightnessBRT01_BrightnessSettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 9 );
  MenuVerticalMenu_OnSetArrowScrollBarVisible( &_this->Super1.Menu, 1 );

  /* Call the user defined constructor */
  BrightnessBRT01_BrightnessSettingMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Brightness::BRT01_BrightnessSettingMenu' */
void BrightnessBRT01_BrightnessSettingMenu__ReInit( BrightnessBRT01_BrightnessSettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Brightness::BRT01_BrightnessSettingMenu' */
void BrightnessBRT01_BrightnessSettingMenu__Done( BrightnessBRT01_BrightnessSettingMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void BrightnessBRT01_BrightnessSettingMenu_Init( BrightnessBRT01_BrightnessSettingMenu _this, 
  XHandle aArg )
{
  XInt32 NoOfItems;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  NoOfItems = 1;

  if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleSupportedFunctionMETER_BRIGHTNESS_ADJ ))
    NoOfItems++;

  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, NoOfItems );
}

/* 'C' function for method : 'Brightness::BRT01_BrightnessSettingMenu.LoadItemClass()' */
XClass BrightnessBRT01_BrightnessSettingMenu_LoadItemClass( BrightnessBRT01_BrightnessSettingMenu _this, 
  XInt32 aItemNo )
{
  XClass ItemClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemClass = 0;

  if ( aItemNo >= 0 )
    ItemClass = EW_CLASS( MenuItemBase );

  return ItemClass;
}

/* 'C' function for method : 'Brightness::BRT01_BrightnessSettingMenu.LoadItemTitle()' */
XString BrightnessBRT01_BrightnessSettingMenu_LoadItemTitle( BrightnessBRT01_BrightnessSettingMenu _this, 
  XInt32 aItemNo )
{
  XString Title;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Title = 0;

  switch ( aItemNo )
  {
    case 0 :
      Title = EwLoadString( &StringsBRT01_TFT_DISPLAY );
    break;

    case 1 :
      Title = EwLoadString( &StringsBRT01_SPEED_METER );
    break;

    default :; 
  }

  return Title;
}

/* 'C' function for method : 'Brightness::BRT01_BrightnessSettingMenu.OnItemActivate()' */
void BrightnessBRT01_BrightnessSettingMenu_OnItemActivate( BrightnessBRT01_BrightnessSettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  switch ( aItemNo )
  {
    case 0 :
      ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)EwNewObject( 
      BrightnessBRT02_TFTBrightness, 0 )));
    break;

    case 1 :
      ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)EwNewObject( 
      BrightnessBRT03_MeterBrightness, 0 )));
    break;

    default :; 
  }
}

/* Variants derived from the class : 'Brightness::BRT01_BrightnessSettingMenu' */
EW_DEFINE_CLASS_VARIANTS( BrightnessBRT01_BrightnessSettingMenu )
EW_END_OF_CLASS_VARIANTS( BrightnessBRT01_BrightnessSettingMenu )

/* Virtual Method Table (VMT) for the class : 'Brightness::BRT01_BrightnessSettingMenu' */
EW_DEFINE_CLASS( BrightnessBRT01_BrightnessSettingMenu, MenuBaseMenuView, _.VMT, 
                 _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, "Brightness::BRT01_BrightnessSettingMenu" )
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
  BrightnessBRT01_BrightnessSettingMenu_LoadItemClass,
  BrightnessBRT01_BrightnessSettingMenu_LoadItemTitle,
  BrightnessBRT01_BrightnessSettingMenu_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
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
EW_END_OF_CLASS( BrightnessBRT01_BrightnessSettingMenu )

/* Initializer for the class 'Brightness::BRT02_TFTBrightness' */
void BrightnessBRT02_TFTBrightness__Init( BrightnessBRT02_TFTBrightness _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( BrightnessBRT02_TFTBrightness );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->Base, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->LevelBar, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->HighTempImage, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ReceivedSystemEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( BrightnessBRT02_TFTBrightness );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super1.SlideOutEffectEnabled = 1;
  CoreRectView__OnSetBounds( &_this->Base, _Const0001 );
  _this->LevelBarBounds[ 0 ] = _Const0002;
  _this->LevelBarBounds[ 1 ] = _Const0003;
  _this->LevelBarBounds[ 2 ] = _Const0004;
  CoreRectView__OnSetBounds( &_this->LevelBar, _Const0004 );
  ViewsImage_OnSetFrameNumber( &_this->LevelBar, 1 );
  ViewsImage_OnSetVisible( &_this->LevelBar, 0 );
  CoreRectView__OnSetBounds( &_this->HighTempImage, _Const0005 );
  ViewsImage_OnSetVisible( &_this->HighTempImage, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Base ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LevelBar ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->HighTempImage ), 0 );
  ViewsImage_OnSetBitmap( &_this->Base, EwLoadResource( &ResourceTFTBrightnessBase, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->LevelBar, EwLoadResource( &ResourceBrightnessBar, 
  ResourcesBitmap ));
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, BrightnessBRT02_TFTBrightness_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );
  ViewsImage_OnSetBitmap( &_this->HighTempImage, EwLoadResource( &ResourceHighTemperature, 
  ResourcesBitmap ));
  _this->ReceivedSystemEventHandler.OnEvent = EwNewSlot( _this, BrightnessBRT02_TFTBrightness_OnSystemEventReceived );
  CoreSystemEventHandler_OnSetEvent( &_this->ReceivedSystemEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->SystemDataReceivedSystemEvent );

  /* Call the user defined constructor */
  BrightnessBRT02_TFTBrightness_Init( _this, aArg );
}

/* Re-Initializer for the class 'Brightness::BRT02_TFTBrightness' */
void BrightnessBRT02_TFTBrightness__ReInit( BrightnessBRT02_TFTBrightness _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->Base );
  ViewsImage__ReInit( &_this->LevelBar );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
  ViewsImage__ReInit( &_this->HighTempImage );
  CoreSystemEventHandler__ReInit( &_this->ReceivedSystemEventHandler );
}

/* Finalizer method for the class 'Brightness::BRT02_TFTBrightness' */
void BrightnessBRT02_TFTBrightness__Done( BrightnessBRT02_TFTBrightness _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->Base );
  ViewsImage__Done( &_this->LevelBar );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );
  ViewsImage__Done( &_this->HighTempImage );
  CoreSystemEventHandler__Done( &_this->ReceivedSystemEventHandler );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void BrightnessBRT02_TFTBrightness_Init( BrightnessBRT02_TFTBrightness _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  BrightnessBRT02_TFTBrightness_UpdateBrightnessLevel( _this );
  BrightnessBRT02_TFTBrightness_OnSetIsDeratingOn( _this, !!DeviceInterfaceSystemDeviceClass_GetSystemStatus( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ), 
  EnumSystemStatusIS_TFT_DERATING_ON ));
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
void BrightnessBRT02_TFTBrightness_UpdateViewState( BrightnessBRT02_TFTBrightness _this, 
  XSet aState )
{
  CoreGroup_UpdateViewState((CoreGroup)_this, aState );

  if (( 1 <= _this->BrightnessLevel ) && ( 3 >= _this->BrightnessLevel ))
  {
    CoreRectView__OnSetBounds( &_this->LevelBar, _this->LevelBarBounds[ EwCheckIndex((XInt32)_this->BrightnessLevel 
    - 1, 3 )]);
    ViewsImage_OnSetVisible( &_this->LevelBar, 1 );
  }
}

/* 'C' function for method : 'Brightness::BRT02_TFTBrightness.OnShortDownKeyActivated()' */
void BrightnessBRT02_TFTBrightness_OnShortDownKeyActivated( BrightnessBRT02_TFTBrightness _this )
{
  if ( !_this->IsDeratingOn && ( 1 < _this->BrightnessLevel ))
    DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
    DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeTFT_BRIGHTNESS_OPERATION, 
    1 );
}

/* 'C' function for method : 'Brightness::BRT02_TFTBrightness.OnShortUpKeyActivated()' */
void BrightnessBRT02_TFTBrightness_OnShortUpKeyActivated( BrightnessBRT02_TFTBrightness _this )
{
  if ( !_this->IsDeratingOn && ( 3 > _this->BrightnessLevel ))
    DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
    DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeTFT_BRIGHTNESS_OPERATION, 
    2 );
}

/* 'C' function for method : 'Brightness::BRT02_TFTBrightness.OnShortEnterKeyActivated()' */
void BrightnessBRT02_TFTBrightness_OnShortEnterKeyActivated( BrightnessBRT02_TFTBrightness _this )
{
  ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
}

/* Callback when down key of on trigger mode is released */
void BrightnessBRT02_TFTBrightness_OnDownKeyReleased( BrightnessBRT02_TFTBrightness _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeTFT_BRIGHTNESS_OPERATION, 
  0 );
}

/* Callback when up key of on trigger mode is released */
void BrightnessBRT02_TFTBrightness_OnUpKeyReleased( BrightnessBRT02_TFTBrightness _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeTFT_BRIGHTNESS_OPERATION, 
  0 );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void BrightnessBRT02_TFTBrightness_OnVehicleDataReceivedSlot( BrightnessBRT02_TFTBrightness _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if (( VehicleData != 0 ) && ( EnumVehicleRxTypeTFT_BRIGHTNESS_LEVEL == VehicleData->RxType ))
    BrightnessBRT02_TFTBrightness_UpdateBrightnessLevel( _this );
}

/* 'C' function for method : 'Brightness::BRT02_TFTBrightness.UpdateBrightnessLevel()' */
void BrightnessBRT02_TFTBrightness_UpdateBrightnessLevel( BrightnessBRT02_TFTBrightness _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeTFT_BRIGHTNESS_LEVEL );

  if ( _this->BrightnessLevel != VehicleData->DataUInt32 )
  {
    _this->BrightnessLevel = VehicleData->DataUInt32;
    CoreGroup_InvalidateViewState((CoreGroup)_this );
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void BrightnessBRT02_TFTBrightness_OnSystemEventReceived( BrightnessBRT02_TFTBrightness _this, 
  XObject sender )
{
  DeviceInterfaceSystemData SystemData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  SystemData = EwCastObject( _this->ReceivedSystemEventHandler.Context, DeviceInterfaceSystemData );

  if ( SystemData != 0 )
    switch ( SystemData->RxEvent )
    {
      case EnumSystemRxEventTFT_DERATING_OFF :
        BrightnessBRT02_TFTBrightness_OnSetIsDeratingOn( _this, 0 );
      break;

      case EnumSystemRxEventTFT_DERATING_ON :
        BrightnessBRT02_TFTBrightness_OnSetIsDeratingOn( _this, 1 );
      break;

      default :; 
    }
}

/* 'C' function for method : 'Brightness::BRT02_TFTBrightness.OnSetIsDeratingOn()' */
void BrightnessBRT02_TFTBrightness_OnSetIsDeratingOn( BrightnessBRT02_TFTBrightness _this, 
  XBool value )
{
  if ( _this->IsDeratingOn != value )
  {
    _this->IsDeratingOn = value;

    if ( value )
      ViewsImage_OnSetFrameNumber( &_this->LevelBar, 0 );
    else
      ViewsImage_OnSetFrameNumber( &_this->LevelBar, 1 );

    ViewsImage_OnSetVisible( &_this->HighTempImage, value );
  }
}

/* Variants derived from the class : 'Brightness::BRT02_TFTBrightness' */
EW_DEFINE_CLASS_VARIANTS( BrightnessBRT02_TFTBrightness )
EW_END_OF_CLASS_VARIANTS( BrightnessBRT02_TFTBrightness )

/* Virtual Method Table (VMT) for the class : 'Brightness::BRT02_TFTBrightness' */
EW_DEFINE_CLASS( BrightnessBRT02_TFTBrightness, ComponentsBaseMainBG, Base, Base, 
                 Base, Base, LevelBarBounds, LevelBarBounds, "Brightness::BRT02_TFTBrightness" )
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
  BrightnessBRT02_TFTBrightness_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  BrightnessBRT02_TFTBrightness_OnShortDownKeyActivated,
  BrightnessBRT02_TFTBrightness_OnShortUpKeyActivated,
  BrightnessBRT02_TFTBrightness_OnShortEnterKeyActivated,
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  BrightnessBRT02_TFTBrightness_OnDownKeyReleased,
  BrightnessBRT02_TFTBrightness_OnUpKeyReleased,
EW_END_OF_CLASS( BrightnessBRT02_TFTBrightness )

/* Initializer for the class 'Brightness::BRT03_MeterBrightness' */
void BrightnessBRT03_MeterBrightness__Init( BrightnessBRT03_MeterBrightness _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( BrightnessBRT03_MeterBrightness );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->Base, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->LevelBar, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( BrightnessBRT03_MeterBrightness );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super1.SlideOutEffectEnabled = 1;
  CoreRectView__OnSetBounds( &_this->Base, _Const0001 );
  CoreRectView__OnSetBounds( &_this->LevelBar, _Const0002 );
  ViewsImage_OnSetFrameNumber( &_this->LevelBar, 1 );
  ViewsImage_OnSetVisible( &_this->LevelBar, 0 );
  _this->LevelBarBounds[ 0 ] = _Const0002;
  _this->LevelBarBounds[ 1 ] = _Const0006;
  _this->LevelBarBounds[ 2 ] = _Const0007;
  _this->LevelBarBounds[ 3 ] = _Const0008;
  _this->LevelBarBounds[ 4 ] = _Const0009;
  _this->LevelBarBounds[ 5 ] = _Const0004;
  CoreGroup__Add( _this, ((CoreView)&_this->Base ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LevelBar ), 0 );
  ViewsImage_OnSetBitmap( &_this->Base, EwLoadResource( &ResourceMeterBrightnessBase, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->LevelBar, EwLoadResource( &ResourceBrightnessBar, 
  ResourcesBitmap ));
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, BrightnessBRT03_MeterBrightness_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );

  /* Call the user defined constructor */
  BrightnessBRT03_MeterBrightness_Init( _this, aArg );
}

/* Re-Initializer for the class 'Brightness::BRT03_MeterBrightness' */
void BrightnessBRT03_MeterBrightness__ReInit( BrightnessBRT03_MeterBrightness _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->Base );
  ViewsImage__ReInit( &_this->LevelBar );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'Brightness::BRT03_MeterBrightness' */
void BrightnessBRT03_MeterBrightness__Done( BrightnessBRT03_MeterBrightness _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->Base );
  ViewsImage__Done( &_this->LevelBar );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void BrightnessBRT03_MeterBrightness_Init( BrightnessBRT03_MeterBrightness _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  BrightnessBRT03_MeterBrightness_UpdateBrightnessLevel( _this );
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
void BrightnessBRT03_MeterBrightness_UpdateViewState( BrightnessBRT03_MeterBrightness _this, 
  XSet aState )
{
  CoreGroup_UpdateViewState((CoreGroup)_this, aState );

  if (( 1 <= _this->BrightnessLevel ) && ( 6 >= _this->BrightnessLevel ))
  {
    CoreRectView__OnSetBounds( &_this->LevelBar, _this->LevelBarBounds[ EwCheckIndex((XInt32)_this->BrightnessLevel 
    - 1, 6 )]);
    ViewsImage_OnSetVisible( &_this->LevelBar, 1 );
  }
}

/* 'C' function for method : 'Brightness::BRT03_MeterBrightness.OnShortDownKeyActivated()' */
void BrightnessBRT03_MeterBrightness_OnShortDownKeyActivated( BrightnessBRT03_MeterBrightness _this )
{
  if ( 1 < _this->BrightnessLevel )
    DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
    DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeMETER_BRIGHTNESS_OPERATION, 
    1 );
}

/* 'C' function for method : 'Brightness::BRT03_MeterBrightness.OnShortUpKeyActivated()' */
void BrightnessBRT03_MeterBrightness_OnShortUpKeyActivated( BrightnessBRT03_MeterBrightness _this )
{
  if ( 6 > _this->BrightnessLevel )
    DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
    DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeMETER_BRIGHTNESS_OPERATION, 
    2 );
}

/* 'C' function for method : 'Brightness::BRT03_MeterBrightness.OnShortEnterKeyActivated()' */
void BrightnessBRT03_MeterBrightness_OnShortEnterKeyActivated( BrightnessBRT03_MeterBrightness _this )
{
  ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
}

/* Callback when down key of on trigger mode is released */
void BrightnessBRT03_MeterBrightness_OnDownKeyReleased( BrightnessBRT03_MeterBrightness _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeMETER_BRIGHTNESS_OPERATION, 
  0 );
}

/* Callback when up key of on trigger mode is released */
void BrightnessBRT03_MeterBrightness_OnUpKeyReleased( BrightnessBRT03_MeterBrightness _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeMETER_BRIGHTNESS_OPERATION, 
  0 );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void BrightnessBRT03_MeterBrightness_OnVehicleDataReceivedSlot( BrightnessBRT03_MeterBrightness _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if (( VehicleData != 0 ) && ( EnumVehicleRxTypeMETER_BRIGHTNESS_LEVEL == VehicleData->RxType ))
    BrightnessBRT03_MeterBrightness_UpdateBrightnessLevel( _this );
}

/* 'C' function for method : 'Brightness::BRT03_MeterBrightness.UpdateBrightnessLevel()' */
void BrightnessBRT03_MeterBrightness_UpdateBrightnessLevel( BrightnessBRT03_MeterBrightness _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeMETER_BRIGHTNESS_LEVEL );

  if ( _this->BrightnessLevel != VehicleData->DataUInt32 )
  {
    _this->BrightnessLevel = VehicleData->DataUInt32;
    CoreGroup_InvalidateViewState((CoreGroup)_this );
  }
}

/* Variants derived from the class : 'Brightness::BRT03_MeterBrightness' */
EW_DEFINE_CLASS_VARIANTS( BrightnessBRT03_MeterBrightness )
EW_END_OF_CLASS_VARIANTS( BrightnessBRT03_MeterBrightness )

/* Virtual Method Table (VMT) for the class : 'Brightness::BRT03_MeterBrightness' */
EW_DEFINE_CLASS( BrightnessBRT03_MeterBrightness, ComponentsBaseMainBG, Base, Base, 
                 Base, Base, BrightnessLevel, BrightnessLevel, "Brightness::BRT03_MeterBrightness" )
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
  BrightnessBRT03_MeterBrightness_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  BrightnessBRT03_MeterBrightness_OnShortDownKeyActivated,
  BrightnessBRT03_MeterBrightness_OnShortUpKeyActivated,
  BrightnessBRT03_MeterBrightness_OnShortEnterKeyActivated,
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  BrightnessBRT03_MeterBrightness_OnDownKeyReleased,
  BrightnessBRT03_MeterBrightness_OnUpKeyReleased,
EW_END_OF_CLASS( BrightnessBRT03_MeterBrightness )

/* Embedded Wizard */
