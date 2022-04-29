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
// Private header for HTML export
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/_htmlexp.h_v  $
// 
//    Rev 1.3   10 Feb 1997 10:02:18   sp
// Arp Live merge to trunk
// 
//    Rev 1.1.1.2   30 Nov 1996 16:14:52   smh
// No longer require a printer for html export.
// 
//    Rev 1.1.1.1   31 Oct 1996 09:08:46   smh
// Changed arg to putline so can send it CStrings.
// 
//    Rev 1.1.1.0   21 Oct 1996 15:43:08   sp
// added csDefaultColor as last parameter to external declaration of 
// getColorString
// 
//    Rev 1.1   08 Oct 1996 16:49:36   amh
// Arp 1.0 U02 merged to trunk
// 
// 
// 
//    Rev 1.0.1.0   26 Sep 1996 11:40:16   sjo
// Added prototypes for new color routines.  (smh for sjo)
// 
//    Rev 1.0   30 Jul 1996 16:52:30   sjo
// Initial revision.
// 
// Check to make sure this is not included more than once.
//
#ifndef _HTMLEXP_H_

//
// Make a definition for this module.
//
#define _HTMLEXP_H_
#include "wmain.h"
#include "wprintui.h"
#include "_pd.h"
#include "resource.h"

// defines section *****************************************************

#define HWEXPPS ps->pDest.html.wpd	// point to wpd part of html structure
#define HEXPPS  ps->pDest.html		// point to html part of structure

	// from wexport.h
#define RRWVTRES	720
#define PD_LPI		6			/* assume 6 lines per inch */
#define FACTOR		120		/* RRWVTRES / PD_LPI */
#define EXP_CPI	10			/* characters per inch */
#define NCOL		255		/* number of columns per line in screen buffer */
#define PBUFSIZE (NCOL*4)	/* page buffer size (bytes) */
#define LBUFSIZE	200		/* line buffer size from pdriver.h */
#define IDS_0626	626		// from resource.h

// Data section

#if defined(_HTMLEXP_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif

// prototypes section
//extern void FAR PASCAL pwClearFontCache(LPPRT_STRUCT );
//extern WORD FAR PASCAL pwVertLoc(LPPRT_STRUCT );

extern BOOL near sendLine(LPPRT_STRUCT, char *, int);
extern UINT put_html_head(LPPRT_STRUCT);
extern BOOL putline(LPPRT_STRUCT, LPCSTR);
extern BOOL flushEBufs(LPPRT_STRUCT ps);
extern BOOL setBOL(LPPRT_STRUCT, WORD);
extern void setEOL(LPPRT_STRUCT, WORD);
extern int setFont(LPPRT_STRUCT, HDC, int, int, int);
extern void delMemFonts(LPPRT_STRUCT);
extern BOOL html_line_ht(LPPRT_STRUCT, int, BOOL);
extern int getColor (int Rval, int Gval, int Bval);

// sp 10/21/96 added default color as last parameter
extern CString getColorString (int iColorIndex, CString csDefaultColor);

// from dllmem.c
//LPSTR dll_globalAlloc(WORD flags,DWORD size);
//void dll_globalFree(LPSTR pMem);

#undef GLOBAL
#endif
