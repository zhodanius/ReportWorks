// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// dparams.h
// =========
//
// Description:
// ============
//
// Class definition
//
// ****************************************************************************

//
// Make a definition for this module.
//
#ifndef _DPARAMS_H_

#define _DPARAMS_H_


#include <afxpriv.h>
#include "appres.h"
#include <afxdtctl.h>
//#include "dfdata.h"

#if defined(INTERACTIVE)
/////////////////////////////////////////////////////////////////////////////
// List Parameters dialog

class CParamsListDlg : public CDialog
{
// Construction
public:
	CParamsListDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CParamsListDlg)
	enum			{ IDD = IDD_PARAMS_LIST };
	CString			FName ;
	CString			DefaultValue ;
	// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Implementation
public:
private:
	CRrDoc		*pDoc;				// the ubiquitous document pointer
	CListCtrl	*flist ;
	int			findex ;
	FLDID		*BigFIDList ;
	FLDID		*FIDList ;			// list truncated for FName
	int			Pcount ;
	int			PcountInit ;
	int			Sort ;
	FLDID		SelectFID ;
	LPMFFIELD	SelectField ;
	HWND		hDlg ;
	bool		dragging ;

	void		EnableButtons(void) ;
	void		DisplayFieldList(void) ;
	void		SetSelected(void) ;
	int			SelectedOrder(void) ;
	void		ReSort(int n) ;
	void		OnNameChange(void) ;
	void		OnNew(void) ;
	void		OnCopy(void) ;
	void		OnEdit(void) ;
	void		OnDelete(void) ;
	void		Rebuild() ;
	void		OnComment(void) ;
	void		OnMoveUp(void) ;
	void		OnMoveDown(void) ;
protected:
	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void	OnDestroy();
	// Generated message map functions
	//{{AFX_MSG(CParamsListDlg)
	virtual BOOL	OnInitDialog		();
	virtual void	OnOK				();
	virtual void	OnCancel			();
	LRESULT			OnCommandHelp		(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp				();
	afx_msg void	OnItemClick			(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnItemDoubleClick	(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnColumnClick		(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnBeginDrag			(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnMouseMove			(UINT nFlags, CPoint point);
	afx_msg void	OnLButtonUp			(UINT nFlags, CPoint point);
	afx_msg void	OnKeyDown			(NMLVKEYDOWN* pKey, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class CParamsName : public CPropertyPage
{
// Construction
public:
	CParamsName(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CParamsName)
	//}}AFX_DATA
	CRrDoc			*pDoc;
// Implementation
public:
private:

protected:
	void	EnableOK(void);
	void	OnNameChange(void) ;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CParamsName)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnApply(void) ;
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CParamsName)
	LRESULT			OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	afx_msg void	OnDestroy();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class CParamsValue : public CPropertyPage
{
// Construction
public:
	CParamsValue(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CParamsValue)
	//}}AFX_DATA
	CRrDoc			*pDoc;
// Implementation
public:
	void HandleSel(NMHDR *pHdr, LRESULT *pRes);
	void HandleSelChange(NMHDR *pHdr, LRESULT *pRes);
	void HandleTimeChange(NMHDR *pHdr, LRESULT *pRes);	
private:
	int				MaxDefault;
	int				ValueWidth ;
	CButton			m_bBtnDate;
	CBitmap			m_bmp;
	CMonthCalCtrl	m_MonthCal;
protected:
	void	EnableOK(void);
	void	OnTypeChange(void) ;
	void	OnDefaultChange(void) ;
	void	OnCheckList(void) ;
	void	OnCalClick(void) ;
	void	OnStaticClick(void) ;
	void	OnDynamicClick(void) ;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CParamsValue)
protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive() ;
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CParamsValue)
	LRESULT			OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class CParamsPresent : public CPropertyPage
{
// Construction
public:
	CParamsPresent(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CParamsPresent)
	//}}AFX_DATA
	CRrDoc			*pDoc;
// Implementation
public:
private:

protected:
	void	OnEditFormat(void) ;
	void	EnableOK(void);
	void	OnValueChange(void) ;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CParamsPresent)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CParamsPresent)
	LRESULT			OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class CParamsValidate : public CPropertyPage
{
// Construction
public:
	CParamsValidate(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CParamsValidate)
	//}}AFX_DATA
	CRrDoc			*pDoc;
// Implementation
public:
private:

protected:
	void	EnableOK(void);
	void	OnEdit(void) ;
	void	OnDelete(void) ;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CParamsValidate)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CParamsValidate)
	LRESULT			OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class CParamsValidateList : public CPropertyPage
{
// Construction
public:
	CParamsValidateList(CRrDoc *, UINT );
	~CParamsValidateList();

// Dialog Data
	//{{AFX_DATA(CParamsValidateList)
	CString		ValueText ;
	CString		DescriptionText ;
	//}}AFX_DATA
	CRrDoc		*pDoc;
// Implementation
public:
	void HandleSel(NMHDR *pHdr, LRESULT *pRes);
	void HandleSelChange(NMHDR *pHdr, LRESULT *pRes);
	void HandleTimeChange(NMHDR *pHdr, LRESULT *pRes);	
private:
	CListCtrl	*flist ;
	CImageList	*pImageListSmall;
	int			PSelectIndex ;
	int			DefaultIndex ;
	int			EditMode ;
	CButton			m_bBtnDate;
	CButton			m_bBtnTime;
	CBitmap			m_bmp;
	CMonthCalCtrl	m_MonthCal;

protected:
	void		EnableOK(void);
	void		OnMoveUp(void) ;
	void		OnMoveDown(void) ;
	void		OnChangeDefault(void) ;
	void		OnEdit(void) ;
	void		OnDelete(void) ;
	void		OnNew(void) ;
	void		OnValueChange(void) ;
	void		OnTableChange(void) ;
	void		OnEditOK(void) ;
	void		OnEditCancel(void) ;
	void		SetSelected(void) ;
	void		DisplayList(void) ;
	void		OnCalClick(void) ;
	void		OnTableClick(void) ;
	void		OnClearTableClick(void) ;
	void		OnClearFieldClick(void) ;
	void		OnValueFieldClick(void) ;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CParamsValidateList)
protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive() ;
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CParamsValidateList)
	LRESULT			OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	afx_msg void	OnItemClick	(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnKeyDown	(NMLVKEYDOWN* pKey, LRESULT* pResult);

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Edit params dialog

class CParams : public CPropertySheet
{
// Construction
public:
	CParams (int ids, CRrDoc* pDoc, CWnd* pParent) ;
protected:
	// Dialog Data
	//{{AFX_DATA(CExport)
	CButton m_buttonClose ;
	//}}AFX_DATA

public:
	CParamsName			*pageName ;
	CParamsValue		*pageValue ;
	CParamsPresent		*pagePresent ;
	CParamsValidate		*pageValidate ;
	CParamsValidateList	*pageValidateList ;

// Implementation
protected:
	virtual BOOL OnInitDialog() ;
	// Generated message map functions
	//{{AFX_MSG(CMTotal)
	afx_msg void OnHelp();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

#endif		// INTERACTIVE

/////////////////////////////////////////////////////////////////////////////
// Enter Parameters dialog

class CParamsEnterDlg : public CDialog
{
// Construction
public:
	CParamsEnterDlg(CWnd* pParent = NULL);	// standard constructor
	~CParamsEnterDlg();

// Dialog Data
	//{{AFX_DATA(CParamsListDlg)
	enum			{ IDD = IDD_PARAMS_ENTER };
	CString			Comment ;
	CString			Name ;
	CString			Value ;
	int				LogicalIndex ;
	CString			Instructions ;
	// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Implementation
public:

	void HandleSel(NMHDR *pHdr, LRESULT *pRes);
	void HandleSelChange(NMHDR *pHdr, LRESULT *pRes);
	void HandleTimeChange(NMHDR *pHdr, LRESULT *pRes);	

private:
	CRrDoc		*pDoc;				// the ubiquitous document pointer

	CListCtrl	*flist ;
	int			findex ;
	int			fCount ;

	CListCtrl	*plist ;
	CImageList	*pImageListSmall;
	int			pindex;
//	int			pindexOld;
	PLArray		PList;
	int			pCount;
	int			pDefault ;
	int			ValueWidth ;
	int			ValueHeight ;
	bool		ItemChange ;

	int			Sort ;
	FLDID		*FIDList ;			// list truncated for FName
	int			Pcount ;
	FLDID		SelectFID ;
	LPMFFIELD	SelectField ;
	int			dataType ;			// 0=char;1=num;2=date;3=datetime;4=logical
	HWND		hDlg ;
	//bool		ItemChange ;		//  experiment by CAS 9/19/2013 to move to public
	int			waitTime ;

	CButton			m_bBtnDate;
	CBitmap			m_bmp;
	CMonthCalCtrl	m_MonthCal;
	CString			szTime ;
	CString			szDateTime;
	CDateTimeCtrl	dTime;

	void		EnableButtons(void) ;
	void		DisplayFieldList(void) ;
	void		OnLogicalChange() ;
	void		OnValueChange(void) ;
	void		OnModify() ;
	void		OnLookup() ;
	void		SetSelected(void) ;
	void		SetValue(void) ;
	void		DisplayPList(void) ;
	void		SetPSelected(void) ;
//	int			SelectedOrder(void) ;
//	void		ReSort(int n) ;
//	void		OnNameChange(void) ;
//	void		OnNew(void) ;
//	void		OnCopy(void) ;
//	void		OnEdit(void) ;
//	void		OnDelete(void) ;
//	void		Rebuild() ;
//	void		OnComment(void) ;
//	void		OnMoveUp(void) ;
//	void		OnMoveDown(void) ;
	void		OnCalClick(void) ;
protected:
	virtual void	DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CParamsEnterDlg)
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL	OnInitDialog		();
	virtual void	OnOK				();
	virtual void	OnCancel			();
	LRESULT			OnCommandHelp		(WPARAM wParam, LPARAM lParam);
	LRESULT			OnTimer				(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp				();
	afx_msg void	OnItemClick			(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnItemDoubleClick	(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnKeyDown			(NMLVKEYDOWN* pKey, LRESULT* pResult);
	afx_msg void	OnPItemClick			(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnPItemDoubleClick	(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void	OnPKeyDown			(NMLVKEYDOWN* pKey, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif	// #ifndef _DPARAMS_H_
