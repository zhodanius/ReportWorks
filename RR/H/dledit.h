// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   dledit.h  $
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
#ifndef _DLEDIT_H_

#define _DLEDIT_H_

/////////////////////////////////////////////////////////////////////////////
// Band Line Properties Type page

class CBandLineType : public CPropertyPage
{
// Construction
public:
	CBandLineType(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CBandLineType)
	//}}AFX_DATA
	CRrDoc			*pDoc;
// Implementation
public:
private:
	void	OnChecks(void) ;
protected:

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CBandLineType)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnOK(void) ;
	virtual BOOL OnInitDialog();
//	virtual BOOL OnKillActive(void);
//	virtual BOOL OnSetActive(void);
//	virtual BOOL OnApply(void) ;
//	virtual void OnCancel() ;
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CBandLineType)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
//	afx_msg void	OnDestroy();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Band Line Properties Height page

class CBandLineHeight : public CPropertyPage
{
// Construction
public:
	CBandLineHeight(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CBandLineHeight)
	//}}AFX_DATA
	CRrDoc			*pDoc;
// Implementation
public:
private:
	void	OnChangeAuto(void) ;
	void	OnChangeUnits(void) ;
	void	EnableButtons(void) ;
	int		inchesPoints(void) ;

protected:

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CBandLineHeight)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//	virtual void OnOK(void) ;
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
//	virtual BOOL OnSetActive(void);
//	virtual BOOL OnApply(void) ;
//	virtual void OnCancel() ;
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CBandLineHeight)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
//	afx_msg void	OnDestroy();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Band Line Properties Condition page

class CBandLineCondition : public CPropertyPage
{
// Construction
public:
	CBandLineCondition(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CBandLineCondition)
	//}}AFX_DATA
	CRrDoc			*pDoc;
// Implementation
public:
private:

	void	EnableButtons(void) ;
	void	OnCalc(void) ;
	void	OnSelect(void) ;
	void	OnClear(void) ;

protected:

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CBandLineCondition)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//	virtual void OnOK(void) ;
	virtual BOOL OnInitDialog();
//	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
//	virtual BOOL OnApply(void) ;
//	virtual void OnCancel() ;
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CBandLineCondition)
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	afx_msg void	OnDestroy();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
// Band line Properties dialog

class CBandLineProperties : public CPropertySheet
{
// Construction
public:
	CBandLineProperties (int id, CRrDoc* pDoc, CWnd* pParent) ;
protected:
	// Dialog Data
	//{{AFX_DATA(CExport)
	CButton m_buttonClose ;
	//}}AFX_DATA

public:
	CBandLineType		*pageType ;
	CBandLineHeight		*pageHeight ;
	CBandLineCondition	*pageCondition ;

// Implementation
protected:
	virtual BOOL OnInitDialog() ;
	// Generated message map functions
	//{{AFX_MSG(CBandLineProperties)
	afx_msg void OnHelp();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

#endif
