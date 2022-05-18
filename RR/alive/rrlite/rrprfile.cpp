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
// File Read Thread - reads data and sets up page objects

//      Note that this thread executes completely independent of MFC.
//      Communication to the main control class is done exclusively
//      via messages.
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/alive/rrlite/RRPRFILE.CPV  $
// 
//    Rev 1.15   Feb 28 2001 09:25:12   nhubacker
// Debug
// 
//    Rev 1.14   10 Jul 1997 13:04:34   smh
// Return our error code as the thread exit code.
// 
//    Rev 1.13   22 May 1997 16:30:34   par
// Charts are now being displayed in the viewer control.
// 
//    Rev 1.12   19 May 1997 10:59:16   smh
// Now read old (Live 1.0) PDI files as well as current version.
// 
//    Rev 1.11   30 Apr 1997 16:38:28   amh
// Merged with Steve C's latest source on 4-30-97
//
//    Rev 1.10   26 Apr 1997 12:41:06   smh
// Merged Live1.0 Loc changes.
// 
//    Rev 1.9   28 Mar 1997 16:08:06   smh
// Error when entire report cannot be read, as in case with invalid 
// PDI file b/c of bad diskette.
// 
//    Rev 1.8   22 Mar 1997 20:03:06   smh
// Sources from 1/24/97
// 
//    Rev 1.7.1.0   25 Apr 1997 13:43:32   smh
// Added header for Live 1.0 localization.
// Also added change that was in Steve's version of the source which
// reports an error when incomplete or invalid PDI is found.  Thought
// safer to ship localized version with this change than to attempt
// a merge against english baseline.
// 
//    Rev 1.7   02 Jan 1997 15:33:52   smh
// Use Win32 system date/time format functions.
// 
//    Rev 1.6   31 Dec 1996 11:35:54   smh
// Call byte dump routine if file header bad (DEBUG only)
// 
//    Rev 1.5   31 Dec 1996 11:01:20   smh
// Skip over data size packets.  Read and store report name.
// Format date/time string for header info.
// 
//    Rev 1.4   19 Dec 1996 16:22:02   smh
// Moved image code to readimg.cpp and added auto-comment header.
// 

#include <windows.h>
#include <wininet.h>
#include <tchar.h>
#include "fileread.h"
#include "rrvwctrl.h"
#include "reppage.h"
#include "rrutil.h"
#include "accusoft.h"
#include "rrlangid.h"
#include "resource.h"

///////////////////////////////////////////////////////////////////////
// Build & store date/time string
void buildDateStr( ViewCtrl *pViewCtrl, FILE_HDR *pHdr )
{
	SYSTEMTIME sysTime;
	sysTime.wYear = pHdr->wYear;
	sysTime.wMonth = pHdr->cMonth;
	sysTime.wDay = pHdr->cDay;
	sysTime.wHour = pHdr->cHour;
	sysTime.wMinute = pHdr->cMinute;
	// seconds must be zero or time function fails, even w/ TIME_NOSECONDS specified
	sysTime.wSecond = 0;
	// compute buffer sizes first
	int nDateSize = GetDateFormat( LOCALE_USER_DEFAULT, DATE_SHORTDATE, &sysTime, NULL, NULL, 0 );
	int nTimeSize = GetTimeFormat( LOCALE_USER_DEFAULT, TIME_NOSECONDS, &sysTime, NULL, NULL, 0 );
	if ( nDateSize && nTimeSize )
	{ // get storage and combine strings
		pViewCtrl->m_pRepDate = new TCHAR[nDateSize + nTimeSize + 3];
		if ( pViewCtrl->m_pRepDate )
		{ // okay, format to: "date<2 spaces>time"
			GetDateFormat( LOCALE_USER_DEFAULT, DATE_SHORTDATE, &sysTime, NULL,
				pViewCtrl->m_pRepDate, nDateSize + 1 );
			lstrcat( pViewCtrl->m_pRepDate, "  " );
			GetTimeFormat( LOCALE_USER_DEFAULT, TIME_NOSECONDS, &sysTime, NULL,
				pViewCtrl->m_pRepDate + lstrlen( pViewCtrl->m_pRepDate ), nTimeSize + 1 );
		}
	}
}

///////////////////////////////////////////////////////////////////////
// Read PDI page data via page index, creating a page object for each page
UINT createPageObjects( FileRead *pFileRead, ViewCtrl *pViewCtrl )
{
	int nPages = 0;
	// allocate page object array
	pViewCtrl->m_pPageArray = (PAGE_ARRAY *)HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, pViewCtrl->m_nPageCount * sizeof( PAGE_ARRAY ));
	// position to beginning of page index
	if ( !g_bStopThreads && pViewCtrl->m_pPageArray && pFileRead->frSeek( FALSE, - ( pViewCtrl->m_nPageCount * (int)sizeof( PAGE_POS ))))
	{ // got page array and file is positioned
		for ( int ii = 0; ii < pViewCtrl->m_nPageCount; ii++ )
		{ // first read sequentially thru the index packets
			PAGE_POS pagePos;
			if ( g_bStopThreads )
				ExitThread( FALSE );	// emergency shutdown
			
			if ( pFileRead->frReadBlock( (LPSTR)&pagePos, sizeof( PAGE_POS )))
			{
				RepPage *pRepPage = new RepPage( pViewCtrl );
				if ( pRepPage )
				{
					pRepPage->m_dwFilePos = pagePos.dwPagePos;
					pViewCtrl->m_pPageArray[ii].pRepPage = pRepPage;
					
					if ( pagePos.wBoxCount )
					{
						LINE_BOX *pData = (LINE_BOX *)HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, pagePos.wBoxCount * sizeof( LINE_BOX ));
						if ( pData )
						{
							pRepPage->m_pBoxes    = pData;
							pRepPage->m_nBoxCount =	pagePos.wBoxCount;
						}
					}
					
					if ( pagePos.wLineCount )
					{
						LINE_BOX *pData = (LINE_BOX *)HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, pagePos.wLineCount * sizeof( LINE_BOX ));
						if ( pData )
						{
							pRepPage->m_pLines     = pData;
							pRepPage->m_nLineCount = pagePos.wLineCount;
						}
					}
					
					if ( pagePos.wImageCount )
					{
						IMAGE *pData = (IMAGE *)HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, pagePos.wImageCount * sizeof( IMAGE ));
						if ( pData )
						{
							pRepPage->m_pImages     = pData;
							pRepPage->m_nImageCount = pagePos.wImageCount;
						}
					}
					
					if ( pagePos.wObjectCount )
					{
						OBJECT *pData = (OBJECT *)HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, pagePos.wObjectCount * sizeof( OBJECT ));
						if ( pData )
						{
							pRepPage->m_pObjects     = pData;
							pRepPage->m_nObjectCount = pagePos.wObjectCount;
						}
					}
					
					if ( pagePos.wChartCount )
					{
						CHART *pData = (CHART *)HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, pagePos.wChartCount * sizeof( CHART ));
						if ( pData )
						{
							pRepPage->m_pCharts     = pData;
							pRepPage->m_nChartCount = pagePos.wChartCount;
						}
					}
					
					if ( pagePos.dwTextByteCount )
					{
						LPTSTR pData = (LPTSTR)HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, pagePos.dwTextByteCount );
						if ( pData )
						{
							pRepPage->m_pText           = pData;
							pRepPage->m_dwTextByteCount = pagePos.dwTextByteCount;
						}
					}
				}
			}
			else
				return nPages;
		}
		// now read data into page object buffers
		for ( ii = 0; ii < pViewCtrl->m_nPageCount; ii++ )
		{
			if ( g_bStopThreads )
				ExitThread( FALSE );	// emergency shutdown
			RepPage *pRepPage = pViewCtrl->m_pPageArray[ii].pRepPage;
			if ( !g_bStopThreads && pRepPage && pFileRead->frSeek( TRUE, pRepPage->m_dwFilePos + SIZE_OBJECT_PACKET ))
			{
				// now @ start of page data
				char sizePacket[ SIZE_OBJECT_PACKET ];
				if ( !g_bStopThreads && ( pRepPage->m_pBoxes != NULL ))
				{
					if ( !pFileRead->frReadBlock( (LPSTR)pRepPage->m_pBoxes, pRepPage->m_nBoxCount * sizeof( LINE_BOX )))
						return nPages;
				}
				if ( !pFileRead->frReadBlock( sizePacket, sizeof( sizePacket )))
					return nPages;
				
				if ( !g_bStopThreads && ( pRepPage->m_pLines != NULL ))
				{
					if ( !pFileRead->frReadBlock( (LPSTR)pRepPage->m_pLines, pRepPage->m_nLineCount * sizeof( LINE_BOX )))
						return nPages;
				}
				if ( !pFileRead->frReadBlock( sizePacket, sizeof( sizePacket )))
					return nPages;
				
				if ( !g_bStopThreads && ( pRepPage->m_pImages != NULL ))
				{
					if ( !pViewCtrl->m_bImageDLLError && ( pViewCtrl->m_hImageLib == NULL ))
					{ // check if Accusoft DLL loaded
						pViewCtrl->m_hImageLib = loadImageLib();
						if ( pViewCtrl->m_hImageLib == NULL )
							pViewCtrl->m_bImageDLLError = TRUE;	// flag error
					}
					if ( !readImages( pFileRead, pRepPage, pViewCtrl ))
						return nPages;
				}
				if ( !pFileRead->frReadBlock( sizePacket, sizeof( sizePacket )))
					return nPages;

				if (( !g_bStopThreads ) && ( pRepPage->m_pObjects != NULL ))
				{
					pViewCtrl->m_bGotObjects = readObjects( pFileRead, pRepPage );
					if ( !pViewCtrl->m_bGotObjects )
					{ // no objects read into memory, clean up now
						pRepPage->m_nObjectCount = 0;
						HeapFree( GetProcessHeap(), 0, pRepPage->m_pObjects );
						return nPages;
					}
				}
				if ( !pFileRead->frReadBlock( sizePacket, sizeof( sizePacket )))
					return nPages;
				
				if (( !g_bStopThreads ) && ( pRepPage->m_pCharts != NULL ))
				{
					pViewCtrl->m_bGotCharts = readCharts( pFileRead, pRepPage );
					if ( !pViewCtrl->m_bGotCharts )
					{ // no Charts read into memory, clean up now
						pRepPage->m_nChartCount = 0;
						HeapFree( GetProcessHeap(), 0, pRepPage->m_pCharts );
						return nPages;
					}
				}
				if ( !pFileRead->frReadBlock( sizePacket, sizeof( sizePacket )))
					return nPages;
				
				if ( !g_bStopThreads && (pRepPage->m_pText != NULL ))
				{
					if ( !pFileRead->frReadBlock( pRepPage->m_pText, pRepPage->m_dwTextByteCount ))
						return nPages;
				}
				
				// done reading page data
				pRepPage->m_bPageReady = TRUE;	// flag page as ready
				if ( !g_bStopThreads )
				{
					SendMessage( pViewCtrl->getCtrlHwnd(), WM_USER_PAGEDONE, ii, 0 ); // notify main thread - we've got another page
				}
				nPages++;
			}
			else
				return nPages;
		}
	}
	// return pages processed
	return nPages;
}

///////////////////////////////////////////////////////////////////////
// Read data file and create page objects.  This routine is run in a
// separate thread which reads the data and thereby allows the UI to
// be operative after the first page has been read and stored.
//
UINT readDataFile( LPVOID pParam )
{
	int nErrStrID = 0;	// potential error string ID
	ViewCtrl *pViewCtrl = (ViewCtrl *)pParam;
	FileRead fileRd;	// instantiate file reader class

	BOOL bOpenFile = fileRd.frOpen( pViewCtrl->m_pReportURL );
//::MessageBox( NULL, pViewCtrl->m_pReportURL, "URL", MB_ICONSTOP | MB_TASKMODAL );
	while ( !g_bStopThreads && bOpenFile )
	{ // page object created
		FILE_HDR fileHd;
		BOOL bResult = fileRd.frReadBlock( (LPSTR)&fileHd, sizeof( FILE_HDR ));
		if ( !bResult )
		{
//			::MessageBox( NULL, "frReadBlock Error", "BooBoo", MB_ICONSTOP | MB_TASKMODAL );
			nErrStrID = IDS_ERR_READ_SYSTEM;	// system read error
		}
		else if ( fileHd.cID != PDI_FILE_ID )
			nErrStrID = IDS_ERR_READ_TYPE;		// invalid file type
		else if ( fileHd.cVer > PDI_VERSION )
			nErrStrID = IDS_ERR_READ_VERSION;	// invalid version #
		else if ( !fileHd.dwPages )
			nErrStrID = IDS_ERR_READ_EMPTY;		// no pages count in header
#ifdef _DEBUG 	// dump out the file header into a message box
		if ( bResult && nErrStrID )
			dumpBytes( pViewCtrl->getCtrlHwnd(), (LPSTR)&fileHd, sizeof( fileHd ));
#endif
		char cNameCnt;	// report name count byte
		bResult = bResult && fileRd.frReadBlock( &cNameCnt, 1 );
		if ( bResult && cNameCnt )
		{ // read report name
			pViewCtrl->m_pRepName = new TCHAR[cNameCnt + 1];
			if ( pViewCtrl->m_pRepName &&
				( bResult = fileRd.frReadBlock( pViewCtrl->m_pRepName, cNameCnt )))
				pViewCtrl->m_pRepName[cNameCnt] = '\0';
		}
		if ( !bResult || g_bStopThreads || nErrStrID )
		{ // bad header info - invalid file
			fileRd.frClose();
			break;	// post bad news and exit thread
		}
		pViewCtrl->m_nPageCount = fileHd.dwPages;
		pViewCtrl->m_sizePage.cx = fileHd.wPaperWidth;
		pViewCtrl->m_sizePage.cy = fileHd.wPaperHeight;
		// now sanity check the values & set to default if empty
		if ( !pViewCtrl->m_sizePage.cx )
			pViewCtrl->m_sizePage.cx = PAGE_WIDTH_DEFAULT;
		if ( !pViewCtrl->m_sizePage.cy )
			pViewCtrl->m_sizePage.cy = PAGE_HEIGHT_DEFAULT;
		// set landscape mode based on page dimensions
		pViewCtrl->m_bLandscape = pViewCtrl->m_sizePage.cx > pViewCtrl->m_sizePage.cy;
		// build date string and store away
		buildDateStr( pViewCtrl, &fileHd );
		if ( !g_bStopThreads )
		{ // create pages
			int nPages = fileHd.cVer == 2 ? createVer2PageObjects( &fileRd, pViewCtrl ) :
				createPageObjects( &fileRd, pViewCtrl );
			if (!( pViewCtrl->m_bReportLoaded = ( nPages == pViewCtrl->m_nPageCount )))
				nErrStrID = IDS_ERR_READ_ALL;	// report the shortage
		}
		fileRd.frClose();
		break;	// finished - exit thread //
	}
	if ( !bOpenFile )
	{
//		::MessageBox( NULL, "bOpenFile", "BooBoo", MB_ICONSTOP | MB_TASKMODAL );
		nErrStrID = IDS_ERR_READ_SYSTEM;	// use system read error message
	}
	if ( !g_bStopThreads )
	{ // send status to main thread before leaving
		// 07/10/97 PAR.  The window might not have been created yet. 
		// If not created, then expect the OnReportDone() to be called 
		// inside AfterCreateWindow(). 
		if ( pViewCtrl->getCtrlHwnd() )
			PostMessage( pViewCtrl->getCtrlHwnd(), WM_USER_READDONE, pViewCtrl->m_bReportLoaded, nErrStrID );
	}
	// shut down
	// 07/10/97 PAR.  Return our error code with the high bit 
	// set to prevent a collision with STILL_ACTIVE value. 
	DWORD dwReadFileExitCode = nErrStrID | 0x80000000 ;
	ExitThread( dwReadFileExitCode  );
	return TRUE;
}
