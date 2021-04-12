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
#include "_MenuUpDownPushButtonSet.h"
#include "_PopPOP01_PleaseWait.h"
#include "_PopPOP02_ConnectionError.h"
#include "_PopPOP07_TROUBLE_SHOOTING.h"
#include "_PopPOP08_WeatherLoadingUI.h"
#include "_PopPOP09_BleConnectionErrorUI.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "_WeatherWEA01_Main.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Fonts.h"
#include "Pop.h"
#include "Resource.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000038, /* ratio 92.86 % */
  0xB8001B00, 0x00092452, 0x00D20037, 0x040003A0, 0x9E002800, 0x0300043C, 0x18000C80,
  0x88341205, 0x87432150, 0xAC422510, 0x49A30318, 0x0001018C, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 10, 156 }, { 470, 187 }};
static const XRect _Const0001 = {{ 193, 54 }, { 287, 148 }};
static const XRect _Const0002 = {{ 10, 50 }, { 470, 236 }};
static const XRect _Const0003 = {{ 0, 0 }, { 480, 272 }};
static const XColor _Const0004 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0005 = {{ 10, 57 }, { 470, 91 }};
static const XRect _Const0006 = {{ 0, 0 }, { 480, 43 }};
static const XColor _Const0007 = { 0xFF, 0xF5, 0x00, 0xFF };
static const XRect _Const0008 = {{ 155, 5 }, { 191, 41 }};
static const XRect _Const0009 = {{ 191, 1 }, { 327, 42 }};
static const XRect _Const000A = {{ 215, 105 }, { 265, 155 }};
static const XRect _Const000B = {{ 296, 105 }, { 346, 155 }};
static const XRect _Const000C = {{ 134, 105 }, { 184, 155 }};
static const XRect _Const000D = {{ 165, 176 }, { 315, 259 }};
static const XStringRes _Const000E = { _StringsDefault0, 0x0002 };
static const XRect _Const000F = {{ 0, 44 }, { 480, 48 }};
static const XRect _Const0010 = {{ 10, 56 }, { 60, 106 }};
static const XRect _Const0011 = {{ 10, 127 }, { 60, 177 }};
static const XRect _Const0012 = {{ 10, 198 }, { 60, 248 }};
static const XRect _Const0013 = {{ 10, 4 }, { 470, 41 }};
static const XColor _Const0014 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const0015 = {{ 68, 50 }, { 440, 112 }};
static const XRect _Const0016 = {{ 68, 121 }, { 440, 183 }};
static const XRect _Const0017 = {{ 68, 192 }, { 440, 254 }};
static const XRect _Const0018 = {{ 0, 115 }, { 480, 119 }};
static const XRect _Const0019 = {{ 0, 186 }, { 480, 190 }};
static const XRect _Const001A = {{ 0, 257 }, { 480, 261 }};
static const XStringRes _Const001B = { _StringsDefault0, 0x000F };

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
  ViewsText_OnSetString( &_this->LoadingText, EwLoadString( &StringsGEN_PLEASE_WAIT ));
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

/* Initializer for the class 'Pop::POP02_ConnectionError' */
void PopPOP02_ConnectionError__Init( PopPOP02_ConnectionError _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( PopPOP02_ConnectionError );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->BlackBackground, &_this->_XObject, 0 );
  ViewsText__Init( &_this->CheckText, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->TopBar, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ErrorIcon, &_this->_XObject, 0 );
  ViewsText__Init( &_this->ConnectionErrText, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ErrorBTIcon, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ErrorNavigationIcon, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ErrorPhoneLockIcon, &_this->_XObject, 0 );
  MenuUpDownPushButtonSet__Init( &_this->UpDownPushButtonSet, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( PopPOP02_ConnectionError );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0003 );
  CoreRectView__OnSetBounds( &_this->BlackBackground, _Const0003 );
  ViewsRectangle_OnSetColor( &_this->BlackBackground, _Const0004 );
  CoreRectView__OnSetBounds( &_this->CheckText, _Const0005 );
  ViewsText_OnSetWrapText( &_this->CheckText, 0 );
  ViewsText_OnSetString( &_this->CheckText, EwLoadString( &StringsPOP02_PLEASE_CHECK ));
  CoreRectView__OnSetBounds( &_this->TopBar, _Const0006 );
  ViewsRectangle_OnSetColor( &_this->TopBar, _Const0007 );
  CoreRectView__OnSetBounds( &_this->ErrorIcon, _Const0008 );
  ViewsImage_OnSetAlignment( &_this->ErrorIcon, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter | ViewsImageAlignmentScaleToFit );
  ViewsImage_OnSetVisible( &_this->ErrorIcon, 1 );
  CoreRectView__OnSetBounds( &_this->ConnectionErrText, _Const0009 );
  ViewsText_OnSetAutoSize( &_this->ConnectionErrText, 1 );
  ViewsText_OnSetAlignment( &_this->ConnectionErrText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ConnectionErrText, EwLoadString( &StringsPOP02_CONNECTION_ERR ));
  ViewsText_OnSetColor( &_this->ConnectionErrText, _Const0004 );
  ViewsText_OnSetVisible( &_this->ConnectionErrText, 1 );
  CoreRectView__OnSetBounds( &_this->ErrorBTIcon, _Const000A );
  ViewsImage_OnSetAlignment( &_this->ErrorBTIcon, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  ViewsImage_OnSetVisible( &_this->ErrorBTIcon, 1 );
  CoreRectView__OnSetBounds( &_this->ErrorNavigationIcon, _Const000B );
  ViewsImage_OnSetAlignment( &_this->ErrorNavigationIcon, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  ViewsImage_OnSetVisible( &_this->ErrorNavigationIcon, 1 );
  CoreRectView__OnSetBounds( &_this->ErrorPhoneLockIcon, _Const000C );
  ViewsImage_OnSetAlignment( &_this->ErrorPhoneLockIcon, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  ViewsImage_OnSetVisible( &_this->ErrorPhoneLockIcon, 1 );
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const000D );
  _this->UpDownPushButtonSet.Super1.PassHomeKey = 1;
  _this->UpDownPushButtonSet.Super1.PassMagicKey = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->UpDownPushButtonSet, 1 );
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwGetVariantOfString( 
  &StringsGEN_OK ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwLoadString( 
  &StringsPOP02_DETAILS ));
  MenuUpDownPushButtonSet_OnSetDownButtonEnabled( &_this->UpDownPushButtonSet, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->BlackBackground ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CheckText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TopBar ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ErrorIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ConnectionErrText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ErrorBTIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ErrorNavigationIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ErrorPhoneLockIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UpDownPushButtonSet ), 0 );
  ViewsText_OnSetFont( &_this->CheckText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->ErrorIcon, EwLoadResource( &ResourceIconError, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->ConnectionErrText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->ErrorBTIcon, EwLoadResource( &ResourceIconErrorBT, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ErrorNavigationIcon, EwLoadResource( &ResourceIconErrorNavigation, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ErrorPhoneLockIcon, EwLoadResource( &ResourceIconErrorPhoneLock, 
  ResourcesBitmap ));
  _this->UpDownPushButtonSet.OnUpButtonActivated = EwNewSlot( _this, PopPOP02_ConnectionError_OnOkButtonActivatedSlot );
  _this->UpDownPushButtonSet.OnDownButtonActivated = EwNewSlot( _this, PopPOP02_ConnectionError_OnDetailsButtonActivatedSlot );

  /* Call the user defined constructor */
  PopPOP02_ConnectionError_Init( _this, aArg );
}

/* Re-Initializer for the class 'Pop::POP02_ConnectionError' */
void PopPOP02_ConnectionError__ReInit( PopPOP02_ConnectionError _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->BlackBackground );
  ViewsText__ReInit( &_this->CheckText );
  ViewsRectangle__ReInit( &_this->TopBar );
  ViewsImage__ReInit( &_this->ErrorIcon );
  ViewsText__ReInit( &_this->ConnectionErrText );
  ViewsImage__ReInit( &_this->ErrorBTIcon );
  ViewsImage__ReInit( &_this->ErrorNavigationIcon );
  ViewsImage__ReInit( &_this->ErrorPhoneLockIcon );
  MenuUpDownPushButtonSet__ReInit( &_this->UpDownPushButtonSet );
}

/* Finalizer method for the class 'Pop::POP02_ConnectionError' */
void PopPOP02_ConnectionError__Done( PopPOP02_ConnectionError _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->BlackBackground );
  ViewsText__Done( &_this->CheckText );
  ViewsRectangle__Done( &_this->TopBar );
  ViewsImage__Done( &_this->ErrorIcon );
  ViewsText__Done( &_this->ConnectionErrText );
  ViewsImage__Done( &_this->ErrorBTIcon );
  ViewsImage__Done( &_this->ErrorNavigationIcon );
  ViewsImage__Done( &_this->ErrorPhoneLockIcon );
  MenuUpDownPushButtonSet__Done( &_this->UpDownPushButtonSet );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void PopPOP02_ConnectionError_Init( PopPOP02_ConnectionError _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const000E ));
}

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void PopPOP02_ConnectionError_UpdateLayout( PopPOP02_ConnectionError _this, XPoint 
  aSize )
{
  XInt32 TextIconGapPixel;
  XInt32 TotalWidth;
  XInt32 Margin;
  XInt32 Width;
  XRect NewBounds;

  CoreGroup_UpdateLayout((CoreGroup)_this, aSize );
  TextIconGapPixel = 3;
  TotalWidth = ( EwGetRectW( _this->ErrorIcon.Super1.Bounds ) + TextIconGapPixel ) 
  + EwGetRectW( ViewsText_GetContentArea( &_this->ConnectionErrText ));
  Margin = ( EwGetRectW( _this->Super3.Bounds ) - TotalWidth ) / 2;
  Width = EwGetRectW( _this->ErrorIcon.Super1.Bounds );
  NewBounds = _this->ErrorIcon.Super1.Bounds;
  NewBounds.Point1.X = Margin;
  NewBounds.Point2.X = ( NewBounds.Point1.X + Width );
  CoreRectView__OnSetBounds( &_this->ErrorIcon, NewBounds );
  Width = EwGetRectW( _this->ConnectionErrText.Super1.Bounds );
  NewBounds = _this->ConnectionErrText.Super1.Bounds;
  NewBounds.Point1.X = ( _this->ErrorIcon.Super1.Bounds.Point2.X + TextIconGapPixel );
  NewBounds.Point2.X = ( NewBounds.Point1.X + Width );
  CoreRectView__OnSetBounds( &_this->ConnectionErrText, NewBounds );
}

/* 'C' function for method : 'Pop::POP02_ConnectionError.OnShortHomeKeyActivated()' */
void PopPOP02_ConnectionError_OnShortHomeKeyActivated( PopPOP02_ConnectionError _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* 'C' function for method : 'Pop::POP02_ConnectionError.OnLongHomeKeyActivated()' */
void PopPOP02_ConnectionError_OnLongHomeKeyActivated( PopPOP02_ConnectionError _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* 'C' function for method : 'Pop::POP02_ConnectionError.OnOkButtonActivatedSlot()' */
void PopPOP02_ConnectionError_OnOkButtonActivatedSlot( PopPOP02_ConnectionError _this, 
  XObject sender )
{
  ApplicationApplication App;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
  {
    ApplicationApplication_SwitchToHome( App, EnumHomeTypeVEHICLE_INFO );
  }
}

/* 'C' function for method : 'Pop::POP02_ConnectionError.OnDetailsButtonActivatedSlot()' */
void PopPOP02_ConnectionError_OnDetailsButtonActivatedSlot( PopPOP02_ConnectionError _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( PopPOP07_TROUBLE_SHOOTING, 
  0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* Variants derived from the class : 'Pop::POP02_ConnectionError' */
EW_DEFINE_CLASS_VARIANTS( PopPOP02_ConnectionError )
EW_END_OF_CLASS_VARIANTS( PopPOP02_ConnectionError )

/* Virtual Method Table (VMT) for the class : 'Pop::POP02_ConnectionError' */
EW_DEFINE_CLASS( PopPOP02_ConnectionError, ComponentsBaseComponent, BlackBackground, 
                 BlackBackground, BlackBackground, BlackBackground, _None, _None, 
                 "Pop::POP02_ConnectionError" )
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
  PopPOP02_ConnectionError_UpdateLayout,
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
  PopPOP02_ConnectionError_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  PopPOP02_ConnectionError_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseComponent_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( PopPOP02_ConnectionError )

/* Initializer for the class 'Pop::POP07_TROUBLE_SHOOTING' */
void PopPOP07_TROUBLE_SHOOTING__Init( PopPOP07_TROUBLE_SHOOTING _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( PopPOP07_TROUBLE_SHOOTING );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->Divider, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ErrorPhoneLockIcon, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ErrorBTIcon, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ErrorNavigationIcon, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TroubleShootingText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TroubleShootingText1, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TroubleShootingText2, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TroubleShootingText3, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Divider1, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Divider2, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Divider3, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( PopPOP07_TROUBLE_SHOOTING );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Super1.BlackBG, _Const0003 );
  CoreRectView__OnSetBounds( &_this->Divider, _Const000F );
  ViewsImage_OnSetAlignment( &_this->Divider, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  CoreRectView__OnSetBounds( &_this->ErrorPhoneLockIcon, _Const0010 );
  ViewsImage_OnSetAlignment( &_this->ErrorPhoneLockIcon, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  ViewsImage_OnSetVisible( &_this->ErrorPhoneLockIcon, 1 );
  CoreRectView__OnSetBounds( &_this->ErrorBTIcon, _Const0011 );
  ViewsImage_OnSetAlignment( &_this->ErrorBTIcon, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  ViewsImage_OnSetVisible( &_this->ErrorBTIcon, 1 );
  CoreRectView__OnSetBounds( &_this->ErrorNavigationIcon, _Const0012 );
  ViewsImage_OnSetAlignment( &_this->ErrorNavigationIcon, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  ViewsImage_OnSetVisible( &_this->ErrorNavigationIcon, 1 );
  CoreRectView__OnSetBounds( &_this->TroubleShootingText, _Const0013 );
  ViewsText_OnSetAutoSize( &_this->TroubleShootingText, 1 );
  ViewsText_OnSetAlignment( &_this->TroubleShootingText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TroubleShootingText, EwLoadString( &StringsPOP07_TROUBLE_SHOOTING ));
  ViewsText_OnSetColor( &_this->TroubleShootingText, _Const0014 );
  ViewsText_OnSetVisible( &_this->TroubleShootingText, 1 );
  CoreRectView__OnSetBounds( &_this->TroubleShootingText1, _Const0015 );
  ViewsText_OnSetAutoSize( &_this->TroubleShootingText1, 0 );
  ViewsText_OnSetAlignment( &_this->TroubleShootingText1, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TroubleShootingText1, EwLoadString( &StringsPOP07_UNLOCK_PHONE ));
  ViewsText_OnSetColor( &_this->TroubleShootingText1, _Const0014 );
  ViewsText_OnSetVisible( &_this->TroubleShootingText1, 1 );
  CoreRectView__OnSetBounds( &_this->TroubleShootingText2, _Const0016 );
  ViewsText_OnSetAutoSize( &_this->TroubleShootingText2, 0 );
  ViewsText_OnSetAlignment( &_this->TroubleShootingText2, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TroubleShootingText2, EwLoadString( &StringsPOP07_TURN_ON_BT ));
  ViewsText_OnSetColor( &_this->TroubleShootingText2, _Const0014 );
  ViewsText_OnSetVisible( &_this->TroubleShootingText2, 1 );
  CoreRectView__OnSetBounds( &_this->TroubleShootingText3, _Const0017 );
  ViewsText_OnSetAutoSize( &_this->TroubleShootingText3, 0 );
  ViewsText_OnSetAlignment( &_this->TroubleShootingText3, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TroubleShootingText3, EwLoadString( &StringsPOP07_LAUNCH_APP ));
  ViewsText_OnSetColor( &_this->TroubleShootingText3, _Const0014 );
  ViewsText_OnSetVisible( &_this->TroubleShootingText3, 1 );
  CoreRectView__OnSetBounds( &_this->Divider1, _Const0018 );
  ViewsImage_OnSetAlignment( &_this->Divider1, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  CoreRectView__OnSetBounds( &_this->Divider2, _Const0019 );
  ViewsImage_OnSetAlignment( &_this->Divider2, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  CoreRectView__OnSetBounds( &_this->Divider3, _Const001A );
  ViewsImage_OnSetAlignment( &_this->Divider3, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ErrorPhoneLockIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ErrorBTIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ErrorNavigationIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TroubleShootingText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TroubleShootingText1 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TroubleShootingText2 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TroubleShootingText3 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider1 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider2 ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider3 ), 0 );
  ViewsImage_OnSetBitmap( &_this->Divider, EwLoadResource( &ResourceSplitLineLarge, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ErrorPhoneLockIcon, EwLoadResource( &ResourceIconErrorPhoneLock, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ErrorBTIcon, EwLoadResource( &ResourceIconErrorBT, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ErrorNavigationIcon, EwLoadResource( &ResourceIconErrorNavigation, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->TroubleShootingText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->TroubleShootingText1, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->TroubleShootingText2, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->TroubleShootingText3, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->Divider1, EwLoadResource( &ResourceSplitLineMiddle, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Divider2, EwLoadResource( &ResourceSplitLineMiddle, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Divider3, EwLoadResource( &ResourceSplitLineMiddle, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'Pop::POP07_TROUBLE_SHOOTING' */
void PopPOP07_TROUBLE_SHOOTING__ReInit( PopPOP07_TROUBLE_SHOOTING _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->Divider );
  ViewsImage__ReInit( &_this->ErrorPhoneLockIcon );
  ViewsImage__ReInit( &_this->ErrorBTIcon );
  ViewsImage__ReInit( &_this->ErrorNavigationIcon );
  ViewsText__ReInit( &_this->TroubleShootingText );
  ViewsText__ReInit( &_this->TroubleShootingText1 );
  ViewsText__ReInit( &_this->TroubleShootingText2 );
  ViewsText__ReInit( &_this->TroubleShootingText3 );
  ViewsImage__ReInit( &_this->Divider1 );
  ViewsImage__ReInit( &_this->Divider2 );
  ViewsImage__ReInit( &_this->Divider3 );
}

/* Finalizer method for the class 'Pop::POP07_TROUBLE_SHOOTING' */
void PopPOP07_TROUBLE_SHOOTING__Done( PopPOP07_TROUBLE_SHOOTING _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->Divider );
  ViewsImage__Done( &_this->ErrorPhoneLockIcon );
  ViewsImage__Done( &_this->ErrorBTIcon );
  ViewsImage__Done( &_this->ErrorNavigationIcon );
  ViewsText__Done( &_this->TroubleShootingText );
  ViewsText__Done( &_this->TroubleShootingText1 );
  ViewsText__Done( &_this->TroubleShootingText2 );
  ViewsText__Done( &_this->TroubleShootingText3 );
  ViewsImage__Done( &_this->Divider1 );
  ViewsImage__Done( &_this->Divider2 );
  ViewsImage__Done( &_this->Divider3 );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* 'C' function for method : 'Pop::POP07_TROUBLE_SHOOTING.OnShortEnterKeyActivated()' */
void PopPOP07_TROUBLE_SHOOTING_OnShortEnterKeyActivated( PopPOP07_TROUBLE_SHOOTING _this )
{
  ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
  {
    ApplicationApplication_SwitchToHome( App, EnumHomeTypeVEHICLE_INFO );
  }
}

/* 'C' function for method : 'Pop::POP07_TROUBLE_SHOOTING.OnLongHomeKeyActivated()' */
void PopPOP07_TROUBLE_SHOOTING_OnLongHomeKeyActivated( PopPOP07_TROUBLE_SHOOTING _this )
{
  ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
  {
    ApplicationApplication_SwitchToHome( App, EnumHomeTypeVEHICLE_INFO );
  }
}

/* Variants derived from the class : 'Pop::POP07_TROUBLE_SHOOTING' */
EW_DEFINE_CLASS_VARIANTS( PopPOP07_TROUBLE_SHOOTING )
EW_END_OF_CLASS_VARIANTS( PopPOP07_TROUBLE_SHOOTING )

/* Virtual Method Table (VMT) for the class : 'Pop::POP07_TROUBLE_SHOOTING' */
EW_DEFINE_CLASS( PopPOP07_TROUBLE_SHOOTING, ComponentsBaseMainBG, Divider, Divider, 
                 Divider, Divider, _None, _None, "Pop::POP07_TROUBLE_SHOOTING" )
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
  PopPOP07_TROUBLE_SHOOTING_OnShortEnterKeyActivated,
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  PopPOP07_TROUBLE_SHOOTING_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( PopPOP07_TROUBLE_SHOOTING )

/* Initializer for the class 'Pop::POP01_PleaseWait' */
void PopPOP01_PleaseWait__Init( PopPOP01_PleaseWait _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( PopPOP01_PleaseWait );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->LoadingText, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->LoadingAnimation, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->ConnectionFailedTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( PopPOP01_PleaseWait );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Super1.BlackBG, _Const0003 );
  ViewsRectangle_OnSetColor( &_this->Super1.BlackBG, _Const0004 );
  CoreRectView__OnSetBounds( &_this->LoadingText, _Const0000 );
  ViewsText_OnSetString( &_this->LoadingText, EwLoadString( &StringsGEN_PLEASE_WAIT ));
  CoreRectView__OnSetBounds( &_this->LoadingAnimation, _Const0001 );
  ViewsImage_OnSetAnimated( &_this->LoadingAnimation, 1 );
  CoreTimer_OnSetPeriod( &_this->ConnectionFailedTimer, 0 );
  CoreTimer_OnSetBegin( &_this->ConnectionFailedTimer, 5000 );
  CoreTimer_OnSetEnabled( &_this->ConnectionFailedTimer, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->LoadingText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LoadingAnimation ), 0 );
  ViewsText_OnSetFont( &_this->LoadingText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->LoadingAnimation, EwLoadResource( &ResourceLoadingAnimation, 
  ResourcesBitmap ));
  _this->ConnectionFailedTimer.OnTrigger = EwNewSlot( _this, PopPOP01_PleaseWait_OnConnectionFailedUpdateSlot );

  /* Call the user defined constructor */
  PopPOP01_PleaseWait_Init( _this, aArg );
}

/* Re-Initializer for the class 'Pop::POP01_PleaseWait' */
void PopPOP01_PleaseWait__ReInit( PopPOP01_PleaseWait _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->LoadingText );
  ViewsImage__ReInit( &_this->LoadingAnimation );
  CoreTimer__ReInit( &_this->ConnectionFailedTimer );
}

/* Finalizer method for the class 'Pop::POP01_PleaseWait' */
void PopPOP01_PleaseWait__Done( PopPOP01_PleaseWait _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->LoadingText );
  ViewsImage__Done( &_this->LoadingAnimation );
  CoreTimer__Done( &_this->ConnectionFailedTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void PopPOP01_PleaseWait_Init( PopPOP01_PleaseWait _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const001B ));
}

/* 'C' function for method : 'Pop::POP01_PleaseWait.OnShortHomeKeyActivated()' */
void PopPOP01_PleaseWait_OnShortHomeKeyActivated( PopPOP01_PleaseWait _this )
{
  ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
  {
    ApplicationApplication_SwitchToMeterHome( App );
  }
}

/* 'C' function for method : 'Pop::POP01_PleaseWait.OnLongHomeKeyActivated()' */
void PopPOP01_PleaseWait_OnLongHomeKeyActivated( PopPOP01_PleaseWait _this )
{
  ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
  {
    ApplicationApplication_SwitchToMeterHome( App );
  }
}

/* 'C' function for method : 'Pop::POP01_PleaseWait.OnConnectionFailedUpdateSlot()' */
void PopPOP01_PleaseWait_OnConnectionFailedUpdateSlot( PopPOP01_PleaseWait _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Super5.Owner != 0 )
  {
    CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)EwNewObject( PopPOP02_ConnectionError, 
    0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* Variants derived from the class : 'Pop::POP01_PleaseWait' */
EW_DEFINE_CLASS_VARIANTS( PopPOP01_PleaseWait )
EW_END_OF_CLASS_VARIANTS( PopPOP01_PleaseWait )

/* Virtual Method Table (VMT) for the class : 'Pop::POP01_PleaseWait' */
EW_DEFINE_CLASS( PopPOP01_PleaseWait, ComponentsBaseMainBG, LoadingText, LoadingText, 
                 LoadingText, LoadingText, _None, _None, "Pop::POP01_PleaseWait" )
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
  PopPOP01_PleaseWait_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  PopPOP01_PleaseWait_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( PopPOP01_PleaseWait )

/* Embedded Wizard */
