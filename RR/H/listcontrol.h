// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   listcontrol.h  $
// ================
//
// Description:
// ============
//
// Class definition
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// 
// ****************************************************************************

//
// Make a definition for this module.
//
#ifndef _LISTCONTROL_H_

#define _LISTCONTROL_H_

#include <afxpriv.h>
#include "appres.h"
#include "cfmisc.h"

//  listcontrol.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CListControl 

class CListControl : public CListCtrl
{
// Construction
public:
	CListControl();

// Attributes
public:
	FLDID	SelectFID ;			// currently selected FID or NOID
	int		ListCount ;			// length of list shown
	bool	AllowDrag ;			// true if dragging allowed
	CString	FName ;				// string in the Go To box
	FLDID	*FIDList ;			// list truncated for FName

private:
	FLDID	*BigFIDList ;		// original list of FIDs
	int		findex ;			// index into FIDList of selected item
	int		Sort ;				// sort direction
	CRrDoc	*pDoc ;
	int		nColumns ;			// 3 or 4 
	bool	dragging ;			// dragging is ongoing
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListControl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListControl();
//	void    OnButtonUp(CPoint point);
	void	Initialize	(CRrDoc *pDoc, int (*ck)(LPMFFIELD),
							FLDID InitFID, int ncols, int (*sck)(FLDID **) = NULL) ;
	void	Rebuild		(int (*ck)(LPMFFIELD)) ;
	bool	SetName		(const char *s) ;
	void	AddFID		(FLDID fid) ;
	void	DeleteFID	(FLDID fid) ;
	void	ItemClick	(NMHDR* pNMHDR);
	void	ColumnClick	(NMHDR* pNMHDR) ;
	bool	ItemDoubleClick(NMHDR* pNMHDR);
#if defined(INTERACTIVE)
	void	BeginDrag	(NMHDR* pNMHDR) ;
#endif
	void	Reset		(void) ;
	void	Notify		(WPARAM wParam, LPARAM lParam) ;
private:
	void	DisplayFieldList(void) ;
	void	ReSort		(int n) ;
	void	SetSelected	(void) ;
	void	SetUnSelected(void) ;
	void	notifyParent	(void) ;

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyListCtrl)
	virtual void	OnDestroy		();
	afx_msg void	OnColumnClick	(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnItemClick		(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg bool	OnItemDoubleClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnBeginDrag		(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnMouseMove		(UINT nFlags, CPoint point);
	afx_msg void	OnLButtonUp		(UINT nFlags, CPoint point);
	afx_msg void	OnRButtonDown	(UINT nFlags, CPoint point);
	afx_msg void	OnKeyDown		(NMLVKEYDOWN* pKey, LRESULT* pResult);

//	afx_msg void OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnActivate(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
// CUDFListControl for udf's

class CUDFListControl : public CListCtrl
{
// Construction
public:
	CUDFListControl();

// Attributes
public:
//	BOOL            m_bDragging;
//	int             m_iItemDrag;
//	int             m_iItemDrop;
//	CPoint          m_ptHotSpot;
//	CPoint          m_ptOrigin;
//	CSize           m_sizeDelta;
//	DWORD			m_oldDNDStyle;
//	CImageList      *m_pimageListDrag;
	LPUDF	SelectUDF ;
	int		ListCount ;
	CString	FName ;

private:
	LPUDF	*BigUDFList ;
	LPUDF	*UDFList ;
	int		Sort ;
	int		findex ;
	CRrDoc	*pDoc ;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUDFListControl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUDFListControl();
//	void    OnButtonUp(CPoint point);
	void	Initialize(CRrDoc *pDoc) ;
	void	Rebuild() ;
	bool	SetName(const char *s) ;
	void	ItemClick(NMHDR* pNMHDR);
	bool	ItemDoubleClick(NMHDR* pNMHDR);
	void	ColumnClick(NMHDR* pNMHDR);
	void	Reset(void) ;
private:
	int		BuildUDFList(LPUDF **ulist) ;
	int		CullUDFList(LPUDF *uslist, LPUDF **udlist, const char *name) ;
	void	SortUDFList(LPUDF *ulist, int sort) ;
	int		dtUDF(LPUDF u) ;
	void	DisplayUDFList(void) ;
	void	ReSort(int n) ;
	void	SetSelected(void) ;
	void	SetUnSelected(void) ;

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyListCtrl)
	virtual void	OnDestroy			();
	afx_msg void	OnColumnClick		(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnItemClick			(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg bool	OnItemDoubleClick	(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnKeyDown			(NMLVKEYDOWN* pKey, LRESULT* pResult);
//	afx_msg void OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnBeginrdrag(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnColumnClick(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnActivate(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnItemClick(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

#endif