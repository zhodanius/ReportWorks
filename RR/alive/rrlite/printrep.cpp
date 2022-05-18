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
// Print handler
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/alive/rrlite/PRINTREP.CPV  $
// 
//    Rev 1.10   Feb 07 2000 14:56:22   nhubacker
// Syntax errors for C++ 6.0
// 
//    Rev 1.9   09 May 1997 11:39:30   amh
// More merge changes to sync-up with Steve C's latest code
// 
//    Rev 1.8   02 May 1997 10:08:06   amh
// Removed duplicate definitions from the module
// 
//    Rev 1.7   30 Apr 1997 16:33:22   amh
// Merged with Steve C's source on 4-30-97
// 
//    Rev 1.6   26 Apr 1997 12:41:00   smh
// Merged Live1.0 Loc changes.
// 
//    Rev 1.5   01 Apr 1997 15:52:14   smh
// latest sources on 4/1/97
// 
//    Rev 1.4   22 Mar 1997 20:12:26   smh
// Sources from 1/24/97
// 
//    Rev 1.3.1.0   25 Apr 1997 13:30:24   smh
// Added header for live 1.0 localization
// Also added code to use page size info from PDI rather than canning
// letter size.  Was in Steve's version of the source and thought safer
// to use this version than to try to merge localization change with 
// shipping version.  Therefore difference between english 1.0 version.
// 
//    Rev 1.3   19 Dec 1996 16:15:32   smh
// Added auto-comment header.
//

#include <windows.h>
#include <winspool.h>
#include <tchar.h>
#include "rrvwctrl.h"
#include "reppage.h"
#include "rrutil.h"
#include "viewobj.h"
#include "resource.h"
#include "rrlangid.h"

////////////////////////////////////////////////////////////////////////
// Convert decipoints to millimeters/10
// DWORD ptsToMM( DWORD dwPts )
//{
//	return (((( dwPts * 10L ) / 72 ) * 10000L )) / 3937;
//}
//AMH 5-2-97 already defined in rutil.cpp

////////////////////////////////////////////////////////////////////////
// Set printer resolution and unprintable values
void ViewCtrl::getPrinterMetrics( HDC hDC )
{
	// values in printer resolution
	m_nPrtInchX = ::GetDeviceCaps( hDC, LOGPIXELSX );
	m_nPrtInchY = ::GetDeviceCaps( hDC, LOGPIXELSY );
	// values in logical units
	m_sizeUnprint.cx = MulDiv( ::GetDeviceCaps( hDC, PHYSICALOFFSETX ),
		HZRES, m_nPrtInchX );
	m_sizeUnprint.cy = MulDiv( ::GetDeviceCaps( hDC, PHYSICALOFFSETY ),
		VTRES, m_nPrtInchY );
}

////////////////////////////////////////////////////////////////////////
// Get default printer name and information context
BOOL ViewCtrl::getPrinterInfo( void )
{
	PRINTDLG pd;

	ZeroMemory( &pd, sizeof( PRINTDLG ));
	pd.lStructSize = sizeof( PRINTDLG );
	pd.Flags = PD_RETURNDEFAULT | PD_RETURNIC;
	if ( PrintDlg( &pd ))
	{ // we should have default printer info now
		if ( pd.hDevNames && pd.hDevMode )
		{ // store the printer properties
			LPDEVNAMES pDevNames = (LPDEVNAMES)GlobalLock( pd.hDevNames );
			if ( !m_bGotPrinter && ( pDevNames != NULL ))
			{ // get printer name
				lstrcpy( m_szPrtName, (LPTSTR)pDevNames + pDevNames->wDeviceOffset );
				if ( pd.hDC )
				{ // get printer metrics
					getPrinterMetrics( pd.hDC );
					DeleteDC( pd.hDC );	// delete IC
				}
			}
			GlobalUnlock( pd.hDevNames );
			if ( pd.hDevMode != NULL )
//				GlobalFree( pd.hDevMode ) == NULL;
 				GlobalFree( pd.hDevMode ) ;
			if ( pd.hDevNames != NULL )
//				GlobalFree( pd.hDevNames ) == NULL;
				GlobalFree( pd.hDevNames ) ;
			return ( pDevNames != NULL );	// got a default printer?
		}
	}
	return FALSE;
}

////////////////////////////////////////////////////////////////////////
// (Background) print the range of pages requested
UINT printReportThread( LPVOID pParam )
{
	ViewCtrl *pViewCtrl = (ViewCtrl *)pParam;

	// copies > 1 means driver can't handle it
	int nReportCopies = !( pViewCtrl->m_pd.Flags & PD_PRINTTOFILE ) &&
		( pViewCtrl->m_pd.Flags & PD_COLLATE ) ? pViewCtrl->m_pd.nCopies : 1;
	BOOL bFirstCopy = TRUE;	// no StartDoc first time around - first call made in main thread
	while ( !g_bStopThreads && !pViewCtrl->m_bPrintCancelled && nReportCopies-- )
	{ // output report(s)
		if ( !bFirstCopy && ( StartDoc( pViewCtrl->m_pd.hDC, &pViewCtrl->m_docInfo ) <= 0 ))
		{ // failure...
			DeleteDC( pViewCtrl->m_pd.hDC );
			DWORD dwErr = GetLastError();	// get last error value
			if ( dwErr && ( dwErr != ERROR_PRINT_CANCELLED ))
			{ // it's okay if user hit Cancel, but otherwise...
				PostMessage( pViewCtrl->getCtrlHwnd(), WM_USER_DISPLAYERROR, IDS_ERR_PRT_START, 0 );
			}
			pViewCtrl->m_bPrintCancelled = TRUE;
			break;
		}
		bFirstCopy = FALSE;	// call StartDoc on subsequent copies
		// set start/end page values
		int nStartPage = pViewCtrl->m_pd.nFromPage &&
			( pViewCtrl->m_pd.nFromPage <= pViewCtrl->m_nPageCount ) ?
			pViewCtrl->m_pd.nFromPage : 1;
		int nEndPage = pViewCtrl->m_pd.nToPage &&
			( pViewCtrl->m_pd.nToPage <= pViewCtrl->m_nPageCount ) ?
			pViewCtrl->m_pd.nToPage : pViewCtrl->m_nPageCount;
		for ( int ii = nStartPage; ( ii <= nEndPage ) && !g_bStopThreads &&
			!pViewCtrl->m_bPrintCancelled; ii++ )
		{ // print pages
			int nPageCopies = ( pViewCtrl->m_pd.Flags & PD_PRINTTOFILE ) ||
				( pViewCtrl->m_pd.Flags & PD_COLLATE ) ? 1 : pViewCtrl->m_pd.nCopies;
			RepPage *pRepPage = pViewCtrl->m_pPageArray[ii - 1].pRepPage;
			while ( !g_bStopThreads && !pViewCtrl->m_bPrintCancelled && nPageCopies-- )
			{ // if not collated, print n copies of each page
				if ( !pRepPage || ( ::StartPage( pViewCtrl->m_pd.hDC ) <= 0 ) ||
					!pRepPage->printPage( pViewCtrl->m_pd.hDC, NULL, FALSE ) ||
					( ::EndPage( pViewCtrl->m_pd.hDC ) <= 0 ))
				{ // no can print
#ifdef _DEBUG
					displayDebugError( _T( "Start/EndPage" ));
#endif
					PostMessage( pViewCtrl->getCtrlHwnd(), WM_USER_DISPLAYERROR, IDS_ERR_PRINT, 0 );
					pViewCtrl->m_bPrintCancelled = TRUE;
					break;
				}
				// tell UI we printed a page
				PostMessage( pViewCtrl->getCtrlHwnd(), WM_USER_PAGEPRINTED,
					( nEndPage - nStartPage ) + 1, 0 );
			}
		}
		// end the job
		if ( !g_bStopThreads && !pViewCtrl->m_bPrintCancelled )
		{ // don't end job if cancelled
			EndDoc( pViewCtrl->m_pd.hDC );
		}
	}
	if ( !g_bStopThreads )
	{ // notify UI that we're done
		// clean up PRINTDLG stuff
		DeleteDC( pViewCtrl->m_pd.hDC );
		pViewCtrl->m_bPrinting = FALSE;
		PostMessage( pViewCtrl->getCtrlHwnd(), WM_USER_PRINTDONE, 0, 0 );
	}
	// terminate thread
	pViewCtrl->m_hPrintThread = NULL;	// flag it as terminated
	return 0;
}

////////////////////////////////////////////////////////////////////////
// Get printer info from common dialog, then print away
void ViewCtrl::printReport( void )
{
	HANDLE hPrint = NULL;
	HGLOBAL hDevMode = NULL;
	LONG lPrintInfo;
	LPDEVMODE pDevMode;

	// first get a printer handle
	if ( !OpenPrinter( m_szPrtName, &hPrint, NULL ) ||
		// get the size of the printer info block...
		(( lPrintInfo = DocumentProperties( NULL, hPrint, m_szPrtName, NULL, NULL, 0 )) <= 0 ) ||
		// get the memory for DEVMODE structure
		(( hDevMode = GlobalAlloc( GHND, lPrintInfo )) == NULL ) ||
		(( pDevMode = (LPDEVMODE)GlobalLock( hDevMode )) == NULL) ||
		// now get the info into the buffer allocated...
		( DocumentProperties( NULL, hPrint, m_szPrtName, pDevMode, NULL, DM_OUT_BUFFER) != IDOK ))
	{ // failure...
		if ( hDevMode )
			GlobalFree( hDevMode );
		if ( hPrint )
			ClosePrinter( hPrint );
		errorMessage( IDS_ERR_PRT_START );
		return;
	}
	ClosePrinter( hPrint );

	// set overrides
	pDevMode->dmFields &= ~DM_PAPERSIZE;
	pDevMode->dmFields |= DM_PAPERLENGTH | DM_PAPERWIDTH | DM_ORIENTATION;
	pDevMode->dmPaperLength = m_bLandscape ? (short)ptsToMM( m_sizePage.cx ) :
		(short)ptsToMM( m_sizePage.cy );
	pDevMode->dmPaperWidth = m_bLandscape ? (short)ptsToMM( m_sizePage.cy ) :
		(short)ptsToMM( m_sizePage.cx );
	pDevMode->dmOrientation = m_bLandscape ?
		(short)DMORIENT_LANDSCAPE : (short)DMORIENT_PORTRAIT;

	// initialize the structure
	ZeroMemory( &m_pd, sizeof( PRINTDLG ));
	m_pd.lStructSize = sizeof( PRINTDLG );
	// we've allocated the DEVMODE structure
	m_pd.hDevMode = hDevMode;
	// use ctrl window
	m_pd.hwndOwner = m_hwnd;
	// set flags - note we're requesting the DC here
	m_pd.Flags = PD_RETURNDC | PD_NOSELECTION | PD_COLLATE;
	// don't bother with page range if just one page
	if ( m_nPageCount < 2 )
		m_pd.Flags |= PD_NOPAGENUMS;
	else
	{ // set range, etc.
		m_pd.nFromPage = m_pd.nMinPage = 1;
		m_pd.nToPage = m_pd.nMaxPage = (unsigned short)m_nPageCount;
	}
	m_pd.nCopies = 1;		// start with one copy
	ModalDialog( TRUE );	// spread the word - we're goin' modal
	BOOL bOK = PrintDlg( &m_pd );
	if ( bOK )
	{ // OK pressed, start the job
		// do first StartDoc here in main thread, since it might have some UI
		int nStartDoc = StartDoc( m_pd.hDC, &m_docInfo );
		if ( m_pd.hDevNames )
		{ // check for printer change
			LPDEVNAMES pDevNames = (LPDEVNAMES)GlobalLock( m_pd.hDevNames );
			if ( pDevNames && lstrcmp( m_szPrtName,
				(LPCSTR)( pDevNames + pDevNames->wDeviceOffset )))
			{ // new printer name
				lstrcpy( m_szPrtName, (LPTSTR)pDevNames + pDevNames->wDeviceOffset );
				GlobalUnlock( m_pd.hDevNames );
			}
		}
		// free up any memory allocated by dialog
		if ( m_pd.hDevMode != NULL )
		{
			// unlock first, since we've allocated it
			GlobalUnlock( m_pd.hDevMode );
			GlobalFree( m_pd.hDevMode );
		}
 		if ( m_pd.hDevNames != NULL )
			GlobalFree( m_pd.hDevNames );

		if ( nStartDoc <= 0 )
		{ // failed or user cancelled print file dialog
			DeleteDC( m_pd.hDC );
			DWORD dwErr = GetLastError();	// get last error value
			if ( dwErr && ( dwErr != ERROR_PRINT_CANCELLED ))
			{ // it's okay if user hit Cancel, but otherwise...
				errorMessage( IDS_ERR_PRT_START );
			}
		}
		else
		{ // kick off printing task
			m_bPrintCancelled = FALSE;
			m_nPagesPrinted = 0;
			// just call this and ignore return
			SetAbortProc( m_pd.hDC, (ABORTPROC)abortProc );
			// get metrics & recompute unprintable regions
			getPrinterMetrics( m_pd.hDC );
			if ( m_bGotObjects )
			{ // can't print in background if got OLE objects
				m_bPrinting = TRUE;
				printReportThread( this );
			}
			else
			{ // start background print thread
				DWORD dwThreadID;
				m_hPrintThread = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)printReportThread,
					this, CREATE_SUSPENDED, &dwThreadID );
				if ( m_hPrintThread )
				{ // set priority a bit lower than normal
					SetThreadPriority( m_hPrintThread, THREAD_PRIORITY_BELOW_NORMAL );
					ResumeThread( m_hPrintThread );
					m_bPrinting = m_hPrintThread != NULL;
				}
				else
				{ // okay, we'll print unthreaded then
					m_bPrinting = TRUE;
					printReportThread( this );
				}
			}
		}
	}
	ModalDialog( FALSE );	// done with printing UI
}

////////////////////////////////////////////////////////////////////////
// The AbortProc function is an application-defined callback function
// that is called when a print job is to be canceled during spooling.
BOOL CALLBACK abortProc( HDC, int nError )
{
	return nError == 0;	// zero is good
}
