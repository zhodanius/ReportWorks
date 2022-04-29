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
// $Log:   H:/vcsmfc/h/_mfdata.h_v  $
// 
//    Rev 1.5   08 Sep 1995 11:55:04   jpb
// make some ints UTWOs in MFGROUP struc, to maintain temp file size
// 
//    Rev 1.4   06 Sep 1995 16:10:20   jpb
// 32 bits
// 
//    Rev 1.3   11 Aug 1995 17:12:02   jpb
// Second cleanup pass for RSW
// 
//    Rev 1.2   07 Jul 1995 18:12:00   jpb
// First pass at moving all data and functions to CRrDoc class
// 
//    Rev 1.1   26 Apr 1995 10:53:02   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.0   16 Mar 1995 16:14:36   sbc
// Initial revision.
// 
//    Rev 1.5   22 Nov 1993 15:25:32   sbc
// Add C++ check for extern "C"
// 
//    Rev 1.4   22 Nov 1993 14:59:30   jpb
// 1. add macros for mfsql.c - CHARFLD, LEFTJOIN, RIGHTJOIN, OUTERJOIN,
//    INNERJOIN, PLATFORM, TRANSLATED
// 2. change contents of select builder packet, part of mfsql.c restructure
//    phase 2
// 
//    Rev 1.7   29 Mar 1995 16:44:18   dlm
// Fixed CHARFLD macro to include DATETIME and TIME bits.
// 
//    Rev 1.6   21 Feb 1995 17:51:14   jpb
// change select packe members for Lower strings - change name and usage
// 
//    Rev 1.5   22 Nov 1993 15:25:32   sbc
// Add C++ check for extern "C"
// 
//    Rev 1.4   22 Nov 1993 14:59:30   jpb
// 1. add macros for mfsql.c - CHARFLD, LEFTJOIN, RIGHTJOIN, OUTERJOIN,
//    INNERJOIN, PLATFORM, TRANSLATED
// 2. change contents of select builder packet, part of mfsql.c restructure
//    phase 2
// 
//    Rev 1.3   04 Nov 1993 15:45:52   jpb
// Use MF "global internal header" _mf.h instead of foreign internal MF headers
// 
//    Rev 1.3   04 Nov 1993 15:25:34   jpb
// Use MF "global internal header" _mf.h instead of foreign internal MF headers
// 
//    Rev 1.0   14 Oct 1993 10:12:38   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __MFDATA_H_

//
// Make a definition for this module.
//
#define __MFDATA_H_

#include "mfdata.h"

#if defined (_MFGETREC_C_)
 #define GLOBAL
#else
 #define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

// CHARFLD used in mfsql.c - is f a character field?
#define CHARFLD(f) (!((f)->dFlags&(zfNUMERIC | zfDATE | zfDATETIME | zfTIME | zfLOGICAL | zfMEMO)))

// JOIN macros used in mfsql.c to test for join type
#define LEFTJOIN(f) (((f)->mLinkFlags&MFFAIL)==MFEMPTY)
#define RIGHTJOIN(f) (((f)->mLinkFlags&MFFAIL)==MFEMPTY2)
#define OUTERJOIN(f) (LEFTJOIN(f) || RIGHTJOIN(f))
#define INNERJOIN(f) (((f)->mLinkFlags&MFFAIL)==MFSKIP)

// PLATFORM macro for tired typists
#define PLATFORM(p) (sql_get_connected_platform() == p)

// TRANSLATED macro identifies translated calcs
#define TRANSLATED(f) (f->dFlags&zfCALCULATED && f->dRecU.calcS.dExpX)

	// from mfmembuf.h
/* macro defines size of font-less memo buffer */
#define MFMEMBSZ sizeof(MFMEMBUF)

/* macro defines size of memo buffer with room for font/attr byte per char */
#define MFMEMBSZ2 (sizeof(MFMEMBUF) + 255)

/* byte length of dBASE IV *** AND FOXPRO *** memo header */
#define MFDB4HLen	8

	// from mfgroup.h
/* MFGROUP gFlags bits */
#define NOISORT 0x01	/* set=> don't break FSort ties with ISort */
						/*  If there are multiple contiguous sort fields */
						/*  that are all derived from totals at the same */
						/*  group level, this bit is set for all but the */
						/*  last in the list */


// **************************************************************************
//
// Structure Section:
// Place in this section any structure definitions.
//
	// from mfmembuf.h
typedef struct mfmembuf		/* font-less memo buffer */
{
	MFMEMHDR mHdr;			/* header */
	char mData[255];		/* data (one byte per char) */
} MFMEMBUF;

	// from mfgroup.h - header for group file / final total stuff

typedef struct mffintot
{
	LPMFFIELD ftFld;			/* the final total */
	struct mffintot far *ftNext;	/* next element in linked list */
	int ftLen;				/* length of data buffer */
} MFFINTOT;

typedef struct mfgroup
{
	LPMFFIELD gFSort;		/* final sort pass sort field */
	UTWO	 gFDir;			/* TRUE=> ascending */
	UTWO	 gFSz;			/* data len for FSort field */
	LPMFFIELD gISort;		/* initial pass sort field, if final is total */
	UTWO	 gIDir;			/* TRUE=> ascending */
	UTWO	 gISz;			/* data len for ISort field */
	char	 gFlags;		/* flags - see below */
	MFFINTOT far *gFinTot;	/* start of final total chain */
	long	 gCompRN;		/* component record number */
	long	 gLen;			/* length of group file data at this level */
	long	 gPos;			/* file pointer to slot for this level */
} MFGROUP;

// 11/02/93  sjo  added this structure for use in mfsql.c.  This packet 
//						contains what is necessary to build the SELECT statement
//
typedef struct mf_select_builder_pkt
{
char far    *select_buffer; 	// pointer to buff used to build select
int			current_mode;   // The current mode changes the format of the select
int			num_fields;		// Ids the number of items between SELECT & FROM
int			num_sort_fields; // Ids the number of sort fields in SELECT
LPMFFIELD	*sort_fields;
int 		*ad;
// rest of packet is append_where_clause() data for append_xxx_join()
LPMFFILE	file;		// current related file for join
char		*LowerOpen;		// pointer to "lower(" or ""
char 		*LowerClose;	// pointer to ")" of ""
int			where;		// "where" vs. "and" flag
char		subsel;		// current approx join id char
char		*equalText;		// used by append_join_condition
int			usePlusOj;	// TRUE if append_join_condition should use "(+)"
} MF_SELECT_BUILDER_PKT;

#if 0
//
// Global Data Section:
// Place in this section any global data.
//

GLOBAL long MFGfpPos;
GLOBAL long MFTotPos;
GLOBAL long MFSortPos;
GLOBAL long MFSaveIn;
GLOBAL long MFSaveCnt;
GLOBAL long MFSaveComp;
#if 0	// already in GLOBAL.H
GLOBAL LPMFFILE near csf;			/* current scanning-link file */
#endif
GLOBAL int MFInitialSort;
GLOBAL MFGROUP far *groups
 #if defined (_MFGETREC_C_)
		= NULL;
 #else
 		;
 #endif
GLOBAL int deepest;
GLOBAL long finreccnt;
// GLOBAL int groupmap[NOBRKFLDS];	// Already in mfdata.h

#ifdef RSW
GLOBAL long MFSQLRecNo;
#endif
GLOBAL int MFPtrChan					/* pointer file channel */
 #if defined (_MFGETREC_C_)
		= -1;
 #else
 		;
 #endif

GLOBAL int MFQueryFinal;					/* query on finals flag */
GLOBAL int MFCache					/* cache file channel */
 #if defined (_MFGETREC_C_)
		= -1;
 #else
 		;
 #endif

GLOBAL int MFFromCache			/* "reading from the cache" flag */
 #if defined (_MFGETREC_C_)
		= FALSE;
 #else
 		;
 #endif

GLOBAL int MFNeedSnap				/* will we need read ahead? */
 #if defined (_MFGETREC_C_)
		= FALSE;
 #else
 		;
 #endif

GLOBAL int MFSnap					/* have we a snapshot? */
 #if defined (_MFGETREC_C_)
		= FALSE;
 #else
 		;
 #endif

GLOBAL long MFCacheCnt;					/* number of records read ahead */
GLOBAL int MFNextSnap				/* next rec in snap bufs flag */
 #if defined (_MFGETREC_C_)
		= FALSE;
 #else
 		;
 #endif

GLOBAL long MFCacheIn				/* where we are reading from */
 #if defined (_MFGETREC_C_)
		= 0L;
 #else
 		;
 #endif

GLOBAL long MFCacheOut				/* and writing to */
 #if defined (_MFGETREC_C_)
		= 0L;
 #else
 		;
 #endif

GLOBAL long near MFCompCnt;				/* used by mfgetrec */
#if !defined(RSW)
GLOBAL unsigned int near MFMaxRec;		/* maximum length record, this composite */
GLOBAL char * near mfxtempl;	/* index file template for zfilmenu calls */
#endif
GLOBAL int near MFLastRet;			/* last rdnext/rec return code inside mfgetrec */
GLOBAL int  near MFPrevRej;					/* previous record rejected flag */
GLOBAL int near MFAbort;		/* signals abort thru post-read routine */
#endif

#if 0
//
// Function Prototypes Section:
// Place in this section any function prototypes
//

// First group is from common MFDATA modules
extern int mfgstart(char far *sortfile, int rdo);
extern int compfont(void);
extern int rdmc(char *cP);
extern int mfpreview(void);
#if !defined RSW
extern void mfnoprev(void);
extern int lbadnum(char far *s);
extern void lmfrdflds(LPMFFILE cfile);
extern void clrlkfail(void);
#endif
extern void mfcopyfins(void);
extern void mfmove(LPMFFIELD fld);
extern int mfnxtgrp(long *rec, long *cnt);
extern int mfrdmore(LPMFFIELD field);
#if defined(RSW)
extern int mfread(int (*postRead)(), int lastret, long recno);
#endif
extern int getfinbrk(void);
extern int totsort(void);
extern void freefins(void);
extern int mfwrfin(int row, int col, int *dosort);
extern int mfrlsmbs(LPMFFIELD fld);
extern int mfgetmbs(LPMFFIELD fld);
extern void mfclrbufs(void);

// Next group is from RRW-specific MFDATA modules
extern	int fmtkey(unsigned int len,int dec,LPMFFIELD fld,char far *buf);
extern	int lmfgfilss(LPMFFILE file);
extern	int lmflkup(LPMFFILE fileP);
extern	int lmfnd(LPMFFILE fileP,int checkkey);
extern	int lmfnxtdup(LPMFFILE fileP);
extern	int lmfrdata(LPMFFILE fileP,char far *buf,unsigned int len);
extern	int mfgetlb(LPMFFIELD fld);
extern	int mfgfldss(LPMFFIELD fld);
extern	int mfrdnext(int (*postRead)(void),int lastret);
extern	int mfrestore(void);
extern	int mfrlslb(LPMFFIELD fld);
extern	int mfsave(void);

// Next group is from RSW-specific MFDATA modules
extern	char far *mfselname(LPMFFILE file);
#endif

#undef GLOBAL

#endif // end __MFDATA_H_

// *************************** End of File ************************************

