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
#include "_CoreVerticalList.h"
#include "_CoreView.h"
#include "_DeviceInterfaceVehicleDataClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_DeviceInterfaceWeatherDeviceClass.h"
#include "_EffectsInt32Effect.h"
#include "_MenuArrowScrollBar.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsLine.h"
#include "_ViewsText.h"
#include "_WeatherWEA01_Main.h"
#include "_WeatherWeatherDayViewUI.h"
#include "_WeatherWeatherItemWrapper.h"
#include "_WeatherWeatherList.h"
#include "_WeatherWeatherWeekViewUI.h"
#include "Core.h"
#include "DeviceInterface.h"
#include "Effects.h"
#include "Enum.h"
#include "Fonts.h"
#include "Resource.h"
#include "Views.h"
#include "Weather.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x000000B0, /* ratio 65.91 % */
  0xB8000B00, 0x00066452, 0x0A120034, 0x60E32824, 0x8B0B0042, 0xD09870C4, 0x5322C0C0,
  0xE001D400, 0x8245A1E6, 0xE1BC004D, 0x1522F1E8, 0x94CA008D, 0x25257824, 0x8B2B3200,
  0xB1B8449C, 0x002345E2, 0x134800E4, 0x00186333, 0xB8121E74, 0x8661E2F8, 0xFE5C778B,
  0xA5508A0C, 0x9200104E, 0x06B954AA, 0x3B3B5400, 0xCA85265D, 0xA0CF23B3, 0x04061F0F,
  0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 224 }};
static const XRect _Const0001 = {{ 129, 15 }, { 353, 49 }};
static const XRect _Const0002 = {{ 142, 59 }, { 197, 93 }};
static const XRect _Const0003 = {{ 199, 60 }, { 264, 91 }};
static const XRect _Const0004 = {{ 394, 60 }, { 425, 91 }};
static const XRect _Const0005 = {{ 363, 15 }, { 431, 49 }};
static const XColor _Const0006 = { 0xA0, 0xA0, 0xA0, 0xFF };
static const XRect _Const0007 = {{ 20, 13 }, { 113, 106 }};
static const XRect _Const0008 = {{ 0, 118 }, { 480, 121 }};
static const XPoint _Const0009 = { 155, 224 };
static const XPoint _Const000A = { 155, 118 };
static const XColor _Const000B = { 0x80, 0x80, 0x80, 0xFF };
static const XPoint _Const000C = { 299, 224 };
static const XPoint _Const000D = { 299, 118 };
static const XRect _Const000E = {{ 382, 123 }, { 434, 154 }};
static const XStringRes _Const000F = { _StringsDefault0, 0x0002 };
static const XRect _Const0010 = {{ 237, 123 }, { 289, 154 }};
static const XStringRes _Const0011 = { _StringsDefault0, 0x0007 };
static const XRect _Const0012 = {{ 93, 123 }, { 145, 154 }};
static const XStringRes _Const0013 = { _StringsDefault0, 0x000C };
static const XRect _Const0014 = {{ 20, 122 }, { 84, 186 }};
static const XRect _Const0015 = {{ 164, 122 }, { 228, 186 }};
static const XRect _Const0016 = {{ 308, 122 }, { 372, 186 }};
static const XRect _Const0017 = {{ 85, 165 }, { 127, 196 }};
static const XRect _Const0018 = {{ 229, 165 }, { 271, 196 }};
static const XRect _Const0019 = {{ 373, 165 }, { 415, 196 }};
static const XRect _Const001A = {{ 127, 169 }, { 149, 190 }};
static const XRect _Const001B = {{ 271, 169 }, { 293, 190 }};
static const XRect _Const001C = {{ 415, 169 }, { 437, 190 }};
static const XRect _Const001D = {{ 85, 191 }, { 127, 222 }};
static const XRect _Const001E = {{ 229, 191 }, { 271, 222 }};
static const XRect _Const001F = {{ 373, 191 }, { 415, 222 }};
static const XRect _Const0020 = {{ 127, 195 }, { 149, 216 }};
static const XRect _Const0021 = {{ 271, 195 }, { 293, 216 }};
static const XRect _Const0022 = {{ 415, 195 }, { 437, 216 }};
static const XStringRes _Const0023 = { _StringsDefault0, 0x0011 };
static const XStringRes _Const0024 = { _StringsDefault0, 0x0017 };
static const XStringRes _Const0025 = { _StringsDefault0, 0x001D };
static const XStringRes _Const0026 = { _StringsDefault0, 0x0023 };
static const XStringRes _Const0027 = { _StringsDefault0, 0x0029 };
static const XStringRes _Const0028 = { _StringsDefault0, 0x002F };
static const XStringRes _Const0029 = { _StringsDefault0, 0x0035 };
static const XRect _Const002A = {{ 280, 59 }, { 336, 93 }};
static const XColor _Const002B = { 0x28, 0xAA, 0xFF, 0xFF };
static const XRect _Const002C = {{ 336, 59 }, { 347, 93 }};
static const XStringRes _Const002D = { _StringsDefault0, 0x003B };
static const XRect _Const002E = {{ 347, 59 }, { 392, 93 }};
static const XColor _Const002F = { 0xFF, 0x28, 0x28, 0xFF };
static const XRect _Const0030 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0031 = {{ 0, 36 }, { 480, 272 }};
static const XRect _Const0032 = {{ 20, 7 }, { 84, 71 }};
static const XRect _Const0033 = {{ 85, 8 }, { 146, 39 }};
static const XRect _Const0034 = {{ 85, 50 }, { 127, 81 }};
static const XRect _Const0035 = {{ 30, 76 }, { 75, 107 }};
static const XPoint _Const0036 = { 155, 111 };
static const XPoint _Const0037 = { 155, 5 };
static const XPoint _Const0038 = { 299, 111 };
static const XPoint _Const0039 = { 299, 5 };
static const XRect _Const003A = {{ 164, 7 }, { 228, 71 }};
static const XRect _Const003B = {{ 127, 54 }, { 149, 75 }};
static const XRect _Const003C = {{ 229, 8 }, { 290, 39 }};
static const XRect _Const003D = {{ 229, 50 }, { 271, 81 }};
static const XRect _Const003E = {{ 271, 54 }, { 293, 75 }};
static const XRect _Const003F = {{ 174, 76 }, { 219, 107 }};
static const XRect _Const0040 = {{ 308, 7 }, { 372, 71 }};
static const XRect _Const0041 = {{ 373, 8 }, { 434, 39 }};
static const XRect _Const0042 = {{ 373, 50 }, { 415, 81 }};
static const XRect _Const0043 = {{ 415, 54 }, { 437, 75 }};
static const XRect _Const0044 = {{ 318, 76 }, { 363, 107 }};
static const XRect _Const0045 = {{ 0, 109 }, { 480, 111 }};
static const XRect _Const0046 = {{ 20, 122 }, { 84, 176 }};
static const XRect _Const0047 = {{ 164, 122 }, { 228, 176 }};
static const XRect _Const0048 = {{ 308, 122 }, { 372, 176 }};
static const XRect _Const0049 = {{ 85, 123 }, { 146, 154 }};
static const XRect _Const004A = {{ 229, 123 }, { 290, 154 }};
static const XRect _Const004B = {{ 373, 123 }, { 434, 154 }};
static const XRect _Const004C = {{ 30, 191 }, { 75, 222 }};
static const XRect _Const004D = {{ 174, 191 }, { 219, 222 }};
static const XRect _Const004E = {{ 318, 191 }, { 363, 222 }};
static const XRect _Const004F = {{ 127, 80 }, { 149, 101 }};
static const XRect _Const0050 = {{ 271, 80 }, { 293, 101 }};
static const XRect _Const0051 = {{ 415, 80 }, { 437, 101 }};
static const XRect _Const0052 = {{ 75, 76 }, { 85, 107 }};
static const XRect _Const0053 = {{ 85, 76 }, { 127, 107 }};
static const XRect _Const0054 = {{ 219, 76 }, { 229, 107 }};
static const XRect _Const0055 = {{ 229, 76 }, { 271, 107 }};
static const XRect _Const0056 = {{ 363, 76 }, { 373, 107 }};
static const XRect _Const0057 = {{ 373, 76 }, { 415, 107 }};
static const XRect _Const0058 = {{ 75, 191 }, { 85, 222 }};
static const XRect _Const0059 = {{ 219, 191 }, { 229, 222 }};
static const XRect _Const005A = {{ 363, 191 }, { 373, 222 }};
static const XStringRes _Const005B = { _StringsDefault0, 0x003F };
static const XRect _Const005C = {{ 0, 0 }, { 480, 236 }};
static const XRect _Const005D = {{ 0, 2 }, { 435, 226 }};
static const XRect _Const005E = {{ 441, 5 }, { 473, 221 }};
static const XRect _Const005F = {{ 0, 0 }, { 441, 224 }};

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

/* Initializer for the class 'Weather::WeatherDayViewUI' */
void WeatherWeatherDayViewUI__Init( WeatherWeatherDayViewUI _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( WeatherWeatherDayViewUI );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->CurrentLocationText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->ChanceOfRainText, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->PerOfRainIcon, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->TempUnitIcon, &_this->_XObject, 0 );
  ViewsText__Init( &_this->WeekDayText, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->WeatherIcon, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->WeatherHorizLine, &_this->_XObject, 0 );
  ViewsLine__Init( &_this->DivideLineLeft, &_this->_XObject, 0 );
  ViewsLine__Init( &_this->DivideLineRight, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TimeInterval3h, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TimeInterval2h, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TimeInterval1h, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Weather1h, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Weather2h, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Weather3h, &_this->_XObject, 0 );
  ViewsText__Init( &_this->ChanceOfRain1h, &_this->_XObject, 0 );
  ViewsText__Init( &_this->ChanceOfRain2h, &_this->_XObject, 0 );
  ViewsText__Init( &_this->ChanceOfRain3h, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->WeaPerIcon1h, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->WeaPerIcon2h, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->WeaPerIcon3h, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Temp1h, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Temp2h, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Temp3h, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->TempUnit1h, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->TempUnit2h, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->TempUnit3h, &_this->_XObject, 0 );
  ViewsText__Init( &_this->MinTempText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TempTextSlash, &_this->_XObject, 0 );
  ViewsText__Init( &_this->MaxTempText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( WeatherWeatherDayViewUI );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->CurrentLocationText, _Const0001 );
  ViewsText_OnSetEllipsis( &_this->CurrentLocationText, 1 );
  ViewsText_OnSetString( &_this->CurrentLocationText, 0 );
  CoreRectView__OnSetBounds( &_this->ChanceOfRainText, _Const0002 );
  ViewsText_OnSetAlignment( &_this->ChanceOfRainText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ChanceOfRainText, 0 );
  CoreRectView__OnSetBounds( &_this->PerOfRainIcon, _Const0003 );
  CoreRectView__OnSetBounds( &_this->TempUnitIcon, _Const0004 );
  CoreRectView__OnSetBounds( &_this->WeekDayText, _Const0005 );
  ViewsText_OnSetString( &_this->WeekDayText, 0 );
  ViewsText_OnSetColor( &_this->WeekDayText, _Const0006 );
  CoreRectView__OnSetBounds( &_this->WeatherIcon, _Const0007 );
  ViewsImage_OnSetFrameNumber( &_this->WeatherIcon, 0 );
  CoreRectView__OnSetBounds( &_this->WeatherHorizLine, _Const0008 );
  CoreLineView_OnSetPoint2((CoreLineView)&_this->DivideLineLeft, _Const0009 );
  CoreLineView_OnSetPoint1((CoreLineView)&_this->DivideLineLeft, _Const000A );
  ViewsLine_OnSetWidth( &_this->DivideLineLeft, 2 );
  ViewsLine_OnSetColor( &_this->DivideLineLeft, _Const000B );
  CoreLineView_OnSetPoint2((CoreLineView)&_this->DivideLineRight, _Const000C );
  CoreLineView_OnSetPoint1((CoreLineView)&_this->DivideLineRight, _Const000D );
  ViewsLine_OnSetWidth( &_this->DivideLineRight, 2 );
  ViewsLine_OnSetColor( &_this->DivideLineRight, _Const000B );
  CoreRectView__OnSetBounds( &_this->TimeInterval3h, _Const000E );
  ViewsText_OnSetAlignment( &_this->TimeInterval3h, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TimeInterval3h, EwLoadString( &_Const000F ));
  CoreRectView__OnSetBounds( &_this->TimeInterval2h, _Const0010 );
  ViewsText_OnSetAlignment( &_this->TimeInterval2h, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TimeInterval2h, EwLoadString( &_Const0011 ));
  CoreRectView__OnSetBounds( &_this->TimeInterval1h, _Const0012 );
  ViewsText_OnSetAlignment( &_this->TimeInterval1h, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TimeInterval1h, EwLoadString( &_Const0013 ));
  CoreRectView__OnSetBounds( &_this->Weather1h, _Const0014 );
  CoreRectView__OnSetBounds( &_this->Weather2h, _Const0015 );
  CoreRectView__OnSetBounds( &_this->Weather3h, _Const0016 );
  CoreRectView__OnSetBounds( &_this->ChanceOfRain1h, _Const0017 );
  ViewsText_OnSetAlignment( &_this->ChanceOfRain1h, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ChanceOfRain1h, 0 );
  CoreRectView__OnSetBounds( &_this->ChanceOfRain2h, _Const0018 );
  ViewsText_OnSetAlignment( &_this->ChanceOfRain2h, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ChanceOfRain2h, 0 );
  CoreRectView__OnSetBounds( &_this->ChanceOfRain3h, _Const0019 );
  ViewsText_OnSetAlignment( &_this->ChanceOfRain3h, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ChanceOfRain3h, 0 );
  CoreRectView__OnSetBounds( &_this->WeaPerIcon1h, _Const001A );
  CoreRectView__OnSetBounds( &_this->WeaPerIcon2h, _Const001B );
  CoreRectView__OnSetBounds( &_this->WeaPerIcon3h, _Const001C );
  CoreRectView__OnSetBounds( &_this->Temp1h, _Const001D );
  ViewsText_OnSetAlignment( &_this->Temp1h, ViewsTextAlignmentAlignHorzRight | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Temp1h, 0 );
  CoreRectView__OnSetBounds( &_this->Temp2h, _Const001E );
  ViewsText_OnSetAlignment( &_this->Temp2h, ViewsTextAlignmentAlignHorzRight | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Temp2h, 0 );
  CoreRectView__OnSetBounds( &_this->Temp3h, _Const001F );
  ViewsText_OnSetAlignment( &_this->Temp3h, ViewsTextAlignmentAlignHorzRight | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Temp3h, 0 );
  CoreRectView__OnSetBounds( &_this->TempUnit1h, _Const0020 );
  CoreRectView__OnSetBounds( &_this->TempUnit2h, _Const0021 );
  CoreRectView__OnSetBounds( &_this->TempUnit3h, _Const0022 );
  _this->WeekDayTextArray[ 0 ] = EwShareString( EwLoadString( &_Const0023 ));
  _this->WeekDayTextArray[ 1 ] = EwShareString( EwLoadString( &_Const0024 ));
  _this->WeekDayTextArray[ 2 ] = EwShareString( EwLoadString( &_Const0025 ));
  _this->WeekDayTextArray[ 3 ] = EwShareString( EwLoadString( &_Const0026 ));
  _this->WeekDayTextArray[ 4 ] = EwShareString( EwLoadString( &_Const0027 ));
  _this->WeekDayTextArray[ 5 ] = EwShareString( EwLoadString( &_Const0028 ));
  _this->WeekDayTextArray[ 6 ] = EwShareString( EwLoadString( &_Const0029 ));
  _this->WeaItemIdxArray[ 0 ] = EnumWeatherTimeTypeWEATHER_CURRENT;
  _this->WeaItemIdxArray[ 1 ] = EnumWeatherTimeTypeWEATHER_AFTER_1HOUR;
  _this->WeaItemIdxArray[ 2 ] = EnumWeatherTimeTypeWEATHER_AFTER_2HOUR;
  _this->WeaItemIdxArray[ 3 ] = EnumWeatherTimeTypeWEATHER_AFTER_3HOUR;
  CoreRectView__OnSetBounds( &_this->MinTempText, _Const002A );
  ViewsText_OnSetAlignment( &_this->MinTempText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->MinTempText, 0 );
  ViewsText_OnSetColor( &_this->MinTempText, _Const002B );
  CoreRectView__OnSetBounds( &_this->TempTextSlash, _Const002C );
  ViewsText_OnSetAlignment( &_this->TempTextSlash, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TempTextSlash, EwLoadString( &_Const002D ));
  ViewsText_OnSetColor( &_this->TempTextSlash, _Const0006 );
  CoreRectView__OnSetBounds( &_this->MaxTempText, _Const002E );
  ViewsText_OnSetAlignment( &_this->MaxTempText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->MaxTempText, 0 );
  ViewsText_OnSetColor( &_this->MaxTempText, _Const002F );
  _this->MinTempTextBounds = _Const002A;
  _this->TempTextSlashBounds = _Const002C;
  CoreGroup__Add( _this, ((CoreView)&_this->CurrentLocationText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ChanceOfRainText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PerOfRainIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TempUnitIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->WeekDayText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->WeatherIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->WeatherHorizLine ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DivideLineLeft ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DivideLineRight ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeInterval3h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeInterval2h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeInterval1h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Weather1h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Weather2h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Weather3h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ChanceOfRain1h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ChanceOfRain2h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ChanceOfRain3h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->WeaPerIcon1h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->WeaPerIcon2h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->WeaPerIcon3h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Temp1h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Temp2h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Temp3h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TempUnit1h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TempUnit2h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TempUnit3h ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MinTempText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TempTextSlash ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MaxTempText ), 0 );
  ViewsText_OnSetFont( &_this->CurrentLocationText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->ChanceOfRainText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->PerOfRainIcon, EwLoadResource( &ResourceIconPerOfRain, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->TempUnitIcon, EwLoadResource( &ResourceIconTempDegC, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->WeekDayText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->WeatherIcon, EwLoadResource( &ResourceCurrentWeatherIcon, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->WeatherHorizLine, EwLoadResource( &ResourceWeatherLine, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->TimeInterval3h, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->TimeInterval2h, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->TimeInterval1h, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->Weather1h, EwLoadResource( &ResourceForecastWeatherIcon, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Weather2h, EwLoadResource( &ResourceForecastWeatherIcon, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Weather3h, EwLoadResource( &ResourceForecastWeatherIcon, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->ChanceOfRain1h, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->ChanceOfRain2h, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->ChanceOfRain3h, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->WeaPerIcon1h, EwLoadResource( &ResourceIconWeatherPercentage, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->WeaPerIcon2h, EwLoadResource( &ResourceIconWeatherPercentage, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->WeaPerIcon3h, EwLoadResource( &ResourceIconWeatherPercentage, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->Temp1h, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->Temp2h, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->Temp3h, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->TempUnit1h, EwLoadResource( &ResourceIconTempDeg, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->TempUnit2h, EwLoadResource( &ResourceIconTempDeg, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->TempUnit3h, EwLoadResource( &ResourceIconTempDeg, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->MinTempText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->TempTextSlash, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->MaxTempText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));

  /* Call the user defined constructor */
  WeatherWeatherDayViewUI_Init( _this, aArg );
}

/* Re-Initializer for the class 'Weather::WeatherDayViewUI' */
void WeatherWeatherDayViewUI__ReInit( WeatherWeatherDayViewUI _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->CurrentLocationText );
  ViewsText__ReInit( &_this->ChanceOfRainText );
  ViewsImage__ReInit( &_this->PerOfRainIcon );
  ViewsImage__ReInit( &_this->TempUnitIcon );
  ViewsText__ReInit( &_this->WeekDayText );
  ViewsImage__ReInit( &_this->WeatherIcon );
  ViewsImage__ReInit( &_this->WeatherHorizLine );
  ViewsLine__ReInit( &_this->DivideLineLeft );
  ViewsLine__ReInit( &_this->DivideLineRight );
  ViewsText__ReInit( &_this->TimeInterval3h );
  ViewsText__ReInit( &_this->TimeInterval2h );
  ViewsText__ReInit( &_this->TimeInterval1h );
  ViewsImage__ReInit( &_this->Weather1h );
  ViewsImage__ReInit( &_this->Weather2h );
  ViewsImage__ReInit( &_this->Weather3h );
  ViewsText__ReInit( &_this->ChanceOfRain1h );
  ViewsText__ReInit( &_this->ChanceOfRain2h );
  ViewsText__ReInit( &_this->ChanceOfRain3h );
  ViewsImage__ReInit( &_this->WeaPerIcon1h );
  ViewsImage__ReInit( &_this->WeaPerIcon2h );
  ViewsImage__ReInit( &_this->WeaPerIcon3h );
  ViewsText__ReInit( &_this->Temp1h );
  ViewsText__ReInit( &_this->Temp2h );
  ViewsText__ReInit( &_this->Temp3h );
  ViewsImage__ReInit( &_this->TempUnit1h );
  ViewsImage__ReInit( &_this->TempUnit2h );
  ViewsImage__ReInit( &_this->TempUnit3h );
  ViewsText__ReInit( &_this->MinTempText );
  ViewsText__ReInit( &_this->TempTextSlash );
  ViewsText__ReInit( &_this->MaxTempText );
}

/* Finalizer method for the class 'Weather::WeatherDayViewUI' */
void WeatherWeatherDayViewUI__Done( WeatherWeatherDayViewUI _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->CurrentLocationText );
  ViewsText__Done( &_this->ChanceOfRainText );
  ViewsImage__Done( &_this->PerOfRainIcon );
  ViewsImage__Done( &_this->TempUnitIcon );
  ViewsText__Done( &_this->WeekDayText );
  ViewsImage__Done( &_this->WeatherIcon );
  ViewsImage__Done( &_this->WeatherHorizLine );
  ViewsLine__Done( &_this->DivideLineLeft );
  ViewsLine__Done( &_this->DivideLineRight );
  ViewsText__Done( &_this->TimeInterval3h );
  ViewsText__Done( &_this->TimeInterval2h );
  ViewsText__Done( &_this->TimeInterval1h );
  ViewsImage__Done( &_this->Weather1h );
  ViewsImage__Done( &_this->Weather2h );
  ViewsImage__Done( &_this->Weather3h );
  ViewsText__Done( &_this->ChanceOfRain1h );
  ViewsText__Done( &_this->ChanceOfRain2h );
  ViewsText__Done( &_this->ChanceOfRain3h );
  ViewsImage__Done( &_this->WeaPerIcon1h );
  ViewsImage__Done( &_this->WeaPerIcon2h );
  ViewsImage__Done( &_this->WeaPerIcon3h );
  ViewsText__Done( &_this->Temp1h );
  ViewsText__Done( &_this->Temp2h );
  ViewsText__Done( &_this->Temp3h );
  ViewsImage__Done( &_this->TempUnit1h );
  ViewsImage__Done( &_this->TempUnit2h );
  ViewsImage__Done( &_this->TempUnit3h );
  ViewsText__Done( &_this->MinTempText );
  ViewsText__Done( &_this->TempTextSlash );
  ViewsText__Done( &_this->MaxTempText );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void WeatherWeatherDayViewUI_Init( WeatherWeatherDayViewUI _this, XHandle aArg )
{
  XInt32 i;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  for ( i = 0; i < 4; i++ )
  {
    DeviceInterfaceWeatherDeviceClass_GetWeatherInfo( EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
    DeviceInterfaceWeatherDeviceClass ), _this->WeaItemIdxArray[ EwCheckIndex( i, 
    4 )]);
    EwSignal( EwNewSlot( _this, WeatherWeatherDayViewUI_OnWeatherInfoUpdateSlot ), 
      ((XObject)_this ));
  }

  DeviceInterfaceWeatherDeviceClass_GetWeatherLoc( EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
  DeviceInterfaceWeatherDeviceClass ));
  EwSignal( EwNewSlot( _this, WeatherWeatherDayViewUI_OnWeatherLocUpdateSlot ), 
    ((XObject)_this ));
  DeviceInterfaceWeatherDeviceClass_GetWeekDay( EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
  DeviceInterfaceWeatherDeviceClass ));
  EwSignal( EwNewSlot( _this, WeatherWeatherDayViewUI_OnWeekDayUpdateSlot ), ((XObject)_this ));
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void WeatherWeatherDayViewUI_OnWeatherLocUpdateSlot( WeatherWeatherDayViewUI _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->IsWeatherInfoReceived )
  {
    ViewsText_OnSetString( &_this->CurrentLocationText, EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
    DeviceInterfaceWeatherDeviceClass )->WeatherLocation );
  }
}

/* 'C' function for method : 'Weather::WeatherDayViewUI.OnWeatherInfoUpdateSlot()' */
void WeatherWeatherDayViewUI_OnWeatherInfoUpdateSlot( WeatherWeatherDayViewUI _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->IsWeatherInfoReceived )
  {
    XEnum WeatherTime = (XEnum)EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->WeatherTime;

    switch ( WeatherTime )
    {
      case EnumWeatherTimeTypeWEATHER_CURRENT :
      {
        DeviceInterfaceVehicleDataClass VehicleData;
        XInt32 TempShiftPixel;
        XRect NewSlashBounds;
        XRect NewMinBounds;
        CoreRectView__OnSetBounds( &_this->MinTempText, _this->MinTempTextBounds );
        CoreRectView__OnSetBounds( &_this->TempTextSlash, _this->TempTextSlashBounds );
        ViewsImage_OnSetFrameNumber( &_this->WeatherIcon, EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
        DeviceInterfaceWeatherDeviceClass )->WeatherType );
        ViewsText_OnSetString( &_this->ChanceOfRainText, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->RainProbability, 
        0, 10 ));
        VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
        &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeTEMPERATURE_UNIT );

        if ((XEnum)VehicleData->DataUInt32 == EnumTemperatureSettingItemTEMP_F )
        {
          ViewsImage_OnSetBitmap( &_this->TempUnitIcon, EwLoadResource( &ResourceIconTempDegF, 
          ResourcesBitmap ));
        }
        else
        {
          ViewsImage_OnSetBitmap( &_this->TempUnitIcon, EwLoadResource( &ResourceIconTempDegC, 
          ResourcesBitmap ));
        }

        ViewsText_OnSetString( &_this->MinTempText, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->MinTemperature, 
        0, 10 ));
        ViewsText_OnSetString( &_this->MaxTempText, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->MaxTemperature, 
        0, 10 ));
        TempShiftPixel = EwGetRectW( _this->MaxTempText.Super1.Bounds ) - EwGetRectW( 
        ViewsText_GetContentArea( &_this->MaxTempText ));
        NewSlashBounds = _this->TempTextSlash.Super1.Bounds;
        NewMinBounds = _this->MinTempText.Super1.Bounds;
        NewSlashBounds.Point1.X = ( _this->TempTextSlash.Super1.Bounds.Point1.X 
        + TempShiftPixel );
        NewSlashBounds.Point2.X = ( _this->TempTextSlash.Super1.Bounds.Point2.X 
        + TempShiftPixel );
        NewMinBounds.Point1.X = ( _this->MinTempText.Super1.Bounds.Point1.X + TempShiftPixel );
        NewMinBounds.Point2.X = ( _this->MinTempText.Super1.Bounds.Point2.X + TempShiftPixel );
        CoreRectView__OnSetBounds( &_this->TempTextSlash, NewSlashBounds );
        CoreRectView__OnSetBounds( &_this->MinTempText, NewMinBounds );
      }
      break;

      case EnumWeatherTimeTypeWEATHER_AFTER_1HOUR :
      {
        ViewsImage_OnSetFrameNumber( &_this->Weather1h, EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
        DeviceInterfaceWeatherDeviceClass )->WeatherType );
        ViewsText_OnSetString( &_this->ChanceOfRain1h, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->RainProbability, 
        0, 10 ));
        ViewsText_OnSetString( &_this->Temp1h, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->Temperature, 
        0, 10 ));
      }
      break;

      case EnumWeatherTimeTypeWEATHER_AFTER_2HOUR :
      {
        ViewsImage_OnSetFrameNumber( &_this->Weather2h, EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
        DeviceInterfaceWeatherDeviceClass )->WeatherType );
        ViewsText_OnSetString( &_this->ChanceOfRain2h, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->RainProbability, 
        0, 10 ));
        ViewsText_OnSetString( &_this->Temp2h, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->Temperature, 
        0, 10 ));
      }
      break;

      case EnumWeatherTimeTypeWEATHER_AFTER_3HOUR :
      {
        ViewsImage_OnSetFrameNumber( &_this->Weather3h, EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
        DeviceInterfaceWeatherDeviceClass )->WeatherType );
        ViewsText_OnSetString( &_this->ChanceOfRain3h, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->RainProbability, 
        0, 10 ));
        ViewsText_OnSetString( &_this->Temp3h, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->Temperature, 
        0, 10 ));
      }
      break;

      default : 
        ;
    }
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void WeatherWeatherDayViewUI_OnWeekDayUpdateSlot( WeatherWeatherDayViewUI _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( 7 > EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->WeekDay )
  {
    ViewsText_OnSetString( &_this->WeekDayText, _this->WeekDayTextArray[ EwCheckIndex( 
    EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->WeekDay, 
    7 )]);
  }
}

/* Variants derived from the class : 'Weather::WeatherDayViewUI' */
EW_DEFINE_CLASS_VARIANTS( WeatherWeatherDayViewUI )
EW_END_OF_CLASS_VARIANTS( WeatherWeatherDayViewUI )

/* Virtual Method Table (VMT) for the class : 'Weather::WeatherDayViewUI' */
EW_DEFINE_CLASS( WeatherWeatherDayViewUI, CoreGroup, CurrentLocationText, CurrentLocationText, 
                 CurrentLocationText, CurrentLocationText, WeekDayTextArray, MinTempTextBounds, 
                 "Weather::WeatherDayViewUI" )
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
EW_END_OF_CLASS( WeatherWeatherDayViewUI )

/* Initializer for the class 'Weather::WEA01_Main' */
void WeatherWEA01_Main__Init( WeatherWEA01_Main _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( WeatherWEA01_Main );

  /* ... then construct all embedded objects */
  WeatherWeatherList__Init( &_this->WeatherListView, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( WeatherWEA01_Main );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0030 );
  CoreRectView__OnSetBounds( &_this->WeatherListView, _Const0031 );
  _this->WeatherListView.Super1.PassHomeKey = 1;
  CoreGroup__Add( _this, ((CoreView)&_this->WeatherListView ), 0 );
}

/* Re-Initializer for the class 'Weather::WEA01_Main' */
void WeatherWEA01_Main__ReInit( WeatherWEA01_Main _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  WeatherWeatherList__ReInit( &_this->WeatherListView );
}

/* Finalizer method for the class 'Weather::WEA01_Main' */
void WeatherWEA01_Main__Done( WeatherWEA01_Main _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  WeatherWeatherList__Done( &_this->WeatherListView );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* 'C' function for method : 'Weather::WEA01_Main.OnShortHomeKeyActivated()' */
void WeatherWEA01_Main_OnShortHomeKeyActivated( WeatherWEA01_Main _this )
{
  ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
  {
    ApplicationApplication_ReturnToLauncher( App );
  }
}

/* Variants derived from the class : 'Weather::WEA01_Main' */
EW_DEFINE_CLASS_VARIANTS( WeatherWEA01_Main )
EW_END_OF_CLASS_VARIANTS( WeatherWEA01_Main )

/* Virtual Method Table (VMT) for the class : 'Weather::WEA01_Main' */
EW_DEFINE_CLASS( WeatherWEA01_Main, ComponentsBaseMainBG, WeatherListView, WeatherListView, 
                 WeatherListView, WeatherListView, _None, _None, "Weather::WEA01_Main" )
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
  WeatherWEA01_Main_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( WeatherWEA01_Main )

/* Initializer for the class 'Weather::WeatherWeekViewUI' */
void WeatherWeatherWeekViewUI__Init( WeatherWeatherWeekViewUI _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( WeatherWeatherWeekViewUI );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->DayOneWeather, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayOneText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayOneChanceOfRain, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayOneMinTemp, &_this->_XObject, 0 );
  ViewsLine__Init( &_this->DivideLineUpLeft, &_this->_XObject, 0 );
  ViewsLine__Init( &_this->DivideLineUpRight, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DayTwoWeather, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DayOneRainPerIcon, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayTwoText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayTwoChanceOfRain, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DayTwoRainPerIcon, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayTwoMinTemp, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DayThreeWeather, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayThreeText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayThreeChanceOfRain, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DayThreeRainPerIcon, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayThreeMinTemp, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->WeatherLineUp, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->WeatherLineDown, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DayFourWeather, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DayFiveWeather, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DaySixWeather, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayFourText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayFiveText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DaySixText, &_this->_XObject, 0 );
  ViewsLine__Init( &_this->DivideLineDownLeft, &_this->_XObject, 0 );
  ViewsLine__Init( &_this->DivideLineDownRight, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayFourChanceOfRain, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayFiveChanceOfRain, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DaySixChanceOfRain, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DayFourRainPerIcon, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DayFiveRainPerIcon, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DaySixRainPerIcon, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayFourMinTemp, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayFiveMinTemp, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DaySixMinTemp, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DayOneTempUnit, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DayTwoTempUnit, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DayThreeTempUnit, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DayFourTempUnit, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DayFiveTempUnit, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DaySixTempUnit, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayOneTempSlash, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayOneMaxTemp, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayTwoTempSlash, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayTwoMaxTemp, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayThreeTempSlash, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayThreeMaxTemp, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayFourTempSlash, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayFourMaxTemp, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayFiveTempSlash, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayFiveMaxTemp, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DaySixTempSlash, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DaySixMaxTemp, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( WeatherWeatherWeekViewUI );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->DayOneWeather, _Const0032 );
  CoreRectView__OnSetBounds( &_this->DayOneText, _Const0033 );
  ViewsText_OnSetAlignment( &_this->DayOneText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayOneText, 0 );
  CoreRectView__OnSetBounds( &_this->DayOneChanceOfRain, _Const0034 );
  ViewsText_OnSetAlignment( &_this->DayOneChanceOfRain, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayOneChanceOfRain, 0 );
  CoreRectView__OnSetBounds( &_this->DayOneMinTemp, _Const0035 );
  ViewsText_OnSetAlignment( &_this->DayOneMinTemp, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayOneMinTemp, 0 );
  ViewsText_OnSetColor( &_this->DayOneMinTemp, _Const002B );
  CoreLineView_OnSetPoint2((CoreLineView)&_this->DivideLineUpLeft, _Const0036 );
  CoreLineView_OnSetPoint1((CoreLineView)&_this->DivideLineUpLeft, _Const0037 );
  ViewsLine_OnSetWidth( &_this->DivideLineUpLeft, 2 );
  ViewsLine_OnSetColor( &_this->DivideLineUpLeft, _Const000B );
  CoreLineView_OnSetPoint2((CoreLineView)&_this->DivideLineUpRight, _Const0038 );
  CoreLineView_OnSetPoint1((CoreLineView)&_this->DivideLineUpRight, _Const0039 );
  ViewsLine_OnSetWidth( &_this->DivideLineUpRight, 2 );
  ViewsLine_OnSetColor( &_this->DivideLineUpRight, _Const000B );
  CoreRectView__OnSetBounds( &_this->DayTwoWeather, _Const003A );
  CoreRectView__OnSetBounds( &_this->DayOneRainPerIcon, _Const003B );
  CoreRectView__OnSetBounds( &_this->DayTwoText, _Const003C );
  ViewsText_OnSetAlignment( &_this->DayTwoText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayTwoText, 0 );
  CoreRectView__OnSetBounds( &_this->DayTwoChanceOfRain, _Const003D );
  ViewsText_OnSetAlignment( &_this->DayTwoChanceOfRain, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayTwoChanceOfRain, 0 );
  CoreRectView__OnSetBounds( &_this->DayTwoRainPerIcon, _Const003E );
  CoreRectView__OnSetBounds( &_this->DayTwoMinTemp, _Const003F );
  ViewsText_OnSetAlignment( &_this->DayTwoMinTemp, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayTwoMinTemp, 0 );
  ViewsText_OnSetColor( &_this->DayTwoMinTemp, _Const002B );
  CoreRectView__OnSetBounds( &_this->DayThreeWeather, _Const0040 );
  CoreRectView__OnSetBounds( &_this->DayThreeText, _Const0041 );
  ViewsText_OnSetAlignment( &_this->DayThreeText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayThreeText, 0 );
  CoreRectView__OnSetBounds( &_this->DayThreeChanceOfRain, _Const0042 );
  ViewsText_OnSetAlignment( &_this->DayThreeChanceOfRain, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayThreeChanceOfRain, 0 );
  CoreRectView__OnSetBounds( &_this->DayThreeRainPerIcon, _Const0043 );
  CoreRectView__OnSetBounds( &_this->DayThreeMinTemp, _Const0044 );
  ViewsText_OnSetAlignment( &_this->DayThreeMinTemp, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayThreeMinTemp, 0 );
  ViewsText_OnSetColor( &_this->DayThreeMinTemp, _Const002B );
  CoreRectView__OnSetBounds( &_this->WeatherLineUp, _Const0045 );
  CoreRectView__OnSetBounds( &_this->WeatherLineDown, _Const0008 );
  CoreRectView__OnSetBounds( &_this->DayFourWeather, _Const0046 );
  CoreRectView__OnSetBounds( &_this->DayFiveWeather, _Const0047 );
  CoreRectView__OnSetBounds( &_this->DaySixWeather, _Const0048 );
  CoreRectView__OnSetBounds( &_this->DayFourText, _Const0049 );
  ViewsText_OnSetAlignment( &_this->DayFourText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayFourText, 0 );
  CoreRectView__OnSetBounds( &_this->DayFiveText, _Const004A );
  ViewsText_OnSetAlignment( &_this->DayFiveText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayFiveText, 0 );
  CoreRectView__OnSetBounds( &_this->DaySixText, _Const004B );
  ViewsText_OnSetAlignment( &_this->DaySixText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DaySixText, 0 );
  CoreLineView_OnSetPoint2((CoreLineView)&_this->DivideLineDownLeft, _Const0009 );
  CoreLineView_OnSetPoint1((CoreLineView)&_this->DivideLineDownLeft, _Const000A );
  ViewsLine_OnSetWidth( &_this->DivideLineDownLeft, 2 );
  ViewsLine_OnSetColor( &_this->DivideLineDownLeft, _Const000B );
  CoreLineView_OnSetPoint2((CoreLineView)&_this->DivideLineDownRight, _Const000C );
  CoreLineView_OnSetPoint1((CoreLineView)&_this->DivideLineDownRight, _Const000D );
  ViewsLine_OnSetWidth( &_this->DivideLineDownRight, 2 );
  ViewsLine_OnSetColor( &_this->DivideLineDownRight, _Const000B );
  CoreRectView__OnSetBounds( &_this->DayFourChanceOfRain, _Const0017 );
  ViewsText_OnSetAlignment( &_this->DayFourChanceOfRain, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayFourChanceOfRain, 0 );
  CoreRectView__OnSetBounds( &_this->DayFiveChanceOfRain, _Const0018 );
  ViewsText_OnSetAlignment( &_this->DayFiveChanceOfRain, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayFiveChanceOfRain, 0 );
  CoreRectView__OnSetBounds( &_this->DaySixChanceOfRain, _Const0019 );
  ViewsText_OnSetAlignment( &_this->DaySixChanceOfRain, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DaySixChanceOfRain, 0 );
  CoreRectView__OnSetBounds( &_this->DayFourRainPerIcon, _Const001A );
  CoreRectView__OnSetBounds( &_this->DayFiveRainPerIcon, _Const001B );
  CoreRectView__OnSetBounds( &_this->DaySixRainPerIcon, _Const001C );
  CoreRectView__OnSetBounds( &_this->DayFourMinTemp, _Const004C );
  ViewsText_OnSetAlignment( &_this->DayFourMinTemp, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayFourMinTemp, 0 );
  ViewsText_OnSetColor( &_this->DayFourMinTemp, _Const002B );
  CoreRectView__OnSetBounds( &_this->DayFiveMinTemp, _Const004D );
  ViewsText_OnSetAlignment( &_this->DayFiveMinTemp, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayFiveMinTemp, 0 );
  ViewsText_OnSetColor( &_this->DayFiveMinTemp, _Const002B );
  CoreRectView__OnSetBounds( &_this->DaySixMinTemp, _Const004E );
  ViewsText_OnSetAlignment( &_this->DaySixMinTemp, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DaySixMinTemp, 0 );
  ViewsText_OnSetColor( &_this->DaySixMinTemp, _Const002B );
  CoreRectView__OnSetBounds( &_this->DayOneTempUnit, _Const004F );
  CoreRectView__OnSetBounds( &_this->DayTwoTempUnit, _Const0050 );
  CoreRectView__OnSetBounds( &_this->DayThreeTempUnit, _Const0051 );
  CoreRectView__OnSetBounds( &_this->DayFourTempUnit, _Const0020 );
  CoreRectView__OnSetBounds( &_this->DayFiveTempUnit, _Const0021 );
  CoreRectView__OnSetBounds( &_this->DaySixTempUnit, _Const0022 );
  _this->WeaItemIdxArray[ 0 ] = EnumWeatherTimeTypeWEATHER_AFTER_1DAY;
  _this->WeaItemIdxArray[ 1 ] = EnumWeatherTimeTypeWEATHER_AFTER_2DAY;
  _this->WeaItemIdxArray[ 2 ] = EnumWeatherTimeTypeWEATHER_AFTER_3DAY;
  _this->WeaItemIdxArray[ 3 ] = EnumWeatherTimeTypeWEATHER_AFTER_4DAY;
  _this->WeaItemIdxArray[ 4 ] = EnumWeatherTimeTypeWEATHER_AFTER_5DAY;
  _this->WeaItemIdxArray[ 5 ] = EnumWeatherTimeTypeWEATHER_AFTER_6DAY;
  CoreRectView__OnSetBounds( &_this->DayOneTempSlash, _Const0052 );
  ViewsText_OnSetAlignment( &_this->DayOneTempSlash, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayOneTempSlash, EwLoadString( &_Const002D ));
  ViewsText_OnSetColor( &_this->DayOneTempSlash, _Const0006 );
  CoreRectView__OnSetBounds( &_this->DayOneMaxTemp, _Const0053 );
  ViewsText_OnSetAlignment( &_this->DayOneMaxTemp, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayOneMaxTemp, 0 );
  ViewsText_OnSetColor( &_this->DayOneMaxTemp, _Const002F );
  CoreRectView__OnSetBounds( &_this->DayTwoTempSlash, _Const0054 );
  ViewsText_OnSetAlignment( &_this->DayTwoTempSlash, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayTwoTempSlash, EwLoadString( &_Const002D ));
  ViewsText_OnSetColor( &_this->DayTwoTempSlash, _Const0006 );
  CoreRectView__OnSetBounds( &_this->DayTwoMaxTemp, _Const0055 );
  ViewsText_OnSetAlignment( &_this->DayTwoMaxTemp, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayTwoMaxTemp, 0 );
  ViewsText_OnSetColor( &_this->DayTwoMaxTemp, _Const002F );
  CoreRectView__OnSetBounds( &_this->DayThreeTempSlash, _Const0056 );
  ViewsText_OnSetAlignment( &_this->DayThreeTempSlash, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayThreeTempSlash, EwLoadString( &_Const002D ));
  ViewsText_OnSetColor( &_this->DayThreeTempSlash, _Const0006 );
  CoreRectView__OnSetBounds( &_this->DayThreeMaxTemp, _Const0057 );
  ViewsText_OnSetAlignment( &_this->DayThreeMaxTemp, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayThreeMaxTemp, 0 );
  ViewsText_OnSetColor( &_this->DayThreeMaxTemp, _Const002F );
  CoreRectView__OnSetBounds( &_this->DayFourTempSlash, _Const0058 );
  ViewsText_OnSetAlignment( &_this->DayFourTempSlash, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayFourTempSlash, EwLoadString( &_Const002D ));
  ViewsText_OnSetColor( &_this->DayFourTempSlash, _Const0006 );
  CoreRectView__OnSetBounds( &_this->DayFourMaxTemp, _Const001D );
  ViewsText_OnSetAlignment( &_this->DayFourMaxTemp, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayFourMaxTemp, 0 );
  ViewsText_OnSetColor( &_this->DayFourMaxTemp, _Const002F );
  CoreRectView__OnSetBounds( &_this->DayFiveTempSlash, _Const0059 );
  ViewsText_OnSetAlignment( &_this->DayFiveTempSlash, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayFiveTempSlash, EwLoadString( &_Const002D ));
  ViewsText_OnSetColor( &_this->DayFiveTempSlash, _Const0006 );
  CoreRectView__OnSetBounds( &_this->DayFiveMaxTemp, _Const001E );
  ViewsText_OnSetAlignment( &_this->DayFiveMaxTemp, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayFiveMaxTemp, 0 );
  ViewsText_OnSetColor( &_this->DayFiveMaxTemp, _Const002F );
  CoreRectView__OnSetBounds( &_this->DaySixTempSlash, _Const005A );
  ViewsText_OnSetAlignment( &_this->DaySixTempSlash, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DaySixTempSlash, EwLoadString( &_Const002D ));
  ViewsText_OnSetColor( &_this->DaySixTempSlash, _Const0006 );
  CoreRectView__OnSetBounds( &_this->DaySixMaxTemp, _Const001F );
  ViewsText_OnSetAlignment( &_this->DaySixMaxTemp, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DaySixMaxTemp, 0 );
  ViewsText_OnSetColor( &_this->DaySixMaxTemp, _Const002F );
  _this->TempSlashBounds[ 0 ] = _Const0052;
  _this->TempSlashBounds[ 1 ] = _Const0054;
  _this->TempSlashBounds[ 2 ] = _Const0056;
  _this->TempSlashBounds[ 3 ] = _Const0058;
  _this->TempSlashBounds[ 4 ] = _Const0059;
  _this->TempSlashBounds[ 5 ] = _Const005A;
  _this->MinTempBounds[ 0 ] = _Const0035;
  _this->MinTempBounds[ 1 ] = _Const003F;
  _this->MinTempBounds[ 2 ] = _Const0044;
  _this->MinTempBounds[ 3 ] = _Const004C;
  _this->MinTempBounds[ 4 ] = _Const004D;
  _this->MinTempBounds[ 5 ] = _Const004E;
  _this->WeekDayTextArray[ 0 ] = EwShareString( EwLoadString( &_Const0023 ));
  _this->WeekDayTextArray[ 1 ] = EwShareString( EwLoadString( &_Const0024 ));
  _this->WeekDayTextArray[ 2 ] = EwShareString( EwLoadString( &_Const0025 ));
  _this->WeekDayTextArray[ 3 ] = EwShareString( EwLoadString( &_Const0026 ));
  _this->WeekDayTextArray[ 4 ] = EwShareString( EwLoadString( &_Const0027 ));
  _this->WeekDayTextArray[ 5 ] = EwShareString( EwLoadString( &_Const0028 ));
  _this->WeekDayTextArray[ 6 ] = EwShareString( EwLoadString( &_Const0029 ));
  CoreGroup__Add( _this, ((CoreView)&_this->DayOneWeather ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayOneText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayOneChanceOfRain ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayOneMinTemp ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DivideLineUpLeft ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DivideLineUpRight ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayTwoWeather ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayOneRainPerIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayTwoText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayTwoChanceOfRain ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayTwoRainPerIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayTwoMinTemp ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayThreeWeather ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayThreeText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayThreeChanceOfRain ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayThreeRainPerIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayThreeMinTemp ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->WeatherLineUp ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->WeatherLineDown ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayFourWeather ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayFiveWeather ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DaySixWeather ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayFourText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayFiveText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DaySixText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DivideLineDownLeft ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DivideLineDownRight ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayFourChanceOfRain ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayFiveChanceOfRain ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DaySixChanceOfRain ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayFourRainPerIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayFiveRainPerIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DaySixRainPerIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayFourMinTemp ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayFiveMinTemp ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DaySixMinTemp ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayOneTempUnit ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayTwoTempUnit ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayThreeTempUnit ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayFourTempUnit ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayFiveTempUnit ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DaySixTempUnit ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayOneTempSlash ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayOneMaxTemp ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayTwoTempSlash ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayTwoMaxTemp ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayThreeTempSlash ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayThreeMaxTemp ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayFourTempSlash ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayFourMaxTemp ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayFiveTempSlash ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayFiveMaxTemp ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DaySixTempSlash ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DaySixMaxTemp ), 0 );
  ViewsImage_OnSetBitmap( &_this->DayOneWeather, EwLoadResource( &ResourceForecastWeatherIcon, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->DayOneText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayOneChanceOfRain, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayOneMinTemp, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->DayTwoWeather, EwLoadResource( &ResourceForecastWeatherIcon, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->DayOneRainPerIcon, EwLoadResource( &ResourceIconWeatherPercentage, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->DayTwoText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayTwoChanceOfRain, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->DayTwoRainPerIcon, EwLoadResource( &ResourceIconWeatherPercentage, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->DayTwoMinTemp, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->DayThreeWeather, EwLoadResource( &ResourceForecastWeatherIcon, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->DayThreeText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayThreeChanceOfRain, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->DayThreeRainPerIcon, EwLoadResource( &ResourceIconWeatherPercentage, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->DayThreeMinTemp, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->WeatherLineUp, EwLoadResource( &ResourceWeatherLine, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->WeatherLineDown, EwLoadResource( &ResourceWeatherLine, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->DayFourWeather, EwLoadResource( &ResourceForecastWeatherIcon, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->DayFiveWeather, EwLoadResource( &ResourceForecastWeatherIcon, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->DaySixWeather, EwLoadResource( &ResourceForecastWeatherIcon, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->DayFourText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayFiveText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DaySixText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayFourChanceOfRain, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayFiveChanceOfRain, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DaySixChanceOfRain, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->DayFourRainPerIcon, EwLoadResource( &ResourceIconWeatherPercentage, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->DayFiveRainPerIcon, EwLoadResource( &ResourceIconWeatherPercentage, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->DaySixRainPerIcon, EwLoadResource( &ResourceIconWeatherPercentage, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->DayFourMinTemp, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayFiveMinTemp, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DaySixMinTemp, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->DayOneTempUnit, EwLoadResource( &ResourceIconTempDeg, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->DayTwoTempUnit, EwLoadResource( &ResourceIconTempDeg, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->DayThreeTempUnit, EwLoadResource( &ResourceIconTempDeg, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->DayFourTempUnit, EwLoadResource( &ResourceIconTempDeg, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->DayFiveTempUnit, EwLoadResource( &ResourceIconTempDeg, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->DaySixTempUnit, EwLoadResource( &ResourceIconTempDeg, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->DayOneTempSlash, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayOneMaxTemp, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayTwoTempSlash, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayTwoMaxTemp, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayThreeTempSlash, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayThreeMaxTemp, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayFourTempSlash, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayFourMaxTemp, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayFiveTempSlash, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayFiveMaxTemp, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DaySixTempSlash, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DaySixMaxTemp, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->DayTextViewArray[ 0 ] = &_this->DayOneText;
  _this->DayTextViewArray[ 1 ] = &_this->DayTwoText;
  _this->DayTextViewArray[ 2 ] = &_this->DayThreeText;
  _this->DayTextViewArray[ 3 ] = &_this->DayFourText;
  _this->DayTextViewArray[ 4 ] = &_this->DayFiveText;
  _this->DayTextViewArray[ 5 ] = &_this->DaySixText;

  /* Call the user defined constructor */
  WeatherWeatherWeekViewUI_Init( _this, aArg );
}

/* Re-Initializer for the class 'Weather::WeatherWeekViewUI' */
void WeatherWeatherWeekViewUI__ReInit( WeatherWeatherWeekViewUI _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->DayOneWeather );
  ViewsText__ReInit( &_this->DayOneText );
  ViewsText__ReInit( &_this->DayOneChanceOfRain );
  ViewsText__ReInit( &_this->DayOneMinTemp );
  ViewsLine__ReInit( &_this->DivideLineUpLeft );
  ViewsLine__ReInit( &_this->DivideLineUpRight );
  ViewsImage__ReInit( &_this->DayTwoWeather );
  ViewsImage__ReInit( &_this->DayOneRainPerIcon );
  ViewsText__ReInit( &_this->DayTwoText );
  ViewsText__ReInit( &_this->DayTwoChanceOfRain );
  ViewsImage__ReInit( &_this->DayTwoRainPerIcon );
  ViewsText__ReInit( &_this->DayTwoMinTemp );
  ViewsImage__ReInit( &_this->DayThreeWeather );
  ViewsText__ReInit( &_this->DayThreeText );
  ViewsText__ReInit( &_this->DayThreeChanceOfRain );
  ViewsImage__ReInit( &_this->DayThreeRainPerIcon );
  ViewsText__ReInit( &_this->DayThreeMinTemp );
  ViewsImage__ReInit( &_this->WeatherLineUp );
  ViewsImage__ReInit( &_this->WeatherLineDown );
  ViewsImage__ReInit( &_this->DayFourWeather );
  ViewsImage__ReInit( &_this->DayFiveWeather );
  ViewsImage__ReInit( &_this->DaySixWeather );
  ViewsText__ReInit( &_this->DayFourText );
  ViewsText__ReInit( &_this->DayFiveText );
  ViewsText__ReInit( &_this->DaySixText );
  ViewsLine__ReInit( &_this->DivideLineDownLeft );
  ViewsLine__ReInit( &_this->DivideLineDownRight );
  ViewsText__ReInit( &_this->DayFourChanceOfRain );
  ViewsText__ReInit( &_this->DayFiveChanceOfRain );
  ViewsText__ReInit( &_this->DaySixChanceOfRain );
  ViewsImage__ReInit( &_this->DayFourRainPerIcon );
  ViewsImage__ReInit( &_this->DayFiveRainPerIcon );
  ViewsImage__ReInit( &_this->DaySixRainPerIcon );
  ViewsText__ReInit( &_this->DayFourMinTemp );
  ViewsText__ReInit( &_this->DayFiveMinTemp );
  ViewsText__ReInit( &_this->DaySixMinTemp );
  ViewsImage__ReInit( &_this->DayOneTempUnit );
  ViewsImage__ReInit( &_this->DayTwoTempUnit );
  ViewsImage__ReInit( &_this->DayThreeTempUnit );
  ViewsImage__ReInit( &_this->DayFourTempUnit );
  ViewsImage__ReInit( &_this->DayFiveTempUnit );
  ViewsImage__ReInit( &_this->DaySixTempUnit );
  ViewsText__ReInit( &_this->DayOneTempSlash );
  ViewsText__ReInit( &_this->DayOneMaxTemp );
  ViewsText__ReInit( &_this->DayTwoTempSlash );
  ViewsText__ReInit( &_this->DayTwoMaxTemp );
  ViewsText__ReInit( &_this->DayThreeTempSlash );
  ViewsText__ReInit( &_this->DayThreeMaxTemp );
  ViewsText__ReInit( &_this->DayFourTempSlash );
  ViewsText__ReInit( &_this->DayFourMaxTemp );
  ViewsText__ReInit( &_this->DayFiveTempSlash );
  ViewsText__ReInit( &_this->DayFiveMaxTemp );
  ViewsText__ReInit( &_this->DaySixTempSlash );
  ViewsText__ReInit( &_this->DaySixMaxTemp );
}

/* Finalizer method for the class 'Weather::WeatherWeekViewUI' */
void WeatherWeatherWeekViewUI__Done( WeatherWeatherWeekViewUI _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->DayOneWeather );
  ViewsText__Done( &_this->DayOneText );
  ViewsText__Done( &_this->DayOneChanceOfRain );
  ViewsText__Done( &_this->DayOneMinTemp );
  ViewsLine__Done( &_this->DivideLineUpLeft );
  ViewsLine__Done( &_this->DivideLineUpRight );
  ViewsImage__Done( &_this->DayTwoWeather );
  ViewsImage__Done( &_this->DayOneRainPerIcon );
  ViewsText__Done( &_this->DayTwoText );
  ViewsText__Done( &_this->DayTwoChanceOfRain );
  ViewsImage__Done( &_this->DayTwoRainPerIcon );
  ViewsText__Done( &_this->DayTwoMinTemp );
  ViewsImage__Done( &_this->DayThreeWeather );
  ViewsText__Done( &_this->DayThreeText );
  ViewsText__Done( &_this->DayThreeChanceOfRain );
  ViewsImage__Done( &_this->DayThreeRainPerIcon );
  ViewsText__Done( &_this->DayThreeMinTemp );
  ViewsImage__Done( &_this->WeatherLineUp );
  ViewsImage__Done( &_this->WeatherLineDown );
  ViewsImage__Done( &_this->DayFourWeather );
  ViewsImage__Done( &_this->DayFiveWeather );
  ViewsImage__Done( &_this->DaySixWeather );
  ViewsText__Done( &_this->DayFourText );
  ViewsText__Done( &_this->DayFiveText );
  ViewsText__Done( &_this->DaySixText );
  ViewsLine__Done( &_this->DivideLineDownLeft );
  ViewsLine__Done( &_this->DivideLineDownRight );
  ViewsText__Done( &_this->DayFourChanceOfRain );
  ViewsText__Done( &_this->DayFiveChanceOfRain );
  ViewsText__Done( &_this->DaySixChanceOfRain );
  ViewsImage__Done( &_this->DayFourRainPerIcon );
  ViewsImage__Done( &_this->DayFiveRainPerIcon );
  ViewsImage__Done( &_this->DaySixRainPerIcon );
  ViewsText__Done( &_this->DayFourMinTemp );
  ViewsText__Done( &_this->DayFiveMinTemp );
  ViewsText__Done( &_this->DaySixMinTemp );
  ViewsImage__Done( &_this->DayOneTempUnit );
  ViewsImage__Done( &_this->DayTwoTempUnit );
  ViewsImage__Done( &_this->DayThreeTempUnit );
  ViewsImage__Done( &_this->DayFourTempUnit );
  ViewsImage__Done( &_this->DayFiveTempUnit );
  ViewsImage__Done( &_this->DaySixTempUnit );
  ViewsText__Done( &_this->DayOneTempSlash );
  ViewsText__Done( &_this->DayOneMaxTemp );
  ViewsText__Done( &_this->DayTwoTempSlash );
  ViewsText__Done( &_this->DayTwoMaxTemp );
  ViewsText__Done( &_this->DayThreeTempSlash );
  ViewsText__Done( &_this->DayThreeMaxTemp );
  ViewsText__Done( &_this->DayFourTempSlash );
  ViewsText__Done( &_this->DayFourMaxTemp );
  ViewsText__Done( &_this->DayFiveTempSlash );
  ViewsText__Done( &_this->DayFiveMaxTemp );
  ViewsText__Done( &_this->DaySixTempSlash );
  ViewsText__Done( &_this->DaySixMaxTemp );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void WeatherWeatherWeekViewUI_Init( WeatherWeatherWeekViewUI _this, XHandle aArg )
{
  XInt32 i;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const005B ));

  for ( i = 0; i < 6; i++ )
  {
    DeviceInterfaceWeatherDeviceClass_GetWeatherInfo( EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
    DeviceInterfaceWeatherDeviceClass ), _this->WeaItemIdxArray[ EwCheckIndex( i, 
    6 )]);
    EwSignal( EwNewSlot( _this, WeatherWeatherWeekViewUI_OnWeatherInfoUpdateSlot ), 
      ((XObject)_this ));
  }

  DeviceInterfaceWeatherDeviceClass_GetWeekDay( EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
  DeviceInterfaceWeatherDeviceClass ));
  EwSignal( EwNewSlot( _this, WeatherWeatherWeekViewUI_OnWeekDayUpdateSlot ), ((XObject)_this ));
  DeviceInterfaceWeatherDeviceClass_OnSetIsWeatherInfoReceived( EwGetAutoObject( 
  &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass ), 0 );
}

/* 'C' function for method : 'Weather::WeatherWeekViewUI.OnWeatherInfoUpdateSlot()' */
void WeatherWeatherWeekViewUI_OnWeatherInfoUpdateSlot( WeatherWeatherWeekViewUI _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->IsWeatherInfoReceived )
  {
    XEnum WeatherTime = (XEnum)EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->WeatherTime;

    switch ( WeatherTime )
    {
      case EnumWeatherTimeTypeWEATHER_AFTER_1DAY :
      {
        XInt32 TempShiftPixel;
        XRect NewSlashBounds;
        XRect NewMinBounds;
        CoreRectView__OnSetBounds( &_this->DayOneMinTemp, _this->MinTempBounds[ 
        EwCheckIndex( EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->WeatherTime 
        - 1, 6 )]);
        CoreRectView__OnSetBounds( &_this->DayOneTempSlash, _this->TempSlashBounds[ 
        EwCheckIndex( EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->WeatherTime 
        - 1, 6 )]);
        ViewsImage_OnSetFrameNumber( &_this->DayOneWeather, EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
        DeviceInterfaceWeatherDeviceClass )->WeatherType );
        ViewsText_OnSetString( &_this->DayOneChanceOfRain, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->RainProbability, 
        0, 10 ));
        ViewsText_OnSetString( &_this->DayOneMinTemp, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->MinTemperature, 
        0, 10 ));
        ViewsText_OnSetString( &_this->DayOneMaxTemp, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->MaxTemperature, 
        0, 10 ));
        TempShiftPixel = EwGetRectW( _this->DayOneMaxTemp.Super1.Bounds ) - EwGetRectW( 
        ViewsText_GetContentArea( &_this->DayOneMaxTemp ));
        NewSlashBounds = _this->DayOneTempSlash.Super1.Bounds;
        NewMinBounds = _this->DayOneMinTemp.Super1.Bounds;
        NewSlashBounds.Point1.X = ( _this->DayOneTempSlash.Super1.Bounds.Point1.X 
        + TempShiftPixel );
        NewSlashBounds.Point2.X = ( _this->DayOneTempSlash.Super1.Bounds.Point2.X 
        + TempShiftPixel );
        NewMinBounds.Point1.X = ( _this->DayOneMinTemp.Super1.Bounds.Point1.X + 
        TempShiftPixel );
        NewMinBounds.Point2.X = ( _this->DayOneMinTemp.Super1.Bounds.Point2.X + 
        TempShiftPixel );
        CoreRectView__OnSetBounds( &_this->DayOneTempSlash, NewSlashBounds );
        CoreRectView__OnSetBounds( &_this->DayOneMinTemp, NewMinBounds );
      }
      break;

      case EnumWeatherTimeTypeWEATHER_AFTER_2DAY :
      {
        XInt32 TempShiftPixel;
        XRect NewSlashBounds;
        XRect NewMinBounds;
        CoreRectView__OnSetBounds( &_this->DayTwoMinTemp, _this->MinTempBounds[ 
        EwCheckIndex( EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->WeatherTime 
        - 1, 6 )]);
        CoreRectView__OnSetBounds( &_this->DayTwoTempSlash, _this->TempSlashBounds[ 
        EwCheckIndex( EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->WeatherTime 
        - 1, 6 )]);
        ViewsImage_OnSetFrameNumber( &_this->DayTwoWeather, EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
        DeviceInterfaceWeatherDeviceClass )->WeatherType );
        ViewsText_OnSetString( &_this->DayTwoChanceOfRain, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->RainProbability, 
        0, 10 ));
        ViewsText_OnSetString( &_this->DayTwoMinTemp, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->MinTemperature, 
        0, 10 ));
        ViewsText_OnSetString( &_this->DayTwoMaxTemp, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->MaxTemperature, 
        0, 10 ));
        TempShiftPixel = EwGetRectW( _this->DayTwoMaxTemp.Super1.Bounds ) - EwGetRectW( 
        ViewsText_GetContentArea( &_this->DayTwoMaxTemp ));
        NewSlashBounds = _this->DayTwoTempSlash.Super1.Bounds;
        NewMinBounds = _this->DayTwoMinTemp.Super1.Bounds;
        NewSlashBounds.Point1.X = ( _this->DayTwoTempSlash.Super1.Bounds.Point1.X 
        + TempShiftPixel );
        NewSlashBounds.Point2.X = ( _this->DayTwoTempSlash.Super1.Bounds.Point2.X 
        + TempShiftPixel );
        NewMinBounds.Point1.X = ( _this->DayTwoMinTemp.Super1.Bounds.Point1.X + 
        TempShiftPixel );
        NewMinBounds.Point2.X = ( _this->DayTwoMinTemp.Super1.Bounds.Point2.X + 
        TempShiftPixel );
        CoreRectView__OnSetBounds( &_this->DayTwoTempSlash, NewSlashBounds );
        CoreRectView__OnSetBounds( &_this->DayTwoMinTemp, NewMinBounds );
      }
      break;

      case EnumWeatherTimeTypeWEATHER_AFTER_3DAY :
      {
        XInt32 TempShiftPixel;
        XRect NewSlashBounds;
        XRect NewMinBounds;
        CoreRectView__OnSetBounds( &_this->DayThreeMinTemp, _this->MinTempBounds[ 
        EwCheckIndex( EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->WeatherTime 
        - 1, 6 )]);
        CoreRectView__OnSetBounds( &_this->DayThreeTempSlash, _this->TempSlashBounds[ 
        EwCheckIndex( EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->WeatherTime 
        - 1, 6 )]);
        ViewsImage_OnSetFrameNumber( &_this->DayThreeWeather, EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
        DeviceInterfaceWeatherDeviceClass )->WeatherType );
        ViewsText_OnSetString( &_this->DayThreeChanceOfRain, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->RainProbability, 
        0, 10 ));
        ViewsText_OnSetString( &_this->DayThreeMinTemp, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->MinTemperature, 
        0, 10 ));
        ViewsText_OnSetString( &_this->DayThreeMaxTemp, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->MaxTemperature, 
        0, 10 ));
        TempShiftPixel = EwGetRectW( _this->DayThreeMaxTemp.Super1.Bounds ) - EwGetRectW( 
        ViewsText_GetContentArea( &_this->DayThreeMaxTemp ));
        NewSlashBounds = _this->DayThreeTempSlash.Super1.Bounds;
        NewMinBounds = _this->DayThreeMinTemp.Super1.Bounds;
        NewSlashBounds.Point1.X = ( _this->DayThreeTempSlash.Super1.Bounds.Point1.X 
        + TempShiftPixel );
        NewSlashBounds.Point2.X = ( _this->DayThreeTempSlash.Super1.Bounds.Point2.X 
        + TempShiftPixel );
        NewMinBounds.Point1.X = ( _this->DayThreeMinTemp.Super1.Bounds.Point1.X 
        + TempShiftPixel );
        NewMinBounds.Point2.X = ( _this->DayThreeMinTemp.Super1.Bounds.Point2.X 
        + TempShiftPixel );
        CoreRectView__OnSetBounds( &_this->DayThreeTempSlash, NewSlashBounds );
        CoreRectView__OnSetBounds( &_this->DayThreeMinTemp, NewMinBounds );
      }
      break;

      case EnumWeatherTimeTypeWEATHER_AFTER_4DAY :
      {
        XInt32 TempShiftPixel;
        XRect NewSlashBounds;
        XRect NewMinBounds;
        CoreRectView__OnSetBounds( &_this->DayFourMinTemp, _this->MinTempBounds[ 
        EwCheckIndex( EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->WeatherTime 
        - 1, 6 )]);
        CoreRectView__OnSetBounds( &_this->DayFourTempSlash, _this->TempSlashBounds[ 
        EwCheckIndex( EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->WeatherTime 
        - 1, 6 )]);
        ViewsImage_OnSetFrameNumber( &_this->DayFourWeather, EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
        DeviceInterfaceWeatherDeviceClass )->WeatherType );
        ViewsText_OnSetString( &_this->DayFourChanceOfRain, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->RainProbability, 
        0, 10 ));
        ViewsText_OnSetString( &_this->DayFourMinTemp, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->MinTemperature, 
        0, 10 ));
        ViewsText_OnSetString( &_this->DayFourMaxTemp, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->MaxTemperature, 
        0, 10 ));
        TempShiftPixel = EwGetRectW( _this->DayFourMaxTemp.Super1.Bounds ) - EwGetRectW( 
        ViewsText_GetContentArea( &_this->DayFourMaxTemp ));
        NewSlashBounds = _this->DayFourTempSlash.Super1.Bounds;
        NewMinBounds = _this->DayFourMinTemp.Super1.Bounds;
        NewSlashBounds.Point1.X = ( _this->DayFourTempSlash.Super1.Bounds.Point1.X 
        + TempShiftPixel );
        NewSlashBounds.Point2.X = ( _this->DayFourTempSlash.Super1.Bounds.Point2.X 
        + TempShiftPixel );
        NewMinBounds.Point1.X = ( _this->DayFourMinTemp.Super1.Bounds.Point1.X + 
        TempShiftPixel );
        NewMinBounds.Point2.X = ( _this->DayFourMinTemp.Super1.Bounds.Point2.X + 
        TempShiftPixel );
        CoreRectView__OnSetBounds( &_this->DayFourTempSlash, NewSlashBounds );
        CoreRectView__OnSetBounds( &_this->DayFourMinTemp, NewMinBounds );
      }
      break;

      case EnumWeatherTimeTypeWEATHER_AFTER_5DAY :
      {
        XInt32 TempShiftPixel;
        XRect NewSlashBounds;
        XRect NewMinBounds;
        CoreRectView__OnSetBounds( &_this->DayFiveMinTemp, _this->MinTempBounds[ 
        EwCheckIndex( EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->WeatherTime 
        - 1, 6 )]);
        CoreRectView__OnSetBounds( &_this->DayFiveTempSlash, _this->TempSlashBounds[ 
        EwCheckIndex( EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->WeatherTime 
        - 1, 6 )]);
        ViewsImage_OnSetFrameNumber( &_this->DayFiveWeather, EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
        DeviceInterfaceWeatherDeviceClass )->WeatherType );
        ViewsText_OnSetString( &_this->DayFiveChanceOfRain, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->RainProbability, 
        0, 10 ));
        ViewsText_OnSetString( &_this->DayFiveMinTemp, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->MinTemperature, 
        0, 10 ));
        ViewsText_OnSetString( &_this->DayFiveMaxTemp, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->MaxTemperature, 
        0, 10 ));
        TempShiftPixel = EwGetRectW( _this->DayFiveMaxTemp.Super1.Bounds ) - EwGetRectW( 
        ViewsText_GetContentArea( &_this->DayFiveMaxTemp ));
        NewSlashBounds = _this->DayFiveTempSlash.Super1.Bounds;
        NewMinBounds = _this->DayFiveMinTemp.Super1.Bounds;
        NewSlashBounds.Point1.X = ( _this->DayFiveTempSlash.Super1.Bounds.Point1.X 
        + TempShiftPixel );
        NewSlashBounds.Point2.X = ( _this->DayFiveTempSlash.Super1.Bounds.Point2.X 
        + TempShiftPixel );
        NewMinBounds.Point1.X = ( _this->DayFiveMinTemp.Super1.Bounds.Point1.X + 
        TempShiftPixel );
        NewMinBounds.Point2.X = ( _this->DayFiveMinTemp.Super1.Bounds.Point2.X + 
        TempShiftPixel );
        CoreRectView__OnSetBounds( &_this->DayFiveTempSlash, NewSlashBounds );
        CoreRectView__OnSetBounds( &_this->DayFiveMinTemp, NewMinBounds );
      }
      break;

      case EnumWeatherTimeTypeWEATHER_AFTER_6DAY :
      {
        XInt32 TempShiftPixel;
        XRect NewSlashBounds;
        XRect NewMinBounds;
        CoreRectView__OnSetBounds( &_this->DaySixMinTemp, _this->MinTempBounds[ 
        5 ]);
        CoreRectView__OnSetBounds( &_this->DaySixTempSlash, _this->TempSlashBounds[ 
        5 ]);
        ViewsImage_OnSetFrameNumber( &_this->DaySixWeather, EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
        DeviceInterfaceWeatherDeviceClass )->WeatherType );
        ViewsText_OnSetString( &_this->DaySixChanceOfRain, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->RainProbability, 
        0, 10 ));
        ViewsText_OnSetString( &_this->DaySixMinTemp, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->MinTemperature, 
        0, 10 ));
        ViewsText_OnSetString( &_this->DaySixMaxTemp, EwNewStringInt( EwGetAutoObject( 
        &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->MaxTemperature, 
        0, 10 ));
        TempShiftPixel = EwGetRectW( _this->DaySixMaxTemp.Super1.Bounds ) - EwGetRectW( 
        ViewsText_GetContentArea( &_this->DaySixMaxTemp ));
        NewSlashBounds = _this->DaySixTempSlash.Super1.Bounds;
        NewMinBounds = _this->DaySixMinTemp.Super1.Bounds;
        NewSlashBounds.Point1.X = ( _this->DaySixTempSlash.Super1.Bounds.Point1.X 
        + TempShiftPixel );
        NewSlashBounds.Point2.X = ( _this->DaySixTempSlash.Super1.Bounds.Point2.X 
        + TempShiftPixel );
        NewMinBounds.Point1.X = ( _this->DaySixMinTemp.Super1.Bounds.Point1.X + 
        TempShiftPixel );
        NewMinBounds.Point2.X = ( _this->DaySixMinTemp.Super1.Bounds.Point2.X + 
        TempShiftPixel );
        CoreRectView__OnSetBounds( &_this->DaySixTempSlash, NewSlashBounds );
        CoreRectView__OnSetBounds( &_this->DaySixMinTemp, NewMinBounds );
      }
      break;

      default : 
        ;
    }
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void WeatherWeatherWeekViewUI_OnWeekDayUpdateSlot( WeatherWeatherWeekViewUI _this, 
  XObject sender )
{
  XInt32 i;
  XInt32 idx;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  idx = 0;

  for ( i = EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->WeekDay 
       + 1; i < ( EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->WeekDay 
       + 7 ); i++ )
  {
    ViewsText_OnSetString( _this->DayTextViewArray[ EwCheckIndex( idx, 6 )], _this->WeekDayTextArray[ 
    EwCheckIndex( i % 7, 7 )]);
    idx++;
  }
}

/* Variants derived from the class : 'Weather::WeatherWeekViewUI' */
EW_DEFINE_CLASS_VARIANTS( WeatherWeatherWeekViewUI )
EW_END_OF_CLASS_VARIANTS( WeatherWeatherWeekViewUI )

/* Virtual Method Table (VMT) for the class : 'Weather::WeatherWeekViewUI' */
EW_DEFINE_CLASS( WeatherWeatherWeekViewUI, CoreGroup, DayTextViewArray, DayOneWeather, 
                 DayOneWeather, DayOneWeather, WeekDayTextArray, TempSlashBounds, 
                 "Weather::WeatherWeekViewUI" )
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
EW_END_OF_CLASS( WeatherWeatherWeekViewUI )

/* Initializer for the class 'Weather::WeatherList' */
void WeatherWeatherList__Init( WeatherWeatherList _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( WeatherWeatherList );

  /* ... then construct all embedded objects */
  CoreVerticalList__Init( &_this->VerticalList, &_this->_XObject, 0 );
  MenuArrowScrollBar__Init( &_this->ArrowScrollBar, &_this->_XObject, 0 );
  EffectsInt32Effect__Init( &_this->PageScrollEffect, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( WeatherWeatherList );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const005C );
  CoreRectView__OnSetBounds( &_this->VerticalList, _Const005D );
  CoreVerticalList_OnSetSelectedItem( &_this->VerticalList, 0 );
  CoreVerticalList_OnSetItemHeight( &_this->VerticalList, 224 );
  CoreVerticalList_OnSetNoOfItems( &_this->VerticalList, 2 );
  CoreVerticalList_OnSetItemClass( &_this->VerticalList, EW_CLASS( WeatherWeatherItemWrapper ));
  CoreRectView__OnSetBounds( &_this->ArrowScrollBar, _Const005E );
  CoreGroup__OnSetVisible( &_this->ArrowScrollBar, 1 );
  MenuArrowScrollBar_OnSetNoOfPages( &_this->ArrowScrollBar, 2 );
  EffectsEffect_OnSetExponent((EffectsEffect)&_this->PageScrollEffect, 4.190000f );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->PageScrollEffect, EffectsTimingExp_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->PageScrollEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->PageScrollEffect, 200 );
  EffectsEffect_OnSetInitialDelay((EffectsEffect)&_this->PageScrollEffect, 50 );
  CoreGroup__Add( _this, ((CoreView)&_this->VerticalList ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ArrowScrollBar ), 0 );
  _this->VerticalList.OnLoadItem = EwNewSlot( _this, WeatherWeatherList_OnLoadItem );
  _this->PageScrollEffect.Super1.OnFinished = EwNewSlot( _this, WeatherWeatherList_OnPageScrolledSlot );
  _this->PageScrollEffect.Outlet = EwNewRef( &_this->VerticalList, CoreVerticalList_OnGetScrollOffset, 
  CoreVerticalList_OnSetScrollOffset );
}

/* Re-Initializer for the class 'Weather::WeatherList' */
void WeatherWeatherList__ReInit( WeatherWeatherList _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreVerticalList__ReInit( &_this->VerticalList );
  MenuArrowScrollBar__ReInit( &_this->ArrowScrollBar );
  EffectsInt32Effect__ReInit( &_this->PageScrollEffect );
}

/* Finalizer method for the class 'Weather::WeatherList' */
void WeatherWeatherList__Done( WeatherWeatherList _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  CoreVerticalList__Done( &_this->VerticalList );
  MenuArrowScrollBar__Done( &_this->ArrowScrollBar );
  EffectsInt32Effect__Done( &_this->PageScrollEffect );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* 'C' function for method : 'Weather::WeatherList.OnShortDownKeyActivated()' */
void WeatherWeatherList_OnShortDownKeyActivated( WeatherWeatherList _this )
{
  XInt32 NextItemIdx = _this->VerticalList.SelectedItem + 1;

  if ( NextItemIdx < _this->VerticalList.NoOfItems )
  {
    CoreVerticalList_OnSetSelectedItem( &_this->VerticalList, NextItemIdx );
    _this->PageScrollEffect.Value1 = _this->VerticalList.ScrollOffset;
    _this->PageScrollEffect.Value2 = -1 * EwGetRectH( _this->VerticalList.Super2.Bounds );
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->PageScrollEffect, 1 );
  }
}

/* 'C' function for method : 'Weather::WeatherList.OnShortUpKeyActivated()' */
void WeatherWeatherList_OnShortUpKeyActivated( WeatherWeatherList _this )
{
  XInt32 PrevItemIdx = _this->VerticalList.SelectedItem - 1;

  if ( PrevItemIdx >= 0 )
  {
    CoreVerticalList_OnSetSelectedItem( &_this->VerticalList, PrevItemIdx );
    _this->PageScrollEffect.Value1 = _this->VerticalList.ScrollOffset;
    _this->PageScrollEffect.Value2 = 0;
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->PageScrollEffect, 1 );
  }
}

/* This method is called by 'VerticalList' every time the list loads or updates 
   an item. */
void WeatherWeatherList_OnLoadItem( WeatherWeatherList _this, XObject sender )
{
  XInt32 itemNo;
  WeatherWeatherItemWrapper item;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  itemNo = _this->VerticalList.Item;
  item = EwCastObject( _this->VerticalList.View, WeatherWeatherItemWrapper );

  if ( item != 0 )
  {
    item->ItemIdx = itemNo;

    switch ( itemNo )
    {
      case 0 :
        WeatherWeatherItemWrapper_OnSetItemClass( item, EW_CLASS( WeatherWeatherDayViewUI ));
      break;

      case 1 :
        WeatherWeatherItemWrapper_OnSetItemClass( item, EW_CLASS( WeatherWeatherWeekViewUI ));
      break;

      default : 
        ;
    }

    CoreRectView__OnSetBounds( item, EwSetRectSize( item->Super2.Bounds, EwNewPoint( 
    EwGetRectW( _this->VerticalList.Super2.Bounds ), _this->VerticalList.ItemHeight )));
  }
}

/* 'C' function for method : 'Weather::WeatherList.OnPageScrolledSlot()' */
void WeatherWeatherList_OnPageScrolledSlot( WeatherWeatherList _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  MenuArrowScrollBar_OnSetCurrentPageIdx( &_this->ArrowScrollBar, _this->VerticalList.SelectedItem );
}

/* Variants derived from the class : 'Weather::WeatherList' */
EW_DEFINE_CLASS_VARIANTS( WeatherWeatherList )
EW_END_OF_CLASS_VARIANTS( WeatherWeatherList )

/* Virtual Method Table (VMT) for the class : 'Weather::WeatherList' */
EW_DEFINE_CLASS( WeatherWeatherList, ComponentsBaseComponent, VerticalList, VerticalList, 
                 VerticalList, VerticalList, _None, _None, "Weather::WeatherList" )
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
  WeatherWeatherList_OnShortDownKeyActivated,
  WeatherWeatherList_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( WeatherWeatherList )

/* Initializer for the class 'Weather::WeatherItemWrapper' */
void WeatherWeatherItemWrapper__Init( WeatherWeatherItemWrapper _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( WeatherWeatherItemWrapper );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( WeatherWeatherItemWrapper );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const005F );
}

/* Re-Initializer for the class 'Weather::WeatherItemWrapper' */
void WeatherWeatherItemWrapper__ReInit( WeatherWeatherItemWrapper _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Weather::WeatherItemWrapper' */
void WeatherWeatherItemWrapper__Done( WeatherWeatherItemWrapper _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* 'C' function for method : 'Weather::WeatherItemWrapper.OnSetItemClass()' */
void WeatherWeatherItemWrapper_OnSetItemClass( WeatherWeatherItemWrapper _this, 
  XClass value )
{
  if ( _this->ItemClass != value )
  {
    _this->ItemClass = value;

    if ( CoreGroup__CountViews( _this ) > 0 )
    {
      CoreGroup__Remove( _this, CoreGroup__FindNextView( _this, 0, 0 ));
    }

    switch ( _this->ItemIdx )
    {
      case 0 :
      {
        WeatherWeatherDayViewUI Item = EwCastObject( EwNewObjectIndirect( value, 
          0 ), WeatherWeatherDayViewUI );
        CoreGroup__Add( _this, ((CoreView)Item ), 0 );
      }
      break;

      case 1 :
      {
        WeatherWeatherWeekViewUI Item = EwCastObject( EwNewObjectIndirect( value, 
          0 ), WeatherWeatherWeekViewUI );
        CoreGroup__Add( _this, ((CoreView)Item ), 0 );
      }
      break;

      default : 
        ;
    }
  }
}

/* Variants derived from the class : 'Weather::WeatherItemWrapper' */
EW_DEFINE_CLASS_VARIANTS( WeatherWeatherItemWrapper )
EW_END_OF_CLASS_VARIANTS( WeatherWeatherItemWrapper )

/* Virtual Method Table (VMT) for the class : 'Weather::WeatherItemWrapper' */
EW_DEFINE_CLASS( WeatherWeatherItemWrapper, CoreGroup, _None, _None, _None, _None, 
                 _None, _None, "Weather::WeatherItemWrapper" )
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
EW_END_OF_CLASS( WeatherWeatherItemWrapper )

/* Embedded Wizard */
