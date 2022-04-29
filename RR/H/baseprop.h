// baseprop.h : header file
//

#ifndef _BASEPROP_H_
#define _BASEPROP_H_

#include "apidef.h"

#define _IDOK			1
#define _IDCANCEL		2
#define _IDHELP			4
#define _IDAPPLYNOW 	8

/////////////////////////////////////////////////////////////////////////////
// CBasePropertySheet

//class CBasePropertySheet : public CWDPropertySheet
class CBasePropertySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CBasePropertySheet)

// Construction
public:
	CBasePropertySheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0, UINT nButtonFlags = _IDOK|_IDCANCEL);
	CBasePropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0, UINT nButtonFlags = _IDOK|_IDCANCEL);

// Attributes
public:
	void GetRectPosition(int id, RECT *rect);
	BOOL PositionButton(HWND hWnd, RECT *rect);

protected:
	UINT m_ButtonFlags;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBasePropertySheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBasePropertySheet();

// Overridables (special message map entries)
	virtual BOOL OnInitDialog();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBasePropertySheet)
	afx_msg BOOL OnNcCreate(LPCREATESTRUCT);
	afx_msg long OnHelp ( UINT, long );
	afx_msg LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

////////////////////////////////////////////////////////////////////////////
// CBasePropertyPage -- one page of a tabbed dialog

class CBasePropertyPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CBasePropertyPage)

// Construction
public:
	CBasePropertyPage(UINT nIDTemplate, UINT nIDCaption = 0);
	CBasePropertyPage(LPCTSTR lpszTemplateName, UINT nIDCaption = 0);
	CBasePropertyPage();

// Attributes

// Operations

// Overridables
public:

// Implementation
public:
	virtual ~CBasePropertyPage();

	// Generated message map functions
	//{{AFX_MSG(CPropertyPage)
	afx_msg long OnHelp ( UINT, long );
	afx_msg LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CBaseDialog - a modal or modeless dialog

class CBaseDialog : public CDialog
{
	DECLARE_DYNAMIC(CBaseDialog)

	// Modeless construct
public:
	CBaseDialog();

	// Modal construct
public:
	CBaseDialog(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	CBaseDialog(UINT nIDTemplate, CWnd* pParentWnd = NULL);

	~CBaseDialog();

// Overridables (special message map entries)
	virtual BOOL OnInitDialog();

protected:
	// Generated message map functions
	//{{AFX_MSG(CMDIMainFrame)
	afx_msg virtual void OnHelp ( void );
//	afx_msg long OnHelp ( UINT, long );
	afx_msg LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif	// _BASEPROP_H
