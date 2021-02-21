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
#include "_HomeHOM11_TachoVisualizer.h"
#include "_HomeHOM12_EcoVisualizer.h"
#include "_HomeHOM13_SpeedVisualizer.h"
#include "_LauncherLNC_Main.h"
#include "_ResourcesFont.h"
#include "_ViewsText.h"
#include "Fonts.h"
#include "Home.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000052, /* ratio 78.05 % */
  0xB8001B00, 0x00092452, 0x00D20037, 0x040003A0, 0x9E002400, 0x20026800, 0x18004546,
  0x88341205, 0x87432150, 0xB4522510, 0x00230328, 0x260F058D, 0x61F0D85C, 0x671789C4,
  0x10199C98, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 72, 113 }, { 403, 156 }};
static const XStringRes _Const0001 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0002 = { _StringsDefault0, 0x000F };
static const XStringRes _Const0003 = { _StringsDefault0, 0x001C };

/* Initializer for the class 'Home::HOM11_TachoVisualizer' */
void HomeHOM11_TachoVisualizer__Init( HomeHOM11_TachoVisualizer _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( HomeHOM11_TachoVisualizer );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Title, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( HomeHOM11_TachoVisualizer );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Title, _Const0000 );
  ViewsText_OnSetAlignment( &_this->Title, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Title, EwLoadString( &StringsINF01_TACHO_VISUALIZER ));
  CoreGroup__Add( _this, ((CoreView)&_this->Title ), 0 );
  ViewsText_OnSetFont( &_this->Title, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));

  /* Call the user defined constructor */
  HomeHOM11_TachoVisualizer_Init( _this, aArg );
}

/* Re-Initializer for the class 'Home::HOM11_TachoVisualizer' */
void HomeHOM11_TachoVisualizer__ReInit( HomeHOM11_TachoVisualizer _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Title );
}

/* Finalizer method for the class 'Home::HOM11_TachoVisualizer' */
void HomeHOM11_TachoVisualizer__Done( HomeHOM11_TachoVisualizer _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Title );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void HomeHOM11_TachoVisualizer_Init( HomeHOM11_TachoVisualizer _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0001 ));
}

/* 'C' function for method : 'Home::HOM11_TachoVisualizer.OnShortEnterKeyActivated()' */
void HomeHOM11_TachoVisualizer_OnShortEnterKeyActivated( HomeHOM11_TachoVisualizer _this )
{
  CoreGroup_PresentDialog((CoreGroup)CoreView__GetRoot( _this ), ((CoreGroup)EwNewObject( 
  LauncherLNC_Main, 0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Home::HOM11_TachoVisualizer.OnShortHomeKeyActivated()' */
void HomeHOM11_TachoVisualizer_OnShortHomeKeyActivated( HomeHOM11_TachoVisualizer _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Variants derived from the class : 'Home::HOM11_TachoVisualizer' */
EW_DEFINE_CLASS_VARIANTS( HomeHOM11_TachoVisualizer )
EW_END_OF_CLASS_VARIANTS( HomeHOM11_TachoVisualizer )

/* Virtual Method Table (VMT) for the class : 'Home::HOM11_TachoVisualizer' */
EW_DEFINE_CLASS( HomeHOM11_TachoVisualizer, ComponentsBaseMainBG, Title, Title, 
                 Title, Title, _None, _None, "Home::HOM11_TachoVisualizer" )
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
  HomeHOM11_TachoVisualizer_OnShortEnterKeyActivated,
  HomeHOM11_TachoVisualizer_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( HomeHOM11_TachoVisualizer )

/* Initializer for the class 'Home::HOM12_EcoVisualizer' */
void HomeHOM12_EcoVisualizer__Init( HomeHOM12_EcoVisualizer _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( HomeHOM12_EcoVisualizer );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Title, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( HomeHOM12_EcoVisualizer );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Title, _Const0000 );
  ViewsText_OnSetAlignment( &_this->Title, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Title, EwLoadString( &StringsINF01_ECHO_VISUALIZER ));
  CoreGroup__Add( _this, ((CoreView)&_this->Title ), 0 );
  ViewsText_OnSetFont( &_this->Title, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));

  /* Call the user defined constructor */
  HomeHOM12_EcoVisualizer_Init( _this, aArg );
}

/* Re-Initializer for the class 'Home::HOM12_EcoVisualizer' */
void HomeHOM12_EcoVisualizer__ReInit( HomeHOM12_EcoVisualizer _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Title );
}

/* Finalizer method for the class 'Home::HOM12_EcoVisualizer' */
void HomeHOM12_EcoVisualizer__Done( HomeHOM12_EcoVisualizer _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Title );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void HomeHOM12_EcoVisualizer_Init( HomeHOM12_EcoVisualizer _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0002 ));
}

/* 'C' function for method : 'Home::HOM12_EcoVisualizer.OnShortEnterKeyActivated()' */
void HomeHOM12_EcoVisualizer_OnShortEnterKeyActivated( HomeHOM12_EcoVisualizer _this )
{
  CoreGroup_PresentDialog((CoreGroup)CoreView__GetRoot( _this ), ((CoreGroup)EwNewObject( 
  LauncherLNC_Main, 0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Home::HOM12_EcoVisualizer.OnShortHomeKeyActivated()' */
void HomeHOM12_EcoVisualizer_OnShortHomeKeyActivated( HomeHOM12_EcoVisualizer _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Variants derived from the class : 'Home::HOM12_EcoVisualizer' */
EW_DEFINE_CLASS_VARIANTS( HomeHOM12_EcoVisualizer )
EW_END_OF_CLASS_VARIANTS( HomeHOM12_EcoVisualizer )

/* Virtual Method Table (VMT) for the class : 'Home::HOM12_EcoVisualizer' */
EW_DEFINE_CLASS( HomeHOM12_EcoVisualizer, ComponentsBaseMainBG, Title, Title, Title, 
                 Title, _None, _None, "Home::HOM12_EcoVisualizer" )
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
  HomeHOM12_EcoVisualizer_OnShortEnterKeyActivated,
  HomeHOM12_EcoVisualizer_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( HomeHOM12_EcoVisualizer )

/* Initializer for the class 'Home::HOM13_SpeedVisualizer' */
void HomeHOM13_SpeedVisualizer__Init( HomeHOM13_SpeedVisualizer _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( HomeHOM13_SpeedVisualizer );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Title, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( HomeHOM13_SpeedVisualizer );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Title, _Const0000 );
  ViewsText_OnSetAlignment( &_this->Title, ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Title, EwLoadString( &StringsINF01_SPEED_VISUALIZER ));
  CoreGroup__Add( _this, ((CoreView)&_this->Title ), 0 );
  ViewsText_OnSetFont( &_this->Title, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));

  /* Call the user defined constructor */
  HomeHOM13_SpeedVisualizer_Init( _this, aArg );
}

/* Re-Initializer for the class 'Home::HOM13_SpeedVisualizer' */
void HomeHOM13_SpeedVisualizer__ReInit( HomeHOM13_SpeedVisualizer _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Title );
}

/* Finalizer method for the class 'Home::HOM13_SpeedVisualizer' */
void HomeHOM13_SpeedVisualizer__Done( HomeHOM13_SpeedVisualizer _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Title );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void HomeHOM13_SpeedVisualizer_Init( HomeHOM13_SpeedVisualizer _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0003 ));
}

/* 'C' function for method : 'Home::HOM13_SpeedVisualizer.OnShortEnterKeyActivated()' */
void HomeHOM13_SpeedVisualizer_OnShortEnterKeyActivated( HomeHOM13_SpeedVisualizer _this )
{
  CoreGroup_PresentDialog((CoreGroup)CoreView__GetRoot( _this ), ((CoreGroup)EwNewObject( 
  LauncherLNC_Main, 0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Home::HOM13_SpeedVisualizer.OnShortHomeKeyActivated()' */
void HomeHOM13_SpeedVisualizer_OnShortHomeKeyActivated( HomeHOM13_SpeedVisualizer _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Variants derived from the class : 'Home::HOM13_SpeedVisualizer' */
EW_DEFINE_CLASS_VARIANTS( HomeHOM13_SpeedVisualizer )
EW_END_OF_CLASS_VARIANTS( HomeHOM13_SpeedVisualizer )

/* Virtual Method Table (VMT) for the class : 'Home::HOM13_SpeedVisualizer' */
EW_DEFINE_CLASS( HomeHOM13_SpeedVisualizer, ComponentsBaseMainBG, Title, Title, 
                 Title, Title, _None, _None, "Home::HOM13_SpeedVisualizer" )
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
  HomeHOM13_SpeedVisualizer_OnShortEnterKeyActivated,
  HomeHOM13_SpeedVisualizer_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( HomeHOM13_SpeedVisualizer )

/* Embedded Wizard */
