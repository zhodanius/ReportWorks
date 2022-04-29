//***************************************************************************
//
// CHtmlDlg.h : header file
//

#define _HTMLDLG_H_

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
// 

class CHtmlLocationPage : public CPropertyPage
{
public:
	CHtmlLocationPage(CRrDoc *pDoc, HTML_EXPORT *pHtmlExport);
protected:
	CColorCombo  m_colorList;
	CRrDoc		*m_pDoc;	// Doc pointer
	HTML_EXPORT	*m_pExport;	// Pointer to HtmlExport in CRrExport...
	// Dialog Data
	//{{AFX_DATA(CHtmlLocationPage)
	enum { IDD = IDD_HTML2_PAGE_LOCATION };
	CEdit     m_editExportPathname             ;
	CComboBox m_comboImageFileFormat           ;
	CEdit     m_editHtmlImageDirectory         ;
	CButton   m_buttonHtmlImageDirectoryBrowse ;
	CStatic   m_staticSample                   ;
	//}}AFX_DATA
	CString& m_csExportPathname               ;
	CString& m_csExportDirectory              ;
	BOOL&    m_bHtmlSameDirectoryAsOutput     ;
	CString& m_csHtmlImageDirectory           ;
	BOOL&    m_bHtmlOpenInBrowser             ;
	BOOL&    m_bCopyAllImagesToDirectory      ;
	CString& m_csHtmlImageFileFormat          ;
	BOOL     m_bEnableInvalidFileWarning      ;

public:
	void    UpdateSample() ;

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX) ;
	virtual BOOL OnInitDialog() ;
	virtual BOOL OnWizardFinish() ;

	// Generated message map functions
	//{{AFX_MSG(CHtmlLocationPage)
	afx_msg void OnExportNameBrowse             () ;
	afx_msg void OnChangeExportName             () ;
	afx_msg void OnHtmlImagePlaceSame           () ;
	afx_msg void OnHtmlImageDirectoryBrowse     () ;
	afx_msg void OnChangeHtmlImageDirectory     () ;
	afx_msg void OnSelchangeHtmlimageFileformat () ;
	afx_msg void OnEditchangeHtmlimageFileformat() ;
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
} ;


class CHtmlBackgroundPage : public CPropertyPage
{
public:
	CHtmlBackgroundPage(CRrDoc *pDoc, HTML_EXPORT *pHtmlExport);
protected:
	CColorCombo  m_colorList;
	CRrDoc		*m_pDoc;	// Doc pointer
	HTML_EXPORT	*m_pExport;	// Pointer to HtmlExport in CRrExport...
	// Dialog Data
	//{{AFX_DATA(CHtmlBackgroundPage)
	enum { IDD = IDD_HTML2_PAGE_BACKGROUND };
	CEdit       m_editHtmlBackgroundImage ;
	CButton     m_buttonImageBrowse       ;
	CStatic     m_staticSample            ;
	//}}AFX_DATA
	CColorCombo m_comboColor              ;
	int&        m_nHtmlBackgroundType     ;
	CString&    m_csHtmlBackgroundImage   ;
	COLORREF&   m_rgbHtmlBackgroundColor  ;

private:
	BOOL	displayImage( HDC, CRect & );
	BOOL	makeFont( CDC *, CFont *, LPSTR, int, int );
	void	showSample();
public:
	// sp 12/23/96 saves the color to the member variable
	void SaveBackgroundColor();
	// sp 3/4/97 save the backgroud image information
	void SaveImagePath(CString csImageNameAndPath);

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX) ;
	virtual BOOL OnInitDialog() ;
	virtual BOOL OnWizardFinish() ;

	// Generated message map functions
	//{{AFX_MSG(CHtmlBackgroundPage)
	afx_msg void OnPaint();
	afx_msg void OnChangeColor();
	afx_msg void OnHtmlBackgroundImageBrowse() ;
	afx_msg void OnHtmlBackgroundColor      () ;
	afx_msg void OnHtmlBackgroundImage      () ;
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
} ;


class CHtmlBorderPage : public CPropertyPage
{
public:
	CHtmlBorderPage(CRrDoc *pDoc, HTML_EXPORT *pHtmlExport);
protected:
	CRrDoc		*m_pDoc;	// Doc pointer
	HTML_EXPORT	*m_pExport;	// Pointer to HtmlExport in CRrExport...
	// Dialog Data
	//{{AFX_DATA(CHtmlBorderPage)
	enum { IDD = IDD_HTML2_PAGE_BORDER };
	CEdit           m_editHtmlTableBorderWidth ;
	CSpinButtonCtrl m_spinHtmlTableBorderWidth ;
	//}}AFX_DATA
	int&            m_nHtmlTableBorderType     ;
	int&            m_nHtmlTableBorderWidth    ;

public:

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX) ;
	virtual BOOL OnInitDialog() ;
	virtual BOOL OnWizardFinish() ;

	// Generated message map functions
	//{{AFX_MSG(CHtmlBorderPage)
	afx_msg void OnBorderNone();
	afx_msg void OnBorderWidth();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
} ;

/////////////////////////////////////////////////////////////////////////////
// CHtmlDlg dialog

class CHtmlDlg : public CPropertySheet
{
// Construction
public:
	CHtmlDlg (CRrDoc* pDoc, CWnd* pParent=NULL) ;
protected:
	// Dialog Data
	//{{AFX_DATA(CHtmlDlg)
	enum { IDD = IDD_HTML2_EXPORT };
	CButton m_buttonClose ;
	//}}AFX_DATA
	CHtmlLocationPage   m_pageLocation   ;
	CHtmlBackgroundPage m_pageBackground ;
	CHtmlBorderPage     m_pageBorder     ;
public:
	HTML_EXPORT         m_HtmlExport     ;

// Implementation
protected:
	virtual BOOL OnInitDialog() ;

	// Generated message map functions
	//{{AFX_MSG(CHtmlDlg)
	afx_msg void OnHelp();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



