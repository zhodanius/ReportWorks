// ****************************************************************************
//
//		(C) Copyright 1996 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   dfileset.h  $
// ================
//
// Description:
// ============
// RulerDlg Class definition
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/DFILESET.H_V  $
// 
//    Rev 1.1   Feb 28 2002 10:59:08   Admin
// Remove Dictionary folder settings
// 
//    Rev 1.0   22 Jan 1996 18:07:16   par
// The template library has changed to a template directory.  Removed references
// to the last library.
// 
// Initial revision.
// 
// ****************************************************************************
//
// Make a definition for this module.
//
#ifndef _DFILESET_H_
#define _DFILESET_H_

#include "appres.h"

#define EXTLEN		3


/////////////////////////////////////////////////////////////////////////////
// CFileSettingsDialog dialog

class CRrDoc ;

class CFileSettingsDialog : public CDialog
{
// Construction
public:
	CFileSettingsDialog(CRrDoc* pDoc, CWnd* pParent=NULL) ;   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFileSettingsDialog)
	enum { IDD = IDD_DEFAULT_FILE_SETTINGS } ;
	char      m_szDataDirectory[WINPATHLEN+1]     ;
//	char      m_szReportDictionary[WINPATHLEN+1]  ;
	char      m_szImageDirectory[WINPATHLEN+1]    ;
	char      m_szLookupDirectory[WINPATHLEN+1] ;
	char      m_szTemplateDirectory[WINPATHLEN+1] ;
	char      m_szReportDirectory[WINPATHLEN+1]   ;
//	char      m_szDictionaryIndex[WINPATHLEN+1]   ;
	char      m_szImageExtension[EXTLEN+1]        ;
	char      m_szIndexExtension[EXTLEN+1]        ;
	char      m_szTextExtension[EXTLEN+1]         ;
	//}}AFX_DATA
	CComboBox m_cbImageExtension                  ;
	CComboBox m_cbTextExtension                   ;
	CComboBox m_cbIndexExtension                  ;
	
	CRrDoc* m_pDoc ;  // Need access to function. 

// Helper functions
protected:
	void SetExtensionList(int ctrl_id, WORD str_id) ;
	int  CheckIfThere() ;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileSettingsDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX) ;  // DDX/DDV support
	virtual BOOL OnInitDialog() ;
	virtual void OnOK() ;
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFileSettingsDialog)
	afx_msg void OnFileSettingsDataBrowse()   ;
	afx_msg void OnFileSettingsReportBrowse() ;
	afx_msg void OnFileSettingsImageBrowse()  ;
	afx_msg void OnFileSettingsTemplateBrowse()  ;
	afx_msg void OnFileSettingsLookupBrowse()  ;
//	afx_msg void OnFileSettingsReportDictionaryBrowse() ;
//	afx_msg void OnFileSettingsDictionaryIndexBrowse()  ;
	afx_msg void OnHelp() ;
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam) ;
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
} ;

#endif // _DFILESET_H_
/////////////////////////////////////////////////////////////////////////////
