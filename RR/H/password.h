// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   password.h  $
// ================
//
// Description:
// ============
//
// PasswordDLg Class definition
//
// Modification History
// ====================
//
// 
// Initial revision.
// 
// ****************************************************************************
//
// Make a definition for this module.
//
#ifndef _PASSWORD_H_

#define _PASSWORD_H_

#include "appres.h"

/////////////////////////////////////////////////////////////////////////////
// RulerDlg dialog

class PasswordDlg : public CDialog
{
// Construction
public:
	PasswordDlg(CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(PasswordDlg)
	CString	DPass ;
	CString	RPass ;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Implementation
private:
	CRrDoc	*m_pDoc;	// the ubiquitous document pointer
public:

protected:
	// Generated message map functions
	//{{AFX_MSG(PasswordDlg)
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnTyping(void) ;
	LRESULT OnCommandHelp(WPARAM, LPARAM);
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif	// #ifndef _DRULER_H_
