// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   dsort.h  $
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
#ifndef _DFUNC_H_

#define _DFUNC_H_

//  header file for dfunc.cpp
//

#include <afxpriv.h>
#include "appres.h"

#define RR_FUNC_FLAG	0x80000000

/////////////////////////////////////////////////////////////////////////////
// SelectSFDlg dialog

class CFuncList : public CDialog
{
// Construction
public:
	CFuncList(int type, CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFuncList)
	enum			{ IDD = IDD_SELECT_FUNCTION };
	int		paste ;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Implementation
public:
	int		xtype ;
private:
	CRrDoc		*pDoc;	// the ubiquitous document pointer
	CListCtrl	*flist ;
	int			*plist ;
	int			findex ;
	int			fselect ;
	int			Sort ;
	int			LCount ;
	void		ActiveFocusCommon(void);
	void		EnableButtons(void) ;
	int			BuildFunkList(void) ;
	void		DisplayList(void) ;
	void		SortList() ;
	void		ReSort(int n) ;
	void		SetSelected() ;
protected:
	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void	OnDestroy();
	// Generated message map functions
	//{{AFX_MSG(CFuncList)
	virtual BOOL	OnInitDialog		();
	virtual void	OnOK				();
	virtual void	OnCancel			();
	LRESULT			OnCommandHelp		(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp				();
	afx_msg void	OnItemClick			(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnItemDoubleClick	(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnColumnClick		(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif	// #ifndef _DFUNC_H_
