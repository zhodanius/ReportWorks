// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   preview.h  $
// ================
//
// Description:
// ============
//
// C++ preview header
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/PREVIEW.H_V  $
// 
//    Rev 1.13   Aug 12 2002 10:37:18   Admin
// Restart button for runtime
// 
//    Rev 1.12   03 Apr 1996 13:39:10   mjs
// Add flag to supress extraneous Invalidate on a NextPage
// 
//    Rev 1.11   09 Jan 1996 12:12:10   sbc
// New function
// 
//    Rev 1.10   27 Nov 1995 09:34:36   sbc
// Add funciton
// 
//    Rev 1.9   15 Nov 1995 16:48:40   sbc
// Back to using accelerators
// 
//    Rev 1.8   14 Nov 1995 10:40:52   sbc
// Add help function
// 
//    Rev 1.7   10 Nov 1995 10:06:28   sbc
// Add function
// 
//    Rev 1.6   08 Nov 1995 14:43:34   sbc
// Remove accelerator handle
// 
//    Rev 1.5   26 Oct 1995 16:32:20   sbc
// Add OnKeyDown()
// 
//    Rev 1.4   25 Sep 1995 14:08:32   sbc
// 
// Add routine to close window from close button (called from
// CMainFrame::OnClose()
// 
//    Rev 1.3   31 Jul 1995 14:42:48   pjm
// Include rrdoc.h.
// 
//    Rev 1.2   18 Jul 1995 11:20:26   sbc
// Changes for MFC classification
// 
//    Rev 1.1   11 Jul 1995 16:36:20   sbc
// Add module template
// 
// Initial revision.
// 
// ****************************************************************************

//
// Make a definition for this module.
//
#define _PREVIEW_H_

#include "rrdoc.h"

/////////////////////////////////////////////////////////////////////////////
// CPreview view

class CPreview : public CView
{
	DECLARE_DYNCREATE(CPreview)
//protected:
	CPreview();			// protected constructor used by dynamic creation
	virtual ~CPreview();

// Attributes
public:

// Operations
public:

// Implementation
	CToolBar			*m_pToolBar;
	CRect				m_RectTemp;
	CPrintPreviewState	*m_pPreviewState;
	BOOL				m_bPrintFromPreview;
	CRrDoc 				*m_pDoc;
private:
	BOOL				m_bMainMaxed;
	BOOL 				m_bOnLastPage;
	BOOL 				m_bPrevMaxed;
	BOOL 				m_bStopAtEndofPage;
	BOOL 				m_bWorking;
   BOOL				m_bNextPage;	// mjs 4/3/96
	HACCEL				m_hAccel;
	int 				m_LastPage;
	CPrevPgDlg 			*m_pPrevPgDlg;
	CRect 				m_rectPage;
   bool           miPrinted;
	
	virtual	void OnDraw(CDC* pDC);		// overridden to draw this view
	friend BOOL CRrDoc::createPreviewView(CMainFrame *pFrame);
	friend BOOL CRrDoc::printPreview(BOOL);

public:
	void waitAtEOP(BOOL);
	void dispPrevStatus(void);
	void dispPreviewPage(void);
	void ClosePreviewWindow(void);	// called from CMainFrame OnClose function
private:
	BOOL drawPage(CDC *, CRect *);
	void previewScroll(UINT, UINT, BOOL);
	void prevPrtDlgClose(void);
	void prevPrtPageDlg(void);
	UINT prevX(UINT x);
	void printCurrentPage(void);
	void setCursorShape(POINT);
	void setMinimumWindowWidth(void);
	void setPageSizes(void);
	void setScrollStuff(void);
	void setZoomPoint(POINT);

	// Generated message map functions
private:
	virtual void OnActivateView(BOOL bActivate, CView*, CView*);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual BOOL PreCreateWindow(CREATESTRUCT &pCreate);
	virtual BOOL PreTranslateMessage(MSG *);
	//{{AFX_MSG(CPreview)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHelp();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnPrintReport();
	afx_msg void OnUpdatePrintReport(CCmdUI* pCmdUI);
	afx_msg void OnRestart();
	afx_msg void OnUpdateRestart(CCmdUI* pCmdUI);
	afx_msg void OnPrintPage();
	afx_msg void OnUpdatePrintPage(CCmdUI* pCmdUI);
	afx_msg void OnPrevPage();
	afx_msg void OnUpdatePrevPage(CCmdUI* pCmdUI);
	afx_msg void OnFirstPage();
	afx_msg void OnUpdateFirstPage(CCmdUI* pCmdUI);
	afx_msg void OnNextPage();
	afx_msg void OnUpdateNextPage(CCmdUI* pCmdUI);
	afx_msg void OnPause();
	afx_msg void OnUpdatePause(CCmdUI* pCmdUI);
	afx_msg void OnStop();
	afx_msg void OnUpdateStop(CCmdUI* pCmdUI);
	afx_msg void OnZoomIn();
	afx_msg void OnUpdateZoomIn(CCmdUI* pCmdUI);
	afx_msg void OnZoomOut();
	afx_msg void OnUpdateZoomOut(CCmdUI* pCmdUI);
	afx_msg void OnLastPage();
	afx_msg void OnUpdateLastPage(CCmdUI* pCmdUI);
	afx_msg void OnCursorLeft();
	afx_msg void OnCursorBigLeft();
	afx_msg void OnCursorBigRight();
	afx_msg void OnCursorDown();
	afx_msg void OnEnd();
	afx_msg void OnHome();
	afx_msg void OnPageDown();
	afx_msg void OnPageUp();
	afx_msg void OnCursorRight();
	afx_msg void OnCursorUp();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
