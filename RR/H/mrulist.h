// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   mrulist.h  $
// ================
//
// Description:
// ============
// Special version of MRU that truncates name after 40 characters. 
// 
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/mrulist.h_v  $
// 
//    Rev 1.1   06 Mar 1996 11:39:30   par
// Don't use the MFC version of the Add.  There seems to be a bug in the code.
// 
//    Rev 1.0   05 Dec 1995 14:11:40   par
// Initial revision.
// 
// Initial revision.
// 
// ****************************************************************************


#ifndef __MRULIST_H__
#define __MRULIST_H__

#define MRU_ABBREV_FILENAME_LEN 40

class CRrRecentFileList : public CRecentFileList
{
	// Construction
	public:
		CRrRecentFileList(UINT nStart, LPCSTR lpszSection, LPCSTR lpszEntryFormat, int nSize, int nMaxDispLen=MRU_ABBREV_FILENAME_LEN) ;
	
	// Operations
	public:
		void AbbreviateName(LPSTR lpszCanon, int cchMax, BOOL bAtLeastName) const ;
		// Our version of GetDisplay Name will always truncate instead of just when directories are different. 
		BOOL GetDisplayName(CString& strName, int nIndex, LPCSTR lpszCurDir, int nCurDir, BOOL bAtLeastName = TRUE) const ;
		virtual void UpdateMenu(CCmdUI* pCmdUI) ;
		virtual void Add(LPCTSTR lpszPathName) ;
} ;

#endif // __MRULIST_H__
/////////////////////////////////////////////////////////////////////////////
