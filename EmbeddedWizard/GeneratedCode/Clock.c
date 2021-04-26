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
#include "_ClockCLK01_ClockSettingMenu.h"
#include "_ClockCLK02_ClockManualAdjustment.h"
#include "_ClockCLK03_SetClock.h"
#include "_ClockTimePicker.h"
#include "_ComponentsBaseMainBG.h"
#include "_CoreGroup.h"
#include "_CoreView.h"
#include "_DeviceInterfaceBluetoothDeviceClass.h"
#include "_DeviceInterfaceRtcTime.h"
#include "_DeviceInterfaceSystemDeviceClass.h"
#include "_EffectSlideTransitionNoFade.h"
#include "_EffectsTransition.h"
#include "_MenuItemBase.h"
#include "_MenuItemCheckbox.h"
#include "_MenuUpDownPushButtonSet.h"
#include "_MenuVerticalMenu.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsBorder.h"
#include "_ViewsImage.h"
#include "_ViewsText.h"
#include "Clock.h"
#include "DeviceInterface.h"
#include "Effect.h"
#include "Enum.h"
#include "Fonts.h"
#include "Resource.h"
#include "Strings.h"
#include "Views.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x0000002E, /* ratio 104.35 % */
  0xB8001B00, 0x00092452, 0x00D20037, 0x040003A0, 0x98002180, 0x00025800, 0x00188006,
  0x58181232, 0x004645E4, 0xF8EA091B, 0x00203248, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 92, 100 }};
static const XRect _Const0001 = {{ 17, 0 }, { 75, 100 }};
static const XRect _Const0002 = {{ 0, 22 }, { 92, 78 }};
static const XColor _Const0003 = { 0x33, 0x33, 0x33, 0xFF };
static const XRect _Const0004 = {{ 9, 22 }, { 47, 78 }};
static const XRect _Const0005 = {{ 0, 22 }, { 56, 78 }};
static const XRect _Const0006 = {{ 0, 0 }, { 58, 100 }};
static const XRect _Const0007 = {{ 22, 67 }, { 458, 99 }};
static const XRect _Const0008 = {{ 23, 100 }, { 115, 200 }};
static const XRect _Const0009 = {{ 126, 100 }, { 182, 200 }};
static const XRect _Const000A = {{ 193, 100 }, { 249, 200 }};
static const XRect _Const000B = {{ 267, 100 }, { 323, 200 }};
static const XRect _Const000C = {{ 334, 100 }, { 390, 200 }};
static const XRect _Const000D = {{ 401, 100 }, { 457, 200 }};
static const XRect _Const000E = {{ 390, 135 }, { 401, 163 }};
static const XRect _Const000F = {{ 23, 122 }, { 115, 178 }};
static const XColor _Const0010 = { 0x00, 0x72, 0xFF, 0xFF };
static const XRect _Const0011 = {{ 126, 122 }, { 182, 178 }};
static const XStringRes _Const0012 = { _StringsDefault0, 0x0002 };
static const XRect _Const0013 = {{ 16, 60 }, { 465, 91 }};
static const XRect _Const0014 = {{ 69, 111 }, { 107, 145 }};
static const XRect _Const0015 = {{ 120, 111 }, { 158, 145 }};
static const XRect _Const0016 = {{ 109, 114 }, { 120, 142 }};
static const XStringRes _Const0017 = { _StringsDefault0, 0x000F };
static const XRect _Const0018 = {{ 160, 114 }, { 171, 142 }};
static const XRect _Const0019 = {{ 171, 111 }, { 245, 145 }};
static const XRect _Const001A = {{ 267, 111 }, { 318, 145 }};
static const XRect _Const001B = {{ 321, 111 }, { 359, 145 }};
static const XRect _Const001C = {{ 372, 111 }, { 410, 145 }};
static const XRect _Const001D = {{ 360, 112 }, { 371, 140 }};
static const XStringRes _Const001E = { _StringsDefault0, 0x0013 };
static const XRect _Const001F = {{ 165, 176 }, { 315, 259 }};

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

/* Initializer for the class 'Clock::TimePicker' */
void ClockTimePicker__Init( ClockTimePicker _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( ClockTimePicker );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->TimePickerButtons, &_this->_XObject, 0 );
  ViewsBorder__Init( &_this->BackgroundFrame, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TimeText, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ClockTimePicker );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->TimePickerButtons, _Const0001 );
  ViewsImage_OnSetVisible( &_this->TimePickerButtons, 0 );
  CoreRectView__OnSetBounds( &_this->BackgroundFrame, _Const0002 );
  ViewsBorder_OnSetColor( &_this->BackgroundFrame, _Const0003 );
  CoreRectView__OnSetBounds( &_this->TimeText, _Const0002 );
  ViewsText_OnSetAlignment( &_this->TimeText, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->TimeText, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimePickerButtons ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->BackgroundFrame ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeText ), 0 );
  ViewsImage_OnSetBitmap( &_this->TimePickerButtons, EwLoadResource( &ResourceClockArrow, 
  ResourcesBitmap ));
  ViewsText_OnSetFont( &_this->TimeText, EwLoadResource( &FontsNotoSansMedium32pt, 
  ResourcesFont ));
}

/* Re-Initializer for the class 'Clock::TimePicker' */
void ClockTimePicker__ReInit( ClockTimePicker _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->TimePickerButtons );
  ViewsBorder__ReInit( &_this->BackgroundFrame );
  ViewsText__ReInit( &_this->TimeText );
}

/* Finalizer method for the class 'Clock::TimePicker' */
void ClockTimePicker__Done( ClockTimePicker _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->TimePickerButtons );
  ViewsBorder__Done( &_this->BackgroundFrame );
  ViewsText__Done( &_this->TimeText );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_Super );
}

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void ClockTimePicker_UpdateLayout( ClockTimePicker _this, XPoint aSize )
{
  CoreGroup_UpdateLayout((CoreGroup)_this, aSize );

  switch ( _this->Width )
  {
    case 92 :
    {
      CoreRectView__OnSetBounds( &_this->TimeText, _Const0002 );
      CoreRectView__OnSetBounds( &_this->BackgroundFrame, _Const0002 );
    }
    break;

    case 56 :
    {
      switch ( _this->TimePickerType )
      {
        case EnumTimeTypeMONTH :
        case EnumTimeTypeDAY :
        case EnumTimeTypeHOUR :
        case EnumTimeTypeMINUTE :
          CoreRectView__OnSetBounds( &_this->TimeText, _Const0004 );
        break;

        case EnumTimeTypeFORMAT :
          CoreRectView__OnSetBounds( &_this->TimeText, _Const0005 );
        break;

        default : 
          ;
      }

      CoreRectView__OnSetBounds( &_this->BackgroundFrame, _Const0005 );
      CoreRectView__OnSetBounds( &_this->TimePickerButtons, _Const0006 );
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Clock::TimePicker.OnSetTime()' */
void ClockTimePicker_OnSetTime( ClockTimePicker _this, XInt32 value )
{
  _this->Time = value;
  ViewsText_OnSetString( &_this->TimeText, EwNewStringInt( _this->Time, 0, 10 ));
}

/* 'C' function for method : 'Clock::TimePicker.OnSetArrowVisibility()' */
void ClockTimePicker_OnSetArrowVisibility( ClockTimePicker _this, XBool value )
{
  if ( _this->ArrowVisibility != value )
  {
    _this->ArrowVisibility = value;
    ViewsImage_OnSetVisible( &_this->TimePickerButtons, _this->ArrowVisibility );
  }
}

/* Variants derived from the class : 'Clock::TimePicker' */
EW_DEFINE_CLASS_VARIANTS( ClockTimePicker )
EW_END_OF_CLASS_VARIANTS( ClockTimePicker )

/* Virtual Method Table (VMT) for the class : 'Clock::TimePicker' */
EW_DEFINE_CLASS( ClockTimePicker, CoreGroup, TimePickerButtons, TimePickerButtons, 
                 TimePickerButtons, TimePickerButtons, Width, Width, "Clock::TimePicker" )
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
  ClockTimePicker_UpdateLayout,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
EW_END_OF_CLASS( ClockTimePicker )

/* Initializer for the class 'Clock::CLK02_ClockManualAdjustment' */
void ClockCLK02_ClockManualAdjustment__Init( ClockCLK02_ClockManualAdjustment _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( ClockCLK02_ClockManualAdjustment );

  /* ... then construct all embedded objects */
  ViewsImage__Init( &_this->DayTimeText, &_this->_XObject, 0 );
  ClockTimePicker__Init( &_this->YearTimePicker, &_this->_XObject, 0 );
  ClockTimePicker__Init( &_this->MonthTimePicker, &_this->_XObject, 0 );
  ClockTimePicker__Init( &_this->DayTimePicker, &_this->_XObject, 0 );
  ClockTimePicker__Init( &_this->TimeFormatPicker, &_this->_XObject, 0 );
  ClockTimePicker__Init( &_this->HourPicker, &_this->_XObject, 0 );
  ClockTimePicker__Init( &_this->MinutePicker, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ColonMark, &_this->_XObject, 0 );
  ViewsBorder__Init( &_this->FocusFrame, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ClockCLK02_ClockManualAdjustment );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super1.SlideOutEffectEnabled = 1;
  CoreRectView__OnSetBounds( &_this->DayTimeText, _Const0007 );
  CoreRectView__OnSetBounds( &_this->YearTimePicker, _Const0008 );
  _this->YearTimePicker.Width = 92;
  _this->YearTimePicker.TimePickerType = EnumTimeTypeYEAR;
  CoreRectView__OnSetBounds( &_this->MonthTimePicker, _Const0009 );
  _this->MonthTimePicker.Width = 56;
  _this->MonthTimePicker.TimePickerType = EnumTimeTypeMONTH;
  CoreRectView__OnSetBounds( &_this->DayTimePicker, _Const000A );
  _this->DayTimePicker.Width = 56;
  _this->DayTimePicker.TimePickerType = EnumTimeTypeDAY;
  CoreRectView__OnSetBounds( &_this->TimeFormatPicker, _Const000B );
  _this->TimeFormatPicker.Width = 56;
  _this->TimeFormatPicker.TimePickerType = EnumTimeTypeFORMAT;
  CoreRectView__OnSetBounds( &_this->HourPicker, _Const000C );
  _this->HourPicker.Width = 56;
  _this->HourPicker.TimePickerType = EnumTimeTypeHOUR;
  CoreRectView__OnSetBounds( &_this->MinutePicker, _Const000D );
  _this->MinutePicker.Width = 56;
  _this->MinutePicker.TimePickerType = EnumTimeTypeMINUTE;
  CoreRectView__OnSetBounds( &_this->ColonMark, _Const000E );
  CoreRectView__OnSetBounds( &_this->FocusFrame, _Const000F );
  ViewsBorder_OnSetWidth( &_this->FocusFrame, 3 );
  ViewsBorder_OnSetColor( &_this->FocusFrame, _Const0010 );
  _this->ValidDayArray[ 1 ] = 31;
  _this->ValidDayArray[ 2 ] = 28;
  _this->ValidDayArray[ 3 ] = 31;
  _this->ValidDayArray[ 4 ] = 30;
  _this->ValidDayArray[ 5 ] = 31;
  _this->ValidDayArray[ 6 ] = 30;
  _this->ValidDayArray[ 7 ] = 31;
  _this->ValidDayArray[ 8 ] = 31;
  _this->ValidDayArray[ 9 ] = 30;
  _this->ValidDayArray[ 10 ] = 31;
  _this->ValidDayArray[ 11 ] = 30;
  _this->ValidDayArray[ 12 ] = 31;
  CoreGroup__Add( _this, ((CoreView)&_this->DayTimeText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->YearTimePicker ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MonthTimePicker ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayTimePicker ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeFormatPicker ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->HourPicker ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MinutePicker ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ColonMark ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->FocusFrame ), 0 );
  ViewsImage_OnSetBitmap( &_this->DayTimeText, EwLoadResource( &ResourceClockDayTimeText, 
  ResourcesBitmap ));
  ViewsImage_OnSetBitmap( &_this->ColonMark, EwLoadResource( &ResourceClockColon, 
  ResourcesBitmap ));

  /* Call the user defined constructor */
  ClockCLK02_ClockManualAdjustment_Init( _this, aArg );
}

/* Re-Initializer for the class 'Clock::CLK02_ClockManualAdjustment' */
void ClockCLK02_ClockManualAdjustment__ReInit( ClockCLK02_ClockManualAdjustment _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsImage__ReInit( &_this->DayTimeText );
  ClockTimePicker__ReInit( &_this->YearTimePicker );
  ClockTimePicker__ReInit( &_this->MonthTimePicker );
  ClockTimePicker__ReInit( &_this->DayTimePicker );
  ClockTimePicker__ReInit( &_this->TimeFormatPicker );
  ClockTimePicker__ReInit( &_this->HourPicker );
  ClockTimePicker__ReInit( &_this->MinutePicker );
  ViewsImage__ReInit( &_this->ColonMark );
  ViewsBorder__ReInit( &_this->FocusFrame );
}

/* Finalizer method for the class 'Clock::CLK02_ClockManualAdjustment' */
void ClockCLK02_ClockManualAdjustment__Done( ClockCLK02_ClockManualAdjustment _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsImage__Done( &_this->DayTimeText );
  ClockTimePicker__Done( &_this->YearTimePicker );
  ClockTimePicker__Done( &_this->MonthTimePicker );
  ClockTimePicker__Done( &_this->DayTimePicker );
  ClockTimePicker__Done( &_this->TimeFormatPicker );
  ClockTimePicker__Done( &_this->HourPicker );
  ClockTimePicker__Done( &_this->MinutePicker );
  ViewsImage__Done( &_this->ColonMark );
  ViewsBorder__Done( &_this->FocusFrame );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ClockCLK02_ClockManualAdjustment_Init( ClockCLK02_ClockManualAdjustment _this, 
  XHandle aArg )
{
  DeviceInterfaceRtcTime CurrentTime;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  CurrentTime = DeviceInterfaceSystemDeviceClass_GetLocalTime( EwGetAutoObject( 
  &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ));
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->CurrentAdjustTime 
  = EwNewObject( DeviceInterfaceRtcTime, 0 );
  _this->SetClockComponent = EwNewObject( ClockCLK03_SetClock, 0 );
  _this->SetClockComponent->OnTimeUpdateSignal = EwNewSlot( _this, ClockCLK02_ClockManualAdjustment_OnTimeUpdateSlot );
  _this->SetClockComponent->OnTimeCancelSignal = EwNewSlot( _this, ClockCLK02_ClockManualAdjustment_OnTimeCancelSlot );
  ClockTimePicker_OnSetTime( &_this->YearTimePicker, CurrentTime->Year );
  ClockTimePicker_OnSetTime( &_this->MonthTimePicker, CurrentTime->Month );
  ViewsText_OnSetAlignment( &_this->MonthTimePicker.TimeText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ClockTimePicker_OnSetTime( &_this->DayTimePicker, CurrentTime->Day );
  ViewsText_OnSetAlignment( &_this->DayTimePicker.TimeText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );

  if ( CurrentTime->Hour < 12 )
  {
    if ( CurrentTime->Hour == 0 )
    {
      ClockTimePicker_OnSetTime( &_this->HourPicker, 12 );
    }
    else
    {
      ClockTimePicker_OnSetTime( &_this->HourPicker, CurrentTime->Hour );
    }

    ViewsText_OnSetString( &_this->TimeFormatPicker.TimeText, EwLoadString( &StringsCLK02_AM ));
  }
  else
    if ( CurrentTime->Hour >= 12 )
    {
      if ( CurrentTime->Hour == 12 )
      {
        ClockTimePicker_OnSetTime( &_this->HourPicker, 12 );
      }
      else
      {
        ClockTimePicker_OnSetTime( &_this->HourPicker, CurrentTime->Hour - 12 );
      }

      ViewsText_OnSetString( &_this->TimeFormatPicker.TimeText, EwLoadString( &StringsCLK02_PM ));
    }

  ViewsText_OnSetAlignment( &_this->HourPicker.TimeText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ClockTimePicker_OnSetTime( &_this->MinutePicker, CurrentTime->Minute );

  if ( _this->MinutePicker.Time < 10 )
  {
    ViewsText_OnSetString( &_this->MinutePicker.TimeText, EwNewStringInt( _this->MinutePicker.Time, 
    2, 10 ));
  }
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
void ClockCLK02_ClockManualAdjustment_UpdateViewState( ClockCLK02_ClockManualAdjustment _this, 
  XSet aState )
{
  CoreGroup_UpdateViewState((CoreGroup)_this, aState );
  ClockTimePicker_OnSetArrowVisibility( &_this->YearTimePicker, 1 );
}

/* 'C' function for method : 'Clock::CLK02_ClockManualAdjustment.OnShortDownKeyActivated()' */
void ClockCLK02_ClockManualAdjustment_OnShortDownKeyActivated( ClockCLK02_ClockManualAdjustment _this )
{
  ClockCLK02_ClockManualAdjustment_DecreaseCurrentTime( _this );
}

/* 'C' function for method : 'Clock::CLK02_ClockManualAdjustment.OnShortUpKeyActivated()' */
void ClockCLK02_ClockManualAdjustment_OnShortUpKeyActivated( ClockCLK02_ClockManualAdjustment _this )
{
  ClockCLK02_ClockManualAdjustment_IncreaseCurrentTime( _this );
}

/* 'C' function for method : 'Clock::CLK02_ClockManualAdjustment.OnShortEnterKeyActivated()' */
void ClockCLK02_ClockManualAdjustment_OnShortEnterKeyActivated( ClockCLK02_ClockManualAdjustment _this )
{
  if ( _this->TimePickerIdx < 5 )
  {
    ClockCLK02_ClockManualAdjustment_MoveFocusFrame( _this );
    _this->TimePickerIdx++;
  }
  else
    if ( _this->TimePickerIdx == 5 )
    {
      ClockTimePicker_OnSetArrowVisibility( &_this->MinutePicker, 0 );
      _this->TimePickerIdx = 0;
      ClockCLK03_SetClock_SetTime( _this->SetClockComponent, (XUInt16)_this->YearTimePicker.Time, 
      (XUInt8)_this->MonthTimePicker.Time, (XUInt8)_this->DayTimePicker.Time, _this->TimeFormatPicker.TimeText.String, 
      (XUInt8)_this->HourPicker.Time, (XUInt8)_this->MinutePicker.Time );
      CoreRectView__OnSetBounds( &_this->FocusFrame, ClockFOCUSFRAME_ORI_POS );
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)_this->SetClockComponent ), 
      0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
    else
      ;
}

/* 'C' function for method : 'Clock::CLK02_ClockManualAdjustment.MoveFocusFrame()' */
void ClockCLK02_ClockManualAdjustment_MoveFocusFrame( ClockCLK02_ClockManualAdjustment _this )
{
  XEnum CurrentTimeType = (XEnum)_this->TimePickerIdx;

  switch ( CurrentTimeType )
  {
    case EnumTimeTypeYEAR :
    {
      CoreRectView__OnSetBounds( &_this->FocusFrame, _Const0011 );
      ClockTimePicker_OnSetArrowVisibility( &_this->YearTimePicker, 0 );
      ClockTimePicker_OnSetArrowVisibility( &_this->MonthTimePicker, 1 );
    }
    break;

    case EnumTimeTypeMONTH :
    {
      CoreRectView__OnSetBounds( &_this->FocusFrame, EwSetRectX1( _this->FocusFrame.Super1.Bounds, 
      _this->FocusFrame.Super1.Bounds.Point1.X + 67 ));
      CoreRectView__OnSetBounds( &_this->FocusFrame, EwSetRectX2( _this->FocusFrame.Super1.Bounds, 
      _this->FocusFrame.Super1.Bounds.Point2.X + 67 ));
      ClockTimePicker_OnSetArrowVisibility( &_this->MonthTimePicker, 0 );
      ClockTimePicker_OnSetArrowVisibility( &_this->DayTimePicker, 1 );
    }
    break;

    case EnumTimeTypeDAY :
    {
      CoreRectView__OnSetBounds( &_this->FocusFrame, EwSetRectX1( _this->FocusFrame.Super1.Bounds, 
      _this->FocusFrame.Super1.Bounds.Point1.X + 74 ));
      CoreRectView__OnSetBounds( &_this->FocusFrame, EwSetRectX2( _this->FocusFrame.Super1.Bounds, 
      _this->FocusFrame.Super1.Bounds.Point2.X + 74 ));
      ClockTimePicker_OnSetArrowVisibility( &_this->DayTimePicker, 0 );
      ClockTimePicker_OnSetArrowVisibility( &_this->TimeFormatPicker, 1 );
    }
    break;

    case EnumTimeTypeFORMAT :
    {
      CoreRectView__OnSetBounds( &_this->FocusFrame, EwSetRectX1( _this->FocusFrame.Super1.Bounds, 
      _this->FocusFrame.Super1.Bounds.Point1.X + 67 ));
      CoreRectView__OnSetBounds( &_this->FocusFrame, EwSetRectX2( _this->FocusFrame.Super1.Bounds, 
      _this->FocusFrame.Super1.Bounds.Point2.X + 67 ));
      ClockTimePicker_OnSetArrowVisibility( &_this->TimeFormatPicker, 0 );
      ClockTimePicker_OnSetArrowVisibility( &_this->HourPicker, 1 );
    }
    break;

    case EnumTimeTypeHOUR :
    {
      CoreRectView__OnSetBounds( &_this->FocusFrame, EwSetRectX1( _this->FocusFrame.Super1.Bounds, 
      _this->FocusFrame.Super1.Bounds.Point1.X + 67 ));
      CoreRectView__OnSetBounds( &_this->FocusFrame, EwSetRectX2( _this->FocusFrame.Super1.Bounds, 
      _this->FocusFrame.Super1.Bounds.Point2.X + 67 ));
      ClockTimePicker_OnSetArrowVisibility( &_this->HourPicker, 0 );
      ClockTimePicker_OnSetArrowVisibility( &_this->MinutePicker, 1 );
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Clock::CLK02_ClockManualAdjustment.IncreaseCurrentTime()' */
void ClockCLK02_ClockManualAdjustment_IncreaseCurrentTime( ClockCLK02_ClockManualAdjustment _this )
{
  XEnum CurrentTimeType = (XEnum)_this->TimePickerIdx;

  switch ( CurrentTimeType )
  {
    case EnumTimeTypeYEAR :
    {
      if ( _this->YearTimePicker.Time < 2099 )
      {
        ClockTimePicker_OnSetTime( &_this->YearTimePicker, _this->YearTimePicker.Time 
        + 1 );
      }
      else
      {
        ClockTimePicker_OnSetTime( &_this->YearTimePicker, 2018 );
      }
    }
    break;

    case EnumTimeTypeMONTH :
    {
      if ( _this->MonthTimePicker.Time < 12 )
      {
        ClockTimePicker_OnSetTime( &_this->MonthTimePicker, _this->MonthTimePicker.Time 
        + 1 );
      }
      else
      {
        ClockTimePicker_OnSetTime( &_this->MonthTimePicker, 1 );
      }

      ClockCLK02_ClockManualAdjustment_SetValidDay( _this );
    }
    break;

    case EnumTimeTypeDAY :
    {
      if ( _this->DayTimePicker.Time < ClockCLK02_ClockManualAdjustment_GetMaxDayOfMonth( 
          _this ))
      {
        ClockTimePicker_OnSetTime( &_this->DayTimePicker, _this->DayTimePicker.Time 
        + 1 );
      }
      else
      {
        ClockTimePicker_OnSetTime( &_this->DayTimePicker, 1 );
      }
    }
    break;

    case EnumTimeTypeFORMAT :
    {
      if ( !EwCompString( EwLoadString( &StringsCLK02_AM ), _this->TimeFormatPicker.TimeText.String ))
      {
        ViewsText_OnSetString( &_this->TimeFormatPicker.TimeText, EwLoadString( 
        &StringsCLK02_PM ));
      }
      else
      {
        ViewsText_OnSetString( &_this->TimeFormatPicker.TimeText, EwLoadString( 
        &StringsCLK02_AM ));
      }
    }
    break;

    case EnumTimeTypeHOUR :
    {
      if ( _this->HourPicker.Time < 12 )
      {
        ClockTimePicker_OnSetTime( &_this->HourPicker, _this->HourPicker.Time + 
        1 );
      }
      else
      {
        ClockTimePicker_OnSetTime( &_this->HourPicker, 1 );
      }
    }
    break;

    case EnumTimeTypeMINUTE :
    {
      if ( _this->MinutePicker.Time < 59 )
      {
        ClockTimePicker_OnSetTime( &_this->MinutePicker, _this->MinutePicker.Time 
        + 1 );
      }
      else
      {
        ClockTimePicker_OnSetTime( &_this->MinutePicker, 0 );
      }

      if ( _this->MinutePicker.Time < 10 )
      {
        ViewsText_OnSetString( &_this->MinutePicker.TimeText, EwNewStringInt( _this->MinutePicker.Time, 
        2, 10 ));
      }
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Clock::CLK02_ClockManualAdjustment.DecreaseCurrentTime()' */
void ClockCLK02_ClockManualAdjustment_DecreaseCurrentTime( ClockCLK02_ClockManualAdjustment _this )
{
  XEnum CurrentTimeType = (XEnum)_this->TimePickerIdx;

  switch ( CurrentTimeType )
  {
    case EnumTimeTypeYEAR :
    {
      if ( _this->YearTimePicker.Time > 2018 )
      {
        ClockTimePicker_OnSetTime( &_this->YearTimePicker, _this->YearTimePicker.Time 
        - 1 );
      }
      else
      {
        ClockTimePicker_OnSetTime( &_this->YearTimePicker, 2099 );
      }
    }
    break;

    case EnumTimeTypeMONTH :
    {
      if ( _this->MonthTimePicker.Time > 1 )
      {
        ClockTimePicker_OnSetTime( &_this->MonthTimePicker, _this->MonthTimePicker.Time 
        - 1 );
      }
      else
      {
        ClockTimePicker_OnSetTime( &_this->MonthTimePicker, 12 );
      }

      ClockCLK02_ClockManualAdjustment_SetValidDay( _this );
    }
    break;

    case EnumTimeTypeDAY :
    {
      if ( _this->DayTimePicker.Time > 1 )
      {
        ClockTimePicker_OnSetTime( &_this->DayTimePicker, _this->DayTimePicker.Time 
        - 1 );
      }
      else
      {
        ClockTimePicker_OnSetTime( &_this->DayTimePicker, ClockCLK02_ClockManualAdjustment_GetMaxDayOfMonth( 
        _this ));
      }
    }
    break;

    case EnumTimeTypeFORMAT :
    {
      if ( !EwCompString( EwLoadString( &StringsCLK02_AM ), _this->TimeFormatPicker.TimeText.String ))
      {
        ViewsText_OnSetString( &_this->TimeFormatPicker.TimeText, EwLoadString( 
        &StringsCLK02_PM ));
      }
      else
      {
        ViewsText_OnSetString( &_this->TimeFormatPicker.TimeText, EwLoadString( 
        &StringsCLK02_AM ));
      }
    }
    break;

    case EnumTimeTypeHOUR :
    {
      if ( _this->HourPicker.Time > 1 )
      {
        ClockTimePicker_OnSetTime( &_this->HourPicker, _this->HourPicker.Time - 
        1 );
      }
      else
      {
        ClockTimePicker_OnSetTime( &_this->HourPicker, 12 );
      }
    }
    break;

    case EnumTimeTypeMINUTE :
    {
      if ( _this->MinutePicker.Time > 0 )
      {
        ClockTimePicker_OnSetTime( &_this->MinutePicker, _this->MinutePicker.Time 
        - 1 );
      }
      else
      {
        ClockTimePicker_OnSetTime( &_this->MinutePicker, 59 );
      }

      if ( _this->MinutePicker.Time < 10 )
      {
        ViewsText_OnSetString( &_this->MinutePicker.TimeText, EwNewStringInt( _this->MinutePicker.Time, 
        2, 10 ));
      }
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Clock::CLK02_ClockManualAdjustment.IsLeapYear()' */
XBool ClockCLK02_ClockManualAdjustment_IsLeapYear( ClockCLK02_ClockManualAdjustment _this )
{
  return (XBool)(((( _this->YearTimePicker.Time % 4 ) == 0 ) && (( _this->YearTimePicker.Time 
    % 100 ) != 0 )) || (( _this->YearTimePicker.Time % 400 ) == 0 ));
}

/* 'C' function for method : 'Clock::CLK02_ClockManualAdjustment.GetMaxDayOfMonth()' */
XInt32 ClockCLK02_ClockManualAdjustment_GetMaxDayOfMonth( ClockCLK02_ClockManualAdjustment _this )
{
  XInt32 maxday = 0;

  if ( _this->MonthTimePicker.Time != 0 )
  {
    maxday = _this->ValidDayArray[ EwCheckIndex( _this->MonthTimePicker.Time, 13 )];

    if (( _this->MonthTimePicker.Time == 2 ) && ClockCLK02_ClockManualAdjustment_IsLeapYear( 
        _this ))
    {
      maxday = 29;
    }
  }

  return maxday;
}

/* 'C' function for method : 'Clock::CLK02_ClockManualAdjustment.OnTimeUpdateSlot()' */
void ClockCLK02_ClockManualAdjustment_OnTimeUpdateSlot( ClockCLK02_ClockManualAdjustment _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwSignal( _this->OnRestoreFocusFrameSignal, ((XObject)_this ));
  CoreGroup_DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), ((EffectsTransition)EwGetAutoObject( 
  &EffectNoSlideOut, EffectSlideTransitionNoFade )), 0, 0, EwNullSlot, EwNullSlot, 
  0 );
}

/* 'C' function for method : 'Clock::CLK02_ClockManualAdjustment.OnTimeCancelSlot()' */
void ClockCLK02_ClockManualAdjustment_OnTimeCancelSlot( ClockCLK02_ClockManualAdjustment _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'Clock::CLK02_ClockManualAdjustment.SetValidDay()' */
void ClockCLK02_ClockManualAdjustment_SetValidDay( ClockCLK02_ClockManualAdjustment _this )
{
  if ((( _this->MonthTimePicker.Time != 0 ) && ( _this->DayTimePicker.Time > _this->ValidDayArray[ 
      EwCheckIndex( _this->MonthTimePicker.Time, 13 )])) || ( _this->DayTimePicker.Time 
      == 0 ))
  {
    ClockTimePicker_OnSetTime( &_this->DayTimePicker, _this->ValidDayArray[ EwCheckIndex( 
    _this->MonthTimePicker.Time, 13 )]);

    if (( _this->MonthTimePicker.Time == 2 ) && ClockCLK02_ClockManualAdjustment_IsLeapYear( 
        _this ))
    {
      ClockTimePicker_OnSetTime( &_this->DayTimePicker, 29 );
    }
  }
}

/* Variants derived from the class : 'Clock::CLK02_ClockManualAdjustment' */
EW_DEFINE_CLASS_VARIANTS( ClockCLK02_ClockManualAdjustment )
EW_END_OF_CLASS_VARIANTS( ClockCLK02_ClockManualAdjustment )

/* Virtual Method Table (VMT) for the class : 'Clock::CLK02_ClockManualAdjustment' */
EW_DEFINE_CLASS( ClockCLK02_ClockManualAdjustment, ComponentsBaseMainBG, SetClockComponent, 
                 OnRestoreFocusFrameSignal, DayTimeText, DayTimeText, TimePickerIdx, 
                 TimePickerIdx, "Clock::CLK02_ClockManualAdjustment" )
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
  ClockCLK02_ClockManualAdjustment_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  ClockCLK02_ClockManualAdjustment_OnShortDownKeyActivated,
  ClockCLK02_ClockManualAdjustment_OnShortUpKeyActivated,
  ClockCLK02_ClockManualAdjustment_OnShortEnterKeyActivated,
  ComponentsBaseMainBG_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( ClockCLK02_ClockManualAdjustment )

/* Initializer for the class 'Clock::CLK01_ClockSettingMenu' */
void ClockCLK01_ClockSettingMenu__Init( ClockCLK01_ClockSettingMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( ClockCLK01_ClockSettingMenu );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ClockCLK01_ClockSettingMenu );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  _this->Super2.SlideOutEffectEnabled = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->Super1.Menu, 1 );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Super1.Menu, 2 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &StringsCLK01_AUTO_ADJUSTMENT ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &StringsCLK01_MANUAL_ADJUSTMENT ));
  _this->ItemClassArray[ 0 ] = EW_CLASS( MenuItemCheckbox );
  _this->ItemClassArray[ 1 ] = EW_CLASS( MenuItemBase );

  /* Call the user defined constructor */
  ClockCLK01_ClockSettingMenu_Init( _this, aArg );
}

/* Re-Initializer for the class 'Clock::CLK01_ClockSettingMenu' */
void ClockCLK01_ClockSettingMenu__ReInit( ClockCLK01_ClockSettingMenu _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Clock::CLK01_ClockSettingMenu' */
void ClockCLK01_ClockSettingMenu__Done( ClockCLK01_ClockSettingMenu _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ClockCLK01_ClockSettingMenu_Init( ClockCLK01_ClockSettingMenu _this, XHandle 
  aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aArg );

  EwTrace( "%s", EwLoadString( &_Const0012 ));
}

/* 'C' function for method : 'Clock::CLK01_ClockSettingMenu.LoadItemClass()' */
XClass ClockCLK01_ClockSettingMenu_LoadItemClass( ClockCLK01_ClockSettingMenu _this, 
  XInt32 aItemNo )
{
  XClass ClassType = 0;

  if ( aItemNo < 2 )
  {
    ClassType = _this->ItemClassArray[ EwCheckIndex( aItemNo, 2 )];
  }

  return ClassType;
}

/* 'C' function for method : 'Clock::CLK01_ClockSettingMenu.LoadItemTitle()' */
XString ClockCLK01_ClockSettingMenu_LoadItemTitle( ClockCLK01_ClockSettingMenu _this, 
  XInt32 aItemNo )
{
  XString title = 0;

  if ( aItemNo < 2 )
  {
    title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 2 )];
  }

  return title;
}

/* 'C' function for method : 'Clock::CLK01_ClockSettingMenu.OnItemActivate()' */
void ClockCLK01_ClockSettingMenu_OnItemActivate( ClockCLK01_ClockSettingMenu _this, 
  XInt32 aItemNo, MenuItemBase aMenuItem )
{
  XBool IsChecked = 0;
  MenuItemCheckbox CheckBoxItem = EwCastObject( aMenuItem, MenuItemCheckbox );

  if ( CheckBoxItem != 0 )
  {
    IsChecked = CheckBoxItem->Checked;
  }

  switch ( aItemNo )
  {
    case 0 :
    {
      DeviceInterfaceSystemDeviceClass_OnSetIsClockAutoAdj( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
      DeviceInterfaceSystemDeviceClass ), IsChecked );
      MenuVerticalMenu_InvalidateItems( &_this->Super1.Menu, 0, 1 );

      if ( IsChecked && DeviceInterfaceBluetoothDeviceClass_IsMotoconConnected( 
          EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass )))
      {
        DeviceInterfaceSystemDeviceClass_NotifyTimeRequest( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
        DeviceInterfaceSystemDeviceClass ));
      }
    }
    break;

    case 1 :
    {
      if ( !DeviceInterfaceSystemDeviceClass_OnGetIsClockAutoAdj( EwGetAutoObject( 
          &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )))
      {
        _this->ClockManualAdjComponent = EwNewObject( ClockCLK02_ClockManualAdjustment, 
        0 );
        _this->ClockManualAdjComponent->OnRestoreFocusFrameSignal = EwNewSlot( _this, 
        ClockCLK01_ClockSettingMenu_OnRestoreFocusFrameUpdateSlot );
        ComponentsBaseMainBG_SlideInDialog((ComponentsBaseMainBG)_this, ((ComponentsBaseMainBG)_this->ClockManualAdjComponent ));
      }
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Clock::CLK01_ClockSettingMenu.LoadItemChecked()' */
XBool ClockCLK01_ClockSettingMenu_LoadItemChecked( ClockCLK01_ClockSettingMenu _this, 
  XInt32 aItemNo )
{
  XBool IsChecked;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  IsChecked = 0;

  switch ( aItemNo )
  {
    case 0 :
      IsChecked = DeviceInterfaceSystemDeviceClass_OnGetIsClockAutoAdj( EwGetAutoObject( 
      &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ));
    break;

    default : 
      ;
  }

  return IsChecked;
}

/* 'C' function for method : 'Clock::CLK01_ClockSettingMenu.LoadItemEnabled()' */
XBool ClockCLK01_ClockSettingMenu_LoadItemEnabled( ClockCLK01_ClockSettingMenu _this, 
  XInt32 aItemNo )
{
  XBool ItemEnabled;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemEnabled = 1;

  if ( aItemNo > 0 )
  {
    ItemEnabled = (XBool)!DeviceInterfaceSystemDeviceClass_OnGetIsClockAutoAdj( 
    EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass ));
  }

  return ItemEnabled;
}

/* 'C' function for method : 'Clock::CLK01_ClockSettingMenu.OnRestoreFocusFrameUpdateSlot()' */
void ClockCLK01_ClockSettingMenu_OnRestoreFocusFrameUpdateSlot( ClockCLK01_ClockSettingMenu _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  MenuVerticalMenu_RestoreFocusFrame( &_this->Super1.Menu );
}

/* Variants derived from the class : 'Clock::CLK01_ClockSettingMenu' */
EW_DEFINE_CLASS_VARIANTS( ClockCLK01_ClockSettingMenu )
EW_END_OF_CLASS_VARIANTS( ClockCLK01_ClockSettingMenu )

/* Virtual Method Table (VMT) for the class : 'Clock::CLK01_ClockSettingMenu' */
EW_DEFINE_CLASS( ClockCLK01_ClockSettingMenu, MenuBaseMenuView, ClockManualAdjComponent, 
                 ItemTitleArray, ItemTitleArray, ItemTitleArray, ItemTitleArray, 
                 ItemClassArray, "Clock::CLK01_ClockSettingMenu" )
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
  MenuBaseMenuView_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
  ClockCLK01_ClockSettingMenu_LoadItemClass,
  ClockCLK01_ClockSettingMenu_LoadItemTitle,
  ClockCLK01_ClockSettingMenu_OnItemActivate,
  ClockCLK01_ClockSettingMenu_LoadItemChecked,
  ClockCLK01_ClockSettingMenu_LoadItemEnabled,
  MenuBaseMenuView_LoadItemBaseValue,
  MenuBaseMenuView_LoadItemMessage,
  MenuBaseMenuView_LoadItemReceivedTime,
  MenuBaseMenuView_LoadItemCategory,
  MenuBaseMenuView_LoadItemUid,
  MenuBaseMenuView_LoadItemToggle,
  MenuBaseMenuView_LoadItemUnit,
  MenuBaseMenuView_LoadItemValue,
  MenuBaseMenuView_OnItemLongEnterKeyActivate,
  MenuBaseMenuView_LoadItemHour,
  MenuBaseMenuView_LoadItemMinute,
EW_END_OF_CLASS( ClockCLK01_ClockSettingMenu )

/* Initializer for the class 'Clock::CLK03_SetClock' */
void ClockCLK03_SetClock__Init( ClockCLK03_SetClock _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseMainBG__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( ClockCLK03_SetClock );

  /* ... then construct all embedded objects */
  ViewsText__Init( &_this->Title, &_this->_XObject, 0 );
  ViewsText__Init( &_this->DayText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->MonthText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->SlashDay, &_this->_XObject, 0 );
  ViewsText__Init( &_this->SlashMonth, &_this->_XObject, 0 );
  ViewsText__Init( &_this->YearText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->TimeFormat, &_this->_XObject, 0 );
  ViewsText__Init( &_this->HourText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->MinuteText, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Colon, &_this->_XObject, 0 );
  MenuUpDownPushButtonSet__Init( &_this->UpDownPushButtonSet, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ClockCLK03_SetClock );

  /* ... and initialize objects, variables, properties, etc. */
  ComponentsBaseComponent__OnSetDDModeEnabled( _this, 1 );
  CoreRectView__OnSetBounds( &_this->Title, _Const0013 );
  ViewsText_OnSetString( &_this->Title, EwLoadString( &StringsCLK03_SET_CLOCK ));
  CoreRectView__OnSetBounds( &_this->DayText, _Const0014 );
  ViewsText_OnSetAlignment( &_this->DayText, ViewsTextAlignmentAlignHorzRight | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->DayText, 0 );
  CoreRectView__OnSetBounds( &_this->MonthText, _Const0015 );
  ViewsText_OnSetAlignment( &_this->MonthText, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->MonthText, 0 );
  CoreRectView__OnSetBounds( &_this->SlashDay, _Const0016 );
  ViewsText_OnSetAlignment( &_this->SlashDay, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->SlashDay, EwLoadString( &_Const0017 ));
  CoreRectView__OnSetBounds( &_this->SlashMonth, _Const0018 );
  ViewsText_OnSetAlignment( &_this->SlashMonth, ViewsTextAlignmentAlignHorzCenter 
  | ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->SlashMonth, EwLoadString( &_Const0017 ));
  CoreRectView__OnSetBounds( &_this->YearText, _Const0019 );
  ViewsText_OnSetString( &_this->YearText, 0 );
  CoreRectView__OnSetBounds( &_this->TimeFormat, _Const001A );
  ViewsText_OnSetString( &_this->TimeFormat, 0 );
  CoreRectView__OnSetBounds( &_this->HourText, _Const001B );
  ViewsText_OnSetAlignment( &_this->HourText, ViewsTextAlignmentAlignHorzRight | 
  ViewsTextAlignmentAlignVertCenter );
  ViewsText_OnSetString( &_this->HourText, 0 );
  CoreRectView__OnSetBounds( &_this->MinuteText, _Const001C );
  ViewsText_OnSetString( &_this->MinuteText, 0 );
  CoreRectView__OnSetBounds( &_this->Colon, _Const001D );
  ViewsText_OnSetString( &_this->Colon, EwLoadString( &_Const001E ));
  CoreRectView__OnSetBounds( &_this->UpDownPushButtonSet, _Const001F );
  _this->UpDownPushButtonSet.Super1.PassHomeKey = 1;
  _this->UpDownPushButtonSet.Super1.PassMagicKey = 1;
  ComponentsBaseComponent__OnSetDDModeEnabled( &_this->UpDownPushButtonSet, 1 );
  MenuUpDownPushButtonSet_OnSetUpButtonTitle( &_this->UpDownPushButtonSet, EwGetVariantOfString( 
  &StringsGEN_CANCEL ));
  MenuUpDownPushButtonSet_OnSetDownButtonTitle( &_this->UpDownPushButtonSet, EwGetVariantOfString( 
  &StringsGEN_OK ));
  MenuUpDownPushButtonSet_OnSetDownButtonEnabled( &_this->UpDownPushButtonSet, 1 );
  CoreGroup__Add( _this, ((CoreView)&_this->Title ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->DayText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MonthText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SlashDay ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->SlashMonth ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->YearText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->TimeFormat ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->HourText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->MinuteText ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->Colon ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->UpDownPushButtonSet ), 0 );
  ViewsText_OnSetFont( &_this->Title, EwLoadResource( &FontsNotoSansCjkJpMedium28pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->DayText, EwLoadResource( &FontsNotoSansMedium32pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->MonthText, EwLoadResource( &FontsNotoSansMedium32pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->SlashDay, EwLoadResource( &FontsNotoSansMedium32pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->SlashMonth, EwLoadResource( &FontsNotoSansMedium32pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->YearText, EwLoadResource( &FontsNotoSansMedium32pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->TimeFormat, EwLoadResource( &FontsNotoSansMedium32pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->HourText, EwLoadResource( &FontsNotoSansMedium32pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->MinuteText, EwLoadResource( &FontsNotoSansMedium32pt, 
  ResourcesFont ));
  ViewsText_OnSetFont( &_this->Colon, EwLoadResource( &FontsNotoSansMedium32pt, 
  ResourcesFont ));
  _this->UpDownPushButtonSet.OnUpButtonActivated = EwNewSlot( _this, ClockCLK03_SetClock_OnCancelActivatedSlot );
  _this->UpDownPushButtonSet.OnDownButtonActivated = EwNewSlot( _this, ClockCLK03_SetClock_OnOkActivatedSlot );
}

/* Re-Initializer for the class 'Clock::CLK03_SetClock' */
void ClockCLK03_SetClock__ReInit( ClockCLK03_SetClock _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseMainBG__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsText__ReInit( &_this->Title );
  ViewsText__ReInit( &_this->DayText );
  ViewsText__ReInit( &_this->MonthText );
  ViewsText__ReInit( &_this->SlashDay );
  ViewsText__ReInit( &_this->SlashMonth );
  ViewsText__ReInit( &_this->YearText );
  ViewsText__ReInit( &_this->TimeFormat );
  ViewsText__ReInit( &_this->HourText );
  ViewsText__ReInit( &_this->MinuteText );
  ViewsText__ReInit( &_this->Colon );
  MenuUpDownPushButtonSet__ReInit( &_this->UpDownPushButtonSet );
}

/* Finalizer method for the class 'Clock::CLK03_SetClock' */
void ClockCLK03_SetClock__Done( ClockCLK03_SetClock _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseMainBG );

  /* Finalize all embedded objects */
  ViewsText__Done( &_this->Title );
  ViewsText__Done( &_this->DayText );
  ViewsText__Done( &_this->MonthText );
  ViewsText__Done( &_this->SlashDay );
  ViewsText__Done( &_this->SlashMonth );
  ViewsText__Done( &_this->YearText );
  ViewsText__Done( &_this->TimeFormat );
  ViewsText__Done( &_this->HourText );
  ViewsText__Done( &_this->MinuteText );
  ViewsText__Done( &_this->Colon );
  MenuUpDownPushButtonSet__Done( &_this->UpDownPushButtonSet );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseMainBG__Done( &_this->_Super );
}

/* 'C' function for method : 'Clock::CLK03_SetClock.OnShortHomeKeyActivated()' */
void ClockCLK03_SetClock_OnShortHomeKeyActivated( ClockCLK03_SetClock _this )
{
  EwSignal( _this->OnTimeCancelSignal, ((XObject)_this ));
  CoreGroup_DismissDialog( _this->Super5.Owner, ((CoreGroup)_this ), 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* 'C' function for method : 'Clock::CLK03_SetClock.OnOkActivatedSlot()' */
void ClockCLK03_SetClock_OnOkActivatedSlot( ClockCLK03_SetClock _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  DeviceInterfaceSystemDeviceClass_SetRtcTime( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ), EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass )->CurrentAdjustTime );
  DeviceInterfaceSystemDeviceClass_SendManualAdjTimeToMeter( EwGetAutoObject( &DeviceInterfaceSystemDevice, 
  DeviceInterfaceSystemDeviceClass ));
  EwSignal( _this->OnTimeUpdateSignal, ((XObject)_this ));
}

/* 'C' function for method : 'Clock::CLK03_SetClock.OnCancelActivatedSlot()' */
void ClockCLK03_SetClock_OnCancelActivatedSlot( ClockCLK03_SetClock _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  ComponentsBaseComponent__OnShortHomeKeyActivated( _this );
}

/* 'C' function for method : 'Clock::CLK03_SetClock.SetTime()' */
void ClockCLK03_SetClock_SetTime( ClockCLK03_SetClock _this, XUInt16 aNewYear, XUInt8 
  aNewMonth, XUInt8 aNewDay, XString aNewFormat, XUInt8 aNewHour, XUInt8 aNewMinute )
{
  /* List of temporarily used variables */
  void* _tmpO0;
  ViewsText_OnSetString( &_this->YearText, EwNewStringInt( aNewYear, 0, 10 ));
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->CurrentAdjustTime->Year 
  = aNewYear;
  ViewsText_OnSetString( &_this->MonthText, EwNewStringInt( aNewMonth, 0, 10 ));
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->CurrentAdjustTime->Month 
  = aNewMonth;
  ViewsText_OnSetString( &_this->DayText, EwNewStringInt( aNewDay, 0, 10 ));
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->CurrentAdjustTime->Day 
  = aNewDay;
  ViewsText_OnSetString( &_this->TimeFormat, aNewFormat );
  ViewsText_OnSetString( &_this->HourText, EwNewStringInt( aNewHour, 0, 10 ));
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->CurrentAdjustTime->Hour 
  = aNewHour;

  if ( !EwCompString( EwLoadString( &StringsCLK02_PM ), _this->TimeFormat.String ))
  {
    if ( aNewHour < 12 )
    {
      ( _tmpO0 = EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->CurrentAdjustTime, 
      ((DeviceInterfaceRtcTime)_tmpO0)->Hour = (XUInt8)(((DeviceInterfaceRtcTime)_tmpO0)->Hour 
      + 12 ));
    }
  }
  else
  {
    if ( aNewHour == 12 )
    {
      ( _tmpO0 = EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->CurrentAdjustTime, 
      ((DeviceInterfaceRtcTime)_tmpO0)->Hour = (XUInt8)(((DeviceInterfaceRtcTime)_tmpO0)->Hour 
      - 12 ));
    }
  }

  ViewsText_OnSetString( &_this->MinuteText, EwNewStringInt( aNewMinute, 0, 10 ));
  EwGetAutoObject( &DeviceInterfaceSystemDevice, DeviceInterfaceSystemDeviceClass )->CurrentAdjustTime->Minute 
  = aNewMinute;

  if ( aNewMinute < 10 )
  {
    ViewsText_OnSetString( &_this->MinuteText, EwNewStringInt( aNewMinute, 2, 10 ));
  }
}

/* Variants derived from the class : 'Clock::CLK03_SetClock' */
EW_DEFINE_CLASS_VARIANTS( ClockCLK03_SetClock )
EW_END_OF_CLASS_VARIANTS( ClockCLK03_SetClock )

/* Virtual Method Table (VMT) for the class : 'Clock::CLK03_SetClock' */
EW_DEFINE_CLASS( ClockCLK03_SetClock, ComponentsBaseMainBG, OnTimeUpdateSignal, 
                 OnTimeUpdateSignal, Title, Title, _None, _None, "Clock::CLK03_SetClock" )
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
  ClockCLK03_SetClock_OnShortHomeKeyActivated,
  ComponentsBaseComponent_OnLongDownKeyActivated,
  ComponentsBaseComponent_OnLongUpKeyActivated,
  ComponentsBaseComponent_OnLongEnterKeyActivated,
  ComponentsBaseComponent_OnLongHomeKeyActivated,
  ComponentsBaseComponent_OnShortMagicKeyActivated,
  ComponentsBaseMainBG_OnSetDDModeEnabled,
  ComponentsBaseComponent_OnDownKeyReleased,
  ComponentsBaseComponent_OnUpKeyReleased,
EW_END_OF_CLASS( ClockCLK03_SetClock )

/* User defined constant: 'Clock::FOCUSFRAME_ORI_POS' */
const XRect ClockFOCUSFRAME_ORI_POS = {{ 23, 122 }, { 115, 178 }};

/* Embedded Wizard */
