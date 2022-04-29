// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   pagebase.h  $
// ================
//
// Description:
// ============
//
// Base Property Page Class
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/PAGEBASE.H_V  $
// 
//    Rev 1.3   25 Aug 2004 07:54:00   Nick
// Version 10.5
// 
//    Rev 1.2   02 Jul 2004 13:27:46   Nick
// Add stuff for Preference dialog
// 
//    Rev 1.1   05 Feb 1996 12:32:16   sbc
// Make Initialize() and SavePage() pure virtual
// 
//    Rev 1.0   08 Nov 1995 12:02:56   sbc
// Initial revision.
// 
// 
// ****************************************************************************

//
// Make a definition for this module.
//
#define _PAGEBASE_H_

// pagebase.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// FldPageBase dialog

class FldPageBase : public CPropertyPage
{
// Construction
public:
	FldPageBase(CRrDoc *, LPTSTR, UINT);

// Dialog Data
	//{{AFX_DATA(FldPageBase)
	CString	m_FieldName;
	//}}AFX_DATA
	CRrDoc *m_pDoc;
	
// Implementation
protected:
	// called to setup up the property page
	virtual void Initialize(void) = 0;
	// called to save the control states
	virtual void SavePage(void) = 0;
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(FldPageBase)
protected:
	virtual void OnOK();
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(FldPageBase)

	//}}AFX_MSG
//	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// PrefsPageBase dialog

class PrefsPageBase : public CPropertyPage
{
// Construction
public:
	PrefsPageBase(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(FldPageBase)
	//}}AFX_DATA
	CRrDoc *m_pDoc;
	
// Implementation
protected:
	// called to setup up the property page
	virtual void Initialize(void) = 0;
	// called to save the control states
	virtual void SavePage(void) = 0;
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(FldPageBase)
protected:
	virtual void OnOK();
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(FldPageBase)

	//}}AFX_MSG
//	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
// Rulers dialog

class RulersPageBase : public CPropertyPage
{
// Construction
public:
	RulersPageBase(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(RulersPageBase)
	//}}AFX_DATA
	CRrDoc *m_pDoc;

// Implementation
protected:
	// called to setup up the property page
	virtual void Initialize(void) = 0;
	// called to save the control states
	virtual void SavePage(void) = 0;
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(RulersPageBase)
protected:
	virtual void OnOK();
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(FldPageBase)

	//}}AFX_MSG
//	DECLARE_MESSAGE_MAP()
};
