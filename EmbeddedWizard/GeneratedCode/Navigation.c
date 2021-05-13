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
#include "_CoreKeyPressHandler.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreVerticalList.h"
#include "_CoreView.h"
#include "_DeviceInterfaceNaviDataClass.h"
#include "_DeviceInterfaceNaviTbtDataClass.h"
#include "_DeviceInterfaceNavigationDeviceClass.h"
#include "_DeviceInterfaceVehicleDataClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_EffectsRectEffect.h"
#include "_MenuBaseMenuView.h"
#include "_MenuItemBase.h"
#include "_MenuItemCheckMark.h"
#include "_MenuPushButton.h"
#include "_MenuUpDownPushButtonSet.h"
#include "_MenuVerticalMenu.h"
#include "_NavigationNAV01_DefaultView.h"
#include "_NavigationNAV03_TBTListView.h"
#include "_NavigationNAV05_TBTView.h"
#include "_NavigationNAV06_NaviSettingMenu.h"
#include "_NavigationNAV08_NaviChageViewMenu.h"
#include "_NavigationNaviAlert.h"
#include "_NavigationNaviAlertMessage.h"
#include "_NavigationNaviCurrentRoad.h"
#include "_NavigationNaviDialog.h"
#include "_NavigationNaviETA.h"
#include "_NavigationTbtInfoItem.h"
#include "_NavigationTbtListMenu.h"
#include "_PopPOP03_HomeOfficeSettingError.h"
#include "_PopPOP09_POP14_BleConnectionErrorUI.h"
#include "_PopPOP17_AppInitSettingError.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesExternBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsFrame.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "_ViewsWallpaper.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Fonts.h"
#include "Navigation.h"
#include "Resource.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x0000010C, /* ratio 64.18 % */
  0xB8000D00, 0x8009A452, 0x00E00030, 0x60607858, 0xDE002911, 0x6640041C, 0x0E028021,
  0x636800D7, 0x8E438091, 0x046E330C, 0x1A0002F0, 0x023E098B, 0x0D800348, 0x4D243280,
  0xB0E0445A, 0x3A9B0005, 0x885CEA6E, 0x90422091, 0x042A1D17, 0x4E48B3DA, 0xE61D1D18,
  0x2090285C, 0x8B16A3D2, 0xC118B53E, 0x63984421, 0x5ACCBA26, 0x3A44E5A7, 0x01B8012B,
  0x08000670, 0x96CF0E94, 0x05D6B000, 0x176EB700, 0x05487056, 0x75001080, 0x3B0932CF,
  0xB3D80007, 0xBCC2C256, 0x58EC3663, 0xA6796096, 0x29228005, 0x231614C1, 0x00000407,
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
static const XRect _Const0009 = {{ 9, 122 }, { 49, 162 }};
static const XRect _Const000A = {{ 9, 170 }, { 49, 210 }};
static const XRect _Const000B = {{ 411, 164 }, { 473, 226 }};
static const XRect _Const000C = {{ 420, 179 }, { 464, 212 }};
static const XRect _Const000D = {{ 480, 226 }, { 480, 272 }};
static const XRect _Const000E = {{ 0, 38 }, { 480, 49 }};
static const XRect _Const000F = {{ 0, 226 }, { 480, 272 }};
static const XRect _Const0010 = {{ 370, 226 }, { 480, 272 }};
static const XColor _Const0011 = { 0x00, 0x00, 0x00, 0x80 };
static const XStringRes _Const0012 = { _StringsDefault0, 0x0002 };
static const XRect _Const0013 = {{ 0, 0 }, { 0, 0 }};
static const XRect _Const0014 = {{ 140, 228 }, { 470, 259 }};
static const XRect _Const0015 = {{ 0, 0 }, { 330, 31 }};
static const XRect _Const0016 = {{ 0, 8 }, { 20, 28 }};
static const XRect _Const0017 = {{ 24, 0 }, { 330, 31 }};
static const XStringRes _Const0018 = { _StringsDefault0, 0x0008 };
static const XRect _Const0019 = {{ 0, 0 }, { 480, 46 }};
static const XRect _Const001A = {{ 405, 0 }, { 480, 46 }};
static const XColor _Const001B = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const001C = {{ 445, 9 }, { 470, 31 }};
static const XRect _Const001D = {{ 405, 3 }, { 443, 33 }};
static const XStringRes _Const001E = { _StringsDefault0, 0x000F };
static const XStringRes _Const001F = { _StringsDefault0, 0x0014 };
static const XStringRes _Const0020 = { _StringsDefault0, 0x0018 };
static const XStringRes _Const0021 = { _StringsDefault0, 0x001F };
static const XRect _Const0022 = {{ 370, 0 }, { 480, 46 }};
static const XColor _Const0023 = { 0xE2, 0x7F, 0x07, 0xFF };
static const XColor _Const0024 = { 0xAA, 0x14, 0x15, 0xFF };
static const XRect _Const0025 = {{ 0, 0 }, { 405, 46 }};
static const XRect _Const0026 = {{ 10, 8 }, { 30, 28 }};
static const XRect _Const0027 = {{ 34, 2 }, { 315, 33 }};
static const XRect _Const0028 = {{ 325, 3 }, { 352, 33 }};
static const XRect _Const0029 = {{ 354, 9 }, { 395, 31 }};
static const XRect _Const002A = {{ 0, 0 }, { 110, 33 }};
static const XRect _Const002B = {{ 19, 7 }, { 39, 29 }};
static const XRect _Const002C = {{ 41, 2 }, { 92, 33 }};
static const XRect _Const002D = {{ 84, 9 }, { 110, 31 }};
static const XStringRes _Const002E = { _StringsDefault0, 0x0028 };
static const XStringRes _Const002F = { _StringsDefault0, 0x0030 };
static const XStringRes _Const0030 = { _StringsDefault0, 0x0035 };
static const XStringRes _Const0031 = { _StringsDefault0, 0x003A };
static const XStringRes _Const0032 = { _StringsDefault0, 0x003F };
static const XStringRes _Const0033 = { _StringsDefault0, 0x0043 };
static const XStringRes _Const0034 = { _StringsDefault0, 0x0049 };
static const XRect _Const0035 = {{ 0, 38 }, { 480, 226 }};
static const XRect _Const0036 = {{ 186, 68 }, { 254, 116 }};
static const XRect _Const0037 = {{ 254, 82 }, { 278, 112 }};
static const XRect _Const0038 = {{ 186, 117 }, { 408, 210 }};
static const XColor _Const0039 = { 0xCF, 0xCF, 0xCF, 0xFF };
static const XRect _Const003A = {{ 28, 54 }, { 178, 204 }};
static const XRect _Const003B = {{ 104, 75 }, { 376, 199 }};
static const XStringRes _Const003C = { _StringsDefault0, 0x004E };
static const XStringRes _Const003D = { _StringsDefault0, 0x005F };
static const XRect _Const003E = {{ 0, 36 }, { 480, 272 }};
static const XStringRes _Const003F = { _StringsDefault0, 0x0068 };
static const XRect _Const0040 = {{ 0, 0 }, { 480, 74 }};
static const XRect _Const0041 = {{ 20, 0 }, { 440, 72 }};
static const XColor _Const0042 = { 0x1E, 0x47, 0x8C, 0xFF };
static const XRect _Const0043 = {{ 30, 22 }, { 58, 50 }};
static const XRect _Const0044 = {{ 62, 19 }, { 106, 53 }};
static const XRect _Const0045 = {{ 106, 19 }, { 154, 53 }};
static const XRect _Const0046 = {{ 155, 5 }, { 430, 72 }};
static const XColor _Const0047 = { 0xC8, 0xC8, 0xC8, 0xFF };
static const XRect _Const0048 = {{ 0, 72 }, { 480, 74 }};
static const XRect _Const0049 = {{ 0, 0 }, { 480, 236 }};
static const XRect _Const004A = {{ 0, 0 }, { 340, 252 }};
static const XRect _Const004B = {{ 15, 13 }, { 325, 190 }};
static const XStringRes _Const004C = { _StringsDefault0, 0x007D };
static const XStringRes _Const004D = { _StringsDefault0, 0x0082 };
static const XRect _Const004E = {{ 69, 154 }, { 271, 240 }};
static const XRect _Const004F = {{ 15, 13 }, { 325, 144 }};
static const XRect _Const0050 = {{ 69, 200 }, { 271, 240 }};

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
  HomeBaseHome__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationNAV01_DefaultView );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Background, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->MapUpdateEventHandler, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->MapImage, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->ArrivalBg, &_this->_XObject, 0 );
  NavigationNaviETA__Init( &_this->ETAComponent, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->RoadNameBg, &_this->_XObject, 0 );
  NavigationNaviCurrentRoad__Init( &_this->CurrentRoadWithGuide, &_this->_XObject, 0 );
  NavigationNaviCurrentRoad__Init( &_this->CurrentRoadWithOutGuide, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Shadow, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ZoomInButton, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ZoomOutButton, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->SpeedLimitIcon, &_this->_XObject, 0 );
  ViewsText__Init( &_this->SpeedLimitText, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->CurRdUpdateEventHandler, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ETAUpdateEventHandler, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->DayNightModeUpdateEventHandler, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->HighlightTimer, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->SpeedLimitUpdateEventHandler, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NaviIncidentUpdateEventHandler, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->CurrentRoadShiftEffect, &_this->_XObject, 0 );
  NavigationNaviAlert__Init( &_this->NaviEventObject, &_this->_XObject, 0 );
  ViewsWallpaper__Init( &_this->StatusBarShadowImage, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->NaviEventEnLargeEffect, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->NaviEventDismissEffect, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NavigatingStatusUpdateEventHandler, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->SpeedLimitFlickeringTimer, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NaviDialogEventHandler, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->Mask, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationNAV01_DefaultView );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super1.HomeType = EnumHomeTypeNAVI_DEFAULT_VIEW;
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
  CoreRectView__OnSetBounds( &_this->ZoomInButton, _Const0009 );
  ViewsImage_OnSetVisible( &_this->ZoomInButton, 1 );
  CoreRectView__OnSetBounds( &_this->ZoomOutButton, _Const000A );
  ViewsImage_OnSetVisible( &_this->ZoomOutButton, 1 );
  CoreRectView__OnSetBounds( &_this->SpeedLimitIcon, _Const000B );
  ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 0 );
  CoreRectView__OnSetBounds( &_this->SpeedLimitText, _Const000C );
  ViewsText_OnSetString( &_this->SpeedLimitText, 0 );
  ViewsText_OnSetColor( &_this->SpeedLimitText, _Const0001 );
  ViewsText_OnSetVisible( &_this->SpeedLimitText, 0 );
  CoreTimer_OnSetPeriod( &_this->HighlightTimer, 100 );
  CoreTimer_OnSetEnabled( &_this->HighlightTimer, 0 );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->CurrentRoadShiftEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->CurrentRoadShiftEffect, 
  500 );
  CoreRectView__OnSetBounds( &_this->NaviEventObject, _Const000D );
  CoreRectView__OnSetBounds( &_this->StatusBarShadowImage, _Const000E );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->NaviEventEnLargeEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->NaviEventEnLargeEffect, 
  500 );
  _this->NaviEventEnLargeEffect.Value2 = _Const000F;
  _this->NaviEventEnLargeEffect.Value1 = _Const000D;
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->NaviEventDismissEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->NaviEventDismissEffect, 
  500 );
  _this->NaviEventDismissEffect.Value2 = _Const000D;
  _this->NaviEventDismissEffect.Value1 = _Const0010;
  CoreTimer_OnSetPeriod( &_this->SpeedLimitFlickeringTimer, 300 );
  CoreRectView__OnSetBounds( &_this->Mask, _Const0002 );
  ViewsRectangle_OnSetColor( &_this->Mask, _Const0011 );
  ViewsRectangle_OnSetVisible( &_this->Mask, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Background ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MapImage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ArrivalBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ETAComponent ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RoadNameBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CurrentRoadWithGuide ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CurrentRoadWithOutGuide ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Shadow ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ZoomInButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ZoomOutButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SpeedLimitIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SpeedLimitText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviEventObject ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->StatusBarShadowImage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Mask ), 0 );
  _this->MapUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV01_DefaultView_OnMapUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->MapUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->MapUpdateEvent );
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
  _this->NaviIncidentUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV01_DefaultView_OnNaviIncidentUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NaviIncidentUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->NaviIncidentUpdateEvent );
  _this->CurrentRoadShiftEffect.Super1.OnFinished = EwNewSlot( _this, NavigationNAV01_DefaultView_OnCurrentRoadShiftEffectFinishSlot );
  _this->CurrentRoadShiftEffect.Outlet = EwNewRef( &_this->CurrentRoadWithGuide, 
  CoreRectView_OnGetBounds, CoreRectView__OnSetBounds );
  _this->NaviEventObject.DismissAlertSignal = EwNewSlot( _this, NavigationNAV01_DefaultView_DismissAlert );
  ViewsWallpaper_OnSetBitmap( &_this->StatusBarShadowImage, EwLoadResource( &ResourceStatusBarShadow, 
  ResourcesBitmap ));
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
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV01_DefaultView_OnVehicleSpeedUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );
  _this->NaviDialogEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV01_DefaultView_OnNaviDialogEventUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NaviDialogEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->DialogEventUpdateEvent );

  /* Call the user defined constructor */
  NavigationNAV01_DefaultView_Init( _this, aArg );
}

/* Re-Initializer for the class 'Navigation::NAV01_DefaultView' */
void NavigationNAV01_DefaultView__ReInit( NavigationNAV01_DefaultView _this )
{
  /* At first re-initialize the super class ... */
  HomeBaseHome__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Background );
  CoreSystemEventHandler__ReInit( &_this->MapUpdateEventHandler );
  ViewsImage__ReInit( &_this->MapImage );
  ViewsRectangle__ReInit( &_this->ArrivalBg );
  NavigationNaviETA__ReInit( &_this->ETAComponent );
  ViewsRectangle__ReInit( &_this->RoadNameBg );
  NavigationNaviCurrentRoad__ReInit( &_this->CurrentRoadWithGuide );
  NavigationNaviCurrentRoad__ReInit( &_this->CurrentRoadWithOutGuide );
  ViewsImage__ReInit( &_this->Shadow );
  ViewsImage__ReInit( &_this->ZoomInButton );
  ViewsImage__ReInit( &_this->ZoomOutButton );
  ViewsImage__ReInit( &_this->SpeedLimitIcon );
  ViewsText__ReInit( &_this->SpeedLimitText );
  CoreSystemEventHandler__ReInit( &_this->CurRdUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->ETAUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->DayNightModeUpdateEventHandler );
  CoreTimer__ReInit( &_this->HighlightTimer );
  CoreSystemEventHandler__ReInit( &_this->SpeedLimitUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->NaviIncidentUpdateEventHandler );
  EffectsRectEffect__ReInit( &_this->CurrentRoadShiftEffect );
  NavigationNaviAlert__ReInit( &_this->NaviEventObject );
  ViewsWallpaper__ReInit( &_this->StatusBarShadowImage );
  EffectsRectEffect__ReInit( &_this->NaviEventEnLargeEffect );
  EffectsRectEffect__ReInit( &_this->NaviEventDismissEffect );
  CoreSystemEventHandler__ReInit( &_this->NavigatingStatusUpdateEventHandler );
  CoreTimer__ReInit( &_this->SpeedLimitFlickeringTimer );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
  CoreSystemEventHandler__ReInit( &_this->NaviDialogEventHandler );
  ViewsRectangle__ReInit( &_this->Mask );
}

/* Finalizer method for the class 'Navigation::NAV01_DefaultView' */
void NavigationNAV01_DefaultView__Done( NavigationNAV01_DefaultView _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Background );
  CoreSystemEventHandler__Done( &_this->MapUpdateEventHandler );
  ViewsImage__Done( &_this->MapImage );
  ViewsRectangle__Done( &_this->ArrivalBg );
  NavigationNaviETA__Done( &_this->ETAComponent );
  ViewsRectangle__Done( &_this->RoadNameBg );
  NavigationNaviCurrentRoad__Done( &_this->CurrentRoadWithGuide );
  NavigationNaviCurrentRoad__Done( &_this->CurrentRoadWithOutGuide );
  ViewsImage__Done( &_this->Shadow );
  ViewsImage__Done( &_this->ZoomInButton );
  ViewsImage__Done( &_this->ZoomOutButton );
  ViewsImage__Done( &_this->SpeedLimitIcon );
  ViewsText__Done( &_this->SpeedLimitText );
  CoreSystemEventHandler__Done( &_this->CurRdUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->ETAUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->DayNightModeUpdateEventHandler );
  CoreTimer__Done( &_this->HighlightTimer );
  CoreSystemEventHandler__Done( &_this->SpeedLimitUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->NaviIncidentUpdateEventHandler );
  EffectsRectEffect__Done( &_this->CurrentRoadShiftEffect );
  NavigationNaviAlert__Done( &_this->NaviEventObject );
  ViewsWallpaper__Done( &_this->StatusBarShadowImage );
  EffectsRectEffect__Done( &_this->NaviEventEnLargeEffect );
  EffectsRectEffect__Done( &_this->NaviEventDismissEffect );
  CoreSystemEventHandler__Done( &_this->NavigatingStatusUpdateEventHandler );
  CoreTimer__Done( &_this->SpeedLimitFlickeringTimer );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );
  CoreSystemEventHandler__Done( &_this->NaviDialogEventHandler );
  ViewsRectangle__Done( &_this->Mask );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void NavigationNAV01_DefaultView_Init( NavigationNAV01_DefaultView _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  if ( DeviceInterfaceNavigationDeviceClass_IsMapFrameReady( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass )))
  {
    if ( !ViewsImage_OnGetVisible( &_this->Shadow ))
    {
      ViewsImage_OnSetVisible( &_this->Shadow, 1 );
    }

    EwPostSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnMapUpdateSlot ), 
      ((XObject)_this ));
  }

  NavigationNAV01_DefaultView_SetItemBounds( _this );
  EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnCurRdUpdateSlot ), ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnETAUpdateSlot ), ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnDayNightModeUpdateSlot ), 
    ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnSpeedLimitUpdateSlot ), 
    ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnNaviIncidentUpdateSlot ), 
    ((XObject)_this ));
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnShortDownKeyActivated()' */
void NavigationNAV01_DefaultView_OnShortDownKeyActivated( NavigationNAV01_DefaultView _this )
{
  if ( ViewsImage_OnGetVisible( &_this->ZoomOutButton ) && EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass )->IsZoomLevelButtonEnabled )
  {
    EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->IsZoomLevelButtonEnabled 
    = 0;
    _this->ZoomButtonStatus = 1;
    NavigationNAV01_DefaultView_StartHighlight( _this );
    DeviceInterfaceNavigationDeviceClass_ZoomOutRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
    DeviceInterfaceNavigationDeviceClass ));
  }
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnShortUpKeyActivated()' */
void NavigationNAV01_DefaultView_OnShortUpKeyActivated( NavigationNAV01_DefaultView _this )
{
  if ( ViewsImage_OnGetVisible( &_this->ZoomInButton ) && EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass )->IsZoomLevelButtonEnabled )
  {
    EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->IsZoomLevelButtonEnabled 
    = 0;
    _this->ZoomButtonStatus = 0;
    NavigationNAV01_DefaultView_StartHighlight( _this );
    DeviceInterfaceNavigationDeviceClass_ZoomInRequest( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
    DeviceInterfaceNavigationDeviceClass ));
  }
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnLongEnterKeyActivated()' */
void NavigationNAV01_DefaultView_OnLongEnterKeyActivated( NavigationNAV01_DefaultView _this )
{
  if ( 1 == _this->Super3.KeyHandler.RepetitionCount )
  {
    if ( !DeviceInterfaceNavigationDeviceClass_GetNaviConnectStatus( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
    {
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( PopPOP09_POP14_BleConnectionErrorUI, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
    else
      if ( !DeviceInterfaceNavigationDeviceClass_GetNaviAppInitSettingStatus( EwGetAutoObject( 
          &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
      {
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( PopPOP17_AppInitSettingError, 
        0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
      else
      {
        DeviceInterfaceNavigationDeviceClass_StopMapFrameRequest( EwGetAutoObject( 
        &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( NavigationNAV06_NaviSettingMenu, 
        0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnMapUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( !ViewsImage_OnGetVisible( &_this->Shadow ))
  {
    ViewsImage_OnSetVisible( &_this->Shadow, 1 );
  }

  _this->MapFrameIdx = _this->MapFrameIdx + 1;
  ResourcesExternBitmap_OnSetName( EwGetAutoObject( &ResourceExternBitmap, ResourcesExternBitmap ), 
  EwConcatString( EwLoadString( &_Const0012 ), EwNewStringInt( _this->MapFrameIdx, 
  0, 10 )));
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

  if ( !!NaviData->DayNightMode )
  {
    ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInNightIcon, 
    ResourcesBitmap ));
    ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutNightIcon, 
    ResourcesBitmap ));
  }
  else
  {
    ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInDayIcon, 
    ResourcesBitmap ));
    ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutDayIcon, 
    ResourcesBitmap ));
  }
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.StartHighlight()' */
void NavigationNAV01_DefaultView_StartHighlight( NavigationNAV01_DefaultView _this )
{
  DeviceInterfaceNaviDataClass NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( 
    EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
    EnumNaviDataTypeDAYNIGHT );

  if ( !!!_this->ZoomButtonStatus )
  {
    if ( !!NaviData->DayNightMode )
    {
      ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInNightFocusIcon, 
      ResourcesBitmap ));
    }
    else
    {
      ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInDayFocusIcon, 
      ResourcesBitmap ));
    }
  }
  else
  {
    if ( !!NaviData->DayNightMode )
    {
      ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutNightFocusIcon, 
      ResourcesBitmap ));
    }
    else
    {
      ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutDayFocusIcon, 
      ResourcesBitmap ));
    }
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

  if ( !!!_this->ZoomButtonStatus )
  {
    if ( !!NaviData->DayNightMode )
    {
      ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInNightIcon, 
      ResourcesBitmap ));
    }
    else
    {
      ViewsImage_OnSetBitmap( &_this->ZoomInButton, EwLoadResource( &ResourceZoomInDayIcon, 
      ResourcesBitmap ));
    }
  }
  else
  {
    if ( !!NaviData->DayNightMode )
    {
      ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutNightIcon, 
      ResourcesBitmap ));
    }
    else
    {
      ViewsImage_OnSetBitmap( &_this->ZoomOutButton, EwLoadResource( &ResourceZoomOutDayIcon, 
      ResourcesBitmap ));
    }
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
    {
      CoreTimer_OnSetEnabled( &_this->SpeedLimitFlickeringTimer, 1 );
    }
    else
    {
      CoreTimer_OnSetEnabled( &_this->SpeedLimitFlickeringTimer, 0 );
    }
  }
  else
  {
    ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 0 );
    ViewsText_OnSetVisible( &_this->SpeedLimitText, 0 );
    CoreTimer_OnSetEnabled( &_this->SpeedLimitFlickeringTimer, 0 );
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnNaviIncidentUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( !_this->IsEventDisplaying )
  {
    DeviceInterfaceNaviDataClass NaviData;
    _this->IsEventDisplaying = 1;
    NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( EwGetAutoObject( 
    &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), EnumNaviDataTypeNAVI_EVENT );

    if (( NaviData != 0 ) && NaviData->NaviEventVisibility )
    {
      NavigationNaviAlert_SetAlert( &_this->NaviEventObject, NaviData->NaviEventType, 
      NaviData->NaviCameraType, NaviData->NaviEventSpeed, NaviData->NaviEventDist );
      EffectsEffect_OnSetEnabled((EffectsEffect)&_this->NaviEventEnLargeEffect, 
      1 );
    }
    else
    {
      _this->IsEventDisplaying = 0;
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
  _this->IsEventDisplaying = 0;
  EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnNaviIncidentUpdateSlot ), 
    ((XObject)_this ));
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.DismissAlert()' */
void NavigationNAV01_DefaultView_DismissAlert( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  XRect NewCurrentRoadObjectBounds;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->CurrentRoadShiftEffect.Value1 = _this->CurrentRoadWithGuide.Super2.Bounds;
  NewCurrentRoadObjectBounds = _Const0013;
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
    CoreRectView__OnSetBounds( &_this->CurrentRoadWithGuide, _Const0014 );
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

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnVehicleSpeedUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if (( VehicleData != 0 ) && ( EnumVehicleRxTypeVEHICLE_SPEED_REAL == VehicleData->RxType ))
  {
    EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnSpeedLimitUpdateSlot ), 
      ((XObject)_this ));
  }
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
    CoreGroup__OnSetVisible( &_this->CurrentRoadWithOutGuide, 0 );
  }
  else
  {
    CoreRectView__OnSetBounds( &_this->ZoomInButton, NavigationZOOMIN_WO_NAVI_BOUNDS );
    CoreRectView__OnSetBounds( &_this->ZoomOutButton, NavigationZOOMOUT_WO_NAVI_BOUNDS );
    CoreRectView__OnSetBounds( &_this->RoadNameBg, NavigationROAD_BG_WO_NAVI_BOUNDS );
    CoreGroup__OnSetVisible( &_this->CurrentRoadWithGuide, 0 );
    CoreGroup__OnSetVisible( &_this->CurrentRoadWithOutGuide, 1 );
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnNaviDialogEventUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  XEnum NaviDialog;
  XString NaviDialogMessage;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  NaviDialog = DeviceInterfaceNavigationDeviceClass_GetNaviDialogType( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));
  NaviDialogMessage = DeviceInterfaceNavigationDeviceClass_GetNaviDialogMessage( 
  EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ));

  switch ( NaviDialog )
  {
    case EnumNaviDialogTypeDIALOG_YES_NO :
    {
      NavigationNaviDialog Dialog = EwNewObject( NavigationNaviDialog, 0 );
      NavigationNaviDialog_OnSetDialogType( Dialog, EnumNaviDialogTypeDIALOG_YES_NO );
      NavigationNaviDialog_OnSetDialogButton( Dialog, EW_CLASS( MenuUpDownPushButtonSet ));
      NavigationNaviDialog_OnSetDialogMessage( Dialog, NaviDialogMessage );
      Dialog->OnDialogDismiss = EwNewSlot( _this, NavigationNAV01_DefaultView_OnNaviDialogDismissSlot );
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)Dialog ), 0, 0, 0, 0, 
      0, 0, EwNullSlot, EwNullSlot, 0 );
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
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)Dialog ), 0, 0, 0, 0, 
      0, 0, EwNullSlot, EwNullSlot, 0 );
      ViewsRectangle_OnSetVisible( &_this->Mask, 1 );
    }
    break;

    default : 
      ;
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
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( NavigationNAV01_DefaultView )

/* Initializer for the class 'Navigation::NAV06_NaviSettingMenu' */
void NavigationNAV06_NaviSettingMenu__Init( NavigationNAV06_NaviSettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationNAV06_NaviSettingMenu );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->HomeSettingUpdateSystemEventHandler, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->OfficeSettingUpdateEventHandler, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NavigatingStatusUpdateEventHandler, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ViaPointUpdateEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationNAV06_NaviSettingMenu );

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
  _this->HomeSettingUpdateSystemEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV06_NaviSettingMenu_OnHomeSettingUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->HomeSettingUpdateSystemEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->HomeSettingUpdateEvent );
  _this->OfficeSettingUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV06_NaviSettingMenu_OnOfficeSettingUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->OfficeSettingUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->OfficeSettingUpdateEvent );
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
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->HomeSettingUpdateSystemEventHandler );
  CoreSystemEventHandler__ReInit( &_this->OfficeSettingUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->NavigatingStatusUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->ViaPointUpdateEventHandler );
}

/* Finalizer method for the class 'Navigation::NAV06_NaviSettingMenu' */
void NavigationNAV06_NaviSettingMenu__Done( NavigationNAV06_NaviSettingMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CoreSystemEventHandler__Done( &_this->HomeSettingUpdateSystemEventHandler );
  CoreSystemEventHandler__Done( &_this->OfficeSettingUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->NavigatingStatusUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->ViaPointUpdateEventHandler );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void NavigationNAV06_NaviSettingMenu_Init( NavigationNAV06_NaviSettingMenu _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  NavigationNAV06_NaviSettingMenu_SetNaviSettingMenuItem( _this );
}

/* 'C' function for method : 'Navigation::NAV06_NaviSettingMenu.OnShortHomeKeyActivated()' */
void NavigationNAV06_NaviSettingMenu_OnShortHomeKeyActivated( NavigationNAV06_NaviSettingMenu _this )
{
  CoreGroup_DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
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
  {
    ItemClass = EW_CLASS( MenuItemBase );
  }

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
      Title = EwLoadString( &StringsNAV06_STOP_NAVIGATION );
    break;

    case EnumNaviSettingItemSkipNextStop :
      Title = EwLoadString( &StringsNAV06_SKIP_NEXT_STOP );
    break;

    case EnumNaviSettingItemGoHome :
      Title = EwLoadString( &StringsNAV06_GO_HOME );
    break;

    case EnumNaviSettingItemGoToWork :
      Title = EwLoadString( &StringsNAV06_GO_TO_WORK );
    break;

    case EnumNaviSettingItemFavorites :
      Title = EwLoadString( &StringsNAV06_FAVORITES );
    break;

    case EnumNaviSettingItemNearbyGasStations :
      Title = EwLoadString( &StringsNAV06_NEARBY_GAS_STATIONS );
    break;

    case EnumNaviSettingItemChangeView :
      Title = EwLoadString( &StringsNAV06_CHANGE_VIEW );
    break;

    default : 
      ;
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
      DeviceInterfaceNavigationDeviceClass_SkipNextWaypoint( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ));
    }
    break;

    case EnumNaviSettingItemGoHome :
    {
      _this->SelectedItem = EnumNaviSettingItemGoHome;
      DeviceInterfaceNavigationDeviceClass_GoHome( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ));
    }
    break;

    case EnumNaviSettingItemGoToWork :
    {
      _this->SelectedItem = EnumNaviSettingItemGoToWork;
      DeviceInterfaceNavigationDeviceClass_GoOffice( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass ));
    }
    break;

    case EnumNaviSettingItemFavorites :
      ;
    break;

    case EnumNaviSettingItemNearbyGasStations :
      ;
    break;

    case EnumNaviSettingItemChangeView :
      MenuDialog = ((MenuBaseMenuView)EwNewObject( NavigationNAV08_NaviChageViewMenu, 
      0 ));
    break;

    default : 
      ;
  }

  if ( MenuDialog != 0 )
  {
    ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)MenuDialog ));
  }
}

/* 'C' function for method : 'Navigation::NAV06_NaviSettingMenu.LoadItemEnabled()' */
XBool NavigationNAV06_NaviSettingMenu_LoadItemEnabled( NavigationNAV06_NaviSettingMenu _this, 
  XInt32 aItemNo )
{
  XBool ItemEnabled = 1;

  switch ( _this->NaviSettings[ EwCheckIndex( aItemNo, 7 )])
  {
    case EnumNaviSettingItemStopNavigation :
      ;
    break;

    case EnumNaviSettingItemSkipNextStop :
      ;
    break;

    case EnumNaviSettingItemGoHome :
      ;
    break;

    case EnumNaviSettingItemGoToWork :
      ;
    break;

    case EnumNaviSettingItemFavorites :
      ;
    break;

    case EnumNaviSettingItemNearbyGasStations :
      ;
    break;

    case EnumNaviSettingItemChangeView :
    {
      if ( !DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
          &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
      {
        ItemEnabled = 0;
      }
    }
    break;

    default : 
      ;
  }

  return ItemEnabled;
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV06_NaviSettingMenu_OnHomeSettingUpdateSlot( NavigationNAV06_NaviSettingMenu _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->IsHomeSet 
      && ( _this->SelectedItem == EnumNaviSettingItemGoHome ))
  {
    ApplicationApplication App;
    _this->SelectedItem = EnumNaviSettingItemTOTAL;
    App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

    if ( App != 0 )
    {
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
      = EnumHomeTypeNAVI_DEFAULT_VIEW;
      ApplicationApplication_SwitchToHome( App, EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass )->CurrentHome );
    }
  }
  else
  {
    PopPOP03_HomeOfficeSettingError HomeSettingError = EwNewObject( PopPOP03_HomeOfficeSettingError, 
      0 );
    PopPOP03_HomeOfficeSettingError_OnSetErrorMessage( HomeSettingError, EwLoadString( 
    &StringsPOP03_NO_HOME_LOCATION ));
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)HomeSettingError ), 0, 
    0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV06_NaviSettingMenu_OnOfficeSettingUpdateSlot( NavigationNAV06_NaviSettingMenu _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->IsOfficeSet 
      && ( _this->SelectedItem == EnumNaviSettingItemGoToWork ))
  {
    ApplicationApplication App;
    _this->SelectedItem = EnumNaviSettingItemTOTAL;
    App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

    if ( App != 0 )
    {
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
      = EnumHomeTypeNAVI_DEFAULT_VIEW;
      ApplicationApplication_SwitchToHome( App, EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass )->CurrentHome );
    }
  }
  else
  {
    PopPOP03_HomeOfficeSettingError OfficeSettingError = EwNewObject( PopPOP03_HomeOfficeSettingError, 
      0 );
    PopPOP03_HomeOfficeSettingError_OnSetErrorMessage( OfficeSettingError, EwLoadString( 
    &StringsPOP03_NO_OFFICE_LOCATION ));
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)OfficeSettingError ), 
    0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
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
    ApplicationApplication App;
    _this->SelectedItem = EnumNaviSettingItemTOTAL;
    App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

    if ( App != 0 )
    {
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurrentHome 
      = EnumHomeTypeNAVI_DEFAULT_VIEW;
      ApplicationApplication_SwitchToHome( App, EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass )->CurrentHome );
    }
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
    ApplicationApplication App;
    _this->SelectedItem = EnumNaviSettingItemTOTAL;
    App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

    if ( App != 0 )
    {
      ApplicationApplication_SwitchToHome( App, EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass )->CurrentHome );
    }
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
      {
        if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
            &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
        {
          _this->NaviSettings[ EwCheckIndex( NoOfItems, 7 )] = NaviSettingItem;
          NoOfItems++;
        }
      }
      break;

      case EnumNaviSettingItemSkipNextStop :
      {
        if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
            &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )) 
            && ( EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->ViaPointNum 
            > 0 ))
        {
          _this->NaviSettings[ EwCheckIndex( NoOfItems, 7 )] = NaviSettingItem;
          NoOfItems++;
        }
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

/* Variants derived from the class : 'Navigation::NAV06_NaviSettingMenu' */
EW_DEFINE_CLASS_VARIANTS( NavigationNAV06_NaviSettingMenu )
EW_END_OF_CLASS_VARIANTS( NavigationNAV06_NaviSettingMenu )

/* Virtual Method Table (VMT) for the class : 'Navigation::NAV06_NaviSettingMenu' */
EW_DEFINE_CLASS( NavigationNAV06_NaviSettingMenu, MenuBaseMenuView, HomeSettingUpdateSystemEventHandler, 
                 HomeSettingUpdateSystemEventHandler, HomeSettingUpdateSystemEventHandler, 
                 HomeSettingUpdateSystemEventHandler, SelectedItem, SelectedItem, 
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
EW_END_OF_CLASS( NavigationNAV06_NaviSettingMenu )

/* Initializer for the class 'Navigation::NAV08_NaviChageViewMenu' */
void NavigationNAV08_NaviChageViewMenu__Init( NavigationNAV08_NaviChageViewMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationNAV08_NaviChageViewMenu );

  /* ... then construct all embedded objects */
  CoreTimer__Init( &_this->CheckMarkUpdateTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationNAV08_NaviChageViewMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0002 );
  _this->Super2.SlideOutEffectEnabled = 1;
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 3 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsNAV08_DEFAULT_VIEW ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsNAV08_TURN_BY_TURN ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &StringsNAV08_TURN_LIST ));
  CoreTimer_OnSetPeriod( &_this->CheckMarkUpdateTimer, 450 );
  _this->CheckMarkUpdateTimer.OnTrigger = EwNewSlot( _this, NavigationNAV08_NaviChageViewMenu_OnCheckMarkUpdateSlot );
}

/* Re-Initializer for the class 'Navigation::NAV08_NaviChageViewMenu' */
void NavigationNAV08_NaviChageViewMenu__ReInit( NavigationNAV08_NaviChageViewMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreTimer__ReInit( &_this->CheckMarkUpdateTimer );
}

/* Finalizer method for the class 'Navigation::NAV08_NaviChageViewMenu' */
void NavigationNAV08_NaviChageViewMenu__Done( NavigationNAV08_NaviChageViewMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CoreTimer__Done( &_this->CheckMarkUpdateTimer );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
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
  {
    ItemClass = EW_CLASS( MenuItemCheckMark );
  }

  return ItemClass;
}

/* 'C' function for method : 'Navigation::NAV08_NaviChageViewMenu.LoadItemTitle()' */
XString NavigationNAV08_NaviChageViewMenu_LoadItemTitle( NavigationNAV08_NaviChageViewMenu _this, 
  XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < 3 )
  {
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 3 )];
  }

  return title;
}

/* 'C' function for method : 'Navigation::NAV08_NaviChageViewMenu.OnItemActivate()' */
void NavigationNAV08_NaviChageViewMenu_OnItemActivate( NavigationNAV08_NaviChageViewMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  if ( aMenuItem == 0 )
    ;

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

    default : 
      ;
  }

  MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 2 );
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
    {
      if ( EnumHomeTypeNAVI_DEFAULT_VIEW == EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
          DeviceInterfaceNavigationDeviceClass )->CurrentHome )
      {
        IsChecked = 1;
      }
    }
    break;

    case 1 :
    {
      if ( EnumHomeTypeNAVI_NEXT_TURN == EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
          DeviceInterfaceNavigationDeviceClass )->CurrentHome )
      {
        IsChecked = 1;
      }
    }
    break;

    case 2 :
    {
      if ( EnumHomeTypeNAVI_TURN_BY_TURN == EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
          DeviceInterfaceNavigationDeviceClass )->CurrentHome )
      {
        IsChecked = 1;
      }
    }
    break;

    default : 
      ;
  }

  return IsChecked;
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
    {
      ApplicationApplication_SwitchToHome( App, EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass )->CurrentHome );
    }
  }
}

/* Variants derived from the class : 'Navigation::NAV08_NaviChageViewMenu' */
EW_DEFINE_CLASS_VARIANTS( NavigationNAV08_NaviChageViewMenu )
EW_END_OF_CLASS_VARIANTS( NavigationNAV08_NaviChageViewMenu )

/* Virtual Method Table (VMT) for the class : 'Navigation::NAV08_NaviChageViewMenu' */
EW_DEFINE_CLASS( NavigationNAV08_NaviChageViewMenu, MenuBaseMenuView, CheckMarkUpdateTimer, 
                 CheckMarkUpdateTimer, CheckMarkUpdateTimer, CheckMarkUpdateTimer, 
                 ItemTitleArray, NaviScreenIdx, "Navigation::NAV08_NaviChageViewMenu" )
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
EW_END_OF_CLASS( NavigationNAV08_NaviChageViewMenu )

/* Initializer for the class 'Navigation::NaviCurrentRoad' */
void NavigationNaviCurrentRoad__Init( NavigationNaviCurrentRoad _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationNaviCurrentRoad );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->NaviIconCurRd, &_this->_XObject, 0 );
  ViewsText__Init( &_this->RoadNameText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationNaviCurrentRoad );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0015 );
  CoreRectView__OnSetBounds( &_this->NaviIconCurRd, _Const0016 );
  ViewsImage_OnSetVisible( &_this->NaviIconCurRd, 0 );
  CoreRectView__OnSetBounds( &_this->RoadNameText, _Const0017 );
  ViewsText_OnSetAlignment( &_this->RoadNameText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->RoadNameText, 0 );
  _this->NaviIconBounds = _Const0016;
  CoreGroup__Add( _this, ((CoreView)&_this->NaviIconCurRd ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RoadNameText ), 0 );
  ViewsImage_OnSetBitmap( &_this->NaviIconCurRd, EwLoadResource( &ResourceCurRdIcon, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->RoadNameText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Navigation::NaviCurrentRoad' */
void NavigationNaviCurrentRoad__ReInit( NavigationNaviCurrentRoad _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->NaviIconCurRd );
  ViewsText__ReInit( &_this->RoadNameText );
}

/* Finalizer method for the class 'Navigation::NaviCurrentRoad' */
void NavigationNaviCurrentRoad__Done( NavigationNaviCurrentRoad _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->NaviIconCurRd );
  ViewsText__Done( &_this->RoadNameText );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* 'C' function for method : 'Navigation::NaviCurrentRoad.SetItemBounds()' */
void NavigationNaviCurrentRoad_SetItemBounds( NavigationNaviCurrentRoad _this, XBool 
  IsAnimationStarted )
{
  if ( EwCompRect( _this->RoadNameText.Super1.Bounds, _this->RoadNameTextBounds ))
  {
    CoreRectView__OnSetBounds( &_this->RoadNameText, _this->RoadNameTextBounds );
  }

  if ( EwCompRect( _this->NaviIconCurRd.Super1.Bounds, _this->NaviIconBounds ))
  {
    CoreRectView__OnSetBounds( &_this->NaviIconCurRd, _this->NaviIconBounds );
  }

  if ( !ViewsImage_OnGetVisible( &_this->NaviIconCurRd ))
  {
    ViewsImage_OnSetVisible( &_this->NaviIconCurRd, 1 );
  }

  ViewsText_OnSetEllipsis( &_this->RoadNameText, 0 );

  if ( EwGetRectW( ViewsText_GetContentArea( &_this->RoadNameText )) < EwGetRectW( 
      _this->RoadNameText.Super1.Bounds ))
  {
    XRect NewRoadNameBounds = _Const0013;
    XRect NewCurIcnBounds;
    NewRoadNameBounds.Point1.X = ViewsText_GetContentArea( &_this->RoadNameText ).Point1.X;
    NewRoadNameBounds.Point2.X = ( NewRoadNameBounds.Point1.X + EwGetRectW( ViewsText_GetContentArea( 
    &_this->RoadNameText )));
    NewRoadNameBounds.Point1.Y = _this->RoadNameText.Super1.Bounds.Point1.Y;
    NewRoadNameBounds.Point2.Y = _this->RoadNameText.Super1.Bounds.Point2.Y;
    CoreRectView__OnSetBounds( &_this->RoadNameText, NewRoadNameBounds );
    NewCurIcnBounds = _Const0013;
    NewCurIcnBounds.Point1.X = ( _this->RoadNameText.Super1.Bounds.Point1.X - 24 );
    NewCurIcnBounds.Point2.X = ( NewCurIcnBounds.Point1.X + EwGetRectW( _this->NaviIconCurRd.Super1.Bounds ));
    NewCurIcnBounds.Point1.Y = _this->NaviIconCurRd.Super1.Bounds.Point1.Y;
    NewCurIcnBounds.Point2.Y = _this->NaviIconCurRd.Super1.Bounds.Point2.Y;
    CoreRectView__OnSetBounds( &_this->NaviIconCurRd, NewCurIcnBounds );
  }
  else
  {
    ViewsText_OnSetAlignment( &_this->RoadNameText, ViewsTextAlignmentAlignHorzLeft 
    | ViewsTextAlignmentAlignVertCenter );
    ViewsText_OnSetEllipsis( &_this->RoadNameText, 1 );
  }

  if ( !IsAnimationStarted )
  {
    _this->NaviIconX1Pos = _this->NaviIconCurRd.Super1.Bounds.Point1.X;
  }
}

/* 'C' function for method : 'Navigation::NaviCurrentRoad.OnSetRoadName()' */
void NavigationNaviCurrentRoad_OnSetRoadName( NavigationNaviCurrentRoad _this, XString 
  value )
{
  _this->RoadName = EwShareString( value );
  ViewsText_OnSetString( &_this->RoadNameText, _this->RoadName );

  if ( !EwCompString( _this->RoadNameText.String, 0 ))
  {
    ViewsText_OnSetString( &_this->RoadNameText, EwLoadString( &_Const0018 ));
  }
}

/* 'C' function for method : 'Navigation::NaviCurrentRoad.UpdateItemBounds()' */
void NavigationNaviCurrentRoad_UpdateItemBounds( NavigationNaviCurrentRoad _this, 
  XEnum aAnimationType, XInt32 aNewWidth )
{
  switch ( aAnimationType )
  {
    case EnumNaviAlertAnimationTypeShrink :
      ViewsText_OnSetAlignment( &_this->RoadNameText, ViewsTextAlignmentAlignHorzLeft 
      | ViewsTextAlignmentAlignVertCenter );
    break;

    case EnumNaviAlertAnimationTypeDismiss :
      ViewsText_OnSetAlignment( &_this->RoadNameText, ViewsTextAlignmentAlignHorzCenter 
      | ViewsTextAlignmentAlignVertCenter );
    break;

    default : 
      ;
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
                 NaviIconCurRd, NaviIconCurRd, RoadName, NaviIconBounds, "Navigation::NaviCurrentRoad" )
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
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationNaviAlert );

  /* ... then construct all embedded objects */
  NavigationNaviAlertMessage__Init( &_this->AlertMessage, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->NaviDistBg, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DistUnit, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Distance, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->SuspendTimer, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->NaviEventShrinkEffect, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationNaviAlert );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0019 );
  CoreRectView__OnSetBounds( &_this->AlertMessage, NavigationALERT_MESSAGE_BOUNDS );
  CoreRectView__OnSetBounds( &_this->NaviDistBg, _Const001A );
  ViewsRectangle_OnSetColor( &_this->NaviDistBg, _Const001B );
  CoreRectView__OnSetBounds( &_this->DistUnit, _Const001C );
  ViewsText_OnSetAlignment( &_this->DistUnit, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DistUnit, 0 );
  CoreRectView__OnSetBounds( &_this->Distance, _Const001D );
  ViewsText_OnSetAlignment( &_this->Distance, ViewsTextAlignmentAlignHorzRight | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Distance, 0 );
  CoreTimer_OnSetPeriod( &_this->SuspendTimer, 8000 );
  _this->DistUnitTextArray[ 0 ] = EwShareString( EwLoadString( &_Const001E ));
  _this->DistUnitTextArray[ 1 ] = EwShareString( EwLoadString( &_Const001F ));
  _this->SpeedUnitTextArray[ 0 ] = EwShareString( EwLoadString( &_Const0020 ));
  _this->SpeedUnitTextArray[ 1 ] = EwShareString( EwLoadString( &_Const0021 ));
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->NaviEventShrinkEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->NaviEventShrinkEffect, 
  500 );
  _this->NaviEventShrinkEffect.Value2 = _Const0022;
  _this->NaviEventShrinkEffect.Value1 = _Const0019;
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
}

/* Re-Initializer for the class 'Navigation::NaviAlert' */
void NavigationNaviAlert__ReInit( NavigationNaviAlert _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  NavigationNaviAlertMessage__ReInit( &_this->AlertMessage );
  ViewsRectangle__ReInit( &_this->NaviDistBg );
  ViewsText__ReInit( &_this->DistUnit );
  ViewsText__ReInit( &_this->Distance );
  CoreTimer__ReInit( &_this->SuspendTimer );
  EffectsRectEffect__ReInit( &_this->NaviEventShrinkEffect );
}

/* Finalizer method for the class 'Navigation::NaviAlert' */
void NavigationNaviAlert__Done( NavigationNaviAlert _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  NavigationNaviAlertMessage__Done( &_this->AlertMessage );
  ViewsRectangle__Done( &_this->NaviDistBg );
  ViewsText__Done( &_this->DistUnit );
  ViewsText__Done( &_this->Distance );
  CoreTimer__Done( &_this->SuspendTimer );
  EffectsRectEffect__Done( &_this->NaviEventShrinkEffect );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
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
      EwSignal( _this->DismissAlertSignal, ((XObject)_this ));
    }
    else
      ;
}

/* 'C' function for method : 'Navigation::NaviAlert.SetAlert()' */
void NavigationNaviAlert_SetAlert( NavigationNaviAlert _this, XEnum aNaviEventType, 
  XEnum aNaviCameraType, XString aNaviEventSpeed, XString aNaviEventDist )
{
  XInt32 i;
  XInt32 idx;

  switch ( aNaviEventType )
  {
    case EnumNaviAlertTypeSCHOOL :
    {
      if ( ViewsText_OnGetVisible( &_this->AlertMessage.NaviSpeed ))
      {
        ViewsText_OnSetVisible( &_this->AlertMessage.NaviSpeed, 0 );
      }

      if ( ViewsText_OnGetVisible( &_this->AlertMessage.NaviSpeedUnit ))
      {
        ViewsText_OnSetVisible( &_this->AlertMessage.NaviSpeedUnit, 0 );
      }

      ViewsImage_OnSetBitmap( &_this->AlertMessage.NaviAlertIcon, EwLoadResource( 
      &ResourceSafeCamSchoolZone, ResourcesBitmap ));
      ViewsText_OnSetString( &_this->AlertMessage.EventType, EwLoadString( &StringsNAV01_SCHOOL_ZONE ));
      ViewsRectangle_OnSetColor( &_this->AlertMessage.NaviEventBg, _Const0023 );
      ViewsRectangle_OnSetColor( &_this->NaviDistBg, _Const0023 );
    }
    break;

    case EnumNaviAlertTypeCAMERA :
    {
      if ( !ViewsText_OnGetVisible( &_this->AlertMessage.NaviSpeed ))
      {
        ViewsText_OnSetVisible( &_this->AlertMessage.NaviSpeed, 1 );
      }

      if ( !ViewsText_OnGetVisible( &_this->AlertMessage.NaviSpeedUnit ))
      {
        ViewsText_OnSetVisible( &_this->AlertMessage.NaviSpeedUnit, 1 );
      }

      NavigationNaviAlert_SetCamera( _this, aNaviCameraType );
      ViewsRectangle_OnSetColor( &_this->AlertMessage.NaviEventBg, _Const0024 );
      ViewsRectangle_OnSetColor( &_this->NaviDistBg, _Const0024 );
    }
    break;

    default : 
      ;
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
      ViewsImage_OnSetBitmap( &_this->AlertMessage.NaviAlertIcon, EwLoadResource( 
      &ResourceSafeCamEU, ResourcesBitmap ));
      ViewsText_OnSetString( &_this->AlertMessage.EventType, EwLoadString( &StringsNAV01_CHECK_FIXED ));
    }
    break;

    case EnumNaviCameraTypeCHECK_TEMPORARY :
    {
      ViewsImage_OnSetBitmap( &_this->AlertMessage.NaviAlertIcon, EwLoadResource( 
      &ResourceSafeCamTempEU, ResourcesBitmap ));
      ViewsText_OnSetString( &_this->AlertMessage.EventType, EwLoadString( &StringsNAV01_CHECK_TEMPORARY ));
    }
    break;

    case EnumNaviCameraTypeMOBILE :
    {
      ViewsImage_OnSetBitmap( &_this->AlertMessage.NaviAlertIcon, EwLoadResource( 
      &ResourceSafeCamMobileEU, ResourcesBitmap ));
      ViewsText_OnSetString( &_this->AlertMessage.EventType, EwLoadString( &StringsNAV01_MOBILE ));
    }
    break;

    case EnumNaviCameraTypeAVERAGE :
    {
      ViewsImage_OnSetBitmap( &_this->AlertMessage.NaviAlertIcon, EwLoadResource( 
      &ResourceSafeAvrgCamEU, ResourcesBitmap ));
      ViewsText_OnSetString( &_this->AlertMessage.EventType, EwLoadString( &StringsNAV01_AVERAGE ));
    }
    break;

    case EnumNaviCameraTypeVARIABLE :
    {
      ViewsImage_OnSetBitmap( &_this->AlertMessage.NaviAlertIcon, EwLoadResource( 
      &ResourceSafeCamVariableEU, ResourcesBitmap ));
      ViewsText_OnSetString( &_this->AlertMessage.EventType, EwLoadString( &StringsNAV01_VARIABLE ));
    }
    break;

    case EnumNaviCameraTypeRED_LIGHT :
    {
      ViewsImage_OnSetBitmap( &_this->AlertMessage.NaviAlertIcon, EwLoadResource( 
      &ResourceSafeCamRedLight, ResourcesBitmap ));
      ViewsText_OnSetString( &_this->AlertMessage.EventType, EwLoadString( &StringsNAV01_RED_LIGHT ));
    }
    break;

    case EnumNaviCameraTypeUSER :
    {
      ViewsImage_OnSetBitmap( &_this->AlertMessage.NaviAlertIcon, EwLoadResource( 
      &ResourceSafeCamRealTimeEU, ResourcesBitmap ));
      ViewsText_OnSetString( &_this->AlertMessage.EventType, EwLoadString( &StringsNAV01_USER ));
    }
    break;

    case EnumNaviCameraTypeMOBILE_ZONE :
    {
      ViewsImage_OnSetBitmap( &_this->AlertMessage.NaviAlertIcon, EwLoadResource( 
      &ResourceSafeCamLifemobileEU, ResourcesBitmap ));
      ViewsText_OnSetString( &_this->AlertMessage.EventType, EwLoadString( &StringsNAV01_MOBILE_ZONE ));
    }
    break;

    case EnumNaviCameraTypeDANGEROUS_ZONE :
    case EnumNaviCameraTypeDANGEROUS_POINT :
    {
      ViewsImage_OnSetBitmap( &_this->AlertMessage.NaviAlertIcon, EwLoadResource( 
      &ResourceSafeCamRiskZone, ResourcesBitmap ));
      ViewsText_OnSetString( &_this->AlertMessage.EventType, EwLoadString( &StringsNAV01_DANGEROUS_ZONE ));
    }
    break;

    case EnumNaviCameraTypeRISK_ZONE :
    {
      ViewsImage_OnSetBitmap( &_this->AlertMessage.NaviAlertIcon, EwLoadResource( 
      &ResourceSafeCamRiskZone, ResourcesBitmap ));
      ViewsText_OnSetString( &_this->AlertMessage.EventType, EwLoadString( &StringsNAV01_RISK_ZONE ));
    }
    break;

    case EnumNaviCameraTypeUNKNOWN :
    {
      ViewsImage_OnSetBitmap( &_this->AlertMessage.NaviAlertIcon, EwLoadResource( 
      &ResourceSafeCamMobileNA, ResourcesBitmap ));
      ViewsText_OnSetString( &_this->AlertMessage.EventType, EwLoadString( &StringsNAV01_UNKNOWN ));
    }
    break;

    default : 
      ;
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
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationNaviAlertMessage );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->NaviEventBg, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->NaviAlertIcon, &_this->_XObject, 0 );
  ViewsText__Init( &_this->EventType, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NaviSpeed, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NaviSpeedUnit, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationNaviAlertMessage );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0025 );
  CoreRectView__OnSetBounds( &_this->NaviEventBg, _Const0025 );
  ViewsRectangle_OnSetColor( &_this->NaviEventBg, _Const001B );
  ViewsRectangle_OnSetVisible( &_this->NaviEventBg, 1 );
  CoreRectView__OnSetBounds( &_this->NaviAlertIcon, _Const0026 );
  CoreRectView__OnSetBounds( &_this->EventType, _Const0027 );
  ViewsText_OnSetAlignment( &_this->EventType, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->EventType, 0 );
  CoreRectView__OnSetBounds( &_this->NaviSpeed, _Const0028 );
  ViewsText_OnSetString( &_this->NaviSpeed, 0 );
  ViewsText_OnSetVisible( &_this->NaviSpeed, 0 );
  CoreRectView__OnSetBounds( &_this->NaviSpeedUnit, _Const0029 );
  ViewsText_OnSetString( &_this->NaviSpeedUnit, 0 );
  ViewsText_OnSetVisible( &_this->NaviSpeedUnit, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviEventBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviAlertIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->EventType ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviSpeed ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviSpeedUnit ), 0 );
  ViewsImage_OnSetBitmap( &_this->NaviAlertIcon, EwLoadResource( &ResourceSafeCamTempEU, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->EventType, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
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
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->NaviEventBg );
  ViewsImage__ReInit( &_this->NaviAlertIcon );
  ViewsText__ReInit( &_this->EventType );
  ViewsText__ReInit( &_this->NaviSpeed );
  ViewsText__ReInit( &_this->NaviSpeedUnit );
}

/* Finalizer method for the class 'Navigation::NaviAlertMessage' */
void NavigationNaviAlertMessage__Done( NavigationNaviAlertMessage _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->NaviEventBg );
  ViewsImage__Done( &_this->NaviAlertIcon );
  ViewsText__Done( &_this->EventType );
  ViewsText__Done( &_this->NaviSpeed );
  ViewsText__Done( &_this->NaviSpeedUnit );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* Variants derived from the class : 'Navigation::NaviAlertMessage' */
EW_DEFINE_CLASS_VARIANTS( NavigationNaviAlertMessage )
EW_END_OF_CLASS_VARIANTS( NavigationNaviAlertMessage )

/* Virtual Method Table (VMT) for the class : 'Navigation::NaviAlertMessage' */
EW_DEFINE_CLASS( NavigationNaviAlertMessage, CoreGroup, NaviEventBg, NaviEventBg, 
                 NaviEventBg, NaviEventBg, _None, _None, "Navigation::NaviAlertMessage" )
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
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationNaviETA );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->NaviIconFlag, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TimeText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->AmPmText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationNaviETA );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const002A );
  CoreRectView__OnSetBounds( &_this->NaviIconFlag, _Const002B );
  ViewsImage_OnSetVisible( &_this->NaviIconFlag, 1 );
  CoreRectView__OnSetBounds( &_this->TimeText, _Const002C );
  ViewsText_OnSetAlignment( &_this->TimeText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TimeText, 0 );
  ViewsText_OnSetVisible( &_this->TimeText, 0 );
  CoreRectView__OnSetBounds( &_this->AmPmText, _Const002D );
  ViewsText_OnSetAlignment( &_this->AmPmText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->AmPmText, 0 );
  ViewsText_OnSetVisible( &_this->AmPmText, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviIconFlag ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->AmPmText ), 0 );
  ViewsImage_OnSetBitmap( &_this->NaviIconFlag, EwLoadResource( &ResourceFlagIcon, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->TimeText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->AmPmText, EwLoadResource( &FontsNotoSansMedium16pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Navigation::NaviETA' */
void NavigationNaviETA__ReInit( NavigationNaviETA _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->NaviIconFlag );
  ViewsText__ReInit( &_this->TimeText );
  ViewsText__ReInit( &_this->AmPmText );
}

/* Finalizer method for the class 'Navigation::NaviETA' */
void NavigationNaviETA__Done( NavigationNaviETA _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->NaviIconFlag );
  ViewsText__Done( &_this->TimeText );
  ViewsText__Done( &_this->AmPmText );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* 'C' function for method : 'Navigation::NaviETA.OnSetETA()' */
void NavigationNaviETA_OnSetETA( NavigationNaviETA _this, XInt32 value )
{
  _this->ETA = value;
  ViewsText_OnSetVisible( &_this->TimeText, 1 );

  if (( value > 0 ) && DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( 
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
  {
    NavigationNaviETA_FormatTime( _this );
    ViewsText_OnSetAlignment( &_this->TimeText, ViewsTextAlignmentAlignHorzRight 
    | ViewsTextAlignmentAlignVertCenter );
    CoreRectView__OnSetBounds( &_this->TimeText, NavigationTIMETEXT_W_NAVI_BOUNDS );
    CoreRectView__OnSetBounds( &_this->NaviIconFlag, NavigationNAVIFLAG_W_NAVI_BOUNDS );
    ViewsText_OnSetVisible( &_this->AmPmText, 1 );
  }
  else
  {
    ViewsText_OnSetString( &_this->TimeText, EwLoadString( &_Const002E ));
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
    {
      ViewsText_OnSetString( &_this->AmPmText, EwLoadString( &_Const002F ));
    }
    else
    {
      ViewsText_OnSetString( &_this->AmPmText, EwLoadString( &_Const0030 ));

      if ( hour > 12 )
      {
        hour = hour - 12;
      }
    }

    if ( min < 10 )
    {
      eta = EwConcatString( EwConcatString( EwNewStringInt( hour, 0, 10 ), EwLoadString( 
      &_Const0031 )), EwNewStringInt( min, 0, 10 ));
    }
    else
    {
      eta = EwConcatString( EwConcatString( EwNewStringInt( hour, 0, 10 ), EwLoadString( 
      &_Const0032 )), EwNewStringInt( min, 0, 10 ));
    }
  }
  else
  {
    if ( min < 10 )
    {
      eta = EwConcatString( EwLoadString( &_Const0033 ), EwNewStringInt( min, 0, 
      10 ));
    }
    else
    {
      eta = EwConcatString( EwLoadString( &_Const0034 ), EwNewStringInt( min, 0, 
      10 ));
    }

    ViewsText_OnSetString( &_this->AmPmText, EwLoadString( &_Const002F ));
  }

  ViewsText_OnSetString( &_this->TimeText, eta );
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
  HomeBaseHome__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationNAV05_TBTView );

  /* ... then construct all embedded objects */
  ViewsWallpaper__Init( &_this->NaviTBTViewBg, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->ArrivalBg, &_this->_XObject, 0 );
  NavigationNaviETA__Init( &_this->ETAComponent, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->RoadNameBg, &_this->_XObject, 0 );
  NavigationNaviCurrentRoad__Init( &_this->CurrentRoadComponent, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->SpeedLimitIcon, &_this->_XObject, 0 );
  ViewsText__Init( &_this->SpeedLimitText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NextTurnDist, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NextTurnDistUnit, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NextTurnDescription, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->NextTurnIcon, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ETAUpdateEventHandler, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->CurRdUpdateEventHandler, &_this->_XObject, 0 );
  ViewsText__Init( &_this->RecalculateMessage, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ActiveTbtItemUpdateEventHandler, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->SpeedLimitUpdateEventHandler, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->SpeedLimitFlickeringTimer, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->RouteCalProgressUpdateEventHandler, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NavigatingStatusUpdateEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationNAV05_TBTView );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0002 );
  _this->Super1.HomeType = EnumHomeTypeNAVI_NEXT_TURN;
  CoreRectView__OnSetBounds( &_this->NaviTBTViewBg, _Const0035 );
  CoreRectView__OnSetBounds( &_this->ArrivalBg, _Const0003 );
  ViewsRectangle_OnSetColor( &_this->ArrivalBg, _Const0004 );
  ViewsRectangle_OnSetVisible( &_this->ArrivalBg, 1 );
  CoreRectView__OnSetBounds( &_this->ETAComponent, _Const0005 );
  CoreRectView__OnSetBounds( &_this->RoadNameBg, _Const0006 );
  ViewsRectangle_OnSetColor( &_this->RoadNameBg, _Const0007 );
  CoreRectView__OnSetBounds( &_this->CurrentRoadComponent, _Const0014 );
  CoreRectView__OnSetBounds( &_this->SpeedLimitIcon, _Const000B );
  ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 0 );
  CoreRectView__OnSetBounds( &_this->SpeedLimitText, _Const000C );
  ViewsText_OnSetString( &_this->SpeedLimitText, 0 );
  ViewsText_OnSetColor( &_this->SpeedLimitText, _Const0001 );
  ViewsText_OnSetVisible( &_this->SpeedLimitText, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnDist, _Const0036 );
  ViewsText_OnSetString( &_this->NextTurnDist, 0 );
  ViewsText_OnSetVisible( &_this->NextTurnDist, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnDistUnit, _Const0037 );
  ViewsText_OnSetString( &_this->NextTurnDistUnit, 0 );
  ViewsText_OnSetVisible( &_this->NextTurnDistUnit, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnDescription, _Const0038 );
  ViewsText_OnSetEllipsis( &_this->NextTurnDescription, 1 );
  ViewsText_OnSetWrapText( &_this->NextTurnDescription, 1 );
  ViewsText_OnSetAlignment( &_this->NextTurnDescription, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->NextTurnDescription, 0 );
  ViewsText_OnSetColor( &_this->NextTurnDescription, _Const0039 );
  CoreRectView__OnSetBounds( &_this->NextTurnIcon, _Const003A );
  ViewsImage_OnSetVisible( &_this->NextTurnIcon, 0 );
  CoreRectView__OnSetBounds( &_this->RecalculateMessage, _Const003B );
  ViewsText_OnSetString( &_this->RecalculateMessage, 0 );
  ViewsText_OnSetColor( &_this->RecalculateMessage, _Const0039 );
  ViewsText_OnSetVisible( &_this->RecalculateMessage, 0 );
  CoreTimer_OnSetPeriod( &_this->SpeedLimitFlickeringTimer, 300 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviTBTViewBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ArrivalBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ETAComponent ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RoadNameBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CurrentRoadComponent ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SpeedLimitIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SpeedLimitText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTurnDist ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTurnDistUnit ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTurnDescription ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTurnIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RecalculateMessage ), 0 );
  ViewsWallpaper_OnSetBitmap( &_this->NaviTBTViewBg, EwLoadResource( &ResourceNaviTBTViewBg, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->SpeedLimitIcon, EwLoadResource( &ResourceSpeedLimitIcon, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->SpeedLimitText, EwLoadResource( &FontsNotoSansBold24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->NextTurnDist, EwLoadResource( &FontsNotoSansBold38pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->NextTurnDistUnit, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->NextTurnDescription, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->ETAUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV05_TBTView_OnETAUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->ETAUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->ETAUpdateEvent );
  _this->CurRdUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV05_TBTView_OnCurRdUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->CurRdUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->CurRdUpdateEvent );
  ViewsText_OnSetFont( &_this->RecalculateMessage, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->ActiveTbtItemUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV05_TBTView_OnActiveTbtItemUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->ActiveTbtItemUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->ActiveTbtItemUpdateEvent );
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

  /* Call the user defined constructor */
  NavigationNAV05_TBTView_Init( _this, aArg );
}

/* Re-Initializer for the class 'Navigation::NAV05_TBTView' */
void NavigationNAV05_TBTView__ReInit( NavigationNAV05_TBTView _this )
{
  /* At first re-initialize the super class ... */
  HomeBaseHome__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsWallpaper__ReInit( &_this->NaviTBTViewBg );
  ViewsRectangle__ReInit( &_this->ArrivalBg );
  NavigationNaviETA__ReInit( &_this->ETAComponent );
  ViewsRectangle__ReInit( &_this->RoadNameBg );
  NavigationNaviCurrentRoad__ReInit( &_this->CurrentRoadComponent );
  ViewsImage__ReInit( &_this->SpeedLimitIcon );
  ViewsText__ReInit( &_this->SpeedLimitText );
  ViewsText__ReInit( &_this->NextTurnDist );
  ViewsText__ReInit( &_this->NextTurnDistUnit );
  ViewsText__ReInit( &_this->NextTurnDescription );
  ViewsImage__ReInit( &_this->NextTurnIcon );
  CoreSystemEventHandler__ReInit( &_this->ETAUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->CurRdUpdateEventHandler );
  ViewsText__ReInit( &_this->RecalculateMessage );
  CoreSystemEventHandler__ReInit( &_this->ActiveTbtItemUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->SpeedLimitUpdateEventHandler );
  CoreTimer__ReInit( &_this->SpeedLimitFlickeringTimer );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
  CoreSystemEventHandler__ReInit( &_this->RouteCalProgressUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->NavigatingStatusUpdateEventHandler );
}

/* Finalizer method for the class 'Navigation::NAV05_TBTView' */
void NavigationNAV05_TBTView__Done( NavigationNAV05_TBTView _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  ViewsWallpaper__Done( &_this->NaviTBTViewBg );
  ViewsRectangle__Done( &_this->ArrivalBg );
  NavigationNaviETA__Done( &_this->ETAComponent );
  ViewsRectangle__Done( &_this->RoadNameBg );
  NavigationNaviCurrentRoad__Done( &_this->CurrentRoadComponent );
  ViewsImage__Done( &_this->SpeedLimitIcon );
  ViewsText__Done( &_this->SpeedLimitText );
  ViewsText__Done( &_this->NextTurnDist );
  ViewsText__Done( &_this->NextTurnDistUnit );
  ViewsText__Done( &_this->NextTurnDescription );
  ViewsImage__Done( &_this->NextTurnIcon );
  CoreSystemEventHandler__Done( &_this->ETAUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->CurRdUpdateEventHandler );
  ViewsText__Done( &_this->RecalculateMessage );
  CoreSystemEventHandler__Done( &_this->ActiveTbtItemUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->SpeedLimitUpdateEventHandler );
  CoreTimer__Done( &_this->SpeedLimitFlickeringTimer );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );
  CoreSystemEventHandler__Done( &_this->RouteCalProgressUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->NavigatingStatusUpdateEventHandler );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void NavigationNAV05_TBTView_Init( NavigationNAV05_TBTView _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnNavigatingStatusUpdateSlot ), 
    ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnActiveTbtItemUpdateSlot ), 
    ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnSpeedLimitUpdateSlot ), 
    ((XObject)_this ));
}

/* 'C' function for method : 'Navigation::NAV05_TBTView.OnLongEnterKeyActivated()' */
void NavigationNAV05_TBTView_OnLongEnterKeyActivated( NavigationNAV05_TBTView _this )
{
  if ( 1 == _this->Super3.KeyHandler.RepetitionCount )
  {
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( NavigationNAV06_NaviSettingMenu, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
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
  NavigationNAV05_TBTView_SetCurrentRoadBounds( _this );
  NavigationNaviCurrentRoad_OnSetRoadName( &_this->CurrentRoadComponent, NaviData->CurrentRoad );
  NavigationNaviCurrentRoad_SetItemBounds( &_this->CurrentRoadComponent, 0 );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV05_TBTView_OnActiveTbtItemUpdateSlot( NavigationNAV05_TBTView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
  {
    DeviceInterfaceNaviTbtDataClass NaviTbtData = DeviceInterfaceNavigationDeviceClass_GetNaviTbtData( 
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->ActiveTbtItemIdx );
    NavigationNAV05_TBTView_ShowNextTurnIcon( _this, NaviTbtData->IconIdx );

    if ( !ViewsText_OnGetVisible( &_this->NextTurnDist ))
    {
      ViewsText_OnSetVisible( &_this->NextTurnDist, 1 );
    }

    if ( !ViewsText_OnGetVisible( &_this->NextTurnDistUnit ))
    {
      ViewsText_OnSetVisible( &_this->NextTurnDistUnit, 1 );
    }

    ViewsText_OnSetString( &_this->NextTurnDistUnit, NaviTbtData->DistUnit );
    ViewsText_OnSetString( &_this->NextTurnDist, EwNewStringInt( NaviTbtData->Distance, 
    0, 10 ));
    ViewsText_OnSetString( &_this->NextTurnDescription, NaviTbtData->TbtDescription );
  }
}

/* 'C' function for method : 'Navigation::NAV05_TBTView.ShowNextTurnIcon()' */
void NavigationNAV05_TBTView_ShowNextTurnIcon( NavigationNAV05_TBTView _this, XInt32 
  index )
{
  XEnum NaviTurnStatus;

  if ( !ViewsImage_OnGetVisible( &_this->NextTurnIcon ))
  {
    ViewsImage_OnSetVisible( &_this->NextTurnIcon, 1 );
  }

  NaviTurnStatus = (XEnum)index;

  switch ( NaviTurnStatus )
  {
    case EnumNaviTurnStatusTypeCONTINUE_LEFT :
      ViewsImage_OnSetBitmap( &_this->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwContinueIrgTbt, 
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

    default : 
      ;
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
    {
      CoreTimer_OnSetEnabled( &_this->SpeedLimitFlickeringTimer, 1 );
    }
    else
    {
      CoreTimer_OnSetEnabled( &_this->SpeedLimitFlickeringTimer, 0 );
    }
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
  {
    EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnSpeedLimitUpdateSlot ), 
      ((XObject)_this ));
  }
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
  if ( aNewRouteCalProgress < 100 )
  {
    ViewsImage_OnSetVisible( &_this->NextTurnIcon, 0 );
    ViewsText_OnSetVisible( &_this->NextTurnDescription, 0 );
    ViewsText_OnSetVisible( &_this->NextTurnDistUnit, 0 );
    ViewsText_OnSetVisible( &_this->NextTurnDist, 0 );
    ViewsText_OnSetVisible( &_this->SpeedLimitText, 0 );
    ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 0 );
    NavigationNaviETA_OnSetETA( &_this->ETAComponent, 0 );
    ViewsText_OnSetString( &_this->RecalculateMessage, EwConcatString( EwConcatString( 
    EwLoadString( &_Const003C ), EwNewStringInt( aNewRouteCalProgress, 0, 10 )), 
    EwLoadString( &_Const003D )));
    ViewsText_OnSetVisible( &_this->RecalculateMessage, 1 );
  }
  else
    if ( aNewRouteCalProgress == 100 )
    {
      ViewsImage_OnSetVisible( &_this->NextTurnIcon, 1 );
      ViewsText_OnSetVisible( &_this->NextTurnDescription, 1 );
      ViewsText_OnSetVisible( &_this->NextTurnDistUnit, 1 );
      ViewsText_OnSetVisible( &_this->NextTurnDist, 1 );
      ViewsText_OnSetVisible( &_this->SpeedLimitText, 1 );
      ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 1 );
      ViewsText_OnSetVisible( &_this->RecalculateMessage, 0 );
      EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnETAUpdateSlot ), ((XObject)_this ));
    }
    else
      ;
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV05_TBTView_OnNavigatingStatusUpdateSlot( NavigationNAV05_TBTView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnCurRdUpdateSlot ), ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnETAUpdateSlot ), ((XObject)_this ));
}

/* 'C' function for method : 'Navigation::NAV05_TBTView.SetCurrentRoadBounds()' */
void NavigationNAV05_TBTView_SetCurrentRoadBounds( NavigationNAV05_TBTView _this )
{
  if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
  {
    CoreRectView__OnSetBounds( &_this->RoadNameBg, NavigationROAD_BG_W_NAVI_BOUNDS );
    CoreRectView__OnSetBounds( &_this->CurrentRoadComponent, NavigationCURRENT_ROAD_W_NAVI_BOUNDS );
    _this->CurrentRoadComponent.RoadNameTextBounds = NavigationROADNAME_W_NAVI_BOUNDS;
  }
  else
  {
    CoreRectView__OnSetBounds( &_this->RoadNameBg, NavigationROAD_BG_WO_NAVI_BOUNDS );
    CoreRectView__OnSetBounds( &_this->CurrentRoadComponent, NavigationCURRENT_ROAD_WO_NAVI_BOUNDS );
    _this->CurrentRoadComponent.RoadNameTextBounds = NavigationROADNAME_WO_NAVI_BOUNDS;
  }
}

/* Variants derived from the class : 'Navigation::NAV05_TBTView' */
EW_DEFINE_CLASS_VARIANTS( NavigationNAV05_TBTView )
EW_END_OF_CLASS_VARIANTS( NavigationNAV05_TBTView )

/* Virtual Method Table (VMT) for the class : 'Navigation::NAV05_TBTView' */
EW_DEFINE_CLASS( NavigationNAV05_TBTView, HomeBaseHome, NaviTBTViewBg, NaviTBTViewBg, 
                 NaviTBTViewBg, NaviTBTViewBg, _None, _None, "Navigation::NAV05_TBTView" )
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
EW_END_OF_CLASS( NavigationNAV05_TBTView )

/* Initializer for the class 'Navigation::NAV03_TBTListView' */
void NavigationNAV03_TBTListView__Init( NavigationNAV03_TBTListView _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  HomeBaseHome__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationNAV03_TBTListView );

  /* ... then construct all embedded objects */
  NavigationTbtListMenu__Init( &_this->TbtList, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->TbtListUpdateEventHandler, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->ActiveTbtItemUpdateEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationNAV03_TBTListView );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Super2.BlackBG, _Const0000 );
  _this->Super1.HomeType = EnumHomeTypeNAVI_TURN_BY_TURN;
  CoreRectView__OnSetBounds( &_this->TbtList, _Const003E );
  _this->TbtList.Super2.PassHomeKey = 1;
  _this->TbtList.Super2.PassEnterKey = 1;
  MenuVerticalMenu_OnSetArrowScrollBarVisible((MenuVerticalMenu)&_this->TbtList, 
  1 );
  CoreGroup__Add( _this, ((CoreView)&_this->TbtList ), 0 );
  _this->TbtListUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV03_TBTListView_OnTbtListUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->TbtListUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->TbtListUpdateEvent );
  _this->ActiveTbtItemUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationNAV03_TBTListView_OnActiveTbtItemUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->ActiveTbtItemUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->ActiveTbtItemUpdateEvent );

  /* Call the user defined constructor */
  NavigationNAV03_TBTListView_Init( _this, aArg );
}

/* Re-Initializer for the class 'Navigation::NAV03_TBTListView' */
void NavigationNAV03_TBTListView__ReInit( NavigationNAV03_TBTListView _this )
{
  /* At first re-initialize the super class ... */
  HomeBaseHome__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  NavigationTbtListMenu__ReInit( &_this->TbtList );
  CoreSystemEventHandler__ReInit( &_this->TbtListUpdateEventHandler );
  CoreSystemEventHandler__ReInit( &_this->ActiveTbtItemUpdateEventHandler );
}

/* Finalizer method for the class 'Navigation::NAV03_TBTListView' */
void NavigationNAV03_TBTListView__Done( NavigationNAV03_TBTListView _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  NavigationTbtListMenu__Done( &_this->TbtList );
  CoreSystemEventHandler__Done( &_this->TbtListUpdateEventHandler );
  CoreSystemEventHandler__Done( &_this->ActiveTbtItemUpdateEventHandler );

  /* Don't forget to deinitialize the super class ... */
  HomeBaseHome__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void NavigationNAV03_TBTListView_Init( NavigationNAV03_TBTListView _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const003F ));
  EwSignal( EwNewSlot( _this, NavigationNAV03_TBTListView_OnTbtListUpdateSlot ), 
    ((XObject)_this ));
}

/* 'C' function for method : 'Navigation::NAV03_TBTListView.OnLongEnterKeyActivated()' */
void NavigationNAV03_TBTListView_OnLongEnterKeyActivated( NavigationNAV03_TBTListView _this )
{
  if ( 1 == _this->Super3.KeyHandler.RepetitionCount )
  {
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( NavigationNAV06_NaviSettingMenu, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV03_TBTListView_OnTbtListUpdateSlot( NavigationNAV03_TBTListView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  MenuVerticalMenu_OnSetNoOfItems((MenuVerticalMenu)&_this->TbtList, EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->TbtListSize );
  _this->TbtList.ActiveTbtIdx = EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
  DeviceInterfaceNavigationDeviceClass )->ActiveTbtItemIdx;
  MenuVerticalMenu_InvalidateItems((MenuVerticalMenu)&_this->TbtList, 0, EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->TbtListSize 
  - 1 );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV03_TBTListView_OnActiveTbtItemUpdateSlot( NavigationNAV03_TBTListView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->TbtList.ActiveTbtIdx = EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
  DeviceInterfaceNavigationDeviceClass )->ActiveTbtItemIdx;
  MenuVerticalMenu_InvalidateItems((MenuVerticalMenu)&_this->TbtList, _this->TbtList.ActiveTbtIdx, 
  _this->TbtList.ActiveTbtIdx );
}

/* Variants derived from the class : 'Navigation::NAV03_TBTListView' */
EW_DEFINE_CLASS_VARIANTS( NavigationNAV03_TBTListView )
EW_END_OF_CLASS_VARIANTS( NavigationNAV03_TBTListView )

/* Virtual Method Table (VMT) for the class : 'Navigation::NAV03_TBTListView' */
EW_DEFINE_CLASS( NavigationNAV03_TBTListView, HomeBaseHome, TbtList, TbtList, TbtList, 
                 TbtList, _None, _None, "Navigation::NAV03_TBTListView" )
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
  NavigationNAV03_TBTListView_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( NavigationNAV03_TBTListView )

/* Initializer for the class 'Navigation::TbtInfoItem' */
void NavigationTbtInfoItem__Init( NavigationTbtInfoItem _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationTbtInfoItem );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->TbtItemBg, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->NextTurnIcon, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NextTurnDist, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NextTurnDistUnit, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NextTurnDescription, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ListDivider, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationTbtInfoItem );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0040 );
  CoreRectView__OnSetBounds( &_this->TbtItemBg, _Const0041 );
  ViewsRectangle_OnSetColor( &_this->TbtItemBg, _Const0042 );
  ViewsRectangle_OnSetVisible( &_this->TbtItemBg, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnIcon, _Const0043 );
  CoreRectView__OnSetBounds( &_this->NextTurnDist, _Const0044 );
  ViewsText_OnSetString( &_this->NextTurnDist, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnDistUnit, _Const0045 );
  ViewsText_OnSetString( &_this->NextTurnDistUnit, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnDescription, _Const0046 );
  ViewsText_OnSetEllipsis( &_this->NextTurnDescription, 1 );
  ViewsText_OnSetWrapText( &_this->NextTurnDescription, 1 );
  ViewsText_OnSetAlignment( &_this->NextTurnDescription, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->NextTurnDescription, 0 );
  ViewsText_OnSetColor( &_this->NextTurnDescription, _Const0047 );
  CoreRectView__OnSetBounds( &_this->ListDivider, _Const0048 );
  ViewsImage_OnSetAlignment( &_this->ListDivider, ViewsImageAlignmentScaleToFit );
  CoreGroup__Add( _this, ((CoreView)&_this->TbtItemBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTurnIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTurnDist ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTurnDistUnit ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTurnDescription ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ListDivider ), 0 );
  ViewsText_OnSetFont( &_this->NextTurnDist, EwLoadResource( &FontsNotoSansBold24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->NextTurnDistUnit, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->NextTurnDescription, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->ListDivider, EwLoadResource( &ResourceListDivider3, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'Navigation::TbtInfoItem' */
void NavigationTbtInfoItem__ReInit( NavigationTbtInfoItem _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->TbtItemBg );
  ViewsImage__ReInit( &_this->NextTurnIcon );
  ViewsText__ReInit( &_this->NextTurnDist );
  ViewsText__ReInit( &_this->NextTurnDistUnit );
  ViewsText__ReInit( &_this->NextTurnDescription );
  ViewsImage__ReInit( &_this->ListDivider );
}

/* Finalizer method for the class 'Navigation::TbtInfoItem' */
void NavigationTbtInfoItem__Done( NavigationTbtInfoItem _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->TbtItemBg );
  ViewsImage__Done( &_this->NextTurnIcon );
  ViewsText__Done( &_this->NextTurnDist );
  ViewsText__Done( &_this->NextTurnDistUnit );
  ViewsText__Done( &_this->NextTurnDescription );
  ViewsImage__Done( &_this->ListDivider );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* Variants derived from the class : 'Navigation::TbtInfoItem' */
EW_DEFINE_CLASS_VARIANTS( NavigationTbtInfoItem )
EW_END_OF_CLASS_VARIANTS( NavigationTbtInfoItem )

/* Virtual Method Table (VMT) for the class : 'Navigation::TbtInfoItem' */
EW_DEFINE_CLASS( NavigationTbtInfoItem, CoreGroup, TbtItemBg, TbtItemBg, TbtItemBg, 
                 TbtItemBg, _None, _None, "Navigation::TbtInfoItem" )
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
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
EW_END_OF_CLASS( NavigationTbtInfoItem )

/* Initializer for the class 'Navigation::TbtListMenu' */
void NavigationTbtListMenu__Init( NavigationTbtListMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuVerticalMenu__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationTbtListMenu );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationTbtListMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0049 );
  CoreVerticalList_OnSetItemClass( &_this->Super1.MenuList, EW_CLASS( NavigationTbtInfoItem ));
}

/* Re-Initializer for the class 'Navigation::TbtListMenu' */
void NavigationTbtListMenu__ReInit( NavigationTbtListMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuVerticalMenu__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Navigation::TbtListMenu' */
void NavigationTbtListMenu__Done( NavigationTbtListMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuVerticalMenu );

  /* Don't forget to deinitialize the super class ... */
  MenuVerticalMenu__Done( &_this->_Super );
}

/* 'C' function for method : 'Navigation::TbtListMenu.OnShortDownKeyActivated()' */
void NavigationTbtListMenu_OnShortDownKeyActivated( NavigationTbtListMenu _this )
{
  XInt32 NextItemIdx = _this->Super1.MenuList.SelectedItem + 1;

  if ( NextItemIdx < _this->Super1.MenuList.NoOfItems )
  {
    CoreVerticalList_OnSetSelectedItem( &_this->Super1.MenuList, NextItemIdx );
    MenuVerticalMenu_SwitchToPageOfSelectedItem((MenuVerticalMenu)_this );
    MenuVerticalMenu_MoveFocusFrame((MenuVerticalMenu)_this );
  }
}

/* 'C' function for method : 'Navigation::TbtListMenu.OnShortUpKeyActivated()' */
void NavigationTbtListMenu_OnShortUpKeyActivated( NavigationTbtListMenu _this )
{
  XInt32 PrevItemIdx = _this->Super1.MenuList.SelectedItem - 1;

  if ( PrevItemIdx >= 0 )
  {
    CoreVerticalList_OnSetSelectedItem( &_this->Super1.MenuList, PrevItemIdx );
    MenuVerticalMenu_SwitchToPageOfSelectedItem((MenuVerticalMenu)_this );
    MenuVerticalMenu_MoveFocusFrame((MenuVerticalMenu)_this );
  }
}

/* This method is called by 'VerticalList' every time the list loads or updates 
   an item. */
void NavigationTbtListMenu_OnLoadItemSlot( NavigationTbtListMenu _this, XObject 
  sender )
{
  NavigationTbtInfoItem item;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  item = EwCastObject( _this->Super1.MenuList.View, NavigationTbtInfoItem );

  if ( item != 0 )
  {
    DeviceInterfaceNaviTbtDataClass NaviTbtData = DeviceInterfaceNavigationDeviceClass_GetNaviTbtData( 
      EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
      _this->Super1.MenuList.Item );

    if ( NaviTbtData->ListIdx < 0 )
      ;

    NavigationTbtListMenu_ShowTbtListItemIcon( _this, NaviTbtData->IconIdx );
    ViewsText_OnSetString( &item->NextTurnDistUnit, NaviTbtData->DistUnit );
    ViewsText_OnSetString( &item->NextTurnDist, EwNewStringInt( NaviTbtData->Distance, 
    0, 10 ));
    ViewsText_OnSetString( &item->NextTurnDescription, NaviTbtData->TbtDescription );
    ViewsRectangle_OnSetVisible( &item->TbtItemBg, 0 );

    if ( _this->ActiveTbtIdx == _this->Super1.MenuList.Item )
    {
      ViewsRectangle_OnSetVisible( &item->TbtItemBg, 1 );
    }

    CoreRectView__OnSetBounds( item, EwSetRectSize( item->Super2.Bounds, EwNewPoint( 
    EwGetRectW( _this->Super1.MenuList.Super2.Bounds ), _this->Super1.MenuList.ItemHeight )));
  }
}

/* 'C' function for method : 'Navigation::TbtListMenu.ShowTbtListItemIcon()' */
void NavigationTbtListMenu_ShowTbtListItemIcon( NavigationTbtListMenu _this, XInt32 
  index )
{
  NavigationTbtInfoItem item = EwCastObject( _this->Super1.MenuList.View, NavigationTbtInfoItem );

  if ( item != 0 )
  {
    XEnum NaviTurnStatus = (XEnum)index;

    switch ( NaviTurnStatus )
    {
      case EnumNaviTurnStatusTypeCONTINUE_LEFT :
        ViewsImage_OnSetBitmap( &item->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwKeepLIrg28, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeTURN_LEFT :
        ViewsImage_OnSetBitmap( &item->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwTurnLIrg28, 
        ResourcesBitmap ));
      break;

      case EnumNaviTurnStatusTypeTURN_RIGHT :
        ViewsImage_OnSetBitmap( &item->NextTurnIcon, EwLoadResource( &ResourceNaviTurnArrwTurnRIrg28, 
        ResourcesBitmap ));
      break;

      default : 
        ;
    }
  }
}

/* Variants derived from the class : 'Navigation::TbtListMenu' */
EW_DEFINE_CLASS_VARIANTS( NavigationTbtListMenu )
EW_END_OF_CLASS_VARIANTS( NavigationTbtListMenu )

/* Virtual Method Table (VMT) for the class : 'Navigation::TbtListMenu' */
EW_DEFINE_CLASS( NavigationTbtListMenu, MenuVerticalMenu, _None, _None, _None, _None, 
                 _None, _None, "Navigation::TbtListMenu" )
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
  MenuVerticalMenu_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  NavigationTbtListMenu_OnShortDownKeyActivated,
  NavigationTbtListMenu_OnShortUpKeyActivated,
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
  NavigationTbtListMenu_OnLoadItemSlot,
EW_END_OF_CLASS( NavigationTbtListMenu )

/* Initializer for the class 'Navigation::NaviDialog' */
void NavigationNaviDialog__Init( NavigationNaviDialog _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationNaviDialog );

  /* ... then construct all embedded objects */
  ViewsFrame__Init( &_this->DialogBackground, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DialogContent, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->CountDownTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationNaviDialog );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const004A );
  CoreRectView__OnSetBounds( &_this->DialogBackground, _Const004A );
  CoreRectView__OnSetBounds( &_this->DialogContent, _Const004B );
  ViewsText_OnSetWrapText( &_this->DialogContent, 1 );
  ViewsText_OnSetString( &_this->DialogContent, 0 );
  _this->CountDownTime = 10;
  CoreGroup__Add( _this, ((CoreView)&_this->DialogBackground ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DialogContent ), 0 );
  ViewsFrame_OnSetBitmap( &_this->DialogBackground, EwLoadResource( &ResourceDialogBackground, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->DialogContent, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->CountDownTimer.OnTrigger = EwNewSlot( _this, NavigationNaviDialog_UpdateCountDownTimeSlot );
}

/* Re-Initializer for the class 'Navigation::NaviDialog' */
void NavigationNaviDialog__ReInit( NavigationNaviDialog _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsFrame__ReInit( &_this->DialogBackground );
  ViewsText__ReInit( &_this->DialogContent );
  CoreTimer__ReInit( &_this->CountDownTimer );
}

/* Finalizer method for the class 'Navigation::NaviDialog' */
void NavigationNaviDialog__Done( NavigationNaviDialog _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsFrame__Done( &_this->DialogBackground );
  ViewsText__Done( &_this->DialogContent );
  CoreTimer__Done( &_this->CountDownTimer );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
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
        _this->ButtonSet = EwCastObject( EwNewObjectIndirect( value, 0 ), MenuUpDownPushButtonSet );
        _this->ButtonSet->OnUpButtonActivated = EwNewSlot( _this, NavigationNaviDialog_OnOkActivatedSlot );
        _this->ButtonSet->OnDownButtonActivated = EwNewSlot( _this, NavigationNaviDialog_OnNoActivatedSlot );
        MenuUpDownPushButtonSet_OnSetUpButtonTitle( _this->ButtonSet, EwLoadString( 
        &StringsGEN_YES ));
        MenuUpDownPushButtonSet_OnSetDownButtonTitle( _this->ButtonSet, EwConcatString( 
        EwConcatString( EwConcatString( EwLoadString( &StringsGEN_NO ), EwLoadString( 
        &_Const004C )), EwNewStringInt( _this->CountDownTime, 0, 10 )), EwLoadString( 
        &_Const004D )));
        CoreRectView__OnSetBounds( _this->ButtonSet, _Const004E );
        CoreGroup__Add( _this, ((CoreView)_this->ButtonSet ), 0 );
        CoreRectView__OnSetBounds( &_this->DialogContent, _Const004F );
      }
      break;

      case EnumNaviDialogTypeDIALOG_OK :
      {
        MenuPushButton Button = EwCastObject( EwNewObjectIndirect( value, 0 ), MenuPushButton );
        Button->OnActivate = EwNewSlot( _this, NavigationNaviDialog_OnOkActivatedSlot );
        CoreRectView__OnSetBounds( Button, _Const0050 );
        MenuPushButton_OnSetTitle( Button, EwGetVariantOfString( &StringsGEN_OK ));
        CoreGroup__Add( _this, ((CoreView)Button ), 0 );
        CoreRectView__OnSetBounds( &_this->DialogContent, _Const004B );
      }
      break;

      default : 
        ;
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
    ViewsText_OnSetString( &_this->DialogContent, _this->DialogMessage );
  }
}

/* 'C' function for method : 'Navigation::NaviDialog.OnSetDialogType()' */
void NavigationNaviDialog_OnSetDialogType( NavigationNaviDialog _this, XEnum value )
{
  if ( _this->DialogType != value )
  {
    _this->DialogType = value;
  }
}

/* 'C' function for method : 'Navigation::NaviDialog.OnOkActivatedSlot()' */
void NavigationNaviDialog_OnOkActivatedSlot( NavigationNaviDialog _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->DialogType == EnumNaviDialogTypeDIALOG_OK )
  {
    DeviceInterfaceNavigationDeviceClass_SendSelectedDialog( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
    DeviceInterfaceNavigationDeviceClass ), EnumNaviButtonTypeOK );
  }
  else
    if ( _this->DialogType == EnumNaviDialogTypeDIALOG_YES_NO )
    {
      DeviceInterfaceNavigationDeviceClass_SendSelectedDialog( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), 
      EnumNaviButtonTypeYES );
    }
    else
      ;

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
    EwConcatString( EwConcatString( EwLoadString( &StringsGEN_NO ), EwLoadString( 
    &_Const004C )), EwNewStringInt( _this->CountDownTime, 0, 10 )), EwLoadString( 
    &_Const004D )));
    CoreGroup_InvalidateViewState((CoreGroup)_this );
  }
  else
  {
    CoreTimer_OnSetEnabled( &_this->CountDownTimer, 0 );
    _this->CountDownTime = 10;
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

/* Embedded Wizard */
