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
// $Log:   H:/VCSMFC/H/LIBIO.H_V  $
// 
//    Rev 1.4   16 Jan 1998 15:36:06   JSF
// PTF 20001 merge
// 
//    Rev 1.3.1.0   23 Oct 1997 13:46:58   jsf
// added sqlext.h for VC50
// 
//    Rev 1.3   06 Jun 1996 14:21:18   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.2   22 Sep 1995 13:47:54   dlm
// 32-bit-related edits.
// 
//    Rev 1.1   12 Jul 1995 13:24:08   dlm
// Changed functions to CRrDoc member functions and variables to CRrDoc
//  member variables.
// 
//    Rev 1.0   16 Mar 1995 16:12:46   sbc
// Initial revision.
// 
//    Rev 1.7   17 Nov 1994 10:18:40   dlm
// Changed prototypes to indicate far pointers to YZNAME structures.
// 
//    Rev 1.6   28 Sep 1994 15:46:54   sbc
// FileOpenName -> Paths
// 
//    Rev 1.5   03 Aug 1994 12:27:00   smh
// Added yznNote to YZNAME structure for report annotation info
// 
//    Rev 1.4   08 Jun 1994 14:37:02   erp
// changed FAR to far, so it will build for 32-bits
// 
//    Rev 1.3   14 Mar 1994 15:27:40   dlm
// Added definitions of ABRA library-type sub-codes and comments about how
//  I screwed up the RRW one.
// 
//    Rev 1.2   28 Jan 1994 17:36:38   say
// 
//    Rev 1.1   19 Nov 1993 17:39:46   sbc
// Add extern C for C++
// 
//    Rev 1.0.1.1   28 Feb 1994 11:04:14   dlm
// Added definition of RRREP_OEM_ABRA and comment about how I screwed up
//  definition of RRWIN_OEM_ABRA.
// 
//    Rev 1.0.1.0   11 Jan 1994 10:55:18   dlm
// Added library type sub-code for ABRA OEM version.
// 
//    Rev 1.0   14 Oct 1993 10:10:38   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _LIBIO_H_

//
// Make a definition for this module.
//
#define _LIBIO_H_

#include "util.h"	// for ZDATE, ZTIME
#if defined RSW
#include "sql.h"	// for SQL_MAX_DSN_LENGTH
#include "sqlext.h"	// for SQL_MAX_DSN_LENGTH, now here in VC 5.0
#endif

#if defined _YYINIT_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

// ********************************************************************
//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
	// from yz.h - application-level nosam routines & structures
	// "user-defined" type codes for library contents
	// OEM sub-codes need only be unique for a specific type code
	//  i.e., if we make an OEM version of RSW, the first one can also have
	//  a value of 0x100.  This allows for 256 OEM variants of each of 256
	//  library types.  The purpose of sub-codes is to make OEM libraries
	//  unusable by other OEM or standard versions of the same basic product
	//  and to make standard libraries unusable by the OEM products.
	// YZC_RRWIN_ABRA should have been defined as YZC_RRWIN | 0x100 so first
	//  OEM version of YZC_RRREP must be 0x200!?
#define YZC_RRREP 0		/* R&R report libraries */
 #define YZC_RRREP_ABRA (YZC_RRREP | 0x200)	// OEM sub-code for ABRA libraries
#define YZC_RWREP 1		/* RW report libraries */
#define YZC_RXREP 2		/* RX report libraries */
#define YZC_RRUDF 0		/* R&R/RW udf libraries */
#define YZC_RRFONT 3	/* R&R/RW/SQL font libraries */
#define YZC_RPREP 4		/* RP report libraries */
#define YZC_RRWIN 5		/* R&R for Windows - dBASE version */
#define YZC_RPWIN 6		/* R&R for Windows - Paradox version */
 #define YZC_RRWIN_ABRA 0x100	// OEM sub-code for ABRA libraries
#define YZC_RWWIN 7		/* R&R for Windows - Worksheet version */
#define YZC_RXWIN 8		/* R&R for Windows - SQL version */
	// library chunk sizes - MUST BE POWER OF 2 (in range 32-512)
#define YZSZ_RRREP 512	/* used for dBASE and SQL versions */
#define YZSZ_RWREP 512
#define YZSZ_RRUDF 32
#define YZSZ_RRFONT 32

	// from yyerror.h
#define YYEBCN			0x100		/* bad chunk number */
#define YYENCP			0x101		/* no current position */
#define YYEIM			0x102		/* insufficient memory */
#define YYEIBN			0x103		/* invalid block number */
#define YYEDE			0x104		/* disk error */
#define YYEDF			0x105		/* disk full */
#define YYECOF			0x106		/* can't open file */
#define YYEFF			0x107		/* file full */
#define YYEIFR			0x108		/* invalid file revision */

	// yzerror.h, defines used in yz.c
#define YZEIAC			0x200		/* invalid application chain */
#define YZENIU			0x201		/* name in use */
#define YZENSN			0x202		/* no such name */

// ********************************************************************
//
// Structure Section:
// Place in this section any structure definitions.
//
typedef union YYChunk
{	struct 
	{	char yycHLk;	/* high-order byte of link to next chunk */
		unsigned short yycLLk;	/* low-order word of link */
		char yycData[1];	/* really chunksize-YYLINKSZ */
	} c;
	struct
	{	char yy0HLk;	/* high-order byte of link to next chunk */
		unsigned short yy0LLk;	/* low-order word of link */
		char yy0Major;	/* major rev number of nosam file format */
		char yy0Minor;	/* minor rev number of nosam file format */
		long yy0Free;	/* chunk number of 1st chunk in free chain or NULL */
		long yy0App;	/* 1st chunk num of main application chain or NULL */
		long yy0Next;	/* chunk number of next unallocated chunk */
		unsigned short yy0Size;	/* file size in blocks */
		unsigned short yy0ChkSz;	/* chunk size in bytes */
		unsigned short yy0Type;	/* type code identifying library contents */
	} c0;
} YYCHUNK;

typedef struct YYBuffer
{	char yyBMf;						/* modified flag */
	unsigned int yyBRb;						/* relative block number */
	unsigned int yyBTm;						/* time of assignment */
	unsigned int yyBFn;						/* file number */
	union
	{	YYCHUNK yyChunk[1];			/* actual data (really many chunks) */
		char yyBuf[YYBLKSZ];		/* to make sizeof(YYBUFFER) work */
	} yyB;							/*  and buffer pointer manipulation */
} YYBUFFER;

typedef YYBUFFER far	*LPYYBUFFER;

typedef struct YYFiletab
{	int yyFile;			/* channel number */
	long yyFree;		/* chunk number of start of free chunk chain */
	long yyApp;			/* chunk number of start of main application chain */
	long yyNext;		/* chunk number of next available block */
	unsigned short yySize;		/* file size in blocks */
	long yyChk;			/* chunk number of current file position */
	unsigned short yyOff;			/* offset in yyRec of current file position */
	unsigned short yyType;		/* type code identifying library contents */
	unsigned short yyChkSz;		/* chunk size in bytes */
	char yyChkPerBlk;	/* corresponding number of chunks per block */
} YYFILETAB;

typedef struct yzstamp
{	ZDATE yzsDate;			/* date structure */
	ZTIME yzsTime;			/* time structure */
	char yzsUser[1];		/* really strlen(user id string)+1 chars */
} YZSTAMP;

typedef YZSTAMP far * LPYZSTAMP;

typedef struct yzname
{	struct yzname far * yznLk;	// link to next yzname structure or NULL
	long yznChNo;				// starting chunk number for additional info
	LPYZSTAMP yznStamp;			// pointer to time stamp or NULL
	LPSTR yznNote;				// report annotation
#if defined RSW
	char yznDataSource[SQL_MAX_DSN_LENGTH];	// data source name
#endif
	char yznName[1];			// really strlen(name)+1 characters
} YZNAME;

typedef YZNAME far * LPYZNAME;
//
// Global Data Section:
// Place in this section any global data.
//


#if 0
GLOBAL int near YYError;
GLOBAL YYFILETAB *RepFile;
#endif


//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#if 0
extern	LPYZNAME yzread1name(struct YYFiletab *ftab,char *name);
extern	void yzrlsnames(LPYZNAME yzname);
extern	int lyyrdseq(struct YYFiletab *ftab,int bct,char far *p);
extern	struct YYFiletab *yycreate(LPSTR name,int share,LPSTR full,int type,int chksz);
extern	char *yyetext(void);
extern	int yyfreechunks(struct YYFiletab *ftab,long c);
extern	struct YYFiletab *yyopen(char far *name,int sharing,int mode,int *type,int chksz);
extern	int yzaddname(struct YYFiletab *ftab,LPYZNAME yzname);
extern	int yzdelname(struct YYFiletab *ftab,LPYZNAME yzname);
extern	void yyclose(struct YYFiletab *ftab);
extern	long yygetchunkno(struct YYFiletab *ftab);
extern	void lyysetchunkno(struct YYFiletab *ftab,long c);
extern	char far *yyosname(char far *s);
extern	int lyywrseq(struct YYFiletab *ftab,int bct,char far *p,int f,int r);
extern	void yyreset(void);
extern	int yzupdatename(struct YYFiletab *ftab,LPYZNAME yzname);
extern	LPYZNAME yzreadnames(struct YYFiletab *ftab);
#endif


#undef GLOBAL
#endif // end _LIBIO_H_

// *************************** End of File ************************************
