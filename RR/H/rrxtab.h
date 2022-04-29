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
// Global header file for crosstab DLL module
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/rrxtab.h_v  $
// 
//    Rev 1.6   27 Dec 1995 17:38:26   pjm
// Change "handle" to "index" to minimize confusion.
// 
//    Rev 1.5   06 Dec 1995 13:53:18   pjm
// Win32 changes.
// 
//    Rev 1.4   03 Oct 1995 09:10:14   pjm
// Define FLDID (from product.h).
// 
//    Rev 1.3   02 Oct 1995 15:54:34   dlm
// Adjust sizes of stuff in XTAB_INFO in attempt to keep Excel export
//  record sizes the same in 32-bit world as they were in 16-bit world.
// 
//    Rev 1.2   12 Sep 1995 11:34:36   pjm
// MSVC20 changes.
// 
//    Rev 1.1   26 Apr 1995 13:29:26   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.0   16 Mar 1995 16:13:22   sbc
// Initial revision.
// 
//    Rev 1.4   14 Feb 1995 14:18:28   vff
// Fix RRW 2204 to allow RI_EXPDST=D to work
// 
//    Rev 1.3   31 Aug 1994 13:18:50   erp
// No change.
// 
//    Rev 1.2   31 Mar 1994 15:03:32   erp
// added a dirty flag to indicate if we really need to save the export
// information
// 
//    Rev 1.1   11 Mar 1994 15:40:32   erp
// updated with seperate runtime and interactive new entries
// 
//    Rev 1.0   11 Mar 1994 10:01:40   erp
// Initial revision.
// 
//    Rev 1.9   10 Mar 1994 14:16:14   erp
// fixed bug in memory management
// 
//    Rev 1.8   09 Mar 1994 15:29:52   erp
// added BOOL to indicate if printing should happen
// 
//    Rev 1.7   07 Mar 1994 15:25:36   erp
// added output file name override for runtime entry point
// 
//    Rev 1.6   02 Mar 1994 12:22:08   erp
// added some runtime support information
// 
//    Rev 1.5   02 Mar 1994 10:04:44   erp
// fixed up entry point definitions
// 
//    Rev 1.4   01 Mar 1994 12:51:52   erp
// added title string
// 
//    Rev 1.3   28 Feb 1994 14:47:38   erp
// new version for "clean interface"
// 
//    Rev 1.2   25 Feb 1994 13:20:38   erp
// cleaned up interface
// 
//    Rev 1.1   22 Feb 1994 10:02:40   erp
// change xcall.h include to crstabif.h include
// 
//    Rev 1.0   14 Oct 1993 10:11:18   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _RRXTAB_H_
#define _RRXTAB_H_

#define MAX_LIST_SIZE 4 * 1024
#ifndef WINPATHLEN	// to avoid including product.h
 #define WINPATHLEN _MAX_PATH
 #define MAXDNAME 129	// use RSW value
 #define MFFIELDNAMESIZE MAXDNAME+1
#endif
typedef unsigned int FLDID;	// product.h

#include "crstabif.h"

typedef enum tag_RECORD_TYPE
{
	DETAIL_RECORD,
	SUMMARY_RECORD,
	UNDEFINED_RECORD
} RECORD_TYPE;

typedef enum tagEXPORT_TYPE
{
	EXCEL50_XTAB,
	EXCEL50_CHART,
	UNDEFINED
} EXPORT_TYPE;


// DLM changed various ints and BOOLs to shorts in this structure so its size doesn't change as
//  we go to 32-bit land.  Also changed RecordType from RECORD_TYPE to short for same reason.
//  RECORD_TYPE is enumerated and would I think be 32-bits now, which we can't have.  I believe
//  comparisons in code to enumerated-type values should still work properly since they'll all be
//  very small numbers.
typedef struct tagXTAB_INFO
{
	// Save the export info record, which has the set of callbacks from R&R
	EXPORT_INFO 	ExportInfoRecord;
	short index;			// index of saved xtab
	short /*RECORD_TYPE*/ RecordType;
	char szLibraryName		[_MAX_PATH]; // Various file Names
	char szTempExportName 	[_MAX_PATH];
	char szMacroName     	[_MAX_PATH];
	char szTitle		 	[_MAX_PATH];
	char szCommandLine [1024];
	char szTypeStrings [1024];
	
	short iCurrentFieldCol;
	short iNumberOfRows;
	short iNumberOfCols;
	short iNumberOfVals;
	short iNumberOfFieldsExported;
	short TypeArray [100];            // Array to hold the type entry for each value

	short bRuntime;	// indicates if this data is running in the runtime or not.
	short xPrint;	// indicates for the runtime if printing is an option
	// These next two strings are used for the runtime to indicate
	// a specific printer, or an output file name
	char szPrinterName [_MAX_PATH];
	// If the output file is specified, then we will try to save the resulting crosstab
	// in the output file
	char szOutFileName [_MAX_PATH];
	WORD wSizeOfListBuffer; // Large buffer for other data
	char szListBuffer[MAX_LIST_SIZE];
	short bDirty;
} XTAB_INFO;
typedef XTAB_INFO far * LPXTABINFO;

#ifdef _RRXTAB_CPP_
	#define GLOBAL
#else
	#define GLOBAL extern
#endif

#undef GLOBAL


typedef void (FAR PASCAL * EntryFunctionType) (int index, HWND hParentWnd, HINSTANCE hRRInstanceHandle, LPEXPORTINFO XTAB_Info, int iNumberOfExports, LPSTR lpszTitle);
extern void DLLENTRY RREXP_InteractiveEntry  (int index,
											  HWND hParentWnd,
										      HINSTANCE hRRInstanceHandle,
											  LPEXPORTINFO EXPORT_Info,
											  int iNumberOfExports,
											  LPSTR lpszTitle);

typedef void (FAR PASCAL * RuntimeEntryFunctionType) (int index,
													  HWND hParentWnd,
													  HINSTANCE hRRInstanceHandle,
													  LPEXPORTINFO XTAB_Info,
													  int iNumberOfExports,
													  LPSTR lpszTitle,
													  int xPrint,
													  LPSTR lpszPrinterName,
												 	  LPSTR lpszOutputFile);
extern void DLLENTRY RREXP_RuntimeEntry      (int index,
											  HWND hParentWnd,
											  HINSTANCE hRRInstanceHandle,
											  LPEXPORTINFO EXPORT_Info,
											  int iNumberOfExports,
											  LPSTR lpszTitle,
											  int xPrint,
											  LPSTR lpszPrinterName,
										 	  LPSTR lpszOutputFile);

#endif
