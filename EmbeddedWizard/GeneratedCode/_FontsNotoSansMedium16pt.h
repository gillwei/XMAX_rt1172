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
EW_DEFINE_FONT_RES( FontsNotoSansMedium16pt, 17, 5, 0, 4, 0x0001, 0x0060 )
  EW_GLYPH( 0x0001, 1, -12, 8, 12, 10, 0x00000000 ),
  EW_GLYPH( 0x0020, 0, 0, 0, 0, 4, 0x0000005E ),                /* ' ' */
  EW_GLYPH( 0x0021, 1, -12, 3, 12, 4, 0x0000005E ),             /* '!' */
  EW_GLYPH( 0x0022, 1, -12, 5, 4, 7, 0x00000085 ),              /* '"' */
  EW_GLYPH( 0x0023, 0, -12, 10, 12, 10, 0x000000A6 ),           /* '#' */
  EW_GLYPH( 0x0024, 0, -12, 9, 13, 9, 0x00000175 ),             /* '$' */
  EW_GLYPH( 0x0025, 0, -12, 13, 12, 14, 0x00000231 ),           /* '%' */
  EW_GLYPH( 0x0026, 0, -12, 12, 12, 12, 0x0000032F ),           /* '&' */
  EW_GLYPH( 0x0027, 1, -12, 2, 4, 4, 0x0000041E ),              /* ''' */
  EW_GLYPH( 0x0028, 0, -12, 5, 14, 5, 0x0000042B ),             /* '(' */
  EW_GLYPH( 0x0029, 0, -12, 5, 14, 5, 0x00000495 ),             /* ')' */
  EW_GLYPH( 0x002A, 0, -12, 9, 8, 9, 0x000004F8 ),              /* '*' */
  EW_GLYPH( 0x002B, 0, -10, 9, 8, 9, 0x00000573 ),              /* '+' */
  EW_GLYPH( 0x002C, 0, -2, 4, 4, 4, 0x000005C8 ),               /* ',' */
  EW_GLYPH( 0x002D, 0, -6, 5, 3, 5, 0x000005E7 ),               /* '-' */
  EW_GLYPH( 0x002E, 1, -3, 3, 3, 4, 0x00000607 ),               /* '.' */
  EW_GLYPH( 0x002F, 0, -12, 6, 12, 6, 0x00000612 ),             /* '/' */
  EW_GLYPH( 0x0030, 0, -12, 9, 12, 9, 0x00000681 ),             /* '0' */
  EW_GLYPH( 0x0031, 1, -12, 5, 12, 9, 0x0000072C ),             /* '1' */
  EW_GLYPH( 0x0032, 0, -12, 9, 12, 9, 0x0000076B ),             /* '2' */
  EW_GLYPH( 0x0033, 0, -12, 9, 12, 9, 0x0000081A ),             /* '3' */
  EW_GLYPH( 0x0034, 0, -12, 9, 12, 9, 0x000008D6 ),             /* '4' */
  EW_GLYPH( 0x0035, 0, -12, 9, 12, 9, 0x0000096C ),             /* '5' */
  EW_GLYPH( 0x0036, 0, -12, 9, 12, 9, 0x00000A22 ),             /* '6' */
  EW_GLYPH( 0x0037, 0, -12, 9, 12, 9, 0x00000AE4 ),             /* '7' */
  EW_GLYPH( 0x0038, 0, -12, 9, 12, 9, 0x00000B93 ),             /* '8' */
  EW_GLYPH( 0x0039, 0, -12, 9, 12, 9, 0x00000C6F ),             /* '9' */
  EW_GLYPH( 0x003A, 1, -9, 3, 9, 4, 0x00000D31 ),               /* ':' */
  EW_GLYPH( 0x003B, 0, -9, 4, 11, 4, 0x00000D4F ),              /* ';' */
  EW_GLYPH( 0x003C, 0, -10, 9, 9, 9, 0x00000D86 ),              /* '<' */
  EW_GLYPH( 0x003D, 0, -9, 9, 6, 9, 0x00000E0A ),               /* '=' */
  EW_GLYPH( 0x003E, 0, -10, 9, 9, 9, 0x00000E65 ),              /* '>' */
  EW_GLYPH( 0x003F, 0, -12, 7, 12, 7, 0x00000EE9 ),             /* '?' */
  EW_GLYPH( 0x0040, 0, -12, 14, 14, 14, 0x00000F6E ),           /* '@' */
  EW_GLYPH( 0x0041, 0, -12, 11, 12, 10, 0x000010D5 ),           /* 'A' */
  EW_GLYPH( 0x0042, 1, -12, 9, 12, 11, 0x000011B2 ),            /* 'B' */
  EW_GLYPH( 0x0043, 1, -12, 9, 12, 10, 0x00001272 ),            /* 'C' */
  EW_GLYPH( 0x0044, 1, -12, 10, 12, 12, 0x0000130C ),           /* 'D' */
  EW_GLYPH( 0x0045, 1, -12, 7, 12, 9, 0x000013B9 ),             /* 'E' */
  EW_GLYPH( 0x0046, 1, -12, 7, 12, 8, 0x00001445 ),             /* 'F' */
  EW_GLYPH( 0x0047, 1, -12, 10, 12, 12, 0x000014B7 ),           /* 'G' */
  EW_GLYPH( 0x0048, 1, -12, 10, 12, 12, 0x00001581 ),           /* 'H' */
  EW_GLYPH( 0x0049, 0, -12, 5, 12, 6, 0x000015EF ),             /* 'I' */
  EW_GLYPH( 0x004A, -2, -12, 6, 16, 5, 0x00001634 ),            /* 'J' */
  EW_GLYPH( 0x004B, 1, -12, 10, 12, 10, 0x00001687 ),           /* 'K' */
  EW_GLYPH( 0x004C, 1, -12, 8, 12, 9, 0x00001725 ),             /* 'L' */
  EW_GLYPH( 0x004D, 1, -12, 13, 12, 15, 0x00001775 ),           /* 'M' */
  EW_GLYPH( 0x004E, 1, -12, 10, 12, 12, 0x00001847 ),           /* 'N' */
  EW_GLYPH( 0x004F, 1, -12, 11, 12, 13, 0x000018E1 ),           /* 'O' */
  EW_GLYPH( 0x0050, 1, -12, 8, 12, 10, 0x000019B0 ),            /* 'P' */
  EW_GLYPH( 0x0051, 1, -12, 11, 15, 13, 0x00001A3D ),           /* 'Q' */
  EW_GLYPH( 0x0052, 1, -12, 9, 12, 10, 0x00001B34 ),            /* 'R' */
  EW_GLYPH( 0x0053, 0, -12, 9, 12, 9, 0x00001BE2 ),             /* 'S' */
  EW_GLYPH( 0x0054, 0, -12, 9, 12, 9, 0x00001C9F ),             /* 'T' */
  EW_GLYPH( 0x0055, 1, -12, 10, 12, 12, 0x00001D07 ),           /* 'U' */
  EW_GLYPH( 0x0056, 0, -12, 10, 12, 10, 0x00001D85 ),           /* 'V' */
  EW_GLYPH( 0x0057, 0, -12, 15, 12, 15, 0x00001E46 ),           /* 'W' */
  EW_GLYPH( 0x0058, 0, -12, 10, 12, 10, 0x00001F6D ),           /* 'X' */
  EW_GLYPH( 0x0059, 0, -12, 10, 12, 9, 0x00002041 ),            /* 'Y' */
  EW_GLYPH( 0x005A, 0, -12, 9, 12, 9, 0x000020DD ),             /* 'Z' */
  EW_GLYPH( 0x005B, 1, -12, 4, 15, 5, 0x000021A6 ),             /* '[' */
  EW_GLYPH( 0x005C, 0, -12, 6, 12, 6, 0x000021EC ),             /* '\' */
  EW_GLYPH( 0x005D, 0, -12, 4, 15, 5, 0x0000225B ),             /* ']' */
  EW_GLYPH( 0x005E, 0, -12, 9, 8, 9, 0x000022A5 ),              /* '^' */
  EW_GLYPH( 0x005F, 0, 0, 7, 3, 7, 0x0000230A ),                /* '_' */
  EW_GLYPH( 0x0060, 0, -13, 5, 3, 5, 0x00002335 ),              /* '`' */
  EW_GLYPH( 0x0061, 0, -9, 8, 9, 9, 0x0000234E ),               /* 'a' */
  EW_GLYPH( 0x0062, 1, -12, 9, 12, 10, 0x000023D4 ),            /* 'b' */
  EW_GLYPH( 0x0063, 0, -9, 8, 9, 8, 0x00002469 ),               /* 'c' */
  EW_GLYPH( 0x0064, 0, -12, 9, 12, 10, 0x000024DD ),            /* 'd' */
  EW_GLYPH( 0x0065, 0, -9, 9, 9, 9, 0x00002575 ),               /* 'e' */
  EW_GLYPH( 0x0066, 0, -12, 7, 12, 6, 0x0000260D ),             /* 'f' */
  EW_GLYPH( 0x0067, 0, -9, 9, 13, 10, 0x00002675 ),             /* 'g' */
  EW_GLYPH( 0x0068, 1, -12, 8, 12, 10, 0x00002741 ),            /* 'h' */
  EW_GLYPH( 0x0069, 1, -12, 3, 12, 4, 0x000027A6 ),             /* 'i' */
  EW_GLYPH( 0x006A, -1, -12, 5, 16, 4, 0x000027CE ),            /* 'j' */
  EW_GLYPH( 0x006B, 1, -12, 8, 12, 9, 0x00002822 ),             /* 'k' */
  EW_GLYPH( 0x006C, 1, -12, 2, 12, 4, 0x000028A2 ),             /* 'l' */
  EW_GLYPH( 0x006D, 1, -9, 13, 9, 15, 0x000028B4 ),             /* 'm' */
  EW_GLYPH( 0x006E, 1, -9, 8, 9, 10, 0x00002946 ),              /* 'n' */
  EW_GLYPH( 0x006F, 0, -9, 9, 9, 10, 0x0000299B ),              /* 'o' */
  EW_GLYPH( 0x0070, 1, -9, 9, 13, 10, 0x00002A27 ),             /* 'p' */
  EW_GLYPH( 0x0071, 0, -9, 9, 13, 10, 0x00002AD1 ),             /* 'q' */
  EW_GLYPH( 0x0072, 1, -9, 6, 9, 7, 0x00002B79 ),               /* 'r' */
  EW_GLYPH( 0x0073, 0, -9, 8, 9, 8, 0x00002BB5 ),               /* 's' */
  EW_GLYPH( 0x0074, 0, -11, 6, 11, 6, 0x00002C46 ),             /* 't' */
  EW_GLYPH( 0x0075, 1, -9, 8, 9, 10, 0x00002CA0 ),              /* 'u' */
  EW_GLYPH( 0x0076, 0, -9, 9, 9, 8, 0x00002CEA ),               /* 'v' */
  EW_GLYPH( 0x0077, 0, -9, 13, 9, 13, 0x00002D7D ),             /* 'w' */
  EW_GLYPH( 0x0078, 0, -9, 9, 9, 9, 0x00002E52 ),               /* 'x' */
  EW_GLYPH( 0x0079, 0, -9, 9, 13, 8, 0x00002EEC ),              /* 'y' */
  EW_GLYPH( 0x007A, 0, -9, 7, 9, 8, 0x00002FB3 ),               /* 'z' */
  EW_GLYPH( 0x007B, 0, -12, 6, 15, 6, 0x0000303B ),             /* '{' */
  EW_GLYPH( 0x007C, 3, -12, 3, 16, 9, 0x000030AF ),             /* '|' */
  EW_GLYPH( 0x007D, 0, -12, 6, 15, 6, 0x000030CB ),             /* '}' */
  EW_GLYPH( 0x007E, 0, -8, 9, 4, 9, 0x00003147 ),               /* '~' */

  EW_FONT_PIXEL( FontsNotoSansMedium16pt, 0x00003185 )          /* ratio 75.03 % */
    0xDF477BFF, 0x0000001B, 0xC6F7D000, 0xE5E04061, 0x181CEBE3, 0x4083A306, 0xF7FB00A9,
    0xF38F771F, 0xFF6C4F5C, 0x7FF5DF79, 0x4365FF7E, 0x418041ED, 0x67C754C5, 0x9582C9E6,
    0x6649D8D4, 0xFFC22B52, 0x33B7B7D9, 0xA17C017E, 0xA954FE43, 0x0220B8F9, 0xF954F276,
    0xCBE79F72, 0x1A6FFF8C, 0x4740CA97, 0xE1FFDB41, 0x05FD2EE8, 0x9FFC4EF2, 0xEFC6C23F,
    0xC8993C2D, 0x499DD9D0, 0x8699EE8D, 0xCCFBD47C, 0xE67679D0, 0xA3DAF1B7, 0x440D4B1E,
    0x2C350220, 0xC3A3D8F5, 0x161A8F55, 0x4B022044, 0x6A5C7A8D, 0xB8F12820, 0xFA3D1BF9,
    0x9F7276A7, 0x0061F1D4, 0xB59C7714, 0x04437D7F, 0x8D443D00, 0xFFAEEA0A, 0xF1F09D0D,
    0x1A876557, 0xABF8309E, 0x4C2A1EC7, 0x76F0BFBC, 0xBFDF7EC7, 0x14101DBF, 0xDBF88140,
    0xD7FBEFD1, 0xC747A1DD, 0x0053F55B, 0xC2FEF000, 0x7CF475F9, 0x0CF000FF, 0xBA5FA1FA,
    0xF3F7A6E9, 0xFA6FBE78, 0x1D7F217E, 0xA03FDF3D, 0xFC37BAB6, 0x04DEA4CF, 0xBEF3EF6C,
    0x3D074FB5, 0x0E42C0A8, 0x2E83D922, 0xFDC625EA, 0x7E6F77F5, 0x2EF75028, 0x13D42FBE,
    0xFEEA1B0A, 0xCABDF9F4, 0xFD1D801B, 0x74F77FBC, 0xFCE96FA8, 0x563E77A9, 0x1FFFFE00,
    0xFC76D7E3, 0xAABF841F, 0xBEE967EE, 0x3EF7BFF9, 0x9EAB37DF, 0x7E8350A7, 0x3B0447F0,
    0x50563FA8, 0xFEF07E83, 0xDCBFDBC2, 0xEC40F3EF, 0xF3DEFEA7, 0x9C873585, 0xA0CC3599,
    0x9C567AD4, 0x2FEF4DDF, 0x9E8EBFBC, 0x203B1FEF, 0xDF7AFEFE, 0x16166FA1, 0x1EF9E19E,
    0x3E3E7E6F, 0x3A4E93A0, 0xF1A93A01, 0x50EF0A04, 0x53BDE7E7, 0xE0BF7077, 0x0B3A93BD,
    0xEF7B806F, 0xB05EF7D8, 0xBDEEBDEF, 0xF417E0A3, 0x05F9D49D, 0xAC77876F, 0x49DD373A,
    0xDACCFA07, 0x0E67DF39, 0x3D2FA4F0, 0x51F87ED3, 0xBE7D00F8, 0x7C6FC6A0, 0x3BCF7FFC,
    0xDBE757C2, 0x8ABBA3A3, 0x1550E731, 0xC554015B, 0x1BF90A36, 0xDFECEC77, 0x42FA8BFB,
    0x45EF7FE1, 0x0383FB9D, 0x30FEA2F5, 0x9FC6A09E, 0x4430767A, 0xDB77FE78, 0xE78337EF,
    0xFF9278C9, 0xEFFC760E, 0x4BF7F42F, 0xA88133CF, 0xF3A66FA5, 0x20FFE56B, 0x8ACF3C50,
    0xF3EA46FE, 0xDFA3EFF9, 0x42C6ADE7, 0xBA141401, 0x7AF3EFD1, 0xBFBFF1F7, 0x9E3F3BE0,
    0x41FB1327, 0xA360006D, 0x779E3F60, 0xFE7C6FA4, 0x3EFE8EF7, 0xF41013CF, 0x028DCE5D,
    0xBFA279E0, 0xE8EF7FEF, 0x013CF3EF, 0x7D1B9C28, 0x75000097, 0x72FCE17E, 0x3E6F3F74,
    0xF4010589, 0x8A7FA15D, 0x9F7E8992, 0x78DF8D57, 0x000058FE, 0xC7F738A1, 0x01423FB9,
    0x5DFF8000, 0x00002FF9, 0x06AFE350, 0x00000000, 0xEE47B1D8, 0xC0FF3F9F, 0x4991BA0A,
    0x07A83E35, 0x26623FBF, 0x21FD41FA, 0x00000FF3, 0x3CF00000, 0x3FF2FBE1, 0xF8B04BA8,
    0x7F50EC53, 0x55FC5C22, 0x1102A3B0, 0xD815FE17, 0x07F3C06F, 0x79F27F82, 0x51330FE0,
    0x2B0FFA0F, 0x7BA0C4F1, 0xD81981E0, 0xEEF267BC, 0xF3EFD3F3, 0x0A3B3776, 0x285000F1,
    0xA3B36F05, 0xEF6DE7DF, 0xFBFF3F3E, 0xCF4C6F85, 0x44A147FB, 0x9D319DFF, 0xC000085F,
    0x3EEF267B, 0x6F3EFD3F, 0x10A3B377, 0x5285000F, 0xFA3B36F0, 0xEEF6DE7D, 0x404F79AF,
    0xBFF2F437, 0xE1D3E85F, 0x2810FF79, 0x9DCE19E5, 0x8991157A, 0xFD1FD415, 0xFBD37F7A,
    0x4CF3F61B, 0xBF307A81, 0xCDE4EBE0, 0x9FA20AA4, 0x8E9F6FF7, 0xBEFDEF73, 0x0F0ABEFC,
    0x00000000, 0x00B53F80, 0x00000000, 0x7F476115, 0xA7951CCF, 0x516FC3E3, 0x6A7EC23B,
    0x56443B28, 0x566DFC59, 0xA83FC43D, 0x504FD831, 0xF43FC7C5, 0x8FF37B09, 0xD5FC4450,
    0x1E7A83B2, 0x51A8C32C, 0xA9556355, 0x52855555, 0xEE1FFD9B, 0x8822089F, 0x3A1FE110,
    0x9746A19F, 0xF2F57E19, 0xA247609C, 0xEF9267B0, 0xF6FEFEA3, 0x7ED23323, 0xA8673A3E,
    0x77466951, 0x43F679FD, 0x413D41CE, 0x6000006F, 0xFBE37BDF, 0xBCF3D566, 0xD833C198,
    0x1FD4DD0F, 0x7E92782B, 0xFBEAA79E, 0x27D5F9E6, 0x7EA00000, 0xA931F7E7, 0xF87A87B0,
    0x0D427833, 0xFFF1543B, 0x006A37DF, 0xFF3FC000, 0xFD8BC097, 0x93BB8D52, 0x7AE1E888,
    0x7BDF6154, 0x42A3BDEF, 0x17F78FAB, 0xFDF34E6E, 0xFBA37383, 0xBD6A2D46, 0x07F1DF76,
    0xE4E4CE00, 0x84399FB4, 0x88A186C2, 0xFF5FEF5A, 0x3597F43A, 0x593EFDAE, 0xEC1A8030,
    0x03CAC9F7, 0x49D4003B, 0xF9AD2795, 0xF00D8457, 0x0CFBF657, 0xFF42FF6F, 0xF45FEEC2,
    0xFE027CFB, 0x5DEEA337, 0x949F3905, 0xD3FBCBBF, 0xF2A7EC3D, 0x28A7BFC4, 0xFBC00000,
    0x67FB78EB, 0x57F2CFBF, 0xD610D400, 0x433CABFC, 0x7DE1099D, 0xD3ED4FFE, 0xBFD000FE,
    0xD6B393A8, 0x000017FB, 0x6AA35BC0, 0x0D578000, 0x000006A5, 0x676A7B60, 0x274001FE,
    0x3BCFEA99, 0xC97EA0D5, 0xFD9322F3, 0xF6F001FC, 0xFF4FDE2F, 0xD6A78CFA, 0xC4A39CDF,
    0x00000000, 0x70BFDBC0, 0xFF7AD672, 0xD0000002, 0x647BDA5F, 0x3F8CCFBF, 0xD451B07F,
    0xF23EF9C8, 0xA17FB7B6, 0xDEB51D7F, 0xB03022BF, 0xCCFFE509, 0x6714E4E1, 0xBFBC0002,
    0xB17FB78E, 0xC50867DF, 0xD610D400, 0xA93CABFC, 0xDE00024E, 0x15ACCE5E, 0xF7C00002,
    0xD6A9DE8B, 0xFBE8B51B, 0x1FE4CDE3, 0x6FC3FCFD, 0x7BBC24A4, 0x015DCF45, 0x1C8FD500,
    0x00001F87, 0xDE37C8C0, 0x77FC7D7D, 0xBF84F1D8, 0x0EC7622D, 0x4FB9FC4F, 0xE5EA3FA8,
    0x87FECB53, 0x2D444A35, 0xED4F5FE2, 0x2BF946D8, 0xA7AA8AE3, 0x614B50DE, 0xF0EC350D,
    0xEF593CF9, 0xF536FD0E, 0xCAC19EA7, 0x19E2B994, 0xDFF1F7F5, 0xF0CF1D8F, 0xB3D44437,
    0xE33F8D43, 0xFD47F509, 0xDEA18151, 0xF7D8D7E2, 0x67A9F7E6, 0x8FD867A5, 0x9EB2F56E,
    0x54BF79E7, 0xA0245BD3, 0x6DEDFE18, 0x3C202835, 0x000DAF53, 0x7FC37800, 0x56003FAA,
    0x67EF3F78, 0xFB7F8005, 0x8F3E7027, 0x7BE46FBB, 0x00000013

  EW_FONT_KERNING_CODES( FontsNotoSansMedium16pt )
  EW_FONT_KERNING_VALUES( FontsNotoSansMedium16pt )
EW_END_OF_FONT_RES( FontsNotoSansMedium16pt )

/* Embedded Wizard */
