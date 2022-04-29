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
// $Log:   H:/vcsmfc/h/_mffile.h_v  $
// 
//    Rev 1.1   07 Jul 1995 18:11:58   jpb
// First pass at moving all data and functions to CRrDoc class
// 
//    Rev 1.0   16 Mar 1995 16:14:42   sbc
// Initial revision.
// 
//    Rev 1.4   21 Mar 1994 11:56:40   dlm
// Merge of Abra branch:
//  Moved memo-file extension strings to mffile.h.
//  Moved mfnewfil() extern to mffile.h.
// 
//    Rev 1.3   18 Feb 1994 15:25:56   sjo
// I am merging the RRWINNSX branch back onto the RRWIN tree. This branch was
// setup to allow me to port my RR 5.1 NSX, SMT and DBV changes to RRW and
// RSW.
// 
//    Rev 1.2.1.0   24 Jan 1994 10:01:50   sjo
// I am merging RR 5.1 changes into the windows products.  I added two new memo
// file extensions - DBV and SMT.
// 
//    Rev 1.2   19 Nov 1993 17:44:46   sbc
// Add extern C for C++
// 
//    Rev 1.1   04 Nov 1993 15:45:48   jpb
// Use MF "global internal header" _mf.h instead of foreign internal MF headers
// 
//    Rev 1.1   04 Nov 1993 15:25:14   jpb
// Use MF "global internal header" _mf.h instead of foreign internal MF headers
// 
//    Rev 1.0.1.1   28 Feb 1994 11:09:02   dlm
// Removed a commented out extern.
// 
//    Rev 1.0.1.0   11 Jan 1994 10:47:58   dlm
// Moved .DBT and .FPT strings to mffile.h.
// Moved lmfopen(), mfnewfil(), newext() externs to mffile.h.
// 
//    Rev 1.0   14 Oct 1993 10:12:34   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __MFFILE_H_

//
// Make a definition for this module.
//
#define __MFFILE_H_

#include "mffile.h"

#if defined (_MFGETFTB_C_)
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






//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#if 0
// First group is from common MFFILE modules
extern	int colnames(LPSTR lpSelect, int *curoffP);
extern	void lmfalias(char far *name);
extern	LPMFFIELD matchfld(LPMFFIELD fld);
extern	int mfainit(void);
extern	void mfcfabt(void);
extern	int mfcfinit(void);
extern	int mfchgfil(int doit, int *askedP);
extern	int mfmemfld(char *name,long start,long end);
extern	int mfsetlvl(void);
extern	void mfunlink(int rfileno);
extern	int nextcolname(LPSTR *names, LPSTR *nextname, PINT namelen);
extern	int nexttok(LPSTR lpSelect, int *curoffP, PSTR token);

#if !defined RSW
extern	sxsetscan(char far *expr);
#endif

// Next group is from RRW-specific MFFILE modules
extern	int lmfnewrec(LPMFFILE file);
extern	LPMFFILE lmfnxtfil(void);
extern	int lmfodbf(LPMFFILE fil);
extern	int lmfodbt(LPMFFILE fil);
extern	LPMFFILE near lnextchild(LPMFFILE prevchild,LPMFFILE curparent);
extern	LPMFFILE near lparent(LPMFFILE file);
extern	int mfclose1(void);
extern	void newext(char *name,char *ext);

#endif

#undef GLOBAL

#endif // end __MFFILE_H_

// *************************** End of File ************************************

