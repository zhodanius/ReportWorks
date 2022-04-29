// ****************************************************************************
//
//      (C) Copyright 1992-1993 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $Workfile:   qeval.h  $
// ================
//
// Description:
// ============
//
//	stuff having to do with early application of query
//
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/qeval.h_v  $
// 
//    Rev 1.2   21 Sep 1995 15:47:08   dlm
// FLDID-related edits.
// 
//    Rev 1.1   10 Jul 1995 10:55:44   dlm
// Changed functions to CRrDoc member functions and variables to CRrDoc
//  member variables.
// 
//    Rev 1.0   16 Mar 1995 16:13:16   sbc
// Initial revision.
// 
//    Rev 1.3   23 Jan 1995 09:35:00   dlm
// Eliminate compiler warnings in mfrdnext.c by changing type of second
//  argument to LPVOID, since it is sometimes an LPMFFIELD, sometimes LPFILE.
// 
//    Rev 1.2   20 Jan 1995 15:57:20   dlm
// Fixes compiler warnings in sxeeval.c.
// 
//    Rev 1.1   10 Mar 1994 14:44:30   nwh
// (dlm) Seems to fix a few typos.  Mostly just some reformatting.  Also
//  adds "far" to a few declarations.
// 
//    Rev 1.0   20 Jan 1994 16:51:00   nwh
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _QEVAL_H_

//
// Includes needed by this header.
//
//
#include	"mffile.h"

#if defined _SXEPREP_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

// Make a definition for this module.
//
#define _QEVAL_H_

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

// values stored in qqVal members during query evaluations

#define qqVT		1		// TRUE
#define qqVF		-1		// FALSE
#define qqVI		0		// unknown

// values stored in qqTok members during query parsing

#define qqTTERM		0		// "terminal" node
#define qqTAND		1		// "and"
#define qqTOR		2		// "or"



// Structure embodying extra info about a "terminal" node of query.
// When qtCount for one or more QTStr's becomes zero, a "try query"
//  flag gets inserted into an MFFIELD or MFFILE structure.
// The qtPtr member is used to convert an MFFIELD or MFFILE structure
//  address into an SXCurTime value.

//
// Structure Section:
// Place in this section any structure definitions.
//

typedef struct QTStr
{	int qtCount;				// number of fields still unknowable
	FLDID qtFID1;				// field index of 1st field in terminal
	FLDID qtFID2;				// field index of 2nd field in terminal
	struct QTStr far *qtNext;	// link to next of these structures
	struct QQStr far *qtDad;	// link to QQSTR parent of this structure
	void far *qtPtr;			// address of object responsible for this eval
} QTSTR;

typedef QTSTR far * LPQTSTR ;

// Structure embodying info about "and", "or", or "terminal" node.
// The linked lists of QQStr & QTStr structures is built by or after
//  sxparse() and used by a routine called at Print Go after mfeord()
//  has built evaluate chains.  The qqVal members are initialized to
//  "indeterminate" (qqVI).  As query is re-evaluated, various qqVal
//  members may change to qqVT or qqVF.  qqVal members are all reset to
//  qqVI before the building of each composite record.

typedef struct QQStr
{	int qqTok;					// "and", "or", or terminal
	int qqVal;					// at eval time, "t", "f", or "?"
	struct QQStr far *qqSib;	// link to next sibling struct
	int qqCOff;					// offset to code fragment (qqTok=qqTTERM)
	unsigned int qqTStamp;		// "time" at which this "term" is evaluatable
	union
	{	struct QQStr far *qqAndOr;	// link to 1st child struct (qqTok=qqTAND/TOR)
		QTSTR far *qqTerm;		// link to terminal struct (qqTok=qqTTERM)
	} qqChild;
} QQSTR;

typedef QQSTR far * LPQQSTR ;

//
// Global Data Section:
// Place in this section any global data.
//


#if 0	// moved to rrdoc.h
GLOBAL LPQTSTR QTFirst;		// pointer to first QTStr
GLOBAL LPQQSTR QQFirst;		// pointer to root QQStr node of query
GLOBAL LPSTR EvalStart;
GLOBAL int QQError;
GLOBAL unsigned int SXCurTime;
GLOBAL int SXMultiScan;
#endif



//
// Function Prototypes Section:
// Place in this section any function prototypes
//



#if 0	// moved to rrdoc.h
//		from sxeprep.c
void	freeqqstr(LPQQSTR qq) ;
void	sxclearval(LPQQSTR qq) ;
int		sxeprep(void) ;
int		sxeord(void) ;

//		from sxeeval.c
int		sxeeval(LPSTR eval, LPVOID ptr) ;
#endif


#undef GLOBAL
#endif // end _QEVAL_H_

// *************************** End of File ************************************

