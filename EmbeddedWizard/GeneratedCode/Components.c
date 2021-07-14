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
#include "_ApplicationApplication.h"
#include "_ComponentsBaseComponent.h"
#include "_ComponentsBaseMainBG.h"
#include "_ComponentsBaseText.h"
#include "_ComponentsDDModeMask.h"
#include "_CoreGroup.h"
#include "_CoreKeyPressHandler.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_EffectSlideTransitionNoFade.h"
#include "_EffectsTransition.h"
#include "_MenuBaseMenuView.h"
#include "_MenuVerticalMenu.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsBorder.h"
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
#include "Strings.h"
#include "Views.h"

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0001 = {{ 0, 182 }, { 480, 272 }};
static const XRect _Const0002 = {{ 0, 38 }, { 480, 182 }};
static const XColor _Const0003 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0004 = {{ 0, 36 }, { 480, 272 }};
static const XRect _Const0005 = {{ 0, 0 }, { 480, 236 }};
static const XColor _Const0006 = { 0x00, 0x00, 0x00, 0xCD };
static const XRect _Const0007 = {{ 195, 37 }, { 285, 127 }};
static const XRect _Const0008 = {{ 10, 138 }, { 470, 200 }};

/* Initializer for the class 'Components::BaseComponent' */
void ComponentsBaseComponent__Init( ComponentsBaseComponent _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ComponentsBaseComponent );

  /* ... then construct all embedded objects */
  CoreKeyPressHandler__Init( &_this->KeyHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ComponentsBaseComponent );

  /* ... and initialize objects, variables, properties, etc. */
  _this->UpKeyTriggerMode = EnumKeyTriggerModeON;
  _this->DownKeyTriggerMode = EnumKeyTriggerModeON;
  _this->KeyHandler.OnRelease = EwNewSlot( _this, ComponentsBaseComponent_OnKeyReleaseSlot );
  _this->KeyHandler.OnPress = EwNewSlot( _this, ComponentsBaseComponent_OnKeyPressSlot );
  _this->KeyHandler.OnHold = EwNewSlot( _this, ComponentsBaseComponent_OnKeyHoldSlot );

  /* Call the user defined constructor */
  ComponentsBaseComponent_Init( _this, aArg );
}

/* Re-Initializer for the class 'Components::BaseComponent' */
void ComponentsBaseComponent__ReInit( ComponentsBaseComponent _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreKeyPressHandler__ReInit( &_this->KeyHandler );
}

/* Finalizer method for the class 'Components::BaseComponent' */
void ComponentsBaseComponent__Done( ComponentsBaseComponent _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  CoreKeyPressHandler__Done( &_this->KeyHandler );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ComponentsBaseComponent_Init( ComponentsBaseComponent _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  DeviceInterfaceSystemDeviceClass_SetKeyTriggerMode( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ), CoreKeyCodeUp, _this->UpKeyTriggerMode );
  DeviceInterfaceSystemDeviceClass_SetKeyTriggerMode( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ), CoreKeyCodeDown, _this->DownKeyTriggerMode );
  DeviceInterfaceSystemDeviceClass_SetKeyTriggerMode( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ), CoreKeyCodeOk, EnumKeyTriggerModeOFF );
  DeviceInterfaceSystemDeviceClass_SetKeyTriggerMode( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ), CoreKeyCodeHome, EnumKeyTriggerModeOFF );
  DeviceInterfaceSystemDeviceClass_SetMagicKeyEnabled( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ), _this->MagicKeyEnabled );
}

/* 'C' function for method : 'Components::BaseComponent.OnKeyPressSlot()' */
void ComponentsBaseComponent_OnKeyPressSlot( ComponentsBaseComponent _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  switch ( _this->KeyHandler.Code )
  {
    case CoreKeyCodeUp :
      if ( _this->PassUpKey )
        _this->KeyHandler.Continue = 1;
      else
        if (( EnumKeyTriggerModeON == _this->UpKeyTriggerMode ) && !ComponentsBaseComponent_IsDDModeEffected( 
            _this ))
          ComponentsBaseComponent__OnShortUpKeyActivated( _this );
    break;

    case CoreKeyCodeDown :
      if ( _this->PassDownKey )
        _this->KeyHandler.Continue = 1;
      else
        if (( EnumKeyTriggerModeON == _this->DownKeyTriggerMode ) && !ComponentsBaseComponent_IsDDModeEffected( 
            _this ))
          ComponentsBaseComponent__OnShortDownKeyActivated( _this );
    break;

    case CoreKeyCodeOk :
      if ( _this->PassEnterKey )
        _this->KeyHandler.Continue = 1;
    break;

    case CoreKeyCodeHome :
      if ( _this->PassHomeKey )
        _this->KeyHandler.Continue = 1;
    break;

    case CoreKeyCodeF9 :
      if ( _this->PassMagicKey )
        _this->KeyHandler.Continue = 1;
      else
        ComponentsBaseComponent__OnShortMagicKeyActivated( _this );
    break;

    default :; 
  }
}

/* 'C' function for method : 'Components::BaseComponent.OnKeyHoldSlot()' */
void ComponentsBaseComponent_OnKeyHoldSlot( ComponentsBaseComponent _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( !ComponentsBaseComponent_IsDDModeEffected( _this ))
    switch ( _this->KeyHandler.Code )
    {
      case CoreKeyCodeUp :
        ComponentsBaseComponent__OnLongUpKeyActivated( _this );
      break;

      case CoreKeyCodeDown :
        ComponentsBaseComponent__OnLongDownKeyActivated( _this );
      break;

      case CoreKeyCodeOk :
        ComponentsBaseComponent__OnLongEnterKeyActivated( _this );
      break;

      case CoreKeyCodeHome :
        ComponentsBaseComponent__OnLongHomeKeyActivated( _this );
      break;

      default :; 
    }
}

/* 'C' function for method : 'Components::BaseComponent.OnKeyReleaseSlot()' */
void ComponentsBaseComponent_OnKeyReleaseSlot( ComponentsBaseComponent _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( !_this->KeyHandler.Repetition )
    switch ( _this->KeyHandler.Code )
    {
      case CoreKeyCodeUp :
        if ((( EnumKeyTriggerModeOFF == _this->UpKeyTriggerMode ) && !ComponentsBaseComponent_IsDDModeEffected( 
            _this )) && DeviceInterfaceSystemDeviceClass_IsKeyStateValid( EwGetAutoObject( 
            &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )))
          ComponentsBaseComponent__OnShortUpKeyActivated( _this );
        else
          ComponentsBaseComponent__OnUpKeyReleased( _this );
      break;

      case CoreKeyCodeDown :
        if ((( EnumKeyTriggerModeOFF == _this->DownKeyTriggerMode ) && !ComponentsBaseComponent_IsDDModeEffected( 
            _this )) && DeviceInterfaceSystemDeviceClass_IsKeyStateValid( EwGetAutoObject( 
            &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )))
          ComponentsBaseComponent__OnShortDownKeyActivated( _this );
        else
          ComponentsBaseComponent__OnDownKeyReleased( _this );
      break;

      case CoreKeyCodeOk :
        if ( !ComponentsBaseComponent_IsDDModeEffected( _this ) && DeviceInterfaceSystemDeviceClass_IsKeyStateValid( 
            EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )))
          ComponentsBaseComponent__OnShortEnterKeyActivated( _this );
      break;

      case CoreKeyCodeHome :
        if ( DeviceInterfaceSystemDeviceClass_IsKeyStateValid( EwGetAutoObject( 
            &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )))
          ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
      break;

      default :; 
    }
  else
    switch ( _this->KeyHandler.Code )
    {
      case CoreKeyCodeUp :
        ComponentsBaseComponent__OnUpKeyReleased( _this );
      break;

      case CoreKeyCodeDown :
        ComponentsBaseComponent__OnDownKeyReleased( _this );
      break;

      default :; 
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
  ((ComponentsBaseComponent)_this)->_.VMT->OnShortDownKeyActivated((ComponentsBaseComponent)_this );
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
  ((ComponentsBaseComponent)_this)->_.VMT->OnShortUpKeyActivated((ComponentsBaseComponent)_this );
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
  ((ComponentsBaseComponent)_this)->_.VMT->OnShortEnterKeyActivated((ComponentsBaseComponent)_this );
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
  ((ComponentsBaseComponent)_this)->_.VMT->OnShortHomeKeyActivated((ComponentsBaseComponent)_this );
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
  ((ComponentsBaseComponent)_this)->_.VMT->OnLongDownKeyActivated((ComponentsBaseComponent)_this );
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
  ((ComponentsBaseComponent)_this)->_.VMT->OnLongUpKeyActivated((ComponentsBaseComponent)_this );
}

/* 'C' function for method : 'Components::BaseComponent.OnLongEnterKeyActivated()' */
void ComponentsBaseComponent_OnLongEnterKeyActivated( ComponentsBaseComponent _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnLongEnterKeyActivated()' */
void ComponentsBaseComponent__OnLongEnterKeyActivated( void* _this )
{
  ((ComponentsBaseComponent)_this)->_.VMT->OnLongEnterKeyActivated((ComponentsBaseComponent)_this );
}

/* 'C' function for method : 'Components::BaseComponent.OnLongHomeKeyActivated()' */
void ComponentsBaseComponent_OnLongHomeKeyActivated( ComponentsBaseComponent _this )
{
  if ( 1 == _this->KeyHandler.RepetitionCount )
  {
    ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

    if ( App != 0 )
      ApplicationApplication_ReturnToHome( App );
  }
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnLongHomeKeyActivated()' */
void ComponentsBaseComponent__OnLongHomeKeyActivated( void* _this )
{
  ((ComponentsBaseComponent)_this)->_.VMT->OnLongHomeKeyActivated((ComponentsBaseComponent)_this );
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
  ((ComponentsBaseComponent)_this)->_.VMT->OnShortMagicKeyActivated((ComponentsBaseComponent)_this );
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
    _this->DDModeEnabled = value;
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnSetDDModeEnabled()' */
void ComponentsBaseComponent__OnSetDDModeEnabled( void* _this, XBool value )
{
  ((ComponentsBaseComponent)_this)->_.VMT->OnSetDDModeEnabled((ComponentsBaseComponent)_this
  , value );
}

/* Callback when down key of on trigger mode is released */
void ComponentsBaseComponent_OnDownKeyReleased( ComponentsBaseComponent _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnDownKeyReleased()' */
void ComponentsBaseComponent__OnDownKeyReleased( void* _this )
{
  ((ComponentsBaseComponent)_this)->_.VMT->OnDownKeyReleased((ComponentsBaseComponent)_this );
}

/* Callback when up key of on trigger mode is released */
void ComponentsBaseComponent_OnUpKeyReleased( ComponentsBaseComponent _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Wrapper function for the virtual method : 'Components::BaseComponent.OnUpKeyReleased()' */
void ComponentsBaseComponent__OnUpKeyReleased( void* _this )
{
  ((ComponentsBaseComponent)_this)->_.VMT->OnUpKeyReleased((ComponentsBaseComponent)_this );
}

/* 'C' function for method : 'Components::BaseComponent.OnSetMagicKeyEnabled()' */
void ComponentsBaseComponent_OnSetMagicKeyEnabled( ComponentsBaseComponent _this, 
  XBool value )
{
  if ( _this->MagicKeyEnabled != value )
  {
    _this->MagicKeyEnabled = value;
    DeviceInterfaceSystemDeviceClass_SetMagicKeyEnabled( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
    DeviceInterfaceSystemDeviceClass ), value );
  }
}

/* Variants derived from the class : 'Components::BaseComponent' */
EW_DEFINE_CLASS_VARIANTS( ComponentsBaseComponent )
EW_END_OF_CLASS_VARIANTS( ComponentsBaseComponent )

/* Virtual Method Table (VMT) for the class : 'Components::BaseComponent' */
EW_DEFINE_CLASS( ComponentsBaseComponent, CoreGroup, KeyHandler, KeyHandler, KeyHandler, 
                 KeyHandler, DownKeyTriggerMode, DownKeyTriggerMode, "Components::BaseComponent" )
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
  ComponentsBaseComponent_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( ComponentsBaseComponent )

/* Initializer for the class 'Components::BaseMainBG' */
void ComponentsBaseMainBG__Init( ComponentsBaseMainBG _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ComponentsBaseMainBG );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->MainBottomBG, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->BlackBG, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->DDModeStateChangedHandler, &_this->_.XObject, 0 );
  ComponentsDDModeMask__Init( &_this->DDModeMask, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->HideFocusFrameTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->MainBottomBG, _Const0001 );
  CoreRectView__OnSetBounds( &_this->BlackBG, _Const0002 );
  ViewsRectangle_OnSetColor( &_this->BlackBG, _Const0003 );
  CoreSystemEventHandler_OnSetEnabled( &_this->DDModeStateChangedHandler, 0 );
  CoreView_OnSetStackingPriority((CoreView)&_this->DDModeMask, 1 );
  CoreRectView__OnSetBounds( &_this->DDModeMask, _Const0004 );
  CoreGroup__OnSetEnabled( &_this->DDModeMask, 0 );
  CoreGroup__OnSetVisible( &_this->DDModeMask, 0 );
  CoreTimer_OnSetPeriod( &_this->HideFocusFrameTimer, 50 );
  CoreGroup__Add( _this, ((CoreView)&_this->MainBottomBG ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BlackBG ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DDModeMask ), 0 );
  ViewsImage_OnSetBitmap( &_this->MainBottomBG, EwLoadResource( &ResourceMainBG, 
  ResourcesBitmap ));
  _this->DDModeStateChangedHandler.OnEvent = EwNewSlot( _this, ComponentsBaseMainBG_OnDDModeStateChangedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->DDModeStateChangedHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->DDModeStateChangedSystemEvent );
  _this->HideFocusFrameTimer.OnTrigger = EwNewSlot( _this, ComponentsBaseMainBG_OnHideFocusFrameTimeoutSlot );

  /* Call the user defined constructor */
  ComponentsBaseMainBG_Init( _this, aArg );
}

/* Re-Initializer for the class 'Components::BaseMainBG' */
void ComponentsBaseMainBG__ReInit( ComponentsBaseMainBG _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->MainBottomBG );
  ViewsRectangle__ReInit( &_this->BlackBG );
  CoreSystemEventHandler__ReInit( &_this->DDModeStateChangedHandler );
  ComponentsDDModeMask__ReInit( &_this->DDModeMask );
  CoreTimer__ReInit( &_this->HideFocusFrameTimer );
}

/* Finalizer method for the class 'Components::BaseMainBG' */
void ComponentsBaseMainBG__Done( ComponentsBaseMainBG _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->MainBottomBG );
  ViewsRectangle__Done( &_this->BlackBG );
  CoreSystemEventHandler__Done( &_this->DDModeStateChangedHandler );
  ComponentsDDModeMask__Done( &_this->DDModeMask );
  CoreTimer__Done( &_this->HideFocusFrameTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_.Super );
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
      ApplicationApplication_ReturnToLauncher( App );
  }
  else
    ComponentsBaseMainBG_DismissThisDialog( _this );
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
  if ( _this->Super1.DDModeEnabled )
  {
    if ( !DeviceInterfaceVehicleDeviceClass_OnGetDDModeActivated( EwGetAutoObject( 
        &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
      CoreGroup__OnSetVisible( &_this->DDModeMask, 0 );
    else
      if ( CoreGroup__IsCurrentDialog( _this ))
        CoreGroup__OnSetVisible( &_this->DDModeMask, 1 );
  }
}

/* 'C' function for method : 'Components::BaseMainBG.DismissThisDialog()' */
void ComponentsBaseMainBG_DismissThisDialog( ComponentsBaseMainBG _this )
{
  if ( _this->SlideOutEffectEnabled )
    ComponentsBaseMainBG_SlideOutDialog( _this );
  else
    if ( _this->Super4.Owner != 0 )
    {
      MenuBaseMenuView MenuDialog = EwCastObject( _this->Super4.Owner, MenuBaseMenuView );

      if ( MenuDialog != 0 )
        ViewsBorder_OnSetVisible( &MenuDialog->Menu.FocusFrame, 1 );

      CoreGroup_DismissDialog( _this->Super4.Owner, ((CoreGroup)_this ), ((EffectsTransition)EwGetAutoObject( 
      &EffectNoSlideOut, EffectSlideTransitionNoFade )), 0, 0, EwNullSlot, EwNullSlot, 
      0 );
    }
}

/* 'C' function for method : 'Components::BaseMainBG.SlideInDialog()' */
void ComponentsBaseMainBG_SlideInDialog( ComponentsBaseMainBG _this, ComponentsBaseMainBG 
  aChildDialog )
{
  if ( CoreGroup__IsCurrentDialog( _this ) && ( aChildDialog != 0 ))
  {
    MenuBaseMenuView ChildMenu;
    MenuBaseMenuView CurrentMenu;
    _this->ChildDialog = aChildDialog;
    ChildMenu = EwCastObject( aChildDialog, MenuBaseMenuView );

    if ( ChildMenu != 0 )
    {
      ViewsBorder_OnSetVisible( &ChildMenu->Menu.FocusFrame, 0 );
      MenuVerticalMenu_HideArrowScrollBar( &ChildMenu->Menu );
      MenuVerticalMenu_HideScrollbar( &ChildMenu->Menu );
    }

    CurrentMenu = EwCastObject( _this, MenuBaseMenuView );

    if ( CurrentMenu != 0 )
    {
      ViewsBorder_OnSetVisible( &CurrentMenu->Menu.FocusFrame, 0 );
      MenuVerticalMenu_HideArrowScrollBar( &CurrentMenu->Menu );
      MenuVerticalMenu_HideScrollbar( &CurrentMenu->Menu );
    }

    _this->SlideDirection = CoreDirectionLeft;
    CoreTimer_OnSetEnabled( &_this->HideFocusFrameTimer, 1 );
  }
}

/* 'C' function for method : 'Components::BaseMainBG.OnHideFocusFrameTimeoutSlot()' */
void ComponentsBaseMainBG_OnHideFocusFrameTimeoutSlot( ComponentsBaseMainBG _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->HideFocusFrameTimer, 0 );

  if ( CoreDirectionLeft == _this->SlideDirection )
    ComponentsBaseMainBG_PresentDialogWithSlideInEffect( _this, ((CoreGroup)_this->ChildDialog ));
  else
    ComponentsBaseMainBG_DismissMenuWithSlideOutEffect( _this );
}

/* 'C' function for method : 'Components::BaseMainBG.OnDialogSlideInCompletedSlot()' */
void ComponentsBaseMainBG_OnDialogSlideInCompletedSlot( ComponentsBaseMainBG _this, 
  XObject sender )
{
  MenuBaseMenuView ChildMenu;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ChildMenu = EwCastObject( _this->ChildDialog, MenuBaseMenuView );

  if ( ChildMenu != 0 )
  {
    if ( ChildMenu->Menu.NoOfItems > 0 )
      ViewsBorder_OnSetVisible( &ChildMenu->Menu.FocusFrame, 1 );

    if ( ChildMenu->Menu.ArrowScrollBarVisible )
      MenuVerticalMenu_RestoreArrowScrollBar( &ChildMenu->Menu );
  }

  _this->ChildDialog = 0;
}

/* 'C' function for method : 'Components::BaseMainBG.PresentDialogWithSlideInEffect()' */
void ComponentsBaseMainBG_PresentDialogWithSlideInEffect( ComponentsBaseMainBG _this, 
  CoreGroup aView )
{
  if ( aView != 0 )
    CoreGroup_PresentDialog((CoreGroup)_this, aView, ((EffectsTransition)EwGetAutoObject( 
    &EffectSlideInTransition, EffectSlideTransitionNoFade )), 0, 0, 0, 0, 0, EwNewSlot( 
    _this, ComponentsBaseMainBG_OnDialogSlideInCompletedSlot ), EwNullSlot, 0 );
}

/* 'C' function for method : 'Components::BaseMainBG.OnDialogSlideOutCompletedSlot()' */
void ComponentsBaseMainBG_OnDialogSlideOutCompletedSlot( ComponentsBaseMainBG _this, 
  XObject sender )
{
  MenuBaseMenuView OwnerMenu;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  OwnerMenu = EwCastObject( _this->OwnerDialog, MenuBaseMenuView );

  if ( OwnerMenu != 0 )
  {
    MenuVerticalMenu_RestoreFocusFrame( &OwnerMenu->Menu );
    MenuVerticalMenu_RestoreArrowScrollBar( &OwnerMenu->Menu );
    MenuVerticalMenu_RestoreScrollbar( &OwnerMenu->Menu );
  }
}

/* 'C' function for method : 'Components::BaseMainBG.SlideOutDialog()' */
void ComponentsBaseMainBG_SlideOutDialog( ComponentsBaseMainBG _this )
{
  if ( CoreGroup__IsCurrentDialog( _this ))
  {
    MenuBaseMenuView CurrentMenu;
    _this->OwnerDialog = EwCastObject( _this->Super4.Owner, ComponentsBaseMainBG );
    CurrentMenu = EwCastObject( _this, MenuBaseMenuView );

    if ( CurrentMenu != 0 )
    {
      ViewsBorder_OnSetVisible( &CurrentMenu->Menu.FocusFrame, 0 );
      MenuVerticalMenu_HideArrowScrollBar( &CurrentMenu->Menu );
    }

    _this->SlideDirection = CoreDirectionRight;
    CoreTimer_OnSetEnabled( &_this->HideFocusFrameTimer, 1 );
  }
}

/* 'C' function for method : 'Components::BaseMainBG.DismissMenuWithSlideOutEffect()' */
void ComponentsBaseMainBG_DismissMenuWithSlideOutEffect( ComponentsBaseMainBG _this )
{
  CoreGroup_DismissDialog( _this->Super4.Owner, ((CoreGroup)_this ), ((EffectsTransition)EwGetAutoObject( 
  &EffectSlideOutTransition, EffectSlideTransitionNoFade )), 0, 0, EwNewSlot( _this, 
  ComponentsBaseMainBG_OnDialogSlideOutCompletedSlot ), EwNullSlot, 0 );
}

/* Variants derived from the class : 'Components::BaseMainBG' */
EW_DEFINE_CLASS_VARIANTS( ComponentsBaseMainBG )
EW_END_OF_CLASS_VARIANTS( ComponentsBaseMainBG )

/* Virtual Method Table (VMT) for the class : 'Components::BaseMainBG' */
EW_DEFINE_CLASS( ComponentsBaseMainBG, ComponentsBaseComponent, ChildDialog, MainBottomBG, 
                 MainBottomBG, MainBottomBG, SlideDirection, SlideDirection, "Components::BaseMainBG" )
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
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( ComponentsBaseMainBG )

/* Initializer for the class 'Components::DDModeMask' */
void ComponentsDDModeMask__Init( ComponentsDDModeMask _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ComponentsDDModeMask );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->DDModeBG, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->DDModeIcon, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->WarningText, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ComponentsDDModeMask );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0005 );
  CoreView_OnSetStackingPriority((CoreView)&_this->DDModeBG, 0 );
  CoreRectView__OnSetBounds( &_this->DDModeBG, _Const0005 );
  ViewsRectangle_OnSetColor( &_this->DDModeBG, _Const0006 );
  CoreView_OnSetStackingPriority((CoreView)&_this->DDModeIcon, 0 );
  CoreRectView__OnSetBounds( &_this->DDModeIcon, _Const0007 );
  CoreRectView__OnSetBounds( &_this->WarningText, _Const0008 );
  ViewsText_OnSetAlignment( &_this->WarningText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->WarningText, EwGetVariantOfString( &StringsDD_WARNING ));
  CoreGroup__Add( _this, ((CoreView)&_this->DDModeBG ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DDModeIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->WarningText ), 0 );
  ViewsImage_OnSetBitmap( &_this->DDModeIcon, EwLoadResource( &ResourceIconDDActive, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->WarningText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Components::DDModeMask' */
void ComponentsDDModeMask__ReInit( ComponentsDDModeMask _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->DDModeBG );
  ViewsImage__ReInit( &_this->DDModeIcon );
  ViewsText__ReInit( &_this->WarningText );
}

/* Finalizer method for the class 'Components::DDModeMask' */
void ComponentsDDModeMask__Done( ComponentsDDModeMask _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->DDModeBG );
  ViewsImage__Done( &_this->DDModeIcon );
  ViewsText__Done( &_this->WarningText );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* Variants derived from the class : 'Components::DDModeMask' */
EW_DEFINE_CLASS_VARIANTS( ComponentsDDModeMask )
EW_END_OF_CLASS_VARIANTS( ComponentsDDModeMask )

/* Virtual Method Table (VMT) for the class : 'Components::DDModeMask' */
EW_DEFINE_CLASS( ComponentsDDModeMask, CoreGroup, DDModeBG, DDModeBG, DDModeBG, 
                 DDModeBG, _.VMT, _.VMT, "Components::DDModeMask" )
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
EW_END_OF_CLASS( ComponentsDDModeMask )

/* Initializer for the class 'Components::BaseText' */
void ComponentsBaseText__Init( ComponentsBaseText _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ViewsText__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ComponentsBaseText );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ComponentsBaseText );

  /* Call the user defined constructor */
  ComponentsBaseText_Init( _this, aArg );
}

/* Re-Initializer for the class 'Components::BaseText' */
void ComponentsBaseText__ReInit( ComponentsBaseText _this )
{
  /* At first re-initialize the super class ... */
  ViewsText__ReInit( &_this->_.Super );

  /* Call the user defined re-constructor of the class */
  ComponentsBaseText_ReInit( _this );
}

/* Finalizer method for the class 'Components::BaseText' */
void ComponentsBaseText__Done( ComponentsBaseText _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ViewsText );

  /* Don't forget to deinitialize the super class ... */
  ViewsText__Done( &_this->_.Super );
}

/* 'C' function for method : 'Components::BaseText.ReInit()' */
void ComponentsBaseText_ReInit( ComponentsBaseText _this )
{
  EwPostSignal( EwNewSlot( _this, ComponentsBaseText_UpdateFontSlot ), ((XObject)_this ));
}

/* 'C' function for method : 'Components::BaseText.Init()' */
void ComponentsBaseText_Init( ComponentsBaseText _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwPostSignal( EwNewSlot( _this, ComponentsBaseText_UpdateFontSlot ), ((XObject)_this ));
}

/* 'C' function for method : 'Components::BaseText.UpdateFontSlot()' */
void ComponentsBaseText_UpdateFontSlot( ComponentsBaseText _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EwLoadResource( &FontsNotoSansCjkJpMedium24pt, ResourcesFont ) == _this->Super1.Font )
    switch ( EwGetLanguage())
    {
      case TraditionalChinese :
        ViewsText_OnSetFont((ViewsText)_this, EwLoadResource( &FontsNotoSansCjkTcMedium24pt, 
        ResourcesFont ));
      break;

      default :; 
    }
  else
    if ( EwLoadResource( &FontsNotoSansCjkJpMedium28pt, ResourcesFont ) == _this->Super1.Font )
      switch ( EwGetLanguage())
      {
        case TraditionalChinese :
          ViewsText_OnSetFont((ViewsText)_this, EwLoadResource( &FontsNotoSansCjkTcMedium28pt, 
          ResourcesFont ));
        break;

        default :; 
      }
    else
      if ( EwLoadResource( &FontsNotoSansCjkTcMedium24pt, ResourcesFont ) == _this->Super1.Font )
        switch ( EwGetLanguage())
        {
          case TraditionalChinese :
          break;

          default : 
            ViewsText_OnSetFont((ViewsText)_this, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
            ResourcesFont ));
        }
      else
        if ( EwLoadResource( &FontsNotoSansCjkTcMedium28pt, ResourcesFont ) == _this->Super1.Font )
          switch ( EwGetLanguage())
          {
            case TraditionalChinese :
            break;

            default : 
              ViewsText_OnSetFont((ViewsText)_this, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
              ResourcesFont ));
          }
}

/* Variants derived from the class : 'Components::BaseText' */
EW_DEFINE_CLASS_VARIANTS( ComponentsBaseText )
EW_END_OF_CLASS_VARIANTS( ComponentsBaseText )

/* Virtual Method Table (VMT) for the class : 'Components::BaseText' */
EW_DEFINE_CLASS( ComponentsBaseText, ViewsText, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, "Components::BaseText" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  ViewsText_Draw,
  CoreView_HandleEvent,
  CoreView_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreView_ChangeViewState,
  ViewsText_OnSetBounds,
EW_END_OF_CLASS( ComponentsBaseText )

/* Embedded Wizard */
