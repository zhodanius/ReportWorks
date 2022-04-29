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
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/H/_MFFIELD.H_V  $
// 
//    Rev 1.2   Feb 27 2001 15:33:16   nhubacker
// Removed some INTERACTIVE #if
// 
//    Rev 1.1   07 Jul 1995 18:11:54   jpb
// First pass at moving all data and functions to CRrDoc class
// 
//    Rev 1.0   16 Mar 1995 16:14:40   sbc
// Initial revision.
// 
//    Rev 1.5   22 Sep 1994 09:58:06   sjo
// Fixed a problem with compiling editcalc.c for the runtime.
// 
//    Rev 1.4   21 Sep 1994 16:19:26   sjo
// Added a structure to allow us to change field and calc's which are fully
// qualified. Also changed mfeord.c, editcalc.c and cfrepnm.c. Fixes RSW bug
// #605.
// 
//    Rev 1.3   19 Nov 1993 17:44:50   sbc
// Add extern C for C++
// 
//    Rev 1.2   05 Nov 1993 16:48:50   smh
// Moved a couple of things from here to _mf.h for the runtime.
// 
//    Rev 1.1   04 Nov 1993 15:45:52   jpb
// Use MF "global internal header" _mf.h instead of foreign internal MF headers
// 
//    Rev 1.1   04 Nov 1993 15:25:18   jpb
// Use MF "global internal header" _mf.h instead of foreign internal MF headers
// 
//    Rev 1.0   14 Oct 1993 10:12:36   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __MFFIELD_H_

//
// Make a definition for this module.
//
#define __MFFIELD_H_

#include "mffield.h"

#if defined (_MFGETFLD_C_)
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

//#ifdef INTERACTIVE
typedef struct mff_fileno_entry
{
struct mff_fileno_entry far	*next;	// pointer to next in chain
LPMFFIELD		change_field;
char				old_dfileno;				// old filenumber
} MFF_FILENO_ENTRY;

typedef struct mff_fileno_header
{
MFF_FILENO_ENTRY far	*head;	// pointer to the head of the chain
MFF_FILENO_ENTRY far	*tail;	// pointer to the tail of the chain
} MFF_FILENO_HEADER;
//#endif

//
// Global Data Section:
// Place in this section any global data.
//

#if 0

#if defined INTERACTIVE
GLOBAL MFF_FILENO_HEADER	far *fileno_header
 #if defined (_MFGETFLD_C_)
 	= NULL
 #endif
;
#endif

#endif

//
// Function Prototypes Section:
// Place in this section any function prototypes
//

#if 0

#if !defined RSW
extern	void freqtext(int sindex,char *buf,int forprompt);
#endif
extern	void mfrlsfld(LPMFFIELD f,int o);

#endif

#undef GLOBAL

#endif // end __MFFIELD_H_

// *************************** End of File ************************************

