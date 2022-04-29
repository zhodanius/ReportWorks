// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   printdlg.h  $
// ================
//
// Description:
// ============
//
// 
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/printdlg.h_v  $
// 
//    Rev 1.1   11 Jan 1996 16:56:46   dlm
// Added conditionals to allow this header to be multiply included.
// 
//    Rev 1.0   27 Oct 1995 11:12:16   sbc
// Initial revision.
// 
// Initial revision.
// 
// ****************************************************************************

#if !defined(_PRINTDLG_H_)
//
// Make a definition for this module.
//
#define _PRINTDLG_H_

/////////////////////////////////////////////////////////////////////////////
// PrintDialog command target

class PrintDialog : public CObject
{   
//	DECLARE_DYNCREATE(PrintDialog)
//protected:
//	PrintDialog();	// protected constructor used by dynamic creation
public:
	PrintDialog(CRrDoc *);

// Attributes
private:
	BOOL	m_bDlgInit;
	BOOL	m_bPreview;
	BOOL	m_bSetToClose;
	int		m_iReturn;
	CRrDoc	*m_pDoc;		// current document
		
// Operations
public:
	int DoModal();			// our own flavor
private:
	BOOL printDlgError();
	static UINT CALLBACK EXPORT printHook( HWND, UINT, WPARAM, LPARAM );

// Implementation
public:
	virtual ~PrintDialog();
// Static routines
public:
protected:
	// Generated message map functions
	//{{AFX_MSG(PrintDialog)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
};

#endif	// !defined(_PRINTDLG_H_)
