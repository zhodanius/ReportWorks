// ****************************************************************************
//
//		(C) Copyright 2001 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   fldprop.h  $
// ================
//
// Description:
// ============
//
// Field comment property page
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/FLDPROP.H_V  $
// 
//    Rev 1.4   02 Jul 2004 13:25:18   Nick
// Font page
// 
//    Rev 1.3   Apr 25 2002 10:09:08   Admin
// Add (unused) code for image property sheet
// 
//    Rev 1.2   16 Nov 1995 16:22:02   sbc
// Changes for text field properties
// 
//    Rev 1.1   08 Nov 1995 11:59:46   sbc
// Apply button support
// 
//    Rev 1.0   07 Nov 1995 14:55:10   sbc
// Initial revision.
// 
//    Rev 1.0   06 Nov 1995 11:56:12   sbc
// Initial revision.
// 
// Initial revision.
// 
// ****************************************************************************

// page order
#define PAGE_FORMAT		0
#define PAGE_ALIGN		1
#define PAGE_FONT		2
#define PAGE_COMMENT	3

//
// Make a definition for this module.
//
#define _FLDPROP_H_

// fcomment.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// FldProp dialog

class FldProp : public CPropertySheet
{
// Construction
public:
	FldProp(UINT nIDCaption, CWnd* pParent, UINT iSelPage);

// Overrides
//	afx_msg void OnApplyNow();
// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(FldProp)
	afx_msg void OnHelp();	// help hander enables help button
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#include "pagebase.h"
#include "fcharfld.h"
#include "fcharpic.h"
#include "fdatefld.h"
#include "fdtfld.h"
#include "fnumfld.h"
#include "fldalign.h"
#include "ftimefld.h"
#include "fcomment.h"
#include "ftextfld.h"
