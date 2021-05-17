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

#include "ewlocale.h"
#include "_EffectSlideTransitionNoFade.h"
#include "_EffectsFader.h"
#include "_EffectsInt32Effect.h"
#include "_EffectsPointEffect.h"
#include "_EffectsPositionFader.h"
#include "Core.h"
#include "Effect.h"
#include "Effects.h"

/* User defined auto object: 'Effect::SlideOutTransition' */
EW_DEFINE_AUTOOBJECT( EffectSlideOutTransition, EffectSlideTransitionNoFade )

/* Initializer for the auto object 'Effect::SlideOutTransition' */
void EffectSlideOutTransition__Init( EffectSlideTransitionNoFade _this )
{
  _this->Super1.Buffered = 1;
  _this->Super1.Exponent = 4.430000f;
  _this->Super1.Timing = EffectsTimingExp_Out;
  _this->Super1.Duration = 200;
  _this->Super1.Direction = CoreDirectionRight;
}

/* Table with links to derived variants of the auto object : 'Effect::SlideOutTransition' */
EW_DEFINE_AUTOOBJECT_VARIANTS( EffectSlideOutTransition )
EW_END_OF_AUTOOBJECT_VARIANTS( EffectSlideOutTransition )

/* User defined auto object: 'Effect::SlideInTransition' */
EW_DEFINE_AUTOOBJECT( EffectSlideInTransition, EffectSlideTransitionNoFade )

/* Initializer for the auto object 'Effect::SlideInTransition' */
void EffectSlideInTransition__Init( EffectSlideTransitionNoFade _this )
{
  _this->Super1.Buffered = 1;
  _this->Super1.Exponent = 4.430000f;
  _this->Super1.Timing = EffectsTimingExp_Out;
  _this->Super1.Duration = 200;
  _this->Super1.Direction = CoreDirectionLeft;
}

/* Table with links to derived variants of the auto object : 'Effect::SlideInTransition' */
EW_DEFINE_AUTOOBJECT_VARIANTS( EffectSlideInTransition )
EW_END_OF_AUTOOBJECT_VARIANTS( EffectSlideInTransition )

/* Initializer for the class 'Effect::SlideTransitionNoFade' */
void EffectSlideTransitionNoFade__Init( EffectSlideTransitionNoFade _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  EffectsSlideTransition__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( EffectSlideTransitionNoFade );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( EffectSlideTransitionNoFade );
}

/* Re-Initializer for the class 'Effect::SlideTransitionNoFade' */
void EffectSlideTransitionNoFade__ReInit( EffectSlideTransitionNoFade _this )
{
  /* At first re-initialize the super class ... */
  EffectsSlideTransition__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Effect::SlideTransitionNoFade' */
void EffectSlideTransitionNoFade__Done( EffectSlideTransitionNoFade _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( EffectsSlideTransition );

  /* Don't forget to deinitialize the super class ... */
  EffectsSlideTransition__Done( &_this->_.Super );
}

/* The method CreatePresentFader() creates an object of one of the classes descending 
   from Effects::Fader and configures it with parameters according to the desired 
   fade-in (present) transition. Finally the prepared fader object is returned to 
   the caller. Typically, the created fader is used to show (to present) a GUI component 
   when the user navigates to it. The method has to be overridden and implemented 
   in derived classes. The actual implementation does nothing and returns 'null'. */
EffectsFader EffectSlideTransitionNoFade_CreatePresentFader( EffectSlideTransitionNoFade _this )
{
  EffectsPositionFader fader = EwNewObject( EffectsPositionFader, 0 );

  fader->Super1.Visible = 1;
  fader->Super1.AssignFocus = 0;
  fader->Super1.RestackTopmost = 1;
  fader->Super1.UseCurrentState = 1;
  fader->Buffered = _this->Super1.Buffered;
  fader->Super1.OnInitialize = EwNewSlot( _this, EffectsSlideTransition_onInitializeIn );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&fader->OpacityEffect, 0 );
  fader->OpacityEffect.Value1 = 255;
  fader->OpacityEffect.Value2 = 255;
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&fader->PositionEffect, _this->Super1.Duration );
  EffectsEffect_OnSetTiming((EffectsEffect)&fader->PositionEffect, _this->Super1.Timing );
  EffectsEffect_OnSetTimingCustom1((EffectsEffect)&fader->PositionEffect, 0.000000f );
  EffectsEffect_OnSetTimingCustom2((EffectsEffect)&fader->PositionEffect, 0.000000f );
  EffectsEffect_OnSetExponent((EffectsEffect)&fader->PositionEffect, _this->Super1.Exponent );
  EffectsEffect_OnSetAmplitude((EffectsEffect)&fader->PositionEffect, 0.500000f );
  EffectsEffect_OnSetOscillations((EffectsEffect)&fader->PositionEffect, 3 );
  EffectsEffect_OnSetBounces((EffectsEffect)&fader->PositionEffect, 3 );
  EffectsEffect_OnSetElasticity((EffectsEffect)&fader->PositionEffect, 0.500000f );
  return ((EffectsFader)fader );
}

/* The method CreateDismissFader() creates an object of one of the classes descending 
   from Effects::Fader and configures it with parameters according to the desired 
   fade-out (dismiss) transition. Finally the prepared fader object is returned 
   to the caller. Typically, the created fader is used to hide (to dismiss) a GUI 
   component when the user leaves it while he/she navigates in the GUI system. The 
   method has to be overridden and implemented in derived classes. The actual implementation 
   does nothing and returns 'null'. */
EffectsFader EffectSlideTransitionNoFade_CreateDismissFader( EffectSlideTransitionNoFade _this )
{
  EffectsPositionFader fader = EwNewObject( EffectsPositionFader, 0 );

  fader->Super1.Visible = 0;
  fader->Super1.RemoveIfHidden = 1;
  fader->Super1.UseCurrentState = 1;
  fader->Buffered = _this->Super1.Buffered;
  fader->Super1.OnInitialize = EwNewSlot( _this, EffectsSlideTransition_onInitializeOut );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&fader->OpacityEffect, 0 );
  fader->OpacityEffect.Value1 = 255;
  fader->OpacityEffect.Value2 = 255;
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&fader->PositionEffect, _this->Super1.Duration );
  EffectsEffect_OnSetTiming((EffectsEffect)&fader->PositionEffect, _this->Super1.Timing );
  EffectsEffect_OnSetTimingCustom1((EffectsEffect)&fader->PositionEffect, 0.000000f );
  EffectsEffect_OnSetTimingCustom2((EffectsEffect)&fader->PositionEffect, 0.000000f );
  EffectsEffect_OnSetExponent((EffectsEffect)&fader->PositionEffect, _this->Super1.Exponent );
  EffectsEffect_OnSetAmplitude((EffectsEffect)&fader->PositionEffect, 0.500000f );
  EffectsEffect_OnSetOscillations((EffectsEffect)&fader->PositionEffect, 3 );
  EffectsEffect_OnSetBounces((EffectsEffect)&fader->PositionEffect, 3 );
  EffectsEffect_OnSetElasticity((EffectsEffect)&fader->PositionEffect, 0.500000f );
  return ((EffectsFader)fader );
}

/* Variants derived from the class : 'Effect::SlideTransitionNoFade' */
EW_DEFINE_CLASS_VARIANTS( EffectSlideTransitionNoFade )
EW_END_OF_CLASS_VARIANTS( EffectSlideTransitionNoFade )

/* Virtual Method Table (VMT) for the class : 'Effect::SlideTransitionNoFade' */
EW_DEFINE_CLASS( EffectSlideTransitionNoFade, EffectsSlideTransition, _.VMT, _.VMT, 
                 _.VMT, _.VMT, _.VMT, _.VMT, "Effect::SlideTransitionNoFade" )
  EffectSlideTransitionNoFade_CreatePresentFader,
  EffectSlideTransitionNoFade_CreateDismissFader,
  EffectsSlideTransition_CreateRestoreFader,
  EffectsSlideTransition_CreateOverlayFader,
EW_END_OF_CLASS( EffectSlideTransitionNoFade )

/* User defined auto object: 'Effect::NoSlideOut' */
EW_DEFINE_AUTOOBJECT( EffectNoSlideOut, EffectSlideTransitionNoFade )

/* Initializer for the auto object 'Effect::NoSlideOut' */
void EffectNoSlideOut__Init( EffectSlideTransitionNoFade _this )
{
  _this->Super1.Buffered = 1;
  _this->Super1.Exponent = 4.430000f;
  _this->Super1.Timing = EffectsTimingExp_Out;
  _this->Super1.Duration = 0;
  _this->Super1.Direction = CoreDirectionRight;
}

/* Table with links to derived variants of the auto object : 'Effect::NoSlideOut' */
EW_DEFINE_AUTOOBJECT_VARIANTS( EffectNoSlideOut )
EW_END_OF_AUTOOBJECT_VARIANTS( EffectNoSlideOut )

/* Embedded Wizard */
