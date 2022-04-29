// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   
// ================
//
// Description:
// ============
//
// Field Trim dialog
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/fldtrim.h_v  $
// 
//    Rev 1.2   26 Sep 1995 09:57:34   sbc
// Remove unused function
// 
//    Rev 1.1   19 Jul 1995 16:24:40   sbc
// Add header
// 
// Initial revision.
// 
// ****************************************************************************

//
// Make a definition for this module.
//
#define _FLDTRIM_H_

// fldtrim.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFldTrim dialog

class CFldTrim : public CPropertyPage
{
// Construction
public:
	CFldTrim();

// Dialog Data
	//{{AFX_DATA(CFldTrim)
	enum { IDD = IDD_TRIM };
	int m_nTrim;
	CString	m_FieldName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CFldTrim)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CFldTrim)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
