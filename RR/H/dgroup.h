// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   dgroup.h  $
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
#ifndef _DGROUP_H_

#define _DGROUP_H_

//  dgroup.h : header file
//

#include "appres.h"

/////////////////////////////////////////////////////////////////////////////
// SelectGFDlg dialog

class SelectGFDlg : public CDialog
{
// Construction
public:
	SelectGFDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(SelectGFDlg)
	enum { IDD = IDD_SELECT_GROUP_FIELD };
	int		findex ;
	CString	FName ;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	FLDID	*SelectGroupFIDList ;
	FLDID	SelectGroupFID ;
	int		SelectCount ;
	int		Sort ;				// -1: Not sorted
								// 0,1: Name Sort (up, down)
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Implementation
private:
	CRrDoc	*m_pDoc;	// the ubiquitous document pointer

	void	ActiveFocusCommon(void);
	void	EnableButtons(void) ;
	void	displayFieldList(void) ;
	void	SetSelected(void) ;
	void	SetName(void) ;
	void	ReSort(int n) ;
protected:
	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void	OnDestroy();
	// Generated message map functions
	//{{AFX_MSG(SelectGFDlg)
	virtual BOOL	OnInitDialog();
	virtual void	OnOK();
	virtual void	OnCancel();
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnRefresh(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	afx_msg void	OnListChange();
	afx_msg void	OnNameChange();
	afx_msg void	OnNameSort();
	afx_msg void	OnFileSort();
	afx_msg void	OnTypeSort();
	afx_msg void	OnOriginSort();
	afx_msg void	OnListDblClick();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif	// #ifndef _DINSFLD_H_
