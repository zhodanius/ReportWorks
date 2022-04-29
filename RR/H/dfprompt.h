// ****************************************************************************
//
//		(C) Copyright 1996 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   dfprompt.h  $
// ================
//
// Description:
// ============
// Filter Prompt Dialog Class definition
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/dfprompt.h_v  $
// 
//    Rev 1.0   18 Apr 1998 18:06:18   jpb
// Initial revision.
// 
// 
// ****************************************************************************
//
// Make a definition for this module.
//
#ifndef _DFPROMPT_H_
#define _DFPROMPT_H_

#include "appres.h"

/////////////////////////////////////////////////////////////////////////////
// CFilterPromptDialog dialog

class CRrDoc ;

class CFilterPromptDialog : public CDialog
{
// Construction
public:
	CFilterPromptDialog(CRrDoc* pDoc, CWnd* pParent=NULL) ;   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFilterPromptDialog)
	enum { IDD = IDD_FILTER_PROMPT } ;
	CString      m_csPromptString ;
	//}}AFX_DATA
	
	CRrDoc* m_pDoc ;  // Need access to function. 

private:
	CEdit& ctlPrompt () { return *(CEdit *) GetDlgItem (IDC_FILTERPROMPT_PROMPT_STRING); }

// Helper functions
protected:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFilterPromptDialog)
	protected:
//	virtual void DoDataExchange(CDataExchange* pDX) ;  // DDX/DDV support
	virtual BOOL OnInitDialog() ;
	virtual void OnOK() ;
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFileSettingsDialog)
	afx_msg void OnHelp() ;
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam) ;
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
} ;

#endif // _DFILESET_H_
/////////////////////////////////////////////////////////////////////////////
