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
// $Log:   H:/VCSMFC/H/_WUTIL.H_V  $
// 
//    Rev 1.1   26 Jul 1995 10:59:06   mjs
// No change.
// 
//    Rev 1.0   16 Mar 1995 16:15:16   sbc
// Initial revision.
// 
//    Rev 1.3   19 Jun 1994 14:50:26   smh
// Added ACROSS and DOWN, PrOpt[ORDER] constants.
// 
//    Rev 1.2   16 Jun 1994 17:27:32   smh
// Moved avery label stuff to wutil from dfile.
// 
//    Rev 1.1   19 Nov 1993 17:41:34   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:11:16   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __WUTIL_H_

//
// Make a definition for this module.
//
#define __WUTIL_H_

#include "wutil.h"

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
#define LFLD(l,n) (*(LPMFFIELD *)((l)[n]-sizeof(LPMFFIELD)))

#define ACROSS	0			// PrOpt[ORDER] values
#define DOWN	1

// Page sizes for avery labels
#define USERDEF	0	/* User-defined label setting */
#define LETTER		1
#define A4			2
#define PIN			3
#define MINI		4

#define TWOANDTWO 9999		/* limit to two integer & two decimal places */
#define LABVALUE		75	  // max length of value in INI file
							// amnt of mem to alloc for label names & lab descripts

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





#undef GLOBAL

#endif // end __WUTIL_H_

// *************************** End of File ************************************
