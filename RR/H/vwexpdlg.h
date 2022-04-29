//****************************************************************************
//
//	VWEXPDLG.H - Header for dialog to export PDI (for Report Viewer Control)
//
//		(C) Copyright 1996 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
// 
//

#define _VWEXPDLG_H_

/////////////////////////////////////////////////////////////////////////////
// ViewExpDlg dialog

class ViewExpDlg : public CDialog
{
// Construction
public:
	ViewExpDlg ( CRrDoc *pDoc, CWnd* pParent = NULL );
private:
	CRrDoc		*m_pDoc;	// Doc pointer

	// Dialog Data
	//{{AFX_DATA(ViewExpDlg)
	enum { IDD = IDD_PDI_EXPORT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ViewExpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
private:
	void	checkPath( BOOL );
	void	setExpOLEFlag();
protected:
	// Generated message map functions
	//{{AFX_MSG(ViewExpDlg)
	//}}AFX_MSG
	virtual BOOL OnInitDialog();
	afx_msg void OnExport();
	afx_msg void OnClose();
	afx_msg void OnCreateDoc();
	afx_msg void OnHelp();
	afx_msg void OnCancel();
	DECLARE_MESSAGE_MAP()
};
