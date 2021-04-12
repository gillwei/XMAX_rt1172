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
#include "_CoreRoot.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DeviceInterfaceBluetoothDeviceClass.h"
#include "_DeviceInterfaceNotificationDeviceClass.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_EffectSlideTransitionNoFade.h"
#include "_EffectsTransition.h"
#include "_FactoryDisplayAutoRun.h"
#include "_FactoryDisplayManual.h"
#include "_FactoryTestContext.h"
#include "_HomeBaseHome.h"
#include "_HomeHOM03_VehicleInfo.h"
#include "_HomeHOM11_TachoVisualizer.h"
#include "_HomeHOM12_EcoVisualizer.h"
#include "_HomeHOM13_SpeedVisualizer.h"
#include "_InspectionTFT_Main.h"
#include "_LauncherLNC_Main.h"
#include "_NavigationNAV01_DefaultView.h"
#include "_NavigationNAV03_TBTListView.h"
#include "_NavigationNAV05_TBTView.h"
#include "_OpenOPN01_BootupAnimation.h"
#include "_OpenOPN02_FactoryMode.h"
#include "_PopPOP01_PleaseWait.h"
#include "_SettingsBtFwUpdateDialog.h"
#include "_StatusBarMain.h"
#include "_TelephoneTEL01_IncomingCall.h"
#include "_TopTOP01_Disclaimer.h"
#include "_ViewsRectangle.h"
#include "Application.h"
#include "Color.h"
#include "DeviceInterface.h"
#include "Effect.h"
#include "Enum.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x0000009E, /* ratio 75.95 % */
  0xB8002D00, 0x000A6452, 0x1CC2003A, 0xC0075004, 0x1242001C, 0x00039002, 0x002B0004,
  0x08CC38D2, 0x36000C40, 0xD000CA00, 0xC9801151, 0x508B0307, 0xA111B909, 0x60002245,
  0x06F00136, 0x16961900, 0xC294A64F, 0x8A436112, 0xACAC006E, 0x80268489, 0x2A4D2C36,
  0x88D2B948, 0x411E92D0, 0x928004E6, 0x1A9041A0, 0x024C8A6F, 0x9AD16820, 0x354E4548,
  0x00203269, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0001 = {{ 0, 0 }, { 480, 38 }};
static const XStringRes _Const0002 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0003 = { _StringsDefault0, 0x0018 };
static const XStringRes _Const0004 = { _StringsDefault0, 0x0027 };
static const XStringRes _Const0005 = { _StringsDefault0, 0x0036 };
static const XStringRes _Const0006 = { _StringsDefault0, 0x0040 };

/* Initializer for the class 'Application::Application' */
void ApplicationApplication__Init( ApplicationApplication _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRoot__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( ApplicationApplication );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->FactoryTestEventHandler, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->BtFwStatusObserver, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->DDModeTestTimer, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->OpeningSystemEventHandler, &_this->_XObject, 0 );
  StatusBarMain__Init( &_this->StatusBar, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->CheckOpeningTimer, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->PhoneCallStateChangedEventHandler, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->InspectionModeEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ApplicationApplication );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  _this->StatusBarVisible = 1;
  CoreTimer_OnSetPeriod( &_this->DDModeTestTimer, 3000 );
  CoreTimer_OnSetEnabled( &_this->DDModeTestTimer, 0 );
  CoreRectView__OnSetBounds( &_this->StatusBar, _Const0001 );
  CoreGroup__OnSetVisible( &_this->StatusBar, 0 );
  CoreTimer_OnSetPeriod( &_this->CheckOpeningTimer, 200 );
  CoreTimer_OnSetBegin( &_this->CheckOpeningTimer, 500 );
  CoreTimer_OnSetEnabled( &_this->CheckOpeningTimer, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->StatusBar ), 0 );
  _this->FactoryTestEventHandler.OnEvent = EwNewSlot( _this, ApplicationApplication_OnFactoryTestEventSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->FactoryTestEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->FactoryTestSystemEvent );
  _this->BtFwStatusObserver.OnEvent = EwNewSlot( _this, ApplicationApplication_OnBtFwStatusUpdteSlot );
  CorePropertyObserver_OnSetOutlet( &_this->BtFwStatusObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), DeviceInterfaceBluetoothDeviceClass_OnGetBtFwStatus, 
  DeviceInterfaceBluetoothDeviceClass_OnSetBtFwStatus ));
  _this->DDModeTestTimer.OnTrigger = EwNewSlot( _this, ApplicationApplication_OnDDModeTestSlot );
  _this->OpeningSystemEventHandler.OnEvent = EwNewSlot( _this, ApplicationApplication_OnStartOpeningSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->OpeningSystemEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->OpeningSystemEvent );
  _this->CheckOpeningTimer.OnTrigger = EwNewSlot( _this, ApplicationApplication_OnCheckOpeningSlot );
  _this->PhoneCallStateChangedEventHandler.OnEvent = EwNewSlot( _this, ApplicationApplication_OnPhoneCallStateChangedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->PhoneCallStateChangedEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )->PhoneCallStateChangedSystemEvent );
  _this->InspectionModeEventHandler.OnEvent = EwNewSlot( _this, ApplicationApplication_OnInspectionModeEventSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->InspectionModeEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->InspectionModeSystemEvent );

  /* Call the user defined constructor */
  ApplicationApplication_Init( _this, aArg );
}

/* Re-Initializer for the class 'Application::Application' */
void ApplicationApplication__ReInit( ApplicationApplication _this )
{
  /* At first re-initialize the super class ... */
  CoreRoot__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->FactoryTestEventHandler );
  CorePropertyObserver__ReInit( &_this->BtFwStatusObserver );
  CoreTimer__ReInit( &_this->DDModeTestTimer );
  CoreSystemEventHandler__ReInit( &_this->OpeningSystemEventHandler );
  StatusBarMain__ReInit( &_this->StatusBar );
  CoreTimer__ReInit( &_this->CheckOpeningTimer );
  CoreSystemEventHandler__ReInit( &_this->PhoneCallStateChangedEventHandler );
  CoreSystemEventHandler__ReInit( &_this->InspectionModeEventHandler );
}

/* Finalizer method for the class 'Application::Application' */
void ApplicationApplication__Done( ApplicationApplication _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreRoot );

  /* Finalize all embedded objects */
  CoreSystemEventHandler__Done( &_this->FactoryTestEventHandler );
  CorePropertyObserver__Done( &_this->BtFwStatusObserver );
  CoreTimer__Done( &_this->DDModeTestTimer );
  CoreSystemEventHandler__Done( &_this->OpeningSystemEventHandler );
  StatusBarMain__Done( &_this->StatusBar );
  CoreTimer__Done( &_this->CheckOpeningTimer );
  CoreSystemEventHandler__Done( &_this->PhoneCallStateChangedEventHandler );
  CoreSystemEventHandler__Done( &_this->InspectionModeEventHandler );

  /* Don't forget to deinitialize the super class ... */
  CoreRoot__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationApplication_Init( ApplicationApplication _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );
}

/* 'C' function for method : 'Application::Application.OnDisclaimerAcceptedSlot()' */
void ApplicationApplication_OnDisclaimerAcceptedSlot( ApplicationApplication _this, 
  XObject sender )
{
  TopTOP01_Disclaimer DisclaimerDialog = EwCastObject( sender, TopTOP01_Disclaimer );

  if ( DisclaimerDialog != 0 )
  {
    ViewsRectangle_OnSetColor( &DisclaimerDialog->TopBar, ColorBLACK );
  }

  _this->IsDisclaimerDismissed = 1;
  CoreGroup__OnSetVisible( &_this->StatusBar, 1 );

  if ((( EnumHomeTypeNAVI_DEFAULT_VIEW == EwGetAutoObject( &DeviceInterfaceSystemDevice, 
      DeviceInterfaceSystemDeviceClass )->HomeType ) || ( EnumHomeTypeNAVI_NEXT_TURN 
      == EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->HomeType )) 
      || ( EnumHomeTypeNAVI_TURN_BY_TURN == EwGetAutoObject( &DeviceInterfaceSystemDevice, 
      DeviceInterfaceSystemDeviceClass )->HomeType ))
  {
    CoreGroup_SwitchToDialog((CoreGroup)CoreView__GetRoot( _this ), ((CoreGroup)EwNewObject( 
    PopPOP01_PleaseWait, 0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
  else
  {
    CoreGroup HomeDialog = ApplicationApplication_HomeDialogOfHomeType( _this, EwGetAutoObject( 
      &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->HomeType );

    if ( HomeDialog != 0 )
    {
      CoreGroup_SwitchToDialog((CoreGroup)CoreView__GetRoot( _this ), HomeDialog, 
      0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
  }
}

/* 'C' function for method : 'Application::Application.ShowDisclaimer()' */
void ApplicationApplication_ShowDisclaimer( ApplicationApplication _this )
{
  TopTOP01_Disclaimer Disclaimer = EwNewObject( TopTOP01_Disclaimer, 0 );

  Disclaimer->OnAcceptButtonClicked = EwNewSlot( _this, ApplicationApplication_OnDisclaimerAcceptedSlot );
  CoreGroup_SwitchToDialog((CoreGroup)CoreView__GetRoot( _this ), ((CoreGroup)Disclaimer ), 
  0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void ApplicationApplication_OnFactoryTestEventSlot( ApplicationApplication _this, 
  XObject sender )
{
  FactoryTestContext TestContext;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  TestContext = EwCastObject( _this->FactoryTestEventHandler.Context, FactoryTestContext );

  if ( TestContext != 0 )
  {
    switch ( TestContext->TestItem )
    {
      case EnumFactoryTestDisplay :
      {
        FactoryDisplayManual FactoryTestDialog = EwCastObject( CoreGroup_FindDialogByClass((CoreGroup)_this, 
          EW_CLASS( FactoryDisplayManual )), FactoryDisplayManual );

        if ( FactoryTestDialog == 0 )
        {
          FactoryTestDialog = EwNewObject( FactoryDisplayManual, 0 );
          CoreView_OnSetStackingPriority((CoreView)FactoryTestDialog, 1 );
          CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)FactoryTestDialog ), 
          0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
        }

        FactoryDisplayManual_OnSetPatternIdx( FactoryTestDialog, TestContext->Data );
        _this->IsFactoryTest = 1;
      }
      break;

      case EnumFactoryTestBurnInStart :
      {
        FactoryDisplayAutoRun DisplayAutoRunDialog = EwNewObject( FactoryDisplayAutoRun, 
          0 );
        FactoryDisplayAutoRun_OnSetBurnInEnabled( DisplayAutoRunDialog, 1 );
        CoreView_OnSetStackingPriority((CoreView)DisplayAutoRunDialog, 1 );
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)DisplayAutoRunDialog ), 
        0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
        _this->IsFactoryTest = 1;
      }
      break;

      case EnumFactoryTestQuit :
      {
        ApplicationApplication_DismissFactoryTestDialog( _this );
        ApplicationApplication_OnSetStatusBarVisible( _this, 1 );
        _this->IsFactoryTest = 0;
      }
      break;

      default : 
        ;
    }
  }
}

/* 'C' function for method : 'Application::Application.OnSetStatusBarVisible()' */
void ApplicationApplication_OnSetStatusBarVisible( ApplicationApplication _this, 
  XBool value )
{
  if ( _this->StatusBarVisible != value )
  {
    _this->StatusBarVisible = value;
    CoreGroup__OnSetVisible( &_this->StatusBar, value );
    EwTrace( "%s%b", EwLoadString( &_Const0002 ), value );
  }
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void ApplicationApplication_OnBtFwStatusUpdteSlot( ApplicationApplication _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EnumBtFwStatusUPDATE_START == EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
      DeviceInterfaceBluetoothDeviceClass )->BtFwStatus )
  {
    SettingsBtFwUpdateDialog BtFwDialog = EwNewObject( SettingsBtFwUpdateDialog, 
      0 );
    CoreView_OnSetStackingPriority((CoreView)BtFwDialog, 1 );
    CoreGroup__Add( CoreView__GetRoot( _this ), ((CoreView)BtFwDialog ), 0 );
    CoreRoot_BeginModal( CoreView__GetRoot( _this ), ((CoreGroup)BtFwDialog ));
  }
}

/* 'C' function for method : 'Application::Application.DismissFactoryTestDialog()' */
void ApplicationApplication_DismissFactoryTestDialog( ApplicationApplication _this )
{
  CoreGroup FactoryTestDialog = CoreGroup_FindDialogByClass((CoreGroup)_this, EW_CLASS( 
    FactoryDisplayAutoRun ));

  if ( FactoryTestDialog != 0 )
  {
    CoreGroup__DismissDialog( _this, FactoryTestDialog, 0, 0, 0, EwNullSlot, EwNullSlot, 
    0 );
  }

  FactoryTestDialog = CoreGroup_FindDialogByClass((CoreGroup)_this, EW_CLASS( FactoryDisplayManual ));

  if ( FactoryTestDialog != 0 )
  {
    CoreGroup__DismissDialog( _this, FactoryTestDialog, 0, 0, 0, EwNullSlot, EwNullSlot, 
    0 );
  }
}

/* 'C' function for method : 'Application::Application.SwitchToHome()' */
void ApplicationApplication_SwitchToHome( ApplicationApplication _this, XEnum aHomeType )
{
  XClass HomeClass = ApplicationApplication_HomeClassOfHomeType( _this, aHomeType );

  if ( HomeClass != 0 )
  {
    XBool IsInDialogStack = 0;
    XInt32 DialogIdx = 0;

    for ( DialogIdx = 0; DialogIdx < CoreGroup_CountDialogs((CoreGroup)_this ); 
         DialogIdx++ )
    {
      if ( HomeClass == EwClassOf(((XObject)CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
          DialogIdx ))))
      {
        IsInDialogStack = 1;
        break;
      }
    }

    if ( IsInDialogStack )
    {
      for ( DialogIdx = 0; DialogIdx < CoreGroup_CountDialogs((CoreGroup)_this ); 
           DialogIdx++ )
      {
        if ( HomeClass == EwClassOf(((XObject)CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
            0 ))))
        {
          HomeBaseHome HomeDialog = EwCastObject( CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
            0 ), HomeBaseHome );

          if ( HomeDialog != 0 )
          {
            HomeBaseHome_ReturnToHome( HomeDialog );
          }

          break;
        }
        else
        {
          CoreGroup__DismissDialog( _this, CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
          0 ), 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
        }
      }
    }
    else
    {
      CoreGroup HomeDialog = ApplicationApplication_HomeDialogOfHomeType( _this, 
        aHomeType );

      if ( HomeDialog != 0 )
      {
        while ( CoreGroup_CountDialogs((CoreGroup)_this ) > 0 )
        {
          CoreGroup__DismissDialog( _this, CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
          0 ), ((EffectsTransition)EwGetAutoObject( &EffectNoSlideOut, EffectSlideTransitionNoFade )), 
          0, 0, EwNullSlot, EwNullSlot, 1 );
        }

        CoreGroup_SwitchToDialog((CoreGroup)_this, HomeDialog, 0, 0, 0, 0, 0, 0, 
        0, EwNullSlot, EwNullSlot, 1 );
        DeviceInterfaceSystemDeviceClass_OnSetHomeType( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
        DeviceInterfaceSystemDeviceClass ), aHomeType );
      }
    }
  }
}

/* 'C' function for method : 'Application::Application.OnDDModeTestSlot()' */
void ApplicationApplication_OnDDModeTestSlot( ApplicationApplication _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( sender );

  EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->DDModeActivated 
  = (XBool)!DeviceInterfaceVehicleDeviceClass_OnGetDDModeActivated( EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ));
  EwTrace( "%s%b", EwLoadString( &_Const0003 ), DeviceInterfaceVehicleDeviceClass_OnGetDDModeActivated( 
    EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )));
  DeviceInterfaceVehicleDeviceClass_NotifyDDModeStateChanged( EwGetAutoObject( &DeviceInterfaceVehicleDevice, 
  DeviceInterfaceVehicleDeviceClass ));
}

/* Return from the DD mode forbidden UI to the launcher */
void ApplicationApplication_ReturnToLauncher( ApplicationApplication _this )
{
  XInt32 NoOfDialogs = CoreGroup_CountDialogs((CoreGroup)_this );
  XInt32 i;

  for ( i = 0; i < NoOfDialogs; i++ )
  {
    LauncherLNC_Main LauncherMain = EwCastObject( CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
      i ), LauncherLNC_Main );

    if ( LauncherMain != 0 )
    {
      LauncherLNC_Main_DismissChildDialogs( LauncherMain );
      break;
    }
  }
}

/* 'C' function for method : 'Application::Application.HomeClassOfHomeType()' */
XClass ApplicationApplication_HomeClassOfHomeType( ApplicationApplication _this, 
  XEnum aHomeType )
{
  XClass HomeClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  HomeClass = 0;

  switch ( aHomeType )
  {
    case EnumHomeTypeTACHO_VISUALIZER :
      HomeClass = EW_CLASS( HomeHOM11_TachoVisualizer );
    break;

    case EnumHomeTypeECO_VISUALIZER :
      HomeClass = EW_CLASS( HomeHOM12_EcoVisualizer );
    break;

    case EnumHomeTypeSPEED_VISUALIZER :
      HomeClass = EW_CLASS( HomeHOM13_SpeedVisualizer );
    break;

    case EnumHomeTypeNAVI_DEFAULT_VIEW :
      HomeClass = EW_CLASS( NavigationNAV01_DefaultView );
    break;

    case EnumHomeTypeNAVI_TURN_BY_TURN :
      HomeClass = EW_CLASS( NavigationNAV03_TBTListView );
    break;

    case EnumHomeTypeNAVI_NEXT_TURN :
      HomeClass = EW_CLASS( NavigationNAV05_TBTView );
    break;

    case EnumHomeTypeVEHICLE_INFO :
      HomeClass = EW_CLASS( HomeHOM03_VehicleInfo );
    break;

    default : 
      ;
  }

  return HomeClass;
}

/* 'C' function for method : 'Application::Application.HomeDialogOfHomeType()' */
CoreGroup ApplicationApplication_HomeDialogOfHomeType( ApplicationApplication _this, 
  XEnum aHomeType )
{
  CoreGroup aHomeDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  aHomeDialog = 0;

  switch ( aHomeType )
  {
    case EnumHomeTypeTACHO_VISUALIZER :
      aHomeDialog = ((CoreGroup)EwNewObject( HomeHOM11_TachoVisualizer, 0 ));
    break;

    case EnumHomeTypeECO_VISUALIZER :
      aHomeDialog = ((CoreGroup)EwNewObject( HomeHOM12_EcoVisualizer, 0 ));
    break;

    case EnumHomeTypeSPEED_VISUALIZER :
      aHomeDialog = ((CoreGroup)EwNewObject( HomeHOM13_SpeedVisualizer, 0 ));
    break;

    case EnumHomeTypeNAVI_DEFAULT_VIEW :
      aHomeDialog = ((CoreGroup)EwNewObject( NavigationNAV01_DefaultView, 0 ));
    break;

    case EnumHomeTypeNAVI_TURN_BY_TURN :
      aHomeDialog = ((CoreGroup)EwNewObject( NavigationNAV03_TBTListView, 0 ));
    break;

    case EnumHomeTypeNAVI_NEXT_TURN :
      aHomeDialog = ((CoreGroup)EwNewObject( NavigationNAV05_TBTView, 0 ));
    break;

    case EnumHomeTypeVEHICLE_INFO :
      aHomeDialog = ((CoreGroup)EwNewObject( HomeHOM03_VehicleInfo, 0 ));
    break;

    default : 
      ;
  }

  return aHomeDialog;
}

/* 'C' function for method : 'Application::Application.OnOpeningFinishedSlot()' */
void ApplicationApplication_OnOpeningFinishedSlot( ApplicationApplication _this, 
  XObject sender )
{
  CoreGroup OpeningDialog = EwCastObject( sender, CoreGroup );

  if ( OpeningDialog != 0 )
  {
    CoreGroup__DismissDialog( _this, OpeningDialog, 0, 0, 0, EwNullSlot, EwNullSlot, 
    0 );
  }

  _this->IsFactoryModeDialogDisplayed = 0;
  DeviceInterfaceBluetoothDeviceClass_GetBluetoothEnable( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
  DeviceInterfaceBluetoothDeviceClass ));
  ApplicationApplication_ShowDisclaimer( _this );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void ApplicationApplication_OnStartOpeningSlot( ApplicationApplication _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->CheckOpeningTimer, 0 );

  if ( EnumOperationModeFACTORY == DeviceInterfaceSystemDeviceClass_OnGetOperationMode( 
      EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )))
  {
    OpenOPN02_FactoryMode FactoryModeDialog = EwNewObject( OpenOPN02_FactoryMode, 
      0 );
    FactoryModeDialog->OnFactoryModeFinished = EwNewSlot( _this, ApplicationApplication_OnOpeningFinishedSlot );
    CoreGroup_SwitchToDialog((CoreGroup)_this, ((CoreGroup)FactoryModeDialog ), 
    0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    _this->IsFactoryModeDialogDisplayed = 1;
  }
  else
  {
    OpenOPN01_BootupAnimation BootupAnimationDialog = EwNewObject( OpenOPN01_BootupAnimation, 
      0 );
    BootupAnimationDialog->OnBootupAnimationFinished = EwNewSlot( _this, ApplicationApplication_OnOpeningFinishedSlot );
    CoreGroup_SwitchToDialog((CoreGroup)_this, ((CoreGroup)BootupAnimationDialog ), 
    0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* Return from the DD mode forbidden UI to the launcher */
void ApplicationApplication_ReturnToHome( ApplicationApplication _this )
{
  XInt32 NoOfDialogs;
  XInt32 i;

  EwTrace( "%s", EwLoadString( &_Const0004 ));
  NoOfDialogs = CoreGroup_CountDialogs((CoreGroup)_this );

  for ( i = 0; i < NoOfDialogs; i++ )
  {
    HomeBaseHome Dialog = EwCastObject( CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
      0 ), HomeBaseHome );

    if ( Dialog != 0 )
    {
      HomeBaseHome_ReturnToHome( Dialog );
    }
    else
    {
      CoreGroup__DismissDialog( _this, CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
      0 ), 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
  }
}

/* 'C' function for method : 'Application::Application.OnCheckOpeningSlot()' */
void ApplicationApplication_OnCheckOpeningSlot( ApplicationApplication _this, XObject 
  sender )
{
  XBool IsTFTBacklightOn;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  IsTFTBacklightOn = DeviceInterfaceSystemDeviceClass_IsTFTBacklightOn( EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ));

  if ( IsTFTBacklightOn && DeviceInterfaceSystemDeviceClass_IsOperationModeReady( 
      EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )))
  {
    EwTrace( "%s%b", EwLoadString( &_Const0005 ), IsTFTBacklightOn );
    CoreTimer_OnSetEnabled( &_this->CheckOpeningTimer, 0 );
    EwSignal( EwNewSlot( _this, ApplicationApplication_OnStartOpeningSlot ), ((XObject)_this ));
  }
}

/* 'C' function for method : 'Application::Application.SlideInHome()' */
void ApplicationApplication_SlideInHome( ApplicationApplication _this, XEnum aHomeType )
{
  CoreGroup HomeDialog = ApplicationApplication_HomeDialogOfHomeType( _this, aHomeType );

  EwTrace( "%s%$", EwLoadString( &_Const0006 ), EwClassOf(((XObject)HomeDialog )));
  CoreGroup_PresentDialog((CoreGroup)_this, HomeDialog, ((EffectsTransition)EwGetAutoObject( 
  &EffectSlideInTransition, EffectSlideTransitionNoFade )), 0, 0, 0, 0, 0, EwNewSlot( 
  _this, ApplicationApplication_OnSlideInHomeFinishedSlot ), EwNullSlot, 0 );
  DeviceInterfaceSystemDeviceClass_OnSetHomeType( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ), aHomeType );
}

/* 'C' function for method : 'Application::Application.OnSlideInHomeFinishedSlot()' */
void ApplicationApplication_OnSlideInHomeFinishedSlot( ApplicationApplication _this, 
  XObject sender )
{
  XInt32 DialogIdx;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  DialogIdx = 1;

  while ( 1 < CoreGroup_CountDialogs((CoreGroup)_this ))
  {
    CoreGroup__DismissDialog( _this, CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
    DialogIdx ), ((EffectsTransition)EwGetAutoObject( &EffectNoSlideOut, EffectSlideTransitionNoFade )), 
    0, 0, EwNullSlot, EwNullSlot, 0 );
  }
}

/* 'C' function for method : 'Application::Application.OnPhoneCallStateChangedSlot()' */
void ApplicationApplication_OnPhoneCallStateChangedSlot( ApplicationApplication _this, 
  XObject sender )
{
  XEnum PhoneCallState;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  PhoneCallState = DeviceInterfaceNotificationDeviceClass_GetPhoneCallState( EwGetAutoObject( 
  &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass ));

  switch ( PhoneCallState )
  {
    case EnumPhoneCallStateINCOMING_STARTED :
    {
      if ( _this->IsDisclaimerDismissed && !_this->IsFactoryTest )
      {
        TelephoneTEL01_IncomingCall IncomingCallDialog = EwNewObject( TelephoneTEL01_IncomingCall, 
          0 );
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)IncomingCallDialog ), 
        0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
    }
    break;

    default : 
      ;
  }
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void ApplicationApplication_OnInspectionModeEventSlot( ApplicationApplication _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->IsFactoryModeDialogDisplayed )
  {
    switch ( EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->InspectionMode )
    {
      case EnumInspectionModeDISPLAY :
        ApplicationApplication_ProcInspectionDisplay( _this );
      break;

      case EnumInspectionModeEND :
        ApplicationApplication_StopInspection( _this );
      break;

      default : 
        ;
    }
  }
  else
  {
    DeviceInterfaceSystemDeviceClass_SendInspectionResponse( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
    DeviceInterfaceSystemDeviceClass ), EwGetAutoObject( &DeviceInterfaceSystemDevice, 
    DeviceInterfaceSystemDeviceClass )->InspectionMode, 255 );
  }
}

/* 'C' function for method : 'Application::Application.ProcInspectionDisplay()' */
void ApplicationApplication_ProcInspectionDisplay( ApplicationApplication _this )
{
  InspectionTFT_Main InspectionDialog = EwCastObject( CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
    0 ), InspectionTFT_Main );

  if ( InspectionDialog == 0 )
  {
    InspectionDialog = EwNewObject( InspectionTFT_Main, 0 );
    CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)InspectionDialog ), 0, 
    0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
  }

  InspectionTFT_Main_OnSetPattern( InspectionDialog, EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass )->InspectionDisplayPattern );
}

/* 'C' function for method : 'Application::Application.StopInspection()' */
void ApplicationApplication_StopInspection( ApplicationApplication _this )
{
  InspectionTFT_Main InspectionDialog = EwCastObject( CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
    0 ), InspectionTFT_Main );

  if ( InspectionDialog != 0 )
  {
    CoreGroup__DismissDialog( _this, ((CoreGroup)InspectionDialog ), 0, 0, 0, EwNullSlot, 
    EwNullSlot, 0 );
  }

  DeviceInterfaceSystemDeviceClass_SendInspectionResponse( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ), EnumInspectionModeEND, 0 );
}

/* 'C' function for method : 'Application::Application.SwitchToMeterHome()' */
void ApplicationApplication_SwitchToMeterHome( ApplicationApplication _this )
{
  XEnum MeterHomeType;

  switch ( EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->CurrentMeterDisplay )
  {
    case EnumMeterDisplayTACHOMETER :
      MeterHomeType = EnumHomeTypeTACHO_VISUALIZER;
    break;

    case EnumMeterDisplayECHO_METER :
      MeterHomeType = EnumHomeTypeECO_VISUALIZER;
    break;

    case EnumMeterDisplaySPEED_METER :
      MeterHomeType = EnumHomeTypeSPEED_VISUALIZER;
    break;

    default : 
      MeterHomeType = EnumHomeTypeTACHO_VISUALIZER;
  }

  ApplicationApplication_SwitchToHome( _this, MeterHomeType );
}

/* Variants derived from the class : 'Application::Application' */
EW_DEFINE_CLASS_VARIANTS( ApplicationApplication )
EW_END_OF_CLASS_VARIANTS( ApplicationApplication )

/* Virtual Method Table (VMT) for the class : 'Application::Application' */
EW_DEFINE_CLASS( ApplicationApplication, CoreRoot, FactoryTestEventHandler, FactoryTestEventHandler, 
                 FactoryTestEventHandler, FactoryTestEventHandler, IsFactoryModeDialogDisplayed, 
                 IsFactoryModeDialogDisplayed, "Application::Application" )
  CoreRectView_initLayoutContext,
  CoreRoot_GetRoot,
  CoreRoot_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreRoot_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreRoot_OnSetFocus,
  CoreRoot_OnSetBuffered,
  CoreGroup_OnGetEnabled,
  CoreGroup_OnSetEnabled,
  CoreRoot_OnSetOpacity,
  CoreGroup_OnSetVisible,
  CoreRoot_IsCurrentDialog,
  CoreRoot_IsActiveDialog,
  CoreGroup_DismissDialog,
  CoreRoot_DispatchEvent,
  CoreRoot_BroadcastEvent,
  CoreGroup_UpdateLayout,
  CoreGroup_UpdateViewState,
  CoreRoot_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
EW_END_OF_CLASS( ApplicationApplication )

/* Embedded Wizard */
