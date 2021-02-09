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
#include "_CoreSystemEventHandler.h"
#include "_CoreView.h"
#include "_DeviceInterfaceRtcTime.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_StatusBarClock.h"
#include "_StatusBarMain.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "DeviceInterface.h"
#include "Fonts.h"
#include "Resource.h"
#include "StatusBar.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x0000000C, /* ratio 166.67 % */
  0xB8000900, 0x80074452, 0x04010883, 0x00000004, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 38 }};
static const XColor _Const0001 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0002 = {{ 0, 36 }, { 480, 38 }};
static const XRect _Const0003 = {{ 11, 0 }, { 93, 38 }};
static const XRect _Const0004 = {{ 0, 0 }, { 82, 38 }};
static const XRect _Const0005 = {{ 0, 1 }, { 37, 38 }};
static const XColor _Const0006 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const0007 = {{ 45, 1 }, { 82, 38 }};
static const XRect _Const0008 = {{ 37, 1 }, { 48, 38 }};
static const XStringRes _Const0009 = { _StringsDefault0, 0x0002 };

/* Initializer for the class 'StatusBar::Main' */
void StatusBarMain__Init( StatusBarMain _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( StatusBarMain );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Background, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Divider, &_this->_XObject, 0 );
  StatusBarClock__Init( &_this->Clock, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( StatusBarMain );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Background, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Background, _Const0001 );
  CoreRectView__OnSetBounds( &_this->Divider, _Const0002 );
  ViewsImage_OnSetAlignment( &_this->Divider, ViewsImageAlignmentAlignVertBottom 
  | ViewsImageAlignmentScaleToFit );
  CoreRectView__OnSetBounds( &_this->Clock, _Const0003 );
  CoreGroup__Add( _this, ((CoreView)&_this->Background ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Clock ), 0 );
  ViewsImage_OnSetBitmap( &_this->Divider, EwLoadResource( &ResourceStatusBarDivider, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'StatusBar::Main' */
void StatusBarMain__ReInit( StatusBarMain _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Background );
  ViewsImage__ReInit( &_this->Divider );
  StatusBarClock__ReInit( &_this->Clock );
}

/* Finalizer method for the class 'StatusBar::Main' */
void StatusBarMain__Done( StatusBarMain _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Background );
  ViewsImage__Done( &_this->Divider );
  StatusBarClock__Done( &_this->Clock );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* Variants derived from the class : 'StatusBar::Main' */
EW_DEFINE_CLASS_VARIANTS( StatusBarMain )
EW_END_OF_CLASS_VARIANTS( StatusBarMain )

/* Virtual Method Table (VMT) for the class : 'StatusBar::Main' */
EW_DEFINE_CLASS( StatusBarMain, CoreGroup, Background, Background, Background, Background, 
                 _None, _None, "StatusBar::Main" )
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
EW_END_OF_CLASS( StatusBarMain )

/* Initializer for the class 'StatusBar::Clock' */
void StatusBarClock__Init( StatusBarClock _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( StatusBarClock );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->ClockHourText, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->OnUpdateLocalTimeEventHandler, &_this->_XObject, 0 );
  ViewsText__Init( &_this->ClockMinuteText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->ClockColonText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( StatusBarClock );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0004 );
  CoreRectView__OnSetBounds( &_this->ClockHourText, _Const0005 );
  ViewsText_OnSetAlignment( &_this->ClockHourText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ClockHourText, 0 );
  ViewsText_OnSetColor( &_this->ClockHourText, _Const0006 );
  ViewsText_OnSetVisible( &_this->ClockHourText, 1 );
  CoreRectView__OnSetBounds( &_this->ClockMinuteText, _Const0007 );
  ViewsText_OnSetAlignment( &_this->ClockMinuteText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ClockMinuteText, 0 );
  ViewsText_OnSetColor( &_this->ClockMinuteText, _Const0006 );
  ViewsText_OnSetVisible( &_this->ClockMinuteText, 1 );
  CoreRectView__OnSetBounds( &_this->ClockColonText, _Const0008 );
  ViewsText_OnSetAlignment( &_this->ClockColonText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ClockColonText, EwLoadString( &_Const0009 ));
  ViewsText_OnSetColor( &_this->ClockColonText, _Const0006 );
  ViewsText_OnSetVisible( &_this->ClockColonText, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ClockHourText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ClockMinuteText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ClockColonText ), 0 );
  ViewsText_OnSetFont( &_this->ClockHourText, EwLoadResource( &FontsNotoSansMedium32pt, 
  ResourcesFont ));
  _this->OnUpdateLocalTimeEventHandler.OnEvent = EwNewSlot( _this, StatusBarClock_OnUpdateLocalTimeSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->OnUpdateLocalTimeEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->UpdateLocalTimeSystemEvent );
  ViewsText_OnSetFont( &_this->ClockMinuteText, EwLoadResource( &FontsNotoSansMedium32pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->ClockColonText, EwLoadResource( &FontsNotoSansMedium32pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'StatusBar::Clock' */
void StatusBarClock__ReInit( StatusBarClock _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->ClockHourText );
  CoreSystemEventHandler__ReInit( &_this->OnUpdateLocalTimeEventHandler );
  ViewsText__ReInit( &_this->ClockMinuteText );
  ViewsText__ReInit( &_this->ClockColonText );
}

/* Finalizer method for the class 'StatusBar::Clock' */
void StatusBarClock__Done( StatusBarClock _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->ClockHourText );
  CoreSystemEventHandler__Done( &_this->OnUpdateLocalTimeEventHandler );
  ViewsText__Done( &_this->ClockMinuteText );
  ViewsText__Done( &_this->ClockColonText );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* 'C' function for method : 'StatusBar::Clock.OnUpdateLocalTimeSlot()' */
void StatusBarClock_OnUpdateLocalTimeSlot( StatusBarClock _this, XObject sender )
{
  DeviceInterfaceRtcTime CurrentTime;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CurrentTime = DeviceInterfaceSystemDeviceClass_GetLocalTime( EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ));

  if ( CurrentTime->Hour > 12 )
  {
    CurrentTime->Hour = (XUInt8)( CurrentTime->Hour - 12 );
  }

  ViewsText_OnSetString( &_this->ClockHourText, EwNewStringInt( CurrentTime->Hour, 
  0, 10 ));
  ViewsText_OnSetString( &_this->ClockMinuteText, EwNewStringInt( CurrentTime->Minute, 
  2, 10 ));
  ViewsText_OnSetVisible( &_this->ClockColonText, (XBool)!ViewsText_OnGetVisible( 
  &_this->ClockColonText ));
}

/* Variants derived from the class : 'StatusBar::Clock' */
EW_DEFINE_CLASS_VARIANTS( StatusBarClock )
EW_END_OF_CLASS_VARIANTS( StatusBarClock )

/* Virtual Method Table (VMT) for the class : 'StatusBar::Clock' */
EW_DEFINE_CLASS( StatusBarClock, CoreGroup, ClockHourText, ClockHourText, ClockHourText, 
                 ClockHourText, _None, _None, "StatusBar::Clock" )
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
EW_END_OF_CLASS( StatusBarClock )

/* Embedded Wizard */
