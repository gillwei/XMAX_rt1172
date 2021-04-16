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
#include "_ComponentsBaseMainBG.h"
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreVerticalList.h"
#include "_CoreView.h"
#include "_DeviceInterfaceDateTime.h"
#include "_DeviceInterfaceNotificationContext.h"
#include "_DeviceInterfaceNotificationDeviceClass.h"
#include "_DeviceInterfaceVehicleDeviceClass.h"
#include "_EffectsInt32Effect.h"
#include "_MenuItemNotification.h"
#include "_MenuScrollbar.h"
#include "_MenuVerticalMenu.h"
#include "_NotificationNTF01_NotificationList.h"
#include "_NotificationNTF02_NotificationDetail.h"
#include "_NotificationNotificationDetailText.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "Core.h"
#include "DeviceInterface.h"
#include "Effects.h"
#include "Enum.h"
#include "Fonts.h"
#include "Notification.h"
#include "Resource.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000168, /* ratio 62.22 % */
  0xB8001500, 0x8009C452, 0x00400037, 0x0C200320, 0x010D3A00, 0xB0306C48, 0x6E001248,
  0x9879A400, 0x2A418010, 0x80008C00, 0x44862001, 0x2A2A0400, 0x20929894, 0x8B2D938A,
  0x515980A4, 0x151149C7, 0x78F4609F, 0x3346E390, 0x898C011A, 0xC2237108, 0xCE824C8C,
  0x000558E1, 0x0144859C, 0x053A8194, 0x109E9B00, 0x4004AE6D, 0xA9D562A1, 0x850EA757,
  0xC2A19538, 0x363B218F, 0xA3A448BD, 0x012A0644, 0x07500188, 0x0C8BD000, 0x7AD000F1,
  0x834EE733, 0x0DDA8B08, 0xE0A1D43A, 0x4EDA00A3, 0xE370E885, 0x971BB6D5, 0x600A51B6,
  0x81ABD569, 0x7824524F, 0x8846E331, 0x14800167, 0x49C65249, 0x02855E07, 0xEAF3D390,
  0x76779EE3, 0xB04B856E, 0x08D650EA, 0xFA68035D, 0x0049EB74, 0x00000101, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 10, 0 }, { 444, 76 }};
static const XRect _Const0001 = {{ 10, 50 }, { 470, 236 }};
static const XStringRes _Const0002 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0003 = { _StringsDefault0, 0x000C };
static const XStringRes _Const0004 = { _StringsDefault0, 0x0019 };
static const XStringRes _Const0005 = { _StringsDefault0, 0x001D };
static const XStringRes _Const0006 = { _StringsDefault0, 0x0021 };
static const XStringRes _Const0007 = { _StringsDefault0, 0x0025 };
static const XStringRes _Const0008 = { _StringsDefault0, 0x0029 };
static const XStringRes _Const0009 = { _StringsDefault0, 0x004B };
static const XStringRes _Const000A = { _StringsDefault0, 0x005F };
static const XStringRes _Const000B = { _StringsDefault0, 0x006B };
static const XRect _Const000C = {{ 11, 44 }, { 444, 265 }};
static const XColor _Const000D = { 0xCC, 0xCC, 0xCC, 0xFF };
static const XRect _Const000E = {{ 453, 44 }, { 461, 252 }};
static const XRect _Const000F = {{ 33, 48 }, { 439, 258 }};
static const XRect _Const0010 = {{ 0, 36 }, { 480, 38 }};
static const XStringRes _Const0011 = { _StringsDefault0, 0x008D };
static const XRect _Const0012 = {{ 0, 0 }, { 406, 210 }};
static const XRect _Const0013 = {{ 0, 0 }, { 332, 30 }};
static const XColor _Const0014 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0015 = {{ 343, 0 }, { 406, 30 }};
static const XRect _Const0016 = {{ 0, 30 }, { 406, 1260 }};
static const XPoint _Const0017 = { 0, 0 };
static const XStringRes _Const0018 = { _StringsDefault0, 0x009A };
static const XStringRes _Const0019 = { _StringsDefault0, 0x00A8 };

#ifndef EW_DONT_CHECK_INDEX
  /* This function is used to check the indices when accessing an array.
     If you don't want this verification add the define EW_DONT_CHECK_INDEX
     to your Makefile or project settings. */
  static int EwCheckIndex( int aIndex, int aRange, const char* aFile, int aLine )
  {
    if (( aIndex < 0 ) || ( aIndex >= aRange ))
    {
      EwPrint( "[FATAL ERROR in %s:%d] Array index %d out of bounds %d",
                aFile, aLine, aIndex, aRange );
      EwPanic();
    }
    return aIndex;
  }

  #define EwCheckIndex( aIndex, aRange ) \
    EwCheckIndex( aIndex, aRange, __FILE__, __LINE__ )
#else
  #define EwCheckIndex( aIndex, aRange ) aIndex
#endif

/* Initializer for the class 'Notification::NTF01_NotificationList' */
void NotificationNTF01_NotificationList__Init( NotificationNTF01_NotificationList _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NotificationNTF01_NotificationList );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->NotificationListUpdatedSystemEventHandler, &_this->_XObject, 0 );
  ViewsText__Init( &_this->NoDataText, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->NoDataTimeoutTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NotificationNTF01_NotificationList );

  /* ... and initialize objects, variables, properties, etc. */
  MenuVerticalMenu_OnSetScrollbarVisible( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetFocusFrameBounds( &_this->Super1.Menu, _Const0000 );
  MenuVerticalMenu_OnSetSelectedItem( &_this->Super1.Menu, 0 );
  CoreRectView__OnSetBounds( &_this->NoDataText, _Const0001 );
  ViewsText_OnSetString( &_this->NoDataText, EwLoadString( &_Const0002 ));
  CoreTimer_OnSetPeriod( &_this->NoDataTimeoutTimer, 0 );
  CoreTimer_OnSetBegin( &_this->NoDataTimeoutTimer, 2000 );
  CoreTimer_OnSetEnabled( &_this->NoDataTimeoutTimer, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->NoDataText ), 0 );
  _this->NotificationListUpdatedSystemEventHandler.OnEvent = EwNewSlot( _this, NotificationNTF01_NotificationList_OnNotificationListUpdatedSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->NotificationListUpdatedSystemEventHandler, 
  &EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )->NotificationListUpdatedSystemEvent );
  ViewsText_OnSetFont( &_this->NoDataText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->NoDataTimeoutTimer.OnTrigger = EwNewSlot( _this, NotificationNTF01_NotificationList_OnNoDataTimeoutSlot );

  /* Call the user defined constructor */
  NotificationNTF01_NotificationList_Init( _this, aArg );
}

/* Re-Initializer for the class 'Notification::NTF01_NotificationList' */
void NotificationNTF01_NotificationList__ReInit( NotificationNTF01_NotificationList _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->NotificationListUpdatedSystemEventHandler );
  ViewsText__ReInit( &_this->NoDataText );
  CoreTimer__ReInit( &_this->NoDataTimeoutTimer );
}

/* Finalizer method for the class 'Notification::NTF01_NotificationList' */
void NotificationNTF01_NotificationList__Done( NotificationNTF01_NotificationList _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  CoreSystemEventHandler__Done( &_this->NotificationListUpdatedSystemEventHandler );
  ViewsText__Done( &_this->NoDataText );
  CoreTimer__Done( &_this->NoDataTimeoutTimer );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void NotificationNTF01_NotificationList_Init( NotificationNTF01_NotificationList _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0003 ));
  EwPostSignal( EwNewSlot( _this, NotificationNTF01_NotificationList_OnNotificationListUpdatedSlot ), 
    ((XObject)_this ));
}

/* 'C' function for method : 'Notification::NTF01_NotificationList.LoadItemClass()' */
XClass NotificationNTF01_NotificationList_LoadItemClass( NotificationNTF01_NotificationList _this, 
  XInt32 aItemNo )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aItemNo );

  return EW_CLASS( MenuItemNotification );
}

/* 'C' function for method : 'Notification::NTF01_NotificationList.LoadItemTitle()' */
XString NotificationNTF01_NotificationList_LoadItemTitle( NotificationNTF01_NotificationList _this, 
  XInt32 aItemNo )
{
  XString Title = 0;

  if ( DeviceInterfaceNotificationDeviceClass_OnGetNotificationNum( EwGetAutoObject( 
      &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )) 
      > 0 )
  {
    XUInt32 NotificationIdx = ( DeviceInterfaceNotificationDeviceClass_OnGetNotificationNum( 
      EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )) 
      - aItemNo ) - 1;
    _this->NotificationData = DeviceInterfaceNotificationDeviceClass_GetNotificationAtItem( 
    EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass ), 
    NotificationIdx );

    if ( 0 < EwGetStringLength( _this->NotificationData->Title ))
    {
      Title = _this->NotificationData->Title;
    }

    if ( 0 < EwGetStringLength( _this->NotificationData->Subtitle ))
    {
      if ( 0 < EwGetStringLength( Title ))
      {
        Title = EwConcatString( Title, EwLoadString( &_Const0004 ));
      }

      Title = EwConcatString( Title, _this->NotificationData->Subtitle );
    }

    if ( 0 == EwGetStringLength( Title ))
    {
      Title = EwLoadString( &StringsGEN_THREE_HYPHENS );
    }

    if (( EnumNotificationCategoryMISSED_CALL == _this->NotificationData->Category ) 
        && ( 1 < _this->NotificationData->CallRepetition ))
    {
      Title = EwConcatString( Title, EwConcatString( EwConcatString( EwLoadString( 
      &_Const0005 ), EwNewStringInt( _this->NotificationData->CallRepetition, 0, 
      10 )), EwLoadString( &_Const0006 )));
    }
  }

  return Title;
}

/* 'C' function for method : 'Notification::NTF01_NotificationList.LoadItemReceivedTime()' */
XString NotificationNTF01_NotificationList_LoadItemReceivedTime( NotificationNTF01_NotificationList _this, 
  XInt32 aItemNo )
{
  XString ReceivedTime;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aItemNo );

  ReceivedTime = 0;

  if ( DeviceInterfaceNotificationDeviceClass_OnGetNotificationNum( EwGetAutoObject( 
      &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )) 
      > 0 )
  {
    ReceivedTime = EwConcatString( EwConcatString( _this->NotificationData->ReceivedTime->Hour, 
    EwLoadString( &_Const0007 )), _this->NotificationData->ReceivedTime->Minute );
  }

  return ReceivedTime;
}

/* 'C' function for method : 'Notification::NTF01_NotificationList.LoadItemCategory()' */
XEnum NotificationNTF01_NotificationList_LoadItemCategory( NotificationNTF01_NotificationList _this, 
  XInt32 aItemNo )
{
  XEnum Category;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aItemNo );

  Category = EnumNotificationCategoryMESSAGE;

  if ( DeviceInterfaceNotificationDeviceClass_OnGetNotificationNum( EwGetAutoObject( 
      &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )) 
      > 0 )
  {
    Category = _this->NotificationData->Category;
  }

  return Category;
}

/* 'C' function for method : 'Notification::NTF01_NotificationList.LoadItemUid()' */
XUInt32 NotificationNTF01_NotificationList_LoadItemUid( NotificationNTF01_NotificationList _this, 
  XInt32 aItemNo )
{
  XUInt32 Uid = 0;

  if (( 0 < DeviceInterfaceNotificationDeviceClass_OnGetNotificationNum( EwGetAutoObject( 
      &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass ))) 
      && ( aItemNo < 100 ))
  {
    Uid = _this->NotificationData->Uid;
    _this->NotificationUID[ EwCheckIndex( aItemNo, 100 )] = _this->NotificationData->Uid;
  }

  return Uid;
}

/* 'C' function for method : 'Notification::NTF01_NotificationList.OnItemActivate()' */
void NotificationNTF01_NotificationList_OnItemActivate( NotificationNTF01_NotificationList _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aMenuItem );

  if (( aItemNo >= 0 ) && !DeviceInterfaceVehicleDeviceClass_OnGetDDModeActivated( 
      EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass )))
  {
    NotificationNTF02_NotificationDetail Dialog = EwNewObject( NotificationNTF02_NotificationDetail, 
      0 );
    XUInt32 NotificationIdx = ( DeviceInterfaceNotificationDeviceClass_OnGetNotificationNum( 
      EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )) 
      - aItemNo ) - 1;
    NotificationNTF02_NotificationDetail_OnSetNotificationData( Dialog, DeviceInterfaceNotificationDeviceClass_GetNotificationAtItem( 
    EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass ), 
    NotificationIdx ));
    Dialog->OnDismiss = EwNewSlot( _this, NotificationNTF01_NotificationList_OnNotificationDetailDismissSlot );
    ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)Dialog ));
  }
}

/* 'C' function for method : 'Notification::NTF01_NotificationList.LoadItemMessage()' */
XString NotificationNTF01_NotificationList_LoadItemMessage( NotificationNTF01_NotificationList _this, 
  XInt32 aItemNo )
{
  XString Message;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aItemNo );

  Message = 0;

  if ( EnumNotificationCategoryMESSAGE == _this->NotificationData->Category )
  {
    if ( DeviceInterfaceNotificationDeviceClass_OnGetNotificationNum( EwGetAutoObject( 
        &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass )) 
        > 0 )
    {
      Message = EwStringLeft( _this->NotificationData->Message, 64 );
    }

    if ( 0 == EwGetStringLength( Message ))
    {
      Message = EwLoadString( &StringsGEN_THREE_HYPHENS );
    }
  }
  else
    ;

  return Message;
}

/* This slot method is executed when the associated property observer 'PropertyObserver' 
   is notified. */
void NotificationNTF01_NotificationList_OnNotificationListUpdatedSlot( NotificationNTF01_NotificationList _this, 
  XObject sender )
{
  XUInt32 NotificationNum;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  NotificationNum = DeviceInterfaceNotificationDeviceClass_OnGetNotificationNum( 
  EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass ));
  EwTrace( "%s%u", EwLoadString( &_Const0008 ), NotificationNum );

  if ( 0 < NotificationNum )
  {
    CoreTimer_OnSetEnabled( &_this->NoDataTimeoutTimer, 0 );
    ViewsText_OnSetVisible( &_this->NoDataText, 0 );
    MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, (XInt32)NotificationNum );
    _this->Super1.Menu.Focusable = 1;
    MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, (XInt32)NotificationNum 
    - 1 );

    if ( 0 < _this->Super1.Menu.NoOfItems )
    {
      XUInt32 SelectedNotificationUID = _this->NotificationUID[ EwCheckIndex( _this->Super1.Menu.MenuList.SelectedItem, 
        100 )];
      XInt32 BufferIdx = DeviceInterfaceNotificationDeviceClass_GetBufferIdxOfNotificationUID( 
        EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass ), 
        SelectedNotificationUID );
      EwTrace( "%s%u%s%i", EwLoadString( &_Const0009 ), SelectedNotificationUID, 
        EwLoadString( &_Const000A ), BufferIdx );

      if (( 0 <= BufferIdx ) && ( BufferIdx < _this->Super1.Menu.NoOfItems ))
      {
        MenuVerticalMenu_OnSetSelectedItem( &_this->Super1.Menu, ( _this->Super1.Menu.NoOfItems 
        - BufferIdx ) - 1 );
      }
    }
  }
  else
  {
    if ( CoreGroup__IsCurrentDialog( _this ))
    {
      CoreTimer_OnSetEnabled( &_this->NoDataTimeoutTimer, 1 );
    }

    ViewsText_OnSetVisible( &_this->NoDataText, 1 );
    MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 0 );
    _this->Super1.Menu.Focusable = 0;
  }
}

/* 'C' function for method : 'Notification::NTF01_NotificationList.OnNoDataTimeoutSlot()' */
void NotificationNTF01_NotificationList_OnNoDataTimeoutSlot( NotificationNTF01_NotificationList _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if (( _this->Super6.Owner != 0 ) && CoreGroup__IsCurrentDialog( _this ))
  {
    ComponentsBaseMainBG_DismissThisDialog((ComponentsBaseMainBG)_this );
  }
}

/* 'C' function for method : 'Notification::NTF01_NotificationList.OnNotificationDetailDismissSlot()' */
void NotificationNTF01_NotificationList_OnNotificationDetailDismissSlot( NotificationNTF01_NotificationList _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwTrace( "%s", EwLoadString( &_Const000B ));

  if ( 0 == _this->Super1.Menu.NoOfItems )
  {
    CoreTimer_OnSetEnabled( &_this->NoDataTimeoutTimer, 1 );
  }
}

/* Variants derived from the class : 'Notification::NTF01_NotificationList' */
EW_DEFINE_CLASS_VARIANTS( NotificationNTF01_NotificationList )
EW_END_OF_CLASS_VARIANTS( NotificationNTF01_NotificationList )

/* Virtual Method Table (VMT) for the class : 'Notification::NTF01_NotificationList' */
EW_DEFINE_CLASS( NotificationNTF01_NotificationList, MenuBaseMenuView, NotificationData, 
                 NotificationListUpdatedSystemEventHandler, NotificationListUpdatedSystemEventHandler, 
                 NotificationListUpdatedSystemEventHandler, NotificationUID, NotificationUID, 
                 "Notification::NTF01_NotificationList" )
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
  NotificationNTF01_NotificationList_LoadItemClass,
  NotificationNTF01_NotificationList_LoadItemTitle,
  NotificationNTF01_NotificationList_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemBaseValue,
  NotificationNTF01_NotificationList_LoadItemMessage,
  NotificationNTF01_NotificationList_LoadItemReceivedTime,
  NotificationNTF01_NotificationList_LoadItemCategory,
  NotificationNTF01_NotificationList_LoadItemUid,
  MenuBaseMenuView_LoadItemToggle,
EW_END_OF_CLASS( NotificationNTF01_NotificationList )

/* Initializer for the class 'Notification::NTF02_NotificationDetail' */
void NotificationNTF02_NotificationDetail__Init( NotificationNTF02_NotificationDetail _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NotificationNTF02_NotificationDetail );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->GrayBG, &_this->_XObject, 0 );
  MenuScrollbar__Init( &_this->Scrollbar, &_this->_XObject, 0 );
  NotificationNotificationDetailText__Init( &_this->NotificationText, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->Divider, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NotificationNTF02_NotificationDetail );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super1.SlideOutEffectEnabled = 1;
  CoreRectView__OnSetBounds( &_this->GrayBG, _Const000C );
  ViewsRectangle_OnSetColor( &_this->GrayBG, _Const000D );
  CoreRectView__OnSetBounds( &_this->Scrollbar, _Const000E );
  MenuScrollbar_OnSetViewIdx( &_this->Scrollbar, 0 );
  MenuScrollbar_OnSetPageItems( &_this->Scrollbar, 7 );
  MenuScrollbar_OnSetListItems( &_this->Scrollbar, 1 );
  CoreRectView__OnSetBounds( &_this->NotificationText, _Const000F );
  CoreRectView__OnSetBounds( &_this->Divider, _Const0010 );
  ViewsImage_OnSetAlignment( &_this->Divider, ViewsImageAlignmentAlignVertBottom 
  | ViewsImageAlignmentScaleToFit );
  CoreGroup__Add( _this, ((CoreView)&_this->GrayBG ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Scrollbar ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->NotificationText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Divider ), 0 );
  _this->NotificationText.OnLineNumUpdated = EwNewSlot( _this, NotificationNTF02_NotificationDetail_OnLineNumUpdatedSlot );
  ViewsImage_OnSetBitmap( &_this->Divider, EwLoadResource( &ResourceStatusBarDivider, 
  ResourcesBitmap ));

  /* Call the user defined constructor */
  NotificationNTF02_NotificationDetail_Init( _this, aArg );
}

/* Re-Initializer for the class 'Notification::NTF02_NotificationDetail' */
void NotificationNTF02_NotificationDetail__ReInit( NotificationNTF02_NotificationDetail _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->GrayBG );
  MenuScrollbar__ReInit( &_this->Scrollbar );
  NotificationNotificationDetailText__ReInit( &_this->NotificationText );
  ViewsImage__ReInit( &_this->Divider );
}

/* Finalizer method for the class 'Notification::NTF02_NotificationDetail' */
void NotificationNTF02_NotificationDetail__Done( NotificationNTF02_NotificationDetail _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->GrayBG );
  MenuScrollbar__Done( &_this->Scrollbar );
  NotificationNotificationDetailText__Done( &_this->NotificationText );
  ViewsImage__Done( &_this->Divider );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void NotificationNTF02_NotificationDetail_Init( NotificationNTF02_NotificationDetail _this, 
  XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0011 ));
}

/* 'C' function for method : 'Notification::NTF02_NotificationDetail.OnShortDownKeyActivated()' */
void NotificationNTF02_NotificationDetail_OnShortDownKeyActivated( NotificationNTF02_NotificationDetail _this )
{
  MenuScrollbar_OnSetViewIdx( &_this->Scrollbar, NotificationNotificationDetailText_ScrollDownPage( 
  &_this->NotificationText ));
}

/* 'C' function for method : 'Notification::NTF02_NotificationDetail.OnShortUpKeyActivated()' */
void NotificationNTF02_NotificationDetail_OnShortUpKeyActivated( NotificationNTF02_NotificationDetail _this )
{
  MenuScrollbar_OnSetViewIdx( &_this->Scrollbar, NotificationNotificationDetailText_ScrollUpPage( 
  &_this->NotificationText ));
}

/* 'C' function for method : 'Notification::NTF02_NotificationDetail.OnShortEnterKeyActivated()' */
void NotificationNTF02_NotificationDetail_OnShortEnterKeyActivated( NotificationNTF02_NotificationDetail _this )
{
  ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
}

/* 'C' function for method : 'Notification::NTF02_NotificationDetail.OnShortHomeKeyActivated()' */
void NotificationNTF02_NotificationDetail_OnShortHomeKeyActivated( NotificationNTF02_NotificationDetail _this )
{
  EwSignal( _this->OnDismiss, ((XObject)_this ));
  ComponentsBaseMainBG_DismissThisDialog((ComponentsBaseMainBG)_this );
}

/* 'C' function for method : 'Notification::NTF02_NotificationDetail.OnSetNotificationData()' */
void NotificationNTF02_NotificationDetail_OnSetNotificationData( NotificationNTF02_NotificationDetail _this, 
  DeviceInterfaceNotificationContext value )
{
  if ( _this->NotificationData != value )
  {
    _this->NotificationData = value;
    NotificationNotificationDetailText_OnSetNotificationData( &_this->NotificationText, 
    value );
    DeviceInterfaceNotificationDeviceClass_DeleteNotificationOfUid( EwGetAutoObject( 
    &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass ), 
    _this->NotificationData->Uid );
  }
}

/* 'C' function for method : 'Notification::NTF02_NotificationDetail.OnLineNumUpdatedSlot()' */
void NotificationNTF02_NotificationDetail_OnLineNumUpdatedSlot( NotificationNTF02_NotificationDetail _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  MenuScrollbar_OnSetListItems( &_this->Scrollbar, _this->NotificationText.NoOfLines );
}

/* Variants derived from the class : 'Notification::NTF02_NotificationDetail' */
EW_DEFINE_CLASS_VARIANTS( NotificationNTF02_NotificationDetail )
EW_END_OF_CLASS_VARIANTS( NotificationNTF02_NotificationDetail )

/* Virtual Method Table (VMT) for the class : 'Notification::NTF02_NotificationDetail' */
EW_DEFINE_CLASS( NotificationNTF02_NotificationDetail, ComponentsBaseMainBG, NotificationData, 
                 OnDismiss, GrayBG, GrayBG, _None, _None, "Notification::NTF02_NotificationDetail" )
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
  NotificationNTF02_NotificationDetail_OnShortDownKeyActivated,
  NotificationNTF02_NotificationDetail_OnShortUpKeyActivated,
  NotificationNTF02_NotificationDetail_OnShortEnterKeyActivated,
  NotificationNTF02_NotificationDetail_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( NotificationNTF02_NotificationDetail )

/* Initializer for the class 'Notification::NotificationDetailText' */
void NotificationNotificationDetailText__Init( NotificationNotificationDetailText _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( NotificationNotificationDetailText );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->TitleText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->ReceivedTimeText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->MessageText, &_this->_XObject, 0 );
  EffectsInt32Effect__Init( &_this->ScrollEffect, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( NotificationNotificationDetailText );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0012 );
  CoreView_OnSetLayout((CoreView)&_this->TitleText, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->TitleText, _Const0013 );
  ViewsText_OnSetEllipsis( &_this->TitleText, 1 );
  ViewsText_OnSetAlignment( &_this->TitleText, ViewsTextAlignmentAlignHorzLeft | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TitleText, 0 );
  ViewsText_OnSetColor( &_this->TitleText, _Const0014 );
  CoreView_OnSetLayout((CoreView)&_this->ReceivedTimeText, CoreLayoutAlignToLeft 
  | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->ReceivedTimeText, _Const0015 );
  ViewsText_OnSetAlignment( &_this->ReceivedTimeText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->ReceivedTimeText, 0 );
  ViewsText_OnSetColor( &_this->ReceivedTimeText, _Const0014 );
  CoreView_OnSetLayout((CoreView)&_this->MessageText, CoreLayoutAlignToLeft | CoreLayoutAlignToTop );
  CoreRectView__OnSetBounds( &_this->MessageText, _Const0016 );
  ViewsText_OnSetRowDistance( &_this->MessageText, 30 );
  ViewsText_OnSetEllipsis( &_this->MessageText, 1 );
  ViewsText_OnSetWrapText( &_this->MessageText, 1 );
  ViewsText_OnSetScrollOffset( &_this->MessageText, _Const0017 );
  ViewsText_OnSetAlignment( &_this->MessageText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertTop );
  ViewsText_OnSetString( &_this->MessageText, 0 );
  ViewsText_OnSetColor( &_this->MessageText, _Const0014 );
  _this->TitleInitBounds = _Const0013;
  _this->ReceivedTimeInitBounds = _Const0015;
  _this->MessageInitBounds = _Const0016;
  EffectsEffect_OnSetExponent((EffectsEffect)&_this->ScrollEffect, 4.190000f );
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->ScrollEffect, EffectsTimingExp_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->ScrollEffect, 1 );
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->ScrollEffect, 200 );
  EffectsEffect_OnSetInitialDelay((EffectsEffect)&_this->ScrollEffect, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TitleText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ReceivedTimeText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MessageText ), 0 );
  ViewsText_OnSetFont( &_this->TitleText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->ReceivedTimeText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->MessageText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->ScrollEffect.Super1.OnFinished = EwNullSlot;
  _this->ScrollEffect.Super1.OnAnimate = EwNullSlot;
  _this->ScrollEffect.Outlet = EwNewRef( _this, NotificationNotificationDetailText_OnGetScrollOffsetY, 
  NotificationNotificationDetailText_OnSetScrollOffsetY );
}

/* Re-Initializer for the class 'Notification::NotificationDetailText' */
void NotificationNotificationDetailText__ReInit( NotificationNotificationDetailText _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->TitleText );
  ViewsText__ReInit( &_this->ReceivedTimeText );
  ViewsText__ReInit( &_this->MessageText );
  EffectsInt32Effect__ReInit( &_this->ScrollEffect );
}

/* Finalizer method for the class 'Notification::NotificationDetailText' */
void NotificationNotificationDetailText__Done( NotificationNotificationDetailText _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->TitleText );
  ViewsText__Done( &_this->ReceivedTimeText );
  ViewsText__Done( &_this->MessageText );
  EffectsInt32Effect__Done( &_this->ScrollEffect );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* 'C' function for method : 'Notification::NotificationDetailText.OnSetScrollOffsetY()' */
void NotificationNotificationDetailText_OnSetScrollOffsetY( NotificationNotificationDetailText _this, 
  XInt32 value )
{
  if ( _this->ScrollOffsetY != value )
  {
    XRect NewBounds;
    _this->ScrollOffsetY = value;
    NewBounds = _this->TitleInitBounds;
    NewBounds.Point1.Y = value;
    NewBounds.Point2.Y = ( NewBounds.Point1.Y + EwGetRectH( _this->TitleInitBounds ));
    CoreRectView__OnSetBounds( &_this->TitleText, NewBounds );
    NewBounds = _this->ReceivedTimeInitBounds;
    NewBounds.Point1.Y = value;
    NewBounds.Point2.Y = ( NewBounds.Point1.Y + EwGetRectH( _this->ReceivedTimeInitBounds ));
    CoreRectView__OnSetBounds( &_this->ReceivedTimeText, NewBounds );
    NewBounds = _this->MessageInitBounds;
    NewBounds.Point1.Y = ( NewBounds.Point1.Y + value );
    NewBounds.Point2.Y = ( NewBounds.Point1.Y + EwGetRectH( _this->MessageInitBounds ));
    CoreRectView__OnSetBounds( &_this->MessageText, NewBounds );
  }
}

/* 'C' function for method : 'Notification::NotificationDetailText.ScrollDownPage()' */
XInt32 NotificationNotificationDetailText_ScrollDownPage( NotificationNotificationDetailText _this )
{
  if ( !_this->ScrollEffect.Super1.Enabled )
  {
    XInt32 NextScrollOffsetY = _this->ScrollOffsetY - EwGetRectH( _this->Super2.Bounds );
    XInt32 MaxScrollOffset = ( _this->NoOfLines * _this->MessageText.RowDistance ) 
      - EwGetRectH( _this->Super2.Bounds );

    if ( MaxScrollOffset < 0 )
    {
      MaxScrollOffset = 0;
    }

    if ( EwGetInt32Abs( NextScrollOffsetY ) > MaxScrollOffset )
    {
      NextScrollOffsetY = -1 * MaxScrollOffset;
    }

    _this->ScrollEffect.Value1 = _this->ScrollOffsetY;
    _this->ScrollEffect.Value2 = NextScrollOffsetY;
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->ScrollEffect, 1 );
    _this->LineToScroll = (( EwGetInt32Abs( NextScrollOffsetY ) / _this->MessageText.RowDistance ) 
    + 7 ) - 1;
    EwTrace( "%s%i", EwLoadString( &_Const0018 ), _this->LineToScroll );
  }

  return _this->LineToScroll;
}

/* 'C' function for method : 'Notification::NotificationDetailText.UpdateLineNum()' */
void NotificationNotificationDetailText_UpdateLineNum( NotificationNotificationDetailText _this )
{
  _this->NoOfLines = ViewsText_GetNoOfRows( &_this->MessageText ) + 1;
  EwSignal( _this->OnLineNumUpdated, ((XObject)_this ));
}

/* 'C' function for method : 'Notification::NotificationDetailText.ScrollUpPage()' */
XInt32 NotificationNotificationDetailText_ScrollUpPage( NotificationNotificationDetailText _this )
{
  if ( !_this->ScrollEffect.Super1.Enabled && ( _this->ScrollOffsetY < 0 ))
  {
    XInt32 NextScrollOffsetY = _this->ScrollOffsetY + EwGetRectH( _this->Super2.Bounds );

    if ( NextScrollOffsetY > 0 )
    {
      NextScrollOffsetY = 0;
    }

    _this->ScrollEffect.Value1 = _this->ScrollOffsetY;
    _this->ScrollEffect.Value2 = NextScrollOffsetY;
    EffectsEffect_OnSetEnabled((EffectsEffect)&_this->ScrollEffect, 1 );
    _this->LineToScroll = (( EwGetInt32Abs( NextScrollOffsetY ) / _this->MessageText.RowDistance ) 
    + 7 ) - 1;
    EwTrace( "%s%i", EwLoadString( &_Const0019 ), _this->LineToScroll );
  }

  return _this->LineToScroll;
}

/* 'C' function for method : 'Notification::NotificationDetailText.OnSetNotificationData()' */
void NotificationNotificationDetailText_OnSetNotificationData( NotificationNotificationDetailText _this, 
  DeviceInterfaceNotificationContext value )
{
  if ( _this->NotificationData != value )
  {
    _this->NotificationData = value;
    ViewsText_OnSetString( &_this->TitleText, value->Title );

    if ( 0 < EwGetStringLength( value->Title ))
    {
      ViewsText_OnSetString( &_this->TitleText, value->Title );
    }

    if ( 0 < EwGetStringLength( value->Subtitle ))
    {
      if ( 0 < EwGetStringLength( _this->TitleText.String ))
      {
        ViewsText_OnSetString( &_this->TitleText, EwConcatString( _this->TitleText.String, 
        EwLoadString( &_Const0004 )));
      }

      ViewsText_OnSetString( &_this->TitleText, EwConcatString( _this->TitleText.String, 
      value->Subtitle ));
    }

    if ( 0 == EwGetStringLength( _this->TitleText.String ))
    {
      ViewsText_OnSetString( &_this->TitleText, EwLoadString( &StringsGEN_THREE_HYPHENS ));
    }

    ViewsText_OnSetString( &_this->ReceivedTimeText, EwConcatString( EwConcatString( 
    _this->NotificationData->ReceivedTime->Hour, EwLoadString( &_Const0007 )), _this->NotificationData->ReceivedTime->Minute ));

    if ( EnumNotificationCategoryMESSAGE == _this->NotificationData->Category )
    {
      ViewsText_OnSetString( &_this->MessageText, EwConcatString( _this->MessageText.String, 
      value->Message ));

      if ( 0 == EwGetStringLength( _this->MessageText.String ))
      {
        ViewsText_OnSetString( &_this->MessageText, EwLoadString( &StringsGEN_THREE_HYPHENS ));
      }
    }

    NotificationNotificationDetailText_UpdateLineNum( _this );
  }
}

/* Default onget method for the property 'ScrollOffsetY' */
XInt32 NotificationNotificationDetailText_OnGetScrollOffsetY( NotificationNotificationDetailText _this )
{
  return _this->ScrollOffsetY;
}

/* Variants derived from the class : 'Notification::NotificationDetailText' */
EW_DEFINE_CLASS_VARIANTS( NotificationNotificationDetailText )
EW_END_OF_CLASS_VARIANTS( NotificationNotificationDetailText )

/* Virtual Method Table (VMT) for the class : 'Notification::NotificationDetailText' */
EW_DEFINE_CLASS( NotificationNotificationDetailText, CoreGroup, NotificationData, 
                 OnLineNumUpdated, TitleText, TitleText, ScrollOffsetY, ScrollOffsetY, 
                 "Notification::NotificationDetailText" )
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
EW_END_OF_CLASS( NotificationNotificationDetailText )

/* Embedded Wizard */
