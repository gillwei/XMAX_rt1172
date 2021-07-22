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
#include "_CoreGroup.h"
#include "_CoreKeyPressHandler.h"
#include "_CoreRoot.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreVerticalList.h"
#include "_CoreView.h"
#include "_DeviceInterfaceNaviDataClass.h"
#include "_DeviceInterfaceNavigationDeviceClass.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_DeviceInterfaceVehicleDataClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_EffectsInt32Effect.h"
#include "_EffectsRectEffect.h"
#include "_HomeBaseHome.h"
#include "_HomeEcoMeterChart.h"
#include "_HomeEcoMeterComponent.h"
#include "_HomeHOM03_VehicleInfo.h"
#include "_HomeHOM11_TachoVisualizer.h"
#include "_HomeHOM12_EcoVisualizer.h"
#include "_HomeHOM13_SpeedVisualizer.h"
#include "_HomeItemVehicleInfo.h"
#include "_HomeRecord.h"
#include "_HomeRecordList.h"
#include "_HomeSpeedCircle.h"
#include "_HomeTachoBaseline.h"
#include "_HomeTachoColor.h"
#include "_HomeTachoScale.h"
#include "_HomeVehicleInfoMenu.h"
#include "_InfoINF01_MeterDisplaySettingMenu.h"
#include "_LauncherLNC_Main.h"
#include "_MenuBaseMenuView.h"
#include "_PopPOP02_ConnectionError.h"
#include "_PopPOP16_NaviLoadingUI.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesExternBitmap.h"
#include "_ResourcesFont.h"
#include "_SettingsSET46_VehicleInfoReset.h"
#include "_ViewsFrame.h"
#include "_ViewsImage.h"
#include "_ViewsLine.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "_ViewsWallpaper.h"
#include "_ViewsWarpImage.h"
#include "Color.h"
#include "Core.h"
#include "DeviceInterface.h"
#include "Effects.h"
#include "Enum.h"
#include "Fonts.h"
#include "Home.h"
#include "Resource.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault0[] =
{
  0x000000C2, /* ratio 74.23 % */
  0xB8001700, 0x00082452, 0x008E002B, 0x08C00100, 0x8A002A80, 0xA0026000, 0x45818222,
  0x02780090, 0x188009A0, 0x04546400, 0x126300D0, 0xA4006E00, 0x21674001, 0x3D1C8D00,
  0xD2319C82, 0x2E16C600, 0x08C45A71, 0x180023B3, 0x84566800, 0x00251260, 0x00C2003B,
  0x0012A360, 0x532B9719, 0x00032D3E, 0x180CC8CF, 0xAAA000E5, 0x34000C74, 0xAD24DB2E,
  0x1D6C54DA, 0x7A196200, 0xAC670A55, 0xF32D95D7, 0xB048BC8C, 0x238FCCA7, 0x000406F3,
  0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 61, 44 }, { 417, 200 }};
static const XRect _Const0001 = {{ 61, 44 }, { 435, 200 }};
static const XRect _Const0002 = {{ 417, 44 }, { 435, 184 }};
static const XColor _Const0003 = { 0x07, 0x07, 0x07, 0xFF };
static const XRect _Const0004 = {{ 43, 44 }, { 61, 184 }};
static const XRect _Const0005 = {{ 55, 61 }, { 412, 189 }};
static const XRect _Const0006 = {{ 85, 212 }, { 194, 242 }};
static const XStringRes _Const0007 = { _StringsDefault0, 0x0002 };
static const XRect _Const0008 = {{ 205, 196 }, { 328, 253 }};
static const XRect _Const0009 = {{ 333, 205 }, { 393, 247 }};
static const XRect _Const000A = {{ 52, 244 }, { 428, 259 }};
static const XRect _Const000B = {{ 0, 102 }, { 480, 129 }};
static const XRect _Const000C = {{ 50, 45 }, { 419, 184 }};
static const XRect _Const000D = {{ 56, 45 }, { 425, 184 }};
static const XStringRes _Const000E = { _StringsDefault0, 0x000D };
static const XRect _Const000F = {{ 0, 38 }, { 480, 272 }};
static const XRect _Const0010 = {{ 93, 91 }, { 387, 225 }};
static const XRect _Const0011 = {{ 211, 191 }, { 271, 211 }};
static const XRect _Const0012 = {{ 183, 136 }, { 297, 193 }};
static const XRect _Const0013 = {{ 142, 105 }, { 338, 148 }};
static const XRect _Const0014 = {{ 0, 38 }, { 480, 52 }};
static const XStringRes _Const0015 = { _StringsDefault0, 0x0015 };
static const XStringRes _Const0016 = { _StringsDefault0, 0x0022 };
static const XRect _Const0017 = {{ 17, 51 }, { 67, 101 }};
static const XRect _Const0018 = {{ 78, 40 }, { 480, 268 }};
static const XStringRes _Const0019 = { _StringsDefault0, 0x0028 };
static const XRect _Const001A = {{ 0, 0 }, { 402, 228 }};
static const XRect _Const001B = {{ 0, 70 }, { 359, 77 }};
static const XRect _Const001C = {{ 0, 146 }, { 359, 153 }};
static const XRect _Const001D = {{ 363, 1 }, { 395, 33 }};
static const XRect _Const001E = {{ 363, 185 }, { 395, 217 }};
static const XRect _Const001F = {{ 0, 0 }, { 400, 76 }};
static const XRect _Const0020 = {{ 7, 19 }, { 144, 52 }};
static const XColor _Const0021 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const0022 = {{ 288, 15 }, { 346, 57 }};
static const XRect _Const0023 = {{ 149, 7 }, { 281, 64 }};
static const XRect _Const0024 = {{ 232, 7 }, { 282, 64 }};
static const XRect _Const0025 = {{ 147, 7 }, { 197, 64 }};
static const XRect _Const0026 = {{ 204, 15 }, { 231, 57 }};
static const XRect _Const0027 = {{ 0, 0 }, { 369, 156 }};
static const XStringRes _Const0028 = { _StringsDefault0, 0x0030 };
static const XRect _Const0029 = {{ 0, 0 }, { 6, 118 }};
static const XRect _Const002A = {{ 0, 3 }, { 6, 118 }};
static const XColor _Const002B = { 0x71, 0x9E, 0x0D, 0xFF };
static const XRect _Const002C = {{ 0, 0 }, { 6, 6 }};
static const XStringRes _Const002D = { _StringsDefault0, 0x0040 };
static const XRect _Const002E = {{ 0, 0 }, { 480, 234 }};
static const XRect _Const002F = {{ 0, 0 }, { 223, 234 }};
static const XRect _Const0030 = {{ 0, 0 }, { 223, 91 }};
static const XRect _Const0031 = {{ 0, 133 }, { 223, 234 }};
static const XRect _Const0032 = {{ 188, 0 }, { 234, 234 }};
static const XPoint _Const0033 = { 223, 15 };
static const XPoint _Const0034 = { 3, 15 };
static const XPoint _Const0035 = { 223, 201 };
static const XPoint _Const0036 = { 3, 201 };
static const XPoint _Const0037 = { 223, 93 };
static const XPoint _Const0038 = { 3, 93 };
static const XColor _Const0039 = { 0xFE, 0xFF, 0x64, 0xFF };
static const XPoint _Const003A = { 223, 56 };
static const XPoint _Const003B = { 3, 56 };
static const XColor _Const003C = { 0x46, 0xFF, 0x4B, 0xFF };
static const XPoint _Const003D = { 223, 156 };
static const XPoint _Const003E = { 3, 156 };
static const XPoint _Const003F = { 223, 185 };
static const XPoint _Const0040 = { 3, 185 };
static const XRect _Const0041 = {{ 0, 0 }, { 480, 63 }};
static const XRect _Const0042 = {{ -189, 38 }, { 34, 272 }};
static const XRect _Const0043 = {{ 0, 119 }, { 480, 182 }};
static const XRect _Const0044 = {{ 323, 232 }, { 474, 265 }};
static const XRect _Const0045 = {{ 0, 38 }, { 480, 51 }};
static const XRect _Const0046 = {{ 364, 38 }, { 474, 73 }};
static const XStringRes _Const0047 = { _StringsDefault0, 0x0059 };
static const XRect _Const0048 = {{ 50, 0 }, { 430, 234 }};
static const XPoint _Const0049 = { 235, 132 };
static const XPoint _Const004A = { 252, 132 };
static const XPoint _Const004B = { 252, 114 };
static const XPoint _Const004C = { 235, 114 };
static const XPoint _Const004D = { 113, 113 };
static const XColor _Const004E = { 0x7B, 0xA6, 0x5B, 0xFF };

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

/* Initializer for the class 'Home::HOM12_EcoVisualizer' */
void HomeHOM12_EcoVisualizer__Init( HomeHOM12_EcoVisualizer _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  HomeBaseHome__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeHOM12_EcoVisualizer );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->EcoMeterBase, &_this->_.XObject, 0 );
  HomeEcoMeterChart__Init( &_this->EcoMeterChart, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->RightBlackArea, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->LeftBlackArea, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->GradientCover, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->AvgFuel, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Average, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Unit, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->EcoWindowLine, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->AvgLine, &_this->_.XObject, 0 );
  EffectsRectEffect__Init( &_this->ShiftLeftEffect, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->Timer, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_.XObject, 0 );
  HomeRecordList__Init( &_this->EcoRecordList, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->EcoBarUpdateTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeHOM12_EcoVisualizer );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super1.HomeType = EnumHomeTypeECO_VISUALIZER;
  CoreRectView__OnSetBounds( &_this->EcoMeterBase, _Const0000 );
  CoreView_OnSetLayout((CoreView)&_this->EcoMeterChart, CoreLayoutAlignToRight );
  CoreRectView__OnSetBounds( &_this->EcoMeterChart, _Const0001 );
  CoreGroup__OnSetEnabled( &_this->EcoMeterChart, 0 );
  HomeEcoMeterChart_OnSetBarSize( &_this->EcoMeterChart, 6 );
  CoreRectView__OnSetBounds( &_this->RightBlackArea, _Const0002 );
  ViewsRectangle_OnSetColor( &_this->RightBlackArea, _Const0003 );
  CoreRectView__OnSetBounds( &_this->LeftBlackArea, _Const0004 );
  ViewsRectangle_OnSetColor( &_this->LeftBlackArea, _Const0003 );
  CoreRectView__OnSetBounds( &_this->GradientCover, _Const0005 );
  ViewsImage_OnSetVisible( &_this->GradientCover, 1 );
  CoreRectView__OnSetBounds( &_this->AvgFuel, _Const0006 );
  ViewsText_OnSetString( &_this->AvgFuel, EwLoadString( &_Const0007 ));
  CoreRectView__OnSetBounds( &_this->Average, _Const0008 );
  ViewsText_OnSetAlignment( &_this->Average, ViewsTextAlignmentAlignHorzRight | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Average, 0 );
  CoreRectView__OnSetBounds( &_this->Unit, _Const0009 );
  CoreRectView__OnSetBounds( &_this->EcoWindowLine, _Const000A );
  CoreRectView__OnSetBounds( &_this->AvgLine, _Const000B );
  EffectsEffect_OnSetBounces((EffectsEffect)&_this->ShiftLeftEffect, 1 );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->ShiftLeftEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->ShiftLeftEffect, 200 );
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->ShiftLeftEffect, 0 );
  _this->ShiftLeftEffect.Value2 = _Const000C;
  _this->ShiftLeftEffect.Value1 = _Const000D;
  CoreTimer_OnSetPeriod( &_this->Timer, 1000 );
  CoreTimer_OnSetEnabled( &_this->Timer, 0 );
  _this->ValueArray[ 1 ] = 0.100000f;
  _this->ValueArray[ 2 ] = 0.200000f;
  _this->ValueArray[ 3 ] = 0.300000f;
  _this->ValueArray[ 4 ] = 0.400000f;
  _this->ValueArray[ 5 ] = 0.500000f;
  _this->ValueArray[ 6 ] = 0.600000f;
  _this->ValueArray[ 7 ] = 0.700000f;
  _this->ValueArray[ 8 ] = 0.800000f;
  _this->ValueArray[ 9 ] = 0.900000f;
  _this->ValueArray[ 10 ] = 1.000000f;
  _this->ValueArray[ 11 ] = 1.100000f;
  _this->ValueArray[ 12 ] = 1.200000f;
  _this->ValueArray[ 13 ] = 1.300000f;
  _this->ValueArray[ 14 ] = 1.400000f;
  _this->ValueArray[ 15 ] = 1.500000f;
  _this->ValueArray[ 16 ] = 1.600000f;
  _this->ValueArray[ 17 ] = 1.700000f;
  _this->ValueArray[ 18 ] = 1.800000f;
  _this->ValueArray[ 19 ] = 1.900000f;
  _this->ValueArray[ 20 ] = 2.000000f;
  CoreTimer_OnSetPeriod( &_this->EcoBarUpdateTimer, 1000 );
  CoreTimer_OnSetEnabled( &_this->EcoBarUpdateTimer, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->EcoMeterBase ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->EcoMeterChart ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RightBlackArea ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LeftBlackArea ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->GradientCover ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->AvgFuel ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Average ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Unit ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->EcoWindowLine ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->AvgLine ), 0 );
  ViewsImage_OnSetBitmap( &_this->EcoMeterBase, EwLoadResource( &ResourceEcoBase, 
  ResourcesBitmap ));
  HomeEcoMeterChart_OnSetDotFrame( &_this->EcoMeterChart, EwLoadResource( &ResourceEcoDot, 
  ResourcesBitmap ));
  HomeEcoMeterChart_OnSetRecords( &_this->EcoMeterChart, 0 );
  _this->EcoMeterChart.StartAnimation = EwNewSlot( _this, HomeHOM12_EcoVisualizer_ShiftLeftStarts );
  _this->EcoMeterChart.EndAnimation = EwNewSlot( _this, HomeHOM12_EcoVisualizer_ShiftLeftEnds );
  ViewsImage_OnSetBitmap( &_this->GradientCover, EwLoadResource( &ResourceGradientCover, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->AvgFuel, EwLoadResource( &FontsNotoSansMedium22pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->Average, EwLoadResource( &FontsNotoSansMedium42pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->Unit, EwLoadResource( &ResourceIconUnitKM_L, ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->EcoWindowLine, EwLoadResource( &ResourceEcoWindowLine, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->AvgLine, EwLoadResource( &ResourceAvgLine, ResourcesBitmap ));
  _this->ShiftLeftEffect.Super1.OnFinished = EwNewSlot( _this, HomeHOM12_EcoVisualizer_ShiftLeftEnds );
  _this->ShiftLeftEffect.Super1.OnAnimate = EwNewSlot( _this, HomeHOM12_EcoVisualizer_OnMoveLeft );
  _this->Timer.OnTrigger = EwNewSlot( _this, HomeHOM12_EcoVisualizer_OnUpdateSlot );
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, HomeHOM12_EcoVisualizer_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );
  _this->EcoBarUpdateTimer.OnTrigger = EwNewSlot( _this, HomeHOM12_EcoVisualizer_OnEcoBarUpdateSlot );

  /* Call the user defined constructor */
  HomeHOM12_EcoVisualizer_Init( _this, aArg );
}

/* Re-Initializer for the class 'Home::HOM12_EcoVisualizer' */
void HomeHOM12_EcoVisualizer__ReInit( HomeHOM12_EcoVisualizer _this )
{
  /* At first re-initialize the super class ... */
  HomeBaseHome__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->EcoMeterBase );
  HomeEcoMeterChart__ReInit( &_this->EcoMeterChart );
  ViewsRectangle__ReInit( &_this->RightBlackArea );
  ViewsRectangle__ReInit( &_this->LeftBlackArea );
  ViewsImage__ReInit( &_this->GradientCover );
  ViewsText__ReInit( &_this->AvgFuel );
  ViewsText__ReInit( &_this->Average );
  ViewsImage__ReInit( &_this->Unit );
  ViewsImage__ReInit( &_this->EcoWindowLine );
  ViewsImage__ReInit( &_this->AvgLine );
  EffectsRectEffect__ReInit( &_this->ShiftLeftEffect );
  CoreTimer__ReInit( &_this->Timer );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
  HomeRecordList__ReInit( &_this->EcoRecordList );
  CoreTimer__ReInit( &_this->EcoBarUpdateTimer );
}

/* Finalizer method for the class 'Home::HOM12_EcoVisualizer' */
void HomeHOM12_EcoVisualizer__Done( HomeHOM12_EcoVisualizer _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->EcoMeterBase );
  HomeEcoMeterChart__Done( &_this->EcoMeterChart );
  ViewsRectangle__Done( &_this->RightBlackArea );
  ViewsRectangle__Done( &_this->LeftBlackArea );
  ViewsImage__Done( &_this->GradientCover );
  ViewsText__Done( &_this->AvgFuel );
  ViewsText__Done( &_this->Average );
  ViewsImage__Done( &_this->Unit );
  ViewsImage__Done( &_this->EcoWindowLine );
  ViewsImage__Done( &_this->AvgLine );
  EffectsRectEffect__Done( &_this->ShiftLeftEffect );
  CoreTimer__Done( &_this->Timer );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );
  HomeRecordList__Done( &_this->EcoRecordList );
  CoreTimer__Done( &_this->EcoBarUpdateTimer );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void HomeHOM12_EcoVisualizer_Init( HomeHOM12_EcoVisualizer _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const000E ));

  if ( DeviceInterfaceVehicleDeviceClass_OnGetIsTimeoutError2Detected( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
    HomeHOM12_EcoVisualizer_RemoveAllEcoRecord( _this );
  else
    EwSignal( EwNewSlot( _this, HomeHOM12_EcoVisualizer_OnEcoBarUpdateSlot ), ((XObject)_this ));

  HomeHOM12_EcoVisualizer_SetFuelRateUnit( _this );
}

/* 'C' function for method : 'Home::HOM12_EcoVisualizer.OnLongEnterKeyActivated()' */
void HomeHOM12_EcoVisualizer_OnLongEnterKeyActivated( HomeHOM12_EcoVisualizer _this )
{
  if ( 1 == _this->Super3.KeyHandler.RepetitionCount )
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( InfoINF01_MeterDisplaySettingMenu, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Home::HOM12_EcoVisualizer.OnSetCurrentRelativeValue()' */
void HomeHOM12_EcoVisualizer_OnSetCurrentRelativeValue( HomeHOM12_EcoVisualizer _this, 
  XFloat value )
{
  _this->CurrentRelativeValue = value;

  if ( _this->EcoRecordList.NoOfItems >= 32 )
    HomeRecordList_RemoveRecord( &_this->EcoRecordList );

  HomeRecordList_AddRecord( &_this->EcoRecordList, _this->CurrentRelativeValue );

  if ( _this->EcoRecordList.NoOfItems == 1 )
  {
    _this->EcoMeterChart.Record = _this->EcoRecordList.firstRecord;
    _this->Index++;
  }
  else
  {
    if ( _this->Index == 32 )
    {
      HomeEcoMeterChart_RemoveEcoUnit( &_this->EcoMeterChart, _this->Index - 32 );
      _this->Index--;
    }

    _this->EcoMeterChart.Record = HomeRecordList_GetRecord( &_this->EcoRecordList, 
    _this->Index );
    _this->Index++;
  }

  HomeEcoMeterChart_OnSetRecords( &_this->EcoMeterChart, &_this->EcoRecordList );
}

/* 'C' function for method : 'Home::HOM12_EcoVisualizer.OnMoveLeft()' */
void HomeHOM12_EcoVisualizer_OnMoveLeft( HomeHOM12_EcoVisualizer _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreRectView__OnSetBounds( &_this->EcoMeterChart, _this->ShiftLeftEffect.Value );
}

/* 'C' function for method : 'Home::HOM12_EcoVisualizer.ShiftLeftStarts()' */
void HomeHOM12_EcoVisualizer_ShiftLeftStarts( HomeHOM12_EcoVisualizer _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwSignal( EwNewSlot( &_this->EcoMeterChart, HomeEcoMeterChart_OnAnimate ), ((XObject)_this ));
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->ShiftLeftEffect, 1 );
}

/* 'C' function for method : 'Home::HOM12_EcoVisualizer.ShiftLeftEnds()' */
void HomeHOM12_EcoVisualizer_ShiftLeftEnds( HomeHOM12_EcoVisualizer _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->ShiftLeftEffect, 0 );
}

/* 'C' function for method : 'Home::HOM12_EcoVisualizer.OnUpdateSlot()' */
void HomeHOM12_EcoVisualizer_OnUpdateSlot( HomeHOM12_EcoVisualizer _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->ValueArrayIdx > 20 )
    _this->ValueArrayIdx = 0;

  if (( _this->ValueArrayIdx > 5 ) && ( _this->ValueArrayIdx < 9 ))
  {
    HomeHOM12_EcoVisualizer_OnSetCurrentRelativeValue( _this, -1.000000f );
    HomeEcoMeterChart_HideEcoUnit( &_this->EcoMeterChart, _this->ValueArrayIdx );
  }
  else
    HomeHOM12_EcoVisualizer_OnSetCurrentRelativeValue( _this, _this->ValueArray[ 
    EwCheckIndex( _this->ValueArrayIdx, 21 )]);

  _this->ValueArrayIdx++;
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void HomeHOM12_EcoVisualizer_OnVehicleDataReceivedSlot( HomeHOM12_EcoVisualizer _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if ( VehicleData != 0 )
    switch ( VehicleData->RxType )
    {
      case EnumVehicleRxTypeTIMEOUT_ERROR2_UPDATED :
        if ( DeviceInterfaceVehicleDeviceClass_OnGetIsTimeoutError2Detected( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
        {
          CoreTimer_OnSetEnabled( &_this->EcoBarUpdateTimer, 0 );
          HomeHOM12_EcoVisualizer_RemoveAllEcoRecord( _this );
          ViewsText_OnSetString( &_this->Average, EwLoadString( &StringsGEN_THREE_HYPHENS ));
        }
        else
          CoreTimer_OnSetEnabled( &_this->EcoBarUpdateTimer, 1 );
      break;

      case EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT :
      {
        HomeHOM12_EcoVisualizer_SetFuelRateUnit( _this );
        HomeHOM12_EcoVisualizer_RemoveAllEcoRecord( _this );
      }
      break;

      default :; 
    }
}

/* 'C' function for method : 'Home::HOM12_EcoVisualizer.RemoveAllEcoRecord()' */
void HomeHOM12_EcoVisualizer_RemoveAllEcoRecord( HomeHOM12_EcoVisualizer _this )
{
  if ( _this->EcoRecordList.NoOfItems > 0 )
  {
    while ( _this->EcoRecordList.NoOfItems > 0 )
    {
      HomeEcoMeterChart_RemoveEcoUnit( &_this->EcoMeterChart, _this->Index - 1 );
      HomeRecordList_RemoveRecord( &_this->EcoRecordList );
      _this->Index--;
    }

    HomeRecordList_ClearList( &_this->EcoRecordList );
  }
}

/* 'C' function for method : 'Home::HOM12_EcoVisualizer.OnSetFuelRateAvg()' */
void HomeHOM12_EcoVisualizer_OnSetFuelRateAvg( HomeHOM12_EcoVisualizer _this, XFloat 
  value )
{
  _this->FuelRateAvg = value;

  if ( _this->FuelRateAvg == 0.000000f )
  {
    HomeHOM12_EcoVisualizer_RemoveAllEcoRecord( _this );
    ViewsImage_OnSetVisible( &_this->AvgLine, 0 );
    ViewsText_OnSetString( &_this->Average, EwLoadString( &StringsGEN_THREE_HYPHENS ));
  }
  else
  {
    ViewsImage_OnSetVisible( &_this->AvgLine, 1 );
    HomeHOM12_EcoVisualizer_OnSetCurrentRelativeValue( _this, _this->FuelRateInst 
    / _this->FuelRateAvg );
    ViewsText_OnSetString( &_this->Average, EwNewStringFloat( _this->FuelRateAvg, 
    0, 1 ));
  }
}

/* 'C' function for method : 'Home::HOM12_EcoVisualizer.OnEcoBarUpdateSlot()' */
void HomeHOM12_EcoVisualizer_OnEcoBarUpdateSlot( HomeHOM12_EcoVisualizer _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeENGINE_SPEED );

  if ( VehicleData->DataUInt32 < 50 )
  {
    HomeHOM12_EcoVisualizer_OnSetCurrentRelativeValue( _this, -1.000000f );
    HomeEcoMeterChart_HideEcoUnit( &_this->EcoMeterChart, _this->Index );
  }
  else
    if ( DeviceInterfaceVehicleDeviceClass_OnGetEngineIdling( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
        DeviceInterfaceVehicleDeviceClass )))
      switch ( DeviceInterfaceVehicleDeviceClass_OnGetFuelConsumptionUnit( EwGetAutoObject( 
              &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
      {
        case EnumMeterFuelConsumptionUnitKM_PER_LITER :
          HomeHOM12_EcoVisualizer_OnSetCurrentRelativeValue( _this, 0.000000f );
        break;

        case EnumMeterFuelConsumptionUnitL_PER_100KM :
          HomeHOM12_EcoVisualizer_OnSetCurrentRelativeValue( _this, 2.000000f );
        break;

        default :; 
      }
    else
    {
      VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeFUEL_RATE_INSTANT_UNIT_CONVERTED );
      _this->FuelRateInst = VehicleData->DataFloat;
      VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeFUEL_RATE_AVERAGE_UNIT_CONVERTED );

      if ( VehicleData->Valid )
        HomeHOM12_EcoVisualizer_OnSetFuelRateAvg( _this, VehicleData->DataFloat );
      else
      {
        ViewsImage_OnSetVisible( &_this->AvgLine, 0 );
        HomeHOM12_EcoVisualizer_RemoveAllEcoRecord( _this );
        ViewsText_OnSetString( &_this->Average, EwLoadString( &StringsGEN_THREE_HYPHENS ));
      }
    }
}

/* 'C' function for method : 'Home::HOM12_EcoVisualizer.SetFuelRateUnit()' */
void HomeHOM12_EcoVisualizer_SetFuelRateUnit( HomeHOM12_EcoVisualizer _this )
{
  switch ( DeviceInterfaceVehicleDeviceClass_OnGetFuelConsumptionUnit( EwGetAutoObject( 
          &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
  {
    case EnumMeterFuelConsumptionUnitKM_PER_LITER :
      ViewsImage_OnSetBitmap( &_this->Unit, EwLoadResource( &ResourceIconUnitKM_L, 
      ResourcesBitmap ));
    break;

    case EnumMeterFuelConsumptionUnitL_PER_100KM :
      ViewsImage_OnSetBitmap( &_this->Unit, EwLoadResource( &ResourceIconUnitL_100KM, 
      ResourcesBitmap ));
    break;

    case EnumMeterFuelConsumptionUnitMILE_PER_IMPERIAL_GAL :
    case EnumMeterFuelConsumptionUnitMILE_PER_US_GAL :
      ViewsImage_OnSetBitmap( &_this->Unit, EwLoadResource( &ResourceIconUnitMPG, 
      ResourcesBitmap ));
    break;

    default :; 
  }
}

/* Variants derived from the class : 'Home::HOM12_EcoVisualizer' */
EW_DEFINE_CLASS_VARIANTS( HomeHOM12_EcoVisualizer )
EW_END_OF_CLASS_VARIANTS( HomeHOM12_EcoVisualizer )

/* Virtual Method Table (VMT) for the class : 'Home::HOM12_EcoVisualizer' */
EW_DEFINE_CLASS( HomeHOM12_EcoVisualizer, HomeBaseHome, EcoMeterBase, EcoMeterBase, 
                 EcoMeterBase, EcoMeterBase, CurrentRelativeValue, CurrentRelativeValue, 
                 "Home::HOM12_EcoVisualizer" )
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
  HomeBaseHome_OnShortEnterKeyActivated,
  HomeBaseHome_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  HomeHOM12_EcoVisualizer_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  HomeBaseHome_ReturnToHome,
EW_END_OF_CLASS( HomeHOM12_EcoVisualizer )

/* Initializer for the class 'Home::HOM13_SpeedVisualizer' */
void HomeHOM13_SpeedVisualizer__Init( HomeHOM13_SpeedVisualizer _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  HomeBaseHome__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeHOM13_SpeedVisualizer );

  /* ... then construct all embedded objects */
  HomeSpeedCircle__Init( &_this->SpeedCircle, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->SpeedVisualizerTitle, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->SpeedLimitUnit, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->SpeedLimitText, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->SpeedLimitTitle, &_this->_.XObject, 0 );
  ViewsWallpaper__Init( &_this->StatusShadow, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->SpeedLimitUpdateEventHandler, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->Timer, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->SpeedUpdateTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeHOM13_SpeedVisualizer );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super1.HomeType = EnumHomeTypeSPEED_VISUALIZER;
  CoreRectView__OnSetBounds( &_this->SpeedCircle, _Const000F );
  CoreRectView__OnSetBounds( &_this->SpeedVisualizerTitle, _Const0010 );
  ViewsImage_OnSetVisible( &_this->SpeedVisualizerTitle, 1 );
  CoreRectView__OnSetBounds( &_this->SpeedLimitUnit, _Const0011 );
  ViewsImage_OnSetVisible( &_this->SpeedLimitUnit, 0 );
  CoreRectView__OnSetBounds( &_this->SpeedLimitText, _Const0012 );
  ViewsText_OnSetString( &_this->SpeedLimitText, 0 );
  CoreRectView__OnSetBounds( &_this->SpeedLimitTitle, _Const0013 );
  ViewsImage_OnSetVisible( &_this->SpeedLimitTitle, 0 );
  CoreRectView__OnSetBounds( &_this->StatusShadow, _Const0014 );
  CoreTimer_OnSetPeriod( &_this->Timer, 100 );
  CoreTimer_OnSetEnabled( &_this->Timer, 0 );
  _this->Ascending = 1;
  CoreTimer_OnSetPeriod( &_this->SpeedUpdateTimer, 100 );
  CoreTimer_OnSetEnabled( &_this->SpeedUpdateTimer, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->SpeedCircle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SpeedVisualizerTitle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SpeedLimitUnit ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SpeedLimitText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SpeedLimitTitle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->StatusShadow ), 0 );
  ViewsImage_OnSetBitmap( &_this->SpeedVisualizerTitle, EwLoadResource( &ResourceSVSpeedUnLimit, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->SpeedLimitUnit, EwLoadResource( &ResourceSVKmH, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->SpeedLimitText, EwLoadResource( &FontsNotoSansMedium42pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->SpeedLimitTitle, EwLoadResource( &ResourceSVSpeedLimit, 
  ResourcesBitmap ));
  ViewsWallpaper_OnSetBitmap( &_this->StatusShadow, EwLoadResource( &ResourceStatusShadow, 
  ResourcesBitmap ));
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, HomeHOM13_SpeedVisualizer_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );
  _this->SpeedLimitUpdateEventHandler.OnEvent = EwNewSlot( _this, HomeHOM13_SpeedVisualizer_OnSpeedLimitUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->SpeedLimitUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->SpeedLimitUpdateEvent );
  _this->Timer.OnTrigger = EwNewSlot( _this, HomeHOM13_SpeedVisualizer_OnTimerSlot );
  _this->SpeedUpdateTimer.OnTrigger = EwNewSlot( _this, HomeHOM13_SpeedVisualizer_OnSpeedUpdateSlot );

  /* Call the user defined constructor */
  HomeHOM13_SpeedVisualizer_Init( _this, aArg );
}

/* Re-Initializer for the class 'Home::HOM13_SpeedVisualizer' */
void HomeHOM13_SpeedVisualizer__ReInit( HomeHOM13_SpeedVisualizer _this )
{
  /* At first re-initialize the super class ... */
  HomeBaseHome__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  HomeSpeedCircle__ReInit( &_this->SpeedCircle );
  ViewsImage__ReInit( &_this->SpeedVisualizerTitle );
  ViewsImage__ReInit( &_this->SpeedLimitUnit );
  ViewsText__ReInit( &_this->SpeedLimitText );
  ViewsImage__ReInit( &_this->SpeedLimitTitle );
  ViewsWallpaper__ReInit( &_this->StatusShadow );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
  CoreSystemEventHandler__ReInit( &_this->SpeedLimitUpdateEventHandler );
  CoreTimer__ReInit( &_this->Timer );
  CoreTimer__ReInit( &_this->SpeedUpdateTimer );
}

/* Finalizer method for the class 'Home::HOM13_SpeedVisualizer' */
void HomeHOM13_SpeedVisualizer__Done( HomeHOM13_SpeedVisualizer _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  HomeSpeedCircle__Done( &_this->SpeedCircle );
  ViewsImage__Done( &_this->SpeedVisualizerTitle );
  ViewsImage__Done( &_this->SpeedLimitUnit );
  ViewsText__Done( &_this->SpeedLimitText );
  ViewsImage__Done( &_this->SpeedLimitTitle );
  ViewsWallpaper__Done( &_this->StatusShadow );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );
  CoreSystemEventHandler__Done( &_this->SpeedLimitUpdateEventHandler );
  CoreTimer__Done( &_this->Timer );
  CoreTimer__Done( &_this->SpeedUpdateTimer );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void HomeHOM13_SpeedVisualizer_Init( HomeHOM13_SpeedVisualizer _this, XHandle aArg )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0015 ));
  VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeMILEAGE_UNIT );

  if ( VehicleData != 0 )
    HomeHOM13_SpeedVisualizer_OnSetSpeedUnit( _this, (XEnum)VehicleData->DataUInt32 );

  EwSignal( EwNewSlot( _this, HomeHOM13_SpeedVisualizer_OnSpeedLimitUpdateSlot ), 
    ((XObject)_this ));
}

/* 'C' function for method : 'Home::HOM13_SpeedVisualizer.OnLongEnterKeyActivated()' */
void HomeHOM13_SpeedVisualizer_OnLongEnterKeyActivated( HomeHOM13_SpeedVisualizer _this )
{
  if ( 1 == _this->Super3.KeyHandler.RepetitionCount )
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( InfoINF01_MeterDisplaySettingMenu, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void HomeHOM13_SpeedVisualizer_OnVehicleDataReceivedSlot( HomeHOM13_SpeedVisualizer _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if ( VehicleData != 0 )
    switch ( VehicleData->RxType )
    {
      case EnumVehicleRxTypeTIMEOUT_ERROR2_UPDATED :
        if ( DeviceInterfaceVehicleDeviceClass_OnGetIsTimeoutError2Detected( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
        {
          ViewsText_OnSetString( &_this->SpeedLimitText, EwLoadString( &_Const0016 ));
          ViewsText_OnSetColor( &_this->SpeedLimitText, ColorGRAY_FOR_DISABLED );
        }
        else
        {
          ViewsText_OnSetColor( &_this->SpeedLimitText, ColorWHITE );
          EwSignal( EwNewSlot( _this, HomeHOM13_SpeedVisualizer_OnSpeedLimitUpdateSlot ), 
            ((XObject)_this ));
        }
      break;

      case EnumVehicleRxTypeMILEAGE_UNIT :
      {
        VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
        &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeMILEAGE_UNIT );
        HomeHOM13_SpeedVisualizer_OnSetSpeedUnit( _this, (XEnum)VehicleData->DataUInt32 );
        EwSignal( EwNewSlot( _this, HomeHOM13_SpeedVisualizer_OnSpeedLimitUpdateSlot ), 
          ((XObject)_this ));
      }
      break;

      default :; 
    }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void HomeHOM13_SpeedVisualizer_OnSpeedLimitUpdateSlot( HomeHOM13_SpeedVisualizer _this, 
  XObject sender )
{
  DeviceInterfaceNaviDataClass NaviData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), EnumNaviDataTypeSPEED_LIMIT );

  if ( NaviData != 0 )
  {
    HomeHOM13_SpeedVisualizer_OnSetSpeedLimit( _this, NaviData->SpeedLimit );
    EwSignal( EwNewSlot( _this, HomeHOM13_SpeedVisualizer_OnSpeedUpdateSlot ), ((XObject)_this ));
  }
}

/* 'C' function for method : 'Home::HOM13_SpeedVisualizer.OnSetSpeedUnit()' */
void HomeHOM13_SpeedVisualizer_OnSetSpeedUnit( HomeHOM13_SpeedVisualizer _this, 
  XEnum value )
{
  if ( _this->SpeedUnit != value )
  {
    _this->SpeedUnit = value;

    switch ( _this->SpeedUnit )
    {
      case EnumMileageSettingItemKM :
        ViewsImage_OnSetBitmap( &_this->SpeedLimitUnit, EwLoadResource( &ResourceSVKmH, 
        ResourcesBitmap ));
      break;

      case EnumMileageSettingItemMILE :
        ViewsImage_OnSetBitmap( &_this->SpeedLimitUnit, EwLoadResource( &ResourceSVMPH, 
        ResourcesBitmap ));
      break;

      default :; 
    }
  }
}

/* 'C' function for method : 'Home::HOM13_SpeedVisualizer.OnSetSpeedLimit()' */
void HomeHOM13_SpeedVisualizer_OnSetSpeedLimit( HomeHOM13_SpeedVisualizer _this, 
  XInt32 value )
{
  if ( _this->SpeedLimit != value )
  {
    _this->SpeedLimit = value;
    _this->SpeedCircle.SpeedLimit = value;
    ViewsText_OnSetString( &_this->SpeedLimitText, EwNewStringInt( value, 0, 10 ));

    if ( value > 0 )
    {
      HomeSpeedCircle_OnSetColor( &_this->SpeedCircle, HomeSV_WITH_SPEED_LIMIT );
      ViewsImage_OnSetVisible( &_this->SpeedCircle.GradientLine, 1 );
      ViewsImage_OnSetVisible( &_this->SpeedVisualizerTitle, 0 );
      ViewsImage_OnSetVisible( &_this->SpeedLimitTitle, 1 );
      ViewsImage_OnSetVisible( &_this->SpeedLimitUnit, 1 );
      ViewsText_OnSetVisible( &_this->SpeedLimitText, 1 );
    }
    else
    {
      HomeSpeedCircle_OnSetColor( &_this->SpeedCircle, HomeSV_WITHOUT_SPEED_LIMIT );
      ViewsImage_OnSetVisible( &_this->SpeedCircle.GradientLine, 0 );
      ViewsImage_OnSetVisible( &_this->SpeedVisualizerTitle, 1 );
      ViewsImage_OnSetVisible( &_this->SpeedLimitTitle, 0 );
      ViewsImage_OnSetVisible( &_this->SpeedLimitUnit, 0 );
      ViewsText_OnSetVisible( &_this->SpeedLimitText, 0 );
    }
  }
}

/* 'C' function for method : 'Home::HOM13_SpeedVisualizer.OnTimerSlot()' */
void HomeHOM13_SpeedVisualizer_OnTimerSlot( HomeHOM13_SpeedVisualizer _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Ascending )
  {
    HomeSpeedCircle_OnSetSpeedValue( &_this->SpeedCircle, _this->SpeedCircle.SpeedValue 
    + 10 );

    if ( _this->SpeedCircle.SpeedValue == 70 )
      HomeHOM13_SpeedVisualizer_OnSetSpeedLimit( _this, 50 );

    if ( _this->SpeedCircle.SpeedValue >= 140 )
      _this->Ascending = 0;
  }
  else
  {
    HomeSpeedCircle_OnSetSpeedValue( &_this->SpeedCircle, _this->SpeedCircle.SpeedValue 
    - 10 );

    if ( _this->SpeedCircle.SpeedValue == 70 )
      HomeHOM13_SpeedVisualizer_OnSetSpeedLimit( _this, 40 );

    if ( _this->SpeedCircle.SpeedValue == 0 )
      _this->Ascending = 1;
  }
}

/* 'C' function for method : 'Home::HOM13_SpeedVisualizer.OnSpeedUpdateSlot()' */
void HomeHOM13_SpeedVisualizer_OnSpeedUpdateSlot( HomeHOM13_SpeedVisualizer _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeVEHICLE_SPEED_METER );

  if ( VehicleData != 0 )
    HomeSpeedCircle_OnSetSpeedValue( &_this->SpeedCircle, (XInt32)VehicleData->DataUInt32 );
}

/* Variants derived from the class : 'Home::HOM13_SpeedVisualizer' */
EW_DEFINE_CLASS_VARIANTS( HomeHOM13_SpeedVisualizer )
EW_END_OF_CLASS_VARIANTS( HomeHOM13_SpeedVisualizer )

/* Virtual Method Table (VMT) for the class : 'Home::HOM13_SpeedVisualizer' */
EW_DEFINE_CLASS( HomeHOM13_SpeedVisualizer, HomeBaseHome, SpeedCircle, SpeedCircle, 
                 SpeedCircle, SpeedCircle, SpeedLimit, SpeedLimit, "Home::HOM13_SpeedVisualizer" )
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
  HomeBaseHome_OnShortEnterKeyActivated,
  HomeBaseHome_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  HomeHOM13_SpeedVisualizer_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  HomeBaseHome_ReturnToHome,
EW_END_OF_CLASS( HomeHOM13_SpeedVisualizer )

/* Initializer for the class 'Home::BaseHome' */
void HomeBaseHome__Init( HomeBaseHome _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeBaseHome );

  /* ... then construct all embedded objects */
  CoreTimer__Init( &_this->NaviConnectFailedTimer, &_this->_.XObject, 0 );
  PopPOP16_NaviLoadingUI__Init( &_this->LoadingAnimation, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeBaseHome );

  /* ... and initialize objects, variables, properties, etc. */
  CoreTimer_OnSetPeriod( &_this->NaviConnectFailedTimer, 5000 );
  CoreRectView__OnSetBounds( &_this->LoadingAnimation, _Const000F );
  CoreGroup__OnSetVisible( &_this->LoadingAnimation, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LoadingAnimation ), 0 );
  _this->NaviConnectFailedTimer.OnTrigger = EwNewSlot( _this, HomeBaseHome_OnNaviConnectFailedSlot );
}

/* Re-Initializer for the class 'Home::BaseHome' */
void HomeBaseHome__ReInit( HomeBaseHome _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreTimer__ReInit( &_this->NaviConnectFailedTimer );
  PopPOP16_NaviLoadingUI__ReInit( &_this->LoadingAnimation );
}

/* Finalizer method for the class 'Home::BaseHome' */
void HomeBaseHome__Done( HomeBaseHome _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  CoreTimer__Done( &_this->NaviConnectFailedTimer );
  PopPOP16_NaviLoadingUI__Done( &_this->LoadingAnimation );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* 'C' function for method : 'Home::BaseHome.OnShortEnterKeyActivated()' */
void HomeBaseHome_OnShortEnterKeyActivated( HomeBaseHome _this )
{
  if ( !_this->NaviConnectFailedTimer.Enabled )
    CoreGroup_PresentDialog((CoreGroup)CoreView__GetRoot( _this ), ((CoreGroup)EwNewObject( 
    LauncherLNC_Main, 0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Home::BaseHome.OnShortHomeKeyActivated()' */
void HomeBaseHome_OnShortHomeKeyActivated( HomeBaseHome _this )
{
  if ( !_this->NaviConnectFailedTimer.Enabled )
  {
    XEnum NextHomeType = HomeBaseHome_GetNextHomeType( _this, _this->HomeType );
    ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

    if ( App != 0 )
    {
      if ( EnumHomeTypeNAVI_DEFAULT_VIEW == _this->HomeType )
      {
        DeviceInterfaceNavigationDeviceClass_StopMapFrameRequest( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));
        DeviceInterfaceNavigationDeviceClass_StopContentRequest( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));
      }

      if ( EnumHomeTypeNAVI_NEXT_TURN == _this->HomeType )
        DeviceInterfaceNavigationDeviceClass_StopContentRequest( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));

      switch ( NextHomeType )
      {
        case EnumHomeTypeTACHO_VISUALIZER :
        case EnumHomeTypeSPEED_VISUALIZER :
        case EnumHomeTypeECO_VISUALIZER :
          ApplicationApplication_SlideInHome( App, NextHomeType );
        break;

        case EnumHomeTypeNAVI_DEFAULT_VIEW :
        case EnumHomeTypeNAVI_NEXT_TURN :
        case EnumHomeTypeNAVI_TURN_BY_TURN :
          ApplicationApplication_SwitchToHome( App, NextHomeType );
        break;

        case EnumHomeTypeVEHICLE_INFO :
          ApplicationApplication_SlideInHome( App, NextHomeType );
        break;

        default :; 
      }
    }
  }
}

/* 'C' function for method : 'Home::BaseHome.ReturnToHome()' */
void HomeBaseHome_ReturnToHome( HomeBaseHome _this )
{
  MenuBaseMenuView MenuDialog = EwCastObject( CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
    0 ), MenuBaseMenuView );

  if ( MenuDialog != 0 )
    CoreGroup_DismissDialog((CoreGroup)_this, ((CoreGroup)MenuDialog ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 0 );
}

/* Wrapper function for the virtual method : 'Home::BaseHome.ReturnToHome()' */
void HomeBaseHome__ReturnToHome( void* _this )
{
  ((HomeBaseHome)_this)->_.VMT->ReturnToHome((HomeBaseHome)_this );
}

/* 'C' function for method : 'Home::BaseHome.GetNextHomeType()' */
XEnum HomeBaseHome_GetNextHomeType( HomeBaseHome _this, XEnum aCurrentHomeType )
{
  XEnum NextHomeType;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  NextHomeType = EnumHomeTypeTOTAL;

  switch ( aCurrentHomeType )
  {
    case EnumHomeTypeTACHO_VISUALIZER :
    case EnumHomeTypeECO_VISUALIZER :
    case EnumHomeTypeSPEED_VISUALIZER :
      if ( !DeviceInterfaceNavigationDeviceClass_OnGetNaviAppSppConnected( EwGetAutoObject( 
          &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
        NextHomeType = EnumHomeTypeVEHICLE_INFO;
      else
        if ( !DeviceInterfaceNavigationDeviceClass_GetAppInitStatus( EwGetAutoObject( 
            &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )) 
            || !DeviceInterfaceNavigationDeviceClass_GetNaviConnectStatus( EwGetAutoObject( 
            &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
          NextHomeType = EnumHomeTypeVEHICLE_INFO;
        else
          NextHomeType = EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome;
    break;

    case EnumHomeTypeNAVI_DEFAULT_VIEW :
    case EnumHomeTypeNAVI_NEXT_TURN :
    case EnumHomeTypeNAVI_TURN_BY_TURN :
      NextHomeType = EnumHomeTypeVEHICLE_INFO;
    break;

    case EnumHomeTypeVEHICLE_INFO :
      switch ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay )
      {
        case EnumMeterDisplayTACHOMETER :
          NextHomeType = EnumHomeTypeTACHO_VISUALIZER;
        break;

        case EnumMeterDisplayECHO_METER :
          NextHomeType = EnumHomeTypeECO_VISUALIZER;
        break;

        case EnumMeterDisplaySPEED_METER :
          NextHomeType = EnumHomeTypeSPEED_VISUALIZER;
        break;

        default :; 
      }
    break;

    default :; 
  }

  return NextHomeType;
}

/* 'C' function for method : 'Home::BaseHome.OnSetAccessNaviView()' */
void HomeBaseHome_OnSetAccessNaviView( HomeBaseHome _this, XBool value )
{
  if ( _this->AccessNaviView != value )
  {
    _this->AccessNaviView = value;
    CoreTimer_OnSetEnabled( &_this->NaviConnectFailedTimer, value );
    PopPOP16_NaviLoadingUI_OnSetAnimated( &_this->LoadingAnimation, value );
    CoreGroup__OnSetVisible( &_this->LoadingAnimation, value );
  }
}

/* 'C' function for method : 'Home::BaseHome.OnNaviConnectFailedSlot()' */
void HomeBaseHome_OnNaviConnectFailedSlot( HomeBaseHome _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  HomeBaseHome_OnSetAccessNaviView( _this, 0 );
  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( PopPOP02_ConnectionError, 
  0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* Variants derived from the class : 'Home::BaseHome' */
EW_DEFINE_CLASS_VARIANTS( HomeBaseHome )
EW_END_OF_CLASS_VARIANTS( HomeBaseHome )

/* Virtual Method Table (VMT) for the class : 'Home::BaseHome' */
EW_DEFINE_CLASS( HomeBaseHome, ComponentsBaseMainBG, NaviConnectFailedTimer, NaviConnectFailedTimer, 
                 NaviConnectFailedTimer, NaviConnectFailedTimer, HomeType, HomeType, 
                 "Home::BaseHome" )
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
  HomeBaseHome_OnShortEnterKeyActivated,
  HomeBaseHome_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  HomeBaseHome_ReturnToHome,
EW_END_OF_CLASS( HomeBaseHome )

/* Initializer for the class 'Home::HOM03_VehicleInfo' */
void HomeHOM03_VehicleInfo__Init( HomeHOM03_VehicleInfo _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  HomeBaseHome__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeHOM03_VehicleInfo );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->IconInfo, &_this->_.XObject, 0 );
  HomeVehicleInfoMenu__Init( &_this->VehicleInfoMenu, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeHOM03_VehicleInfo );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super1.HomeType = EnumHomeTypeVEHICLE_INFO;
  CoreRectView__OnSetBounds( &_this->IconInfo, _Const0017 );
  CoreRectView__OnSetBounds( &_this->VehicleInfoMenu, _Const0018 );
  CoreGroup__Add( _this, ((CoreView)&_this->IconInfo ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->VehicleInfoMenu ), 0 );
  ViewsImage_OnSetBitmap( &_this->IconInfo, EwLoadResource( &ResourceIconInfo, ResourcesBitmap ));

  /* Call the user defined constructor */
  HomeHOM03_VehicleInfo_Init( _this, aArg );
}

/* Re-Initializer for the class 'Home::HOM03_VehicleInfo' */
void HomeHOM03_VehicleInfo__ReInit( HomeHOM03_VehicleInfo _this )
{
  /* At first re-initialize the super class ... */
  HomeBaseHome__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->IconInfo );
  HomeVehicleInfoMenu__ReInit( &_this->VehicleInfoMenu );
}

/* Finalizer method for the class 'Home::HOM03_VehicleInfo' */
void HomeHOM03_VehicleInfo__Done( HomeHOM03_VehicleInfo _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->IconInfo );
  HomeVehicleInfoMenu__Done( &_this->VehicleInfoMenu );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void HomeHOM03_VehicleInfo_Init( HomeHOM03_VehicleInfo _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0019 ));
}

/* 'C' function for method : 'Home::HOM03_VehicleInfo.OnShortDownKeyActivated()' */
void HomeHOM03_VehicleInfo_OnShortDownKeyActivated( HomeHOM03_VehicleInfo _this )
{
  HomeVehicleInfoMenu_ScrollUp( &_this->VehicleInfoMenu );
}

/* 'C' function for method : 'Home::HOM03_VehicleInfo.OnShortUpKeyActivated()' */
void HomeHOM03_VehicleInfo_OnShortUpKeyActivated( HomeHOM03_VehicleInfo _this )
{
  HomeVehicleInfoMenu_ScrollDown( &_this->VehicleInfoMenu );
}

/* 'C' function for method : 'Home::HOM03_VehicleInfo.OnLongEnterKeyActivated()' */
void HomeHOM03_VehicleInfo_OnLongEnterKeyActivated( HomeHOM03_VehicleInfo _this )
{
  if ( 1 == _this->Super3.KeyHandler.RepetitionCount )
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( SettingsSET46_VehicleInfoReset, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* Variants derived from the class : 'Home::HOM03_VehicleInfo' */
EW_DEFINE_CLASS_VARIANTS( HomeHOM03_VehicleInfo )
EW_END_OF_CLASS_VARIANTS( HomeHOM03_VehicleInfo )

/* Virtual Method Table (VMT) for the class : 'Home::HOM03_VehicleInfo' */
EW_DEFINE_CLASS( HomeHOM03_VehicleInfo, HomeBaseHome, IconInfo, IconInfo, IconInfo, 
                 IconInfo, _.VMT, _.VMT, "Home::HOM03_VehicleInfo" )
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
  HomeHOM03_VehicleInfo_OnShortDownKeyActivated,
  HomeHOM03_VehicleInfo_OnShortUpKeyActivated,
  HomeBaseHome_OnShortEnterKeyActivated,
  HomeBaseHome_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  HomeHOM03_VehicleInfo_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  HomeBaseHome_ReturnToHome,
EW_END_OF_CLASS( HomeHOM03_VehicleInfo )

/* Initializer for the class 'Home::VehicleInfoMenu' */
void HomeVehicleInfoMenu__Init( HomeVehicleInfoMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeVehicleInfoMenu );

  /* ... then construct all embedded objects */
  CoreVerticalList__Init( &_this->VerticalList, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Divider1, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Divider2, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->UpArrowIcon, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->DownArrowIcon, &_this->_.XObject, 0 );
  EffectsInt32Effect__Init( &_this->RowScrollEffect, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeVehicleInfoMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const001A );
  CoreRectView__OnSetBounds( &_this->VerticalList, _Const001A );
  CoreVerticalList_OnSetEndless( &_this->VerticalList, 1 );
  CoreVerticalList_OnSetItemHeight( &_this->VerticalList, 76 );
  CoreVerticalList_OnSetItemClass( &_this->VerticalList, EW_CLASS( HomeItemVehicleInfo ));
  CoreRectView__OnSetBounds( &_this->Divider1, _Const001B );
  CoreRectView__OnSetBounds( &_this->Divider2, _Const001C );
  CoreRectView__OnSetBounds( &_this->UpArrowIcon, _Const001D );
  CoreRectView__OnSetBounds( &_this->DownArrowIcon, _Const001E );
  ViewsImage_OnSetFrameNumber( &_this->DownArrowIcon, 1 );
  EffectsEffect_OnSetExponent((EffectsEffect)&_this->RowScrollEffect, 4.190000f );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->RowScrollEffect, EffectsTimingExp_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->RowScrollEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->RowScrollEffect, 200 );
  EffectsEffect_OnSetInitialDelay((EffectsEffect)&_this->RowScrollEffect, 50 );
  CoreGroup__Add( _this, ((CoreView)&_this->VerticalList ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider1 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider2 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UpArrowIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DownArrowIcon ), 0 );
  _this->VerticalList.OnLoadItem = EwNewSlot( _this, HomeVehicleInfoMenu_OnLoadItem );
  ViewsImage_OnSetBitmap( &_this->Divider1, EwLoadResource( &ResourceInfoDivider, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Divider2, EwLoadResource( &ResourceInfoDivider, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->UpArrowIcon, EwLoadResource( &ResourcePageUpDown, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->DownArrowIcon, EwLoadResource( &ResourcePageUpDown, 
  ResourcesBitmap ));
  _this->RowScrollEffect.Outlet = EwNewRef( &_this->VerticalList, CoreVerticalList_OnGetScrollOffset, 
  CoreVerticalList_OnSetScrollOffset );
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, HomeVehicleInfoMenu_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );

  /* Call the user defined constructor */
  HomeVehicleInfoMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Home::VehicleInfoMenu' */
void HomeVehicleInfoMenu__ReInit( HomeVehicleInfoMenu _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreVerticalList__ReInit( &_this->VerticalList );
  ViewsImage__ReInit( &_this->Divider1 );
  ViewsImage__ReInit( &_this->Divider2 );
  ViewsImage__ReInit( &_this->UpArrowIcon );
  ViewsImage__ReInit( &_this->DownArrowIcon );
  EffectsInt32Effect__ReInit( &_this->RowScrollEffect );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'Home::VehicleInfoMenu' */
void HomeVehicleInfoMenu__Done( HomeVehicleInfoMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  CoreVerticalList__Done( &_this->VerticalList );
  ViewsImage__Done( &_this->Divider1 );
  ViewsImage__Done( &_this->Divider2 );
  ViewsImage__Done( &_this->UpArrowIcon );
  ViewsImage__Done( &_this->DownArrowIcon );
  EffectsInt32Effect__Done( &_this->RowScrollEffect );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void HomeVehicleInfoMenu_Init( HomeVehicleInfoMenu _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  HomeVehicleInfoMenu_InitItems( _this );
  HomeVehicleInfoMenu_SetDividers( _this );
  HomeVehicleInfoMenu_SetArrowIcons( _this );

  if ( _this->VerticalList.NoOfItems < 3 )
    CoreRectView__OnSetBounds( &_this->VerticalList, EwSetRectH( _this->VerticalList.Super2.Bounds, 
    _this->VerticalList.ItemHeight * _this->VerticalList.NoOfItems ));
  else
    CoreRectView__OnSetBounds( &_this->VerticalList, EwSetRectH( _this->VerticalList.Super2.Bounds, 
    EwGetRectH( _this->Super2.Bounds )));
}

/* This method is called by 'VerticalList' every time the list loads or updates 
   an item. */
void HomeVehicleInfoMenu_OnLoadItem( HomeVehicleInfoMenu _this, XObject sender )
{
  XInt32 ItemNo;
  HomeItemVehicleInfo MenuItem;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ItemNo = _this->VerticalList.Item;
  MenuItem = EwCastObject( _this->VerticalList.View, HomeItemVehicleInfo );

  if ( MenuItem != 0 )
  {
    ViewsText_OnSetString( &MenuItem->Title, HomeVehicleInfoMenu_LoadItemTitle( 
    _this, ItemNo ));
    ViewsImage_OnSetBitmap( &MenuItem->IconUnit, HomeVehicleInfoMenu_LoadItemUnitIconBmp( 
    _this, ItemNo ));

    if ( EnumVehicleInfoMenuItemTRIP_TIME == _this->Items[ EwCheckIndex( ItemNo, 
        14 )])
    {
      ViewsText_OnSetString( &MenuItem->HourText, HomeVehicleInfoMenu_LoadItemHour( 
      _this, ItemNo ));
      ViewsText_OnSetVisible( &MenuItem->HourText, 1 );
      ViewsText_OnSetString( &MenuItem->MinuteText, HomeVehicleInfoMenu_LoadItemMinute( 
      _this, ItemNo ));
      ViewsText_OnSetVisible( &MenuItem->MinuteText, 1 );
      ViewsImage_OnSetVisible( &MenuItem->HourIcon, 1 );
      ViewsText_OnSetVisible( &MenuItem->ValueText, 0 );
    }
    else
    {
      ViewsText_OnSetString( &MenuItem->ValueText, HomeVehicleInfoMenu_LoadItemValue( 
      _this, ItemNo ));
      ViewsText_OnSetVisible( &MenuItem->ValueText, 1 );
      HomeItemVehicleInfo_OnSetValueTextBlink( MenuItem, HomeVehicleInfoMenu_LoadItemValueBlink( 
      _this, ItemNo ));
      ViewsText_OnSetVisible( &MenuItem->HourText, 0 );
      ViewsText_OnSetVisible( &MenuItem->MinuteText, 0 );
      ViewsImage_OnSetVisible( &MenuItem->HourIcon, 0 );
    }
  }
}

/* 'C' function for method : 'Home::VehicleInfoMenu.InitItems()' */
void HomeVehicleInfoMenu_InitItems( HomeVehicleInfoMenu _this )
{
  XInt32 i;
  XInt32 NoOfItems = 0;
  XEnum MenuItem;

  for ( i = 0; i < 14; i++ )
  {
    MenuItem = (XEnum)i;

    switch ( MenuItem )
    {
      case EnumVehicleInfoMenuItemAVG_SPEED :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionAVG_SPEED ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemAVG_FUEL :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionAVG_FUEL ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemINST_FUEL :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionCURRENT_FUEL ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemRANGE :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionRANGE_DISTANCE ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemFUEL_CONSUMPTION :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionFUEL_CONSUMPTION ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemAIR_TEMPERATURE :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionAIR_TEMPERATURE ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemCOOLANT_TEMPERATURE :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionCOOLANT ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemBATTERY :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionBATTERY_VOLTAGE ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemTIRE_FRONT :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionTIRE_FRONT ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemTIRE_REAR :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionTIRE_REAR ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemTIRE_FRONT_RIGHT :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionTIRE_FRONT_RIGHT ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemTIRE_FRONT_LEFT :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionTIRE_FRONT_LEFT ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      case EnumVehicleInfoMenuItemCRUISE :
        if ( DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( EwGetAutoObject( 
            &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
            EnumVehicleSupportedFunctionCRUISE ))
        {
          _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
          NoOfItems++;
        }
      break;

      default : 
      {
        _this->Items[ EwCheckIndex( NoOfItems, 14 )] = MenuItem;
        NoOfItems++;
      }
    }
  }

  CoreVerticalList_OnSetNoOfItems( &_this->VerticalList, NoOfItems );
}

/* 'C' function for method : 'Home::VehicleInfoMenu.LoadItemTitle()' */
XString HomeVehicleInfoMenu_LoadItemTitle( HomeVehicleInfoMenu _this, XInt32 aItemNo )
{
  XString Title = 0;

  switch ( _this->Items[ EwCheckIndex( aItemNo, 14 )])
  {
    case EnumVehicleInfoMenuItemAVG_SPEED :
      Title = EwLoadString( &StringsHOM03_AVG_SPEED );
    break;

    case EnumVehicleInfoMenuItemAVG_FUEL :
      Title = EwLoadString( &StringsHOM03_AVG_FUEL );
    break;

    case EnumVehicleInfoMenuItemINST_FUEL :
      Title = EwLoadString( &StringsHOM03_INST_FUEL );
    break;

    case EnumVehicleInfoMenuItemTRIP_TIME :
      Title = EwLoadString( &StringsHOM03_TRIP_TIME );
    break;

    case EnumVehicleInfoMenuItemRANGE :
      Title = EwLoadString( &StringsHOM03_RANGE );
    break;

    case EnumVehicleInfoMenuItemFUEL_CONSUMPTION :
      Title = EwLoadString( &StringsHOM03_FUEL_CONSUMPTION );
    break;

    case EnumVehicleInfoMenuItemAIR_TEMPERATURE :
      Title = EwLoadString( &StringsHOM03_AIR );
    break;

    case EnumVehicleInfoMenuItemCOOLANT_TEMPERATURE :
      Title = EwLoadString( &StringsHOM03_COOLANT );
    break;

    case EnumVehicleInfoMenuItemBATTERY :
      Title = EwLoadString( &StringsHOM03_BATTERY );
    break;

    case EnumVehicleInfoMenuItemTIRE_FRONT_RIGHT :
      Title = EwLoadString( &StringsHOM03_FRONT_R );
    break;

    case EnumVehicleInfoMenuItemTIRE_FRONT_LEFT :
      Title = EwLoadString( &StringsHOM03_FRONT_L );
    break;

    case EnumVehicleInfoMenuItemTIRE_FRONT :
      Title = EwLoadString( &StringsHOM03_FRONT );
    break;

    case EnumVehicleInfoMenuItemTIRE_REAR :
      Title = EwLoadString( &StringsHOM03_REAR );
    break;

    case EnumVehicleInfoMenuItemCRUISE :
      Title = EwLoadString( &StringsHOM03_CRUISE );
    break;

    default :; 
  }

  return Title;
}

/* 'C' function for method : 'Home::VehicleInfoMenu.SetDividers()' */
void HomeVehicleInfoMenu_SetDividers( HomeVehicleInfoMenu _this )
{
  if ( 1 <= _this->VerticalList.NoOfItems )
    ViewsImage_OnSetVisible( &_this->Divider1, 1 );
  else
    ViewsImage_OnSetVisible( &_this->Divider1, 0 );

  if ( 2 <= _this->VerticalList.NoOfItems )
    ViewsImage_OnSetVisible( &_this->Divider2, 1 );
  else
    ViewsImage_OnSetVisible( &_this->Divider2, 0 );
}

/* 'C' function for method : 'Home::VehicleInfoMenu.LoadItemUnitIconBmp()' */
ResourcesBitmap HomeVehicleInfoMenu_LoadItemUnitIconBmp( HomeVehicleInfoMenu _this, 
  XInt32 aItemNo )
{
  ResourcesBitmap IconBitmap = 0;

  switch ( _this->Items[ EwCheckIndex( aItemNo, 14 )])
  {
    case EnumVehicleInfoMenuItemAVG_SPEED :
    case EnumVehicleInfoMenuItemRANGE :
    case EnumVehicleInfoMenuItemCRUISE :
      if ( EnumMileageSettingItemKM == DeviceInterfaceVehicleDeviceClass_OnGetMileageUnit( 
          EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
        IconBitmap = EwLoadResource( &ResourceIconUnitKM, ResourcesBitmap );
      else
        IconBitmap = EwLoadResource( &ResourceIconUnitMile, ResourcesBitmap );
    break;

    case EnumVehicleInfoMenuItemAVG_FUEL :
    case EnumVehicleInfoMenuItemINST_FUEL :
      switch ( DeviceInterfaceVehicleDeviceClass_OnGetFuelConsumptionUnit( EwGetAutoObject( 
              &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
      {
        case EnumMeterFuelConsumptionUnitKM_PER_LITER :
          IconBitmap = EwLoadResource( &ResourceIconUnitKM_L, ResourcesBitmap );
        break;

        case EnumMeterFuelConsumptionUnitL_PER_100KM :
          IconBitmap = EwLoadResource( &ResourceIconUnitL_100KM, ResourcesBitmap );
        break;

        case EnumMeterFuelConsumptionUnitMILE_PER_IMPERIAL_GAL :
        case EnumMeterFuelConsumptionUnitMILE_PER_US_GAL :
          IconBitmap = EwLoadResource( &ResourceIconUnitMPG, ResourcesBitmap );
        break;

        default :; 
      }
    break;

    case EnumVehicleInfoMenuItemTRIP_TIME :
      IconBitmap = EwLoadResource( &ResourceIconUnitMinute, ResourcesBitmap );
    break;

    case EnumVehicleInfoMenuItemFUEL_CONSUMPTION :
      switch ( DeviceInterfaceVehicleDeviceClass_OnGetFuelConsumptionUnit( EwGetAutoObject( 
              &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
      {
        case EnumMeterFuelConsumptionUnitKM_PER_LITER :
        case EnumMeterFuelConsumptionUnitL_PER_100KM :
          IconBitmap = EwLoadResource( &ResourceIconUnitL, ResourcesBitmap );
        break;

        case EnumMeterFuelConsumptionUnitMILE_PER_US_GAL :
        case EnumMeterFuelConsumptionUnitMILE_PER_IMPERIAL_GAL :
          IconBitmap = EwLoadResource( &ResourceIconUnitGal, ResourcesBitmap );
        break;

        default :; 
      }
    break;

    case EnumVehicleInfoMenuItemAIR_TEMPERATURE :
    case EnumVehicleInfoMenuItemCOOLANT_TEMPERATURE :
      if ( EnumTemperatureSettingItemTEMP_C == DeviceInterfaceVehicleDeviceClass_OnGetTemperatureUnit( 
          EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
        IconBitmap = EwLoadResource( &ResourceIconUnitDegC, ResourcesBitmap );
      else
        IconBitmap = EwLoadResource( &ResourceIconUnitDegF, ResourcesBitmap );
    break;

    case EnumVehicleInfoMenuItemBATTERY :
      IconBitmap = EwLoadResource( &ResourceIconUnitVolt, ResourcesBitmap );
    break;

    case EnumVehicleInfoMenuItemTIRE_FRONT :
    case EnumVehicleInfoMenuItemTIRE_REAR :
    case EnumVehicleInfoMenuItemTIRE_FRONT_RIGHT :
    case EnumVehicleInfoMenuItemTIRE_FRONT_LEFT :
      switch ( DeviceInterfaceVehicleDeviceClass_OnGetPressureUnit( EwGetAutoObject( 
              &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
      {
        case EnumPressureSettingItemKGF_PER_CM2 :
          IconBitmap = EwLoadResource( &ResourceIconUnitKGF_CM2, ResourcesBitmap );
        break;

        case EnumPressureSettingItemKPA :
          IconBitmap = EwLoadResource( &ResourceIconUnitKPA, ResourcesBitmap );
        break;

        case EnumPressureSettingItemPSI :
          IconBitmap = EwLoadResource( &ResourceIconUnitPSI, ResourcesBitmap );
        break;

        default :; 
      }
    break;

    default :; 
  }

  return IconBitmap;
}

/* 'C' function for method : 'Home::VehicleInfoMenu.LoadItemValue()' */
XString HomeVehicleInfoMenu_LoadItemValue( HomeVehicleInfoMenu _this, XInt32 aItemNo )
{
  XString ValueStr = 0;

  switch ( _this->Items[ EwCheckIndex( aItemNo, 14 )])
  {
    case EnumVehicleInfoMenuItemAVG_SPEED :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetAvgSpeedStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemAVG_FUEL :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetAvgFuelRateStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemINST_FUEL :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetInstantFuelRateStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemRANGE :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetRangeStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemFUEL_CONSUMPTION :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetFuelConStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemAIR_TEMPERATURE :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetAirTemperatureStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemCOOLANT_TEMPERATURE :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetCoolantTemperatureStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemBATTERY :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetBatteryStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemTIRE_FRONT :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetTireFrontPressureStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemTIRE_REAR :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetTireRearPressureStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    case EnumVehicleInfoMenuItemTIRE_FRONT_RIGHT :
      ValueStr = EwLoadString( &StringsGEN_THREE_HYPHENS );
    break;

    case EnumVehicleInfoMenuItemTIRE_FRONT_LEFT :
      ValueStr = EwLoadString( &StringsGEN_THREE_HYPHENS );
    break;

    case EnumVehicleInfoMenuItemCRUISE :
      ValueStr = DeviceInterfaceVehicleDeviceClass_OnGetCruiseSpeedStr( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
    break;

    default :; 
  }

  return ValueStr;
}

/* 'C' function for method : 'Home::VehicleInfoMenu.ScrollUp()' */
void HomeVehicleInfoMenu_ScrollUp( HomeVehicleInfoMenu _this )
{
  if ( !_this->RowScrollEffect.Super1.Enabled && ( 1 < _this->VerticalList.NoOfItems ))
  {
    _this->RowScrollEffect.Value1 = _this->VerticalList.ScrollOffset;
    _this->RowScrollEffect.Value2 = _this->VerticalList.ScrollOffset - 76;
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->RowScrollEffect, 1 );
  }
}

/* 'C' function for method : 'Home::VehicleInfoMenu.ScrollDown()' */
void HomeVehicleInfoMenu_ScrollDown( HomeVehicleInfoMenu _this )
{
  if ( !_this->RowScrollEffect.Super1.Enabled && ( 1 < _this->VerticalList.NoOfItems ))
  {
    _this->RowScrollEffect.Value1 = _this->VerticalList.ScrollOffset;
    _this->RowScrollEffect.Value2 = _this->VerticalList.ScrollOffset + 76;
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->RowScrollEffect, 1 );
  }
}

/* 'C' function for method : 'Home::VehicleInfoMenu.SetArrowIcons()' */
void HomeVehicleInfoMenu_SetArrowIcons( HomeVehicleInfoMenu _this )
{
  if ( 1 < _this->VerticalList.NoOfItems )
  {
    ViewsImage_OnSetVisible( &_this->UpArrowIcon, 1 );
    ViewsImage_OnSetVisible( &_this->DownArrowIcon, 1 );
  }
  else
  {
    ViewsImage_OnSetVisible( &_this->UpArrowIcon, 0 );
    ViewsImage_OnSetVisible( &_this->DownArrowIcon, 0 );
  }
}

/* 'C' function for method : 'Home::VehicleInfoMenu.LoadItemHour()' */
XString HomeVehicleInfoMenu_LoadItemHour( HomeVehicleInfoMenu _this, XInt32 aItemNo )
{
  XString HourString = 0;

  if ( EnumVehicleInfoMenuItemTRIP_TIME == _this->Items[ EwCheckIndex( aItemNo, 
      14 )])
    HourString = DeviceInterfaceVehicleDeviceClass_OnGetTripTimeHourStr( EwGetAutoObject( 
    &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));

  return HourString;
}

/* 'C' function for method : 'Home::VehicleInfoMenu.LoadItemMinute()' */
XString HomeVehicleInfoMenu_LoadItemMinute( HomeVehicleInfoMenu _this, XInt32 aItemNo )
{
  XString MinuteString = 0;

  if ( EnumVehicleInfoMenuItemTRIP_TIME == _this->Items[ EwCheckIndex( aItemNo, 
      14 )])
    MinuteString = DeviceInterfaceVehicleDeviceClass_OnGetTripTimeMinuteStr( EwGetAutoObject( 
    &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));

  return MinuteString;
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void HomeVehicleInfoMenu_OnVehicleDataReceivedSlot( HomeVehicleInfoMenu _this, XObject 
  sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if ( VehicleData != 0 )
    switch ( VehicleData->RxType )
    {
      case EnumVehicleRxTypeTEMPERATURE_UNIT :
      {
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemAIR_TEMPERATURE );
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemCOOLANT_TEMPERATURE );
      }
      break;

      case EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT :
      {
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemAVG_FUEL );
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemINST_FUEL );
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemFUEL_CONSUMPTION );
      }
      break;

      case EnumVehicleRxTypeMILEAGE_UNIT :
      {
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemAVG_SPEED );
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemRANGE );
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemCRUISE );
      }
      break;

      case EnumVehicleRxTypePRESSURE_UNIT :
      case EnumVehicleRxTypeTIRE_SENSOR_EQUIPPED :
      {
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTIRE_FRONT );
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTIRE_REAR );
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTIRE_FRONT_LEFT );
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTIRE_FRONT_RIGHT );
      }
      break;

      case EnumVehicleRxTypeAVERAGE_SPEED :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemAVG_SPEED );
      break;

      case EnumVehicleRxTypeFUEL_RATE_AVERAGE :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemAVG_FUEL );
      break;

      case EnumVehicleRxTypeFUEL_RATE_INSTANT :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemINST_FUEL );
      break;

      case EnumVehicleRxTypeTRIP_TIME :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTRIP_TIME );
      break;

      case EnumVehicleRxTypeRANGE_DISTANCE :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemRANGE );
      break;

      case EnumVehicleRxTypeFUEL_CONSUMPTION :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemFUEL_CONSUMPTION );
      break;

      case EnumVehicleRxTypeAIR_TEMPERATURE :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemAIR_TEMPERATURE );
      break;

      case EnumVehicleRxTypeCOOLANT_TEMPERATURE :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemCOOLANT_TEMPERATURE );
      break;

      case EnumVehicleRxTypeBATTERY_VOLTAGE :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemBATTERY );
      break;

      case EnumVehicleRxTypeTIRE_FRONT :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTIRE_FRONT );
      break;

      case EnumVehicleRxTypeTIRE_REAR :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTIRE_REAR );
      break;

      case EnumVehicleRxTypeTIRE_FRONT_LEFT :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTIRE_FRONT_LEFT );
      break;

      case EnumVehicleRxTypeTIRE_FRONT_RIGHT :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemTIRE_FRONT_RIGHT );
      break;

      case EnumVehicleRxTypeCRUISE_SPEED :
        HomeVehicleInfoMenu_ReloadItem( _this, EnumVehicleInfoMenuItemCRUISE );
      break;

      default :; 
    }
}

/* 'C' function for method : 'Home::VehicleInfoMenu.ReloadItem()' */
void HomeVehicleInfoMenu_ReloadItem( HomeVehicleInfoMenu _this, XEnum aVehicleInfoItem )
{
  XInt32 i;

  for ( i = 0; i < _this->VerticalList.NoOfItems; i++ )
    if (( i < 14 ) && ( aVehicleInfoItem == _this->Items[ EwCheckIndex( i, 14 )]))
    {
      CoreVerticalList_InvalidateItems( &_this->VerticalList, i, i );
      break;
    }
}

/* 'C' function for method : 'Home::VehicleInfoMenu.LoadItemValueBlink()' */
XBool HomeVehicleInfoMenu_LoadItemValueBlink( HomeVehicleInfoMenu _this, XInt32 
  aItemNo )
{
  XBool blink = 0;

  switch ( _this->Items[ EwCheckIndex( aItemNo, 14 )])
  {
    case EnumVehicleInfoMenuItemCOOLANT_TEMPERATURE :
    {
      DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        EnumVehicleRxTypeCOOLANT_TEMPERATURE );

      if ( VehicleData->Valid && ( 128.750000f == VehicleData->DataFloat ))
        blink = 1;
    }
    break;

    default :; 
  }

  return blink;
}

/* Variants derived from the class : 'Home::VehicleInfoMenu' */
EW_DEFINE_CLASS_VARIANTS( HomeVehicleInfoMenu )
EW_END_OF_CLASS_VARIANTS( HomeVehicleInfoMenu )

/* Virtual Method Table (VMT) for the class : 'Home::VehicleInfoMenu' */
EW_DEFINE_CLASS( HomeVehicleInfoMenu, CoreGroup, VerticalList, VerticalList, VerticalList, 
                 VerticalList, Items, Items, "Home::VehicleInfoMenu" )
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
EW_END_OF_CLASS( HomeVehicleInfoMenu )

/* Initializer for the class 'Home::ItemVehicleInfo' */
void HomeItemVehicleInfo__Init( HomeItemVehicleInfo _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeItemVehicleInfo );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Title, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->IconUnit, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->ValueText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->MinuteText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->HourText, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->HourIcon, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->ValueTextBlinkTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeItemVehicleInfo );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const001F );
  _this->Super1.PassUpKey = 1;
  _this->Super1.PassDownKey = 1;
  CoreView_OnSetLayout((CoreView)&_this->Title, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->Title, _Const0020 );
  ViewsText_OnSetEllipsis( &_this->Title, 1 );
  ViewsText_OnSetAlignment( &_this->Title, ViewsTextAlignmentAlignHorzLeft | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Title, 0 );
  ViewsText_OnSetColor( &_this->Title, _Const0021 );
  CoreRectView__OnSetBounds( &_this->IconUnit, _Const0022 );
  CoreView_OnSetLayout((CoreView)&_this->ValueText, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->ValueText, _Const0023 );
  ViewsText_OnSetEllipsis( &_this->ValueText, 1 );
  ViewsText_OnSetAlignment( &_this->ValueText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ValueText, 0 );
  ViewsText_OnSetColor( &_this->ValueText, _Const0021 );
  CoreView_OnSetLayout((CoreView)&_this->MinuteText, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->MinuteText, _Const0024 );
  ViewsText_OnSetEllipsis( &_this->MinuteText, 1 );
  ViewsText_OnSetAlignment( &_this->MinuteText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->MinuteText, 0 );
  ViewsText_OnSetColor( &_this->MinuteText, _Const0021 );
  CoreView_OnSetLayout((CoreView)&_this->HourText, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->HourText, _Const0025 );
  ViewsText_OnSetEllipsis( &_this->HourText, 1 );
  ViewsText_OnSetAlignment( &_this->HourText, ViewsTextAlignmentAlignHorzRight | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->HourText, 0 );
  ViewsText_OnSetColor( &_this->HourText, _Const0021 );
  CoreRectView__OnSetBounds( &_this->HourIcon, _Const0026 );
  ViewsImage_OnSetVisible( &_this->HourIcon, 0 );
  CoreTimer_OnSetPeriod( &_this->ValueTextBlinkTimer, 500 );
  CoreGroup__Add( _this, ((CoreView)&_this->Title ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->IconUnit ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ValueText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MinuteText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->HourText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->HourIcon ), 0 );
  ViewsText_OnSetFont( &_this->Title, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->IconUnit, EwLoadResource( &ResourceIconUnitKM_L, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->ValueText, EwLoadResource( &FontsNotoSansMedium40pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->MinuteText, EwLoadResource( &FontsNotoSansMedium40pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->HourText, EwLoadResource( &FontsNotoSansMedium40pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->HourIcon, EwLoadResource( &ResourceIconUnitHour, 
  ResourcesBitmap ));
  _this->ValueTextBlinkTimer.OnTrigger = EwNewSlot( _this, HomeItemVehicleInfo_OnValueTextBlinkText );
}

/* Re-Initializer for the class 'Home::ItemVehicleInfo' */
void HomeItemVehicleInfo__ReInit( HomeItemVehicleInfo _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Title );
  ViewsImage__ReInit( &_this->IconUnit );
  ViewsText__ReInit( &_this->ValueText );
  ViewsText__ReInit( &_this->MinuteText );
  ViewsText__ReInit( &_this->HourText );
  ViewsImage__ReInit( &_this->HourIcon );
  CoreTimer__ReInit( &_this->ValueTextBlinkTimer );
}

/* Finalizer method for the class 'Home::ItemVehicleInfo' */
void HomeItemVehicleInfo__Done( HomeItemVehicleInfo _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Title );
  ViewsImage__Done( &_this->IconUnit );
  ViewsText__Done( &_this->ValueText );
  ViewsText__Done( &_this->MinuteText );
  ViewsText__Done( &_this->HourText );
  ViewsImage__Done( &_this->HourIcon );
  CoreTimer__Done( &_this->ValueTextBlinkTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_.Super );
}

/* 'C' function for method : 'Home::ItemVehicleInfo.OnValueTextBlinkText()' */
void HomeItemVehicleInfo_OnValueTextBlinkText( HomeItemVehicleInfo _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsText_OnSetVisible( &_this->ValueText, (XBool)!ViewsText_OnGetVisible( &_this->ValueText ));
}

/* 'C' function for method : 'Home::ItemVehicleInfo.OnSetValueTextBlink()' */
void HomeItemVehicleInfo_OnSetValueTextBlink( HomeItemVehicleInfo _this, XBool value )
{
  if ( _this->ValueTextBlink != value )
  {
    _this->ValueTextBlink = value;
    CoreTimer_OnSetEnabled( &_this->ValueTextBlinkTimer, value );
  }
}

/* Variants derived from the class : 'Home::ItemVehicleInfo' */
EW_DEFINE_CLASS_VARIANTS( HomeItemVehicleInfo )
EW_END_OF_CLASS_VARIANTS( HomeItemVehicleInfo )

/* Virtual Method Table (VMT) for the class : 'Home::ItemVehicleInfo' */
EW_DEFINE_CLASS( HomeItemVehicleInfo, ComponentsBaseComponent, Title, Title, Title, 
                 Title, ValueTextBlink, ValueTextBlink, "Home::ItemVehicleInfo" )
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
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( HomeItemVehicleInfo )

/* Initializer for the class 'Home::EcoMeterChart' */
void HomeEcoMeterChart__Init( HomeEcoMeterChart _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeEcoMeterChart );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeEcoMeterChart );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0027 );
}

/* Re-Initializer for the class 'Home::EcoMeterChart' */
void HomeEcoMeterChart__ReInit( HomeEcoMeterChart _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Home::EcoMeterChart' */
void HomeEcoMeterChart__Done( HomeEcoMeterChart _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Home::EcoMeterChart.OnSetDotFrame()' */
void HomeEcoMeterChart_OnSetDotFrame( HomeEcoMeterChart _this, ResourcesBitmap value )
{
  _this->DotFrame = value;
  CoreGroup__InvalidateArea( _this, EwGetRectORect( _this->Super2.Bounds ));
}

/* 'C' function for method : 'Home::EcoMeterChart.OnSetBarSize()' */
void HomeEcoMeterChart_OnSetBarSize( HomeEcoMeterChart _this, XInt32 value )
{
  if ( value < 0 )
    value = 0;

  if ( value == _this->BarSize )
    return;

  _this->BarSize = value;
  CoreGroup__InvalidateArea( _this, EwGetRectORect( _this->Super2.Bounds ));
}

/* 'C' function for method : 'Home::EcoMeterChart.OnSetRecords()' */
void HomeEcoMeterChart_OnSetRecords( HomeEcoMeterChart _this, HomeRecordList value )
{
  _this->Records = value;

  if (( _this->Records == 0 ) || ( _this->Records->NoOfItems < 1 ))
    return;

  if ( _this->Record != 0 )
  {
    XInt32 dist;

    if ( _this->Record->Value > 2.000000f )
      _this->Record->Value = 2.000000f;

    dist = (XInt32)( 5.600000f * ( _this->Record->Value * 10 ));

    if ( _this->DotFrame != 0 )
    {
      _this->EcoUnit = EwNewObject( HomeEcoMeterComponent, 0 );
      CoreRectView__OnSetBounds( _this->EcoUnit, EwNewRect( 363, 133 - dist, 369, 
      140 ));
      CoreGroup__Add( _this, ((CoreView)_this->EcoUnit ), 0 );
    }

    EwSignal( _this->StartAnimation, ((XObject)_this ));
  }
}

/* 'C' function for method : 'Home::EcoMeterChart.OnAnimate()' */
void HomeEcoMeterChart_OnAnimate( HomeEcoMeterChart _this, XObject sender )
{
  CoreView view;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  view = CoreGroup__FindNextView( _this, 0, 0 );

  while ( view != 0 )
  {
    if ( EwClassOf(((XObject)view )) == EwClassOf(((XObject)_this->EcoUnit )))
    {
      HomeEcoMeterComponent bar = EwCastObject( view, HomeEcoMeterComponent );
      CoreRectView__OnSetBounds( bar, EwSetRectX1( bar->Super2.Bounds, bar->Super2.Bounds.Point1.X 
      - 11 ));
      CoreRectView__OnSetBounds( bar, EwSetRectX2( bar->Super2.Bounds, bar->Super2.Bounds.Point2.X 
      - 11 ));
    }

    view = view->next;
  }
}

/* 'C' function for method : 'Home::EcoMeterChart.RemoveEcoUnit()' */
void HomeEcoMeterChart_RemoveEcoUnit( HomeEcoMeterChart _this, XInt32 aIndex )
{
  if ( aIndex >= 0 )
  {
    CoreView view = CoreGroup__GetViewAtIndex( _this, aIndex );
    HomeEcoMeterComponent EcoBar = EwCastObject( view, HomeEcoMeterComponent );

    if ( EcoBar != 0 )
      CoreGroup__Remove( _this, ((CoreView)EcoBar ));
  }
  else
    EwTrace( "%s", EwLoadString( &_Const0028 ));
}

/* 'C' function for method : 'Home::EcoMeterChart.HideEcoUnit()' */
void HomeEcoMeterChart_HideEcoUnit( HomeEcoMeterChart _this, XInt32 aIndex )
{
  if ( aIndex >= 0 )
  {
    CoreView view = CoreGroup__GetViewAtIndex( _this, aIndex );
    HomeEcoMeterComponent EcoBar = EwCastObject( view, HomeEcoMeterComponent );

    if ( EcoBar != 0 )
      CoreGroup__OnSetVisible( EcoBar, 0 );
  }
  else
    EwTrace( "%s", EwLoadString( &_Const0028 ));
}

/* Variants derived from the class : 'Home::EcoMeterChart' */
EW_DEFINE_CLASS_VARIANTS( HomeEcoMeterChart )
EW_END_OF_CLASS_VARIANTS( HomeEcoMeterChart )

/* Virtual Method Table (VMT) for the class : 'Home::EcoMeterChart' */
EW_DEFINE_CLASS( HomeEcoMeterChart, CoreGroup, DotFrame, StartAnimation, BarSize, 
                 BarSize, BarSize, BarSize, "Home::EcoMeterChart" )
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
EW_END_OF_CLASS( HomeEcoMeterChart )

/* Initializer for the class 'Home::EcoMeterComponent' */
void HomeEcoMeterComponent__Init( HomeEcoMeterComponent _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeEcoMeterComponent );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Bar, &_this->_.XObject, 0 );
  ViewsFrame__Init( &_this->Dot, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeEcoMeterComponent );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0029 );
  CoreRectView__OnSetBounds( &_this->Bar, _Const002A );
  ViewsRectangle_OnSetColor( &_this->Bar, _Const002B );
  CoreRectView__OnSetBounds( &_this->Dot, _Const002C );
  CoreGroup__Add( _this, ((CoreView)&_this->Bar ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Dot ), 0 );
  ViewsFrame_OnSetBitmap( &_this->Dot, EwLoadResource( &ResourceEcoDot, ResourcesBitmap ));
}

/* Re-Initializer for the class 'Home::EcoMeterComponent' */
void HomeEcoMeterComponent__ReInit( HomeEcoMeterComponent _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Bar );
  ViewsFrame__ReInit( &_this->Dot );
}

/* Finalizer method for the class 'Home::EcoMeterComponent' */
void HomeEcoMeterComponent__Done( HomeEcoMeterComponent _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Bar );
  ViewsFrame__Done( &_this->Dot );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* Variants derived from the class : 'Home::EcoMeterComponent' */
EW_DEFINE_CLASS_VARIANTS( HomeEcoMeterComponent )
EW_END_OF_CLASS_VARIANTS( HomeEcoMeterComponent )

/* Virtual Method Table (VMT) for the class : 'Home::EcoMeterComponent' */
EW_DEFINE_CLASS( HomeEcoMeterComponent, CoreGroup, Bar, Bar, Bar, Bar, _.VMT, _.VMT, 
                 "Home::EcoMeterComponent" )
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
EW_END_OF_CLASS( HomeEcoMeterComponent )

/* Initializer for the class 'Home::RecordList' */
void HomeRecordList__Init( HomeRecordList _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeRecordList );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeRecordList );

  /* ... and initialize objects, variables, properties, etc. */
}

/* Re-Initializer for the class 'Home::RecordList' */
void HomeRecordList__ReInit( HomeRecordList _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Home::RecordList' */
void HomeRecordList__Done( HomeRecordList _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* The method 'ClearList' is used to clear the list of records. */
void HomeRecordList_ClearList( HomeRecordList _this )
{
  _this->firstRecord = 0;
  _this->lastRecord = 0;
  _this->NoOfItems = 0;
}

/* The method GetRecord returns the record object with the given index. */
HomeRecord HomeRecordList_GetRecord( HomeRecordList _this, XInt32 aIndex )
{
  HomeRecord record;

  if (( aIndex < 0 ) || ( aIndex >= _this->NoOfItems ))
    return 0;

  record = _this->firstRecord;

  while (( aIndex > 0 ) && ( record != 0 ))
  {
    aIndex = aIndex - 1;
    record = record->next;
  }

  return record;
}

/* 'C' function for method : 'Home::RecordList.AddRecord()' */
void HomeRecordList_AddRecord( HomeRecordList _this, XFloat aValue )
{
  HomeRecord record;

  record = EwNewObject( HomeRecord, 0 );
  record->Value = aValue;

  if ( _this->firstRecord == 0 )
  {
    _this->firstRecord = record;
    _this->lastRecord = record;
    _this->NoOfItems = 1;
  }
  else
    if ( _this->NoOfItems < 32 )
    {
      _this->lastRecord->next = record;
      _this->lastRecord = record;
      _this->NoOfItems = _this->NoOfItems + 1;
    }
    else
      EwTrace( "%s", EwLoadString( &_Const002D ));
}

/* 'C' function for method : 'Home::RecordList.RemoveRecord()' */
void HomeRecordList_RemoveRecord( HomeRecordList _this )
{
  HomeRecord record;

  if ( _this->firstRecord == 0 )
    return;

  record = _this->firstRecord;
  _this->NoOfItems = _this->NoOfItems - 1;
  _this->firstRecord = record->next;
}

/* Variants derived from the class : 'Home::RecordList' */
EW_DEFINE_CLASS_VARIANTS( HomeRecordList )
EW_END_OF_CLASS_VARIANTS( HomeRecordList )

/* Virtual Method Table (VMT) for the class : 'Home::RecordList' */
EW_DEFINE_CLASS( HomeRecordList, XObject, firstRecord, NoOfItems, NoOfItems, NoOfItems, 
                 NoOfItems, NoOfItems, "Home::RecordList" )
EW_END_OF_CLASS( HomeRecordList )

/* Initializer for the class 'Home::Record' */
void HomeRecord__Init( HomeRecord _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeRecord );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeRecord );
}

/* Re-Initializer for the class 'Home::Record' */
void HomeRecord__ReInit( HomeRecord _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Home::Record' */
void HomeRecord__Done( HomeRecord _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* Variants derived from the class : 'Home::Record' */
EW_DEFINE_CLASS_VARIANTS( HomeRecord )
EW_END_OF_CLASS_VARIANTS( HomeRecord )

/* Virtual Method Table (VMT) for the class : 'Home::Record' */
EW_DEFINE_CLASS( HomeRecord, XObject, next, Value, Value, Value, Value, Value, "Home::Record" )
EW_END_OF_CLASS( HomeRecord )

/* Initializer for the class 'Home::TachoBaseline' */
void HomeTachoBaseline__Init( HomeTachoBaseline _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeTachoBaseline );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeTachoBaseline );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const002E );
}

/* Re-Initializer for the class 'Home::TachoBaseline' */
void HomeTachoBaseline__ReInit( HomeTachoBaseline _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Home::TachoBaseline' */
void HomeTachoBaseline__Done( HomeTachoBaseline _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void HomeTachoBaseline_UpdateLayout( HomeTachoBaseline _this, XPoint aSize )
{
  XInt32 BaselineDistanceX;
  XInt32 BaselineNum;

  CoreGroup_UpdateLayout((CoreGroup)_this, aSize );

  if ( EnumTachoFullScaleRPM10000 == _this->FullScaleType )
  {
    BaselineDistanceX = 21;
    BaselineNum = 21;
  }
  else
  {
    BaselineDistanceX = 14;
    BaselineNum = 31;
  }

  HomeTachoBaseline_DrawBaselines( _this, 4, BaselineDistanceX, BaselineNum );
}

/* 'C' function for method : 'Home::TachoBaseline.OnSetRedZoneBeginRPM()' */
void HomeTachoBaseline_OnSetRedZoneBeginRPM( HomeTachoBaseline _this, XInt32 value )
{
  if ( _this->RedZoneBeginRPM != value )
  {
    _this->RedZoneBeginRPM = value;
    CoreGroup_InvalidateLayout((CoreGroup)_this );
  }
}

/* 'C' function for method : 'Home::TachoBaseline.OnSetFullScaleType()' */
void HomeTachoBaseline_OnSetFullScaleType( HomeTachoBaseline _this, XEnum value )
{
  if ( _this->FullScaleType != value )
  {
    _this->FullScaleType = value;
    CoreGroup_InvalidateLayout((CoreGroup)_this );
  }
}

/* 'C' function for method : 'Home::TachoBaseline.DrawBaselines()' */
void HomeTachoBaseline_DrawBaselines( HomeTachoBaseline _this, XInt32 BaselineStartX, 
  XInt32 BaselineDistanceX, XInt32 BaselineNum )
{
  XInt32 BaselineIdx;
  XInt32 RedZoneStartIdx = _this->RedZoneBeginRPM / 500;

  CoreGroup_RemoveAll((CoreGroup)_this );

  for ( BaselineIdx = 0; BaselineIdx < BaselineNum; BaselineIdx++ )
  {
    ViewsImage BaselineImg = EwNewObject( ViewsImage, 0 );
    XInt32 StartX;
    XRect BaselineBounds;

    if ( 0 == ( BaselineIdx % 2 ))
      ViewsImage_OnSetBitmap( BaselineImg, EwLoadResource( &ResourceTachoBaselineA, 
      ResourcesBitmap ));
    else
      ViewsImage_OnSetBitmap( BaselineImg, EwLoadResource( &ResourceTachoBaselineB, 
      ResourcesBitmap ));

    if ( BaselineIdx >= RedZoneStartIdx )
      ViewsImage_OnSetFrameNumber( BaselineImg, 1 );

    StartX = BaselineStartX + ( BaselineDistanceX * BaselineIdx );
    BaselineBounds = EwNewRect( StartX, 0, StartX + EwLoadResource( &ResourceTachoBaselineA, 
    ResourcesBitmap )->FrameSize.X, EwLoadResource( &ResourceTachoBaselineA, ResourcesBitmap )->FrameSize.Y );
    CoreRectView__OnSetBounds( BaselineImg, BaselineBounds );
    CoreGroup__Add( _this, ((CoreView)BaselineImg ), 0 );
  }
}

/* Variants derived from the class : 'Home::TachoBaseline' */
EW_DEFINE_CLASS_VARIANTS( HomeTachoBaseline )
EW_END_OF_CLASS_VARIANTS( HomeTachoBaseline )

/* Virtual Method Table (VMT) for the class : 'Home::TachoBaseline' */
EW_DEFINE_CLASS( HomeTachoBaseline, CoreGroup, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, "Home::TachoBaseline" )
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
  HomeTachoBaseline_UpdateLayout,
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
EW_END_OF_CLASS( HomeTachoBaseline )

/* Initializer for the class 'Home::TachoColor' */
void HomeTachoColor__Init( HomeTachoColor _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeTachoColor );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->UpColorbaseImg, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->DownColorbaseImg, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Front, &_this->_.XObject, 0 );
  ViewsLine__Init( &_this->ColorbaseUpLine, &_this->_.XObject, 0 );
  ViewsLine__Init( &_this->ColorbaseDownLine, &_this->_.XObject, 0 );
  ViewsLine__Init( &_this->YmaskUpEndLine, &_this->_.XObject, 0 );
  ViewsLine__Init( &_this->YmaskUpStartLine, &_this->_.XObject, 0 );
  ViewsLine__Init( &_this->YmaskDownStartLine, &_this->_.XObject, 0 );
  ViewsLine__Init( &_this->YmaskDownEndLine, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeTachoColor );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const002F );
  CoreRectView__OnSetBounds( &_this->UpColorbaseImg, _Const0030 );
  ViewsImage_OnSetAlignment( &_this->UpColorbaseImg, ViewsImageAlignmentAlignHorzRight 
  | ViewsImageAlignmentAlignVertBottom );
  CoreRectView__OnSetBounds( &_this->DownColorbaseImg, _Const0031 );
  ViewsImage_OnSetAlignment( &_this->DownColorbaseImg, ViewsImageAlignmentAlignHorzRight 
  | ViewsImageAlignmentAlignVertTop );
  CoreRectView__OnSetBounds( &_this->Front, _Const0032 );
  CoreLineView_OnSetPoint2((CoreLineView)&_this->ColorbaseUpLine, _Const0033 );
  CoreLineView_OnSetPoint1((CoreLineView)&_this->ColorbaseUpLine, _Const0034 );
  ViewsLine_OnSetVisible( &_this->ColorbaseUpLine, 0 );
  CoreLineView_OnSetPoint2((CoreLineView)&_this->ColorbaseDownLine, _Const0035 );
  CoreLineView_OnSetPoint1((CoreLineView)&_this->ColorbaseDownLine, _Const0036 );
  ViewsLine_OnSetVisible( &_this->ColorbaseDownLine, 0 );
  CoreLineView_OnSetPoint2((CoreLineView)&_this->YmaskUpEndLine, _Const0037 );
  CoreLineView_OnSetPoint1((CoreLineView)&_this->YmaskUpEndLine, _Const0038 );
  ViewsLine_OnSetColor( &_this->YmaskUpEndLine, _Const0039 );
  ViewsLine_OnSetVisible( &_this->YmaskUpEndLine, 0 );
  CoreLineView_OnSetPoint2((CoreLineView)&_this->YmaskUpStartLine, _Const003A );
  CoreLineView_OnSetPoint1((CoreLineView)&_this->YmaskUpStartLine, _Const003B );
  ViewsLine_OnSetColor( &_this->YmaskUpStartLine, _Const003C );
  ViewsLine_OnSetVisible( &_this->YmaskUpStartLine, 0 );
  CoreLineView_OnSetPoint2((CoreLineView)&_this->YmaskDownStartLine, _Const003D );
  CoreLineView_OnSetPoint1((CoreLineView)&_this->YmaskDownStartLine, _Const003E );
  ViewsLine_OnSetColor( &_this->YmaskDownStartLine, _Const0039 );
  ViewsLine_OnSetVisible( &_this->YmaskDownStartLine, 0 );
  CoreLineView_OnSetPoint2((CoreLineView)&_this->YmaskDownEndLine, _Const003F );
  CoreLineView_OnSetPoint1((CoreLineView)&_this->YmaskDownEndLine, _Const0040 );
  ViewsLine_OnSetColor( &_this->YmaskDownEndLine, _Const003C );
  ViewsLine_OnSetVisible( &_this->YmaskDownEndLine, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UpColorbaseImg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DownColorbaseImg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Front ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ColorbaseUpLine ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ColorbaseDownLine ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->YmaskUpEndLine ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->YmaskUpStartLine ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->YmaskDownStartLine ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->YmaskDownEndLine ), 0 );
  ViewsImage_OnSetBitmap( &_this->UpColorbaseImg, ((ResourcesBitmap)EwGetAutoObject( 
  &ResourceExternTachoUpColorbase, ResourcesExternBitmap )));
  ViewsImage_OnSetBitmap( &_this->DownColorbaseImg, ((ResourcesBitmap)EwGetAutoObject( 
  &ResourceExternTachoDownColorbase, ResourcesExternBitmap )));
  ViewsImage_OnSetBitmap( &_this->Front, EwLoadResource( &ResourceTachoFront, ResourcesBitmap ));

  /* Call the user defined constructor */
  HomeTachoColor_Init( _this, aArg );
}

/* Re-Initializer for the class 'Home::TachoColor' */
void HomeTachoColor__ReInit( HomeTachoColor _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->UpColorbaseImg );
  ViewsImage__ReInit( &_this->DownColorbaseImg );
  ViewsImage__ReInit( &_this->Front );
  ViewsLine__ReInit( &_this->ColorbaseUpLine );
  ViewsLine__ReInit( &_this->ColorbaseDownLine );
  ViewsLine__ReInit( &_this->YmaskUpEndLine );
  ViewsLine__ReInit( &_this->YmaskUpStartLine );
  ViewsLine__ReInit( &_this->YmaskDownStartLine );
  ViewsLine__ReInit( &_this->YmaskDownEndLine );
}

/* Finalizer method for the class 'Home::TachoColor' */
void HomeTachoColor__Done( HomeTachoColor _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->UpColorbaseImg );
  ViewsImage__Done( &_this->DownColorbaseImg );
  ViewsImage__Done( &_this->Front );
  ViewsLine__Done( &_this->ColorbaseUpLine );
  ViewsLine__Done( &_this->ColorbaseDownLine );
  ViewsLine__Done( &_this->YmaskUpEndLine );
  ViewsLine__Done( &_this->YmaskUpStartLine );
  ViewsLine__Done( &_this->YmaskDownStartLine );
  ViewsLine__Done( &_this->YmaskDownEndLine );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void HomeTachoColor_Init( HomeTachoColor _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  HomeTachoColor_UpdateYMask( _this, 0 );
}

/* 'C' function for method : 'Home::TachoColor.OnSetApsAngle()' */
void HomeTachoColor_OnSetApsAngle( HomeTachoColor _this, XInt32 value )
{
  if ( _this->ApsAngle != value )
  {
    _this->ApsAngle = value;
    HomeTachoColor_UpdateYMask( _this, value );
  }
}

/* 'C' function for method : 'Home::TachoColor.UpdateYMask()' */
void HomeTachoColor_UpdateYMask( HomeTachoColor _this, XInt32 aApsAngle )
{
  XInt32 UpperMaskY2 = (XInt32)( 88 - ( 0.987500f * aApsAngle ));
  XInt32 UpperMaskY1 = ( UpperMaskY2 - 46 ) + 1;
  XInt32 LowerMaskY1;
  XInt32 LowerMaskY2;

  if ( UpperMaskY1 < 0 )
    UpperMaskY1 = 0;

  LowerMaskY1 = (XInt32)( 137 + ( 0.987500f * aApsAngle ));
  LowerMaskY2 = ( LowerMaskY1 + 46 ) - 1;

  if ( EwGetRectH( _this->Super2.Bounds ) < LowerMaskY2 )
    LowerMaskY2 = EwGetRectH( _this->Super2.Bounds );

  if ( _this->ReferenceLineVisible )
  {
    CoreLineView_OnSetPoint1((CoreLineView)&_this->YmaskUpStartLine, EwSetPointY( 
    _this->YmaskUpStartLine.Super1.Point1, UpperMaskY1 ));
    CoreLineView_OnSetPoint2((CoreLineView)&_this->YmaskUpStartLine, EwSetPointY( 
    _this->YmaskUpStartLine.Super1.Point2, UpperMaskY1 ));
    CoreLineView_OnSetPoint1((CoreLineView)&_this->YmaskUpEndLine, EwSetPointY( 
    _this->YmaskUpEndLine.Super1.Point1, UpperMaskY2 ));
    CoreLineView_OnSetPoint2((CoreLineView)&_this->YmaskUpEndLine, EwSetPointY( 
    _this->YmaskUpEndLine.Super1.Point2, UpperMaskY2 ));
    CoreLineView_OnSetPoint1((CoreLineView)&_this->YmaskDownStartLine, EwSetPointY( 
    _this->YmaskDownStartLine.Super1.Point1, LowerMaskY1 ));
    CoreLineView_OnSetPoint2((CoreLineView)&_this->YmaskDownStartLine, EwSetPointY( 
    _this->YmaskDownStartLine.Super1.Point2, LowerMaskY1 ));
    CoreLineView_OnSetPoint1((CoreLineView)&_this->YmaskDownEndLine, EwSetPointY( 
    _this->YmaskDownEndLine.Super1.Point1, LowerMaskY2 ));
    CoreLineView_OnSetPoint2((CoreLineView)&_this->YmaskDownEndLine, EwSetPointY( 
    _this->YmaskDownEndLine.Super1.Point2, LowerMaskY2 ));
  }

  DeviceInterfaceVehicleDeviceClass_SetTachoYMask( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), UpperMaskY1, UpperMaskY2, LowerMaskY1, LowerMaskY2 );
}

/* 'C' function for method : 'Home::TachoColor.UpdateColorbase()' */
void HomeTachoColor_UpdateColorbase( HomeTachoColor _this, XInt32 aApsAngle )
{
  XRect ColorRect = _this->Super2.Bounds;
  XInt32 UpHalfHeight;
  XInt32 DownHalfHeight;
  XRect UpperColorbase;
  XRect LowerColorbase;

  ColorRect.Point1.X = ( ColorRect.Point1.X - 8 );
  ColorRect.Point2.X = ( ColorRect.Point2.X - 8 );

  if ( ColorRect.Point1.X < 0 )
    ColorRect.Point1.X = 0;

  if ( EwGetRectH( _this->Super2.Bounds ) < EwGetRectH( ColorRect ))
    ColorRect = EwSetRectH( ColorRect, EwGetRectH( _this->Super2.Bounds ));

  UpHalfHeight = (XInt32)( 1.137500f * aApsAngle );
  ColorRect.Point1.Y = (( 88 - UpHalfHeight ) - 46 );

  if ( 0 > ColorRect.Point1.Y )
    ColorRect.Point1.Y = 0;

  DownHalfHeight = (XInt32)( 1.250000f * aApsAngle );
  ColorRect.Point2.Y = (( 137 + DownHalfHeight ) + 46 );

  if ( EwGetRectH( _this->Super2.Bounds ) < ColorRect.Point2.Y )
    ColorRect.Point2.Y = EwGetRectH( _this->Super2.Bounds );

  CoreLineView_OnSetPoint1((CoreLineView)&_this->ColorbaseUpLine, EwSetPointY( _this->ColorbaseUpLine.Super1.Point1, 
  ColorRect.Point1.Y ));
  CoreLineView_OnSetPoint2((CoreLineView)&_this->ColorbaseUpLine, EwSetPointY( _this->ColorbaseUpLine.Super1.Point2, 
  ColorRect.Point1.Y ));
  CoreLineView_OnSetPoint1((CoreLineView)&_this->ColorbaseDownLine, EwSetPointY( 
  _this->ColorbaseDownLine.Super1.Point1, ColorRect.Point2.Y ));
  CoreLineView_OnSetPoint2((CoreLineView)&_this->ColorbaseDownLine, EwSetPointY( 
  _this->ColorbaseDownLine.Super1.Point2, ColorRect.Point2.Y ));
  UpperColorbase = ColorRect;
  LowerColorbase = ColorRect;
  UpperColorbase.Point2.Y = _this->UpColorbaseImg.Super1.Bounds.Point2.Y;
  LowerColorbase.Point1.Y = _this->DownColorbaseImg.Super1.Bounds.Point1.Y;
  DeviceInterfaceVehicleDeviceClass_SetTachoColorbaseRect( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), UpperColorbase, LowerColorbase );
}

/* 'C' function for method : 'Home::TachoColor.OnSetEngineSpeed()' */
void HomeTachoColor_OnSetEngineSpeed( HomeTachoColor _this, XInt32 value )
{
  if ( _this->EngineSpeed != value )
  {
    _this->EngineSpeed = value;
    HomeTachoColor_UpdateBounds( _this, value );
  }
}

/* 'C' function for method : 'Home::TachoColor.UpdateBounds()' */
void HomeTachoColor_UpdateBounds( HomeTachoColor _this, XInt32 aEngineSpeed )
{
  XFloat EngineSpeedToXPositionFactor;
  XRect CircularSectorBounds;
  XInt32 CircularSectorBoundsWidth;

  if ( EnumTachoFullScaleRPM10000 == _this->FullScaleType )
    EngineSpeedToXPositionFactor = 0.042300f;
  else
    EngineSpeedToXPositionFactor = 0.028200f;

  CircularSectorBounds = _this->Super2.Bounds;
  CircularSectorBoundsWidth = EwGetRectW( _this->Super2.Bounds );
  CircularSectorBounds.Point2.X = (XInt32)EwMathCeil( 34.000000f + ( EngineSpeedToXPositionFactor 
  * (XFloat)aEngineSpeed ));

  if ( 457 < CircularSectorBounds.Point2.X )
    CircularSectorBounds.Point2.X = 457;

  CircularSectorBounds.Point1.X = ( CircularSectorBounds.Point2.X - CircularSectorBoundsWidth );
  CoreRectView__OnSetBounds( _this, CircularSectorBounds );
}

/* 'C' function for method : 'Home::TachoColor.OnSetReferenceLineVisible()' */
void HomeTachoColor_OnSetReferenceLineVisible( HomeTachoColor _this, XBool value )
{
  if ( _this->ReferenceLineVisible != value )
  {
    _this->ReferenceLineVisible = value;
    ViewsLine_OnSetVisible( &_this->ColorbaseUpLine, value );
    ViewsLine_OnSetVisible( &_this->ColorbaseDownLine, value );
    ViewsLine_OnSetVisible( &_this->YmaskUpStartLine, value );
    ViewsLine_OnSetVisible( &_this->YmaskUpEndLine, value );
    ViewsLine_OnSetVisible( &_this->YmaskDownStartLine, value );
    ViewsLine_OnSetVisible( &_this->YmaskDownEndLine, value );
  }
}

/* 'C' function for method : 'Home::TachoColor.SetEngineData()' */
void HomeTachoColor_SetEngineData( HomeTachoColor _this, XInt32 aEngineSpeed, XInt32 
  aApsAngle )
{
  XBool NeedReloadColorbase = 0;

  if ( _this->EngineSpeed != aEngineSpeed )
  {
    HomeTachoColor_OnSetEngineSpeed( _this, aEngineSpeed );
    NeedReloadColorbase = 1;
  }

  if ( _this->ApsAngle != aApsAngle )
  {
    HomeTachoColor_OnSetApsAngle( _this, aApsAngle );
    NeedReloadColorbase = 1;
  }

  if ( NeedReloadColorbase )
  {
    HomeTachoColor_UpdateColorbase( _this, aApsAngle );
    HomeTachoColor_ReloadColorbase( _this );
  }
}

/* 'C' function for method : 'Home::TachoColor.ReloadColorbase()' */
void HomeTachoColor_ReloadColorbase( HomeTachoColor _this )
{
  ResourcesExternBitmap_OnSetName( EwGetAutoObject( &ResourceExternTachoUpColorbase, 
  ResourcesExternBitmap ), EwLoadString( &ResourceTACHO_COLORBASE_UP ));
  ResourcesExternBitmap_Reload( EwGetAutoObject( &ResourceExternTachoUpColorbase, 
  ResourcesExternBitmap ));

  if ( _this->DownPartEnabled )
  {
    ResourcesExternBitmap_OnSetName( EwGetAutoObject( &ResourceExternTachoDownColorbase, 
    ResourcesExternBitmap ), EwLoadString( &ResourceTACHO_COLORBASE_DOWN ));
    ResourcesExternBitmap_Reload( EwGetAutoObject( &ResourceExternTachoDownColorbase, 
    ResourcesExternBitmap ));
    ViewsImage_OnSetVisible( &_this->DownColorbaseImg, 1 );
  }
  else
    ViewsImage_OnSetVisible( &_this->DownColorbaseImg, 0 );
}

/* Variants derived from the class : 'Home::TachoColor' */
EW_DEFINE_CLASS_VARIANTS( HomeTachoColor )
EW_END_OF_CLASS_VARIANTS( HomeTachoColor )

/* Virtual Method Table (VMT) for the class : 'Home::TachoColor' */
EW_DEFINE_CLASS( HomeTachoColor, CoreGroup, UpColorbaseImg, UpColorbaseImg, UpColorbaseImg, 
                 UpColorbaseImg, ApsAngle, ApsAngle, "Home::TachoColor" )
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
EW_END_OF_CLASS( HomeTachoColor )

/* Initializer for the class 'Home::TachoScale' */
void HomeTachoScale__Init( HomeTachoScale _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeTachoScale );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->Background, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeTachoScale );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0041 );
  CoreRectView__OnSetBounds( &_this->Background, _Const0041 );
  CoreGroup__Add( _this, ((CoreView)&_this->Background ), 0 );
  ViewsImage_OnSetBitmap( &_this->Background, EwLoadResource( &ResourceTachoNumberBG, 
  ResourcesBitmap ));

  /* Call the user defined constructor */
  HomeTachoScale_Init( _this, aArg );
}

/* Re-Initializer for the class 'Home::TachoScale' */
void HomeTachoScale__ReInit( HomeTachoScale _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->Background );
}

/* Finalizer method for the class 'Home::TachoScale' */
void HomeTachoScale__Done( HomeTachoScale _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->Background );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void HomeTachoScale_Init( HomeTachoScale _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );
}

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void HomeTachoScale_UpdateLayout( HomeTachoScale _this, XPoint aSize )
{
  CoreGroup_UpdateLayout((CoreGroup)_this, aSize );
  CoreGroup_RemoveAll((CoreGroup)_this );
  CoreGroup__Add( _this, ((CoreView)&_this->Background ), 0 );

  if ( EnumTachoFullScaleRPM10000 == _this->FullScaleType )
    HomeTachoScale_Draw10000rpmScale( _this );
  else
    HomeTachoScale_Draw15000rpmScale( _this );
}

/* 'C' function for method : 'Home::TachoScale.OnSetRedZoneBeginRPM()' */
void HomeTachoScale_OnSetRedZoneBeginRPM( HomeTachoScale _this, XInt32 value )
{
  if ( _this->RedZoneBeginRPM != value )
  {
    _this->RedZoneBeginRPM = value;
    CoreGroup_InvalidateLayout((CoreGroup)_this );
  }
}

/* 'C' function for method : 'Home::TachoScale.OnSetFullScaleType()' */
void HomeTachoScale_OnSetFullScaleType( HomeTachoScale _this, XEnum value )
{
  if ( _this->FullScaleType != value )
  {
    _this->FullScaleType = value;
    CoreGroup_InvalidateLayout((CoreGroup)_this );
  }
}

/* 'C' function for method : 'Home::TachoScale.OnSetCurrentEngineSpeed()' */
void HomeTachoScale_OnSetCurrentEngineSpeed( HomeTachoScale _this, XUInt32 value )
{
  if ( _this->CurrentEngineSpeed != value )
  {
    _this->CurrentEngineSpeed = value;

    if ( EnumTachoFullScaleRPM10000 == _this->FullScaleType )
      HomeTachoScale_Highlight1000rpmScale( _this );
    else
      HomeTachoScale_Highlight1500rpmScale( _this );
  }
}

/* 'C' function for method : 'Home::TachoScale.Draw10000rpmScale()' */
void HomeTachoScale_Draw10000rpmScale( HomeTachoScale _this )
{
  XInt32 i;
  XInt32 RedZoneBeginIdx = _this->RedZoneBeginRPM / 500;
  XInt32 StartX = 13;

  for ( i = 0; i < 21; i++ )
  {
    ViewsImage ScaleImage = EwNewObject( ViewsImage, 0 );

    if ( _this->HighlightImages[ EwCheckIndex( i, 21 )] == 0 )
      _this->HighlightImages[ EwCheckIndex( i, 21 )] = EwNewObject( ViewsImage, 
      0 );

    if (( i % 2 ) == 0 )
    {
      XInt32 Number = i / 2;

      if (( i < RedZoneBeginIdx ) || ( Number < 8 ))
      {
        ViewsImage_OnSetBitmap( ScaleImage, EwLoadResource( &ResourceTachoNumberOff, 
        ResourcesBitmap ));
        ViewsImage_OnSetFrameNumber( ScaleImage, Number );
        ViewsImage_OnSetBitmap( _this->HighlightImages[ EwCheckIndex( i, 21 )], 
        EwLoadResource( &ResourceTachoNumberOn, ResourcesBitmap ));
        ViewsImage_OnSetFrameNumber( _this->HighlightImages[ EwCheckIndex( i, 21 )], 
        Number );
      }
      else
      {
        ViewsImage_OnSetBitmap( ScaleImage, EwLoadResource( &ResourceTachoNumberOffRed, 
        ResourcesBitmap ));
        ViewsImage_OnSetFrameNumber( ScaleImage, Number - 8 );
        ViewsImage_OnSetBitmap( _this->HighlightImages[ EwCheckIndex( i, 21 )], 
        EwLoadResource( &ResourceTachoNumberOnRed, ResourcesBitmap ));
        ViewsImage_OnSetFrameNumber( _this->HighlightImages[ EwCheckIndex( i, 21 )], 
        Number - 8 );
      }
    }
    else
      if ( i < RedZoneBeginIdx )
      {
        ViewsImage_OnSetBitmap( ScaleImage, EwLoadResource( &ResourceTachoNumberDot, 
        ResourcesBitmap ));
        ViewsImage_OnSetBitmap( _this->HighlightImages[ EwCheckIndex( i, 21 )], 
        EwLoadResource( &ResourceTachoNumberDot, ResourcesBitmap ));
        ViewsImage_OnSetFrameNumber( _this->HighlightImages[ EwCheckIndex( i, 21 )], 
        1 );
      }
      else
      {
        ViewsImage_OnSetBitmap( ScaleImage, EwLoadResource( &ResourceTachoNumberDotRed, 
        ResourcesBitmap ));
        ViewsImage_OnSetBitmap( _this->HighlightImages[ EwCheckIndex( i, 21 )], 
        EwLoadResource( &ResourceTachoNumberDotRed, ResourcesBitmap ));
        ViewsImage_OnSetFrameNumber( _this->HighlightImages[ EwCheckIndex( i, 21 )], 
        1 );
      }

    CoreRectView__OnSetBounds( ScaleImage, EwNewRect( StartX, 10, StartX + ScaleImage->Bitmap->FrameSize.X, 
    10 + ScaleImage->Bitmap->FrameSize.Y ));
    ViewsImage_OnSetVisible( ScaleImage, 1 );
    CoreGroup__Add( _this, ((CoreView)ScaleImage ), 0 );
    CoreRectView__OnSetBounds( _this->HighlightImages[ EwCheckIndex( i, 21 )], ScaleImage->Super1.Bounds );
    ViewsImage_OnSetVisible( _this->HighlightImages[ EwCheckIndex( i, 21 )], 0 );
    CoreGroup__Add( _this, ((CoreView)_this->HighlightImages[ EwCheckIndex( i, 21 )]), 
    0 );
    StartX += 21;
  }
}

/* 'C' function for method : 'Home::TachoScale.Draw15000rpmScale()' */
void HomeTachoScale_Draw15000rpmScale( HomeTachoScale _this )
{
  XInt32 i;
  XInt32 RedZoneBeginIdx = _this->RedZoneBeginRPM / 1000;
  XInt32 StartX = 13;

  for ( i = 0; i < 16; i++ )
  {
    ViewsImage ScaleImage = EwNewObject( ViewsImage, 0 );

    if ( _this->HighlightImages[ EwCheckIndex( i, 21 )] == 0 )
      _this->HighlightImages[ EwCheckIndex( i, 21 )] = EwNewObject( ViewsImage, 
      0 );

    if (( i == 0 ) || (( i % 2 ) == 1 ))
    {
      XInt32 Number = i;

      if (( i < RedZoneBeginIdx ) || ( Number < 8 ))
      {
        ViewsImage_OnSetBitmap( ScaleImage, EwLoadResource( &ResourceTachoNumberOff, 
        ResourcesBitmap ));
        ViewsImage_OnSetFrameNumber( ScaleImage, Number );
        ViewsImage_OnSetBitmap( _this->HighlightImages[ EwCheckIndex( i, 21 )], 
        EwLoadResource( &ResourceTachoNumberOn, ResourcesBitmap ));
        ViewsImage_OnSetFrameNumber( _this->HighlightImages[ EwCheckIndex( i, 21 )], 
        Number );
      }
      else
      {
        ViewsImage_OnSetBitmap( ScaleImage, EwLoadResource( &ResourceTachoNumberOffRed, 
        ResourcesBitmap ));
        ViewsImage_OnSetFrameNumber( ScaleImage, Number - 8 );
        ViewsImage_OnSetBitmap( _this->HighlightImages[ EwCheckIndex( i, 21 )], 
        EwLoadResource( &ResourceTachoNumberOnRed, ResourcesBitmap ));
        ViewsImage_OnSetFrameNumber( _this->HighlightImages[ EwCheckIndex( i, 21 )], 
        Number - 8 );
      }
    }
    else
      if ( i < RedZoneBeginIdx )
      {
        ViewsImage_OnSetBitmap( ScaleImage, EwLoadResource( &ResourceTachoNumberDot, 
        ResourcesBitmap ));
        ViewsImage_OnSetBitmap( _this->HighlightImages[ EwCheckIndex( i, 21 )], 
        EwLoadResource( &ResourceTachoNumberDot, ResourcesBitmap ));
        ViewsImage_OnSetFrameNumber( _this->HighlightImages[ EwCheckIndex( i, 21 )], 
        1 );
      }
      else
      {
        ViewsImage_OnSetBitmap( ScaleImage, EwLoadResource( &ResourceTachoNumberDotRed, 
        ResourcesBitmap ));
        ViewsImage_OnSetBitmap( _this->HighlightImages[ EwCheckIndex( i, 21 )], 
        EwLoadResource( &ResourceTachoNumberDotRed, ResourcesBitmap ));
        ViewsImage_OnSetFrameNumber( _this->HighlightImages[ EwCheckIndex( i, 21 )], 
        1 );
      }

    CoreRectView__OnSetBounds( ScaleImage, EwNewRect( StartX, 10, StartX + ScaleImage->Bitmap->FrameSize.X, 
    10 + ScaleImage->Bitmap->FrameSize.Y ));
    ViewsImage_OnSetVisible( ScaleImage, 1 );
    CoreGroup__Add( _this, ((CoreView)ScaleImage ), 0 );
    CoreRectView__OnSetBounds( _this->HighlightImages[ EwCheckIndex( i, 21 )], ScaleImage->Super1.Bounds );
    ViewsImage_OnSetVisible( _this->HighlightImages[ EwCheckIndex( i, 21 )], 0 );
    CoreGroup__Add( _this, ((CoreView)_this->HighlightImages[ EwCheckIndex( i, 21 )]), 
    0 );
    StartX += 28;
  }
}

/* 'C' function for method : 'Home::TachoScale.Highlight1000rpmScale()' */
void HomeTachoScale_Highlight1000rpmScale( HomeTachoScale _this )
{
  XInt32 HighlightStartIdx = (XInt32)( _this->CurrentEngineSpeed / 500 );
  XInt32 i;

  for ( i = 0; i < 21; i++ )
    if ( i <= HighlightStartIdx )
      ViewsImage_OnSetVisible( _this->HighlightImages[ EwCheckIndex( i, 21 )], 1 );
    else
      ViewsImage_OnSetVisible( _this->HighlightImages[ EwCheckIndex( i, 21 )], 0 );
}

/* 'C' function for method : 'Home::TachoScale.Highlight1500rpmScale()' */
void HomeTachoScale_Highlight1500rpmScale( HomeTachoScale _this )
{
  XInt32 HighlightStartIdx = (XInt32)( _this->CurrentEngineSpeed / 1000 );
  XInt32 i;

  for ( i = 0; i < 16; i++ )
    if ( i <= HighlightStartIdx )
      ViewsImage_OnSetVisible( _this->HighlightImages[ EwCheckIndex( i, 21 )], 1 );
    else
      ViewsImage_OnSetVisible( _this->HighlightImages[ EwCheckIndex( i, 21 )], 0 );
}

/* Variants derived from the class : 'Home::TachoScale' */
EW_DEFINE_CLASS_VARIANTS( HomeTachoScale )
EW_END_OF_CLASS_VARIANTS( HomeTachoScale )

/* Virtual Method Table (VMT) for the class : 'Home::TachoScale' */
EW_DEFINE_CLASS( HomeTachoScale, CoreGroup, HighlightImages, Background, Background, 
                 Background, RedZoneBeginRPM, RedZoneBeginRPM, "Home::TachoScale" )
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
  HomeTachoScale_UpdateLayout,
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
EW_END_OF_CLASS( HomeTachoScale )

/* Initializer for the class 'Home::HOM11_TachoVisualizer' */
void HomeHOM11_TachoVisualizer__Init( HomeHOM11_TachoVisualizer _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  HomeBaseHome__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeHOM11_TachoVisualizer );

  /* ... then construct all embedded objects */
  HomeTachoBaseline__Init( &_this->TachoBaseline, &_this->_.XObject, 0 );
  HomeTachoColor__Init( &_this->CircularSector, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->UpdateTimer, &_this->_.XObject, 0 );
  HomeTachoScale__Init( &_this->TachoScale, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->RpmImg, &_this->_.XObject, 0 );
  ViewsWallpaper__Init( &_this->StatusbarShadow, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->VVAIndicatorImage, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeHOM11_TachoVisualizer );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Super2.BlackBG, _Const000F );
  CoreRectView__OnSetBounds( &_this->TachoBaseline, _Const000F );
  CoreRectView__OnSetBounds( &_this->CircularSector, _Const0042 );
  HomeTachoColor_OnSetReferenceLineVisible( &_this->CircularSector, 0 );
  _this->CircularSector.DownPartEnabled = 1;
  CoreTimer_OnSetPeriod( &_this->UpdateTimer, 40 );
  CoreTimer_OnSetEnabled( &_this->UpdateTimer, 1 );
  CoreRectView__OnSetBounds( &_this->TachoScale, _Const0043 );
  CoreRectView__OnSetBounds( &_this->RpmImg, _Const0044 );
  ViewsImage_OnSetFrameNumber( &_this->RpmImg, 0 );
  ViewsImage_OnSetVisible( &_this->RpmImg, 1 );
  CoreRectView__OnSetBounds( &_this->StatusbarShadow, _Const0045 );
  CoreRectView__OnSetBounds( &_this->VVAIndicatorImage, _Const0046 );
  ViewsImage_OnSetFrameNumber( &_this->VVAIndicatorImage, 1 );
  ViewsImage_OnSetVisible( &_this->VVAIndicatorImage, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TachoBaseline ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CircularSector ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TachoScale ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RpmImg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->StatusbarShadow ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->VVAIndicatorImage ), 0 );
  _this->UpdateTimer.OnTrigger = EwNewSlot( _this, HomeHOM11_TachoVisualizer_OnUpdateSlot );
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, HomeHOM11_TachoVisualizer_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );
  ViewsImage_OnSetBitmap( &_this->RpmImg, EwLoadResource( &ResourceTacho1000R, ResourcesBitmap ));
  ViewsWallpaper_OnSetBitmap( &_this->StatusbarShadow, EwLoadResource( &ResourceTachoStatusbarShadow, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->VVAIndicatorImage, EwLoadResource( &ResourceTachoVVA, 
  ResourcesBitmap ));

  /* Call the user defined constructor */
  HomeHOM11_TachoVisualizer_Init( _this, aArg );
}

/* Re-Initializer for the class 'Home::HOM11_TachoVisualizer' */
void HomeHOM11_TachoVisualizer__ReInit( HomeHOM11_TachoVisualizer _this )
{
  /* At first re-initialize the super class ... */
  HomeBaseHome__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  HomeTachoBaseline__ReInit( &_this->TachoBaseline );
  HomeTachoColor__ReInit( &_this->CircularSector );
  CoreTimer__ReInit( &_this->UpdateTimer );
  HomeTachoScale__ReInit( &_this->TachoScale );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
  ViewsImage__ReInit( &_this->RpmImg );
  ViewsWallpaper__ReInit( &_this->StatusbarShadow );
  ViewsImage__ReInit( &_this->VVAIndicatorImage );
}

/* Finalizer method for the class 'Home::HOM11_TachoVisualizer' */
void HomeHOM11_TachoVisualizer__Done( HomeHOM11_TachoVisualizer _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  HomeTachoBaseline__Done( &_this->TachoBaseline );
  HomeTachoColor__Done( &_this->CircularSector );
  CoreTimer__Done( &_this->UpdateTimer );
  HomeTachoScale__Done( &_this->TachoScale );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );
  ViewsImage__Done( &_this->RpmImg );
  ViewsWallpaper__Done( &_this->StatusbarShadow );
  ViewsImage__Done( &_this->VVAIndicatorImage );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void HomeHOM11_TachoVisualizer_Init( HomeHOM11_TachoVisualizer _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0047 ));
  HomeHOM11_TachoVisualizer_OnSetFullScaleType( _this, (XEnum)DeviceInterfaceSystemDeviceClass_GetSystemStatus( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ), 
  EnumSystemStatusTACHO_FULLSCALE ));
  HomeHOM11_TachoVisualizer_OnSetRedZoneBeginRPM( _this, DeviceInterfaceSystemDeviceClass_GetSystemStatus( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ), 
  EnumSystemStatusTACHO_REDZONE_BEGIN ));
  HomeHOM11_TachoVisualizer_UpdateVVAIndicator( _this );
}

/* 'C' function for method : 'Home::HOM11_TachoVisualizer.OnLongEnterKeyActivated()' */
void HomeHOM11_TachoVisualizer_OnLongEnterKeyActivated( HomeHOM11_TachoVisualizer _this )
{
  if ( 1 == _this->Super3.KeyHandler.RepetitionCount )
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( InfoINF01_MeterDisplaySettingMenu, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Home::HOM11_TachoVisualizer.OnUpdateSlot()' */
void HomeHOM11_TachoVisualizer_OnUpdateSlot( HomeHOM11_TachoVisualizer _this, XObject 
  sender )
{
  XUInt32 EngineSpeed;
  XUInt32 ApsAngle;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ApsAngle = 0;

  if ( CoreGroup__IsCurrentDialog( _this ))
  {
    if ( DeviceInterfaceVehicleDeviceClass_OnGetIsTimeoutError2Detected( EwGetAutoObject( 
        &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
      EngineSpeed = 0;
    else
    {
      DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        EnumVehicleRxTypeENGINE_SPEED );
      EngineSpeed = VehicleData->DataUInt32;
      VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeAPS_ANGLE );
      ApsAngle = VehicleData->DataUInt32;
    }

    HomeTachoColor_SetEngineData( &_this->CircularSector, (XInt32)EngineSpeed, (XInt32)ApsAngle );
    HomeTachoScale_OnSetCurrentEngineSpeed( &_this->TachoScale, EngineSpeed );
  }
}

/* 'C' function for method : 'Home::HOM11_TachoVisualizer.OnSetFullScaleType()' */
void HomeHOM11_TachoVisualizer_OnSetFullScaleType( HomeHOM11_TachoVisualizer _this, 
  XEnum value )
{
  if ( _this->FullScaleType != value )
  {
    _this->FullScaleType = value;
    HomeTachoScale_OnSetFullScaleType( &_this->TachoScale, value );
    HomeTachoBaseline_OnSetFullScaleType( &_this->TachoBaseline, value );
    _this->CircularSector.FullScaleType = value;
  }
}

/* 'C' function for method : 'Home::HOM11_TachoVisualizer.OnSetRedZoneBeginRPM()' */
void HomeHOM11_TachoVisualizer_OnSetRedZoneBeginRPM( HomeHOM11_TachoVisualizer _this, 
  XInt32 value )
{
  if ( _this->RedZoneBeginRPM != value )
  {
    _this->RedZoneBeginRPM = value;
    HomeTachoScale_OnSetRedZoneBeginRPM( &_this->TachoScale, value );
    HomeTachoBaseline_OnSetRedZoneBeginRPM( &_this->TachoBaseline, value );
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void HomeHOM11_TachoVisualizer_OnVehicleDataReceivedSlot( HomeHOM11_TachoVisualizer _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if ( VehicleData != 0 )
    switch ( VehicleData->RxType )
    {
      case EnumVehicleRxTypeVVA_INDICATOR :
      case EnumVehicleRxTypeTIMEOUT_ERROR2_UPDATED :
        HomeHOM11_TachoVisualizer_UpdateVVAIndicator( _this );
      break;

      case EnumVehicleRxTypeTACHO_SETTING :
      {
        HomeHOM11_TachoVisualizer_OnSetFullScaleType( _this, (XEnum)DeviceInterfaceSystemDeviceClass_GetSystemStatus( 
        EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ), 
        EnumSystemStatusTACHO_FULLSCALE ));
        HomeHOM11_TachoVisualizer_OnSetRedZoneBeginRPM( _this, DeviceInterfaceSystemDeviceClass_GetSystemStatus( 
        EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ), 
        EnumSystemStatusTACHO_REDZONE_BEGIN ));
      }
      break;

      default :; 
    }
}

/* 'C' function for method : 'Home::HOM11_TachoVisualizer.UpdateVVAIndicator()' */
void HomeHOM11_TachoVisualizer_UpdateVVAIndicator( HomeHOM11_TachoVisualizer _this )
{
  if ( !DeviceInterfaceVehicleDeviceClass_OnGetIsTimeoutError2Detected( EwGetAutoObject( 
      &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
  {
    DeviceInterfaceVehicleDataClass VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( 
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
      EnumVehicleRxTypeVVA_INDICATOR );

    if ( 1 == VehicleData->DataUInt32 )
      ViewsImage_OnSetVisible( &_this->VVAIndicatorImage, 1 );
    else
      ViewsImage_OnSetVisible( &_this->VVAIndicatorImage, 0 );
  }
}

/* Variants derived from the class : 'Home::HOM11_TachoVisualizer' */
EW_DEFINE_CLASS_VARIANTS( HomeHOM11_TachoVisualizer )
EW_END_OF_CLASS_VARIANTS( HomeHOM11_TachoVisualizer )

/* Virtual Method Table (VMT) for the class : 'Home::HOM11_TachoVisualizer' */
EW_DEFINE_CLASS( HomeHOM11_TachoVisualizer, HomeBaseHome, TachoBaseline, TachoBaseline, 
                 TachoBaseline, TachoBaseline, RedZoneBeginRPM, RedZoneBeginRPM, 
                 "Home::HOM11_TachoVisualizer" )
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
  HomeBaseHome_OnShortEnterKeyActivated,
  HomeBaseHome_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  HomeHOM11_TachoVisualizer_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  HomeBaseHome_ReturnToHome,
EW_END_OF_CLASS( HomeHOM11_TachoVisualizer )

/* User defined constant: 'Home::SV_WITHOUT_SPEED_LIMIT' */
const XColor HomeSV_WITHOUT_SPEED_LIMIT = { 0x44, 0x4A, 0xFF, 0xFF };

/* User defined constant: 'Home::SV_WITH_SPEED_LIMIT' */
const XColor HomeSV_WITH_SPEED_LIMIT = { 0x31, 0xA6, 0x8F, 0xFF };

/* User defined constant: 'Home::SV_OVER_SPEED_LIMIT' */
const XColor HomeSV_OVER_SPEED_LIMIT = { 0xEA, 0x73, 0x0A, 0xFF };

/* User defined constant: 'Home::CIRCLE_CENTER_POS' */
const XPoint HomeCIRCLE_CENTER_POS = { 243, 123 };

/* Initializer for the class 'Home::SpeedCircle' */
void HomeSpeedCircle__Init( HomeSpeedCircle _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( HomeSpeedCircle );

  /* ... then construct all embedded objects */
  EffectsInt32Effect__Init( &_this->SpeedCircleResizeEffect, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->GradientLine, &_this->_.XObject, 0 );
  ViewsWarpImage__Init( &_this->SpeedCircleImage, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( HomeSpeedCircle );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const002E );
  EffectsEffect_OnSetElasticity((EffectsEffect)&_this->SpeedCircleResizeEffect, 
  0.000000f );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->SpeedCircleResizeEffect, 
  1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->SpeedCircleResizeEffect, 
  50 );
  _this->SpeedCircleResizeEffect.Value2 = 0;
  CoreRectView__OnSetBounds( &_this->GradientLine, _Const0048 );
  ViewsImage_OnSetVisible( &_this->GradientLine, 0 );
  CoreView_OnSetStackingPriority((CoreView)&_this->SpeedCircleImage, 0 );
  CoreQuadView__OnSetPoint4( &_this->SpeedCircleImage, _Const0049 );
  CoreQuadView__OnSetPoint3( &_this->SpeedCircleImage, _Const004A );
  CoreQuadView__OnSetPoint2( &_this->SpeedCircleImage, _Const004B );
  CoreQuadView__OnSetPoint1( &_this->SpeedCircleImage, _Const004C );
  ViewsWarpView_OnSetSourceAnchor((ViewsWarpView)&_this->SpeedCircleImage, _Const004D );
  ViewsWarpView_OnSetVisible((ViewsWarpView)&_this->SpeedCircleImage, 0 );
  ViewsWarpImage_OnSetColor( &_this->SpeedCircleImage, _Const004E );
  CoreGroup__Add( _this, ((CoreView)&_this->GradientLine ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SpeedCircleImage ), 0 );
  _this->SpeedCircleResizeEffect.Super1.OnFinished = EwNullSlot;
  _this->SpeedCircleResizeEffect.Super1.OnAnimate = EwNewSlot( _this, HomeSpeedCircle_OnValueChangeSlot );
  ViewsImage_OnSetBitmap( &_this->GradientLine, EwLoadResource( &ResourceGradientCircleWhite, 
  ResourcesBitmap ));
  ViewsWarpImage_OnSetBitmap( &_this->SpeedCircleImage, EwLoadResource( &ResourceSpeedLimitCircle, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'Home::SpeedCircle' */
void HomeSpeedCircle__ReInit( HomeSpeedCircle _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  EffectsInt32Effect__ReInit( &_this->SpeedCircleResizeEffect );
  ViewsImage__ReInit( &_this->GradientLine );
  ViewsWarpImage__ReInit( &_this->SpeedCircleImage );
}

/* Finalizer method for the class 'Home::SpeedCircle' */
void HomeSpeedCircle__Done( HomeSpeedCircle _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  EffectsInt32Effect__Done( &_this->SpeedCircleResizeEffect );
  ViewsImage__Done( &_this->GradientLine );
  ViewsWarpImage__Done( &_this->SpeedCircleImage );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Home::SpeedCircle.OnValueChangeSlot()' */
void HomeSpeedCircle_OnValueChangeSlot( HomeSpeedCircle _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->SpeedCircleResizeEffect.Value == 0 )
    ViewsWarpView_OnSetVisible((ViewsWarpView)&_this->SpeedCircleImage, 0 );
  else
  {
    XFloat RelativeValue;
    XFloat Scale;
    ViewsWarpView_OnSetVisible((ViewsWarpView)&_this->SpeedCircleImage, 1 );

    if ( _this->SpeedLimit > 0 )
    {
      RelativeValue = (XFloat)_this->SpeedCircleResizeEffect.Value / (XFloat)_this->SpeedLimit;
      ViewsImage_OnSetVisible( &_this->GradientLine, 1 );
    }
    else
    {
      RelativeValue = (XFloat)_this->SpeedCircleResizeEffect.Value / 100.000000f;
      ViewsImage_OnSetVisible( &_this->GradientLine, 0 );
    }

    if ( RelativeValue > 1.286000f )
      RelativeValue = 1.286000f;

    Scale = RelativeValue * 280;
    Scale = EwMathRound( Scale );
    Scale = Scale * 0.005500f;

    if ( ViewsImage_OnGetVisible( &_this->GradientLine ))
    {
      if ( _this->SpeedCircleResizeEffect.Value > _this->SpeedLimit )
        ViewsWarpImage_OnSetColor( &_this->SpeedCircleImage, HomeSV_OVER_SPEED_LIMIT );
      else
        ViewsWarpImage_OnSetColor( &_this->SpeedCircleImage, HomeSV_WITH_SPEED_LIMIT );
    }
    else
      ViewsWarpImage_OnSetColor( &_this->SpeedCircleImage, HomeSV_WITHOUT_SPEED_LIMIT );

    ViewsWarpView_OnSetVisible((ViewsWarpView)&_this->SpeedCircleImage, 1 );
    ViewsWarpView_RotateAndScale((ViewsWarpView)&_this->SpeedCircleImage, HomeCIRCLE_CENTER_POS, 
    0.000000f, Scale, Scale );
  }
}

/* 'C' function for method : 'Home::SpeedCircle.OnSetSpeedValue()' */
void HomeSpeedCircle_OnSetSpeedValue( HomeSpeedCircle _this, XInt32 value )
{
  HomeSpeedCircle_StartAnimation( _this, _this->SpeedValue, value );
  _this->SpeedValue = value;
}

/* 'C' function for method : 'Home::SpeedCircle.StartAnimation()' */
void HomeSpeedCircle_StartAnimation( HomeSpeedCircle _this, XInt32 aCurrentValue, 
  XInt32 aNextValue )
{
  if ( _this->SpeedCircleResizeEffect.Super1.Enabled )
  {
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->SpeedCircleResizeEffect, 0 );
    _this->SpeedCircleResizeEffect.Value1 = _this->SpeedCircleResizeEffect.Value;
    _this->SpeedCircleResizeEffect.Value2 = aNextValue;
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->SpeedCircleResizeEffect, 1 );
  }
  else
  {
    _this->SpeedCircleResizeEffect.Value1 = aCurrentValue;
    _this->SpeedCircleResizeEffect.Value2 = aNextValue;
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->SpeedCircleResizeEffect, 1 );
  }
}

/* 'C' function for method : 'Home::SpeedCircle.OnSetColor()' */
void HomeSpeedCircle_OnSetColor( HomeSpeedCircle _this, XColor value )
{
  if ( EwCompColor( _this->Color, value ))
  {
    _this->Color = value;
    ViewsWarpImage_OnSetColor( &_this->SpeedCircleImage, value );
  }
}

/* Variants derived from the class : 'Home::SpeedCircle' */
EW_DEFINE_CLASS_VARIANTS( HomeSpeedCircle )
EW_END_OF_CLASS_VARIANTS( HomeSpeedCircle )

/* Virtual Method Table (VMT) for the class : 'Home::SpeedCircle' */
EW_DEFINE_CLASS( HomeSpeedCircle, CoreGroup, SpeedCircleResizeEffect, SpeedCircleResizeEffect, 
                 SpeedCircleResizeEffect, SpeedCircleResizeEffect, SpeedValue, SpeedValue, 
                 "Home::SpeedCircle" )
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
EW_END_OF_CLASS( HomeSpeedCircle )

/* Embedded Wizard */
