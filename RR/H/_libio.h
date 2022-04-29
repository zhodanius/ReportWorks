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
// $Log:   H:/VCSMFC/H/_LIBIO.H_V  $
// 
//    Rev 1.2   06 Jun 1996 14:12:48   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.1   12 Jul 1995 13:24:18   dlm
// Changed functions to CRrDoc member functions and variables to CRrDoc
//  member variables.
// 
//    Rev 1.0   16 Mar 1995 16:14:32   sbc
// Initial revision.
// 
//    Rev 1.2   17 Nov 1994 10:19:08   dlm
// Changed prototypes to indicate far pointers to YZNAME structures.
// 
//    Rev 1.1   19 Nov 1993 17:45:08   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:10:40   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __LIBIO_H_

//
// Includes needed by this header.
//
	#include "libio.h"

//
// Make a definition for this module.
//
#define __LIBIO_H_

#if defined _YYINIT_C_
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
#define NOFILE (-1)

	// from yyhooks.h, YYBUFCT used in yyopen.c, yycreate.c, yygetblk.c
#define	YYBUFCT 6

	// from yychunk.h
#define YYMAJ_REV		1
#define YYMIN_REV		3	/* so RR v3 can't read version 4 libraries */
#define YYMIN_V3		2	/* old R&R for dBASE version (yyopen uses this) */
#define YYLINKSZ		3
#define YYCHUNKmaxNO	((1L << 24) - 1)
#if YYLINKSZ != 3
	fix definition of YYChunk; link size is wrong
#endif

	// from yyerror.h
#define DOS_SHARING_VIOLATION	0x20	/* int 21 share error code */

// **************************************************************************
//
// Structure Section:
// Place in this section any structure definitions.
//
typedef YYCHUNK far	*LPYYCHUNK;

// **************************************************************************
//
// Global Data Section:
// Place in this section any global data.
//


#if 0
GLOBAL YYFILETAB *near yy_ftab;
GLOBAL LPYYBUFFER near yy_bufe;				/* end of buffer pool */
GLOBAL int near yy_time;
GLOBAL int near yy_headchg;

GLOBAL UONE near YyMajRev
 #if defined _YYINIT_C_
 = YYMAJ_REV
 #endif
;

GLOBAL UONE near YyMinRev
 #if defined _YYINIT_C_
= YYMIN_REV
 #endif
;

GLOBAL LPYYBUFFER near yy_bufs
 #if defined(_YYINIT_C_)
	= NULL
 #endif
;
GLOBAL LPYYBUFFER near yy_bufx
 #if defined(_YYINIT_C_)
	= NULL
 #endif
;
GLOBAL int near YYCheckSpace
 #if defined(_YYINIT_C_)
	= 0
 #endif
;
 #if defined(RSW)
GLOBAL char	near yyfilext[]
  #if defined(_YYINIT_C_)
	= ".RP6"
  #endif
;
 #else
GLOBAL char	near yyfilext[]
  #if defined(_YYINIT_C_)
	= ".RP5"
  #endif
;
 #endif
#endif



// **************************************************************************
//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#if 0
extern	void yy_binit(void);
extern	void yy_crinit(int type,int chksz);
extern	void yy_flush(int final);
extern	int zlrdblock(int file,int blkno,char FAR *dest);
extern	int zlwrblock(int file,int blkno,char FAR *source);
extern	struct YYBuffer FAR *yy_getblk(unsigned int rbn);
extern	struct YYBuffer FAR *yy_getbuf(void);
extern	struct YYBuffer FAR *yy_getchk(long c,union YYChunk FAR **ppc );
extern	long yy_getcn(void);
extern	long yy_getlink(union YYChunk FAR *pc);
extern	int yyinit(int bufc);
extern	void yysetext(char *ext);
extern	void yy_setlink(union YYChunk FAR *pc,long c);
extern	int yy_wrbuf(struct YYBuffer FAR *pb);
extern	void yy_wrhdr(void);
extern	void yzcompname(struct YYFiletab *ftab);
extern	int yz_delname(struct YYFiletab *ftab,LPYZNAME yzname,int del);
extern	int yzrename(struct YYFiletab *ftab,LPYZNAME yzname,char *newone);
#endif


#undef GLOBAL
#endif // end __LIBIO_H_

// *************************** End of File ************************************
