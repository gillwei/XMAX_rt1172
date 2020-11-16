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
#include "_CoreKeyPressHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_FactoryDisplayAutoRun.h"
#include "_FactoryDisplayManual.h"
#include "_FactoryMain.h"
#include "_FactoryTestContext.h"
#include "_MenuItemBase.h"
#include "_MenuVerticalMenu.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesExternBitmap.h"
#include "_ViewsBorder.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "Core.h"
#include "Factory.h"
#include "Resource.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000076, /* ratio 81.36 % */
  0xB8002300, 0x80088452, 0x00E60034, 0x0D800380, 0xF2003080, 0xF0D23000, 0x00318020,
  0x032800D6, 0x8F800E40, 0xB4160613, 0x43A190A8, 0x00411288, 0xC9A00140, 0x006E0043,
  0x30E979D4, 0x150047C5, 0x58441A44, 0x004A22B2, 0x9106592A, 0x800E8009, 0x48014037,
  0xE6D31A21, 0x01019BCD, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 480, 272 }};
static const XColor _Const0001 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const0002 = {{ 120, 68 }, { 360, 204 }};
static const XColor _Const0003 = { 0xFF, 0x00, 0x00, 0xFF };
static const XColor _Const0004 = { 0x00, 0xFF, 0x00, 0xFF };
static const XColor _Const0005 = { 0x00, 0x00, 0xFF, 0xFF };
static const XColor _Const0006 = { 0x00, 0x00, 0x00, 0xFF };
static const XColor _Const0007 = { 0x80, 0x80, 0x80, 0xFF };
static const XStringRes _Const0008 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0009 = { _StringsDefault0, 0x0013 };
static const XStringRes _Const000A = { _StringsDefault0, 0x0026 };
static const XRect _Const000B = {{ 10, 32 }, { 470, 272 }};
static const XColor _Const000C = { 0xBA, 0xBA, 0xBA, 0xFF };
static const XColor _Const000D = { 0x40, 0x40, 0x40, 0xFF };

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

/* Initializer for the class 'Factory::DisplayAutoRun' */
void FactoryDisplayAutoRun__Init( FactoryDisplayAutoRun _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( FactoryDisplayAutoRun );

  /* ... then construct all embedded objects */
  CoreTimer__Init( &_this->TimerNextPattern, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->FullScreen, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->CenterBlock, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ImagePattern, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( FactoryDisplayAutoRun );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  _this->PatternIdx = -1;
  CoreTimer_OnSetPeriod( &_this->TimerNextPattern, 1000 );
  CoreTimer_OnSetEnabled( &_this->TimerNextPattern, 1 );
  _this->TotalPatternNum = 11;
  CoreRectView__OnSetBounds( &_this->FullScreen, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0001 );
  CoreRectView__OnSetBounds( &_this->CenterBlock, _Const0002 );
  ViewsRectangle_OnSetColor( &_this->CenterBlock, _Const0001 );
  CoreRectView__OnSetBounds( &_this->ImagePattern, _Const0000 );
  ViewsImage_OnSetVisible( &_this->ImagePattern, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->FullScreen ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CenterBlock ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ImagePattern ), 0 );
  _this->TimerNextPattern.OnTrigger = EwNewSlot( _this, FactoryDisplayAutoRun_OnTimerNextPatternSlot );
  ViewsImage_OnSetBitmap( &_this->ImagePattern, EwLoadResource( &ResourceDisplayTest, 
  ResourcesBitmap ));

  /* Call the user defined constructor */
  FactoryDisplayAutoRun_Init( _this, aArg );
}

/* Re-Initializer for the class 'Factory::DisplayAutoRun' */
void FactoryDisplayAutoRun__ReInit( FactoryDisplayAutoRun _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  CoreTimer__ReInit( &_this->TimerNextPattern );
  ViewsRectangle__ReInit( &_this->FullScreen );
  ViewsRectangle__ReInit( &_this->CenterBlock );
  ViewsImage__ReInit( &_this->ImagePattern );
}

/* Finalizer method for the class 'Factory::DisplayAutoRun' */
void FactoryDisplayAutoRun__Done( FactoryDisplayAutoRun _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  CoreTimer__Done( &_this->TimerNextPattern );
  ViewsRectangle__Done( &_this->FullScreen );
  ViewsRectangle__Done( &_this->CenterBlock );
  ViewsImage__Done( &_this->ImagePattern );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void FactoryDisplayAutoRun_Init( FactoryDisplayAutoRun _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  FactoryDisplayAutoRun_OnSetPatternIdx( _this, 0 );
}

/* 'C' function for method : 'Factory::DisplayAutoRun.OnLongKeyPressed()' */
void FactoryDisplayAutoRun_OnLongKeyPressed( FactoryDisplayAutoRun _this, XObject 
  sender )
{
  CoreKeyPressHandler CurrentKeyHandler = EwCastObject( sender, CoreKeyPressHandler );

  if (( CurrentKeyHandler != 0 ) && ( _this->Super4.Owner != 0 ))
  {
    switch ( CurrentKeyHandler->Code )
    {
      case CoreKeyCodeOk :
        CoreGroup__DismissDialog( _this->Super4.Owner, ((CoreGroup)_this ), 0, 0, 
        0, EwNullSlot, EwNullSlot, 0 );
      break;

      default : 
        ;
    }
  }
}

/* 'C' function for method : 'Factory::DisplayAutoRun.DisplayPattern()' */
void FactoryDisplayAutoRun_DisplayPattern( FactoryDisplayAutoRun _this, XInt32 aPatternIdx )
{
  switch ( aPatternIdx )
  {
    case 0 :
    {
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0003 );
      ViewsRectangle_OnSetVisible( &_this->CenterBlock, 0 );
      ViewsImage_OnSetVisible( &_this->ImagePattern, 0 );
    }
    break;

    case 1 :
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0004 );
    break;

    case 2 :
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0005 );
    break;

    case 3 :
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0001 );
    break;

    case 4 :
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0006 );
    break;

    case 5 :
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0007 );
    break;

    case 6 :
      ViewsRectangle_OnSetVisible( &_this->CenterBlock, 1 );
    break;

    case 7 :
    {
      ViewsImage_OnSetBitmap( &_this->ImagePattern, EwLoadResource( &ResourceDisplayTest, 
      ResourcesBitmap ));
      ViewsImage_OnSetFrameNumber( &_this->ImagePattern, 1 );
      ViewsImage_OnSetVisible( &_this->ImagePattern, 1 );
    }
    break;

    case 8 :
      ViewsImage_OnSetFrameNumber( &_this->ImagePattern, 2 );
    break;

    case 9 :
      ViewsImage_OnSetFrameNumber( &_this->ImagePattern, 3 );
    break;

    case 10 :
    {
      ResourcesExternBitmap_OnSetName( EwGetAutoObject( &ResourceExternBitmap, ResourcesExternBitmap ), 
      EwLoadString( &_Const0008 ));
      ViewsImage_OnSetBitmap( &_this->ImagePattern, ((ResourcesBitmap)EwGetAutoObject( 
      &ResourceExternBitmap, ResourcesExternBitmap )));
      ViewsImage_OnSetFrameNumber( &_this->ImagePattern, 0 );
    }
    break;

    default : 
      ;
  }
}

/* 'C' function for method : 'Factory::DisplayAutoRun.OnSetPatternIdx()' */
void FactoryDisplayAutoRun_OnSetPatternIdx( FactoryDisplayAutoRun _this, XInt32 
  value )
{
  if ( _this->PatternIdx != value )
  {
    _this->PatternIdx = value;
    FactoryDisplayAutoRun_DisplayPattern( _this, _this->PatternIdx );
  }
}

/* 'C' function for method : 'Factory::DisplayAutoRun.OnTimerNextPatternSlot()' */
void FactoryDisplayAutoRun_OnTimerNextPatternSlot( FactoryDisplayAutoRun _this, 
  XObject sender )
{
  XInt32 Idx;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  Idx = _this->PatternIdx + 1;

  if ( Idx >= _this->TotalPatternNum )
  {
    Idx = 0;
  }

  FactoryDisplayAutoRun_OnSetPatternIdx( _this, Idx );
}

/* Variants derived from the class : 'Factory::DisplayAutoRun' */
EW_DEFINE_CLASS_VARIANTS( FactoryDisplayAutoRun )
EW_END_OF_CLASS_VARIANTS( FactoryDisplayAutoRun )

/* Virtual Method Table (VMT) for the class : 'Factory::DisplayAutoRun' */
EW_DEFINE_CLASS( FactoryDisplayAutoRun, ComponentsBaseComponent, TimerNextPattern, 
                 TimerNextPattern, TimerNextPattern, TimerNextPattern, PatternIdx, 
                 PatternIdx, "Factory::DisplayAutoRun" )
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  FactoryDisplayAutoRun_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
EW_END_OF_CLASS( FactoryDisplayAutoRun )

/* Initializer for the class 'Factory::Main' */
void FactoryMain__Init( FactoryMain _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  MenuBaseMenuView__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( FactoryMain );

  /* ... then construct all embedded objects */
  MenuVerticalMenu__Init( &_this->Menu, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( FactoryMain );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  _this->ItemTitleArray[ 0 ] = EwShareString( EwLoadString( &_Const0009 ));
  _this->ItemTitleArray[ 1 ] = EwShareString( EwLoadString( &_Const000A ));
  CoreRectView__OnSetBounds( &_this->Menu, _Const000B );
  MenuVerticalMenu_OnSetNoOfItems( &_this->Menu, 2 );
  CoreGroup__Add( _this, ((CoreView)&_this->Menu ), 0 );
  _this->Menu.Super1.PassKeyHold = EwNewSlot( _this, ComponentsBaseComponent__OnLongKeyPressed );
}

/* Re-Initializer for the class 'Factory::Main' */
void FactoryMain__ReInit( FactoryMain _this )
{
  /* At first re-initialize the super class ... */
  MenuBaseMenuView__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  MenuVerticalMenu__ReInit( &_this->Menu );
}

/* Finalizer method for the class 'Factory::Main' */
void FactoryMain__Done( FactoryMain _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( MenuBaseMenuView );

  /* Finalize all embedded objects */
  MenuVerticalMenu__Done( &_this->Menu );

  /* Don't forget to deinitialize the super class ... */
  MenuBaseMenuView__Done( &_this->_Super );
}

/* The method DismissDialog() schedules an operation to hide again the component 
   passed in the parameter aDialogGroup. The component has to be presented by a 
   preceding @PresentDialog() or @SwitchToDialog() method invocation. Calling the 
   method DismissDialog() causes the corresponding entry to be removed from the 
   internal stack containing all dialogs existing at the moment in context of 'this' 
   owner component. The dialog component on top of the stack is considered as the 
   active dialog - the dialog, the user may interact with. Other dialogs lying in 
   the background are automatically deactivated and they are suppressed from being 
   able to receive and process user inputs. Accordingly, applying the dismiss operation 
   on the actually active (top) dialog causes the dialog existing eventually behind 
   it to restore its active state.
   The operation to hide the component is performed with an animation specified 
   at its presentation time (in the parameter aDismissTransition of the method @PresentDialog() 
   or @SwitchToDialog()). Alternatively, other transition to hide the component 
   can be specified in the parameter aOverrideDismissTransition.
   Dismissing a dialog may affect the visibility state of the dialog component lying 
   further in the background. In particular, the component in the background will 
   schedule a restore transition as expected to be after the dialog overlaying it 
   is dismissed. When dismissing a dialog, which is not the active one (not on top 
   of the stack), the component in the background will also schedule an overlay 
   transition as resulting from the new overlaying dialog component. Which transitions 
   are performed results primarily from the parameters aOverlayTransition and aRestoreTransition 
   specified at the presentation time of the background dialog component and the 
   parameters aOverrideRestoreTransition specified at the presentation time of the 
   overlaying (just dismissed) dialog component. Furthermore, you can override this 
   behavior by specifying other animations in the parameters aOverrideOverlayTransition 
   and aOverrideRestoreTransition in the invocation of the method DismissDialog().
   The both parameters aComplete and aCancel can be provided with references to 
   slot methods, which are signaled as soon as the dismiss operation is finished 
   (aComplete) or it has been canceled (aCancel) due to other transition being scheduled 
   for the same GUI component aDialogGroup making the actual operation obsolete.
   The dismiss operation is enqueued, so calling @SwitchToDialog(), @PresentDialog() 
   and DismissDialog() several times in sequence for different components in context 
   of 'this' owner component causes the resulting transitions to be executed strictly 
   one after another. This behavior can be changed by passing the value 'true' in 
   the parameter aCombine. In this case, the new operation will be executed together 
   with last prepared but not yet started operation. In this manner several independent 
   transitions can run simultaneously. */
void FactoryMain_DismissDialog( FactoryMain _this, CoreGroup aDialogGroup, EffectsTransition 
  aOverrideDismissTransition, EffectsTransition aOverrideOverlayTransition, EffectsTransition 
  aOverrideRestoreTransition, XSlot aComplete, XSlot aCancel, XBool aCombine )
{
  ApplicationApplication App;

  CoreGroup_DismissDialog((CoreGroup)_this, aDialogGroup, aOverrideDismissTransition, 
  aOverrideOverlayTransition, aOverrideRestoreTransition, aComplete, aCancel, aCombine );
  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );
  ApplicationApplication_OnSetStatusBarVisible( App, 1 );
}

/* 'C' function for method : 'Factory::Main.OnLongKeyPressed()' */
void FactoryMain_OnLongKeyPressed( FactoryMain _this, XObject sender )
{
  CoreKeyPressHandler CurrentKeyHandler = EwCastObject( sender, CoreKeyPressHandler );

  if (( CurrentKeyHandler != 0 ) && ( _this->Super5.Owner != 0 ))
  {
    switch ( CurrentKeyHandler->Code )
    {
      case CoreKeyCodeOk :
        ComponentsBaseComponent_SlideOutDialog((ComponentsBaseComponent)_this, ((CoreGroup)_this ));
      break;

      default : 
        ;
    }
  }
}

/* 'C' function for method : 'Factory::Main.LoadItemClass()' */
XClass FactoryMain_LoadItemClass( FactoryMain _this, XInt32 aItemNo )
{
  XClass ItemClass;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  ItemClass = 0;

  if ( aItemNo >= 0 )
  {
    ItemClass = EW_CLASS( MenuItemBase );
  }

  return ItemClass;
}

/* 'C' function for method : 'Factory::Main.LoadItemTitle()' */
XString FactoryMain_LoadItemTitle( FactoryMain _this, XInt32 aItemNo )
{
  XString Title = 0;

  if ( aItemNo < 2 )
  {
    Title = _this->ItemTitleArray[ EwCheckIndex( aItemNo, 2 )];
  }

  return Title;
}

/* 'C' function for method : 'Factory::Main.OnItemActivate()' */
void FactoryMain_OnItemActivate( FactoryMain _this, XInt32 aItemNo, MenuItemBase 
  aMenuItem )
{
  ApplicationApplication App;

  if ( aMenuItem == 0 )
    ;

  App = EwCastObject( CoreView__GetRoot( _this ), ApplicationApplication );

  switch ( aItemNo )
  {
    case 0 :
    {
      ApplicationApplication_OnSetStatusBarVisible( App, 0 );
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( FactoryDisplayManual, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
    break;

    case 1 :
    {
      ApplicationApplication_OnSetStatusBarVisible( App, 0 );
      CoreGroup_PresentDialog((CoreGroup)_this, ((CoreGroup)EwNewObject( FactoryDisplayAutoRun, 
      0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
    }
    break;

    default : 
      ;
  }
}

/* Variants derived from the class : 'Factory::Main' */
EW_DEFINE_CLASS_VARIANTS( FactoryMain )
EW_END_OF_CLASS_VARIANTS( FactoryMain )

/* Virtual Method Table (VMT) for the class : 'Factory::Main' */
EW_DEFINE_CLASS( FactoryMain, MenuBaseMenuView, Menu, Menu, Menu, Menu, ItemTitleArray, 
                 _None, "Factory::Main" )
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
  FactoryMain_DismissDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  FactoryMain_OnLongKeyPressed,
  ComponentsBaseComponent_OnShortDownKeyPressed,
  ComponentsBaseComponent_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
  FactoryMain_LoadItemClass,
  FactoryMain_LoadItemTitle,
  FactoryMain_OnItemActivate,
  MenuBaseMenuView_LoadItemChecked,
  MenuBaseMenuView_LoadItemEnabled,
  MenuBaseMenuView_LoadItemConnected,
  MenuBaseMenuView_LoadItemValid,
EW_END_OF_CLASS( FactoryMain )

/* Initializer for the class 'Factory::DisplayManual' */
void FactoryDisplayManual__Init( FactoryDisplayManual _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ComponentsBaseComponent__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( FactoryDisplayManual );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->FullScreen, &_this->_XObject, 0 );
  ViewsRectangle__Init( &_this->CenterBlock, &_this->_XObject, 0 );
  ViewsBorder__Init( &_this->OuterFrame, &_this->_XObject, 0 );
  ViewsImage__Init( &_this->ImagePattern, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( FactoryDisplayManual );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  _this->TotalPatternNum = 17;
  CoreRectView__OnSetBounds( &_this->FullScreen, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0006 );
  CoreRectView__OnSetBounds( &_this->CenterBlock, _Const0002 );
  ViewsRectangle_OnSetColor( &_this->CenterBlock, _Const0001 );
  ViewsRectangle_OnSetVisible( &_this->CenterBlock, 0 );
  CoreRectView__OnSetBounds( &_this->OuterFrame, _Const0000 );
  CoreRectView__OnSetBounds( &_this->ImagePattern, _Const0000 );
  ViewsImage_OnSetVisible( &_this->ImagePattern, 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->FullScreen ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->CenterBlock ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->OuterFrame ), 0 );
  CoreGroup__Add( _this, ((CoreView)&_this->ImagePattern ), 0 );
  ViewsImage_OnSetBitmap( &_this->ImagePattern, EwLoadResource( &ResourceDisplayTest, 
  ResourcesBitmap ));
}

/* Re-Initializer for the class 'Factory::DisplayManual' */
void FactoryDisplayManual__ReInit( FactoryDisplayManual _this )
{
  /* At first re-initialize the super class ... */
  ComponentsBaseComponent__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->FullScreen );
  ViewsRectangle__ReInit( &_this->CenterBlock );
  ViewsBorder__ReInit( &_this->OuterFrame );
  ViewsImage__ReInit( &_this->ImagePattern );
}

/* Finalizer method for the class 'Factory::DisplayManual' */
void FactoryDisplayManual__Done( FactoryDisplayManual _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( ComponentsBaseComponent );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->FullScreen );
  ViewsRectangle__Done( &_this->CenterBlock );
  ViewsBorder__Done( &_this->OuterFrame );
  ViewsImage__Done( &_this->ImagePattern );

  /* Don't forget to deinitialize the super class ... */
  ComponentsBaseComponent__Done( &_this->_Super );
}

/* 'C' function for method : 'Factory::DisplayManual.OnLongKeyPressed()' */
void FactoryDisplayManual_OnLongKeyPressed( FactoryDisplayManual _this, XObject 
  sender )
{
  CoreKeyPressHandler CurrentKeyHandler = EwCastObject( sender, CoreKeyPressHandler );

  if (( CurrentKeyHandler != 0 ) && ( _this->Super4.Owner != 0 ))
  {
    switch ( CurrentKeyHandler->Code )
    {
      case CoreKeyCodeOk :
        CoreGroup__DismissDialog( _this->Super4.Owner, ((CoreGroup)_this ), 0, 0, 
        0, EwNullSlot, EwNullSlot, 0 );
      break;

      default : 
        ;
    }
  }
}

/* 'C' function for method : 'Factory::DisplayManual.OnShortDownKeyPressed()' */
void FactoryDisplayManual_OnShortDownKeyPressed( FactoryDisplayManual _this )
{
  XInt32 NextIdx = _this->PatternIdx + 1;

  if ( NextIdx >= _this->TotalPatternNum )
  {
    NextIdx = 0;
  }

  FactoryDisplayManual_OnSetPatternIdx( _this, NextIdx );
}

/* 'C' function for method : 'Factory::DisplayManual.OnShortUpKeyPressed()' */
void FactoryDisplayManual_OnShortUpKeyPressed( FactoryDisplayManual _this )
{
  XInt32 PreviousIdx = _this->PatternIdx - 1;

  if ( PreviousIdx < 0 )
  {
    PreviousIdx = _this->TotalPatternNum - 1;
  }

  FactoryDisplayManual_OnSetPatternIdx( _this, PreviousIdx );
}

/* 'C' function for method : 'Factory::DisplayManual.OnSetPatternIdx()' */
void FactoryDisplayManual_OnSetPatternIdx( FactoryDisplayManual _this, XInt32 value )
{
  if ( _this->PatternIdx != value )
  {
    _this->PatternIdx = value;
    FactoryDisplayManual_DisplayPattern( _this, _this->PatternIdx );
  }
}

/* 'C' function for method : 'Factory::DisplayManual.DisplayPattern()' */
void FactoryDisplayManual_DisplayPattern( FactoryDisplayManual _this, XInt32 aPatternIdx )
{
  switch ( aPatternIdx )
  {
    case 0 :
    {
      ViewsImage_OnSetVisible( &_this->ImagePattern, 0 );
      ViewsRectangle_OnSetVisible( &_this->CenterBlock, 0 );
      ViewsBorder_OnSetVisible( &_this->OuterFrame, 1 );
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0006 );
    }
    break;

    case 1 :
    {
      ViewsImage_OnSetBitmap( &_this->ImagePattern, EwLoadResource( &ResourceDisplayTest, 
      ResourcesBitmap ));
      ViewsImage_OnSetFrameNumber( &_this->ImagePattern, 0 );
      ViewsImage_OnSetVisible( &_this->ImagePattern, 1 );
    }
    break;

    case 2 :
    {
      ViewsImage_OnSetVisible( &_this->ImagePattern, 0 );
      ViewsRectangle_OnSetVisible( &_this->CenterBlock, 0 );
      ViewsBorder_OnSetVisible( &_this->OuterFrame, 0 );
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0003 );
    }
    break;

    case 3 :
    {
      ViewsImage_OnSetVisible( &_this->ImagePattern, 0 );
      ViewsRectangle_OnSetVisible( &_this->CenterBlock, 0 );
      ViewsBorder_OnSetVisible( &_this->OuterFrame, 0 );
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0004 );
    }
    break;

    case 4 :
    {
      ViewsImage_OnSetVisible( &_this->ImagePattern, 0 );
      ViewsRectangle_OnSetVisible( &_this->CenterBlock, 0 );
      ViewsBorder_OnSetVisible( &_this->OuterFrame, 0 );
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0005 );
    }
    break;

    case 5 :
    {
      ViewsImage_OnSetVisible( &_this->ImagePattern, 0 );
      ViewsRectangle_OnSetVisible( &_this->CenterBlock, 0 );
      ViewsBorder_OnSetVisible( &_this->OuterFrame, 0 );
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0001 );
    }
    break;

    case 6 :
    {
      ViewsImage_OnSetVisible( &_this->ImagePattern, 0 );
      ViewsRectangle_OnSetVisible( &_this->CenterBlock, 0 );
      ViewsBorder_OnSetVisible( &_this->OuterFrame, 0 );
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0006 );
    }
    break;

    case 7 :
    {
      ViewsImage_OnSetVisible( &_this->ImagePattern, 0 );
      ViewsRectangle_OnSetVisible( &_this->CenterBlock, 0 );
      ViewsBorder_OnSetVisible( &_this->OuterFrame, 0 );
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const000C );
    }
    break;

    case 8 :
    {
      ViewsImage_OnSetVisible( &_this->ImagePattern, 0 );
      ViewsRectangle_OnSetVisible( &_this->CenterBlock, 1 );
      ViewsBorder_OnSetVisible( &_this->OuterFrame, 0 );
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0007 );
    }
    break;

    case 9 :
    {
      ViewsImage_OnSetVisible( &_this->ImagePattern, 0 );
      ViewsRectangle_OnSetVisible( &_this->CenterBlock, 0 );
      ViewsBorder_OnSetVisible( &_this->OuterFrame, 0 );
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const0007 );
    }
    break;

    case 10 :
    {
      ViewsImage_OnSetBitmap( &_this->ImagePattern, EwLoadResource( &ResourceDisplayTest, 
      ResourcesBitmap ));
      ViewsImage_OnSetFrameNumber( &_this->ImagePattern, 1 );
      ViewsImage_OnSetVisible( &_this->ImagePattern, 1 );
      ViewsRectangle_OnSetVisible( &_this->CenterBlock, 0 );
    }
    break;

    case 11 :
    {
      ViewsImage_OnSetVisible( &_this->ImagePattern, 0 );
      ViewsRectangle_OnSetVisible( &_this->CenterBlock, 0 );
      ViewsBorder_OnSetVisible( &_this->OuterFrame, 0 );
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const000C );
    }
    break;

    case 12 :
    {
      ViewsImage_OnSetBitmap( &_this->ImagePattern, EwLoadResource( &ResourceDisplayTest, 
      ResourcesBitmap ));
      ViewsImage_OnSetFrameNumber( &_this->ImagePattern, 4 );
      ViewsImage_OnSetVisible( &_this->ImagePattern, 1 );
    }
    break;

    case 13 :
    {
      ViewsImage_OnSetBitmap( &_this->ImagePattern, EwLoadResource( &ResourceDisplayTest, 
      ResourcesBitmap ));
      ViewsImage_OnSetFrameNumber( &_this->ImagePattern, 2 );
      ViewsImage_OnSetVisible( &_this->ImagePattern, 1 );
    }
    break;

    case 14 :
    {
      ViewsImage_OnSetBitmap( &_this->ImagePattern, EwLoadResource( &ResourceDisplayTest, 
      ResourcesBitmap ));
      ViewsImage_OnSetFrameNumber( &_this->ImagePattern, 3 );
      ViewsImage_OnSetVisible( &_this->ImagePattern, 1 );
    }
    break;

    case 15 :
    {
      ResourcesExternBitmap_OnSetName( EwGetAutoObject( &ResourceExternBitmap, ResourcesExternBitmap ), 
      EwLoadString( &_Const0008 ));
      ViewsImage_OnSetBitmap( &_this->ImagePattern, ((ResourcesBitmap)EwGetAutoObject( 
      &ResourceExternBitmap, ResourcesExternBitmap )));
      ViewsImage_OnSetFrameNumber( &_this->ImagePattern, 0 );
      ViewsImage_OnSetVisible( &_this->ImagePattern, 1 );
    }
    break;

    case 16 :
    {
      ViewsImage_OnSetVisible( &_this->ImagePattern, 0 );
      ViewsRectangle_OnSetVisible( &_this->CenterBlock, 0 );
      ViewsBorder_OnSetVisible( &_this->OuterFrame, 0 );
      ViewsRectangle_OnSetColor( &_this->FullScreen, _Const000D );
    }
    break;

    default : 
      ;
  }
}

/* Variants derived from the class : 'Factory::DisplayManual' */
EW_DEFINE_CLASS_VARIANTS( FactoryDisplayManual )
EW_END_OF_CLASS_VARIANTS( FactoryDisplayManual )

/* Virtual Method Table (VMT) for the class : 'Factory::DisplayManual' */
EW_DEFINE_CLASS( FactoryDisplayManual, ComponentsBaseComponent, FullScreen, FullScreen, 
                 FullScreen, FullScreen, TotalPatternNum, TotalPatternNum, "Factory::DisplayManual" )
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
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
  FactoryDisplayManual_OnLongKeyPressed,
  FactoryDisplayManual_OnShortDownKeyPressed,
  FactoryDisplayManual_OnShortUpKeyPressed,
  ComponentsBaseComponent_OnShortEnterKeyPressed,
EW_END_OF_CLASS( FactoryDisplayManual )

/* Initializer for the class 'Factory::TestContext' */
void FactoryTestContext__Init( FactoryTestContext _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( FactoryTestContext );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( FactoryTestContext );
}

/* Re-Initializer for the class 'Factory::TestContext' */
void FactoryTestContext__ReInit( FactoryTestContext _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Factory::TestContext' */
void FactoryTestContext__Done( FactoryTestContext _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_Super );
}

/* Variants derived from the class : 'Factory::TestContext' */
EW_DEFINE_CLASS_VARIANTS( FactoryTestContext )
EW_END_OF_CLASS_VARIANTS( FactoryTestContext )

/* Virtual Method Table (VMT) for the class : 'Factory::TestContext' */
EW_DEFINE_CLASS( FactoryTestContext, XObject, _None, _None, _None, _None, _None, 
                 _None, "Factory::TestContext" )
EW_END_OF_CLASS( FactoryTestContext )

/* Embedded Wizard */
