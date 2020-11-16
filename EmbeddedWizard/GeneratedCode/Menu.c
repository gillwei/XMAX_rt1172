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
#include "_CoreTimer.h"
#include "_CoreVerticalList.h"
#include "_CoreView.h"
#include "_MenuBaseMenuView.h"
#include "_MenuItemBase.h"
#include "_MenuItemBtPairedDevice.h"
#include "_MenuItemCheckbox.h"
#include "_MenuItemRightArrow.h"
#include "_MenuItemWrapper.h"
#include "_MenuScrollbar.h"
#include "_MenuVerticalMenu.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsFrame.h"
#include "_ViewsImage.h"
#include "_ViewsLine.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "_WidgetSetToggleButton.h"
#include "_WidgetSetToggleButtonConfig.h"
#include "Core.h"
#include "Fonts.h"
#include "Menu.h"
#include "Resource.h"
#include "UIConfig.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000072, /* ratio 77.19 % */
  0xB8003F00, 0x0009E452, 0x1C8A0037, 0x40074004, 0x00720019, 0x80087148, 0x0030C50D,
  0x016450E6, 0x8A440400, 0x4C362870, 0xC90010C3, 0x74750B37, 0xC212C004, 0x150B82C0,
  0x30F86C22, 0x28001222, 0xA001922D, 0x044B23D2, 0x2C98A92F, 0xCB21F169, 0x020200A3,
  0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 440, 60 }};
static const XColor _Const0001 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0002 = {{ 0, 53 }, { 440, 63 }};
static const XRect _Const0003 = {{ 20, 10 }, { 380, 50 }};
static const XColor _Const0004 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XStringRes _Const0005 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0006 = { _StringsDefault0, 0x0021 };
static const XColor _Const0007 = { 0x64, 0x64, 0x64, 0xFF };
static const XRect _Const0008 = {{ 396, 11 }, { 433, 48 }};
static const XRect _Const0009 = {{ 0, 0 }, { 460, 240 }};
static const XRect _Const000A = {{ 0, 0 }, { 480, 240 }};
static const XRect _Const000B = {{ 0, 0 }, { 440, 240 }};
static const XRect _Const000C = {{ 450, 0 }, { 460, 240 }};
static const XRect _Const000D = {{ 392, 15 }, { 422, 45 }};
static const XRect _Const000E = {{ 0, 0 }, { 400, 60 }};
static const XStringRes _Const000F = { _StringsDefault0, 0x0031 };
static const XRect _Const0010 = {{ 0, 0 }, { 10, 240 }};
static const XPoint _Const0011 = { 5, 240 };
static const XPoint _Const0012 = { 5, 0 };
static const XRect _Const0013 = {{ 0, 50 }, { 10, 80 }};
static const XRect _Const0014 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0015 = {{ 20, 10 }, { 370, 50 }};

/* Initializer for the class 'Menu::ItemBase' */
void MenuItemBase__Init( MenuItemBase _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MenuItemBase );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Background, &_this->_XObject, 0 );
  CoreKeyPressHandler__Init( &_this->KeyHandler, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ListDivider, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->FocusFrameFlashTimer, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Title, &_this->_XObject, 0 );
  ViewsFrame__Init( &_this->FocusFrame, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MenuItemBase );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Background, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Background, _Const0001 );
  _this->KeyHandler.Filter = CoreKeyCodeOk;
  CoreRectView__OnSetBounds( &_this->ListDivider, _Const0002 );
  ViewsImage_OnSetAlignment( &_this->ListDivider, ViewsImageAlignmentScaleToFit );
  CoreTimer_OnSetPeriod( &_this->FocusFrameFlashTimer, 0 );
  CoreTimer_OnSetBegin( &_this->FocusFrameFlashTimer, 100 );
  CoreView_OnSetLayout((CoreView)&_this->Title, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->Title, _Const0003 );
  ViewsText_OnSetAlignment( &_this->Title, ViewsTextAlignmentAlignHorzLeft | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Title, 0 );
  ViewsText_OnSetColor( &_this->Title, _Const0004 );
  CoreRectView__OnSetBounds( &_this->FocusFrame, _Const0000 );
  ViewsFrame_OnSetVisible( &_this->FocusFrame, 0 );
  _this->Focusable = 1;
  CoreGroup__Add( _this, ((CoreView)&_this->Background ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ListDivider ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Title ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->FocusFrame ), 0 );
  _this->KeyHandler.OnRelease = EwNewSlot( _this, MenuItemBase__OnEnterReleaseSlot );
  _this->KeyHandler.OnPress = EwNullSlot;
  _this->KeyHandler.OnHold = EwNewSlot( _this, MenuItemBase_OnEnterHoldSlot );
  ViewsImage_OnSetBitmap( &_this->ListDivider, EwLoadResource( &ResourceListDivider, 
  ResourcesBitmap ));
  _this->FocusFrameFlashTimer.OnTrigger = EwNewSlot( _this, MenuItemBase_OnFocusFrameFlashTimer );
  ViewsText_OnSetFont( &_this->Title, EwLoadResource( &FontsFontNotoSansCjkJp36, 
  ResourcesFont ));
  ViewsFrame_OnSetBitmap( &_this->FocusFrame, EwLoadResource( &ResourceFocusFrame, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'Menu::ItemBase' */
void MenuItemBase__ReInit( MenuItemBase _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Background );
  CoreKeyPressHandler__ReInit( &_this->KeyHandler );
  ViewsImage__ReInit( &_this->ListDivider );
  CoreTimer__ReInit( &_this->FocusFrameFlashTimer );
  ViewsText__ReInit( &_this->Title );
  ViewsFrame__ReInit( &_this->FocusFrame );
}

/* Finalizer method for the class 'Menu::ItemBase' */
void MenuItemBase__Done( MenuItemBase _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Background );
  CoreKeyPressHandler__Done( &_this->KeyHandler );
  ViewsImage__Done( &_this->ListDivider );
  CoreTimer__Done( &_this->FocusFrameFlashTimer );
  ViewsText__Done( &_this->Title );
  ViewsFrame__Done( &_this->FocusFrame );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* The method UpdateViewState() is invoked automatically after the state of the 
   component has been changed. This method can be overridden and filled with logic 
   to ensure the visual aspect of the component does reflect its current state. 
   For example, the 'enabled' state of the component can affect its colors (disabled 
   components may appear pale). In this case the logic of the method should modify 
   the respective color properties accordingly to the current 'enabled' state. 
   The current state of the component is passed as a set in the parameter aState. 
   It reflects the very basic component state like its visibility or the ability 
   to react to user inputs. Beside this common state, the method can also involve 
   any other variables used in the component as long as they reflect its current 
   state. For example, the toggle switch component can take in account its toggle 
   state 'on' or 'off' and change accordingly the location of the slider, etc.
   Usually, this method will be invoked automatically by the framework. Optionally 
   you can request its invocation by using the method @InvalidateViewState(). */
void MenuItemBase_UpdateViewState( MenuItemBase _this, XSet aState )
{
  CoreGroup_UpdateViewState((CoreGroup)_this, aState );

  if ( _this->FocusFrameFlashTimer.Enabled )
  {
    ViewsFrame_OnSetFrameNumber( &_this->FocusFrame, 1 );
  }
  else
    if ((( aState & CoreViewStateFocused ) == CoreViewStateFocused ))
    {
      if ( _this->Focusable )
      {
        ViewsFrame_OnSetFrameNumber( &_this->FocusFrame, 0 );
        ViewsFrame_OnSetVisible( &_this->FocusFrame, 1 );
      }
    }
    else
    {
      ViewsFrame_OnSetVisible( &_this->FocusFrame, 0 );
    }
}

/* This internal slot method is called when the '@KeyHandler' is activated (when 
   the user has pressed the key specified in the property 'Filter' of the key handler). */
void MenuItemBase_OnEnterReleaseSlot( MenuItemBase _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwTrace( "%s%b", EwLoadString( &_Const0005 ), _this->KeyHandler.Repetition );

  if (( 0 == _this->KeyHandler.Repetition ) && _this->Focusable )
  {
    CoreGroup_InvalidateViewState((CoreGroup)_this );

    if ( _this->FocusFrameFlashTimer.Enabled )
    {
      EwPostSignal( _this->OnActivate, ((XObject)_this ));
      CoreTimer_OnSetEnabled( &_this->FocusFrameFlashTimer, 0 );
    }

    CoreTimer_OnSetEnabled( &_this->FocusFrameFlashTimer, 1 );
  }
}

/* Wrapper function for the virtual method : 'Menu::ItemBase.OnEnterReleaseSlot()' */
void MenuItemBase__OnEnterReleaseSlot( void* _this, XObject sender )
{
  ((MenuItemBase)_this)->_VMT->OnEnterReleaseSlot((MenuItemBase)_this, sender );
}

/* This internal slot method is called when the '@FlashTimer' is expired. It ends 
   the short flash feedback effect. */
void MenuItemBase_OnFocusFrameFlashTimer( MenuItemBase _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_InvalidateViewState((CoreGroup)_this );
  EwPostSignal( _this->OnActivate, ((XObject)_this ));
}

/* 'C' function for method : 'Menu::ItemBase.SetTitle()' */
void MenuItemBase_SetTitle( MenuItemBase _this, XString aTitle )
{
  if ( EwCompString( _this->Title.String, aTitle ) != 0 )
  {
    ViewsText_OnSetString( &_this->Title, aTitle );
  }
}

/* This internal slot method is called when the '@KeyHandler' is activated (when 
   the user has pressed the key specified in the property 'Filter' of the key handler). */
void MenuItemBase_OnEnterHoldSlot( MenuItemBase _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwTrace( "%s%i", EwLoadString( &_Const0006 ), _this->KeyHandler.RepetitionCount );
  EwPostSignal( _this->OnEnterHold, ((XObject)&_this->KeyHandler ));
}

/* 'C' function for method : 'Menu::ItemBase.OnSetEnabled()' */
void MenuItemBase_OnSetEnabled( MenuItemBase _this, XBool value )
{
  if ( _this->Super1.Enabled != value )
  {
    _this->Super1.Enabled = value;

    if ( value )
    {
      ViewsText_OnSetColor( &_this->Title, _Const0004 );
    }
    else
    {
      ViewsText_OnSetColor( &_this->Title, _Const0007 );
    }
  }
}

/* 'C' function for method : 'Menu::ItemBase.OnSetFocusable()' */
void MenuItemBase_OnSetFocusable( MenuItemBase _this, XBool value )
{
  if ( _this->Focusable != value )
  {
    _this->Focusable = value;
    ViewsFrame_OnSetVisible( &_this->FocusFrame, value );
  }
}

/* Variants derived from the class : 'Menu::ItemBase' */
EW_DEFINE_CLASS_VARIANTS( MenuItemBase )
EW_END_OF_CLASS_VARIANTS( MenuItemBase )

/* Virtual Method Table (VMT) for the class : 'Menu::ItemBase' */
EW_DEFINE_CLASS( MenuItemBase, CoreGroup, OnActivate, OnActivate, Background, Background, 
                 Focusable, Focusable, "Menu::ItemBase" )
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
  MenuItemBase_OnSetEnabled,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DismissDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  MenuItemBase_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  MenuItemBase_OnEnterReleaseSlot,
EW_END_OF_CLASS( MenuItemBase )

/* Initializer for the class 'Menu::ItemRightArrow' */
void MenuItemRightArrow__Init( MenuItemRightArrow _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuItemBase__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MenuItemRightArrow );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->IconRight, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MenuItemRightArrow );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->IconRight, _Const0008 );
  ViewsImage_OnSetAlignment( &_this->IconRight, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter | ViewsImageAlignmentScaleToFit );
  CoreGroup__Add( _this, ((CoreView)&_this->IconRight ), 0 );
  ViewsImage_OnSetBitmap( &_this->IconRight, EwLoadResource( &ResourceListIconNext, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'Menu::ItemRightArrow' */
void MenuItemRightArrow__ReInit( MenuItemRightArrow _this )
{
  /* At first re-initialize the super class ... */
  MenuItemBase__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->IconRight );
}

/* Finalizer method for the class 'Menu::ItemRightArrow' */
void MenuItemRightArrow__Done( MenuItemRightArrow _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuItemBase );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->IconRight );

  /* Don't forget to deinitialize the super class ... */
  MenuItemBase__Done( &_this->_Super );
}

/* 'C' function for method : 'Menu::ItemRightArrow.OnSetEnabled()' */
void MenuItemRightArrow_OnSetEnabled( MenuItemRightArrow _this, XBool value )
{
  if ( _this->Super2.Enabled != value )
  {
    MenuItemBase_OnSetEnabled((MenuItemBase)_this, value );

    if ( value )
    {
      ViewsImage_OnSetFrameNumber( &_this->IconRight, 0 );
    }
    else
    {
      ViewsImage_OnSetFrameNumber( &_this->IconRight, 1 );
    }
  }
}

/* Variants derived from the class : 'Menu::ItemRightArrow' */
EW_DEFINE_CLASS_VARIANTS( MenuItemRightArrow )
EW_END_OF_CLASS_VARIANTS( MenuItemRightArrow )

/* Virtual Method Table (VMT) for the class : 'Menu::ItemRightArrow' */
EW_DEFINE_CLASS( MenuItemRightArrow, MenuItemBase, IconRight, IconRight, IconRight, 
                 IconRight, _None, _None, "Menu::ItemRightArrow" )
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
  MenuItemRightArrow_OnSetEnabled,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DismissDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  MenuItemBase_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  MenuItemBase_OnEnterReleaseSlot,
EW_END_OF_CLASS( MenuItemRightArrow )

/* Initializer for the class 'Menu::VerticalMenu' */
void MenuVerticalMenu__Init( MenuVerticalMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MenuVerticalMenu );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Background, &_this->_XObject, 0 );
  CoreVerticalList__Init( &_this->MenuList, &_this->_XObject, 0 );
  MenuScrollbar__Init( &_this->Scrollbar, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MenuVerticalMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0009 );
  CoreRectView__OnSetBounds( &_this->Background, _Const000A );
  ViewsRectangle_OnSetColor( &_this->Background, _Const0001 );
  CoreRectView__OnSetBounds( &_this->MenuList, _Const000B );
  CoreVerticalList_OnSetSelectedItem( &_this->MenuList, 0 );
  CoreVerticalList_OnSetItemHeight( &_this->MenuList, 60 );
  CoreVerticalList_OnSetNoOfItems( &_this->MenuList, 1 );
  CoreVerticalList_OnSetItemClass( &_this->MenuList, EW_CLASS( MenuItemWrapper ));
  CoreRectView__OnSetBounds( &_this->Scrollbar, _Const000C );
  MenuScrollbar_OnSetPageItems( &_this->Scrollbar, 4 );
  _this->Focusable = 1;
  CoreGroup__Add( _this, ((CoreView)&_this->Background ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MenuList ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Scrollbar ), 0 );
  CoreGroup__OnSetFocus( &_this->MenuList, 0 );
  _this->MenuList.OnLoadItem = EwNewSlot( _this, MenuVerticalMenu_OnLoadItemSlot );
}

/* Re-Initializer for the class 'Menu::VerticalMenu' */
void MenuVerticalMenu__ReInit( MenuVerticalMenu _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Background );
  CoreVerticalList__ReInit( &_this->MenuList );
  MenuScrollbar__ReInit( &_this->Scrollbar );
}

/* Finalizer method for the class 'Menu::VerticalMenu' */
void MenuVerticalMenu__Done( MenuVerticalMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Background );
  CoreVerticalList__Done( &_this->MenuList );
  MenuScrollbar__Done( &_this->Scrollbar );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* 'C' function for method : 'Menu::VerticalMenu.OnLongKeyPressed()' */
void MenuVerticalMenu_OnLongKeyPressed( MenuVerticalMenu _this, XObject sender )
{
  EwSignal( _this->Super1.PassKeyHold, sender );
}

/* 'C' function for method : 'Menu::VerticalMenu.OnShortDownKeyPressed()' */
void MenuVerticalMenu_OnShortDownKeyPressed( MenuVerticalMenu _this )
{
  if ( CoreGroup__IsCurrentDialog( _this->Super4.Owner ))
  {
    XInt32 NextItemIdx = _this->MenuList.SelectedItem + 1;

    if ( NextItemIdx < _this->MenuList.NoOfItems )
    {
      MenuItemWrapper Item = EwCastObject( CoreVerticalList_GetViewForItem( &_this->MenuList, 
        NextItemIdx ), MenuItemWrapper );

      if (( Item != 0 ) && CoreGroup__OnGetEnabled( Item ))
      {
        CoreVerticalList_OnSetSelectedItem( &_this->MenuList, NextItemIdx );
        CoreVerticalList_EnsureVisible( &_this->MenuList, _this->MenuList.SelectedItem, 
        0, 0, EwNullSlot );
        MenuScrollbar_OnSetViewIdx( &_this->Scrollbar, _this->MenuList.SelectedItem );
      }
    }
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.OnShortUpKeyPressed()' */
void MenuVerticalMenu_OnShortUpKeyPressed( MenuVerticalMenu _this )
{
  if ( CoreGroup__IsCurrentDialog( _this->Super4.Owner ))
  {
    XInt32 PrevItemIdx = _this->MenuList.SelectedItem - 1;

    if ( PrevItemIdx >= 0 )
    {
      CoreVerticalList_OnSetSelectedItem( &_this->MenuList, PrevItemIdx );
      CoreVerticalList_EnsureVisible( &_this->MenuList, _this->MenuList.SelectedItem, 
      0, 0, EwNullSlot );
      MenuScrollbar_OnSetViewIdx( &_this->Scrollbar, _this->MenuList.SelectedItem );
    }
  }
}

/* This method is called by 'VerticalList' every time the list loads or updates 
   an item. */
void MenuVerticalMenu_OnLoadItemSlot( MenuVerticalMenu _this, XObject sender )
{
  XInt32 ItemNo;
  MenuItemWrapper Item;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ItemNo = _this->MenuList.Item;
  Item = EwCastObject( _this->MenuList.View, MenuItemWrapper );

  if ( Item != 0 )
  {
    MenuBaseMenuView OwnerMenu = EwCastObject( _this->Super4.Owner, MenuBaseMenuView );

    if ( OwnerMenu != 0 )
    {
      MenuItemWrapper_OnSetItemClass( Item, MenuBaseMenuView__LoadItemClass( OwnerMenu, 
      ItemNo ));
      MenuItemWrapper_OnSetTitle( Item, MenuBaseMenuView__LoadItemTitle( OwnerMenu, 
      ItemNo ));
      CoreGroup__OnSetEnabled( Item, MenuBaseMenuView__LoadItemEnabled( OwnerMenu, 
      ItemNo ));
      Item->OnActivate = EwNewSlot( _this, MenuVerticalMenu_OnItemActivateSlot );
      Item->OnEnterHold = EwNewSlot( _this, ComponentsBaseComponent__OnLongKeyPressed );
      MenuItemWrapper_OnSetFocusable( Item, _this->Focusable );
    }

    if ( EW_CLASS( MenuItemCheckbox ) == Item->ItemClass )
    {
      MenuItemWrapper_OnSetChecked( Item, MenuBaseMenuView__LoadItemChecked( OwnerMenu, 
      ItemNo ));
    }
    else
      if ( EW_CLASS( MenuItemBtPairedDevice ) == Item->ItemClass )
      {
        MenuItemWrapper_OnSetConnected( Item, MenuBaseMenuView__LoadItemConnected( 
        OwnerMenu, ItemNo ));
        MenuItemWrapper_OnSetValid( Item, MenuBaseMenuView__LoadItemValid( OwnerMenu, 
        ItemNo ));
      }

    CoreRectView__OnSetBounds( Item, EwSetRectSize( Item->Super2.Bounds, EwNewPoint( 
    EwGetRectW( _this->MenuList.Super2.Bounds ), _this->MenuList.ItemHeight )));
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.OnItemActivateSlot()' */
void MenuVerticalMenu_OnItemActivateSlot( MenuVerticalMenu _this, XObject sender )
{
  MenuItemBase MenuItem = 0;
  MenuItemWrapper WrapperItem = EwCastObject( sender, MenuItemWrapper );
  MenuBaseMenuView OwnerMenu;

  if ( WrapperItem != 0 )
  {
    CoreView Menu = CoreGroup__FindNextView( WrapperItem, 0, 0 );

    if ( Menu != 0 )
    {
      MenuItem = EwCastObject( Menu, MenuItemBase );
    }
  }

  OwnerMenu = EwCastObject( _this->Super4.Owner, MenuBaseMenuView );

  if ( OwnerMenu != 0 )
  {
    MenuBaseMenuView__OnItemActivate( OwnerMenu, _this->MenuList.SelectedItem, MenuItem );
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.OnSetNoOfItems()' */
void MenuVerticalMenu_OnSetNoOfItems( MenuVerticalMenu _this, XInt32 value )
{
  if ( _this->NoOfItems != value )
  {
    _this->NoOfItems = value;
    CoreVerticalList_OnSetNoOfItems( &_this->MenuList, value );
    MenuScrollbar_OnSetListItems( &_this->Scrollbar, value );
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.InvalidateItems()' */
void MenuVerticalMenu_InvalidateItems( MenuVerticalMenu _this, XInt32 aFirstItem, 
  XInt32 aLastItem )
{
  CoreVerticalList_InvalidateItems( &_this->MenuList, aFirstItem, aLastItem );
  MenuScrollbar_OnSetViewIdx( &_this->Scrollbar, 0 );
}

/* Variants derived from the class : 'Menu::VerticalMenu' */
EW_DEFINE_CLASS_VARIANTS( MenuVerticalMenu )
EW_END_OF_CLASS_VARIANTS( MenuVerticalMenu )

/* Virtual Method Table (VMT) for the class : 'Menu::VerticalMenu' */
EW_DEFINE_CLASS( MenuVerticalMenu, ComponentsBaseComponent, Background, Background, 
                 Background, Background, NoOfItems, NoOfItems, "Menu::VerticalMenu" )
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
  MenuVerticalMenu_OnLongKeyPressed,
  MenuVerticalMenu_OnShortDownKeyPressed,
  MenuVerticalMenu_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
EW_END_OF_CLASS( MenuVerticalMenu )

/* Initializer for the class 'Menu::ItemCheckbox' */
void MenuItemCheckbox__Init( MenuItemCheckbox _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuItemBase__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MenuItemCheckbox );

  /* ... then construct all embedded objects */
  WidgetSetToggleButton__Init( &_this->CheckBoxButton, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MenuItemCheckbox );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->CheckBoxButton, _Const000D );
  CoreGroup__OnSetEnabled( &_this->CheckBoxButton, 1 );
  WidgetSetToggleButton_OnSetChecked( &_this->CheckBoxButton, 0 );
  WidgetSetToggleButton_OnSetIconFrame( &_this->CheckBoxButton, 0 );
  WidgetSetToggleButton_OnSetLabel( &_this->CheckBoxButton, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CheckBoxButton ), 0 );
  WidgetSetToggleButton_OnSetAppearance( &_this->CheckBoxButton, EwGetAutoObject( 
  &UIConfigToggleButtonConfig, WidgetSetToggleButtonConfig ));
}

/* Re-Initializer for the class 'Menu::ItemCheckbox' */
void MenuItemCheckbox__ReInit( MenuItemCheckbox _this )
{
  /* At first re-initialize the super class ... */
  MenuItemBase__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  WidgetSetToggleButton__ReInit( &_this->CheckBoxButton );
}

/* Finalizer method for the class 'Menu::ItemCheckbox' */
void MenuItemCheckbox__Done( MenuItemCheckbox _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuItemBase );

  /* Finalize all embedded objects */
  WidgetSetToggleButton__Done( &_this->CheckBoxButton );

  /* Don't forget to deinitialize the super class ... */
  MenuItemBase__Done( &_this->_Super );
}

/* This internal slot method is called when the '@KeyHandler' is activated (when 
   the user has pressed the key specified in the property 'Filter' of the key handler). */
void MenuItemCheckbox_OnEnterReleaseSlot( MenuItemCheckbox _this, XObject sender )
{
  MenuItemBase_OnEnterReleaseSlot((MenuItemBase)_this, sender );
  WidgetSetToggleButton_OnSetChecked( &_this->CheckBoxButton, (XBool)!_this->CheckBoxButton.Checked );
}

/* 'C' function for method : 'Menu::ItemCheckbox.OnSetEnabled()' */
void MenuItemCheckbox_OnSetEnabled( MenuItemCheckbox _this, XBool value )
{
  if ( _this->Super2.Enabled != value )
  {
    MenuItemBase_OnSetEnabled((MenuItemBase)_this, value );
    CoreGroup__OnSetEnabled( &_this->CheckBoxButton, value );
  }
}

/* 'C' function for method : 'Menu::ItemCheckbox.OnSetChecked()' */
void MenuItemCheckbox_OnSetChecked( MenuItemCheckbox _this, XBool value )
{
  if ( _this->Checked == value )
    return;

  _this->Checked = value;
  WidgetSetToggleButton_OnSetChecked( &_this->CheckBoxButton, value );
}

/* Variants derived from the class : 'Menu::ItemCheckbox' */
EW_DEFINE_CLASS_VARIANTS( MenuItemCheckbox )
EW_END_OF_CLASS_VARIANTS( MenuItemCheckbox )

/* Virtual Method Table (VMT) for the class : 'Menu::ItemCheckbox' */
EW_DEFINE_CLASS( MenuItemCheckbox, MenuItemBase, CheckBoxButton, CheckBoxButton, 
                 CheckBoxButton, CheckBoxButton, Checked, Checked, "Menu::ItemCheckbox" )
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
  MenuItemCheckbox_OnSetEnabled,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DismissDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  MenuItemBase_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  MenuItemCheckbox_OnEnterReleaseSlot,
EW_END_OF_CLASS( MenuItemCheckbox )

/* Initializer for the class 'Menu::ItemWrapper' */
void MenuItemWrapper__Init( MenuItemWrapper _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MenuItemWrapper );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MenuItemWrapper );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const000E );
  _this->Title = EwShareString( EwLoadString( &_Const000F ));
  _this->Focusable = 1;
  _this->Valid = 1;
}

/* Re-Initializer for the class 'Menu::ItemWrapper' */
void MenuItemWrapper__ReInit( MenuItemWrapper _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Menu::ItemWrapper' */
void MenuItemWrapper__Done( MenuItemWrapper _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* 'C' function for method : 'Menu::ItemWrapper.OnGetEnabled()' */
XBool MenuItemWrapper_OnGetEnabled( MenuItemWrapper _this )
{
  return _this->Super1.Enabled;
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetEnabled()' */
void MenuItemWrapper_OnSetEnabled( MenuItemWrapper _this, XBool value )
{
  if ( _this->Super1.Enabled != value )
  {
    CoreView view;
    MenuItemRightArrow ItemRight;
    _this->Super1.Enabled = value;
    view = CoreGroup__FindNextView( _this, 0, 0 );
    ItemRight = EwCastObject( view, MenuItemRightArrow );

    if ( ItemRight != 0 )
    {
      CoreGroup__OnSetEnabled( ItemRight, value );
    }
    else
    {
      MenuItemCheckbox ItemCheck = EwCastObject( view, MenuItemCheckbox );

      if ( ItemCheck != 0 )
      {
        CoreGroup__OnSetEnabled( ItemCheck, value );
      }
      else
      {
        MenuItemBase Item = EwCastObject( view, MenuItemBase );

        if ( Item != 0 )
        {
          CoreGroup__OnSetEnabled( Item, value );
        }
      }
    }
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetItemClass()' */
void MenuItemWrapper_OnSetItemClass( MenuItemWrapper _this, XClass value )
{
  MenuItemBase Item;

  if ( _this->ItemClass == value )
    return;

  _this->ItemClass = value;

  if ( CoreGroup__CountViews( _this ) > 0 )
  {
    CoreGroup__Remove( _this, CoreGroup__FindNextView( _this, 0, 0 ));
  }

  Item = EwCastObject( EwNewObjectIndirect( value, 0 ), MenuItemBase );
  Item->OnActivate = EwNewSlot( _this, MenuItemWrapper_OnActivateSlot );
  Item->OnEnterHold = EwNewSlot( _this, MenuItemWrapper_OnEnterHoldSlot );
  CoreGroup__Add( _this, ((CoreView)Item ), 0 );
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetTitle()' */
void MenuItemWrapper_OnSetTitle( MenuItemWrapper _this, XString value )
{
  if ( EwCompString( _this->Title, value ) != 0 )
  {
    CoreView view;
    MenuItemBase MenuItem;
    _this->Title = EwShareString( value );
    view = CoreGroup__FindNextView( _this, 0, 0 );
    MenuItem = EwCastObject( view, MenuItemBase );

    if ( MenuItem != 0 )
    {
      MenuItemBase_SetTitle( MenuItem, _this->Title );
    }
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnActivateSlot()' */
void MenuItemWrapper_OnActivateSlot( MenuItemWrapper _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwPostSignal( _this->OnActivate, ((XObject)_this ));
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetChecked()' */
void MenuItemWrapper_OnSetChecked( MenuItemWrapper _this, XBool value )
{
  if ( _this->Checked != value )
  {
    CoreView view;
    MenuItemCheckbox Checkbox;
    _this->Checked = value;
    view = CoreGroup__FindNextView( _this, 0, 0 );
    Checkbox = EwCastObject( view, MenuItemCheckbox );

    if ( Checkbox != 0 )
    {
      MenuItemCheckbox_OnSetChecked( Checkbox, value );
    }
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnEnterHoldSlot()' */
void MenuItemWrapper_OnEnterHoldSlot( MenuItemWrapper _this, XObject sender )
{
  EwPostSignal( _this->OnEnterHold, sender );
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetConnected()' */
void MenuItemWrapper_OnSetConnected( MenuItemWrapper _this, XBool value )
{
  if ( _this->Connected != value )
  {
    CoreView view;
    MenuItemBtPairedDevice PairedDevice;
    _this->Connected = value;
    view = CoreGroup__FindNextView( _this, 0, 0 );
    PairedDevice = EwCastObject( view, MenuItemBtPairedDevice );

    if ( PairedDevice != 0 )
    {
      MenuItemBtPairedDevice_OnSetConnected( PairedDevice, value );
    }
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetFocusable()' */
void MenuItemWrapper_OnSetFocusable( MenuItemWrapper _this, XBool value )
{
  if ( _this->Focusable != value )
  {
    CoreView view;
    MenuItemBase Item;
    _this->Focusable = value;
    view = CoreGroup__FindNextView( _this, 0, 0 );
    Item = EwCastObject( view, MenuItemBase );

    if ( Item != 0 )
    {
      MenuItemBase_OnSetFocusable( Item, value );
    }
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetValid()' */
void MenuItemWrapper_OnSetValid( MenuItemWrapper _this, XBool value )
{
  if ( _this->Valid != value )
  {
    CoreView view;
    MenuItemBtPairedDevice PairedDevice;
    _this->Valid = value;
    view = CoreGroup__FindNextView( _this, 0, 0 );
    PairedDevice = EwCastObject( view, MenuItemBtPairedDevice );

    if ( PairedDevice != 0 )
    {
      MenuItemBtPairedDevice_OnSetValid( PairedDevice, value );
    }
  }
}

/* Variants derived from the class : 'Menu::ItemWrapper' */
EW_DEFINE_CLASS_VARIANTS( MenuItemWrapper )
EW_END_OF_CLASS_VARIANTS( MenuItemWrapper )

/* Virtual Method Table (VMT) for the class : 'Menu::ItemWrapper' */
EW_DEFINE_CLASS( MenuItemWrapper, CoreGroup, OnActivate, OnActivate, Title, Title, 
                 Title, ItemClass, "Menu::ItemWrapper" )
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
  MenuItemWrapper_OnGetEnabled,
  MenuItemWrapper_OnSetEnabled,
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
EW_END_OF_CLASS( MenuItemWrapper )

/* Initializer for the class 'Menu::Scrollbar' */
void MenuScrollbar__Init( MenuScrollbar _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MenuScrollbar );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Background, &_this->_XObject, 0 );
  ViewsLine__Init( &_this->Track, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->Bar, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MenuScrollbar );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0010 );
  CoreRectView__OnSetBounds( &_this->Background, _Const0010 );
  ViewsRectangle_OnSetColor( &_this->Background, _Const0001 );
  CoreLineView_OnSetPoint2((CoreLineView)&_this->Track, _Const0011 );
  CoreLineView_OnSetPoint1((CoreLineView)&_this->Track, _Const0012 );
  ViewsLine_OnSetWidth( &_this->Track, 3 );
  ViewsLine_OnSetColor( &_this->Track, _Const0007 );
  CoreRectView__OnSetBounds( &_this->Bar, _Const0013 );
  CoreGroup__Add( _this, ((CoreView)&_this->Background ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Track ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Bar ), 0 );
}

/* Re-Initializer for the class 'Menu::Scrollbar' */
void MenuScrollbar__ReInit( MenuScrollbar _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Background );
  ViewsLine__ReInit( &_this->Track );
  ViewsRectangle__ReInit( &_this->Bar );
}

/* Finalizer method for the class 'Menu::Scrollbar' */
void MenuScrollbar__Done( MenuScrollbar _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Background );
  ViewsLine__Done( &_this->Track );
  ViewsRectangle__Done( &_this->Bar );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* The method UpdateViewState() is invoked automatically after the state of the 
   component has been changed. This method can be overridden and filled with logic 
   to ensure the visual aspect of the component does reflect its current state. 
   For example, the 'enabled' state of the component can affect its colors (disabled 
   components may appear pale). In this case the logic of the method should modify 
   the respective color properties accordingly to the current 'enabled' state. 
   The current state of the component is passed as a set in the parameter aState. 
   It reflects the very basic component state like its visibility or the ability 
   to react to user inputs. Beside this common state, the method can also involve 
   any other variables used in the component as long as they reflect its current 
   state. For example, the toggle switch component can take in account its toggle 
   state 'on' or 'off' and change accordingly the location of the slider, etc.
   Usually, this method will be invoked automatically by the framework. Optionally 
   you can request its invocation by using the method @InvalidateViewState(). */
void MenuScrollbar_UpdateViewState( MenuScrollbar _this, XSet aState )
{
  CoreGroup_UpdateViewState((CoreGroup)_this, aState );

  if ( _this->PageNum > 0 )
  {
    XInt32 CurrentPage = _this->ViewIdx / _this->PageItems;
    XInt32 BarHeight = (XInt32)((XFloat)EwGetRectH( _this->Super2.Bounds ) / (XFloat)_this->PageNum );
    XInt32 BarTopY = (XInt32)((XFloat)EwGetRectH( _this->Super2.Bounds ) * ((XFloat)CurrentPage 
      / (XFloat)_this->PageNum ));
    CoreRectView__OnSetBounds( &_this->Bar, EwNewRect( _this->Bar.Super1.Bounds.Point1.X, 
    BarTopY, _this->Bar.Super1.Bounds.Point2.X, BarTopY + BarHeight ));
  }
}

/* 'C' function for method : 'Menu::Scrollbar.OnSetViewIdx()' */
void MenuScrollbar_OnSetViewIdx( MenuScrollbar _this, XInt32 value )
{
  if ( _this->ViewIdx != value )
  {
    _this->ViewIdx = value;
    CoreGroup_InvalidateViewState((CoreGroup)_this );
  }
}

/* 'C' function for method : 'Menu::Scrollbar.OnSetPageItems()' */
void MenuScrollbar_OnSetPageItems( MenuScrollbar _this, XInt32 value )
{
  if ( _this->PageItems != value )
  {
    _this->PageItems = value;
    MenuScrollbar_UpdatePageNum( _this );
  }
}

/* 'C' function for method : 'Menu::Scrollbar.OnSetListItems()' */
void MenuScrollbar_OnSetListItems( MenuScrollbar _this, XInt32 value )
{
  if ( _this->ListItems != value )
  {
    _this->ListItems = value;
    MenuScrollbar_UpdatePageNum( _this );
    CoreGroup_InvalidateViewState((CoreGroup)_this );
  }
}

/* 'C' function for method : 'Menu::Scrollbar.UpdatePageNum()' */
void MenuScrollbar_UpdatePageNum( MenuScrollbar _this )
{
  if ( _this->PageItems >= _this->ListItems )
  {
    ViewsRectangle_OnSetVisible( &_this->Bar, 0 );
    ViewsLine_OnSetVisible( &_this->Track, 0 );
    _this->PageNum = 0;
  }
  else
    if ( _this->PageItems > 0 )
    {
      _this->PageNum = _this->ListItems / _this->PageItems;

      if ( _this->ListItems > ( _this->PageNum * _this->PageItems ))
      {
        _this->PageNum = _this->PageNum + 1;
      }

      ViewsRectangle_OnSetVisible( &_this->Bar, 1 );
      ViewsLine_OnSetVisible( &_this->Track, 1 );
    }
}

/* Variants derived from the class : 'Menu::Scrollbar' */
EW_DEFINE_CLASS_VARIANTS( MenuScrollbar )
EW_END_OF_CLASS_VARIANTS( MenuScrollbar )

/* Virtual Method Table (VMT) for the class : 'Menu::Scrollbar' */
EW_DEFINE_CLASS( MenuScrollbar, CoreGroup, Background, Background, Background, Background, 
                 ViewIdx, ViewIdx, "Menu::Scrollbar" )
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
  MenuScrollbar_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
EW_END_OF_CLASS( MenuScrollbar )

/* Initializer for the class 'Menu::BaseMenuView' */
void MenuBaseMenuView__Init( MenuBaseMenuView _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MenuBaseMenuView );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MenuBaseMenuView );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0014 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0014 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0001 );
  CoreGroup__Add( _this, ((CoreView)&_this->Rectangle ), 0 );
}

/* Re-Initializer for the class 'Menu::BaseMenuView' */
void MenuBaseMenuView__ReInit( MenuBaseMenuView _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
}

/* Finalizer method for the class 'Menu::BaseMenuView' */
void MenuBaseMenuView__Done( MenuBaseMenuView _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemClass()' */
XClass MenuBaseMenuView_LoadItemClass( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemClass()' */
XClass MenuBaseMenuView__LoadItemClass( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_VMT->LoadItemClass((MenuBaseMenuView)_this, 
  aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemTitle()' */
XString MenuBaseMenuView_LoadItemTitle( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemTitle()' */
XString MenuBaseMenuView__LoadItemTitle( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_VMT->LoadItemTitle((MenuBaseMenuView)_this, 
  aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.OnItemActivate()' */
void MenuBaseMenuView_OnItemActivate( MenuBaseMenuView _this, XInt32 aItemNo, MenuItemBase 
  aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if (( aMenuItem == 0 ) || ( aItemNo < 0 ))
    ;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.OnItemActivate()' */
void MenuBaseMenuView__OnItemActivate( void* _this, XInt32 aItemNo, MenuItemBase 
  aMenuItem )
{
  ((MenuBaseMenuView)_this)->_VMT->OnItemActivate((MenuBaseMenuView)_this, aItemNo
  , aMenuItem );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemChecked()' */
XBool MenuBaseMenuView_LoadItemChecked( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemChecked()' */
XBool MenuBaseMenuView__LoadItemChecked( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_VMT->LoadItemChecked((MenuBaseMenuView)_this
  , aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemEnabled()' */
XBool MenuBaseMenuView_LoadItemEnabled( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

  return 1;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemEnabled()' */
XBool MenuBaseMenuView__LoadItemEnabled( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_VMT->LoadItemEnabled((MenuBaseMenuView)_this
  , aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemConnected()' */
XBool MenuBaseMenuView_LoadItemConnected( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemConnected()' */
XBool MenuBaseMenuView__LoadItemConnected( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_VMT->LoadItemConnected((MenuBaseMenuView)_this
  , aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemValid()' */
XBool MenuBaseMenuView_LoadItemValid( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  if ( aItemNo >= 0 )
    ;

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemValid()' */
XBool MenuBaseMenuView__LoadItemValid( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_VMT->LoadItemValid((MenuBaseMenuView)_this, 
  aItemNo );
}

/* Variants derived from the class : 'Menu::BaseMenuView' */
EW_DEFINE_CLASS_VARIANTS( MenuBaseMenuView )
EW_END_OF_CLASS_VARIANTS( MenuBaseMenuView )

/* Virtual Method Table (VMT) for the class : 'Menu::BaseMenuView' */
EW_DEFINE_CLASS( MenuBaseMenuView, ComponentsBaseComponent, Rectangle, Rectangle, 
                 Rectangle, Rectangle, _None, _None, "Menu::BaseMenuView" )
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
  ComponentsBaseComponent_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemConnected,
  MenuBaseMenuView_LoadItemValid,
EW_END_OF_CLASS( MenuBaseMenuView )

/* Initializer for the class 'Menu::ItemBtPairedDevice' */
void MenuItemBtPairedDevice__Init( MenuItemBtPairedDevice _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuItemBase__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MenuItemBtPairedDevice );

  /* ... then construct all embedded objects */
  WidgetSetToggleButton__Init( &_this->CheckBoxButton, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MenuItemBtPairedDevice );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Super1.Title, _Const0015 );
  CoreRectView__OnSetBounds( &_this->CheckBoxButton, _Const000D );
  CoreGroup__OnSetEnabled( &_this->CheckBoxButton, 1 );
  WidgetSetToggleButton_OnSetChecked( &_this->CheckBoxButton, 0 );
  WidgetSetToggleButton_OnSetIconFrame( &_this->CheckBoxButton, 0 );
  WidgetSetToggleButton_OnSetLabel( &_this->CheckBoxButton, 0 );
  _this->Valid = 1;
  CoreGroup__Add( _this, ((CoreView)&_this->CheckBoxButton ), 0 );
  WidgetSetToggleButton_OnSetAppearance( &_this->CheckBoxButton, EwGetAutoObject( 
  &UIConfigToggleButtonConfig, WidgetSetToggleButtonConfig ));
}

/* Re-Initializer for the class 'Menu::ItemBtPairedDevice' */
void MenuItemBtPairedDevice__ReInit( MenuItemBtPairedDevice _this )
{
  /* At first re-initialize the super class ... */
  MenuItemBase__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  WidgetSetToggleButton__ReInit( &_this->CheckBoxButton );
}

/* Finalizer method for the class 'Menu::ItemBtPairedDevice' */
void MenuItemBtPairedDevice__Done( MenuItemBtPairedDevice _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuItemBase );

  /* Finalize all embedded objects */
  WidgetSetToggleButton__Done( &_this->CheckBoxButton );

  /* Don't forget to deinitialize the super class ... */
  MenuItemBase__Done( &_this->_Super );
}

/* 'C' function for method : 'Menu::ItemBtPairedDevice.OnSetConnected()' */
void MenuItemBtPairedDevice_OnSetConnected( MenuItemBtPairedDevice _this, XBool 
  value )
{
  if ( _this->Connected != value )
  {
    _this->Connected = value;
    WidgetSetToggleButton_OnSetChecked( &_this->CheckBoxButton, value );
  }
}

/* 'C' function for method : 'Menu::ItemBtPairedDevice.OnSetValid()' */
void MenuItemBtPairedDevice_OnSetValid( MenuItemBtPairedDevice _this, XBool value )
{
  if ( _this->Valid != value )
  {
    _this->Valid = value;
    CoreGroup_OnSetVisible((CoreGroup)&_this->CheckBoxButton, value );
  }
}

/* Variants derived from the class : 'Menu::ItemBtPairedDevice' */
EW_DEFINE_CLASS_VARIANTS( MenuItemBtPairedDevice )
EW_END_OF_CLASS_VARIANTS( MenuItemBtPairedDevice )

/* Virtual Method Table (VMT) for the class : 'Menu::ItemBtPairedDevice' */
EW_DEFINE_CLASS( MenuItemBtPairedDevice, MenuItemBase, CheckBoxButton, CheckBoxButton, 
                 CheckBoxButton, CheckBoxButton, Valid, Valid, "Menu::ItemBtPairedDevice" )
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
  MenuItemBase_OnSetEnabled,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DismissDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  MenuItemBase_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  MenuItemBase_OnEnterReleaseSlot,
EW_END_OF_CLASS( MenuItemBtPairedDevice )

/* Embedded Wizard */
