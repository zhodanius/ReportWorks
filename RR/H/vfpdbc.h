// ****************************************************************************
//
//      (C) Copyright 1997 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
// Structures for Visual FoxPro DBC mapping table
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/vfpdbc.h_v  $
// 
//    Rev 1.1   03 Apr 1997 21:10:28   pjm
// Mode DBC-related changes.
// 
//    Rev 1.0   19 Mar 1997 09:58:22   pjm
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _VFPDBC_H_
//
// Make a definition for this module.
//
#define _VFPDBC_H_

#include "product.h"	// for MAXDNAME etc.

// ********************************************************************
//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
//
//
// Structure Section:
// Place in this section any structure definitions.
//

// define the long/short tablename mapping structure
typedef struct dbctbl
{
	int	TblID; 				 		// Object ID (from DBC)
	char	TblName[MAXDNAME]; 		// Object (long table) Name (from DBC)
	char	TblPath[WINPATHLEN];		// Full Path to short name (from DCT)
	struct dbcfld * nxtField;		// pointer to next DBCFLD structure
	struct dbctbl * nxtTable;		// pointer to next DBCTBL structure
} DBCTBL;

// define the long/short fieldname mapping structure
typedef struct dbcfld
{
	char	lFldName[MAXDNAME];		// long field name (from DBC
	char	sFldName[MAXSDNAME];		// short field name (from DBF)
	struct dbcfld * nxtField;
} DBCFLD;


#undef GLOBAL
#endif // end _VFPDBC_H_

// *************************** End of File ************************************
