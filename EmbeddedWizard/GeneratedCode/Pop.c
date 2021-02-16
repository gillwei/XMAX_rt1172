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
#include "_CorePropertyObserver.h"
#include "_CoreView.h"
#include "_DeviceInterfaceWeatherDeviceClass.h"
#include "_PopPOP08_WeatherLoadingUI.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsText.h"
#include "_WeatherWEA01_Main.h"
#include "DeviceInterface.h"
#include "Fonts.h"
#include "Pop.h"
#include "Resource.h"
#include "Strings.h"

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0001 = {{ 10, 156 }, { 470, 187 }};
static const XRect _Const0002 = {{ 193, 54 }, { 287, 148 }};

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

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( PopPOP08_WeatherLoadingUI );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->LoadingText, _Const0001 );
  ViewsText_OnSetString( &_this->LoadingText, EwLoadString( &StringsGEN_please_wait ));
  CoreRectView__OnSetBounds( &_this->LoadingAnimation, _Const0002 );
  ViewsImage_OnSetAnimated( &_this->LoadingAnimation, 1 );
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
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( WeatherWEA01_Main, 
    0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
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
EW_END_OF_CLASS( PopPOP08_WeatherLoadingUI )

/* Embedded Wizard */
