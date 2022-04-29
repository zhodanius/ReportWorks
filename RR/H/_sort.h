// ****************************************************************************
//
//      (C) Copyright 1992-1993 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $Workfile:   _sort.h  $
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
// $Log:   I:/vcsmfc/h/_sort.h_v  $
// 
//    Rev 1.4   17 Sep 1995 16:45:50   par
// Corrected SRPack.
// 
//    Rev 1.3   10 Jul 1995 11:03:58   dlm
// Removed unused definition of DTYPE.
// 
//    Rev 1.2   06 Jul 1995 15:49:26   dlm
// Moved sort variables and functions to CRrDoc.
// 
//    Rev 1.1   26 Apr 1995 11:51:40   pjm
// 6.1.03 -> 7.0 merge
// 
//    Rev 1.0   16 Mar 1995 16:14:58   sbc
// Initial revision.
// 
//    Rev 1.3   23 Mar 1995 17:09:56   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
// 
//    Rev 1.2   10 Mar 1994 14:41:14   nwh
// (dlm) Miscellaneous changes relating to sort performance improvements,
//  including change of maximum merge files from 10 to 20.
// 
//    Rev 1.1   19 Nov 1993 17:42:04   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:10:48   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __SORT_H_

//
// Includes needed by this header.
//
	#include "sort.h"
	#include "mffield.h"	// needed for zfXXX definitions

#if defined _GSORT_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

//
// Make a definition for this module.
//
#define __SORT_H_

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
//#define	DTYPE	(zfNUMERIC | zfDATE | zfLOGICAL | zfDATETIME | zfTIME)
#define	NOFILE	(-1)

#define MAX_SORT_FIELDS		8
#define MAX_MERGE_FILES		60		// arbitrary number equal to number of links

// Values used in SRTypes[] to indicate data types of SRFields[] fields.
// They are mapped from zfNUMERIC, etc. by gsort().
#define stCHAR		 0		// we want these to be consecutive integers
#define stNUM		 1		// for reasons of srinorder performance
#define stDATE		 2
#define stLOG		 3
#define stDATETIME 4
#define stTIME		 5

typedef char far * far	*LPLPSTR;

//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//


#if 0	// moved to h\rrdoc.h & rr\rrdoc.cpp
GLOBAL int * near	SRAscend;		// for each SRFields item: sort ascending?
GLOBAL int near		SRMergeMode;	// mfpstat() mode for merge phase display
GLOBAL int near		SRPktSize;		// size of sort packet
GLOBAL FOUR near	SRRecNo;
GLOBAL LPSTR near	SRBuffer;		// for merge file buffering
GLOBAL UINT near	SRBufCt;		// number of chars in buffer, so far
GLOBAL UINT near 	SRBufSize;		// buffer size
GLOBAL int near 	SRTypes[MAX_SORT_FIELDS];	// stXXXX data types of SRFields[]

 #if MAX_MERGE_FILES != 20
  !!! Fix the initializer for SRHandles in _sort.h !!!
 #endif
	// maximum of MAX_MERGE_FILES input files + one output file
	// last entry is used for output file
GLOBAL UINT near SRHandles[MAX_MERGE_FILES+1]
 #if defined(_GSORT_C_)
	= {	(UINT)-1,(UINT)-1,(UINT)-1,
		(UINT)-1,(UINT)-1,(UINT)-1,
		(UINT)-1,(UINT)-1,(UINT)-1,
		(UINT)-1,(UINT)-1,(UINT)-1,
		(UINT)-1,(UINT)-1,(UINT)-1,
		(UINT)-1,(UINT)-1,(UINT)-1,
		(UINT)-1,(UINT)-1,(UINT)-1}	// 21 initializers
 #endif
;
#endif



//
// Function Prototypes Section:
// Place in this section any function prototypes
//


 #if 0	// moved to rrdoc.h and rr\rrdoc.cpp
GLOBAL int	(* near SRRead)(void);
GLOBAL int	(* near SRWrite)(int, LPSTR);
GLOBAL int	(* near SRPack)(LPSTR, UINT);

int		srmerge(UINT high, LPSTR resultFile);
int		srinsertsort(LPLPSTR memory, int ff, int jj);
int		srsortmemory(LPLPSTR memory, /* int firstRecord,*/ int lastRecord);
int		srsortfile(int *lastTemp, char far *sortFile);
void	srexchange(LPLPSTR one, LPLPSTR two);
int		srinorder(LPSTR earlier, LPSTR later);
void	srbase36(PSTR string, WORD num);
void	srtempname(char *name, int num);
int		srmaketemp(int fileNum);
int		srflushbuf(int outFile);
int		srwrrecord(int outFile, LPSTR record);
int		srrdrecord(int inFile, LPSTR record);
 #endif


#undef GLOBAL
#endif // end __SORT_H_

// *************************** End of File ************************************
