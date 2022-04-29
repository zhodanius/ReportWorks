// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   dxedit.h  $
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
#ifndef _DXEDIT_H_

#define _DXEDIT_H_

//  header file for dxedit.cpp
//

#include <afxpriv.h>
#include "appres.h"

/////////////////////////////////////////////////////////////////////////////
// Expression edit dialog

class CXEdit : public CDialog
{
// Construction
public:
	CXEdit(int etype, CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(SelectSFDlg)
	enum			{ IDD = IDD_XEDIT };
	CString			XName ;
	CString			Expression ;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	int			xtype ;
	LPMFFIELD	Field ;
	LPMFFIELD	CopyField ;
	HWND		hDlg ;
	LPUDF		udf ;
	int			maxName ;
	int			maxExp ;
	int			helpCode ;

// Implementation
private:
	CRrDoc	*pDoc;	// the ubiquitous document pointer

	void	EnableButtons(int id = -1) ;
	void	AddText(const char *text) ;
	void	AddFieldName(FLDID fid) ;
	bool	expOkay(BOOL) ;
	void	SelectExpression(int k) ;
	void	KeyFocus(int id) ;
protected:
	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void	OnDestroy();
	// Generated message map functions
	//{{AFX_MSG(SelectSFDlg)
	virtual BOOL	OnInitDialog();
	virtual void	OnOK();
	virtual void	OnCancel();
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	afx_msg void	OnNameChange() ;
	afx_msg void	OnExpressionChange() ;
	afx_msg void	OnExpressionUpdate() ;
	virtual void	OnOp01(void) ;
	virtual void	OnOp02(void) ;
	virtual void	OnOp03(void) ;
	virtual void	OnOp04(void) ;
	virtual void	OnOp05(void) ;
	virtual void	OnOp06(void) ;
	virtual void	OnOp07(void) ;
	virtual void	OnOp08(void) ;
	virtual void	OnOp09(void) ;
	virtual void	OnOp10(void) ;
	virtual void	OnOp11(void) ;
	virtual void	OnOp12(void) ;
	virtual void	OnOp13(void) ;
	virtual void	OnOp14(void) ;
	virtual void	OnOp15(void) ;
	virtual void	OnOp16(void) ;
	virtual void	OnOpTRUE(void) ;
	virtual void	OnOpFALSE(void) ;
	virtual void	OnVerify() ;
	virtual void	OnReplace() ;
	virtual void	OnField() ;
	virtual void	OnFunction() ;
	virtual void	OnCalcExp() ;
#if !defined(RSW)
	virtual void	OnKeyExp() ;
#endif
	virtual void	OnUDFExp() ;
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif	// #ifndef _DXEDIT_H_
