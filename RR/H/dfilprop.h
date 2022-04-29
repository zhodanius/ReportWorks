// ****************************************************************************
//
//      (C) Copyright 1995 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $WorkFile$   dfilprop.h $
// ================
//
// Description:
// ============
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/dfilprop.h_v  $
// 
//    Rev 1.2   29 Feb 1996 15:55:56   par
// Add On Command Help support so that F1 would work in dialogs.  OnHelp() in the 
// main frame must call the CWnd version in order for F1 to work in MFC style 
// dialogs.
// 
//    Rev 1.1   14 Dec 1995 11:53:54   par
// Corrected the useage of ReportName and Title.  The Title in this instance is a
// user specified title and is not related to the Title variable in the MFC document.
// 
//    Rev 1.0   11 Dec 1995 11:08:18   par
// Replaced report summary with file properties dialog.
// 
// 
// ****************************************************************************

#ifndef __FILEPROP_H__
#define __FILEPROP_H__

/////////////////////////////////////////////////////////////////////////////
// CFilePropertiesDialog dialog

class CFilePropertiesDialog : public CDialog
{
// Construction
public:
	CFilePropertiesDialog(CWnd* pParent=NULL) ;   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFilePropertiesDialog)
	enum { IDD = IDD_FILE_PROPERTIES } ;
	CString m_csReportName ;
	CString	m_csComment    ;
	CString	m_csAuthor     ;
	CString	m_csKeywords   ;
	CString	m_csTitle      ;
	CString	m_csSubject    ;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFilePropertiesDialog)
protected:
	virtual void DoDataExchange(CDataExchange* pDX) ;    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFilePropertiesDialog)
	virtual BOOL OnInitDialog() ;
	afx_msg void OnHelp() ;
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam) ;
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
} ;

#endif // __FILEPROP_H__
/////////////////////////////////////////////////////////////////////////////
