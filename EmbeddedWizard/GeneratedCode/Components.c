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
#include "_ComponentsBaseComponent.h"
#include "_ComponentsBaseMainBG.h"
#include "_ComponentsDisclaimerView.h"
#include "_ComponentsPushButton.h"
#include "_ComponentsStatusBar.h"
#include "_CoreGroup.h"
#include "_CoreKeyPressHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_EffectsSlideTransition.h"
#include "_EffectsTransition.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "_WidgetSetPushButton.h"
#include "_WidgetSetPushButtonConfig.h"
#include "Components.h"
#include "Core.h"
#include "DeviceInterface.h"
#include "Effect.h"
#include "Fonts.h"
#include "Resource.h"
#include "UIConfig.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x000001EA, /* ratio 56.33 % */
  0xB8002300, 0x0009E452, 0x00960037, 0x0F200328, 0xE4002800, 0x8730042C, 0x00298022,
  0x037800D8, 0x8F800E80, 0x3C160610, 0x43A27098, 0x02331B24, 0x25517320, 0x271F8F47,
  0x50883488, 0x52874321, 0x18646A26, 0x8C4322C6, 0x047E5F1A, 0x11A44AC0, 0xA8D33D00,
  0x2531D104, 0x1B483853, 0xD3DA6002, 0x088647A3, 0x88E52A3D, 0x001DE990, 0xDD280068,
  0xD8A23539, 0x9E116795, 0x65263B29, 0x992C951D, 0xF158644A, 0x4C8F46AD, 0xCB457695,
  0xA65869B3, 0xAD32251C, 0x56E250C8, 0xE62B6F00, 0xB106A925, 0xCA2E8759, 0xB5F95106,
  0x00C543A7, 0x3CCD72DA, 0xAAD9AB31, 0x94930113, 0x5EA5967B, 0x8A996B00, 0xCD74CA91,
  0x4F508644, 0xF1CA96A7, 0x139360AD, 0x1844F731, 0xB49B4017, 0x95EF4568, 0xCB27B1C8,
  0xF6734CC8, 0xB6B0EDED, 0x115FD159, 0xC2700616, 0xBBDFD322, 0x18D4F71D, 0x910263F9,
  0x85B6DB93, 0x02A3F4DD, 0x4AA25791, 0xA87B2844, 0x000080FB, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XStringRes _Const0000 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0001 = { _StringsDefault0, 0x0013 };
static const XStringRes _Const0002 = { _StringsDefault0, 0x0023 };
static const XRect _Const0003 = {{ 0, 0 }, { 480, 272 }};
static const XColor _Const0004 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0005 = {{ 30, 30 }, { 440, 200 }};
static const XStringRes _Const0006 = { _StringsDefault0, 0x0036 };
static const XRect _Const0007 = {{ 150, 200 }, { 330, 260 }};
static const XStringRes _Const0008 = { _StringsDefault0, 0x00E2 };
static const XRect _Const0009 = {{ 0, 0 }, { 480, 32 }};
static const XColor _Const000A = { 0xED, 0x96, 0x2B, 0xFF };
static const XRect _Const000B = {{ 174, 0 }, { 204, 30 }};
static const XRect _Const000C = {{ 221, 0 }, { 431, 30 }};
static const XStringRes _Const000D = { _StringsDefault0, 0x00EB };
static const XRect _Const000E = {{ 50, 0 }, { 420, 30 }};
static const XRect _Const000F = {{ 0, 30 }, { 480, 32 }};
static const XRect _Const0010 = {{ 2, 0 }, { 80, 30 }};
static const XColor _Const0011 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const0012 = {{ 0, 182 }, { 480, 272 }};
static const XRect _Const0013 = {{ 0, 32 }, { 480, 182 }};

/* Initializer for the class 'Components::BaseComponent' */
void ComponentsBaseComponent__Init( ComponentsBaseComponent _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( ComponentsBaseComponent );

  /* ... then construct all embedded objects */
  CoreKeyPressHandler__Init( &_this->KeyHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ComponentsBaseComponent );

  /* ... and initialize objects, variables, properties, etc. */
  _this->KeyHandler.OnRelease = EwNewSlot( _this, ComponentsBaseComponent_OnKeyReleaseSlot );
  _this->KeyHandler.OnPress = EwNewSlot( _this, ComponentsBaseComponent_OnKeyPressSlot );
  _this->KeyHandler.OnHold = EwNewSlot( _this, ComponentsBaseComponent_OnKeyHoldSlot );
}

/* Re-Initializer for the class 'Components::BaseComponent' */
void ComponentsBaseComponent__ReInit( ComponentsBaseComponent _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreKeyPressHandler__ReInit( &_this->KeyHandler );
}

/* Finalizer method for the class 'Components::BaseComponent' */
void ComponentsBaseComponent__Done( ComponentsBaseComponent _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  CoreKeyPressHandler__Done( &_this->KeyHandler );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* 'C' function for method : 'Components::BaseComponent.OnKeyPressSlot()' */
void ComponentsBaseComponent_OnKeyPressSlot( ComponentsBaseComponent _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwTrace( "%s%e", EwLoadString( &_Const0000 ), _this->KeyHandler.Code );

  switch ( _this->KeyHandler.Code )
  {
    case CoreKeyCodeDown :
      ;
    break;

    case CoreKeyCodeUp :
      ;
    break;

    case CoreKeyCodeOk :
      ;
    break;

    case CoreKeyCodeHome :
      ;
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Components::BaseComponent.OnKeyHoldSlot()' */
void ComponentsBaseComponent_OnKeyHoldSlot( ComponentsBaseComponent _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwTrace( "%s%e", EwLoadString( &_Const0001 ), _this->KeyHandler.Code );

  if ( 1 == _this->KeyHandler.RepetitionCount )
  {
    EwSignal( EwNewSlot( _this, ComponentsBaseComponent__OnLongKeyPressed ), ((XObject)&_this->KeyHandler ));
  }
}

/* 'C' function for method : 'Components::BaseComponent.OnKeyReleaseSlot()' */
void ComponentsBaseComponent_OnKeyReleaseSlot( ComponentsBaseComponent _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwTrace( "%s%e", EwLoadString( &_Const0002 ), _this->KeyHandler.Code );

  if ( !_this->KeyHandler.Repetition )
  {
    switch ( _this->KeyHandler.Code )
    {
      case CoreKeyCodeDown :
        ComponentsBaseComponent__OnShortDownKeyPressed( _this );
      break;

      case CoreKeyCodeUp :
        ComponentsBaseComponent__OnShortUpKeyPressed( _this );
      break;

      case CoreKeyCodeOk :
        ComponentsBaseComponent__OnShortEnterKeyPressed( _this );
      break;

      case CoreKeyCodeHome :
        ComponentsBaseComponent_OnShortHomeKeyPressed( _this );
      break;

      default : 
        ;
    }
  }
}

/* 'C' function for method : 'Components::BaseComponent.OnLongKeyPressed()' */
void ComponentsBaseComponent_OnLongKeyPressed( ComponentsBaseComponent _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( sender );
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnLongKeyPressed()' */
void ComponentsBaseComponent__OnLongKeyPressed( void* _this, XObject sender )
{
  ((ComponentsBaseComponent)_this)->_VMT->OnLongKeyPressed((ComponentsBaseComponent)_this
  , sender );
}

/* 'C' function for method : 'Components::BaseComponent.OnShortDownKeyPressed()' */
void ComponentsBaseComponent_OnShortDownKeyPressed( ComponentsBaseComponent _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnShortDownKeyPressed()' */
void ComponentsBaseComponent__OnShortDownKeyPressed( void* _this )
{
  ((ComponentsBaseComponent)_this)->_VMT->OnShortDownKeyPressed((ComponentsBaseComponent)_this );
}

/* 'C' function for method : 'Components::BaseComponent.OnShortUpKeyPressed()' */
void ComponentsBaseComponent_OnShortUpKeyPressed( ComponentsBaseComponent _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnShortUpKeyPressed()' */
void ComponentsBaseComponent__OnShortUpKeyPressed( void* _this )
{
  ((ComponentsBaseComponent)_this)->_VMT->OnShortUpKeyPressed((ComponentsBaseComponent)_this );
}

/* 'C' function for method : 'Components::BaseComponent.OnShortEnterKeyPressed()' */
void ComponentsBaseComponent_OnShortEnterKeyPressed( ComponentsBaseComponent _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnShortEnterKeyPressed()' */
void ComponentsBaseComponent__OnShortEnterKeyPressed( void* _this )
{
  ((ComponentsBaseComponent)_this)->_VMT->OnShortEnterKeyPressed((ComponentsBaseComponent)_this );
}

/* 'C' function for method : 'Components::BaseComponent.OnSlideEffectCompletedSlot()' */
void ComponentsBaseComponent_OnSlideEffectCompletedSlot( ComponentsBaseComponent _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->IsSlideEffectPresenting = 0;
}

/* 'C' function for method : 'Components::BaseComponent.SlideInDialog()' */
void ComponentsBaseComponent_SlideInDialog( ComponentsBaseComponent _this, CoreGroup 
  aView )
{
  if ((( aView != 0 ) && CoreGroup__IsCurrentDialog( _this )) && ( 0 == _this->IsSlideEffectPresenting ))
  {
    _this->IsSlideEffectPresenting = 1;
    CoreGroup_PresentDialog((CoreGroup)_this, aView, ((EffectsTransition)EwGetAutoObject( 
    &EffectLeftSlideTransition, EffectsSlideTransition )), 0, 0, 0, 0, 0, EwNewSlot( 
    _this, ComponentsBaseComponent_OnSlideEffectCompletedSlot ), EwNullSlot, 0 );
  }
}

/* 'C' function for method : 'Components::BaseComponent.SlideOutDialog()' */
void ComponentsBaseComponent_SlideOutDialog( ComponentsBaseComponent _this, CoreGroup 
  aView )
{
  if (( aView != 0 ) && ( 0 == _this->IsSlideEffectPresenting ))
  {
    _this->IsSlideEffectPresenting = 1;
    CoreGroup__DismissDialog( _this->Super3.Owner, ((CoreGroup)_this ), ((EffectsTransition)EwGetAutoObject( 
    &EffectRightSlideTransition, EffectsSlideTransition )), 0, 0, EwNewSlot( _this, 
    ComponentsBaseComponent_OnSlideEffectCompletedSlot ), EwNullSlot, 0 );
  }
}

/* 'C' function for method : 'Components::BaseComponent.OnShortHomeKeyPressed()' */
void ComponentsBaseComponent_OnShortHomeKeyPressed( ComponentsBaseComponent _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Variants derived from the class : 'Components::BaseComponent' */
EW_DEFINE_CLASS_VARIANTS( ComponentsBaseComponent )
EW_END_OF_CLASS_VARIANTS( ComponentsBaseComponent )

/* Virtual Method Table (VMT) for the class : 'Components::BaseComponent' */
EW_DEFINE_CLASS( ComponentsBaseComponent, CoreGroup, PassKeyHold, PassKeyHold, KeyHandler, 
                 KeyHandler, IsSlideEffectPresenting, IsSlideEffectPresenting, "Components::BaseComponent" )
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
EW_END_OF_CLASS( ComponentsBaseComponent )

/* Initializer for the class 'Components::DisclaimerView' */
void ComponentsDisclaimerView__Init( ComponentsDisclaimerView _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( ComponentsDisclaimerView );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );
  WidgetSetPushButton__Init( &_this->PushButton, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->Rectangle1, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->IconWarning, &_this->_XObject, 0 );
  ViewsText__Init( &_this->WarningText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ComponentsDisclaimerView );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0003 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0003 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0004 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0005 );
  ViewsText_OnSetWrapText( &_this->Text, 1 );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const0006 ));
  CoreRectView__OnSetBounds( &_this->PushButton, _Const0007 );
  WidgetSetPushButton_OnSetLabel( &_this->PushButton, EwLoadString( &_Const0008 ));
  CoreRectView__OnSetBounds( &_this->Rectangle1, _Const0009 );
  ViewsRectangle_OnSetColor( &_this->Rectangle1, _Const000A );
  CoreRectView__OnSetBounds( &_this->IconWarning, _Const000B );
  ViewsImage_OnSetAlignment( &_this->IconWarning, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter | ViewsImageAlignmentScaleToFit );
  ViewsImage_OnSetVisible( &_this->IconWarning, 1 );
  CoreRectView__OnSetBounds( &_this->WarningText, _Const000C );
  ViewsText_OnSetAlignment( &_this->WarningText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->WarningText, EwLoadString( &_Const000D ));
  ViewsText_OnSetColor( &_this->WarningText, _Const0004 );
  ViewsText_OnSetVisible( &_this->WarningText, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Text ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->PushButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Rectangle1 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->IconWarning ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->WarningText ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &FontsFontNotoSansCjkJp32, 
  ResourcesFont ));
  _this->PushButton.OnActivate = EwNewSlot( _this, ComponentsDisclaimerView_OnAcceptedSlot );
  WidgetSetPushButton_OnSetAppearance( &_this->PushButton, EwGetAutoObject( &UIConfigPushButtonConfig, 
  WidgetSetPushButtonConfig ));
  ViewsImage_OnSetBitmap( &_this->IconWarning, EwLoadResource( &ResourceIconWarning, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->WarningText, EwLoadResource( &FontsFontNotoSansCjkJp32, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Components::DisclaimerView' */
void ComponentsDisclaimerView__ReInit( ComponentsDisclaimerView _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsText__ReInit( &_this->Text );
  WidgetSetPushButton__ReInit( &_this->PushButton );
  ViewsRectangle__ReInit( &_this->Rectangle1 );
  ViewsImage__ReInit( &_this->IconWarning );
  ViewsText__ReInit( &_this->WarningText );
}

/* Finalizer method for the class 'Components::DisclaimerView' */
void ComponentsDisclaimerView__Done( ComponentsDisclaimerView _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsText__Done( &_this->Text );
  WidgetSetPushButton__Done( &_this->PushButton );
  ViewsRectangle__Done( &_this->Rectangle1 );
  ViewsImage__Done( &_this->IconWarning );
  ViewsText__Done( &_this->WarningText );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* 'C' function for method : 'Components::DisclaimerView.OnAcceptedSlot()' */
void ComponentsDisclaimerView_OnAcceptedSlot( ComponentsDisclaimerView _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwSignal( _this->OnYesClicked, ((XObject)_this ));
}

/* Variants derived from the class : 'Components::DisclaimerView' */
EW_DEFINE_CLASS_VARIANTS( ComponentsDisclaimerView )
EW_END_OF_CLASS_VARIANTS( ComponentsDisclaimerView )

/* Virtual Method Table (VMT) for the class : 'Components::DisclaimerView' */
EW_DEFINE_CLASS( ComponentsDisclaimerView, ComponentsBaseComponent, OnYesClicked, 
                 OnYesClicked, Rectangle, Rectangle, _None, _None, "Components::DisclaimerView" )
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
EW_END_OF_CLASS( ComponentsDisclaimerView )

/* Initializer for the class 'Components::StatusBar' */
void ComponentsStatusBar__Init( ComponentsStatusBar _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( ComponentsStatusBar );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Background, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TitleText, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Divider, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->IconWarning, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TimeText, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->GetRtcTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ComponentsStatusBar );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0009 );
  CoreRectView__OnSetBounds( &_this->Background, _Const0009 );
  ViewsRectangle_OnSetColor( &_this->Background, _Const0004 );
  CoreRectView__OnSetBounds( &_this->TitleText, _Const000E );
  ViewsText_OnSetAlignment( &_this->TitleText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TitleText, 0 );
  CoreRectView__OnSetBounds( &_this->Divider, _Const000F );
  ViewsImage_OnSetAlignment( &_this->Divider, ViewsImageAlignmentAlignVertBottom 
  | ViewsImageAlignmentScaleToFit );
  CoreRectView__OnSetBounds( &_this->IconWarning, _Const000B );
  ViewsImage_OnSetAlignment( &_this->IconWarning, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter | ViewsImageAlignmentScaleToFit );
  ViewsImage_OnSetVisible( &_this->IconWarning, 0 );
  CoreRectView__OnSetBounds( &_this->TimeText, _Const0010 );
  ViewsText_OnSetAlignment( &_this->TimeText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TimeText, 0 );
  ViewsText_OnSetColor( &_this->TimeText, _Const0011 );
  ViewsText_OnSetVisible( &_this->TimeText, 1 );
  CoreTimer_OnSetEnabled( &_this->GetRtcTimer, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->Background ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TitleText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->IconWarning ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeText ), 0 );
  ViewsText_OnSetFont( &_this->TitleText, EwLoadResource( &FontsFontNotoSansCjkJp32, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->Divider, EwLoadResource( &ResourceListDivider4, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->IconWarning, EwLoadResource( &ResourceIconWarning, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->TimeText, EwLoadResource( &FontsFontNotoSansCjkJp32, 
  ResourcesFont ));
  _this->GetRtcTimer.OnTrigger = EwNewSlot( _this, ComponentsStatusBar_OnGetRtcTimeSlot );
}

/* Re-Initializer for the class 'Components::StatusBar' */
void ComponentsStatusBar__ReInit( ComponentsStatusBar _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Background );
  ViewsText__ReInit( &_this->TitleText );
  ViewsImage__ReInit( &_this->Divider );
  ViewsImage__ReInit( &_this->IconWarning );
  ViewsText__ReInit( &_this->TimeText );
  CoreTimer__ReInit( &_this->GetRtcTimer );
}

/* Finalizer method for the class 'Components::StatusBar' */
void ComponentsStatusBar__Done( ComponentsStatusBar _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Background );
  ViewsText__Done( &_this->TitleText );
  ViewsImage__Done( &_this->Divider );
  ViewsImage__Done( &_this->IconWarning );
  ViewsText__Done( &_this->TimeText );
  CoreTimer__Done( &_this->GetRtcTimer );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* 'C' function for method : 'Components::StatusBar.OnGetRtcTimeSlot()' */
void ComponentsStatusBar_OnGetRtcTimeSlot( ComponentsStatusBar _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsText_OnSetString( &_this->TimeText, DeviceInterfaceSystemDeviceClass_OnGetRtcTime( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
}

/* Variants derived from the class : 'Components::StatusBar' */
EW_DEFINE_CLASS_VARIANTS( ComponentsStatusBar )
EW_END_OF_CLASS_VARIANTS( ComponentsStatusBar )

/* Virtual Method Table (VMT) for the class : 'Components::StatusBar' */
EW_DEFINE_CLASS( ComponentsStatusBar, CoreGroup, Background, Background, Background, 
                 Background, _None, _None, "Components::StatusBar" )
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
EW_END_OF_CLASS( ComponentsStatusBar )

/* Initializer for the class 'Components::PushButton' */
void ComponentsPushButton__Init( ComponentsPushButton _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  WidgetSetPushButton__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( ComponentsPushButton );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ComponentsPushButton );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super1.KeyHandler.OnHold = EwNewSlot( _this, ComponentsPushButton_OnKeyHoldSlot );
}

/* Re-Initializer for the class 'Components::PushButton' */
void ComponentsPushButton__ReInit( ComponentsPushButton _this )
{
  /* At first re-initialize the super class ... */
  WidgetSetPushButton__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Components::PushButton' */
void ComponentsPushButton__Done( ComponentsPushButton _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( WidgetSetPushButton );

  /* Don't forget to deinitialize the super class ... */
  WidgetSetPushButton__Done( &_this->_Super );
}

/* 'C' function for method : 'Components::PushButton.OnKeyHoldSlot()' */
void ComponentsPushButton_OnKeyHoldSlot( ComponentsPushButton _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( 1 == _this->Super1.KeyHandler.RepetitionCount )
  {
    EwSignal( _this->PassKeyHold, ((XObject)&_this->Super1.KeyHandler ));
  }
}

/* Variants derived from the class : 'Components::PushButton' */
EW_DEFINE_CLASS_VARIANTS( ComponentsPushButton )
EW_END_OF_CLASS_VARIANTS( ComponentsPushButton )

/* Virtual Method Table (VMT) for the class : 'Components::PushButton' */
EW_DEFINE_CLASS( ComponentsPushButton, WidgetSetPushButton, PassKeyHold, PassKeyHold, 
                 _None, _None, _None, _None, "Components::PushButton" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  WidgetSetPushButton_OnSetBounds,
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
  WidgetSetPushButton_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
EW_END_OF_CLASS( ComponentsPushButton )

/* Initializer for the class 'Components::BaseMainBG' */
void ComponentsBaseMainBG__Init( ComponentsBaseMainBG _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( ComponentsBaseMainBG );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->MainBottomBG, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->BlackBG, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ComponentsBaseMainBG );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0003 );
  CoreRectView__OnSetBounds( &_this->MainBottomBG, _Const0012 );
  CoreRectView__OnSetBounds( &_this->BlackBG, _Const0013 );
  ViewsRectangle_OnSetColor( &_this->BlackBG, _Const0004 );
  CoreGroup__Add( _this, ((CoreView)&_this->MainBottomBG ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BlackBG ), 0 );
  ViewsImage_OnSetBitmap( &_this->MainBottomBG, EwLoadResource( &ResourceMainBG, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'Components::BaseMainBG' */
void ComponentsBaseMainBG__ReInit( ComponentsBaseMainBG _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->MainBottomBG );
  ViewsRectangle__ReInit( &_this->BlackBG );
}

/* Finalizer method for the class 'Components::BaseMainBG' */
void ComponentsBaseMainBG__Done( ComponentsBaseMainBG _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->MainBottomBG );
  ViewsRectangle__Done( &_this->BlackBG );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* Variants derived from the class : 'Components::BaseMainBG' */
EW_DEFINE_CLASS_VARIANTS( ComponentsBaseMainBG )
EW_END_OF_CLASS_VARIANTS( ComponentsBaseMainBG )

/* Virtual Method Table (VMT) for the class : 'Components::BaseMainBG' */
EW_DEFINE_CLASS( ComponentsBaseMainBG, ComponentsBaseComponent, MainBottomBG, MainBottomBG, 
                 MainBottomBG, MainBottomBG, _None, _None, "Components::BaseMainBG" )
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
EW_END_OF_CLASS( ComponentsBaseMainBG )

/* Embedded Wizard */
