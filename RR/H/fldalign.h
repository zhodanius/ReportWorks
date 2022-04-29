// fldalign.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFldAlign dialog

class CFldAlign : public FldPageBase
{
// Construction
public:
	CFldAlign(CRrDoc *, LPTSTR, UINT);

// Dialog Data
	//{{AFX_DATA(CFldAlign)
	int		m_nWrapCheck;
	int		m_nAlign;
	int		m_nTrim;
	//}}AFX_DATA
	BOOL m_bWrapEnabled;
	UINT m_nTrimCount;
	UINT m_nLeftCount;
	UINT m_nCenterCount;
	UINT m_nRightCount;
	UINT m_nWrapCount;
	
	void Initialize();
	void SavePage();
	void setCharControlValues( LPFLDHDR );
	void setDateControlValues( LPFLDHDR );
	void setNumericControlValues( LPFLDHDR );
	void setTextControlValues( LPFLDHDR );

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CFldAlign)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CFldAlign)
	afx_msg void OnControlChange();
	afx_msg void OnWrapCheck();
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
