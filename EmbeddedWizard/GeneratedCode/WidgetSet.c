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
#include "_CoreKeyPressHandler.h"
#include "_CoreRoot.h"
#include "_CoreSimpleTouchHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_ResourcesBitmap.h"
#include "_ViewsFrame.h"
#include "_ViewsImage.h"
#include "_WidgetSetHorizontalSlider.h"
#include "_WidgetSetHorizontalSliderConfig.h"
#include "_WidgetSetWidgetConfig.h"
#include "Core.h"
#include "Graphics.h"
#include "WidgetSet.h"

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 200, 50 }};
static const XPoint _Const0001 = { 0, 50 };
static const XPoint _Const0002 = { 200, 50 };
static const XPoint _Const0003 = { 200, 0 };
static const XPoint _Const0004 = { 0, 0 };
static const XColor _Const0005 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XRect _Const0006 = {{ -8, -8 }, { 9, 9 }};

/* Initializer for the class 'WidgetSet::HorizontalSliderConfig' */
void WidgetSetHorizontalSliderConfig__Init( WidgetSetHorizontalSliderConfig _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  WidgetSetWidgetConfig__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( WidgetSetHorizontalSliderConfig );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( WidgetSetHorizontalSliderConfig );

  /* ... and initialize objects, variables, properties, etc. */
  _this->TrackRightFrameFocused = -1;
  _this->TrackRightFrameDefault = -1;
  _this->TrackLeftFrameFocused = -1;
  _this->TrackLeftFrameDefault = -1;
}

/* Re-Initializer for the class 'WidgetSet::HorizontalSliderConfig' */
void WidgetSetHorizontalSliderConfig__ReInit( WidgetSetHorizontalSliderConfig _this )
{
  /* At first re-initialize the super class ... */
  WidgetSetWidgetConfig__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'WidgetSet::HorizontalSliderConfig' */
void WidgetSetHorizontalSliderConfig__Done( WidgetSetHorizontalSliderConfig _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( WidgetSetWidgetConfig );

  /* Don't forget to deinitialize the super class ... */
  WidgetSetWidgetConfig__Done( &_this->_.Super );
}

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbFocused( WidgetSetHorizontalSliderConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->ThumbFocused == value )
    return;

  _this->ThumbFocused = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetThumbDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetThumbDefault( WidgetSetHorizontalSliderConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->ThumbDefault == value )
    return;

  _this->ThumbDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightFrameFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightFrameFocused( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value )
{
  if ( _this->TrackRightFrameFocused == value )
    return;

  _this->TrackRightFrameFocused = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightFrameDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightFrameDefault( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value )
{
  if ( _this->TrackRightFrameDefault == value )
    return;

  _this->TrackRightFrameDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightFocused( WidgetSetHorizontalSliderConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->TrackRightFocused == value )
    return;

  _this->TrackRightFocused = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackRightDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackRightDefault( WidgetSetHorizontalSliderConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->TrackRightDefault == value )
    return;

  _this->TrackRightDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftFrameFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftFrameFocused( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value )
{
  if ( _this->TrackLeftFrameFocused == value )
    return;

  _this->TrackLeftFrameFocused = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftFrameDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftFrameDefault( WidgetSetHorizontalSliderConfig _this, 
  XInt32 value )
{
  if ( _this->TrackLeftFrameDefault == value )
    return;

  _this->TrackLeftFrameDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftFocused()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftFocused( WidgetSetHorizontalSliderConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->TrackLeftFocused == value )
    return;

  _this->TrackLeftFocused = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::HorizontalSliderConfig.OnSetTrackLeftDefault()' */
void WidgetSetHorizontalSliderConfig_OnSetTrackLeftDefault( WidgetSetHorizontalSliderConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->TrackLeftDefault == value )
    return;

  _this->TrackLeftDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* Variants derived from the class : 'WidgetSet::HorizontalSliderConfig' */
EW_DEFINE_CLASS_VARIANTS( WidgetSetHorizontalSliderConfig )
EW_END_OF_CLASS_VARIANTS( WidgetSetHorizontalSliderConfig )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::HorizontalSliderConfig' */
EW_DEFINE_CLASS( WidgetSetHorizontalSliderConfig, WidgetSetWidgetConfig, ThumbFocused, 
                 TrackRightFrameFocused, TrackRightFrameFocused, TrackRightFrameFocused, 
                 TrackRightFrameFocused, TrackRightFrameFocused, "WidgetSet::HorizontalSliderConfig" )
EW_END_OF_CLASS( WidgetSetHorizontalSliderConfig )

/* Initializer for the class 'WidgetSet::WidgetConfig' */
void WidgetSetWidgetConfig__Init( WidgetSetWidgetConfig _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( WidgetSetWidgetConfig );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( WidgetSetWidgetConfig );
}

/* Re-Initializer for the class 'WidgetSet::WidgetConfig' */
void WidgetSetWidgetConfig__ReInit( WidgetSetWidgetConfig _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'WidgetSet::WidgetConfig' */
void WidgetSetWidgetConfig__Done( WidgetSetWidgetConfig _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* 'C' function for method : 'WidgetSet::WidgetConfig.onInvalidate()' */
void WidgetSetWidgetConfig_onInvalidate( WidgetSetWidgetConfig _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwNotifyObjObservers((XObject)_this, 0 );
}

/* Variants derived from the class : 'WidgetSet::WidgetConfig' */
EW_DEFINE_CLASS_VARIANTS( WidgetSetWidgetConfig )
EW_END_OF_CLASS_VARIANTS( WidgetSetWidgetConfig )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::WidgetConfig' */
EW_DEFINE_CLASS( WidgetSetWidgetConfig, XObject, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, "WidgetSet::WidgetConfig" )
EW_END_OF_CLASS( WidgetSetWidgetConfig )

/* Initializer for the class 'WidgetSet::HorizontalSlider' */
void WidgetSetHorizontalSlider__Init( WidgetSetHorizontalSlider _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( WidgetSetHorizontalSlider );

  /* ... then construct all embedded objects */
  CoreTimer__Init( &_this->RepetitionTimer, &_this->_.XObject, 0 );
  CoreKeyPressHandler__Init( &_this->KeyHandlerLeft, &_this->_.XObject, 0 );
  CoreKeyPressHandler__Init( &_this->KeyHandlerRight, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->TouchHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( WidgetSetHorizontalSlider );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreTimer_OnSetPeriod( &_this->RepetitionTimer, 0 );
  CoreTimer_OnSetBegin( &_this->RepetitionTimer, 50 );
  _this->KeyHandlerLeft.Filter = CoreKeyCodeLeft;
  _this->KeyHandlerRight.Filter = CoreKeyCodeRight;
  CoreView_OnSetLayout((CoreView)&_this->TouchHandler, CoreLayoutAlignToBottom | 
  CoreLayoutAlignToLeft | CoreLayoutAlignToRight | CoreLayoutAlignToTop | CoreLayoutResizeHorz 
  | CoreLayoutResizeVert );
  CoreQuadView_OnSetPoint4((CoreQuadView)&_this->TouchHandler, _Const0001 );
  CoreQuadView_OnSetPoint3((CoreQuadView)&_this->TouchHandler, _Const0002 );
  CoreQuadView_OnSetPoint2((CoreQuadView)&_this->TouchHandler, _Const0003 );
  CoreQuadView_OnSetPoint1((CoreQuadView)&_this->TouchHandler, _Const0004 );
  CoreSimpleTouchHandler_OnSetRetargetOffset( &_this->TouchHandler, 16 );
  CoreSimpleTouchHandler_OnSetMaxStrikeCount( &_this->TouchHandler, 100 );
  _this->CurrentValue = 50;
  CoreGroup__Add( _this, ((CoreView)&_this->TouchHandler ), 0 );
  _this->RepetitionTimer.OnTrigger = EwNewSlot( _this, WidgetSetHorizontalSlider_onRepetitionTimer );
  _this->KeyHandlerLeft.OnRelease = EwNewSlot( _this, WidgetSetHorizontalSlider_onReleaseKey );
  _this->KeyHandlerLeft.OnPress = EwNewSlot( _this, WidgetSetHorizontalSlider_onPressKey );
  _this->KeyHandlerRight.OnRelease = EwNewSlot( _this, WidgetSetHorizontalSlider_onReleaseKey );
  _this->KeyHandlerRight.OnPress = EwNewSlot( _this, WidgetSetHorizontalSlider_onPressKey );
  _this->TouchHandler.OnDrag = EwNewSlot( _this, WidgetSetHorizontalSlider_onDragTouch );
  _this->TouchHandler.OnRelease = EwNewSlot( _this, WidgetSetHorizontalSlider_onReleaseTouch );
  _this->TouchHandler.OnPress = EwNewSlot( _this, WidgetSetHorizontalSlider_onPressTouch );
}

/* Re-Initializer for the class 'WidgetSet::HorizontalSlider' */
void WidgetSetHorizontalSlider__ReInit( WidgetSetHorizontalSlider _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreTimer__ReInit( &_this->RepetitionTimer );
  CoreKeyPressHandler__ReInit( &_this->KeyHandlerLeft );
  CoreKeyPressHandler__ReInit( &_this->KeyHandlerRight );
  CoreSimpleTouchHandler__ReInit( &_this->TouchHandler );
}

/* Finalizer method for the class 'WidgetSet::HorizontalSlider' */
void WidgetSetHorizontalSlider__Done( WidgetSetHorizontalSlider _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  CoreTimer__Done( &_this->RepetitionTimer );
  CoreKeyPressHandler__Done( &_this->KeyHandlerLeft );
  CoreKeyPressHandler__Done( &_this->KeyHandlerRight );
  CoreSimpleTouchHandler__Done( &_this->TouchHandler );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'WidgetSet::HorizontalSlider.OnSetBounds()' */
void WidgetSetHorizontalSlider_OnSetBounds( WidgetSetHorizontalSlider _this, XRect 
  value )
{
  if ( _this->Appearance != 0 )
  {
    XPoint cs = EwGetRectSize( value );
    XPoint ns = cs;
    XPoint delta;

    if ( ns.X < 0 )
      ns.X = 0;

    if ( ns.Y < 0 )
      ns.Y = 0;

    delta = EwMovePointNeg( ns, cs );

    if ( delta.X != 0 )
    {
      XBool alignToLeft = (( _this->Super3.Layout & CoreLayoutAlignToLeft ) == CoreLayoutAlignToLeft );
      XBool alignToRight = (( _this->Super3.Layout & CoreLayoutAlignToRight ) == 
        CoreLayoutAlignToRight );

      if ( alignToLeft && !alignToRight )
        value.Point2.X = ( value.Point2.X + delta.X );
      else
        if ( !alignToLeft && alignToRight )
          value.Point1.X = ( value.Point1.X - delta.X );
        else
        {
          value.Point1.X = ( value.Point1.X - ( delta.X / 2 ));
          value.Point2.X = ( value.Point1.X + ns.X );
        }
    }

    if ( delta.Y != 0 )
    {
      XBool alignToTop = (( _this->Super3.Layout & CoreLayoutAlignToTop ) == CoreLayoutAlignToTop );
      XBool alignToBottom = (( _this->Super3.Layout & CoreLayoutAlignToBottom ) 
        == CoreLayoutAlignToBottom );

      if ( alignToTop && !alignToBottom )
        value.Point2.Y = ( value.Point2.Y + delta.Y );
      else
        if ( !alignToTop && alignToBottom )
          value.Point1.Y = ( value.Point1.Y - delta.Y );
        else
        {
          value.Point1.Y = ( value.Point1.Y - ( delta.Y / 2 ));
          value.Point2.Y = ( value.Point1.Y + ns.Y );
        }
    }
  }

  CoreGroup_OnSetBounds((CoreGroup)_this, value );
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
void WidgetSetHorizontalSlider_UpdateViewState( WidgetSetHorizontalSlider _this, 
  XSet aState )
{
  XBool needsTrackLeft;
  XBool needsTrackRight;
  XBool needsThumb;
  XBool restack;
  XRect area;
  XPoint thumbSize;
  XBool isEnabled;
  XBool isFocused;
  XBool isPressed;
  XInt32 marginLeft;
  XInt32 marginRight;
  XInt32 minPos;
  XInt32 maxPos;
  XInt32 newThumbPos;

  CoreGroup_UpdateViewState((CoreGroup)_this, aState );
  needsTrackLeft = (XBool)(( _this->Appearance != 0 ) && (( _this->Appearance->TrackLeftDefault 
  != 0 ) || ( _this->Appearance->TrackLeftFocused != 0 )));
  needsTrackRight = (XBool)(( _this->Appearance != 0 ) && (( _this->Appearance->TrackRightDefault 
  != 0 ) || ( _this->Appearance->TrackRightFocused != 0 )));
  needsThumb = (XBool)(( _this->Appearance != 0 ) && (( _this->Appearance->ThumbDefault 
  != 0 ) || ( _this->Appearance->ThumbFocused != 0 )));
  restack = 0;
  area = EwGetRectORect( _this->Super2.Bounds );
  thumbSize = _Const0004;

  if ( needsTrackLeft && ( _this->frameView2 == 0 ))
  {
    _this->frameView2 = EwNewObject( ViewsFrame, 0 );
    CoreGroup__Add( _this, ((CoreView)_this->frameView2 ), 0 );
    restack = 1;
  }
  else
    if ( !needsTrackLeft && ( _this->frameView2 != 0 ))
    {
      CoreGroup__Remove( _this, ((CoreView)_this->frameView2 ));
      _this->frameView2 = 0;
    }

  if ( needsTrackRight && ( _this->frameView3 == 0 ))
  {
    _this->frameView3 = EwNewObject( ViewsFrame, 0 );
    CoreGroup__Add( _this, ((CoreView)_this->frameView3 ), 0 );
    restack = 1;
  }
  else
    if ( !needsTrackRight && ( _this->frameView3 != 0 ))
    {
      CoreGroup__Remove( _this, ((CoreView)_this->frameView3 ));
      _this->frameView3 = 0;
    }

  if ( needsThumb && ( _this->imageView == 0 ))
  {
    _this->imageView = EwNewObject( ViewsImage, 0 );
    CoreGroup__Add( _this, ((CoreView)_this->imageView ), 0 );
    restack = 1;
  }
  else
    if ( !needsThumb && ( _this->imageView != 0 ))
    {
      CoreGroup__Remove( _this, ((CoreView)_this->imageView ));
      _this->imageView = 0;
    }

  if ( restack )
  {
    if ( _this->frameView2 != 0 )
      CoreGroup__RestackTop( _this, ((CoreView)_this->frameView2 ));

    if ( _this->frameView3 != 0 )
      CoreGroup__RestackTop( _this, ((CoreView)_this->frameView3 ));

    if ( _this->imageView != 0 )
      CoreGroup__RestackTop( _this, ((CoreView)_this->imageView ));
  }

  isEnabled = (( aState & CoreViewStateEnabled ) == CoreViewStateEnabled );
  isFocused = (( aState & CoreViewStateFocused ) == CoreViewStateFocused );
  isPressed = (XBool)(( _this->touchActive || _this->KeyHandlerRight.Down ) || _this->KeyHandlerLeft.Down );

  if ( _this->frameView2 != 0 )
  {
    ResourcesBitmap bitmap;
    XInt32 frameNo;

    if ( !isEnabled )
    {
      bitmap = 0;
      frameNo = -1;
    }
    else
      if ( isPressed )
      {
        bitmap = 0;
        frameNo = -1;
      }
      else
        if ( isFocused )
        {
          bitmap = _this->Appearance->TrackLeftFocused;
          frameNo = _this->Appearance->TrackLeftFrameFocused;
        }
        else
        {
          bitmap = _this->Appearance->TrackLeftDefault;
          frameNo = _this->Appearance->TrackLeftFrameDefault;
        }

    ViewsFrame_OnSetAnimated( _this->frameView2, (XBool)( frameNo < 0 ));
    ViewsFrame_OnSetColor( _this->frameView2, _Const0005 );

    if ( frameNo < 0 )
      frameNo = 0;

    ViewsFrame_OnSetFrameNumber( _this->frameView2, frameNo );
    ViewsFrame_OnSetBitmap( _this->frameView2, bitmap );
    ViewsFrame_OnSetEdges( _this->frameView2, GraphicsEdgesBottom | GraphicsEdgesInterior 
    | GraphicsEdgesLeft | GraphicsEdgesTop );
  }

  if ( _this->frameView3 != 0 )
  {
    ResourcesBitmap bitmap;
    XInt32 frameNo;

    if ( !isEnabled )
    {
      bitmap = 0;
      frameNo = -1;
    }
    else
      if ( isPressed )
      {
        bitmap = 0;
        frameNo = -1;
      }
      else
        if ( isFocused )
        {
          bitmap = _this->Appearance->TrackRightFocused;
          frameNo = _this->Appearance->TrackRightFrameFocused;
        }
        else
        {
          bitmap = _this->Appearance->TrackRightDefault;
          frameNo = _this->Appearance->TrackRightFrameDefault;
        }

    ViewsFrame_OnSetAnimated( _this->frameView3, (XBool)( frameNo < 0 ));
    ViewsFrame_OnSetColor( _this->frameView3, _Const0005 );

    if ( frameNo < 0 )
      frameNo = 0;

    ViewsFrame_OnSetFrameNumber( _this->frameView3, frameNo );
    ViewsFrame_OnSetBitmap( _this->frameView3, bitmap );
    ViewsFrame_OnSetEdges( _this->frameView3, GraphicsEdgesBottom | GraphicsEdgesInterior 
    | GraphicsEdgesRight | GraphicsEdgesTop );
  }

  if ( _this->imageView != 0 )
  {
    ResourcesBitmap bitmap;

    if ( !isEnabled )
      bitmap = 0;
    else
      if ( isPressed )
        bitmap = 0;
      else
        if ( isFocused )
          bitmap = _this->Appearance->ThumbFocused;
        else
          bitmap = _this->Appearance->ThumbDefault;

    ViewsImage_OnSetAnimated( _this->imageView, 1 );
    ViewsImage_OnSetColor( _this->imageView, _Const0005 );
    ViewsImage_OnSetFrameNumber( _this->imageView, 0 );
    ViewsImage_OnSetBitmap( _this->imageView, bitmap );
  }

  if (( _this->imageView != 0 ) && ( _this->imageView->Bitmap != 0 ))
    thumbSize = _this->imageView->Bitmap->FrameSize;

  marginLeft = thumbSize.X / 2;
  marginRight = thumbSize.X - marginLeft;
  minPos = marginLeft;
  maxPos = EwGetRectW( area ) - marginRight;
  newThumbPos = (XInt32)(((XFloat)WidgetSetHorizontalSlider_OnGetCurrentValue( _this ) 
  * (XFloat)( maxPos - minPos )) / 100.000000f ) + minPos;

  if ( newThumbPos < 0 )
    newThumbPos = 0;

  if ( newThumbPos > EwGetRectW( area ))
    newThumbPos = EwGetRectW( area );

  if (( _this->frameView2 != 0 ) && ( _this->frameView2->Bitmap != 0 ))
  {
    XPoint s = _this->frameView2->Bitmap->FrameSize;
    CoreRectView__OnSetBounds( _this->frameView2, EwNewRect( 0, ( EwGetRectH( area ) 
    / 2 ) - ( s.Y / 2 ), newThumbPos, (( EwGetRectH( area ) / 2 ) - ( s.Y / 2 )) 
    + s.Y ));
    ViewsFrame_OnSetNoEdgesLimit( _this->frameView2, EwSetPointX( _this->frameView2->NoEdgesLimit, 
    EwGetRectW( area ) - ( s.X / 3 )));
    ViewsFrame_OnSetVisible( _this->frameView2, 1 );
  }

  if (( _this->frameView3 != 0 ) && ( _this->frameView3->Bitmap != 0 ))
  {
    XPoint s = _this->frameView3->Bitmap->FrameSize;
    CoreRectView__OnSetBounds( _this->frameView3, EwNewRect( newThumbPos, ( EwGetRectH( 
    area ) / 2 ) - ( s.Y / 2 ), EwGetRectW( area ), (( EwGetRectH( area ) / 2 ) 
    - ( s.Y / 2 )) + s.Y ));
    ViewsFrame_OnSetNoEdgesLimit( _this->frameView3, EwSetPointX( _this->frameView3->NoEdgesLimit, 
    EwGetRectW( area ) - ( s.X / 3 )));
    ViewsFrame_OnSetVisible( _this->frameView3, 1 );
  }

  if (( _this->imageView != 0 ) && ( _this->imageView->Bitmap != 0 ))
  {
    XRect thumbArea = EwNewRect2Point( _Const0004, thumbSize );
    CoreRectView__OnSetBounds( _this->imageView, EwMoveRectPos( EwMoveRectNeg( thumbArea, 
    EwGetRectCenter( thumbArea )), EwNewPoint( newThumbPos, EwGetRectH( area ) / 
    2 )));
  }
}

/* 'C' function for method : 'WidgetSet::HorizontalSlider.onConfigChanged()' */
void WidgetSetHorizontalSlider_onConfigChanged( WidgetSetHorizontalSlider _this, 
  XObject sender )
{
  XEnum oldKeyCodeRight;
  XEnum oldKeyCodeLeft;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  oldKeyCodeRight = _this->KeyHandlerRight.Filter;
  oldKeyCodeLeft = _this->KeyHandlerLeft.Filter;
  _this->KeyHandlerRight.Filter = CoreKeyCodeRight;
  _this->KeyHandlerLeft.Filter = CoreKeyCodeLeft;

  if (((( oldKeyCodeRight == CoreKeyCodeNoKey ) || ( oldKeyCodeLeft == CoreKeyCodeNoKey )) 
      && ( _this->KeyHandlerRight.Filter != CoreKeyCodeNoKey )) && ( _this->KeyHandlerLeft.Filter 
      != CoreKeyCodeNoKey ))
    CoreView__ChangeViewState( _this, CoreViewStateFocusable, 0 );

  if ((( oldKeyCodeRight != CoreKeyCodeNoKey ) && ( oldKeyCodeLeft != CoreKeyCodeNoKey )) 
      && (( _this->KeyHandlerRight.Filter == CoreKeyCodeNoKey ) || ( _this->KeyHandlerLeft.Filter 
      == CoreKeyCodeNoKey )))
    CoreView__ChangeViewState( _this, 0, CoreViewStateFocusable );

  CoreTimer_OnSetBegin( &_this->RepetitionTimer, 0 );
  CoreTimer_OnSetPeriod( &_this->RepetitionTimer, 0 );

  if ( _this->Appearance != 0 )
    CoreRectView__OnSetBounds( _this, _this->Super2.Bounds );

  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::HorizontalSlider.onRepetitionTimer()' */
void WidgetSetHorizontalSlider_onRepetitionTimer( WidgetSetHorizontalSlider _this, 
  XObject sender )
{
  XInt32 oldValue;
  XInt32 newValue;
  XInt32 delta;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  oldValue = WidgetSetHorizontalSlider_OnGetCurrentValue( _this );
  newValue = oldValue;
  delta = 1;

  if ( _this->KeyHandlerLeft.Down )
    delta = -1;

  if ( oldValue < 0 )
  {
    newValue = -newValue;
    delta = -delta;
  }

  if ( delta > 0 )
    newValue = ( newValue + delta ) - (( newValue + delta ) % delta );

  if ( delta < 0 )
  {
    if (( newValue % -delta ) != 0 )
      newValue = ( newValue - delta ) - ( newValue % -delta );

    newValue = newValue + delta;
  }

  if ( oldValue < 0 )
    newValue = -newValue;

  WidgetSetHorizontalSlider_OnSetCurrentValue( _this, newValue );

  if ( oldValue == WidgetSetHorizontalSlider_OnGetCurrentValue( _this ))
    return;
}

/* 'C' function for method : 'WidgetSet::HorizontalSlider.onReleaseKey()' */
void WidgetSetHorizontalSlider_onReleaseKey( WidgetSetHorizontalSlider _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreSimpleTouchHandler_OnSetEnabled( &_this->TouchHandler, 1 );
  CoreGroup_InvalidateViewState((CoreGroup)_this );
  CoreTimer_OnSetEnabled( &_this->RepetitionTimer, 0 );
}

/* 'C' function for method : 'WidgetSet::HorizontalSlider.onPressKey()' */
void WidgetSetHorizontalSlider_onPressKey( WidgetSetHorizontalSlider _this, XObject 
  sender )
{
  XInt32 oldValue;
  XInt32 newValue;
  XInt32 delta;

  CoreSimpleTouchHandler_OnSetEnabled( &_this->TouchHandler, 0 );
  CoreGroup_InvalidateViewState((CoreGroup)_this );
  CoreTimer_OnSetEnabled( &_this->RepetitionTimer, 1 );
  oldValue = WidgetSetHorizontalSlider_OnGetCurrentValue( _this );
  newValue = oldValue;
  delta = 1;

  if ( sender == ((XObject)&_this->KeyHandlerLeft ))
    delta = -1;

  if ( oldValue < 0 )
  {
    newValue = -newValue;
    delta = -delta;
  }

  if ( delta > 0 )
    newValue = ( newValue + delta ) - (( newValue + delta ) % delta );

  if ( delta < 0 )
  {
    if (( newValue % -delta ) != 0 )
      newValue = ( newValue - delta ) - ( newValue % -delta );

    newValue = newValue + delta;
  }

  if ( oldValue < 0 )
    newValue = -newValue;

  WidgetSetHorizontalSlider_OnSetCurrentValue( _this, newValue );

  if ( oldValue == WidgetSetHorizontalSlider_OnGetCurrentValue( _this ))
    return;
}

/* 'C' function for method : 'WidgetSet::HorizontalSlider.onDragTouch()' */
void WidgetSetHorizontalSlider_onDragTouch( WidgetSetHorizontalSlider _this, XObject 
  sender )
{
  XPoint delta;
  XInt32 maxPos;
  XInt32 oldValue;
  XInt32 newValue;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( !_this->touchActive )
    return;

  delta = EwMovePointNeg( _this->TouchHandler.CurrentPos, _this->TouchHandler.HittingPos );
  maxPos = EwGetRectW( _this->Super2.Bounds );
  oldValue = WidgetSetHorizontalSlider_OnGetCurrentValue( _this );
  newValue = oldValue;

  if (( _this->imageView != 0 ) && ( _this->imageView->Bitmap != 0 ))
    maxPos = maxPos - EwGetRectW( _this->imageView->Super1.Bounds );

  if ( maxPos > 0 )
    newValue = (XInt32)(((XFloat)delta.X * 100.000000f ) / (XFloat)maxPos ) + _this->touchStartValue;

  WidgetSetHorizontalSlider_OnSetCurrentValue( _this, newValue );

  if ( oldValue == WidgetSetHorizontalSlider_OnGetCurrentValue( _this ))
    return;
}

/* 'C' function for method : 'WidgetSet::HorizontalSlider.onReleaseTouch()' */
void WidgetSetHorizontalSlider_onReleaseTouch( WidgetSetHorizontalSlider _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( !_this->touchActive )
    return;

  _this->touchActive = 0;
  _this->KeyHandlerRight.Enabled = 1;
  _this->KeyHandlerLeft.Enabled = 1;
  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::HorizontalSlider.onPressTouch()' */
void WidgetSetHorizontalSlider_onPressTouch( WidgetSetHorizontalSlider _this, XObject 
  sender )
{
  XRect touchArea;
  XBool hasThumb;
  XBool insideThumb;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  touchArea = EwMoveRectPos( _Const0006, _this->TouchHandler.CurrentPos );
  hasThumb = (XBool)(( _this->imageView != 0 ) && ( _this->imageView->Bitmap != 
  0 ));
  insideThumb = (XBool)( hasThumb && !EwIsRectEmpty( EwIntersectRect( _this->imageView->Super1.Bounds, 
  touchArea )));

  if ( hasThumb && !insideThumb )
  {
    CoreRoot root = CoreView__GetRoot( _this );
    CoreSimpleTouchHandler_OnSetEnabled( &_this->TouchHandler, 0 );
    CoreRoot_RetargetCursor( root, ((CoreView)root ), 0 );
    CoreSimpleTouchHandler_OnSetEnabled( &_this->TouchHandler, 1 );
    return;
  }

  _this->touchActive = 1;
  _this->KeyHandlerRight.Enabled = 0;
  _this->KeyHandlerLeft.Enabled = 0;
  CoreGroup_InvalidateViewState((CoreGroup)_this );
  _this->touchStartValue = WidgetSetHorizontalSlider_OnGetCurrentValue( _this );
}

/* 'C' function for method : 'WidgetSet::HorizontalSlider.OnGetCurrentValue()' */
XInt32 WidgetSetHorizontalSlider_OnGetCurrentValue( WidgetSetHorizontalSlider _this )
{
  XInt32 value = _this->CurrentValue;

  if ( value < 0 )
    value = 0;

  if ( value > 100 )
    value = 100;

  return value;
}

/* 'C' function for method : 'WidgetSet::HorizontalSlider.OnSetCurrentValue()' */
void WidgetSetHorizontalSlider_OnSetCurrentValue( WidgetSetHorizontalSlider _this, 
  XInt32 value )
{
  if ( _this->CurrentValue == value )
    return;

  _this->CurrentValue = value;
  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::HorizontalSlider.OnSetAppearance()' */
void WidgetSetHorizontalSlider_OnSetAppearance( WidgetSetHorizontalSlider _this, 
  WidgetSetHorizontalSliderConfig value )
{
  if ( _this->Appearance == value )
    return;

  if ( _this->Appearance != 0 )
    EwDetachObjObserver( EwNewSlot( _this, WidgetSetHorizontalSlider_onConfigChanged ), 
      (XObject)_this->Appearance, 0 );

  _this->Appearance = value;

  if ( value != 0 )
    EwAttachObjObserver( EwNewSlot( _this, WidgetSetHorizontalSlider_onConfigChanged ), 
      (XObject)value, 0 );

  EwPostSignal( EwNewSlot( _this, WidgetSetHorizontalSlider_onConfigChanged ), ((XObject)_this ));
}

/* Variants derived from the class : 'WidgetSet::HorizontalSlider' */
EW_DEFINE_CLASS_VARIANTS( WidgetSetHorizontalSlider )
EW_END_OF_CLASS_VARIANTS( WidgetSetHorizontalSlider )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::HorizontalSlider' */
EW_DEFINE_CLASS( WidgetSetHorizontalSlider, CoreGroup, imageView, RepetitionTimer, 
                 RepetitionTimer, RepetitionTimer, touchStartValue, touchStartValue, 
                 "WidgetSet::HorizontalSlider" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  WidgetSetHorizontalSlider_OnSetBounds,
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
  WidgetSetHorizontalSlider_UpdateViewState,
  CoreGroup_InvalidateArea,
  CoreGroup_GetViewAtIndex,
  CoreGroup_CountViews,
  CoreGroup_FindNextView,
  CoreGroup_FindSiblingView,
  CoreGroup_RestackTop,
  CoreGroup_Restack,
  CoreGroup_Remove,
  CoreGroup_Add,
EW_END_OF_CLASS( WidgetSetHorizontalSlider )

/* Embedded Wizard */
