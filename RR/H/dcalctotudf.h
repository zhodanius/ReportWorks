// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   dcalctotudf.h  $
// ================
//
// Description:
// ============
//
// Class definition for dialogs listing calc/tot/udf fields
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:
/////////////////////////////////////////////////////////////////////////////

//
// Make a definition for this module.
//
#ifndef _DCALCTOTUDF_H_

#define _DCALCTOTUDF_H_

// List calc/tot dialog

class CListCalcTot : public CDialog
{
// Construction
public:
	CListCalcTot(int idd, CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(InsFldDlg)
//	enum			{ IDD = IDD_CALC_FIELDS };
	CListControl	 m_listctrl;
	CString			FName ;
	CString			expression ;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	FLDID	SelectFID ;
	int		ListType ;
								// 0,1: Name Sort (up, down)

// Implementation
private:
	CRrDoc*	pDoc;			// the ubiquitous document pointer
	HWND	hDlg ;
	HBRUSH	groupheader1Brush,
			groupheader2Brush,
			groupheader3Brush,
			groupfooter3Brush,
			groupfooter2Brush,
			groupfooter1Brush,
			summaryBrush,
			pgFooterBrush,
			bwBrush;

	void	displayFieldList(void) ;
	void	EnableButtons(void) ;
	int		fldFilter(LPMFFIELD f) ;
	void	showExpression() ;
	void	DoEdit() ;
	void	SetCloseDefault(int id) ;

protected:
	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
//	virtual void	OnDestroy();

	// Generated message map functions
	//{{AFX_MSG(InsFldDlg)
	virtual BOOL	OnInitDialog();
	virtual void	OnOK();
	virtual void	OnCancel();

//	virtual void	OnCancel();
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
//	afx_msg LRESULT OnDropInsert(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnItemDoubleClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnBrowse() ;
	afx_msg void	OnHelp();
	afx_msg	void	OnNew() ;
	afx_msg	void	OnEdit() ;
	afx_msg	void	OnCopy() ;
	afx_msg	void	OnDelete() ;
	afx_msg	void	OnAdd() ;
	afx_msg void	OnReset() ;
	afx_msg void	OnMultiEdit() ;
	afx_msg	void	OnComment() ;
	afx_msg LRESULT OnDropInsert(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnColor(WPARAM wParam, LPARAM lParam);
	afx_msg	LRESULT	OnNewSelect(WPARAM wParam, LPARAM lParam) ;
	afx_msg	void	OnNameChange() ;


	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif	// #ifndef _DCALCTOTUDF_H_
