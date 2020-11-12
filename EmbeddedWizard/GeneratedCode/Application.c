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
* Profile  : Profile
* Platform : NXP.iMX_RT_VGLite.RGBA8888
*
*******************************************************************************/

#include "ewlocale.h"
#include "_ApplicationApplication.h"
#include "_ApplicationBlackWhite.h"
#include "_CoreGroup.h"
#include "_CoreRoot.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_EffectsSlideTransition.h"
#include "_EffectsTransition.h"
#include "_ViewsRectangle.h"
#include "Application.h"
#include "Effects.h"

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0001 = {{ 0, 0 }, { 160, 272 }};
static const XColor _Const0002 = { 0xFF, 0x00, 0x00, 0xFF };
static const XRect _Const0003 = {{ 160, 0 }, { 320, 272 }};
static const XColor _Const0004 = { 0x00, 0xFF, 0x00, 0xFF };
static const XRect _Const0005 = {{ 320, 0 }, { 480, 272 }};
static const XColor _Const0006 = { 0x00, 0x00, 0xFF, 0xFF };
static const XRect _Const0007 = {{ 0, 0 }, { 480, 136 }};
static const XColor _Const0008 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0009 = {{ 0, 136 }, { 480, 272 }};
static const XColor _Const000A = { 0xFF, 0xFF, 0xFF, 0xFF };

/* Initializer for the class 'Application::Application' */
void ApplicationApplication__Init( ApplicationApplication _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRoot__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( ApplicationApplication );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->RectangleLeft, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->RectangleMiddle, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->RectangleRight, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->Timer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ApplicationApplication );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->RectangleLeft, _Const0001 );
  ViewsRectangle_OnSetColor( &_this->RectangleLeft, _Const0002 );
  CoreRectView__OnSetBounds( &_this->RectangleMiddle, _Const0003 );
  ViewsRectangle_OnSetColor( &_this->RectangleMiddle, _Const0004 );
  CoreRectView__OnSetBounds( &_this->RectangleRight, _Const0005 );
  ViewsRectangle_OnSetColor( &_this->RectangleRight, _Const0006 );
  CoreTimer_OnSetPeriod( &_this->Timer, 2000 );
  CoreTimer_OnSetEnabled( &_this->Timer, 1 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->RectangleLeft ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->RectangleMiddle ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->RectangleRight ), 0 );
  _this->Timer.OnTrigger = EwNewSlot( _this, ApplicationApplication_Slot );
}

/* Re-Initializer for the class 'Application::Application' */
void ApplicationApplication__ReInit( ApplicationApplication _this )
{
  /* At first re-initialize the super class ... */
  CoreRoot__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->RectangleLeft );
  ViewsRectangle__ReInit( &_this->RectangleMiddle );
  ViewsRectangle__ReInit( &_this->RectangleRight );
  CoreTimer__ReInit( &_this->Timer );
}

/* Finalizer method for the class 'Application::Application' */
void ApplicationApplication__Done( ApplicationApplication _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreRoot );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->RectangleLeft );
  ViewsRectangle__Done( &_this->RectangleMiddle );
  ViewsRectangle__Done( &_this->RectangleRight );
  CoreTimer__Done( &_this->Timer );

  /* Don't forget to deinitialize the super class ... */
  CoreRoot__Done( &_this->_Super );
}

/* 'C' function for method : 'Application::Application.Slot()' */
void ApplicationApplication_Slot( ApplicationApplication _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( CoreGroup__IsCurrentDialog( CoreView__GetRoot( _this )))
  {
    CoreGroup_PresentDialog((CoreGroup)CoreView__GetRoot( _this ), ((CoreGroup)EwNewObject( 
    ApplicationBlackWhite, 0 )), ((EffectsTransition)EwGetAutoObject( &EffectsSlideLeftCentered, 
    EffectsSlideTransition )), 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
  else
  {
    CoreGroup aGroup = CoreGroup_GetDialogAtIndex((CoreGroup)_this, 0 );

    if ( aGroup != 0 )
    {
      CoreGroup_DismissDialog((CoreGroup)CoreView__GetRoot( _this ), aGroup, 0, 
      0, 0, EwNullSlot, EwNullSlot, 0 );
    }
  }
}

/* Variants derived from the class : 'Application::Application' */
EW_DEFINE_CLASS_VARIANTS( ApplicationApplication )
EW_END_OF_CLASS_VARIANTS( ApplicationApplication )

/* Virtual Method Table (VMT) for the class : 'Application::Application' */
EW_DEFINE_CLASS( ApplicationApplication, CoreRoot, RectangleLeft, RectangleLeft, 
                 RectangleLeft, RectangleLeft, _None, _None, "Application::Application" )
  CoreRectView_initLayoutContext,
  CoreRoot_GetRoot,
  CoreRoot_Draw,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreRoot_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreRoot_OnSetFocus,
  CoreRoot_OnSetBuffered,
  CoreRoot_OnSetOpacity,
  CoreRoot_IsCurrentDialog,
  CoreRoot_IsActiveDialog,
  CoreRoot_DispatchEvent,
  CoreRoot_BroadcastEvent,
  CoreRoot_InvalidateArea,
EW_END_OF_CLASS( ApplicationApplication )

/* Initializer for the class 'Application::BlackWhite' */
void ApplicationBlackWhite__Init( ApplicationBlackWhite _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( ApplicationBlackWhite );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->RectangleMiddle, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->RectangleMiddle1, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ApplicationBlackWhite );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->RectangleMiddle, _Const0007 );
  ViewsRectangle_OnSetColor( &_this->RectangleMiddle, _Const0008 );
  CoreRectView__OnSetBounds( &_this->RectangleMiddle1, _Const0009 );
  ViewsRectangle_OnSetColor( &_this->RectangleMiddle1, _Const000A );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->RectangleMiddle ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->RectangleMiddle1 ), 0 );
}

/* Re-Initializer for the class 'Application::BlackWhite' */
void ApplicationBlackWhite__ReInit( ApplicationBlackWhite _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->RectangleMiddle );
  ViewsRectangle__ReInit( &_this->RectangleMiddle1 );
}

/* Finalizer method for the class 'Application::BlackWhite' */
void ApplicationBlackWhite__Done( ApplicationBlackWhite _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->RectangleMiddle );
  ViewsRectangle__Done( &_this->RectangleMiddle1 );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* Variants derived from the class : 'Application::BlackWhite' */
EW_DEFINE_CLASS_VARIANTS( ApplicationBlackWhite )
EW_END_OF_CLASS_VARIANTS( ApplicationBlackWhite )

/* Virtual Method Table (VMT) for the class : 'Application::BlackWhite' */
EW_DEFINE_CLASS( ApplicationBlackWhite, CoreGroup, RectangleMiddle, RectangleMiddle, 
                 RectangleMiddle, RectangleMiddle, _None, _None, "Application::BlackWhite" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetBuffered,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( ApplicationBlackWhite )

/* Embedded Wizard */
