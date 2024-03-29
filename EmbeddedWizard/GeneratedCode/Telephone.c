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
#include "_ComponentsBaseText.h"
#include "_CoreGroup.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DeviceInterfaceNotificationDeviceClass.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_TelephoneImageButton.h"
#include "_TelephoneTEL01_IncomingCall.h"
#include "_TelephoneTEL02_ActiveCall.h"
#include "_ViewsImage.h"
#include "_ViewsText.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "Fonts.h"
#include "Resource.h"
#include "Resources.h"
#include "Strings.h"
#include "Telephone.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault0[] =
{
  0x0000004C, /* ratio 84.21 % */
  0xB8001500, 0x800A8452, 0x00980022, 0x06200180, 0x40001600, 0x60989800, 0x0983C160,
  0x11900217, 0x02002271, 0x6C787516, 0x800C7160, 0xA4D80030, 0xC00768EC, 0x2522959B,
  0x1018F47A, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 94, 75 }};
static const XRect _Const0001 = {{ 0, 39 }, { 94, 114 }};
static const XRect _Const0002 = {{ 0, 189 }, { 94, 264 }};
static const XRect _Const0003 = {{ 241, 44 }, { 311, 114 }};
static const XRect _Const0004 = {{ 100, 114 }, { 451, 190 }};
static const XRect _Const0005 = {{ 0, 36 }, { 480, 38 }};
static const XRect _Const0006 = {{ 100, 114 }, { 451, 152 }};
static const XStringRes _Const0007 = { _StringsDefault0, 0x0002 };
static const XRect _Const0008 = {{ 101, 112 }, { 452, 188 }};
static const XRect _Const0009 = {{ 100, 203 }, { 451, 237 }};
static const XRect _Const000A = {{ 0, 114 }, { 94, 189 }};
static const XStringRes _Const000B = { _StringsDefault0, 0x000C };
static const XStringRes _Const000C = { _StringsDefault0, 0x0015 };
static const XStringRes _Const000D = { _StringsDefault0, 0x0019 };

/* Initializer for the class 'Telephone::ImageButton' */
void TelephoneImageButton__Init( TelephoneImageButton _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( TelephoneImageButton );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->BackgroundImage, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ForegroundImage, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->HighlightTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( TelephoneImageButton );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->BackgroundImage, _Const0000 );
  CoreRectView__OnSetBounds( &_this->ForegroundImage, _Const0000 );
  CoreTimer_OnSetPeriod( &_this->HighlightTimer, 0 );
  CoreTimer_OnSetBegin( &_this->HighlightTimer, 100 );
  CoreTimer_OnSetEnabled( &_this->HighlightTimer, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BackgroundImage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ForegroundImage ), 0 );
  ViewsImage_OnSetBitmap( &_this->BackgroundImage, EwLoadResource( &ResourcePhoneButtonBG, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ForegroundImage, EwLoadResource( &ResourcesDefaultBitmap, 
  ResourcesBitmap ));
  _this->HighlightTimer.OnTrigger = EwNewSlot( _this, TelephoneImageButton_OnHighlightEndSlot );
}

/* Re-Initializer for the class 'Telephone::ImageButton' */
void TelephoneImageButton__ReInit( TelephoneImageButton _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->BackgroundImage );
  ViewsImage__ReInit( &_this->ForegroundImage );
  CoreTimer__ReInit( &_this->HighlightTimer );
}

/* Finalizer method for the class 'Telephone::ImageButton' */
void TelephoneImageButton__Done( TelephoneImageButton _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->BackgroundImage );
  ViewsImage__Done( &_this->ForegroundImage );
  CoreTimer__Done( &_this->HighlightTimer );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Telephone::ImageButton.OnSetEnabled()' */
void TelephoneImageButton_OnSetEnabled( TelephoneImageButton _this, XBool value )
{
  CoreGroup_OnSetEnabled((CoreGroup)_this, value );

  if ( value )
    TelephoneImageButton_OnSetForegroundFrameNumber( _this, 0 );
  else
    TelephoneImageButton_OnSetForegroundFrameNumber( _this, 1 );
}

/* 'C' function for method : 'Telephone::ImageButton.OnSetForegroundBmp()' */
void TelephoneImageButton_OnSetForegroundBmp( TelephoneImageButton _this, ResourcesBitmap 
  value )
{
  if ( _this->ForegroundBmp != value )
  {
    _this->ForegroundBmp = value;
    ViewsImage_OnSetBitmap( &_this->ForegroundImage, value );
  }
}

/* 'C' function for method : 'Telephone::ImageButton.OnSetForegroundFrameNumber()' */
void TelephoneImageButton_OnSetForegroundFrameNumber( TelephoneImageButton _this, 
  XInt32 value )
{
  if ( _this->ForegroundFrameNumber != value )
  {
    _this->ForegroundFrameNumber = value;
    ViewsImage_OnSetFrameNumber( &_this->ForegroundImage, value );
  }
}

/* 'C' function for method : 'Telephone::ImageButton.DisplayHighlightAnimation()' */
void TelephoneImageButton_DisplayHighlightAnimation( TelephoneImageButton _this )
{
  if ( CoreGroup__OnGetEnabled( _this ))
  {
    ViewsImage_OnSetFrameNumber( &_this->BackgroundImage, 1 );
    CoreTimer_OnSetEnabled( &_this->HighlightTimer, 1 );
  }
}

/* 'C' function for method : 'Telephone::ImageButton.OnHighlightEndSlot()' */
void TelephoneImageButton_OnHighlightEndSlot( TelephoneImageButton _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ViewsImage_OnSetFrameNumber( &_this->BackgroundImage, 0 );
}

/* Variants derived from the class : 'Telephone::ImageButton' */
EW_DEFINE_CLASS_VARIANTS( TelephoneImageButton )
EW_END_OF_CLASS_VARIANTS( TelephoneImageButton )

/* Virtual Method Table (VMT) for the class : 'Telephone::ImageButton' */
EW_DEFINE_CLASS( TelephoneImageButton, CoreGroup, ForegroundBmp, BackgroundImage, 
                 BackgroundImage, BackgroundImage, ForegroundFrameNumber, ForegroundFrameNumber, 
                 "Telephone::ImageButton" )
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
  TelephoneImageButton_OnSetEnabled,
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
EW_END_OF_CLASS( TelephoneImageButton )

/* Initializer for the class 'Telephone::TEL01_IncomingCall' */
void TelephoneTEL01_IncomingCall__Init( TelephoneTEL01_IncomingCall _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( TelephoneTEL01_IncomingCall );

  /* ... then construct all embedded objects */
  TelephoneImageButton__Init( &_this->AnswerButton, &_this->_.XObject, 0 );
  TelephoneImageButton__Init( &_this->DeclineButton, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ForegroundImage, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->CallerText, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->PhoneCallStateChangedEventHandler, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->DismissTimer, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->KeyEnableTimer, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Divider, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( TelephoneTEL01_IncomingCall );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->AnswerButton, _Const0001 );
  CoreRectView__OnSetBounds( &_this->DeclineButton, _Const0002 );
  TelephoneImageButton_OnSetForegroundFrameNumber( &_this->DeclineButton, 1 );
  CoreRectView__OnSetBounds( &_this->ForegroundImage, _Const0003 );
  CoreRectView__OnSetBounds( &_this->CallerText, _Const0004 );
  ViewsText_OnSetEllipsis((ViewsText)&_this->CallerText, 1 );
  ViewsText_OnSetWrapText((ViewsText)&_this->CallerText, 1 );
  ViewsText_OnSetAlignment((ViewsText)&_this->CallerText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString((ViewsText)&_this->CallerText, 0 );
  ViewsText_OnSetVisible((ViewsText)&_this->CallerText, 0 );
  CoreTimer_OnSetPeriod( &_this->DismissTimer, 0 );
  CoreTimer_OnSetBegin( &_this->DismissTimer, 1000 );
  CoreTimer_OnSetPeriod( &_this->KeyEnableTimer, 0 );
  CoreTimer_OnSetBegin( &_this->KeyEnableTimer, 1000 );
  CoreTimer_OnSetEnabled( &_this->KeyEnableTimer, 1 );
  CoreRectView__OnSetBounds( &_this->Divider, _Const0005 );
  ViewsImage_OnSetAlignment( &_this->Divider, ViewsImageAlignmentAlignVertBottom 
  | ViewsImageAlignmentScaleToFit );
  CoreGroup__Add( _this, ((CoreView)&_this->AnswerButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DeclineButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ForegroundImage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CallerText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider ), 0 );
  ViewsImage_OnSetBitmap( &_this->Super1.MainBottomBG, EwLoadResource( &ResourcePhoneBG, 
  ResourcesBitmap ));
  TelephoneImageButton_OnSetForegroundBmp( &_this->AnswerButton, EwLoadResource( 
  &ResourcePhoneAnswerDecline, ResourcesBitmap ));
  TelephoneImageButton_OnSetForegroundBmp( &_this->DeclineButton, EwLoadResource( 
  &ResourcePhoneAnswerDecline, ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ForegroundImage, EwLoadResource( &ResourceIncomingCallIcon, 
  ResourcesBitmap ));
  ViewsText_OnSetFont((ViewsText)&_this->CallerText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  _this->PhoneCallStateChangedEventHandler.OnEvent = EwNewSlot( _this, TelephoneTEL01_IncomingCall_OnPhoneCallStateChangedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->PhoneCallStateChangedEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )->PhoneCallStateChangedSystemEvent );
  _this->DismissTimer.OnTrigger = EwNewSlot( _this, TelephoneTEL01_IncomingCall_OnDismissSlot );
  _this->KeyEnableTimer.OnTrigger = EwNewSlot( _this, TelephoneTEL01_IncomingCall_OnKeyEnableSlot );
  ViewsImage_OnSetBitmap( &_this->Divider, EwLoadResource( &ResourceStatusBarDivider, 
  ResourcesBitmap ));

  /* Call the user defined constructor */
  TelephoneTEL01_IncomingCall_Init( _this, aArg );
}

/* Re-Initializer for the class 'Telephone::TEL01_IncomingCall' */
void TelephoneTEL01_IncomingCall__ReInit( TelephoneTEL01_IncomingCall _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  TelephoneImageButton__ReInit( &_this->AnswerButton );
  TelephoneImageButton__ReInit( &_this->DeclineButton );
  ViewsImage__ReInit( &_this->ForegroundImage );
  ComponentsBaseText__ReInit( &_this->CallerText );
  CoreSystemEventHandler__ReInit( &_this->PhoneCallStateChangedEventHandler );
  CoreTimer__ReInit( &_this->DismissTimer );
  CoreTimer__ReInit( &_this->KeyEnableTimer );
  ViewsImage__ReInit( &_this->Divider );

  /* ... and re-initialize objects, variables, properties, etc. */
  ViewsText_OnSetFont((ViewsText)&_this->CallerText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
}

/* Finalizer method for the class 'Telephone::TEL01_IncomingCall' */
void TelephoneTEL01_IncomingCall__Done( TelephoneTEL01_IncomingCall _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  TelephoneImageButton__Done( &_this->AnswerButton );
  TelephoneImageButton__Done( &_this->DeclineButton );
  ViewsImage__Done( &_this->ForegroundImage );
  ComponentsBaseText__Done( &_this->CallerText );
  CoreSystemEventHandler__Done( &_this->PhoneCallStateChangedEventHandler );
  CoreTimer__Done( &_this->DismissTimer );
  CoreTimer__Done( &_this->KeyEnableTimer );
  ViewsImage__Done( &_this->Divider );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void TelephoneTEL01_IncomingCall_Init( TelephoneTEL01_IncomingCall _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  ViewsText_OnSetString((ViewsText)&_this->CallerText, DeviceInterfaceNotificationDeviceClass_GetIncomingCallCaller( 
  EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )));

  if ( 0 == EwGetStringLength( _this->CallerText.Super1.String ))
    ViewsText_OnSetString((ViewsText)&_this->CallerText, EwLoadString( &StringsGEN_THREE_HYPHENS ));

  if ( 1 >= ViewsText_GetNoOfRows((ViewsText)&_this->CallerText ))
    ViewsText_OnSetAlignment((ViewsText)&_this->CallerText, ViewsTextAlignmentAlignHorzCenter 
    | ViewsTextAlignmentAlignVertTop );
  else
  {
    ViewsText_OnSetAlignment((ViewsText)&_this->CallerText, ViewsTextAlignmentAlignHorzLeft 
    | ViewsTextAlignmentAlignVertTop );
    CoreRectView__OnSetBounds( &_this->CallerText, _Const0006 );
  }

  ViewsText_OnSetVisible((ViewsText)&_this->CallerText, 1 );
  EwTrace( "%s%s", EwLoadString( &_Const0007 ), _this->CallerText.Super1.String );
}

/* 'C' function for method : 'Telephone::TEL01_IncomingCall.OnShortDownKeyActivated()' */
void TelephoneTEL01_IncomingCall_OnShortDownKeyActivated( TelephoneTEL01_IncomingCall _this )
{
  if ( _this->IsKeyEnabled )
  {
    TelephoneImageButton_DisplayHighlightAnimation( &_this->DeclineButton );
    DeviceInterfaceNotificationDeviceClass_DeclinePhoneCall( EwGetAutoObject( &DeviceInterfaceNotificationDevice, 
    DeviceInterfaceNotificationDeviceClass ));
  }
}

/* 'C' function for method : 'Telephone::TEL01_IncomingCall.OnShortUpKeyActivated()' */
void TelephoneTEL01_IncomingCall_OnShortUpKeyActivated( TelephoneTEL01_IncomingCall _this )
{
  if ( _this->IsKeyEnabled )
  {
    TelephoneImageButton_DisplayHighlightAnimation( &_this->AnswerButton );
    DeviceInterfaceNotificationDeviceClass_AnswerPhoneCall( EwGetAutoObject( &DeviceInterfaceNotificationDevice, 
    DeviceInterfaceNotificationDeviceClass ));
  }
}

/* 'C' function for method : 'Telephone::TEL01_IncomingCall.OnShortHomeKeyActivated()' */
void TelephoneTEL01_IncomingCall_OnShortHomeKeyActivated( TelephoneTEL01_IncomingCall _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* 'C' function for method : 'Telephone::TEL01_IncomingCall.OnLongHomeKeyActivated()' */
void TelephoneTEL01_IncomingCall_OnLongHomeKeyActivated( TelephoneTEL01_IncomingCall _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* 'C' function for method : 'Telephone::TEL01_IncomingCall.OnPhoneCallStateChangedSlot()' */
void TelephoneTEL01_IncomingCall_OnPhoneCallStateChangedSlot( TelephoneTEL01_IncomingCall _this, 
  XObject sender )
{
  XEnum PhoneCallState;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  PhoneCallState = DeviceInterfaceNotificationDeviceClass_GetPhoneCallState( EwGetAutoObject( 
  &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass ));

  switch ( PhoneCallState )
  {
    case EnumPhoneCallStateIDLE :
      CoreTimer_OnSetEnabled( &_this->DismissTimer, 1 );
    break;

    case EnumPhoneCallStateACTIVE :
    {
      CoreTimer_OnSetEnabled( &_this->DismissTimer, 0 );

      if ( _this->Super5.Owner != 0 )
        CoreGroup_SwitchToDialog( _this->Super5.Owner, ((CoreGroup)EwNewObject( 
        TelephoneTEL02_ActiveCall, 0 )), 0, 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 
        0 );
    }
    break;

    default :; 
  }
}

/* 'C' function for method : 'Telephone::TEL01_IncomingCall.OnDismissSlot()' */
void TelephoneTEL01_IncomingCall_OnDismissSlot( TelephoneTEL01_IncomingCall _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ComponentsBaseMainBG_DismissThisDialog((ComponentsBaseMainBG)_this );
}

/* 'C' function for method : 'Telephone::TEL01_IncomingCall.OnKeyEnableSlot()' */
void TelephoneTEL01_IncomingCall_OnKeyEnableSlot( TelephoneTEL01_IncomingCall _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->IsKeyEnabled = 1;
}

/* Variants derived from the class : 'Telephone::TEL01_IncomingCall' */
EW_DEFINE_CLASS_VARIANTS( TelephoneTEL01_IncomingCall )
EW_END_OF_CLASS_VARIANTS( TelephoneTEL01_IncomingCall )

/* Virtual Method Table (VMT) for the class : 'Telephone::TEL01_IncomingCall' */
EW_DEFINE_CLASS( TelephoneTEL01_IncomingCall, ComponentsBaseMainBG, AnswerButton, 
                 AnswerButton, AnswerButton, AnswerButton, IsKeyEnabled, IsKeyEnabled, 
                 "Telephone::TEL01_IncomingCall" )
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
  TelephoneTEL01_IncomingCall_OnShortDownKeyActivated,
  TelephoneTEL01_IncomingCall_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  TelephoneTEL01_IncomingCall_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  TelephoneTEL01_IncomingCall_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( TelephoneTEL01_IncomingCall )

/* Initializer for the class 'Telephone::TEL02_ActiveCall' */
void TelephoneTEL02_ActiveCall__Init( TelephoneTEL02_ActiveCall _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( TelephoneTEL02_ActiveCall );

  /* ... then construct all embedded objects */
  TelephoneImageButton__Init( &_this->VolumeUpButton, &_this->_.XObject, 0 );
  TelephoneImageButton__Init( &_this->VolumeDownButton, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->ForegroundImage, &_this->_.XObject, 0 );
  ComponentsBaseText__Init( &_this->CallerText, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->DurationText, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->PhoneCallStateChangedEventHandler, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->UpdateDurationTimer, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Divider, &_this->_.XObject, 0 );
  CoreSystemEventHandler__Init( &_this->PhoneCallVolumeChangedEventHandler, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Image, &_this->_.XObject, 0 );
  CoreTimer__Init( &_this->DismissTimer, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( TelephoneTEL02_ActiveCall );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( &_this->VolumeUpButton, _Const0001 );
  TelephoneImageButton_OnSetForegroundFrameNumber( &_this->VolumeUpButton, 1 );
  CoreRectView__OnSetBounds( &_this->VolumeDownButton, _Const0002 );
  TelephoneImageButton_OnSetForegroundFrameNumber( &_this->VolumeDownButton, 1 );
  CoreRectView__OnSetBounds( &_this->ForegroundImage, _Const0003 );
  CoreRectView__OnSetBounds( &_this->CallerText, _Const0008 );
  ViewsText_OnSetEllipsis((ViewsText)&_this->CallerText, 1 );
  ViewsText_OnSetWrapText((ViewsText)&_this->CallerText, 1 );
  ViewsText_OnSetAlignment((ViewsText)&_this->CallerText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString((ViewsText)&_this->CallerText, 0 );
  ViewsText_OnSetVisible((ViewsText)&_this->CallerText, 1 );
  CoreRectView__OnSetBounds( &_this->DurationText, _Const0009 );
  ViewsText_OnSetEllipsis( &_this->DurationText, 1 );
  ViewsText_OnSetString( &_this->DurationText, 0 );
  ViewsText_OnSetVisible( &_this->DurationText, 1 );
  CoreTimer_OnSetPeriod( &_this->UpdateDurationTimer, 500 );
  CoreTimer_OnSetEnabled( &_this->UpdateDurationTimer, 1 );
  CoreRectView__OnSetBounds( &_this->Divider, _Const0005 );
  ViewsImage_OnSetAlignment( &_this->Divider, ViewsImageAlignmentAlignVertBottom 
  | ViewsImageAlignmentScaleToFit );
  CoreRectView__OnSetBounds( &_this->Image, _Const000A );
  CoreTimer_OnSetPeriod( &_this->DismissTimer, 0 );
  CoreTimer_OnSetBegin( &_this->DismissTimer, 1000 );
  CoreGroup__Add( _this, ((CoreView)&_this->VolumeUpButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->VolumeDownButton ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ForegroundImage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CallerText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DurationText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Image ), 0 );
  ViewsImage_OnSetBitmap( &_this->Super1.MainBottomBG, EwLoadResource( &ResourceMainBG, 
  ResourcesBitmap ));
  TelephoneImageButton_OnSetForegroundBmp( &_this->VolumeUpButton, EwLoadResource( 
  &ResourcePhoneVolumeUp, ResourcesBitmap ));
  TelephoneImageButton_OnSetForegroundBmp( &_this->VolumeDownButton, EwLoadResource( 
  &ResourcePhoneVolumeDown, ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ForegroundImage, EwLoadResource( &ResourceActiveCallIcon, 
  ResourcesBitmap ));
  ViewsText_OnSetFont((ViewsText)&_this->CallerText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DurationText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  _this->PhoneCallStateChangedEventHandler.OnEvent = EwNewSlot( _this, TelephoneTEL02_ActiveCall_OnPhoneCallStateChangedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->PhoneCallStateChangedEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )->PhoneCallStateChangedSystemEvent );
  _this->UpdateDurationTimer.OnTrigger = EwNewSlot( _this, TelephoneTEL02_ActiveCall_OnUpdateDurationSlot );
  ViewsImage_OnSetBitmap( &_this->Divider, EwLoadResource( &ResourceStatusBarDivider, 
  ResourcesBitmap ));
  _this->PhoneCallVolumeChangedEventHandler.OnEvent = EwNewSlot( _this, TelephoneTEL02_ActiveCall_OnPhoneCallVolumeChangedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->PhoneCallVolumeChangedEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )->PhoneCallVolumeChangedSystemEvent );
  ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ResourcePhoneVol, ResourcesBitmap ));
  _this->DismissTimer.OnTrigger = EwNewSlot( _this, TelephoneTEL02_ActiveCall_OnDismissSlot );

  /* Call the user defined constructor */
  TelephoneTEL02_ActiveCall_Init( _this, aArg );
}

/* Re-Initializer for the class 'Telephone::TEL02_ActiveCall' */
void TelephoneTEL02_ActiveCall__ReInit( TelephoneTEL02_ActiveCall _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  TelephoneImageButton__ReInit( &_this->VolumeUpButton );
  TelephoneImageButton__ReInit( &_this->VolumeDownButton );
  ViewsImage__ReInit( &_this->ForegroundImage );
  ComponentsBaseText__ReInit( &_this->CallerText );
  ViewsText__ReInit( &_this->DurationText );
  CoreSystemEventHandler__ReInit( &_this->PhoneCallStateChangedEventHandler );
  CoreTimer__ReInit( &_this->UpdateDurationTimer );
  ViewsImage__ReInit( &_this->Divider );
  CoreSystemEventHandler__ReInit( &_this->PhoneCallVolumeChangedEventHandler );
  ViewsImage__ReInit( &_this->Image );
  CoreTimer__ReInit( &_this->DismissTimer );

  /* ... and re-initialize objects, variables, properties, etc. */
  ViewsText_OnSetFont((ViewsText)&_this->CallerText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DurationText, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
}

/* Finalizer method for the class 'Telephone::TEL02_ActiveCall' */
void TelephoneTEL02_ActiveCall__Done( TelephoneTEL02_ActiveCall _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  TelephoneImageButton__Done( &_this->VolumeUpButton );
  TelephoneImageButton__Done( &_this->VolumeDownButton );
  ViewsImage__Done( &_this->ForegroundImage );
  ComponentsBaseText__Done( &_this->CallerText );
  ViewsText__Done( &_this->DurationText );
  CoreSystemEventHandler__Done( &_this->PhoneCallStateChangedEventHandler );
  CoreTimer__Done( &_this->UpdateDurationTimer );
  ViewsImage__Done( &_this->Divider );
  CoreSystemEventHandler__Done( &_this->PhoneCallVolumeChangedEventHandler );
  ViewsImage__Done( &_this->Image );
  CoreTimer__Done( &_this->DismissTimer );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void TelephoneTEL02_ActiveCall_Init( TelephoneTEL02_ActiveCall _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  TelephoneTEL02_ActiveCall_UpdateCaller( _this );
  _this->VolumeControllable = DeviceInterfaceNotificationDeviceClass_IsPhoneCallVolumeControllable( 
  EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass ));

  if ( _this->VolumeControllable )
  {
    TelephoneImageButton_OnSetForegroundFrameNumber( &_this->VolumeUpButton, 0 );
    TelephoneImageButton_OnSetForegroundFrameNumber( &_this->VolumeDownButton, 0 );
  }

  EwSignal( EwNewSlot( _this, TelephoneTEL02_ActiveCall_OnPhoneCallVolumeChangedSlot ), 
    ((XObject)_this ));
  EwSignal( EwNewSlot( _this, TelephoneTEL02_ActiveCall_OnUpdateDurationSlot ), 
    ((XObject)_this ));
  EwTrace( "%s%s", EwLoadString( &_Const000B ), _this->CallerText.Super1.String );
}

/* 'C' function for method : 'Telephone::TEL02_ActiveCall.OnShortDownKeyActivated()' */
void TelephoneTEL02_ActiveCall_OnShortDownKeyActivated( TelephoneTEL02_ActiveCall _this )
{
  if ( _this->VolumeControllable && ( 0 < _this->PhoneCallVolume ))
  {
    TelephoneImageButton_DisplayHighlightAnimation( &_this->VolumeDownButton );
    DeviceInterfaceNotificationDeviceClass_PhoneCallVolumeControl( EwGetAutoObject( 
    &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass ), 
    EnumVolumeControlDOWN );
  }
}

/* 'C' function for method : 'Telephone::TEL02_ActiveCall.OnShortUpKeyActivated()' */
void TelephoneTEL02_ActiveCall_OnShortUpKeyActivated( TelephoneTEL02_ActiveCall _this )
{
  if ( _this->VolumeControllable && ( 100 > _this->PhoneCallVolume ))
  {
    TelephoneImageButton_DisplayHighlightAnimation( &_this->VolumeUpButton );
    DeviceInterfaceNotificationDeviceClass_PhoneCallVolumeControl( EwGetAutoObject( 
    &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass ), 
    EnumVolumeControlUP );
  }
}

/* 'C' function for method : 'Telephone::TEL02_ActiveCall.OnPhoneCallStateChangedSlot()' */
void TelephoneTEL02_ActiveCall_OnPhoneCallStateChangedSlot( TelephoneTEL02_ActiveCall _this, 
  XObject sender )
{
  XEnum PhoneCallState;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  PhoneCallState = DeviceInterfaceNotificationDeviceClass_GetPhoneCallState( EwGetAutoObject( 
  &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass ));

  switch ( PhoneCallState )
  {
    case EnumPhoneCallStateIDLE :
      CoreTimer_OnSetEnabled( &_this->DismissTimer, 1 );
    break;

    case EnumPhoneCallStateACTIVE :
    {
      CoreTimer_OnSetEnabled( &_this->DismissTimer, 0 );
      TelephoneTEL02_ActiveCall_UpdateCaller( _this );
    }
    break;

    default :; 
  }
}

/* 'C' function for method : 'Telephone::TEL02_ActiveCall.OnUpdateDurationSlot()' */
void TelephoneTEL02_ActiveCall_OnUpdateDurationSlot( TelephoneTEL02_ActiveCall _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( EnumPhoneCallStateACTIVE == DeviceInterfaceNotificationDeviceClass_GetPhoneCallState( 
      EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )))
  {
    XUInt32 TotalDurationSec = DeviceInterfaceNotificationDeviceClass_GetActiveCallDuration( 
      EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )) 
      / 1000;
    XUInt32 DurationHour = TotalDurationSec / 3600;
    XUInt32 DurationSec = TotalDurationSec % 60;
    XUInt32 DurationMinute = ( TotalDurationSec / 60 ) - ( DurationHour * 60 );

    if ( DurationHour > 0 )
      ViewsText_OnSetString( &_this->DurationText, EwConcatString( EwConcatString( 
      EwConcatString( EwConcatString( EwNewStringUInt( DurationHour, 0, 10 ), EwLoadString( 
      &_Const000C )), EwNewStringUInt( DurationMinute, 2, 10 )), EwLoadString( &_Const000C )), 
      EwNewStringUInt( DurationSec, 2, 10 )));
    else
      ViewsText_OnSetString( &_this->DurationText, EwConcatString( EwConcatString( 
      EwNewStringUInt( DurationMinute, 0, 10 ), EwLoadString( &_Const000C )), EwNewStringUInt( 
      DurationSec, 2, 10 )));
  }
}

/* 'C' function for method : 'Telephone::TEL02_ActiveCall.OnPhoneCallVolumeChangedSlot()' */
void TelephoneTEL02_ActiveCall_OnPhoneCallVolumeChangedSlot( TelephoneTEL02_ActiveCall _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( DeviceInterfaceNotificationDeviceClass_IsPhoneCallVolumeControllable( EwGetAutoObject( 
      &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )))
  {
    _this->PhoneCallVolume = DeviceInterfaceNotificationDeviceClass_GetPhoneCallVolume( 
    EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass ));
    EwTrace( "%s%u", EwLoadString( &_Const000D ), _this->PhoneCallVolume );

    if ( 0 == _this->PhoneCallVolume )
      TelephoneImageButton_OnSetForegroundFrameNumber( &_this->VolumeDownButton, 
      1 );
    else
      if ( 100 == _this->PhoneCallVolume )
        TelephoneImageButton_OnSetForegroundFrameNumber( &_this->VolumeUpButton, 
        1 );
      else
      {
        TelephoneImageButton_OnSetForegroundFrameNumber( &_this->VolumeDownButton, 
        0 );
        TelephoneImageButton_OnSetForegroundFrameNumber( &_this->VolumeUpButton, 
        0 );
      }
  }
}

/* 'C' function for method : 'Telephone::TEL02_ActiveCall.OnDismissSlot()' */
void TelephoneTEL02_ActiveCall_OnDismissSlot( TelephoneTEL02_ActiveCall _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ComponentsBaseMainBG_DismissThisDialog((ComponentsBaseMainBG)_this );
}

/* 'C' function for method : 'Telephone::TEL02_ActiveCall.UpdateCaller()' */
void TelephoneTEL02_ActiveCall_UpdateCaller( TelephoneTEL02_ActiveCall _this )
{
  ViewsText_OnSetString((ViewsText)&_this->CallerText, DeviceInterfaceNotificationDeviceClass_GetActiveCallCaller( 
  EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )));

  if ( 0 == EwGetStringLength( _this->CallerText.Super1.String ))
    ViewsText_OnSetString((ViewsText)&_this->CallerText, EwLoadString( &StringsGEN_THREE_HYPHENS ));

  if ( 1 >= ViewsText_GetNoOfRows((ViewsText)&_this->CallerText ))
    ViewsText_OnSetAlignment((ViewsText)&_this->CallerText, ViewsTextAlignmentAlignHorzCenter 
    | ViewsTextAlignmentAlignVertTop );
  else
  {
    ViewsText_OnSetAlignment((ViewsText)&_this->CallerText, ViewsTextAlignmentAlignHorzLeft 
    | ViewsTextAlignmentAlignVertTop );
    CoreRectView__OnSetBounds( &_this->CallerText, _Const0006 );
  }

  ViewsText_OnSetVisible((ViewsText)&_this->CallerText, 1 );
}

/* Variants derived from the class : 'Telephone::TEL02_ActiveCall' */
EW_DEFINE_CLASS_VARIANTS( TelephoneTEL02_ActiveCall )
EW_END_OF_CLASS_VARIANTS( TelephoneTEL02_ActiveCall )

/* Virtual Method Table (VMT) for the class : 'Telephone::TEL02_ActiveCall' */
EW_DEFINE_CLASS( TelephoneTEL02_ActiveCall, ComponentsBaseMainBG, VolumeUpButton, 
                 VolumeUpButton, VolumeUpButton, VolumeUpButton, PhoneCallVolume, 
                 PhoneCallVolume, "Telephone::TEL02_ActiveCall" )
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
  TelephoneTEL02_ActiveCall_OnShortDownKeyActivated,
  TelephoneTEL02_ActiveCall_OnShortUpKeyActivated,
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
EW_END_OF_CLASS( TelephoneTEL02_ActiveCall )

/* Embedded Wizard */
