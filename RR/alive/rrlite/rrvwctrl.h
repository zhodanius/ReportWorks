// ****************************************************************************
//
//      (C) Copyright 1996 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
// Declaration of the ViewCtrl OLE control class, derived
// from Microsoft base control framework classes
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/rrvwctrl.h_v  $
// 
//    Rev 1.15   22 May 1997 17:50:50   par
// Charting in viewer control works
// 
//    Rev 1.14   19 May 1997 11:00:20   smh
// Changes to read old (Live 1.0) version of PDI file.
// 
//    Rev 1.13   09 May 1997 14:37:16   amh
// merge changes
// 
//    Rev 1.12   09 May 1997 13:27:34   amh
// More merging to sync-up with Steve C's latest code
// 
//    Rev 1.11   01 May 1997 16:56:46   amh
// Had to a literal WM_USER_PRINT so that RRVWCTRL.cpp would compile
// using the non-MFC callback print function
// 
//    Rev 1.10   01 May 1997 15:58:10   amh
// Removed duplicate definitions of variables from the merge
// 
//    Rev 1.9   30 Apr 1997 16:49:14   amh
// Merged with Steve C's latest source on 4-30-97
// 
//    Rev 1.8   26 Apr 1997 12:41:40   smh
// Merged Live1.0 Loc changes.
// 
//    Rev 1.7   01 Apr 1997 15:51:56   smh
// latest sources on 4/1/97
// 
//    Rev 1.6   22 Mar 1997 19:02:38   smh
// Sources from 1/24/97
// 
//    Rev 1.5.1.0   25 Apr 1997 14:31:04   smh
// Live 1.0 localization change.
// 
//    Rev 1.5   07 Jan 1997 14:10:36   smh
// Find images in ImagePath
// 
//    Rev 1.4   02 Jan 1997 15:30:48   smh
// Chage file date/time strings to pointers.
// 
//    Rev 1.3   31 Dec 1996 11:07:04   smh
// Add storage for report name and date/time string.
// 
//    Rev 1.2   19 Dec 1996 16:28:34   smh
// Added auto-comment header.
// 
//
// Class declaration for the Report Viewer control
//
#ifndef _REPORTVIEWERCONTROL_H_

#include "ipserver.h"
#include "CtrlObj.H"
#include "internet.h"
#include "RRPrViewInterfaces.H"
#include "DispIDs.H"

#define PRINTER_NAME_SIZE	_MAX_PATH

class FileRead;
class RepPage;

typedef struct
{
	RepPage	*pRepPage;
} PAGE_ARRAY;

//=--------------------------------------------------------------------------=
// ViewCtrl
//=--------------------------------------------------------------------------=
//
class ViewCtrl : public CInternetControl, public IRepView, public ISupportErrorInfo
{
  public:
    // IUnknown methods
    //
    DECLARE_STANDARD_UNKNOWN();

    // IDispatch methods
    //
    DECLARE_STANDARD_DISPATCH();

    // ISupportErrorInfo methods
    //
    DECLARE_STANDARD_SUPPORTERRORINFO();

    /* IRepView methods */
    STDMETHOD( get_ReportURL )( THIS_ BSTR FAR* path );
    STDMETHOD( put_ReportURL )( THIS_ BSTR path );

    STDMETHOD( get_ImagePath )( THIS_ BSTR FAR* path );
    STDMETHOD( put_ImagePath )( THIS_ BSTR path );

    STDMETHOD( get_LanguageID )( THIS_ BSTR FAR* path );
    STDMETHOD( put_LanguageID )( THIS_ BSTR path );

    // OLE Control stuff follows:
    //
    ViewCtrl( IUnknown *pUnkOuter );
    virtual ~ViewCtrl();

    // static creation function.  all controls must have one of these!
    //
    static IUnknown *Create( IUnknown * );

  private:
    // overridables that the control must implement.
    //
    STDMETHOD(LoadBinaryState)(IStream *pStream);
    STDMETHOD(SaveBinaryState)(IStream *pStream);
    STDMETHOD(LoadTextState)(IPropertyBag *pPropertyBag, IErrorLog *pErrorLog);
    STDMETHOD(SaveTextState)(IPropertyBag *pPropertyBag, BOOL fWriteDefault);
    STDMETHOD(OnDraw)(DWORD dvAspect, HDC hdcDraw, LPCRECTL prcBounds, LPCRECTL prcWBounds, HDC hicTargetDev, BOOL fOptimize);
	
    virtual LRESULT WindowProc(UINT msg, WPARAM wParam, LPARAM lParam);
    virtual BOOL    RegisterClassData(void);
    virtual HRESULT InternalQueryInterface(REFIID, void **);
	virtual BOOL	BeforeCreateWindow( DWORD *pdwWindowStyle, DWORD *pdwExWindowStyle, LPSTR pszWindowTitle );
    virtual BOOL	AfterCreateWindow(void);

	virtual BOOL	OnSpecialKey( LPMSG );

	// Actual properties

    // private state information.
    //
public:
	BOOL		m_bImageDLLError;
	BOOL		m_bStopThreads;
	int			m_nLangDelta;
	int			m_nPageCount;	
	int			m_nTrackPage;
	BOOL		m_bLandscape;
	BOOL		m_bReportLoaded;
	BOOL		m_bPrinting;
	BOOL		m_bScreenInit;
	BOOL		m_bGotReportURL;
	BOOL		m_bGotPrinter;
	BOOL		m_bPrintCancelled;
	BOOL		m_bGotObjects;
	BOOL		m_bGotCharts;
	int			m_nPagesPrinted;
	int			m_nPrtInchX;
	int			m_nPrtInchY;
	int			m_nCurPage;
	int			m_nToolbarHeight;
	UINT		m_nScrollPosX;
	UINT		m_nScrollPosY;
	UINT		m_nVertLineScroll;
	UINT		m_nHorzLineScroll;
	UINT		m_nVertPageScroll;
	UINT		m_nHorzPageScroll;
	TCHAR		* m_pReportURL;
	TCHAR		* m_pImagePath;
	TCHAR		*m_pRepName;
	TCHAR		*m_pRepDate;
	TCHAR		m_szPrtName[PRINTER_NAME_SIZE + 1];
	SIZE		m_sizePage;
	SIZE		m_sizeScrPage;
	SIZE		m_sizeUnprint;
	RECT		m_rectPageTip;
	RECT		m_rectDataWnd;
	HWND		m_hWndToolbar;
	HWND		m_hWndProgress;
	HANDLE		m_hMutex;
	HANDLE		m_hPrintThread;
	HANDLE		m_hReadThread;
	HINSTANCE	m_hImageLib; // Accusoft image library handle
	PAGE_ARRAY	* m_pPageArray;
	PRINTDLG	m_pd;
	DOCINFO		m_docInfo;
// Implementation
public:
		void	errorMessage( int );
		HWND	getCtrlHwnd();
		LPTSTR	loadString( int );
private:
		void	clearPageTip();
		void	displayProperties();
		BOOL	getFullURL( LPSTR );
		void	getImagePath( IPropertyBag *, IErrorLog * );
		BOOL	getPrinterInfo();
		void	getPrinterMetrics( HDC );
		void	pageScroll( UINT,BOOL );
		void	printReport();
		void	setHorzScrollRange();
		void	setScrollPos( BOOL, int );
		void	setVertScrollRange( int );
		void	showPageTip( int );
		void	startReadThread();
		void	toAdjacentPage( BOOL );
		// message handlers
		void	OnDisplayError( WPARAM, LPARAM );
		void	OnHScroll( WPARAM, LPARAM );
		void	OnPageDone( WPARAM, LPARAM );
		void	OnPagePrinted( WPARAM, LPARAM );
		void	OnPrintDone( WPARAM, LPARAM );
		void	OnPrintReport();
		void	OnReportDone( WPARAM, LPARAM );
		void	OnSize( WPARAM, LPARAM );
		void	OnVScroll( WPARAM, LPARAM );
};

// TODO: if you have an array of verbs, then add an extern here with the name
//       of it, so that you can include it in the DEFINE_CONTROLOBJECT.
//       ie.  extern VERBINFO m_WebImageCustomVerbs [];
//
//extern const GUID    *rgWebImagePropPages [];

DEFINE_CONTROLOBJECT(RepView,
    &CLSID_RepView,
    _T( "RepViewCtrl" ),
    ViewCtrl::Create,
    1,		// version
    &IID_IRepView,
    _T( "RepView.HLP" ),
    &DIID_DRepViewEvents,
    OLEMISC_SETCLIENTSITEFIRST | OLEMISC_ACTIVATEWHENVISIBLE | OLEMISC_RECOMPOSEONRESIZE | OLEMISC_CANTLINKINSIDE | OLEMISC_INSIDEOUT,
    0,
    IDB_RRPRVIEW,
    _T( "RepViewWndClass" ),
    1,
    0,	// rgWebImagePropPages,
    0,
    NULL);

// font stuff
#define LEADING				2
#define POINTSIZE			72	// a point is 1/72 inches

// progress bar dimensions
#define PROGRESS_WIDTH		200
#define PROGRESS_HEIGHT		16
#define PROGRESS_RIGHT		( PROGRESS_WIDTH + 20 )
#define PROGRESS_TOP		6
#define PROGRESS_MIN		( PROGRESS_RIGHT + 100 )

// user-defined messages
#define WM_USER_PAGEDONE		WM_USER
#define WM_USER_READDONE		( WM_USER_PAGEDONE + 1 )
#define WM_USER_PAGEPRINTED		( WM_USER_READDONE + 1 )
#define WM_USER_PRINTDONE		( WM_USER_PAGEPRINTED + 1 )
#define WM_USER_DISPLAYERROR	( WM_USER_PRINTDONE + 1 )
#define WM_USER_LOADOLE			( WM_USER_DISPLAYERROR + 1 )

//AMH 5-1-97 added this because RRVWCTRL.cpp has a non-MFC callback function
// that uses this literal "WM_USER_PRINT"
#define WM_USER_PRINT			( WM_USER_DISPLAYERROR + 1 )

#define IMAGE_READ_SIZE		500
#define MAX_IMAGE__PATH		1024

////  global variables  ////

extern BOOL g_bStopThreads;	// emergency shutdown flag

////  global function prototypes  ////

// file read routines
UINT createPageObjects( FileRead *, ViewCtrl * );
UINT createVer2PageObjects( FileRead *, ViewCtrl * );
BOOL readImages( FileRead *, RepPage *, ViewCtrl * );
BOOL readObjects( FileRead *, RepPage * );
BOOL readCharts( FileRead *, RepPage * );
// file read thread
UINT readDataFile( LPVOID );
// print report thread
UINT printReportThread( LPVOID );
// print report callback
BOOL CALLBACK abortProc( HDC, int );

#define _REPORTVIEWERCONTROL_H_

#endif // _REPORTVIEWERCONTROL_H_
