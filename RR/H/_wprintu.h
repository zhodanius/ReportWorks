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
// $Log:   H:/vcsmfc/h/_wprintu.h_v  $
// 
//    Rev 1.6   01 Aug 1995 11:38:30   sbc
// Moved stuff to rrview.h
// 
//    Rev 1.5   18 Jul 1995 15:37:56   smh
// Made char arrays NEAR.
// 
//    Rev 1.4   18 Jul 1995 09:54:26   sbc
// Move print-related prototypes to rrdoc.h
// 
//    Rev 1.3   18 Jul 1995 09:44:00   smh
// Classification.
// 
//    Rev 1.2   28 Jun 1995 15:45:00   smh
// Merged CSV export changes from 6.5.
// 
//    Rev 1.1   25 Apr 1995 15:11:00   smh
// Merged 6.1.03 and 7.0 headers.
// 
//    Rev 1.0   16 Mar 1995 16:15:12   sbc
// Initial revision.
// 
//    Rev 1.5   12 Jun 1995 13:48:06   smh
// CSV Export
// 
//    Rev 1.4   08 Feb 1995 10:54:36   smh
// Made lpfnCreate a global, now call it from print code for bug
// RRW 2278 / RSW 1704
// 
//    Rev 1.3   28 Apr 1994 15:58:00   sbc
// DbfXStr now far pointer.  Remove TextExportFile[].
// 
//    Rev 1.2   29 Dec 1993 13:34:28   smh
// Database export:  Changed and added some prototypes.
// See Scott for complete list of files.
// 
//    Rev 1.1   19 Nov 1993 17:40:46   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:11:08   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __WPRINTU_H_

//
// Make a definition for this module.
//
#define __WPRINTU_H_

#include "wprintui.h"
#include "mffile.h"			// for LPMFFILE
#include "pd.h"				// for database export structure

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

#if defined(_WEXPORT_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif


GLOBAL char NEAR WxCSVExt[] 
#if defined _WEXPORT_C_
 = "CSV"
#endif
;
GLOBAL char NEAR WxSDFExt[] 
#if defined _WEXPORT_C_
 = "SDF"
#endif
;

// Paths->RpEName now holds text export path (sbc 4/28/94)
//GLOBAL char	TextExportFile[WINPATHLEN+1];




//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#undef GLOBAL

#endif // end __WPRINTU_H_

// *************************** End of File ************************************
