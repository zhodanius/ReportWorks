// pvpgdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPrevPgDlg dialog

class CPrevPgDlg : public CDialog
{
// Construction
public:
	CPrevPgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPrevPgDlg)
	enum { IDD = IDD_PREVPGDLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
private:
	CRrDoc *m_pDoc;		// set at creation
// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void PostNcDestroy();

	// Generated message map functions
	//{{AFX_MSG(CPrevPgDlg)
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
