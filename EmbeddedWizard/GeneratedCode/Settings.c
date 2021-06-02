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
#include "_ClockCLK01_ClockSettingMenu.h"
#include "_ComponentsBaseComponent.h"
#include "_ComponentsBaseMainBG.h"
#include "_CoreGroup.h"
#include "_CorePropertyObserver.h"
#include "_CoreRoot.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DevelopmentDEV_Main.h"
#include "_DeviceInterfaceBluetoothDeviceClass.h"
#include "_DeviceInterfaceBluetoothPairedDeviceInfo.h"
#include "_DeviceInterfaceSystemData.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_DeviceInterfaceVehicleDataClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_EffectsInt32Effect.h"
#include "_MaintenanceMNT01_MaintenanceReset.h"
#include "_MenuBaseMenuView.h"
#include "_MenuItemBase.h"
#include "_MenuItemCheckMark.h"
#include "_MenuItemCheckbox.h"
#include "_MenuItemTimeHourMinute.h"
#include "_MenuItemValueUnit.h"
#include "_MenuItemValueUnit2.h"
#include "_MenuPushButton.h"
#include "_MenuScrollbar.h"
#include "_MenuUpDownPushButtonSet.h"
#include "_MenuVerticalMenu.h"
#include "_PopPOP04_Reset.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesExternBitmap.h"
#include "_ResourcesFont.h"
#include "_SeatHeater_GripWarmerSHT02_GPW02_Main.h"
#include "_SettingsBtFwUpdateDialog.h"
#include "_SettingsLicenseDetail.h"
#include "_SettingsSET01_MainSettingMenu.h"
#include "_SettingsSET03_ConnectionSettingMenu.h"
#include "_SettingsSET04_BtSettingMenu.h"
#include "_SettingsSET05_BtcMaxPairedDevice.h"
#include "_SettingsSET06_BtcDiscovarable.h"
#include "_SettingsSET08_BtcPairDevice.h"
#include "_SettingsSET17_BtcPairedDeviceList.h"
#include "_SettingsSET18_DeleteBleDevice.h"
#include "_SettingsSET19_BtcPairedDeviceOperation.h"
#include "_SettingsSET22_BleAdvertising.h"
#include "_SettingsSET23_BlePairingFail.h"
#include "_SettingsSET24_CheckPairingRecord.h"
#include "_SettingsSET25_BlePincode.h"
#include "_SettingsSET27_ConfirmUpdate.h"
#include "_SettingsSET28_SystemInfo.h"
#include "_SettingsSET30_QRCode.h"
#include "_SettingsSET35_LegalMenu.h"
#include "_SettingsSET37_3rdPartyLicenses.h"
#include "_SettingsSET38_ConfirmAllReset.h"
#include "_SettingsSET39_DeletePairedDevice.h"
#include "_SettingsSET41_ResetInProgress.h"
#include "_SettingsSET42_ResetCompleted.h"
#include "_SettingsSET43_ResetMenu.h"
#include "_SettingsSET45_TripMileageReset.h"
#include "_SettingsSET46_VehicleInfoReset.h"
#include "_SettingsSET9_10_11_BtConnectionResult.h"
#include "_SettingsTimeoutDialog.h"
#include "_TCSTCS01_Main.h"
#include "_TelephoneImageButton.h"
#include "_UnitUNT01_UnitSettingMenu.h"
#include "_ViewsBorder.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "Core.h"
#include "DeviceInterface.h"
#include "Effects.h"
#include "Enum.h"
#include "Fonts.h"
#include "Resource.h"
#include "Settings.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault0[] =
{
  0x00000376, /* ratio 48.76 % */
  0xB8001B00, 0x00092452, 0x00D20037, 0x040003A0, 0x8A002980, 0x0002A000, 0x00198006,
  0x68240A32, 0x8642A110, 0xA44A210E, 0x46473188, 0x1E0B1B00, 0xE1B0B84C, 0x011388C3,
  0xE31000D0, 0x45818124, 0x803C9C14, 0x8A8EA313, 0x54E23540, 0x4865B1E8, 0xDA2D1498,
  0x62D389B0, 0x7F049BC6, 0x33803466, 0x0032800B, 0x802C9CE6, 0x378009D3, 0x64765327,
  0x48E5F209, 0xE2C235A0, 0xA5D1FB1C, 0x711698C8, 0xF3805C9C, 0x7200526D, 0x9B04221D,
  0xA45D4191, 0xC802F340, 0x49EB3573, 0x82BD049D, 0x40064875, 0x858F9698, 0xF6D95C72,
  0x379AD9E8, 0x7BF8264E, 0x87664019, 0x7CE02919, 0x614A52B2, 0x14E40033, 0x00068AD6,
  0x195A9613, 0xB5F36442, 0x459564A5, 0x09A5DACB, 0xB66DE4C0, 0xACC6CD46, 0x09E33729,
  0xC000559C, 0x31F8D001, 0xCE00A243, 0xD31214B8, 0xAA856A21, 0xE3B800DB, 0x16617538,
  0xC6D3972E, 0x562B58FA, 0xB71FDC87, 0x3D800175, 0x901E8CFB, 0x9DDE672B, 0xD40079E1,
  0x99675A29, 0xD5777B7D, 0x9B518DF7, 0x6615E276, 0xC81A49DF, 0x2D735CB7, 0x4B9F97DD,
  0x5DA779D7, 0x87DDDE7A, 0xD0007A9A, 0xA3041196, 0x778514AD, 0x18D6D443, 0x4791A656,
  0x51BF611F, 0x326EDC16, 0x8A62D000, 0x5805B9B9, 0xE465338B, 0xEA2A5AC0, 0x69002336,
  0x87000681, 0x1D06BD04, 0x05811456, 0x81AA8091, 0x3E6D1B45, 0x8CA3958A, 0x1184CD67,
  0x1941648C, 0xA22F4CD3, 0x968C6384, 0x5AA3C95D, 0x1C297193, 0x452D3345, 0xBA636565,
  0x6C49D9E8, 0x00000406, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XStringRes _Const0000 = { _StringsDefault0, 0x0002 };
static const XRect _Const0001 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0002 = {{ 10, 46 }, { 470, 170 }};
static const XRect _Const0003 = {{ 165, 176 }, { 315, 259 }};
static const XRect _Const0004 = {{ 165, 219 }, { 315, 259 }};
static const XRect _Const0005 = {{ 10, 46 }, { 470, 201 }};
static const XStringRes _Const0006 = { _StringsDefault0, 0x000F };
static const XRect _Const0007 = {{ 193, 54 }, { 287, 148 }};
static const XRect _Const0008 = {{ 10, 156 }, { 470, 187 }};
static const XStringRes _Const0009 = { _StringsDefault0, 0x001C };
static const XRect _Const000A = {{ 453, 44 }, { 461, 254 }};
static const XRect _Const000B = {{ 33, 47 }, { 421, 258 }};
static const XStringRes _Const000C = { _StringsDefault0, 0x0029 };
static const XRect _Const000D = {{ 10, 46 }, { 470, 108 }};
static const XRect _Const000E = {{ 10, 170 }, { 470, 201 }};
static const XStringRes _Const000F = { _StringsDefault0, 0x002D };
static const XRect _Const0010 = {{ 10, 108 }, { 470, 170 }};
static const XStringRes _Const0011 = { _StringsDefault0, 0x0034 };
static const XStringRes _Const0012 = { _StringsDefault0, 0x0041 };
static const XStringRes _Const0013 = { _StringsDefault0, 0x0045 };
static const XRect _Const0014 = {{ 10, 50 }, { 470, 236 }};
static const XRect _Const0015 = {{ 0, 36 }, { 480, 38 }};
static const XRect _Const0016 = {{ 10, 45 }, { 470, 169 }};
static const XStringRes _Const0017 = { _StringsDefault0, 0x0049 };
static const XStringRes _Const0018 = { _StringsDefault0, 0x004F };
static const XStringRes _Const0019 = { _StringsDefault0, 0x0054 };
static const XRect _Const001A = {{ 10, 45 }, { 470, 107 }};
static const XRect _Const001B = {{ 10, 107 }, { 470, 169 }};
static const XStringRes _Const001C = { _StringsDefault0, 0x0061 };
static const XStringRes _Const001D = { _StringsDefault0, 0x006E };
static const XStringRes _Const001E = { _StringsDefault0, 0x0079 };
static const XStringRes _Const001F = { _StringsDefault0, 0x0085 };
static const XStringRes _Const0020 = { _StringsDefault0, 0x008F };
static const XStringRes _Const0021 = { _StringsDefault0, 0x009C };
static const XStringRes _Const0022 = { _StringsDefault0, 0x00A5 };
static const XStringRes _Const0023 = { _StringsDefault0, 0x00B9 };
static const XStringRes _Const0024 = { _StringsDefault0, 0x00C6 };
static const XColor _Const0025 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0026 = {{ 80, 60 }, { 380, 210 }};
static const XStringRes _Const0027 = { _StringsDefault0, 0x00D3 };
static const XColor _Const0028 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XStringRes _Const0029 = { _StringsDefault0, 0x00FA };
static const XStringRes _Const002A = { _StringsDefault0, 0x0118 };
static const XRect _Const002B = {{ 174, 63 }, { 306, 195 }};
static const XRect _Const002C = {{ 0, 39 }, { 94, 114 }};
static const XRect _Const002D = {{ 0, 189 }, { 94, 264 }};
static const XRect _Const002E = {{ 0, 114 }, { 95, 189 }};
static const XStringRes _Const002F = { _StringsDefault0, 0x0132 };
static const XRect _Const0030 = {{ 10, 132 }, { 470, 163 }};
static const XRect _Const0031 = {{ 10, 194 }, { 470, 256 }};
static const XRect _Const0032 = {{ 10, 163 }, { 470, 194 }};
static const XRect _Const0033 = {{ 193, 36 }, { 287, 130 }};
static const XStringRes _Const0034 = { _StringsDefault0, 0x0142 };
static const XStringRes _Const0035 = { _StringsDefault0, 0x014F };
static const XStringRes _Const0036 = { _StringsDefault0, 0x015C };
static const XRect _Const0037 = {{ 10, 45 }, { 470, 76 }};
static const XRect _Const0038 = {{ 10, 107 }, { 470, 138 }};
static const XRect _Const0039 = {{ 10, 76 }, { 470, 107 }};
static const XRect _Const003A = {{ 10, 138 }, { 470, 169 }};
static const XRect _Const003B = {{ 95, 176 }, { 385, 259 }};
static const XRect _Const003C = {{ 0, 0 }, { 388, 211 }};
static const XRect _Const003D = {{ 0, 0 }, { 388, 31 }};
static const XRect _Const003E = {{ 0, 61 }, { 388, 1301 }};
static const XStringRes _Const003F = { _StringsDefault0, 0x016A };
static const XStringRes _Const0040 = { _StringsDefault0, 0x017A };
static const XStringRes _Const0041 = { _StringsDefault0, 0x0187 };
static const XStringRes _Const0042 = { _StringsDefault0, 0x0194 };
static const XStringRes _Const0043 = { _StringsDefault0, 0x01A1 };
static const XStringRes _Const0044 = { _StringsDefault0, 0x01AE };

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

/* User defined inline code: 'Settings::Inline' */
#include "BTM_pub.h"
#include "ew_priv.h"

/* Initializer for the class 'Settings::SET01_MainSettingMenu' */
void SettingsSET01_MainSettingMenu__Init( SettingsSET01_MainSettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET01_MainSettingMenu );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET01_MainSettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 9 );
  MenuVerticalMenu_OnSetArrowScrollBarVisible( &_this->Super1.Menu, 1 );

  /* Call the user defined constructor */
  SettingsSET01_MainSettingMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET01_MainSettingMenu' */
void SettingsSET01_MainSettingMenu__ReInit( SettingsSET01_MainSettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Settings::SET01_MainSettingMenu' */
void SettingsSET01_MainSettingMenu__Done( SettingsSET01_MainSettingMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET01_MainSettingMenu_Init( SettingsSET01_MainSettingMenu _this, XHandle 
  aArg )
{
  XInt32 i;
  XInt32 NoOfItems;
  XEnum SettingItem;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  NoOfItems = 0;

  for ( i = 0; i < 10; i++ )
  {
    SettingItem = (XEnum)i;

    switch ( SettingItem )
    {
      case EnumMainSettingItemTRACTION_CONTROL :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionTCS ))
        {
          _this->Settings[ EwCheckIndex( NoOfItems, 10 )] = SettingItem;
          NoOfItems++;
        }
      break;

      case EnumMainSettingItemGRIP_WARMER :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionGRIP_WARMER ))
        {
          _this->Settings[ EwCheckIndex( NoOfItems, 10 )] = SettingItem;
          NoOfItems++;
        }
      break;

      case EnumMainSettingItemSEAT_HEATER :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionSEAT_HEATER ))
        {
          _this->Settings[ EwCheckIndex( NoOfItems, 10 )] = SettingItem;
          NoOfItems++;
        }
      break;

      default : 
      {
        _this->Settings[ EwCheckIndex( NoOfItems, 10 )] = SettingItem;
        NoOfItems++;
      }
    }
  }

  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, NoOfItems );
}

/* 'C' function for method : 'Settings::SET01_MainSettingMenu.LoadItemClass()' */
XClass SettingsSET01_MainSettingMenu_LoadItemClass( SettingsSET01_MainSettingMenu _this, 
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

/* 'C' function for method : 'Settings::SET01_MainSettingMenu.LoadItemTitle()' */
XString SettingsSET01_MainSettingMenu_LoadItemTitle( SettingsSET01_MainSettingMenu _this, 
  XInt32 aItemNo )
{
  XString Title = 0;

  switch ( _this->Settings[ EwCheckIndex( aItemNo, 10 )])
  {
    case EnumMainSettingItemTRACTION_CONTROL :
      Title = EwLoadString( &StringsSET01_TRACTION_CONTROL );
    break;

    case EnumMainSettingItemCONNECTION :
      Title = EwLoadString( &StringsSET01_CONNECTION );
    break;

    case EnumMainSettingItemCLOCK :
      Title = EwLoadString( &StringsSET01_CLOCK );
    break;

    case EnumMainSettingItemBRIGHTNESS :
      Title = EwLoadString( &StringsSET01_BRIGHTNESS );
    break;

    case EnumMainSettingItemUNIT :
      Title = EwLoadString( &StringsSET01_UNIT );
    break;

    case EnumMainSettingItemGRIP_WARMER :
      Title = EwLoadString( &StringsSET01_GRIP_WARMER_SETTINGS );
    break;

    case EnumMainSettingItemSEAT_HEATER :
      Title = EwLoadString( &StringsSET01_SEAT_HEATER_SETTINGS );
    break;

    case EnumMainSettingItemSYSTEM_INFO :
      Title = EwLoadString( &StringsSET01_SYSTEM_INFO );
    break;

    case EnumMainSettingItemLEGAL_INFO :
      Title = EwLoadString( &StringsSET01_LEGAL_INFO );
    break;

    case EnumMainSettingItemINFORMATION_RESET :
      Title = EwLoadString( &StringsSET01_INFO_RESET );
    break;

    default :; 
  }

  return Title;
}

/* 'C' function for method : 'Settings::SET01_MainSettingMenu.OnItemActivate()' */
void SettingsSET01_MainSettingMenu_OnItemActivate( SettingsSET01_MainSettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  ComponentsBaseComponent Dialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  Dialog = 0;

  switch ( _this->Settings[ EwCheckIndex( aItemNo, 10 )])
  {
    case EnumMainSettingItemTRACTION_CONTROL :
      Dialog = ((ComponentsBaseComponent)EwNewObject( TCSTCS01_Main, 0 ));
    break;

    case EnumMainSettingItemCONNECTION :
      if ( !EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->IsHopperTestMode )
        Dialog = ((ComponentsBaseComponent)EwNewObject( SettingsSET03_ConnectionSettingMenu, 
        0 ));
    break;

    case EnumMainSettingItemINFORMATION_RESET :
      Dialog = ((ComponentsBaseComponent)EwNewObject( SettingsSET43_ResetMenu, 0 ));
    break;

    case EnumMainSettingItemCLOCK :
      Dialog = ((ComponentsBaseComponent)EwNewObject( ClockCLK01_ClockSettingMenu, 
      0 ));
    break;

    case EnumMainSettingItemBRIGHTNESS :
      Dialog = ((ComponentsBaseComponent)EwNewObject( BrightnessBRT01_BrightnessSettingMenu, 
      0 ));
    break;

    case EnumMainSettingItemUNIT :
      Dialog = ((ComponentsBaseComponent)EwNewObject( UnitUNT01_UnitSettingMenu, 
      0 ));
    break;

    case EnumMainSettingItemGRIP_WARMER :
    {
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
      = EnumVehicleSupportedFunctionGRIP_WARMER;
      DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
      DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeHEATER_SELECT, 0 );
      Dialog = ((ComponentsBaseComponent)EwNewObject( SeatHeater_GripWarmerSHT02_GPW02_Main, 
      0 ));
    }
    break;

    case EnumMainSettingItemSEAT_HEATER :
    {
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentVehicleFunction 
      = EnumVehicleSupportedFunctionSEAT_HEATER;
      DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
      DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeHEATER_SELECT, 1 );
      Dialog = ((ComponentsBaseComponent)EwNewObject( SeatHeater_GripWarmerSHT02_GPW02_Main, 
      0 ));
    }
    break;

    case EnumMainSettingItemSYSTEM_INFO :
      Dialog = ((ComponentsBaseComponent)EwNewObject( SettingsSET28_SystemInfo, 
      0 ));
    break;

    case EnumMainSettingItemLEGAL_INFO :
      Dialog = ((ComponentsBaseComponent)EwNewObject( SettingsSET35_LegalMenu, 0 ));
    break;

    default :; 
  }

  if ( Dialog != 0 )
  {
    MenuBaseMenuView MenuDialog = EwCastObject( Dialog, MenuBaseMenuView );

    if ( MenuDialog != 0 )
      ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)MenuDialog ));
    else
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)Dialog ), 0, 0, 0, 0, 
      0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* Variants derived from the class : 'Settings::SET01_MainSettingMenu' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET01_MainSettingMenu )
EW_END_OF_CLASS_VARIANTS( SettingsSET01_MainSettingMenu )

/* Virtual Method Table (VMT) for the class : 'Settings::SET01_MainSettingMenu' */
EW_DEFINE_CLASS( SettingsSET01_MainSettingMenu, MenuBaseMenuView, _.VMT, _.VMT, 
                 _.VMT, _.VMT, _.VMT, _.VMT, "Settings::SET01_MainSettingMenu" )
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
  SettingsSET01_MainSettingMenu_LoadItemClass,
  SettingsSET01_MainSettingMenu_LoadItemTitle,
  SettingsSET01_MainSettingMenu_OnItemActivate,
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
EW_END_OF_CLASS( SettingsSET01_MainSettingMenu )

/* Initializer for the class 'Settings::SET03_ConnectionSettingMenu' */
void SettingsSET03_ConnectionSettingMenu__Init( SettingsSET03_ConnectionSettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET03_ConnectionSettingMenu );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET03_ConnectionSettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 2 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsGEN_BLUETOOTH ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsSET03_Y_CONNECT_APP_PAIRING ));

  /* Call the user defined constructor */
  SettingsSET03_ConnectionSettingMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET03_ConnectionSettingMenu' */
void SettingsSET03_ConnectionSettingMenu__ReInit( SettingsSET03_ConnectionSettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Settings::SET03_ConnectionSettingMenu' */
void SettingsSET03_ConnectionSettingMenu__Done( SettingsSET03_ConnectionSettingMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET03_ConnectionSettingMenu_Init( SettingsSET03_ConnectionSettingMenu _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0000 ));
}

/* 'C' function for method : 'Settings::SET03_ConnectionSettingMenu.LoadItemClass()' */
XClass SettingsSET03_ConnectionSettingMenu_LoadItemClass( SettingsSET03_ConnectionSettingMenu _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemBase );
}

/* 'C' function for method : 'Settings::SET03_ConnectionSettingMenu.LoadItemTitle()' */
XString SettingsSET03_ConnectionSettingMenu_LoadItemTitle( SettingsSET03_ConnectionSettingMenu _this, 
  XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < 2 )
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 2 )];

  return title;
}

/* 'C' function for method : 'Settings::SET03_ConnectionSettingMenu.OnItemActivate()' */
void SettingsSET03_ConnectionSettingMenu_OnItemActivate( SettingsSET03_ConnectionSettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  switch ( aItemNo )
  {
    case 0 :
      ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)EwNewObject( 
      SettingsSET04_BtSettingMenu, 0 )));
    break;

    case 1 :
      SettingsSET03_ConnectionSettingMenu_HandleYConnectAppPairing( _this );
    break;

    default :; 
  }
}

/* 'C' function for method : 'Settings::SET03_ConnectionSettingMenu.HandleYConnectAppPairing()' */
void SettingsSET03_ConnectionSettingMenu_HandleYConnectAppPairing( SettingsSET03_ConnectionSettingMenu _this )
{
  if ( DeviceInterfaceBluetoothDeviceClass_IsBtConnected( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
      DeviceInterfaceBluetoothDeviceClass )))
  {
    if ( DeviceInterfaceBluetoothDeviceClass_IsMotoconConnected( EwGetAutoObject( 
        &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )))
    {
      XString ProcessString = EwLoadString( &StringsSET21_BLE_ALREADY_CONNECTED );
      XInt32 LeftIdx = EwStringFind( ProcessString, EwLoadString( &StringsARGUMENT_STR ), 
        0 );
      XInt32 RightIdx = ( EwGetStringLength( ProcessString ) - LeftIdx ) - EwGetStringLength( 
        EwLoadString( &StringsARGUMENT_STR ));
      XString Message = EwConcatString( EwConcatString( EwStringLeft( ProcessString, 
        LeftIdx ), DeviceInterfaceBluetoothDeviceClass_GetBleConnectedDeviceName( 
        EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ))), 
        EwStringRight( ProcessString, RightIdx ));
      SettingsSET03_ConnectionSettingMenu_PresentDialogWithTimeout( _this, Message );
    }
    else
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsSET22_BleAdvertising, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
  else
    SettingsSET03_ConnectionSettingMenu_PresentDialogWithTimeout( _this, EwLoadString( 
    &StringsSET20_COMPLETE_BT_PAIRING_FIRST ));
}

/* 'C' function for method : 'Settings::SET03_ConnectionSettingMenu.PresentDialogWithTimeout()' */
void SettingsSET03_ConnectionSettingMenu_PresentDialogWithTimeout( SettingsSET03_ConnectionSettingMenu _this, 
  XString aMessage )
{
  SettingsTimeoutDialog Dialog = EwNewObject( SettingsTimeoutDialog, 0 );

  SettingsTimeoutDialog_OnSetMessage( Dialog, aMessage );
  Dialog->DismissAfterTimeout = 1;
  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)Dialog ), 0, 0, 0, 0, 0, 
  0, EwNullSlot, EwNullSlot, 0 );
}

/* Variants derived from the class : 'Settings::SET03_ConnectionSettingMenu' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET03_ConnectionSettingMenu )
EW_END_OF_CLASS_VARIANTS( SettingsSET03_ConnectionSettingMenu )

/* Virtual Method Table (VMT) for the class : 'Settings::SET03_ConnectionSettingMenu' */
EW_DEFINE_CLASS( SettingsSET03_ConnectionSettingMenu, MenuBaseMenuView, ItemTitleArray, 
                 ItemTitleArray, ItemTitleArray, ItemTitleArray, ItemTitleArray, 
                 _.VMT, "Settings::SET03_ConnectionSettingMenu" )
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
  SettingsSET03_ConnectionSettingMenu_LoadItemClass,
  SettingsSET03_ConnectionSettingMenu_LoadItemTitle,
  SettingsSET03_ConnectionSettingMenu_OnItemActivate,
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
EW_END_OF_CLASS( SettingsSET03_ConnectionSettingMenu )

/* Initializer for the class 'Settings::SET04_BtSettingMenu' */
void SettingsSET04_BtSettingMenu__Init( SettingsSET04_BtSettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET04_BtSettingMenu );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET04_BtSettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 4 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  _this->ItemClassArray[ 0 ] = EW_CLASS( MenuItemCheckbox );
  _this->ItemClassArray[ 1 ] = EW_CLASS( MenuItemBase );
  _this->ItemClassArray[ 2 ] = EW_CLASS( MenuItemBase );
  _this->ItemClassArray[ 3 ] = EW_CLASS( MenuItemCheckbox );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsGEN_BLUETOOTH ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsSET04_DISCOVERY_MODE ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &StringsSET04_PAIRED_DEVICES ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &StringsSET04_BT_AUTO_CONNECT ));

  /* Call the user defined constructor */
  SettingsSET04_BtSettingMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET04_BtSettingMenu' */
void SettingsSET04_BtSettingMenu__ReInit( SettingsSET04_BtSettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Settings::SET04_BtSettingMenu' */
void SettingsSET04_BtSettingMenu__Done( SettingsSET04_BtSettingMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET04_BtSettingMenu_Init( SettingsSET04_BtSettingMenu _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  DeviceInterfaceBluetoothDeviceClass_GetBluetoothEnable( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ));
}

/* 'C' function for method : 'Settings::SET04_BtSettingMenu.LoadItemClass()' */
XClass SettingsSET04_BtSettingMenu_LoadItemClass( SettingsSET04_BtSettingMenu _this, 
  XInt32 aItemNo )
{
  XClass ClassType = 0;

  if ( aItemNo < 4 )
    ClassType = _this->ItemClassArray[ EwCheckIndex( aItemNo, 4 )];

  return ClassType;
}

/* 'C' function for method : 'Settings::SET04_BtSettingMenu.LoadItemTitle()' */
XString SettingsSET04_BtSettingMenu_LoadItemTitle( SettingsSET04_BtSettingMenu _this, 
  XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < 4 )
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 4 )];

  return title;
}

/* 'C' function for method : 'Settings::SET04_BtSettingMenu.OnItemActivate()' */
void SettingsSET04_BtSettingMenu_OnItemActivate( SettingsSET04_BtSettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  XBool IsChecked = 0;
  MenuItemCheckbox CheckBoxItem = EwCastObject( aMenuItem, MenuItemCheckbox );

  if ( CheckBoxItem != 0 )
    IsChecked = CheckBoxItem->Checked;

  switch ( aItemNo )
  {
    case 0 :
    {
      DeviceInterfaceBluetoothDeviceClass_OnSetBluetoothEnable( EwGetAutoObject( 
      &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), IsChecked );
      MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 1, 4 );
    }
    break;

    case 1 :
      if ( DeviceInterfaceBluetoothDeviceClass_OnGetIsMaxPairedDevice( EwGetAutoObject( 
          &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )))
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsSET05_BtcMaxPairedDevice, 
        0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      else
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsSET06_BtcDiscovarable, 
        0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 2 :
      ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)EwNewObject( 
      SettingsSET17_BtcPairedDeviceList, 0 )));
    break;

    case 3 :
      DeviceInterfaceBluetoothDeviceClass_OnSetAutoConnect( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
      DeviceInterfaceBluetoothDeviceClass ), IsChecked );
    break;

    default :; 
  }
}

/* 'C' function for method : 'Settings::SET04_BtSettingMenu.LoadItemChecked()' */
XBool SettingsSET04_BtSettingMenu_LoadItemChecked( SettingsSET04_BtSettingMenu _this, 
  XInt32 aItemNo )
{
  XBool IsChecked;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsChecked = 0;

  switch ( aItemNo )
  {
    case 0 :
      IsChecked = EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->BluetoothEnable;
    break;

    case 3 :
      IsChecked = DeviceInterfaceBluetoothDeviceClass_OnGetAutoConnect( EwGetAutoObject( 
      &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ));
    break;

    default :; 
  }

  return IsChecked;
}

/* 'C' function for method : 'Settings::SET04_BtSettingMenu.LoadItemEnabled()' */
XBool SettingsSET04_BtSettingMenu_LoadItemEnabled( SettingsSET04_BtSettingMenu _this, 
  XInt32 aItemNo )
{
  XBool ItemEnabled;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemEnabled = 1;

  if ( aItemNo > 0 )
    ItemEnabled = EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->BluetoothEnable;

  return ItemEnabled;
}

/* Variants derived from the class : 'Settings::SET04_BtSettingMenu' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET04_BtSettingMenu )
EW_END_OF_CLASS_VARIANTS( SettingsSET04_BtSettingMenu )

/* Virtual Method Table (VMT) for the class : 'Settings::SET04_BtSettingMenu' */
EW_DEFINE_CLASS( SettingsSET04_BtSettingMenu, MenuBaseMenuView, ItemTitleArray, 
                 ItemTitleArray, ItemTitleArray, ItemTitleArray, ItemTitleArray, 
                 ItemClassArray, "Settings::SET04_BtSettingMenu" )
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
  SettingsSET04_BtSettingMenu_LoadItemClass,
  SettingsSET04_BtSettingMenu_LoadItemTitle,
  SettingsSET04_BtSettingMenu_OnItemActivate,
  SettingsSET04_BtSettingMenu_LoadItemChecked,
  SettingsSET04_BtSettingMenu_LoadItemEnabled,
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
EW_END_OF_CLASS( SettingsSET04_BtSettingMenu )

/* Initializer for the class 'Settings::SET35_LegalMenu' */
void SettingsSET35_LegalMenu__Init( SettingsSET35_LegalMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET35_LegalMenu );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET35_LegalMenu );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 1 );
}

/* Re-Initializer for the class 'Settings::SET35_LegalMenu' */
void SettingsSET35_LegalMenu__ReInit( SettingsSET35_LegalMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Settings::SET35_LegalMenu' */
void SettingsSET35_LegalMenu__Done( SettingsSET35_LegalMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* 'C' function for method : 'Settings::SET35_LegalMenu.LoadItemClass()' */
XClass SettingsSET35_LegalMenu_LoadItemClass( SettingsSET35_LegalMenu _this, XInt32 
  aItemNo )
{
  XClass ItemClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemClass = 0;

  if ( aItemNo >= 0 )
    ItemClass = EW_CLASS( MenuItemBase );

  return ItemClass;
}

/* 'C' function for method : 'Settings::SET35_LegalMenu.LoadItemTitle()' */
XString SettingsSET35_LegalMenu_LoadItemTitle( SettingsSET35_LegalMenu _this, XInt32 
  aItemNo )
{
  XString Title;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Title = 0;

  if ( aItemNo >= 0 )
    Title = EwLoadString( &StringsSET35_LICENSE );

  return Title;
}

/* 'C' function for method : 'Settings::SET35_LegalMenu.OnItemActivate()' */
void SettingsSET35_LegalMenu_OnItemActivate( SettingsSET35_LegalMenu _this, XInt32 
  aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );
  EW_UNUSED_ARG( aItemNo );

  ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)EwNewObject( 
  SettingsSET37_3rdPartyLicenses, 0 )));
}

/* Variants derived from the class : 'Settings::SET35_LegalMenu' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET35_LegalMenu )
EW_END_OF_CLASS_VARIANTS( SettingsSET35_LegalMenu )

/* Virtual Method Table (VMT) for the class : 'Settings::SET35_LegalMenu' */
EW_DEFINE_CLASS( SettingsSET35_LegalMenu, MenuBaseMenuView, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, _.VMT, "Settings::SET35_LegalMenu" )
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
  SettingsSET35_LegalMenu_LoadItemClass,
  SettingsSET35_LegalMenu_LoadItemTitle,
  SettingsSET35_LegalMenu_OnItemActivate,
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
EW_END_OF_CLASS( SettingsSET35_LegalMenu )

/* Initializer for the class 'Settings::SET38_ConfirmAllReset' */
void SettingsSET38_ConfirmAllReset__Init( SettingsSET38_ConfirmAllReset _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET38_ConfirmAllReset );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Text, &_this->_.XObject, 0 );
  MenuUpDownPushButtonSet__Init( &_this->UpDownPushButtonSet, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET38_ConfirmAllReset );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0001 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0002 );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &StringsSET38_RESET_TO_FACTORY ));
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const0003 );
  _this->UpDownPushButtonSet.Super1.PassHomeKey = 1;
  _this->UpDownPushButtonSet.Super1.PassMagicKey = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->UpDownPushButtonSet, 1 );
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwGetVariantOfString( 
  &StringsGEN_CANCEL ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwGetVariantOfString( 
  &StringsGEN_OK ));
  MenuUpDownPushButtonSet_OnSetDownButtonEnabled( &_this->UpDownPushButtonSet, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UpDownPushButtonSet ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->UpDownPushButtonSet.OnUpButtonActivated = EwNewSlot( _this, SettingsSET38_ConfirmAllReset_OnCancelActivatedSlot );
  _this->UpDownPushButtonSet.OnDownButtonActivated = EwNewSlot( _this, SettingsSET38_ConfirmAllReset_OnOkActivatedSlot );
}

/* Re-Initializer for the class 'Settings::SET38_ConfirmAllReset' */
void SettingsSET38_ConfirmAllReset__ReInit( SettingsSET38_ConfirmAllReset _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Text );
  MenuUpDownPushButtonSet__ReInit( &_this->UpDownPushButtonSet );
}

/* Finalizer method for the class 'Settings::SET38_ConfirmAllReset' */
void SettingsSET38_ConfirmAllReset__Done( SettingsSET38_ConfirmAllReset _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Text );
  MenuUpDownPushButtonSet__Done( &_this->UpDownPushButtonSet );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* 'C' function for method : 'Settings::SET38_ConfirmAllReset.OnOkActivatedSlot()' */
void SettingsSET38_ConfirmAllReset_OnOkActivatedSlot( SettingsSET38_ConfirmAllReset _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( 0 < DeviceInterfaceBluetoothDeviceClass_OnGetPairedDeviceNum( EwGetAutoObject( 
      &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )))
    CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)EwNewObject( SettingsSET39_DeletePairedDevice, 
    0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  else
    CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)EwNewObject( SettingsSET41_ResetInProgress, 
    0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Settings::SET38_ConfirmAllReset.OnCancelActivatedSlot()' */
void SettingsSET38_ConfirmAllReset_OnCancelActivatedSlot( SettingsSET38_ConfirmAllReset _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
}

/* Variants derived from the class : 'Settings::SET38_ConfirmAllReset' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET38_ConfirmAllReset )
EW_END_OF_CLASS_VARIANTS( SettingsSET38_ConfirmAllReset )

/* Virtual Method Table (VMT) for the class : 'Settings::SET38_ConfirmAllReset' */
EW_DEFINE_CLASS( SettingsSET38_ConfirmAllReset, ComponentsBaseMainBG, Text, Text, 
                 Text, Text, _.VMT, _.VMT, "Settings::SET38_ConfirmAllReset" )
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
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SettingsSET38_ConfirmAllReset )

/* Initializer for the class 'Settings::SET39_DeletePairedDevice' */
void SettingsSET39_DeletePairedDevice__Init( SettingsSET39_DeletePairedDevice _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET39_DeletePairedDevice );

  /* ... then construct all embedded objects */
  MenuPushButton__Init( &_this->PushButton, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Text, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET39_DeletePairedDevice );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->PushButton, _Const0004 );
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->PushButton, 1 );
  MenuPushButton_OnSetTitle( &_this->PushButton, EwGetVariantOfString( &StringsGEN_OK ));
  CoreRectView__OnSetBounds( &_this->Text, _Const0005 );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &StringsSET39_DELETE_PAIRING ));
  CoreGroup__Add( _this, ((CoreView)&_this->PushButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  _this->PushButton.OnActivate = EwNewSlot( _this, SettingsSET39_DeletePairedDevice_OnOkSelectedSlot );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));

  /* Call the user defined constructor */
  SettingsSET39_DeletePairedDevice_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET39_DeletePairedDevice' */
void SettingsSET39_DeletePairedDevice__ReInit( SettingsSET39_DeletePairedDevice _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  MenuPushButton__ReInit( &_this->PushButton );
  ViewsText__ReInit( &_this->Text );
}

/* Finalizer method for the class 'Settings::SET39_DeletePairedDevice' */
void SettingsSET39_DeletePairedDevice__Done( SettingsSET39_DeletePairedDevice _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  MenuPushButton__Done( &_this->PushButton );
  ViewsText__Done( &_this->Text );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET39_DeletePairedDevice_Init( SettingsSET39_DeletePairedDevice _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0006 ));
}

/* 'C' function for method : 'Settings::SET39_DeletePairedDevice.OnOkSelectedSlot()' */
void SettingsSET39_DeletePairedDevice_OnOkSelectedSlot( SettingsSET39_DeletePairedDevice _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)EwNewObject( SettingsSET41_ResetInProgress, 
  0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* Variants derived from the class : 'Settings::SET39_DeletePairedDevice' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET39_DeletePairedDevice )
EW_END_OF_CLASS_VARIANTS( SettingsSET39_DeletePairedDevice )

/* Virtual Method Table (VMT) for the class : 'Settings::SET39_DeletePairedDevice' */
EW_DEFINE_CLASS( SettingsSET39_DeletePairedDevice, ComponentsBaseMainBG, PushButton, 
                 PushButton, PushButton, PushButton, _.VMT, _.VMT, "Settings::SET39_DeletePairedDevice" )
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
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SettingsSET39_DeletePairedDevice )

/* Initializer for the class 'Settings::SET41_ResetInProgress' */
void SettingsSET41_ResetInProgress__Init( SettingsSET41_ResetInProgress _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET41_ResetInProgress );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->LoadingAnimation, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->LoadingText, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ReceivedSystemEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET41_ResetInProgress );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->LoadingAnimation, _Const0007 );
  ViewsImage_OnSetAnimated( &_this->LoadingAnimation, 1 );
  CoreRectView__OnSetBounds( &_this->LoadingText, _Const0008 );
  ViewsText_OnSetString( &_this->LoadingText, EwLoadString( &StringsGEN_PLEASE_WAIT ));
  CoreGroup__Add( _this, ((CoreView)&_this->LoadingAnimation ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LoadingText ), 0 );
  ViewsImage_OnSetBitmap( &_this->LoadingAnimation, EwLoadResource( &ResourceLoadingAnimation, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->LoadingText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->ReceivedSystemEventHandler.OnEvent = EwNewSlot( _this, SettingsSET41_ResetInProgress_OnSystemEventReceived );
  CoreSystemEventHandler_OnSetEvent( &_this->ReceivedSystemEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->SystemDataReceivedSystemEvent );

  /* Call the user defined constructor */
  SettingsSET41_ResetInProgress_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET41_ResetInProgress' */
void SettingsSET41_ResetInProgress__ReInit( SettingsSET41_ResetInProgress _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->LoadingAnimation );
  ViewsText__ReInit( &_this->LoadingText );
  CoreSystemEventHandler__ReInit( &_this->ReceivedSystemEventHandler );
}

/* Finalizer method for the class 'Settings::SET41_ResetInProgress' */
void SettingsSET41_ResetInProgress__Done( SettingsSET41_ResetInProgress _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->LoadingAnimation );
  ViewsText__Done( &_this->LoadingText );
  CoreSystemEventHandler__Done( &_this->ReceivedSystemEventHandler );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET41_ResetInProgress_Init( SettingsSET41_ResetInProgress _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0009 ));

  if ( DeviceInterfaceVehicleDeviceClass_OnGetDDModeActivated( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
  {
    SettingsTimeoutDialog Dialog = EwNewObject( SettingsTimeoutDialog, 0 );
    SettingsTimeoutDialog_OnSetMessage( Dialog, EwLoadString( &StringsSET40_CANNOT_EXECUTE ));
    Dialog->DismissAfterTimeout = 1;
    CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)Dialog ), 0, 0, 0, 
    0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
  else
    DeviceInterfaceSystemDeviceClass_ResetToFactoryDefault( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
    DeviceInterfaceSystemDeviceClass ));
}

/* 'C' function for method : 'Settings::SET41_ResetInProgress.OnShortHomeKeyActivated()' */
void SettingsSET41_ResetInProgress_OnShortHomeKeyActivated( SettingsSET41_ResetInProgress _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* 'C' function for method : 'Settings::SET41_ResetInProgress.OnLongHomeKeyActivated()' */
void SettingsSET41_ResetInProgress_OnLongHomeKeyActivated( SettingsSET41_ResetInProgress _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SettingsSET41_ResetInProgress_OnSystemEventReceived( SettingsSET41_ResetInProgress _this, 
  XObject sender )
{
  DeviceInterfaceSystemData SystemData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  SystemData = EwCastObject( _this->ReceivedSystemEventHandler.Context, DeviceInterfaceSystemData );

  if ( SystemData != 0 )
    switch ( SystemData->RxEvent )
    {
      case EnumSystemRxEventFACTORY_RESET_COMPLETED :
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsSET42_ResetCompleted, 
        0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      break;

      default :; 
    }
}

/* Variants derived from the class : 'Settings::SET41_ResetInProgress' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET41_ResetInProgress )
EW_END_OF_CLASS_VARIANTS( SettingsSET41_ResetInProgress )

/* Virtual Method Table (VMT) for the class : 'Settings::SET41_ResetInProgress' */
EW_DEFINE_CLASS( SettingsSET41_ResetInProgress, ComponentsBaseMainBG, LoadingAnimation, 
                 LoadingAnimation, LoadingAnimation, LoadingAnimation, _.VMT, _.VMT, 
                 "Settings::SET41_ResetInProgress" )
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
  SettingsSET41_ResetInProgress_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  SettingsSET41_ResetInProgress_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SettingsSET41_ResetInProgress )

/* Initializer for the class 'Settings::SET37_3rdPartyLicenses' */
void SettingsSET37_3rdPartyLicenses__Init( SettingsSET37_3rdPartyLicenses _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET37_3rdPartyLicenses );

  /* ... then construct all embedded objects */
  MenuScrollbar__Init( &_this->Scrollbar, &_this->_.XObject, 0 );
  SettingsLicenseDetail__Init( &_this->ThirdPartyLicenseText, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET37_3rdPartyLicenses );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super1.SlideOutEffectEnabled = 1;
  CoreRectView__OnSetBounds( &_this->Scrollbar, _Const000A );
  MenuScrollbar_OnSetViewIdx( &_this->Scrollbar, 0 );
  MenuScrollbar_OnSetPageItems( &_this->Scrollbar, 7 );
  MenuScrollbar_OnSetListItems( &_this->Scrollbar, 1 );
  CoreRectView__OnSetBounds( &_this->ThirdPartyLicenseText, _Const000B );
  CoreGroup__Add( _this, ((CoreView)&_this->Scrollbar ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ThirdPartyLicenseText ), 0 );
  _this->ThirdPartyLicenseText.OnLineNumUpdated = EwNewSlot( _this, SettingsSET37_3rdPartyLicenses_OnLineNumUpdatedSlot );

  /* Call the user defined constructor */
  SettingsSET37_3rdPartyLicenses_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET37_3rdPartyLicenses' */
void SettingsSET37_3rdPartyLicenses__ReInit( SettingsSET37_3rdPartyLicenses _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  MenuScrollbar__ReInit( &_this->Scrollbar );
  SettingsLicenseDetail__ReInit( &_this->ThirdPartyLicenseText );
}

/* Finalizer method for the class 'Settings::SET37_3rdPartyLicenses' */
void SettingsSET37_3rdPartyLicenses__Done( SettingsSET37_3rdPartyLicenses _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  MenuScrollbar__Done( &_this->Scrollbar );
  SettingsLicenseDetail__Done( &_this->ThirdPartyLicenseText );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET37_3rdPartyLicenses_Init( SettingsSET37_3rdPartyLicenses _this, 
  XHandle aArg )
{
  XInt32 i;
  XString CopyRightTitle;
  XString CopyRightContent;
  XInt32 NumberOfLicenses;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  CopyRightTitle = 0;
  CopyRightContent = 0;
  NumberOfLicenses = 0;
  NumberOfLicenses = ew_get_num_of_licenses();

  for ( i = 0; i < NumberOfLicenses; i++ )
  {
    {
      uint8_t* copyright_title;
      uint8_t* copyright_content;
      ew_get_copyright( i, &copyright_title, &copyright_content );
      CopyRightTitle = EwNewStringUtf8( ( const unsigned char* )copyright_title, ( int )strlen( ( char* )copyright_title ) );
      CopyRightContent = EwNewStringUtf8( ( const unsigned char* )copyright_content, ( int )strlen( ( char* )copyright_content ) );
    }
    ViewsText_OnSetString( &_this->ThirdPartyLicenseText.LicenseText, EwConcatString( 
    _this->ThirdPartyLicenseText.LicenseText.String, EwConcatString( EwConcatString( 
    EwConcatString( CopyRightTitle, EwLoadString( &_Const000C )), CopyRightContent ), 
    EwLoadString( &_Const000C ))));
    ViewsText_OnSetString( &_this->ThirdPartyLicenseText.LicenseText, EwConcatString( 
    _this->ThirdPartyLicenseText.LicenseText.String, EwLoadString( &_Const000C )));
  }

  SettingsLicenseDetail_UpdateLineNum( &_this->ThirdPartyLicenseText );
  _this->ThirdPartyLicenseText.LicenseInitBounds = _this->ThirdPartyLicenseText.LicenseText.Super1.Bounds;
}

/* 'C' function for method : 'Settings::SET37_3rdPartyLicenses.OnShortDownKeyActivated()' */
void SettingsSET37_3rdPartyLicenses_OnShortDownKeyActivated( SettingsSET37_3rdPartyLicenses _this )
{
  MenuScrollbar_OnSetViewIdx( &_this->Scrollbar, SettingsLicenseDetail_ScrollDownPage( 
  &_this->ThirdPartyLicenseText ));
}

/* 'C' function for method : 'Settings::SET37_3rdPartyLicenses.OnShortUpKeyActivated()' */
void SettingsSET37_3rdPartyLicenses_OnShortUpKeyActivated( SettingsSET37_3rdPartyLicenses _this )
{
  MenuScrollbar_OnSetViewIdx( &_this->Scrollbar, SettingsLicenseDetail_ScrollUpPage( 
  &_this->ThirdPartyLicenseText ));
}

/* 'C' function for method : 'Settings::SET37_3rdPartyLicenses.OnShortEnterKeyActivated()' */
void SettingsSET37_3rdPartyLicenses_OnShortEnterKeyActivated( SettingsSET37_3rdPartyLicenses _this )
{
  ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
}

/* 'C' function for method : 'Settings::SET37_3rdPartyLicenses.OnLineNumUpdatedSlot()' */
void SettingsSET37_3rdPartyLicenses_OnLineNumUpdatedSlot( SettingsSET37_3rdPartyLicenses _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  MenuScrollbar_OnSetListItems( &_this->Scrollbar, _this->ThirdPartyLicenseText.NoOfLines );
}

/* Variants derived from the class : 'Settings::SET37_3rdPartyLicenses' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET37_3rdPartyLicenses )
EW_END_OF_CLASS_VARIANTS( SettingsSET37_3rdPartyLicenses )

/* Virtual Method Table (VMT) for the class : 'Settings::SET37_3rdPartyLicenses' */
EW_DEFINE_CLASS( SettingsSET37_3rdPartyLicenses, ComponentsBaseMainBG, Scrollbar, 
                 Scrollbar, Scrollbar, Scrollbar, _.VMT, _.VMT, "Settings::SET37_3rdPartyLicenses" )
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
  SettingsSET37_3rdPartyLicenses_OnShortDownKeyActivated,
  SettingsSET37_3rdPartyLicenses_OnShortUpKeyActivated,
  SettingsSET37_3rdPartyLicenses_OnShortEnterKeyActivated,
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SettingsSET37_3rdPartyLicenses )

/* Initializer for the class 'Settings::SET06_BtcDiscovarable' */
void SettingsSET06_BtcDiscovarable__Init( SettingsSET06_BtcDiscovarable _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET06_BtcDiscovarable );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->DiscoverableText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->TimeLeftText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->NameText, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->CountDownTimer, &_this->_.XObject, 0 );
  MenuPushButton__Init( &_this->PushButton, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->BtcPairingStateChangeEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET06_BtcDiscovarable );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->DiscoverableText, _Const000D );
  ViewsText_OnSetWrapText( &_this->DiscoverableText, 1 );
  ViewsText_OnSetAlignment( &_this->DiscoverableText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->DiscoverableText, EwLoadString( &StringsSET06_DISCOVERABLE ));
  CoreRectView__OnSetBounds( &_this->TimeLeftText, _Const000E );
  ViewsText_OnSetWrapText( &_this->TimeLeftText, 1 );
  ViewsText_OnSetAlignment( &_this->TimeLeftText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TimeLeftText, EwConcatString( EwLoadString( &StringsSET06_TIME_LEFT ), 
  EwLoadString( &_Const000F )));
  CoreRectView__OnSetBounds( &_this->NameText, _Const0010 );
  ViewsText_OnSetEllipsis( &_this->NameText, 1 );
  ViewsText_OnSetWrapText( &_this->NameText, 1 );
  ViewsText_OnSetAlignment( &_this->NameText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->NameText, EwLoadString( &StringsSET06_NAME ));
  CoreTimer_OnSetPeriod( &_this->CountDownTimer, 1000 );
  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 0 );
  _this->CountDownTimeSec = 180;
  CoreRectView__OnSetBounds( &_this->PushButton, _Const0004 );
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->PushButton, 1 );
  MenuPushButton_OnSetTitle( &_this->PushButton, EwGetVariantOfString( &StringsGEN_CANCEL ));
  CoreGroup__Add( _this, ((CoreView)&_this->DiscoverableText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeLeftText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NameText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PushButton ), 0 );
  ViewsText_OnSetFont( &_this->DiscoverableText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->TimeLeftText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->NameText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->CountDownTimer.OnTrigger = EwNewSlot( _this, SettingsSET06_BtcDiscovarable_UpdateCountDownTimeSlot );
  _this->PushButton.OnActivate = EwNewSlot( _this, SettingsSET06_BtcDiscovarable_OnCancelSlot );
  _this->BtcPairingStateChangeEventHandler.OnEvent = EwNewSlot( _this, SettingsSET06_BtcDiscovarable_OnBtcPairingStateChangeSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->BtcPairingStateChangeEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->BtcPairingChangedSystemEvent );

  /* Call the user defined constructor */
  SettingsSET06_BtcDiscovarable_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET06_BtcDiscovarable' */
void SettingsSET06_BtcDiscovarable__ReInit( SettingsSET06_BtcDiscovarable _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->DiscoverableText );
  ViewsText__ReInit( &_this->TimeLeftText );
  ViewsText__ReInit( &_this->NameText );
  CoreTimer__ReInit( &_this->CountDownTimer );
  MenuPushButton__ReInit( &_this->PushButton );
  CoreSystemEventHandler__ReInit( &_this->BtcPairingStateChangeEventHandler );
}

/* Finalizer method for the class 'Settings::SET06_BtcDiscovarable' */
void SettingsSET06_BtcDiscovarable__Done( SettingsSET06_BtcDiscovarable _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->DiscoverableText );
  ViewsText__Done( &_this->TimeLeftText );
  ViewsText__Done( &_this->NameText );
  CoreTimer__Done( &_this->CountDownTimer );
  MenuPushButton__Done( &_this->PushButton );
  CoreSystemEventHandler__Done( &_this->BtcPairingStateChangeEventHandler );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET06_BtcDiscovarable_Init( SettingsSET06_BtcDiscovarable _this, XHandle 
  aArg )
{
  XString ProcessString;
  XInt32 LeftIdx;
  XInt32 RightIdx;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0011 ));
  DeviceInterfaceBluetoothDeviceClass_OnSetDiscoverable( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ), 1 );
  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 1 );
  ProcessString = EwLoadString( &StringsSET06_NAME );
  LeftIdx = EwStringFind( ProcessString, EwLoadString( &StringsARGUMENT_STR ), 0 );
  RightIdx = ( EwGetStringLength( ProcessString ) - LeftIdx ) - EwGetStringLength( 
  EwLoadString( &StringsARGUMENT_STR ));
  ViewsText_OnSetString( &_this->NameText, EwConcatString( EwConcatString( EwStringLeft( 
  ProcessString, LeftIdx ), DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceName( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ))), 
  EwStringRight( ProcessString, RightIdx )));
}

/* 'C' function for method : 'Settings::SET06_BtcDiscovarable.OnShortHomeKeyActivated()' */
void SettingsSET06_BtcDiscovarable_OnShortHomeKeyActivated( SettingsSET06_BtcDiscovarable _this )
{
  DeviceInterfaceBluetoothDeviceClass_OnSetDiscoverable( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ), 0 );
  ComponentsBaseMainBG_OnShortHomeKeyActivated((ComponentsBaseMainBG)_this );
}

/* 'C' function for method : 'Settings::SET06_BtcDiscovarable.OnLongHomeKeyActivated()' */
void SettingsSET06_BtcDiscovarable_OnLongHomeKeyActivated( SettingsSET06_BtcDiscovarable _this )
{
  DeviceInterfaceBluetoothDeviceClass_OnSetDiscoverable( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ), 0 );
  ComponentsBaseComponent_OnLongHomeKeyActivated((ComponentsBaseComponent)_this );
}

/* 'C' function for method : 'Settings::SET06_BtcDiscovarable.OnCancelSlot()' */
void SettingsSET06_BtcDiscovarable_OnCancelSlot( SettingsSET06_BtcDiscovarable _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 0 );
  DeviceInterfaceBluetoothDeviceClass_OnSetDiscoverable( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ), 0 );
  CoreGroup_DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Settings::SET06_BtcDiscovarable.UpdateCountDownTimeSlot()' */
void SettingsSET06_BtcDiscovarable_UpdateCountDownTimeSlot( SettingsSET06_BtcDiscovarable _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->CountDownTimeSec > 0 )
  {
    XInt32 Second;
    XString SecondStr;
    _this->CountDownTimeSec = _this->CountDownTimeSec - 1;
    Second = _this->CountDownTimeSec % 60;

    if ( Second < 10 )
      SecondStr = EwConcatString( EwLoadString( &_Const0012 ), EwNewStringInt( Second, 
      0, 10 ));
    else
      SecondStr = EwNewStringInt( Second, 0, 10 );

    ViewsText_OnSetString( &_this->TimeLeftText, EwConcatString( EwConcatString( 
    EwConcatString( EwLoadString( &StringsSET06_TIME_LEFT ), EwNewStringInt( _this->CountDownTimeSec 
    / 60, 0, 10 )), EwLoadString( &_Const0013 )), SecondStr ));
  }
  else
  {
    SettingsTimeoutDialog PairingFailDialog = EwNewObject( SettingsTimeoutDialog, 
      0 );
    SettingsTimeoutDialog_OnSetMessage( PairingFailDialog, EwLoadString( &StringsSET07_PAIRING_FAILED ));
    PairingFailDialog->DismissAfterTimeout = 1;
    CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)PairingFailDialog ), 
    0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SettingsSET06_BtcDiscovarable_OnBtcPairingStateChangeSlot( SettingsSET06_BtcDiscovarable _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Super5.Owner != 0 )
    switch ( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->BtcPairingState )
    {
      case EnumBtcPairingStateFAIL :
      {
        SettingsTimeoutDialog PairingFailDialog = EwNewObject( SettingsTimeoutDialog, 
          0 );
        SettingsTimeoutDialog_OnSetMessage( PairingFailDialog, EwLoadString( &StringsSET07_PAIRING_FAILED ));
        PairingFailDialog->DismissAfterTimeout = 1;
        DeviceInterfaceBluetoothDeviceClass_OnSetDiscoverable( EwGetAutoObject( 
        &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 
        0 );
        CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)PairingFailDialog ), 
        0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
      break;

      case EnumBtcPairingStatePASSKEY_GENERATED :
      {
        DeviceInterfaceBluetoothDeviceClass_OnSetDiscoverable( EwGetAutoObject( 
        &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 
        0 );
        CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)EwNewObject( 
        SettingsSET08_BtcPairDevice, 0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 
        0 );
      }
      break;

      default :; 
    }
}

/* Variants derived from the class : 'Settings::SET06_BtcDiscovarable' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET06_BtcDiscovarable )
EW_END_OF_CLASS_VARIANTS( SettingsSET06_BtcDiscovarable )

/* Virtual Method Table (VMT) for the class : 'Settings::SET06_BtcDiscovarable' */
EW_DEFINE_CLASS( SettingsSET06_BtcDiscovarable, ComponentsBaseMainBG, DiscoverableText, 
                 DiscoverableText, DiscoverableText, DiscoverableText, CountDownTimeSec, 
                 CountDownTimeSec, "Settings::SET06_BtcDiscovarable" )
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
  SettingsSET06_BtcDiscovarable_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  SettingsSET06_BtcDiscovarable_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SettingsSET06_BtcDiscovarable )

/* Initializer for the class 'Settings::SET9_10_11_BtConnectionResult' */
void SettingsSET9_10_11_BtConnectionResult__Init( SettingsSET9_10_11_BtConnectionResult _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET9_10_11_BtConnectionResult );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Message, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ConnectPairedDeviceResultHandler, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->DismissTimer, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Divider, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->LoadingAnimation, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->LoadingText, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET9_10_11_BtConnectionResult );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->Message, _Const0014 );
  ViewsText_OnSetEllipsis( &_this->Message, 1 );
  ViewsText_OnSetWrapText( &_this->Message, 1 );
  ViewsText_OnSetAlignment( &_this->Message, ViewsTextAlignmentAlignHorzCenter | 
  ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Message, 0 );
  CoreTimer_OnSetPeriod( &_this->DismissTimer, 0 );
  CoreTimer_OnSetBegin( &_this->DismissTimer, 2000 );
  CoreRectView__OnSetBounds( &_this->Divider, _Const0015 );
  ViewsImage_OnSetAlignment( &_this->Divider, ViewsImageAlignmentAlignVertBottom 
  | ViewsImageAlignmentScaleToFit );
  CoreRectView__OnSetBounds( &_this->LoadingAnimation, _Const0007 );
  ViewsImage_OnSetAnimated( &_this->LoadingAnimation, 1 );
  CoreRectView__OnSetBounds( &_this->LoadingText, _Const0008 );
  ViewsText_OnSetString( &_this->LoadingText, EwLoadString( &StringsGEN_PLEASE_WAIT ));
  CoreGroup__Add( _this, ((CoreView)&_this->Message ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->LoadingAnimation ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LoadingText ), 0 );
  ViewsText_OnSetFont( &_this->Message, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->ConnectPairedDeviceResultHandler.OnEvent = EwNewSlot( _this, SettingsSET9_10_11_BtConnectionResult_OnConnectPairedDeviceResultSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->ConnectPairedDeviceResultHandler, &EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->BtcConnectionResultSystemEvent );
  _this->DismissTimer.OnTrigger = EwNewSlot( _this, SettingsSET9_10_11_BtConnectionResult_OnDismissSlot );
  ViewsImage_OnSetBitmap( &_this->Divider, EwLoadResource( &ResourceStatusBarDivider, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->LoadingAnimation, EwLoadResource( &ResourceLoadingAnimation, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->LoadingText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Settings::SET9_10_11_BtConnectionResult' */
void SettingsSET9_10_11_BtConnectionResult__ReInit( SettingsSET9_10_11_BtConnectionResult _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Message );
  CoreSystemEventHandler__ReInit( &_this->ConnectPairedDeviceResultHandler );
  CoreTimer__ReInit( &_this->DismissTimer );
  ViewsImage__ReInit( &_this->Divider );
  ViewsImage__ReInit( &_this->LoadingAnimation );
  ViewsText__ReInit( &_this->LoadingText );
}

/* Finalizer method for the class 'Settings::SET9_10_11_BtConnectionResult' */
void SettingsSET9_10_11_BtConnectionResult__Done( SettingsSET9_10_11_BtConnectionResult _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Message );
  CoreSystemEventHandler__Done( &_this->ConnectPairedDeviceResultHandler );
  CoreTimer__Done( &_this->DismissTimer );
  ViewsImage__Done( &_this->Divider );
  ViewsImage__Done( &_this->LoadingAnimation );
  ViewsText__Done( &_this->LoadingText );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SettingsSET9_10_11_BtConnectionResult_OnConnectPairedDeviceResultSlot( SettingsSET9_10_11_BtConnectionResult _this, 
  XObject sender )
{
  XEnum ConnectionResult;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ConnectionResult = EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->ConnectPairedDeviceResult;

  switch ( ConnectionResult )
  {
    case EnumBtDeviceConnectionResultSUCCESS :
    {
      XString ProcessString = EwLoadString( &StringsSET09_BT_CONNECTED );
      XInt32 LeftIdx = EwStringFind( ProcessString, EwLoadString( &StringsARGUMENT_STR ), 
        0 );
      XInt32 RightIdx = ( EwGetStringLength( ProcessString ) - LeftIdx ) - EwGetStringLength( 
        EwLoadString( &StringsARGUMENT_STR ));
      SettingsSET9_10_11_BtConnectionResult_HideLoadingUI( _this );
      ViewsText_OnSetString( &_this->Message, EwConcatString( EwConcatString( EwStringLeft( 
      ProcessString, LeftIdx ), _this->DeviceName ), EwStringRight( ProcessString, 
      RightIdx )));
    }
    break;

    case EnumBtDeviceConnectionResultFAIL :
    {
      XString ProcessString = EwLoadString( &StringsSET10_CONNECTION_FAILED );
      XInt32 LeftIdx = EwStringFind( ProcessString, EwLoadString( &StringsARGUMENT_STR ), 
        0 );
      XInt32 RightIdx = ( EwGetStringLength( ProcessString ) - LeftIdx ) - EwGetStringLength( 
        EwLoadString( &StringsARGUMENT_STR ));
      SettingsSET9_10_11_BtConnectionResult_HideLoadingUI( _this );
      ViewsText_OnSetString( &_this->Message, EwConcatString( EwConcatString( EwStringLeft( 
      ProcessString, LeftIdx ), _this->DeviceName ), EwStringRight( ProcessString, 
      RightIdx )));
    }
    break;

    case EnumBtDeviceConnectionResultAUTHENTICATION_ERR :
    {
      XString ProcessString = EwLoadString( &StringsSET11_NO_LONGER_PAIRED );
      XInt32 LeftIdx = EwStringFind( ProcessString, EwLoadString( &StringsARGUMENT_STR ), 
        0 );
      XInt32 RightIdx = ( EwGetStringLength( ProcessString ) - LeftIdx ) - EwGetStringLength( 
        EwLoadString( &StringsARGUMENT_STR ));
      SettingsSET9_10_11_BtConnectionResult_HideLoadingUI( _this );
      ViewsText_OnSetString( &_this->Message, EwConcatString( EwConcatString( EwStringLeft( 
      ProcessString, LeftIdx ), _this->DeviceName ), EwStringRight( ProcessString, 
      RightIdx )));
    }
    break;

    default : 
      ViewsText_OnSetString( &_this->Message, 0 );
  }

  CoreTimer_OnSetEnabled( &_this->DismissTimer, 1 );
}

/* 'C' function for method : 'Settings::SET9_10_11_BtConnectionResult.OnDismissSlot()' */
void SettingsSET9_10_11_BtConnectionResult_OnDismissSlot( SettingsSET9_10_11_BtConnectionResult _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
  DeviceInterfaceBluetoothDeviceClass_OnSetRefreshPairedDeviceList( EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 1 );
}

/* 'C' function for method : 'Settings::SET9_10_11_BtConnectionResult.HideLoadingUI()' */
void SettingsSET9_10_11_BtConnectionResult_HideLoadingUI( SettingsSET9_10_11_BtConnectionResult _this )
{
  ViewsText_OnSetVisible( &_this->LoadingText, 0 );
  ViewsImage_OnSetVisible( &_this->LoadingAnimation, 0 );
}

/* Variants derived from the class : 'Settings::SET9_10_11_BtConnectionResult' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET9_10_11_BtConnectionResult )
EW_END_OF_CLASS_VARIANTS( SettingsSET9_10_11_BtConnectionResult )

/* Virtual Method Table (VMT) for the class : 'Settings::SET9_10_11_BtConnectionResult' */
EW_DEFINE_CLASS( SettingsSET9_10_11_BtConnectionResult, ComponentsBaseMainBG, Message, 
                 Message, Message, Message, DeviceName, _.VMT, "Settings::SET9_10_11_BtConnectionResult" )
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
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SettingsSET9_10_11_BtConnectionResult )

/* Initializer for the class 'Settings::SET05_BtcMaxPairedDevice' */
void SettingsSET05_BtcMaxPairedDevice__Init( SettingsSET05_BtcMaxPairedDevice _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET05_BtcMaxPairedDevice );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Text, &_this->_.XObject, 0 );
  MenuUpDownPushButtonSet__Init( &_this->UpDownPushButtonSet, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET05_BtcMaxPairedDevice );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0016 );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &StringsSET05_MAX_DEVICES ));
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const0003 );
  _this->UpDownPushButtonSet.Super1.PassHomeKey = 1;
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &_Const0017 ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &_Const0018 ));
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UpDownPushButtonSet ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->UpDownPushButtonSet.OnUpButtonActivated = EwNewSlot( _this, SettingsSET05_BtcMaxPairedDevice_OnYesActivatedSlot );
  _this->UpDownPushButtonSet.OnDownButtonActivated = EwNewSlot( _this, SettingsSET05_BtcMaxPairedDevice_OnNoActivatedSlot );

  /* Call the user defined constructor */
  SettingsSET05_BtcMaxPairedDevice_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET05_BtcMaxPairedDevice' */
void SettingsSET05_BtcMaxPairedDevice__ReInit( SettingsSET05_BtcMaxPairedDevice _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Text );
  MenuUpDownPushButtonSet__ReInit( &_this->UpDownPushButtonSet );
}

/* Finalizer method for the class 'Settings::SET05_BtcMaxPairedDevice' */
void SettingsSET05_BtcMaxPairedDevice__Done( SettingsSET05_BtcMaxPairedDevice _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Text );
  MenuUpDownPushButtonSet__Done( &_this->UpDownPushButtonSet );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET05_BtcMaxPairedDevice_Init( SettingsSET05_BtcMaxPairedDevice _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0019 ));
}

/* 'C' function for method : 'Settings::SET05_BtcMaxPairedDevice.OnYesActivatedSlot()' */
void SettingsSET05_BtcMaxPairedDevice_OnYesActivatedSlot( SettingsSET05_BtcMaxPairedDevice _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Super5.Owner != 0 )
    CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)EwNewObject( SettingsSET17_BtcPairedDeviceList, 
    0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Settings::SET05_BtcMaxPairedDevice.OnNoActivatedSlot()' */
void SettingsSET05_BtcMaxPairedDevice_OnNoActivatedSlot( SettingsSET05_BtcMaxPairedDevice _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Super5.Owner != 0 )
    CoreGroup_DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 0 );
}

/* Variants derived from the class : 'Settings::SET05_BtcMaxPairedDevice' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET05_BtcMaxPairedDevice )
EW_END_OF_CLASS_VARIANTS( SettingsSET05_BtcMaxPairedDevice )

/* Virtual Method Table (VMT) for the class : 'Settings::SET05_BtcMaxPairedDevice' */
EW_DEFINE_CLASS( SettingsSET05_BtcMaxPairedDevice, ComponentsBaseMainBG, Text, Text, 
                 Text, Text, _.VMT, _.VMT, "Settings::SET05_BtcMaxPairedDevice" )
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
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SettingsSET05_BtcMaxPairedDevice )

/* Initializer for the class 'Settings::SET08_BtcPairDevice' */
void SettingsSET08_BtcPairDevice__Init( SettingsSET08_BtcPairDevice _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET08_BtcPairDevice );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->PairText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->PasskeyText, &_this->_.XObject, 0 );
  MenuUpDownPushButtonSet__Init( &_this->UpDownPushButtonSet, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->BtcPairingStateChangeEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET08_BtcPairDevice );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->PairText, _Const001A );
  ViewsText_OnSetWrapText( &_this->PairText, 1 );
  ViewsText_OnSetAlignment( &_this->PairText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->PairText, EwLoadString( &StringsSET08_PAIR_WITH ));
  CoreRectView__OnSetBounds( &_this->PasskeyText, _Const001B );
  ViewsText_OnSetWrapText( &_this->PasskeyText, 1 );
  ViewsText_OnSetAlignment( &_this->PasskeyText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->PasskeyText, EwLoadString( &StringsSET08_PASSKEY ));
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const0003 );
  _this->UpDownPushButtonSet.Super1.PassHomeKey = 1;
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &StringsGEN_YES ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &StringsGEN_NO ));
  CoreGroup__Add( _this, ((CoreView)&_this->PairText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PasskeyText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UpDownPushButtonSet ), 0 );
  ViewsText_OnSetFont( &_this->PairText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->PasskeyText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->UpDownPushButtonSet.OnUpButtonActivated = EwNewSlot( _this, SettingsSET08_BtcPairDevice_OnYesActivatedSlot );
  _this->UpDownPushButtonSet.OnDownButtonActivated = EwNewSlot( _this, SettingsSET08_BtcPairDevice_OnNoActivatedSlot );
  _this->BtcPairingStateChangeEventHandler.OnEvent = EwNewSlot( _this, SettingsSET08_BtcPairDevice_OnBtcPairingStateChangeSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->BtcPairingStateChangeEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->BtcPairingChangedSystemEvent );

  /* Call the user defined constructor */
  SettingsSET08_BtcPairDevice_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET08_BtcPairDevice' */
void SettingsSET08_BtcPairDevice__ReInit( SettingsSET08_BtcPairDevice _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->PairText );
  ViewsText__ReInit( &_this->PasskeyText );
  MenuUpDownPushButtonSet__ReInit( &_this->UpDownPushButtonSet );
  CoreSystemEventHandler__ReInit( &_this->BtcPairingStateChangeEventHandler );
}

/* Finalizer method for the class 'Settings::SET08_BtcPairDevice' */
void SettingsSET08_BtcPairDevice__Done( SettingsSET08_BtcPairDevice _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->PairText );
  ViewsText__Done( &_this->PasskeyText );
  MenuUpDownPushButtonSet__Done( &_this->UpDownPushButtonSet );
  CoreSystemEventHandler__Done( &_this->BtcPairingStateChangeEventHandler );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET08_BtcPairDevice_Init( SettingsSET08_BtcPairDevice _this, XHandle 
  aArg )
{
  XString ProcessString;
  XInt32 LeftIdx;
  XInt32 RightIdx;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const001C ));
  ProcessString = EwLoadString( &StringsSET08_PAIR_WITH );
  LeftIdx = EwStringFind( ProcessString, EwLoadString( &StringsARGUMENT_STR ), 0 );
  RightIdx = ( EwGetStringLength( ProcessString ) - LeftIdx ) - EwGetStringLength( 
  EwLoadString( &StringsARGUMENT_STR ));
  ViewsText_OnSetString( &_this->PairText, EwConcatString( EwConcatString( EwStringLeft( 
  ProcessString, LeftIdx ), DeviceInterfaceBluetoothDeviceClass_GetBtcPairingDeviceName( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ))), 
  EwStringRight( ProcessString, RightIdx )));
  ViewsText_OnSetString( &_this->PasskeyText, EwConcatString( EwConcatString( EwLoadString( 
  &StringsSET08_PASSKEY ), EwLoadString( &_Const000C )), EwNewStringUInt( DeviceInterfaceBluetoothDeviceClass_GetBtcPasskey( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )), 
  6, 10 )));
}

/* 'C' function for method : 'Settings::SET08_BtcPairDevice.OnNoActivatedSlot()' */
void SettingsSET08_BtcPairDevice_OnNoActivatedSlot( SettingsSET08_BtcPairDevice _this, 
  XObject sender )
{
  SettingsSET04_BtSettingMenu BtSettingMenu;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwTrace( "%s", EwLoadString( &_Const001D ));
  BTM_btc_confirm_passkey( false );
  BtSettingMenu = EwCastObject( _this->Super5.Owner, SettingsSET04_BtSettingMenu );

  if ( BtSettingMenu != 0 )
  {
    BtSettingMenu->Super2.SlideOutEffectEnabled = 0;
    ComponentsBaseMainBG_DismissThisDialog((ComponentsBaseMainBG)BtSettingMenu );
  }
}

/* 'C' function for method : 'Settings::SET08_BtcPairDevice.OnYesActivatedSlot()' */
void SettingsSET08_BtcPairDevice_OnYesActivatedSlot( SettingsSET08_BtcPairDevice _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( sender );

  EwTrace( "%s", EwLoadString( &_Const001E ));
  BTM_btc_confirm_passkey( true );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SettingsSET08_BtcPairDevice_OnBtcPairingStateChangeSlot( SettingsSET08_BtcPairDevice _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Super5.Owner != 0 )
    switch ( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->BtcPairingState )
    {
      case EnumBtcPairingStateFAIL :
      {
        SettingsTimeoutDialog PairingFailDialog = EwNewObject( SettingsTimeoutDialog, 
          0 );
        SettingsTimeoutDialog_OnSetMessage( PairingFailDialog, EwLoadString( &StringsSET07_PAIRING_FAILED ));
        PairingFailDialog->DismissAfterTimeout = 1;
        CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)PairingFailDialog ), 
        0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
      break;

      case EnumBtcPairingStateSUCCESSFUL :
      {
        CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)EwNewObject( 
        SettingsSET17_BtcPairedDeviceList, 0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, 
        EwNullSlot, 0 );
        DeviceInterfaceBluetoothDeviceClass_OnSetRefreshPairedDeviceList( EwGetAutoObject( 
        &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 
        1 );
      }
      break;

      default :; 
    }
}

/* Variants derived from the class : 'Settings::SET08_BtcPairDevice' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET08_BtcPairDevice )
EW_END_OF_CLASS_VARIANTS( SettingsSET08_BtcPairDevice )

/* Virtual Method Table (VMT) for the class : 'Settings::SET08_BtcPairDevice' */
EW_DEFINE_CLASS( SettingsSET08_BtcPairDevice, ComponentsBaseMainBG, PairText, PairText, 
                 PairText, PairText, _.VMT, _.VMT, "Settings::SET08_BtcPairDevice" )
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
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SettingsSET08_BtcPairDevice )

/* Initializer for the class 'Settings::SET17_BtcPairedDeviceList' */
void SettingsSET17_BtcPairedDeviceList__Init( SettingsSET17_BtcPairedDeviceList _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET17_BtcPairedDeviceList );

  /* ... then construct all embedded objects */
  CorePropertyObserver__Init( &_this->RefreshListObserver, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->NoDataText, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->NoDataTimeoutTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET17_BtcPairedDeviceList );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 0 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  MenuVerticalMenu_OnSetArrowScrollBarVisible( &_this->Super1.Menu, 1 );
  CoreRectView__OnSetBounds( &_this->NoDataText, _Const0014 );
  ViewsText_OnSetString( &_this->NoDataText, EwLoadString( &_Const001F ));
  CoreTimer_OnSetBegin( &_this->NoDataTimeoutTimer, 2000 );
  CoreGroup__Add( _this, ((CoreView)&_this->NoDataText ), 0 );
  _this->RefreshListObserver.OnEvent = EwNewSlot( _this, SettingsSET17_BtcPairedDeviceList_OnRefreshListSlot );
  CorePropertyObserver_OnSetOutlet( &_this->RefreshListObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), DeviceInterfaceBluetoothDeviceClass_OnGetRefreshPairedDeviceList, 
  DeviceInterfaceBluetoothDeviceClass_OnSetRefreshPairedDeviceList ));
  ViewsText_OnSetFont( &_this->NoDataText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->NoDataTimeoutTimer.OnTrigger = EwNewSlot( _this, SettingsSET17_BtcPairedDeviceList_OnNoDataTimeoutSlot );

  /* Call the user defined constructor */
  SettingsSET17_BtcPairedDeviceList_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET17_BtcPairedDeviceList' */
void SettingsSET17_BtcPairedDeviceList__ReInit( SettingsSET17_BtcPairedDeviceList _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CorePropertyObserver__ReInit( &_this->RefreshListObserver );
  ViewsText__ReInit( &_this->NoDataText );
  CoreTimer__ReInit( &_this->NoDataTimeoutTimer );
}

/* Finalizer method for the class 'Settings::SET17_BtcPairedDeviceList' */
void SettingsSET17_BtcPairedDeviceList__Done( SettingsSET17_BtcPairedDeviceList _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CorePropertyObserver__Done( &_this->RefreshListObserver );
  ViewsText__Done( &_this->NoDataText );
  CoreTimer__Done( &_this->NoDataTimeoutTimer );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET17_BtcPairedDeviceList_Init( SettingsSET17_BtcPairedDeviceList _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0020 ));
  SettingsSET17_BtcPairedDeviceList_UpdatePairedDeviceNum( _this );
}

/* 'C' function for method : 'Settings::SET17_BtcPairedDeviceList.LoadItemClass()' */
XClass SettingsSET17_BtcPairedDeviceList_LoadItemClass( SettingsSET17_BtcPairedDeviceList _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemCheckMark );
}

/* 'C' function for method : 'Settings::SET17_BtcPairedDeviceList.LoadItemTitle()' */
XString SettingsSET17_BtcPairedDeviceList_LoadItemTitle( SettingsSET17_BtcPairedDeviceList _this, 
  XInt32 aItemNo )
{
  XString Title = 0;

  if ( _this->PairedDeviceNum > 0 )
  {
    DeviceInterfaceBluetoothDeviceClass_GetPairedDeviceAtItem( EwGetAutoObject( 
    &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), aItemNo );
    Title = EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->PairedDeviceObj.DeviceName;
  }

  return Title;
}

/* 'C' function for method : 'Settings::SET17_BtcPairedDeviceList.OnItemActivate()' */
void SettingsSET17_BtcPairedDeviceList_OnItemActivate( SettingsSET17_BtcPairedDeviceList _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  MenuItemCheckMark BtDeviceItem = EwCastObject( aMenuItem, MenuItemCheckMark );

  if ( BtDeviceItem != 0 )
  {
    SettingsSET19_BtcPairedDeviceOperation Dialog = EwNewObject( SettingsSET19_BtcPairedDeviceOperation, 
      0 );
    Dialog->PairedDeviceIndex = aItemNo;
    Dialog->DeviceName = EwShareString( BtDeviceItem->Super1.Title.String );
    Dialog->IsConnected = BtDeviceItem->Checked;
    ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)Dialog ));
  }
}

/* 'C' function for method : 'Settings::SET17_BtcPairedDeviceList.LoadItemChecked()' */
XBool SettingsSET17_BtcPairedDeviceList_LoadItemChecked( SettingsSET17_BtcPairedDeviceList _this, 
  XInt32 aItemNo )
{
  XBool result;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aItemNo );

  result = 0;

  if ( _this->PairedDeviceNum > 0 )
    result = EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->PairedDeviceObj.IsConnected;

  return result;
}

/* 'C' function for method : 'Settings::SET17_BtcPairedDeviceList.UpdatePairedDeviceNum()' */
void SettingsSET17_BtcPairedDeviceList_UpdatePairedDeviceNum( SettingsSET17_BtcPairedDeviceList _this )
{
  _this->PairedDeviceNum = DeviceInterfaceBluetoothDeviceClass_OnGetPairedDeviceNum( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ));
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, _this->PairedDeviceNum );
  EwTrace( "%s%i", EwLoadString( &_Const0021 ), _this->PairedDeviceNum );

  if ( _this->PairedDeviceNum > 0 )
  {
    CoreTimer_OnSetEnabled( &_this->NoDataTimeoutTimer, 0 );
    _this->Super1.Menu.Focusable = 1;
    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, _this->PairedDeviceNum 
    - 1 );
    ViewsText_OnSetVisible( &_this->NoDataText, 0 );
  }
  else
  {
    CoreTimer_OnSetEnabled( &_this->NoDataTimeoutTimer, 1 );
    _this->Super1.Menu.Focusable = 0;
    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 0 );
    ViewsText_OnSetVisible( &_this->NoDataText, 1 );
  }
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void SettingsSET17_BtcPairedDeviceList_OnRefreshListSlot( SettingsSET17_BtcPairedDeviceList _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwTrace( "%s", EwLoadString( &_Const0022 ));
  SettingsSET17_BtcPairedDeviceList_UpdatePairedDeviceNum( _this );
}

/* 'C' function for method : 'Settings::SET17_BtcPairedDeviceList.OnNoDataTimeoutSlot()' */
void SettingsSET17_BtcPairedDeviceList_OnNoDataTimeoutSlot( SettingsSET17_BtcPairedDeviceList _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Super6.Owner != 0 )
    ComponentsBaseMainBG_SlideOutDialog((ComponentsBaseMainBG)_this );
}

/* Variants derived from the class : 'Settings::SET17_BtcPairedDeviceList' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET17_BtcPairedDeviceList )
EW_END_OF_CLASS_VARIANTS( SettingsSET17_BtcPairedDeviceList )

/* Virtual Method Table (VMT) for the class : 'Settings::SET17_BtcPairedDeviceList' */
EW_DEFINE_CLASS( SettingsSET17_BtcPairedDeviceList, MenuBaseMenuView, RefreshListObserver, 
                 RefreshListObserver, RefreshListObserver, RefreshListObserver, 
                 PairedDeviceNum, PairedDeviceNum, "Settings::SET17_BtcPairedDeviceList" )
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
  SettingsSET17_BtcPairedDeviceList_LoadItemClass,
  SettingsSET17_BtcPairedDeviceList_LoadItemTitle,
  SettingsSET17_BtcPairedDeviceList_OnItemActivate,
  SettingsSET17_BtcPairedDeviceList_LoadItemChecked,
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
EW_END_OF_CLASS( SettingsSET17_BtcPairedDeviceList )

/* Initializer for the class 'Settings::SET19_BtcPairedDeviceOperation' */
void SettingsSET19_BtcPairedDeviceOperation__Init( SettingsSET19_BtcPairedDeviceOperation _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET19_BtcPairedDeviceOperation );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET19_BtcPairedDeviceOperation );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 3 );

  /* Call the user defined constructor */
  SettingsSET19_BtcPairedDeviceOperation_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET19_BtcPairedDeviceOperation' */
void SettingsSET19_BtcPairedDeviceOperation__ReInit( SettingsSET19_BtcPairedDeviceOperation _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Settings::SET19_BtcPairedDeviceOperation' */
void SettingsSET19_BtcPairedDeviceOperation__Done( SettingsSET19_BtcPairedDeviceOperation _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET19_BtcPairedDeviceOperation_Init( SettingsSET19_BtcPairedDeviceOperation _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0023 ));
}

/* 'C' function for method : 'Settings::SET19_BtcPairedDeviceOperation.LoadItemClass()' */
XClass SettingsSET19_BtcPairedDeviceOperation_LoadItemClass( SettingsSET19_BtcPairedDeviceOperation _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemBase );
}

/* 'C' function for method : 'Settings::SET19_BtcPairedDeviceOperation.LoadItemTitle()' */
XString SettingsSET19_BtcPairedDeviceOperation_LoadItemTitle( SettingsSET19_BtcPairedDeviceOperation _this, 
  XInt32 aItemNo )
{
  XString title;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  title = 0;

  switch ( aItemNo )
  {
    case 0 :
      title = EwLoadString( &StringsSET19_DELETE_PAIRING );
    break;

    case 1 :
      title = EwLoadString( &StringsSET19_CONNECT );
    break;

    case 2 :
      title = EwLoadString( &StringsSET19_DISCONNECT );
    break;

    default :; 
  }

  return title;
}

/* 'C' function for method : 'Settings::SET19_BtcPairedDeviceOperation.OnItemActivate()' */
void SettingsSET19_BtcPairedDeviceOperation_OnItemActivate( SettingsSET19_BtcPairedDeviceOperation _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  switch ( aItemNo )
  {
    case 0 :
    {
      DeviceInterfaceBluetoothDeviceClass_UnpairDevice( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
      DeviceInterfaceBluetoothDeviceClass ), _this->PairedDeviceIndex );

      if ( DeviceInterfaceBluetoothDeviceClass_IsBlePairedDevice( EwGetAutoObject( 
          &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 
          _this->PairedDeviceIndex ))
      {
        SettingsSET18_DeleteBleDevice Dialog = EwNewObject( SettingsSET18_DeleteBleDevice, 
          0 );
        MenuBaseMenuView OwnerMenu;
        Dialog->DeviceName = EwShareString( _this->DeviceName );
        OwnerMenu = EwCastObject( _this->Super6.Owner, MenuBaseMenuView );

        if ( OwnerMenu != 0 )
          ViewsBorder_OnSetVisible( &OwnerMenu->Menu.FocusFrame, 1 );

        CoreGroup_SwitchToDialog( _this->Super6.Owner, ((CoreGroup)Dialog ), 0, 
        0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
      else
      {
        DeviceInterfaceBluetoothDeviceClass_OnSetRefreshPairedDeviceList( EwGetAutoObject( 
        &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 
        1 );
        ComponentsBaseMainBG_SlideOutDialog((ComponentsBaseMainBG)_this );
      }
    }
    break;

    case 1 :
    {
      SettingsSET9_10_11_BtConnectionResult Dialog = EwNewObject( SettingsSET9_10_11_BtConnectionResult, 
        0 );
      MenuBaseMenuView OwnerMenu;
      Dialog->DeviceName = EwShareString( _this->DeviceName );
      OwnerMenu = EwCastObject( _this->Super6.Owner, MenuBaseMenuView );

      if ( OwnerMenu != 0 )
        ViewsBorder_OnSetVisible( &OwnerMenu->Menu.FocusFrame, 1 );

      CoreGroup_SwitchToDialog( _this->Super6.Owner, ((CoreGroup)Dialog ), 0, 0, 
      0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      DeviceInterfaceBluetoothDeviceClass_ConnectPairedDevice( EwGetAutoObject( 
      &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), _this->PairedDeviceIndex );
    }
    break;

    case 2 :
    {
      DeviceInterfaceBluetoothDeviceClass_DisconnectPairedDevice( EwGetAutoObject( 
      &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), _this->PairedDeviceIndex );
      ComponentsBaseMainBG_SlideOutDialog((ComponentsBaseMainBG)_this );
      DeviceInterfaceBluetoothDeviceClass_OnSetRefreshPairedDeviceList( EwGetAutoObject( 
      &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 1 );
    }
    break;

    default : 
      EwTrace( "%s%*", 0, aMenuItem );
  }
}

/* 'C' function for method : 'Settings::SET19_BtcPairedDeviceOperation.LoadItemEnabled()' */
XBool SettingsSET19_BtcPairedDeviceOperation_LoadItemEnabled( SettingsSET19_BtcPairedDeviceOperation _this, 
  XInt32 aItemNo )
{
  XBool OptionEnabled = 0;

  switch ( aItemNo )
  {
    case 0 :
      OptionEnabled = 1;
    break;

    case 1 :
      OptionEnabled = (XBool)!_this->IsConnected;
    break;

    case 2 :
      OptionEnabled = _this->IsConnected;
    break;

    default :; 
  }

  return OptionEnabled;
}

/* Variants derived from the class : 'Settings::SET19_BtcPairedDeviceOperation' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET19_BtcPairedDeviceOperation )
EW_END_OF_CLASS_VARIANTS( SettingsSET19_BtcPairedDeviceOperation )

/* Virtual Method Table (VMT) for the class : 'Settings::SET19_BtcPairedDeviceOperation' */
EW_DEFINE_CLASS( SettingsSET19_BtcPairedDeviceOperation, MenuBaseMenuView, DeviceName, 
                 DeviceName, DeviceName, DeviceName, DeviceName, PairedDeviceIndex, 
                 "Settings::SET19_BtcPairedDeviceOperation" )
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
  SettingsSET19_BtcPairedDeviceOperation_LoadItemClass,
  SettingsSET19_BtcPairedDeviceOperation_LoadItemTitle,
  SettingsSET19_BtcPairedDeviceOperation_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  SettingsSET19_BtcPairedDeviceOperation_LoadItemEnabled,
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
EW_END_OF_CLASS( SettingsSET19_BtcPairedDeviceOperation )

/* Initializer for the class 'Settings::SET18_DeleteBleDevice' */
void SettingsSET18_DeleteBleDevice__Init( SettingsSET18_DeleteBleDevice _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET18_DeleteBleDevice );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Text, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET18_DeleteBleDevice );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0014 );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &StringsSET18_DELETE_PAIRING_RECORD ));
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));

  /* Call the user defined constructor */
  SettingsSET18_DeleteBleDevice_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET18_DeleteBleDevice' */
void SettingsSET18_DeleteBleDevice__ReInit( SettingsSET18_DeleteBleDevice _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Text );
}

/* Finalizer method for the class 'Settings::SET18_DeleteBleDevice' */
void SettingsSET18_DeleteBleDevice__Done( SettingsSET18_DeleteBleDevice _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Text );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET18_DeleteBleDevice_Init( SettingsSET18_DeleteBleDevice _this, XHandle 
  aArg )
{
  XString ProcessString;
  XInt32 LeftIdx;
  XInt32 RightIdx;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0024 ));
  ProcessString = EwLoadString( &StringsSET18_DELETE_PAIRING_RECORD );
  LeftIdx = EwStringFind( ProcessString, EwLoadString( &StringsARGUMENT_STR ), 0 );
  RightIdx = ( EwGetStringLength( ProcessString ) - LeftIdx ) - EwGetStringLength( 
  EwLoadString( &StringsARGUMENT_STR ));
  ViewsText_OnSetString( &_this->Text, EwConcatString( EwConcatString( EwStringLeft( 
  ProcessString, LeftIdx ), _this->DeviceName ), EwStringRight( ProcessString, RightIdx )));
}

/* Variants derived from the class : 'Settings::SET18_DeleteBleDevice' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET18_DeleteBleDevice )
EW_END_OF_CLASS_VARIANTS( SettingsSET18_DeleteBleDevice )

/* Virtual Method Table (VMT) for the class : 'Settings::SET18_DeleteBleDevice' */
EW_DEFINE_CLASS( SettingsSET18_DeleteBleDevice, ComponentsBaseMainBG, Text, Text, 
                 Text, Text, DeviceName, _.VMT, "Settings::SET18_DeleteBleDevice" )
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
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SettingsSET18_DeleteBleDevice )

/* Initializer for the class 'Settings::BtFwUpdateDialog' */
void SettingsBtFwUpdateDialog__Init( SettingsBtFwUpdateDialog _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsBtFwUpdateDialog );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->StatusText, &_this->_.XObject, 0 );
  CorePropertyObserver__Init( &_this->BtFwStatusObserver, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->RemoveDialogTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsBtFwUpdateDialog );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0001 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0001 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0025 );
  CoreRectView__OnSetBounds( &_this->StatusText, _Const0026 );
  ViewsText_OnSetWrapText( &_this->StatusText, 1 );
  ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const0027 ));
  ViewsText_OnSetColor( &_this->StatusText, _Const0028 );
  CoreTimer_OnSetPeriod( &_this->RemoveDialogTimer, 2000 );
  CoreGroup__Add( _this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->StatusText ), 0 );
  ViewsText_OnSetFont( &_this->StatusText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->BtFwStatusObserver.OnEvent = EwNewSlot( _this, SettingsBtFwUpdateDialog_OnBtFwStatusUpdateSlot );
  CorePropertyObserver_OnSetOutlet( &_this->BtFwStatusObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), DeviceInterfaceBluetoothDeviceClass_OnGetBtFwStatus, 
  DeviceInterfaceBluetoothDeviceClass_OnSetBtFwStatus ));
  _this->RemoveDialogTimer.OnTrigger = EwNewSlot( _this, SettingsBtFwUpdateDialog_OnRemoveDialogSlot );
}

/* Re-Initializer for the class 'Settings::BtFwUpdateDialog' */
void SettingsBtFwUpdateDialog__ReInit( SettingsBtFwUpdateDialog _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsText__ReInit( &_this->StatusText );
  CorePropertyObserver__ReInit( &_this->BtFwStatusObserver );
  CoreTimer__ReInit( &_this->RemoveDialogTimer );
}

/* Finalizer method for the class 'Settings::BtFwUpdateDialog' */
void SettingsBtFwUpdateDialog__Done( SettingsBtFwUpdateDialog _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsText__Done( &_this->StatusText );
  CorePropertyObserver__Done( &_this->BtFwStatusObserver );
  CoreTimer__Done( &_this->RemoveDialogTimer );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void SettingsBtFwUpdateDialog_OnBtFwStatusUpdateSlot( SettingsBtFwUpdateDialog _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  switch ( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->BtFwStatus )
  {
    case EnumBtFwStatusUPDATE_FINISH :
    {
      ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const0029 ));
      CoreTimer_OnSetEnabled( &_this->RemoveDialogTimer, 1 );
    }
    break;

    case EnumBtFwStatusUPDATE_ABORT :
    {
      ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const002A ));
      CoreTimer_OnSetEnabled( &_this->RemoveDialogTimer, 1 );
    }
    break;

    default :; 
  }
}

/* 'C' function for method : 'Settings::BtFwUpdateDialog.OnRemoveDialogSlot()' */
void SettingsBtFwUpdateDialog_OnRemoveDialogSlot( SettingsBtFwUpdateDialog _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreRoot_EndModal( CoreView__GetRoot( _this ), ((CoreGroup)_this ));
  CoreGroup__Remove( CoreView__GetRoot( _this ), ((CoreView)_this ));
}

/* Variants derived from the class : 'Settings::BtFwUpdateDialog' */
EW_DEFINE_CLASS_VARIANTS( SettingsBtFwUpdateDialog )
EW_END_OF_CLASS_VARIANTS( SettingsBtFwUpdateDialog )

/* Virtual Method Table (VMT) for the class : 'Settings::BtFwUpdateDialog' */
EW_DEFINE_CLASS( SettingsBtFwUpdateDialog, CoreGroup, Rectangle, Rectangle, Rectangle, 
                 Rectangle, _.VMT, _.VMT, "Settings::BtFwUpdateDialog" )
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
EW_END_OF_CLASS( SettingsBtFwUpdateDialog )

/* Initializer for the class 'Settings::TimeoutDialog' */
void SettingsTimeoutDialog__Init( SettingsTimeoutDialog _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsTimeoutDialog );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->MessageText, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->TimeoutTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsTimeoutDialog );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->MessageText, _Const0014 );
  ViewsText_OnSetEllipsis( &_this->MessageText, 1 );
  ViewsText_OnSetWrapText( &_this->MessageText, 1 );
  ViewsText_OnSetString( &_this->MessageText, 0 );
  CoreTimer_OnSetPeriod( &_this->TimeoutTimer, 0 );
  CoreTimer_OnSetBegin( &_this->TimeoutTimer, 2000 );
  CoreTimer_OnSetEnabled( &_this->TimeoutTimer, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->MessageText ), 0 );
  ViewsText_OnSetFont( &_this->MessageText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->TimeoutTimer.OnTrigger = EwNewSlot( _this, SettingsTimeoutDialog__OnTimeoutSlot );
}

/* Re-Initializer for the class 'Settings::TimeoutDialog' */
void SettingsTimeoutDialog__ReInit( SettingsTimeoutDialog _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->MessageText );
  CoreTimer__ReInit( &_this->TimeoutTimer );
}

/* Finalizer method for the class 'Settings::TimeoutDialog' */
void SettingsTimeoutDialog__Done( SettingsTimeoutDialog _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->MessageText );
  CoreTimer__Done( &_this->TimeoutTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* 'C' function for method : 'Settings::TimeoutDialog.OnSetMessage()' */
void SettingsTimeoutDialog_OnSetMessage( SettingsTimeoutDialog _this, XString value )
{
  if ( EwCompString( _this->Message, value ) != 0 )
  {
    _this->Message = EwShareString( value );
    ViewsText_OnSetString( &_this->MessageText, value );
  }
}

/* 'C' function for method : 'Settings::TimeoutDialog.OnTimeoutSlot()' */
void SettingsTimeoutDialog_OnTimeoutSlot( SettingsTimeoutDialog _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->DismissAfterTimeout && ( _this->Super5.Owner != 0 ))
    CoreGroup_DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 0 );
}

/* Wrapper function for the virtual method : 'Settings::TimeoutDialog.OnTimeoutSlot()' */
void SettingsTimeoutDialog__OnTimeoutSlot( void* _this, XObject sender )
{
  ((SettingsTimeoutDialog)_this)->_.VMT->OnTimeoutSlot((SettingsTimeoutDialog)_this
  , sender );
}

/* Variants derived from the class : 'Settings::TimeoutDialog' */
EW_DEFINE_CLASS_VARIANTS( SettingsTimeoutDialog )
EW_END_OF_CLASS_VARIANTS( SettingsTimeoutDialog )

/* Virtual Method Table (VMT) for the class : 'Settings::TimeoutDialog' */
EW_DEFINE_CLASS( SettingsTimeoutDialog, ComponentsBaseMainBG, MessageText, MessageText, 
                 MessageText, MessageText, Message, DismissAfterTimeout, "Settings::TimeoutDialog" )
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
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  SettingsTimeoutDialog_OnTimeoutSlot,
EW_END_OF_CLASS( SettingsTimeoutDialog )

/* Initializer for the class 'Settings::SET30_QRCode' */
void SettingsSET30_QRCode__Init( SettingsSET30_QRCode _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET30_QRCode );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->QrCodeReadyEventHandler, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->WhiteMargin, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->QrCodeImage, &_this->_.XObject, 0 );
  MenuPushButton__Init( &_this->PushButton, &_this->_.XObject, 0 );
  TelephoneImageButton__Init( &_this->BrightnessUpButton, &_this->_.XObject, 0 );
  TelephoneImageButton__Init( &_this->BrightnessDownButton, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->BrightnessIcon, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET30_QRCode );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->WhiteMargin, _Const002B );
  CoreRectView__OnSetBounds( &_this->QrCodeImage, _Const002B );
  ViewsImage_OnSetAlignment( &_this->QrCodeImage, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  CoreRectView__OnSetBounds( &_this->PushButton, _Const0004 );
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->PushButton, 1 );
  MenuPushButton_OnSetTitle( &_this->PushButton, EwGetVariantOfString( &StringsGEN_OK ));
  CoreRectView__OnSetBounds( &_this->BrightnessUpButton, _Const002C );
  CoreRectView__OnSetBounds( &_this->BrightnessDownButton, _Const002D );
  CoreRectView__OnSetBounds( &_this->BrightnessIcon, _Const002E );
  CoreGroup__Add( _this, ((CoreView)&_this->WhiteMargin ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->QrCodeImage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PushButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BrightnessUpButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BrightnessDownButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BrightnessIcon ), 0 );
  _this->QrCodeReadyEventHandler.OnEvent = EwNewSlot( _this, SettingsSET30_QRCode_OnQrCodeReadySlot );
  CoreSystemEventHandler_OnSetEvent( &_this->QrCodeReadyEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->QrCodeSystemEvent );
  _this->PushButton.OnActivate = EwNewSlot( _this, SettingsSET30_QRCode_OnOkSelectedSlot );
  TelephoneImageButton_OnSetForegroundBmp( &_this->BrightnessUpButton, EwLoadResource( 
  &ResourcePhoneVolumeUp, ResourcesBitmap ));
  TelephoneImageButton_OnSetForegroundBmp( &_this->BrightnessDownButton, EwLoadResource( 
  &ResourcePhoneVolumeDown, ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->BrightnessIcon, EwLoadResource( &ResourceBrightness, 
  ResourcesBitmap ));

  /* Call the user defined constructor */
  SettingsSET30_QRCode_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET30_QRCode' */
void SettingsSET30_QRCode__ReInit( SettingsSET30_QRCode _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->QrCodeReadyEventHandler );
  ViewsRectangle__ReInit( &_this->WhiteMargin );
  ViewsImage__ReInit( &_this->QrCodeImage );
  MenuPushButton__ReInit( &_this->PushButton );
  TelephoneImageButton__ReInit( &_this->BrightnessUpButton );
  TelephoneImageButton__ReInit( &_this->BrightnessDownButton );
  ViewsImage__ReInit( &_this->BrightnessIcon );
}

/* Finalizer method for the class 'Settings::SET30_QRCode' */
void SettingsSET30_QRCode__Done( SettingsSET30_QRCode _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  CoreSystemEventHandler__Done( &_this->QrCodeReadyEventHandler );
  ViewsRectangle__Done( &_this->WhiteMargin );
  ViewsImage__Done( &_this->QrCodeImage );
  MenuPushButton__Done( &_this->PushButton );
  TelephoneImageButton__Done( &_this->BrightnessUpButton );
  TelephoneImageButton__Done( &_this->BrightnessDownButton );
  ViewsImage__Done( &_this->BrightnessIcon );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET30_QRCode_Init( SettingsSET30_QRCode _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  DeviceInterfaceSystemDeviceClass_GetQrCode( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ));
  DeviceInterfaceSystemDeviceClass_SendSystemCommand( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ), EnumSystemTxCmdENABLE_TFT_BRIGHTNESS_MANUAL_ADJ );
  EwPostSignal( EwNewSlot( _this, SettingsSET30_QRCode_UpdateBrightnessButtonEnabled ), 
    ((XObject)_this ));
}

/* 'C' function for method : 'Settings::SET30_QRCode.OnShortDownKeyActivated()' */
void SettingsSET30_QRCode_OnShortDownKeyActivated( SettingsSET30_QRCode _this )
{
  TelephoneImageButton_DisplayHighlightAnimation( &_this->BrightnessDownButton );
  DeviceInterfaceSystemDeviceClass_SendSystemCommand( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ), EnumSystemTxCmdADJ_TFT_BRIGHTNESS_LEVEL_DOWN );
  EwPostSignal( EwNewSlot( _this, SettingsSET30_QRCode_UpdateBrightnessButtonEnabled ), 
    ((XObject)_this ));
}

/* 'C' function for method : 'Settings::SET30_QRCode.OnShortUpKeyActivated()' */
void SettingsSET30_QRCode_OnShortUpKeyActivated( SettingsSET30_QRCode _this )
{
  TelephoneImageButton_DisplayHighlightAnimation( &_this->BrightnessUpButton );
  DeviceInterfaceSystemDeviceClass_SendSystemCommand( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ), EnumSystemTxCmdADJ_TFT_BRIGHTNESS_LEVEL_UP );
  EwPostSignal( EwNewSlot( _this, SettingsSET30_QRCode_UpdateBrightnessButtonEnabled ), 
    ((XObject)_this ));
}

/* 'C' function for method : 'Settings::SET30_QRCode.OnShortHomeKeyActivated()' */
void SettingsSET30_QRCode_OnShortHomeKeyActivated( SettingsSET30_QRCode _this )
{
  DeviceInterfaceSystemDeviceClass_SendSystemCommand( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ), EnumSystemTxCmdDISABLE_TFT_BRIGHTNESS_MANUAL_ADJ );
  ComponentsBaseMainBG_OnShortHomeKeyActivated((ComponentsBaseMainBG)_this );
}

/* 'C' function for method : 'Settings::SET30_QRCode.OnLongHomeKeyActivated()' */
void SettingsSET30_QRCode_OnLongHomeKeyActivated( SettingsSET30_QRCode _this )
{
  DeviceInterfaceSystemDeviceClass_SendSystemCommand( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ), EnumSystemTxCmdDISABLE_TFT_BRIGHTNESS_MANUAL_ADJ );
  ComponentsBaseComponent_OnLongHomeKeyActivated((ComponentsBaseComponent)_this );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SettingsSET30_QRCode_OnQrCodeReadySlot( SettingsSET30_QRCode _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwTrace( "%s", EwLoadString( &_Const002F ));
  ViewsImage_OnSetBitmap( &_this->QrCodeImage, ((ResourcesBitmap)EwGetAutoObject( 
  &ResourceQrCodeExternBitmap, ResourcesExternBitmap )));
  ResourcesExternBitmap_OnSetName( EwGetAutoObject( &ResourceQrCodeExternBitmap, 
  ResourcesExternBitmap ), EwLoadString( &ResourceEXTERN_BMP_QRCODE ));
  ResourcesExternBitmap_Reload( EwGetAutoObject( &ResourceQrCodeExternBitmap, ResourcesExternBitmap ));
}

/* 'C' function for method : 'Settings::SET30_QRCode.OnOkSelectedSlot()' */
void SettingsSET30_QRCode_OnOkSelectedSlot( SettingsSET30_QRCode _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  DeviceInterfaceSystemDeviceClass_SendSystemCommand( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ), EnumSystemTxCmdDISABLE_TFT_BRIGHTNESS_MANUAL_ADJ );
  ComponentsBaseMainBG_DismissThisDialog((ComponentsBaseMainBG)_this );
}

/* 'C' function for method : 'Settings::SET30_QRCode.UpdateBrightnessButtonEnabled()' */
void SettingsSET30_QRCode_UpdateBrightnessButtonEnabled( SettingsSET30_QRCode _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( !!DeviceInterfaceSystemDeviceClass_GetSystemStatus( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
      DeviceInterfaceSystemDeviceClass ), EnumSystemStatusIS_TFT_BRIGHTNESS_LEVEL_MAX ))
    CoreGroup__OnSetEnabled( &_this->BrightnessUpButton, 0 );
  else
    CoreGroup__OnSetEnabled( &_this->BrightnessUpButton, 1 );

  if ( !!DeviceInterfaceSystemDeviceClass_GetSystemStatus( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
      DeviceInterfaceSystemDeviceClass ), EnumSystemStatusIS_TFT_BRIGHTNESS_LEVEL_MIN ))
    CoreGroup__OnSetEnabled( &_this->BrightnessDownButton, 0 );
  else
    CoreGroup__OnSetEnabled( &_this->BrightnessDownButton, 1 );
}

/* Variants derived from the class : 'Settings::SET30_QRCode' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET30_QRCode )
EW_END_OF_CLASS_VARIANTS( SettingsSET30_QRCode )

/* Virtual Method Table (VMT) for the class : 'Settings::SET30_QRCode' */
EW_DEFINE_CLASS( SettingsSET30_QRCode, ComponentsBaseMainBG, QrCodeReadyEventHandler, 
                 QrCodeReadyEventHandler, QrCodeReadyEventHandler, QrCodeReadyEventHandler, 
                 _.VMT, _.VMT, "Settings::SET30_QRCode" )
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
  SettingsSET30_QRCode_OnShortDownKeyActivated,
  SettingsSET30_QRCode_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  SettingsSET30_QRCode_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  SettingsSET30_QRCode_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SettingsSET30_QRCode )

/* Initializer for the class 'Settings::SET22_BleAdvertising' */
void SettingsSET22_BleAdvertising__Init( SettingsSET22_BleAdvertising _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET22_BleAdvertising );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->DeviceNameText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->WaitText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->LocalDeviceNameText, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Image, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->BlePairingStateChangedEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET22_BleAdvertising );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->DeviceNameText, _Const0030 );
  ViewsText_OnSetString( &_this->DeviceNameText, EwLoadString( &StringsSET22_DEVICE_NAME ));
  CoreRectView__OnSetBounds( &_this->WaitText, _Const0031 );
  ViewsText_OnSetWrapText( &_this->WaitText, 1 );
  ViewsText_OnSetString( &_this->WaitText, EwLoadString( &StringsSET22_WAIT_APP_CONNECTION ));
  CoreRectView__OnSetBounds( &_this->LocalDeviceNameText, _Const0032 );
  ViewsText_OnSetEllipsis( &_this->LocalDeviceNameText, 1 );
  ViewsText_OnSetString( &_this->LocalDeviceNameText, DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceName( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )));
  CoreRectView__OnSetBounds( &_this->Image, _Const0033 );
  ViewsImage_OnSetAnimated( &_this->Image, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->DeviceNameText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->WaitText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LocalDeviceNameText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Image ), 0 );
  ViewsText_OnSetFont( &_this->DeviceNameText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->WaitText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->LocalDeviceNameText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceLoadingAnimation, 
  ResourcesBitmap ));
  _this->BlePairingStateChangedEventHandler.OnEvent = EwNewSlot( _this, SettingsSET22_BleAdvertising_OnBlePairingStateChangedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->BlePairingStateChangedEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->BlePairingStateChangedEvent );

  /* Call the user defined constructor */
  SettingsSET22_BleAdvertising_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET22_BleAdvertising' */
void SettingsSET22_BleAdvertising__ReInit( SettingsSET22_BleAdvertising _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->DeviceNameText );
  ViewsText__ReInit( &_this->WaitText );
  ViewsText__ReInit( &_this->LocalDeviceNameText );
  ViewsImage__ReInit( &_this->Image );
  CoreSystemEventHandler__ReInit( &_this->BlePairingStateChangedEventHandler );
}

/* Finalizer method for the class 'Settings::SET22_BleAdvertising' */
void SettingsSET22_BleAdvertising__Done( SettingsSET22_BleAdvertising _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->DeviceNameText );
  ViewsText__Done( &_this->WaitText );
  ViewsText__Done( &_this->LocalDeviceNameText );
  ViewsImage__Done( &_this->Image );
  CoreSystemEventHandler__Done( &_this->BlePairingStateChangedEventHandler );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET22_BleAdvertising_Init( SettingsSET22_BleAdvertising _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0034 ));
  DeviceInterfaceBluetoothDeviceClass_SetBleAdvertisement( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ), 1 );
}

/* 'C' function for method : 'Settings::SET22_BleAdvertising.OnShortHomeKeyActivated()' */
void SettingsSET22_BleAdvertising_OnShortHomeKeyActivated( SettingsSET22_BleAdvertising _this )
{
  DeviceInterfaceBluetoothDeviceClass_SetBleAdvertisement( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ), 0 );
  ComponentsBaseMainBG_OnShortHomeKeyActivated((ComponentsBaseMainBG)_this );
}

/* 'C' function for method : 'Settings::SET22_BleAdvertising.OnLongHomeKeyActivated()' */
void SettingsSET22_BleAdvertising_OnLongHomeKeyActivated( SettingsSET22_BleAdvertising _this )
{
  DeviceInterfaceBluetoothDeviceClass_SetBleAdvertisement( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ), 0 );
  ComponentsBaseComponent_OnLongHomeKeyActivated((ComponentsBaseComponent)_this );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SettingsSET22_BleAdvertising_OnBlePairingStateChangedSlot( SettingsSET22_BleAdvertising _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Super5.Owner != 0 )
    switch ( DeviceInterfaceBluetoothDeviceClass_OnGetBlePairingState( EwGetAutoObject( 
            &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )))
    {
      case EnumBlePairingStateTIMEOUT :
      case EnumBlePairingStateFAIL :
      {
        DeviceInterfaceBluetoothDeviceClass_SetBleAdvertisement( EwGetAutoObject( 
        &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 
        0 );
        CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)EwNewObject( 
        SettingsSET23_BlePairingFail, 0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 
        0 );
      }
      break;

      case EnumBlePairingStateSUCCESSFUL :
      {
        SettingsTimeoutDialog MessageDialog = EwNewObject( SettingsTimeoutDialog, 
          0 );
        SettingsSET03_ConnectionSettingMenu ConnectionSettingDialog = EwCastObject( 
          _this->Super5.Owner, SettingsSET03_ConnectionSettingMenu );

        if ( ConnectionSettingDialog != 0 )
        {
          SettingsTimeoutDialog_OnSetMessage( MessageDialog, EwLoadString( &StringsSET26_PAIRING_SUCCESSFUL ));
          MessageDialog->DismissAfterTimeout = 1;
          DeviceInterfaceBluetoothDeviceClass_SetBleAdvertisement( EwGetAutoObject( 
          &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 
          0 );
          CoreGroup_SwitchToDialog((CoreGroup)ConnectionSettingDialog, ((CoreGroup)MessageDialog ), 
          0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
        }
      }
      break;

      case EnumBlePairingStatePINCODE_GENERATED :
      {
        DeviceInterfaceBluetoothDeviceClass_SetBleAdvertisement( EwGetAutoObject( 
        &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 
        0 );
        CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)EwNewObject( 
        SettingsSET25_BlePincode, 0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 
        0 );
      }
      break;

      default :; 
    }
}

/* Variants derived from the class : 'Settings::SET22_BleAdvertising' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET22_BleAdvertising )
EW_END_OF_CLASS_VARIANTS( SettingsSET22_BleAdvertising )

/* Virtual Method Table (VMT) for the class : 'Settings::SET22_BleAdvertising' */
EW_DEFINE_CLASS( SettingsSET22_BleAdvertising, ComponentsBaseMainBG, DeviceNameText, 
                 DeviceNameText, DeviceNameText, DeviceNameText, _.VMT, _.VMT, "Settings::SET22_BleAdvertising" )
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
  SettingsSET22_BleAdvertising_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  SettingsSET22_BleAdvertising_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SettingsSET22_BleAdvertising )

/* Initializer for the class 'Settings::SET23_BlePairingFail' */
void SettingsSET23_BlePairingFail__Init( SettingsSET23_BlePairingFail _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  SettingsTimeoutDialog__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET23_BlePairingFail );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET23_BlePairingFail );

  /* ... and initialize objects, variables, properties, etc. */
  ViewsText_OnSetString( &_this->Super1.MessageText, EwLoadString( &StringsSET23_PAIRING_FAILED ));
}

/* Re-Initializer for the class 'Settings::SET23_BlePairingFail' */
void SettingsSET23_BlePairingFail__ReInit( SettingsSET23_BlePairingFail _this )
{
  /* At first re-initialize the super class ... */
  SettingsTimeoutDialog__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Settings::SET23_BlePairingFail' */
void SettingsSET23_BlePairingFail__Done( SettingsSET23_BlePairingFail _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( SettingsTimeoutDialog );

  /* Don't forget to deinitialize the super class ... */
  SettingsTimeoutDialog__Done( &_this->_.Super );
}

/* 'C' function for method : 'Settings::SET23_BlePairingFail.OnTimeoutSlot()' */
void SettingsSET23_BlePairingFail_OnTimeoutSlot( SettingsSET23_BlePairingFail _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( DeviceInterfaceBluetoothDeviceClass_GetBlePairingFailCount( EwGetAutoObject( 
      &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )) > 
      1 )
    CoreGroup_SwitchToDialog( _this->Super6.Owner, ((CoreGroup)EwNewObject( SettingsSET24_CheckPairingRecord, 
    0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  else
    CoreGroup_DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 0 );
}

/* Variants derived from the class : 'Settings::SET23_BlePairingFail' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET23_BlePairingFail )
EW_END_OF_CLASS_VARIANTS( SettingsSET23_BlePairingFail )

/* Virtual Method Table (VMT) for the class : 'Settings::SET23_BlePairingFail' */
EW_DEFINE_CLASS( SettingsSET23_BlePairingFail, SettingsTimeoutDialog, _.VMT, _.VMT, 
                 _.VMT, _.VMT, _.VMT, _.VMT, "Settings::SET23_BlePairingFail" )
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
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  SettingsSET23_BlePairingFail_OnTimeoutSlot,
EW_END_OF_CLASS( SettingsSET23_BlePairingFail )

/* Initializer for the class 'Settings::SET24_CheckPairingRecord' */
void SettingsSET24_CheckPairingRecord__Init( SettingsSET24_CheckPairingRecord _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET24_CheckPairingRecord );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->MessageText, &_this->_.XObject, 0 );
  MenuPushButton__Init( &_this->PushButton, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET24_CheckPairingRecord );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->MessageText, _Const0005 );
  ViewsText_OnSetWrapText( &_this->MessageText, 1 );
  ViewsText_OnSetString( &_this->MessageText, EwLoadString( &StringsSET24_CHECK_BT_PAIRING_RECORD ));
  CoreRectView__OnSetBounds( &_this->PushButton, _Const0004 );
  MenuPushButton_OnSetTitle( &_this->PushButton, EwGetVariantOfString( &StringsGEN_OK ));
  CoreGroup__Add( _this, ((CoreView)&_this->MessageText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PushButton ), 0 );
  ViewsText_OnSetFont( &_this->MessageText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->PushButton.OnActivate = EwNewSlot( _this, SettingsSET24_CheckPairingRecord_OnOkActivatedSlot );

  /* Call the user defined constructor */
  SettingsSET24_CheckPairingRecord_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET24_CheckPairingRecord' */
void SettingsSET24_CheckPairingRecord__ReInit( SettingsSET24_CheckPairingRecord _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->MessageText );
  MenuPushButton__ReInit( &_this->PushButton );
}

/* Finalizer method for the class 'Settings::SET24_CheckPairingRecord' */
void SettingsSET24_CheckPairingRecord__Done( SettingsSET24_CheckPairingRecord _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->MessageText );
  MenuPushButton__Done( &_this->PushButton );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET24_CheckPairingRecord_Init( SettingsSET24_CheckPairingRecord _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0035 ));
}

/* 'C' function for method : 'Settings::SET24_CheckPairingRecord.OnOkActivatedSlot()' */
void SettingsSET24_CheckPairingRecord_OnOkActivatedSlot( SettingsSET24_CheckPairingRecord _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* Variants derived from the class : 'Settings::SET24_CheckPairingRecord' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET24_CheckPairingRecord )
EW_END_OF_CLASS_VARIANTS( SettingsSET24_CheckPairingRecord )

/* Virtual Method Table (VMT) for the class : 'Settings::SET24_CheckPairingRecord' */
EW_DEFINE_CLASS( SettingsSET24_CheckPairingRecord, ComponentsBaseMainBG, MessageText, 
                 MessageText, MessageText, MessageText, _.VMT, _.VMT, "Settings::SET24_CheckPairingRecord" )
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
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SettingsSET24_CheckPairingRecord )

/* Initializer for the class 'Settings::SET25_BlePincode' */
void SettingsSET25_BlePincode__Init( SettingsSET25_BlePincode _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET25_BlePincode );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->BleStateChangedEventHandler, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->PincodeText, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET25_BlePincode );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->PincodeText, _Const0014 );
  ViewsText_OnSetString( &_this->PincodeText, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PincodeText ), 0 );
  _this->BleStateChangedEventHandler.OnEvent = EwNewSlot( _this, SettingsSET25_BlePincode_OnBlePairingStateChangedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->BleStateChangedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->BlePairingStateChangedEvent );
  ViewsText_OnSetFont( &_this->PincodeText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));

  /* Call the user defined constructor */
  SettingsSET25_BlePincode_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET25_BlePincode' */
void SettingsSET25_BlePincode__ReInit( SettingsSET25_BlePincode _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->BleStateChangedEventHandler );
  ViewsText__ReInit( &_this->PincodeText );
}

/* Finalizer method for the class 'Settings::SET25_BlePincode' */
void SettingsSET25_BlePincode__Done( SettingsSET25_BlePincode _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  CoreSystemEventHandler__Done( &_this->BleStateChangedEventHandler );
  ViewsText__Done( &_this->PincodeText );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET25_BlePincode_Init( SettingsSET25_BlePincode _this, XHandle aArg )
{
  XString PincodeString;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  PincodeString = EwNewStringUInt( DeviceInterfaceBluetoothDeviceClass_OnGetBlePincode( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )), 
  6, 10 );
  ViewsText_OnSetString( &_this->PincodeText, EwConcatString( EwConcatString( EwLoadString( 
  &StringsSET25_PIN ), EwLoadString( &_Const000C )), PincodeString ));
  EwTrace( "%s%s", EwLoadString( &_Const0036 ), PincodeString );
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
void SettingsSET25_BlePincode_UpdateViewState( SettingsSET25_BlePincode _this, XSet 
  aState )
{
  CoreGroup_UpdateViewState((CoreGroup)_this, aState );

  if ((( aState & CoreViewStateDialog ) == CoreViewStateDialog ) && ( _this->Super5.Owner 
      != 0 ))
    EwPostSignal( EwNewSlot( _this, SettingsSET25_BlePincode_OnBlePairingStateChangedSlot ), 
      ((XObject)_this ));
}

/* 'C' function for method : 'Settings::SET25_BlePincode.OnShortHomeKeyActivated()' */
void SettingsSET25_BlePincode_OnShortHomeKeyActivated( SettingsSET25_BlePincode _this )
{
  DeviceInterfaceBluetoothDeviceClass_SetBleAdvertisement( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ), 0 );
  ComponentsBaseMainBG_OnShortHomeKeyActivated((ComponentsBaseMainBG)_this );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SettingsSET25_BlePincode_OnBlePairingStateChangedSlot( SettingsSET25_BlePincode _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Super5.Owner != 0 )
    switch ( DeviceInterfaceBluetoothDeviceClass_OnGetBlePairingState( EwGetAutoObject( 
            &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )))
    {
      case EnumBlePairingStateFAIL :
      case EnumBlePairingStateTIMEOUT :
        CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)EwNewObject( 
        SettingsSET23_BlePairingFail, 0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 
        0 );
      break;

      case EnumBlePairingStateSUCCESSFUL :
      {
        SettingsTimeoutDialog MessageDialog = EwNewObject( SettingsTimeoutDialog, 
          0 );
        SettingsTimeoutDialog_OnSetMessage( MessageDialog, EwLoadString( &StringsSET26_PAIRING_SUCCESSFUL ));
        MessageDialog->DismissAfterTimeout = 1;
        CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)MessageDialog ), 
        0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
      break;

      default :; 
    }
}

/* Variants derived from the class : 'Settings::SET25_BlePincode' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET25_BlePincode )
EW_END_OF_CLASS_VARIANTS( SettingsSET25_BlePincode )

/* Virtual Method Table (VMT) for the class : 'Settings::SET25_BlePincode' */
EW_DEFINE_CLASS( SettingsSET25_BlePincode, ComponentsBaseMainBG, BleStateChangedEventHandler, 
                 BleStateChangedEventHandler, BleStateChangedEventHandler, BleStateChangedEventHandler, 
                 _.VMT, _.VMT, "Settings::SET25_BlePincode" )
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
  SettingsSET25_BlePincode_UpdateViewState,
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
  SettingsSET25_BlePincode_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SettingsSET25_BlePincode )

/* Initializer for the class 'Settings::SET28_SystemInfo' */
void SettingsSET28_SystemInfo__Init( SettingsSET28_SystemInfo _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET28_SystemInfo );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->ESN, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->SoftwareVersionTitle, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->EsnText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->SoftwareVersionText, &_this->_.XObject, 0 );
  CorePropertyObserver__Init( &_this->EsnObserver, &_this->_.XObject, 0 );
  MenuUpDownPushButtonSet__Init( &_this->UpDownPushButtonSet, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Divider, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ReceivedSystemEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET28_SystemInfo );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0001 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  ComponentsBaseComponent_OnSetMagicKeyEnabled((ComponentsBaseComponent)_this, 1 );
  CoreRectView__OnSetBounds( &_this->ESN, _Const0037 );
  ViewsText_OnSetString( &_this->ESN, EwLoadString( &StringsSET28_ESN ));
  CoreRectView__OnSetBounds( &_this->SoftwareVersionTitle, _Const0038 );
  ViewsText_OnSetString( &_this->SoftwareVersionTitle, EwLoadString( &StringsSET28_SW_VERSION ));
  CoreRectView__OnSetBounds( &_this->EsnText, _Const0039 );
  ViewsText_OnSetString( &_this->EsnText, 0 );
  CoreRectView__OnSetBounds( &_this->SoftwareVersionText, _Const003A );
  ViewsText_OnSetString( &_this->SoftwareVersionText, DeviceInterfaceSystemDeviceClass_OnGetSoftwareVersion( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const003B );
  _this->UpDownPushButtonSet.Super1.PassHomeKey = 1;
  _this->UpDownPushButtonSet.Super1.PassMagicKey = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->UpDownPushButtonSet, 1 );
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &StringsSET28_UNIT_ID ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &StringsSET28_SW_UPDATE ));
  MenuUpDownPushButtonSet_OnSetDownButtonEnabled( &_this->UpDownPushButtonSet, 0 );
  CoreRectView__OnSetBounds( &_this->Divider, _Const0015 );
  ViewsImage_OnSetAlignment( &_this->Divider, ViewsImageAlignmentAlignVertBottom 
  | ViewsImageAlignmentScaleToFit );
  CoreGroup__Add( _this, ((CoreView)&_this->ESN ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SoftwareVersionTitle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->EsnText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SoftwareVersionText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UpDownPushButtonSet ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider ), 0 );
  ViewsText_OnSetFont( &_this->ESN, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->SoftwareVersionTitle, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->EsnText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->SoftwareVersionText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->EsnObserver.OnEvent = EwNewSlot( _this, SettingsSET28_SystemInfo_OnEsnReceivedSlot );
  CorePropertyObserver_OnSetOutlet( &_this->EsnObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ), DeviceInterfaceSystemDeviceClass_OnGetESN, 
  DeviceInterfaceSystemDeviceClass_OnSetESN ));
  _this->UpDownPushButtonSet.OnUpButtonActivated = EwNewSlot( _this, SettingsSET28_SystemInfo_OnUnitIdButtonActivatedSlot );
  _this->UpDownPushButtonSet.OnDownButtonActivated = EwNewSlot( _this, SettingsSET28_SystemInfo_OnSoftwareUpdateButtonActivatedSlot );
  ViewsImage_OnSetBitmap( &_this->Divider, EwLoadResource( &ResourceStatusBarDivider, 
  ResourcesBitmap ));
  _this->ReceivedSystemEventHandler.OnEvent = EwNewSlot( _this, SettingsSET28_SystemInfo_OnSystemEventReceived );
  CoreSystemEventHandler_OnSetEvent( &_this->ReceivedSystemEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->SystemDataReceivedSystemEvent );

  /* Call the user defined constructor */
  SettingsSET28_SystemInfo_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET28_SystemInfo' */
void SettingsSET28_SystemInfo__ReInit( SettingsSET28_SystemInfo _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->ESN );
  ViewsText__ReInit( &_this->SoftwareVersionTitle );
  ViewsText__ReInit( &_this->EsnText );
  ViewsText__ReInit( &_this->SoftwareVersionText );
  CorePropertyObserver__ReInit( &_this->EsnObserver );
  MenuUpDownPushButtonSet__ReInit( &_this->UpDownPushButtonSet );
  ViewsImage__ReInit( &_this->Divider );
  CoreSystemEventHandler__ReInit( &_this->ReceivedSystemEventHandler );
}

/* Finalizer method for the class 'Settings::SET28_SystemInfo' */
void SettingsSET28_SystemInfo__Done( SettingsSET28_SystemInfo _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->ESN );
  ViewsText__Done( &_this->SoftwareVersionTitle );
  ViewsText__Done( &_this->EsnText );
  ViewsText__Done( &_this->SoftwareVersionText );
  CorePropertyObserver__Done( &_this->EsnObserver );
  MenuUpDownPushButtonSet__Done( &_this->UpDownPushButtonSet );
  ViewsImage__Done( &_this->Divider );
  CoreSystemEventHandler__Done( &_this->ReceivedSystemEventHandler );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET28_SystemInfo_Init( SettingsSET28_SystemInfo _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  ViewsText_OnSetString( &_this->EsnText, DeviceInterfaceSystemDeviceClass_OnGetESN( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
  ViewsText_OnSetString( &_this->SoftwareVersionText, DeviceInterfaceSystemDeviceClass_OnGetSoftwareVersion( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
  MenuUpDownPushButtonSet_OnSetDownButtonEnabled( &_this->UpDownPushButtonSet, DeviceInterfaceSystemDeviceClass_OnGetIsSoftwareUpdateEnabled( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
}

/* 'C' function for method : 'Settings::SET28_SystemInfo.OnShortMagicKeyActivated()' */
void SettingsSET28_SystemInfo_OnShortMagicKeyActivated( SettingsSET28_SystemInfo _this )
{
  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_Main, 
  0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void SettingsSET28_SystemInfo_OnEsnReceivedSlot( SettingsSET28_SystemInfo _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsText_OnSetString( &_this->EsnText, DeviceInterfaceSystemDeviceClass_OnGetESN( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
}

/* 'C' function for method : 'Settings::SET28_SystemInfo.OnUnitIdButtonActivatedSlot()' */
void SettingsSET28_SystemInfo_OnUnitIdButtonActivatedSlot( SettingsSET28_SystemInfo _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsSET30_QRCode, 
  0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SettingsSET28_SystemInfo_OnSystemEventReceived( SettingsSET28_SystemInfo _this, 
  XObject sender )
{
  DeviceInterfaceSystemData SystemData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  SystemData = EwCastObject( _this->ReceivedSystemEventHandler.Context, DeviceInterfaceSystemData );

  if ( SystemData != 0 )
    switch ( SystemData->RxEvent )
    {
      case EnumSystemRxEventSW_UPDATE_ENABLE :
        MenuUpDownPushButtonSet_OnSetDownButtonEnabled( &_this->UpDownPushButtonSet, 
        1 );
      break;

      case EnumSystemRxEventSW_UPDATE_DISABLE :
        MenuUpDownPushButtonSet_OnSetDownButtonEnabled( &_this->UpDownPushButtonSet, 
        0 );
      break;

      default :; 
    }
}

/* 'C' function for method : 'Settings::SET28_SystemInfo.OnSoftwareUpdateButtonActivatedSlot()' */
void SettingsSET28_SystemInfo_OnSoftwareUpdateButtonActivatedSlot( SettingsSET28_SystemInfo _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsSET27_ConfirmUpdate, 
  0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* Variants derived from the class : 'Settings::SET28_SystemInfo' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET28_SystemInfo )
EW_END_OF_CLASS_VARIANTS( SettingsSET28_SystemInfo )

/* Virtual Method Table (VMT) for the class : 'Settings::SET28_SystemInfo' */
EW_DEFINE_CLASS( SettingsSET28_SystemInfo, ComponentsBaseMainBG, ESN, ESN, ESN, 
                 ESN, _.VMT, _.VMT, "Settings::SET28_SystemInfo" )
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
  SettingsSET28_SystemInfo_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SettingsSET28_SystemInfo )

/* Initializer for the class 'Settings::LicenseDetail' */
void SettingsLicenseDetail__Init( SettingsLicenseDetail _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsLicenseDetail );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->TitleText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->LicenseText, &_this->_.XObject, 0 );
  EffectsInt32Effect__Init( &_this->ScrollEffect, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsLicenseDetail );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const003C );
  CoreRectView__OnSetBounds( &_this->TitleText, _Const003D );
  ViewsText_OnSetAlignment( &_this->TitleText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TitleText, EwLoadString( &StringsSET35_LICENSE ));
  CoreRectView__OnSetBounds( &_this->LicenseText, _Const003E );
  ViewsText_OnSetRowDistance( &_this->LicenseText, 30 );
  ViewsText_OnSetAutoSize( &_this->LicenseText, 1 );
  ViewsText_OnSetWrapText( &_this->LicenseText, 1 );
  ViewsText_OnSetAlignment( &_this->LicenseText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertTop );
  EffectsEffect_OnSetExponent((EffectsEffect)&_this->ScrollEffect, 4.190000f );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->ScrollEffect, EffectsTimingExp_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->ScrollEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->ScrollEffect, 200 );
  EffectsEffect_OnSetInitialDelay((EffectsEffect)&_this->ScrollEffect, 0 );
  _this->LicenseInitBounds = _Const003E;
  CoreGroup__Add( _this, ((CoreView)&_this->TitleText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LicenseText ), 0 );
  ViewsText_OnSetFont( &_this->TitleText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->LicenseText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->ScrollEffect.Super1.OnFinished = EwNullSlot;
  _this->ScrollEffect.Super1.OnAnimate = EwNullSlot;
  _this->ScrollEffect.Outlet = EwNewRef( _this, SettingsLicenseDetail_OnGetScrollOffsetY, 
  SettingsLicenseDetail_OnSetScrollOffsetY );
}

/* Re-Initializer for the class 'Settings::LicenseDetail' */
void SettingsLicenseDetail__ReInit( SettingsLicenseDetail _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->TitleText );
  ViewsText__ReInit( &_this->LicenseText );
  EffectsInt32Effect__ReInit( &_this->ScrollEffect );
}

/* Finalizer method for the class 'Settings::LicenseDetail' */
void SettingsLicenseDetail__Done( SettingsLicenseDetail _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->TitleText );
  ViewsText__Done( &_this->LicenseText );
  EffectsInt32Effect__Done( &_this->ScrollEffect );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Settings::LicenseDetail.ScrollUpPage()' */
XInt32 SettingsLicenseDetail_ScrollUpPage( SettingsLicenseDetail _this )
{
  if ( !_this->ScrollEffect.Super1.Enabled && ( _this->ScrollOffsetY < 0 ))
  {
    XInt32 NextScrollOffsetY = _this->ScrollOffsetY + EwGetRectH( _this->Super2.Bounds );

    if ( NextScrollOffsetY > 0 )
      NextScrollOffsetY = 0;

    _this->ScrollEffect.Value1 = _this->ScrollOffsetY;
    _this->ScrollEffect.Value2 = NextScrollOffsetY;
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->ScrollEffect, 1 );
    _this->LineToScroll = (( EwGetInt32Abs( NextScrollOffsetY ) / _this->LicenseText.RowDistance ) 
    + 7 ) - 1;
    EwTrace( "%s%i", EwLoadString( &_Const003F ), _this->LineToScroll );
  }

  return _this->LineToScroll;
}

/* 'C' function for method : 'Settings::LicenseDetail.ScrollDownPage()' */
XInt32 SettingsLicenseDetail_ScrollDownPage( SettingsLicenseDetail _this )
{
  if ( !_this->ScrollEffect.Super1.Enabled )
  {
    XInt32 NextScrollOffsetY = _this->ScrollOffsetY - EwGetRectH( _this->Super2.Bounds );
    XInt32 MaxScrollOffset = ( _this->NoOfLines * _this->LicenseText.RowDistance ) 
      - EwGetRectH( _this->Super2.Bounds );

    if ( MaxScrollOffset < 0 )
      MaxScrollOffset = 0;

    if ( EwGetInt32Abs( NextScrollOffsetY ) > MaxScrollOffset )
      NextScrollOffsetY = -1 * MaxScrollOffset;

    _this->ScrollEffect.Value1 = _this->ScrollOffsetY;
    _this->ScrollEffect.Value2 = NextScrollOffsetY;
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->ScrollEffect, 1 );
    _this->LineToScroll = (( EwGetInt32Abs( NextScrollOffsetY ) / _this->LicenseText.RowDistance ) 
    + 7 ) - 1;
    EwTrace( "%s%i", EwLoadString( &_Const003F ), _this->LineToScroll );
  }

  return _this->LineToScroll;
}

/* 'C' function for method : 'Settings::LicenseDetail.OnSetScrollOffsetY()' */
void SettingsLicenseDetail_OnSetScrollOffsetY( SettingsLicenseDetail _this, XInt32 
  value )
{
  if ( _this->ScrollOffsetY != value )
  {
    XRect NewBounds;
    _this->ScrollOffsetY = value;
    NewBounds = _Const003D;
    NewBounds.Point1.Y = value;
    NewBounds.Point2.Y = ( NewBounds.Point1.Y + 31 );
    CoreRectView__OnSetBounds( &_this->TitleText, NewBounds );
    NewBounds = _this->LicenseInitBounds;
    NewBounds.Point1.Y = ( NewBounds.Point1.Y + value );
    NewBounds.Point2.Y = ( NewBounds.Point1.Y + EwGetRectH( _this->LicenseInitBounds ));
    CoreRectView__OnSetBounds( &_this->LicenseText, NewBounds );
  }
}

/* 'C' function for method : 'Settings::LicenseDetail.UpdateLineNum()' */
void SettingsLicenseDetail_UpdateLineNum( SettingsLicenseDetail _this )
{
  _this->NoOfLines = ViewsText_GetNoOfRows( &_this->LicenseText ) + 2;
  EwSignal( _this->OnLineNumUpdated, ((XObject)_this ));
}

/* Default onget method for the property 'ScrollOffsetY' */
XInt32 SettingsLicenseDetail_OnGetScrollOffsetY( SettingsLicenseDetail _this )
{
  return _this->ScrollOffsetY;
}

/* Variants derived from the class : 'Settings::LicenseDetail' */
EW_DEFINE_CLASS_VARIANTS( SettingsLicenseDetail )
EW_END_OF_CLASS_VARIANTS( SettingsLicenseDetail )

/* Virtual Method Table (VMT) for the class : 'Settings::LicenseDetail' */
EW_DEFINE_CLASS( SettingsLicenseDetail, CoreGroup, OnLineNumUpdated, OnLineNumUpdated, 
                 TitleText, TitleText, LineToScroll, LineToScroll, "Settings::LicenseDetail" )
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
EW_END_OF_CLASS( SettingsLicenseDetail )

/* Initializer for the class 'Settings::SET43_ResetMenu' */
void SettingsSET43_ResetMenu__Init( SettingsSET43_ResetMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET43_ResetMenu );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET43_ResetMenu );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 4 );
  MenuVerticalMenu_OnSetArrowScrollBarVisible( &_this->Super1.Menu, 1 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsSET43_TRIP_MILEAGE_RESET ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsSET43_MAINTENANCE_RESET ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &StringsSET43_VEHICLE_INFO ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &StringsSET43_ALL_RESET ));

  /* Call the user defined constructor */
  SettingsSET43_ResetMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET43_ResetMenu' */
void SettingsSET43_ResetMenu__ReInit( SettingsSET43_ResetMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Settings::SET43_ResetMenu' */
void SettingsSET43_ResetMenu__Done( SettingsSET43_ResetMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET43_ResetMenu_Init( SettingsSET43_ResetMenu _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0040 ));
}

/* 'C' function for method : 'Settings::SET43_ResetMenu.LoadItemClass()' */
XClass SettingsSET43_ResetMenu_LoadItemClass( SettingsSET43_ResetMenu _this, XInt32 
  aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemBase );
}

/* 'C' function for method : 'Settings::SET43_ResetMenu.LoadItemTitle()' */
XString SettingsSET43_ResetMenu_LoadItemTitle( SettingsSET43_ResetMenu _this, XInt32 
  aItemNo )
{
  XString title = 0;

  if ( aItemNo < 4 )
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 4 )];

  return title;
}

/* 'C' function for method : 'Settings::SET43_ResetMenu.OnItemActivate()' */
void SettingsSET43_ResetMenu_OnItemActivate( SettingsSET43_ResetMenu _this, XInt32 
  aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  switch ( aItemNo )
  {
    case 0 :
      ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)EwNewObject( 
      SettingsSET45_TripMileageReset, 0 )));
    break;

    case 1 :
      ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)EwNewObject( 
      MaintenanceMNT01_MaintenanceReset, 0 )));
    break;

    case 2 :
      ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)EwNewObject( 
      SettingsSET46_VehicleInfoReset, 0 )));
    break;

    case 3 :
      if ( !EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->IsHopperTestMode )
        ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)EwNewObject( 
        SettingsSET38_ConfirmAllReset, 0 )));
    break;

    default :; 
  }
}

/* Variants derived from the class : 'Settings::SET43_ResetMenu' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET43_ResetMenu )
EW_END_OF_CLASS_VARIANTS( SettingsSET43_ResetMenu )

/* Virtual Method Table (VMT) for the class : 'Settings::SET43_ResetMenu' */
EW_DEFINE_CLASS( SettingsSET43_ResetMenu, MenuBaseMenuView, ItemTitleArray, ItemTitleArray, 
                 ItemTitleArray, ItemTitleArray, ItemTitleArray, _.VMT, "Settings::SET43_ResetMenu" )
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
  SettingsSET43_ResetMenu_LoadItemClass,
  SettingsSET43_ResetMenu_LoadItemTitle,
  SettingsSET43_ResetMenu_OnItemActivate,
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
EW_END_OF_CLASS( SettingsSET43_ResetMenu )

/* Initializer for the class 'Settings::SET42_ResetCompleted' */
void SettingsSET42_ResetCompleted__Init( SettingsSET42_ResetCompleted _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET42_ResetCompleted );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->MessageText, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ReceivedSystemEventHandler, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->HoldTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET42_ResetCompleted );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->MessageText, _Const0014 );
  ViewsText_OnSetEllipsis( &_this->MessageText, 1 );
  ViewsText_OnSetWrapText( &_this->MessageText, 1 );
  ViewsText_OnSetString( &_this->MessageText, EwLoadString( &StringsSET42_RESET_COMPLETE ));
  CoreTimer_OnSetPeriod( &_this->HoldTimer, 0 );
  CoreTimer_OnSetBegin( &_this->HoldTimer, 2000 );
  CoreTimer_OnSetEnabled( &_this->HoldTimer, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->MessageText ), 0 );
  ViewsText_OnSetFont( &_this->MessageText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->ReceivedSystemEventHandler.OnEvent = EwNewSlot( _this, SettingsSET42_ResetCompleted_OnSystemEventReceived );
  CoreSystemEventHandler_OnSetEvent( &_this->ReceivedSystemEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->SystemDataReceivedSystemEvent );
  _this->HoldTimer.OnTrigger = EwNewSlot( _this, SettingsSET42_ResetCompleted_OnHoldTimerFinishedSlot );

  /* Call the user defined constructor */
  SettingsSET42_ResetCompleted_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET42_ResetCompleted' */
void SettingsSET42_ResetCompleted__ReInit( SettingsSET42_ResetCompleted _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->MessageText );
  CoreSystemEventHandler__ReInit( &_this->ReceivedSystemEventHandler );
  CoreTimer__ReInit( &_this->HoldTimer );
}

/* Finalizer method for the class 'Settings::SET42_ResetCompleted' */
void SettingsSET42_ResetCompleted__Done( SettingsSET42_ResetCompleted _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->MessageText );
  CoreSystemEventHandler__Done( &_this->ReceivedSystemEventHandler );
  CoreTimer__Done( &_this->HoldTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET42_ResetCompleted_Init( SettingsSET42_ResetCompleted _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0041 ));
  DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeREBOOT_REQUEST, 0 );
}

/* 'C' function for method : 'Settings::SET42_ResetCompleted.OnShortHomeKeyActivated()' */
void SettingsSET42_ResetCompleted_OnShortHomeKeyActivated( SettingsSET42_ResetCompleted _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* 'C' function for method : 'Settings::SET42_ResetCompleted.OnLongHomeKeyActivated()' */
void SettingsSET42_ResetCompleted_OnLongHomeKeyActivated( SettingsSET42_ResetCompleted _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SettingsSET42_ResetCompleted_OnSystemEventReceived( SettingsSET42_ResetCompleted _this, 
  XObject sender )
{
  DeviceInterfaceSystemData SystemData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  SystemData = EwCastObject( _this->ReceivedSystemEventHandler.Context, DeviceInterfaceSystemData );

  if ( SystemData != 0 )
    switch ( SystemData->RxEvent )
    {
      case EnumSystemRxEventREBOOT_ACCEPTED :
      case EnumSystemRxEventREBOOT_REJECTED :
        if ( _this->IsHoldTimerFinished )
          DeviceInterfaceSystemDeviceClass_RebootSystem( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
          DeviceInterfaceSystemDeviceClass ));
        else
          _this->IsRebootResponseReceived = 1;
      break;

      default :; 
    }
}

/* 'C' function for method : 'Settings::SET42_ResetCompleted.OnHoldTimerFinishedSlot()' */
void SettingsSET42_ResetCompleted_OnHoldTimerFinishedSlot( SettingsSET42_ResetCompleted _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->IsRebootResponseReceived )
    DeviceInterfaceSystemDeviceClass_RebootSystem( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
    DeviceInterfaceSystemDeviceClass ));
  else
    _this->IsHoldTimerFinished = 1;
}

/* Variants derived from the class : 'Settings::SET42_ResetCompleted' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET42_ResetCompleted )
EW_END_OF_CLASS_VARIANTS( SettingsSET42_ResetCompleted )

/* Virtual Method Table (VMT) for the class : 'Settings::SET42_ResetCompleted' */
EW_DEFINE_CLASS( SettingsSET42_ResetCompleted, ComponentsBaseMainBG, MessageText, 
                 MessageText, MessageText, MessageText, IsRebootResponseReceived, 
                 IsRebootResponseReceived, "Settings::SET42_ResetCompleted" )
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
  SettingsSET42_ResetCompleted_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  SettingsSET42_ResetCompleted_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SettingsSET42_ResetCompleted )

/* Initializer for the class 'Settings::SET45_TripMileageReset' */
void SettingsSET45_TripMileageReset__Init( SettingsSET45_TripMileageReset _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET45_TripMileageReset );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET45_TripMileageReset );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 74 );
  _this->AllSettings[ 0 ] = EnumMeterInfoTRIP1;
  _this->AllSettings[ 1 ] = EnumMeterInfoTRIP2;
  _this->AllSettings[ 2 ] = EnumMeterInfoTRIP_F;
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, SettingsSET45_TripMileageReset_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );

  /* Call the user defined constructor */
  SettingsSET45_TripMileageReset_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET45_TripMileageReset' */
void SettingsSET45_TripMileageReset__ReInit( SettingsSET45_TripMileageReset _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'Settings::SET45_TripMileageReset' */
void SettingsSET45_TripMileageReset__Done( SettingsSET45_TripMileageReset _this )
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
void SettingsSET45_TripMileageReset_Init( SettingsSET45_TripMileageReset _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0042 ));
  SettingsSET45_TripMileageReset_SetNoOfMenuItems( _this );
  SettingsSET45_TripMileageReset_GetMileageSetting( _this );
}

/* 'C' function for method : 'Settings::SET45_TripMileageReset.LoadItemClass()' */
XClass SettingsSET45_TripMileageReset_LoadItemClass( SettingsSET45_TripMileageReset _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemValueUnit );
}

/* 'C' function for method : 'Settings::SET45_TripMileageReset.LoadItemTitle()' */
XString SettingsSET45_TripMileageReset_LoadItemTitle( SettingsSET45_TripMileageReset _this, 
  XInt32 aItemNo )
{
  XString Title = 0;

  switch ( _this->SupportedSetting[ EwCheckIndex( aItemNo, 3 )])
  {
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

/* 'C' function for method : 'Settings::SET45_TripMileageReset.OnItemActivate()' */
void SettingsSET45_TripMileageReset_OnItemActivate( SettingsSET45_TripMileageReset _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  PopPOP04_Reset ResetDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  ResetDialog = EwNewObject( PopPOP04_Reset, 0 );
  ResetDialog->SelectedMeterInfo = _this->SupportedSetting[ EwCheckIndex( aItemNo, 
  3 )];
  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)ResetDialog ), 0, 0, 0, 
  0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Settings::SET45_TripMileageReset.LoadItemEnabled()' */
XBool SettingsSET45_TripMileageReset_LoadItemEnabled( SettingsSET45_TripMileageReset _this, 
  XInt32 aItemNo )
{
  XBool ItemEnabled = 1;

  if ( EnumMeterInfoTRIP_F == _this->SupportedSetting[ EwCheckIndex( aItemNo, 3 )])
  {
    DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
      EnumVehicleRxTypeLOW_FUEL_WARNING );

    if ( VehicleData->Valid && ( 0 == !!VehicleData->DataUInt32 ))
      ItemEnabled = 0;
  }

  return ItemEnabled;
}

/* 'C' function for method : 'Settings::SET45_TripMileageReset.LoadItemUnit()' */
XString SettingsSET45_TripMileageReset_LoadItemUnit( SettingsSET45_TripMileageReset _this, 
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

/* 'C' function for method : 'Settings::SET45_TripMileageReset.LoadItemValue()' */
XString SettingsSET45_TripMileageReset_LoadItemValue( SettingsSET45_TripMileageReset _this, 
  XInt32 aItemNo )
{
  XString Value;
  DeviceInterfaceVehicleDataClass VehicleData = 0;

  switch ( _this->SupportedSetting[ EwCheckIndex( aItemNo, 3 )])
  {
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

    switch ( _this->SupportedSetting[ EwCheckIndex( aItemNo, 3 )])
    {
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

    Value = EwNewStringFloat( VehicleData->DataFloat, 0, 1 );
  }
  else
    Value = EwLoadString( &StringsGEN_THREE_HYPHENS );

  return Value;
}

/* 'C' function for method : 'Settings::SET45_TripMileageReset.GetMileageSetting()' */
void SettingsSET45_TripMileageReset_GetMileageSetting( SettingsSET45_TripMileageReset _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeMILEAGE_UNIT );

  if ( 1 == VehicleData->DataUInt32 )
    _this->MileageSetting = EnumMileageSettingItemMILE;
  else
    _this->MileageSetting = EnumMileageSettingItemKM;
}

/* 'C' function for method : 'Settings::SET45_TripMileageReset.SetNoOfMenuItems()' */
void SettingsSET45_TripMileageReset_SetNoOfMenuItems( SettingsSET45_TripMileageReset _this )
{
  XInt32 i;
  XInt32 NoOfItems = 0;
  XEnum SettingItem;

  for ( i = 0; i < 3; i++ )
  {
    SettingItem = _this->AllSettings[ EwCheckIndex( i, 3 )];

    switch ( SettingItem )
    {
      case EnumMeterInfoTRIP1 :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionTRIP1 ))
        {
          _this->SupportedSetting[ EwCheckIndex( NoOfItems, 3 )] = SettingItem;
          NoOfItems++;
        }
      break;

      case EnumMeterInfoTRIP2 :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionTRIP2 ))
        {
          _this->SupportedSetting[ EwCheckIndex( NoOfItems, 3 )] = SettingItem;
          NoOfItems++;
        }
      break;

      case EnumMeterInfoTRIP_F :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionF_TRIP ))
        {
          _this->SupportedSetting[ EwCheckIndex( NoOfItems, 3 )] = SettingItem;
          NoOfItems++;
        }
      break;

      default : 
      {
        _this->SupportedSetting[ EwCheckIndex( NoOfItems, 3 )] = SettingItem;
        NoOfItems++;
      }
    }
  }

  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, NoOfItems );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SettingsSET45_TripMileageReset_OnVehicleDataReceivedSlot( SettingsSET45_TripMileageReset _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if ( VehicleData != 0 )
    switch ( VehicleData->RxType )
    {
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

/* Variants derived from the class : 'Settings::SET45_TripMileageReset' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET45_TripMileageReset )
EW_END_OF_CLASS_VARIANTS( SettingsSET45_TripMileageReset )

/* Virtual Method Table (VMT) for the class : 'Settings::SET45_TripMileageReset' */
EW_DEFINE_CLASS( SettingsSET45_TripMileageReset, MenuBaseMenuView, VehicleDataReceivedEventHandler, 
                 VehicleDataReceivedEventHandler, VehicleDataReceivedEventHandler, 
                 VehicleDataReceivedEventHandler, AllSettings, AllSettings, "Settings::SET45_TripMileageReset" )
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
  SettingsSET45_TripMileageReset_LoadItemClass,
  SettingsSET45_TripMileageReset_LoadItemTitle,
  SettingsSET45_TripMileageReset_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  SettingsSET45_TripMileageReset_LoadItemEnabled,
  MenuBaseMenuView_LoadItemBaseValue,
  MenuBaseMenuView_LoadItemMessage,
  MenuBaseMenuView_LoadItemReceivedTime,
  MenuBaseMenuView_LoadItemCategory,
  MenuBaseMenuView_LoadItemUid,
  MenuBaseMenuView_LoadItemToggle,
  SettingsSET45_TripMileageReset_LoadItemUnit,
  SettingsSET45_TripMileageReset_LoadItemValue,
  MenuBaseMenuView_OnItemLongEnterKeyActivate,
  MenuBaseMenuView_LoadItemHour,
  MenuBaseMenuView_LoadItemMinute,
EW_END_OF_CLASS( SettingsSET45_TripMileageReset )

/* Initializer for the class 'Settings::SET46_VehicleInfoReset' */
void SettingsSET46_VehicleInfoReset__Init( SettingsSET46_VehicleInfoReset _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET46_VehicleInfoReset );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET46_VehicleInfoReset );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 74 );
  MenuVerticalMenu_OnSetArrowScrollBarVisible( &_this->Super1.Menu, 1 );
  _this->AllSettings[ 0 ] = EnumMeterInfoAVG_SPEED;
  _this->AllSettings[ 1 ] = EnumMeterInfoAVG_FUEL;
  _this->AllSettings[ 2 ] = EnumMeterInfoTRIP_TIME;
  _this->AllSettings[ 3 ] = EnumMeterInfoFUEL_CONSUMPTION;
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, SettingsSET46_VehicleInfoReset_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );

  /* Call the user defined constructor */
  SettingsSET46_VehicleInfoReset_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET46_VehicleInfoReset' */
void SettingsSET46_VehicleInfoReset__ReInit( SettingsSET46_VehicleInfoReset _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'Settings::SET46_VehicleInfoReset' */
void SettingsSET46_VehicleInfoReset__Done( SettingsSET46_VehicleInfoReset _this )
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
void SettingsSET46_VehicleInfoReset_Init( SettingsSET46_VehicleInfoReset _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0043 ));
  SettingsSET46_VehicleInfoReset_SetNoOfMenuItems( _this );
  SettingsSET46_VehicleInfoReset_GetUnitSetting( _this );
}

/* 'C' function for method : 'Settings::SET46_VehicleInfoReset.LoadItemClass()' */
XClass SettingsSET46_VehicleInfoReset_LoadItemClass( SettingsSET46_VehicleInfoReset _this, 
  XInt32 aItemNo )
{
  XClass ItemClass = EW_CLASS( MenuItemValueUnit2 );

  if ( EnumMeterInfoTRIP_TIME == _this->SupportedSetting[ EwCheckIndex( aItemNo, 
      4 )])
    ItemClass = EW_CLASS( MenuItemTimeHourMinute );

  return ItemClass;
}

/* 'C' function for method : 'Settings::SET46_VehicleInfoReset.LoadItemTitle()' */
XString SettingsSET46_VehicleInfoReset_LoadItemTitle( SettingsSET46_VehicleInfoReset _this, 
  XInt32 aItemNo )
{
  XString Title = 0;

  switch ( _this->SupportedSetting[ EwCheckIndex( aItemNo, 4 )])
  {
    case EnumMeterInfoAVG_FUEL :
      Title = EwLoadString( &StringsHOM03_AVG_FUEL );
    break;

    case EnumMeterInfoAVG_SPEED :
      Title = EwLoadString( &StringsHOM03_AVG_SPEED );
    break;

    case EnumMeterInfoTRIP_TIME :
      Title = EwLoadString( &StringsHOM03_TRIP_TIME );
    break;

    case EnumMeterInfoFUEL_CONSUMPTION :
      Title = EwLoadString( &StringsHOM03_FUEL_CONSUMPTION );
    break;

    default :; 
  }

  return Title;
}

/* 'C' function for method : 'Settings::SET46_VehicleInfoReset.OnItemActivate()' */
void SettingsSET46_VehicleInfoReset_OnItemActivate( SettingsSET46_VehicleInfoReset _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  PopPOP04_Reset ResetDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  ResetDialog = EwNewObject( PopPOP04_Reset, 0 );
  ResetDialog->SelectedMeterInfo = _this->SupportedSetting[ EwCheckIndex( aItemNo, 
  4 )];
  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)ResetDialog ), 0, 0, 0, 
  0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Settings::SET46_VehicleInfoReset.LoadItemUnit()' */
XString SettingsSET46_VehicleInfoReset_LoadItemUnit( SettingsSET46_VehicleInfoReset _this, 
  XInt32 aItemNo )
{
  XString UnitString = 0;

  switch ( _this->SupportedSetting[ EwCheckIndex( aItemNo, 4 )])
  {
    case EnumMeterInfoAVG_SPEED :
      if ( EnumMileageSettingItemMILE == _this->MileageUnit )
        UnitString = EwLoadString( &StringsGEN_SPEED_MILE_PER_HOUR );
      else
        UnitString = EwLoadString( &StringsGEN_SPEED_KM_PER_HOUR );
    break;

    case EnumMeterInfoAVG_FUEL :
      switch ( _this->FuelConsumptionUnit )
      {
        case EnumMeterFuelConsumptionUnitKM_PER_LITER :
          UnitString = EwLoadString( &StringsUNT03_UNIT_FUEL_KM_PER_LITER );
        break;

        case EnumMeterFuelConsumptionUnitMILE_PER_US_GAL :
        case EnumMeterFuelConsumptionUnitMILE_PER_IMPERIAL_GAL :
          UnitString = EwLoadString( &StringsUNT03_UNIT_FUEL_MILE_PER_GALLON );
        break;

        case EnumMeterFuelConsumptionUnitL_PER_100KM :
          UnitString = EwLoadString( &StringsUNT03_UNIT_FUEL_LITER_PER_HUNDRED_KM );
        break;

        default :; 
      }
    break;

    case EnumMeterInfoFUEL_CONSUMPTION :
      switch ( _this->FuelConsumptionUnit )
      {
        case EnumMeterFuelConsumptionUnitKM_PER_LITER :
        case EnumMeterFuelConsumptionUnitL_PER_100KM :
          UnitString = EwLoadString( &StringsGEN_FUEL_UNIT_LITTER );
        break;

        case EnumMeterFuelConsumptionUnitMILE_PER_US_GAL :
        case EnumMeterFuelConsumptionUnitMILE_PER_IMPERIAL_GAL :
          UnitString = EwLoadString( &StringsGEN_FUEL_UNIT_GALLON );
        break;

        default :; 
      }
    break;

    default :; 
  }

  return UnitString;
}

/* 'C' function for method : 'Settings::SET46_VehicleInfoReset.LoadItemValue()' */
XString SettingsSET46_VehicleInfoReset_LoadItemValue( SettingsSET46_VehicleInfoReset _this, 
  XInt32 aItemNo )
{
  XString ValueStr;

  switch ( _this->SupportedSetting[ EwCheckIndex( aItemNo, 4 )])
  {
    case EnumMeterInfoAVG_SPEED :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetAvgSpeedStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumMeterInfoAVG_FUEL :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetAvgFuelRateStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumMeterInfoFUEL_CONSUMPTION :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetFuelConStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    default : 
      ValueStr = EwLoadString( &StringsGEN_THREE_HYPHENS );
  }

  return ValueStr;
}

/* 'C' function for method : 'Settings::SET46_VehicleInfoReset.LoadItemHour()' */
XString SettingsSET46_VehicleInfoReset_LoadItemHour( SettingsSET46_VehicleInfoReset _this, 
  XInt32 aItemNo )
{
  XString HourString = EwLoadString( &StringsGEN_THREE_HYPHENS );

  if ( EnumMeterInfoTRIP_TIME == _this->SupportedSetting[ EwCheckIndex( aItemNo, 
      4 )])
    HourString = DeviceInterfaceVehicleDeviceClass_OnGetTripTimeHourStr( EwGetAutoObject( 
    &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));

  return HourString;
}

/* 'C' function for method : 'Settings::SET46_VehicleInfoReset.LoadItemMinute()' */
XString SettingsSET46_VehicleInfoReset_LoadItemMinute( SettingsSET46_VehicleInfoReset _this, 
  XInt32 aItemNo )
{
  XString MinuteString = EwLoadString( &StringsGEN_THREE_HYPHENS );

  if ( EnumMeterInfoTRIP_TIME == _this->SupportedSetting[ EwCheckIndex( aItemNo, 
      4 )])
    MinuteString = DeviceInterfaceVehicleDeviceClass_OnGetTripTimeMinuteStr( EwGetAutoObject( 
    &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));

  return MinuteString;
}

/* 'C' function for method : 'Settings::SET46_VehicleInfoReset.GetUnitSetting()' */
void SettingsSET46_VehicleInfoReset_GetUnitSetting( SettingsSET46_VehicleInfoReset _this )
{
  DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
    EnumVehicleRxTypeMILEAGE_UNIT );

  if ( 1 == VehicleData->DataUInt32 )
    _this->MileageUnit = EnumMileageSettingItemMILE;
  else
    _this->MileageUnit = EnumMileageSettingItemKM;

  VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT );

  if ( 4 > VehicleData->DataUInt32 )
    _this->FuelConsumptionUnit = (XEnum)VehicleData->DataUInt32;
}

/* 'C' function for method : 'Settings::SET46_VehicleInfoReset.SetNoOfMenuItems()' */
void SettingsSET46_VehicleInfoReset_SetNoOfMenuItems( SettingsSET46_VehicleInfoReset _this )
{
  XInt32 i;
  XInt32 NoOfItems = 0;
  XEnum SettingItem;

  for ( i = 0; i < 4; i++ )
  {
    SettingItem = _this->AllSettings[ EwCheckIndex( i, 4 )];

    switch ( SettingItem )
    {
      case EnumMeterInfoAVG_SPEED :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionAVG_SPEED ))
        {
          _this->SupportedSetting[ EwCheckIndex( NoOfItems, 4 )] = SettingItem;
          NoOfItems++;
        }
      break;

      case EnumMeterInfoAVG_FUEL :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionAVG_FUEL ))
        {
          _this->SupportedSetting[ EwCheckIndex( NoOfItems, 4 )] = SettingItem;
          NoOfItems++;
        }
      break;

      case EnumMeterInfoFUEL_CONSUMPTION :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionFUEL_CONSUMPTION ))
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

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SettingsSET46_VehicleInfoReset_OnVehicleDataReceivedSlot( SettingsSET46_VehicleInfoReset _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if ( VehicleData != 0 )
    switch ( VehicleData->RxType )
    {
      case EnumVehicleRxTypeAVERAGE_SPEED :
        SettingsSET46_VehicleInfoReset_ReloadItem( _this, EnumMeterInfoAVG_SPEED );
      break;

      case EnumVehicleRxTypeFUEL_RATE_AVERAGE :
        SettingsSET46_VehicleInfoReset_ReloadItem( _this, EnumMeterInfoAVG_FUEL );
      break;

      case EnumVehicleRxTypeTRIP_TIME :
        SettingsSET46_VehicleInfoReset_ReloadItem( _this, EnumMeterInfoTRIP_TIME );
      break;

      case EnumVehicleRxTypeFUEL_CONSUMPTION :
        SettingsSET46_VehicleInfoReset_ReloadItem( _this, EnumMeterInfoFUEL_CONSUMPTION );
      break;

      default :; 
    }
}

/* 'C' function for method : 'Settings::SET46_VehicleInfoReset.ReloadItem()' */
void SettingsSET46_VehicleInfoReset_ReloadItem( SettingsSET46_VehicleInfoReset _this, 
  XEnum aMeterInfo )
{
  XInt32 i;

  for ( i = 0; i < 4; i++ )
    if ( aMeterInfo == _this->SupportedSetting[ EwCheckIndex( i, 4 )])
    {
      MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, i, i );
      break;
    }
}

/* Variants derived from the class : 'Settings::SET46_VehicleInfoReset' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET46_VehicleInfoReset )
EW_END_OF_CLASS_VARIANTS( SettingsSET46_VehicleInfoReset )

/* Virtual Method Table (VMT) for the class : 'Settings::SET46_VehicleInfoReset' */
EW_DEFINE_CLASS( SettingsSET46_VehicleInfoReset, MenuBaseMenuView, VehicleDataReceivedEventHandler, 
                 VehicleDataReceivedEventHandler, VehicleDataReceivedEventHandler, 
                 VehicleDataReceivedEventHandler, FuelConsumptionUnit, FuelConsumptionUnit, 
                 "Settings::SET46_VehicleInfoReset" )
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
  SettingsSET46_VehicleInfoReset_LoadItemClass,
  SettingsSET46_VehicleInfoReset_LoadItemTitle,
  SettingsSET46_VehicleInfoReset_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemBaseValue,
  MenuBaseMenuView_LoadItemMessage,
  MenuBaseMenuView_LoadItemReceivedTime,
  MenuBaseMenuView_LoadItemCategory,
  MenuBaseMenuView_LoadItemUid,
  MenuBaseMenuView_LoadItemToggle,
  SettingsSET46_VehicleInfoReset_LoadItemUnit,
  SettingsSET46_VehicleInfoReset_LoadItemValue,
  MenuBaseMenuView_OnItemLongEnterKeyActivate,
  SettingsSET46_VehicleInfoReset_LoadItemHour,
  SettingsSET46_VehicleInfoReset_LoadItemMinute,
EW_END_OF_CLASS( SettingsSET46_VehicleInfoReset )

/* Initializer for the class 'Settings::SET27_ConfirmUpdate' */
void SettingsSET27_ConfirmUpdate__Init( SettingsSET27_ConfirmUpdate _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( SettingsSET27_ConfirmUpdate );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Text, &_this->_.XObject, 0 );
  MenuUpDownPushButtonSet__Init( &_this->UpDownPushButtonSet, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ReceivedSystemEventHandler, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->HoldTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( SettingsSET27_ConfirmUpdate );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0002 );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &StringsSET27_UPDATE_SYSTEM ));
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const0003 );
  _this->UpDownPushButtonSet.Super1.PassHomeKey = 1;
  _this->UpDownPushButtonSet.Super1.PassMagicKey = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->UpDownPushButtonSet, 1 );
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwGetVariantOfString( 
  &StringsGEN_CANCEL ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwGetVariantOfString( 
  &StringsGEN_OK ));
  MenuUpDownPushButtonSet_OnSetDownButtonEnabled( &_this->UpDownPushButtonSet, 1 );
  CoreTimer_OnSetPeriod( &_this->HoldTimer, 0 );
  CoreTimer_OnSetBegin( &_this->HoldTimer, 2000 );
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UpDownPushButtonSet ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->UpDownPushButtonSet.OnUpButtonActivated = EwNewSlot( _this, SettingsSET27_ConfirmUpdate_OnCancelActivatedSlot );
  _this->UpDownPushButtonSet.OnDownButtonActivated = EwNewSlot( _this, SettingsSET27_ConfirmUpdate_OnOkActivatedSlot );
  _this->ReceivedSystemEventHandler.OnEvent = EwNewSlot( _this, SettingsSET27_ConfirmUpdate_OnSystemEventReceived );
  CoreSystemEventHandler_OnSetEvent( &_this->ReceivedSystemEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->SystemDataReceivedSystemEvent );
  _this->HoldTimer.OnTrigger = EwNewSlot( _this, SettingsSET27_ConfirmUpdate_OnHoldTimerSlot );

  /* Call the user defined constructor */
  SettingsSET27_ConfirmUpdate_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET27_ConfirmUpdate' */
void SettingsSET27_ConfirmUpdate__ReInit( SettingsSET27_ConfirmUpdate _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Text );
  MenuUpDownPushButtonSet__ReInit( &_this->UpDownPushButtonSet );
  CoreSystemEventHandler__ReInit( &_this->ReceivedSystemEventHandler );
  CoreTimer__ReInit( &_this->HoldTimer );
}

/* Finalizer method for the class 'Settings::SET27_ConfirmUpdate' */
void SettingsSET27_ConfirmUpdate__Done( SettingsSET27_ConfirmUpdate _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Text );
  MenuUpDownPushButtonSet__Done( &_this->UpDownPushButtonSet );
  CoreSystemEventHandler__Done( &_this->ReceivedSystemEventHandler );
  CoreTimer__Done( &_this->HoldTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET27_ConfirmUpdate_Init( SettingsSET27_ConfirmUpdate _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0044 ));
  DeviceInterfaceSystemDeviceClass_SaveLastStatus( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ));
}

/* 'C' function for method : 'Settings::SET27_ConfirmUpdate.OnOkActivatedSlot()' */
void SettingsSET27_ConfirmUpdate_OnOkActivatedSlot( SettingsSET27_ConfirmUpdate _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( sender );

  DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeREQUEST_REPROGRAM, 0 );
}

/* 'C' function for method : 'Settings::SET27_ConfirmUpdate.OnCancelActivatedSlot()' */
void SettingsSET27_ConfirmUpdate_OnCancelActivatedSlot( SettingsSET27_ConfirmUpdate _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SettingsSET27_ConfirmUpdate_OnSystemEventReceived( SettingsSET27_ConfirmUpdate _this, 
  XObject sender )
{
  DeviceInterfaceSystemData SystemData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  SystemData = EwCastObject( _this->ReceivedSystemEventHandler.Context, DeviceInterfaceSystemData );

  if ( SystemData != 0 )
    switch ( SystemData->RxEvent )
    {
      case EnumSystemRxEventREPROGRAM_ACCEPTED :
      {
        CoreTimer_OnSetEnabled( &_this->HoldTimer, 1 );
        DeviceInterfaceBluetoothDeviceClass_SendMotoConCommand( EwGetAutoObject( 
        &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 
        EnumMotoConTxCREATE_OTA_CONNECTION );
      }
      break;

      case EnumSystemRxEventREPROGRAM_REJECTED :
      {
        SettingsTimeoutDialog Dialog = EwNewObject( SettingsTimeoutDialog, 0 );
        SettingsTimeoutDialog_OnSetMessage( Dialog, EwLoadString( &StringsSET29_DRIVING_NO_SW_UPDATE ));
        Dialog->DismissAfterTimeout = 1;
        CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)Dialog ), 0, 
        0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
      break;

      default :; 
    }
}

/* 'C' function for method : 'Settings::SET27_ConfirmUpdate.OnHoldTimerSlot()' */
void SettingsSET27_ConfirmUpdate_OnHoldTimerSlot( SettingsSET27_ConfirmUpdate _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( sender );

  DeviceInterfaceSystemDeviceClass_StartOTA( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ));
}

/* Variants derived from the class : 'Settings::SET27_ConfirmUpdate' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET27_ConfirmUpdate )
EW_END_OF_CLASS_VARIANTS( SettingsSET27_ConfirmUpdate )

/* Virtual Method Table (VMT) for the class : 'Settings::SET27_ConfirmUpdate' */
EW_DEFINE_CLASS( SettingsSET27_ConfirmUpdate, ComponentsBaseMainBG, Text, Text, 
                 Text, Text, _.VMT, _.VMT, "Settings::SET27_ConfirmUpdate" )
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
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( SettingsSET27_ConfirmUpdate )

/* Embedded Wizard */
