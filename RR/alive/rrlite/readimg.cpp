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
// Read file image info and set up image in memory
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/readimg.cpv  $
// 
//    Rev 1.3   30 Apr 1997 16:34:20   amh
// Merged with Steve C's latest source on 4-30-97
// 
//    Rev 1.2   01 Apr 1997 15:52:14   smh
// latest sources on 4/1/97
// 
//    Rev 1.1   07 Jan 1997 14:12:20   smh
// Find images in ImagePath
// 
//    Rev 1.0   19 Dec 1996 16:18:44   smh
// Initial revision.
// 

#include <windows.h>
#include <wininet.h>
#include <tchar.h>
#include "fileread.h"
#include "rrvwctrl.h"
#include "reppage.h"
#include "rrutil.h"
#include "accusoft.h"

///////////////////////////////////////////////////////////////
// Read image file into memory and return Accusoft handle
int loadImageFile( LPTSTR pFileName, HANDLE hMutex )
{
	FileRead fileRd;

	LPTSTR pImageMem = NULL;
	if ( !g_bStopThreads && fileRd.frOpen( pFileName ))
	{ // file found and opened
		DWORD dwOffset = 0;
		DWORD dwSize = IMAGE_READ_SIZE;	// start with this - grab more later
		pImageMem = (LPTSTR)HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, dwSize );
		while ( !g_bStopThreads && pImageMem &&
			fileRd.frReadBlock( pImageMem + dwOffset, IMAGE_READ_SIZE ))
		{ // read and grab memory as needed
			dwSize += IMAGE_READ_SIZE;
			LPTSTR pMore = (LPTSTR)HeapReAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY,
				(LPVOID)pImageMem, dwSize );
			if ( g_bStopThreads || ( pMore == NULL ))
			{ // we've shut down  or run out of memory
				fileRd.frClose();
				if ( pImageMem != NULL )
					HeapFree( GetProcessHeap(), 0, pImageMem );
				return -1;
			}
			pImageMem = pMore;
			dwOffset += IMAGE_READ_SIZE;
		}
		// hand over to Accusoft
		int nDib = !g_bStopThreads ? loadImageToMem( hMutex, pImageMem ) : -1;
		HeapFree( GetProcessHeap(), 0, pImageMem );
		fileRd.frClose();
		return nDib;	// return image handle
	}
	return -1;
}

///////////////////////////////////////////////////////////////////////
// Read thru image structures and load each image into memory
BOOL readImages( FileRead *pFileRead, RepPage *pRepPage, ViewCtrl *pViewCtrl )
{
	for ( UINT ii = 0; ii < pRepPage->m_nImageCount; ii++ )
	{ // read and set up each image
		char cFileLen;
		EXPORT_IMAGE expImage;
		TCHAR szFileName[256];
		if ( g_bStopThreads )
			ExitThread( FALSE );
		ZeroMemory( szFileName, sizeof( szFileName ));
		if ( !pFileRead->frReadBlock( (LPTSTR)&expImage, sizeof( EXPORT_IMAGE )) ||
				!pFileRead->frReadBlock( (LPTSTR)&cFileLen, sizeof( char )) ||
				!pFileRead->frReadBlock( (LPTSTR)szFileName, cFileLen ) || g_bStopThreads )
			return FALSE;
		if ( !pViewCtrl->m_bImageDLLError && ( pViewCtrl->m_pImagePath != NULL ))
		{ // look for images in report file location (or directory below)
			TCHAR szImage[MAX_IMAGE__PATH];
			lstrcpy( szImage, pViewCtrl->m_pImagePath );
			lstrcat( szImage, szFileName );
			// get file from server and store in memory
			int nDib = loadImageFile( szImage, pViewCtrl->m_hMutex );
			pRepPage->m_pImages[ii].nDib = nDib;
			if ( nDib >= 0 )
			{ // image loaded, store parameters
				pRepPage->m_pImages[ii].wLeft = expImage.wLeft;
				pRepPage->m_pImages[ii].wBottom = expImage.wBottom;
				pRepPage->m_pImages[ii].wWidth = expImage.wWidth;
				pRepPage->m_pImages[ii].wHeight = expImage.wHeight;
				pRepPage->m_pImages[ii].wCropWidth = expImage.wCropWidth;
				pRepPage->m_pImages[ii].wCropHeight = expImage.wCropHeight;
				pRepPage->m_pImages[ii].bCropped = FALSE;
			}
		}
		else	// no image loaded
			pRepPage->m_pImages[ii].nDib = -1;
	}
	return TRUE;
}
