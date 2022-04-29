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
// Rev 1.00    17 Oct 2013 14:53:10   CAS
// Added message handler constructor for WM_SIZE message; new capability to flexibly
//  resize all insert field dialogs throughout the program
// 
// ****************************************************************************

//
// Make a definition for this module.
//
#ifndef _DFDATA_H_

#define _DFDATA_H_

#include <afxpriv.h>
#include "appres.h"
#include <afxdtctl.h>

/////////////////////////////////////////////////////////////////////////////
// SelectSFDlg dialog

class CSelectDBDataDlg : public CDialog
{
// Construction
public:
	CSelectDBDataDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(SelectSFDlg)
	enum			{ IDD = IDD_INSERT_DB_FIELD };
	CString			FName ;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	int			(*ck)(LPMFFIELD) ;
	int			FieldType;


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
	afx_msg void	OnNameChange();
	afx_msg void	OnNameSort();
	afx_msg void	OnItemClick			(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg LRESULT OnSize(UINT nType, int cx, int cy);
	afx_msg void	OnItemDoubleClick	(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnKeyDown			(NMLVKEYDOWN* pKey, LRESULT* pResult);

	//}}AFX_MSG
    afx_msg void OnCustomdrawList(NMHDR*, LRESULT*);
	DECLARE_MESSAGE_MAP()
};

#endif
