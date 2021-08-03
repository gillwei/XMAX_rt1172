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

#ifndef _MenuBaseMenuView_H
#define _MenuBaseMenuView_H

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

#include "_ComponentsBaseMainBG.h"
#include "_ComponentsDDModeMask.h"
#include "_CoreKeyPressHandler.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_MenuVerticalMenu.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"

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

/* Forward declaration of the class Menu::BaseMenuView */
#ifndef _MenuBaseMenuView_
  EW_DECLARE_CLASS( MenuBaseMenuView )
#define _MenuBaseMenuView_
#endif

/* Forward declaration of the class Menu::ItemBase */
#ifndef _MenuItemBase_
  EW_DECLARE_CLASS( MenuItemBase )
#define _MenuItemBase_
#endif


/* Deklaration of class : 'Menu::BaseMenuView' */
EW_DEFINE_FIELDS( MenuBaseMenuView, ComponentsBaseMainBG )
  EW_OBJECT  ( Menu,            MenuVerticalMenu )
EW_END_OF_FIELDS( MenuBaseMenuView )

/* Virtual Method Table (VMT) for the class : 'Menu::BaseMenuView' */
EW_DEFINE_METHODS( MenuBaseMenuView, ComponentsBaseMainBG )
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
  EW_METHOD( GetViewAtIndex,    CoreView )( CoreGroup _this, XInt32 aIndex )
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
  EW_METHOD( OnShortHomeKeyActivated, void )( ComponentsBaseMainBG _this )
  EW_METHOD( OnLongDownKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLongUpKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLongEnterKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLongHomeKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnShortMagicKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnSetDDModeEnabled, void )( MenuBaseMenuView _this, XBool value )
  EW_METHOD( OnDownKeyReleased, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnUpKeyReleased,   void )( ComponentsBaseComponent _this )
  EW_METHOD( LoadItemClass,     XClass )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemTitle,     XString )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( OnItemActivate,    void )( MenuBaseMenuView _this, XInt32 aItemNo, 
    MenuItemBase aMenuItem )
  EW_METHOD( LoadItemChecked,   XBool )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemEnabled,   XBool )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemBaseValue, XString )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemMessage,   XString )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemReceivedTime, XString )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemCategory,  XEnum )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemUid,       XUInt32 )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemToggle,    XBool )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemUnit,      XString )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemValue,     XString )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( OnItemLongEnterKeyActivate, void )( MenuBaseMenuView _this, XInt32 
    aItemNo, MenuItemBase aMenuItem )
  EW_METHOD( LoadItemHour,      XString )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemMinute,    XString )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadPoiListItemValue, XString )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadPoiListItemUnit, XString )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemIcon1Visible, XBool )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemIcon2Visible, XBool )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemDeviceAddress, XUInt64 )( MenuBaseMenuView _this, XInt32 aItemNo )
EW_END_OF_METHODS( MenuBaseMenuView )

/* 'C' function for method : 'Menu::BaseMenuView.ReInit()' */
void MenuBaseMenuView_ReInit( MenuBaseMenuView _this );

/* super( value ); */
void MenuBaseMenuView_OnSetDDModeEnabled( MenuBaseMenuView _this, XBool value );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemClass()' */
XClass MenuBaseMenuView_LoadItemClass( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemClass()' */
XClass MenuBaseMenuView__LoadItemClass( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemTitle()' */
XString MenuBaseMenuView_LoadItemTitle( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemTitle()' */
XString MenuBaseMenuView__LoadItemTitle( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.OnItemActivate()' */
void MenuBaseMenuView_OnItemActivate( MenuBaseMenuView _this, XInt32 aItemNo, MenuItemBase 
  aMenuItem );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.OnItemActivate()' */
void MenuBaseMenuView__OnItemActivate( void* _this, XInt32 aItemNo, MenuItemBase 
  aMenuItem );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemChecked()' */
XBool MenuBaseMenuView_LoadItemChecked( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemChecked()' */
XBool MenuBaseMenuView__LoadItemChecked( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemEnabled()' */
XBool MenuBaseMenuView_LoadItemEnabled( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemEnabled()' */
XBool MenuBaseMenuView__LoadItemEnabled( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemBaseValue()' */
XString MenuBaseMenuView_LoadItemBaseValue( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemBaseValue()' */
XString MenuBaseMenuView__LoadItemBaseValue( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemMessage()' */
XString MenuBaseMenuView_LoadItemMessage( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemMessage()' */
XString MenuBaseMenuView__LoadItemMessage( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemReceivedTime()' */
XString MenuBaseMenuView_LoadItemReceivedTime( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemReceivedTime()' */
XString MenuBaseMenuView__LoadItemReceivedTime( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemCategory()' */
XEnum MenuBaseMenuView_LoadItemCategory( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemCategory()' */
XEnum MenuBaseMenuView__LoadItemCategory( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemUid()' */
XUInt32 MenuBaseMenuView_LoadItemUid( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemUid()' */
XUInt32 MenuBaseMenuView__LoadItemUid( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemToggle()' */
XBool MenuBaseMenuView_LoadItemToggle( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemToggle()' */
XBool MenuBaseMenuView__LoadItemToggle( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemUnit()' */
XString MenuBaseMenuView_LoadItemUnit( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemUnit()' */
XString MenuBaseMenuView__LoadItemUnit( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemValue()' */
XString MenuBaseMenuView_LoadItemValue( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemValue()' */
XString MenuBaseMenuView__LoadItemValue( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.OnItemLongEnterKeyActivate()' */
void MenuBaseMenuView_OnItemLongEnterKeyActivate( MenuBaseMenuView _this, XInt32 
  aItemNo, MenuItemBase aMenuItem );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.OnItemLongEnterKeyActivate()' */
void MenuBaseMenuView__OnItemLongEnterKeyActivate( void* _this, XInt32 aItemNo, 
  MenuItemBase aMenuItem );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemHour()' */
XString MenuBaseMenuView_LoadItemHour( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemHour()' */
XString MenuBaseMenuView__LoadItemHour( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemMinute()' */
XString MenuBaseMenuView_LoadItemMinute( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemMinute()' */
XString MenuBaseMenuView__LoadItemMinute( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.LoadPoiListItemValue()' */
XString MenuBaseMenuView_LoadPoiListItemValue( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadPoiListItemValue()' */
XString MenuBaseMenuView__LoadPoiListItemValue( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.LoadPoiListItemUnit()' */
XString MenuBaseMenuView_LoadPoiListItemUnit( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadPoiListItemUnit()' */
XString MenuBaseMenuView__LoadPoiListItemUnit( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemIcon1Visible()' */
XBool MenuBaseMenuView_LoadItemIcon1Visible( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemIcon1Visible()' */
XBool MenuBaseMenuView__LoadItemIcon1Visible( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemIcon2Visible()' */
XBool MenuBaseMenuView_LoadItemIcon2Visible( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemIcon2Visible()' */
XBool MenuBaseMenuView__LoadItemIcon2Visible( void* _this, XInt32 aItemNo );

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemDeviceAddress()' */
XUInt64 MenuBaseMenuView_LoadItemDeviceAddress( MenuBaseMenuView _this, XInt32 aItemNo );

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemDeviceAddress()' */
XUInt64 MenuBaseMenuView__LoadItemDeviceAddress( void* _this, XInt32 aItemNo );

#ifdef __cplusplus
  }
#endif

#endif /* _MenuBaseMenuView_H */

/* Embedded Wizard */
