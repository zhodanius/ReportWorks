// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   druler.h  $
// ================
//
// Description:
// ============
//
// RulerDlg Class definition
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/druler.h_v  $
// 
//    Rev 1.0   27 Nov 1995 11:19:32   sbc
// Initial revision.
// 
// ****************************************************************************
//
// Make a definition for this module.
//
#ifndef _DRULER_H_

#define _DRULER_H_

#include "appres.h"

/////////////////////////////////////////////////////////////////////////////
// RulerDlg dialog

class RulerDlg : public CDialog
{
// Construction
public:
	RulerDlg(CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(RulerDlg)
	enum { IDD = IDD_RULERS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Implementation
private:
	CRrDoc	*m_pDoc;	// the ubiquitous document pointer
public:
	BOOL	m_bVertFocus;
	int		m_HorzSpacing;
	int		m_VertSpacing;

protected:
	// Generated message map functions
	//{{AFX_MSG(RulerDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();

	LRESULT OnCommandHelp(WPARAM, LPARAM);
	afx_msg void OnHScroll(UINT, UINT, CScrollBar*);
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif	// #ifndef _DRULER_H_
