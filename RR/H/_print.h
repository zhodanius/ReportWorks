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
// $Log:   H:/vcsmfc/h/_print.h_v  $
// 
//    Rev 1.2   18 Jul 1995 15:38:46   smh
// Told preprocessor size of pghRtn array to fix warning.
// 
//    Rev 1.1   11 Jul 1995 16:28:56   sbc
// Move stuff to rrdoc.h
// 
//    Rev 1.0   16 Mar 1995 16:14:48   sbc
// Initial revision.
// 
//    Rev 1.7   26 Jul 1994 18:13:56   sjo
// I am adding snaked column support.  I changed rppage.c, wprint.c, prec.c,
// rphf.c, pline.c, rpwrap.c, prwritex.c, gropts.c, totals.c and _print.h.
// 
//    Rev 1.6   23 Mar 1994 12:22:18   sbc
// Change arg to outline()
// 
//    Rev 1.5   29 Dec 1993 13:34:34   smh
// Database export:  Made some things visible to rpexport.c
// See Scott for complete list of files.
// 
//    Rev 1.4   19 Nov 1993 17:39:52   sbc
// Add extern C for C++
// 
//    Rev 1.3   29 Oct 1993 14:03:18   sbc
// Add SnapBreakData, needed for READAHEAD
// 
//    Rev 1.2   26 Oct 1993 10:31:54   sbc
// These headers need #undef GLOBAL
// 
//    Rev 1.1   25 Oct 1993 15:53:46   sbc
// Add new LinePtr local heap pointer.  Change outline() & hzheight() args.
// 
//    Rev 1.0   14 Oct 1993 10:12:46   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __PRINT_H_

//
// Make a definition for this module.
//
#define __PRINT_H_

#include "print_.h"

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
/* longest full month name (September), excluding NULL terminator */
#define MONTHMAX 9

	// from prec.c (need to share 'em w/ rpexport.c)
#define WRAPPING	0x0001
#define LAST_TIME	0x0002
#define PUSHED		0x0004
#define DONE		0x0008
#define PRINT_ME	0x0010	// print 2D'er


//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//



#if defined _PLINE_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

extern int pghyes(int ind);
extern int pghbreak(int ind);
extern int pghrepeat(int ind);

GLOBAL int (*pghRtn[3])(int)
#if defined _PLINE_C_
 = {
		pghyes,pghbreak,pghrepeat
	}
#endif
;


//
// Function Prototypes Section:
// Place in this section any function prototypes
//

#undef GLOBAL

#endif // end __PRINT_H_

// *************************** End of File ************************************
