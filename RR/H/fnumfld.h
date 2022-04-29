// fnumfld.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNumPicture dialog

class CNumPicture : public FldPageBase
{
// Construction
public:
	CNumPicture(CRrDoc *, LPTSTR, UINT);

// Dialog Data
	//{{AFX_DATA(CNumPicture)
	//}}AFX_DATA
	
// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);
	void commonIntDecChange(void);
	void displaySample(void);

	int m_nIntegers;
	int m_nDecimals;
	int m_nShowZero;
	int m_nLeadingZero;
	int m_nFormatIndex;

	BOOL badPrecision(int nIntegers, int nDecimals, int bTrans1, int bTrans2);
	BOOL onTabOrOK(void);
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CNumPicture)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CNumPicture)
	afx_msg void OnPictureChange();
	afx_msg void OnFormatChange();
	afx_msg void OnDecimalChange();
	afx_msg void OnIntegerChange();
	afx_msg void OnLeadZero();
	afx_msg void OnShowZero();
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

