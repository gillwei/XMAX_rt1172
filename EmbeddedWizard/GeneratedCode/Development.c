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
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DevelopmentDEV_AncsCategory.h"
#include "_DevelopmentDEV_Bluetooth.h"
#include "_DevelopmentDEV_EEPROMTest.h"
#include "_DevelopmentDEV_FontMenu.h"
#include "_DevelopmentDEV_FontTest.h"
#include "_DevelopmentDEV_LanguageTest.h"
#include "_DevelopmentDEV_Main.h"
#include "_DevelopmentDEV_MotoCon.h"
#include "_DevelopmentDEV_RealTimeClock.h"
#include "_DevelopmentDEV_TFTBrightness.h"
#include "_DevelopmentDEV_VehicleSupportedFunction.h"
#include "_DeviceInterfaceRtcTime.h"
#include "_DeviceInterfaceSystemData.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_FactoryMain.h"
#include "_InspectionTFT_Main.h"
#include "_MenuItemBase.h"
#include "_MenuItemCheckMark.h"
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
  0x00000414, /* ratio 51.34 % */
  0xB8001F00, 0x8008C452, 0x00C60030, 0x0DE003A0, 0xF2003900, 0xA0010000, 0x64004349,
  0xC0019400, 0x22C0C271, 0x01C22E48, 0x44237230, 0x0234548A, 0x6270B398, 0x37198BC5,
  0xD0481472, 0x0C854220, 0x8894421D, 0x864B2552, 0x647C171C, 0x1B801072, 0xD4006700,
  0x26549A29, 0xA51F0900, 0xC6C844A8, 0x0034CA65, 0x38A4A8DA, 0x87554004, 0x0470D70A,
  0x10A3E110, 0xE6554AAF, 0x8D10C8BC, 0x392D9F55, 0xD298F85A, 0x678A4A60, 0xEA4D6221,
  0x8DD1E196, 0x04F6592C, 0x8640171C, 0xBA54568F, 0xEAB0AAC5, 0xD2538A46, 0xB3A91C8E,
  0x148CC6E5, 0xAA3D2E0D, 0x8B47E670, 0x7576D70E, 0xCAF07478, 0x1A3E0CC2, 0xF4D2DD24,
  0x0950B1CF, 0xBA7A3126, 0x5896C264, 0xEC2EBB59, 0x001163E0, 0x9000A1BF, 0x6EE5E4FA,
  0x128400A0, 0x088002CC, 0xE1CFBB80, 0x17408722, 0x44E859C0, 0x3E3EBEB1, 0x94C13A96,
  0xC6265DD7, 0x5BCEF1BA, 0x7C29C8C2, 0xA5B532BC, 0x01E2935B, 0x9E600790, 0x45EF473B,
  0x02700082, 0x8A646BA0, 0xD0C4210A, 0x26554946, 0x7C044711, 0x0958C2F4, 0x82114412,
  0xD630E91F, 0x0785045C, 0xB46645D9, 0x10421E64, 0x6240063D, 0x1B94B1F0, 0xF0251C6D,
  0x31914211, 0x1C4AA024, 0x49227021, 0x20F84A30, 0x947C1800, 0x31105162, 0x44001784,
  0x421146FD, 0x52A1D919, 0x869DF28E, 0x714951D5, 0x2D8D8174, 0x8ED23439, 0x2404BA3D,
  0xC7C24200, 0x22457690, 0x0492D639, 0x51D1B645, 0x9585A198, 0x18E10F18, 0x96554B91,
  0x4745E229, 0x97E4C929, 0xDE64B918, 0x57BE2B46, 0x021D4526, 0xE85A4710, 0x975EA58D,
  0xA689812A, 0xB6364562, 0x64009655, 0x1B4710E8, 0x985B49BC, 0x9B762E69, 0xB4B12E63,
  0xD2574311, 0x2A9E1496, 0x61D1C9ED, 0x6619C280, 0x49690855, 0xD9124311, 0x7B46E9C6,
  0x4727D52E, 0xA8FA8635, 0xC7E95D4B, 0xAD68AADF, 0x194B9978, 0x58D088AD, 0x00040563,
  0x00000000
};

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault1[] =
{
  0x00000408, /* ratio 44.96 % */
  0xB8002900, 0x800A6452, 0x00DC0032, 0x04000320, 0x82002180, 0x10D27000, 0x00839C80,
  0x038000E6, 0x8CC24DE0, 0xC8000118, 0x4620B030, 0xA61D0C85, 0xE306A8F9, 0x00740018,
  0xD0A8F4AC, 0x75001C61, 0xC0018400, 0x004C2646, 0xD0024479, 0x4220D250, 0xE0DB1594,
  0xA5F2B904, 0x7F3497C3, 0xD3D8F45E, 0x3B9EC721, 0x50DC8A83, 0xA4C2E4F4, 0xAD36354B,
  0xCC63F508, 0x722B3CA9, 0x235399DC, 0xBA1E9142, 0x50EAFD1E, 0x4E9F5B69, 0x78559401,
  0xAB5A63B6, 0xF1DA3116, 0x48AEF1E9, 0x7E8D04A2, 0x2EC0094C, 0xFD64BD53, 0xB54C0DF2,
  0x788442A2, 0x20E48A7E, 0x95C57177, 0x052ACB0A, 0xE44CE00D, 0xEAAB3D9D, 0x0EF1A8FC,
  0x3B228BC6, 0xF2AA4674, 0x0A9F68A3, 0x9D5D3F4D, 0x844322BA, 0x7E927B2F, 0x6276400B,
  0x60D18CAF, 0xEDD0C9DC, 0x631A874F, 0xD0898CEE, 0x378445E1, 0x2E8C2273, 0xB9F1E494,
  0xCE57078C, 0xE43AB4A9, 0x3B2B7DA8, 0xEB71C9CC, 0xC400BA6C, 0x718F25A7, 0x7FCA7A37,
  0xAD747ABF, 0xF785E450, 0x1D46398C, 0xC5A16358, 0x11517291, 0x9E77D027, 0x80D4B5D5,
  0x1CB46DD0, 0x26BC6B00, 0xD20C7FD4, 0x0C4618D6, 0x4393B4AD, 0x9F44F5F2, 0x0775EC79,
  0x75085820, 0x7E881AB8, 0x79A1B889, 0xD1F7ED0C, 0xA8B22766, 0xE16679DE, 0x624EDBD7,
  0x75DE65A4, 0x5874DC00, 0x3901908D, 0x3C007D5D, 0x11150001, 0x76640455, 0x92277118,
  0x57812677, 0x4A4C9291, 0xB81310E4, 0x6AD0F851, 0x9A463117, 0x64897E19, 0x41109101,
  0x49000554, 0x93844000, 0x95184A51, 0x79117073, 0x8A4864A0, 0xA847DA55, 0x4213D455,
  0xDAA42183, 0x1A154293, 0x00000010, 0x00000000
};

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault2[] =
{
  0x0000041E, /* ratio 50.85 % */
  0xB8001B00, 0x800A8452, 0x24CE0037, 0x4006C004, 0x00200019, 0x11486104, 0x03048000,
  0x0390020B, 0x38000D20, 0xB0C40110, 0x41A33178, 0x46411E8E, 0x23124194, 0x5A002341,
  0xF1D93800, 0x190BC923, 0x4004389B, 0x88C72767, 0x54D63642, 0x00278688, 0x00E73B37,
  0x22711A50, 0x486A0019, 0x8438C822, 0x0031C222, 0x603490D6, 0x29D54012, 0x3C641D24,
  0xC8653422, 0x08C2002B, 0x6C33E36D, 0xD50FB046, 0x64888CF6, 0x16B6DCA7, 0xEB4412C5,
  0x88D3E911, 0x7C72B160, 0xC5A910F8, 0xD49F1905, 0xA691186C, 0xAD19BCD9, 0xF41004C4,
  0x33B9C361, 0xE8B4DACB, 0xC1CC08B2, 0xE48E233B, 0xCEF3F19C, 0x32492B87, 0xCED138C8,
  0x0936C042, 0xF16A7803, 0x75005501, 0x8A468284, 0xCB6E6619, 0x6C131124, 0xEF801AFD,
  0x4E2D0D9D, 0x791B8D28, 0x9108AAC8, 0x16CDCD2A, 0xD18F4F64, 0x5D604A49, 0x87E667F3,
  0xCDDEDBD5, 0x76E2DA0D, 0xF6EF4182, 0x4F31C87C, 0x2F08C948, 0xD0F85DA7, 0x08DB82A2,
  0x4DE7CFE3, 0x29464232, 0x1217D1FB, 0xD5293511, 0x61485A93, 0x02001F55, 0x47906411,
  0x5A6445A0, 0xD7293D76, 0x19A18415, 0x21851427, 0x5111E801, 0xA1779946, 0xC869A850,
  0x31118711, 0x211993B1, 0x839AB002, 0x600865DD, 0xF459425C, 0xD92846A2, 0x6C4D58D4,
  0x5559D82D, 0x91E6E51C, 0x906E0B52, 0x19071391, 0x08581085, 0x4E92152E, 0x0005FD0F,
  0x84D8344B, 0xF50F8A99, 0x008D5EB4, 0x92104918, 0x64B4F508, 0x00014C80, 0xB1216CE5,
  0x21958384, 0x96D46961, 0xC1A4591C, 0x098A4991, 0x39479300, 0x00129559, 0x9F00012C,
  0x40094C50, 0x55551195, 0xED495F54, 0x45979164, 0x9DE4A980, 0x67F57A64, 0x4A06939F,
  0xAA7C4865, 0x0F935205, 0x9CD24911, 0x2499D65F, 0xCA49D29E, 0x0A809FA7, 0x00A166BA,
  0xA7679A1C, 0x6749768A, 0xBA46A398, 0xAAA9A527, 0x9B7CE989, 0x82E4EABE, 0x10100124,
  0x00000000
};

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault3[] =
{
  0x000003C2, /* ratio 54.47 % */
  0xB8002B00, 0x800A0452, 0x00CE0030, 0x0A600328, 0xE4003180, 0x80037800, 0x4F00454D,
  0x08D19800, 0x0042CE60, 0x00E80074, 0xC9800200, 0x5C8B030B, 0x0D200889, 0x2D258FC8,
  0xB218F422, 0x09839C24, 0x01800261, 0x23000F00, 0x88024D3F, 0x47CA5290, 0x5E486484,
  0x26D2F99C, 0x4D0C854E, 0x52B8240A, 0x0C90CBA2, 0xD8ED624B, 0x00154014, 0x0124004E,
  0x58E94540, 0x141F4222, 0x69200A3D, 0xC761AFC9, 0x56792D96, 0x43948428, 0x2844322E,
  0xB1582DF1, 0x4002CD64, 0xCA41526B, 0xE4DC0022, 0x23D2E8B4, 0x5209A11A, 0x50C89502,
  0x26C7C431, 0xF23C1323, 0x9C1B6251, 0x1CA70B8A, 0x6321121B, 0xA41742D0, 0x26F38254,
  0x3D0CC542, 0x98600546, 0x89D743A0, 0x0CC5725B, 0xB2CA42C0, 0x0EEA9112, 0x62A292E9,
  0x3EF34AD3, 0xEB9B0976, 0x1C45A9EC, 0xF37CFCBA, 0x0C9746F4, 0xAE5002DD, 0xA16CB9BB,
  0xA6725208, 0xD08D71FC, 0x328045DA, 0x0018DDCF, 0x9104F0EF, 0xDBAB6F74, 0xB9D18364,
  0xE8FF1A93, 0xC86BE5D1, 0xD1441929, 0x45098E69, 0xB1138041, 0x391D5214, 0x47DB1831,
  0x0620005F, 0xA1E9084B, 0x1D26459B, 0x387B9BF0, 0x4A5F64B9, 0x50C6E856, 0xF001C748,
  0xA9B383D9, 0x0912D045, 0x799FF792, 0x58851919, 0x04997F10, 0xE04D115F, 0x79001324,
  0x46529780, 0x90C63D21, 0x45DD2644, 0x259658D0, 0x0A7AD9F8, 0x72179495, 0x40E00218,
  0xF7B6394A, 0x5E4F769D, 0x047DE514, 0x4B914885, 0x40056510, 0x14B9088E, 0x25D166A5,
  0x177F9108, 0x6D9AA499, 0x1D98710F, 0x345A0C00, 0x7D888DDB, 0x009B6656, 0x58504868,
  0x95C1DD0C, 0x24A41349, 0x05175EDF, 0x4A0994A9, 0x7792F7A9, 0x9D000283, 0xB5727410,
  0x951E83DE, 0x8E4968C4, 0x6CE49896, 0x84C1166F, 0x9711389A, 0x18006860, 0x8A620459,
  0x6951256D, 0x5B989DF3, 0x15094248, 0x00000010, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XStringRes _Const0000 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0001 = { _StringsDefault0, 0x0011 };
static const XStringRes _Const0002 = { _StringsDefault0, 0x0024 };
static const XStringRes _Const0003 = { _StringsDefault0, 0x0033 };
static const XStringRes _Const0004 = { _StringsDefault0, 0x003E };
static const XStringRes _Const0005 = { _StringsDefault0, 0x0050 };
static const XStringRes _Const0006 = { _StringsDefault0, 0x0061 };
static const XStringRes _Const0007 = { _StringsDefault0, 0x0077 };
static const XStringRes _Const0008 = { _StringsDefault0, 0x0090 };
static const XStringRes _Const0009 = { _StringsDefault0, 0x009F };
static const XStringRes _Const000A = { _StringsDefault0, 0x00AB };
static const XStringRes _Const000B = { _StringsDefault0, 0x00BD };
static const XStringRes _Const000C = { _StringsDefault0, 0x00CB };
static const XStringRes _Const000D = { _StringsDefault0, 0x00D6 };
static const XStringRes _Const000E = { _StringsDefault0, 0x00E6 };
static const XStringRes _Const000F = { _StringsDefault0, 0x00F6 };
static const XStringRes _Const0010 = { _StringsDefault0, 0x010A };
static const XRect _Const0011 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0012 = {{ 96, 79 }, { 390, 122 }};
static const XStringRes _Const0013 = { _StringsDefault0, 0x011A };
static const XStringRes _Const0014 = { _StringsDefault0, 0x011E };
static const XStringRes _Const0015 = { _StringsDefault0, 0x0122 };
static const XRect _Const0016 = {{ 0, 40 }, { 240, 65 }};
static const XStringRes _Const0017 = { _StringsDefault0, 0x0126 };
static const XRect _Const0018 = {{ 247, 40 }, { 356, 65 }};
static const XRect _Const0019 = {{ 0, 2 }, { 480, 272 }};
static const XRect _Const001A = {{ 432, 2 }, { 482, 22 }};
static const XStringRes _Const001B = { _StringsDefault0, 0x013C };
static const XStringRes _Const001C = { _StringsDefault0, 0x0145 };
static const XStringRes _Const001D = { _StringsDefault0, 0x014D };
static const XStringRes _Const001E = { _StringsDefault0, 0x0165 };
static const XStringRes _Const001F = { _StringsDefault0, 0x017C };
static const XStringRes _Const0020 = { _StringsDefault0, 0x0193 };
static const XStringRes _Const0021 = { _StringsDefault0, 0x01AA };
static const XStringRes _Const0022 = { _StringsDefault0, 0x01BE };
static const XStringRes _Const0023 = { _StringsDefault0, 0x01D9 };
static const XStringRes _Const0024 = { _StringsDefault0, 0x01F2 };
static const XStringRes _Const0025 = { _StringsDefault1, 0x0002 };
static const XStringRes _Const0026 = { _StringsDefault1, 0x0016 };
static const XStringRes _Const0027 = { _StringsDefault1, 0x002F };
static const XStringRes _Const0028 = { _StringsDefault1, 0x0049 };
static const XStringRes _Const0029 = { _StringsDefault1, 0x0064 };
static const XStringRes _Const002A = { _StringsDefault1, 0x0082 };
static const XStringRes _Const002B = { _StringsDefault1, 0x009C };
static const XStringRes _Const002C = { _StringsDefault1, 0x00B8 };
static const XStringRes _Const002D = { _StringsDefault1, 0x00D5 };
static const XStringRes _Const002E = { _StringsDefault1, 0x00F2 };
static const XStringRes _Const002F = { _StringsDefault1, 0x010B };
static const XStringRes _Const0030 = { _StringsDefault1, 0x0126 };
static const XStringRes _Const0031 = { _StringsDefault1, 0x013D };
static const XStringRes _Const0032 = { _StringsDefault1, 0x0151 };
static const XStringRes _Const0033 = { _StringsDefault1, 0x0168 };
static const XStringRes _Const0034 = { _StringsDefault1, 0x0181 };
static const XStringRes _Const0035 = { _StringsDefault1, 0x019D };
static const XStringRes _Const0036 = { _StringsDefault1, 0x01B7 };
static const XStringRes _Const0037 = { _StringsDefault1, 0x01D0 };
static const XStringRes _Const0038 = { _StringsDefault1, 0x01E6 };
static const XStringRes _Const0039 = { _StringsDefault2, 0x0002 };
static const XStringRes _Const003A = { _StringsDefault2, 0x000F };
static const XStringRes _Const003B = { _StringsDefault2, 0x0018 };
static const XStringRes _Const003C = { _StringsDefault2, 0x0021 };
static const XStringRes _Const003D = { _StringsDefault2, 0x002A };
static const XStringRes _Const003E = { _StringsDefault2, 0x0041 };
static const XStringRes _Const003F = { _StringsDefault2, 0x0049 };
static const XStringRes _Const0040 = { _StringsDefault2, 0x004F };
static const XStringRes _Const0041 = { _StringsDefault2, 0x005D };
static const XStringRes _Const0042 = { _StringsDefault2, 0x006B };
static const XStringRes _Const0043 = { _StringsDefault2, 0x0079 };
static const XStringRes _Const0044 = { _StringsDefault2, 0x0084 };
static const XStringRes _Const0045 = { _StringsDefault2, 0x0092 };
static const XStringRes _Const0046 = { _StringsDefault2, 0x009B };
static const XStringRes _Const0047 = { _StringsDefault2, 0x00A4 };
static const XStringRes _Const0048 = { _StringsDefault2, 0x00B0 };
static const XStringRes _Const0049 = { _StringsDefault2, 0x00BF };
static const XStringRes _Const004A = { _StringsDefault2, 0x00CA };
static const XStringRes _Const004B = { _StringsDefault2, 0x00DD };
static const XStringRes _Const004C = { _StringsDefault2, 0x00EF };
static const XStringRes _Const004D = { _StringsDefault2, 0x0101 };
static const XStringRes _Const004E = { _StringsDefault2, 0x010B };
static const XStringRes _Const004F = { _StringsDefault2, 0x011C };
static const XStringRes _Const0050 = { _StringsDefault2, 0x0129 };
static const XStringRes _Const0051 = { _StringsDefault2, 0x013C };
static const XStringRes _Const0052 = { _StringsDefault2, 0x014E };
static const XStringRes _Const0053 = { _StringsDefault2, 0x015A };
static const XStringRes _Const0054 = { _StringsDefault2, 0x0166 };
static const XStringRes _Const0055 = { _StringsDefault2, 0x016F };
static const XStringRes _Const0056 = { _StringsDefault2, 0x018A };
static const XStringRes _Const0057 = { _StringsDefault2, 0x01A5 };
static const XStringRes _Const0058 = { _StringsDefault2, 0x01BF };
static const XStringRes _Const0059 = { _StringsDefault2, 0x01DA };
static const XStringRes _Const005A = { _StringsDefault2, 0x01F4 };
static const XRect _Const005B = {{ 10, 50 }, { 470, 236 }};
static const XStringRes _Const005C = { _StringsDefault3, 0x0002 };
static const XStringRes _Const005D = { _StringsDefault3, 0x0017 };
static const XStringRes _Const005E = { _StringsDefault3, 0x002E };
static const XStringRes _Const005F = { _StringsDefault3, 0x003F };
static const XStringRes _Const0060 = { _StringsDefault3, 0x0054 };
static const XStringRes _Const0061 = { _StringsDefault3, 0x0063 };
static const XStringRes _Const0062 = { _StringsDefault3, 0x0073 };
static const XStringRes _Const0063 = { _StringsDefault3, 0x007D };
static const XStringRes _Const0064 = { _StringsDefault3, 0x0086 };
static const XStringRes _Const0065 = { _StringsDefault3, 0x008F };
static const XStringRes _Const0066 = { _StringsDefault3, 0x0099 };
static const XStringRes _Const0067 = { _StringsDefault3, 0x00A4 };
static const XStringRes _Const0068 = { _StringsDefault3, 0x00AE };
static const XStringRes _Const0069 = { _StringsDefault3, 0x00C4 };
static const XStringRes _Const006A = { _StringsDefault3, 0x00D9 };
static const XStringRes _Const006B = { _StringsDefault3, 0x00E1 };
static const XStringRes _Const006C = { _StringsDefault3, 0x00EB };
static const XStringRes _Const006D = { _StringsDefault3, 0x00F3 };
static const XStringRes _Const006E = { _StringsDefault3, 0x0100 };
static const XStringRes _Const006F = { _StringsDefault3, 0x0109 };
static const XStringRes _Const0070 = { _StringsDefault3, 0x011D };
static const XStringRes _Const0071 = { _StringsDefault3, 0x0124 };
static const XStringRes _Const0072 = { _StringsDefault3, 0x0131 };
static const XStringRes _Const0073 = { _StringsDefault3, 0x0140 };
static const XStringRes _Const0074 = { _StringsDefault3, 0x0148 };
static const XStringRes _Const0075 = { _StringsDefault3, 0x0150 };
static const XStringRes _Const0076 = { _StringsDefault3, 0x0160 };
static const XStringRes _Const0077 = { _StringsDefault3, 0x016E };
static const XStringRes _Const0078 = { _StringsDefault3, 0x017B };
static const XStringRes _Const0079 = { _StringsDefault3, 0x0184 };
static const XStringRes _Const007A = { _StringsDefault3, 0x018F };
static const XStringRes _Const007B = { _StringsDefault3, 0x0197 };
static const XStringRes _Const007C = { _StringsDefault3, 0x019E };
static const XStringRes _Const007D = { _StringsDefault3, 0x01B1 };
static const XStringRes _Const007E = { _StringsDefault3, 0x01C6 };
static const XStringRes _Const007F = { _StringsDefault3, 0x01D1 };

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
#include "ew_priv.h"
#include "BC_ancs_pub.h"

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
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 17 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  MenuVerticalMenu_OnSetArrowScrollBarVisible( &_this->Super1.Menu, 1 );
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
  _this->ItemTitleArray[ 15 ] = EwShareString( EwLoadString( &_Const000F ));
  _this->ItemTitleArray[ 16 ] = EwShareString( EwLoadString( &_Const0010 ));
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

  if ( aItemNo < 17 )
    Title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 17 )];

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
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_LanguageTest, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 4 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_RealTimeClock, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 5 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_Bluetooth, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 6 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_TFTBrightness, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 7 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_VehicleSupportedFunction, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 8 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_MotoCon, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 9 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_FontMenu, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 10 :
    {
      InspectionTFT_Main InspectionDialog = EwNewObject( InspectionTFT_Main, 0 );
      InspectionDialog->Super2.PassUpKey = 0;
      InspectionDialog->Super2.PassDownKey = 0;
      InspectionDialog->Super2.PassHomeKey = 0;
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)InspectionDialog ), 
      0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
    break;

    case 11 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_EEPROMTest, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 12 :
    {
      XInt32 i;

      for ( i = 0; i < 3; i++ )
        DeviceInterfaceVehicleDeviceClass_NotifyDataReceived( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeYDT_DETECTED );
    }
    break;

    case 13 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( NavigationNAV03_TBTListView, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 14 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( NavigationNAV05_TBTView, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 15 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( WeatherWEA01_Main, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 16 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_AncsCategory, 
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
  MenuBaseMenuView_LoadItemIcon1Visible,
  MenuBaseMenuView_LoadItemIcon2Visible,
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
  CoreRectView__OnSetBounds( _this, _Const0011 );
  CoreRectView__OnSetBounds( &_this->TimeText, _Const0012 );
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
  &_Const0013 )), EwNewStringInt( CurrentTime->Month, 2, 10 )), EwLoadString( &_Const0013 )), 
  EwNewStringInt( CurrentTime->Day, 2, 10 )), EwLoadString( &_Const0014 )), EwNewStringInt( 
  CurrentTime->Hour, 2, 10 )), EwLoadString( &_Const0015 )), EwNewStringInt( CurrentTime->Minute, 
  2, 10 )), EwLoadString( &_Const0015 )), EwNewStringInt( CurrentTime->Second, 2, 
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
  CoreRectView__OnSetBounds( _this, _Const0011 );
  CoreRectView__OnSetBounds( &_this->BtSwVersionTitle, _Const0016 );
  ViewsText_OnSetString( &_this->BtSwVersionTitle, EwLoadString( &_Const0017 ));
  CoreRectView__OnSetBounds( &_this->BtSwVersionText, _Const0018 );
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
  CoreRectView__OnSetBounds( _this, _Const0011 );
  CoreRectView__OnSetBounds( &_this->ChessboardImage, _Const0019 );
  CoreRectView__OnSetBounds( &_this->LevelText, _Const001A );
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
  EwTrace( "%s%t", EwLoadString( &_Const001B ), aState );
  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );
  EwTrace( "%s%*", EwLoadString( &_Const001C ), App );

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
  CoreRectView__OnSetBounds( _this, _Const0011 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 28 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const001D ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const001E ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const001F ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const0020 ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const0021 ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const0022 ));
  _this->ItemTitleArray[ 6 ] = EwShareString( EwLoadString( &_Const0023 ));
  _this->ItemTitleArray[ 7 ] = EwShareString( EwLoadString( &_Const0024 ));
  _this->ItemTitleArray[ 8 ] = EwShareString( EwLoadString( &_Const0025 ));
  _this->ItemTitleArray[ 9 ] = EwShareString( EwLoadString( &_Const0026 ));
  _this->ItemTitleArray[ 10 ] = EwShareString( EwLoadString( &_Const0027 ));
  _this->ItemTitleArray[ 11 ] = EwShareString( EwLoadString( &_Const0028 ));
  _this->ItemTitleArray[ 12 ] = EwShareString( EwLoadString( &_Const0029 ));
  _this->ItemTitleArray[ 13 ] = EwShareString( EwLoadString( &_Const002A ));
  _this->ItemTitleArray[ 14 ] = EwShareString( EwLoadString( &_Const002B ));
  _this->ItemTitleArray[ 15 ] = EwShareString( EwLoadString( &_Const002C ));
  _this->ItemTitleArray[ 16 ] = EwShareString( EwLoadString( &_Const002D ));
  _this->ItemTitleArray[ 17 ] = EwShareString( EwLoadString( &_Const002E ));
  _this->ItemTitleArray[ 18 ] = EwShareString( EwLoadString( &_Const002F ));
  _this->ItemTitleArray[ 19 ] = EwShareString( EwLoadString( &_Const0030 ));
  _this->ItemTitleArray[ 20 ] = EwShareString( EwLoadString( &_Const0031 ));
  _this->ItemTitleArray[ 21 ] = EwShareString( EwLoadString( &_Const0032 ));
  _this->ItemTitleArray[ 22 ] = EwShareString( EwLoadString( &_Const0033 ));
  _this->ItemTitleArray[ 23 ] = EwShareString( EwLoadString( &_Const0034 ));
  _this->ItemTitleArray[ 24 ] = EwShareString( EwLoadString( &_Const0035 ));
  _this->ItemTitleArray[ 25 ] = EwShareString( EwLoadString( &_Const0036 ));
  _this->ItemTitleArray[ 26 ] = EwShareString( EwLoadString( &_Const0037 ));
  _this->ItemTitleArray[ 27 ] = EwShareString( EwLoadString( &_Const0038 ));
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
  MenuBaseMenuView_LoadItemIcon1Visible,
  MenuBaseMenuView_LoadItemIcon2Visible,
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
  CoreRectView__OnSetBounds( _this, _Const0011 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 28 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  MenuVerticalMenu_OnSetScrollbarVisible( &_this->Super1.Menu, 0 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0039 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const003A ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const003B ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const003C ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const003D ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const003E ));
  _this->ItemTitleArray[ 6 ] = EwShareString( EwLoadString( &_Const003F ));
  _this->ItemTitleArray[ 7 ] = EwShareString( EwLoadString( &_Const0040 ));
  _this->ItemTitleArray[ 8 ] = EwShareString( EwLoadString( &_Const0041 ));
  _this->ItemTitleArray[ 9 ] = EwShareString( EwLoadString( &_Const0042 ));
  _this->ItemTitleArray[ 10 ] = EwShareString( EwLoadString( &_Const0043 ));
  _this->ItemTitleArray[ 11 ] = EwShareString( EwLoadString( &_Const0044 ));
  _this->ItemTitleArray[ 12 ] = EwShareString( EwLoadString( &_Const0045 ));
  _this->ItemTitleArray[ 13 ] = EwShareString( EwLoadString( &_Const0046 ));
  _this->ItemTitleArray[ 14 ] = EwShareString( EwLoadString( &_Const0047 ));
  _this->ItemTitleArray[ 15 ] = EwShareString( EwLoadString( &_Const0048 ));
  _this->ItemTitleArray[ 16 ] = EwShareString( EwLoadString( &_Const0049 ));
  _this->ItemTitleArray[ 17 ] = EwShareString( EwLoadString( &_Const004A ));
  _this->ItemTitleArray[ 18 ] = EwShareString( EwLoadString( &_Const004B ));
  _this->ItemTitleArray[ 19 ] = EwShareString( EwLoadString( &_Const004C ));
  _this->ItemTitleArray[ 20 ] = EwShareString( EwLoadString( &_Const004D ));
  _this->ItemTitleArray[ 21 ] = EwShareString( EwLoadString( &_Const004E ));
  _this->ItemTitleArray[ 22 ] = EwShareString( EwLoadString( &_Const004F ));
  _this->ItemTitleArray[ 23 ] = EwShareString( EwLoadString( &_Const0050 ));
  _this->ItemTitleArray[ 24 ] = EwShareString( EwLoadString( &_Const0051 ));
  _this->ItemTitleArray[ 25 ] = EwShareString( EwLoadString( &_Const0052 ));
  _this->ItemTitleArray[ 26 ] = EwShareString( EwLoadString( &_Const0053 ));
  _this->ItemTitleArray[ 27 ] = EwShareString( EwLoadString( &_Const0054 ));
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
  MenuBaseMenuView_LoadItemIcon1Visible,
  MenuBaseMenuView_LoadItemIcon2Visible,
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
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0055 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0056 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0057 ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const0058 ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const0059 ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const005A ));
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
  MenuBaseMenuView_LoadItemIcon1Visible,
  MenuBaseMenuView_LoadItemIcon2Visible,
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
  CoreRectView__OnSetBounds( &_this->Text, _Const005B );
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
    EwTrace( "%s%i", EwLoadString( &_Const005C ), _this->PageScrollOffset );
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
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const005D ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const005E ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const005F ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const0060 ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const0061 ));
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
  MenuBaseMenuView_LoadItemIcon1Visible,
  MenuBaseMenuView_LoadItemIcon2Visible,
EW_END_OF_CLASS( DevelopmentDEV_EEPROMTest )

/* Initializer for the class 'Development::DEV_LanguageTest' */
void DevelopmentDEV_LanguageTest__Init( DevelopmentDEV_LanguageTest _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DevelopmentDEV_LanguageTest );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->ReceivedSystemEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DevelopmentDEV_LanguageTest );

  /* ... and initialize objects, variables, properties, etc. */
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 18 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  MenuVerticalMenu_OnSetArrowScrollBarVisible( &_this->Super1.Menu, 1 );
  _this->ReceivedSystemEventHandler.OnEvent = EwNewSlot( _this, DevelopmentDEV_LanguageTest_OnSystemEventReceived );
  CoreSystemEventHandler_OnSetEvent( &_this->ReceivedSystemEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->SystemDataReceivedSystemEvent );

  /* Call the user defined constructor */
  DevelopmentDEV_LanguageTest_Init( _this, aArg );
}

/* Re-Initializer for the class 'Development::DEV_LanguageTest' */
void DevelopmentDEV_LanguageTest__ReInit( DevelopmentDEV_LanguageTest _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->ReceivedSystemEventHandler );
}

/* Finalizer method for the class 'Development::DEV_LanguageTest' */
void DevelopmentDEV_LanguageTest__Done( DevelopmentDEV_LanguageTest _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CoreSystemEventHandler__Done( &_this->ReceivedSystemEventHandler );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void DevelopmentDEV_LanguageTest_Init( DevelopmentDEV_LanguageTest _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  DevelopmentDEV_LanguageTest_GetCurrentLanguage( _this );
}

/* 'C' function for method : 'Development::DEV_LanguageTest.LoadItemClass()' */
XClass DevelopmentDEV_LanguageTest_LoadItemClass( DevelopmentDEV_LanguageTest _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemCheckMark );
}

/* 'C' function for method : 'Development::DEV_LanguageTest.LoadItemTitle()' */
XString DevelopmentDEV_LanguageTest_LoadItemTitle( DevelopmentDEV_LanguageTest _this, 
  XInt32 aItemNo )
{
  XString Title;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Title = 0;

  if ( 18 > aItemNo )
  {
    XEnum LanguageType = (XEnum)aItemNo;

    switch ( LanguageType )
    {
      case EnumLanguageENGLISH :
        Title = EwLoadString( &_Const0062 );
      break;

      case EnumLanguageFRENCH :
        Title = EwLoadString( &_Const0063 );
      break;

      case EnumLanguageGERMAN :
        Title = EwLoadString( &_Const0064 );
      break;

      case EnumLanguageITALIAN :
        Title = EwLoadString( &_Const0065 );
      break;

      case EnumLanguageJAPANESE :
        Title = EwLoadString( &_Const0066 );
      break;

      case EnumLanguageSPANISH :
        Title = EwLoadString( &_Const0067 );
      break;

      case EnumLanguageTRADITIONAL_CHINESE :
        Title = EwLoadString( &_Const0068 );
      break;

      case EnumLanguageSIMPLIFIED_CHINESE :
        Title = EwLoadString( &_Const0069 );
      break;

      case EnumLanguageGREEK :
        Title = EwLoadString( &_Const006A );
      break;

      case EnumLanguageFINNISH :
        Title = EwLoadString( &_Const006B );
      break;

      case EnumLanguageHINDI :
        Title = EwLoadString( &_Const006C );
      break;

      case EnumLanguageINDONESIAN :
        Title = EwLoadString( &_Const006D );
      break;

      case EnumLanguagePOLISH :
        Title = EwLoadString( &_Const006E );
      break;

      case EnumLanguagePORTUGUESE_BRAZIL :
        Title = EwLoadString( &_Const006F );
      break;

      case EnumLanguageTHAI :
        Title = EwLoadString( &_Const0070 );
      break;

      case EnumLanguageVIETNAMESE :
        Title = EwLoadString( &_Const0071 );
      break;

      case EnumLanguageKOREAN :
        Title = EwLoadString( &_Const0072 );
      break;

      case EnumLanguageMALAY :
        Title = EwLoadString( &_Const0073 );
      break;

      default :; 
    }
  }

  return Title;
}

/* 'C' function for method : 'Development::DEV_LanguageTest.OnItemActivate()' */
void DevelopmentDEV_LanguageTest_OnItemActivate( DevelopmentDEV_LanguageTest _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aMenuItem );
  EW_UNUSED_ARG( aItemNo );

  ew_system_set_language( LANGUAGE_SRC_PRIORITY_PHONE, aItemNo );
}

/* 'C' function for method : 'Development::DEV_LanguageTest.LoadItemChecked()' */
XBool DevelopmentDEV_LanguageTest_LoadItemChecked( DevelopmentDEV_LanguageTest _this, 
  XInt32 aItemNo )
{
  XBool IsChecked = 0;

  if ( 18 > aItemNo )
  {
    XEnum Language = (XEnum)aItemNo;

    if ( _this->CurrentLanguage == Language )
      IsChecked = 1;
  }

  return IsChecked;
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void DevelopmentDEV_LanguageTest_OnSystemEventReceived( DevelopmentDEV_LanguageTest _this, 
  XObject sender )
{
  DeviceInterfaceSystemData SystemData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  SystemData = EwCastObject( _this->ReceivedSystemEventHandler.Context, DeviceInterfaceSystemData );

  if ( SystemData != 0 )
    switch ( SystemData->RxEvent )
    {
      case EnumSystemRxEventLANGUAGE_CHANGED :
      {
        DevelopmentDEV_LanguageTest_GetCurrentLanguage( _this );
        MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, _this->Super1.Menu.NoOfItems 
        - 1 );
      }
      break;

      default :; 
    }
}

/* 'C' function for method : 'Development::DEV_LanguageTest.GetCurrentLanguage()' */
void DevelopmentDEV_LanguageTest_GetCurrentLanguage( DevelopmentDEV_LanguageTest _this )
{
  _this->CurrentLanguage = (XEnum)DeviceInterfaceSystemDeviceClass_GetSystemStatus( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ), 
  EnumSystemStatusLANGUAGE );
}

/* Variants derived from the class : 'Development::DEV_LanguageTest' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_LanguageTest )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_LanguageTest )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_LanguageTest' */
EW_DEFINE_CLASS( DevelopmentDEV_LanguageTest, MenuBaseMenuView, ReceivedSystemEventHandler, 
                 ReceivedSystemEventHandler, ReceivedSystemEventHandler, ReceivedSystemEventHandler, 
                 CurrentLanguage, CurrentLanguage, "Development::DEV_LanguageTest" )
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
  DevelopmentDEV_LanguageTest_LoadItemClass,
  DevelopmentDEV_LanguageTest_LoadItemTitle,
  DevelopmentDEV_LanguageTest_OnItemActivate,
  DevelopmentDEV_LanguageTest_LoadItemChecked,
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
  MenuBaseMenuView_LoadItemIcon1Visible,
  MenuBaseMenuView_LoadItemIcon2Visible,
EW_END_OF_CLASS( DevelopmentDEV_LanguageTest )

/* Initializer for the class 'Development::DEV_AncsCategory' */
void DevelopmentDEV_AncsCategory__Init( DevelopmentDEV_AncsCategory _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DevelopmentDEV_AncsCategory );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DevelopmentDEV_AncsCategory );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0011 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 13 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  MenuVerticalMenu_OnSetScrollbarVisible( &_this->Super1.Menu, 0 );
  _this->CategoryList[ 0 ] = EwShareString( EwLoadString( &_Const0039 ));
  _this->CategoryList[ 1 ] = EwShareString( EwLoadString( &_Const0074 ));
  _this->CategoryList[ 2 ] = EwShareString( EwLoadString( &_Const0075 ));
  _this->CategoryList[ 3 ] = EwShareString( EwLoadString( &_Const0076 ));
  _this->CategoryList[ 4 ] = EwShareString( EwLoadString( &_Const0077 ));
  _this->CategoryList[ 5 ] = EwShareString( EwLoadString( &_Const0078 ));
  _this->CategoryList[ 6 ] = EwShareString( EwLoadString( &_Const0079 ));
  _this->CategoryList[ 7 ] = EwShareString( EwLoadString( &_Const007A ));
  _this->CategoryList[ 8 ] = EwShareString( EwLoadString( &_Const007B ));
  _this->CategoryList[ 9 ] = EwShareString( EwLoadString( &_Const007C ));
  _this->CategoryList[ 10 ] = EwShareString( EwLoadString( &_Const007D ));
  _this->CategoryList[ 11 ] = EwShareString( EwLoadString( &_Const007E ));
  _this->CategoryList[ 12 ] = EwShareString( EwLoadString( &_Const007F ));
}

/* Re-Initializer for the class 'Development::DEV_AncsCategory' */
void DevelopmentDEV_AncsCategory__ReInit( DevelopmentDEV_AncsCategory _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Development::DEV_AncsCategory' */
void DevelopmentDEV_AncsCategory__Done( DevelopmentDEV_AncsCategory _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* 'C' function for method : 'Development::DEV_AncsCategory.OnShortHomeKeyActivated()' */
void DevelopmentDEV_AncsCategory_OnShortHomeKeyActivated( DevelopmentDEV_AncsCategory _this )
{
  CoreGroup_DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Development::DEV_AncsCategory.LoadItemClass()' */
XClass DevelopmentDEV_AncsCategory_LoadItemClass( DevelopmentDEV_AncsCategory _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemCheckbox );
}

/* 'C' function for method : 'Development::DEV_AncsCategory.LoadItemTitle()' */
XString DevelopmentDEV_AncsCategory_LoadItemTitle( DevelopmentDEV_AncsCategory _this, 
  XInt32 aItemNo )
{
  XString Title = 0;

  if ( aItemNo < 13 )
    Title = _this->CategoryList[ EwCheckIndex( aItemNo, 13 )];

  return Title;
}

/* 'C' function for method : 'Development::DEV_AncsCategory.OnItemActivate()' */
void DevelopmentDEV_AncsCategory_OnItemActivate( DevelopmentDEV_AncsCategory _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  XBool IsChecked = 0;
  MenuItemCheckbox CheckBoxItem = EwCastObject( aMenuItem, MenuItemCheckbox );
  XInt32 CategoryNum;

  if ( CheckBoxItem != 0 )
    IsChecked = CheckBoxItem->Checked;

  CategoryNum = 12;
  {
    if( 0 == aItemNo )
    {
      for( int32_t i = 0; i < CategoryNum; i++ )
      {
        BC_ancs_set_notification_category_enabled( i, IsChecked );
      }
    }
    else
    {
      // offset 1 for the toggle all option
      BC_ancs_set_notification_category_enabled( aItemNo - 1 , IsChecked );
    }
  }

  if ( 0 == aItemNo )
    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 1, _this->Super1.Menu.NoOfItems 
    - 1 );
}

/* 'C' function for method : 'Development::DEV_AncsCategory.LoadItemChecked()' */
XBool DevelopmentDEV_AncsCategory_LoadItemChecked( DevelopmentDEV_AncsCategory _this, 
  XInt32 aItemNo )
{
  XBool IsChecked;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsChecked = 0;

  if ( 0 == aItemNo )
  {
    XBool IsCategoryEnabled = 0;
    XBool IsAllEnabled = 1;
    XInt32 i;

    for ( i = 0; i < 12; i++ )
    {
      IsCategoryEnabled = BC_ancs_is_category_enabled( i );

      if ( !IsCategoryEnabled )
      {
        IsAllEnabled = 0;
        break;
      }
    }

    IsChecked = IsAllEnabled;
  }
  else
  {
    XInt32 CategoryIdx = aItemNo - 1;
    IsChecked = BC_ancs_is_category_enabled( CategoryIdx );
  }

  return IsChecked;
}

/* Variants derived from the class : 'Development::DEV_AncsCategory' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_AncsCategory )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_AncsCategory )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_AncsCategory' */
EW_DEFINE_CLASS( DevelopmentDEV_AncsCategory, MenuBaseMenuView, CategoryList, CategoryList, 
                 CategoryList, CategoryList, CategoryList, _.VMT, "Development::DEV_AncsCategory" )
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
  DevelopmentDEV_AncsCategory_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  MenuBaseMenuView_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  DevelopmentDEV_AncsCategory_LoadItemClass,
  DevelopmentDEV_AncsCategory_LoadItemTitle,
  DevelopmentDEV_AncsCategory_OnItemActivate,
  DevelopmentDEV_AncsCategory_LoadItemChecked,
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
  MenuBaseMenuView_LoadItemIcon1Visible,
  MenuBaseMenuView_LoadItemIcon2Visible,
EW_END_OF_CLASS( DevelopmentDEV_AncsCategory )

/* Embedded Wizard */
