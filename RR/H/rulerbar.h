// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   rulerbar.h  $
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
// $Log:   D:/R&R Project/archives/H/RULERBAR.H_V  $
// 
//    Rev 1.2   25 Aug 2004 07:54:00   Nick
// Version 10.5
// 
//    Rev 1.1   08 Oct 1996 16:50:18   amh
// Arp 1.0 U02 merged to trunk
// 
// 
// 
//    Rev 1.0.1.0   27 Jun 1996 12:12:46   par
// CRulerBar must inherit from CDialogBar and not CToolBar under VC4.1.  This is
// because VC4.1 uses the Win95 common controls to do the tool bar stuff.
// 
//    Rev 1.0   01 Dec 1995 13:40:38   par
// Rulers are now derived from CToolBar so that they don't get overwritten by OLE
// objects.
// 
// Initial revision.
// 
// ****************************************************************************

#ifndef __RULERBAR_H__
#define __RULERBAR_H__

/////////////////////////////////////////////////////////////////////////////
// CRulerBar window

class CRrDoc ;

class CRulerBar : public CDialogBar
{
	DECLARE_DYNAMIC(CRulerBar)
// Construction
public:
	CRulerBar();
	BOOL Create(CWnd* pParentWnd, CRrDoc* pDoc, DWORD dwStyle=CBRS_TOP) ;

// Attributes
protected:
	CRrDoc*    m_pDoc           ;
	CRulerBar* m_pOtherRuler1    ;  // The horz ruler needs to know if the vertical ruler dimensions. 
	CRulerBar* m_pOtherRuler2    ;  // The horz ruler needs to know if the vertical ruler dimensions. 
	DWORD      m_dwStyle        ;  // Keep a local version to be efficient. 
	int        m_nCaretLocation ;

protected:
	void DrawLine(CDC* pDC, int topX, int topY, int botX, int botY) ;
	void DrawTopHorzRuler(CDC* pDC, CRect& rectClip) ;
	void DrawBottomHorzRuler(CDC* pDC, CRect& rectClip) ;
	void DrawLeftVertRuler(CDC* pDC, CRect& rectClip) ;
	void DrawRightVertRuler(CDC* pDC, CRect& rectClip) ;

// Operations
public:
	void SetOtherRulers(CRulerBar* pOtherRuler1, CRulerBar* pOtherRuler2) { m_pOtherRuler1 = pOtherRuler1 ;m_pOtherRuler2 = pOtherRuler2 ;}
	void InvalidateMarker() ;
	void SetMarker(int x) ;
	void EditRuler() ;  // change ruler spacing

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRulerBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRulerBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRulerBar)
	afx_msg void OnPaint() ;
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point) ;
	afx_msg void OnRButtonDown  (UINT nFlags, CPoint point) ;
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // __RULERBAR_H__
/////////////////////////////////////////////////////////////////////////////
