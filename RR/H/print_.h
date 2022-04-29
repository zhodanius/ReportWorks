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
// $Log:   H:/vcsmfc/h/print_.h_v  $
// 
//    Rev 1.2   26 Sep 1995 15:28:18   sjo
// changed brkflds to a FLDID.
// 
//    Rev 1.1   11 Jul 1995 16:29:06   sbc
// Move stuff to rrdoc.h
// 
//    Rev 1.0   16 Mar 1995 16:13:08   sbc
// Initial revision.
// 
//    Rev 1.2   19 Nov 1993 17:39:50   sbc
// Add extern C for C++
// 
//    Rev 1.1   11 Nov 1993 09:10:46   jpb
// Fix the "multiple mfgetbuf()" RSW memory leak.  Sources changed for this
// fix were: PRINT_.H, MFSRTFIN.C, MFWRFIN.C, RPSETUP.C, RPSORT.C, SORT.C
// 
//    Rev 1.0   14 Oct 1993 10:12:50   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _PRINT_H_

//
// Make a definition for this module.
//
#define _PRINT_H_
#include "mffield.h"

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

//
// Structure Section:
// Place in this section any structure definitions.
//
typedef struct		// multiple records across
{
	LPSTR data;			/* line buffer */
	WORD hite;			/* line height */ 
	WORD len;			// current length
	char status;		/* status byte */
} MULT;

typedef struct brkFld		/* group field structure */
{
	FLDID	index;				/* group field index */
	char 	brkFlags;			/* option flag byte */
	char 	status;			/* status flags */
} BRKFLD;

//
// Global Data Section:
// Place in this section any global data.
//


// put globals here:



//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#endif // end _PRINT_H_

// *************************** End of File ************************************
