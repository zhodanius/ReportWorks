// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   custcfd.h  $
// ================
//
// Description:
// ============
//
//	This is CRRFileDialog, a class derived from CFileDialog for the purpose of implementing
//	the help button and centering the dialog.
//
//	This is also classes derived from CRRFileDialog for the purpose of customizing the
//	dialog with our own controls.
//
// CNoMastFileDlg implements the Create Report without Master Table checkbox that
//	appears on the File New - Blank Report master select dialog.
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/CUSTCFD.H_V  $
// 
//    Rev 1.14.1.0   May 09 2002 15:25:24   Admin
// Create branch for 10.0
// 
//    Rev 1.14   21 Jan 1998 12:13:58   smh
// OEM20001 merge
// 
//    Rev 1.13.1.0   15 Jan 1998 16:06:22   smh
// RRW 8.0 Abra OEM
// 
//    Rev 1.13   08 Oct 1996 16:49:46   amh
// Arp 1.0 U02 merged to trunk
// 
// 
// 
//    Rev 1.7.1.4   11 Jul 1996 15:04:56   smh
// Runtime DLL conditional out OnNotify.
// 
//    Rev 1.7.1.3   10 Jul 1996 14:03:10   smh
// Create Rep w/o Master customized dialog & data source override
// customized dialog now work when build w/ msvc 4.1 under Win95,
// NT3.51, & NT 4.0 beta 2.
// 
//    Rev 1.7.1.2   03 Jul 1996 09:25:14   smh
// Make help button work under msvc 4.1.
// 
//    Rev 1.7.1.1   02 Jul 1996 16:08:56   smh
// Fixed context sensitive help for Create Rep w/o Master checkbox
// get when UseCommonDlg=1.  ALso finished last change like this.
// 
//    Rev 1.7.1.0   02 Jul 1996 15:27:14   smh
// Fixed two bugs caused by msvc 4.1.  One is that data source
// override control broke because edit control now in parent class
// of dialog.  Other is that lost context sensitive help for
// custom control as those messages moved too.
// 
//    Rev 1.12   11 Jul 1996 15:08:26   smh
// RUNDLL conditionaled out OnNotify.
// 
//    Rev 1.7.1.4   11 Jul 1996 15:04:56   smh
// Runtime DLL conditional out OnNotify.
// 
//    Rev 1.7.1.3   10 Jul 1996 14:03:10   smh
// Create Rep w/o Master customized dialog & data source override
// customized dialog now work when build w/ msvc 4.1 under Win95,
// NT3.51, & NT 4.0 beta 2.
// 
//    Rev 1.7.1.2   03 Jul 1996 09:25:14   smh
// Make help button work under msvc 4.1.
// 
//    Rev 1.7.1.1   02 Jul 1996 16:08:56   smh
// Fixed context sensitive help for Create Rep w/o Master checkbox
// get when UseCommonDlg=1.  ALso finished last change like this.
// 
//    Rev 1.7.1.0   02 Jul 1996 15:27:14   smh
// Fixed two bugs caused by msvc 4.1.  One is that data source
// override control broke because edit control now in parent class
// of dialog.  Other is that lost context sensitive help for
// custom control as those messages moved too.
// 
//    Rev 1.7   14 Feb 1996 17:21:30   par
// The no-master checkbox needed to be NTified.
// 
//    Rev 1.6   14 Feb 1996 16:52:34   par
// Did some ugly stuff to make the same code work under NT.
// 
//    Rev 1.5   19 Dec 1995 10:24:00   smh
// Find file for ds override even when have extensions off in explorer.
// 
//    Rev 1.4   18 Dec 1995 13:53:02   smh
// Have to set data source override buffer in template's
// OnFileNameOK, not parent's OnOK for some reason.
// 
//    Rev 1.3   17 Dec 1995 16:39:44   smh
// New class for RSW file open dialog with data source override ctrl.
// 
//    Rev 1.2   13 Dec 1995 09:17:50   smh
// Added new classes to change way do common file dialogs once
// again, this time for MSVC4.0 which didn't like my hook rtn.
// 
//    Rev 1.1   05 Dec 1995 15:21:54   sbc
// Remove overwrite prompt flag bit from constructor
// 
//    Rev 1.0   30 Oct 1995 10:14:40   smh
// Initial revision.
// 
// 
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _CUSTCFD_H_

// Make a definition for this module.
//
#define _CUSTCFD_H_


// Class derived from CFileDialog so can implement Help button, and center the dialog
class CRRFileDialog : public CFileDialog
{
public:
    
	// Constructors
    CRRFileDialog( BOOL bOpenFileDialog, // TRUE for FileOpen, FALSE for FileSaveAs
						LPSTR helppath = NULL,
	               int helpid = 0,
	               LPCSTR lpszDefExt = NULL,
         	      LPCSTR lpszFileName = NULL,
            	   DWORD dwFlags = OFN_HIDEREADONLY,
               	LPCSTR lpszFilter = NULL,
	               CWnd* pParentWnd = NULL);

	// Data
	char	m_helppath[WINPATHLEN];			// save path to help file in constructor
	int	m_helpid;							// help id for dialog
	PROCESS_INFORMATION m_tblview;	// tblview process info

	void ShowFileInfo();
	void tblviewLaunch();

	//{{AFX_DATA(CRRFileDialog)
	//	enum { IDD = IDD_FILEDLG };
	//}}AFX_DATA

	// Overrides
	//{{AFX_VIRTUAL(CRRFileDialog)
	protected:
	virtual BOOL OnInitDialog();
#if !defined(RUNDLL)
	virtual BOOL OnNotify( WPARAM wParam, LPARAM lParam, LRESULT* pResult );
	virtual void OnFileNameChange();
#endif
	//}}AFX_VIRTUAL

#if defined (OEM_ABRA)
	// 8/04/97 MFC - ABRAFIX: Conversion to RRW 8.0
	// Special code for ABRA to stop the user from changing directories on file open
public:
	CString GetAppDir () {return AppDir;}

private:
	CString AppDir;
	int OFUseTemplate;

protected:
	virtual void OnInitDone();
	virtual void OnFolderChange();
#endif // ABRA
	
	
	// Implementation
	protected:
	// message map functions
	//{{AFX_MSG(CRRFileDialog)
#if !defined(RUNDLL)
	afx_msg void OnHelpButton();
	afx_msg void OnIDMasterOpenDict();
#endif
	//	afx_msg void OnFiledlgTemplate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#if defined(INTERACTIVE)
// CNoMasterFileDlg and CNoMasterTemplate go together.
// They are the parent and child dialogs used to customize the common file dialog
//	for the Create Report without Master Table checkbox on the File New Blank Report
//	dialog.  CNoMasterFileDlg is what the outside world uses, it overrides the OnOK()
//	processing based on data exchanged with the child dialog.  CNoMasterTemplate is
// for the template with the custom control.  It lets the parent know when its
// checkbox is checked, and implements the Win95 control help for the checkbox
class CNoMasterTemplate : public CFileDialog
{
	// construction
	public:
//	CNoMasterTemplate( LPSTR dlgtemplate, LPSTR helppath = NULL, CWnd *pParent = NULL );
	CNoMasterTemplate( LPSTR helppath = NULL );

	// Data
	//{{AFX_DATA(CNoMasterTemplate)
	//	enum 	{ IDD = DMASTEROPEN, IDDNT = DOLDMASTEROPEN };	// dlg templates
	BOOL	m_bNoMasterCheck;						// state of no master checkbox
	char	m_helppath[WINPATHLEN];				// save path of help file
	//}}AFX_DATA

	// Overrides
	//{{AFX_VIRTUAL(CNoMasterTemplate)
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

	// Implementation
	// message map functions
	//{{AFX_MSG(CNoMasterTemplate)
	//	afx_msg void OnFiledlgTemplate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


class CNoMasterFileDlg;

//class CNMFDParent : public CCommonDialog
class CNMFDParent : public CFileDialog
{
	public:
		CNMFDParent( ) : CFileDialog( TRUE ){};
	
	public:
		CNoMasterFileDlg* m_pwndChild ;
	
	protected:
		// Overrides
		//{{AFX_VIRTUAL(CNMFDParent)
		virtual void OnOK();
		//}}AFX_VIRTUAL

		// Implementation
	protected:
		// message map functions
		//{{AFX_MSG(CNMFDParent)
		//}}AFX_MSG
		//DECLARE_MESSAGE_MAP()
} ;


class CNoMasterFileDlg : public CRRFileDialog
{
public:
    
	// Constructors
    CNoMasterFileDlg( //BOOL bOpenFileDialog, // TRUE for FileOpen, FALSE for FileSaveAs
    				LPSTR dlgtemplate, LPSTR helppath = NULL, int helpid = 0);

//               ,
//               LPCSTR lpszDefExt = NULL,
//               LPCSTR lpszFileName = NULL,
//               DWORD dwFlags = OFN_HIDEREADONLY,
//               LPCSTR lpszFilter = NULL,
//               CWnd* pParentWnd = NULL) : CRRFileDialog(bOpenFileDialog, helppath, helpid, 
//               														lpszDefExt, lpszFileName, dwFlags, 
//               														lpszFilter, pParentWnd), 
//																			m_dlgTemplate(dlgtemplate, helppath) {}

	// Data
	//{{AFX_DATA(CNoMasterFileDlg)
	//	enum { IDD = IDD_FILEDLG };
	//}}AFX_DATA
	CNoMasterTemplate m_dlgTemplate;
	CNMFDParent			m_dlgParent;							// Parent dialog for VC 4.1. 

	enum	{	CTRLID = DNOMASTER,				// custom control id
			 	HELPCODE = IDH_NOMASTER			// id of help for custom control
			};

	// Overrides
	//{{AFX_VIRTUAL(CCustomFileDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);		// DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//virtual BOOL OnFileNameOK();
	//}}AFX_VIRTUAL

	// Implementation
	protected:
	// message map functions
	//{{AFX_MSG(CNoMasterFileDlg)
	//	afx_msg void OnFiledlgTemplate();
	afx_msg LRESULT OnF1andHookHelp( WPARAM wParam, LPARAM lParam );
	afx_msg LRESULT OnWhatsThisHelp( WPARAM wParam, LPARAM lParam );
	//afx_msg void OnNoMaster();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
		// INTERACTIVE
#endif

#if defined(RSW)
// CDSOFileDlg and CDSOTemplate go together.
// They are the parent and child dialogs used to customize the common file dialog
//	for data source override dropdown on RSW File Open dialog.  CDSOFileDlg is what 
//	the outside world uses, CDSOTemplate is for the template with the custom control.
class CDSOTemplate : public CFileDialog
{
	// construction
	public:
	CDSOTemplate(LPSTR helppath = NULL );

	// Data
	//{{AFX_DATA(CNoMasterTemplate)
	//}}AFX_DATA
	public:
	CWnd*   m_pwndParent ;
	enum	{	CTRLID = DLIBDATASOURCE,			// custom control ids
			};
	protected:

	char	m_helppath[WINPATHLEN];					// save path of help file
	CComboBox	m_cbDSList;							// data source override combo box
	char 			m_currentDS[SQL_MAX_DSN_LENGTH]; // current datasource 
	char			m_DSOverride[SQL_MAX_DSN_LENGTH]; // store data source override here
	int			m_notAvailState;					// indicates position of "not avail" datasource

	// Public routines
	public:
	VOID InitDataSource();
	void ResetDSList( void );						// reset datasource list
	void SetCurrentDS( LPSTR datasource );		// select current data source 
	void EnableDSList( void );						// enable or disable datasource list
	BOOL GetDSOverride( LPSTR buffer );			// for parent to retrieve data source override
	BOOL SetDSOverride( void );					// to set ds override buffer

	// Overrides
	//{{AFX_VIRTUAL(CDSOTemplate)
	//}}AFX_VIRTUAL
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnFileNameOK();

	// Implementation
	protected:
	// message map functions
	//{{AFX_MSG(CNoMasterTemplate)
	afx_msg void OnDropdownDSList( void );

	//	afx_msg void OnFiledlgTemplate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class CDSOFileDlg : public CRRFileDialog
{
public:
    
	// Constructors
    CDSOFileDlg( LPSTR dlgtemplate, LPSTR helppath = NULL, int helpid = 0) ;

	BOOL GetDSOverride( LPSTR buffer );				// retrieve data source override from child

	// Data
	//{{AFX_DATA(CNoMasterFileDlg)
	//	enum { IDD = IDD_FILEDLG };
	//}}AFX_DATA
	protected:
	CDSOTemplate	m_dlgTemplate;							// child dialog
	CEdit 			m_enFile;								// file name edit control
	enum	{	CTRLID = DLIBDATASOURCE,			// custom control ids
				TCTRLID = DLIBDATASOURCETEXT,
			 	HELPCODE = IDH_DSOVERRIDE			// id of help for custom controls
			};

	// Overrides
	//{{AFX_VIRTUAL(CCustomFileDialog)
	//}}AFX_VIRTUAL
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);		// DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnFileNameOK();
	virtual void OnInitDone();
	virtual void OnFileNameChange( );

	void updateDSOCtrl();

	// Implementation
	protected:
	// message map functions
	afx_msg void OnEditChange();				// do some processing when file name edit changes
	afx_msg LRESULT OnF1andHookHelp( WPARAM wParam, LPARAM lParam );
	afx_msg LRESULT OnWhatsThisHelp( WPARAM wParam, LPARAM lParam );
	//{{AFX_MSG(CDSOFileDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
			//RSW
#endif
			// _CUSTCFD_H_
#endif
