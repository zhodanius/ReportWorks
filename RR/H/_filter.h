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
// $Log:   D:/workhere/arpeggio/randr/Archive/H/_filter.h_v  $
// 
//    Rev 1.6   Aug 30 1999 15:43:30   BUILD
// ARP20001
// 
//    Rev 1.5   06 Jun 1996 14:12:44   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.4   28 Jul 1995 14:44:20   dlm
// Commented out #define of BOOL(x).
// 
//    Rev 1.3   10 Jul 1995 10:55:42   dlm
// Changed functions to CRrDoc member functions and variables to CRrDoc
//  member variables.
// 
//    Rev 1.2   01 May 1995 16:41:18   dlm
// Adjusted prototype for sxoutdate(). Moved sxout...() prototypes to
//  RSW conditional, since they're now in sxselect.c.
// 
//    Rev 1.1   26 Apr 1995 11:52:08   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.4   13 Apr 1995 18:43:16   dlm
// Removed duplicate definition of EditQuery (also in global.h).  Since this
//  one had an initializer and that one didn't, I moved the initializer to
//  global.h.  Also, note that this one was 'near' and that one wasn't.
// 
//    Rev 1.3   03 Apr 1995 17:46:10   dlm
// Removed 'edit' argument from sxoutdate() prototype.
// 
//    Rev 1.2   23 Mar 1995 17:09:58   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
//    Rev 1.1   19 Nov 1993 17:43:14   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:11:52   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __FILTER_H_

//
// Make a definition for this module.
//
#define __FILTER_H_

//
// Includes needed by this header.
//
	#include "filter.h"
	#include "mffield.h"	// for zfXXX definitions

#if defined _PKSX_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
	// from selex.h -- insertion file for selection expressions
/* codebytes for selection expression */

#define	LPAREN	'\050'
#define	RPAREN	'\051'
#define	ENDTERM	'\052'

#define	CONN_BASE	030	/* connector values start here */
#define	AND			'\030'
#define	OR			'\031'
#define	CONNECTOR	'\032'

#define	RELOP_BASE	001	/* relational operator values start here */
#define	EQ			'\001'
#define	NE			'\002'
#define	GT			'\003'
#define	GE			'\004'
#define	LT			'\005'
#define	LE			'\006'
#define	RANGEEQ		'\007'
#define	RANGENE		'\010'
#define	LISTEQ		'\011'
#define	LISTNE		'\012'
#if defined(RSW)
#define LIKE		'\013'
#define NLIKE		'\014'
#define ISNULL		'\015'
#define ISNNULL		'\016'
#define RELOP_CAP	PATNE
#else
#define	PATEQ		'\013'
#define	PATNE		'\014'
#define	RELOP_CAP	PATNE	/* relational operator values end here */
#endif

#define	TERM_BASE	040
#define	FIELD		'\040'
#define	TERM		'\041'
#define	KCHAR		'\042'
#define	KNUMBER		'\043'
#define	KDATE		'\044'
#define	KLOG		'\045'
#define	KMEMO		'\046'
#define KDATETIME	'\060'
#define KTIME		'\061'

// following block is support for prompting filters
#define	PROMPT		'\070'		// followed by prompt string, then default string
#define	FILLCHAR	'\071'		// single byte place holder for string value storage
#define	FILLNUMBER	'\072'		// followed by space for number (douoble)
#define	FILLDATE	'\073'		// followed by space for date (long)
#define	FILLLOG		'\074'		// followed by space for logical (single byte)
#define	FILLDATETIME '\075'		// followed by space for datetime (double and long)
#define	FILLTIME	'\076'		// followed by space for time (double)

#define	MATH_BASE	020
#define	PLUS		'\020'
#define	MINUS		'\021'
#define	TIMES		'\022'
#define	DIVIDED		'\023'
#define	PERCENT		'\024'

#define QUIT	2		/* we need to distinguish between Esc & \q */

/* screen attributes */
#define	aCONST		0
#define aOPER		0
#define aCONNECT	0
#define aCURRENT	0
#define	aBLANK		0
#define	aFIELD		0

/* display area */
#define	sTOP		4	/* topmost usable row inside box */
#define	sBOTTOM		13
#define	sLEFT		0	/* leftmost usable column inside box */
#define	sRIGHT		zMAXCOL
#define trMAIN		(sBOTTOM+1)
#define tcMAIN		0
#define thMAIN		(22-trMAIN)
#define twMAIN		30
#define trRELOP		(trMAIN+1)
#define tcRELOP		25
#define thRELOP		(thMAIN-1)
#define twRELOP		25
#define trCOMP		(trRELOP+1)
#define tcCOMP		40
#define thCOMP		(thRELOP-1)
#define twCOMP		36
#define trCONN		trMAIN
#define tcCONN		72
#define thCONN		3
#define twCONN		4

/* editing area */
#define	eTOP		(sBOTTOM+2)
#define	eBOTTOM		(eTOP+1)
#define	eLEFT		sLEFT
#define	eRIGHT		sRIGHT

/* size of temporary storage areas */
#define	MAX_POS		50			/* separate items we can position to */
#define	TERM_BUF	200			/* total term storage */
#define MAX_LIST	10			/* maximum items in a "list" */
#define FLMAXQ		(50+3)		/* max length of a quoted field value */

/* switch between ends of term or expression */
#define	ENDS_KEY	0x7500		/* ^End */

/* indices into SXIndex for early part of term */
#define	pFIELD	0
#define	pRELOP	1
#define	pCOMP	2

/* mask to retain type of an ISAM field */
#define	SX_DTYPE	(zfNUMERIC | zfDATE | zfLOGICAL | zfMEMO | zfDATETIME | zfTIME)

/* long number in evaluatable form has top bit of first byte set */
#define	LONGNUM	(1 << (BITSperBYTE-1))

/** for debugging purposes **/

//#define	BOOL(x)	((x)?"TRUE":"FALSE")

/* match any number of any character */
#define	WILD ('*')
/* match any single character */
#define ANY ('?')


// ********************************************************************
//
// Structure Section:
// Place in this section any structure definitions.
//

// from sxparse.cpp
typedef struct TempItem
{
	int 	tiBytes;				/* bytes for this item */
	int 	tiClass;
	char	far *tiItem;			/* pointer to actual text of item */
} TEMPITEM;

typedef struct OutItem
{
	int 			oiBytes;		/* bytes for this subpiece */
	int 			oiClass;
	char		far *oiItem;		/* pointer to actual text of item */
	struct OutItem	*oiChild;
	struct OutItem	*oiSibling;
} OUTITEM;

// ********************************************************************
//
// Global Data Section:
// Place in this section any global data.
//


#if 0	// moved to rrdoc.h
GLOBAL int  near SXAllNormal;
GLOBAL int	near SXUsed;
 #if defined(INTERACTIVE)
GLOBAL char	far * near SXCurPtr;
 #endif
GLOBAL unsigned int	near SXIx;
GLOBAL int * near SXRow;
GLOBAL int * near SXCol;
GLOBAL int * near SXIndex;
GLOBAL char	* near SXTerm;
GLOBAL char	* near SXExpr;
GLOBAL char	near SXRelOp;
GLOBAL char * near SXRelOpP;
GLOBAL int	near SXNumItems;
GLOBAL int	SXAbortL[];
GLOBAL int	near SXComplete;
GLOBAL int	near SXQuiet;
GLOBAL int	near SXTermFull;
GLOBAL int	near SXAutoErase;
GLOBAL int	near SXForBox;
GLOBAL int	near SXForSelect;
GLOBAL int	near SXTooLong;
GLOBAL LPMFFIELD near SXMainField;
GLOBAL char *near SXOutChar;
GLOBAL char *SelList[];
 #if defined(RSW)
GLOBAL char far *SXOpPtr;
GLOBAL char far *SXSelOut;
GLOBAL char near SXSelOp;
 #endif
#endif


// ********************************************************************
//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#if 0
extern	char sxtype(int typeBits);
extern	int sxcompfield(struct mffield FAR *f,char FAR *v);
extern	int sxgetnum(char FAR **eval );
extern	int sxbytes(char FAR *item);
extern	int sxvaldel(char FAR *expr,unsigned int elgt,int (*func)(int ));
extern	int sxokay(char FAR *expr,unsigned int elgt);
 #ifdef RSW
extern	int bscount(char FAR *p,int lgt);
 #else
extern	int bscount(char *p,int lgt);
 #endif
extern	int sxtotal(char FAR *expr,unsigned int elgt);
extern	int sxlvlerr(unsigned int fno);
 #ifdef RSW
extern	void sxoutnum(char FAR *num,char FAR *string);
extern	void sxoutdate(char FAR *dt,char FAR *string);
extern	void sxoutstring(char FAR *in,char FAR *out);
extern	void sxoutval(char type,char FAR *in,char FAR *out,int mn,int mx);
extern	void fixLower(void);
 #endif
#endif

#undef GLOBAL
#endif // end __FILTER_H_

// *************************** End of File ************************************

