// CValList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CValueList dialog

class CValueList : public CDialog
{
// Construction
public:
	CValueList(CRrDoc* pDoc, CWnd* pParent = NULL);   // standard constructor
	void freeLists();

// Dialog Data
	//{{AFX_DATA(CValueList)
	enum { IDD = IDD_VALUELISTS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	CRrDoc* m_pDoc ;  // Need access to function. 

private:
	int			m_ColCount;
	CObArray	m_ValLists;	//array of CObjLists of values for entries in column listbox
	BOOL		m_ValueChanged;

	CEdit& ctlMaxCount () { return *(CEdit *) GetDlgItem (IDC_MAXEDIT); }
	CEdit& ctlValueEdit () { return *(CEdit *) GetDlgItem (IDC_VALUEEDIT1); }
	CListBox& ctlColList () { return *(CListBox *) GetDlgItem (IDC_COLLIST); }
	CListBox& ctlValueList () { return *(CListBox *) GetDlgItem (IDC_VALUELIST); }
	CButton& ctlCaseCheck () { return *(CButton *) GetDlgItem (IDC_CASECHECK); }
	CStatic& ctlUniqueCountVal () { return *(CStatic *) GetDlgItem (IDC_UNIQUECOUNT); }
	CButton& ctlFetchButton () { return *(CButton *) GetDlgItem (IDC_FETCHBUTTON); }
	CButton& ctlAddButton () { return *(CButton *) GetDlgItem (IDC_ADDBUTTON); }
	CButton& ctlModifyButton () { return *(CButton *) GetDlgItem (IDC_MODIFYBUTTON); }
	CButton& ctlDeleteButton () { return *(CButton *) GetDlgItem (IDC_DELETEBUTTON); }
	CButton& ctlClearButton () { return *(CButton *) GetDlgItem (IDC_CLEARBUTTON); }

	void showValueList(CStringList *pStringList);
	void showValueListCount(void);

	CString getValueSelect(LPMFFIELD pFld, BOOL bUseDistinct);
	void getColAndTableNames(LPMFFIELD pFld);
	BOOL isDataValid(int iFldFlags, CString strEntry);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CValueList)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CValueList)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCollist();
	afx_msg void OnFetchbutton();
	afx_msg void OnSelchangeValuelist();
	afx_msg void OnDeletebutton();
	afx_msg void OnAddbutton();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnHelp() ;
	afx_msg void OnClearbutton();
	afx_msg void OnModifybutton();
	afx_msg void OnKillfocusMaxedit();
	afx_msg void OnKillfocusValueedit1();
	afx_msg void OnSetfocusValueedit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
