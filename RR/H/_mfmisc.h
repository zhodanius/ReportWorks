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
// $Log:   H:/vcsmfc/h/_mfmisc.h_v  $
// 
//    Rev 1.1   07 Jul 1995 18:12:00   jpb
// First pass at moving all data and functions to CRrDoc class
// 
//    Rev 1.0   16 Mar 1995 16:14:44   sbc
// Initial revision.
// 
//    Rev 1.3   18 Feb 1994 15:26:04   sjo
// I am merging the RRWINNSX branch back onto the RRWIN tree. This branch was
// setup to allow me to port my RR 5.1 NSX, SMT and DBV changes to RRW and
// RSW.
// 
//    Rev 1.2.1.0   24 Jan 1994 09:37:26   sjo
// I am merging RR 5.1 changes into the windows products.  I added a call to
// initialize memos.
// 
//    Rev 1.2   19 Nov 1993 17:44:44   sbc
// Add extern C for C++
// 
//    Rev 1.1   04 Nov 1993 15:44:42   jpb
// Use MF "global internal header" _mf.h instead of foreign internal MF headers
// 
//    Rev 1.0   14 Oct 1993 10:12:40   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __MFMISC_H_

//
// Make a definition for this module.
//
#define __MFMISC_H_

#include "mfmisc.h"
#include "memo.h"

#if defined (_MFINIT_C_)
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


#if 0
// Already in mfmisc.h
// GLOBAL int near userQuit;	/* halt flag if user decided to get out */
GLOBAL long near SRReadCt;
GLOBAL long near SRSelCt;
GLOBAL long near SRGrpCt;



//
// Function Prototypes Section:
// Place in this section any function prototypes
//



// First group is from common MFMISC modules
extern	void mffixord(LPFLDHDR fld);

// Next group is from RRW-specific MFMISC modules
extern	void getdate(int hi,char *buf);
extern	int keytod(char *key,char *ascii);
extern 	int mf_memo_hdlr(int action, MF_MEMO_HDLR_PKT *a_mf_memo_hdlr_pkt);

#endif

#undef GLOBAL

#endif // end __MFMISC_H_

// *************************** End of File ************************************

