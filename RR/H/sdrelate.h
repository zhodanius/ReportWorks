// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   sdrelate.h  $
// ================
//
// Description:
// ============
//
// Class definition
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
#ifndef _SDRELATE_H_

#define _SDRELATE_H_

//  sdrelate.h : header file
//

#include <afxpriv.h>
#include "appres.h"

#if 0	// Future
/////////////////////////////////////////////////////////////////////////////
// Join Fields Dialog
class CJoinFieldsDlg : public CDialog
{
// Construction
public:
	CJoinFieldsDlg(int fno, CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CJoinFieldsDlg)
	enum			{ IDD = IDD_JOIN };
	CString			FromTable ;
	CString			FromAlias ;
	CString			FromField ;
	CString			ToTable ;
	CString			ToAlias ;
	CString			ToField ;
	int				FromListIndex ;
	int				ToListIndex ;
	int				TypeExact ;
	int				ApproxHigh ;
	int				Unmatched ;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
public:

// Implementation
private:
	CRrDoc		*pDoc;				// the ubiquitous document pointer
	int			fileNum ;
	PKREL		rs;
	int			iNumJoinPairs ;
	BOOL		OJokDS ;
	BOOL		OJokFrom ;
	BOOL		OJokTo ;
	BOOL		OJAnyCombo ;
	BOOL		ApproxOK ;
	BOOL		bMultiMode ; 	// TRUE if in multi-column join mode

	HWND		hDlg ;
	int			helpCode ;
	char		fldName[FLDLISTENTRYSIZE];
	char		tempbuf[WINPATHLEN+1];
	char		szPathBuf[WINPATHLEN+1];
	char		saveName[MAXDNAME+2+82];	// +2 for spaces in From-field combo box

	void		EnableButtons(void) ;
	void		showFromTable(JOINPAIR *joinpairs,
								int iNumJoinPairs) ;
	int			initSTFldList(LPMFFILE lpMffile,
								LPSTR curFld) ;

	BOOL		fillToFields(BOOL bNeedOpen,
								LPSTR relfile,
								int filenum,
								LPSTR initSel) ;
	void		PurgeToList (int i,
								JOINPAIR *joinpairs,
								char *szTest) ;
	void		NotCartesian(void) ;

	void		EnableJoinButtons (BOOL bEnableApprox, int relType) ;

	BOOL		relFldFilter(LPMFFIELD f) ;

protected:
	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	// Generated message map functions
	//{{AFX_MSG(CJoinFieldsDlg)
	virtual BOOL	OnInitDialog();
	virtual void	OnOK();
	virtual void	OnCancel();
	virtual void		OnFromField() ;
	virtual void		OnToTable() ;
	virtual void		OnToField() ;
	LRESULT			OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnRefresh(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif	// future

/////////////////////////////////////////////////////////////////////////////
// Select To Field dialog

class CSelectToFieldDlg : public CDialog
{
// Construction
public:
	CSelectToFieldDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSelectToField)
	enum			{ IDD = IDD_SELECT_TO_FIELD };
	CString			FName ;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
public:
	int			SelectIndex ;

// Implementation
private:
	CRrDoc		*pDoc;				// the ubiquitous document pointer
	CListCtrl	*flist ;
	int			findex ;
	int			fCount ;
	int			Sort ;
	void		EnableButtons(void) ;
	void		SetName(void) ;
	void		SetSelected(void) ;
	void		DisplayList(void) ;
	void		ReSort(int n) ;
	void		SortList(void) ;
	void		Swap(int k1, int k2) ;
	int			CullList(void) ;
protected:
	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	// Generated message map functions
	//{{AFX_MSG(CSelectToField)
	virtual BOOL	OnInitDialog();
	virtual void	OnOK();
	virtual void	OnCancel();
	LRESULT			OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnRefresh(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	afx_msg void	OnNameChange();
	afx_msg void	OnNameSort();
	afx_msg void	OnItemClick			(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnColumnClick		(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnItemDoubleClick	(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnKeyDown			(NMLVKEYDOWN* pKey, LRESULT* pResult);

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif
