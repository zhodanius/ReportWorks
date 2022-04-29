#if !defined( _WDWIN95_H_ )
#define _WDWIN95_H_
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*      Copyright (c) 1994 Wall Data Incorporated.  All Rights Reserved.  */
/*--------------------------------------------------------------------------*/
/* This file contains proprietary trade secrets of Wall Data, Incorporated.  */
/* No part of this file may be reproduced or transmitted in any form or by   */
/* any means, electronic or mechanical, including photocopying and        */
/* recording, for any purpose without the expressed written permission    */
/* of Wall Data Incorporated.                                    */
/*--------------------------------------------------------------------------*/
/* Purpose:      Windows95 Header information.                      */
/*--------------------------------------------------------------------------*/
/* Authors:      Patrick D. Jenny                       10/25/94 */
/*--------------------------------------------------------------------------*/
/* Abstract:                                               */
/*                                                         */
/*--------------------------------------------------------------------------*/
/* $Revision:   1.0  $                                          */
/*--------------------------------------------------------------------------*/

//
// Define API decoration for direct importing of DLL references.
//
#ifndef WINCOMMCTRLAPI
#if !defined(_COMCTL32_) && defined(_WIN32)
#define WINCOMMCTRLAPI DECLSPEC_IMPORT
#else
#define WINCOMMCTRLAPI
#endif
#endif // WINCOMMCTRLAPI

/* This is code added for Windows 95 */
#if (WINVER < 0x0400)

#if defined( __cplusplus )
extern "C" {
#endif

//-----------------------------------------------------------------------------
// MMortensen.
// The following section is specific information added by Mark Mortensen for
// W16 and W32 to work properly.  Note that some of the W32 defines should be
// removed once the commctl.lib is updated to contain the imagelist functions.
//
// Added macros to simplify using trackbar.  These are currently not standard
// in the Win95 SDK (don't even exist) so will have to update these if they come out with
// some different macros later. 2/1/95

// Define for both W32 and W16.
#if defined( W16 )

#define LVM_SETVIEW    (LVM_FIRST + 100 ) // Additional messages sent to list view window.
#define ListView_SetView( hListWnd )	\
		SendMessage( hListWnd, LVM_SETVIEW, 0, 0 );
		
#define LVM_ADDICON    (LVM_FIRST + 101 )
#define LVM_REPLACEICON   (LVM_FIRST + 102 )

#define HDS_HIDDEN     0x01
#define HDS_BUTTONS    0x02

#define HDN_ITEMCLICK  ( HDN_FIRST + 1 )

#endif

// Added for Up-Down control.  Documentation has this notification message, but
// not listed below.
#define UDM_DELTAPOS	(WM_USER + 1)


//
// End of MMortensen added section
//-----------------------------------------------------------------------------



/* Users of this header may define any number of these constants to avoid
 * the definitions of each functional group.
 *    NOTOOLBAR    Customizable bitmap-button toolbar control.
 *    NOUPDOWN     Up and Down arrow increment/decrement control.
 *    NOSTATUSBAR  Status bar and header bar controls.
 *    NOMENUHELP   APIs to help manage menus, especially with a status bar.
 *    NOTRACKBAR   Customizable column-width tracking control.
 *    NODRAGLIST   APIs to make a listbox source and sink drag&drop actions.
 *    NOPROGRESS   Progress gas gauge.
 *    NOHOTKEY     HotKey control
 */

/*/////////////////////////////////////////////////////////////////////////*/

/* InitCommonControls:
 * Any application requiring the use of any common control should call this
 * API upon application startup.  There is no required shutdown.
 */
WINCOMMCTRLAPI void WINAPI InitCommonControls();

// Define Ownerdraw type for Header controls BUGBUG: should be in windows.h?
#define ODT_HEADER      100
#define ODT_TAB         101
#define ODT_LISTVIEW    102

//====== Ranges for control message IDs
// (making each control's messages unique makes validation and
// debugging easier).
//
#define LVM_FIRST       0x1000      // ListView messages
#define TV_FIRST        0x1100      // TreeView messages
#define HDM_FIRST       0x1200      // Header messages

#define HANDLE_WM_NOTIFY(hwnd, wParam, lParam, fn) \
    (fn)((hwnd), (int)(wParam), (NMHDR FAR*)(lParam))
#define FORWARD_WM_NOTIFY(hwnd, idFrom, pnmhdr, fn) \
    (void)(fn)((hwnd), WM_NOTIFY, (WPARAM)(int)(idFrom), (LPARAM)(NMHDR FAR*)(pnmhdr))

// Generic WM_NOTIFY notification codes

#define NM_OUTOFMEMORY          (NM_FIRST-1)
#define NM_CLICK                (NM_FIRST-2)
#define NM_DBLCLK               (NM_FIRST-3)
#define NM_RETURN               (NM_FIRST-4)
#define NM_RCLICK               (NM_FIRST-5)
#define NM_RDBLCLK              (NM_FIRST-6)
#define NM_SETFOCUS             (NM_FIRST-7)
#define NM_KILLFOCUS            (NM_FIRST-8)
#define NM_STARTWAIT            (NM_FIRST-9)
#define NM_ENDWAIT              (NM_FIRST-10)
#define NM_BTNCLK               (NM_FIRST-10)

// WM_NOTIFY codes (NMHDR.code values)
// these are not required to be in seperate ranges but that makes
// validation and debugging easier

#define NM_FIRST        (0U-  0U)  // generic to all controls
#define NM_LAST         (0U- 99U)

#define LVN_FIRST       (0U-100U)  // listview
#define LVN_LAST        (0U-199U)

#define HDN_FIRST       (0U-300U)  // header
#define HDN_LAST        (0U-399U)

#define TVN_FIRST       (0U-400U)  // treeview
#define TVN_LAST        (0U-499U)

#define TTN_FIRST   (0U-520U)   // tooltips
#define TTN_LAST (0U-549U)

#define TCN_FIRST       (0U-550U)  // tab control
#define TCN_LAST        (0U-580U)

// Shell reserved       (0U-580U) -  (0U-589U)

#define CDN_FIRST   (0U-601U)   // common dialog (new)
#define CDN_LAST (0U-699U)

#define TBN_FIRST       (0U-700U)  // toolbar
#define TBN_LAST        (0U-720U)

#define UDN_FIRST       (0U-721)   // updown
#define UDN_LAST        (0U-740)   // updown

// Message Filter Proc codes - These are defined above MSGF_USER
#define MSGF_COMMCTRL_BEGINDRAG     0x4200
#define MSGF_COMMCTRL_SIZEHEADER    0x4201
#define MSGF_COMMCTRL_DRAGSELECT    0x4202
#define MSGF_COMMCTRL_TOOLBARCUST   0x4203

//dwhanger,25.1.95,mfc-ing
#if defined( W16 )
typedef struct tagNMHDR                                 //
{                                                       //
    HWND  hwndFrom;                                     //
    UINT  idFrom;                                       //
    UINT  code;                                         //
}   NMHDR;                                              //
typedef NMHDR FAR * LPNMHDR;                            //
#elif defined( W32)	|| defined( WIN32 )
#if !defined( USING_MFC)
typedef struct tagNMHDR                                 //
{                                                       //
    HWND  hwndFrom;                                     //
    UINT  idFrom;                                       //
    UINT  code;                                         //
}   NMHDR;                                              //
typedef NMHDR FAR * LPNMHDR;                            //
#endif
#endif


//====== IMAGE APIS ==================================================

#define CLR_NONE    0xFFFFFFFFL
#define CLR_DEFAULT 0xFF000000L

struct _IMAGELIST;

// MMortensen.  W16 may have slightly different implementations for these functions.
#if defined( W32 ) || defined( WIN32 )
typedef struct _IMAGELIST NEAR* HIMAGELIST;
#else
class ImageList;
typedef ImageList FAR * HIMAGELIST;
#endif

#define ILC_MASK        0x0001      // ImageList has a mask

#define ILC_COLOR       0x00FE      // bitdepth of the image list
#define ILC_COLORDDB    0x00FE      // use device dependent bitmap
#define ILC_COLOR4      0x0004      // use 4bpp DIBSection
#define ILC_COLOR8      0x0008      // use 8bpp DIBSection
#define ILC_COLOR16     0x0010      // use 16bpp DIBSection
#define ILC_COLOR24     0x0018      // use 24bpp DIBSection
#define ILC_COLOR32     0x0020      // use 32bpp DIBSection

#define ILC_PALETTE     0x0800      // use palette with image list


WINCOMMCTRLAPI HIMAGELIST  WINAPI ImageList_Create(int cx, int cy, UINT flags, int cInitial, int cGrow);
WINCOMMCTRLAPI BOOL        WINAPI ImageList_Destroy(HIMAGELIST himl);
WINCOMMCTRLAPI int         WINAPI ImageList_GetImageCount(HIMAGELIST himl);
WINCOMMCTRLAPI int         WINAPI ImageList_ReplaceIcon(HIMAGELIST himl, int i, HICON hicon);
WINCOMMCTRLAPI BOOL        WINAPI ImageList_Remove(HIMAGELIST himl, int i);

WINCOMMCTRLAPI int         WINAPI ImageList_Add(HIMAGELIST himl, HBITMAP hbmImage, HBITMAP hbmMask);
WINCOMMCTRLAPI COLORREF    WINAPI ImageList_SetBkColor(HIMAGELIST himl, COLORREF clrBk);
WINCOMMCTRLAPI COLORREF    WINAPI ImageList_GetBkColor(HIMAGELIST himl);
WINCOMMCTRLAPI BOOL        WINAPI ImageList_SetOverlayImage(HIMAGELIST himl, int iImage, int iOverlay);

#define     ImageList_AddIcon(himl, hicon) ImageList_ReplaceIcon(himl, -1, hicon)

#define ILD_NORMAL      0x0000          // use current bkcolor
#define ILD_TRANSPARENT 0x0001          // force transparent icon style (override bk color)
#define ILD_MASK        0x0010          // draw the mask
#define ILD_IMAGE       0x0020          // draw the image
#define ILD_BLEND       0x000E          // blend with passed color
#define ILD_BLEND25     0x0002          // blend 25%
#define ILD_BLEND50     0x0004          // blend 50%
#define ILD_OVERLAYMASK 0x0F00     // use these as indexes into special items
#define INDEXTOOVERLAYMASK(i) ((i) << 8)    //

#define ILD_SELECTED    ILD_BLEND50     // draw as selected
#define ILD_FOCUS       ILD_BLEND25     // draw as focused (selection)
#define CLR_HILIGHT     CLR_DEFAULT     // draw using default color

WINCOMMCTRLAPI BOOL WINAPI ImageList_Draw(HIMAGELIST himl, int i, HDC hdcDst, int x, int y, UINT fStyle);

#ifdef _WIN32

WINCOMMCTRLAPI BOOL        WINAPI ImageList_Replace(HIMAGELIST himl, int i, HBITMAP hbmImage, HBITMAP hbmMask);
WINCOMMCTRLAPI int         WINAPI ImageList_AddMasked(HIMAGELIST himl, HBITMAP hbmImage, COLORREF crMask);
WINCOMMCTRLAPI BOOL        WINAPI ImageList_DrawEx(HIMAGELIST himl, int i, HDC hdcDst, int x, int y, int dx, int dy, COLORREF rgbBk, COLORREF rgbFg, UINT fStyle);
WINCOMMCTRLAPI HICON       WINAPI ImageList_GetIcon(HIMAGELIST himl, int i, UINT flags);
WINCOMMCTRLAPI HIMAGELIST  WINAPI ImageList_LoadImage(HINSTANCE hi, LPCSTR lpbmp, int cx, int cGrow, COLORREF crMask, UINT uType, UINT uFlags);

WINCOMMCTRLAPI BOOL WINAPI ImageList_BeginDrag(HIMAGELIST himlTrack, int iTrack, int dxHotspot, int dyHotspot);
WINCOMMCTRLAPI void WINAPI ImageList_EndDrag();
WINCOMMCTRLAPI BOOL WINAPI ImageList_DragEnter(HWND hwndLock, int x, int y);
WINCOMMCTRLAPI BOOL WINAPI ImageList_DragLeave(HWND hwndLock);
WINCOMMCTRLAPI BOOL WINAPI ImageList_DragMove(int x, int y);
WINCOMMCTRLAPI BOOL WINAPI ImageList_SetDragCursorImage(HIMAGELIST himlDrag, int iDrag, int dxHotspot, int dyHotspot);

WINCOMMCTRLAPI BOOL WINAPI ImageList_DragShowNolock(BOOL fShow);
WINCOMMCTRLAPI HIMAGELIST WINAPI ImageList_GetDragImage(POINT FAR* ppt,POINT FAR* pptHotspot);

#define     ImageList_RemoveAll(himl) ImageList_Remove(himl, -1)
#define     ImageList_ExtractIcon(hi, himl, i) ImageList_GetIcon(himl, i, 0)
#define     ImageList_LoadBitmap(hi, lpbmp, cx, cGrow, crMask) ImageList_LoadImage(hi, lpbmp, cx, cGrow, crMask, IMAGE_BITMAP, 0)

#ifdef __IStream_INTERFACE_DEFINED__
WINCOMMCTRLAPI HIMAGELIST  WINAPI ImageList_Read(LPSTREAM pstm);
WINCOMMCTRLAPI BOOL        WINAPI ImageList_Write(HIMAGELIST himl, LPSTREAM pstm);
#endif

typedef struct _IMAGEINFO
{
    HBITMAP hbmImage;
    HBITMAP hbmMask;
    int     Unused1;
    int     Unused2;
    RECT    rcImage;
} IMAGEINFO;


WINCOMMCTRLAPI BOOL        WINAPI ImageList_GetIconSize(HIMAGELIST himl, int FAR *cx, int FAR *cy);
WINCOMMCTRLAPI BOOL        WINAPI ImageList_SetIconSize(HIMAGELIST himl, int cx, int cy);
WINCOMMCTRLAPI BOOL        WINAPI ImageList_GetImageInfo(HIMAGELIST himl, int i, IMAGEINFO FAR* pImageInfo);
WINCOMMCTRLAPI HIMAGELIST  WINAPI ImageList_Merge(HIMAGELIST himl1, int i1, HIMAGELIST himl2, int i2, int dx, int dy);

#endif // _WIN32



/*/////////////////////////////////////////////////////////////////////////*/
// slider control

#ifndef NOTRACKBAR
/*
    This control keeps its ranges in LONGs.  but for
    convienence and symetry with scrollbars
    WORD parameters are are used for some messages.
    if you need a range in LONGs don't use any messages
    that pack values into loword/hiword pairs

    The trackbar messages:
    message         wParam  lParam  return

    TBM_GETPOS      ------  ------  Current logical position of trackbar.
    TBM_GETRANGEMIN ------  ------  Current logical minimum position allowed.
    TBM_GETRANGEMAX ------  ------  Current logical maximum position allowed.
    TBM_SETTIC
    TBM_SETPOS
    TBM_SETRANGEMIN
    TBM_SETRANGEMAX
*/

#ifdef WIN32
#define TRACKBAR_CLASS          "msctls_trackbar32"
#else
#define TRACKBAR_CLASS          "wdmsctls_trackbar"
#endif

/* Trackbar styles */

/* add ticks automatically on TBM_SETRANGE message */
#define TBS_AUTOTICKS           0x0001
#define TBS_VERT                0x0002  /* vertical trackbar */
#define TBS_HORZ                0x0000  /* default */
#define TBS_TOP        0x0004  /* Ticks on top */
#define TBS_BOTTOM     0x0000  /* Ticks on bottom  (default) */
#define TBS_LEFT    0x0004  /* Ticks on left */
#define TBS_RIGHT      0x0000  /* Ticks on right (default) */
#define TBS_BOTH    0x0008  /* Ticks on both side */
#define TBS_NOTICKS    0x0010
#define TBS_ENABLESELRANGE   0x0020
#define TBS_FIXEDLENGTH         0x0040  /* specifies that the thumb will be of fixed size */
#define TBS_NOTHUMB             0x0080


/* Trackbar messages */

/* returns current position (LONG) */
#define TBM_GETPOS              (WM_USER)

/* set the min of the range to LPARAM */
#define TBM_GETRANGEMIN         (WM_USER+1)

/* set the max of the range to LPARAM */
#define TBM_GETRANGEMAX         (WM_USER+2)

/* wParam is index of tick to get (ticks are in the range of min - max) */
#define TBM_GETTIC              (WM_USER+3)

/* wParam is index of tick to set */
#define TBM_SETTIC              (WM_USER+4)

/* set the position to the value of lParam (wParam is the redraw flag) */
#define TBM_SETPOS              (WM_USER+5)

/* LOWORD(lParam) = min, HIWORD(lParam) = max, wParam == fRepaint */
#define TBM_SETRANGE            (WM_USER+6)

/* lParam is range min (use this to keep LONG precision on range) */
#define TBM_SETRANGEMIN         (WM_USER+7)

/* lParam is range max (use this to keep LONG precision on range) */
#define TBM_SETRANGEMAX         (WM_USER+8)

/* remove the ticks */
#define TBM_CLEARTICS           (WM_USER+9)

/* select a range LOWORD(lParam) min, HIWORD(lParam) max */
#define TBM_SETSEL              (WM_USER+10)

/* set selection rang (LONG form) */
#define TBM_SETSELSTART         (WM_USER+11)
#define TBM_SETSELEND           (WM_USER+12)

// #define TBM_SETTICTOK           (WM_USER+13)

/* return a pointer to the list of tics (DWORDS) */
#define TBM_GETPTICS            (WM_USER+14)

/* get the pixel position of a given tick */
#define TBM_GETTICPOS           (WM_USER+15)
/* get the number of tics */
#define TBM_GETNUMTICS          (WM_USER+16)

/* get the selection range */
#define TBM_GETSELSTART         (WM_USER+17)
#define TBM_GETSELEND             (WM_USER+18)

/* clear the selection */
#define TBM_CLEARSEL           (WM_USER+19)

/* set tic frequency */
#define TBM_SETTICFREQ    (WM_USER+20)

/* Set/get the page size */
#define TBM_SETPAGESIZE         (WM_USER+21)  // lParam = lPageSize .  Returns old pagesize
#define TBM_GETPAGESIZE         (WM_USER+22)

/* Set/get the line size */
#define TBM_SETLINESIZE         (WM_USER+23)
#define TBM_GETLINESIZE         (WM_USER+24)

/* Get the thumb's and channel's rect size */
#define TBM_GETTHUMBRECT        (WM_USER+25) // lParam = lprc  .  for return value
#define TBM_GETCHANNELRECT      (WM_USER+26) // lParam = lprc  .  for return value

#define TBM_SETTHUMBLENGTH       (WM_USER+27) // wParam = UINT size
#define TBM_GETTHUMBLENGTH       (WM_USER+28)


/*REVIEW: these match the SB_ (scroll bar messages); define them that way? */

#define TB_LINEUP      0
#define TB_LINEDOWN    1
#define TB_PAGEUP      2
#define TB_PAGEDOWN    3
#define TB_THUMBPOSITION  4
#define TB_THUMBTRACK     5
#define TB_TOP         6
#define TB_BOTTOM      7
#define TB_ENDTRACK             8
#endif


/*/////////////////////////////////////////////////////////////////////////*/
// spinner control
#ifndef NOUPDOWN

/*
// OVERVIEW:
//
// The UpDown control is a simple pair of buttons which increment or
// decrement an integer value.  The operation is similar to a vertical
// scrollbar; except that the control only has line-up and line-down
// functionality, and changes the current position automatically.
//
// The control also can be linked with a companion control, usually an
// "edit" control, to simplify dialog-box management.  This companion is
// termed a "buddy" in this documentation.  Any sibling HWND may be
// assigned as the control's buddy, or the control may be allowed to
// choose one automatically.  Once chosen, the UpDown can size itself to
// match the buddy's right or left border, and/or automatically set the
// text of the buddy control to make the current position visible.
//
// ADDITIONAL NOTES:
//
// The "upper" and "lower" limits must not cover a range larger than 32,767
// positions.  It is acceptable to have the range inverted, i.e., to have
// (lower > upper).  The upper button always moves the current position
// towards the "upper" number, and the lower button always moves towards the
// "lower" number.  If the range is zero (lower == upper), or the control
// is disabled (EnableWindow(hCtrl, FALSE)), the control draws grayed
// arrows in both buttons.  The UDS_WRAP style makes the range cyclic; that
// is, the numbers will wrap once one end of the range is reached.
//
// The buddy window must have the same parent as the UpDown control.
//
// If either of the UDS_ALIGN* styles are used, the updown control will
// locate itself on the "inside" of the buddy by resizing the buddy
// accordingly.  so the original size of the buddy will now emcompass
// both a slightly smaller buddy and the updown control.
//
// If the buddy window resizes, and the UDS_ALIGN* styles are used, it
// is necessary to send the UDM_SETBUDDY message to re-anchor the UpDown
// control on the appropriate border of the buddy window.
//
// The UDS_AUTOBUDDY style uses GetWindow(hCtrl, GW_HWNDPREV) to pick
// the best buddy window.  In the case of a DIALOG resource, this will
// choose the previous control listed in the resource script.  If the
// windows will change in Z-order, sending UDM_SETBUDDY with a NULL handle
// will pick a new buddy; otherwise the original auto-buddy choice is
// maintained.
//
// The UDS_SETBUDDYINT style uses its own SetDlgItemInt-style
// functionality to set the caption text of the buddy.  All WIN.INI [Intl]
// values are honored by this routine.
//
// The UDS_ARROWKEYS style will subclass the buddy window, in order to steal
// the VK_UP and VK_DOWN arrow key messages.
//
// The UDS_HORZ sytle will draw the two buttons side by side with
// left and right arrows instead of up and down arrows.  It will also
// send the WM_HSCROLL message instead
//
*/

#ifdef _WIN32
#define UPDOWN_CLASS "msctls_updown32"
#else
#define UPDOWN_CLASS "wdmsctls_updown"
#endif

/* Structures */

typedef struct _UDACCEL {
    UINT nSec;
    UINT nInc;
} UDACCEL, FAR *LPUDACCEL;

#define UD_MAXVAL   0x7fff
#define UD_MINVAL   (-UD_MAXVAL)

/* STYLE BITS */

#define UDS_WRAP    0x0001
#define UDS_SETBUDDYINT      0x0002
#define UDS_ALIGNRIGHT    0x0004
#define UDS_ALIGNLEFT     0x0008
#define UDS_AUTOBUDDY     0x0010
#define UDS_ARROWKEYS     0x0020
#define UDS_HORZ                0x0040
#define UDS_NOTHOUSANDS      0x0080

/* MESSAGES */

#define UDM_SETRANGE      (WM_USER+101)
  /* wParam: not used, 0
  // lParam: short LOWORD, new upper; short HIWORD, new lower limit
  // return: not used
  */

#define UDM_GETRANGE      (WM_USER+102)
  /* wParam: not used, 0
  // lParam: not used, 0
  // return: short LOWORD, upper; short HIWORD, lower limit
  */

#define UDM_SETPOS     (WM_USER+103)
  /* wParam: not used, 0
  // lParam: short LOWORD, new pos; HIWORD not used, 0
  // return: short LOWORD, old pos; HIWORD not used
  */

#define UDM_GETPOS     (WM_USER+104)
  /* wParam: not used, 0
  // lParam: not used, 0
  // return: short LOWORD, current pos; HIWORD not used
  */

#define UDM_SETBUDDY      (WM_USER+105)
  /* wParam: HWND, new buddy
  // lParam: not used, 0
  // return: HWND LOWORD, old buddy; HIWORD not used
  */

#define UDM_GETBUDDY      (WM_USER+106)
  /* wParam: not used, 0
  // lParam: not used, 0
  // return: HWND LOWORD, current buddy; HIWORD not used
  */

#define UDM_SETACCEL      (WM_USER+107)
  /* wParam: UINT, number of acceleration steps
  // lParam: LPUDACCEL, pointer to array of UDACCEL elements
  //         Elements should be sorted in increasing nSec order.
  // return: BOOL LOWORD, nonzero if successful; HIWORD not used
  */

#define UDM_GETACCEL      (WM_USER+108)
  /* wParam: UINT, number of elements in the UDACCEL array
  // lParam: LPUDACCEL, pointer to UDACCEL buffer to receive array
  // return: UINT LOWORD, number of elements returned in buffer
  */

#define UDM_SETBASE    (WM_USER+109)
  /* wParam: UINT, new radix base (10 for decimal, 16 for hex, etc.)
  // lParam: not used, 0
  // return: not used
  */
#define UDM_GETBASE    (WM_USER+110)
  /* wParam: not used, 0
  // lParam: not used, 0
  // return: UINT LOWORD, current radix base; HIWORD not used
  */

/* NOTIFICATIONS */

/* WM_VSCROLL
// Note that unlike a scrollbar, the position is automatically changed by
// the control, and the LOWORD(lParam) is always the new position.  Only
// SB_THUMBTRACK and SB_THUMBPOSITION scroll codes are sent in the wParam.
*/

/* HELPER APIs */
WINCOMMCTRLAPI HWND WINAPI CreateUpDownControl(DWORD dwStyle, int x, int y, int cx, int cy,
                                HWND hParent, int nID, HINSTANCE hInst,
                                HWND hBuddy,
           int nUpper, int nLower, int nPos);
  /* Does the CreateWindow call followed by setting the various
  // state information:
  // hBuddy   The companion control (usually an "edit").
  // nUpper   The range limit corresponding to the upper button.
  // nLower   The range limit corresponding to the lower button.
  // nPos  The initial position.
  // Returns the handle to the control or NULL on failure.
  */

typedef struct _NM_UPDOWN
{
    NMHDR hdr;
    int iPos;
    int iDelta;
} NM_UPDOWN, FAR *LPNM_UPDOWN;

// this will be received Before the WM_VSCROLL notification.
// this gives the parent a chance to bail (return non 0) or change the delta
#define UDN_DELTAPOS (UDN_FIRST - 1)

#endif /* NOUPDOWN */


/*/////////////////////////////////////////////////////////////////////////*/
// progress indicator
#ifndef NOPROGRESS

#ifdef _WIN32
#define PROGRESS_CLASS "msctls_progress32"
#else
#define PROGRESS_CLASS "wdmsctls_progress"
#endif

/*
// OVERVIEW:
//
// The progress bar control is a "gas gauge" that can be used to show the
// progress of a lengthy operation.
//
// The application sets the range and current position (similar to a
// scrollbar) and has the ability to advance the current position in
// a variety of ways.
//
// Text can be displayed in the progress bar as either a percentage
// of the entire range (using the PBS_SHOWPERCENT style) or as the
// value of the current position (using the PBS_SHOWPOS style).  If
// neither bit is set, no text is shown in the bar.
//
// When PBM_STEPIT is used to advance the current position, the gauge
// will wrap when it reaches the end and start again at the start.
// The position is clamped at either end in other cases.
//
*/

/*/////////////////////////////////////////////////////////////////////////*/

/* STYLE BITS */

#define PBS_SHOWPERCENT      0x01  // BUGBUG: not implemented yet
#define PBS_SHOWPOS    0x02  // BUGBUG: not implemented yet

/* MESSAGES */

#define PBM_SETRANGE         (WM_USER+1)
  /* wParam: not used, 0
  // lParam: int LOWORD, bottom of range; int HIWORD top of range
  // return: int LOWORD, previous bottom; int HIWORD old top
  */
#define PBM_SETPOS           (WM_USER+2)
  /* wParam: int new position
  // lParam: not used, 0
  // return: int LOWORD, previous position; HIWORD not used
  */
#define PBM_DELTAPOS         (WM_USER+3)
  /* wParam: int amount to advance current position
  // lParam: not used, 0
  // return: int LOWORD, previous position; HIWORD not used
  */
#define PBM_SETSTEP          (WM_USER+4)
  /* wParam: int new step
  // lParam: not used, 0
  // return: int LOWORD, previous step; HIWORD not used
  */
#define PBM_STEPIT       (WM_USER+5)
        /* advance current position by current step
  // wParam: not used 0
  // lParam: not used, 0
  // return: int LOWORD, previous position; HIWORD not used
  */
#endif /* NOPROGRESS */

#ifndef NOHOTKEY

/*
// OVERVIEW:                        k
//
// The hotkey control is designed as an edit control for hotkey
// entry.  the application supplies a set of control/alt/shift
// combinations that are considered invalid and a default combination
// to be used OR'd with an invalid combination.
//
// Hotkey values are returned as a pair of bytes, one for the
// virtual key code of the key and the other specifying the
// modifier combinations used with the key.
//
*/

// possible modifiers
#define HOTKEYF_SHIFT  0x01
#define HOTKEYF_CONTROL   0x02
#define HOTKEYF_ALT 0x04
#define HOTKEYF_EXT 0x08  // keyboard extended bit

// possible modifier combinations (for defining invalid combos)
#define HKCOMB_NONE 0x0001   // no modifiers
#define HKCOMB_S 0x0002   // only shift
#define HKCOMB_C 0x0004   // only control
#define HKCOMB_A 0x0008   // only alt
#define HKCOMB_SC   0x0010   // shift+control
#define HKCOMB_SA   0x0020   // shift+alt
#define HKCOMB_CA   0x0040   // control+alt
#define HKCOMB_SCA  0x0080   // shift+control+alt

// wHotkey: WORD lobyte, virtual key code
//       WORD hibyte, modifers (combination of HOTKEYF_).

#define HKM_SETHOTKEY         (WM_USER+1)
  /* wParam: wHotkey;
  // lParam: not used, 0
  // return: not used
  */

#define HKM_GETHOTKEY         (WM_USER+2)
  /* wParam: not used, 0
  // lParam: not used, 0
  // return: wHotkey;
  */

#define HKM_SETRULES         (WM_USER+3)
  /* wParam: UINT, invalid modifier combinations (using HKCOMB_*)
  // lParam: UINT loword, default modifier combination (using HOTKEYF_*)
  //         hiword not used
  // return: not used
  */

#ifdef _WIN32
#define HOTKEY_CLASS "msctls_hotkey32"
#else
#define HOTKEY_CLASS "msctls_hotkey"
#endif
#endif /* NOHOTKEY */

/*/////////////////////////////////////////////////////////////////////////*/

/* Note that the following flags are checked every time the window gets a
 * WM_SIZE message, so the style of the window can be changed "on-the-fly".
 * If NORESIZE is set, then the app is responsible for all control placement
 * and sizing.  If NOPARENTALIGN is set, then the app is responsible for
 * placement.  If neither is set, the app just needs to send a WM_SIZE
 * message for the window to be positioned and sized correctly whenever the
 * parent window size changes.
 * Note that for STATUS bars, CCS_BOTTOM is the default, for HEADER bars,
 * CCS_NOMOVEY is the default, and for TOOL bars, CCS_TOP is the default.
 */
#define CCS_TOP        0x00000001L
/* This flag means the status bar should be "top" aligned.  If the
 * NOPARENTALIGN flag is set, then the control keeps the same top, left, and
 * width measurements, but the height is adjusted to the default, otherwise
 * the status bar is positioned at the top of the parent window such that
 * its client area is as wide as the parent window and its client origin is
 * the same as its parent.
 * Similarly, if this flag is not set, the control is bottom-aligned, either
 * with its original rect or its parent rect, depending on the NOPARENTALIGN
 * flag.
 */
#define CCS_NOMOVEY    0x00000002L
/* This flag means the control may be resized and moved horizontally (if the
 * CCS_NORESIZE flag is not set), but it will not move vertically when a
 * WM_SIZE message comes through.
 */
#define CCS_BOTTOM     0x00000003L
/* Same as CCS_TOP, only on the bottom.
 */
#define CCS_NORESIZE      0x00000004L
/* This flag means that the size given when creating or resizing is exact,
 * and the control should not resize itself to the default height or width
 */
#define CCS_NOPARENTALIGN 0x00000008L
/* This flag means that the control should not "snap" to the top or bottom
 * or the parent window, but should keep the same placement it was given
 */
#define CCS_NOHILITE      0x00000010L
/* Don't draw the one pixel highlight at the top of the control
 */
#define CCS_ADJUSTABLE    0x00000020L
/* This allows a toolbar (header bar?) to be configured by the user.
 */
#define CCS_NODIVIDER     0x00000040L
/* Don't draw the 2 pixel highlight at top of control (toolbar)
 */


/*/////////////////////////////////////////////////////////////////////////*/

//================ LISTVIEW APIS ===========================================
//
// Class name: SysListView (WC_LISTVIEW)
//
// The SysListView control provides for a group of items which are displayed
// as a name and/or an associated icon and associated sub-items, in one of
// several organizations, depending on current style settings:
//  * The Icon Format (LVS_ICON)
//      The control arranges standard-sized icons on an invisible grid
//      with their text caption below the icon. The user can drag icons to
//      rearrange them freely, even overlapping each other.
//  * The Small Icon Format (LVS_SMALLICON)
//      The control arranges half-sized icons on an invisible columnar grid
//      like a multi-column owner-draw listbox, with the caption of each
//      item to the icon's right.  The user can still rearrange items
//      freely to taste.  Converting from LVS_ICON to LVS_SMALLICON and back
//      will attempt to preserve approximate relative positions of
//      repositioned items.
//  * The List Format (LVS_LIST)
//      The control enforces a multi-column list of small-icon items with
//      each item's caption to the right.  No free rearranging is possible.
//  * The Report Format (LVS_REPORT)
//      The control enforces a single-column list of small-icon items with
//      each item's caption to the right, and further columns used for item-
//      specific sub-item text.  The columns are capped with a SysHeader
//      bar (unless specified) which allows the user to change the relative
//      widths of each sub-item column.
//
// The icons and small-icons presented may be assigned as indices into
// an ImageList of the appropriate size.  These ImageLists (either custom
// lists or copies of the system lists) are assigned to the control by the
// owner at initialization time or at any later time.
//
// Text and icon values may be "late-bound," or assigned by a callback
// routine as required by the control.  For example, if it would be slow to
// compute the correct icon or caption for an item, the item can be assigned
// special values which indicate that they should be computed only as the
// items become visible (say, for a long list of items being scrolled into
// view).
//
// Each item has a state, which can be (nearly) any combination of the
// following attributes, mostly managed automatically by the control:
//  * Selected (LVIS_SELECTED)
//      The item appears selected.  The appearance of selected items
//      depends on whether the control has the focus, and the selection
//      system colors.
//  * Focused (LVIS_FOCUSED)
//      One item at a time may be focused.  The item is surrounded with a
//      standard focus-rectangle.
//  * Marked (LVIS_CUT)
//      REVIEW: Call this "Checked"?
//  * Disabled (LVIS_DISABLED)
//      The item is drawn with the standard disabled style and coloring.
//  * Drop-Highlighted (LVIS_DROPHILITED)
//      The item appears marked when the user drags an object over it, if
//      it can accept the object as a drop-target.
//  * Link/Alias/Shortcut (LVIS_LINK)
//      The item's text has a standard link-indicator appended (Foo >>).
//
// There are notifications that allow applications to determine when an item
// has been clicked or double clicked, caption text changes have occured,
// drag tracking is occuring, widths of columns have changed, etc.
//
//////////////////////////////////////////////////////////////////////////////


#if defined( _WIN32 ) || defined( W32 )
#define WC_LISTVIEW         "SysListView32"
#else
#define WC_LISTVIEW         "SysListView"
#endif

// ListView styles
//
// view type styles (we only have 16 bits to use here)
#define LVS_ICON            0x0000
#define LVS_REPORT          0x0001
#define LVS_SMALLICON       0x0002
#define LVS_LIST            0x0003
#define LVS_TYPEMASK        0x0003

// shared styles
#define LVS_SINGLESEL       0x0004
#define LVS_SHOWSELALWAYS   0x0008
#define LVS_SORTASCENDING   0x0010
#define LVS_SORTDESCENDING  0x0020
#define LVS_SHAREIMAGELISTS 0x0040

#define LVS_NOLABELWRAP     0x0080
#define LVS_AUTOARRANGE     0x0100
#define LVS_EDITLABELS      0x0200

#define LVS_NOSCROLL        0x2000

/// the fields below are reserved for style specific settings.
#define LVS_TYPESTYLEMASK   0xfc00     // the mask for all these styles

// Large icon.
#define LVS_ALIGNTOP        0x0000
#define LVS_ALIGNLEFT       0x0800
#define LVS_ALIGNMASK       0x0c00

// Report view.
#define LVS_OWNERDRAWFIXED  0x0400
#define LVS_NOCOLUMNHEADER  0x4000
#define LVS_NOSORTHEADER    0x8000

// COLORREF ListView_GetBkColor(HWND hwnd);
#define LVM_GETBKCOLOR      (LVM_FIRST + 0)
#define ListView_GetBkColor(hwnd)  \
    (COLORREF)SendMessage((hwnd), LVM_GETBKCOLOR, 0, 0L)

// BOOL ListView_SetBkColor(HWND hwnd, COLORREF clrBk);
#define LVM_SETBKCOLOR      (LVM_FIRST + 1)
#define ListView_SetBkColor(hwnd, clrBk) \
    (BOOL)SendMessage((hwnd), LVM_SETBKCOLOR, 0, (LPARAM)(COLORREF)(clrBk))

// HIMAGELIST ListView_GetImageList(HWND hwnd, int iImageList);
#define LVM_GETIMAGELIST    (LVM_FIRST + 2)
#define ListView_GetImageList(hwnd, iImageList) \
    (HIMAGELIST)SendMessage((hwnd), LVM_GETIMAGELIST, (WPARAM)(int)(iImageList), 0L)

#define LVSIL_NORMAL   0
#define LVSIL_SMALL 1
#define LVSIL_STATE 2

// HIMAGELIST ListView_SetImageList(HWND hwnd, HIMAGELIST himl, int iImageList);
#define LVM_SETIMAGELIST    (LVM_FIRST + 3)
// MMortensen.
#if defined( W32 )
#define ListView_SetImageList(hwnd, himl, iImageList) \
    (HIMAGELIST)(UINT)SendMessage((hwnd), LVM_SETIMAGELIST, (WPARAM)(iImageList), (LPARAM)(UINT)(HIMAGELIST)(himl))
#else
#define ListView_SetImageList(hwnd, himl, iImageList) \
    (UINT)SendMessage((hwnd), LVM_SETIMAGELIST, (WPARAM)(iImageList), (LPARAM)(himl))
#endif

// int ListView_GetItemCount(HWND hwnd);
#define LVM_GETITEMCOUNT    (LVM_FIRST + 4)
#define ListView_GetItemCount(hwnd) \
    (int)SendMessage((hwnd), LVM_GETITEMCOUNT, 0, 0L)

// ListView Item structure

#define LVIF_TEXT           0x0001  // LV_ITEM.mask flags (indicate valid fields in LV_ITEM)
#define LVIF_IMAGE          0x0002
#define LVIF_PARAM          0x0004
#define LVIF_STATE          0x0008
#define LVIF_ALL       0x0010

// State flags
#define LVIS_FOCUSED       0x0001  // LV_ITEM.state flags
#define LVIS_SELECTED       0x0002
#define LVIS_CUT            0x0004  // LVIS_MARKED
#define LVIS_DROPHILITED    0x0008
#define LVIS_LINK           0x0040

#define LVIS_OVERLAYMASK    0x0F00  // used as ImageList overlay image indexes
#define LVIS_STATEIMAGEMASK 0xF000 // client bits for state image drawing
#define LVIS_USERMASK       LVIS_STATEIMAGEMASK  // BUGBUG: remove me.

#define INDEXTOSTATEIMAGEMASK(i) ((i) << 12)

typedef struct _LV_ITEM
{
    UINT mask;      // LVIF_ flags
    int iItem;
    int iSubItem;
    UINT state;     // LVIS_ flags
    UINT stateMask; // LVIS_ flags (valid bits in state)
    LPSTR pszText;
    int cchTextMax;
    int iImage;
    LPARAM lParam;
} LV_ITEM, FAR * LPLV_ITEM;

    // Values used to cause text/image GETDISPINFO callbacks
#define LPSTR_TEXTCALLBACK      ((LPSTR)-1L)
#define I_IMAGECALLBACK         (-1)

// BOOL ListView_GetItem(HWND hwnd, LV_ITEM FAR* pitem);
#define LVM_GETITEM         (LVM_FIRST + 5)
#define ListView_GetItem(hwnd, pitem) \
    (BOOL)SendMessage((hwnd), LVM_GETITEM, 0, (LPARAM)(LV_ITEM FAR*)(pitem))

// Sets items and subitems.
//
// BOOL ListView_SetItem(HWND hwnd, const LV_ITEM FAR* pitem);
#define LVM_SETITEM         (LVM_FIRST + 6)
#define ListView_SetItem(hwnd, pitem) \
    (BOOL)SendMessage((hwnd), LVM_SETITEM, 0, (LPARAM)(const LV_ITEM FAR*)(pitem))

// int ListView_InsertItem(HWND hwnd, const LV_ITEM FAR* pitem);
#define LVM_INSERTITEM         (LVM_FIRST + 7)
#define ListView_InsertItem(hwnd, pitem)   \
    (int)SendMessage((hwnd), LVM_INSERTITEM, 0, (LPARAM)(const LV_ITEM FAR*)(pitem))

// Deletes the specified item along with all its subitems.
//
// BOOL ListView_DeleteItem(HWND hwnd, int i);
#define LVM_DELETEITEM      (LVM_FIRST + 8)
#define ListView_DeleteItem(hwnd, i) \
    (BOOL)SendMessage((hwnd), LVM_DELETEITEM, (WPARAM)(int)(i), 0L)

// BOOL ListView_DeleteAllItems(HWND hwnd);
#define LVM_DELETEALLITEMS  (LVM_FIRST + 9)
#define ListView_DeleteAllItems(hwnd) \
    (BOOL)SendMessage((hwnd), LVM_DELETEALLITEMS, 0, 0L)

// UINT ListView_GetCallbackMask(HWND hwnd);
#define LVM_GETCALLBACKMASK (LVM_FIRST + 10)
#define ListView_GetCallbackMask(hwnd) \
    (BOOL)SendMessage((hwnd), LVM_GETCALLBACKMASK, 0, 0)

// BOOL ListView_SetCallbackMask(HWND hwnd, UINT mask);
#define LVM_SETCALLBACKMASK (LVM_FIRST + 11)
#define ListView_SetCallbackMask(hwnd, mask) \
    (BOOL)SendMessage((hwnd), LVM_SETCALLBACKMASK, (WPARAM)(UINT)(mask), 0)

// ListView_GetNextItem flags (can be used in combination)
#define LVNI_ALL    0x0000
#define LVNI_FOCUSED      0x0001  // return only focused item
#define LVNI_SELECTED     0x0002  // return only selected items
#define LVNI_CUT       0x0004  // return only marked items
#define LVNI_DROPHILITED  0x0008 // return only drophilited items
#define LVNI_PREVIOUS     0x0020  // Go backwards

#define LVNI_ABOVE        0x0100  // return item geometrically above
#define LVNI_BELOW        0x0200  // "" below
#define LVNI_TOLEFT       0x0400  // "" to left
#define LVNI_TORIGHT      0x0800  // "" to right (NOTE: these four are
                                   //              mutually exclusive, but
                                   //              can be used with other LVNI's)

// int ListView_GetNextItem(HWND hwnd, int i, UINT flags);
#define LVM_GETNEXTITEM     (LVM_FIRST + 12)
#define ListView_GetNextItem(hwnd, i, flags) \
    (int)SendMessage((hwnd), LVM_GETNEXTITEM, (WPARAM)(int)(i), MAKELPARAM((flags), 0))

// ListView_FindInfo definitions
#define LVFI_PARAM      0x0001
#define LVFI_STRING     0x0002
#define LVFI_PARTIAL    0x0008
#define LVFI_WRAP       0x0020
#define LVFI_NEARESTXY  0x0040

typedef struct _LV_FINDINFO
{
    UINT flags;
    LPCSTR psz;
    LPARAM lParam;

    POINT pt;  //  only used for nearestxy
    UINT vkDirection; //  only used for nearestxy
} LV_FINDINFO;

// int ListView_FindItem(HWND hwnd, int iStart, const LV_FINDINFO FAR* plvfi);
#define LVM_FINDITEM        (LVM_FIRST + 13)
#define ListView_FindItem(hwnd, iStart, plvfi) \
    (int)SendMessage((hwnd), LVM_FINDITEM, (WPARAM)(int)(iStart), (LPARAM)(const LV_FINDINFO FAR*)(plvfi))


#define LVIR_BOUNDS     0
#define LVIR_ICON       1
#define LVIR_LABEL      2
#define LVIR_SELECTBOUNDS 3


    // Rectangle bounding all or part of item, based on LVIR_* code.  Rect is returned in view coords
    // BOOL ListView_GetItemRect(HWND hwndLV, int i, RECT FAR* prc, int code);
#define LVM_GETITEMRECT     (LVM_FIRST + 14)
#define ListView_GetItemRect(hwnd, i, prc, code) \
    ((prc)->left = (code), (BOOL)SendMessage((hwnd), LVM_GETITEMRECT, (WPARAM)(int)(i), (LPARAM)(RECT FAR*)(prc)))

    // Move top-left corner of item to (x, y), specified in view rect relative coords
    // (icon and small view only)

// BOOL ListView_SetItemPosition(HWND hwndLV, int i, int x, int y);
#define LVM_SETITEMPOSITION (LVM_FIRST + 15)
#define ListView_SetItemPosition(hwndLV, i, x, y) \
    (BOOL)SendMessage((hwndLV), LVM_SETITEMPOSITION, (WPARAM)(int)(i), MAKELPARAM((x), (y)))

// BOOL ListView_GetItemPosition(HWND hwndLV, int i, POINT FAR* ppt);
#define LVM_GETITEMPOSITION (LVM_FIRST + 16)
#define ListView_GetItemPosition(hwndLV, i, ppt) \
    (BOOL)SendMessage((hwndLV), LVM_GETITEMPOSITION, (WPARAM)(int)(i), (LPARAM)(POINT FAR*)(ppt))

    // Get column width of string
    // int ListView_GetStringWidth(HWND hwndLV, LPCSTR psz);
#define LVM_GETSTRINGWIDTH  (LVM_FIRST + 17)
#define ListView_GetStringWidth(hwndLV, psz) \
    (int)SendMessage((hwndLV), LVM_GETSTRINGWIDTH, 0, (LPARAM)(LPCSTR)(psz))

    // Hit test item.  Returns item at (x,y), or -1 if not on an item.
    // Combination of LVHT_ values *pflags, indicating where the cursor
    // is relative to edges of ListView window (above, below, right, left)
    // or whether (x, y) is over icon, label, or inside window but not on item.
    // int ListView_HitTest(HWND hwndLV, LV_HITTESTINFO FAR* pinfo);

    // ItemHitTest flag values
#define LVHT_NOWHERE        0x0001
#define LVHT_ONITEMICON     0x0002
#define LVHT_ONITEMLABEL    0x0004
#define LVHT_ONITEMSTATEICON 0x0008
#define LVHT_ONITEM         (LVHT_ONITEMICON | LVHT_ONITEMLABEL | LVHT_ONITEMSTATEICON)

#define LVHT_ABOVE          0x0008
#define LVHT_BELOW          0x0010
#define LVHT_TORIGHT        0x0020
#define LVHT_TOLEFT         0x0040

typedef struct _LV_HITTESTINFO
{
    POINT pt;     // in:  client coords
    UINT flags;      // out: LVHT_ flags
    int iItem;       // out: item
} LV_HITTESTINFO;

    // int ListView_HitTest(HWND hwndLV, LV_HITTESTINFO FAR* pinfo);
#define LVM_HITTEST     (LVM_FIRST + 18)
#define ListView_HitTest(hwndLV, pinfo) \
    (int)SendMessage((hwndLV), LVM_HITTEST, 0, (LPARAM)(LV_HITTESTINFO FAR*)(pinfo))

    // Return view rectangle, relative to window
    // BOOL ListView_GetViewRect(HWND hwndLV, RECT FAR* prcVis);
    // Scroll an item into view if not wholly or partially visible
    // BOOL ListView_EnsureVisible(HWND hwndLV, int i, BOOL fPartialOK);
#define LVM_ENSUREVISIBLE   (LVM_FIRST + 19)
#define ListView_EnsureVisible(hwndLV, i, fPartialOK) \
    (BOOL)SendMessage((hwndLV), LVM_ENSUREVISIBLE, (WPARAM)(int)(i), MAKELPARAM((fPartialOK), 0))

    // Scroll listview -- offsets origin of view rectangle by dx, dy
    // BOOL ListView_Scroll(HWND hwndLV, int dx, int dy);
#define LVM_SCROLL          (LVM_FIRST + 20)
#define ListView_Scroll(hwndLV, dx, dy) \
    (BOOL)SendMessage((hwndLV), LVM_SCROLL, (WPARAM)(int)dx, (LPARAM)(int)dy)

    // Force eventual redraw of range of items (redraw doesn't occur
    // until WM_PAINT processed -- call UpdateWindow() after to redraw right away)
    // BOOL ListView_RedrawItems(HWND hwndLV, int iFirst, int iLast);
#define LVM_REDRAWITEMS     (LVM_FIRST + 21)
#define ListView_RedrawItems(hwndLV, iFirst, iLast) \
    (BOOL)SendMessage((hwndLV), LVM_REDRAWITEMS, (WPARAM)(int)iFirst, (LPARAM)(int)iLast)

    // Arrange style
#define LVA_DEFAULT         0x0000
#define LVA_ALIGNLEFT       0x0001
#define LVA_ALIGNTOP        0x0002
#define LVA_ALIGNRIGHT      0x0003
#define LVA_ALIGNBOTTOM     0x0004
#define LVA_SNAPTOGRID      0x0005

#define LVA_SORTASCENDING   0x0100  // can be used in combo with above LVA_* values
#define LVA_SORTDESCENDING  0x0200  // ""

    // Arrange icons according to LVA_* code
    // BOOL ListView_Arrange(HWND hwndLV, UINT code);
#define LVM_ARRANGE         (LVM_FIRST + 22)
#define ListView_Arrange(hwndLV, code) \
    (BOOL)SendMessage((hwndLV), LVM_ARRANGE, (WPARAM)(UINT)(code), 0L)

    // Begin editing the label of a control.  Implicitly selects and focuses
    // item.  Send WM_CANCELMODE to cancel.
    // HWND ListView_EditLabel(HWND hwndLV, int i);
#define LVM_EDITLABEL       (LVM_FIRST + 23)
#define ListView_EditLabel(hwndLV, i) \
    (HWND)SendMessage((hwndLV), LVM_EDITLABEL, (WPARAM)(int)(i), 0L)

    // Return edit control being used for editing.  Subclass OK, but
    // don't destroy.  Will be destroyed when editing is finished.
    //HWND ListView_GetEditControl(HWND hwndLV);
#define LVM_GETEDITCONTROL  (LVM_FIRST + 24)
#define ListView_GetEditControl(hwndLV) \
    (HWND)SendMessage((hwndLV), LVM_GETEDITCONTROL, 0, 0L)

typedef struct _LV_COLUMN
{
    UINT mask;
    int fmt;
    int cx;
    LPSTR pszText;
    int cchTextMax;
    int iSubItem;       // subitem to display
} LV_COLUMN, * PLV_COLUMN, FAR * LPLV_COLUMN;


// LV_COLUMN mask values
#define LVCF_FMT        0x0001
#define LVCF_WIDTH      0x0002
#define LVCF_TEXT       0x0004
#define LVCF_SUBITEM    0x0008
#define LVCF_ALL    0x0010


// Column format codes
#define LVCFMT_LEFT     0
#define LVCFMT_RIGHT    1
#define LVCFMT_CENTER   2

// Set/Query column info
// BOOL ListView_GetColumn(HWND hwndLV, int iCol, LV_COLUMN FAR* pcol);
#define LVM_GETCOLUMN       (LVM_FIRST + 25)
#define ListView_GetColumn(hwnd, iCol, pcol) \
    (BOOL)SendMessage((hwnd), LVM_GETCOLUMN, (WPARAM)(int)(iCol), (LPARAM)(LV_COLUMN FAR*)(pcol))

// BOOL ListView_SetColumn(HWND hwndLV, int iCol, LV_COLUMN FAR* pcol);
#define LVM_SETCOLUMN       (LVM_FIRST + 26)
#define ListView_SetColumn(hwnd, iCol, pcol) \
    (BOOL)SendMessage((hwnd), LVM_SETCOLUMN, (WPARAM)(int)(iCol), (LPARAM)(const LV_COLUMN FAR*)(pcol))

// insert/delete report view column
// int ListView_InsertColumn(HWND hwndLV, int iCol, const LV_COLUMN FAR* pcol);
#define LVM_INSERTCOLUMN    (LVM_FIRST + 27)
#define ListView_InsertColumn(hwnd, iCol, pcol) \
    (int)SendMessage((hwnd), LVM_INSERTCOLUMN, (WPARAM)(int)(iCol), (LPARAM)(const LV_COLUMN FAR*)(pcol))

// BOOL ListView_DeleteColumn(HWND hwndLV, int iCol);
#define LVM_DELETECOLUMN    (LVM_FIRST + 28)
#define ListView_DeleteColumn(hwnd, iCol) \
    (BOOL)SendMessage((hwnd), LVM_DELETECOLUMN, (WPARAM)(int)(iCol), 0)

#define LVM_GETCOLUMNWIDTH  (LVM_FIRST + 29)
#define ListView_GetColumnWidth(hwnd, iCol) \
    (int)SendMessage((hwnd), LVM_GETCOLUMNWIDTH, (WPARAM)(int)(iCol), 0)

#define     LVSCW_AUTOSIZE              -1
#define     LVSCW_AUTOSIZE_USEHEADER    -2
#define LVM_SETCOLUMNWIDTH  (LVM_FIRST + 30)
#define ListView_SetColumnWidth(hwnd, iCol, cx) \
    (BOOL)SendMessage((hwnd), LVM_SETCOLUMNWIDTH, (WPARAM)(int)(iCol), MAKELPARAM((cx), 0))

// HIMAGELIST ListView_CreateDragImage(HWND hwndLV, int iItem, LPPOINT lpptUpLeft);
#define LVM_CREATEDRAGIMAGE        (LVM_FIRST + 33)
#define ListView_CreateDragImage(hwnd, i, lpptUpLeft) \
    (HIMAGELIST)SendMessage((hwnd), LVM_CREATEDRAGIMAGE, (WPARAM)(int)(i), (LPARAM)(LPPOINT)(lpptUpLeft))

// BOOL ListView_GetViewRect(HWND hwndLV, RECT FAR* prc);
#define LVM_GETVIEWRECT     (LVM_FIRST + 34)
#define ListView_GetViewRect(hwnd, prc) \
    (BOOL)SendMessage((hwnd), LVM_GETVIEWRECT, 0, (LPARAM)(RECT FAR*)(prc))

// get/set text and textbk color for text drawing.  these override
// the standard window/windowtext settings.  they do NOT override
// when drawing selected text.
// COLORREF ListView_GetTextColor(HWND hwnd);
#define LVM_GETTEXTCOLOR      (LVM_FIRST + 35)
#define ListView_GetTextColor(hwnd)  \
    (COLORREF)SendMessage((hwnd), LVM_GETTEXTCOLOR, 0, 0L)

// BOOL ListView_SetTextColor(HWND hwnd, COLORREF clrText);
#define LVM_SETTEXTCOLOR      (LVM_FIRST + 36)
#define ListView_SetTextColor(hwnd, clrText) \
    (BOOL)SendMessage((hwnd), LVM_SETTEXTCOLOR, 0, (LPARAM)(COLORREF)(clrText))

// COLORREF ListView_GetTextBkColor(HWND hwnd);
#define LVM_GETTEXTBKCOLOR      (LVM_FIRST + 37)
#define ListView_GetTextBkColor(hwnd)  \
    (COLORREF)SendMessage((hwnd), LVM_GETTEXTBKCOLOR, 0, 0L)

// BOOL ListView_SetTextBkColor(HWND hwnd, COLORREF clrTextBk);
#define LVM_SETTEXTBKCOLOR      (LVM_FIRST + 38)
#define ListView_SetTextBkColor(hwnd, clrTextBk) \
    (BOOL)SendMessage((hwnd), LVM_SETTEXTBKCOLOR, 0, (LPARAM)(COLORREF)(clrTextBk))

// messages for getting the index of the first visible item
#define LVM_GETTOPINDEX         (LVM_FIRST + 39)
#define ListView_GetTopIndex(hwndLV) \
    (int)SendMessage((hwndLV), LVM_GETTOPINDEX, 0, 0)

// Message for getting the count of items per page
#define LVM_GETCOUNTPERPAGE     (LVM_FIRST + 40)
#define ListView_GetCountPerPage(hwndLV) \
    (int)SendMessage((hwndLV), LVM_GETCOUNTPERPAGE, 0, 0)

// Message for getting the listview origin, which is needed for SetItemPos...
#define LVM_GETORIGIN           (LVM_FIRST + 41)
#define ListView_GetOrigin(hwndLV, ppt) \
    (BOOL)SendMessage((hwndLV), LVM_GETORIGIN, (WPARAM)0, (LPARAM)(POINT FAR*)(ppt))

// Message for getting the count of items per page
#define LVM_UPDATE     (LVM_FIRST + 42)
#define ListView_Update(hwndLV, i) \
    (BOOL)SendMessage((hwndLV), LVM_UPDATE, (WPARAM)i, 0L)

// set and item's state.  this macro will return VOID.  but the
// message returns BOOL success.
#define LVM_SETITEMSTATE                (LVM_FIRST + 43)
#define ListView_SetItemState(hwndLV, i, data, mask) \
{ LV_ITEM _ms_lvi;\
  _ms_lvi.stateMask = mask;\
  _ms_lvi.state = data;\
  SendMessage((hwndLV), LVM_SETITEMSTATE, (WPARAM)i, (LPARAM)(LV_ITEM FAR *)&_ms_lvi);\
}

// get the item's state
#define LVM_GETITEMSTATE                (LVM_FIRST + 44)
#define ListView_GetItemState(hwndLV, i, mask) \
   (UINT)SendMessage((hwndLV), LVM_GETITEMSTATE, (WPARAM)i, (LPARAM)mask)

// get the item  text.
// if you want the int return value of how the buff size, you call it yourself.
#define LVM_GETITEMTEXT                 (LVM_FIRST + 45)
#define ListView_GetItemText(hwndLV, i, iSubItem_, pszText_, cchTextMax_) \
{ LV_ITEM _ms_lvi;\
  _ms_lvi.iSubItem = iSubItem_;\
  _ms_lvi.cchTextMax = cchTextMax_;\
  _ms_lvi.pszText = pszText_;\
  SendMessage((hwndLV), LVM_GETITEMTEXT, (WPARAM)i, (LPARAM)(LV_ITEM FAR *)&_ms_lvi);\
}

// get the item  text.
// if you want the int return value (BOOL) success do it yourself
#define LVM_SETITEMTEXT                 (LVM_FIRST + 46)
#define ListView_SetItemText(hwndLV, i, iSubItem_, pszText_) \
{ LV_ITEM _ms_lvi;\
  _ms_lvi.iSubItem = iSubItem_;\
  _ms_lvi.pszText = pszText_;\
  SendMessage((hwndLV), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)(LV_ITEM FAR *)&_ms_lvi);\
}

// tell the listview that you are going to add nItems lot of items
#define LVM_SETITEMCOUNT                 (LVM_FIRST + 47)
#define ListView_SetItemCount(hwndLV, cItems) \
  SendMessage((hwndLV), LVM_SETITEMCOUNT, (WPARAM)cItems, 0)

typedef int (CALLBACK *PFNLVCOMPARE)(LPARAM, LPARAM, LPARAM);

// tell the listview to resort the items
#define LVM_SORTITEMS                    (LVM_FIRST + 48)
#define ListView_SortItems(hwndLV, _pfnCompare, _lPrm) \
  (BOOL)SendMessage((hwndLV), LVM_SORTITEMS, (WPARAM)(LPARAM)_lPrm, \
  (LPARAM)(PFNLVCOMPARE)_pfnCompare)

// void ListView_SetItemPosition(HWND hwndLV, int i, int x, int y);
#define LVM_SETITEMPOSITION32 (LVM_FIRST + 49)
#define ListView_SetItemPosition32(hwndLV, i, x, y) \
{ POINT ptNewPos = {x,y}; \
    SendMessage((hwndLV), LVM_SETITEMPOSITION32, (WPARAM)(int)(i), (LPARAM)&ptNewPos); \
}

// get the number of items selected
#define LVM_GETSELECTEDCOUNT  (LVM_FIRST + 50)
#define ListView_GetSelectedCount(hwndLV) \
    (UINT)SendMessage((hwndLV), LVM_GETSELECTEDCOUNT, 0, 0L)

#define LVM_GETITEMSPACING (LVM_FIRST + 51)
#define ListView_GetItemSpacing(hwndLV, fSmall) \
        (DWORD)SendMessage((hwndLV), LVM_GETITEMSPACING, fSmall, 0L)

// returns true/false telling whether it's in search mode or not
#define LVM_GETISEARCHSTRING (LVM_FIRST + 52)
#define ListView_GetISearchString(hwndLV, lpsz) \
        (BOOL)SendMessage((hwndLV), LVM_GETISEARCHSTRING, 0, (LPARAM)(LPSTR)lpsz)


// ListView notification codes

// Structure used by all ListView control notifications.
// Not all fields supply useful info for all notifications:
// iItem will be -1 and others 0 if not used.
// Some return a BOOL, too.
//

typedef struct _NM_LISTVIEW
{
    NMHDR   hdr;
    int     iItem;
    int     iSubItem;
    UINT    uNewState;      // Combination of LVIS_* (if uChanged & LVIF_STATE)
    UINT    uOldState;      // Combination of LVIS_*
    UINT    uChanged;       // Combination of LVIF_* indicating what changed
    POINT   ptAction;       // Only valid for LVN_BEGINDRAG and LVN_BEGINRDRAG
    LPARAM  lParam;         // Only valid for LVN_DELETEITEM
} NM_LISTVIEW, FAR *LPNM_LISTVIEW;

#define LVN_ITEMCHANGING        (LVN_FIRST-0)  // lParam -> NM_LISTVIEW: item changing.  Return FALSE to disallow
#define LVN_ITEMCHANGED         (LVN_FIRST-1)  // item changed.
#define LVN_INSERTITEM          (LVN_FIRST-2)
#define LVN_DELETEITEM          (LVN_FIRST-3)
#define LVN_DELETEALLITEMS      (LVN_FIRST-4)
#define LVN_BEGINLABELEDIT      (LVN_FIRST-5)  // lParam -> LV_DISPINFO: start of label editing
#define LVN_ENDLABELEDIT        (LVN_FIRST-6)  // lParam -> LV_DISPINFO: end of label editing
                                         // (iItem == -1 if cancel)

//(LVN_FIRST-7) not used


#define LVN_COLUMNCLICK         (LVN_FIRST-8)   // column identified by iItem was clicked

#define LVN_BEGINDRAG           (LVN_FIRST-9)   // Start of drag operation requested
                                         // (return FALSE if the app handles it)
#define LVN_ENDDRAG             (LVN_FIRST-10)  // End of dragging operation.
#define LVN_BEGINRDRAG          (LVN_FIRST-11)  // Start of button 2 dragging
#define LVN_ENDRDRAG            (LVN_FIRST-12)  // End of button 2 drag (not used yet)

#ifdef PW2
#define LVN_PEN                 (LVN_FIRST-20)  // pen notifications
#endif //PW2

// LVN_DISPINFO notification

#define LVN_GETDISPINFO         (LVN_FIRST-50) // lParam -> LV_DISPINFO
#define LVN_SETDISPINFO         (LVN_FIRST-51)  // lParam -> LV_DISPINFO

#define LVIF_DI_SETITEM      0x1000   // keeps values returned in this GetDispInfo call

typedef struct _LV_DISPINFO {
    NMHDR hdr;
    LV_ITEM item;
} LV_DISPINFO, FAR * LPLV_DISPINFO;

// LVN_KEYDOWN notification
#define LVN_KEYDOWN (LVN_FIRST-55)

typedef struct _LV_KEYDOWN
{
    NMHDR hdr;
    WORD wVKey;
    UINT flags;
} LV_KEYDOWN;



// ====== TREEVIEW APIs =================================================
//
// Class name: SysTreeView (WC_TREEVIEW)
//
// The SysTreeView control provides for a group of items which are
// displayed in a hierarchical organization.  Each item may contain
// independent "sub-item" entries which are displayed below and indented
// from the parent item.
//
// Operation of this control is similar to the SysListView control above,
// except that sub-items are distinct entries, not supporting text elements
// belonging to the owning object (which is the case for the Report View
// mode of the SysListView).
//
// There are notifications that allow applications to determine when an item
// has been clicked or double clicked, caption text changes have occured,
// drag tracking is occuring, widths of columns have changed, node items
// are expanded, etc.
//
// NOTE: All "messages" below are documented as APIs; eventually these
// will be changed to window messages, and corresponding macros will be
// written that have the same signature as the APIs shown below.
//

#ifdef WIN32
#define WC_TREEVIEW     "SysTreeView32"
#else
#define WC_TREEVIEW     "SysTreeView"
#endif

// TreeView window styles
#define TVS_HASBUTTONS      0x0001 // draw "plus" & "minus" sign on nodes with children
#define TVS_HASLINES        0x0002 // draw lines between nodes
#define TVS_LINESATROOT     0x0004
#define TVS_EDITLABELS      0x0008 // alow text edit in place
#define TVS_DISABLEDRAGDROP 0x0010      // disable draggine notification of nodes
#define TVS_SHOWSELALWAYS   0x0020

typedef struct _TREEITEM FAR* HTREEITEM;

#define TVIF_TEXT           0x0001  // TV_ITEM.mask flags
#define TVIF_IMAGE         0x0002
#define TVIF_PARAM          0x0004
#define TVIF_STATE          0x0008
#define TVIF_HANDLE         0x0010
#define TVIF_SELECTEDIMAGE  0x0020
#define TVIF_CHILDREN      0x0040

// State flags
#define TVIS_FOCUSED       0x0001  // TV_ITEM.state flags
#define TVIS_SELECTED       0x0002
#define TVIS_CUT            0x0004  // TVIS_MARKED
#define TVIS_DROPHILITED    0x0008
#define TVIS_BOLD           0x0010
#define TVIS_EXPANDED       0x0020
#define TVIS_EXPANDEDONCE   0x0040

#define TVIS_OVERLAYMASK    0x0F00  // used as ImageList overlay image indexes
#define TVIS_STATEIMAGEMASK 0xF000
#define TVIS_USERMASK       0xF000

#define I_CHILDRENCALLBACK  (-1)    // cChildren value for children callback

typedef struct _TV_ITEM {
    UINT      mask;    // TVIF_ flags
    HTREEITEM hItem;      // The item to be changed
    UINT      state;      // TVIS_ flags
    UINT      stateMask;  // TVIS_ flags (valid bits in state)
    LPSTR     pszText;    // The text for this item
    int       cchTextMax; // The length of the pszText buffer
    int       iImage;     // The index of the image for this item
    int       iSelectedImage;   // the index of the selected imagex
    int       cChildren;  // # of child nodes, I_CHILDRENCALLBACK for callback
    LPARAM    lParam;     // App defined data
} TV_ITEM, FAR *LPTV_ITEM;

#define TVI_ROOT  ((HTREEITEM)0xFFFF0000)
#define TVI_FIRST ((HTREEITEM)0xFFFF0001)
#define TVI_LAST  ((HTREEITEM)0xFFFF0002)
#define TVI_SORT  ((HTREEITEM)0xFFFF0003)

typedef struct _TV_INSERTSTRUCT {
    HTREEITEM hParent;    // a valid HTREEITEM or TVI_ value
    HTREEITEM hInsertAfter;  // a valid HTREEITEM or TVI_ value
    TV_ITEM item;
} TV_INSERTSTRUCT, FAR *LPTV_INSERTSTRUCT;

#define TVM_INSERTITEM      (TV_FIRST + 0)
#define TreeView_InsertItem(hwnd, lpis) \
    (HTREEITEM)SendMessage((hwnd), TVM_INSERTITEM, 0, (LPARAM)(LPTV_INSERTSTRUCT)(lpis))

#define TVM_DELETEITEM      (TV_FIRST + 1)
#define TreeView_DeleteItem(hwnd, hitem) \
    (BOOL)SendMessage((hwnd), TVM_DELETEITEM, 0, (LPARAM)(HTREEITEM)(hitem))

#define TreeView_DeleteAllItems(hwnd) \
    (BOOL)SendMessage((hwnd), TVM_DELETEITEM, 0, (LPARAM)TVI_ROOT)

#define TVM_EXPAND      (TV_FIRST + 2)
#define TreeView_Expand(hwnd, hitem, code) \
    (BOOL)SendMessage((hwnd), TVM_EXPAND, (WPARAM)code, (LPARAM)(HTREEITEM)(hitem))

// TreeView_Expand codes
#define TVE_COLLAPSE        0x0001
#define TVE_EXPAND          0x0002
#define TVE_TOGGLE          0x0003
#define TVE_COLLAPSERESET   0x8000 // remove all children when collapsing


#define TVM_GETITEMRECT     (TV_FIRST + 4)
#define TreeView_GetItemRect(hwnd, hitem, prc, code) \
    (*(HTREEITEM FAR *)prc = (hitem), (BOOL)SendMessage((hwnd), TVM_GETITEMRECT, (WPARAM)(code), (LPARAM)(RECT FAR*)(prc)))

#define TVM_GETCOUNT        (TV_FIRST + 5)
#define TreeView_GetCount(hwnd) \
    (UINT)SendMessage((hwnd), TVM_GETCOUNT, 0, 0)

#define TVM_GETINDENT       (TV_FIRST + 6)
#define TreeView_GetIndent(hwnd) \
    (UINT)SendMessage((hwnd), TVM_GETINDENT, 0, 0)

#define TVM_SETINDENT       (TV_FIRST + 7)
#define TreeView_SetIndent(hwnd, indent) \
    (BOOL)SendMessage((hwnd), TVM_SETINDENT, (WPARAM)indent, 0)

#define TVM_GETIMAGELIST    (TV_FIRST + 8)
#define TreeView_GetImageList(hwnd, iImage) \
    (HIMAGELIST)SendMessage((hwnd), TVM_GETIMAGELIST, iImage, 0)

#define TVSIL_NORMAL   0
#define TVSIL_STATE 2  // use TVIS_STATEIMAGEMASK as index into state imagelist

#define TVM_SETIMAGELIST    (TV_FIRST + 9)
#define TreeView_SetImageList(hwnd, himl, iImage) \
    (HIMAGELIST)SendMessage((hwnd), TVM_SETIMAGELIST, iImage, (LPARAM)(UINT)(HIMAGELIST)(himl))


#define TVM_GETNEXTITEM       (TV_FIRST + 10)
#define TreeView_GetNextItem(hwnd, hitem, code) \
    (HTREEITEM)SendMessage((hwnd), TVM_GETNEXTITEM, (WPARAM)code, (LPARAM)(HTREEITEM)(hitem))

// TreeView_GetNextItem & TreeView_SelectItem codes
#define TVGN_ROOT      0x0000  // GetNextItem()
#define TVGN_NEXT      0x0001   // GetNextItem()
#define TVGN_PREVIOUS     0x0002   // GetNextItem()
#define TVGN_PARENT    0x0003   // GetNextItem()
#define TVGN_CHILD     0x0004   // GetNextItem()
#define TVGN_FIRSTVISIBLE 0x0005  // GetNextItem() & SelectItem()
#define TVGN_NEXTVISIBLE  0x0006   // GetNextItem()
#define TVGN_PREVIOUSVISIBLE 0x0007   // GetNextItem()
#define TVGN_DROPHILITE      0x0008   // GetNextItem() & SelectItem()
#define TVGN_CARET     0x0009   // GetNextItem() & SelectItem()

#define TreeView_GetChild(hwnd, hitem)      TreeView_GetNextItem(hwnd, hitem, TVGN_CHILD)
#define TreeView_GetNextSibling(hwnd, hitem)   TreeView_GetNextItem(hwnd, hitem, TVGN_NEXT)
#define TreeView_GetPrevSibling(hwnd, hitem)    TreeView_GetNextItem(hwnd, hitem, TVGN_PREVIOUS)
#define TreeView_GetParent(hwnd, hitem)     TreeView_GetNextItem(hwnd, hitem, TVGN_PARENT)
#define TreeView_GetFirstVisible(hwnd)      TreeView_GetNextItem(hwnd, NULL,  TVGN_FIRSTVISIBLE)
#define TreeView_GetNextVisible(hwnd, hitem)   TreeView_GetNextItem(hwnd, hitem, TVGN_NEXTVISIBLE)
#define TreeView_GetPrevVisible(hwnd, hitem)    TreeView_GetNextItem(hwnd, hitem, TVGN_PREVIOUSVISIBLE)
#define TreeView_GetSelection(hwnd)      TreeView_GetNextItem(hwnd, NULL,  TVGN_CARET)
#define TreeView_GetDropHilight(hwnd)    TreeView_GetNextItem(hwnd, NULL,  TVGN_DROPHILITE)
#define TreeView_GetRoot(hwnd)           TreeView_GetNextItem(hwnd, NULL,  TVGN_ROOT)

#define TVM_SELECTITEM      (TV_FIRST + 11)
#define TreeView_Select(hwnd, hitem, code) \
    (HTREEITEM)SendMessage((hwnd), TVM_SELECTITEM, (WPARAM)code, (LPARAM)(HTREEITEM)(hitem))

#define TreeView_SelectItem(hwnd, hitem)     TreeView_Select(hwnd, hitem, TVGN_CARET)
#define TreeView_SelectDropTarget(hwnd, hitem)     TreeView_Select(hwnd, hitem, TVGN_DROPHILITE)
#define TreeView_SelectSetFirstVisible(hwnd, hitem) TreeView_Select(hwnd, hitem, TVGN_FIRSTVISIBLE)

#define TVM_GETITEM         (TV_FIRST + 12)
#define TreeView_GetItem(hwnd, pitem) \
    (BOOL)SendMessage((hwnd), TVM_GETITEM, 0, (LPARAM)(TV_ITEM FAR*)(pitem))

#define TVM_SETITEM         (TV_FIRST + 13)
#define TreeView_SetItem(hwnd, pitem) \
    (BOOL)SendMessage((hwnd), TVM_SETITEM, 0, (LPARAM)(const TV_ITEM FAR*)(pitem))

#define TVM_EDITLABEL       (TV_FIRST + 14)
#define TreeView_EditLabel(hwnd, hitem) \
    (HWND)SendMessage((hwnd), TVM_EDITLABEL, 0, (LPARAM)(HTREEITEM)(hitem))

#define TVM_GETEDITCONTROL  (TV_FIRST + 15)
#define TreeView_GetEditControl(hwnd) \
    (HWND)SendMessage((hwnd), TVM_GETEDITCONTROL, 0, 0)

#define TVM_GETVISIBLECOUNT (TV_FIRST + 16)
#define TreeView_GetVisibleCount(hwnd) \
    (UINT)SendMessage((hwnd), TVM_GETVISIBLECOUNT, 0, 0)

#define TVM_HITTEST         (TV_FIRST + 17)
#define TreeView_HitTest(hwnd, lpht) \
    (HTREEITEM)SendMessage((hwnd), TVM_HITTEST, 0, (LPARAM)(LPTV_HITTESTINFO)(lpht))

typedef struct _TV_HITTESTINFO {
    POINT       pt;    // in: client coords
    UINT   flags;      // out: TVHT_ flags
    HTREEITEM   hItem;    // out:
} TV_HITTESTINFO, FAR *LPTV_HITTESTINFO;

#define TVHT_NOWHERE        0x0001
#define TVHT_ONITEMICON     0x0002
#define TVHT_ONITEMLABEL    0x0004
#define TVHT_ONITEM         (TVHT_ONITEMICON | TVHT_ONITEMLABEL | TVHT_ONITEMSTATEICON)
#define TVHT_ONITEMINDENT   0x0008
#define TVHT_ONITEMBUTTON   0x0010
#define TVHT_ONITEMRIGHT    0x0020
#define TVHT_ONITEMSTATEICON 0x0040

#define TVHT_ABOVE          0x0100
#define TVHT_BELOW          0x0200
#define TVHT_TORIGHT        0x0400
#define TVHT_TOLEFT         0x0800

#define TVM_CREATEDRAGIMAGE  (TV_FIRST + 18)
#define TreeView_CreateDragImage(hwnd, hitem) \
    (HIMAGELIST)SendMessage((hwnd), TVM_CREATEDRAGIMAGE, 0, (LPARAM)(HTREEITEM)(hitem))

#define TVM_SORTCHILDREN     (TV_FIRST + 19)
#define TreeView_SortChildren(hwnd, hitem, recurse) \
    (BOOL)SendMessage((hwnd), TVM_SORTCHILDREN, (WPARAM)recurse, (LPARAM)(HTREEITEM)(hitem))

#define TVM_ENSUREVISIBLE    (TV_FIRST + 20)
#define TreeView_EnsureVisible(hwnd, hitem) \
    (BOOL)SendMessage((hwnd), TVM_ENSUREVISIBLE, 0, (LPARAM)(HTREEITEM)(hitem))

#define TVM_SORTCHILDRENCB   (TV_FIRST + 21)
#define TreeView_SortChildrenCB(hwnd, psort, recurse) \
    (BOOL)SendMessage((hwnd), TVM_SORTCHILDRENCB, (WPARAM)recurse, \
    (LPARAM)(LPTV_SORTCB)(psort))

#define TVM_ENDEDITLABELNOW  (TV_FIRST + 22)
#define TreeView_EndEditLabelNow(hwnd, fCancel) \
    (BOOL)SendMessage((hwnd), TVM_ENDEDITLABELNOW, (WPARAM)fCancel, 0)

// returns true/false telling whether it's in search mode or not
#define TVM_GETISEARCHSTRING (TV_FIRST + 23)
#define TreeView_GetISearchString(hwndTV, lpsz) \
        (BOOL)SendMessage((hwndTV), TVM_GETISEARCHSTRING, 0, (LPARAM)(LPSTR)lpsz)

typedef int (CALLBACK *PFNTVCOMPARE)(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);
typedef struct _TV_SORTCB
{
  HTREEITEM   hParent;
  PFNTVCOMPARE   lpfnCompare;
  LPARAM      lParam;
} TV_SORTCB, FAR *LPTV_SORTCB;

// common notificaton structure for WM_NOTIFY sent to parent
// some fields are only valid on some notify messages

typedef struct _NM_TREEVIEW {
    NMHDR       hdr;
    UINT   action;         // notification specific action
    TV_ITEM   itemOld;
    TV_ITEM   itemNew;
    POINT       ptDrag;
} NM_TREEVIEW, FAR *LPNM_TREEVIEW;

#define TVN_SELCHANGING     (TVN_FIRST-1)
#define TVN_SELCHANGED      (TVN_FIRST-2)

// lParam -> NM_TREEVIEW
// NM_TREEVIEW.itemNew.hItem & NM_TREEVIEW.itemNew.lParam are valid
// NM_TREEVIEW.itemOld.hItem & NM_TREEVIEW.itemOld.lParam are valid
// NM_TREEVIEW.action is a TVE_ value indicating how the selcection changed

// TVN_SELCHANGING & TVN_SELCHANGED action values
#define TVC_UNKNOWN     0x0000
#define TVC_BYMOUSE         0x0001
#define TVC_BYKEYBOARD      0x0002


#define TVN_GETDISPINFO     (TVN_FIRST-3)
#define TVN_SETDISPINFO     (TVN_FIRST-4)
// lParam -> TV_DISPINFO structure
// TV_DISPINFO.item.hItem & TV_DISPINFO.item.lParam are valid

#define TVIF_DI_SETITEM      0x1000   // keeps values returned in this GetDispInfo call

typedef struct _TV_DISPINFO {
    NMHDR hdr;
    TV_ITEM item;
} TV_DISPINFO;

#define TVN_ITEMEXPANDING   (TVN_FIRST-5)
#define TVN_ITEMEXPANDED    (TVN_FIRST-6)
// lParam -> NM_TREEVIEW
// NM_TREEVIEW.itemNew.hItem & NM_TREEVIEW.itemNew.state & NM_TREEVIEW.itemNew.lParam are valid
// NM_TREEVIEW.action is TVE_ action and flags

#define TVN_BEGINDRAG       (TVN_FIRST-7)
#define TVN_BEGINRDRAG      (TVN_FIRST-8)
// lParam -> NM_TREEVIEW
// NM_TREEVIEW.itemNew.hItem & NM_TREEVIEW.itemNew.lParam are valid
// NM_TREEVIEW.ptDrag is start of drag in client coords

#define TVN_DELETEITEM      (TVN_FIRST-9)
// lParam -> NM_TREEVIEW
// NM_TREEVIEW.itemOld.hItem & NM_TREEVIEW.itemOld.lParam are valid

#define TVN_BEGINLABELEDIT  (TVN_FIRST-10)
#define TVN_ENDLABELEDIT    (TVN_FIRST-11)
// lParam -> TV_DISPINFO
// TV_DISPINFO.item.hItem & TV_DISPINFO.item.state & TV_DISPINFO.item.lParam & TV_DISPINFO.item.pszText
// are valid

#define TVN_KEYDOWN         (TVN_FIRST-12)
// lParam -> TV_KEYDOWN

typedef struct _TV_KEYDOWN {
    NMHDR hdr;
    WORD wVKey;
    UINT flags;
} TV_KEYDOWN;




/*
 * Extended Window Styles
 */
#define WS_EX_MDICHILD          0x00000040L
#define WS_EX_TOOLWINDOW        0x00000080L
#define WS_EX_WINDOWEDGE        0x00000100L
#define WS_EX_CLIENTEDGE        0x00000200L
#define WS_EX_CONTEXTHELP       0x00000400L

#define WS_EX_RIGHT             0x00001000L
#define WS_EX_LEFT              0x00000000L
#define WS_EX_RTLREADING        0x00002000L
#define WS_EX_LTRREADING        0x00000000L
#define WS_EX_LEFTSCROLLBAR     0x00004000L
#define WS_EX_RIGHTSCROLLBAR    0x00000000L

#define WS_EX_CONTROLPARENT     0x00010000L
#define WS_EX_STATICEDGE        0x00020000L


#define WS_EX_OVERLAPPEDWINDOW  (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#define WS_EX_PALETTEWINDOW     (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)

/*
 * Dialog Styles
 */
#define DS_3DLOOK           0x0004L
#define DS_FIXEDSYS         0x0008L
#define DS_NOFAILCREATE     0x0010L
#define DS_CONTROL          0x0400L
#define DS_CENTER           0x0800L
#define DS_CENTERMOUSE      0x1000L
#define DS_CONTEXTHELP      0x2000L


/*/////////////////////////////////////////////////////////////////////////*/


//dwhanger,25.1.95,mfc-ing
#if !defined( USING_MFC )
  #define WM_NOTIFY                   0x004E
#endif
#if !defined( WM_HELP )
#define WM_HELP                 0x0053
#define WM_CONTEXTMENU          0x007B

#define HELPINFO_WINDOW            0x0001
#define HELPINFO_MENUITEM       0x0002

typedef  struct  tagHELPINFO    /* Structure pointed to by lParam of WM_HELP */
{
    UINT    cbSize;             /* Size in bytes of this struct  */
    int     iContextType;       /* Either HELPINFO_WINDOW or HELPINFO_MENUITEM */
    int     iCtrlId;            /* Control Id or a Menu item Id. */
    HANDLE  hItemHandle;        /* hWnd of control or hMenu.     */
    DWORD   dwContextId;        /* Context Id associated with this item */
    POINT   MousePos;           /* Mouse Position in screen co-ordinates */
}  HELPINFO;
typedef HELPINFO  FAR *LPHELPINFO;
#endif		// !defined( WM_HELP )

typedef struct tagWNDCLASSEXA
{
    UINT        cbSize;

    /* Win 3.x */
    UINT        style;
    WNDPROC     lpfnWndProc;
    int         cbClsExtra;
    int         cbWndExtra;
    HINSTANCE   hInstance;
    HICON       hIcon;
    HCURSOR     hCursor;
    HBRUSH      hbrBackground;
    LPCSTR      lpszMenuName;
    LPCSTR      lpszClassName;

    /* Win 4.0 */
    HICON       hIconSm;
} WNDCLASSEXA, *PWNDCLASSEXA, NEAR *NPWNDCLASSEXA, FAR *LPWNDCLASSEXA;

// UNICODE Structures should not be defined of WIN 3.X
#if (WINVER > 0x030a )
typedef struct tagWNDCLASSEXW
{
    UINT        cbSize;

    /* Win 3.x */
    UINT        style;
    WNDPROC     lpfnWndProc;
    int         cbClsExtra;
    int         cbWndExtra;
    HINSTANCE   hInstance;
    HICON       hIcon;
    HCURSOR     hCursor;
    HBRUSH      hbrBackground;
    LPCWSTR      lpszMenuName;
    LPCWSTR      lpszClassName;

    /* Win 4.0 */
    HICON       hIconSm;
} WNDCLASSEXW, *PWNDCLASSEXW, NEAR *NPWNDCLASSEXW, FAR *LPWNDCLASSEXW;
#endif

#ifdef UNICODE
typedef WNDCLASSEXW WNDCLASSEX;
typedef PWNDCLASSEXW PWNDCLASSEX;
typedef NPWNDCLASSEXW NPWNDCLASSEX;
typedef LPWNDCLASSEXW LPWNDCLASSEX;
#else /* UNICODE */
typedef WNDCLASSEXA WNDCLASSEX;
typedef PWNDCLASSEXA PWNDCLASSEX;
typedef NPWNDCLASSEXA NPWNDCLASSEX;
typedef LPWNDCLASSEXA LPWNDCLASSEX;
#endif /* !UNICODE */



#if (WINVER > 0x030a )
ATOM    WINAPI RegisterClassExW(const WNDCLASSEXW FAR *);
#endif
ATOM    WINAPI RegisterClassExA(const WNDCLASSEXA FAR *);

#ifdef UNICODE
#define RegisterClassEx RegisterClassExW
#else
#define RegisterClassEx RegisterClassExA
#endif /* !UNICODE */


#define IMAGE_BITMAP        0
#define IMAGE_ICON          1
#define IMAGE_CURSOR        2
#define IMAGE_ENHMETAFILE   3

#define LR_DEFAULTCOLOR     0x0000
#define LR_MONOCHROME       0x0001
#define LR_COPYRETURNORG    0x0002
#define LR_COPYDELETEORG    0x0004
#define LR_COPYFROMRESOURCE 0x0008
#define LR_LOADFROMFILE     0x0010
#define LR_LOADREALSIZE     0x0020
#define LR_LOADMAP3DCOLORS  0x1000

// UNICODE Structures should not be defined of WIN 3.X
#if (WINVER > 0x030a )
HANDLE
WINAPI
LoadImageW(
    HINSTANCE,
    LPCWSTR,
    UINT,
    int,
    int,
    UINT);
#endif
HANDLE
WINAPI
LoadImageA(
    HINSTANCE,
    LPCSTR,
    UINT,
    int,
    int,
    UINT);
#ifdef UNICODE
#define LoadImage   LoadImageW
#else
#define LoadImage   LoadImageA
#endif

// OPENFILENAME Flags.
#define OFN_EXPLORER                 0x00080000     // new look commdlg
#define OFN_NODEREFERENCELINKS       0x00100000
#define OFN_LONGNAMES                0x00200000     // force long names for 3.x modules


#define DN_DEFAULTPRN      0x0001

#define WM_PSD_PAGESETUPDLG     (WM_USER  )
#define WM_PSD_FULLPAGERECT     (WM_USER+1)
#define WM_PSD_MINMARGINRECT    (WM_USER+2)
#define WM_PSD_MARGINRECT       (WM_USER+3)
#define WM_PSD_GREEKTEXTRECT    (WM_USER+4)
#define WM_PSD_ENVSTAMPRECT     (WM_USER+5)
#define WM_PSD_YAFULLPAGERECT   (WM_USER+6)

typedef UINT (WINAPI* LPPAGEPAINTHOOK)( HWND, UINT, WPARAM, LPARAM );
typedef UINT (WINAPI* LPPAGESETUPHOOK)( HWND, UINT, WPARAM, LPARAM );

typedef struct tagPSDA
{
    DWORD           lStructSize;
    HWND            hwndOwner;
    HGLOBAL         hDevMode;
    HGLOBAL         hDevNames;
    DWORD           Flags;
    POINT           ptPaperSize;
    RECT            rtMinMargin;
    RECT            rtMargin;
    HINSTANCE       hInstance;
    LPARAM          lCustData;
    LPPAGESETUPHOOK lpfnPageSetupHook;
    LPPAGEPAINTHOOK lpfnPagePaintHook;
    LPCSTR          lpPageSetupTemplateName;
    HGLOBAL         hPageSetupTemplate;
} PAGESETUPDLGA, * LPPAGESETUPDLGA;

// UNICODE Structures should not be defined of WIN 3.X
#if (WINVER > 0x030a )
typedef struct tagPSDW
{
    DWORD           lStructSize;
    HWND            hwndOwner;
    HGLOBAL         hDevMode;
    HGLOBAL         hDevNames;
    DWORD           Flags;
    POINT           ptPaperSize;
    RECT            rtMinMargin;
    RECT            rtMargin;
    HINSTANCE       hInstance;
    LPARAM          lCustData;
    LPPAGESETUPHOOK lpfnPageSetupHook;
    LPPAGEPAINTHOOK lpfnPagePaintHook;
    LPCWSTR         lpPageSetupTemplateName;
    HGLOBAL         hPageSetupTemplate;
} PAGESETUPDLGW, * LPPAGESETUPDLGW;

BOOL WINAPI PageSetupDlgW( LPPAGESETUPDLGW );

#endif //(WINVER > 0x030a )

#ifdef UNICODE
typedef PAGESETUPDLGW PAGESETUPDLG;
typedef LPPAGESETUPDLGW LPPAGESETUPDLG;
#else
typedef PAGESETUPDLGA PAGESETUPDLG;
typedef LPPAGESETUPDLGA LPPAGESETUPDLG;
#endif // UNICODE

BOOL WINAPI PageSetupDlgA( LPPAGESETUPDLGA );

#ifdef UNICODE
#define PageSetupDlg  PageSetupDlgW
#else
#define PageSetupDlg  PageSetupDlgA
#endif // !UNICODE

#define PSD_DEFAULTMINMARGINS             0x00000000 // default (printer's)
#define PSD_INWININIINTLMEASURE           0x00000000 // 1st of 4 possible

#define PSD_MINMARGINS                    0x00000001 // use caller's
#define PSD_MARGINS                       0x00000002 // use caller's
#define PSD_INTHOUSANDTHSOFINCHES         0x00000004 // 2nd of 4 possible
#define PSD_INHUNDREDTHSOFMILLIMETERS     0x00000008 // 3rd of 4 possible
#define PSD_DISABLEMARGINS                0x00000010
#define PSD_DISABLEPRINTER                0x00000020
#define PSD_NOWARNING                     0x00000080 // must be same as PD_*
#define PSD_DISABLEORIENTATION            0x00000100
#define PSD_RETURNDEFAULT                 0x00000400 // must be same as PD_*
#define PSD_DISABLEPAPER                  0x00000200
#define PSD_SHOWHELP                      0x00000800 // must be same as PD_*
#define PSD_ENABLEPAGESETUPHOOK           0x00002000 // must be same as PD_*
#define PSD_ENABLEPAGESETUPTEMPLATE       0x00008000 // must be same as PD_*
#define PSD_ENABLEPAGESETUPTEMPLATEHANDLE 0x00020000 // must be same as PD_*
#define PSD_ENABLEPAGEPAINTHOOK           0x00040000
#define PSD_DISABLEPAGEPAINTING           0x00080000


#if defined( __cplusplus )
} // extern "C"
#endif

#else	// WINVER >= 0x0400

#include	<CommCtrl.H>

// Wall Data typedefs.
//typedef	LV_ITEM	FAR * LPLV_ITEM;

#endif  // WINVER < 0x0400


// Macros for TrackBar Class.
#define TrackBar_GetPosition( hWnd )     \
  (long)SendMessage( (HWND)hWnd, TBM_GETPOS, 0, 0L )

#define TrackBar_GetRangeMin( hWnd )  \
  (long)SendMessage( (HWND)hWnd, TBM_GETRANGEMIN, 0, 0L )

#define TrackBar_GetRangeMax( hWnd )  \
  (long)SendMessage( (HWND)hWnd, TBM_GETRANGEMAX, 0, 0L )

#define TrackBar_GetTic( hWnd, iTic ) \
  (long)SendMessage( (HWND)hWnd, TBM_GETTIC, (WPARAM)(WORD)iTic, 0L )

#define TrackBar_SetTic( hWnd, iTic ) \
  (BOOL)SendMessage( (HWND)hWnd, TBM_SETTIC, 0, (LPARAM)(long)iTic )

#define TrackBar_SetPosition( hWnd, fPosition, lPosition )    \
  SendMessage( (HWND)hWnd, TBM_SETPOS, (WPARAM)(BOOL)fPosition, (LPARAM)(long)lPosition )

#define TrackBar_SetRange( hWnd, fRedraw, lMin, lMax )     \
  SendMessage( (HWND)hWnd, TBM_SETRANGE, (WPARAM)(BOOL)fRedraw, (LPARAM)MAKELONG((int)lMin, (int)lMax) )

#define TrackBar_SetRangeMin( hWnd, fRedraw, lMin )     \
  SendMessage( (HWND)hWnd, TBM_SETRANGEMIN, (WPARAM)(BOOL)fRedraw, (LPARAM)(int)lMin )

#define TrackBar_SetRangeMax( hWnd, fRedraw, lMax )     \
  SendMessage( (HWND)hWnd, TBM_SETRANGEMAX, (WPARAM)(BOOL)fRedraw, (LPARAM)(int)lMax )

#define TrackBar_ClearTics( hWnd, fErase )  \
  SendMessage( (HWND)hWnd, TBM_CLEARTICS, (WPARAM)(BOOL)fErase, 0L )

#define TrackBar_SetSelection( hWnd, fErase, lMin, lMax )  \
  SendMessage( (HWND)hWnd, TBM_SETSEL, (WPARAM)(BOOL)fErase, (LPARAM)MAKELONG((int)lMin, (int)lMax) )

#define TrackBar_SetSelectionStart( hWnd, fErase, lStart ) \
  SendMessage( (HWND)hWnd, TBM_SETSELSTART, (WPARAM)(BOOL)fErase, (LPARAM)(int)lStart )

#define TrackBar_SetSelectionEnd( hWnd, fErase, lEnd )  \
  SendMessage( (HWND)hWnd, TBM_SETSELEND, (WPARAM)(BOOL)fErase, (LPARAM)(int)lEnd )

#define TrackBar_GetPTics( hWnd )     \
  (long)SendMessage( (HWND)hWnd, TBM_GETPTICS, 0, 0L )

#define TrackBar_GetTicPosition( hWnd, iTic )  \
  (long)SendMessage( (HWND)hWnd, TBM_GETTICPOS, (WPARAM)(WORD)iTic, 0L )

#define TrackBar_GetNumTics( hWnd )      \
  (long)SendMessage( (HWND)hWnd, TBM_GETNUMTICS, 0, 0L )

#define TrackBar_GetSelStart( hWnd )     \
  (long)SendMessage( (HWND)hWnd, TBM_GETSELSTART, 0, 0L )

#define TrackBar_GetSelEnd( hWnd )    \
  (long)SendMessage( (HWND)hWnd, TBM_GETSELEND, 0, 0L )

#define TrackBar_ClearSel( hWnd, fErase )   \
  SendMessage( (HWND)hWnd, TBM_CLEARSEL, (WPARAM)(BOOL)fErase, 0L )

#define TrackBar_SetTicFrequency( hWnd, wFreq, lPosition ) \
  SendMessage( (HWND)hWnd, TBM_SETTICFREQ, (WPARAM)(int)wFreq, (LPARAM)(long)lPosition )

#define TrackBar_SetPageSize( hWnd, iPageSize )      \
  (long)SendMessage( (HWND)hWnd, TBM_SETPAGESIZE, 0, (LPARAM)(long)iPageSize )

#define TrackBar_GetPageSize( hWnd )     \
  (long)SendMessage( (HWND)hWnd, TBM_GETPAGESIZE, 0, 0L )

#define TrackBar_SetLineSize( hWnd, iLineSize )      \
  (long)SendMessage( (HWND)hWnd, TBM_SETLINESIZE, 0, (LPARAM)(long)iLineSize )

#define TrackBar_GetLineSize( hWnd )  \
  (long)SendMessage( (HWND)hWnd, TBM_GETLINESIZE, 0, 0L )

#define TrackBar_GetThumbRect( hWnd, lpRect )  \
  SendMessage( (HWND)hWnd, TBM_GETTHUMBRECT, 0, (LPARAM)(LPRECT)lpRect )

#define TrackBar_GetChannelRect( hWnd, lpRect )   \
  SendMessage( (HWND)hWnd, TBM_GETCHANNELRECT, (WPARAM)0, (LPARAM)(LPRECT)lpRect )

// Macros for UpDown Class.
#define UpDown_GetAccel( hWnd, Count, pAccels )			\
	(int)SendMessage( hWnd, UDM_GETACCEL, (WPARAM)Count, (LPARAM)(LPUDACCEL)pAccels )

#define UpDown_GetBase( hWnd )							\
	(int)SendMessage( hWnd, UDM_GETBASE, 0, 0L )

#define UpDown_GetBuddy( hWnd )							\
	(HWND)(UINT)SendMessage( hWnd, UDM_GETBUDDY, 0, 0L )

#define UpDown_GetPos( hWnd )							\
	(long)SendMessage( hWnd, UDM_GETPOS, 0, 0L )

#define UpDown_GetRange( hWnd )							\
	(long)SendMessage( hWnd, UDM_GETRANGE, 0, 0L )

#define UpDown_SetAccel( hWnd, Count, pAccel )			\
	(BOOL)SendMessage( hWnd, UDM_SETACCEL, (WPARAM)Count, (LPARAM)(LPUDACCEL)pAccel )

#define UpDown_SetBase( hWnd, NewBase )					\
	(int)SendMessage( hWnd, UDM_SETBASE, (WPARAM)NewBase, 0L )

#define UpDown_SetBuddy( hWnd, NewBuddy )				\
	(HWND)(UINT)SendMessage( hWnd, UDM_SETBUDDY, (WPARAM)(UINT)NewBuddy, 0L )

#define UpDown_SetPos( hWnd, NewPos )					\
	(int)SendMessage( hWnd, UDM_SETPOS, 0, MAKELPARAM( NewPos, 0 ) )

#define UpDown_SetRange( hWnd, nLower, nUpper )			\
	SendMessage( hWnd, UDM_SETRANGE, 0, MAKELPARAM( nUpper, nLower ) )


// End of macro declarations.


/*--------------------------------------------------------------------------*/
#endif  // ! _WDWIN95_H_
