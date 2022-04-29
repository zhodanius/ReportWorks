// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
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
#ifndef _DSELECT_H_

#define _DSELECT_H_

//  dgroup.h : header file
//

#include <afxpriv.h>
#include "appres.h"

/////////////////////////////////////////////////////////////////////////////
// SelectSFDlg dialog

class CSelectFieldDlg : public CDialog
{
// Construction
public:
	CSelectFieldDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSelectFieldDlg)
	enum			{ IDD = IDD_SELECT_GROUP_FIELD };
	CListControl	listctrl;
	CString			FName ;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	FLDID		SelectFID ;
	int			(*ck)(LPMFFIELD) ;
	int			TitleTextID ;
	int			HelpCode ;
	CString		OKButton ;

// Implementation
private:
	CRrDoc	*pDoc;			// the ubiquitous document pointer

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
	afx_msg LRESULT OnNewSelect(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSize(UINT nType, int cx, int cy);
	afx_msg void	OnHelp();
	afx_msg void	OnNameChange();
	afx_msg void	OnNameSort();
	afx_msg void	OnItemDoubleClick(NMHDR* pNMHDR, LRESULT* pResult);

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif	// #ifndef _DSELECT_H_
