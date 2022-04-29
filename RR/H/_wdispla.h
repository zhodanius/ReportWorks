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
// $Log:   H:/vcsmfc/h/_wdispla.h_v  $
// 
//    Rev 1.1   12 Jul 1995 15:44:16   sbc
// Move stuff to RRVIEW.H
// 
//    Rev 1.0   16 Mar 1995 16:15:08   sbc
// Initial revision.
// 
//    Rev 1.5   13 Jul 1994 15:21:24   mjs
// Moved statusInfo to wdisplay.h
// 
//    Rev 1.4   08 Apr 1994 11:36:30   mjs
// Move setStatusPaneText proto to wdisplay.
// 
//    Rev 1.3   08 Mar 1994 15:44:20   sbc
// dispSnapGrid gets far pointer for V4
// 
//    Rev 1.2   08 Mar 1994 15:36:30   mjs
// Added prototype for setStatusPaneText().
// 
//    Rev 1.1   19 Nov 1993 17:40:40   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:10:58   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __DISPLA_H_

//
// Make a definition for this module.
//
#define __DISPLA_H_

#include "wdisplay.h"

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
#ifdef _WDSPSTAT_C_
#define GLOBAL
#else
#define GLOBAL extern
#endif


#undef GLOBAL
//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#endif // end __DISPLA_H_

// *************************** End of File ************************************
