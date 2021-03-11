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
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_OpenOPN01_BootupAnimation.h"
#include "_ResourcesBitmap.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "Open.h"
#include "Resource.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x0000001E, /* ratio 133.33 % */
  0xB8001B00, 0x00092452, 0x00D20037, 0x040003A0, 0xA0002780, 0x00027000, 0x00188006,
  0x10046A32, 0x00000010, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XColor _Const0001 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0002 = {{ 102, 101 }, { 378, 166 }};
static const XStringRes _Const0003 = { _StringsDefault0, 0x0002 };

/* Initializer for the class 'Open::OPN01_BootupAnimation' */
void OpenOPN01_BootupAnimation__Init( OpenOPN01_BootupAnimation _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( OpenOPN01_BootupAnimation );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->BlackBackground, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->BootupAnimation, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->FadeOutTimer, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->HoldTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( OpenOPN01_BootupAnimation );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->BlackBackground, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->BlackBackground, _Const0001 );
  CoreRectView__OnSetBounds( &_this->BootupAnimation, _Const0002 );
  _this->BootupAnimation.Endless = 0;
  ViewsImage_OnSetAnimated( &_this->BootupAnimation, 1 );
  ViewsImage_OnSetFrameNumber( &_this->BootupAnimation, 0 );
  CoreTimer_OnSetPeriod( &_this->FadeOutTimer, 50 );
  CoreTimer_OnSetBegin( &_this->FadeOutTimer, 2600 );
  CoreTimer_OnSetEnabled( &_this->FadeOutTimer, 1 );
  CoreTimer_OnSetPeriod( &_this->HoldTimer, 0 );
  CoreTimer_OnSetBegin( &_this->HoldTimer, 400 );
  CoreGroup__Add( _this, ((CoreView)&_this->BlackBackground ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BootupAnimation ), 0 );
  ViewsImage_OnSetBitmap( &_this->BootupAnimation, EwLoadResource( &ResourceOpeningFadeIn, 
  ResourcesBitmap ));
  _this->FadeOutTimer.OnTrigger = EwNewSlot( _this, OpenOPN01_BootupAnimation_OnFadeOutTriggeredSlot );
  _this->HoldTimer.OnTrigger = EwNewSlot( _this, OpenOPN01_BootupAnimation_OnHoldFinishedSlot );

  /* Call the user defined constructor */
  OpenOPN01_BootupAnimation_Init( _this, aArg );
}

/* Re-Initializer for the class 'Open::OPN01_BootupAnimation' */
void OpenOPN01_BootupAnimation__ReInit( OpenOPN01_BootupAnimation _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->BlackBackground );
  ViewsImage__ReInit( &_this->BootupAnimation );
  CoreTimer__ReInit( &_this->FadeOutTimer );
  CoreTimer__ReInit( &_this->HoldTimer );
}

/* Finalizer method for the class 'Open::OPN01_BootupAnimation' */
void OpenOPN01_BootupAnimation__Done( OpenOPN01_BootupAnimation _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->BlackBackground );
  ViewsImage__Done( &_this->BootupAnimation );
  CoreTimer__Done( &_this->FadeOutTimer );
  CoreTimer__Done( &_this->HoldTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void OpenOPN01_BootupAnimation_Init( OpenOPN01_BootupAnimation _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0003 ));
}

/* 'C' function for method : 'Open::OPN01_BootupAnimation.OnFadeOutTriggeredSlot()' */
void OpenOPN01_BootupAnimation_OnFadeOutTriggeredSlot( OpenOPN01_BootupAnimation _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->FadeOutFrameNumber < 8 )
  {
    ViewsImage_OnSetBitmap( &_this->BootupAnimation, EwLoadResource( &ResourceOpeningFadeOut, 
    ResourcesBitmap ));
    ViewsImage_OnSetAnimated( &_this->BootupAnimation, 0 );
    ViewsImage_OnSetFrameNumber( &_this->BootupAnimation, _this->FadeOutFrameNumber );
    _this->FadeOutFrameNumber++;
  }
  else
  {
    ViewsImage_OnSetVisible( &_this->BootupAnimation, 0 );
    CoreTimer_OnSetEnabled( &_this->FadeOutTimer, 0 );
    CoreTimer_OnSetEnabled( &_this->HoldTimer, 1 );
  }
}

/* 'C' function for method : 'Open::OPN01_BootupAnimation.OnHoldFinishedSlot()' */
void OpenOPN01_BootupAnimation_OnHoldFinishedSlot( OpenOPN01_BootupAnimation _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwSignal( _this->OnBootupAnimationFinished, ((XObject)_this ));
}

/* Variants derived from the class : 'Open::OPN01_BootupAnimation' */
EW_DEFINE_CLASS_VARIANTS( OpenOPN01_BootupAnimation )
EW_END_OF_CLASS_VARIANTS( OpenOPN01_BootupAnimation )

/* Virtual Method Table (VMT) for the class : 'Open::OPN01_BootupAnimation' */
EW_DEFINE_CLASS( OpenOPN01_BootupAnimation, ComponentsBaseComponent, OnBootupAnimationFinished, 
                 OnBootupAnimationFinished, BlackBackground, BlackBackground, FadeOutFrameNumber, 
                 FadeOutFrameNumber, "Open::OPN01_BootupAnimation" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetBuffered,
  CoreGroup_OnGetEnabled,
  CoreGroup_OnSetEnabled,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DismissDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateLayout,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( OpenOPN01_BootupAnimation )

/* Embedded Wizard */
