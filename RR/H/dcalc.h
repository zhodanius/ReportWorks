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
// $Log:   D:/R&R Project/archives/H/DCALC.H_V  $
// 
//    Rev 1.6   Mar 21 2001 10:01:46   nhubacker
// Purge Parameter
// 
//    Rev 1.5   Feb 27 2001 15:34:44   nhubacker
// Parameter
// 
//    Rev 1.4   Jan 19 2001 14:06:48   nhubacker
// New calc. type TPARAM
// 
//    Rev 1.3   Dec 05 2000 12:59:38   nhubacker
// Add TINDEX type code for Index expression dialog
// 
//    Rev 1.2   16 Dec 1996 14:33:36   par
// Remove unused externs.
// 
//    Rev 1.1   17 Jul 1995 16:41:40   dlm
// Changed functions to CRrDoc member functions and variables to CRrDoc
//  member variables.
// 
//    Rev 1.0   16 Mar 1995 16:12:26   sbc
// Initial revision.
// 
//    Rev 1.4   03 Aug 1994 21:50:06   smh
// Calc/Tot comment - added proto for fieldCommentDialog()
// 
//    Rev 1.3   27 Jul 1994 17:50:40   jpb
// add externs for auto total create
// 
//    Rev 1.0   27 Jul 1994 17:48:26   jpb
// Initial revision.
// 
//    Rev 1.2   25 Jul 1994 17:24:38   jpb
// add TTOTCND
// 
//    Rev 1.1   19 Nov 1993 17:45:18   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:11:54   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _DCALC_H_

#include "mffield.h"
#include "cfmisc.h"

#if defined _DCALCTOT_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

//
// Make a definition for this module.
//
#define _DCALC_H_

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

/* type codes (input) */
#define TCALC	0x01
#define TUDF	0x02
#define TQUERY	0x04
#define TTOTCND	0x08
#define TINDEX	0x10
#define TPARAM  0x20
#define TPARCND	0x40

/* status member bits (output) */
#define BADCNAME	0x01	/* calc name or udf decl is bad */
#define BADCFORM	0x02	/* formula is bad */
#define QCHANGE		0x04	/* query, sort, or link changed this pass */

/* for purge routines */
#define PURGECALCS	0x01	/* purge flag for calcs */
#define PURGETOTS	0x02	/* purge flag for totals */
#define PURGEPARS	0x04	/* purge flag for parameters */

/* status member bits (input) */
#define CDELETE	0x01	/* set=> calc or udf is being deleted */

//
// Structure Section:
// Place in this section any structure definitions.
//

#undef GLOBAL
#endif // end _DCALC_H_

// *************************** End of File ************************************
