// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   mainfrm.h  $
// ================
//
// Description:
// ============
//
// 
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/MAINFRM.H_V  $
// 
//    Rev 1.43.1.1   20 Sep 2004 13:41:16   Nick
// Tom Le
// 
//    Rev 1.43.1.0   May 09 2002 11:54:36   Admin
// Just to make a branch
// 
//    Rev 1.43   14 Mar 1997 15:36:04   SRM
// chart support initial checkin
// 
//    Rev 1.42   08 Oct 1996 16:49:54   amh
// Arp 1.0 U02 merged to trunk
// 
// 
// 
//    Rev 1.41.1.0   06 Aug 1996 13:24:48   par
// Fixed help problem by filtering out WM_HELP that Win95 is sending.
// VC 2.2 did not support it but VC 4.x does.  We don't want it.
// 
//    Rev 1.41   29 Mar 1996 14:37:44   jpb
// Add OnQueryOpen for runtime
// 
//    Rev 1.40   28 Mar 1996 18:30:48   jpb
// Add OnExit for runtime, to let you pick the runtime's
// main window's exit menu item if you're unlucky enough to
// see the main window
// 
//    Rev 1.39   12 Mar 1996 12:00:56   dlm
// Added bExiting to main-frame class so SaveModified can know if it is
//  being called on the way out of the product or for some other reason.
//  See also mainfrm.cpp, rrdoc.cpp, rrview.cpp.
// 
//    Rev 1.38   27 Feb 1996 15:16:30   mjs
// Moved splash function from CRrView class.
// 
//    Rev 1.37   15 Feb 1996 14:55:20   dlm
// Add OnUpdateFrameTitle() to CMainFrm class to take over title bar updating
//  from CFrameWnd.  Part of fix to RSW bug 2074.
// 
//    Rev 1.36   13 Feb 1996 16:33:44   sbc
// Move OnUpdateKeyIndicators out of interactive conditional
// 
//    Rev 1.35   13 Feb 1996 13:29:48   sbc
// New update handlers for help menu
// 
//    Rev 1.34   12 Feb 1996 10:41:58   par
// Added OnDropFiles to the runtime message map.
// 
//    Rev 1.33   31 Jan 1996 14:17:56   sbc
// Add m_hFormBarAccel accelerator handle and rename to OnEditChangePoints
// 
//    Rev 1.32   25 Jan 1996 15:48:36   sbc
// Make format bar function public
// 
//    Rev 1.31   13 Dec 1995 14:19:38   sbc
// Add support for WM_SETTINGCHANGE, which doesn't seem to work
// 
//    Rev 1.30   11 Dec 1995 13:25:50   sbc
// Runtime conditionals
// 
//    Rev 1.29   06 Dec 1995 15:47:58   sbc
// Add OnHelp()
// 
//    Rev 1.28   05 Dec 1995 10:30:56   sjo
// Use new CRrunView class for the runtime.
// 
//    Rev 1.27   21 Nov 1995 15:49:14   sbc
// Add function overrides for accelerator processing
// 
//    Rev 1.26   06 Nov 1995 16:07:18   par
// Toolbar can not be shown after being closed as a undocked window.
// 
//    Rev 1.25   03 Nov 1995 08:27:34   pjm
// Add argument to CreateToolBar function.
// 
//    Rev 1.24   01 Nov 1995 17:17:54   jpb
// add OnDisplayChange declaration
// 
//    Rev 1.23   24 Oct 1995 13:20:32   jpb
// add WM_DEVICECHANGE handler
// 
//    Rev 1.22   19 Oct 1995 15:50:36   sbc
// Remove some help message handlers
// 
//    Rev 1.21   13 Oct 1995 10:37:00   par
// Replace internal tooltips code with MFC code.
// 
//    Rev 1.20   12 Oct 1995 10:57:22   par
// Replaced internal MRU code with MFC code.
// 
//    Rev 1.19   09 Oct 1995 16:49:00   sbc
// Remove print setup function
// 
//    Rev 1.18   28 Sep 1995 08:16:12   sbc
// Wizard termination message handler moved here from rrview.h
// 
//    Rev 1.17   29 Aug 1995 10:13:56   sbc
// Comment out OnMinMaxInfo message handler
// 
//    Rev 1.16   16 Aug 1995 13:46:40   mjs
// Added ToolHelpReplace to fix wreport.cpp problem.
// 
//    Rev 1.15   27 Jul 1995 11:24:40   mjs
// Fixed error in RR dir.
// 
//    Rev 1.14   26 Jul 1995 14:19:36   mjs
// Added fixActiveState().
// 
//    Rev 1.13   26 Jul 1995 11:03:02   mjs
// Move zbusy to rrdoc.
// 
//    Rev 1.12   25 Jul 1995 15:44:44   mjs
// Moved zbusy here, since it deals with cursors.
// 
//    Rev 1.11   25 Jul 1995 10:06:18   smh
// Added MRU stuff from WREPORT
// 
//    Rev 1.10   19 Jul 1995 08:07:18   pjm
// Picked up stuff from global.h.
// 
//    Rev 1.9   17 Jul 1995 17:19:54   sbc
// Change to use R&R status bar class
// 
//    Rev 1.8   17 Jul 1995 14:13:30   mjs
// Tooltips fns and vars.
// 
//    Rev 1.7   12 Jul 1995 17:35:32   smh
// Removed rrview.h include.
// 
//    Rev 1.6   11 Jul 1995 12:54:46   sbc
// Changes for classification
// 
// Initial revision.
// 
// ****************************************************************************
//
// Make a definition for this module.
//
#define _MAINFRM_H_

// mainfrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////
#include "appres.h"
#include "bandview.h"
#include "rstatbar.h"
#include "wtools.h"
#include "pvpgdlg.h"
#include "preview.h"
#include "preprint.h"
#include "pstatdlg.h"
//tl
#if defined(INTERACTIVE)
#include "UndoPopup.h"
#endif
/////////////////////////////////////////////////////////////////////////////

#ifndef __AFXEXT_H__
#include <afxext.h>         // for access to CToolBar and CStatusBar
#endif

#define MIN_TOOLS 2	// Just show New and Open tools.

class CRrView;
class CRrunView;

class CMainFrame : public CFrameWnd
{
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
#if defined(RSW)
	BOOL bExiting;			// flag used to signal that we're exiting the product, normally false
#endif

	WORD ActiveState; 		// current mouse/keyboard state
	HCURSOR hHourGlass;		// handle to hourglass cursor
	HCURSOR hMainCursor;		// the arrow
	HCURSOR hPreviewCursor;	// preview zoom cursor
	HCURSOR hSaveCursor; 	// save old cursor
#if defined (INTERACTIVE)
	CBandView	*m_pBandView;	// the band view
	CRrView		*m_pFieldView;	// the field view
	CSplitterWnd m_wndSplitter;
	int PrefToolHelp;  // Keep this one.  It might be used later. 
	HCURSOR hBoxCursor;		// for drawing boxes
	HCURSOR hCrossCursor;	// for sizing/moving
	HCURSOR hHorzCursor;		// for sizing
	HCURSOR hImgCursor;		// for outlining images
	HCURSOR hChartCursor;		// for outlining charts
	HCURSOR hLineCursor;		// for drawing lines
	HCURSOR hMoveCursor;		// for moving fields
	HCURSOR hNECursor;		// for sizing/moving northeast (Westborough)
	HCURSOR hNWCursor;		// for sizing/moving	northwest (Redmond)
	HCURSOR hVertCursor;		// for sizing
	HFONT BarFont;				// font for font/pts combos in Format Bar
	HWND BarFontWnd;			// font combo in Format Bar
	HWND BarPtsWnd;			// point size combo in Format Bar
	UINT	uContextHelp;	// context-sensitive help value

	void GetToolBarRect(CRect *prect);

	//tl
	CUndoPopup* m_pUndo;
	void add_toolbar_arrow(CToolBar* pToolbar, int command);

	BOOL CreateToolBar(BOOL bUpdate);
	BOOL CreateFormBar();
  	BOOL ComboDropped();
	void ShowToolBar(BOOL show);
	void ShowFormBar(BOOL show);
	void fixActiveState(void);
	// Access functions now that bstate, Tools, etc. are private.
	void ToolStateSet(int tool, int state) {m_wndFormBar.ToolStateSet(tool,state);}
	void BarFontChange(void) {m_wndFormBar.BarFontChange();}
	void FormatBarEnable(void) {m_wndFormBar.Enable();}
	int BoldStateGet() {return m_wndFormBar.BoldStateGet();}
	int ItalicStateGet() {return m_wndFormBar.ItalicStateGet();}
	int UnderStateGet() {return m_wndFormBar.UnderStateGet();}
	virtual BOOL PreCreateWindow(CREATESTRUCT &pCreate);
	virtual BOOL PreTranslateMessage(MSG *);

public:  // control bar embedded members
	CToolBar    m_wndToolBar;
	CFormBar    m_wndFormBar;
private:
	HACCEL	m_hAccel;	// main accelerator handle
	HACCEL	m_hFormBarAccel;	// for format bar combos

#else	// Runtime below
public:
	CRrunView	*m_pFieldView;

#endif	// #if defined (INTERACTIVE)

public:
	CPreview	*m_pPrevView;	// the preview view
	RrStatusBar  m_wndStatusBar;
	CPrePrintDlg *m_pPrePrintDlg;// sort/merge status
	CPStatDlg *m_pPStatDlg;		// print page/record count
	LPCSTR m_lpszSplashClass;		// our very own class name
	CWnd *m_pSplashWnd;			// the (very) temporary splash window

// Operations
public:
	void OnUpdateKeyIndicator(CCmdUI* pCmdUI);
	void showMainWindow(void);
	void statusText(LPSTR lpszText);
	void displaySplashImage(BOOL bShow);

// Overrides
//tl
//   virtual BOOL OnNotify (WPARAM wParam, LPARAM lParam, LRESULT* pResult);

#if defined(RSW)
	// Try overriding this so WE have control over what is on our title bar
	void OnUpdateFrameTitle(BOOL bAddToTitle);
#endif

protected:

// Implementation
public:
	virtual ~CMainFrame();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// OnEditChangeFont() was added by CAS on 2/20/2014
// Generated message map functions
protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	afx_msg LRESULT OnDeviceChange(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDisplayChange(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSettingChange(WPARAM, LPARAM);
	afx_msg void OnEndSession(BOOL bEnding);
	afx_msg BOOL OnQueryEndSession();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnTimer(UINT nIDEvent);
#if defined (INTERACTIVE)
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnActivateApp(BOOL bActive, HTASK hTask);
	afx_msg void OnPaletteChanged(CWnd* pFocusWnd);
	afx_msg BOOL OnQueryNewPalette();
	afx_msg void OnSysColorChange();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnWinIniChange(LPCSTR lpszSection);
	afx_msg void OnFontChange();
	afx_msg void OnHelp();
	afx_msg void OnHelpIndex();
	afx_msg void OnHelpAbout();
	afx_msg void OnUpdateFormbar(CCmdUI* pCmdUI);
	afx_msg BOOL OnChangeFormbar(UINT nID);
	afx_msg void OnUpdateViewFormatbar(CCmdUI* pCmdUI);
	afx_msg BOOL OnViewFormatBar(UINT nID);
	afx_msg BOOL OnViewToolBar(UINT nID);
	afx_msg void OnSelChangeFont();
	afx_msg void OnEditChangeFont();
	afx_msg void OnSelEndOKFont();
	afx_msg void OnSetFocusFont();
	afx_msg void OnKillFocusFont();
	afx_msg void OnEditChangePoints();
	afx_msg void OnSetFocusPoints();
	afx_msg void OnKillFocusPoints();
	afx_msg void OnDblClickPoints();
	afx_msg LRESULT OnWizardTerminate(WPARAM wParam, LPARAM lParam);
	afx_msg void OnUpdateTrue(CCmdUI* pCmdUI);
	afx_msg void OnUpdateHelpTopics( CCmdUI* );
	afx_msg void OnUpdateHelpAbout( CCmdUI* );
	afx_msg BOOL OnHelpInfo(HELPINFO* lpHelpInfo);  // VC++ 4.x WM_HELP.  Ignore messages. 
public:
	afx_msg void OnSelEndOKPoints();
protected:
   afx_msg void OnToolbarDropDown (NMTOOLBAR* pnmh, LRESULT* plRes);
#else
	afx_msg void OnPreviewReport();
	afx_msg void OnExit();
	afx_msg BOOL OnQueryOpen();
#endif
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
