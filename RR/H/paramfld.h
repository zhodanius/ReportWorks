#if !defined(AFX_PARAMFLD_H__B195DD01_4CA1_11D2_997E_0000F6AB05CB__INCLUDED_)
#define AFX_PARAMFLD_H__B195DD01_4CA1_11D2_997E_0000F6AB05CB__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ParamFld.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CParamFld dialog

class CParamFld : public CDialog
{
// Construction
public:
	CParamFld(CRrDoc* pDoc, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CParamFld)
	enum { IDD = IDD_DPARAM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	CRrDoc* m_pDoc ;  // Need access to function. 


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParamFld)
	//}}AFX_VIRTUAL

// Implementation
private:
	CButton& ctlOK () { return *(CButton *) GetDlgItem (IDOK); }
	CButton& ctlCharType () { return *(CButton *) GetDlgItem (IDC_CHAR); }
	CButton& ctlNumType () { return *(CButton *) GetDlgItem (IDC_NUM); }
	CButton& ctlLogicalType () { return *(CButton *) GetDlgItem (IDC_LOGICAL); }
	CButton& ctlDateType () { return *(CButton *) GetDlgItem (IDC_DATE); }
	CButton& ctlDateTimeType () { return *(CButton *) GetDlgItem (IDC_DATETIME); }
	CButton& ctlTimeType () { return *(CButton *) GetDlgItem (IDC_TIME); }
	CEdit& ctlName () { return *(CEdit *) GetDlgItem (IDC_NAME); }
	CEdit& ctlPrompt () { return *(CEdit *) GetDlgItem (IDC_PROMPT); }
	BOOL ParamSpecComplete(void);

protected:

	// Generated message map functions
	//{{AFX_MSG(CParamFld)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeName();
	afx_msg void OnChangePrompt();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARAMFLD_H__B195DD01_4CA1_11D2_997E_0000F6AB05CB__INCLUDED_)
