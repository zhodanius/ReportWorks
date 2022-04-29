// xdrelatedialog.h: interface for the xdrelatedialog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XDRELATEDIALOG_H__B11148D3_605D_4D9B_A5B1_D8CF70A09582__INCLUDED_)
#define AFX_XDRELATEDIALOG_H__B11148D3_605D_4D9B_A5B1_D8CF70A09582__INCLUDED_

//#if _MSC_VER > 1000
//#pragma once
//#endif // _MSC_VER > 1000

//class xdrelatedialog  
//{
//public:
//	xdrelatedialog();
//	virtual ~xdrelatedialog();
//
//};

//#ifndef _DRELATE_C_

//#define _DRELATE_C_

//#include "ColorCtrl.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class xdrelateLinkField : public CPropertyPage
{
// Construction
public:
	xdrelateLinkField(CRrDoc *, UINT );
	PKREL		rs;

// Dialog Data
	//{{AFX_DATA(CExportOptions)
	int		change ;
// Implementation
public:
	void SavePage(void);
protected:
	CRrDoc *pDoc;
	void	OnChange(void) ;
	void	OnSelectLink();
	void	OnMakeCalcField();
//	void Initialize(void);
//	void OnOK(void) ;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMTotalAccum)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMTotalAccum)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class xdrelateRelatedTable : public CPropertyPage
{
// Construction
public:
	xdrelateRelatedTable(CRrDoc *, UINT );
	PKREL		rs;

// Dialog Data
	//{{AFX_DATA(CExportOptions)
	int		change ;
// Implementation
public:
	void SavePage(void);
protected:
	CRrDoc *pDoc;
	void	OnChange(void) ;
	void	OnGetRelateTable();
//	void Initialize(void);
//	void OnOK(void) ;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMTotalAccum)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMTotalAccum)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	afx_msg void	OnNameChange();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};///////////////////////////////////////////////////////////////////////////////////////////////////////////
class xdrelateRelatedIndex : public CPropertyPage
{
// Construction
public:
	xdrelateRelatedIndex(CRrDoc *, UINT );
	PKREL		rs;

// Dialog Data
	//{{AFX_DATA(CExportOptions)
	int		change ;
// Implementation
public:
	void SavePage(void);
protected:
	CRrDoc *pDoc;
	void	OnChange(void) ;
	void	OnGetIndex(void) ;
	void	OnEditKey(void) ;
	void	OnButtonPreDefind(void) ;
	void	OnButtonUserIndex(void) ;
	void	OnButtonRecNumber(void) ;
	void	OnTagChanged(void) ;
	
//	void Initialize(void);
//	void OnOK(void) ;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMTotalAccum)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMTotalAccum)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};///////////////////////////////////////////////////////////////////////////////////////////////////////////
class xdrelateRelateType : public CPropertyPage
{
// Construction
public:
	xdrelateRelateType(CRrDoc *, UINT );
	PKREL		rs;

// Dialog Data
	//{{AFX_DATA(CExportOptions)
	int		change ;
// Implementation
public:
	void SavePage(void);
protected:
	CRrDoc *pDoc;
	void	OnChange(void) ;
	void	OnButtonExact(void) ;
	void	OnButtonScan(void) ;
	void	OnButtonApprox(void) ;
//	void Initialize(void);
//	void OnOK(void) ;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMTotalAccum)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMTotalAccum)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};///////////////////////////////////////////////////////////////////////////////////////////////////////////
class xdrelateCharacterMatch : public CPropertyPage
{
// Construction
public:
	xdrelateCharacterMatch(CRrDoc *, UINT );
	PKREL		rs;

// Dialog Data
	//{{AFX_DATA(CExportOptions)
	int		change ;
//	int		autoSave;
	CString	m_szDPARTLEN05 ;
// Implementation
public:
	void SavePage(void);
protected:
	CRrDoc *pDoc;
	void	OnChange(void) ;
	void	OnButtonFull();
	void	OnButtonPartialLength();	
//	void Initialize(void);
//	void OnOK(void) ;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMTotalAccum)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMTotalAccum)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	afx_msg void	OnValueChange();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};///////////////////////////////////////////////////////////////////////////////////////////////////////////
class xdrelateFailureAction : public CPropertyPage
{
// Construction
public:
	xdrelateFailureAction(CRrDoc *, UINT );
	PKREL		rs;

// Dialog Data
	//{{AFX_DATA(CExportOptions)
	int		change ;
// Implementation
public:
	void SavePage(void);
protected:
	CRrDoc *pDoc;
	void	OnChange(void) ;
	void	OnButtonBlank();
	void	OnButtonSkip();
	void	OnButtonTerm();
//	void Initialize(void);
//	void OnOK(void) ;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMTotalAccum)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMTotalAccum)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class xdrelatedialog : public CPropertySheet
{
// Construction
public:
	xdrelatedialog (CRrDoc* pDoc, CWnd* pParent) ;
protected:
	// Dialog Data
	//{{AFX_DATA(CExport)
	CRrDoc *pDoc;
	CButton m_buttonClose ;
	//}}AFX_DATA

public:
//	void OnButtonJoinHelp();
	CButton m_buttonJoinHelp;
	PKREL		rs;


	xdrelateLinkField		*pageLinkField;
	xdrelateRelatedTable	*pageRelatedTable;
	xdrelateRelatedIndex	*pageRelatedIndex;
	xdrelateRelateType		*pageRelateType;
	xdrelateCharacterMatch	*pageCharacterMatch;
	xdrelateFailureAction	*pageFailureAction;

// Implementation
//	void HandleButtonJoinHelp(NMHDR *pHdr, LRESULT *pRes);
protected:
	virtual LRESULT WindowProc(UINT msg, WPARAM wp, LPARAM lp);
	virtual BOOL OnInitDialog() ;
//	virtual BOOL OnSetActive(void);
	// Generated message map functions
	//{{AFX_MSG(CMTotal)
	afx_msg void OnHelp();
	afx_msg void OnOk();
	afx_msg void OnCancel();
	afx_msg void OnButtonJoinHelp();
	afx_msg void OnDestroy();
//	afx_msg void OnWMPaint();
	afx_msg void OnWMNotify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // !defined(AFX_XDRELATEDIALOG_H__B11148D3_605D_4D9B_A5B1_D8CF70A09582__INCLUDED_)
