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
#include "_InspectionTFT01_ColorGradient.h"
#include "_InspectionTFT09_Flicker.h"
#include "_InspectionTFT10_CrossTalk.h"
#include "_InspectionTFT_Main.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesExternBitmap.h"
#include "_ViewsBorder.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "Color.h"
#include "Enum.h"
#include "Inspection.h"
#include "Resource.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000026, /* ratio 115.79 % */
  0xB8002300, 0x80088452, 0x00E60034, 0x0D800380, 0xF2003080, 0xF0D23000, 0x00318020,
  0x032800D6, 0x8F800E40, 0x04040120, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XColor _Const0001 = { 0x00, 0x00, 0x00, 0xFF };
static const XColor _Const0002 = { 0x00, 0xFF, 0x00, 0xFF };
static const XRect _Const0003 = {{ 6, 6 }, { 474, 264 }};
static const XRect _Const0004 = {{ 11, 11 }, { 469, 73 }};
static const XRect _Const0005 = {{ 11, 73 }, { 469, 135 }};
static const XRect _Const0006 = {{ 11, 135 }, { 469, 197 }};
static const XRect _Const0007 = {{ 11, 197 }, { 469, 259 }};
static const XColor _Const0008 = { 0x7F, 0x7F, 0x7F, 0xFF };
static const XRect _Const0009 = {{ 120, 68 }, { 240, 136 }};
static const XRect _Const000A = {{ 240, 136 }, { 360, 204 }};
static const XStringRes _Const000B = { _StringsDefault0, 0x0002 };

/* Initializer for the class 'Inspection::TFT_Main' */
void InspectionTFT_Main__Init( InspectionTFT_Main _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( InspectionTFT_Main );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->FullScreen, &_this->_XObject, 0 );
  InspectionTFT10_CrossTalk__Init( &_this->CrossTalk, &_this->_XObject, 0 );
  InspectionTFT09_Flicker__Init( &_this->Flicker, &_this->_XObject, 0 );
  InspectionTFT01_ColorGradient__Init( &_this->ColorGradient, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( InspectionTFT_Main );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  _this->Super2.PassUpKey = 1;
  _this->Super2.PassDownKey = 1;
  _this->Super2.PassHomeKey = 1;
  _this->Pattern = EnumInspectionDisplayCOLOR_GRADIENT;
  CoreRectView__OnSetBounds( &_this->FullScreen, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0001 );
  CoreRectView__OnSetBounds( &_this->CrossTalk, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Flicker, _Const0000 );
  CoreRectView__OnSetBounds( &_this->ColorGradient, _Const0000 );
  CoreGroup__Add( _this, ((CoreView)&_this->FullScreen ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CrossTalk ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Flicker ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ColorGradient ), 0 );
}

/* Re-Initializer for the class 'Inspection::TFT_Main' */
void InspectionTFT_Main__ReInit( InspectionTFT_Main _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->FullScreen );
  InspectionTFT10_CrossTalk__ReInit( &_this->CrossTalk );
  InspectionTFT09_Flicker__ReInit( &_this->Flicker );
  InspectionTFT01_ColorGradient__ReInit( &_this->ColorGradient );
}

/* Finalizer method for the class 'Inspection::TFT_Main' */
void InspectionTFT_Main__Done( InspectionTFT_Main _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->FullScreen );
  InspectionTFT10_CrossTalk__Done( &_this->CrossTalk );
  InspectionTFT09_Flicker__Done( &_this->Flicker );
  InspectionTFT01_ColorGradient__Done( &_this->ColorGradient );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* 'C' function for method : 'Inspection::TFT_Main.OnShortDownKeyActivated()' */
void InspectionTFT_Main_OnShortDownKeyActivated( InspectionTFT_Main _this )
{
  XInt32 NextPatternIdx = _this->Pattern + 1;

  if ( NextPatternIdx >= 9 )
  {
    NextPatternIdx = 1;
  }

  InspectionTFT_Main_OnSetPattern( _this, (XEnum)NextPatternIdx );
}

/* 'C' function for method : 'Inspection::TFT_Main.OnShortUpKeyActivated()' */
void InspectionTFT_Main_OnShortUpKeyActivated( InspectionTFT_Main _this )
{
  XInt32 PreviousIdx = _this->Pattern - 1;

  if ( PreviousIdx <= 0 )
  {
    PreviousIdx = 8;
  }

  InspectionTFT_Main_OnSetPattern( _this, (XEnum)PreviousIdx );
}

/* 'C' function for method : 'Inspection::TFT_Main.OnSetPattern()' */
void InspectionTFT_Main_OnSetPattern( InspectionTFT_Main _this, XEnum value )
{
  if ( _this->Pattern != value )
  {
    _this->Pattern = value;
    InspectionTFT_Main_DisplayPattern( _this, _this->Pattern );
  }
}

/* 'C' function for method : 'Inspection::TFT_Main.DisplayPattern()' */
void InspectionTFT_Main_DisplayPattern( InspectionTFT_Main _this, XEnum aPattern )
{
  CoreGroup__OnSetVisible( &_this->ColorGradient, 0 );
  ViewsRectangle_OnSetVisible( &_this->FullScreen, 0 );
  CoreGroup__OnSetVisible( &_this->CrossTalk, 0 );
  CoreGroup__OnSetVisible( &_this->Flicker, 0 );

  switch ( aPattern )
  {
    case EnumInspectionDisplayCOLOR_GRADIENT :
      CoreGroup__OnSetVisible( &_this->ColorGradient, 1 );
    break;

    case EnumInspectionDisplayFULL_BLACK :
    {
      ViewsRectangle_OnSetColor( &_this->FullScreen, ColorBLACK );
      ViewsRectangle_OnSetVisible( &_this->FullScreen, 1 );
    }
    break;

    case EnumInspectionDisplayFULL_WHITE :
    {
      ViewsRectangle_OnSetColor( &_this->FullScreen, ColorWHITE );
      ViewsRectangle_OnSetVisible( &_this->FullScreen, 1 );
    }
    break;

    case EnumInspectionDisplayFULL_RED :
    {
      ViewsRectangle_OnSetColor( &_this->FullScreen, ColorRED );
      ViewsRectangle_OnSetVisible( &_this->FullScreen, 1 );
    }
    break;

    case EnumInspectionDisplayFULL_GREEN :
    {
      ViewsRectangle_OnSetColor( &_this->FullScreen, ColorGREEN );
      ViewsRectangle_OnSetVisible( &_this->FullScreen, 1 );
    }
    break;

    case EnumInspectionDisplayFULL_BLUE :
    {
      ViewsRectangle_OnSetColor( &_this->FullScreen, ColorBLUE );
      ViewsRectangle_OnSetVisible( &_this->FullScreen, 1 );
    }
    break;

    case EnumInspectionDisplayFLICKER :
      CoreGroup__OnSetVisible( &_this->Flicker, 1 );
    break;

    case EnumInspectionDisplayCROSSTALK :
      CoreGroup__OnSetVisible( &_this->CrossTalk, 1 );
    break;

    default : 
      ;
  }
}

/* Variants derived from the class : 'Inspection::TFT_Main' */
EW_DEFINE_CLASS_VARIANTS( InspectionTFT_Main )
EW_END_OF_CLASS_VARIANTS( InspectionTFT_Main )

/* Virtual Method Table (VMT) for the class : 'Inspection::TFT_Main' */
EW_DEFINE_CLASS( InspectionTFT_Main, ComponentsBaseMainBG, FullScreen, FullScreen, 
                 FullScreen, FullScreen, Pattern, Pattern, "Inspection::TFT_Main" )
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
  InspectionTFT_Main_OnShortDownKeyActivated,
  InspectionTFT_Main_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( InspectionTFT_Main )

/* Initializer for the class 'Inspection::TFT01_ColorGradient' */
void InspectionTFT01_ColorGradient__Init( InspectionTFT01_ColorGradient _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( InspectionTFT01_ColorGradient );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->GeenBG, &_this->_XObject, 0 );
  ViewsBorder__Init( &_this->BlackFrame, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->StripRed, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->StripGreen, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->SripBlue, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->StripWhite, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( InspectionTFT01_ColorGradient );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->GeenBG, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->GeenBG, _Const0002 );
  CoreRectView__OnSetBounds( &_this->BlackFrame, _Const0003 );
  ViewsBorder_OnSetWidth( &_this->BlackFrame, 5 );
  ViewsBorder_OnSetColor( &_this->BlackFrame, _Const0001 );
  CoreRectView__OnSetBounds( &_this->StripRed, _Const0004 );
  ViewsRectangle_OnSetColorBL( &_this->StripRed, ColorRED );
  ViewsRectangle_OnSetColorBR( &_this->StripRed, ColorBLACK );
  ViewsRectangle_OnSetColorTR( &_this->StripRed, ColorBLACK );
  ViewsRectangle_OnSetColorTL( &_this->StripRed, ColorRED );
  CoreRectView__OnSetBounds( &_this->StripGreen, _Const0005 );
  ViewsRectangle_OnSetColorBL( &_this->StripGreen, ColorGREEN );
  ViewsRectangle_OnSetColorBR( &_this->StripGreen, ColorBLACK );
  ViewsRectangle_OnSetColorTR( &_this->StripGreen, ColorBLACK );
  ViewsRectangle_OnSetColorTL( &_this->StripGreen, ColorGREEN );
  CoreRectView__OnSetBounds( &_this->SripBlue, _Const0006 );
  ViewsRectangle_OnSetColorBL( &_this->SripBlue, ColorBLUE );
  ViewsRectangle_OnSetColorBR( &_this->SripBlue, ColorBLACK );
  ViewsRectangle_OnSetColorTR( &_this->SripBlue, ColorBLACK );
  ViewsRectangle_OnSetColorTL( &_this->SripBlue, ColorBLUE );
  CoreRectView__OnSetBounds( &_this->StripWhite, _Const0007 );
  ViewsRectangle_OnSetColorBR( &_this->StripWhite, _Const0001 );
  ViewsRectangle_OnSetColorTR( &_this->StripWhite, _Const0001 );
  CoreGroup__Add( _this, ((CoreView)&_this->GeenBG ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BlackFrame ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->StripRed ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->StripGreen ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SripBlue ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->StripWhite ), 0 );
}

/* Re-Initializer for the class 'Inspection::TFT01_ColorGradient' */
void InspectionTFT01_ColorGradient__ReInit( InspectionTFT01_ColorGradient _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->GeenBG );
  ViewsBorder__ReInit( &_this->BlackFrame );
  ViewsRectangle__ReInit( &_this->StripRed );
  ViewsRectangle__ReInit( &_this->StripGreen );
  ViewsRectangle__ReInit( &_this->SripBlue );
  ViewsRectangle__ReInit( &_this->StripWhite );
}

/* Finalizer method for the class 'Inspection::TFT01_ColorGradient' */
void InspectionTFT01_ColorGradient__Done( InspectionTFT01_ColorGradient _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->GeenBG );
  ViewsBorder__Done( &_this->BlackFrame );
  ViewsRectangle__Done( &_this->StripRed );
  ViewsRectangle__Done( &_this->StripGreen );
  ViewsRectangle__Done( &_this->SripBlue );
  ViewsRectangle__Done( &_this->StripWhite );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* Variants derived from the class : 'Inspection::TFT01_ColorGradient' */
EW_DEFINE_CLASS_VARIANTS( InspectionTFT01_ColorGradient )
EW_END_OF_CLASS_VARIANTS( InspectionTFT01_ColorGradient )

/* Virtual Method Table (VMT) for the class : 'Inspection::TFT01_ColorGradient' */
EW_DEFINE_CLASS( InspectionTFT01_ColorGradient, CoreGroup, GeenBG, GeenBG, GeenBG, 
                 GeenBG, _None, _None, "Inspection::TFT01_ColorGradient" )
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
EW_END_OF_CLASS( InspectionTFT01_ColorGradient )

/* Initializer for the class 'Inspection::TFT10_CrossTalk' */
void InspectionTFT10_CrossTalk__Init( InspectionTFT10_CrossTalk _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( InspectionTFT10_CrossTalk );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->GrayBG, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->RectanbleBlack, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->RectangleWhite, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( InspectionTFT10_CrossTalk );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->GrayBG, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->GrayBG, _Const0008 );
  CoreRectView__OnSetBounds( &_this->RectanbleBlack, _Const0009 );
  ViewsRectangle_OnSetColor( &_this->RectanbleBlack, ColorBLACK );
  CoreRectView__OnSetBounds( &_this->RectangleWhite, _Const000A );
  ViewsRectangle_OnSetColor( &_this->RectangleWhite, ColorWHITE );
  CoreGroup__Add( _this, ((CoreView)&_this->GrayBG ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RectanbleBlack ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->RectangleWhite ), 0 );
}

/* Re-Initializer for the class 'Inspection::TFT10_CrossTalk' */
void InspectionTFT10_CrossTalk__ReInit( InspectionTFT10_CrossTalk _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->GrayBG );
  ViewsRectangle__ReInit( &_this->RectanbleBlack );
  ViewsRectangle__ReInit( &_this->RectangleWhite );
}

/* Finalizer method for the class 'Inspection::TFT10_CrossTalk' */
void InspectionTFT10_CrossTalk__Done( InspectionTFT10_CrossTalk _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->GrayBG );
  ViewsRectangle__Done( &_this->RectanbleBlack );
  ViewsRectangle__Done( &_this->RectangleWhite );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* Variants derived from the class : 'Inspection::TFT10_CrossTalk' */
EW_DEFINE_CLASS_VARIANTS( InspectionTFT10_CrossTalk )
EW_END_OF_CLASS_VARIANTS( InspectionTFT10_CrossTalk )

/* Virtual Method Table (VMT) for the class : 'Inspection::TFT10_CrossTalk' */
EW_DEFINE_CLASS( InspectionTFT10_CrossTalk, CoreGroup, GrayBG, GrayBG, GrayBG, GrayBG, 
                 _None, _None, "Inspection::TFT10_CrossTalk" )
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
EW_END_OF_CLASS( InspectionTFT10_CrossTalk )

/* Initializer for the class 'Inspection::TFT09_Flicker' */
void InspectionTFT09_Flicker__Init( InspectionTFT09_Flicker _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( InspectionTFT09_Flicker );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->FlickerImage, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( InspectionTFT09_Flicker );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->FlickerImage, _Const0000 );
  ViewsImage_OnSetVisible( &_this->FlickerImage, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->FlickerImage ), 0 );
  ViewsImage_OnSetBitmap( &_this->FlickerImage, ((ResourcesBitmap)EwGetAutoObject( 
  &ResourceExternFlickerPattern, ResourcesExternBitmap )));

  /* Call the user defined constructor */
  InspectionTFT09_Flicker_Init( _this, aArg );
}

/* Re-Initializer for the class 'Inspection::TFT09_Flicker' */
void InspectionTFT09_Flicker__ReInit( InspectionTFT09_Flicker _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->FlickerImage );
}

/* Finalizer method for the class 'Inspection::TFT09_Flicker' */
void InspectionTFT09_Flicker__Done( InspectionTFT09_Flicker _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->FlickerImage );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void InspectionTFT09_Flicker_Init( InspectionTFT09_Flicker _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  ResourcesExternBitmap_OnSetName( EwGetAutoObject( &ResourceExternFlickerPattern, 
  ResourcesExternBitmap ), EwLoadString( &_Const000B ));
}

/* 'C' function for method : 'Inspection::TFT09_Flicker.OnSetVisible()' */
void InspectionTFT09_Flicker_OnSetVisible( InspectionTFT09_Flicker _this, XBool 
  value )
{
  if ( _this->Super2.Visible != value )
  {
    _this->Super2.Visible = value;
    ViewsImage_OnSetVisible( &_this->FlickerImage, value );
  }
}

/* Variants derived from the class : 'Inspection::TFT09_Flicker' */
EW_DEFINE_CLASS_VARIANTS( InspectionTFT09_Flicker )
EW_END_OF_CLASS_VARIANTS( InspectionTFT09_Flicker )

/* Virtual Method Table (VMT) for the class : 'Inspection::TFT09_Flicker' */
EW_DEFINE_CLASS( InspectionTFT09_Flicker, ComponentsBaseComponent, FlickerImage, 
                 FlickerImage, FlickerImage, FlickerImage, _None, _None, "Inspection::TFT09_Flicker" )
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
  InspectionTFT09_Flicker_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
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
EW_END_OF_CLASS( InspectionTFT09_Flicker )

/* Embedded Wizard */
