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
* Version  : 11.00
* Profile  : iMX_RT
* Platform : NXP.iMX_RT_VGLite.RGBA8888
*
*******************************************************************************/

#ifndef _StatusBarMain_H
#define _StatusBarMain_H

#ifdef __cplusplus
  extern "C"
  {
#endif

#include "ewrte.h"
#if EW_RTE_VERSION != 0x000B0000
  #error Wrong version of Embedded Wizard Runtime Environment.
#endif

#include "ewgfx.h"
#if EW_GFX_VERSION != 0x000B0000
  #error Wrong version of Embedded Wizard Graphics Engine.
#endif

#include "_CoreGroup.h"
#include "_CorePropertyObserver.h"
#include "_CoreSystemEventHandler.h"
#include "_StatusBarClock.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"

/* Forward declaration of the class Core::DialogContext */
#ifndef _CoreDialogContext_
  EW_DECLARE_CLASS( CoreDialogContext )
#define _CoreDialogContext_
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

/* Forward declaration of the class StatusBar::Main */
#ifndef _StatusBarMain_
  EW_DECLARE_CLASS( StatusBarMain )
#define _StatusBarMain_
#endif


/* Deklaration of class : 'StatusBar::Main' */
EW_DEFINE_FIELDS( StatusBarMain, CoreGroup )
  EW_OBJECT  ( Background,      ViewsRectangle )
  EW_OBJECT  ( Divider,         ViewsImage )
  EW_OBJECT  ( Clock,           StatusBarClock )
  EW_OBJECT  ( MotoConEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( BatteryIcon,     ViewsImage )
  EW_OBJECT  ( HeadsetIcon,     ViewsImage )
  EW_OBJECT  ( AppIcon,         ViewsImage )
  EW_OBJECT  ( BtIcon,          ViewsImage )
  EW_OBJECT  ( BTEnabledObserver, CorePropertyObserver )
  EW_OBJECT  ( PairdDeviceChangedObserver, CorePropertyObserver )
  EW_OBJECT  ( SignalLevelIcon, ViewsImage )
  EW_OBJECT  ( VehicleDataReceivedEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( PhoneIcon,       ViewsImage )
  EW_OBJECT  ( PhoneCallStateChangedEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( NotificationListUpdatedSystemEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( MessageIcon,     ViewsImage )
  EW_OBJECT  ( GripWarmerIcon,  ViewsImage )
  EW_OBJECT  ( SeatHeaterIcon,  ViewsImage )
  EW_OBJECT  ( AirTemperatureText, ViewsText )
  EW_OBJECT  ( UnitImage,       ViewsImage )
  EW_VARIABLE( IsMotoConConnected, XBool )
EW_END_OF_FIELDS( StatusBarMain )

/* Virtual Method Table (VMT) for the class : 'StatusBar::Main' */
EW_DEFINE_METHODS( StatusBarMain, CoreGroup )
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
  EW_METHOD( OnSetVisible,      void )( CoreGroup _this, XBool value )
  EW_METHOD( IsCurrentDialog,   XBool )( CoreGroup _this )
  EW_METHOD( IsActiveDialog,    XBool )( CoreGroup _this, XBool aRecursive )
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
EW_END_OF_METHODS( StatusBarMain )

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void StatusBarMain_Init( StatusBarMain _this, XHandle aArg );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void StatusBarMain_OnMotoConEventReceived( StatusBarMain _this, XObject sender );

/* 'C' function for method : 'StatusBar::Main.UpdateMotoConConnectionStatus()' */
void StatusBarMain_UpdateMotoConConnectionStatus( StatusBarMain _this );

/* 'C' function for method : 'StatusBar::Main.UpdateBatteryIcon()' */
void StatusBarMain_UpdateBatteryIcon( StatusBarMain _this );

/* 'C' function for method : 'StatusBar::Main.UpdateHeadsetIcon()' */
void StatusBarMain_UpdateHeadsetIcon( StatusBarMain _this );

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void StatusBarMain_OnBtcConnectionStatusChangedSlot( StatusBarMain _this, XObject 
  sender );

/* 'C' function for method : 'StatusBar::Main.UpdateAppIcon()' */
void StatusBarMain_UpdateAppIcon( StatusBarMain _this );

/* 'C' function for method : 'StatusBar::Main.UpdatePhoneCellSignalLevelIcon()' */
void StatusBarMain_UpdatePhoneCellSignalLevelIcon( StatusBarMain _this );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void StatusBarMain_OnVehicleDataReceivedSlot( StatusBarMain _this, XObject sender );

/* 'C' function for method : 'StatusBar::Main.OnUpdatePhoneIconSlot()' */
void StatusBarMain_OnUpdatePhoneIconSlot( StatusBarMain _this, XObject sender );

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void StatusBarMain_OnNotificationListUpdatedSlot( StatusBarMain _this, XObject sender );

/* 'C' function for method : 'StatusBar::Main.UpdateGripWarmerIcon()' */
void StatusBarMain_UpdateGripWarmerIcon( StatusBarMain _this );

/* 'C' function for method : 'StatusBar::Main.UpdateSeatHeaterIcon()' */
void StatusBarMain_UpdateSeatHeaterIcon( StatusBarMain _this );

/* 'C' function for method : 'StatusBar::Main.UpdateAirTemperature()' */
void StatusBarMain_UpdateAirTemperature( StatusBarMain _this );

/* 'C' function for method : 'StatusBar::Main.UpdateClockVisible()' */
void StatusBarMain_UpdateClockVisible( StatusBarMain _this );

#ifdef __cplusplus
  }
#endif

#endif /* _StatusBarMain_H */

/* Embedded Wizard */
