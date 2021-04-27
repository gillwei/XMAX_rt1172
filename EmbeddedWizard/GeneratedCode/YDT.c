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
#include "_MenuPushButton.h"
#include "_ResourcesFont.h"
#include "_ViewsText.h"
#include "_YDTYDT01_Main.h"
#include "Fonts.h"
#include "Strings.h"
#include "YDT.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x0000001E, /* ratio 133.33 % */
  0xB8001B00, 0x00092452, 0x00D20037, 0x040003A0, 0x88002C80, 0x0002A000, 0x00188006,
  0x10046A32, 0x00000010, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 165, 219 }, { 315, 259 }};
static const XRect _Const0001 = {{ 10, 46 }, { 470, 201 }};
static const XStringRes _Const0002 = { _StringsDefault0, 0x0002 };

/* Initializer for the class 'YDT::YDT01_Main' */
void YDTYDT01_Main__Init( YDTYDT01_Main _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( YDTYDT01_Main );

  /* ... then construct all embedded objects */
  MenuPushButton__Init( &_this->PushButton, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->DisableTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( YDTYDT01_Main );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->PushButton, _Const0000 );
  MenuPushButton_OnSetTitle( &_this->PushButton, EwGetVariantOfString( &StringsGEN_OK ));
  CoreRectView__OnSetBounds( &_this->Text, _Const0001 );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &StringsYDT01_MESSAGE ));
  CoreTimer_OnSetPeriod( &_this->DisableTimer, 0 );
  CoreTimer_OnSetBegin( &_this->DisableTimer, 1000 );
  CoreGroup__Add( _this, ((CoreView)&_this->PushButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  _this->PushButton.OnActivate = EwNewSlot( _this, YDTYDT01_Main_OnOkSelectedSlot );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->DisableTimer.OnTrigger = EwNewSlot( _this, YDTYDT01_Main_OnDisableSlot );

  /* Call the user defined constructor */
  YDTYDT01_Main_Init( _this, aArg );
}

/* Re-Initializer for the class 'YDT::YDT01_Main' */
void YDTYDT01_Main__ReInit( YDTYDT01_Main _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  MenuPushButton__ReInit( &_this->PushButton );
  ViewsText__ReInit( &_this->Text );
  CoreTimer__ReInit( &_this->DisableTimer );
}

/* Finalizer method for the class 'YDT::YDT01_Main' */
void YDTYDT01_Main__Done( YDTYDT01_Main _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  MenuPushButton__Done( &_this->PushButton );
  ViewsText__Done( &_this->Text );
  CoreTimer__Done( &_this->DisableTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void YDTYDT01_Main_Init( YDTYDT01_Main _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0002 ));
  _this->PushButton.Super1.PassEnterKey = 1;
  CoreTimer_OnSetEnabled( &_this->DisableTimer, 1 );
}

/* 'C' function for method : 'YDT::YDT01_Main.OnShortEnterKeyActivated()' */
void YDTYDT01_Main_OnShortEnterKeyActivated( YDTYDT01_Main _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* 'C' function for method : 'YDT::YDT01_Main.OnShortHomeKeyActivated()' */
void YDTYDT01_Main_OnShortHomeKeyActivated( YDTYDT01_Main _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* 'C' function for method : 'YDT::YDT01_Main.OnLongHomeKeyActivated()' */
void YDTYDT01_Main_OnLongHomeKeyActivated( YDTYDT01_Main _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* 'C' function for method : 'YDT::YDT01_Main.OnOkSelectedSlot()' */
void YDTYDT01_Main_OnOkSelectedSlot( YDTYDT01_Main _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ComponentsBaseMainBG_DismissThisDialog((ComponentsBaseMainBG)_this );
}

/* 'C' function for method : 'YDT::YDT01_Main.OnDisableSlot()' */
void YDTYDT01_Main_OnDisableSlot( YDTYDT01_Main _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->DisableTimer, 0 );
  _this->PushButton.Super1.PassEnterKey = 0;
}

/* Variants derived from the class : 'YDT::YDT01_Main' */
EW_DEFINE_CLASS_VARIANTS( YDTYDT01_Main )
EW_END_OF_CLASS_VARIANTS( YDTYDT01_Main )

/* Virtual Method Table (VMT) for the class : 'YDT::YDT01_Main' */
EW_DEFINE_CLASS( YDTYDT01_Main, ComponentsBaseMainBG, PushButton, PushButton, PushButton, 
                 PushButton, _None, _None, "YDT::YDT01_Main" )
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
  CoreGroup_OnSetVisible,
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
  YDTYDT01_Main_OnShortEnterKeyActivated,
  YDTYDT01_Main_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  YDTYDT01_Main_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( YDTYDT01_Main )

/* Embedded Wizard */
