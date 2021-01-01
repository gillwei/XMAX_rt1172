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
#include "_MenuItemCheckMark.h"
#include "_MenuItemCheckbox.h"
#include "_MenuPushButton.h"
#include "_MenuUpDownPushButtonSet.h"
#include "_MenuVerticalMenu.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesExternBitmap.h"
#include "_ResourcesFont.h"
#include "_SettingsAllReset.h"
#include "_SettingsAllResetCompleted.h"
#include "_SettingsBluetooth.h"
#include "_SettingsBtConnectionResult.h"
#include "_SettingsBtDeleteBleDevice.h"
#include "_SettingsBtDiscovarable.h"
#include "_SettingsBtFwUpdateDialog.h"
#include "_SettingsBtMaxPairedDevice.h"
#include "_SettingsBtPairedDeviceOperation.h"
#include "_SettingsConnection.h"
#include "_SettingsDisplayBrightness.h"
#include "_SettingsInProgress.h"
#include "_SettingsMain.h"
#include "_SettingsReset.h"
#include "_SettingsSET17_BtPairedDeviceList.h"
#include "_SettingsSET30_QRCode.h"
#include "_SettingsSystemInfo.h"
#include "_SettingsSystemMenu.h"
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
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x0000041C, /* ratio 53.23 % */
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
  0x1386153C, 0x652D086D, 0x292E6A59, 0x1666D0B6, 0x045240FD, 0x54C6F953, 0x57DD8281,
  0x002E4454, 0x178A6290, 0x4191A035, 0x99348D08, 0xA561AA4A, 0x2DAD6EA2, 0x2D4FD7E4,
  0x4360348D, 0x52E5B14E, 0xB66DC77C, 0x5E367F19, 0x11748144, 0x11911831, 0x8008514C,
  0x88FC0085, 0x64005EE1, 0x1C4E1044, 0x491B1935, 0xD3846808, 0xC6E59364, 0x682F45D3,
  0xD6421CB4, 0x4396350D, 0x1FC52514, 0x28D14E4E, 0xB6175398, 0x977F1325, 0x5CD2D5A1,
  0x54460A7A, 0xD9C15D43, 0x022C4590, 0xF14122E0, 0x5812344D, 0xDB97D622, 0xB4126145,
  0x028F4E1C, 0x07002930, 0x6E5E6468, 0x2A100030, 0xA5322F46, 0x5D4F57D0, 0xA3468044,
  0x412AB002, 0x10440A9B, 0x44B5778C, 0x6D0A44DB, 0xB2002676, 0x4A928116, 0x51483D69,
  0x2780004C, 0x68104902, 0x75782C74, 0x6790A451, 0x2898D9B4, 0x04040049, 0x00000000
};

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault1[] =
{
  0x0000042C, /* ratio 50.19 % */
  0xB8007300, 0x80040452, 0x00E60034, 0xC006E830, 0xD800859B, 0xF0D00438, 0x0032800C,
  0x331C40E4, 0x8C4361B1, 0x045CE91C, 0xC8A20640, 0xA2450687, 0xCED06919, 0x390895C8,
  0x02E8C44A, 0x61001422, 0x8884660E, 0x9CC1A450, 0x6C227316, 0x00001358, 0x888B030C,
  0x6360A000, 0x43238A47, 0xD0D87CEA, 0x3A9C19A0, 0x50049267, 0xA483C014, 0x047E9E43,
  0x00287520, 0x1A97068B, 0x2D549025, 0x9B492280, 0xB103C560, 0x6D001D61, 0xA9198800,
  0xABC3E0D1, 0x74624B06, 0x42A47319, 0xE6311A83, 0x6312B8E4, 0xA5069AC9, 0xD0FBCC8C,
  0x50BF4625, 0xAAB8032F, 0x835E61F1, 0x4C22B070, 0x48F035BC, 0x465964C2, 0xE450A9D4,
  0x0C00A30F, 0x1862CD24, 0x4EA48176, 0x4A6D1A26, 0xADCA3730, 0x34E64539, 0x1560948A,
  0x064BA100, 0xE853791F, 0x8800C74E, 0x11C9D69C, 0x79BBEE63, 0xFA48528D, 0x8C64AA04,
  0x64AF6B9C, 0xC8801AC2, 0x8A1FAB29, 0xA9211A34, 0x455A8C74, 0x53AE6E6A, 0xBB8B59A3,
  0x6A8D8AC1, 0xF703761E, 0x554471E5, 0x07ADA966, 0xDD490AC0, 0x0A4E55A4, 0x6AD82669,
  0x1267C918, 0x14418D00, 0x41F6739A, 0xA973D685, 0x4951A43D, 0x40055598, 0xA5DD131E,
  0x11725191, 0xEA4402C4, 0x0017C851, 0xD1879477, 0xF891068A, 0xE5065DD0, 0x0C891395,
  0x5E93E44D, 0x97B4E5AA, 0x844D2956, 0x8E037F18, 0x31419525, 0x41A2E4F6, 0x06B599E4,
  0xF4E56100, 0x15504F21, 0x0055A159, 0x899225DC, 0x1B757523, 0x012DDD41, 0x1D4909DB,
  0x22561C97, 0x109107DD, 0xD1015000, 0x05E1A355, 0xD1A45623, 0x58841C88, 0x8C510835,
  0xD35489CE, 0x9079B0A0, 0xF5CA9EE6, 0x729C19A7, 0x5E675972, 0x90687280, 0x16867680,
  0x694648DF, 0xCB9AE870, 0x9CE71A2D, 0x2919D9F5, 0x273A5C69, 0x24125191, 0x0C48E965,
  0x691A16AA, 0xE5D61D0A, 0xCAA9DA9E, 0xBD9AAB67, 0x25AC9B5A, 0x4363143D, 0x1016C1B0,
  0x00000000
};

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault2[] =
{
  0x00000070, /* ratio 82.14 % */
  0xB8001300, 0x000A2452, 0x00860029, 0x0C800378, 0x22003280, 0x0208240A, 0x69001400,
  0x0879E000, 0x00444D80, 0xB916060A, 0x0021B182, 0x00D0003A, 0x62A001D0, 0x2B220344,
  0xE6D0018E, 0x06910523, 0xC8545611, 0x994421D0, 0x39B8010B, 0x4A2871C9, 0x7E3F2196,
  0x0000080C, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XStringRes _Const0001 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0002 = { _StringsDefault0, 0x0010 };
static const XRect _Const0003 = {{ 0, 36 }, { 480, 272 }};
static const XStringRes _Const0004 = { _StringsDefault0, 0x0019 };
static const XStringRes _Const0005 = { _StringsDefault0, 0x0025 };
static const XStringRes _Const0006 = { _StringsDefault0, 0x0040 };
static const XStringRes _Const0007 = { _StringsDefault0, 0x0055 };
static const XStringRes _Const0008 = { _StringsDefault0, 0x006E };
static const XStringRes _Const0009 = { _StringsDefault0, 0x0083 };
static const XStringRes _Const000A = { _StringsDefault0, 0x0098 };
static const XStringRes _Const000B = { _StringsDefault0, 0x00A4 };
static const XRect _Const000C = {{ 82, 49 }, { 369, 79 }};
static const XStringRes _Const000D = { _StringsDefault0, 0x00B6 };
static const XRect _Const000E = {{ 120, 120 }, { 340, 145 }};
static const XStringRes _Const000F = { _StringsDefault0, 0x00D0 };
static const XRect _Const0010 = {{ 90, 80 }, { 362, 110 }};
static const XStringRes _Const0011 = { _StringsDefault0, 0x00E3 };
static const XRect _Const0012 = {{ 132, 150 }, { 328, 180 }};
static const XRect _Const0013 = {{ 86, 190 }, { 366, 215 }};
static const XStringRes _Const0014 = { _StringsDefault0, 0x00ED };
static const XRect _Const0015 = {{ 110, 220 }, { 343, 250 }};
static const XRect _Const0016 = {{ 10, 45 }, { 470, 169 }};
static const XStringRes _Const0017 = { _StringsDefault0, 0x0103 };
static const XRect _Const0018 = {{ 165, 176 }, { 315, 259 }};
static const XRect _Const0019 = {{ 110, 100 }, { 350, 150 }};
static const XStringRes _Const001A = { _StringsDefault0, 0x0129 };
static const XRect _Const001B = {{ 100, 95 }, { 360, 170 }};
static const XStringRes _Const001C = { _StringsDefault0, 0x013A };
static const XStringRes _Const001D = { _StringsDefault0, 0x0147 };
static const XStringRes _Const001E = { _StringsDefault0, 0x0161 };
static const XRect _Const001F = {{ 432, 2 }, { 482, 22 }};
static const XStringRes _Const0020 = { _StringsDefault0, 0x0175 };
static const XStringRes _Const0021 = { _StringsDefault0, 0x017E };
static const XRect _Const0022 = {{ 60, 34 }, { 410, 110 }};
static const XStringRes _Const0023 = { _StringsDefault0, 0x0186 };
static const XRect _Const0024 = {{ 130, 153 }, { 280, 193 }};
static const XStringRes _Const0025 = { _StringsDefault0, 0x01B5 };
static const XRect _Const0026 = {{ 120, 113 }, { 240, 153 }};
static const XStringRes _Const0027 = { _StringsDefault0, 0x01C2 };
static const XRect _Const0028 = {{ 260, 153 }, { 340, 193 }};
static const XStringRes _Const0029 = { _StringsDefault0, 0x01CA };
static const XRect _Const002A = {{ 230, 113 }, { 400, 153 }};
static const XRect _Const002B = {{ 165, 219 }, { 315, 259 }};
static const XStringRes _Const002C = { _StringsDefault0, 0x01D1 };
static const XStringRes _Const002D = { _StringsDefault0, 0x01DA };
static const XStringRes _Const002E = { _StringsDefault0, 0x01DE };
static const XRect _Const002F = {{ 40, 40 }, { 440, 230 }};
static const XRect _Const0030 = {{ 30, 90 }, { 460, 140 }};
static const XStringRes _Const0031 = { _StringsDefault0, 0x01E2 };
static const XStringRes _Const0032 = { _StringsDefault0, 0x01F0 };
static const XStringRes _Const0033 = { _StringsDefault0, 0x01FE };
static const XStringRes _Const0034 = { _StringsDefault1, 0x0002 };
static const XStringRes _Const0035 = { _StringsDefault1, 0x003B };
static const XStringRes _Const0036 = { _StringsDefault1, 0x0053 };
static const XStringRes _Const0037 = { _StringsDefault1, 0x0062 };
static const XRect _Const0038 = {{ 20, 70 }, { 460, 150 }};
static const XStringRes _Const0039 = { _StringsDefault1, 0x0066 };
static const XStringRes _Const003A = { _StringsDefault1, 0x00AB };
static const XStringRes _Const003B = { _StringsDefault1, 0x00B1 };
static const XRect _Const003C = {{ 10, 50 }, { 470, 236 }};
static const XStringRes _Const003D = { _StringsDefault1, 0x00B6 };
static const XStringRes _Const003E = { _StringsDefault1, 0x00C0 };
static const XStringRes _Const003F = { _StringsDefault1, 0x00D8 };
static const XStringRes _Const0040 = { _StringsDefault1, 0x00EC };
static const XStringRes _Const0041 = { _StringsDefault1, 0x00FD };
static const XStringRes _Const0042 = { _StringsDefault1, 0x0107 };
static const XRect _Const0043 = {{ 40, 50 }, { 440, 200 }};
static const XStringRes _Const0044 = { _StringsDefault1, 0x0114 };
static const XStringRes _Const0045 = { _StringsDefault1, 0x013F };
static const XStringRes _Const0046 = { _StringsDefault1, 0x018C };
static const XColor _Const0047 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0048 = {{ 80, 60 }, { 380, 210 }};
static const XStringRes _Const0049 = { _StringsDefault1, 0x0191 };
static const XColor _Const004A = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XStringRes _Const004B = { _StringsDefault1, 0x01B8 };
static const XStringRes _Const004C = { _StringsDefault1, 0x01D6 };
static const XRect _Const004D = {{ 20, 98 }, { 207, 227 }};
static const XRect _Const004E = {{ 210, 85 }, { 398, 135 }};
static const XRect _Const004F = {{ 210, 192 }, { 442, 240 }};
static const XRect _Const0050 = {{ 210, 137 }, { 463, 192 }};
static const XStringRes _Const0051 = { _StringsDefault1, 0x01F0 };
static const XStringRes _Const0052 = { _StringsDefault1, 0x0202 };
static const XStringRes _Const0053 = { _StringsDefault2, 0x0002 };
static const XStringRes _Const0054 = { _StringsDefault2, 0x000B };
static const XStringRes _Const0055 = { _StringsDefault2, 0x0014 };
static const XStringRes _Const0056 = { _StringsDefault2, 0x001E };
static const XStringRes _Const0057 = { _StringsDefault2, 0x0024 };

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
  EwSignal( _this->Super3.PassKeyHold, sender );
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
    ItemClass = EW_CLASS( MenuItemBase );
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
    {
      if ( !EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->IsHopperTestMode )
      {
        ComponentsBaseComponent_SlideInDialog((ComponentsBaseComponent)_this, ((CoreGroup)EwNewObject( 
        SettingsConnection, 0 )));
      }
    }
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
  SettingsMain_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  SettingsMain_LoadItemClass,
  SettingsMain_LoadItemTitle,
  SettingsMain_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
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
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 1 );
  _this->ItemClassArray[ 0 ] = EW_CLASS( MenuItemBase );
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

  if (( CurrentKeyHandler != 0 ) && ( _this->Super6.Owner != 0 ))
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
  SettingsConnection_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
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
  CoreRectView__OnSetBounds( &_this->Menu, _Const0003 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 4 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Menu, 4 );
  _this->ItemClassArray[ 0 ] = EW_CLASS( MenuItemCheckbox );
  _this->ItemClassArray[ 1 ] = EW_CLASS( MenuItemBase );
  _this->ItemClassArray[ 2 ] = EW_CLASS( MenuItemBase );
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

  if (( CurrentKeyHandler != 0 ) && ( _this->Super6.Owner != 0 ))
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
  SettingsBluetooth_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  SettingsBluetooth_LoadItemClass,
  SettingsBluetooth_LoadItemTitle,
  SettingsBluetooth_OnItemActivate,
  SettingsBluetooth_LoadItemChecked,
  SettingsBluetooth_LoadItemEnabled,
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

  if (( CurrentKeyHandler != 0 ) && ( _this->Super6.Owner != 0 ))
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
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

  return EW_CLASS( MenuItemBase );
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
  SettingsSystemMenu_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  SettingsSystemMenu_LoadItemClass,
  SettingsSystemMenu_LoadItemTitle,
  SettingsSystemMenu_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
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
  CorePropertyObserver__Init( &_this->EsnObserver, &_this->_XObject, 0 );
  ViewsText__Init( &_this->BtSwVersionTitle, &_this->_XObject, 0 );
  ViewsText__Init( &_this->BtSwVersionText, &_this->_XObject, 0 );
  CoreKeyPressHandler__Init( &_this->MagicKeyHandler, &_this->_XObject, 0 );

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
  CoreRectView__OnSetBounds( &_this->BtSwVersionTitle, _Const0013 );
  ViewsText_OnSetString( &_this->BtSwVersionTitle, EwLoadString( &_Const0014 ));
  CoreRectView__OnSetBounds( &_this->BtSwVersionText, _Const0015 );
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

/* 'C' function for method : 'Settings::SystemInfo.OnLongKeyPressed()' */
void SettingsSystemInfo_OnLongKeyPressed( SettingsSystemInfo _this, XObject sender )
{
  CoreKeyPressHandler CurrentKeyHandler = EwCastObject( sender, CoreKeyPressHandler );

  if (( CurrentKeyHandler != 0 ) && ( _this->Super6.Owner != 0 ))
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

/* 'C' function for method : 'Settings::SystemInfo.OnShortEnterKeyActivated()' */
void SettingsSystemInfo_OnShortEnterKeyActivated( SettingsSystemInfo _this )
{
  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsSET30_QRCode, 
  0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Settings::SystemInfo.OnMagicKeyReleaseSlot()' */
void SettingsSystemInfo_OnMagicKeyReleaseSlot( SettingsSystemInfo _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( !EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->IsHopperTestMode )
  {
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentMain, 
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
  SettingsSystemInfo_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  SettingsSystemInfo_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
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
  MenuUpDownPushButtonSet__Init( &_this->UpDownPushButtonSet, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( SettingsAllReset );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0016 );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const0017 ));
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const0018 );
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UpDownPushButtonSet ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->UpDownPushButtonSet.OnUpButtonReleased = EwNewSlot( _this, SettingsAllReset_OnButtonNo );
  _this->UpDownPushButtonSet.OnDownButtonReleased = EwNewSlot( _this, SettingsAllReset_OnButtonYes );
}

/* Re-Initializer for the class 'Settings::AllReset' */
void SettingsAllReset__ReInit( SettingsAllReset _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Text );
  MenuUpDownPushButtonSet__ReInit( &_this->UpDownPushButtonSet );
}

/* Finalizer method for the class 'Settings::AllReset' */
void SettingsAllReset__Done( SettingsAllReset _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Text );
  MenuUpDownPushButtonSet__Done( &_this->UpDownPushButtonSet );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Settings::AllReset.OnLongKeyPressed()' */
void SettingsAllReset_OnLongKeyPressed( SettingsAllReset _this, XObject sender )
{
  CoreKeyPressHandler CurrentKeyHandler = EwCastObject( sender, CoreKeyPressHandler );

  if (( CurrentKeyHandler != 0 ) && ( _this->Super6.Owner != 0 ))
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
EW_DEFINE_CLASS( SettingsAllReset, MenuBaseMenuView, OnYes, OnYes, Text, Text, _None, 
                 _None, "Settings::AllReset" )
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
  SettingsAllReset_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
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
  CoreRectView__OnSetBounds( &_this->Text, _Const0019 );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const001A ));
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
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
  ComponentsBaseComponent_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
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
  CoreRectView__OnSetBounds( &_this->Text, _Const001B );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const001C ));
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
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
  ComponentsBaseComponent_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
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

  if ( !EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->IsHopperTestMode )
  {
    SettingsReset_StartFactoryReset( _this );
  }
  else
  {
    CoreGroup__DismissDialog( _this->Super4.Owner, ((CoreGroup)_this ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 0 );
  }
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

  EwTrace( "%s", EwLoadString( &_Const001D ));
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
  EwTrace( "%s", EwLoadString( &_Const001E ));
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
  ComponentsBaseComponent_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
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
  CoreRectView__OnSetBounds( &_this->LevelText, _Const001F );
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
  ViewsText_OnSetFont( &_this->LevelText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
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
  EwTrace( "%s%t", EwLoadString( &_Const0020 ), aState );
  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );
  EwTrace( "%s%*", EwLoadString( &_Const0021 ), App );

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

  if (( CurrentKeyHandler != 0 ) && ( _this->Super6.Owner != 0 ))
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

/* 'C' function for method : 'Settings::DisplayBrightness.OnShortDownKeyActivated()' */
void SettingsDisplayBrightness_OnShortDownKeyActivated( SettingsDisplayBrightness _this )
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

/* 'C' function for method : 'Settings::DisplayBrightness.OnShortUpKeyActivated()' */
void SettingsDisplayBrightness_OnShortUpKeyActivated( SettingsDisplayBrightness _this )
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
  CoreGroup_UpdateLayout,
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
  SettingsDisplayBrightness_OnShortDownKeyActivated,
  SettingsDisplayBrightness_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
EW_END_OF_CLASS( SettingsDisplayBrightness )

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
  CoreRectView__OnSetBounds( &_this->DiscoverableText, _Const0022 );
  ViewsText_OnSetWrapText( &_this->DiscoverableText, 1 );
  ViewsText_OnSetAlignment( &_this->DiscoverableText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->DiscoverableText, EwLoadString( &_Const0023 ));
  CoreRectView__OnSetBounds( &_this->TimeLeftText, _Const0024 );
  ViewsText_OnSetWrapText( &_this->TimeLeftText, 1 );
  ViewsText_OnSetAlignment( &_this->TimeLeftText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->TimeLeftText, EwLoadString( &_Const0025 ));
  CoreRectView__OnSetBounds( &_this->NameText, _Const0026 );
  ViewsText_OnSetWrapText( &_this->NameText, 1 );
  ViewsText_OnSetAlignment( &_this->NameText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->NameText, EwLoadString( &_Const0027 ));
  CoreTimer_OnSetPeriod( &_this->CountDownTimer, 1000 );
  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 0 );
  CoreRectView__OnSetBounds( &_this->RemainTimeText, _Const0028 );
  ViewsText_OnSetWrapText( &_this->RemainTimeText, 1 );
  ViewsText_OnSetAlignment( &_this->RemainTimeText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->RemainTimeText, EwLoadString( &_Const0029 ));
  _this->CountDownTimeSec = 180;
  CoreRectView__OnSetBounds( &_this->DeviceNameText, _Const002A );
  ViewsText_OnSetWrapText( &_this->DeviceNameText, 1 );
  ViewsText_OnSetAlignment( &_this->DeviceNameText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DeviceNameText, DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceName( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )));
  CoreRectView__OnSetBounds( &_this->PushButton, _Const002B );
  MenuPushButton_OnSetTitle( &_this->PushButton, EwLoadString( &_Const002C ));
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
      SecondStr = EwConcatString( EwLoadString( &_Const002D ), EwNewStringInt( Second, 
      0, 10 ));
    }
    else
    {
      SecondStr = EwNewStringInt( Second, 0, 10 );
    }

    ViewsText_OnSetString( &_this->RemainTimeText, EwConcatString( EwConcatString( 
    EwNewStringInt( _this->CountDownTimeSec / 60, 0, 10 ), EwLoadString( &_Const002E )), 
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
  ComponentsBaseComponent_OnLongKeyPressed,
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
  CoreRectView__OnSetBounds( &_this->Text, _Const002F );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Text, 0 );
  CoreTimer_OnSetPeriod( &_this->CloseDialogTimer, 2000 );
  CoreRectView__OnSetBounds( &_this->ConnectingText, _Const0030 );
  ViewsText_OnSetAlignment( &_this->ConnectingText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ConnectingText, EwLoadString( &_Const0031 ));
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
      &_Const0032 ), _this->DeviceName ), EwLoadString( &_Const0033 )));
    break;

    case EnumBtResultTIMEOUT :
    {
      ViewsText_OnSetString( &_this->Text, EwConcatString( _this->DeviceName, EwLoadString( 
      &_Const0034 )));
      ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzLeft );
    }
    break;

    case EnumBtResultFAIL :
      ViewsText_OnSetString( &_this->Text, EwConcatString( EwConcatString( EwLoadString( 
      &_Const0032 ), _this->DeviceName ), EwLoadString( &_Const0035 )));
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
    EwLoadString( &_Const0036 ), value ), EwLoadString( &_Const0037 )));
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
  ComponentsBaseComponent_OnLongKeyPressed,
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
  CoreRectView__OnSetBounds( &_this->Text, _Const0038 );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const0039 ));
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const0018 );
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &_Const003A ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &_Const003B ));
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
  ComponentsBaseComponent_OnLongKeyPressed,
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
  CoreRectView__OnSetBounds( &_this->Menu, _Const0003 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 1 );
  _this->Menu.Focusable = 0;
  MenuVerticalMenu_OnSetItemHeight( &_this->Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Menu, 4 );
  CoreRectView__OnSetBounds( &_this->NoDataText, _Const003C );
  ViewsText_OnSetString( &_this->NoDataText, EwLoadString( &_Const003D ));
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NoDataText ), 0 );
  _this->Menu.Super1.PassKeyHold = EwNewSlot( _this, ComponentsBaseComponent__OnLongKeyPressed );
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

/* 'C' function for method : 'Settings::SET17_BtPairedDeviceList.OnLongKeyPressed()' */
void SettingsSET17_BtPairedDeviceList_OnLongKeyPressed( SettingsSET17_BtPairedDeviceList _this, 
  XObject sender )
{
  CoreKeyPressHandler CurrentKeyHandler = EwCastObject( sender, CoreKeyPressHandler );

  if (( CurrentKeyHandler != 0 ) && ( _this->Super6.Owner != 0 ))
  {
    switch ( CurrentKeyHandler->Code )
    {
      case CoreKeyCodeOk :
        CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 
        0, EwNullSlot, EwNullSlot, 0 );
      break;

      default : 
        ;
    }
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
  EwTrace( "%s", EwLoadString( &_Const003E ));
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

  EwTrace( "%s", EwLoadString( &_Const003F ));
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
  SettingsSET17_BtPairedDeviceList_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
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
  CoreRectView__OnSetBounds( &_this->Menu, _Const0003 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 3 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0040 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0041 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0042 ));
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

  if (( CurrentKeyHandler != 0 ) && ( _this->Super6.Owner != 0 ))
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
  SettingsBtPairedDeviceOperation_OnLongKeyPressed,
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
  CoreRectView__OnSetBounds( &_this->Text, _Const0043 );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Text, 0 );
  _this->DialogString1 = EwShareString( EwLoadString( &_Const0044 ));
  _this->DialogString2 = EwShareString( EwLoadString( &_Const0045 ));
  CoreRectView__OnSetBounds( &_this->PushButton, _Const002B );
  MenuPushButton_OnSetTitle( &_this->PushButton, EwLoadString( &_Const0046 ));
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
  ComponentsBaseComponent_OnLongKeyPressed,
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
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0047 );
  CoreRectView__OnSetBounds( &_this->StatusText, _Const0048 );
  ViewsText_OnSetWrapText( &_this->StatusText, 1 );
  ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const0049 ));
  ViewsText_OnSetColor( &_this->StatusText, _Const004A );
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
      ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const004B ));
      CoreTimer_OnSetEnabled( &_this->RemoveDialogTimer, 1 );
    }
    break;

    case EnumBtFwStatusUPDATE_ABORT :
    {
      ViewsText_OnSetString( &_this->StatusText, EwLoadString( &_Const004C ));
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
  CoreRectView__OnSetBounds( &_this->QrCode, _Const004D );
  ViewsImage_OnSetAlignment( &_this->QrCode, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  _this->PixelPerModule = 1;
  CoreRectView__OnSetBounds( &_this->PixelText, _Const004E );
  ViewsText_OnSetAlignment( &_this->PixelText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->PixelText, 0 );
  CoreRectView__OnSetBounds( &_this->QrCodeWidthText, _Const004F );
  ViewsText_OnSetAlignment( &_this->QrCodeWidthText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->QrCodeWidthText, 0 );
  CoreRectView__OnSetBounds( &_this->QrCodeContent, _Const0050 );
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

/* 'C' function for method : 'Settings::SET30_QRCode.OnLongKeyPressed()' */
void SettingsSET30_QRCode_OnLongKeyPressed( SettingsSET30_QRCode _this, XObject 
  sender )
{
  CoreKeyPressHandler CurrentKeyHandler = EwCastObject( sender, CoreKeyPressHandler );

  if (( CurrentKeyHandler != 0 ) && ( _this->Super6.Owner != 0 ))
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
    EwTrace( "%s", EwLoadString( &_Const0051 ));
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
    EwTrace( "%s", EwLoadString( &_Const0052 ));
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
  ResourcesExternBitmap ), EwConcatString( EwLoadString( &_Const0053 ), EwNewStringInt( 
  _this->PixelPerModule, 0, 10 )));
  ViewsText_OnSetString( &_this->PixelText, EwConcatString( EwNewStringInt( _this->PixelPerModule, 
  0, 10 ), EwLoadString( &_Const0054 )));
  QrCodeWidth = ( 33 * _this->PixelPerModule ) * 0.019350f;
  ViewsText_OnSetString( &_this->QrCodeWidthText, EwConcatString( EwConcatString( 
  EwLoadString( &_Const0055 ), EwNewStringFloat( QrCodeWidth, 0, -1 )), EwLoadString( 
  &_Const0056 )));
  ViewsText_OnSetString( &_this->QrCodeContent, EwConcatString( EwLoadString( &_Const0057 ), 
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
  SettingsSET30_QRCode_OnLongKeyPressed,
  SettingsSET30_QRCode_OnShortDownKeyActivated,
  SettingsSET30_QRCode_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
EW_END_OF_CLASS( SettingsSET30_QRCode )

/* Embedded Wizard */
