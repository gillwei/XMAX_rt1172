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

#ifndef _MediaMED01_MediaUI_H
#define _MediaMED01_MediaUI_H

#ifdef __cplusplus
  extern "C"
  {
#endif

#include "ewrte.h"
#if EW_RTE_VERSION != 0x000A0000
  #error Wrong version of Embedded Wizard Runtime Environment.
#endif

#include "ewgfx.h"
#if EW_GFX_VERSION != 0x000A0000
  #error Wrong version of Embedded Wizard Graphics Engine.
#endif

#include "_ComponentsBaseMainBG.h"
#include "_CoreKeyPressHandler.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_MediaTrack.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "_WidgetSetHorizontalSlider.h"

/* Forward declaration of the class Core::DialogContext */
#ifndef _CoreDialogContext_
  EW_DECLARE_CLASS( CoreDialogContext )
#define _CoreDialogContext_
#endif

/* Forward declaration of the class Core::Group */
#ifndef _CoreGroup_
  EW_DECLARE_CLASS( CoreGroup )
#define _CoreGroup_
#endif

/* Forward declaration of the class Core::LayoutContext */
#ifndef _CoreLayoutContext_
  EW_DECLARE_CLASS( CoreLayoutContext )
#define _CoreLayoutContext_
#endif

/* Forward declaration of the class Core::TaskQueue */
#ifndef _CoreTaskQueue_
  EW_DECLARE_CLASS( CoreTaskQueue )
#define _CoreTaskQueue_
#endif

/* Forward declaration of the class Core::View */
#ifndef _CoreView_
  EW_DECLARE_CLASS( CoreView )
#define _CoreView_
#endif

/* Forward declaration of the class Effects::Fader */
#ifndef _EffectsFader_
  EW_DECLARE_CLASS( EffectsFader )
#define _EffectsFader_
#endif

/* Forward declaration of the class Graphics::Canvas */
#ifndef _GraphicsCanvas_
  EW_DECLARE_CLASS( GraphicsCanvas )
#define _GraphicsCanvas_
#endif

/* Forward declaration of the class Media::MED01_MediaUI */
#ifndef _MediaMED01_MediaUI_
  EW_DECLARE_CLASS( MediaMED01_MediaUI )
#define _MediaMED01_MediaUI_
#endif


/* Deklaration of class : 'Media::MED01_MediaUI' */
EW_DEFINE_FIELDS( MediaMED01_MediaUI, ComponentsBaseMainBG )
  EW_PROPERTY( HighlightBG,     ViewsImage )
  EW_OBJECT  ( Title,           ViewsText )
  EW_OBJECT  ( Artist,          ViewsText )
  EW_OBJECT  ( Album,           ViewsText )
  EW_OBJECT  ( ElapsedTimeSec,  ViewsText )
  EW_OBJECT  ( RemainTimeSec,   ViewsText )
  EW_OBJECT  ( Track,           MediaTrack )
  EW_OBJECT  ( PlaybackTimeEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( PlayPauseBG,     ViewsImage )
  EW_OBJECT  ( PlayPauseButton, ViewsImage )
  EW_OBJECT  ( ControlDownBG,   ViewsImage )
  EW_OBJECT  ( PreviousTrackButton, ViewsImage )
  EW_OBJECT  ( VolumeDownButton, ViewsImage )
  EW_OBJECT  ( ControlUpBG,     ViewsImage )
  EW_OBJECT  ( NextTrackButton, ViewsImage )
  EW_OBJECT  ( VolumeUpButton,  ViewsImage )
  EW_OBJECT  ( SeekBar,         WidgetSetHorizontalSlider )
  EW_OBJECT  ( HighlightTimer,  CoreTimer )
EW_END_OF_FIELDS( MediaMED01_MediaUI )

/* Virtual Method Table (VMT) for the class : 'Media::MED01_MediaUI' */
EW_DEFINE_METHODS( MediaMED01_MediaUI, ComponentsBaseMainBG )
  EW_METHOD( initLayoutContext, void )( CoreRectView _this, XRect aBounds, CoreOutline 
    aOutline )
  EW_METHOD( GetRoot,           CoreRoot )( CoreView _this )
  EW_METHOD( Draw,              void )( CoreGroup _this, GraphicsCanvas aCanvas, 
    XRect aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend )
  EW_METHOD( HandleEvent,       XObject )( CoreView _this, CoreEvent aEvent )
  EW_METHOD( CursorHitTest,     CoreCursorHit )( CoreGroup _this, XRect aArea, XInt32 
    aFinger, XInt32 aStrikeCount, CoreView aDedicatedView, XSet aRetargetReason )
  EW_METHOD( ArrangeView,       XPoint )( CoreRectView _this, XRect aBounds, XEnum 
    aFormation )
  EW_METHOD( MoveView,          void )( CoreRectView _this, XPoint aOffset, XBool 
    aFastMove )
  EW_METHOD( GetExtent,         XRect )( CoreRectView _this )
  EW_METHOD( ChangeViewState,   void )( CoreGroup _this, XSet aSetState, XSet aClearState )
  EW_METHOD( OnSetBounds,       void )( CoreGroup _this, XRect value )
  EW_METHOD( OnSetFocus,        void )( CoreGroup _this, CoreView value )
  EW_METHOD( OnSetBuffered,     void )( CoreGroup _this, XBool value )
  EW_METHOD( OnGetEnabled,      XBool )( CoreGroup _this )
  EW_METHOD( OnSetEnabled,      void )( CoreGroup _this, XBool value )
  EW_METHOD( OnSetOpacity,      void )( CoreGroup _this, XInt32 value )
  EW_METHOD( IsCurrentDialog,   XBool )( CoreGroup _this )
  EW_METHOD( IsActiveDialog,    XBool )( CoreGroup _this, XBool aRecursive )
  EW_METHOD( DismissDialog,     void )( CoreGroup _this, CoreGroup aDialogGroup, 
    EffectsTransition aOverrideDismissTransition, EffectsTransition aOverrideOverlayTransition, 
    EffectsTransition aOverrideRestoreTransition, XSlot aComplete, XSlot aCancel, 
    XBool aCombine )
  EW_METHOD( DispatchEvent,     XObject )( CoreGroup _this, CoreEvent aEvent )
  EW_METHOD( BroadcastEvent,    XObject )( CoreGroup _this, CoreEvent aEvent, XSet 
    aFilter )
  EW_METHOD( UpdateLayout,      void )( CoreGroup _this, XPoint aSize )
  EW_METHOD( UpdateViewState,   void )( CoreGroup _this, XSet aState )
  EW_METHOD( InvalidateArea,    void )( CoreGroup _this, XRect aArea )
  EW_METHOD( CountViews,        XInt32 )( CoreGroup _this )
  EW_METHOD( FindNextView,      CoreView )( CoreGroup _this, CoreView aView, XSet 
    aFilter )
  EW_METHOD( FindSiblingView,   CoreView )( CoreGroup _this, CoreView aView, XSet 
    aFilter )
  EW_METHOD( RestackTop,        void )( CoreGroup _this, CoreView aView )
  EW_METHOD( Restack,           void )( CoreGroup _this, CoreView aView, XInt32 
    aOrder )
  EW_METHOD( Remove,            void )( CoreGroup _this, CoreView aView )
  EW_METHOD( Add,               void )( CoreGroup _this, CoreView aView, XInt32 
    aOrder )
  EW_METHOD( OnShortDownKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnShortUpKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnShortEnterKeyActivated, void )( MediaMED01_MediaUI _this )
  EW_METHOD( OnShortHomeKeyActivated, void )( MediaMED01_MediaUI _this )
  EW_METHOD( OnLongDownKeyActivated, void )( MediaMED01_MediaUI _this )
  EW_METHOD( OnLongUpKeyActivated, void )( MediaMED01_MediaUI _this )
EW_END_OF_METHODS( MediaMED01_MediaUI )

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void MediaMED01_MediaUI_Init( MediaMED01_MediaUI _this, XHandle aArg );

/* 'C' function for method : 'Media::MED01_MediaUI.OnShortEnterKeyActivated()' */
void MediaMED01_MediaUI_OnShortEnterKeyActivated( MediaMED01_MediaUI _this );

/* 'C' function for method : 'Media::MED01_MediaUI.OnShortHomeKeyActivated()' */
void MediaMED01_MediaUI_OnShortHomeKeyActivated( MediaMED01_MediaUI _this );

/* 'C' function for method : 'Media::MED01_MediaUI.OnLongDownKeyActivated()' */
void MediaMED01_MediaUI_OnLongDownKeyActivated( MediaMED01_MediaUI _this );

/* 'C' function for method : 'Media::MED01_MediaUI.OnLongUpKeyActivated()' */
void MediaMED01_MediaUI_OnLongUpKeyActivated( MediaMED01_MediaUI _this );

/* 'C' function for method : 'Media::MED01_MediaUI.OnPlayPauseSlot()' */
void MediaMED01_MediaUI_OnPlayPauseSlot( MediaMED01_MediaUI _this, XObject sender );

/* 'C' function for method : 'Media::MED01_MediaUI.OnPrevTrackSlot()' */
void MediaMED01_MediaUI_OnPrevTrackSlot( MediaMED01_MediaUI _this, XObject sender );

/* 'C' function for method : 'Media::MED01_MediaUI.OnNextTrackSlot()' */
void MediaMED01_MediaUI_OnNextTrackSlot( MediaMED01_MediaUI _this, XObject sender );

/* 'C' function for method : 'Media::MED01_MediaUI.SetTrackInfo()' */
void MediaMED01_MediaUI_SetTrackInfo( MediaMED01_MediaUI _this, XObject sender );

/* 'C' function for method : 'Media::MED01_MediaUI.ChangeTrack()' */
void MediaMED01_MediaUI_ChangeTrack( MediaMED01_MediaUI _this );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void MediaMED01_MediaUI_OnPlaybackTimeUpdateSlot( MediaMED01_MediaUI _this, XObject 
  sender );

/* 'C' function for method : 'Media::MED01_MediaUI.FormatTimeText()' */
XString MediaMED01_MediaUI_FormatTimeText( MediaMED01_MediaUI _this, XInt32 TimeSec );

/* 'C' function for method : 'Media::MED01_MediaUI.OnHighlightEndSlot()' */
void MediaMED01_MediaUI_OnHighlightEndSlot( MediaMED01_MediaUI _this, XObject sender );

/* 'C' function for method : 'Media::MED01_MediaUI.StartHighlight()' */
void MediaMED01_MediaUI_StartHighlight( MediaMED01_MediaUI _this, ViewsImage aBackground );

#ifdef __cplusplus
  }
#endif

#endif /* _MediaMED01_MediaUI_H */

/* Embedded Wizard */
