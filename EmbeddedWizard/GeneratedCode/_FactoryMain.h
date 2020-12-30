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

#ifndef _FactoryMain_H
#define _FactoryMain_H

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

#include "_CoreKeyPressHandler.h"
#include "_MenuBaseMenuView.h"
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

/* Forward declaration of the class Effects::Transition */
#ifndef _EffectsTransition_
  EW_DECLARE_CLASS( EffectsTransition )
#define _EffectsTransition_
#endif

/* Forward declaration of the class Factory::Main */
#ifndef _FactoryMain_
  EW_DECLARE_CLASS( FactoryMain )
#define _FactoryMain_
#endif

/* Forward declaration of the class Graphics::Canvas */
#ifndef _GraphicsCanvas_
  EW_DECLARE_CLASS( GraphicsCanvas )
#define _GraphicsCanvas_
#endif

/* Forward declaration of the class Menu::ItemBase */
#ifndef _MenuItemBase_
  EW_DECLARE_CLASS( MenuItemBase )
#define _MenuItemBase_
#endif


/* Deklaration of class : 'Factory::Main' */
EW_DEFINE_FIELDS( FactoryMain, MenuBaseMenuView )
  EW_OBJECT  ( Menu,            MenuVerticalMenu )
  EW_ARRAY   ( ItemTitleArray,  XString, [2])
EW_END_OF_FIELDS( FactoryMain )

/* Virtual Method Table (VMT) for the class : 'Factory::Main' */
EW_DEFINE_METHODS( FactoryMain, MenuBaseMenuView )
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
  EW_METHOD( DismissDialog,     void )( FactoryMain _this, CoreGroup aDialogGroup, 
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
  EW_METHOD( OnLongKeyPressed,  void )( FactoryMain _this, XObject sender )
  EW_METHOD( OnShortDownKeyPressed, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnShortUpKeyPressed, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnShortEnterKeyPressed, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnShortHomeKeyPressed, void )( ComponentsBaseComponent _this )
  EW_METHOD( LoadItemClass,     XClass )( FactoryMain _this, XInt32 aItemNo )
  EW_METHOD( LoadItemTitle,     XString )( FactoryMain _this, XInt32 aItemNo )
  EW_METHOD( OnItemActivate,    void )( FactoryMain _this, XInt32 aItemNo, MenuItemBase 
    aMenuItem )
  EW_METHOD( LoadItemChecked,   XBool )( MenuBaseMenuView _this, XInt32 aItemNo )
  EW_METHOD( LoadItemEnabled,   XBool )( MenuBaseMenuView _this, XInt32 aItemNo )
EW_END_OF_METHODS( FactoryMain )

/* The method DismissDialog() schedules an operation to hide again the component 
   passed in the parameter aDialogGroup. The component has to be presented by a 
   preceding @PresentDialog() or @SwitchToDialog() method invocation. Calling the 
   method DismissDialog() causes the corresponding entry to be removed from the 
   internal stack containing all dialogs existing at the moment in context of 'this' 
   owner component. The dialog component on top of the stack is considered as the 
   active dialog - the dialog, the user may interact with. Other dialogs lying in 
   the background are automatically deactivated and they are suppressed from being 
   able to receive and process user inputs. Accordingly, applying the dismiss operation 
   on the actually active (top) dialog causes the dialog existing eventually behind 
   it to restore its active state.
   The operation to hide the component is performed with an animation specified 
   at its presentation time (in the parameter aDismissTransition of the method @PresentDialog() 
   or @SwitchToDialog()). Alternatively, other transition to hide the component 
   can be specified in the parameter aOverrideDismissTransition.
   Dismissing a dialog may affect the visibility state of the dialog component lying 
   further in the background. In particular, the component in the background will 
   schedule a restore transition as expected to be after the dialog overlaying it 
   is dismissed. When dismissing a dialog, which is not the active one (not on top 
   of the stack), the component in the background will also schedule an overlay 
   transition as resulting from the new overlaying dialog component. Which transitions 
   are performed results primarily from the parameters aOverlayTransition and aRestoreTransition 
   specified at the presentation time of the background dialog component and the 
   parameters aOverrideRestoreTransition specified at the presentation time of the 
   overlaying (just dismissed) dialog component. Furthermore, you can override this 
   behavior by specifying other animations in the parameters aOverrideOverlayTransition 
   and aOverrideRestoreTransition in the invocation of the method DismissDialog().
   The both parameters aComplete and aCancel can be provided with references to 
   slot methods, which are signaled as soon as the dismiss operation is finished 
   (aComplete) or it has been canceled (aCancel) due to other transition being scheduled 
   for the same GUI component aDialogGroup making the actual operation obsolete.
   The dismiss operation is enqueued, so calling @SwitchToDialog(), @PresentDialog() 
   and DismissDialog() several times in sequence for different components in context 
   of 'this' owner component causes the resulting transitions to be executed strictly 
   one after another. This behavior can be changed by passing the value 'true' in 
   the parameter aCombine. In this case, the new operation will be executed together 
   with last prepared but not yet started operation. In this manner several independent 
   transitions can run simultaneously. */
void FactoryMain_DismissDialog( FactoryMain _this, CoreGroup aDialogGroup, EffectsTransition 
  aOverrideDismissTransition, EffectsTransition aOverrideOverlayTransition, EffectsTransition 
  aOverrideRestoreTransition, XSlot aComplete, XSlot aCancel, XBool aCombine );

/* 'C' function for method : 'Factory::Main.OnLongKeyPressed()' */
void FactoryMain_OnLongKeyPressed( FactoryMain _this, XObject sender );

/* 'C' function for method : 'Factory::Main.LoadItemClass()' */
XClass FactoryMain_LoadItemClass( FactoryMain _this, XInt32 aItemNo );

/* 'C' function for method : 'Factory::Main.LoadItemTitle()' */
XString FactoryMain_LoadItemTitle( FactoryMain _this, XInt32 aItemNo );

/* 'C' function for method : 'Factory::Main.OnItemActivate()' */
void FactoryMain_OnItemActivate( FactoryMain _this, XInt32 aItemNo, MenuItemBase 
  aMenuItem );

#ifdef __cplusplus
  }
#endif

#endif /* _FactoryMain_H */

/* Embedded Wizard */
