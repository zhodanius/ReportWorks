// ****************************************************************************
//
//      (C) Copyright 1994 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
//	Global vars for the VBX.
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/VBXGLOB.H_V  $
// 
//    Rev 1.3   Feb 06 2003 19:07:38   Admin
// Increase sizes for some printer variables
// 
//    Rev 1.2   26 Feb 1997 16:31:54   jsf
// fixes RSW 2392, variable PrintType in RRDoc class
// was 41 bytes via constant PTYPESZ, now it is 81. 
// 
//    Rev 1.1   29 Aug 1995 13:25:26   mjs
// win32
// 
//    Rev 1.0   16 Mar 1995 16:13:50   sbc
// Initial revision.
// 
//    Rev 1.0   17 Nov 1994 14:09:26   mjs
// Initial revision.
// 
//    Rev 1.4   27 Oct 1994 15:58:10   mjs
// szDatabase
// 
//    Rev 1.3   06 Sep 1994 16:18:08   mjs
// Version 6.0.11
// 
//    Rev 1.2   08 Aug 1994 09:06:38   mjs
// Version 6.0.09, RSW support.
// 
//    Rev 1.1   02 Jun 1994 08:42:26   mjs
// Rel 6.0.08
// 
//    Rev 1.0   26 May 1994 15:17:54   mjs
// Initial revision.
// 
// ****************************************************************************
//

#if defined _GLOBAL_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

#include "windows.h"
#include "commdlg.h"
#include "vbapi.h"
#include <stdlib.h>
#include <string.h>
#include "vbx.h"

#define WINSTRLEN	255
#define WINPATHLEN		_MAX_PATH	// it's big
#define MAXFILESIZE		WINPATHLEN+1
#define MAXTITLESIZE	WINPATHLEN+1
#define MAXFILTERSIZE	255  // up from 200 for AccuSoft filters
#define FILTERLEN 512		  // Longest calc field.	
#define MAXREPLACE 1024		// Longest User-SQL replace.

// For getDriver()
#define DEVICEMAX	512
#define PDRVSZ		81		// printer driver array
#define PPORTSZ		81		// printer port array
#define PTITLESZ	201		// printer title array
#define PTYPESZ		221		// printer type array


/*  Message from Dave about Alias and Field lengths:
From a look at product.h:
MAXALIAS = 9 (including null)
MAXDNAME = 42 (RSW) or 11 (RRW) (including null, I think)
Separator is "->" for RRW, "." for RSW so the magic numbers would seem to be
	8+2+10+1=21 for RRW, and
	8+1+41+1=51 for RSW,
though you might want to add 1 to each, in case I'm wrong about null
terminators.
*/

#if !defined(RSW)
#define FIELDLEN 10
#define SORTLEN 22
#else
#define FIELDLEN 41
#define SORTLEN 52
#endif
#define FILELEN 128		

#define DLLENTRY int FAR PASCAL EXPORT

typedef struct open_file		// File Open common dialog
{
	OPENFILENAME of;
	char szFile[MAXFILESIZE];
	char szFileTitle[MAXTITLESIZE];
	char szFilter[MAXFILTERSIZE];
} OPEN_FILE;

typedef OPEN_FILE FAR *LPOPENFILE;

#define DNSIZE 32

typedef struct prtdev		// Printer DEVNAMES
{
	DEVNAMES dn;
	char szDriver[DNSIZE];
	char szDevice[DNSIZE];
	char szPort[DNSIZE];
} PRTDEV;

typedef PRTDEV FAR *LPPRTDEV;

#define OFF_DRIVER sizeof(DEVNAMES) 
#define OFF_DEVICE sizeof(DEVNAMES) + DNSIZE
#define OFF_PORT   sizeof(DEVNAMES) + DNSIZE	+ DNSIZE 


/***  Function prototypes  ***/

// From vbx.c
extern VOID PASCAL PaintControl(HWND hwnd);
extern VOID PASCAL SetDefaults(HCTL hctl);
extern HWND NEAR HwndInitRRWPopup(void);
extern void populateRelatedTables(HCTL hctl);
extern void onSize(HWND hwnd);
extern void onDestroy(HCTL hctl);
extern LONG onVbmCreated(HCTL hctl);
extern LONG onGetProperty(HCTL hctl, HWND hwnd, WPARAM wp, LPARAM lp);
extern LONG onSetProperty(HCTL hctl, HWND hwnd, WPARAM wp, LPARAM lp);
extern LONG onInitPropPopup(HCTL hctl, HWND hwnd, USHORT msg, WPARAM wp, LPARAM lp);

// From vbxutil.c
extern BOOL openFileDialog(HWND hWnd,PSTR file,PSTR stdir,int filter_id,PSTR defext,int title_id,WORD help);
extern BOOL FAR PASCAL openFileHook(HWND,WORD,WORD,LONG);
extern BOOL saveAsDialog(HWND hWnd,PSTR file,PSTR stdir,int filter_id,PSTR defext,int title_id);
extern void centerDialog(HWND hDlg);
extern LPSTR getString(WORD id,int buf) ;
extern PSTR getHelpPath(void);
extern BOOL getHsz(HSZ hsz);
extern BOOL freeString(HSZ hsz);
extern BOOL getError(void);

// From vbxarray.c
extern LPSTR getArrayString(LPSTR lpStr);
extern void freeGlobals(void);

// From vbxrels.c
extern LPSTR parseRel(LPSTR lpStr);
extern void populateRelatedTables(HCTL hctl);
extern BOOL CALLBACK relateDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);

// From vbxparm.c
extern LPSTR parseParm(LPSTR lpStr);
extern void populateParameters(HCTL hctl);
extern BOOL CALLBACK parmsDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);

// From vbxsort.c
extern LPSTR parseSort(LPSTR lpStr);
extern LPSTR parseGroup(LPSTR lpStr);
extern void populateSort(HCTL hctl);
extern void populateGroup(HCTL hctl);
extern BOOL CALLBACK sortDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
extern BOOL CALLBACK groupDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);

// From vbxdlg.c
extern BOOL CALLBACK aboutDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
extern BOOL CALLBACK filterDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
extern BOOL changeIndex(HWND hwnd, int title);	 // in vbxdlg.c
extern int getReport(void);
extern void closeReport(void);
extern void parseMIndex(LPSTR lpStr);
#if defined(RSW)
extern BOOL initDataSource(void);
extern BOOL initDatabase(void);
#endif

// From vbxwrite.c
extern void writeDumpFile(HCTL hctl, HWND hwnd);
extern void writeRuninFile(HCTL hctl, HWND hwnd, LPSTR lpCmd);
extern BOOL runReport(HCTL hctl, HWND hwnd, BOOL bWait);

#if defined(RSW)
// From ienglog.c
extern BOOL CALLBACK dataSourceDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
// From vbcreplc.c
extern BOOL CALLBACK replaceDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);

#endif

// GLOBAL VARIABLES

GLOBAL char WxDefKey[] 
#if defined _GLOBAL_C_
 = "Defaults"
#endif
;

GLOBAL char WxDefLibDir[]
#if defined _GLOBAL_C_
 = "LibDir"
#endif
;

GLOBAL char WxDefDataDir[] 
#if defined _GLOBAL_C_
 = "DataDir"
#endif
;

// This is an INI setting we can use to turn on debugging features.
GLOBAL char WxVBXTest[] 
#if defined _GLOBAL_C_
 = "VBXTest"
#endif
;

GLOBAL char WxDBFExt[] 
#if defined _GLOBAL_C_
 = "DBF"
#endif
;

GLOBAL char WxDefIndExt[] 
#if defined _GLOBAL_C_
 = "IndExt"
#endif
;
// These are product-specific.

GLOBAL char WxRRInitFile[]
#if defined _GLOBAL_C_
 #if !defined(RSW)
 ="RRW.INI"
 #else
 ="RSW.INI"
 #endif
#endif
;

GLOBAL char WxLibExt[]
#if defined _GLOBAL_C_
 #if !defined(RSW)
 =	"RP5"
 #else
 =	"RP6"
 #endif
#endif
;

GLOBAL char WxTxtExt[]
#if defined _GLOBAL_C_
 =	"TXT"
#endif
;

GLOBAL char	szAppName[]
#if defined _GLOBAL_C_
 #if !defined(RSW)
  = "RRWVBX"
 #else
  = "RSWVBX"
 #endif
#endif
;

GLOBAL WORD cVBXusers
#if defined _GLOBAL_C_
 = 0
#endif
 ;

GLOBAL BOOL bDevTimeInit
#if defined _GLOBAL_C_
 = FALSE
#endif
 ;

GLOBAL BOOL   fDlgInUse
#if defined _GLOBAL_C_
 = FALSE
#endif
;

GLOBAL char szIndexTypes[4]
#if defined _GLOBAL_C_
 = "NDC"
#endif
;


GLOBAL char FileOpenName[MAXFILESIZE];	// local storage for file open
GLOBAL HINSTANCE HInst;				// our instance
GLOBAL HINSTANCE hResource;		// handle to resource DLL

GLOBAL BOOL GotRep; 					// do we have a report in memory?
GLOBAL OPEN_FILE OpenFileData;	// had a problem with globalAlloc...
GLOBAL LPOPENFILE OpenFileS; 		// pointer to file open structure

GLOBAL DATASTRUCT ds;
GLOBAL LPSTR 		lpProp;

GLOBAL HANDLE  hModDLL;
GLOBAL HBITMAP HBitmap;
GLOBAL HGLOBAL hProp;
HGLOBAL 			hHold;
int	  			nHold;

GLOBAL HCTL    hctlDialog;
GLOBAL HSZ 		hszDialog;
GLOBAL USHORT 	ipropDialog;
GLOBAL USHORT 	hReport;			 	// Handle for getting report stuff

GLOBAL int  	ecode;
GLOBAL LONG 	pageCount;
GLOBAL char 	szErrorMsg[80];

GLOBAL USHORT bmWidth;
GLOBAL USHORT bmHeight;

GLOBAL PSTR	pFile;
GLOBAL int	hTemp;
GLOBAL int  curSel;

GLOBAL LPSTR lpTemp;

GLOBAL LPRRW	lpRRW;
GLOBAL PRINTDLG	pd;
GLOBAL LPDEVNAMES lpDevNames;
GLOBAL LPPRTDEV   lpPrtDev;
GLOBAL FARPROC lpOpenFileHook;

// GLOBAL char szTemp[(FILELEN*2)+(FIELDLEN*2)+4];	 
GLOBAL char szTemp[MAXREPLACE];	// 1024 bytes will handle anything.
GLOBAL char szPath[FILELEN+1];
GLOBAL char szFile[FILELEN+1];
GLOBAL char szAlias[FIELDLEN+1];
GLOBAL char szTag[FIELDLEN+1];
GLOBAL char szType[FIELDLEN+1];
GLOBAL char szIndex[FILELEN+1];
GLOBAL char szReport[32];
GLOBAL char szExt[10];
GLOBAL char szParm[FIELDLEN+1];
GLOBAL char szValue[WINSTRLEN+1];
GLOBAL char szSort[SORTLEN];
GLOBAL char szPrinter[DNSIZE];
GLOBAL char szPort[DNSIZE];

#if defined(RSW)
GLOBAL char szDatabase[32];		// SERVERNAMELEN
#endif


