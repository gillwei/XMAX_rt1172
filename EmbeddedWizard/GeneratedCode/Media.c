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
#include "_CoreGroup.h"
#include "_CorePropertyObserver.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DeviceInterfaceMediaManagerDeviceClass.h"
#include "_MediaMED01_MediaUI.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsText.h"
#include "_WidgetSetHorizontalSlider.h"
#include "_WidgetSetHorizontalSliderConfig.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Fonts.h"
#include "Media.h"
#include "Resource.h"
#include "Strings.h"
#include "UIConfig.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000014, /* ratio 120.00 % */
  0xB8000900, 0x80074452, 0xC2090283, 0x60F0C838, 0x00000040, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0001 = {{ 127, 69 }, { 457, 103 }};
static const XRect _Const0002 = {{ 127, 114 }, { 457, 148 }};
static const XRect _Const0003 = {{ 127, 153 }, { 457, 187 }};
static const XRect _Const0004 = {{ 127, 226 }, { 204, 256 }};
static const XRect _Const0005 = {{ 364, 226 }, { 441, 256 }};
static const XRect _Const0006 = {{ 0, 114 }, { 94, 189 }};
static const XRect _Const0007 = {{ 0, 189 }, { 94, 264 }};
static const XRect _Const0008 = {{ 0, 39 }, { 94, 114 }};
static const XRect _Const0009 = {{ 111, 188 }, { 455, 231 }};
static const XStringRes _Const000A = { _StringsDefault0, 0x0002 };
static const XStringRes _Const000B = { _StringsDefault0, 0x0006 };

/* Initializer for the class 'Media::MED01_MediaUI' */
void MediaMED01_MediaUI__Init( MediaMED01_MediaUI _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MediaMED01_MediaUI );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Title, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Artist, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Album, &_this->_XObject, 0 );
  ViewsText__Init( &_this->ElapsedTimeSec, &_this->_XObject, 0 );
  ViewsText__Init( &_this->RemainTimeSec, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->PlaybackTimeEventHandler, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->PlayPauseBG, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->PlayPauseButton, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ControlDownBG, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->PreviousTrackButton, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->VolumeDownButton, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ControlUpBG, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->NextTrackButton, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->VolumeUpButton, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->HighlightTimer, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->TitleObserver, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->AlbumObserver, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->ArtistObserver, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->PlayStateObserver, &_this->_XObject, 0 );
  WidgetSetHorizontalSlider__Init( &_this->SeekBar, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MediaMED01_MediaUI );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  _this->Super2.UpKeyTriggerMode = EnumKeyTriggerModeOFF;
  _this->Super2.DownKeyTriggerMode = EnumKeyTriggerModeOFF;
  CoreRectView__OnSetBounds( &_this->Title, _Const0001 );
  ViewsText_OnSetEllipsis( &_this->Title, 1 );
  ViewsText_OnSetAlignment( &_this->Title, ViewsTextAlignmentAlignHorzLeft | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Title, 0 );
  ViewsText_OnSetVisible( &_this->Title, 1 );
  CoreRectView__OnSetBounds( &_this->Artist, _Const0002 );
  ViewsText_OnSetEllipsis( &_this->Artist, 1 );
  ViewsText_OnSetAlignment( &_this->Artist, ViewsTextAlignmentAlignHorzLeft | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Artist, 0 );
  ViewsText_OnSetVisible( &_this->Artist, 1 );
  CoreRectView__OnSetBounds( &_this->Album, _Const0003 );
  ViewsText_OnSetEllipsis( &_this->Album, 1 );
  ViewsText_OnSetAlignment( &_this->Album, ViewsTextAlignmentAlignHorzLeft | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Album, 0 );
  ViewsText_OnSetVisible( &_this->Album, 1 );
  CoreRectView__OnSetBounds( &_this->ElapsedTimeSec, _Const0004 );
  ViewsText_OnSetAlignment( &_this->ElapsedTimeSec, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ElapsedTimeSec, 0 );
  ViewsText_OnSetVisible( &_this->ElapsedTimeSec, 0 );
  CoreRectView__OnSetBounds( &_this->RemainTimeSec, _Const0005 );
  ViewsText_OnSetAlignment( &_this->RemainTimeSec, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->RemainTimeSec, 0 );
  ViewsText_OnSetVisible( &_this->RemainTimeSec, 0 );
  CoreRectView__OnSetBounds( &_this->PlayPauseBG, _Const0006 );
  ViewsImage_OnSetFrameNumber( &_this->PlayPauseBG, 0 );
  CoreRectView__OnSetBounds( &_this->PlayPauseButton, _Const0006 );
  CoreRectView__OnSetBounds( &_this->ControlDownBG, _Const0007 );
  CoreRectView__OnSetBounds( &_this->PreviousTrackButton, _Const0007 );
  CoreRectView__OnSetBounds( &_this->VolumeDownButton, _Const0007 );
  CoreRectView__OnSetBounds( &_this->ControlUpBG, _Const0008 );
  CoreRectView__OnSetBounds( &_this->NextTrackButton, _Const0008 );
  CoreRectView__OnSetBounds( &_this->VolumeUpButton, _Const0008 );
  CoreTimer_OnSetPeriod( &_this->HighlightTimer, 100 );
  CoreTimer_OnSetEnabled( &_this->HighlightTimer, 0 );
  CoreRectView__OnSetBounds( &_this->SeekBar, _Const0009 );
  CoreGroup_OnSetVisible((CoreGroup)&_this->SeekBar, 0 );
  WidgetSetHorizontalSlider_OnSetCurrentValue( &_this->SeekBar, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Title ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Artist ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Album ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ElapsedTimeSec ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RemainTimeSec ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PlayPauseBG ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PlayPauseButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ControlDownBG ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PreviousTrackButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->VolumeDownButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ControlUpBG ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NextTrackButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->VolumeUpButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SeekBar ), 0 );
  ViewsText_OnSetFont( &_this->Title, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->Artist, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->Album, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->ElapsedTimeSec, EwLoadResource( &FontsNotoSansCjkJpMedium22pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->RemainTimeSec, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->PlaybackTimeEventHandler.OnEvent = EwNewSlot( _this, MediaMED01_MediaUI_OnPlaybackTimeUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->PlaybackTimeEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->NotifyPlayBackTimeChangedSystemEvent );
  ViewsImage_OnSetBitmap( &_this->PlayPauseBG, EwLoadResource( &ResourceControlKeyBackground, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->PlayPauseButton, EwLoadResource( &ResourceIconMediaPlayPause, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ControlDownBG, EwLoadResource( &ResourceControlKeyBackground, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->PreviousTrackButton, EwLoadResource( &ResourceIconMediaPrevious, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->VolumeDownButton, EwLoadResource( &ResourceIconVolumeDown, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ControlUpBG, EwLoadResource( &ResourceControlKeyBackground, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->NextTrackButton, EwLoadResource( &ResourceIconMediaNext, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->VolumeUpButton, EwLoadResource( &ResourceIconVolumeUp, 
  ResourcesBitmap ));
  _this->HighlightTimer.OnTrigger = EwNewSlot( _this, MediaMED01_MediaUI_OnHighlightEndSlot );
  _this->TitleObserver.OnEvent = EwNewSlot( _this, MediaMED01_MediaUI_OnTrackInfoUpdateSlot );
  CorePropertyObserver_OnSetOutlet( &_this->TitleObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass ), 
  DeviceInterfaceMediaManagerDeviceClass_OnGetTitle, DeviceInterfaceMediaManagerDeviceClass_OnSetTitle ));
  _this->AlbumObserver.OnEvent = EwNewSlot( _this, MediaMED01_MediaUI_OnTrackInfoUpdateSlot );
  CorePropertyObserver_OnSetOutlet( &_this->AlbumObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass ), 
  DeviceInterfaceMediaManagerDeviceClass_OnGetAlbum, DeviceInterfaceMediaManagerDeviceClass_OnSetAlbum ));
  _this->ArtistObserver.OnEvent = EwNewSlot( _this, MediaMED01_MediaUI_OnTrackInfoUpdateSlot );
  CorePropertyObserver_OnSetOutlet( &_this->ArtistObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass ), 
  DeviceInterfaceMediaManagerDeviceClass_OnGetArtist, DeviceInterfaceMediaManagerDeviceClass_OnSetArtist ));
  _this->PlayStateObserver.OnEvent = EwNewSlot( _this, MediaMED01_MediaUI_OnTrackInfoUpdateSlot );
  CorePropertyObserver_OnSetOutlet( &_this->PlayStateObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass ), 
  DeviceInterfaceMediaManagerDeviceClass_OnGetPlaybackState, DeviceInterfaceMediaManagerDeviceClass_OnSetPlaybackState ));
  WidgetSetHorizontalSlider_OnSetAppearance( &_this->SeekBar, EwGetAutoObject( &UIConfigHorizontalSliderConfig, 
  WidgetSetHorizontalSliderConfig ));

  /* Call the user defined constructor */
  MediaMED01_MediaUI_Init( _this, aArg );
}

/* Re-Initializer for the class 'Media::MED01_MediaUI' */
void MediaMED01_MediaUI__ReInit( MediaMED01_MediaUI _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Title );
  ViewsText__ReInit( &_this->Artist );
  ViewsText__ReInit( &_this->Album );
  ViewsText__ReInit( &_this->ElapsedTimeSec );
  ViewsText__ReInit( &_this->RemainTimeSec );
  CoreSystemEventHandler__ReInit( &_this->PlaybackTimeEventHandler );
  ViewsImage__ReInit( &_this->PlayPauseBG );
  ViewsImage__ReInit( &_this->PlayPauseButton );
  ViewsImage__ReInit( &_this->ControlDownBG );
  ViewsImage__ReInit( &_this->PreviousTrackButton );
  ViewsImage__ReInit( &_this->VolumeDownButton );
  ViewsImage__ReInit( &_this->ControlUpBG );
  ViewsImage__ReInit( &_this->NextTrackButton );
  ViewsImage__ReInit( &_this->VolumeUpButton );
  CoreTimer__ReInit( &_this->HighlightTimer );
  CorePropertyObserver__ReInit( &_this->TitleObserver );
  CorePropertyObserver__ReInit( &_this->AlbumObserver );
  CorePropertyObserver__ReInit( &_this->ArtistObserver );
  CorePropertyObserver__ReInit( &_this->PlayStateObserver );
  WidgetSetHorizontalSlider__ReInit( &_this->SeekBar );
}

/* Finalizer method for the class 'Media::MED01_MediaUI' */
void MediaMED01_MediaUI__Done( MediaMED01_MediaUI _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Title );
  ViewsText__Done( &_this->Artist );
  ViewsText__Done( &_this->Album );
  ViewsText__Done( &_this->ElapsedTimeSec );
  ViewsText__Done( &_this->RemainTimeSec );
  CoreSystemEventHandler__Done( &_this->PlaybackTimeEventHandler );
  ViewsImage__Done( &_this->PlayPauseBG );
  ViewsImage__Done( &_this->PlayPauseButton );
  ViewsImage__Done( &_this->ControlDownBG );
  ViewsImage__Done( &_this->PreviousTrackButton );
  ViewsImage__Done( &_this->VolumeDownButton );
  ViewsImage__Done( &_this->ControlUpBG );
  ViewsImage__Done( &_this->NextTrackButton );
  ViewsImage__Done( &_this->VolumeUpButton );
  CoreTimer__Done( &_this->HighlightTimer );
  CorePropertyObserver__Done( &_this->TitleObserver );
  CorePropertyObserver__Done( &_this->AlbumObserver );
  CorePropertyObserver__Done( &_this->ArtistObserver );
  CorePropertyObserver__Done( &_this->PlayStateObserver );
  WidgetSetHorizontalSlider__Done( &_this->SeekBar );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void MediaMED01_MediaUI_Init( MediaMED01_MediaUI _this, XHandle aArg )
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

  if (( EwCompString( 0, EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->Title ) 
      != 0 ) && ( EwCompString( EwLoadString( &StringsGEN_three_hyphens ), EwGetAutoObject( 
      &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->Title ) 
      != 0 ))
  {
    EwSignal( EwNewSlot( _this, MediaMED01_MediaUI_OnPlaybackTimeUpdateSlot ), ((XObject)_this ));
  }
}

/* 'C' function for method : 'Media::MED01_MediaUI.OnShortEnterKeyActivated()' */
void MediaMED01_MediaUI_OnShortEnterKeyActivated( MediaMED01_MediaUI _this )
{
  MediaMED01_MediaUI_StartHighlight( _this, &_this->PlayPauseBG );
  EwPostSignal( EwNewSlot( _this, MediaMED01_MediaUI_OnPlayPauseSlot ), ((XObject)_this ));
}

/* 'C' function for method : 'Media::MED01_MediaUI.OnShortHomeKeyActivated()' */
void MediaMED01_MediaUI_OnShortHomeKeyActivated( MediaMED01_MediaUI _this )
{
  CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Media::MED01_MediaUI.OnLongDownKeyActivated()' */
void MediaMED01_MediaUI_OnLongDownKeyActivated( MediaMED01_MediaUI _this )
{
  MediaMED01_MediaUI_StartHighlight( _this, &_this->ControlDownBG );
  EwPostSignal( EwNewSlot( _this, MediaMED01_MediaUI_OnPrevTrackSlot ), ((XObject)_this ));
}

/* 'C' function for method : 'Media::MED01_MediaUI.OnLongUpKeyActivated()' */
void MediaMED01_MediaUI_OnLongUpKeyActivated( MediaMED01_MediaUI _this )
{
  MediaMED01_MediaUI_StartHighlight( _this, &_this->ControlUpBG );
  EwPostSignal( EwNewSlot( _this, MediaMED01_MediaUI_OnNextTrackSlot ), ((XObject)_this ));
}

/* 'C' function for method : 'Media::MED01_MediaUI.OnPlayPauseSlot()' */
void MediaMED01_MediaUI_OnPlayPauseSlot( MediaMED01_MediaUI _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( 0 == _this->PlaybackState )
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

/* 'C' function for method : 'Media::MED01_MediaUI.OnPrevTrackSlot()' */
void MediaMED01_MediaUI_OnPrevTrackSlot( MediaMED01_MediaUI _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  MediaMED01_MediaUI_ChangeTrack( _this );
  DeviceInterfaceMediaManagerDeviceClass_SendRemoteCommand( EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
  DeviceInterfaceMediaManagerDeviceClass ), EnumCommandTypePrevTrack );
}

/* 'C' function for method : 'Media::MED01_MediaUI.OnNextTrackSlot()' */
void MediaMED01_MediaUI_OnNextTrackSlot( MediaMED01_MediaUI _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  MediaMED01_MediaUI_ChangeTrack( _this );
  DeviceInterfaceMediaManagerDeviceClass_SendRemoteCommand( EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
  DeviceInterfaceMediaManagerDeviceClass ), EnumCommandTypeNextTrack );
}

/* 'C' function for method : 'Media::MED01_MediaUI.ChangeTrack()' */
void MediaMED01_MediaUI_ChangeTrack( MediaMED01_MediaUI _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->IsTitleReceived 
  = 0;
  EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->IsArtistReceived 
  = 0;
  EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->IsAlbumReceived 
  = 0;
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void MediaMED01_MediaUI_OnPlaybackTimeUpdateSlot( MediaMED01_MediaUI _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( !ViewsText_OnGetVisible( &_this->ElapsedTimeSec ))
  {
    ViewsText_OnSetVisible( &_this->ElapsedTimeSec, 1 );
  }

  ViewsText_OnSetString( &_this->ElapsedTimeSec, MediaMED01_MediaUI_FormatTimeText( 
  _this, EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->ElapsedTimeSec ));

  if ( !ViewsText_OnGetVisible( &_this->RemainTimeSec ))
  {
    ViewsText_OnSetVisible( &_this->RemainTimeSec, 1 );
  }

  ViewsText_OnSetString( &_this->RemainTimeSec, MediaMED01_MediaUI_FormatTimeText( 
  _this, EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->RemainTimeSec ));

  if ( 0 != EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->DurationTimeSec )
  {
    if ( !CoreGroup_OnGetVisible((CoreGroup)&_this->SeekBar ))
    {
      CoreGroup_OnSetVisible((CoreGroup)&_this->SeekBar, 1 );
    }

    WidgetSetHorizontalSlider_OnSetCurrentValue( &_this->SeekBar, ( EwGetAutoObject( 
    &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->ElapsedTimeSec 
    * 100 ) / EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )->DurationTimeSec );
  }
}

/* 'C' function for method : 'Media::MED01_MediaUI.FormatTimeText()' */
XString MediaMED01_MediaUI_FormatTimeText( MediaMED01_MediaUI _this, XInt32 TimeSec )
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
    TimeText = EwConcatString( EwNewStringInt( Hour, 0, 10 ), EwLoadString( &_Const000A ));

    if ( Minute < 10 )
    {
      TimeText = EwConcatString( TimeText, EwLoadString( &_Const000B ));
    }
  }

  TimeText = EwConcatString( EwConcatString( TimeText, EwNewStringInt( Minute, 0, 
  10 )), EwLoadString( &_Const000A ));

  if ( Second < 10 )
  {
    TimeText = EwConcatString( TimeText, EwLoadString( &_Const000B ));
  }

  TimeText = EwConcatString( TimeText, EwNewStringInt( Second, 0, 10 ));
  return TimeText;
}

/* 'C' function for method : 'Media::MED01_MediaUI.OnHighlightEndSlot()' */
void MediaMED01_MediaUI_OnHighlightEndSlot( MediaMED01_MediaUI _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->HighlightTimer, 0 );
  ViewsImage_OnSetFrameNumber( _this->HighlightBG, 0 );
}

/* 'C' function for method : 'Media::MED01_MediaUI.StartHighlight()' */
void MediaMED01_MediaUI_StartHighlight( MediaMED01_MediaUI _this, ViewsImage aBackground )
{
  ViewsImage_OnSetFrameNumber( aBackground, 1 );
  _this->HighlightBG = aBackground;
  CoreTimer_OnSetEnabled( &_this->HighlightTimer, 1 );
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void MediaMED01_MediaUI_OnTrackInfoUpdateSlot( MediaMED01_MediaUI _this, XObject 
  sender )
{
  if ( sender == ((XObject)&_this->TitleObserver ))
  {
    ViewsText_OnSetString( &_this->Title, EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
    DeviceInterfaceMediaManagerDeviceClass )->Title );
  }
  else
    if ( sender == ((XObject)&_this->AlbumObserver ))
    {
      ViewsText_OnSetString( &_this->Album, EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
      DeviceInterfaceMediaManagerDeviceClass )->Album );
    }
    else
      if ( sender == ((XObject)&_this->ArtistObserver ))
      {
        ViewsText_OnSetString( &_this->Artist, EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
        DeviceInterfaceMediaManagerDeviceClass )->Artist );
      }
      else
        if ( sender == ((XObject)&_this->PlayStateObserver ))
        {
          _this->PlaybackState = EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, 
          DeviceInterfaceMediaManagerDeviceClass )->PlaybackState;
        }
}

/* Variants derived from the class : 'Media::MED01_MediaUI' */
EW_DEFINE_CLASS_VARIANTS( MediaMED01_MediaUI )
EW_END_OF_CLASS_VARIANTS( MediaMED01_MediaUI )

/* Virtual Method Table (VMT) for the class : 'Media::MED01_MediaUI' */
EW_DEFINE_CLASS( MediaMED01_MediaUI, ComponentsBaseMainBG, HighlightBG, Title, Title, 
                 Title, PlaybackState, PlaybackState, "Media::MED01_MediaUI" )
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
  MediaMED01_MediaUI_OnShortEnterKeyActivated,
  MediaMED01_MediaUI_OnShortHomeKeyActivated,
  MediaMED01_MediaUI_OnLongDownKeyActivated,
  MediaMED01_MediaUI_OnLongUpKeyActivated,
EW_END_OF_CLASS( MediaMED01_MediaUI )

/* Embedded Wizard */
