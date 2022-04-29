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
// $Log:   D:/R&R Project/archives/H/MSG_DEFS.H_V  $
// 
//    Rev 1.4   04 Oct 2004 10:03:12   Nick
// Futile attempt to fix crash bug
// 
//    Rev 1.3   20 Sep 2004 13:42:12   Nick
// List fields in dialog boxes
// 
//    Rev 1.2   22 Nov 1995 14:23:52   sbc
// Convert insert field dialog to MFC
// 
//    Rev 1.1   15 Sep 1995 14:04:02   pjm
// Removed RRCTL messages.
// 
//    Rev 1.0   16 Mar 1995 16:13:02   sbc
// Initial revision.
// 
//    Rev 1.3   28 Jul 1994 16:33:46   sbc
// New message for wiping insert dialog
// 
//    Rev 1.2   09 Jun 1994 16:17:22   sbc
// New messages
// 
//    Rev 1.1   06 Jun 1994 12:32:26   sbc
// Insert field messages
// 
//    Rev 1.0   13 May 1994 09:11:02   erp
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _MSG_DEFS_H_
#define _MSG_DEFS_H_

//
// These messages are used by the CODE (Concentric Open Data Export) DLL.
//
#define RM_CODE_GETFIRSTFIELD	WM_USER + 15
#define RM_CODE_GETNEXTFIELD	WM_USER + 16

#define RM_CODE_SETFIELDOPTIONS WM_USER + 17
#define RM_CODE_GETFIELDINFO    WM_USER + 18
#define RM_CODE_SETEXPORTOPTIONS WM_USER + 19

#define RM_CODE_SETFIRSTFIELD   WM_USER + 20
#define RM_CODE_SETNEXTFIELD	WM_USER + 21

#define RM_CODE_SETOUTPUTFILE   WM_USER + 22
#define RM_CODE_SETCOMMAND      WM_USER + 23
#define RM_CODE_EXPORT			WM_USER + 24

#define RM_CODE_SETDATA			WM_USER + 25
#define RM_CODE_GETDATA			WM_USER + 26

#define RM_CODE_SETSTATE		WM_USER + 27

//#define	WM_PRIVATE WM_APP
#define	WM_PRIVATE WM_USER

// insert field dialog
#define WM_INS_DLG_REFRESH		WM_PRIVATE + 28
#define WM_INS_DLG_DROP			WM_PRIVATE + 29
//#define WM_INS_DLG_CLOSE		WM_PRIVATE + 30
//
#define WM_EDIT_TEXT_FOCUS		WM_PRIVATE + 31
#define WM_WIZARD_TERMINATE		WM_PRIVATE + 32
#define WM_USER_UPDATE_SORT		WM_PRIVATE + 33
#define WM_USER_UPDATE_PAGE		WM_PRIVATE + 34
#define WM_USER_UPDATE_RECORDS	WM_PRIVATE + 35
#define WM_USER_UPDATE_COPIES	WM_PRIVATE + 36

#define	WM_USER_UPDATE_SELECT	WM_PRIVATE + 37
#endif	// #ifndef _MSG_DEFS_H_
