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

#ifndef _ComponentsBaseText_H
#define _ComponentsBaseText_H

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

#include "_ViewsText.h"

/* Forward declaration of the class Components::BaseText */
#ifndef _ComponentsBaseText_
  EW_DECLARE_CLASS( ComponentsBaseText )
#define _ComponentsBaseText_
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

/* Forward declaration of the class Core::View */
#ifndef _CoreView_
  EW_DECLARE_CLASS( CoreView )
#define _CoreView_
#endif

/* Forward declaration of the class Resources::Font */
#ifndef _ResourcesFont_
  EW_DECLARE_CLASS( ResourcesFont )
#define _ResourcesFont_
#endif


/* Deklaration of class : 'Components::BaseText' */
EW_DEFINE_FIELDS( ComponentsBaseText, ViewsText )
EW_END_OF_FIELDS( ComponentsBaseText )

/* Virtual Method Table (VMT) for the class : 'Components::BaseText' */
EW_DEFINE_METHODS( ComponentsBaseText, ViewsText )
  EW_METHOD( initLayoutContext, void )( CoreRectView _this, XRect aBounds, CoreOutline 
    aOutline )
  EW_METHOD( GetRoot,           CoreRoot )( CoreView _this )
  EW_METHOD( Draw,              void )( ViewsText _this, GraphicsCanvas aCanvas, 
    XRect aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend )
  EW_METHOD( HandleEvent,       XObject )( CoreView _this, CoreEvent aEvent )
  EW_METHOD( CursorHitTest,     CoreCursorHit )( CoreView _this, XRect aArea, XInt32 
    aFinger, XInt32 aStrikeCount, CoreView aDedicatedView, XSet aRetargetReason )
  EW_METHOD( ArrangeView,       XPoint )( CoreRectView _this, XRect aBounds, XEnum 
    aFormation )
  EW_METHOD( MoveView,          void )( CoreRectView _this, XPoint aOffset, XBool 
    aFastMove )
  EW_METHOD( GetExtent,         XRect )( CoreRectView _this )
  EW_METHOD( ChangeViewState,   void )( CoreView _this, XSet aSetState, XSet aClearState )
  EW_METHOD( OnSetBounds,       void )( ViewsText _this, XRect value )
EW_END_OF_METHODS( ComponentsBaseText )

/* 'C' function for method : 'Components::BaseText.ReInit()' */
void ComponentsBaseText_ReInit( ComponentsBaseText _this );

/* 'C' function for method : 'Components::BaseText.Init()' */
void ComponentsBaseText_Init( ComponentsBaseText _this, XHandle aArg );

/* 'C' function for method : 'Components::BaseText.UpdateFontSlot()' */
void ComponentsBaseText_UpdateFontSlot( ComponentsBaseText _this, XObject sender );

#ifdef __cplusplus
  }
#endif

#endif /* _ComponentsBaseText_H */

/* Embedded Wizard */
