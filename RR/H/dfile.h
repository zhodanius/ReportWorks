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
//
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/dfile.h_v  $
// 
//    Rev 1.7   05 May 1997 15:13:12   par
// Removed A L I V E (spacing prevents search hits) and PDI _ EXPORT conditionals.
// From this point forward, this code will always be included in build.
// 
// 
//    Rev 1.6   10 Feb 1997 10:02:18   sp
// Arp Live merge to trunk
// 
//    Rev 1.4.1.2   29 Oct 1996 14:23:02   smh
// PDI _ EXPORT change
// 
//    Rev 1.4   18 Aug 1995 14:50:42   mjs
// Moved strings to global.h
// 
//    Rev 1.3   26 Jul 1995 17:58:04   smh
// Moved most to doc class, some to view class.
// 
//    Rev 1.2   28 Jun 1995 16:34:42   smh
// Merged csv/rtf export changes from 6.5.
// 
//    Rev 1.1   25 Apr 1995 15:11:34   smh
// Merged 6.1.03 and 7.0 headers.
// 
//    Rev 1.0   16 Mar 1995 16:12:28   sbc
// Initial revision.
// 
//    Rev 1.19   22 Jun 1995 11:33:10   smh
// Code for ExportType improvements.
// 
//    Rev 1.18   12 Jun 1995 16:07:04   sjo
// Made some changes to fix a problem with disabling exports from INI file.
// 
//    Rev 1.17   08 Jun 1995 11:43:16   sjo
// Checking in changes for CSV (both Word Merge and Text Data) export 
// support. Changed dfile\dexport.c, dtxtopt.c, repio\grmisc.c, rpwritex.c,
// spec\specopt.c, h\dfile.h, dbexport.h, repio.h, resource.h, wmain.h,
// _dfile.h and wdialog.h.  Also resource\rrw.str,export.dlg.
// 
//    Rev 1.16   26 May 1995 16:32:26   pjm
// Add new listbox entry for RTF export and define prototype for dlg.
//
//    Rev 1.15   17 Feb 1995 17:33:20   smh
// Added AppendINIExports proto for RRW 2288.
// 
//    Rev 1.14   31 Aug 1994 19:25:32   smh
// RI_RepPick: Moved repno & rname here from wreport.h becuase
// wreport.c is not compiled in the runtime.
// 
//    Rev 1.13   19 Aug 1994 09:18:02   erp
// fixed section for multiple include 
// 
//    Rev 1.12   09 Aug 1994 14:01:02   sbc
// Move bOldDOSRep to repio.h
// 
//    Rev 1.11   02 Aug 1994 16:54:44   smh
// Report annotate - proto for summaryDialog().
// 
//    Rev 1.10   19 Jun 1994 14:47:28   smh
// Added prototype for set_PageSize, routine to set page size for Avery Labels.
// 
//    Rev 1.9   16 Jun 1994 17:27:52   smh
// Moved avery label stuff from dfile to wutil
// 
//    Rev 1.8   14 Jun 1994 15:38:48   smh
// Added label_name structure for Avery Labels support.
// 
//    Rev 1.7   08 Jun 1994 10:43:26   sbc
// File New dialog
// 
//    Rev 1.6   07 Mar 1994 13:37:10   erp
// moved the global for MAPI to the header file
// 
//    Rev 1.5   01 Mar 1994 08:56:36   sbc
// New call out of DPRINT.C for MFC
// 
//    Rev 1.4   24 Feb 1994 09:21:10   erp
// removed the Excel 5 entry from ExportTypes table
// 
//    Rev 1.3   22 Feb 1994 11:06:52   erp
// 
//    Rev 1.2   29 Dec 1993 13:34:32   smh
// Database export:  Changed & added some prototypes.
// See Scott for complete list of files.
// 
//    Rev 1.1   19 Nov 1993 17:38:48   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:10:22   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _DFILE_H_

//
// Make a definition for this module.
//
#define _DFILE_H_

#include "resource.h"		// for IDS_ constants
#include "wutil.h"			// for LABNAMEMAX

#if defined _DREPORT_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

// The following structure is used to define the various export types.  There has been
//  a correspondence to the ???EXP define (like TXTEXP) and various other things in the
//  product.  This struct, combined with the ???EXP define, will give you the string to
//  display in the Export dialog as well as whether or not this export is disabled.  MAPI
//  is not part of this struct, because every export in the ExportTypes array supports
//  MAPI.
typedef struct ExportInfo
{
	int	type;			// ExportType constant
	int	StringID;
	BOOL	Disabled;	// Is this export disabled
} EXPORTINFO;


//  VERY IMPORTANT! - NUMEXPTYPES must be set to
//  reflect the number of export types PLUS ONE!
//  See CRrExport constructor in rr\rrexport.cpp.
//  (sbc - 10/16/96)
#define NUMEXPTYPES 11

//
// Structure Section:
// Place in this section any structure definitions.
//
typedef struct label_name
{
	char name[LABNAMEMAX+1];
//	char description[LABDESCMAX+1];
} LABEL_NAME;
typedef LABEL_NAME far * LPLABNAME;

//
// Global Data Section:
// Place in this section any global data.
//




//
// Function Prototypes Section:
// Place in this section any function prototypes
//

//	THESE RSW RTNS SEEM TO BE OBSOLETE, NOT IN RSW.MAK
//	extern BOOL CALLBACK copyDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);

//
// The following call back procedure were added for the new export options dialog boxes
//


#if defined INTERACTIVE
 #ifdef RRMFC
extern void printerSetup(HWND hWnd);
 #endif
#endif

//	THESE RSW RTNS SEEM TO BE OBSOLETE, NOT IN RSW.MAK
#if 0
#if defined RSW
extern BOOL FAR PASCAL tableMasterRelateDlgProc(HWND hDlg,WORD message,WORD wParam,LONG lParam);
extern void BtrieveTableFromFile (LPSTR FileAndTable, LPSTR szTableName);
extern BOOL FAR PASCAL connectDialog(HWND hDlg,WORD message,WORD wParam,LONG lParam);
#endif
#endif



#undef GLOBAL

#endif // end _DFILE_H_

// *************************** End of File ************************************
