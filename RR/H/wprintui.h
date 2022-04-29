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
// $Log:   H:/vcsmfc/h/wprintui.h_v  $
// 
//    Rev 1.4   18 Jul 1995 09:58:00   sbc
// Move prototypes to rrdoc.h
// 
//    Rev 1.3   18 Jul 1995 09:43:52   smh
// Classification.
// 
//    Rev 1.2   25 Apr 1995 15:11:06   smh
// Merged 6.1.03 and 7.0 headers.
// 
//    Rev 1.1   27 Mar 1995 13:31:34   mjs
// Moved prt_init stuff to prtinit.h
// 
//    Rev 1.0   16 Mar 1995 16:14:04   sbc
// Initial revision.
// 
//    Rev 1.8   08 Feb 1995 10:55:38   smh
// Proto for createExportFile().  RRW 2278, RSW 1704.
// 
//    Rev 1.7   19 Sep 1994 15:59:38   sbc
// Some "line status" defines for pline & prec
// 
//    Rev 1.6   16 Sep 1994 09:50:12   sbc
// New global for print-time task check
// 
//    Rev 1.5   14 Sep 1994 13:58:34   sbc
// New function (preview sys_command call)
// 
//    Rev 1.4   17 May 1994 11:12:38   sbc
// New call for preview
// 
//    Rev 1.3   29 Dec 1993 13:34:22   smh
// Database export:  Changed & added some prototypes.  
// See Scott for complete list of files.
// 
//    Rev 1.2   06 Dec 1993 16:59:52   jpb
// change arglist for finalPrintInfo for RSW version
// 
//    Rev 1.1   19 Nov 1993 17:41:04   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:11:06   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _WPRINTUI_H_

//
// Make a definition for this module.
//
#define _WPRINTUI_H_
// #include <print.h>	// for LPDEVMODE
#include "prtinit.h"	// for prt_init
#include "mffield.h" // for LPMFFIELD

#if defined(_WPRINT_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
// preview error, display message in status bar after preview
#define ERROR_FROM_PREVIEW	-6

// Preview screen parameters

#define PREV_FULL_TOPBOT	7

// Preview button indexes
#define PVPRINT		0
#define PVPPAGE		1
#define PVZOOMIN	2
#define PVZOOMOUT	3
#define PVFIRST		4
#define PVBACK		5
#define PVNEXT		6
#define PVLAST		7
#define PVPAUSE		8
#define PVSTOP		9

#if 0	// now in prtinit.h
#define ZOOM_FULL	0		// zoom levels
#define ZOOM_FIT	1
#define ZOOM_DEEP	2
#endif

#define DLGEXPORT 0		// can remove from DEXPORT.C - keep in synch
#define DLGEXPCLOSE 1	// return values tell caller EXPORT or CLOSE selected

// line content flags (prec.c & pline.c)
#define LINE_NULL	0	// empty fields
#define LINE_BLANK	1	// no fields
#define LINE_DATA	2	// some sort of data
#define LINE_BOXEND	3	// box passing through

//
// Structure Section:
// Place in this section any structure definitions.
//
#if 0		// now in prtinit.h
typedef struct prt_init		// printer driver init structure
{
	WORD paper_tray;
	char orientation;
	WORD pagelen;
	WORD leftmar;
	DWORD dmFields;
	LPDEVMODE pDevMode;
	WORD repnmlen;
	char repname[31];
} PRT_INIT;

typedef PRT_INIT far *LPPRT_INIT;
#endif

// ***************************************************************
//
// Global Data Section:
// Place in this section any global data.
//




// ***************************************************************
//
// Function Prototypes Section:
// Place in this section any function prototypes
//

#undef GLOBAL

#endif // end _WPRINTUI_H_

// *************************** End of File ************************************
