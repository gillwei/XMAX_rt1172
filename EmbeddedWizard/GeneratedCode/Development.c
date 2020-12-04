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
#include "_CoreKeyPressHandler.h"
#include "_CoreView.h"
#include "_DevelopmentMain.h"
#include "_FactoryMain.h"
#include "_MenuItemBaseLower.h"
#include "_MenuVerticalMenu.h"
#include "Core.h"
#include "Development.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000022, /* ratio 117.65 % */
  0xB8001F00, 0x8008C452, 0x00C60030, 0x0DE003A0, 0xF2003900, 0x80010000, 0x0032800A,
  0xC0042CE6, 0x808023B1, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XStringRes _Const0001 = { _StringsDefault0, 0x0002 };
static const XRect _Const0002 = {{ 0, 36 }, { 480, 272 }};

#ifndef EW_DONT_CHECK_INDEX
  /* This function is used to check the indices when accessing an array.
     If you don't want this verification add the define EW_DONT_CHECK_INDEX
     to your Makefile or project settings. */
  static int EwCheckIndex( int aIndex, int aRange, const char* aFile, int aLine )
  {
    if (( aIndex < 0 ) || ( aIndex >= aRange ))
    {
      EwPrint( "[FATAL ERROR in %s:%d] Array index %d out of bounds %d",
                aFile, aLine, aIndex, aRange );
      EwPanic();
    }
    return aIndex;
  }

  #define EwCheckIndex( aIndex, aRange ) \
    EwCheckIndex( aIndex, aRange, __FILE__, __LINE__ )
#else
  #define EwCheckIndex( aIndex, aRange ) aIndex
#endif

/* Initializer for the class 'Development::Main' */
void DevelopmentMain__Init( DevelopmentMain _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DevelopmentMain );

  /* ... then construct all embedded objects */
  MenuVerticalMenu__Init( &_this->Menu, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DevelopmentMain );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0001 ));
  CoreRectView__OnSetBounds( &_this->Menu, _Const0002 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 1 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Menu, 56 );
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), -2 );
  _this->Menu.Super1.PassKeyHold = EwNewSlot( _this, ComponentsBaseComponent__OnLongKeyPressed );
}

/* Re-Initializer for the class 'Development::Main' */
void DevelopmentMain__ReInit( DevelopmentMain _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  MenuVerticalMenu__ReInit( &_this->Menu );
}

/* Finalizer method for the class 'Development::Main' */
void DevelopmentMain__Done( DevelopmentMain _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  MenuVerticalMenu__Done( &_this->Menu );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Development::Main.OnLongKeyPressed()' */
void DevelopmentMain_OnLongKeyPressed( DevelopmentMain _this, XObject sender )
{
  CoreKeyPressHandler CurrentKeyHandler = EwCastObject( sender, CoreKeyPressHandler );

  if (( CurrentKeyHandler != 0 ) && ( _this->Super5.Owner != 0 ))
  {
    switch ( CurrentKeyHandler->Code )
    {
      case CoreKeyCodeOk :
        CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 
        0, EwNullSlot, EwNullSlot, 0 );
      break;

      default : 
        ;
    }
  }
}

/* 'C' function for method : 'Development::Main.LoadItemClass()' */
XClass DevelopmentMain_LoadItemClass( DevelopmentMain _this, XInt32 aItemNo )
{
  XClass ItemClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemClass = 0;

  if ( aItemNo >= 0 )
  {
    ItemClass = EW_CLASS( MenuItemBaseLower );
  }

  return ItemClass;
}

/* 'C' function for method : 'Development::Main.LoadItemTitle()' */
XString DevelopmentMain_LoadItemTitle( DevelopmentMain _this, XInt32 aItemNo )
{
  XString Title = 0;

  if ( aItemNo < 1 )
  {
    Title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 1 )];
  }

  return Title;
}

/* 'C' function for method : 'Development::Main.OnItemActivate()' */
void DevelopmentMain_OnItemActivate( DevelopmentMain _this, XInt32 aItemNo, MenuItemBase 
  aMenuItem )
{
  if ( aMenuItem == 0 )
    ;

  switch ( aItemNo )
  {
    case 0 :
      ComponentsBaseComponent_SlideInDialog((ComponentsBaseComponent)_this, ((CoreGroup)EwNewObject( 
      FactoryMain, 0 )));
    break;

    default : 
      ;
  }
}

/* Variants derived from the class : 'Development::Main' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentMain )
EW_END_OF_CLASS_VARIANTS( DevelopmentMain )

/* Virtual Method Table (VMT) for the class : 'Development::Main' */
EW_DEFINE_CLASS( DevelopmentMain, MenuBaseMenuView, Menu, Menu, Menu, Menu, ItemTitleArray, 
                 _None, "Development::Main" )
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  DevelopmentMain_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
  DevelopmentMain_LoadItemClass,
  DevelopmentMain_LoadItemTitle,
  DevelopmentMain_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
EW_END_OF_CLASS( DevelopmentMain )

/* Embedded Wizard */
