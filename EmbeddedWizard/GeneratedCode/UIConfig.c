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
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_WidgetSetPushButtonConfig.h"
#include "_WidgetSetToggleButtonConfig.h"
#include "Core.h"
#include "Fonts.h"
#include "Resource.h"
#include "UIConfig.h"

/* Constant values used in this 'C' module only. */
static const XColor _Const0000 = { 0xFF, 0xFF, 0xFF, 0xFF };

/* User defined auto object: 'UIConfig::PushButtonConfig' */
EW_DEFINE_AUTOOBJECT( UIConfigPushButtonConfig, WidgetSetPushButtonConfig )

/* Initializer for the auto object 'UIConfig::PushButtonConfig' */
void UIConfigPushButtonConfig__Init( WidgetSetPushButtonConfig _this )
{
  WidgetSetPushButtonConfig_OnSetKeyCode( _this, CoreKeyCodeOk );
  WidgetSetPushButtonConfig_OnSetLabelColorActive( _this, _Const0000 );
  WidgetSetPushButtonConfig_OnSetLabelColorFocused( _this, _Const0000 );
  WidgetSetPushButtonConfig_OnSetLabelColorDisabled( _this, _Const0000 );
  WidgetSetPushButtonConfig_OnSetLabelColorDefault( _this, _Const0000 );
  WidgetSetPushButtonConfig_OnSetLabelFont( _this, EwLoadResource( &FontsFontNotoSansCjkJp32, 
  ResourcesFont ));
  WidgetSetPushButtonConfig_OnSetFaceLayout( _this, CoreLayoutAlignToBottom | CoreLayoutAlignToLeft 
  | CoreLayoutAlignToRight | CoreLayoutAlignToTop | CoreLayoutResizeHorz | CoreLayoutResizeVert );
  WidgetSetPushButtonConfig_OnSetFaceFrameActive( _this, 1 );
  WidgetSetPushButtonConfig_OnSetFaceActive( _this, EwLoadResource( &ResourceFocusFrame, 
  ResourcesBitmap ));
  WidgetSetPushButtonConfig_OnSetFaceFocused( _this, EwLoadResource( &ResourceFocusFrame, 
  ResourcesBitmap ));
}

/* Table with links to derived variants of the auto object : 'UIConfig::PushButtonConfig' */
EW_DEFINE_AUTOOBJECT_VARIANTS( UIConfigPushButtonConfig )
EW_END_OF_AUTOOBJECT_VARIANTS( UIConfigPushButtonConfig )

/* User defined auto object: 'UIConfig::CheckBoxConfig' */
EW_DEFINE_AUTOOBJECT( UIConfigCheckBoxConfig, WidgetSetToggleButtonConfig )

/* Initializer for the auto object 'UIConfig::CheckBoxConfig' */
void UIConfigCheckBoxConfig__Init( WidgetSetToggleButtonConfig _this )
{
  WidgetSetToggleButtonConfig_OnSetKeyCode( _this, CoreKeyCodeNoKey );
  WidgetSetToggleButtonConfig_OnSetFaceOnFrameActive( _this, 1 );
  WidgetSetToggleButtonConfig_OnSetFaceOnFrameFocused( _this, 1 );
  WidgetSetToggleButtonConfig_OnSetFaceOnFrameDisabled( _this, 1 );
  WidgetSetToggleButtonConfig_OnSetFaceOnFrameDefault( _this, 1 );
  WidgetSetToggleButtonConfig_OnSetFaceOnActive( _this, 0 );
  WidgetSetToggleButtonConfig_OnSetFaceOnFocused( _this, 0 );
  WidgetSetToggleButtonConfig_OnSetFaceOnDisabled( _this, EwLoadResource( &ResourceCheckboxDisable, 
  ResourcesBitmap ));
  WidgetSetToggleButtonConfig_OnSetFaceOnDefault( _this, EwLoadResource( &ResourceCheckboxNormal, 
  ResourcesBitmap ));
  WidgetSetToggleButtonConfig_OnSetFaceOffFrameActive( _this, 0 );
  WidgetSetToggleButtonConfig_OnSetFaceOffFrameFocused( _this, 0 );
  WidgetSetToggleButtonConfig_OnSetFaceOffFrameDisabled( _this, 0 );
  WidgetSetToggleButtonConfig_OnSetFaceOffFrameDefault( _this, 0 );
  WidgetSetToggleButtonConfig_OnSetFaceOffActive( _this, 0 );
  WidgetSetToggleButtonConfig_OnSetFaceOffFocused( _this, 0 );
  WidgetSetToggleButtonConfig_OnSetFaceOffDisabled( _this, EwLoadResource( &ResourceCheckboxDisable, 
  ResourcesBitmap ));
  WidgetSetToggleButtonConfig_OnSetFaceOffDefault( _this, EwLoadResource( &ResourceCheckboxNormal, 
  ResourcesBitmap ));
}

/* Table with links to derived variants of the auto object : 'UIConfig::CheckBoxConfig' */
EW_DEFINE_AUTOOBJECT_VARIANTS( UIConfigCheckBoxConfig )
EW_END_OF_AUTOOBJECT_VARIANTS( UIConfigCheckBoxConfig )

/* Embedded Wizard */
