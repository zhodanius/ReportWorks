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
// $Log:   H:/VCSMFC/H/WUTIL.H_V  $
// 
//    Rev 1.6   11 Sep 1995 15:58:28   mjs
// Changed first param to getString to UINT.
// 
//    Rev 1.5   26 Jul 1995 10:59:16   mjs
// Moved all vars and fns to rrdoc (except getString)
// 
//    Rev 1.4   10 Jul 1995 11:57:08   sbc
// Remove buildTermFromPacket prototype
// 
//    Rev 1.3   30 Jun 1995 16:24:22   jpb
// merge rrwin tree rev 1.33
// 
//    Rev 1.2   14 Jun 1995 14:21:10   mjs
// Long fieldnames.
// 
//    Rev 1.1   25 Apr 1995 12:39:50   sbc
// 6.1.03 -> 7.0.01 merge
// 
//    Rev 1.0   16 Mar 1995 16:14:08   sbc
// Initial revision.
// 
//    Rev 1.28   14 Apr 1995 11:18:34   jpb
// add bldIntDateYearControl prototype
// 
//    Rev 1.27   14 Apr 1995 08:17:14   sbc
// New routine prototype
// 
//    Rev 1.26   06 Apr 1995 19:05:46   sjo
// added extern for wintimeshape call for report specs.
// 
//    Rev 1.25   29 Mar 1995 19:41:22   sjo
// changes for international time support.
// 
//    Rev 1.24   10 Mar 1995 12:50:40   smh
// openFileDir -> openDirDialog (more meaningful).
// 
//    Rev 1.23   17 Jan 1995 15:35:00   jpb
// change chevron prototype
// 
//    Rev 1.22   01 Dec 1994 17:23:14   sjo
// Moved truncatepath from mru.cpp to wutil.c, so that other routines can use it
// 
//    Rev 1.21   10 Nov 1994 14:43:08   smh
// Added openCommonFileDir() to select dir from common file dlg.
// 
//    Rev 1.20   20 Sep 1994 15:15:36   smh
// Changed proto of set_Snaked to accept an across value.
// 
//    Rev 1.19   08 Sep 1994 10:13:02   sbc
// New function
// 
//    Rev 1.18   31 Aug 1994 13:14:14   erp
// added function to public api so it could be used by the export code
// 
//    Rev 1.17   18 Jul 1994 10:26:06   sbc
// New function
// 
//    Rev 1.16   11 Jul 1994 13:08:14   sbc
// Remove deleted function prototypes
// 
//    Rev 1.15   20 Jun 1994 10:05:14   smh
// Changed set_Label_PrOpts() prototype to return a BOOL.
// 
//    Rev 1.14   19 Jun 1994 14:45:08   smh
// Avery label constants, structure, routine prototypes for labels.c.
// 
//    Rev 1.13   16 Jun 1994 17:27:12   smh
// Moved avery label stuff here.
// 
//    Rev 1.12   19 May 1994 14:55:04   sbc
// New function for VBX
// 
//    Rev 1.11   11 May 1994 09:25:14   sbc
// Field list changes
// 
//    Rev 1.10   09 May 1994 15:59:38   sbc
// Drag/drop
// 
//    Rev 1.9   06 May 1994 11:15:04   sbc
// function arg change
// 
//    Rev 1.8   21 Mar 1994 13:53:28   dlm
// Added GLOBAL for OFUseTemplate in ABRA-version only.
// 
//    Rev 1.7   08 Feb 1994 16:25:58   mjs
// Only global is hookLink, so tie it to wdialog.c
// 
//    Rev 1.6   31 Jan 1994 14:32:44   unknown
// lowMemoryBox needs LPSTR, not PSTR
// 
//    Rev 1.5   29 Nov 1993 09:27:14   sbc
// Add externs for enableAlign, enableFont, enablePicture (for MFC actually)
// 
//    Rev 1.4   19 Nov 1993 17:41:34   sbc
// Add extern C for C++
// 
//    Rev 1.3   02 Nov 1993 11:01:14   smh
// Moved MAX_MESSAGE here from werror.c - I needed it in runtime.c
// 
//    Rev 1.2   27 Oct 1993 13:24:34   sbc
// Add new getWindowsDates() prototype
// 
//    Rev 1.1   27 Oct 1993 09:25:20   sbc
// Add extern for new globalHeapMin function (WMEM.C)
// 
//    Rev 1.0   14 Oct 1993 10:11:14   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _WUTIL_H_

//
// Make a definition for this module.
//
#define _WUTIL_H_

#include "commdlg.h"
#include "wreport.h" // for COMMENTLEN
#include "mffield.h" // for LPMFFIELD

#if defined(_WDIALOG_C_)  // for hookLink only
#define GLOBAL
#else
#define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
#define MAX_MESSAGE 	512 + 12 // needs to be 512 for Q+E messages
										// plus strlen(WxDBmsgIntro)

#define MAXLABELS		200	// number of labels to alloc memory for
#define LABNAMEMAX	15
#define LABDESCMAX	25		// description (doesn't include width/height info)
#define LABNAMEMEM	LABNAMEMAX * MAXLABELS	
//#define LABDESCMEM	LABDESCMAX * MAXLABELS

//  There can be up to 3 129 character (RSW) field names in a total,
// so I subtracted 3 * 42 (the old field length) from the old 200 to get the 74.
#if defined(RSW)
#define BUILDTOTSIZE (MAXDNAME*3)+74
#else
//	mjs 6/8/95  Above change makes RRW buffer 100 bytes smaller - could be dangerous.
#define BUILDTOTSIZE 200
#endif

// mjs 6/8/95  Put here so callers of fldlist stuff can use it to size their buffers.
// size for field name + long comment + " (Character [123])" + separator slop
#define FLDLISTENTRYSIZE MFFIELDNAMESIZE + COMMENTLEN + 20 + 5

// a unique string so can register a unique message for Select Directory dlg processing
#define UPDATEDIRSTRING "CDS_commondlg_UpdateDirBuf"


//
// Structure Section:
// Place in this section any structure definitions.
//
typedef struct open_file		// File Open common dialog
{
	OPENFILENAME of;
	char szFile[MAXFILESIZE];
	char szFileTitle[MAXTITLESIZE];
	char szFilter[MAXFILTERSIZE];
} OPEN_FILE;

typedef OPEN_FILE FAR *LPOPENFILE;

typedef struct colorstruct	// 16-color table
{
	WORD name_id;		// color string name identifier
	COLORREF rgb;		// red/green/blue value
} COLORS;


// Structure for Avery Label definition (read from INI file)
typedef struct label_definition
{
	char name[LABNAMEMAX+1];
	char descript[LABDESCMAX+1];
	UTWO index;							// array index (not used)
	UONE type;							//  page size (letter, a4, pin, mini, user)
	UTWO labht;							// label height, width
	UTWO labwid;
	UTWO across;						// # across, down
	UTWO down;
	UTWO top;							// top, side margins
	UTWO sides;
	UTWO hpitch;						// record width, height
	UTWO vpitch;
}	LABDEF;

// HOOKPROC is defined as returning an LRESULT
typedef UINT (CALLBACK* UINTPROC)(HWND, UINT, WPARAM, LPARAM);

//
// Global Data Section:
// Place in this section any global data.
//


//
// Function Prototypes Section:
// Place in this section any function prototypes
//

extern LPSTR getString(UINT id,int buf);

#undef GLOBAL
#endif // end _WUTIL_H_

// *************************** End of File ************************************
