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

#include "ewlocale.h"
#include "_EffectsSlideTransition.h"
#include "Core.h"
#include "Effect.h"

/* User defined auto object: 'Effect::RightSlideTransition' */
EW_DEFINE_AUTOOBJECT( EffectRightSlideTransition, EffectsSlideTransition )

/* Initializer for the auto object 'Effect::RightSlideTransition' */
void EffectRightSlideTransition__Init( EffectsSlideTransition _this )
{
  _this->Direction = CoreDirectionRight;
}

/* Table with links to derived variants of the auto object : 'Effect::RightSlideTransition' */
EW_DEFINE_AUTOOBJECT_VARIANTS( EffectRightSlideTransition )
EW_END_OF_AUTOOBJECT_VARIANTS( EffectRightSlideTransition )

/* User defined auto object: 'Effect::LeftSlideTransition' */
EW_DEFINE_AUTOOBJECT( EffectLeftSlideTransition, EffectsSlideTransition )

/* Initializer for the auto object 'Effect::LeftSlideTransition' */
void EffectLeftSlideTransition__Init( EffectsSlideTransition _this )
{
  _this->Direction = CoreDirectionLeft;
}

/* Table with links to derived variants of the auto object : 'Effect::LeftSlideTransition' */
EW_DEFINE_AUTOOBJECT_VARIANTS( EffectLeftSlideTransition )
EW_END_OF_AUTOOBJECT_VARIANTS( EffectLeftSlideTransition )

/* Embedded Wizard */
