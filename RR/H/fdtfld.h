// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   fdtfld.h  $
// ================
//
// Description:
// ============
//
// Format a date/time field
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/fdtfld.h_v  $
// 
//    Rev 1.6   10 Nov 1995 10:08:24   sbc
// Add function
// 
//    Rev 1.5   08 Nov 1995 11:59:40   sbc
// Apply button support
// 
//    Rev 1.4   07 Nov 1995 13:46:32   sbc
// Enable property sheet help
// 
//    Rev 1.3   19 Jul 1995 17:01:08   sbc
// Add doc pointer to constructor
// 
//    Rev 1.2   19 Jul 1995 16:01:16   sbc
// Add doc pointer (classification)
// 
// Initial revision.
// 
// ****************************************************************************

//
// Make a definition for this module.
//
#define _FDTFLD_H_

// fdtfld.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDateTimePic dialog

class CDateTimePic : public FldPageBase
{
// Construction
public:
	CDateTimePic(CRrDoc *, LPTSTR, UINT);	// constructor

// Dialog Data
	//{{AFX_DATA(CDateTimePic)
	int		m_nDateIndex;
	int		m_nTimeIndex;
	BOOL	m_bShowDate;
	BOOL	m_bShowTime;
	//}}AFX_DATA
// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);
	BOOL showDateTimeCommon(BOOL);
	void showSample();

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);

	// Generated message map functions
	//{{AFX_MSG(CDateTimePic)
	afx_msg void OnShowDate();
	afx_msg void OnShowTime();
	afx_msg void OnDTChange();
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
