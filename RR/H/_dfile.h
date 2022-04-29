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
// $Log:   H:/vcsmfc/h/_dfile.h_v  $
// 
//    Rev 1.1   05 Jul 1995 09:51:48   sjo
// Merged in CSV changes from 6.5
// 
//    Rev 1.0   16 Mar 1995 16:14:20   sbc
// Initial revision.
// 
//    Rev 1.8   15 Sep 1994 13:51:30   erp
// fixed export bugs
// 
//    Rev 1.7   22 Aug 1994 11:13:18   erp
// moved common API to header file
// 
//    Rev 1.6   19 Jun 1994 14:48:56   smh
// Moved Avery Label ACROSS, DOWN, & read_Label proto to _wutil.h.
// 
//    Rev 1.5   16 Jun 1994 17:28:08   smh
// Moved avery label stuff from dfile to wutil.
// 
//    Rev 1.4   14 Jun 1994 15:49:24   smh
// Added some label constants, a label definition structure, and a prototype
// for Avery Labels support.
// 
//    Rev 1.3   06 Jun 1994 12:07:04   erp
// changed the return type definitions
// 
//    Rev 1.2   01 Mar 1994 13:54:36   erp
// moved constants to this header
// 
//    Rev 1.1   19 Nov 1993 17:39:34   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:10:26   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __DFILE_H_

//
// Make a definition for this module.
//
#define __DFILE_H_

#include "dfile.h"

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
#define RET_EXPORT 0 	// return values tell caller EXPORT or CLOSE selected
#define RET_CLOSE  1
#define RET_CANCEL 2

// Defines export type for common CSV routines.
#define WORDEXPORT 1
#define CSVEXPORT  2

//
// Global Data Section:
// Place in this section any global data.
//





//
// Function Prototypes Section:
// Place in this section any function prototypes
//





#endif // end __DFILE_H_

// *************************** End of File ************************************
