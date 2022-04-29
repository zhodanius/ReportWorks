// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   explmgr.h  $
// ================
//
// Description:
// ============
// Explicit Library Manager.  The management of the DLLs needed to be centralized. 
// The purpose of this manager is to resolve the location of the DLLs.
// 
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/explmgr.h_v  $
// 
//    Rev 1.11   05 May 1997 15:13:12   par
// Removed A L I V E (spacing prevents search hits) and PDI _ EXPORT conditionals.
// From this point forward, this code will always be included in build.
// 
// 
//    Rev 1.10   14 Mar 1997 15:31:38   SRM
// charting support initial checkin
// 
//    Rev 1.9   10 Feb 1997 10:02:18   sp
// Arp Live merge to trunk
// 
//    Rev 1.7.1.2   30 Dec 1996 09:34:22   smh
// Added GetResourceDLL().
// 
//    Rev 1.7.1.1   29 Oct 1996 14:22:16   smh
// Fix PDI _ EXPORT conditionals
// 
//    Rev 1.5.1.2   06 Sep 1996 10:57:04   amh
// Added function prototype for GetAttribDriver for the new attribution
// DLL  Attrib.dll
// 
//    Rev 1.5.1.1   30 Jul 1996 16:51:34   sjo
// This is the first round of HTML export changes.  On the U02 branch I am
// putting the code in A L I V E conditionals so that we develop the code on the
// U02 branch but not effect the build of that product.
// 
//    Rev 1.5.1.0   03 Jul 1996 09:59:12   jpb
// change OdbcAdmin names to OdbcInstaller names
// 
//    Rev 1.5   22 Feb 1996 17:51:22   par
// Provide a function for releasing all memory.  
// 
//    Rev 1.4   09 Feb 1996 11:39:28   jpb
// remove QELIB.INI routine
// 
//    Rev 1.3   26 Jan 1996 10:55:16   par
//  Fix compiler errors.
// 
//    Rev 1.2   15 Jan 1996 14:46:32   par
// Use registry to get system directory.
// 
//    Rev 1.1   05 Jan 1996 18:55:56   par
// Add path searching to verify dll existance.
// 
//    Rev 1.0   05 Jan 1996 16:39:52   par
// Initial revision.
// 
// Initial revision.
// 
// ****************************************************************************

#ifndef _EXPLMGR_H_
#define _EXPLMGR_H_


class CExplicitLibraryManager : public CObject
{
	DECLARE_DYNAMIC(CExplicitLibraryManager)
	
// Constructors
public:
	CExplicitLibraryManager() ;

// Attributes
protected:
	CString m_csAppDirectory      ;
	CString m_csRrSystemDirectory ;  // DLLs, EXEs, INIs. 
	CString m_csRrHelpDirectory   ;  // HLPs. 

	// The full path to the initialization file is cached 
	// becaused it is used so frequently. 
	CString m_csRRInitFile       ;

// Registry Operations
protected:
	HKEY    GetLocalAppRegistryKey() const ;
	HKEY    GetLocalSectionKey(LPCSTR lpszSection) const ;
public:
	UINT    GetLocalProfileInt   (LPCSTR lpszSection, LPCSTR lpszEntry, int    nDefault   ) const ;
	CString GetLocalProfileString(LPCSTR lpszSection, LPCSTR lpszEntry, LPCSTR lpszDefault) const ;

// Operations
protected:
	CString FindWindowsFile    (CString csFileName) const ;
	CString FindLocalFile      (CString csFileName) const ;
	CString FindLocalDllFile   (CString csDllName ) const ;
	CString FindLocalIniFile   (CString csIniName ) const ;
	CString FindLocalHelpFile  (CString csHelpName) const ;
	
	BOOL DoesFileExist    (CString csFile) const ;
	BOOL DoesDllExist     (CString csDll ) const ;
	BOOL DoesIniExist     (CString csIni ) const ;
	BOOL DoesHelpFileExist(CString csFile) const ;

// Operations
public:
	// These modules are used so infrequently that the string can be 
	// created on the stack with no noticable speed or memory penalty. 
	CString GetDefaultPrinterDriver() const ;
	CString GetCsvExportDriver()      const ;
	CString GetDbfExportDriver()      const ;
	CString GetWksExportDriver()      const ;
	CString GetRtfExportDriver()      const ;
	CString GetHtml2ExportDriver()    const ;
	CString GetPDIExportDriver()      const ;
	CString GetResourceDll(LANGID)    const ;
	CString GetTextExportDriver()     const ;
	
	// Other drivers. 
	CString GetImageDriver()          const ;
	CString GetChartDriver()          const ;
	CString GetAGChartDriver()        const ;
	CString GetMapiDriver()           const ;
	
	// Data files. 
	CString GetSortRulesFile()        const ;
	CString GetUsersDatFile()         const ;
	CString GetFontConversionFile()   const ;
	CString GetLinkDirectoryFile()    const ;
	CString GetLinkDirectoryName()    const ;  // Name only, no path stuff. 
	
	// Help file. 
	CString GetHelpFile()             const ;

	// Other helper applications. 
	CString GetRrWizard()             const ;

	// SQL specific files. 
#ifdef RSW
	CString GetOdbcInstaller()		  const ;
	CString GetSqlInitFile()          const ;
	CString GetODBCInitFile()         const ;
	CString GetODBCInstInitFile()     const ;

	// AMH 9/6/96 Added this method for attribution 
	CString GetAttribDriver()		  const;
#endif
	
	CString GetLabelInitFile()        const ;
	// Return a constant string reference so that CStrings are not 
	// created on the stack.  This file variable is accessed about 137 times. 
	const CString& GetRRInitFile() const { return m_csRRInitFile ; }

// Implementation
public:
	~CExplicitLibraryManager() ;
	void DeleteContents() ;

#ifdef _DEBUG
	virtual void AssertValid() const ;
	virtual void Dump(CDumpContext& dc) const ;
#endif
} ;


#endif  // _EXPLMGR_H_
/////////////////////////////////////////////////////////////////////////////
