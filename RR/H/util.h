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
// $Log:   H:/VCSMFC/H/UTIL.H_V  $
// 
//    Rev 1.7   06 Jun 1996 14:22:06   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.6   29 Aug 1995 16:06:28   dlm
// Make LSORT_ROUTINE not pascal. Relates to change of CompNames in
//  RRVIEW.H and yzncomp in RRDOC.H.
// 
//    Rev 1.5   24 Jul 1995 16:56:14   pjm
// Moved ARGS strucure definition and related stuff here (from readstr.cpp).
// 
//    Rev 1.4   20 Jul 1995 13:22:06   pjm
// Moved stuff to R&R classes.
// 
//    Rev 1.3   12 Jul 1995 17:36:36   smh
// Made LSORT_ROUTINE a pascal so can use w/ SPEC CRrView member.
// 
//    Rev 1.2   27 Apr 1995 12:37:10   sjo
// Merge of 6.1.03+.  I say + because I have added some of the time functions
// to this merge, which will be a part of 6.1.04.  I merged the CF directories
// and some H files (for the time function changes).
// 
//    Rev 1.1   26 Apr 1995 08:02:24   sbc
// 6.1.03 -> 7.0.01 merge
// 
//    Rev 1.0   16 Mar 1995 16:13:44   sbc
// Initial revision.
// 
//    Rev 1.15   28 Mar 1995 17:52:12   jpb
// support datetime/time literals
// 
//    Rev 1.14   24 Mar 1995 12:51:34   sjo
// Added some entry points for datetime support.
// 
//    Rev 1.13   23 Mar 1995 17:09:40   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
// 
//    Rev 1.12   08 Feb 1995 13:29:44   sjo
// Checking in a bunch of files for the first wave of datetime support. These
// sources have support for a dFlags that is a long (not an unsigned int) and
// it recognizes date, time and datetime fields.  It only supports dates at
// this time, because we need calcs, picture types, etc if we are to do time and
// datetime.
// 
//    Rev 1.11   08 Jun 1994 12:38:22   erp
//  changed FAR to far, so it will build for 32-bits
// 
//    Rev 1.10   14 Apr 1994 09:36:38   say
// Add ZNVOK, ZNVWARNCOMMENT codes, ZNVFATAL macro for runtime front
// end tool
// 
//    Rev 1.10   14 Apr 1994 09:28:44   say
// Add ZNVOK and ZNVWARNCOMMENT for runtime front end tool.
// 
//    Rev 1.9   13 Apr 1994 14:56:32   say
// add NV typedef, un#ifdef nvlist protos for use by runtime front end tool
// 
//    Rev 1.9   13 Apr 1994 14:52:08   say
// remove INTERACTIVE #ifdef from nvlist protos
// 
//    Rev 1.8   05 Apr 1994 12:23:16   dlm
// Moved externs for zmemory(), zcompBin() outside of !RSW conditional for
//  the benefit of data dictionary support.
// 
//    Rev 1.7   31 Jan 1994 12:49:18   sbc
// CompFlat/SortFlat had conflicting defines (near) with global.h
// 
//    Rev 1.6   19 Nov 1993 17:35:52   sbc
// Add extern C for C++
// 
//    Rev 1.5   16 Nov 1993 16:22:40   smh
// Created a compare routine typedef that expects far pointer arguments and
// use that for lzppsort compare routine argument.
// 
//    Rev 1.4   11 Nov 1993 10:35:28   smh
// Back to revision 1.2
// 
//    Rev 1.2   04 Nov 1993 14:28:26   erp
// added typedef for user supplied sort rroutine
// 
//    Rev 1.1   27 Oct 1993 12:06:20   erp
// fixed function prototype for zdatecheck for RSW build
// 
//    Rev 1.0   14 Oct 1993 10:10:20   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _UTIL_H_

//
// Make a definition for this module.
//
#define _UTIL_H_


#if !defined(INTERACTIVE)
#include "runtime.h"
#endif


//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
#define CHARP	LPSTR
#define CHARPP	LPSTR far *

//
/* znv error codes. Placed in ZNVError on a znv routine error return */
// These are just used in wnextjob.c outside of util.
#define ZNVFATAL(err) ((err) > 0 && (err) < 100)
#define ZNVOK    0   // Copacetic
#define ZNVMEM   1	/* ran out of memory */
#define ZNVNAME  2	/* no such name */
#define ZNVDUP   3	/* duplicate names found */
#define ZNVEMPTY 4	/* no names in file */
#define ZNVBADLN 5	/* bad input line (eg name with no =) */
#define ZNVWARNCOMMENT	100	// Comment or section header found - used 
                              // by runtime frontend tool.
/* getnvlist() argument parameters */
#define ZNV_BEG (0L)					/* 2nd arg => start at bof */
#define ZNV_END ((long)(0x7FFFFFFF))	/* 3rd arg => end at eof */

#define BLOCKSIZE 512
#define BLOCKPOS(x) (((long int) BLOCKSIZE) * (x))

// These are used when converting seconds to a character string.
//  We need to know what is the highest order part of the time 
// field that we are interested in. We dont worry about seconds,
// because no conversion is necessary.
#define ZHOURS		1
#define ZMINUTES	2

//
// Structure Section:
// Place in this section any structure definitions.
//
typedef struct ZDate
{	int zYear;
	char zMonth;
	char zDay;
	char zDayOfWeek;
} ZDATE;

// This struct is used for the report time and such.  It isnt good enough for
//  DB times, because it doesnt support micro seconds
typedef struct ZTime
{	char zHour;
	char zMinute;
	char zSecond;
} ZTIME;

// DBITIME is used to store times coming back from Q&E
//  I'm not sure I need all these structs.
typedef struct DBITime
{	char zHour;
	char zMinute;
	char zSecond;
	unsigned long zMsecond;		// Micro seconds
} DBITIME;

typedef struct TimeInterval
{
	long 		zHours;
	long 	 	zMinutes;
	long	 	zSeconds;
} TIMEINTERVAL;

// DBIDATETIME is used to store the value that Q&E passes back to us from the
//  driver. This is a temporary step to actually saving the datetime value
//  (or just date or just time) in dFldP.  The dFldP pointer points to a 
//  ZDATETIME struct.
typedef struct DBIDateTime
{
	ZDATE		dbiDate;
	DBITIME	dbiTime;
} DBIDATETIME;

typedef struct ZDateTime
{  long 		zDate;
	double 	zTime;
} ZDATETIME;
	

// These 3 structs are only used by util\zfcmp.c and wmain\readsrt.c, I think. -syost
typedef struct Umlaut
{	char umchar;	/* umlaut char */
	char nchar;		/* corresponding ASCII char */
	char echar;		/* correct expansion char */
} UMLAUT;

typedef struct Accent
{	char achar;		/* accented char */
	char nchar;		/* corresponding ASCII char */
} ACCENT;

typedef struct Inequal
{	char achar;		/* accented char */
	char nchar;		/* character preceding accented char */
} INEQUAL;

// This is used by runtime and by runtime front end tool
typedef struct nv			/* name / value structure */
{
	char far *name; 		/* pointer to name */
	char far *value;		/* pointer to value */
	int  vlen;				/* mjs 12/18/92 Length of field value (for Runtime) */ 
	struct nv far *next;		/* next element */
} NV;

#define MAXEQ 128
#define MAXINEQ 128
#define MAXEXP 128
#define TOKENSZ 30

typedef struct Args
{
	int linect;
	char state;
	char first;
	char second;
	unsigned char uct;
	unsigned char act;
	unsigned char ict;
	char *tp;
	char token[TOKENSZ];
	UMLAUT *up[MAXEXP];
	ACCENT *ap[MAXEQ];
	INEQUAL *ip[MAXINEQ];
} ARGS;

//
// Defined a typedef for a user supplied sort routine. This is used in the
// zpsort and lzppsort functions.
//
typedef int (*SORT_ROUTINE)(void *, void *);
typedef int (*LSORT_ROUTINE)(void far *, void far *);



//
// Global Data Section:
// Place in this section any global data.
//
#ifdef _ZCMP_C_
#define GLOBAL
#else
#define GLOBAL extern
#endif



#if 0	// moved for MFC
GLOBAL int near ZNVError;
GLOBAL FOUR	near DateConstant;
GLOBAL char near ZWild;		/* assume no secondary multi-wild character */
GLOBAL char near ZAny;			/* and no secondary single-wild character */
GLOBAL char near ZEscape;		/* and no escape character */
GLOBAL int near DBAnsi;		/* assume OEM character set in databases */
GLOBAL int near ExactComp;		/* assume approximate comparisons */

#if 0	// these are defined in GLOBAL.H
// These next 6 came from zcmp.c
GLOBAL int SortFlat		/* assume case-independent sorting */
#ifdef _ZCMP_C_
 = TRUE
#endif
;
GLOBAL int CompFlat		/* assume case-independent comparisons */
#ifdef _ZCMP_C_
 = TRUE
#endif
;
#endif

GLOBAL int near IndexFlat;		/* assume case-dependent indexes */
GLOBAL int near IndexSRT;		/* assume not using SRT rules with indexes */
GLOBAL int near IndexWin;		/* assume not using Windows routines with indexes */
GLOBAL int near SRTRules;		/* assume no .SRT file */

// These next came from zfcmp.c
GLOBAL char near UCount1;			/* number of lowercase elements in umlaut[] */
GLOBAL char near ACount1;			/* number of lowercase elements in accent[] */
GLOBAL char near ICount1;			/* number of lowercase elements in inequal[] */
GLOBAL char near UCount2;			/* number of elements in umlaut[] */
GLOBAL char near ACount2;			/* number of elements in accent[] */
GLOBAL char near ICount2;			/* number of elements in inequal[] */

/* relative position in accent array determines which equivalent char
   sorts first */
// These 3 globals are only used by util\zfcmp.c and wmain\readsrt.c, I think. -syost
GLOBAL ACCENT *accent;
GLOBAL UMLAUT *umlaut;
GLOBAL INEQUAL *inequal;

#endif	// end of #if 0 for MFC

//
// Function Prototypes Section:
// Place in this section any function prototypes
//



#if 0	// moved for MFC
extern char far *   ldatadir(char far *buf);
extern LPSTR        libdir(LPSTR buf);
extern int          zstrdint(char * string, FOUR *day);
extern int 			  zstrtint(char *string, double *dtime);
extern int          zsflatcomp(LPSTR left, LPSTR right);
extern int          zcompOem(LPSTR left,LPSTR right,int len,int exact,int flat);
extern void         zdateout(FOUR dy,ZDATE *dt);
extern void 		  ztimeout(double mSecs, DBITIME *time_out);
extern void 		  ztimeintervalout(double mSeconds, TIMEINTERVAL *time_out,int timepart);
extern void         zdatedelta(FOUR d1,FOUR d2,ZDATE *dt);
extern int          zERRdbl(double dbl);
extern char far *   lstpblk(char far *p);
extern char *       stpblk(char *p);
extern char *       zmontext(int m);
extern BOOL         lzmatch(char far *pattern, char	far *string);
extern void         lzppsort(char far *list[],int cnt,LSORT_ROUTINE rtn);
extern void         lzmemcpy(char far *dest,char far *src,unsigned ct);
#ifdef RSW
extern BOOL         zdatecheck(ZDATE far *dt);
#else
extern BOOL         zdatecheck(ZDATE *dt);
#endif
extern void         zgetdate(ZDATE *d);
extern char far *   ldatadir(char far *buf);
extern BOOL         zdatenumin(char *s, int places, int *number, int atstar);
extern char *       zfdaytxt(int d);
extern void         zgettime(ZTIME *t);
extern char far *   lzfileext(char far *path);
extern void         zsnullnum(double far *dblP);
extern void         lzpad(char far *s,char c,int	endLen);
extern char *       zfmontxt(int m);
extern int          ztnullnum(double dbl);
extern int          lzcutoff(char far *s, char c);
extern int          zcutoff(char *s, char c);
extern void         zppsort(char *list[],int cnt,SORT_ROUTINE rtn);
extern char *       testdate(char *input);
extern int 			zfcmp(CHARP left,CHARP right,int exact,int flat);
extern int 			zfcmpsort(CHARP left,CHARP right);
extern int 			zfcmp1(CHARPP left,CHARPP right);

#ifdef RSW
extern BOOL         zdatein(ZDATE far *dt, FOUR far *dy);
#else
extern BOOL         zdatein(ZDATE *dt, FOUR *dy);
#endif
extern void 		  ztimein(DBITIME *dt, double far *mSeconds);
extern int          zfncmp(CHARP left,CHARP right,int lgt,int exact,int flat);
extern void         zsnullstr(UONE *data);
extern double		zsERRdbl(void);
extern int			zERRdbl(double dbl);
// These also needed by runtime front-end tool
extern void lfreenvlist(NV far *nv);
extern NV far *     lfindnv(char far *name,NV far *first);
extern NV FAR *getnvlist(int fn,long startpos,long endpos);

// needed for index routines - zmemory(), zcompBin() needed for data dictionary in RSW, too
extern	unsigned int zmemory(unsigned int minsz);
extern	int zcompBin(char far *left,char far *right,int len);
#if !defined (RSW)
extern void zpsort(char *list[],int cnt);
extern int zcompWin(LPSTR left,LPSTR right,int len,int exact,int flat);
#endif

#endif	// end of #if 0 for MFC


#undef GLOBAL

#endif // end _UTIL_H_

// *************************** End of File ************************************
