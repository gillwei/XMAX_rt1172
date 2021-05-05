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

#ifndef _MenuItemWrapper_H
#define _MenuItemWrapper_H

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

/* Forward declaration of the class Menu::ItemWrapper */
#ifndef _MenuItemWrapper_
  EW_DECLARE_CLASS( MenuItemWrapper )
#define _MenuItemWrapper_
#endif


/* This is a GUI component. */
EW_DEFINE_FIELDS( MenuItemWrapper, CoreGroup )
  EW_PROPERTY( OnActivate,      XSlot )
  EW_PROPERTY( OnLongEnterKeyActivate, XSlot )
  EW_PROPERTY( Title,           XString )
  EW_PROPERTY( Value,           XString )
  EW_PROPERTY( Message,         XString )
  EW_PROPERTY( ReceivedTime,    XString )
  EW_PROPERTY( Unit,            XString )
  EW_PROPERTY( ItemClass,       XClass )
  EW_PROPERTY( Height,          XInt32 )
  EW_PROPERTY( Uid,             XUInt32 )
  EW_PROPERTY( Category,        XEnum )
  EW_PROPERTY( ToggleEnabled,   XBool )
  EW_PROPERTY( DDModeEnabled,   XBool )
  EW_PROPERTY( Focusable,       XBool )
  EW_PROPERTY( Checked,         XBool )
EW_END_OF_FIELDS( MenuItemWrapper )

/* Virtual Method Table (VMT) for the class : 'Menu::ItemWrapper' */
EW_DEFINE_METHODS( MenuItemWrapper, CoreGroup )
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
  EW_METHOD( OnGetEnabled,      XBool )( MenuItemWrapper _this )
  EW_METHOD( OnSetEnabled,      void )( MenuItemWrapper _this, XBool value )
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
EW_END_OF_METHODS( MenuItemWrapper )

/* 'C' function for method : 'Menu::ItemWrapper.OnGetEnabled()' */
XBool MenuItemWrapper_OnGetEnabled( MenuItemWrapper _this );

/* 'C' function for method : 'Menu::ItemWrapper.OnSetEnabled()' */
void MenuItemWrapper_OnSetEnabled( MenuItemWrapper _this, XBool value );

/* 'C' function for method : 'Menu::ItemWrapper.OnSetItemClass()' */
void MenuItemWrapper_OnSetItemClass( MenuItemWrapper _this, XClass value );

/* 'C' function for method : 'Menu::ItemWrapper.OnSetTitle()' */
void MenuItemWrapper_OnSetTitle( MenuItemWrapper _this, XString value );

/* 'C' function for method : 'Menu::ItemWrapper.OnActivateSlot()' */
void MenuItemWrapper_OnActivateSlot( MenuItemWrapper _this, XObject sender );

/* 'C' function for method : 'Menu::ItemWrapper.OnSetChecked()' */
void MenuItemWrapper_OnSetChecked( MenuItemWrapper _this, XBool value );

/* 'C' function for method : 'Menu::ItemWrapper.OnLongEnterKeyActivatedSlot()' */
void MenuItemWrapper_OnLongEnterKeyActivatedSlot( MenuItemWrapper _this, XObject 
  sender );

/* 'C' function for method : 'Menu::ItemWrapper.OnSetFocusable()' */
void MenuItemWrapper_OnSetFocusable( MenuItemWrapper _this, XBool value );

/* 'C' function for method : 'Menu::ItemWrapper.OnSetDDModeEnabled()' */
void MenuItemWrapper_OnSetDDModeEnabled( MenuItemWrapper _this, XBool value );

/* 'C' function for method : 'Menu::ItemWrapper.OnSetValue()' */
void MenuItemWrapper_OnSetValue( MenuItemWrapper _this, XString value );

/* 'C' function for method : 'Menu::ItemWrapper.OnSetMessage()' */
void MenuItemWrapper_OnSetMessage( MenuItemWrapper _this, XString value );

/* 'C' function for method : 'Menu::ItemWrapper.OnSetReceivedTime()' */
void MenuItemWrapper_OnSetReceivedTime( MenuItemWrapper _this, XString value );

/* 'C' function for method : 'Menu::ItemWrapper.OnSetCategory()' */
void MenuItemWrapper_OnSetCategory( MenuItemWrapper _this, XEnum value );

/* 'C' function for method : 'Menu::ItemWrapper.OnSetUid()' */
void MenuItemWrapper_OnSetUid( MenuItemWrapper _this, XUInt32 value );

/* 'C' function for method : 'Menu::ItemWrapper.OnSetToggleEnabled()' */
void MenuItemWrapper_OnSetToggleEnabled( MenuItemWrapper _this, XBool value );

/* 'C' function for method : 'Menu::ItemWrapper.OnSetUnit()' */
void MenuItemWrapper_OnSetUnit( MenuItemWrapper _this, XString value );

/* 'C' function for method : 'Menu::ItemWrapper.OnSetHour()' */
void MenuItemWrapper_OnSetHour( MenuItemWrapper _this, XString value );

/* 'C' function for method : 'Menu::ItemWrapper.OnSetMinute()' */
void MenuItemWrapper_OnSetMinute( MenuItemWrapper _this, XString value );

#ifdef __cplusplus
  }
#endif

#endif /* _MenuItemWrapper_H */

/* Embedded Wizard */
