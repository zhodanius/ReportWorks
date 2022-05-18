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
// Read file chart info
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/readchrt.cpv  $
// 
//    Rev 1.0   22 May 1997 16:31:46   par
// Charts are now being displayed in the viewer control.
// 

#include <windows.h>
#include <wininet.h>
#include <tchar.h>
#include "fileread.h"
#include "rrvwctrl.h"
#include "reppage.h"

///////////////////////////////////////////////////////////////////////
// Read & store chart structure - object actually loaded when displayed
BOOL readCharts( FileRead *pFileRead, RepPage *pRepPage )
{
	UINT nRead = 0;

	for ( UINT ii = 0; ii < pRepPage->m_nChartCount; ii++ )
	{ // read and set up each object
		EXPORT_CHART expChart;
		if ( g_bStopThreads )
			ExitThread( FALSE ); // we have to shut down
		ZeroMemory( &pRepPage->m_pCharts[ii], sizeof( CHART ));
		// assume the worst
		DWORD dwBytes;
		if ( !pFileRead->frReadBlock( (LPTSTR)&expChart, sizeof( EXPORT_CHART )) || !pFileRead->frReadBlock( (LPTSTR)&dwBytes, sizeof( DWORD )) || !dwBytes )
			break;	// can't read the data

		// allocate enough memory to read entire block
		HGLOBAL hMetafileBits = ::GlobalAlloc( GMEM_SHARE | GMEM_MOVEABLE, dwBytes );
		if ( hMetafileBits == NULL )
			break;	// can't get the memory

		LPBYTE lpBuf = (LPBYTE) ::GlobalLock( hMetafileBits );
		if ( !lpBuf || !pFileRead->frReadBlock( lpBuf, dwBytes ))
		{ // can't lock memory or can't read object data
			::GlobalFree( hMetafileBits );
			break;
		}
		pRepPage->m_pCharts[ii].hmf = SetEnhMetaFileBits ( dwBytes, lpBuf ) ;
		::GlobalUnlock( hMetafileBits );
		
		// copy over first part of object structure
		CopyMemory( &pRepPage->m_pCharts[ii], &expChart, sizeof( EXPORT_CHART ));
		// we've got R&R structure - we'll load the object later when needed
		nRead++;	// count objects read & stored
	}
	return nRead > 0;
}
