// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   rulervw.h  $
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
// $Log:   D:/R&R Project/archives/H/RULERVW.H_V  $
// 
//    Rev 1.2   25 Aug 2004 07:54:00   Nick
// Version 10.5
// 
//    Rev 1.1   05 Dec 1995 18:06:52   par
// Ruler needs OnUpdate to prevent the wrong invalidation.
// 
//    Rev 1.0   01 Dec 1995 13:40:22   par
// Rulers are now derived from CToolBar so that they don't get overwritten by OLE
// objects.
// 
// Initial revision.
// 
// ****************************************************************************

#ifndef __RULERVW_H__
#define __RULERVW_H__

#include "rulerbar.h"  // CRulerBar

class CRrView ;

class CRulerView : public CView
{
protected: // create from serialization only
	CRulerView();
	DECLARE_DYNCREATE(CRulerView)
	
	CRrView*  m_pClientView  ;
// Attributes
public:
	CRulerBar m_wndTopHorzRuler ;
	CRulerBar m_wndBottomHorzRuler ;
	CRulerBar m_wndLeftVertRuler ;
	CRulerBar m_wndRightVertRuler ;
	
// Operations
public:
	void   ShowControlBar(CControlBar* pBar, BOOL bShow) ;
	CRrView* GetClientView() { return m_pClientView ; }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRulerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) ;
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRulerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRulerView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif // __RULERVW_H__
/////////////////////////////////////////////////////////////////////////////
