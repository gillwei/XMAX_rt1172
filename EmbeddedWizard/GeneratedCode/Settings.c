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
#include "_ApplicationApplication.h"
#include "_ComponentsPushButton.h"
#include "_CoreGroup.h"
#include "_CoreKeyPressHandler.h"
#include "_CorePropertyObserver.h"
#include "_CoreRoot.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DevelopmentMain.h"
#include "_DeviceInterfaceBluetoothDeviceClass.h"
#include "_DeviceInterfaceBluetoothPairedDeviceInfo.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_MenuItemBase.h"
#include "_MenuItemBtPairedDevice.h"
#include "_MenuItemCheckbox.h"
#include "_MenuItemRightArrow.h"
#include "_MenuVerticalMenu.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_SettingsAllReset.h"
#include "_SettingsAllResetCompleted.h"
#include "_SettingsBluetooth.h"
#include "_SettingsBtConnectionResult.h"
#include "_SettingsBtDeleteBleDevice.h"
#include "_SettingsBtDiscovarable.h"
#include "_SettingsBtFwUpdateDialog.h"
#include "_SettingsBtMaxPairedDevice.h"
#include "_SettingsBtPairedDeviceList.h"
#include "_SettingsBtPairedDeviceOperation.h"
#include "_SettingsConnection.h"
#include "_SettingsDisplayBrightness.h"
#include "_SettingsInProgress.h"
#include "_SettingsMain.h"
#include "_SettingsReset.h"
#include "_SettingsSystemInfo.h"
#include "_SettingsSystemMenu.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "_WidgetSetPushButton.h"
#include "_WidgetSetPushButtonConfig.h"
#include "_WidgetSetToggleButton.h"
#include "Core.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Fonts.h"
#include "Resource.h"
#include "Settings.h"
#include "UIConfig.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000412, /* ratio 53.36 % */
  0xB8001D00, 0x80086452, 0x24DC0037, 0xC0065004, 0x00740018, 0x70B839A4, 0x098B800E,
  0x02991606, 0x8B000F20, 0xB9B61B11, 0x46818008, 0x00D80021, 0x2210C3A8, 0xD1118445,
  0xB1A0DC90, 0x00308009, 0xF104B4D6, 0x90CF63B1, 0x24F24600, 0x43E7B123, 0xCA5A7684,
  0x4C4009B9, 0x2B1796CA, 0x74C28468, 0x4486D2E2, 0x99691279, 0x86C3E274, 0x0514993C,
  0xC9C33249, 0x461B2CA7, 0x80130844, 0x59389E4C, 0xF3C005AE, 0x0D8542E8, 0xAA8C461F,
  0xB247A391, 0x5516E922, 0xD2E28668, 0x4E233891, 0x2F90A844, 0x2D13ADC1, 0xD38A79C2,
  0x4B944F23, 0xEB719E27, 0x8B4F6F12, 0x0C124D17, 0xCF2554F2, 0x92D53DAB, 0xC9F1A094,
  0x032E24C2, 0x345BD693, 0x3A96E269, 0x58D06A48, 0xA5EAA9E4, 0xE43E8B8C, 0x6661B1C9,
  0x3801A6A6, 0xA9B41959, 0xFA139252, 0xF11C2C52, 0x3CD4530E, 0xB8B73CAD, 0x0545E178,
  0x9000631A, 0x00066001, 0x006A001A, 0xA49E91B0, 0x0454B385, 0x1D484473, 0xD89C7580,
  0xDE376801, 0x00637BB3, 0x45246826, 0x16A9164B, 0x013960D6, 0x007E1060, 0x4212E564,
  0x1386153C, 0x652D086D, 0x292E6A59, 0x1666D0B6, 0x015240FD, 0xD0872D1A, 0x94680645,
  0x45248105, 0x4C6F9530, 0x7DD82815, 0x02E44545, 0x78CE3300, 0x191A0351, 0x9348D084,
  0x561AA4A9, 0xDAD6EA34, 0xD4FD7E42, 0x360348D2, 0x2E5B14E4, 0x66DC77C5, 0xE407F19B,
  0x17481445, 0x19118311, 0x008514C1, 0x92400858, 0x4005EE18, 0xC4E10446, 0x91B195D1,
  0x38468084, 0x6E59364D, 0x42F45D3C, 0x37591488, 0x510E58D4, 0x387F1494, 0x60A3E539,
  0x96D85D4E, 0x865DFC4C, 0x0D734B56, 0x0D51182A, 0x43679575, 0x6638D916, 0xF4294C8E,
  0x6A3753D5, 0x2344DF14, 0x7D62C581, 0x26B45DB9, 0xD4E1CB41, 0x02A10029, 0xE6468070,
  0x000306E5, 0x80445EAF, 0x3002B146, 0x0AA9412B, 0x778E9044, 0x44DB44B5, 0x27166D0A,
  0x8116BA00, 0x3D694A92, 0x004C5148, 0x49022780, 0x000406D0, 0x00000000
};

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault1[] =
{
  0x0000040E, /* ratio 50.48 % */
  0xB8002100, 0x00044452, 0x00400005, 0x0DE00318, 0x010F3700, 0x80085994, 0x6400448E,
  0xC000B800, 0x22C0C731, 0x9800D30A, 0x43A23093, 0x461A6C85, 0x4E51733C, 0x210E8649,
  0xD0C89C42, 0x0A8CC4E2, 0x08AC9E2D, 0x8545CD00, 0x14FA2E76, 0xC4E530C9, 0x00A10A8D,
  0xA4400308, 0x153C90CB, 0x54C96532, 0x1C8DC424, 0x88347C31, 0x88CC2150, 0x145A2933,
  0x99A4B319, 0x18014DA5, 0x2391A8C5, 0x871F0780, 0xB17994A8, 0x2C885A66, 0x48E41A15,
  0x22DBAB60, 0xC5A09B1F, 0x1D621253, 0x88006D00, 0xE1D25969, 0x27198559, 0x917A2506,
  0x139742A4, 0x79F43299, 0x2942ADB3, 0x0C3B1317, 0xD961513A, 0xBACE00D2, 0x21589874,
  0x2F4EB41C, 0x392B64E2, 0x29D4432D, 0xF8B49245, 0x8F89ADC3, 0xC002AB4A, 0xC5C896CC,
  0x322714C9, 0x001BBB49, 0x0055928B, 0xD4C8CEBC, 0x692B0026, 0x3001DE27, 0x8BF56785,
  0x44724A3A, 0x4A89D048, 0x33BFC685, 0xFA31FACD, 0x83D6B474, 0xD19E25A7, 0x13CA6D78,
  0xCC4E1FCD, 0xFB47C231, 0x5D645D6A, 0x770DB052, 0x8D2C0017, 0x115CD717, 0x4713C4D1,
  0x1CC7FC0D, 0x65856545, 0x002B4717, 0x23666017, 0x86DB44FD, 0x1166A13C, 0x26BD2567,
  0x21564B9C, 0x5F711258, 0x595B34B9, 0xD2A1E50A, 0x24712E61, 0x99CF4118, 0x2E8913C6,
  0x45DBA76D, 0xA3200239, 0x94298743, 0x2A325318, 0x16439104, 0x6A18B429, 0x56B62D4C,
  0xE819E74E, 0x45758560, 0x3B8F8005, 0x8A5CB496, 0x1720006B, 0x94962E53, 0x2A249522,
  0x1661D674, 0x561178D1, 0xD1F01400, 0xE12C0013, 0x49ED09D6, 0x2977D6C7, 0x108005E6,
  0xD6615000, 0x896D887C, 0xBE417116, 0x245316B6, 0x709DB6A1, 0xA9246D16, 0xF9E41E5B,
  0x01A877DE, 0x849AA82A, 0x95A8F626, 0x9894A92F, 0xC45E02A2, 0xEE960691, 0x9A496219,
  0xA79B1A0E, 0x96787A87, 0xE5B92970, 0x00004056, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XStringRes _Const0001 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0002 = { _StringsDefault0, 0x0010 };
static const XRect _Const0003 = {{ 10, 32 }, { 470, 272 }};
static const XStringRes _Const0004 = { _StringsDefault0, 0x0019 };
static const XStringRes _Const0005 = { _StringsDefault0, 0x0025 };
static const XStringRes _Const0006 = { _StringsDefault0, 0x0040 };
static const XStringRes _Const0007 = { _StringsDefault0, 0x0055 };
static const XStringRes _Const0008 = { _StringsDefault0, 0x006E };
static const XStringRes _Const0009 = { _StringsDefault0, 0x0083 };
static const XStringRes _Const000A = { _StringsDefault0, 0x0098 };
static const XStringRes _Const000B = { _StringsDefault0, 0x00A4 };
static const XRect _Const000C = {{ 106, 50 }, { 357, 80 }};
static const XStringRes _Const000D = { _StringsDefault0, 0x00B6 };
static const XRect _Const000E = {{ 120, 120 }, { 340, 145 }};
static const XStringRes _Const000F = { _StringsDefault0, 0x00D0 };
static const XRect _Const0010 = {{ 130, 80 }, { 330, 110 }};
static const XStringRes _Const0011 = { _StringsDefault0, 0x00E3 };
static const XRect _Const0012 = {{ 150, 150 }, { 310, 180 }};
static const XRect _Const0013 = {{ 400, 190 }, { 470, 260 }};
static const XRect _Const0014 = {{ 120, 190 }, { 340, 215 }};
static const XStringRes _Const0015 = { _StringsDefault0, 0x00ED };
static const XRect _Const0016 = {{ 150, 220 }, { 310, 250 }};
static const XRect _Const0017 = {{ 30, 45 }, { 450, 180 }};
static const XStringRes _Const0018 = { _StringsDefault0, 0x0103 };
static const XRect _Const0019 = {{ 260, 190 }, { 410, 240 }};
static const XStringRes _Const001A = { _StringsDefault0, 0x0129 };
static const XRect _Const001B = {{ 40, 190 }, { 190, 240 }};
static const XStringRes _Const001C = { _StringsDefault0, 0x012E };
static const XRect _Const001D = {{ 110, 100 }, { 350, 150 }};
static const XStringRes _Const001E = { _StringsDefault0, 0x0134 };
static const XRect _Const001F = {{ 100, 95 }, { 360, 170 }};
static const XStringRes _Const0020 = { _StringsDefault0, 0x0145 };
static const XStringRes _Const0021 = { _StringsDefault0, 0x0152 };
static const XStringRes _Const0022 = { _StringsDefault0, 0x016C };
static const XRect _Const0023 = {{ 432, 2 }, { 482, 22 }};
static const XStringRes _Const0024 = { _StringsDefault0, 0x0180 };
static const XStringRes _Const0025 = { _StringsDefault0, 0x0189 };
static const XColor _Const0026 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0027 = {{ 60, 34 }, { 410, 110 }};
static const XStringRes _Const0028 = { _StringsDefault0, 0x0191 };
static const XRect _Const0029 = {{ 160, 200 }, { 300, 250 }};
static const XStringRes _Const002A = { _StringsDefault0, 0x01C0 };
static const XRect _Const002B = {{ 130, 153 }, { 280, 193 }};
static const XStringRes _Const002C = { _StringsDefault0, 0x01C9 };
static const XRect _Const002D = {{ 120, 113 }, { 240, 153 }};
static const XStringRes _Const002E = { _StringsDefault0, 0x01D6 };
static const XRect _Const002F = {{ 260, 153 }, { 340, 193 }};
static const XStringRes _Const0030 = { _StringsDefault0, 0x01DE };
static const XRect _Const0031 = {{ 230, 113 }, { 400, 153 }};
static const XStringRes _Const0032 = { _StringsDefault0, 0x01E5 };
static const XStringRes _Const0033 = { _StringsDefault0, 0x01E9 };
static const XRect _Const0034 = {{ 40, 40 }, { 440, 230 }};
static const XRect _Const0035 = {{ 30, 90 }, { 460, 140 }};
static const XStringRes _Const0036 = { _StringsDefault0, 0x01ED };
static const XStringRes _Const0037 = { _StringsDefault0, 0x01FB };
static const XStringRes _Const0038 = { _StringsDefault1, 0x0002 };
static const XStringRes _Const0039 = { _StringsDefault1, 0x0012 };
static const XStringRes _Const003A = { _StringsDefault1, 0x004B };
static const XStringRes _Const003B = { _StringsDefault1, 0x0063 };
static const XStringRes _Const003C = { _StringsDefault1, 0x0072 };
static const XRect _Const003D = {{ 20, 70 }, { 460, 150 }};
static const XStringRes _Const003E = { _StringsDefault1, 0x0076 };
static const XRect _Const003F = {{ 250, 190 }, { 390, 240 }};
static const XRect _Const0040 = {{ 100, 190 }, { 240, 240 }};
static const XStringRes _Const0041 = { _StringsDefault1, 0x00BB };
static const XStringRes _Const0042 = { _StringsDefault1, 0x00E1 };
static const XStringRes _Const0043 = { _StringsDefault1, 0x00EB };
static const XStringRes _Const0044 = { _StringsDefault1, 0x0103 };
static const XStringRes _Const0045 = { _StringsDefault1, 0x0114 };
static const XStringRes _Const0046 = { _StringsDefault1, 0x011E };
static const XRect _Const0047 = {{ 40, 50 }, { 440, 200 }};
static const XStringRes _Const0048 = { _StringsDefault1, 0x012B };
static const XStringRes _Const0049 = { _StringsDefault1, 0x0156 };
static const XRect _Const004A = {{ 150, 210 }, { 290, 260 }};
static const XStringRes _Const004B = { _StringsDefault1, 0x01A3 };
static const XRect _Const004C = {{ 80, 60 }, { 380, 210 }};
static const XStringRes _Const004D = { _StringsDefault1, 0x01A8 };
static const XColor _Const004E = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XStringRes _Const004F = { _StringsDefault1, 0x01CF };
static const XStringRes _Const0050 = { _StringsDefault1, 0x01ED };

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

/* Initializer for the class 'Settings::Main' */
void SettingsMain__Init( SettingsMain _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsMain );

  /* ... then construct all embedded objects */
  MenuVerticalMenu__Init( &_this->Menu, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsMain );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0001 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0002 ));
  CoreRectView__OnSetBounds( &_this->Menu, _Const0003 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 2 );
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );
  _this->Menu.Super1.PassKeyHold = EwNewSlot( _this, ComponentsBaseComponent__OnLongKeyPressed );
}

/* Re-Initializer for the class 'Settings::Main' */
void SettingsMain__ReInit( SettingsMain _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  MenuVerticalMenu__ReInit( &_this->Menu );
}

/* Finalizer method for the class 'Settings::Main' */
void SettingsMain__Done( SettingsMain _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  MenuVerticalMenu__Done( &_this->Menu );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Settings::Main.OnLongKeyPressed()' */
void SettingsMain_OnLongKeyPressed( SettingsMain _this, XObject sender )
{
  EwSignal( _this->Super2.PassKeyHold, sender );
}

/* 'C' function for method : 'Settings::Main.LoadItemClass()' */
XClass SettingsMain_LoadItemClass( SettingsMain _this, XInt32 aItemNo )
{
  XClass ItemClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemClass = 0;

  if ( aItemNo >= 0 )
  {
    ItemClass = EW_CLASS( MenuItemRightArrow );
  }

  return ItemClass;
}

/* 'C' function for method : 'Settings::Main.LoadItemTitle()' */
XString SettingsMain_LoadItemTitle( SettingsMain _this, XInt32 aItemNo )
{
  XString Title = 0;

  if ( aItemNo < 2 )
  {
    Title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 2 )];
  }

  return Title;
}

/* 'C' function for method : 'Settings::Main.OnItemActivate()' */
void SettingsMain_OnItemActivate( SettingsMain _this, XInt32 aItemNo, MenuItemBase 
  aMenuItem )
{
  if ( aMenuItem == 0 )
    ;

  switch ( aItemNo )
  {
    case 0 :
      ComponentsBaseComponent_SlideInDialog((ComponentsBaseComponent)_this, ((CoreGroup)EwNewObject( 
      SettingsConnection, 0 )));
    break;

    case 1 :
      ComponentsBaseComponent_SlideInDialog((ComponentsBaseComponent)_this, ((CoreGroup)EwNewObject( 
      SettingsSystemMenu, 0 )));
    break;

    default : 
      ;
  }
}

/* Variants derived from the class : 'Settings::Main' */
EW_DEFINE_CLASS_VARIANTS( SettingsMain )
EW_END_OF_CLASS_VARIANTS( SettingsMain )

/* Virtual Method Table (VMT) for the class : 'Settings::Main' */
EW_DEFINE_CLASS( SettingsMain, MenuBaseMenuView, Menu, Menu, Menu, Menu, ItemTitleArray, 
                 _None, "Settings::Main" )
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  SettingsMain_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
  SettingsMain_LoadItemClass,
  SettingsMain_LoadItemTitle,
  SettingsMain_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemConnected,
  MenuBaseMenuView_LoadItemValid,
EW_END_OF_CLASS( SettingsMain )

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
  CoreRectView__OnSetBounds( &_this->Menu, _Const0003 );
  _this->ItemClassArray[ 0 ] = EW_CLASS( MenuItemRightArrow );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0004 ));
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );
  _this->Menu.Super1.PassKeyHold = EwNewSlot( _this, ComponentsBaseComponent__OnLongKeyPressed );
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

/* 'C' function for method : 'Settings::Connection.OnLongKeyPressed()' */
void SettingsConnection_OnLongKeyPressed( SettingsConnection _this, XObject sender )
{
  CoreKeyPressHandler CurrentKeyHandler = EwCastObject( sender, CoreKeyPressHandler );

  if (( CurrentKeyHandler != 0 ) && ( _this->Super5.Owner != 0 ))
  {
    switch ( CurrentKeyHandler->Code )
    {
      case CoreKeyCodeOk :
        ComponentsBaseComponent_SlideOutDialog((ComponentsBaseComponent)_this, ((CoreGroup)_this ));
      break;

      default : 
        ;
    }
  }
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  SettingsConnection_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
  SettingsConnection_LoadItemClass,
  SettingsConnection_LoadItemTitle,
  SettingsConnection_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemConnected,
  MenuBaseMenuView_LoadItemValid,
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
  CoreRectView__OnSetBounds( &_this->Menu, _Const0003 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 4 );
  _this->ItemClassArray[ 0 ] = EW_CLASS( MenuItemCheckbox );
  _this->ItemClassArray[ 1 ] = EW_CLASS( MenuItemBase );
  _this->ItemClassArray[ 2 ] = EW_CLASS( MenuItemRightArrow );
  _this->ItemClassArray[ 3 ] = EW_CLASS( MenuItemCheckbox );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0004 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0005 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0006 ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const0007 ));
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );
  _this->Menu.Super1.PassKeyHold = EwNewSlot( _this, ComponentsBaseComponent__OnLongKeyPressed );

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

/* 'C' function for method : 'Settings::Bluetooth.OnLongKeyPressed()' */
void SettingsBluetooth_OnLongKeyPressed( SettingsBluetooth _this, XObject sender )
{
  CoreKeyPressHandler CurrentKeyHandler = EwCastObject( sender, CoreKeyPressHandler );

  if (( CurrentKeyHandler != 0 ) && ( _this->Super5.Owner != 0 ))
  {
    switch ( CurrentKeyHandler->Code )
    {
      case CoreKeyCodeOk :
        ComponentsBaseComponent_SlideOutDialog((ComponentsBaseComponent)_this, ((CoreGroup)_this ));
      break;

      default : 
        ;
    }
  }
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

  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsBtPairedDeviceList, 
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  SettingsBluetooth_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
  SettingsBluetooth_LoadItemClass,
  SettingsBluetooth_LoadItemTitle,
  SettingsBluetooth_OnItemActivate,
  SettingsBluetooth_LoadItemChecked,
  SettingsBluetooth_LoadItemEnabled,
  MenuBaseMenuView_LoadItemConnected,
  MenuBaseMenuView_LoadItemValid,
EW_END_OF_CLASS( SettingsBluetooth )

/* Initializer for the class 'Settings::SystemMenu' */
void SettingsSystemMenu__Init( SettingsSystemMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsSystemMenu );

  /* ... then construct all embedded objects */
  MenuVerticalMenu__Init( &_this->Menu, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSystemMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  _this->SystemMenu[ 0 ] = EwShareString( EwLoadString( &_Const0008 ));
  _this->SystemMenu[ 1 ] = EwShareString( EwLoadString( &_Const0009 ));
  _this->SystemMenu[ 2 ] = EwShareString( EwLoadString( &_Const000A ));
  CoreRectView__OnSetBounds( &_this->Menu, _Const0003 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 3 );
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );
  _this->Menu.Super1.PassKeyHold = EwNewSlot( _this, ComponentsBaseComponent__OnLongKeyPressed );
}

/* Re-Initializer for the class 'Settings::SystemMenu' */
void SettingsSystemMenu__ReInit( SettingsSystemMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  MenuVerticalMenu__ReInit( &_this->Menu );
}

/* Finalizer method for the class 'Settings::SystemMenu' */
void SettingsSystemMenu__Done( SettingsSystemMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  MenuVerticalMenu__Done( &_this->Menu );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Settings::SystemMenu.OnLongKeyPressed()' */
void SettingsSystemMenu_OnLongKeyPressed( SettingsSystemMenu _this, XObject sender )
{
  CoreKeyPressHandler CurrentKeyHandler = EwCastObject( sender, CoreKeyPressHandler );

  if (( CurrentKeyHandler != 0 ) && ( _this->Super5.Owner != 0 ))
  {
    switch ( CurrentKeyHandler->Code )
    {
      case CoreKeyCodeOk :
        ComponentsBaseComponent_SlideOutDialog((ComponentsBaseComponent)_this, ((CoreGroup)_this ));
      break;

      default : 
        ;
    }
  }
}

/* 'C' function for method : 'Settings::SystemMenu.LoadItemClass()' */
XClass SettingsSystemMenu_LoadItemClass( SettingsSystemMenu _this, XInt32 aItemNo )
{
  XClass ItemClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemClass = 0;

  if ( aItemNo >= 0 )
  {
    if ( aItemNo != 2 )
    {
      ItemClass = EW_CLASS( MenuItemBase );
    }
    else
    {
      ItemClass = EW_CLASS( MenuItemRightArrow );
    }
  }

  return ItemClass;
}

/* 'C' function for method : 'Settings::SystemMenu.LoadItemTitle()' */
XString SettingsSystemMenu_LoadItemTitle( SettingsSystemMenu _this, XInt32 aItemNo )
{
  XString Title = 0;

  if ( aItemNo < 3 )
  {
    Title = _this->SystemMenu[ EwCheckIndex( aItemNo, 3 )];
  }

  return Title;
}

/* 'C' function for method : 'Settings::SystemMenu.OnItemActivate()' */
void SettingsSystemMenu_OnItemActivate( SettingsSystemMenu _this, XInt32 aItemNo, 
  MenuItemBase aMenuItem )
{
  EwTrace( "%s%i", EwLoadString( &_Const000B ), aItemNo );

  if ( aMenuItem == 0 )
    ;

  switch ( aItemNo )
  {
    case 0 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsSystemInfo, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 1 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsDisplayBrightness, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 2 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsReset, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    default : 
      ;
  }
}

/* Variants derived from the class : 'Settings::SystemMenu' */
EW_DEFINE_CLASS_VARIANTS( SettingsSystemMenu )
EW_END_OF_CLASS_VARIANTS( SettingsSystemMenu )

/* Virtual Method Table (VMT) for the class : 'Settings::SystemMenu' */
EW_DEFINE_CLASS( SettingsSystemMenu, MenuBaseMenuView, Menu, Menu, Menu, Menu, SystemMenu, 
                 _None, "Settings::SystemMenu" )
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  SettingsSystemMenu_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
  SettingsSystemMenu_LoadItemClass,
  SettingsSystemMenu_LoadItemTitle,
  SettingsSystemMenu_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemConnected,
  MenuBaseMenuView_LoadItemValid,
EW_END_OF_CLASS( SettingsSystemMenu )

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
  ComponentsPushButton__Init( &_this->DevButton, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->EsnObserver, &_this->_XObject, 0 );
  ViewsText__Init( &_this->BtSwVersionTitle, &_this->_XObject, 0 );
  ViewsText__Init( &_this->BtSwVersionText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsSystemInfo );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->ESN, _Const000C );
  ViewsText_OnSetString( &_this->ESN, EwLoadString( &_Const000D ));
  CoreRectView__OnSetBounds( &_this->SoftwareVersionTitle, _Const000E );
  ViewsText_OnSetString( &_this->SoftwareVersionTitle, EwLoadString( &_Const000F ));
  CoreRectView__OnSetBounds( &_this->EsnText, _Const0010 );
  ViewsText_OnSetString( &_this->EsnText, EwLoadString( &_Const0011 ));
  CoreRectView__OnSetBounds( &_this->SoftwareVersionText, _Const0012 );
  ViewsText_OnSetString( &_this->SoftwareVersionText, DeviceInterfaceSystemDeviceClass_OnGetSoftwareVersion( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
  CoreRectView__OnSetBounds( &_this->DevButton, _Const0013 );
  CoreGroup__OnSetEnabled( &_this->DevButton, 0 );
  CoreGroup_OnSetVisible((CoreGroup)&_this->DevButton, 0 );
  WidgetSetPushButton_OnSetLabel((WidgetSetPushButton)&_this->DevButton, 0 );
  CoreRectView__OnSetBounds( &_this->BtSwVersionTitle, _Const0014 );
  ViewsText_OnSetString( &_this->BtSwVersionTitle, EwLoadString( &_Const0015 ));
  CoreRectView__OnSetBounds( &_this->BtSwVersionText, _Const0016 );
  ViewsText_OnSetString( &_this->BtSwVersionText, DeviceInterfaceSystemDeviceClass_OnGetSoftwareVersion( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
  CoreGroup__Add( _this, ((CoreView)&_this->ESN ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SoftwareVersionTitle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->EsnText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SoftwareVersionText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DevButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BtSwVersionTitle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BtSwVersionText ), 0 );
  ViewsText_OnSetFont( &_this->ESN, EwLoadResource( &FontsFontNotoSansCjkJp32, ResourcesFont ));
  ViewsText_OnSetFont( &_this->SoftwareVersionTitle, EwLoadResource( &FontsFontNotoSansCjkJp32, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->EsnText, EwLoadResource( &FontsFontNotoSansCjkJp32, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->SoftwareVersionText, EwLoadResource( &FontsFontNotoSansCjkJp32, 
  ResourcesFont ));
  _this->DevButton.Super1.OnRelease = EwNewSlot( _this, SettingsSystemInfo_OnDevButtonReleaseSlot );
  WidgetSetPushButton_OnSetIcon((WidgetSetPushButton)&_this->DevButton, EwLoadResource( 
  &ResourceDevelopment, ResourcesBitmap ));
  WidgetSetPushButton_OnSetAppearance((WidgetSetPushButton)&_this->DevButton, EwGetAutoObject( 
  &UIConfigPushButtonConfig, WidgetSetPushButtonConfig ));
  _this->DevButton.PassKeyHold = EwNewSlot( _this, ComponentsBaseComponent__OnLongKeyPressed );
  _this->EsnObserver.OnEvent = EwNewSlot( _this, SettingsSystemInfo_OnEsnReceivedSlot );
  CorePropertyObserver_OnSetOutlet( &_this->EsnObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ), DeviceInterfaceSystemDeviceClass_OnGetESN, 
  DeviceInterfaceSystemDeviceClass_OnSetESN ));
  ViewsText_OnSetFont( &_this->BtSwVersionTitle, EwLoadResource( &FontsFontNotoSansCjkJp32, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->BtSwVersionText, EwLoadResource( &FontsFontNotoSansCjkJp32, 
  ResourcesFont ));

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
  ComponentsPushButton__ReInit( &_this->DevButton );
  CorePropertyObserver__ReInit( &_this->EsnObserver );
  ViewsText__ReInit( &_this->BtSwVersionTitle );
  ViewsText__ReInit( &_this->BtSwVersionText );
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
  ComponentsPushButton__Done( &_this->DevButton );
  CorePropertyObserver__Done( &_this->EsnObserver );
  ViewsText__Done( &_this->BtSwVersionTitle );
  ViewsText__Done( &_this->BtSwVersionText );

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

  if ( DeviceInterfaceSystemDeviceClass_OnGetIsDebugBuild( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
      DeviceInterfaceSystemDeviceClass )))
  {
    CoreGroup__OnSetEnabled( &_this->DevButton, 1 );
    CoreGroup_OnSetVisible((CoreGroup)&_this->DevButton, 1 );
    CoreGroup__OnSetFocus( _this, ((CoreView)&_this->DevButton ));
  }
}

/* 'C' function for method : 'Settings::SystemInfo.OnLongKeyPressed()' */
void SettingsSystemInfo_OnLongKeyPressed( SettingsSystemInfo _this, XObject sender )
{
  CoreKeyPressHandler CurrentKeyHandler = EwCastObject( sender, CoreKeyPressHandler );

  if (( CurrentKeyHandler != 0 ) && ( _this->Super5.Owner != 0 ))
  {
    switch ( CurrentKeyHandler->Code )
    {
      case CoreKeyCodeOk :
        ComponentsBaseComponent_SlideOutDialog((ComponentsBaseComponent)_this, ((CoreGroup)_this ));
      break;

      default : 
        ;
    }
  }
}

/* 'C' function for method : 'Settings::SystemInfo.OnDevButtonReleaseSlot()' */
void SettingsSystemInfo_OnDevButtonReleaseSlot( SettingsSystemInfo _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentMain, 
  0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  SettingsSystemInfo_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemConnected,
  MenuBaseMenuView_LoadItemValid,
EW_END_OF_CLASS( SettingsSystemInfo )

/* Initializer for the class 'Settings::AllReset' */
void SettingsAllReset__Init( SettingsAllReset _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsAllReset );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );
  WidgetSetPushButton__Init( &_this->ButtonNo, &_this->_XObject, 0 );
  WidgetSetPushButton__Init( &_this->ButtonYes, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsAllReset );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0017 );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const0018 ));
  CoreRectView__OnSetBounds( &_this->ButtonNo, _Const0019 );
  WidgetSetPushButton_OnSetLabel( &_this->ButtonNo, EwLoadString( &_Const001A ));
  CoreRectView__OnSetBounds( &_this->ButtonYes, _Const001B );
  WidgetSetPushButton_OnSetLabel( &_this->ButtonYes, EwLoadString( &_Const001C ));
  _this->FocusIdx = 1;
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ButtonNo ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ButtonYes ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsFontNotoSansCjkJp32, 
  ResourcesFont ));
  _this->ButtonNo.OnRelease = EwNewSlot( _this, SettingsAllReset_OnButtonNo );
  WidgetSetPushButton_OnSetAppearance( &_this->ButtonNo, EwGetAutoObject( &UIConfigPushButtonConfig, 
  WidgetSetPushButtonConfig ));
  _this->ButtonYes.OnRelease = EwNewSlot( _this, SettingsAllReset_OnButtonYes );
  WidgetSetPushButton_OnSetAppearance( &_this->ButtonYes, EwGetAutoObject( &UIConfigPushButtonConfig, 
  WidgetSetPushButtonConfig ));
  _this->FocusList[ 0 ] = ((CoreView)&_this->ButtonYes );
  _this->FocusList[ 1 ] = ((CoreView)&_this->ButtonNo );
}

/* Re-Initializer for the class 'Settings::AllReset' */
void SettingsAllReset__ReInit( SettingsAllReset _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Text );
  WidgetSetPushButton__ReInit( &_this->ButtonNo );
  WidgetSetPushButton__ReInit( &_this->ButtonYes );
}

/* Finalizer method for the class 'Settings::AllReset' */
void SettingsAllReset__Done( SettingsAllReset _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Text );
  WidgetSetPushButton__Done( &_this->ButtonNo );
  WidgetSetPushButton__Done( &_this->ButtonYes );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Settings::AllReset.OnLongKeyPressed()' */
void SettingsAllReset_OnLongKeyPressed( SettingsAllReset _this, XObject sender )
{
  CoreKeyPressHandler CurrentKeyHandler = EwCastObject( sender, CoreKeyPressHandler );

  if (( CurrentKeyHandler != 0 ) && ( _this->Super5.Owner != 0 ))
  {
    switch ( CurrentKeyHandler->Code )
    {
      case CoreKeyCodeHome :
        EwPostSignal( _this->OnNo, ((XObject)_this ));
      break;

      default : 
        ;
    }
  }
}

/* 'C' function for method : 'Settings::AllReset.OnShortDownKeyPressed()' */
void SettingsAllReset_OnShortDownKeyPressed( SettingsAllReset _this )
{
  XInt32 NextFocusIdx = _this->FocusIdx + 1;

  if ( NextFocusIdx >= 2 )
  {
    NextFocusIdx = 1;
  }

  if ( _this->FocusIdx != NextFocusIdx )
  {
    _this->FocusIdx = NextFocusIdx;
    CoreGroup__OnSetFocus( _this, _this->FocusList[ EwCheckIndex( NextFocusIdx, 
    2 )]);
  }
}

/* 'C' function for method : 'Settings::AllReset.OnShortUpKeyPressed()' */
void SettingsAllReset_OnShortUpKeyPressed( SettingsAllReset _this )
{
  XInt32 NextFocusIdx = _this->FocusIdx - 1;

  if ( NextFocusIdx < 0 )
  {
    NextFocusIdx = 0;
  }

  if ( _this->FocusIdx != NextFocusIdx )
  {
    _this->FocusIdx = NextFocusIdx;
    CoreGroup__OnSetFocus( _this, _this->FocusList[ EwCheckIndex( NextFocusIdx, 
    2 )]);
  }
}

/* 'C' function for method : 'Settings::AllReset.OnButtonYes()' */
void SettingsAllReset_OnButtonYes( SettingsAllReset _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwPostSignal( _this->OnYes, ((XObject)_this ));
}

/* 'C' function for method : 'Settings::AllReset.OnButtonNo()' */
void SettingsAllReset_OnButtonNo( SettingsAllReset _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwPostSignal( _this->OnNo, ((XObject)_this ));
}

/* Variants derived from the class : 'Settings::AllReset' */
EW_DEFINE_CLASS_VARIANTS( SettingsAllReset )
EW_END_OF_CLASS_VARIANTS( SettingsAllReset )

/* Virtual Method Table (VMT) for the class : 'Settings::AllReset' */
EW_DEFINE_CLASS( SettingsAllReset, MenuBaseMenuView, FocusList, OnYes, Text, Text, 
                 FocusIdx, FocusIdx, "Settings::AllReset" )
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  SettingsAllReset_OnLongKeyPressed,
  SettingsAllReset_OnShortDownKeyPressed,
  SettingsAllReset_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemConnected,
  MenuBaseMenuView_LoadItemValid,
EW_END_OF_CLASS( SettingsAllReset )

/* Initializer for the class 'Settings::InProgress' */
void SettingsInProgress__Init( SettingsInProgress _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsInProgress );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsInProgress );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Text, _Const001D );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const001E ));
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsFontNotoSansCjkJp36, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Settings::InProgress' */
void SettingsInProgress__ReInit( SettingsInProgress _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Text );
}

/* Finalizer method for the class 'Settings::InProgress' */
void SettingsInProgress__Done( SettingsInProgress _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Text );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* Variants derived from the class : 'Settings::InProgress' */
EW_DEFINE_CLASS_VARIANTS( SettingsInProgress )
EW_END_OF_CLASS_VARIANTS( SettingsInProgress )

/* Virtual Method Table (VMT) for the class : 'Settings::InProgress' */
EW_DEFINE_CLASS( SettingsInProgress, MenuBaseMenuView, Text, Text, Text, Text, _None, 
                 _None, "Settings::InProgress" )
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  ComponentsBaseComponent_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemConnected,
  MenuBaseMenuView_LoadItemValid,
EW_END_OF_CLASS( SettingsInProgress )

/* Initializer for the class 'Settings::AllResetCompleted' */
void SettingsAllResetCompleted__Init( SettingsAllResetCompleted _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsAllResetCompleted );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsAllResetCompleted );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Text, _Const001F );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const0020 ));
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsFontNotoSansCjkJp32, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Settings::AllResetCompleted' */
void SettingsAllResetCompleted__ReInit( SettingsAllResetCompleted _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Text );
}

/* Finalizer method for the class 'Settings::AllResetCompleted' */
void SettingsAllResetCompleted__Done( SettingsAllResetCompleted _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Text );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* Variants derived from the class : 'Settings::AllResetCompleted' */
EW_DEFINE_CLASS_VARIANTS( SettingsAllResetCompleted )
EW_END_OF_CLASS_VARIANTS( SettingsAllResetCompleted )

/* Virtual Method Table (VMT) for the class : 'Settings::AllResetCompleted' */
EW_DEFINE_CLASS( SettingsAllResetCompleted, MenuBaseMenuView, Text, Text, Text, 
                 Text, _None, _None, "Settings::AllResetCompleted" )
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  ComponentsBaseComponent_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemConnected,
  MenuBaseMenuView_LoadItemValid,
EW_END_OF_CLASS( SettingsAllResetCompleted )

/* Initializer for the class 'Settings::Reset' */
void SettingsReset__Init( SettingsReset _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsReset );

  /* ... then construct all embedded objects */
  CoreTimer__Init( &_this->SystemRebootCountDownTimer, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->ResetResultObserver, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsReset );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreTimer_OnSetPeriod( &_this->SystemRebootCountDownTimer, 2000 );
  _this->SystemRebootCountDownTimer.OnTrigger = EwNewSlot( _this, SettingsReset_OnSystemRebootTriggeredSlot );
  _this->ResetResultObserver.OnEvent = EwNewSlot( _this, SettingsReset_OnResetCompleteSlot );
  CorePropertyObserver_OnSetOutlet( &_this->ResetResultObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ), DeviceInterfaceSystemDeviceClass_OnGetFactoryResetComplete, 
  DeviceInterfaceSystemDeviceClass_OnSetFactoryResetComplete ));

  /* Call the user defined constructor */
  SettingsReset_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::Reset' */
void SettingsReset__ReInit( SettingsReset _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreTimer__ReInit( &_this->SystemRebootCountDownTimer );
  CorePropertyObserver__ReInit( &_this->ResetResultObserver );
}

/* Finalizer method for the class 'Settings::Reset' */
void SettingsReset__Done( SettingsReset _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  CoreTimer__Done( &_this->SystemRebootCountDownTimer );
  CorePropertyObserver__Done( &_this->ResetResultObserver );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsReset_Init( SettingsReset _this, XHandle aArg )
{
  SettingsAllReset all_reset;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  all_reset = EwNewObject( SettingsAllReset, 0 );
  all_reset->OnYes = EwNewSlot( _this, SettingsReset_OnAllResetYesSlot );
  all_reset->OnNo = EwNewSlot( _this, SettingsReset_OnAllResetNoSlot );
  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)all_reset ), 0, 0, 0, 0, 
  0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Settings::Reset.OnAllResetYesSlot()' */
void SettingsReset_OnAllResetYesSlot( SettingsReset _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  SettingsReset_StartFactoryReset( _this );
}

/* 'C' function for method : 'Settings::Reset.OnAllResetNoSlot()' */
void SettingsReset_OnAllResetNoSlot( SettingsReset _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup__DismissDialog( _this->Super4.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Settings::Reset.OnSystemRebootTriggeredSlot()' */
void SettingsReset_OnSystemRebootTriggeredSlot( SettingsReset _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwTrace( "%s", EwLoadString( &_Const0021 ));
  CoreTimer_OnSetEnabled( &_this->SystemRebootCountDownTimer, 0 );
  DeviceInterfaceSystemDeviceClass_RebootSystem( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ));
}

/* 'C' function for method : 'Settings::Reset.ShowResetCompleteDialog()' */
void SettingsReset_ShowResetCompleteDialog( SettingsReset _this )
{
  SettingsAllResetCompleted AllResetCompletedDialog;

  if ( _this->BusyDialog != 0 )
  {
    CoreGroup__DismissDialog( _this, ((CoreGroup)_this->BusyDialog ), 0, 0, 0, EwNullSlot, 
    EwNullSlot, 0 );
    _this->BusyDialog = 0;
  }

  AllResetCompletedDialog = EwNewObject( SettingsAllResetCompleted, 0 );
  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)AllResetCompletedDialog ), 
  0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  CoreTimer_OnSetEnabled( &_this->SystemRebootCountDownTimer, 1 );
}

/* 'C' function for method : 'Settings::Reset.StartFactoryReset()' */
void SettingsReset_StartFactoryReset( SettingsReset _this )
{
  EwTrace( "%s", EwLoadString( &_Const0022 ));
  _this->BusyDialog = EwNewObject( SettingsInProgress, 0 );
  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)_this->BusyDialog ), 0, 
  0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  DeviceInterfaceSystemDeviceClass_ResetToFactoryDefault( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ));
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void SettingsReset_OnResetCompleteSlot( SettingsReset _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  SettingsReset_ShowResetCompleteDialog( _this );
}

/* Variants derived from the class : 'Settings::Reset' */
EW_DEFINE_CLASS_VARIANTS( SettingsReset )
EW_END_OF_CLASS_VARIANTS( SettingsReset )

/* Virtual Method Table (VMT) for the class : 'Settings::Reset' */
EW_DEFINE_CLASS( SettingsReset, ComponentsBaseComponent, BusyDialog, SystemRebootCountDownTimer, 
                 SystemRebootCountDownTimer, SystemRebootCountDownTimer, _None, 
                 _None, "Settings::Reset" )
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  ComponentsBaseComponent_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
EW_END_OF_CLASS( SettingsReset )

/* Initializer for the class 'Settings::DisplayBrightness' */
void SettingsDisplayBrightness__Init( SettingsDisplayBrightness _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsDisplayBrightness );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->CheckerboardImage, &_this->_XObject, 0 );
  ViewsText__Init( &_this->LevelText, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->HideLevelTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsDisplayBrightness );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->CheckerboardImage, _Const0000 );
  ViewsImage_OnSetFrameNumber( &_this->CheckerboardImage, 1 );
  CoreRectView__OnSetBounds( &_this->LevelText, _Const0023 );
  ViewsText_OnSetWrapText( &_this->LevelText, 1 );
  ViewsText_OnSetString( &_this->LevelText, 0 );
  _this->BrightnessLevel = -1;
  _this->BrightnessList[ 0 ] = 1;
  _this->BrightnessList[ 1 ] = 3;
  _this->BrightnessList[ 2 ] = 6;
  _this->BrightnessList[ 3 ] = 11;
  _this->BrightnessList[ 4 ] = 18;
  _this->BrightnessList[ 5 ] = 27;
  _this->BrightnessList[ 6 ] = 38;
  _this->BrightnessList[ 7 ] = 50;
  _this->BrightnessList[ 8 ] = 65;
  _this->BrightnessList[ 9 ] = 81;
  _this->BrightnessList[ 10 ] = 100;
  CoreGroup__Add( _this, ((CoreView)&_this->CheckerboardImage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LevelText ), 0 );
  ViewsImage_OnSetBitmap( &_this->CheckerboardImage, EwLoadResource( &ResourceDisplayTest, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->LevelText, EwLoadResource( &FontsFontNotoSansCjkJp36, 
  ResourcesFont ));
  _this->HideLevelTimer.OnTrigger = EwNewSlot( _this, SettingsDisplayBrightness_OnHideLevelSlot );

  /* Call the user defined constructor */
  SettingsDisplayBrightness_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::DisplayBrightness' */
void SettingsDisplayBrightness__ReInit( SettingsDisplayBrightness _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->CheckerboardImage );
  ViewsText__ReInit( &_this->LevelText );
  CoreTimer__ReInit( &_this->HideLevelTimer );
}

/* Finalizer method for the class 'Settings::DisplayBrightness' */
void SettingsDisplayBrightness__Done( SettingsDisplayBrightness _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->CheckerboardImage );
  ViewsText__Done( &_this->LevelText );
  CoreTimer__Done( &_this->HideLevelTimer );

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
void SettingsDisplayBrightness_UpdateViewState( SettingsDisplayBrightness _this, 
  XSet aState )
{
  ApplicationApplication App;

  CoreGroup_UpdateViewState((CoreGroup)_this, aState );
  EwTrace( "%s%t", EwLoadString( &_Const0024 ), aState );
  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );
  EwTrace( "%s%*", EwLoadString( &_Const0025 ), App );

  if ( App != 0 )
  {
    if ((( aState & CoreViewStateDialog ) == CoreViewStateDialog ))
    {
      ApplicationApplication_OnSetStatusBarVisible( App, 0 );
    }
    else
    {
      ApplicationApplication_OnSetStatusBarVisible( App, 1 );
    }
  }
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsDisplayBrightness_Init( SettingsDisplayBrightness _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  SettingsDisplayBrightness_OnSetBrightnessLevel( _this, EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass )->BrightnessLevel );
}

/* 'C' function for method : 'Settings::DisplayBrightness.OnLongKeyPressed()' */
void SettingsDisplayBrightness_OnLongKeyPressed( SettingsDisplayBrightness _this, 
  XObject sender )
{
  CoreKeyPressHandler CurrentKeyHandler = EwCastObject( sender, CoreKeyPressHandler );

  if (( CurrentKeyHandler != 0 ) && ( _this->Super5.Owner != 0 ))
  {
    switch ( CurrentKeyHandler->Code )
    {
      case CoreKeyCodeOk :
        ComponentsBaseComponent_SlideOutDialog((ComponentsBaseComponent)_this, ((CoreGroup)_this ));
      break;

      default : 
        ;
    }
  }
}

/* 'C' function for method : 'Settings::DisplayBrightness.OnShortDownKeyPressed()' */
void SettingsDisplayBrightness_OnShortDownKeyPressed( SettingsDisplayBrightness _this )
{
  XInt32 NextBrightnessLevel = _this->BrightnessLevel - 1;

  if ( 0 <= NextBrightnessLevel )
  {
    SettingsDisplayBrightness_OnSetBrightnessLevel( _this, NextBrightnessLevel );
  }
  else
  {
    SettingsDisplayBrightness_ShowLevelText( _this );
  }
}

/* 'C' function for method : 'Settings::DisplayBrightness.OnShortUpKeyPressed()' */
void SettingsDisplayBrightness_OnShortUpKeyPressed( SettingsDisplayBrightness _this )
{
  XInt32 NextBrightnessLevel = _this->BrightnessLevel + 1;

  if ( 11 > NextBrightnessLevel )
  {
    SettingsDisplayBrightness_OnSetBrightnessLevel( _this, NextBrightnessLevel );
  }
  else
  {
    SettingsDisplayBrightness_ShowLevelText( _this );
  }
}

/* 'C' function for method : 'Settings::DisplayBrightness.OnSetBrightnessLevel()' */
void SettingsDisplayBrightness_OnSetBrightnessLevel( SettingsDisplayBrightness _this, 
  XInt32 value )
{
  if ( _this->BrightnessLevel != value )
  {
    _this->BrightnessLevel = value;
    ViewsText_OnSetString( &_this->LevelText, EwNewStringInt( _this->BrightnessLevel, 
    0, 10 ));
    SettingsDisplayBrightness_ShowLevelText( _this );

    if ( EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->BrightnessLevel 
        != value )
    {
      EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->BrightnessLevel 
      = value;
    }

    DeviceInterfaceSystemDeviceClass_SetBrightness( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
    DeviceInterfaceSystemDeviceClass ), _this->BrightnessList[ EwCheckIndex( _this->BrightnessLevel, 
    11 )]);
  }
}

/* 'C' function for method : 'Settings::DisplayBrightness.OnHideLevelSlot()' */
void SettingsDisplayBrightness_OnHideLevelSlot( SettingsDisplayBrightness _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->HideLevelTimer, 0 );
  ViewsText_OnSetVisible( &_this->LevelText, 0 );
}

/* 'C' function for method : 'Settings::DisplayBrightness.ShowLevelText()' */
void SettingsDisplayBrightness_ShowLevelText( SettingsDisplayBrightness _this )
{
  ViewsText_OnSetVisible( &_this->LevelText, 1 );
  CoreTimer_OnSetEnabled( &_this->HideLevelTimer, 1 );
}

/* Variants derived from the class : 'Settings::DisplayBrightness' */
EW_DEFINE_CLASS_VARIANTS( SettingsDisplayBrightness )
EW_END_OF_CLASS_VARIANTS( SettingsDisplayBrightness )

/* Virtual Method Table (VMT) for the class : 'Settings::DisplayBrightness' */
EW_DEFINE_CLASS( SettingsDisplayBrightness, MenuBaseMenuView, CheckerboardImage, 
                 CheckerboardImage, CheckerboardImage, CheckerboardImage, BrightnessLevel, 
                 BrightnessLevel, "Settings::DisplayBrightness" )
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
  SettingsDisplayBrightness_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  SettingsDisplayBrightness_OnLongKeyPressed,
  SettingsDisplayBrightness_OnShortDownKeyPressed,
  SettingsDisplayBrightness_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemConnected,
  MenuBaseMenuView_LoadItemValid,
EW_END_OF_CLASS( SettingsDisplayBrightness )

/* Initializer for the class 'Settings::BtDiscovarable' */
void SettingsBtDiscovarable__Init( SettingsBtDiscovarable _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsBtDiscovarable );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DiscoverableText, &_this->_XObject, 0 );
  ComponentsPushButton__Init( &_this->NoButton, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TimeLeftText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NameText, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->CountDownTimer, &_this->_XObject, 0 );
  ViewsText__Init( &_this->RemainTimeText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DeviceNameText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsBtDiscovarable );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0026 );
  CoreRectView__OnSetBounds( &_this->DiscoverableText, _Const0027 );
  ViewsText_OnSetWrapText( &_this->DiscoverableText, 1 );
  ViewsText_OnSetAlignment( &_this->DiscoverableText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->DiscoverableText, EwLoadString( &_Const0028 ));
  CoreRectView__OnSetBounds( &_this->NoButton, _Const0029 );
  WidgetSetPushButton_OnSetLabel((WidgetSetPushButton)&_this->NoButton, EwLoadString( 
  &_Const002A ));
  CoreRectView__OnSetBounds( &_this->TimeLeftText, _Const002B );
  ViewsText_OnSetWrapText( &_this->TimeLeftText, 1 );
  ViewsText_OnSetAlignment( &_this->TimeLeftText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->TimeLeftText, EwLoadString( &_Const002C ));
  CoreRectView__OnSetBounds( &_this->NameText, _Const002D );
  ViewsText_OnSetWrapText( &_this->NameText, 1 );
  ViewsText_OnSetAlignment( &_this->NameText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->NameText, EwLoadString( &_Const002E ));
  CoreTimer_OnSetPeriod( &_this->CountDownTimer, 1000 );
  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 0 );
  CoreRectView__OnSetBounds( &_this->RemainTimeText, _Const002F );
  ViewsText_OnSetWrapText( &_this->RemainTimeText, 1 );
  ViewsText_OnSetAlignment( &_this->RemainTimeText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->RemainTimeText, EwLoadString( &_Const0030 ));
  _this->CountDownTimeSec = 180;
  CoreRectView__OnSetBounds( &_this->DeviceNameText, _Const0031 );
  ViewsText_OnSetWrapText( &_this->DeviceNameText, 1 );
  ViewsText_OnSetAlignment( &_this->DeviceNameText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DeviceNameText, DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceName( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )));
  CoreGroup__Add( _this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DiscoverableText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NoButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeLeftText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NameText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RemainTimeText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DeviceNameText ), 0 );
  ViewsText_OnSetFont( &_this->DiscoverableText, EwLoadResource( &FontsFontNotoSansCjkJp36, 
  ResourcesFont ));
  _this->NoButton.Super1.OnActivate = EwNewSlot( _this, SettingsBtDiscovarable_OnCancelSlot );
  WidgetSetPushButton_OnSetAppearance((WidgetSetPushButton)&_this->NoButton, EwGetAutoObject( 
  &UIConfigPushButtonConfig, WidgetSetPushButtonConfig ));
  ViewsText_OnSetFont( &_this->TimeLeftText, EwLoadResource( &FontsFontNotoSansCjkJp36, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->NameText, EwLoadResource( &FontsFontNotoSansCjkJp36, 
  ResourcesFont ));
  _this->CountDownTimer.OnTrigger = EwNewSlot( _this, SettingsBtDiscovarable_UpdateCountDownTimeSlot );
  ViewsText_OnSetFont( &_this->RemainTimeText, EwLoadResource( &FontsFontNotoSansCjkJp36, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DeviceNameText, EwLoadResource( &FontsFontNotoSansCjkJp36, 
  ResourcesFont ));

  /* Call the user defined constructor */
  SettingsBtDiscovarable_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::BtDiscovarable' */
void SettingsBtDiscovarable__ReInit( SettingsBtDiscovarable _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsText__ReInit( &_this->DiscoverableText );
  ComponentsPushButton__ReInit( &_this->NoButton );
  ViewsText__ReInit( &_this->TimeLeftText );
  ViewsText__ReInit( &_this->NameText );
  CoreTimer__ReInit( &_this->CountDownTimer );
  ViewsText__ReInit( &_this->RemainTimeText );
  ViewsText__ReInit( &_this->DeviceNameText );
}

/* Finalizer method for the class 'Settings::BtDiscovarable' */
void SettingsBtDiscovarable__Done( SettingsBtDiscovarable _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsText__Done( &_this->DiscoverableText );
  ComponentsPushButton__Done( &_this->NoButton );
  ViewsText__Done( &_this->TimeLeftText );
  ViewsText__Done( &_this->NameText );
  CoreTimer__Done( &_this->CountDownTimer );
  ViewsText__Done( &_this->RemainTimeText );
  ViewsText__Done( &_this->DeviceNameText );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
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
  CoreGroup__DismissDialog( _this->Super4.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
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
      SecondStr = EwConcatString( EwLoadString( &_Const0032 ), EwNewStringInt( Second, 
      0, 10 ));
    }
    else
    {
      SecondStr = EwNewStringInt( Second, 0, 10 );
    }

    ViewsText_OnSetString( &_this->RemainTimeText, EwConcatString( EwConcatString( 
    EwNewStringInt( _this->CountDownTimeSec / 60, 0, 10 ), EwLoadString( &_Const0033 )), 
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
EW_DEFINE_CLASS( SettingsBtDiscovarable, ComponentsBaseComponent, Rectangle, Rectangle, 
                 Rectangle, Rectangle, CountDownTimeSec, CountDownTimeSec, "Settings::BtDiscovarable" )
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  ComponentsBaseComponent_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
EW_END_OF_CLASS( SettingsBtDiscovarable )

/* Initializer for the class 'Settings::BtConnectionResult' */
void SettingsBtConnectionResult__Init( SettingsBtConnectionResult _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsBtConnectionResult );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ConnectionResultHandler, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->CloseDialogTimer, &_this->_XObject, 0 );
  ViewsText__Init( &_this->ConnectingText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsBtConnectionResult );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0026 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0034 );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Text, 0 );
  CoreTimer_OnSetPeriod( &_this->CloseDialogTimer, 2000 );
  CoreRectView__OnSetBounds( &_this->ConnectingText, _Const0035 );
  ViewsText_OnSetAlignment( &_this->ConnectingText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ConnectingText, EwLoadString( &_Const0036 ));
  CoreGroup__Add( _this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ConnectingText ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsFontNotoSansCjkJp36, 
  ResourcesFont ));
  _this->ConnectionResultHandler.OnEvent = EwNewSlot( _this, SettingsBtConnectionResult_OnConnectionResultReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->ConnectionResultHandler, &EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->ConnectionResultSystemEvent );
  _this->CloseDialogTimer.OnTrigger = EwNewSlot( _this, SettingsBtConnectionResult_OnCloseDialogSlot );
  ViewsText_OnSetFont( &_this->ConnectingText, EwLoadResource( &FontsFontNotoSansCjkJp36, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Settings::BtConnectionResult' */
void SettingsBtConnectionResult__ReInit( SettingsBtConnectionResult _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsText__ReInit( &_this->Text );
  CoreSystemEventHandler__ReInit( &_this->ConnectionResultHandler );
  CoreTimer__ReInit( &_this->CloseDialogTimer );
  ViewsText__ReInit( &_this->ConnectingText );
}

/* Finalizer method for the class 'Settings::BtConnectionResult' */
void SettingsBtConnectionResult__Done( SettingsBtConnectionResult _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsText__Done( &_this->Text );
  CoreSystemEventHandler__Done( &_this->ConnectionResultHandler );
  CoreTimer__Done( &_this->CloseDialogTimer );
  ViewsText__Done( &_this->ConnectingText );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
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
      &_Const0037 ), _this->DeviceName ), EwLoadString( &_Const0038 )));
    break;

    case EnumBtResultTIMEOUT :
    {
      ViewsText_OnSetString( &_this->Text, EwConcatString( _this->DeviceName, EwLoadString( 
      &_Const0039 )));
      ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzLeft );
    }
    break;

    case EnumBtResultFAIL :
      ViewsText_OnSetString( &_this->Text, EwConcatString( EwConcatString( EwLoadString( 
      &_Const0037 ), _this->DeviceName ), EwLoadString( &_Const003A )));
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
  CoreGroup__DismissDialog( _this->Super4.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
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
    EwLoadString( &_Const003B ), value ), EwLoadString( &_Const003C )));
  }
}

/* Variants derived from the class : 'Settings::BtConnectionResult' */
EW_DEFINE_CLASS_VARIANTS( SettingsBtConnectionResult )
EW_END_OF_CLASS_VARIANTS( SettingsBtConnectionResult )

/* Virtual Method Table (VMT) for the class : 'Settings::BtConnectionResult' */
EW_DEFINE_CLASS( SettingsBtConnectionResult, ComponentsBaseComponent, Rectangle, 
                 Rectangle, Rectangle, Rectangle, DeviceName, _None, "Settings::BtConnectionResult" )
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  ComponentsBaseComponent_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
EW_END_OF_CLASS( SettingsBtConnectionResult )

/* Initializer for the class 'Settings::BtMaxPairedDevice' */
void SettingsBtMaxPairedDevice__Init( SettingsBtMaxPairedDevice _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsBtMaxPairedDevice );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );
  ComponentsPushButton__Init( &_this->NoButton, &_this->_XObject, 0 );
  ComponentsPushButton__Init( &_this->YesButton, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsBtMaxPairedDevice );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0026 );
  CoreRectView__OnSetBounds( &_this->Text, _Const003D );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const003E ));
  CoreRectView__OnSetBounds( &_this->NoButton, _Const003F );
  WidgetSetPushButton_OnSetLabel((WidgetSetPushButton)&_this->NoButton, EwLoadString( 
  &_Const001A ));
  CoreRectView__OnSetBounds( &_this->YesButton, _Const0040 );
  WidgetSetPushButton_OnSetLabel((WidgetSetPushButton)&_this->YesButton, EwLoadString( 
  &_Const001C ));
  CoreGroup__Add( _this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NoButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->YesButton ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsFontNotoSansCjkJp36, 
  ResourcesFont ));
  _this->NoButton.Super1.OnActivate = EwNewSlot( _this, SettingsBtMaxPairedDevice_OnYesNoSlot );
  WidgetSetPushButton_OnSetAppearance((WidgetSetPushButton)&_this->NoButton, EwGetAutoObject( 
  &UIConfigPushButtonConfig, WidgetSetPushButtonConfig ));
  _this->YesButton.Super1.OnActivate = EwNewSlot( _this, SettingsBtMaxPairedDevice_OnYesNoSlot );
  WidgetSetPushButton_OnSetAppearance((WidgetSetPushButton)&_this->YesButton, EwGetAutoObject( 
  &UIConfigPushButtonConfig, WidgetSetPushButtonConfig ));
}

/* Re-Initializer for the class 'Settings::BtMaxPairedDevice' */
void SettingsBtMaxPairedDevice__ReInit( SettingsBtMaxPairedDevice _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsText__ReInit( &_this->Text );
  ComponentsPushButton__ReInit( &_this->NoButton );
  ComponentsPushButton__ReInit( &_this->YesButton );
}

/* Finalizer method for the class 'Settings::BtMaxPairedDevice' */
void SettingsBtMaxPairedDevice__Done( SettingsBtMaxPairedDevice _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsText__Done( &_this->Text );
  ComponentsPushButton__Done( &_this->NoButton );
  ComponentsPushButton__Done( &_this->YesButton );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* 'C' function for method : 'Settings::BtMaxPairedDevice.OnShortDownKeyPressed()' */
void SettingsBtMaxPairedDevice_OnShortDownKeyPressed( SettingsBtMaxPairedDevice _this )
{
  if (((CoreView)&_this->YesButton ) == _this->Super2.Focus )
  {
    CoreGroup__OnSetFocus( _this, ((CoreView)&_this->NoButton ));
  }
}

/* 'C' function for method : 'Settings::BtMaxPairedDevice.OnShortUpKeyPressed()' */
void SettingsBtMaxPairedDevice_OnShortUpKeyPressed( SettingsBtMaxPairedDevice _this )
{
  if (((CoreView)&_this->NoButton ) == _this->Super2.Focus )
  {
    CoreGroup__OnSetFocus( _this, ((CoreView)&_this->YesButton ));
  }
}

/* 'C' function for method : 'Settings::BtMaxPairedDevice.OnYesNoSlot()' */
void SettingsBtMaxPairedDevice_OnYesNoSlot( SettingsBtMaxPairedDevice _this, XObject 
  sender )
{
  if (((XObject)&_this->YesButton ) == sender )
  {
    EwPostSignal( _this->ToRemovePairedDevice, ((XObject)_this ));
  }

  CoreGroup__DismissDialog( _this->Super4.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* Variants derived from the class : 'Settings::BtMaxPairedDevice' */
EW_DEFINE_CLASS_VARIANTS( SettingsBtMaxPairedDevice )
EW_END_OF_CLASS_VARIANTS( SettingsBtMaxPairedDevice )

/* Virtual Method Table (VMT) for the class : 'Settings::BtMaxPairedDevice' */
EW_DEFINE_CLASS( SettingsBtMaxPairedDevice, ComponentsBaseComponent, ToRemovePairedDevice, 
                 ToRemovePairedDevice, Rectangle, Rectangle, _None, _None, "Settings::BtMaxPairedDevice" )
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  ComponentsBaseComponent_OnLongKeyPressed,
  SettingsBtMaxPairedDevice_OnShortDownKeyPressed,
  SettingsBtMaxPairedDevice_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
EW_END_OF_CLASS( SettingsBtMaxPairedDevice )

/* Initializer for the class 'Settings::BtPairedDeviceList' */
void SettingsBtPairedDeviceList__Init( SettingsBtPairedDeviceList _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsBtPairedDeviceList );

  /* ... then construct all embedded objects */
  MenuVerticalMenu__Init( &_this->Menu, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->RefreshListObserver, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsBtPairedDeviceList );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Menu, _Const0003 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 0 );
  _this->Menu.Focusable = 0;
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );
  _this->Menu.Super1.PassKeyHold = EwNewSlot( _this, ComponentsBaseComponent__OnLongKeyPressed );
  _this->RefreshListObserver.OnEvent = EwNewSlot( _this, SettingsBtPairedDeviceList_OnRefreshListSlot );
  CorePropertyObserver_OnSetOutlet( &_this->RefreshListObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), DeviceInterfaceBluetoothDeviceClass_OnGetRefreshPairedDeviceList, 
  DeviceInterfaceBluetoothDeviceClass_OnSetRefreshPairedDeviceList ));
}

/* Re-Initializer for the class 'Settings::BtPairedDeviceList' */
void SettingsBtPairedDeviceList__ReInit( SettingsBtPairedDeviceList _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  MenuVerticalMenu__ReInit( &_this->Menu );
  CorePropertyObserver__ReInit( &_this->RefreshListObserver );
}

/* Finalizer method for the class 'Settings::BtPairedDeviceList' */
void SettingsBtPairedDeviceList__Done( SettingsBtPairedDeviceList _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  MenuVerticalMenu__Done( &_this->Menu );
  CorePropertyObserver__Done( &_this->RefreshListObserver );

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
void SettingsBtPairedDeviceList_UpdateViewState( SettingsBtPairedDeviceList _this, 
  XSet aState )
{
  CoreGroup_UpdateViewState((CoreGroup)_this, aState );
  EwTrace( "%s%t", EwLoadString( &_Const0041 ), aState );

  if ((( aState & CoreViewStateDialog ) == CoreViewStateDialog ) && !(( aState & 
      CoreViewStatePendingFader ) == CoreViewStatePendingFader ))
  {
    SettingsBtPairedDeviceList_UpdatePairedDeviceNum( _this );
  }
}

/* 'C' function for method : 'Settings::BtPairedDeviceList.OnLongKeyPressed()' */
void SettingsBtPairedDeviceList_OnLongKeyPressed( SettingsBtPairedDeviceList _this, 
  XObject sender )
{
  CoreKeyPressHandler CurrentKeyHandler = EwCastObject( sender, CoreKeyPressHandler );

  if (( CurrentKeyHandler != 0 ) && ( _this->Super5.Owner != 0 ))
  {
    switch ( CurrentKeyHandler->Code )
    {
      case CoreKeyCodeOk :
        CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 
        0, EwNullSlot, EwNullSlot, 0 );
      break;

      default : 
        ;
    }
  }
}

/* 'C' function for method : 'Settings::BtPairedDeviceList.LoadItemClass()' */
XClass SettingsBtPairedDeviceList_LoadItemClass( SettingsBtPairedDeviceList _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

  return EW_CLASS( MenuItemBtPairedDevice );
}

/* 'C' function for method : 'Settings::BtPairedDeviceList.LoadItemTitle()' */
XString SettingsBtPairedDeviceList_LoadItemTitle( SettingsBtPairedDeviceList _this, 
  XInt32 aItemNo )
{
  XString Title;

  if ( aItemNo > 0 )
    ;

  if ( _this->PairedDeviceNum > 0 )
  {
    DeviceInterfaceBluetoothDeviceClass_GetPairedDeviceAtItem( EwGetAutoObject( 
    &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), aItemNo );
    Title = EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->PairedDeviceObj.DeviceName;
  }
  else
  {
    Title = EwLoadString( &_Const0042 );
  }

  return Title;
}

/* 'C' function for method : 'Settings::BtPairedDeviceList.OnItemActivate()' */
void SettingsBtPairedDeviceList_OnItemActivate( SettingsBtPairedDeviceList _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  MenuItemBtPairedDevice BtDeviceItem;

  if ( aItemNo >= 0 )
    ;

  BtDeviceItem = EwCastObject( aMenuItem, MenuItemBtPairedDevice );

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

/* 'C' function for method : 'Settings::BtPairedDeviceList.LoadItemConnected()' */
XBool SettingsBtPairedDeviceList_LoadItemConnected( SettingsBtPairedDeviceList _this, 
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

/* 'C' function for method : 'Settings::BtPairedDeviceList.LoadItemValid()' */
XBool SettingsBtPairedDeviceList_LoadItemValid( SettingsBtPairedDeviceList _this, 
  XInt32 aItemNo )
{
  if ( aItemNo > 0 )
    ;

  if ( _this->PairedDeviceNum > 0 )
    return 1;
  else
    return 0;
}

/* 'C' function for method : 'Settings::BtPairedDeviceList.UpdatePairedDeviceNum()' */
void SettingsBtPairedDeviceList_UpdatePairedDeviceNum( SettingsBtPairedDeviceList _this )
{
  EwTrace( "%s", EwLoadString( &_Const0043 ));
  _this->PairedDeviceNum = DeviceInterfaceBluetoothDeviceClass_OnGetPairedDeviceNum( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ));

  if ( _this->PairedDeviceNum > 0 )
  {
    MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, _this->PairedDeviceNum );
    _this->Menu.Focusable = 1;
    MenuVerticalMenu_InvalidateItems( &_this->Menu, 0, _this->PairedDeviceNum - 
    1 );
  }
  else
  {
    MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 1 );
    _this->Menu.Focusable = 0;
    MenuVerticalMenu_InvalidateItems( &_this->Menu, 0, 0 );
  }
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void SettingsBtPairedDeviceList_OnRefreshListSlot( SettingsBtPairedDeviceList _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  SettingsBtPairedDeviceList_UpdatePairedDeviceNum( _this );
}

/* Variants derived from the class : 'Settings::BtPairedDeviceList' */
EW_DEFINE_CLASS_VARIANTS( SettingsBtPairedDeviceList )
EW_END_OF_CLASS_VARIANTS( SettingsBtPairedDeviceList )

/* Virtual Method Table (VMT) for the class : 'Settings::BtPairedDeviceList' */
EW_DEFINE_CLASS( SettingsBtPairedDeviceList, MenuBaseMenuView, Menu, Menu, Menu, 
                 Menu, PairedDeviceNum, PairedDeviceNum, "Settings::BtPairedDeviceList" )
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
  SettingsBtPairedDeviceList_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  SettingsBtPairedDeviceList_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
  SettingsBtPairedDeviceList_LoadItemClass,
  SettingsBtPairedDeviceList_LoadItemTitle,
  SettingsBtPairedDeviceList_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  SettingsBtPairedDeviceList_LoadItemConnected,
  SettingsBtPairedDeviceList_LoadItemValid,
EW_END_OF_CLASS( SettingsBtPairedDeviceList )

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
  CoreRectView__OnSetBounds( &_this->Menu, _Const0003 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 3 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0044 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0045 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0046 ));
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );
  _this->Menu.Super1.PassKeyHold = EwNewSlot( _this, ComponentsBaseComponent__OnLongKeyPressed );
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

/* 'C' function for method : 'Settings::BtPairedDeviceOperation.OnLongKeyPressed()' */
void SettingsBtPairedDeviceOperation_OnLongKeyPressed( SettingsBtPairedDeviceOperation _this, 
  XObject sender )
{
  CoreKeyPressHandler CurrentKeyHandler = EwCastObject( sender, CoreKeyPressHandler );

  if (( CurrentKeyHandler != 0 ) && ( _this->Super5.Owner != 0 ))
  {
    switch ( CurrentKeyHandler->Code )
    {
      case CoreKeyCodeOk :
        ComponentsBaseComponent_SlideOutDialog((ComponentsBaseComponent)_this, ((CoreGroup)_this ));
      break;

      default : 
        ;
    }
  }
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
        CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)Dialog ), 0, 
        0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
        CoreGroup_InvalidateViewState( _this->Super5.Owner );
      }
      else
      {
        CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 
        0, EwNullSlot, EwNullSlot, 0 );
      }
    }
    break;

    case 1 :
    {
      SettingsBtConnectionResult Dialog = EwNewObject( SettingsBtConnectionResult, 
        0 );
      SettingsBtConnectionResult_OnSetDeviceName( Dialog, _this->DeviceName );
      CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)Dialog ), 0, 0, 
      0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      DeviceInterfaceBluetoothDeviceClass_ConnectPairedDevice( EwGetAutoObject( 
      &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), _this->PairedDeviceIndex );
    }
    break;

    case 2 :
    {
      DeviceInterfaceBluetoothDeviceClass_DisconnectPairedDevice( EwGetAutoObject( 
      &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), _this->PairedDeviceIndex );
      CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  SettingsBtPairedDeviceOperation_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
  SettingsBtPairedDeviceOperation_LoadItemClass,
  SettingsBtPairedDeviceOperation_LoadItemTitle,
  SettingsBtPairedDeviceOperation_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemConnected,
  MenuBaseMenuView_LoadItemValid,
EW_END_OF_CLASS( SettingsBtPairedDeviceOperation )

/* Initializer for the class 'Settings::BtDeleteBleDevice' */
void SettingsBtDeleteBleDevice__Init( SettingsBtDeleteBleDevice _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( SettingsBtDeleteBleDevice );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );
  ComponentsPushButton__Init( &_this->NoButton, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsBtDeleteBleDevice );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0026 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0047 );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Text, 0 );
  _this->DialogString1 = EwShareString( EwLoadString( &_Const0048 ));
  _this->DialogString2 = EwShareString( EwLoadString( &_Const0049 ));
  CoreRectView__OnSetBounds( &_this->NoButton, _Const004A );
  WidgetSetPushButton_OnSetLabel((WidgetSetPushButton)&_this->NoButton, EwLoadString( 
  &_Const004B ));
  CoreGroup__Add( _this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NoButton ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsFontNotoSansCjkJp36, 
  ResourcesFont ));
  _this->NoButton.Super1.OnActivate = EwNewSlot( _this, SettingsBtDeleteBleDevice_OnOkSlot );
  WidgetSetPushButton_OnSetAppearance((WidgetSetPushButton)&_this->NoButton, EwGetAutoObject( 
  &UIConfigPushButtonConfig, WidgetSetPushButtonConfig ));

  /* Call the user defined constructor */
  SettingsBtDeleteBleDevice_Init( _this, aArg );
}

/* Re-Initializer for the class 'Settings::BtDeleteBleDevice' */
void SettingsBtDeleteBleDevice__ReInit( SettingsBtDeleteBleDevice _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsText__ReInit( &_this->Text );
  ComponentsPushButton__ReInit( &_this->NoButton );
}

/* Finalizer method for the class 'Settings::BtDeleteBleDevice' */
void SettingsBtDeleteBleDevice__Done( SettingsBtDeleteBleDevice _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsText__Done( &_this->Text );
  ComponentsPushButton__Done( &_this->NoButton );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
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

  CoreGroup__DismissDialog( _this->Super4.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
  DeviceInterfaceBluetoothDeviceClass_OnSetRefreshPairedDeviceList( EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 1 );
}

/* Variants derived from the class : 'Settings::BtDeleteBleDevice' */
EW_DEFINE_CLASS_VARIANTS( SettingsBtDeleteBleDevice )
EW_END_OF_CLASS_VARIANTS( SettingsBtDeleteBleDevice )

/* Virtual Method Table (VMT) for the class : 'Settings::BtDeleteBleDevice' */
EW_DEFINE_CLASS( SettingsBtDeleteBleDevice, ComponentsBaseComponent, Rectangle, 
                 Rectangle, Rectangle, Rectangle, DeviceName, _None, "Settings::BtDeleteBleDevice" )
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  ComponentsBaseComponent_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
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
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0026 );
  CoreRectView__OnSetBounds( &_this->StatusText, _Const004C );
  ViewsText_OnSetWrapText( &_this->StatusText, 1 );
  ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const004D ));
  ViewsText_OnSetColor( &_this->StatusText, _Const004E );
  CoreTimer_OnSetPeriod( &_this->RemoveDialogTimer, 2000 );
  CoreGroup__Add( _this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->StatusText ), 0 );
  ViewsText_OnSetFont( &_this->StatusText, EwLoadResource( &FontsFontNotoSansCjkJp36, 
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
      ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const004F ));
      CoreTimer_OnSetEnabled( &_this->RemoveDialogTimer, 1 );
    }
    break;

    case EnumBtFwStatusUPDATE_ABORT :
    {
      ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const0050 ));
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

/* Embedded Wizard */
