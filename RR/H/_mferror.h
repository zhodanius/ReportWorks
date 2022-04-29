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
// $Log:   H:/vcsmfc/h/_mferror.h_v  $
// 
//    Rev 1.1   07 Jul 1995 18:11:58   jpb
// First pass at moving all data and functions to CRrDoc class
// 
//    Rev 1.0   16 Mar 1995 16:14:38   sbc
// Initial revision.
// 
//    Rev 1.3   19 Nov 1993 17:44:40   sbc
// Add extern C for C++
// 
//    Rev 1.2   04 Nov 1993 15:44:40   jpb
// Use MF "global internal header" _mf.h instead of foreign internal MF headers
// 
//    Rev 1.0   14 Oct 1993 10:12:38   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __MFERROR_H_

//
// Make a definition for this module.
//
#define __MFERROR_H_

#include "mferror.h"

#include "mffield.h"

#if defined (_MFERROR_C_)
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



#if 0
extern	int ckfins(HWND handy,int warn,char far *expr,UTWO lgt);
extern	int mfbadfinal(void);
extern	char *mfmess(LPMFFIELD fld,char *msgbuf);
extern	int mfruntot(void);
#endif


#undef GLOBAL

#endif // end __MFERROR_H_

// *************************** End of File ************************************

