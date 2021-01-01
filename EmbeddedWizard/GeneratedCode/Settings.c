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
#include "_CorePropertyObserver.h"
#include "_CoreRoot.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DevelopmentDEV_Main.h"
#include "_DeviceInterfaceBluetoothDeviceClass.h"
#include "_DeviceInterfaceBluetoothPairedDeviceInfo.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_MenuItemBase.h"
#include "_MenuItemCheckMark.h"
#include "_MenuItemCheckbox.h"
#include "_MenuPushButton.h"
#include "_MenuUpDownPushButtonSet.h"
#include "_MenuVerticalMenu.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesExternBitmap.h"
#include "_ResourcesFont.h"
#include "_SettingsBluetooth.h"
#include "_SettingsBtConnectionResult.h"
#include "_SettingsBtDeleteBleDevice.h"
#include "_SettingsBtDiscovarable.h"
#include "_SettingsBtFwUpdateDialog.h"
#include "_SettingsBtMaxPairedDevice.h"
#include "_SettingsBtPairedDeviceOperation.h"
#include "_SettingsConnection.h"
#include "_SettingsSET01_MainSettingMenu.h"
#include "_SettingsSET17_BtPairedDeviceList.h"
#include "_SettingsSET30_QRCode.h"
#include "_SettingsSystemInfo.h"
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
  0x0000042C, /* ratio 52.43 % */
  0xB8001900, 0x00084452, 0x00EA0036, 0x0E800328, 0x1B0F3780, 0xA0034002, 0x458186E2,
  0x0308009A, 0x0042CD60, 0x01CC0020, 0x44A44790, 0x02406D86, 0x8D200320, 0xED1131C9,
  0x11B3947C, 0x1F839880, 0x08C0562B, 0x9A4BA6A5, 0x2486590C, 0x4BA651F2, 0x32430C98,
  0x61D26969, 0x0D180CC5, 0xD0C85422, 0x0E884421, 0xA8E48629, 0x984AAAD0, 0x1000DD10,
  0x53A610CB, 0x16301A00, 0x001559C1, 0x614CB0CD, 0x93329C86, 0x21844729, 0x9004249D,
  0x9A4326F2, 0xA4602715, 0xC48CD10B, 0xAA81353B, 0xA47752B4, 0x1515B84B, 0x40018C60,
  0x00198006, 0x01A80068, 0x8AE6C6C0, 0x05442C00, 0x61254540, 0x221D8600, 0x2438A8E6,
  0x1F26BFE3, 0x02FD058F, 0x88885EA3, 0x3974B243, 0x99002C12, 0x44DE39B0, 0x4926D498,
  0xD6275895, 0x6F75290D, 0xB512ABDB, 0xF71A2CAE, 0xA01748E3, 0xED2C601B, 0xE2716532,
  0x00EA25A8, 0x4D76C08D, 0x57C600EF, 0xF311803C, 0xE0001878, 0x71804C57, 0x48B14D48,
  0x80245671, 0xFE003E51, 0x8007A904, 0x2445F503, 0x98005916, 0x675894C5, 0x811154A8,
  0x95473504, 0x0565D044, 0x80226480, 0x19460106, 0x6F92164A, 0x60A47E07, 0x57600050,
  0x85180E51, 0x624A9BC4, 0x42121441, 0xDB083570, 0x56CE0687, 0x85D349D6, 0xCA8E95E4,
  0x729C0715, 0xA255B147, 0xF4713D4A, 0x392E4A93, 0x0D0015B4, 0x899B391A, 0xE1C06000,
  0x88D55F85, 0x89B282A0, 0x4E619215, 0x9412C782, 0xD708140F, 0xC4B91295, 0xEE194AA0,
  0x6B456537, 0x4711A411, 0x57B8B078, 0x6445CB5F, 0x05D46E98, 0x2148D0C9, 0x4C11C629,
  0x5D889114, 0x947C5248, 0x863F4412, 0x86715704, 0x4A97C5BD, 0xD6E4F870, 0xC74D4247,
  0x7E095190, 0x235322F4, 0x6803F439, 0x85946006, 0x6015A075, 0x9D91441E, 0x1C4B12AA,
  0x4551C439, 0x05541252, 0x8AB29100, 0x294C9163, 0x975112C6, 0x5E90C756, 0x1154A50A,
  0x313D1805, 0x350CA15B, 0x4B452A4A, 0x5D10E8AD, 0x1A044A30, 0x00010168, 0x00000000
};

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault1[] =
{
  0x000002C4, /* ratio 53.11 % */
  0xB8002300, 0x80088452, 0x1CD80032, 0x21674004, 0x00500008, 0x06900184, 0x008A1C80,
  0x033800DC, 0x8182A3A0, 0x78008645, 0xC224B193, 0x023B0C31, 0x60D20068, 0x500039C5,
  0xF1A8D492, 0x2B8ECA64, 0x88544640, 0x844C2270, 0xE42CC90F, 0x4A681299, 0xC0010E34,
  0x62F18891, 0x1F1C8D45, 0xF249B45E, 0x3387D0A2, 0x33CC3C01, 0x8B1D4012, 0x64809B2A,
  0x436BB5A1, 0xDE2F08A4, 0x0013F8C1, 0xBF5DADD9, 0x94C36C3E, 0x248D43EB, 0x93143E1B,
  0xA25F2274, 0x94921B0F, 0xC96650BA, 0x3E53319A, 0x6CF15B5C, 0x35182659, 0x722001AE,
  0x4FB2D5A2, 0x6A363ACB, 0xAFCA6BC6, 0x50B80153, 0x13E40059, 0x9E544B00, 0x29455900,
  0x1B13A100, 0x400A8E66, 0x652A0008, 0x48BC573B, 0x85E5AD77, 0xF5135D6F, 0xC637D499,
  0xAB93A386, 0x35DAC0F4, 0x6D65A2EC, 0x1BA87EE3, 0xA1A66F6C, 0xBBA61A1F, 0x84436894,
  0x5F34351D, 0xF47BFCFA, 0x029BB9DB, 0x339BFEB8, 0x3B0A8AD3, 0x7DD9004A, 0x4BA37121,
  0xF984C343, 0x8ED2EBF0, 0x9097D014, 0xF5B4007D, 0xED0B7E50, 0x24509657, 0x4751A5AD,
  0x05148009, 0xD6505200, 0x01E05095, 0x0F412110, 0x1E115445, 0x11F4A943, 0x24605741,
  0x943A6394, 0x200191D5, 0x4A9EB769, 0x61341201, 0x44890F85, 0x19658612, 0x3B7991A6,
  0x47E29002, 0x1014A92A, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0001 = {{ 0, 36 }, { 480, 272 }};
static const XStringRes _Const0002 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0003 = { _StringsDefault0, 0x000E };
static const XStringRes _Const0004 = { _StringsDefault0, 0x0029 };
static const XStringRes _Const0005 = { _StringsDefault0, 0x003E };
static const XRect _Const0006 = {{ 82, 49 }, { 369, 79 }};
static const XStringRes _Const0007 = { _StringsDefault0, 0x0057 };
static const XRect _Const0008 = {{ 120, 120 }, { 340, 145 }};
static const XStringRes _Const0009 = { _StringsDefault0, 0x0071 };
static const XRect _Const000A = {{ 90, 80 }, { 362, 110 }};
static const XStringRes _Const000B = { _StringsDefault0, 0x0084 };
static const XRect _Const000C = {{ 132, 150 }, { 328, 180 }};
static const XRect _Const000D = {{ 86, 190 }, { 366, 215 }};
static const XStringRes _Const000E = { _StringsDefault0, 0x008E };
static const XRect _Const000F = {{ 110, 220 }, { 343, 250 }};
static const XRect _Const0010 = {{ 60, 34 }, { 410, 110 }};
static const XStringRes _Const0011 = { _StringsDefault0, 0x00A4 };
static const XRect _Const0012 = {{ 130, 153 }, { 280, 193 }};
static const XStringRes _Const0013 = { _StringsDefault0, 0x00D3 };
static const XRect _Const0014 = {{ 120, 113 }, { 240, 153 }};
static const XStringRes _Const0015 = { _StringsDefault0, 0x00E0 };
static const XRect _Const0016 = {{ 260, 153 }, { 340, 193 }};
static const XStringRes _Const0017 = { _StringsDefault0, 0x00E8 };
static const XRect _Const0018 = {{ 230, 113 }, { 400, 153 }};
static const XRect _Const0019 = {{ 165, 219 }, { 315, 259 }};
static const XStringRes _Const001A = { _StringsDefault0, 0x00EF };
static const XStringRes _Const001B = { _StringsDefault0, 0x00F8 };
static const XStringRes _Const001C = { _StringsDefault0, 0x00FC };
static const XRect _Const001D = {{ 40, 40 }, { 440, 230 }};
static const XRect _Const001E = {{ 30, 90 }, { 460, 140 }};
static const XStringRes _Const001F = { _StringsDefault0, 0x0100 };
static const XStringRes _Const0020 = { _StringsDefault0, 0x010E };
static const XStringRes _Const0021 = { _StringsDefault0, 0x011C };
static const XStringRes _Const0022 = { _StringsDefault0, 0x012C };
static const XStringRes _Const0023 = { _StringsDefault0, 0x0165 };
static const XStringRes _Const0024 = { _StringsDefault0, 0x017D };
static const XStringRes _Const0025 = { _StringsDefault0, 0x018C };
static const XRect _Const0026 = {{ 20, 70 }, { 460, 150 }};
static const XStringRes _Const0027 = { _StringsDefault0, 0x0190 };
static const XRect _Const0028 = {{ 165, 176 }, { 315, 259 }};
static const XStringRes _Const0029 = { _StringsDefault0, 0x01D5 };
static const XStringRes _Const002A = { _StringsDefault0, 0x01DB };
static const XRect _Const002B = {{ 10, 50 }, { 470, 236 }};
static const XStringRes _Const002C = { _StringsDefault0, 0x01E0 };
static const XStringRes _Const002D = { _StringsDefault0, 0x01EA };
static const XStringRes _Const002E = { _StringsDefault0, 0x0202 };
static const XStringRes _Const002F = { _StringsDefault1, 0x0002 };
static const XStringRes _Const0030 = { _StringsDefault1, 0x0013 };
static const XStringRes _Const0031 = { _StringsDefault1, 0x001D };
static const XRect _Const0032 = {{ 40, 50 }, { 440, 200 }};
static const XStringRes _Const0033 = { _StringsDefault1, 0x002A };
static const XStringRes _Const0034 = { _StringsDefault1, 0x0055 };
static const XStringRes _Const0035 = { _StringsDefault1, 0x00A2 };
static const XColor _Const0036 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0037 = {{ 80, 60 }, { 380, 210 }};
static const XStringRes _Const0038 = { _StringsDefault1, 0x00A7 };
static const XColor _Const0039 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XStringRes _Const003A = { _StringsDefault1, 0x00CE };
static const XStringRes _Const003B = { _StringsDefault1, 0x00EC };
static const XRect _Const003C = {{ 20, 98 }, { 207, 227 }};
static const XRect _Const003D = {{ 210, 85 }, { 398, 135 }};
static const XRect _Const003E = {{ 210, 192 }, { 442, 240 }};
static const XRect _Const003F = {{ 210, 137 }, { 463, 192 }};
static const XStringRes _Const0040 = { _StringsDefault1, 0x0106 };
static const XStringRes _Const0041 = { _StringsDefault1, 0x0118 };
static const XStringRes _Const0042 = { _StringsDefault1, 0x012C };
static const XStringRes _Const0043 = { _StringsDefault1, 0x0135 };
static const XStringRes _Const0044 = { _StringsDefault1, 0x013E };
static const XStringRes _Const0045 = { _StringsDefault1, 0x0148 };
static const XStringRes _Const0046 = { _StringsDefault1, 0x014E };

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

  /* ... then construct all embedded objects */
  MenuVerticalMenu__Init( &_this->Menu, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET01_MainSettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Menu, _Const0001 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 9 );
  _this->Settings[ 0 ] = EnumMainSettingItemConnection;
  _this->Settings[ 1 ] = EnumMainSettingItemClock;
  _this->Settings[ 2 ] = EnumMainSettingItemBrightness;
  _this->Settings[ 3 ] = EnumMainSettingItemUnit;
  _this->Settings[ 4 ] = EnumMainSettingItemGripWarmerSettings;
  _this->Settings[ 5 ] = EnumMainSettingItemSeatHeaterSettings;
  _this->Settings[ 6 ] = EnumMainSettingItemSystemInfo;
  _this->Settings[ 7 ] = EnumMainSettingItemLegalInfo;
  _this->Settings[ 8 ] = EnumMainSettingItemReset;
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );

  /* Call the user defined constructor */
  SettingsSET01_MainSettingMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SET01_MainSettingMenu' */
void SettingsSET01_MainSettingMenu__ReInit( SettingsSET01_MainSettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  MenuVerticalMenu__ReInit( &_this->Menu );
}

/* Finalizer method for the class 'Settings::SET01_MainSettingMenu' */
void SettingsSET01_MainSettingMenu__Done( SettingsSET01_MainSettingMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  MenuVerticalMenu__Done( &_this->Menu );

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

  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, NoOfItems );
}

/* 'C' function for method : 'Settings::SET01_MainSettingMenu.OnShortHomeKeyActivated()' */
void SettingsSET01_MainSettingMenu_OnShortHomeKeyActivated( SettingsSET01_MainSettingMenu _this )
{
  CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
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
        Dialog = ((ComponentsBaseComponent)EwNewObject( SettingsConnection, 0 ));
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
      Dialog = ((ComponentsBaseComponent)EwNewObject( SettingsSystemInfo, 0 ));
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
    ComponentsBaseComponent_SlideInDialog((ComponentsBaseComponent)_this, ((CoreGroup)Dialog ));
  }
}

/* Variants derived from the class : 'Settings::SET01_MainSettingMenu' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET01_MainSettingMenu )
EW_END_OF_CLASS_VARIANTS( SettingsSET01_MainSettingMenu )

/* Virtual Method Table (VMT) for the class : 'Settings::SET01_MainSettingMenu' */
EW_DEFINE_CLASS( SettingsSET01_MainSettingMenu, MenuBaseMenuView, Menu, Menu, Menu, 
                 Menu, Settings, Settings, "Settings::SET01_MainSettingMenu" )
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
  SettingsSET01_MainSettingMenu_OnShortHomeKeyActivated,
  SettingsSET01_MainSettingMenu_LoadItemClass,
  SettingsSET01_MainSettingMenu_LoadItemTitle,
  SettingsSET01_MainSettingMenu_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
EW_END_OF_CLASS( SettingsSET01_MainSettingMenu )

/* Initializer for the class 'Settings::Connection' */
void SettingsConnection__Init( SettingsConnection _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsConnection );

  /* ... then construct all embedded objects */
  MenuVerticalMenu__Init( &_this->Menu, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsConnection );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Menu, _Const0001 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 1 );
  _this->ItemClassArray[ 0 ] = EW_CLASS( MenuItemBase );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0002 ));
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );
}

/* Re-Initializer for the class 'Settings::Connection' */
void SettingsConnection__ReInit( SettingsConnection _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  MenuVerticalMenu__ReInit( &_this->Menu );
}

/* Finalizer method for the class 'Settings::Connection' */
void SettingsConnection__Done( SettingsConnection _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  MenuVerticalMenu__Done( &_this->Menu );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Settings::Connection.OnShortHomeKeyActivated()' */
void SettingsConnection_OnShortHomeKeyActivated( SettingsConnection _this )
{
  CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Settings::Connection.LoadItemClass()' */
XClass SettingsConnection_LoadItemClass( SettingsConnection _this, XInt32 aItemNo )
{
  XClass ClassType = 0;

  if ( aItemNo < 1 )
  {
    ClassType = _this->ItemClassArray[ EwCheckIndex( aItemNo, 1 )];
  }

  return ClassType;
}

/* 'C' function for method : 'Settings::Connection.LoadItemTitle()' */
XString SettingsConnection_LoadItemTitle( SettingsConnection _this, XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < 1 )
  {
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 1 )];
  }

  return title;
}

/* 'C' function for method : 'Settings::Connection.OnItemActivate()' */
void SettingsConnection_OnItemActivate( SettingsConnection _this, XInt32 aItemNo, 
  MenuItemBase aMenuItem )
{
  if ( aMenuItem == 0 )
    ;

  switch ( aItemNo )
  {
    case 0 :
      ComponentsBaseComponent_SlideInDialog((ComponentsBaseComponent)_this, ((CoreGroup)EwNewObject( 
      SettingsBluetooth, 0 )));
    break;

    case 1 :
      ;
    break;

    default : 
      ;
  }
}

/* Variants derived from the class : 'Settings::Connection' */
EW_DEFINE_CLASS_VARIANTS( SettingsConnection )
EW_END_OF_CLASS_VARIANTS( SettingsConnection )

/* Virtual Method Table (VMT) for the class : 'Settings::Connection' */
EW_DEFINE_CLASS( SettingsConnection, MenuBaseMenuView, Menu, Menu, Menu, Menu, ItemTitleArray, 
                 ItemClassArray, "Settings::Connection" )
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
  SettingsConnection_OnShortHomeKeyActivated,
  SettingsConnection_LoadItemClass,
  SettingsConnection_LoadItemTitle,
  SettingsConnection_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
EW_END_OF_CLASS( SettingsConnection )

/* Initializer for the class 'Settings::Bluetooth' */
void SettingsBluetooth__Init( SettingsBluetooth _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsBluetooth );

  /* ... then construct all embedded objects */
  MenuVerticalMenu__Init( &_this->Menu, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsBluetooth );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Menu, _Const0001 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 4 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Menu, 4 );
  _this->ItemClassArray[ 0 ] = EW_CLASS( MenuItemCheckbox );
  _this->ItemClassArray[ 1 ] = EW_CLASS( MenuItemBase );
  _this->ItemClassArray[ 2 ] = EW_CLASS( MenuItemBase );
  _this->ItemClassArray[ 3 ] = EW_CLASS( MenuItemCheckbox );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0002 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0003 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0004 ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const0005 ));
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );

  /* Call the user defined constructor */
  SettingsBluetooth_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::Bluetooth' */
void SettingsBluetooth__ReInit( SettingsBluetooth _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  MenuVerticalMenu__ReInit( &_this->Menu );
}

/* Finalizer method for the class 'Settings::Bluetooth' */
void SettingsBluetooth__Done( SettingsBluetooth _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  MenuVerticalMenu__Done( &_this->Menu );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsBluetooth_Init( SettingsBluetooth _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  DeviceInterfaceBluetoothDeviceClass_GetBluetoothEnable( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ));
}

/* 'C' function for method : 'Settings::Bluetooth.OnShortHomeKeyActivated()' */
void SettingsBluetooth_OnShortHomeKeyActivated( SettingsBluetooth _this )
{
  CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Settings::Bluetooth.LoadItemClass()' */
XClass SettingsBluetooth_LoadItemClass( SettingsBluetooth _this, XInt32 aItemNo )
{
  XClass ClassType = 0;

  if ( aItemNo < 4 )
  {
    ClassType = _this->ItemClassArray[ EwCheckIndex( aItemNo, 4 )];
  }

  return ClassType;
}

/* 'C' function for method : 'Settings::Bluetooth.LoadItemTitle()' */
XString SettingsBluetooth_LoadItemTitle( SettingsBluetooth _this, XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < 4 )
  {
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 4 )];
  }

  return title;
}

/* 'C' function for method : 'Settings::Bluetooth.OnItemActivate()' */
void SettingsBluetooth_OnItemActivate( SettingsBluetooth _this, XInt32 aItemNo, 
  MenuItemBase aMenuItem )
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
      MenuVerticalMenu_InvalidateItems( &_this->Menu, 1, 4 );
    }
    break;

    case 1 :
    {
      if ( DeviceInterfaceBluetoothDeviceClass_OnGetIsMaxPairedDevice( EwGetAutoObject( 
          &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )))
      {
        SettingsBtMaxPairedDevice MaxPairedDevDialog = EwNewObject( SettingsBtMaxPairedDevice, 
          0 );
        MaxPairedDevDialog->ToRemovePairedDevice = EwNewSlot( _this, SettingsBluetooth_ShowPairedDeviceListSlot );
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
      EwSignal( EwNewSlot( _this, SettingsBluetooth_ShowPairedDeviceListSlot ), 
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

/* 'C' function for method : 'Settings::Bluetooth.LoadItemChecked()' */
XBool SettingsBluetooth_LoadItemChecked( SettingsBluetooth _this, XInt32 aItemNo )
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

/* 'C' function for method : 'Settings::Bluetooth.LoadItemEnabled()' */
XBool SettingsBluetooth_LoadItemEnabled( SettingsBluetooth _this, XInt32 aItemNo )
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

/* 'C' function for method : 'Settings::Bluetooth.ShowPairedDeviceListSlot()' */
void SettingsBluetooth_ShowPairedDeviceListSlot( SettingsBluetooth _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsSET17_BtPairedDeviceList, 
  0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* Variants derived from the class : 'Settings::Bluetooth' */
EW_DEFINE_CLASS_VARIANTS( SettingsBluetooth )
EW_END_OF_CLASS_VARIANTS( SettingsBluetooth )

/* Virtual Method Table (VMT) for the class : 'Settings::Bluetooth' */
EW_DEFINE_CLASS( SettingsBluetooth, MenuBaseMenuView, Menu, Menu, Menu, Menu, ItemTitleArray, 
                 ItemClassArray, "Settings::Bluetooth" )
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
  SettingsBluetooth_OnShortHomeKeyActivated,
  SettingsBluetooth_LoadItemClass,
  SettingsBluetooth_LoadItemTitle,
  SettingsBluetooth_OnItemActivate,
  SettingsBluetooth_LoadItemChecked,
  SettingsBluetooth_LoadItemEnabled,
EW_END_OF_CLASS( SettingsBluetooth )

/* Initializer for the class 'Settings::SystemInfo' */
void SettingsSystemInfo__Init( SettingsSystemInfo _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSystemInfo );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->ESN, &_this->_XObject, 0 );
  ViewsText__Init( &_this->SoftwareVersionTitle, &_this->_XObject, 0 );
  ViewsText__Init( &_this->EsnText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->SoftwareVersionText, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->EsnObserver, &_this->_XObject, 0 );
  ViewsText__Init( &_this->BtSwVersionTitle, &_this->_XObject, 0 );
  ViewsText__Init( &_this->BtSwVersionText, &_this->_XObject, 0 );
  CoreKeyPressHandler__Init( &_this->MagicKeyHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSystemInfo );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->ESN, _Const0006 );
  ViewsText_OnSetString( &_this->ESN, EwLoadString( &_Const0007 ));
  CoreRectView__OnSetBounds( &_this->SoftwareVersionTitle, _Const0008 );
  ViewsText_OnSetString( &_this->SoftwareVersionTitle, EwLoadString( &_Const0009 ));
  CoreRectView__OnSetBounds( &_this->EsnText, _Const000A );
  ViewsText_OnSetString( &_this->EsnText, EwLoadString( &_Const000B ));
  CoreRectView__OnSetBounds( &_this->SoftwareVersionText, _Const000C );
  ViewsText_OnSetString( &_this->SoftwareVersionText, DeviceInterfaceSystemDeviceClass_OnGetSoftwareVersion( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
  CoreRectView__OnSetBounds( &_this->BtSwVersionTitle, _Const000D );
  ViewsText_OnSetString( &_this->BtSwVersionTitle, EwLoadString( &_Const000E ));
  CoreRectView__OnSetBounds( &_this->BtSwVersionText, _Const000F );
  ViewsText_OnSetString( &_this->BtSwVersionText, DeviceInterfaceSystemDeviceClass_OnGetSoftwareVersion( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
  _this->MagicKeyHandler.Filter = CoreKeyCodeF9;
  CoreGroup__Add( _this, ((CoreView)&_this->ESN ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SoftwareVersionTitle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->EsnText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SoftwareVersionText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BtSwVersionTitle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BtSwVersionText ), 0 );
  ViewsText_OnSetFont( &_this->ESN, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->SoftwareVersionTitle, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->EsnText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->SoftwareVersionText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->EsnObserver.OnEvent = EwNewSlot( _this, SettingsSystemInfo_OnEsnReceivedSlot );
  CorePropertyObserver_OnSetOutlet( &_this->EsnObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ), DeviceInterfaceSystemDeviceClass_OnGetESN, 
  DeviceInterfaceSystemDeviceClass_OnSetESN ));
  ViewsText_OnSetFont( &_this->BtSwVersionTitle, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->BtSwVersionText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->MagicKeyHandler.OnRelease = EwNewSlot( _this, SettingsSystemInfo_OnMagicKeyReleaseSlot );

  /* Call the user defined constructor */
  SettingsSystemInfo_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::SystemInfo' */
void SettingsSystemInfo__ReInit( SettingsSystemInfo _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->ESN );
  ViewsText__ReInit( &_this->SoftwareVersionTitle );
  ViewsText__ReInit( &_this->EsnText );
  ViewsText__ReInit( &_this->SoftwareVersionText );
  CorePropertyObserver__ReInit( &_this->EsnObserver );
  ViewsText__ReInit( &_this->BtSwVersionTitle );
  ViewsText__ReInit( &_this->BtSwVersionText );
  CoreKeyPressHandler__ReInit( &_this->MagicKeyHandler );
}

/* Finalizer method for the class 'Settings::SystemInfo' */
void SettingsSystemInfo__Done( SettingsSystemInfo _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->ESN );
  ViewsText__Done( &_this->SoftwareVersionTitle );
  ViewsText__Done( &_this->EsnText );
  ViewsText__Done( &_this->SoftwareVersionText );
  CorePropertyObserver__Done( &_this->EsnObserver );
  ViewsText__Done( &_this->BtSwVersionTitle );
  ViewsText__Done( &_this->BtSwVersionText );
  CoreKeyPressHandler__Done( &_this->MagicKeyHandler );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsSystemInfo_Init( SettingsSystemInfo _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  ViewsText_OnSetString( &_this->EsnText, DeviceInterfaceSystemDeviceClass_OnGetESN( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
  ViewsText_OnSetString( &_this->SoftwareVersionText, DeviceInterfaceSystemDeviceClass_OnGetSoftwareVersion( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
  ViewsText_OnSetString( &_this->BtSwVersionText, DeviceInterfaceSystemDeviceClass_OnGetBtSoftwareVersion( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
}

/* 'C' function for method : 'Settings::SystemInfo.OnShortEnterKeyActivated()' */
void SettingsSystemInfo_OnShortEnterKeyActivated( SettingsSystemInfo _this )
{
  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsSET30_QRCode, 
  0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Settings::SystemInfo.OnShortHomeKeyActivated()' */
void SettingsSystemInfo_OnShortHomeKeyActivated( SettingsSystemInfo _this )
{
  CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Settings::SystemInfo.OnMagicKeyReleaseSlot()' */
void SettingsSystemInfo_OnMagicKeyReleaseSlot( SettingsSystemInfo _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( !EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->IsHopperTestMode )
  {
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_Main, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void SettingsSystemInfo_OnEsnReceivedSlot( SettingsSystemInfo _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsText_OnSetString( &_this->EsnText, DeviceInterfaceSystemDeviceClass_OnGetESN( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
}

/* Variants derived from the class : 'Settings::SystemInfo' */
EW_DEFINE_CLASS_VARIANTS( SettingsSystemInfo )
EW_END_OF_CLASS_VARIANTS( SettingsSystemInfo )

/* Virtual Method Table (VMT) for the class : 'Settings::SystemInfo' */
EW_DEFINE_CLASS( SettingsSystemInfo, MenuBaseMenuView, ESN, ESN, ESN, ESN, _None, 
                 _None, "Settings::SystemInfo" )
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
  SettingsSystemInfo_OnShortEnterKeyActivated,
  SettingsSystemInfo_OnShortHomeKeyActivated,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
EW_END_OF_CLASS( SettingsSystemInfo )

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
  CoreRectView__OnSetBounds( &_this->DiscoverableText, _Const0010 );
  ViewsText_OnSetWrapText( &_this->DiscoverableText, 1 );
  ViewsText_OnSetAlignment( &_this->DiscoverableText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->DiscoverableText, EwLoadString( &_Const0011 ));
  CoreRectView__OnSetBounds( &_this->TimeLeftText, _Const0012 );
  ViewsText_OnSetWrapText( &_this->TimeLeftText, 1 );
  ViewsText_OnSetAlignment( &_this->TimeLeftText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->TimeLeftText, EwLoadString( &_Const0013 ));
  CoreRectView__OnSetBounds( &_this->NameText, _Const0014 );
  ViewsText_OnSetWrapText( &_this->NameText, 1 );
  ViewsText_OnSetAlignment( &_this->NameText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->NameText, EwLoadString( &_Const0015 ));
  CoreTimer_OnSetPeriod( &_this->CountDownTimer, 1000 );
  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 0 );
  CoreRectView__OnSetBounds( &_this->RemainTimeText, _Const0016 );
  ViewsText_OnSetWrapText( &_this->RemainTimeText, 1 );
  ViewsText_OnSetAlignment( &_this->RemainTimeText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->RemainTimeText, EwLoadString( &_Const0017 ));
  _this->CountDownTimeSec = 180;
  CoreRectView__OnSetBounds( &_this->DeviceNameText, _Const0018 );
  ViewsText_OnSetWrapText( &_this->DeviceNameText, 1 );
  ViewsText_OnSetAlignment( &_this->DeviceNameText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DeviceNameText, DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceName( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )));
  CoreRectView__OnSetBounds( &_this->PushButton, _Const0019 );
  MenuPushButton_OnSetTitle( &_this->PushButton, EwLoadString( &_Const001A ));
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
      SecondStr = EwConcatString( EwLoadString( &_Const001B ), EwNewStringInt( Second, 
      0, 10 ));
    }
    else
    {
      SecondStr = EwNewStringInt( Second, 0, 10 );
    }

    ViewsText_OnSetString( &_this->RemainTimeText, EwConcatString( EwConcatString( 
    EwNewStringInt( _this->CountDownTimeSec / 60, 0, 10 ), EwLoadString( &_Const001C )), 
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
  ComponentsBaseComponent_OnShortHomeKeyActivated,
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
  CoreRectView__OnSetBounds( &_this->Text, _Const001D );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Text, 0 );
  CoreTimer_OnSetPeriod( &_this->CloseDialogTimer, 2000 );
  CoreRectView__OnSetBounds( &_this->ConnectingText, _Const001E );
  ViewsText_OnSetAlignment( &_this->ConnectingText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ConnectingText, EwLoadString( &_Const001F ));
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
      &_Const0020 ), _this->DeviceName ), EwLoadString( &_Const0021 )));
    break;

    case EnumBtResultTIMEOUT :
    {
      ViewsText_OnSetString( &_this->Text, EwConcatString( _this->DeviceName, EwLoadString( 
      &_Const0022 )));
      ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzLeft );
    }
    break;

    case EnumBtResultFAIL :
      ViewsText_OnSetString( &_this->Text, EwConcatString( EwConcatString( EwLoadString( 
      &_Const0020 ), _this->DeviceName ), EwLoadString( &_Const0023 )));
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
    EwLoadString( &_Const0024 ), value ), EwLoadString( &_Const0025 )));
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
  ComponentsBaseComponent_OnShortHomeKeyActivated,
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
  CoreRectView__OnSetBounds( &_this->Text, _Const0026 );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const0027 ));
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const0028 );
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &_Const0029 ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &_Const002A ));
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UpDownPushButtonSet ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->UpDownPushButtonSet.OnUpButtonReleased = EwNewSlot( _this, SettingsBtMaxPairedDevice_OnYesSlot );
  _this->UpDownPushButtonSet.OnDownButtonReleased = EwNewSlot( _this, SettingsBtMaxPairedDevice_OnNoSlot );
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
  ComponentsBaseComponent_OnShortHomeKeyActivated,
EW_END_OF_CLASS( SettingsBtMaxPairedDevice )

/* Initializer for the class 'Settings::SET17_BtPairedDeviceList' */
void SettingsSET17_BtPairedDeviceList__Init( SettingsSET17_BtPairedDeviceList _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSET17_BtPairedDeviceList );

  /* ... then construct all embedded objects */
  MenuVerticalMenu__Init( &_this->Menu, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->RefreshListObserver, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NoDataText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSET17_BtPairedDeviceList );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Menu, _Const0001 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 1 );
  _this->Menu.Focusable = 0;
  MenuVerticalMenu_OnSetItemHeight( &_this->Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Menu, 4 );
  CoreRectView__OnSetBounds( &_this->NoDataText, _Const002B );
  ViewsText_OnSetString( &_this->NoDataText, EwLoadString( &_Const002C ));
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );
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
  MenuVerticalMenu__ReInit( &_this->Menu );
  CorePropertyObserver__ReInit( &_this->RefreshListObserver );
  ViewsText__ReInit( &_this->NoDataText );
}

/* Finalizer method for the class 'Settings::SET17_BtPairedDeviceList' */
void SettingsSET17_BtPairedDeviceList__Done( SettingsSET17_BtPairedDeviceList _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  MenuVerticalMenu__Done( &_this->Menu );
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

/* 'C' function for method : 'Settings::SET17_BtPairedDeviceList.OnShortHomeKeyActivated()' */
void SettingsSET17_BtPairedDeviceList_OnShortHomeKeyActivated( SettingsSET17_BtPairedDeviceList _this )
{
  CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
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
    SettingsBtPairedDeviceOperation Dialog = EwNewObject( SettingsBtPairedDeviceOperation, 
      0 );
    Dialog->PairedDeviceIndex = aItemNo;
    Dialog->DeviceName = EwShareString( BtDeviceItem->Super1.Title.String );
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
  EwTrace( "%s", EwLoadString( &_Const002D ));
  _this->PairedDeviceNum = DeviceInterfaceBluetoothDeviceClass_OnGetPairedDeviceNum( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ));
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, _this->PairedDeviceNum );

  if ( _this->PairedDeviceNum > 0 )
  {
    _this->Menu.Focusable = 1;
    MenuVerticalMenu_InvalidateItems( &_this->Menu, 0, _this->PairedDeviceNum - 
    1 );
    ViewsText_OnSetVisible( &_this->NoDataText, 0 );
  }
  else
  {
    _this->Menu.Focusable = 0;
    MenuVerticalMenu_InvalidateItems( &_this->Menu, 0, 0 );
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

  EwTrace( "%s", EwLoadString( &_Const002E ));
  SettingsSET17_BtPairedDeviceList_UpdatePairedDeviceNum( _this );
}

/* Variants derived from the class : 'Settings::SET17_BtPairedDeviceList' */
EW_DEFINE_CLASS_VARIANTS( SettingsSET17_BtPairedDeviceList )
EW_END_OF_CLASS_VARIANTS( SettingsSET17_BtPairedDeviceList )

/* Virtual Method Table (VMT) for the class : 'Settings::SET17_BtPairedDeviceList' */
EW_DEFINE_CLASS( SettingsSET17_BtPairedDeviceList, MenuBaseMenuView, Menu, Menu, 
                 Menu, Menu, PairedDeviceNum, PairedDeviceNum, "Settings::SET17_BtPairedDeviceList" )
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
  SettingsSET17_BtPairedDeviceList_OnShortHomeKeyActivated,
  SettingsSET17_BtPairedDeviceList_LoadItemClass,
  SettingsSET17_BtPairedDeviceList_LoadItemTitle,
  SettingsSET17_BtPairedDeviceList_OnItemActivate,
  SettingsSET17_BtPairedDeviceList_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
EW_END_OF_CLASS( SettingsSET17_BtPairedDeviceList )

/* Initializer for the class 'Settings::BtPairedDeviceOperation' */
void SettingsBtPairedDeviceOperation__Init( SettingsBtPairedDeviceOperation _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsBtPairedDeviceOperation );

  /* ... then construct all embedded objects */
  MenuVerticalMenu__Init( &_this->Menu, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsBtPairedDeviceOperation );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Menu, _Const0001 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 3 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const002F ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0030 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0031 ));
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );
}

/* Re-Initializer for the class 'Settings::BtPairedDeviceOperation' */
void SettingsBtPairedDeviceOperation__ReInit( SettingsBtPairedDeviceOperation _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  MenuVerticalMenu__ReInit( &_this->Menu );
}

/* Finalizer method for the class 'Settings::BtPairedDeviceOperation' */
void SettingsBtPairedDeviceOperation__Done( SettingsBtPairedDeviceOperation _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  MenuVerticalMenu__Done( &_this->Menu );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Settings::BtPairedDeviceOperation.LoadItemClass()' */
XClass SettingsBtPairedDeviceOperation_LoadItemClass( SettingsBtPairedDeviceOperation _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

  return EW_CLASS( MenuItemBase );
}

/* 'C' function for method : 'Settings::BtPairedDeviceOperation.LoadItemTitle()' */
XString SettingsBtPairedDeviceOperation_LoadItemTitle( SettingsBtPairedDeviceOperation _this, 
  XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < 3 )
  {
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 3 )];
  }

  return title;
}

/* 'C' function for method : 'Settings::BtPairedDeviceOperation.OnItemActivate()' */
void SettingsBtPairedDeviceOperation_OnItemActivate( SettingsBtPairedDeviceOperation _this, 
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

/* Variants derived from the class : 'Settings::BtPairedDeviceOperation' */
EW_DEFINE_CLASS_VARIANTS( SettingsBtPairedDeviceOperation )
EW_END_OF_CLASS_VARIANTS( SettingsBtPairedDeviceOperation )

/* Virtual Method Table (VMT) for the class : 'Settings::BtPairedDeviceOperation' */
EW_DEFINE_CLASS( SettingsBtPairedDeviceOperation, MenuBaseMenuView, Menu, Menu, 
                 Menu, Menu, ItemTitleArray, PairedDeviceIndex, "Settings::BtPairedDeviceOperation" )
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
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  SettingsBtPairedDeviceOperation_LoadItemClass,
  SettingsBtPairedDeviceOperation_LoadItemTitle,
  SettingsBtPairedDeviceOperation_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
EW_END_OF_CLASS( SettingsBtPairedDeviceOperation )

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
  CoreRectView__OnSetBounds( &_this->Text, _Const0032 );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Text, 0 );
  _this->DialogString1 = EwShareString( EwLoadString( &_Const0033 ));
  _this->DialogString2 = EwShareString( EwLoadString( &_Const0034 ));
  CoreRectView__OnSetBounds( &_this->PushButton, _Const0019 );
  MenuPushButton_OnSetTitle( &_this->PushButton, EwLoadString( &_Const0035 ));
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
  ComponentsBaseComponent_OnShortHomeKeyActivated,
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
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0036 );
  CoreRectView__OnSetBounds( &_this->StatusText, _Const0037 );
  ViewsText_OnSetWrapText( &_this->StatusText, 1 );
  ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const0038 ));
  ViewsText_OnSetColor( &_this->StatusText, _Const0039 );
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
      ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const003A ));
      CoreTimer_OnSetEnabled( &_this->RemoveDialogTimer, 1 );
    }
    break;

    case EnumBtFwStatusUPDATE_ABORT :
    {
      ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const003B ));
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
  CoreRectView__OnSetBounds( &_this->QrCode, _Const003C );
  ViewsImage_OnSetAlignment( &_this->QrCode, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  _this->PixelPerModule = 1;
  CoreRectView__OnSetBounds( &_this->PixelText, _Const003D );
  ViewsText_OnSetAlignment( &_this->PixelText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->PixelText, 0 );
  CoreRectView__OnSetBounds( &_this->QrCodeWidthText, _Const003E );
  ViewsText_OnSetAlignment( &_this->QrCodeWidthText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->QrCodeWidthText, 0 );
  CoreRectView__OnSetBounds( &_this->QrCodeContent, _Const003F );
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
    EwTrace( "%s", EwLoadString( &_Const0040 ));
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
    EwTrace( "%s", EwLoadString( &_Const0041 ));
  }
}

/* 'C' function for method : 'Settings::SET30_QRCode.OnShortHomeKeyActivated()' */
void SettingsSET30_QRCode_OnShortHomeKeyActivated( SettingsSET30_QRCode _this )
{
  CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
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
  ResourcesExternBitmap ), EwConcatString( EwLoadString( &_Const0042 ), EwNewStringInt( 
  _this->PixelPerModule, 0, 10 )));
  ViewsText_OnSetString( &_this->PixelText, EwConcatString( EwNewStringInt( _this->PixelPerModule, 
  0, 10 ), EwLoadString( &_Const0043 )));
  QrCodeWidth = ( 33 * _this->PixelPerModule ) * 0.019350f;
  ViewsText_OnSetString( &_this->QrCodeWidthText, EwConcatString( EwConcatString( 
  EwLoadString( &_Const0044 ), EwNewStringFloat( QrCodeWidth, 0, -1 )), EwLoadString( 
  &_Const0045 )));
  ViewsText_OnSetString( &_this->QrCodeContent, EwConcatString( EwLoadString( &_Const0046 ), 
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
  SettingsSET30_QRCode_OnShortHomeKeyActivated,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
EW_END_OF_CLASS( SettingsSET30_QRCode )

/* Embedded Wizard */
