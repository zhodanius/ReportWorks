// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   prefs.h  $
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

// page order
#define PAGE_DISPLAY		0
#define PAGE_FILE_NEW		1
#define PAGE_MEMO_EDITOR	2
#define PAGE_DATA_SOURCE	2
#define PAGE_FIELD_LISTS	3
#define PAGE_AUTO_SAVE		4

//
// Make a definition for this module.
//
#define _PREFS_H_


/////////////////////////////////////////////////////////////////////////////
// Preferences dialog

class Prefs : public CPropertySheet
{
// Construction
public:
	Prefs( CRrDoc * m_pDoc, UINT nIDCaption, CWnd* pParent, UINT iSelPage);

// Overrides
//	afx_msg void OnApplyNow();
// Implementation
protected:
	CRrDoc *pDoc ;
	// Generated message map functions
	//{{AFX_MSG(FldProp)
	afx_msg void OnHelp();	// help hander enables help button
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Display Preferences dialog

class CDisplayPrefs : public PrefsPageBase
{
// Construction
public:
	CDisplayPrefs(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CDisplayPrefs)
	int		HSBar ;
	int		VSBar ;
	int		CBands ;
	int		CTotals ;
	//}}AFX_DATA
	
// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);
	BOOL onTabOrOK(void);
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDisplayPrefs)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CDisplayPrefs)
	afx_msg void OnHelp();
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
// File New Preferences dialog

class CFileNewPrefs : public PrefsPageBase
{
// Construction
public:
	CFileNewPrefs(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CFileNewPrefs)
	int		newPref ;
	//}}AFX_DATA
	
// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);
	BOOL onTabOrOK(void);
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CFileNewPrefs)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CFileNewPrefs)
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



#ifndef RSW
/////////////////////////////////////////////////////////////////////////////
// Memo Editor Preferences dialog

class CMemoEditPrefs : public PrefsPageBase
{
// Construction
public:
	CMemoEditPrefs(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CMemoEditPrefs)
	int		memoEditor;
	//}}AFX_DATA
	
// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);
	BOOL onTabOrOK(void);
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMemoEditPrefs)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMemoEditPrefs)
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif

#ifdef RSW
/////////////////////////////////////////////////////////////////////////////
// Memo Editor Preferences dialog

class CDataSourcePrefs : public PrefsPageBase
{
// Construction
public:
	CDataSourcePrefs(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CDataSourcePrefs)
	int		newReports;
	int		openReports;
	//}}AFX_DATA
	
// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);
	BOOL onTabOrOK(void);
	void OnNewButton() ;
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDataSourcePrefs)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CDataSourcePrefs)
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#endif



/////////////////////////////////////////////////////////////////////////////
// Field Lists Preferences dialog

class CFieldListsPrefs : public PrefsPageBase
{
// Construction
public:
	CFieldListsPrefs(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CDisplayPrefs)
	int		showDD;
	int		sortFieldNames;
	//}}AFX_DATA
	
// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);
	BOOL onTabOrOK(void);
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CCharWidth)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CCharWidth)
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
// Auto Save Preferences dialog

class CAutoSavePrefs : public PrefsPageBase
{
// Construction
public:
	CAutoSavePrefs(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CDisplayPrefs)
	int		autoSave;
	CString	autoSaveMin ;
	//}}AFX_DATA
	
// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);
	BOOL onTabOrOK(void);
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CCharWidth)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CCharWidth)
	afx_msg void OnAutoSave();
	afx_msg void OnTimeChange();
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


