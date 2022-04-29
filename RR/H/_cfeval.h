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
// $Log:   D:/workhere/arpeggio/randr/Archive/H/_cfeval.h_v  $
// 
//    Rev 1.5   Aug 30 1999 15:43:30   BUILD
// ARP20001
// 
//    Rev 1.4.1.0   15 Jul 1998 11:38:44   wrr
// Code ported from 16bit to 32bit
// Jim added the percomp()
// WO157195
// 
// Rev 1.9.1.0   18 May 1998 17:44:50   jpb	   //WRR WO157195 7/1/98
// Add percomp function
// 

 
//    Rev 1.4   06 Jun 1996 14:12:40   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.3   20 Jul 1995 16:39:34   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.2   27 Apr 1995 12:37:24   sjo
// Merge of 6.1.03+.  I say + because I have added some of the time functions
// to this merge, which will be a part of 6.1.04.  I merged the CF directories
// and some H files (for the time function changes).
// 
//    Rev 1.1   26 Apr 1995 10:38:28   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.0   16 Mar 1995 16:14:14   sbc
// Initial revision.
// 
//    Rev 1.8   03 Apr 1995 15:46:52   pjm
// Updated for dtlookup and needs of other functions that might
// take a datetime arg.
// 
//    Rev 1.7   27 Mar 1995 19:33:10   sjo
// Added support for new DT functions.
// 
//    Rev 1.6   23 Mar 1995 17:09:50   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
// 
//    Rev 1.5   18 Jan 1995 17:50:44   sjo
// Made changes to remove compiler warnings.
// 
//    Rev 1.4   20 Jul 1994 17:28:18   vff
// Added ISNULL() for Runtime DLL/VBX
// 
//    Rev 1.3   16 Jun 1994 10:47:22   vff
// Merged RR6 functions into R?W 6.0
// 
//    Rev 1.2   08 Jun 1994 14:57:38   erp
// changed FAR to far, so it will build for 32-bits
// 
//    Rev 1.1   19 Nov 1993 17:43:44   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:12:12   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __CFEVAL_H_

//
// Make a definition for this module.
//
#define __CFEVAL_H_

#include "cfeval.h"
#include "sort.h"		// for SREmptyOrder (and brings in mffield.h)
#include "util.h"		// for ZDATETIME reference

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

// ************************************************
//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//

GLOBAL char near T0Trans []
#if defined (_EVAL_C_)
= "9999999999.99"
#endif
;

// Parentheses characters used for negative numbers if @( function specified
GLOBAL char near C19Trans
#if defined (_EVAL_C_)
 =  '('
#endif
;
GLOBAL char near T1Trans	[] 
#if defined (_EVAL_C_)
 =  ")"
#endif
;
// String added to transformed negative number if @X function specified
GLOBAL char near T2Trans	[] 
#if defined (_EVAL_C_)
=  " DB"
#endif
;
// String added to transformed positive number if @C function specified
GLOBAL char near T3Trans	[] 
#if defined (_EVAL_C_)
=  " CR"
#endif
;

// numeric format string characters, signifying ...
GLOBAL char near C1Trans
#if defined (_EVAL_C_)
 = '#'  		// a digit position
#endif
;
GLOBAL char near C2Trans
#if defined (_EVAL_C_)
 = '$'		// a fill character
#endif
;
GLOBAL char near C3Trans 
#if defined (_EVAL_C_)
 = '*'		// a fill character
#endif
;
GLOBAL char near C4Trans 
#if defined (_EVAL_C_)
 = '.'		// the decimal point position
#endif
;
GLOBAL char near C5Trans 
#if defined (_EVAL_C_)
 = ','		// the thousands separator
#endif
;

// character format string characters, signifying ...
GLOBAL char near C6Trans
#if defined (_EVAL_C_)
 = 'x'		// substitute current source character
#endif
;
GLOBAL char near C7Trans 
#if defined (_EVAL_C_)
 = 'X'		// substitute current source character
#endif
;
GLOBAL char near C8Trans 
#if defined (_EVAL_C_)
 = '!'		// substitute uppercase of current source char
#endif
;

// As the first character of a format string, signifies that functions follow
GLOBAL char near C9Trans 
#if defined (_EVAL_C_)
 = '@'
#endif
;
// numeric format string functions
GLOBAL char near C10Trans 
#if defined (_EVAL_C_)
 = 'C'		// add " CR" to positive numbers
#endif
;
GLOBAL char near C11Trans 
#if defined (_EVAL_C_)
 = 'X'		// add " DB" to negative numbers
#endif
;
GLOBAL char near C12Trans
#if defined (_EVAL_C_)
 = '('		// enclose negative numbers in parentheses
#endif
;
GLOBAL char near C13Trans
#if defined (_EVAL_C_)
 = 'B'		// left-justify number
#endif
;
GLOBAL char near C14Trans
#if defined (_EVAL_C_)
 = 'Z'		// show 0 as a string of fill characters
#endif
;

GLOBAL char near C17Trans
#if defined (_EVAL_C_)
 = '!'		// show all alphas as uppercase
#endif
;
GLOBAL char near C18Trans
#if defined (_EVAL_C_)
 = 'R'		// reuse source characters from places
#endif
;

//
// Function Prototypes Section:
// Place in this section any function prototypes
//
extern 	int fpercomp(void); //WRR WO157195 7/1/95.

#undef GLOBAL
#endif // end __CFEVAL_H_


// *************************** End of File *******************************
