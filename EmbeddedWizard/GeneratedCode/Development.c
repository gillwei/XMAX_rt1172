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
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DevelopmentDEV_Bluetooth.h"
#include "_DevelopmentDEV_Main.h"
#include "_DevelopmentDEV_MotoCon.h"
#include "_DevelopmentDEV_RealTimeClock.h"
#include "_DevelopmentDEV_TFTBrightness.h"
#include "_DevelopmentDEV_VehicleFeature.h"
#include "_DeviceInterfaceRtcTime.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_FactoryMain.h"
#include "_MenuItemBase.h"
#include "_MenuItemCheckbox.h"
#include "_MenuVerticalMenu.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsText.h"
#include "_WidgetSetToggleButton.h"
#include "Core.h"
#include "Development.h"
#include "DeviceInterface.h"
#include "Fonts.h"
#include "Resource.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000430, /* ratio 49.25 % */
  0xB8001F00, 0x8008C452, 0x00C60030, 0x0DE003A0, 0xF2003900, 0x80010000, 0x0032800A,
  0xC0042CE6, 0x22C0C271, 0x80021A48, 0xC3E2F233, 0x6A4D1589, 0x89B14864, 0x39263248,
  0xC528F84A, 0x28364224, 0xD001A62D, 0x21C524C6, 0x543A7000, 0x802386B8, 0x04851F08,
  0x24C75005, 0x190E8743, 0x72A9C9A2, 0x1F0B4723, 0x48B41A2D, 0x9DC42951, 0x654C0067,
  0x46AAA6E8, 0xAE31168A, 0xA0933A34, 0x77539315, 0x9189C42A, 0x088C41A2, 0x88853619,
  0x8240A391, 0x048AA32E, 0xDA2CB0EA, 0x12390CAA, 0xE8C2F8F8, 0x15148262, 0x1461D47F,
  0x5CA5412B, 0x69114C01, 0x839DE366, 0x7802EB27, 0xC6A2118B, 0x268D859D, 0x337088F8,
  0x0131BCC3, 0x925D6020, 0x00C8E524, 0x0D747C30, 0x004B221A, 0x2800994A, 0x4C211282,
  0x037D263B, 0x401A79D8, 0x2F1CB0D9, 0x90E8DEEC, 0xC2005764, 0x0E345389, 0x8DE97900,
  0x073B97CC, 0x74801D00, 0x96319B82, 0xE7114985, 0x1127314E, 0xD1489442, 0xA9E6C9FB,
  0x0F574FA3, 0xCF803D80, 0xD5346D78, 0x05F11477, 0x214C1C40, 0xFB051466, 0x7D9FE78D,
  0x94B42571, 0xD5953B68, 0x7D1C4399, 0x287AE0D0, 0x5CDE2841, 0x14E4653E, 0x5585E378,
  0x360849A0, 0x005596A5, 0x7F61B064, 0xD084E128, 0x24312873, 0x19A24911, 0x1C82A298,
  0x499E86E9, 0x4004FE1C, 0x81380010, 0x6E328192, 0x307F9184, 0x471086C1, 0x9FC8FE0C,
  0x6911407F, 0x922B89E4, 0x7D469A94, 0x7FA2F8B5, 0x86A00215, 0x84310A49, 0xED1478DA,
  0x36789378, 0x97C1D51A, 0x52866128, 0xA7354D4F, 0xA50A4510, 0x0E4410C6, 0x491144E1,
  0x91C44A49, 0x975E7007, 0xCA229D19, 0xE39E5285, 0x9F9229ED, 0x67542125, 0x0A14216C,
  0x21144A5C, 0x22A2E76A, 0x9F68E595, 0x20649128, 0xCA4E6772, 0x3A529BD1, 0x3CA62718,
  0x9E29B825, 0xE7C46E9D, 0x85951452, 0x1A2C1E11, 0x00404005, 0x00000000
};

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault1[] =
{
  0x00000408, /* ratio 49.61 % */
  0xB8003900, 0x800A6452, 0x00DC0032, 0x04000320, 0x01093480, 0x06F0018C, 0x11879B40,
  0x089434CF, 0x36000C20, 0x547A371F, 0x9DC00738, 0x00E40083, 0x6061D958, 0x190A9441,
  0x70A8843A, 0x348BC562, 0x38746801, 0x904823D1, 0x9C22190E, 0x42273208, 0x220D2E96,
  0x0D11B98C, 0x4B0C8F4A, 0xB1B3A422, 0x548F5524, 0x89543A11, 0x3A800E30, 0x04AEAD28,
  0xCC292190, 0x50ED1B85, 0xA2F6090C, 0x15158E56, 0x11595552, 0x700057E8, 0xBB306EC6,
  0xB543AD14, 0xDDBAEF75, 0xDCE23368, 0x561976B5, 0xE570A93C, 0x6511BE07, 0xD6CC0002,
  0x6B9E4A22, 0x1C44A6E5, 0x9098A3D2, 0xF002B96F, 0x640352BA, 0x634598A6, 0x09E00CBD,
  0x82002A00, 0x15ED146C, 0x2BB1422C, 0xAD84B813, 0x875E6212, 0x26EAC631, 0x6FE31BC8,
  0xBB843200, 0xC5A00234, 0xC7BECDEB, 0x04D9705E, 0x0ECDD665, 0x09D74085, 0x855529C0,
  0x749401B7, 0x9AA19B28, 0x0E5C08B1, 0xE2715909, 0x7606B19A, 0x706F5803, 0x479703A5,
  0xD2BF1FB6, 0x9560F371, 0x9AB641F6, 0x053C4843, 0x020075C0, 0xFC411F70, 0x419924E5,
  0xD7D68913, 0xE4B80B4A, 0x1576441A, 0x04805D17, 0x001CD159, 0x120421DA, 0x88690E55,
  0x31047297, 0xC146E127, 0x66DCB6E5, 0xDC95BD08, 0x24B80C4A, 0x013B5A9B, 0x315E5060,
  0x03D2B5A2, 0x92A5DDEA, 0xC4399A68, 0x51216D9C, 0xDC64E368, 0x88977919, 0x22F04D63,
  0x17AD7692, 0x9D827897, 0x57441548, 0x92C124AE, 0x2254A910, 0xB8F1174A, 0x89606AD9,
  0xDA4BA5E6, 0x002086AD, 0x61E46C79, 0x77715760, 0x040A0014, 0x23605159, 0x0456381D,
  0x9FD1492E, 0x45BD1A42, 0xF5624604, 0x0D9DD139, 0x6B2617C8, 0xE7E6662A, 0x8712524A,
  0xD24E6891, 0x8246D865, 0x7791A442, 0xE9697D63, 0x7A456FA3, 0x30008925, 0x93199281,
  0x4052B58E, 0x00000000
};

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault2[] =
{
  0x00000046, /* ratio 85.71 % */
  0xB8001900, 0x800A8452, 0x00E40034, 0x04000328, 0x010B2900, 0xA0084984, 0x068240A2,
  0xD3842215, 0x84418010, 0x4C56226D, 0x10C8B030, 0x020E758A, 0xA2B22398, 0x000080CB,
  0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XStringRes _Const0001 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0002 = { _StringsDefault0, 0x0011 };
static const XStringRes _Const0003 = { _StringsDefault0, 0x0024 };
static const XStringRes _Const0004 = { _StringsDefault0, 0x0036 };
static const XStringRes _Const0005 = { _StringsDefault0, 0x0047 };
static const XStringRes _Const0006 = { _StringsDefault0, 0x005D };
static const XStringRes _Const0007 = { _StringsDefault0, 0x006F };
static const XRect _Const0008 = {{ 96, 79 }, { 390, 122 }};
static const XStringRes _Const0009 = { _StringsDefault0, 0x007E };
static const XStringRes _Const000A = { _StringsDefault0, 0x0082 };
static const XStringRes _Const000B = { _StringsDefault0, 0x0086 };
static const XRect _Const000C = {{ 0, 40 }, { 240, 65 }};
static const XStringRes _Const000D = { _StringsDefault0, 0x008A };
static const XRect _Const000E = {{ 247, 40 }, { 356, 65 }};
static const XRect _Const000F = {{ 432, 2 }, { 482, 22 }};
static const XStringRes _Const0010 = { _StringsDefault0, 0x00A0 };
static const XStringRes _Const0011 = { _StringsDefault0, 0x00A9 };
static const XStringRes _Const0012 = { _StringsDefault0, 0x00B1 };
static const XStringRes _Const0013 = { _StringsDefault0, 0x00C9 };
static const XStringRes _Const0014 = { _StringsDefault0, 0x00E0 };
static const XStringRes _Const0015 = { _StringsDefault0, 0x00F7 };
static const XStringRes _Const0016 = { _StringsDefault0, 0x010E };
static const XStringRes _Const0017 = { _StringsDefault0, 0x0122 };
static const XStringRes _Const0018 = { _StringsDefault0, 0x0141 };
static const XStringRes _Const0019 = { _StringsDefault0, 0x015A };
static const XStringRes _Const001A = { _StringsDefault0, 0x0172 };
static const XStringRes _Const001B = { _StringsDefault0, 0x0186 };
static const XStringRes _Const001C = { _StringsDefault0, 0x019F };
static const XStringRes _Const001D = { _StringsDefault0, 0x01BC };
static const XStringRes _Const001E = { _StringsDefault0, 0x01DA };
static const XStringRes _Const001F = { _StringsDefault0, 0x01FB };
static const XStringRes _Const0020 = { _StringsDefault1, 0x0002 };
static const XStringRes _Const0021 = { _StringsDefault1, 0x001E };
static const XStringRes _Const0022 = { _StringsDefault1, 0x003B };
static const XStringRes _Const0023 = { _StringsDefault1, 0x0058 };
static const XStringRes _Const0024 = { _StringsDefault1, 0x0071 };
static const XStringRes _Const0025 = { _StringsDefault1, 0x008C };
static const XStringRes _Const0026 = { _StringsDefault1, 0x00AB };
static const XStringRes _Const0027 = { _StringsDefault1, 0x00C5 };
static const XStringRes _Const0028 = { _StringsDefault1, 0x00CE };
static const XStringRes _Const0029 = { _StringsDefault1, 0x00D7 };
static const XStringRes _Const002A = { _StringsDefault1, 0x00E0 };
static const XStringRes _Const002B = { _StringsDefault1, 0x00F7 };
static const XStringRes _Const002C = { _StringsDefault1, 0x00FF };
static const XStringRes _Const002D = { _StringsDefault1, 0x0105 };
static const XStringRes _Const002E = { _StringsDefault1, 0x0113 };
static const XStringRes _Const002F = { _StringsDefault1, 0x0121 };
static const XStringRes _Const0030 = { _StringsDefault1, 0x012F };
static const XStringRes _Const0031 = { _StringsDefault1, 0x013A };
static const XStringRes _Const0032 = { _StringsDefault1, 0x0148 };
static const XStringRes _Const0033 = { _StringsDefault1, 0x0151 };
static const XStringRes _Const0034 = { _StringsDefault1, 0x015A };
static const XStringRes _Const0035 = { _StringsDefault1, 0x0166 };
static const XStringRes _Const0036 = { _StringsDefault1, 0x0175 };
static const XStringRes _Const0037 = { _StringsDefault1, 0x0180 };
static const XStringRes _Const0038 = { _StringsDefault1, 0x0193 };
static const XStringRes _Const0039 = { _StringsDefault1, 0x01A5 };
static const XStringRes _Const003A = { _StringsDefault1, 0x01B7 };
static const XStringRes _Const003B = { _StringsDefault1, 0x01C1 };
static const XStringRes _Const003C = { _StringsDefault1, 0x01D2 };
static const XStringRes _Const003D = { _StringsDefault1, 0x01DF };
static const XStringRes _Const003E = { _StringsDefault1, 0x01F2 };
static const XStringRes _Const003F = { _StringsDefault2, 0x0002 };
static const XStringRes _Const0040 = { _StringsDefault2, 0x000E };
static const XStringRes _Const0041 = { _StringsDefault2, 0x001A };

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

/* User defined inline code: 'Development::Inline' */
#include "TEST_pub.h"
#include "VI_pub.h"

/* Initializer for the class 'Development::DEV_Main' */
void DevelopmentDEV_Main__Init( DevelopmentDEV_Main _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DevelopmentDEV_Main );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DevelopmentDEV_Main );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0001 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0002 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0003 ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const0004 ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const0005 ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const0006 ));
  _this->ItemTitleArray[ 6 ] = EwShareString( EwLoadString( &_Const0007 ));
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 7 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
}

/* Re-Initializer for the class 'Development::DEV_Main' */
void DevelopmentDEV_Main__ReInit( DevelopmentDEV_Main _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Development::DEV_Main' */
void DevelopmentDEV_Main__Done( DevelopmentDEV_Main _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Development::DEV_Main.OnShortHomeKeyActivated()' */
void DevelopmentDEV_Main_OnShortHomeKeyActivated( DevelopmentDEV_Main _this )
{
  CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Development::DEV_Main.LoadItemClass()' */
XClass DevelopmentDEV_Main_LoadItemClass( DevelopmentDEV_Main _this, XInt32 aItemNo )
{
  XClass ItemClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemClass = 0;

  switch ( aItemNo )
  {
    case 1 :
      ItemClass = EW_CLASS( MenuItemCheckbox );
    break;

    default : 
      ItemClass = EW_CLASS( MenuItemBase );
  }

  return ItemClass;
}

/* 'C' function for method : 'Development::DEV_Main.LoadItemTitle()' */
XString DevelopmentDEV_Main_LoadItemTitle( DevelopmentDEV_Main _this, XInt32 aItemNo )
{
  XString Title = 0;

  if ( aItemNo < 7 )
  {
    Title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 7 )];
  }

  return Title;
}

/* 'C' function for method : 'Development::DEV_Main.OnItemActivate()' */
void DevelopmentDEV_Main_OnItemActivate( DevelopmentDEV_Main _this, XInt32 aItemNo, 
  MenuItemBase aMenuItem )
{
  if ( aMenuItem == 0 )
    ;

  switch ( aItemNo )
  {
    case 0 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( FactoryMain, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 1 :
      EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->IsHopperTestMode 
      = (XBool)!EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->IsHopperTestMode;
    break;

    case 2 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_RealTimeClock, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 3 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_Bluetooth, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 4 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_TFTBrightness, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 5 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_VehicleFeature, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 6 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_MotoCon, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Development::DEV_Main.LoadItemChecked()' */
XBool DevelopmentDEV_Main_LoadItemChecked( DevelopmentDEV_Main _this, XInt32 aItemNo )
{
  XBool IsChecked;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsChecked = 0;

  switch ( aItemNo )
  {
    case 1 :
      IsChecked = EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->IsHopperTestMode;
    break;

    default : 
      ;
  }

  return IsChecked;
}

/* Variants derived from the class : 'Development::DEV_Main' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_Main )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_Main )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_Main' */
EW_DEFINE_CLASS( DevelopmentDEV_Main, MenuBaseMenuView, ItemTitleArray, ItemTitleArray, 
                 ItemTitleArray, ItemTitleArray, ItemTitleArray, _None, "Development::DEV_Main" )
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
  DevelopmentDEV_Main_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  DevelopmentDEV_Main_LoadItemClass,
  DevelopmentDEV_Main_LoadItemTitle,
  DevelopmentDEV_Main_OnItemActivate,
  DevelopmentDEV_Main_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemUnitValue,
EW_END_OF_CLASS( DevelopmentDEV_Main )

/* Initializer for the class 'Development::DEV_RealTimeClock' */
void DevelopmentDEV_RealTimeClock__Init( DevelopmentDEV_RealTimeClock _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DevelopmentDEV_RealTimeClock );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->OnUpdateLocalTimeEventHandler, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TimeText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DevelopmentDEV_RealTimeClock );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->TimeText, _Const0008 );
  ViewsText_OnSetAlignment( &_this->TimeText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TimeText, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeText ), 0 );
  _this->OnUpdateLocalTimeEventHandler.OnEvent = EwNewSlot( _this, DevelopmentDEV_RealTimeClock_OnUpdateLocalTimeSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->OnUpdateLocalTimeEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->UpdateLocalTimeSystemEvent );
  ViewsText_OnSetFont( &_this->TimeText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Development::DEV_RealTimeClock' */
void DevelopmentDEV_RealTimeClock__ReInit( DevelopmentDEV_RealTimeClock _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->OnUpdateLocalTimeEventHandler );
  ViewsText__ReInit( &_this->TimeText );
}

/* Finalizer method for the class 'Development::DEV_RealTimeClock' */
void DevelopmentDEV_RealTimeClock__Done( DevelopmentDEV_RealTimeClock _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  CoreSystemEventHandler__Done( &_this->OnUpdateLocalTimeEventHandler );
  ViewsText__Done( &_this->TimeText );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* 'C' function for method : 'Development::DEV_RealTimeClock.OnShortHomeKeyActivated()' */
void DevelopmentDEV_RealTimeClock_OnShortHomeKeyActivated( DevelopmentDEV_RealTimeClock _this )
{
  CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Development::DEV_RealTimeClock.OnUpdateLocalTimeSlot()' */
void DevelopmentDEV_RealTimeClock_OnUpdateLocalTimeSlot( DevelopmentDEV_RealTimeClock _this, 
  XObject sender )
{
  DeviceInterfaceRtcTime CurrentTime;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CurrentTime = DeviceInterfaceSystemDeviceClass_GetLocalTime( EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ));
  ViewsText_OnSetString( &_this->TimeText, EwConcatString( EwConcatString( EwConcatString( 
  EwConcatString( EwConcatString( EwConcatString( EwConcatString( EwConcatString( 
  EwConcatString( EwConcatString( EwNewStringInt( CurrentTime->Year, 4, 10 ), EwLoadString( 
  &_Const0009 )), EwNewStringInt( CurrentTime->Month, 2, 10 )), EwLoadString( &_Const0009 )), 
  EwNewStringInt( CurrentTime->Day, 2, 10 )), EwLoadString( &_Const000A )), EwNewStringInt( 
  CurrentTime->Hour, 2, 10 )), EwLoadString( &_Const000B )), EwNewStringInt( CurrentTime->Minute, 
  2, 10 )), EwLoadString( &_Const000B )), EwNewStringInt( CurrentTime->Second, 2, 
  10 )));
}

/* Variants derived from the class : 'Development::DEV_RealTimeClock' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_RealTimeClock )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_RealTimeClock )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_RealTimeClock' */
EW_DEFINE_CLASS( DevelopmentDEV_RealTimeClock, ComponentsBaseMainBG, OnUpdateLocalTimeEventHandler, 
                 OnUpdateLocalTimeEventHandler, OnUpdateLocalTimeEventHandler, OnUpdateLocalTimeEventHandler, 
                 _None, _None, "Development::DEV_RealTimeClock" )
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
  DevelopmentDEV_RealTimeClock_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( DevelopmentDEV_RealTimeClock )

/* Initializer for the class 'Development::DEV_Bluetooth' */
void DevelopmentDEV_Bluetooth__Init( DevelopmentDEV_Bluetooth _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DevelopmentDEV_Bluetooth );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->BtSwVersionTitle, &_this->_XObject, 0 );
  ViewsText__Init( &_this->BtSwVersionText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DevelopmentDEV_Bluetooth );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->BtSwVersionTitle, _Const000C );
  ViewsText_OnSetString( &_this->BtSwVersionTitle, EwLoadString( &_Const000D ));
  CoreRectView__OnSetBounds( &_this->BtSwVersionText, _Const000E );
  ViewsText_OnSetAlignment( &_this->BtSwVersionText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->BtSwVersionText, DeviceInterfaceSystemDeviceClass_OnGetBtSoftwareVersion( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
  CoreGroup__Add( _this, ((CoreView)&_this->BtSwVersionTitle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BtSwVersionText ), 0 );
  ViewsText_OnSetFont( &_this->BtSwVersionTitle, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->BtSwVersionText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Development::DEV_Bluetooth' */
void DevelopmentDEV_Bluetooth__ReInit( DevelopmentDEV_Bluetooth _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->BtSwVersionTitle );
  ViewsText__ReInit( &_this->BtSwVersionText );
}

/* Finalizer method for the class 'Development::DEV_Bluetooth' */
void DevelopmentDEV_Bluetooth__Done( DevelopmentDEV_Bluetooth _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->BtSwVersionTitle );
  ViewsText__Done( &_this->BtSwVersionText );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* 'C' function for method : 'Development::DEV_Bluetooth.OnShortHomeKeyActivated()' */
void DevelopmentDEV_Bluetooth_OnShortHomeKeyActivated( DevelopmentDEV_Bluetooth _this )
{
  CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* Variants derived from the class : 'Development::DEV_Bluetooth' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_Bluetooth )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_Bluetooth )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_Bluetooth' */
EW_DEFINE_CLASS( DevelopmentDEV_Bluetooth, ComponentsBaseMainBG, BtSwVersionTitle, 
                 BtSwVersionTitle, BtSwVersionTitle, BtSwVersionTitle, _None, _None, 
                 "Development::DEV_Bluetooth" )
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
  DevelopmentDEV_Bluetooth_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( DevelopmentDEV_Bluetooth )

/* Initializer for the class 'Development::DEV_TFTBrightness' */
void DevelopmentDEV_TFTBrightness__Init( DevelopmentDEV_TFTBrightness _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DevelopmentDEV_TFTBrightness );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->CheckerboardImage, &_this->_XObject, 0 );
  ViewsText__Init( &_this->LevelText, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->HideLevelTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DevelopmentDEV_TFTBrightness );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->CheckerboardImage, _Const0000 );
  ViewsImage_OnSetFrameNumber( &_this->CheckerboardImage, 1 );
  CoreRectView__OnSetBounds( &_this->LevelText, _Const000F );
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
  _this->HideLevelTimer.OnTrigger = EwNewSlot( _this, DevelopmentDEV_TFTBrightness_OnHideLevelSlot );

  /* Call the user defined constructor */
  DevelopmentDEV_TFTBrightness_Init( _this, aArg );
}

/* Re-Initializer for the class 'Development::DEV_TFTBrightness' */
void DevelopmentDEV_TFTBrightness__ReInit( DevelopmentDEV_TFTBrightness _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->CheckerboardImage );
  ViewsText__ReInit( &_this->LevelText );
  CoreTimer__ReInit( &_this->HideLevelTimer );
}

/* Finalizer method for the class 'Development::DEV_TFTBrightness' */
void DevelopmentDEV_TFTBrightness__Done( DevelopmentDEV_TFTBrightness _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->CheckerboardImage );
  ViewsText__Done( &_this->LevelText );
  CoreTimer__Done( &_this->HideLevelTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void DevelopmentDEV_TFTBrightness_Init( DevelopmentDEV_TFTBrightness _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  DevelopmentDEV_TFTBrightness_OnSetBrightnessLevel( _this, EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass )->BrightnessLevel );
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
void DevelopmentDEV_TFTBrightness_UpdateViewState( DevelopmentDEV_TFTBrightness _this, 
  XSet aState )
{
  ApplicationApplication App;

  CoreGroup_UpdateViewState((CoreGroup)_this, aState );
  EwTrace( "%s%t", EwLoadString( &_Const0010 ), aState );
  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );
  EwTrace( "%s%*", EwLoadString( &_Const0011 ), App );

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

/* 'C' function for method : 'Development::DEV_TFTBrightness.OnShortDownKeyActivated()' */
void DevelopmentDEV_TFTBrightness_OnShortDownKeyActivated( DevelopmentDEV_TFTBrightness _this )
{
  XInt32 NextBrightnessLevel = _this->BrightnessLevel - 1;

  if ( 0 <= NextBrightnessLevel )
  {
    DevelopmentDEV_TFTBrightness_OnSetBrightnessLevel( _this, NextBrightnessLevel );
  }
  else
  {
    DevelopmentDEV_TFTBrightness_ShowLevelText( _this );
  }
}

/* 'C' function for method : 'Development::DEV_TFTBrightness.OnShortUpKeyActivated()' */
void DevelopmentDEV_TFTBrightness_OnShortUpKeyActivated( DevelopmentDEV_TFTBrightness _this )
{
  XInt32 NextBrightnessLevel = _this->BrightnessLevel + 1;

  if ( 11 > NextBrightnessLevel )
  {
    DevelopmentDEV_TFTBrightness_OnSetBrightnessLevel( _this, NextBrightnessLevel );
  }
  else
  {
    DevelopmentDEV_TFTBrightness_ShowLevelText( _this );
  }
}

/* 'C' function for method : 'Development::DEV_TFTBrightness.OnShortHomeKeyActivated()' */
void DevelopmentDEV_TFTBrightness_OnShortHomeKeyActivated( DevelopmentDEV_TFTBrightness _this )
{
  CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Development::DEV_TFTBrightness.OnSetBrightnessLevel()' */
void DevelopmentDEV_TFTBrightness_OnSetBrightnessLevel( DevelopmentDEV_TFTBrightness _this, 
  XInt32 value )
{
  if ( _this->BrightnessLevel != value )
  {
    _this->BrightnessLevel = value;
    ViewsText_OnSetString( &_this->LevelText, EwNewStringInt( _this->BrightnessLevel, 
    0, 10 ));
    DevelopmentDEV_TFTBrightness_ShowLevelText( _this );

    if ( EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->BrightnessLevel 
        != value )
    {
      EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->BrightnessLevel 
      = value;
    }

    DeviceInterfaceSystemDeviceClass_SetTFTDutyCycle( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
    DeviceInterfaceSystemDeviceClass ), _this->BrightnessList[ EwCheckIndex( _this->BrightnessLevel, 
    11 )]);
  }
}

/* 'C' function for method : 'Development::DEV_TFTBrightness.OnHideLevelSlot()' */
void DevelopmentDEV_TFTBrightness_OnHideLevelSlot( DevelopmentDEV_TFTBrightness _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->HideLevelTimer, 0 );
  ViewsText_OnSetVisible( &_this->LevelText, 0 );
}

/* 'C' function for method : 'Development::DEV_TFTBrightness.ShowLevelText()' */
void DevelopmentDEV_TFTBrightness_ShowLevelText( DevelopmentDEV_TFTBrightness _this )
{
  ViewsText_OnSetVisible( &_this->LevelText, 1 );
  CoreTimer_OnSetEnabled( &_this->HideLevelTimer, 1 );
}

/* Variants derived from the class : 'Development::DEV_TFTBrightness' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_TFTBrightness )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_TFTBrightness )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_TFTBrightness' */
EW_DEFINE_CLASS( DevelopmentDEV_TFTBrightness, ComponentsBaseMainBG, CheckerboardImage, 
                 CheckerboardImage, CheckerboardImage, CheckerboardImage, BrightnessLevel, 
                 BrightnessLevel, "Development::DEV_TFTBrightness" )
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
  DevelopmentDEV_TFTBrightness_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  DevelopmentDEV_TFTBrightness_OnShortDownKeyActivated,
  DevelopmentDEV_TFTBrightness_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  DevelopmentDEV_TFTBrightness_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( DevelopmentDEV_TFTBrightness )

/* Initializer for the class 'Development::DEV_MotoCon' */
void DevelopmentDEV_MotoCon__Init( DevelopmentDEV_MotoCon _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DevelopmentDEV_MotoCon );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DevelopmentDEV_MotoCon );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0012 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0013 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0014 ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const0015 ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const0016 ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const0017 ));
  _this->ItemTitleArray[ 6 ] = EwShareString( EwLoadString( &_Const0018 ));
  _this->ItemTitleArray[ 7 ] = EwShareString( EwLoadString( &_Const0019 ));
  _this->ItemTitleArray[ 8 ] = EwShareString( EwLoadString( &_Const001A ));
  _this->ItemTitleArray[ 9 ] = EwShareString( EwLoadString( &_Const001B ));
  _this->ItemTitleArray[ 10 ] = EwShareString( EwLoadString( &_Const001C ));
  _this->ItemTitleArray[ 11 ] = EwShareString( EwLoadString( &_Const001D ));
  _this->ItemTitleArray[ 12 ] = EwShareString( EwLoadString( &_Const001E ));
  _this->ItemTitleArray[ 13 ] = EwShareString( EwLoadString( &_Const001F ));
  _this->ItemTitleArray[ 14 ] = EwShareString( EwLoadString( &_Const0020 ));
  _this->ItemTitleArray[ 15 ] = EwShareString( EwLoadString( &_Const0021 ));
  _this->ItemTitleArray[ 16 ] = EwShareString( EwLoadString( &_Const0022 ));
  _this->ItemTitleArray[ 17 ] = EwShareString( EwLoadString( &_Const0023 ));
  _this->ItemTitleArray[ 18 ] = EwShareString( EwLoadString( &_Const0024 ));
  _this->ItemTitleArray[ 19 ] = EwShareString( EwLoadString( &_Const0025 ));
  _this->ItemTitleArray[ 20 ] = EwShareString( EwLoadString( &_Const0026 ));
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 21 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
}

/* Re-Initializer for the class 'Development::DEV_MotoCon' */
void DevelopmentDEV_MotoCon__ReInit( DevelopmentDEV_MotoCon _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Development::DEV_MotoCon' */
void DevelopmentDEV_MotoCon__Done( DevelopmentDEV_MotoCon _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Development::DEV_MotoCon.OnShortHomeKeyActivated()' */
void DevelopmentDEV_MotoCon_OnShortHomeKeyActivated( DevelopmentDEV_MotoCon _this )
{
  CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Development::DEV_MotoCon.LoadItemClass()' */
XClass DevelopmentDEV_MotoCon_LoadItemClass( DevelopmentDEV_MotoCon _this, XInt32 
  aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

  return EW_CLASS( MenuItemBase );
}

/* 'C' function for method : 'Development::DEV_MotoCon.LoadItemTitle()' */
XString DevelopmentDEV_MotoCon_LoadItemTitle( DevelopmentDEV_MotoCon _this, XInt32 
  aItemNo )
{
  XString Title = 0;

  if ( aItemNo < 21 )
  {
    Title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 21 )];
  }

  return Title;
}

/* 'C' function for method : 'Development::DEV_MotoCon.OnItemActivate()' */
void DevelopmentDEV_MotoCon_OnItemActivate( DevelopmentDEV_MotoCon _this, XInt32 
  aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if (( aMenuItem == 0 ) || ( aItemNo > 0 ))
    ;

  TEST_motocon_tx( aItemNo );
}

/* Variants derived from the class : 'Development::DEV_MotoCon' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_MotoCon )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_MotoCon )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_MotoCon' */
EW_DEFINE_CLASS( DevelopmentDEV_MotoCon, MenuBaseMenuView, ItemTitleArray, ItemTitleArray, 
                 ItemTitleArray, ItemTitleArray, ItemTitleArray, _None, "Development::DEV_MotoCon" )
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
  DevelopmentDEV_MotoCon_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  DevelopmentDEV_MotoCon_LoadItemClass,
  DevelopmentDEV_MotoCon_LoadItemTitle,
  DevelopmentDEV_MotoCon_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemUnitValue,
EW_END_OF_CLASS( DevelopmentDEV_MotoCon )

/* Initializer for the class 'Development::DEV_VehicleFeature' */
void DevelopmentDEV_VehicleFeature__Init( DevelopmentDEV_VehicleFeature _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DevelopmentDEV_VehicleFeature );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DevelopmentDEV_VehicleFeature );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0027 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0028 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0029 ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const002A ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const002B ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const002C ));
  _this->ItemTitleArray[ 6 ] = EwShareString( EwLoadString( &_Const002D ));
  _this->ItemTitleArray[ 7 ] = EwShareString( EwLoadString( &_Const002E ));
  _this->ItemTitleArray[ 8 ] = EwShareString( EwLoadString( &_Const002F ));
  _this->ItemTitleArray[ 9 ] = EwShareString( EwLoadString( &_Const0030 ));
  _this->ItemTitleArray[ 10 ] = EwShareString( EwLoadString( &_Const0031 ));
  _this->ItemTitleArray[ 11 ] = EwShareString( EwLoadString( &_Const0032 ));
  _this->ItemTitleArray[ 12 ] = EwShareString( EwLoadString( &_Const0033 ));
  _this->ItemTitleArray[ 13 ] = EwShareString( EwLoadString( &_Const0034 ));
  _this->ItemTitleArray[ 14 ] = EwShareString( EwLoadString( &_Const0035 ));
  _this->ItemTitleArray[ 15 ] = EwShareString( EwLoadString( &_Const0036 ));
  _this->ItemTitleArray[ 16 ] = EwShareString( EwLoadString( &_Const0037 ));
  _this->ItemTitleArray[ 17 ] = EwShareString( EwLoadString( &_Const0038 ));
  _this->ItemTitleArray[ 18 ] = EwShareString( EwLoadString( &_Const0039 ));
  _this->ItemTitleArray[ 19 ] = EwShareString( EwLoadString( &_Const003A ));
  _this->ItemTitleArray[ 20 ] = EwShareString( EwLoadString( &_Const003B ));
  _this->ItemTitleArray[ 21 ] = EwShareString( EwLoadString( &_Const003C ));
  _this->ItemTitleArray[ 22 ] = EwShareString( EwLoadString( &_Const003D ));
  _this->ItemTitleArray[ 23 ] = EwShareString( EwLoadString( &_Const003E ));
  _this->ItemTitleArray[ 24 ] = EwShareString( EwLoadString( &_Const003F ));
  _this->ItemTitleArray[ 25 ] = EwShareString( EwLoadString( &_Const0040 ));
  _this->ItemTitleArray[ 26 ] = EwShareString( EwLoadString( &_Const0041 ));
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 27 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
}

/* Re-Initializer for the class 'Development::DEV_VehicleFeature' */
void DevelopmentDEV_VehicleFeature__ReInit( DevelopmentDEV_VehicleFeature _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Development::DEV_VehicleFeature' */
void DevelopmentDEV_VehicleFeature__Done( DevelopmentDEV_VehicleFeature _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Development::DEV_VehicleFeature.OnShortHomeKeyActivated()' */
void DevelopmentDEV_VehicleFeature_OnShortHomeKeyActivated( DevelopmentDEV_VehicleFeature _this )
{
  CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Development::DEV_VehicleFeature.LoadItemClass()' */
XClass DevelopmentDEV_VehicleFeature_LoadItemClass( DevelopmentDEV_VehicleFeature _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

  return EW_CLASS( MenuItemCheckbox );
}

/* 'C' function for method : 'Development::DEV_VehicleFeature.LoadItemTitle()' */
XString DevelopmentDEV_VehicleFeature_LoadItemTitle( DevelopmentDEV_VehicleFeature _this, 
  XInt32 aItemNo )
{
  XString Title = 0;

  if ( aItemNo < 27 )
  {
    Title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 27 )];
  }

  return Title;
}

/* 'C' function for method : 'Development::DEV_VehicleFeature.OnItemActivate()' */
void DevelopmentDEV_VehicleFeature_OnItemActivate( DevelopmentDEV_VehicleFeature _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  XBool IsChecked;
  MenuItemCheckbox CheckBoxItem;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if (( aMenuItem == 0 ) || ( aItemNo > 0 ))
    ;

  IsChecked = 0;
  CheckBoxItem = EwCastObject( aMenuItem, MenuItemCheckbox );

  if ( CheckBoxItem != 0 )
  {
    IsChecked = CheckBoxItem->CheckBoxButton.Checked;
  }

  VI_set_feature_supported( aItemNo, IsChecked );
}

/* 'C' function for method : 'Development::DEV_VehicleFeature.LoadItemChecked()' */
XBool DevelopmentDEV_VehicleFeature_LoadItemChecked( DevelopmentDEV_VehicleFeature _this, 
  XInt32 aItemNo )
{
  XBool IsFeatureSupported;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsFeatureSupported = 0;
  IsFeatureSupported = DeviceInterfaceVehicleDeviceClass_IsVehicleFeatureSupported( 
  EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
  (XEnum)aItemNo );
  return IsFeatureSupported;
}

/* Variants derived from the class : 'Development::DEV_VehicleFeature' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_VehicleFeature )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_VehicleFeature )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_VehicleFeature' */
EW_DEFINE_CLASS( DevelopmentDEV_VehicleFeature, MenuBaseMenuView, ItemTitleArray, 
                 ItemTitleArray, ItemTitleArray, ItemTitleArray, ItemTitleArray, 
                 _None, "Development::DEV_VehicleFeature" )
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
  DevelopmentDEV_VehicleFeature_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  DevelopmentDEV_VehicleFeature_LoadItemClass,
  DevelopmentDEV_VehicleFeature_LoadItemTitle,
  DevelopmentDEV_VehicleFeature_OnItemActivate,
  DevelopmentDEV_VehicleFeature_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemUnitValue,
EW_END_OF_CLASS( DevelopmentDEV_VehicleFeature )

/* Embedded Wizard */
