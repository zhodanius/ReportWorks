// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   dlplace.h  $
// ================
//
// Description:
// ============
//
// Create Band Lines dialog
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
#ifndef _DLPLACE_H_

#define _DLPLACE_H_

#include "ColorCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// Create Band Lines dialog

class CBandLine : public CDialog
{
// Construction
public:
	CBandLine(int idd, CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBandLine)
	int			LinePlace ;
	int			LineType ;
	int			HFIndex ;
	int			Number ;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	bool		paste ;

	CColorCtrl<CButton>	m_radio00;
	CColorCtrl<CButton>	m_radio01;
	CColorCtrl<CButton>	m_radio02;
	CColorCtrl<CButton>	m_radio03;
	CColorCtrl<CButton>	m_radio04;
	CColorCtrl<CButton>	m_radio05;
	CColorCtrl<CButton>	m_radio06;
	CColorCtrl<CButton>	m_radio07;
	CColorCtrl<CButton>	m_radio08;
	CColorCtrl<CButton>	m_radio09;

// Implementation
private:
	CRrDoc	*pDoc;			// the ubiquitous document pointer
	int		OriginalLineType,
			OriginalHFIndex ;
	HWND	hDlg ;
	HBRUSH	brush ;

protected:
	void			OnNumber(void) ;
	void			OnLinePlace(void) ;
	void			OnLineType(void) ;
	void			EnableButtons(void) ;

	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
//	virtual void	OnDestroy();
	// Generated message map functions
	//{{AFX_MSG(CTotalsOK)
	virtual BOOL	OnInitDialog();
	virtual void	OnOK();
	virtual void	OnCancel();
	LRESULT			OnCommandHelp(WPARAM wParam, LPARAM lParam);
	LRESULT			OnDraw(WPARAM wParam, LPARAM lParam);
	LRESULT			OnColor(WPARAM wParam, LPARAM lParam);
	virtual BOOL	OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) ;
	afx_msg void	OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif