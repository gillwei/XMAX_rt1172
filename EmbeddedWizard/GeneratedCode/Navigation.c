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
#include "_ComponentsBaseComponent.h"
#include "_CoreGroup.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DeviceInterfaceNavigationDeviceClass.h"
#include "_MenuItemBase.h"
#include "_MenuItemCheckMark.h"
#include "_MenuVerticalMenu.h"
#include "_NavigationMain.h"
#include "_NavigationNAV06_NaviSettingMenu.h"
#include "_NavigationNAV08_NaviChageViewMenu.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesExternBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
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
  0x00000084, /* ratio 81.82 % */
  0xB8000D00, 0x00062452, 0x00660019, 0x60614858, 0xD2002691, 0x20037000, 0x003A800E,
  0x00044CC2, 0x32802062, 0xA000E600, 0x148011C3, 0x02326F00, 0xC010B320, 0x00418703,
  0x111991C8, 0x6C951D80, 0xD9A9524A, 0x044B63E6, 0x00C20D0E, 0xC18003A0, 0x380B2D1A,
  0x2173D8D4, 0x014D8701, 0x51082408, 0x58969C23, 0x00000203, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XColor _Const0001 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0002 = {{ 0, 33 }, { 120, 210 }};
static const XRect _Const0003 = {{ 0, 210 }, { 120, 272 }};
static const XRect _Const0004 = {{ 10, 40 }, { 110, 110 }};
static const XRect _Const0005 = {{ 0, 117 }, { 70, 147 }};
static const XStringRes _Const0006 = { _StringsDefault0, 0x0002 };
static const XRect _Const0007 = {{ 0, 149 }, { 120, 199 }};
static const XStringRes _Const0008 = { _StringsDefault0, 0x0008 };
static const XRect _Const0009 = {{ 4, 210 }, { 114, 240 }};
static const XStringRes _Const000A = { _StringsDefault0, 0x001C };
static const XRect _Const000B = {{ 8, 240 }, { 68, 268 }};
static const XStringRes _Const000C = { _StringsDefault0, 0x002B };
static const XRect _Const000D = {{ 73, 240 }, { 113, 270 }};
static const XStringRes _Const000E = { _StringsDefault0, 0x0033 };
static const XRect _Const000F = {{ 77, 120 }, { 107, 150 }};
static const XStringRes _Const0010 = { _StringsDefault0, 0x0038 };
static const XStringRes _Const0011 = { _StringsDefault0, 0x003C };
static const XRect _Const0012 = {{ 0, 36 }, { 480, 272 }};

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

/* Initializer for the class 'Navigation::Main' */
void NavigationMain__Init( NavigationMain _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationMain );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Background, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->MapUpdateEventHandler, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->MapImage, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->TbTBgImage, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ArrivalBgImage, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->TbtImage, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DistanceText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->RoadText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->ArrivalText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TimeText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->AmPmText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->RoadText1, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationMain );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Background, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Background, _Const0001 );
  CoreRectView__OnSetBounds( &_this->MapImage, _Const0000 );
  ViewsImage_OnSetAlignment( &_this->MapImage, ViewsImageAlignmentAlignHorzRight 
  | ViewsImageAlignmentAlignVertBottom );
  CoreRectView__OnSetBounds( &_this->TbTBgImage, _Const0002 );
  ViewsImage_OnSetAlignment( &_this->TbTBgImage, ViewsImageAlignmentScaleToFill );
  CoreRectView__OnSetBounds( &_this->ArrivalBgImage, _Const0003 );
  CoreRectView__OnSetBounds( &_this->TbtImage, _Const0004 );
  ViewsImage_OnSetAlignment( &_this->TbtImage, ViewsImageAlignmentScaleToFit );
  CoreRectView__OnSetBounds( &_this->DistanceText, _Const0005 );
  ViewsText_OnSetAlignment( &_this->DistanceText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DistanceText, EwLoadString( &_Const0006 ));
  CoreRectView__OnSetBounds( &_this->RoadText, _Const0007 );
  ViewsText_OnSetWrapText( &_this->RoadText, 1 );
  ViewsText_OnSetString( &_this->RoadText, EwLoadString( &_Const0008 ));
  CoreRectView__OnSetBounds( &_this->ArrivalText, _Const0009 );
  ViewsText_OnSetString( &_this->ArrivalText, EwLoadString( &_Const000A ));
  CoreRectView__OnSetBounds( &_this->TimeText, _Const000B );
  ViewsText_OnSetAlignment( &_this->TimeText, ViewsTextAlignmentAlignHorzRight | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TimeText, EwLoadString( &_Const000C ));
  CoreRectView__OnSetBounds( &_this->AmPmText, _Const000D );
  ViewsText_OnSetAlignment( &_this->AmPmText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->AmPmText, EwLoadString( &_Const000E ));
  CoreRectView__OnSetBounds( &_this->RoadText1, _Const000F );
  ViewsText_OnSetWrapText( &_this->RoadText1, 0 );
  ViewsText_OnSetAlignment( &_this->RoadText1, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->RoadText1, EwLoadString( &_Const0010 ));
  CoreGroup__Add( _this, ((CoreView)&_this->Background ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MapImage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TbTBgImage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ArrivalBgImage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TbtImage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DistanceText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RoadText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ArrivalText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->AmPmText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RoadText1 ), 0 );
  _this->MapUpdateEventHandler.OnEvent = EwNewSlot( _this, NavigationMain_OnMapUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->MapUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->MapUpdateEvent );
  ViewsImage_OnSetBitmap( &_this->MapImage, ((ResourcesBitmap)EwGetAutoObject( &ResourceExternBitmap, 
  ResourcesExternBitmap )));
  ViewsImage_OnSetBitmap( &_this->TbTBgImage, EwLoadResource( &ResourceTbTBg, ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ArrivalBgImage, EwLoadResource( &ResourceArrivalBg, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->TbtImage, EwLoadResource( &ResourceIconTbT, ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->DistanceText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->RoadText, EwLoadResource( &FontsFontNotoSansCjkJp24, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->ArrivalText, EwLoadResource( &FontsFontNotoSansCjkJp20, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->TimeText, EwLoadResource( &FontsFontNotoSansCjkJp24, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->AmPmText, EwLoadResource( &FontsFontNotoSansCjkJp20, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->RoadText1, EwLoadResource( &FontsFontNotoSansCjkJp24, 
  ResourcesFont ));

  /* Call the user defined constructor */
  NavigationMain_Init( _this, aArg );
}

/* Re-Initializer for the class 'Navigation::Main' */
void NavigationMain__ReInit( NavigationMain _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Background );
  CoreSystemEventHandler__ReInit( &_this->MapUpdateEventHandler );
  ViewsImage__ReInit( &_this->MapImage );
  ViewsImage__ReInit( &_this->TbTBgImage );
  ViewsImage__ReInit( &_this->ArrivalBgImage );
  ViewsImage__ReInit( &_this->TbtImage );
  ViewsText__ReInit( &_this->DistanceText );
  ViewsText__ReInit( &_this->RoadText );
  ViewsText__ReInit( &_this->ArrivalText );
  ViewsText__ReInit( &_this->TimeText );
  ViewsText__ReInit( &_this->AmPmText );
  ViewsText__ReInit( &_this->RoadText1 );
}

/* Finalizer method for the class 'Navigation::Main' */
void NavigationMain__Done( NavigationMain _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Background );
  CoreSystemEventHandler__Done( &_this->MapUpdateEventHandler );
  ViewsImage__Done( &_this->MapImage );
  ViewsImage__Done( &_this->TbTBgImage );
  ViewsImage__Done( &_this->ArrivalBgImage );
  ViewsImage__Done( &_this->TbtImage );
  ViewsText__Done( &_this->DistanceText );
  ViewsText__Done( &_this->RoadText );
  ViewsText__Done( &_this->ArrivalText );
  ViewsText__Done( &_this->TimeText );
  ViewsText__Done( &_this->AmPmText );
  ViewsText__Done( &_this->RoadText1 );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void NavigationMain_Init( NavigationMain _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  if ( DeviceInterfaceNavigationDeviceClass_IsMapFrameReady( EwGetAutoObject( &DeviceInterfaceNavigationDevice, 
      DeviceInterfaceNavigationDeviceClass )))
  {
    EwPostSignal( EwNewSlot( _this, NavigationMain_OnMapUpdateSlot ), ((XObject)_this ));
  }
}

/* 'C' function for method : 'Navigation::Main.OnShortDownKeyActivated()' */
void NavigationMain_OnShortDownKeyActivated( NavigationMain _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* 'C' function for method : 'Navigation::Main.OnShortUpKeyActivated()' */
void NavigationMain_OnShortUpKeyActivated( NavigationMain _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* 'C' function for method : 'Navigation::Main.OnShortEnterKeyActivated()' */
void NavigationMain_OnShortEnterKeyActivated( NavigationMain _this )
{
  ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  ApplicationApplication_OnSetStatusBarVisible( App, 0 );
}

/* 'C' function for method : 'Navigation::Main.OnShortHomeKeyActivated()' */
void NavigationMain_OnShortHomeKeyActivated( NavigationMain _this )
{
  CoreGroup__DismissDialog( _this->Super4.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationMain_OnMapUpdateSlot( NavigationMain _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->MapFrameIdx = _this->MapFrameIdx + 1;
  ResourcesExternBitmap_OnSetName( EwGetAutoObject( &ResourceExternBitmap, ResourcesExternBitmap ), 
  EwConcatString( EwLoadString( &_Const0011 ), EwNewStringInt( _this->MapFrameIdx, 
  0, 10 )));
}

/* Variants derived from the class : 'Navigation::Main' */
EW_DEFINE_CLASS_VARIANTS( NavigationMain )
EW_END_OF_CLASS_VARIANTS( NavigationMain )

/* Virtual Method Table (VMT) for the class : 'Navigation::Main' */
EW_DEFINE_CLASS( NavigationMain, ComponentsBaseComponent, Background, Background, 
                 Background, Background, MapFrameIdx, MapFrameIdx, "Navigation::Main" )
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
  NavigationMain_OnShortDownKeyActivated,
  NavigationMain_OnShortUpKeyActivated,
  NavigationMain_OnShortEnterKeyActivated,
  NavigationMain_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
EW_END_OF_CLASS( NavigationMain )

/* Initializer for the class 'Navigation::NAV06_NaviSettingMenu' */
void NavigationNAV06_NaviSettingMenu__Init( NavigationNAV06_NaviSettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationNAV06_NaviSettingMenu );

  /* ... then construct all embedded objects */
  MenuVerticalMenu__Init( &_this->Menu, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationNAV06_NaviSettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Menu, _Const0012 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 7 );
  MenuVerticalMenu_OnSetArrowScrollBarVisible( &_this->Menu, 1 );
  _this->NaviSettings[ 0 ] = EnumNaviSettingItemStopNavigation;
  _this->NaviSettings[ 1 ] = EnumNaviSettingItemSkipNextStop;
  _this->NaviSettings[ 2 ] = EnumNaviSettingItemGoHome;
  _this->NaviSettings[ 3 ] = EnumNaviSettingItemGoToWork;
  _this->NaviSettings[ 4 ] = EnumNaviSettingItemFavorites;
  _this->NaviSettings[ 5 ] = EnumNaviSettingItemNearbyGasStations;
  _this->NaviSettings[ 6 ] = EnumNaviSettingItemChangeView;
  _this->IsDestSet = 1;
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );
}

/* Re-Initializer for the class 'Navigation::NAV06_NaviSettingMenu' */
void NavigationNAV06_NaviSettingMenu__ReInit( NavigationNAV06_NaviSettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  MenuVerticalMenu__ReInit( &_this->Menu );
}

/* Finalizer method for the class 'Navigation::NAV06_NaviSettingMenu' */
void NavigationNAV06_NaviSettingMenu__Done( NavigationNAV06_NaviSettingMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  MenuVerticalMenu__Done( &_this->Menu );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Navigation::NAV06_NaviSettingMenu.OnShortHomeKeyActivated()' */
void NavigationNAV06_NaviSettingMenu_OnShortHomeKeyActivated( NavigationNAV06_NaviSettingMenu _this )
{
  CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
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
      Title = EwLoadString( &StringsNAV06_stop_navigation );
    break;

    case EnumNaviSettingItemSkipNextStop :
      Title = EwLoadString( &StringsNAV06_stop_next_stop );
    break;

    case EnumNaviSettingItemGoHome :
      Title = EwLoadString( &StringsNAV06_go_home );
    break;

    case EnumNaviSettingItemGoToWork :
      Title = EwLoadString( &StringsNAV06_go_to_work );
    break;

    case EnumNaviSettingItemFavorites :
      Title = EwLoadString( &StringsNAV06_favorites );
    break;

    case EnumNaviSettingItemNearbyGasStations :
      Title = EwLoadString( &StringsNAV06_nearby_gas_stations );
    break;

    case EnumNaviSettingItemChangeView :
      Title = EwLoadString( &StringsNAV06_change_view );
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
  ComponentsBaseComponent Dialog;

  if ( aMenuItem == 0 )
    ;

  Dialog = 0;

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
      Dialog = ((ComponentsBaseComponent)EwNewObject( NavigationNAV08_NaviChageViewMenu, 
      0 ));
    break;

    default : 
      ;
  }

  if ( Dialog != 0 )
  {
    ComponentsBaseComponent_SlideInDialog((ComponentsBaseComponent)_this, ((CoreGroup)Dialog ));
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
EW_DEFINE_CLASS( NavigationNAV06_NaviSettingMenu, MenuBaseMenuView, Menu, Menu, 
                 Menu, Menu, NaviSettings, NaviSettings, "Navigation::NAV06_NaviSettingMenu" )
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
  NavigationNAV06_NaviSettingMenu_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  NavigationNAV06_NaviSettingMenu_LoadItemClass,
  NavigationNAV06_NaviSettingMenu_LoadItemTitle,
  NavigationNAV06_NaviSettingMenu_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  NavigationNAV06_NaviSettingMenu_LoadItemEnabled,
EW_END_OF_CLASS( NavigationNAV06_NaviSettingMenu )

/* Initializer for the class 'Navigation::NAV08_NaviChageViewMenu' */
void NavigationNAV08_NaviChageViewMenu__Init( NavigationNAV08_NaviChageViewMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationNAV08_NaviChageViewMenu );

  /* ... then construct all embedded objects */
  MenuVerticalMenu__Init( &_this->Menu, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->CheckMarkUpdateTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationNAV08_NaviChageViewMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Menu, _Const0012 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 3 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsNAV08_default_view ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsNAV08_turn_by_turn ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &StringsNAV08_turn_list ));
  _this->ItemCheckedArray[ 0 ] = 1;
  CoreTimer_OnSetPeriod( &_this->CheckMarkUpdateTimer, 450 );
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );
  _this->CheckMarkUpdateTimer.OnTrigger = EwNewSlot( _this, NavigationNAV08_NaviChageViewMenu_OnCheckMarkUpdateSlot );
}

/* Re-Initializer for the class 'Navigation::NAV08_NaviChageViewMenu' */
void NavigationNAV08_NaviChageViewMenu__ReInit( NavigationNAV08_NaviChageViewMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  MenuVerticalMenu__ReInit( &_this->Menu );
  CoreTimer__ReInit( &_this->CheckMarkUpdateTimer );
}

/* Finalizer method for the class 'Navigation::NAV08_NaviChageViewMenu' */
void NavigationNAV08_NaviChageViewMenu__Done( NavigationNAV08_NaviChageViewMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  MenuVerticalMenu__Done( &_this->Menu );
  CoreTimer__Done( &_this->CheckMarkUpdateTimer );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Navigation::NAV08_NaviChageViewMenu.OnShortHomeKeyActivated()' */
void NavigationNAV08_NaviChageViewMenu_OnShortHomeKeyActivated( NavigationNAV08_NaviChageViewMenu _this )
{
  CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
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
  XInt32 i;

  if ( aMenuItem == 0 )
    ;

  i = 0;

  for ( i = 0; i < 3; i++ )
  {
    if ( i == aItemNo )
    {
      _this->ItemCheckedArray[ EwCheckIndex( i, 3 )] = 1;
    }
    else
    {
      _this->ItemCheckedArray[ EwCheckIndex( i, 3 )] = 0;
    }
  }

  MenuVerticalMenu_InvalidateItems( &_this->Menu, 0, 2 );
  CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 1 );
  _this->NaviScreenIdx = aItemNo;
}

/* 'C' function for method : 'Navigation::NAV08_NaviChageViewMenu.LoadItemChecked()' */
XBool NavigationNAV08_NaviChageViewMenu_LoadItemChecked( NavigationNAV08_NaviChageViewMenu _this, 
  XInt32 aItemNo )
{
  XBool IsChecked = 0;

  if ( aItemNo < 3 )
  {
    IsChecked = _this->ItemCheckedArray[ EwCheckIndex( aItemNo, 3 )];
  }

  return IsChecked;
}

/* 'C' function for method : 'Navigation::NAV08_NaviChageViewMenu.OnCheckMarkUpdateSlot()' */
void NavigationNAV08_NaviChageViewMenu_OnCheckMarkUpdateSlot( NavigationNAV08_NaviChageViewMenu _this, 
  XObject sender )
{
  ComponentsBaseComponent Dialog;
  ApplicationApplication App;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->CheckMarkUpdateTimer, 0 );
  Dialog = 0;
  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  switch ( _this->NaviScreenIdx )
  {
    case 0 :
    {
      Dialog = ((ComponentsBaseComponent)EwNewObject( NavigationMain, 0 ));
      ApplicationApplication_SwitchToHome( App, ((CoreGroup)Dialog ));
    }
    break;

    case 1 :
      ;
    break;

    case 2 :
      ;
    break;

    default : 
      ;
  }
}

/* Variants derived from the class : 'Navigation::NAV08_NaviChageViewMenu' */
EW_DEFINE_CLASS_VARIANTS( NavigationNAV08_NaviChageViewMenu )
EW_END_OF_CLASS_VARIANTS( NavigationNAV08_NaviChageViewMenu )

/* Virtual Method Table (VMT) for the class : 'Navigation::NAV08_NaviChageViewMenu' */
EW_DEFINE_CLASS( NavigationNAV08_NaviChageViewMenu, MenuBaseMenuView, Menu, Menu, 
                 Menu, Menu, ItemTitleArray, NaviScreenIdx, "Navigation::NAV08_NaviChageViewMenu" )
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
  NavigationNAV08_NaviChageViewMenu_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  NavigationNAV08_NaviChageViewMenu_LoadItemClass,
  NavigationNAV08_NaviChageViewMenu_LoadItemTitle,
  NavigationNAV08_NaviChageViewMenu_OnItemActivate,
  NavigationNAV08_NaviChageViewMenu_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
EW_END_OF_CLASS( NavigationNAV08_NaviChageViewMenu )

/* Embedded Wizard */
