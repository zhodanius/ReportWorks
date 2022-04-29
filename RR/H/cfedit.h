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
// $Log:   H:/VCSMFC/H/CFEDIT.H_V  $
// 
//    Rev 1.3   18 Aug 1995 14:50:22   mjs
// Moved strings to global.h.
// 
//    Rev 1.2   02 Aug 1995 11:08:38   sjo
// Moved some variables from the doc class to this header.
// 
//    Rev 1.1   20 Jul 1995 16:39:36   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.0   16 Mar 1995 16:12:12   sbc
// Initial revision.
// 
//    Rev 1.2   14 Mar 1994 15:31:28   dlm
// From Abra branch, added delcaration of crecomp(), which is no longer static.
// 
//    Rev 1.1   19 Nov 1993 17:43:26   sbc
// Add extern C for C++
// 
//    Rev 1.0.1.0   28 Feb 1994 11:09:38   dlm
// Added extern declaration for crecomp() which is no longer static.
// 
//    Rev 1.0   14 Oct 1993 10:12:06   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _CFEDIT_H_

//
// Make a definition for this module.
//
#define _CFEDIT_H_

#include "MFFIELD.H"			// Needed for MFFIELD references
#include "CFMISC.H"			// Needed for UDF references

#if defined(_EDITCALC_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
	// from cfcomp.h
#define ue_niu	1		/* user function name in use */
#define ue_nop	2		/* no opening parenthesis */
#define ue_ban	3		/* bad argument name */
#define ue_ncp	4		/* no closeing parenthesis */
#define ue_bfn	5		/* bad function name */
#define ue_aiu	6		/* argument name in use */
#define ue_mem	7		/* insufficient memory */
#define ue_mar	8		/* missing argument */
#define ue_anu	9		/* name not unique in forst four chars */

							/* ^ == \/ */
#define ue_max	9		/* highest error code value */

//
// Structure Section:
// Place in this section any structure definitions.
//
//
// Global Data Section:
// Place in this section any global data.
//

GLOBAL LPSTR lpszTPTRUE;
GLOBAL LPSTR lpszTPYES;
GLOBAL LPSTR lpszTPON;
GLOBAL LPSTR lpszTPFALSE;
GLOBAL LPSTR lpszTPNO;
GLOBAL LPSTR lpszTPOFF;
GLOBAL LPSTR lpszTPAND;
GLOBAL LPSTR lpszTPOR;
GLOBAL LPSTR lpszTPNOT;

GLOBAL LPSTR * near pwords[]
#if defined (_EDITCALC_C_)
 = {&lpszTPTRUE,&lpszTPYES,&lpszTPON,&lpszTPFALSE,&lpszTPNO,&lpszTPOFF,
   &lpszTPAND,&lpszTPOR,&lpszTPNOT,NULL};
#endif
;

//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#undef GLOBAL

#endif // end _CFEDIT_H_

// *************************** End of File ************************************
