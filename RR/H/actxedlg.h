
// ****************************************************************************
//
//      (C) Copyright 1997 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
// This class defines custom modal property sheet and property pages:
// CRrActXViewExpDlg, CRrActXInputFilePage, and CRrActXObjTagPage.
//
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/ACTXEDLG.H_V  $
// 
//    Rev 1.5   Aug 14 2001 11:51:26   nhubacker
// Add CreateHTMLdocument()
// 
//    Rev 1.4   30 May 1997 17:24:44   hxc
// Added Viewer Control size variables to the INI file.
// 
//    Rev 1.3   20 May 1997 15:47:52   hxc
// Improve the defaut setup.
// 
//    Rev 1.2   15 May 1997 16:39:08   hxc
// Added checkLocation function.
// 
//    Rev 1.1   15 May 1997 09:39:12   hxc
// Added more functions for r?w.ini I/O.
// 
//    Rev 1.0   12 May 1997 10:11:12   amh
// Initial revision.
// ****************************************************************************
// ActXEDlg.h : header file
//
 
#ifndef __ACTXEDLG_H__
#define __ACTXEDLG_H__
#include "rrdoc.h"

/////////////////////////////////////////////////////////////////////////////
// CRrActXInputFilePage dialog

class CRrActXInputFilePage : public CPropertyPage
{
	DECLARE_DYNCREATE(CRrActXInputFilePage)

private:
	CRrDoc		*m_pDoc;	// Doc pointer

// Construction
public:
	CRrActXInputFilePage(CRrDoc *pDoc = NULL);
	~CRrActXInputFilePage();

	BOOL OnInitDialog();

// Dialog Data
	//{{AFX_DATA(CRrActXInputFilePage)
	enum { IDD = IDD_ACTX_INPUT_FILE_DLG };
	CString	m_csInputFileName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CRrActXInputFilePage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	void WriteInputFileDirToIni();
	void ReadInputFileDirFromIni();

private:
	BOOL	checkPath( BOOL );
	void	setExpOLEFlag();
	void	CreateHTMLDocument();

protected:
	// Generated message map functions
	//{{AFX_MSG(CRrActXInputFilePage)
	afx_msg void OnExportPDI();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CRrActXObjTagPage dialog

class CRrActXObjTagPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CRrActXObjTagPage)

private:
	CRrDoc		*m_pDoc;	// Doc pointer

// Construction
public:
	CRrActXObjTagPage(CRrDoc *pDoc = NULL);
	~CRrActXObjTagPage();

	BOOL OnInitDialog();
	
// Dialog Data
	//{{AFX_DATA(CRrActXObjTagPage)
	enum { IDD = IDD_ACTX_OBJ_TAG_DLG };
	CString	m_csCabinet;
	CString	m_csHTMLDoc;
	CString	m_csPDIFile;
	CString	m_csImagePath;
	int		m_nHeight;
	int		m_nWidth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CRrActXObjTagPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL checkLocations();
	char* getHTMLTags();
	void WriteHTMLDirToIni();
	void ReadHTMLDirFromIni();
	void WriteInputLocToIni();
	void ReadInputLocFromIni();
	void WriteCtrlLocToIni();
	void ReadCtrlLocFromIni();
	void WriteImageLocToIni();
	void ReadImageLocFromIni();
	void WriteViewerCtlSize();
	void ReadViewerCtlSize();

protected:
	// Generated message map functions
	//{{AFX_MSG(CRrActXObjTagPage)
	afx_msg void OnButtonViewHtml();
	afx_msg void OnCreateHTMLDocument();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CRrActXViewExpDlg

class CRrActXViewExpDlg : public CPropertySheet
{
	DECLARE_DYNAMIC(CRrActXViewExpDlg)

// Construction
public:
	CRrActXViewExpDlg(CRrDoc *pDoc, CWnd* pParentWnd = NULL);

// Attributes
public:
	CRrActXInputFilePage m_PageInputFile;
	CRrActXObjTagPage m_PageObjTag;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRrActXViewExpDlg)
	public:
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRrActXViewExpDlg();

// Generated message map functions
protected:
	//{{AFX_MSG(CRrActXViewExpDlg)
		// NOTE - the ClassWizard will add and remove member functions here.
	afx_msg void OnHelp();
	afx_msg void OnApply();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif	// __ACTXEDLG_H__
