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
// Internal "global" header for MF* directory modules
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/_mf.h_v  $
// 
//    Rev 1.3   31 Jul 1995 16:03:14   jpb
// More classification
// 
//    Rev 1.2   26 Jul 1995 17:13:02   jpb
// add MF_DTYPE
// 
//    Rev 1.1   07 Jul 1995 18:11:56   jpb
// First pass at moving all data and functions to CRrDoc class
// 
//    Rev 1.0   16 Mar 1995 16:14:34   sbc
// Initial revision.
// 
//    Rev 1.7   31 Oct 1994 15:54:52   jpb
// add a prototype for wizard stuff
// 
//    Rev 1.6   19 Jul 1994 18:00:38   jpb
// add extern for total condition evaluator
// 
//    Rev 1.5   05 Apr 1994 12:24:44   dlm
// Added "alias" argument to extern for mfnewfil().
// 
//    Rev 1.4   24 Mar 1994 10:03:04   dlm
// Moved extern for mfnewfil() from mffile.h to _mf.h.
// 
//    Rev 1.3   23 Mar 1994 16:13:30   erp
// removed mfnewfil from local header file to public header file
// 
//    Rev 1.2   19 Nov 1993 17:39:48   sbc
// Add extern C for C++
// 
//    Rev 1.1   05 Nov 1993 16:48:20   smh
// Moved a couple of things here from _mffield.h for the runtime.
// 
//    Rev 1.0   04 Nov 1993 15:24:22   jpb
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __MF_H_

//
// Make a definition for this module.
//
#define __MF_H_

#include "mffile.h"

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

/* mask to retain type of a field */
#define	MF_DTYPE	(zfNUMERIC | zfDATE | zfLOGICAL | zfMEMO | zfDATETIME | zfTIME)

//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//

#if 0

GLOBAL int MFAFile						// from _MFDATA.H
 #if defined (_MFINIT_C_)
		= -1;
 #else
 		;
 #endif

GLOBAL long near MFAge;					// from _MFDATA.H
GLOBAL int near MFDelCAC				// from _MFDATA.H
 #if defined (_MFINIT_C_)
		= FALSE;
 #else
 		;
 #endif

GLOBAL int near MFDelGFP				// from _MFDATA.H
 #if defined (_MFINIT_C_)
		= FALSE;
 #else
 		;
 #endif

GLOBAL int near MFDelTOT				// from _MFDATA.H
 #if defined (_MFINIT_C_)
		= FALSE;
 #else
 		;
 #endif
			     
GLOBAL int MFDoQuery;					// from _MFDATA.H
GLOBAL LPMFFIELD near MFErrFld;			// from _MFDATA.H
GLOBAL int near MFEvalCode;				// from _MFDATA.H
GLOBAL int MFGroupChan    				// from _MFDATA.H
 #if defined (_MFINIT_C_)
		= -1;
 #else
 		;
 #endif

// GLOBAL char * near mflimbonm;			// from _MFFIELD.H
GLOBAL long near MFMastRecCnt;			// from _MFERROR.H
GLOBAL unsigned int near MFMaxMatch;	// from _MFERROR.H
GLOBAL LPMFFIELD far * near MFNdxTab;	// from _MFDATA.H
GLOBAL int (*MFPostRead)(); 			// from _MFDATA.H
GLOBAL char far * near MFRecBuf; 		// from _MFDATA.H
GLOBAL long near MFRecCnt;  			// from _MFDATA.H
GLOBAL int MFSort     					// from _MFDATA.H
 #if defined (_MFINIT_C_)
		= -1;
 #else
 		;
 #endif

GLOBAL LPSTR MFSortFile;     			// from _MFDATA.H
GLOBAL int MFSortFinal;     			// from _MFDATA.H
GLOBAL char MFSQLCIPName[WINPATHLEN+1];	// from _MFFILE.H
GLOBAL LPSTR far * MFSQLNames;			// from _MFFILE.H
GLOBAL int MFSQLSelectOffset;			// from _MFFILE.H
GLOBAL int qeoff;							// from _mffield.h
GLOBAL int qenum;							// from _mffield.h
GLOBAL LPSTR far * saveMFSQLNames;		// from _MFEDIT.H
GLOBAL int saveMFSQLSelectOffset;		// from _MFEDIT.H
#endif

GLOBAL char NEAR TCDXX []					// from _MFFILE.H
 #if defined (_MFINIT_C_)
	= ".CDX";	// extension of Paradox 2 multiple index file name
 #else
	;
 #endif

GLOBAL char NEAR TIDXX []					// from _MFFILE.H
 #if defined (_MFINIT_C_)
	= ".IDX";	// extension of index file name (Foxbase)
 #else
	;
 #endif

GLOBAL char NEAR TMDXX []					// from _MFFILE.H
 #if defined (_MFINIT_C_)
	= ".MDX";	// extension of dBASE IV multiple index file name
 #else
	;
 #endif

GLOBAL char NEAR TNDXX []					// from _MFFILE.H
 #if defined (_MFINIT_C_)
	= ".NDX";	// extension of index file name (dBASE)
 #else
	;
 #endif

GLOBAL char NEAR TNTXX []					// from _MFFILE.H
 #if defined (_MFINIT_C_)
	= ".NTX";	// extension of index file name (Clipper)
 #else
	;
 #endif


//
// Function Prototypes Section:
// Place in this section any function prototypes
//

#if  0

extern int AreWeWizing(void);
extern int cktotcond(LPMFFIELD fld);	// from _MFDATA.H
extern void countbox(void);				// from _MFMISC.H
extern void grpclear(void);				// from _MFMISC.H
extern void grpinit(void);				// from _MFMISC.H
extern void grpnext(void);				// from _MFMISC.H
extern void lmfffilss(LPMFFILE file);	// from _MFDATA.H
extern int lmfnewrec(LPMFFILE file);	// from _MFFILE.H
extern LPMFFILE lmfnxtfil(void);		// from _MFFILE.H
extern int lmfodbf(LPMFFILE fil);		// from _MFFILE.H
extern int lmfodbt(LPMFFILE fil);		// from _MFFILE.H
extern void mfcfabt(void);				// from _MFFILE.H
extern int mfcfinit(void);				// from _MFFILE.H
extern int mfchgfil(int doit, int *askedP);	// from _MFFILE.H
#if defined(RSW)
extern	int mfnewfil(int fn,char *name,LPSTR select,LPSTR far *names,LPSTR alias);
#else
extern	int mfnewfil(int fn,char *name,char *alias);
#endif
extern void mfffldss(LPMFFIELD fld);	// from _MFDATA.H
extern int mfmemdbc(void);				// from _MFMISC.H
extern void mfrepfld(LPMFFIELD ofld,LPMFFIELD nfld); // from _MFFIELD.H
extern int mfsetlvl(void);				// from _MFFILE.H
extern int mfslist(LPMFFIELD sf[], int sa[]);	// from _MFERROR.H
extern void mfunlink(int rfileno);		// from _MFFILE.H
extern int parseSelect(LPSTR lpSelect, PINT offP); // from _MFFILE.H
extern void rcinit(void);				// from _MFMISC.H
extern void set_current_db(LPSTR lpszTableName); // from _MFDATA.H
#endif


#undef GLOBAL
#endif // end __MF_H_
// *************************** End of File ************************************

