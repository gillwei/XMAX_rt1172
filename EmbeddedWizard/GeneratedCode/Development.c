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
#include "_DevelopmentDEV_BtLogLevel.h"
#include "_DevelopmentDEV_EEPROMTest.h"
#include "_DevelopmentDEV_FontMenu.h"
#include "_DevelopmentDEV_FontTest.h"
#include "_DevelopmentDEV_LanguageTest.h"
#include "_DevelopmentDEV_Main.h"
#include "_DevelopmentDEV_MotoCon.h"
#include "_DevelopmentDEV_RealTimeClock.h"
#include "_DevelopmentDEV_TFTBrightness.h"
#include "_DevelopmentDEV_VehicleSupportedFunction.h"
#include "_DeviceInterfaceBluetoothDeviceClass.h"
#include "_DeviceInterfaceRtcTime.h"
#include "_DeviceInterfaceSystemData.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_FactoryMain.h"
#include "_InspectionTFT_Main.h"
#include "_MenuItemBase.h"
#include "_MenuItemBaseValue.h"
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
  0x0000040C, /* ratio 53.28 % */
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
  0x9630E91F, 0xC6451F02, 0xC189451E, 0x340020F7, 0x43944115, 0xD4445149, 0x54A87646,
  0xB82D4515, 0xAA0211C4, 0x5510C515, 0xD048B163, 0x5441106F, 0x12144719, 0x10421EC4,
  0x51D5851D, 0xC0747149, 0x651DB347, 0x7E2B45C6, 0x6246DCE4, 0x002415A4, 0xE1911639,
  0xE9340043, 0xC54E4B10, 0x24154456, 0x56E2E461, 0x15891C00, 0xC7995A44, 0x251C4AA3,
  0x914211F0, 0x8C5968BD, 0x9239766B, 0x50621B84, 0x32674B61, 0x44001784, 0x421146FD,
  0x1F089519, 0x47C9DA43, 0xDC1793DB, 0x7B48D6B9, 0xA012E9F6, 0x254A0800, 0x88FDA7A1,
  0x128958D4, 0x4746D914, 0x56168661, 0x2674424D, 0x04AA914F, 0xD1B94B11, 0x45A651C6,
  0xA79B4A6C, 0x20246DE6, 0x4951EF00, 0xC51B4411, 0x637A1691, 0x4AA9A7A9, 0xE924BA9D,
  0xE639B762, 0x3A47A592, 0x0158D634, 0x00000001, 0x00000000
};

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault1[] =
{
  0x00000406, /* ratio 44.66 % */
  0xB8003700, 0x800A6452, 0x00DC0032, 0x04000320, 0x01073B00, 0x069001A0, 0x6C0018C0,
  0x139C3A22, 0x8F000E91, 0x699E1515, 0xC44E4008, 0x66520038, 0xA2305818, 0x330E8642,
  0x60084986, 0x798F43A4, 0x58D1C000, 0x3A8024F2, 0x4C7A3911, 0x41A58189, 0x0E492F84,
  0x80041001, 0x11269213, 0x1118FCCA, 0x330042E6, 0x494CCE3D, 0xABCBA8C1, 0x7D36970E,
  0x002A30EA, 0xD0DF3B8E, 0xA55088E4, 0x2960A457, 0xF11354D2, 0x6A004822, 0x09443A15,
  0x8AC66674, 0xD0025338, 0xD5A696F0, 0xCACF3F36, 0x62F0E8BD, 0xD526AA5E, 0x73B87466,
  0x0294CE6A, 0x4C351E09, 0x8E503112, 0xC45B1915, 0x6463D34B, 0xCE77248C, 0xA5311CFC,
  0x1D49C287, 0x9A1C567A, 0x3DD2E3A4, 0x89EEA725, 0xB5456210, 0xD61253AC, 0x6270F5FC,
  0x931BA3D0, 0xF49A6856, 0xF1089A64, 0x01C94D50, 0xA390DC76, 0x6EC622D5, 0xD45FB473,
  0xE42A670E, 0xC9A22778, 0x5BAC1D94, 0x3B7B7EC5, 0xBF17EECD, 0xF088673F, 0x82E85FE2,
  0x6B8713D3, 0x99C22275, 0xD545B10C, 0xC5655446, 0x057C5993, 0x2B001D35, 0x4399C7ED,
  0x1406E910, 0xF7290862, 0x39BA7358, 0x984ED404, 0x845247A9, 0xD3C84DA8, 0x06E5CC6D,
  0x956A55DE, 0x174A50A7, 0x625B2878, 0x8008551E, 0xB69D177B, 0xB58F44D3, 0x0E574005,
  0x8C2336C6, 0xD115A13C, 0x27986B4C, 0xC63D8B58, 0x1555E145, 0x73A104CD, 0xA1A92D89,
  0xD835824E, 0x559D7F12, 0x0F939725, 0x8CA22941, 0x1348A50C, 0x99762E75, 0x9DB87661,
  0x6254D196, 0x822326A0, 0xE5770D82, 0x6599A383, 0x004F8CA0, 0x50530540, 0x421404F9,
  0x68260942, 0x00000040, 0x00000000
};

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault2[] =
{
  0x00000418, /* ratio 51.91 % */
  0xB8003300, 0x800A6452, 0x00DC0032, 0x04000320, 0xA8002780, 0x10D20800, 0x69001300,
  0x03580212, 0x30800860, 0xAC2CE400, 0x19A15198, 0xA8006F00, 0xE0B030B4, 0x1D0C8D41,
  0x0558F47A, 0x44001240, 0x38448A2A, 0x941C0007, 0x54227B1A, 0x41A5A1E9, 0xFA630A84,
  0xA8068004, 0x7B0E8442, 0x11A33C66, 0x578A9B24, 0x7979DA11, 0x004EE1D5, 0x68025471,
  0x4A6252D0, 0x56B354AA, 0xAAF578A4, 0x436504CA, 0x30EA5C62, 0x04B85886, 0xF8CC8A25,
  0xBB8CA1D3, 0x68008D2D, 0x5F2E5111, 0x365A17B1, 0xA5E74979, 0x0C428748, 0xB4DAA003,
  0x3D0053F1, 0xC8A43A7B, 0x04588D50, 0x4D5E3D2D, 0x58A36639, 0x1A3D7103, 0xE5A0E954,
  0x077DC911, 0xC6DB947E, 0x04D6D8B1, 0xEC6ECE8F, 0x904BC910, 0x648A118D, 0xDCCAF2DD,
  0x960D15A4, 0xEC548AFE, 0x33109682, 0x77BC2D76, 0x56827129, 0x8C880306, 0xEA6F2AF0,
  0x0DBE7F73, 0x5421172C, 0x13C77600, 0xE2BCCC14, 0x5A0C955F, 0xD54ADC52, 0xE69FC1A1,
  0x107CAA47, 0xB91D401A, 0x9DF4295F, 0xE775FF60, 0xD0007C9C, 0x5C811157, 0x79013589,
  0x9D300205, 0xD4292947, 0xFDB57FD3, 0x154658D4, 0x8201258A, 0x18563D19, 0x06DA1942,
  0x79E57F9C, 0x276452D8, 0x1E572706, 0x92976515, 0x3551B377, 0xF40A0014, 0xB38CD297,
  0x04562809, 0xE3D1492D, 0x94392F64, 0x353D4653, 0xA5429206, 0x5E5648DD, 0x10E57D73,
  0xD0014E7B, 0x420F4A98, 0x00916219, 0x77E1D950, 0x94C54E42, 0x996A2A95, 0x7D7294E2,
  0x0845D159, 0x0025749D, 0x252999F1, 0x04224200, 0xC67070D2, 0x126C5D55, 0x8DDB5465,
  0x91E11578, 0xF921FF48, 0xB41B4A92, 0x8D5004E4, 0x92D064A5, 0x18B45598, 0x45FD4A42,
  0xB1DF52C3, 0x788BA649, 0xA2D04A26, 0xC00A3529, 0xFA4941A3, 0xE000A552, 0x8C9AE980,
  0x589C2991, 0x28CA281A, 0xD85AA450, 0x004A0011, 0x00AE04B0, 0xA5800140, 0x54D47915,
  0x25092F49, 0x0101B1D6, 0x00000000
};

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault3[] =
{
  0x0000042C, /* ratio 53.93 % */
  0xB8003700, 0x8009C452, 0x1CE80037, 0x40053004, 0x006E0018, 0x043001CC, 0x4B001280,
  0x0280022C, 0x1A000640, 0x7C684000, 0x4421C708, 0xA2246500, 0xC352C004, 0x150B82C0,
  0x30F86C22, 0x178AC4E2, 0xE8E45E33, 0x8A484711, 0x4800D000, 0xC4E53273, 0x12052C94,
  0x26508834, 0x81369343, 0x13C8D4E6, 0x17914F80, 0x795D4249, 0x0A802594, 0x3C3E392F,
  0x18E1B2B3, 0xB2167200, 0x09F6B001, 0x556F3300, 0xE3A854A6, 0x2F0BCB27, 0x9A1DA0AF,
  0xB5C8A570, 0x142A270F, 0x5FAC7259, 0xE0003000, 0xB1846001, 0xA52F08D7, 0xE6487CAC,
  0x83956027, 0x40061401, 0xBCD7E916, 0x4C2A897B, 0xE6347229, 0x1800559F, 0xCA80024C,
  0xBC44D64F, 0x193C883E, 0xA9916540, 0x0D7EB757, 0x084B3620, 0x4DAE2B2F, 0x6E2D30F9,
  0xBB5800D5, 0xABDB0916, 0x4E459782, 0x744B5D92, 0x099650A2, 0x9B4E365E, 0xEBD9E232,
  0x3C13B200, 0x9B6D32B2, 0x139F2CAD, 0x21F0AD64, 0x1600F475, 0x79AACCBC, 0xE995D1AB,
  0x1CDC365F, 0xAF507AB1, 0x5AE4BC16, 0xA5F1945A, 0x45085110, 0x154FDEE4, 0x44544509,
  0x160679F7, 0x75110D41, 0xC1EF495E, 0xB74A5445, 0x5160E501, 0xC0857972, 0xB771E44B,
  0x69CE1AD2, 0xFD4457C7, 0x88DE04A9, 0xA2B12104, 0xD4B17C6D, 0x45AC4BC0, 0x5C825954,
  0x579355F1, 0x11C115E2, 0xE759EF42, 0x2D610515, 0x75429694, 0x93400670, 0x05F00211,
  0xF5EC6200, 0xAD7C1E90, 0x0201D2C5, 0x5110F7FE, 0x0564BE36, 0xF49D735F, 0xB25179D0,
  0x19411B34, 0x8FE26421, 0x5925BA28, 0xC7204174, 0x34458C12, 0x7965D261, 0x5B92F888,
  0x5295090A, 0x78E1BF5A, 0x9D0859D2, 0x2293A0F7, 0x96A0B455, 0x92F03800, 0xD575FE9E,
  0x656CA3A1, 0x6341261A, 0x59D44422, 0xE7A001A4, 0xA7869A97, 0x116742DF, 0xF24B20B5,
  0x77C00851, 0xE4D6552B, 0x14127E70, 0x42A479DD, 0x2B52E5CA, 0x4B12A1DD, 0x2324BC13,
  0xFA069971, 0x353F0993, 0x13881A26, 0x84D2C44D, 0xA4F10845, 0x37DE8B4A, 0x8AC84891,
  0x8799ACA4, 0x4B15E7E2, 0x00000101, 0x00000000
};

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault4[] =
{
  0x0000003A, /* ratio 96.55 % */
  0xB8001700, 0x80098452, 0x00C60037, 0x0E800308, 0x01073480, 0x114001B8, 0x4522C0C2,
  0x50043624, 0x8D9C8006, 0x6C4E210C, 0x43A351C3, 0x0401288A, 0x00000004, 0x00000000
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
static const XStringRes _Const0016 = { _StringsDefault0, 0x0126 };
static const XStringRes _Const0017 = { _StringsDefault0, 0x0130 };
static const XStringRes _Const0018 = { _StringsDefault0, 0x013F };
static const XStringRes _Const0019 = { _StringsDefault0, 0x0147 };
static const XStringRes _Const001A = { _StringsDefault0, 0x014F };
static const XStringRes _Const001B = { _StringsDefault0, 0x0159 };
static const XStringRes _Const001C = { _StringsDefault0, 0x0160 };
static const XStringRes _Const001D = { _StringsDefault0, 0x0168 };
static const XStringRes _Const001E = { _StringsDefault0, 0x0172 };
static const XRect _Const001F = {{ 0, 2 }, { 480, 272 }};
static const XRect _Const0020 = {{ 432, 2 }, { 482, 22 }};
static const XStringRes _Const0021 = { _StringsDefault0, 0x0184 };
static const XStringRes _Const0022 = { _StringsDefault0, 0x018D };
static const XStringRes _Const0023 = { _StringsDefault0, 0x0195 };
static const XStringRes _Const0024 = { _StringsDefault0, 0x01AD };
static const XStringRes _Const0025 = { _StringsDefault0, 0x01C4 };
static const XStringRes _Const0026 = { _StringsDefault0, 0x01DB };
static const XStringRes _Const0027 = { _StringsDefault0, 0x01F2 };
static const XStringRes _Const0028 = { _StringsDefault1, 0x0002 };
static const XStringRes _Const0029 = { _StringsDefault1, 0x001D };
static const XStringRes _Const002A = { _StringsDefault1, 0x0036 };
static const XStringRes _Const002B = { _StringsDefault1, 0x004E };
static const XStringRes _Const002C = { _StringsDefault1, 0x0062 };
static const XStringRes _Const002D = { _StringsDefault1, 0x007B };
static const XStringRes _Const002E = { _StringsDefault1, 0x0095 };
static const XStringRes _Const002F = { _StringsDefault1, 0x00B0 };
static const XStringRes _Const0030 = { _StringsDefault1, 0x00CE };
static const XStringRes _Const0031 = { _StringsDefault1, 0x00E8 };
static const XStringRes _Const0032 = { _StringsDefault1, 0x0104 };
static const XStringRes _Const0033 = { _StringsDefault1, 0x0121 };
static const XStringRes _Const0034 = { _StringsDefault1, 0x013E };
static const XStringRes _Const0035 = { _StringsDefault1, 0x0157 };
static const XStringRes _Const0036 = { _StringsDefault1, 0x0172 };
static const XStringRes _Const0037 = { _StringsDefault1, 0x0189 };
static const XStringRes _Const0038 = { _StringsDefault1, 0x019D };
static const XStringRes _Const0039 = { _StringsDefault1, 0x01B4 };
static const XStringRes _Const003A = { _StringsDefault1, 0x01CD };
static const XStringRes _Const003B = { _StringsDefault1, 0x01E9 };
static const XStringRes _Const003C = { _StringsDefault2, 0x0002 };
static const XStringRes _Const003D = { _StringsDefault2, 0x001B };
static const XStringRes _Const003E = { _StringsDefault2, 0x0031 };
static const XStringRes _Const003F = { _StringsDefault2, 0x004F };
static const XStringRes _Const0040 = { _StringsDefault2, 0x005C };
static const XStringRes _Const0041 = { _StringsDefault2, 0x0065 };
static const XStringRes _Const0042 = { _StringsDefault2, 0x006E };
static const XStringRes _Const0043 = { _StringsDefault2, 0x0077 };
static const XStringRes _Const0044 = { _StringsDefault2, 0x008E };
static const XStringRes _Const0045 = { _StringsDefault2, 0x0096 };
static const XStringRes _Const0046 = { _StringsDefault2, 0x009C };
static const XStringRes _Const0047 = { _StringsDefault2, 0x00AA };
static const XStringRes _Const0048 = { _StringsDefault2, 0x00B8 };
static const XStringRes _Const0049 = { _StringsDefault2, 0x00C6 };
static const XStringRes _Const004A = { _StringsDefault2, 0x00D1 };
static const XStringRes _Const004B = { _StringsDefault2, 0x00DF };
static const XStringRes _Const004C = { _StringsDefault2, 0x00E8 };
static const XStringRes _Const004D = { _StringsDefault2, 0x00F1 };
static const XStringRes _Const004E = { _StringsDefault2, 0x00FD };
static const XStringRes _Const004F = { _StringsDefault2, 0x010C };
static const XStringRes _Const0050 = { _StringsDefault2, 0x0117 };
static const XStringRes _Const0051 = { _StringsDefault2, 0x012A };
static const XStringRes _Const0052 = { _StringsDefault2, 0x013C };
static const XStringRes _Const0053 = { _StringsDefault2, 0x014E };
static const XStringRes _Const0054 = { _StringsDefault2, 0x0158 };
static const XStringRes _Const0055 = { _StringsDefault2, 0x0169 };
static const XStringRes _Const0056 = { _StringsDefault2, 0x0176 };
static const XStringRes _Const0057 = { _StringsDefault2, 0x0189 };
static const XStringRes _Const0058 = { _StringsDefault2, 0x019B };
static const XStringRes _Const0059 = { _StringsDefault2, 0x01A7 };
static const XStringRes _Const005A = { _StringsDefault2, 0x01B3 };
static const XStringRes _Const005B = { _StringsDefault2, 0x01BC };
static const XStringRes _Const005C = { _StringsDefault2, 0x01D7 };
static const XStringRes _Const005D = { _StringsDefault2, 0x01F2 };
static const XStringRes _Const005E = { _StringsDefault3, 0x0002 };
static const XStringRes _Const005F = { _StringsDefault3, 0x001D };
static const XStringRes _Const0060 = { _StringsDefault3, 0x0037 };
static const XRect _Const0061 = {{ 10, 50 }, { 470, 236 }};
static const XStringRes _Const0062 = { _StringsDefault3, 0x0052 };
static const XStringRes _Const0063 = { _StringsDefault3, 0x0067 };
static const XStringRes _Const0064 = { _StringsDefault3, 0x007E };
static const XStringRes _Const0065 = { _StringsDefault3, 0x008F };
static const XStringRes _Const0066 = { _StringsDefault3, 0x00A4 };
static const XStringRes _Const0067 = { _StringsDefault3, 0x00B3 };
static const XStringRes _Const0068 = { _StringsDefault3, 0x00C3 };
static const XStringRes _Const0069 = { _StringsDefault3, 0x00CD };
static const XStringRes _Const006A = { _StringsDefault3, 0x00D6 };
static const XStringRes _Const006B = { _StringsDefault3, 0x00DF };
static const XStringRes _Const006C = { _StringsDefault3, 0x00E9 };
static const XStringRes _Const006D = { _StringsDefault3, 0x00F4 };
static const XStringRes _Const006E = { _StringsDefault3, 0x00FE };
static const XStringRes _Const006F = { _StringsDefault3, 0x0114 };
static const XStringRes _Const0070 = { _StringsDefault3, 0x0129 };
static const XStringRes _Const0071 = { _StringsDefault3, 0x0131 };
static const XStringRes _Const0072 = { _StringsDefault3, 0x013B };
static const XStringRes _Const0073 = { _StringsDefault3, 0x0143 };
static const XStringRes _Const0074 = { _StringsDefault3, 0x0150 };
static const XStringRes _Const0075 = { _StringsDefault3, 0x0159 };
static const XStringRes _Const0076 = { _StringsDefault3, 0x016D };
static const XStringRes _Const0077 = { _StringsDefault3, 0x0174 };
static const XStringRes _Const0078 = { _StringsDefault3, 0x0181 };
static const XStringRes _Const0079 = { _StringsDefault3, 0x0190 };
static const XStringRes _Const007A = { _StringsDefault3, 0x0198 };
static const XStringRes _Const007B = { _StringsDefault3, 0x01A0 };
static const XStringRes _Const007C = { _StringsDefault3, 0x01B0 };
static const XStringRes _Const007D = { _StringsDefault3, 0x01BE };
static const XStringRes _Const007E = { _StringsDefault3, 0x01CB };
static const XStringRes _Const007F = { _StringsDefault3, 0x01D4 };
static const XStringRes _Const0080 = { _StringsDefault3, 0x01DF };
static const XStringRes _Const0081 = { _StringsDefault3, 0x01E7 };
static const XStringRes _Const0082 = { _StringsDefault3, 0x01EE };
static const XStringRes _Const0083 = { _StringsDefault3, 0x0201 };
static const XStringRes _Const0084 = { _StringsDefault4, 0x0002 };
static const XStringRes _Const0085 = { _StringsDefault4, 0x000D };

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
  MenuBaseMenuView_LoadItemDeviceAddress,
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
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DevelopmentDEV_Bluetooth );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DevelopmentDEV_Bluetooth );

  /* ... and initialize objects, variables, properties, etc. */
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 5 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  MenuVerticalMenu_OnSetArrowScrollBarVisible( &_this->Super1.Menu, 1 );
}

/* Re-Initializer for the class 'Development::DEV_Bluetooth' */
void DevelopmentDEV_Bluetooth__ReInit( DevelopmentDEV_Bluetooth _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Development::DEV_Bluetooth' */
void DevelopmentDEV_Bluetooth__Done( DevelopmentDEV_Bluetooth _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* 'C' function for method : 'Development::DEV_Bluetooth.OnShortHomeKeyActivated()' */
void DevelopmentDEV_Bluetooth_OnShortHomeKeyActivated( DevelopmentDEV_Bluetooth _this )
{
  CoreGroup_DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Development::DEV_Bluetooth.LoadItemClass()' */
XClass DevelopmentDEV_Bluetooth_LoadItemClass( DevelopmentDEV_Bluetooth _this, XInt32 
  aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemBaseValue );
}

/* 'C' function for method : 'Development::DEV_Bluetooth.LoadItemTitle()' */
XString DevelopmentDEV_Bluetooth_LoadItemTitle( DevelopmentDEV_Bluetooth _this, 
  XInt32 aItemNo )
{
  XString Title;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Title = 0;

  switch ( aItemNo )
  {
    case 0 :
      Title = EwConcatString( EwLoadString( &_Const0016 ), DeviceInterfaceBluetoothDeviceClass_OnGetBtSoftwareVersion( 
      EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )));
    break;

    case 1 :
      Title = DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceName( EwGetAutoObject( 
      &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ));
    break;

    case 2 :
      Title = DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceAddress( EwGetAutoObject( 
      &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ));
    break;

    case 3 :
    {
      Title = EwLoadString( &_Const0017 );

      switch ( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->LogLevel )
      {
        case 0 :
          Title = EwConcatString( Title, EwLoadString( &_Const0018 ));
        break;

        case 1 :
          Title = EwConcatString( Title, EwLoadString( &_Const0019 ));
        break;

        case 2 :
          Title = EwConcatString( Title, EwLoadString( &_Const001A ));
        break;

        case 3 :
          Title = EwConcatString( Title, EwLoadString( &_Const001B ));
        break;

        case 4 :
          Title = EwConcatString( Title, EwLoadString( &_Const001C ));
        break;

        case 5 :
          Title = EwConcatString( Title, EwLoadString( &_Const001D ));
        break;

        default :; 
      }
    }
    break;

    case 4 :
      Title = EwLoadString( &_Const001E );
    break;

    default :; 
  }

  return Title;
}

/* 'C' function for method : 'Development::DEV_Bluetooth.OnItemActivate()' */
void DevelopmentDEV_Bluetooth_OnItemActivate( DevelopmentDEV_Bluetooth _this, XInt32 
  aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  switch ( aItemNo )
  {
    case 3 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_BtLogLevel, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 4 :
      DeviceInterfaceBluetoothDeviceClass_UpdateBtFirmware( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
      DeviceInterfaceBluetoothDeviceClass ));
    break;

    default :; 
  }
}

/* 'C' function for method : 'Development::DEV_Bluetooth.OnLogLevelChangedSlot()' */
void DevelopmentDEV_Bluetooth_OnLogLevelChangedSlot( DevelopmentDEV_Bluetooth _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 3, 3 );
}

/* Variants derived from the class : 'Development::DEV_Bluetooth' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_Bluetooth )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_Bluetooth )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_Bluetooth' */
EW_DEFINE_CLASS( DevelopmentDEV_Bluetooth, MenuBaseMenuView, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, _.VMT, "Development::DEV_Bluetooth" )
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
  MenuBaseMenuView_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  DevelopmentDEV_Bluetooth_LoadItemClass,
  DevelopmentDEV_Bluetooth_LoadItemTitle,
  DevelopmentDEV_Bluetooth_OnItemActivate,
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
  MenuBaseMenuView_LoadItemDeviceAddress,
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
  CoreRectView__OnSetBounds( &_this->ChessboardImage, _Const001F );
  CoreRectView__OnSetBounds( &_this->LevelText, _Const0020 );
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
  EwTrace( "%s%t", EwLoadString( &_Const0021 ), aState );
  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );
  EwTrace( "%s%*", EwLoadString( &_Const0022 ), App );

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
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0023 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0024 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0025 ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const0026 ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const0027 ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const0028 ));
  _this->ItemTitleArray[ 6 ] = EwShareString( EwLoadString( &_Const0029 ));
  _this->ItemTitleArray[ 7 ] = EwShareString( EwLoadString( &_Const002A ));
  _this->ItemTitleArray[ 8 ] = EwShareString( EwLoadString( &_Const002B ));
  _this->ItemTitleArray[ 9 ] = EwShareString( EwLoadString( &_Const002C ));
  _this->ItemTitleArray[ 10 ] = EwShareString( EwLoadString( &_Const002D ));
  _this->ItemTitleArray[ 11 ] = EwShareString( EwLoadString( &_Const002E ));
  _this->ItemTitleArray[ 12 ] = EwShareString( EwLoadString( &_Const002F ));
  _this->ItemTitleArray[ 13 ] = EwShareString( EwLoadString( &_Const0030 ));
  _this->ItemTitleArray[ 14 ] = EwShareString( EwLoadString( &_Const0031 ));
  _this->ItemTitleArray[ 15 ] = EwShareString( EwLoadString( &_Const0032 ));
  _this->ItemTitleArray[ 16 ] = EwShareString( EwLoadString( &_Const0033 ));
  _this->ItemTitleArray[ 17 ] = EwShareString( EwLoadString( &_Const0034 ));
  _this->ItemTitleArray[ 18 ] = EwShareString( EwLoadString( &_Const0035 ));
  _this->ItemTitleArray[ 19 ] = EwShareString( EwLoadString( &_Const0036 ));
  _this->ItemTitleArray[ 20 ] = EwShareString( EwLoadString( &_Const0037 ));
  _this->ItemTitleArray[ 21 ] = EwShareString( EwLoadString( &_Const0038 ));
  _this->ItemTitleArray[ 22 ] = EwShareString( EwLoadString( &_Const0039 ));
  _this->ItemTitleArray[ 23 ] = EwShareString( EwLoadString( &_Const003A ));
  _this->ItemTitleArray[ 24 ] = EwShareString( EwLoadString( &_Const003B ));
  _this->ItemTitleArray[ 25 ] = EwShareString( EwLoadString( &_Const003C ));
  _this->ItemTitleArray[ 26 ] = EwShareString( EwLoadString( &_Const003D ));
  _this->ItemTitleArray[ 27 ] = EwShareString( EwLoadString( &_Const003E ));
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
  MenuBaseMenuView_LoadItemDeviceAddress,
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
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const003F ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0040 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0041 ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const0042 ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const0043 ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const0044 ));
  _this->ItemTitleArray[ 6 ] = EwShareString( EwLoadString( &_Const0045 ));
  _this->ItemTitleArray[ 7 ] = EwShareString( EwLoadString( &_Const0046 ));
  _this->ItemTitleArray[ 8 ] = EwShareString( EwLoadString( &_Const0047 ));
  _this->ItemTitleArray[ 9 ] = EwShareString( EwLoadString( &_Const0048 ));
  _this->ItemTitleArray[ 10 ] = EwShareString( EwLoadString( &_Const0049 ));
  _this->ItemTitleArray[ 11 ] = EwShareString( EwLoadString( &_Const004A ));
  _this->ItemTitleArray[ 12 ] = EwShareString( EwLoadString( &_Const004B ));
  _this->ItemTitleArray[ 13 ] = EwShareString( EwLoadString( &_Const004C ));
  _this->ItemTitleArray[ 14 ] = EwShareString( EwLoadString( &_Const004D ));
  _this->ItemTitleArray[ 15 ] = EwShareString( EwLoadString( &_Const004E ));
  _this->ItemTitleArray[ 16 ] = EwShareString( EwLoadString( &_Const004F ));
  _this->ItemTitleArray[ 17 ] = EwShareString( EwLoadString( &_Const0050 ));
  _this->ItemTitleArray[ 18 ] = EwShareString( EwLoadString( &_Const0051 ));
  _this->ItemTitleArray[ 19 ] = EwShareString( EwLoadString( &_Const0052 ));
  _this->ItemTitleArray[ 20 ] = EwShareString( EwLoadString( &_Const0053 ));
  _this->ItemTitleArray[ 21 ] = EwShareString( EwLoadString( &_Const0054 ));
  _this->ItemTitleArray[ 22 ] = EwShareString( EwLoadString( &_Const0055 ));
  _this->ItemTitleArray[ 23 ] = EwShareString( EwLoadString( &_Const0056 ));
  _this->ItemTitleArray[ 24 ] = EwShareString( EwLoadString( &_Const0057 ));
  _this->ItemTitleArray[ 25 ] = EwShareString( EwLoadString( &_Const0058 ));
  _this->ItemTitleArray[ 26 ] = EwShareString( EwLoadString( &_Const0059 ));
  _this->ItemTitleArray[ 27 ] = EwShareString( EwLoadString( &_Const005A ));
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
  MenuBaseMenuView_LoadItemDeviceAddress,
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
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const005B ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const005C ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const005D ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const005E ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const005F ));
  _this->ItemTitleArray[ 5 ] = EwShareString( EwLoadString( &_Const0060 ));
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
  MenuBaseMenuView_LoadItemDeviceAddress,
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
  CoreRectView__OnSetBounds( &_this->Text, _Const0061 );
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
    EwTrace( "%s%i", EwLoadString( &_Const0062 ), _this->PageScrollOffset );
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
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0063 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0064 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0065 ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const0066 ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const0067 ));
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
  MenuBaseMenuView_LoadItemDeviceAddress,
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
        Title = EwLoadString( &_Const0068 );
      break;

      case EnumLanguageFRENCH :
        Title = EwLoadString( &_Const0069 );
      break;

      case EnumLanguageGERMAN :
        Title = EwLoadString( &_Const006A );
      break;

      case EnumLanguageITALIAN :
        Title = EwLoadString( &_Const006B );
      break;

      case EnumLanguageJAPANESE :
        Title = EwLoadString( &_Const006C );
      break;

      case EnumLanguageSPANISH :
        Title = EwLoadString( &_Const006D );
      break;

      case EnumLanguageTRADITIONAL_CHINESE :
        Title = EwLoadString( &_Const006E );
      break;

      case EnumLanguageSIMPLIFIED_CHINESE :
        Title = EwLoadString( &_Const006F );
      break;

      case EnumLanguageGREEK :
        Title = EwLoadString( &_Const0070 );
      break;

      case EnumLanguageFINNISH :
        Title = EwLoadString( &_Const0071 );
      break;

      case EnumLanguageHINDI :
        Title = EwLoadString( &_Const0072 );
      break;

      case EnumLanguageINDONESIAN :
        Title = EwLoadString( &_Const0073 );
      break;

      case EnumLanguagePOLISH :
        Title = EwLoadString( &_Const0074 );
      break;

      case EnumLanguagePORTUGUESE_BRAZIL :
        Title = EwLoadString( &_Const0075 );
      break;

      case EnumLanguageTHAI :
        Title = EwLoadString( &_Const0076 );
      break;

      case EnumLanguageVIETNAMESE :
        Title = EwLoadString( &_Const0077 );
      break;

      case EnumLanguageKOREAN :
        Title = EwLoadString( &_Const0078 );
      break;

      case EnumLanguageMALAY :
        Title = EwLoadString( &_Const0079 );
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
  MenuBaseMenuView_LoadItemDeviceAddress,
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
  _this->CategoryList[ 0 ] = EwShareString( EwLoadString( &_Const003F ));
  _this->CategoryList[ 1 ] = EwShareString( EwLoadString( &_Const007A ));
  _this->CategoryList[ 2 ] = EwShareString( EwLoadString( &_Const007B ));
  _this->CategoryList[ 3 ] = EwShareString( EwLoadString( &_Const007C ));
  _this->CategoryList[ 4 ] = EwShareString( EwLoadString( &_Const007D ));
  _this->CategoryList[ 5 ] = EwShareString( EwLoadString( &_Const007E ));
  _this->CategoryList[ 6 ] = EwShareString( EwLoadString( &_Const007F ));
  _this->CategoryList[ 7 ] = EwShareString( EwLoadString( &_Const0080 ));
  _this->CategoryList[ 8 ] = EwShareString( EwLoadString( &_Const0081 ));
  _this->CategoryList[ 9 ] = EwShareString( EwLoadString( &_Const0082 ));
  _this->CategoryList[ 10 ] = EwShareString( EwLoadString( &_Const0083 ));
  _this->CategoryList[ 11 ] = EwShareString( EwLoadString( &_Const0084 ));
  _this->CategoryList[ 12 ] = EwShareString( EwLoadString( &_Const0085 ));
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
  MenuBaseMenuView_LoadItemDeviceAddress,
EW_END_OF_CLASS( DevelopmentDEV_AncsCategory )

/* Initializer for the class 'Development::DEV_BtLogLevel' */
void DevelopmentDEV_BtLogLevel__Init( DevelopmentDEV_BtLogLevel _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( DevelopmentDEV_BtLogLevel );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( DevelopmentDEV_BtLogLevel );

  /* ... and initialize objects, variables, properties, etc. */
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 6 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Super1.Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Super1.Menu, 4 );
  MenuVerticalMenu_OnSetArrowScrollBarVisible( &_this->Super1.Menu, 1 );
}

/* Re-Initializer for the class 'Development::DEV_BtLogLevel' */
void DevelopmentDEV_BtLogLevel__ReInit( DevelopmentDEV_BtLogLevel _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Development::DEV_BtLogLevel' */
void DevelopmentDEV_BtLogLevel__Done( DevelopmentDEV_BtLogLevel _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* 'C' function for method : 'Development::DEV_BtLogLevel.OnShortHomeKeyActivated()' */
void DevelopmentDEV_BtLogLevel_OnShortHomeKeyActivated( DevelopmentDEV_BtLogLevel _this )
{
  CoreGroup_DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Development::DEV_BtLogLevel.LoadItemClass()' */
XClass DevelopmentDEV_BtLogLevel_LoadItemClass( DevelopmentDEV_BtLogLevel _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemCheckMark );
}

/* 'C' function for method : 'Development::DEV_BtLogLevel.LoadItemTitle()' */
XString DevelopmentDEV_BtLogLevel_LoadItemTitle( DevelopmentDEV_BtLogLevel _this, 
  XInt32 aItemNo )
{
  XString Title;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Title = 0;

  switch ( aItemNo )
  {
    case 0 :
      Title = EwLoadString( &_Const0018 );
    break;

    case 1 :
      Title = EwLoadString( &_Const0019 );
    break;

    case 2 :
      Title = EwLoadString( &_Const001A );
    break;

    case 3 :
      Title = EwLoadString( &_Const001B );
    break;

    case 4 :
      Title = EwLoadString( &_Const001C );
    break;

    case 5 :
      Title = EwLoadString( &_Const001D );
    break;

    default :; 
  }

  return Title;
}

/* 'C' function for method : 'Development::DEV_BtLogLevel.OnItemActivate()' */
void DevelopmentDEV_BtLogLevel_OnItemActivate( DevelopmentDEV_BtLogLevel _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  DevelopmentDEV_Bluetooth DevBtTestPage;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  DeviceInterfaceBluetoothDeviceClass_OnSetLogLevel( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ), aItemNo );
  DevBtTestPage = EwCastObject( _this->Super6.Owner, DevelopmentDEV_Bluetooth );

  if ( DevBtTestPage != 0 )
    EwPostSignal( EwNewSlot( DevBtTestPage, DevelopmentDEV_Bluetooth_OnLogLevelChangedSlot ), 
      ((XObject)_this ));

  ComponentsBaseMainBG_DismissThisDialog((ComponentsBaseMainBG)_this );
}

/* 'C' function for method : 'Development::DEV_BtLogLevel.LoadItemChecked()' */
XBool DevelopmentDEV_BtLogLevel_LoadItemChecked( DevelopmentDEV_BtLogLevel _this, 
  XInt32 aItemNo )
{
  XBool Checked;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Checked = 0;

  if ( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->LogLevel 
      == aItemNo )
    Checked = 1;

  return Checked;
}

/* Variants derived from the class : 'Development::DEV_BtLogLevel' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_BtLogLevel )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_BtLogLevel )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_BtLogLevel' */
EW_DEFINE_CLASS( DevelopmentDEV_BtLogLevel, MenuBaseMenuView, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, _.VMT, "Development::DEV_BtLogLevel" )
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
  DevelopmentDEV_BtLogLevel_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  MenuBaseMenuView_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  DevelopmentDEV_BtLogLevel_LoadItemClass,
  DevelopmentDEV_BtLogLevel_LoadItemTitle,
  DevelopmentDEV_BtLogLevel_OnItemActivate,
  DevelopmentDEV_BtLogLevel_LoadItemChecked,
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
  MenuBaseMenuView_LoadItemDeviceAddress,
EW_END_OF_CLASS( DevelopmentDEV_BtLogLevel )

/* Embedded Wizard */
