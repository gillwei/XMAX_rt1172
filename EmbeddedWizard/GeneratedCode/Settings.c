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
#include "_SettingsBtConnectionResult.h"
#include "_SettingsBtDeleteBleDevice.h"
#include "_SettingsBtDiscovarable.h"
#include "_SettingsBtFwUpdateDialog.h"
#include "_SettingsBtMaxPairedDevice.h"
#include "_SettingsSET01_MainSettingMenu.h"
#include "_SettingsSET03_ConnectionSettingMenu.h"
#include "_SettingsSET04_BtSettingMenu.h"
#include "_SettingsSET17_BtPairedDeviceList.h"
#include "_SettingsSET19_BtPairedDeviceOperation.h"
#include "_SettingsSET28_SystemInfo.h"
#include "_SettingsSET30_QRCode.h"
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
  0x00000430, /* ratio 52.24 % */
  0xB8005F00, 0x8009C452, 0x00EE0037, 0x0C800100, 0xE6003480, 0x10731800, 0x65001D80,
  0x1001C800, 0x00188006, 0xF42E306C, 0x48CF2008, 0xA0007484, 0xA191B911, 0xEA009010,
  0x10894C88, 0x0E91CAA5, 0x48845E33, 0x1744A331, 0x18368200, 0x43CA8458, 0x32446D00,
  0x0CD1990C, 0x823A9480, 0xD4404002, 0x19A4C760, 0x403D06A3, 0xA8800674, 0x0D840030,
  0x10E8809A, 0x4CDC008E, 0x28321914, 0x0163A201, 0x15A825BC, 0x15B30380, 0x48CDAAD5,
  0xB5442531, 0xBD064667, 0x4865F04B, 0x56691999, 0x0152B94C, 0x21521100, 0x98EC8510,
  0x7A844521, 0xE915F645, 0x1CD06810, 0x94421944, 0xC22D50C8, 0x040179A5, 0x2D72D8CE,
  0x9F9AB4E6, 0x98A91E72, 0x16A56321, 0x09E4AE45, 0x86502333, 0x6C42D050, 0xC325310D,
  0xFE3B818E, 0x0019E005, 0x2A00C986, 0x77BD86BB, 0x0CD4DFAD, 0xDDEF2A9D, 0x07D4B990,
  0xDF575F78, 0x43303CBC, 0x07A16EC8, 0x09B4422D, 0xD5233C5A, 0x91FA4CCA, 0x4E0049F5,
  0xCDCCE619, 0x8DC8E7DB, 0xD1447519, 0x3675194A, 0x25221492, 0x1945D085, 0x835AF431,
  0x515469F8, 0x21C10C52, 0xE205849C, 0x6B4ED224, 0x68D21841, 0x9520FDB2, 0x21654401,
  0x15414492, 0x41455550, 0x41904639, 0x51D775A7, 0xF5051D4A, 0x0055411C, 0x3343A160,
  0x76DC148A, 0xC4477600, 0x04F54786, 0x49F34180, 0x4F510145, 0x536086C0, 0x13744618,
  0x94494713, 0xD93014D2, 0x440AD414, 0x5A14C705, 0xDFB84112, 0x78412997, 0x0216841B,
  0xFF601479, 0x46D086C5, 0x1B08390E, 0x24212643, 0xB94146D3, 0xF70B1047, 0x42A1299D,
  0x27C46620, 0xC4C9159D, 0x991D5250, 0x2362DA54, 0x475237D5, 0x5B697D1F, 0x79050C45,
  0x19B17519, 0xB751D097, 0x72E54431, 0x5670006B, 0xB48E7047, 0x8E04A4DC, 0x294C94E4,
  0x735229DD, 0xE4D4122A, 0x409D5212, 0xA23B8E54, 0x2E9B1D75, 0x76546001, 0x94946D47,
  0x348AA442, 0x75DC8EA8, 0xC448E614, 0x501DEA72, 0x400549CD, 0x00000040, 0x00000000
};

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault1[] =
{
  0x0000012C, /* ratio 62.67 % */
  0xB8003D00, 0x000AA452, 0x00C80038, 0x0E800308, 0x40003280, 0x80021000, 0x6600444A,
  0x2001A400, 0x001B4007, 0x7C721677, 0x800C7178, 0x020F1E37, 0x21D24360, 0x34000044,
  0x52A82C0C, 0x17974321, 0x98945A29, 0x8FC76371, 0x84761921, 0x46E453C8, 0xCC253096,
  0x2212C844, 0x252439C3, 0x000A1C22, 0x7589542A, 0xB0A4C254, 0xA7C92574, 0xB5525551,
  0xCA21517A, 0x02606E90, 0x0A333048, 0x86002900, 0x12484C9C, 0x12825B26, 0x800468A1,
  0x00522487, 0xD95E660A, 0x1A21D0AB, 0xC22E3A00, 0xA2533034, 0xDB5B8FC9, 0x1728BDBE,
  0x00A242A5, 0x8B4CA24C, 0xC0623393, 0x0407436A, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0001 = {{ 10, 46 }, { 470, 77 }};
static const XRect _Const0002 = {{ 10, 108 }, { 470, 139 }};
static const XRect _Const0003 = {{ 10, 77 }, { 470, 108 }};
static const XRect _Const0004 = {{ 10, 139 }, { 470, 170 }};
static const XRect _Const0005 = {{ 95, 176 }, { 385, 259 }};
static const XRect _Const0006 = {{ 60, 34 }, { 410, 110 }};
static const XStringRes _Const0007 = { _StringsDefault0, 0x0002 };
static const XRect _Const0008 = {{ 130, 153 }, { 280, 193 }};
static const XStringRes _Const0009 = { _StringsDefault0, 0x0031 };
static const XRect _Const000A = {{ 120, 113 }, { 240, 153 }};
static const XStringRes _Const000B = { _StringsDefault0, 0x003E };
static const XRect _Const000C = {{ 260, 153 }, { 340, 193 }};
static const XStringRes _Const000D = { _StringsDefault0, 0x0046 };
static const XRect _Const000E = {{ 230, 113 }, { 400, 153 }};
static const XRect _Const000F = {{ 165, 219 }, { 315, 259 }};
static const XStringRes _Const0010 = { _StringsDefault0, 0x004D };
static const XStringRes _Const0011 = { _StringsDefault0, 0x0056 };
static const XStringRes _Const0012 = { _StringsDefault0, 0x005A };
static const XRect _Const0013 = {{ 40, 40 }, { 440, 230 }};
static const XRect _Const0014 = {{ 30, 90 }, { 460, 140 }};
static const XStringRes _Const0015 = { _StringsDefault0, 0x005E };
static const XStringRes _Const0016 = { _StringsDefault0, 0x006C };
static const XStringRes _Const0017 = { _StringsDefault0, 0x007A };
static const XStringRes _Const0018 = { _StringsDefault0, 0x008A };
static const XStringRes _Const0019 = { _StringsDefault0, 0x00C3 };
static const XStringRes _Const001A = { _StringsDefault0, 0x00DB };
static const XStringRes _Const001B = { _StringsDefault0, 0x00EA };
static const XRect _Const001C = {{ 20, 70 }, { 460, 150 }};
static const XStringRes _Const001D = { _StringsDefault0, 0x00EE };
static const XRect _Const001E = {{ 165, 176 }, { 315, 259 }};
static const XStringRes _Const001F = { _StringsDefault0, 0x0133 };
static const XStringRes _Const0020 = { _StringsDefault0, 0x0139 };
static const XRect _Const0021 = {{ 10, 50 }, { 470, 236 }};
static const XStringRes _Const0022 = { _StringsDefault0, 0x013E };
static const XStringRes _Const0023 = { _StringsDefault0, 0x0148 };
static const XStringRes _Const0024 = { _StringsDefault0, 0x0160 };
static const XRect _Const0025 = {{ 40, 50 }, { 440, 200 }};
static const XStringRes _Const0026 = { _StringsDefault0, 0x0174 };
static const XStringRes _Const0027 = { _StringsDefault0, 0x019F };
static const XStringRes _Const0028 = { _StringsDefault0, 0x01EC };
static const XColor _Const0029 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const002A = {{ 80, 60 }, { 380, 210 }};
static const XStringRes _Const002B = { _StringsDefault0, 0x01F1 };
static const XColor _Const002C = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XStringRes _Const002D = { _StringsDefault1, 0x0002 };
static const XStringRes _Const002E = { _StringsDefault1, 0x0020 };
static const XRect _Const002F = {{ 20, 98 }, { 207, 227 }};
static const XRect _Const0030 = {{ 210, 85 }, { 398, 135 }};
static const XRect _Const0031 = {{ 210, 192 }, { 442, 240 }};
static const XRect _Const0032 = {{ 210, 137 }, { 463, 192 }};
static const XStringRes _Const0033 = { _StringsDefault1, 0x003A };
static const XStringRes _Const0034 = { _StringsDefault1, 0x004C };
static const XStringRes _Const0035 = { _StringsDefault1, 0x0060 };
static const XStringRes _Const0036 = { _StringsDefault1, 0x0069 };
static const XStringRes _Const0037 = { _StringsDefault1, 0x0072 };
static const XStringRes _Const0038 = { _StringsDefault1, 0x007C };
static const XStringRes _Const0039 = { _StringsDefault1, 0x0082 };

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
  CoreRectView__OnSetBounds( _this, _Const0000 );
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
      ;
    break;

    case EnumMainSettingItemUnit :
      ;
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  SettingsSET01_MainSettingMenu_LoadItemClass,
  SettingsSET01_MainSettingMenu_LoadItemTitle,
  SettingsSET01_MainSettingMenu_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
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
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 2 );
  _this->Super2.SlideOutEffectEnabled = 1;
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsGEN_bluetooth ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsSET03_y_connect_app_pairing ));
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
      ;
    break;

    default : 
      ;
  }
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  SettingsSET03_ConnectionSettingMenu_LoadItemClass,
  SettingsSET03_ConnectionSettingMenu_LoadItemTitle,
  SettingsSET03_ConnectionSettingMenu_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
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
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 4 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  _this->Super2.SlideOutEffectEnabled = 1;
  _this->ItemClassArray[ 0 ] = EW_CLASS( MenuItemCheckbox );
  _this->ItemClassArray[ 1 ] = EW_CLASS( MenuItemBase );
  _this->ItemClassArray[ 2 ] = EW_CLASS( MenuItemBase );
  _this->ItemClassArray[ 3 ] = EW_CLASS( MenuItemCheckbox );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsGEN_bluetooth ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsSET04_discovery_mode ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &StringsSET04_paired_devices ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &StringsSET04_bt_auto_connect ));

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
        SettingsBtMaxPairedDevice MaxPairedDevDialog = EwNewObject( SettingsBtMaxPairedDevice, 
          0 );
        MaxPairedDevDialog->ToRemovePairedDevice = EwNewSlot( _this, SettingsSET04_BtSettingMenu_ShowPairedDeviceListSlot );
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)MaxPairedDevDialog ), 
        0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
      else
      {
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsBtDiscovarable, 
        0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
    }
    break;

    case 2 :
      EwSignal( EwNewSlot( _this, SettingsSET04_BtSettingMenu_ShowPairedDeviceListSlot ), 
        ((XObject)_this ));
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

/* 'C' function for method : 'Settings::SET04_BtSettingMenu.ShowPairedDeviceListSlot()' */
void SettingsSET04_BtSettingMenu_ShowPairedDeviceListSlot( SettingsSET04_BtSettingMenu _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsSET17_BtPairedDeviceList, 
  0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  SettingsSET04_BtSettingMenu_LoadItemClass,
  SettingsSET04_BtSettingMenu_LoadItemTitle,
  SettingsSET04_BtSettingMenu_OnItemActivate,
  SettingsSET04_BtSettingMenu_LoadItemChecked,
  SettingsSET04_BtSettingMenu_LoadItemEnabled,
EW_END_OF_CLASS( SettingsSET04_BtSettingMenu )

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
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->ESN, _Const0001 );
  ViewsText_OnSetString( &_this->ESN, EwLoadString( &StringsSET28_esn ));
  CoreRectView__OnSetBounds( &_this->SoftwareVersionTitle, _Const0002 );
  ViewsText_OnSetString( &_this->SoftwareVersionTitle, EwLoadString( &StringsSET28_sw_version ));
  CoreRectView__OnSetBounds( &_this->EsnText, _Const0003 );
  ViewsText_OnSetString( &_this->EsnText, 0 );
  CoreRectView__OnSetBounds( &_this->SoftwareVersionText, _Const0004 );
  ViewsText_OnSetString( &_this->SoftwareVersionText, DeviceInterfaceSystemDeviceClass_OnGetSoftwareVersion( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const0005 );
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
  SettingsSET28_SystemInfo_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( SettingsSET28_SystemInfo )

/* Initializer for the class 'Settings::BtDiscovarable' */
void SettingsBtDiscovarable__Init( SettingsBtDiscovarable _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsBtDiscovarable );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->DiscoverableText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TimeLeftText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NameText, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->CountDownTimer, &_this->_XObject, 0 );
  ViewsText__Init( &_this->RemainTimeText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DeviceNameText, &_this->_XObject, 0 );
  MenuPushButton__Init( &_this->PushButton, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsBtDiscovarable );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->DiscoverableText, _Const0006 );
  ViewsText_OnSetWrapText( &_this->DiscoverableText, 1 );
  ViewsText_OnSetAlignment( &_this->DiscoverableText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->DiscoverableText, EwLoadString( &_Const0007 ));
  CoreRectView__OnSetBounds( &_this->TimeLeftText, _Const0008 );
  ViewsText_OnSetWrapText( &_this->TimeLeftText, 1 );
  ViewsText_OnSetAlignment( &_this->TimeLeftText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->TimeLeftText, EwLoadString( &_Const0009 ));
  CoreRectView__OnSetBounds( &_this->NameText, _Const000A );
  ViewsText_OnSetWrapText( &_this->NameText, 1 );
  ViewsText_OnSetAlignment( &_this->NameText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->NameText, EwLoadString( &_Const000B ));
  CoreTimer_OnSetPeriod( &_this->CountDownTimer, 1000 );
  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 0 );
  CoreRectView__OnSetBounds( &_this->RemainTimeText, _Const000C );
  ViewsText_OnSetWrapText( &_this->RemainTimeText, 1 );
  ViewsText_OnSetAlignment( &_this->RemainTimeText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->RemainTimeText, EwLoadString( &_Const000D ));
  _this->CountDownTimeSec = 180;
  CoreRectView__OnSetBounds( &_this->DeviceNameText, _Const000E );
  ViewsText_OnSetWrapText( &_this->DeviceNameText, 1 );
  ViewsText_OnSetAlignment( &_this->DeviceNameText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DeviceNameText, DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceName( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )));
  CoreRectView__OnSetBounds( &_this->PushButton, _Const000F );
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->PushButton, 1 );
  MenuPushButton_OnSetTitle( &_this->PushButton, EwLoadString( &_Const0010 ));
  CoreGroup__Add( _this, ((CoreView)&_this->DiscoverableText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeLeftText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NameText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RemainTimeText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DeviceNameText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PushButton ), 0 );
  ViewsText_OnSetFont( &_this->DiscoverableText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->TimeLeftText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->NameText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->CountDownTimer.OnTrigger = EwNewSlot( _this, SettingsBtDiscovarable_UpdateCountDownTimeSlot );
  ViewsText_OnSetFont( &_this->RemainTimeText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DeviceNameText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->PushButton.OnActivate = EwNewSlot( _this, SettingsBtDiscovarable_OnCancelSlot );

  /* Call the user defined constructor */
  SettingsBtDiscovarable_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::BtDiscovarable' */
void SettingsBtDiscovarable__ReInit( SettingsBtDiscovarable _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->DiscoverableText );
  ViewsText__ReInit( &_this->TimeLeftText );
  ViewsText__ReInit( &_this->NameText );
  CoreTimer__ReInit( &_this->CountDownTimer );
  ViewsText__ReInit( &_this->RemainTimeText );
  ViewsText__ReInit( &_this->DeviceNameText );
  MenuPushButton__ReInit( &_this->PushButton );
}

/* Finalizer method for the class 'Settings::BtDiscovarable' */
void SettingsBtDiscovarable__Done( SettingsBtDiscovarable _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->DiscoverableText );
  ViewsText__Done( &_this->TimeLeftText );
  ViewsText__Done( &_this->NameText );
  CoreTimer__Done( &_this->CountDownTimer );
  ViewsText__Done( &_this->RemainTimeText );
  ViewsText__Done( &_this->DeviceNameText );
  MenuPushButton__Done( &_this->PushButton );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsBtDiscovarable_Init( SettingsBtDiscovarable _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  DeviceInterfaceBluetoothDeviceClass_OnSetDiscoverable( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ), 1 );
  ViewsText_OnSetString( &_this->DeviceNameText, DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceName( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )));
  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 1 );
}

/* 'C' function for method : 'Settings::BtDiscovarable.OnCancelSlot()' */
void SettingsBtDiscovarable_OnCancelSlot( SettingsBtDiscovarable _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 0 );
  DeviceInterfaceBluetoothDeviceClass_OnSetDiscoverable( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ), 0 );
  CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Settings::BtDiscovarable.UpdateCountDownTimeSlot()' */
void SettingsBtDiscovarable_UpdateCountDownTimeSlot( SettingsBtDiscovarable _this, 
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
      SecondStr = EwConcatString( EwLoadString( &_Const0011 ), EwNewStringInt( Second, 
      0, 10 ));
    }
    else
    {
      SecondStr = EwNewStringInt( Second, 0, 10 );
    }

    ViewsText_OnSetString( &_this->RemainTimeText, EwConcatString( EwConcatString( 
    EwNewStringInt( _this->CountDownTimeSec / 60, 0, 10 ), EwLoadString( &_Const0012 )), 
    SecondStr ));
  }
  else
  {
    EwPostSignal( EwNewSlot( _this, SettingsBtDiscovarable_OnCancelSlot ), ((XObject)_this ));
  }
}

/* Variants derived from the class : 'Settings::BtDiscovarable' */
EW_DEFINE_CLASS_VARIANTS( SettingsBtDiscovarable )
EW_END_OF_CLASS_VARIANTS( SettingsBtDiscovarable )

/* Virtual Method Table (VMT) for the class : 'Settings::BtDiscovarable' */
EW_DEFINE_CLASS( SettingsBtDiscovarable, ComponentsBaseMainBG, DiscoverableText, 
                 DiscoverableText, DiscoverableText, DiscoverableText, CountDownTimeSec, 
                 CountDownTimeSec, "Settings::BtDiscovarable" )
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( SettingsBtDiscovarable )

/* Initializer for the class 'Settings::BtConnectionResult' */
void SettingsBtConnectionResult__Init( SettingsBtConnectionResult _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsBtConnectionResult );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ConnectionResultHandler, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->CloseDialogTimer, &_this->_XObject, 0 );
  ViewsText__Init( &_this->ConnectingText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsBtConnectionResult );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0013 );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Text, 0 );
  CoreTimer_OnSetPeriod( &_this->CloseDialogTimer, 2000 );
  CoreRectView__OnSetBounds( &_this->ConnectingText, _Const0014 );
  ViewsText_OnSetAlignment( &_this->ConnectingText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ConnectingText, EwLoadString( &_Const0015 ));
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ConnectingText ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->ConnectionResultHandler.OnEvent = EwNewSlot( _this, SettingsBtConnectionResult_OnConnectionResultReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->ConnectionResultHandler, &EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->ConnectionResultSystemEvent );
  _this->CloseDialogTimer.OnTrigger = EwNewSlot( _this, SettingsBtConnectionResult_OnCloseDialogSlot );
  ViewsText_OnSetFont( &_this->ConnectingText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Settings::BtConnectionResult' */
void SettingsBtConnectionResult__ReInit( SettingsBtConnectionResult _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Text );
  CoreSystemEventHandler__ReInit( &_this->ConnectionResultHandler );
  CoreTimer__ReInit( &_this->CloseDialogTimer );
  ViewsText__ReInit( &_this->ConnectingText );
}

/* Finalizer method for the class 'Settings::BtConnectionResult' */
void SettingsBtConnectionResult__Done( SettingsBtConnectionResult _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Text );
  CoreSystemEventHandler__Done( &_this->ConnectionResultHandler );
  CoreTimer__Done( &_this->CloseDialogTimer );
  ViewsText__Done( &_this->ConnectingText );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void SettingsBtConnectionResult_OnConnectionResultReceivedSlot( SettingsBtConnectionResult _this, 
  XObject sender )
{
  XEnum ConnectionResult;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsText_OnSetVisible( &_this->ConnectingText, 0 );
  ConnectionResult = EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->ConnectionResult;

  switch ( ConnectionResult )
  {
    case EnumBtResultSUCCESS :
      ViewsText_OnSetString( &_this->Text, EwConcatString( EwConcatString( EwLoadString( 
      &_Const0016 ), _this->DeviceName ), EwLoadString( &_Const0017 )));
    break;

    case EnumBtResultTIMEOUT :
    {
      ViewsText_OnSetString( &_this->Text, EwConcatString( _this->DeviceName, EwLoadString( 
      &_Const0018 )));
      ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzLeft );
    }
    break;

    case EnumBtResultFAIL :
      ViewsText_OnSetString( &_this->Text, EwConcatString( EwConcatString( EwLoadString( 
      &_Const0016 ), _this->DeviceName ), EwLoadString( &_Const0019 )));
    break;

    default : 
      ViewsText_OnSetString( &_this->Text, 0 );
  }

  CoreTimer_OnSetEnabled( &_this->CloseDialogTimer, 1 );
}

/* 'C' function for method : 'Settings::BtConnectionResult.OnCloseDialogSlot()' */
void SettingsBtConnectionResult_OnCloseDialogSlot( SettingsBtConnectionResult _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->CloseDialogTimer, 0 );
  CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
  DeviceInterfaceBluetoothDeviceClass_OnSetRefreshPairedDeviceList( EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 1 );
}

/* 'C' function for method : 'Settings::BtConnectionResult.OnSetDeviceName()' */
void SettingsBtConnectionResult_OnSetDeviceName( SettingsBtConnectionResult _this, 
  XString value )
{
  if ( EwCompString( _this->DeviceName, value ) != 0 )
  {
    _this->DeviceName = EwShareString( value );
    ViewsText_OnSetString( &_this->ConnectingText, EwConcatString( EwConcatString( 
    EwLoadString( &_Const001A ), value ), EwLoadString( &_Const001B )));
  }
}

/* Variants derived from the class : 'Settings::BtConnectionResult' */
EW_DEFINE_CLASS_VARIANTS( SettingsBtConnectionResult )
EW_END_OF_CLASS_VARIANTS( SettingsBtConnectionResult )

/* Virtual Method Table (VMT) for the class : 'Settings::BtConnectionResult' */
EW_DEFINE_CLASS( SettingsBtConnectionResult, ComponentsBaseMainBG, Text, Text, Text, 
                 Text, DeviceName, _None, "Settings::BtConnectionResult" )
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( SettingsBtConnectionResult )

/* Initializer for the class 'Settings::BtMaxPairedDevice' */
void SettingsBtMaxPairedDevice__Init( SettingsBtMaxPairedDevice _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsBtMaxPairedDevice );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );
  MenuUpDownPushButtonSet__Init( &_this->UpDownPushButtonSet, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsBtMaxPairedDevice );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->Text, _Const001C );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const001D ));
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const001E );
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &_Const001F ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &_Const0020 ));
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UpDownPushButtonSet ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->UpDownPushButtonSet.OnUpButtonActivated = EwNewSlot( _this, SettingsBtMaxPairedDevice_OnYesSlot );
  _this->UpDownPushButtonSet.OnDownButtonActivated = EwNewSlot( _this, SettingsBtMaxPairedDevice_OnNoSlot );
}

/* Re-Initializer for the class 'Settings::BtMaxPairedDevice' */
void SettingsBtMaxPairedDevice__ReInit( SettingsBtMaxPairedDevice _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Text );
  MenuUpDownPushButtonSet__ReInit( &_this->UpDownPushButtonSet );
}

/* Finalizer method for the class 'Settings::BtMaxPairedDevice' */
void SettingsBtMaxPairedDevice__Done( SettingsBtMaxPairedDevice _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Text );
  MenuUpDownPushButtonSet__Done( &_this->UpDownPushButtonSet );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* 'C' function for method : 'Settings::BtMaxPairedDevice.OnYesSlot()' */
void SettingsBtMaxPairedDevice_OnYesSlot( SettingsBtMaxPairedDevice _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwPostSignal( _this->ToRemovePairedDevice, ((XObject)_this ));
  CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Settings::BtMaxPairedDevice.OnNoSlot()' */
void SettingsBtMaxPairedDevice_OnNoSlot( SettingsBtMaxPairedDevice _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* Variants derived from the class : 'Settings::BtMaxPairedDevice' */
EW_DEFINE_CLASS_VARIANTS( SettingsBtMaxPairedDevice )
EW_END_OF_CLASS_VARIANTS( SettingsBtMaxPairedDevice )

/* Virtual Method Table (VMT) for the class : 'Settings::BtMaxPairedDevice' */
EW_DEFINE_CLASS( SettingsBtMaxPairedDevice, ComponentsBaseMainBG, ToRemovePairedDevice, 
                 ToRemovePairedDevice, Text, Text, _None, _None, "Settings::BtMaxPairedDevice" )
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( SettingsBtMaxPairedDevice )

/* Initializer for the class 'Settings::SET17_BtPairedDeviceList' */
void SettingsSET17_BtPairedDeviceList__Init( SettingsSET17_BtPairedDeviceList _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET17_BtPairedDeviceList );

  /* ... then construct all embedded objects */
  CorePropertyObserver__Init( &_this->RefreshListObserver, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NoDataText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET17_BtPairedDeviceList );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 0 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  MenuVerticalMenu_OnSetArrowScrollBarVisible( &_this->Super1.Menu, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  CoreRectView__OnSetBounds( &_this->NoDataText, _Const0021 );
  ViewsText_OnSetString( &_this->NoDataText, EwLoadString( &_Const0022 ));
  CoreGroup__Add( _this, ((CoreView)&_this->NoDataText ), 0 );
  _this->RefreshListObserver.OnEvent = EwNewSlot( _this, SettingsSET17_BtPairedDeviceList_OnRefreshListSlot );
  CorePropertyObserver_OnSetOutlet( &_this->RefreshListObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), DeviceInterfaceBluetoothDeviceClass_OnGetRefreshPairedDeviceList, 
  DeviceInterfaceBluetoothDeviceClass_OnSetRefreshPairedDeviceList ));
  ViewsText_OnSetFont( &_this->NoDataText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Settings::SET17_BtPairedDeviceList' */
void SettingsSET17_BtPairedDeviceList__ReInit( SettingsSET17_BtPairedDeviceList _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CorePropertyObserver__ReInit( &_this->RefreshListObserver );
  ViewsText__ReInit( &_this->NoDataText );
}

/* Finalizer method for the class 'Settings::SET17_BtPairedDeviceList' */
void SettingsSET17_BtPairedDeviceList__Done( SettingsSET17_BtPairedDeviceList _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CorePropertyObserver__Done( &_this->RefreshListObserver );
  ViewsText__Done( &_this->NoDataText );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
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
void SettingsSET17_BtPairedDeviceList_UpdateViewState( SettingsSET17_BtPairedDeviceList _this, 
  XSet aState )
{
  CoreGroup_UpdateViewState((CoreGroup)_this, aState );

  if ((( aState & CoreViewStateDialog ) == CoreViewStateDialog ) && !(( aState & 
      CoreViewStatePendingFader ) == CoreViewStatePendingFader ))
  {
    SettingsSET17_BtPairedDeviceList_UpdatePairedDeviceNum( _this );
  }
}

/* 'C' function for method : 'Settings::SET17_BtPairedDeviceList.LoadItemClass()' */
XClass SettingsSET17_BtPairedDeviceList_LoadItemClass( SettingsSET17_BtPairedDeviceList _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

  return EW_CLASS( MenuItemCheckMark );
}

/* 'C' function for method : 'Settings::SET17_BtPairedDeviceList.LoadItemTitle()' */
XString SettingsSET17_BtPairedDeviceList_LoadItemTitle( SettingsSET17_BtPairedDeviceList _this, 
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

/* 'C' function for method : 'Settings::SET17_BtPairedDeviceList.OnItemActivate()' */
void SettingsSET17_BtPairedDeviceList_OnItemActivate( SettingsSET17_BtPairedDeviceList _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  MenuItemCheckMark BtDeviceItem;

  if ( aItemNo >= 0 )
    ;

  BtDeviceItem = EwCastObject( aMenuItem, MenuItemCheckMark );

  if ( BtDeviceItem != 0 )
  {
    SettingsSET19_BtPairedDeviceOperation Dialog = EwNewObject( SettingsSET19_BtPairedDeviceOperation, 
      0 );
    Dialog->PairedDeviceIndex = aItemNo;
    Dialog->DeviceName = EwShareString( BtDeviceItem->Super1.Title.String );
    Dialog->IsConnected = BtDeviceItem->Checked;
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)Dialog ), 0, 0, 0, 0, 
    0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* 'C' function for method : 'Settings::SET17_BtPairedDeviceList.LoadItemChecked()' */
XBool SettingsSET17_BtPairedDeviceList_LoadItemChecked( SettingsSET17_BtPairedDeviceList _this, 
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

/* 'C' function for method : 'Settings::SET17_BtPairedDeviceList.UpdatePairedDeviceNum()' */
void SettingsSET17_BtPairedDeviceList_UpdatePairedDeviceNum( SettingsSET17_BtPairedDeviceList _this )
{
  EwTrace( "%s", EwLoadString( &_Const0023 ));
  _this->PairedDeviceNum = DeviceInterfaceBluetoothDeviceClass_OnGetPairedDeviceNum( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ));
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, _this->PairedDeviceNum );

  if ( _this->PairedDeviceNum > 0 )
  {
    _this->Super1.Menu.Focusable = 1;
    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, _this->PairedDeviceNum 
    - 1 );
    ViewsText_OnSetVisible( &_this->NoDataText, 0 );
  }
  else
  {
    _this->Super1.Menu.Focusable = 0;
    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 0 );
    ViewsText_OnSetVisible( &_this->NoDataText, 1 );
  }
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void SettingsSET17_BtPairedDeviceList_OnRefreshListSlot( SettingsSET17_BtPairedDeviceList _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwTrace( "%s", EwLoadString( &_Const0024 ));
  SettingsSET17_BtPairedDeviceList_UpdatePairedDeviceNum( _this );
}

/* Variants derived from the class : 'Settings::SET17_BtPairedDeviceList' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET17_BtPairedDeviceList )
EW_END_OF_CLASS_VARIANTS( SettingsSET17_BtPairedDeviceList )

/* Virtual Method Table (VMT) for the class : 'Settings::SET17_BtPairedDeviceList' */
EW_DEFINE_CLASS( SettingsSET17_BtPairedDeviceList, MenuBaseMenuView, RefreshListObserver, 
                 RefreshListObserver, RefreshListObserver, RefreshListObserver, 
                 PairedDeviceNum, PairedDeviceNum, "Settings::SET17_BtPairedDeviceList" )
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
  SettingsSET17_BtPairedDeviceList_UpdateViewState,
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  SettingsSET17_BtPairedDeviceList_LoadItemClass,
  SettingsSET17_BtPairedDeviceList_LoadItemTitle,
  SettingsSET17_BtPairedDeviceList_OnItemActivate,
  SettingsSET17_BtPairedDeviceList_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
EW_END_OF_CLASS( SettingsSET17_BtPairedDeviceList )

/* Initializer for the class 'Settings::SET19_BtPairedDeviceOperation' */
void SettingsSET19_BtPairedDeviceOperation__Init( SettingsSET19_BtPairedDeviceOperation _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET19_BtPairedDeviceOperation );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET19_BtPairedDeviceOperation );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
}

/* Re-Initializer for the class 'Settings::SET19_BtPairedDeviceOperation' */
void SettingsSET19_BtPairedDeviceOperation__ReInit( SettingsSET19_BtPairedDeviceOperation _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Settings::SET19_BtPairedDeviceOperation' */
void SettingsSET19_BtPairedDeviceOperation__Done( SettingsSET19_BtPairedDeviceOperation _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Settings::SET19_BtPairedDeviceOperation.LoadItemClass()' */
XClass SettingsSET19_BtPairedDeviceOperation_LoadItemClass( SettingsSET19_BtPairedDeviceOperation _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

  return EW_CLASS( MenuItemBase );
}

/* 'C' function for method : 'Settings::SET19_BtPairedDeviceOperation.LoadItemTitle()' */
XString SettingsSET19_BtPairedDeviceOperation_LoadItemTitle( SettingsSET19_BtPairedDeviceOperation _this, 
  XInt32 aItemNo )
{
  XString title;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  title = 0;

  switch ( aItemNo )
  {
    case 0 :
      title = EwLoadString( &StringsSET19_delete_pairing );
    break;

    case 1 :
      title = EwLoadString( &StringsSET19_connect );
    break;

    case 2 :
      title = EwLoadString( &StringsSET19_disconnect );
    break;

    default : 
      ;
  }

  return title;
}

/* 'C' function for method : 'Settings::SET19_BtPairedDeviceOperation.OnItemActivate()' */
void SettingsSET19_BtPairedDeviceOperation_OnItemActivate( SettingsSET19_BtPairedDeviceOperation _this, 
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
        SettingsBtDeleteBleDevice Dialog = EwNewObject( SettingsBtDeleteBleDevice, 
          0 );
        Dialog->DeviceName = EwShareString( _this->DeviceName );
        CoreGroup_SwitchToDialog( _this->Super6.Owner, ((CoreGroup)Dialog ), 0, 
        0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
        CoreGroup_InvalidateViewState( _this->Super6.Owner );
      }
      else
      {
        CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 
        0, EwNullSlot, EwNullSlot, 0 );
      }
    }
    break;

    case 1 :
    {
      SettingsBtConnectionResult Dialog = EwNewObject( SettingsBtConnectionResult, 
        0 );
      SettingsBtConnectionResult_OnSetDeviceName( Dialog, _this->DeviceName );
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
      CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 
      0, EwNullSlot, EwNullSlot, 0 );
      DeviceInterfaceBluetoothDeviceClass_OnSetRefreshPairedDeviceList( EwGetAutoObject( 
      &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 1 );
    }
    break;

    default : 
      EwTrace( "%s%*", 0, aMenuItem );
  }
}

/* 'C' function for method : 'Settings::SET19_BtPairedDeviceOperation.LoadItemEnabled()' */
XBool SettingsSET19_BtPairedDeviceOperation_LoadItemEnabled( SettingsSET19_BtPairedDeviceOperation _this, 
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

/* Variants derived from the class : 'Settings::SET19_BtPairedDeviceOperation' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET19_BtPairedDeviceOperation )
EW_END_OF_CLASS_VARIANTS( SettingsSET19_BtPairedDeviceOperation )

/* Virtual Method Table (VMT) for the class : 'Settings::SET19_BtPairedDeviceOperation' */
EW_DEFINE_CLASS( SettingsSET19_BtPairedDeviceOperation, MenuBaseMenuView, DeviceName, 
                 DeviceName, DeviceName, DeviceName, DeviceName, PairedDeviceIndex, 
                 "Settings::SET19_BtPairedDeviceOperation" )
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  SettingsSET19_BtPairedDeviceOperation_LoadItemClass,
  SettingsSET19_BtPairedDeviceOperation_LoadItemTitle,
  SettingsSET19_BtPairedDeviceOperation_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  SettingsSET19_BtPairedDeviceOperation_LoadItemEnabled,
EW_END_OF_CLASS( SettingsSET19_BtPairedDeviceOperation )

/* Initializer for the class 'Settings::BtDeleteBleDevice' */
void SettingsBtDeleteBleDevice__Init( SettingsBtDeleteBleDevice _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsBtDeleteBleDevice );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );
  MenuPushButton__Init( &_this->PushButton, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsBtDeleteBleDevice );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0025 );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Text, 0 );
  _this->DialogString1 = EwShareString( EwLoadString( &_Const0026 ));
  _this->DialogString2 = EwShareString( EwLoadString( &_Const0027 ));
  CoreRectView__OnSetBounds( &_this->PushButton, _Const000F );
  MenuPushButton_OnSetTitle( &_this->PushButton, EwLoadString( &_Const0028 ));
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PushButton ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->PushButton.OnActivate = EwNewSlot( _this, SettingsBtDeleteBleDevice_OnOkSlot );

  /* Call the user defined constructor */
  SettingsBtDeleteBleDevice_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::BtDeleteBleDevice' */
void SettingsBtDeleteBleDevice__ReInit( SettingsBtDeleteBleDevice _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Text );
  MenuPushButton__ReInit( &_this->PushButton );
}

/* Finalizer method for the class 'Settings::BtDeleteBleDevice' */
void SettingsBtDeleteBleDevice__Done( SettingsBtDeleteBleDevice _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Text );
  MenuPushButton__Done( &_this->PushButton );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsBtDeleteBleDevice_Init( SettingsBtDeleteBleDevice _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  ViewsText_OnSetString( &_this->Text, EwConcatString( EwConcatString( _this->DialogString1, 
  _this->DeviceName ), _this->DialogString2 ));
}

/* 'C' function for method : 'Settings::BtDeleteBleDevice.OnOkSlot()' */
void SettingsBtDeleteBleDevice_OnOkSlot( SettingsBtDeleteBleDevice _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
  DeviceInterfaceBluetoothDeviceClass_OnSetRefreshPairedDeviceList( EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 1 );
}

/* Variants derived from the class : 'Settings::BtDeleteBleDevice' */
EW_DEFINE_CLASS_VARIANTS( SettingsBtDeleteBleDevice )
EW_END_OF_CLASS_VARIANTS( SettingsBtDeleteBleDevice )

/* Virtual Method Table (VMT) for the class : 'Settings::BtDeleteBleDevice' */
EW_DEFINE_CLASS( SettingsBtDeleteBleDevice, ComponentsBaseMainBG, Text, Text, Text, 
                 Text, DeviceName, _None, "Settings::BtDeleteBleDevice" )
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( SettingsBtDeleteBleDevice )

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
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0029 );
  CoreRectView__OnSetBounds( &_this->StatusText, _Const002A );
  ViewsText_OnSetWrapText( &_this->StatusText, 1 );
  ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const002B ));
  ViewsText_OnSetColor( &_this->StatusText, _Const002C );
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
      ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const002D ));
      CoreTimer_OnSetEnabled( &_this->RemoveDialogTimer, 1 );
    }
    break;

    case EnumBtFwStatusUPDATE_ABORT :
    {
      ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const002E ));
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
  CoreRectView__OnSetBounds( _this, _Const0000 );
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->QrCode, _Const002F );
  ViewsImage_OnSetAlignment( &_this->QrCode, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  _this->PixelPerModule = 1;
  CoreRectView__OnSetBounds( &_this->PixelText, _Const0030 );
  ViewsText_OnSetAlignment( &_this->PixelText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->PixelText, 0 );
  CoreRectView__OnSetBounds( &_this->QrCodeWidthText, _Const0031 );
  ViewsText_OnSetAlignment( &_this->QrCodeWidthText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->QrCodeWidthText, 0 );
  CoreRectView__OnSetBounds( &_this->QrCodeContent, _Const0032 );
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
    EwTrace( "%s", EwLoadString( &_Const0033 ));
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
    EwTrace( "%s", EwLoadString( &_Const0034 ));
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
  ResourcesExternBitmap ), EwConcatString( EwLoadString( &_Const0035 ), EwNewStringInt( 
  _this->PixelPerModule, 0, 10 )));
  ViewsText_OnSetString( &_this->PixelText, EwConcatString( EwNewStringInt( _this->PixelPerModule, 
  0, 10 ), EwLoadString( &_Const0036 )));
  QrCodeWidth = ( 33 * _this->PixelPerModule ) * 0.019350f;
  ViewsText_OnSetString( &_this->QrCodeWidthText, EwConcatString( EwConcatString( 
  EwLoadString( &_Const0037 ), EwNewStringFloat( QrCodeWidth, 0, -1 )), EwLoadString( 
  &_Const0038 )));
  ViewsText_OnSetString( &_this->QrCodeContent, EwConcatString( EwLoadString( &_Const0039 ), 
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
EW_END_OF_CLASS( SettingsSET30_QRCode )

/* Embedded Wizard */
