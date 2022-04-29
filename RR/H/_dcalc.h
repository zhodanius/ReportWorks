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
// $Log:   H:/vcsmfc/h/_dcalc.h_v  $
// 
//    Rev 1.2   17 Jul 1995 16:41:50   dlm
// Changed functions to CRrDoc member functions and variables to CRrDoc
//  member variables.
// 
//    Rev 1.1   28 Apr 1995 09:18:34   sbc
// 6.1.03 -> 7.0.01 merge
// 
//    Rev 1.0   16 Mar 1995 16:14:18   sbc
// Initial revision.
// 
//    Rev 1.5   06 Mar 1995 13:06:08   jpb
// add condErr prototype (RRW 2302)
// 
//    Rev 1.4   02 Aug 1994 15:03:48   jpb
// Change batchReset() prototype
// 
//    Rev 1.3   01 Aug 1994 17:53:26   jpb
// prep for Batch Reset Change
// 
//    Rev 1.2   22 Jul 1994 18:28:40   jpb
// make internal global condTotP
// 
//    Rev 1.1   19 Nov 1993 17:43:54   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:11:56   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __DCALC_H_

//
// Make a definition for this module.
//
#define __DCALC_H_

#include "dcalc.h"
#include "mffield.h"

#if defined _DCALCUDF_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
#define TEXTLIMIT	50

//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//

#if 0
GLOBAL	LPSTR	totCondP;
#endif

//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#if 0
extern void batchReset(HWND hDlg);
extern void compErr(HWND hDlg,int qenum,int erroff,LPSTR errstr);
extern void condErr(HWND hDlg,int qenum);
extern LPMFFIELD getMarkedFld(void);
#endif


#undef GLOBAL
#endif // end __DCALC_H_

// *************************** End of File ************************************
