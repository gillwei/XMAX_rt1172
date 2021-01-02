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
#include "_MenuArrowScrollBar.h"
#include "_MenuBaseMenuView.h"
#include "_MenuItemBase.h"
#include "_MenuItemCheckMark.h"
#include "_MenuItemCheckbox.h"
#include "_MenuItemWrapper.h"
#include "_MenuPushButton.h"
#include "_MenuScrollbar.h"
#include "_MenuUpDownPushButtonSet.h"
#include "_MenuVerticalMenu.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsBorder.h"
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
  0x0000006E, /* ratio 76.36 % */
  0xB8001100, 0x800A8452, 0x00E80034, 0x0CA00360, 0x061F8780, 0xC0027916, 0x1522800D,
  0x20043613, 0x8D948007, 0x01861D0C, 0x0B236730, 0x6E382000, 0x2151B384, 0xDE009742,
  0xF281D464, 0x12048021, 0x69180087, 0x9B480C71, 0x5C522405, 0x4068B362, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 74 }};
static const XRect _Const0001 = {{ 18, 0 }, { 435, 74 }};
static const XColor _Const0002 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const0003 = {{ 0, 72 }, { 480, 74 }};
static const XRect _Const0004 = {{ 37, 1 }, { 417, 69 }};
static const XRect _Const0005 = {{ 37, 9 }, { 417, 43 }};
static const XRect _Const0006 = {{ 18, 0 }, { 435, 54 }};
static const XRect _Const0007 = {{ 0, 54 }, { 480, 56 }};
static const XColor _Const0008 = { 0x64, 0x64, 0x64, 0xFF };
static const XRect _Const0009 = {{ 0, 0 }, { 480, 236 }};
static const XRect _Const000A = {{ 0, 2 }, { 435, 224 }};
static const XRect _Const000B = {{ 470, 2 }, { 480, 226 }};
static const XRect _Const000C = {{ 18, 0 }, { 435, 76 }};
static const XColor _Const000D = { 0x00, 0x72, 0xFF, 0xFF };
static const XRect _Const000E = {{ 441, 5 }, { 473, 221 }};
static const XRect _Const000F = {{ 37, 1 }, { 386, 69 }};
static const XRect _Const0010 = {{ 394, 10 }, { 444, 60 }};
static const XRect _Const0011 = {{ 37, 9 }, { 367, 43 }};
static const XRect _Const0012 = {{ 371, 2 }, { 421, 52 }};
static const XStringRes _Const0013 = { _StringsDefault0, 0x0002 };
static const XRect _Const0014 = {{ 0, 0 }, { 10, 240 }};
static const XColor _Const0015 = { 0x00, 0x00, 0x00, 0xFF };
static const XPoint _Const0016 = { 5, 240 };
static const XPoint _Const0017 = { 5, 0 };
static const XRect _Const0018 = {{ 0, 50 }, { 10, 80 }};
static const XRect _Const0019 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const001A = {{ 0, 0 }, { 150, 40 }};
static const XRect _Const001B = {{ 0, 4 }, { 150, 38 }};
static const XColor _Const001C = { 0xFF, 0xFF, 0xFF, 0xCD };
static const XColor _Const001D = { 0x72, 0x71, 0x71, 0xFF };
static const XStringRes _Const001E = { _StringsDefault0, 0x000A };
static const XRect _Const001F = {{ 0, 0 }, { 150, 83 }};
static const XStringRes _Const0020 = { _StringsDefault0, 0x0029 };
static const XRect _Const0021 = {{ 0, 43 }, { 150, 83 }};
static const XStringRes _Const0022 = { _StringsDefault0, 0x0032 };
static const XRect _Const0023 = {{ 37, 1 }, { 364, 69 }};
static const XRect _Const0024 = {{ 371, 9 }, { 421, 59 }};
static const XRect _Const0025 = {{ 0, 0 }, { 32, 216 }};
static const XRect _Const0026 = {{ 0, 0 }, { 32, 32 }};
static const XRect _Const0027 = {{ 0, 184 }, { 32, 216 }};

/* Initializer for the class 'Menu::ItemBase' */
void MenuItemBase__Init( MenuItemBase _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MenuItemBase );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->HighlightRect, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ListDivider, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->FocusFrameFlashTimer, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Title, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MenuItemBase );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  _this->Super1.PassUpKey = 1;
  _this->Super1.PassDownKey = 1;
  _this->Super1.PassHomeKey = 1;
  CoreRectView__OnSetBounds( &_this->HighlightRect, _Const0001 );
  ViewsRectangle_OnSetColor( &_this->HighlightRect, _Const0002 );
  ViewsRectangle_OnSetVisible( &_this->HighlightRect, 0 );
  CoreRectView__OnSetBounds( &_this->ListDivider, _Const0003 );
  ViewsImage_OnSetAlignment( &_this->ListDivider, ViewsImageAlignmentScaleToFit );
  CoreTimer_OnSetPeriod( &_this->FocusFrameFlashTimer, 0 );
  CoreTimer_OnSetBegin( &_this->FocusFrameFlashTimer, 100 );
  CoreView_OnSetLayout((CoreView)&_this->Title, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->Title, _Const0004 );
  ViewsText_OnSetAlignment( &_this->Title, ViewsTextAlignmentAlignHorzLeft | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->Title, 0 );
  ViewsText_OnSetColor( &_this->Title, _Const0002 );
  _this->Focusable = 1;
  _this->Height = 74;
  CoreGroup__Add( _this, ((CoreView)&_this->HighlightRect ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ListDivider ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Title ), 0 );
  ViewsImage_OnSetBitmap( &_this->ListDivider, EwLoadResource( &ResourceListDivider3, 
  ResourcesBitmap ));
  _this->FocusFrameFlashTimer.OnTrigger = EwNewSlot( _this, MenuItemBase_OnFocusFrameFlashTimer );
  ViewsText_OnSetFont( &_this->Title, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Menu::ItemBase' */
void MenuItemBase__ReInit( MenuItemBase _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->HighlightRect );
  ViewsImage__ReInit( &_this->ListDivider );
  CoreTimer__ReInit( &_this->FocusFrameFlashTimer );
  ViewsText__ReInit( &_this->Title );
}

/* Finalizer method for the class 'Menu::ItemBase' */
void MenuItemBase__Done( MenuItemBase _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->HighlightRect );
  ViewsImage__Done( &_this->ListDivider );
  CoreTimer__Done( &_this->FocusFrameFlashTimer );
  ViewsText__Done( &_this->Title );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void MenuItemBase_UpdateLayout( MenuItemBase _this, XPoint aSize )
{
  CoreGroup_UpdateLayout((CoreGroup)_this, aSize );

  switch ( _this->Height )
  {
    case 56 :
    {
      CoreRectView__OnSetBounds( &_this->Title, _Const0005 );
      CoreRectView__OnSetBounds( &_this->HighlightRect, _Const0006 );
      CoreRectView__OnSetBounds( &_this->ListDivider, _Const0007 );
    }
    break;

    default : 
      ;
  }
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
    ViewsRectangle_OnSetVisible( &_this->HighlightRect, 1 );
  }
  else
    if ((( aState & CoreViewStateFocused ) == CoreViewStateFocused ))
    {
      if ( _this->Focusable )
      {
        ViewsRectangle_OnSetVisible( &_this->HighlightRect, 0 );
      }
    }
    else
    {
      ViewsRectangle_OnSetVisible( &_this->HighlightRect, 0 );
    }
}

/* 'C' function for method : 'Menu::ItemBase.OnSetEnabled()' */
void MenuItemBase_OnSetEnabled( MenuItemBase _this, XBool value )
{
  if ( _this->Super2.Enabled != value )
  {
    _this->Super2.Enabled = value;

    if ( value )
    {
      ViewsText_OnSetColor( &_this->Title, _Const0002 );
    }
    else
    {
      ViewsText_OnSetColor( &_this->Title, _Const0008 );
    }
  }
}

/* 'C' function for method : 'Menu::ItemBase.OnShortEnterKeyActivated()' */
void MenuItemBase_OnShortEnterKeyActivated( MenuItemBase _this )
{
  if ( _this->Focusable )
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

/* 'C' function for method : 'Menu::ItemBase.OnSetFocusable()' */
void MenuItemBase_OnSetFocusable( MenuItemBase _this, XBool value )
{
  if ( _this->Focusable != value )
  {
    _this->Focusable = value;
  }
}

/* Variants derived from the class : 'Menu::ItemBase' */
EW_DEFINE_CLASS_VARIANTS( MenuItemBase )
EW_END_OF_CLASS_VARIANTS( MenuItemBase )

/* Virtual Method Table (VMT) for the class : 'Menu::ItemBase' */
EW_DEFINE_CLASS( MenuItemBase, ComponentsBaseComponent, OnActivate, OnActivate, 
                 HighlightRect, HighlightRect, Height, Height, "Menu::ItemBase" )
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
  MenuItemBase_UpdateLayout,
  MenuItemBase_UpdateViewState,
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
  MenuItemBase_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
EW_END_OF_CLASS( MenuItemBase )

/* Initializer for the class 'Menu::VerticalMenu' */
void MenuVerticalMenu__Init( MenuVerticalMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MenuVerticalMenu );

  /* ... then construct all embedded objects */
  CoreVerticalList__Init( &_this->MenuList, &_this->_XObject, 0 );
  MenuScrollbar__Init( &_this->Scrollbar, &_this->_XObject, 0 );
  ViewsBorder__Init( &_this->FocusFrame, &_this->_XObject, 0 );
  MenuArrowScrollBar__Init( &_this->ArrowScrollBar, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MenuVerticalMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0009 );
  _this->Super1.PassHomeKey = 1;
  CoreRectView__OnSetBounds( &_this->MenuList, _Const000A );
  CoreVerticalList_OnSetSelectedItem( &_this->MenuList, 0 );
  CoreVerticalList_OnSetItemHeight( &_this->MenuList, 74 );
  CoreVerticalList_OnSetItemClass( &_this->MenuList, EW_CLASS( MenuItemWrapper ));
  CoreRectView__OnSetBounds( &_this->Scrollbar, _Const000B );
  CoreGroup_OnSetVisible((CoreGroup)&_this->Scrollbar, 0 );
  MenuScrollbar_OnSetPageItems( &_this->Scrollbar, 4 );
  _this->Focusable = 1;
  _this->ItemHeight = 74;
  _this->ItemNumPerPage = 3;
  CoreRectView__OnSetBounds( &_this->FocusFrame, _Const000C );
  ViewsBorder_OnSetWidth( &_this->FocusFrame, 3 );
  ViewsBorder_OnSetColor( &_this->FocusFrame, _Const000D );
  CoreRectView__OnSetBounds( &_this->ArrowScrollBar, _Const000E );
  CoreGroup_OnSetVisible((CoreGroup)&_this->ArrowScrollBar, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MenuList ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Scrollbar ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->FocusFrame ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ArrowScrollBar ), 0 );
  CoreGroup__OnSetFocus( &_this->MenuList, 0 );
  _this->MenuList.OnLoadItem = EwNewSlot( _this, MenuVerticalMenu_OnLoadItemSlot );
}

/* Re-Initializer for the class 'Menu::VerticalMenu' */
void MenuVerticalMenu__ReInit( MenuVerticalMenu _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreVerticalList__ReInit( &_this->MenuList );
  MenuScrollbar__ReInit( &_this->Scrollbar );
  ViewsBorder__ReInit( &_this->FocusFrame );
  MenuArrowScrollBar__ReInit( &_this->ArrowScrollBar );
}

/* Finalizer method for the class 'Menu::VerticalMenu' */
void MenuVerticalMenu__Done( MenuVerticalMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  CoreVerticalList__Done( &_this->MenuList );
  MenuScrollbar__Done( &_this->Scrollbar );
  ViewsBorder__Done( &_this->FocusFrame );
  MenuArrowScrollBar__Done( &_this->ArrowScrollBar );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* 'C' function for method : 'Menu::VerticalMenu.OnShortDownKeyActivated()' */
void MenuVerticalMenu_OnShortDownKeyActivated( MenuVerticalMenu _this )
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
        MenuVerticalMenu_SwitchToPageOfSelectedItem( _this );
        MenuScrollbar_OnSetViewIdx( &_this->Scrollbar, _this->MenuList.SelectedItem );
        MenuVerticalMenu_MoveFocusFrame( _this );
      }
    }
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.OnShortUpKeyActivated()' */
void MenuVerticalMenu_OnShortUpKeyActivated( MenuVerticalMenu _this )
{
  if ( CoreGroup__IsCurrentDialog( _this->Super4.Owner ))
  {
    XInt32 PrevItemIdx = _this->MenuList.SelectedItem - 1;

    if ( PrevItemIdx >= 0 )
    {
      CoreVerticalList_OnSetSelectedItem( &_this->MenuList, PrevItemIdx );
      MenuVerticalMenu_SwitchToPageOfSelectedItem( _this );
      MenuScrollbar_OnSetViewIdx( &_this->Scrollbar, _this->MenuList.SelectedItem );
      MenuVerticalMenu_MoveFocusFrame( _this );
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
      Item->Height = _this->ItemHeight;
      MenuItemWrapper_OnSetItemClass( Item, MenuBaseMenuView__LoadItemClass( OwnerMenu, 
      ItemNo ));
      MenuItemWrapper_OnSetTitle( Item, MenuBaseMenuView__LoadItemTitle( OwnerMenu, 
      ItemNo ));
      CoreGroup__OnSetEnabled( Item, MenuBaseMenuView__LoadItemEnabled( OwnerMenu, 
      ItemNo ));
      Item->OnActivate = EwNewSlot( _this, MenuVerticalMenu_OnItemActivateSlot );
      MenuItemWrapper_OnSetFocusable( Item, _this->Focusable );
    }

    if (( EW_CLASS( MenuItemCheckbox ) == Item->ItemClass ) || ( EW_CLASS( MenuItemCheckMark ) 
        == Item->ItemClass ))
    {
      MenuItemWrapper_OnSetChecked( Item, MenuBaseMenuView__LoadItemChecked( OwnerMenu, 
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

    if ( 0 == _this->NoOfItems )
    {
      ViewsBorder_OnSetVisible( &_this->FocusFrame, 0 );
    }
    else
    {
      ViewsBorder_OnSetVisible( &_this->FocusFrame, 1 );
    }

    if ( _this->ArrowScrollBarVisible && ( 0 != _this->ItemNumPerPage ))
    {
      XInt32 NoOfPages = value / _this->ItemNumPerPage;

      if ( value > ( NoOfPages * _this->ItemNumPerPage ))
      {
        NoOfPages++;
      }

      MenuArrowScrollBar_OnSetNoOfPages( &_this->ArrowScrollBar, NoOfPages );
    }

    if ( _this->MenuList.SelectedItem >= _this->MenuList.NoOfItems )
    {
      CoreVerticalList_OnSetSelectedItem( &_this->MenuList, _this->MenuList.NoOfItems 
      - 1 );
      MenuVerticalMenu_MoveFocusFrame( _this );
      MenuVerticalMenu_SwitchToPageOfSelectedItem( _this );
    }
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.InvalidateItems()' */
void MenuVerticalMenu_InvalidateItems( MenuVerticalMenu _this, XInt32 aFirstItem, 
  XInt32 aLastItem )
{
  CoreVerticalList_InvalidateItems( &_this->MenuList, aFirstItem, aLastItem );
  MenuScrollbar_OnSetViewIdx( &_this->Scrollbar, 0 );
}

/* 'C' function for method : 'Menu::VerticalMenu.OnSetItemHeight()' */
void MenuVerticalMenu_OnSetItemHeight( MenuVerticalMenu _this, XInt32 value )
{
  if ( _this->ItemHeight != value )
  {
    _this->ItemHeight = value;
    CoreVerticalList_OnSetItemHeight( &_this->MenuList, value );
    CoreRectView__OnSetBounds( &_this->FocusFrame, EwSetRectY2( _this->FocusFrame.Super1.Bounds, 
    2 + _this->ItemHeight ));
    MenuVerticalMenu_UpdateListHeight( _this );
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.MoveFocusFrame()' */
void MenuVerticalMenu_MoveFocusFrame( MenuVerticalMenu _this )
{
  XInt32 SelectedRow = _this->MenuList.SelectedItem % _this->ItemNumPerPage;
  XRect FocusFrameRect = _this->FocusFrame.Super1.Bounds;

  FocusFrameRect.Point1.Y = ( _this->ItemHeight * SelectedRow );
  FocusFrameRect.Point2.Y = ( 2 + ( _this->ItemHeight * ( SelectedRow + 1 )));
  CoreRectView__OnSetBounds( &_this->FocusFrame, FocusFrameRect );
}

/* 'C' function for method : 'Menu::VerticalMenu.OnSetItemNumPerPage()' */
void MenuVerticalMenu_OnSetItemNumPerPage( MenuVerticalMenu _this, XInt32 value )
{
  if ( _this->ItemNumPerPage != value )
  {
    _this->ItemNumPerPage = value;
    MenuVerticalMenu_UpdateListHeight( _this );
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.UpdateListHeight()' */
void MenuVerticalMenu_UpdateListHeight( MenuVerticalMenu _this )
{
  CoreRectView__OnSetBounds( &_this->MenuList, EwSetRectY2( _this->MenuList.Super2.Bounds, 
  _this->MenuList.Super2.Bounds.Point1.Y + ( _this->ItemHeight * _this->ItemNumPerPage )));
}

/* 'C' function for method : 'Menu::VerticalMenu.SwitchToPageOfSelectedItem()' */
void MenuVerticalMenu_SwitchToPageOfSelectedItem( MenuVerticalMenu _this )
{
  XInt32 CurrentPageIdx = ( -1 * _this->MenuList.ScrollOffset ) / EwGetRectH( _this->MenuList.Super2.Bounds );
  XInt32 PageIdxOfSelectedItem = _this->MenuList.SelectedItem / _this->ItemNumPerPage;

  if ( CurrentPageIdx != PageIdxOfSelectedItem )
  {
    CoreVerticalList_OnSetScrollOffset( &_this->MenuList, ( -1 * PageIdxOfSelectedItem ) 
    * EwGetRectH( _this->MenuList.Super2.Bounds ));
  }

  if ( _this->ArrowScrollBarVisible )
  {
    MenuArrowScrollBar_OnSetCurrentPageIdx( &_this->ArrowScrollBar, PageIdxOfSelectedItem );
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.OnSetArrowScrollBarVisible()' */
void MenuVerticalMenu_OnSetArrowScrollBarVisible( MenuVerticalMenu _this, XBool 
  value )
{
  if ( _this->ArrowScrollBarVisible != value )
  {
    _this->ArrowScrollBarVisible = value;
    CoreGroup_OnSetVisible((CoreGroup)&_this->ArrowScrollBar, value );
  }
}

/* Variants derived from the class : 'Menu::VerticalMenu' */
EW_DEFINE_CLASS_VARIANTS( MenuVerticalMenu )
EW_END_OF_CLASS_VARIANTS( MenuVerticalMenu )

/* Virtual Method Table (VMT) for the class : 'Menu::VerticalMenu' */
EW_DEFINE_CLASS( MenuVerticalMenu, ComponentsBaseComponent, MenuList, MenuList, 
                 MenuList, MenuList, NoOfItems, NoOfItems, "Menu::VerticalMenu" )
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
  MenuVerticalMenu_OnShortDownKeyActivated,
  MenuVerticalMenu_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
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
  CoreRectView__OnSetBounds( &_this->Super1.Title, _Const000F );
  CoreRectView__OnSetBounds( &_this->CheckBoxButton, _Const0010 );
  CoreGroup__OnSetEnabled( &_this->CheckBoxButton, 1 );
  WidgetSetToggleButton_OnSetChecked( &_this->CheckBoxButton, 0 );
  WidgetSetToggleButton_OnSetIconFrame( &_this->CheckBoxButton, 0 );
  WidgetSetToggleButton_OnSetLabel( &_this->CheckBoxButton, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CheckBoxButton ), 0 );
  WidgetSetToggleButton_OnSetAppearance( &_this->CheckBoxButton, EwGetAutoObject( 
  &UIConfigCheckBoxConfig, WidgetSetToggleButtonConfig ));
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

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void MenuItemCheckbox_UpdateLayout( MenuItemCheckbox _this, XPoint aSize )
{
  MenuItemBase_UpdateLayout((MenuItemBase)_this, aSize );

  switch ( _this->Super1.Height )
  {
    case 56 :
    {
      CoreRectView__OnSetBounds( &_this->Super1.Title, _Const0011 );
      CoreRectView__OnSetBounds( &_this->CheckBoxButton, _Const0012 );
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Menu::ItemCheckbox.OnSetEnabled()' */
void MenuItemCheckbox_OnSetEnabled( MenuItemCheckbox _this, XBool value )
{
  if ( _this->Super3.Enabled != value )
  {
    MenuItemBase_OnSetEnabled((MenuItemBase)_this, value );
    CoreGroup__OnSetEnabled( &_this->CheckBoxButton, value );
  }
}

/* 'C' function for method : 'Menu::ItemCheckbox.OnShortEnterKeyActivated()' */
void MenuItemCheckbox_OnShortEnterKeyActivated( MenuItemCheckbox _this )
{
  MenuItemBase_OnShortEnterKeyActivated((MenuItemBase)_this );
  WidgetSetToggleButton_OnSetChecked( &_this->CheckBoxButton, (XBool)!_this->CheckBoxButton.Checked );
}

/* 'C' function for method : 'Menu::ItemCheckbox.OnSetChecked()' */
void MenuItemCheckbox_OnSetChecked( MenuItemCheckbox _this, XBool value )
{
  if ( _this->Checked != value )
  {
    _this->Checked = value;
    WidgetSetToggleButton_OnSetChecked( &_this->CheckBoxButton, value );
  }
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
  MenuItemCheckbox_UpdateLayout,
  MenuItemBase_UpdateViewState,
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
  MenuItemCheckbox_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
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
  CoreRectView__OnSetBounds( _this, _Const0000 );
  _this->Title = EwShareString( EwLoadString( &_Const0013 ));
  _this->Focusable = 1;
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
    MenuItemBase ItemBase;
    _this->Super1.Enabled = value;
    view = CoreGroup__FindNextView( _this, 0, 0 );
    ItemBase = EwCastObject( view, MenuItemBase );

    if ( ItemBase != 0 )
    {
      CoreGroup__OnSetEnabled( ItemBase, value );
    }
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetItemClass()' */
void MenuItemWrapper_OnSetItemClass( MenuItemWrapper _this, XClass value )
{
  if ( _this->ItemClass != value )
  {
    MenuItemBase Item;
    _this->ItemClass = value;

    if ( CoreGroup__CountViews( _this ) > 0 )
    {
      CoreGroup__Remove( _this, CoreGroup__FindNextView( _this, 0, 0 ));
    }

    Item = EwCastObject( EwNewObjectIndirect( value, 0 ), MenuItemBase );
    Item->Height = _this->Height;
    Item->OnActivate = EwNewSlot( _this, MenuItemWrapper_OnActivateSlot );
    CoreGroup__Add( _this, ((CoreView)Item ), 0 );
  }
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
    MenuItemCheckbox CheckboxMenuItem;
    _this->Checked = value;
    view = CoreGroup__FindNextView( _this, 0, 0 );
    CheckboxMenuItem = EwCastObject( view, MenuItemCheckbox );

    if ( CheckboxMenuItem != 0 )
    {
      MenuItemCheckbox_OnSetChecked( CheckboxMenuItem, value );
    }
    else
    {
      MenuItemCheckMark CheckMarkMenuItem = EwCastObject( view, MenuItemCheckMark );

      if ( CheckMarkMenuItem != 0 )
      {
        MenuItemCheckMark_OnSetChecked( CheckMarkMenuItem, value );
      }
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
  CoreRectView__OnSetBounds( _this, _Const0014 );
  CoreRectView__OnSetBounds( &_this->Background, _Const0014 );
  ViewsRectangle_OnSetColor( &_this->Background, _Const0015 );
  CoreLineView_OnSetPoint2((CoreLineView)&_this->Track, _Const0016 );
  CoreLineView_OnSetPoint1((CoreLineView)&_this->Track, _Const0017 );
  ViewsLine_OnSetWidth( &_this->Track, 3 );
  ViewsLine_OnSetColor( &_this->Track, _Const0008 );
  CoreRectView__OnSetBounds( &_this->Bar, _Const0018 );
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
  CoreGroup_UpdateLayout,
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
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MenuBaseMenuView );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MenuBaseMenuView );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0019 );
  CoreGroup__Restack( _this, ((CoreView)&_this->Super1.BlackBG ), -1 );
}

/* Re-Initializer for the class 'Menu::BaseMenuView' */
void MenuBaseMenuView__ReInit( MenuBaseMenuView _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Menu::BaseMenuView' */
void MenuBaseMenuView__Done( MenuBaseMenuView _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
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

/* Variants derived from the class : 'Menu::BaseMenuView' */
EW_DEFINE_CLASS_VARIANTS( MenuBaseMenuView )
EW_END_OF_CLASS_VARIANTS( MenuBaseMenuView )

/* Virtual Method Table (VMT) for the class : 'Menu::BaseMenuView' */
EW_DEFINE_CLASS( MenuBaseMenuView, ComponentsBaseMainBG, _None, _None, _None, _None, 
                 _None, _None, "Menu::BaseMenuView" )
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
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
EW_END_OF_CLASS( MenuBaseMenuView )

/* Initializer for the class 'Menu::PushButton' */
void MenuPushButton__Init( MenuPushButton _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MenuPushButton );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Background, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TitleText, &_this->_XObject, 0 );
  CoreKeyPressHandler__Init( &_this->KeyHandler, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->FocusFrameFlashTimer, &_this->_XObject, 0 );
  ViewsBorder__Init( &_this->FocusBorder, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MenuPushButton );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const001A );
  CoreRectView__OnSetBounds( &_this->Background, _Const001A );
  ViewsRectangle_OnSetColor( &_this->Background, _Const0015 );
  CoreRectView__OnSetBounds( &_this->TitleText, _Const001B );
  ViewsText_OnSetString( &_this->TitleText, 0 );
  _this->KeyHandler.Filter = CoreKeyCodeOk;
  CoreTimer_OnSetPeriod( &_this->FocusFrameFlashTimer, 0 );
  CoreTimer_OnSetBegin( &_this->FocusFrameFlashTimer, 100 );
  CoreRectView__OnSetBounds( &_this->FocusBorder, _Const001A );
  ViewsBorder_OnSetWidth( &_this->FocusBorder, 3 );
  ViewsBorder_OnSetColor( &_this->FocusBorder, _Const000D );
  _this->Focusable = 1;
  CoreGroup__Add( _this, ((CoreView)&_this->Background ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TitleText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->FocusBorder ), 0 );
  ViewsText_OnSetFont( &_this->TitleText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  _this->KeyHandler.OnRelease = EwNewSlot( _this, MenuPushButton_OnEnterReleaseSlot );
  _this->FocusFrameFlashTimer.OnTrigger = EwNewSlot( _this, MenuPushButton_OnFocusFrameFlashTimer );
}

/* Re-Initializer for the class 'Menu::PushButton' */
void MenuPushButton__ReInit( MenuPushButton _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Background );
  ViewsText__ReInit( &_this->TitleText );
  CoreKeyPressHandler__ReInit( &_this->KeyHandler );
  CoreTimer__ReInit( &_this->FocusFrameFlashTimer );
  ViewsBorder__ReInit( &_this->FocusBorder );
}

/* Finalizer method for the class 'Menu::PushButton' */
void MenuPushButton__Done( MenuPushButton _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Background );
  ViewsText__Done( &_this->TitleText );
  CoreKeyPressHandler__Done( &_this->KeyHandler );
  CoreTimer__Done( &_this->FocusFrameFlashTimer );
  ViewsBorder__Done( &_this->FocusBorder );

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
void MenuPushButton_UpdateViewState( MenuPushButton _this, XSet aState )
{
  CoreGroup_UpdateViewState((CoreGroup)_this, aState );

  if ( _this->FocusFrameFlashTimer.Enabled )
  {
    ViewsRectangle_OnSetVisible( &_this->Background, 1 );
    ViewsRectangle_OnSetColor( &_this->Background, _Const001C );
  }
  else
    if ((( aState & CoreViewStateFocused ) == CoreViewStateFocused ))
    {
      ViewsRectangle_OnSetVisible( &_this->Background, 0 );

      if ( _this->Focusable )
      {
        ViewsBorder_OnSetColor( &_this->FocusBorder, _Const000D );
        ViewsBorder_OnSetWidth( &_this->FocusBorder, 3 );
      }
    }
    else
    {
      ViewsRectangle_OnSetVisible( &_this->Background, 0 );
      ViewsBorder_OnSetColor( &_this->FocusBorder, _Const001D );
      ViewsBorder_OnSetWidth( &_this->FocusBorder, 2 );
    }
}

/* 'C' function for method : 'Menu::PushButton.OnSetTitle()' */
void MenuPushButton_OnSetTitle( MenuPushButton _this, XString value )
{
  if ( EwCompString( _this->Title, value ) != 0 )
  {
    _this->Title = EwShareString( value );
    ViewsText_OnSetString( &_this->TitleText, value );
  }
}

/* 'C' function for method : 'Menu::PushButton.OnEnterReleaseSlot()' */
void MenuPushButton_OnEnterReleaseSlot( MenuPushButton _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwTrace( "%s%b", EwLoadString( &_Const001E ), _this->KeyHandler.Repetition );

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

/* 'C' function for method : 'Menu::PushButton.OnFocusFrameFlashTimer()' */
void MenuPushButton_OnFocusFrameFlashTimer( MenuPushButton _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_InvalidateViewState((CoreGroup)_this );
  EwPostSignal( _this->OnActivate, ((XObject)_this ));
}

/* Variants derived from the class : 'Menu::PushButton' */
EW_DEFINE_CLASS_VARIANTS( MenuPushButton )
EW_END_OF_CLASS_VARIANTS( MenuPushButton )

/* Virtual Method Table (VMT) for the class : 'Menu::PushButton' */
EW_DEFINE_CLASS( MenuPushButton, CoreGroup, OnActivate, OnActivate, Background, 
                 Background, Title, Focusable, "Menu::PushButton" )
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
  MenuPushButton_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
EW_END_OF_CLASS( MenuPushButton )

/* Initializer for the class 'Menu::UpDownPushButtonSet' */
void MenuUpDownPushButtonSet__Init( MenuUpDownPushButtonSet _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MenuUpDownPushButtonSet );

  /* ... then construct all embedded objects */
  MenuPushButton__Init( &_this->UpButton, &_this->_XObject, 0 );
  MenuPushButton__Init( &_this->DownButton, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MenuUpDownPushButtonSet );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const001F );
  CoreRectView__OnSetBounds( &_this->UpButton, _Const001A );
  MenuPushButton_OnSetTitle( &_this->UpButton, EwLoadString( &_Const0020 ));
  CoreRectView__OnSetBounds( &_this->DownButton, _Const0021 );
  MenuPushButton_OnSetTitle( &_this->DownButton, EwLoadString( &_Const0022 ));
  _this->UpButtonTitle = EwShareString( EwLoadString( &_Const0020 ));
  _this->DownButtonTitle = EwShareString( EwLoadString( &_Const0022 ));
  CoreGroup__Add( _this, ((CoreView)&_this->UpButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DownButton ), 0 );
  _this->UpButton.OnActivate = EwNewSlot( _this, MenuUpDownPushButtonSet_OnActivateSlot );
  _this->DownButton.OnActivate = EwNewSlot( _this, MenuUpDownPushButtonSet_OnActivateSlot );
}

/* Re-Initializer for the class 'Menu::UpDownPushButtonSet' */
void MenuUpDownPushButtonSet__ReInit( MenuUpDownPushButtonSet _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  MenuPushButton__ReInit( &_this->UpButton );
  MenuPushButton__ReInit( &_this->DownButton );
}

/* Finalizer method for the class 'Menu::UpDownPushButtonSet' */
void MenuUpDownPushButtonSet__Done( MenuUpDownPushButtonSet _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  MenuPushButton__Done( &_this->UpButton );
  MenuPushButton__Done( &_this->DownButton );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* 'C' function for method : 'Menu::UpDownPushButtonSet.OnShortDownKeyActivated()' */
void MenuUpDownPushButtonSet_OnShortDownKeyActivated( MenuUpDownPushButtonSet _this )
{
  CoreGroup__OnSetFocus( _this, ((CoreView)&_this->DownButton ));
}

/* 'C' function for method : 'Menu::UpDownPushButtonSet.OnShortUpKeyActivated()' */
void MenuUpDownPushButtonSet_OnShortUpKeyActivated( MenuUpDownPushButtonSet _this )
{
  CoreGroup__OnSetFocus( _this, ((CoreView)&_this->UpButton ));
}

/* 'C' function for method : 'Menu::UpDownPushButtonSet.OnActivateSlot()' */
void MenuUpDownPushButtonSet_OnActivateSlot( MenuUpDownPushButtonSet _this, XObject 
  sender )
{
  if (((XObject)&_this->DownButton ) == sender )
  {
    EwPostSignal( _this->OnDownButtonReleased, ((XObject)_this ));
  }
  else
    if (((XObject)&_this->UpButton ) == sender )
    {
      EwPostSignal( _this->OnUpButtonReleased, ((XObject)_this ));
    }
    else
      ;
}

/* 'C' function for method : 'Menu::UpDownPushButtonSet.OnSetUpButtonTitle()' */
void MenuUpDownPushButtonSet_OnSetUpButtonTitle( MenuUpDownPushButtonSet _this, 
  XString value )
{
  if ( EwCompString( _this->UpButtonTitle, value ) != 0 )
  {
    _this->UpButtonTitle = EwShareString( value );
    ViewsText_OnSetString( &_this->UpButton.TitleText, value );
  }
}

/* 'C' function for method : 'Menu::UpDownPushButtonSet.OnSetDownButtonTitle()' */
void MenuUpDownPushButtonSet_OnSetDownButtonTitle( MenuUpDownPushButtonSet _this, 
  XString value )
{
  if ( EwCompString( _this->DownButtonTitle, value ) != 0 )
  {
    _this->DownButtonTitle = EwShareString( value );
    ViewsText_OnSetString( &_this->DownButton.TitleText, value );
  }
}

/* Variants derived from the class : 'Menu::UpDownPushButtonSet' */
EW_DEFINE_CLASS_VARIANTS( MenuUpDownPushButtonSet )
EW_END_OF_CLASS_VARIANTS( MenuUpDownPushButtonSet )

/* Virtual Method Table (VMT) for the class : 'Menu::UpDownPushButtonSet' */
EW_DEFINE_CLASS( MenuUpDownPushButtonSet, ComponentsBaseComponent, OnUpButtonReleased, 
                 OnUpButtonReleased, UpButton, UpButton, UpButtonTitle, _None, "Menu::UpDownPushButtonSet" )
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
  MenuUpDownPushButtonSet_OnShortDownKeyActivated,
  MenuUpDownPushButtonSet_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
EW_END_OF_CLASS( MenuUpDownPushButtonSet )

/* Initializer for the class 'Menu::ItemCheckMark' */
void MenuItemCheckMark__Init( MenuItemCheckMark _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuItemBase__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MenuItemCheckMark );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->CheckMark, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MenuItemCheckMark );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Super1.Title, _Const0023 );
  CoreRectView__OnSetBounds( &_this->CheckMark, _Const0024 );
  ViewsImage_OnSetFrameNumber( &_this->CheckMark, 1 );
  ViewsImage_OnSetVisible( &_this->CheckMark, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CheckMark ), 0 );
  ViewsImage_OnSetBitmap( &_this->CheckMark, EwLoadResource( &ResourceCheckMark, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'Menu::ItemCheckMark' */
void MenuItemCheckMark__ReInit( MenuItemCheckMark _this )
{
  /* At first re-initialize the super class ... */
  MenuItemBase__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->CheckMark );
}

/* Finalizer method for the class 'Menu::ItemCheckMark' */
void MenuItemCheckMark__Done( MenuItemCheckMark _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuItemBase );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->CheckMark );

  /* Don't forget to deinitialize the super class ... */
  MenuItemBase__Done( &_this->_Super );
}

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void MenuItemCheckMark_UpdateLayout( MenuItemCheckMark _this, XPoint aSize )
{
  MenuItemBase_UpdateLayout((MenuItemBase)_this, aSize );

  switch ( _this->Super1.Height )
  {
    case 56 :
    {
      CoreRectView__OnSetBounds( &_this->Super1.Title, _Const0011 );
      CoreRectView__OnSetBounds( &_this->CheckMark, _Const0012 );
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Menu::ItemCheckMark.OnSetChecked()' */
void MenuItemCheckMark_OnSetChecked( MenuItemCheckMark _this, XBool value )
{
  if ( _this->Checked != value )
  {
    _this->Checked = value;
    ViewsImage_OnSetVisible( &_this->CheckMark, value );
  }
}

/* Variants derived from the class : 'Menu::ItemCheckMark' */
EW_DEFINE_CLASS_VARIANTS( MenuItemCheckMark )
EW_END_OF_CLASS_VARIANTS( MenuItemCheckMark )

/* Virtual Method Table (VMT) for the class : 'Menu::ItemCheckMark' */
EW_DEFINE_CLASS( MenuItemCheckMark, MenuItemBase, CheckMark, CheckMark, CheckMark, 
                 CheckMark, Checked, Checked, "Menu::ItemCheckMark" )
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
  MenuItemCheckMark_UpdateLayout,
  MenuItemBase_UpdateViewState,
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
  MenuItemBase_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
EW_END_OF_CLASS( MenuItemCheckMark )

/* Initializer for the class 'Menu::ArrowScrollBar' */
void MenuArrowScrollBar__Init( MenuArrowScrollBar _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( MenuArrowScrollBar );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->UpArrowIcon, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DownArrowIcon, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( MenuArrowScrollBar );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0025 );
  CoreRectView__OnSetBounds( &_this->UpArrowIcon, _Const0026 );
  CoreRectView__OnSetBounds( &_this->DownArrowIcon, _Const0027 );
  ViewsImage_OnSetFrameNumber( &_this->DownArrowIcon, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->UpArrowIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DownArrowIcon ), 0 );
  ViewsImage_OnSetBitmap( &_this->UpArrowIcon, EwLoadResource( &ResourcePageUpDown, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->DownArrowIcon, EwLoadResource( &ResourcePageUpDown, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'Menu::ArrowScrollBar' */
void MenuArrowScrollBar__ReInit( MenuArrowScrollBar _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->UpArrowIcon );
  ViewsImage__ReInit( &_this->DownArrowIcon );
}

/* Finalizer method for the class 'Menu::ArrowScrollBar' */
void MenuArrowScrollBar__Done( MenuArrowScrollBar _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->UpArrowIcon );
  ViewsImage__Done( &_this->DownArrowIcon );

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
void MenuArrowScrollBar_UpdateViewState( MenuArrowScrollBar _this, XSet aState )
{
  CoreGroup_UpdateViewState((CoreGroup)_this, aState );

  if ( 0 == _this->CurrentPageIdx )
  {
    ViewsImage_OnSetVisible( &_this->UpArrowIcon, 0 );
  }
  else
  {
    ViewsImage_OnSetVisible( &_this->UpArrowIcon, 1 );
  }

  if (( _this->NoOfPages - 1 ) == _this->CurrentPageIdx )
  {
    ViewsImage_OnSetVisible( &_this->DownArrowIcon, 0 );
  }
  else
  {
    ViewsImage_OnSetVisible( &_this->DownArrowIcon, 1 );
  }
}

/* 'C' function for method : 'Menu::ArrowScrollBar.OnSetCurrentPageIdx()' */
void MenuArrowScrollBar_OnSetCurrentPageIdx( MenuArrowScrollBar _this, XInt32 value )
{
  if ( _this->CurrentPageIdx != value )
  {
    _this->CurrentPageIdx = value;
    CoreGroup_InvalidateViewState((CoreGroup)_this );
  }
}

/* 'C' function for method : 'Menu::ArrowScrollBar.OnSetNoOfPages()' */
void MenuArrowScrollBar_OnSetNoOfPages( MenuArrowScrollBar _this, XInt32 value )
{
  if ( _this->NoOfPages != value )
  {
    _this->NoOfPages = value;
    CoreGroup_InvalidateViewState((CoreGroup)_this );
  }
}

/* Variants derived from the class : 'Menu::ArrowScrollBar' */
EW_DEFINE_CLASS_VARIANTS( MenuArrowScrollBar )
EW_END_OF_CLASS_VARIANTS( MenuArrowScrollBar )

/* Virtual Method Table (VMT) for the class : 'Menu::ArrowScrollBar' */
EW_DEFINE_CLASS( MenuArrowScrollBar, CoreGroup, UpArrowIcon, UpArrowIcon, UpArrowIcon, 
                 UpArrowIcon, CurrentPageIdx, CurrentPageIdx, "Menu::ArrowScrollBar" )
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
  MenuArrowScrollBar_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
EW_END_OF_CLASS( MenuArrowScrollBar )

/* Embedded Wizard */
