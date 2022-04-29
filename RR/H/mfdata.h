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
// $Log:   H:/vcsmfc/h/mfdata.h_v  $
// 
//    Rev 1.7   28 Jan 1997 09:28:58   pjm
// Added stuff for lookups using Visual FoxPro 3 B, I and Y types.
// 
//    Rev 1.6   06 Jun 1996 14:21:20   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.5   17 Nov 1995 19:04:38   smh
// Win32 file i/o.
// 
//    Rev 1.4   16 Nov 1995 14:14:28   smh
// Updated MFLKBUF structure, now new & delete it for CFile member.
// 
//    Rev 1.3   15 Nov 1995 16:45:24   smh
// Win32 file i/o changes int LkFileNo -> CFile LkCFile.
// 
//    Rev 1.2   07 Jul 1995 18:11:40   jpb
// First pass at moving all data and functions to CRrDoc class
// 
//    Rev 1.1   26 Apr 1995 10:52:48   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.0   16 Mar 1995 16:12:52   sbc
// Initial revision.
// 
//    Rev 1.13   22 Feb 1995 17:05:32   jpb
// add prototype for mfjobsel() and add JOB_FILE
// 
//    Rev 1.12   18 Jan 1995 17:51:00   sjo
// Made changes to remove compiler warnings.
// 
//    Rev 1.11   14 Sep 1994 09:38:14   dlm
// Part of fix to RRW bug 1540.  Allow non-softening of hard spaces in
//  database fields (only), by checking new INI file setting SoftenDBFields,
//  which defaults to 1 - meaning DO soften 'em, as before.  Fix involves
//  wmain.h, winit.c, mfdbc.c, lookup.c.
// 
//    Rev 1.10   08 Jun 1994 12:37:22   erp
//  changed FAR to far, so it will build for 32-bits
// 
//    Rev 1.9   21 Mar 1994 11:57:50   dlm
// Added GLOBAL for CharFldSize, which specifies the number of bytes used
//  to indicate width of character fields.  This is intended to be controlled
//  by a new INI file setting, and defaults to 1.
// 
//    Rev 1.8   18 Feb 1994 15:26:22   sjo
// I am merging the RRWINNSX branch back onto the RRWIN tree. This branch was
// setup to allow me to port my RR 5.1 NSX, SMT and DBV changes to RRW and
// RSW.
// 
//    Rev 1.7.1.0   21 Jan 1994 17:30:34   sjo
// I am merging RR 5.1 changes into the windows products. I modified the memo
// header structure and added some macros for the memo performance changes
// that were made.
// 
//    Rev 1.7   04 Jan 1994 13:04:54   smh
// Fixed bug where last rec of (rejected) data would print in title area
// area of runtime no-records-found rep. In rpprep.c, clear buffers.
// Also undid previous attempt to fix this by changing mfcopyflds(). Files:
// rpprep.c,mfrdrec.c,mfrdflds.c,mfrdnext.c,mfgetrec.c,rpexport.c,mfdata.c
// 
//    Rev 1.6   20 Dec 1993 17:54:20   jpb
// get rid of bEvalX
// 
//    Rev 1.5   08 Dec 1993 16:56:54   jpb
// change colref prototype
// 
//    Rev 1.4   19 Nov 1993 17:41:54   sbc
// Add extern C for C++
// 
//    Rev 1.3   08 Nov 1993 11:12:54   smh
// Added argument to mfcopyflds() routine (for bug fix rsw 575).
// 
//    Rev 1.2   04 Nov 1993 14:36:48   sjo
// I added some new defines.  These are the 'modes' that mfsqlsel() get called
// with.  Depending on whether we are doing a show sql, printing out the sql
// for a report spec, etc.
// 
//    Rev 1.1   29 Oct 1993 16:33:48   jpb
// Clean up sources to remove compiler warnings
// 
//    Rev 1.0.1.0   11 Jan 1994 10:51:10   dlm
// Added CharFldSize, which is used to remember whether one or two bytes
//  are required to hold the maximum size of a character field.  This is
//  now settable in the .ini file, instead of deduced based on index-file
//  extensions.
// 
//    Rev 1.0   14 Oct 1993 10:12:22   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _MFDATA_H_

//
// Make a definition for this module.
//
#define _MFDATA_H_

#include "mffield.h"
#include "mffile.h"

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
	// from mfmembuf.h
/* macro generates memo file current offset from mData pointer */
#define MFMO(p) (MFMH(p)->mCOff)

/* macro generates memo file current offset from mData pointer */
#define MFEO(p) (MFMH(p)->mEOff)

/* macro generates memo file starting offset from mData pointer */
#define MFSO(p) (MFMH(p)->mSOff)

/* macro generates memo owner file pointer from mData pointer */
#define MFFP(p) (MFMH(p)->mMemFile)

/* The following macros generate offsets used for DB4 memo access */

#define MFCSZ(p) (MFMH(p)->mCSZ)
#define MFCST(p) (MFMH(p)->mCST)
#define MFCBK(p) (MFMH(p)->mCBK)
#define MFPSZ(p) (MFMH(p)->mPSZ)
#define MFPST(p) (MFMH(p)->mPST)
#define MFPBK(p) (MFMH(p)->mPBK)
#define MFNBK(p) (MFMH(p)->mNBK)

/* macro generates memo header pointer from mData pointer */
#define MFMH(p) ((MFMEMHDR far *)(((char far *)(p)) - MFMEMHSZ))

/* macro generates memo-merge field from mData pointer */
#define MFMF(p) (MFMH(p)->mCurFld)

/* macro generates memo-merge data offset from mData pointer */
#define MFMFO(p) (MFMH(p)->mCurFOff)

/* macro generates memo flags from mData pointer */
#define MFMFF(p) (MFMH(p)->mMemFlags)

/* macro generates memo state from mData pointer */
#define MFMS(p) (MFMH(p)->mState)

/* macro generates font number from mData pointer */
#define MFMFN(p) (MFMH(p)->mFontNo)

/* macro generates attribute from mData pointer */
#define MFMATTR(p) (MFMH(p)->mAttr)

/* macro generates point size from mData pointer */
#define MFMPNT(p) (MFMH(p)->mPoint)

/* macro generates point size buffer from mData pointer */
#define MFPB(p) (MFMH(p)->mPntBuf)

/* macro generates unit buffer size from mData pointer */
#define MFUS(p) (MFMH(p)->mUnitSize)

/* memo flag bits */
#define MFNOTPRE 0x0001	/* memo not yet previewed */
#define MFMTMEMO 0x0002	/* memo is empty (wks version, calc'd empty memos) */
#define MFDBASE4 0x0004	/* memo written in dBASE IV format */
#define MFFONT	 0x0008	/* we are outputting a "font" sequence */
#define MFASC	 0x0010	/* ASCII memo as opposed to DB */

/* mAttr attribute bits */
#define MFBOLD	 0x01	/* bold */
#define MFULIN	 0x02	/* underline */
#define MFITAL	 0x04	/* italic */
#define MFNORM	 0x08	/* normal */
#define MFMAST	 0x10	/* special value to handle <D> */

/* font/attr manipulators */
#define FONT(f) ((int)((f)&0xFFFF))	/* get font from points/font */
#define POINTS(f) ((int)((f)>>16))	/* get points from points/font */
#define FPT(p,f) ((long)(((long)(p)<<16)+(long)(f)))	/* set points/font from points, font */

// Defines the different modes of operation mfsqlsel() supports.
#define PRINT_GO	 0
#define CHECK_SELECT 1
#define PRINT_SPEC   2
#define SHOW_SQL	 3
#define JOB_FILE	 4


	// from mflkbuf.h
/* macro defines size of lookup buffer */


// ********************************************************************
//
// Structure Section:
// Place in this section any structure definitions.
//
//
// avbuf should stay with fieldsnap since it is used to define
// it.
//
typedef struct avbuf
{
	long count;		/* count value for Average */
	double sum;		/* sum value for Average */
	double sum2;	/* used for variance/deviation */
} MFAVBUF;

typedef struct fieldsnap
{
	char far *sFldP;		/* saved main record data */
	char far *sTmpP;		/* saved temp record data */
	MFAVBUF far *sTotP;		/* saved count/sum values for average */
	char sError;		/* saved main ERR/NA/conversion-error flags */
	char sTpError;		/* saved temp ERR/NA/conversion-error flags */
} MFFLDSNAP;

	// from mfmembuf.h - memo buffer contents definitions
typedef struct mfmemhdr		/* memo buffer header */
{
#if !defined(RSW)
	LPMFFILE mMemFile;		/* MFFILE of memo owner file */
#endif
	LPMFFIELD mCurFld;		/* current memo-merge field */
	long far *mPntBuf;		/* pointer to buffer for fonts and point sizes */
	int mUnitSize;			/* byte size of first 1/2 of buf (if prev'd) */
	int mCurFOff;			/* current memo-merge data offset */
	char mMemFlags;			/* flags */
	char mState;			/* saved state */
	int mFontNo;			/* current font */
	char mAttr;				/* current attributes */
	int mPoint;				/* current point size */
	FOUR mSOff;				/* starting offset in memo file */
	FOUR mCOff;				/* current offset in memo file */
	FOUR mEOff;				/* ending offset of memo */
// #if !defined(RSW)		/* *** The following are for DB4 memos *** */
	FOUR mCSZ;				/* Memo size, current block */
	FOUR mCST;				/* Memo start,current block (relative to the memo) */
	FOUR mCBK;				/* file position, current block */
	FOUR mPSZ;				/* Memo size, previous block */
	FOUR mPST;				/* Memo start, previous block */
	FOUR mPBK;				/* file position, previous block */
	FOUR mNBK;				/* file position, next block */
// #endif
} MFMEMHDR;
/* macro defines size of memo header */
#define MFMEMHSZ sizeof(MFMEMHDR)

	// from mflkbuf.h - LOOKUP() buffer contents definitions */
struct MFLKBUF				/* lookup buffer structure */
{
	MFLKBUF	*LkLnk;				/* link to next buffer */
	char		LkFile[FNLEN+1];		/* full path of file to read */
	char		LkNdx[FNLEN+1];			/* full path of index file */
	KLNTXFILE	**LkNtxPtr;	 		/* pointer to array of node buffer ptrs */
	KLNTXFILE	*lDbcFd;				/* DBC file descriptor pointer */
	char		LkFld[MAXDNAME];		/* field name */
	char		LkTag[MAXTAG];			/* tag name */
	CFile		LkCFile;					// class for dbf file
	int		LkFlags;					// some flags
	int		MaxFld;					/* max char field (platform-dependent) */
	int		LkFldLen;				/* length of field data */
	int		LkFldOff;				/* offset of field in record */
	FOUR		LkRec0Pos;				/* file position of first record */
	UTWO		LkRecLen;				/* dbf record byte length */
	int		LkKeyLen;				/* length of key */
	UONE		LkLstVal[250+1];		/* last value we looked up (MAXKEYSZ) */
	UONE		LkLstRes[DBMAXFLDBUF];	/* last result of lookup() */
	long		LkTStamp;					/* timestamp */

	MFLKBUF()
	{
		LkLnk = NULL;
		LkNtxPtr = NULL;
		lDbcFd = NULL;
		LkFlags= 0;
//test made by CAS 8/22/2014 to determine if we need to address ADS file differently here
#if defined(RSW)
		LkCFile.m_hFile = CFile::hFileNull;
#else
		LkCFile.m_hFile = CADSFile::hFileNull;
#endif
	}
};
#define MFLKBSZ sizeof(MFLKBUF)

// define the settings for LkFlags
#define fLkNUMERIC	1		// std numeric type (N or F), stored as string
#define fLkVFPI		2		// Visual FoxPro Integer (I)
#define fLkVFPY		4		// Visual FoxPro Currency (Y)
#define fLkVFPB		8		// Visual FoxPro Double (B)


#if 0
//
// Global Data Section:
// Place in this section any global data.
//

GLOBAL int bMidGo
 #if defined (_MFGETREC_C_)
 	= FALSE;
 #else
 	;
 #endif

#if !defined(RSW)
GLOBAL int CharFldSize
 #if defined (_MFGETREC_C_)
	= 1;
 #else
	;
 #endif
 
GLOBAL int SoftenDBFields
 #if defined (_MFGETREC_C_)
	= 1;
 #else
	;
 #endif
#endif
GLOBAL int bRandomMode;
GLOBAL int bSeqPass;
GLOBAL int groupmap[NOBRKFLDS];
GLOBAL int near Klipper		/* TRUE if Clipper support overlays present */
 #if defined (_MFGETREC_C_)
		= FALSE;
 #else
 		;
 #endif

GLOBAL long near LKAge;			/* lookup buffer LRU pseudo-time */

GLOBAL int near MFDbaseEd	/* TRUE if using dBASE III editor's memos */
 #if defined (_MFGETREC_C_)
		= TRUE;
 #else
 		;
 #endif

GLOBAL char * near mfexttab[6];/* default index file extensions for zfilmenu calls */
GLOBAL int near MFCurOpen;		/* cur number of files mf has open */
GLOBAL int near MFDels;			/* if TRUE, read deleted records */
GLOBAL int near MFNonDels;			/* if TRUE, read non-deleted records */
GLOBAL int near MFDialog;				/* "master file is DIALOG" flag */
GLOBAL LPMFFILE near MFErrFile;	/* file being processed when lookup failed */
GLOBAL char * near MFHiKey;	/* pointer to high end of range (or NULL) */
GLOBAL char * near MFLoKey;	/* pointer to low end of range (or NULL) */
GLOBAL char near MFNdxType;	/* master index type ('C', 'N', 'D', or '\0') */
GLOBAL long near MFLoRecNo;	/* starting record number (or 0xFFFFFFFF) */
GLOBAL long near MFHiRecNo; 	/* ending record number (or 0) */
GLOBAL int near MFMaxOpen;		/* max files allowed open by mf */
GLOBAL int near MFShMode;			/* shared mode for DBF/DBT opens */

#if 0	// MFC conversion - not referenced
GLOBAL LPSTR MFSQLcontrol
 #if defined (_MFOPEN_C_)
 	= NULL;
 #else
 	;
 #endif
#endif

GLOBAL char * near MFWhere		/* additional where text for runtime */
 #if defined (_MFGETREC_C_)
		= NULL;
 #else
 		;
 #endif
#endif


#if 0
//
// Function Prototypes Section:
// Place in this section any function prototypes
//

extern	int buildfinals(int row,int col);
extern	int clpnseq(char *x,char *y);
extern	char far *colref(struct mffield far *fld,struct mffile far *file,int bufno);
extern	char far *dbname(LPMFFILE file,char far *nmbuf);
extern	void emptyfield(struct mffield far *cfld);
extern	int getfinal(void);
extern	void mfclrbufs(void );
extern	void mfcopyflds(void);
extern	void mfcpyscn(void);
extern	int mfdbsize(struct mffield far *fld);
extern	void mfeval(LPMFFIELD fld);
extern	int mfexpinfo(char far *exp,struct mffield far *fld, int action,int disperr);
GLOBAL	void (*MFFldDel)(int);		/* address of routine to adjust for field deletion */
GLOBAL	int (*MFTotal)(LPMFFIELD fld,int pass);		/* address of routine to evauate a total field */
#if defined RSW
extern	int mfgetbuf(void );
#else
extern	int mfgetbuf(int unsorted);
#endif
extern	int mfgetmch(struct mffield far *fld,char far *dataP,int coff,int applyFont);
extern	void mfgetpos(long *pos);
extern	int mfgetrec(int (*postRead)(void ));
extern	int mfgetstart(char far *sortfile);
extern	int mfgetstop(void);
extern	int mfgstop(int fins);
extern	int mfgo(void);
extern	LPSTR mfjobsel(void);
extern	void mflgetpos(long far *pos);
extern	void mfmemcpy(char far *src,char far *dest);
extern	void mfmeminit(void );
#if defined RSW
extern	void mfneeded(int locfld);
#else
extern	void mfneeded(void);
#endif
extern	int mfonebuf(struct mffield far *fld);
extern	void mfoptbuf(void );
extern	void mfoptrls(void );
extern	void mfpgeval(void );
extern	long far *mfptbuf(char far *p);
extern	int mfrdnext(int (*postRead)(void),int lastret);
extern	int mfrdnxrec(int (*postRead)(void),long recno,int lastret);
extern	int mfrdrec(FOUR pos[], int lastret);
extern	int mfreal(LPMFFIELD fld);
extern	void mfrlsbuf(void);
extern	void mfrlsfld(struct mffield far *f,int o);
extern	int mfsctest(int fno,int cur);
extern	void mfsetsqlneeds(void );
extern	int lmfskprec(LPMFFILE fileP);
extern int mfsortlist(LPMFFIELD sfa[],int saa[],int row,int col);
//extern	int mfsortlist(struct mffield far **sfa ,UTWO *saa,int row,int col);
extern	int mfsqlsel(int mode);
extern	void mfstop(void);
extern	int mftottot(int level);
#endif


#undef GLOBAL

#endif // end _MFDATA_H_

// *************************** End of File ************************************

