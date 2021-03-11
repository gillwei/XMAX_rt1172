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
#include "_ComponentsBaseMainBG.h"
#include "_CoreGroup.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DevelopmentDEV_Bluetooth.h"
#include "_DevelopmentDEV_FontMenu.h"
#include "_DevelopmentDEV_FontTest.h"
#include "_DevelopmentDEV_Main.h"
#include "_DevelopmentDEV_MotoCon.h"
#include "_DevelopmentDEV_RealTimeClock.h"
#include "_DevelopmentDEV_TFTBrightness.h"
#include "_DevelopmentDEV_VehicleSupportedFunction.h"
#include "_DeviceInterfaceRtcTime.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_FactoryMain.h"
#include "_MenuItemBase.h"
#include "_MenuItemCheckbox.h"
#include "_MenuVerticalMenu.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsText.h"
#include "_ViewsWallpaper.h"
#include "_WidgetSetToggleButton.h"
#include "Core.h"
#include "Development.h"
#include "DeviceInterface.h"
#include "Fonts.h"
#include "Resource.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x0000041C, /* ratio 50.19 % */
  0xB8001F00, 0x8008C452, 0x00C60030, 0x0DE003A0, 0xF2003900, 0x80010000, 0x0032800A,
  0xC0042CE6, 0x22C0C271, 0x80021A48, 0xC3E2F233, 0x6A4D1589, 0x89B14864, 0x39263248,
  0xC528F84A, 0x28364224, 0xD001A62D, 0x21C524C6, 0x543A7000, 0x802386B8, 0x04851F08,
  0x24C75005, 0x190E8743, 0x72A9C9A2, 0x1F0B4723, 0x48B41A2D, 0x9DC42951, 0x654C0067,
  0x46AAA6E8, 0xAE31168A, 0xA3E19A34, 0x77539315, 0x9189C42A, 0x25A614E2, 0xC8843A49,
  0x8A4C2310, 0x55969B06, 0x412051C8, 0x02455197, 0x6D165875, 0x191C8655, 0x78C8347C,
  0x56B563A3, 0xF8F81001, 0x8266E8C2, 0x2E7E3914, 0x5628C3A2, 0x02B94A82, 0xCCD0EBB8,
  0x4F073BC6, 0x16F005D6, 0x3B8D4423, 0xF04C732B, 0x865DE111, 0x451AFB08, 0x802F3BD0,
  0x6001A1D2, 0x363BF8F8, 0x994A945F, 0x12822800, 0x263B4C21, 0x0DC4EF9F, 0x8E586CA0,
  0x746F9817, 0x002BB248, 0x5A29D4E9, 0xF6DD8007, 0x7600EDC6, 0x9E1A377A, 0x658C5DE0,
  0x29DD2EFF, 0x884224E6, 0xDED45112, 0x06E9DC49, 0xDC457D40, 0xFA001DD7, 0x705186C1,
  0x12876562, 0x81C51844, 0x01906617, 0xF8788140, 0x80D28831, 0xD4B42571, 0xE001F26C,
  0x7D1C439A, 0xFA82E1C0, 0x889F1881, 0x11A4A174, 0x54310C46, 0x51145862, 0x4D858008,
  0x8AD6C861, 0x1384A1F9, 0xC451F342, 0xCD244490, 0x8F8F23A6, 0x7D9CB519, 0x13F90526,
  0xE0004100, 0x0D2684C4, 0x285F91B9, 0x422104C1, 0x65086D1C, 0x5501FA87, 0x563995E5,
  0x3382D7A5, 0x8B2638FE, 0x86A89528, 0x28D90A49, 0xE23B6352, 0x478BD375, 0x9001D51A,
  0x5AA79A1E, 0xA7714D4F, 0x550A4510, 0x0E4410C6, 0x491144E1, 0x91C44A5A, 0x97EA8007,
  0x66844A1A, 0x22A1E2F4, 0xA3527A2A, 0x50849128, 0x100131A1, 0xA5D0A542, 0x86A65144,
  0x82E894A2, 0x68E48A8B, 0x97623A49, 0x191A5E1B, 0x00405465, 0x00000000
};

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault1[] =
{
  0x0000041E, /* ratio 49.72 % */
  0xB8003B00, 0x800A6452, 0x00DC0032, 0x04000320, 0xA8002100, 0x06D00434, 0x73001D40,
  0x3001A400, 0x37C76266, 0x01D00109, 0x48000720, 0x22151336, 0x801223C4, 0x0B030E4B,
  0xD0C90C1E, 0x1F8546E1, 0x790C6A29, 0x308023C6, 0x74A25000, 0xC6615408, 0xBA4B333B,
  0x20D04814, 0x77358542, 0xF3A934E2, 0x0E9E8026, 0x3A15023B, 0x8EC22191, 0x5C22AD28,
  0xCD29D31A, 0x02666889, 0xE1119865, 0x47198748, 0xD0891D02, 0x71844961, 0xEB8CCE2C,
  0xB2864012, 0xB44EA133, 0xC5E51543, 0x5239758A, 0xE4B23855, 0xE11789C9, 0xF800DDF4,
  0x85C1C2E9, 0x09F622F5, 0xCCC93192, 0x4482190E, 0x87E5D0AA, 0x121D67CA, 0x66787C7E,
  0x1D2DC5D6, 0x540D9D07, 0x77C4ECCC, 0xA975E401, 0xD7E0B501, 0x06BAE7B9, 0x802224F0,
  0xE7731320, 0xAF9088BD, 0x253104CB, 0xD928DC96, 0xD0BE8C61, 0x59DF4A09, 0xEC0C801D,
  0x68008D31, 0x003A7C61, 0xC42F2EC9, 0xEE93326C, 0xCD108767, 0x523B4CF7, 0x0EFBC625,
  0xD3543391, 0x21CC4117, 0xD1D481B3, 0x10197D1A, 0x1A00001D, 0x310392E4, 0x7519F11D,
  0xD3F15D13, 0x05299B67, 0xA94D8300, 0x484392D5, 0x859EE868, 0xA1211618, 0xD4195155,
  0xB9966E51, 0xC54C40B4, 0x7954346D, 0xA215F5DC, 0x343DE315, 0xC16F4A13, 0xE173E108,
  0x6250867D, 0x9048F1D7, 0xF44E2878, 0xC40C4B9D, 0x58611C84, 0x64906001, 0xD2E65E3F,
  0x55E9FF03, 0x399E6E52, 0xB3731E24, 0x0024A8A9, 0xE5B44E4C, 0xD04D7D8D, 0x022F9723,
  0xAD7DD9D8, 0x46D23649, 0xC124BA6B, 0xE4951B97, 0x55084490, 0xC267E504, 0x9C9B945D,
  0xDC244131, 0x31E40087, 0xC98F8D11, 0x2E4CD575, 0x48255029, 0x92D5158F, 0x24C4114B,
  0xF50A84C5, 0x3B111894, 0x476925F1, 0xC0D00163, 0x470E7581, 0xB9236C24, 0x3B76A664,
  0x67E5A6E5, 0xE978E66B, 0xDA4DF346, 0x01014B97, 0x00000000
};

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault2[] =
{
  0x000001D4, /* ratio 55.56 % */
  0xB8002500, 0x800A8452, 0x00E40034, 0x04000328, 0x01092300, 0x06E001BC, 0x00869D00,
  0x60042C98, 0x8F8022C6, 0x3C16060C, 0x43A19118, 0x44C31B29, 0xA0D22904, 0x30708442,
  0x66D8441A, 0x2204C7E3, 0x43AC4487, 0x004D8E72, 0x913A441B, 0x14E271E8, 0xFA2B2A00,
  0x2364D874, 0x00328C19, 0xF31000D0, 0x0C8D43A2, 0xA8645E2F, 0x825063F0, 0x345E2743,
  0x8022948A, 0x329A00A5, 0x2A30EA7C, 0xAF1EAA0E, 0xB1BAD46E, 0x420D002B, 0x70058E89,
  0x0059E934, 0x5800953A, 0x14304002, 0x3AA75100, 0x648689D4, 0x193E8645, 0x962BCD7A,
  0x3EB35F68, 0x0C2E0F03, 0x8C6270E0, 0xF4C65582, 0x5E27F90B, 0x972D7AB0, 0x33980A55,
  0x0188C361, 0xA00C5DBC, 0x7FC7C231, 0x5CA50325, 0xBFEAEF94, 0x8E775F9A, 0xE8B39B3D,
  0x5775A5DF, 0xE5587910, 0xC7478D99, 0x06C89C44, 0x1C27F540, 0xA8F647B3, 0xEFC7E303,
  0x00020200, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XStringRes _Const0000 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0001 = { _StringsDefault0, 0x0011 };
static const XStringRes _Const0002 = { _StringsDefault0, 0x0024 };
static const XStringRes _Const0003 = { _StringsDefault0, 0x0036 };
static const XStringRes _Const0004 = { _StringsDefault0, 0x0047 };
static const XStringRes _Const0005 = { _StringsDefault0, 0x005D };
static const XStringRes _Const0006 = { _StringsDefault0, 0x0076 };
static const XStringRes _Const0007 = { _StringsDefault0, 0x0085 };
static const XRect _Const0008 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0009 = {{ 96, 79 }, { 390, 122 }};
static const XStringRes _Const000A = { _StringsDefault0, 0x0091 };
static const XStringRes _Const000B = { _StringsDefault0, 0x0095 };
static const XStringRes _Const000C = { _StringsDefault0, 0x0099 };
static const XRect _Const000D = {{ 0, 40 }, { 240, 65 }};
static const XStringRes _Const000E = { _StringsDefault0, 0x009D };
static const XRect _Const000F = {{ 247, 40 }, { 356, 65 }};
static const XRect _Const0010 = {{ 0, 2 }, { 480, 272 }};
static const XRect _Const0011 = {{ 432, 2 }, { 482, 22 }};
static const XStringRes _Const0012 = { _StringsDefault0, 0x00B3 };
static const XStringRes _Const0013 = { _StringsDefault0, 0x00BC };
static const XStringRes _Const0014 = { _StringsDefault0, 0x00C4 };
static const XStringRes _Const0015 = { _StringsDefault0, 0x00DC };
static const XStringRes _Const0016 = { _StringsDefault0, 0x00F3 };
static const XStringRes _Const0017 = { _StringsDefault0, 0x010A };
static const XStringRes _Const0018 = { _StringsDefault0, 0x0121 };
static const XStringRes _Const0019 = { _StringsDefault0, 0x0135 };
static const XStringRes _Const001A = { _StringsDefault0, 0x0154 };
static const XStringRes _Const001B = { _StringsDefault0, 0x016D };
static const XStringRes _Const001C = { _StringsDefault0, 0x0185 };
static const XStringRes _Const001D = { _StringsDefault0, 0x0199 };
static const XStringRes _Const001E = { _StringsDefault0, 0x01B2 };
static const XStringRes _Const001F = { _StringsDefault0, 0x01CF };
static const XStringRes _Const0020 = { _StringsDefault0, 0x01ED };
static const XStringRes _Const0021 = { _StringsDefault1, 0x0002 };
static const XStringRes _Const0022 = { _StringsDefault1, 0x001F };
static const XStringRes _Const0023 = { _StringsDefault1, 0x003B };
static const XStringRes _Const0024 = { _StringsDefault1, 0x0058 };
static const XStringRes _Const0025 = { _StringsDefault1, 0x0075 };
static const XStringRes _Const0026 = { _StringsDefault1, 0x008E };
static const XStringRes _Const0027 = { _StringsDefault1, 0x00A9 };
static const XStringRes _Const0028 = { _StringsDefault1, 0x00C8 };
static const XStringRes _Const0029 = { _StringsDefault1, 0x00E2 };
static const XStringRes _Const002A = { _StringsDefault1, 0x00EB };
static const XStringRes _Const002B = { _StringsDefault1, 0x00F4 };
static const XStringRes _Const002C = { _StringsDefault1, 0x00FD };
static const XStringRes _Const002D = { _StringsDefault1, 0x0114 };
static const XStringRes _Const002E = { _StringsDefault1, 0x011C };
static const XStringRes _Const002F = { _StringsDefault1, 0x0122 };
static const XStringRes _Const0030 = { _StringsDefault1, 0x0130 };
static const XStringRes _Const0031 = { _StringsDefault1, 0x013E };
static const XStringRes _Const0032 = { _StringsDefault1, 0x014C };
static const XStringRes _Const0033 = { _StringsDefault1, 0x0157 };
static const XStringRes _Const0034 = { _StringsDefault1, 0x0165 };
static const XStringRes _Const0035 = { _StringsDefault1, 0x016E };
static const XStringRes _Const0036 = { _StringsDefault1, 0x0177 };
static const XStringRes _Const0037 = { _StringsDefault1, 0x0183 };
static const XStringRes _Const0038 = { _StringsDefault1, 0x0192 };
static const XStringRes _Const0039 = { _StringsDefault1, 0x019D };
static const XStringRes _Const003A = { _StringsDefault1, 0x01B0 };
static const XStringRes _Const003B = { _StringsDefault1, 0x01C2 };
static const XStringRes _Const003C = { _StringsDefault1, 0x01D4 };
static const XStringRes _Const003D = { _StringsDefault1, 0x01DE };
static const XStringRes _Const003E = { _StringsDefault1, 0x01EF };
static const XStringRes _Const003F = { _StringsDefault1, 0x01FC };
static const XStringRes _Const0040 = { _StringsDefault2, 0x0002 };
static const XStringRes _Const0041 = { _StringsDefault2, 0x0014 };
static const XStringRes _Const0042 = { _StringsDefault2, 0x0020 };
static const XStringRes _Const0043 = { _StringsDefault2, 0x002C };
static const XStringRes _Const0044 = { _StringsDefault2, 0x0035 };
static const XStringRes _Const0045 = { _StringsDefault2, 0x0050 };
static const XStringRes _Const0046 = { _StringsDefault2, 0x006B };
static const XStringRes _Const0047 = { _StringsDefault2, 0x0085 };
static const XStringRes _Const0048 = { _StringsDefault2, 0x00A0 };
static const XStringRes _Const0049 = { _StringsDefault2, 0x00BA };
static const XRect _Const004A = {{ 10, 50 }, { 470, 236 }};
static const XStringRes _Const004B = { _StringsDefault2, 0x00D5 };

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
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0000 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0001 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0002 ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const0003 ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const0004 ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const0005 ));
  _this->ItemTitleArray[ 6 ] = EwShareString( EwLoadString( &_Const0006 ));
  _this->ItemTitleArray[ 7 ] = EwShareString( EwLoadString( &_Const0007 ));
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 8 );
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

  if ( aItemNo < 8 )
  {
    Title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 8 )];
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
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_VehicleSupportedFunction, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 6 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_MotoCon, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 7 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_FontMenu, 
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
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
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
  CoreRectView__OnSetBounds( _this, _Const0008 );
  CoreRectView__OnSetBounds( &_this->TimeText, _Const0009 );
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
  &_Const000A )), EwNewStringInt( CurrentTime->Month, 2, 10 )), EwLoadString( &_Const000A )), 
  EwNewStringInt( CurrentTime->Day, 2, 10 )), EwLoadString( &_Const000B )), EwNewStringInt( 
  CurrentTime->Hour, 2, 10 )), EwLoadString( &_Const000C )), EwNewStringInt( CurrentTime->Minute, 
  2, 10 )), EwLoadString( &_Const000C )), EwNewStringInt( CurrentTime->Second, 2, 
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
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
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
  CoreRectView__OnSetBounds( _this, _Const0008 );
  CoreRectView__OnSetBounds( &_this->BtSwVersionTitle, _Const000D );
  ViewsText_OnSetString( &_this->BtSwVersionTitle, EwLoadString( &_Const000E ));
  CoreRectView__OnSetBounds( &_this->BtSwVersionText, _Const000F );
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
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( DevelopmentDEV_Bluetooth )

/* Initializer for the class 'Development::DEV_TFTBrightness' */
void DevelopmentDEV_TFTBrightness__Init( DevelopmentDEV_TFTBrightness _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DevelopmentDEV_TFTBrightness );

  /* ... then construct all embedded objects */
  ViewsWallpaper__Init( &_this->ChessboardImage, &_this->_XObject, 0 );
  ViewsText__Init( &_this->LevelText, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->HideLevelTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DevelopmentDEV_TFTBrightness );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0008 );
  CoreRectView__OnSetBounds( &_this->ChessboardImage, _Const0010 );
  CoreRectView__OnSetBounds( &_this->LevelText, _Const0011 );
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
  CoreGroup__Add( _this, ((CoreView)&_this->ChessboardImage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LevelText ), 0 );
  ViewsWallpaper_OnSetBitmap( &_this->ChessboardImage, EwLoadResource( &ResourceChessboard, 
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
  ViewsWallpaper__ReInit( &_this->ChessboardImage );
  ViewsText__ReInit( &_this->LevelText );
  CoreTimer__ReInit( &_this->HideLevelTimer );
}

/* Finalizer method for the class 'Development::DEV_TFTBrightness' */
void DevelopmentDEV_TFTBrightness__Done( DevelopmentDEV_TFTBrightness _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsWallpaper__Done( &_this->ChessboardImage );
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
  EwTrace( "%s%t", EwLoadString( &_Const0012 ), aState );
  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );
  EwTrace( "%s%*", EwLoadString( &_Const0013 ), App );

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
EW_DEFINE_CLASS( DevelopmentDEV_TFTBrightness, ComponentsBaseMainBG, ChessboardImage, 
                 ChessboardImage, ChessboardImage, ChessboardImage, BrightnessLevel, 
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
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
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
  CoreRectView__OnSetBounds( _this, _Const0008 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0014 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0015 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0016 ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const0017 ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const0018 ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const0019 ));
  _this->ItemTitleArray[ 6 ] = EwShareString( EwLoadString( &_Const001A ));
  _this->ItemTitleArray[ 7 ] = EwShareString( EwLoadString( &_Const001B ));
  _this->ItemTitleArray[ 8 ] = EwShareString( EwLoadString( &_Const001C ));
  _this->ItemTitleArray[ 9 ] = EwShareString( EwLoadString( &_Const001D ));
  _this->ItemTitleArray[ 10 ] = EwShareString( EwLoadString( &_Const001E ));
  _this->ItemTitleArray[ 11 ] = EwShareString( EwLoadString( &_Const001F ));
  _this->ItemTitleArray[ 12 ] = EwShareString( EwLoadString( &_Const0020 ));
  _this->ItemTitleArray[ 13 ] = EwShareString( EwLoadString( &_Const0021 ));
  _this->ItemTitleArray[ 14 ] = EwShareString( EwLoadString( &_Const0022 ));
  _this->ItemTitleArray[ 15 ] = EwShareString( EwLoadString( &_Const0023 ));
  _this->ItemTitleArray[ 16 ] = EwShareString( EwLoadString( &_Const0024 ));
  _this->ItemTitleArray[ 17 ] = EwShareString( EwLoadString( &_Const0025 ));
  _this->ItemTitleArray[ 18 ] = EwShareString( EwLoadString( &_Const0026 ));
  _this->ItemTitleArray[ 19 ] = EwShareString( EwLoadString( &_Const0027 ));
  _this->ItemTitleArray[ 20 ] = EwShareString( EwLoadString( &_Const0028 ));
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
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  DevelopmentDEV_MotoCon_LoadItemClass,
  DevelopmentDEV_MotoCon_LoadItemTitle,
  DevelopmentDEV_MotoCon_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemUnitValue,
EW_END_OF_CLASS( DevelopmentDEV_MotoCon )

/* Initializer for the class 'Development::DEV_VehicleSupportedFunction' */
void DevelopmentDEV_VehicleSupportedFunction__Init( DevelopmentDEV_VehicleSupportedFunction _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DevelopmentDEV_VehicleSupportedFunction );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DevelopmentDEV_VehicleSupportedFunction );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0008 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 27 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0029 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const002A ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const002B ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const002C ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const002D ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const002E ));
  _this->ItemTitleArray[ 6 ] = EwShareString( EwLoadString( &_Const002F ));
  _this->ItemTitleArray[ 7 ] = EwShareString( EwLoadString( &_Const0030 ));
  _this->ItemTitleArray[ 8 ] = EwShareString( EwLoadString( &_Const0031 ));
  _this->ItemTitleArray[ 9 ] = EwShareString( EwLoadString( &_Const0032 ));
  _this->ItemTitleArray[ 10 ] = EwShareString( EwLoadString( &_Const0033 ));
  _this->ItemTitleArray[ 11 ] = EwShareString( EwLoadString( &_Const0034 ));
  _this->ItemTitleArray[ 12 ] = EwShareString( EwLoadString( &_Const0035 ));
  _this->ItemTitleArray[ 13 ] = EwShareString( EwLoadString( &_Const0036 ));
  _this->ItemTitleArray[ 14 ] = EwShareString( EwLoadString( &_Const0037 ));
  _this->ItemTitleArray[ 15 ] = EwShareString( EwLoadString( &_Const0038 ));
  _this->ItemTitleArray[ 16 ] = EwShareString( EwLoadString( &_Const0039 ));
  _this->ItemTitleArray[ 17 ] = EwShareString( EwLoadString( &_Const003A ));
  _this->ItemTitleArray[ 18 ] = EwShareString( EwLoadString( &_Const003B ));
  _this->ItemTitleArray[ 19 ] = EwShareString( EwLoadString( &_Const003C ));
  _this->ItemTitleArray[ 20 ] = EwShareString( EwLoadString( &_Const003D ));
  _this->ItemTitleArray[ 21 ] = EwShareString( EwLoadString( &_Const003E ));
  _this->ItemTitleArray[ 22 ] = EwShareString( EwLoadString( &_Const003F ));
  _this->ItemTitleArray[ 23 ] = EwShareString( EwLoadString( &_Const0040 ));
  _this->ItemTitleArray[ 24 ] = EwShareString( EwLoadString( &_Const0041 ));
  _this->ItemTitleArray[ 25 ] = EwShareString( EwLoadString( &_Const0042 ));
  _this->ItemTitleArray[ 26 ] = EwShareString( EwLoadString( &_Const0043 ));
}

/* Re-Initializer for the class 'Development::DEV_VehicleSupportedFunction' */
void DevelopmentDEV_VehicleSupportedFunction__ReInit( DevelopmentDEV_VehicleSupportedFunction _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Development::DEV_VehicleSupportedFunction' */
void DevelopmentDEV_VehicleSupportedFunction__Done( DevelopmentDEV_VehicleSupportedFunction _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Development::DEV_VehicleSupportedFunction.OnShortHomeKeyActivated()' */
void DevelopmentDEV_VehicleSupportedFunction_OnShortHomeKeyActivated( DevelopmentDEV_VehicleSupportedFunction _this )
{
  CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Development::DEV_VehicleSupportedFunction.LoadItemClass()' */
XClass DevelopmentDEV_VehicleSupportedFunction_LoadItemClass( DevelopmentDEV_VehicleSupportedFunction _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

  return EW_CLASS( MenuItemCheckbox );
}

/* 'C' function for method : 'Development::DEV_VehicleSupportedFunction.LoadItemTitle()' */
XString DevelopmentDEV_VehicleSupportedFunction_LoadItemTitle( DevelopmentDEV_VehicleSupportedFunction _this, 
  XInt32 aItemNo )
{
  XString Title = 0;

  if ( aItemNo < 27 )
  {
    Title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 27 )];
  }

  return Title;
}

/* 'C' function for method : 'Development::DEV_VehicleSupportedFunction.OnItemActivate()' */
void DevelopmentDEV_VehicleSupportedFunction_OnItemActivate( DevelopmentDEV_VehicleSupportedFunction _this, 
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

  VI_set_supported_function( aItemNo, IsChecked );
}

/* 'C' function for method : 'Development::DEV_VehicleSupportedFunction.LoadItemChecked()' */
XBool DevelopmentDEV_VehicleSupportedFunction_LoadItemChecked( DevelopmentDEV_VehicleSupportedFunction _this, 
  XInt32 aItemNo )
{
  XBool IsFunctionSupported;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsFunctionSupported = 0;
  IsFunctionSupported = DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( 
  EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
  (XEnum)aItemNo );
  return IsFunctionSupported;
}

/* Variants derived from the class : 'Development::DEV_VehicleSupportedFunction' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_VehicleSupportedFunction )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_VehicleSupportedFunction )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_VehicleSupportedFunction' */
EW_DEFINE_CLASS( DevelopmentDEV_VehicleSupportedFunction, MenuBaseMenuView, ItemTitleArray, 
                 ItemTitleArray, ItemTitleArray, ItemTitleArray, ItemTitleArray, 
                 _None, "Development::DEV_VehicleSupportedFunction" )
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
  DevelopmentDEV_VehicleSupportedFunction_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  DevelopmentDEV_VehicleSupportedFunction_LoadItemClass,
  DevelopmentDEV_VehicleSupportedFunction_LoadItemTitle,
  DevelopmentDEV_VehicleSupportedFunction_OnItemActivate,
  DevelopmentDEV_VehicleSupportedFunction_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemUnitValue,
EW_END_OF_CLASS( DevelopmentDEV_VehicleSupportedFunction )

/* Initializer for the class 'Development::DEV_FontMenu' */
void DevelopmentDEV_FontMenu__Init( DevelopmentDEV_FontMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DevelopmentDEV_FontMenu );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DevelopmentDEV_FontMenu );

  /* ... and initialize objects, variables, properties, etc. */
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 6 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0044 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0045 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0046 ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const0047 ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const0048 ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const0049 ));
}

/* Re-Initializer for the class 'Development::DEV_FontMenu' */
void DevelopmentDEV_FontMenu__ReInit( DevelopmentDEV_FontMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Development::DEV_FontMenu' */
void DevelopmentDEV_FontMenu__Done( DevelopmentDEV_FontMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Development::DEV_FontMenu.LoadItemClass()' */
XClass DevelopmentDEV_FontMenu_LoadItemClass( DevelopmentDEV_FontMenu _this, XInt32 
  aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

  return EW_CLASS( MenuItemBase );
}

/* 'C' function for method : 'Development::DEV_FontMenu.LoadItemTitle()' */
XString DevelopmentDEV_FontMenu_LoadItemTitle( DevelopmentDEV_FontMenu _this, XInt32 
  aItemNo )
{
  XString Title = 0;

  if ( aItemNo < 6 )
  {
    Title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 6 )];
  }

  return Title;
}

/* 'C' function for method : 'Development::DEV_FontMenu.OnItemActivate()' */
void DevelopmentDEV_FontMenu_OnItemActivate( DevelopmentDEV_FontMenu _this, XInt32 
  aItemNo, MenuItemBase aMenuItem )
{
  DevelopmentDEV_FontTest Dialog;

  if ( aMenuItem == 0 )
    ;

  Dialog = EwNewObject( DevelopmentDEV_FontTest, 0 );

  switch ( aItemNo )
  {
    case 0 :
    {
      DevelopmentDEV_FontTest_OnSetTestFont( Dialog, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
      ResourcesFont ));
      DevelopmentDEV_FontTest_OnSetTestString( Dialog, EwLoadString( &StringsDEV_TEST_LETTERS ));
    }
    break;

    case 1 :
    {
      DevelopmentDEV_FontTest_OnSetTestFont( Dialog, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
      ResourcesFont ));
      DevelopmentDEV_FontTest_OnSetTestString( Dialog, EwLoadString( &StringsDEV_TEST_LETTERS ));
    }
    break;

    case 2 :
    {
      DevelopmentDEV_FontTest_OnSetTestFont( Dialog, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
      ResourcesFont ));
      DevelopmentDEV_FontTest_OnSetTestString( Dialog, EwLoadString( &StringsDEV_TEST_CHINESE ));
    }
    break;

    case 3 :
    {
      DevelopmentDEV_FontTest_OnSetTestFont( Dialog, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
      ResourcesFont ));
      DevelopmentDEV_FontTest_OnSetTestString( Dialog, EwLoadString( &StringsDEV_TEST_JAPANESE ));
    }
    break;

    case 4 :
    {
      DevelopmentDEV_FontTest_OnSetTestFont( Dialog, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
      ResourcesFont ));
      DevelopmentDEV_FontTest_OnSetTestString( Dialog, EwLoadString( &StringsDEV_TEST_CHINESE ));
    }
    break;

    case 5 :
    {
      DevelopmentDEV_FontTest_OnSetTestFont( Dialog, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
      ResourcesFont ));
      DevelopmentDEV_FontTest_OnSetTestString( Dialog, EwLoadString( &StringsDEV_TEST_JAPANESE ));
    }
    break;

    default : 
      ;
  }

  ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)Dialog ));
}

/* Variants derived from the class : 'Development::DEV_FontMenu' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_FontMenu )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_FontMenu )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_FontMenu' */
EW_DEFINE_CLASS( DevelopmentDEV_FontMenu, MenuBaseMenuView, ItemTitleArray, ItemTitleArray, 
                 ItemTitleArray, ItemTitleArray, ItemTitleArray, _None, "Development::DEV_FontMenu" )
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
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  DevelopmentDEV_FontMenu_LoadItemClass,
  DevelopmentDEV_FontMenu_LoadItemTitle,
  DevelopmentDEV_FontMenu_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemUnitValue,
EW_END_OF_CLASS( DevelopmentDEV_FontMenu )

/* Initializer for the class 'Development::DEV_FontTest' */
void DevelopmentDEV_FontTest__Init( DevelopmentDEV_FontTest _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DevelopmentDEV_FontTest );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DevelopmentDEV_FontTest );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super1.SlideOutEffectEnabled = 1;
  CoreRectView__OnSetBounds( &_this->Text, _Const004A );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzLeft | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Text, 0 );
  _this->PageScrollOffset = 186;
  _this->RowDistance = 31;
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Development::DEV_FontTest' */
void DevelopmentDEV_FontTest__ReInit( DevelopmentDEV_FontTest _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Text );
}

/* Finalizer method for the class 'Development::DEV_FontTest' */
void DevelopmentDEV_FontTest__Done( DevelopmentDEV_FontTest _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Text );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* 'C' function for method : 'Development::DEV_FontTest.OnShortDownKeyActivated()' */
void DevelopmentDEV_FontTest_OnShortDownKeyActivated( DevelopmentDEV_FontTest _this )
{
  /* List of temporarily used variables */
  XPoint _tmpJ0;
  if (( EwGetInt32Abs( _this->Text.ScrollOffset.Y ) + _this->PageScrollOffset ) 
      < ( ViewsText_GetNoOfRows( &_this->Text ) * _this->RowDistance ))
  {
    ( _tmpJ0 = _this->Text.ScrollOffset, ViewsText_OnSetScrollOffset( &_this->Text, 
    EwSetPointY( _tmpJ0, _tmpJ0.Y - _this->PageScrollOffset )));
  }
}

/* 'C' function for method : 'Development::DEV_FontTest.OnShortUpKeyActivated()' */
void DevelopmentDEV_FontTest_OnShortUpKeyActivated( DevelopmentDEV_FontTest _this )
{
  XInt32 OffsetY = _this->Text.ScrollOffset.Y + _this->PageScrollOffset;

  if ( OffsetY <= 0 )
  {
    ViewsText_OnSetScrollOffset( &_this->Text, EwSetPointY( _this->Text.ScrollOffset, 
    OffsetY ));
  }
}

/* 'C' function for method : 'Development::DEV_FontTest.OnSetTestFont()' */
void DevelopmentDEV_FontTest_OnSetTestFont( DevelopmentDEV_FontTest _this, ResourcesFont 
  value )
{
  if ( _this->TestFont != value )
  {
    _this->TestFont = value;
    ViewsText_OnSetFont( &_this->Text, value );

    if ( EwLoadResource( &FontsNotoSansCjkJpMedium28pt, ResourcesFont ) == value )
    {
      _this->RowDistance = 36;
    }

    _this->PageScrollOffset = ( EwGetRectH( _this->Text.Super1.Bounds ) / _this->RowDistance ) 
    * _this->RowDistance;
    EwTrace( "%s%i", EwLoadString( &_Const004B ), _this->PageScrollOffset );
  }
}

/* 'C' function for method : 'Development::DEV_FontTest.OnSetTestString()' */
void DevelopmentDEV_FontTest_OnSetTestString( DevelopmentDEV_FontTest _this, XString 
  value )
{
  if ( EwCompString( _this->TestString, value ) != 0 )
  {
    _this->TestString = EwShareString( value );
    ViewsText_OnSetString( &_this->Text, value );
  }
}

/* Variants derived from the class : 'Development::DEV_FontTest' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_FontTest )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_FontTest )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_FontTest' */
EW_DEFINE_CLASS( DevelopmentDEV_FontTest, ComponentsBaseMainBG, TestFont, Text, 
                 Text, Text, TestString, PageScrollOffset, "Development::DEV_FontTest" )
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
  DevelopmentDEV_FontTest_OnShortDownKeyActivated,
  DevelopmentDEV_FontTest_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( DevelopmentDEV_FontTest )

/* Embedded Wizard */
