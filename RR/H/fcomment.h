// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   fcomment.h  $
// ================
//
// Description:
// ============
//
// Field comment property page
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/fcomment.h_v  $
// 
//    Rev 1.2   08 Nov 1995 11:59:34   sbc
// Apply button support
// 
//    Rev 1.1   07 Nov 1995 13:46:30   sbc
// Enable property sheet help
// 
//    Rev 1.0   06 Nov 1995 11:56:12   sbc
// Initial revision.
// 
// Initial revision.
// 
// ****************************************************************************

//
// Make a definition for this module.
//
#define _FCOMMENT_H_

// fcomment.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// FldComment dialog

class FldComment : public FldPageBase
{
// Construction
public:
	FldComment(CRrDoc *, LPTSTR, UINT);

// Dialog Data
	//{{AFX_DATA(FldComment)
	//}}AFX_DATA
protected:
	CString 	m_Comment;
	BOOL 		m_bDatabaseFld;
// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(FldComment)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(FldComment)
	afx_msg void OnControlChange();
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
