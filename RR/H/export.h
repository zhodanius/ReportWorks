// ****************************************************************************
//
//		(C) Copyright 2004 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   export.h  $
// ================
//
// Description:
// ============
//
// Preferences property page
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// Rev 1.01    17 Nov 2014 14:09:12   CAS
// Added the CButton m_buttonOpenInBrowser element / object in the 
// declaration for HTML Export to allow manipulation of the checkbox
// as requested by Anis Karim (LogoTech)
// 
// ****************************************************************************

// page order
#define PAGE_TYPE			0
#define PAGE_MAPI			1
#define PAGE_OPTIONS_TEXT	2
#define PAGE_OPTIONS_HTML	3
#define PAGE_OPTIONS_ACTIVEX 4

//
// Make a definition for this module.
//
#define _EXPORT_H_

#include "ColorCtrl.h"



/////////////////////////////////////////////////////////////////////////////
// Export Type dialog

class CExportType : public CPropertyPage
{
// Construction
public:
	CExportType(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CExportType)
	int		ExportType ;
	int		FileType ;
	CString	FileName ;
	int		 FileFilterID ;
	//}}AFX_DATA
	CRrDoc *m_pDoc;
	
// Implementation
public:
	void SavePage(void);
protected:
	void		Initialize(void);
	BOOL		onTabOrOK(void);
	void		setButtons	(void) ;
	void loadInitialSettings(void) ;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CExportType)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnOK(void) ;
	virtual	BOOL OnApply() ;
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CExportType)
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	afx_msg void OnHelp();
	afx_msg LRESULT OnExportTypeText();
	afx_msg LRESULT OnExportTypeRTF();
	afx_msg LRESULT OnExportTypeHTML();
	afx_msg LRESULT OnExportTypeActiveX();
	afx_msg LRESULT OnExportTypeXbase();
	afx_msg LRESULT OnExportTypeResult();
	afx_msg LRESULT OnExportTypeTextData();
	afx_msg LRESULT OnExportTypeWorksheet();
	afx_msg LRESULT OnExportTypeExcelChart();
	afx_msg LRESULT OnExportTypeExcelPivot();

	afx_msg LRESULT OnFileTypeComma();
	afx_msg LRESULT OnFileTypeSDF();
	afx_msg LRESULT OnFileTypeTab();
	afx_msg LRESULT OnFileTypeChar();

	afx_msg LRESULT OnFileBrowse();
	afx_msg LRESULT OnFileEdit();


	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// ExportMAPI dialog

class CExportMAPI : public CPropertyPage
{
// Construction
public:
	CExportMAPI(CRrDoc *, UINT );

	int		burstable ;
	int		MAPIpresent ;
// Dialog Data
	//{{AFX_DATA(CExportMAPI)
	int		useMAPI ;
	int		MAPItype ;
	CString	subject ;
	CString	message ;
	CString SendTo ;
	int		burstIndex ;
	CString	sendToFieldName ;
	CString	subjectFieldName ;
	CString	messageFieldName ;
	//}}AFX_DATA
	CRrDoc *m_pDoc;

// Implementation
public:
	void SavePage(void);
protected:
	FLDID	sendToFID ;
	FLDID	subjectFID ;
	FLDID	messageFID ;
	void	Initialize(void);
	BOOL	onTabOrOK(void);
	void	showControls() ;
	void	OnOK(void) ;
	bool	IsBurstable(void) ;
	void	SetBurstFields(void) ;
	void	SetSubjectMessageFields(void) ;
	void	OnSendToField(void) ;
	void	OnSubjectField(void) ;
	void	OnSubjectText(void) ;
	void	OnMessageField(void) ;
	void	OnMessageText(void) ;
	void	OnSendTo(void) ;
	void	OnBurst(void) ;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CExportMAPI)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CCharWidth)
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	afx_msg void OnHelp();
	afx_msg LRESULT OnEnableMAPI();
	afx_msg LRESULT OnMAPItype();
	afx_msg LRESULT OnEditSendTo() ;
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
// Export Text/WKS/DBF Options dialog

class CExportOptions : public CPropertyPage
{
// Construction
public:
	CExportOptions(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CExportOptions)
	int		band ;
	int		OneCR ;
	int		NoMargins ;
	int		UseDOS ;
	int		Quote ;
	int		UseFieldNames ;
	CString	Separator ;
	CListBox	CBGroupH ;
	CListBox	CBGroupF ;
	//}}AFX_DATA
	CRrDoc *m_pDoc;
	int		groups ;
	int		grouph ;
	int		groupf ;
	int		ExportType ;
	CColorCtrl<CButton>	m_radio00;
	CColorCtrl<CButton>	m_radio01;
	CColorCtrl<CButton>	m_radio02;
	CColorCtrl<CButton>	m_radio03;
	CColorCtrl<CButton>	m_radio04;
// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);
	BOOL onTabOrOK(void);
	void setControls(void) ;
	void OnOK(void) ;
	void OnNewBand(void) ;

	void OnCarriageReturns(void) ;
	void OnNoMargins(void) ;
	void OnAddQuoteDelimiter(void) ;
	void OnUseDOS(void) ;
	void OnUseFieldNames(void) ;
	void OnCharacterSeparator(void) ;
	
	void OnNewGroup(void) ;
	void loadInitialSettings(void) ;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CExportOptions)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CExportOptions)
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	LRESULT			OnDraw(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnHelp();
	afx_msg void	NoFocus();
	afx_msg LRESULT OnSelectBand();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Custom Combo box - containing colors

class CColorCombo : public CComboBox
{
public:
	// Overridables (must override draw, measure and compare for owner draw)
	virtual void DrawItem   (LPDRAWITEMSTRUCT    lpDrawItemStruct   ) ;
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) ;
	virtual int  CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct) ;

protected:
	void DrawColorEntry     (LPDRAWITEMSTRUCT lpdis) ;
	void ColorSelectionState(LPDRAWITEMSTRUCT lpdis) ;

public:
	static int FindColor(COLORREF rgbFind) ;
} ;

/////////////////////////////////////////////////////////////////////////////
// Export HTML Options dialog

class CExportOptionsHTML : public CPropertyPage
{
// Construction
public:
	CExportOptionsHTML(CRrDoc *, UINT );


// Dialog Data
	//{{AFX_DATA(CExportOptionsHTML)
	CComboBox	m_comboImageFileFormat ;
	CEdit		m_editHtmlImageDirectory ;
	CButton		m_buttonHtmlImageDirectoryBrowse ;
	CEdit		m_editHtmlTableBorderWidth ;
	CSpinButtonCtrl m_spinHtmlTableBorderWidth ;
	CEdit       m_editHtmlBackgroundImage ;
	CButton     m_buttonImageBrowse       ;
	//Rev 1.01
	CButton		m_buttonOpenInBrowser;

	int		borderType ;
	int		borderWidth ;
	int		openBrowser ;
	CString	imageDirectory ;
	CString	imageFileFormat ;
	int		background ;
	int		bgColor ;
	int		imageFormat ;
	int		backgroundType ;
	CString	backgroundImage ;
	//}}AFX_DATA
	CRrDoc		*m_pDoc;
	CColorCombo m_comboColor				;
	COLORREF	m_rgbHtmlBackgroundColor		;
	CString		m_csExportDirectory              ;
	BOOL		m_bHtmlSameDirectoryAsOutput     ;
//	BOOL&		m_bHtmlOpenInBrowser             ;
	BOOL		m_bCopyAllImagesToDirectory      ;
//	CString&	m_csHtmlImageFileFormat          ;
	BOOL		m_bEnableInvalidFileWarning      ;
	HTML_EXPORT	m_HtmlExport ;	
	// Implementation
public:
	void SavePage(void);
protected:
	void Initialize(void);
	BOOL onTabOrOK(void);
	void setControls(void) ;
	void OnOK(void) ;
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CExportOptionsHTML)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CExportOptionsHTML)
	afx_msg void OnBorderNone();
	afx_msg void OnBorderWidth();
	afx_msg void OnHtmlImageDirectoryBrowse     () ;
	afx_msg void OnChangeHtmlImageDirectory     () ;
	afx_msg void OnSelchangeHtmlimageFileformat () ;
	afx_msg void OnEditchangeHtmlimageFileformat() ;
	afx_msg void OnPaint();
	afx_msg void OnChangeColor();
	afx_msg void OnHtmlBackgroundImageBrowse() ;
	afx_msg void OnHtmlBackgroundColor      () ;
	afx_msg void OnHtmlBackgroundImage      () ;

	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Export ActiveX Options dialog

#define DEFAULT_VW_SS	"85"
#define DEFAULT_VW_SIZE	85
#define MAX_URL_LENGTH	260
#define HTML_TEXT_LENGTH	600
#define VIEWER_CTRL_DEFAULT "rrprview.cab" // Viewer Control setup filename
#define PERCENT_SIGN '%'
#define URL_MIN_LENGTH 3

class CExportOptionsActiveX : public CPropertyPage
{
// Construction
public:
	CExportOptionsActiveX(CRrDoc *, UINT );

// Dialog Data
	//{{AFX_DATA(CExportOptionsActiveX)
	enum { IDD = IDD_ACTX_OBJ_TAG_DLG };
	CString	m_csCabinet;
	CString	m_csHTMLDoc;
	CString	m_csPDIFile;
	CString	m_csImagePath;
	int		m_nHeight;
	int		m_nWidth;
	//}}AFX_DATA
	CRrDoc *m_pDoc;
	
// Implementation
public:
	void WriteInputFileDirToIni();
	void ReadInputFileDirFromIni();


	BOOL checkLocations();
	char* getHTMLTags();
	void WriteHTMLDirToIni();
	void ReadHTMLDirFromIni();
	void WriteInputLocToIni();
	void ReadInputLocFromIni();
	void WriteCtrlLocToIni();
	void ReadCtrlLocFromIni();
	void WriteImageLocToIni();
	void ReadImageLocFromIni();
	void WriteViewerCtlSize();
	void ReadViewerCtlSize();
	void SavePage(void);
protected:
	void Initialize(void);
	BOOL onTabOrOK(void);
	void setControls(void) ;
	void OnOK(void) ;
private:
	BOOL	checkPath( BOOL );
	void	setExpOLEFlag();
	void	CreateHTMLDocument();
	
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CExportOptionsActiveX)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive(void);
	virtual BOOL OnSetActive(void);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CExportOptionsActiveX)
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	afx_msg void OnHelp();
	afx_msg LRESULT OnSelectBand();
	afx_msg void OnButtonViewHtml();
	afx_msg void OnCreateHTMLDocument();
	afx_msg void OnPaint();
	afx_msg void OnChangeColor();
	afx_msg void OnHtmlBackgroundImageBrowse() ;
	afx_msg void OnHtmlBackgroundColor      () ;
	afx_msg void OnHtmlBackgroundImage      () ;
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CExport dialog

class CExport : public CPropertySheet
{
// Construction
public:
	CExport (CRrDoc* pDoc, CWnd* pParent, UINT) ;
protected:
	// Dialog Data
	//{{AFX_DATA(CExport)
//	enum { IDD = IDD_HTML2_EXPORT };
	CButton m_buttonClose ;
	//}}AFX_DATA

public:
	CExportOptions		*pageOptions ;
	CExportOptionsHTML	*pageOptionsHTML ;
	CExportOptionsActiveX *pageOptionsActiveX ;

// Implementation
protected:
	virtual BOOL OnInitDialog() ;

	// Generated message map functions
	//{{AFX_MSG(CHtmlDlg)
	afx_msg void OnHelp();
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


	extern	int		XExportType, XFileType, XPage ;
	extern	CString XFileName ;
