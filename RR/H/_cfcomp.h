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
// $Log:   H:/VCSMFC/H/_CFCOMP.H_V  $
// 
//    Rev 1.5   06 Jun 1996 14:12:38   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.4   15 Aug 1995 16:24:52   sjo
// Changes for RSW compiles.
// 
//    Rev 1.3   20 Jul 1995 16:39:30   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.2   27 Apr 1995 12:37:18   sjo
// Merge of 6.1.03+.  I say + because I have added some of the time functions
// to this merge, which will be a part of 6.1.04.  I merged the CF directories
// and some H files (for the time function changes).
// 
//    Rev 1.1   26 Apr 1995 10:38:02   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.0   16 Mar 1995 16:14:10   sbc
// Initial revision.
// 
//    Rev 1.13   10 Apr 1995 18:23:00   jpb
// datetime/time literal cleanup
// 
//    Rev 1.12   27 Mar 1995 19:32:44   sjo
// Added support for new DT functions.
// 
//    Rev 1.11   23 Mar 1995 17:09:48   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
// 
//    Rev 1.10   18 Jan 1995 17:50:28   sjo
// Made changes to remove compiler warnings.
// 
//    Rev 1.9   16 Jun 1994 16:20:44   vff
// Fix a typo in extern declaration (paged vs aged for AGED() function)
// 
//    Rev 1.8   16 Jun 1994 10:47:48   vff
// Merged RR6 functions into R?W
// 
//    Rev 1.7   08 Jun 1994 12:34:22   erp
//  changed FAR to far, so it will build for 32-bits
// 
//    Rev 1.6   14 Mar 1994 15:13:38   dlm
// Moved declaration of lcfreplace() to cfcomp.h from here..
// 
//    Rev 1.5   31 Jan 1994 15:33:08   unknown
// Fix inconsistent definition of savchain (near)
// 
//    Rev 1.4   07 Dec 1993 13:36:20   nwh
// Added Txdateformat for date literal
// 
//    Rev 1.3   23 Nov 1993 12:13:40   sbc
// C++ ifdefs
// 
//    Rev 1.2   23 Nov 1993 11:54:16   nwh
// No change.
// 
//    Rev 1.1   22 Nov 1993 15:00:20   nwh
// Added text for ODBC
// 
//    Rev 1.0.1.0   11 Jan 1994 10:46:34   dlm
// Moved extern for lcfreplace() to cfcomp.h.
// 
//    Rev 1.0   14 Oct 1993 10:12:10   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __CFCOMP_H_

//
// Make a definition for this module.
//
#define __CFCOMP_H_

// #include "cfcomp.h"

// Turn extern on or off. When off, instantiate them.
//
#if defined (_CFCOMP_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif


//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
	// from token.h   TLOG is in cfcomp.h cuz used in explt.c
#define TNULLSTR 0x40		/* set on t_str token code=> empty string */ 
#define TOKMASK  (~(TLOG|TNULLSTR)) /* mask to remove above magic bits */

/* note: this is defined (differently) in dexport.c */	
#define MAXFILE		8		/* maximum length of file name (alias) */

//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//

typedef struct optab
{
	char	oUnary;		/* unary precedence value */
	char	oBinary;	/* binary precedence value */
	char	oUAction;	/* unary action code */
	char	oBAction;	/* binary action code */
} OPTAB;

GLOBAL OPTAB optable[TOKEN_COUNT] 
#if defined (_CFCOMP_C_)
=
{
7, 4, a_uplus, a_plus,		/* t_plus */	/* unary higher than exp */
7, 4, a_uminus, a_minus,	/* t_minus */
0, 5, 0, a_div,				/* t_div */
0, 5, 0, a_mul,				/* t_mul */
0, 6, 0, a_exp,				/* t_exp */		/* exp lower than unary */
0, 5, 0, a_pct,				/* t_pct */
0, 0, 0, 0,					/* t_lp */
0, 0, 0, 0,					/* t_rp */
0, 0, 0, 0,					/* t_comma */
0, 0, 0, 0,					/* t_box */
0, 0, 0, 0,					/* t_eox */
0, 0, 0, 0,					/* t_err */
0, 0, 0, 0,					/* t_num */
0, 0, 0, 0,					/* t_func */
0, 0, 0, 0,					/* t_fld */
0, 0, 0, 0,					/* t_file */
0, 3, 0, a_eq,				/* t_eq */
0, 3, 0, a_neq,				/* t_neq */
0, 3, 0, a_le,				/* t_le */
0, 3, 0, a_ge,				/* t_ge */
0, 3, 0, a_lt,				/* t_lt */
0, 3, 0, a_gt,				/* t_gt */
#if defined(RSW)
0, 2, 0, a_and,				/* t_and (higher than t_or for SQLand Paradox) */
#else
0, 1, 0, a_and,				/* t_and */
#endif
0, 1, 0, a_or,				/* t_or */
2, 0, a_not, 0,				/* t_not */
0, 0, 0, 0,					/* t_true */
0, 0, 0, 0,					/* t_false */
0, 4, 0, a_cat,				/* t_cat */
0, 4, 0, a_tcat,			/* t_tcat */
0, 5, 0, a_subst,			/* t_subst */
0, 4, 0, a_str,				/* t_str */
0, 0, 0, 0,					/* t_noarg */
0, 0, 0, 0,					/* t_date */
0, 0, 0, 0,					/* t_pgerr */
0, 0, 0, 0,					/* t_memo */
0, 0, 0, 0					/* t_qualify */
}
#endif
;

#if defined (RSW)

//   RSWXLATE.INI key name strings (non-translatable)

GLOBAL char  near Txcomn[] 
#if defined (_CFCOMP_C_)
= "Common";		/* common section name */
#endif
;

GLOBAL char  near Txodbc[] 
#if defined (_CFCOMP_C_)
= "ODBC";		/* ODBC section name */
#endif
;

GLOBAL char near Txdateformat[] 
#if defined (_CFCOMP_C_)
= "DateFormat";		/* format of date literal */
#endif
;


GLOBAL char near Txdatetimeformat[] 
#if defined (_CFCOMP_C_)
= "DatetimeFormat";		/* format of datetime literal */
#endif
;


GLOBAL char near Txtimeformat[] 
#if defined (_CFCOMP_C_)
= "TimeFormat";		/* format of time literal */
#endif
;


GLOBAL char near Txplus[] 
#if defined (_CFCOMP_C_)
= "plus";			/* addition */
#endif
;

GLOBAL char near Txminus[] 
#if defined (_CFCOMP_C_)
= "minus";		/* subtraction */
#endif
;

GLOBAL char near Txdiv[] 
#if defined (_CFCOMP_C_)
= "div";			/* division */
#endif
;

GLOBAL char near Txmul[] 
#if defined (_CFCOMP_C_)
= "mul";			/* multiplication */
#endif
;

GLOBAL char near Txexp[] 
#if defined (_CFCOMP_C_)
= "oexp";			/* exponentiation */
#endif
;

GLOBAL char near Txuplus[] 
#if defined (_CFCOMP_C_)
= "uplus";		/* unary plus */
#endif
;

GLOBAL char near Txuminus[] 
#if defined (_CFCOMP_C_)
= "uminus";		/* unary negative */
#endif
;

GLOBAL char near Txpct[] 
#if defined (_CFCOMP_C_)
= "pct";			/* percentage */
#endif
;

GLOBAL char near Txeq[] 
#if defined (_CFCOMP_C_)
= "eq";				/* test for equality */
#endif
;

GLOBAL char near Txneq[] 
#if defined (_CFCOMP_C_)
= "neq";			/* test for inequality */
#endif
;

GLOBAL char near Txle[] 
#if defined (_CFCOMP_C_)
= "le";				/* test for less than or equal to */
#endif
;

GLOBAL char near Txge[] 
#if defined (_CFCOMP_C_)
= "ge";				/* test for greater than or equal to */
#endif
;

GLOBAL char near Txlt[] 
#if defined (_CFCOMP_C_)
= "lt";				/* test for less than */
#endif
;

GLOBAL char near Txgt[] 
#if defined (_CFCOMP_C_)
= "gt";				/* test for greater than */
#endif
;

GLOBAL char near Txand[] 
#if defined (_CFCOMP_C_)
= "and";			/* AND */
#endif
;

GLOBAL char near Txor[] 
#if defined (_CFCOMP_C_)
= "or";				/* OR */
#endif
;

GLOBAL char near Txnot[] 
#if defined (_CFCOMP_C_)
= "not";			/* NOT */
#endif
;

GLOBAL char near Txcat[] 
#if defined (_CFCOMP_C_)
= "cat";			/* + (normal concatenation) */
#endif
;

GLOBAL char near Txtcat[] 
#if defined (_CFCOMP_C_)
= "tcat";			/* - (trimmed concatenation) */
#endif
;

GLOBAL char near Txsubstr[] 
#if defined (_CFCOMP_C_)
= "osubstr"; 	/* $ (substring) */
#endif
;

GLOBAL char near Txdatedif[] 
#if defined (_CFCOMP_C_)
= "datedif";	/* subtract two dates */
#endif
;

GLOBAL char near Txplusdays[] 
#if defined (_CFCOMP_C_)
= "plusdays";	/* add date and number of days */
#endif
;

GLOBAL char near Txsubdays[] 
#if defined (_CFCOMP_C_)
= "osubdays";	/* subtract number of days from date */
#endif
;
#endif

//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#undef GLOBAL
#endif // end __CFCOMP_H_

// *************************** End of File ****************************
