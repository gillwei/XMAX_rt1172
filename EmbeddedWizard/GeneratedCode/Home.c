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
#include "_CoreGroup.h"
#include "_CoreRoot.h"
#include "_CoreView.h"
#include "_HomeHOM11_tachometer.h"
#include "_LauncherLNC_Main.h"
#include "_ResourcesFont.h"
#include "_ViewsText.h"
#include "Fonts.h"
#include "Home.h"
#include "Strings.h"
#include "Views.h"

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0001 = {{ 72, 113 }, { 403, 156 }};

/* Initializer for the class 'Home::HOM11_tachometer' */
void HomeHOM11_tachometer__Init( HomeHOM11_tachometer _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( HomeHOM11_tachometer );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Title, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( HomeHOM11_tachometer );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Title, _Const0001 );
  ViewsText_OnSetAlignment( &_this->Title, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Title, EwLoadString( &StringsINF01_tachometer ));
  CoreGroup__Add( _this, ((CoreView)&_this->Title ), 0 );
  ViewsText_OnSetFont( &_this->Title, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Home::HOM11_tachometer' */
void HomeHOM11_tachometer__ReInit( HomeHOM11_tachometer _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Title );
}

/* Finalizer method for the class 'Home::HOM11_tachometer' */
void HomeHOM11_tachometer__Done( HomeHOM11_tachometer _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Title );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* 'C' function for method : 'Home::HOM11_tachometer.OnShortEnterKeyActivated()' */
void HomeHOM11_tachometer_OnShortEnterKeyActivated( HomeHOM11_tachometer _this )
{
  CoreGroup_PresentDialog((CoreGroup)CoreView__GetRoot( _this ), ((CoreGroup)EwNewObject( 
  LauncherLNC_Main, 0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* Variants derived from the class : 'Home::HOM11_tachometer' */
EW_DEFINE_CLASS_VARIANTS( HomeHOM11_tachometer )
EW_END_OF_CLASS_VARIANTS( HomeHOM11_tachometer )

/* Virtual Method Table (VMT) for the class : 'Home::HOM11_tachometer' */
EW_DEFINE_CLASS( HomeHOM11_tachometer, ComponentsBaseMainBG, Title, Title, Title, 
                 Title, _None, _None, "Home::HOM11_tachometer" )
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
  HomeHOM11_tachometer_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
EW_END_OF_CLASS( HomeHOM11_tachometer )

/* Embedded Wizard */
