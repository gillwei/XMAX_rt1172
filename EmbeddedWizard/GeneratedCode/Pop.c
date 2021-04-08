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
#include "_CoreGroup.h"
#include "_CorePropertyObserver.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DeviceInterfaceBluetoothDeviceClass.h"
#include "_DeviceInterfaceMotoConContext.h"
#include "_DeviceInterfaceWeatherDeviceClass.h"
#include "_PopPOP08_WeatherLoadingUI.h"
#include "_PopPOP09_BleConnectionErrorUI.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsText.h"
#include "_WeatherWEA01_Main.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Fonts.h"
#include "Pop.h"
#include "Resource.h"
#include "Strings.h"

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 10, 156 }, { 470, 187 }};
static const XRect _Const0001 = {{ 193, 54 }, { 287, 148 }};
static const XRect _Const0002 = {{ 10, 50 }, { 470, 236 }};

/* Initializer for the class 'Pop::POP08_WeatherLoadingUI' */
void PopPOP08_WeatherLoadingUI__Init( PopPOP08_WeatherLoadingUI _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( PopPOP08_WeatherLoadingUI );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->LoadingText, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->WeatherLoadingObserver, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->LoadingAnimation, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->ConnectionFailedTimer, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->MotoConConnectionEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( PopPOP08_WeatherLoadingUI );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->LoadingText, _Const0000 );
  ViewsText_OnSetString( &_this->LoadingText, EwLoadString( &StringsGEN_please_wait ));
  CoreRectView__OnSetBounds( &_this->LoadingAnimation, _Const0001 );
  ViewsImage_OnSetAnimated( &_this->LoadingAnimation, 1 );
  CoreTimer_OnSetPeriod( &_this->ConnectionFailedTimer, 20000 );
  CoreTimer_OnSetEnabled( &_this->ConnectionFailedTimer, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->LoadingText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LoadingAnimation ), 0 );
  ViewsText_OnSetFont( &_this->LoadingText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->WeatherLoadingObserver.OnEvent = EwNewSlot( _this, PopPOP08_WeatherLoadingUI_OnWeatherLoadingUpdateSlot );
  CorePropertyObserver_OnSetOutlet( &_this->WeatherLoadingObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass ), DeviceInterfaceWeatherDeviceClass_OnGetIsWeatherInfoReceived, 
  DeviceInterfaceWeatherDeviceClass_OnSetIsWeatherInfoReceived ));
  ViewsImage_OnSetBitmap( &_this->LoadingAnimation, EwLoadResource( &ResourceLoadingAnimation, 
  ResourcesBitmap ));
  _this->ConnectionFailedTimer.OnTrigger = EwNewSlot( _this, PopPOP08_WeatherLoadingUI_OnConnectionFailedUpdateSlot );
  _this->MotoConConnectionEventHandler.OnEvent = EwNewSlot( _this, PopPOP08_WeatherLoadingUI_OnMotoConConnectionUpdateEvent );
  CoreSystemEventHandler_OnSetEvent( &_this->MotoConConnectionEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->MotoConSystemEvent );

  /* Call the user defined constructor */
  PopPOP08_WeatherLoadingUI_Init( _this, aArg );
}

/* Re-Initializer for the class 'Pop::POP08_WeatherLoadingUI' */
void PopPOP08_WeatherLoadingUI__ReInit( PopPOP08_WeatherLoadingUI _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->LoadingText );
  CorePropertyObserver__ReInit( &_this->WeatherLoadingObserver );
  ViewsImage__ReInit( &_this->LoadingAnimation );
  CoreTimer__ReInit( &_this->ConnectionFailedTimer );
  CoreSystemEventHandler__ReInit( &_this->MotoConConnectionEventHandler );
}

/* Finalizer method for the class 'Pop::POP08_WeatherLoadingUI' */
void PopPOP08_WeatherLoadingUI__Done( PopPOP08_WeatherLoadingUI _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->LoadingText );
  CorePropertyObserver__Done( &_this->WeatherLoadingObserver );
  ViewsImage__Done( &_this->LoadingAnimation );
  CoreTimer__Done( &_this->ConnectionFailedTimer );
  CoreSystemEventHandler__Done( &_this->MotoConConnectionEventHandler );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void PopPOP08_WeatherLoadingUI_Init( PopPOP08_WeatherLoadingUI _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  DeviceInterfaceWeatherDeviceClass_SendWeatherInfoRequest( EwGetAutoObject( &DeviceInterfaceWeatherDevice, 
  DeviceInterfaceWeatherDeviceClass ));
  DeviceInterfaceWeatherDeviceClass_SendVehicleSettingRequest( EwGetAutoObject( 
  &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass ));
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void PopPOP08_WeatherLoadingUI_OnWeatherLoadingUpdateSlot( PopPOP08_WeatherLoadingUI _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass )->IsWeatherInfoReceived )
  {
    CoreTimer_OnSetEnabled( &_this->ConnectionFailedTimer, 0 );
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( WeatherWEA01_Main, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* 'C' function for method : 'Pop::POP08_WeatherLoadingUI.OnConnectionFailedUpdateSlot()' */
void PopPOP08_WeatherLoadingUI_OnConnectionFailedUpdateSlot( PopPOP08_WeatherLoadingUI _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->ConnectionFailedTimer, 0 );
  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( PopPOP09_BleConnectionErrorUI, 
  0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void PopPOP08_WeatherLoadingUI_OnMotoConConnectionUpdateEvent( PopPOP08_WeatherLoadingUI _this, 
  XObject sender )
{
  DeviceInterfaceMotoConContext MotoConContext;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  MotoConContext = EwCastObject( _this->MotoConConnectionEventHandler.Context, DeviceInterfaceMotoConContext );

  if ( EnumMotoConRxEventCONNECTION_STATUS == MotoConContext->RxEvent )
  {
    if ( !DeviceInterfaceBluetoothDeviceClass_IsMotoconConnected( EwGetAutoObject( 
        &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )))
    {
      EwSignal( EwNewSlot( _this, PopPOP08_WeatherLoadingUI_OnConnectionFailedUpdateSlot ), 
        ((XObject)_this ));
    }
  }
}

/* Variants derived from the class : 'Pop::POP08_WeatherLoadingUI' */
EW_DEFINE_CLASS_VARIANTS( PopPOP08_WeatherLoadingUI )
EW_END_OF_CLASS_VARIANTS( PopPOP08_WeatherLoadingUI )

/* Virtual Method Table (VMT) for the class : 'Pop::POP08_WeatherLoadingUI' */
EW_DEFINE_CLASS( PopPOP08_WeatherLoadingUI, ComponentsBaseMainBG, LoadingText, LoadingText, 
                 LoadingText, LoadingText, _None, _None, "Pop::POP08_WeatherLoadingUI" )
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
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( PopPOP08_WeatherLoadingUI )

/* Initializer for the class 'Pop::POP09_BleConnectionErrorUI' */
void PopPOP09_BleConnectionErrorUI__Init( PopPOP09_BleConnectionErrorUI _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( PopPOP09_BleConnectionErrorUI );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->ConnectionFailedMessage, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->CountDownTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( PopPOP09_BleConnectionErrorUI );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->ConnectionFailedMessage, _Const0002 );
  ViewsText_OnSetString( &_this->ConnectionFailedMessage, EwLoadString( &StringsPOP09_CONNECTION_FAILED ));
  CoreTimer_OnSetPeriod( &_this->CountDownTimer, 2000 );
  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->ConnectionFailedMessage ), 0 );
  ViewsText_OnSetFont( &_this->ConnectionFailedMessage, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->CountDownTimer.OnTrigger = EwNewSlot( _this, PopPOP09_BleConnectionErrorUI_OnLauncherScreenUpdateSlot );
}

/* Re-Initializer for the class 'Pop::POP09_BleConnectionErrorUI' */
void PopPOP09_BleConnectionErrorUI__ReInit( PopPOP09_BleConnectionErrorUI _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->ConnectionFailedMessage );
  CoreTimer__ReInit( &_this->CountDownTimer );
}

/* Finalizer method for the class 'Pop::POP09_BleConnectionErrorUI' */
void PopPOP09_BleConnectionErrorUI__Done( PopPOP09_BleConnectionErrorUI _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->ConnectionFailedMessage );
  CoreTimer__Done( &_this->CountDownTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* 'C' function for method : 'Pop::POP09_BleConnectionErrorUI.OnLauncherScreenUpdateSlot()' */
void PopPOP09_BleConnectionErrorUI_OnLauncherScreenUpdateSlot( PopPOP09_BleConnectionErrorUI _this, 
  XObject sender )
{
  ApplicationApplication App;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 0 );
  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
  {
    ApplicationApplication_ReturnToLauncher( App );
  }
}

/* Variants derived from the class : 'Pop::POP09_BleConnectionErrorUI' */
EW_DEFINE_CLASS_VARIANTS( PopPOP09_BleConnectionErrorUI )
EW_END_OF_CLASS_VARIANTS( PopPOP09_BleConnectionErrorUI )

/* Virtual Method Table (VMT) for the class : 'Pop::POP09_BleConnectionErrorUI' */
EW_DEFINE_CLASS( PopPOP09_BleConnectionErrorUI, ComponentsBaseMainBG, ConnectionFailedMessage, 
                 ConnectionFailedMessage, ConnectionFailedMessage, ConnectionFailedMessage, 
                 _None, _None, "Pop::POP09_BleConnectionErrorUI" )
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
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( PopPOP09_BleConnectionErrorUI )

/* Embedded Wizard */
