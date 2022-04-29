// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   dtotal.h  $
// ================
//
// Description:
// ============
//
// Preferences property page
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===

// 
// ****************************************************************************

//
// Make a definition for this module.
//
#ifndef _DTOTAL_H_

#define _DTOTAL_H_

#include "ColorCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// Total Name Field dialog

class CTotalName : public CPropertyPage
{
// Construction
public:
	CTotalName(CRrDoc *, UINT );
	~CTotalName();

// Dialog Data
	//{{AFX_DATA(CTotalName)
	//}}AFX_DATA
	CRrDoc			*pDoc;
// Implementation
public:
private:
	CString	XFieldName ;
	HWND	hDlg ;
	HBRUSH	groupheader1Brush,
			groupheader2Brush,
			groupheader3Brush,
			groupfooter3Brush,
			groupfooter2Brush,
			groupfooter1Brush,
			summaryBrush,
			pgFooterBrush,
			bwBrush;

protected:
	void	MopUp() ;
	void	EnableOK(void);
	void	OnNameChange(void) ;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTotalName)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnOK(void) ;
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	virtual BOOL OnApply(void) ;
	virtual void OnCancel() ;
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CTotalName)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	afx_msg LRESULT OnColor(WPARAM wParam, LPARAM lParam);

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Total type dialog (now Target/type)

class CTotalType : public CPropertyPage
{
// Construction
public:
	CTotalType(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CTotalType)
	//}}AFX_DATA
	CRrDoc *pDoc;

// Implementation
public:
protected:
	CString	TargetName ;
	CString	TargetExpression ;
//	void	Initialize(void);
//	void	OnOK(void) ;
	void	EnableButtons(void) ;
	void	OnSelect(void) ;
	void	OnTypeChange(void) ;
	void	ShowExpression(void) ;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTotalType)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CTotalType)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#if 0

/////////////////////////////////////////////////////////////////////////////
// Total Target Fields dialog

class CTotalTarget : public CPropertyPage
{
// Construction
public:
	CTotalTarget(CRrDoc *, UINT );
private:
	void	EnableOK(void);

// Dialog Data
	//{{AFX_DATA(CExportOptions)
// Implementation
public:
	void SavePage(void);
protected:
	CString	TargetDescription ;
	CRrDoc *pDoc;
	CListControl	pFieldList ;
	void	OnChange(void) ;
//	void Initialize(void);
//	void OnOK(void) ;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTotalTarget)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
//	virtual BOOL OnApply(void) ;
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CTotalTarget)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	afx_msg LRESULT OnNewSelect(WPARAM wParam, LPARAM lParam) ;
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#endif

/////////////////////////////////////////////////////////////////////////////
// Total Reset dialog

class CTotalReset : public CPropertyPage
{
// Construction
public:
	CTotalReset(CRrDoc *, UINT );

	CColorCtrl<CButton>	m_radio00;
	CColorCtrl<CButton>	m_radio01;
	CColorCtrl<CButton>	m_radio02;
	CColorCtrl<CButton>	m_radio03;
	CColorCtrl<CButton>	m_radio04;
	CColorCtrl<CButton>	m_radio05;
	CColorCtrl<CButton>	m_radio06;
	CColorCtrl<CButton>	m_radio07;
	CColorCtrl<CButton>	m_radio08;
	CColorCtrl<CButton>	m_radio09;
	CColorCtrl<CButton>	m_radio10;

// Dialog Data
	//{{AFX_DATA(CTotalReset)
// Implementation
public:
	void SavePage(void);
protected:
	CRrDoc *pDoc;
	void	OnChange(void) ;
//	void Initialize(void);
//	void OnOK(void) ;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTotalReset)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnApply(void) ;
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CTotalReset)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Total Accumulation dialog

class CTotalAccum : public CPropertyPage
{
// Construction
public:
	CTotalAccum(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CTotalAccum)
// Implementation
public:
	void SavePage(void);
protected:
	CRrDoc *pDoc;
	void	OnChange(void) ;
//	void Initialize(void);
//	void OnOK(void) ;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMTotalAccum)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnApply(void) ;
//	virtual BOOL OnKillActive(void);
//	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMTotalAccum)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Total Processing dialog

class CTotalProcess : public CPropertyPage
{
// Construction
public:
	CTotalProcess(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CTotalProcess)
// Implementation
public:
	void SavePage(void);
protected:
	CRrDoc *pDoc;
//	void Initialize(void);
//	void OnOK(void) ;
	void	OnChange(void) ;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTotalProcess)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
//	virtual BOOL OnApply(void) ;
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMTotalProcess)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Total Condition dialog

class CTotalCondition : public CPropertyPage
{
// Construction
public:
	CTotalCondition(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CMTotalCondition)
// Implementation
public:
	void SavePage(void);
protected:
	CRrDoc *pDoc;
	void	OnEditCondition(void) ;
	void	OnDeleteCondition(void) ;
//	void Initialize(void);
//	void OnOK(void) ;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMTotalCondition)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnApply(void) ;
//	virtual BOOL OnKillActive(void);
//	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMTotalCondition)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
// Edit totals dialog

class CTotal : public CPropertySheet
{
// Construction
public:
	CTotal (int ids, CRrDoc* pDoc, CWnd* pParent) ;
protected:
	// Dialog Data
	//{{AFX_DATA(CExport)
	CButton m_buttonClose ;
	//}}AFX_DATA

public:
	CTotalName			*pageName ;
	CTotalType			*pageType ;
//	CTotalTarget		*pageTarget ;
	CTotalReset			*pageReset ;
	CTotalAccum			*pageAccum ;
	CTotalProcess		*pageProcess ;
	CTotalCondition		*pageCondition ;

// Implementation
protected:
	virtual BOOL OnInitDialog() ;
	// Generated message map functions
	//{{AFX_MSG(CMTotal)
	afx_msg void OnHelp();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

///////////////////////////////////////////////////////////////////////
// Reset Totals dialog

class CTotalsReset : public CDialog
{
// Construction
public:
	CTotalsReset(CWnd* pParent = NULL);	// standard constructor

	CColorCtrl<CButton>	m_radio00;
	CColorCtrl<CButton>	m_radio01;
	CColorCtrl<CButton>	m_radio02;
	CColorCtrl<CButton>	m_radio03;
	CColorCtrl<CButton>	m_radio04;
	CColorCtrl<CButton>	m_radio05;
	CColorCtrl<CButton>	m_radio06;
	CColorCtrl<CButton>	m_radio07;
	CColorCtrl<CButton>	m_radio08;
	CColorCtrl<CButton>	m_radio09;
	CColorCtrl<CButton>	m_radio10;
	CColorCtrl<CButton>	m_radio11;
	CColorCtrl<CButton>	m_radio12;
	CColorCtrl<CButton>	m_radio13;
	CColorCtrl<CButton>	m_radio14;
	CColorCtrl<CButton>	m_radio15;
	CColorCtrl<CButton>	m_radio16;
	CColorCtrl<CButton>	m_radio17;
	CColorCtrl<CButton>	m_radio18;
	CColorCtrl<CButton>	m_radio19;

// Dialog Data
	//{{AFX_DATA(CTotalsReset)
	enum	{ IDD = IDD_TOTALS_RESET_ALL };
	int		fromIndex ;
	int		toIndex ;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Implementation
private:
	CRrDoc	*pDoc;	// the ubiquitous document pointer

protected:
	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
//	virtual void	OnDestroy();
	// Generated message map functions
	//{{AFX_MSG(CTotalsOK)
	virtual BOOL	OnInitDialog();
	virtual void	OnOK();
//	virtual void	OnCancel();
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif