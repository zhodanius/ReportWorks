// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   dtotals.h  $
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
#ifndef _DTOTALS_H_

#define _DTOTALS_H_

#include "ColorCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// Totals OK dialog

class CTotalsOK : public CDialog
{
// Construction
public:
	CTotalsOK(CWnd* pParent = NULL);	// standard constructor
	~CTotalsOK(void) ;
// Dialog Data
	//{{AFX_DATA(CTotalsOK)
	enum			{ IDD = IDD_MTOTAL_OK };
	CString			comment ;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Implementation
private:
	CRrDoc		*pDoc;	// the ubiquitous document pointer
	CListCtrl	*flist ;
	CImageList	*pImageListSmall;
	int			findex ;
	int			ListCount ;

protected:
	int			IsOK(LPMFFIELD f,
						LPMFFIELD tf,
						int ttype,
						int reset, 
						int accum,
						int process) ;
	void		SetSelected(void) ;

	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
//	virtual void	OnDestroy();
	// Generated message map functions
	//{{AFX_MSG(CTotalsOK)
	virtual BOOL	OnInitDialog();
	virtual void	OnOK();
//	virtual void	OnCancel();
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	afx_msg void	OnItemClick			(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnKeyDown			(NMLVKEYDOWN* pKey, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Multiple Total Select Fields dialog

class CMTotalSelect : public CPropertyPage
{
// Construction
public:
	CMTotalSelect(CRrDoc *, UINT );
	~CMTotalSelect(void) ;

// Dialog Data
	//{{AFX_DATA(CMTotalSelect)
	//}}AFX_DATA
	CRrDoc			*pDoc;
	CListControl	pFromList ;	
	CListControl	pToList ;	
	CString			expression ;
// Implementation
public:
private:
	FLDID	FromFID ;
	FLDID	ToFID ;
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
//	void	Initialize(void);
	virtual void OnOK(void) ;
	virtual BOOL OnApply(void) ;
	void	OnAdd(void) ;
	void	OnRemove() ;
	void	showExpression(void) ;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMTotalSelect)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
//	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMTotalSelect)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	afx_msg LRESULT OnColor(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnNewSelect(WPARAM wParam, LPARAM lParam) ;

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Multiple Total type dialog

class CMTotalType : public CPropertyPage
{
// Construction
public:
	CMTotalType(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CMTotalType)
	int		type ;
	//}}AFX_DATA
	CRrDoc *pDoc;

// Implementation
public:
protected:
//	void	Initialize(void);
//	void	OnOK(void) ;
	void	OnTypeChange(void) ;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMTotalType)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMTotalType)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
// Multiple Total Target Fields dialog

class CMTotalTarget : public CPropertyPage
{
// Construction
public:
	CMTotalTarget(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CExportOptions)
	int		change ;
// Implementation
public:
	void SavePage(void);
protected:
	CRrDoc *pDoc;
	void	OnChange(void) ;
	void	OnSelectField(void) ;
//	void Initialize(void);
//	void OnOK(void) ;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMTotalTarget)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMTotalTarget)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Multiple Total Reset dialog

class CMTotalReset : public CPropertyPage
{
// Construction
public:
	CMTotalReset(CRrDoc *, UINT );

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
	//{{AFX_DATA(CExportOptions)
	int		change ;
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
	//{{AFX_VIRTUAL(CMTotalReset)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMTotalReset)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Multiple Total Accumulation dialog

class CMTotalAccum : public CPropertyPage
{
// Construction
public:
	CMTotalAccum(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CExportOptions)
	int		change ;
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

/////////////////////////////////////////////////////////////////////////////
// Multiple Total Processing dialog

class CMTotalProcess : public CPropertyPage
{
// Construction
public:
	CMTotalProcess(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CMTotalProcess)
	int		change ;
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
	//{{AFX_VIRTUAL(CMTotalProcess)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMTotalProcess)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Multiple Total Condition dialog

class CMTotalCondition : public CPropertyPage
{
// Construction
public:
	CMTotalCondition(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CMTotalCondition)
	int		condition ;
// Implementation
public:
	void SavePage(void);
protected:
	CRrDoc *pDoc;
	void	OnCheckCondition(void) ;
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
//	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMTotalCondition)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
// Edit Multiple totals dialog

class CMTotal : public CPropertySheet
{
// Construction
public:
	CMTotal (CRrDoc* pDoc, CWnd* pParent) ;
protected:
	// Dialog Data
	//{{AFX_DATA(CExport)
	CButton m_buttonClose ;
	//}}AFX_DATA

public:
	CMTotalSelect		*pageSelect ;
	CMTotalType			*pageType ;
	CMTotalTarget		*pageTarget ;
	CMTotalReset		*pageReset ;
	CMTotalAccum		*pageAccum ;
	CMTotalProcess		*pageProcess ;
	CMTotalCondition	*pageCondition ;

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

#endif