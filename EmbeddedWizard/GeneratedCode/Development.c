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
#include "_ApplicationApplication.h"
#include "_ComponentsBaseMainBG.h"
#include "_CoreGroup.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DevelopmentDEV_Bluetooth.h"
#include "_DevelopmentDEV_EEPROMTest.h"
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
#include "_InspectionTFT_Main.h"
#include "_MenuItemBase.h"
#include "_MenuItemCheckbox.h"
#include "_MenuVerticalMenu.h"
#include "_NavigationNAV03_TBTListView.h"
#include "_NavigationNAV05_TBTView.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsText.h"
#include "_ViewsWallpaper.h"
#include "_WeatherWEA01_Main.h"
#include "Core.h"
#include "Development.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Fonts.h"
#include "Resource.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault0[] =
{
  0x00000406, /* ratio 50.49 % */
  0xB8001F00, 0x8008C452, 0x00C60030, 0x0DE003A0, 0xF2003900, 0xA0010000, 0x64004349,
  0xC0019400, 0x22C0C271, 0x01C22E48, 0x44237230, 0x0234548A, 0x6270B398, 0x37198BC5,
  0xD0481472, 0x0C854220, 0x8894421D, 0x864B2552, 0x947C251C, 0x1B2112A2, 0x00D32997,
  0xE292A368, 0x1D470010, 0x11C35C2A, 0x428F8440, 0xA3A802A0, 0x8645E732, 0x6CFA9068,
  0xC7C2D1C9, 0x52530694, 0xE9510ACC, 0x19610019, 0xB2CB19BA, 0x559FC6E7, 0xA2B47C33,
  0x8552AC32, 0x9C523747, 0x61A495B2, 0x66372D9D, 0xEB9068A4, 0x3F33855C, 0xF5E8745A,
  0x76B9C3A9, 0xC0059257, 0xCBC1A3E0, 0x0DE3332D, 0x800931FA, 0x264B2CB9, 0xB414A96C,
  0x3E0ECDE8, 0x1B300116, 0x4FA2000A, 0x0A06BE5E, 0x2CC7C160, 0x50008800, 0x6F2C7C3B,
  0x64016708, 0x8004CE25, 0xABBBBC52, 0x72982722, 0x4ABE4BB9, 0x7B11DE37, 0x8F853377,
  0x0CB68A57, 0x73BAF26B, 0x73A3DB95, 0x45F1F024, 0x2904F655, 0xA3A8FFAE, 0xD68259AA,
  0xD3345F07, 0x88423B72, 0x57C00182, 0x76B52C79, 0x7C09555A, 0x0C611084, 0x4C90C421,
  0xA0A02000, 0x27D52361, 0x7C18001F, 0x0F41E0C4, 0x001CA685, 0x1146CDCD, 0xA1D91942,
  0x3D0C4412, 0x6F5CDE77, 0x86817471, 0xD234392D, 0xE6D2205A, 0x98008912, 0x9A8A5E58,
  0x5562C529, 0xD844122F, 0xA62D7346, 0x74625295, 0x2E445FF8, 0x8161D8E9, 0x22E5CD17,
  0xE462448C, 0x391B76D2, 0x2E89D708, 0x1C400801, 0xDBC77585, 0x54AA4277, 0x9D7D9364,
  0x2B535807, 0x439FC002, 0xE5406D1C, 0xE93A4681, 0xB9816AD7, 0x0C46D2C4, 0x4523F8F1,
  0x91C9825E, 0x6956655E, 0xFD0851E4, 0xAA4492D9, 0x9812AA01, 0x5559895C, 0xE9D28586,
  0x004153D2, 0x2A9744E0, 0x95989A21, 0x25A46514, 0x59911C42, 0x3A9690C4, 0x9BA64005,
  0x48DDDA3A, 0xD559EDA0, 0x000101AC, 0x00000000
};

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault1[] =
{
  0x0000040C, /* ratio 45.56 % */
  0xB8003300, 0x800A6452, 0x00DC0032, 0x04000320, 0x01093480, 0x600839A8, 0x0F3A000C,
  0xE889BC01, 0x3A800E30, 0x6000C200, 0x1E631193, 0x0C352800, 0x2151482C, 0x3E6D8743,
  0xD1939802, 0x1B8B43A2, 0xA3946215, 0x00436471, 0x3C8A7C70, 0x4AC37289, 0xFE5D0883,
  0x2692098C, 0x7B159B44, 0x73C004EA, 0x41874923, 0x88A53645, 0x96D1C3D2, 0x74CA970B,
  0xD4A6F51A, 0x5E7B548B, 0xA1169A05, 0xB71B8C9D, 0x349AFCA6, 0x35B1CC2C, 0xB88CE27F,
  0x854FED53, 0x45A0F108, 0xC46E81C9, 0xEE151997, 0xE151098D, 0x7D21BD19, 0x90A915AE,
  0x3C8A1DE6, 0xAC307651, 0xA8E361D4, 0x7C47191B, 0xC924566C, 0x5A110CB5, 0xA119F924,
  0x0176CE66, 0x9228A1A0, 0x18844D21, 0x28C4D21D, 0x87422312, 0x047A113C, 0x4A377089,
  0x22090200, 0xADF3FC3D, 0x7F319955, 0xF69BE683, 0x419043B9, 0xEC46C28B, 0xE8C827DC,
  0xADA27390, 0xC321D3EA, 0xA215978D, 0x2C5DB0BC, 0x9F62DF48, 0x5B3B6756, 0x14006BBC,
  0x4F7DDFDA, 0x845B3751, 0xD981AD22, 0x0729EC71, 0x31E06216, 0x0E489104, 0x77D24775,
  0x1D94C9FD, 0x9001FA72, 0x020C4660, 0x117420E0, 0x7A40079E, 0x606615C7, 0x65F9DC5D,
  0x3D7D7896, 0x62489247, 0x705D24F8, 0xD7347800, 0x0599CC88, 0x3E116F63, 0x00150001,
  0x8C13F104, 0x1C6451C3, 0x44B1C94A, 0xF23A4FE2, 0x4C43A3E8, 0x80800624, 0x13C64443,
  0xD1999F62, 0x54164A13, 0x55946518, 0x00049000, 0x2428FC44, 0x76DDE25B, 0x7634579C,
  0xD259DF46, 0x4298F591, 0x9244FDA6, 0x05AD145B, 0xAC0D71E4, 0x8F46E3C4, 0x4FE7363D,
  0x5C769E3E, 0x05A67A02, 0xC50E5051, 0x01A2DC70, 0x00000001, 0x00000000
};

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault2[] =
{
  0x0000041C, /* ratio 51.33 % */
  0xB8001300, 0x000A8452, 0x00D20039, 0x04000380, 0x22001900, 0x0468240A, 0x06000B40,
  0x18642A11, 0x22C0C2F1, 0x0194004D, 0xC1E44740, 0x9C840086, 0x00067854, 0xDC00921A,
  0x80039C98, 0x0020C3A6, 0x135000C8, 0x8F820011, 0x01B00043, 0x18C006F0, 0x1A7A6B00,
  0xE83068F8, 0x3E0E9E94, 0x10B9591E, 0x610015E5, 0x8931B64E, 0x82546230, 0x2D66474F,
  0xC98910E9, 0x7EA15CB1, 0xA650AABC, 0x8F4F874E, 0x52391C22, 0x1F05C466, 0x8A14249F,
  0x8E5EE332, 0xB116BE00, 0xC9A53162, 0x523164A1, 0x48B13C05, 0x1D26B9C5, 0xF8D9E8C6,
  0x0E91C9B1, 0xF0644621, 0x001DA711, 0xA556E12D, 0x03E7B39B, 0x9CEA00A0, 0x71332C84,
  0x8723D545, 0xE00CEDDE, 0xAF006873, 0xF09CF70F, 0x946C7731, 0xA4CA8B41, 0xC32B7AA9,
  0xF7850A92, 0x215B4094, 0x47068742, 0x568B4F1A, 0xCC88E435, 0x5B44AA09, 0x3CC22472,
  0x45170928, 0xC9B4158C, 0x17500A88, 0x75BE5F1D, 0xA51F08CF, 0x198F37B4, 0x34BD9100,
  0x7995664B, 0x06C46474, 0x9905ED4C, 0x57299643, 0x11BC4452, 0x91739064, 0x819276E1,
  0x92C7C928, 0x1761304B, 0x15F58320, 0x0E4C1318, 0x19926131, 0x99C00215, 0x28360282,
  0x6D27589F, 0x5546A016, 0x56D7B741, 0x58D001FE, 0xA6A90850, 0x6E314D10, 0x441391F0,
  0x53D454C1, 0x5284D5FB, 0xF5BD2348, 0x54340010, 0x23879895, 0x8A5DD495, 0x1048E800,
  0xF495458F, 0x01367CE3, 0x99696440, 0x92838001, 0xD3093128, 0xA0015D93, 0x5A3D8EC1,
  0x1B900009, 0x129414D2, 0x00012C00, 0x991C509C, 0xBD4143A4, 0xE74CD6D4, 0x95668945,
  0x1C39B23D, 0x39C66F00, 0x42750027, 0x59A1E774, 0x48E41431, 0xE674F638, 0x8A066994,
  0xCA87A125, 0x5F91E749, 0x9EE149E2, 0x6529F690, 0xB8FA5411, 0x6A85A5E6, 0x28A7288A,
  0x7CE8D9C1, 0xC158C6A1, 0xD5667547, 0x3D7148D2, 0x7A50D7C8, 0xA4620881, 0x5280E925,
  0x04053D4F, 0x00000000
};

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault3[] =
{
  0x000000BC, /* ratio 68.09 % */
  0xB8002F00, 0x000AE452, 0x00D20039, 0x0CA003A0, 0xD8001000, 0x60030800, 0x0087C2CE,
  0x70044CE0, 0x184621A6, 0x3000F000, 0xC9801232, 0x488B0308, 0x0C9148F1, 0x2D148946,
  0x91A88432, 0x26874762, 0x8834A42B, 0x87432150, 0xBC567F10, 0x000AB108, 0x00920027,
  0x295182A0, 0x1E009311, 0xB0E95CA4, 0x48A34625, 0xE8853295, 0x94842A14, 0x3CB22243,
  0xD268F578, 0x3C014DA5, 0x20350A85, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XStringRes _Const0000 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0001 = { _StringsDefault0, 0x0011 };
static const XStringRes _Const0002 = { _StringsDefault0, 0x0024 };
static const XStringRes _Const0003 = { _StringsDefault0, 0x0033 };
static const XStringRes _Const0004 = { _StringsDefault0, 0x0045 };
static const XStringRes _Const0005 = { _StringsDefault0, 0x0056 };
static const XStringRes _Const0006 = { _StringsDefault0, 0x006C };
static const XStringRes _Const0007 = { _StringsDefault0, 0x0085 };
static const XStringRes _Const0008 = { _StringsDefault0, 0x0094 };
static const XStringRes _Const0009 = { _StringsDefault0, 0x00A0 };
static const XStringRes _Const000A = { _StringsDefault0, 0x00B2 };
static const XStringRes _Const000B = { _StringsDefault0, 0x00C0 };
static const XStringRes _Const000C = { _StringsDefault0, 0x00CB };
static const XStringRes _Const000D = { _StringsDefault0, 0x00DB };
static const XStringRes _Const000E = { _StringsDefault0, 0x00EB };
static const XRect _Const000F = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0010 = {{ 96, 79 }, { 390, 122 }};
static const XStringRes _Const0011 = { _StringsDefault0, 0x00FF };
static const XStringRes _Const0012 = { _StringsDefault0, 0x0103 };
static const XStringRes _Const0013 = { _StringsDefault0, 0x0107 };
static const XRect _Const0014 = {{ 0, 40 }, { 240, 65 }};
static const XStringRes _Const0015 = { _StringsDefault0, 0x010B };
static const XRect _Const0016 = {{ 247, 40 }, { 356, 65 }};
static const XRect _Const0017 = {{ 0, 2 }, { 480, 272 }};
static const XRect _Const0018 = {{ 432, 2 }, { 482, 22 }};
static const XStringRes _Const0019 = { _StringsDefault0, 0x0121 };
static const XStringRes _Const001A = { _StringsDefault0, 0x012A };
static const XStringRes _Const001B = { _StringsDefault0, 0x0132 };
static const XStringRes _Const001C = { _StringsDefault0, 0x014A };
static const XStringRes _Const001D = { _StringsDefault0, 0x0161 };
static const XStringRes _Const001E = { _StringsDefault0, 0x0178 };
static const XStringRes _Const001F = { _StringsDefault0, 0x018F };
static const XStringRes _Const0020 = { _StringsDefault0, 0x01A3 };
static const XStringRes _Const0021 = { _StringsDefault0, 0x01BE };
static const XStringRes _Const0022 = { _StringsDefault0, 0x01D7 };
static const XStringRes _Const0023 = { _StringsDefault0, 0x01EF };
static const XStringRes _Const0024 = { _StringsDefault1, 0x0002 };
static const XStringRes _Const0025 = { _StringsDefault1, 0x001B };
static const XStringRes _Const0026 = { _StringsDefault1, 0x0035 };
static const XStringRes _Const0027 = { _StringsDefault1, 0x0050 };
static const XStringRes _Const0028 = { _StringsDefault1, 0x006E };
static const XStringRes _Const0029 = { _StringsDefault1, 0x0088 };
static const XStringRes _Const002A = { _StringsDefault1, 0x00A4 };
static const XStringRes _Const002B = { _StringsDefault1, 0x00C1 };
static const XStringRes _Const002C = { _StringsDefault1, 0x00DE };
static const XStringRes _Const002D = { _StringsDefault1, 0x00F7 };
static const XStringRes _Const002E = { _StringsDefault1, 0x0112 };
static const XStringRes _Const002F = { _StringsDefault1, 0x0129 };
static const XStringRes _Const0030 = { _StringsDefault1, 0x013D };
static const XStringRes _Const0031 = { _StringsDefault1, 0x0154 };
static const XStringRes _Const0032 = { _StringsDefault1, 0x016D };
static const XStringRes _Const0033 = { _StringsDefault1, 0x0189 };
static const XStringRes _Const0034 = { _StringsDefault1, 0x01A3 };
static const XStringRes _Const0035 = { _StringsDefault1, 0x01BC };
static const XStringRes _Const0036 = { _StringsDefault1, 0x01D2 };
static const XStringRes _Const0037 = { _StringsDefault1, 0x01F0 };
static const XStringRes _Const0038 = { _StringsDefault1, 0x01FD };
static const XStringRes _Const0039 = { _StringsDefault2, 0x0002 };
static const XStringRes _Const003A = { _StringsDefault2, 0x000B };
static const XStringRes _Const003B = { _StringsDefault2, 0x0014 };
static const XStringRes _Const003C = { _StringsDefault2, 0x002B };
static const XStringRes _Const003D = { _StringsDefault2, 0x0033 };
static const XStringRes _Const003E = { _StringsDefault2, 0x0039 };
static const XStringRes _Const003F = { _StringsDefault2, 0x0047 };
static const XStringRes _Const0040 = { _StringsDefault2, 0x0055 };
static const XStringRes _Const0041 = { _StringsDefault2, 0x0063 };
static const XStringRes _Const0042 = { _StringsDefault2, 0x006E };
static const XStringRes _Const0043 = { _StringsDefault2, 0x007C };
static const XStringRes _Const0044 = { _StringsDefault2, 0x0085 };
static const XStringRes _Const0045 = { _StringsDefault2, 0x008E };
static const XStringRes _Const0046 = { _StringsDefault2, 0x009A };
static const XStringRes _Const0047 = { _StringsDefault2, 0x00A9 };
static const XStringRes _Const0048 = { _StringsDefault2, 0x00B4 };
static const XStringRes _Const0049 = { _StringsDefault2, 0x00C7 };
static const XStringRes _Const004A = { _StringsDefault2, 0x00D9 };
static const XStringRes _Const004B = { _StringsDefault2, 0x00EB };
static const XStringRes _Const004C = { _StringsDefault2, 0x00F5 };
static const XStringRes _Const004D = { _StringsDefault2, 0x0106 };
static const XStringRes _Const004E = { _StringsDefault2, 0x0113 };
static const XStringRes _Const004F = { _StringsDefault2, 0x0126 };
static const XStringRes _Const0050 = { _StringsDefault2, 0x0138 };
static const XStringRes _Const0051 = { _StringsDefault2, 0x0144 };
static const XStringRes _Const0052 = { _StringsDefault2, 0x0150 };
static const XStringRes _Const0053 = { _StringsDefault2, 0x0159 };
static const XStringRes _Const0054 = { _StringsDefault2, 0x0174 };
static const XStringRes _Const0055 = { _StringsDefault2, 0x018F };
static const XStringRes _Const0056 = { _StringsDefault2, 0x01A9 };
static const XStringRes _Const0057 = { _StringsDefault2, 0x01C4 };
static const XStringRes _Const0058 = { _StringsDefault2, 0x01DE };
static const XRect _Const0059 = {{ 10, 50 }, { 470, 236 }};
static const XStringRes _Const005A = { _StringsDefault2, 0x01F9 };
static const XStringRes _Const005B = { _StringsDefault3, 0x0002 };
static const XStringRes _Const005C = { _StringsDefault3, 0x0019 };
static const XStringRes _Const005D = { _StringsDefault3, 0x002A };
static const XStringRes _Const005E = { _StringsDefault3, 0x003F };
static const XStringRes _Const005F = { _StringsDefault3, 0x004E };

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
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DevelopmentDEV_Main );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DevelopmentDEV_Main );

  /* ... and initialize objects, variables, properties, etc. */
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 15 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0000 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0001 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0002 ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const0003 ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const0004 ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const0005 ));
  _this->ItemTitleArray[ 6 ] = EwShareString( EwLoadString( &_Const0006 ));
  _this->ItemTitleArray[ 7 ] = EwShareString( EwLoadString( &_Const0007 ));
  _this->ItemTitleArray[ 8 ] = EwShareString( EwLoadString( &_Const0008 ));
  _this->ItemTitleArray[ 9 ] = EwShareString( EwLoadString( &_Const0009 ));
  _this->ItemTitleArray[ 10 ] = EwShareString( EwLoadString( &_Const000A ));
  _this->ItemTitleArray[ 11 ] = EwShareString( EwLoadString( &_Const000B ));
  _this->ItemTitleArray[ 12 ] = EwShareString( EwLoadString( &_Const000C ));
  _this->ItemTitleArray[ 13 ] = EwShareString( EwLoadString( &_Const000D ));
  _this->ItemTitleArray[ 14 ] = EwShareString( EwLoadString( &_Const000E ));
}

/* Re-Initializer for the class 'Development::DEV_Main' */
void DevelopmentDEV_Main__ReInit( DevelopmentDEV_Main _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Development::DEV_Main' */
void DevelopmentDEV_Main__Done( DevelopmentDEV_Main _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* 'C' function for method : 'Development::DEV_Main.LoadItemClass()' */
XClass DevelopmentDEV_Main_LoadItemClass( DevelopmentDEV_Main _this, XInt32 aItemNo )
{
  XClass ItemClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  switch ( aItemNo )
  {
    case 0 :
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

  if ( aItemNo < 15 )
    Title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 15 )];

  return Title;
}

/* 'C' function for method : 'Development::DEV_Main.OnItemActivate()' */
void DevelopmentDEV_Main_OnItemActivate( DevelopmentDEV_Main _this, XInt32 aItemNo, 
  MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  switch ( aItemNo )
  {
    case 0 :
      if ( EnumOperationModeFACTORY == DeviceInterfaceSystemDeviceClass_OnGetOperationMode( 
          EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )))
        DeviceInterfaceSystemDeviceClass_OnSetOperationMode( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
        DeviceInterfaceSystemDeviceClass ), EnumOperationModeNORMAL );
      else
        DeviceInterfaceSystemDeviceClass_OnSetOperationMode( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
        DeviceInterfaceSystemDeviceClass ), EnumOperationModeFACTORY );
    break;

    case 1 :
      EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->IsHopperTestMode 
      = (XBool)!EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->IsHopperTestMode;
    break;

    case 2 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( FactoryMain, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 3 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_RealTimeClock, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 4 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_Bluetooth, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 5 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_TFTBrightness, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 6 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_VehicleSupportedFunction, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 7 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_MotoCon, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 8 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_FontMenu, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 9 :
    {
      InspectionTFT_Main InspectionDialog = EwNewObject( InspectionTFT_Main, 0 );
      InspectionDialog->Super2.PassUpKey = 0;
      InspectionDialog->Super2.PassDownKey = 0;
      InspectionDialog->Super2.PassHomeKey = 0;
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)InspectionDialog ), 
      0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
    break;

    case 10 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_EEPROMTest, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 11 :
    {
      XInt32 i;

      for ( i = 0; i < 3; i++ )
        DeviceInterfaceVehicleDeviceClass_NotifyDataReceived( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeYDT_DETECTED );
    }
    break;

    case 12 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( NavigationNAV03_TBTListView, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 13 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( NavigationNAV05_TBTView, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 14 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( WeatherWEA01_Main, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    default :; 
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
    case 0 :
      IsChecked = (XBool)( EnumOperationModeNORMAL != DeviceInterfaceSystemDeviceClass_OnGetOperationMode( 
      EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
    break;

    case 1 :
      IsChecked = EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->IsHopperTestMode;
    break;

    default :; 
  }

  return IsChecked;
}

/* Variants derived from the class : 'Development::DEV_Main' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_Main )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_Main )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_Main' */
EW_DEFINE_CLASS( DevelopmentDEV_Main, MenuBaseMenuView, ItemTitleArray, ItemTitleArray, 
                 ItemTitleArray, ItemTitleArray, ItemTitleArray, _.VMT, "Development::DEV_Main" )
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
  CoreGroup_GetViewAtIndex,
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
  DevelopmentDEV_Main_LoadItemClass,
  DevelopmentDEV_Main_LoadItemTitle,
  DevelopmentDEV_Main_OnItemActivate,
  DevelopmentDEV_Main_LoadItemChecked,
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
  MenuBaseMenuView_LoadPoiListItemValue,
  MenuBaseMenuView_LoadPoiListItemUnit,
EW_END_OF_CLASS( DevelopmentDEV_Main )

/* Initializer for the class 'Development::DEV_RealTimeClock' */
void DevelopmentDEV_RealTimeClock__Init( DevelopmentDEV_RealTimeClock _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DevelopmentDEV_RealTimeClock );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->TimeText, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->UpdateLocalTimeTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DevelopmentDEV_RealTimeClock );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const000F );
  CoreRectView__OnSetBounds( &_this->TimeText, _Const0010 );
  ViewsText_OnSetAlignment( &_this->TimeText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TimeText, 0 );
  CoreTimer_OnSetPeriod( &_this->UpdateLocalTimeTimer, 500 );
  CoreTimer_OnSetEnabled( &_this->UpdateLocalTimeTimer, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeText ), 0 );
  ViewsText_OnSetFont( &_this->TimeText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->UpdateLocalTimeTimer.OnTrigger = EwNewSlot( _this, DevelopmentDEV_RealTimeClock_OnUpdateLocalTimeSlot );
}

/* Re-Initializer for the class 'Development::DEV_RealTimeClock' */
void DevelopmentDEV_RealTimeClock__ReInit( DevelopmentDEV_RealTimeClock _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->TimeText );
  CoreTimer__ReInit( &_this->UpdateLocalTimeTimer );
}

/* Finalizer method for the class 'Development::DEV_RealTimeClock' */
void DevelopmentDEV_RealTimeClock__Done( DevelopmentDEV_RealTimeClock _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->TimeText );
  CoreTimer__Done( &_this->UpdateLocalTimeTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* 'C' function for method : 'Development::DEV_RealTimeClock.OnShortHomeKeyActivated()' */
void DevelopmentDEV_RealTimeClock_OnShortHomeKeyActivated( DevelopmentDEV_RealTimeClock _this )
{
  CoreGroup_DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
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
  &_Const0011 )), EwNewStringInt( CurrentTime->Month, 2, 10 )), EwLoadString( &_Const0011 )), 
  EwNewStringInt( CurrentTime->Day, 2, 10 )), EwLoadString( &_Const0012 )), EwNewStringInt( 
  CurrentTime->Hour, 2, 10 )), EwLoadString( &_Const0013 )), EwNewStringInt( CurrentTime->Minute, 
  2, 10 )), EwLoadString( &_Const0013 )), EwNewStringInt( CurrentTime->Second, 2, 
  10 )));
}

/* Variants derived from the class : 'Development::DEV_RealTimeClock' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_RealTimeClock )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_RealTimeClock )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_RealTimeClock' */
EW_DEFINE_CLASS( DevelopmentDEV_RealTimeClock, ComponentsBaseMainBG, TimeText, TimeText, 
                 TimeText, TimeText, _.VMT, _.VMT, "Development::DEV_RealTimeClock" )
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
  CoreGroup_GetViewAtIndex,
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
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( DevelopmentDEV_RealTimeClock )

/* Initializer for the class 'Development::DEV_Bluetooth' */
void DevelopmentDEV_Bluetooth__Init( DevelopmentDEV_Bluetooth _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DevelopmentDEV_Bluetooth );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->BtSwVersionTitle, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->BtSwVersionText, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DevelopmentDEV_Bluetooth );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const000F );
  CoreRectView__OnSetBounds( &_this->BtSwVersionTitle, _Const0014 );
  ViewsText_OnSetString( &_this->BtSwVersionTitle, EwLoadString( &_Const0015 ));
  CoreRectView__OnSetBounds( &_this->BtSwVersionText, _Const0016 );
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
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->BtSwVersionTitle );
  ViewsText__ReInit( &_this->BtSwVersionText );
}

/* Finalizer method for the class 'Development::DEV_Bluetooth' */
void DevelopmentDEV_Bluetooth__Done( DevelopmentDEV_Bluetooth _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->BtSwVersionTitle );
  ViewsText__Done( &_this->BtSwVersionText );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* 'C' function for method : 'Development::DEV_Bluetooth.OnShortHomeKeyActivated()' */
void DevelopmentDEV_Bluetooth_OnShortHomeKeyActivated( DevelopmentDEV_Bluetooth _this )
{
  CoreGroup_DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* Variants derived from the class : 'Development::DEV_Bluetooth' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_Bluetooth )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_Bluetooth )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_Bluetooth' */
EW_DEFINE_CLASS( DevelopmentDEV_Bluetooth, ComponentsBaseMainBG, BtSwVersionTitle, 
                 BtSwVersionTitle, BtSwVersionTitle, BtSwVersionTitle, _.VMT, _.VMT, 
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateLayout,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( DevelopmentDEV_Bluetooth )

/* Initializer for the class 'Development::DEV_TFTBrightness' */
void DevelopmentDEV_TFTBrightness__Init( DevelopmentDEV_TFTBrightness _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DevelopmentDEV_TFTBrightness );

  /* ... then construct all embedded objects */
  ViewsWallpaper__Init( &_this->ChessboardImage, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->LevelText, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->HideLevelTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DevelopmentDEV_TFTBrightness );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const000F );
  CoreRectView__OnSetBounds( &_this->ChessboardImage, _Const0017 );
  CoreRectView__OnSetBounds( &_this->LevelText, _Const0018 );
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
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsWallpaper__ReInit( &_this->ChessboardImage );
  ViewsText__ReInit( &_this->LevelText );
  CoreTimer__ReInit( &_this->HideLevelTimer );
}

/* Finalizer method for the class 'Development::DEV_TFTBrightness' */
void DevelopmentDEV_TFTBrightness__Done( DevelopmentDEV_TFTBrightness _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsWallpaper__Done( &_this->ChessboardImage );
  ViewsText__Done( &_this->LevelText );
  CoreTimer__Done( &_this->HideLevelTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
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
  EwTrace( "%s%t", EwLoadString( &_Const0019 ), aState );
  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );
  EwTrace( "%s%*", EwLoadString( &_Const001A ), App );

  if ( App != 0 )
  {
    if ((( aState & CoreViewStateDialog ) == CoreViewStateDialog ))
      ApplicationApplication_OnSetStatusBarVisible( App, 0 );
    else
      ApplicationApplication_OnSetStatusBarVisible( App, 1 );
  }
}

/* 'C' function for method : 'Development::DEV_TFTBrightness.OnShortDownKeyActivated()' */
void DevelopmentDEV_TFTBrightness_OnShortDownKeyActivated( DevelopmentDEV_TFTBrightness _this )
{
  XInt32 NextBrightnessLevel = _this->BrightnessLevel - 1;

  if ( 0 <= NextBrightnessLevel )
    DevelopmentDEV_TFTBrightness_OnSetBrightnessLevel( _this, NextBrightnessLevel );
  else
    DevelopmentDEV_TFTBrightness_ShowLevelText( _this );
}

/* 'C' function for method : 'Development::DEV_TFTBrightness.OnShortUpKeyActivated()' */
void DevelopmentDEV_TFTBrightness_OnShortUpKeyActivated( DevelopmentDEV_TFTBrightness _this )
{
  XInt32 NextBrightnessLevel = _this->BrightnessLevel + 1;

  if ( 11 > NextBrightnessLevel )
    DevelopmentDEV_TFTBrightness_OnSetBrightnessLevel( _this, NextBrightnessLevel );
  else
    DevelopmentDEV_TFTBrightness_ShowLevelText( _this );
}

/* 'C' function for method : 'Development::DEV_TFTBrightness.OnShortHomeKeyActivated()' */
void DevelopmentDEV_TFTBrightness_OnShortHomeKeyActivated( DevelopmentDEV_TFTBrightness _this )
{
  CoreGroup_DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
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
      EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->BrightnessLevel 
      = value;

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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateLayout,
  DevelopmentDEV_TFTBrightness_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( DevelopmentDEV_TFTBrightness )

/* Initializer for the class 'Development::DEV_MotoCon' */
void DevelopmentDEV_MotoCon__Init( DevelopmentDEV_MotoCon _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DevelopmentDEV_MotoCon );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DevelopmentDEV_MotoCon );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const000F );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 28 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const001B ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const001C ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const001D ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const001E ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const001F ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const0020 ));
  _this->ItemTitleArray[ 6 ] = EwShareString( EwLoadString( &_Const0021 ));
  _this->ItemTitleArray[ 7 ] = EwShareString( EwLoadString( &_Const0022 ));
  _this->ItemTitleArray[ 8 ] = EwShareString( EwLoadString( &_Const0023 ));
  _this->ItemTitleArray[ 9 ] = EwShareString( EwLoadString( &_Const0024 ));
  _this->ItemTitleArray[ 10 ] = EwShareString( EwLoadString( &_Const0025 ));
  _this->ItemTitleArray[ 11 ] = EwShareString( EwLoadString( &_Const0026 ));
  _this->ItemTitleArray[ 12 ] = EwShareString( EwLoadString( &_Const0027 ));
  _this->ItemTitleArray[ 13 ] = EwShareString( EwLoadString( &_Const0028 ));
  _this->ItemTitleArray[ 14 ] = EwShareString( EwLoadString( &_Const0029 ));
  _this->ItemTitleArray[ 15 ] = EwShareString( EwLoadString( &_Const002A ));
  _this->ItemTitleArray[ 16 ] = EwShareString( EwLoadString( &_Const002B ));
  _this->ItemTitleArray[ 17 ] = EwShareString( EwLoadString( &_Const002C ));
  _this->ItemTitleArray[ 18 ] = EwShareString( EwLoadString( &_Const002D ));
  _this->ItemTitleArray[ 19 ] = EwShareString( EwLoadString( &_Const002E ));
  _this->ItemTitleArray[ 20 ] = EwShareString( EwLoadString( &_Const002F ));
  _this->ItemTitleArray[ 21 ] = EwShareString( EwLoadString( &_Const0030 ));
  _this->ItemTitleArray[ 22 ] = EwShareString( EwLoadString( &_Const0031 ));
  _this->ItemTitleArray[ 23 ] = EwShareString( EwLoadString( &_Const0032 ));
  _this->ItemTitleArray[ 24 ] = EwShareString( EwLoadString( &_Const0033 ));
  _this->ItemTitleArray[ 25 ] = EwShareString( EwLoadString( &_Const0034 ));
  _this->ItemTitleArray[ 26 ] = EwShareString( EwLoadString( &_Const0035 ));
  _this->ItemTitleArray[ 27 ] = EwShareString( EwLoadString( &_Const0036 ));
}

/* Re-Initializer for the class 'Development::DEV_MotoCon' */
void DevelopmentDEV_MotoCon__ReInit( DevelopmentDEV_MotoCon _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Development::DEV_MotoCon' */
void DevelopmentDEV_MotoCon__Done( DevelopmentDEV_MotoCon _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* 'C' function for method : 'Development::DEV_MotoCon.OnShortHomeKeyActivated()' */
void DevelopmentDEV_MotoCon_OnShortHomeKeyActivated( DevelopmentDEV_MotoCon _this )
{
  CoreGroup_DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Development::DEV_MotoCon.LoadItemClass()' */
XClass DevelopmentDEV_MotoCon_LoadItemClass( DevelopmentDEV_MotoCon _this, XInt32 
  aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemBase );
}

/* 'C' function for method : 'Development::DEV_MotoCon.LoadItemTitle()' */
XString DevelopmentDEV_MotoCon_LoadItemTitle( DevelopmentDEV_MotoCon _this, XInt32 
  aItemNo )
{
  XString Title = 0;

  if ( aItemNo < 28 )
    Title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 28 )];

  return Title;
}

/* 'C' function for method : 'Development::DEV_MotoCon.OnItemActivate()' */
void DevelopmentDEV_MotoCon_OnItemActivate( DevelopmentDEV_MotoCon _this, XInt32 
  aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aMenuItem );

  TEST_motocon_tx( aItemNo );
}

/* Variants derived from the class : 'Development::DEV_MotoCon' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_MotoCon )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_MotoCon )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_MotoCon' */
EW_DEFINE_CLASS( DevelopmentDEV_MotoCon, MenuBaseMenuView, ItemTitleArray, ItemTitleArray, 
                 ItemTitleArray, ItemTitleArray, ItemTitleArray, _.VMT, "Development::DEV_MotoCon" )
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
  CoreGroup_GetViewAtIndex,
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
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  MenuBaseMenuView_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  DevelopmentDEV_MotoCon_LoadItemClass,
  DevelopmentDEV_MotoCon_LoadItemTitle,
  DevelopmentDEV_MotoCon_OnItemActivate,
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
  MenuBaseMenuView_LoadPoiListItemValue,
  MenuBaseMenuView_LoadPoiListItemUnit,
EW_END_OF_CLASS( DevelopmentDEV_MotoCon )

/* Initializer for the class 'Development::DEV_VehicleSupportedFunction' */
void DevelopmentDEV_VehicleSupportedFunction__Init( DevelopmentDEV_VehicleSupportedFunction _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DevelopmentDEV_VehicleSupportedFunction );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DevelopmentDEV_VehicleSupportedFunction );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const000F );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 28 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  MenuVerticalMenu_OnSetScrollbarVisible( &_this->Super1.Menu, 0 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0037 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0038 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0039 ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const003A ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const003B ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const003C ));
  _this->ItemTitleArray[ 6 ] = EwShareString( EwLoadString( &_Const003D ));
  _this->ItemTitleArray[ 7 ] = EwShareString( EwLoadString( &_Const003E ));
  _this->ItemTitleArray[ 8 ] = EwShareString( EwLoadString( &_Const003F ));
  _this->ItemTitleArray[ 9 ] = EwShareString( EwLoadString( &_Const0040 ));
  _this->ItemTitleArray[ 10 ] = EwShareString( EwLoadString( &_Const0041 ));
  _this->ItemTitleArray[ 11 ] = EwShareString( EwLoadString( &_Const0042 ));
  _this->ItemTitleArray[ 12 ] = EwShareString( EwLoadString( &_Const0043 ));
  _this->ItemTitleArray[ 13 ] = EwShareString( EwLoadString( &_Const0044 ));
  _this->ItemTitleArray[ 14 ] = EwShareString( EwLoadString( &_Const0045 ));
  _this->ItemTitleArray[ 15 ] = EwShareString( EwLoadString( &_Const0046 ));
  _this->ItemTitleArray[ 16 ] = EwShareString( EwLoadString( &_Const0047 ));
  _this->ItemTitleArray[ 17 ] = EwShareString( EwLoadString( &_Const0048 ));
  _this->ItemTitleArray[ 18 ] = EwShareString( EwLoadString( &_Const0049 ));
  _this->ItemTitleArray[ 19 ] = EwShareString( EwLoadString( &_Const004A ));
  _this->ItemTitleArray[ 20 ] = EwShareString( EwLoadString( &_Const004B ));
  _this->ItemTitleArray[ 21 ] = EwShareString( EwLoadString( &_Const004C ));
  _this->ItemTitleArray[ 22 ] = EwShareString( EwLoadString( &_Const004D ));
  _this->ItemTitleArray[ 23 ] = EwShareString( EwLoadString( &_Const004E ));
  _this->ItemTitleArray[ 24 ] = EwShareString( EwLoadString( &_Const004F ));
  _this->ItemTitleArray[ 25 ] = EwShareString( EwLoadString( &_Const0050 ));
  _this->ItemTitleArray[ 26 ] = EwShareString( EwLoadString( &_Const0051 ));
  _this->ItemTitleArray[ 27 ] = EwShareString( EwLoadString( &_Const0052 ));
}

/* Re-Initializer for the class 'Development::DEV_VehicleSupportedFunction' */
void DevelopmentDEV_VehicleSupportedFunction__ReInit( DevelopmentDEV_VehicleSupportedFunction _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Development::DEV_VehicleSupportedFunction' */
void DevelopmentDEV_VehicleSupportedFunction__Done( DevelopmentDEV_VehicleSupportedFunction _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* 'C' function for method : 'Development::DEV_VehicleSupportedFunction.OnShortHomeKeyActivated()' */
void DevelopmentDEV_VehicleSupportedFunction_OnShortHomeKeyActivated( DevelopmentDEV_VehicleSupportedFunction _this )
{
  CoreGroup_DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Development::DEV_VehicleSupportedFunction.LoadItemClass()' */
XClass DevelopmentDEV_VehicleSupportedFunction_LoadItemClass( DevelopmentDEV_VehicleSupportedFunction _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemCheckbox );
}

/* 'C' function for method : 'Development::DEV_VehicleSupportedFunction.LoadItemTitle()' */
XString DevelopmentDEV_VehicleSupportedFunction_LoadItemTitle( DevelopmentDEV_VehicleSupportedFunction _this, 
  XInt32 aItemNo )
{
  XString Title = 0;

  if ( aItemNo < 28 )
    Title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 28 )];

  return Title;
}

/* 'C' function for method : 'Development::DEV_VehicleSupportedFunction.OnItemActivate()' */
void DevelopmentDEV_VehicleSupportedFunction_OnItemActivate( DevelopmentDEV_VehicleSupportedFunction _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  XBool IsChecked = 0;
  MenuItemCheckbox CheckBoxItem = EwCastObject( aMenuItem, MenuItemCheckbox );
  XInt32 VehicleFeatureNum;

  if ( CheckBoxItem != 0 )
    IsChecked = CheckBoxItem->Checked;

  VehicleFeatureNum = 27;
  {
    if( 0 == aItemNo )
    {
      for( int i = 0; i < VehicleFeatureNum; i++ )
      {
        VI_set_supported_function( i, IsChecked );
      }
    }
    else
    {
      // offset 1 for the toggle all option
      VI_set_supported_function( aItemNo - 1 , IsChecked );
    }
  }

  if ( 0 == aItemNo )
    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 1, _this->Super1.Menu.NoOfItems 
    - 1 );
}

/* 'C' function for method : 'Development::DEV_VehicleSupportedFunction.LoadItemChecked()' */
XBool DevelopmentDEV_VehicleSupportedFunction_LoadItemChecked( DevelopmentDEV_VehicleSupportedFunction _this, 
  XInt32 aItemNo )
{
  XBool IsChecked;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( 0 == aItemNo )
  {
    XBool IsAllEnabled = 1;
    XInt32 i;

    for ( i = 0; i < 27; i++ )
      if ( !DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
          &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), (XEnum)i ))
      {
        IsAllEnabled = 0;
        break;
      }

    IsChecked = IsAllEnabled;
  }
  else
    IsChecked = DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
    &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), (XEnum)( 
    aItemNo - 1 ));

  return IsChecked;
}

/* Variants derived from the class : 'Development::DEV_VehicleSupportedFunction' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_VehicleSupportedFunction )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_VehicleSupportedFunction )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_VehicleSupportedFunction' */
EW_DEFINE_CLASS( DevelopmentDEV_VehicleSupportedFunction, MenuBaseMenuView, ItemTitleArray, 
                 ItemTitleArray, ItemTitleArray, ItemTitleArray, ItemTitleArray, 
                 _.VMT, "Development::DEV_VehicleSupportedFunction" )
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
  CoreGroup_GetViewAtIndex,
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
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  MenuBaseMenuView_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  DevelopmentDEV_VehicleSupportedFunction_LoadItemClass,
  DevelopmentDEV_VehicleSupportedFunction_LoadItemTitle,
  DevelopmentDEV_VehicleSupportedFunction_OnItemActivate,
  DevelopmentDEV_VehicleSupportedFunction_LoadItemChecked,
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
  MenuBaseMenuView_LoadPoiListItemValue,
  MenuBaseMenuView_LoadPoiListItemUnit,
EW_END_OF_CLASS( DevelopmentDEV_VehicleSupportedFunction )

/* Initializer for the class 'Development::DEV_FontMenu' */
void DevelopmentDEV_FontMenu__Init( DevelopmentDEV_FontMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DevelopmentDEV_FontMenu );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DevelopmentDEV_FontMenu );

  /* ... and initialize objects, variables, properties, etc. */
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 6 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0053 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0054 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0055 ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const0056 ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const0057 ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const0058 ));
}

/* Re-Initializer for the class 'Development::DEV_FontMenu' */
void DevelopmentDEV_FontMenu__ReInit( DevelopmentDEV_FontMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Development::DEV_FontMenu' */
void DevelopmentDEV_FontMenu__Done( DevelopmentDEV_FontMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* 'C' function for method : 'Development::DEV_FontMenu.LoadItemClass()' */
XClass DevelopmentDEV_FontMenu_LoadItemClass( DevelopmentDEV_FontMenu _this, XInt32 
  aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemBase );
}

/* 'C' function for method : 'Development::DEV_FontMenu.LoadItemTitle()' */
XString DevelopmentDEV_FontMenu_LoadItemTitle( DevelopmentDEV_FontMenu _this, XInt32 
  aItemNo )
{
  XString Title = 0;

  if ( aItemNo < 6 )
    Title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 6 )];

  return Title;
}

/* 'C' function for method : 'Development::DEV_FontMenu.OnItemActivate()' */
void DevelopmentDEV_FontMenu_OnItemActivate( DevelopmentDEV_FontMenu _this, XInt32 
  aItemNo, MenuItemBase aMenuItem )
{
  DevelopmentDEV_FontTest Dialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

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

    default :; 
  }

  ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)Dialog ));
}

/* Variants derived from the class : 'Development::DEV_FontMenu' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_FontMenu )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_FontMenu )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_FontMenu' */
EW_DEFINE_CLASS( DevelopmentDEV_FontMenu, MenuBaseMenuView, ItemTitleArray, ItemTitleArray, 
                 ItemTitleArray, ItemTitleArray, ItemTitleArray, _.VMT, "Development::DEV_FontMenu" )
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
  CoreGroup_GetViewAtIndex,
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
  DevelopmentDEV_FontMenu_LoadItemClass,
  DevelopmentDEV_FontMenu_LoadItemTitle,
  DevelopmentDEV_FontMenu_OnItemActivate,
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
  MenuBaseMenuView_LoadPoiListItemValue,
  MenuBaseMenuView_LoadPoiListItemUnit,
EW_END_OF_CLASS( DevelopmentDEV_FontMenu )

/* Initializer for the class 'Development::DEV_FontTest' */
void DevelopmentDEV_FontTest__Init( DevelopmentDEV_FontTest _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DevelopmentDEV_FontTest );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Text, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DevelopmentDEV_FontTest );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super1.SlideOutEffectEnabled = 1;
  CoreRectView__OnSetBounds( &_this->Text, _Const0059 );
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
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Text );
}

/* Finalizer method for the class 'Development::DEV_FontTest' */
void DevelopmentDEV_FontTest__Done( DevelopmentDEV_FontTest _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Text );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* 'C' function for method : 'Development::DEV_FontTest.OnShortDownKeyActivated()' */
void DevelopmentDEV_FontTest_OnShortDownKeyActivated( DevelopmentDEV_FontTest _this )
{
  /* List of temporarily used variables */
  XPoint _tmpJ0;
  if (( EwGetInt32Abs( _this->Text.ScrollOffset.Y ) + _this->PageScrollOffset ) 
      < ( ViewsText_GetNoOfRows( &_this->Text ) * _this->RowDistance ))
    ( _tmpJ0 = _this->Text.ScrollOffset, ViewsText_OnSetScrollOffset( &_this->Text, 
    EwSetPointY( _tmpJ0, _tmpJ0.Y - _this->PageScrollOffset )));
}

/* 'C' function for method : 'Development::DEV_FontTest.OnShortUpKeyActivated()' */
void DevelopmentDEV_FontTest_OnShortUpKeyActivated( DevelopmentDEV_FontTest _this )
{
  XInt32 OffsetY = _this->Text.ScrollOffset.Y + _this->PageScrollOffset;

  if ( OffsetY <= 0 )
    ViewsText_OnSetScrollOffset( &_this->Text, EwSetPointY( _this->Text.ScrollOffset, 
    OffsetY ));
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
      _this->RowDistance = 36;

    _this->PageScrollOffset = ( EwGetRectH( _this->Text.Super1.Bounds ) / _this->RowDistance ) 
    * _this->RowDistance;
    EwTrace( "%s%i", EwLoadString( &_Const005A ), _this->PageScrollOffset );
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateLayout,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( DevelopmentDEV_FontTest )

/* Initializer for the class 'Development::DEV_EEPROMTest' */
void DevelopmentDEV_EEPROMTest__Init( DevelopmentDEV_EEPROMTest _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DevelopmentDEV_EEPROMTest );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DevelopmentDEV_EEPROMTest );

  /* ... and initialize objects, variables, properties, etc. */
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 5 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  MenuVerticalMenu_OnSetArrowScrollBarVisible( &_this->Super1.Menu, 1 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const005B ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const005C ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const005D ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const005E ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const005F ));
}

/* Re-Initializer for the class 'Development::DEV_EEPROMTest' */
void DevelopmentDEV_EEPROMTest__ReInit( DevelopmentDEV_EEPROMTest _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Development::DEV_EEPROMTest' */
void DevelopmentDEV_EEPROMTest__Done( DevelopmentDEV_EEPROMTest _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* 'C' function for method : 'Development::DEV_EEPROMTest.LoadItemClass()' */
XClass DevelopmentDEV_EEPROMTest_LoadItemClass( DevelopmentDEV_EEPROMTest _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemBase );
}

/* 'C' function for method : 'Development::DEV_EEPROMTest.LoadItemTitle()' */
XString DevelopmentDEV_EEPROMTest_LoadItemTitle( DevelopmentDEV_EEPROMTest _this, 
  XInt32 aItemNo )
{
  XString Title = 0;

  if ( aItemNo < 5 )
    Title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 5 )];

  return Title;
}

/* 'C' function for method : 'Development::DEV_EEPROMTest.OnItemActivate()' */
void DevelopmentDEV_EEPROMTest_OnItemActivate( DevelopmentDEV_EEPROMTest _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  XEnum TestItem;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aMenuItem );

  TestItem = (XEnum)aItemNo;
  TEST_eeprom( TestItem );
}

/* Variants derived from the class : 'Development::DEV_EEPROMTest' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_EEPROMTest )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_EEPROMTest )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_EEPROMTest' */
EW_DEFINE_CLASS( DevelopmentDEV_EEPROMTest, MenuBaseMenuView, ItemTitleArray, ItemTitleArray, 
                 ItemTitleArray, ItemTitleArray, ItemTitleArray, _.VMT, "Development::DEV_EEPROMTest" )
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
  CoreGroup_GetViewAtIndex,
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
  DevelopmentDEV_EEPROMTest_LoadItemClass,
  DevelopmentDEV_EEPROMTest_LoadItemTitle,
  DevelopmentDEV_EEPROMTest_OnItemActivate,
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
  MenuBaseMenuView_LoadPoiListItemValue,
  MenuBaseMenuView_LoadPoiListItemUnit,
EW_END_OF_CLASS( DevelopmentDEV_EEPROMTest )

/* Embedded Wizard */
