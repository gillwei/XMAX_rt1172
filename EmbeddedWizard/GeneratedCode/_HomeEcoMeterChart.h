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

#ifndef _HomeEcoMeterChart_H
#define _HomeEcoMeterChart_H

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

/* Forward declaration of the class Home::EcoMeterChart */
#ifndef _HomeEcoMeterChart_
  EW_DECLARE_CLASS( HomeEcoMeterChart )
#define _HomeEcoMeterChart_
#endif

/* Forward declaration of the class Home::EcoMeterComponent */
#ifndef _HomeEcoMeterComponent_
  EW_DECLARE_CLASS( HomeEcoMeterComponent )
#define _HomeEcoMeterComponent_
#endif

/* Forward declaration of the class Home::Record */
#ifndef _HomeRecord_
  EW_DECLARE_CLASS( HomeRecord )
#define _HomeRecord_
#endif

/* Forward declaration of the class Home::RecordList */
#ifndef _HomeRecordList_
  EW_DECLARE_CLASS( HomeRecordList )
#define _HomeRecordList_
#endif

/* Forward declaration of the class Resources::Bitmap */
#ifndef _ResourcesBitmap_
  EW_DECLARE_CLASS( ResourcesBitmap )
#define _ResourcesBitmap_
#endif


/* Deklaration of class : 'Home::EcoMeterChart' */
EW_DEFINE_FIELDS( HomeEcoMeterChart, CoreGroup )
  EW_PROPERTY( DotFrame,        ResourcesBitmap )
  EW_PROPERTY( Records,         HomeRecordList )
  EW_PROPERTY( Record,          HomeRecord )
  EW_VARIABLE( EcoUnit,         HomeEcoMeterComponent )
  EW_PROPERTY( StartAnimation,  XSlot )
  EW_PROPERTY( EndAnimation,    XSlot )
  EW_PROPERTY( BarSize,         XInt32 )
EW_END_OF_FIELDS( HomeEcoMeterChart )

/* Virtual Method Table (VMT) for the class : 'Home::EcoMeterChart' */
EW_DEFINE_METHODS( HomeEcoMeterChart, CoreGroup )
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
EW_END_OF_METHODS( HomeEcoMeterChart )

/* 'C' function for method : 'Home::EcoMeterChart.OnSetDotFrame()' */
void HomeEcoMeterChart_OnSetDotFrame( HomeEcoMeterChart _this, ResourcesBitmap value );

/* 'C' function for method : 'Home::EcoMeterChart.OnSetBarSize()' */
void HomeEcoMeterChart_OnSetBarSize( HomeEcoMeterChart _this, XInt32 value );

/* 'C' function for method : 'Home::EcoMeterChart.OnSetRecords()' */
void HomeEcoMeterChart_OnSetRecords( HomeEcoMeterChart _this, HomeRecordList value );

/* 'C' function for method : 'Home::EcoMeterChart.OnAnimate()' */
void HomeEcoMeterChart_OnAnimate( HomeEcoMeterChart _this, XObject sender );

/* 'C' function for method : 'Home::EcoMeterChart.RemoveEcoUnit()' */
void HomeEcoMeterChart_RemoveEcoUnit( HomeEcoMeterChart _this, XInt32 aIndex );

/* 'C' function for method : 'Home::EcoMeterChart.HideEcoUnit()' */
void HomeEcoMeterChart_HideEcoUnit( HomeEcoMeterChart _this, XInt32 aIndex );

#ifdef __cplusplus
  }
#endif

#endif /* _HomeEcoMeterChart_H */

/* Embedded Wizard */
