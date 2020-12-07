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
#include "_CoreSystemEvent.h"
#include "_CoreTimer.h"
#include "_DeviceInterfaceBluetoothDeviceClass.h"
#include "_DeviceInterfaceBluetoothPairedDeviceInfo.h"
#include "_DeviceInterfaceMediaManagerDeviceClass.h"
#include "_DeviceInterfaceNavigationDeviceClass.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_FactoryTestContext.h"
#include "DeviceInterface.h"
#include "Enum.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000222, /* ratio 55.68 % */
  0xB8002500, 0x000A6452, 0x00C2003A, 0x80107390, 0x16750010, 0x20037002, 0x540044C9,
  0x30019400, 0x000021A7, 0x04160619, 0x1BC00680, 0x421C7700, 0x22D14894, 0x3B1B8CC5,
  0x91A29422, 0x0D364AE3, 0xF1000075, 0x9105C011, 0x4C364C4E, 0x800CC003, 0x1001183C,
  0xE3738845, 0x2F099210, 0x0649A99E, 0x1F9E4E80, 0x8A150031, 0xA451A890, 0xB5762441,
  0x4969F089, 0x6EA71485, 0xE7B57AAC, 0x4F41824F, 0x200AFD8E, 0x2B314E2C, 0x1B3000DB,
  0xAB552D35, 0xD8767B3B, 0xD169572A, 0x00A000A3, 0xE910A9C0, 0x11068646, 0x14E8442A,
  0x6A005A2A, 0xFC0DB001, 0x22C88211, 0xB1C2A38B, 0x512936B9, 0x7EDB1BBD, 0xC892206C,
  0x0D93864A, 0x1AA8A49F, 0x34826780, 0x4855EA37, 0xB1CF2294, 0x056301A8, 0xD0F081B0,
  0x2B1548C3, 0x4D71D8EC, 0x6A47A44D, 0x951C7C52, 0x3DE166B2, 0x727C12B5, 0x8446E0D1,
  0xFC46710F, 0x4970B42E, 0xE21514D0, 0x4019CA6D, 0x1173E305, 0x6468443F, 0xD5C88020,
  0xCDAC7657, 0x007CE440, 0x4564A5F5, 0xD6D50C4D, 0x01010013, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XStringRes _Const0000 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0001 = { _StringsDefault0, 0x0014 };
static const XStringRes _Const0002 = { _StringsDefault0, 0x002D };
static const XStringRes _Const0003 = { _StringsDefault0, 0x0044 };
static const XStringRes _Const0004 = { _StringsDefault0, 0x005C };
static const XStringRes _Const0005 = { _StringsDefault0, 0x0073 };
static const XStringRes _Const0006 = { _StringsDefault0, 0x0090 };
static const XStringRes _Const0007 = { _StringsDefault0, 0x00A0 };
static const XStringRes _Const0008 = { _StringsDefault0, 0x00AD };
static const XStringRes _Const0009 = { _StringsDefault0, 0x00BD };
static const XStringRes _Const000A = { _StringsDefault0, 0x00D8 };
static const XStringRes _Const000B = { _StringsDefault0, 0x00F0 };
static const XStringRes _Const000C = { _StringsDefault0, 0x0105 };

/* User defined inline code: 'DeviceInterface::Inline' */
#include <stddef.h>
#include <stdlib.h>
#include "ew_priv.h"
#include "EEPM_pub.h"
#include "PERIPHERAL_pub.h"
/* uncomment these lines when integrating media manager
#include "MM_pub_ams_type.h"
#include "MM_pub.h"
*/


/* Initializer for the class 'DeviceInterface::SystemDeviceClass' */
void DeviceInterfaceSystemDeviceClass__Init( DeviceInterfaceSystemDeviceClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  TemplatesDeviceClass__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DeviceInterfaceSystemDeviceClass );

  /* ... then construct all embedded objects */
  CoreSystemEvent__Init( &_this->FactoryTestSystemEvent, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->FactoryResetTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DeviceInterfaceSystemDeviceClass );

  /* ... and initialize objects, variables, properties, etc. */
  CoreTimer_OnSetPeriod( &_this->FactoryResetTimer, 2000 );
  CoreTimer_OnSetEnabled( &_this->FactoryResetTimer, 0 );
  _this->BrightnessLevel = 7;
  _this->FactoryResetTimer.OnTrigger = EwNewSlot( _this, DeviceInterfaceSystemDeviceClass_OnFactoryResetTimeoutSlot );
}

/* Re-Initializer for the class 'DeviceInterface::SystemDeviceClass' */
void DeviceInterfaceSystemDeviceClass__ReInit( DeviceInterfaceSystemDeviceClass _this )
{
  /* At first re-initialize the super class ... */
  TemplatesDeviceClass__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEvent__ReInit( &_this->FactoryTestSystemEvent );
  CoreTimer__ReInit( &_this->FactoryResetTimer );
}

/* Finalizer method for the class 'DeviceInterface::SystemDeviceClass' */
void DeviceInterfaceSystemDeviceClass__Done( DeviceInterfaceSystemDeviceClass _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( TemplatesDeviceClass );

  /* Finalize all embedded objects */
  CoreSystemEvent__Done( &_this->FactoryTestSystemEvent );
  CoreTimer__Done( &_this->FactoryResetTimer );

  /* Don't forget to deinitialize the super class ... */
  TemplatesDeviceClass__Done( &_this->_Super );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.QuitTest()' */
void DeviceInterfaceSystemDeviceClass_QuitTest( DeviceInterfaceSystemDeviceClass _this )
{
  FactoryTestContext TestContext = EwNewObject( FactoryTestContext, 0 );

  TestContext->TestItem = EnumFactoryTestQuit;
  CoreSystemEvent_Trigger( &_this->FactoryTestSystemEvent, ((XObject)TestContext ), 
  0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.QuitTest()' */
void DeviceInterfaceSystemDeviceClass__QuitTest( void* _this )
{
  DeviceInterfaceSystemDeviceClass_QuitTest((DeviceInterfaceSystemDeviceClass)_this );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceSystemDeviceClass_TestDisplayPattern( DeviceInterfaceSystemDeviceClass _this, 
  XInt32 aIdx )
{
  FactoryTestContext TestContext = EwNewObject( FactoryTestContext, 0 );

  TestContext->TestItem = EnumFactoryTestDisplay;
  TestContext->Data = aIdx - 1;
  CoreSystemEvent_Trigger( &_this->FactoryTestSystemEvent, ((XObject)TestContext ), 
  0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.TestDisplayPattern()' */
void DeviceInterfaceSystemDeviceClass__TestDisplayPattern( void* _this, XInt32 aIdx )
{
  DeviceInterfaceSystemDeviceClass_TestDisplayPattern((DeviceInterfaceSystemDeviceClass)_this
  , aIdx );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.NotifyEsnRead()' */
void DeviceInterfaceSystemDeviceClass_NotifyEsnRead( DeviceInterfaceSystemDeviceClass _this, 
  XString aESN )
{
  DeviceInterfaceSystemDeviceClass_OnSetESN( _this, aESN );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.NotifyEsnRead()' */
void DeviceInterfaceSystemDeviceClass__NotifyEsnRead( void* _this, XString aESN )
{
  DeviceInterfaceSystemDeviceClass_NotifyEsnRead((DeviceInterfaceSystemDeviceClass)_this
  , aESN );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnSetESN()' */
void DeviceInterfaceSystemDeviceClass_OnSetESN( DeviceInterfaceSystemDeviceClass _this, 
  XString value )
{
  if ( EwCompString( _this->ESN, value ) != 0 )
  {
    _this->ESN = EwShareString( value );
    EwNotifyRefObservers( EwNewRef( _this, DeviceInterfaceSystemDeviceClass_OnGetESN, 
      DeviceInterfaceSystemDeviceClass_OnSetESN ), 0 );
  }
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnGetESN()' */
XString DeviceInterfaceSystemDeviceClass_OnGetESN( DeviceInterfaceSystemDeviceClass _this )
{
  if ( !EwCompString( 0, _this->ESN ))
  {
    ew_get_esn();
  }

  return _this->ESN;
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnGetSoftwareVersion()' */
XString DeviceInterfaceSystemDeviceClass_OnGetSoftwareVersion( DeviceInterfaceSystemDeviceClass _this )
{
  XString software_version = 0;

  if ( !EwCompString( 0, _this->SoftwareVersion ))
  {
    {
      char version[8];
      ew_get_software_version( version );
      software_version = EwNewStringAnsi( version );
    }
    _this->SoftwareVersion = EwShareString( software_version );
  }

  return _this->SoftwareVersion;
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnGetRtcTime()' */
XString DeviceInterfaceSystemDeviceClass_OnGetRtcTime( DeviceInterfaceSystemDeviceClass _this )
{
  XString rtc_time;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  rtc_time = 0;
  {
    char rtc_time_str[8];
    ew_get_rtc_time( rtc_time_str );
    rtc_time = EwNewStringAnsi( rtc_time_str );
  }
  return rtc_time;
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.ResetToFactoryDefault()' */
void DeviceInterfaceSystemDeviceClass_ResetToFactoryDefault( DeviceInterfaceSystemDeviceClass _this )
{
  CoreTimer_OnSetEnabled( &_this->FactoryResetTimer, 1 );
  ew_reset_to_factory_default();
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceSystemDeviceClass_NotifyFactoryResetComplete( DeviceInterfaceSystemDeviceClass _this )
{
  CoreTimer_OnSetEnabled( &_this->FactoryResetTimer, 0 );
  EwNotifyRefObservers( EwNewRef( _this, DeviceInterfaceSystemDeviceClass_OnGetFactoryResetComplete, 
    DeviceInterfaceSystemDeviceClass_OnSetFactoryResetComplete ), 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.NotifyFactoryResetComplete()' */
void DeviceInterfaceSystemDeviceClass__NotifyFactoryResetComplete( void* _this )
{
  DeviceInterfaceSystemDeviceClass_NotifyFactoryResetComplete((DeviceInterfaceSystemDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnFactoryResetTimeoutSlot()' */
void DeviceInterfaceSystemDeviceClass_OnFactoryResetTimeoutSlot( DeviceInterfaceSystemDeviceClass _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->FactoryResetTimer, 0 );
  DeviceInterfaceSystemDeviceClass_NotifyFactoryResetComplete( _this );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.RebootSystem()' */
void DeviceInterfaceSystemDeviceClass_RebootSystem( DeviceInterfaceSystemDeviceClass _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ew_reboot_system();
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.SetBrightness()' */
void DeviceInterfaceSystemDeviceClass_SetBrightness( DeviceInterfaceSystemDeviceClass _this, 
  XInt32 aBrightness )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  PERIPHERAL_pwm_set_display_dutycycle( aBrightness );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.OnGetBtSoftwareVersion()' */
XString DeviceInterfaceSystemDeviceClass_OnGetBtSoftwareVersion( DeviceInterfaceSystemDeviceClass _this )
{
  XString bt_sw_version = 0;

  if ( !EwCompString( 0, _this->BtSoftwareVersion ))
  {
    {
      char version[8];
      ew_get_bt_software_version( version );
      bt_sw_version = EwNewStringAnsi( version );
    }
    _this->BtSoftwareVersion = EwShareString( bt_sw_version );
  }

  return _this->BtSoftwareVersion;
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.StartBurnInTest()' */
void DeviceInterfaceSystemDeviceClass_StartBurnInTest( DeviceInterfaceSystemDeviceClass _this )
{
  FactoryTestContext TestContext;

  EwTrace( "%s", EwLoadString( &_Const0000 ));
  TestContext = EwNewObject( FactoryTestContext, 0 );
  TestContext->TestItem = EnumFactoryTestBurnInStart;
  CoreSystemEvent_Trigger( &_this->FactoryTestSystemEvent, ((XObject)TestContext ), 
  0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.StartBurnInTest()' */
void DeviceInterfaceSystemDeviceClass__StartBurnInTest( void* _this )
{
  DeviceInterfaceSystemDeviceClass_StartBurnInTest((DeviceInterfaceSystemDeviceClass)_this );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.UpdateBurnInTestTime()' */
void DeviceInterfaceSystemDeviceClass_UpdateBurnInTestTime( DeviceInterfaceSystemDeviceClass _this, 
  XUInt32 aTimeSec )
{
  FactoryTestContext TestContext = EwNewObject( FactoryTestContext, 0 );

  TestContext->TestItem = EnumFactoryTestBurnInTimeUpdate;
  TestContext->Data = (XInt32)aTimeSec;
  CoreSystemEvent_Trigger( &_this->FactoryTestSystemEvent, ((XObject)TestContext ), 
  0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.UpdateBurnInTestTime()' */
void DeviceInterfaceSystemDeviceClass__UpdateBurnInTestTime( void* _this, XUInt32 
  aTimeSec )
{
  DeviceInterfaceSystemDeviceClass_UpdateBurnInTestTime((DeviceInterfaceSystemDeviceClass)_this
  , aTimeSec );
}

/* 'C' function for method : 'DeviceInterface::SystemDeviceClass.ShowBurnInTestResult()' */
void DeviceInterfaceSystemDeviceClass_ShowBurnInTestResult( DeviceInterfaceSystemDeviceClass _this, 
  XBool aResult )
{
  FactoryTestContext TestContext;

  EwTrace( "%s%b", EwLoadString( &_Const0001 ), aResult );
  TestContext = EwNewObject( FactoryTestContext, 0 );
  TestContext->TestItem = EnumFactoryTestBurnInResult;

  if ( aResult )
  {
    TestContext->Data = 1;
  }
  else
  {
    TestContext->Data = 0;
  }

  CoreSystemEvent_Trigger( &_this->FactoryTestSystemEvent, ((XObject)TestContext ), 
  0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::SystemDeviceClass.ShowBurnInTestResult()' */
void DeviceInterfaceSystemDeviceClass__ShowBurnInTestResult( void* _this, XBool 
  aResult )
{
  DeviceInterfaceSystemDeviceClass_ShowBurnInTestResult((DeviceInterfaceSystemDeviceClass)_this
  , aResult );
}

/* Default onget method for the property 'FactoryResetComplete' */
XBool DeviceInterfaceSystemDeviceClass_OnGetFactoryResetComplete( DeviceInterfaceSystemDeviceClass _this )
{
  return _this->FactoryResetComplete;
}

/* Default onset method for the property 'FactoryResetComplete' */
void DeviceInterfaceSystemDeviceClass_OnSetFactoryResetComplete( DeviceInterfaceSystemDeviceClass _this, 
  XBool value )
{
  _this->FactoryResetComplete = value;
}

/* Variants derived from the class : 'DeviceInterface::SystemDeviceClass' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceSystemDeviceClass )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceSystemDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::SystemDeviceClass' */
EW_DEFINE_CLASS( DeviceInterfaceSystemDeviceClass, TemplatesDeviceClass, FactoryTestSystemEvent, 
                 FactoryTestSystemEvent, FactoryTestSystemEvent, FactoryTestSystemEvent, 
                 SoftwareVersion, BrightnessLevel, "DeviceInterface::SystemDeviceClass" )
EW_END_OF_CLASS( DeviceInterfaceSystemDeviceClass )

/* User defined auto object: 'DeviceInterface::SystemDevice' */
EW_DEFINE_AUTOOBJECT( DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )

/* Initializer for the auto object 'DeviceInterface::SystemDevice' */
void DeviceInterfaceSystemDevice__Init( DeviceInterfaceSystemDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'DeviceInterface::SystemDevice' */
EW_DEFINE_AUTOOBJECT_VARIANTS( DeviceInterfaceSystemDevice )
EW_END_OF_AUTOOBJECT_VARIANTS( DeviceInterfaceSystemDevice )

/* Initializer for the class 'DeviceInterface::NavigationDeviceClass' */
void DeviceInterfaceNavigationDeviceClass__Init( DeviceInterfaceNavigationDeviceClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  TemplatesDeviceClass__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DeviceInterfaceNavigationDeviceClass );

  /* ... then construct all embedded objects */
  CoreSystemEvent__Init( &_this->MapUpdateEvent, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DeviceInterfaceNavigationDeviceClass );
}

/* Re-Initializer for the class 'DeviceInterface::NavigationDeviceClass' */
void DeviceInterfaceNavigationDeviceClass__ReInit( DeviceInterfaceNavigationDeviceClass _this )
{
  /* At first re-initialize the super class ... */
  TemplatesDeviceClass__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEvent__ReInit( &_this->MapUpdateEvent );
}

/* Finalizer method for the class 'DeviceInterface::NavigationDeviceClass' */
void DeviceInterfaceNavigationDeviceClass__Done( DeviceInterfaceNavigationDeviceClass _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( TemplatesDeviceClass );

  /* Finalize all embedded objects */
  CoreSystemEvent__Done( &_this->MapUpdateEvent );

  /* Don't forget to deinitialize the super class ... */
  TemplatesDeviceClass__Done( &_this->_Super );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceNavigationDeviceClass_NotifyMapUpdate( DeviceInterfaceNavigationDeviceClass _this )
{
  CoreSystemEvent_Trigger( &_this->MapUpdateEvent, 0, 1 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::NavigationDeviceClass.NotifyMapUpdate()' */
void DeviceInterfaceNavigationDeviceClass__NotifyMapUpdate( void* _this )
{
  DeviceInterfaceNavigationDeviceClass_NotifyMapUpdate((DeviceInterfaceNavigationDeviceClass)_this );
}

/* Variants derived from the class : 'DeviceInterface::NavigationDeviceClass' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceNavigationDeviceClass )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceNavigationDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::NavigationDeviceClass' */
EW_DEFINE_CLASS( DeviceInterfaceNavigationDeviceClass, TemplatesDeviceClass, MapUpdateEvent, 
                 MapUpdateEvent, MapUpdateEvent, MapUpdateEvent, _None, _None, "DeviceInterface::NavigationDeviceClass" )
EW_END_OF_CLASS( DeviceInterfaceNavigationDeviceClass )

/* User defined auto object: 'DeviceInterface::NavigationDevice' */
EW_DEFINE_AUTOOBJECT( DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass )

/* Initializer for the auto object 'DeviceInterface::NavigationDevice' */
void DeviceInterfaceNavigationDevice__Init( DeviceInterfaceNavigationDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'DeviceInterface::NavigationDevice' */
EW_DEFINE_AUTOOBJECT_VARIANTS( DeviceInterfaceNavigationDevice )
EW_END_OF_AUTOOBJECT_VARIANTS( DeviceInterfaceNavigationDevice )

/* Initializer for the class 'DeviceInterface::MediaManagerDeviceClass' */
void DeviceInterfaceMediaManagerDeviceClass__Init( DeviceInterfaceMediaManagerDeviceClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  TemplatesDeviceClass__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DeviceInterfaceMediaManagerDeviceClass );

  /* ... then construct all embedded objects */
  CoreSystemEvent__Init( &_this->NotifyPlayBackTimeChangedSystemEvent, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DeviceInterfaceMediaManagerDeviceClass );
}

/* Re-Initializer for the class 'DeviceInterface::MediaManagerDeviceClass' */
void DeviceInterfaceMediaManagerDeviceClass__ReInit( DeviceInterfaceMediaManagerDeviceClass _this )
{
  /* At first re-initialize the super class ... */
  TemplatesDeviceClass__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEvent__ReInit( &_this->NotifyPlayBackTimeChangedSystemEvent );
}

/* Finalizer method for the class 'DeviceInterface::MediaManagerDeviceClass' */
void DeviceInterfaceMediaManagerDeviceClass__Done( DeviceInterfaceMediaManagerDeviceClass _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( TemplatesDeviceClass );

  /* Finalize all embedded objects */
  CoreSystemEvent__Done( &_this->NotifyPlayBackTimeChangedSystemEvent );

  /* Don't forget to deinitialize the super class ... */
  TemplatesDeviceClass__Done( &_this->_Super );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.OnSetTitle()' */
void DeviceInterfaceMediaManagerDeviceClass_OnSetTitle( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString value )
{
  if ( !EwCompString( _this->Title, value ) && !_this->IsInit )
    return;

  _this->Title = EwShareString( value );
  EwNotifyRefObservers( EwNewRef( _this, DeviceInterfaceMediaManagerDeviceClass_OnGetTitle, 
    DeviceInterfaceMediaManagerDeviceClass_OnSetTitle ), 0 );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.OnSetAlbum()' */
void DeviceInterfaceMediaManagerDeviceClass_OnSetAlbum( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString value )
{
  if ( !EwCompString( _this->Album, value ) && !_this->IsInit )
    return;

  _this->Album = EwShareString( value );
  EwNotifyRefObservers( EwNewRef( _this, DeviceInterfaceMediaManagerDeviceClass_OnGetAlbum, 
    DeviceInterfaceMediaManagerDeviceClass_OnSetAlbum ), 0 );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.OnSetArtist()' */
void DeviceInterfaceMediaManagerDeviceClass_OnSetArtist( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString value )
{
  if ( !EwCompString( _this->Artist, value ) && !_this->IsInit )
    return;

  _this->Artist = EwShareString( value );
  EwNotifyRefObservers( EwNewRef( _this, DeviceInterfaceMediaManagerDeviceClass_OnGetArtist, 
    DeviceInterfaceMediaManagerDeviceClass_OnSetArtist ), 0 );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.SendRemoteCommand()' */
void DeviceInterfaceMediaManagerDeviceClass_SendRemoteCommand( DeviceInterfaceMediaManagerDeviceClass _this, 
  XEnum cmd_type )
{
  XInt32 cmd_idx;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  switch ( cmd_type )
  {
    case EnumCommandTypePlay :
      cmd_idx = 0;
    break;

    case EnumCommandTypePause :
      cmd_idx = 1;
    break;

    case EnumCommandTypeNextTrack :
      cmd_idx = 2;
    break;

    case EnumCommandTypePrevTrack :
      cmd_idx = 3;
    break;

    default : 
      cmd_idx = 14;
  }

  if ( !!cmd_idx )
    ;

  {
    ams_remote_command cmd = AMS_REMOTE_COMMAND_CNT;
    switch( cmd_idx )
    {
      case 0:
        cmd = AMS_REMOTE_COMMAND_PLAY;
        break;
      case 1:
        cmd = AMS_REMOTE_COMMAND_PAUSE;
        break;
      case 2:
        cmd = AMS_REMOTE_COMMAND_NEXT_TRACK;
        break;
      case 3:
        cmd = AMS_REMOTE_COMMAND_PREVIOUS_TRACK;
        break;
      default:
        break;
    }
    ew_send_command( cmd );
  }
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.OnSetPlaybackState()' */
void DeviceInterfaceMediaManagerDeviceClass_OnSetPlaybackState( DeviceInterfaceMediaManagerDeviceClass _this, 
  XInt32 value )
{
  if (( _this->PlaybackState == value ) && !_this->IsInit )
    return;

  _this->PlaybackState = value;
  EwNotifyRefObservers( EwNewRef( _this, DeviceInterfaceMediaManagerDeviceClass_OnGetPlaybackState, 
    DeviceInterfaceMediaManagerDeviceClass_OnSetPlaybackState ), 0 );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.OnSetPlayerName()' */
void DeviceInterfaceMediaManagerDeviceClass_OnSetPlayerName( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString value )
{
  if ( !EwCompString( _this->PlayerName, value ) && !_this->IsInit )
    return;

  _this->PlayerName = EwShareString( value );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.NotifyTitleChanged()' */
void DeviceInterfaceMediaManagerDeviceClass_NotifyTitleChanged( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString aTitle )
{
  EwTrace( "%s", EwConcatString( EwLoadString( &_Const0002 ), aTitle ));
  DeviceInterfaceMediaManagerDeviceClass_OnSetTitle( _this, aTitle );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotifyTitleChanged()' */
void DeviceInterfaceMediaManagerDeviceClass__NotifyTitleChanged( void* _this, XString 
  aTitle )
{
  DeviceInterfaceMediaManagerDeviceClass_NotifyTitleChanged((DeviceInterfaceMediaManagerDeviceClass)_this
  , aTitle );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.NotifyArtistChanged()' */
void DeviceInterfaceMediaManagerDeviceClass_NotifyArtistChanged( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString aArtist )
{
  EwTrace( "%s", EwConcatString( EwLoadString( &_Const0003 ), aArtist ));
  DeviceInterfaceMediaManagerDeviceClass_OnSetArtist( _this, aArtist );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotifyArtistChanged()' */
void DeviceInterfaceMediaManagerDeviceClass__NotifyArtistChanged( void* _this, XString 
  aArtist )
{
  DeviceInterfaceMediaManagerDeviceClass_NotifyArtistChanged((DeviceInterfaceMediaManagerDeviceClass)_this
  , aArtist );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.NotifyAlbumChanged()' */
void DeviceInterfaceMediaManagerDeviceClass_NotifyAlbumChanged( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString aAlbum )
{
  EwTrace( "%s", EwConcatString( EwLoadString( &_Const0004 ), aAlbum ));
  DeviceInterfaceMediaManagerDeviceClass_OnSetAlbum( _this, aAlbum );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotifyAlbumChanged()' */
void DeviceInterfaceMediaManagerDeviceClass__NotifyAlbumChanged( void* _this, XString 
  aAlbum )
{
  DeviceInterfaceMediaManagerDeviceClass_NotifyAlbumChanged((DeviceInterfaceMediaManagerDeviceClass)_this
  , aAlbum );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.GetPlayerInfo()' */
void DeviceInterfaceMediaManagerDeviceClass_GetPlayerInfo( DeviceInterfaceMediaManagerDeviceClass _this )
{
  XString p_name = 0;
  XInt32 p_state = 0;

  {
    mm_media_player_obj mp_state;
    mp_state = ew_get_media_player_state();
    p_name = EwNewStringAnsi( mp_state.str.player_name );
    p_state = mp_state.playback_state;
  }
  DeviceInterfaceMediaManagerDeviceClass_OnSetPlayerName( _this, p_name );
  DeviceInterfaceMediaManagerDeviceClass_OnSetPlaybackState( _this, p_state );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.GetPlaybackInfo()' */
void DeviceInterfaceMediaManagerDeviceClass_GetPlaybackInfo( DeviceInterfaceMediaManagerDeviceClass _this )
{
  XInt32 ela_time = 0;
  XInt32 dur = 0;

  {
    mm_media_player_obj mp_state;
    mp_state = ew_get_media_player_state();
    ela_time = mp_state.current_elapsed_time_sec;
    dur = mp_state.duration_sec;
  }
  _this->ElapsedTimeSec = ela_time;
  _this->DurationTimeSec = dur;
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.GetTrackInfo()' */
void DeviceInterfaceMediaManagerDeviceClass_GetTrackInfo( DeviceInterfaceMediaManagerDeviceClass _this )
{
  XString media_artist = 0;
  XString media_album = 0;
  XString media_title = 0;

  {
    mm_media_player_obj mp_state;
    mp_state = ew_get_media_player_state();
    media_artist = EwNewStringUtf8( ( const unsigned char* )mp_state.str.track_artist, ( int )strlen( mp_state.str.track_artist ) );
    media_album = EwNewStringUtf8( ( const unsigned char* )mp_state.str.track_album, ( int )strlen( mp_state.str.track_album ) );
    media_title = EwNewStringUtf8( ( const unsigned char* )mp_state.str.track_title, ( int )strlen( mp_state.str.track_title ) );
  }
  DeviceInterfaceMediaManagerDeviceClass_OnSetArtist( _this, media_artist );
  DeviceInterfaceMediaManagerDeviceClass_OnSetAlbum( _this, media_album );
  DeviceInterfaceMediaManagerDeviceClass_OnSetTitle( _this, media_title );
}

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.NotifyPlayerStateChanged()' */
void DeviceInterfaceMediaManagerDeviceClass_NotifyPlayerStateChanged( DeviceInterfaceMediaManagerDeviceClass _this, 
  XInt32 aPlaybackState )
{
  EwTrace( "%s%i", EwLoadString( &_Const0005 ), aPlaybackState );
  DeviceInterfaceMediaManagerDeviceClass_OnSetPlaybackState( _this, aPlaybackState );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotifyPlayerStateChanged()' */
void DeviceInterfaceMediaManagerDeviceClass__NotifyPlayerStateChanged( void* _this, 
  XInt32 aPlaybackState )
{
  DeviceInterfaceMediaManagerDeviceClass_NotifyPlayerStateChanged((DeviceInterfaceMediaManagerDeviceClass)_this
  , aPlaybackState );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceMediaManagerDeviceClass_NotifyPlayBackTimeChanged( DeviceInterfaceMediaManagerDeviceClass _this, 
  XInt32 aElapsedTimeSec, XInt32 aDurationTimeSec, XInt32 aRemainTimeSec )
{
  EwTrace( "%s%i", EwLoadString( &_Const0006 ), aElapsedTimeSec );
  EwTrace( "%s%i", EwLoadString( &_Const0007 ), aDurationTimeSec );
  EwTrace( "%s%i", EwLoadString( &_Const0008 ), aDurationTimeSec );
  _this->ElapsedTimeSec = aElapsedTimeSec;
  _this->DurationTimeSec = aDurationTimeSec;
  _this->RemainTimeSec = aRemainTimeSec;
  CoreSystemEvent_Trigger( &_this->NotifyPlayBackTimeChangedSystemEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotifyPlayBackTimeChanged()' */
void DeviceInterfaceMediaManagerDeviceClass__NotifyPlayBackTimeChanged( void* _this, 
  XInt32 aElapsedTimeSec, XInt32 aDurationTimeSec, XInt32 aRemainTimeSec )
{
  DeviceInterfaceMediaManagerDeviceClass_NotifyPlayBackTimeChanged((DeviceInterfaceMediaManagerDeviceClass)_this
  , aElapsedTimeSec, aDurationTimeSec, aRemainTimeSec );
}

/* Default onget method for the property 'Title' */
XString DeviceInterfaceMediaManagerDeviceClass_OnGetTitle( DeviceInterfaceMediaManagerDeviceClass _this )
{
  return _this->Title;
}

/* Default onget method for the property 'Album' */
XString DeviceInterfaceMediaManagerDeviceClass_OnGetAlbum( DeviceInterfaceMediaManagerDeviceClass _this )
{
  return _this->Album;
}

/* Default onget method for the property 'Artist' */
XString DeviceInterfaceMediaManagerDeviceClass_OnGetArtist( DeviceInterfaceMediaManagerDeviceClass _this )
{
  return _this->Artist;
}

/* Default onget method for the property 'PlaybackState' */
XInt32 DeviceInterfaceMediaManagerDeviceClass_OnGetPlaybackState( DeviceInterfaceMediaManagerDeviceClass _this )
{
  return _this->PlaybackState;
}

/* Variants derived from the class : 'DeviceInterface::MediaManagerDeviceClass' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceMediaManagerDeviceClass )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceMediaManagerDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::MediaManagerDeviceClass' */
EW_DEFINE_CLASS( DeviceInterfaceMediaManagerDeviceClass, TemplatesDeviceClass, NotifyPlayBackTimeChangedSystemEvent, 
                 NotifyPlayBackTimeChangedSystemEvent, NotifyPlayBackTimeChangedSystemEvent, 
                 NotifyPlayBackTimeChangedSystemEvent, Title, DurationTimeSec, "DeviceInterface::MediaManagerDeviceClass" )
EW_END_OF_CLASS( DeviceInterfaceMediaManagerDeviceClass )

/* User defined auto object: 'DeviceInterface::MediaManagerDevice' */
EW_DEFINE_AUTOOBJECT( DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass )

/* Initializer for the auto object 'DeviceInterface::MediaManagerDevice' */
void DeviceInterfaceMediaManagerDevice__Init( DeviceInterfaceMediaManagerDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'DeviceInterface::MediaManagerDevice' */
EW_DEFINE_AUTOOBJECT_VARIANTS( DeviceInterfaceMediaManagerDevice )
EW_END_OF_AUTOOBJECT_VARIANTS( DeviceInterfaceMediaManagerDevice )

/* Initializer for the class 'DeviceInterface::BluetoothDeviceClass' */
void DeviceInterfaceBluetoothDeviceClass__Init( DeviceInterfaceBluetoothDeviceClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  TemplatesDeviceClass__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DeviceInterfaceBluetoothDeviceClass );

  /* ... then construct all embedded objects */
  CoreSystemEvent__Init( &_this->PasskeyGeneratedSystemEvent, &_this->_XObject, 0 );
  CoreSystemEvent__Init( &_this->ConnectionResultSystemEvent, &_this->_XObject, 0 );
  DeviceInterfaceBluetoothPairedDeviceInfo__Init( &_this->PairedDeviceObj, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DeviceInterfaceBluetoothDeviceClass );

  /* ... and initialize objects, variables, properties, etc. */
  _this->ConnectionResult = EnumBtResultFAIL;
}

/* Re-Initializer for the class 'DeviceInterface::BluetoothDeviceClass' */
void DeviceInterfaceBluetoothDeviceClass__ReInit( DeviceInterfaceBluetoothDeviceClass _this )
{
  /* At first re-initialize the super class ... */
  TemplatesDeviceClass__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEvent__ReInit( &_this->PasskeyGeneratedSystemEvent );
  CoreSystemEvent__ReInit( &_this->ConnectionResultSystemEvent );
  DeviceInterfaceBluetoothPairedDeviceInfo__ReInit( &_this->PairedDeviceObj );
}

/* Finalizer method for the class 'DeviceInterface::BluetoothDeviceClass' */
void DeviceInterfaceBluetoothDeviceClass__Done( DeviceInterfaceBluetoothDeviceClass _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( TemplatesDeviceClass );

  /* Finalize all embedded objects */
  CoreSystemEvent__Done( &_this->PasskeyGeneratedSystemEvent );
  CoreSystemEvent__Done( &_this->ConnectionResultSystemEvent );
  DeviceInterfaceBluetoothPairedDeviceInfo__Done( &_this->PairedDeviceObj );

  /* Don't forget to deinitialize the super class ... */
  TemplatesDeviceClass__Done( &_this->_Super );
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetPairedDeviceAtItem()' */
void DeviceInterfaceBluetoothDeviceClass_GetPairedDeviceAtItem( DeviceInterfaceBluetoothDeviceClass _this, 
  XInt32 aItemNo )
{
  XString DevName = 0;
  XBool IsConnected = 0;

  {
    uint8_t* device_name;
    bool     is_connected;
    ew_bt_get_paired_device_at_index( aItemNo, &device_name, &is_connected );
    DevName = EwNewStringAnsi( ( char* )device_name );
    IsConnected = is_connected;
  }
  _this->PairedDeviceObj.DeviceName = EwShareString( DevName );
  _this->PairedDeviceObj.IsConnected = IsConnected;
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceBluetoothDeviceClass_NotifyPasskeyGenerated( DeviceInterfaceBluetoothDeviceClass _this, 
  XString aPasskey )
{
  EwTrace( "%s%s", EwLoadString( &_Const0009 ), aPasskey );
  _this->Passkey = EwShareString( aPasskey );
  CoreSystemEvent_Trigger( &_this->PasskeyGeneratedSystemEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyPasskeyGenerated()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyPasskeyGenerated( void* _this, XString 
  aPasskey )
{
  DeviceInterfaceBluetoothDeviceClass_NotifyPasskeyGenerated((DeviceInterfaceBluetoothDeviceClass)_this
  , aPasskey );
}

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceBluetoothDeviceClass_NotifyConnectionResult( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum aResult )
{
  _this->ConnectionResult = aResult;
  CoreSystemEvent_Trigger( &_this->ConnectionResultSystemEvent, 0, 0 );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyConnectionResult()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyConnectionResult( void* _this, XEnum 
  aResult )
{
  DeviceInterfaceBluetoothDeviceClass_NotifyConnectionResult((DeviceInterfaceBluetoothDeviceClass)_this
  , aResult );
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetDiscoverable()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetDiscoverable( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool value )
{
  if ( _this->Discoverable != value )
  {
    _this->Discoverable = value;
    ew_bt_set_discoverable( ( bool )value );
  }
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetBluetoothEnable()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetBluetoothEnable( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool value )
{
  EwTrace( "%s%b", EwLoadString( &_Const000A ), value );

  if ( _this->BluetoothEnable != value )
  {
    _this->BluetoothEnable = value;
    ew_bt_set_enable( ( bool )value );
  }
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetAutoConnect()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetAutoConnect( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool value )
{
  _this->AutoConnect = value;
  ew_bt_set_autoconnect( ( bool )value );
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetAutoConnect()' */
XBool DeviceInterfaceBluetoothDeviceClass_OnGetAutoConnect( DeviceInterfaceBluetoothDeviceClass _this )
{
  XBool IsAutoConnect;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsAutoConnect = 0;
  IsAutoConnect = ew_bt_get_autoconnect();
  return IsAutoConnect;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetPairedDeviceNum()' */
XInt32 DeviceInterfaceBluetoothDeviceClass_OnGetPairedDeviceNum( DeviceInterfaceBluetoothDeviceClass _this )
{
  XInt32 PairedDevNum;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  PairedDevNum = 0;
  PairedDevNum = ew_bt_get_paired_device_num();
  return PairedDevNum;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.UnpairDevice()' */
void DeviceInterfaceBluetoothDeviceClass_UnpairDevice( DeviceInterfaceBluetoothDeviceClass _this, 
  XInt32 aPairedDeviceIndex )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ew_bt_unpair_paired_device( aPairedDeviceIndex );
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.GetBluetoothEnable()' */
void DeviceInterfaceBluetoothDeviceClass_GetBluetoothEnable( DeviceInterfaceBluetoothDeviceClass _this )
{
  XBool enable = 0;

  enable = ew_bt_get_enable();
  DeviceInterfaceBluetoothDeviceClass_OnSetBluetoothEnable( _this, enable );
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetLocalDeviceName()' */
XString DeviceInterfaceBluetoothDeviceClass_OnGetLocalDeviceName( DeviceInterfaceBluetoothDeviceClass _this )
{
  XString DevName;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  DevName = 0;
  {
    uint8_t* device_name;
    ew_bt_get_local_device_name( &device_name );
    DevName = EwNewStringAnsi( ( char* )device_name );
  }
  return DevName;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.ConnectPairedDevice()' */
void DeviceInterfaceBluetoothDeviceClass_ConnectPairedDevice( DeviceInterfaceBluetoothDeviceClass _this, 
  XInt32 aPairedDeviceIndex )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ew_bt_connect_paired_device( aPairedDeviceIndex );
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.IsBlePairedDevice()' */
XBool DeviceInterfaceBluetoothDeviceClass_IsBlePairedDevice( DeviceInterfaceBluetoothDeviceClass _this, 
  XInt32 aPairedDeviceIndex )
{
  XBool IsBlePairedDevice;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsBlePairedDevice = 0;
  IsBlePairedDevice = ew_bt_is_ble_paired_device( aPairedDeviceIndex );
  return IsBlePairedDevice;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.DisconnectPairedDevice()' */
void DeviceInterfaceBluetoothDeviceClass_DisconnectPairedDevice( DeviceInterfaceBluetoothDeviceClass _this, 
  XInt32 aPairedDeviceIndex )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ew_bt_disconnect_paired_device( aPairedDeviceIndex );
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnGetIsMaxPairedDevice()' */
XBool DeviceInterfaceBluetoothDeviceClass_OnGetIsMaxPairedDevice( DeviceInterfaceBluetoothDeviceClass _this )
{
  XBool is_max_paired_device;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  is_max_paired_device = 0;
  is_max_paired_device = ew_bt_is_max_paired_device_num();
  return is_max_paired_device;
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetBtFwStatus()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetBtFwStatus( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum value )
{
  if ( _this->BtFwStatus != value )
  {
    _this->BtFwStatus = value;
    EwNotifyRefObservers( EwNewRef( _this, DeviceInterfaceBluetoothDeviceClass_OnGetBtFwStatus, 
      DeviceInterfaceBluetoothDeviceClass_OnSetBtFwStatus ), 0 );
  }
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.NotifyBtFwStatus()' */
void DeviceInterfaceBluetoothDeviceClass_NotifyBtFwStatus( DeviceInterfaceBluetoothDeviceClass _this, 
  XEnum status, XString version )
{
  EwTrace( "%s%e", EwLoadString( &_Const000B ), status );
  EwTrace( "%s%s", EwLoadString( &_Const000C ), version );
  DeviceInterfaceBluetoothDeviceClass_OnSetBtFwStatus( _this, status );
}

/* Wrapper function for the non virtual method : 'DeviceInterface::BluetoothDeviceClass.NotifyBtFwStatus()' */
void DeviceInterfaceBluetoothDeviceClass__NotifyBtFwStatus( void* _this, XEnum status, 
  XString version )
{
  DeviceInterfaceBluetoothDeviceClass_NotifyBtFwStatus((DeviceInterfaceBluetoothDeviceClass)_this
  , status, version );
}

/* 'C' function for method : 'DeviceInterface::BluetoothDeviceClass.OnSetRefreshPairedDeviceList()' */
void DeviceInterfaceBluetoothDeviceClass_OnSetRefreshPairedDeviceList( DeviceInterfaceBluetoothDeviceClass _this, 
  XBool value )
{
  _this->RefreshPairedDeviceList = value;
  EwNotifyRefObservers( EwNewRef( _this, DeviceInterfaceBluetoothDeviceClass_OnGetRefreshPairedDeviceList, 
    DeviceInterfaceBluetoothDeviceClass_OnSetRefreshPairedDeviceList ), 0 );
}

/* Default onget method for the property 'BtFwStatus' */
XEnum DeviceInterfaceBluetoothDeviceClass_OnGetBtFwStatus( DeviceInterfaceBluetoothDeviceClass _this )
{
  return _this->BtFwStatus;
}

/* Default onget method for the property 'RefreshPairedDeviceList' */
XBool DeviceInterfaceBluetoothDeviceClass_OnGetRefreshPairedDeviceList( DeviceInterfaceBluetoothDeviceClass _this )
{
  return _this->RefreshPairedDeviceList;
}

/* Variants derived from the class : 'DeviceInterface::BluetoothDeviceClass' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceBluetoothDeviceClass )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceBluetoothDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::BluetoothDeviceClass' */
EW_DEFINE_CLASS( DeviceInterfaceBluetoothDeviceClass, TemplatesDeviceClass, PasskeyGeneratedSystemEvent, 
                 PasskeyGeneratedSystemEvent, PasskeyGeneratedSystemEvent, PasskeyGeneratedSystemEvent, 
                 Passkey, BtFwStatus, "DeviceInterface::BluetoothDeviceClass" )
EW_END_OF_CLASS( DeviceInterfaceBluetoothDeviceClass )

/* User defined auto object: 'DeviceInterface::BluetoothDevice' */
EW_DEFINE_AUTOOBJECT( DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )

/* Initializer for the auto object 'DeviceInterface::BluetoothDevice' */
void DeviceInterfaceBluetoothDevice__Init( DeviceInterfaceBluetoothDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'DeviceInterface::BluetoothDevice' */
EW_DEFINE_AUTOOBJECT_VARIANTS( DeviceInterfaceBluetoothDevice )
EW_END_OF_AUTOOBJECT_VARIANTS( DeviceInterfaceBluetoothDevice )

/* Initializer for the class 'DeviceInterface::BluetoothPairedDeviceInfo' */
void DeviceInterfaceBluetoothPairedDeviceInfo__Init( DeviceInterfaceBluetoothPairedDeviceInfo _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DeviceInterfaceBluetoothPairedDeviceInfo );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DeviceInterfaceBluetoothPairedDeviceInfo );
}

/* Re-Initializer for the class 'DeviceInterface::BluetoothPairedDeviceInfo' */
void DeviceInterfaceBluetoothPairedDeviceInfo__ReInit( DeviceInterfaceBluetoothPairedDeviceInfo _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'DeviceInterface::BluetoothPairedDeviceInfo' */
void DeviceInterfaceBluetoothPairedDeviceInfo__Done( DeviceInterfaceBluetoothPairedDeviceInfo _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_Super );
}

/* Variants derived from the class : 'DeviceInterface::BluetoothPairedDeviceInfo' */
EW_DEFINE_CLASS_VARIANTS( DeviceInterfaceBluetoothPairedDeviceInfo )
EW_END_OF_CLASS_VARIANTS( DeviceInterfaceBluetoothPairedDeviceInfo )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::BluetoothPairedDeviceInfo' */
EW_DEFINE_CLASS( DeviceInterfaceBluetoothPairedDeviceInfo, XObject, DeviceName, 
                 DeviceName, DeviceName, DeviceName, DeviceName, IsConnected, "DeviceInterface::BluetoothPairedDeviceInfo" )
EW_END_OF_CLASS( DeviceInterfaceBluetoothPairedDeviceInfo )

/* Embedded Wizard */
