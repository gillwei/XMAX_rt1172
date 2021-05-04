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
#include "_MenuVerticalMenu.h"
#include "_NavigationNAV01_DefaultView.h"
#include "_NavigationNAV03_TBTListView.h"
#include "_NavigationNAV05_TBTView.h"
#include "_NavigationNAV06_NaviSettingMenu.h"
#include "_NavigationNAV08_NaviChageViewMenu.h"
#include "_NavigationNaviAlert.h"
#include "_NavigationNaviAlertMessage.h"
#include "_NavigationNaviCurrentRoad.h"
#include "_NavigationNaviETA.h"
#include "_NavigationTbtInfoItem.h"
#include "_NavigationTbtListMenu.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesExternBitmap.h"
#include "_ResourcesFont.h"
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
  0x00000110, /* ratio 66.18 % */
  0xB8000D00, 0x8009A452, 0x00E00030, 0x60607858, 0xDE002911, 0x6640041C, 0x0E028021,
  0x636800D7, 0x8E438091, 0x046E330C, 0x1A0002F0, 0x023E098B, 0x0D800348, 0x4D243280,
  0x70E0745A, 0x3231800A, 0x09744A25, 0x88968002, 0xB4BCDC00, 0x1061C178, 0xCA867600,
  0x68667899, 0x610A9B4F, 0x73D8ACC2, 0x308E44C8, 0x885C2297, 0x000B61C0, 0x1D80755F,
  0x412310BB, 0x3A2F2084, 0x6CD69854, 0x3A30B111, 0x50BB143A, 0x70B8C120, 0x6BC5BA2D,
  0x2A4382B1, 0x00008400, 0x4AC993DC, 0xD0007300, 0xCAD3D001, 0x18779861, 0x72CA161F,
  0x018B45B1, 0x00000001, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 38 }, { 480, 272 }};
static const XColor _Const0001 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0002 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0003 = {{ 0, 226 }, { 130, 272 }};
static const XColor _Const0004 = { 0x16, 0x1F, 0x3C, 0xFF };
static const XRect _Const0005 = {{ 130, 226 }, { 480, 272 }};
static const XColor _Const0006 = { 0x02, 0x03, 0x05, 0xE6 };
static const XRect _Const0007 = {{ 140, 228 }, { 470, 259 }};
static const XRect _Const0008 = {{ 130, 224 }, { 480, 226 }};
static const XRect _Const0009 = {{ 10, 228 }, { 120, 259 }};
static const XRect _Const000A = {{ 9, 122 }, { 49, 162 }};
static const XRect _Const000B = {{ 9, 170 }, { 49, 210 }};
static const XRect _Const000C = {{ 411, 164 }, { 473, 226 }};
static const XRect _Const000D = {{ 420, 179 }, { 464, 212 }};
static const XRect _Const000E = {{ 480, 226 }, { 480, 272 }};
static const XRect _Const000F = {{ 0, 226 }, { 480, 272 }};
static const XRect _Const0010 = {{ 370, 226 }, { 480, 272 }};
static const XStringRes _Const0011 = { _StringsDefault0, 0x0002 };
static const XRect _Const0012 = {{ 134, 228 }, { 310, 259 }};
static const XRect _Const0013 = {{ 0, 0 }, { 0, 0 }};
static const XRect _Const0014 = {{ 130, 122 }, { 170, 162 }};
static const XRect _Const0015 = {{ 130, 170 }, { 170, 210 }};
static const XRect _Const0016 = {{ 0, 0 }, { 330, 31 }};
static const XRect _Const0017 = {{ 0, 8 }, { 20, 28 }};
static const XRect _Const0018 = {{ 24, 0 }, { 330, 31 }};
static const XStringRes _Const0019 = { _StringsDefault0, 0x0008 };
static const XRect _Const001A = {{ 0, 0 }, { 480, 46 }};
static const XRect _Const001B = {{ 405, 0 }, { 480, 46 }};
static const XColor _Const001C = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const001D = {{ 445, 9 }, { 470, 31 }};
static const XRect _Const001E = {{ 405, 3 }, { 443, 33 }};
static const XStringRes _Const001F = { _StringsDefault0, 0x000F };
static const XStringRes _Const0020 = { _StringsDefault0, 0x0014 };
static const XStringRes _Const0021 = { _StringsDefault0, 0x0018 };
static const XStringRes _Const0022 = { _StringsDefault0, 0x001F };
static const XRect _Const0023 = {{ 370, 0 }, { 480, 46 }};
static const XStringRes _Const0024 = { _StringsDefault0, 0x0028 };
static const XColor _Const0025 = { 0xE2, 0x7F, 0x07, 0xFF };
static const XStringRes _Const0026 = { _StringsDefault0, 0x0036 };
static const XColor _Const0027 = { 0xAA, 0x14, 0x15, 0xFF };
static const XRect _Const0028 = {{ 0, 0 }, { 405, 46 }};
static const XRect _Const0029 = {{ 10, 8 }, { 30, 28 }};
static const XRect _Const002A = {{ 34, 2 }, { 315, 33 }};
static const XRect _Const002B = {{ 325, 3 }, { 352, 33 }};
static const XRect _Const002C = {{ 354, 9 }, { 395, 31 }};
static const XRect _Const002D = {{ 0, 0 }, { 110, 33 }};
static const XRect _Const002E = {{ 19, 7 }, { 39, 29 }};
static const XRect _Const002F = {{ 41, 2 }, { 92, 33 }};
static const XRect _Const0030 = {{ 84, 9 }, { 110, 31 }};
static const XStringRes _Const0031 = { _StringsDefault0, 0x004D };
static const XStringRes _Const0032 = { _StringsDefault0, 0x0055 };
static const XStringRes _Const0033 = { _StringsDefault0, 0x005A };
static const XStringRes _Const0034 = { _StringsDefault0, 0x005F };
static const XStringRes _Const0035 = { _StringsDefault0, 0x0064 };
static const XStringRes _Const0036 = { _StringsDefault0, 0x0068 };
static const XStringRes _Const0037 = { _StringsDefault0, 0x006E };
static const XRect _Const0038 = {{ 0, 38 }, { 480, 226 }};
static const XRect _Const0039 = {{ 186, 68 }, { 254, 116 }};
static const XRect _Const003A = {{ 254, 82 }, { 278, 112 }};
static const XRect _Const003B = {{ 186, 117 }, { 408, 210 }};
static const XColor _Const003C = { 0xCF, 0xCF, 0xCF, 0xFF };
static const XRect _Const003D = {{ 28, 54 }, { 178, 204 }};
static const XRect _Const003E = {{ 104, 75 }, { 376, 199 }};
static const XRect _Const003F = {{ 0, 36 }, { 480, 272 }};
static const XStringRes _Const0040 = { _StringsDefault0, 0x0073 };
static const XRect _Const0041 = {{ 0, 0 }, { 480, 74 }};
static const XRect _Const0042 = {{ 20, 0 }, { 440, 72 }};
static const XColor _Const0043 = { 0x1E, 0x47, 0x8C, 0xFF };
static const XRect _Const0044 = {{ 30, 22 }, { 58, 50 }};
static const XRect _Const0045 = {{ 62, 19 }, { 106, 53 }};
static const XRect _Const0046 = {{ 106, 19 }, { 154, 53 }};
static const XRect _Const0047 = {{ 155, 5 }, { 430, 72 }};
static const XColor _Const0048 = { 0xC8, 0xC8, 0xC8, 0xFF };
static const XRect _Const0049 = {{ 0, 72 }, { 480, 74 }};
static const XRect _Const004A = {{ 0, 0 }, { 480, 236 }};

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
  ViewsRectangle__Init( &_this->RoadNameBg, &_this->_XObject, 0 );
  NavigationNaviCurrentRoad__Init( &_this->CurrentRoadObject, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Shadow, &_this->_XObject, 0 );
  NavigationNaviETA__Init( &_this->NaviETAObject, &_this->_XObject, 0 );
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
  EffectsRectEffect__Init( &_this->NaviEventEnLargeEffect, &_this->_XObject, 0 );
  EffectsRectEffect__Init( &_this->NaviEventDismissEffect, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NavigatingStatusUpdateEventHandler, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->SpeedLimitFlickeringTimer, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_XObject, 0 );

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
  CoreRectView__OnSetBounds( &_this->RoadNameBg, _Const0005 );
  ViewsRectangle_OnSetColor( &_this->RoadNameBg, _Const0006 );
  CoreRectView__OnSetBounds( &_this->CurrentRoadObject, _Const0007 );
  CoreRectView__OnSetBounds( &_this->Shadow, _Const0008 );
  ViewsImage_OnSetVisible( &_this->Shadow, 0 );
  CoreRectView__OnSetBounds( &_this->NaviETAObject, _Const0009 );
  CoreGroup__OnSetVisible( &_this->NaviETAObject, 1 );
  CoreRectView__OnSetBounds( &_this->ZoomInButton, _Const000A );
  ViewsImage_OnSetVisible( &_this->ZoomInButton, 0 );
  CoreRectView__OnSetBounds( &_this->ZoomOutButton, _Const000B );
  ViewsImage_OnSetVisible( &_this->ZoomOutButton, 0 );
  CoreRectView__OnSetBounds( &_this->SpeedLimitIcon, _Const000C );
  ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 0 );
  CoreRectView__OnSetBounds( &_this->SpeedLimitText, _Const000D );
  ViewsText_OnSetString( &_this->SpeedLimitText, 0 );
  ViewsText_OnSetColor( &_this->SpeedLimitText, _Const0001 );
  ViewsText_OnSetVisible( &_this->SpeedLimitText, 0 );
  CoreTimer_OnSetPeriod( &_this->HighlightTimer, 100 );
  CoreTimer_OnSetEnabled( &_this->HighlightTimer, 0 );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->CurrentRoadShiftEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->CurrentRoadShiftEffect, 
  500 );
  CoreRectView__OnSetBounds( &_this->NaviEventObject, _Const000E );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->NaviEventEnLargeEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->NaviEventEnLargeEffect, 
  500 );
  _this->NaviEventEnLargeEffect.Value2 = _Const000F;
  _this->NaviEventEnLargeEffect.Value1 = _Const000E;
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->NaviEventDismissEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->NaviEventDismissEffect, 
  500 );
  _this->NaviEventDismissEffect.Value2 = _Const000E;
  _this->NaviEventDismissEffect.Value1 = _Const0010;
  CoreTimer_OnSetPeriod( &_this->SpeedLimitFlickeringTimer, 300 );
  CoreGroup__Add( _this, ((CoreView)&_this->Background ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MapImage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ArrivalBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RoadNameBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CurrentRoadObject ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Shadow ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviETAObject ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ZoomInButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ZoomOutButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SpeedLimitIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SpeedLimitText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviEventObject ), 0 );
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
  _this->CurrentRoadShiftEffect.Outlet = EwNewRef( &_this->CurrentRoadObject, CoreRectView_OnGetBounds, 
  CoreRectView__OnSetBounds );
  _this->NaviEventObject.DismissAlertSignal = EwNewSlot( _this, NavigationNAV01_DefaultView_DismissAlert );
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
  ViewsRectangle__ReInit( &_this->RoadNameBg );
  NavigationNaviCurrentRoad__ReInit( &_this->CurrentRoadObject );
  ViewsImage__ReInit( &_this->Shadow );
  NavigationNaviETA__ReInit( &_this->NaviETAObject );
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
  EffectsRectEffect__ReInit( &_this->NaviEventEnLargeEffect );
  EffectsRectEffect__ReInit( &_this->NaviEventDismissEffect );
  CoreSystemEventHandler__ReInit( &_this->NavigatingStatusUpdateEventHandler );
  CoreTimer__ReInit( &_this->SpeedLimitFlickeringTimer );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
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
  ViewsRectangle__Done( &_this->RoadNameBg );
  NavigationNaviCurrentRoad__Done( &_this->CurrentRoadObject );
  ViewsImage__Done( &_this->Shadow );
  NavigationNaviETA__Done( &_this->NaviETAObject );
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
  EffectsRectEffect__Done( &_this->NaviEventEnLargeEffect );
  EffectsRectEffect__Done( &_this->NaviEventDismissEffect );
  CoreSystemEventHandler__Done( &_this->NavigatingStatusUpdateEventHandler );
  CoreTimer__Done( &_this->SpeedLimitFlickeringTimer );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );

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

  EwSignal( EwNewSlot( _this, NavigationNAV01_DefaultView_OnNavigatingStatusUpdateSlot ), 
    ((XObject)_this ));
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
  if ( ViewsImage_OnGetVisible( &_this->ZoomOutButton ))
  {
    _this->ZoomButtonStatus = 1;
    NavigationNAV01_DefaultView_StartHighlight( _this );
  }
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnShortUpKeyActivated()' */
void NavigationNAV01_DefaultView_OnShortUpKeyActivated( NavigationNAV01_DefaultView _this )
{
  if ( ViewsImage_OnGetVisible( &_this->ZoomInButton ))
  {
    _this->ZoomButtonStatus = 0;
    NavigationNAV01_DefaultView_StartHighlight( _this );
  }
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnLongEnterKeyActivated()' */
void NavigationNAV01_DefaultView_OnLongEnterKeyActivated( NavigationNAV01_DefaultView _this )
{
  if ( 1 == _this->Super3.KeyHandler.RepetitionCount )
  {
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( NavigationNAV06_NaviSettingMenu, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
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
  EwConcatString( EwLoadString( &_Const0011 ), EwNewStringInt( _this->MapFrameIdx, 
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
  NavigationNaviCurrentRoad_OnSetRoadName( &_this->CurrentRoadObject, NaviData->CurrentRoad );
  NavigationNaviCurrentRoad_SetItemBounds( &_this->CurrentRoadObject, 0 );
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
  NavigationNaviETA_OnSetETA( &_this->NaviETAObject, NaviData->ETA );
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
  DeviceInterfaceNaviDataClass NaviData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  NaviData = DeviceInterfaceNavigationDeviceClass_GetNaviData( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), EnumNaviDataTypeNAVI_EVENT );

  if ( NaviData->NaviEventVisibility )
  {
    NavigationNaviAlert_SetupAlert( &_this->NaviEventObject, NaviData->NaviEventType, 
    NaviData->NaviEventSpeed, NaviData->NaviEventDist );
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->NaviEventEnLargeEffect, 1 );
  }
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnCurrentRoadShiftEffectFinishSlot()' */
void NavigationNAV01_DefaultView_OnCurrentRoadShiftEffectFinishSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreRectView__OnSetBounds( &_this->CurrentRoadObject, _Const0007 );
  NavigationNaviCurrentRoad_UpdateItemBounds( &_this->CurrentRoadObject, EnumNaviAlertAnimationTypeDismiss, 
  EwGetRectW( _this->CurrentRoadObject.Super2.Bounds ));
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->CurrentRoadShiftEffect, 0 );
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnNaviEventEnlargeFinishSlot()' */
void NavigationNAV01_DefaultView_OnNaviEventEnlargeFinishSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->NaviEventEnLargeEffect, 0 );
  CoreRectView__OnSetBounds( &_this->CurrentRoadObject, _Const0012 );
  NavigationNaviCurrentRoad_UpdateItemBounds( &_this->CurrentRoadObject, EnumNaviAlertAnimationTypeShrink, 
  EwGetRectW( _this->CurrentRoadObject.Super2.Bounds ));
  NavigationNaviAlert_ShrinkAlert( &_this->NaviEventObject );
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnNaviEventDismissFinishSlot()' */
void NavigationNAV01_DefaultView_OnNaviEventDismissFinishSlot( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->NaviEventDismissEffect, 0 );
}

/* 'C' function for method : 'Navigation::NAV01_DefaultView.DismissAlert()' */
void NavigationNAV01_DefaultView_DismissAlert( NavigationNAV01_DefaultView _this, 
  XObject sender )
{
  XRect NewCurrentRoadObjectBounds;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->CurrentRoadShiftEffect.Value1 = _this->CurrentRoadObject.Super2.Bounds;
  NewCurrentRoadObjectBounds = _Const0013;
  NewCurrentRoadObjectBounds.Point1.X = ( _this->CurrentRoadObject.NaviIconX1Pos 
  + EwGetRectW( _this->ArrivalBg.Super1.Bounds ));
  NewCurrentRoadObjectBounds.Point2.X = ( NewCurrentRoadObjectBounds.Point1.X + 
  EwGetRectW( _this->CurrentRoadObject.Super2.Bounds ));
  NewCurrentRoadObjectBounds.Point1.Y = _this->CurrentRoadObject.Super2.Bounds.Point1.Y;
  NewCurrentRoadObjectBounds.Point2.Y = _this->CurrentRoadObject.Super2.Bounds.Point2.Y;

  if ( NewCurrentRoadObjectBounds.Point1.X > _this->CurrentRoadShiftEffect.Value1.Point1.X )
  {
    _this->CurrentRoadShiftEffect.Value2 = NewCurrentRoadObjectBounds;
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->CurrentRoadShiftEffect, 1 );
  }
  else
  {
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->CurrentRoadShiftEffect, 0 );
    CoreRectView__OnSetBounds( &_this->CurrentRoadObject, _Const0007 );
    NavigationNaviCurrentRoad_UpdateItemBounds( &_this->CurrentRoadObject, EnumNaviAlertAnimationTypeDismiss, 
    EwGetRectW( _this->CurrentRoadObject.Super2.Bounds ));
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

  if ( DeviceInterfaceNavigationDeviceClass_IsRouteGuidanceStarted( EwGetAutoObject( 
      &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )))
  {
    CoreRectView__OnSetBounds( &_this->ZoomInButton, _Const0014 );
    CoreRectView__OnSetBounds( &_this->ZoomOutButton, _Const0015 );
  }
  else
  {
    CoreRectView__OnSetBounds( &_this->ZoomInButton, _Const000A );
    CoreRectView__OnSetBounds( &_this->ZoomOutButton, _Const000B );
  }

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
  _this->IsDestSet = 1;
}

/* Re-Initializer for the class 'Navigation::NAV06_NaviSettingMenu' */
void NavigationNAV06_NaviSettingMenu__ReInit( NavigationNAV06_NaviSettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Navigation::NAV06_NaviSettingMenu' */
void NavigationNAV06_NaviSettingMenu__Done( NavigationNAV06_NaviSettingMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
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

  if ( aMenuItem == 0 )
    ;

  MenuDialog = 0;

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
    {
      if ( !_this->IsDestSet )
      {
        ItemEnabled = 0;
      }
    }
    break;

    case EnumNaviSettingItemSkipNextStop :
    {
      if ( !_this->IsDestSet )
      {
        ItemEnabled = 0;
      }
      else
      {
        if ( !_this->IsWayPointSet )
        {
          ItemEnabled = 0;
        }
      }
    }
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
      if ( !_this->IsDestSet )
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

/* Variants derived from the class : 'Navigation::NAV06_NaviSettingMenu' */
EW_DEFINE_CLASS_VARIANTS( NavigationNAV06_NaviSettingMenu )
EW_END_OF_CLASS_VARIANTS( NavigationNAV06_NaviSettingMenu )

/* Virtual Method Table (VMT) for the class : 'Navigation::NAV06_NaviSettingMenu' */
EW_DEFINE_CLASS( NavigationNAV06_NaviSettingMenu, MenuBaseMenuView, _None, _None, 
                 _None, _None, _None, _None, "Navigation::NAV06_NaviSettingMenu" )
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
  CoreRectView__OnSetBounds( _this, _Const0016 );
  CoreRectView__OnSetBounds( &_this->NaviIconCurRd, _Const0017 );
  ViewsImage_OnSetVisible( &_this->NaviIconCurRd, 0 );
  CoreRectView__OnSetBounds( &_this->RoadNameText, _Const0018 );
  ViewsText_OnSetAlignment( &_this->RoadNameText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->RoadNameText, 0 );
  _this->RoadNameTextBounds = _Const0018;
  _this->NaviIconBounds = _Const0017;
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
    ViewsText_OnSetString( &_this->RoadNameText, EwLoadString( &_Const0019 ));
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
                 NaviIconCurRd, NaviIconCurRd, RoadName, RoadNameTextBounds, "Navigation::NaviCurrentRoad" )
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
  CoreRectView__OnSetBounds( _this, _Const001A );
  CoreRectView__OnSetBounds( &_this->NaviDistBg, _Const001B );
  ViewsRectangle_OnSetColor( &_this->NaviDistBg, _Const001C );
  CoreRectView__OnSetBounds( &_this->DistUnit, _Const001D );
  ViewsText_OnSetAlignment( &_this->DistUnit, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DistUnit, 0 );
  CoreRectView__OnSetBounds( &_this->Distance, _Const001E );
  ViewsText_OnSetAlignment( &_this->Distance, ViewsTextAlignmentAlignHorzRight | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Distance, 0 );
  CoreTimer_OnSetPeriod( &_this->SuspendTimer, 8000 );
  _this->DistUnitTextArray[ 0 ] = EwShareString( EwLoadString( &_Const001F ));
  _this->DistUnitTextArray[ 1 ] = EwShareString( EwLoadString( &_Const0020 ));
  _this->SpeedUnitTextArray[ 0 ] = EwShareString( EwLoadString( &_Const0021 ));
  _this->SpeedUnitTextArray[ 1 ] = EwShareString( EwLoadString( &_Const0022 ));
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->NaviEventShrinkEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->NaviEventShrinkEffect, 
  500 );
  _this->NaviEventShrinkEffect.Value2 = _Const0023;
  _this->NaviEventShrinkEffect.Value1 = _Const001A;
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

/* 'C' function for method : 'Navigation::NaviAlert.SetupAlert()' */
void NavigationNaviAlert_SetupAlert( NavigationNaviAlert _this, XInt32 aNaviEventType, 
  XString aNaviEventSpeed, XString aNaviEventDist )
{
  XInt32 i;
  XInt32 idx;

  switch ( aNaviEventType )
  {
    case 4 :
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
      &ResourceSafeCamTempEU, ResourcesBitmap ));
      ViewsText_OnSetString( &_this->AlertMessage.EventType, EwLoadString( &_Const0024 ));
      ViewsRectangle_OnSetColor( &_this->AlertMessage.NaviEventBg, _Const0025 );
      ViewsRectangle_OnSetColor( &_this->NaviDistBg, _Const0025 );
    }
    break;

    case 2 :
    {
      if ( !ViewsText_OnGetVisible( &_this->AlertMessage.NaviSpeed ))
      {
        ViewsText_OnSetVisible( &_this->AlertMessage.NaviSpeed, 1 );
      }

      if ( !ViewsText_OnGetVisible( &_this->AlertMessage.NaviSpeedUnit ))
      {
        ViewsText_OnSetVisible( &_this->AlertMessage.NaviSpeedUnit, 1 );
      }

      ViewsImage_OnSetBitmap( &_this->AlertMessage.NaviAlertIcon, EwLoadResource( 
      &ResourceSafeAvrgCamEU, ResourcesBitmap ));
      ViewsText_OnSetString( &_this->AlertMessage.EventType, EwLoadString( &_Const0026 ));
      ViewsRectangle_OnSetColor( &_this->AlertMessage.NaviEventBg, _Const0027 );
      ViewsRectangle_OnSetColor( &_this->NaviDistBg, _Const0027 );
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
        aNaviEventSpeed = EwStringRemove( aNaviEventSpeed, idx, EwGetStringLength( 
        _this->SpeedUnitTextArray[ EwCheckIndex( i, 2 )]));
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
      aNaviEventDist = EwStringRemove( aNaviEventDist, idx, EwGetStringLength( _this->DistUnitTextArray[ 
      EwCheckIndex( i, 2 )]));
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
  CoreRectView__OnSetBounds( _this, _Const0028 );
  CoreRectView__OnSetBounds( &_this->NaviEventBg, _Const0028 );
  ViewsRectangle_OnSetColor( &_this->NaviEventBg, _Const001C );
  ViewsRectangle_OnSetVisible( &_this->NaviEventBg, 1 );
  CoreRectView__OnSetBounds( &_this->NaviAlertIcon, _Const0029 );
  CoreRectView__OnSetBounds( &_this->EventType, _Const002A );
  ViewsText_OnSetAlignment( &_this->EventType, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->EventType, 0 );
  CoreRectView__OnSetBounds( &_this->NaviSpeed, _Const002B );
  ViewsText_OnSetString( &_this->NaviSpeed, 0 );
  ViewsText_OnSetVisible( &_this->NaviSpeed, 0 );
  CoreRectView__OnSetBounds( &_this->NaviSpeedUnit, _Const002C );
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
  CoreRectView__OnSetBounds( _this, _Const002D );
  CoreRectView__OnSetBounds( &_this->NaviIconFlag, _Const002E );
  ViewsImage_OnSetVisible( &_this->NaviIconFlag, 1 );
  CoreRectView__OnSetBounds( &_this->TimeText, _Const002F );
  ViewsText_OnSetAlignment( &_this->TimeText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TimeText, 0 );
  ViewsText_OnSetVisible( &_this->TimeText, 0 );
  CoreRectView__OnSetBounds( &_this->AmPmText, _Const0030 );
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
    ViewsText_OnSetString( &_this->TimeText, EwLoadString( &_Const0031 ));
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
      ViewsText_OnSetString( &_this->AmPmText, EwLoadString( &_Const0032 ));
    }
    else
    {
      ViewsText_OnSetString( &_this->AmPmText, EwLoadString( &_Const0033 ));

      if ( hour > 12 )
      {
        hour = hour - 12;
      }
    }

    if ( min < 10 )
    {
      eta = EwConcatString( EwConcatString( EwNewStringInt( hour, 0, 10 ), EwLoadString( 
      &_Const0034 )), EwNewStringInt( min, 0, 10 ));
    }
    else
    {
      eta = EwConcatString( EwConcatString( EwNewStringInt( hour, 0, 10 ), EwLoadString( 
      &_Const0035 )), EwNewStringInt( min, 0, 10 ));
    }
  }
  else
  {
    if ( min < 10 )
    {
      eta = EwConcatString( EwLoadString( &_Const0036 ), EwNewStringInt( min, 0, 
      10 ));
    }
    else
    {
      eta = EwConcatString( EwLoadString( &_Const0037 ), EwNewStringInt( min, 0, 
      10 ));
    }

    ViewsText_OnSetString( &_this->AmPmText, EwLoadString( &_Const0032 ));
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
  NavigationNaviETA__Init( &_this->NaviETAObject, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->RoadNameBg, &_this->_XObject, 0 );
  NavigationNaviCurrentRoad__Init( &_this->CurrentRoadObject, &_this->_XObject, 0 );
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

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationNAV05_TBTView );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0002 );
  _this->Super1.HomeType = EnumHomeTypeNAVI_NEXT_TURN;
  CoreRectView__OnSetBounds( &_this->NaviTBTViewBg, _Const0038 );
  CoreRectView__OnSetBounds( &_this->ArrivalBg, _Const0003 );
  ViewsRectangle_OnSetColor( &_this->ArrivalBg, _Const0004 );
  ViewsRectangle_OnSetVisible( &_this->ArrivalBg, 1 );
  CoreRectView__OnSetBounds( &_this->NaviETAObject, _Const0009 );
  CoreRectView__OnSetBounds( &_this->RoadNameBg, _Const0005 );
  ViewsRectangle_OnSetColor( &_this->RoadNameBg, _Const0006 );
  CoreRectView__OnSetBounds( &_this->CurrentRoadObject, _Const0007 );
  CoreRectView__OnSetBounds( &_this->SpeedLimitIcon, _Const000C );
  ViewsImage_OnSetVisible( &_this->SpeedLimitIcon, 0 );
  CoreRectView__OnSetBounds( &_this->SpeedLimitText, _Const000D );
  ViewsText_OnSetString( &_this->SpeedLimitText, 0 );
  ViewsText_OnSetColor( &_this->SpeedLimitText, _Const0001 );
  ViewsText_OnSetVisible( &_this->SpeedLimitText, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnDist, _Const0039 );
  ViewsText_OnSetString( &_this->NextTurnDist, 0 );
  ViewsText_OnSetVisible( &_this->NextTurnDist, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnDistUnit, _Const003A );
  ViewsText_OnSetString( &_this->NextTurnDistUnit, 0 );
  ViewsText_OnSetVisible( &_this->NextTurnDistUnit, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnDescription, _Const003B );
  ViewsText_OnSetEllipsis( &_this->NextTurnDescription, 1 );
  ViewsText_OnSetWrapText( &_this->NextTurnDescription, 1 );
  ViewsText_OnSetAlignment( &_this->NextTurnDescription, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->NextTurnDescription, 0 );
  ViewsText_OnSetColor( &_this->NextTurnDescription, _Const003C );
  CoreRectView__OnSetBounds( &_this->NextTurnIcon, _Const003D );
  ViewsImage_OnSetVisible( &_this->NextTurnIcon, 0 );
  CoreRectView__OnSetBounds( &_this->RecalculateMessage, _Const003E );
  ViewsText_OnSetString( &_this->RecalculateMessage, 0 );
  ViewsText_OnSetColor( &_this->RecalculateMessage, _Const003C );
  ViewsText_OnSetVisible( &_this->RecalculateMessage, 0 );
  CoreTimer_OnSetPeriod( &_this->SpeedLimitFlickeringTimer, 300 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviTBTViewBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ArrivalBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviETAObject ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RoadNameBg ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CurrentRoadObject ), 0 );
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
  NavigationNaviETA__ReInit( &_this->NaviETAObject );
  ViewsRectangle__ReInit( &_this->RoadNameBg );
  NavigationNaviCurrentRoad__ReInit( &_this->CurrentRoadObject );
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
}

/* Finalizer method for the class 'Navigation::NAV05_TBTView' */
void NavigationNAV05_TBTView__Done( NavigationNAV05_TBTView _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( HomeBaseHome );

  /* Finalize all embedded objects */
  ViewsWallpaper__Done( &_this->NaviTBTViewBg );
  ViewsRectangle__Done( &_this->ArrivalBg );
  NavigationNaviETA__Done( &_this->NaviETAObject );
  ViewsRectangle__Done( &_this->RoadNameBg );
  NavigationNaviCurrentRoad__Done( &_this->CurrentRoadObject );
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

  EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnCurRdUpdateSlot ), ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnETAUpdateSlot ), ((XObject)_this ));
  EwSignal( EwNewSlot( _this, NavigationNAV05_TBTView_OnActiveTbtItemUpdateSlot ), 
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
  NavigationNaviETA_OnSetETA( &_this->NaviETAObject, NaviData->ETA );
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
  NavigationNaviCurrentRoad_OnSetRoadName( &_this->CurrentRoadObject, NaviData->CurrentRoad );
  NavigationNaviCurrentRoad_SetItemBounds( &_this->CurrentRoadObject, 0 );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV05_TBTView_OnActiveTbtItemUpdateSlot( NavigationNAV05_TBTView _this, 
  XObject sender )
{
  DeviceInterfaceNaviTbtDataClass NaviTbtData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  NaviTbtData = DeviceInterfaceNavigationDeviceClass_GetNaviTbtData( EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass ), EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->ActiveTbtItemIdx );
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
  CoreRectView__OnSetBounds( &_this->TbtList, _Const003F );
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

  EwTrace( "%s", EwLoadString( &_Const0040 ));
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
  CoreRectView__OnSetBounds( _this, _Const0041 );
  CoreRectView__OnSetBounds( &_this->TbtItemBg, _Const0042 );
  ViewsRectangle_OnSetColor( &_this->TbtItemBg, _Const0043 );
  ViewsRectangle_OnSetVisible( &_this->TbtItemBg, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnIcon, _Const0044 );
  CoreRectView__OnSetBounds( &_this->NextTurnDist, _Const0045 );
  ViewsText_OnSetString( &_this->NextTurnDist, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnDistUnit, _Const0046 );
  ViewsText_OnSetString( &_this->NextTurnDistUnit, 0 );
  CoreRectView__OnSetBounds( &_this->NextTurnDescription, _Const0047 );
  ViewsText_OnSetEllipsis( &_this->NextTurnDescription, 1 );
  ViewsText_OnSetWrapText( &_this->NextTurnDescription, 1 );
  ViewsText_OnSetAlignment( &_this->NextTurnDescription, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->NextTurnDescription, 0 );
  ViewsText_OnSetColor( &_this->NextTurnDescription, _Const0048 );
  CoreRectView__OnSetBounds( &_this->ListDivider, _Const0049 );
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
  CoreRectView__OnSetBounds( _this, _Const004A );
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

/* User defined constant: 'Navigation::TIMETEXT_W_NAVI_BOUNDS' */
const XRect NavigationTIMETEXT_W_NAVI_BOUNDS = {{ 22, 2 }, { 84, 33 }};

/* User defined constant: 'Navigation::NAVIFLAG_W_NAVI_BOUNDS' */
const XRect NavigationNAVIFLAG_W_NAVI_BOUNDS = {{ 0, 6 }, { 20, 28 }};

/* Embedded Wizard */
