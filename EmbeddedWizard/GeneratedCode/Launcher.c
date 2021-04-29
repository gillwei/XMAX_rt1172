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
#include "_ComponentsBaseComponent.h"
#include "_CoreGroup.h"
#include "_CoreKeyPressHandler.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DeviceInterfaceBluetoothDeviceClass.h"
#include "_DeviceInterfaceMediaManagerDeviceClass.h"
#include "_DeviceInterfaceNotificationDeviceClass.h"
#include "_DeviceInterfaceVehicleDataClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_EffectsRectEffect.h"
#include "_InfoINF01_MeterDisplaySettingMenu.h"
#include "_InfoINF26_ODO_TRIP_SettingMenu.h"
#include "_LauncherLNC_Base.h"
#include "_LauncherLNC_Main.h"
#include "_LauncherLNC_RotaryPlate.h"
#include "_MediaMED01_MediaUI.h"
#include "_NavigationNAV06_NaviSettingMenu.h"
#include "_NotificationNTF01_NotificationList.h"
#include "_PopPOP04_Reset.h"
#include "_PopPOP08_WeatherLoadingUI.h"
#include "_PopPOP09_BleConnectionErrorUI.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction.h"
#include "_SeatHeater_GripWarmerSHT02_GPW02_Main.h"
#include "_SettingsSET01_MainSettingMenu.h"
#include "_TelephoneTEL02_ActiveCall.h"
#include "_ViewsImage.h"
#include "_ViewsText.h"
#include "_ViewsWallpaper.h"
#include "Core.h"
#include "DeviceInterface.h"
#include "Effects.h"
#include "Enum.h"
#include "Fonts.h"
#include "Launcher.h"
#include "Resource.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x0000008C, /* ratio 80.00 % */
  0xB8001F00, 0x80098452, 0x00EA0030, 0x0C600370, 0xCA003400, 0x20039000, 0x690042C9,
  0xC001D000, 0x22C0C2F1, 0x98023044, 0x488DA003, 0x3C872492, 0x0006C914, 0x33210019,
  0x06F96C22, 0x009199C0, 0xE0047040, 0x0014A3E1, 0xA4223735, 0x8B000798, 0x44A6009C,
  0xA99158D4, 0x75249344, 0x90A95520, 0x0C894522, 0xB9D54A37, 0x00406773, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0001 = {{ 0, 38 }, { 480, 272 }};
static const XRect _Const0002 = {{ -480, 38 }, { 0, 272 }};
static const XRect _Const0003 = {{ 0, 38 }, { 134, 272 }};
static const XRect _Const0004 = {{ -134, 38 }, { 0, 272 }};
static const XRect _Const0005 = {{ 0, 38 }, { 480, 49 }};
static const XStringRes _Const0006 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0007 = { _StringsDefault0, 0x0011 };
static const XRect _Const0008 = {{ 0, 0 }, { 134, 234 }};
static const XRect _Const0009 = {{ -81, -143 }, { -31, -93 }};
static const XRect _Const000A = {{ 9, 10 }, { 59, 60 }};
static const XRect _Const000B = {{ 27, 88 }, { 77, 138 }};
static const XRect _Const000C = {{ 9, 166 }, { 59, 216 }};
static const XRect _Const000D = {{ -81, 231 }, { -31, 281 }};
static const XRect _Const000E = {{ 0, 0 }, { 0, 0 }};
static const XRect _Const000F = {{ -1, 249 }, { 41, 291 }};
static const XRect _Const0010 = {{ 13, 74 }, { 91, 152 }};
static const XRect _Const0011 = {{ 0, 70 }, { 122, 156 }};
static const XStringRes _Const0012 = { _StringsDefault0, 0x0028 };
static const XRect _Const0013 = {{ 0, 0 }, { 480, 234 }};
static const XRect _Const0014 = {{ 0, 58 }, { 480, 168 }};
static const XRect _Const0015 = {{ 138, 92 }, { 469, 135 }};
static const XRect _Const0016 = {{ 121, 17 }, { 439, 50 }};
static const XColor _Const0017 = { 0x6B, 0x6B, 0x6B, 0xFF };
static const XRect _Const0018 = {{ 121, 173 }, { 439, 206 }};

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

/* Initializer for the class 'Launcher::LNC_Main' */
void LauncherLNC_Main__Init( LauncherLNC_Main _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( LauncherLNC_Main );

  /* ... then construct all embedded objects */
  EffectsRectEffect__Init( &_this->BaseSlideInEffect, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->BaseSlideOutEffect, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->RotaryPlateSlideInEffect, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->RotaryPlateSlideOutEffect, &_this->_XObject, 0 );
  LauncherLNC_Base__Init( &_this->LNC_Base, &_this->_XObject, 0 );
  LauncherLNC_RotaryPlate__Init( &_this->LNC_RotaryPlate, &_this->_XObject, 0 );
  ViewsWallpaper__Init( &_this->StatusBarShadowImage, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( LauncherLNC_Main );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  EffectsEffect_OnSetExponent((EffectsEffect)&_this->BaseSlideInEffect, 4.380000f );
  EffectsEffect_OnSetTimingCustom1((EffectsEffect)&_this->BaseSlideInEffect, 0.000000f );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->BaseSlideInEffect, EffectsTimingExp_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->BaseSlideInEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->BaseSlideInEffect, 300 );
  _this->BaseSlideInEffect.Value2 = _Const0001;
  _this->BaseSlideInEffect.Value1 = _Const0002;
  EffectsEffect_OnSetExponent((EffectsEffect)&_this->BaseSlideOutEffect, 4.380000f );
  EffectsEffect_OnSetTimingCustom1((EffectsEffect)&_this->BaseSlideOutEffect, 0.000000f );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->BaseSlideOutEffect, EffectsTimingExp_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->BaseSlideOutEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->BaseSlideOutEffect, 300 );
  _this->BaseSlideOutEffect.Value2 = _Const0002;
  _this->BaseSlideOutEffect.Value1 = _Const0001;
  EffectsEffect_OnSetExponent((EffectsEffect)&_this->RotaryPlateSlideInEffect, 4.490000f );
  EffectsEffect_OnSetTimingCustom1((EffectsEffect)&_this->RotaryPlateSlideInEffect, 
  0.000000f );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->RotaryPlateSlideInEffect, EffectsTimingExp_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->RotaryPlateSlideInEffect, 
  1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->RotaryPlateSlideInEffect, 
  300 );
  _this->RotaryPlateSlideInEffect.Value2 = _Const0003;
  _this->RotaryPlateSlideInEffect.Value1 = _Const0004;
  EffectsEffect_OnSetExponent((EffectsEffect)&_this->RotaryPlateSlideOutEffect, 
  4.490000f );
  EffectsEffect_OnSetTimingCustom1((EffectsEffect)&_this->RotaryPlateSlideOutEffect, 
  0.000000f );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->RotaryPlateSlideOutEffect, EffectsTimingExp_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->RotaryPlateSlideOutEffect, 
  1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->RotaryPlateSlideOutEffect, 
  300 );
  _this->RotaryPlateSlideOutEffect.Value2 = _Const0004;
  _this->RotaryPlateSlideOutEffect.Value1 = _Const0003;
  CoreRectView__OnSetBounds( &_this->LNC_Base, _Const0002 );
  CoreRectView__OnSetBounds( &_this->LNC_RotaryPlate, _Const0004 );
  CoreRectView__OnSetBounds( &_this->StatusBarShadowImage, _Const0005 );
  CoreGroup__Add( _this, ((CoreView)&_this->LNC_Base ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LNC_RotaryPlate ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->StatusBarShadowImage ), 0 );
  _this->BaseSlideInEffect.Outlet = EwNewRef( &_this->LNC_Base, CoreRectView_OnGetBounds, 
  CoreRectView__OnSetBounds );
  _this->BaseSlideOutEffect.Super1.OnFinished = EwNewSlot( _this, LauncherLNC_Main_OnSlideOutFinishedSlot );
  _this->BaseSlideOutEffect.Outlet = EwNewRef( &_this->LNC_Base, CoreRectView_OnGetBounds, 
  CoreRectView__OnSetBounds );
  _this->RotaryPlateSlideInEffect.Outlet = EwNewRef( &_this->LNC_RotaryPlate, CoreRectView_OnGetBounds, 
  CoreRectView__OnSetBounds );
  _this->RotaryPlateSlideOutEffect.Super1.OnFinished = EwNewSlot( _this, LauncherLNC_Main_OnSlideOutFinishedSlot );
  _this->RotaryPlateSlideOutEffect.Outlet = EwNewRef( &_this->LNC_RotaryPlate, CoreRectView_OnGetBounds, 
  CoreRectView__OnSetBounds );
  _this->LNC_RotaryPlate.OnIconsRotated = EwNewSlot( _this, LauncherLNC_Main_OnCurrentItemChangedSlot );
  _this->LNC_RotaryPlate.OnSelectedAnimationFinished = EwNewSlot( _this, LauncherLNC_Main_OnSelectedAnimationFinishedSlot );
  ViewsWallpaper_OnSetBitmap( &_this->StatusBarShadowImage, EwLoadResource( &ResourceStatusBarShadow, 
  ResourcesBitmap ));
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, LauncherLNC_Main_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );

  /* Call the user defined constructor */
  LauncherLNC_Main_Init( _this, aArg );
}

/* Re-Initializer for the class 'Launcher::LNC_Main' */
void LauncherLNC_Main__ReInit( LauncherLNC_Main _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  EffectsRectEffect__ReInit( &_this->BaseSlideInEffect );
  EffectsRectEffect__ReInit( &_this->BaseSlideOutEffect );
  EffectsRectEffect__ReInit( &_this->RotaryPlateSlideInEffect );
  EffectsRectEffect__ReInit( &_this->RotaryPlateSlideOutEffect );
  LauncherLNC_Base__ReInit( &_this->LNC_Base );
  LauncherLNC_RotaryPlate__ReInit( &_this->LNC_RotaryPlate );
  ViewsWallpaper__ReInit( &_this->StatusBarShadowImage );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'Launcher::LNC_Main' */
void LauncherLNC_Main__Done( LauncherLNC_Main _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  EffectsRectEffect__Done( &_this->BaseSlideInEffect );
  EffectsRectEffect__Done( &_this->BaseSlideOutEffect );
  EffectsRectEffect__Done( &_this->RotaryPlateSlideInEffect );
  EffectsRectEffect__Done( &_this->RotaryPlateSlideOutEffect );
  LauncherLNC_Base__Done( &_this->LNC_Base );
  LauncherLNC_RotaryPlate__Done( &_this->LNC_RotaryPlate );
  ViewsWallpaper__Done( &_this->StatusBarShadowImage );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void LauncherLNC_Main_Init( LauncherLNC_Main _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0006 ));
  LauncherLNC_Main_GetVehicleSupportedFeature( _this );
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->RotaryPlateSlideInEffect, 1 );
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->BaseSlideInEffect, 1 );
  _this->CurrentItem = LauncherLNC_Main_GetInitialSelectedItem( _this );
  _this->NextItem = LauncherLNC_Main_GetNextItem( _this, _this->CurrentItem );
  _this->PreviousItem = LauncherLNC_Main_GetPreviousItem( _this, _this->CurrentItem );
  LauncherLNC_Base_SetItems( &_this->LNC_Base, _this->PreviousItem, _this->CurrentItem, 
  _this->NextItem );
  LauncherLNC_RotaryPlate_SetItems( &_this->LNC_RotaryPlate, _this->PreviousItem, 
  _this->CurrentItem, _this->NextItem );
}

/* 'C' function for method : 'Launcher::LNC_Main.OnShortDownKeyActivated()' */
void LauncherLNC_Main_OnShortDownKeyActivated( LauncherLNC_Main _this )
{
  ComponentsBaseComponent__OnShortDownKeyActivated( &_this->LNC_RotaryPlate );
}

/* 'C' function for method : 'Launcher::LNC_Main.OnShortUpKeyActivated()' */
void LauncherLNC_Main_OnShortUpKeyActivated( LauncherLNC_Main _this )
{
  ComponentsBaseComponent__OnShortUpKeyActivated( &_this->LNC_RotaryPlate );
}

/* 'C' function for method : 'Launcher::LNC_Main.OnShortEnterKeyActivated()' */
void LauncherLNC_Main_OnShortEnterKeyActivated( LauncherLNC_Main _this )
{
  if (( EnumLauncherItemSETTINGS == _this->CurrentItem ) && DeviceInterfaceVehicleDeviceClass_OnGetDDModeActivated( 
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
    ;
  else
  {
    LauncherLNC_RotaryPlate_StartSelectedAnimation( &_this->LNC_RotaryPlate );
  }
}

/* 'C' function for method : 'Launcher::LNC_Main.OnShortHomeKeyActivated()' */
void LauncherLNC_Main_OnShortHomeKeyActivated( LauncherLNC_Main _this )
{
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->BaseSlideOutEffect, 1 );
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->RotaryPlateSlideOutEffect, 1 );
}

/* 'C' function for method : 'Launcher::LNC_Main.OnLongEnterKeyActivated()' */
void LauncherLNC_Main_OnLongEnterKeyActivated( LauncherLNC_Main _this )
{
  if ( 1 == _this->Super1.KeyHandler.RepetitionCount )
  {
    ComponentsBaseComponent ItemDialog = 0;

    switch ( _this->CurrentItem )
    {
      case EnumLauncherItemSEAT_HEATER :
      {
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
        = EnumVehicleSupportedFunctionSEAT_HEATER;
        DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeHEATER_SELECT, 1 );
        ItemDialog = ((ComponentsBaseComponent)EwNewObject( SeatHeater_GripWarmerSHT02_GPW02_Main, 
        0 ));
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)ItemDialog ), 0, 0, 
        0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
      break;

      case EnumLauncherItemGRIP_WARMER :
      {
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
        = EnumVehicleSupportedFunctionGRIP_WARMER;
        DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeHEATER_SELECT, 0 );
        ItemDialog = ((ComponentsBaseComponent)EwNewObject( SeatHeater_GripWarmerSHT02_GPW02_Main, 
        0 ));
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)ItemDialog ), 0, 0, 
        0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
      break;

      case EnumLauncherItemODO_TRIP :
      {
        DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
          EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
          EnumVehicleRxTypeODO_TRIP_DISPLAY );
        XEnum OdoTripSetting = (XEnum)VehicleData->DataUInt32;
        XEnum SelectedMeterInfo = EnumMeterInfoTOTAL;

        switch ( OdoTripSetting )
        {
          case EnumOdoTripSettingItemTRIP1 :
            SelectedMeterInfo = EnumMeterInfoTRIP1;
          break;

          case EnumOdoTripSettingItemTRIP2 :
            SelectedMeterInfo = EnumMeterInfoTRIP2;
          break;

          case EnumOdoTripSettingItemTRIP_F :
            SelectedMeterInfo = EnumMeterInfoTRIP_F;
          break;

          default : 
            ;
        }

        if ( EnumMeterInfoTOTAL != SelectedMeterInfo )
        {
          PopPOP04_Reset ResetDialog = EwNewObject( PopPOP04_Reset, 0 );
          ResetDialog->SelectedMeterInfo = SelectedMeterInfo;
          CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)ResetDialog ), 0, 
          0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
        }
      }
      break;

      default : 
        ;
    }
  }
}

/* 'C' function for method : 'Launcher::LNC_Main.OnCurrentItemChangedSlot()' */
void LauncherLNC_Main_OnCurrentItemChangedSlot( LauncherLNC_Main _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->PreviousItem = _this->LNC_RotaryPlate.PreviousItem;
  _this->CurrentItem = _this->LNC_RotaryPlate.CurrentItem;
  _this->NextItem = _this->LNC_RotaryPlate.NextItem;
  LauncherLNC_Base_SetItems( &_this->LNC_Base, _this->PreviousItem, _this->CurrentItem, 
  _this->NextItem );
}

/* 'C' function for method : 'Launcher::LNC_Main.GetInitialSelectedItem()' */
XEnum LauncherLNC_Main_GetInitialSelectedItem( LauncherLNC_Main _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( DeviceInterfaceNotificationDeviceClass_IsPhoneCallStateActive( EwGetAutoObject( 
      &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )))
    return EnumLauncherItemPHONE;
  else
    return EnumLauncherItemMUSIC;
}

/* 'C' function for method : 'Launcher::LNC_Main.GetNextItem()' */
XEnum LauncherLNC_Main_GetNextItem( LauncherLNC_Main _this, XEnum aBaseItem )
{
  XUInt32 TotalItemNum = 11;
  XEnum BaseItemNext = aBaseItem;
  XBool bypass = 0;

  do
  {
    BaseItemNext = (XEnum)(((XUInt32)BaseItemNext + 1 ) % TotalItemNum );

    if ((((( EnumLauncherItemSEAT_HEATER == BaseItemNext ) && !_this->SeatHeaterEnabled ) 
        || (( EnumLauncherItemGRIP_WARMER == BaseItemNext ) && !_this->GripWarmerEnabled )) 
        || (( EnumLauncherItemWIND_SCREEN == BaseItemNext ) && !_this->WindScreenEnabled )) 
        || (( EnumLauncherItemPHONE == BaseItemNext ) && !DeviceInterfaceNotificationDeviceClass_IsPhoneCallStateActive( 
        EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass ))))
    {
      bypass = 1;
    }
    else
    {
      bypass = 0;
    }
  }
  while ( bypass );

  return BaseItemNext;
}

/* 'C' function for method : 'Launcher::LNC_Main.GetPreviousItem()' */
XEnum LauncherLNC_Main_GetPreviousItem( LauncherLNC_Main _this, XEnum aBaseItem )
{
  XUInt32 TotalItemNum = 11;
  XEnum BaseItemPrevious = aBaseItem;
  XBool bypass = 0;

  do
  {
    BaseItemPrevious = (XEnum)((((XUInt32)BaseItemPrevious + TotalItemNum ) - 1 ) 
    % TotalItemNum );

    if ((((( EnumLauncherItemSEAT_HEATER == BaseItemPrevious ) && !_this->SeatHeaterEnabled ) 
        || (( EnumLauncherItemGRIP_WARMER == BaseItemPrevious ) && !_this->GripWarmerEnabled )) 
        || (( EnumLauncherItemWIND_SCREEN == BaseItemPrevious ) && !_this->WindScreenEnabled )) 
        || (( EnumLauncherItemPHONE == BaseItemPrevious ) && !DeviceInterfaceNotificationDeviceClass_IsPhoneCallStateActive( 
        EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass ))))
    {
      bypass = 1;
    }
    else
    {
      bypass = 0;
    }
  }
  while ( bypass );

  return BaseItemPrevious;
}

/* 'C' function for method : 'Launcher::LNC_Main.OnSelectedAnimationFinishedSlot()' */
void LauncherLNC_Main_OnSelectedAnimationFinishedSlot( LauncherLNC_Main _this, XObject 
  sender )
{
  ComponentsBaseComponent ItemDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ItemDialog = 0;

  switch ( _this->CurrentItem )
  {
    case EnumLauncherItemPHONE :
    {
      if ( DeviceInterfaceNotificationDeviceClass_IsPhoneCallStateActive( EwGetAutoObject( 
          &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )))
      {
        ItemDialog = ((ComponentsBaseComponent)EwNewObject( TelephoneTEL02_ActiveCall, 
        0 ));
      }
      else
      {
        ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
      }
    }
    break;

    case EnumLauncherItemMUSIC :
    {
      if ( DeviceInterfaceMediaManagerDeviceClass_IsAmsConnected( EwGetAutoObject( 
          &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )))
      {
        ItemDialog = ((ComponentsBaseComponent)EwNewObject( MediaMED01_MediaUI, 
        0 ));
      }
      else
        if ( DeviceInterfaceBluetoothDeviceClass_IsMotoconConnected( EwGetAutoObject( 
            &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )))
        {
          ItemDialog = ((ComponentsBaseComponent)EwNewObject( MediaMED01_MediaUI, 
          0 ));
        }
        else
        {
          ItemDialog = ((ComponentsBaseComponent)EwNewObject( PopPOP09_BleConnectionErrorUI, 
          0 ));
        }
    }
    break;

    case EnumLauncherItemODO_TRIP :
      ItemDialog = ((ComponentsBaseComponent)EwNewObject( InfoINF26_ODO_TRIP_SettingMenu, 
      0 ));
    break;

    case EnumLauncherItemMETER_DISPLAY :
      ItemDialog = ((ComponentsBaseComponent)EwNewObject( InfoINF01_MeterDisplaySettingMenu, 
      0 ));
    break;

    case EnumLauncherItemNAVIGATION :
      ItemDialog = ((ComponentsBaseComponent)EwNewObject( NavigationNAV06_NaviSettingMenu, 
      0 ));
    break;

    case EnumLauncherItemNOTIFICATION :
    {
      if ( DeviceInterfaceBluetoothDeviceClass_IsMotoconConnected( EwGetAutoObject( 
          &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )))
      {
        ItemDialog = ((ComponentsBaseComponent)EwNewObject( NotificationNTF01_NotificationList, 
        0 ));
      }
      else
      {
        ItemDialog = ((ComponentsBaseComponent)EwNewObject( PopPOP09_BleConnectionErrorUI, 
        0 ));
      }
    }
    break;

    case EnumLauncherItemWEATHER :
    {
      if ( DeviceInterfaceBluetoothDeviceClass_IsMotoconConnected( EwGetAutoObject( 
          &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )))
      {
        ItemDialog = ((ComponentsBaseComponent)EwNewObject( PopPOP08_WeatherLoadingUI, 
        0 ));
      }
      else
      {
        ItemDialog = ((ComponentsBaseComponent)EwNewObject( PopPOP09_BleConnectionErrorUI, 
        0 ));
      }
    }
    break;

    case EnumLauncherItemSETTINGS :
      ItemDialog = ((ComponentsBaseComponent)EwNewObject( SettingsSET01_MainSettingMenu, 
      0 ));
    break;

    case EnumLauncherItemSEAT_HEATER :
    {
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
      = EnumVehicleSupportedFunctionSEAT_HEATER;
      ItemDialog = ((ComponentsBaseComponent)EwNewObject( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction, 
      0 ));
    }
    break;

    case EnumLauncherItemGRIP_WARMER :
    {
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
      = EnumVehicleSupportedFunctionGRIP_WARMER;
      ItemDialog = ((ComponentsBaseComponent)EwNewObject( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction, 
      0 ));
    }
    break;

    case EnumLauncherItemWIND_SCREEN :
    {
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
      = EnumVehicleSupportedFunctionWIND_SCREEN;
      ItemDialog = ((ComponentsBaseComponent)EwNewObject( SeatHeater_GripWarmerSHT01_GPW01_WSC01_VehicleFunction, 
      0 ));
    }
    break;

    default : 
      ;
  }

  if ( ItemDialog != 0 )
  {
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)ItemDialog ), 0, 0, 0, 
    0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* 'C' function for method : 'Launcher::LNC_Main.OnSlideOutFinishedSlot()' */
void LauncherLNC_Main_OnSlideOutFinishedSlot( LauncherLNC_Main _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( !_this->BaseSlideOutEffect.Super1.Enabled && !_this->RotaryPlateSlideOutEffect.Super1.Enabled )
  {
    CoreGroup_DismissDialog( _this->Super4.Owner, ((CoreGroup)_this ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 0 );
  }
}

/* Dismiss dialogs presented from launcher */
void LauncherLNC_Main_DismissChildDialogs( LauncherLNC_Main _this )
{
  while ( CoreGroup_CountDialogs((CoreGroup)_this ) > 0 )
  {
    EwTrace( "%s%$", EwLoadString( &_Const0007 ), EwClassOf(((XObject)CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
      0 ))));
    CoreGroup_DismissDialog((CoreGroup)_this, CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
    0 ), 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* 'C' function for method : 'Launcher::LNC_Main.GetVehicleSupportedFeature()' */
void LauncherLNC_Main_GetVehicleSupportedFeature( LauncherLNC_Main _this )
{
  _this->SeatHeaterEnabled = DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( 
  EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
  EnumVehicleSupportedFunctionSEAT_HEATER );
  _this->GripWarmerEnabled = DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( 
  EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
  EnumVehicleSupportedFunctionGRIP_WARMER );
  _this->WindScreenEnabled = DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( 
  EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
  EnumVehicleSupportedFunctionWIND_SCREEN );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void LauncherLNC_Main_OnVehicleDataReceivedSlot( LauncherLNC_Main _this, XObject 
  sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if ( VehicleData != 0 )
  {
    switch ( VehicleData->RxType )
    {
      case EnumVehicleRxTypeSUPPORT_FUNC_GRIP_WARMER :
        _this->GripWarmerEnabled = DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        EnumVehicleSupportedFunctionGRIP_WARMER );
      break;

      case EnumVehicleRxTypeSUPPORT_FUNC_SEAT_HEATER :
        _this->SeatHeaterEnabled = DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        EnumVehicleSupportedFunctionSEAT_HEATER );
      break;

      case EnumVehicleRxTypeSUPPORT_FUNC_WIND_SCREEN :
        _this->WindScreenEnabled = DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        EnumVehicleSupportedFunctionWIND_SCREEN );
      break;

      case EnumVehicleRxTypeGRIP_WARMER_STATUS :
      {
        XBool IsGripWarmerItemDisplayed = (XBool)((( EnumLauncherItemGRIP_WARMER 
          == _this->PreviousItem ) || ( EnumLauncherItemGRIP_WARMER == _this->CurrentItem )) 
          || ( EnumLauncherItemGRIP_WARMER == _this->NextItem ));

        if ( IsGripWarmerItemDisplayed )
        {
          LauncherLNC_RotaryPlate_SetItems( &_this->LNC_RotaryPlate, _this->PreviousItem, 
          _this->CurrentItem, _this->NextItem );
        }
      }
      break;

      case EnumVehicleRxTypeSEAT_HEATER_STATUS :
      {
        XBool IsSeatHeaterItemDisplayed = (XBool)((( EnumLauncherItemSEAT_HEATER 
          == _this->PreviousItem ) || ( EnumLauncherItemSEAT_HEATER == _this->CurrentItem )) 
          || ( EnumLauncherItemSEAT_HEATER == _this->NextItem ));

        if ( IsSeatHeaterItemDisplayed )
        {
          LauncherLNC_RotaryPlate_SetItems( &_this->LNC_RotaryPlate, _this->PreviousItem, 
          _this->CurrentItem, _this->NextItem );
        }
      }
      break;

      default : 
        ;
    }
  }
}

/* Variants derived from the class : 'Launcher::LNC_Main' */
EW_DEFINE_CLASS_VARIANTS( LauncherLNC_Main )
EW_END_OF_CLASS_VARIANTS( LauncherLNC_Main )

/* Virtual Method Table (VMT) for the class : 'Launcher::LNC_Main' */
EW_DEFINE_CLASS( LauncherLNC_Main, ComponentsBaseComponent, BaseSlideInEffect, BaseSlideInEffect, 
                 BaseSlideInEffect, BaseSlideInEffect, NextItem, NextItem, "Launcher::LNC_Main" )
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
  LauncherLNC_Main_OnShortDownKeyActivated,
  LauncherLNC_Main_OnShortUpKeyActivated,
  LauncherLNC_Main_OnShortEnterKeyActivated,
  LauncherLNC_Main_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  LauncherLNC_Main_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( LauncherLNC_Main )

/* Initializer for the class 'Launcher::LNC_RotaryPlate' */
void LauncherLNC_RotaryPlate__Init( LauncherLNC_RotaryPlate _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( LauncherLNC_RotaryPlate );

  /* ... then construct all embedded objects */
  EffectsRectEffect__Init( &_this->RectEffect0, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->RectEffect1, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->RectEffect2, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->RectEffect3, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->SelectedAnimationTimer, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->BaseImage, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Icon0, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Icon1, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Icon2, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Icon3, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->IconSelectedLarge, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->HighlightImage, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( LauncherLNC_RotaryPlate );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0008 );
  _this->RotationDirection = EnumRotationDirectionCLOCKWISE;
  _this->IconPositions[ 0 ] = _Const0009;
  _this->IconPositions[ 1 ] = _Const000A;
  _this->IconPositions[ 2 ] = _Const000B;
  _this->IconPositions[ 3 ] = _Const000C;
  _this->IconPositions[ 4 ] = _Const000D;
  _this->SelectedIconIdx = 1;
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->RectEffect0, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->RectEffect0, 150 );
  _this->RectEffect0.Value2 = _Const000E;
  _this->RectEffect0.Value1 = _Const000E;
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->RectEffect1, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->RectEffect1, 150 );
  _this->RectEffect1.Value2 = _Const000E;
  _this->RectEffect1.Value1 = _Const000E;
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->RectEffect2, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->RectEffect2, 150 );
  _this->RectEffect2.Value2 = _Const000E;
  _this->RectEffect2.Value1 = _Const000E;
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->RectEffect3, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->RectEffect3, 150 );
  _this->RectEffect3.Value2 = _Const000E;
  _this->RectEffect3.Value1 = _Const000E;
  CoreTimer_OnSetPeriod( &_this->SelectedAnimationTimer, 100 );
  CoreRectView__OnSetBounds( &_this->BaseImage, _Const0008 );
  CoreView_OnSetLayout((CoreView)&_this->Icon0, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->Icon0, _Const000A );
  ViewsImage_OnSetFrameNumber( &_this->Icon0, 1 );
  CoreView_OnSetLayout((CoreView)&_this->Icon1, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->Icon1, _Const000B );
  ViewsImage_OnSetFrameNumber( &_this->Icon1, 1 );
  ViewsImage_OnSetVisible( &_this->Icon1, 0 );
  CoreView_OnSetLayout((CoreView)&_this->Icon2, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->Icon2, _Const000C );
  ViewsImage_OnSetFrameNumber( &_this->Icon2, 1 );
  CoreView_OnSetLayout((CoreView)&_this->Icon3, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->Icon3, _Const000F );
  ViewsImage_OnSetFrameNumber( &_this->Icon3, 1 );
  CoreView_OnSetLayout((CoreView)&_this->IconSelectedLarge, CoreLayoutAlignToLeft 
  | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->IconSelectedLarge, _Const0010 );
  ViewsImage_OnSetFrameNumber( &_this->IconSelectedLarge, 1 );
  ViewsImage_OnSetVisible( &_this->IconSelectedLarge, 1 );
  CoreRectView__OnSetBounds( &_this->HighlightImage, _Const0011 );
  ViewsImage_OnSetVisible( &_this->HighlightImage, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BaseImage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Icon0 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Icon1 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Icon2 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Icon3 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->IconSelectedLarge ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->HighlightImage ), 0 );
  _this->Icons[ 0 ] = &_this->Icon0;
  _this->Icons[ 1 ] = &_this->Icon1;
  _this->Icons[ 2 ] = &_this->Icon2;
  _this->Icons[ 3 ] = &_this->Icon3;
  _this->RectEffectArray[ 0 ] = &_this->RectEffect0;
  _this->RectEffectArray[ 1 ] = &_this->RectEffect1;
  _this->RectEffectArray[ 2 ] = &_this->RectEffect2;
  _this->RectEffectArray[ 3 ] = &_this->RectEffect3;
  _this->SelectedAnimationTimer.OnTrigger = EwNewSlot( _this, LauncherLNC_RotaryPlate_OnSelectedAnimationFinishedSlot );
  ViewsImage_OnSetBitmap( &_this->BaseImage, EwLoadResource( &ResourceLCBase, ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Icon0, EwLoadResource( &ResourceIconMusicSmall, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Icon1, EwLoadResource( &ResourceIconMusicSmall, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Icon2, EwLoadResource( &ResourceIconPhoneSmall, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Icon3, EwLoadResource( &ResourceIconSettingSmall, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->IconSelectedLarge, EwLoadResource( &ResourceIconMusicLarge, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->HighlightImage, EwLoadResource( &ResourceLCHighlight, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'Launcher::LNC_RotaryPlate' */
void LauncherLNC_RotaryPlate__ReInit( LauncherLNC_RotaryPlate _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  EffectsRectEffect__ReInit( &_this->RectEffect0 );
  EffectsRectEffect__ReInit( &_this->RectEffect1 );
  EffectsRectEffect__ReInit( &_this->RectEffect2 );
  EffectsRectEffect__ReInit( &_this->RectEffect3 );
  CoreTimer__ReInit( &_this->SelectedAnimationTimer );
  ViewsImage__ReInit( &_this->BaseImage );
  ViewsImage__ReInit( &_this->Icon0 );
  ViewsImage__ReInit( &_this->Icon1 );
  ViewsImage__ReInit( &_this->Icon2 );
  ViewsImage__ReInit( &_this->Icon3 );
  ViewsImage__ReInit( &_this->IconSelectedLarge );
  ViewsImage__ReInit( &_this->HighlightImage );
}

/* Finalizer method for the class 'Launcher::LNC_RotaryPlate' */
void LauncherLNC_RotaryPlate__Done( LauncherLNC_RotaryPlate _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  EffectsRectEffect__Done( &_this->RectEffect0 );
  EffectsRectEffect__Done( &_this->RectEffect1 );
  EffectsRectEffect__Done( &_this->RectEffect2 );
  EffectsRectEffect__Done( &_this->RectEffect3 );
  CoreTimer__Done( &_this->SelectedAnimationTimer );
  ViewsImage__Done( &_this->BaseImage );
  ViewsImage__Done( &_this->Icon0 );
  ViewsImage__Done( &_this->Icon1 );
  ViewsImage__Done( &_this->Icon2 );
  ViewsImage__Done( &_this->Icon3 );
  ViewsImage__Done( &_this->IconSelectedLarge );
  ViewsImage__Done( &_this->HighlightImage );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.OnShortDownKeyActivated()' */
void LauncherLNC_RotaryPlate_OnShortDownKeyActivated( LauncherLNC_RotaryPlate _this )
{
  LauncherLNC_RotaryPlate_StartIconRotation( _this, EnumRotationDirectionCOUNTER_CLOCKWISE );
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.OnShortUpKeyActivated()' */
void LauncherLNC_RotaryPlate_OnShortUpKeyActivated( LauncherLNC_RotaryPlate _this )
{
  LauncherLNC_RotaryPlate_StartIconRotation( _this, EnumRotationDirectionCLOCKWISE );
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.StartIconRotation()' */
void LauncherLNC_RotaryPlate_StartIconRotation( LauncherLNC_RotaryPlate _this, XEnum 
  aDirection )
{
  LauncherLNC_Main LNCMainDialog;
  XInt32 HiddenIconIdx;
  XInt32 IconIdx;
  XInt32 i;

  _this->RotationDirection = aDirection;
  LNCMainDialog = EwCastObject( _this->Super4.Owner, LauncherLNC_Main );

  if ( EnumRotationDirectionCLOCKWISE == aDirection )
  {
    _this->HiddenItem = LauncherLNC_Main_GetPreviousItem( LNCMainDialog, _this->PreviousItem );
  }
  else
  {
    _this->HiddenItem = LauncherLNC_Main_GetNextItem( LNCMainDialog, _this->NextItem );
  }

  HiddenIconIdx = ( _this->SelectedIconIdx + 2 ) % 4;
  ViewsImage_OnSetBitmap( _this->Icons[ EwCheckIndex( HiddenIconIdx, 4 )], LauncherLNC_RotaryPlate_GetSmallIconResourceOfItem( 
  _this, _this->HiddenItem ));
  ViewsImage_OnSetVisible( &_this->IconSelectedLarge, 0 );
  ViewsImage_OnSetVisible( _this->Icons[ EwCheckIndex( _this->SelectedIconIdx, 4 )], 
  1 );
  IconIdx = 0;
  i = 0;

  for ( i = 0; i < 4; i = i + 1 )
  {
    EffectsRectEffect Effect = _this->RectEffectArray[ EwCheckIndex( i, 4 )];

    if ( EnumRotationDirectionCLOCKWISE == aDirection )
    {
      IconIdx = ((( _this->SelectedIconIdx - 2 ) + i ) + 4 ) % 4;
      Effect->Value1 = _this->IconPositions[ EwCheckIndex( i, 5 )];
      Effect->Value2 = _this->IconPositions[ EwCheckIndex( i + 1, 5 )];
    }
    else
    {
      IconIdx = ((( _this->SelectedIconIdx - 1 ) + i ) + 4 ) % 4;
      Effect->Value1 = _this->IconPositions[ EwCheckIndex( i + 1, 5 )];
      Effect->Value2 = _this->IconPositions[ EwCheckIndex( i, 5 )];
    }

    if ( _this->SelectedIconIdx == IconIdx )
    {
      Effect->Super1.OnFinished = EwNewSlot( _this, LauncherLNC_RotaryPlate_OnIconRotationFinished );
    }
    else
    {
      Effect->Super1.OnFinished = EwNullSlot;
    }

    Effect->Outlet = EwNewRef( _this->Icons[ EwCheckIndex( IconIdx, 4 )], CoreRectView_OnGetBounds, 
    CoreRectView__OnSetBounds );
    EffectsEffect_OnSetEnabled((EffectsEffect)Effect, 1 );
  }
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.OnIconRotationFinished()' */
void LauncherLNC_RotaryPlate_OnIconRotationFinished( LauncherLNC_RotaryPlate _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EnumRotationDirectionCLOCKWISE == _this->RotationDirection )
  {
    _this->SelectedIconIdx = (( _this->SelectedIconIdx - 1 ) + 4 ) % 4;
    _this->NextItem = _this->CurrentItem;
    _this->CurrentItem = _this->PreviousItem;
    _this->PreviousItem = _this->HiddenItem;
  }
  else
  {
    _this->SelectedIconIdx = ( _this->SelectedIconIdx + 1 ) % 4;
    _this->PreviousItem = _this->CurrentItem;
    _this->CurrentItem = _this->NextItem;
    _this->NextItem = _this->HiddenItem;
  }

  ViewsImage_OnSetBitmap( &_this->IconSelectedLarge, LauncherLNC_RotaryPlate_GetLargeIconResourceOfItem( 
  _this, _this->CurrentItem ));
  ViewsImage_OnSetVisible( _this->Icons[ EwCheckIndex( _this->SelectedIconIdx, 4 )], 
  0 );
  ViewsImage_OnSetVisible( &_this->IconSelectedLarge, 1 );
  EwPostSignal( _this->OnIconsRotated, ((XObject)_this ));
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.SetItems()' */
void LauncherLNC_RotaryPlate_SetItems( LauncherLNC_RotaryPlate _this, XEnum aPreviousItem, 
  XEnum aCurrentItem, XEnum aNextItem )
{
  XInt32 PeviousIconIdx;
  XInt32 NextIconIdx;

  EwTrace( "%s%e", EwLoadString( &_Const0012 ), aCurrentItem );
  _this->PreviousItem = aPreviousItem;
  _this->CurrentItem = aCurrentItem;
  _this->NextItem = aNextItem;
  ViewsImage_OnSetBitmap( _this->Icons[ EwCheckIndex( _this->SelectedIconIdx, 4 )], 
  LauncherLNC_RotaryPlate_GetSmallIconResourceOfItem( _this, _this->CurrentItem ));
  ViewsImage_OnSetBitmap( &_this->IconSelectedLarge, LauncherLNC_RotaryPlate_GetLargeIconResourceOfItem( 
  _this, _this->CurrentItem ));
  PeviousIconIdx = (( _this->SelectedIconIdx - 1 ) + 4 ) % 4;
  ViewsImage_OnSetBitmap( _this->Icons[ EwCheckIndex( PeviousIconIdx, 4 )], LauncherLNC_RotaryPlate_GetSmallIconResourceOfItem( 
  _this, _this->PreviousItem ));
  NextIconIdx = ( _this->SelectedIconIdx + 1 ) % 4;
  ViewsImage_OnSetBitmap( _this->Icons[ EwCheckIndex( NextIconIdx, 4 )], LauncherLNC_RotaryPlate_GetSmallIconResourceOfItem( 
  _this, _this->NextItem ));
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.GetSmallIconResourceOfItem()' */
ResourcesBitmap LauncherLNC_RotaryPlate_GetSmallIconResourceOfItem( LauncherLNC_RotaryPlate _this, 
  XEnum aItem )
{
  ResourcesBitmap IconBitmap;
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IconBitmap = 0;

  switch ( aItem )
  {
    case EnumLauncherItemPHONE :
      IconBitmap = EwLoadResource( &ResourceIconPhoneSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemMUSIC :
      IconBitmap = EwLoadResource( &ResourceIconMusicSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemODO_TRIP :
      IconBitmap = EwLoadResource( &ResourceIconOdoTripSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemMETER_DISPLAY :
      IconBitmap = EwLoadResource( &ResourceIconThemeSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemNAVIGATION :
      IconBitmap = EwLoadResource( &ResourceIconNavigationSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemNOTIFICATION :
      IconBitmap = EwLoadResource( &ResourceIconNotificationSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemWEATHER :
      IconBitmap = EwLoadResource( &ResourceIconWeatherSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemSETTINGS :
      IconBitmap = EwLoadResource( &ResourceIconSettingSmall, ResourcesBitmap );
    break;

    case EnumLauncherItemSEAT_HEATER :
    {
      VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeSEAT_HEATER_STATUS );

      if ((( VehicleData != 0 ) && ( 3 >= VehicleData->DataUInt32 )) && ( VehicleData->DataUInt32 
          >= 0 ))
      {
        XEnum HeaterSettingStatus = (XEnum)VehicleData->DataUInt32;

        switch ( HeaterSettingStatus )
        {
          case EnumHeaterSettingStatusTypeOFF :
            IconBitmap = EwLoadResource( &ResourceIconSeatHeater0Small, ResourcesBitmap );
          break;

          case EnumHeaterSettingStatusTypeLOW :
            IconBitmap = EwLoadResource( &ResourceIconSeatHeater1Small, ResourcesBitmap );
          break;

          case EnumHeaterSettingStatusTypeMID :
            IconBitmap = EwLoadResource( &ResourceIconSeatHeater2Small, ResourcesBitmap );
          break;

          case EnumHeaterSettingStatusTypeHIGH :
            IconBitmap = EwLoadResource( &ResourceIconSeatHeater3Small, ResourcesBitmap );
          break;

          default : 
            ;
        }
      }
    }
    break;

    case EnumLauncherItemGRIP_WARMER :
    {
      VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeGRIP_WARMER_STATUS );

      if ((( VehicleData != 0 ) && ( 3 >= VehicleData->DataUInt32 )) && ( VehicleData->DataUInt32 
          >= 0 ))
      {
        XEnum HeaterSettingStatus = (XEnum)VehicleData->DataUInt32;

        switch ( HeaterSettingStatus )
        {
          case EnumHeaterSettingStatusTypeOFF :
            IconBitmap = EwLoadResource( &ResourceIconGripWarmer0Small, ResourcesBitmap );
          break;

          case EnumHeaterSettingStatusTypeLOW :
            IconBitmap = EwLoadResource( &ResourceIconGripWarmer1Small, ResourcesBitmap );
          break;

          case EnumHeaterSettingStatusTypeMID :
            IconBitmap = EwLoadResource( &ResourceIconGripWarmer2Small, ResourcesBitmap );
          break;

          case EnumHeaterSettingStatusTypeHIGH :
            IconBitmap = EwLoadResource( &ResourceIconGripWarmer3Small, ResourcesBitmap );
          break;

          default : 
            ;
        }
      }
    }
    break;

    case EnumLauncherItemWIND_SCREEN :
      IconBitmap = EwLoadResource( &ResourceIconWindScreenSmall, ResourcesBitmap );
    break;

    default : 
      ;
  }

  return IconBitmap;
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.GetLargeIconResourceOfItem()' */
ResourcesBitmap LauncherLNC_RotaryPlate_GetLargeIconResourceOfItem( LauncherLNC_RotaryPlate _this, 
  XEnum aItem )
{
  ResourcesBitmap IconBitmap;
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IconBitmap = 0;

  switch ( aItem )
  {
    case EnumLauncherItemPHONE :
      IconBitmap = EwLoadResource( &ResourceIconPhoneLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemMUSIC :
      IconBitmap = EwLoadResource( &ResourceIconMusicLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemODO_TRIP :
      IconBitmap = EwLoadResource( &ResourceIconOdoTripLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemMETER_DISPLAY :
      IconBitmap = EwLoadResource( &ResourceIconThemeLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemNAVIGATION :
      IconBitmap = EwLoadResource( &ResourceIconNavigationLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemNOTIFICATION :
      IconBitmap = EwLoadResource( &ResourceIconNotificationLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemWEATHER :
      IconBitmap = EwLoadResource( &ResourceIconWeatherLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemSETTINGS :
      IconBitmap = EwLoadResource( &ResourceIconSettingLarge, ResourcesBitmap );
    break;

    case EnumLauncherItemSEAT_HEATER :
    {
      VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeSEAT_HEATER_STATUS );

      if ((( VehicleData != 0 ) && ( 3 >= VehicleData->DataUInt32 )) && ( VehicleData->DataUInt32 
          >= 0 ))
      {
        XEnum HeaterSettingStatus = (XEnum)VehicleData->DataUInt32;

        switch ( HeaterSettingStatus )
        {
          case EnumHeaterSettingStatusTypeOFF :
            IconBitmap = EwLoadResource( &ResourceIconSeatHeater0Large, ResourcesBitmap );
          break;

          case EnumHeaterSettingStatusTypeLOW :
            IconBitmap = EwLoadResource( &ResourceIconSeatHeater1Large, ResourcesBitmap );
          break;

          case EnumHeaterSettingStatusTypeMID :
            IconBitmap = EwLoadResource( &ResourceIconSeatHeater2Large, ResourcesBitmap );
          break;

          case EnumHeaterSettingStatusTypeHIGH :
            IconBitmap = EwLoadResource( &ResourceIconSeatHeater3Large, ResourcesBitmap );
          break;

          default : 
            ;
        }
      }
    }
    break;

    case EnumLauncherItemGRIP_WARMER :
    {
      VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeGRIP_WARMER_STATUS );

      if ((( VehicleData != 0 ) && ( 3 >= VehicleData->DataUInt32 )) && ( VehicleData->DataUInt32 
          >= 0 ))
      {
        XEnum HeaterSettingStatus = (XEnum)VehicleData->DataUInt32;

        switch ( HeaterSettingStatus )
        {
          case EnumHeaterSettingStatusTypeOFF :
            IconBitmap = EwLoadResource( &ResourceIconGripWarmer0Large, ResourcesBitmap );
          break;

          case EnumHeaterSettingStatusTypeLOW :
            IconBitmap = EwLoadResource( &ResourceIconGripWarmer1Large, ResourcesBitmap );
          break;

          case EnumHeaterSettingStatusTypeMID :
            IconBitmap = EwLoadResource( &ResourceIconGripWarmer2Large, ResourcesBitmap );
          break;

          case EnumHeaterSettingStatusTypeHIGH :
            IconBitmap = EwLoadResource( &ResourceIconGripWarmer3Large, ResourcesBitmap );
          break;

          default : 
            ;
        }
      }
    }
    break;

    case EnumLauncherItemWIND_SCREEN :
      IconBitmap = EwLoadResource( &ResourceIconWindScreenLarge, ResourcesBitmap );
    break;

    default : 
      ;
  }

  return IconBitmap;
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.StartSelectedAnimation()' */
void LauncherLNC_RotaryPlate_StartSelectedAnimation( LauncherLNC_RotaryPlate _this )
{
  ViewsImage_OnSetVisible( &_this->HighlightImage, 1 );
  CoreTimer_OnSetEnabled( &_this->SelectedAnimationTimer, 1 );
}

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.OnSelectedAnimationFinishedSlot()' */
void LauncherLNC_RotaryPlate_OnSelectedAnimationFinishedSlot( LauncherLNC_RotaryPlate _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsImage_OnSetVisible( &_this->HighlightImage, 0 );
  CoreTimer_OnSetEnabled( &_this->SelectedAnimationTimer, 0 );
  EwPostSignal( _this->OnSelectedAnimationFinished, ((XObject)_this ));
}

/* Variants derived from the class : 'Launcher::LNC_RotaryPlate' */
EW_DEFINE_CLASS_VARIANTS( LauncherLNC_RotaryPlate )
EW_END_OF_CLASS_VARIANTS( LauncherLNC_RotaryPlate )

/* Virtual Method Table (VMT) for the class : 'Launcher::LNC_RotaryPlate' */
EW_DEFINE_CLASS( LauncherLNC_RotaryPlate, ComponentsBaseComponent, Icons, OnIconsRotated, 
                 RectEffect0, RectEffect0, IconPositions, IconPositions, "Launcher::LNC_RotaryPlate" )
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
  LauncherLNC_RotaryPlate_OnShortDownKeyActivated,
  LauncherLNC_RotaryPlate_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( LauncherLNC_RotaryPlate )

/* Initializer for the class 'Launcher::LNC_Base' */
void LauncherLNC_Base__Init( LauncherLNC_Base _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( LauncherLNC_Base );

  /* ... then construct all embedded objects */
  ViewsWallpaper__Init( &_this->Background, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ImgLCBlueline, &_this->_XObject, 0 );
  ViewsText__Init( &_this->CurrentItemTitleText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->PreviousItemTitleText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NextItemTitleText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( LauncherLNC_Base );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0001 );
  CoreView_OnSetLayout((CoreView)&_this->Background, CoreLayoutAlignToBottom | CoreLayoutAlignToLeft );
  CoreRectView__OnSetBounds( &_this->Background, _Const0013 );
  CoreRectView__OnSetBounds( &_this->ImgLCBlueline, _Const0014 );
  CoreRectView__OnSetBounds( &_this->CurrentItemTitleText, _Const0015 );
  ViewsText_OnSetAlignment( &_this->CurrentItemTitleText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  CoreRectView__OnSetBounds( &_this->PreviousItemTitleText, _Const0016 );
  ViewsText_OnSetAlignment( &_this->PreviousItemTitleText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->PreviousItemTitleText, 0 );
  ViewsText_OnSetColor( &_this->PreviousItemTitleText, _Const0017 );
  CoreRectView__OnSetBounds( &_this->NextItemTitleText, _Const0018 );
  ViewsText_OnSetAlignment( &_this->NextItemTitleText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->NextItemTitleText, 0 );
  ViewsText_OnSetColor( &_this->NextItemTitleText, _Const0017 );
  CoreGroup__Add( _this, ((CoreView)&_this->Background ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ImgLCBlueline ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CurrentItemTitleText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PreviousItemTitleText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextItemTitleText ), 0 );
  ViewsWallpaper_OnSetBitmap( &_this->Background, EwLoadResource( &ResourceLauncherBG, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ImgLCBlueline, EwLoadResource( &ResourceLCBlueline, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->CurrentItemTitleText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->PreviousItemTitleText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->NextItemTitleText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Launcher::LNC_Base' */
void LauncherLNC_Base__ReInit( LauncherLNC_Base _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsWallpaper__ReInit( &_this->Background );
  ViewsImage__ReInit( &_this->ImgLCBlueline );
  ViewsText__ReInit( &_this->CurrentItemTitleText );
  ViewsText__ReInit( &_this->PreviousItemTitleText );
  ViewsText__ReInit( &_this->NextItemTitleText );
}

/* Finalizer method for the class 'Launcher::LNC_Base' */
void LauncherLNC_Base__Done( LauncherLNC_Base _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsWallpaper__Done( &_this->Background );
  ViewsImage__Done( &_this->ImgLCBlueline );
  ViewsText__Done( &_this->CurrentItemTitleText );
  ViewsText__Done( &_this->PreviousItemTitleText );
  ViewsText__Done( &_this->NextItemTitleText );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* 'C' function for method : 'Launcher::LNC_Base.GetStringOfLauncherItem()' */
XString LauncherLNC_Base_GetStringOfLauncherItem( LauncherLNC_Base _this, XEnum 
  aLauncherItem )
{
  XString Title;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Title = 0;

  switch ( aLauncherItem )
  {
    case EnumLauncherItemPHONE :
      Title = EwLoadString( &StringsLNC_PHONE );
    break;

    case EnumLauncherItemMUSIC :
      Title = EwLoadString( &StringsLNC_MUSIC );
    break;

    case EnumLauncherItemODO_TRIP :
      Title = EwLoadString( &StringsLNC_ODO_TRIP );
    break;

    case EnumLauncherItemMETER_DISPLAY :
      Title = EwLoadString( &StringsLNC_METER_DISPLAY );
    break;

    case EnumLauncherItemNAVIGATION :
      Title = EwLoadString( &StringsLNC_NAVIGATION );
    break;

    case EnumLauncherItemNOTIFICATION :
      Title = EwLoadString( &StringsLNC_NOTIFICATION );
    break;

    case EnumLauncherItemWEATHER :
      Title = EwLoadString( &StringsLNC_WEATHER );
    break;

    case EnumLauncherItemSETTINGS :
      Title = EwLoadString( &StringsLNC_SETTINGS );
    break;

    case EnumLauncherItemSEAT_HEATER :
      Title = EwLoadString( &StringsLNC_SEAT_HEATER );
    break;

    case EnumLauncherItemGRIP_WARMER :
      Title = EwLoadString( &StringsGPW01_GRIP_WARMER );
    break;

    case EnumLauncherItemWIND_SCREEN :
      Title = EwLoadString( &StringsWSC01_WIND_SCREEN );
    break;

    default : 
      ;
  }

  return Title;
}

/* 'C' function for method : 'Launcher::LNC_Base.SetItems()' */
void LauncherLNC_Base_SetItems( LauncherLNC_Base _this, XEnum aPreviousItem, XEnum 
  aCurrentItem, XEnum aNextItem )
{
  ViewsText_OnSetString( &_this->PreviousItemTitleText, LauncherLNC_Base_GetStringOfLauncherItem( 
  _this, aPreviousItem ));
  ViewsText_OnSetString( &_this->CurrentItemTitleText, LauncherLNC_Base_GetStringOfLauncherItem( 
  _this, aCurrentItem ));
  ViewsText_OnSetString( &_this->NextItemTitleText, LauncherLNC_Base_GetStringOfLauncherItem( 
  _this, aNextItem ));
}

/* Variants derived from the class : 'Launcher::LNC_Base' */
EW_DEFINE_CLASS_VARIANTS( LauncherLNC_Base )
EW_END_OF_CLASS_VARIANTS( LauncherLNC_Base )

/* Virtual Method Table (VMT) for the class : 'Launcher::LNC_Base' */
EW_DEFINE_CLASS( LauncherLNC_Base, CoreGroup, Background, Background, Background, 
                 Background, _None, _None, "Launcher::LNC_Base" )
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
EW_END_OF_CLASS( LauncherLNC_Base )

/* Embedded Wizard */
