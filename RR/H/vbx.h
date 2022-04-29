// ****************************************************************************
//
//		(C) Copyright 1994 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
// vbx.h	 VBX-related structures and definitions
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/vbx.h_v  $
// 
//    Rev 1.0   16 Mar 1995 16:13:48   sbc
// Initial revision.
// 
//    Rev 1.1   30 Nov 1994 15:46:46   mjs
// Set version level to VB100.
// 
//    Rev 1.0   17 Nov 1994 14:09:02   mjs
// Initial revision.
// 
//    Rev 1.4   27 Oct 1994 15:51:02   mjs
// 6.0.16.  Databse, WriteAllow, XbaseEditor
// 
//    Rev 1.3   06 Sep 1994 16:10:24   mjs
// Version 6.0.11.  RepPick, SuppressTitle.
// 
//    Rev 1.2   08 Aug 1994 09:06:14   mjs
// Version 6.0.09, RSW support.
// 
//    Rev 1.1   02 Jun 1994 08:40:30   mjs
// Rel 6.0.08
// 
//    Rev 1.0   26 May 1994 15:17:12   mjs
// Initial revision.

//---------------------------------------------------------------------------
// Resource Information
//---------------------------------------------------------------------------
// Toolbox bitmap resource IDs numbers.
//---------------------------------------------------------------------------
#define IDBMP_UP    8000
#define IDBMP_DOWN  8001
#define IDBMP_MONO  8003
#define IDBMP_EGA   8006

LONG FAR PASCAL _export RRWCtlProc(HCTL, HWND, USHORT, USHORT, LONG);
LONG FAR PASCAL _export RRWPopupWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

// Note that the RRW structure below can be only 256 bytes long!
// This is because the offsetData member of the PROPINFO	struct is a BYTE.
// We have packed some BOOLs and ENUMs into 2 bytes with bit fields to
// save space.  Each HSZ uses 4 bytes.
// That is why we have a limited number of RelatedTables and Parameters.

#define MAXRELS  9
#define MAXPARMS 6
#define MAXSORT  8

// Note:  DON'T EVEN THINK ABOUT MOVING ANY OF THIS STUFF.
// See page 108 of CDK Guide re bit-packing.

typedef struct tagRRW {
	// Eight bit-packed BOOLs at offset 0, LSB->MSB.
	unsigned int		bNoEscape				:1;
	unsigned int		bTestPattern			:1;
	unsigned int		bDisplayError			:1;
	unsigned int		bDisplayStatus			:1;
	unsigned int		bSuppressTitle			:1;
	unsigned int		bWindowMaxButton		:1;
	unsigned int		bWindowMinButton		:1;
	unsigned int		bWindowControlBox		:1;

	// Four bit-packed ENUMs at offset 1, LSB->MSB.
	unsigned int		usWindowBorderStyle 	:2;
	unsigned int		usExportDestination 	:2;
	unsigned int		usQuery				  	:2;
	unsigned int      usReportPick			:2;

	// Two more BOOLs at offset 2, and an ENUM, LSB->MSB.
	// These are RRW only, but will stay here for simplicity.
	unsigned int		bWriteAllow				:1;
	unsigned int		bXbaseEditor			:1;
	unsigned int      usIndexExtension	   :3;
	unsigned int		reserved					:3;

	ENUM		usDestination;
	USHORT	usWindowParentHandle;
	USHORT	usWindowTop;
	USHORT	usWindowLeft;
	USHORT	usWindowHeight;
	USHORT	usWindowWidth;
	USHORT	usCopiesToPrinter;
	USHORT	usStartPage;
	USHORT	usEndPage;
	USHORT  	usLastErrorCode;
	USHORT	usLastErrorPage;
	USHORT	usAction;
   HSZ		hszWindowTitle;
   HSZ		hszPrintFileName;
   HSZ		hszMemoFileName;
   HSZ		hszReportName;
   HSZ		hszReportLibrary;
	HSZ		hszAbout;
	HSZ		hszPrinter;
	HSZ		hszPort;
	HSZ		hszMasterTable;
	HSZ		hszFilter;
	HSZ 		hszRelString;
	HSZ 		hszParmString;
	HSZ 		hszSortString;
	HSZ 		hszGroupString;
	HSZ 		hszDataDirectory;
	HSZ 		hszReportDirectory;
	HSZ 		hszImageDirectory;
	HSZ 		hszLastErrorString;
	HSZ		ParmList[MAXPARMS];
	HSZ		RelList[MAXRELS];
	HSZ		GroupList[MAXSORT];
	HSZ		SortList[MAXSORT];
	HSZ		hszControlFile;
	HSZ		hszStatusFileName;
#if !defined (RSW)
	HSZ		hszMasterIndex;
   HSZ		hszLowScope;
   HSZ		hszHighScope;
	ENUM		usScope;
#else
	HSZ		hszDataSource;
	HSZ		hszPassword;
	HSZ		hszUserName;
	HSZ		hszReplace;
	HSZ		hszWhere;
   HSZ		hszDatabase;
#endif
} RRW, FAR *LPRRW;

#define LprrwDEREF(hctl)     ((LPRRW)VBDerefControl(hctl))
#define OFFSETIN(struc, field)	((USHORT)&( ((struc *)0)->field ))

#if !defined(RSW)
#define CLASS_RRWPOPUP  "RRWPopup"
#else
#define CLASS_RRWPOPUP  "RSWPopup"
#endif

#define CM_OPENRRWDLG 	WM_USER

// Values for the Action property
#define RRW_RUN		1
#define RRW_RUNASYNC	2
#define RRW_WINEXEC  3	   
#define RRW_BUILD		4
#define RRW_DUMP		5

//---------------------------------------------------------------------------
// Property info
//---------------------------------------------------------------------------

// These first 8 BOOLs are packed into the byte at offset 0.

GLOBAL PROPINFO Property_NoEscape 
#if defined _GLOBAL_C_
= {
    "NoEscape",
    DT_BOOL | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    0,
	 0x10, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_TestPattern 
#if defined _GLOBAL_C_
= {
    "TestPattern",
    DT_BOOL | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    0,
	 0x11, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_DisplayError 
#if defined _GLOBAL_C_
= {
    "DisplayError",
    DT_BOOL | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    0,
	 0x12, 1, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_DisplayStatus 
#if defined _GLOBAL_C_
= {
    "DisplayStatus",
    DT_BOOL | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    0,
	 0x13, 1, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_SuppressTitle 
#if defined _GLOBAL_C_
= {
    "SuppressTitle",
    DT_BOOL | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    0,
	 0x14, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_WindowMaxButton 
#if defined _GLOBAL_C_
= {
    "WindowMaxButton",
    DT_BOOL | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    0,
	 0x15, 1, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_WindowMinButton 
#if defined _GLOBAL_C_
= {
    "WindowMinButton",
    DT_BOOL | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    0,
	 0x16, 1, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_WindowControlBox 
#if defined _GLOBAL_C_
= {
    "WindowControlBox",
    DT_BOOL | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    0,
	 0x17, 1, NULL, 0
}
#endif
;

#define ENUM_BORDERS "0 - None\0" "1 - Fixed Single\0" "2 - Sizable\0" "3 - Fixed Double\0"
#define ENUM_DEST		"0 - Saved\0" "1 - Window\0" "2 - Printer\0" "3 - Text File\0" "4 - DBF File\0" "5 - WKS File\0" "6 - Prompt user\0"
#define ENUM_EXPDEST	"0 - Window\0" "1 - Printer\0" "2 - File\0"
#define ENUM_SCOPE  	"0 - Saved\0" "1 - Entire\0" "2 - Override\0"
#define ENUM_QUESTION "3 - Prompt user\0"
#define ENUM_REPPICK	"0 - Pick none\0" "1 - Pick one\0" "2 - Pick many\0"
#define ENUM_INDEXEXT "0 - None\0" "1 - CDX (FoxPro)\0" "2 - IDX (FoxBASE+)\0"	"3 - MDX (dBASE IV)\0" "4 - NDX (dBASE III)\0" "5 - NTX (Clipper)\0" "6 - NSX (SuccessWare)\0" "7 - WDX (Wordtech)\0"


// The next four ENUMs are packed into the byte at offset 1.

GLOBAL PROPINFO Property_WindowBorderStyle 
#if defined _GLOBAL_C_
= {
    "WindowBorderStyle",
    DT_ENUM | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    1,
	 0x30,
	 0,
	 ENUM_BORDERS,
	 4
}
#endif
;

GLOBAL PROPINFO Property_ExportDestination 
#if defined _GLOBAL_C_
= {
    "ExportDestination",
    DT_ENUM | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    1,
	 0x32,
	 0,
	 ENUM_EXPDEST,
	 3
}
#endif
;

GLOBAL PROPINFO Property_Query 
#if defined _GLOBAL_C_
= {
 #if !defined (RSW)
    "Query",
 #else
    "Include",
 #endif
    DT_ENUM | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    1,
	 0x34,
	 0,
	 ENUM_SCOPE ENUM_QUESTION,
	 4
}
#endif
;


GLOBAL PROPINFO Property_ReportPick 
#if defined _GLOBAL_C_
= {
    "ReportPick",
    DT_ENUM | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    1,
	 0x36,
	 0,
	 ENUM_REPPICK,
	 3
}
#endif
;

#if !defined(RSW)
// These next 2 BOOLs are packed into the byte at offset 2.

GLOBAL PROPINFO Property_WriteAllow 
#if defined _GLOBAL_C_
= {
    "WriteAllow",
    DT_BOOL | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    2,
	 0x10, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_XbaseEditor 
#if defined _GLOBAL_C_
= {
    "XbaseEditor",
    DT_BOOL | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    2,
	 0x11, 0, NULL, 0
}
#endif
;

// This ENUM is packed into 3 bits of the byte at offset 2.
GLOBAL PROPINFO Property_IndexExtension
#if defined _GLOBAL_C_
= {
    "IndexExtension",
    DT_ENUM | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    2,
	 0x72,	// 3 bits (a mask of 0x07) starting at bit 0x02
	 0,
	 ENUM_INDEXEXT,
	 8
}
#endif
;

#endif


GLOBAL PROPINFO Property_Destination 
#if defined _GLOBAL_C_
= {
    "Destination",
    DT_ENUM | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
   OFFSETIN(RRW, usDestination),
	0,
	0,
	ENUM_DEST,
	7
}
#endif
;
GLOBAL PROPINFO Property_WindowTop 
#if defined _GLOBAL_C_
= {
    "WindowTop",
    DT_SHORT | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    OFFSETIN(RRW, usWindowTop),
	0, 100, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_WindowLeft 
#if defined _GLOBAL_C_
= {
    "WindowLeft",
    DT_SHORT | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    OFFSETIN(RRW, usWindowLeft),
	0, 100, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_WindowHeight 
#if defined _GLOBAL_C_
= {
    "WindowHeight",
    DT_SHORT | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    OFFSETIN(RRW, usWindowHeight),
	0, 300, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_WindowWidth 
#if defined _GLOBAL_C_
= {
    "WindowWidth",
    DT_SHORT | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    OFFSETIN(RRW, usWindowWidth),
	0, 500, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_CopiesToPrinter 
#if defined _GLOBAL_C_
= {
    "CopiesToPrinter",
    DT_SHORT | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    OFFSETIN(RRW, usCopiesToPrinter),
	0, 1, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_StartPage 
#if defined _GLOBAL_C_
= {
    "StartPage",
    DT_SHORT | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    OFFSETIN(RRW, usStartPage),
	0, 1, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_EndPage 
#if defined _GLOBAL_C_
= {
    "EndPage",
    DT_SHORT | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    OFFSETIN(RRW, usEndPage),
	0, 9999, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_WindowParentHandle 
#if defined _GLOBAL_C_
= {
    "WindowParentHandle",
    DT_SHORT | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fNoShow, 
    OFFSETIN(RRW, usWindowParentHandle),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_LastErrorCode 
#if defined _GLOBAL_C_
= {
    "LastErrorCode",
    DT_SHORT | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fNoShow, 
    OFFSETIN(RRW, usLastErrorCode),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_LastErrorPage 
#if defined _GLOBAL_C_
= {
    "LastErrorPage",
    DT_SHORT | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fNoShow, 
    OFFSETIN(RRW, usLastErrorPage),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_ControlFile
  #if defined _GLOBAL_C_
   = {
    "ControlFile",
#if defined(_DEBUG)
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
#else
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fNoShow,
#endif
    OFFSETIN(RRW, hszControlFile),
	0, 0, NULL, 0
  }
  #endif
;

GLOBAL PROPINFO Property_StatusFileName
  #if defined _GLOBAL_C_
   = {
    "StatusFileName",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszStatusFileName),
	0, 0, NULL, 0
  }
  #endif
;

GLOBAL PROPINFO Property_WindowTitle 
#if defined _GLOBAL_C_
= {
    "WindowTitle",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszWindowTitle),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_DataDirectory 
#if defined _GLOBAL_C_
= {
    "DataDirectory",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fNoShow,
    OFFSETIN(RRW, hszDataDirectory),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_ReportDirectory 
#if defined _GLOBAL_C_
= {
    "ReportDirectory",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fNoShow,
    OFFSETIN(RRW, hszReportDirectory),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_ImageDirectory 
#if defined _GLOBAL_C_
= {
    "ImageDirectory",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fNoShow,
    OFFSETIN(RRW, hszImageDirectory),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_LastErrorString 
#if defined _GLOBAL_C_
= {
    "LastErrorString",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fNoShow,
    OFFSETIN(RRW, hszLastErrorString),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_Filter
#if defined _GLOBAL_C_
= {
    "Filter",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszFilter),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_PrintFileName 
#if defined _GLOBAL_C_
= {
    "PrintFileName",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszPrintFileName),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_MemoFileName 
#if defined _GLOBAL_C_
= {
    "MemoFileName",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszMemoFileName),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_MasterTable 
#if defined _GLOBAL_C_
= {
    "MasterTable",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszMasterTable),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_ReportName 
#if defined _GLOBAL_C_
= {
    "ReportName",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszReportName),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_ReportLibrary 
#if defined _GLOBAL_C_
= {
    "ReportLibrary",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszReportLibrary),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_About 
#if defined _GLOBAL_C_
= {
    "(About)",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData,
    OFFSETIN(RRW, hszAbout),
	0, 0, NULL, 0
}
#endif
;

// This is a dummy property for related tables.
GLOBAL PROPINFO Property_RelString 
#if defined _GLOBAL_C_
= {
    "RelatedTables",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszRelString),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_RelatedTables 
#if defined _GLOBAL_C_
= {
    "RelatedTables",
	 DT_HSZ | PF_fGetMsg | PF_fSetMsg | PF_fPropArray | PF_fNoShow,
    OFFSETIN(RRW, RelList),
	0, 0, NULL, 0
}
#endif
;

// This is a dummy property for Group.
GLOBAL PROPINFO Property_GroupString 
#if defined _GLOBAL_C_
= {
    "GroupFields",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszGroupString),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_GroupFields 
#if defined _GLOBAL_C_
= {
    "GroupFields",
	 DT_HSZ | PF_fGetMsg | PF_fSetMsg | PF_fPropArray | PF_fNoShow,
    OFFSETIN(RRW, GroupList),
	0, 0, NULL, 0
}
#endif
;

// This is a dummy property for Sort.
GLOBAL PROPINFO Property_SortString 
#if defined _GLOBAL_C_
= {
    "SortFields",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszSortString),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_SortFields 
#if defined _GLOBAL_C_
= {
    "SortFields",
	 DT_HSZ | PF_fGetMsg | PF_fSetMsg | PF_fPropArray | PF_fNoShow,
    OFFSETIN(RRW, SortList),
	0, 0, NULL, 0
}
#endif
;

// This is a dummy property for Parameters.
GLOBAL PROPINFO Property_ParmString 
#if defined _GLOBAL_C_
= {
    "Parameters",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszParmString),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_Parameters 
#if defined _GLOBAL_C_
= {
    "Parameters",
    // DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData,
	 DT_HSZ | PF_fGetMsg | PF_fSetMsg | PF_fPropArray | PF_fNoShow,
    OFFSETIN(RRW, ParmList),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_Printer 
#if defined _GLOBAL_C_
= {
    "Printer",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszPrinter),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_Port 
#if defined _GLOBAL_C_
= {
    "Port",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszPort),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_Action 
#if defined _GLOBAL_C_
= {
    "Action",
    DT_SHORT | PF_fGetData | PF_fSetMsg | PF_fNoShow,
    OFFSETIN(RRW, usAction),
	0, 0, NULL, 0
}
#endif
;

#if !defined(RSW)
GLOBAL PROPINFO Property_MasterIndex 
#if defined _GLOBAL_C_
= {
    "MasterIndex",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszMasterIndex),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_Scope 
#if defined _GLOBAL_C_
= {
    "Scope",
    DT_ENUM | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fDefVal, 
    OFFSETIN(RRW, usScope),
	 0,
	 0,
	 ENUM_SCOPE ENUM_QUESTION,
	 4
}
#endif
;

GLOBAL PROPINFO Property_LowScope 
#if defined _GLOBAL_C_
= {
    "LowScope",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszLowScope),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_HighScope 
#if defined _GLOBAL_C_
= {
    "HighScope",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszHighScope),
	0, 0, NULL, 0
}
#endif
;

#else
GLOBAL PROPINFO Property_DataSource 
#if defined _GLOBAL_C_
= {
    "DataSource",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszDataSource),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_Database 
#if defined _GLOBAL_C_
= {
    "Database",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszDatabase),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_Password 
#if defined _GLOBAL_C_
= {
    "Password",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fNoShow,
    OFFSETIN(RRW, hszPassword),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_UserName 
#if defined _GLOBAL_C_
= {
    "UserName",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fNoShow,
    OFFSETIN(RRW, hszUserName),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_Replace 
#if defined _GLOBAL_C_
= {
    "Replace",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszReplace),
	0, 0, NULL, 0
}
#endif
;

GLOBAL PROPINFO Property_Where 
#if defined _GLOBAL_C_
= {
    "Where",
    DT_HSZ | PF_fGetData | PF_fSetData | PF_fSaveData | PF_fEditable,
    OFFSETIN(RRW, hszWhere),
	0, 0, NULL, 0
}
#endif
;
#endif	// RSW


#define IPROP_RRW_CTLNAME		 		0
#define IPROP_RRW_INDEX            	1
#define IPROP_RRW_HELPCONTEXTID     2
#define IPROP_RRW_TAG            	3
#define IPROP_RRW_LEFT           	4
#define IPROP_RRW_TOP            	5
#define IPROP_RRW_NOESCAPE       	6  
#define IPROP_RRW_TESTPATTERN    	7
#define IPROP_RRW_DISPLAYERROR   	8
#define IPROP_RRW_DISPLAYSTATUS  	9
#define IPROP_RRW_WINDOWMAXBUTTON 	10
#define IPROP_RRW_WINDOWMINBUTTON 	11
#define IPROP_RRW_WINDOWCONTROLBOX 	12
#define IPROP_RRW_WINDOWTOP			13
#define IPROP_RRW_WINDOWLEFT     	14
#define IPROP_RRW_WINDOWHEIGHT		15
#define IPROP_RRW_WINDOWWIDTH			16
#define IPROP_RRW_WINDOWBORDERSTYLE 17
#define IPROP_RRW_WINDOWTITLE    	18
#define IPROP_RRW_ACTION         	19
#define IPROP_RRW_COPIESTOPRINTER  	20
#define IPROP_RRW_DESTINATION 	  	21
#define IPROP_RRW_PRINTFILENAME	  	22
#define IPROP_RRW_EXPORTDESTINATION	23
#define IPROP_RRW_REPORTNAME			24
#define IPROP_RRW_REPORTLIBRARY		25
#define IPROP_RRW_ABOUT					26
#define IPROP_RRW_MEMOFILENAME      27
#define IPROP_RRW_STARTPAGE			28
#define IPROP_RRW_ENDPAGE				29
#define IPROP_RRW_PRINTER				30
#define IPROP_RRW_PORT					31
#define IPROP_RRW_MASTERTABLE			32
#define IPROP_RRW_FILTER  33
#define IPROP_RRW_RELATEDTABLES		34
#define IPROP_RRW_RELSTRING			35
#define IPROP_RRW_GROUPFIELDS 36
#define IPROP_RRW_SORTFIELDS			37
#define IPROP_RRW_QUERY					38
#define IPROP_RRW_WINDOWPARENTHANDLE 39
#define IPROP_RRW_PARAMETERS			40
#define IPROP_RRW_DATADIRECTORY		41
#define IPROP_RRW_REPORTDIRECTORY  	42
#define IPROP_RRW_IMAGEDIRECTORY		43
#define IPROP_RRW_LASTERRORCODE		44
#define IPROP_RRW_LASTERRORSTRING   45
#define IPROP_RRW_LASTERRORPAGE		46
#define IPROP_RRW_SUPPRESSTITLE		47
#define IPROP_RRW_PARMSTRING			48
#define IPROP_RRW_SORTSTRING			49
#define IPROP_RRW_GROUPSTRING	 		50
#define IPROP_RRW_CONTROLFILE			51
#define IPROP_RRW_REPORTPICK			52
#define IPROP_RRW_STATUSFILENAME		53
#if !defined(RSW)
#define IPROP_RRW_MASTERINDEX			54
#define IPROP_RRW_SCOPE		      	55
#define IPROP_RRW_LOWSCOPE				56
#define IPROP_RRW_HIGHSCOPE			57
#define IPROP_RRW_WRITEALLOW			58
#define IPROP_RRW_XBASEEDITOR			59
#define IPROP_RRW_INDEXEXTENSION		60
#else
#define IPROP_RRW_DATASOURCE			54
#define IPROP_RRW_PASSWORD				55
#define IPROP_RRW_USERNAME				56
#define IPROP_RRW_REPLACE				57
#define IPROP_RRW_WHERE					58
#define IPROP_RRW_DATABASE				59
#endif

GLOBAL PPROPINFO RRW_Properties[] 
#if defined _GLOBAL_C_
= {
    PPROPINFO_STD_CTLNAME,
    PPROPINFO_STD_INDEX,
    PPROPINFO_STD_HELPCONTEXTID,
    PPROPINFO_STD_TAG,
    PPROPINFO_STD_LEFT,
    PPROPINFO_STD_TOP,
    &Property_NoEscape,
    &Property_TestPattern,
    &Property_DisplayError,
    &Property_DisplayStatus,
    &Property_WindowMaxButton,
    &Property_WindowMinButton,
    &Property_WindowControlBox,
    &Property_WindowTop,
    &Property_WindowLeft,
    &Property_WindowHeight,
    &Property_WindowWidth,
    &Property_WindowBorderStyle,
    &Property_WindowTitle,
    &Property_Action,
    &Property_CopiesToPrinter,
    &Property_Destination,
    &Property_PrintFileName,
    &Property_ExportDestination,
    &Property_ReportName,
    &Property_ReportLibrary,
    &Property_About,
    &Property_MemoFileName,
    &Property_StartPage,
    &Property_EndPage,
    &Property_Printer,
    &Property_Port,
    &Property_MasterTable,
    &Property_Filter,
    &Property_RelatedTables,
    &Property_RelString,
    &Property_GroupFields,
    &Property_SortFields,
    &Property_Query,
	 &Property_WindowParentHandle,
    &Property_Parameters,
    &Property_DataDirectory,
    &Property_ReportDirectory,
    &Property_ImageDirectory,
    &Property_LastErrorCode,
    &Property_LastErrorString,
    &Property_LastErrorPage,
    &Property_SuppressTitle,
    &Property_ParmString,
    &Property_SortString,
    &Property_GroupString,
    &Property_ControlFile,
	 &Property_ReportPick,
	 &Property_StatusFileName,
#if !defined(RSW)
    &Property_MasterIndex,
    &Property_Scope,
    &Property_LowScope,
    &Property_HighScope,
    &Property_WriteAllow,
    &Property_XbaseEditor,
    &Property_IndexExtension,
#else
    &Property_DataSource,
    &Property_Password,
    &Property_UserName,
    &Property_Replace,
    &Property_Where,
    &Property_Database,
#endif
    NULL
}
#endif
;

#define MODEL_FLAGS		MODEL_fInitMsg | MODEL_fLoadMsg

GLOBAL MODEL modelRRW 
#if defined _GLOBAL_C_
= {
    VB100_VERSION, 			  	// VB version being used (11/30/94 Change to V1)
    MODEL_FLAGS,					// MODEL flags
    (PCTLPROC)RRWCtlProc,		// Control procedures
    CS_VREDRAW | CS_HREDRAW,	// Class style
    WS_CHILD | WS_BORDER,		// Default Windows style
    sizeof(RRW),					// Size of RRW structure
    IDBMP_UP,           		// Palette bitmap ID
#if !defined(RSW)
    "Report",	  					// Default control name
    "RRReport",					// Visual Basic class name
#else
    "Report",						// Default control name
    "RSReport",					// Visual Basic class name
#endif
    NULL,							// Parent class name
    RRW_Properties,				// Property information table
    NULL			  					// Event information table
}
#endif
;


