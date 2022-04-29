// ****************************************************************************
//
//		(C) Copyright 2001 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   dreplace.h  $
// ================
//
// Description:
// ============
//
// ReplaceDlg Class definition
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:
//
// Make a definition for this module.
//
#ifndef _DREPLACE_H_

#define _DREPLACE_H_

//  dreplace.h : header file
//

#include "appres.h"


/////////////////////////////////////////////////////////////////////////////
// ReplaceDlg dialog

class ReplaceDlg : public CDialog
{
// Construction
public:
	ReplaceDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(ReplaceDlg)
	enum { IDD = IDD_REPLACE };
	int		FindIndex ;
	CString	FindText ;
	int		ReplaceIndex ;
	CString	ReplaceText ;
	int		MatchCase ;
	int		WholeWord ;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	HWND	hDlg ;
	int		TextID ;
	CString	text ;
	CString OriginalText ;
	CString Ltext ;
	CString LFindText ;
	int		textIndex ;
	bool	textFound ;
	int		fcount, rcount ;

// Implementation
private:
	CRrDoc	*m_pDoc;	// the ubiquitous document pointer

	void	ActiveFocusCommon(void);
	void	EnableButtons(void) ;
	void	SetSelected(void) ;
	bool	IsWordChar(TCHAR c) ;
	void	UpdateTextArrays(void) ;
	void	message(char *s) ;

protected:
	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void	OnDestroy();
	virtual void	PostNcDestroy();
	virtual void	OnActivate(UINT, CWnd*, BOOL);
	virtual void	OnSetFocus(CWnd*);
	virtual void	OnKillFocus(CWnd*);
//	virtual BOOL	OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	// Generated message map functions
	//{{AFX_MSG(ReplaceDlg)
	virtual BOOL	OnInitDialog();
	virtual void	OnOK();
	virtual void	OnCancel();
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDropInsert(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	afx_msg void	OnTextChange();
	afx_msg void	OnFindChange();
	afx_msg void	OnFindNext();
	afx_msg void	OnReplace();
	afx_msg void	OnReplaceAll();
	afx_msg void	OnContextHelp();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif	// #ifndef _DREPLACE_H_
