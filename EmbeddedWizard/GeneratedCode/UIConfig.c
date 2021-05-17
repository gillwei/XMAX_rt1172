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
#include "_ResourcesBitmap.h"
#include "_WidgetSetHorizontalSliderConfig.h"
#include "Resource.h"
#include "UIConfig.h"

/* User defined auto object: 'UIConfig::HorizontalSliderConfig' */
EW_DEFINE_AUTOOBJECT( UIConfigHorizontalSliderConfig, WidgetSetHorizontalSliderConfig )

/* Initializer for the auto object 'UIConfig::HorizontalSliderConfig' */
void UIConfigHorizontalSliderConfig__Init( WidgetSetHorizontalSliderConfig _this )
{
  WidgetSetHorizontalSliderConfig_OnSetThumbFocused( _this, EwLoadResource( &ResourceSeekBarDot, 
  ResourcesBitmap ));
  WidgetSetHorizontalSliderConfig_OnSetThumbDefault( _this, EwLoadResource( &ResourceSeekBarDot, 
  ResourcesBitmap ));
  WidgetSetHorizontalSliderConfig_OnSetTrackRightFrameFocused( _this, 0 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightFrameDefault( _this, 0 );
  WidgetSetHorizontalSliderConfig_OnSetTrackRightFocused( _this, EwLoadResource( 
  &ResourceSeekBar, ResourcesBitmap ));
  WidgetSetHorizontalSliderConfig_OnSetTrackRightDefault( _this, EwLoadResource( 
  &ResourceSeekBar, ResourcesBitmap ));
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftFrameFocused( _this, 1 );
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftFrameDefault( _this, 1 );
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftFocused( _this, EwLoadResource( 
  &ResourceSeekBar, ResourcesBitmap ));
  WidgetSetHorizontalSliderConfig_OnSetTrackLeftDefault( _this, EwLoadResource( 
  &ResourceSeekBar, ResourcesBitmap ));
}

/* Table with links to derived variants of the auto object : 'UIConfig::HorizontalSliderConfig' */
EW_DEFINE_AUTOOBJECT_VARIANTS( UIConfigHorizontalSliderConfig )
EW_END_OF_AUTOOBJECT_VARIANTS( UIConfigHorizontalSliderConfig )

/* Embedded Wizard */
