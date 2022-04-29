// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   rrunview.h  $
// ================
//
// Description:
// ============
//	 Runtime view header
// 
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/rrunview.h_v  $
// 
//    Rev 1.5   22 Dec 1995 09:38:36   jpb
// fix inline non-debug GetDocument()
// 
//    Rev 1.4   11 Dec 1995 12:04:32   par
// The runtime view does not need to know anything about ole objects.
// 
//    Rev 1.3   07 Dec 1995 10:29:22   par
// Removed all references to Field Rect in favor of Get Client Rect.  The goal was
// to reduce the number of variables used for the runtime.  Besides, with the 
// rulers now being windows, the field rect is always the client rect.
// 
//    Rev 1.2   06 Dec 1995 12:58:26   sjo
// Added runtime stuff.
// 
//    Rev 1.1   06 Dec 1995 09:48:12   sjo
// Runtime change.
// 
//    Rev 1.0   30 Nov 1995 18:21:12   sjo
// Initial revision.
// 
//
/////////////////////////////////////////////////////////////////////////////

class CRrDoc;

class CRrunView : public CView
{
protected: // create from serialization only
	CRrunView();
	DECLARE_DYNCREATE(CRrunView)

// Attributes
public:
	CRrDoc* GetDocument();
	CRrDoc	*m_pDoc;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRrunView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRrunView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRrunView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RRUNview.cpp
inline CRrDoc* CRrunView::GetDocument()
   { return (CRrDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
