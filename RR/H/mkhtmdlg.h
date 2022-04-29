//****************************************************************************
//
//	MKHTMDLG.H - Header for dialog to create PDI Export HTML Document
//
//		(C) Copyright 1996 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
// 
//

/////////////////////////////////////////////////////////////////////////////
// MakeHTMLDlg dialog

class MakeHTMLDlg : public CDialog
{
// Construction
public:
	MakeHTMLDlg( CRrDoc *, LPSTR, CWnd* pParent = NULL );
private:
	CRrDoc		*m_pDoc;
	CString		m_csDefName;	// default filename passed in

// Dialog Data
	//{{AFX_DATA(MakeHTMLDlg)
	enum { IDD = IDD_CREATE_HTML };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MakeHTMLDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
private:
	BOOL	verifyDimension( int, LPSTR );
protected:
	// Generated message map functions
	//{{AFX_MSG(MakeHTMLDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
