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

/* This is a font resource. */
EW_DEFINE_FONT_RES( FontsNotoSansMedium32pt, 34, 9, 0, 4, 0x0001, 0x0011 )
  EW_GLYPH( 0x0001, 3, -23, 14, 23, 19, 0x00000000 ),
  EW_GLYPH( 0x002D, 1, -10, 9, 3, 10, 0x0000012D ),             /* '-' */
  EW_GLYPH( 0x002F, 0, -23, 12, 23, 12, 0x00000161 ),           /* '/' */
  EW_GLYPH( 0x0030, 1, -23, 16, 23, 18, 0x00000291 ),           /* '0' */
  EW_GLYPH( 0x0031, 2, -23, 10, 23, 18, 0x00000452 ),           /* '1' */
  EW_GLYPH( 0x0032, 1, -23, 16, 23, 18, 0x00000509 ),           /* '2' */
  EW_GLYPH( 0x0033, 1, -23, 16, 23, 18, 0x000006E1 ),           /* '3' */
  EW_GLYPH( 0x0034, 0, -23, 18, 23, 18, 0x000008E7 ),           /* '4' */
  EW_GLYPH( 0x0035, 1, -23, 16, 23, 18, 0x00000AA6 ),           /* '5' */
  EW_GLYPH( 0x0036, 1, -23, 16, 23, 18, 0x00000C76 ),           /* '6' */
  EW_GLYPH( 0x0037, 1, -23, 16, 23, 18, 0x00000E85 ),           /* '7' */
  EW_GLYPH( 0x0038, 1, -23, 16, 23, 18, 0x00001034 ),           /* '8' */
  EW_GLYPH( 0x0039, 1, -23, 16, 23, 18, 0x0000127B ),           /* '9' */
  EW_GLYPH( 0x003A, 2, -18, 5, 18, 9, 0x00001488 ),             /* ':' */
  EW_GLYPH( 0x0041, 0, -23, 21, 23, 21, 0x000014FF ),           /* 'A' */
  EW_GLYPH( 0x004D, 3, -23, 24, 23, 29, 0x00001732 ),           /* 'M' */
  EW_GLYPH( 0x0050, 3, -23, 15, 23, 20, 0x00001960 ),           /* 'P' */

  EW_FONT_PIXEL( FontsNotoSansMedium32pt, 0x00001AD3 )          /* ratio 60.53 % */
    0xEF7BDEF7, 0x9E79E7A8, 0xEFBEFEC7, 0x0000003B, 0x00000000, 0x00000000, 0x00000000,
    0xDF7DFD80, 0x3CF3D477, 0xBEFBE3CF, 0x013CF3CF, 0xB183FFE0, 0xB0250A21, 0x6205540D,
    0x045428C3, 0x4F0201B6, 0x0F10D8C1, 0xA816C0CA, 0x50A0DC82, 0xAA06D811, 0xF3A80102,
    0xEA2FD40B, 0x930AAF04, 0xAD13BF51, 0x6DCA65E2, 0x794129B0, 0x36051080, 0x00000030,
    0x14430000, 0x412840D8, 0x45B06DA9, 0x6434CBC5, 0xE8544EFD, 0x5F52F0A8, 0xFFE13FD4,
    0x1D1313A3, 0xF1D4ACD4, 0x02D49DD2, 0x00000000, 0x00000000, 0x2FCF7800, 0x7FA8CEF1,
    0x2F09E9EA, 0x8A89DFFE, 0x9869937E, 0x800000D8, 0x2012806D, 0xE0BC740B, 0xE0D95091,
    0x03B2A135, 0x3B2A135E, 0xB2A135E0, 0xEFFF5E03, 0xE78FBEFB, 0x00279E79, 0xE26FCF78,
    0xED37A8CC, 0xD75784F0, 0xD4564EF9, 0xB00C782F, 0x80DB0001, 0xDF7C159A, 0x3CF0F9EF,
    0x13FE00DE, 0x0DE2FEF7, 0xF68069A8, 0x08000100, 0x981BD5A0, 0x3BEFCEA2, 0xE13D4951,
    0xE78F9FF5, 0x8037D024, 0x7400A809, 0x540FF201, 0x802BA05C, 0x018E817C, 0x78C0153C,
    0x9E048E81, 0xE8078C06, 0xEEA78127, 0x01F9CBBD, 0x79E79E78, 0xBFBFCF1E, 0x6FD2FBEF,
    0x00000002, 0xBDEF7380, 0x3CF50017, 0xF7F443CF, 0x02001F7D, 0xFA801400, 0x79F780BE,
    0xF55E024E, 0x9517F7BB, 0xB4029A8A, 0x00000202, 0x745A0510, 0x7E751A60, 0x528A89DF,
    0xE7A7D44F, 0xEA02F9E3, 0xEFD43FBB, 0x13D4F851, 0x3BEFF474, 0xD8C0B53C, 0xDB01E2A0,
    0x3E7BC400, 0x1678CF4A, 0x23A3D4F5, 0x25BEFE6A, 0x1228E979, 0x00040363, 0x6D8604A0,
    0x4BC57620, 0x7DFACC7B, 0x3D4752AB, 0xBD4F7C5E, 0xEF7BDCE9, 0xF5803FBD, 0x84F3CF3C,
    0xEFBEFBF7, 0x03C541B3, 0x0A9E01B6, 0x05103630, 0x2092805A, 0xC541B00B, 0x9E01B603,
    0x8A80300A, 0x32805B06, 0xD8805640, 0x7BC03CA0, 0xA33D137E, 0xC7AA64DE, 0xDF7FA2AB,
    0xFE1EDCAC, 0x88014182, 0xBC54D06D, 0x7EB34ACC, 0xD474BC6F, 0xDE3604EC, 0x6A9A9F78,
    0x8DE2FCF6, 0xA7C9F26D, 0xC6028A82, 0xF6305006, 0xDB51D263, 0xD64B7DFB, 0xF0DE3CF4,
    0xE277A8CE, 0x67A05F3D, 0x3D305F3C, 0xFBC75351, 0x3165689D, 0x11D05465, 0x60060280,
    0x285428EC, 0xFBDB3F93, 0x3D354C9D, 0xE9DEDAF1, 0x4EF781CD, 0x04A05100, 0x159806D8,
    0xF7CBC6F0, 0x7A83599D, 0xE7941BC2, 0xF3F5FD24, 0x97C4F980, 0x397C0000, 0x1E7E809F,
    0x6C00DFF8, 0x2004201B, 0x6E5B004A, 0x802222A0, 0x2504B7B1, 0x1E212802, 0x406DB630,
    0xDA0A7855, 0x1B628140, 0x37DF7C78, 0xCF3D5B0A, 0xA20011A3, 0x5577BDEE, 0x4D8C06D8,
    0x05909414, 0xD8C0304A, 0x8C4A0515, 0x3BDE4A02, 0x05177380, 0x50506C04, 0x0B60B605,
    0x101942A8, 0x3C60221B, 0x20420A30, 0x55425A36, 0x7836C0A0, 0x05182836, 0x300443C4,
    0xA78032B6, 0x5510016C, 0x03623680, 0x60078C44, 0x28800C74, 0xC00A5001, 0x029401B6,
    0x05FBDEF7, 0xCF5277A8, 0xEFBF26A3, 0x2535094C, 0x14016C00, 0x50D880D8, 0x9DF7E159,
    0x479EA959, 0xD25F3C25, 0x000337F7, 0x00000000, 0x00000000

  EW_FONT_KERNING_CODES( FontsNotoSansMedium32pt )
  EW_FONT_KERNING_VALUES( FontsNotoSansMedium32pt )
EW_END_OF_FONT_RES( FontsNotoSansMedium32pt )

/* Embedded Wizard */
