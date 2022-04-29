/*****************************************************************************\
*                                                                             *
* winextra.h -  These macros were removed from the ntg w16\windowsx.h 		  *
*				The ntg w16\windowsx.h no longer exists.  This must be 		  *
*				will be included with process.h								  *
*																			  *
\*****************************************************************************/


#ifndef _INC_WINEXTRA
#define _INC_WINEXTRA

#ifndef RC_INVOKED
#pragma pack(1)         /* Assume byte packing throughout */
#endif  /* RC_INVOKED */

#ifdef __cplusplus
extern "C" {            /* Assume C declarations for C++ */
#endif  /* __cplusplus */


#define ListBox_SetAnchorIndex(hwndCtl, index)      ((void)SendMessage((hwndCtl), LB_SETANCHORINDEX, (WPARAM)(int)(index), 0L))            /* ;Internal */
#define ListBox_GetAnchorIndex(hwndCtl)             ((int)(DWORD)SendMessage((hwndCtl), LB_GETANCHORINDEX, 0, 0L))                        /* ;Internal */
#define ListBox_AddFile(hwndCtl, lpszFilename)      ((int)(DWORD)SendMessage((hwndCtl), LB_ADDFILE, 0, (LPARAM)(LPCSTR)(lpszFilename)))    /* ;Internal */


/****** Alternate porting layer macros ****************************************/

/* USER MESSAGES: */

#define GET_WPARAM(wp, lp)                      (wp)
#define GET_LPARAM(wp, lp)                      (lp)

#define GET_WM_ACTIVATE_STATE(wp, lp)               (wp)
#define GET_WM_ACTIVATE_FMINIMIZED(wp, lp)          (BOOL)HIWORD(lp)
#define GET_WM_ACTIVATE_HWND(wp, lp)                (HWND)LOWORD(lp)
#define GET_WM_ACTIVATE_MPS(s, fmin, hwnd)   \
        (WPARAM)(s), MAKELONG(hwnd, fmin)

#define GET_WM_CHARTOITEM_CHAR(wp, lp)              (CHAR)(wp)
#define GET_WM_CHARTOITEM_POS(wp, lp)               HIWORD(lp)
#define GET_WM_CHARTOITEM_HWND(wp, lp)              (HWND)LOWORD(lp)
#define GET_WM_CHARTOITEM_MPS(ch, pos, hwnd) \
        (WPARAM)(ch), MAKELONG(hwnd, pos)

#define GET_WM_COMMAND_ID(wp, lp)                   (wp)
#define GET_WM_COMMAND_HWND(wp, lp)                 (HWND)LOWORD(lp)
#define GET_WM_COMMAND_CMD(wp, lp)                  HIWORD(lp)
#define GET_WM_COMMAND_MPS(id, hwnd, cmd)    \
        (WPARAM)(id), MAKELONG(hwnd, cmd)

#define WM_CTLCOLORMSGBOX       0x0132
#define WM_CTLCOLOREDIT         0x0133
#define WM_CTLCOLORLISTBOX      0x0134
#define WM_CTLCOLORBTN          0x0135
#define WM_CTLCOLORDLG          0x0136
#define WM_CTLCOLORSCROLLBAR    0x0137
#define WM_CTLCOLORSTATIC       0x0138

#define GET_WM_CTLCOLOR_HDC(wp, lp, msg)            (HDC)(wp)
#define GET_WM_CTLCOLOR_HWND(wp, lp, msg)           (HWND)LOWORD(lp)
#define GET_WM_CTLCOLOR_TYPE(wp, lp, msg)           HIWORD(lp)
#define GET_WM_CTLCOLOR_MPS(hdc, hwnd, type) \
        (WPARAM)(hdc), MAKELONG(hwnd, type)


#define GET_WM_MENUSELECT_CMD(wp, lp)               (wp)
#define GET_WM_MENUSELECT_FLAGS(wp, lp)             LOWORD(lp)
#define GET_WM_MENUSELECT_HMENU(wp, lp)             (HMENU)HIWORD(lp)
#define GET_WM_MENUSELECT_MPS(cmd, f, hmenu)  \
        (WPARAM)(cmd), MAKELONG(f, hmenu)

// Note: the following are for interpreting MDIclient to MDI child messages.
#define GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wp, lp)  (BOOL)(wp)
#define GET_WM_MDIACTIVATE_HWNDDEACT(wp, lp)        (HWND)HIWORD(lp)
#define GET_WM_MDIACTIVATE_HWNDACTIVATE(wp, lp)     (HWND)LOWORD(lp)
// Note: the following is for sending to the MDI client window.
#define GET_WM_MDIACTIVATE_MPS(f, hwndD, hwndA)\
        (WPARAM)(hwndA), 0

#define GET_WM_MDISETMENU_MPS(hmenuF, hmenuW) 0, MAKELONG(hmenuF, hmenuW)

#define GET_WM_MENUCHAR_CHAR(wp, lp)                (CHAR)(wp)
#define GET_WM_MENUCHAR_HMENU(wp, lp)               (HMENU)LOWORD(lp)
#define GET_WM_MENUCHAR_FMENU(wp, lp)               (BOOL)HIWORD(lp)
#define GET_WM_MENUCHAR_MPS(ch, hmenu, f)    \
        (WPARAM)(ch), MAKELONG(hmenu, f)

#define GET_WM_PARENTNOTIFY_MSG(wp, lp)             (wp)
#define GET_WM_PARENTNOTIFY_ID(wp, lp)              HIWORD(lp)
#define GET_WM_PARENTNOTIFY_HWNDCHILD(wp, lp)       (HWND)LOWORD(lp)
#define GET_WM_PARENTNOTIFY_X(wp, lp)               (INT)LOWORD(lp)
#define GET_WM_PARENTNOTIFY_Y(wp, lp)               (INT)HIWORD(lp)
#define GET_WM_PARENTNOTIFY_MPS(msg, id, hwnd) \
        (WPARAM)(msg), MAKELONG(hwnd, id)
#define GET_WM_PARENTNOTIFY2_MPS(msg, x, y) \
        (WPARAM)(msg), MAKELONG(x, y)

#define GET_WM_VKEYTOITEM_CODE(wp, lp)              (wp)
#define GET_WM_VKEYTOITEM_ITEM(wp, lp)              (INT)HIWORD(lp)
#define GET_WM_VKEYTOITEM_HWND(wp, lp)              (HWND)LOWORD(lp)
#define GET_WM_VKEYTOITEM_MPS(code, item, hwnd) \
        (WPARAM)(code), MAKELONG(hwnd, item)

#define GET_EM_SETSEL_START(wp, lp)                 LOWORD(lp)
#define GET_EM_SETSEL_END(wp, lp)                   HIWORD(lp)
#define GET_EM_SETSEL_MPS(iStart, iEnd) \
        0, MAKELONG(iStart, iEnd)

#define GET_EM_LINESCROLL_MPS(vert, horz)     \
        0, MAKELONG(vert, horz)

#define GET_WM_CHANGECBCHAIN_HWNDNEXT(wp, lp)       (HWND)LOWORD(lp)

#define GET_WM_HSCROLL_CODE(wp, lp)                 (wp)
#define GET_WM_HSCROLL_POS(wp, lp)                  LOWORD(lp)
#define GET_WM_HSCROLL_HWND(wp, lp)                 (HWND)HIWORD(lp)
#define GET_WM_HSCROLL_MPS(code, pos, hwnd)    \
        (WPARAM)(code), MAKELONG(pos, hwnd)

#define GET_WM_VSCROLL_CODE(wp, lp)                 (wp)
#define GET_WM_VSCROLL_POS(wp, lp)                  LOWORD(lp)
#define GET_WM_VSCROLL_HWND(wp, lp)                 (HWND)HIWORD(lp)
#define GET_WM_VSCROLL_MPS(code, pos, hwnd)    \
        (WPARAM)(code), MAKELONG(pos, hwnd)

#ifndef RC_INVOKED
#pragma pack()          /* Revert to default packing */
#endif  /* RC_INVOKED */

#ifdef __cplusplus
}                       /* End of extern "C" { */
#endif  /* __cplusplus */

#endif  /* !_INC_WINEXTRA */
