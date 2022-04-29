// fdatefld.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDatePicture dialog

class CDatePicture : public FldPageBase
{
// Construction
public:
	CDatePicture(CRrDoc *, LPTSTR, UINT);

// Dialog Data
	//{{AFX_DATA(CDatePicture)
	int		m_nDateIndex;
	//}}AFX_DATA

// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);

	void showSample();

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDatePicture)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CDatePicture)
	afx_msg void OnPictureChange();
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

