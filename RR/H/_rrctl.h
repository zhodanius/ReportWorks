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
// $Log:   H:/vcsmfc/h/_rrctl.h_v  $
// 
//    Rev 1.0   16 Mar 1995 16:14:52   sbc
// Initial revision.
// 
//    Rev 1.4   13 May 1994 09:10:32   erp
// moved WM_USER message definitions to MSG_DEFS.H
// 
//    Rev 1.3   29 Nov 1993 15:18:30   erp
// added global/extern data definition
// 
//    Rev 1.2   23 Nov 1993 11:34:24   erp
// added hscroll routines
// 
//    Rev 1.1   19 Nov 1993 17:43:02   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:10:46   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __RRCTL_H_

//
// Make a definition for this module.
//
#define __RRCTL_H_

#include "rrctl.h"
#include "msg_defs.h"

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
 
//Notification codes sent via WM_COMMAND from the control.
#define MSN_ASSOCIATEGAIN   1
#define MSN_ASSOCIATELOSS   2
#define MSN_RANGECHANGE     3


//Color indices for MSM_COLORSET/GET and MSCrColorSet/Get
#define MSCOLOR_FACE        0
#define MSCOLOR_ARROW       1
#define MSCOLOR_SHADOW      2
#define MSCOLOR_HIGHLIGHT   3
#define MSCOLOR_FRAME       4

#define CCOLORS             5

#define IDT_FIRSTCLICK      500
#define IDT_HOLDCLICK       501

#define CTICKS_FIRSTCLICK   400
#define CTICKS_HOLDCLICK    50


//Default range and position constants.
#define IDEFAULTMIN         0
#define IDEFAULTMAX         9
#define IDEFAULTPOS         5




//Stringtable identifiers
#define IDS_CLASSNAME           0
#define IDS_FULLNAME            1
#define IDS_CREDITS             2

//Dialog editor interface string
#define IDS_VERTICAL            3
#define IDS_HORIZONTAL          4
#define IDS_MSS_VERTICAL        5
#define IDS_MSS_HORIZONTAL      6
#define IDS_MSS_TEXTHASRANGE    7
#define IDS_MSS_NOPEGSCROLL     8
#define IDS_MSS_INVERTRANGE     9
#define IDS_RANGEERROR          10





/*
 * All that follows in this include file is specific to
 * the dialog editor interface for the MicroScroll control.
 */

//Identifiers for the Style dialog.
#define ID_NULL                 -1
#define ID_IDEDIT               100
#define ID_TEXTEDIT             101
#define ID_RADIOVERTICAL        102
#define ID_RADIOHORIZONTAL      103
#define ID_CHECKTEXTHASRANGE    104
#define ID_CHECKNOPEGSCROLL     105
#define ID_CHECKINVERTRANGE     106



//Dialog box identifiers.
#define IDD_STYLEDIALOG         1
//Offsets to use with GetWindowWord
#define GWW_MUSCROLLHMEM    0

//Extra bytes for the window if the size of a local handle.
#define CBWINDOWEXTRA       sizeof(HANDLE)

//Extra Class bytes.
#define CBCLASSEXTRA        0



//Control state flags.
#define MUSTATE_GRAYED      0x0001
#define MUSTATE_HIDDEN      0x0002
#define MUSTATE_MOUSEOUT    0x0004
#define MUSTATE_UPCLICK     0x0008
#define MUSTATE_DOWNCLICK   0x0010
#define MUSTATE_LEFTCLICK   0x0008  //Repeated since MSS_VERTICAL and
#define MUSTATE_RIGHTCLICK  0x0010  //MSS_HORIZONTAL are exclusive.

//Combination of click states.
#define MUSTATE_CLICKED     (MUSTATE_LEFTCLICK | MUSTATE_RIGHTCLICK)

//Combination of state flags.
#define MUSTATE_ALL         0x001F

/*
 * Macros to change the control state given a PMUSCROLL
 * and state flag(s)
 */
#define StateSet(p, wFlags)    (p->wState |=  (wFlags))
#define StateClear(p, wFlags)  (p->wState &= ~(wFlags))
#define StateTest(p, wFlags)   (p->wState &   (wFlags))


//
// Structure Section:
// Place in this section any structure definitions.
//
/*
 * In window extra bytes we simply store a local handle to
 * a MUSCROLL data structure.  The local memory is allocated
 * from the control's local heap (either application or DLL)
 * instead of from USER's heap, thereby saving system resources.
 *
 * Note that the window styles that are stored in the regular
 * windwow structure are copied here.  This is to optimize access
 * to these bits, avoiding extra calls to GetWindowLong.
 */

typedef struct tagMUSCROLL
    {
    HWND        hWndAssociate;  //Associate window handle
    DWORD       dwStyle;        //Copy of GetWindowLong(hWnd, GWL_STYLE)
    WORD        iMin;           //Minimum position
    WORD        iMax;           //Maximum position
    WORD        iPos;           //Current position
    WORD        wState;         //State flags
    COLORREF    rgCr[CCOLORS];  //Configurable colors.
    } MUSCROLL;

typedef MUSCROLL     *PMUSCROLL;
typedef MUSCROLL FAR *LPMUSCROLL;

#define CBMUSCROLL sizeof(MUSCROLL)


//
// Global Data Section:
// Place in this section any global data.
//
#ifdef _INIT_C_
#define GLOBAL
#else
#define GLOBAL extern
#endif

GLOBAL HANDLE hgInst;


//
// Function Prototypes Section:
// Place in this section any function prototypes
//



//Private functions specific to the control.

//INIT.C
HANDLE FAR PASCAL LibMain(HANDLE, WORD, WORD, LPSTR);
BOOL       PASCAL FRegisterControl(HANDLE);
LONG       PASCAL LMicroScrollCreate(HWND, WORD, PMUSCROLL, LPCREATESTRUCT);
BOOL       PASCAL FTextParse(LPSTR, LPINT, LPINT, LPINT);
WORD       PASCAL WTranslateUpToChar(LPSTR FAR *, char);

//MSAPI.C
LONG       PASCAL LMicroScrollAPI(HWND, WORD, WORD, LONG, PMUSCROLL);


//MUSCROLL.C
void       PASCAL PositionChange(HWND, PMUSCROLL);
void       PASCAL ClickedRectCalc(HWND, PMUSCROLL, LPRECT);


//PAINT.C
LONG       PASCAL LMicroScrollPaint(HWND, PMUSCROLL);
void       PASCAL Draw3DButtonRect(HDC, HPEN, HPEN, WORD, WORD,\
                                   WORD, WORD, BOOL);

/*
 * LISTHSCR.H
 *
 * Private definitions and prototypes for the listhscr DLL.
 */



//Unit of allocation for extent list.
#define CBALLOCUNIT     (sizeof(WORD)<<7)

//Number of units per allocation unit.
#define CALLOCUNITS     128


/*
 * Private prototypes
 */

BOOL HSCROLL_ReAllocExtentList(HANDLE, BOOL);
WORD HSCROLL_GetListboxStringExtent(HWND, LPSTR);
WORD HSCROLL_FindExtentInList(WORD *, WORD, WORD);



#include "rrctl.h"

#endif // end __RRCTL_H_

// *************************** End of File ************************************



