// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   ftextfld.h  $
// ================
//
// Description:
// ============
// For text field property page
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/ftextfld.h_v  $
// 
//    Rev 1.1   02 May 1997 11:23:50   par
// New Export property page for text and data fields.  This is where the HTML
// angle bracket flag is set.
// 
//    Rev 1.0   16 Nov 1995 16:15:32   sbc
// Initial revision.
// 
// ****************************************************************************

//
// Make a definition for this module.
//
#ifndef _FTEXTFLD_H_

#define _FTEXTFLD_H_

/////////////////////////////////////////////////////////////////////////////
// CTextPropDlg dialog

class CTextPropDlg : public FldPageBase
{
// Construction
public:
	CTextPropDlg(CRrDoc *, LPTSTR, UINT );

// Dialog Data
	//{{AFX_DATA(CTextPropDlg)
	CString	m_Text;
	//}}AFX_DATA
	char m_cSpaceDot;
	
// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);
	void OnTextChange();
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTextPropDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CTextPropDlg)
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CExportPropDlg dialog

class CExportPropDlg : public FldPageBase
{
// Construction
public:
	CExportPropDlg(CRrDoc *, LPTSTR, UINT );

// Dialog Data
	//{{AFX_DATA(CExportPropDlg)
	enum { IDD = IDD_FIELDPROP_PAGE_EXPORT };
	int  m_nAllowAngleBrackets ;
	//}}AFX_DATA
	
// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CExportPropDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CExportPropDlg)
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	afx_msg void OnFieldpropHtmlAngle();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif
