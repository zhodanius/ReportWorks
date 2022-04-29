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
//	3/27/95  Created this to bring in a subset of WPRINTUI.H for use by the PD modules.
// This avoids bringing in all kinds of layout stuff into the printer driver.
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/prtinit.h_v  $
// 
//    Rev 1.6   05 May 1997 15:13:14   par
// Removed A L I V E (spacing prevents search hits) and PDI _ EXPORT conditionals.
// From this point forward, this code will always be included in build.
// 
// 
//    Rev 1.5   10 Feb 1997 10:02:22   sp
// Arp Live merge to trunk
// 
//    Rev 1.3.1.0   18 Oct 1996 12:33:10   smh
// PDI export implementation
// 
//    Rev 1.3   25 Sep 1995 10:18:10   mjs
// Commented out print.h
// 
//    Rev 1.2   13 Sep 1995 14:16:58   smh
// Port to 32-bits.
// 
//    Rev 1.1   29 Aug 1995 13:27:46   mjs
// win32
// 
//    Rev 1.0   27 Mar 1995 13:27:14   mjs
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _WPRTINIT_H_

//
// Make a definition for this module.
//
#define _WPRTINIT_H_

#ifdef WIN32
#include <wingdi.h>	// DEVMODE in here now.
#else
// mjs  Had to comment this out due to brain-dead dependancy scan by MSVC 2.2.
// #include <print.h>	// for LPDEVMODE
#endif

typedef struct prt_init		// printer driver init structure
{
	DWORD dmFields;
	LPDEVMODE pDevMode;
	UINT	paper_tray;
	UINT	pagelen;
	UINT	leftmar;
	UINT	repnmlen;
	char orientation;
	char repname[31];
	HANDLE	hPDIFile;	// Report Viewer Control Export
} PRT_INIT;

typedef PRT_INIT far *LPPRT_INIT;


// smh - changed *Weight WORDs to ints because lfWeight is an int in LOGFONT struct
//		also put LOGFONT between ints and chars for alignment reasons b/c LOGFONT made up of
//		ints and chars itself.
typedef struct prt_face			// font structure
{
	int	normWeight;
	int	boldWeight;
	int	italicWeight;
	LOGFONT logFont;		// master font descriptor
	char sizes;				// number of sizes
	char flags;				// flag bits
	char font_saved;		// index of font saved in report library
	char ptSizes[FONT_SIZES];	// computed point sizes
} PRT_FACE;

typedef PRT_FACE far *LPPRT_FACE;

#define ZOOM_FULL	0		// zoom levels
#define ZOOM_FIT	1
#define ZOOM_DEEP	2

#endif
