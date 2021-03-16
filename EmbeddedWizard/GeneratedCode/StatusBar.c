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
#include "_CorePropertyObserver.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreView.h"
#include "_DeviceInterfaceBluetoothDeviceClass.h"
#include "_DeviceInterfaceMotoConContext.h"
#include "_DeviceInterfaceRtcTime.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_DeviceInterfaceVehicleDataClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_StatusBarClock.h"
#include "_StatusBarMain.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Fonts.h"
#include "Resource.h"
#include "StatusBar.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x0000000C, /* ratio 166.67 % */
  0xB8000900, 0x80074452, 0x04010883, 0x00000004, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 38 }};
static const XColor _Const0001 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0002 = {{ 0, 36 }, { 480, 38 }};
static const XRect _Const0003 = {{ 11, 0 }, { 93, 38 }};
static const XRect _Const0004 = {{ 228, 3 }, { 260, 35 }};
static const XRect _Const0005 = {{ 294, 3 }, { 326, 35 }};
static const XRect _Const0006 = {{ 261, 3 }, { 293, 35 }};
static const XRect _Const0007 = {{ 96, 3 }, { 128, 35 }};
static const XRect _Const0008 = {{ 195, 3 }, { 227, 35 }};
static const XRect _Const0009 = {{ 0, 0 }, { 82, 38 }};
static const XRect _Const000A = {{ 1, 0 }, { 38, 37 }};
static const XColor _Const000B = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const000C = {{ 48, 0 }, { 82, 37 }};
static const XRect _Const000D = {{ 37, 0 }, { 48, 37 }};
static const XStringRes _Const000E = { _StringsDefault0, 0x0002 };

/* User defined inline code: 'StatusBar::Inline' */
#include "BC_motocon_pub.h"
#include "BC_motocon_pub_type.h"

/* Initializer for the class 'StatusBar::Main' */
void StatusBarMain__Init( StatusBarMain _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( StatusBarMain );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Background, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Divider, &_this->_XObject, 0 );
  StatusBarClock__Init( &_this->Clock, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->MotoConEventHandler, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->BatteryIcon, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->HeadsetIcon, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->AppIcon, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->BtIcon, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->BTEnabledObserver, &_this->_XObject, 0 );
  CorePropertyObserver__Init( &_this->PairdDeviceChangedObserver, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->SignalLevelIcon, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->VehicleDataReceivedEventHandler, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( StatusBarMain );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Background, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Background, _Const0001 );
  CoreRectView__OnSetBounds( &_this->Divider, _Const0002 );
  ViewsImage_OnSetAlignment( &_this->Divider, ViewsImageAlignmentAlignVertBottom 
  | ViewsImageAlignmentScaleToFit );
  CoreRectView__OnSetBounds( &_this->Clock, _Const0003 );
  CoreGroup_OnSetVisible((CoreGroup)&_this->Clock, 0 );
  CoreRectView__OnSetBounds( &_this->BatteryIcon, _Const0004 );
  ViewsImage_OnSetVisible( &_this->BatteryIcon, 0 );
  CoreRectView__OnSetBounds( &_this->HeadsetIcon, _Const0005 );
  ViewsImage_OnSetVisible( &_this->HeadsetIcon, 0 );
  CoreRectView__OnSetBounds( &_this->AppIcon, _Const0006 );
  ViewsImage_OnSetVisible( &_this->AppIcon, 0 );
  CoreRectView__OnSetBounds( &_this->BtIcon, _Const0007 );
  ViewsImage_OnSetVisible( &_this->BtIcon, 0 );
  CoreRectView__OnSetBounds( &_this->SignalLevelIcon, _Const0008 );
  ViewsImage_OnSetVisible( &_this->SignalLevelIcon, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Background ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Clock ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BatteryIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->HeadsetIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->AppIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BtIcon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SignalLevelIcon ), 0 );
  ViewsImage_OnSetBitmap( &_this->Divider, EwLoadResource( &ResourceStatusBarDivider, 
  ResourcesBitmap ));
  _this->MotoConEventHandler.OnEvent = EwNewSlot( _this, StatusBarMain_OnMotoConEventReceived );
  CoreSystemEventHandler_OnSetEvent( &_this->MotoConEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->MotoConSystemEvent );
  ViewsImage_OnSetBitmap( &_this->BatteryIcon, EwLoadResource( &ResourceBatteryNotChagingIcon, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->HeadsetIcon, EwLoadResource( &ResourceHeadsetIcon, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->AppIcon, EwLoadResource( &ResourceAppIcon, ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->BtIcon, EwLoadResource( &ResourceStatusBarBtIcon, 
  ResourcesBitmap ));
  _this->BTEnabledObserver.OnEvent = EwNewSlot( _this, StatusBarMain_OnBtcConnectionStatusChangedSlot );
  CorePropertyObserver_OnSetOutlet( &_this->BTEnabledObserver, EwNewRef( EwGetAutoObject( 
  &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), DeviceInterfaceBluetoothDeviceClass_OnGetBluetoothEnable, 
  DeviceInterfaceBluetoothDeviceClass_OnSetBluetoothEnable ));
  _this->PairdDeviceChangedObserver.OnEvent = EwNewSlot( _this, StatusBarMain_OnBtcConnectionStatusChangedSlot );
  CorePropertyObserver_OnSetOutlet( &_this->PairdDeviceChangedObserver, EwNewRef( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ), 
  DeviceInterfaceBluetoothDeviceClass_OnGetRefreshPairedDeviceList, DeviceInterfaceBluetoothDeviceClass_OnSetRefreshPairedDeviceList ));
  ViewsImage_OnSetBitmap( &_this->SignalLevelIcon, EwLoadResource( &ResourceSignalLevelIcon, 
  ResourcesBitmap ));
  _this->VehicleDataReceivedEventHandler.OnEvent = EwNewSlot( _this, StatusBarMain_OnVehicleDataReceivedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->VehicleDataReceivedEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )->VehicleDataReceivedSystemEvent );
}

/* Re-Initializer for the class 'StatusBar::Main' */
void StatusBarMain__ReInit( StatusBarMain _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Background );
  ViewsImage__ReInit( &_this->Divider );
  StatusBarClock__ReInit( &_this->Clock );
  CoreSystemEventHandler__ReInit( &_this->MotoConEventHandler );
  ViewsImage__ReInit( &_this->BatteryIcon );
  ViewsImage__ReInit( &_this->HeadsetIcon );
  ViewsImage__ReInit( &_this->AppIcon );
  ViewsImage__ReInit( &_this->BtIcon );
  CorePropertyObserver__ReInit( &_this->BTEnabledObserver );
  CorePropertyObserver__ReInit( &_this->PairdDeviceChangedObserver );
  ViewsImage__ReInit( &_this->SignalLevelIcon );
  CoreSystemEventHandler__ReInit( &_this->VehicleDataReceivedEventHandler );
}

/* Finalizer method for the class 'StatusBar::Main' */
void StatusBarMain__Done( StatusBarMain _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Background );
  ViewsImage__Done( &_this->Divider );
  StatusBarClock__Done( &_this->Clock );
  CoreSystemEventHandler__Done( &_this->MotoConEventHandler );
  ViewsImage__Done( &_this->BatteryIcon );
  ViewsImage__Done( &_this->HeadsetIcon );
  ViewsImage__Done( &_this->AppIcon );
  ViewsImage__Done( &_this->BtIcon );
  CorePropertyObserver__Done( &_this->BTEnabledObserver );
  CorePropertyObserver__Done( &_this->PairdDeviceChangedObserver );
  ViewsImage__Done( &_this->SignalLevelIcon );
  CoreSystemEventHandler__Done( &_this->VehicleDataReceivedEventHandler );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void StatusBarMain_OnMotoConEventReceived( StatusBarMain _this, XObject sender )
{
  DeviceInterfaceMotoConContext MotoConContext;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  MotoConContext = EwCastObject( _this->MotoConEventHandler.Context, DeviceInterfaceMotoConContext );

  switch ( MotoConContext->RxEvent )
  {
    case EnumMotoConRxEventCONNECTION_STATUS :
      StatusBarMain_UpdateMotoConConnectionStatus( _this );
    break;

    case EnumMotoConRxEventPHONE_BATTERY :
      StatusBarMain_UpdateBatteryIcon( _this );
    break;

    case EnumMotoConRxEventPHONE_HEADSET :
      StatusBarMain_UpdateHeadsetIcon( _this );
    break;

    case EnumMotoConRxEventPHONE_THERMAL :
      StatusBarMain_UpdateAppIcon( _this );
    break;

    case EnumMotoConRxEventPHONE_CELL_SIGNAL_LEVEL :
      StatusBarMain_UpdatePhoneCellSignalLevelIcon( _this );
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'StatusBar::Main.UpdateMotoConConnectionStatus()' */
void StatusBarMain_UpdateMotoConConnectionStatus( StatusBarMain _this )
{
  _this->IsMotoConConnected = DeviceInterfaceBluetoothDeviceClass_IsMotoconConnected( 
  EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass ));

  if ( !_this->IsMotoConConnected )
  {
    ViewsImage_OnSetVisible( &_this->AppIcon, 0 );
    ViewsImage_OnSetVisible( &_this->BatteryIcon, 0 );
    ViewsImage_OnSetVisible( &_this->HeadsetIcon, 0 );
  }
  else
  {
    StatusBarMain_UpdateAppIcon( _this );
  }
}

/* 'C' function for method : 'StatusBar::Main.UpdateBatteryIcon()' */
void StatusBarMain_UpdateBatteryIcon( StatusBarMain _this )
{
  XBool IsBatteryCharging = 0;
  XUInt8 PhoneBatteryPercentage = 0;

  {
    bc_motocon_battery_t charging_state = BC_motocon_get_battery_charging_state();
    if( BC_MOTOCON_BATTERY_CHARGING == charging_state )
    {
      IsBatteryCharging = true;
    }
    PhoneBatteryPercentage = BC_motocon_get_battery_percentage();
  }

  if ( _this->IsMotoConConnected )
  {
    if ( IsBatteryCharging )
    {
      ViewsImage_OnSetBitmap( &_this->BatteryIcon, EwLoadResource( &ResourceBatteryChagingIcon, 
      ResourcesBitmap ));
    }
    else
    {
      ViewsImage_OnSetBitmap( &_this->BatteryIcon, EwLoadResource( &ResourceBatteryNotChagingIcon, 
      ResourcesBitmap ));
    }

    if ( PhoneBatteryPercentage >= 81 )
    {
      ViewsImage_OnSetFrameNumber( &_this->BatteryIcon, 5 );
    }
    else
      if ( PhoneBatteryPercentage >= 61 )
      {
        ViewsImage_OnSetFrameNumber( &_this->BatteryIcon, 4 );
      }
      else
        if ( PhoneBatteryPercentage >= 41 )
        {
          ViewsImage_OnSetFrameNumber( &_this->BatteryIcon, 3 );
        }
        else
          if ( PhoneBatteryPercentage >= 16 )
          {
            ViewsImage_OnSetFrameNumber( &_this->BatteryIcon, 2 );
          }
          else
            if ( PhoneBatteryPercentage >= 4 )
            {
              ViewsImage_OnSetFrameNumber( &_this->BatteryIcon, 1 );
            }
            else
            {
              ViewsImage_OnSetFrameNumber( &_this->BatteryIcon, 0 );
            }

    ViewsImage_OnSetVisible( &_this->BatteryIcon, 1 );
  }
}

/* 'C' function for method : 'StatusBar::Main.UpdateHeadsetIcon()' */
void StatusBarMain_UpdateHeadsetIcon( StatusBarMain _this )
{
  XBool IsHeadsetConnected = 0;

  {
    bc_motocon_bt_headset_state_t headset_state = BC_motocon_get_bt_headset_state();
    if( BC_MOTOCON_HEADSET_CONNECTED == headset_state )
    {
      IsHeadsetConnected = true;
    }
  }

  if ( _this->IsMotoConConnected && IsHeadsetConnected )
  {
    ViewsImage_OnSetVisible( &_this->HeadsetIcon, 1 );
  }
  else
  {
    ViewsImage_OnSetVisible( &_this->HeadsetIcon, 0 );
  }
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void StatusBarMain_OnBtcConnectionStatusChangedSlot( StatusBarMain _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )->BluetoothEnable )
  {
    if ( DeviceInterfaceBluetoothDeviceClass_IsBtConnected( EwGetAutoObject( &DeviceInterfaceBluetoothDevice, 
        DeviceInterfaceBluetoothDeviceClass )))
    {
      ViewsImage_OnSetFrameNumber( &_this->BtIcon, 1 );
    }
    else
    {
      ViewsImage_OnSetFrameNumber( &_this->BtIcon, 0 );
    }

    ViewsImage_OnSetVisible( &_this->BtIcon, 1 );
  }
  else
  {
    ViewsImage_OnSetVisible( &_this->BtIcon, 0 );
  }
}

/* 'C' function for method : 'StatusBar::Main.UpdateAppIcon()' */
void StatusBarMain_UpdateAppIcon( StatusBarMain _this )
{
  if ( _this->IsMotoConConnected )
  {
    XBool IsPhoneThermalHigh = 0;
    {
      bc_motocon_thermal_state_t charging_state = BC_motocon_get_phone_thermal();
      if( BC_MOTOCON_THERMAL_HIGH == charging_state )
      {
        IsPhoneThermalHigh = true;
      }
    }

    if ( IsPhoneThermalHigh )
    {
      ViewsImage_OnSetFrameNumber( &_this->AppIcon, 1 );
    }
    else
    {
      ViewsImage_OnSetFrameNumber( &_this->AppIcon, 0 );
    }
  }

  ViewsImage_OnSetVisible( &_this->AppIcon, _this->IsMotoConConnected );
}

/* 'C' function for method : 'StatusBar::Main.UpdatePhoneCellSignalLevelIcon()' */
void StatusBarMain_UpdatePhoneCellSignalLevelIcon( StatusBarMain _this )
{
  if ( _this->IsMotoConConnected )
  {
    XUInt8 PhoneCellSignalLevel = 0;
    PhoneCellSignalLevel = BC_motocon_get_phone_cell_signal_level();

    if ( 4 >= PhoneCellSignalLevel )
    {
      ViewsImage_OnSetFrameNumber( &_this->SignalLevelIcon, PhoneCellSignalLevel );
    }
  }

  ViewsImage_OnSetVisible( &_this->SignalLevelIcon, _this->IsMotoConConnected );
}

/* This slot method is executed when the associated system event handler 'SystemEventHandler' 
   receives an event. */
void StatusBarMain_OnVehicleDataReceivedSlot( StatusBarMain _this, XObject sender )
{
  DeviceInterfaceVehicleDataClass VehicleData;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  VehicleData = EwCastObject( _this->VehicleDataReceivedEventHandler.Context, DeviceInterfaceVehicleDataClass );

  if ( VehicleData != 0 )
  {
    switch ( VehicleData->RxType )
    {
      case EnumVehicleRxTypeSUPPORT_FUNC_CLOCK :
        CoreGroup_OnSetVisible((CoreGroup)&_this->Clock, DeviceInterfaceVehicleDeviceClass_IsVehicleFunctionSupported( 
        EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass ), 
        EnumVehicleSupportedFunctionCLOCK ));
      break;

      default : 
        ;
    }
  }
}

/* Variants derived from the class : 'StatusBar::Main' */
EW_DEFINE_CLASS_VARIANTS( StatusBarMain )
EW_END_OF_CLASS_VARIANTS( StatusBarMain )

/* Virtual Method Table (VMT) for the class : 'StatusBar::Main' */
EW_DEFINE_CLASS( StatusBarMain, CoreGroup, Background, Background, Background, Background, 
                 IsMotoConConnected, IsMotoConConnected, "StatusBar::Main" )
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
EW_END_OF_CLASS( StatusBarMain )

/* Initializer for the class 'StatusBar::Clock' */
void StatusBarClock__Init( StatusBarClock _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( StatusBarClock );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->ClockHourText, &_this->_XObject, 0 );
  CoreSystemEventHandler__Init( &_this->OnUpdateLocalTimeEventHandler, &_this->_XObject, 0 );
  ViewsText__Init( &_this->ClockMinuteText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->ClockColonText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( StatusBarClock );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0009 );
  CoreRectView__OnSetBounds( &_this->ClockHourText, _Const000A );
  ViewsText_OnSetAlignment( &_this->ClockHourText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ClockHourText, 0 );
  ViewsText_OnSetColor( &_this->ClockHourText, _Const000B );
  ViewsText_OnSetVisible( &_this->ClockHourText, 1 );
  CoreRectView__OnSetBounds( &_this->ClockMinuteText, _Const000C );
  ViewsText_OnSetAlignment( &_this->ClockMinuteText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ClockMinuteText, 0 );
  ViewsText_OnSetColor( &_this->ClockMinuteText, _Const000B );
  ViewsText_OnSetVisible( &_this->ClockMinuteText, 1 );
  CoreRectView__OnSetBounds( &_this->ClockColonText, _Const000D );
  ViewsText_OnSetAlignment( &_this->ClockColonText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ClockColonText, EwLoadString( &_Const000E ));
  ViewsText_OnSetColor( &_this->ClockColonText, _Const000B );
  ViewsText_OnSetVisible( &_this->ClockColonText, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ClockHourText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ClockMinuteText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ClockColonText ), 0 );
  ViewsText_OnSetFont( &_this->ClockHourText, EwLoadResource( &FontsNotoSansMedium32pt, 
  ResourcesFont ));
  _this->OnUpdateLocalTimeEventHandler.OnEvent = EwNewSlot( _this, StatusBarClock_OnUpdateLocalTimeSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->OnUpdateLocalTimeEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->UpdateLocalTimeSystemEvent );
  ViewsText_OnSetFont( &_this->ClockMinuteText, EwLoadResource( &FontsNotoSansMedium32pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->ClockColonText, EwLoadResource( &FontsNotoSansMedium32pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'StatusBar::Clock' */
void StatusBarClock__ReInit( StatusBarClock _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->ClockHourText );
  CoreSystemEventHandler__ReInit( &_this->OnUpdateLocalTimeEventHandler );
  ViewsText__ReInit( &_this->ClockMinuteText );
  ViewsText__ReInit( &_this->ClockColonText );
}

/* Finalizer method for the class 'StatusBar::Clock' */
void StatusBarClock__Done( StatusBarClock _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->ClockHourText );
  CoreSystemEventHandler__Done( &_this->OnUpdateLocalTimeEventHandler );
  ViewsText__Done( &_this->ClockMinuteText );
  ViewsText__Done( &_this->ClockColonText );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* 'C' function for method : 'StatusBar::Clock.OnUpdateLocalTimeSlot()' */
void StatusBarClock_OnUpdateLocalTimeSlot( StatusBarClock _this, XObject sender )
{
  DeviceInterfaceRtcTime CurrentTime;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CurrentTime = DeviceInterfaceSystemDeviceClass_GetLocalTime( EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ));

  if ( CurrentTime->Hour > 12 )
  {
    CurrentTime->Hour = (XUInt8)( CurrentTime->Hour - 12 );
  }

  ViewsText_OnSetString( &_this->ClockHourText, EwNewStringInt( CurrentTime->Hour, 
  0, 10 ));
  ViewsText_OnSetString( &_this->ClockMinuteText, EwNewStringInt( CurrentTime->Minute, 
  2, 10 ));
  ViewsText_OnSetVisible( &_this->ClockColonText, (XBool)!ViewsText_OnGetVisible( 
  &_this->ClockColonText ));
}

/* Variants derived from the class : 'StatusBar::Clock' */
EW_DEFINE_CLASS_VARIANTS( StatusBarClock )
EW_END_OF_CLASS_VARIANTS( StatusBarClock )

/* Virtual Method Table (VMT) for the class : 'StatusBar::Clock' */
EW_DEFINE_CLASS( StatusBarClock, CoreGroup, ClockHourText, ClockHourText, ClockHourText, 
                 ClockHourText, _None, _None, "StatusBar::Clock" )
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
EW_END_OF_CLASS( StatusBarClock )

/* Embedded Wizard */
