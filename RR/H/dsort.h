// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   dsort.h  $
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
#ifndef _DSORT_H_

#define _DSORT_H_

//  dgroup.h : header file
//

#include <afxpriv.h>
#include "appres.h"

/////////////////////////////////////////////////////////////////////////////
// SelectSFDlg dialog

class SelectSFDlg : public CDialog
{
// Construction
public:
	SelectSFDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(SelectSFDlg)
	enum			{ IDD = IDD_SELECT_GROUP_FIELD };
	CListControl	m_listctrl;
	CString			FName ;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	FLDID		SortGroupFID ;
	int			(*ck)(LPMFFIELD) ;
	int			TitleTextID ;
	CString		OKButton ;

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Implementation
private:
	CRrDoc	*m_pDoc;	// the ubiquitous document pointer

	void	ActiveFocusCommon(void);
	void	EnableButtons(void) ;
	void	SetName(void) ;
protected:
	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void	OnDestroy();
	// Generated message map functions
	//{{AFX_MSG(SelectSFDlg)
	virtual BOOL	OnInitDialog();
	virtual void	OnOK();
	virtual void	OnCancel();
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnRefresh(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	afx_msg void	OnNameChange();
	afx_msg void	OnNameSort();
	afx_msg void	OnItemDoubleClick(NMHDR* pNMHDR, LRESULT* pResult);

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif	// #ifndef _DINSFLD_H_
