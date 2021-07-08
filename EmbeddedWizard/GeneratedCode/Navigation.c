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
#include "_ComponentsBaseText.h"
#include "_CoreGroup.h"
#include "_CoreKeyPressHandler.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreVerticalList.h"
#include "_CoreView.h"
#include "_DeviceInterfaceNaviDataClass.h"
#include "_DeviceInterfaceNaviPoiDataClass.h"
#include "_DeviceInterfaceNaviTbtDataClass.h"
#include "_DeviceInterfaceNavigationDeviceClass.h"
#include "_DeviceInterfaceVehicleDataClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_EffectsInt32Effect.h"
#include "_EffectsRectEffect.h"
#include "_LauncherLNC_Main.h"
#include "_MenuArrowScrollBar.h"
#include "_MenuBaseMenuView.h"
#include "_MenuItemBase.h"
#include "_MenuItemCheckMark.h"
#include "_MenuItemPoiList.h"
#include "_MenuPushButton.h"
#include "_MenuUpDownPushButtonSet.h"
#include "_MenuVerticalMenu.h"
#include "_NavigationNAV01_DefaultView.h"
#include "_NavigationNAV03_TBTListView.h"
#include "_NavigationNAV05_TBTView.h"
#include "_NavigationNAV06_NaviSettingMenu.h"
#include "_NavigationNAV08_NaviChageViewMenu.h"
#include "_NavigationNAV09_NAV10_PoiList.h"
#include "_NavigationNAV11_RouteOptionMenu.h"
#include "_NavigationNaviAlert.h"
#include "_NavigationNaviAlertMessage.h"
#include "_NavigationNaviCurrentRoad.h"
#include "_NavigationNaviDialog.h"
#include "_NavigationNaviETA.h"
#include "_NavigationNaviTbtListDataEmptyDialog.h"
#include "_NavigationNaviZoomToast.h"
#include "_NavigationReRoute.h"
#include "_NavigationTbtInfoItem.h"
#include "_NavigationTbtListMenu.h"
#include "_PopPOP02_ConnectionError.h"
#include "_PopPOP03_HomeOfficeSettingError.h"
#include "_PopPOP09_POP14_BleConnectionErrorUI.h"
#include "_PopPOP16_NaviLoadingUI.h"
#include "_PopPOP17_AppInitSettingError.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesExternBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsFrame.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "_ViewsWallpaper.h"
#include "Color.h"
#include "DeviceInterface.h"
#include "Effects.h"
#include "Enum.h"
#include "Fonts.h"
#include "Navigation.h"
#include "Resource.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault0[] =
{
  0x00000286, /* ratio 56.97 % */
  0xB8001100, 0x8009C452, 0x00AC0020, 0x06200180, 0x06148780, 0xE002D116, 0x6D00454D,
  0xE0012400, 0x0013C006, 0x01D00075, 0x80244530, 0xCE432630, 0x0003A001, 0x3C008788,
  0x92B8DC48, 0x198B45A2, 0x18FC7637, 0x91C96472, 0x04AA4728, 0x19400520, 0x028C6300,
  0x8EC00348, 0x5D2C3252, 0xB12034C2, 0x700049C9, 0x68240A60, 0x8642A110, 0x24BE6036,
  0x52CD7258, 0x1E0C00AC, 0xE7F263C5, 0x5F2DACC5, 0x94E94476, 0x41A84BE9, 0x2A3CBEAF,
  0x8B5F4007, 0x24CA1F7D, 0xC662E488, 0x8E8F25A3, 0xE3B4C91C, 0x9B73A919, 0x157BBD9E,
  0x7EBE54A8, 0x4A96062F, 0x0019A3F0, 0x4526999F, 0x59F174AC, 0xD6AF90C7, 0x24D78A95,
  0xFF99BDCA, 0xB5B87E66, 0x0B84C1E0, 0x7980E001, 0x8B516240, 0x2C3EA128, 0xC66CD120,
  0x1E240487, 0xA09BD007, 0x002F0071, 0x409981A0, 0x4A3659F9, 0x2DA74FA3, 0xEF0005B1,
  0x1F7BBD2D, 0x72E5112E, 0x9EB304E2, 0x2192D897, 0x2553F672, 0x130F6C32, 0x5AF9917D,
  0xCDC57625, 0x08CC06B0, 0x149529BE, 0x1525D84A, 0x35797612, 0x2F63C006, 0x4115443D,
  0x8000952F, 0x7571DC84, 0xCC0057DB, 0x12029300, 0x70517131, 0x9F582DA7, 0x00A12F44,
  0xA5047253, 0xFA02D300, 0x0E5B985D, 0x50D17C00, 0xE6DA156E, 0xC10E8CD5, 0x00405304,
  0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 38 }, { 480, 272 }};
static const XColor _Const0001 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0002 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0003 = {{ 0, 226 }, { 130, 272 }};
static const XColor _Const0004 = { 0x16, 0x1F, 0x3C, 0xFF };
static const XRect _Const0005 = {{ 10, 228 }, { 120, 259 }};
static const XRect _Const0006 = {{ 130, 226 }, { 480, 272 }};
static const XColor _Const0007 = { 0x02, 0x03, 0x05, 0xE6 };
static const XRect _Const0008 = {{ 130, 224 }, { 480, 226 }};
static const XRect _Const0009 = {{ 205, 185 }, { 275, 219 }};
static const XRect _Const000A = {{ 9, 122 }, { 49, 162 }};
static const XRect _Const000B = {{ 9, 170 }, { 49, 210 }};
static const XRect _Const000C = {{ 411, 164 }, { 473, 226 }};
static const XRect _Const000D = {{ 420, 179 }, { 464, 212 }};
static const XRect _Const000E = {{ 480, 226 }, { 480, 272 }};
static const XRect _Const000F = {{ 0, 226 }, { 480, 272 }};
static const XRect _Const0010 = {{ 0, 38 }, { 480, 49 }};
static const XColor _Const0011 = { 0x00, 0x00, 0x00, 0x80 };
static const XRect _Const0012 = {{ 193, 89 }, { 287, 183 }};
static const XRect _Const0013 = {{ 370, 226 }, { 480, 272 }};
static const XStringRes _Const0014 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0015 = { _StringsDefault0, 0x000A };
static const XStringRes _Const0016 = { _StringsDefault0, 0x001E };
static const XStringRes _Const0017 = { _StringsDefault0, 0x003C };
static const XRect _Const0018 = {{ 0, 0 }, { 0, 0 }};
static const XRect _Const0019 = {{ 140, 228 }, { 470, 259 }};
static const XStringRes _Const001A = { _StringsDefault0, 0x0042 };
static const XStringRes _Const001B = { _StringsDefault0, 0x004A };
static const XStringRes _Const001C = { _StringsDefault0, 0x006A };
static const XStringRes _Const001D = { _StringsDefault0, 0x0088 };
static const XStringRes _Const001E = { _StringsDefault0, 0x00A8 };
static const XRect _Const001F = {{ 0, 0 }, { 330, 31 }};
static const XRect _Const0020 = {{ 0, 8 }, { 20, 28 }};
static const XRect _Const0021 = {{ 24, 0 }, { 330, 31 }};
static const XStringRes _Const0022 = { _StringsDefault0, 0x00B0 };
static const XRect _Const0023 = {{ 0, 0 }, { 480, 46 }};
static const XRect _Const0024 = {{ 405, 0 }, { 480, 46 }};
static const XColor _Const0025 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const0026 = {{ 445, 12 }, { 470, 34 }};
static const XRect _Const0027 = {{ 405, 6 }, { 443, 36 }};
static const XStringRes _Const0028 = { _StringsDefault0, 0x00B7 };
static const XStringRes _Const0029 = { _StringsDefault0, 0x00BC };
static const XStringRes _Const002A = { _StringsDefault0, 0x00C0 };
static const XStringRes _Const002B = { _StringsDefault0, 0x00C7 };
static const XRect _Const002C = {{ 366, 0 }, { 480, 46 }};
static const XRect _Const002D = {{ 0, 0 }, { 405, 46 }};
static const XRect _Const002E = {{ 10, 8 }, { 34, 32 }};
static const XRect _Const002F = {{ 38, 6 }, { 308, 37 }};
static const XRect _Const0030 = {{ 316, 6 }, { 354, 36 }};
static const XRect _Const0031 = {{ 356, 12 }, { 397, 34 }};
static const XRect _Const0032 = {{ 0, 0 }, { 110, 33 }};
static const XRect _Const0033 = {{ 19, 7 }, { 39, 29 }};
static const XRect _Const0034 = {{ 41, 2 }, { 92, 33 }};
static const XRect _Const0035 = {{ 84, 9 }, { 110, 31 }};
static const XStringRes _Const0036 = { _StringsDefault0, 0x00D0 };
static const XStringRes _Const0037 = { _StringsDefault0, 0x00D8 };
static const XStringRes _Const0038 = { _StringsDefault0, 0x00DD };
static const XStringRes _Const0039 = { _StringsDefault0, 0x00E2 };
static const XStringRes _Const003A = { _StringsDefault0, 0x00E7 };
static const XStringRes _Const003B = { _StringsDefault0, 0x00EB };
static const XStringRes _Const003C = { _StringsDefault0, 0x00F1 };
static const XRect _Const003D = {{ 0, 38 }, { 480, 226 }};
static const XRect _Const003E = {{ 186, 68 }, { 270, 116 }};
static const XRect _Const003F = {{ 270, 82 }, { 318, 112 }};
static const XRect _Const0040 = {{ 186, 117 }, { 408, 210 }};
static const XColor _Const0041 = { 0xCF, 0xCF, 0xCF, 0xFF };
static const XRect _Const0042 = {{ 28, 54 }, { 178, 204 }};
static const XRect _Const0043 = {{ 104, 75 }, { 376, 199 }};
static const XRect _Const0044 = {{ 193, 90 }, { 287, 182 }};
static const XRect _Const0045 = {{ 417, 43 }, { 467, 93 }};
static const XStringRes _Const0046 = { _StringsDefault0, 0x00F6 };
static const XStringRes _Const0047 = { _StringsDefault0, 0x00FE };
static const XStringRes _Const0048 = { _StringsDefault0, 0x010F };
static const XRect _Const0049 = {{ 0, 36 }, { 480, 272 }};
static const XRect _Const004A = {{ 0, 36 }, { 480, 38 }};
static const XStringRes _Const004B = { _StringsDefault0, 0x0115 };
static const XRect _Const004C = {{ 0, 0 }, { 480, 111 }};
static const XRect _Const004D = {{ 20, 0 }, { 440, 109 }};
static const XColor _Const004E = { 0x1E, 0x47, 0x8C, 0xFF };
static const XRect _Const004F = {{ 45, 14 }, { 90, 59 }};
static const XRect _Const0050 = {{ 27, 61 }, { 74, 95 }};
static const XRect _Const0051 = {{ 76, 61 }, { 108, 95 }};
static const XRect _Const0052 = {{ 114, 8 }, { 417, 109 }};
static const XColor _Const0053 = { 0xC8, 0xC8, 0xC8, 0xFF };
static const XRect _Const0054 = {{ 0, 109 }, { 480, 111 }};
static const XStringRes _Const0055 = { _StringsDefault0, 0x011D };
static const XRect _Const0056 = {{ 0, 0 }, { 340, 252 }};
static const XRect _Const0057 = {{ 15, 13 }, { 325, 190 }};
static const XStringRes _Const0058 = { _StringsDefault0, 0x0127 };
static const XStringRes _Const0059 = { _StringsDefault0, 0x012C };
static const XRect _Const005A = {{ 69, 154 }, { 271, 240 }};
static const XRect _Const005B = {{ 15, 13 }, { 325, 144 }};
static const XRect _Const005C = {{ 69, 200 }, { 271, 240 }};
static const XRect _Const005D = {{ 0, 0 }, { 480, 236 }};
static const XRect _Const005E = {{ 0, 2 }, { 444, 224 }};
static const XRect _Const005F = {{ 441, 5 }, { 473, 221 }};
static const XRect _Const0060 = {{ 10, 50 }, { 470, 236 }};
static const XStringRes _Const0061 = { _StringsDefault0, 0x0130 };
static const XStringRes _Const0062 = { _StringsDefault0, 0x013B };
static const XRect _Const0063 = {{ 144, 209 }, { 336, 249 }};
static const XRect _Const0064 = {{ 105, 83 }, { 375, 189 }};
static const XRect _Const0065 = {{ 0, 0 }, { 70, 34 }};
static const XRect _Const0066 = {{ 0, 3 }, { 70, 24 }};
static const XRect _Const0067 = {{ 10, 6 }, { 34, 30 }};
static const XRect _Const0068 = {{ 38, 2 }, { 470, 33 }};

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

/* Initializer for the class 'Navigation::NAV01_DefaultView' */
void NavigationNAV01_DefaultView__Init( NavigationNAV01_DefaultView _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  HomeBaseHome__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationNAV01_DefaultView );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Background, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->MapImage, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->ArrivalBg, &_this->_.XObject, 0 );
  NavigationNaviETA__Init( &_this->ETAComponent, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->RoadNameBg, &_this->_.XObject, 0 );
  NavigationNaviCurrentRoad__Init( &_this->CurrentRoadWithGuide, &_this->_.XObject, 0 );
  NavigationNaviCurrentRoad__Init( &_this->CurrentRoadWithOutGuide, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Shadow, &_this->_.XObject, 0 );
  NavigationNaviZoomToast__Init( &_this->ZoomToast, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ZoomInButton, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ZoomOutButton, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->SpeedLimitIcon, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->SpeedLimitText, &_this->_.XObject, 0 );
  NavigationNaviAlert__Init( &_this->NaviEventObject, &_this->_.XObject, 0 );
  NavigationReRoute__Init( &_this->ReRouteObject, &_this->_.XObject, 0 );
  ViewsWallpaper__Init( &_this->StatusBarShadowImage, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->Mask, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->BtLoadingAnimation, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->MapUpdateEventHandler, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->CurRdUpdateEventHandler, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ETAUpdateEventHandler, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->DayNightModeUpdateEventHandler, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->HighlightTimer, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->SpeedLimitUpdateEventHandler, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NavigationAlertUpdateEventHandler, &_this->_.XObject, 0 );
  EffectsRectEffect__Init( &_this->CurrentRoadShiftEffect, &_this->_.XObject, 0 );
  EffectsRectEffect__Init( &_this->NaviEventEnLargeEffect, &_this->_.XObject, 0 );
  EffectsRectEffect__Init( &_this->NaviEventDismissEffect, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NavigatingStatusUpdateEventHandler, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->SpeedLimitFlickeringTimer, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NaviDialogEventHandler, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NaviDisconnectEventHandler, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->ZoomToastDismissTimer, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ZoomLevelUpdateEventHandler, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->DisableFlickeringTimer, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->DisableReRouteAlertTimer, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NaviBtThroughputUpdateEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationNAV01_DefaultView );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Background, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Background, _Const0001 );
  CoreRectView__OnSetBounds( &_this->MapImage, _Const0002 );
  ViewsImage_OnSetAlignment( &_this->MapImage, ViewsImageAlignmentAlignHorzRight 
  | ViewsImageAlignmentAlignVertBottom );
  CoreRectView__OnSetBounds( &_this->ArrivalBg, _Const0003 );
  ViewsRectangle_OnSetColor( &_this->ArrivalBg, _Const0004 );
  ViewsRectangle_OnSetVisible( &_this->ArrivalBg, 1 );
  CoreRectView__OnSetBounds( &_this->ETAComponent, _Const0005 );
  CoreGroup__OnSetVisible( &_this->ETAComponent, 1 );
  CoreRectView__OnSetBounds( &_this->RoadNameBg, _Const0006 );
  ViewsRectangle_OnSetColor( &_this->RoadNameBg, _Const0007 );
  CoreRectView__OnSetBounds( &_this->CurrentRoadWithGuide, NavigationCURRENT_ROAD_W_NAVI_BOUNDS );
  CoreGroup__OnSetVisible( &_this->CurrentRoadWithGuide, 0 );
  _this->CurrentRoadWithGuide.RoadNameTextBounds = NavigationROADNAME_W_NAVI_BOUNDS;
  CoreRectView__OnSetBounds( &_this->CurrentRoadWithOutGuide, NavigationCURRENT_ROAD_WO_NAVI_BOUNDS );
  CoreGroup__OnSetVisible( &_this->CurrentRoadWithOutGuide, 1 );
  _this->CurrentRoadWithOutGuide.RoadNameTextBounds = NavigationROADNAME_WO_NAVI_BOUNDS;
  CoreRectView__OnSetBounds( &_this->Shadow, _Const0008 );
  ViewsImage_OnSetVisible( &_this->Shadow, 0 );
  CoreRectView__OnSetBounds( &_this->ZoomToast, _Const0009 );
  CoreGroup__OnSetVisible( &_this->ZoomToast, 0 );
  CoreRectView__OnSetBounds( &_this->ZoomInButton, _Const000A );
  ViewsImage_OnSetVisible( &_this->ZoomInButton, 1 );
  CoreRectView__OnSetBounds( &_this->ZoomOutButton, _Const000B );
  ViewsImage_OnSetVisible( &_this->ZoomOutButton, 1 );
  CoreRectView__OnSetBounds( &_this->SpeedLimitIcon, _Const000C );
  ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 1 );
  CoreRectView__OnSetBounds( &_this->SpeedLimitText, _Const000D );
  ViewsText_OnSetString( &_this->SpeedLimitText, 0 );
  ViewsText_OnSetColor( &_this->SpeedLimitText, _Const0001 );
  ViewsText_OnSetVisible( &_this->SpeedLimitText, 1 );
  CoreRectView__OnSetBounds( &_this->NaviEventObject, _Const000E );
  CoreRectView__OnSetBounds( &_this->ReRouteObject, _Const000F );
  CoreGroup__OnSetVisible( &_this->ReRouteObject, 0 );
  CoreRectView__OnSetBounds( &_this->StatusBarShadowImage, _Const0010 );
  CoreRectView__OnSetBounds( &_this->Mask, _Const0002 );
  ViewsRectangle_OnSetColor( &_this->Mask, _Const0011 );
  ViewsRectangle_OnSetVisible( &_this->Mask, 0 );
  CoreRectView__OnSetBounds( &_this->BtLoadingAnimation, _Const0012 );
  ViewsImage_OnSetAnimated( &_this->BtLoadingAnimation, 0 );
  ViewsImage_OnSetVisible( &_this->BtLoadingAnimation, 0 );
  _this->Super1.HomeType = EnumHomeTypeNAVI_DEFAULT_VIEW;
  CoreView_OnSetStackingPriority((CoreView)&_this->Super1.LoadingAnimation, 1 );
  CoreTimer_OnSetPeriod( &_this->HighlightTimer, 100 );
  CoreTimer_OnSetEnabled( &_this->HighlightTimer, 0 );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->CurrentRoadShiftEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->CurrentRoadShiftEffect, 
  500 );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->NaviEventEnLargeEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->NaviEventEnLargeEffect, 
  500 );
  _this->NaviEventEnLargeEffect.Value2 = _Const000F;
  _this->NaviEventEnLargeEffect.Value1 = _Const000E;
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->NaviEventDismissEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->NaviEventDismissEffect, 
  500 );
  _this->NaviEventDismissEffect.Value2 = _Const000E;
  _this->NaviEventDismissEffect.Value1 = _Const0013;
  CoreTimer_OnSetPeriod( &_this->SpeedLimitFlickeringTimer, 300 );
  CoreTimer_OnSetPeriod( &_this->ZoomToastDismissTimer, 500 );
  CoreTimer_OnSetEnabled( &_this->ZoomToastDismissTimer, 0 );
  CoreTimer_OnSetPeriod( &_this->DisableFlickeringTimer, 0 );
  CoreTimer_OnSetBegin( &_this->DisableFlickeringTimer, 5000 );
  CoreTimer_OnSetPeriod( &_this->DisableReRouteAlertTimer, 0 );
  CoreTimer_OnSetBegin( &_this->DisableReRouteAlertTimer, 5000 );
  CoreGroup__Add( _this, ((CoreView)&_this->Background ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->MapImage ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->ArrivalBg ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->ETAComponent ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->RoadNameBg ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->CurrentRoadWithGuide ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->CurrentRoadWithOutGuide ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->Shadow ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->ZoomToast ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->ZoomInButton ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->ZoomOutButton ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->SpeedLimitIcon ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->SpeedLimitText ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviEventObject ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->ReRouteObject ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->StatusBarShadowImage ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->Mask ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->BtLoadingAnimation ), -1 );
  ViewsImage_OnSetBitmap( &_this->MapImage, ((ResourcesBitmap)EwGetAutoObject( &ResourceExternBitmap, 
  ResourcesExternBitmap )));
  ViewsImage_OnSetBitmap( &_this->Shadow, EwLoadResource( &ResourceNaviShadowLine, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInDayIcon, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutDayIcon, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->SpeedLimitIcon, EwLoadResource( &ResourceSpeedLimitIcon, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->SpeedLimitText, EwLoadResource( &FontsNotoSansBold24pt, 
  ResourcesFont ));
  _this->NaviEventObject.DismissAlertSignal = EwNewSlot( _this, NavigationNAV01_DefaultView_DismissAlert );
  ViewsWallpaper_OnSetBitmap( &_this->StatusBarShadowImage, EwLoadResource( &ResourceStatusBarShadow, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->BtLoadingAnimation, EwLoadResource( &ResourceLoadingAnimation, 
  ResourcesBitmap ));
  _this->MapUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV01_DefaultView_OnMapUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->MapUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->MapUpdateEvent );
  _this->CurRdUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV01_DefaultView_OnCurRdUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->CurRdUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurRdUpdateEvent );
  _this->ETAUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV01_DefaultView_OnETAUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->ETAUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->ETAUpdateEvent );
  _this->DayNightModeUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV01_DefaultView_OnDayNightModeUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->DayNightModeUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->DayNightModeUpdateEvent );
  _this->HighlightTimer.OnTrigger = EwNewSlot( _this, NavigationNAV01_DefaultView_OnHighlightEndSlot );
  _this->SpeedLimitUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV01_DefaultView_OnSpeedLimitUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->SpeedLimitUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->SpeedLimitUpdateEvent );
  _this->NavigationAlertUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV01_DefaultView_OnNavigationAlertUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NavigationAlertUpdateEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->NavigationAlertUpdateEvent );
  _this->CurrentRoadShiftEffect.Super1.OnFinished = EwNewSlot( _this, NavigationNAV01_DefaultView_OnCurrentRoadShiftEffectFinishSlot );
  _this->CurrentRoadShiftEffect.Outlet = EwNewRef( &_this->CurrentRoadWithGuide, 
  CoreRectView_OnGetBounds, CoreRectView__OnSetBounds );
  _this->NaviEventEnLargeEffect.Super1.OnFinished = EwNewSlot( _this, NavigationNAV01_DefaultView_OnNaviEventEnlargeFinishSlot );
  _this->NaviEventEnLargeEffect.Outlet = EwNewRef( &_this->NaviEventObject, CoreRectView_OnGetBounds, 
  CoreRectView__OnSetBounds );
  _this->NaviEventDismissEffect.Super1.OnFinished = EwNewSlot( _this, NavigationNAV01_DefaultView_OnNaviEventDismissFinishSlot );
  _this->NaviEventDismissEffect.Outlet = EwNewRef( &_this->NaviEventObject, CoreRectView_OnGetBounds, 
  CoreRectView__OnSetBounds );
  _this->NavigatingStatusUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV01_DefaultView_OnNavigatingStatusUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NavigatingStatusUpdateEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->NavigatingStatusUpdateEvent );
  _this->SpeedLimitFlickeringTimer.OnTrigger = EwNewSlot( _this, NavigationNAV01_DefaultView_OnSpeedLimitFlickeringSlot );
  _this->NaviDialogEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV01_DefaultView_OnNaviDialogEventUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NaviDialogEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->DialogEventUpdateEvent );
  _this->NaviDisconnectEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV01_DefaultView_OnNaviDisconnectUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NaviDisconnectEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->DisconnectStatusUpdateEvent );
  _this->ZoomToastDismissTimer.OnTrigger = EwNewSlot( _this, NavigationNAV01_DefaultView_OnZoomToastDismissSlot );
  _this->ZoomLevelUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV01_DefaultView_OnZoomLevelUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->ZoomLevelUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->ZoomLevelUpdateEventHandler );
  _this->DisableFlickeringTimer.OnTrigger = EwNewSlot( _this, NavigationNAV01_DefaultView_OnDisableFlickeringSlot );
  _this->DisableReRouteAlertTimer.OnTrigger = EwNewSlot( _this, NavigationNAV01_DefaultView_OnDisableReRouteAlertSlot );
  _this->NaviBtThroughputUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV01_DefaultView_OnNaviBtThroughputStatusUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NaviBtThroughputUpdateEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->BtThroughputStatusUpdateEvent );

  /* Call the user defined constructor */
  NavigationNAV01_DefaultView_Init( _this, aArg );
}

/* Re-Initializer for the class 'Navigation::NAV01_DefaultView' */
void NavigationNAV01_DefaultView__ReInit( NavigationNAV01_DefaultView _this )
{
  /* At first re-initialize the super class ... */
  HomeBaseHome__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Background );
  ViewsImage__ReInit( &_this->MapImage );
  ViewsRectangle__ReInit( &_this->ArrivalBg );
  NavigationNaviETA__ReInit( &_this->ETAComponent );
  ViewsRectangle__ReInit( &_this->RoadNameBg );
  NavigationNaviCurrentRoad__ReInit( &_this->CurrentRoadWithGuide );
  NavigationNaviCurrentRoad__ReInit( &_this->CurrentRoadWithOutGuide );
  ViewsImage__ReInit( &_this->Shadow );
  NavigationNaviZoomToast__ReInit( &_this->ZoomToast );
  ViewsImage__ReInit( &_this->ZoomInButton );
  ViewsImage__ReInit( &_this->ZoomOutButton );
  ViewsImage__ReInit( &_this->SpeedLimitIcon );
  ViewsText__ReInit( &_this->SpeedLimitText );
  NavigationNaviAlert__ReInit( &_this->NaviEventObject );
  NavigationReRoute__ReInit( &_this->ReRouteObject );
  ViewsWallpaper__ReInit( &_this->StatusBarShadowImage );
  ViewsRectangle__ReInit( &_this->Mask );
  ViewsImage__ReInit( &_this->BtLoadingAnimation );
  CoreSystemEventHandler__ReInit( &_this->MapUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->CurRdUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->ETAUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->DayNightModeUpdateEventHandler );
  CoreTimer__ReInit( &_this->HighlightTimer );
  CoreSystemEventHandler__ReInit( &_this->SpeedLimitUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->NavigationAlertUpdateEventHandler );
  EffectsRectEffect__ReInit( &_this->CurrentRoadShiftEffect );
  EffectsRectEffect__ReInit( &_this->NaviEventEnLargeEffect );
  EffectsRectEffect__ReInit( &_this->NaviEventDismissEffect );
  CoreSystemEventHandler__ReInit( &_this->NavigatingStatusUpdateEventHandler );
  CoreTimer__ReInit( &_this->SpeedLimitFlickeringTimer );
  CoreSystemEventHandler__ReInit( &_this->NaviDialogEventHandler );
  CoreSystemEventHandler__ReInit( &_this->NaviDisconnectEventHandler );
  CoreTimer__ReInit( &_this->ZoomToastDismissTimer );
  CoreSystemEventHandler__ReInit( &_this->ZoomLevelUpdateEventHandler );
  CoreTimer__ReInit( &_this->DisableFlickeringTimer );
  CoreTimer__ReInit( &_this->DisableReRouteAlertTimer );
  CoreSystemEventHandler__ReInit( &_this->NaviBtThroughputUpdateEventHandler );
}

/* Finalizer method for the class 'Navigation::NAV01_DefaultView' */
void NavigationNAV01_DefaultView__Done( NavigationNAV01_DefaultView _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Background );
  ViewsImage__Done( &_this->MapImage );
  ViewsRectangle__Done( &_this->ArrivalBg );
  NavigationNaviETA__Done( &_this->ETAComponent );
  ViewsRectangle__Done( &_this->RoadNameBg );
  NavigationNaviCurrentRoad__Done( &_this->CurrentRoadWithGuide );
  NavigationNaviCurrentRoad__Done( &_this->CurrentRoadWithOutGuide );
  ViewsImage__Done( &_this->Shadow );
  NavigationNaviZoomToast__Done( &_this->ZoomToast );
  ViewsImage__Done( &_this->ZoomInButton );
  ViewsImage__Done( &_this->ZoomOutButton );
  ViewsImage__Done( &_this->SpeedLimitIcon );
  ViewsText__Done( &_this->SpeedLimitText );
  NavigationNaviAlert__Done( &_this->NaviEventObject );
  NavigationReRoute__Done( &_this->ReRouteObject );
  ViewsWallpaper__Done( &_this->StatusBarShadowImage );
  ViewsRectangle__Done( &_this->Mask );
  ViewsImage__Done( &_this->BtLoadingAnimation );
  CoreSystemEventHandler__Done( &_this->MapUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->CurRdUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->ETAUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->DayNightModeUpdateEventHandler );
  CoreTimer__Done( &_this->HighlightTimer );
  CoreSystemEventHandler__Done( &_this->SpeedLimitUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->NavigationAlertUpdateEventHandler );
  EffectsRectEffect__Done( &_this->CurrentRoadShiftEffect );
  EffectsRectEffect__Done( &_this->NaviEventEnLargeEffect );
  EffectsRectEffect__Done( &_this->NaviEventDismissEffect );
  CoreSystemEventHandler__Done( &_this->NavigatingStatusUpdateEventHandler );
  CoreTimer__Done( &_this->SpeedLimitFlickeringTimer );
  CoreSystemEventHandler__Done( &_this->NaviDialogEventHandler );
  CoreSystemEventHandler__Done( &_this->NaviDisconnectEventHandler );
  CoreTimer__Done( &_this->ZoomToastDismissTimer );
  CoreSystemEventHandler__Done( &_this->ZoomLevelUpdateEventHandler );
  CoreTimer__Done( &_this->DisableFlickeringTimer );
  CoreTimer__Done( &_this->DisableReRouteAlertTimer );
  CoreSystemEventHandler__Done( &_this->NaviBtThroughputUpdateEventHandler );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void NavigationNAV01_DefaultView_Init( NavigationNAV01_DefaultView _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0014 ));
  NavigationNAV01_DefaultView_SetItemBounds( _this );
  EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnCurRdUpdateSlot ), ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnETAUpdateSlot ), ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnDayNightModeUpdateSlot ), 
    ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnSpeedLimitUpdateSlot ), 
    ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnNavigationAlertUpdateSlot ), 
    ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnNaviBtThroughputStatusUpdateSlot ), 
    ((XObject)_this ));

  if ( EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->IsNaviLoadingDialogDisplayed )
  {
    EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->IsNaviLoadingDialogDisplayed 
    = 0;
    HomeBaseHome_OnSetAccessNaviView((HomeBaseHome)_this, 0 );
  }
  else
    HomeBaseHome_OnSetAccessNaviView((HomeBaseHome)_this, 1 );

  DeviceInterfaceNavigationDeviceClass_StartMapFrameRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
  DeviceInterfaceNavigationDeviceClass ));
  DeviceInterfaceNavigationDeviceClass_StartContentRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
  DeviceInterfaceNavigationDeviceClass ));
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnShortDownKeyActivated()' */
void NavigationNAV01_DefaultView_OnShortDownKeyActivated( NavigationNAV01_DefaultView _this )
{
  XEnum ZoomInOutStatus = DeviceInterfaceNavigationDeviceClass_GetZoomInOutStatus( 
    EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));

  EwTrace( "%s%e", EwLoadString( &_Const0015 ), ZoomInOutStatus );
  EwTrace( "%s%b", EwLoadString( &_Const0016 ), EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
    DeviceInterfaceNavigationDeviceClass )->IsZoomInOutStatusReceived );

  if ( ViewsImage_OnGetVisible( &_this->ZoomOutButton ) && EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass )->IsZoomInOutStatusReceived )
  {
    DeviceInterfaceNaviDataClass NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( 
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
      EnumNaviDataTypeDAYNIGHT );

    switch ( ZoomInOutStatus )
    {
      case EnumNaviZoomInOutStatusTypeREACH_MINIMUM :
      case EnumNaviZoomInOutStatusTypeNORMAL :
      {
        switch ( NaviData->DayNightMode )
        {
          case 2 :
            ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInNightIcon, 
            ResourcesBitmap ));
          break;

          case 1 :
            ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInDayIcon, 
            ResourcesBitmap ));
          break;

          default :; 
        }

        NavigationNAV01_DefaultView_OnSetZoomAction( _this, EnumNaviZoomActionTypeZOOM_OUT );
        EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->IsZoomInOutStatusReceived 
        = 0;
        NavigationNAV01_DefaultView_StartHighlight( _this );
        DeviceInterfaceNavigationDeviceClass_ZoomOutRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
        DeviceInterfaceNavigationDeviceClass ));
      }
      break;

      default :; 
    }
  }
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnShortUpKeyActivated()' */
void NavigationNAV01_DefaultView_OnShortUpKeyActivated( NavigationNAV01_DefaultView _this )
{
  XEnum ZoomInOutStatus = DeviceInterfaceNavigationDeviceClass_GetZoomInOutStatus( 
    EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));

  EwTrace( "%s%e", EwLoadString( &_Const0015 ), ZoomInOutStatus );
  EwTrace( "%s%b", EwLoadString( &_Const0016 ), EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
    DeviceInterfaceNavigationDeviceClass )->IsZoomInOutStatusReceived );

  if ( ViewsImage_OnGetVisible( &_this->ZoomInButton ) && EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass )->IsZoomInOutStatusReceived )
  {
    DeviceInterfaceNaviDataClass NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( 
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
      EnumNaviDataTypeDAYNIGHT );

    switch ( ZoomInOutStatus )
    {
      case EnumNaviZoomInOutStatusTypeREACH_MAXIMUM :
      case EnumNaviZoomInOutStatusTypeNORMAL :
      {
        switch ( NaviData->DayNightMode )
        {
          case 2 :
            ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutNightIcon, 
            ResourcesBitmap ));
          break;

          case 1 :
            ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutDayIcon, 
            ResourcesBitmap ));
          break;

          default :; 
        }

        NavigationNAV01_DefaultView_OnSetZoomAction( _this, EnumNaviZoomActionTypeZOOM_IN );
        EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->IsZoomInOutStatusReceived 
        = 0;
        NavigationNAV01_DefaultView_StartHighlight( _this );
        DeviceInterfaceNavigationDeviceClass_ZoomInRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
        DeviceInterfaceNavigationDeviceClass ));
      }
      break;

      default :; 
    }
  }
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnLongEnterKeyActivated()' */
void NavigationNAV01_DefaultView_OnLongEnterKeyActivated( NavigationNAV01_DefaultView _this )
{
  if ( !_this->Super1.NaviConnectFailedTimer.Enabled && ( 1 == _this->Super3.KeyHandler.RepetitionCount ))
  {
    if ( !DeviceInterfaceNavigationDeviceClass_OnGetNaviAppSppConnected( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( PopPOP09_POP14_BleConnectionErrorUI, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    else
      if ( !DeviceInterfaceNavigationDeviceClass_GetNaviConnectStatus( EwGetAutoObject( 
          &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( PopPOP17_AppInitSettingError, 
        0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      else
      {
        DeviceInterfaceNavigationDeviceClass_StopMapFrameRequest( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));
        DeviceInterfaceNavigationDeviceClass_StopContentRequest( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( NavigationNAV06_NaviSettingMenu, 
        0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
  }
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnLongHomeKeyActivated()' */
void NavigationNAV01_DefaultView_OnLongHomeKeyActivated( NavigationNAV01_DefaultView _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.ReturnToHome()' */
void NavigationNAV01_DefaultView_ReturnToHome( NavigationNAV01_DefaultView _this )
{
  HomeBaseHome_ReturnToHome((HomeBaseHome)_this );
  HomeBaseHome_OnSetAccessNaviView((HomeBaseHome)_this, 1 );
  DeviceInterfaceNavigationDeviceClass_StartMapFrameRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
  DeviceInterfaceNavigationDeviceClass ));
  DeviceInterfaceNavigationDeviceClass_StartContentRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
  DeviceInterfaceNavigationDeviceClass ));
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnMapUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( DeviceInterfaceNavigationDeviceClass_IsMapFrameReady( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass )))
  {
    if ( !ViewsImage_OnGetVisible( &_this->Shadow ))
      ViewsImage_OnSetVisible( &_this->Shadow, 1 );

    if ( _this->Super1.AccessNaviView )
    {
      HomeBaseHome_OnSetAccessNaviView((HomeBaseHome)_this, 0 );
      EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnNaviDialogEventUpdateSlot ), 
        ((XObject)_this ));
    }

    if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
      NavigationNAV01_DefaultView_OnSetIsJcvDisplayed( _this, DeviceInterfaceNavigationDeviceClass_IsJcvReceived( 
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )));
    else
    {
      DeviceInterfaceNaviDataClass NaviData;
      ViewsImage_OnSetVisible( &_this->ZoomInButton, 1 );
      ViewsImage_OnSetVisible( &_this->ZoomOutButton, 1 );
      NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
      EnumNaviDataTypeSPEED_LIMIT );

      if ( NaviData->SpeedLimit > 0 )
      {
        ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 1 );
        ViewsText_OnSetVisible( &_this->SpeedLimitText, 1 );
      }
      else
      {
        ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 0 );
        ViewsText_OnSetVisible( &_this->SpeedLimitText, 0 );
      }
    }

    _this->MapFrameIdx = _this->MapFrameIdx + 1;
    ResourcesExternBitmap_OnSetName( EwGetAutoObject( &ResourceExternBitmap, ResourcesExternBitmap ), 
    EwConcatString( EwLoadString( &_Const0017 ), EwNewStringInt( _this->MapFrameIdx, 
    0, 10 )));
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnCurRdUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  DeviceInterfaceNaviDataClass NaviData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), EnumNaviDataTypeCURRENT_ROAD );
  NavigationNaviCurrentRoad_OnSetRoadName( &_this->CurrentRoadWithGuide, NaviData->CurrentRoad );
  NavigationNaviCurrentRoad_SetItemBounds( &_this->CurrentRoadWithGuide, 0 );
  NavigationNaviCurrentRoad_OnSetRoadName( &_this->CurrentRoadWithOutGuide, NaviData->CurrentRoad );
  NavigationNaviCurrentRoad_SetItemBounds( &_this->CurrentRoadWithOutGuide, 0 );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnETAUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  DeviceInterfaceNaviDataClass NaviData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), EnumNaviDataTypeETA );
  NavigationNaviETA_OnSetETA( &_this->ETAComponent, NaviData->ETA );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnDayNightModeUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  DeviceInterfaceNaviDataClass NaviData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), EnumNaviDataTypeDAYNIGHT );

  if ( 1 == NaviData->DayNightMode )
  {
    ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInDayIcon, 
    ResourcesBitmap ));
    ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutDayIcon, 
    ResourcesBitmap ));
  }
  else
    if ( 2 == NaviData->DayNightMode )
    {
      ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInNightIcon, 
      ResourcesBitmap ));
      ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutNightIcon, 
      ResourcesBitmap ));
    }
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.StartHighlight()' */
void NavigationNAV01_DefaultView_StartHighlight( NavigationNAV01_DefaultView _this )
{
  DeviceInterfaceNaviDataClass NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( 
    EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
    EnumNaviDataTypeDAYNIGHT );

  switch ( _this->ZoomAction )
  {
    case EnumNaviZoomActionTypeZOOM_IN :
      if ( 2 == NaviData->DayNightMode )
        ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInNightFocusIcon, 
        ResourcesBitmap ));
      else
        if ( 1 == NaviData->DayNightMode )
          ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInDayFocusIcon, 
          ResourcesBitmap ));
    break;

    case EnumNaviZoomActionTypeZOOM_OUT :
      if ( 2 == NaviData->DayNightMode )
        ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutNightFocusIcon, 
        ResourcesBitmap ));
      else
        if ( 1 == NaviData->DayNightMode )
          ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutDayFocusIcon, 
          ResourcesBitmap ));
    break;

    default :; 
  }

  CoreTimer_OnSetEnabled( &_this->HighlightTimer, 1 );
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnHighlightEndSlot()' */
void NavigationNAV01_DefaultView_OnHighlightEndSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  DeviceInterfaceNaviDataClass NaviData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->HighlightTimer, 0 );
  NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), EnumNaviDataTypeDAYNIGHT );

  switch ( _this->ZoomAction )
  {
    case EnumNaviZoomActionTypeZOOM_IN :
      if ( 2 == NaviData->DayNightMode )
        ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInNightIcon, 
        ResourcesBitmap ));
      else
        if ( 1 == NaviData->DayNightMode )
          ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInDayIcon, 
          ResourcesBitmap ));
    break;

    case EnumNaviZoomActionTypeZOOM_OUT :
      if ( 2 == NaviData->DayNightMode )
        ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutNightIcon, 
        ResourcesBitmap ));
      else
        if ( 1 == NaviData->DayNightMode )
          ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutDayIcon, 
          ResourcesBitmap ));
    break;

    default :; 
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnSpeedLimitUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  DeviceInterfaceNaviDataClass NaviData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), EnumNaviDataTypeSPEED_LIMIT );

  if (( NaviData->SpeedLimit > 0 ) && !DeviceInterfaceNavigationDeviceClass_IsJcvReceived( 
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
  {
    ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 1 );
    ViewsText_OnSetString( &_this->SpeedLimitText, EwNewStringInt( NaviData->SpeedLimit, 
    0, 10 ));
    ViewsText_OnSetVisible( &_this->SpeedLimitText, 1 );
  }
  else
  {
    ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 0 );
    ViewsText_OnSetVisible( &_this->SpeedLimitText, 0 );
    NavigationNAV01_DefaultView_OnSetSpeedingEventStatus( _this, 0 );
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnNavigationAlertUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  DeviceInterfaceNaviDataClass NaviData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), EnumNaviDataTypeNAVI_EVENT );

  if (( NaviData != 0 ) && NaviData->NaviEventVisibility )
  {
    if ( DeviceInterfaceNavigationDeviceClass_IsSpeedingAlertReceived( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
      NavigationNAV01_DefaultView_OnSetSpeedingEventStatus( _this, 1 );

    if ( DeviceInterfaceNavigationDeviceClass_IsReRouteAlertReceived( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
    {
      NavigationReRoute_OnSetMessage( &_this->ReRouteObject, DeviceInterfaceNavigationDeviceClass_GetRerouteAlertMessage( 
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )));
      CoreGroup__OnSetVisible( &_this->ReRouteObject, 1 );
      NavigationNAV01_DefaultView_OnSetReRouteEventStatus( _this, 1 );
    }
    else
      if ( !DeviceInterfaceNavigationDeviceClass_GetAlertDisplayStatus( EwGetAutoObject( 
          &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
      {
        DeviceInterfaceNavigationDeviceClass_EnableAlertDisplayFlag( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));
        NavigationNaviAlert_SetAlert( &_this->NaviEventObject, NaviData->NaviEventType, 
        NaviData->NaviCameraType, NaviData->NaviEventSpeed, NaviData->NaviEventDist );
        EffectsEffect_OnSetEnabled((EffectsEffect)&_this->NaviEventEnLargeEffect, 
        1 );
      }
  }
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnCurrentRoadShiftEffectFinishSlot()' */
void NavigationNAV01_DefaultView_OnCurrentRoadShiftEffectFinishSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreRectView__OnSetBounds( &_this->CurrentRoadWithGuide, NavigationCURRENT_ROAD_W_NAVI_BOUNDS );
  NavigationNaviCurrentRoad_UpdateItemBounds( &_this->CurrentRoadWithGuide, EnumNaviAlertAnimationTypeDismiss, 
  EwGetRectW( _this->CurrentRoadWithGuide.Super2.Bounds ));
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->CurrentRoadShiftEffect, 0 );
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnNaviEventEnlargeFinishSlot()' */
void NavigationNAV01_DefaultView_OnNaviEventEnlargeFinishSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->NaviEventEnLargeEffect, 0 );
  CoreRectView__OnSetBounds( &_this->CurrentRoadWithGuide, NavigationCURRENT_ROAD_SHRINK_ALERT );
  NavigationNaviCurrentRoad_UpdateItemBounds( &_this->CurrentRoadWithGuide, EnumNaviAlertAnimationTypeShrink, 
  EwGetRectW( _this->CurrentRoadWithGuide.Super2.Bounds ));
  NavigationNaviAlert_ShrinkAlert( &_this->NaviEventObject );
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnNaviEventDismissFinishSlot()' */
void NavigationNAV01_DefaultView_OnNaviEventDismissFinishSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->NaviEventDismissEffect, 0 );
  CoreRectView__OnSetBounds( &_this->NaviEventObject.AlertMessage, NavigationALERT_MESSAGE_BOUNDS );
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.DismissAlert()' */
void NavigationNAV01_DefaultView_DismissAlert( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  XRect NewCurrentRoadObjectBounds;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->CurrentRoadShiftEffect.Value1 = _this->CurrentRoadWithGuide.Super2.Bounds;
  NewCurrentRoadObjectBounds = _Const0018;
  NewCurrentRoadObjectBounds.Point1.X = ( _this->CurrentRoadWithGuide.NaviIconX1Pos 
  + EwGetRectW( _this->ArrivalBg.Super1.Bounds ));
  NewCurrentRoadObjectBounds.Point2.X = ( NewCurrentRoadObjectBounds.Point1.X + 
  EwGetRectW( _this->CurrentRoadWithGuide.Super2.Bounds ));
  NewCurrentRoadObjectBounds.Point1.Y = _this->CurrentRoadWithGuide.Super2.Bounds.Point1.Y;
  NewCurrentRoadObjectBounds.Point2.Y = _this->CurrentRoadWithGuide.Super2.Bounds.Point2.Y;

  if ( NewCurrentRoadObjectBounds.Point1.X > _this->CurrentRoadShiftEffect.Value1.Point1.X )
  {
    _this->CurrentRoadShiftEffect.Value2 = NewCurrentRoadObjectBounds;
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->CurrentRoadShiftEffect, 1 );
  }
  else
  {
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->CurrentRoadShiftEffect, 0 );
    CoreRectView__OnSetBounds( &_this->CurrentRoadWithGuide, _Const0019 );
    NavigationNaviCurrentRoad_UpdateItemBounds( &_this->CurrentRoadWithGuide, EnumNaviAlertAnimationTypeDismiss, 
    EwGetRectW( _this->CurrentRoadWithGuide.Super2.Bounds ));
  }

  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->NaviEventDismissEffect, 1 );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnNavigatingStatusUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  NavigationNAV01_DefaultView_SetItemBounds( _this );
  EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnCurRdUpdateSlot ), ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnETAUpdateSlot ), ((XObject)_this ));
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnSpeedLimitFlickeringSlot()' */
void NavigationNAV01_DefaultView_OnSpeedLimitFlickeringSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, (XBool)!ViewsImage_OnGetVisible( 
  &_this->SpeedLimitIcon ));
  ViewsText_OnSetVisible( &_this->SpeedLimitText, (XBool)!ViewsText_OnGetVisible( 
  &_this->SpeedLimitText ));
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.SetItemBounds()' */
void NavigationNAV01_DefaultView_SetItemBounds( NavigationNAV01_DefaultView _this )
{
  if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
  {
    CoreRectView__OnSetBounds( &_this->ZoomInButton, NavigationZOOMIN_W_NAVI_BOUNDS );
    CoreRectView__OnSetBounds( &_this->ZoomOutButton, NavigationZOOMOUT_W_NAVI_BOUNDS );
    CoreRectView__OnSetBounds( &_this->RoadNameBg, NavigationROAD_BG_W_NAVI_BOUNDS );
    CoreGroup__OnSetVisible( &_this->CurrentRoadWithGuide, 1 );
    CoreGroup__OnSetVisible( &_this->ETAComponent, 1 );
    ViewsRectangle_OnSetVisible( &_this->ArrivalBg, 1 );
    CoreGroup__OnSetVisible( &_this->CurrentRoadWithOutGuide, 0 );
  }
  else
  {
    CoreRectView__OnSetBounds( &_this->ZoomInButton, NavigationZOOMIN_WO_NAVI_BOUNDS );
    CoreRectView__OnSetBounds( &_this->ZoomOutButton, NavigationZOOMOUT_WO_NAVI_BOUNDS );
    CoreRectView__OnSetBounds( &_this->RoadNameBg, NavigationROAD_BG_WO_NAVI_BOUNDS );
    CoreGroup__OnSetVisible( &_this->CurrentRoadWithGuide, 0 );
    CoreGroup__OnSetVisible( &_this->ETAComponent, 0 );
    ViewsRectangle_OnSetVisible( &_this->ArrivalBg, 0 );
    CoreGroup__OnSetVisible( &_this->CurrentRoadWithOutGuide, 1 );
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnNaviDialogEventUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( CoreGroup__IsCurrentDialog( _this ))
  {
    XEnum NaviDialogType = DeviceInterfaceNavigationDeviceClass_GetNaviDialogType( 
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));
    XString NaviDialogMessage = DeviceInterfaceNavigationDeviceClass_GetNaviDialogMessage( 
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));

    switch ( NaviDialogType )
    {
      case EnumNaviDialogTypeDIALOG_YES_NO :
      {
        NavigationNaviDialog Dialog = EwNewObject( NavigationNaviDialog, 0 );
        NavigationNaviDialog_OnSetDialogType( Dialog, EnumNaviDialogTypeDIALOG_YES_NO );
        NavigationNaviDialog_OnSetDialogButton( Dialog, EW_CLASS( MenuUpDownPushButtonSet ));
        NavigationNaviDialog_OnSetDialogMessage( Dialog, NaviDialogMessage );
        Dialog->OnDialogDismiss = EwNewSlot( _this, NavigationNAV01_DefaultView_OnNaviDialogDismissSlot );
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)Dialog ), 0, 0, 0, 
        0, 0, 0, EwNullSlot, EwNullSlot, 0 );
        CoreTimer_OnSetEnabled( &Dialog->CountDownTimer, 1 );
        ViewsRectangle_OnSetVisible( &_this->Mask, 1 );
      }
      break;

      case EnumNaviDialogTypeDIALOG_OK :
      {
        NavigationNaviDialog Dialog = EwNewObject( NavigationNaviDialog, 0 );
        NavigationNaviDialog_OnSetDialogType( Dialog, EnumNaviDialogTypeDIALOG_OK );
        NavigationNaviDialog_OnSetDialogButton( Dialog, EW_CLASS( MenuPushButton ));
        NavigationNaviDialog_OnSetDialogMessage( Dialog, NaviDialogMessage );
        Dialog->OnDialogDismiss = EwNewSlot( _this, NavigationNAV01_DefaultView_OnNaviDialogDismissSlot );
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)Dialog ), 0, 0, 0, 
        0, 0, 0, EwNullSlot, EwNullSlot, 0 );
        ViewsRectangle_OnSetVisible( &_this->Mask, 1 );
      }
      break;

      default :; 
    }
  }
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnNaviDialogDismissSlot()' */
void NavigationNAV01_DefaultView_OnNaviDialogDismissSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsRectangle_OnSetVisible( &_this->Mask, 0 );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnNaviDisconnectUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if (( _this->Super6.Owner != 0 ) && CoreGroup__IsCurrentDialog( _this ))
    CoreGroup_SwitchToDialog( _this->Super6.Owner, ((CoreGroup)EwNewObject( PopPOP02_ConnectionError, 
    0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnSetIsJcvDisplayed()' */
void NavigationNAV01_DefaultView_OnSetIsJcvDisplayed( NavigationNAV01_DefaultView _this, 
  XBool value )
{
  if ( _this->IsJcvDisplayed != value )
  {
    _this->IsJcvDisplayed = value;
    ViewsText_OnSetVisible( &_this->SpeedLimitText, (XBool)!value );
    ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, (XBool)!value );
    ViewsImage_OnSetVisible( &_this->ZoomInButton, (XBool)!value );
    ViewsImage_OnSetVisible( &_this->ZoomOutButton, (XBool)!value );
  }
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnZoomToastDismissSlot()' */
void NavigationNAV01_DefaultView_OnZoomToastDismissSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->ZoomToastDismissTimer, 0 );
  CoreGroup__OnSetVisible( &_this->ZoomToast, 0 );
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnSetZoomAction()' */
void NavigationNAV01_DefaultView_OnSetZoomAction( NavigationNAV01_DefaultView _this, 
  XEnum value )
{
  if ( _this->ZoomAction != value )
    _this->ZoomAction = value;
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnZoomLevelUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  XEnum ZoomInOutStatus;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ZoomInOutStatus = DeviceInterfaceNavigationDeviceClass_GetZoomInOutStatus( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));

  switch ( ZoomInOutStatus )
  {
    case EnumNaviZoomInOutStatusTypeREACH_MAXIMUM :
    {
      DeviceInterfaceNaviDataClass NaviData;

      if (( EwLoadResource( &ResourceZoomOutNightDisableIcon, ResourcesBitmap ) 
          != _this->ZoomOutButton.Bitmap ) && ( EwLoadResource( &ResourceZoomOutDayDisableIcon, 
          ResourcesBitmap ) != _this->ZoomOutButton.Bitmap ))
        NavigationNAV01_DefaultView_ShowZoomToast( _this );

      NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
      EnumNaviDataTypeDAYNIGHT );

      if ( NaviData != 0 )
        switch ( NaviData->DayNightMode )
        {
          case 2 :
            ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutNightDisableIcon, 
            ResourcesBitmap ));
          break;

          case 1 :
            ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutDayDisableIcon, 
            ResourcesBitmap ));
          break;

          default :; 
        }
    }
    break;

    case EnumNaviZoomInOutStatusTypeREACH_MINIMUM :
    {
      DeviceInterfaceNaviDataClass NaviData;

      if (( EwLoadResource( &ResourceZoomInNightDisableIcon, ResourcesBitmap ) != 
          _this->ZoomInButton.Bitmap ) && ( EwLoadResource( &ResourceZoomInDayDisableIcon, 
          ResourcesBitmap ) != _this->ZoomInButton.Bitmap ))
        NavigationNAV01_DefaultView_ShowZoomToast( _this );

      NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
      EnumNaviDataTypeDAYNIGHT );

      if ( NaviData != 0 )
        switch ( NaviData->DayNightMode )
        {
          case 2 :
            ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInNightDisableIcon, 
            ResourcesBitmap ));
          break;

          case 1 :
            ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInDayDisableIcon, 
            ResourcesBitmap ));
          break;

          default :; 
        }
    }
    break;

    case EnumNaviZoomInOutStatusTypeNORMAL :
      NavigationNAV01_DefaultView_ShowZoomToast( _this );
    break;

    default :; 
  }
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.ShowZoomToast()' */
void NavigationNAV01_DefaultView_ShowZoomToast( NavigationNAV01_DefaultView _this )
{
  DeviceInterfaceNaviDataClass NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( 
    EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
    EnumNaviDataTypeZOOM_LEVEL );

  if ( NaviData != 0 )
    ViewsText_OnSetString( &_this->ZoomToast.ZoomLevelText, NaviData->ZoomLevel );

  CoreGroup__OnSetVisible( &_this->ZoomToast, 1 );
  CoreTimer_OnSetEnabled( &_this->ZoomToastDismissTimer, 1 );
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnDisableFlickeringSlot()' */
void NavigationNAV01_DefaultView_OnDisableFlickeringSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 0 );
  ViewsText_OnSetVisible( &_this->SpeedLimitText, 0 );
  NavigationNAV01_DefaultView_OnSetSpeedingEventStatus( _this, 0 );
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnDisableReRouteAlertSlot()' */
void NavigationNAV01_DefaultView_OnDisableReRouteAlertSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup__OnSetVisible( &_this->ReRouteObject, 0 );
  NavigationNAV01_DefaultView_OnSetReRouteEventStatus( _this, 0 );
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnSetSpeedingEventStatus()' */
void NavigationNAV01_DefaultView_OnSetSpeedingEventStatus( NavigationNAV01_DefaultView _this, 
  XBool value )
{
  _this->SpeedingEventStatus = value;
  CoreTimer_OnSetEnabled( &_this->SpeedLimitFlickeringTimer, value );
  CoreTimer_OnSetEnabled( &_this->DisableFlickeringTimer, value );

  if ( !_this->SpeedingEventStatus )
    DeviceInterfaceNavigationDeviceClass_RemoveSpeedingAlert( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
    DeviceInterfaceNavigationDeviceClass ));
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnSetReRouteEventStatus()' */
void NavigationNAV01_DefaultView_OnSetReRouteEventStatus( NavigationNAV01_DefaultView _this, 
  XBool value )
{
  _this->ReRouteEventStatus = value;
  CoreTimer_OnSetEnabled( &_this->DisableReRouteAlertTimer, value );

  if ( !_this->ReRouteEventStatus )
    DeviceInterfaceNavigationDeviceClass_RemoteReRouteAlert( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
    DeviceInterfaceNavigationDeviceClass ));
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnNaviBtThroughputStatusUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  XEnum BtThroughputUIMode;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  BtThroughputUIMode = DeviceInterfaceNavigationDeviceClass_GetBtThroughputUIMode( 
  EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));

  if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
    switch ( BtThroughputUIMode )
    {
      case EnumNaviBtThroughputUIModeBUSY :
        NavigationNAV01_DefaultView_OnSetIsBtLoading( _this, 1 );
      break;

      case EnumNaviBtThroughputUIModeTBT :
      {
        NavigationNAV01_DefaultView_OnSetIsBtLoading( _this, 0 );

        if ( CoreGroup__IsCurrentDialog( _this ))
        {
          ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), 
            ApplicationApplication );

          if ( App != 0 )
          {
            EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
            = EnumHomeTypeNAVI_NEXT_TURN;
            EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->IsBtThoughputModeActivateFromMap 
            = 1;
            ApplicationApplication_SwitchToHome( App, EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
            DeviceInterfaceNavigationDeviceClass )->CurrentHome );
          }
        }
      }
      break;

      default :; 
    }
  else
    switch ( BtThroughputUIMode )
    {
      case EnumNaviBtThroughputUIModeBUSY :
      case EnumNaviBtThroughputUIModeTBT :
        NavigationNAV01_DefaultView_OnSetIsBtLoading( _this, 1 );
      break;

      case EnumNaviBtThroughputUIModeMAP :
        NavigationNAV01_DefaultView_OnSetIsBtLoading( _this, 0 );
      break;

      default :; 
    }
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnSetIsBtLoading()' */
void NavigationNAV01_DefaultView_OnSetIsBtLoading( NavigationNAV01_DefaultView _this, 
  XBool value )
{
  if ( _this->IsBtLoading != value )
  {
    _this->IsBtLoading = value;
    ViewsImage_OnSetVisible( &_this->BtLoadingAnimation, value );
    ViewsImage_OnSetAnimated( &_this->BtLoadingAnimation, value );
    ViewsRectangle_OnSetVisible( &_this->Mask, value );
  }
}

/* Variants derived from the class : 'Navigation::NAV01_DefaultView' */
EW_DEFINE_CLASS_VARIANTS( NavigationNAV01_DefaultView )
EW_END_OF_CLASS_VARIANTS( NavigationNAV01_DefaultView )

/* Virtual Method Table (VMT) for the class : 'Navigation::NAV01_DefaultView' */
EW_DEFINE_CLASS( NavigationNAV01_DefaultView, HomeBaseHome, Background, Background, 
                 Background, Background, MapFrameIdx, MapFrameIdx, "Navigation::NAV01_DefaultView" )
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
  NavigationNAV01_DefaultView_OnShortDownKeyActivated,
  NavigationNAV01_DefaultView_OnShortUpKeyActivated,
  HomeBaseHome_OnShortEnterKeyActivated,
  HomeBaseHome_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  NavigationNAV01_DefaultView_OnLongEnterKeyActivated,
  NavigationNAV01_DefaultView_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  NavigationNAV01_DefaultView_ReturnToHome,
EW_END_OF_CLASS( NavigationNAV01_DefaultView )

/* Initializer for the class 'Navigation::NAV06_NaviSettingMenu' */
void NavigationNAV06_NaviSettingMenu__Init( NavigationNAV06_NaviSettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationNAV06_NaviSettingMenu );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->NavigatingStatusUpdateEventHandler, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ViaPointUpdateEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationNAV06_NaviSettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0002 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 7 );
  MenuVerticalMenu_OnSetArrowScrollBarVisible( &_this->Super1.Menu, 1 );
  _this->NaviSettings[ 0 ] = EnumNaviSettingItemStopNavigation;
  _this->NaviSettings[ 1 ] = EnumNaviSettingItemSkipNextStop;
  _this->NaviSettings[ 2 ] = EnumNaviSettingItemGoHome;
  _this->NaviSettings[ 3 ] = EnumNaviSettingItemGoToWork;
  _this->NaviSettings[ 4 ] = EnumNaviSettingItemFavorites;
  _this->NaviSettings[ 5 ] = EnumNaviSettingItemNearbyGasStations;
  _this->NaviSettings[ 6 ] = EnumNaviSettingItemChangeView;
  _this->SelectedItem = EnumNaviSettingItemTOTAL;
  _this->NavigatingStatusUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV06_NaviSettingMenu_OnNavigatingStatusUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NavigatingStatusUpdateEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->NavigatingStatusUpdateEvent );
  _this->ViaPointUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV06_NaviSettingMenu_OnViaPointUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->ViaPointUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->ViaPointUpdateEvent );

  /* Call the user defined constructor */
  NavigationNAV06_NaviSettingMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Navigation::NAV06_NaviSettingMenu' */
void NavigationNAV06_NaviSettingMenu__ReInit( NavigationNAV06_NaviSettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->NavigatingStatusUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->ViaPointUpdateEventHandler );
}

/* Finalizer method for the class 'Navigation::NAV06_NaviSettingMenu' */
void NavigationNAV06_NaviSettingMenu__Done( NavigationNAV06_NaviSettingMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CoreSystemEventHandler__Done( &_this->NavigatingStatusUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->ViaPointUpdateEventHandler );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void NavigationNAV06_NaviSettingMenu_Init( NavigationNAV06_NaviSettingMenu _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const001A ));
  NavigationNAV06_NaviSettingMenu_SetNaviSettingMenuItem( _this );
}

/* 'C' function for method : 'Navigation::NAV06_NaviSettingMenu.OnShortHomeKeyActivated()' */
void NavigationNAV06_NaviSettingMenu_OnShortHomeKeyActivated( NavigationNAV06_NaviSettingMenu _this )
{
  LauncherLNC_Main LauncherMain = EwCastObject( _this->Super6.Owner, LauncherLNC_Main );

  if ( LauncherMain != 0 )
    CoreGroup_DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 0 );
  else
    EwSignal( EwNewSlot( _this, NavigationNAV06_NaviSettingMenu_ReturnToNaviHome ), 
      ((XObject)_this ));
}

/* 'C' function for method : 'Navigation::NAV06_NaviSettingMenu.LoadItemClass()' */
XClass NavigationNAV06_NaviSettingMenu_LoadItemClass( NavigationNAV06_NaviSettingMenu _this, 
  XInt32 aItemNo )
{
  XClass ItemClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemClass = 0;

  if ( aItemNo >= 0 )
    ItemClass = EW_CLASS( MenuItemBase );

  return ItemClass;
}

/* 'C' function for method : 'Navigation::NAV06_NaviSettingMenu.LoadItemTitle()' */
XString NavigationNAV06_NaviSettingMenu_LoadItemTitle( NavigationNAV06_NaviSettingMenu _this, 
  XInt32 aItemNo )
{
  XString Title = 0;

  switch ( _this->NaviSettings[ EwCheckIndex( aItemNo, 7 )])
  {
    case EnumNaviSettingItemStopNavigation :
      Title = EwGetVariantOfString( &StringsNAV06_STOP_NAVIGATION );
    break;

    case EnumNaviSettingItemSkipNextStop :
      Title = EwGetVariantOfString( &StringsNAV06_SKIP_NEXT_STOP );
    break;

    case EnumNaviSettingItemGoHome :
      Title = EwGetVariantOfString( &StringsNAV06_GO_HOME );
    break;

    case EnumNaviSettingItemGoToWork :
      Title = EwGetVariantOfString( &StringsNAV06_GO_TO_WORK );
    break;

    case EnumNaviSettingItemFavorites :
      Title = EwGetVariantOfString( &StringsNAV06_FAVORITES );
    break;

    case EnumNaviSettingItemNearbyGasStations :
      Title = EwGetVariantOfString( &StringsNAV06_NEARBY_GAS_STATIONS );
    break;

    case EnumNaviSettingItemChangeView :
      Title = EwGetVariantOfString( &StringsNAV06_CHANGE_VIEW );
    break;

    default :; 
  }

  return Title;
}

/* 'C' function for method : 'Navigation::NAV06_NaviSettingMenu.OnItemActivate()' */
void NavigationNAV06_NaviSettingMenu_OnItemActivate( NavigationNAV06_NaviSettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  MenuBaseMenuView MenuDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  MenuDialog = 0;

  switch ( _this->NaviSettings[ EwCheckIndex( aItemNo, 7 )])
  {
    case EnumNaviSettingItemStopNavigation :
    {
      _this->SelectedItem = EnumNaviSettingItemStopNavigation;
      DeviceInterfaceNavigationDeviceClass_StopRoute( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ));
    }
    break;

    case EnumNaviSettingItemSkipNextStop :
    {
      _this->SelectedItem = EnumNaviSettingItemSkipNextStop;
      DeviceInterfaceNavigationDeviceClass_SkipNextStop( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ));
    }
    break;

    case EnumNaviSettingItemGoHome :
      if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
          &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
      {
        EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->RouteOptionTriggerItem 
        = EnumNaviRouteOptionTriggerItemHOME;
        MenuDialog = ((MenuBaseMenuView)EwNewObject( NavigationNAV11_RouteOptionMenu, 
        0 ));
      }
      else
      {
        DeviceInterfaceNavigationDeviceClass_GoHome( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
        DeviceInterfaceNavigationDeviceClass ), EnumNaviRouteOptionTypeNEW_ROUTE );
        NavigationNAV06_NaviSettingMenu_UpdateHomeSetting( _this );
      }
    break;

    case EnumNaviSettingItemGoToWork :
      if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
          &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
      {
        EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->RouteOptionTriggerItem 
        = EnumNaviRouteOptionTriggerItemOFFICE;
        MenuDialog = ((MenuBaseMenuView)EwNewObject( NavigationNAV11_RouteOptionMenu, 
        0 ));
      }
      else
      {
        DeviceInterfaceNavigationDeviceClass_GoOffice( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
        DeviceInterfaceNavigationDeviceClass ), EnumNaviRouteOptionTypeNEW_ROUTE );
        NavigationNAV06_NaviSettingMenu_UpdateOfficeSetting( _this );
      }
    break;

    case EnumNaviSettingItemFavorites :
    {
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentPoiListType 
      = EnumNaviPoiListTypeFAVORITE;
      DeviceInterfaceNavigationDeviceClass_PoiListRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ), EnumNaviPoiListTypeFAVORITE, 1 );
      MenuDialog = ((MenuBaseMenuView)EwNewObject( NavigationNAV09_NAV10_PoiList, 
      0 ));
    }
    break;

    case EnumNaviSettingItemNearbyGasStations :
    {
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentPoiListType 
      = EnumNaviPoiListTypeGAS_STATION;
      DeviceInterfaceNavigationDeviceClass_PoiListRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ), EnumNaviPoiListTypeGAS_STATION, 1 );
      MenuDialog = ((MenuBaseMenuView)EwNewObject( NavigationNAV09_NAV10_PoiList, 
      0 ));
    }
    break;

    case EnumNaviSettingItemChangeView :
      MenuDialog = ((MenuBaseMenuView)EwNewObject( NavigationNAV08_NaviChageViewMenu, 
      0 ));
    break;

    default :; 
  }

  if ( MenuDialog != 0 )
    ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)MenuDialog ));
}

/* 'C' function for method : 'Navigation::NAV06_NaviSettingMenu.LoadItemEnabled()' */
XBool NavigationNAV06_NaviSettingMenu_LoadItemEnabled( NavigationNAV06_NaviSettingMenu _this, 
  XInt32 aItemNo )
{
  XBool ItemEnabled = 1;

  switch ( _this->NaviSettings[ EwCheckIndex( aItemNo, 7 )])
  {
    case EnumNaviSettingItemStopNavigation :
    break;

    case EnumNaviSettingItemSkipNextStop :
    break;

    case EnumNaviSettingItemGoHome :
    break;

    case EnumNaviSettingItemGoToWork :
    break;

    case EnumNaviSettingItemFavorites :
    break;

    case EnumNaviSettingItemNearbyGasStations :
    break;

    case EnumNaviSettingItemChangeView :
      if ( !DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
          &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
        ItemEnabled = 0;
    break;

    default :; 
  }

  return ItemEnabled;
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV06_NaviSettingMenu_OnNavigatingStatusUpdateSlot( NavigationNAV06_NaviSettingMenu _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( !DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )) 
      && ( _this->SelectedItem == EnumNaviSettingItemStopNavigation ))
  {
    _this->SelectedItem = EnumNaviSettingItemTOTAL;
    EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
    = EnumHomeTypeNAVI_DEFAULT_VIEW;
    EwSignal( EwNewSlot( _this, NavigationNAV06_NaviSettingMenu_ReturnToNaviHome ), 
      ((XObject)_this ));
  }
  else
  {
    NavigationNAV06_NaviSettingMenu_SetNaviSettingMenuItem( _this );
    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, _this->Super1.Menu.NoOfItems 
    - 1 );
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV06_NaviSettingMenu_OnViaPointUpdateSlot( NavigationNAV06_NaviSettingMenu _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->SelectedItem == EnumNaviSettingItemSkipNextStop )
  {
    _this->SelectedItem = EnumNaviSettingItemTOTAL;
    EwSignal( EwNewSlot( _this, NavigationNAV06_NaviSettingMenu_ReturnToNaviHome ), 
      ((XObject)_this ));
  }
  else
  {
    NavigationNAV06_NaviSettingMenu_SetNaviSettingMenuItem( _this );
    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, _this->Super1.Menu.NoOfItems 
    - 1 );
  }
}

/* 'C' function for method : 'Navigation::NAV06_NaviSettingMenu.SetNaviSettingMenuItem()' */
void NavigationNAV06_NaviSettingMenu_SetNaviSettingMenuItem( NavigationNAV06_NaviSettingMenu _this )
{
  XInt32 i;
  XInt32 NoOfItems = 0;
  XEnum NaviSettingItem;

  for ( i = 0; i < 7; i++ )
  {
    NaviSettingItem = (XEnum)i;

    switch ( NaviSettingItem )
    {
      case EnumNaviSettingItemStopNavigation :
        if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
            &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
        {
          _this->NaviSettings[ EwCheckIndex( NoOfItems, 7 )] = NaviSettingItem;
          NoOfItems++;
        }
      break;

      case EnumNaviSettingItemSkipNextStop :
      {
        DeviceInterfaceNaviDataClass NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( 
          EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
          EnumNaviDataTypeVIA_POINT );

        if ( NaviData != 0 )
        {
          if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
              &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )) 
              && ( NaviData->ViaPoints > 0 ))
          {
            _this->NaviSettings[ EwCheckIndex( NoOfItems, 7 )] = NaviSettingItem;
            NoOfItems++;
          }
        }
        else
          EwTrace( "%s", EwLoadString( &_Const001B ));
      }
      break;

      default : 
      {
        _this->NaviSettings[ EwCheckIndex( NoOfItems, 7 )] = NaviSettingItem;
        NoOfItems++;
      }
    }
  }

  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, NoOfItems );
}

/* 'C' function for method : 'Navigation::NAV06_NaviSettingMenu.ReturnToNaviHome()' */
void NavigationNAV06_NaviSettingMenu_ReturnToNaviHome( NavigationNAV06_NaviSettingMenu _this, 
  XObject sender )
{
  ApplicationApplication App;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
    ApplicationApplication_SwitchToHome( App, EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
    DeviceInterfaceNavigationDeviceClass )->CurrentHome );
}

/* 'C' function for method : 'Navigation::NAV06_NaviSettingMenu.UpdateHomeSetting()' */
void NavigationNAV06_NaviSettingMenu_UpdateHomeSetting( NavigationNAV06_NaviSettingMenu _this )
{
  DeviceInterfaceNaviDataClass NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( 
    EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
    EnumNaviDataTypeHOME );

  if ( NaviData != 0 )
  {
    if ( NaviData->IsHomeSet )
    {
      _this->SelectedItem = EnumNaviSettingItemTOTAL;
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
      = EnumHomeTypeNAVI_DEFAULT_VIEW;
      EwSignal( EwNewSlot( _this, NavigationNAV06_NaviSettingMenu_ReturnToNaviHome ), 
        ((XObject)_this ));
    }
    else
    {
      PopPOP03_HomeOfficeSettingError HomeSettingError = EwNewObject( PopPOP03_HomeOfficeSettingError, 
        0 );
      HomeSettingError->ReturnToNaviHomeSlot = EwNewSlot( _this, NavigationNAV06_NaviSettingMenu_ReturnToNaviHome );
      PopPOP03_HomeOfficeSettingError_OnSetErrorMessage( HomeSettingError, EwGetVariantOfString( 
      &StringsPOP03_NO_HOME_LOCATION ));
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)HomeSettingError ), 
      0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
  }
  else
    EwTrace( "%s", EwLoadString( &_Const001C ));
}

/* 'C' function for method : 'Navigation::NAV06_NaviSettingMenu.UpdateOfficeSetting()' */
void NavigationNAV06_NaviSettingMenu_UpdateOfficeSetting( NavigationNAV06_NaviSettingMenu _this )
{
  DeviceInterfaceNaviDataClass NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( 
    EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
    EnumNaviDataTypeOFFICE );

  if ( NaviData != 0 )
  {
    if ( NaviData->IsOfficeSet )
    {
      _this->SelectedItem = EnumNaviSettingItemTOTAL;
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
      = EnumHomeTypeNAVI_DEFAULT_VIEW;
      EwSignal( EwNewSlot( _this, NavigationNAV06_NaviSettingMenu_ReturnToNaviHome ), 
        ((XObject)_this ));
    }
    else
    {
      PopPOP03_HomeOfficeSettingError OfficeSettingError = EwNewObject( PopPOP03_HomeOfficeSettingError, 
        0 );
      OfficeSettingError->ReturnToNaviHomeSlot = EwNewSlot( _this, NavigationNAV06_NaviSettingMenu_ReturnToNaviHome );
      PopPOP03_HomeOfficeSettingError_OnSetErrorMessage( OfficeSettingError, EwGetVariantOfString( 
      &StringsPOP13_NO_OFFICE_LOCATION ));
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)OfficeSettingError ), 
      0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
  }
  else
    EwTrace( "%s", EwLoadString( &_Const001D ));
}

/* Variants derived from the class : 'Navigation::NAV06_NaviSettingMenu' */
EW_DEFINE_CLASS_VARIANTS( NavigationNAV06_NaviSettingMenu )
EW_END_OF_CLASS_VARIANTS( NavigationNAV06_NaviSettingMenu )

/* Virtual Method Table (VMT) for the class : 'Navigation::NAV06_NaviSettingMenu' */
EW_DEFINE_CLASS( NavigationNAV06_NaviSettingMenu, MenuBaseMenuView, NavigatingStatusUpdateEventHandler, 
                 NavigatingStatusUpdateEventHandler, NavigatingStatusUpdateEventHandler, 
                 NavigatingStatusUpdateEventHandler, SelectedItem, SelectedItem, 
                 "Navigation::NAV06_NaviSettingMenu" )
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
  NavigationNAV06_NaviSettingMenu_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  MenuBaseMenuView_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  NavigationNAV06_NaviSettingMenu_LoadItemClass,
  NavigationNAV06_NaviSettingMenu_LoadItemTitle,
  NavigationNAV06_NaviSettingMenu_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  NavigationNAV06_NaviSettingMenu_LoadItemEnabled,
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
EW_END_OF_CLASS( NavigationNAV06_NaviSettingMenu )

/* Initializer for the class 'Navigation::NAV08_NaviChageViewMenu' */
void NavigationNAV08_NaviChageViewMenu__Init( NavigationNAV08_NaviChageViewMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationNAV08_NaviChageViewMenu );

  /* ... then construct all embedded objects */
  CoreTimer__Init( &_this->CheckMarkUpdateTimer, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NaviBtThroughputUpdateEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationNAV08_NaviChageViewMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0002 );
  _this->Super2.SlideOutEffectEnabled = 1;
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 3 );
  CoreTimer_OnSetPeriod( &_this->CheckMarkUpdateTimer, 450 );
  _this->CheckMarkUpdateTimer.OnTrigger = EwNewSlot( _this, NavigationNAV08_NaviChageViewMenu_OnCheckMarkUpdateSlot );
  _this->NaviBtThroughputUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV08_NaviChageViewMenu_OnNaviBtThroughputStatusUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NaviBtThroughputUpdateEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->BtThroughputStatusUpdateEvent );

  /* Call the user defined constructor */
  NavigationNAV08_NaviChageViewMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Navigation::NAV08_NaviChageViewMenu' */
void NavigationNAV08_NaviChageViewMenu__ReInit( NavigationNAV08_NaviChageViewMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreTimer__ReInit( &_this->CheckMarkUpdateTimer );
  CoreSystemEventHandler__ReInit( &_this->NaviBtThroughputUpdateEventHandler );
}

/* Finalizer method for the class 'Navigation::NAV08_NaviChageViewMenu' */
void NavigationNAV08_NaviChageViewMenu__Done( NavigationNAV08_NaviChageViewMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CoreTimer__Done( &_this->CheckMarkUpdateTimer );
  CoreSystemEventHandler__Done( &_this->NaviBtThroughputUpdateEventHandler );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void NavigationNAV08_NaviChageViewMenu_Init( NavigationNAV08_NaviChageViewMenu _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const001E ));
}

/* 'C' function for method : 'Navigation::NAV08_NaviChageViewMenu.LoadItemClass()' */
XClass NavigationNAV08_NaviChageViewMenu_LoadItemClass( NavigationNAV08_NaviChageViewMenu _this, 
  XInt32 aItemNo )
{
  XClass ItemClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemClass = 0;

  if ( aItemNo >= 0 )
    ItemClass = EW_CLASS( MenuItemCheckMark );

  return ItemClass;
}

/* 'C' function for method : 'Navigation::NAV08_NaviChageViewMenu.LoadItemTitle()' */
XString NavigationNAV08_NaviChageViewMenu_LoadItemTitle( NavigationNAV08_NaviChageViewMenu _this, 
  XInt32 aItemNo )
{
  XString Title;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Title = 0;

  switch ( aItemNo )
  {
    case 0 :
      Title = EwGetVariantOfString( &StringsNAV08_DEFAULT_VIEW );
    break;

    case 1 :
      Title = EwGetVariantOfString( &StringsNAV08_TURN_BY_TURN );
    break;

    case 2 :
      Title = EwGetVariantOfString( &StringsNAV08_TURN_LIST );
    break;

    default :; 
  }

  return Title;
}

/* 'C' function for method : 'Navigation::NAV08_NaviChageViewMenu.OnItemActivate()' */
void NavigationNAV08_NaviChageViewMenu_OnItemActivate( NavigationNAV08_NaviChageViewMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  _this->NaviScreenIdx = aItemNo;

  switch ( aItemNo )
  {
    case 0 :
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
      = EnumHomeTypeNAVI_DEFAULT_VIEW;
    break;

    case 1 :
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
      = EnumHomeTypeNAVI_NEXT_TURN;
    break;

    case 2 :
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
      = EnumHomeTypeNAVI_TURN_BY_TURN;
    break;

    default :; 
  }

  MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, _this->Super1.Menu.NoOfItems 
  - 1 );
  CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
}

/* 'C' function for method : 'Navigation::NAV08_NaviChageViewMenu.LoadItemChecked()' */
XBool NavigationNAV08_NaviChageViewMenu_LoadItemChecked( NavigationNAV08_NaviChageViewMenu _this, 
  XInt32 aItemNo )
{
  XBool IsChecked;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsChecked = 0;

  switch ( aItemNo )
  {
    case 0 :
      if ( EnumHomeTypeNAVI_DEFAULT_VIEW == EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
          DeviceInterfaceNavigationDeviceClass )->CurrentHome )
        IsChecked = 1;
    break;

    case 1 :
      if ( EnumHomeTypeNAVI_NEXT_TURN == EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
          DeviceInterfaceNavigationDeviceClass )->CurrentHome )
        IsChecked = 1;
    break;

    case 2 :
      if ( EnumHomeTypeNAVI_TURN_BY_TURN == EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
          DeviceInterfaceNavigationDeviceClass )->CurrentHome )
        IsChecked = 1;
    break;

    default :; 
  }

  return IsChecked;
}

/* 'C' function for method : 'Navigation::NAV08_NaviChageViewMenu.LoadItemEnabled()' */
XBool NavigationNAV08_NaviChageViewMenu_LoadItemEnabled( NavigationNAV08_NaviChageViewMenu _this, 
  XInt32 aItemNo )
{
  XBool ItemEnabled;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemEnabled = 1;

  if ( aItemNo == 0 )
  {
    XEnum BtRhroughputUIMode = DeviceInterfaceNavigationDeviceClass_GetBtThroughputUIMode( 
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));

    switch ( BtRhroughputUIMode )
    {
      case EnumNaviBtThroughputUIModeBUSY :
      case EnumNaviBtThroughputUIModeTBT :
        ItemEnabled = 0;
      break;

      default :; 
    }
  }

  return ItemEnabled;
}

/* 'C' function for method : 'Navigation::NAV08_NaviChageViewMenu.OnCheckMarkUpdateSlot()' */
void NavigationNAV08_NaviChageViewMenu_OnCheckMarkUpdateSlot( NavigationNAV08_NaviChageViewMenu _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 0 );

  if ( EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
      != EnumHomeTypeTOTAL )
  {
    ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

    if ( App != 0 )
      ApplicationApplication_SwitchToHome( App, EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass )->CurrentHome );
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV08_NaviChageViewMenu_OnNaviBtThroughputStatusUpdateSlot( NavigationNAV08_NaviChageViewMenu _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, _this->Super1.Menu.NoOfItems 
  - 1 );
}

/* Variants derived from the class : 'Navigation::NAV08_NaviChageViewMenu' */
EW_DEFINE_CLASS_VARIANTS( NavigationNAV08_NaviChageViewMenu )
EW_END_OF_CLASS_VARIANTS( NavigationNAV08_NaviChageViewMenu )

/* Virtual Method Table (VMT) for the class : 'Navigation::NAV08_NaviChageViewMenu' */
EW_DEFINE_CLASS( NavigationNAV08_NaviChageViewMenu, MenuBaseMenuView, CheckMarkUpdateTimer, 
                 CheckMarkUpdateTimer, CheckMarkUpdateTimer, CheckMarkUpdateTimer, 
                 NaviScreenIdx, NaviScreenIdx, "Navigation::NAV08_NaviChageViewMenu" )
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
  NavigationNAV08_NaviChageViewMenu_LoadItemClass,
  NavigationNAV08_NaviChageViewMenu_LoadItemTitle,
  NavigationNAV08_NaviChageViewMenu_OnItemActivate,
  NavigationNAV08_NaviChageViewMenu_LoadItemChecked,
  NavigationNAV08_NaviChageViewMenu_LoadItemEnabled,
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
EW_END_OF_CLASS( NavigationNAV08_NaviChageViewMenu )

/* Initializer for the class 'Navigation::NaviCurrentRoad' */
void NavigationNaviCurrentRoad__Init( NavigationNaviCurrentRoad _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationNaviCurrentRoad );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->NaviIconCurRd, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->RoadNameText, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationNaviCurrentRoad );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const001F );
  CoreRectView__OnSetBounds( &_this->NaviIconCurRd, _Const0020 );
  ViewsImage_OnSetVisible( &_this->NaviIconCurRd, 0 );
  CoreRectView__OnSetBounds( &_this->RoadNameText, _Const0021 );
  ViewsText_OnSetAlignment((ViewsText)&_this->RoadNameText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString((ViewsText)&_this->RoadNameText, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviIconCurRd ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RoadNameText ), 0 );
  ViewsImage_OnSetBitmap( &_this->NaviIconCurRd, EwLoadResource( &ResourceCurRdIcon, 
  ResourcesBitmap ));
  ViewsText_OnSetFont((ViewsText)&_this->RoadNameText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Navigation::NaviCurrentRoad' */
void NavigationNaviCurrentRoad__ReInit( NavigationNaviCurrentRoad _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->NaviIconCurRd );
  ComponentsBaseText__ReInit( &_this->RoadNameText );
}

/* Finalizer method for the class 'Navigation::NaviCurrentRoad' */
void NavigationNaviCurrentRoad__Done( NavigationNaviCurrentRoad _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->NaviIconCurRd );
  ComponentsBaseText__Done( &_this->RoadNameText );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Navigation::NaviCurrentRoad.SetItemBounds()' */
void NavigationNaviCurrentRoad_SetItemBounds( NavigationNaviCurrentRoad _this, XBool 
  IsAnimationStarted )
{
  if ( EwCompRect( _this->RoadNameText.Super2.Bounds, _this->RoadNameTextBounds ))
    CoreRectView__OnSetBounds( &_this->RoadNameText, _this->RoadNameTextBounds );

  if ( EwCompRect( _this->NaviIconCurRd.Super1.Bounds, _Const0020 ))
    CoreRectView__OnSetBounds( &_this->NaviIconCurRd, _Const0020 );

  if ( !ViewsImage_OnGetVisible( &_this->NaviIconCurRd ))
    ViewsImage_OnSetVisible( &_this->NaviIconCurRd, 1 );

  ViewsText_OnSetEllipsis((ViewsText)&_this->RoadNameText, 0 );

  if ( EwGetRectW( ViewsText_GetContentArea((ViewsText)&_this->RoadNameText )) < 
      EwGetRectW( _this->RoadNameText.Super2.Bounds ))
  {
    XRect NewRoadNameBounds = _Const0018;
    XRect NewCurIcnBounds;
    NewRoadNameBounds.Point1.X = ViewsText_GetContentArea((ViewsText)&_this->RoadNameText ).Point1.X;
    NewRoadNameBounds.Point2.X = ( NewRoadNameBounds.Point1.X + EwGetRectW( ViewsText_GetContentArea((ViewsText)&_this->RoadNameText )));
    NewRoadNameBounds.Point1.Y = _this->RoadNameText.Super2.Bounds.Point1.Y;
    NewRoadNameBounds.Point2.Y = _this->RoadNameText.Super2.Bounds.Point2.Y;
    CoreRectView__OnSetBounds( &_this->RoadNameText, NewRoadNameBounds );
    NewCurIcnBounds = _Const0018;
    NewCurIcnBounds.Point1.X = ( _this->RoadNameText.Super2.Bounds.Point1.X - 24 );
    NewCurIcnBounds.Point2.X = ( NewCurIcnBounds.Point1.X + EwGetRectW( _this->NaviIconCurRd.Super1.Bounds ));
    NewCurIcnBounds.Point1.Y = _this->NaviIconCurRd.Super1.Bounds.Point1.Y;
    NewCurIcnBounds.Point2.Y = _this->NaviIconCurRd.Super1.Bounds.Point2.Y;
    CoreRectView__OnSetBounds( &_this->NaviIconCurRd, NewCurIcnBounds );
  }
  else
  {
    ViewsText_OnSetAlignment((ViewsText)&_this->RoadNameText, ViewsTextAlignmentAlignHorzLeft 
    | ViewsTextAlignmentAlignVertCenter );
    ViewsText_OnSetEllipsis((ViewsText)&_this->RoadNameText, 1 );
  }

  if ( !IsAnimationStarted )
    _this->NaviIconX1Pos = _this->NaviIconCurRd.Super1.Bounds.Point1.X;
}

/* 'C' function for method : 'Navigation::NaviCurrentRoad.OnSetRoadName()' */
void NavigationNaviCurrentRoad_OnSetRoadName( NavigationNaviCurrentRoad _this, XString 
  value )
{
  _this->RoadName = EwShareString( value );
  ViewsText_OnSetString((ViewsText)&_this->RoadNameText, _this->RoadName );

  if ( !EwCompString( _this->RoadNameText.Super1.String, 0 ))
    ViewsText_OnSetString((ViewsText)&_this->RoadNameText, EwLoadString( &_Const0022 ));
}

/* 'C' function for method : 'Navigation::NaviCurrentRoad.UpdateItemBounds()' */
void NavigationNaviCurrentRoad_UpdateItemBounds( NavigationNaviCurrentRoad _this, 
  XEnum aAnimationType, XInt32 aNewWidth )
{
  switch ( aAnimationType )
  {
    case EnumNaviAlertAnimationTypeShrink :
      ViewsText_OnSetAlignment((ViewsText)&_this->RoadNameText, ViewsTextAlignmentAlignHorzLeft 
      | ViewsTextAlignmentAlignVertCenter );
    break;

    case EnumNaviAlertAnimationTypeDismiss :
      ViewsText_OnSetAlignment((ViewsText)&_this->RoadNameText, ViewsTextAlignmentAlignHorzCenter 
      | ViewsTextAlignmentAlignVertCenter );
    break;

    default :; 
  }

  _this->RoadNameTextBounds.Point2.X = ( _this->RoadNameTextBounds.Point1.X + ( 
  aNewWidth - ( EwGetRectW( _this->NaviIconCurRd.Super1.Bounds ) + 4 )));
  NavigationNaviCurrentRoad_SetItemBounds( _this, 1 );
}

/* Variants derived from the class : 'Navigation::NaviCurrentRoad' */
EW_DEFINE_CLASS_VARIANTS( NavigationNaviCurrentRoad )
EW_END_OF_CLASS_VARIANTS( NavigationNaviCurrentRoad )

/* Virtual Method Table (VMT) for the class : 'Navigation::NaviCurrentRoad' */
EW_DEFINE_CLASS( NavigationNaviCurrentRoad, CoreGroup, NaviIconCurRd, NaviIconCurRd, 
                 NaviIconCurRd, NaviIconCurRd, RoadName, NaviIconX1Pos, "Navigation::NaviCurrentRoad" )
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
EW_END_OF_CLASS( NavigationNaviCurrentRoad )

/* Initializer for the class 'Navigation::NaviAlert' */
void NavigationNaviAlert__Init( NavigationNaviAlert _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationNaviAlert );

  /* ... then construct all embedded objects */
  NavigationNaviAlertMessage__Init( &_this->AlertMessage, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->NaviDistBg, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->DistUnit, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Distance, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->SuspendTimer, &_this->_.XObject, 0 );
  EffectsRectEffect__Init( &_this->NaviEventShrinkEffect, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->AlertDistanceUpdate, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationNaviAlert );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0023 );
  CoreRectView__OnSetBounds( &_this->AlertMessage, NavigationALERT_MESSAGE_BOUNDS );
  CoreRectView__OnSetBounds( &_this->NaviDistBg, _Const0024 );
  ViewsRectangle_OnSetColor( &_this->NaviDistBg, _Const0025 );
  CoreRectView__OnSetBounds( &_this->DistUnit, _Const0026 );
  ViewsText_OnSetAlignment( &_this->DistUnit, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DistUnit, 0 );
  CoreRectView__OnSetBounds( &_this->Distance, _Const0027 );
  ViewsText_OnSetAlignment( &_this->Distance, ViewsTextAlignmentAlignHorzRight | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Distance, 0 );
  CoreTimer_OnSetPeriod( &_this->SuspendTimer, 8000 );
  _this->DistUnitTextArray[ 0 ] = EwShareString( EwLoadString( &_Const0028 ));
  _this->DistUnitTextArray[ 1 ] = EwShareString( EwLoadString( &_Const0029 ));
  _this->SpeedUnitTextArray[ 0 ] = EwShareString( EwLoadString( &_Const002A ));
  _this->SpeedUnitTextArray[ 1 ] = EwShareString( EwLoadString( &_Const002B ));
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->NaviEventShrinkEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->NaviEventShrinkEffect, 
  500 );
  _this->NaviEventShrinkEffect.Value2 = _Const002C;
  _this->NaviEventShrinkEffect.Value1 = _Const0023;
  CoreGroup__Add( _this, ((CoreView)&_this->AlertMessage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviDistBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DistUnit ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Distance ), 0 );
  ViewsText_OnSetFont( &_this->DistUnit, EwLoadResource( &FontsNotoSansMedium16pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->Distance, EwLoadResource( &FontsNotoSansMedium22pt, 
  ResourcesFont ));
  _this->SuspendTimer.OnTrigger = EwNewSlot( _this, NavigationNaviAlert_OnSuspendUpdateSlot );
  _this->NaviEventShrinkEffect.Super1.OnFinished = EwNewSlot( _this, NavigationNaviAlert_OnNaviEventShrinkFinishSlot );
  _this->NaviEventShrinkEffect.Outlet = EwNewRef( &_this->AlertMessage, CoreRectView_OnGetBounds, 
  CoreRectView__OnSetBounds );
  _this->AlertDistanceUpdate.OnEvent = EwNewSlot( _this, NavigationNaviAlert_OnAlertDistanceUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->AlertDistanceUpdate, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->AlertDistanceUpdateEvent );
}

/* Re-Initializer for the class 'Navigation::NaviAlert' */
void NavigationNaviAlert__ReInit( NavigationNaviAlert _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  NavigationNaviAlertMessage__ReInit( &_this->AlertMessage );
  ViewsRectangle__ReInit( &_this->NaviDistBg );
  ViewsText__ReInit( &_this->DistUnit );
  ViewsText__ReInit( &_this->Distance );
  CoreTimer__ReInit( &_this->SuspendTimer );
  EffectsRectEffect__ReInit( &_this->NaviEventShrinkEffect );
  CoreSystemEventHandler__ReInit( &_this->AlertDistanceUpdate );
}

/* Finalizer method for the class 'Navigation::NaviAlert' */
void NavigationNaviAlert__Done( NavigationNaviAlert _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  NavigationNaviAlertMessage__Done( &_this->AlertMessage );
  ViewsRectangle__Done( &_this->NaviDistBg );
  ViewsText__Done( &_this->DistUnit );
  ViewsText__Done( &_this->Distance );
  CoreTimer__Done( &_this->SuspendTimer );
  EffectsRectEffect__Done( &_this->NaviEventShrinkEffect );
  CoreSystemEventHandler__Done( &_this->AlertDistanceUpdate );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Navigation::NaviAlert.ShrinkAlert()' */
void NavigationNaviAlert_ShrinkAlert( NavigationNaviAlert _this )
{
  _this->IsEnlargeFinished = 1;
  CoreTimer_OnSetEnabled( &_this->SuspendTimer, 1 );
}

/* 'C' function for method : 'Navigation::NaviAlert.OnSuspendUpdateSlot()' */
void NavigationNaviAlert_OnSuspendUpdateSlot( NavigationNaviAlert _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->SuspendTimer, 0 );

  if ( _this->IsEnlargeFinished )
  {
    _this->IsEnlargeFinished = 0;
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->NaviEventShrinkEffect, 1 );
  }
  else
    if ( _this->IsShrinkFinished )
    {
      _this->IsShrinkFinished = 0;
      CoreTimer_OnSetPeriod( &_this->SuspendTimer, 8000 );
      EwSignal( _this->DismissAlertSignal, ((XObject)_this ));
    }
}

/* 'C' function for method : 'Navigation::NaviAlert.SetAlert()' */
void NavigationNaviAlert_SetAlert( NavigationNaviAlert _this, XEnum aNaviEventType, 
  XEnum aNaviCameraType, XString aNaviEventSpeed, XString aNaviEventDist )
{
  XInt32 i;
  XInt32 idx;

  switch ( aNaviEventType )
  {
    case EnumNaviAlertTypeBORDER :
    {
      NavigationNaviAlertMessage_OnSetIsSpeedDisplayed( &_this->AlertMessage, 0 );
      NavigationNaviAlert_SetCamera( _this, aNaviCameraType );
      NavigationNaviAlertMessage_OnSetColor( &_this->AlertMessage, ColorNAVI_ORANGE );
      ViewsRectangle_OnSetColor( &_this->NaviDistBg, ColorNAVI_ORANGE );
    }
    break;

    case EnumNaviAlertTypeSCHOOL :
    {
      NavigationNaviAlertMessage_OnSetIsSpeedDisplayed( &_this->AlertMessage, 0 );
      NavigationNaviAlertMessage_OnSetIcon( &_this->AlertMessage, EwLoadResource( 
      &ResourceSafeCamSchoolZone, ResourcesBitmap ));
      NavigationNaviAlertMessage_OnSetMessage( &_this->AlertMessage, EwLoadString( 
      &StringsNAV01_SCHOOL_ZONE ));
      NavigationNaviAlertMessage_OnSetColor( &_this->AlertMessage, ColorNAVI_ORANGE );
      ViewsRectangle_OnSetColor( &_this->NaviDistBg, ColorNAVI_ORANGE );
    }
    break;

    case EnumNaviAlertTypeCAMERA :
    {
      NavigationNaviAlertMessage_OnSetIsSpeedDisplayed( &_this->AlertMessage, 1 );
      NavigationNaviAlert_SetCamera( _this, aNaviCameraType );
      NavigationNaviAlertMessage_OnSetColor( &_this->AlertMessage, ColorNAVI_RED );
      ViewsRectangle_OnSetColor( &_this->NaviDistBg, ColorNAVI_RED );
    }
    break;

    default :; 
  }

  if ( EwCompString( aNaviEventSpeed, 0 ) != 0 )
  {
    for ( i = 0; i < 2; i++ )
    {
      idx = EwStringFind( aNaviEventSpeed, _this->SpeedUnitTextArray[ EwCheckIndex( 
      i, 2 )], 0 );

      if ( idx > -1 )
      {
        ViewsText_OnSetString( &_this->AlertMessage.NaviSpeedUnit, _this->SpeedUnitTextArray[ 
        EwCheckIndex( i, 2 )]);
        aNaviEventSpeed = EwStringRemove( aNaviEventSpeed, idx - 1, EwGetStringLength( 
        _this->SpeedUnitTextArray[ EwCheckIndex( i, 2 )]) + 1 );
        break;
      }
    }

    ViewsText_OnSetString( &_this->AlertMessage.NaviSpeed, aNaviEventSpeed );
  }

  for ( i = 0; i < 2; i++ )
  {
    idx = EwStringFind( aNaviEventDist, _this->DistUnitTextArray[ EwCheckIndex( 
    i, 2 )], 0 );

    if ( idx > -1 )
    {
      ViewsText_OnSetString( &_this->DistUnit, _this->DistUnitTextArray[ EwCheckIndex( 
      i, 2 )]);
      aNaviEventDist = EwStringRemove( aNaviEventDist, idx - 1, EwGetStringLength( 
      _this->DistUnitTextArray[ EwCheckIndex( i, 2 )]) + 1 );
      break;
    }
  }

  ViewsText_OnSetString( &_this->Distance, aNaviEventDist );
}

/* 'C' function for method : 'Navigation::NaviAlert.OnNaviEventShrinkFinishSlot()' */
void NavigationNaviAlert_OnNaviEventShrinkFinishSlot( NavigationNaviAlert _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->NaviEventShrinkEffect, 0 );
  _this->IsShrinkFinished = 1;
  CoreTimer_OnSetPeriod( &_this->SuspendTimer, 3000 );
  CoreTimer_OnSetEnabled( &_this->SuspendTimer, 1 );
}

/* 'C' function for method : 'Navigation::NaviAlert.SetCamera()' */
void NavigationNaviAlert_SetCamera( NavigationNaviAlert _this, XEnum aNaviCameraType )
{
  switch ( aNaviCameraType )
  {
    case EnumNaviCameraTypeCHECK_FIXED :
    {
      NavigationNaviAlertMessage_OnSetIcon( &_this->AlertMessage, EwLoadResource( 
      &ResourceSafeCamEU, ResourcesBitmap ));
      NavigationNaviAlertMessage_OnSetMessage( &_this->AlertMessage, EwLoadString( 
      &StringsNAV01_CHECK_FIXED ));
    }
    break;

    case EnumNaviCameraTypeCHECK_TEMPORARY :
    {
      NavigationNaviAlertMessage_OnSetIcon( &_this->AlertMessage, EwLoadResource( 
      &ResourceSafeCamTempEU, ResourcesBitmap ));
      NavigationNaviAlertMessage_OnSetMessage( &_this->AlertMessage, EwLoadString( 
      &StringsNAV01_CHECK_TEMPORARY ));
    }
    break;

    case EnumNaviCameraTypeMOBILE :
    {
      NavigationNaviAlertMessage_OnSetIcon( &_this->AlertMessage, EwLoadResource( 
      &ResourceSafeCamMobileEU, ResourcesBitmap ));
      NavigationNaviAlertMessage_OnSetMessage( &_this->AlertMessage, EwLoadString( 
      &StringsNAV01_MOBILE ));
    }
    break;

    case EnumNaviCameraTypeAVERAGE :
    {
      NavigationNaviAlertMessage_OnSetIcon( &_this->AlertMessage, EwLoadResource( 
      &ResourceSafeAvrgCamEU, ResourcesBitmap ));
      NavigationNaviAlertMessage_OnSetMessage( &_this->AlertMessage, EwLoadString( 
      &StringsNAV01_AVERAGE ));
    }
    break;

    case EnumNaviCameraTypeVARIABLE :
    {
      NavigationNaviAlertMessage_OnSetIcon( &_this->AlertMessage, EwLoadResource( 
      &ResourceSafeCamVariableEU, ResourcesBitmap ));
      NavigationNaviAlertMessage_OnSetMessage( &_this->AlertMessage, EwLoadString( 
      &StringsNAV01_VARIABLE ));
    }
    break;

    case EnumNaviCameraTypeRED_LIGHT :
    {
      NavigationNaviAlertMessage_OnSetIcon( &_this->AlertMessage, EwLoadResource( 
      &ResourceSafeCamRedLight, ResourcesBitmap ));
      NavigationNaviAlertMessage_OnSetMessage( &_this->AlertMessage, EwLoadString( 
      &StringsNAV01_RED_LIGHT ));
    }
    break;

    case EnumNaviCameraTypeUSER :
    {
      NavigationNaviAlertMessage_OnSetIcon( &_this->AlertMessage, EwLoadResource( 
      &ResourceSafeCamRealTimeEU, ResourcesBitmap ));
      NavigationNaviAlertMessage_OnSetMessage( &_this->AlertMessage, EwLoadString( 
      &StringsNAV01_USER ));
    }
    break;

    case EnumNaviCameraTypeMOBILE_ZONE :
    {
      NavigationNaviAlertMessage_OnSetIcon( &_this->AlertMessage, EwLoadResource( 
      &ResourceSafeCamLifemobileEU, ResourcesBitmap ));
      NavigationNaviAlertMessage_OnSetMessage( &_this->AlertMessage, EwLoadString( 
      &StringsNAV01_MOBILE_ZONE ));
    }
    break;

    case EnumNaviCameraTypeDANGEROUS_ZONE :
    case EnumNaviCameraTypeDANGEROUS_POINT :
    {
      NavigationNaviAlertMessage_OnSetIcon( &_this->AlertMessage, EwLoadResource( 
      &ResourceSafeCamRiskZone, ResourcesBitmap ));
      NavigationNaviAlertMessage_OnSetMessage( &_this->AlertMessage, EwLoadString( 
      &StringsNAV01_DANGEROUS_ZONE ));
    }
    break;

    case EnumNaviCameraTypeRISK_ZONE :
    {
      NavigationNaviAlertMessage_OnSetIcon( &_this->AlertMessage, EwLoadResource( 
      &ResourceSafeCamRiskZone, ResourcesBitmap ));
      NavigationNaviAlertMessage_OnSetMessage( &_this->AlertMessage, EwLoadString( 
      &StringsNAV01_RISK_ZONE ));
    }
    break;

    case EnumNaviCameraTypeUNKNOWN :
    {
      NavigationNaviAlertMessage_OnSetIcon( &_this->AlertMessage, EwLoadResource( 
      &ResourceSafeCamMobileNA, ResourcesBitmap ));
      NavigationNaviAlertMessage_OnSetMessage( &_this->AlertMessage, EwLoadString( 
      &StringsNAV01_UNKNOWN ));
    }
    break;

    case EnumNaviCameraTypeSTATE_BORDER :
    {
      NavigationNaviAlertMessage_OnSetIcon( &_this->AlertMessage, EwLoadResource( 
      &ResourceSafeBorder, ResourcesBitmap ));
      NavigationNaviAlertMessage_OnSetMessage( &_this->AlertMessage, EwLoadString( 
      &StringsNAV01_STATE_BORDER ));
    }
    break;

    case EnumNaviCameraTypeCOUNTRY_BORDER :
    {
      NavigationNaviAlertMessage_OnSetIcon( &_this->AlertMessage, EwLoadResource( 
      &ResourceSafeBorder, ResourcesBitmap ));
      NavigationNaviAlertMessage_OnSetMessage( &_this->AlertMessage, EwLoadString( 
      &StringsNAV01_COUNTRY_BORDER ));
    }
    break;

    default :; 
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNaviAlert_OnAlertDistanceUpdateSlot( NavigationNaviAlert _this, XObject 
  sender )
{
  XString distance;
  XInt32 i;
  XInt32 idx;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  distance = DeviceInterfaceNavigationDeviceClass_GetAlertDistance( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));

  for ( i = 0; i < 2; i++ )
  {
    idx = EwStringFind( distance, _this->DistUnitTextArray[ EwCheckIndex( i, 2 )], 
    0 );

    if ( idx > -1 )
    {
      ViewsText_OnSetString( &_this->DistUnit, _this->DistUnitTextArray[ EwCheckIndex( 
      i, 2 )]);
      ViewsText_OnSetString( &_this->Distance, EwStringRemove( distance, idx - 1, 
      EwGetStringLength( _this->DistUnitTextArray[ EwCheckIndex( i, 2 )]) + 1 ));
      break;
    }
  }
}

/* Variants derived from the class : 'Navigation::NaviAlert' */
EW_DEFINE_CLASS_VARIANTS( NavigationNaviAlert )
EW_END_OF_CLASS_VARIANTS( NavigationNaviAlert )

/* Virtual Method Table (VMT) for the class : 'Navigation::NaviAlert' */
EW_DEFINE_CLASS( NavigationNaviAlert, CoreGroup, DismissAlertSignal, DismissAlertSignal, 
                 AlertMessage, AlertMessage, DistUnitTextArray, IsEnlargeFinished, 
                 "Navigation::NaviAlert" )
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
EW_END_OF_CLASS( NavigationNaviAlert )

/* Initializer for the class 'Navigation::NaviAlertMessage' */
void NavigationNaviAlertMessage__Init( NavigationNaviAlertMessage _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationNaviAlertMessage );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->NaviEventBg, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->NaviAlertIcon, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->EventType, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->NaviSpeed, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->NaviSpeedUnit, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationNaviAlertMessage );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const002D );
  CoreRectView__OnSetBounds( &_this->NaviEventBg, _Const002D );
  ViewsRectangle_OnSetColor( &_this->NaviEventBg, _Const0025 );
  ViewsRectangle_OnSetVisible( &_this->NaviEventBg, 1 );
  CoreRectView__OnSetBounds( &_this->NaviAlertIcon, _Const002E );
  CoreRectView__OnSetBounds( &_this->EventType, _Const002F );
  ViewsText_OnSetAlignment((ViewsText)&_this->EventType, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString((ViewsText)&_this->EventType, 0 );
  CoreRectView__OnSetBounds( &_this->NaviSpeed, _Const0030 );
  ViewsText_OnSetAlignment( &_this->NaviSpeed, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->NaviSpeed, 0 );
  ViewsText_OnSetVisible( &_this->NaviSpeed, 0 );
  CoreRectView__OnSetBounds( &_this->NaviSpeedUnit, _Const0031 );
  ViewsText_OnSetAlignment( &_this->NaviSpeedUnit, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->NaviSpeedUnit, 0 );
  ViewsText_OnSetVisible( &_this->NaviSpeedUnit, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviEventBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviAlertIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->EventType ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviSpeed ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviSpeedUnit ), 0 );
  ViewsText_OnSetFont((ViewsText)&_this->EventType, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->NaviSpeed, EwLoadResource( &FontsNotoSansMedium22pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->NaviSpeedUnit, EwLoadResource( &FontsNotoSansMedium16pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Navigation::NaviAlertMessage' */
void NavigationNaviAlertMessage__ReInit( NavigationNaviAlertMessage _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->NaviEventBg );
  ViewsImage__ReInit( &_this->NaviAlertIcon );
  ComponentsBaseText__ReInit( &_this->EventType );
  ViewsText__ReInit( &_this->NaviSpeed );
  ViewsText__ReInit( &_this->NaviSpeedUnit );
}

/* Finalizer method for the class 'Navigation::NaviAlertMessage' */
void NavigationNaviAlertMessage__Done( NavigationNaviAlertMessage _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->NaviEventBg );
  ViewsImage__Done( &_this->NaviAlertIcon );
  ComponentsBaseText__Done( &_this->EventType );
  ViewsText__Done( &_this->NaviSpeed );
  ViewsText__Done( &_this->NaviSpeedUnit );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Navigation::NaviAlertMessage.OnSetIsSpeedDisplayed()' */
void NavigationNaviAlertMessage_OnSetIsSpeedDisplayed( NavigationNaviAlertMessage _this, 
  XBool value )
{
  if ( _this->IsSpeedDisplayed != value )
  {
    _this->IsSpeedDisplayed = value;
    ViewsText_OnSetVisible( &_this->NaviSpeed, value );
    ViewsText_OnSetVisible( &_this->NaviSpeedUnit, value );
  }
}

/* 'C' function for method : 'Navigation::NaviAlertMessage.OnSetColor()' */
void NavigationNaviAlertMessage_OnSetColor( NavigationNaviAlertMessage _this, XColor 
  value )
{
  _this->Color = value;
  ViewsRectangle_OnSetColor( &_this->NaviEventBg, value );
}

/* 'C' function for method : 'Navigation::NaviAlertMessage.OnSetIcon()' */
void NavigationNaviAlertMessage_OnSetIcon( NavigationNaviAlertMessage _this, ResourcesBitmap 
  value )
{
  _this->Icon = value;
  ViewsImage_OnSetBitmap( &_this->NaviAlertIcon, value );
}

/* 'C' function for method : 'Navigation::NaviAlertMessage.OnSetMessage()' */
void NavigationNaviAlertMessage_OnSetMessage( NavigationNaviAlertMessage _this, 
  XString value )
{
  _this->Message = EwShareString( value );
  ViewsText_OnSetString((ViewsText)&_this->EventType, value );
}

/* Variants derived from the class : 'Navigation::NaviAlertMessage' */
EW_DEFINE_CLASS_VARIANTS( NavigationNaviAlertMessage )
EW_END_OF_CLASS_VARIANTS( NavigationNaviAlertMessage )

/* Virtual Method Table (VMT) for the class : 'Navigation::NaviAlertMessage' */
EW_DEFINE_CLASS( NavigationNaviAlertMessage, CoreGroup, Icon, NaviEventBg, NaviEventBg, 
                 NaviEventBg, Message, Color, "Navigation::NaviAlertMessage" )
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
EW_END_OF_CLASS( NavigationNaviAlertMessage )

/* Initializer for the class 'Navigation::NaviETA' */
void NavigationNaviETA__Init( NavigationNaviETA _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationNaviETA );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->NaviIconFlag, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->TimeText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->AmPmText, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationNaviETA );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0032 );
  CoreRectView__OnSetBounds( &_this->NaviIconFlag, _Const0033 );
  ViewsImage_OnSetVisible( &_this->NaviIconFlag, 1 );
  CoreRectView__OnSetBounds( &_this->TimeText, _Const0034 );
  ViewsText_OnSetAlignment((ViewsText)&_this->TimeText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString((ViewsText)&_this->TimeText, 0 );
  ViewsText_OnSetVisible((ViewsText)&_this->TimeText, 0 );
  CoreRectView__OnSetBounds( &_this->AmPmText, _Const0035 );
  ViewsText_OnSetAlignment( &_this->AmPmText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->AmPmText, 0 );
  ViewsText_OnSetVisible( &_this->AmPmText, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviIconFlag ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->AmPmText ), 0 );
  ViewsImage_OnSetBitmap( &_this->NaviIconFlag, EwLoadResource( &ResourceFlagIcon, 
  ResourcesBitmap ));
  ViewsText_OnSetFont((ViewsText)&_this->TimeText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->AmPmText, EwLoadResource( &FontsNotoSansMedium16pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Navigation::NaviETA' */
void NavigationNaviETA__ReInit( NavigationNaviETA _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->NaviIconFlag );
  ComponentsBaseText__ReInit( &_this->TimeText );
  ViewsText__ReInit( &_this->AmPmText );
}

/* Finalizer method for the class 'Navigation::NaviETA' */
void NavigationNaviETA__Done( NavigationNaviETA _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->NaviIconFlag );
  ComponentsBaseText__Done( &_this->TimeText );
  ViewsText__Done( &_this->AmPmText );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Navigation::NaviETA.OnSetETA()' */
void NavigationNaviETA_OnSetETA( NavigationNaviETA _this, XInt32 value )
{
  _this->ETA = value;
  ViewsText_OnSetVisible((ViewsText)&_this->TimeText, 1 );

  if (( value > 0 ) && DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( 
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
  {
    NavigationNaviETA_FormatTime( _this );
    ViewsText_OnSetAlignment((ViewsText)&_this->TimeText, ViewsTextAlignmentAlignHorzRight 
    | ViewsTextAlignmentAlignVertCenter );
    CoreRectView__OnSetBounds( &_this->TimeText, NavigationTIMETEXT_W_NAVI_BOUNDS );
    CoreRectView__OnSetBounds( &_this->NaviIconFlag, NavigationNAVIFLAG_W_NAVI_BOUNDS );
    ViewsText_OnSetVisible( &_this->AmPmText, 1 );
  }
  else
  {
    ViewsText_OnSetString((ViewsText)&_this->TimeText, EwLoadString( &_Const0036 ));
    ViewsText_OnSetVisible( &_this->AmPmText, 0 );
  }
}

/* 'C' function for method : 'Navigation::NaviETA.FormatTime()' */
void NavigationNaviETA_FormatTime( NavigationNaviETA _this )
{
  XString eta;
  XInt32 hour;
  XInt32 min;

  hour = _this->ETA / 60;
  min = _this->ETA % 60;

  if ( hour > 0 )
  {
    if ( hour < 12 )
      ViewsText_OnSetString( &_this->AmPmText, EwLoadString( &_Const0037 ));
    else
    {
      ViewsText_OnSetString( &_this->AmPmText, EwLoadString( &_Const0038 ));

      if ( hour > 12 )
        hour = hour - 12;
    }

    if ( min < 10 )
      eta = EwConcatString( EwConcatString( EwNewStringInt( hour, 0, 10 ), EwLoadString( 
      &_Const0039 )), EwNewStringInt( min, 0, 10 ));
    else
      eta = EwConcatString( EwConcatString( EwNewStringInt( hour, 0, 10 ), EwLoadString( 
      &_Const003A )), EwNewStringInt( min, 0, 10 ));
  }
  else
  {
    if ( min < 10 )
      eta = EwConcatString( EwLoadString( &_Const003B ), EwNewStringInt( min, 0, 
      10 ));
    else
      eta = EwConcatString( EwLoadString( &_Const003C ), EwNewStringInt( min, 0, 
      10 ));

    ViewsText_OnSetString( &_this->AmPmText, EwLoadString( &_Const0037 ));
  }

  ViewsText_OnSetString((ViewsText)&_this->TimeText, eta );
}

/* Variants derived from the class : 'Navigation::NaviETA' */
EW_DEFINE_CLASS_VARIANTS( NavigationNaviETA )
EW_END_OF_CLASS_VARIANTS( NavigationNaviETA )

/* Virtual Method Table (VMT) for the class : 'Navigation::NaviETA' */
EW_DEFINE_CLASS( NavigationNaviETA, CoreGroup, NaviIconFlag, NaviIconFlag, NaviIconFlag, 
                 NaviIconFlag, ETA, ETA, "Navigation::NaviETA" )
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
EW_END_OF_CLASS( NavigationNaviETA )

/* Initializer for the class 'Navigation::NAV05_TBTView' */
void NavigationNAV05_TBTView__Init( NavigationNAV05_TBTView _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  HomeBaseHome__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationNAV05_TBTView );

  /* ... then construct all embedded objects */
  ViewsWallpaper__Init( &_this->NaviTBTViewBg, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->ArrivalBg, &_this->_.XObject, 0 );
  NavigationNaviETA__Init( &_this->ETAComponent, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->RoadNameBg, &_this->_.XObject, 0 );
  NavigationNaviCurrentRoad__Init( &_this->CurrentRoadComponent, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->SpeedLimitIcon, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->SpeedLimitText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->NextTurnDist, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->NextTurnDistUnit, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->NextTurnDescription, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->NextTurnIcon, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ETAUpdateEventHandler, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->CurRdUpdateEventHandler, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->RecalculateMessage, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->Mask, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->BtLoadingAnimation, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->BtLoadingIcon, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->TbtListUpdateEventHandler, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->SpeedLimitUpdateEventHandler, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->SpeedLimitFlickeringTimer, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->RouteCalProgressUpdateEventHandler, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NavigatingStatusUpdateEventHandler, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NaviDisconnectEventHandler, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NaviBtThroughputUpdateEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationNAV05_TBTView );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0002 );
  _this->Super1.HomeType = EnumHomeTypeNAVI_NEXT_TURN;
  CoreRectView__OnSetBounds( &_this->NaviTBTViewBg, _Const003D );
  CoreRectView__OnSetBounds( &_this->ArrivalBg, _Const0003 );
  ViewsRectangle_OnSetColor( &_this->ArrivalBg, _Const0004 );
  ViewsRectangle_OnSetVisible( &_this->ArrivalBg, 1 );
  CoreRectView__OnSetBounds( &_this->ETAComponent, _Const0005 );
  CoreRectView__OnSetBounds( &_this->RoadNameBg, _Const0006 );
  ViewsRectangle_OnSetColor( &_this->RoadNameBg, _Const0007 );
  CoreRectView__OnSetBounds( &_this->CurrentRoadComponent, _Const0019 );
  CoreRectView__OnSetBounds( &_this->SpeedLimitIcon, _Const000C );
  ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 0 );
  CoreRectView__OnSetBounds( &_this->SpeedLimitText, _Const000D );
  ViewsText_OnSetString( &_this->SpeedLimitText, 0 );
  ViewsText_OnSetColor( &_this->SpeedLimitText, _Const0001 );
  ViewsText_OnSetVisible( &_this->SpeedLimitText, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnDist, _Const003E );
  ViewsText_OnSetVisible( &_this->NextTurnDist, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnDistUnit, _Const003F );
  ViewsText_OnSetVisible((ViewsText)&_this->NextTurnDistUnit, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnDescription, _Const0040 );
  ViewsText_OnSetEllipsis((ViewsText)&_this->NextTurnDescription, 1 );
  ViewsText_OnSetWrapText((ViewsText)&_this->NextTurnDescription, 1 );
  ViewsText_OnSetAlignment((ViewsText)&_this->NextTurnDescription, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString((ViewsText)&_this->NextTurnDescription, 0 );
  ViewsText_OnSetColor((ViewsText)&_this->NextTurnDescription, _Const0041 );
  ViewsText_OnSetVisible((ViewsText)&_this->NextTurnDescription, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnIcon, _Const0042 );
  ViewsImage_OnSetVisible( &_this->NextTurnIcon, 0 );
  CoreRectView__OnSetBounds( &_this->RecalculateMessage, _Const0043 );
  ViewsText_OnSetEllipsis((ViewsText)&_this->RecalculateMessage, 1 );
  ViewsText_OnSetWrapText((ViewsText)&_this->RecalculateMessage, 1 );
  ViewsText_OnSetString((ViewsText)&_this->RecalculateMessage, 0 );
  ViewsText_OnSetColor((ViewsText)&_this->RecalculateMessage, _Const0041 );
  ViewsText_OnSetVisible((ViewsText)&_this->RecalculateMessage, 0 );
  CoreRectView__OnSetBounds( &_this->Mask, _Const0002 );
  ViewsRectangle_OnSetColor( &_this->Mask, _Const0011 );
  ViewsRectangle_OnSetVisible( &_this->Mask, 0 );
  CoreRectView__OnSetBounds( &_this->BtLoadingAnimation, _Const0044 );
  ViewsImage_OnSetAnimated( &_this->BtLoadingAnimation, 0 );
  ViewsImage_OnSetVisible( &_this->BtLoadingAnimation, 0 );
  CoreRectView__OnSetBounds( &_this->BtLoadingIcon, _Const0045 );
  ViewsImage_OnSetAnimated( &_this->BtLoadingIcon, 0 );
  ViewsImage_OnSetVisible( &_this->BtLoadingIcon, 0 );
  CoreTimer_OnSetPeriod( &_this->SpeedLimitFlickeringTimer, 300 );
  CoreView_OnSetStackingPriority((CoreView)&_this->Super1.LoadingAnimation, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviTBTViewBg ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->ArrivalBg ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->ETAComponent ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->RoadNameBg ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->CurrentRoadComponent ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->SpeedLimitIcon ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->SpeedLimitText ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTurnDist ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTurnDistUnit ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTurnDescription ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTurnIcon ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->RecalculateMessage ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->Mask ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->BtLoadingAnimation ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->BtLoadingIcon ), -1 );
  ViewsWallpaper_OnSetBitmap( &_this->NaviTBTViewBg, EwLoadResource( &ResourceNaviTBTViewBg, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->SpeedLimitIcon, EwLoadResource( &ResourceSpeedLimitIcon, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->SpeedLimitText, EwLoadResource( &FontsNotoSansBold24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->NextTurnDist, EwLoadResource( &FontsNotoSansBold38pt, 
  ResourcesFont ));
  ViewsText_OnSetFont((ViewsText)&_this->NextTurnDistUnit, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont((ViewsText)&_this->NextTurnDescription, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->ETAUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV05_TBTView_OnETAUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->ETAUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->ETAUpdateEvent );
  _this->CurRdUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV05_TBTView_OnCurRdUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->CurRdUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurRdUpdateEvent );
  ViewsText_OnSetFont((ViewsText)&_this->RecalculateMessage, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->BtLoadingAnimation, EwLoadResource( &ResourceLoadingAnimation, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->BtLoadingIcon, EwLoadResource( &ResourceBtLoadingIcon, 
  ResourcesBitmap ));
  _this->TbtListUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV05_TBTView_OnTbtListUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->TbtListUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->TbtListUpdateEvent );
  _this->SpeedLimitUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV05_TBTView_OnSpeedLimitUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->SpeedLimitUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->SpeedLimitUpdateEvent );
  _this->SpeedLimitFlickeringTimer.OnTrigger = EwNewSlot( _this, NavigationNAV05_TBTView_OnSpeedLimitFlickeringSlot );
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV05_TBTView_OnVehicleSpeedUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );
  _this->RouteCalProgressUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV05_TBTView_OnRouteCalProgressUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->RouteCalProgressUpdateEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->RouteCalProgressUpdateEvent );
  _this->NavigatingStatusUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV05_TBTView_OnNavigatingStatusUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NavigatingStatusUpdateEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->NavigatingStatusUpdateEvent );
  _this->NaviDisconnectEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV05_TBTView_OnNaviDisconnectUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NaviDisconnectEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->DisconnectStatusUpdateEvent );
  _this->NaviBtThroughputUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV05_TBTView_OnNaviBtThroughputStatusUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NaviBtThroughputUpdateEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->BtThroughputStatusUpdateEvent );

  /* Call the user defined constructor */
  NavigationNAV05_TBTView_Init( _this, aArg );
}

/* Re-Initializer for the class 'Navigation::NAV05_TBTView' */
void NavigationNAV05_TBTView__ReInit( NavigationNAV05_TBTView _this )
{
  /* At first re-initialize the super class ... */
  HomeBaseHome__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsWallpaper__ReInit( &_this->NaviTBTViewBg );
  ViewsRectangle__ReInit( &_this->ArrivalBg );
  NavigationNaviETA__ReInit( &_this->ETAComponent );
  ViewsRectangle__ReInit( &_this->RoadNameBg );
  NavigationNaviCurrentRoad__ReInit( &_this->CurrentRoadComponent );
  ViewsImage__ReInit( &_this->SpeedLimitIcon );
  ViewsText__ReInit( &_this->SpeedLimitText );
  ViewsText__ReInit( &_this->NextTurnDist );
  ComponentsBaseText__ReInit( &_this->NextTurnDistUnit );
  ComponentsBaseText__ReInit( &_this->NextTurnDescription );
  ViewsImage__ReInit( &_this->NextTurnIcon );
  CoreSystemEventHandler__ReInit( &_this->ETAUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->CurRdUpdateEventHandler );
  ComponentsBaseText__ReInit( &_this->RecalculateMessage );
  ViewsRectangle__ReInit( &_this->Mask );
  ViewsImage__ReInit( &_this->BtLoadingAnimation );
  ViewsImage__ReInit( &_this->BtLoadingIcon );
  CoreSystemEventHandler__ReInit( &_this->TbtListUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->SpeedLimitUpdateEventHandler );
  CoreTimer__ReInit( &_this->SpeedLimitFlickeringTimer );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
  CoreSystemEventHandler__ReInit( &_this->RouteCalProgressUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->NavigatingStatusUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->NaviDisconnectEventHandler );
  CoreSystemEventHandler__ReInit( &_this->NaviBtThroughputUpdateEventHandler );
}

/* Finalizer method for the class 'Navigation::NAV05_TBTView' */
void NavigationNAV05_TBTView__Done( NavigationNAV05_TBTView _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  ViewsWallpaper__Done( &_this->NaviTBTViewBg );
  ViewsRectangle__Done( &_this->ArrivalBg );
  NavigationNaviETA__Done( &_this->ETAComponent );
  ViewsRectangle__Done( &_this->RoadNameBg );
  NavigationNaviCurrentRoad__Done( &_this->CurrentRoadComponent );
  ViewsImage__Done( &_this->SpeedLimitIcon );
  ViewsText__Done( &_this->SpeedLimitText );
  ViewsText__Done( &_this->NextTurnDist );
  ComponentsBaseText__Done( &_this->NextTurnDistUnit );
  ComponentsBaseText__Done( &_this->NextTurnDescription );
  ViewsImage__Done( &_this->NextTurnIcon );
  CoreSystemEventHandler__Done( &_this->ETAUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->CurRdUpdateEventHandler );
  ComponentsBaseText__Done( &_this->RecalculateMessage );
  ViewsRectangle__Done( &_this->Mask );
  ViewsImage__Done( &_this->BtLoadingAnimation );
  ViewsImage__Done( &_this->BtLoadingIcon );
  CoreSystemEventHandler__Done( &_this->TbtListUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->SpeedLimitUpdateEventHandler );
  CoreTimer__Done( &_this->SpeedLimitFlickeringTimer );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );
  CoreSystemEventHandler__Done( &_this->RouteCalProgressUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->NavigatingStatusUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->NaviDisconnectEventHandler );
  CoreSystemEventHandler__Done( &_this->NaviBtThroughputUpdateEventHandler );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void NavigationNAV05_TBTView_Init( NavigationNAV05_TBTView _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0046 ));
  EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnNavigatingStatusUpdateSlot ), 
    ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnSpeedLimitUpdateSlot ), 
    ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnNaviBtThroughputStatusUpdateSlot ), 
    ((XObject)_this ));

  if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
  {
    if ( EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->IsNaviLoadingDialogDisplayed )
    {
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->IsNaviLoadingDialogDisplayed 
      = 0;
      HomeBaseHome_OnSetAccessNaviView((HomeBaseHome)_this, 0 );
      EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnTbtListUpdateSlot ), 
        ((XObject)_this ));
    }
    else
    {
      if ( DeviceInterfaceNavigationDeviceClass_GetTbtListSize( EwGetAutoObject( 
          &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )) 
          > 0 )
      {
        HomeBaseHome_OnSetAccessNaviView((HomeBaseHome)_this, 0 );
        EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnTbtListUpdateSlot ), 
          ((XObject)_this ));
      }
      else
        HomeBaseHome_OnSetAccessNaviView((HomeBaseHome)_this, 1 );

      DeviceInterfaceNavigationDeviceClass_StartContentRequest( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));
    }
  }
}

/* 'C' function for method : 'Navigation::NAV05_TBTView.OnLongEnterKeyActivated()' */
void NavigationNAV05_TBTView_OnLongEnterKeyActivated( NavigationNAV05_TBTView _this )
{
  if ( !_this->Super1.NaviConnectFailedTimer.Enabled && ( 1 == _this->Super3.KeyHandler.RepetitionCount ))
  {
    if ( !DeviceInterfaceNavigationDeviceClass_OnGetNaviAppSppConnected( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( PopPOP09_POP14_BleConnectionErrorUI, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    else
      if ( !DeviceInterfaceNavigationDeviceClass_GetNaviConnectStatus( EwGetAutoObject( 
          &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( PopPOP17_AppInitSettingError, 
        0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      else
      {
        DeviceInterfaceNavigationDeviceClass_StopContentRequest( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( NavigationNAV06_NaviSettingMenu, 
        0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
  }
}

/* 'C' function for method : 'Navigation::NAV05_TBTView.ReturnToHome()' */
void NavigationNAV05_TBTView_ReturnToHome( NavigationNAV05_TBTView _this )
{
  HomeBaseHome_ReturnToHome((HomeBaseHome)_this );
  DeviceInterfaceNavigationDeviceClass_StartContentRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
  DeviceInterfaceNavigationDeviceClass ));
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV05_TBTView_OnETAUpdateSlot( NavigationNAV05_TBTView _this, XObject 
  sender )
{
  DeviceInterfaceNaviDataClass NaviData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), EnumNaviDataTypeETA );
  NavigationNaviETA_OnSetETA( &_this->ETAComponent, NaviData->ETA );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV05_TBTView_OnCurRdUpdateSlot( NavigationNAV05_TBTView _this, XObject 
  sender )
{
  DeviceInterfaceNaviDataClass NaviData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), EnumNaviDataTypeCURRENT_ROAD );
  NavigationNAV05_TBTView_SetItemBounds( _this );
  NavigationNaviCurrentRoad_OnSetRoadName( &_this->CurrentRoadComponent, NaviData->CurrentRoad );
  NavigationNaviCurrentRoad_SetItemBounds( &_this->CurrentRoadComponent, 0 );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV05_TBTView_OnTbtListUpdateSlot( NavigationNAV05_TBTView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Super1.NaviConnectFailedTimer.Enabled )
    HomeBaseHome_OnSetAccessNaviView((HomeBaseHome)_this, 0 );

  if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
    NavigationNAV05_TBTView_UpdateActiveTbtItem( _this );
}

/* 'C' function for method : 'Navigation::NAV05_TBTView.ShowNextTurnIcon()' */
void NavigationNAV05_TBTView_ShowNextTurnIcon( NavigationNAV05_TBTView _this, XInt32 
  index )
{
  XEnum NaviTurnStatus;

  if ( !ViewsImage_OnGetVisible( &_this->NextTurnIcon ))
    ViewsImage_OnSetVisible( &_this->NextTurnIcon, 1 );

  NaviTurnStatus = (XEnum)index;

  switch ( NaviTurnStatus )
  {
    case EnumNaviTurnStatusTypeARRVIAL_LEFT :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwArvngLIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeARRIVAL_RIGHT :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwArvngRIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeARRIVAL_VIA_LEFT :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwArvngViaLIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeARRIVAL_VIA_RIGHT :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwArvngViaRIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeCONTINUE :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwContinueIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeDRIVETO :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwDrivetoIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeDEST_FLAG :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwDstntnFlgIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeDEST_VIA_FLAG :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwViaFlgIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeEXIT_LEFT :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwExitLIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeEXIT_RIGHT :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwExitRIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeFERRY :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnarrwFerryIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeKEEP_LEFT :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwKeepLIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeKEEP_RIGHT :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwKeepRIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_45 :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundabout45IrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_90 :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundabout90IrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_135 :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundabout135IrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_180 :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundabout180IrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_225 :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundabout225IrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_270 :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundabout270IrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_315 :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundabout315IrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_360 :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundabout360IrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_EU_45 :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuro45IrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_EU_90 :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuro90IrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_EU_135 :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuro135IrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_EU_180 :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuro180IrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_EU_225 :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuro225IrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_EU_270 :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuro270IrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_EU_315 :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuro315IrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_EU_360 :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuro360IrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_EU_GEN :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuroGenericIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeROUNDABOUT_GEN :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwRoundaboutGenericIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeSHARP_TURN_LEFT :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwShrpturnLIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeSHARP_TURN_RIGHT :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwShrpturnRIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeTURN_LEFT :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwTurnLIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeTURN_RIGHT :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwTurnRIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeUTURN_LEFT :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwUturnLIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeUTURN_RIGHT :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwUturnRIrgTbt, 
      ResourcesBitmap ));
    break;

    case EnumNaviTurnStatusTypeEXIT_UNSPEC :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, 0 );
    break;

    default :; 
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV05_TBTView_OnSpeedLimitUpdateSlot( NavigationNAV05_TBTView _this, 
  XObject sender )
{
  DeviceInterfaceNaviDataClass NaviData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), EnumNaviDataTypeSPEED_LIMIT );

  if ( NaviData->SpeedLimit > 0 )
  {
    DeviceInterfaceVehicleDataClass VehicleData;
    ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 1 );
    ViewsText_OnSetString( &_this->SpeedLimitText, EwNewStringInt( NaviData->SpeedLimit, 
    0, 10 ));
    ViewsText_OnSetVisible( &_this->SpeedLimitText, 1 );
    VehicleData = DeviceInterfaceVehicleDeviceClass_GetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
    DeviceInterfaceVehicleDeviceClass ), EnumVehicleRxTypeVEHICLE_SPEED_REAL );

    if ((XInt32)VehicleData->DataUInt32 > NaviData->SpeedLimit )
      CoreTimer_OnSetEnabled( &_this->SpeedLimitFlickeringTimer, 1 );
    else
      CoreTimer_OnSetEnabled( &_this->SpeedLimitFlickeringTimer, 0 );
  }
  else
  {
    ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 0 );
    ViewsText_OnSetVisible( &_this->SpeedLimitText, 0 );
    CoreTimer_OnSetEnabled( &_this->SpeedLimitFlickeringTimer, 0 );
  }
}

/* 'C' function for method : 'Navigation::NAV05_TBTView.OnSpeedLimitFlickeringSlot()' */
void NavigationNAV05_TBTView_OnSpeedLimitFlickeringSlot( NavigationNAV05_TBTView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, (XBool)!ViewsImage_OnGetVisible( 
  &_this->SpeedLimitIcon ));
  ViewsText_OnSetVisible( &_this->SpeedLimitText, (XBool)!ViewsText_OnGetVisible( 
  &_this->SpeedLimitText ));
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV05_TBTView_OnVehicleSpeedUpdateSlot( NavigationNAV05_TBTView _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if (( VehicleData != 0 ) && ( EnumVehicleRxTypeVEHICLE_SPEED_REAL == VehicleData->RxType ))
    EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnSpeedLimitUpdateSlot ), 
      ((XObject)_this ));
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV05_TBTView_OnRouteCalProgressUpdateSlot( NavigationNAV05_TBTView _this, 
  XObject sender )
{
  DeviceInterfaceNaviDataClass NaviData;
  XInt32 RouteCalProgress;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), EnumNaviDataTypeNAVI_ROUTE_CAL_PROGRESS );
  RouteCalProgress = NaviData->RouteCalProgress;
  NavigationNAV05_TBTView_SetRecalculatingStatus( _this, RouteCalProgress );
}

/* 'C' function for method : 'Navigation::NAV05_TBTView.SetRecalculatingStatus()' */
void NavigationNAV05_TBTView_SetRecalculatingStatus( NavigationNAV05_TBTView _this, 
  XInt32 aNewRouteCalProgress )
{
  ViewsImage_OnSetVisible( &_this->NextTurnIcon, 0 );
  ViewsText_OnSetVisible((ViewsText)&_this->NextTurnDescription, 0 );
  ViewsText_OnSetVisible((ViewsText)&_this->NextTurnDistUnit, 0 );
  ViewsText_OnSetVisible( &_this->NextTurnDist, 0 );
  ViewsText_OnSetVisible( &_this->SpeedLimitText, 0 );
  ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 0 );
  NavigationNaviETA_OnSetETA( &_this->ETAComponent, 0 );
  ViewsText_OnSetString((ViewsText)&_this->RecalculateMessage, EwConcatString( EwConcatString( 
  EwLoadString( &_Const0047 ), EwNewStringInt( aNewRouteCalProgress, 0, 10 )), EwLoadString( 
  &_Const0048 )));
  ViewsText_OnSetVisible((ViewsText)&_this->RecalculateMessage, 1 );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV05_TBTView_OnNavigatingStatusUpdateSlot( NavigationNAV05_TBTView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( !DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
  {
    ViewsText_OnSetVisible( &_this->NextTurnDist, 0 );
    ViewsImage_OnSetVisible( &_this->NextTurnIcon, 0 );
    ViewsText_OnSetVisible((ViewsText)&_this->NextTurnDistUnit, 0 );
    ViewsText_OnSetVisible((ViewsText)&_this->NextTurnDescription, 0 );
  }
  else
  {
    ViewsText_OnSetVisible( &_this->NextTurnDist, 1 );
    ViewsImage_OnSetVisible( &_this->NextTurnIcon, 1 );
    ViewsText_OnSetVisible((ViewsText)&_this->NextTurnDistUnit, 1 );
    ViewsText_OnSetVisible((ViewsText)&_this->NextTurnDescription, 1 );
    ViewsText_OnSetVisible((ViewsText)&_this->RecalculateMessage, 0 );
  }

  EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnCurRdUpdateSlot ), ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnETAUpdateSlot ), ((XObject)_this ));
}

/* 'C' function for method : 'Navigation::NAV05_TBTView.SetItemBounds()' */
void NavigationNAV05_TBTView_SetItemBounds( NavigationNAV05_TBTView _this )
{
  if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
  {
    CoreRectView__OnSetBounds( &_this->RoadNameBg, NavigationROAD_BG_W_NAVI_BOUNDS );
    CoreRectView__OnSetBounds( &_this->CurrentRoadComponent, NavigationCURRENT_ROAD_W_NAVI_BOUNDS );
    _this->CurrentRoadComponent.RoadNameTextBounds = NavigationROADNAME_W_NAVI_BOUNDS;
    CoreGroup__OnSetVisible( &_this->ETAComponent, 1 );
    ViewsRectangle_OnSetVisible( &_this->ArrivalBg, 1 );
  }
  else
  {
    CoreRectView__OnSetBounds( &_this->RoadNameBg, NavigationROAD_BG_WO_NAVI_BOUNDS );
    CoreRectView__OnSetBounds( &_this->CurrentRoadComponent, NavigationCURRENT_ROAD_WO_NAVI_BOUNDS );
    _this->CurrentRoadComponent.RoadNameTextBounds = NavigationROADNAME_WO_NAVI_BOUNDS;
    CoreGroup__OnSetVisible( &_this->ETAComponent, 0 );
    ViewsRectangle_OnSetVisible( &_this->ArrivalBg, 0 );
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV05_TBTView_OnNaviDisconnectUpdateSlot( NavigationNAV05_TBTView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if (( _this->Super6.Owner != 0 ) && CoreGroup__IsCurrentDialog( _this ))
    CoreGroup_SwitchToDialog( _this->Super6.Owner, ((CoreGroup)EwNewObject( PopPOP02_ConnectionError, 
    0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Navigation::NAV05_TBTView.UpdateActiveTbtItem()' */
void NavigationNAV05_TBTView_UpdateActiveTbtItem( NavigationNAV05_TBTView _this )
{
  DeviceInterfaceNaviTbtDataClass NaviTbtData = DeviceInterfaceNavigationDeviceClass_GetNaviTbtData( 
    EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
    0 );

  if ( NaviTbtData != 0 )
  {
    NavigationNAV05_TBTView_ShowNextTurnIcon( _this, NaviTbtData->IconIdx );

    if ( !ViewsText_OnGetVisible( &_this->NextTurnDist ))
      ViewsText_OnSetVisible( &_this->NextTurnDist, 1 );

    if ( !ViewsText_OnGetVisible((ViewsText)&_this->NextTurnDistUnit ))
      ViewsText_OnSetVisible((ViewsText)&_this->NextTurnDistUnit, 1 );

    if ( !ViewsText_OnGetVisible((ViewsText)&_this->NextTurnDescription ))
      ViewsText_OnSetVisible((ViewsText)&_this->NextTurnDescription, 1 );

    ViewsText_OnSetString((ViewsText)&_this->NextTurnDistUnit, NaviTbtData->DistUnit );

    if ( 0.000000f == EwMathFract( NaviTbtData->Distance ))
      ViewsText_OnSetString( &_this->NextTurnDist, EwNewStringInt((XInt32)NaviTbtData->Distance, 
      0, 10 ));
    else
      ViewsText_OnSetString( &_this->NextTurnDist, EwNewStringFloat( NaviTbtData->Distance, 
      0, 1 ));

    ViewsText_OnSetString((ViewsText)&_this->NextTurnDescription, NaviTbtData->TbtDescription );
  }
}

/* 'C' function for method : 'Navigation::NAV05_TBTView.OnSetIsBtLoading()' */
void NavigationNAV05_TBTView_OnSetIsBtLoading( NavigationNAV05_TBTView _this, XBool 
  value )
{
  if ( _this->IsBtLoading != value )
  {
    _this->IsBtLoading = value;
    ViewsImage_OnSetVisible( &_this->BtLoadingAnimation, value );
    ViewsImage_OnSetAnimated( &_this->BtLoadingAnimation, value );
    ViewsRectangle_OnSetVisible( &_this->Mask, value );
  }
}

/* 'C' function for method : 'Navigation::NAV05_TBTView.OnSetIsBtLoadingIconDisplayed()' */
void NavigationNAV05_TBTView_OnSetIsBtLoadingIconDisplayed( NavigationNAV05_TBTView _this, 
  XBool value )
{
  if ( _this->IsBtLoadingIconDisplayed != value )
  {
    _this->IsBtLoadingIconDisplayed = value;
    ViewsImage_OnSetVisible( &_this->BtLoadingIcon, value );
    ViewsImage_OnSetAnimated( &_this->BtLoadingIcon, value );
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV05_TBTView_OnNaviBtThroughputStatusUpdateSlot( NavigationNAV05_TBTView _this, 
  XObject sender )
{
  XEnum BtThroughputUIMode;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  BtThroughputUIMode = DeviceInterfaceNavigationDeviceClass_GetBtThroughputUIMode( 
  EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));

  if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
    switch ( BtThroughputUIMode )
    {
      case EnumNaviBtThroughputUIModeBUSY :
      {
        NavigationNAV05_TBTView_OnSetIsBtLoading( _this, 1 );
        NavigationNAV05_TBTView_OnSetIsBtLoadingIconDisplayed( _this, 0 );
      }
      break;

      case EnumNaviBtThroughputUIModeTBT :
      {
        NavigationNAV05_TBTView_OnSetIsBtLoadingIconDisplayed( _this, 1 );
        NavigationNAV05_TBTView_OnSetIsBtLoading( _this, 0 );
      }
      break;

      case EnumNaviBtThroughputUIModeMAP :
      {
        NavigationNAV05_TBTView_OnSetIsBtLoading( _this, 0 );
        NavigationNAV05_TBTView_OnSetIsBtLoadingIconDisplayed( _this, 0 );

        if ( CoreGroup__IsCurrentDialog( _this ) && EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
            DeviceInterfaceNavigationDeviceClass )->IsBtThoughputModeActivateFromMap )
        {
          ApplicationApplication App;
          EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->IsBtThoughputModeActivateFromMap 
          = 0;
          App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

          if ( App != 0 )
          {
            EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
            = EnumHomeTypeNAVI_DEFAULT_VIEW;
            ApplicationApplication_SwitchToHome( App, EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
            DeviceInterfaceNavigationDeviceClass )->CurrentHome );
          }
        }
      }
      break;

      default :; 
    }
}

/* Variants derived from the class : 'Navigation::NAV05_TBTView' */
EW_DEFINE_CLASS_VARIANTS( NavigationNAV05_TBTView )
EW_END_OF_CLASS_VARIANTS( NavigationNAV05_TBTView )

/* Virtual Method Table (VMT) for the class : 'Navigation::NAV05_TBTView' */
EW_DEFINE_CLASS( NavigationNAV05_TBTView, HomeBaseHome, NaviTBTViewBg, NaviTBTViewBg, 
                 NaviTBTViewBg, NaviTBTViewBg, IsBtLoadingIconDisplayed, IsBtLoadingIconDisplayed, 
                 "Navigation::NAV05_TBTView" )
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
  NavigationNAV05_TBTView_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  NavigationNAV05_TBTView_ReturnToHome,
EW_END_OF_CLASS( NavigationNAV05_TBTView )

/* Initializer for the class 'Navigation::NAV03_TBTListView' */
void NavigationNAV03_TBTListView__Init( NavigationNAV03_TBTListView _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  HomeBaseHome__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationNAV03_TBTListView );

  /* ... then construct all embedded objects */
  NavigationTbtListMenu__Init( &_this->TbtList, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->TbtListUpdateEventHandler, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NavigatingStatusUpdateEventHandler, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NaviDisconnectEventHandler, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Divider, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationNAV03_TBTListView );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Super2.BlackBG, _Const0000 );
  _this->Super1.HomeType = EnumHomeTypeNAVI_TURN_BY_TURN;
  CoreRectView__OnSetBounds( &_this->TbtList, _Const0049 );
  NavigationTbtListMenu_OnSetArrowScrollBarVisible( &_this->TbtList, 1 );
  CoreRectView__OnSetBounds( &_this->Divider, _Const004A );
  ViewsImage_OnSetAlignment( &_this->Divider, ViewsImageAlignmentAlignVertBottom 
  | ViewsImageAlignmentScaleToFit );
  CoreView_OnSetStackingPriority((CoreView)&_this->Super1.LoadingAnimation, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->TbtList ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider ), -1 );
  _this->TbtListUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV03_TBTListView_OnTbtListUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->TbtListUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->TbtListUpdateEvent );
  _this->NavigatingStatusUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV03_TBTListView_OnNavigatingStatusUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NavigatingStatusUpdateEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->NavigatingStatusUpdateEvent );
  _this->NaviDisconnectEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV03_TBTListView_OnNaviDisconnectUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NaviDisconnectEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->DisconnectStatusUpdateEvent );
  ViewsImage_OnSetBitmap( &_this->Divider, EwLoadResource( &ResourceStatusBarDivider, 
  ResourcesBitmap ));

  /* Call the user defined constructor */
  NavigationNAV03_TBTListView_Init( _this, aArg );
}

/* Re-Initializer for the class 'Navigation::NAV03_TBTListView' */
void NavigationNAV03_TBTListView__ReInit( NavigationNAV03_TBTListView _this )
{
  /* At first re-initialize the super class ... */
  HomeBaseHome__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  NavigationTbtListMenu__ReInit( &_this->TbtList );
  CoreSystemEventHandler__ReInit( &_this->TbtListUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->NavigatingStatusUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->NaviDisconnectEventHandler );
  ViewsImage__ReInit( &_this->Divider );
}

/* Finalizer method for the class 'Navigation::NAV03_TBTListView' */
void NavigationNAV03_TBTListView__Done( NavigationNAV03_TBTListView _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  NavigationTbtListMenu__Done( &_this->TbtList );
  CoreSystemEventHandler__Done( &_this->TbtListUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->NavigatingStatusUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->NaviDisconnectEventHandler );
  ViewsImage__Done( &_this->Divider );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void NavigationNAV03_TBTListView_Init( NavigationNAV03_TBTListView _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const004B ));

  if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
  {
    if ( EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->IsNaviLoadingDialogDisplayed )
    {
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->IsNaviLoadingDialogDisplayed 
      = 0;
      HomeBaseHome_OnSetAccessNaviView((HomeBaseHome)_this, 0 );
      EwSignal( EwNewSlot( _this, NavigationNAV03_TBTListView_OnTbtListUpdateSlot ), 
        ((XObject)_this ));
    }
    else
      if ( DeviceInterfaceNavigationDeviceClass_GetTbtListSize( EwGetAutoObject( 
          &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )) 
          > 0 )
      {
        HomeBaseHome_OnSetAccessNaviView((HomeBaseHome)_this, 0 );
        EwSignal( EwNewSlot( _this, NavigationNAV03_TBTListView_OnTbtListUpdateSlot ), 
          ((XObject)_this ));
      }
      else
        HomeBaseHome_OnSetAccessNaviView((HomeBaseHome)_this, 1 );
  }
  else
    EwPostSignal( EwNewSlot( _this, NavigationNAV03_TBTListView_OnNoTbtListDataSlot ), 
      ((XObject)_this ));
}

/* 'C' function for method : 'Navigation::NAV03_TBTListView.OnShortDownKeyActivated()' */
void NavigationNAV03_TBTListView_OnShortDownKeyActivated( NavigationNAV03_TBTListView _this )
{
  NavigationTbtListMenu_ScrollDown( &_this->TbtList );
}

/* 'C' function for method : 'Navigation::NAV03_TBTListView.OnShortUpKeyActivated()' */
void NavigationNAV03_TBTListView_OnShortUpKeyActivated( NavigationNAV03_TBTListView _this )
{
  NavigationTbtListMenu_ScrollUp( &_this->TbtList );
}

/* 'C' function for method : 'Navigation::NAV03_TBTListView.OnLongEnterKeyActivated()' */
void NavigationNAV03_TBTListView_OnLongEnterKeyActivated( NavigationNAV03_TBTListView _this )
{
  if ( !_this->Super1.NaviConnectFailedTimer.Enabled && ( 1 == _this->Super3.KeyHandler.RepetitionCount ))
  {
    if ( !DeviceInterfaceNavigationDeviceClass_OnGetNaviAppSppConnected( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( PopPOP09_POP14_BleConnectionErrorUI, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    else
      if ( !DeviceInterfaceNavigationDeviceClass_GetNaviConnectStatus( EwGetAutoObject( 
          &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( PopPOP17_AppInitSettingError, 
        0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      else
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( NavigationNAV06_NaviSettingMenu, 
        0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* 'C' function for method : 'Navigation::NAV03_TBTListView.ReturnToHome()' */
void NavigationNAV03_TBTListView_ReturnToHome( NavigationNAV03_TBTListView _this )
{
  HomeBaseHome_ReturnToHome((HomeBaseHome)_this );

  if ( !DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
    EwSignal( EwNewSlot( _this, NavigationNAV03_TBTListView_OnNoTbtListDataSlot ), 
      ((XObject)_this ));
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV03_TBTListView_OnTbtListUpdateSlot( NavigationNAV03_TBTListView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Super1.NaviConnectFailedTimer.Enabled )
    HomeBaseHome_OnSetAccessNaviView((HomeBaseHome)_this, 0 );

  if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
  {
    if ( DeviceInterfaceNavigationDeviceClass_IsTbtMessageDisplayed( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
      NavigationTbtListMenu_OnSetNoOfItems( &_this->TbtList, DeviceInterfaceNavigationDeviceClass_GetTbtListSize( 
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )) 
      + 1 );
    else
      NavigationTbtListMenu_OnSetNoOfItems( &_this->TbtList, DeviceInterfaceNavigationDeviceClass_GetTbtListSize( 
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )));

    if ( _this->TbtList.NoOfItems == 0 )
      EwSignal( EwNewSlot( _this, NavigationNAV03_TBTListView_OnNoTbtListDataSlot ), 
        ((XObject)_this ));
    else
    {
      if ( CoreGroup_CountDialogs((CoreGroup)_this ) > 0 )
      {
        NavigationNaviTbtListDataEmptyDialog Dialog = EwCastObject( CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
          0 ), NavigationNaviTbtListDataEmptyDialog );

        if ( Dialog != 0 )
          CoreGroup_DismissDialog((CoreGroup)_this, ((CoreGroup)Dialog ), 0, 0, 
          0, EwNullSlot, EwNullSlot, 0 );
      }

      NavigationTbtListMenu_InvalidateItems( &_this->TbtList, 0, _this->TbtList.NoOfItems 
      - 1 );
    }
  }
  else
    EwSignal( EwNewSlot( _this, NavigationNAV03_TBTListView_OnNoTbtListDataSlot ), 
      ((XObject)_this ));
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV03_TBTListView_OnNavigatingStatusUpdateSlot( NavigationNAV03_TBTListView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( !DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
  {
    NavigationTbtListMenu_OnSetNoOfItems( &_this->TbtList, 0 );
    EwSignal( EwNewSlot( _this, NavigationNAV03_TBTListView_OnNoTbtListDataSlot ), 
      ((XObject)_this ));
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV03_TBTListView_OnNaviDisconnectUpdateSlot( NavigationNAV03_TBTListView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if (( _this->Super6.Owner != 0 ) && CoreGroup__IsCurrentDialog( _this ))
    CoreGroup_SwitchToDialog( _this->Super6.Owner, ((CoreGroup)EwNewObject( PopPOP02_ConnectionError, 
    0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Navigation::NAV03_TBTListView.OnNoTbtListDataSlot()' */
void NavigationNAV03_TBTListView_OnNoTbtListDataSlot( NavigationNAV03_TBTListView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( CoreGroup__IsCurrentDialog( _this ) || ( CoreGroup_CountDialogs((CoreGroup)_this ) 
      == 0 ))
  {
    NavigationNaviTbtListDataEmptyDialog NoTbtListData = EwNewObject( NavigationNaviTbtListDataEmptyDialog, 
      0 );
    NoTbtListData->ViewMapUpdateSlot = EwNewSlot( _this, NavigationNAV03_TBTListView_ReturnToMapSlot );
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)NoTbtListData ), 0, 0, 
    0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* 'C' function for method : 'Navigation::NAV03_TBTListView.ReturnToMapSlot()' */
void NavigationNAV03_TBTListView_ReturnToMapSlot( NavigationNAV03_TBTListView _this, 
  XObject sender )
{
  ApplicationApplication App;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
  {
    EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
    = EnumHomeTypeNAVI_DEFAULT_VIEW;
    ApplicationApplication_SwitchToHome( App, EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
    DeviceInterfaceNavigationDeviceClass )->CurrentHome );
  }
}

/* Variants derived from the class : 'Navigation::NAV03_TBTListView' */
EW_DEFINE_CLASS_VARIANTS( NavigationNAV03_TBTListView )
EW_END_OF_CLASS_VARIANTS( NavigationNAV03_TBTListView )

/* Virtual Method Table (VMT) for the class : 'Navigation::NAV03_TBTListView' */
EW_DEFINE_CLASS( NavigationNAV03_TBTListView, HomeBaseHome, TbtList, TbtList, TbtList, 
                 TbtList, _.VMT, _.VMT, "Navigation::NAV03_TBTListView" )
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
  NavigationNAV03_TBTListView_OnShortDownKeyActivated,
  NavigationNAV03_TBTListView_OnShortUpKeyActivated,
  HomeBaseHome_OnShortEnterKeyActivated,
  HomeBaseHome_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  NavigationNAV03_TBTListView_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  NavigationNAV03_TBTListView_ReturnToHome,
EW_END_OF_CLASS( NavigationNAV03_TBTListView )

/* Initializer for the class 'Navigation::TbtInfoItem' */
void NavigationTbtInfoItem__Init( NavigationTbtInfoItem _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationTbtInfoItem );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->TbtItemBg, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->NextTurnIcon, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->NextTurnDist, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->NextTurnDistUnit, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->NextTurnDescription, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ListDivider, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->LoadingText, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationTbtInfoItem );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const004C );
  CoreRectView__OnSetBounds( &_this->TbtItemBg, _Const004D );
  ViewsRectangle_OnSetColor( &_this->TbtItemBg, _Const004E );
  ViewsRectangle_OnSetVisible( &_this->TbtItemBg, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnIcon, _Const004F );
  ViewsImage_OnSetAlignment( &_this->NextTurnIcon, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter | ViewsImageAlignmentScaleToFit );
  CoreRectView__OnSetBounds( &_this->NextTurnDist, _Const0050 );
  ViewsText_OnSetAlignment( &_this->NextTurnDist, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->NextTurnDist, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnDistUnit, _Const0051 );
  ViewsText_OnSetAlignment((ViewsText)&_this->NextTurnDistUnit, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString((ViewsText)&_this->NextTurnDistUnit, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnDescription, _Const0052 );
  ViewsText_OnSetEllipsis((ViewsText)&_this->NextTurnDescription, 1 );
  ViewsText_OnSetWrapText((ViewsText)&_this->NextTurnDescription, 1 );
  ViewsText_OnSetAlignment((ViewsText)&_this->NextTurnDescription, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString((ViewsText)&_this->NextTurnDescription, 0 );
  ViewsText_OnSetColor((ViewsText)&_this->NextTurnDescription, _Const0053 );
  CoreRectView__OnSetBounds( &_this->ListDivider, _Const0054 );
  ViewsImage_OnSetAlignment( &_this->ListDivider, ViewsImageAlignmentScaleToFit );
  CoreRectView__OnSetBounds( &_this->LoadingText, _Const004C );
  ViewsText_OnSetString((ViewsText)&_this->LoadingText, EwLoadString( &_Const0055 ));
  ViewsText_OnSetColor((ViewsText)&_this->LoadingText, _Const0053 );
  ViewsText_OnSetVisible((ViewsText)&_this->LoadingText, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TbtItemBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTurnIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTurnDist ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTurnDistUnit ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTurnDescription ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ListDivider ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LoadingText ), 0 );
  ViewsText_OnSetFont( &_this->NextTurnDist, EwLoadResource( &FontsNotoSansBold20pt, 
  ResourcesFont ));
  ViewsText_OnSetFont((ViewsText)&_this->NextTurnDistUnit, EwLoadResource( &FontsNotoSansBold20pt, 
  ResourcesFont ));
  ViewsText_OnSetFont((ViewsText)&_this->NextTurnDescription, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->ListDivider, EwLoadResource( &ResourceListDivider3, 
  ResourcesBitmap ));
  ViewsText_OnSetFont((ViewsText)&_this->LoadingText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Navigation::TbtInfoItem' */
void NavigationTbtInfoItem__ReInit( NavigationTbtInfoItem _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->TbtItemBg );
  ViewsImage__ReInit( &_this->NextTurnIcon );
  ViewsText__ReInit( &_this->NextTurnDist );
  ComponentsBaseText__ReInit( &_this->NextTurnDistUnit );
  ComponentsBaseText__ReInit( &_this->NextTurnDescription );
  ViewsImage__ReInit( &_this->ListDivider );
  ComponentsBaseText__ReInit( &_this->LoadingText );
}

/* Finalizer method for the class 'Navigation::TbtInfoItem' */
void NavigationTbtInfoItem__Done( NavigationTbtInfoItem _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->TbtItemBg );
  ViewsImage__Done( &_this->NextTurnIcon );
  ViewsText__Done( &_this->NextTurnDist );
  ComponentsBaseText__Done( &_this->NextTurnDistUnit );
  ComponentsBaseText__Done( &_this->NextTurnDescription );
  ViewsImage__Done( &_this->ListDivider );
  ComponentsBaseText__Done( &_this->LoadingText );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Navigation::TbtInfoItem.OnSetDistance()' */
void NavigationTbtInfoItem_OnSetDistance( NavigationTbtInfoItem _this, XString value )
{
  _this->Distance = EwShareString( value );
  ViewsText_OnSetString( &_this->NextTurnDist, value );

  if ( EwGetRectW( ViewsText_GetContentArea( &_this->NextTurnDist )) > EwGetRectW( 
      _this->NextTurnDist.Super1.Bounds ))
  {
    if ( EwGetRectW( ViewsText_GetContentArea( &_this->NextTurnDist )) > 47 )
      CoreRectView__OnSetBounds( &_this->NextTurnDist, EwSetRectW( _this->NextTurnDist.Super1.Bounds, 
      47 ));
    else
      CoreRectView__OnSetBounds( &_this->NextTurnDist, EwSetRectW( _this->NextTurnDist.Super1.Bounds, 
      EwGetRectW( ViewsText_GetContentArea( &_this->NextTurnDist ))));
  }
}

/* 'C' function for method : 'Navigation::TbtInfoItem.OnSetDistanceUnit()' */
void NavigationTbtInfoItem_OnSetDistanceUnit( NavigationTbtInfoItem _this, XString 
  value )
{
  _this->DistanceUnit = EwShareString( value );
  ViewsText_OnSetString((ViewsText)&_this->NextTurnDistUnit, value );

  if ( EwGetRectW( ViewsText_GetContentArea((ViewsText)&_this->NextTurnDistUnit )) 
      > EwGetRectW( _this->NextTurnDistUnit.Super2.Bounds ))
  {
    if ( EwGetRectW( ViewsText_GetContentArea((ViewsText)&_this->NextTurnDistUnit )) 
        > 32 )
      CoreRectView__OnSetBounds( &_this->NextTurnDistUnit, EwSetRectW( _this->NextTurnDistUnit.Super2.Bounds, 
      32 ));
    else
      CoreRectView__OnSetBounds( &_this->NextTurnDistUnit, EwSetRectW( _this->NextTurnDistUnit.Super2.Bounds, 
      EwGetRectW( ViewsText_GetContentArea((ViewsText)&_this->NextTurnDistUnit ))));
  }
}

/* 'C' function for method : 'Navigation::TbtInfoItem.OnSetTurnIconBitmap()' */
void NavigationTbtInfoItem_OnSetTurnIconBitmap( NavigationTbtInfoItem _this, ResourcesBitmap 
  value )
{
  _this->TurnIconBitmap = value;
  ViewsImage_OnSetBitmap( &_this->NextTurnIcon, _this->TurnIconBitmap );

  if ( !EwCompString( 0, _this->Distance ) && !EwCompString( 0, _this->DistanceUnit ))
    CoreRectView__OnSetBounds( &_this->NextTurnIcon, NavigationTURN_ICON_BOUNDS_WO_DIST );
  else
    CoreRectView__OnSetBounds( &_this->NextTurnIcon, NavigationTURN_ICON_BOUNDS_W_DIST );
}

/* 'C' function for method : 'Navigation::TbtInfoItem.OnSetTbtItemEnabled()' */
void NavigationTbtInfoItem_OnSetTbtItemEnabled( NavigationTbtInfoItem _this, XBool 
  value )
{
  _this->TbtItemEnabled = value;
  ViewsRectangle_OnSetVisible( &_this->TbtItemBg, value );
  ViewsText_OnSetVisible((ViewsText)&_this->NextTurnDescription, value );
  ViewsText_OnSetVisible( &_this->NextTurnDist, value );
  ViewsImage_OnSetVisible( &_this->NextTurnIcon, value );
  ViewsText_OnSetVisible((ViewsText)&_this->NextTurnDistUnit, value );
  ViewsImage_OnSetVisible( &_this->ListDivider, value );
  ViewsText_OnSetVisible((ViewsText)&_this->LoadingText, (XBool)!value );
}

/* Variants derived from the class : 'Navigation::TbtInfoItem' */
EW_DEFINE_CLASS_VARIANTS( NavigationTbtInfoItem )
EW_END_OF_CLASS_VARIANTS( NavigationTbtInfoItem )

/* Virtual Method Table (VMT) for the class : 'Navigation::TbtInfoItem' */
EW_DEFINE_CLASS( NavigationTbtInfoItem, CoreGroup, TurnIconBitmap, TbtItemBg, TbtItemBg, 
                 TbtItemBg, Distance, TbtItemEnabled, "Navigation::TbtInfoItem" )
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
EW_END_OF_CLASS( NavigationTbtInfoItem )

/* Initializer for the class 'Navigation::NaviDialog' */
void NavigationNaviDialog__Init( NavigationNaviDialog _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationNaviDialog );

  /* ... then construct all embedded objects */
  ViewsFrame__Init( &_this->DialogBackground, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->DialogContent, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->CountDownTimer, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NaviDialogEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationNaviDialog );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0056 );
  CoreRectView__OnSetBounds( &_this->DialogBackground, _Const0056 );
  CoreRectView__OnSetBounds( &_this->DialogContent, _Const0057 );
  ViewsText_OnSetWrapText((ViewsText)&_this->DialogContent, 1 );
  ViewsText_OnSetString((ViewsText)&_this->DialogContent, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DialogBackground ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DialogContent ), 0 );
  ViewsFrame_OnSetBitmap( &_this->DialogBackground, EwLoadResource( &ResourceDialogBackground, 
  ResourcesBitmap ));
  ViewsText_OnSetFont((ViewsText)&_this->DialogContent, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->CountDownTimer.OnTrigger = EwNewSlot( _this, NavigationNaviDialog_UpdateCountDownTimeSlot );
  _this->NaviDialogEventHandler.OnEvent = EwNewSlot( _this, NavigationNaviDialog_OnNaviDialogEventUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NaviDialogEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->DialogEventUpdateEvent );
}

/* Re-Initializer for the class 'Navigation::NaviDialog' */
void NavigationNaviDialog__ReInit( NavigationNaviDialog _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsFrame__ReInit( &_this->DialogBackground );
  ComponentsBaseText__ReInit( &_this->DialogContent );
  CoreTimer__ReInit( &_this->CountDownTimer );
  CoreSystemEventHandler__ReInit( &_this->NaviDialogEventHandler );
}

/* Finalizer method for the class 'Navigation::NaviDialog' */
void NavigationNaviDialog__Done( NavigationNaviDialog _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsFrame__Done( &_this->DialogBackground );
  ComponentsBaseText__Done( &_this->DialogContent );
  CoreTimer__Done( &_this->CountDownTimer );
  CoreSystemEventHandler__Done( &_this->NaviDialogEventHandler );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Navigation::NaviDialog.OnSetDialogButton()' */
void NavigationNaviDialog_OnSetDialogButton( NavigationNaviDialog _this, XClass 
  value )
{
  if ( _this->DialogButton != value )
  {
    _this->DialogButton = value;

    switch ( _this->DialogType )
    {
      case EnumNaviDialogTypeDIALOG_YES_NO :
      {
        XEnum ButtonType;
        _this->ButtonSet = EwCastObject( EwNewObjectIndirect( value, 0 ), MenuUpDownPushButtonSet );
        _this->ButtonSet->OnUpButtonActivated = EwNewSlot( _this, NavigationNaviDialog_OnOkActivatedSlot );
        _this->ButtonSet->OnDownButtonActivated = EwNewSlot( _this, NavigationNaviDialog_OnNoActivatedSlot );
        ButtonType = DeviceInterfaceNavigationDeviceClass_GetNaviDialogDefaultButton( 
        EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));

        if ( EnumNaviButtonTypeYES == ButtonType )
          CoreGroup__OnSetFocus( _this->ButtonSet, ((CoreView)&_this->ButtonSet->UpButton ));
        else
          if ( EnumNaviButtonTypeNO == ButtonType )
            CoreGroup__OnSetFocus( _this->ButtonSet, ((CoreView)&_this->ButtonSet->DownButton ));

        _this->CountDownTime = DeviceInterfaceNavigationDeviceClass_GetNaviDialogTimeOut( 
        EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));
        MenuUpDownPushButtonSet_OnSetUpButtonTitle( _this->ButtonSet, EwGetVariantOfString( 
        &StringsGEN_YES ));
        MenuUpDownPushButtonSet_OnSetDownButtonTitle( _this->ButtonSet, EwConcatString( 
        EwConcatString( EwConcatString( EwGetVariantOfString( &StringsGEN_NO ), 
        EwLoadString( &_Const0058 )), EwNewStringInt( _this->CountDownTime, 0, 10 )), 
        EwLoadString( &_Const0059 )));
        CoreRectView__OnSetBounds( _this->ButtonSet, _Const005A );
        CoreGroup__Add( _this, ((CoreView)_this->ButtonSet ), 0 );
        CoreRectView__OnSetBounds( &_this->DialogContent, _Const005B );
      }
      break;

      case EnumNaviDialogTypeDIALOG_OK :
      {
        MenuPushButton Button = EwCastObject( EwNewObjectIndirect( value, 0 ), MenuPushButton );
        Button->OnActivate = EwNewSlot( _this, NavigationNaviDialog_OnOkActivatedSlot );
        CoreRectView__OnSetBounds( Button, _Const005C );
        MenuPushButton_OnSetTitle( Button, EwGetVariantOfString( &StringsGEN_OK ));
        CoreGroup__Add( _this, ((CoreView)Button ), 0 );
        CoreRectView__OnSetBounds( &_this->DialogContent, _Const0057 );
      }
      break;

      default :; 
    }
  }
}

/* 'C' function for method : 'Navigation::NaviDialog.OnSetDialogMessage()' */
void NavigationNaviDialog_OnSetDialogMessage( NavigationNaviDialog _this, XString 
  value )
{
  if ( EwCompString( _this->DialogMessage, value ) != 0 )
  {
    _this->DialogMessage = EwShareString( value );
    ViewsText_OnSetString((ViewsText)&_this->DialogContent, _this->DialogMessage );
  }
}

/* 'C' function for method : 'Navigation::NaviDialog.OnSetDialogType()' */
void NavigationNaviDialog_OnSetDialogType( NavigationNaviDialog _this, XEnum value )
{
  if ( _this->DialogType != value )
    _this->DialogType = value;
}

/* 'C' function for method : 'Navigation::NaviDialog.OnOkActivatedSlot()' */
void NavigationNaviDialog_OnOkActivatedSlot( NavigationNaviDialog _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->DialogType == EnumNaviDialogTypeDIALOG_OK )
    DeviceInterfaceNavigationDeviceClass_SendSelectedDialog( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
    DeviceInterfaceNavigationDeviceClass ), EnumNaviButtonTypeOK );
  else
    if ( _this->DialogType == EnumNaviDialogTypeDIALOG_YES_NO )
      DeviceInterfaceNavigationDeviceClass_SendSelectedDialog( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
      EnumNaviButtonTypeYES );

  CoreGroup_DismissDialog( _this->Super3.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
  EwSignal( _this->OnDialogDismiss, ((XObject)_this ));
}

/* 'C' function for method : 'Navigation::NaviDialog.UpdateCountDownTimeSlot()' */
void NavigationNaviDialog_UpdateCountDownTimeSlot( NavigationNaviDialog _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if (( _this->ButtonSet != 0 ) && ( _this->CountDownTime > 0 ))
  {
    _this->CountDownTime--;
    MenuUpDownPushButtonSet_OnSetDownButtonTitle( _this->ButtonSet, EwConcatString( 
    EwConcatString( EwConcatString( EwGetVariantOfString( &StringsGEN_NO ), EwLoadString( 
    &_Const0058 )), EwNewStringInt( _this->CountDownTime, 0, 10 )), EwLoadString( 
    &_Const0059 )));
    CoreGroup_InvalidateViewState((CoreGroup)_this );
  }
  else
  {
    CoreTimer_OnSetEnabled( &_this->CountDownTimer, 0 );
    EwSignal( EwNewSlot( _this, NavigationNaviDialog_OnNoActivatedSlot ), ((XObject)_this ));
  }
}

/* 'C' function for method : 'Navigation::NaviDialog.OnNoActivatedSlot()' */
void NavigationNaviDialog_OnNoActivatedSlot( NavigationNaviDialog _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  DeviceInterfaceNavigationDeviceClass_SendSelectedDialog( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
  DeviceInterfaceNavigationDeviceClass ), EnumNaviButtonTypeNO );
  CoreGroup_DismissDialog( _this->Super3.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
  EwSignal( _this->OnDialogDismiss, ((XObject)_this ));
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNaviDialog_OnNaviDialogEventUpdateSlot( NavigationNaviDialog _this, 
  XObject sender )
{
  XEnum NaviDialogType;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  NaviDialogType = DeviceInterfaceNavigationDeviceClass_GetNaviDialogType( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));

  if ( EnumNaviDialogTypeDIALOG_DISMISS == NaviDialogType )
  {
    CoreGroup_DismissDialog( _this->Super3.Owner, ((CoreGroup)_this ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 0 );
    EwSignal( _this->OnDialogDismiss, ((XObject)_this ));
  }
}

/* Variants derived from the class : 'Navigation::NaviDialog' */
EW_DEFINE_CLASS_VARIANTS( NavigationNaviDialog )
EW_END_OF_CLASS_VARIANTS( NavigationNaviDialog )

/* Virtual Method Table (VMT) for the class : 'Navigation::NaviDialog' */
EW_DEFINE_CLASS( NavigationNaviDialog, CoreGroup, ButtonSet, OnDialogDismiss, DialogBackground, 
                 DialogBackground, DialogMessage, DialogButton, "Navigation::NaviDialog" )
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
EW_END_OF_CLASS( NavigationNaviDialog )

/* User defined constant: 'Navigation::TIMETEXT_W_NAVI_BOUNDS' */
const XRect NavigationTIMETEXT_W_NAVI_BOUNDS = {{ 22, 2 }, { 84, 33 }};

/* User defined constant: 'Navigation::NAVIFLAG_W_NAVI_BOUNDS' */
const XRect NavigationNAVIFLAG_W_NAVI_BOUNDS = {{ 0, 6 }, { 20, 28 }};

/* User defined constant: 'Navigation::ZOOMIN_W_NAVI_BOUNDS' */
const XRect NavigationZOOMIN_W_NAVI_BOUNDS = {{ 130, 122 }, { 170, 162 }};

/* User defined constant: 'Navigation::ZOOMOUT_W_NAVI_BOUNDS' */
const XRect NavigationZOOMOUT_W_NAVI_BOUNDS = {{ 130, 170 }, { 170, 210 }};

/* User defined constant: 'Navigation::ZOOMIN_WO_NAVI_BOUNDS' */
const XRect NavigationZOOMIN_WO_NAVI_BOUNDS = {{ 9, 122 }, { 49, 162 }};

/* User defined constant: 'Navigation::ZOOMOUT_WO_NAVI_BOUNDS' */
const XRect NavigationZOOMOUT_WO_NAVI_BOUNDS = {{ 9, 170 }, { 49, 210 }};

/* User defined constant: 'Navigation::CURRENT_ROAD_W_NAVI_BOUNDS' */
const XRect NavigationCURRENT_ROAD_W_NAVI_BOUNDS = {{ 140, 228 }, { 470, 259 }};

/* User defined constant: 'Navigation::CURRENT_ROAD_WO_NAVI_BOUNDS' */
const XRect NavigationCURRENT_ROAD_WO_NAVI_BOUNDS = {{ 10, 228 }, { 470, 259 }};

/* User defined constant: 'Navigation::ROAD_BG_W_NAVI_BOUNDS' */
const XRect NavigationROAD_BG_W_NAVI_BOUNDS = {{ 130, 226 }, { 480, 272 }};

/* User defined constant: 'Navigation::ROAD_BG_WO_NAVI_BOUNDS' */
const XRect NavigationROAD_BG_WO_NAVI_BOUNDS = {{ 0, 226 }, { 480, 272 }};

/* User defined constant: 'Navigation::ROADNAME_W_NAVI_BOUNDS' */
const XRect NavigationROADNAME_W_NAVI_BOUNDS = {{ 24, 0 }, { 330, 31 }};

/* User defined constant: 'Navigation::ROADNAME_WO_NAVI_BOUNDS' */
const XRect NavigationROADNAME_WO_NAVI_BOUNDS = {{ 24, 0 }, { 460, 31 }};

/* User defined constant: 'Navigation::CURRENT_ROAD_SHRINK_ALERT' */
const XRect NavigationCURRENT_ROAD_SHRINK_ALERT = {{ 134, 228 }, { 310, 259 }};

/* User defined constant: 'Navigation::ALERT_MESSAGE_BOUNDS' */
const XRect NavigationALERT_MESSAGE_BOUNDS = {{ 0, 0 }, { 405, 46 }};

/* Initializer for the class 'Navigation::TbtListMenu' */
void NavigationTbtListMenu__Init( NavigationTbtListMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationTbtListMenu );

  /* ... then construct all embedded objects */
  CoreVerticalList__Init( &_this->VerticalList, &_this->_.XObject, 0 );
  MenuArrowScrollBar__Init( &_this->ArrowScrollBar, &_this->_.XObject, 0 );
  EffectsInt32Effect__Init( &_this->PageScrollEffect, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationTbtListMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const005D );
  CoreRectView__OnSetBounds( &_this->VerticalList, _Const005E );
  CoreVerticalList_OnSetSelectedItem( &_this->VerticalList, 0 );
  CoreVerticalList_OnSetItemHeight( &_this->VerticalList, 111 );
  CoreVerticalList_OnSetItemClass( &_this->VerticalList, EW_CLASS( NavigationTbtInfoItem ));
  CoreRectView__OnSetBounds( &_this->ArrowScrollBar, _Const005F );
  CoreGroup__OnSetVisible( &_this->ArrowScrollBar, 0 );
  EffectsEffect_OnSetExponent((EffectsEffect)&_this->PageScrollEffect, 4.190000f );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->PageScrollEffect, EffectsTimingExp_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->PageScrollEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->PageScrollEffect, 200 );
  EffectsEffect_OnSetInitialDelay((EffectsEffect)&_this->PageScrollEffect, 50 );
  CoreGroup__Add( _this, ((CoreView)&_this->VerticalList ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ArrowScrollBar ), 0 );
  _this->VerticalList.OnLoadItem = EwNewSlot( _this, NavigationTbtListMenu_OnLoadItem );
  _this->PageScrollEffect.Super1.OnFinished = EwNewSlot( _this, NavigationTbtListMenu_OnPageScrolledSlot );
  _this->PageScrollEffect.Outlet = EwNewRef( &_this->VerticalList, CoreVerticalList_OnGetScrollOffset, 
  CoreVerticalList_OnSetScrollOffset );
}

/* Re-Initializer for the class 'Navigation::TbtListMenu' */
void NavigationTbtListMenu__ReInit( NavigationTbtListMenu _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreVerticalList__ReInit( &_this->VerticalList );
  MenuArrowScrollBar__ReInit( &_this->ArrowScrollBar );
  EffectsInt32Effect__ReInit( &_this->PageScrollEffect );
}

/* Finalizer method for the class 'Navigation::TbtListMenu' */
void NavigationTbtListMenu__Done( NavigationTbtListMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  CoreVerticalList__Done( &_this->VerticalList );
  MenuArrowScrollBar__Done( &_this->ArrowScrollBar );
  EffectsInt32Effect__Done( &_this->PageScrollEffect );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
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
void NavigationTbtListMenu_UpdateViewState( NavigationTbtListMenu _this, XSet aState )
{
  CoreGroup_UpdateViewState((CoreGroup)_this, aState );

  if ( _this->ArrowScrollBarVisible )
  {
    XInt32 NoOfPages = _this->NoOfItems / 2;

    if ( _this->NoOfItems > ( NoOfPages * 2 ))
      NoOfPages++;

    MenuArrowScrollBar_OnSetNoOfPages( &_this->ArrowScrollBar, NoOfPages );
  }
}

/* This method is called by 'VerticalList' every time the list loads or updates 
   an item. */
void NavigationTbtListMenu_OnLoadItem( NavigationTbtListMenu _this, XObject sender )
{
  NavigationTbtInfoItem item;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  item = EwCastObject( _this->VerticalList.View, NavigationTbtInfoItem );

  if ( item != 0 )
  {
    if ( DeviceInterfaceNavigationDeviceClass_IsTbtMessageDisplayed( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )) 
        && ( _this->VerticalList.Item == ( _this->NoOfItems - 1 )))
      NavigationTbtInfoItem_OnSetTbtItemEnabled( item, 0 );
    else
    {
      DeviceInterfaceNaviTbtDataClass NaviTbtData = DeviceInterfaceNavigationDeviceClass_GetNaviTbtData( 
        EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
        _this->VerticalList.Item );

      if ( NaviTbtData != 0 )
      {
        NavigationTbtInfoItem_OnSetTbtItemEnabled( item, 1 );
        NavigationTbtListMenu_ShowTbtListItemIcon( _this, NaviTbtData->IconIdx );
        NavigationTbtInfoItem_OnSetDistanceUnit( item, NaviTbtData->DistUnit );

        if ( 0.000000f == EwMathFract( NaviTbtData->Distance ))
          NavigationTbtInfoItem_OnSetDistance( item, EwNewStringInt((XInt32)NaviTbtData->Distance, 
          0, 10 ));
        else
          NavigationTbtInfoItem_OnSetDistance( item, EwNewStringFloat( NaviTbtData->Distance, 
          0, 1 ));

        ViewsText_OnSetString((ViewsText)&item->NextTurnDescription, NaviTbtData->TbtDescription );
        ViewsRectangle_OnSetVisible( &item->TbtItemBg, 0 );

        if ( 0 == _this->VerticalList.Item )
          ViewsRectangle_OnSetVisible( &item->TbtItemBg, 1 );
      }
    }

    CoreRectView__OnSetBounds( item, EwSetRectSize( item->Super2.Bounds, EwNewPoint( 
    EwGetRectW( _this->VerticalList.Super2.Bounds ), _this->VerticalList.ItemHeight )));
  }
}

/* 'C' function for method : 'Navigation::TbtListMenu.ScrollUp()' */
void NavigationTbtListMenu_ScrollUp( NavigationTbtListMenu _this )
{
  XInt32 PrevItemIdx = _this->VerticalList.SelectedItem - 2;

  if ( PrevItemIdx >= 0 )
  {
    CoreVerticalList_OnSetSelectedItem( &_this->VerticalList, PrevItemIdx );
    NavigationTbtListMenu_SwitchToPageOfSelectedItem( _this );
  }
}

/* 'C' function for method : 'Navigation::TbtListMenu.ScrollDown()' */
void NavigationTbtListMenu_ScrollDown( NavigationTbtListMenu _this )
{
  XInt32 NextItemIdx = _this->VerticalList.SelectedItem + 2;

  if ( NextItemIdx < _this->VerticalList.NoOfItems )
  {
    CoreVerticalList_OnSetSelectedItem( &_this->VerticalList, NextItemIdx );
    NavigationTbtListMenu_SwitchToPageOfSelectedItem( _this );
  }
}

/* 'C' function for method : 'Navigation::TbtListMenu.ShowTbtListItemIcon()' */
void NavigationTbtListMenu_ShowTbtListItemIcon( NavigationTbtListMenu _this, XInt32 
  index )
{
  NavigationTbtInfoItem item = EwCastObject( _this->VerticalList.View, NavigationTbtInfoItem );

  if ( item != 0 )
  {
    XEnum NaviTurnStatus = (XEnum)index;

    switch ( NaviTurnStatus )
    {
      case EnumNaviTurnStatusTypeARRVIAL_LEFT :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwArvngLIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeARRIVAL_RIGHT :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwArvngRIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeARRIVAL_VIA_LEFT :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwArvngViaLIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeARRIVAL_VIA_RIGHT :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwArvngViaRIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeCONTINUE :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwContinuelrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeDRIVETO :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwDriveTolrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeDEST_FLAG :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwDstntnFlgIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeDEST_VIA_FLAG :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwViaflgIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeEXIT_LEFT :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwExitLIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeEXIT_RIGHT :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwExitRIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeFERRY :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwFerryIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeKEEP_LEFT :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwKeepLIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeKEEP_RIGHT :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwKeepRIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_45 :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundabout45IrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_90 :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundabout90IrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_135 :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundabout135IrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_180 :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundabout180IrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_225 :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundabout225IrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_270 :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundabout270IrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_315 :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundabout315IrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_360 :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundabout360IrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_EU_45 :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuro45IrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_EU_90 :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuro90IrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_EU_135 :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuro135IrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_EU_180 :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuro180IrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_EU_225 :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuro225IrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_EU_270 :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuro270IrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_EU_315 :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuro315IrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_EU_360 :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuro360IrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_EU_GEN :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundaboutEuroGenericIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeROUNDABOUT_GEN :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwRoundaboutGenericIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeSHARP_TURN_LEFT :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwShrpturnLIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeSHARP_TURN_RIGHT :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwShrpturnRIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeTURN_LEFT :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwTurnLIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeTURN_RIGHT :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwTurnRIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeUTURN_LEFT :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwUturnLIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeUTURN_RIGHT :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, EwLoadResource( &ResourceNaviTurnArrwUturnRIrgTbtList, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeEXIT_UNSPEC :
        NavigationTbtInfoItem_OnSetTurnIconBitmap( item, 0 );
      break;

      default :; 
    }
  }
}

/* 'C' function for method : 'Navigation::TbtListMenu.InvalidateItems()' */
void NavigationTbtListMenu_InvalidateItems( NavigationTbtListMenu _this, XInt32 
  aStart, XInt32 aEnd )
{
  CoreVerticalList_InvalidateItems( &_this->VerticalList, aStart, aEnd );
}

/* 'C' function for method : 'Navigation::TbtListMenu.OnSetNoOfItems()' */
void NavigationTbtListMenu_OnSetNoOfItems( NavigationTbtListMenu _this, XInt32 value )
{
  if ( _this->NoOfItems != value )
  {
    _this->NoOfItems = value;
    CoreVerticalList_OnSetNoOfItems( &_this->VerticalList, value );

    if (( 0 < _this->VerticalList.NoOfItems ) && ( _this->VerticalList.SelectedItem 
        >= _this->VerticalList.NoOfItems ))
    {
      CoreVerticalList_OnSetSelectedItem( &_this->VerticalList, _this->VerticalList.NoOfItems 
      - 1 );
      NavigationTbtListMenu_SwitchToPageOfSelectedItem( _this );
    }

    CoreGroup_InvalidateViewState((CoreGroup)_this );
  }
}

/* 'C' function for method : 'Navigation::TbtListMenu.OnSetArrowScrollBarVisible()' */
void NavigationTbtListMenu_OnSetArrowScrollBarVisible( NavigationTbtListMenu _this, 
  XBool value )
{
  if ( _this->ArrowScrollBarVisible != value )
  {
    _this->ArrowScrollBarVisible = value;
    CoreGroup__OnSetVisible( &_this->ArrowScrollBar, value );
  }
}

/* 'C' function for method : 'Navigation::TbtListMenu.OnPageScrolledSlot()' */
void NavigationTbtListMenu_OnPageScrolledSlot( NavigationTbtListMenu _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->ArrowScrollBarVisible )
  {
    XInt32 PageIdxOfSelectedItem = _this->VerticalList.SelectedItem / 2;
    MenuArrowScrollBar_OnSetCurrentPageIdx( &_this->ArrowScrollBar, PageIdxOfSelectedItem );
  }
}

/* 'C' function for method : 'Navigation::TbtListMenu.SwitchToPageOfSelectedItem()' */
void NavigationTbtListMenu_SwitchToPageOfSelectedItem( NavigationTbtListMenu _this )
{
  XInt32 CurrentPageIdx = ( -1 * _this->VerticalList.ScrollOffset ) / EwGetRectH( 
    _this->VerticalList.Super2.Bounds );
  XInt32 PageIdxOfSelectedItem = _this->VerticalList.SelectedItem / 2;

  if ( CurrentPageIdx != PageIdxOfSelectedItem )
  {
    _this->PageScrollEffect.Value1 = _this->VerticalList.ScrollOffset;
    _this->PageScrollEffect.Value2 = ( -1 * PageIdxOfSelectedItem ) * EwGetRectH( 
    _this->VerticalList.Super2.Bounds );
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->PageScrollEffect, 1 );
  }
}

/* Variants derived from the class : 'Navigation::TbtListMenu' */
EW_DEFINE_CLASS_VARIANTS( NavigationTbtListMenu )
EW_END_OF_CLASS_VARIANTS( NavigationTbtListMenu )

/* Virtual Method Table (VMT) for the class : 'Navigation::TbtListMenu' */
EW_DEFINE_CLASS( NavigationTbtListMenu, CoreGroup, VerticalList, VerticalList, VerticalList, 
                 VerticalList, NoOfItems, NoOfItems, "Navigation::TbtListMenu" )
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
  NavigationTbtListMenu_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
EW_END_OF_CLASS( NavigationTbtListMenu )

/* Initializer for the class 'Navigation::NAV09_NAV10_PoiList' */
void NavigationNAV09_NAV10_PoiList__Init( NavigationNAV09_NAV10_PoiList _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationNAV09_NAV10_PoiList );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->PoiListUpdateEventHandler, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->PoiListLoadingTimer, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->DataErrorText, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->CountDownTimer, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->NoDataText, &_this->_.XObject, 0 );
  PopPOP16_NaviLoadingUI__Init( &_this->LoadingAnimation, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Divider, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->ReturnToFirstRowTestTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationNAV09_NAV10_PoiList );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super2.SlideOutEffectEnabled = 1;
  MenuVerticalMenu_OnSetScrollbarVisible( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetSelectedItem( &_this->Super1.Menu, 0 );
  CoreTimer_OnSetPeriod( &_this->PoiListLoadingTimer, 3000 );
  CoreRectView__OnSetBounds( &_this->DataErrorText, _Const0060 );
  ViewsText_OnSetWrapText((ViewsText)&_this->DataErrorText, 1 );
  ViewsText_OnSetString((ViewsText)&_this->DataErrorText, EwGetVariantOfString( 
  &StringsPOP21_POI_LOADING_FAILED ));
  ViewsText_OnSetVisible((ViewsText)&_this->DataErrorText, 0 );
  CoreTimer_OnSetPeriod( &_this->CountDownTimer, 2000 );
  CoreRectView__OnSetBounds( &_this->NoDataText, _Const0060 );
  ViewsText_OnSetWrapText((ViewsText)&_this->NoDataText, 1 );
  ViewsText_OnSetString((ViewsText)&_this->NoDataText, 0 );
  ViewsText_OnSetVisible((ViewsText)&_this->NoDataText, 0 );
  CoreRectView__OnSetBounds( &_this->LoadingAnimation, _Const0000 );
  PopPOP16_NaviLoadingUI_OnSetAnimated( &_this->LoadingAnimation, 1 );
  CoreRectView__OnSetBounds( &_this->Divider, _Const004A );
  ViewsImage_OnSetAlignment( &_this->Divider, ViewsImageAlignmentAlignVertBottom 
  | ViewsImageAlignmentScaleToFit );
  CoreTimer_OnSetPeriod( &_this->ReturnToFirstRowTestTimer, 10000 );
  CoreGroup__Add( _this, ((CoreView)&_this->DataErrorText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NoDataText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LoadingAnimation ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider ), 0 );
  _this->PoiListUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV09_NAV10_PoiList_OnPoiListUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->PoiListUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->PoiListUpdateEvent );
  _this->PoiListLoadingTimer.OnTrigger = EwNewSlot( _this, NavigationNAV09_NAV10_PoiList_OnPoiListLoadingFailedSlot );
  ViewsText_OnSetFont((ViewsText)&_this->DataErrorText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->CountDownTimer.OnTrigger = EwNewSlot( _this, NavigationNAV09_NAV10_PoiList_OnListDismissSlot );
  ViewsText_OnSetFont((ViewsText)&_this->NoDataText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->Divider, EwLoadResource( &ResourceStatusBarDivider, 
  ResourcesBitmap ));
  _this->ReturnToFirstRowTestTimer.OnTrigger = EwNewSlot( _this, NavigationNAV09_NAV10_PoiList_OnReturnToFirstRowTestSlot );

  /* Call the user defined constructor */
  NavigationNAV09_NAV10_PoiList_Init( _this, aArg );
}

/* Re-Initializer for the class 'Navigation::NAV09_NAV10_PoiList' */
void NavigationNAV09_NAV10_PoiList__ReInit( NavigationNAV09_NAV10_PoiList _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->PoiListUpdateEventHandler );
  CoreTimer__ReInit( &_this->PoiListLoadingTimer );
  ComponentsBaseText__ReInit( &_this->DataErrorText );
  CoreTimer__ReInit( &_this->CountDownTimer );
  ComponentsBaseText__ReInit( &_this->NoDataText );
  PopPOP16_NaviLoadingUI__ReInit( &_this->LoadingAnimation );
  ViewsImage__ReInit( &_this->Divider );
  CoreTimer__ReInit( &_this->ReturnToFirstRowTestTimer );
}

/* Finalizer method for the class 'Navigation::NAV09_NAV10_PoiList' */
void NavigationNAV09_NAV10_PoiList__Done( NavigationNAV09_NAV10_PoiList _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CoreSystemEventHandler__Done( &_this->PoiListUpdateEventHandler );
  CoreTimer__Done( &_this->PoiListLoadingTimer );
  ComponentsBaseText__Done( &_this->DataErrorText );
  CoreTimer__Done( &_this->CountDownTimer );
  ComponentsBaseText__Done( &_this->NoDataText );
  PopPOP16_NaviLoadingUI__Done( &_this->LoadingAnimation );
  ViewsImage__Done( &_this->Divider );
  CoreTimer__Done( &_this->ReturnToFirstRowTestTimer );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void NavigationNAV09_NAV10_PoiList_Init( NavigationNAV09_NAV10_PoiList _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0061 ));
  CoreTimer_OnSetEnabled( &_this->PoiListLoadingTimer, 1 );
}

/* 'C' function for method : 'Navigation::NAV09_NAV10_PoiList.OnShortHomeKeyActivated()' */
void NavigationNAV09_NAV10_PoiList_OnShortHomeKeyActivated( NavigationNAV09_NAV10_PoiList _this )
{
  switch ( EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentPoiListType )
  {
    case EnumNaviPoiListTypeFAVORITE :
      DeviceInterfaceNavigationDeviceClass_PoiListRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ), EnumNaviPoiListTypeFAVORITE, 0 );
    break;

    case EnumNaviPoiListTypeGAS_STATION :
      DeviceInterfaceNavigationDeviceClass_PoiListRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ), EnumNaviPoiListTypeGAS_STATION, 0 );
    break;

    default :; 
  }

  ComponentsBaseMainBG_DismissThisDialog((ComponentsBaseMainBG)_this );
}

/* 'C' function for method : 'Navigation::NAV09_NAV10_PoiList.LoadItemClass()' */
XClass NavigationNAV09_NAV10_PoiList_LoadItemClass( NavigationNAV09_NAV10_PoiList _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemPoiList );
}

/* 'C' function for method : 'Navigation::NAV09_NAV10_PoiList.LoadItemTitle()' */
XString NavigationNAV09_NAV10_PoiList_LoadItemTitle( NavigationNAV09_NAV10_PoiList _this, 
  XInt32 aItemNo )
{
  XString title;
  DeviceInterfaceNaviPoiDataClass NaviPoiData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  title = 0;
  NaviPoiData = DeviceInterfaceNavigationDeviceClass_GetNaviPoiData( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), aItemNo );

  if ( NaviPoiData != 0 )
    title = NaviPoiData->PoiTitle;

  return title;
}

/* 'C' function for method : 'Navigation::NAV09_NAV10_PoiList.OnItemActivate()' */
void NavigationNAV09_NAV10_PoiList_OnItemActivate( NavigationNAV09_NAV10_PoiList _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  MenuBaseMenuView MenuDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  MenuDialog = 0;

  if ( EnumNaviPoiListTypeFAVORITE == EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass )->CurrentPoiListType )
  {
    if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
    {
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->RouteOptionTriggerItem 
      = EnumNaviRouteOptionTriggerItemFAVORITE_PLACE;
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentSelectPoiIdx 
      = aItemNo;
      MenuDialog = ((MenuBaseMenuView)EwNewObject( NavigationNAV11_RouteOptionMenu, 
      0 ));
    }
    else
    {
      DeviceInterfaceNavigationDeviceClass_StartRoute( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ), aItemNo, EnumNaviRouteOptionTypeNEW_ROUTE );
      DeviceInterfaceNavigationDeviceClass_PoiListRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ), EnumNaviPoiListTypeFAVORITE, 0 );
      EwPostSignal( EwNewSlot( _this, NavigationNAV09_NAV10_PoiList_ReturnToNaviMapView ), 
        ((XObject)_this ));
    }
  }
  else
    if ( EnumNaviPoiListTypeGAS_STATION == EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
        DeviceInterfaceNavigationDeviceClass )->CurrentPoiListType )
    {
      if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
          &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
      {
        EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->RouteOptionTriggerItem 
        = EnumNaviRouteOptionTriggerItemGAS_STATION;
        EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentSelectPoiIdx 
        = aItemNo;
        MenuDialog = ((MenuBaseMenuView)EwNewObject( NavigationNAV11_RouteOptionMenu, 
        0 ));
      }
      else
      {
        DeviceInterfaceNavigationDeviceClass_StartRoute( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
        DeviceInterfaceNavigationDeviceClass ), aItemNo, EnumNaviRouteOptionTypeNEW_ROUTE );
        DeviceInterfaceNavigationDeviceClass_PoiListRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
        DeviceInterfaceNavigationDeviceClass ), EnumNaviPoiListTypeGAS_STATION, 
        0 );
        EwPostSignal( EwNewSlot( _this, NavigationNAV09_NAV10_PoiList_ReturnToNaviMapView ), 
          ((XObject)_this ));
      }
    }

  if ( MenuDialog != 0 )
    ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)MenuDialog ));
}

/* 'C' function for method : 'Navigation::NAV09_NAV10_PoiList.LoadPoiListItemValue()' */
XString NavigationNAV09_NAV10_PoiList_LoadPoiListItemValue( NavigationNAV09_NAV10_PoiList _this, 
  XInt32 aItemNo )
{
  XString PoiItemValue;
  DeviceInterfaceNaviPoiDataClass NaviPoiData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  PoiItemValue = 0;
  NaviPoiData = DeviceInterfaceNavigationDeviceClass_GetNaviPoiData( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), aItemNo );

  if ( NaviPoiData != 0 )
  {
    if ( 0.000000f == EwMathFract( NaviPoiData->Distance ))
      PoiItemValue = EwNewStringInt((XInt32)NaviPoiData->Distance, 0, 10 );
    else
      PoiItemValue = EwNewStringFloat( NaviPoiData->Distance, 0, 1 );
  }

  return PoiItemValue;
}

/* 'C' function for method : 'Navigation::NAV09_NAV10_PoiList.LoadPoiListItemUnit()' */
XString NavigationNAV09_NAV10_PoiList_LoadPoiListItemUnit( NavigationNAV09_NAV10_PoiList _this, 
  XInt32 aItemNo )
{
  XString PoiItemUnit;
  DeviceInterfaceNaviPoiDataClass NaviPoiData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  PoiItemUnit = 0;
  NaviPoiData = DeviceInterfaceNavigationDeviceClass_GetNaviPoiData( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), aItemNo );

  if ( NaviPoiData != 0 )
    PoiItemUnit = NaviPoiData->DistUnit;

  return PoiItemUnit;
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV09_NAV10_PoiList_OnPoiListUpdateSlot( NavigationNAV09_NAV10_PoiList _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->PoiListLoadingTimer.Enabled )
  {
    CoreTimer_OnSetEnabled( &_this->PoiListLoadingTimer, 0 );
    CoreGroup__OnSetVisible( &_this->LoadingAnimation, 0 );
    PopPOP16_NaviLoadingUI_OnSetAnimated( &_this->LoadingAnimation, 0 );
    ViewsImage_OnSetVisible( &_this->Divider, 0 );
  }

  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, DeviceInterfaceNavigationDeviceClass_GetPoiListSize( 
  EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )));
  MenuVerticalMenu_OnSetSelectedItem( &_this->Super1.Menu, 0 );

  if ( _this->Super1.Menu.NoOfItems == 0 )
    switch ( EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentPoiListType )
    {
      case EnumNaviPoiListTypeFAVORITE :
      {
        ViewsText_OnSetString((ViewsText)&_this->DataErrorText, EwGetVariantOfString( 
        &StringsPOP19_NO_FAVORITE_PLACE ));
        ViewsText_OnSetVisible((ViewsText)&_this->DataErrorText, 1 );
        CoreTimer_OnSetEnabled( &_this->CountDownTimer, 1 );
      }
      break;

      case EnumNaviPoiListTypeGAS_STATION :
      {
        ViewsText_OnSetString((ViewsText)&_this->DataErrorText, EwGetVariantOfString( 
        &StringsPOP20_NO_GAS_STATION ));
        ViewsText_OnSetVisible((ViewsText)&_this->DataErrorText, 1 );
        CoreTimer_OnSetEnabled( &_this->CountDownTimer, 1 );
      }
      break;

      default :; 
    }
  else
    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, _this->Super1.Menu.NoOfItems 
    - 1 );
}

/* 'C' function for method : 'Navigation::NAV09_NAV10_PoiList.OnPoiListLoadingFailedSlot()' */
void NavigationNAV09_NAV10_PoiList_OnPoiListLoadingFailedSlot( NavigationNAV09_NAV10_PoiList _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->PoiListLoadingTimer, 0 );
  CoreGroup__OnSetVisible( &_this->LoadingAnimation, 0 );
  PopPOP16_NaviLoadingUI_OnSetAnimated( &_this->LoadingAnimation, 0 );
  ViewsImage_OnSetVisible( &_this->Divider, 0 );
  ViewsText_OnSetVisible((ViewsText)&_this->DataErrorText, 1 );
  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 1 );
}

/* 'C' function for method : 'Navigation::NAV09_NAV10_PoiList.OnListDismissSlot()' */
void NavigationNAV09_NAV10_PoiList_OnListDismissSlot( NavigationNAV09_NAV10_PoiList _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 0 );
  ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
}

/* 'C' function for method : 'Navigation::NAV09_NAV10_PoiList.ReturnToNaviMapView()' */
void NavigationNAV09_NAV10_PoiList_ReturnToNaviMapView( NavigationNAV09_NAV10_PoiList _this, 
  XObject sender )
{
  ApplicationApplication App;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
  {
    EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
    = EnumHomeTypeNAVI_DEFAULT_VIEW;
    ApplicationApplication_SwitchToHome( App, EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
    DeviceInterfaceNavigationDeviceClass )->CurrentHome );
  }
}

/* 'C' function for method : 'Navigation::NAV09_NAV10_PoiList.OnReturnToFirstRowTestSlot()' */
void NavigationNAV09_NAV10_PoiList_OnReturnToFirstRowTestSlot( NavigationNAV09_NAV10_PoiList _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->ReturnToFirstRowTestTimer, 0 );
  EwSignal( EwNewSlot( _this, NavigationNAV09_NAV10_PoiList_OnPoiListUpdateSlot ), 
    ((XObject)_this ));
}

/* Variants derived from the class : 'Navigation::NAV09_NAV10_PoiList' */
EW_DEFINE_CLASS_VARIANTS( NavigationNAV09_NAV10_PoiList )
EW_END_OF_CLASS_VARIANTS( NavigationNAV09_NAV10_PoiList )

/* Virtual Method Table (VMT) for the class : 'Navigation::NAV09_NAV10_PoiList' */
EW_DEFINE_CLASS( NavigationNAV09_NAV10_PoiList, MenuBaseMenuView, PoiListUpdateEventHandler, 
                 PoiListUpdateEventHandler, PoiListUpdateEventHandler, PoiListUpdateEventHandler, 
                 _.VMT, _.VMT, "Navigation::NAV09_NAV10_PoiList" )
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
  NavigationNAV09_NAV10_PoiList_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  MenuBaseMenuView_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  NavigationNAV09_NAV10_PoiList_LoadItemClass,
  NavigationNAV09_NAV10_PoiList_LoadItemTitle,
  NavigationNAV09_NAV10_PoiList_OnItemActivate,
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
  NavigationNAV09_NAV10_PoiList_LoadPoiListItemValue,
  NavigationNAV09_NAV10_PoiList_LoadPoiListItemUnit,
  MenuBaseMenuView_LoadItemIcon1Visible,
  MenuBaseMenuView_LoadItemIcon2Visible,
EW_END_OF_CLASS( NavigationNAV09_NAV10_PoiList )

/* Initializer for the class 'Navigation::NAV11_RouteOptionMenu' */
void NavigationNAV11_RouteOptionMenu__Init( NavigationNAV11_RouteOptionMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationNAV11_RouteOptionMenu );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationNAV11_RouteOptionMenu );

  /* ... and initialize objects, variables, properties, etc. */
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 3 );
  _this->NaviRouteOptions[ 0 ] = EnumNaviRouteOptionTypeNEW_ROUTE;
  _this->NaviRouteOptions[ 1 ] = EnumNaviRouteOptionTypeNEXT_STOP;
  _this->NaviRouteOptions[ 2 ] = EnumNaviRouteOptionTypeLAST_STOP;

  /* Call the user defined constructor */
  NavigationNAV11_RouteOptionMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Navigation::NAV11_RouteOptionMenu' */
void NavigationNAV11_RouteOptionMenu__ReInit( NavigationNAV11_RouteOptionMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Navigation::NAV11_RouteOptionMenu' */
void NavigationNAV11_RouteOptionMenu__Done( NavigationNAV11_RouteOptionMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void NavigationNAV11_RouteOptionMenu_Init( NavigationNAV11_RouteOptionMenu _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0062 ));
}

/* 'C' function for method : 'Navigation::NAV11_RouteOptionMenu.LoadItemClass()' */
XClass NavigationNAV11_RouteOptionMenu_LoadItemClass( NavigationNAV11_RouteOptionMenu _this, 
  XInt32 aItemNo )
{
  XClass ItemClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemClass = 0;

  if ( aItemNo >= 0 )
    ItemClass = EW_CLASS( MenuItemBase );

  return ItemClass;
}

/* 'C' function for method : 'Navigation::NAV11_RouteOptionMenu.LoadItemTitle()' */
XString NavigationNAV11_RouteOptionMenu_LoadItemTitle( NavigationNAV11_RouteOptionMenu _this, 
  XInt32 aItemNo )
{
  XString Title = 0;

  switch ( _this->NaviRouteOptions[ EwCheckIndex( aItemNo, 3 )])
  {
    case EnumNaviRouteOptionTypeNEW_ROUTE :
      Title = EwLoadString( &StringsNAV11_NEW_ROUTE );
    break;

    case EnumNaviRouteOptionTypeNEXT_STOP :
      Title = EwLoadString( &StringsNAV11_NEXT_STOP );
    break;

    case EnumNaviRouteOptionTypeLAST_STOP :
      Title = EwLoadString( &StringsNAV11_LAST_STOP );
    break;

    default :; 
  }

  return Title;
}

/* 'C' function for method : 'Navigation::NAV11_RouteOptionMenu.OnItemActivate()' */
void NavigationNAV11_RouteOptionMenu_OnItemActivate( NavigationNAV11_RouteOptionMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  switch ( EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->RouteOptionTriggerItem )
  {
    case EnumNaviRouteOptionTriggerItemHOME :
      DeviceInterfaceNavigationDeviceClass_GoHome( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ), _this->NaviRouteOptions[ EwCheckIndex( 
      aItemNo, 3 )]);
    break;

    case EnumNaviRouteOptionTriggerItemOFFICE :
      DeviceInterfaceNavigationDeviceClass_GoOffice( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ), _this->NaviRouteOptions[ EwCheckIndex( 
      aItemNo, 3 )]);
    break;

    case EnumNaviRouteOptionTriggerItemFAVORITE_PLACE :
    {
      DeviceInterfaceNavigationDeviceClass_StartRoute( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ), EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass )->CurrentSelectPoiIdx, _this->NaviRouteOptions[ 
      EwCheckIndex( aItemNo, 3 )]);
      DeviceInterfaceNavigationDeviceClass_PoiListRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ), EnumNaviPoiListTypeFAVORITE, 0 );
    }
    break;

    case EnumNaviRouteOptionTriggerItemGAS_STATION :
    {
      DeviceInterfaceNavigationDeviceClass_StartRoute( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ), EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass )->CurrentSelectPoiIdx, _this->NaviRouteOptions[ 
      EwCheckIndex( aItemNo, 3 )]);
      DeviceInterfaceNavigationDeviceClass_PoiListRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ), EnumNaviPoiListTypeGAS_STATION, 0 );
    }
    break;

    default :; 
  }

  EwPostSignal( EwNewSlot( _this, NavigationNAV11_RouteOptionMenu_ReturnToNaviMapView ), 
    ((XObject)_this ));
}

/* 'C' function for method : 'Navigation::NAV11_RouteOptionMenu.ReturnToNaviMapView()' */
void NavigationNAV11_RouteOptionMenu_ReturnToNaviMapView( NavigationNAV11_RouteOptionMenu _this, 
  XObject sender )
{
  ApplicationApplication App;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
  {
    EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
    = EnumHomeTypeNAVI_DEFAULT_VIEW;
    ApplicationApplication_SwitchToHome( App, EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
    DeviceInterfaceNavigationDeviceClass )->CurrentHome );
  }
}

/* Variants derived from the class : 'Navigation::NAV11_RouteOptionMenu' */
EW_DEFINE_CLASS_VARIANTS( NavigationNAV11_RouteOptionMenu )
EW_END_OF_CLASS_VARIANTS( NavigationNAV11_RouteOptionMenu )

/* Virtual Method Table (VMT) for the class : 'Navigation::NAV11_RouteOptionMenu' */
EW_DEFINE_CLASS( NavigationNAV11_RouteOptionMenu, MenuBaseMenuView, _.VMT, _.VMT, 
                 _.VMT, _.VMT, _.VMT, _.VMT, "Navigation::NAV11_RouteOptionMenu" )
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
  NavigationNAV11_RouteOptionMenu_LoadItemClass,
  NavigationNAV11_RouteOptionMenu_LoadItemTitle,
  NavigationNAV11_RouteOptionMenu_OnItemActivate,
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
EW_END_OF_CLASS( NavigationNAV11_RouteOptionMenu )

/* User defined constant: 'Navigation::TURN_ICON_BOUNDS_W_DIST' */
const XRect NavigationTURN_ICON_BOUNDS_W_DIST = {{ 45, 14 }, { 90, 59 }};

/* User defined constant: 'Navigation::TURN_ICON_BOUNDS_WO_DIST' */
const XRect NavigationTURN_ICON_BOUNDS_WO_DIST = {{ 45, 32 }, { 90, 77 }};

/* Initializer for the class 'Navigation::NaviTbtListDataEmptyDialog' */
void NavigationNaviTbtListDataEmptyDialog__Init( NavigationNaviTbtListDataEmptyDialog _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationNaviTbtListDataEmptyDialog );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->BlackBG, &_this->_.XObject, 0 );
  MenuPushButton__Init( &_this->PushButton, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->DataErrorMessage, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationNaviTbtListDataEmptyDialog );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0002 );
  CoreRectView__OnSetBounds( &_this->BlackBG, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->BlackBG, _Const0001 );
  CoreRectView__OnSetBounds( &_this->PushButton, _Const0063 );
  CoreGroup__OnSetVisible( &_this->PushButton, 1 );
  MenuPushButton_OnSetTitle( &_this->PushButton, EwLoadString( &StringsNAV03_VIEW_MAP ));
  CoreRectView__OnSetBounds( &_this->DataErrorMessage, _Const0064 );
  ViewsText_OnSetString( &_this->DataErrorMessage, EwLoadString( &StringsNAV03_NOT_ON_A_ROUTE ));
  ViewsText_OnSetVisible( &_this->DataErrorMessage, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->BlackBG ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PushButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DataErrorMessage ), 0 );
  _this->PushButton.OnActivate = EwNewSlot( _this, NavigationNaviTbtListDataEmptyDialog_OnViewMapSlot );
  ViewsText_OnSetFont( &_this->DataErrorMessage, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Navigation::NaviTbtListDataEmptyDialog' */
void NavigationNaviTbtListDataEmptyDialog__ReInit( NavigationNaviTbtListDataEmptyDialog _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->BlackBG );
  MenuPushButton__ReInit( &_this->PushButton );
  ViewsText__ReInit( &_this->DataErrorMessage );
}

/* Finalizer method for the class 'Navigation::NaviTbtListDataEmptyDialog' */
void NavigationNaviTbtListDataEmptyDialog__Done( NavigationNaviTbtListDataEmptyDialog _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->BlackBG );
  MenuPushButton__Done( &_this->PushButton );
  ViewsText__Done( &_this->DataErrorMessage );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Navigation::NaviTbtListDataEmptyDialog.OnViewMapSlot()' */
void NavigationNaviTbtListDataEmptyDialog_OnViewMapSlot( NavigationNaviTbtListDataEmptyDialog _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_DismissDialog( _this->Super3.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
  EwSignal( _this->ViewMapUpdateSlot, ((XObject)_this ));
}

/* Variants derived from the class : 'Navigation::NaviTbtListDataEmptyDialog' */
EW_DEFINE_CLASS_VARIANTS( NavigationNaviTbtListDataEmptyDialog )
EW_END_OF_CLASS_VARIANTS( NavigationNaviTbtListDataEmptyDialog )

/* Virtual Method Table (VMT) for the class : 'Navigation::NaviTbtListDataEmptyDialog' */
EW_DEFINE_CLASS( NavigationNaviTbtListDataEmptyDialog, CoreGroup, ViewMapUpdateSlot, 
                 ViewMapUpdateSlot, BlackBG, BlackBG, _.VMT, _.VMT, "Navigation::NaviTbtListDataEmptyDialog" )
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
EW_END_OF_CLASS( NavigationNaviTbtListDataEmptyDialog )

/* Initializer for the class 'Navigation::NaviZoomToast' */
void NavigationNaviZoomToast__Init( NavigationNaviZoomToast _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationNaviZoomToast );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->ZoomToast, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->ZoomLevelText, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationNaviZoomToast );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0065 );
  CoreRectView__OnSetBounds( &_this->ZoomToast, _Const0065 );
  CoreRectView__OnSetBounds( &_this->ZoomLevelText, _Const0066 );
  ViewsText_OnSetString( &_this->ZoomLevelText, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ZoomToast ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ZoomLevelText ), 0 );
  ViewsImage_OnSetBitmap( &_this->ZoomToast, EwLoadResource( &ResourceZoomToast, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->ZoomLevelText, EwLoadResource( &FontsNotoSansMedium16pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Navigation::NaviZoomToast' */
void NavigationNaviZoomToast__ReInit( NavigationNaviZoomToast _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->ZoomToast );
  ViewsText__ReInit( &_this->ZoomLevelText );
}

/* Finalizer method for the class 'Navigation::NaviZoomToast' */
void NavigationNaviZoomToast__Done( NavigationNaviZoomToast _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->ZoomToast );
  ViewsText__Done( &_this->ZoomLevelText );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* Variants derived from the class : 'Navigation::NaviZoomToast' */
EW_DEFINE_CLASS_VARIANTS( NavigationNaviZoomToast )
EW_END_OF_CLASS_VARIANTS( NavigationNaviZoomToast )

/* Virtual Method Table (VMT) for the class : 'Navigation::NaviZoomToast' */
EW_DEFINE_CLASS( NavigationNaviZoomToast, CoreGroup, ZoomToast, ZoomToast, ZoomToast, 
                 ZoomToast, _.VMT, _.VMT, "Navigation::NaviZoomToast" )
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
EW_END_OF_CLASS( NavigationNaviZoomToast )

/* Initializer for the class 'Navigation::ReRoute' */
void NavigationReRoute__Init( NavigationReRoute _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( NavigationReRoute );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->ReRouteBg, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ReRouteIcon, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->ReRouteMessage, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( NavigationReRoute );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0023 );
  CoreRectView__OnSetBounds( &_this->ReRouteBg, _Const0023 );
  ViewsRectangle_OnSetColor( &_this->ReRouteBg, ColorNAVI_GRAY );
  CoreRectView__OnSetBounds( &_this->ReRouteIcon, _Const0067 );
  CoreRectView__OnSetBounds( &_this->ReRouteMessage, _Const0068 );
  ViewsText_OnSetAlignment( &_this->ReRouteMessage, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ReRouteMessage, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ReRouteBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ReRouteIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ReRouteMessage ), 0 );
  ViewsImage_OnSetBitmap( &_this->ReRouteIcon, EwLoadResource( &ResourceAlertRouteIcon, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->ReRouteMessage, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Navigation::ReRoute' */
void NavigationReRoute__ReInit( NavigationReRoute _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->ReRouteBg );
  ViewsImage__ReInit( &_this->ReRouteIcon );
  ViewsText__ReInit( &_this->ReRouteMessage );
}

/* Finalizer method for the class 'Navigation::ReRoute' */
void NavigationReRoute__Done( NavigationReRoute _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->ReRouteBg );
  ViewsImage__Done( &_this->ReRouteIcon );
  ViewsText__Done( &_this->ReRouteMessage );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Navigation::ReRoute.OnSetMessage()' */
void NavigationReRoute_OnSetMessage( NavigationReRoute _this, XString value )
{
  if ( EwCompString( _this->Message, value ) != 0 )
  {
    _this->Message = EwShareString( value );
    ViewsText_OnSetString( &_this->ReRouteMessage, value );
  }
}

/* Variants derived from the class : 'Navigation::ReRoute' */
EW_DEFINE_CLASS_VARIANTS( NavigationReRoute )
EW_END_OF_CLASS_VARIANTS( NavigationReRoute )

/* Virtual Method Table (VMT) for the class : 'Navigation::ReRoute' */
EW_DEFINE_CLASS( NavigationReRoute, CoreGroup, ReRouteBg, ReRouteBg, ReRouteBg, 
                 ReRouteBg, Message, _.VMT, "Navigation::ReRoute" )
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
EW_END_OF_CLASS( NavigationReRoute )

/* Embedded Wizard */
