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
#include "_ApplicationApplication.h"
#include "_ComponentsBaseComponent.h"
#include "_ComponentsBaseMainBG.h"
#include "_ComponentsDDModeMask.h"
#include "_ComponentsStatusBar.h"
#include "_CoreGroup.h"
#include "_CoreKeyPressHandler.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreView.h"
#include "_DeviceInterfaceRtcTime.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_EffectsSlideTransition.h"
#include "_EffectsTransition.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "Components.h"
#include "Core.h"
#include "DeviceInterface.h"
#include "Effect.h"
#include "Enum.h"
#include "Fonts.h"
#include "Resource.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000068, /* ratio 80.77 % */
  0xB8002300, 0x800D6452, 0x00F20032, 0x80107100, 0x006E869D, 0x112859D0, 0x3A001BC0,
  0x40000228, 0x8C916060, 0x24782F1B, 0x13648002, 0x34C8008B, 0xC006193C, 0x1906001C,
  0xC690015A, 0x62004D25, 0x9869B000, 0x0346E191, 0xF4466B1E, 0x4068B1B9, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XStringRes _Const0000 = { _StringsDefault0, 0x0002 };
static const XRect _Const0001 = {{ 0, 0 }, { 480, 32 }};
static const XColor _Const0002 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0003 = {{ 50, 0 }, { 420, 30 }};
static const XRect _Const0004 = {{ 0, 30 }, { 480, 32 }};
static const XRect _Const0005 = {{ 174, 0 }, { 204, 30 }};
static const XRect _Const0006 = {{ 2, 0 }, { 80, 30 }};
static const XColor _Const0007 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XStringRes _Const0008 = { _StringsDefault0, 0x0013 };
static const XRect _Const0009 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const000A = {{ 0, 182 }, { 480, 272 }};
static const XRect _Const000B = {{ 0, 32 }, { 480, 182 }};
static const XRect _Const000C = {{ 0, 36 }, { 480, 272 }};
static const XStringRes _Const000D = { _StringsDefault0, 0x0017 };
static const XStringRes _Const000E = { _StringsDefault0, 0x002E };
static const XRect _Const000F = {{ 0, 0 }, { 480, 236 }};
static const XColor _Const0010 = { 0x00, 0x00, 0x00, 0xCD };
static const XRect _Const0011 = {{ 195, 62 }, { 285, 152 }};

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
  _this->UpKeyTriggerMode = EnumKeyTriggerModeON;
  _this->DownKeyTriggerMode = EnumKeyTriggerModeON;
  _this->EnterKeyTriggerMode = EnumKeyTriggerModeOFF;
  _this->HomeKeyTriggerMode = EnumKeyTriggerModeOFF;
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

  EwTrace( "%s%$", EwLoadString( &_Const0000 ), EwClassOf(((XObject)_this )));

  switch ( _this->KeyHandler.Code )
  {
    case CoreKeyCodeUp :
    {
      if ( _this->PassUpKey )
      {
        _this->KeyHandler.Continue = 1;
      }
      else
      {
        if (( EnumKeyTriggerModeON == _this->UpKeyTriggerMode ) && !ComponentsBaseComponent_IsDDModeEffected( 
            _this ))
        {
          ComponentsBaseComponent__OnShortUpKeyActivated( _this );
        }
      }
    }
    break;

    case CoreKeyCodeDown :
    {
      if ( _this->PassDownKey )
      {
        _this->KeyHandler.Continue = 1;
      }
      else
      {
        if (( EnumKeyTriggerModeON == _this->DownKeyTriggerMode ) && !ComponentsBaseComponent_IsDDModeEffected( 
            _this ))
        {
          ComponentsBaseComponent__OnShortDownKeyActivated( _this );
        }
      }
    }
    break;

    case CoreKeyCodeOk :
    {
      if ( _this->PassEnterKey )
      {
        _this->KeyHandler.Continue = 1;
      }
      else
      {
        if (( EnumKeyTriggerModeON == _this->EnterKeyTriggerMode ) && !ComponentsBaseComponent_IsDDModeEffected( 
            _this ))
        {
          ComponentsBaseComponent__OnShortEnterKeyActivated( _this );
        }
      }
    }
    break;

    case CoreKeyCodeHome :
    {
      if ( _this->PassHomeKey )
      {
        _this->KeyHandler.Continue = 1;
      }
      else
      {
        if ( EnumKeyTriggerModeON == _this->HomeKeyTriggerMode )
        {
          ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
        }
      }
    }
    break;

    case CoreKeyCodeF9 :
    {
      if ( _this->PassMagicKey )
      {
        _this->KeyHandler.Continue = 1;
      }
      else
      {
        ComponentsBaseComponent__OnShortMagicKeyActivated( _this );
      }
    }
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

  if ( !ComponentsBaseComponent_IsDDModeEffected( _this ))
  {
    switch ( _this->KeyHandler.Code )
    {
      case CoreKeyCodeUp :
        ComponentsBaseComponent__OnLongUpKeyActivated( _this );
      break;

      case CoreKeyCodeDown :
        ComponentsBaseComponent__OnLongDownKeyActivated( _this );
      break;

      case CoreKeyCodeOk :
        ComponentsBaseComponent_OnLongEnterKeyActivated( _this );
      break;

      case CoreKeyCodeHome :
        ComponentsBaseComponent_OnLongHomeKeyActivated( _this );
      break;

      default : 
        ;
    }
  }
}

/* 'C' function for method : 'Components::BaseComponent.OnKeyReleaseSlot()' */
void ComponentsBaseComponent_OnKeyReleaseSlot( ComponentsBaseComponent _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( !_this->KeyHandler.Repetition )
  {
    switch ( _this->KeyHandler.Code )
    {
      case CoreKeyCodeUp :
      {
        if (( EnumKeyTriggerModeOFF == _this->UpKeyTriggerMode ) && !ComponentsBaseComponent_IsDDModeEffected( 
            _this ))
        {
          ComponentsBaseComponent__OnShortUpKeyActivated( _this );
        }
      }
      break;

      case CoreKeyCodeDown :
      {
        if (( EnumKeyTriggerModeOFF == _this->DownKeyTriggerMode ) && !ComponentsBaseComponent_IsDDModeEffected( 
            _this ))
        {
          ComponentsBaseComponent__OnShortDownKeyActivated( _this );
        }
      }
      break;

      case CoreKeyCodeOk :
      {
        if (( EnumKeyTriggerModeOFF == _this->EnterKeyTriggerMode ) && !ComponentsBaseComponent_IsDDModeEffected( 
            _this ))
        {
          ComponentsBaseComponent__OnShortEnterKeyActivated( _this );
        }
      }
      break;

      case CoreKeyCodeHome :
      {
        if ( EnumKeyTriggerModeOFF == _this->HomeKeyTriggerMode )
        {
          ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
        }
      }
      break;

      default : 
        ;
    }
  }
}

/* 'C' function for method : 'Components::BaseComponent.OnShortDownKeyActivated()' */
void ComponentsBaseComponent_OnShortDownKeyActivated( ComponentsBaseComponent _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnShortDownKeyActivated()' */
void ComponentsBaseComponent__OnShortDownKeyActivated( void* _this )
{
  ((ComponentsBaseComponent)_this)->_VMT->OnShortDownKeyActivated((ComponentsBaseComponent)_this );
}

/* 'C' function for method : 'Components::BaseComponent.OnShortUpKeyActivated()' */
void ComponentsBaseComponent_OnShortUpKeyActivated( ComponentsBaseComponent _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnShortUpKeyActivated()' */
void ComponentsBaseComponent__OnShortUpKeyActivated( void* _this )
{
  ((ComponentsBaseComponent)_this)->_VMT->OnShortUpKeyActivated((ComponentsBaseComponent)_this );
}

/* 'C' function for method : 'Components::BaseComponent.OnShortEnterKeyActivated()' */
void ComponentsBaseComponent_OnShortEnterKeyActivated( ComponentsBaseComponent _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnShortEnterKeyActivated()' */
void ComponentsBaseComponent__OnShortEnterKeyActivated( void* _this )
{
  ((ComponentsBaseComponent)_this)->_VMT->OnShortEnterKeyActivated((ComponentsBaseComponent)_this );
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

/* 'C' function for method : 'Components::BaseComponent.OnShortHomeKeyActivated()' */
void ComponentsBaseComponent_OnShortHomeKeyActivated( ComponentsBaseComponent _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnShortHomeKeyActivated()' */
void ComponentsBaseComponent__OnShortHomeKeyActivated( void* _this )
{
  ((ComponentsBaseComponent)_this)->_VMT->OnShortHomeKeyActivated((ComponentsBaseComponent)_this );
}

/* 'C' function for method : 'Components::BaseComponent.OnLongDownKeyActivated()' */
void ComponentsBaseComponent_OnLongDownKeyActivated( ComponentsBaseComponent _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnLongDownKeyActivated()' */
void ComponentsBaseComponent__OnLongDownKeyActivated( void* _this )
{
  ((ComponentsBaseComponent)_this)->_VMT->OnLongDownKeyActivated((ComponentsBaseComponent)_this );
}

/* 'C' function for method : 'Components::BaseComponent.OnLongUpKeyActivated()' */
void ComponentsBaseComponent_OnLongUpKeyActivated( ComponentsBaseComponent _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnLongUpKeyActivated()' */
void ComponentsBaseComponent__OnLongUpKeyActivated( void* _this )
{
  ((ComponentsBaseComponent)_this)->_VMT->OnLongUpKeyActivated((ComponentsBaseComponent)_this );
}

/* 'C' function for method : 'Components::BaseComponent.OnLongEnterKeyActivated()' */
void ComponentsBaseComponent_OnLongEnterKeyActivated( ComponentsBaseComponent _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* 'C' function for method : 'Components::BaseComponent.OnLongHomeKeyActivated()' */
void ComponentsBaseComponent_OnLongHomeKeyActivated( ComponentsBaseComponent _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* 'C' function for method : 'Components::BaseComponent.OnShortMagicKeyActivated()' */
void ComponentsBaseComponent_OnShortMagicKeyActivated( ComponentsBaseComponent _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnShortMagicKeyActivated()' */
void ComponentsBaseComponent__OnShortMagicKeyActivated( void* _this )
{
  ((ComponentsBaseComponent)_this)->_VMT->OnShortMagicKeyActivated((ComponentsBaseComponent)_this );
}

/* 'C' function for method : 'Components::BaseComponent.IsDDModeEffected()' */
XBool ComponentsBaseComponent_IsDDModeEffected( ComponentsBaseComponent _this )
{
  return (XBool)( _this->DDModeEnabled && DeviceInterfaceVehicleDeviceClass_OnGetDDModeActivated( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )));
}

/* 'C' function for method : 'Components::BaseComponent.OnSetDDModeEnabled()' */
void ComponentsBaseComponent_OnSetDDModeEnabled( ComponentsBaseComponent _this, 
  XBool value )
{
  if ( _this->DDModeEnabled != value )
  {
    _this->DDModeEnabled = value;
  }
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnSetDDModeEnabled()' */
void ComponentsBaseComponent__OnSetDDModeEnabled( void* _this, XBool value )
{
  ((ComponentsBaseComponent)_this)->_VMT->OnSetDDModeEnabled((ComponentsBaseComponent)_this
  , value );
}

/* Variants derived from the class : 'Components::BaseComponent' */
EW_DEFINE_CLASS_VARIANTS( ComponentsBaseComponent )
EW_END_OF_CLASS_VARIANTS( ComponentsBaseComponent )

/* Virtual Method Table (VMT) for the class : 'Components::BaseComponent' */
EW_DEFINE_CLASS( ComponentsBaseComponent, CoreGroup, KeyHandler, KeyHandler, KeyHandler, 
                 KeyHandler, HomeKeyTriggerMode, HomeKeyTriggerMode, "Components::BaseComponent" )
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
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
EW_END_OF_CLASS( ComponentsBaseComponent )

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
  CoreSystemEventHandler__Init( &_this->OnUpdateLocalTimeEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ComponentsStatusBar );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0001 );
  CoreRectView__OnSetBounds( &_this->Background, _Const0001 );
  ViewsRectangle_OnSetColor( &_this->Background, _Const0002 );
  CoreRectView__OnSetBounds( &_this->TitleText, _Const0003 );
  ViewsText_OnSetAlignment( &_this->TitleText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TitleText, 0 );
  CoreRectView__OnSetBounds( &_this->Divider, _Const0004 );
  ViewsImage_OnSetAlignment( &_this->Divider, ViewsImageAlignmentAlignVertBottom 
  | ViewsImageAlignmentScaleToFit );
  CoreRectView__OnSetBounds( &_this->IconWarning, _Const0005 );
  ViewsImage_OnSetAlignment( &_this->IconWarning, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter | ViewsImageAlignmentScaleToFit );
  ViewsImage_OnSetVisible( &_this->IconWarning, 0 );
  CoreRectView__OnSetBounds( &_this->TimeText, _Const0006 );
  ViewsText_OnSetAlignment( &_this->TimeText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TimeText, 0 );
  ViewsText_OnSetColor( &_this->TimeText, _Const0007 );
  ViewsText_OnSetVisible( &_this->TimeText, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->Background ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TitleText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->IconWarning ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeText ), 0 );
  ViewsText_OnSetFont( &_this->TitleText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->Divider, EwLoadResource( &ResourceListDivider4, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->IconWarning, EwLoadResource( &ResourceIconWarning, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->TimeText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  _this->OnUpdateLocalTimeEventHandler.OnEvent = EwNewSlot( _this, ComponentsStatusBar_OnUpdateLocalTimeSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->OnUpdateLocalTimeEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->UpdateLocalTimeSystemEvent );
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
  CoreSystemEventHandler__ReInit( &_this->OnUpdateLocalTimeEventHandler );
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
  CoreSystemEventHandler__Done( &_this->OnUpdateLocalTimeEventHandler );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* 'C' function for method : 'Components::StatusBar.OnUpdateLocalTimeSlot()' */
void ComponentsStatusBar_OnUpdateLocalTimeSlot( ComponentsStatusBar _this, XObject 
  sender )
{
  DeviceInterfaceRtcTime CurrentTime;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CurrentTime = EwCastObject( _this->OnUpdateLocalTimeEventHandler.Context, DeviceInterfaceRtcTime );

  if ( CurrentTime != 0 )
  {
    ViewsText_OnSetString( &_this->TimeText, EwConcatString( EwConcatString( EwNewStringInt( 
    CurrentTime->Hour, 2, 10 ), EwLoadString( &_Const0008 )), EwNewStringInt( CurrentTime->Minute, 
    2, 10 )));
  }
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
EW_END_OF_CLASS( ComponentsStatusBar )

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
  CoreSystemEventHandler__Init( &_this->DDModeStateChangedHandler, &_this->_XObject, 0 );
  ComponentsDDModeMask__Init( &_this->DDModeMask, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ComponentsBaseMainBG );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0009 );
  CoreRectView__OnSetBounds( &_this->MainBottomBG, _Const000A );
  CoreRectView__OnSetBounds( &_this->BlackBG, _Const000B );
  ViewsRectangle_OnSetColor( &_this->BlackBG, _Const0002 );
  CoreSystemEventHandler_OnSetEnabled( &_this->DDModeStateChangedHandler, 0 );
  CoreView_OnSetStackingPriority((CoreView)&_this->DDModeMask, 1 );
  CoreRectView__OnSetBounds( &_this->DDModeMask, _Const000C );
  CoreGroup__OnSetEnabled( &_this->DDModeMask, 0 );
  CoreGroup_OnSetVisible((CoreGroup)&_this->DDModeMask, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MainBottomBG ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BlackBG ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DDModeMask ), 0 );
  ViewsImage_OnSetBitmap( &_this->MainBottomBG, EwLoadResource( &ResourceMainBG, 
  ResourcesBitmap ));
  _this->DDModeStateChangedHandler.OnEvent = EwNewSlot( _this, ComponentsBaseMainBG_OnDDModeStateChangedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->DDModeStateChangedHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->DDModeStateChangedSystemEvent );

  /* Call the user defined constructor */
  ComponentsBaseMainBG_Init( _this, aArg );
}

/* Re-Initializer for the class 'Components::BaseMainBG' */
void ComponentsBaseMainBG__ReInit( ComponentsBaseMainBG _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->MainBottomBG );
  ViewsRectangle__ReInit( &_this->BlackBG );
  CoreSystemEventHandler__ReInit( &_this->DDModeStateChangedHandler );
  ComponentsDDModeMask__ReInit( &_this->DDModeMask );
}

/* Finalizer method for the class 'Components::BaseMainBG' */
void ComponentsBaseMainBG__Done( ComponentsBaseMainBG _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->MainBottomBG );
  ViewsRectangle__Done( &_this->BlackBG );
  CoreSystemEventHandler__Done( &_this->DDModeStateChangedHandler );
  ComponentsDDModeMask__Done( &_this->DDModeMask );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ComponentsBaseMainBG_Init( ComponentsBaseMainBG _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  CoreSystemEventHandler_OnSetEnabled( &_this->DDModeStateChangedHandler, _this->Super1.DDModeEnabled );
  ComponentsBaseMainBG_UpdateDDModeMask( _this );
}

/* 'C' function for method : 'Components::BaseMainBG.OnShortHomeKeyActivated()' */
void ComponentsBaseMainBG_OnShortHomeKeyActivated( ComponentsBaseMainBG _this )
{
  if ( ComponentsBaseComponent_IsDDModeEffected((ComponentsBaseComponent)_this ))
  {
    ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

    if ( App != 0 )
    {
      ApplicationApplication_ReturnToLauncher( App );
    }
  }
  else
  {
    CoreGroup__DismissDialog( _this->Super4.Owner, ((CoreGroup)_this ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 0 );
  }
}

/* 'C' function for method : 'Components::BaseMainBG.OnSetDDModeEnabled()' */
void ComponentsBaseMainBG_OnSetDDModeEnabled( ComponentsBaseMainBG _this, XBool 
  value )
{
  ComponentsBaseComponent_OnSetDDModeEnabled((ComponentsBaseComponent)_this, value );
  CoreSystemEventHandler_OnSetEnabled( &_this->DDModeStateChangedHandler, value );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void ComponentsBaseMainBG_OnDDModeStateChangedSlot( ComponentsBaseMainBG _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ComponentsBaseMainBG_UpdateDDModeMask( _this );
}

/* 'C' function for method : 'Components::BaseMainBG.UpdateDDModeMask()' */
void ComponentsBaseMainBG_UpdateDDModeMask( ComponentsBaseMainBG _this )
{
  if ( CoreGroup__IsCurrentDialog( _this ) && _this->Super1.DDModeEnabled )
  {
    CoreGroup_OnSetVisible((CoreGroup)&_this->DDModeMask, DeviceInterfaceVehicleDeviceClass_OnGetDDModeActivated( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )));
    EwTrace( "%s%b%s%$", EwLoadString( &_Const000D ), CoreGroup_OnGetVisible((CoreGroup)&_this->DDModeMask ), 
      EwLoadString( &_Const000E ), EwClassOf(((XObject)_this )));
  }
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
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
EW_END_OF_CLASS( ComponentsBaseMainBG )

/* Initializer for the class 'Components::DDModeMask' */
void ComponentsDDModeMask__Init( ComponentsDDModeMask _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( ComponentsDDModeMask );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->DDModeBG, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->DDModeIcon, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ComponentsDDModeMask );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const000F );
  CoreView_OnSetStackingPriority((CoreView)&_this->DDModeBG, 0 );
  CoreRectView__OnSetBounds( &_this->DDModeBG, _Const000F );
  ViewsRectangle_OnSetColor( &_this->DDModeBG, _Const0010 );
  CoreView_OnSetStackingPriority((CoreView)&_this->DDModeIcon, 0 );
  CoreRectView__OnSetBounds( &_this->DDModeIcon, _Const0011 );
  CoreGroup__Add( _this, ((CoreView)&_this->DDModeBG ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DDModeIcon ), 0 );
  ViewsImage_OnSetBitmap( &_this->DDModeIcon, EwLoadResource( &ResourceIconDDActive, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'Components::DDModeMask' */
void ComponentsDDModeMask__ReInit( ComponentsDDModeMask _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->DDModeBG );
  ViewsImage__ReInit( &_this->DDModeIcon );
}

/* Finalizer method for the class 'Components::DDModeMask' */
void ComponentsDDModeMask__Done( ComponentsDDModeMask _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->DDModeBG );
  ViewsImage__Done( &_this->DDModeIcon );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* Variants derived from the class : 'Components::DDModeMask' */
EW_DEFINE_CLASS_VARIANTS( ComponentsDDModeMask )
EW_END_OF_CLASS_VARIANTS( ComponentsDDModeMask )

/* Virtual Method Table (VMT) for the class : 'Components::DDModeMask' */
EW_DEFINE_CLASS( ComponentsDDModeMask, CoreGroup, DDModeBG, DDModeBG, DDModeBG, 
                 DDModeBG, _None, _None, "Components::DDModeMask" )
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
EW_END_OF_CLASS( ComponentsDDModeMask )

/* Embedded Wizard */
