// ****************************************************************************
//
//      (C) Copyright 1992-1993 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $Workfile:   sort.h  $
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
// $Log:   H:/vcsmfc/h/sort.h_v  $
// 
//    Rev 1.4   07 Feb 1996 09:06:42   dlm
// Changed default size of "sort pool" from 60000 to 512KB.
// 
//    Rev 1.3   06 Jul 1995 15:48:28   dlm
// Moved sort member variables and functions to CRrDoc class.
// 
//    Rev 1.2   01 May 1995 16:54:44   dlm
// Cleaned up some prototypes.
// 
//    Rev 1.1   26 Apr 1995 11:51:22   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.0   16 Mar 1995 16:13:32   sbc
// Initial revision.
// 
//    Rev 1.4   31 Mar 1995 14:22:50   dlm
// Defined parameters for how to sort null values.  Also defined
//  SREmptyOrder and SREmptyNumsZero variables for same.  Defaults
//  are to sort nulls as low values and to treat null nums as zeros.
// 
//    Rev 1.3   20 Jan 1995 15:46:42   dlm
// Fixed some compiler warnings in gsort.c.
// 
//    Rev 1.2   10 Mar 1994 14:48:02   nwh
// (dlm) Added definition of SORTPOOLSIZE.  Mostly minor reformatting.
// 
//    Rev 1.1   19 Nov 1993 17:42:12   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:10:48   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _SORT_H_

//
// Includes needed by this header.
//
	#include "mffield.h"

#if defined _GSORT_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

//
// Make a definition for this module.
//
#define _SORT_H_

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
#ifdef RSW
#define MAXCHARSORT		1000	// largest string we'll sort (excl. null term)
#endif
#define SORTPOOLSIZE	1024*512	// size of buffer for sorting (override in R?W.INI: [Special] SortPoolSize)

// Values for SREmptyOrder indicating how to sort empty (null) values
//  for ODBC platform compatibiity.  EARLY is default.
#define SREMPTYisLOW	0
#define SREMPTYisHIGH	1
#define SREMPTYisFIRST	2
#define SREMPTYisLAST	3

//
// Structure Section:
// Place in this section any structure definitions.
//
typedef struct SortRec
{
	UINT	srBytes;	// bytes this record takes up
	long	srRecNo;	// input record sequence number (for stability)
	long	srID;		// position or recno in the file
} SORTREC;

typedef SORTREC far		*LPSORTREC;

//
// Global Data Section:
// Place in this section any global data.
//


#if 0	// moved to rrdoc.h & rr\rrdoc.cpp
GLOBAL LPMFFIELD * near	SRFields;	// list of fields to sort; ends with NULL
GLOBAL UINT near		SRMxRcSz;
GLOBAL int near			SRNoPtrs;
GLOBAL UINT				SREmptyOrder	// flag for how to sort empty values for platform compatibility
 #if defined(_GSORT_C_)
	= SREMPTYisLOW
 #endif
;
GLOBAL UINT				SREmptyNumsZero	// if TRUE, treat empty NUMs as zeros
 #if defined(_GSORT_C_)
	= TRUE
 #endif
;
GLOBAL UINT near		SRPoolSize
 #if defined(_GSORT_C_)
	= SORTPOOLSIZE
 #endif
;
 #if !defined(INTERACTIVE)
GLOBAL int near SRHiTemp
  #if defined(_GSORT_C_)
	= -1
  #endif
;
 #endif
#endif



//
// Function Prototypes Section:
// Place in this section any function prototypes
//


 #if 0
int sort(LPMFFIELD *fields, int *ascend, char far *sortFile);
int gsort(LPMFFIELD *fields, int *ascend, char far *sortFile, int (*init)(void),
	void (*end)(void), int (*rd)(void), int (*wr)(int, LPSTR), int (*pack)(LPSTR, int),
	int noptrs, char *outext, int mergemode);
void srdeltemps(int lastTemp);
 #endif


#undef GLOBAL
#endif // end _SORT_H_

// *************************** End of File ************************************
