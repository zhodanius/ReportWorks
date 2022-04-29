// ****************************************************************************
//
//      (C) Copyright 1992-1993 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
//	NON-TRANSLATED text goes here (translated in RRW.STR)
// XBase specific strings
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/xglobal.h_v  $
// 
//    Rev 1.5   05 Jan 1996 16:31:20   par
// All explicitly linked modules and external initialization files are located
// with the explicit file manager.  This will provide a central location where
// file paths can be adjusted.
// 
//    Rev 1.4   30 Nov 1995 15:06:46   sbc
// Move printer driver name to global.h now that it's common
// 
//    Rev 1.3   27 Nov 1995 13:47:32   smh
// rrwexp.dll -> rrtxtx.dll
// 
//    Rev 1.2   08 Nov 1995 15:42:36   dlm
// Added WxRepExt to hold compound file extension (.RRW).
// 
//    Rev 1.1   26 Jul 1995 09:11:18   pjm
// Made Global character arrays near.
// 
//    Rev 1.0   16 Mar 1995 16:14:10   sbc
// Initial revision.
// 
//    Rev 1.14   10 Jan 1995 14:40:36   sbc
// Remove unused "WxDefPgL[] & WxDefPgW[]
// 
//    Rev 1.13   20 Sep 1994 14:01:22   pjm
// Added WxIgnU (IgnoreU) for ignoring unknown DBF data types in RRW.
// 
//    Rev 1.12   14 Sep 1994 16:06:26   smh
// RT5, the template library extension.
// 
//    Rev 1.11   06 May 1994 16:19:44   sbc
// RRWRUN needs ASCII runout string
// 
//    Rev 1.10   24 Mar 1994 09:34:12   erp
// removed include of version.h
// 
//    Rev 1.9   24 Mar 1994 09:27:30   erp
// moved WxVersion to version.h
// 
//    Rev 1.8   23 Mar 1994 15:01:36   erp
// added single version change
// 
//    Rev 1.7   16 Mar 1994 15:55:50   erp
// changed the version number
// 
//    Rev 1.6   16 Mar 1994 15:35:46   dlm
// From Abra branch, added RRWABRA.INI as name of ini file, conditional
//  on ABRA.
// 
//    Rev 1.5   10 Mar 1994 12:02:04   sbc
// Change version numbers: 2.0.04 -> 3.0.01 & 3.0.00 -> 4.0.00
// 
//    Rev 1.4   15 Feb 1994 09:33:34   mjs
// Updated version number for RRMFC.
// 
//    Rev 1.3   19 Nov 1993 17:35:46   sbc
// Add extern C for C++
// 
//    Rev 1.2   03 Nov 1993 11:33:14   say
// Bracket file with #ifdefs
// 
//    Rev 1.1   25 Oct 1993 15:26:20   mjs
// Next version will be 2.0.04.
// 
//    Rev 1.0   14 Oct 1993 10:12:50   erp
// Initial revision.
// ****************************************************************************
//
#ifndef _XGLOBAL_H_
#define _XGLOBAL_H_

#ifdef _GLOBAL_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif



// Xbase Runtime stuff

#if !defined INTERACTIVE
GLOBAL char near T10ARun[] 
#ifdef _GLOBAL_C_
 = "RI_QUERY"
#endif
;
GLOBAL char near WxRunOut[] 
#ifdef _GLOBAL_C_
 = "RRUNOUT.DBF"
#endif
;
#endif  // Runtime


GLOBAL char near WxDefAWrite[] 
#ifdef _GLOBAL_C_
 = "AllowW"
#endif
;
GLOBAL char near WxDefIndExt[] 
#ifdef _GLOBAL_C_
 = "IndExt"
#endif
;
GLOBAL char near WxIgnU[] 
#ifdef _GLOBAL_C_
 = "IgnoreU"
#endif
;
GLOBAL char near WxHandleEnv[] 
#ifdef _GLOBAL_C_
 =	"RRWHANDLES"
#endif
;
GLOBAL char near WxLibExt[] 
#ifdef _GLOBAL_C_
 = "RP5"
#endif
;
GLOBAL char near WxRepExt[]
#ifdef _GLOBAL_C_
 = "RRW"
#endif
;
GLOBAL char near WxTemplExt[] 
#ifdef _GLOBAL_C_
 = "RT5"
#endif
;
GLOBAL char near WxMemoEd[] 
#ifdef _GLOBAL_C_
 = "MemoEd"
#endif
;
GLOBAL char near WxStandardLib[] 
#ifdef _GLOBAL_C_
 = "STANDARD.RP5"
#endif
;
GLOBAL char near Tixcase[] 
#ifdef _GLOBAL_C_
 =	"INDEXCASE"
#endif
;
GLOBAL char near Tixsrt[] 
#ifdef _GLOBAL_C_
 = "INDEXSRT"
#endif
;
GLOBAL char near Tisuse[] 
#ifdef _GLOBAL_C_
 = "USESRT"
#endif
;
GLOBAL char near Tisignore[] 
#ifdef _GLOBAL_C_
 =	"IGNORESRT"
#endif
;
GLOBAL char near Tixcomp[] 
#ifdef _GLOBAL_C_
 =	"INDEXCOMP"
#endif
;
GLOBAL char near Tixwin[] 
#ifdef _GLOBAL_C_
 = "WINDOWS"
#endif
;
GLOBAL char near WxRunOutHeader[] 
#ifdef _GLOBAL_C_
 = "[RRW Runtime output]\r\n"
#endif
;


#undef GLOBAL
#endif // _XGLOBAL_H_
