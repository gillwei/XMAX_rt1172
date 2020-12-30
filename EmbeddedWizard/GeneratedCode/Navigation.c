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
#include "_CoreGroup.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreView.h"
#include "_DeviceInterfaceNavigationDeviceClass.h"
#include "_NavigationGarmin.h"
#include "_NavigationMain.h"
#include "_NavigationYMC.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesExternBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "DeviceInterface.h"
#include "Fonts.h"
#include "Navigation.h"
#include "Resource.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x000000A2, /* ratio 76.54 % */
  0xB8000D00, 0x00062452, 0x00660019, 0x60614858, 0xD2002691, 0x20037000, 0x003A800E,
  0x00044CC2, 0x32802062, 0xA000E600, 0x148011C3, 0x02326F00, 0xC010B320, 0x00418703,
  0x111991C8, 0x6C951D80, 0xD9A9524A, 0x044B63E6, 0x00C20D0E, 0xC18003A0, 0x380B2D1A,
  0x2173D8D4, 0x014D8701, 0x51082408, 0x53969C23, 0x0001648B, 0x04CB4871, 0x9CA88F0E,
  0xC52253D9, 0x02032D96, 0x00000000
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
static const XRect _Const0012 = {{ 2, 0 }, { 82, 30 }};
static const XStringRes _Const0013 = { _StringsDefault0, 0x0042 };
static const XRect _Const0014 = {{ 2, 0 }, { 102, 30 }};
static const XStringRes _Const0015 = { _StringsDefault0, 0x0048 };

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

/* 'C' function for method : 'Navigation::Main.OnLongKeyPressed()' */
void NavigationMain_OnLongKeyPressed( NavigationMain _this, XObject sender )
{
  EwSignal( _this->Super1.PassKeyHold, sender );
}

/* 'C' function for method : 'Navigation::Main.OnShortDownKeyPressed()' */
void NavigationMain_OnShortDownKeyPressed( NavigationMain _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* 'C' function for method : 'Navigation::Main.OnShortUpKeyPressed()' */
void NavigationMain_OnShortUpKeyPressed( NavigationMain _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* 'C' function for method : 'Navigation::Main.OnShortEnterKeyPressed()' */
void NavigationMain_OnShortEnterKeyPressed( NavigationMain _this )
{
  ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );
  NavigationYMC Pictures;

  ApplicationApplication_OnSetStatusBarVisible( App, 0 );
  Pictures = EwNewObject( NavigationYMC, 0 );
  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)Pictures ), 0, 0, 0, 0, 
  0, 0, EwNullSlot, EwNullSlot, 0 );
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
  NavigationMain_OnLongKeyPressed,
  NavigationMain_OnShortDownKeyPressed,
  NavigationMain_OnShortUpKeyPressed,
  NavigationMain_OnShortEnterKeyPressed,
  ComponentsBaseComponent_OnShortHomeKeyPressed,
EW_END_OF_CLASS( NavigationMain )

/* Initializer for the class 'Navigation::YMC' */
void NavigationYMC__Init( NavigationYMC _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationYMC );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->Image, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationYMC );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Image, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0012 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzLeft | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const0013 ));
  CoreGroup__Add( _this, ((CoreView)&_this->Image ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceYmcNaviDay, ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Navigation::YMC' */
void NavigationYMC__ReInit( NavigationYMC _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->Image );
  ViewsText__ReInit( &_this->Text );
}

/* Finalizer method for the class 'Navigation::YMC' */
void NavigationYMC__Done( NavigationYMC _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->Image );
  ViewsText__Done( &_this->Text );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* 'C' function for method : 'Navigation::YMC.OnShortDownKeyPressed()' */
void NavigationYMC_OnShortDownKeyPressed( NavigationYMC _this )
{
  XInt32 NextIdx = _this->PictureIdx + 1;

  if ( NextIdx >= 9 )
  {
    NextIdx = 0;
  }

  NavigationYMC_OnSetPictureIdx( _this, NextIdx );
}

/* 'C' function for method : 'Navigation::YMC.OnShortUpKeyPressed()' */
void NavigationYMC_OnShortUpKeyPressed( NavigationYMC _this )
{
  XInt32 PreviousIdx = _this->PictureIdx - 1;

  if ( PreviousIdx < 0 )
  {
    PreviousIdx = 8;
  }

  NavigationYMC_OnSetPictureIdx( _this, PreviousIdx );
}

/* 'C' function for method : 'Navigation::YMC.OnShortEnterKeyPressed()' */
void NavigationYMC_OnShortEnterKeyPressed( NavigationYMC _this )
{
  NavigationGarmin GarminScreen = EwNewObject( NavigationGarmin, 0 );

  CoreGroup_SwitchToDialog( _this->Super4.Owner, ((CoreGroup)GarminScreen ), 0, 
  0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Navigation::YMC.OnSetPictureIdx()' */
void NavigationYMC_OnSetPictureIdx( NavigationYMC _this, XInt32 value )
{
  if ( _this->PictureIdx != value )
  {
    _this->PictureIdx = value;

    switch ( _this->PictureIdx )
    {
      case 0 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceYmcNaviDay, 
        ResourcesBitmap ));
      break;

      case 1 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceYmcNaviNight, 
        ResourcesBitmap ));
      break;

      case 2 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceYmcRouteDay, 
        ResourcesBitmap ));
      break;

      case 3 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceYmcRouteNight, 
        ResourcesBitmap ));
      break;

      case 4 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceYmcTurnList, 
        ResourcesBitmap ));
      break;

      case 5 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceYmcNextTurnDay, 
        ResourcesBitmap ));
      break;

      case 6 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceYmcNextTurnNight, 
        ResourcesBitmap ));
      break;

      case 7 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceYmcTbTDay, 
        ResourcesBitmap ));
      break;

      case 8 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceYmcTbTNight, 
        ResourcesBitmap ));
      break;

      default : 
        ;
    }
  }
}

/* Variants derived from the class : 'Navigation::YMC' */
EW_DEFINE_CLASS_VARIANTS( NavigationYMC )
EW_END_OF_CLASS_VARIANTS( NavigationYMC )

/* Virtual Method Table (VMT) for the class : 'Navigation::YMC' */
EW_DEFINE_CLASS( NavigationYMC, ComponentsBaseComponent, Image, Image, Image, Image, 
                 PictureIdx, PictureIdx, "Navigation::YMC" )
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
  ComponentsBaseComponent_OnLongKeyPressed,
  NavigationYMC_OnShortDownKeyPressed,
  NavigationYMC_OnShortUpKeyPressed,
  NavigationYMC_OnShortEnterKeyPressed,
  ComponentsBaseComponent_OnShortHomeKeyPressed,
EW_END_OF_CLASS( NavigationYMC )

/* Initializer for the class 'Navigation::Garmin' */
void NavigationGarmin__Init( NavigationGarmin _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NavigationGarmin );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->Image, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NavigationGarmin );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Image, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0014 );
  ViewsText_OnSetAlignment( &_this->Text, ViewsTextAlignmentAlignHorzLeft | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const0015 ));
  CoreGroup__Add( _this, ((CoreView)&_this->Image ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceGrmnNaviDay, ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Navigation::Garmin' */
void NavigationGarmin__ReInit( NavigationGarmin _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->Image );
  ViewsText__ReInit( &_this->Text );
}

/* Finalizer method for the class 'Navigation::Garmin' */
void NavigationGarmin__Done( NavigationGarmin _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->Image );
  ViewsText__Done( &_this->Text );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* 'C' function for method : 'Navigation::Garmin.OnShortDownKeyPressed()' */
void NavigationGarmin_OnShortDownKeyPressed( NavigationGarmin _this )
{
  XInt32 NextIdx = _this->PictureIdx + 1;

  if ( NextIdx >= 9 )
  {
    NextIdx = 0;
  }

  NavigationGarmin_OnSetPictureIdx( _this, NextIdx );
}

/* 'C' function for method : 'Navigation::Garmin.OnShortUpKeyPressed()' */
void NavigationGarmin_OnShortUpKeyPressed( NavigationGarmin _this )
{
  XInt32 PreviousIdx = _this->PictureIdx - 1;

  if ( PreviousIdx < 0 )
  {
    PreviousIdx = 8;
  }

  NavigationGarmin_OnSetPictureIdx( _this, PreviousIdx );
}

/* 'C' function for method : 'Navigation::Garmin.OnShortEnterKeyPressed()' */
void NavigationGarmin_OnShortEnterKeyPressed( NavigationGarmin _this )
{
  ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  ApplicationApplication_OnSetStatusBarVisible( App, 1 );
  CoreGroup__DismissDialog( _this->Super4.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Navigation::Garmin.OnSetPictureIdx()' */
void NavigationGarmin_OnSetPictureIdx( NavigationGarmin _this, XInt32 value )
{
  if ( _this->PictureIdx != value )
  {
    _this->PictureIdx = value;

    switch ( _this->PictureIdx )
    {
      case 0 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceGrmnNaviDay, 
        ResourcesBitmap ));
      break;

      case 1 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceGrmnNaviNight, 
        ResourcesBitmap ));
      break;

      case 2 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceGrmnRouteDay, 
        ResourcesBitmap ));
      break;

      case 3 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceGrmnRouteNight, 
        ResourcesBitmap ));
      break;

      case 4 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceGrmnTurnList, 
        ResourcesBitmap ));
      break;

      case 5 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceGrmnNextTurnDay, 
        ResourcesBitmap ));
      break;

      case 6 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceGrmnNextTurnNight, 
        ResourcesBitmap ));
      break;

      case 7 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceGrmnTbTDay, 
        ResourcesBitmap ));
      break;

      case 8 :
        ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourceGrmnTbTNight, 
        ResourcesBitmap ));
      break;

      default : 
        ;
    }
  }
}

/* Variants derived from the class : 'Navigation::Garmin' */
EW_DEFINE_CLASS_VARIANTS( NavigationGarmin )
EW_END_OF_CLASS_VARIANTS( NavigationGarmin )

/* Virtual Method Table (VMT) for the class : 'Navigation::Garmin' */
EW_DEFINE_CLASS( NavigationGarmin, ComponentsBaseComponent, Image, Image, Image, 
                 Image, PictureIdx, PictureIdx, "Navigation::Garmin" )
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
  ComponentsBaseComponent_OnLongKeyPressed,
  NavigationGarmin_OnShortDownKeyPressed,
  NavigationGarmin_OnShortUpKeyPressed,
  NavigationGarmin_OnShortEnterKeyPressed,
  ComponentsBaseComponent_OnShortHomeKeyPressed,
EW_END_OF_CLASS( NavigationGarmin )

/* Embedded Wizard */
