// pstatdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPStatDlg dialog

class CPStatDlg : public CDialog
{
// Construction
public:
	CPStatDlg(CWnd* pParent = NULL, BOOL bExporting = FALSE);	// our constructor

// Dialog Data
	//{{AFX_DATA(CPStatDlg)
	enum { IDD = IDD_PSTATDLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Implementation
	BOOL m_bExporting;
private:
	CRrDoc *m_pDoc;		// set at creation
	
	BOOL fieldfit(int id, LPSTR text);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void PostNcDestroy();

	// Generated message map functions
	//{{AFX_MSG(CPStatDlg)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	//}}AFX_MSG
	afx_msg LRESULT OnUserUpdatePage(WPARAM, LPARAM);
	afx_msg LRESULT OnUserUpdateRecords(WPARAM, LPARAM);
	afx_msg LRESULT OnUserUpdateCopies(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
};
