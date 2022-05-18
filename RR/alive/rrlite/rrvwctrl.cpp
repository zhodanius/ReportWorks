// ****************************************************************************
//
//		(C) Copyright 1996 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
// Implementation of the ViewCtrl OLE control class
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/alive/rrlite/RRVWCTRL.CPV  $
// 
//    Rev 1.22   Feb 28 2001 09:25:38   nhubacker
// Debug
// 
//    Rev 1.21   10 Jul 1997 13:32:10   smh
// Fixed comp error from last checkin.
// 
//    Rev 1.20   10 Jul 1997 13:05:00   smh
// Use the Read Thread exit code to determine if the thread has terminated.
// 
//    Rev 1.19   22 May 1997 16:30:34   par
// Charts are now being displayed in the viewer control.
// 
//    Rev 1.18   12 May 1997 21:57:44   smh
// Removed obsolete static (lpButtonProc).
// 
//    Rev 1.17   09 May 1997 14:37:00   amh
// Merge changes
// 
//    Rev 1.16   09 May 1997 13:22:54   amh
// More merging to sync-up with Steve's C latest code
// 
//    Rev 1.15   02 May 1997 10:07:22   amh
// Removed duplicate definitions from the module
// 
//    Rev 1.14   30 Apr 1997 16:48:30   amh
// Merged with Steve C's latest source on 4-30-97
// 
//    Rev 1.13   30 Apr 1997 14:29:30   smh
// Another attempt at localization merge
//
//    Rev 1.12   26 Apr 1997 12:41:34   smh
// Merged Live1.0 Loc changes.
// 
//    Rev 1.11   01 Apr 1997 15:52:08   smh
// latest sources on 4/1/97
// 
//    Rev 1.10   22 Mar 1997 19:52:44   smh
// Sources from 1/24/97
// 
//    Rev 1.9.1.1   26 Apr 1997 11:33:54   smh
// Moved VariantClear before assignments for NT.
// 
//    Rev 1.9.1.0   25 Apr 1997 14:27:40   smh
// Live 1.0 localization change.
// Also includes check from InternetCanoniclizeUrl for insufficient
// buffer size.  Was in Steve's version of source and thought it safer
// to use this than to merge localization change with english shipping
// version of source.
// 
//    Rev 1.9   07 Jan 1997 14:12:50   smh
// Find images in ImagePath
// 
//    Rev 1.8   02 Jan 1997 15:33:10   smh
// Change file date/time strings to pointers.
// 
//    Rev 1.7   31 Dec 1996 11:03:04   smh
// Add storage for report name and date/time string.
// 
//    Rev 1.6   19 Dec 1996 16:26:06   smh
// Added auto-comment header.
// 
#include <tchar.h>
#include "RrvwCtrl.h"
#include "LocalObj.H"
#include "Util.H"
#include "Globals.H"
#include "Resource.H"
#include "reppage.h"
#include "viewtext.h"
#include "rrutil.h"
#include <commctrl.h>
#include <wininet.h>
//#include "IPServer.H"
//#include "accusoft.h"
#include "rrlangid.h"

// emergency shutdown flag
BOOL g_bStopThreads = FALSE;

// toolbar button info
TBBUTTON tbButtons[] = {
	{ 0, 0, TBSTATE_ENABLED, TBSTYLE_SEP, 0L, 0},
	{ 0, IDC_PRINTREPORT, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0L, 0},
	{ 0, 0, TBSTATE_ENABLED, TBSTYLE_SEP, 0L, 0},
	{ 1, IDC_PROPERTIES, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0L, 0}
};

////////////////////////////////////////////////////////////////////////
// Report file URL property name
WCHAR wszReportURL [] = L"ReportURL";
// Image path property name
//WCHAR wszImagePath[] = L"ImagePath";
//AMH 5-2-97 already defined in imgpath.cpp

// Language ID property name
WCHAR wszLanguageID[] = L"LanguageID";

//=--------------------------------------------------------------------------=
// ViewCtrl::Create - Microsoft base control framework function
//=--------------------------------------------------------------------------=
// global static function that creates an instance of the control an returns
// an IUnknown pointer for it.
//
// Parameters:
//    IUnknown *        - [in] controlling unknown for aggregation
//
// Output:
//    IUnknown *        - new object.
//
IUnknown *ViewCtrl::Create( IUnknown *pUnkOuter )
{
    // make sure we return the private unknown so that we support aggegation
    // correctly!
    //
    ViewCtrl *pNew = new ViewCtrl( pUnkOuter );
    return pNew->PrivateUnknown();
}

////////////////////////////////////////////////////////////////////////
// Control constructor

#pragma warning(disable:4355)  // using 'this' in constructor

ViewCtrl::ViewCtrl( IUnknown *pUnkOuter )
	: CInternetControl( pUnkOuter, OBJECT_TYPE_REPVIEWCTRL, (IDispatch *)this )
{
	SIZEL sizeL;

	//sizeL.cx = 400;  //changed as a test by CAS 9/23/2014
	sizeL.cx = 800;
	sizeL.cy = 250;
	SetControlSize( &sizeL );			// set a reasonable default window size

	g_bStopThreads = FALSE;				// global emergency shutdown flag
	m_hReadThread = NULL;				// initialize read thread
	m_hPrintThread = NULL;				// initialize print thread
	m_pReportURL = NULL;				// URL property
	m_pImagePath = NULL;				// image path
	m_nLangDelta = 0;					// language ID string table delta
	m_nCurPage = 0;						// page one
	m_nTrackPage = -1;					// tracking page
	m_bGotPrinter = FALSE;				// default to no printer
	m_bGotObjects = FALSE;				// no OLE objects
	m_bGotCharts  = FALSE;				// no charts
	m_szPrtName[0] = '\0';				// no printer yet
	m_pRepName = NULL;					// no report name
	m_pRepDate = NULL;					// no report date
	m_hWndToolbar = NULL;				// no toolbar yet
	m_nToolbarHeight = 0;
	m_hWndProgress = NULL;				// progress bar handle
	m_nPageCount = 0;					// no pages (yet)
	m_bLandscape = FALSE;				// portrait
	m_bReportLoaded = FALSE;			// no report data loaded
	m_sizePage.cx = 0;					// no page size
	m_sizePage.cy = 0;
	m_sizeScrPage.cx = 0;				// no screen page size
	m_sizeScrPage.cy = 0;
	m_sizeUnprint.cx = HZRES / 4;		// default unprintable regions to 1/4"
	m_sizeUnprint.cy = HZRES / 4;		// (in case there's no default printer)
	m_pPageArray = NULL;				// no pages buffered
	m_bPrinting = FALSE;				// not printing now
	m_nScrollPosX = 0;					// scroll positions
	m_nScrollPosY = 0;
	m_bImageDLLError = FALSE;			// Accusoft DLL load flag
	m_bGotReportURL = FALSE;			// ain't got no URL yet
	::SetRectEmpty( &m_rectDataWnd );	// data portion of control window
	::SetRectEmpty( &m_rectPageTip );	// page tooltip
	
// initialize document info structure
	m_docInfo.cbSize = sizeof( DOCINFO );
	m_docInfo.lpszOutput = NULL;
	// For Windows 95:
	m_docInfo.lpszDatatype = NULL;
	m_docInfo.fwType = 0;
	m_hImageLib = NULL;	// Accusoft not loaded
	// create mutual exclusion object to synch Accusoft functions
	m_hMutex = CreateMutex( NULL, FALSE, _T( "RRPrViewImage" ));
}

#pragma warning(default:4355)  // using 'this' in constructor

////////////////////////////////////////////////////////////////////////
// Control destructor
ViewCtrl::~ViewCtrl ()
{
	if ( m_hReadThread || m_hPrintThread )
	{	// Someone is shutting us down while we're still printing or
		// reading data.  We need to close down any active threads.
		// Only one of the threads can be active, since we don't
		// allow printing until the entire report is read.
		HANDLE hThread = m_hReadThread ? m_hReadThread : m_hPrintThread;
		// Set flag to signal threads to shut down
		g_bStopThreads = TRUE;
		// Wait around a while to buy some time
		if ( WaitForSingleObject( hThread, 30000 ) == WAIT_TIMEOUT )
		{ // we've waited long enough (the user thinks so too)
		
			// TerminateThread can leave stuff a bit unstable, but we have
			// to stop the running thread because it's using a pointer to
			// the ViewCtrl object.  This is a last-resort procedure.
			TerminateThread( hThread, FALSE );
		}
	}
	if ( m_pReportURL )
		delete [] m_pReportURL;
	if ( m_pImagePath )
		delete [] m_pImagePath;
	if ( m_pPageArray != NULL )
	{ // destroy page objects
		for ( int ii = 0; ii < m_nPageCount; ii++ )
		{ // clean up page buffers
			if ( m_pPageArray[ii].pRepPage != NULL )
			{ // free page buffer
				delete m_pPageArray[ii].pRepPage;
			}
		}
		// now free page array
		HeapFree( GetProcessHeap(), 0, m_pPageArray );
	}
	// and free Accusoft library
	if ( m_hImageLib != NULL )
		::FreeLibrary( m_hImageLib );
	// free report name and date buffers
	if ( m_pRepName )
		delete [] m_pRepName;
	if ( m_pRepDate )
		delete [] m_pRepDate;
}

//=--------------------------------------------------------------------------=
// ViewCtrl:RegisterClassData - Microsoft base control framework function
//=--------------------------------------------------------------------------=
// register the window class information for your control here.
// this information will automatically get cleaned up for you on DLL shutdown.
//
// Output:
//    BOOL            - FALSE means fatal error.
//
// Notes:
//
BOOL ViewCtrl::RegisterClassData()
{
    WNDCLASS wndClass;

    // TODO: register any additional information you find interesting here.
    //       this method is only called once for each type of control
    //
    ZeroMemory( &wndClass, sizeof( WNDCLASS ));
    wndClass.style          = CS_VREDRAW | CS_HREDRAW;
    wndClass.lpfnWndProc    = COleControl::ControlWindowProc;
    wndClass.hInstance      = g_hInstance;
    wndClass.hCursor        = LoadCursor( NULL, IDC_ARROW );
    wndClass.hbrBackground  = (HBRUSH)( COLOR_WINDOW + 1 );
    wndClass.lpszClassName  = WNDCLASSNAMEOFCONTROL( OBJECT_TYPE_REPVIEWCTRL );

    return RegisterClass( &wndClass );
}

//=--------------------------------------------------------------------------=
// ViewCtrl::BeforeCreateWindow - Microsoft base control framework function
//=--------------------------------------------------------------------------=
// called just before the window is created.  Great place to set up the
// window title, etc, so that they're passed in to the call to CreateWindowEx.
// speeds things up slightly.
//
// Notes:
//
BOOL ViewCtrl::BeforeCreateWindow( DWORD *pdwWindowStyle, DWORD *pdwExWindowStyle, LPSTR pszWindowTitle )
{
    // add the style bits we need
    *pdwWindowStyle |= WS_VSCROLL | WS_CLIPCHILDREN;
	return TRUE;
}

////////////////////////////////////////////////////////////////////////
// Called after control window created - Microsoft base control framework function
BOOL ViewCtrl::AfterCreateWindow( void )
{
	// 07/10/97 PAR.  It is possible that the read thread has completed, 
	// but since the m_hwnd was NULL, the PostMessage() never actually 
	// executed OnReportDone.  So, the handle will not be NULL and the 
	// thread will be done.  The simple solution is to call the OnReportDone
	// by hand if the thread is no longer active. 
	if ( m_hReadThread )
	{
		DWORD dwReadFileExitCode=0;
		GetExitCodeThread ( m_hReadThread, &dwReadFileExitCode );
		if ( dwReadFileExitCode != STILL_ACTIVE )
		{
			OnReportDone ( m_bReportLoaded, dwReadFileExitCode & 0x7fffffff ) ;
		}
	}
	// create the toolbar control
	m_hWndToolbar = ::CreateToolbarEx( 
		m_hwnd,						// parent
		WS_CHILD | WS_BORDER | WS_VISIBLE | TBSTYLE_TOOLTIPS,   // window style
		ID_TOOLBAR,					// toolbar id
		2,							// number of bitmaps
		g_hInstance,				// mod instance
		IDB_TOOLBAR,				// resource ID for bitmap
		(LPCTBBUTTON)&tbButtons,	// address of buttons
		4,							// number of buttons (including separators)
		16, 16,						// width & height of buttons
		16, 16,						// width & height of bitmaps
		sizeof( TBBUTTON ));		// structure size
	if ( m_hWndToolbar )
	{ // compute & save bar height
		RECT tbRect;
		::GetWindowRect( m_hWndToolbar, &tbRect );
		m_nToolbarHeight = tbRect.bottom - tbRect.top;
	}
	RECT rcClient;
	::GetClientRect( m_hwnd, &rcClient );
	if ( !m_bReportLoaded && ( m_hWndProgress != (HWND)-1) && rectWidth( &rcClient ) > PROGRESS_MIN )
	{ // create progress indicator
		m_hWndProgress = ::CreateWindowEx(
			0,							// no extended styles
			PROGRESS_CLASS,				// class name
			(LPTSTR) NULL,				// title (caption)
			WS_CHILD | WS_VISIBLE,		// style
			rcClient.right - PROGRESS_RIGHT, PROGRESS_TOP,	// position
			PROGRESS_WIDTH, PROGRESS_HEIGHT,// size
			m_hwnd,						// parent
			(HMENU)IDC_PROGRESS,		// control ID
			g_hInstance,				// instance handle
			NULL );						// no WM_CREATE parameter
	}
	// get default printer info
	m_bGotPrinter = getPrinterInfo();
	if ( !m_bGotPrinter ) // disable print button if no printer
		::SendMessage( m_hWndToolbar, TB_ENABLEBUTTON,
			IDC_PRINTREPORT, 0);
	return TRUE;
}

//=--------------------------------------------------------------------------=
// ViewCtrl::InternalQueryInterface - Microsoft base control framework function
//=--------------------------------------------------------------------------=
// qi for things only we support.
//
// Parameters:
// Parameters:
//    REFIID        - [in]  interface they want
//    void **       - [out] where they want to put the resulting object ptr.
//
// Output:
//    HRESULT       - S_OK, E_NOINTERFACE
//
HRESULT ViewCtrl::InternalQueryInterface( REFIID  riid, void  **ppvObjOut )
{
    IUnknown *pUnk;

    *ppvObjOut = NULL;

    // TODO: if you want to support any additional interrfaces, then you should
    // indicate that here.  never forget to call COleControl's version in the
    // case where you don't support the given interface.
    //
    if ( DO_GUIDS_MATCH( riid, IID_IRepView ))
        pUnk = (IUnknown *)(IRepView *)this;
	else
        return COleControl::InternalQueryInterface( riid, ppvObjOut );

    pUnk->AddRef();
    *ppvObjOut = (void *)pUnk;
    return S_OK;
}

//=--------------------------------------------------------------------------=
// ViewCtrl::LoadTextState - Microsoft base control framework function
//=--------------------------------------------------------------------------=
// load in our text state for this control.
//
// Parameters:
//    IPropertyBag *        - [in] property bag to read from
//    IErrorLog *           - [in] errorlog object to use with proeprty bag
//
// Output:
//    HRESULT
//
// Notes:
//    - NOTE: if you have a binary object, then you should pass an unknown
//      pointer to the property bag, and it will QI it for IPersistStream, and
//      get said object to do a Load()
//
STDMETHODIMP ViewCtrl::LoadTextState( IPropertyBag *pPropertyBag, IErrorLog *pErrorLog )
{
VARIANT v;

	VariantInit( &v );
	v.vt = VT_BSTR;
	v.bstrVal = NULL;
	// get language ID if any
	pPropertyBag->Read( ::wszLanguageID, &v, pErrorLog );
	int nID = 0;
	if ( v.bstrVal )
	{ // got language ID in object tag
		MAKE_ANSIPTR_FROMWIDE( pLang, v.bstrVal );
		nID = convertLangStr( pLang );
	}
	else
	{ // not specified, try user default setting
		TCHAR szLangID[10];
		if ( GetLocaleInfo( LOCALE_USER_DEFAULT, LOCALE_ILANGUAGE, szLangID, sizeof( szLangID )))
			nID = convertLangStr( szLangID );
	}
	switch ( nID )
	{ // set string table delta for non-English languages
		case LANG_GER:
			m_nLangDelta = GERMAN_DELTA;	// German
			break;
		case LANG_FRE:
			m_nLangDelta = FRENCH_DELTA;	// French
			break;
		case LANG_SPA:
			m_nLangDelta = SPANISH_DELTA;	// Spanish
			break;
		case LANG_ITA:
			m_nLangDelta = ITALIAN_DELTA;	// Italian
			break;
	}
	// get report URL
	VariantClear( &v );		// VariantClear must come before the two assignments below
									// caused report to not display in control under NT
	v.vt = VT_BSTR;
	v.bstrVal = NULL;
	pPropertyBag->Read( ::wszReportURL, &v, pErrorLog );
	if ( v.bstrVal )
	{
		MAKE_ANSIPTR_FROMWIDE( pReportURL, v.bstrVal );
		DWORD dwLen = lstrlen( pReportURL );
		if ( dwLen )	// get the full URL address
			 m_bGotReportURL = getFullURL( pReportURL );
	}
	VariantClear( &v );
	if ( m_bGotReportURL )
	{ // got data file address, now get image path to image files
		getImagePath( pPropertyBag, pErrorLog );
		// now read data file
		startReadThread();
	}
    return S_OK;
}

//=--------------------------------------------------------------------------=
// ViewCtrl::LoadBinaryState - Microsoft base control framework function
//=--------------------------------------------------------------------------=
// loads in our binary state using streams.
//
// Parameters:
//    IStream *            - [in] stream to write to.
//
// Output:
//    HRESULT
//
STDMETHODIMP ViewCtrl::LoadBinaryState( IStream *pStream )
{
	return S_OK;
}

//=--------------------------------------------------------------------------=
// ViewCtrl::SaveTextState - Microsoft base control framework function
//=--------------------------------------------------------------------------=
// saves out the text state for this control using a property bag.
//
// Parameters:
//    IPropertyBag *        - [in] the property bag with which to work.
//    BOOL                  - [in] if TRUE, then write out ALL properties, even
//                            if they're their the default value ...
//
// Output:
//    HRESULT
//
STDMETHODIMP ViewCtrl::SaveTextState( IPropertyBag *pPropertyBag, BOOL fWriteDefaults )
{
	return S_OK;
}

//=--------------------------------------------------------------------------=
// ViewCtrl::SaveBinaryState - Microsoft base control framework function
//=--------------------------------------------------------------------------=
// save out the binary state for this control, using the given IStream object.
//
// Parameters:
//    IStream  *             - [in] save to which you should save.
//
// Output:
//    HRESULT
//
// Notes:
//    - it is important that you seek to the end of where you saved your
//      properties when you're done with the IStream.
//
STDMETHODIMP ViewCtrl::SaveBinaryState( IStream *pStream )
{
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
// Pass main control window handle over to worker threads
HWND ViewCtrl::getCtrlHwnd( void )
{
	return m_hwnd;
}

///////////////////////////////////////////////////////////////////////
// "Get" report URL property function
STDMETHODIMP ViewCtrl::get_ReportURL( BSTR * pPath )
{
	CHECK_POINTER( pPath );

	// Actually we need to be accepting (happily IMoniker objects)

//	path->vt = VT_BSTR;
		
	BSTR * pBstrPath = pPath; //&path->bstrVal;
    
    *pBstrPath = ( m_pReportURL && *m_pReportURL ) ?
		BSTRFROMANSI( m_pReportURL ) : SysAllocString(L"");

    return *pBstrPath ? S_OK : E_OUTOFMEMORY;
}

///////////////////////////////////////////////////////////////////////
// "Put" report URL property function
STDMETHODIMP ViewCtrl::put_ReportURL( BSTR pPath )
{
	// NOTE: We should reference and IMoniker*!!

//	if( path.vt != VT_BSTR )
//		return(E_UNEXPECTED);

	BSTR & bstrPath = pPath; //.bstrVal;
    // get an ANSI pointer, so we can stuff it in our local buffer for captions!
    //

    MAKE_ANSIPTR_FROMWIDE( pszPath, bstrPath );

	if ( m_pReportURL )
		delete [] m_pReportURL;
	DWORD dwLen = lstrlen( pszPath );
	m_pReportURL = new TCHAR[dwLen + 1];
	if ( m_pReportURL )
		lstrcpy( m_pReportURL, pszPath );

	// update anybody who cares about property changes and mark ourselves
	// as dirty
	//
	PropertyChanged( DISPID_REPORTURL );

    return m_pReportURL ? S_OK : E_OUTOFMEMORY;
}

///////////////////////////////////////////////////////////////////////
// "Get" image path property function
STDMETHODIMP ViewCtrl::get_ImagePath( BSTR * pPath )
{
	CHECK_POINTER( pPath );

	// Actually we need to be accepting (happily IMoniker objects)

//	path->vt = VT_BSTR;
		
	BSTR * pBstrPath = pPath; //&path->bstrVal;
    
    *pBstrPath = ( m_pImagePath && *m_pImagePath ) ?
		BSTRFROMANSI( m_pImagePath ) : SysAllocString(L"");

    return *pBstrPath ? S_OK : E_OUTOFMEMORY;
}

///////////////////////////////////////////////////////////////////////
// "Put" image path property function
STDMETHODIMP ViewCtrl::put_ImagePath( BSTR pPath )
{
	BSTR & bstrPath = pPath; //.bstrVal;
    // get an ANSI pointer, so we can stuff it in our local buffer for captions!
    //

    MAKE_ANSIPTR_FROMWIDE( pszPath, bstrPath );

	if ( m_pImagePath )
		delete [] m_pImagePath;
	DWORD dwLen = lstrlen( pszPath );
	m_pImagePath = new TCHAR[dwLen + 1];
	if ( m_pImagePath )
		lstrcpy( m_pImagePath, pszPath );

	// update anybody who cares about property changes and mark ourselves
	// as dirty
	//
	PropertyChanged( DISPID_IMAGEPATH );

    return m_pImagePath ? S_OK : E_OUTOFMEMORY;
}

///////////////////////////////////////////////////////////////////////
// Get language ID
STDMETHODIMP ViewCtrl::get_LanguageID( BSTR * pPath )
{
    return S_OK;
}

///////////////////////////////////////////////////////////////////////
// "Put" language ID
STDMETHODIMP ViewCtrl::put_LanguageID( BSTR pPath )
{
    return S_OK;
}

///////////////////////////////////////////////////////////////////////
// Create file reader thread
void ViewCtrl::startReadThread( void )
{
	if ( !m_hReadThread )
	{ // first start up the file reader thread
		if ( !m_nPageCount && !DesignMode())
		{ // no pages read - we're in "User Mode"
			if ( m_bGotReportURL && lstrlen( m_pReportURL ))
			{ // create file reader thread
				m_docInfo.lpszDocName = m_pReportURL;
				// start the thread, and hope for the best...
				DWORD dwThreadID;
				m_hReadThread = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)readDataFile,
					this, 0, &dwThreadID );
				if ( !m_hReadThread )
					errorMessage( IDS_ERR_READ_THREAD );
			}
			else	// bad report URL
				errorMessage( IDS_ERR_READ_SYSTEM );
//			{
//				if (m_bGotReportURL)
//	::MessageBox( NULL, "Bad m_pReportURL", "BooBoo", MB_ICONSTOP | MB_TASKMODAL );
//				else
//	::MessageBox( NULL, m_pReportURL, "BooHoo", MB_ICONSTOP | MB_TASKMODAL );
//			}
		}
	}
}

/*****************************************/
/***          Message Handlers         ***/
/*****************************************/

//=--------------------------------------------------------------------------=
// ViewCtrl::WindowProc - Based on Microsoft base control framework function
//=--------------------------------------------------------------------------=
// window procedure for this control.  nothing terribly exciting.
//
// Parameters:
//     see win32sdk on window procs.
//
// Notes:
//
LRESULT ViewCtrl::WindowProc( UINT msg, WPARAM wParam, LPARAM lParam )
{
	WORD wID = LOWORD( wParam );

	switch ( msg )
	{
		case WM_LBUTTONDOWN:
			// try to get the focus for keyboard
			SetFocus( TRUE );
			break;
		case WM_SETFOCUS:
			// just flash to indicate we're keyboard ready
			InvalidateControl( NULL );
			break;
		case WM_SIZE:
			OnSize( wParam, lParam );
			break;
		case WM_ERASEBKGND:
			return TRUE;
		case WM_HSCROLL:
			OnHScroll( wParam, lParam );
			return TRUE;
		case WM_VSCROLL:
			OnVScroll( wParam, lParam );
			return TRUE;
		case WM_SETTINGCHANGE:
			// uh oh, better check printer situation
			m_bGotPrinter = getPrinterInfo();
			::SendMessage( m_hWndToolbar, TB_ENABLEBUTTON,
				IDC_PRINTREPORT, (LPARAM)MAKELONG( m_bGotPrinter, 0 ));
			break;
		case WM_COMMAND:
			if ( wID == IDC_PRINTREPORT )
				OnPrintReport();	// launch print dialog
			else if ( wID == IDC_PROPERTIES )
				displayProperties();	// display properties dialog
			break;
		case WM_NOTIFY:
            if ((((LPNMHDR)lParam)->code ) == TTN_NEEDTEXT )
            { // display the ToolTip text
				LPTOOLTIPTEXT pToolTipText = (LPTOOLTIPTEXT)lParam;
   				pToolTipText->lpszText = loadString ( pToolTipText->hdr.idFrom );
			}
	        break;
		//
		// User messages
		//
		case WM_USER_PAGEDONE:
			OnPageDone( wParam, lParam );
			break;
		case WM_USER_READDONE:
			OnReportDone( wParam, lParam );
			break;
		case WM_USER_PAGEPRINTED:
			OnPagePrinted( wParam, lParam );
			break;
		case WM_USER_PRINTDONE:
			OnPrintDone( wParam, lParam );
			break;
		case WM_USER_DISPLAYERROR:
			OnDisplayError( wParam, lParam );
			break;
		case WM_USER_LOADOLE:
			{ // load ole object for rendering
				RepPage *pRepPage = m_pPageArray[m_nCurPage].pRepPage;
				if ( pRepPage->loadObject( wParam ))
			        InvalidateRect( m_hwnd, NULL, FALSE );	// show object
			}
			break;
		default:
			return OcxDefWindowProc( msg, wParam, lParam );
	}
	return FALSE;
}

////////////////////////////////////////////////////////////////////////
// Page was read, update display
void ViewCtrl::OnPageDone( WPARAM wParam, LPARAM )
{
	// turn off scroll bar if not landscape mode
	if ( !m_bLandscape )
		ShowScrollBar( m_hwnd, SB_HORZ, FALSE );
	//  wParam holds current page-1
	if ( !wParam )
	{ // first page
		InvalidateControl( NULL );
		if ( m_hWndProgress )
		{ // set range/increment of progress bar
			::SendMessage( m_hWndProgress, PBM_SETRANGE, 0, MAKELPARAM( 0, m_nPageCount )); 
			::SendMessage( m_hWndProgress, PBM_SETSTEP, 1, 0 ); 
		}
	}
	// show our progress
	if ( m_hWndProgress )
		::SendMessage( m_hWndProgress, PBM_STEPIT, 0, 0 );
	setVertScrollRange( wParam + 1 );	// set the current scroll range
}

////////////////////////////////////////////////////////////////////////
//  File read thread done, remove progress bar & display any errors
//
//  wParam:	TRUE -	Report fully loaded
//			FALSE -	Error reading file

void ViewCtrl::OnReportDone( WPARAM wParam, LPARAM lParam )
{
	BOOL bSuccess = (BOOL)wParam;

	m_hReadThread = NULL;	// assume thread has terminated
	if ( m_hWndProgress )
	{
		DestroyWindow( m_hWndProgress );
		m_hWndProgress = (HWND)-1;
	}
	// check if data file loaded
	if ( !bSuccess )
	{	// Problem with report data file. An error message
		// string id may be in lParam.
		if ( lParam )
			errorMessage( lParam );
	}
	else
	{ // if file read, check if image DLL loaded
		if ( m_bImageDLLError )
			errorMessage( IDS_ERR_IMAGELIB );
	}
}

/////////////////////////////////////////////////////////////////////////////
// Horizontal scrollbar handler
void ViewCtrl::OnHScroll( WPARAM wParam, LPARAM lParam ) 
{
	if ( m_nPageCount && m_pPageArray )
	{ // must have some report data
		RepPage *pRepPage = m_pPageArray[m_nCurPage].pRepPage;
		// ignore thumb tracking

		int nSBCode = (int)LOWORD( wParam );
		if ( nSBCode != SB_THUMBTRACK )
		{ // not tracking
			//int nPos = (int)HIWORD( wParam );
			pageScroll( nSBCode, FALSE );
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Vertical scroll handler
void ViewCtrl::OnVScroll( WPARAM wParam, LPARAM lParam ) 
{
	if ( m_nPageCount && m_pPageArray )
	{ // must have some report data
		RepPage *pRepPage = m_pPageArray[m_nCurPage].pRepPage;
		//int nSBCode = (int)LOWORD( wParam );
		//int nPos = (int)HIWORD( wParam );
		// call general purpose scroll handler
		pageScroll((int)LOWORD(wParam),TRUE );
	}
}

////////////////////////////////////////////////////////////////////////
// Special keyboard message handler - Microsoft framework function
BOOL ViewCtrl::OnSpecialKey( LPMSG pMsg )
{
	if ( m_nPageCount && m_pPageArray )
	{ // anything there?
		if ( pMsg->message == WM_KEYDOWN )
		{ // accelerator key
			BOOL bVert = TRUE;
			UINT nPosCode = 0;
			RepPage *pRepPage = m_pPageArray[m_nCurPage].pRepPage;
			if ( pRepPage )
			{
				switch ( pMsg->wParam )
				{
					case VK_PRIOR:
						toAdjacentPage( FALSE );
						return TRUE;
					case VK_NEXT:
						toAdjacentPage( TRUE );
						return TRUE;
					case VK_RIGHT:
						bVert = FALSE;	// fall thru
					case VK_DOWN:
						nPosCode = 	( GetKeyState( VK_CONTROL ) >= 0 ) ? SB_LINEDOWN : SB_PAGEDOWN;
						break;
					case VK_LEFT:
						bVert = FALSE;	// fall thru
					case VK_UP:
						nPosCode = 	( GetKeyState( VK_CONTROL ) >= 0 ) ? SB_LINEUP : SB_PAGEUP;
						break;
					case VK_HOME:
						nPosCode = SB_TOP;
						break;
					case VK_END:
						nPosCode = SB_BOTTOM;
						break;
					case VK_ESCAPE:	// cancel any printing
						m_bPrintCancelled = TRUE;
						return TRUE;
					default:
						return FALSE;
				}
				// no horizontal scroll if portrait
				if ( m_nPageCount && ( bVert || m_bLandscape ))
					pageScroll( nPosCode,bVert );
				return TRUE;
			}
		}
	}
	return FALSE;
}

////////////////////////////////////////////////////////////////////////
// Print report. Uses Windows common print dialog.
void ViewCtrl::OnPrintReport( void )
{
	if ( m_nPageCount && m_bGotPrinter && m_bReportLoaded &&
		!m_hReadThread && m_pPageArray && !DesignMode())
	{ // we got a printer and we got the report
		if ( m_bPrinting || m_hPrintThread )
			m_bPrintCancelled = TRUE;
		else
		{
			RECT rcClient;
			::GetClientRect( m_hwnd, &rcClient );
			m_hWndProgress = ::CreateWindowEx(
				0,							// no extended styles
				PROGRESS_CLASS,				// class name
				(LPTSTR) NULL,				// title (caption)
				WS_CHILD | WS_VISIBLE,		// style
				rcClient.right - PROGRESS_RIGHT, PROGRESS_TOP,	// position
				PROGRESS_WIDTH, PROGRESS_HEIGHT,// size
				m_hwnd,						// parent
				(HMENU)IDC_PROGRESS,		// control ID
				g_hInstance,				// instance handle
				NULL );						// no WM_CREATE parameter
			if ( m_hWndProgress )
			{ // set range/increment of progress bar
				::SendMessage( m_hWndProgress, PBM_SETSTEP, 1, 0 ); 
			}
			printReport();
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Show printing status - message sent from print thread
//
//  wParam: Total pages to print
//
void ViewCtrl::OnPagePrinted( WPARAM wParam, LPARAM )
{
	if ( m_hWndProgress )
	{ // show our progress
		::SendMessage( m_hWndProgress, PBM_SETRANGE, 0, MAKELPARAM( 0, wParam )); 
		::SendMessage( m_hWndProgress, PBM_STEPIT, 0, 0 );
	}
}

////////////////////////////////////////////////////////////////////////
// Printing completed
void ViewCtrl::OnPrintDone( WPARAM, LPARAM )
{
	if ( m_hWndProgress )
	{ // printing done, remove progress control
		DestroyWindow( m_hWndProgress );
		m_hWndProgress = NULL;
	}
}

////////////////////////////////////////////////////////////////////////
// Handle error from worker thread - (UI) message required
void ViewCtrl::OnDisplayError( WPARAM wParam, LPARAM )
{
	errorMessage( wParam );
}

////////////////////////////////////////////////////////////////////////
// Handle control sizing
void ViewCtrl::OnSize( WPARAM, LPARAM ) 
{
	int nPageWidth = m_sizePage.cx ? m_sizePage.cx : PAGE_WIDTH_DEFAULT;
	int nPageHeight = m_sizePage.cy ? m_sizePage.cy : PAGE_HEIGHT_DEFAULT;

	// get client rectangle
	::GetClientRect( m_hwnd, &m_rectDataWnd );
	m_rectDataWnd.top += m_nToolbarHeight;
	// Size "page window" depending on page size (from PDI file)
	m_sizeScrPage.cx = rectWidth( &m_rectDataWnd );
	if ( m_bLandscape )
	{ // size screen page for landscape orientation
		m_sizeScrPage.cy = m_sizeScrPage.cx;
		m_sizeScrPage.cx = MulDiv( m_sizeScrPage.cx, nPageWidth, nPageHeight );
	}
	else
	{ // portrait
		m_sizeScrPage.cy = MulDiv( m_sizeScrPage.cx, nPageHeight, nPageWidth );
	}
	// set scroll increments based on page size
	m_nVertLineScroll = max( 1, m_sizeScrPage.cy / 50 );
	m_nHorzLineScroll = max( 1, m_sizeScrPage.cx / 50 );
	m_nVertPageScroll = max( 1, m_sizeScrPage.cy / 4 );
	m_nHorzPageScroll = max( 1, m_sizeScrPage.cx / 4 );
	setVertScrollRange( m_nPageCount );
	if ( m_bLandscape )
	{
		setHorzScrollRange();
		m_nScrollPosX = 0;
		setScrollPos( FALSE, 0 );
	}
	m_nScrollPosY = 0;
	setScrollPos( TRUE, m_nCurPage * m_sizeScrPage.cy );
}


static TCHAR szLoadStr[WINSTRLEN + 1];

//////////////////////////////////////////////////////////
// Load string from resource
//
//  nStrID: String ID - NOTE: The language delta is added here
//
LPTSTR ViewCtrl::loadString( int nStrID )
{
	::LoadString( g_hInstance, nStrID + m_nLangDelta, szLoadStr, WINSTRLEN );
	return ( szLoadStr );
}

//////////////////////////////////////////////////////////
// Display error message from string ID
//
//  nStrID: String ID
//
void ViewCtrl::errorMessage( int nStrID )
{
	TCHAR szCaption[256];

	lstrcpy( szCaption, loadString( IDS_CTRL_CAPTION ));
	::MessageBox( NULL, loadString( nStrID ), szCaption, MB_ICONSTOP | MB_TASKMODAL );
}


