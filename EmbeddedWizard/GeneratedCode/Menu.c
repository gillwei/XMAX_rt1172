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
* Version  : 11.00
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
#include "_EffectsInt32Effect.h"
#include "_EffectsRectEffect.h"
#include "_MenuArrowScrollBar.h"
#include "_MenuBaseMenuView.h"
#include "_MenuItemBase.h"
#include "_MenuItemBaseValue.h"
#include "_MenuItemCheckMark.h"
#include "_MenuItemCheckbox.h"
#include "_MenuItemNotification.h"
#include "_MenuItemPoiList.h"
#include "_MenuItemTimeHourMinute.h"
#include "_MenuItemValueUnit.h"
#include "_MenuItemValueUnit2.h"
#include "_MenuItemValueUnitCheckmark.h"
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
#include "Color.h"
#include "Core.h"
#include "Effects.h"
#include "Enum.h"
#include "Fonts.h"
#include "Menu.h"
#include "Resource.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault0[] =
{
  0x00000040, /* ratio 93.75 % */
  0xB8001100, 0x800A8452, 0x00E80034, 0x0CA00360, 0x06098780, 0x20021916, 0x0037000C,
  0xF85C34C6, 0x89014010, 0xE92C004F, 0x0C209028, 0xA0752700, 0x63B1D95C, 0x00000040,
  0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 74 }};
static const XRect _Const0001 = {{ 18, 0 }, { 435, 74 }};
static const XColor _Const0002 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const0003 = {{ 0, 72 }, { 480, 74 }};
static const XRect _Const0004 = {{ 37, 1 }, { 417, 66 }};
static const XRect _Const0005 = {{ 37, 3 }, { 417, 45 }};
static const XRect _Const0006 = {{ 18, 0 }, { 435, 54 }};
static const XRect _Const0007 = {{ 0, 54 }, { 480, 56 }};
static const XRect _Const0008 = {{ 0, 0 }, { 480, 236 }};
static const XRect _Const0009 = {{ 0, 2 }, { 444, 224 }};
static const XRect _Const000A = {{ 453, 6 }, { 463, 214 }};
static const XRect _Const000B = {{ 18, 0 }, { 435, 76 }};
static const XColor _Const000C = { 0x00, 0x72, 0xFF, 0xFF };
static const XRect _Const000D = {{ 441, 5 }, { 473, 221 }};
static const XRect _Const000E = {{ 37, 1 }, { 366, 66 }};
static const XRect _Const000F = {{ 371, 11 }, { 421, 61 }};
static const XRect _Const0010 = {{ 37, 7 }, { 367, 41 }};
static const XRect _Const0011 = {{ 371, 2 }, { 421, 52 }};
static const XStringRes _Const0012 = { _StringsDefault0, 0x0002 };
static const XRect _Const0013 = {{ 0, 0 }, { 8, 208 }};
static const XPoint _Const0014 = { 4, 208 };
static const XPoint _Const0015 = { 4, 0 };
static const XColor _Const0016 = { 0x88, 0x87, 0x8C, 0xFF };
static const XRect _Const0017 = {{ 0, 0 }, { 10, 40 }};
static const XRect _Const0018 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0019 = {{ 0, 36 }, { 480, 272 }};
static const XRect _Const001A = {{ 0, 0 }, { 150, 40 }};
static const XColor _Const001B = { 0x00, 0x00, 0x00, 0x26 };
static const XRect _Const001C = {{ 0, 0 }, { 150, 36 }};
static const XColor _Const001D = { 0xFF, 0xFF, 0xFF, 0xCD };
static const XColor _Const001E = { 0x72, 0x71, 0x71, 0xFF };
static const XColor _Const001F = { 0x64, 0x64, 0x64, 0xFF };
static const XRect _Const0020 = {{ 0, 0 }, { 150, 83 }};
static const XStringRes _Const0021 = { _StringsDefault0, 0x000A };
static const XRect _Const0022 = {{ 0, 43 }, { 150, 83 }};
static const XStringRes _Const0023 = { _StringsDefault0, 0x0013 };
static const XRect _Const0024 = {{ 37, 1 }, { 364, 66 }};
static const XRect _Const0025 = {{ 371, 9 }, { 421, 59 }};
static const XRect _Const0026 = {{ 0, 0 }, { 32, 216 }};
static const XRect _Const0027 = {{ 0, 0 }, { 32, 32 }};
static const XRect _Const0028 = {{ 0, 184 }, { 32, 216 }};
static const XRect _Const0029 = {{ 37, 0 }, { 193, 67 }};
static const XRect _Const002A = {{ 384, 0 }, { 417, 51 }};
static const XRect _Const002B = {{ 290, 7 }, { 417, 43 }};
static const XRect _Const002C = {{ 384, 0 }, { 417, 67 }};
static const XRect _Const002D = {{ 10, 0 }, { 444, 74 }};
static const XRect _Const002E = {{ 68, 5 }, { 367, 35 }};
static const XRect _Const002F = {{ 68, 32 }, { 439, 62 }};
static const XRect _Const0030 = {{ 377, 5 }, { 440, 35 }};
static const XStringRes _Const0031 = { _StringsDefault0, 0x0018 };
static const XRect _Const0032 = {{ 13, 11 }, { 63, 61 }};
static const XRect _Const0033 = {{ 145, 7 }, { 300, 41 }};
static const XRect _Const0034 = {{ 306, 7 }, { 366, 41 }};
static const XRect _Const0035 = {{ 200, 0 }, { 351, 67 }};
static const XRect _Const0036 = {{ 357, 0 }, { 417, 67 }};
static const XRect _Const0037 = {{ 212, 0 }, { 286, 67 }};
static const XRect _Const0038 = {{ 326, 0 }, { 360, 67 }};
static const XRect _Const0039 = {{ 290, 0 }, { 321, 67 }};
static const XRect _Const003A = {{ 362, 0 }, { 416, 67 }};
static const XRect _Const003B = {{ 290, 0 }, { 417, 67 }};
static const XRect _Const003C = {{ 37, 1 }, { 233, 76 }};
static const XRect _Const003D = {{ 253, 18 }, { 351, 52 }};
static const XRect _Const003E = {{ 357, 18 }, { 417, 52 }};

/* Initializer for the class 'Menu::ItemBase' */
void MenuItemBase__Init( MenuItemBase _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuItemBase );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->HighlightRect, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ListDivider, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->FocusFrameFlashTimer, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Title, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuItemBase );

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
  ViewsText_OnSetEllipsis( &_this->Title, 1 );
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
  ViewsText_OnSetFont( &_this->Title, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Menu::ItemBase' */
void MenuItemBase__ReInit( MenuItemBase _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_.Super );

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
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->HighlightRect );
  ViewsImage__Done( &_this->ListDivider );
  CoreTimer__Done( &_this->FocusFrameFlashTimer );
  ViewsText__Done( &_this->Title );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_.Super );
}

/* 'C' function for method : 'Menu::ItemBase.OnSetEnabled()' */
void MenuItemBase_OnSetEnabled( MenuItemBase _this, XBool value )
{
  CoreGroup_OnSetEnabled((CoreGroup)_this, value );

  if ( value )
    ViewsText_OnSetColor( &_this->Title, ColorWHITE );
  else
    ViewsText_OnSetColor( &_this->Title, ColorGRAY_FOR_DISABLED );
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

    default :; 
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
    ViewsRectangle_OnSetVisible( &_this->HighlightRect, 1 );
  else
    if ((( aState & CoreViewStateFocused ) == CoreViewStateFocused ))
    {
      if ( _this->Focusable )
        ViewsRectangle_OnSetVisible( &_this->HighlightRect, 0 );
    }
    else
      ViewsRectangle_OnSetVisible( &_this->HighlightRect, 0 );
}

/* 'C' function for method : 'Menu::ItemBase.OnShortEnterKeyActivated()' */
void MenuItemBase_OnShortEnterKeyActivated( MenuItemBase _this )
{
  if ( _this->Focusable && CoreGroup__OnGetEnabled( _this ))
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
    ViewsText_OnSetString( &_this->Title, aTitle );
}

/* 'C' function for method : 'Menu::ItemBase.OnSetFocusable()' */
void MenuItemBase_OnSetFocusable( MenuItemBase _this, XBool value )
{
  if ( _this->Focusable != value )
    _this->Focusable = value;
}

/* 'C' function for method : 'Menu::ItemBase.OnLongEnterKeyActivated()' */
void MenuItemBase_OnLongEnterKeyActivated( MenuItemBase _this )
{
  if ( 1 == _this->Super1.KeyHandler.RepetitionCount )
    EwPostSignal( _this->OnLongEnterKeyActivate, ((XObject)_this ));
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  MenuItemBase_UpdateLayout,
  MenuItemBase_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  MenuItemBase_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( MenuItemBase )

/* Initializer for the class 'Menu::VerticalMenu' */
void MenuVerticalMenu__Init( MenuVerticalMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuVerticalMenu );

  /* ... then construct all embedded objects */
  CoreVerticalList__Init( &_this->MenuList, &_this->_.XObject, 0 );
  MenuScrollbar__Init( &_this->Scrollbar, &_this->_.XObject, 0 );
  ViewsBorder__Init( &_this->FocusFrame, &_this->_.XObject, 0 );
  MenuArrowScrollBar__Init( &_this->ArrowScrollBar, &_this->_.XObject, 0 );
  EffectsInt32Effect__Init( &_this->PageScrollEffect, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuVerticalMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0008 );
  _this->Super1.PassHomeKey = 1;
  CoreRectView__OnSetBounds( &_this->MenuList, _Const0009 );
  CoreVerticalList_OnSetSelectedItem( &_this->MenuList, 0 );
  CoreVerticalList_OnSetItemHeight( &_this->MenuList, 74 );
  CoreVerticalList_OnSetItemClass( &_this->MenuList, EW_CLASS( MenuItemWrapper ));
  CoreRectView__OnSetBounds( &_this->Scrollbar, _Const000A );
  CoreGroup__OnSetVisible( &_this->Scrollbar, 0 );
  MenuScrollbar_OnSetPageItems( &_this->Scrollbar, 3 );
  _this->Focusable = 1;
  _this->ItemHeight = 74;
  _this->ItemNumPerPage = 3;
  CoreRectView__OnSetBounds( &_this->FocusFrame, _Const000B );
  ViewsBorder_OnSetWidth( &_this->FocusFrame, 3 );
  ViewsBorder_OnSetColor( &_this->FocusFrame, _Const000C );
  ViewsBorder_OnSetVisible( &_this->FocusFrame, 0 );
  CoreRectView__OnSetBounds( &_this->ArrowScrollBar, _Const000D );
  CoreGroup__OnSetVisible( &_this->ArrowScrollBar, 0 );
  EffectsEffect_OnSetExponent((EffectsEffect)&_this->PageScrollEffect, 4.190000f );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->PageScrollEffect, EffectsTimingExp_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->PageScrollEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->PageScrollEffect, 200 );
  EffectsEffect_OnSetInitialDelay((EffectsEffect)&_this->PageScrollEffect, 50 );
  _this->SelectedItem = -1;
  CoreGroup__Add( _this, ((CoreView)&_this->MenuList ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Scrollbar ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->FocusFrame ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ArrowScrollBar ), 0 );
  CoreGroup__OnSetFocus( &_this->MenuList, 0 );
  _this->MenuList.OnLoadItem = EwNewSlot( _this, MenuVerticalMenu_OnLoadItemSlot );
  _this->PageScrollEffect.Super1.OnFinished = EwNewSlot( _this, MenuVerticalMenu_OnPageScrolledSlot );
  _this->PageScrollEffect.Outlet = EwNewRef( &_this->MenuList, CoreVerticalList_OnGetScrollOffset, 
  CoreVerticalList_OnSetScrollOffset );
}

/* Re-Initializer for the class 'Menu::VerticalMenu' */
void MenuVerticalMenu__ReInit( MenuVerticalMenu _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreVerticalList__ReInit( &_this->MenuList );
  MenuScrollbar__ReInit( &_this->Scrollbar );
  ViewsBorder__ReInit( &_this->FocusFrame );
  MenuArrowScrollBar__ReInit( &_this->ArrowScrollBar );
  EffectsInt32Effect__ReInit( &_this->PageScrollEffect );
}

/* Finalizer method for the class 'Menu::VerticalMenu' */
void MenuVerticalMenu__Done( MenuVerticalMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  CoreVerticalList__Done( &_this->MenuList );
  MenuScrollbar__Done( &_this->Scrollbar );
  ViewsBorder__Done( &_this->FocusFrame );
  MenuArrowScrollBar__Done( &_this->ArrowScrollBar );
  EffectsInt32Effect__Done( &_this->PageScrollEffect );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_.Super );
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
void MenuVerticalMenu_UpdateViewState( MenuVerticalMenu _this, XSet aState )
{
  CoreGroup_UpdateViewState((CoreGroup)_this, aState );

  if ( _this->ArrowScrollBarVisible && ( 0 != _this->ItemNumPerPage ))
  {
    XInt32 NoOfPages = _this->NoOfItems / _this->ItemNumPerPage;

    if ( _this->NoOfItems > ( NoOfPages * _this->ItemNumPerPage ))
      NoOfPages++;

    MenuArrowScrollBar_OnSetNoOfPages( &_this->ArrowScrollBar, NoOfPages );
  }

  if ( _this->ScrollbarVisible )
  {
    if ( _this->ItemNumPerPage < _this->NoOfItems )
      CoreGroup__OnSetVisible( &_this->Scrollbar, 1 );
    else
      CoreGroup__OnSetVisible( &_this->Scrollbar, 0 );
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.OnShortDownKeyActivated()' */
void MenuVerticalMenu_OnShortDownKeyActivated( MenuVerticalMenu _this )
{
  if ( CoreGroup__IsCurrentDialog( _this->Super4.Owner ))
    MenuVerticalMenu_OnSetSelectedItem( _this, _this->MenuList.SelectedItem + 1 );
}

/* 'C' function for method : 'Menu::VerticalMenu.OnShortUpKeyActivated()' */
void MenuVerticalMenu_OnShortUpKeyActivated( MenuVerticalMenu _this )
{
  if ( CoreGroup__IsCurrentDialog( _this->Super4.Owner ))
    MenuVerticalMenu_OnSetSelectedItem( _this, _this->MenuList.SelectedItem - 1 );
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
      Item->OnLongEnterKeyActivate = EwNewSlot( _this, MenuVerticalMenu_OnLongEnterKeyActivatedSlot );
      MenuItemWrapper_OnSetFocusable( Item, _this->Focusable );
      MenuItemWrapper_OnSetDDModeEnabled( Item, _this->Super1.DDModeEnabled );
    }

    if ((( EW_CLASS( MenuItemCheckbox ) == Item->ItemClass ) || ( EW_CLASS( MenuItemCheckMark ) 
        == Item->ItemClass )) || ( EW_CLASS( MenuItemValueUnitCheckmark ) == Item->ItemClass ))
    {
      MenuItemWrapper_OnSetChecked( Item, MenuBaseMenuView__LoadItemChecked( OwnerMenu, 
      ItemNo ));
      MenuItemWrapper_OnSetToggleEnabled( Item, MenuBaseMenuView__LoadItemToggle( 
      OwnerMenu, ItemNo ));
    }

    if ( EW_CLASS( MenuItemBaseValue ) == Item->ItemClass )
      MenuItemWrapper_OnSetValue( Item, MenuBaseMenuView__LoadItemBaseValue( OwnerMenu, 
      ItemNo ));
    else
      if ( EW_CLASS( MenuItemNotification ) == Item->ItemClass )
      {
        MenuItemWrapper_OnSetMessage( Item, MenuBaseMenuView__LoadItemMessage( OwnerMenu, 
        ItemNo ));
        MenuItemWrapper_OnSetReceivedTime( Item, MenuBaseMenuView__LoadItemReceivedTime( 
        OwnerMenu, ItemNo ));
        MenuItemWrapper_OnSetCategory( Item, MenuBaseMenuView__LoadItemCategory( 
        OwnerMenu, ItemNo ));
        MenuItemWrapper_OnSetUid( Item, MenuBaseMenuView__LoadItemUid( OwnerMenu, 
        ItemNo ));
      }
      else
        if ((( EW_CLASS( MenuItemValueUnitCheckmark ) == Item->ItemClass ) || ( 
            EW_CLASS( MenuItemValueUnit ) == Item->ItemClass )) || ( EW_CLASS( MenuItemValueUnit2 ) 
            == Item->ItemClass ))
        {
          MenuItemWrapper_OnSetValue( Item, MenuBaseMenuView__LoadItemValue( OwnerMenu, 
          ItemNo ));
          MenuItemWrapper_OnSetUnit( Item, MenuBaseMenuView__LoadItemUnit( OwnerMenu, 
          ItemNo ));
        }
        else
          if ( EW_CLASS( MenuItemTimeHourMinute ) == Item->ItemClass )
          {
            MenuItemWrapper_OnSetHour( Item, MenuBaseMenuView__LoadItemHour( OwnerMenu, 
            ItemNo ));
            MenuItemWrapper_OnSetMinute( Item, MenuBaseMenuView__LoadItemMinute( 
            OwnerMenu, ItemNo ));
          }
          else
            if ( EW_CLASS( MenuItemPoiList ) == Item->ItemClass )
            {
              MenuItemWrapper_OnSetPoiListItemValue( Item, MenuBaseMenuView__LoadPoiListItemValue( 
              OwnerMenu, ItemNo ));
              MenuItemWrapper_OnSetPoiListItemUnit( Item, MenuBaseMenuView__LoadPoiListItemUnit( 
              OwnerMenu, ItemNo ));
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
      MenuItem = EwCastObject( Menu, MenuItemBase );
  }

  OwnerMenu = EwCastObject( _this->Super4.Owner, MenuBaseMenuView );

  if ( OwnerMenu != 0 )
    MenuBaseMenuView__OnItemActivate( OwnerMenu, _this->MenuList.SelectedItem, MenuItem );
}

/* 'C' function for method : 'Menu::VerticalMenu.OnSetNoOfItems()' */
void MenuVerticalMenu_OnSetNoOfItems( MenuVerticalMenu _this, XInt32 value )
{
  if ( _this->NoOfItems != value )
  {
    _this->NoOfItems = value;
    CoreVerticalList_OnSetNoOfItems( &_this->MenuList, value );
    MenuScrollbar_OnSetListItems( &_this->Scrollbar, value );

    if ( 0 == value )
      ViewsBorder_OnSetVisible( &_this->FocusFrame, 0 );
    else
      ViewsBorder_OnSetVisible( &_this->FocusFrame, 1 );

    if (( 0 < _this->MenuList.NoOfItems ) && ( _this->MenuList.SelectedItem >= _this->MenuList.NoOfItems ))
    {
      CoreVerticalList_OnSetSelectedItem( &_this->MenuList, _this->MenuList.NoOfItems 
      - 1 );
      MenuVerticalMenu_MoveFocusFrame( _this );
      MenuVerticalMenu_SwitchToPageOfSelectedItem( _this );
    }

    CoreGroup_InvalidateViewState((CoreGroup)_this );
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.InvalidateItems()' */
void MenuVerticalMenu_InvalidateItems( MenuVerticalMenu _this, XInt32 aFirstItem, 
  XInt32 aLastItem )
{
  CoreVerticalList_InvalidateItems( &_this->MenuList, aFirstItem, aLastItem );
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
    MenuScrollbar_OnSetPageItems( &_this->Scrollbar, value );
    MenuVerticalMenu_UpdateListHeight( _this );
    CoreGroup_InvalidateViewState((CoreGroup)_this );
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
    ViewsBorder_OnSetVisible( &_this->FocusFrame, 0 );
    _this->PageScrollEffect.Value1 = _this->MenuList.ScrollOffset;
    _this->PageScrollEffect.Value2 = ( -1 * PageIdxOfSelectedItem ) * EwGetRectH( 
    _this->MenuList.Super2.Bounds );
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->PageScrollEffect, 1 );
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.OnSetArrowScrollBarVisible()' */
void MenuVerticalMenu_OnSetArrowScrollBarVisible( MenuVerticalMenu _this, XBool 
  value )
{
  if ( _this->ArrowScrollBarVisible != value )
  {
    _this->ArrowScrollBarVisible = value;
    CoreGroup__OnSetVisible( &_this->ArrowScrollBar, value );
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.OnPageScrolledSlot()' */
void MenuVerticalMenu_OnPageScrolledSlot( MenuVerticalMenu _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsBorder_OnSetVisible( &_this->FocusFrame, 1 );

  if ( _this->ArrowScrollBarVisible )
  {
    XInt32 PageIdxOfSelectedItem = _this->MenuList.SelectedItem / _this->ItemNumPerPage;
    MenuArrowScrollBar_OnSetCurrentPageIdx( &_this->ArrowScrollBar, PageIdxOfSelectedItem );
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.HideArrowScrollBar()' */
void MenuVerticalMenu_HideArrowScrollBar( MenuVerticalMenu _this )
{
  CoreGroup__OnSetVisible( &_this->ArrowScrollBar, 0 );
}

/* 'C' function for method : 'Menu::VerticalMenu.RestoreArrowScrollBar()' */
void MenuVerticalMenu_RestoreArrowScrollBar( MenuVerticalMenu _this )
{
  if ( _this->ArrowScrollBarVisible )
    CoreGroup__OnSetVisible( &_this->ArrowScrollBar, 1 );
}

/* 'C' function for method : 'Menu::VerticalMenu.OnSetScrollbarVisible()' */
void MenuVerticalMenu_OnSetScrollbarVisible( MenuVerticalMenu _this, XBool value )
{
  if ( _this->ScrollbarVisible != value )
  {
    _this->ScrollbarVisible = value;
    CoreGroup__OnSetVisible( &_this->Scrollbar, value );
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.OnSetFocusFrameBounds()' */
void MenuVerticalMenu_OnSetFocusFrameBounds( MenuVerticalMenu _this, XRect value )
{
  if ( EwCompRect( _this->FocusFrameBounds, value ))
  {
    _this->FocusFrameBounds = value;
    CoreRectView__OnSetBounds( &_this->FocusFrame, value );
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.OnSetSelectedItem()' */
void MenuVerticalMenu_OnSetSelectedItem( MenuVerticalMenu _this, XInt32 value )
{
  if ( _this->SelectedItem != value )
  {
    _this->SelectedItem = value;

    if (( 0 <= value ) && ( _this->MenuList.NoOfItems > value ))
    {
      CoreVerticalList_OnSetSelectedItem( &_this->MenuList, value );
      EwPostSignal( _this->OnSelectedItemChanged, ((XObject)_this ));
      MenuScrollbar_OnSetViewIdx( &_this->Scrollbar, value );
      MenuVerticalMenu_SwitchToPageOfSelectedItem( _this );
      MenuVerticalMenu_MoveFocusFrame( _this );
    }
  }
}

/* 'C' function for method : 'Menu::VerticalMenu.HideScrollbar()' */
void MenuVerticalMenu_HideScrollbar( MenuVerticalMenu _this )
{
  CoreGroup__OnSetVisible( &_this->Scrollbar, 0 );
}

/* 'C' function for method : 'Menu::VerticalMenu.RestoreScrollbar()' */
void MenuVerticalMenu_RestoreScrollbar( MenuVerticalMenu _this )
{
  if ( _this->ScrollbarVisible && ( _this->Scrollbar.PageNum > 0 ))
    CoreGroup__OnSetVisible( &_this->Scrollbar, 1 );
}

/* 'C' function for method : 'Menu::VerticalMenu.RestoreFocusFrame()' */
void MenuVerticalMenu_RestoreFocusFrame( MenuVerticalMenu _this )
{
  if ( 0 < _this->NoOfItems )
    ViewsBorder_OnSetVisible( &_this->FocusFrame, 1 );
}

/* 'C' function for method : 'Menu::VerticalMenu.OnLongEnterKeyActivatedSlot()' */
void MenuVerticalMenu_OnLongEnterKeyActivatedSlot( MenuVerticalMenu _this, XObject 
  sender )
{
  MenuItemBase MenuItem = 0;
  MenuItemWrapper WrapperItem = EwCastObject( sender, MenuItemWrapper );
  MenuBaseMenuView OwnerMenu;

  if ( WrapperItem != 0 )
  {
    CoreView Menu = CoreGroup__FindNextView( WrapperItem, 0, 0 );

    if ( Menu != 0 )
      MenuItem = EwCastObject( Menu, MenuItemBase );
  }

  OwnerMenu = EwCastObject( _this->Super4.Owner, MenuBaseMenuView );

  if ( OwnerMenu != 0 )
    MenuBaseMenuView__OnItemLongEnterKeyActivate( OwnerMenu, _this->MenuList.SelectedItem, 
    MenuItem );
}

/* Variants derived from the class : 'Menu::VerticalMenu' */
EW_DEFINE_CLASS_VARIANTS( MenuVerticalMenu )
EW_END_OF_CLASS_VARIANTS( MenuVerticalMenu )

/* Virtual Method Table (VMT) for the class : 'Menu::VerticalMenu' */
EW_DEFINE_CLASS( MenuVerticalMenu, ComponentsBaseComponent, OnSelectedItemChanged, 
                 OnSelectedItemChanged, MenuList, MenuList, NoOfItems, NoOfItems, 
                 "Menu::VerticalMenu" )
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
  MenuVerticalMenu_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( MenuVerticalMenu )

/* Initializer for the class 'Menu::ItemCheckbox' */
void MenuItemCheckbox__Init( MenuItemCheckbox _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuItemBase__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuItemCheckbox );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->CheckboxIcon, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuItemCheckbox );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Super1.Title, _Const000E );
  CoreRectView__OnSetBounds( &_this->CheckboxIcon, _Const000F );
  CoreGroup__Add( _this, ((CoreView)&_this->CheckboxIcon ), 0 );
  ViewsImage_OnSetBitmap( &_this->CheckboxIcon, EwLoadResource( &ResourceCheckboxNormal, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'Menu::ItemCheckbox' */
void MenuItemCheckbox__ReInit( MenuItemCheckbox _this )
{
  /* At first re-initialize the super class ... */
  MenuItemBase__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->CheckboxIcon );
}

/* Finalizer method for the class 'Menu::ItemCheckbox' */
void MenuItemCheckbox__Done( MenuItemCheckbox _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuItemBase );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->CheckboxIcon );

  /* Don't forget to deinitialize the super class ... */
  MenuItemBase__Done( &_this->_.Super );
}

/* 'C' function for method : 'Menu::ItemCheckbox.OnSetEnabled()' */
void MenuItemCheckbox_OnSetEnabled( MenuItemCheckbox _this, XBool value )
{
  MenuItemBase_OnSetEnabled((MenuItemBase)_this, value );

  if ( value )
    ViewsImage_OnSetBitmap( &_this->CheckboxIcon, EwLoadResource( &ResourceCheckboxNormal, 
    ResourcesBitmap ));
  else
    ViewsImage_OnSetBitmap( &_this->CheckboxIcon, EwLoadResource( &ResourceCheckboxDisable, 
    ResourcesBitmap ));
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
      CoreRectView__OnSetBounds( &_this->Super1.Title, _Const0010 );
      CoreRectView__OnSetBounds( &_this->CheckboxIcon, _Const0011 );
    }
    break;

    default :; 
  }
}

/* 'C' function for method : 'Menu::ItemCheckbox.OnShortEnterKeyActivated()' */
void MenuItemCheckbox_OnShortEnterKeyActivated( MenuItemCheckbox _this )
{
  MenuItemBase_OnShortEnterKeyActivated((MenuItemBase)_this );

  if ( _this->ToggleEnabled )
    MenuItemCheckbox_OnSetChecked( _this, (XBool)!_this->Checked );
}

/* 'C' function for method : 'Menu::ItemCheckbox.OnSetChecked()' */
void MenuItemCheckbox_OnSetChecked( MenuItemCheckbox _this, XBool value )
{
  if ( _this->Checked != value )
  {
    _this->Checked = value;

    if ( value )
      ViewsImage_OnSetFrameNumber( &_this->CheckboxIcon, 1 );
    else
      ViewsImage_OnSetFrameNumber( &_this->CheckboxIcon, 0 );
  }
}

/* Variants derived from the class : 'Menu::ItemCheckbox' */
EW_DEFINE_CLASS_VARIANTS( MenuItemCheckbox )
EW_END_OF_CLASS_VARIANTS( MenuItemCheckbox )

/* Virtual Method Table (VMT) for the class : 'Menu::ItemCheckbox' */
EW_DEFINE_CLASS( MenuItemCheckbox, MenuItemBase, CheckboxIcon, CheckboxIcon, CheckboxIcon, 
                 CheckboxIcon, ToggleEnabled, ToggleEnabled, "Menu::ItemCheckbox" )
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  MenuItemCheckbox_UpdateLayout,
  MenuItemBase_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  MenuItemBase_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( MenuItemCheckbox )

/* Initializer for the class 'Menu::ItemWrapper' */
void MenuItemWrapper__Init( MenuItemWrapper _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuItemWrapper );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuItemWrapper );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  _this->Title = EwShareString( EwLoadString( &_Const0012 ));
  _this->Focusable = 1;
  _this->Category = EnumNotificationCategoryTOTAL;
}

/* Re-Initializer for the class 'Menu::ItemWrapper' */
void MenuItemWrapper__ReInit( MenuItemWrapper _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Menu::ItemWrapper' */
void MenuItemWrapper__Done( MenuItemWrapper _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
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
      CoreGroup__OnSetEnabled( ItemBase, value );
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
      CoreGroup__Remove( _this, CoreGroup__FindNextView( _this, 0, 0 ));

    Item = EwCastObject( EwNewObjectIndirect( value, 0 ), MenuItemBase );
    Item->Height = _this->Height;
    Item->OnActivate = EwNewSlot( _this, MenuItemWrapper_OnActivateSlot );
    Item->OnLongEnterKeyActivate = EwNewSlot( _this, MenuItemWrapper_OnLongEnterKeyActivatedSlot );
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
      MenuItemBase_SetTitle( MenuItem, _this->Title );
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
      MenuItemCheckbox_OnSetChecked( CheckboxMenuItem, value );
    else
    {
      MenuItemCheckMark CheckMarkMenuItem = EwCastObject( view, MenuItemCheckMark );

      if ( CheckMarkMenuItem != 0 )
        MenuItemCheckMark_OnSetChecked( CheckMarkMenuItem, value );
    }

    if ( EW_CLASS( MenuItemValueUnitCheckmark ) == EwClassOf(((XObject)view )))
    {
      MenuItemValueUnitCheckmark MenuItem = EwCastObject( view, MenuItemValueUnitCheckmark );

      if ( MenuItem != 0 )
        MenuItemCheckMark_OnSetChecked((MenuItemCheckMark)MenuItem, value );
    }
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnLongEnterKeyActivatedSlot()' */
void MenuItemWrapper_OnLongEnterKeyActivatedSlot( MenuItemWrapper _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwPostSignal( _this->OnLongEnterKeyActivate, ((XObject)_this ));
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
      MenuItemBase_OnSetFocusable( Item, value );
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetDDModeEnabled()' */
void MenuItemWrapper_OnSetDDModeEnabled( MenuItemWrapper _this, XBool value )
{
  if ( _this->DDModeEnabled != value )
  {
    CoreView view;
    MenuItemBase Item;
    _this->DDModeEnabled = value;
    view = CoreGroup__FindNextView( _this, 0, 0 );
    Item = EwCastObject( view, MenuItemBase );

    if ( Item != 0 )
      ComponentsBaseComponent__OnSetDDModeEnabled( Item, value );
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetValue()' */
void MenuItemWrapper_OnSetValue( MenuItemWrapper _this, XString value )
{
  if ( EwCompString( _this->Value, value ) != 0 )
  {
    CoreView view;
    _this->Value = EwShareString( value );
    view = CoreGroup__FindNextView( _this, 0, 0 );

    if ( EW_CLASS( MenuItemBaseValue ) == EwClassOf(((XObject)view )))
    {
      MenuItemBaseValue MenuItem = EwCastObject( view, MenuItemBaseValue );

      if ( MenuItem != 0 )
        MenuItemBaseValue_OnSetValue( MenuItem, value );
    }
    else
      if ( EW_CLASS( MenuItemValueUnit ) == EwClassOf(((XObject)view )))
      {
        MenuItemValueUnit MenuItem = EwCastObject( view, MenuItemValueUnit );

        if ( MenuItem != 0 )
          MenuItemValueUnit_OnSetValue( MenuItem, value );
      }
      else
        if ( EW_CLASS( MenuItemValueUnit2 ) == EwClassOf(((XObject)view )))
        {
          MenuItemValueUnit2 MenuItem = EwCastObject( view, MenuItemValueUnit2 );

          if ( MenuItem != 0 )
            MenuItemValueUnit_OnSetValue((MenuItemValueUnit)MenuItem, value );
        }
        else
          if ( EW_CLASS( MenuItemValueUnitCheckmark ) == EwClassOf(((XObject)view )))
          {
            MenuItemValueUnitCheckmark MenuItem = EwCastObject( view, MenuItemValueUnitCheckmark );

            if ( MenuItem != 0 )
              MenuItemValueUnitCheckmark_OnSetValue( MenuItem, value );
          }
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetMessage()' */
void MenuItemWrapper_OnSetMessage( MenuItemWrapper _this, XString value )
{
  if ( EwCompString( _this->Message, value ) != 0 )
  {
    CoreView view;
    MenuItemNotification NotificationItem;
    _this->Message = EwShareString( value );
    view = CoreGroup__FindNextView( _this, 0, 0 );
    NotificationItem = EwCastObject( view, MenuItemNotification );

    if ( NotificationItem != 0 )
      MenuItemNotification_OnSetMessage( NotificationItem, value );
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetReceivedTime()' */
void MenuItemWrapper_OnSetReceivedTime( MenuItemWrapper _this, XString value )
{
  if ( EwCompString( _this->ReceivedTime, value ) != 0 )
  {
    CoreView view;
    MenuItemNotification NotificationItem;
    _this->ReceivedTime = EwShareString( value );
    view = CoreGroup__FindNextView( _this, 0, 0 );
    NotificationItem = EwCastObject( view, MenuItemNotification );

    if ( NotificationItem != 0 )
      MenuItemNotification_OnSetReceivedTime( NotificationItem, value );
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetCategory()' */
void MenuItemWrapper_OnSetCategory( MenuItemWrapper _this, XEnum value )
{
  if ( _this->Category != value )
  {
    CoreView view;
    MenuItemNotification NotificationItem;
    _this->Category = value;
    view = CoreGroup__FindNextView( _this, 0, 0 );
    NotificationItem = EwCastObject( view, MenuItemNotification );

    if ( NotificationItem != 0 )
      MenuItemNotification_OnSetCategory( NotificationItem, value );
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetUid()' */
void MenuItemWrapper_OnSetUid( MenuItemWrapper _this, XUInt32 value )
{
  if ( _this->Uid != value )
  {
    CoreView view;
    MenuItemNotification NotificationItem;
    _this->Uid = value;
    view = CoreGroup__FindNextView( _this, 0, 0 );
    NotificationItem = EwCastObject( view, MenuItemNotification );

    if ( NotificationItem != 0 )
      NotificationItem->Uid = value;
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetToggleEnabled()' */
void MenuItemWrapper_OnSetToggleEnabled( MenuItemWrapper _this, XBool value )
{
  if ( _this->ToggleEnabled != value )
  {
    CoreView view;
    MenuItemCheckbox CheckboxMenuItem;
    _this->ToggleEnabled = value;
    view = CoreGroup__FindNextView( _this, 0, 0 );
    CheckboxMenuItem = EwCastObject( view, MenuItemCheckbox );

    if ( CheckboxMenuItem != 0 )
      CheckboxMenuItem->ToggleEnabled = value;
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetUnit()' */
void MenuItemWrapper_OnSetUnit( MenuItemWrapper _this, XString value )
{
  if ( EwCompString( _this->Unit, value ) != 0 )
  {
    CoreView view;
    _this->Unit = EwShareString( value );
    view = CoreGroup__FindNextView( _this, 0, 0 );

    if ( EW_CLASS( MenuItemValueUnit ) == EwClassOf(((XObject)view )))
    {
      MenuItemValueUnit MenuItem = EwCastObject( view, MenuItemValueUnit );

      if ( MenuItem != 0 )
        MenuItemValueUnit_OnSetUnit( MenuItem, value );
    }
    else
      if ( EW_CLASS( MenuItemValueUnit2 ) == EwClassOf(((XObject)view )))
      {
        MenuItemValueUnit2 MenuItem = EwCastObject( view, MenuItemValueUnit2 );

        if ( MenuItem != 0 )
          MenuItemValueUnit_OnSetUnit((MenuItemValueUnit)MenuItem, value );
      }
      else
        if ( EW_CLASS( MenuItemValueUnitCheckmark ) == EwClassOf(((XObject)view )))
        {
          MenuItemValueUnitCheckmark MenuItem = EwCastObject( view, MenuItemValueUnitCheckmark );

          if ( MenuItem != 0 )
            MenuItemValueUnitCheckmark_OnSetUnit( MenuItem, value );
        }
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetHour()' */
void MenuItemWrapper_OnSetHour( MenuItemWrapper _this, XString value )
{
  if ( EwCompString( _this->Value, value ) != 0 )
  {
    CoreView view;
    _this->Value = EwShareString( value );
    view = CoreGroup__FindNextView( _this, 0, 0 );

    if ( EW_CLASS( MenuItemTimeHourMinute ) == EwClassOf(((XObject)view )))
    {
      MenuItemTimeHourMinute MenuItem = EwCastObject( view, MenuItemTimeHourMinute );

      if ( MenuItem != 0 )
        MenuItemTimeHourMinute_OnSetHour( MenuItem, value );
    }
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetMinute()' */
void MenuItemWrapper_OnSetMinute( MenuItemWrapper _this, XString value )
{
  if ( EwCompString( _this->Unit, value ) != 0 )
  {
    CoreView view;
    _this->Unit = EwShareString( value );
    view = CoreGroup__FindNextView( _this, 0, 0 );

    if ( EW_CLASS( MenuItemTimeHourMinute ) == EwClassOf(((XObject)view )))
    {
      MenuItemTimeHourMinute MenuItem = EwCastObject( view, MenuItemTimeHourMinute );

      if ( MenuItem != 0 )
        MenuItemTimeHourMinute_OnSetMinute( MenuItem, value );
    }
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetPoiListItemValue()' */
void MenuItemWrapper_OnSetPoiListItemValue( MenuItemWrapper _this, XString value )
{
  if ( EwCompString( _this->PoiListItemValue, value ) != 0 )
  {
    CoreView view;
    MenuItemPoiList PoiListItem;
    _this->PoiListItemValue = EwShareString( value );
    view = CoreGroup__FindNextView( _this, 0, 0 );
    PoiListItem = EwCastObject( view, MenuItemPoiList );

    if ( PoiListItem != 0 )
      MenuItemPoiList_OnSetValue( PoiListItem, value );
  }
}

/* 'C' function for method : 'Menu::ItemWrapper.OnSetPoiListItemUnit()' */
void MenuItemWrapper_OnSetPoiListItemUnit( MenuItemWrapper _this, XString value )
{
  if ( EwCompString( _this->PoiListItemUnit, value ) != 0 )
  {
    CoreView view;
    MenuItemPoiList PoiListItem;
    _this->PoiListItemUnit = EwShareString( value );
    view = CoreGroup__FindNextView( _this, 0, 0 );
    PoiListItem = EwCastObject( view, MenuItemPoiList );

    if ( PoiListItem != 0 )
      MenuItemPoiList_OnSetUnit( PoiListItem, value );
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateLayout,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuScrollbar );

  /* ... then construct all embedded objects */
  ViewsLine__Init( &_this->Track, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->Bar, &_this->_.XObject, 0 );
  EffectsRectEffect__Init( &_this->ScrollEffect, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuScrollbar );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0013 );
  CoreLineView_OnSetPoint2((CoreLineView)&_this->Track, _Const0014 );
  CoreLineView_OnSetPoint1((CoreLineView)&_this->Track, _Const0015 );
  ViewsLine_OnSetWidth( &_this->Track, 2 );
  ViewsLine_OnSetColor( &_this->Track, _Const0016 );
  CoreRectView__OnSetBounds( &_this->Bar, _Const0017 );
  EffectsEffect_OnSetExponent((EffectsEffect)&_this->ScrollEffect, 4.190000f );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->ScrollEffect, EffectsTimingExp_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->ScrollEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->ScrollEffect, 200 );
  CoreGroup__Add( _this, ((CoreView)&_this->Track ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Bar ), 0 );
  _this->ScrollEffect.Outlet = EwNewRef( &_this->Bar, CoreRectView_OnGetBounds, 
  CoreRectView__OnSetBounds );
}

/* Re-Initializer for the class 'Menu::Scrollbar' */
void MenuScrollbar__ReInit( MenuScrollbar _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsLine__ReInit( &_this->Track );
  ViewsRectangle__ReInit( &_this->Bar );
  EffectsRectEffect__ReInit( &_this->ScrollEffect );
}

/* Finalizer method for the class 'Menu::Scrollbar' */
void MenuScrollbar__Done( MenuScrollbar _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsLine__Done( &_this->Track );
  ViewsRectangle__Done( &_this->Bar );
  EffectsRectEffect__Done( &_this->ScrollEffect );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
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
    _this->ScrollEffect.Value1 = _this->Bar.Super1.Bounds;
    _this->ScrollEffect.Value2 = EwNewRect( _this->Bar.Super1.Bounds.Point1.X, BarTopY, 
    _this->Bar.Super1.Bounds.Point2.X, BarTopY + BarHeight );
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->ScrollEffect, 1 );
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
        _this->PageNum = _this->PageNum + 1;

      ViewsRectangle_OnSetVisible( &_this->Bar, 1 );
      ViewsLine_OnSetVisible( &_this->Track, 1 );
    }
}

/* Variants derived from the class : 'Menu::Scrollbar' */
EW_DEFINE_CLASS_VARIANTS( MenuScrollbar )
EW_END_OF_CLASS_VARIANTS( MenuScrollbar )

/* Virtual Method Table (VMT) for the class : 'Menu::Scrollbar' */
EW_DEFINE_CLASS( MenuScrollbar, CoreGroup, Track, Track, Track, Track, ViewIdx, 
                 ViewIdx, "Menu::Scrollbar" )
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
  MenuScrollbar_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuBaseMenuView );

  /* ... then construct all embedded objects */
  MenuVerticalMenu__Init( &_this->Menu, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuBaseMenuView );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0018 );
  CoreRectView__OnSetBounds( &_this->Menu, _Const0019 );
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Menu, 0 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 0 );
  MenuVerticalMenu_OnSetArrowScrollBarVisible( &_this->Menu, 0 );
  CoreGroup__Restack( _this, ((CoreView)&_this->Super1.BlackBG ), -1 );
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );
}

/* Re-Initializer for the class 'Menu::BaseMenuView' */
void MenuBaseMenuView__ReInit( MenuBaseMenuView _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  MenuVerticalMenu__ReInit( &_this->Menu );

  /* Call the user defined re-constructor of the class */
  MenuBaseMenuView_ReInit( _this );
}

/* Finalizer method for the class 'Menu::BaseMenuView' */
void MenuBaseMenuView__Done( MenuBaseMenuView _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  MenuVerticalMenu__Done( &_this->Menu );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* 'C' function for method : 'Menu::BaseMenuView.ReInit()' */
void MenuBaseMenuView_ReInit( MenuBaseMenuView _this )
{
  MenuVerticalMenu_InvalidateItems( &_this->Menu, 0, _this->Menu.NoOfItems - 1 );
}

/* super( value ); */
void MenuBaseMenuView_OnSetDDModeEnabled( MenuBaseMenuView _this, XBool value )
{
  ComponentsBaseMainBG_OnSetDDModeEnabled((ComponentsBaseMainBG)_this, value );
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Menu, value );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemClass()' */
XClass MenuBaseMenuView_LoadItemClass( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemClass()' */
XClass MenuBaseMenuView__LoadItemClass( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_.VMT->LoadItemClass((MenuBaseMenuView)_this
  , aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemTitle()' */
XString MenuBaseMenuView_LoadItemTitle( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemTitle()' */
XString MenuBaseMenuView__LoadItemTitle( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_.VMT->LoadItemTitle((MenuBaseMenuView)_this
  , aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.OnItemActivate()' */
void MenuBaseMenuView_OnItemActivate( MenuBaseMenuView _this, XInt32 aItemNo, MenuItemBase 
  aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aMenuItem );
  EW_UNUSED_ARG( aItemNo );
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.OnItemActivate()' */
void MenuBaseMenuView__OnItemActivate( void* _this, XInt32 aItemNo, MenuItemBase 
  aMenuItem )
{
  ((MenuBaseMenuView)_this)->_.VMT->OnItemActivate((MenuBaseMenuView)_this, aItemNo
  , aMenuItem );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemChecked()' */
XBool MenuBaseMenuView_LoadItemChecked( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemChecked()' */
XBool MenuBaseMenuView__LoadItemChecked( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_.VMT->LoadItemChecked((MenuBaseMenuView)_this
  , aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemEnabled()' */
XBool MenuBaseMenuView_LoadItemEnabled( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return 1;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemEnabled()' */
XBool MenuBaseMenuView__LoadItemEnabled( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_.VMT->LoadItemEnabled((MenuBaseMenuView)_this
  , aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemBaseValue()' */
XString MenuBaseMenuView_LoadItemBaseValue( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemBaseValue()' */
XString MenuBaseMenuView__LoadItemBaseValue( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_.VMT->LoadItemBaseValue((MenuBaseMenuView)_this
  , aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemMessage()' */
XString MenuBaseMenuView_LoadItemMessage( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemMessage()' */
XString MenuBaseMenuView__LoadItemMessage( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_.VMT->LoadItemMessage((MenuBaseMenuView)_this
  , aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemReceivedTime()' */
XString MenuBaseMenuView_LoadItemReceivedTime( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemReceivedTime()' */
XString MenuBaseMenuView__LoadItemReceivedTime( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_.VMT->LoadItemReceivedTime((MenuBaseMenuView)_this
  , aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemCategory()' */
XEnum MenuBaseMenuView_LoadItemCategory( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EnumNotificationCategoryMESSAGE;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemCategory()' */
XEnum MenuBaseMenuView__LoadItemCategory( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_.VMT->LoadItemCategory((MenuBaseMenuView)_this
  , aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemUid()' */
XUInt32 MenuBaseMenuView_LoadItemUid( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemUid()' */
XUInt32 MenuBaseMenuView__LoadItemUid( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_.VMT->LoadItemUid((MenuBaseMenuView)_this, 
  aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemToggle()' */
XBool MenuBaseMenuView_LoadItemToggle( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return 1;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemToggle()' */
XBool MenuBaseMenuView__LoadItemToggle( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_.VMT->LoadItemToggle((MenuBaseMenuView)_this
  , aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemUnit()' */
XString MenuBaseMenuView_LoadItemUnit( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemUnit()' */
XString MenuBaseMenuView__LoadItemUnit( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_.VMT->LoadItemUnit((MenuBaseMenuView)_this, 
  aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemValue()' */
XString MenuBaseMenuView_LoadItemValue( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemValue()' */
XString MenuBaseMenuView__LoadItemValue( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_.VMT->LoadItemValue((MenuBaseMenuView)_this
  , aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.OnItemLongEnterKeyActivate()' */
void MenuBaseMenuView_OnItemLongEnterKeyActivate( MenuBaseMenuView _this, XInt32 
  aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aMenuItem );
  EW_UNUSED_ARG( aItemNo );
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.OnItemLongEnterKeyActivate()' */
void MenuBaseMenuView__OnItemLongEnterKeyActivate( void* _this, XInt32 aItemNo, 
  MenuItemBase aMenuItem )
{
  ((MenuBaseMenuView)_this)->_.VMT->OnItemLongEnterKeyActivate((MenuBaseMenuView)_this
  , aItemNo, aMenuItem );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemHour()' */
XString MenuBaseMenuView_LoadItemHour( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemHour()' */
XString MenuBaseMenuView__LoadItemHour( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_.VMT->LoadItemHour((MenuBaseMenuView)_this, 
  aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadItemMinute()' */
XString MenuBaseMenuView_LoadItemMinute( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadItemMinute()' */
XString MenuBaseMenuView__LoadItemMinute( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_.VMT->LoadItemMinute((MenuBaseMenuView)_this
  , aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadPoiListItemValue()' */
XString MenuBaseMenuView_LoadPoiListItemValue( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadPoiListItemValue()' */
XString MenuBaseMenuView__LoadPoiListItemValue( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_.VMT->LoadPoiListItemValue((MenuBaseMenuView)_this
  , aItemNo );
}

/* 'C' function for method : 'Menu::BaseMenuView.LoadPoiListItemUnit()' */
XString MenuBaseMenuView_LoadPoiListItemUnit( MenuBaseMenuView _this, XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return 0;
}

/* Wrapper function for the virtual method : 'Menu::BaseMenuView.LoadPoiListItemUnit()' */
XString MenuBaseMenuView__LoadPoiListItemUnit( void* _this, XInt32 aItemNo )
{
  return ((MenuBaseMenuView)_this)->_.VMT->LoadPoiListItemUnit((MenuBaseMenuView)_this
  , aItemNo );
}

/* Variants derived from the class : 'Menu::BaseMenuView' */
EW_DEFINE_CLASS_VARIANTS( MenuBaseMenuView )
EW_END_OF_CLASS_VARIANTS( MenuBaseMenuView )

/* Virtual Method Table (VMT) for the class : 'Menu::BaseMenuView' */
EW_DEFINE_CLASS( MenuBaseMenuView, ComponentsBaseMainBG, Menu, Menu, Menu, Menu, 
                 _.VMT, _.VMT, "Menu::BaseMenuView" )
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
  CoreGroup_GetViewAtIndex,
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
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  MenuBaseMenuView_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemBaseValue,
  MenuBaseMenuView_LoadItemMessage,
  MenuBaseMenuView_LoadItemReceivedTime,
  MenuBaseMenuView_LoadItemCategory,
  MenuBaseMenuView_LoadItemUid,
  MenuBaseMenuView_LoadItemToggle,
  MenuBaseMenuView_LoadItemUnit,
  MenuBaseMenuView_LoadItemValue,
  MenuBaseMenuView_OnItemLongEnterKeyActivate,
  MenuBaseMenuView_LoadItemHour,
  MenuBaseMenuView_LoadItemMinute,
  MenuBaseMenuView_LoadPoiListItemValue,
  MenuBaseMenuView_LoadPoiListItemUnit,
EW_END_OF_CLASS( MenuBaseMenuView )

/* Initializer for the class 'Menu::PushButton' */
void MenuPushButton__Init( MenuPushButton _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuPushButton );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Background, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->TitleText, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->FocusFrameFlashTimer, &_this->_.XObject, 0 );
  ViewsBorder__Init( &_this->FocusBorder, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuPushButton );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const001A );
  _this->Super1.PassUpKey = 1;
  _this->Super1.PassDownKey = 1;
  _this->Super1.PassHomeKey = 1;
  CoreView_OnSetLayout((CoreView)&_this->Background, CoreLayoutResizeHorz | CoreLayoutResizeVert );
  CoreRectView__OnSetBounds( &_this->Background, _Const001A );
  ViewsRectangle_OnSetColor( &_this->Background, _Const001B );
  CoreView_OnSetLayout((CoreView)&_this->TitleText, CoreLayoutResizeHorz | CoreLayoutResizeVert );
  CoreRectView__OnSetBounds( &_this->TitleText, _Const001C );
  ViewsText_OnSetString( &_this->TitleText, 0 );
  CoreTimer_OnSetPeriod( &_this->FocusFrameFlashTimer, 0 );
  CoreTimer_OnSetBegin( &_this->FocusFrameFlashTimer, 100 );
  CoreView_OnSetLayout((CoreView)&_this->FocusBorder, CoreLayoutResizeHorz | CoreLayoutResizeVert );
  CoreRectView__OnSetBounds( &_this->FocusBorder, _Const001A );
  ViewsBorder_OnSetWidth( &_this->FocusBorder, 2 );
  ViewsBorder_OnSetColor( &_this->FocusBorder, _Const000C );
  _this->ButtonEnabled = 1;
  CoreGroup__Add( _this, ((CoreView)&_this->Background ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TitleText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->FocusBorder ), 0 );
  ViewsText_OnSetFont( &_this->TitleText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  _this->FocusFrameFlashTimer.OnTrigger = EwNewSlot( _this, MenuPushButton_OnFocusFrameFlashTimer );
}

/* Re-Initializer for the class 'Menu::PushButton' */
void MenuPushButton__ReInit( MenuPushButton _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Background );
  ViewsText__ReInit( &_this->TitleText );
  CoreTimer__ReInit( &_this->FocusFrameFlashTimer );
  ViewsBorder__ReInit( &_this->FocusBorder );
}

/* Finalizer method for the class 'Menu::PushButton' */
void MenuPushButton__Done( MenuPushButton _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Background );
  ViewsText__Done( &_this->TitleText );
  CoreTimer__Done( &_this->FocusFrameFlashTimer );
  ViewsBorder__Done( &_this->FocusBorder );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_.Super );
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
    ViewsRectangle_OnSetColor( &_this->Background, _Const001D );
  else
    if ((( aState & CoreViewStateFocused ) == CoreViewStateFocused ))
    {
      ViewsRectangle_OnSetColor( &_this->Background, _Const001B );
      ViewsBorder_OnSetColor( &_this->FocusBorder, _Const000C );
      ViewsBorder_OnSetWidth( &_this->FocusBorder, 3 );
    }
    else
    {
      ViewsRectangle_OnSetColor( &_this->Background, _Const001B );
      ViewsBorder_OnSetColor( &_this->FocusBorder, _Const001E );
      ViewsBorder_OnSetWidth( &_this->FocusBorder, 2 );
    }
}

/* 'C' function for method : 'Menu::PushButton.OnShortEnterKeyActivated()' */
void MenuPushButton_OnShortEnterKeyActivated( MenuPushButton _this )
{
  if ((( 0 == _this->Super1.KeyHandler.Repetition ) && _this->ButtonEnabled ) && 
      !ComponentsBaseComponent_IsDDModeEffected((ComponentsBaseComponent)_this ))
  {
    CoreGroup_InvalidateViewState((CoreGroup)_this );

    if ( _this->FocusFrameFlashTimer.Enabled )
    {
      EwPostSignal( _this->OnActivate, ((XObject)_this ));
      CoreTimer_OnSetEnabled( &_this->FocusFrameFlashTimer, 0 );
    }

    _this->Super1.KeyHandler.Enabled = 0;
    CoreTimer_OnSetEnabled( &_this->FocusFrameFlashTimer, 1 );
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

/* 'C' function for method : 'Menu::PushButton.OnFocusFrameFlashTimer()' */
void MenuPushButton_OnFocusFrameFlashTimer( MenuPushButton _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_InvalidateViewState((CoreGroup)_this );
  EwPostSignal( _this->OnActivate, ((XObject)_this ));
  _this->Super1.KeyHandler.Enabled = 1;
}

/* 'C' function for method : 'Menu::PushButton.OnSetButtonEnabled()' */
void MenuPushButton_OnSetButtonEnabled( MenuPushButton _this, XBool value )
{
  if ( _this->ButtonEnabled != value )
  {
    _this->ButtonEnabled = value;

    if ( value )
      ViewsText_OnSetColor( &_this->TitleText, _Const0002 );
    else
      ViewsText_OnSetColor( &_this->TitleText, _Const001F );
  }
}

/* Variants derived from the class : 'Menu::PushButton' */
EW_DEFINE_CLASS_VARIANTS( MenuPushButton )
EW_END_OF_CLASS_VARIANTS( MenuPushButton )

/* Virtual Method Table (VMT) for the class : 'Menu::PushButton' */
EW_DEFINE_CLASS( MenuPushButton, ComponentsBaseComponent, OnActivate, OnActivate, 
                 Background, Background, Title, ButtonEnabled, "Menu::PushButton" )
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
  MenuPushButton_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  ComponentsBaseComponent_OnShortDownKeyActivated,
  ComponentsBaseComponent_OnShortUpKeyActivated,
  MenuPushButton_OnShortEnterKeyActivated,
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( MenuPushButton )

/* Initializer for the class 'Menu::UpDownPushButtonSet' */
void MenuUpDownPushButtonSet__Init( MenuUpDownPushButtonSet _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuUpDownPushButtonSet );

  /* ... then construct all embedded objects */
  MenuPushButton__Init( &_this->UpButton, &_this->_.XObject, 0 );
  MenuPushButton__Init( &_this->DownButton, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuUpDownPushButtonSet );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0020 );
  CoreView_OnSetLayout((CoreView)&_this->UpButton, CoreLayoutAlignToLeft | CoreLayoutAlignToTop 
  | CoreLayoutResizeHorz );
  CoreRectView__OnSetBounds( &_this->UpButton, _Const001A );
  _this->UpButton.Super1.PassMagicKey = 1;
  MenuPushButton_OnSetTitle( &_this->UpButton, EwLoadString( &_Const0021 ));
  CoreView_OnSetLayout((CoreView)&_this->DownButton, CoreLayoutAlignToBottom | CoreLayoutResizeHorz );
  CoreRectView__OnSetBounds( &_this->DownButton, _Const0022 );
  _this->DownButton.Super1.PassMagicKey = 1;
  MenuPushButton_OnSetTitle( &_this->DownButton, EwLoadString( &_Const0023 ));
  _this->UpButtonTitle = EwShareString( EwGetVariantOfString( &StringsGEN_CANCEL ));
  _this->DownButtonTitle = EwShareString( EwGetVariantOfString( &StringsGEN_OK ));
  _this->DownButtonEnabled = 1;
  CoreGroup__Add( _this, ((CoreView)&_this->UpButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DownButton ), 0 );
  _this->UpButton.OnActivate = EwNewSlot( _this, MenuUpDownPushButtonSet_OnActivateSlot );
  _this->DownButton.OnActivate = EwNewSlot( _this, MenuUpDownPushButtonSet_OnActivateSlot );
}

/* Re-Initializer for the class 'Menu::UpDownPushButtonSet' */
void MenuUpDownPushButtonSet__ReInit( MenuUpDownPushButtonSet _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  MenuPushButton__ReInit( &_this->UpButton );
  MenuPushButton__ReInit( &_this->DownButton );
}

/* Finalizer method for the class 'Menu::UpDownPushButtonSet' */
void MenuUpDownPushButtonSet__Done( MenuUpDownPushButtonSet _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  MenuPushButton__Done( &_this->UpButton );
  MenuPushButton__Done( &_this->DownButton );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_.Super );
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

/* 'C' function for method : 'Menu::UpDownPushButtonSet.OnSetDDModeEnabled()' */
void MenuUpDownPushButtonSet_OnSetDDModeEnabled( MenuUpDownPushButtonSet _this, 
  XBool value )
{
  if ( _this->Super1.DDModeEnabled != value )
  {
    _this->Super1.DDModeEnabled = value;
    ComponentsBaseComponent__OnSetDDModeEnabled( &_this->UpButton, value );
    ComponentsBaseComponent__OnSetDDModeEnabled( &_this->DownButton, value );
  }
}

/* 'C' function for method : 'Menu::UpDownPushButtonSet.OnActivateSlot()' */
void MenuUpDownPushButtonSet_OnActivateSlot( MenuUpDownPushButtonSet _this, XObject 
  sender )
{
  if (((XObject)&_this->DownButton ) == sender )
    EwPostSignal( _this->OnDownButtonActivated, ((XObject)_this ));
  else
    if (((XObject)&_this->UpButton ) == sender )
      EwPostSignal( _this->OnUpButtonActivated, ((XObject)_this ));
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

/* 'C' function for method : 'Menu::UpDownPushButtonSet.OnSetDownButtonEnabled()' */
void MenuUpDownPushButtonSet_OnSetDownButtonEnabled( MenuUpDownPushButtonSet _this, 
  XBool value )
{
  if ( _this->DownButtonEnabled != value )
  {
    _this->DownButtonEnabled = value;
    MenuPushButton_OnSetButtonEnabled( &_this->DownButton, value );
  }
}

/* Variants derived from the class : 'Menu::UpDownPushButtonSet' */
EW_DEFINE_CLASS_VARIANTS( MenuUpDownPushButtonSet )
EW_END_OF_CLASS_VARIANTS( MenuUpDownPushButtonSet )

/* Virtual Method Table (VMT) for the class : 'Menu::UpDownPushButtonSet' */
EW_DEFINE_CLASS( MenuUpDownPushButtonSet, ComponentsBaseComponent, OnUpButtonActivated, 
                 OnUpButtonActivated, UpButton, UpButton, UpButtonTitle, DownButtonEnabled, 
                 "Menu::UpDownPushButtonSet" )
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
  CoreGroup_GetViewAtIndex,
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
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  MenuUpDownPushButtonSet_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( MenuUpDownPushButtonSet )

/* Initializer for the class 'Menu::ItemCheckMark' */
void MenuItemCheckMark__Init( MenuItemCheckMark _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuItemBase__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuItemCheckMark );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->CheckMark, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuItemCheckMark );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Super1.Title, _Const0024 );
  CoreRectView__OnSetBounds( &_this->CheckMark, _Const0025 );
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
  MenuItemBase__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->CheckMark );
}

/* Finalizer method for the class 'Menu::ItemCheckMark' */
void MenuItemCheckMark__Done( MenuItemCheckMark _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuItemBase );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->CheckMark );

  /* Don't forget to deinitialize the super class ... */
  MenuItemBase__Done( &_this->_.Super );
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
      CoreRectView__OnSetBounds( &_this->Super1.Title, _Const0010 );
      CoreRectView__OnSetBounds( &_this->CheckMark, _Const0011 );
    }
    break;

    default :; 
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  MenuItemCheckMark_UpdateLayout,
  MenuItemBase_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  MenuItemBase_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( MenuItemCheckMark )

/* Initializer for the class 'Menu::ArrowScrollBar' */
void MenuArrowScrollBar__Init( MenuArrowScrollBar _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuArrowScrollBar );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->UpArrowIcon, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->DownArrowIcon, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuArrowScrollBar );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0026 );
  CoreRectView__OnSetBounds( &_this->UpArrowIcon, _Const0027 );
  CoreRectView__OnSetBounds( &_this->DownArrowIcon, _Const0028 );
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
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->UpArrowIcon );
  ViewsImage__ReInit( &_this->DownArrowIcon );
}

/* Finalizer method for the class 'Menu::ArrowScrollBar' */
void MenuArrowScrollBar__Done( MenuArrowScrollBar _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->UpArrowIcon );
  ViewsImage__Done( &_this->DownArrowIcon );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
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

  if ( 0 == _this->NoOfPages )
  {
    ViewsImage_OnSetVisible( &_this->UpArrowIcon, 0 );
    ViewsImage_OnSetVisible( &_this->DownArrowIcon, 0 );
  }
  else
  {
    if ( 0 == _this->CurrentPageIdx )
      ViewsImage_OnSetVisible( &_this->UpArrowIcon, 0 );
    else
      ViewsImage_OnSetVisible( &_this->UpArrowIcon, 1 );

    if (( _this->NoOfPages - 1 ) == _this->CurrentPageIdx )
      ViewsImage_OnSetVisible( &_this->DownArrowIcon, 0 );
    else
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateLayout,
  MenuArrowScrollBar_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
EW_END_OF_CLASS( MenuArrowScrollBar )

/* Initializer for the class 'Menu::ItemBaseValue' */
void MenuItemBaseValue__Init( MenuItemBaseValue _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuItemBase__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuItemBaseValue );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->ValueText, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuItemBaseValue );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Super1.Title, _Const0029 );
  CoreRectView__OnSetBounds( &_this->ValueText, _Const002A );
  ViewsText_OnSetAlignment( &_this->ValueText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ValueText, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ValueText ), 0 );
  ViewsText_OnSetFont( &_this->ValueText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Menu::ItemBaseValue' */
void MenuItemBaseValue__ReInit( MenuItemBaseValue _this )
{
  /* At first re-initialize the super class ... */
  MenuItemBase__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->ValueText );
}

/* Finalizer method for the class 'Menu::ItemBaseValue' */
void MenuItemBaseValue__Done( MenuItemBaseValue _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuItemBase );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->ValueText );

  /* Don't forget to deinitialize the super class ... */
  MenuItemBase__Done( &_this->_.Super );
}

/* 'C' function for method : 'Menu::ItemBaseValue.OnSetEnabled()' */
void MenuItemBaseValue_OnSetEnabled( MenuItemBaseValue _this, XBool value )
{
  if ( _this->Super3.Enabled != value )
  {
    MenuItemBase_OnSetEnabled((MenuItemBase)_this, value );

    if ( value )
      ViewsText_OnSetColor( &_this->ValueText, _Const0002 );
    else
      ViewsText_OnSetColor( &_this->ValueText, _Const001F );
  }
}

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void MenuItemBaseValue_UpdateLayout( MenuItemBaseValue _this, XPoint aSize )
{
  MenuItemBase_UpdateLayout((MenuItemBase)_this, aSize );

  switch ( _this->Super1.Height )
  {
    case 56 :
      CoreRectView__OnSetBounds( &_this->ValueText, _Const002B );
    break;

    case 74 :
    {
      CoreRectView__OnSetBounds( &_this->Super1.Title, _Const0029 );
      CoreRectView__OnSetBounds( &_this->ValueText, _Const002C );
    }
    break;

    default :; 
  }
}

/* 'C' function for method : 'Menu::ItemBaseValue.OnSetValue()' */
void MenuItemBaseValue_OnSetValue( MenuItemBaseValue _this, XString value )
{
  if ( EwCompString( _this->Value, value ) != 0 )
  {
    _this->Value = EwShareString( value );
    ViewsText_OnSetString( &_this->ValueText, value );
  }
}

/* Variants derived from the class : 'Menu::ItemBaseValue' */
EW_DEFINE_CLASS_VARIANTS( MenuItemBaseValue )
EW_END_OF_CLASS_VARIANTS( MenuItemBaseValue )

/* Virtual Method Table (VMT) for the class : 'Menu::ItemBaseValue' */
EW_DEFINE_CLASS( MenuItemBaseValue, MenuItemBase, ValueText, ValueText, ValueText, 
                 ValueText, Value, _.VMT, "Menu::ItemBaseValue" )
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
  MenuItemBaseValue_OnSetEnabled,
  CoreGroup_OnSetOpacity,
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  MenuItemBaseValue_UpdateLayout,
  MenuItemBase_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  MenuItemBase_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( MenuItemBaseValue )

/* Initializer for the class 'Menu::ItemNotification' */
void MenuItemNotification__Init( MenuItemNotification _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuItemBase__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuItemNotification );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->MessageText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->ReceivedTimeText, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->CategoryIcon, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuItemNotification );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Super1.HighlightRect, _Const002D );
  ViewsRectangle_OnSetVisible( &_this->Super1.HighlightRect, 1 );
  CoreRectView__OnSetBounds( &_this->Super1.Title, _Const002E );
  CoreView_OnSetLayout((CoreView)&_this->MessageText, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->MessageText, _Const002F );
  ViewsText_OnSetEllipsis( &_this->MessageText, 1 );
  ViewsText_OnSetAlignment( &_this->MessageText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->MessageText, 0 );
  ViewsText_OnSetColor( &_this->MessageText, _Const0002 );
  CoreView_OnSetLayout((CoreView)&_this->ReceivedTimeText, CoreLayoutAlignToLeft 
  | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->ReceivedTimeText, _Const0030 );
  ViewsText_OnSetAlignment( &_this->ReceivedTimeText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ReceivedTimeText, EwLoadString( &_Const0031 ));
  ViewsText_OnSetColor( &_this->ReceivedTimeText, _Const0002 );
  _this->Category = EnumNotificationCategoryTOTAL;
  CoreRectView__OnSetBounds( &_this->CategoryIcon, _Const0032 );
  ViewsImage_OnSetVisible( &_this->CategoryIcon, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MessageText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ReceivedTimeText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CategoryIcon ), 0 );
  ViewsText_OnSetFont( &_this->Super1.Title, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->MessageText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->ReceivedTimeText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->CategoryIcon, EwLoadResource( &ResourceNotificationCategory, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'Menu::ItemNotification' */
void MenuItemNotification__ReInit( MenuItemNotification _this )
{
  /* At first re-initialize the super class ... */
  MenuItemBase__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->MessageText );
  ViewsText__ReInit( &_this->ReceivedTimeText );
  ViewsImage__ReInit( &_this->CategoryIcon );
}

/* Finalizer method for the class 'Menu::ItemNotification' */
void MenuItemNotification__Done( MenuItemNotification _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuItemBase );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->MessageText );
  ViewsText__Done( &_this->ReceivedTimeText );
  ViewsImage__Done( &_this->CategoryIcon );

  /* Don't forget to deinitialize the super class ... */
  MenuItemBase__Done( &_this->_.Super );
}

/* 'C' function for method : 'Menu::ItemNotification.OnSetMessage()' */
void MenuItemNotification_OnSetMessage( MenuItemNotification _this, XString value )
{
  if ( EwCompString( _this->Message, value ) != 0 )
  {
    _this->Message = EwShareString( value );
    ViewsText_OnSetString( &_this->MessageText, value );
  }
}

/* 'C' function for method : 'Menu::ItemNotification.OnSetReceivedTime()' */
void MenuItemNotification_OnSetReceivedTime( MenuItemNotification _this, XString 
  value )
{
  if ( EwCompString( _this->ReceivedTime, value ) != 0 )
  {
    _this->ReceivedTime = EwShareString( value );
    ViewsText_OnSetString( &_this->ReceivedTimeText, value );
  }
}

/* 'C' function for method : 'Menu::ItemNotification.OnSetCategory()' */
void MenuItemNotification_OnSetCategory( MenuItemNotification _this, XEnum value )
{
  if ( _this->Category != value )
  {
    _this->Category = value;

    if ( EnumNotificationCategoryMESSAGE == value )
    {
      ViewsImage_OnSetFrameNumber( &_this->CategoryIcon, 0 );
      ViewsImage_OnSetVisible( &_this->CategoryIcon, 1 );
    }
    else
      if ( EnumNotificationCategoryMISSED_CALL == value )
      {
        ViewsImage_OnSetFrameNumber( &_this->CategoryIcon, 1 );
        ViewsImage_OnSetVisible( &_this->CategoryIcon, 1 );
      }
      else
        ViewsImage_OnSetVisible( &_this->CategoryIcon, 0 );
  }
}

/* Variants derived from the class : 'Menu::ItemNotification' */
EW_DEFINE_CLASS_VARIANTS( MenuItemNotification )
EW_END_OF_CLASS_VARIANTS( MenuItemNotification )

/* Virtual Method Table (VMT) for the class : 'Menu::ItemNotification' */
EW_DEFINE_CLASS( MenuItemNotification, MenuItemBase, MessageText, MessageText, MessageText, 
                 MessageText, Message, Uid, "Menu::ItemNotification" )
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  MenuItemBase_UpdateLayout,
  MenuItemBase_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  MenuItemBase_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( MenuItemNotification )

/* Initializer for the class 'Menu::ItemValueUnitCheckmark' */
void MenuItemValueUnitCheckmark__Init( MenuItemValueUnitCheckmark _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuItemCheckMark__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuItemValueUnitCheckmark );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->ValueText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->UnitText, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuItemValueUnitCheckmark );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->ValueText, _Const0033 );
  ViewsText_OnSetAlignment( &_this->ValueText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ValueText, 0 );
  CoreRectView__OnSetBounds( &_this->UnitText, _Const0034 );
  ViewsText_OnSetAlignment( &_this->UnitText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->UnitText, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ValueText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UnitText ), 0 );
  ViewsText_OnSetFont( &_this->ValueText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->UnitText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Menu::ItemValueUnitCheckmark' */
void MenuItemValueUnitCheckmark__ReInit( MenuItemValueUnitCheckmark _this )
{
  /* At first re-initialize the super class ... */
  MenuItemCheckMark__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->ValueText );
  ViewsText__ReInit( &_this->UnitText );
}

/* Finalizer method for the class 'Menu::ItemValueUnitCheckmark' */
void MenuItemValueUnitCheckmark__Done( MenuItemValueUnitCheckmark _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuItemCheckMark );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->ValueText );
  ViewsText__Done( &_this->UnitText );

  /* Don't forget to deinitialize the super class ... */
  MenuItemCheckMark__Done( &_this->_.Super );
}

/* 'C' function for method : 'Menu::ItemValueUnitCheckmark.OnSetEnabled()' */
void MenuItemValueUnitCheckmark_OnSetEnabled( MenuItemValueUnitCheckmark _this, 
  XBool value )
{
  MenuItemBase_OnSetEnabled((MenuItemBase)_this, value );

  if ( value )
  {
    ViewsText_OnSetColor( &_this->ValueText, ColorWHITE );
    ViewsText_OnSetColor( &_this->UnitText, ColorWHITE );
    ViewsImage_OnSetFrameNumber( &_this->Super1.CheckMark, 1 );
  }
  else
  {
    ViewsText_OnSetColor( &_this->ValueText, ColorGRAY_FOR_DISABLED );
    ViewsText_OnSetColor( &_this->UnitText, ColorGRAY_FOR_DISABLED );
    ViewsImage_OnSetFrameNumber( &_this->Super1.CheckMark, 0 );
  }
}

/* 'C' function for method : 'Menu::ItemValueUnitCheckmark.OnSetValue()' */
void MenuItemValueUnitCheckmark_OnSetValue( MenuItemValueUnitCheckmark _this, XString 
  value )
{
  if ( EwCompString( _this->Value, value ) != 0 )
  {
    _this->Value = EwShareString( value );
    ViewsText_OnSetString( &_this->ValueText, value );
  }
}

/* 'C' function for method : 'Menu::ItemValueUnitCheckmark.OnSetUnit()' */
void MenuItemValueUnitCheckmark_OnSetUnit( MenuItemValueUnitCheckmark _this, XString 
  value )
{
  if ( EwCompString( _this->Unit, value ) != 0 )
  {
    _this->Unit = EwShareString( value );
    ViewsText_OnSetString( &_this->UnitText, value );
  }
}

/* Variants derived from the class : 'Menu::ItemValueUnitCheckmark' */
EW_DEFINE_CLASS_VARIANTS( MenuItemValueUnitCheckmark )
EW_END_OF_CLASS_VARIANTS( MenuItemValueUnitCheckmark )

/* Virtual Method Table (VMT) for the class : 'Menu::ItemValueUnitCheckmark' */
EW_DEFINE_CLASS( MenuItemValueUnitCheckmark, MenuItemCheckMark, ValueText, ValueText, 
                 ValueText, ValueText, Value, _.VMT, "Menu::ItemValueUnitCheckmark" )
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
  MenuItemValueUnitCheckmark_OnSetEnabled,
  CoreGroup_OnSetOpacity,
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  MenuItemCheckMark_UpdateLayout,
  MenuItemBase_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  MenuItemBase_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( MenuItemValueUnitCheckmark )

/* Initializer for the class 'Menu::ItemValueUnit' */
void MenuItemValueUnit__Init( MenuItemValueUnit _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuItemBase__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuItemValueUnit );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->ValueText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->UnitText, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuItemValueUnit );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->ValueText, _Const0035 );
  ViewsText_OnSetAlignment( &_this->ValueText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ValueText, 0 );
  CoreRectView__OnSetBounds( &_this->UnitText, _Const0036 );
  ViewsText_OnSetAlignment( &_this->UnitText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->UnitText, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ValueText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UnitText ), 0 );
  ViewsText_OnSetFont( &_this->ValueText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->UnitText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Menu::ItemValueUnit' */
void MenuItemValueUnit__ReInit( MenuItemValueUnit _this )
{
  /* At first re-initialize the super class ... */
  MenuItemBase__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->ValueText );
  ViewsText__ReInit( &_this->UnitText );
}

/* Finalizer method for the class 'Menu::ItemValueUnit' */
void MenuItemValueUnit__Done( MenuItemValueUnit _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuItemBase );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->ValueText );
  ViewsText__Done( &_this->UnitText );

  /* Don't forget to deinitialize the super class ... */
  MenuItemBase__Done( &_this->_.Super );
}

/* 'C' function for method : 'Menu::ItemValueUnit.OnSetEnabled()' */
void MenuItemValueUnit_OnSetEnabled( MenuItemValueUnit _this, XBool value )
{
  MenuItemBase_OnSetEnabled((MenuItemBase)_this, value );

  if ( value )
  {
    ViewsText_OnSetColor( &_this->ValueText, ColorWHITE );
    ViewsText_OnSetColor( &_this->UnitText, ColorWHITE );
  }
  else
  {
    ViewsText_OnSetColor( &_this->ValueText, ColorGRAY_FOR_DISABLED );
    ViewsText_OnSetColor( &_this->UnitText, ColorGRAY_FOR_DISABLED );
  }
}

/* 'C' function for method : 'Menu::ItemValueUnit.OnSetValue()' */
void MenuItemValueUnit_OnSetValue( MenuItemValueUnit _this, XString value )
{
  if ( EwCompString( _this->Value, value ) != 0 )
  {
    _this->Value = EwShareString( value );
    ViewsText_OnSetString( &_this->ValueText, value );
  }
}

/* 'C' function for method : 'Menu::ItemValueUnit.OnSetUnit()' */
void MenuItemValueUnit_OnSetUnit( MenuItemValueUnit _this, XString value )
{
  if ( EwCompString( _this->Unit, value ) != 0 )
  {
    _this->Unit = EwShareString( value );
    ViewsText_OnSetString( &_this->UnitText, value );
  }
}

/* Variants derived from the class : 'Menu::ItemValueUnit' */
EW_DEFINE_CLASS_VARIANTS( MenuItemValueUnit )
EW_END_OF_CLASS_VARIANTS( MenuItemValueUnit )

/* Virtual Method Table (VMT) for the class : 'Menu::ItemValueUnit' */
EW_DEFINE_CLASS( MenuItemValueUnit, MenuItemBase, ValueText, ValueText, ValueText, 
                 ValueText, Value, _.VMT, "Menu::ItemValueUnit" )
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
  MenuItemValueUnit_OnSetEnabled,
  CoreGroup_OnSetOpacity,
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  MenuItemBase_UpdateLayout,
  MenuItemBase_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  MenuItemBase_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( MenuItemValueUnit )

/* Initializer for the class 'Menu::ItemTimeHourMinute' */
void MenuItemTimeHourMinute__Init( MenuItemTimeHourMinute _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuItemBase__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuItemTimeHourMinute );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->HourValueText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->MinuteValueText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->HourText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->MinuteText, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuItemTimeHourMinute );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->HourValueText, _Const0037 );
  ViewsText_OnSetAlignment( &_this->HourValueText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->HourValueText, 0 );
  CoreRectView__OnSetBounds( &_this->MinuteValueText, _Const0038 );
  ViewsText_OnSetAlignment( &_this->MinuteValueText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->MinuteValueText, 0 );
  CoreRectView__OnSetBounds( &_this->HourText, _Const0039 );
  ViewsText_OnSetAlignment( &_this->HourText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->HourText, EwLoadString( &StringsGEN_HOUR_ABBREVIATION ));
  CoreRectView__OnSetBounds( &_this->MinuteText, _Const003A );
  ViewsText_OnSetAlignment( &_this->MinuteText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->MinuteText, EwLoadString( &StringsGEN_MINUTE_ABBREVIATION ));
  CoreGroup__Add( _this, ((CoreView)&_this->HourValueText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MinuteValueText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->HourText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MinuteText ), 0 );
  ViewsText_OnSetFont( &_this->HourValueText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->MinuteValueText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->HourText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->MinuteText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Menu::ItemTimeHourMinute' */
void MenuItemTimeHourMinute__ReInit( MenuItemTimeHourMinute _this )
{
  /* At first re-initialize the super class ... */
  MenuItemBase__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->HourValueText );
  ViewsText__ReInit( &_this->MinuteValueText );
  ViewsText__ReInit( &_this->HourText );
  ViewsText__ReInit( &_this->MinuteText );
}

/* Finalizer method for the class 'Menu::ItemTimeHourMinute' */
void MenuItemTimeHourMinute__Done( MenuItemTimeHourMinute _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuItemBase );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->HourValueText );
  ViewsText__Done( &_this->MinuteValueText );
  ViewsText__Done( &_this->HourText );
  ViewsText__Done( &_this->MinuteText );

  /* Don't forget to deinitialize the super class ... */
  MenuItemBase__Done( &_this->_.Super );
}

/* 'C' function for method : 'Menu::ItemTimeHourMinute.OnSetHour()' */
void MenuItemTimeHourMinute_OnSetHour( MenuItemTimeHourMinute _this, XString value )
{
  if ( EwCompString( _this->Hour, value ) != 0 )
  {
    _this->Hour = EwShareString( value );
    ViewsText_OnSetString( &_this->HourValueText, value );
  }
}

/* 'C' function for method : 'Menu::ItemTimeHourMinute.OnSetMinute()' */
void MenuItemTimeHourMinute_OnSetMinute( MenuItemTimeHourMinute _this, XString value )
{
  if ( EwCompString( _this->Minute, value ) != 0 )
  {
    _this->Minute = EwShareString( value );
    ViewsText_OnSetString( &_this->MinuteValueText, value );
  }
}

/* Variants derived from the class : 'Menu::ItemTimeHourMinute' */
EW_DEFINE_CLASS_VARIANTS( MenuItemTimeHourMinute )
EW_END_OF_CLASS_VARIANTS( MenuItemTimeHourMinute )

/* Virtual Method Table (VMT) for the class : 'Menu::ItemTimeHourMinute' */
EW_DEFINE_CLASS( MenuItemTimeHourMinute, MenuItemBase, HourValueText, HourValueText, 
                 HourValueText, HourValueText, Hour, _.VMT, "Menu::ItemTimeHourMinute" )
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  MenuItemBase_UpdateLayout,
  MenuItemBase_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  MenuItemBase_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( MenuItemTimeHourMinute )

/* Initializer for the class 'Menu::ItemValueUnit2' */
void MenuItemValueUnit2__Init( MenuItemValueUnit2 _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuItemValueUnit__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuItemValueUnit2 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuItemValueUnit2 );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Super1.ValueText, _Const0037 );
  CoreRectView__OnSetBounds( &_this->Super1.UnitText, _Const003B );
}

/* Re-Initializer for the class 'Menu::ItemValueUnit2' */
void MenuItemValueUnit2__ReInit( MenuItemValueUnit2 _this )
{
  /* At first re-initialize the super class ... */
  MenuItemValueUnit__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Menu::ItemValueUnit2' */
void MenuItemValueUnit2__Done( MenuItemValueUnit2 _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuItemValueUnit );

  /* Don't forget to deinitialize the super class ... */
  MenuItemValueUnit__Done( &_this->_.Super );
}

/* Variants derived from the class : 'Menu::ItemValueUnit2' */
EW_DEFINE_CLASS_VARIANTS( MenuItemValueUnit2 )
EW_END_OF_CLASS_VARIANTS( MenuItemValueUnit2 )

/* Virtual Method Table (VMT) for the class : 'Menu::ItemValueUnit2' */
EW_DEFINE_CLASS( MenuItemValueUnit2, MenuItemValueUnit, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, "Menu::ItemValueUnit2" )
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
  MenuItemValueUnit_OnSetEnabled,
  CoreGroup_OnSetOpacity,
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  MenuItemBase_UpdateLayout,
  MenuItemBase_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  MenuItemBase_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( MenuItemValueUnit2 )

/* Initializer for the class 'Menu::ItemPoiList' */
void MenuItemPoiList__Init( MenuItemPoiList _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuItemBase__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( MenuItemPoiList );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->ValueText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->UnitText, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( MenuItemPoiList );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Super1.Title, _Const003C );
  ViewsText_OnSetEllipsis( &_this->Super1.Title, 1 );
  ViewsText_OnSetWrapText( &_this->Super1.Title, 1 );
  ViewsText_OnSetAlignment( &_this->Super1.Title, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->Super1.Title, 0 );
  CoreRectView__OnSetBounds( &_this->ValueText, _Const003D );
  ViewsText_OnSetString( &_this->ValueText, 0 );
  CoreRectView__OnSetBounds( &_this->UnitText, _Const003E );
  ViewsText_OnSetString( &_this->UnitText, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ValueText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UnitText ), 0 );
  ViewsText_OnSetFont( &_this->ValueText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->UnitText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Menu::ItemPoiList' */
void MenuItemPoiList__ReInit( MenuItemPoiList _this )
{
  /* At first re-initialize the super class ... */
  MenuItemBase__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->ValueText );
  ViewsText__ReInit( &_this->UnitText );
}

/* Finalizer method for the class 'Menu::ItemPoiList' */
void MenuItemPoiList__Done( MenuItemPoiList _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( MenuItemBase );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->ValueText );
  ViewsText__Done( &_this->UnitText );

  /* Don't forget to deinitialize the super class ... */
  MenuItemBase__Done( &_this->_.Super );
}

/* 'C' function for method : 'Menu::ItemPoiList.OnSetValue()' */
void MenuItemPoiList_OnSetValue( MenuItemPoiList _this, XString value )
{
  if ( EwCompString( _this->Value, value ) != 0 )
  {
    _this->Value = EwShareString( value );
    ViewsText_OnSetString( &_this->ValueText, _this->Value );
  }
}

/* 'C' function for method : 'Menu::ItemPoiList.OnSetUnit()' */
void MenuItemPoiList_OnSetUnit( MenuItemPoiList _this, XString value )
{
  if ( EwCompString( _this->Unit, value ) != 0 )
  {
    _this->Unit = EwShareString( value );
    ViewsText_OnSetString( &_this->UnitText, _this->Unit );
  }
}

/* Variants derived from the class : 'Menu::ItemPoiList' */
EW_DEFINE_CLASS_VARIANTS( MenuItemPoiList )
EW_END_OF_CLASS_VARIANTS( MenuItemPoiList )

/* Virtual Method Table (VMT) for the class : 'Menu::ItemPoiList' */
EW_DEFINE_CLASS( MenuItemPoiList, MenuItemBase, ValueText, ValueText, ValueText, 
                 ValueText, Value, _.VMT, "Menu::ItemPoiList" )
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
  CoreGroup_OnSetVisible,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  MenuItemBase_UpdateLayout,
  MenuItemBase_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
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
  MenuItemBase_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( MenuItemPoiList )

/* Embedded Wizard */
