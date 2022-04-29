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
// $Log:   H:/vcsmfc/h/wdisplay.h_v  $
// 
//    Rev 1.5   10 Jan 1996 15:31:08   par
// We are no longer offsetting the layout by 3 pixels.
// 
//    Rev 1.4   31 Oct 1995 08:03:52   sbc
// Reduce horizontal ruler height by two pixels
// 
//    Rev 1.3   28 Oct 1995 13:06:04   sbc
// Change dimensions of ruler edit cursor marker
// 
//    Rev 1.2   12 Jul 1995 15:44:28   sbc
// Move stuff to RRVIEW.H
// 
//    Rev 1.1   17 Mar 1995 10:11:36   sbc
// Add define for vertical ruler
// 
//    Rev 1.0   16 Mar 1995 16:15:46   sbc
// Initial revision.
// 
//    Rev 1.8   09 Sep 1994 15:56:30   mjs
// Added prototype for cleanupStatusBar() and definiation of help msg size.
// 
//    Rev 1.7   04 Aug 1994 12:49:26   sbc
// Add comment status bar stuff
// 
//    Rev 1.6   13 Jul 1994 15:21:50   mjs
// Added statusInfo() and dispStatus().
// 
//    Rev 1.5   08 Jul 1994 13:46:14   mjs
// Added prototypes for new status bar functions.
// 
//    Rev 1.4   21 Apr 1994 12:57:48   erp
// added function for just getting the prompt text
// 
//    Rev 1.3   08 Apr 1994 11:37:04   mjs
// Move proto for setStatusPaneText from _wdispla.h
// 
//    Rev 1.2   25 Feb 1994 16:14:22   sbc
// New MFC scroll routine externs
// 
//    Rev 1.1   19 Nov 1993 17:40:34   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:10:58   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _WDISPLAY_H_

//
// Make a definition for this module.
//
#define _WDISPLAY_H_
#include "wfield.h"

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

#define VT_RULER_WIDTH			20	// width of vertical ruler
#define HZ_RULER_LEFT			0	// horizontal ruler moved over a bit...
#define HZ_RULER_HEIGHT			21	// height of horizontal ruler
#if 1	// 6.5 width
#define HZ_RULER_MARKER_TOP		18	// top of position marker (from bottom of ruler)
#define HZ_RULER_MARKER_BOTTOM	3	// bottom of position marker (from bottom of ruler)
#define HZ_RULER_MARKER_HEIGHT	16	// height of position marker
#define HZ_RULER_MARKER_WIDTH	3	// width of position marker
#else	// Word ruler style width
#define HZ_RULER_MARKER_TOP		11	// top of position marker (from bottom of ruler)
#define HZ_RULER_MARKER_BOTTOM	4	// bottom of position marker (from bottom of ruler)
#define HZ_RULER_MARKER_HEIGHT	8	// height of position marker
#define HZ_RULER_MARKER_WIDTH	9	// width of position marker
#endif

#if defined(DATADICT)
	#define MAXCOMMENT 80		// move this to a header!!	Done!
#else
	#define MAXCOMMENT 0		// move this to a header!! Done!
#endif
#define HELPMESSAGE_SIZE 100

// View update "hints" (MFC version)
#define HINT_UPDATE_ITEM			100
#define HINT_UPDATE_HZRULER			101
#define HINT_UPDATE_VTRULER			102
#define HINT_UPDATE_FIELDVIEW		103
#define HINT_UPDATE_HORIZONTAL		104
#define HINT_UPDATE_VERTICAL		105
#define HINT_UPDATE_FIELDRECT		106
#define HINT_UPDATE_RRVIEW			107
#define HINT_UPDATE_BANDVIEW		108
#define HINT_UPDATE_PREVIEW			109
#define HINT_UPDATE_PREVIEWRECT		110

//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//




//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#endif // end _WDISPLAY_H_

// *************************** End of File ************************************
