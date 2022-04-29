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
// This module contains the DLL interface to the Concentric Open Data Export (CODE)
// interface. Application (.EXEs) can use this interface as an alternate means
// of accessing the CODE interface. This should make it easier to build application
// using tools such as Visual Basic, Visual C++ (App Wizard), or any other tool which can
// access DLL functions.
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/codedll.h_v  $
// 
//    Rev 1.2   12 Sep 1995 11:35:14   pjm
// MSVC20 changes.
// 
//    Rev 1.1   26 Apr 1995 13:15:58   pjm
// 6.0.03 -> 7.0 merge.
// 
//    Rev 1.4   14 Feb 1995 14:19:06   vff
// Fix RRW 2204 to allow RI_EXPDST=D to work
// 
//    Rev 1.3   18 May 1994 13:33:46   erp
// fixed api for far pointers
// 
//    Rev 1.2   17 May 1994 13:50:20   erp
// update api
// 
//    Rev 1.1   16 May 1994 16:18:32   erp
// added new get/set data api
// 
//    Rev 1.0   13 May 1994 09:13:00   erp
// Initial revision.
// 
//    Rev 1.0   23 Mar 1994 16:05:18   erp
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _CODEDLL_H_
#define _CODEDLL_H_

#ifndef DLLENTRY
#define DLLENTRY WINAPI


#endif

typedef void (DLLENTRY *LPFNCODE_InteractiveEntry)(int Handle, HWND hParentWnd,
								      HINSTANCE hRRInstanceHandle,
									  LPEXPORTINFO lpEXPORT_Info,
									  int iNumberOfExports,
									  LPSTR lpszTitle,
									  LPSTR lpszEXEName);

typedef void (DLLENTRY *LPFNCODE_RuntimeEntry)(int Handle, HWND hParentWnd,
									  HINSTANCE hRRInstanceHandle,
									  LPEXPORTINFO lpEXPORT_Info,
									  int iNumberOfExports,
									  LPSTR lpszTitle,
									  LPSTR lpszEXEName,
									  int xPrint,
									  LPSTR lpszPrinterName,
								 	  LPSTR lpszOutputFile);
								 	  
typedef short (DLLENTRY *LPFNCODE_SetData)(int Handle, WORD  wSize,  void far * lpData);
typedef void (DLLENTRY *LPFNCODE_GetSetDataInfo)(WORD far* wSize, void far * far *lpData);

typedef short (DLLENTRY *LPFNCODE_GetData)(int Handle, WORD* pwSize, void far * lpDataAddress);
typedef void (DLLENTRY *LPFNCODE_SetGetDataInfo)(WORD wSize, void far * lpData);

typedef short (DLLENTRY *LPFNCODE_SetFieldOptions)(int Handle, long lFieldOptions);
typedef short (DLLENTRY *LPFNCODE_GetFirstField)(int Handle, LPSTR lpszAliasBuffer, LPSTR lpszFieldBuffer);

typedef void  (DLLENTRY *LPFNCODE_GetAliasFieldStrings)(int Handle, LPSTR lpszAliasBuffer, LPSTR lpszFieldBuffer);
typedef void  (DLLENTRY *LPFNCODE_SetStrings)(int Handle, LPSTR lpszAliasBuffer, LPSTR lpszFieldBuffer);

typedef short (DLLENTRY *LPFNCODE_GetNextField)(int Handle, LPSTR lpszAliasBuffer, LPSTR lpszFieldBuffer);

typedef short (DLLENTRY *LPFNCODE_SetExportOptions)(int Handle, long lFieldOptions);
typedef short (DLLENTRY *LPFNCODE_SetFirstField)(int Handle, LPSTR lpszAliasBuffer, LPSTR lpszFieldBuffer, long lType);
typedef short (DLLENTRY *LPFNCODE_SetNextField)(int Handle, LPSTR lpszAliasBuffer, LPSTR lpszFieldBuffer, long lType);

typedef short (DLLENTRY *LPFNCODE_SetState)(int Handle, BOOL bSave, BOOL bActive);
typedef void  (DLLENTRY *LPFNCODE_GetSetStateInfo)(BOOL far *bSave, BOOL far *bActive);

typedef short (DLLENTRY *LPFNCODE_SetOutputFile)(int Handle, LPSTR lpszFileName);
typedef short (DLLENTRY *LPFNCODE_SetCommand)(int Handle, LPSTR lpszCommandLine, UINT fuCmdShow);

typedef short (DLLENTRY *LPFNCODE_Export)(int Handle);

typedef short (DLLENTRY *LPFNCODE_GetFieldInfo)(int iInfoBufferSize, LPSTR lpszAlias, LPSTR lpszField, LPSTR lpszInfoBuffer);
typedef void  (DLLENTRY *LPFNCODE_GetStrings)(LPSTR lpszAlias, LPSTR lpszField);



#endif
