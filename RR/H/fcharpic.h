// ****************************************************************************
//
//		(C) Copyright 2001 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   fcharpic.h  $
// ================
//
// Description:
// ============
//
// Character field picture dialog
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===

// 
// Initial revision.
// 
// ****************************************************************************

//
// Make a definition for this module.
//
#define _FCHARPIC_H_

// fcharpic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCharPic dialog

class CCharPic : public FldPageBase
{
// Construction
public:
	CCharPic(CRrDoc *, LPTSTR, UINT );

// Dialog Data
	//{{AFX_DATA(CCharPic)
	//}}AFX_DATA
	int		m_nDisplay ;
	bool	m_bDisplayString ;
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
//	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CCharWidth)
	afx_msg void OnDisplayString();
	afx_msg void OnDisplayImage();
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
