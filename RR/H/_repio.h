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
// $Log:   H:/vcsmfc/h/_repio.h_v  $
// 
//    Rev 1.6   19 Feb 1997 15:36:28   dlm
// Part of fix to RRW 2888/RSW 2209 to save up to 255 fonts in a report
//  instead of stopping after considering 255 fonts.  Modules changed are:
//  grmain.cpp, rpwritex.cpp, grmisc.cpp, _repio.h.
// 
//    Rev 1.5   06 Jun 1996 14:12:38   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.4   01 Aug 1995 13:47:16   jpb
// fix rsw 1904
// 
//    Rev 1.3   11 Jul 1995 17:12:48   dlm
// Changed functions to CRrDoc member functions and variables to CRrDoc
//  member variables.
// 
//    Rev 1.2   10 Jul 1995 11:04:36   dlm
// Changed name of #define from DTYPE to REP_DTYPE.
// 
//    Rev 1.1   26 Apr 1995 11:07:44   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.0   16 Mar 1995 16:14:48   sbc
// Initial revision.
// 
//    Rev 1.25   10 Apr 1995 15:43:56   dlm
// Changed prototype for findfld().  Part of datetime support.
// 
//    Rev 1.24   04 Apr 1995 18:37:36   dlm
// Added zfDATETIME and zfTIME to some flags masks.
// 
//    Rev 1.23   29 Mar 1995 13:20:38   dlm
// Updated HFLAGSLEN to include dFldPic2 in HFLAGS record.
// 
//    Rev 1.22   22 Mar 1995 14:50:46   smh
// 
//    Rev 1.21   22 Mar 1995 13:44:50   smh
// Added stuff for set_ridb_override for RSW 1777.
// 
//    Rev 1.0   22 Mar 1995 13:43:40   smh
// Initial revision.
// 
//    Rev 1.20   22 Mar 1995 11:36:36   smh
// Removed loveralias, it's now private to ?grjoin.c.
// 
//    Rev 1.19   13 Feb 1995 16:25:38   sjo
// Changed LocT from a int to a long.
// 
//    Rev 1.18   08 Feb 1995 13:29:40   sjo
// Checking in a bunch of files for the first wave of datetime support. These
// sources have support for a dFlags that is a long (not an unsigned int) and
// it recognizes date, time and datetime fields.  It only supports dates at
// this time, because we need calcs, picture types, etc if we are to do time and
// datetime.
// 
// 
// 
//    Rev 1.17   28 Dec 1994 12:13:36   dlm
// Part of fix to RSW bug 1596.  Changed prototype for sqlCases() to include
//  &nomerge.  Also changed rpwritex.c, grsql.c, grmain.c.
// 
//    Rev 1.16   16 Dec 1994 13:23:52   dlm
// Changed prototype for setlinkfld() to stop passing error buffer.
// 
//    Rev 1.15   09 Dec 1994 17:40:30   dlm
// Part of fix to RSW "bug" 1526, which says we need to save the quote
//  character with saved reports.
// 
//    Rev 1.14   16 Nov 1994 11:50:02   dlm
// Added tMASTDS2 for improved search rules.  Means to try master DS dir,
//  followed by tORIG2.  Used when related file came from master DS, to allow
// 
//    Rev 1.13   09 Nov 1994 13:36:20   dlm
// Defined new trynext()/whatnext() values for ODBC-style search rules.
// Modified sqlCases() prototype.
// 
//    Rev 1.12   28 Oct 1994 17:40:32   dlm
// Added new "time" values for data-source directory search rules and
//  removed tDATASOURCE.
// Adjusted prototypes for some of the ...Cases() routines for new search
//  rules.
// 
//    Rev 1.11   21 Oct 1994 09:40:28   dlm
// Added extern for driveit().
// Made extern for override() conditional on RSW. (New arg if RSW)
// 
//    Rev 1.10   23 Aug 1994 12:54:04   sjo
// Fixed a problem with the definition of _REPIO_H.
// 
//    Rev 1.9   19 Jul 1994 18:00:30   jpb
// add extern for initCond()
// 
//    Rev 1.8   08 Jun 1994 14:37:46   erp
// changed FAR to far, so it will build for 32-bits
// 
//    Rev 1.7   21 Mar 1994 12:00:22   dlm
// Merge of Abra branch:
//  Adjusted value of HFLAGSLEN to include two-byte dFlags2 (!) and new
//   MFFIELD structure member dFlags3.
//  Modified findfld() to accept a far pointer to a field name.
// 
//    Rev 1.6   16 Feb 1994 16:49:56   say
// Add tDATASOURCE to search rule IDs
// 
//    Rev 1.5   28 Jan 1994 17:37:14   say
// data source selection
// 
//    Rev 1.4   17 Dec 1993 16:57:18   say
// Add global szDataSource
// 
//    Rev 1.3   22 Nov 1993 13:33:14   say
// Put back LOGONDATA args so we can still read old reports
// 
//    Rev 1.2   19 Nov 1993 17:45:12   sbc
// Add extern C for C++
// 
//    Rev 1.1   19 Nov 1993 13:20:24   say
// remove LOGONDATA arguments to filecases(). More later...
// 
//    Rev 1.0.1.0   11 Jan 1994 10:53:54   dlm
// Changed HFLAGSLEN parameter that controls length of yxHFLAGS record to
//  account for fact that dFlags2 is two bytes, not one.
// Modified findfld() extern to allow "name" argument to be "far".
// 
//    Rev 1.0   14 Oct 1993 10:11:58   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __REPIO_H_
//
// Make a definition for this module.
//
#define __REPIO_H_

//
// Includes needed by this header.
//
	#include "repio.h"
	#include "mffield.h"
	#include "mffile.h"
	#include "users.h"
#if defined (RSW)
	#include "sql.h" // ODBC header for SQL_MAX_DSN_LENGTH
#endif

#if defined _GRMAIN_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

// **************************************************************************
//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

// MAXFONTS now obsolete
//#define MAXFONTS	200
#define HFLAGSLEN 15
#define MAXFONTSAVE	256		// we'll save 256 different fonts and no more
#define NUMRDFLEN 20

#define TWOBYTE(x) (*(UTWO *)(&(x)))
#define FOURBYTE(x)	(*(FOUR *)(&(x)))

#define REP_DTYPE (zfNUMERIC|zfDATE|zfLOGICAL|zfMEMO|zfDATETIME|zfTIME)
#define CTYPE (REP_DTYPE|zfDUPFLD|zfCALCULATED|zfFROMTOT|zfPAGENO|zfNOTinREC|zfPREV)
#define NOTCTYPE (zfNUMERIC | zfDATE | zfLOGICAL | zfDATETIME | zfTIME)
#define CDTYPE (REP_DTYPE | zfCALCULATED)
#define ALJUST (0x0FF0)

// These are Search Rule transition IDs;
// they say where to try next when there's an error opening 
// a database file or index
#define tMASTER 1		// try the master file's directory
#define tDEFAULT 2		// try the user-defined default data directory
#define tTALK 3			// ask the user what to do next
#define tORIGINAL 4		// try the file's orignal directory (full path saved or fnexpanded)
#define tORIGEXT 5
#define tMASTEXT 6
#define tDEFEXT 7
#define tLIBRARY 8		// try the report library directory
#if defined (RSW)
#define tDSOURCE1 9		// ODBC (flat file) data source's default directory	as first choice
#define tDSOURCE2 10	// ... as choice just before tDEFAULT
	// next 4 are used in ODBC-style rules with join across dirs allowed
#define tDSOURCE3 11	// ODBC-style rules: data source's default dir
#define tORIG2 12		// ODBC-style rules: file's original dir
#define tDSOURCE4 13	// ODBC-style rules: data source's default dir
#define tMASTDS 14		// ODBC-style rules: master data source's default dir
#define tMASTDS2 15		// ODBC-style rules: same as tMASDS but with different "next"
#endif
#define tRECNO (-1)
#define tUNKNOWN (-2)

#if !defined(INTERACTIVE)
/* values returned by override() */
#define oENSF	(-1)		/* no such file */
#define oELGT	(-2)		/* value too long */
#define oEMPTY	1			/* no override value passed */
#define oFULL	2			/* directory + filename */
#define oFILE	3			/* just a filename */
#define oDIR	4			/* just a directory */
#endif

#if defined(RSW)
#define APPROX2LINK 2
#define APPROXLINK 1
#define LOOKUPLINK 0
#else
#define SCANLINK 2
#define APPROXLINK 1
#define LOOKUPLINK 0
#endif

// **************************************************************************
//
// Structure Section:
// Place in this section any structure definitions.
//
typedef struct joinpairchain
{
	struct joinpairchain *chainlink;
	long type;
	int cfileno;
	int cnamelen;
	int rnamelen;
	char names[1];
} JOINPAIRCHAIN;

typedef struct _yxMultiTAG {
	int size;
	char far *buf;
} YXMULTI;

// **************************************************************************
//
// Global Data Section:
// Place in this section any global data.
//


#if 0
 #if defined(INTERACTIVE)
GLOBAL int near CFlds
  #if defined _READREP_C_
    = 0
  #endif
    ;
 #endif

GLOBAL int near cfn;
 #if !defined(INTERACTIVE)
GLOBAL LPMFFIELD fldtogo;
 #endif
GLOBAL int fonts;
 #if defined(RSW)
GLOBAL JOINPAIRCHAIN *joinpairhead;
GLOBAL JOINPAIRCHAIN *joinpairtail;
 #endif
GLOBAL LPMFFIELD LastFld;
 #if defined(RSW)
GLOBAL char near LocName[MAXDNAME];
GLOBAL unsigned long near LocT;
 #endif
GLOBAL int oldMeasure;
GLOBAL int near OldRep;
 #if !defined(RSW)
GLOBAL UTWO near PartLen;
 #endif
 #if defined(INTERACTIVE)
GLOBAL ZDATE near RpDate;
 #endif
 #if defined(INTERACTIVE)
GLOBAL ZTIME near RpTime;
GLOBAL char near RpUser[USE_BYTES];
 #endif
GLOBAL int near ToHunds;
// GLOBAL int near tokslop;  // Already in cfcomp.h
GLOBAL int near TrimBit;
GLOBAL int near WasLabels;
 #if !defined (INTERACTIVE)
  #if defined(RSW)
GLOBAL LPSTR OrigDB
   #if defined (_GRMAIN_C_)
 = NULL
   #endif
;
  #endif
 #endif
#endif



// **************************************************************************
//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#if 0
 #ifdef RSW
extern LPMFFIELD findfld(unsigned long type,char far *name,int fn,int dummyok, int *convert);
 #else
extern LPMFFIELD findfld(unsigned long type,char far *name,int fn);
 #endif
extern void initCond(void);
extern void setdels(unsigned int fn);
extern int  lwhatnext(int time,char far *orig, int dbf);
extern int  lfnexpand(char far *ptr, int dbf);
extern void makepname(char *namebuf, char *dir);
 #ifdef RSW
extern BOOL ltrynext(int time,int dbf,LPMFFILE ftb, int master, char far *orig, int ret, int recno, LPSTR ebuf);
extern BOOL lnewtable(LPMFFILE f,int ecode,LPSTR ebuf);
extern BOOL newDataSource();
 #else
extern BOOL ltrynext(int time,int dbf,LPMFFILE ftb, int master, char far *orig, int ret, int recno);
 #endif
extern	char *lmakename(char far *orig,char *fname);
extern	int newascii(char *f,int ecode);
extern	int findImageFile(char far *path);
extern	int fixsindex(struct mffield far *fld);
extern	int getnewfn(int old);
 #ifdef INTERACTIVE
extern	void fillfld(struct mffield far *fld,char *buf,int longDflags);
 #else
extern	int fillfld(struct mffield far *fld,char *buf, char nomerge,int longDflags);
 #endif
extern	unsigned char *typestring(long type);
extern	int explain(void);
extern	int deplain(void);
 #ifdef INTERACTIVE
extern	int losefield(char *ermsg,struct mffield far *fld,int loseit);
 #else
extern	void losefield(char *ermsg,struct mffield far *fld);
 #endif
extern	int yxfarput(int type,int lgt,char *buf);
extern	void postit(char far *name,int ecode);
extern	int endit(int bad,int zak,int mem);
extern	int compilecalc(struct mffield far *fld,int warn);
extern	int finishtotal(struct mffield far *fld,int warn,int *lostit);

extern char *filename(int fn,char *fname);
 #if defined(RSW)
extern void freejoinpairs(void);
 #endif
extern void invValue(char *msg);
extern void ndxupd(int i);
 #if defined(RSW)
extern int override(char far *dest,char far *source,char far *inp,char far *ext,BOOL path);
extern setlinkfld(YXBUF *buf,int count,char *orig,char *fname, int dsdir, char quote,int longDflags);
extern BOOL fixQuotes(LPSTR name, char quote);
 #else
extern int override(char far *dest,char far *source,char far *inp,char far *ext);
extern setlinkfld(YXBUF *buf,int count,char *orig,char *fname,int tag,int longDflags);
 #endif
extern UTWO yxgettail(YXBUF *buf,char far *tail);
extern int driveit (char far *dest);

// *Cases function externs

	extern int fieldCases(int *status,int type,YXBUF *buf,int count,
		 int *nomerge,char *fname);
 #if defined(RSW)
	extern int fileCases(int *status,int type,YXBUF *buf,int count,
		 char *fname,char *samedir,int *goodver, char *dpath,
		 int *fileflags, char quote);
	extern int joinCases(int *status,int type,YXBUF *buf,int count,
		 int *fileflags, char quote);
	extern int sqlCases(int *status,int type,YXBUF *buf,int count,
		 char *fname,char *dpath, int *master, char *quote, int *nomerge);
  #if !defined(INTERACTIVE)
	extern BOOL set_ridb_override(LPSTR file, BOOL master);
  #endif
 #else
	extern int fileCases(int *status,int type,YXBUF *buf,int count,
		 char *fname,char *samedir,int *goodver,int *clip,int *setscope);
	extern int joinCases(int *status,int type,YXBUF *buf,int count);
 #endif
	extern int miscCases(int *status,int type,YXBUF *buf,int count,
		 ATOM *faces,int *nomerge);
	extern int optsCases(int *status,int type,YXBUF *buf,int count,
		 char *oldops,int *repInchX,int *repInchY);
#endif


#undef GLOBAL
#endif // end __REPIO_H_

// *************************** End of File ************************************
