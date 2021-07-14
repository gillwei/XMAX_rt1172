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
#include "_ComponentsBaseText.h"
#include "_CoreGroup.h"
#include "_CorePropertyObserver.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DeviceInterfaceBluetoothDeviceClass.h"
#include "_DeviceInterfaceMotoConContext.h"
#include "_DeviceInterfaceNavigationDeviceClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_DeviceInterfaceWeatherDeviceClass.h"
#include "_MenuUpDownPushButtonSet.h"
#include "_PopPOP01_PleaseWait.h"
#include "_PopPOP02_ConnectionError.h"
#include "_PopPOP03_HomeOfficeSettingError.h"
#include "_PopPOP04_Reset.h"
#include "_PopPOP07_TROUBLE_SHOOTING.h"
#include "_PopPOP08_WeatherLoadingUI.h"
#include "_PopPOP09_POP14_BleConnectionErrorUI.h"
#include "_PopPOP16_NaviLoadingUI.h"
#include "_PopPOP17_AppInitSettingError.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_WeatherWEA01_Main.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Fonts.h"
#include "Pop.h"
#include "Resource.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault0[] =
{
  0x0000008A, /* ratio 60.87 % */
  0xB8001100, 0x800A0452, 0xC20C0027, 0x80038000, 0x0B0305C3, 0x60084C1E, 0x2F000E61,
  0x4000C400, 0x810021C3, 0x54220D04, 0x47864008, 0x56471290, 0x64E37004, 0x17149144,
  0x1288746E, 0x348EC926, 0xB8344E5F, 0x90CE65B1, 0xF0CE573B, 0x00203448, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 10, 156 }, { 470, 187 }};
static const XRect _Const0001 = {{ 193, 54 }, { 287, 148 }};
static const XStringRes _Const0002 = { _StringsDefault0, 0x0002 };
static const XRect _Const0003 = {{ 10, 49 }, { 470, 235 }};
static const XStringRes _Const0004 = { _StringsDefault0, 0x000A };
static const XRect _Const0005 = {{ 0, 0 }, { 480, 272 }};
static const XColor _Const0006 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0007 = {{ 10, 55 }, { 470, 89 }};
static const XRect _Const0008 = {{ 0, 0 }, { 480, 43 }};
static const XColor _Const0009 = { 0xFF, 0xF5, 0x00, 0xFF };
static const XRect _Const000A = {{ 155, 5 }, { 191, 41 }};
static const XRect _Const000B = {{ 144, 2 }, { 375, 43 }};
static const XRect _Const000C = {{ 215, 105 }, { 265, 155 }};
static const XRect _Const000D = {{ 296, 105 }, { 346, 155 }};
static const XRect _Const000E = {{ 134, 105 }, { 184, 155 }};
static const XRect _Const000F = {{ 165, 176 }, { 315, 259 }};
static const XStringRes _Const0010 = { _StringsDefault0, 0x0015 };
static const XRect _Const0011 = {{ 0, 44 }, { 480, 48 }};
static const XRect _Const0012 = {{ 10, 56 }, { 60, 106 }};
static const XRect _Const0013 = {{ 10, 127 }, { 60, 177 }};
static const XRect _Const0014 = {{ 10, 198 }, { 60, 248 }};
static const XRect _Const0015 = {{ 10, 4 }, { 470, 41 }};
static const XColor _Const0016 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const0017 = {{ 68, 49 }, { 440, 111 }};
static const XRect _Const0018 = {{ 68, 120 }, { 440, 182 }};
static const XRect _Const0019 = {{ 68, 191 }, { 440, 253 }};
static const XRect _Const001A = {{ 0, 115 }, { 480, 119 }};
static const XRect _Const001B = {{ 0, 186 }, { 480, 190 }};
static const XRect _Const001C = {{ 0, 257 }, { 480, 261 }};
static const XStringRes _Const001D = { _StringsDefault0, 0x001D };
static const XStringRes _Const001E = { _StringsDefault0, 0x0025 };
static const XRect _Const001F = {{ 10, 46 }, { 470, 170 }};
static const XRect _Const0020 = {{ 0, 36 }, { 480, 38 }};
static const XStringRes _Const0021 = { _StringsDefault0, 0x002D };
static const XRect _Const0022 = {{ 10, 50 }, { 470, 236 }};
static const XStringRes _Const0023 = { _StringsDefault0, 0x0035 };
static const XStringRes _Const0024 = { _StringsDefault0, 0x003D };
static const XRect _Const0025 = {{ 0, 0 }, { 480, 234 }};
static const XRect _Const0026 = {{ 0, 144 }, { 480, 234 }};
static const XRect _Const0027 = {{ 0, 0 }, { 480, 144 }};
static const XRect _Const0028 = {{ 10, 118 }, { 470, 149 }};
static const XRect _Const0029 = {{ 193, 18 }, { 287, 112 }};

/* Initializer for the class 'Pop::POP08_WeatherLoadingUI' */
void PopPOP08_WeatherLoadingUI__Init( PopPOP08_WeatherLoadingUI _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( PopPOP08_WeatherLoadingUI );

  /* ... then construct all embedded objects */
  ComponentsBaseText__Init( &_this->LoadingText, &_this->_.XObject, 0 );
  CorePropertyObserver__Init( &_this->WeatherLoadingObserver, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->LoadingAnimation, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->ConnectionFailedTimer, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->MotoConConnectionEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( PopPOP08_WeatherLoadingUI );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->LoadingText, _Const0000 );
  ViewsText_OnSetString((ViewsText)&_this->LoadingText, EwGetVariantOfString( &StringsGEN_PLEASE_WAIT ));
  CoreRectView__OnSetBounds( &_this->LoadingAnimation, _Const0001 );
  ViewsImage_OnSetAnimated( &_this->LoadingAnimation, 1 );
  CoreTimer_OnSetPeriod( &_this->ConnectionFailedTimer, 20000 );
  CoreTimer_OnSetEnabled( &_this->ConnectionFailedTimer, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->LoadingText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LoadingAnimation ), 0 );
  ViewsText_OnSetFont((ViewsText)&_this->LoadingText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
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
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ComponentsBaseText__ReInit( &_this->LoadingText );
  CorePropertyObserver__ReInit( &_this->WeatherLoadingObserver );
  ViewsImage__ReInit( &_this->LoadingAnimation );
  CoreTimer__ReInit( &_this->ConnectionFailedTimer );
  CoreSystemEventHandler__ReInit( &_this->MotoConConnectionEventHandler );

  /* ... and re-initialize objects, variables, properties, etc. */
  ViewsText_OnSetString((ViewsText)&_this->LoadingText, EwGetVariantOfString( &StringsGEN_PLEASE_WAIT ));
  ViewsText_OnSetFont((ViewsText)&_this->LoadingText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Finalizer method for the class 'Pop::POP08_WeatherLoadingUI' */
void PopPOP08_WeatherLoadingUI__Done( PopPOP08_WeatherLoadingUI _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ComponentsBaseText__Done( &_this->LoadingText );
  CorePropertyObserver__Done( &_this->WeatherLoadingObserver );
  ViewsImage__Done( &_this->LoadingAnimation );
  CoreTimer__Done( &_this->ConnectionFailedTimer );
  CoreSystemEventHandler__Done( &_this->MotoConConnectionEventHandler );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void PopPOP08_WeatherLoadingUI_Init( PopPOP08_WeatherLoadingUI _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0002 ));
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
    CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)EwNewObject( WeatherWEA01_Main, 
    0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* 'C' function for method : 'Pop::POP08_WeatherLoadingUI.OnConnectionFailedUpdateSlot()' */
void PopPOP08_WeatherLoadingUI_OnConnectionFailedUpdateSlot( PopPOP08_WeatherLoadingUI _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->ConnectionFailedTimer, 0 );
  CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( PopPOP09_POP14_BleConnectionErrorUI, 
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

  if (( EnumMotoConRxEventCONNECTION_STATUS == MotoConContext->RxEvent ) && !DeviceInterfaceBluetoothDeviceClass_IsMotoconConnected( 
      EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )))
    EwSignal( EwNewSlot( _this, PopPOP08_WeatherLoadingUI_OnConnectionFailedUpdateSlot ), 
      ((XObject)_this ));
}

/* Variants derived from the class : 'Pop::POP08_WeatherLoadingUI' */
EW_DEFINE_CLASS_VARIANTS( PopPOP08_WeatherLoadingUI )
EW_END_OF_CLASS_VARIANTS( PopPOP08_WeatherLoadingUI )

/* Virtual Method Table (VMT) for the class : 'Pop::POP08_WeatherLoadingUI' */
EW_DEFINE_CLASS( PopPOP08_WeatherLoadingUI, ComponentsBaseMainBG, LoadingText, LoadingText, 
                 LoadingText, LoadingText, _.VMT, _.VMT, "Pop::POP08_WeatherLoadingUI" )
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
EW_END_OF_CLASS( PopPOP08_WeatherLoadingUI )

/* Initializer for the class 'Pop::POP09_POP14_BleConnectionErrorUI' */
void PopPOP09_POP14_BleConnectionErrorUI__Init( PopPOP09_POP14_BleConnectionErrorUI _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( PopPOP09_POP14_BleConnectionErrorUI );

  /* ... then construct all embedded objects */
  ComponentsBaseText__Init( &_this->ConnectionFailedMessage, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->CountDownTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( PopPOP09_POP14_BleConnectionErrorUI );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->ConnectionFailedMessage, _Const0003 );
  ViewsText_OnSetWrapText((ViewsText)&_this->ConnectionFailedMessage, 1 );
  ViewsText_OnSetString((ViewsText)&_this->ConnectionFailedMessage, EwGetVariantOfString( 
  &StringsPOP09_CONNECTION_FAILED ));
  CoreTimer_OnSetPeriod( &_this->CountDownTimer, 2000 );
  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->ConnectionFailedMessage ), 0 );
  ViewsText_OnSetFont((ViewsText)&_this->ConnectionFailedMessage, EwLoadResource( 
  &FontsNotoSansCjkJpMedium24pt, ResourcesFont ));
  _this->CountDownTimer.OnTrigger = EwNewSlot( _this, PopPOP09_POP14_BleConnectionErrorUI_OnCountDownTimeoutSlot );

  /* Call the user defined constructor */
  PopPOP09_POP14_BleConnectionErrorUI_Init( _this, aArg );
}

/* Re-Initializer for the class 'Pop::POP09_POP14_BleConnectionErrorUI' */
void PopPOP09_POP14_BleConnectionErrorUI__ReInit( PopPOP09_POP14_BleConnectionErrorUI _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ComponentsBaseText__ReInit( &_this->ConnectionFailedMessage );
  CoreTimer__ReInit( &_this->CountDownTimer );

  /* ... and re-initialize objects, variables, properties, etc. */
  ViewsText_OnSetString((ViewsText)&_this->ConnectionFailedMessage, EwGetVariantOfString( 
  &StringsPOP09_CONNECTION_FAILED ));
  ViewsText_OnSetFont((ViewsText)&_this->ConnectionFailedMessage, EwLoadResource( 
  &FontsNotoSansCjkJpMedium24pt, ResourcesFont ));
}

/* Finalizer method for the class 'Pop::POP09_POP14_BleConnectionErrorUI' */
void PopPOP09_POP14_BleConnectionErrorUI__Done( PopPOP09_POP14_BleConnectionErrorUI _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ComponentsBaseText__Done( &_this->ConnectionFailedMessage );
  CoreTimer__Done( &_this->CountDownTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void PopPOP09_POP14_BleConnectionErrorUI_Init( PopPOP09_POP14_BleConnectionErrorUI _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0004 ));
}

/* 'C' function for method : 'Pop::POP09_POP14_BleConnectionErrorUI.OnCountDownTimeoutSlot()' */
void PopPOP09_POP14_BleConnectionErrorUI_OnCountDownTimeoutSlot( PopPOP09_POP14_BleConnectionErrorUI _this, 
  XObject sender )
{
  ApplicationApplication App;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 0 );
  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
    ApplicationApplication_ReturnToLauncher( App );
}

/* Variants derived from the class : 'Pop::POP09_POP14_BleConnectionErrorUI' */
EW_DEFINE_CLASS_VARIANTS( PopPOP09_POP14_BleConnectionErrorUI )
EW_END_OF_CLASS_VARIANTS( PopPOP09_POP14_BleConnectionErrorUI )

/* Virtual Method Table (VMT) for the class : 'Pop::POP09_POP14_BleConnectionErrorUI' */
EW_DEFINE_CLASS( PopPOP09_POP14_BleConnectionErrorUI, ComponentsBaseMainBG, ConnectionFailedMessage, 
                 ConnectionFailedMessage, ConnectionFailedMessage, ConnectionFailedMessage, 
                 _.VMT, _.VMT, "Pop::POP09_POP14_BleConnectionErrorUI" )
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
EW_END_OF_CLASS( PopPOP09_POP14_BleConnectionErrorUI )

/* Initializer for the class 'Pop::POP02_ConnectionError' */
void PopPOP02_ConnectionError__Init( PopPOP02_ConnectionError _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( PopPOP02_ConnectionError );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->BlackBackground, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->CheckText, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->TopBar, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ErrorIcon, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->ConnectionErrText, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ErrorBTIcon, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ErrorNavigationIcon, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ErrorPhoneLockIcon, &_this->_.XObject, 0 );
  MenuUpDownPushButtonSet__Init( &_this->UpDownPushButtonSet, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( PopPOP02_ConnectionError );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0005 );
  CoreRectView__OnSetBounds( &_this->BlackBackground, _Const0005 );
  ViewsRectangle_OnSetColor( &_this->BlackBackground, _Const0006 );
  CoreRectView__OnSetBounds( &_this->CheckText, _Const0007 );
  ViewsText_OnSetWrapText((ViewsText)&_this->CheckText, 0 );
  ViewsText_OnSetString((ViewsText)&_this->CheckText, EwGetVariantOfString( &StringsPOP02_PLEASE_CHECK ));
  CoreRectView__OnSetBounds( &_this->TopBar, _Const0008 );
  ViewsRectangle_OnSetColor( &_this->TopBar, _Const0009 );
  CoreRectView__OnSetBounds( &_this->ErrorIcon, _Const000A );
  ViewsImage_OnSetAlignment( &_this->ErrorIcon, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter | ViewsImageAlignmentScaleToFit );
  ViewsImage_OnSetVisible( &_this->ErrorIcon, 1 );
  CoreRectView__OnSetBounds( &_this->ConnectionErrText, _Const000B );
  ViewsText_OnSetAutoSize((ViewsText)&_this->ConnectionErrText, 1 );
  ViewsText_OnSetAlignment((ViewsText)&_this->ConnectionErrText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString((ViewsText)&_this->ConnectionErrText, EwGetVariantOfString( 
  &StringsPOP02_CONNECTION_ERR ));
  ViewsText_OnSetColor((ViewsText)&_this->ConnectionErrText, _Const0006 );
  ViewsText_OnSetVisible((ViewsText)&_this->ConnectionErrText, 1 );
  CoreRectView__OnSetBounds( &_this->ErrorBTIcon, _Const000C );
  ViewsImage_OnSetAlignment( &_this->ErrorBTIcon, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  ViewsImage_OnSetVisible( &_this->ErrorBTIcon, 1 );
  CoreRectView__OnSetBounds( &_this->ErrorNavigationIcon, _Const000D );
  ViewsImage_OnSetAlignment( &_this->ErrorNavigationIcon, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  ViewsImage_OnSetVisible( &_this->ErrorNavigationIcon, 1 );
  CoreRectView__OnSetBounds( &_this->ErrorPhoneLockIcon, _Const000E );
  ViewsImage_OnSetAlignment( &_this->ErrorPhoneLockIcon, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  ViewsImage_OnSetVisible( &_this->ErrorPhoneLockIcon, 1 );
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const000F );
  _this->UpDownPushButtonSet.Super1.PassHomeKey = 1;
  _this->UpDownPushButtonSet.Super1.PassMagicKey = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->UpDownPushButtonSet, 1 );
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwGetVariantOfString( 
  &StringsGEN_OK ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwGetVariantOfString( 
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
  ViewsText_OnSetFont((ViewsText)&_this->CheckText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->ErrorIcon, EwLoadResource( &ResourceIconError, 
  ResourcesBitmap ));
  ViewsText_OnSetFont((ViewsText)&_this->ConnectionErrText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
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
  ComponentsBaseComponent__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->BlackBackground );
  ComponentsBaseText__ReInit( &_this->CheckText );
  ViewsRectangle__ReInit( &_this->TopBar );
  ViewsImage__ReInit( &_this->ErrorIcon );
  ComponentsBaseText__ReInit( &_this->ConnectionErrText );
  ViewsImage__ReInit( &_this->ErrorBTIcon );
  ViewsImage__ReInit( &_this->ErrorNavigationIcon );
  ViewsImage__ReInit( &_this->ErrorPhoneLockIcon );
  MenuUpDownPushButtonSet__ReInit( &_this->UpDownPushButtonSet );

  /* ... and re-initialize objects, variables, properties, etc. */
  ViewsText_OnSetString((ViewsText)&_this->CheckText, EwGetVariantOfString( &StringsPOP02_PLEASE_CHECK ));
  ViewsText_OnSetString((ViewsText)&_this->ConnectionErrText, EwGetVariantOfString( 
  &StringsPOP02_CONNECTION_ERR ));
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwGetVariantOfString( 
  &StringsGEN_OK ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwGetVariantOfString( 
  &StringsPOP02_DETAILS ));
  ViewsText_OnSetFont((ViewsText)&_this->CheckText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont((ViewsText)&_this->ConnectionErrText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));

  /* Call the user defined re-constructor of the class */
  PopPOP02_ConnectionError_ReInit( _this );
}

/* Finalizer method for the class 'Pop::POP02_ConnectionError' */
void PopPOP02_ConnectionError__Done( PopPOP02_ConnectionError _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->BlackBackground );
  ComponentsBaseText__Done( &_this->CheckText );
  ViewsRectangle__Done( &_this->TopBar );
  ViewsImage__Done( &_this->ErrorIcon );
  ComponentsBaseText__Done( &_this->ConnectionErrText );
  ViewsImage__Done( &_this->ErrorBTIcon );
  ViewsImage__Done( &_this->ErrorNavigationIcon );
  ViewsImage__Done( &_this->ErrorPhoneLockIcon );
  MenuUpDownPushButtonSet__Done( &_this->UpDownPushButtonSet );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_.Super );
}

/* 'C' function for method : 'Pop::POP02_ConnectionError.ReInit()' */
void PopPOP02_ConnectionError_ReInit( PopPOP02_ConnectionError _this )
{
  CoreGroup_InvalidateLayout((CoreGroup)_this );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void PopPOP02_ConnectionError_Init( PopPOP02_ConnectionError _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0010 ));
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
  XInt32 TotalWidth;
  XInt32 Margin;
  XInt32 Width;
  XRect NewBounds;

  CoreGroup_UpdateLayout((CoreGroup)_this, aSize );
  TotalWidth = ( EwGetRectW( _this->ErrorIcon.Super1.Bounds ) + 3 ) + EwGetRectW( 
  ViewsText_GetContentArea((ViewsText)&_this->ConnectionErrText ));
  Margin = ( EwGetRectW( _this->Super3.Bounds ) - TotalWidth ) / 2;
  Width = EwGetRectW( _this->ErrorIcon.Super1.Bounds );
  NewBounds = _this->ErrorIcon.Super1.Bounds;
  NewBounds.Point1.X = Margin;
  NewBounds.Point2.X = ( NewBounds.Point1.X + Width );
  CoreRectView__OnSetBounds( &_this->ErrorIcon, NewBounds );
  Width = EwGetRectW( _this->ConnectionErrText.Super2.Bounds );
  NewBounds = _this->ConnectionErrText.Super2.Bounds;
  NewBounds.Point1.X = ( _this->ErrorIcon.Super1.Bounds.Point2.X + 3 );
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
    ApplicationApplication_SwitchToHome( App, EnumHomeTypeVEHICLE_INFO );
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
                 BlackBackground, BlackBackground, BlackBackground, _.VMT, _.VMT, 
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
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  PopPOP02_ConnectionError_UpdateLayout,
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
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( PopPOP07_TROUBLE_SHOOTING );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->Divider, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ErrorPhoneLockIcon, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ErrorBTIcon, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ErrorNavigationIcon, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->TroubleShootingTitle, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->TroubleShootingText1, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->TroubleShootingText2, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->TroubleShootingText3, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Divider1, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Divider2, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Divider3, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( PopPOP07_TROUBLE_SHOOTING );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Super1.BlackBG, _Const0005 );
  CoreRectView__OnSetBounds( &_this->Divider, _Const0011 );
  ViewsImage_OnSetAlignment( &_this->Divider, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  CoreRectView__OnSetBounds( &_this->ErrorPhoneLockIcon, _Const0012 );
  ViewsImage_OnSetAlignment( &_this->ErrorPhoneLockIcon, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  ViewsImage_OnSetVisible( &_this->ErrorPhoneLockIcon, 1 );
  CoreRectView__OnSetBounds( &_this->ErrorBTIcon, _Const0013 );
  ViewsImage_OnSetAlignment( &_this->ErrorBTIcon, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  ViewsImage_OnSetVisible( &_this->ErrorBTIcon, 1 );
  CoreRectView__OnSetBounds( &_this->ErrorNavigationIcon, _Const0014 );
  ViewsImage_OnSetAlignment( &_this->ErrorNavigationIcon, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  ViewsImage_OnSetVisible( &_this->ErrorNavigationIcon, 1 );
  CoreRectView__OnSetBounds( &_this->TroubleShootingTitle, _Const0015 );
  ViewsText_OnSetAutoSize((ViewsText)&_this->TroubleShootingTitle, 1 );
  ViewsText_OnSetAlignment((ViewsText)&_this->TroubleShootingTitle, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString((ViewsText)&_this->TroubleShootingTitle, EwGetVariantOfString( 
  &StringsPOP07_TROUBLE_SHOOTING ));
  ViewsText_OnSetColor((ViewsText)&_this->TroubleShootingTitle, _Const0016 );
  ViewsText_OnSetVisible((ViewsText)&_this->TroubleShootingTitle, 1 );
  CoreRectView__OnSetBounds( &_this->TroubleShootingText1, _Const0017 );
  ViewsText_OnSetAutoSize((ViewsText)&_this->TroubleShootingText1, 0 );
  ViewsText_OnSetAlignment((ViewsText)&_this->TroubleShootingText1, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString((ViewsText)&_this->TroubleShootingText1, EwGetVariantOfString( 
  &StringsPOP07_UNLOCK_PHONE ));
  ViewsText_OnSetColor((ViewsText)&_this->TroubleShootingText1, _Const0016 );
  ViewsText_OnSetVisible((ViewsText)&_this->TroubleShootingText1, 1 );
  CoreRectView__OnSetBounds( &_this->TroubleShootingText2, _Const0018 );
  ViewsText_OnSetAutoSize((ViewsText)&_this->TroubleShootingText2, 0 );
  ViewsText_OnSetAlignment((ViewsText)&_this->TroubleShootingText2, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString((ViewsText)&_this->TroubleShootingText2, EwGetVariantOfString( 
  &StringsPOP07_TURN_ON_BT ));
  ViewsText_OnSetColor((ViewsText)&_this->TroubleShootingText2, _Const0016 );
  ViewsText_OnSetVisible((ViewsText)&_this->TroubleShootingText2, 1 );
  CoreRectView__OnSetBounds( &_this->TroubleShootingText3, _Const0019 );
  ViewsText_OnSetAutoSize((ViewsText)&_this->TroubleShootingText3, 0 );
  ViewsText_OnSetAlignment((ViewsText)&_this->TroubleShootingText3, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString((ViewsText)&_this->TroubleShootingText3, EwGetVariantOfString( 
  &StringsPOP07_LAUNCH_APP ));
  ViewsText_OnSetColor((ViewsText)&_this->TroubleShootingText3, _Const0016 );
  ViewsText_OnSetVisible((ViewsText)&_this->TroubleShootingText3, 1 );
  CoreRectView__OnSetBounds( &_this->Divider1, _Const001A );
  ViewsImage_OnSetAlignment( &_this->Divider1, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  CoreRectView__OnSetBounds( &_this->Divider2, _Const001B );
  ViewsImage_OnSetAlignment( &_this->Divider2, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  CoreRectView__OnSetBounds( &_this->Divider3, _Const001C );
  ViewsImage_OnSetAlignment( &_this->Divider3, ViewsImageAlignmentAlignHorzCenter 
  | ViewsImageAlignmentAlignVertCenter );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ErrorPhoneLockIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ErrorBTIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ErrorNavigationIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TroubleShootingTitle ), 0 );
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
  ViewsText_OnSetFont((ViewsText)&_this->TroubleShootingTitle, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont((ViewsText)&_this->TroubleShootingText1, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont((ViewsText)&_this->TroubleShootingText2, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont((ViewsText)&_this->TroubleShootingText3, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->Divider1, EwLoadResource( &ResourceSplitLineMiddle, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Divider2, EwLoadResource( &ResourceSplitLineMiddle, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->Divider3, EwLoadResource( &ResourceSplitLineMiddle, 
  ResourcesBitmap ));

  /* Call the user defined constructor */
  PopPOP07_TROUBLE_SHOOTING_Init( _this, aArg );
}

/* Re-Initializer for the class 'Pop::POP07_TROUBLE_SHOOTING' */
void PopPOP07_TROUBLE_SHOOTING__ReInit( PopPOP07_TROUBLE_SHOOTING _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->Divider );
  ViewsImage__ReInit( &_this->ErrorPhoneLockIcon );
  ViewsImage__ReInit( &_this->ErrorBTIcon );
  ViewsImage__ReInit( &_this->ErrorNavigationIcon );
  ComponentsBaseText__ReInit( &_this->TroubleShootingTitle );
  ComponentsBaseText__ReInit( &_this->TroubleShootingText1 );
  ComponentsBaseText__ReInit( &_this->TroubleShootingText2 );
  ComponentsBaseText__ReInit( &_this->TroubleShootingText3 );
  ViewsImage__ReInit( &_this->Divider1 );
  ViewsImage__ReInit( &_this->Divider2 );
  ViewsImage__ReInit( &_this->Divider3 );

  /* ... and re-initialize objects, variables, properties, etc. */
  ViewsText_OnSetString((ViewsText)&_this->TroubleShootingTitle, EwGetVariantOfString( 
  &StringsPOP07_TROUBLE_SHOOTING ));
  ViewsText_OnSetString((ViewsText)&_this->TroubleShootingText1, EwGetVariantOfString( 
  &StringsPOP07_UNLOCK_PHONE ));
  ViewsText_OnSetString((ViewsText)&_this->TroubleShootingText2, EwGetVariantOfString( 
  &StringsPOP07_TURN_ON_BT ));
  ViewsText_OnSetString((ViewsText)&_this->TroubleShootingText3, EwGetVariantOfString( 
  &StringsPOP07_LAUNCH_APP ));
  ViewsText_OnSetFont((ViewsText)&_this->TroubleShootingTitle, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont((ViewsText)&_this->TroubleShootingText1, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont((ViewsText)&_this->TroubleShootingText2, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont((ViewsText)&_this->TroubleShootingText3, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Finalizer method for the class 'Pop::POP07_TROUBLE_SHOOTING' */
void PopPOP07_TROUBLE_SHOOTING__Done( PopPOP07_TROUBLE_SHOOTING _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->Divider );
  ViewsImage__Done( &_this->ErrorPhoneLockIcon );
  ViewsImage__Done( &_this->ErrorBTIcon );
  ViewsImage__Done( &_this->ErrorNavigationIcon );
  ComponentsBaseText__Done( &_this->TroubleShootingTitle );
  ComponentsBaseText__Done( &_this->TroubleShootingText1 );
  ComponentsBaseText__Done( &_this->TroubleShootingText2 );
  ComponentsBaseText__Done( &_this->TroubleShootingText3 );
  ViewsImage__Done( &_this->Divider1 );
  ViewsImage__Done( &_this->Divider2 );
  ViewsImage__Done( &_this->Divider3 );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void PopPOP07_TROUBLE_SHOOTING_Init( PopPOP07_TROUBLE_SHOOTING _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const001D ));
}

/* 'C' function for method : 'Pop::POP07_TROUBLE_SHOOTING.OnShortEnterKeyActivated()' */
void PopPOP07_TROUBLE_SHOOTING_OnShortEnterKeyActivated( PopPOP07_TROUBLE_SHOOTING _this )
{
  ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
    ApplicationApplication_SwitchToHome( App, EnumHomeTypeVEHICLE_INFO );
}

/* 'C' function for method : 'Pop::POP07_TROUBLE_SHOOTING.OnLongHomeKeyActivated()' */
void PopPOP07_TROUBLE_SHOOTING_OnLongHomeKeyActivated( PopPOP07_TROUBLE_SHOOTING _this )
{
  ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
    ApplicationApplication_SwitchToHome( App, EnumHomeTypeVEHICLE_INFO );
}

/* Variants derived from the class : 'Pop::POP07_TROUBLE_SHOOTING' */
EW_DEFINE_CLASS_VARIANTS( PopPOP07_TROUBLE_SHOOTING )
EW_END_OF_CLASS_VARIANTS( PopPOP07_TROUBLE_SHOOTING )

/* Virtual Method Table (VMT) for the class : 'Pop::POP07_TROUBLE_SHOOTING' */
EW_DEFINE_CLASS( PopPOP07_TROUBLE_SHOOTING, ComponentsBaseMainBG, Divider, Divider, 
                 Divider, Divider, _.VMT, _.VMT, "Pop::POP07_TROUBLE_SHOOTING" )
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
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( PopPOP01_PleaseWait );

  /* ... then construct all embedded objects */
  ComponentsBaseText__Init( &_this->LoadingText, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->LoadingAnimation, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->ConnectionFailedTimer, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->NaviConnectUpdateEventHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( PopPOP01_PleaseWait );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->Super1.BlackBG, _Const0005 );
  ViewsRectangle_OnSetColor( &_this->Super1.BlackBG, _Const0006 );
  CoreRectView__OnSetBounds( &_this->LoadingText, _Const0000 );
  ViewsText_OnSetString((ViewsText)&_this->LoadingText, EwGetVariantOfString( &StringsGEN_PLEASE_WAIT ));
  CoreRectView__OnSetBounds( &_this->LoadingAnimation, _Const0001 );
  ViewsImage_OnSetAnimated( &_this->LoadingAnimation, 1 );
  CoreTimer_OnSetPeriod( &_this->ConnectionFailedTimer, 0 );
  CoreTimer_OnSetBegin( &_this->ConnectionFailedTimer, 5000 );
  CoreTimer_OnSetEnabled( &_this->ConnectionFailedTimer, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->LoadingText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LoadingAnimation ), 0 );
  ViewsText_OnSetFont((ViewsText)&_this->LoadingText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->LoadingAnimation, EwLoadResource( &ResourceLoadingAnimation, 
  ResourcesBitmap ));
  _this->ConnectionFailedTimer.OnTrigger = EwNewSlot( _this, PopPOP01_PleaseWait_OnConnectionFailedUpdateSlot );
  _this->NaviConnectUpdateEventHandler.OnEvent = EwNewSlot( _this, PopPOP01_PleaseWait_OnNaviConnectUpdateSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NaviConnectUpdateEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )->ConnectStatusUpdateEvent );

  /* Call the user defined constructor */
  PopPOP01_PleaseWait_Init( _this, aArg );
}

/* Re-Initializer for the class 'Pop::POP01_PleaseWait' */
void PopPOP01_PleaseWait__ReInit( PopPOP01_PleaseWait _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ComponentsBaseText__ReInit( &_this->LoadingText );
  ViewsImage__ReInit( &_this->LoadingAnimation );
  CoreTimer__ReInit( &_this->ConnectionFailedTimer );
  CoreSystemEventHandler__ReInit( &_this->NaviConnectUpdateEventHandler );

  /* ... and re-initialize objects, variables, properties, etc. */
  ViewsText_OnSetString((ViewsText)&_this->LoadingText, EwGetVariantOfString( &StringsGEN_PLEASE_WAIT ));
  ViewsText_OnSetFont((ViewsText)&_this->LoadingText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Finalizer method for the class 'Pop::POP01_PleaseWait' */
void PopPOP01_PleaseWait__Done( PopPOP01_PleaseWait _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ComponentsBaseText__Done( &_this->LoadingText );
  ViewsImage__Done( &_this->LoadingAnimation );
  CoreTimer__Done( &_this->ConnectionFailedTimer );
  CoreSystemEventHandler__Done( &_this->NaviConnectUpdateEventHandler );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void PopPOP01_PleaseWait_Init( PopPOP01_PleaseWait _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const001E ));
}

/* 'C' function for method : 'Pop::POP01_PleaseWait.OnShortHomeKeyActivated()' */
void PopPOP01_PleaseWait_OnShortHomeKeyActivated( PopPOP01_PleaseWait _this )
{
  ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
    ApplicationApplication_SwitchToMeterHome( App );
}

/* 'C' function for method : 'Pop::POP01_PleaseWait.OnLongHomeKeyActivated()' */
void PopPOP01_PleaseWait_OnLongHomeKeyActivated( PopPOP01_PleaseWait _this )
{
  ApplicationApplication App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
    ApplicationApplication_SwitchToMeterHome( App );
}

/* 'C' function for method : 'Pop::POP01_PleaseWait.OnConnectionFailedUpdateSlot()' */
void PopPOP01_PleaseWait_OnConnectionFailedUpdateSlot( PopPOP01_PleaseWait _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->ConnectionFailedTimer, 0 );

  if ( _this->Super5.Owner != 0 )
    CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)EwNewObject( PopPOP02_ConnectionError, 
    0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void PopPOP01_PleaseWait_OnNaviConnectUpdateSlot( PopPOP01_PleaseWait _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->ConnectionFailedTimer, 0 );
  EwSignal( _this->NaviAppConnectedSlot, ((XObject)_this ));
}

/* Variants derived from the class : 'Pop::POP01_PleaseWait' */
EW_DEFINE_CLASS_VARIANTS( PopPOP01_PleaseWait )
EW_END_OF_CLASS_VARIANTS( PopPOP01_PleaseWait )

/* Virtual Method Table (VMT) for the class : 'Pop::POP01_PleaseWait' */
EW_DEFINE_CLASS( PopPOP01_PleaseWait, ComponentsBaseMainBG, NaviAppConnectedSlot, 
                 NaviAppConnectedSlot, LoadingText, LoadingText, _.VMT, _.VMT, "Pop::POP01_PleaseWait" )
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

/* Initializer for the class 'Pop::POP04_Reset' */
void PopPOP04_Reset__Init( PopPOP04_Reset _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( PopPOP04_Reset );

  /* ... then construct all embedded objects */
  ComponentsBaseText__Init( &_this->ResetText, &_this->_.XObject, 0 );
  MenuUpDownPushButtonSet__Init( &_this->UpDownPushButtonSet, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Divider, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( PopPOP04_Reset );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->ResetText, _Const001F );
  ViewsText_OnSetString((ViewsText)&_this->ResetText, EwGetVariantOfString( &StringsGEN_RESET_QUESTION_MARK ));
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const000F );
  _this->UpDownPushButtonSet.Super1.PassHomeKey = 1;
  _this->UpDownPushButtonSet.Super1.PassMagicKey = 1;
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwGetVariantOfString( 
  &StringsGEN_CANCEL ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwGetVariantOfString( 
  &StringsGEN_OK ));
  MenuUpDownPushButtonSet_OnSetDownButtonEnabled( &_this->UpDownPushButtonSet, 1 );
  CoreRectView__OnSetBounds( &_this->Divider, _Const0020 );
  ViewsImage_OnSetAlignment( &_this->Divider, ViewsImageAlignmentAlignVertBottom 
  | ViewsImageAlignmentScaleToFit );
  CoreGroup__Add( _this, ((CoreView)&_this->ResetText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UpDownPushButtonSet ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider ), 0 );
  ViewsText_OnSetFont((ViewsText)&_this->ResetText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->UpDownPushButtonSet.OnUpButtonActivated = EwNewSlot( _this, PopPOP04_Reset_OnCancelButtonActivatedSlot );
  _this->UpDownPushButtonSet.OnDownButtonActivated = EwNewSlot( _this, PopPOP04_Reset_OnOkButtonActivatedSlot );
  ViewsImage_OnSetBitmap( &_this->Divider, EwLoadResource( &ResourceStatusBarDivider, 
  ResourcesBitmap ));

  /* Call the user defined constructor */
  PopPOP04_Reset_Init( _this, aArg );
}

/* Re-Initializer for the class 'Pop::POP04_Reset' */
void PopPOP04_Reset__ReInit( PopPOP04_Reset _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ComponentsBaseText__ReInit( &_this->ResetText );
  MenuUpDownPushButtonSet__ReInit( &_this->UpDownPushButtonSet );
  ViewsImage__ReInit( &_this->Divider );

  /* ... and re-initialize objects, variables, properties, etc. */
  ViewsText_OnSetString((ViewsText)&_this->ResetText, EwGetVariantOfString( &StringsGEN_RESET_QUESTION_MARK ));
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwGetVariantOfString( 
  &StringsGEN_CANCEL ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwGetVariantOfString( 
  &StringsGEN_OK ));
  ViewsText_OnSetFont((ViewsText)&_this->ResetText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Finalizer method for the class 'Pop::POP04_Reset' */
void PopPOP04_Reset__Done( PopPOP04_Reset _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ComponentsBaseText__Done( &_this->ResetText );
  MenuUpDownPushButtonSet__Done( &_this->UpDownPushButtonSet );
  ViewsImage__Done( &_this->Divider );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void PopPOP04_Reset_Init( PopPOP04_Reset _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0021 ));
}

/* 'C' function for method : 'Pop::POP04_Reset.OnOkButtonActivatedSlot()' */
void PopPOP04_Reset_OnOkButtonActivatedSlot( PopPOP04_Reset _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  DeviceInterfaceVehicleDeviceClass_SetData( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ), EnumVehicleTxTypeRESET_METER, (XUInt32)_this->SelectedMeterInfo );
  ComponentsBaseMainBG_DismissThisDialog((ComponentsBaseMainBG)_this );
}

/* 'C' function for method : 'Pop::POP04_Reset.OnCancelButtonActivatedSlot()' */
void PopPOP04_Reset_OnCancelButtonActivatedSlot( PopPOP04_Reset _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ComponentsBaseMainBG_DismissThisDialog((ComponentsBaseMainBG)_this );
}

/* Variants derived from the class : 'Pop::POP04_Reset' */
EW_DEFINE_CLASS_VARIANTS( PopPOP04_Reset )
EW_END_OF_CLASS_VARIANTS( PopPOP04_Reset )

/* Virtual Method Table (VMT) for the class : 'Pop::POP04_Reset' */
EW_DEFINE_CLASS( PopPOP04_Reset, ComponentsBaseMainBG, ResetText, ResetText, ResetText, 
                 ResetText, SelectedMeterInfo, SelectedMeterInfo, "Pop::POP04_Reset" )
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
EW_END_OF_CLASS( PopPOP04_Reset )

/* Initializer for the class 'Pop::POP17_AppInitSettingError' */
void PopPOP17_AppInitSettingError__Init( PopPOP17_AppInitSettingError _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( PopPOP17_AppInitSettingError );

  /* ... then construct all embedded objects */
  ComponentsBaseText__Init( &_this->AppInitSettingFailedMessage, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->CountDownTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( PopPOP17_AppInitSettingError );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->AppInitSettingFailedMessage, _Const0022 );
  ViewsText_OnSetWrapText((ViewsText)&_this->AppInitSettingFailedMessage, 1 );
  ViewsText_OnSetString((ViewsText)&_this->AppInitSettingFailedMessage, EwGetVariantOfString( 
  &StringsPOP17_APP_INIT_SETTING_FAILED ));
  CoreTimer_OnSetPeriod( &_this->CountDownTimer, 2000 );
  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->AppInitSettingFailedMessage ), 0 );
  ViewsText_OnSetFont((ViewsText)&_this->AppInitSettingFailedMessage, EwLoadResource( 
  &FontsNotoSansCjkJpMedium24pt, ResourcesFont ));
  _this->CountDownTimer.OnTrigger = EwNewSlot( _this, PopPOP17_AppInitSettingError_OnLauncherScreenUpdateSlot );

  /* Call the user defined constructor */
  PopPOP17_AppInitSettingError_Init( _this, aArg );
}

/* Re-Initializer for the class 'Pop::POP17_AppInitSettingError' */
void PopPOP17_AppInitSettingError__ReInit( PopPOP17_AppInitSettingError _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ComponentsBaseText__ReInit( &_this->AppInitSettingFailedMessage );
  CoreTimer__ReInit( &_this->CountDownTimer );

  /* ... and re-initialize objects, variables, properties, etc. */
  ViewsText_OnSetString((ViewsText)&_this->AppInitSettingFailedMessage, EwGetVariantOfString( 
  &StringsPOP17_APP_INIT_SETTING_FAILED ));
  ViewsText_OnSetFont((ViewsText)&_this->AppInitSettingFailedMessage, EwLoadResource( 
  &FontsNotoSansCjkJpMedium24pt, ResourcesFont ));
}

/* Finalizer method for the class 'Pop::POP17_AppInitSettingError' */
void PopPOP17_AppInitSettingError__Done( PopPOP17_AppInitSettingError _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ComponentsBaseText__Done( &_this->AppInitSettingFailedMessage );
  CoreTimer__Done( &_this->CountDownTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void PopPOP17_AppInitSettingError_Init( PopPOP17_AppInitSettingError _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0023 ));
}

/* 'C' function for method : 'Pop::POP17_AppInitSettingError.OnLauncherScreenUpdateSlot()' */
void PopPOP17_AppInitSettingError_OnLauncherScreenUpdateSlot( PopPOP17_AppInitSettingError _this, 
  XObject sender )
{
  ApplicationApplication App;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 0 );
  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  if ( App != 0 )
    ApplicationApplication_ReturnToLauncher( App );
}

/* Variants derived from the class : 'Pop::POP17_AppInitSettingError' */
EW_DEFINE_CLASS_VARIANTS( PopPOP17_AppInitSettingError )
EW_END_OF_CLASS_VARIANTS( PopPOP17_AppInitSettingError )

/* Virtual Method Table (VMT) for the class : 'Pop::POP17_AppInitSettingError' */
EW_DEFINE_CLASS( PopPOP17_AppInitSettingError, ComponentsBaseMainBG, AppInitSettingFailedMessage, 
                 AppInitSettingFailedMessage, AppInitSettingFailedMessage, AppInitSettingFailedMessage, 
                 _.VMT, _.VMT, "Pop::POP17_AppInitSettingError" )
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
EW_END_OF_CLASS( PopPOP17_AppInitSettingError )

/* Initializer for the class 'Pop::POP03_HomeOfficeSettingError' */
void PopPOP03_HomeOfficeSettingError__Init( PopPOP03_HomeOfficeSettingError _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( PopPOP03_HomeOfficeSettingError );

  /* ... then construct all embedded objects */
  ComponentsBaseText__Init( &_this->HomeOfficeSettingFailedMessage, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->CountDownTimer, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Divider, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( PopPOP03_HomeOfficeSettingError );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->HomeOfficeSettingFailedMessage, _Const0022 );
  ViewsText_OnSetWrapText((ViewsText)&_this->HomeOfficeSettingFailedMessage, 1 );
  ViewsText_OnSetString((ViewsText)&_this->HomeOfficeSettingFailedMessage, 0 );
  CoreTimer_OnSetPeriod( &_this->CountDownTimer, 2000 );
  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 1 );
  CoreRectView__OnSetBounds( &_this->Divider, _Const0020 );
  ViewsImage_OnSetAlignment( &_this->Divider, ViewsImageAlignmentAlignVertBottom 
  | ViewsImageAlignmentScaleToFit );
  CoreGroup__Add( _this, ((CoreView)&_this->HomeOfficeSettingFailedMessage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider ), 0 );
  ViewsText_OnSetFont((ViewsText)&_this->HomeOfficeSettingFailedMessage, EwLoadResource( 
  &FontsNotoSansCjkJpMedium24pt, ResourcesFont ));
  _this->CountDownTimer.OnTrigger = EwNewSlot( _this, PopPOP03_HomeOfficeSettingError_OnLauncherScreenUpdateSlot );
  ViewsImage_OnSetBitmap( &_this->Divider, EwLoadResource( &ResourceStatusBarDivider, 
  ResourcesBitmap ));

  /* Call the user defined constructor */
  PopPOP03_HomeOfficeSettingError_Init( _this, aArg );
}

/* Re-Initializer for the class 'Pop::POP03_HomeOfficeSettingError' */
void PopPOP03_HomeOfficeSettingError__ReInit( PopPOP03_HomeOfficeSettingError _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ComponentsBaseText__ReInit( &_this->HomeOfficeSettingFailedMessage );
  CoreTimer__ReInit( &_this->CountDownTimer );
  ViewsImage__ReInit( &_this->Divider );

  /* ... and re-initialize objects, variables, properties, etc. */
  ViewsText_OnSetFont((ViewsText)&_this->HomeOfficeSettingFailedMessage, EwLoadResource( 
  &FontsNotoSansCjkJpMedium24pt, ResourcesFont ));
}

/* Finalizer method for the class 'Pop::POP03_HomeOfficeSettingError' */
void PopPOP03_HomeOfficeSettingError__Done( PopPOP03_HomeOfficeSettingError _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ComponentsBaseText__Done( &_this->HomeOfficeSettingFailedMessage );
  CoreTimer__Done( &_this->CountDownTimer );
  ViewsImage__Done( &_this->Divider );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void PopPOP03_HomeOfficeSettingError_Init( PopPOP03_HomeOfficeSettingError _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0024 ));
}

/* 'C' function for method : 'Pop::POP03_HomeOfficeSettingError.OnLauncherScreenUpdateSlot()' */
void PopPOP03_HomeOfficeSettingError_OnLauncherScreenUpdateSlot( PopPOP03_HomeOfficeSettingError _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->CountDownTimer, 0 );
  EwSignal( _this->ReturnToNaviHomeSlot, ((XObject)_this ));
}

/* 'C' function for method : 'Pop::POP03_HomeOfficeSettingError.OnSetErrorMessage()' */
void PopPOP03_HomeOfficeSettingError_OnSetErrorMessage( PopPOP03_HomeOfficeSettingError _this, 
  XString value )
{
  if ( EwCompString( _this->ErrorMessage, value ) != 0 )
  {
    _this->ErrorMessage = EwShareString( value );
    ViewsText_OnSetString((ViewsText)&_this->HomeOfficeSettingFailedMessage, _this->ErrorMessage );
  }
}

/* Variants derived from the class : 'Pop::POP03_HomeOfficeSettingError' */
EW_DEFINE_CLASS_VARIANTS( PopPOP03_HomeOfficeSettingError )
EW_END_OF_CLASS_VARIANTS( PopPOP03_HomeOfficeSettingError )

/* Virtual Method Table (VMT) for the class : 'Pop::POP03_HomeOfficeSettingError' */
EW_DEFINE_CLASS( PopPOP03_HomeOfficeSettingError, ComponentsBaseMainBG, ReturnToNaviHomeSlot, 
                 ReturnToNaviHomeSlot, HomeOfficeSettingFailedMessage, HomeOfficeSettingFailedMessage, 
                 ErrorMessage, _.VMT, "Pop::POP03_HomeOfficeSettingError" )
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
EW_END_OF_CLASS( PopPOP03_HomeOfficeSettingError )

/* Initializer for the class 'Pop::POP16_NaviLoadingUI' */
void PopPOP16_NaviLoadingUI__Init( PopPOP16_NaviLoadingUI _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( PopPOP16_NaviLoadingUI );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->NaviLoadingMainBottom, &_this->_.XObject, 0 );
  ViewsRectangle__Init( &_this->NaviLoadingBlackBG, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->NaviLoadingText, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->NaviLoadingAnimation, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( PopPOP16_NaviLoadingUI );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0025 );
  CoreRectView__OnSetBounds( &_this->NaviLoadingMainBottom, _Const0026 );
  CoreRectView__OnSetBounds( &_this->NaviLoadingBlackBG, _Const0027 );
  ViewsRectangle_OnSetColor( &_this->NaviLoadingBlackBG, _Const0006 );
  CoreRectView__OnSetBounds( &_this->NaviLoadingText, _Const0028 );
  ViewsText_OnSetString((ViewsText)&_this->NaviLoadingText, EwGetVariantOfString( 
  &StringsGEN_PLEASE_WAIT ));
  CoreRectView__OnSetBounds( &_this->NaviLoadingAnimation, _Const0029 );
  ViewsImage_OnSetAnimated( &_this->NaviLoadingAnimation, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviLoadingMainBottom ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviLoadingBlackBG ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviLoadingText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NaviLoadingAnimation ), 0 );
  ViewsImage_OnSetBitmap( &_this->NaviLoadingMainBottom, EwLoadResource( &ResourceMainBG, 
  ResourcesBitmap ));
  ViewsText_OnSetFont((ViewsText)&_this->NaviLoadingText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsImage_OnSetBitmap( &_this->NaviLoadingAnimation, EwLoadResource( &ResourceLoadingAnimation, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'Pop::POP16_NaviLoadingUI' */
void PopPOP16_NaviLoadingUI__ReInit( PopPOP16_NaviLoadingUI _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->NaviLoadingMainBottom );
  ViewsRectangle__ReInit( &_this->NaviLoadingBlackBG );
  ComponentsBaseText__ReInit( &_this->NaviLoadingText );
  ViewsImage__ReInit( &_this->NaviLoadingAnimation );

  /* ... and re-initialize objects, variables, properties, etc. */
  ViewsText_OnSetString((ViewsText)&_this->NaviLoadingText, EwGetVariantOfString( 
  &StringsGEN_PLEASE_WAIT ));
  ViewsText_OnSetFont((ViewsText)&_this->NaviLoadingText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Finalizer method for the class 'Pop::POP16_NaviLoadingUI' */
void PopPOP16_NaviLoadingUI__Done( PopPOP16_NaviLoadingUI _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->NaviLoadingMainBottom );
  ViewsRectangle__Done( &_this->NaviLoadingBlackBG );
  ComponentsBaseText__Done( &_this->NaviLoadingText );
  ViewsImage__Done( &_this->NaviLoadingAnimation );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Pop::POP16_NaviLoadingUI.OnSetAnimated()' */
void PopPOP16_NaviLoadingUI_OnSetAnimated( PopPOP16_NaviLoadingUI _this, XBool value )
{
  if ( _this->Animated != value )
  {
    _this->Animated = value;
    ViewsImage_OnSetAnimated( &_this->NaviLoadingAnimation, value );
  }
}

/* Variants derived from the class : 'Pop::POP16_NaviLoadingUI' */
EW_DEFINE_CLASS_VARIANTS( PopPOP16_NaviLoadingUI )
EW_END_OF_CLASS_VARIANTS( PopPOP16_NaviLoadingUI )

/* Virtual Method Table (VMT) for the class : 'Pop::POP16_NaviLoadingUI' */
EW_DEFINE_CLASS( PopPOP16_NaviLoadingUI, CoreGroup, NaviLoadingMainBottom, NaviLoadingMainBottom, 
                 NaviLoadingMainBottom, NaviLoadingMainBottom, Animated, Animated, 
                 "Pop::POP16_NaviLoadingUI" )
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
EW_END_OF_CLASS( PopPOP16_NaviLoadingUI )

/* Embedded Wizard */
