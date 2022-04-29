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
// $Log:   H:/vcsmfc/h/ddata.h_v  $
// 
//    Rev 1.2   13 Jul 1995 10:13:20   sbc
// Remove dialog procs
// 
//    Rev 1.1   10 Jul 1995 16:17:56   sbc
// Move stuff to rrdoc.h
// 
//    Rev 1.0   16 Mar 1995 16:12:26   sbc
// Initial revision.
// 
//    Rev 1.6   28 Sep 1994 15:46:48   sbc
// FileOpenName -> Paths
// 
//    Rev 1.5   19 Aug 1994 09:31:14   erp
// fixed multiple include check section
// 
//    Rev 1.4   19 Aug 1994 09:17:02   erp
// fixed check for multiple include section
// 
//    Rev 1.3   11 Apr 1994 16:05:30   sbc
// Sort/group return now return boolean
// 
//    Rev 1.2   06 Dec 1993 17:31:04   jpb
// add extern for limitResult
// 
//    Rev 1.1   19 Nov 1993 17:42:50   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:10:34   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _DDATA_H_
//
// Make a definition for this module.
//
#define _DDATA_H_

#include "mffield.h"


#if defined _DQUERY_C_
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

//
// Function Prototypes Section:
// Place in this section any function prototypes
//

#undef GLOBAL
#endif // end _DDATA_H_

// *************************** End of File ************************************
