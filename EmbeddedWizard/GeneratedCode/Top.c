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
#include "_CoreView.h"
#include "_MenuPushButton.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_TopTOP01_Disclaimer.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "Fonts.h"
#include "Resource.h"
#include "Strings.h"
#include "Top.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x0000001E, /* ratio 133.33 % */
  0xB8001B00, 0x00092452, 0x00D20037, 0x040003A0, 0x9E002A00, 0x00028000, 0x00188006,
  0x10046A32, 0x00000010, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XColor _Const0001 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0002 = {{ 10, 51 }, { 470, 206 }};
static const XRect _Const0003 = {{ 0, 0 }, { 480, 43 }};
static const XColor _Const0004 = { 0xF6, 0x95, 0x00, 0xFF };
static const XRect _Const0005 = {{ 155, 5 }, { 191, 41 }};
static const XRect _Const0006 = {{ 196, 4 }, { 333, 42 }};
static const XRect _Const0007 = {{ 165, 219 }, { 315, 259 }};
static const XStringRes _Const0008 = { _StringsDefault0, 0x0002 };

/* Initializer for the class 'Top::TOP01_Disclaimer' */
void TopTOP01_Disclaimer__Init( TopTOP01_Disclaimer _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( TopTOP01_Disclaimer );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->BlackBackground, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DisclaimerText, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->TopBar, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->IconWarning, &_this->_XObject, 0 );
  ViewsText__Init( &_this->WarningText, &_this->_XObject, 0 );
  MenuPushButton__Init( &_this->AcceptButton, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( TopTOP01_Disclaimer );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->BlackBackground, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->BlackBackground, _Const0001 );
  CoreRectView__OnSetBounds( &_this->DisclaimerText, _Const0002 );
  ViewsText_OnSetRowDistance( &_this->DisclaimerText, 31 );
  ViewsText_OnSetWrapText( &_this->DisclaimerText, 1 );
  ViewsText_OnSetString( &_this->DisclaimerText, EwGetVariantOfString( &StringsTOP01_disclaimer ));
  CoreRectView__OnSetBounds( &_this->TopBar, _Const0003 );
  ViewsRectangle_OnSetColor( &_this->TopBar, _Const0004 );
  CoreRectView__OnSetBounds( &_this->IconWarning, _Const0005 );
  ViewsImage_OnSetAlignment( &_this->IconWarning, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter | ViewsImageAlignmentScaleToFit );
  ViewsImage_OnSetVisible( &_this->IconWarning, 1 );
  CoreRectView__OnSetBounds( &_this->WarningText, _Const0006 );
  ViewsText_OnSetAutoSize( &_this->WarningText, 1 );
  ViewsText_OnSetAlignment( &_this->WarningText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->WarningText, EwGetVariantOfString( &StringsTOP01_warning ));
  ViewsText_OnSetColor( &_this->WarningText, _Const0001 );
  ViewsText_OnSetVisible( &_this->WarningText, 1 );
  CoreRectView__OnSetBounds( &_this->AcceptButton, _Const0007 );
  MenuPushButton_OnSetTitle( &_this->AcceptButton, EwGetVariantOfString( &StringsTOP01_accept ));
  CoreGroup__Add( _this, ((CoreView)&_this->BlackBackground ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DisclaimerText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TopBar ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->IconWarning ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->WarningText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->AcceptButton ), 0 );
  ViewsText_OnSetFont( &_this->DisclaimerText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->IconWarning, EwLoadResource( &ResourceIconWarning, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->WarningText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  _this->AcceptButton.OnActivate = EwNewSlot( _this, TopTOP01_Disclaimer_OnAcceptedSlot );

  /* Call the user defined constructor */
  TopTOP01_Disclaimer_Init( _this, aArg );
}

/* Re-Initializer for the class 'Top::TOP01_Disclaimer' */
void TopTOP01_Disclaimer__ReInit( TopTOP01_Disclaimer _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->BlackBackground );
  ViewsText__ReInit( &_this->DisclaimerText );
  ViewsRectangle__ReInit( &_this->TopBar );
  ViewsImage__ReInit( &_this->IconWarning );
  ViewsText__ReInit( &_this->WarningText );
  MenuPushButton__ReInit( &_this->AcceptButton );
}

/* Finalizer method for the class 'Top::TOP01_Disclaimer' */
void TopTOP01_Disclaimer__Done( TopTOP01_Disclaimer _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->BlackBackground );
  ViewsText__Done( &_this->DisclaimerText );
  ViewsRectangle__Done( &_this->TopBar );
  ViewsImage__Done( &_this->IconWarning );
  ViewsText__Done( &_this->WarningText );
  MenuPushButton__Done( &_this->AcceptButton );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void TopTOP01_Disclaimer_Init( TopTOP01_Disclaimer _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0008 ));
}

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void TopTOP01_Disclaimer_UpdateLayout( TopTOP01_Disclaimer _this, XPoint aSize )
{
  XInt32 WarningIconGapPixel;
  XInt32 TotalWidth;
  XInt32 Margin;
  XInt32 Width;
  XRect NewBounds;

  CoreGroup_UpdateLayout((CoreGroup)_this, aSize );
  WarningIconGapPixel = 3;
  TotalWidth = ( EwGetRectW( _this->IconWarning.Super1.Bounds ) + WarningIconGapPixel ) 
  + EwGetRectW( ViewsText_GetContentArea( &_this->WarningText ));
  Margin = ( EwGetRectW( _this->Super3.Bounds ) - TotalWidth ) / 2;
  Width = EwGetRectW( _this->IconWarning.Super1.Bounds );
  NewBounds = _this->IconWarning.Super1.Bounds;
  NewBounds.Point1.X = Margin;
  NewBounds.Point2.X = ( NewBounds.Point1.X + Width );
  CoreRectView__OnSetBounds( &_this->IconWarning, NewBounds );
  Width = EwGetRectW( _this->WarningText.Super1.Bounds );
  NewBounds = _this->WarningText.Super1.Bounds;
  NewBounds.Point1.X = ( _this->IconWarning.Super1.Bounds.Point2.X + WarningIconGapPixel );
  NewBounds.Point2.X = ( NewBounds.Point1.X + Width );
  CoreRectView__OnSetBounds( &_this->WarningText, NewBounds );
}

/* 'C' function for method : 'Top::TOP01_Disclaimer.OnAcceptedSlot()' */
void TopTOP01_Disclaimer_OnAcceptedSlot( TopTOP01_Disclaimer _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwSignal( _this->OnAcceptButtonClicked, ((XObject)_this ));
}

/* Variants derived from the class : 'Top::TOP01_Disclaimer' */
EW_DEFINE_CLASS_VARIANTS( TopTOP01_Disclaimer )
EW_END_OF_CLASS_VARIANTS( TopTOP01_Disclaimer )

/* Virtual Method Table (VMT) for the class : 'Top::TOP01_Disclaimer' */
EW_DEFINE_CLASS( TopTOP01_Disclaimer, ComponentsBaseComponent, OnAcceptButtonClicked, 
                 OnAcceptButtonClicked, BlackBackground, BlackBackground, _None, 
                 _None, "Top::TOP01_Disclaimer" )
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
  TopTOP01_Disclaimer_UpdateLayout,
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
EW_END_OF_CLASS( TopTOP01_Disclaimer )

/* Embedded Wizard */
