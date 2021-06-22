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

#ifndef _LauncherLNC_RotaryPlate_H
#define _LauncherLNC_RotaryPlate_H

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

#include "_ComponentsBaseComponent.h"
#include "_CoreKeyPressHandler.h"
#include "_CoreTimer.h"
#include "_EffectsRectEffect.h"
#include "_ViewsImage.h"

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

/* Forward declaration of the class Launcher::LNC_RotaryPlate */
#ifndef _LauncherLNC_RotaryPlate_
  EW_DECLARE_CLASS( LauncherLNC_RotaryPlate )
#define _LauncherLNC_RotaryPlate_
#endif

/* Forward declaration of the class Resources::Bitmap */
#ifndef _ResourcesBitmap_
  EW_DECLARE_CLASS( ResourcesBitmap )
#define _ResourcesBitmap_
#endif


/* Deklaration of class : 'Launcher::LNC_RotaryPlate' */
EW_DEFINE_FIELDS( LauncherLNC_RotaryPlate, ComponentsBaseComponent )
  EW_ARRAY   ( Icons,           ViewsImage, [4])
  EW_ARRAY   ( RectEffectArray, EffectsRectEffect, [4])
  EW_PROPERTY( OnIconsRotated,  XSlot )
  EW_PROPERTY( OnSelectedAnimationFinished, XSlot )
  EW_OBJECT  ( RectEffect0,     EffectsRectEffect )
  EW_OBJECT  ( RectEffect1,     EffectsRectEffect )
  EW_OBJECT  ( RectEffect2,     EffectsRectEffect )
  EW_OBJECT  ( RectEffect3,     EffectsRectEffect )
  EW_OBJECT  ( SelectedAnimationTimer, CoreTimer )
  EW_OBJECT  ( BaseImage,       ViewsImage )
  EW_OBJECT  ( Icon0,           ViewsImage )
  EW_OBJECT  ( Icon1,           ViewsImage )
  EW_OBJECT  ( Icon2,           ViewsImage )
  EW_OBJECT  ( Icon3,           ViewsImage )
  EW_OBJECT  ( IconSelectedLarge, ViewsImage )
  EW_OBJECT  ( HighlightImage,  ViewsImage )
  EW_ARRAY   ( IconPositions,   XRect, [5])
  EW_VARIABLE( SelectedIconIdx, XInt32 )
  EW_PROPERTY( HiddenItem,      XEnum )
  EW_PROPERTY( NextItem,        XEnum )
  EW_PROPERTY( PreviousItem,    XEnum )
  EW_PROPERTY( CurrentItem,     XEnum )
  EW_VARIABLE( RotationDirection, XEnum )
EW_END_OF_FIELDS( LauncherLNC_RotaryPlate )

/* Virtual Method Table (VMT) for the class : 'Launcher::LNC_RotaryPlate' */
EW_DEFINE_METHODS( LauncherLNC_RotaryPlate, ComponentsBaseComponent )
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
  EW_METHOD( OnShortDownKeyActivated, void )( LauncherLNC_RotaryPlate _this )
  EW_METHOD( OnShortUpKeyActivated, void )( LauncherLNC_RotaryPlate _this )
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
EW_END_OF_METHODS( LauncherLNC_RotaryPlate )

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.OnShortDownKeyActivated()' */
void LauncherLNC_RotaryPlate_OnShortDownKeyActivated( LauncherLNC_RotaryPlate _this );

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.OnShortUpKeyActivated()' */
void LauncherLNC_RotaryPlate_OnShortUpKeyActivated( LauncherLNC_RotaryPlate _this );

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.StartIconRotation()' */
void LauncherLNC_RotaryPlate_StartIconRotation( LauncherLNC_RotaryPlate _this, XEnum 
  aDirection );

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.OnIconRotationFinished()' */
void LauncherLNC_RotaryPlate_OnIconRotationFinished( LauncherLNC_RotaryPlate _this, 
  XObject sender );

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.SetItems()' */
void LauncherLNC_RotaryPlate_SetItems( LauncherLNC_RotaryPlate _this, XEnum aPreviousItem, 
  XEnum aCurrentItem, XEnum aNextItem );

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.GetSmallIconResourceOfItem()' */
ResourcesBitmap LauncherLNC_RotaryPlate_GetSmallIconResourceOfItem( LauncherLNC_RotaryPlate _this, 
  XEnum aItem );

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.GetLargeIconResourceOfItem()' */
ResourcesBitmap LauncherLNC_RotaryPlate_GetLargeIconResourceOfItem( LauncherLNC_RotaryPlate _this, 
  XEnum aItem );

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.StartSelectedAnimation()' */
void LauncherLNC_RotaryPlate_StartSelectedAnimation( LauncherLNC_RotaryPlate _this );

/* 'C' function for method : 'Launcher::LNC_RotaryPlate.OnSelectedAnimationFinishedSlot()' */
void LauncherLNC_RotaryPlate_OnSelectedAnimationFinishedSlot( LauncherLNC_RotaryPlate _this, 
  XObject sender );

#ifdef __cplusplus
  }
#endif

#endif /* _LauncherLNC_RotaryPlate_H */

/* Embedded Wizard */
