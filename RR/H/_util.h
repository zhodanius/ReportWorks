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
// $Log:   H:/vcsmfc/h/_util.h_v  $
// 
//    Rev 1.0   16 Mar 1995 16:15:04   sbc
// Initial revision.
// 
//    Rev 1.2   19 Nov 1993 17:38:44   sbc
// Add extern C for C++
// 
//    Rev 1.1   28 Oct 1993 10:35:18   smh
// Commented out SO structure because not being used.  See znv.c.
// 
//    Rev 1.0   14 Oct 1993 10:10:22   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __UTIL_H_

//
// Make a definition for this module.
//
#define __UTIL_H_

#include "util.h"

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
	// many #define in zfatal.h I didn't think were used - SMH

//
// Structure Section:
// Place in this section any structure definitions.
//

#if 0
	// Scott - 10/28/93
	// This wasn't being used.  See znv.c
typedef struct so			/* section / offsets structure */
{
	char far *section;	   	/* pointer to section name */
	long start;				/* starting file position for section */
	long end;				/* ending file position for section */
	struct so *next;		/* next element */
} SO;
#endif

//
// Global Data Section:
// Place in this section any global data.
//



#ifdef _ZDATEIN_C_
    UONE near modays[] = { 31,30,31,30,31,31,30,31,30,31,31,28 };
#else
    UONE near modays[];
#endif



//
// Function Prototypes Section:
// Place in this section any function prototypes
//




#endif // end __UTIL_H_

// *************************** End of File ************************************
