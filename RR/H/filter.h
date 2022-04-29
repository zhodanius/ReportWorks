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
// $Log:   D:/R&R Project/archives/H/FILTER.H_V  $
// 
//    Rev 1.9   Sep 05 2002 12:19:54   Admin
// Clean up for query
// 
//    Rev 1.8   06 Jun 1996 14:21:16   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.7   22 Sep 1995 09:21:44   dlm
// FLDID-related edits.
// 
//    Rev 1.6   21 Sep 1995 17:13:50   dlm
// FLDID-related edits.
// 
//    Rev 1.5   21 Sep 1995 15:47:34   dlm
// FLDID-related edits.
// 
//    Rev 1.4   10 Jul 1995 10:55:40   dlm
// Changed functions to CRrDoc member functions and variables to CRrDoc
//  member variables.
// 
//    Rev 1.3   01 May 1995 16:44:44   dlm
// Just aligned some stuff while I was in there checking for merge stuff.
// 
//    Rev 1.2   28 Apr 1995 09:28:52   sbc
// Fix prototypes that weren't changed for merge
// 
//    Rev 1.1   26 Apr 1995 11:51:54   pjm
// 
// 6.1.03 -> 7.0 merge
// 
//    Rev 1.0   16 Mar 1995 16:12:40   sbc
// Initial revision.
// 
//    Rev 1.6   06 Apr 1995 10:04:52   dlm
// Fixed an off-by-one error in a couple of filter-validation error message
//  numbers.  sxerr_???? must be one higher than corresponding error message
//  in 0900 range.
// 
//    Rev 1.5   03 Apr 1995 11:27:30   dlm
// Added some error message codes for datetimes and times.
// 
//    Rev 1.4   08 Feb 1995 13:29:12   sjo
// Checking in a bunch of files for the first wave of datetime support. These
// sources have support for a dFlags that is a long (not an unsigned int) and
// it recognizes date, time and datetime fields.  It only supports dates at
// this time, because we need calcs, picture types, etc if we are to do time and
// datetime.
// 
// 
// 
//    Rev 1.3   08 Jun 1994 15:11:00   erp
// replaced FAR and __near with far and near for 32-bit builds
// 
//    Rev 1.2   20 Dec 1993 17:53:58   jpb
// get rid of QSwitch
// 
//    Rev 1.1   19 Nov 1993 17:42:42   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:11:52   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _FILTER_H_

//
// Includes needed by this header.
//
	#include "mffield.h"

#if defined _PKSX_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

//
// Make a definition for this module.
//
#define _FILTER_H_

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
// connector codes
#define SX_NONE	0	// means "first term"
#define SX_AND	1	// "and"
#define SX_OR	2	// "or"

// condition codes
#define	SX_EQ		1	// is equal to
#define	SX_NE		2	// is not equal to
#define	SX_GT		3	// is greater than
#define	SX_GE		4	// is greater than or equal to
#define	SX_LT		5	// is less than
#define	SX_LE		6	// is less than or equal to
#define	SX_RANGEEQ	7	// is in the range
#define	SX_RANGENE	8	// is not in the range
#define	SX_LISTEQ	9	// is in the list
#define	SX_LISTNE	10	// is not in the list
#if defined(RSW)
#define SX_LIKE		11	// is like (SQL only)
#define SX_NLIKE	12	// is not like (SQL only)
#define SX_ISNULL	13	// is NULL (SQL only)
#define SX_ISNNULL	14	// is not NULL (SQL only)
#endif

// True if condition needs right-hand field
#if defined(RSW)
#define NEEDS_RFLD(condn) ((condn) != SX_ISNULL && (condn) != SX_ISNNULL)
#else
#define NEEDS_RFLD(condn) (TRUE)
#endif

// True if condition needs a list

#define NEEDS_LIST(condn) ((condn) == SX_LISTEQ || (condn) == SX_LISTNE)

// True if condition needs a range
#define NEEDS_RANGE(condn) ((condn) == SX_RANGEEQ || (condn) == SX_RANGENE)


#define	SXPARSE_MEM		1	// memory fault on eval buffer
#define	SXPARSE_INTERR	2	// inconceivable program error
#define	SXPARSE_COMPLEX	3	// too hairy

typedef struct pksx				// RRW query interface packet
{
	char	connector;	// see connector codes in pksx.h
	char	lpcount;	// number of left parens
	FLDID	lfield;		// left comparand field index
	char	condition;	// see condition codes in pksx.h
	FLDID	rfield;		// right comparand field index, if field
	char 	rvalue[MAX_EDIT+1];	// right comparand string
	char	rpcount;	// number of right parens
} PKSX;
typedef PKSX far * LPPKSX;

//
// Special values for pksx.rfield (must be negative)
//
//  See PRODUCT.H for definition of FLDID.

const FLDID RFLD_BAD =		0xFFFFFFFF;
const FLDID RFLD_LITERAL =	0xFFFFFFFE;
const FLDID RFLD_UNNEEDED =	0xFFFFFFFD;
//#define RFLD_BAD -1
//#define RFLD_LITERAL -2
//#define RFLD_UNNEEDED -3

//  Used by sxeprep to prevent certain fields from ever being evaluated "early".
//  Must be different from NOID.  (See product.h.)
const FLDID ID_NEVER = 		0xFFFFFFFE;


// error codes
#define sxerr_nolfield		1	// missing first field
#define sxerr_badstr		2	// unterminated string
#define sxerr_qual			3	// fieldname must be qualified
#define sxerr_neednum		4	// numeric required
#define sxerr_needstr		5	// string required
#define sxerr_needdate		6	// date required
#define sxerr_baddate		7	// invalid date literal
#define sxerr_qindirect		8	// invalid used of query function
#define sxerr_fieldtype		9	// field types don't match
#define sxerr_needboole		10	// logical required
#define sxerr_token			11	// bum token
#define sxerr_memocomp		12	// can't compare memo to another field
#define sxerr_rangefld		13	// can't use field in range
#define sxerr_listfld		14	// can't use field in list
#define sxerr_onlyone		15	// single value required
#define sxerr_nofield		16	// fieldname not allowed in range or list
#define sxerr_onlytwo		17	// two values required for range
#define sxerr_badrange		18	// can't use empty value in range
#define sxerr_rangeorder	19	// range no in order
#define sxerr_shortlist		20	// list must have more than one entry
#define sxerr_parens		21	// unbalanced parens
#define sxerr_recno			22	// query on recno
#define sxerr_pageno		23	// query on pageno
#define sxerr_runtot		24	// query on running with finals
#define sxerr_totlvl		25	// query on non-highest final
#define sxerr_badrun		26	// invalid running total query
#define sxerr_badwild		27	// wildcard characters not allowed
#define sxerr_needdatetime	30	// datetime required
#define sxerr_needtime		31	// time required

//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//


#if 0	// moved to rrdoc.h
GLOBAL int	near SXTot;
GLOBAL int near SXSortComp
 #if defined(_PKSX_C_)
	= 0
 #endif
;
GLOBAL int near InMMatch
 #if defined(_PKSX_C_)
	= FALSE
 #endif
;
 #if defined(RSW)
GLOBAL int QueryChanged;
GLOBAL int near SXForSelect
  #if defined(_PKSX_C_)
	= FALSE
  #endif
;
 #endif
#endif



//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#if 0
extern	int sxfintot(char far *expr,unsigned int elgt);
extern	int sxruntot(char far *expr,unsigned int elgt);
extern	int sxreject(char far *eval,int nottot);
extern	char *sxcktot(struct mffield far *fld,char far *expr,unsigned int elgt);
extern	int sxbadfinal(char far *expr,unsigned int elgt);
extern	void sxneeded(char far *expr,unsigned int elgt);
extern	int sxdelfld(char far *expr,unsigned int elgt,unsigned int ix);
extern	int sxload(int termcnt,struct pksx far *termarray);
extern	int sxdoit(int termcnt,struct pksx far *termarray,int *errcode,int *changed);
extern	int sxlen(void );
extern	int sxvalidate(char far *expr,unsigned int elgt);
extern	int sxvalterm(struct pksx far *term,int *errcode,int *erroffP);
extern	int sxvalquery(int termcnt,struct pksx far *termarray,int *errcode,int *badterm);
extern	void sxprint(char far *buf,int maxsize);
extern	int sxinuse(char far *expr,unsigned int elgt,int ix);
extern	int sxparse(void );
extern	void sxunparse(void );
extern	char *testwdate(char *input);
extern	void sxinvalue(char *in,char *out,int type);
extern	int sxterms(void );
extern	int sxlcompvalue(char far *left,char far *right,unsigned long type);
extern	int sxcompvalue(char near *left,char near *right,unsigned long type);
 #ifdef RSW
extern	int sxselect(char far *outSpace,char *prefix);
extern	int lsxmmatch(char far *pat,struct mffield far *fld,int wilds);
 #else
extern	int lsxmmatch(char far *pat,struct mffield far *fld);
 #endif
 #ifdef RSW
extern	void sxrepfld(char far *expr,unsigned int elgt,int old,int newsx);
 #endif
#endif

#undef GLOBAL
#endif // end _FILTER_H_

// *************************** End of File ************************************
