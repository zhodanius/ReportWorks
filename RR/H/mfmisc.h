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
// $Log:   H:/VCSMFC/H/MFMISC.H_V  $
// 
//    Rev 1.3   06 Jun 1996 14:21:56   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.2   07 Jul 1995 18:11:46   jpb
// First pass at moving all data and functions to CRrDoc class
// 
//    Rev 1.1   26 Apr 1995 10:53:30   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.12   12 Apr 1995 17:45:26   jpb
// remove MFLongCharCutoff
// 
//    Rev 1.11   31 Mar 1995 18:00:46   jpb
// datetime changes
// 
//    Rev 1.10   09 Mar 1995 17:57:50   jpb
// add MF vars for [Database] settings
// 
//    Rev 1.9   09 Mar 1995 14:05:26   jpb
// add vars for new INI [Database] long char and memo settings
// 
//    Rev 1.8   14 Feb 1995 12:07:34   jpb
// Fix bug RSW 1496
// 
//    Rev 1.7   08 Feb 1995 13:29:16   sjo
// Checking in a bunch of files for the first wave of datetime support. These
// sources have support for a dFlags that is a long (not an unsigned int) and
// it recognizes date, time and datetime fields.  It only supports dates at
// this time, because we need calcs, picture types, etc if we are to do time and
// datetime.
// 
//    Rev 1.6   06 Feb 1995 10:40:20   jpb
// Change MFHiGroupAcceptCount to MFHiGroupAcceptAnys
// 
//    Rev 1.5   03 Feb 1995 15:01:00   jpb
// add MFHiGroupAcceptCount to fix final total bug.  RRW 306
// 
//    Rev 1.4   28 Sep 1994 15:46:52   sbc
// FileOpenName -> Paths
// 
//    Rev 1.3   08 Jun 1994 12:37:54   erp
//  changed FAR to far, so it will build for 32-bits
// 
//    Rev 1.2   20 Dec 1993 17:54:54   jpb
// get rid of bAlways... flags
// 
//    Rev 1.1   19 Nov 1993 17:44:08   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:12:24   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _MFMISC_H_

//
// Make a definition for this module.
//
#define _MFMISC_H_

#include "mfdata.h"
#include "mffile.h"
#include "mffield.h"
#include "util.h"	/* for ZDATETIME */

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

GLOBAL struct mflkbuf far * near LChain;		// start of buffer chain
GLOBAL char MFAAlias[MAXALIAS];			/* alias for ASCII file */
GLOBAL int MFACharSet;					/* 0=>OEM, 1=>ANSI */
GLOBAL int MFANamedMemos;				/* FALSE=> ascii file has no named memos; TRUE=>named memos */

GLOBAL char *MFAName					/* attached ASCII filename ptr */

 #if defined (_MFINIT_C_)
		= NULL;
 #else
 		;
 #endif

GLOBAL long near MFCompRec;				/* composite record number */
GLOBAL LPMFFIELD near MFEvalOnce;		/* chain for "evaluate once" */
GLOBAL LPMFFIELD near MFFields;			/* start of linked list of fields */
GLOBAL LPMFFILE near MFFiles[MFMAXFILES+1]; /* array of file pointers */
GLOBAL LPMFFILE near MFFromOrd[MFMAXFILES+1]; /* FROM clause file ptrs */
GLOBAL LPMFFIELD near MFGrpEval[NOBRKFLDS];	/* Group level reset chains */
GLOBAL BOOL MFHiGroupAcceptAny;			/* TRUE if any recs of current hi fintot group accepted by filter */
GLOBAL LPFLDHDR near MFHiPos;			/* last field in screen order */
GLOBAL unsigned int MFLongCharLimit;	/* init dLength to this if field longer */
GLOBAL int MFLongCharWrap;				/* TRUE=> default wordwrap limited "long" char fields */
GLOBAL unsigned int MFMemoLimit;		/* what to init dLength to for memo fields */
GLOBAL int MFMemoWrap;					/* TRUE=> default wordwrap memo fields */

GLOBAL LPFLDHDR near MFLoPos;			/* first field in screen order */
GLOBAL unsigned long near MFNdMask;		/* "current" zfNEEDED/zfLINK mask, set by mfgetbuf */
GLOBAL int near MFNewFinal;				/* TRUE=> must evaluate finals */
GLOBAL int near MFNoFiles;				/* current number of files open */
GLOBAL int near MFNoFlds;				/* current number of fields in list */
GLOBAL LPMFFIELD near MFPagEval;		/* page break eval chain */
GLOBAL LPMFFIELD near MFPerComp;		/* chain for "per composite" */

GLOBAL LPMFFIELD near MFQFld			/* MFQuery field */
 #if defined (_MFINIT_C_)
		= NULL;
 #else
 		;
 #endif

GLOBAL int near MFQFldFin				/* "MFQFld is final-related" flag */
 #if defined (_MFINIT_C_)
		= FALSE;
 #else
 		;
 #endif

GLOBAL char * near MFQuery			/* address of runtime query expression */
 #if defined (_MFINIT_C_)
		= NULL;
 #else
 		;
 #endif

GLOBAL int near MFRdErr;				/* TRUE if bad read error */
GLOBAL char far * near MFSelect;		/* address of selection expression */
GLOBAL LPMFFIELD near MFSumEval;		/* Summary ("eof break") eval chain */

GLOBAL int near SRCtNow			/* flag for unconditional display of counts */
 #if defined (_MFINIT_C_)
		= FALSE;
 #else
 		;
 #endif

GLOBAL int near userQuit;		/* halt flag if user decided to get out */



//
// Function Prototypes Section:
// Place in this section any function prototypes
//



extern	void cntinit(void );
extern	void cntnext(void );
extern	void dtimetokey(ZDATETIME *,char *);
extern	int dtokey(char *ascii,char *numkey);
extern	int keepcount(void );
extern	void keytodtime(char *,ZDATETIME *);
extern	char far *lmffname(char far *name,char far *nbuf);
extern	void mfaddord(struct fieldhdr far *fld);
extern	void mfbackord(void);
extern	char *mfdecpt(char *p);
extern	void mfdelord(struct fieldhdr far *fld);
extern	void mfdeltmp(void );
extern	int mfgetkey(char *ebuf, LPSTR ndxname, char *tagname);
extern	void mfgetord(int doprev);
extern	void mfinit(void);
extern	void mfinitcnt(void);
extern	void mfpart(void);
extern	void mfreset(void );
#if defined RSW
extern	char far *mfselname(struct mffile far *file);
extern	int mfrewind(int sqlrestart);
#else
extern	int mfrewind(void );
#endif
extern	int mfscan(int n);
extern	char *mfscopes(char *txt,int hi,int mtcode);
extern	void sortcts(void );

#endif

#undef GLOBAL

#endif // end _MFMISC_H_

// *************************** End of File ************************************

