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
// Private header for RTF export
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/_rtexp.h_v  $
// 
//    Rev 1.6   19 Feb 1997 14:57:06   dlm
// Part of fix to RRW 2991/RSW 2386 to allow specification via SPACEDOT
//  setting in .SRT file of override for hard-space character.  Changed much
//  code to use new SpaceDot variable instead of zdSPC or ANSI_DOT.  Changed
//  most export/printer DLLs to use a new internal SpaceDot function instead
//  of exported pwSpaceDot.  Change EXEs to use new CRrDoc::SpaceDot function
//  instead of using exported pwSpaceDot functions of DLLs.  Modules changed
//  are: explt.cpp, token.cpp, fstr.cpp, trim.cpp, pksx.cpp, sxmisc.cpp,
//  mfgetmch.cpp, mfsql.cpp, htmlexp.cpp, pwint.cpp, pxdriver.cpp, pxint.cpp,
//  rtfexp.cpp, wexpdriv.cpp, wexpint.cpp, pwdriver.cpp, picdata.cpp,
//  picshape.cpp, prec.cpp, rpwrap.cpp, rprint.cpp, gropts.cpp, grfield.cpp,
//  rpwritex.cpp, grmisc.cpp, rrcompos.cpp, rrdoc.cpp, rrrepio.cpp,
//  specfld1.cpp, specfld2.cpp, specquer.cpp, wedtx.cpp, edittext.cpp,
//  wfont.cpp, readsrt.cpp, wprint.cpp, wtxtexp.cpp, winst.cpp, wstring.cpp,
//  global.h, pd.h, rrcompos.h, rrdoc.h, rrrepio.h, _pd.h, _rtexp.h
// 
//    Rev 1.5   08 Oct 1996 16:49:38   amh
// Arp 1.0 U02 merged to trunk
// 
// 
// 
//    Rev 1.3.1.0   19 Aug 1996 14:29:30   smh
// Fixed prototype for dll_globalAlloc now that using it.
// 
//    Rev 1.4   19 Aug 1996 14:30:18   smh
// trunk change for 1.3.1.0.
// 
//    Rev 1.3.1.0   19 Aug 1996 14:29:30   smh
// Fixed prototype for dll_globalAlloc now that using it.
// 
//    Rev 1.3   28 May 1996 13:37:54   pjm
// Change prototype for rtf_line_ht to allow for negative height arg.
// 
//    Rev 1.2   25 Sep 1995 17:13:14   smh
// Removed protos - use those in _pd.h b/c same API
// 
//    Rev 1.1   02 Aug 1995 11:18:40   pjm
// add #undef GLOBAL.
// 
//    Rev 1.0   17 Jul 1995 15:14:10   pjm
// Initial revision.
// 
//    Rev 1.1   06 Jun 1995 13:42:46   pjm
// Added some more headers we need for RTF, like MAXFONTSAVE.
// 
//    Rev 1.0   26 May 1995 16:43:02   pjm
// Initial revision.
// 
//
// Check to make sure this is not included more than once.
//
#ifndef _RTEXP_H_

//
// Make a definition for this module.
//
#define _RTEXP_H_
#include "wmain.h"
#include "wprintui.h"
#include "_pd.h"
#include "resource.h"

// defines section *****************************************************

//#define WEXPPS ps->pDest.rtf.wpd	// point to wpd part of rtf structure
#define REXPPS ps->pDest.rtf		// point to rtf part of structure
#define WEXPPS REXPPS

	// from wexport.h
#define RRWVTRES	720
#define PD_LPI		6			/* assume 6 lines per inch */
#define FACTOR		120		/* RRWVTRES / PD_LPI */
#define NCOL		255		/* number of columns per line in screen buffer */
#define PBUFSIZE (NCOL*4)	/* page buffer size (bytes) */
#define LBUFSIZE	200		/* line buffer size from pdriver.h */
#define IDS_0626	626		// from resource.h

// Data section

#if defined(_RTFEXP_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif

// prototypes section
//extern void FAR PASCAL pwClearFontCache(LPPRT_STRUCT );
//extern WORD FAR PASCAL pwVertLoc(LPPRT_STRUCT );

extern BOOL near sendLine(LPPRT_STRUCT, char *, int);
extern UINT put_rtf_head(LPPRT_STRUCT);
extern BOOL putline(LPPRT_STRUCT, LPSTR);
extern BOOL flushEBufs(LPPRT_STRUCT ps);
extern BOOL setBOL(LPPRT_STRUCT, WORD);
extern void setEOL(LPPRT_STRUCT, WORD);
extern int setFont(LPPRT_STRUCT, HDC, int, int, int);
extern void delMemFonts(LPPRT_STRUCT);
extern BOOL rtf_line_ht(LPPRT_STRUCT, int, BOOL);

// from dllmem.c
LPSTR dll_globalAlloc(UINT flags,DWORD size);		// get some global heap
void  dll_globalFree (LPSTR pMem);

#undef GLOBAL
#endif
