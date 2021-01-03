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

#ifndef _LauncherLNC_Main_H
#define _LauncherLNC_Main_H

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
#include "_EffectsRectEffect.h"
#include "_LauncherLNC_Base.h"
#include "_LauncherLNC_RotaryPlate.h"
#include "_ViewsWallpaper.h"

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

/* Forward declaration of the class Launcher::LNC_Main */
#ifndef _LauncherLNC_Main_
  EW_DECLARE_CLASS( LauncherLNC_Main )
#define _LauncherLNC_Main_
#endif


/* Deklaration of class : 'Launcher::LNC_Main' */
EW_DEFINE_FIELDS( LauncherLNC_Main, ComponentsBaseComponent )
  EW_OBJECT  ( BaseSlideInEffect, EffectsRectEffect )
  EW_OBJECT  ( BaseSlideOutEffect, EffectsRectEffect )
  EW_OBJECT  ( RotaryPlateSlideInEffect, EffectsRectEffect )
  EW_OBJECT  ( RotaryPlateSlideOutEffect, EffectsRectEffect )
  EW_OBJECT  ( LNC_Base,        LauncherLNC_Base )
  EW_OBJECT  ( LNC_RotaryPlate, LauncherLNC_RotaryPlate )
  EW_OBJECT  ( StatusBarShadowImage, ViewsWallpaper )
  EW_VARIABLE( NextItem,        XEnum )
  EW_VARIABLE( CurrentItem,     XEnum )
  EW_VARIABLE( PreviousItem,    XEnum )
  EW_VARIABLE( WindScreenEnabled, XBool )
  EW_VARIABLE( GripWarmerEnabled, XBool )
  EW_VARIABLE( SeatHeaterEnabled, XBool )
  EW_VARIABLE( TCSEnabled,      XBool )
EW_END_OF_FIELDS( LauncherLNC_Main )

/* Virtual Method Table (VMT) for the class : 'Launcher::LNC_Main' */
EW_DEFINE_METHODS( LauncherLNC_Main, ComponentsBaseComponent )
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
  EW_METHOD( OnShortDownKeyActivated, void )( LauncherLNC_Main _this )
  EW_METHOD( OnShortUpKeyActivated, void )( LauncherLNC_Main _this )
  EW_METHOD( OnShortEnterKeyActivated, void )( LauncherLNC_Main _this )
  EW_METHOD( OnShortHomeKeyActivated, void )( LauncherLNC_Main _this )
  EW_METHOD( OnLongDownKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLongUpKeyActivated, void )( ComponentsBaseComponent _this )
EW_END_OF_METHODS( LauncherLNC_Main )

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void LauncherLNC_Main_Init( LauncherLNC_Main _this, XHandle aArg );

/* 'C' function for method : 'Launcher::LNC_Main.OnShortDownKeyActivated()' */
void LauncherLNC_Main_OnShortDownKeyActivated( LauncherLNC_Main _this );

/* 'C' function for method : 'Launcher::LNC_Main.OnShortUpKeyActivated()' */
void LauncherLNC_Main_OnShortUpKeyActivated( LauncherLNC_Main _this );

/* 'C' function for method : 'Launcher::LNC_Main.OnShortEnterKeyActivated()' */
void LauncherLNC_Main_OnShortEnterKeyActivated( LauncherLNC_Main _this );

/* 'C' function for method : 'Launcher::LNC_Main.OnShortHomeKeyActivated()' */
void LauncherLNC_Main_OnShortHomeKeyActivated( LauncherLNC_Main _this );

/* 'C' function for method : 'Launcher::LNC_Main.OnCurrentItemChangedSlot()' */
void LauncherLNC_Main_OnCurrentItemChangedSlot( LauncherLNC_Main _this, XObject 
  sender );

/* 'C' function for method : 'Launcher::LNC_Main.GetInitialSelectedItem()' */
XEnum LauncherLNC_Main_GetInitialSelectedItem( LauncherLNC_Main _this );

/* 'C' function for method : 'Launcher::LNC_Main.GetNextItem()' */
XEnum LauncherLNC_Main_GetNextItem( LauncherLNC_Main _this, XEnum aBaseItem );

/* 'C' function for method : 'Launcher::LNC_Main.GetPreviousItem()' */
XEnum LauncherLNC_Main_GetPreviousItem( LauncherLNC_Main _this, XEnum aBaseItem );

/* 'C' function for method : 'Launcher::LNC_Main.OnSelectedAnimationFinishedSlot()' */
void LauncherLNC_Main_OnSelectedAnimationFinishedSlot( LauncherLNC_Main _this, XObject 
  sender );

/* 'C' function for method : 'Launcher::LNC_Main.OnSlideOutFinishedSlot()' */
void LauncherLNC_Main_OnSlideOutFinishedSlot( LauncherLNC_Main _this, XObject sender );

#ifdef __cplusplus
  }
#endif

#endif /* _LauncherLNC_Main_H */

/* Embedded Wizard */
