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

#ifndef _ApplicationApplication_H
#define _ApplicationApplication_H

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

#include "_CorePropertyObserver.h"
#include "_CoreRoot.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_StatusBarMain.h"

/* Forward declaration of the class Application::Application */
#ifndef _ApplicationApplication_
  EW_DECLARE_CLASS( ApplicationApplication )
#define _ApplicationApplication_
#endif

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

/* Forward declaration of the class Core::KeyPressHandler */
#ifndef _CoreKeyPressHandler_
  EW_DECLARE_CLASS( CoreKeyPressHandler )
#define _CoreKeyPressHandler_
#endif

/* Forward declaration of the class Core::LayoutContext */
#ifndef _CoreLayoutContext_
  EW_DECLARE_CLASS( CoreLayoutContext )
#define _CoreLayoutContext_
#endif

/* Forward declaration of the class Core::ModalContext */
#ifndef _CoreModalContext_
  EW_DECLARE_CLASS( CoreModalContext )
#define _CoreModalContext_
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


/* This is the root component of the entire GUI application. */
EW_DEFINE_FIELDS( ApplicationApplication, CoreRoot )
  EW_OBJECT  ( FactoryTestEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( BtFwStatusObserver, CorePropertyObserver )
  EW_OBJECT  ( DDModeTestTimer, CoreTimer )
  EW_OBJECT  ( OpeningSystemEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( StatusBar,       StatusBarMain )
  EW_OBJECT  ( CheckOpeningTimer, CoreTimer )
  EW_OBJECT  ( PhoneCallStateChangedEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( InspectionModeEventHandler, CoreSystemEventHandler )
  EW_VARIABLE( IsFactoryModeDialogDisplayed, XBool )
  EW_VARIABLE( IsFactoryTest,   XBool )
  EW_VARIABLE( IsDisclaimerDismissed, XBool )
  EW_PROPERTY( StatusBarVisible, XBool )
EW_END_OF_FIELDS( ApplicationApplication )

/* Virtual Method Table (VMT) for the class : 'Application::Application' */
EW_DEFINE_METHODS( ApplicationApplication, CoreRoot )
  EW_METHOD( initLayoutContext, void )( CoreRectView _this, XRect aBounds, CoreOutline 
    aOutline )
  EW_METHOD( GetRoot,           CoreRoot )( CoreRoot _this )
  EW_METHOD( Draw,              void )( CoreRoot _this, GraphicsCanvas aCanvas, 
    XRect aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend )
  EW_METHOD( HandleEvent,       XObject )( CoreView _this, CoreEvent aEvent )
  EW_METHOD( CursorHitTest,     CoreCursorHit )( CoreGroup _this, XRect aArea, XInt32 
    aFinger, XInt32 aStrikeCount, CoreView aDedicatedView, XSet aRetargetReason )
  EW_METHOD( ArrangeView,       XPoint )( CoreRectView _this, XRect aBounds, XEnum 
    aFormation )
  EW_METHOD( MoveView,          void )( CoreRectView _this, XPoint aOffset, XBool 
    aFastMove )
  EW_METHOD( GetExtent,         XRect )( CoreRectView _this )
  EW_METHOD( ChangeViewState,   void )( CoreRoot _this, XSet aSetState, XSet aClearState )
  EW_METHOD( OnSetBounds,       void )( CoreGroup _this, XRect value )
  EW_METHOD( OnSetFocus,        void )( CoreRoot _this, CoreView value )
  EW_METHOD( OnSetBuffered,     void )( CoreRoot _this, XBool value )
  EW_METHOD( OnGetEnabled,      XBool )( CoreGroup _this )
  EW_METHOD( OnSetEnabled,      void )( CoreGroup _this, XBool value )
  EW_METHOD( OnSetOpacity,      void )( CoreRoot _this, XInt32 value )
  EW_METHOD( OnSetVisible,      void )( CoreGroup _this, XBool value )
  EW_METHOD( IsCurrentDialog,   XBool )( CoreRoot _this )
  EW_METHOD( IsActiveDialog,    XBool )( CoreRoot _this, XBool aRecursive )
  EW_METHOD( DismissDialog,     void )( CoreGroup _this, CoreGroup aDialogGroup, 
    EffectsTransition aOverrideDismissTransition, EffectsTransition aOverrideOverlayTransition, 
    EffectsTransition aOverrideRestoreTransition, XSlot aComplete, XSlot aCancel, 
    XBool aCombine )
  EW_METHOD( DispatchEvent,     XObject )( CoreRoot _this, CoreEvent aEvent )
  EW_METHOD( BroadcastEvent,    XObject )( CoreRoot _this, CoreEvent aEvent, XSet 
    aFilter )
  EW_METHOD( UpdateLayout,      void )( CoreGroup _this, XPoint aSize )
  EW_METHOD( UpdateViewState,   void )( CoreGroup _this, XSet aState )
  EW_METHOD( InvalidateArea,    void )( CoreRoot _this, XRect aArea )
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
EW_END_OF_METHODS( ApplicationApplication )

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationApplication_Init( ApplicationApplication _this, XHandle aArg );

/* 'C' function for method : 'Application::Application.OnDisclaimerAcceptedSlot()' */
void ApplicationApplication_OnDisclaimerAcceptedSlot( ApplicationApplication _this, 
  XObject sender );

/* 'C' function for method : 'Application::Application.ShowDisclaimer()' */
void ApplicationApplication_ShowDisclaimer( ApplicationApplication _this );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void ApplicationApplication_OnFactoryTestEventSlot( ApplicationApplication _this, 
  XObject sender );

/* 'C' function for method : 'Application::Application.OnSetStatusBarVisible()' */
void ApplicationApplication_OnSetStatusBarVisible( ApplicationApplication _this, 
  XBool value );

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void ApplicationApplication_OnBtFwStatusUpdteSlot( ApplicationApplication _this, 
  XObject sender );

/* 'C' function for method : 'Application::Application.DismissFactoryTestDialog()' */
void ApplicationApplication_DismissFactoryTestDialog( ApplicationApplication _this );

/* 'C' function for method : 'Application::Application.SwitchToHome()' */
void ApplicationApplication_SwitchToHome( ApplicationApplication _this, XEnum aHomeType );

/* 'C' function for method : 'Application::Application.OnDDModeTestSlot()' */
void ApplicationApplication_OnDDModeTestSlot( ApplicationApplication _this, XObject 
  sender );

/* Return from the DD mode forbidden UI to the launcher */
void ApplicationApplication_ReturnToLauncher( ApplicationApplication _this );

/* 'C' function for method : 'Application::Application.HomeClassOfHomeType()' */
XClass ApplicationApplication_HomeClassOfHomeType( ApplicationApplication _this, 
  XEnum aHomeType );

/* 'C' function for method : 'Application::Application.HomeDialogOfHomeType()' */
CoreGroup ApplicationApplication_HomeDialogOfHomeType( ApplicationApplication _this, 
  XEnum aHomeType );

/* 'C' function for method : 'Application::Application.OnOpeningFinishedSlot()' */
void ApplicationApplication_OnOpeningFinishedSlot( ApplicationApplication _this, 
  XObject sender );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void ApplicationApplication_OnStartOpeningSlot( ApplicationApplication _this, XObject 
  sender );

/* Return from the DD mode forbidden UI to the launcher */
void ApplicationApplication_ReturnToHome( ApplicationApplication _this );

/* 'C' function for method : 'Application::Application.OnCheckOpeningSlot()' */
void ApplicationApplication_OnCheckOpeningSlot( ApplicationApplication _this, XObject 
  sender );

/* 'C' function for method : 'Application::Application.SlideInHome()' */
void ApplicationApplication_SlideInHome( ApplicationApplication _this, XEnum aHomeType );

/* 'C' function for method : 'Application::Application.OnSlideInHomeFinishedSlot()' */
void ApplicationApplication_OnSlideInHomeFinishedSlot( ApplicationApplication _this, 
  XObject sender );

/* 'C' function for method : 'Application::Application.OnPhoneCallStateChangedSlot()' */
void ApplicationApplication_OnPhoneCallStateChangedSlot( ApplicationApplication _this, 
  XObject sender );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void ApplicationApplication_OnInspectionModeEventSlot( ApplicationApplication _this, 
  XObject sender );

/* 'C' function for method : 'Application::Application.ProcInspectionDisplay()' */
void ApplicationApplication_ProcInspectionDisplay( ApplicationApplication _this );

/* 'C' function for method : 'Application::Application.StopInspection()' */
void ApplicationApplication_StopInspection( ApplicationApplication _this );

/* 'C' function for method : 'Application::Application.SwitchToMeterHome()' */
void ApplicationApplication_SwitchToMeterHome( ApplicationApplication _this );

#ifdef __cplusplus
  }
#endif

#endif /* _ApplicationApplication_H */

/* Embedded Wizard */
