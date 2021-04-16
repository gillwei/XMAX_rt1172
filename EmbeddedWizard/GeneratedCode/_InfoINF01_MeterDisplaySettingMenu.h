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

#ifndef _InfoINF01_MeterDisplaySettingMenu_H
#define _InfoINF01_MeterDisplaySettingMenu_H

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

#include "_ComponentsDDModeMask.h"
#include "_CoreKeyPressHandler.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_MenuBaseMenuView.h"
#include "_MenuVerticalMenu.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"

/* Forward declaration of the class Components::BaseMainBG */
#ifndef _ComponentsBaseMainBG_
  EW_DECLARE_CLASS( ComponentsBaseMainBG )
#define _ComponentsBaseMainBG_
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

/* Forward declaration of the class Info::INF01_MeterDisplaySettingMenu */
#ifndef _InfoINF01_MeterDisplaySettingMenu_
  EW_DECLARE_CLASS( InfoINF01_MeterDisplaySettingMenu )
#define _InfoINF01_MeterDisplaySettingMenu_
#endif

/* Forward declaration of the class Menu::ItemBase */
#ifndef _MenuItemBase_
  EW_DECLARE_CLASS( MenuItemBase )
#define _MenuItemBase_
#endif


/* Deklaration of class : 'Info::INF01_MeterDisplaySettingMenu' */
EW_DEFINE_FIELDS( InfoINF01_MeterDisplaySettingMenu, MenuBaseMenuView )
  EW_OBJECT  ( CheckMarkUpdateTimer, CoreTimer )
  EW_ARRAY   ( ItemTitleArray,  XString, [3])
  EW_VARIABLE( SelectedHomeType, XEnum )
EW_END_OF_FIELDS( InfoINF01_MeterDisplaySettingMenu )

/* Virtual Method Table (VMT) for the class : 'Info::INF01_MeterDisplaySettingMenu' */
EW_DEFINE_METHODS( InfoINF01_MeterDisplaySettingMenu, MenuBaseMenuView )
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
  EW_METHOD( DismissDialog,     void )( CoreGroup _this, CoreGroup aDialogGroup, 
    EffectsTransition aOverrideDismissTransition, EffectsTransition aOverrideOverlayTransition, 
    EffectsTransition aOverrideRestoreTransition, XSlot aComplete, XSlot aCancel, 
    XBool aCombine )
  EW_METHOD( DispatchEvent,     XObject )( CoreGroup _this, CoreEvent aEvent )
  EW_METHOD( BroadcastEvent,    XObject )( CoreGroup _this, CoreEvent aEvent, XSet 
    aFilter )
  EW_METHOD( UpdateLayout,      void )( CoreGroup _this, XPoint aSize )
  EW_METHOD( UpdateViewState,   void )( InfoINF01_MeterDisplaySettingMenu _this, 
    XSet aState )
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
  EW_METHOD( OnShortHomeKeyActivated, void )( ComponentsBaseMainBG _this )
  EW_METHOD( OnLongDownKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLongUpKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLongEnterKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLongHomeKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnShortMagicKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnSetDDModeEnabled, void )( ComponentsBaseMainBG _this, XBool value )
  EW_METHOD( OnDownKeyReleased, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnUpKeyReleased,   void )( ComponentsBaseComponent _this )
  EW_METHOD( LoadItemClass,     XClass )( InfoINF01_MeterDisplaySettingMenu _this, 
    XInt32 aItemNo )
  EW_METHOD( LoadItemTitle,     XString )( InfoINF01_MeterDisplaySettingMenu _this, 
    XInt32 aItemNo )
  EW_METHOD( OnItemActivate,    void )( InfoINF01_MeterDisplaySettingMenu _this, 
    XInt32 aItemNo, MenuItemBase aMenuItem )
  EW_METHOD( LoadItemChecked,   XBool )( InfoINF01_MeterDisplaySettingMenu _this, 
    XInt32 aItemNo )
  EW_METHOD( LoadItemEnabled,   XBool )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemBaseValue, XString )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemMessage,   XString )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemReceivedTime, XString )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemCategory,  XEnum )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemUid,       XUInt32 )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemToggle,    XBool )( MenuBaseMenuView _this, XInt32 aItemNo )
EW_END_OF_METHODS( InfoINF01_MeterDisplaySettingMenu )

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void InfoINF01_MeterDisplaySettingMenu_Init( InfoINF01_MeterDisplaySettingMenu _this, 
  XHandle aArg );

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
void InfoINF01_MeterDisplaySettingMenu_UpdateViewState( InfoINF01_MeterDisplaySettingMenu _this, 
  XSet aState );

/* 'C' function for method : 'Info::INF01_MeterDisplaySettingMenu.LoadItemClass()' */
XClass InfoINF01_MeterDisplaySettingMenu_LoadItemClass( InfoINF01_MeterDisplaySettingMenu _this, 
  XInt32 aItemNo );

/* 'C' function for method : 'Info::INF01_MeterDisplaySettingMenu.LoadItemTitle()' */
XString InfoINF01_MeterDisplaySettingMenu_LoadItemTitle( InfoINF01_MeterDisplaySettingMenu _this, 
  XInt32 aItemNo );

/* 'C' function for method : 'Info::INF01_MeterDisplaySettingMenu.OnItemActivate()' */
void InfoINF01_MeterDisplaySettingMenu_OnItemActivate( InfoINF01_MeterDisplaySettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem );

/* 'C' function for method : 'Info::INF01_MeterDisplaySettingMenu.LoadItemChecked()' */
XBool InfoINF01_MeterDisplaySettingMenu_LoadItemChecked( InfoINF01_MeterDisplaySettingMenu _this, 
  XInt32 aItemNo );

/* 'C' function for method : 'Info::INF01_MeterDisplaySettingMenu.OnCheckMarkUpdateSlot()' */
void InfoINF01_MeterDisplaySettingMenu_OnCheckMarkUpdateSlot( InfoINF01_MeterDisplaySettingMenu _this, 
  XObject sender );

#ifdef __cplusplus
  }
#endif

#endif /* _InfoINF01_MeterDisplaySettingMenu_H */

/* Embedded Wizard */
