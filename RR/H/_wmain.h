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
// $Log:   H:/vcsmfc/h/_wmain.h_v  $
// 
//    Rev 1.1   12 Jul 1995 15:17:56   sbc
// Remove display-related prototypes
// 
//    Rev 1.0   16 Mar 1995 16:15:12   sbc
// Initial revision.
// 
//    Rev 1.4   04 Oct 1994 11:36:06   dlm
// Change prototype of customTitleScreen() to reflect new "name" arg.
// 
//    Rev 1.3   23 Aug 1994 19:22:02   sjo
// Added an GLOBAL for the /G switch (GoArg). 
// 
//    Rev 1.2   28 Jul 1994 09:21:34   sbc
// Splash bitmap changes
// 
//    Rev 1.1   19 Nov 1993 17:40:20   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:11:00   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __WMAIN_H_

//
// Make a definition for this module.
//
#define __WMAIN_H_

#include "wmain.h"

#if defined(_RRINIT_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//



// The /G switch is used in WRMAIN and identified in CMDLINE, therefore,
//  we need a global to access it.  We need to find a way to move this
//  processing into CMDLINE, so we dont need this global.
//
GLOBAL int GoArg			
#if defined(_RRINIT_C_)
= FALSE
#endif
;


//
// Function Prototypes Section:
// Place in this section any function prototypes
//



extern void getSQLDefs();
extern BOOL getSQLFlags();

#if defined (INTERACTIVE)
extern BOOL getsnumber(HINSTANCE hPrev);
#endif

void readsrt(void);



#undef GLOBAL

#endif // end __WMAIN_H_

// *************************** End of File ************************************
