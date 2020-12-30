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
#include "_CorePropertyObserver.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreView.h"
#include "_DeviceInterfaceMediaManagerDeviceClass.h"
#include "_MediaMain.h"
#include "_MediaTrack.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "_WidgetSetHorizontalSlider.h"
#include "_WidgetSetHorizontalSliderConfig.h"
#include "_WidgetSetPushButton.h"
#include "_WidgetSetPushButtonConfig.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Fonts.h"
#include "Media.h"
#include "Resource.h"
#include "UIConfig.h"
#include "Views.h"
#include "WidgetSet.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x0000001C, /* ratio 100.00 % */
  0xB8000900, 0x8005A452, 0xEA090283, 0x61200838, 0x230C1811, 0x00000406, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XColor _Const0001 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0002 = {{ 80, 36 }, { 410, 76 }};
static const XRect _Const0003 = {{ 200, 200 }, { 290, 250 }};
static const XRect _Const0004 = {{ 80, 200 }, { 170, 250 }};
static const XRect _Const0005 = {{ 310, 200 }, { 400, 250 }};
static const XRect _Const0006 = {{ 80, 80 }, { 410, 120 }};
static const XRect _Const0007 = {{ 80, 121 }, { 410, 161 }};
static const XRect _Const0008 = {{ 90, 150 }, { 400, 200 }};
static const XRect _Const0009 = {{ 10, 160 }, { 80, 190 }};
static const XRect _Const000A = {{ 400, 160 }, { 470, 190 }};
static const XStringRes _Const000B = { _StringsDefault0, 0x0002 };
static const XStringRes _Const000C = { _StringsDefault0, 0x0006 };
static const XStringRes _Const000D = { _StringsDefault0, 0x000A };
static const XRect _Const000E = {{ 0, 0 }, { 300, 200 }};

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

/* Initializer for the class 'Media::Main' */
void MediaMain__Init( MediaMain _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MediaMain );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Title, &_this->_XObject, 0 );
  WidgetSetPushButton__Init( &_this->PlayPauseButton, &_this->_XObject, 0 );
  WidgetSetPushButton__Init( &_this->PrevTrackButton, &_this->_XObject, 0 );
  WidgetSetPushButton__Init( &_this->NextTrackButton, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Artist, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Album, &_this->_XObject, 0 );
  WidgetSetHorizontalSlider__Init( &_this->PlayProgress, &_this->_XObject, 0 );
  ViewsText__Init( &_this->ElapsedTimeSec, &_this->_XObject, 0 );
  ViewsText__Init( &_this->RemainTimeSec, &_this->_XObject, 0 );
  MediaTrack__Init( &_this->Track, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->PlaybackTimeEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MediaMain );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0001 );
  CoreRectView__OnSetBounds( &_this->Title, _Const0002 );
  ViewsText_OnSetEllipsis( &_this->Title, 1 );
  ViewsText_OnSetAlignment( &_this->Title, ViewsTextAlignmentAlignHorzLeft | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Title, 0 );
  CoreRectView__OnSetBounds( &_this->PlayPauseButton, _Const0003 );
  WidgetSetPushButton_OnSetIconFrameActive( &_this->PlayPauseButton, 1 );
  WidgetSetPushButton_OnSetIconFrameDefault( &_this->PlayPauseButton, 0 );
  WidgetSetPushButton_OnSetIconFrame( &_this->PlayPauseButton, -1 );
  WidgetSetPushButton_OnSetLabel( &_this->PlayPauseButton, 0 );
  CoreRectView__OnSetBounds( &_this->PrevTrackButton, _Const0004 );
  WidgetSetPushButton_OnSetIconFrameActive( &_this->PrevTrackButton, 1 );
  WidgetSetPushButton_OnSetIconFrame( &_this->PrevTrackButton, 0 );
  WidgetSetPushButton_OnSetLabel( &_this->PrevTrackButton, 0 );
  CoreRectView__OnSetBounds( &_this->NextTrackButton, _Const0005 );
  WidgetSetPushButton_OnSetIconFrameActive( &_this->NextTrackButton, 1 );
  WidgetSetPushButton_OnSetIconFrame( &_this->NextTrackButton, 0 );
  WidgetSetPushButton_OnSetLabel( &_this->NextTrackButton, 0 );
  _this->FocusIdx = 1;
  CoreRectView__OnSetBounds( &_this->Artist, _Const0006 );
  ViewsText_OnSetEllipsis( &_this->Artist, 1 );
  ViewsText_OnSetAlignment( &_this->Artist, ViewsTextAlignmentAlignHorzLeft | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Artist, 0 );
  CoreRectView__OnSetBounds( &_this->Album, _Const0007 );
  ViewsText_OnSetEllipsis( &_this->Album, 1 );
  ViewsText_OnSetAlignment( &_this->Album, ViewsTextAlignmentAlignHorzLeft | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Album, 0 );
  CoreRectView__OnSetBounds( &_this->PlayProgress, _Const0008 );
  WidgetSetHorizontalSlider_OnSetStepSize( &_this->PlayProgress, 1 );
  WidgetSetHorizontalSlider_OnSetCurrentValue( &_this->PlayProgress, 0 );
  CoreRectView__OnSetBounds( &_this->ElapsedTimeSec, _Const0009 );
  ViewsText_OnSetString( &_this->ElapsedTimeSec, 0 );
  ViewsText_OnSetVisible( &_this->ElapsedTimeSec, 1 );
  CoreRectView__OnSetBounds( &_this->RemainTimeSec, _Const000A );
  ViewsText_OnSetString( &_this->RemainTimeSec, 0 );
  ViewsText_OnSetVisible( &_this->RemainTimeSec, 1 );
  CoreGroup_OnSetVisible((CoreGroup)&_this->Track, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Title ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PlayPauseButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PrevTrackButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTrackButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Artist ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Album ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PlayProgress ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ElapsedTimeSec ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RemainTimeSec ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Track ), 0 );
  ViewsText_OnSetFont( &_this->Title, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->PlayPauseButton.OnRelease = EwNewSlot( _this, MediaMain_OnPlayPauseSlot );
  WidgetSetPushButton_OnSetIcon( &_this->PlayPauseButton, EwLoadResource( &ResourceIconMediaPlayPause, 
  ResourcesBitmap ));
  WidgetSetPushButton_OnSetAppearance( &_this->PlayPauseButton, EwGetAutoObject( 
  &UIConfigPushButtonConfig, WidgetSetPushButtonConfig ));
  _this->PrevTrackButton.OnRelease = EwNewSlot( _this, MediaMain_OnPrevTrackSlot );
  WidgetSetPushButton_OnSetIcon( &_this->PrevTrackButton, EwLoadResource( &ResourceIconMediaPrevious, 
  ResourcesBitmap ));
  WidgetSetPushButton_OnSetAppearance( &_this->PrevTrackButton, EwGetAutoObject( 
  &UIConfigPushButtonConfig, WidgetSetPushButtonConfig ));
  _this->NextTrackButton.OnRelease = EwNewSlot( _this, MediaMain_OnNextTrackSlot );
  WidgetSetPushButton_OnSetIcon( &_this->NextTrackButton, EwLoadResource( &ResourceIconMediaNext, 
  ResourcesBitmap ));
  WidgetSetPushButton_OnSetAppearance( &_this->NextTrackButton, EwGetAutoObject( 
  &UIConfigPushButtonConfig, WidgetSetPushButtonConfig ));
  _this->FocusList[ 0 ] = ((CoreView)&_this->PrevTrackButton );
  _this->FocusList[ 1 ] = ((CoreView)&_this->PlayPauseButton );
  _this->FocusList[ 2 ] = ((CoreView)&_this->NextTrackButton );
  ViewsText_OnSetFont( &_this->Artist, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->Album, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  WidgetSetHorizontalSlider_OnSetAppearance( &_this->PlayProgress, EwGetAutoObject( 
  &WidgetSetHorizontalSlider_Small, WidgetSetHorizontalSliderConfig ));
  ViewsText_OnSetFont( &_this->ElapsedTimeSec, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->RemainTimeSec, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->Track.OnTrackInfoUpdate = EwNewSlot( _this, MediaMain_SetTrackInfo );
  _this->PlaybackTimeEventHandler.OnEvent = EwNewSlot( _this, MediaMain_OnPlaybackTimeUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->PlaybackTimeEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->NotifyPlayBackTimeChangedSystemEvent );

  /* Call the user defined constructor */
  MediaMain_Init( _this, aArg );
}

/* Re-Initializer for the class 'Media::Main' */
void MediaMain__ReInit( MediaMain _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsText__ReInit( &_this->Title );
  WidgetSetPushButton__ReInit( &_this->PlayPauseButton );
  WidgetSetPushButton__ReInit( &_this->PrevTrackButton );
  WidgetSetPushButton__ReInit( &_this->NextTrackButton );
  ViewsText__ReInit( &_this->Artist );
  ViewsText__ReInit( &_this->Album );
  WidgetSetHorizontalSlider__ReInit( &_this->PlayProgress );
  ViewsText__ReInit( &_this->ElapsedTimeSec );
  ViewsText__ReInit( &_this->RemainTimeSec );
  MediaTrack__ReInit( &_this->Track );
  CoreSystemEventHandler__ReInit( &_this->PlaybackTimeEventHandler );
}

/* Finalizer method for the class 'Media::Main' */
void MediaMain__Done( MediaMain _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsText__Done( &_this->Title );
  WidgetSetPushButton__Done( &_this->PlayPauseButton );
  WidgetSetPushButton__Done( &_this->PrevTrackButton );
  WidgetSetPushButton__Done( &_this->NextTrackButton );
  ViewsText__Done( &_this->Artist );
  ViewsText__Done( &_this->Album );
  WidgetSetHorizontalSlider__Done( &_this->PlayProgress );
  ViewsText__Done( &_this->ElapsedTimeSec );
  ViewsText__Done( &_this->RemainTimeSec );
  MediaTrack__Done( &_this->Track );
  CoreSystemEventHandler__Done( &_this->PlaybackTimeEventHandler );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void MediaMain_Init( MediaMain _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->IsInit 
  = 1;
  DeviceInterfaceMediaManagerDeviceClass_GetPlayerInfo( EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
  DeviceInterfaceMediaManagerDeviceClass ));
  DeviceInterfaceMediaManagerDeviceClass_GetPlaybackInfo( EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
  DeviceInterfaceMediaManagerDeviceClass ));
  DeviceInterfaceMediaManagerDeviceClass_GetTrackInfo( EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
  DeviceInterfaceMediaManagerDeviceClass ));
  EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->IsInit 
  = 0;

  if ( EwCompString( 0, EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->Title ) 
      != 0 )
  {
    EwSignal( EwNewSlot( _this, MediaMain_OnPlaybackTimeUpdateSlot ), ((XObject)_this ));
  }
}

/* 'C' function for method : 'Media::Main.OnLongKeyPressed()' */
void MediaMain_OnLongKeyPressed( MediaMain _this, XObject sender )
{
  EwSignal( _this->Super1.PassKeyHold, sender );
}

/* 'C' function for method : 'Media::Main.OnShortDownKeyPressed()' */
void MediaMain_OnShortDownKeyPressed( MediaMain _this )
{
  XInt32 NextFocusIdx = _this->FocusIdx + 1;

  if ( NextFocusIdx >= 3 )
  {
    NextFocusIdx = 2;
  }

  if ( _this->FocusIdx != NextFocusIdx )
  {
    _this->FocusIdx = NextFocusIdx;
    CoreGroup__OnSetFocus( _this, _this->FocusList[ EwCheckIndex( NextFocusIdx, 
    3 )]);
  }
}

/* 'C' function for method : 'Media::Main.OnShortUpKeyPressed()' */
void MediaMain_OnShortUpKeyPressed( MediaMain _this )
{
  XInt32 NextFocusIdx = _this->FocusIdx - 1;

  if ( NextFocusIdx < 0 )
  {
    NextFocusIdx = 0;
  }

  if ( _this->FocusIdx != NextFocusIdx )
  {
    _this->FocusIdx = NextFocusIdx;
    CoreGroup__OnSetFocus( _this, _this->FocusList[ EwCheckIndex( NextFocusIdx, 
    3 )]);
  }
}

/* 'C' function for method : 'Media::Main.OnPlayPauseSlot()' */
void MediaMain_OnPlayPauseSlot( MediaMain _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( 0 == _this->Track.PlaybackState )
  {
    DeviceInterfaceMediaManagerDeviceClass_SendRemoteCommand( EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
    DeviceInterfaceMediaManagerDeviceClass ), EnumCommandTypePlay );
  }
  else
  {
    DeviceInterfaceMediaManagerDeviceClass_SendRemoteCommand( EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
    DeviceInterfaceMediaManagerDeviceClass ), EnumCommandTypePause );
  }
}

/* 'C' function for method : 'Media::Main.OnPrevTrackSlot()' */
void MediaMain_OnPrevTrackSlot( MediaMain _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  MediaMain_ChangeTrack( _this );
  DeviceInterfaceMediaManagerDeviceClass_SendRemoteCommand( EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
  DeviceInterfaceMediaManagerDeviceClass ), EnumCommandTypePrevTrack );
}

/* 'C' function for method : 'Media::Main.OnNextTrackSlot()' */
void MediaMain_OnNextTrackSlot( MediaMain _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  MediaMain_ChangeTrack( _this );
  DeviceInterfaceMediaManagerDeviceClass_SendRemoteCommand( EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
  DeviceInterfaceMediaManagerDeviceClass ), EnumCommandTypeNextTrack );
}

/* 'C' function for method : 'Media::Main.SetTrackInfo()' */
void MediaMain_SetTrackInfo( MediaMain _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsText_OnSetString( &_this->Title, _this->Track.Title );
  ViewsText_OnSetString( &_this->Album, _this->Track.Album );
  ViewsText_OnSetString( &_this->Artist, _this->Track.Artist );
}

/* 'C' function for method : 'Media::Main.ChangeTrack()' */
void MediaMain_ChangeTrack( MediaMain _this )
{
  MediaTrack_ResetTrackInfo( &_this->Track );
  _this->Track.IsTrackInfoReset = 0;
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void MediaMain_OnPlaybackTimeUpdateSlot( MediaMain _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsText_OnSetString( &_this->ElapsedTimeSec, MediaMain_FormatTimeText( _this, 
  EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->ElapsedTimeSec ));
  ViewsText_OnSetString( &_this->RemainTimeSec, EwConcatString( EwLoadString( &_Const000B ), 
  MediaMain_FormatTimeText( _this, EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
  DeviceInterfaceMediaManagerDeviceClass )->RemainTimeSec )));

  if ( 0 != EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->DurationTimeSec )
  {
    WidgetSetHorizontalSlider_OnSetCurrentValue( &_this->PlayProgress, ( EwGetAutoObject( 
    &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->ElapsedTimeSec 
    * 100 ) / EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->DurationTimeSec );
  }
}

/* 'C' function for method : 'Media::Main.FormatTimeText()' */
XString MediaMain_FormatTimeText( MediaMain _this, XInt32 TimeSec )
{
  XInt32 Hour;
  XInt32 Minute;
  XInt32 Second;
  XString TimeText;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  Hour = TimeSec / 3600;
  Minute = ( TimeSec / 60 ) % 60;
  Second = TimeSec % 60;
  TimeText = 0;

  if ( Hour > 0 )
  {
    TimeText = EwConcatString( EwNewStringInt( Hour, 0, 10 ), EwLoadString( &_Const000C ));
  }

  TimeText = EwConcatString( EwConcatString( TimeText, EwNewStringInt( Minute, 0, 
  10 )), EwLoadString( &_Const000C ));

  if ( Second < 10 )
  {
    TimeText = EwConcatString( TimeText, EwLoadString( &_Const000D ));
  }

  TimeText = EwConcatString( TimeText, EwNewStringInt( Second, 0, 10 ));
  return TimeText;
}

/* Variants derived from the class : 'Media::Main' */
EW_DEFINE_CLASS_VARIANTS( MediaMain )
EW_END_OF_CLASS_VARIANTS( MediaMain )

/* Virtual Method Table (VMT) for the class : 'Media::Main' */
EW_DEFINE_CLASS( MediaMain, ComponentsBaseComponent, FocusList, Rectangle, Rectangle, 
                 Rectangle, FocusIdx, FocusIdx, "Media::Main" )
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
  MediaMain_OnLongKeyPressed,
  MediaMain_OnShortDownKeyPressed,
  MediaMain_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
  ComponentsBaseComponent_OnShortHomeKeyPressed,
EW_END_OF_CLASS( MediaMain )

/* Initializer for the class 'Media::Track' */
void MediaTrack__Init( MediaTrack _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MediaTrack );

  /* ... then construct all embedded objects */
  CorePropertyObserver__Init( &_this->TitleObserver, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->AlbumObserver, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->ArtistObserver, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->PlayStateObserver, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MediaTrack );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const000E );
  _this->TitleObserver.OnEvent = EwNewSlot( _this, MediaTrack_OnTrackInfoUpdateSlot );
  CorePropertyObserver_OnSetOutlet( &_this->TitleObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass ), 
  DeviceInterfaceMediaManagerDeviceClass_OnGetTitle, DeviceInterfaceMediaManagerDeviceClass_OnSetTitle ));
  _this->AlbumObserver.OnEvent = EwNewSlot( _this, MediaTrack_OnTrackInfoUpdateSlot );
  CorePropertyObserver_OnSetOutlet( &_this->AlbumObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass ), 
  DeviceInterfaceMediaManagerDeviceClass_OnGetAlbum, DeviceInterfaceMediaManagerDeviceClass_OnSetAlbum ));
  _this->ArtistObserver.OnEvent = EwNewSlot( _this, MediaTrack_OnTrackInfoUpdateSlot );
  CorePropertyObserver_OnSetOutlet( &_this->ArtistObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass ), 
  DeviceInterfaceMediaManagerDeviceClass_OnGetArtist, DeviceInterfaceMediaManagerDeviceClass_OnSetArtist ));
  _this->PlayStateObserver.OnEvent = EwNewSlot( _this, MediaTrack_OnTrackInfoUpdateSlot );
  CorePropertyObserver_OnSetOutlet( &_this->PlayStateObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass ), 
  DeviceInterfaceMediaManagerDeviceClass_OnGetPlaybackState, DeviceInterfaceMediaManagerDeviceClass_OnSetPlaybackState ));
}

/* Re-Initializer for the class 'Media::Track' */
void MediaTrack__ReInit( MediaTrack _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CorePropertyObserver__ReInit( &_this->TitleObserver );
  CorePropertyObserver__ReInit( &_this->AlbumObserver );
  CorePropertyObserver__ReInit( &_this->ArtistObserver );
  CorePropertyObserver__ReInit( &_this->PlayStateObserver );
}

/* Finalizer method for the class 'Media::Track' */
void MediaTrack__Done( MediaTrack _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  CorePropertyObserver__Done( &_this->TitleObserver );
  CorePropertyObserver__Done( &_this->AlbumObserver );
  CorePropertyObserver__Done( &_this->ArtistObserver );
  CorePropertyObserver__Done( &_this->PlayStateObserver );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* 'C' function for method : 'Media::Track.ResetTrackInfo()' */
void MediaTrack_ResetTrackInfo( MediaTrack _this )
{
  _this->IsTrackInfoReset = 1;
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void MediaTrack_OnTrackInfoUpdateSlot( MediaTrack _this, XObject sender )
{
  if ( !_this->IsTrackInfoReset )
  {
    if ( sender == ((XObject)&_this->TitleObserver ))
    {
      _this->Title = EwShareString( EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
      DeviceInterfaceMediaManagerDeviceClass )->Title );
    }
    else
      if ( sender == ((XObject)&_this->AlbumObserver ))
      {
        _this->Album = EwShareString( EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
        DeviceInterfaceMediaManagerDeviceClass )->Album );
      }
      else
        if ( sender == ((XObject)&_this->ArtistObserver ))
        {
          _this->Artist = EwShareString( EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
          DeviceInterfaceMediaManagerDeviceClass )->Artist );
        }
        else
          if ( sender == ((XObject)&_this->PlayStateObserver ))
          {
            _this->PlaybackState = EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
            DeviceInterfaceMediaManagerDeviceClass )->PlaybackState;
          }

    EwPostSignal( _this->OnTrackInfoUpdate, ((XObject)_this ));
  }
}

/* Variants derived from the class : 'Media::Track' */
EW_DEFINE_CLASS_VARIANTS( MediaTrack )
EW_END_OF_CLASS_VARIANTS( MediaTrack )

/* Virtual Method Table (VMT) for the class : 'Media::Track' */
EW_DEFINE_CLASS( MediaTrack, CoreGroup, OnTrackInfoUpdate, OnTrackInfoUpdate, TitleObserver, 
                 TitleObserver, Artist, PlaybackState, "Media::Track" )
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
EW_END_OF_CLASS( MediaTrack )

/* Embedded Wizard */
