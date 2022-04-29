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
//      NON-TRANSLATED text goes here (translated in RRW.STR)
// SQL (and PACE) specific strings
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/sglobal.h_v  $
// 
//    Rev 1.13   03 May 1996 16:26:58   jpb
// support ListSystemTables
// 
//    Rev 1.12   29 Apr 1996 18:26:34   jpb
// Add WxPassExex string
// 
//    Rev 1.11   28 Feb 1996 19:02:24   jpb
// add JetDBFilter support
// 
//    Rev 1.10   05 Jan 1996 16:31:18   par
// All explicitly linked modules and external initialization files are located
// with the explicit file manager.  This will provide a central location where
// file paths can be adjusted.
// 
//    Rev 1.9   30 Nov 1995 15:06:28   sbc
// Move pritner driver name to global.h now that it's common
// 
//    Rev 1.8   27 Nov 1995 13:47:44   smh
// rswexp.dll -> rrtxtx.dll
// 
//    Rev 1.7   08 Nov 1995 15:41:42   dlm
// Added WxRepExt to hold compound file extension (.RSW).
// 
//    Rev 1.6   18 Aug 1995 14:47:34   mjs
// Moved strings to global.h
// 
//    Rev 1.5   11 Aug 1995 17:12:06   jpb
// Second cleanup pass for RSW
// 
//    Rev 1.4   03 Aug 1995 09:39:40   jpb
// Fix part of rsw 1882
// 
//    Rev 1.3   26 Jul 1995 09:12:24   pjm
// Made string arrays near.
// 
//    Rev 1.2   17 Jul 1995 14:43:58   jpb
// Fix RSW 1801
// 
//    Rev 1.1   26 Apr 1995 14:07:20   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.24   07 Apr 1995 12:13:32   jpb
// stuff for RSW.INI DatetimeCompatibility setting
// 
//    Rev 1.23   01 Feb 1995 17:38:46   jpb
// Fix bad edit
// 
//    Rev 1.22   01 Feb 1995 17:17:10   jpb
// add [Database] section setting strings
// 
//    Rev 1.21   10 Jan 1995 14:42:32   sbc
// Remove the following text globals: WxNotFirstTime, WxLastDictionary,
// WxLastDatabaseFile, WxAccessPreference, WxLastTable, WxBtrieveKey, WxLastFile
// that are obsolete
// 
//    Rev 1.20   27 Sep 1994 18:11:24   jpb
// define stuff for new FileExt ini setting
// 
//    Rev 1.19   14 Sep 1994 16:06:02   smh
// RT6, the template library extension.
// 
//    Rev 1.18   24 Mar 1994 09:34:04   erp
// removed include of version.h
// 
//    Rev 1.17   24 Mar 1994 09:27:54   erp
// moved WxVersion into version.h
// 
//    Rev 1.16   23 Mar 1994 15:01:54   erp
// added single version change
// 
//    Rev 1.15   16 Mar 1994 17:37:28   say
// update version
// 
//    Rev 1.14   11 Mar 1994 12:01:56   say
// Update release num to 3.0.01 for 1st beta release
// 
//    Rev 1.13   25 Feb 1994 15:08:32   smh
// Changes for ODBC in runtime:  rpprep.c, wrtmain.c, wnextjob.c, 
// sconnect.c, mfsql.c, runtime.h,_runtime.h, sglobal.h
// 
//    Rev 1.12   02 Feb 1994 12:26:00   pjm
// Updated version number for 4th RSW 2.5 alpha candidate to 2.0.09.
// 
//    Rev 1.11   21 Jan 1994 09:23:20   erp
// Updated version number for alpha candidate release.
// 
//    Rev 1.10   06 Jan 1994 16:42:14   say
// treat paradox files as file-based
// 
//    Rev 1.9   27 Dec 1993 18:25:32   say
// Update WxVersion
// 
//    Rev 1.8   17 Dec 1993 15:39:24   say
// Update version
// 
//    Rev 1.7   07 Dec 1993 16:53:34   say
// Add, remove INI string defs for ODBC
// 
//    Rev 1.6   19 Nov 1993 17:42:02   sbc
// Add extern C for C++
// 
//    Rev 1.5   05 Nov 1993 10:53:42   jpb
// Add line terminator to last source line (final #endif) so compiler
//  will see it!!!
// 
//    Rev 1.4   03 Nov 1993 11:33:12   say
// Bracket file with #ifdefs
// 
//    Rev 1.3   02 Nov 1993 11:16:56   say
// Add #defines for length, moved from eng.h to remove unnecessary
// dependencies in wmain.h
// 
//    Rev 1.2   25 Oct 1993 15:25:20   mjs
// Next release will be 2.0.04
// 
//    Rev 1.1   18 Oct 1993 09:18:26   erp
// bumped RSW version number
// 
//    Rev 1.0   14 Oct 1993 10:11:40   erp
// Initial revision.
// ****************************************************************************
//

#ifndef _SGLOBAL_H_
#define _SGLOBAL_H_

#ifdef _GLOBAL_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

#define USERIDLEN               32
#define PASSWDLEN               32
#define PLATNAMELEN             16 // platform name length

// DatetimeCompatibiltiy RSW.INI setting mnemonics
#define DTC_ALWAYS_CONVERT_DATETIME_TO_DATE		0
#define DTC_ONLY_ASK_FOR_60_REPORTS				1
#define DTC_ASK_FOR_ALL_REPORTS					2
#define	DTC_DONT_CONVERT_DATETIME_TO_DATE		3

// Runtime SQL stuff



GLOBAL int DatetimeCompatibility;

#if !defined INTERACTIVE
GLOBAL char near T4NRun[] 
#ifdef _GLOBAL_C_
 = "RI_ID"
#endif
;
GLOBAL char near T10ARun[] 
#ifdef _GLOBAL_C_
 = "RI_INCLUDE"
#endif
;
GLOBAL char near T13ARun[] 
#ifdef _GLOBAL_C_
 = "RI_WHERE"
#endif
;
GLOBAL char near T21ARun[] 
#ifdef _GLOBAL_C_
 = "RI_REPLACE"
#endif
;
GLOBAL char near WxWDataSource[]
#ifdef _GLOBAL_C_
 = "RI_DSOURCE"
#endif
;
GLOBAL char near WxRunOutHeader[] 
#ifdef _GLOBAL_C_
 = "[RSW Runtime output]\r\n"
#endif
;
#endif
GLOBAL char near WxQualCol[] 
#ifdef _GLOBAL_C_
 = "AlwaysQualifyColList"
#endif
;
GLOBAL char near WxTableAlias[] 
#ifdef _GLOBAL_C_
 = "AlwaysUseTableAlias"
#endif
;
GLOBAL char near WxQualSort[] 
#ifdef _GLOBAL_C_
 = "AlwaysQualifySortList"
#endif
;
GLOBAL char near WxEvalX[] 
#ifdef _GLOBAL_C_
 = "AlwaysEngineEval"
#endif
;
GLOBAL char near WxAlwaysSelect[] 
#ifdef _GLOBAL_C_
 = "AlwaysSelect"
#endif
;
GLOBAL char near WxAlwaysLocalLog[] 
#ifdef _GLOBAL_C_
 = "AlwaysLocalLog"
#endif
;
GLOBAL char near WxDataSourceProcVerb[] 
#ifdef _GLOBAL_C_
 = "DataSourceProcVerb"
#endif
;
GLOBAL char near WxDatetimeCompatibility[] 
#ifdef _GLOBAL_C_
 = "DatetimeCompatibility"
#endif
;
GLOBAL char near WxQueryTimeout[] 
#ifdef _GLOBAL_C_
 = "QueryTimeout"
#endif
;
GLOBAL char near WxQSwitch[] 
#ifdef _GLOBAL_C_
 = "QSwitch"
#endif
;
GLOBAL char near WxCharRaw[] 
#ifdef _GLOBAL_C_
 = "CharRaw"
#endif
;
GLOBAL char near WxAsciiEditor[] 
#ifdef _GLOBAL_C_
 = "AsciiEditor"
#endif
;
GLOBAL char near WxAddWhereFalse[] 
#ifdef _GLOBAL_C_
 = "AddWhereFalse"
#endif
;
GLOBAL char near WxDBmsgIntro[] 
#ifdef _GLOBAL_C_
 = "DB access: "
#endif           
;   // prepended to Q+E error messages
	// NOTE that if you ever lengthen this message, you'll need
	// to increase buffer sizes in several files.  Search for
	// WxDBmsgIntro comments to locate them.

// Default database connection tags
GLOBAL char near WxDefDataSource[] 
#ifdef _GLOBAL_C_
 = "DefaultDataSource"
#endif
;
GLOBAL char near WxNewReportAutoLogon[]
#ifdef _GLOBAL_C_
 = "NewReportAlwaysUseSameDS"
#endif
;
GLOBAL char near WxReadReportAutoLogon[]
#ifdef _GLOBAL_C_
 = "ReadReportAlwaysUseSameDS"
#endif
;
GLOBAL char near WxServer[] 
#ifdef _GLOBAL_C_
 = "Server"
#endif
;
GLOBAL char near WxUserID[] 
#ifdef _GLOBAL_C_
 = "UserID"
#endif
;
GLOBAL char near WxDataPath[] 
#ifdef _GLOBAL_C_
 = "Data Path"
#endif
;
GLOBAL char near WxDictPath[] 
#ifdef _GLOBAL_C_
 = "Dictionary Path"
#endif
;
GLOBAL char near WxDTAExt[] 
#ifdef _GLOBAL_C_
 = "DTA"
#endif
; // For Btrieve
GLOBAL char near WxDBaseKey [] 
#ifdef _GLOBAL_C_
 = "dBASE"
#endif
;
// For Paradox
GLOBAL char near WxParadoxKey [] 
#ifdef _GLOBAL_C_
 = "Paradox"
#endif
;
#ifdef PACE
 #ifndef INTERACTIVE
GLOBAL char near WxRunOut[] 
#ifdef _GLOBAL_C_
 = "RBRUNOUT.TXT"
#endif
;
 #endif

GLOBAL char near WxHandleEnv[] 
#ifdef _GLOBAL_C_
 = "RBHANDLES"
#endif
;
GLOBAL char near WxLibExt[] 
#ifdef _GLOBAL_C_
 = "RB"
#endif
;
GLOBAL char near WxStandardLib[] 
#ifdef _GLOBAL_C_
 = "STANDARD.RB"
#endif
;
#else   // not PACE
 #ifndef INTERACTIVE
GLOBAL char near WxRunOut[] 
#ifdef _GLOBAL_C_
 = "RRUNOUT.DBF"
#endif
;
 #endif
GLOBAL char near WxHandleEnv[] 
#ifdef _GLOBAL_C_
 = "RSWHANDLES"
#endif
;
GLOBAL char near WxLibExt[] 
#ifdef _GLOBAL_C_
 = "RP6"
#endif
;
GLOBAL char near WxRepExt[] 
#ifdef _GLOBAL_C_
 = "RSW"
#endif
;
GLOBAL char near WxTemplExt[] 
#ifdef _GLOBAL_C_
 = "RT6"
#endif
;
GLOBAL char near WxStandardLib[] 
#ifdef _GLOBAL_C_
 = "STANDARD.RP6"
#endif
;
GLOBAL char near WxQELIBSec[] 
#ifdef _GLOBAL_C_
 ="QELIB"
#endif
;
GLOBAL char near WxQERSWSec[] 
#ifdef _GLOBAL_C_
 ="RSW"
#endif
;
GLOBAL char near WxQERevComp[] 
#ifdef _GLOBAL_C_
 ="Revision"
#endif
;
GLOBAL char near WxUseFileExt[] 
#ifdef _GLOBAL_C_
 ="UseFileExt"
#endif
;
GLOBAL char near WxSelectSortFields[] 
#ifdef _GLOBAL_C_
 ="SelectSortFields"
#endif
;

GLOBAL char near WxJetDBFilter[] 
#ifdef _GLOBAL_C_
 ="JetDBFilter"
#endif
;

GLOBAL char near WxPassExec[] 
#ifdef _GLOBAL_C_
 ="PassExec"
#endif
;

GLOBAL char near WxListSystemTables[] 
#ifdef _GLOBAL_C_
 ="ListSystemTables"
#endif
;

#endif

#undef GLOBAL

#endif // _SGLOBAL_H_

