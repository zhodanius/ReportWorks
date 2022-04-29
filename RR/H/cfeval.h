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
// $Log:   D:/R&R Project/archives/H/CFEVAL.H_V  $
// 
//    Rev 1.4   Aug 30 2001 09:05:28   nhubacker
// Redefine MAX_DAYS
// 
//    Rev 1.3   29 Aug 1995 13:26:04   mjs
// win32
// 
//    Rev 1.2   20 Jul 1995 16:39:32   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.1   26 Apr 1995 10:38:16   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.0   16 Mar 1995 16:12:14   sbc
// Initial revision.
// 
//    Rev 1.4   31 Mar 1995 18:00:48   jpb
// datetime changes
// 
//    Rev 1.3   31 Mar 1995 14:29:10   jpb
// fix macro
// 
//    Rev 1.2   16 Jun 1994 10:49:30   vff
// No change.
// 
//    Rev 1.1   19 Nov 1993 17:43:28   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:12:06   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _CFEVAL_H_

//
// Make a definition for this module.
//
#define _CFEVAL_H_

#include "MFFIELD.H"

#if defined(_EVAL_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
//#define MAX_DAYS 292499			/* 12/31/2400 - 3/1/1600 (in days) */
#define MAX_DAYS 511279				// 12/31/2999 - 3/1/1600 (in days)


/* macros to convert between CDS date format (long) and
   dBASE date key format (double)
*/
#define DAYStoDB(days) ((double)(2305508.0+(double)(days)))
#define DBtoDAYS(dbl) ((long)((double)(dbl) - 2305508.0))

/* and datetime value and FOX key value */
#define DATETIMEtoDB(date,time) ((double)((2305508.0+(double)(date))+(((double)time)/86400000000.0)))
#define DBtoDTTIME(dbl) (((double)(dbl)-floor((double)(dbl)))*86400000000.0)
#define DBtoDTDATE(dbl) ((long)floor((double)(dbl) - 2305508.0))

/* special long values (dates) */
#define ZRANGEDATE	(0x80000000L)
#define ZEMPTYDATE	(0x80000001L)
#define ZNADATE		(0x80000002L)
#define ZERRDATE	(0x7FFFFFFFL)

#define ZLATSTAR	(0x800001FEL)	/* Jan anything, 1600 */
#define ZHATSTAR	(0xFFFFFFFFL)	/* today */
/* wild card & "today's" dates have the form:
	high-order bit set
	15-bit year field	(0 => 1600)
	8-bit month field	(1 => January)
	8-bit day field		(1 => 1st)
   with the special values:
	-1 => @ (today's year, month, or day)
	-2 => * (any year, month, or day)
   For example,
	0x82000101L is Jan 1, (year 0x200 = 1600+512 =) 2112 and
	0x8200FFFEL is any day in today's month in 2112.
*/
#define ZTWILDDATE(d) ((d) <= ZHATSTAR && (d) >= ZLATSTAR)

/* macros for testing for, or setting to, the null date value */
#define ZTNULLDATE(d) ((d) == ZEMPTYDATE)	/* d is a FOUR */
#define ZSNULLDATE(p) (*(p) = ZEMPTYDATE)	/* p points to a FOUR */

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

typedef int (FAR PASCAL* LPFN_DLL)(char FAR *);

#undef GLOBAL
#endif // end _CFEVAL_H_

// *************************** End of File ************************************
