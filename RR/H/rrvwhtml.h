// ****************************************************************************
//
//      (C) Copyright 1997 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
// Defines HTML document preview.
//
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/rrvwhtml.h_v  $
// 
//    Rev 1.1   15 May 1997 09:55:14   hxc
// Added HTML preview.
// 
//    Rev 1.0   09 May 1997 10:11:12   amh
// Initial revision.
// ****************************************************************************
// RrVwHTML.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRrViewHTMLCode dialog

class CRrViewHTMLCode : public CDialog
{
// Construction
public:
	CRrViewHTMLCode(char* szTags, CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(CRrViewHTMLCode)
	enum { IDD = IDD_ACTX_VIEW_HTML_DLG };
	CString	m_csHTMLCode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRrViewHTMLCode)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRrViewHTMLCode)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
