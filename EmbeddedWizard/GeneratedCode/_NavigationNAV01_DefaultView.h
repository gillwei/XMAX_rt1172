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

#ifndef _NavigationNAV01_DefaultView_H
#define _NavigationNAV01_DefaultView_H

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

#include "_ComponentsDDModeMask.h"
#include "_CoreKeyPressHandler.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_EffectsRectEffect.h"
#include "_HomeBaseHome.h"
#include "_NavigationNaviAlert.h"
#include "_NavigationNaviCurrentRoad.h"
#include "_NavigationNaviETA.h"
#include "_PopPOP16_NaviLoadingUI.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "_ViewsWallpaper.h"

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

/* Forward declaration of the class Navigation::NAV01_DefaultView */
#ifndef _NavigationNAV01_DefaultView_
  EW_DECLARE_CLASS( NavigationNAV01_DefaultView )
#define _NavigationNAV01_DefaultView_
#endif


/* Deklaration of class : 'Navigation::NAV01_DefaultView' */
EW_DEFINE_FIELDS( NavigationNAV01_DefaultView, HomeBaseHome )
  EW_OBJECT  ( Background,      ViewsRectangle )
  EW_OBJECT  ( MapImage,        ViewsImage )
  EW_OBJECT  ( ArrivalBg,       ViewsRectangle )
  EW_OBJECT  ( ETAComponent,    NavigationNaviETA )
  EW_OBJECT  ( RoadNameBg,      ViewsRectangle )
  EW_OBJECT  ( CurrentRoadWithGuide, NavigationNaviCurrentRoad )
  EW_OBJECT  ( CurrentRoadWithOutGuide, NavigationNaviCurrentRoad )
  EW_OBJECT  ( Shadow,          ViewsImage )
  EW_OBJECT  ( ZoomInButton,    ViewsImage )
  EW_OBJECT  ( ZoomOutButton,   ViewsImage )
  EW_OBJECT  ( SpeedLimitIcon,  ViewsImage )
  EW_OBJECT  ( SpeedLimitText,  ViewsText )
  EW_OBJECT  ( NaviEventObject, NavigationNaviAlert )
  EW_OBJECT  ( StatusBarShadowImage, ViewsWallpaper )
  EW_OBJECT  ( Mask,            ViewsRectangle )
  EW_OBJECT  ( MapUpdateEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( CurRdUpdateEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( ETAUpdateEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( DayNightModeUpdateEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( HighlightTimer,  CoreTimer )
  EW_OBJECT  ( SpeedLimitUpdateEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( NaviIncidentUpdateEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( CurrentRoadShiftEffect, EffectsRectEffect )
  EW_OBJECT  ( NaviEventEnLargeEffect, EffectsRectEffect )
  EW_OBJECT  ( NaviEventDismissEffect, EffectsRectEffect )
  EW_OBJECT  ( NavigatingStatusUpdateEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( SpeedLimitFlickeringTimer, CoreTimer )
  EW_OBJECT  ( VehicleDataReceivedEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( NaviDialogEventHandler, CoreSystemEventHandler )
  EW_OBJECT  ( NaviDisconnectEventHandler, CoreSystemEventHandler )
  EW_VARIABLE( MapFrameIdx,     XInt32 )
  EW_VARIABLE( ZoomButtonStatus, XInt32 )
  EW_VARIABLE( IsEventDisplaying, XBool )
EW_END_OF_FIELDS( NavigationNAV01_DefaultView )

/* Virtual Method Table (VMT) for the class : 'Navigation::NAV01_DefaultView' */
EW_DEFINE_METHODS( NavigationNAV01_DefaultView, HomeBaseHome )
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
  EW_METHOD( OnShortDownKeyActivated, void )( NavigationNAV01_DefaultView _this )
  EW_METHOD( OnShortUpKeyActivated, void )( NavigationNAV01_DefaultView _this )
  EW_METHOD( OnShortEnterKeyActivated, void )( HomeBaseHome _this )
  EW_METHOD( OnShortHomeKeyActivated, void )( HomeBaseHome _this )
  EW_METHOD( OnLongDownKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLongUpKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnLongEnterKeyActivated, void )( NavigationNAV01_DefaultView _this )
  EW_METHOD( OnLongHomeKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnShortMagicKeyActivated, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnSetDDModeEnabled, void )( ComponentsBaseMainBG _this, XBool value )
  EW_METHOD( OnDownKeyReleased, void )( ComponentsBaseComponent _this )
  EW_METHOD( OnUpKeyReleased,   void )( ComponentsBaseComponent _this )
  EW_METHOD( ReturnToHome,      void )( NavigationNAV01_DefaultView _this )
EW_END_OF_METHODS( NavigationNAV01_DefaultView )

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void NavigationNAV01_DefaultView_Init( NavigationNAV01_DefaultView _this, XHandle 
  aArg );

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnShortDownKeyActivated()' */
void NavigationNAV01_DefaultView_OnShortDownKeyActivated( NavigationNAV01_DefaultView _this );

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnShortUpKeyActivated()' */
void NavigationNAV01_DefaultView_OnShortUpKeyActivated( NavigationNAV01_DefaultView _this );

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnLongEnterKeyActivated()' */
void NavigationNAV01_DefaultView_OnLongEnterKeyActivated( NavigationNAV01_DefaultView _this );

/* 'C' function for method : 'Navigation::NAV01_DefaultView.ReturnToHome()' */
void NavigationNAV01_DefaultView_ReturnToHome( NavigationNAV01_DefaultView _this );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnMapUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnCurRdUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnETAUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnDayNightModeUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender );

/* 'C' function for method : 'Navigation::NAV01_DefaultView.StartHighlight()' */
void NavigationNAV01_DefaultView_StartHighlight( NavigationNAV01_DefaultView _this );

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnHighlightEndSlot()' */
void NavigationNAV01_DefaultView_OnHighlightEndSlot( NavigationNAV01_DefaultView _this, 
  XObject sender );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnSpeedLimitUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnNaviIncidentUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender );

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnCurrentRoadShiftEffectFinishSlot()' */
void NavigationNAV01_DefaultView_OnCurrentRoadShiftEffectFinishSlot( NavigationNAV01_DefaultView _this, 
  XObject sender );

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnNaviEventEnlargeFinishSlot()' */
void NavigationNAV01_DefaultView_OnNaviEventEnlargeFinishSlot( NavigationNAV01_DefaultView _this, 
  XObject sender );

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnNaviEventDismissFinishSlot()' */
void NavigationNAV01_DefaultView_OnNaviEventDismissFinishSlot( NavigationNAV01_DefaultView _this, 
  XObject sender );

/* 'C' function for method : 'Navigation::NAV01_DefaultView.DismissAlert()' */
void NavigationNAV01_DefaultView_DismissAlert( NavigationNAV01_DefaultView _this, 
  XObject sender );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnNavigatingStatusUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender );

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnSpeedLimitFlickeringSlot()' */
void NavigationNAV01_DefaultView_OnSpeedLimitFlickeringSlot( NavigationNAV01_DefaultView _this, 
  XObject sender );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnVehicleSpeedUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender );

/* 'C' function for method : 'Navigation::NAV01_DefaultView.SetItemBounds()' */
void NavigationNAV01_DefaultView_SetItemBounds( NavigationNAV01_DefaultView _this );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnNaviDialogEventUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender );

/* 'C' function for method : 'Navigation::NAV01_DefaultView.OnNaviDialogDismissSlot()' */
void NavigationNAV01_DefaultView_OnNaviDialogDismissSlot( NavigationNAV01_DefaultView _this, 
  XObject sender );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void NavigationNAV01_DefaultView_OnNaviDisconnectUpdateSlot( NavigationNAV01_DefaultView _this, 
  XObject sender );

#ifdef __cplusplus
  }
#endif

#endif /* _NavigationNAV01_DefaultView_H */

/* Embedded Wizard */
