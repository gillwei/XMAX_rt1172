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

#ifndef _SettingsReset_H
#define _SettingsReset_H

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

#include "_ComponentsBaseComponent.h"
#include "_CoreKeyPressHandler.h"
#include "_CorePropertyObserver.h"
#include "_CoreTimer.h"

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

/* Forward declaration of the class Settings::InProgress */
#ifndef _SettingsInProgress_
  EW_DECLARE_CLASS( SettingsInProgress )
#define _SettingsInProgress_
#endif

/* Forward declaration of the class Settings::Reset */
#ifndef _SettingsReset_
  EW_DECLARE_CLASS( SettingsReset )
#define _SettingsReset_
#endif


/* Deklaration of class : 'Settings::Reset' */
EW_DEFINE_FIELDS( SettingsReset, ComponentsBaseComponent )
  EW_VARIABLE( BusyDialog,      SettingsInProgress )
  EW_OBJECT  ( SystemRebootCountDownTimer, CoreTimer )
  EW_OBJECT  ( ResetResultObserver, CorePropertyObserver )
EW_END_OF_FIELDS( SettingsReset )

/* Virtual Method Table (VMT) for the class : 'Settings::Reset' */
EW_DEFINE_METHODS( SettingsReset, ComponentsBaseComponent )
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
  EW_METHOD( OnLongKeyPressed,  void )( ComponentsBaseComponent _this, XObject sender )
  EW_METHOD( OnShortDownKeyPressed, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnShortUpKeyPressed, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnShortEnterKeyPressed, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnShortHomeKeyPressed, void )( ComponentsBaseComponent _this )
EW_END_OF_METHODS( SettingsReset )

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void SettingsReset_Init( SettingsReset _this, XHandle aArg );

/* 'C' function for method : 'Settings::Reset.OnAllResetYesSlot()' */
void SettingsReset_OnAllResetYesSlot( SettingsReset _this, XObject sender );

/* 'C' function for method : 'Settings::Reset.OnAllResetNoSlot()' */
void SettingsReset_OnAllResetNoSlot( SettingsReset _this, XObject sender );

/* 'C' function for method : 'Settings::Reset.OnSystemRebootTriggeredSlot()' */
void SettingsReset_OnSystemRebootTriggeredSlot( SettingsReset _this, XObject sender );

/* 'C' function for method : 'Settings::Reset.ShowResetCompleteDialog()' */
void SettingsReset_ShowResetCompleteDialog( SettingsReset _this );

/* 'C' function for method : 'Settings::Reset.StartFactoryReset()' */
void SettingsReset_StartFactoryReset( SettingsReset _this );

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void SettingsReset_OnResetCompleteSlot( SettingsReset _this, XObject sender );

#ifdef __cplusplus
  }
#endif

#endif /* _SettingsReset_H */

/* Embedded Wizard */
