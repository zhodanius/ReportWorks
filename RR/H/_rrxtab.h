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
// $Log:   H:/vcsmfc/h/_rrxtab.h_v  $
// 
//    Rev 1.0   16 Mar 1995 16:14:54   sbc
// Initial revision.
// 
//    Rev 1.1   10 Mar 1994 14:16:30   erp
// fixed bug in memory management
// 
//    Rev 1.0   22 Feb 1994 11:06:10   erp
// Initial revision.
// 
//    Rev 1.4   20 Dec 1993 11:53:30   mjs
// Changed #ifdef PD_MAIN to #ifdef PD_DRIVER so global gets init'd.
// 
//    Rev 1.3   29 Nov 1993 15:03:58   erp
// added extern needed from mem.c source files
// 
//    Rev 1.2   19 Nov 1993 17:41:48   sbc
// Add extern C for C++
// 
//    Rev 1.1   21 Oct 1993 17:10:22   smh
// Added argument to pwEndBand() prototype.
// 
//    Rev 1.0   14 Oct 1993 10:11:18   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __RRXTAB_H_
//
// Make a definition for this module.
//
#define __RRXTAB_H_

#include "rrxtab.h"
#include "crstabif.h"


#ifdef _RRXTAB_CPP_
#define GLOBAL
#else
#define GLOBAL extern
#endif


extern BOOL DLLENTRY XTAB_DlgBoxProc (HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam);

#undef GLOBAL



#endif

