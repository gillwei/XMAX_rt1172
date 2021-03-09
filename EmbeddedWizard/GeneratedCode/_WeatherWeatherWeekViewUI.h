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

#ifndef _WeatherWeatherWeekViewUI_H
#define _WeatherWeatherWeekViewUI_H

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
#include "_ViewsImage.h"
#include "_ViewsLine.h"
#include "_ViewsText.h"

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

/* Forward declaration of the class Weather::WeatherWeekViewUI */
#ifndef _WeatherWeatherWeekViewUI_
  EW_DECLARE_CLASS( WeatherWeatherWeekViewUI )
#define _WeatherWeatherWeekViewUI_
#endif


/* Deklaration of class : 'Weather::WeatherWeekViewUI' */
EW_DEFINE_FIELDS( WeatherWeatherWeekViewUI, CoreGroup )
  EW_ARRAY   ( DayTextViewArray, ViewsText, [6])
  EW_OBJECT  ( DayOneWeather,   ViewsImage )
  EW_OBJECT  ( DayOneText,      ViewsText )
  EW_OBJECT  ( DayOneChanceOfRain, ViewsText )
  EW_OBJECT  ( DayOneMinTemp,   ViewsText )
  EW_OBJECT  ( DivideLineUpLeft, ViewsLine )
  EW_OBJECT  ( DivideLineUpRight, ViewsLine )
  EW_OBJECT  ( DayTwoWeather,   ViewsImage )
  EW_OBJECT  ( DayOneRainPerIcon, ViewsImage )
  EW_OBJECT  ( DayTwoText,      ViewsText )
  EW_OBJECT  ( DayTwoChanceOfRain, ViewsText )
  EW_OBJECT  ( DayTwoRainPerIcon, ViewsImage )
  EW_OBJECT  ( DayTwoMinTemp,   ViewsText )
  EW_OBJECT  ( DayThreeWeather, ViewsImage )
  EW_OBJECT  ( DayThreeText,    ViewsText )
  EW_OBJECT  ( DayThreeChanceOfRain, ViewsText )
  EW_OBJECT  ( DayThreeRainPerIcon, ViewsImage )
  EW_OBJECT  ( DayThreeMinTemp, ViewsText )
  EW_OBJECT  ( WeatherLineUp,   ViewsImage )
  EW_OBJECT  ( WeatherLineDown, ViewsImage )
  EW_OBJECT  ( DayFourWeather,  ViewsImage )
  EW_OBJECT  ( DayFiveWeather,  ViewsImage )
  EW_OBJECT  ( DaySixWeather,   ViewsImage )
  EW_OBJECT  ( DayFourText,     ViewsText )
  EW_OBJECT  ( DayFiveText,     ViewsText )
  EW_OBJECT  ( DaySixText,      ViewsText )
  EW_OBJECT  ( DivideLineDownLeft, ViewsLine )
  EW_OBJECT  ( DivideLineDownRight, ViewsLine )
  EW_OBJECT  ( DayFourChanceOfRain, ViewsText )
  EW_OBJECT  ( DayFiveChanceOfRain, ViewsText )
  EW_OBJECT  ( DaySixChanceOfRain, ViewsText )
  EW_OBJECT  ( DayFourRainPerIcon, ViewsImage )
  EW_OBJECT  ( DayFiveRainPerIcon, ViewsImage )
  EW_OBJECT  ( DaySixRainPerIcon, ViewsImage )
  EW_OBJECT  ( DayFourMinTemp,  ViewsText )
  EW_OBJECT  ( DayFiveMinTemp,  ViewsText )
  EW_OBJECT  ( DaySixMinTemp,   ViewsText )
  EW_OBJECT  ( DayOneTempUnit,  ViewsImage )
  EW_OBJECT  ( DayTwoTempUnit,  ViewsImage )
  EW_OBJECT  ( DayThreeTempUnit, ViewsImage )
  EW_OBJECT  ( DayFourTempUnit, ViewsImage )
  EW_OBJECT  ( DayFiveTempUnit, ViewsImage )
  EW_OBJECT  ( DaySixTempUnit,  ViewsImage )
  EW_OBJECT  ( DayOneTempSlash, ViewsText )
  EW_OBJECT  ( DayOneMaxTemp,   ViewsText )
  EW_OBJECT  ( DayTwoTempSlash, ViewsText )
  EW_OBJECT  ( DayTwoMaxTemp,   ViewsText )
  EW_OBJECT  ( DayThreeTempSlash, ViewsText )
  EW_OBJECT  ( DayThreeMaxTemp, ViewsText )
  EW_OBJECT  ( DayFourTempSlash, ViewsText )
  EW_OBJECT  ( DayFourMaxTemp,  ViewsText )
  EW_OBJECT  ( DayFiveTempSlash, ViewsText )
  EW_OBJECT  ( DayFiveMaxTemp,  ViewsText )
  EW_OBJECT  ( DaySixTempSlash, ViewsText )
  EW_OBJECT  ( DaySixMaxTemp,   ViewsText )
  EW_ARRAY   ( WeekDayTextArray, XString, [7])
  EW_ARRAY   ( TempSlashBounds, XRect, [6])
  EW_ARRAY   ( MinTempBounds,   XRect, [6])
  EW_ARRAY   ( WeaItemIdxArray, XEnum, [6])
EW_END_OF_FIELDS( WeatherWeatherWeekViewUI )

/* Virtual Method Table (VMT) for the class : 'Weather::WeatherWeekViewUI' */
EW_DEFINE_METHODS( WeatherWeatherWeekViewUI, CoreGroup )
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
EW_END_OF_METHODS( WeatherWeatherWeekViewUI )

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void WeatherWeatherWeekViewUI_Init( WeatherWeatherWeekViewUI _this, XHandle aArg );

/* 'C' function for method : 'Weather::WeatherWeekViewUI.OnWeatherInfoUpdateSlot()' */
void WeatherWeatherWeekViewUI_OnWeatherInfoUpdateSlot( WeatherWeatherWeekViewUI _this, 
  XObject sender );

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void WeatherWeatherWeekViewUI_OnWeekDayUpdateSlot( WeatherWeatherWeekViewUI _this, 
  XObject sender );

#ifdef __cplusplus
  }
#endif

#endif /* _WeatherWeatherWeekViewUI_H */

/* Embedded Wizard */
