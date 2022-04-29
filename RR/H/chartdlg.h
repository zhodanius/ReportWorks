// ****************************************************************************
//
//		(C) Copyright 2001 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// ChartDlg.h : header file
//
//
// Module $Workfile:   chartdlg.h  $
// ================
//
// Description:
// ============
//
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/CHARTDLG.H_V  $
// 
//    Rev 1.40   Apr 25 2002 10:03:48   Admin
// Cosmetic
// 
//    Rev 1.39   16 Jan 1998 15:43:26   JSF
// PTF20001 merge
// 
//    Rev 1.38.1.0   23 Oct 1997 16:35:24   jsf
// charting PTF 1
// 
//    Rev 1.38   20 Jun 1997 10:24:52   jsf
// Apply button now enabled when chart size or anchor 
// is changed on the options page.
// 
//    Rev 1.37   17 Jun 1997 13:40:54   jsf
// Fixed WO131419. Chart size was inadvertently changing. 
// The problem only occurred if the horizontal or vertical spacing for 
// the ruler was set to a value other than 10. The calculations used to 
// determine height and width used the values.  The calc's where moved to
// a new function, SetChartSizes(). This function should only be called in the 
// constructor. Multiple calls might result in the failure.
// 
//    Rev 1.36   16 Jun 1997 15:10:42   jsf
// Cosmetic changes; remove radio buttons from the line style page,
// Add "bottom to top" as a Y axis choice for title,
// charts will be transparent now (prec.cpp),
// Normalize removed from as a value range choice on the options page.
//  
// 
// 
//    Rev 1.35   12 Jun 1997 15:38:52   jsf
// fixed WO130846, 131165 and 131227
// Value ranges are correct when the chart is edited.
// The apply button is enabled when controls are checked on the data page.
// The client can leave the data page w/out picking a field.
//  
// 
// 
//    Rev 1.34   11 Jun 1997 10:55:54   par
// 
// Add selection events to ohlc, scatter and bubble chart data pages.
// 
//    Rev 1.33   10 Jun 1997 18:27:36   par
// New Chart pages for High/Low/Close, Scatter and Bubble types.
// 
//    Rev 1.32   10 Jun 1997 12:06:28   par
// Move populate to CChartPage so that it can be used by new pages.
// Removed many GetBuffer/ReleaseBuffer string calls.
// 
//    Rev 1.31   09 Jun 1997 17:36:54   jsf
// Added code expand/collapse for the list boxes/combo boxes and other
// misc. changes for controls. The min/max controls now accept negative numbers.
// 
// 
//    Rev 1.30   03 Jun 1997 17:16:10   jsf
// fixed problem in CDataPage::OnInitDialog() when calling 
// AddCollectionListBox(). Added bNewChart bool to test before
// setting m_nValueFields in ChartData.
// 
//    Rev 1.29   03 Jun 1997 16:12:26   jsf
// fixes to the option page 
// 
//    Rev 1.28   02 Jun 1997 15:00:56   jsf
// fixes on the data page for drag&drop, collection box reordering
// 
//    Rev 1.27   29 May 1997 17:23:00   jsf
// Added code to call PrepareforPrinting() to CChartSheet's
// OnOK in OnCommand() method
// 
//    Rev 1.26   28 May 1997 11:28:08   par
// Connected the Chart Font dialog to real data.
// 
// 
//    Rev 1.25   27 May 1997 18:04:26   par
// Font is also a combo.
// 
//    Rev 1.24   27 May 1997 17:26:04   par
// Second pass at chart font dialog.
// 
//    Rev 1.23   27 May 1997 16:31:46   jsf
// changed how the anchor radio buttons set the anchor value
// 
//    Rev 1.22   23 May 1997 17:38:34   par
// Added chart font template.
// 
//    Rev 1.21   23 May 1997 16:30:18   jsf
// first pass at drag & drop on the data page
// 
//    Rev 1.20   21 May 1997 13:57:14   jsf
// checkin.txt
// 
//    Rev 1.19   20 May 1997 12:17:10   jsf
// checkin.txt
// 
//    Rev 1.18   19 May 1997 16:59:26   jsf
// fix for chart width and height edit control on options page
// 
//    Rev 1.17   19 May 1997 09:48:54   jsf
// checkin.txt
// 
//    Rev 1.16   13 May 1997 16:44:48   jsf
// Removed SetDefaultStyle when setting grid lines
// 
//    Rev 1.15   12 May 1997 16:14:34   jsf
// Added code to fix bugs
// 
//    Rev 1.14   11 May 1997 19:06:30   jsf
// Added a boolean to check when secondary sort should be set by 
// secondary label
// 
//    Rev 1.13   09 May 1997 14:01:54   jsf
// Added code to update the data page with fields
// from an existing chart
// 
//    Rev 1.12   02 May 1997 15:41:06   jsf
// More support for CChartSheet as a right-click property dialog
// 
//    Rev 1.11   01 May 1997 11:59:30   jsf
// changes to type page
// 
//    Rev 1.10   30 Apr 1997 15:03:12   jsf
// Added support for CChartSheet as a right-click property dialog
// 
//
// ****************************************************************************

#if !defined(_CHARTDLG_H_)
#define _CHARTDLG_H_

#include "chartres.h"
#include "gsw.h"
#include "ChartDat.h"		//common chart properties shared across property pages. object instance in CChartSheet
#include "rrchart.h"		//needed for CRrChart, member of CChartSheet so we can use chartToMF() to draw charts for the dialog.
/////////////////////////////////////////////////////////////////////////////

// Aldus Placeable Header ===================================================
// Since we are a 32bit app, we have to be sure this structure compiles to
// be identical to a 16 bit app's version. To do this, we use the #pragma
// to adjust packing, we use a WORD for the hmf handle, and a SMALL_RECT
// for the bbox rectangle.
#pragma pack( push )
#pragma pack( 2 )
typedef struct
	{
	DWORD       dwKey      ;
	WORD        hmf        ;
	SMALL_RECT  bbox       ;
	WORD        wInch      ;
	DWORD       dwReserved ;
	WORD        wCheckSum  ;
	} APMHEADER, *PAPMHEADER ;
#pragma pack( pop )
// used to read graphic server metafiles

static UINT ddcMsgQueryDrop;
static UINT ddcMsgDoDrop;
static UINT ddcMsgBeginDragDrop;

class CChartSheet;		//forward reference, pages will declare a pointer to CChartSheet to quickly create metafiles.
/////////////////////////////////////////////////////////////////////////////
// CChartPage dialog
//
// base class for all charting property pages
// Holds a pointer to the parent sheet charting data object, m_pobjChartData.
//
class CChartPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CChartPage)

// Construction
public:
	CChartPage(CChartData* pobjChartData,CRrDoc* pDoc, LPRRCHART pRrChart, UINT nIDTemplate, UINT nIDCaption=0);
	CChartPage(CChartData* pobjChartData,CRrDoc* pDoc, LPRRCHART pRrChart, LPCTSTR lpszTemplateName, UINT nIDCaption=0);
	CChartPage() {}
	~CChartPage();

	void SetStyle(int iStyle);

	CChartData*	m_pobjChartData;							//pointer to CChartSheet chart data object
	CRrDoc* m_pDoc;
	LPRRCHART m_pRRCHART;									//pointer to struct for chartToMF()

protected:
	void CreateEnhMF(CStatic* pStat);
	void SetDefaultStyle();										//on the type page, we want to set default styles so drawing works.
	BOOL OnClickCBox(CComboBox* pcb, int index=-1, BOOL bUserSelected = TRUE) ;

// Dialog Data
	//{{AFX_DATA(CChartPage)
	int		m_eStyle;
	CStatic	m_staticPicture;
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CChartPage)
	public:
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CChartPage)
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	void PopulateFieldListBox(CListBox & listbox );
	void PopulateFieldListBox(CComboBox& combobox, BOOL bSubFieldCombo=FALSE);
	int GetIndex(CListBox & listbox ,DWORD dwId);
	int GetIndex(CComboBox& combobox,DWORD dwId);
};

/////////////////////////////////////////////////////////////////////////////
// CChartType dialog
class CChartType : public CChartPage
{
	DECLARE_DYNCREATE(CChartType)

// Construction
public:
	CChartType(CChartData* pobjChartData, CRrDoc* pDoc, LPRRCHART pRrChart);
	CChartType() : m_nTabs(5) {}
	~CChartType();

void SetChartStylePage();
void EnableGridGroup(BOOL bOn);

const int m_nTabs;	//set to 5, update in constructor when adding or deleting property pages
// Dialog Data
	//{{AFX_DATA(CChartType)
	enum { IDD = IDD_TYPE_CHART };
	CButton	m_ctlCheckVertGrid;
	CButton	m_ctlCheckHorGrid;
	CButton	m_ctlGroupGrid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CChartType)
	public:
	virtual BOOL OnKillActive();
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CChartType)
	afx_msg void OnArea();
	afx_msg void OnBar();
	afx_msg void OnBubble();
	afx_msg void OnLine();
	afx_msg void OnOhlc();
	afx_msg void OnPie();
	afx_msg void OnScatter();
	virtual BOOL OnInitDialog();
	afx_msg void OnDimOrHVLine();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
// CLineStyle dialog

class CLineStyle : public CChartPage
{
	DECLARE_DYNCREATE(CLineStyle)

// Construction
public:
	CLineStyle(CChartData* pobjChartData, CRrDoc* pDoc, LPRRCHART pRrChart);
	CLineStyle(){}
	~CLineStyle();

// Dialog Data
	//{{AFX_DATA(CLineStyle)
	enum { IDD = IDD_LINE_CHART };
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CLineStyle)
	public:
	virtual BOOL OnKillActive();
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CLineStyle)
	afx_msg void OnLineModified();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};	//end CLineStyle class


/////////////////////////////////////////////////////////////////////////////
// CDDListBox dialog
class CDDListBox : public CListBox
{
	DECLARE_DYNCREATE(CDDListBox)

public:
    CDDListBox();
    virtual ~CDDListBox();

private:
    int IndexFromPoint(CPoint point);
    void UpdateSelection(int iSel, UINT nFlags, CPoint point);

    CPoint m_ptMouseDown;
    int m_iFirstIndex;
    BOOL m_bMouseOpPending;
    BOOL m_bCaptured;

    // Generated message map functions
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    //{{AFX_MSG(CDDListBox)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg LRESULT OnQueryDrop(WPARAM wParam,LPARAM lParam);
    afx_msg LRESULT OnDoDrop(WPARAM wParam,LPARAM lParam);
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()


}; // end CDDListBox
void BeginDragDrop(CWnd* pSourceWnd, UINT uiFmt, CObject* pObject);
BOOL GetDropData(CObject* pObject);

/////////////////////////////////////////////////////////////////////////////
// CDdcWnd window
// Window object used during drag and drop to receive
// mouse messages

class CDdcWnd : public CWnd
{
public:
    CDdcWnd::CDdcWnd(CWnd* pSourceWnd, UINT uiFmt);

private:
    HWND m_hwndSource;
    UINT m_uiFmt;
    HWND m_hwndOldCapture;
    HWND m_hwndUnder;
    HCURSOR m_hcurOld;
    HCURSOR m_hcurNoDrop; // 
    HCURSOR m_hcurDropOK; // 

protected:
    //{{AFX_MSG(CDdcWnd)
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CDataPage dialog

class CDataPage : public CChartPage
{
	DECLARE_DYNCREATE(CDataPage)

// Construction
public:
	CDataPage(CChartData* pobjChartData, CRrDoc* pDoc, LPRRCHART pRrChart);
	CDataPage() {}
	~CDataPage();

// Dialog Data
	//{{AFX_DATA(CDataPage)
	enum { IDD = IDD_DATA_CHART };
	CButton			m_ctlSubCombineDups;
	CButton			m_ctlCombineDups;
	CButton			m_btnDn;
	CButton			m_btnSubAscending;
	CStatic			m_staticSubField;
	CStatic			m_staticSubSort;
	CStatic			m_staticSubLabel;
	CComboBox		m_cboxSubSort;
	CComboBox		m_cboxSubLabel;
	CComboBox		m_cboxSubField;
	CButton			m_btnUp;
	CButton			m_btnRemove;
	CButton			m_btnAdd;
	CDDListBox		m_lboxCollect;
	CComboBox		m_cboxSort;
	CComboBox		m_lboxLabel;
	CDDListBox		m_lboxFields;
	//}}AFX_DATA

	int			m_nCollectCount;				//number of fields selected into collection listbox

	BOOL		m_bAutoLabel;					//flag if we default label or if client selected it.
	BOOL		m_bAutoSort;					//flag if we default sort field or client chooses. 

	BOOL		m_bSetSort;						//flag if label selected and sort not touched ,set sort as label field
	BOOL		m_bSetSubSort;					//flag if sub label selected and sub sort not touched ,set sub sort as label field

	HICON		m_hIconUp;
	HICON		m_hIconDn;
	CString		m_csFieldDragDrop;
	DWORD		m_dwFieldDragDrop;
	UINT		m_uiDDFormatID;
	int			m_nIndexDragDrop;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDataPage)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

void AddCollectionListBox(int nIndex, BOOL bNewChart = TRUE);
void UpdateCombo(int nIndex,CComboBox* pcb);
void EnableSubGroup(BOOL bOn);


// Implementation
public:
	void OnSelchangeDataCollect();
	void OnSelchangeDataFields();

protected:
	// Generated message map functions
	//{{AFX_MSG(CDataPage)
	afx_msg void OnDblclkDataFields();
	afx_msg void OnDblclkComboLabel();
	afx_msg void OnSelchangeComboLabel();
	afx_msg void OnDblclkComboSort();
	afx_msg void OnSelchangeComboSort();
	afx_msg void OnDblclkDataCollect();
	afx_msg void OnBtnAddCollect();
	afx_msg void OnBtnRemoveCollect();
	afx_msg void OnBtnCollectDn();
	afx_msg void OnBtnCollectUp();
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkComboSubcatField();
	afx_msg void OnSelchangeComboSubcatField();
	afx_msg void OnDblclkComboSubcatLabel();
	afx_msg void OnSelchangeComboSubcatLabel();
	afx_msg void OnDblclkComboSubcatSort();
	afx_msg void OnSelchangeComboSubcatSort();
	afx_msg void OnBtnSubcatClear();
    afx_msg LRESULT OnQueryDrop(WPARAM wParam,LPARAM lParam);
    afx_msg LRESULT OnDoDrop(WPARAM wParam,LPARAM lParam);
    afx_msg LRESULT OnBeginDragDrop(WPARAM wParam,LPARAM lParam);
	afx_msg void OnCheckDataPage();

	afx_msg void OnBtnLabelField();
	afx_msg void OnBtnFieldSort();
	afx_msg void OnBtnValue();
	afx_msg void OnBtnLabel();
	afx_msg void OnBtnSort();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
/////////////////////////////////////////////////////////////////////////////
// COHLCDataPage dialog

class COHLCDataPage : public CChartPage
{
	DECLARE_DYNCREATE(COHLCDataPage)

// Construction
public:
	COHLCDataPage(CChartData* pobjChartData, CRrDoc* pDoc, LPRRCHART pRrChart);
	COHLCDataPage() {}
	~COHLCDataPage();

// Dialog Data
	//{{AFX_DATA(COHLCDataPage)
	enum { IDD = IDD_OHLC_DATA_CHART };
	CComboBox		m_cboxOpen;
	CComboBox		m_cboxHigh;
	CComboBox		m_cboxLow;
	CComboBox		m_cboxClose;
	CComboBox		m_cboxLabel;
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(COHLCDataPage)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void EnableUserDefinedMinMax(BOOL bOn);

	// Generated message map functions
	//{{AFX_MSG(COHLCDataPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkOpen    ();
	afx_msg void OnSelchangeOpen ();
	afx_msg void OnDblclkHigh    ();
	afx_msg void OnSelchangeHigh ();
	afx_msg void OnDblclkLow     ();
	afx_msg void OnSelchangeLow  ();
	afx_msg void OnDblclkClose   ();
	afx_msg void OnSelchangeClose();
	afx_msg void OnDblclkLabel   ();
	afx_msg void OnSelchangeLabel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
// CScatterDataPage dialog

class CScatterDataPage : public CChartPage
{
	DECLARE_DYNCREATE(CScatterDataPage)

// Construction
public:
	CScatterDataPage(CChartData* pobjChartData, CRrDoc* pDoc, LPRRCHART pRrChart);
	CScatterDataPage() {}
	~CScatterDataPage();

// Dialog Data
	//{{AFX_DATA(CScatterDataPage)
	enum { IDD = IDD_SCATTER_DATA_CHART };
	CComboBox		m_cboxX;
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CScatterDataPage)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void EnableUserDefinedMinMax(BOOL bOn);

	// Generated message map functions
	//{{AFX_MSG(CScatterDataPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkX   ();
	afx_msg void OnSelchangeX();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
// CBubbleDataPage dialog

class CBubbleDataPage : public CChartPage
{
	DECLARE_DYNCREATE(CBubbleDataPage)

// Construction
public:
	CBubbleDataPage(CChartData* pobjChartData, CRrDoc* pDoc, LPRRCHART pRrChart);
	CBubbleDataPage() {}
	~CBubbleDataPage();

// Dialog Data
	//{{AFX_DATA(CBubbleDataPage)
	enum { IDD = IDD_BUBBLE_DATA_CHART };
	CComboBox		m_cboxX;
	CComboBox		m_cboxY;
	CComboBox		m_cboxDiameter;
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CBubbleDataPage)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void EnableUserDefinedMinMax(BOOL bOn);

	// Generated message map functions
	//{{AFX_MSG(CBubbleDataPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkX   ();
	afx_msg void OnSelchangeX();
	afx_msg void OnDblclkY   ();
	afx_msg void OnSelchangeY();
	afx_msg void OnDblclkDiameter   ();
	afx_msg void OnSelchangeDiameter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
// CTextPage dialog

class CTextPage : public CChartPage
{
	DECLARE_DYNCREATE(CTextPage)

// Construction
public:
	CTextPage(CChartData* pobjChartData, CRrDoc* pDoc, LPRRCHART pRrChart);
	CTextPage(){}
	~CTextPage();

// Dialog Data
	//{{AFX_DATA(CTextPage)
	enum { IDD = IDD_TEXT_CHART };
	CButton	m_ctlHorizontalY;
	CButton	m_ctlBottoTopY;
	CButton	m_ctlToptoBotY;
	CButton	m_ctlDataLabel;
	CButton	m_ctlLegend;
	CStatic	m_ctlStaticDepth;
	CEdit	m_ctlEditDepth;
	int		m_iHorizontalY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTextPage)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTextPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnKillfocusEditTitles();
	afx_msg void OnTextPageUpdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
/////////////////////////////////////////////////////////////////////////////
// CBarStyle dialog

class CBarStyle : public CChartPage
{
	DECLARE_DYNCREATE(CBarStyle)

// Construction
public:
	CBarStyle(CChartData* pobjChartData, CRrDoc* pDoc, LPRRCHART pRrChart);
	CBarStyle() {}
	~CBarStyle();

// Dialog Data
	//{{AFX_DATA(CBarStyle)
	enum { IDD = IDD_BAR_CHART };
	CButton m_ctlSimple;
	CButton m_ctlStacked;
	CButton m_ctlStackedPercent;
	CButton m_ctlStackedFloat;
	CButton m_ctlHorizontal;
	CButton m_ctlVertical;
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CBarStyle)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation

protected:
	// Generated message map functions
	//{{AFX_MSG(CBarStyle)
	afx_msg void OnBarModified();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
// CChartNumEdit control

class CChartNumEdit : public CEdit
{
// Construction
public:
	CChartNumEdit(CRrDoc* pDoc) : m_pDoc(pDoc) {}
	CChartNumEdit() {}
	CRrDoc* m_pDoc ;  // Need to access doc decimal separator & winBeep. 
	
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChartNumEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) ;
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
} ;

/////////////////////////////////////////////////////////////////////////////
// CChartNegPosNumEdit control

class CChartNegPosNumEdit : public CEdit
{
// Construction
public:
	CChartNegPosNumEdit(CRrDoc* pDoc) : m_pDoc(pDoc) {}
	CChartNegPosNumEdit() {}
	CRrDoc* m_pDoc ;  // Need to access doc decimal separator & winBeep. 
	
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChartNegPosNumEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) ;
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
} ;

/////////////////////////////////////////////////////////////////////////////
// COptionsPage dialog

class COptionsPage : public CChartPage
{
	DECLARE_DYNCREATE(COptionsPage)

// Construction
public:
	COptionsPage(CChartData* pobjChartData, CRrDoc* pDoc, LPRRCHART pRrChart);
	COptionsPage() {}
	~COptionsPage();

// Dialog Data
	//{{AFX_DATA(COptionsPage)
	enum { IDD = IDD_OPTIONS_CHART };
	CButton				m_ctrlAnchorTop;
	CButton				m_ctrlAnchorBottom;
	CStatic				m_staticMin;
	CStatic				m_staticMax;
	CButton				m_ctrlAuto;
	CButton				m_ctrlUserDefined;
	CChartNegPosNumEdit	m_ctrlMinRange;
	CChartNegPosNumEdit	m_ctrlMaxRange;
	CChartNumEdit		m_ctrlWidth;
	CChartNumEdit		m_ctrlHeight;
	CSpinButtonCtrl		m_ctrlSpinWidth;
	CSpinButtonCtrl		m_ctrlSpinHeight;
	int					m_iAnchor;
	CString				m_csHeight;
	CString				m_csWidth;
	CString				m_csMaxRange;
	CString				m_csMinRange;
	int					m_iValueRange;
	//}}AFX_DATA

	double	m_dHeight;
	double	m_dWidth;
	BOOL	m_bInitSizes;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(COptionsPage)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:
void EnableUserDefinedMinMax(BOOL bOn);

	// Generated message map functions
	//{{AFX_MSG(COptionsPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnValueRange();
	afx_msg void OnAnchorChange();
	afx_msg void OnChangeEditChartSize();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
// CChartFontPage dialog

class CChartFontPage : public CChartPage
{
	DECLARE_DYNCREATE(CChartFontPage)

// Construction
public:
	CChartFontPage(CChartData* pobjChartData, CRrDoc* pDoc, LPRRCHART pRrChart);
	CChartFontPage() {}
	~CChartFontPage();

// Dialog Data
	//{{AFX_DATA(CChartFontPage)
	enum { IDD = IDD_FONT_CHART };
	CButton m_ctlTitle      ;
	CButton m_ctlAxisTitle  ;
	CButton m_ctlDataLabel  ;
	CButton m_ctlLegend     ;
	CButton	m_ctlGroupFont  ;
	CComboBox m_comboPalette;
	CComboBox m_comboFont   ;
	CComboBox m_comboFontSize;
	//}}AFX_DATA
	int	 m_iFont;
	int	 m_iFontSize;
	CString m_csCurrentFont;
	BOOL m_bChangeFont;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CChartFontPage)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString SetFontSize(int iFont);
	CString SaveFontSize(int iFont);

	// Generated message map functions
	//{{AFX_MSG(CChartFontPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeChartFontBase();
	afx_msg void OnSelchangeChartFontPaletteList();
	afx_msg void OnWhichFont();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
// CPieStyle dialog

class CPieStyle : public CChartPage
{
	DECLARE_DYNCREATE(CPieStyle)

// Construction
public:
	CPieStyle(CChartData* pobjChartData, CRrDoc* pDoc, LPRRCHART pRrChart);
	CPieStyle() {}
	~CPieStyle();
	
// Dialog Data
	//{{AFX_DATA(CPieStyle)
	enum { IDD = IDD_PIE_CHART };
	CButton m_ctlPieNoLabel;
	CButton m_ctlPieConnectLines;
	CButton m_ctlPieColorSlice;
	CButton m_ctlPiePercent;
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPieStyle)
	public:
	virtual BOOL OnKillActive();
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void OnPieStyleModified();
	// Generated message map functions
	//{{AFX_MSG(CPieStyle)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
/////////////////////////////////////////////////////////////////////////////
// CAreaStyle dialog

class CAreaStyle : public CChartPage
{
	DECLARE_DYNCREATE(CAreaStyle)

// Construction
public:
	CAreaStyle(CChartData* pobjChartData, CRrDoc* pDoc, LPRRCHART pRrChart);
	CAreaStyle() {}
	~CAreaStyle();

// Dialog Data
	//{{AFX_DATA(CAreaStyle)
	enum { IDD = IDD_AREA_CHART };
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CAreaStyle)
	public:
	virtual BOOL OnKillActive();
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CAreaStyle)
	afx_msg void OnAreaModified();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
/////////////////////////////////////////////////////////////////////////////
// CScatterStyle dialog

class CScatterStyle : public CChartPage
{
	DECLARE_DYNCREATE(CScatterStyle)

// Construction
public:
	CScatterStyle(CChartData* pobjChartData, CRrDoc* pDoc, LPRRCHART pRrChart);
	CScatterStyle() {}
	~CScatterStyle();

// Dialog Data
	//{{AFX_DATA(CScatterStyle)
	enum { IDD = IDD_SCATTER_CHART };
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CScatterStyle)
	public:
	virtual BOOL OnKillActive();
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CScatterStyle)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
/////////////////////////////////////////////////////////////////////////////
// COHLCStyle dialog

class COHLCStyle : public CChartPage
{
	DECLARE_DYNCREATE(COHLCStyle)

// Construction
public:
	COHLCStyle(CChartData* pobjChartData, CRrDoc* pDoc, LPRRCHART pRrChart);
	COHLCStyle() {}
	~COHLCStyle();

// Dialog Data
	//{{AFX_DATA(COHLCStyle)
	enum { IDD = IDD_OHLC_CHART };
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(COHLCStyle)
	public:
	virtual BOOL OnKillActive();
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(COHLCStyle)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
// CBubbleStyle dialog

class CBubbleStyle : public CChartPage
{
	DECLARE_DYNCREATE(CBubbleStyle)

// Construction
public:
	CBubbleStyle(CChartData* pobjChartData, CRrDoc* pDoc, LPRRCHART pRrChart);
	CBubbleStyle() {}
	~CBubbleStyle();

// Dialog Data
	//{{AFX_DATA(CBubbleStyle)
	enum { IDD = IDD_BUBBLE_CHART };
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CBubbleStyle)
	public:
	virtual BOOL OnKillActive();
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CBubbleStyle)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
/////////////////////////////////////////////////////////////////////////////
// CChartSheet

class CChartSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CChartSheet)

// Construction
public:
	CChartSheet(CRrDoc* pDoc);									//existing chart
	CChartSheet(CRrDoc* pDoc, PRECT prect);						//new, inserting chart

// Attributes
public:
	CChartData			m_objChartData;		// UI object to gather settings, Set/Get functions of CRrChart will 
	CChartType			m_pageType;			//0
	CBarStyle			m_pageBarStyle;		//1.a
	CLineStyle			m_pageLineStyle;	//1.b
	CPieStyle			m_pagePieStyle;		//1.c
	CAreaStyle			m_pageAreaStyle;	//1.d
	CScatterStyle		m_pageScatterStyle;	//1.e
	COHLCStyle			m_pageOHLCStyle;	//1.f
	CBubbleStyle		m_pageBubbleStyle;	//1.g

	CDataPage			m_pageData;			//2.a
	COHLCDataPage		m_pageOHLCData;		//2.b
	CScatterDataPage	m_pageScatterData;	//2.c
	CBubbleDataPage		m_pageBubbleData;	//2.d
	CTextPage 			m_pageText;			//3
	COptionsPage		m_pageOptions;		//4
	CChartFontPage		m_pageFont;         //5

	CRrDoc*				m_pDoc;
	RRCHART				m_rrChart;			// Internals object to pass chartToMF() to draw the chart.
// Operations
public:
	void SetChartSizes(int nwidth, int nheight);	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChartSheet)
	public:
	virtual BOOL OnInitDialog();
	protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChartSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CChartSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
#endif // _CHARTDLG_H_
