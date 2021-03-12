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

#ifndef _DeviceInterfaceMediaManagerDeviceClass_H
#define _DeviceInterfaceMediaManagerDeviceClass_H

#ifdef __cplusplus
  extern "C"
  {
#endif

#include "ewrte.h"
#if EW_RTE_VERSION != 0x000A0000
  #error Wrong version of Embedded Wizard Runtime Environment.
#endif

#include "ewgfx.h"
#if EW_GFX_VERSION != 0x000A0000
  #error Wrong version of Embedded Wizard Graphics Engine.
#endif

#include "_CoreSystemEvent.h"
#include "_TemplatesDeviceClass.h"

/* Forward declaration of the class DeviceInterface::MediaManagerDeviceClass */
#ifndef _DeviceInterfaceMediaManagerDeviceClass_
  EW_DECLARE_CLASS( DeviceInterfaceMediaManagerDeviceClass )
#define _DeviceInterfaceMediaManagerDeviceClass_
#endif


/* Deklaration of class : 'DeviceInterface::MediaManagerDeviceClass' */
EW_DEFINE_FIELDS( DeviceInterfaceMediaManagerDeviceClass, TemplatesDeviceClass )
  EW_OBJECT  ( NotifyPlayBackTimeChangedSystemEvent, CoreSystemEvent )
  EW_OBJECT  ( NotifyMotoConMusicUpdatedSystemEvent, CoreSystemEvent )
  EW_OBJECT  ( NotifyAmsBleConnectedStatusSystemEvent, CoreSystemEvent )
  EW_PROPERTY( Title,           XString )
  EW_PROPERTY( Album,           XString )
  EW_PROPERTY( Artist,          XString )
  EW_PROPERTY( DurationTimeSec, XInt32 )
  EW_PROPERTY( ElapsedTimeSec,  XInt32 )
  EW_VARIABLE( IsArtistReceived, XBool )
  EW_VARIABLE( IsAlbumReceived, XBool )
  EW_VARIABLE( IsTitleReceived, XBool )
  EW_VARIABLE( IsInit,          XBool )
EW_END_OF_FIELDS( DeviceInterfaceMediaManagerDeviceClass )

/* Virtual Method Table (VMT) for the class : 'DeviceInterface::MediaManagerDeviceClass' */
EW_DEFINE_METHODS( DeviceInterfaceMediaManagerDeviceClass, TemplatesDeviceClass )
EW_END_OF_METHODS( DeviceInterfaceMediaManagerDeviceClass )

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.OnSetTitle()' */
void DeviceInterfaceMediaManagerDeviceClass_OnSetTitle( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString value );

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.OnSetAlbum()' */
void DeviceInterfaceMediaManagerDeviceClass_OnSetAlbum( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString value );

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.OnSetArtist()' */
void DeviceInterfaceMediaManagerDeviceClass_OnSetArtist( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString value );

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.SendRemoteCommand()' */
void DeviceInterfaceMediaManagerDeviceClass_SendRemoteCommand( DeviceInterfaceMediaManagerDeviceClass _this, 
  XEnum cmd_type );

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.NotifyTitleChanged()' */
void DeviceInterfaceMediaManagerDeviceClass_NotifyTitleChanged( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString aTitle );

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotifyTitleChanged()' */
void DeviceInterfaceMediaManagerDeviceClass__NotifyTitleChanged( void* _this, XString 
  aTitle );

/* The following define announces the presence of the method DeviceInterface::MediaManagerDeviceClass.NotifyTitleChanged(). */
#define _DeviceInterfaceMediaManagerDeviceClass__NotifyTitleChanged_

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.NotifyArtistChanged()' */
void DeviceInterfaceMediaManagerDeviceClass_NotifyArtistChanged( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString aArtist );

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotifyArtistChanged()' */
void DeviceInterfaceMediaManagerDeviceClass__NotifyArtistChanged( void* _this, XString 
  aArtist );

/* The following define announces the presence of the method DeviceInterface::MediaManagerDeviceClass.NotifyArtistChanged(). */
#define _DeviceInterfaceMediaManagerDeviceClass__NotifyArtistChanged_

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.NotifyAlbumChanged()' */
void DeviceInterfaceMediaManagerDeviceClass_NotifyAlbumChanged( DeviceInterfaceMediaManagerDeviceClass _this, 
  XString aAlbum );

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotifyAlbumChanged()' */
void DeviceInterfaceMediaManagerDeviceClass__NotifyAlbumChanged( void* _this, XString 
  aAlbum );

/* The following define announces the presence of the method DeviceInterface::MediaManagerDeviceClass.NotifyAlbumChanged(). */
#define _DeviceInterfaceMediaManagerDeviceClass__NotifyAlbumChanged_

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.GetPlayBackStateInfo()' */
XInt32 DeviceInterfaceMediaManagerDeviceClass_GetPlayBackStateInfo( DeviceInterfaceMediaManagerDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.GetPlaybackInfo()' */
void DeviceInterfaceMediaManagerDeviceClass_GetPlaybackInfo( DeviceInterfaceMediaManagerDeviceClass _this );

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.GetTrackInfo()' */
void DeviceInterfaceMediaManagerDeviceClass_GetTrackInfo( DeviceInterfaceMediaManagerDeviceClass _this );

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceMediaManagerDeviceClass_NotifyPlayBackTimeChanged( DeviceInterfaceMediaManagerDeviceClass _this, 
  XInt32 aElapsedTimeSec, XInt32 aDurationTimeSec );

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotifyPlayBackTimeChanged()' */
void DeviceInterfaceMediaManagerDeviceClass__NotifyPlayBackTimeChanged( void* _this, 
  XInt32 aElapsedTimeSec, XInt32 aDurationTimeSec );

/* The following define announces the presence of the method DeviceInterface::MediaManagerDeviceClass.NotifyPlayBackTimeChanged(). */
#define _DeviceInterfaceMediaManagerDeviceClass__NotifyPlayBackTimeChanged_

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceMediaManagerDeviceClass_NotfiyMotoConMusicInfoUpdated( DeviceInterfaceMediaManagerDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotfiyMotoConMusicInfoUpdated()' */
void DeviceInterfaceMediaManagerDeviceClass__NotfiyMotoConMusicInfoUpdated( void* _this );

/* The following define announces the presence of the method DeviceInterface::MediaManagerDeviceClass.NotfiyMotoConMusicInfoUpdated(). */
#define _DeviceInterfaceMediaManagerDeviceClass__NotfiyMotoConMusicInfoUpdated_

/* 'C' function for method : 'DeviceInterface::MediaManagerDeviceClass.IsAmsConnected()' */
XBool DeviceInterfaceMediaManagerDeviceClass_IsAmsConnected( DeviceInterfaceMediaManagerDeviceClass _this );

/* This method is intended to be called by the device to notify the GUI application 
   about a particular system event. */
void DeviceInterfaceMediaManagerDeviceClass_NotifyAmsBleConnectedStatusChanged( DeviceInterfaceMediaManagerDeviceClass _this );

/* Wrapper function for the non virtual method : 'DeviceInterface::MediaManagerDeviceClass.NotifyAmsBleConnectedStatusChanged()' */
void DeviceInterfaceMediaManagerDeviceClass__NotifyAmsBleConnectedStatusChanged( void* _this );

/* The following define announces the presence of the method DeviceInterface::MediaManagerDeviceClass.NotifyAmsBleConnectedStatusChanged(). */
#define _DeviceInterfaceMediaManagerDeviceClass__NotifyAmsBleConnectedStatusChanged_

/* Default onget method for the property 'Title' */
XString DeviceInterfaceMediaManagerDeviceClass_OnGetTitle( DeviceInterfaceMediaManagerDeviceClass _this );

/* Default onget method for the property 'Album' */
XString DeviceInterfaceMediaManagerDeviceClass_OnGetAlbum( DeviceInterfaceMediaManagerDeviceClass _this );

/* Default onget method for the property 'Artist' */
XString DeviceInterfaceMediaManagerDeviceClass_OnGetArtist( DeviceInterfaceMediaManagerDeviceClass _this );

#ifdef __cplusplus
  }
#endif

#endif /* _DeviceInterfaceMediaManagerDeviceClass_H */

/* Embedded Wizard */
