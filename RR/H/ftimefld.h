// ftimefld.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTimeFld dialog

class CTimeFld : public FldPageBase
{
// Construction
public:
	CTimeFld(CRrDoc *, LPTSTR, UINT);	// constructor

// Dialog Data
	//{{AFX_DATA(CTimeFld)
	int		m_nTimeIndex;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	
// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);

	void showSample();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnSetActive(void);

	UINT getTimePictureIndex(UINT nPicture);
	// Generated message map functions
	//{{AFX_MSG(CTimeFld)
	afx_msg void OnTimeChange();
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
