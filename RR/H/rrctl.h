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
// Contains all definitions and and prototypes pertinent ONLY
// to the DLL.  API related information is contained in RRWCTL.H.
// API in any way.
//
//
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/rrctl.h_v  $
// 
//    Rev 1.3   13 Sep 1995 08:33:58   pjm
// COmment out references to LPFNSTRTOID and LPFNIDTOSTR.
// 
//    Rev 1.2   13 Sep 1995 08:28:56   pjm
// Define DLLENTRY only if necessary.
// 
//    Rev 1.1   29 Aug 1995 13:25:12   mjs
// win32
// 
//    Rev 1.0   16 Mar 1995 16:13:18   sbc
// Initial revision.
// 
//    Rev 1.4   23 Aug 1994 14:29:48   erp
// removed field list API from here.
// 
//    Rev 1.3   28 Apr 1994 15:17:28   erp
// updated with field list apis
// 
//    Rev 1.2   15 Feb 1994 11:58:48   erp
// place extern "C" since this can be called from C++ code
// 
//    Rev 1.1   23 Nov 1993 11:34:10   erp
// added hscroll routines
// 
//    Rev 1.0   14 Oct 1993 10:10:46   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _RRCTL_H_

//
// Make a definition for this module.
//
#define _RRCTL_H_
#include <custcntl.h>   //Standard Windows header file for custom controls.



//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
#ifndef DLLENTRY
 #define DLLENTRY WINAPI EXPORT
#endif

//Control specific styles.
#define MSS_VERTICAL        0x0001L
#define MSS_HORIZONTAL      0x0002L
#define MSS_NOPEGSCROLL     0x0004L
#define MSS_TEXTHASRANGE    0x0008L
#define MSS_INVERTRANGE     0x0010L



//
// Structure Section:
// Place in this section any structure definitions.
//
//
// Global Data Section:
// Place in this section any global data.
//

//
// Function Prototypes Section:
// Place in this section any function prototypes
//
//
// Standard dialog editor callbacks.
//
// declare as C routines
#ifdef __cplusplus
extern "C"
{
#endif

void   FAR PASCAL WEP(int);
HANDLE FAR PASCAL RRSpinInfo(void);
// Comment the next line out for now.  LPFNSTRTOID doesn't exist in WIN32.
//BOOL   FAR PASCAL RRSpinStyle(HWND, HANDLE, LPFNSTRTOID, LPFNIDTOSTR);
WORD   FAR PASCAL RRSpinFlags(DWORD, LPSTR, WORD);
LONG   FAR PASCAL MicroScrollWndProc(HWND, UINT, WPARAM, LPARAM);
BOOL   FAR PASCAL RRSpinProc(HWND, WORD, WORD, LONG);

//
// Message API Functions
//
HWND     FAR PASCAL MSHwndAssociateSet(HWND hWnd, HWND hWndAssociate);
HWND     FAR PASCAL MSHwndAssociateGet(HWND hWnd);
DWORD    FAR PASCAL MSDwRangeSet(HWND hWnd, WORD iMin, WORD iMax);
DWORD    FAR PASCAL MSDwRangeGet(HWND hWnd);
WORD     FAR PASCAL MSWCurrentPosSet(HWND hWnd, WORD iPos);
WORD     FAR PASCAL MSWCurrentPosGet(HWND hWnd);
BOOL     FAR PASCAL MSFNoPegScrollSet(HWND hWnd, BOOL fNoPegScroll);
BOOL     FAR PASCAL MSFNoPegScrollGet(HWND hWnd);
BOOL     FAR PASCAL MSFInvertRangeSet(HWND hWnd, BOOL fInvertRange);
BOOL     FAR PASCAL MSFInvertRangeGet(HWND hWnd);
COLORREF FAR PASCAL MSCrColorSet(HWND hWnd, WORD iColor, COLORREF cr);
COLORREF FAR PASCAL MSCrColorGet(HWND hWnd, WORD iColor);
/*
 * LISTHAPI.H
 *
 * Include file that prototypes the exported functions that are in the
 * LISTHSCR DLL to support horizontal listbox scrolling.
 *
 */

BOOL FAR PASCAL HSCROLL_InitListboxExtents(HWND);
WORD FAR PASCAL HSCROLL_AddExtentEntry(HWND, LPSTR);
WORD FAR PASCAL HSCROLL_RemoveExtentEntry(HWND, WORD);
BOOL FAR PASCAL HSCROLL_FreeListboxExtents(HWND);
void FAR PASCAL HSCROLL_ResetListboxExtents(HWND);

#ifdef __cplusplus
}
#endif


#endif // end _RRCTL_H_

// *************************** End of File ************************************









