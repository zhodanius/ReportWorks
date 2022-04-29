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
// $Log:   H:/vcsmfc/h/_ddata.h_v  $
// 
//    Rev 1.2   17 Jul 1995 18:10:24   jpb
// move FIELDNAME struc here for migration
// 
//    Rev 1.1   10 Jul 1995 16:18:08   sbc
// Move stuff to rrdoc.h
// 
//    Rev 1.0   16 Mar 1995 16:14:20   sbc
// Initial revision.
// 
//    Rev 1.1   19 Nov 1993 17:42:54   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:10:34   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __DDATA_H_

//
// Make a definition for this module.
//
#define __DDATA_H_

#include "ddata.h"

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
#define TEXTLIMIT	50

//
// Structure Section:
// Place in this section any structure definitions.
//
#if defined RSW
// The following structure is used in sdrelate.cpp to maintain a list of field names corresponding to the
// "to" field lists in the join dialog.  The "to" field list may not contain simple field
// names and will not represent "real" field specifiers when creating a join (as opposed to
// editing an existing join.  Both the structures and memory for fieldnames will be global
// alloc'ed.
typedef struct FieldName
{
	struct FieldName far * next;
	LPSTR name;
	LPSTR fldLstString;
} FIELDNAME;
typedef FIELDNAME far * LPFIELDNAME;
#endif
//
// Global Data Section:
// Place in this section any global data.
//


//
// Function Prototypes Section:
// Place in this section any function prototypes
//



#endif // end __DDATA_H_

// *************************** End of File ************************************
