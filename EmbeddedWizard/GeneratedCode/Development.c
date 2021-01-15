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
#include "_CoreSystemEventHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_DevelopmentDEV_Bluetooth.h"
#include "_DevelopmentDEV_Main.h"
#include "_DevelopmentDEV_RealTimeClock.h"
#include "_DevelopmentDEV_TFTBrightness.h"
#include "_DeviceInterfaceRtcTime.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_FactoryMain.h"
#include "_MenuItemBase.h"
#include "_MenuItemCheckbox.h"
#include "_MenuVerticalMenu.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsText.h"
#include "Core.h"
#include "Development.h"
#include "DeviceInterface.h"
#include "Fonts.h"
#include "Resource.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000120, /* ratio 63.89 % */
  0xB8001F00, 0x8008C452, 0x00C60030, 0x0DE003A0, 0xF2003900, 0x80010000, 0x0032800A,
  0xC0042CE6, 0x22C0C271, 0x80021A48, 0xC3E2F233, 0x6A4D1589, 0x89B14864, 0x39263248,
  0xC528F84A, 0x28364224, 0xD001A62D, 0x21C524C6, 0x543A7000, 0x802386B8, 0x04851F08,
  0x24C75005, 0x190E8743, 0x72A9C9A2, 0x1F0B4723, 0x48B41A2D, 0x9DC42951, 0x654C0067,
  0x46AAA6E8, 0xAE31168A, 0xE3E04A34, 0x291FB60B, 0x504B6C72, 0x04AC5187, 0x30057295,
  0x8D99A445, 0xC49E0E77, 0x498AD148, 0x3A771A88, 0xC131CB2C, 0x197D8447, 0x91886422,
  0x25C78223, 0x6B95DA49, 0x00406394, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XStringRes _Const0001 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0002 = { _StringsDefault0, 0x0011 };
static const XStringRes _Const0003 = { _StringsDefault0, 0x0024 };
static const XStringRes _Const0004 = { _StringsDefault0, 0x0036 };
static const XStringRes _Const0005 = { _StringsDefault0, 0x0047 };
static const XRect _Const0006 = {{ 0, 36 }, { 480, 272 }};
static const XRect _Const0007 = {{ 96, 79 }, { 390, 122 }};
static const XStringRes _Const0008 = { _StringsDefault0, 0x005D };
static const XStringRes _Const0009 = { _StringsDefault0, 0x0061 };
static const XStringRes _Const000A = { _StringsDefault0, 0x0065 };
static const XRect _Const000B = {{ 0, 40 }, { 240, 65 }};
static const XStringRes _Const000C = { _StringsDefault0, 0x0069 };
static const XRect _Const000D = {{ 247, 40 }, { 356, 65 }};
static const XRect _Const000E = {{ 432, 2 }, { 482, 22 }};
static const XStringRes _Const000F = { _StringsDefault0, 0x007F };
static const XStringRes _Const0010 = { _StringsDefault0, 0x0088 };

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

/* Initializer for the class 'Development::DEV_Main' */
void DevelopmentDEV_Main__Init( DevelopmentDEV_Main _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DevelopmentDEV_Main );

  /* ... then construct all embedded objects */
  MenuVerticalMenu__Init( &_this->Menu, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DevelopmentDEV_Main );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0001 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const0002 ));
  _this->ItemTitleArray[ 2 ] = EwShareString( EwLoadString( &_Const0003 ));
  _this->ItemTitleArray[ 3 ] = EwShareString( EwLoadString( &_Const0004 ));
  _this->ItemTitleArray[ 4 ] = EwShareString( EwLoadString( &_Const0005 ));
  CoreRectView__OnSetBounds( &_this->Menu, _Const0006 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 5 );
  MenuVerticalMenu_OnSetItemHeight( &_this->Menu, 56 );
  MenuVerticalMenu_OnSetItemNumPerPage( &_this->Menu, 4 );
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );
}

/* Re-Initializer for the class 'Development::DEV_Main' */
void DevelopmentDEV_Main__ReInit( DevelopmentDEV_Main _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  MenuVerticalMenu__ReInit( &_this->Menu );
}

/* Finalizer method for the class 'Development::DEV_Main' */
void DevelopmentDEV_Main__Done( DevelopmentDEV_Main _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  MenuVerticalMenu__Done( &_this->Menu );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* 'C' function for method : 'Development::DEV_Main.OnShortHomeKeyActivated()' */
void DevelopmentDEV_Main_OnShortHomeKeyActivated( DevelopmentDEV_Main _this )
{
  CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Development::DEV_Main.LoadItemClass()' */
XClass DevelopmentDEV_Main_LoadItemClass( DevelopmentDEV_Main _this, XInt32 aItemNo )
{
  XClass ItemClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemClass = 0;

  switch ( aItemNo )
  {
    case 1 :
      ItemClass = EW_CLASS( MenuItemCheckbox );
    break;

    default : 
      ItemClass = EW_CLASS( MenuItemBase );
  }

  return ItemClass;
}

/* 'C' function for method : 'Development::DEV_Main.LoadItemTitle()' */
XString DevelopmentDEV_Main_LoadItemTitle( DevelopmentDEV_Main _this, XInt32 aItemNo )
{
  XString Title = 0;

  if ( aItemNo < 5 )
  {
    Title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 5 )];
  }

  return Title;
}

/* 'C' function for method : 'Development::DEV_Main.OnItemActivate()' */
void DevelopmentDEV_Main_OnItemActivate( DevelopmentDEV_Main _this, XInt32 aItemNo, 
  MenuItemBase aMenuItem )
{
  if ( aMenuItem == 0 )
    ;

  switch ( aItemNo )
  {
    case 0 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( FactoryMain, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 1 :
      EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->IsHopperTestMode 
      = (XBool)!EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->IsHopperTestMode;
    break;

    case 2 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_RealTimeClock, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 3 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_Bluetooth, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    case 4 :
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( DevelopmentDEV_TFTBrightness, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Development::DEV_Main.LoadItemChecked()' */
XBool DevelopmentDEV_Main_LoadItemChecked( DevelopmentDEV_Main _this, XInt32 aItemNo )
{
  XBool IsChecked;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsChecked = 0;

  switch ( aItemNo )
  {
    case 1 :
      IsChecked = EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->IsHopperTestMode;
    break;

    default : 
      ;
  }

  return IsChecked;
}

/* Variants derived from the class : 'Development::DEV_Main' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_Main )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_Main )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_Main' */
EW_DEFINE_CLASS( DevelopmentDEV_Main, MenuBaseMenuView, Menu, Menu, Menu, Menu, 
                 ItemTitleArray, _None, "Development::DEV_Main" )
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
  DevelopmentDEV_Main_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  DevelopmentDEV_Main_LoadItemClass,
  DevelopmentDEV_Main_LoadItemTitle,
  DevelopmentDEV_Main_OnItemActivate,
  DevelopmentDEV_Main_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
EW_END_OF_CLASS( DevelopmentDEV_Main )

/* Initializer for the class 'Development::DEV_RealTimeClock' */
void DevelopmentDEV_RealTimeClock__Init( DevelopmentDEV_RealTimeClock _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DevelopmentDEV_RealTimeClock );

  /* ... then construct all embedded objects */
  CoreSystemEventHandler__Init( &_this->OnUpdateLocalTimeEventHandler, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TimeText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DevelopmentDEV_RealTimeClock );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->TimeText, _Const0007 );
  ViewsText_OnSetAlignment( &_this->TimeText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TimeText, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeText ), 0 );
  _this->OnUpdateLocalTimeEventHandler.OnEvent = EwNewSlot( _this, DevelopmentDEV_RealTimeClock_OnUpdateLocalTimeSlot );
  CoreSystemEventHandler_OnSetEvent( &_this->OnUpdateLocalTimeEventHandler, &EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->UpdateLocalTimeSystemEvent );
  ViewsText_OnSetFont( &_this->TimeText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Development::DEV_RealTimeClock' */
void DevelopmentDEV_RealTimeClock__ReInit( DevelopmentDEV_RealTimeClock _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreSystemEventHandler__ReInit( &_this->OnUpdateLocalTimeEventHandler );
  ViewsText__ReInit( &_this->TimeText );
}

/* Finalizer method for the class 'Development::DEV_RealTimeClock' */
void DevelopmentDEV_RealTimeClock__Done( DevelopmentDEV_RealTimeClock _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  CoreSystemEventHandler__Done( &_this->OnUpdateLocalTimeEventHandler );
  ViewsText__Done( &_this->TimeText );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* 'C' function for method : 'Development::DEV_RealTimeClock.OnShortHomeKeyActivated()' */
void DevelopmentDEV_RealTimeClock_OnShortHomeKeyActivated( DevelopmentDEV_RealTimeClock _this )
{
  CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Development::DEV_RealTimeClock.OnUpdateLocalTimeSlot()' */
void DevelopmentDEV_RealTimeClock_OnUpdateLocalTimeSlot( DevelopmentDEV_RealTimeClock _this, 
  XObject sender )
{
  DeviceInterfaceRtcTime CurrentTime;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CurrentTime = EwCastObject( _this->OnUpdateLocalTimeEventHandler.Context, DeviceInterfaceRtcTime );

  if ( CurrentTime != 0 )
  {
    ViewsText_OnSetString( &_this->TimeText, EwConcatString( EwConcatString( EwConcatString( 
    EwConcatString( EwConcatString( EwConcatString( EwConcatString( EwConcatString( 
    EwConcatString( EwConcatString( EwNewStringInt( CurrentTime->Year, 4, 10 ), 
    EwLoadString( &_Const0008 )), EwNewStringInt( CurrentTime->Month, 2, 10 )), 
    EwLoadString( &_Const0008 )), EwNewStringInt( CurrentTime->Day, 2, 10 )), EwLoadString( 
    &_Const0009 )), EwNewStringInt( CurrentTime->Hour, 2, 10 )), EwLoadString( &_Const000A )), 
    EwNewStringInt( CurrentTime->Minute, 2, 10 )), EwLoadString( &_Const000A )), 
    EwNewStringInt( CurrentTime->Second, 2, 10 )));
  }
}

/* Variants derived from the class : 'Development::DEV_RealTimeClock' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_RealTimeClock )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_RealTimeClock )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_RealTimeClock' */
EW_DEFINE_CLASS( DevelopmentDEV_RealTimeClock, ComponentsBaseMainBG, OnUpdateLocalTimeEventHandler, 
                 OnUpdateLocalTimeEventHandler, OnUpdateLocalTimeEventHandler, OnUpdateLocalTimeEventHandler, 
                 _None, _None, "Development::DEV_RealTimeClock" )
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
  DevelopmentDEV_RealTimeClock_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
EW_END_OF_CLASS( DevelopmentDEV_RealTimeClock )

/* Initializer for the class 'Development::DEV_Bluetooth' */
void DevelopmentDEV_Bluetooth__Init( DevelopmentDEV_Bluetooth _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DevelopmentDEV_Bluetooth );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->BtSwVersionTitle, &_this->_XObject, 0 );
  ViewsText__Init( &_this->BtSwVersionText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DevelopmentDEV_Bluetooth );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->BtSwVersionTitle, _Const000B );
  ViewsText_OnSetString( &_this->BtSwVersionTitle, EwLoadString( &_Const000C ));
  CoreRectView__OnSetBounds( &_this->BtSwVersionText, _Const000D );
  ViewsText_OnSetAlignment( &_this->BtSwVersionText, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->BtSwVersionText, DeviceInterfaceSystemDeviceClass_OnGetBtSoftwareVersion( 
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )));
  CoreGroup__Add( _this, ((CoreView)&_this->BtSwVersionTitle ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BtSwVersionText ), 0 );
  ViewsText_OnSetFont( &_this->BtSwVersionTitle, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->BtSwVersionText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Development::DEV_Bluetooth' */
void DevelopmentDEV_Bluetooth__ReInit( DevelopmentDEV_Bluetooth _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->BtSwVersionTitle );
  ViewsText__ReInit( &_this->BtSwVersionText );
}

/* Finalizer method for the class 'Development::DEV_Bluetooth' */
void DevelopmentDEV_Bluetooth__Done( DevelopmentDEV_Bluetooth _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->BtSwVersionTitle );
  ViewsText__Done( &_this->BtSwVersionText );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* 'C' function for method : 'Development::DEV_Bluetooth.OnShortHomeKeyActivated()' */
void DevelopmentDEV_Bluetooth_OnShortHomeKeyActivated( DevelopmentDEV_Bluetooth _this )
{
  CoreGroup__DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* Variants derived from the class : 'Development::DEV_Bluetooth' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_Bluetooth )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_Bluetooth )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_Bluetooth' */
EW_DEFINE_CLASS( DevelopmentDEV_Bluetooth, ComponentsBaseMainBG, BtSwVersionTitle, 
                 BtSwVersionTitle, BtSwVersionTitle, BtSwVersionTitle, _None, _None, 
                 "Development::DEV_Bluetooth" )
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
  DevelopmentDEV_Bluetooth_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
EW_END_OF_CLASS( DevelopmentDEV_Bluetooth )

/* Initializer for the class 'Development::DEV_TFTBrightness' */
void DevelopmentDEV_TFTBrightness__Init( DevelopmentDEV_TFTBrightness _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( DevelopmentDEV_TFTBrightness );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->CheckerboardImage, &_this->_XObject, 0 );
  ViewsText__Init( &_this->LevelText, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->HideLevelTimer, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( DevelopmentDEV_TFTBrightness );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->CheckerboardImage, _Const0000 );
  ViewsImage_OnSetFrameNumber( &_this->CheckerboardImage, 1 );
  CoreRectView__OnSetBounds( &_this->LevelText, _Const000E );
  ViewsText_OnSetWrapText( &_this->LevelText, 1 );
  ViewsText_OnSetString( &_this->LevelText, 0 );
  _this->BrightnessLevel = -1;
  _this->BrightnessList[ 0 ] = 1;
  _this->BrightnessList[ 1 ] = 3;
  _this->BrightnessList[ 2 ] = 6;
  _this->BrightnessList[ 3 ] = 11;
  _this->BrightnessList[ 4 ] = 18;
  _this->BrightnessList[ 5 ] = 27;
  _this->BrightnessList[ 6 ] = 38;
  _this->BrightnessList[ 7 ] = 50;
  _this->BrightnessList[ 8 ] = 65;
  _this->BrightnessList[ 9 ] = 81;
  _this->BrightnessList[ 10 ] = 100;
  CoreGroup__Add( _this, ((CoreView)&_this->CheckerboardImage ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->LevelText ), 0 );
  ViewsImage_OnSetBitmap( &_this->CheckerboardImage, EwLoadResource( &ResourceDisplayTest, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->LevelText, EwLoadResource( &FontsNotoSansCjkJpMedium24pt, 
  ResourcesFont ));
  _this->HideLevelTimer.OnTrigger = EwNewSlot( _this, DevelopmentDEV_TFTBrightness_OnHideLevelSlot );

  /* Call the user defined constructor */
  DevelopmentDEV_TFTBrightness_Init( _this, aArg );
}

/* Re-Initializer for the class 'Development::DEV_TFTBrightness' */
void DevelopmentDEV_TFTBrightness__ReInit( DevelopmentDEV_TFTBrightness _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->CheckerboardImage );
  ViewsText__ReInit( &_this->LevelText );
  CoreTimer__ReInit( &_this->HideLevelTimer );
}

/* Finalizer method for the class 'Development::DEV_TFTBrightness' */
void DevelopmentDEV_TFTBrightness__Done( DevelopmentDEV_TFTBrightness _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->CheckerboardImage );
  ViewsText__Done( &_this->LevelText );
  CoreTimer__Done( &_this->HideLevelTimer );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void DevelopmentDEV_TFTBrightness_Init( DevelopmentDEV_TFTBrightness _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  DevelopmentDEV_TFTBrightness_OnSetBrightnessLevel( _this, EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass )->BrightnessLevel );
}

/* The method UpdateViewState() is invoked automatically after the state of the 
   component has been changed. This method can be overridden and filled with logic 
   to ensure the visual aspect of the component does reflect its current state. 
   For example, the 'enabled' state of the component can affect its colors (disabled 
   components may appear pale). In this case the logic of the method should modify 
   the respective color properties accordingly to the current 'enabled' state. 
   The current state of the component is passed as a set in the parameter aState. 
   It reflects the very basic component state like its visibility or the ability 
   to react to user inputs. Beside this common state, the method can also involve 
   any other variables used in the component as long as they reflect its current 
   state. For example, the toggle switch component can take in account its toggle 
   state 'on' or 'off' and change accordingly the location of the slider, etc.
   Usually, this method will be invoked automatically by the framework. Optionally 
   you can request its invocation by using the method @InvalidateViewState(). */
void DevelopmentDEV_TFTBrightness_UpdateViewState( DevelopmentDEV_TFTBrightness _this, 
  XSet aState )
{
  ApplicationApplication App;

  CoreGroup_UpdateViewState((CoreGroup)_this, aState );
  EwTrace( "%s%t", EwLoadString( &_Const000F ), aState );
  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );
  EwTrace( "%s%*", EwLoadString( &_Const0010 ), App );

  if ( App != 0 )
  {
    if ((( aState & CoreViewStateDialog ) == CoreViewStateDialog ))
    {
      ApplicationApplication_OnSetStatusBarVisible( App, 0 );
    }
    else
    {
      ApplicationApplication_OnSetStatusBarVisible( App, 1 );
    }
  }
}

/* 'C' function for method : 'Development::DEV_TFTBrightness.OnShortDownKeyActivated()' */
void DevelopmentDEV_TFTBrightness_OnShortDownKeyActivated( DevelopmentDEV_TFTBrightness _this )
{
  XInt32 NextBrightnessLevel = _this->BrightnessLevel - 1;

  if ( 0 <= NextBrightnessLevel )
  {
    DevelopmentDEV_TFTBrightness_OnSetBrightnessLevel( _this, NextBrightnessLevel );
  }
  else
  {
    DevelopmentDEV_TFTBrightness_ShowLevelText( _this );
  }
}

/* 'C' function for method : 'Development::DEV_TFTBrightness.OnShortUpKeyActivated()' */
void DevelopmentDEV_TFTBrightness_OnShortUpKeyActivated( DevelopmentDEV_TFTBrightness _this )
{
  XInt32 NextBrightnessLevel = _this->BrightnessLevel + 1;

  if ( 11 > NextBrightnessLevel )
  {
    DevelopmentDEV_TFTBrightness_OnSetBrightnessLevel( _this, NextBrightnessLevel );
  }
  else
  {
    DevelopmentDEV_TFTBrightness_ShowLevelText( _this );
  }
}

/* 'C' function for method : 'Development::DEV_TFTBrightness.OnShortHomeKeyActivated()' */
void DevelopmentDEV_TFTBrightness_OnShortHomeKeyActivated( DevelopmentDEV_TFTBrightness _this )
{
  CoreGroup__DismissDialog( _this->Super6.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Development::DEV_TFTBrightness.OnSetBrightnessLevel()' */
void DevelopmentDEV_TFTBrightness_OnSetBrightnessLevel( DevelopmentDEV_TFTBrightness _this, 
  XInt32 value )
{
  if ( _this->BrightnessLevel != value )
  {
    _this->BrightnessLevel = value;
    ViewsText_OnSetString( &_this->LevelText, EwNewStringInt( _this->BrightnessLevel, 
    0, 10 ));
    DevelopmentDEV_TFTBrightness_ShowLevelText( _this );

    if ( EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->BrightnessLevel 
        != value )
    {
      EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->BrightnessLevel 
      = value;
    }

    DeviceInterfaceSystemDeviceClass_SetBrightness( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
    DeviceInterfaceSystemDeviceClass ), _this->BrightnessList[ EwCheckIndex( _this->BrightnessLevel, 
    11 )]);
  }
}

/* 'C' function for method : 'Development::DEV_TFTBrightness.OnHideLevelSlot()' */
void DevelopmentDEV_TFTBrightness_OnHideLevelSlot( DevelopmentDEV_TFTBrightness _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreTimer_OnSetEnabled( &_this->HideLevelTimer, 0 );
  ViewsText_OnSetVisible( &_this->LevelText, 0 );
}

/* 'C' function for method : 'Development::DEV_TFTBrightness.ShowLevelText()' */
void DevelopmentDEV_TFTBrightness_ShowLevelText( DevelopmentDEV_TFTBrightness _this )
{
  ViewsText_OnSetVisible( &_this->LevelText, 1 );
  CoreTimer_OnSetEnabled( &_this->HideLevelTimer, 1 );
}

/* Variants derived from the class : 'Development::DEV_TFTBrightness' */
EW_DEFINE_CLASS_VARIANTS( DevelopmentDEV_TFTBrightness )
EW_END_OF_CLASS_VARIANTS( DevelopmentDEV_TFTBrightness )

/* Virtual Method Table (VMT) for the class : 'Development::DEV_TFTBrightness' */
EW_DEFINE_CLASS( DevelopmentDEV_TFTBrightness, MenuBaseMenuView, CheckerboardImage, 
                 CheckerboardImage, CheckerboardImage, CheckerboardImage, BrightnessLevel, 
                 BrightnessLevel, "Development::DEV_TFTBrightness" )
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
  DevelopmentDEV_TFTBrightness_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  DevelopmentDEV_TFTBrightness_OnShortDownKeyActivated,
  DevelopmentDEV_TFTBrightness_OnShortUpKeyActivated,
  ComponentsBaseComponent_OnShortEnterKeyActivated,
  DevelopmentDEV_TFTBrightness_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  MenuBaseMenuView_LoadItemClass,
  MenuBaseMenuView_LoadItemTitle,
  MenuBaseMenuView_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
EW_END_OF_CLASS( DevelopmentDEV_TFTBrightness )

/* Embedded Wizard */
