// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   dflex.h  $
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
#ifndef _DFLEX_H_

#define _DFLEX_H_

//  dflex.h : header file
//

#include <afxpriv.h>
#include "appres.h"

/////////////////////////////////////////////////////////////////////////////
// SelectSFDlg dialog

class CInsertDBFieldDlg : public CDialog
{
// Construction
public:
	CInsertDBFieldDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(SelectSFDlg)
	enum			{ IDD = IDD_INSERT_DB_FIELD };
	CString			FName ;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Implementation
private:
	CRrDoc		*pDoc;				// the ubiquitous document pointer
	CListCtrl	*flist ;
	int			findex ;
	int			fCount ;
	void		EnableButtons(void) ;
	void		SetName(void) ;
	void		SetSelected(void) ;
protected:
	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	// Generated message map functions
	//{{AFX_MSG(SelectSFDlg)
	virtual BOOL	OnInitDialog();
	virtual void	OnOK();
	virtual void	OnCancel();
	LRESULT			OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnRefresh(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	afx_msg LRESULT OnSize(UINT nType, int cx, int cy);
	afx_msg void	OnNameChange();
	afx_msg void	OnNameSort();
	afx_msg void	OnItemClick			(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnItemDoubleClick	(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnKeyDown			(NMLVKEYDOWN* pKey, LRESULT* pResult);

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif
