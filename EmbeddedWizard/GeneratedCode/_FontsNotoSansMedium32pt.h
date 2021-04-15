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

/* This is a font resource. */
EW_DEFINE_FONT_RES( FontsNotoSansMedium32pt, 34, 9, 0, 4, 0x0001, 0x000D )
  EW_GLYPH( 0x0001, 3, -23, 14, 23, 19, 0x00000000 ),
  EW_GLYPH( 0x002D, 1, -10, 9, 3, 10, 0x0000012D ),             /* '-' */
  EW_GLYPH( 0x0030, 1, -23, 16, 23, 18, 0x00000161 ),           /* '0' */
  EW_GLYPH( 0x0031, 2, -23, 10, 23, 18, 0x00000322 ),           /* '1' */
  EW_GLYPH( 0x0032, 1, -23, 16, 23, 18, 0x000003D9 ),           /* '2' */
  EW_GLYPH( 0x0033, 1, -23, 16, 23, 18, 0x000005B1 ),           /* '3' */
  EW_GLYPH( 0x0034, 0, -23, 18, 23, 18, 0x000007B7 ),           /* '4' */
  EW_GLYPH( 0x0035, 1, -23, 16, 23, 18, 0x00000976 ),           /* '5' */
  EW_GLYPH( 0x0036, 1, -23, 16, 23, 18, 0x00000B46 ),           /* '6' */
  EW_GLYPH( 0x0037, 1, -23, 16, 23, 18, 0x00000D55 ),           /* '7' */
  EW_GLYPH( 0x0038, 1, -23, 16, 23, 18, 0x00000F04 ),           /* '8' */
  EW_GLYPH( 0x0039, 1, -23, 16, 23, 18, 0x0000114B ),           /* '9' */
  EW_GLYPH( 0x003A, 2, -18, 5, 18, 9, 0x00001358 ),             /* ':' */

  EW_FONT_PIXEL( FontsNotoSansMedium32pt, 0x000013CF )          /* ratio 63.17 % */
    0xEF7BDEF7, 0x9E79E7A8, 0xEFBEFEC7, 0x0000003B, 0x00000000, 0x00000000, 0x00000000,
    0xDF7DFD80, 0x3CF3D477, 0xBEFBE3CF, 0x013CF3CF, 0xD40BF3A8, 0xAF04EA2F, 0xBF51930A,
    0x65E2AD13, 0x29B06DCA, 0x10807941, 0x00303605, 0x00000000, 0x40D81443, 0x6DA94128,
    0xCBC545B0, 0x4EFD6434, 0xF0A8E854, 0x3FD45F52, 0x13A3FFE1, 0xACD41D13, 0x9DD2F1D4,
    0x000002D4, 0x00000000, 0x78000000, 0xCEF12FCF, 0xE9EA7FA8, 0xDFFE2F09, 0x937E8A89,
    0x00D89869, 0x806D8000, 0x740B2012, 0x5091E0BC, 0xA135E0D9, 0x135E03B2, 0x35E03B2A,
    0x5E03B2A1, 0xBEFBEFFF, 0x9E79E78F, 0xCF780027, 0xA8CCE26F, 0x84F0ED37, 0x4EF9D757,
    0x782FD456, 0x0001B00C, 0x159A80DB, 0xF9EFDF7C, 0x00DE3CF0, 0xFEF713FE, 0x69A80DE2,
    0x0100F680, 0xD5A00800, 0xCEA2981B, 0x49513BEF, 0x9FF5E13D, 0xD024E78F, 0xA8098037,
    0xF2017400, 0xA05C540F, 0x817C802B, 0x153C018E, 0x8E8178C0, 0x8C069E04, 0x8127E807,
    0xCBBDEEA7, 0x9E7801F9, 0xCF1E79E7, 0xFBEFBFBF, 0x00026FD2, 0x73800000, 0x0017BDEF,
    0x43CF3CF5, 0x1F7DF7F4, 0x14000200, 0x80BEFA80, 0x024E79F7, 0xF7BBF55E, 0x9A8A9517,
    0x0202B402, 0x05100000, 0x1A60745A, 0x89DF7E75, 0xD44F528A, 0xF9E3E7A7, 0x3FBBEA02,
    0xF851EFD4, 0xF47413D4, 0xB53C3BEF, 0xE2A0D8C0, 0xC400DB01, 0xCF4A3E7B, 0xD4F51678,
    0xFE6A23A3, 0xE97925BE, 0x03631228, 0x04A00004, 0x76206D86, 0xCC7B4BC5, 0x52AB7DFA,
    0x7C5E3D47, 0xDCE9BD4F, 0x3FBDEF7B, 0xCF3CF580, 0xFBF784F3, 0x41B3EFBE, 0x01B603C5,
    0x36300A9E, 0x805A0510, 0xB00B2092, 0xB603C541, 0x300A9E01, 0x5B068A80, 0x56403280,
    0x3CA0D880, 0x137E7BC0, 0x64DEA33D, 0xA2ABC7AA, 0xDCACDF7F, 0x4182FE1E, 0xD06D8801,
    0x4ACCBC54, 0xBC6F7EB3, 0x04ECD474, 0x9F78DE36, 0xFCF66A9A, 0xF26D8DE2, 0x8A82A7C9,
    0x5006C602, 0xD263F630, 0x7DFBDB51, 0x3CF4D64B, 0xA8CEF0DE, 0x5F3DE277, 0x5F3C67A0,
    0x53513D30, 0x689DFBC7, 0x54653165, 0x028011D0, 0x28EC6006, 0x3F932854, 0x4C9DFBDB,
    0xDAF13D35, 0x81CDE9DE, 0x51004EF7, 0x06D804A0, 0xC6F01598, 0x599DF7CB, 0x1BC27A83,
    0xFD24E794, 0xF980F3F5, 0x000097C4, 0x809F397C, 0x00001E7E

  EW_FONT_KERNING_CODES( FontsNotoSansMedium32pt )
  EW_FONT_KERNING_VALUES( FontsNotoSansMedium32pt )
EW_END_OF_FONT_RES( FontsNotoSansMedium32pt )

/* Embedded Wizard */
