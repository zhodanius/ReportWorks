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
// $Log:   H:/vcsmfc/h/_mfedit.h_v  $
// 
//    Rev 1.2   11 Jul 1995 17:08:08   jpb
// add OX struc
// 
//    Rev 1.1   07 Jul 1995 18:11:56   jpb
// First pass at moving all data and functions to CRrDoc class
// 
//    Rev 1.0   16 Mar 1995 16:14:38   sbc
// Initial revision.
// 
//    Rev 1.2   19 Nov 1993 17:45:24   sbc
// Add extern C for C++
// 
//    Rev 1.1   04 Nov 1993 15:45:50   jpb
// Use MF "global internal header" _mf.h instead of foreign internal MF headers
// 
//    Rev 1.1   04 Nov 1993 15:25:16   jpb
// Use MF "global internal header" _mf.h instead of foreign internal MF headers
// 
//    Rev 1.0   14 Oct 1993 10:12:28   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __MFEDIT_H_

//
// Make a definition for this module.
//
#define __MFEDIT_H_

#include "mfedit.h"
#include "mffile.h"

#if defined (_EDITMAST_C_)
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
typedef struct ox
{
	char	oType;		/* 0 = field, 1 = udf */
	char	far *oPtr;	/* pointer to specifier (coerced) */
} OX;

//
// Global Data Section:
// Place in this section any global data.
//



// GLOBAL LPSTR UserSelect;  // Already in mffile.h



//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#if 0
extern LPMFFILE lfilen(int n);
extern int mfckalias(char *name);
 #if defined RSW
extern void selectcleanup(void);
 #endif
#endif



#undef GLOBAL

#endif // end __MFEDIT_H_

// *************************** End of File ************************************

