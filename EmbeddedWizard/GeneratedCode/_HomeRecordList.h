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

#ifndef _HomeRecordList_H
#define _HomeRecordList_H

#ifdef __cplusplus
  extern "C"
  {
#endif

#include "ewrte.h"
#if EW_RTE_VERSION != 0x000B0000
  #error Wrong version of Embedded Wizard Runtime Environment.
#endif

#include "ewgfx.h"
#if EW_GFX_VERSION != 0x000B0000
  #error Wrong version of Embedded Wizard Graphics Engine.
#endif

/* Forward declaration of the class Home::Record */
#ifndef _HomeRecord_
  EW_DECLARE_CLASS( HomeRecord )
#define _HomeRecord_
#endif

/* Forward declaration of the class Home::RecordList */
#ifndef _HomeRecordList_
  EW_DECLARE_CLASS( HomeRecordList )
#define _HomeRecordList_
#endif


/* Deklaration of class : 'Home::RecordList' */
EW_DEFINE_FIELDS( HomeRecordList, XObject )
  EW_VARIABLE( firstRecord,     HomeRecord )
  EW_VARIABLE( lastRecord,      HomeRecord )
  EW_PROPERTY( NoOfItems,       XInt32 )
EW_END_OF_FIELDS( HomeRecordList )

/* Virtual Method Table (VMT) for the class : 'Home::RecordList' */
EW_DEFINE_METHODS( HomeRecordList, XObject )
EW_END_OF_METHODS( HomeRecordList )

/* The method 'ClearList' is used to clear the list of records. */
void HomeRecordList_ClearList( HomeRecordList _this );

/* The method GetRecord returns the record object with the given index. */
HomeRecord HomeRecordList_GetRecord( HomeRecordList _this, XInt32 aIndex );

/* 'C' function for method : 'Home::RecordList.AddRecord()' */
void HomeRecordList_AddRecord( HomeRecordList _this, XFloat aValue );

/* 'C' function for method : 'Home::RecordList.RemoveRecord()' */
void HomeRecordList_RemoveRecord( HomeRecordList _this );

#ifdef __cplusplus
  }
#endif

#endif /* _HomeRecordList_H */

/* Embedded Wizard */
