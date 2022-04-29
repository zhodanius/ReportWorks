// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   edittext.h  $
// ================
//
// Description:
// ============
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/edittext.h_v  $
// 
//    Rev 1.7   21 Nov 1995 15:49:00   sbc
// Add OnChildNotify()
// 
//    Rev 1.6   16 Nov 1995 16:21:26   sbc
// Changes for text field properties
// 
//    Rev 1.5   08 Nov 1995 15:06:48   sbc
// Add help support
// 
//    Rev 1.4   01 Nov 1995 16:28:40   sbc
// Add dialog class for properties
// 
//    Rev 1.3   25 Oct 1995 15:26:38   sbc
// Change to override OnChar and OnKeyDown
// 
//    Rev 1.2   26 Jul 1995 17:53:36   smh
// prevent multiple includes.
// 
// 
// Initial revision.
// 
// ****************************************************************************

//
// Make a definition for this module.
//
#ifndef _EDITTEXT_H_

#define _EDITTEXT_H_


// edittext.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditText window

class CEditText : public CEdit
{
	DECLARE_DYNCREATE(CEditText)
// Construction
public:
	CEditText();

// Attributes
	char m_cSpaceDot;

protected:

// Operations
public:

// Implementation
public:
	virtual ~CEditText();

	BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT *);


	void sizeTextWindow(void);
protected:
	// Generated message map functions
	//{{AFX_MSG(CEditText)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif
