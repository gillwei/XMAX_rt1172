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
#include "_UtilityString.h"
#include "Strings.h"
#include "Utility.h"

/* Initializer for the class 'Utility::String' */
void UtilityString__Init( UtilityString _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( UtilityString );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( UtilityString );
}

/* Re-Initializer for the class 'Utility::String' */
void UtilityString__ReInit( UtilityString _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Utility::String' */
void UtilityString__Done( UtilityString _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* Replace %s in String1 with String2 */
XString UtilityString_ReplaceString( UtilityString _this, XString String1, XString 
  String2 )
{
  XString ResultString;
  XInt32 LeftIdx;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  LeftIdx = EwStringFind( String1, EwLoadString( &StringsARGUMENT_STR ), 0 );

  if ( LeftIdx >= 0 )
  {
    XInt32 RightIdx = ( EwGetStringLength( String1 ) - LeftIdx ) - EwGetStringLength( 
      EwLoadString( &StringsARGUMENT_STR ));
    ResultString = EwConcatString( EwConcatString( EwStringLeft( String1, LeftIdx ), 
    String2 ), EwStringRight( String1, RightIdx ));
  }
  else
    ResultString = String1;

  return ResultString;
}

/* Variants derived from the class : 'Utility::String' */
EW_DEFINE_CLASS_VARIANTS( UtilityString )
EW_END_OF_CLASS_VARIANTS( UtilityString )

/* Virtual Method Table (VMT) for the class : 'Utility::String' */
EW_DEFINE_CLASS( UtilityString, XObject, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, 
                 "Utility::String" )
EW_END_OF_CLASS( UtilityString )

/* Embedded Wizard */
