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
// This header defines the interface between R&R and external DLLs doing 
// export functions.
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/VCSMFC/H/RRXFLD.H_V  $
// 
//    Rev 1.3   29 Aug 1995 13:24:00   mjs
// Win32 fixes.
// 
//    Rev 1.2   12 Jul 1995 11:03:36   jpb
// move stuff to doc class
// 
//    Rev 1.1   26 Apr 1995 13:13:18   jpb
// merge rrw3 tree to rrw7
// 
//    Rev 1.0   16 Mar 1995 16:13:22   sbc
// Initial revision.
// 
//    Rev 1.18   06 Apr 1995 14:04:58   jpb
// datetime changes from date grep
// 
//    Rev 1.17   10 Feb 1995 09:22:18   vff
// To fix bugs 2191 and 2220, to keep Memo Flds from Crosstabs/Charts
// 
//    Rev 1.16   28 Oct 1994 08:24:34   erp
// fix for RRW bug 1826
// 
//    Rev 1.15   31 Aug 1994 13:15:24   erp
// cleaned up interface
// 
//    Rev 1.14   21 Apr 1994 12:58:58   erp
// added API to return field info
// 
// ****************************************************************************
//
// rrxfld.h
//
// exported public functions for access to field list

#ifndef _RRXFLD_H_
#define _RRXFLD_H_

// These are the declarations for use with the Microsoft C compiler:
#ifdef WIN32
#define rrAPI(rtn_type) rtn_type FAR PASCAL
#else
#define rrAPI(rtn_type) rtn_type __export far pascal
#endif

#define rrSTATUS        short

// Field Option flags 
// 	Field types - can be OR-ed to determined set of field names received
//		Added RRFLD_OK_EXCEL to prevent Memo flds from being exported in
//			PivotTables/Charts, since Excel has a problem with those flds (VFF 2/95)
#define RRFLD_CHARACTER		0x00000001L
#define RRFLD_MEMO			0x00000002L
#define RRFLD_NUMERIC		0x00000004L
#define RRFLD_LOGICAL		0x00000008L
#define RRFLD_DATE			0x00000010L
#define RRFLD_DATETIME		0x00000020L
#define RRFLD_TIME			0x00000040L
#define RRFLD_ALL			0x000000FFL
#define RRFLD_CAN_SUM		(RRFLD_NUMERIC | RRFLD_LOGICAL)
#define RRFLD_OK_EXCEL (RRFLD_ALL ^ RRFLD_MEMO)

// Export Option flags - OR one format and one content flag
//  Export formats - use only one at a time - LSB found is used
#define RREXP_TEXT			0x00000001L
#define RREXP_WKS			0x00000002L
#define RREXP_DBF 			0x00000004L
//  Export content - use only one at a time - LSB found is used
#define RREXP_DETAIL		0x00010000L
#define RREXP_SUMMARY		0x00020000L

// Export Field summary types
#define RRSUM_CNT		0	/* count */
#define RRSUM_SUM		1	/* sum */
#define RRSUM_AVG		2	/* average */
#define RRSUM_MIN		3	/* min */
#define RRSUM_MAX		4	/* max */
#define RRSUM_STD		5	/* standard deviation */
#define RRSUM_VAR		6	/* variance */
#define RRSUM_GROUP_BY	10	/* group-by field */
#define RRSUM_IS_SUM(type) ((type) >=RRSUM_CNT && (type) <= RRSUM_VAR)

	// Error codes
#define rrSUCCESS		0
#define rrENDOFLIST		1
// errors 1 thru 32 represent (returns from WinExec of command) + 1
// (WinExec returns errors of 0 thru 31)
#define rrBADARGS		1001
#define rrOUTOFMEM		1002
#define rrBADSTATE		1003		// not initialized, etc.
#define rrNOTFOUND		1004		// item not found in list
#define rrBADHANDLE		1005




//
// This structure defined the order and location for each of the callback functions
// needed to support export in a DLL.
//
typedef struct tagEXPORT_INFO
{
	FARPROC lpSetFieldOptions;
	FARPROC lpSetExportOptions;
	FARPROC lpGetFirstField;
	FARPROC lpGetNextField;
	FARPROC lpSetFirstField;
	FARPROC lpSetNextField;
	FARPROC lpSetOutputFile;
	FARPROC lpSetCommand;
	FARPROC lpSetOpaqueData;
	FARPROC	lpGetOpaqueData;
	FARPROC lpSetState;
	FARPROC lpDoExport;
	FARPROC lpGetFieldInfo;
} EXPORT_INFO;
#define NUMBER_OF_EXPORTS 13
typedef EXPORT_INFO far * LPEXPORTINFO;

//
// This next section is for the type defs for the function prototypes that are expoarted.
//
typedef rrSTATUS (FAR PASCAL * SetOptionsType) 		(int handle, LONG lFieldOptins);
typedef rrSTATUS (FAR PASCAL * SetStateType) 		(int handle, BOOL bSave, BOOL bActive);
typedef rrSTATUS (FAR PASCAL * GetFieldType) 		(LPSTR lpszAliasBuf, LPSTR lpszFieldBuf, LPSTR lpszFieldAndCommentBuf, LONG far * lData);
typedef rrSTATUS (FAR PASCAL * SetFieldType) 		(int handle, LPSTR lpszAliasBuf, LPSTR lpszFieldBuf, LPSTR lpszFieldAndCommentBuf, LONG lData, LONG lType);
typedef rrSTATUS (FAR PASCAL * SetOutputFileType) 	(int handle, LPSTR lpszFilename);
typedef rrSTATUS (FAR PASCAL * SetCommandType) 		(int handle, LPSTR lpszCommand, BOOL bVisible);
typedef rrSTATUS (FAR PASCAL * SetOpaqueDataType) 	(int handle, WORD wSize, char far *data);
typedef rrSTATUS (FAR PASCAL * GetOpaqueDataType) 	(int handle, WORD far *wSize, char far * far *data);
typedef rrSTATUS (FAR PASCAL * DoExportType) 		(int handle);
typedef rrSTATUS (FAR PASCAL * GetFieldInfoType)    (LPSTR lpszAlias, LPSTR lpszField, LPSTR lpszFieldAndComment, LONG lData, LPSTR lpszInfoBuffer, int iInfoBufferSize);

//
// Here are the actual function prototypes for the functions that will be exported.
//
#if 0
extern rrAPI(rrSTATUS) RREXP_SetFieldOptions 		(int handle, LONG lFieldOptions);
extern rrAPI(rrSTATUS) RREXP_SetExportOptions 		(int handle, LONG lFieldOptions);
extern rrAPI(rrSTATUS) RREXP_SetState 				(int handle, BOOL bSave, BOOL bActive);
extern rrAPI(rrSTATUS) RREXP_GetFirstField			(LPSTR lpszAliasBuf, LPSTR lpszFieldBuf, LPSTR lpszFieldAndCommentBuf, LONG far *lData);
extern rrAPI(rrSTATUS) RREXP_GetNextField			(LPSTR lpszAliasBuf, LPSTR lpszFieldBuf, LPSTR lpszFieldAndCommentBuf, LONG far *lData);
extern rrAPI(rrSTATUS) RREXP_SetFirstField			(int handle, LPSTR lpszAliasBuf, LPSTR lpszFieldBuf, LPSTR lpszFieldAndCommentBuf, LONG lData, LONG lType);
extern rrAPI(rrSTATUS) RREXP_SetNextField			(int handle, LPSTR lpszAliasBuf, LPSTR lpszFieldBuf, LPSTR lpszFieldAndCommentBuf, LONG lData, LONG lType);
extern rrAPI(rrSTATUS) RREXP_SetOutputFile			(int handle, LPSTR lpszFileName); // mandatory
extern rrAPI(rrSTATUS) RREXP_SetCommand 			(int handle, LPSTR lpszCommandLine, BOOL bVisible);
extern rrAPI(rrSTATUS) RREXP_SetOpaqueData 			(int handle, WORD wSize, char far *data);
extern rrAPI(rrSTATUS) RREXP_GetOpaqueData 			(int handle, WORD far *wSize, char far * far *data);
extern rrAPI(rrSTATUS) RREXP_DoExport 				(int handle);
extern rrAPI(rrSTATUS) RREXP_GetFieldInfo 			(LPSTR lpszAlias, LPSTR lpszField, LPSTR lpszFieldAndComment, LONG lData, LPSTR lpszInfoBuffer, int iInfoBufferSize);
#endif


#endif // _RRXFLD_ defined
