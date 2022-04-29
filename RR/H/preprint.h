// ..\..\h\preprint.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPrePrintDlg dialog

class CPrePrintDlg : public CDialog
{
// Construction
public:
	CPrePrintDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPrePrintDlg)
	enum { IDD = IDD_PREPRINT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Implementation
	int m_LabelID1;
	int m_LabelID2;
	int m_LabelID3;
	int m_TitleID;
	LPSTR m_pCount1;
	LPSTR m_pCount2;
	LPSTR m_pCount3;

	void setPrePrintInfo(int, int, int, int, LPSTR, LPSTR, LPSTR);
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void PostNcDestroy();
	// Generated message map functions
	//{{AFX_MSG(CPrePrintDlg)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	//}}AFX_MSG
	afx_msg LRESULT OnUserUpdate(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
};
