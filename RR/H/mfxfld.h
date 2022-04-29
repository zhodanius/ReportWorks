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
// $Log:   H:/VCSMFC/H/MFXFLD.H_V  $
// 
//    Rev 1.4   29 Aug 1995 13:24:56   mjs
// win32
// 
//    Rev 1.3   12 Jul 1995 11:03:36   jpb
// move stuff to doc class
// 
//    Rev 1.2   07 Jul 1995 18:11:48   jpb
// First pass at moving all data and functions to CRrDoc class
// 
//    Rev 1.1   28 Jun 1995 16:41:20   smh
// Merged csv/rtf + changes from 6.5.
// 
//    Rev 1.0   16 Mar 1995 16:13:00   sbc
// Initial revision.
// 
//    Rev 1.20   22 Jun 1995 11:33:22   smh
// Some protos for ExportType improvements.
// 
//    Rev 1.19   09 Jun 1995 18:41:42   jpb
// changes for long fieldnames
// 
//    Rev 1.18   28 Oct 1994 08:24:08   erp
// fix for RRW bug 1826
// 
//    Rev 1.17   19 Sep 1994 11:36:12   erp
// increased the size of the field buffer for bug # 1696
// 
//    Rev 1.16   12 Sep 1994 10:06:36   erp
// new function to indicate if an export really occured
// 
//    Rev 1.15   31 Aug 1994 13:17:16   erp
// cleaned up interface
// 
//    Rev 1.14   18 May 1994 13:33:54   erp
// added new api
// 
//    Rev 1.13   16 May 1994 16:18:24   erp
// added new get/set api
// 
//    Rev 1.12   13 May 1994 09:15:38   erp
// added new APIs to call MFXFLD routines from in R&R
// 
//    Rev 1.11   28 Mar 1994 14:27:04   say
// Add proto for existsExportAddon
// 
//    Rev 1.10   16 Mar 1994 10:13:00   erp
// fixed prototype problem
// 
//    Rev 1.9   15 Mar 1994 15:22:46   say
// add resetExport() proto
// 
//    Rev 1.8   09 Mar 1994 13:10:32   say
// add arg to mfxfld.h
// 
//    Rev 1.7   07 Mar 1994 13:59:10   say
// Add argto getFirst/NextExportRecord, remove unused getExportInfo
// 
//    Rev 1.6   07 Mar 1994 11:36:28   say
// make bActive ptr far
// 
//    Rev 1.5   07 Mar 1994 11:05:18   say
// New protos
// 
//    Rev 1.4   05 Mar 1994 18:21:00   say
// Add proto for setOpaqueData
// 
//    Rev 1.3   02 Mar 1994 17:12:00   say
// Add APIs for read and writeRep, remove initExport
// 
//    Rev 1.2   01 Mar 1994 12:00:02   say
// Add EXPFIELD_INFO type
// 
//    Rev 1.1   24 Feb 1994 17:47:16   say
// add initExport prototype
// 
//    Rev 1.0   22 Feb 1994 08:58:22   say
// Initial revision.
// 
// ****************************************************************************
// Structures internal to R&R for public use of the field list
//
// Check to make sure this is not included more than once.
//
#ifndef _MFXFLD_H_
#define _MFXFLD_H_

#include <stdlib.h>
#include "rrxfld.h"
#include "wutil.h"	// for FLDLISTENTRY... param



typedef struct mffield far * LPMFFIELD;	// to avoid mffield.h

#ifndef DLLENTRY
#define DLLENTRY WINAPI EXPORT
#endif

#define MAXEXENTRIES	31 // different types of export

// used to build caller-visible lists for GetFirst/GetNextField
typedef struct tagFIELD_INFO
{
	char szAliasName [16]; 	// 8 is current max size
	char szFieldName [MAXDNAME+90];	// was 100 before made dependent on param (rrw=11)
	char szFieldAndComment [FLDLISTENTRYSIZE];

	LONG lData;
	LPMFFIELD lpMFField;	// read-only
	struct tagFIELD_INFO far * NextField;
} FIELD_INFO;
typedef FIELD_INFO far * LPFIELD_INFO;

// used to build lists of exported fields for SetFirst/SetNextField
typedef struct tagEXPFIELD_INFO
{
	LONG  lExportType;	// summary type/group_by - used only for summary export
	LPMFFIELD lpMFField; // points to original field for detail or group-by fields,
						 // temp total field for summary fields.
	struct tagEXPFIELD_INFO far * NextField;
} EXPFIELD_INFO;
typedef EXPFIELD_INFO far * LPEXPFIELD_INFO;


#define MAXEXTAGLEN 63

typedef struct _exportStuff
{
	char szTypeTag[MAXEXTAGLEN + 1];
	char szDLLName[WINPATHLEN];
	BOOL bSave;	// save it to the report
	BOOL bActive; // it's the currently active export type
	LPSTR lpszCommand;
	BOOL bCommandVisible;

	WORD wOpaqueSize;
	char far* opaqueData;
 
	LONG lFieldOptions;
	LONG lExportOptions;
	LPSTR lpszOutputFile;
} EXPORTSTUFF;

// Function prototypes
#if 0
// These three used by readRep
extern int MFXFLD_ResetExport(void);
extern int MFXFLD_InitExport(LPSTR lpszExpTag, LPSTR lpszDLLName); // also used by export dialog
extern rrSTATUS MFXFLD_SetExportState (int handle, BOOL bActive, BOOL bSave);

// This used only by rpwritex.c (writeRep)
extern BOOL MFXFLD_ExistsExportAddon();

// This internal version of rrexpSetOpaqueData created because prolog for rrAPI
// caused crash.
extern int MFXFLD_SetExportOpaqueData (int handle, WORD wSize, char far *data);

extern int MFXFLD_GetFirstField(LPSTR AliasBuf, LPSTR FieldBuf,LPSTR lpszFieldAndCommentBuf, LONG far * lData);
extern int MFXFLD_GetNextField(LPSTR AliasBuf, LPSTR FieldBuf, LPSTR lpszFieldAndCommentBuf, LONG far * lData);

extern int MFXFLD_SetFieldOptions (int handle, LONG fieldOptions);
extern int MFXFLD_GetFieldInfo (LPSTR lpszAlias, LPSTR lpszField, LPSTR lpszFieldAndCommentBuf, LONG lData, LPSTR lpszInfoBuffer, int iInfoBufferSize);
extern int MFXFLD_SetExportOptions (int handle, LONG lExportOptions);

extern int MFXFLD_SetFirstField(int handle, LPSTR lpszAliasBuf, LPSTR lpszFieldBuf, LPSTR lpszFieldAndCommentBuf, LONG lData, LONG lType);
extern int MFXFLD_SetNextField(int handle, LPSTR lpszAliasBuf, LPSTR lpszFieldBuf, LPSTR lpszFieldAndCommentBuf,LONG lData, LONG lType);

extern int MFXFLD_SetOutputFile(int handle, LPSTR lpszFile); // mandatory
extern int MFXFLD_SetCommand (int handle, LPSTR lpszCommandLine, BOOL bVisible);
extern int MFXFLD_DoExport (int handle);
extern BOOL MFXFLD_WasExported (void);

extern int MFXFLD_SetData (int handle, WORD wSize, char far *data);
extern int MFXFLD_GetData (int handle, WORD far *wSize, char far* far*data);

extern int MFXFLD_SetState (int handle, BOOL bSave, BOOL bActive);

extern BOOL MFXFLD_GetFirstExportRecord(int far *handle, WORD far *bActive, LPSTR far* lpszExpName, // used by writeRep
							LPSTR far *lpszDLLName, 
							char far* far *opaqueData, 
							WORD* opaqueSize,
							BOOL bUnfiltered); // TRUE means "give me the whole list"
                                        // FALSE means "give me only the items marked 'save'"
extern BOOL MFXFLD_GetNextExportRecord(int far *handle, WORD far *bActive, LPSTR far* lpszExpName, // used by writeRep
							LPSTR far *lpszDLLName, 
							char far* far *opaqueData, 
							WORD* opaqueSize,
							BOOL bUnfiltered);
extern LPSTR MFXFLD_GetDLLName(int index);
extern LPSTR MFXFLD_GetExpText(int index);
extern int MFXFLD_findINIExportIndex(LPSTR typestring);
extern LPSTR MFXFLD_findINIExportType(void);
extern void MFXFLD_SetActiveFlag(void);
#endif

#endif // _MFXFLD_ defined
