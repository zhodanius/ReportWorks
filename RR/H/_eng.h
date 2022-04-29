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
// $Log:   H:/vcsmfc/h/_eng.h_v  $
// 
//    Rev 1.2   02 Aug 1995 11:00:08   smh
// Moved #undef GLOBAL to where it is not #if 0ed out.
// 
//    Rev 1.1   19 Jul 1995 10:25:16   jpb
// move to doc class
// 
//    Rev 1.0   16 Mar 1995 16:14:28   sbc
// Initial revision.
// 
//    Rev 1.4   02 Feb 1994 10:31:36   say
// add GLOBAL szSaveOwner so dbi.c can use it
// 
//    Rev 1.3   03 Jan 1994 16:45:48   say
// add global bShowOwner so dbi.c can unset it when changing active DS
// 
//    Rev 1.3   03 Jan 1994 16:41:22   say
// add global bShowOwner so dbi.c can unset it when changing active DS
// 
//    Rev 1.2   27 Dec 1993 14:40:02   say
// Add global ghnds
// 
//    Rev 1.1   19 Nov 1993 17:39:12   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:11:20   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __ENG_H_

//
// Make a definition for this module.
//
#define __ENG_H_

#include "eng.h"

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
	// from sql.h
// SELECT paramater delimiters - 2 in a row are required for delimiting.
#define LPARAM_CHAR '<'
#define RPARAM_CHAR '>'

//
// Structure Section:
// Place in this section any structure definitions.
//
typedef struct typestring
{
	int dbtype;
	int stringid;
} TYPESTRING;

typedef struct _tokenStruct
{
	LPSTR lpszParam;
	BOOL bUse;
} tokenStruct;

#if 0		// remove globals and prototypes
//
// Global Data Section:
// Place in this section any global data.
//
#if defined _IENGLOG_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

GLOBAL GLOBALHANDLE ghndSavedTableList;	// Saved list of tables, so we don't have to fetch
										// Gets freed and zeroed in ienglog.c if user re-logs in.
GLOBAL GLOBALHANDLE ghndSavedOwnerList;	// Saved list of owners, so we don't have to fetch
										// Gets freed and zeroed in ienglog.c if user re-logs in.
GLOBAL GLOBALHANDLE ghndSavedDatabaseList; // Saved list of databases (SQL Server only), so we don't have to fetch
										// Gets freed and zeroed in ienglog.c if user re-logs in.
GLOBAL BOOL bShowOwner			// Need to share between iengmenu.c and dbi.c
#if defined _IENGLOG_C_
	= TRUE
#endif
;

GLOBAL char szSaveOwner[128];	// shared between iengmenu.c and dbi.c



//
// Function Prototypes Section:
// Place in this section any function prototypes
//
extern int sql_fld_bufB(BOOL bAlloc,int iIgnoreFlds);
extern void sql_addwhere(LPSTR destP, LPSTR sourceP);
#endif		// remove globals and prototypes


#undef GLOBAL
#endif // end __ENG_H_

// *************************** End of File ************************************
