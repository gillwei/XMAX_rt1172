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

#ifndef _MenuVerticalMenu_H
#define _MenuVerticalMenu_H

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
#include "_CoreVerticalList.h"
#include "_EffectsInt32Effect.h"
#include "_MenuArrowScrollBar.h"
#include "_MenuScrollbar.h"
#include "_ViewsBorder.h"

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

/* Forward declaration of the class Menu::VerticalMenu */
#ifndef _MenuVerticalMenu_
  EW_DECLARE_CLASS( MenuVerticalMenu )
#define _MenuVerticalMenu_
#endif


/* Deklaration of class : 'Menu::VerticalMenu' */
EW_DEFINE_FIELDS( MenuVerticalMenu, ComponentsBaseComponent )
  EW_OBJECT  ( MenuList,        CoreVerticalList )
  EW_OBJECT  ( Scrollbar,       MenuScrollbar )
  EW_OBJECT  ( FocusFrame,      ViewsBorder )
  EW_OBJECT  ( ArrowScrollBar,  MenuArrowScrollBar )
  EW_OBJECT  ( PageScrollEffect, EffectsInt32Effect )
  EW_PROPERTY( NoOfItems,       XInt32 )
  EW_PROPERTY( ItemHeight,      XInt32 )
  EW_PROPERTY( ItemNumPerPage,  XInt32 )
  EW_PROPERTY( FocusFrameBounds, XRect )
  EW_PROPERTY( SelectedItem,    XInt32 )
  EW_PROPERTY( ScrollbarVisible, XBool )
  EW_PROPERTY( ArrowScrollBarVisible, XBool )
  EW_PROPERTY( Focusable,       XBool )
EW_END_OF_FIELDS( MenuVerticalMenu )

/* Virtual Method Table (VMT) for the class : 'Menu::VerticalMenu' */
EW_DEFINE_METHODS( MenuVerticalMenu, ComponentsBaseComponent )
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
  EW_METHOD( UpdateViewState,   void )( MenuVerticalMenu _this, XSet aState )
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
  EW_METHOD( OnShortDownKeyActivated, void )( MenuVerticalMenu _this )
  EW_METHOD( OnShortUpKeyActivated, void )( MenuVerticalMenu _this )
  EW_METHOD( OnShortEnterKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnShortHomeKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLongDownKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLongUpKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLongEnterKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLongHomeKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnShortMagicKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnSetDDModeEnabled, void )( ComponentsBaseComponent _this, XBool value )
  EW_METHOD( OnDownKeyReleased, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnUpKeyReleased,   void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLoadItemSlot,    void )( MenuVerticalMenu _this, XObject sender )
EW_END_OF_METHODS( MenuVerticalMenu )

/* The method UpdateViewState() is invoked automatically after the state of the 
   component has been changed. This method can be overridden and filled with logic 
   to ensure the visual aspect of the component does reflect its current state. 
   For example, the 'enabled' state of the component can affect its colors (disabled 
   components may appear pale). In this case the logic of the method should modify 
   the respective color properties accordingly to the current 'enabled' state. 
   The current state of the component is passed as a set in the parameter aState. 
   It reflects the very basic component state like its visibility or the ability 
   to react to user inputs. Beside this common state, the method can also involve 
   any other variables used in the component as long as they reflect its current 
   state. For example, the toggle switch component can take in account its toggle 
   state 'on' or 'off' and change accordingly the location of the slider, etc.
   Usually, this method will be invoked automatically by the framework. Optionally 
   you can request its invocation by using the method @InvalidateViewState(). */
void MenuVerticalMenu_UpdateViewState( MenuVerticalMenu _this, XSet aState );

/* 'C' function for method : 'Menu::VerticalMenu.OnShortDownKeyActivated()' */
void MenuVerticalMenu_OnShortDownKeyActivated( MenuVerticalMenu _this );

/* 'C' function for method : 'Menu::VerticalMenu.OnShortUpKeyActivated()' */
void MenuVerticalMenu_OnShortUpKeyActivated( MenuVerticalMenu _this );

/* This method is called by 'VerticalList' every time the list loads or updates 
   an item. */
void MenuVerticalMenu_OnLoadItemSlot( MenuVerticalMenu _this, XObject sender );

/* Wrapper function for the virtual method : 'Menu::VerticalMenu.OnLoadItemSlot()' */
void MenuVerticalMenu__OnLoadItemSlot( void* _this, XObject sender );

/* 'C' function for method : 'Menu::VerticalMenu.OnItemActivateSlot()' */
void MenuVerticalMenu_OnItemActivateSlot( MenuVerticalMenu _this, XObject sender );

/* 'C' function for method : 'Menu::VerticalMenu.OnSetNoOfItems()' */
void MenuVerticalMenu_OnSetNoOfItems( MenuVerticalMenu _this, XInt32 value );

/* 'C' function for method : 'Menu::VerticalMenu.InvalidateItems()' */
void MenuVerticalMenu_InvalidateItems( MenuVerticalMenu _this, XInt32 aFirstItem, 
  XInt32 aLastItem );

/* 'C' function for method : 'Menu::VerticalMenu.OnSetItemHeight()' */
void MenuVerticalMenu_OnSetItemHeight( MenuVerticalMenu _this, XInt32 value );

/* 'C' function for method : 'Menu::VerticalMenu.MoveFocusFrame()' */
void MenuVerticalMenu_MoveFocusFrame( MenuVerticalMenu _this );

/* 'C' function for method : 'Menu::VerticalMenu.OnSetItemNumPerPage()' */
void MenuVerticalMenu_OnSetItemNumPerPage( MenuVerticalMenu _this, XInt32 value );

/* 'C' function for method : 'Menu::VerticalMenu.UpdateListHeight()' */
void MenuVerticalMenu_UpdateListHeight( MenuVerticalMenu _this );

/* 'C' function for method : 'Menu::VerticalMenu.SwitchToPageOfSelectedItem()' */
void MenuVerticalMenu_SwitchToPageOfSelectedItem( MenuVerticalMenu _this );

/* 'C' function for method : 'Menu::VerticalMenu.OnSetArrowScrollBarVisible()' */
void MenuVerticalMenu_OnSetArrowScrollBarVisible( MenuVerticalMenu _this, XBool 
  value );

/* 'C' function for method : 'Menu::VerticalMenu.OnPageScrolledSlot()' */
void MenuVerticalMenu_OnPageScrolledSlot( MenuVerticalMenu _this, XObject sender );

/* 'C' function for method : 'Menu::VerticalMenu.HideArrowScrollBar()' */
void MenuVerticalMenu_HideArrowScrollBar( MenuVerticalMenu _this );

/* 'C' function for method : 'Menu::VerticalMenu.RestoreArrowScrollBar()' */
void MenuVerticalMenu_RestoreArrowScrollBar( MenuVerticalMenu _this );

/* 'C' function for method : 'Menu::VerticalMenu.OnSetScrollbarVisible()' */
void MenuVerticalMenu_OnSetScrollbarVisible( MenuVerticalMenu _this, XBool value );

/* 'C' function for method : 'Menu::VerticalMenu.OnSetFocusFrameBounds()' */
void MenuVerticalMenu_OnSetFocusFrameBounds( MenuVerticalMenu _this, XRect value );

/* 'C' function for method : 'Menu::VerticalMenu.OnSetSelectedItem()' */
void MenuVerticalMenu_OnSetSelectedItem( MenuVerticalMenu _this, XInt32 value );

/* 'C' function for method : 'Menu::VerticalMenu.HideScrollbar()' */
void MenuVerticalMenu_HideScrollbar( MenuVerticalMenu _this );

/* 'C' function for method : 'Menu::VerticalMenu.RestoreScrollbar()' */
void MenuVerticalMenu_RestoreScrollbar( MenuVerticalMenu _this );

/* 'C' function for method : 'Menu::VerticalMenu.RestoreFocusFrame()' */
void MenuVerticalMenu_RestoreFocusFrame( MenuVerticalMenu _this );

#ifdef __cplusplus
  }
#endif

#endif /* _MenuVerticalMenu_H */

/* Embedded Wizard */
