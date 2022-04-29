// ****************************************************************************
//
//		(C) Copyright 2001 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   dinsfld.h  $
// ================
//
// Description:
// ============
//
// InsFldDlg Class definition
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/DINSFLD.H_V  $
// 
//    Rev 1.7   20 Sep 2004 13:42:12   Nick
// List fields in dialog boxes
// 
//    Rev 1.6   09 Sep 2004 08:03:48   Nick
// New list control boxes
// 
//    Rev 1.5   01 Sep 2004 08:07:08   Nick
// New list control
// 
//    Rev 1.4   25 Aug 2004 07:53:58   Nick
// Version 10.5
// 
//    Rev 1.3   02 Jul 2004 13:07:02   Nick
// Add Browse button to Insert Field dialog
// 
//    Rev 1.2   Apr 25 2002 10:05:54   Admin
// Add OnCheckSort()
// 
//    Rev 1.1   11 Mar 1996 15:13:10   sbc
// Add OnDestroy override
// 
//    Rev 1.0   22 Nov 1995 14:23:50   sbc
// Convert insert field dialog to MFC
// 
// ****************************************************************************

//
// Make a definition for this module.
//
#ifndef _DINSFLD_H_

#define _DINSFLD_H_

//  dinsfld.h : header file
//

#include	<afxpriv.h>
#include	"appres.h"
#include	"listcontrol.h"

/////////////////////////////////////////////////////////////////////////////
// InsFldDlg dialog

class InsFldDlg : public CDialog
{
// Construction
public:
	InsFldDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(InsFldDlg)
	enum			{ IDD = IDD_INSERT_FIELD };
	CListControl	listcontrol ;
	CString			FName ;
	int				CloseAfterInsert ;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	FLDID			InsertFID ;

// Implementation
private:
	CRrDoc			*m_pDoc;	// the ubiquitous document pointer

	void			ActiveFocusCommon(void);
	void			CommonInsert(void);
	void			EnableButtons(void) ;
	void			displayFieldList(void) ;
	void			SetName(void) ;

protected:
	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void	OnDestroy();
	virtual void	PostNcDestroy();
	virtual void	OnActivate(UINT, CWnd*, BOOL);
	virtual void	OnSetFocus(CWnd*);
	virtual void	OnKillFocus(CWnd*);
	// Generated message map functions
	//{{AFX_MSG(InsFldDlg)
	virtual BOOL	OnInitDialog();
	virtual void	OnOK();
	virtual void	OnCancel();
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDropInsert(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnRefresh(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnNewSelect(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnItemDoubleClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg LRESULT OnSize(UINT nType, int cx, int cy);
	afx_msg void	OnBrowse() ;
	afx_msg void	OnHelp();
	afx_msg void	OnNameChange();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif	// #ifndef _DINSFLD_H_
