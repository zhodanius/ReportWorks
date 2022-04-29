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
// $Log:   H:/VCSMFC/H/_PIC.H_V  $
// 
//    Rev 1.2   06 Jun 1996 14:12:36   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.1   24 Jul 1995 14:27:08   pjm
// R&R class changes.
// 
//    Rev 1.0   16 Mar 1995 16:14:46   sbc
// Initial revision.
// 
//    Rev 1.1   19 Nov 1993 17:44:58   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:10:42   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __PIC_H_

//
// Make a definition for this module.
//
#define __PIC_H_

#include "pic.h"

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

	//	from winter.h 
// dates
// #define MAX_WIN_DATE_PIC	42		// maximum long date picture
//	iNegCurr values from WIN.INI:
//			0		($1)
//			1		-$1
//			2		$-1
//			3		$1-
//			4		(1$)
//			5		-1$
//			6		1-$
//			7		1$-

// macros for PIC routines to extract iNegCurr setting properties:
// NEGDASH true iff the negative sign is a dash
#define NEGDASH(i) (!(((i)==0)||((i)==4)))

// LEADNEG true iff the negative sing is leading
#define LEADNEG(i) (!(((i)==3)||((i)==6)||((i)==7)))

// LEADCUR true iff the currency sign is leading
#define LEADCUR(i) ((i)<4)

// SIGNFIRST true iff neg sign "closer" to value than currency sign is
#define SIGNFIRST(i) (((i)==2)||((i)==6))

// PARENCUR true if neg sign is parenthetical
#define PARENCUR(i) (((i) == 0) || ((i) == 4))

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
extern	void ictib(int c,int count,char *s,int before);
extern	void commas(char *num);
extern	void fixed(struct mffield FAR *fld,char *out);
#endif


#endif // end __PIC_H_

// *************************** End of File ************************************
