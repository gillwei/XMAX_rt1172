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
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DeviceInterfaceVehicleDataClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_MenuItemBaseValue.h"
#include "_MenuVerticalMenu.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction.h"
#include "_SeatHeater_GripWarmerSHT02_GPW02_Main.h"
#include "_SeatHeater_GripWarmerScaleIndicator.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Fonts.h"
#include "Resource.h"
#include "SeatHeater_GripWarmer.h"
#include "Strings.h"
#include "Views.h"

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
static const XRect _Const0005 = {{ 0, 96 }, { 480, 206 }};
static const XRect _Const0006 = {{ 138, 132 }, { 469, 175 }};
static const XRect _Const0007 = {{ 0, 39 }, { 94, 114 }};
static const XRect _Const0008 = {{ 0, 189 }, { 94, 264 }};
static const XRect _Const0009 = {{ 13, 112 }, { 91, 190 }};

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

/* Initializer for the class 'SeatHeater_GripWarmer::SHT01_GPW01_WSC01_VehicleFunction' */
void SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction__Init( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->ImgLCBlueline, &_this->_XObject, 0 );
  ViewsText__Init( &_this->CurrentItemTitleText, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ControlUpBg, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ControlDownBg, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ControlDownButton, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ControlUpButton, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->VehicleFunctionIcon, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->HighlightTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->ImgLCBlueline, _Const0005 );
  CoreRectView__OnSetBounds( &_this->CurrentItemTitleText, _Const0006 );
  ViewsText_OnSetAlignment( &_this->CurrentItemTitleText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->CurrentItemTitleText, 0 );
  CoreRectView__OnSetBounds( &_this->ControlUpBg, _Const0007 );
  CoreRectView__OnSetBounds( &_this->ControlDownBg, _Const0008 );
  CoreRectView__OnSetBounds( &_this->ControlDownButton, _Const0008 );
  CoreRectView__OnSetBounds( &_this->ControlUpButton, _Const0007 );
  CoreRectView__OnSetBounds( &_this->VehicleFunctionIcon, _Const0009 );
  ViewsImage_OnSetFrameNumber( &_this->VehicleFunctionIcon, 1 );
  ViewsImage_OnSetVisible( &_this->VehicleFunctionIcon, 0 );
  CoreTimer_OnSetPeriod( &_this->HighlightTimer, 100 );
  CoreTimer_OnSetEnabled( &_this->HighlightTimer, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ImgLCBlueline ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CurrentItemTitleText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ControlUpBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ControlDownBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ControlDownButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ControlUpButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->VehicleFunctionIcon ), 0 );
  ViewsImage_OnSetBitmap( &_this->ImgLCBlueline, EwLoadResource( &ResourceLCBlueline, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->CurrentItemTitleText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->ControlUpBg, EwLoadResource( &ResourceControlButtonBackground, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ControlDownBg, EwLoadResource( &ResourceControlButtonBackground, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ControlDownButton, EwLoadResource( &ResourceControlDownButton, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ControlUpButton, EwLoadResource( &ResourceControlUpButton, 
  ResourcesBitmap ));
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );
  _this->HighlightTimer.OnTrigger = EwNewSlot( _this, SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_OnHighlightEndSlot );

  /* Call the user defined constructor */
  SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_Init( _this, aArg );
}

/* Re-Initializer for the class 'SeatHeater_GripWarmer::SHT01_GPW01_WSC01_VehicleFunction' */
void SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction__ReInit( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->ImgLCBlueline );
  ViewsText__ReInit( &_this->CurrentItemTitleText );
  ViewsImage__ReInit( &_this->ControlUpBg );
  ViewsImage__ReInit( &_this->ControlDownBg );
  ViewsImage__ReInit( &_this->ControlDownButton );
  ViewsImage__ReInit( &_this->ControlUpButton );
  ViewsImage__ReInit( &_this->VehicleFunctionIcon );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
  CoreTimer__ReInit( &_this->HighlightTimer );
}

/* Finalizer method for the class 'SeatHeater_GripWarmer::SHT01_GPW01_WSC01_VehicleFunction' */
void SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction__Done( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->ImgLCBlueline );
  ViewsText__Done( &_this->CurrentItemTitleText );
  ViewsImage__Done( &_this->ControlUpBg );
  ViewsImage__Done( &_this->ControlDownBg );
  ViewsImage__Done( &_this->ControlDownButton );
  ViewsImage__Done( &_this->ControlUpButton );
  ViewsImage__Done( &_this->VehicleFunctionIcon );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );
  CoreTimer__Done( &_this->HighlightTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_Init( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  if ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
      == EnumVehicleSupportedFunctionSEAT_HEATER )
  {
    ViewsText_OnSetString( &_this->CurrentItemTitleText, EwLoadString( &StringsLNC_SEAT_HEATER ));
    SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_UpdateHeaterLevel( _this, 
    EnumVehicleRxTypeSEAT_HEATER_STATUS );
  }
  else
    if ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
        == EnumVehicleSupportedFunctionGRIP_WARMER )
    {
      ViewsText_OnSetString( &_this->CurrentItemTitleText, EwLoadString( &StringsGPW01_GRIP_WARMER ));
      SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_UpdateHeaterLevel( 
      _this, EnumVehicleRxTypeGRIP_WARMER_STATUS );
    }
    else
      if ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
          == EnumVehicleSupportedFunctionWIND_SCREEN )
      {
        ViewsText_OnSetString( &_this->CurrentItemTitleText, EwLoadString( &StringsWSC01_WIND_SCREEN ));
        ViewsImage_OnSetBitmap( &_this->ControlUpButton, EwLoadResource( &ResourceControlUpButtonArrow, 
        ResourcesBitmap ));
        ViewsImage_OnSetBitmap( &_this->ControlDownButton, EwLoadResource( &ResourceControlDownButtonArrow, 
        ResourcesBitmap ));
      }
      else
      {
        EwTrace( "%s", EwLoadString( &_Const0000 ));
      }
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
void SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_UpdateViewState( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction _this, 
  XSet aState )
{
  CoreGroup_UpdateViewState((CoreGroup)_this, aState );

  if (( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
      == EnumVehicleSupportedFunctionSEAT_HEATER ) || ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
      DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction == EnumVehicleSupportedFunctionGRIP_WARMER ))
  {
    if (( 0 <= (XUInt32)_this->HeaterSettingStatus ) && ( 3 >= (XUInt32)_this->HeaterSettingStatus ))
    {
      switch ( _this->HeaterSettingStatus )
      {
        case EnumHeaterSettingStatusTypeOFF :
        {
          ViewsImage_OnSetFrameNumber( &_this->ControlUpButton, 0 );
          ViewsImage_OnSetFrameNumber( &_this->ControlDownButton, 1 );
          ViewsImage_OnSetVisible( &_this->VehicleFunctionIcon, 0 );
        }
        break;

        case EnumHeaterSettingStatusTypeLOW :
        {
          if ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
              == EnumVehicleSupportedFunctionSEAT_HEATER )
          {
            ViewsImage_OnSetBitmap( &_this->VehicleFunctionIcon, EwLoadResource( 
            &ResourceIconSeatHeater1Large, ResourcesBitmap ));
          }
          else
          {
            ViewsImage_OnSetBitmap( &_this->VehicleFunctionIcon, EwLoadResource( 
            &ResourceIconGripWarmer1Large, ResourcesBitmap ));
          }

          ViewsImage_OnSetFrameNumber( &_this->ControlUpButton, 0 );
          ViewsImage_OnSetFrameNumber( &_this->ControlDownButton, 0 );
          ViewsImage_OnSetVisible( &_this->VehicleFunctionIcon, 1 );
        }
        break;

        case EnumHeaterSettingStatusTypeMID :
        {
          if ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
              == EnumVehicleSupportedFunctionSEAT_HEATER )
          {
            ViewsImage_OnSetBitmap( &_this->VehicleFunctionIcon, EwLoadResource( 
            &ResourceIconSeatHeater2Large, ResourcesBitmap ));
          }
          else
          {
            ViewsImage_OnSetBitmap( &_this->VehicleFunctionIcon, EwLoadResource( 
            &ResourceIconGripWarmer2Large, ResourcesBitmap ));
          }

          ViewsImage_OnSetFrameNumber( &_this->ControlUpButton, 0 );
          ViewsImage_OnSetFrameNumber( &_this->ControlDownButton, 0 );
          ViewsImage_OnSetVisible( &_this->VehicleFunctionIcon, 1 );
        }
        break;

        case EnumHeaterSettingStatusTypeHIGH :
        {
          if ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
              == EnumVehicleSupportedFunctionSEAT_HEATER )
          {
            ViewsImage_OnSetBitmap( &_this->VehicleFunctionIcon, EwLoadResource( 
            &ResourceIconSeatHeater3Large, ResourcesBitmap ));
          }
          else
          {
            ViewsImage_OnSetBitmap( &_this->VehicleFunctionIcon, EwLoadResource( 
            &ResourceIconGripWarmer3Large, ResourcesBitmap ));
          }

          ViewsImage_OnSetFrameNumber( &_this->ControlUpButton, 1 );
          ViewsImage_OnSetFrameNumber( &_this->ControlDownButton, 0 );
          ViewsImage_OnSetVisible( &_this->VehicleFunctionIcon, 1 );
        }
        break;

        default : 
          ;
      }
    }
  }
  else
    if ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
        == EnumVehicleSupportedFunctionWIND_SCREEN )
    {
      ViewsImage_OnSetBitmap( &_this->VehicleFunctionIcon, EwLoadResource( &ResourceIconWindScreenLarge, 
      ResourcesBitmap ));
      ViewsImage_OnSetVisible( &_this->VehicleFunctionIcon, 1 );
    }
    else
    {
      EwTrace( "%s", EwLoadString( &_Const0000 ));
    }
}

/* 'C' function for method : 'SeatHeater_GripWarmer::SHT01_GPW01_WSC01_VehicleFunction.OnShortDownKeyActivated()' */
void SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_OnShortDownKeyActivated( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction _this )
{
  switch ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction )
  {
    case EnumVehicleSupportedFunctionSEAT_HEATER :
    {
      if ( 0 < (XUInt32)_this->HeaterSettingStatus )
      {
        SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_StartHighlight( _this, 
        &_this->ControlDownBg );
        DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeSEAT_HEATER_CHANGE_LEVEL, 
        1 );
      }
    }
    break;

    case EnumVehicleSupportedFunctionGRIP_WARMER :
    {
      if ( 0 < (XUInt32)_this->HeaterSettingStatus )
      {
        SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_StartHighlight( _this, 
        &_this->ControlDownBg );
        DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeGRIP_WARMER_CHANGE_LEVEL, 
        1 );
      }
    }
    break;

    case EnumVehicleSupportedFunctionWIND_SCREEN :
    {
      ViewsImage_OnSetFrameNumber( &_this->ControlDownBg, 1 );
      DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
      DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeWIND_SCREEN_OPERATION, 
      1 );
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'SeatHeater_GripWarmer::SHT01_GPW01_WSC01_VehicleFunction.OnShortUpKeyActivated()' */
void SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_OnShortUpKeyActivated( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction _this )
{
  switch ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction )
  {
    case EnumVehicleSupportedFunctionSEAT_HEATER :
    {
      if ( 3 > (XUInt32)_this->HeaterSettingStatus )
      {
        SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_StartHighlight( _this, 
        &_this->ControlUpBg );
        DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeSEAT_HEATER_CHANGE_LEVEL, 
        2 );
      }
    }
    break;

    case EnumVehicleSupportedFunctionGRIP_WARMER :
    {
      if ( 3 > (XUInt32)_this->HeaterSettingStatus )
      {
        SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_StartHighlight( _this, 
        &_this->ControlUpBg );
        DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeGRIP_WARMER_CHANGE_LEVEL, 
        2 );
      }
    }
    break;

    case EnumVehicleSupportedFunctionWIND_SCREEN :
    {
      ViewsImage_OnSetFrameNumber( &_this->ControlUpBg, 1 );
      DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
      DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeWIND_SCREEN_OPERATION, 
      2 );
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'SeatHeater_GripWarmer::SHT01_GPW01_WSC01_VehicleFunction.OnShortEnterKeyActivated()' */
void SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_OnShortEnterKeyActivated( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction _this )
{
  ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
}

/* Callback when down key of on trigger mode is released */
void SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_OnDownKeyReleased( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction _this )
{
  switch ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction )
  {
    case EnumVehicleSupportedFunctionSEAT_HEATER :
      DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
      DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeSEAT_HEATER_CHANGE_LEVEL, 
      0 );
    break;

    case EnumVehicleSupportedFunctionGRIP_WARMER :
      DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
      DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeGRIP_WARMER_CHANGE_LEVEL, 
      0 );
    break;

    case EnumVehicleSupportedFunctionWIND_SCREEN :
    {
      ViewsImage_OnSetFrameNumber( &_this->ControlDownBg, 0 );
      DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
      DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeWIND_SCREEN_OPERATION, 
      0 );
    }
    break;

    default : 
      ;
  }
}

/* Callback when up key of on trigger mode is released */
void SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_OnUpKeyReleased( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction _this )
{
  switch ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction )
  {
    case EnumVehicleSupportedFunctionSEAT_HEATER :
      DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
      DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeSEAT_HEATER_CHANGE_LEVEL, 
      0 );
    break;

    case EnumVehicleSupportedFunctionGRIP_WARMER :
      DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
      DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeGRIP_WARMER_CHANGE_LEVEL, 
      0 );
    break;

    case EnumVehicleSupportedFunctionWIND_SCREEN :
    {
      ViewsImage_OnSetFrameNumber( &_this->ControlUpBg, 0 );
      DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
      DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeWIND_SCREEN_OPERATION, 
      0 );
    }
    break;

    default : 
      ;
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_OnVehicleDataReceivedSlot( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if (( VehicleData != 0 ) && (( EnumVehicleRxTypeGRIP_WARMER_STATUS == VehicleData->RxType ) 
      || ( EnumVehicleRxTypeSEAT_HEATER_STATUS == VehicleData->RxType )))
  {
    SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_UpdateHeaterLevel( _this, 
    VehicleData->RxType );
  }
}

/* 'C' function for method : 'SeatHeater_GripWarmer::SHT01_GPW01_WSC01_VehicleFunction.UpdateHeaterLevel()' */
void SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_UpdateHeaterLevel( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction _this, 
  XEnum aNewType )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  switch ( aNewType )
  {
    case EnumVehicleRxTypeGRIP_WARMER_STATUS :
    {
      VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeGRIP_WARMER_STATUS );

      if (((( VehicleData != 0 ) && ((XUInt32)_this->HeaterSettingStatus != VehicleData->DataUInt32 )) 
          && ( 3 >= VehicleData->DataUInt32 )) && ( VehicleData->DataUInt32 >= 0 ))
      {
        _this->HeaterSettingStatus = (XEnum)VehicleData->DataUInt32;
        CoreGroup_InvalidateViewState((CoreGroup)_this );
      }
    }
    break;

    case EnumVehicleRxTypeSEAT_HEATER_STATUS :
    {
      VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeSEAT_HEATER_STATUS );

      if (((( VehicleData != 0 ) && ((XUInt32)_this->HeaterSettingStatus != VehicleData->DataUInt32 )) 
          && ( 3 >= VehicleData->DataUInt32 )) && ( VehicleData->DataUInt32 >= 0 ))
      {
        _this->HeaterSettingStatus = (XEnum)VehicleData->DataUInt32;
        CoreGroup_InvalidateViewState((CoreGroup)_this );
      }
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'SeatHeater_GripWarmer::SHT01_GPW01_WSC01_VehicleFunction.StartHighlight()' */
void SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_StartHighlight( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction _this, 
  ViewsImage aBackground )
{
  ViewsImage_OnSetFrameNumber( aBackground, 1 );
  _this->HighlightBG = aBackground;
  CoreTimer_OnSetEnabled( &_this->HighlightTimer, 1 );
}

/* 'C' function for method : 'SeatHeater_GripWarmer::SHT01_GPW01_WSC01_VehicleFunction.OnHighlightEndSlot()' */
void SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_OnHighlightEndSlot( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->HighlightTimer, 0 );
  ViewsImage_OnSetFrameNumber( _this->HighlightBG, 0 );
}

/* Variants derived from the class : 'SeatHeater_GripWarmer::SHT01_GPW01_WSC01_VehicleFunction' */
EW_DEFINE_CLASS_VARIANTS( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction )
EW_END_OF_CLASS_VARIANTS( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction )

/* Virtual Method Table (VMT) for the class : 'SeatHeater_GripWarmer::SHT01_GPW01_WSC01_VehicleFunction' */
EW_DEFINE_CLASS( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction, ComponentsBaseMainBG, 
                 HighlightBG, ImgLCBlueline, ImgLCBlueline, ImgLCBlueline, HeaterSettingStatus, 
                 HeaterSettingStatus, "SeatHeater_GripWarmer::SHT01_GPW01_WSC01_VehicleFunction" )
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
  SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_OnShortDownKeyActivated,
  SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_OnShortUpKeyActivated,
  SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_OnShortEnterKeyActivated,
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_OnDownKeyReleased,
  SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction_OnUpKeyReleased,
EW_END_OF_CLASS( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction )

/* Embedded Wizard */
