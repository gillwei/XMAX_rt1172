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
#include "_ComponentsStatusBar.h"
#include "_CoreGroup.h"
#include "_CorePropertyObserver.h"
#include "_CoreRoot.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreView.h"
#include "_DeviceInterfaceBluetoothDeviceClass.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_FactoryDisplayAutoRun.h"
#include "_FactoryDisplayManual.h"
#include "_FactoryTestContext.h"
#include "_HomeHOM11_tachometer.h"
#include "_SettingsBtFwUpdateDialog.h"
#include "_TopTOP01_Disclaimer.h"
#include "Application.h"
#include "DeviceInterface.h"
#include "Enum.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000080, /* ratio 78.13 % */
  0xB8002D00, 0x000A6452, 0x1CC2003A, 0xC0075004, 0x1242001C, 0x00039002, 0x002B0004,
  0x08CC38D2, 0x36000C40, 0xD000CA00, 0xC9801151, 0x908B0305, 0x0DB0F8E1, 0x4D168DCB,
  0x64594876, 0x3637CDA2, 0x88545A49, 0x974E0004, 0x54708922, 0x99E71208, 0x5A1F1A92,
  0xA3F0C374, 0x01509353, 0x00000404, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XRect _Const0001 = {{ 0, 0 }, { 480, 32 }};
static const XStringRes _Const0002 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0003 = { _StringsDefault0, 0x0018 };
static const XStringRes _Const0004 = { _StringsDefault0, 0x0023 };

/* Initializer for the class 'Application::Application' */
void ApplicationApplication__Init( ApplicationApplication _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRoot__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( ApplicationApplication );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->FactoryTestEventHandler, &_this->_XObject, 0 );
  ComponentsStatusBar__Init( &_this->StatusBar, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->BtFwStatusObserver, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ApplicationApplication );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->StatusBar, _Const0001 );
  _this->StatusBarVisible = 1;
  CoreGroup__Add( _this, ((CoreView)&_this->StatusBar ), 0 );
  _this->FactoryTestEventHandler.OnEvent = EwNewSlot( _this, ApplicationApplication_OnFactoryTestEventSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->FactoryTestEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->FactoryTestSystemEvent );
  _this->BtFwStatusObserver.OnEvent = EwNewSlot( _this, ApplicationApplication_OnBtFwStatusUpdteSlot );
  CorePropertyObserver_OnSetOutlet( &_this->BtFwStatusObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), DeviceInterfaceBluetoothDeviceClass_OnGetBtFwStatus, 
  DeviceInterfaceBluetoothDeviceClass_OnSetBtFwStatus ));

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
  ComponentsStatusBar__ReInit( &_this->StatusBar );
  CorePropertyObserver__ReInit( &_this->BtFwStatusObserver );
}

/* Finalizer method for the class 'Application::Application' */
void ApplicationApplication__Done( ApplicationApplication _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreRoot );

  /* Finalize all embedded objects */
  CoreSystemEventHandler__Done( &_this->FactoryTestEventHandler );
  ComponentsStatusBar__Done( &_this->StatusBar );
  CorePropertyObserver__Done( &_this->BtFwStatusObserver );

  /* Don't forget to deinitialize the super class ... */
  CoreRoot__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationApplication_Init( ApplicationApplication _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  ApplicationApplication_ShowDisclaimer( _this );
}

/* 'C' function for method : 'Application::Application.OnDisclaimerAcceptedSlot()' */
void ApplicationApplication_OnDisclaimerAcceptedSlot( ApplicationApplication _this, 
  XObject sender )
{
  TopTOP01_Disclaimer Disclaimer = EwCastObject( sender, TopTOP01_Disclaimer );

  if ( Disclaimer != 0 )
  {
    CoreRoot_EndModal( CoreView__GetRoot( _this ), ((CoreGroup)Disclaimer ));
    CoreGroup__Remove( CoreView__GetRoot( _this ), ((CoreView)Disclaimer ));
  }

  CoreView_OnSetStackingPriority((CoreView)&_this->StatusBar, 1 );
  CoreGroup_SwitchToDialog((CoreGroup)CoreView__GetRoot( _this ), ((CoreGroup)EwNewObject( 
  HomeHOM11_tachometer, 0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Application::Application.ShowDisclaimer()' */
void ApplicationApplication_ShowDisclaimer( ApplicationApplication _this )
{
  TopTOP01_Disclaimer Disclaimer = EwNewObject( TopTOP01_Disclaimer, 0 );

  Disclaimer->OnAcceptButtonClicked = EwNewSlot( _this, ApplicationApplication_OnDisclaimerAcceptedSlot );
  CoreGroup__Add( CoreView__GetRoot( _this ), ((CoreView)Disclaimer ), 0 );
  CoreRoot_BeginModal( CoreView__GetRoot( _this ), ((CoreGroup)Disclaimer ));
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
        FactoryDisplayManual FactoryTestDialog;
        ApplicationApplication_OnSetStatusBarVisible( _this, 0 );
        FactoryTestDialog = EwCastObject( CoreGroup_FindDialogByClass((CoreGroup)_this, 
        EW_CLASS( FactoryDisplayManual )), FactoryDisplayManual );

        if ( FactoryTestDialog == 0 )
        {
          FactoryTestDialog = EwNewObject( FactoryDisplayManual, 0 );
          CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)FactoryTestDialog ), 
          0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
        }

        FactoryDisplayManual_OnSetPatternIdx( FactoryTestDialog, TestContext->Data );
      }
      break;

      case EnumFactoryTestBurnInStart :
      {
        FactoryDisplayAutoRun DisplayAutoRunDialog;
        ApplicationApplication_OnSetStatusBarVisible( _this, 0 );
        DisplayAutoRunDialog = EwNewObject( FactoryDisplayAutoRun, 0 );
        FactoryDisplayAutoRun_OnSetBurnInEnabled( DisplayAutoRunDialog, 1 );
        CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)DisplayAutoRunDialog ), 
        0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
      }
      break;

      case EnumFactoryTestQuit :
      {
        ApplicationApplication_DismissFactoryTestDialog( _this );
        ApplicationApplication_OnSetStatusBarVisible( _this, 1 );
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
    CoreGroup_OnSetVisible((CoreGroup)&_this->StatusBar, value );
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
void ApplicationApplication_SwitchToHome( ApplicationApplication _this, CoreGroup 
  aHomeDialog )
{
  if ( aHomeDialog != 0 )
  {
    while ( CoreGroup_CountDialogs((CoreGroup)_this ) > 0 )
    {
      EwTrace( "%s%$", EwLoadString( &_Const0003 ), EwClassOf(((XObject)CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
        0 ))));
      CoreGroup__DismissDialog( _this, CoreGroup_GetDialogAtIndex((CoreGroup)_this, 
      0 ), 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }

    CoreGroup_SwitchToDialog((CoreGroup)_this, aHomeDialog, 0, 0, 0, 0, 0, 0, 0, 
    EwNullSlot, EwNullSlot, 0 );
  }
  else
  {
    EwTrace( "%s", EwLoadString( &_Const0004 ));
  }
}

/* Variants derived from the class : 'Application::Application' */
EW_DEFINE_CLASS_VARIANTS( ApplicationApplication )
EW_END_OF_CLASS_VARIANTS( ApplicationApplication )

/* Virtual Method Table (VMT) for the class : 'Application::Application' */
EW_DEFINE_CLASS( ApplicationApplication, CoreRoot, FactoryTestEventHandler, FactoryTestEventHandler, 
                 FactoryTestEventHandler, FactoryTestEventHandler, StatusBarVisible, 
                 StatusBarVisible, "Application::Application" )
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
