// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   fcharfld.h  $
// ================
//
// Description:
// ============
//
// Character field width dialog
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/fcharfld.h_v  $
// 
//    Rev 1.6   08 Nov 1995 11:59:32   sbc
// Apply button support
// 
//    Rev 1.5   07 Nov 1995 13:46:28   sbc
// Enable property sheet help
// 
//    Rev 1.4   15 Sep 1995 16:15:02   par
// New UpDown controls require OnNotify processing and not OnVScroll.
// 
//    Rev 1.3   19 Jul 1995 17:01:14   sbc
// Add doc pointer to constructor
// 
//    Rev 1.2   19 Jul 1995 15:47:26   sbc
// Move doc pointer out of AFX_DATA section
// 
//    Rev 1.1   19 Jul 1995 15:41:22   sbc
// Add CRrDoc pointer
// 
// Initial revision.
// 
// ****************************************************************************

//
// Make a definition for this module.
//
#define _FCHARFLD_H_

// fcharfld.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCharWidth dialog

class CCharWidth : public FldPageBase
{
// Construction
public:
	CCharWidth(CRrDoc *, LPTSTR, UINT );

// Dialog Data
	//{{AFX_DATA(CCharWidth)
	int m_nInches;
	CString	m_szWidth;
	//}}AFX_DATA
	UINT m_nWidth;
	BOOL m_bCharsSelected;
	
// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);
	BOOL onTabOrOK(void);
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CCharWidth)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CCharWidth)
	afx_msg void OnCharacters();
	afx_msg void OnInches();
	afx_msg void OnWidthChange();
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
