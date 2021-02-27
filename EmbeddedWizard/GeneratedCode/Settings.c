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
#include "_BrightnessBRT01_BrightnessSettingMenu.h"
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
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_MenuBaseMenuView.h"
#include "_MenuItemBase.h"
#include "_MenuItemCheckMark.h"
#include "_MenuItemCheckbox.h"
#include "_MenuPushButton.h"
#include "_MenuUpDownPushButtonSet.h"
#include "_MenuVerticalMenu.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesExternBitmap.h"
#include "_ResourcesFont.h"
#include "_SettingsBtFwUpdateDialog.h"
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
#include "_SettingsSET28_SystemInfo.h"
#include "_SettingsSET30_QRCode.h"
#include "_SettingsSET9_10_11_BtConnectionResult.h"
#include "_SettingsTimeoutDialog.h"
#include "_UnitUNT01_UnitSettingMenu.h"
#include "_ViewsBorder.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "_WidgetSetToggleButton.h"
#include "Core.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Fonts.h"
#include "Resource.h"
#include "Settings.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000410, /* ratio 53.46 % */
  0xB8001B00, 0x00092452, 0x00D20037, 0x040003A0, 0x8A002980, 0x0002A000, 0x00198006,
  0x58181E32, 0x8A8EA304, 0xE0223320, 0x184004E8, 0x94006D00, 0x6331F001, 0x4C438E02,
  0x4630041E, 0x19360025, 0xA8240801, 0x8642A110, 0xA44A210E, 0x4E46D168, 0x662D1C02,
  0x25B04A44, 0xA11C0C00, 0xE0039000, 0x739B4D0D, 0xC8856400, 0x004F6A90, 0xB8B80067,
  0x58611369, 0xE61A6886, 0xEB91C10C, 0xC33384D4, 0x31F8FD66, 0x00290008, 0x02A8008E,
  0x004449A0, 0x797E2925, 0x58AEF138, 0x2ECD2BB2, 0xA3F69004, 0x380F8CC3, 0x0769B112,
  0x2595CD6E, 0xE95CA64F, 0x8E04E738, 0xCD66577E, 0xCAEC327A, 0xC6BD6EB1, 0xA336A965,
  0xB0598E01, 0xB2402CE6, 0x059DCE6A, 0x2B54FE67, 0x1AC5B0B4, 0xF41A39B7, 0x5FE838B9,
  0x1C7000A2, 0xE720A8E5, 0x41C7B682, 0xD088772A, 0xD006466A, 0x9B574A87, 0xE6C67647,
  0x755A4B04, 0xC3264648, 0x0F711993, 0xB0940B87, 0x6E0018F6, 0xB0497CE4, 0xF2F84537,
  0xC0A0031F, 0xBC4CC9F1, 0x96F1992B, 0xC0018C68, 0x31595C04, 0x564E1104, 0x709E9431,
  0x5EE715BA, 0x10E5F061, 0xEDEB411C, 0xC97BDC66, 0x470274E5, 0x4001C17C, 0xF4312779,
  0x090E5855, 0x02439851, 0x4A55442A, 0xD544C877, 0x25A82C4A, 0x9D2B4E22, 0x0E4AD594,
  0x6ED278C5, 0x93990563, 0x20022007, 0xF18B8922, 0x148A8008, 0x8BD708B1, 0xA038F800,
  0x9559355A, 0x31368DD2, 0x1A4652B4, 0x79A47914, 0x22B8A536, 0x05BE2D00, 0x92618CA3,
  0x38429329, 0x47012465, 0x55A8E658, 0x38CE229A, 0xD50E5667, 0xFC4E6461, 0x4CA71411,
  0xE538DA3B, 0x67956A68, 0xB9088C55, 0x861451C4, 0x795564C5, 0x5F40025B, 0xA5490E11,
  0xB5361E10, 0x45780009, 0x7957015C, 0xDFA6B168, 0x5439046B, 0xF5194A53, 0x78A30459,
  0x88E8E439, 0x93395669, 0xD6B2B396, 0x461883DC, 0x007D9ED8, 0x85EBD0C8, 0x6BB711B9,
  0x90D2BE74, 0x0A100393, 0x00B11BCB, 0x4E5FA700, 0x00040400, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XStringRes _Const0000 = { _StringsDefault0, 0x0002 };
static const XRect _Const0001 = {{ 10, 46 }, { 470, 108 }};
static const XRect _Const0002 = {{ 10, 170 }, { 470, 201 }};
static const XStringRes _Const0003 = { _StringsDefault0, 0x000F };
static const XRect _Const0004 = {{ 10, 108 }, { 470, 170 }};
static const XStringRes _Const0005 = { _StringsDefault0, 0x0016 };
static const XRect _Const0006 = {{ 165, 219 }, { 315, 259 }};
static const XStringRes _Const0007 = { _StringsDefault0, 0x001E };
static const XStringRes _Const0008 = { _StringsDefault0, 0x0027 };
static const XStringRes _Const0009 = { _StringsDefault0, 0x0034 };
static const XStringRes _Const000A = { _StringsDefault0, 0x0038 };
static const XRect _Const000B = {{ 10, 50 }, { 470, 236 }};
static const XRect _Const000C = {{ 0, 36 }, { 480, 38 }};
static const XStringRes _Const000D = { _StringsDefault0, 0x003C };
static const XStringRes _Const000E = { _StringsDefault0, 0x0054 };
static const XStringRes _Const000F = { _StringsDefault0, 0x0075 };
static const XStringRes _Const0010 = { _StringsDefault0, 0x0084 };
static const XRect _Const0011 = {{ 10, 45 }, { 470, 169 }};
static const XRect _Const0012 = {{ 165, 176 }, { 315, 259 }};
static const XStringRes _Const0013 = { _StringsDefault0, 0x0097 };
static const XStringRes _Const0014 = { _StringsDefault0, 0x009D };
static const XStringRes _Const0015 = { _StringsDefault0, 0x00A2 };
static const XRect _Const0016 = {{ 10, 45 }, { 470, 107 }};
static const XRect _Const0017 = {{ 10, 107 }, { 470, 169 }};
static const XStringRes _Const0018 = { _StringsDefault0, 0x00AF };
static const XStringRes _Const0019 = { _StringsDefault0, 0x00BC };
static const XStringRes _Const001A = { _StringsDefault0, 0x00C0 };
static const XStringRes _Const001B = { _StringsDefault0, 0x00CB };
static const XStringRes _Const001C = { _StringsDefault0, 0x00D7 };
static const XStringRes _Const001D = { _StringsDefault0, 0x00E1 };
static const XStringRes _Const001E = { _StringsDefault0, 0x00EE };
static const XStringRes _Const001F = { _StringsDefault0, 0x00F7 };
static const XStringRes _Const0020 = { _StringsDefault0, 0x010B };
static const XStringRes _Const0021 = { _StringsDefault0, 0x0118 };
static const XRect _Const0022 = {{ 0, 0 }, { 480, 272 }};
static const XColor _Const0023 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0024 = {{ 80, 60 }, { 380, 210 }};
static const XStringRes _Const0025 = { _StringsDefault0, 0x0125 };
static const XColor _Const0026 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XStringRes _Const0027 = { _StringsDefault0, 0x014C };
static const XStringRes _Const0028 = { _StringsDefault0, 0x016A };
static const XRect _Const0029 = {{ 20, 98 }, { 207, 227 }};
static const XRect _Const002A = {{ 210, 85 }, { 398, 135 }};
static const XRect _Const002B = {{ 210, 192 }, { 442, 240 }};
static const XRect _Const002C = {{ 210, 137 }, { 463, 192 }};
static const XStringRes _Const002D = { _StringsDefault0, 0x0184 };
static const XStringRes _Const002E = { _StringsDefault0, 0x0196 };
static const XStringRes _Const002F = { _StringsDefault0, 0x01AA };
static const XStringRes _Const0030 = { _StringsDefault0, 0x01B3 };
static const XStringRes _Const0031 = { _StringsDefault0, 0x01BC };
static const XStringRes _Const0032 = { _StringsDefault0, 0x01C6 };
static const XStringRes _Const0033 = { _StringsDefault0, 0x01CC };
static const XRect _Const0034 = {{ 10, 132 }, { 470, 163 }};
static const XRect _Const0035 = {{ 10, 194 }, { 470, 256 }};
static const XRect _Const0036 = {{ 10, 163 }, { 470, 194 }};
static const XRect _Const0037 = {{ 193, 36 }, { 287, 130 }};
static const XStringRes _Const0038 = { _StringsDefault0, 0x01E0 };
static const XRect _Const0039 = {{ 10, 46 }, { 470, 201 }};
static const XStringRes _Const003A = { _StringsDefault0, 0x01ED };
static const XStringRes _Const003B = { _StringsDefault0, 0x01FA };
static const XRect _Const003C = {{ 10, 46 }, { 470, 77 }};
static const XRect _Const003D = {{ 10, 108 }, { 470, 139 }};
static const XRect _Const003E = {{ 10, 77 }, { 470, 108 }};
static const XRect _Const003F = {{ 10, 139 }, { 470, 170 }};
static const XRect _Const0040 = {{ 95, 176 }, { 385, 259 }};

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

/* Initializer for the class 'Settings::SET01_MainSettingMenu' */
void SettingsSET01_MainSettingMenu__Init( SettingsSET01_MainSettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET01_MainSettingMenu );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET01_MainSettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 9 );
  MenuVerticalMenu_OnSetArrowScrollBarVisible( &_this->Super1.Menu, 1 );
  _this->Settings[ 0 ] = EnumMainSettingItemConnection;
  _this->Settings[ 1 ] = EnumMainSettingItemClock;
  _this->Settings[ 2 ] = EnumMainSettingItemBrightness;
  _this->Settings[ 3 ] = EnumMainSettingItemUnit;
  _this->Settings[ 4 ] = EnumMainSettingItemGripWarmerSettings;
  _this->Settings[ 5 ] = EnumMainSettingItemSeatHeaterSettings;
  _this->Settings[ 6 ] = EnumMainSettingItemSystemInfo;
  _this->Settings[ 7 ] = EnumMainSettingItemLegalInfo;
  _this->Settings[ 8 ] = EnumMainSettingItemReset;

  /* Call the user defined constructor */
  SettingsSET01_MainSettingMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET01_MainSettingMenu' */
void SettingsSET01_MainSettingMenu__ReInit( SettingsSET01_MainSettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Settings::SET01_MainSettingMenu' */
void SettingsSET01_MainSettingMenu__Done( SettingsSET01_MainSettingMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET01_MainSettingMenu_Init( SettingsSET01_MainSettingMenu _this, XHandle 
  aArg )
{
  XInt32 NoOfItems;
  XInt32 ItemIdx;
  XInt32 i;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  NoOfItems = 7;
  ItemIdx = 4;
  i = 0;

  if ( _this->GripWarmerEnabled )
  {
    NoOfItems++;
    ItemIdx++;
  }

  if ( _this->SeatHeaterEnabled )
  {
    NoOfItems++;
    ItemIdx++;
  }

  if ( NoOfItems < 9 )
  {
    for ( i = 6; i <= 8; i++, ItemIdx++ )
    {
      _this->Settings[ EwCheckIndex( ItemIdx, 9 )] = _this->Settings[ EwCheckIndex( 
      i, 9 )];
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
  {
    ItemClass = EW_CLASS( MenuItemBase );
  }

  return ItemClass;
}

/* 'C' function for method : 'Settings::SET01_MainSettingMenu.LoadItemTitle()' */
XString SettingsSET01_MainSettingMenu_LoadItemTitle( SettingsSET01_MainSettingMenu _this, 
  XInt32 aItemNo )
{
  XString Title = 0;

  switch ( _this->Settings[ EwCheckIndex( aItemNo, 9 )])
  {
    case EnumMainSettingItemConnection :
      Title = EwLoadString( &StringsSET01_connection );
    break;

    case EnumMainSettingItemClock :
      Title = EwLoadString( &StringsSET01_clock );
    break;

    case EnumMainSettingItemBrightness :
      Title = EwLoadString( &StringsSET01_brightness );
    break;

    case EnumMainSettingItemUnit :
      Title = EwLoadString( &StringsSET01_unit );
    break;

    case EnumMainSettingItemGripWarmerSettings :
      Title = EwLoadString( &StringsSET01_grip_warmer_settings );
    break;

    case EnumMainSettingItemSeatHeaterSettings :
      Title = EwLoadString( &StringsSET01_seat_heater_settings );
    break;

    case EnumMainSettingItemSystemInfo :
      Title = EwLoadString( &StringsSET01_system_info );
    break;

    case EnumMainSettingItemLegalInfo :
      Title = EwLoadString( &StringsSET01_legal_info );
    break;

    case EnumMainSettingItemReset :
      Title = EwLoadString( &StringsSET01_reset );
    break;

    default : 
      ;
  }

  return Title;
}

/* 'C' function for method : 'Settings::SET01_MainSettingMenu.OnItemActivate()' */
void SettingsSET01_MainSettingMenu_OnItemActivate( SettingsSET01_MainSettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  ComponentsBaseComponent Dialog;

  if ( aMenuItem == 0 )
    ;

  Dialog = 0;

  switch ( _this->Settings[ EwCheckIndex( aItemNo, 9 )])
  {
    case EnumMainSettingItemConnection :
    {
      if ( !EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->IsHopperTestMode )
      {
        Dialog = ((ComponentsBaseComponent)EwNewObject( SettingsSET03_ConnectionSettingMenu, 
        0 ));
      }
    }
    break;

    case EnumMainSettingItemClock :
      ;
    break;

    case EnumMainSettingItemBrightness :
      Dialog = ((ComponentsBaseComponent)EwNewObject( BrightnessBRT01_BrightnessSettingMenu, 
      0 ));
    break;

    case EnumMainSettingItemUnit :
      Dialog = ((ComponentsBaseComponent)EwNewObject( UnitUNT01_UnitSettingMenu, 
      0 ));
    break;

    case EnumMainSettingItemGripWarmerSettings :
      ;
    break;

    case EnumMainSettingItemSeatHeaterSettings :
      ;
    break;

    case EnumMainSettingItemSystemInfo :
      Dialog = ((ComponentsBaseComponent)EwNewObject( SettingsSET28_SystemInfo, 
      0 ));
    break;

    case EnumMainSettingItemLegalInfo :
      ;
    break;

    case EnumMainSettingItemReset :
      ;
    break;

    default : 
      ;
  }

  if ( Dialog != 0 )
  {
    MenuBaseMenuView MenuDialog = EwCastObject( Dialog, MenuBaseMenuView );

    if ( MenuDialog != 0 )
    {
      ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)MenuDialog ));
    }
    else
    {
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)Dialog ), 0, 0, 0, 0, 
      0, 0, EwNullSlot, EwNullSlot, 0 );
    }
  }
}

/* Variants derived from the class : 'Settings::SET01_MainSettingMenu' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET01_MainSettingMenu )
EW_END_OF_CLASS_VARIANTS( SettingsSET01_MainSettingMenu )

/* Virtual Method Table (VMT) for the class : 'Settings::SET01_MainSettingMenu' */
EW_DEFINE_CLASS( SettingsSET01_MainSettingMenu, MenuBaseMenuView, _None, _None, 
                 _None, _None, _None, _None, "Settings::SET01_MainSettingMenu" )
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  SettingsSET01_MainSettingMenu_LoadItemClass,
  SettingsSET01_MainSettingMenu_LoadItemTitle,
  SettingsSET01_MainSettingMenu_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemUnitValue,
EW_END_OF_CLASS( SettingsSET01_MainSettingMenu )

/* Initializer for the class 'Settings::SET03_ConnectionSettingMenu' */
void SettingsSET03_ConnectionSettingMenu__Init( SettingsSET03_ConnectionSettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET03_ConnectionSettingMenu );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET03_ConnectionSettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 2 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsGEN_bluetooth ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsSET03_Y_CONNECT_APP_PAIRING ));

  /* Call the user defined constructor */
  SettingsSET03_ConnectionSettingMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET03_ConnectionSettingMenu' */
void SettingsSET03_ConnectionSettingMenu__ReInit( SettingsSET03_ConnectionSettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Settings::SET03_ConnectionSettingMenu' */
void SettingsSET03_ConnectionSettingMenu__Done( SettingsSET03_ConnectionSettingMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
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

  if ( !!aItemNo )
    ;

  return EW_CLASS( MenuItemBase );
}

/* 'C' function for method : 'Settings::SET03_ConnectionSettingMenu.LoadItemTitle()' */
XString SettingsSET03_ConnectionSettingMenu_LoadItemTitle( SettingsSET03_ConnectionSettingMenu _this, 
  XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < 2 )
  {
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 2 )];
  }

  return title;
}

/* 'C' function for method : 'Settings::SET03_ConnectionSettingMenu.OnItemActivate()' */
void SettingsSET03_ConnectionSettingMenu_OnItemActivate( SettingsSET03_ConnectionSettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  if ( aMenuItem == 0 )
    ;

  switch ( aItemNo )
  {
    case 0 :
      ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)EwNewObject( 
      SettingsSET04_BtSettingMenu, 0 )));
    break;

    case 1 :
      SettingsSET03_ConnectionSettingMenu_HandleYConnectAppPairing( _this );
    break;

    default : 
      ;
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
    {
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsSET22_BleAdvertising, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
  }
  else
  {
    SettingsSET03_ConnectionSettingMenu_PresentDialogWithTimeout( _this, EwLoadString( 
    &StringsSET20_COMPLETE_BT_PAIRING_FIRST ));
  }
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
                 _None, "Settings::SET03_ConnectionSettingMenu" )
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  SettingsSET03_ConnectionSettingMenu_LoadItemClass,
  SettingsSET03_ConnectionSettingMenu_LoadItemTitle,
  SettingsSET03_ConnectionSettingMenu_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemUnitValue,
EW_END_OF_CLASS( SettingsSET03_ConnectionSettingMenu )

/* Initializer for the class 'Settings::SET04_BtSettingMenu' */
void SettingsSET04_BtSettingMenu__Init( SettingsSET04_BtSettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET04_BtSettingMenu );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET04_BtSettingMenu );

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
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsGEN_bluetooth ));
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
  MenuBaseMenuView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Settings::SET04_BtSettingMenu' */
void SettingsSET04_BtSettingMenu__Done( SettingsSET04_BtSettingMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
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
  {
    ClassType = _this->ItemClassArray[ EwCheckIndex( aItemNo, 4 )];
  }

  return ClassType;
}

/* 'C' function for method : 'Settings::SET04_BtSettingMenu.LoadItemTitle()' */
XString SettingsSET04_BtSettingMenu_LoadItemTitle( SettingsSET04_BtSettingMenu _this, 
  XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < 4 )
  {
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 4 )];
  }

  return title;
}

/* 'C' function for method : 'Settings::SET04_BtSettingMenu.OnItemActivate()' */
void SettingsSET04_BtSettingMenu_OnItemActivate( SettingsSET04_BtSettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  XBool IsChecked = 0;
  MenuItemCheckbox CheckBoxItem = EwCastObject( aMenuItem, MenuItemCheckbox );

  if ( CheckBoxItem != 0 )
  {
    IsChecked = CheckBoxItem->CheckBoxButton.Checked;
  }

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
    {
      if ( DeviceInterfaceBluetoothDeviceClass_OnGetIsMaxPairedDevice( EwGetAutoObject( 
          &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )))
      {
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsSET05_BtcMaxPairedDevice, 
        0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
      else
      {
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsSET06_BtcDiscovarable, 
        0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
    }
    break;

    case 2 :
      ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)EwNewObject( 
      SettingsSET17_BtcPairedDeviceList, 0 )));
    break;

    case 3 :
      DeviceInterfaceBluetoothDeviceClass_OnSetAutoConnect( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
      DeviceInterfaceBluetoothDeviceClass ), IsChecked );
    break;

    default : 
      ;
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

    default : 
      ;
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
  {
    ItemEnabled = EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->BluetoothEnable;
  }

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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  SettingsSET04_BtSettingMenu_LoadItemClass,
  SettingsSET04_BtSettingMenu_LoadItemTitle,
  SettingsSET04_BtSettingMenu_OnItemActivate,
  SettingsSET04_BtSettingMenu_LoadItemChecked,
  SettingsSET04_BtSettingMenu_LoadItemEnabled,
  MenuBaseMenuView_LoadItemUnitValue,
EW_END_OF_CLASS( SettingsSET04_BtSettingMenu )

/* Initializer for the class 'Settings::SET06_BtcDiscovarable' */
void SettingsSET06_BtcDiscovarable__Init( SettingsSET06_BtcDiscovarable _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET06_BtcDiscovarable );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->DiscoverableText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TimeLeftText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NameText, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->CountDownTimer, &_this->_XObject, 0 );
  MenuPushButton__Init( &_this->PushButton, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->BtcPairingStateChangeEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET06_BtcDiscovarable );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->DiscoverableText, _Const0001 );
  ViewsText_OnSetWrapText( &_this->DiscoverableText, 1 );
  ViewsText_OnSetAlignment( &_this->DiscoverableText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->DiscoverableText, EwLoadString( &StringsSET06_DISCOVERABLE ));
  CoreRectView__OnSetBounds( &_this->TimeLeftText, _Const0002 );
  ViewsText_OnSetWrapText( &_this->TimeLeftText, 1 );
  ViewsText_OnSetAlignment( &_this->TimeLeftText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TimeLeftText, EwConcatString( EwLoadString( &StringsSET06_TIME_LEFT ), 
  EwLoadString( &_Const0003 )));
  CoreRectView__OnSetBounds( &_this->NameText, _Const0004 );
  ViewsText_OnSetEllipsis( &_this->NameText, 1 );
  ViewsText_OnSetWrapText( &_this->NameText, 1 );
  ViewsText_OnSetAlignment( &_this->NameText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->NameText, EwLoadString( &_Const0005 ));
  CoreTimer_OnSetPeriod( &_this->CountDownTimer, 1000 );
  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 0 );
  _this->CountDownTimeSec = 180;
  CoreRectView__OnSetBounds( &_this->PushButton, _Const0006 );
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->PushButton, 1 );
  MenuPushButton_OnSetTitle( &_this->PushButton, EwLoadString( &_Const0007 ));
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
  ComponentsBaseMainBG__ReInit( &_this->_Super );

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
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->DiscoverableText );
  ViewsText__Done( &_this->TimeLeftText );
  ViewsText__Done( &_this->NameText );
  CoreTimer__Done( &_this->CountDownTimer );
  MenuPushButton__Done( &_this->PushButton );
  CoreSystemEventHandler__Done( &_this->BtcPairingStateChangeEventHandler );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET06_BtcDiscovarable_Init( SettingsSET06_BtcDiscovarable _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0008 ));
  DeviceInterfaceBluetoothDeviceClass_OnSetDiscoverable( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ), 1 );
  ViewsText_OnSetString( &_this->NameText, EwConcatString( _this->NameText.String, 
  DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceName( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ))));
  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 1 );
}

/* 'C' function for method : 'Settings::SET06_BtcDiscovarable.OnShortHomeKeyActivated()' */
void SettingsSET06_BtcDiscovarable_OnShortHomeKeyActivated( SettingsSET06_BtcDiscovarable _this )
{
  DeviceInterfaceBluetoothDeviceClass_OnSetDiscoverable( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ), 0 );
  ComponentsBaseMainBG_OnShortHomeKeyActivated((ComponentsBaseMainBG)_this );
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
  CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
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
    {
      SecondStr = EwConcatString( EwLoadString( &_Const0009 ), EwNewStringInt( Second, 
      0, 10 ));
    }
    else
    {
      SecondStr = EwNewStringInt( Second, 0, 10 );
    }

    ViewsText_OnSetString( &_this->TimeLeftText, EwConcatString( EwConcatString( 
    EwConcatString( EwLoadString( &StringsSET06_TIME_LEFT ), EwNewStringInt( _this->CountDownTimeSec 
    / 60, 0, 10 )), EwLoadString( &_Const000A )), SecondStr ));
  }
  else
  {
    EwPostSignal( EwNewSlot( _this, SettingsSET06_BtcDiscovarable_OnCancelSlot ), 
      ((XObject)_this ));
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
  {
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

      default : 
        ;
    }
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
  SettingsSET06_BtcDiscovarable_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( SettingsSET06_BtcDiscovarable )

/* Initializer for the class 'Settings::SET9_10_11_BtConnectionResult' */
void SettingsSET9_10_11_BtConnectionResult__Init( SettingsSET9_10_11_BtConnectionResult _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET9_10_11_BtConnectionResult );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Message, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ConnectPairedDeviceResultHandler, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->DismissTimer, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Divider, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET9_10_11_BtConnectionResult );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->Message, _Const000B );
  ViewsText_OnSetEllipsis( &_this->Message, 1 );
  ViewsText_OnSetWrapText( &_this->Message, 1 );
  ViewsText_OnSetAlignment( &_this->Message, ViewsTextAlignmentAlignHorzCenter | 
  ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Message, 0 );
  CoreTimer_OnSetPeriod( &_this->DismissTimer, 0 );
  CoreTimer_OnSetBegin( &_this->DismissTimer, 2000 );
  CoreRectView__OnSetBounds( &_this->Divider, _Const000C );
  ViewsImage_OnSetAlignment( &_this->Divider, ViewsImageAlignmentAlignVertBottom 
  | ViewsImageAlignmentScaleToFit );
  CoreGroup__Add( _this, ((CoreView)&_this->Message ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider ), -1 );
  ViewsText_OnSetFont( &_this->Message, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->ConnectPairedDeviceResultHandler.OnEvent = EwNewSlot( _this, SettingsSET9_10_11_BtConnectionResult_OnConnectPairedDeviceResultSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->ConnectPairedDeviceResultHandler, &EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->BtcConnectionResultSystemEvent );
  _this->DismissTimer.OnTrigger = EwNewSlot( _this, SettingsSET9_10_11_BtConnectionResult_OnDismissSlot );
  ViewsImage_OnSetBitmap( &_this->Divider, EwLoadResource( &ResourceStatusBarDivider, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'Settings::SET9_10_11_BtConnectionResult' */
void SettingsSET9_10_11_BtConnectionResult__ReInit( SettingsSET9_10_11_BtConnectionResult _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Message );
  CoreSystemEventHandler__ReInit( &_this->ConnectPairedDeviceResultHandler );
  CoreTimer__ReInit( &_this->DismissTimer );
  ViewsImage__ReInit( &_this->Divider );
}

/* Finalizer method for the class 'Settings::SET9_10_11_BtConnectionResult' */
void SettingsSET9_10_11_BtConnectionResult__Done( SettingsSET9_10_11_BtConnectionResult _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Message );
  CoreSystemEventHandler__Done( &_this->ConnectPairedDeviceResultHandler );
  CoreTimer__Done( &_this->DismissTimer );
  ViewsImage__Done( &_this->Divider );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
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
      XInt32 RightIdx;
      EwTrace( "%s%i", EwLoadString( &_Const000D ), EwGetStringLength( ProcessString ));
      EwTrace( "%s%i", EwLoadString( &_Const000E ), EwGetStringLength( EwLoadString( 
        &StringsARGUMENT_STR )));
      RightIdx = ( EwGetStringLength( ProcessString ) - LeftIdx ) - EwGetStringLength( 
      EwLoadString( &StringsARGUMENT_STR ));
      EwTrace( "%s%s", EwLoadString( &_Const000F ), _this->DeviceName );
      ViewsText_OnSetString( &_this->Message, EwConcatString( EwConcatString( EwStringLeft( 
      ProcessString, LeftIdx ), _this->DeviceName ), EwStringRight( ProcessString, 
      RightIdx )));
      EwTrace( "%s%s", EwLoadString( &_Const0010 ), _this->Message.String );
    }
    break;

    case EnumBtDeviceConnectionResultAUTHENTICATION_ERR :
    {
      XString ProcessString = EwLoadString( &StringsSET11_NO_LONGER_PAIRED );
      XInt32 LeftIdx = EwStringFind( ProcessString, EwLoadString( &StringsARGUMENT_STR ), 
        0 );
      XInt32 RightIdx = ( EwGetStringLength( ProcessString ) - LeftIdx ) - EwGetStringLength( 
        EwLoadString( &StringsARGUMENT_STR ));
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

  CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
  DeviceInterfaceBluetoothDeviceClass_OnSetRefreshPairedDeviceList( EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 1 );
}

/* Variants derived from the class : 'Settings::SET9_10_11_BtConnectionResult' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET9_10_11_BtConnectionResult )
EW_END_OF_CLASS_VARIANTS( SettingsSET9_10_11_BtConnectionResult )

/* Virtual Method Table (VMT) for the class : 'Settings::SET9_10_11_BtConnectionResult' */
EW_DEFINE_CLASS( SettingsSET9_10_11_BtConnectionResult, ComponentsBaseMainBG, Message, 
                 Message, Message, Message, DeviceName, _None, "Settings::SET9_10_11_BtConnectionResult" )
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( SettingsSET9_10_11_BtConnectionResult )

/* Initializer for the class 'Settings::SET05_BtcMaxPairedDevice' */
void SettingsSET05_BtcMaxPairedDevice__Init( SettingsSET05_BtcMaxPairedDevice _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET05_BtcMaxPairedDevice );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );
  MenuUpDownPushButtonSet__Init( &_this->UpDownPushButtonSet, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET05_BtcMaxPairedDevice );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0011 );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &StringsSET05_MAX_DEVICES ));
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const0012 );
  _this->UpDownPushButtonSet.Super1.PassHomeKey = 1;
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &_Const0013 ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &_Const0014 ));
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
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Text );
  MenuUpDownPushButtonSet__ReInit( &_this->UpDownPushButtonSet );
}

/* Finalizer method for the class 'Settings::SET05_BtcMaxPairedDevice' */
void SettingsSET05_BtcMaxPairedDevice__Done( SettingsSET05_BtcMaxPairedDevice _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Text );
  MenuUpDownPushButtonSet__Done( &_this->UpDownPushButtonSet );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
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

  EwTrace( "%s", EwLoadString( &_Const0015 ));
}

/* 'C' function for method : 'Settings::SET05_BtcMaxPairedDevice.OnYesActivatedSlot()' */
void SettingsSET05_BtcMaxPairedDevice_OnYesActivatedSlot( SettingsSET05_BtcMaxPairedDevice _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Super5.Owner != 0 )
  {
    CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)EwNewObject( SettingsSET17_BtcPairedDeviceList, 
    0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* 'C' function for method : 'Settings::SET05_BtcMaxPairedDevice.OnNoActivatedSlot()' */
void SettingsSET05_BtcMaxPairedDevice_OnNoActivatedSlot( SettingsSET05_BtcMaxPairedDevice _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Super5.Owner != 0 )
  {
    CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 0 );
  }
}

/* Variants derived from the class : 'Settings::SET05_BtcMaxPairedDevice' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET05_BtcMaxPairedDevice )
EW_END_OF_CLASS_VARIANTS( SettingsSET05_BtcMaxPairedDevice )

/* Virtual Method Table (VMT) for the class : 'Settings::SET05_BtcMaxPairedDevice' */
EW_DEFINE_CLASS( SettingsSET05_BtcMaxPairedDevice, ComponentsBaseMainBG, Text, Text, 
                 Text, Text, _None, _None, "Settings::SET05_BtcMaxPairedDevice" )
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( SettingsSET05_BtcMaxPairedDevice )

/* Initializer for the class 'Settings::SET08_BtcPairDevice' */
void SettingsSET08_BtcPairDevice__Init( SettingsSET08_BtcPairDevice _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET08_BtcPairDevice );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->PairText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->PasskeyText, &_this->_XObject, 0 );
  MenuUpDownPushButtonSet__Init( &_this->UpDownPushButtonSet, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->BtcPairingStateChangeEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET08_BtcPairDevice );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->PairText, _Const0016 );
  ViewsText_OnSetWrapText( &_this->PairText, 1 );
  ViewsText_OnSetAlignment( &_this->PairText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->PairText, EwLoadString( &StringsSET08_PAIR_WITH ));
  CoreRectView__OnSetBounds( &_this->PasskeyText, _Const0017 );
  ViewsText_OnSetWrapText( &_this->PasskeyText, 1 );
  ViewsText_OnSetAlignment( &_this->PasskeyText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->PasskeyText, EwLoadString( &StringsSET08_PASSKEY ));
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const0012 );
  _this->UpDownPushButtonSet.Super1.PassHomeKey = 1;
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &StringsGEN_yes ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &StringsGEN_no ));
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
  ComponentsBaseMainBG__ReInit( &_this->_Super );

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
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->PairText );
  ViewsText__Done( &_this->PasskeyText );
  MenuUpDownPushButtonSet__Done( &_this->UpDownPushButtonSet );
  CoreSystemEventHandler__Done( &_this->BtcPairingStateChangeEventHandler );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
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

  EwTrace( "%s", EwLoadString( &_Const0018 ));
  ProcessString = EwLoadString( &StringsSET08_PAIR_WITH );
  LeftIdx = EwStringFind( ProcessString, EwLoadString( &StringsARGUMENT_STR ), 0 );
  RightIdx = ( EwGetStringLength( ProcessString ) - LeftIdx ) - EwGetStringLength( 
  EwLoadString( &StringsARGUMENT_STR ));
  ViewsText_OnSetString( &_this->PairText, EwConcatString( EwConcatString( EwStringLeft( 
  ProcessString, LeftIdx ), DeviceInterfaceBluetoothDeviceClass_GetBtcPairingDeviceName( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ))), 
  EwStringRight( ProcessString, RightIdx )));
  ViewsText_OnSetString( &_this->PasskeyText, EwConcatString( EwConcatString( EwLoadString( 
  &StringsSET08_PASSKEY ), EwLoadString( &_Const0019 )), EwNewStringUInt( DeviceInterfaceBluetoothDeviceClass_GetBtcPasskey( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )), 
  0, 10 )));
}

/* 'C' function for method : 'Settings::SET08_BtcPairDevice.OnNoActivatedSlot()' */
void SettingsSET08_BtcPairDevice_OnNoActivatedSlot( SettingsSET08_BtcPairDevice _this, 
  XObject sender )
{
  SettingsSET04_BtSettingMenu BtSettingMenu;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwTrace( "%s", EwLoadString( &_Const001A ));
  BTM_btc_confirm_passkey( false );
  BtSettingMenu = EwCastObject( _this->Super5.Owner, SettingsSET04_BtSettingMenu );

  if ( BtSettingMenu != 0 )
  {
    if ( BtSettingMenu->Super6.Owner != 0 )
    {
      BtSettingMenu->Super2.SlideOutEffectEnabled = 0;
      ComponentsBaseMainBG_DismissThisDialog((ComponentsBaseMainBG)BtSettingMenu );
    }
  }
}

/* 'C' function for method : 'Settings::SET08_BtcPairDevice.OnYesActivatedSlot()' */
void SettingsSET08_BtcPairDevice_OnYesActivatedSlot( SettingsSET08_BtcPairDevice _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( sender );

  EwTrace( "%s", EwLoadString( &_Const001B ));
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
  {
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

      default : 
        ;
    }
  }
}

/* Variants derived from the class : 'Settings::SET08_BtcPairDevice' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET08_BtcPairDevice )
EW_END_OF_CLASS_VARIANTS( SettingsSET08_BtcPairDevice )

/* Virtual Method Table (VMT) for the class : 'Settings::SET08_BtcPairDevice' */
EW_DEFINE_CLASS( SettingsSET08_BtcPairDevice, ComponentsBaseMainBG, PairText, PairText, 
                 PairText, PairText, _None, _None, "Settings::SET08_BtcPairDevice" )
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( SettingsSET08_BtcPairDevice )

/* Initializer for the class 'Settings::SET17_BtcPairedDeviceList' */
void SettingsSET17_BtcPairedDeviceList__Init( SettingsSET17_BtcPairedDeviceList _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET17_BtcPairedDeviceList );

  /* ... then construct all embedded objects */
  CorePropertyObserver__Init( &_this->RefreshListObserver, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NoDataText, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->NoDataTimeoutTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET17_BtcPairedDeviceList );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 0 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  MenuVerticalMenu_OnSetArrowScrollBarVisible( &_this->Super1.Menu, 1 );
  CoreRectView__OnSetBounds( &_this->NoDataText, _Const000B );
  ViewsText_OnSetString( &_this->NoDataText, EwLoadString( &_Const001C ));
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
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CorePropertyObserver__ReInit( &_this->RefreshListObserver );
  ViewsText__ReInit( &_this->NoDataText );
  CoreTimer__ReInit( &_this->NoDataTimeoutTimer );
}

/* Finalizer method for the class 'Settings::SET17_BtcPairedDeviceList' */
void SettingsSET17_BtcPairedDeviceList__Done( SettingsSET17_BtcPairedDeviceList _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CorePropertyObserver__Done( &_this->RefreshListObserver );
  ViewsText__Done( &_this->NoDataText );
  CoreTimer__Done( &_this->NoDataTimeoutTimer );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET17_BtcPairedDeviceList_Init( SettingsSET17_BtcPairedDeviceList _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const001D ));
  SettingsSET17_BtcPairedDeviceList_UpdatePairedDeviceNum( _this );
}

/* 'C' function for method : 'Settings::SET17_BtcPairedDeviceList.LoadItemClass()' */
XClass SettingsSET17_BtcPairedDeviceList_LoadItemClass( SettingsSET17_BtcPairedDeviceList _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

  return EW_CLASS( MenuItemCheckMark );
}

/* 'C' function for method : 'Settings::SET17_BtcPairedDeviceList.LoadItemTitle()' */
XString SettingsSET17_BtcPairedDeviceList_LoadItemTitle( SettingsSET17_BtcPairedDeviceList _this, 
  XInt32 aItemNo )
{
  XString Title;

  if ( aItemNo > 0 )
    ;

  Title = 0;

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
  MenuItemCheckMark BtDeviceItem;

  if ( aItemNo >= 0 )
    ;

  BtDeviceItem = EwCastObject( aMenuItem, MenuItemCheckMark );

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

  if ( aItemNo > 0 )
    ;

  result = 0;

  if ( _this->PairedDeviceNum > 0 )
  {
    result = EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->PairedDeviceObj.IsConnected;
  }

  return result;
}

/* 'C' function for method : 'Settings::SET17_BtcPairedDeviceList.UpdatePairedDeviceNum()' */
void SettingsSET17_BtcPairedDeviceList_UpdatePairedDeviceNum( SettingsSET17_BtcPairedDeviceList _this )
{
  _this->PairedDeviceNum = DeviceInterfaceBluetoothDeviceClass_OnGetPairedDeviceNum( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ));
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, _this->PairedDeviceNum );
  EwTrace( "%s%i", EwLoadString( &_Const001E ), _this->PairedDeviceNum );

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

  EwTrace( "%s", EwLoadString( &_Const001F ));
  SettingsSET17_BtcPairedDeviceList_UpdatePairedDeviceNum( _this );
}

/* 'C' function for method : 'Settings::SET17_BtcPairedDeviceList.OnNoDataTimeoutSlot()' */
void SettingsSET17_BtcPairedDeviceList_OnNoDataTimeoutSlot( SettingsSET17_BtcPairedDeviceList _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Super6.Owner != 0 )
  {
    ComponentsBaseMainBG_SlideOutDialog((ComponentsBaseMainBG)_this );
  }
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  SettingsSET17_BtcPairedDeviceList_LoadItemClass,
  SettingsSET17_BtcPairedDeviceList_LoadItemTitle,
  SettingsSET17_BtcPairedDeviceList_OnItemActivate,
  SettingsSET17_BtcPairedDeviceList_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemUnitValue,
EW_END_OF_CLASS( SettingsSET17_BtcPairedDeviceList )

/* Initializer for the class 'Settings::SET19_BtcPairedDeviceOperation' */
void SettingsSET19_BtcPairedDeviceOperation__Init( SettingsSET19_BtcPairedDeviceOperation _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET19_BtcPairedDeviceOperation );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET19_BtcPairedDeviceOperation );

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
  MenuBaseMenuView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Settings::SET19_BtcPairedDeviceOperation' */
void SettingsSET19_BtcPairedDeviceOperation__Done( SettingsSET19_BtcPairedDeviceOperation _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
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

  EwTrace( "%s", EwLoadString( &_Const0020 ));
}

/* 'C' function for method : 'Settings::SET19_BtcPairedDeviceOperation.LoadItemClass()' */
XClass SettingsSET19_BtcPairedDeviceOperation_LoadItemClass( SettingsSET19_BtcPairedDeviceOperation _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

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

    default : 
      ;
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
        {
          ViewsBorder_OnSetVisible( &OwnerMenu->Menu.FocusFrame, 1 );
        }

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
      {
        ViewsBorder_OnSetVisible( &OwnerMenu->Menu.FocusFrame, 1 );
      }

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

    default : 
      ;
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  SettingsSET19_BtcPairedDeviceOperation_LoadItemClass,
  SettingsSET19_BtcPairedDeviceOperation_LoadItemTitle,
  SettingsSET19_BtcPairedDeviceOperation_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  SettingsSET19_BtcPairedDeviceOperation_LoadItemEnabled,
  MenuBaseMenuView_LoadItemUnitValue,
EW_END_OF_CLASS( SettingsSET19_BtcPairedDeviceOperation )

/* Initializer for the class 'Settings::SET18_DeleteBleDevice' */
void SettingsSET18_DeleteBleDevice__Init( SettingsSET18_DeleteBleDevice _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET18_DeleteBleDevice );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET18_DeleteBleDevice );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->Text, _Const000B );
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
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Text );
}

/* Finalizer method for the class 'Settings::SET18_DeleteBleDevice' */
void SettingsSET18_DeleteBleDevice__Done( SettingsSET18_DeleteBleDevice _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Text );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
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

  EwTrace( "%s", EwLoadString( &_Const0021 ));
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
                 Text, Text, DeviceName, _None, "Settings::SET18_DeleteBleDevice" )
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( SettingsSET18_DeleteBleDevice )

/* Initializer for the class 'Settings::BtFwUpdateDialog' */
void SettingsBtFwUpdateDialog__Init( SettingsBtFwUpdateDialog _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsBtFwUpdateDialog );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_XObject, 0 );
  ViewsText__Init( &_this->StatusText, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->BtFwStatusObserver, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->RemoveDialogTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsBtFwUpdateDialog );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0022 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0022 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0023 );
  CoreRectView__OnSetBounds( &_this->StatusText, _Const0024 );
  ViewsText_OnSetWrapText( &_this->StatusText, 1 );
  ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const0025 ));
  ViewsText_OnSetColor( &_this->StatusText, _Const0026 );
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
  CoreGroup__ReInit( &_this->_Super );

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
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsText__Done( &_this->StatusText );
  CorePropertyObserver__Done( &_this->BtFwStatusObserver );
  CoreTimer__Done( &_this->RemoveDialogTimer );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
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
      ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const0027 ));
      CoreTimer_OnSetEnabled( &_this->RemoveDialogTimer, 1 );
    }
    break;

    case EnumBtFwStatusUPDATE_ABORT :
    {
      ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const0028 ));
      CoreTimer_OnSetEnabled( &_this->RemoveDialogTimer, 1 );
    }
    break;

    default : 
      ;
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
                 Rectangle, _None, _None, "Settings::BtFwUpdateDialog" )
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
EW_END_OF_CLASS( SettingsBtFwUpdateDialog )

/* Initializer for the class 'Settings::TimeoutDialog' */
void SettingsTimeoutDialog__Init( SettingsTimeoutDialog _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsTimeoutDialog );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->MessageText, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->TimeoutTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsTimeoutDialog );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->MessageText, _Const000B );
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
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->MessageText );
  CoreTimer__ReInit( &_this->TimeoutTimer );
}

/* Finalizer method for the class 'Settings::TimeoutDialog' */
void SettingsTimeoutDialog__Done( SettingsTimeoutDialog _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->MessageText );
  CoreTimer__Done( &_this->TimeoutTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
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

  if ( _this->DismissAfterTimeout )
  {
    if ( _this->Super5.Owner != 0 )
    {
      CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 
      0, EwNullSlot, EwNullSlot, 0 );
    }
  }
  else
  {
    EwPostSignal( _this->OnTimeout, ((XObject)_this ));
  }
}

/* Wrapper function for the virtual method : 'Settings::TimeoutDialog.OnTimeoutSlot()' */
void SettingsTimeoutDialog__OnTimeoutSlot( void* _this, XObject sender )
{
  ((SettingsTimeoutDialog)_this)->_VMT->OnTimeoutSlot((SettingsTimeoutDialog)_this
  , sender );
}

/* Variants derived from the class : 'Settings::TimeoutDialog' */
EW_DEFINE_CLASS_VARIANTS( SettingsTimeoutDialog )
EW_END_OF_CLASS_VARIANTS( SettingsTimeoutDialog )

/* Virtual Method Table (VMT) for the class : 'Settings::TimeoutDialog' */
EW_DEFINE_CLASS( SettingsTimeoutDialog, ComponentsBaseMainBG, OnTimeout, OnTimeout, 
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  SettingsTimeoutDialog_OnTimeoutSlot,
EW_END_OF_CLASS( SettingsTimeoutDialog )

/* Initializer for the class 'Settings::SET30_QRCode' */
void SettingsSET30_QRCode__Init( SettingsSET30_QRCode _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET30_QRCode );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->QrCodeUpdateEventHandler, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->QrCode, &_this->_XObject, 0 );
  ViewsText__Init( &_this->PixelText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->QrCodeWidthText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->QrCodeContent, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET30_QRCode );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0022 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->QrCode, _Const0029 );
  ViewsImage_OnSetAlignment( &_this->QrCode, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  _this->PixelPerModule = 1;
  CoreRectView__OnSetBounds( &_this->PixelText, _Const002A );
  ViewsText_OnSetAlignment( &_this->PixelText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->PixelText, 0 );
  CoreRectView__OnSetBounds( &_this->QrCodeWidthText, _Const002B );
  ViewsText_OnSetAlignment( &_this->QrCodeWidthText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->QrCodeWidthText, 0 );
  CoreRectView__OnSetBounds( &_this->QrCodeContent, _Const002C );
  ViewsText_OnSetWrapText( &_this->QrCodeContent, 1 );
  ViewsText_OnSetAlignment( &_this->QrCodeContent, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->QrCodeContent, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->QrCode ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PixelText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->QrCodeWidthText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->QrCodeContent ), 0 );
  _this->QrCodeUpdateEventHandler.OnEvent = EwNewSlot( _this, SettingsSET30_QRCode_OnQrCodeUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->QrCodeUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->QrCodeSystemEvent );
  ViewsImage_OnSetBitmap( &_this->QrCode, ((ResourcesBitmap)EwGetAutoObject( &ResourceQrCodeExternBitmap, 
  ResourcesExternBitmap )));
  ViewsText_OnSetFont( &_this->PixelText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->QrCodeWidthText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->QrCodeContent, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));

  /* Call the user defined constructor */
  SettingsSET30_QRCode_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET30_QRCode' */
void SettingsSET30_QRCode__ReInit( SettingsSET30_QRCode _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->QrCodeUpdateEventHandler );
  ViewsImage__ReInit( &_this->QrCode );
  ViewsText__ReInit( &_this->PixelText );
  ViewsText__ReInit( &_this->QrCodeWidthText );
  ViewsText__ReInit( &_this->QrCodeContent );
}

/* Finalizer method for the class 'Settings::SET30_QRCode' */
void SettingsSET30_QRCode__Done( SettingsSET30_QRCode _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CoreSystemEventHandler__Done( &_this->QrCodeUpdateEventHandler );
  ViewsImage__Done( &_this->QrCode );
  ViewsText__Done( &_this->PixelText );
  ViewsText__Done( &_this->QrCodeWidthText );
  ViewsText__Done( &_this->QrCodeContent );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSET30_QRCode_Init( SettingsSET30_QRCode _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  DeviceInterfaceSystemDeviceClass_GetQrCode( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ), _this->PixelPerModule );
}

/* 'C' function for method : 'Settings::SET30_QRCode.OnShortDownKeyActivated()' */
void SettingsSET30_QRCode_OnShortDownKeyActivated( SettingsSET30_QRCode _this )
{
  if ( _this->PixelPerModule > 1 )
  {
    _this->PixelPerModule--;
    DeviceInterfaceSystemDeviceClass_GetQrCode( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
    DeviceInterfaceSystemDeviceClass ), _this->PixelPerModule );
  }
  else
  {
    EwTrace( "%s", EwLoadString( &_Const002D ));
  }
}

/* 'C' function for method : 'Settings::SET30_QRCode.OnShortUpKeyActivated()' */
void SettingsSET30_QRCode_OnShortUpKeyActivated( SettingsSET30_QRCode _this )
{
  if ( _this->PixelPerModule < 4 )
  {
    _this->PixelPerModule++;
    DeviceInterfaceSystemDeviceClass_GetQrCode( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
    DeviceInterfaceSystemDeviceClass ), _this->PixelPerModule );
  }
  else
  {
    EwTrace( "%s", EwLoadString( &_Const002E ));
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SettingsSET30_QRCode_OnQrCodeUpdateSlot( SettingsSET30_QRCode _this, XObject 
  sender )
{
  XFloat QrCodeWidth;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ResourcesExternBitmap_OnSetName( EwGetAutoObject( &ResourceQrCodeExternBitmap, 
  ResourcesExternBitmap ), EwConcatString( EwLoadString( &_Const002F ), EwNewStringInt( 
  _this->PixelPerModule, 0, 10 )));
  ViewsText_OnSetString( &_this->PixelText, EwConcatString( EwNewStringInt( _this->PixelPerModule, 
  0, 10 ), EwLoadString( &_Const0030 )));
  QrCodeWidth = ( 33 * _this->PixelPerModule ) * 0.019350f;
  ViewsText_OnSetString( &_this->QrCodeWidthText, EwConcatString( EwConcatString( 
  EwLoadString( &_Const0031 ), EwNewStringFloat( QrCodeWidth, 0, -1 )), EwLoadString( 
  &_Const0032 )));
  ViewsText_OnSetString( &_this->QrCodeContent, EwConcatString( EwLoadString( &_Const0033 ), 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->QrCodeText ));
}

/* Variants derived from the class : 'Settings::SET30_QRCode' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET30_QRCode )
EW_END_OF_CLASS_VARIANTS( SettingsSET30_QRCode )

/* Virtual Method Table (VMT) for the class : 'Settings::SET30_QRCode' */
EW_DEFINE_CLASS( SettingsSET30_QRCode, MenuBaseMenuView, QrCodeUpdateEventHandler, 
                 QrCodeUpdateEventHandler, QrCodeUpdateEventHandler, QrCodeUpdateEventHandler, 
                 PixelPerModule, PixelPerModule, "Settings::SET30_QRCode" )
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
  SettingsSET30_QRCode_OnShortDownKeyActivated,
  SettingsSET30_QRCode_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemUnitValue,
EW_END_OF_CLASS( SettingsSET30_QRCode )

/* Initializer for the class 'Settings::SET22_BleAdvertising' */
void SettingsSET22_BleAdvertising__Init( SettingsSET22_BleAdvertising _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET22_BleAdvertising );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->DeviceNameText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->WaitText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->LocalDeviceNameText, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Image, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->BlePairingStateChangedEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET22_BleAdvertising );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->DeviceNameText, _Const0034 );
  ViewsText_OnSetString( &_this->DeviceNameText, EwLoadString( &StringsSET22_DEVICE_NAME ));
  CoreRectView__OnSetBounds( &_this->WaitText, _Const0035 );
  ViewsText_OnSetWrapText( &_this->WaitText, 1 );
  ViewsText_OnSetString( &_this->WaitText, EwLoadString( &StringsSET22_WAIT_APP_CONNECTION ));
  CoreRectView__OnSetBounds( &_this->LocalDeviceNameText, _Const0036 );
  ViewsText_OnSetEllipsis( &_this->LocalDeviceNameText, 1 );
  ViewsText_OnSetString( &_this->LocalDeviceNameText, DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceName( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )));
  CoreRectView__OnSetBounds( &_this->Image, _Const0037 );
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
  ComponentsBaseMainBG__ReInit( &_this->_Super );

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
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->DeviceNameText );
  ViewsText__Done( &_this->WaitText );
  ViewsText__Done( &_this->LocalDeviceNameText );
  ViewsImage__Done( &_this->Image );
  CoreSystemEventHandler__Done( &_this->BlePairingStateChangedEventHandler );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
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

  EwTrace( "%s", EwLoadString( &_Const0038 ));
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

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SettingsSET22_BleAdvertising_OnBlePairingStateChangedSlot( SettingsSET22_BleAdvertising _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Super5.Owner != 0 )
  {
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

      default : 
        ;
    }
  }
}

/* Variants derived from the class : 'Settings::SET22_BleAdvertising' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET22_BleAdvertising )
EW_END_OF_CLASS_VARIANTS( SettingsSET22_BleAdvertising )

/* Virtual Method Table (VMT) for the class : 'Settings::SET22_BleAdvertising' */
EW_DEFINE_CLASS( SettingsSET22_BleAdvertising, ComponentsBaseMainBG, DeviceNameText, 
                 DeviceNameText, DeviceNameText, DeviceNameText, _None, _None, "Settings::SET22_BleAdvertising" )
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
  SettingsSET22_BleAdvertising_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( SettingsSET22_BleAdvertising )

/* Initializer for the class 'Settings::SET23_BlePairingFail' */
void SettingsSET23_BlePairingFail__Init( SettingsSET23_BlePairingFail _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  SettingsTimeoutDialog__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET23_BlePairingFail );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET23_BlePairingFail );

  /* ... and initialize objects, variables, properties, etc. */
  ViewsText_OnSetString( &_this->Super1.MessageText, EwLoadString( &StringsSET23_PAIRING_FAILED ));
}

/* Re-Initializer for the class 'Settings::SET23_BlePairingFail' */
void SettingsSET23_BlePairingFail__ReInit( SettingsSET23_BlePairingFail _this )
{
  /* At first re-initialize the super class ... */
  SettingsTimeoutDialog__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Settings::SET23_BlePairingFail' */
void SettingsSET23_BlePairingFail__Done( SettingsSET23_BlePairingFail _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( SettingsTimeoutDialog );

  /* Don't forget to deinitialize the super class ... */
  SettingsTimeoutDialog__Done( &_this->_Super );
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
  {
    CoreGroup_SwitchToDialog( _this->Super6.Owner, ((CoreGroup)EwNewObject( SettingsSET24_CheckPairingRecord, 
    0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
  else
  {
    CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 0 );
  }
}

/* Variants derived from the class : 'Settings::SET23_BlePairingFail' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET23_BlePairingFail )
EW_END_OF_CLASS_VARIANTS( SettingsSET23_BlePairingFail )

/* Virtual Method Table (VMT) for the class : 'Settings::SET23_BlePairingFail' */
EW_DEFINE_CLASS( SettingsSET23_BlePairingFail, SettingsTimeoutDialog, _None, _None, 
                 _None, _None, _None, _None, "Settings::SET23_BlePairingFail" )
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  SettingsSET23_BlePairingFail_OnTimeoutSlot,
EW_END_OF_CLASS( SettingsSET23_BlePairingFail )

/* Initializer for the class 'Settings::SET24_CheckPairingRecord' */
void SettingsSET24_CheckPairingRecord__Init( SettingsSET24_CheckPairingRecord _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET24_CheckPairingRecord );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->MessageText, &_this->_XObject, 0 );
  MenuPushButton__Init( &_this->PushButton, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET24_CheckPairingRecord );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->MessageText, _Const0039 );
  ViewsText_OnSetWrapText( &_this->MessageText, 1 );
  ViewsText_OnSetString( &_this->MessageText, EwLoadString( &StringsSET24_CHECK_BT_PAIRING_RECORD ));
  CoreRectView__OnSetBounds( &_this->PushButton, _Const0006 );
  MenuPushButton_OnSetTitle( &_this->PushButton, EwGetVariantOfString( &StringsGEN_ok ));
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
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->MessageText );
  MenuPushButton__ReInit( &_this->PushButton );
}

/* Finalizer method for the class 'Settings::SET24_CheckPairingRecord' */
void SettingsSET24_CheckPairingRecord__Done( SettingsSET24_CheckPairingRecord _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->MessageText );
  MenuPushButton__Done( &_this->PushButton );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
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

  EwTrace( "%s", EwLoadString( &_Const003A ));
}

/* 'C' function for method : 'Settings::SET24_CheckPairingRecord.OnOkActivatedSlot()' */
void SettingsSET24_CheckPairingRecord_OnOkActivatedSlot( SettingsSET24_CheckPairingRecord _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* Variants derived from the class : 'Settings::SET24_CheckPairingRecord' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET24_CheckPairingRecord )
EW_END_OF_CLASS_VARIANTS( SettingsSET24_CheckPairingRecord )

/* Virtual Method Table (VMT) for the class : 'Settings::SET24_CheckPairingRecord' */
EW_DEFINE_CLASS( SettingsSET24_CheckPairingRecord, ComponentsBaseMainBG, MessageText, 
                 MessageText, MessageText, MessageText, _None, _None, "Settings::SET24_CheckPairingRecord" )
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( SettingsSET24_CheckPairingRecord )

/* Initializer for the class 'Settings::SET25_BlePincode' */
void SettingsSET25_BlePincode__Init( SettingsSET25_BlePincode _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET25_BlePincode );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->BleStateChangedEventHandler, &_this->_XObject, 0 );
  ViewsText__Init( &_this->PincodeText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET25_BlePincode );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->PincodeText, _Const000B );
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
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->BleStateChangedEventHandler );
  ViewsText__ReInit( &_this->PincodeText );
}

/* Finalizer method for the class 'Settings::SET25_BlePincode' */
void SettingsSET25_BlePincode__Done( SettingsSET25_BlePincode _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  CoreSystemEventHandler__Done( &_this->BleStateChangedEventHandler );
  ViewsText__Done( &_this->PincodeText );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
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
  0, 10 );
  ViewsText_OnSetString( &_this->PincodeText, EwConcatString( EwConcatString( EwLoadString( 
  &StringsSET25_PIN ), EwLoadString( &_Const0019 )), PincodeString ));
  EwTrace( "%s%s", EwLoadString( &_Const003B ), PincodeString );
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
  {
    EwPostSignal( EwNewSlot( _this, SettingsSET25_BlePincode_OnBlePairingStateChangedSlot ), 
      ((XObject)_this ));
  }
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
  {
    switch ( DeviceInterfaceBluetoothDeviceClass_OnGetBlePairingState( EwGetAutoObject( 
            &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )))
    {
      case EnumBlePairingStateFAIL :
      case EnumBlePairingStateTIMEOUT :
      {
        CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)EwNewObject( 
        SettingsSET23_BlePairingFail, 0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 
        0 );
      }
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

      default : 
        ;
    }
  }
}

/* Variants derived from the class : 'Settings::SET25_BlePincode' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET25_BlePincode )
EW_END_OF_CLASS_VARIANTS( SettingsSET25_BlePincode )

/* Virtual Method Table (VMT) for the class : 'Settings::SET25_BlePincode' */
EW_DEFINE_CLASS( SettingsSET25_BlePincode, ComponentsBaseMainBG, BleStateChangedEventHandler, 
                 BleStateChangedEventHandler, BleStateChangedEventHandler, BleStateChangedEventHandler, 
                 _None, _None, "Settings::SET25_BlePincode" )
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( SettingsSET25_BlePincode )

/* Initializer for the class 'Settings::SET28_SystemInfo' */
void SettingsSET28_SystemInfo__Init( SettingsSET28_SystemInfo _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET28_SystemInfo );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->ESN, &_this->_XObject, 0 );
  ViewsText__Init( &_this->SoftwareVersionTitle, &_this->_XObject, 0 );
  ViewsText__Init( &_this->EsnText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->SoftwareVersionText, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->EsnObserver, &_this->_XObject, 0 );
  MenuUpDownPushButtonSet__Init( &_this->UpDownPushButtonSet, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET28_SystemInfo );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0022 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->ESN, _Const003C );
  ViewsText_OnSetString( &_this->ESN, EwLoadString( &StringsSET28_esn ));
  CoreRectView__OnSetBounds( &_this->SoftwareVersionTitle, _Const003D );
  ViewsText_OnSetString( &_this->SoftwareVersionTitle, EwLoadString( &StringsSET28_sw_version ));
  CoreRectView__OnSetBounds( &_this->EsnText, _Const003E );
  ViewsText_OnSetString( &_this->EsnText, 0 );
  CoreRectView__OnSetBounds( &_this->SoftwareVersionText, _Const003F );
  ViewsText_OnSetString( &_this->SoftwareVersionText, DeviceInterfaceSystemDeviceClass_OnGetSoftwareVersion( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const0040 );
  _this->UpDownPushButtonSet.Super1.PassHomeKey = 1;
  _this->UpDownPushButtonSet.Super1.PassMagicKey = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->UpDownPushButtonSet, 1 );
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &StringsSET28_unit_id ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &StringsSET28_sw_update ));
  MenuUpDownPushButtonSet_OnSetDownButtonEnabled( &_this->UpDownPushButtonSet, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ESN ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SoftwareVersionTitle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->EsnText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SoftwareVersionText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UpDownPushButtonSet ), 0 );
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

  /* Call the user defined constructor */
  SettingsSET28_SystemInfo_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET28_SystemInfo' */
void SettingsSET28_SystemInfo__ReInit( SettingsSET28_SystemInfo _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->ESN );
  ViewsText__ReInit( &_this->SoftwareVersionTitle );
  ViewsText__ReInit( &_this->EsnText );
  ViewsText__ReInit( &_this->SoftwareVersionText );
  CorePropertyObserver__ReInit( &_this->EsnObserver );
  MenuUpDownPushButtonSet__ReInit( &_this->UpDownPushButtonSet );
}

/* Finalizer method for the class 'Settings::SET28_SystemInfo' */
void SettingsSET28_SystemInfo__Done( SettingsSET28_SystemInfo _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->ESN );
  ViewsText__Done( &_this->SoftwareVersionTitle );
  ViewsText__Done( &_this->EsnText );
  ViewsText__Done( &_this->SoftwareVersionText );
  CorePropertyObserver__Done( &_this->EsnObserver );
  MenuUpDownPushButtonSet__Done( &_this->UpDownPushButtonSet );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
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

/* Variants derived from the class : 'Settings::SET28_SystemInfo' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET28_SystemInfo )
EW_END_OF_CLASS_VARIANTS( SettingsSET28_SystemInfo )

/* Virtual Method Table (VMT) for the class : 'Settings::SET28_SystemInfo' */
EW_DEFINE_CLASS( SettingsSET28_SystemInfo, ComponentsBaseMainBG, ESN, ESN, ESN, 
                 ESN, _None, _None, "Settings::SET28_SystemInfo" )
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
  SettingsSET28_SystemInfo_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( SettingsSET28_SystemInfo )

/* Embedded Wizard */
