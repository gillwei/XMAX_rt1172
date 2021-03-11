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

#ifndef _ComponentsBaseComponent_H
#define _ComponentsBaseComponent_H

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

#include "_CoreGroup.h"
#include "_CoreKeyPressHandler.h"

/* Forward declaration of the class Components::BaseComponent */
#ifndef _ComponentsBaseComponent_
  EW_DECLARE_CLASS( ComponentsBaseComponent )
#define _ComponentsBaseComponent_
#endif

/* Forward declaration of the class Core::DialogContext */
#ifndef _CoreDialogContext_
  EW_DECLARE_CLASS( CoreDialogContext )
#define _CoreDialogContext_
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


/* Deklaration of class : 'Components::BaseComponent' */
EW_DEFINE_FIELDS( ComponentsBaseComponent, CoreGroup )
  EW_OBJECT  ( KeyHandler,      CoreKeyPressHandler )
  EW_PROPERTY( HomeKeyTriggerMode, XEnum )
  EW_PROPERTY( EnterKeyTriggerMode, XEnum )
  EW_PROPERTY( DownKeyTriggerMode, XEnum )
  EW_PROPERTY( UpKeyTriggerMode, XEnum )
  EW_PROPERTY( DDModeEnabled,   XBool )
  EW_PROPERTY( PassMagicKey,    XBool )
  EW_PROPERTY( PassEnterKey,    XBool )
  EW_PROPERTY( PassHomeKey,     XBool )
  EW_PROPERTY( PassDownKey,     XBool )
  EW_PROPERTY( PassUpKey,       XBool )
EW_END_OF_FIELDS( ComponentsBaseComponent )

/* Virtual Method Table (VMT) for the class : 'Components::BaseComponent' */
EW_DEFINE_METHODS( ComponentsBaseComponent, CoreGroup )
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
  EW_METHOD( OnShortEnterKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnShortHomeKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLongDownKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLongUpKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLongEnterKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnShortMagicKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnSetDDModeEnabled, void )( ComponentsBaseComponent _this, XBool value )
  EW_METHOD( OnDownKeyReleased, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnUpKeyReleased,   void )( ComponentsBaseComponent _this )
EW_END_OF_METHODS( ComponentsBaseComponent )

/* 'C' function for method : 'Components::BaseComponent.OnKeyPressSlot()' */
void ComponentsBaseComponent_OnKeyPressSlot( ComponentsBaseComponent _this, XObject 
  sender );

/* 'C' function for method : 'Components::BaseComponent.OnKeyHoldSlot()' */
void ComponentsBaseComponent_OnKeyHoldSlot( ComponentsBaseComponent _this, XObject 
  sender );

/* 'C' function for method : 'Components::BaseComponent.OnKeyReleaseSlot()' */
void ComponentsBaseComponent_OnKeyReleaseSlot( ComponentsBaseComponent _this, XObject 
  sender );

/* 'C' function for method : 'Components::BaseComponent.OnShortDownKeyActivated()' */
void ComponentsBaseComponent_OnShortDownKeyActivated( ComponentsBaseComponent _this );

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnShortDownKeyActivated()' */
void ComponentsBaseComponent__OnShortDownKeyActivated( void* _this );

/* 'C' function for method : 'Components::BaseComponent.OnShortUpKeyActivated()' */
void ComponentsBaseComponent_OnShortUpKeyActivated( ComponentsBaseComponent _this );

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnShortUpKeyActivated()' */
void ComponentsBaseComponent__OnShortUpKeyActivated( void* _this );

/* 'C' function for method : 'Components::BaseComponent.OnShortEnterKeyActivated()' */
void ComponentsBaseComponent_OnShortEnterKeyActivated( ComponentsBaseComponent _this );

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnShortEnterKeyActivated()' */
void ComponentsBaseComponent__OnShortEnterKeyActivated( void* _this );

/* 'C' function for method : 'Components::BaseComponent.OnShortHomeKeyActivated()' */
void ComponentsBaseComponent_OnShortHomeKeyActivated( ComponentsBaseComponent _this );

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnShortHomeKeyActivated()' */
void ComponentsBaseComponent__OnShortHomeKeyActivated( void* _this );

/* 'C' function for method : 'Components::BaseComponent.OnLongDownKeyActivated()' */
void ComponentsBaseComponent_OnLongDownKeyActivated( ComponentsBaseComponent _this );

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnLongDownKeyActivated()' */
void ComponentsBaseComponent__OnLongDownKeyActivated( void* _this );

/* 'C' function for method : 'Components::BaseComponent.OnLongUpKeyActivated()' */
void ComponentsBaseComponent_OnLongUpKeyActivated( ComponentsBaseComponent _this );

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnLongUpKeyActivated()' */
void ComponentsBaseComponent__OnLongUpKeyActivated( void* _this );

/* 'C' function for method : 'Components::BaseComponent.OnLongEnterKeyActivated()' */
void ComponentsBaseComponent_OnLongEnterKeyActivated( ComponentsBaseComponent _this );

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnLongEnterKeyActivated()' */
void ComponentsBaseComponent__OnLongEnterKeyActivated( void* _this );

/* 'C' function for method : 'Components::BaseComponent.OnLongHomeKeyActivated()' */
void ComponentsBaseComponent_OnLongHomeKeyActivated( ComponentsBaseComponent _this );

/* 'C' function for method : 'Components::BaseComponent.OnShortMagicKeyActivated()' */
void ComponentsBaseComponent_OnShortMagicKeyActivated( ComponentsBaseComponent _this );

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnShortMagicKeyActivated()' */
void ComponentsBaseComponent__OnShortMagicKeyActivated( void* _this );

/* 'C' function for method : 'Components::BaseComponent.IsDDModeEffected()' */
XBool ComponentsBaseComponent_IsDDModeEffected( ComponentsBaseComponent _this );

/* 'C' function for method : 'Components::BaseComponent.OnSetDDModeEnabled()' */
void ComponentsBaseComponent_OnSetDDModeEnabled( ComponentsBaseComponent _this, 
  XBool value );

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnSetDDModeEnabled()' */
void ComponentsBaseComponent__OnSetDDModeEnabled( void* _this, XBool value );

/* Callback when down key of on trigger mode is released */
void ComponentsBaseComponent_OnDownKeyReleased( ComponentsBaseComponent _this );

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnDownKeyReleased()' */
void ComponentsBaseComponent__OnDownKeyReleased( void* _this );

/* Callback when up key of on trigger mode is released */
void ComponentsBaseComponent_OnUpKeyReleased( ComponentsBaseComponent _this );

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnUpKeyReleased()' */
void ComponentsBaseComponent__OnUpKeyReleased( void* _this );

#ifdef __cplusplus
  }
#endif

#endif /* _ComponentsBaseComponent_H */

/* Embedded Wizard */
