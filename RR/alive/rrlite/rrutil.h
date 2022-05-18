// ****************************************************************************
//
//      (C) Copyright 1996 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
// Utility function prototypes
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/rrutil.h_v  $
// 
//    Rev 1.11   09 May 1997 13:11:32   amh
// More merging to sync-up with Steve's C latest code
// 
//    Rev 1.10   30 Apr 1997 16:47:02   amh
// Merged with Steve C's latest source on 4-30-97
// 
//    Rev 1.9   26 Apr 1997 12:41:28   smh
// Merged Live1.0 Loc changes.
// 
//    Rev 1.8   01 Apr 1997 15:51:58   smh
// latest sources on 4/1/97
// 
//    Rev 1.7   22 Mar 1997 19:05:02   smh
// Sources from 1/24/97
// 
//    Rev 1.6.1.0   25 Apr 1997 14:15:46   smh
// Live 1.0 localization change.
// 
//    Rev 1.6   31 Dec 1996 11:37:04   smh
// Function prototypes for debug code when pdi header bad.
// 
//    Rev 1.5   19 Dec 1996 16:28:18   smh
// Added auto-comment header.
// 
#ifndef H_CAS_RRUTIL
#define H_CAS_RRUTIL 999
#define WINSTRLEN	255

int		convertLangStr( LPTSTR );
//void	displayPrintStatus( HWND, int, LPTSTR );
//void	errorMessage( int );
//LPSTR	loadString( int );
DWORD	ptsToMM( DWORD );
int		rectWidth( LPRECT );
int		rectHeight( LPRECT );
BOOL	strCompareN( LPTSTR, LPTSTR, int );
BOOL	strCompareWideN( LPWSTR, LPWSTR, int );
#ifdef _DEBUG
void	displayDebugError( LPTSTR );
void	dumpBytes( HWND, LPSTR, int );
#endif
#endif