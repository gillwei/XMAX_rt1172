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
#include "_CoreGroup.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreView.h"
#include "_DeviceInterfaceVehicleDataClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_MenuItemBaseValue.h"
#include "_MenuVerticalMenu.h"
#include "_ResourcesBitmap.h"
#include "_SeatHeater_GripWarmerSHT02_GPW02_Main.h"
#include "_SeatHeater_GripWarmerScaleIndicator.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Resource.h"
#include "SeatHeater_GripWarmer.h"
#include "Strings.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000040, /* ratio 93.75 % */
  0xB8003D00, 0x000AA452, 0x00CA0037, 0x4E0003C0, 0x00630042, 0x064879D0, 0x76000800,
  0x9001A21E, 0x36002206, 0x019A2F0F, 0xC7A0E750, 0x98DF1D89, 0x65B2C004, 0x00000040,
  0x00000000
};

/* Constant values used in this 'C' module only. */
static const XStringRes _Const0000 = { _StringsDefault0, 0x0002 };
static const XRect _Const0001 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0002 = {{ 193, 39 }, { 395, 268 }};
static const XRect _Const0003 = {{ 230, 219 }, { 355, 238 }};
static const XRect _Const0004 = {{ 0, 0 }, { 0, 0 }};

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

/* Initializer for the class 'SeatHeater_GripWarmer::SHT02_GPW02_Main' */
void SeatHeater_GripWarmerSHT02_GPW02_Main__Init( SeatHeater_GripWarmerSHT02_GPW02_Main _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SeatHeater_GripWarmerSHT02_GPW02_Main );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SeatHeater_GripWarmerSHT02_GPW02_Main );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 3 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsGEN_LOW ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsGEN_MIDDLE ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &StringsGEN_HIGH ));
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, SeatHeater_GripWarmerSHT02_GPW02_Main_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );

  /* Call the user defined constructor */
  SeatHeater_GripWarmerSHT02_GPW02_Main_Init( _this, aArg );
}

/* Re-Initializer for the class 'SeatHeater_GripWarmer::SHT02_GPW02_Main' */
void SeatHeater_GripWarmerSHT02_GPW02_Main__ReInit( SeatHeater_GripWarmerSHT02_GPW02_Main _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'SeatHeater_GripWarmer::SHT02_GPW02_Main' */
void SeatHeater_GripWarmerSHT02_GPW02_Main__Done( SeatHeater_GripWarmerSHT02_GPW02_Main _this )
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
void SeatHeater_GripWarmerSHT02_GPW02_Main_Init( SeatHeater_GripWarmerSHT02_GPW02_Main _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  _this->ScaleIndicator = EwNewObject( SeatHeater_GripWarmerScaleIndicator, 0 );

  if ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
      == EnumVehicleSupportedFunctionSEAT_HEATER )
  {
    SeatHeater_GripWarmerSHT02_GPW02_Main_UpdateLevel( _this, EnumVehicleRxTypeSEAT_HEATER_VALUE_LOW );
    SeatHeater_GripWarmerSHT02_GPW02_Main_UpdateLevel( _this, EnumVehicleRxTypeSEAT_HEATER_VALUE_MIDDLE );
    SeatHeater_GripWarmerSHT02_GPW02_Main_UpdateLevel( _this, EnumVehicleRxTypeSEAT_HEATER_VALUE_HIGH );
  }
  else
    if ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
        == EnumVehicleSupportedFunctionGRIP_WARMER )
    {
      SeatHeater_GripWarmerSHT02_GPW02_Main_UpdateLevel( _this, EnumVehicleRxTypeGRIP_WARMER_VALUE_LOW );
      SeatHeater_GripWarmerSHT02_GPW02_Main_UpdateLevel( _this, EnumVehicleRxTypeGRIP_WARMER_VALUE_MIDDLE );
      SeatHeater_GripWarmerSHT02_GPW02_Main_UpdateLevel( _this, EnumVehicleRxTypeGRIP_WARMER_VALUE_HIGH );
    }
    else
    {
      EwTrace( "%s", EwLoadString( &_Const0000 ));
    }
}

/* 'C' function for method : 'SeatHeater_GripWarmer::SHT02_GPW02_Main.LoadItemClass()' */
XClass SeatHeater_GripWarmerSHT02_GPW02_Main_LoadItemClass( SeatHeater_GripWarmerSHT02_GPW02_Main _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( !!aItemNo )
    ;

  return EW_CLASS( MenuItemBaseValue );
}

/* 'C' function for method : 'SeatHeater_GripWarmer::SHT02_GPW02_Main.LoadItemTitle()' */
XString SeatHeater_GripWarmerSHT02_GPW02_Main_LoadItemTitle( SeatHeater_GripWarmerSHT02_GPW02_Main _this, 
  XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < 3 )
  {
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 3 )];
  }

  return title;
}

/* 'C' function for method : 'SeatHeater_GripWarmer::SHT02_GPW02_Main.OnItemActivate()' */
void SeatHeater_GripWarmerSHT02_GPW02_Main_OnItemActivate( SeatHeater_GripWarmerSHT02_GPW02_Main _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  if ( aMenuItem == 0 )
    ;

  SeatHeater_GripWarmerScaleIndicator_OnSetLevelValue( _this->ScaleIndicator, (XInt32)_this->ItemValueArray[ 
  EwCheckIndex( aItemNo, 3 )]);
  _this->ItemIdx = aItemNo;

  switch ( aItemNo )
  {
    case 0 :
    {
      SeatHeater_GripWarmerScaleIndicator_OnSetScaleIndicatorType( _this->ScaleIndicator, 
      EnumSeatHeaterGripWarmerLevelTypeLOW );
      DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
      DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeHEATER_LEVEL, 0 );
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)_this->ScaleIndicator ), 
      0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
    break;

    case 1 :
    {
      SeatHeater_GripWarmerScaleIndicator_OnSetScaleIndicatorType( _this->ScaleIndicator, 
      EnumSeatHeaterGripWarmerLevelTypeMID );
      DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
      DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeHEATER_LEVEL, 1 );
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)_this->ScaleIndicator ), 
      0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
    break;

    case 2 :
    {
      SeatHeater_GripWarmerScaleIndicator_OnSetScaleIndicatorType( _this->ScaleIndicator, 
      EnumSeatHeaterGripWarmerLevelTypeHIGH );
      DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
      DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeHEATER_LEVEL, 2 );
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)_this->ScaleIndicator ), 
      0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'SeatHeater_GripWarmer::SHT02_GPW02_Main.LoadItemBaseValue()' */
XString SeatHeater_GripWarmerSHT02_GPW02_Main_LoadItemBaseValue( SeatHeater_GripWarmerSHT02_GPW02_Main _this, 
  XInt32 aItemNo )
{
  XString val = 0;

  if ( aItemNo < 3 )
  {
    val = EwNewStringUInt( _this->ItemValueArray[ EwCheckIndex( aItemNo, 3 )], 0, 
    10 );
  }

  return val;
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SeatHeater_GripWarmerSHT02_GPW02_Main_OnVehicleDataReceivedSlot( SeatHeater_GripWarmerSHT02_GPW02_Main _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;
  XBool IsSeatHeaterValueReceived;
  XBool IsGripWarmerValueReceived;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );
  IsSeatHeaterValueReceived = (XBool)((( EnumVehicleRxTypeSEAT_HEATER_VALUE_LOW 
  == VehicleData->RxType ) || ( EnumVehicleRxTypeSEAT_HEATER_VALUE_MIDDLE == VehicleData->RxType )) 
  || ( EnumVehicleRxTypeSEAT_HEATER_VALUE_HIGH == VehicleData->RxType ));
  IsGripWarmerValueReceived = (XBool)((( EnumVehicleRxTypeGRIP_WARMER_VALUE_LOW 
  == VehicleData->RxType ) || ( EnumVehicleRxTypeGRIP_WARMER_VALUE_MIDDLE == VehicleData->RxType )) 
  || ( EnumVehicleRxTypeGRIP_WARMER_VALUE_HIGH == VehicleData->RxType ));

  if (( VehicleData != 0 ) && ( IsSeatHeaterValueReceived || IsGripWarmerValueReceived ))
  {
    SeatHeater_GripWarmerSHT02_GPW02_Main_UpdateLevel( _this, VehicleData->RxType );
  }
  else
  {
    EwTrace( "%s", EwLoadString( &_Const0000 ));
  }
}

/* 'C' function for method : 'SeatHeater_GripWarmer::SHT02_GPW02_Main.UpdateLevel()' */
void SeatHeater_GripWarmerSHT02_GPW02_Main_UpdateLevel( SeatHeater_GripWarmerSHT02_GPW02_Main _this, 
  XEnum aNewType )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  switch ( aNewType )
  {
    case EnumVehicleRxTypeSEAT_HEATER_VALUE_LOW :
    case EnumVehicleRxTypeGRIP_WARMER_VALUE_LOW :
    {
      if ( aNewType == EnumVehicleRxTypeSEAT_HEATER_VALUE_LOW )
      {
        VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
        &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeSEAT_HEATER_VALUE_LOW );
      }
      else
      {
        VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
        &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeGRIP_WARMER_VALUE_LOW );
      }

      if ((((( VehicleData != 0 ) && VehicleData->Valid ) && ( _this->ItemValueArray[ 
          0 ] != VehicleData->DataUInt32 )) && ( 10 >= VehicleData->DataUInt32 )) 
          && ( VehicleData->DataUInt32 >= 1 ))
      {
        _this->ItemValueArray[ 0 ] = VehicleData->DataUInt32;
        SeatHeater_GripWarmerScaleIndicator_OnSetLevelValue( _this->ScaleIndicator, 
        (XInt32)VehicleData->DataUInt32 );
        MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 0 );
      }
    }
    break;

    case EnumVehicleRxTypeSEAT_HEATER_VALUE_MIDDLE :
    case EnumVehicleRxTypeGRIP_WARMER_VALUE_MIDDLE :
    {
      if ( aNewType == EnumVehicleRxTypeSEAT_HEATER_VALUE_MIDDLE )
      {
        VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
        &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeSEAT_HEATER_VALUE_MIDDLE );
      }
      else
      {
        VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
        &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeGRIP_WARMER_VALUE_MIDDLE );
      }

      if ((((( VehicleData != 0 ) && VehicleData->Valid ) && ( _this->ItemValueArray[ 
          1 ] != VehicleData->DataUInt32 )) && ( 10 >= VehicleData->DataUInt32 )) 
          && ( VehicleData->DataUInt32 >= 1 ))
      {
        _this->ItemValueArray[ 1 ] = VehicleData->DataUInt32;
        SeatHeater_GripWarmerScaleIndicator_OnSetLevelValue( _this->ScaleIndicator, 
        (XInt32)VehicleData->DataUInt32 );
        MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 1, 1 );
      }
    }
    break;

    case EnumVehicleRxTypeSEAT_HEATER_VALUE_HIGH :
    case EnumVehicleRxTypeGRIP_WARMER_VALUE_HIGH :
    {
      if ( aNewType == EnumVehicleRxTypeSEAT_HEATER_VALUE_HIGH )
      {
        VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
        &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeSEAT_HEATER_VALUE_HIGH );
      }
      else
      {
        VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
        &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeGRIP_WARMER_VALUE_HIGH );
      }

      if ((((( VehicleData != 0 ) && VehicleData->Valid ) && ( _this->ItemValueArray[ 
          2 ] != VehicleData->DataUInt32 )) && ( 10 >= VehicleData->DataUInt32 )) 
          && ( VehicleData->DataUInt32 >= 1 ))
      {
        _this->ItemValueArray[ 2 ] = VehicleData->DataUInt32;
        SeatHeater_GripWarmerScaleIndicator_OnSetLevelValue( _this->ScaleIndicator, 
        (XInt32)VehicleData->DataUInt32 );
        MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 2, 2 );
      }
    }
    break;

    default : 
      ;
  }
}

/* Variants derived from the class : 'SeatHeater_GripWarmer::SHT02_GPW02_Main' */
EW_DEFINE_CLASS_VARIANTS( SeatHeater_GripWarmerSHT02_GPW02_Main )
EW_END_OF_CLASS_VARIANTS( SeatHeater_GripWarmerSHT02_GPW02_Main )

/* Virtual Method Table (VMT) for the class : 'SeatHeater_GripWarmer::SHT02_GPW02_Main' */
EW_DEFINE_CLASS( SeatHeater_GripWarmerSHT02_GPW02_Main, MenuBaseMenuView, ScaleIndicator, 
                 VehicleDataReceivedEventHandler, VehicleDataReceivedEventHandler, 
                 VehicleDataReceivedEventHandler, ItemTitleArray, ItemValueArray, 
                 "SeatHeater_GripWarmer::SHT02_GPW02_Main" )
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
  SeatHeater_GripWarmerSHT02_GPW02_Main_LoadItemClass,
  SeatHeater_GripWarmerSHT02_GPW02_Main_LoadItemTitle,
  SeatHeater_GripWarmerSHT02_GPW02_Main_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  SeatHeater_GripWarmerSHT02_GPW02_Main_LoadItemBaseValue,
  MenuBaseMenuView_LoadItemMessage,
  MenuBaseMenuView_LoadItemReceivedTime,
  MenuBaseMenuView_LoadItemCategory,
  MenuBaseMenuView_LoadItemUid,
EW_END_OF_CLASS( SeatHeater_GripWarmerSHT02_GPW02_Main )

/* Initializer for the class 'SeatHeater_GripWarmer::ScaleIndicator' */
void SeatHeater_GripWarmerScaleIndicator__Init( SeatHeater_GripWarmerScaleIndicator _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SeatHeater_GripWarmerScaleIndicator );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->ScaleIndicatorWindow, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ScaleIndicatorBg, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ScaleIndicatorBar, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SeatHeater_GripWarmerScaleIndicator );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0001 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  ViewsImage_OnSetVisible( &_this->Super1.MainBottomBG, 0 );
  ViewsRectangle_OnSetVisible( &_this->Super1.BlackBG, 0 );
  CoreRectView__OnSetBounds( &_this->ScaleIndicatorWindow, _Const0002 );
  CoreRectView__OnSetBounds( &_this->ScaleIndicatorBg, _Const0002 );
  CoreRectView__OnSetBounds( &_this->ScaleIndicatorBar, _Const0003 );
  _this->ScaleIndicatorBarOriBounds = _Const0003;
  CoreGroup__Add( _this, ((CoreView)&_this->ScaleIndicatorWindow ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ScaleIndicatorBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ScaleIndicatorBar ), 0 );
  ViewsImage_OnSetBitmap( &_this->ScaleIndicatorWindow, EwLoadResource( &ResourceScaleIndicatorWindowLow, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ScaleIndicatorBg, EwLoadResource( &ResourceScaleIndicatorBg, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ScaleIndicatorBar, EwLoadResource( &ResourceScaleIndicatorBar, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'SeatHeater_GripWarmer::ScaleIndicator' */
void SeatHeater_GripWarmerScaleIndicator__ReInit( SeatHeater_GripWarmerScaleIndicator _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->ScaleIndicatorWindow );
  ViewsImage__ReInit( &_this->ScaleIndicatorBg );
  ViewsImage__ReInit( &_this->ScaleIndicatorBar );
}

/* Finalizer method for the class 'SeatHeater_GripWarmer::ScaleIndicator' */
void SeatHeater_GripWarmerScaleIndicator__Done( SeatHeater_GripWarmerScaleIndicator _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->ScaleIndicatorWindow );
  ViewsImage__Done( &_this->ScaleIndicatorBg );
  ViewsImage__Done( &_this->ScaleIndicatorBar );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* 'C' function for method : 'SeatHeater_GripWarmer::ScaleIndicator.OnShortDownKeyActivated()' */
void SeatHeater_GripWarmerScaleIndicator_OnShortDownKeyActivated( SeatHeater_GripWarmerScaleIndicator _this )
{
  if ( 1 < _this->LevelValue )
  {
    DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
    DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeBUTTON_STATUS_AUDIO, 0 );
  }
}

/* 'C' function for method : 'SeatHeater_GripWarmer::ScaleIndicator.OnShortUpKeyActivated()' */
void SeatHeater_GripWarmerScaleIndicator_OnShortUpKeyActivated( SeatHeater_GripWarmerScaleIndicator _this )
{
  if ( 10 > _this->LevelValue )
  {
    DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
    DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeBUTTON_STATUS_AUDIO, 1 );
  }
}

/* 'C' function for method : 'SeatHeater_GripWarmer::ScaleIndicator.OnShortEnterKeyActivated()' */
void SeatHeater_GripWarmerScaleIndicator_OnShortEnterKeyActivated( SeatHeater_GripWarmerScaleIndicator _this )
{
  ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
}

/* 'C' function for method : 'SeatHeater_GripWarmer::ScaleIndicator.OnSetScaleIndicatorType()' */
void SeatHeater_GripWarmerScaleIndicator_OnSetScaleIndicatorType( SeatHeater_GripWarmerScaleIndicator _this, 
  XEnum value )
{
  if ( _this->ScaleIndicatorType != value )
  {
    _this->ScaleIndicatorType = value;

    switch ( _this->ScaleIndicatorType )
    {
      case EnumSeatHeaterGripWarmerLevelTypeLOW :
        ViewsImage_OnSetBitmap( &_this->ScaleIndicatorWindow, EwLoadResource( &ResourceScaleIndicatorWindowLow, 
        ResourcesBitmap ));
      break;

      case EnumSeatHeaterGripWarmerLevelTypeMID :
        ViewsImage_OnSetBitmap( &_this->ScaleIndicatorWindow, EwLoadResource( &ResourceScaleIndicatorWindowMid, 
        ResourcesBitmap ));
      break;

      case EnumSeatHeaterGripWarmerLevelTypeHIGH :
        ViewsImage_OnSetBitmap( &_this->ScaleIndicatorWindow, EwLoadResource( &ResourceScaleIndicatorWindowHigh, 
        ResourcesBitmap ));
      break;

      default : 
        ;
    }
  }
}

/* 'C' function for method : 'SeatHeater_GripWarmer::ScaleIndicator.OnSetLevelValue()' */
void SeatHeater_GripWarmerScaleIndicator_OnSetLevelValue( SeatHeater_GripWarmerScaleIndicator _this, 
  XInt32 value )
{
  if ( _this->LevelValue != value )
  {
    XRect NewBounds;
    _this->LevelValue = value;
    ViewsImage_OnSetFrameNumber( &_this->ScaleIndicatorBar, 1 );
    NewBounds = _Const0004;
    NewBounds.Point1.X = _this->ScaleIndicatorBarOriBounds.Point1.X;
    NewBounds.Point1.Y = ( _this->ScaleIndicatorBarOriBounds.Point1.Y - ( 18 * ( 
    _this->LevelValue - 1 )));
    NewBounds.Point2.X = _this->ScaleIndicatorBarOriBounds.Point2.X;
    NewBounds.Point2.Y = ( _this->ScaleIndicatorBarOriBounds.Point2.Y - ( 18 * ( 
    _this->LevelValue - 1 )));
    CoreRectView__OnSetBounds( &_this->ScaleIndicatorBar, NewBounds );
  }
}

/* Variants derived from the class : 'SeatHeater_GripWarmer::ScaleIndicator' */
EW_DEFINE_CLASS_VARIANTS( SeatHeater_GripWarmerScaleIndicator )
EW_END_OF_CLASS_VARIANTS( SeatHeater_GripWarmerScaleIndicator )

/* Virtual Method Table (VMT) for the class : 'SeatHeater_GripWarmer::ScaleIndicator' */
EW_DEFINE_CLASS( SeatHeater_GripWarmerScaleIndicator, ComponentsBaseMainBG, ScaleIndicatorWindow, 
                 ScaleIndicatorWindow, ScaleIndicatorWindow, ScaleIndicatorWindow, 
                 LevelValue, LevelValue, "SeatHeater_GripWarmer::ScaleIndicator" )
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
  SeatHeater_GripWarmerScaleIndicator_OnShortDownKeyActivated,
  SeatHeater_GripWarmerScaleIndicator_OnShortUpKeyActivated,
  SeatHeater_GripWarmerScaleIndicator_OnShortEnterKeyActivated,
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SeatHeater_GripWarmerScaleIndicator )

/* Embedded Wizard */
