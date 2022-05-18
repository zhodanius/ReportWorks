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
// Read file object info and set up object in memory
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/readobj.cpv  $
// 
//    Rev 1.2   30 Apr 1997 16:35:12   amh
// Merged with Steve C's latest source on 4-30-97
// 
//    Rev 1.1   01 Apr 1997 15:52:12   smh
// latest sources on 4/1/97
// 
//    Rev 1.0   20 Mar 1997 12:11:36   smh
// Initial revision.
// 

#include <windows.h>
#include <wininet.h>
#include <tchar.h>
#include "fileread.h"
#include "rrvwctrl.h"
#include "reppage.h"

///////////////////////////////////////////////////////////////////////
// Read & store OLE object structure - object actually loaded when displayed
BOOL readObjects( FileRead *pFileRead, RepPage *pRepPage )
{
	UINT nRead = 0;

	for ( UINT ii = 0; ii < pRepPage->m_nObjectCount; ii++ )
	{ // read and set up each object
		EXPORT_OBJECT expObject;
		if ( g_bStopThreads )
			ExitThread( FALSE ); // we have to shut down
		ZeroMemory( &pRepPage->m_pObjects[ii], sizeof( OBJECT ));
		// assume the worst
		pRepPage->m_pObjects[ii].wStatus = OBJECT_STATUS_ERROR;
		DWORD dwBytes;
		if ( !pFileRead->frReadBlock( (LPTSTR)&expObject, sizeof( EXPORT_OBJECT )) ||
				!pFileRead->frReadBlock( (LPTSTR)&dwBytes, sizeof( DWORD )) || !dwBytes )
			break;	// can't read the data

		// allocate enough memory to read entire block
		pRepPage->m_pObjects[ii].hStorage = ::GlobalAlloc( GMEM_SHARE | GMEM_MOVEABLE, dwBytes );
		if ( pRepPage->m_pObjects[ii].hStorage == NULL )
			break;	// can't get the memory

		LPVOID lpBuf = ::GlobalLock( pRepPage->m_pObjects[ii].hStorage );
		if ( !lpBuf || !pFileRead->frReadBlock( lpBuf, dwBytes ))
		{ // can't lock memory or can't read object data
			::GlobalFree( pRepPage->m_pObjects[ii].hStorage );
			break;
		}
		::GlobalUnlock( pRepPage->m_pObjects[ii].hStorage );
		// copy over first part of object structure
		CopyMemory( &pRepPage->m_pObjects[ii], &expObject, sizeof( EXPORT_OBJECT ));
		// we've got R&R structure - we'll load the object later when needed
		pRepPage->m_pObjects[ii].wStatus = OBJECT_STATUS_UNLOADED;
		nRead++;	// count objects read & stored
	}
	return nRead > 0;
}
