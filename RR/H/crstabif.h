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
// $Log:   H:/vcsmfc/h/crstabif.h_v  $
// 
//    Rev 1.5   21 Sep 1995 10:11:02   pjm
// Made SortFldID a FLDID rather than unsigned.
// 
//    Rev 1.4   12 Sep 1995 11:34:58   pjm
// MSVC20 changes.
// 
//    Rev 1.3   29 Aug 1995 13:24:38   mjs
// win32 fixes
// 
//    Rev 1.2   28 Jul 1995 11:09:44   pjm
// Made changes for R&R classes.
// 
//    Rev 1.1   26 Apr 1995 13:16:14   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.7   14 Feb 1995 14:18:46   vff
// Fix RRW 2204 to allow RI_EXPDST=D to work
// 
//    Rev 1.6   11 Mar 1994 17:17:32   erp
// new exports
// 
//    Rev 1.5   01 Mar 1994 12:50:32   erp
// added strings to entry point
// 
//    Rev 1.0   01 Mar 1994 12:50:16   erp
// Initial revision.
// 
//    Rev 1.4   25 Feb 1994 13:20:10   erp
// cleaned up interface
// 
//    Rev 1.3   22 Feb 1994 14:27:30   erp
// fixed GLOBAL define
// 
//    Rev 1.2   22 Feb 1994 10:00:36   erp
// Implemented changes from xcall.h
// 
//    Rev 1.1   22 Feb 1994 09:35:52   say
// change #define to match new file name
// 
//    Rev 1.0   22 Feb 1994 09:28:34   say
// Initial revision.
// 
//    Rev 1.0   22 Feb 1994 09:27:00   say
// Initial revision.
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
#ifndef _CRSTABIF_H_
#define _CRSTABIF_H_

#include <stdlib.h>

#include "rrxfld.h"
#include "print_.h"		// for BRKFLD

typedef struct mffield far * LPMFFIELD;	// to avoid mffield.h

typedef struct sortdata
{
	FLDID sortFldID;	// field index
	unsigned sortAD;	// ascending/descending
	BRKFLD group;		// group field
} SGDATA;


#ifndef DLLENTRY
#define DLLENTRY WINAPI
#endif


#ifdef _CRSTABIF_C_
	#define GLOBAL
#else
	#define GLOBAL extern
#endif

//
// Add the global for the last ExportInfo Structure
//
#if 0
GLOBAL LPEXPORTINFO lpEXPORT_Info
#ifdef _CRSTABIF_C_
	= NULL;
#else
	;
#endif
#endif

#undef GLOBAL

#if 0
extern HINSTANCE XCALL_NewInteractiveExport		(int handle, HWND hParentWnd, LPSTR lpszExportLine, LPSTR lpszTitle);
extern HINSTANCE XCALL_NewRuntimeExport   		(LPSTR lpszTitle, int xPrint, LPSTR lpszOutputFile);
extern BOOL XCALL_FreeExportInfo (void);
#endif

#endif
