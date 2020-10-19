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
* Version  : 9.30
* Profile  : iMX_RT
* Platform : NXP.iMX_RT_VGLite.RGBA8888
*
*******************************************************************************/

#include "ewlocale.h"
#include "_ApplicationApplication.h"
#include "_CoreView.h"
#include "_ResourcesFont.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "Application.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000040, /* ratio 93.75 % */
  0xB8000D00, 0x800A4452, 0x00880022, 0x60608858, 0x0C002391, 0x64E84422, 0x0E038021,
  0x02600085, 0x8B41CAA0, 0x01221C09, 0x1B000650, 0x00DE0093, 0x65B16108, 0x00000040,
  0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 270 }};
static const XRect _Const0001 = {{ 0, 0 }, { 250, 270 }};
static const XColor _Const0002 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const0003 = {{ 50, 30 }, { 190, 80 }};
static const XStringRes _Const0004 = { _StringsDefault0, 0x0002 };
static const XColor _Const0005 = { 0xFF, 0x00, 0x00, 0xFF };
static const XRect _Const0006 = {{ 40, 110 }, { 200, 160 }};
static const XStringRes _Const0007 = { _StringsDefault0, 0x0008 };
static const XColor _Const0008 = { 0x00, 0xFF, 0x00, 0xFF };
static const XRect _Const0009 = {{ 50, 180 }, { 190, 230 }};
static const XStringRes _Const000A = { _StringsDefault0, 0x0010 };
static const XColor _Const000B = { 0x00, 0x00, 0xFF, 0xFF };
static const XRect _Const000C = {{ 250, 0 }, { 480, 90 }};
static const XRect _Const000D = {{ 250, 90 }, { 480, 180 }};
static const XRect _Const000E = {{ 300, 110 }, { 440, 160 }};
static const XStringRes _Const000F = { _StringsDefault0, 0x0017 };
static const XRect _Const0010 = {{ 250, 180 }, { 480, 270 }};

/* Initializer for the class 'Application::Application' */
void ApplicationApplication__Init( ApplicationApplication _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRoot__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( ApplicationApplication );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Text1, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Text2, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->Rectangle1, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->Rectangle2, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Text3, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->Rectangle3, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ApplicationApplication );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0001 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0002 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0003 );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const0004 ));
  ViewsText_OnSetColor( &_this->Text, _Const0005 );
  CoreRectView__OnSetBounds( &_this->Text1, _Const0006 );
  ViewsText_OnSetString( &_this->Text1, EwLoadString( &_Const0007 ));
  ViewsText_OnSetColor( &_this->Text1, _Const0008 );
  CoreRectView__OnSetBounds( &_this->Text2, _Const0009 );
  ViewsText_OnSetString( &_this->Text2, EwLoadString( &_Const000A ));
  ViewsText_OnSetColor( &_this->Text2, _Const000B );
  CoreRectView__OnSetBounds( &_this->Rectangle1, _Const000C );
  ViewsRectangle_OnSetColor( &_this->Rectangle1, _Const0005 );
  CoreRectView__OnSetBounds( &_this->Rectangle2, _Const000D );
  ViewsRectangle_OnSetColor( &_this->Rectangle2, _Const0008 );
  CoreRectView__OnSetBounds( &_this->Text3, _Const000E );
  ViewsText_OnSetColorTL( &_this->Text3, _Const0002 );
  ViewsText_OnSetString( &_this->Text3, EwLoadString( &_Const000F ));
  CoreRectView__OnSetBounds( &_this->Rectangle3, _Const0010 );
  ViewsRectangle_OnSetColor( &_this->Rectangle3, _Const000B );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Text ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Text1 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Text2 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Rectangle1 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Rectangle2 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Text3 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Rectangle3 ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &ApplicationFont, ResourcesFont ));
  ViewsText_OnSetFont( &_this->Text1, EwLoadResource( &ApplicationFont, ResourcesFont ));
  ViewsText_OnSetFont( &_this->Text2, EwLoadResource( &ApplicationFont, ResourcesFont ));
  ViewsText_OnSetFont( &_this->Text3, EwLoadResource( &ApplicationFont, ResourcesFont ));
}

/* Re-Initializer for the class 'Application::Application' */
void ApplicationApplication__ReInit( ApplicationApplication _this )
{
  /* At first re-initialize the super class ... */
  CoreRoot__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsText__ReInit( &_this->Text );
  ViewsText__ReInit( &_this->Text1 );
  ViewsText__ReInit( &_this->Text2 );
  ViewsRectangle__ReInit( &_this->Rectangle1 );
  ViewsRectangle__ReInit( &_this->Rectangle2 );
  ViewsText__ReInit( &_this->Text3 );
  ViewsRectangle__ReInit( &_this->Rectangle3 );
}

/* Finalizer method for the class 'Application::Application' */
void ApplicationApplication__Done( ApplicationApplication _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreRoot );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsText__Done( &_this->Text );
  ViewsText__Done( &_this->Text1 );
  ViewsText__Done( &_this->Text2 );
  ViewsRectangle__Done( &_this->Rectangle1 );
  ViewsRectangle__Done( &_this->Rectangle2 );
  ViewsText__Done( &_this->Text3 );
  ViewsRectangle__Done( &_this->Rectangle3 );

  /* Don't forget to deinitialize the super class ... */
  CoreRoot__Done( &_this->_Super );
}

/* Variants derived from the class : 'Application::Application' */
EW_DEFINE_CLASS_VARIANTS( ApplicationApplication )
EW_END_OF_CLASS_VARIANTS( ApplicationApplication )

/* Virtual Method Table (VMT) for the class : 'Application::Application' */
EW_DEFINE_CLASS( ApplicationApplication, CoreRoot, Rectangle, Rectangle, Rectangle, 
                 Rectangle, _None, _None, "Application::Application" )
  CoreRectView_initLayoutContext,
  CoreRoot_Draw,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreRoot_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreRoot_OnSetFocus,
  CoreRoot_DispatchEvent,
  CoreRoot_BroadcastEvent,
  CoreRoot_InvalidateArea,
EW_END_OF_CLASS( ApplicationApplication )

/* Include a file containing the font resource : 'Application::Font' */
#include "_ApplicationFont.h"

/* Table with links to derived variants of the font resource : 'Application::Font' */
EW_RES_WITHOUT_VARIANTS( ApplicationFont )

/* Embedded Wizard */
