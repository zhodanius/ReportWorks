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
// $Log:   H:/vcsmfc/h/wclip.h_v  $
// 
//    Rev 1.1   12 Jul 1995 13:04:52   sbc
// Move variables and function prototypes to rrdoc.h
// 
//    Rev 1.0   16 Mar 1995 16:13:54   sbc
// Initial revision.
// 
//    Rev 1.3   20 Jan 1994 14:31:56   sbc
// Add arg to clearLayout()
// 
//    Rev 1.2   18 Jan 1994 14:19:14   sbc
// Add clearLayout() extern
// 
//    Rev 1.1   19 Nov 1993 17:40:26   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:10:54   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _WCLIP_H_

//
// Make a definition for this module.
//
#define _WCLIP_H_
#include "wfield.h"
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
#ifdef _WCLIP_C_
    #define GLOBAL
#else
    #define GLOBAL extern
#endif


#undef GLOBAL
//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#endif // end _WCLIP_H_

// *************************** End of File ************************************
