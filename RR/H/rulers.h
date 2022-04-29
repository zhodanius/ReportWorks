// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   rulers.h  $
// ================
//
// Description:
// ============
//
// Rulers property page
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===

// 
// ****************************************************************************

// page order
#define PAGE_SHOW			0
#define PAGE_SPACING		1

//
// Make a definition for this module.
//
#define _RULERS_H_


/////////////////////////////////////////////////////////////////////////////
// Rulers dialog

class Rulers : public CPropertySheet
{
// Construction
public:
	Rulers(UINT nIDCaption, CWnd* pParent, UINT iSelPage);

// Overrides
//	afx_msg void OnApplyNow();
// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(FldProp)
	afx_msg void OnHelp();	// help hander enables help button
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Show Rulers dialog

class CShowRulers : public RulersPageBase
{
// Construction
public:
	CShowRulers(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CShowRulers)
	int		ShowTH ;
	int		ShowBH ;
	int		ShowLV ;
	int		ShowRV ;
	//}}AFX_DATA
	
// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);
	BOOL onTabOrOK(void);
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CShowRulers)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CShowRulers)
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
// Ruler Spacing dialog

class CSpacingRulers : public RulersPageBase
{
// Construction
public:
	CSpacingRulers(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CSpacingRulers)
	enum { IDD = IDD_RULERS };
	//}}AFX_DATA
	
// Implementation
public:
	BOOL	m_bVertFocus;
	int		m_HorzSpacing;
	int		m_VertSpacing;
	void	SavePage(void);
protected:
	void	Initialize(void);
	BOOL	onTabOrOK(void);
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSpacingRulers)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
//	virtual BOOL OnKillActive(void);
//	virtual BOOL OnSetActive(void);
	virtual void OnOK();

	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CSpacingRulers)
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	afx_msg void OnHScroll(UINT, UINT, CScrollBar*);
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


