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

#ifndef _EffectSlideTransitionNoFade_H
#define _EffectSlideTransitionNoFade_H

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

#include "_EffectsSlideTransition.h"

/* Forward declaration of the class Effect::SlideTransitionNoFade */
#ifndef _EffectSlideTransitionNoFade_
  EW_DECLARE_CLASS( EffectSlideTransitionNoFade )
#define _EffectSlideTransitionNoFade_
#endif

/* Forward declaration of the class Effects::Fader */
#ifndef _EffectsFader_
  EW_DECLARE_CLASS( EffectsFader )
#define _EffectsFader_
#endif


/* Deklaration of class : 'Effect::SlideTransitionNoFade' */
EW_DEFINE_FIELDS( EffectSlideTransitionNoFade, EffectsSlideTransition )
EW_END_OF_FIELDS( EffectSlideTransitionNoFade )

/* Virtual Method Table (VMT) for the class : 'Effect::SlideTransitionNoFade' */
EW_DEFINE_METHODS( EffectSlideTransitionNoFade, EffectsSlideTransition )
  EW_METHOD( CreatePresentFader, EffectsFader )( EffectSlideTransitionNoFade _this )
  EW_METHOD( CreateDismissFader, EffectsFader )( EffectSlideTransitionNoFade _this )
  EW_METHOD( CreateRestoreFader, EffectsFader )( EffectsSlideTransition _this )
  EW_METHOD( CreateOverlayFader, EffectsFader )( EffectsSlideTransition _this )
EW_END_OF_METHODS( EffectSlideTransitionNoFade )

/* The method CreatePresentFader() creates an object of one of the classes descending 
   from Effects::Fader and configures it with parameters according to the desired 
   fade-in (present) transition. Finally the prepared fader object is returned to 
   the caller. Typically, the created fader is used to show (to present) a GUI component 
   when the user navigates to it. The method has to be overridden and implemented 
   in derived classes. The actual implementation does nothing and returns 'null'. */
EffectsFader EffectSlideTransitionNoFade_CreatePresentFader( EffectSlideTransitionNoFade _this );

/* The method CreateDismissFader() creates an object of one of the classes descending 
   from Effects::Fader and configures it with parameters according to the desired 
   fade-out (dismiss) transition. Finally the prepared fader object is returned 
   to the caller. Typically, the created fader is used to hide (to dismiss) a GUI 
   component when the user leaves it while he/she navigates in the GUI system. The 
   method has to be overridden and implemented in derived classes. The actual implementation 
   does nothing and returns 'null'. */
EffectsFader EffectSlideTransitionNoFade_CreateDismissFader( EffectSlideTransitionNoFade _this );

#ifdef __cplusplus
  }
#endif

#endif /* _EffectSlideTransitionNoFade_H */

/* Embedded Wizard */
