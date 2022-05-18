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
// Report Viewer Control Accusoft routines
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/accusoft.cpv  $
// 
//    Rev 1.3   23 Jun 1997 09:38:30   amh
// Removed the reference to Accusoft's library and changed it to SnowBound's
// library
// 
//    Rev 1.2   19 Dec 1996 16:27:28   smh
// Added auto-comment header.
// 

#include <windows.h>
#include <tchar.h>
#include "accusoft.h"

#define SZ_IMGLOADMEM _T( "IMG_decompress_bitmap_mem" )
typedef int ( FAR PASCAL *LPFNIMGLOADMEM )( LPSTR, int );

/* AMH 6/23/97 We no longer use the Accusoft graphics library */
/* We now use the SnowBound dll */

//char szAccusoft[] = _T( "Accuisr5.dll" );
char szSnowBound[] = _T( "Snbd6w9s.dll" );

///////////////////////////////////////////////////////////////
// Function pointers
LPFNIMGLOADMEM		lpfnImgLoadMem = NULL;
LPFNIMGDELETE		lpfnImgDelete = NULL;
LPFNIMGSETCROP		lpfnImgSetCrop = NULL;
LPFNIMGDIBTODDB		lpfnImgDibToDdb = NULL;
LPFNIMGDISPLAYDDB	lpfnImgDisplayDdb = NULL;
LPFNIMGPRINTFAST	lpfnImgPrintFast = NULL;

///////////////////////////////////////////////////////////////
// Load Accusoft DLL
HINSTANCE loadImageLib( void )
{
	HINSTANCE hInstance;

  	//if (( hInstance = LoadLibrary( szAccusoft )) == (HINSTANCE)NULL )
	if (( hInstance = LoadLibrary( szSnowBound )) == (HINSTANCE)NULL )
		return NULL;	// no can load
	// load function pointers for functions we use
 	lpfnImgLoadMem = (LPFNIMGLOADMEM)GetProcAddress( hInstance, SZ_IMGLOADMEM );
	lpfnImgSetCrop = (LPFNIMGSETCROP)GetProcAddress( hInstance, SZ_IMGSETCROP );
 	lpfnImgDelete = (LPFNIMGDELETE)GetProcAddress( hInstance, SZ_IMGDELETE );
 	lpfnImgDibToDdb = (LPFNIMGDIBTODDB)GetProcAddress( hInstance, SZ_IMGDIBTODDB );
	lpfnImgDisplayDdb = (LPFNIMGDISPLAYDDB)GetProcAddress( hInstance, SZ_IMGDISPLAYDDB );
 	lpfnImgPrintFast = (LPFNIMGPRINTFAST)GetProcAddress( hInstance, SZ_IMGPRINTFAST );
	if ( !lpfnImgLoadMem ||  !lpfnImgSetCrop ||  !lpfnImgDelete || !lpfnImgDibToDdb ||
		!lpfnImgDisplayDdb || !lpfnImgPrintFast )
	{ // missing functions!
		::FreeLibrary( hInstance );
		return NULL;
	}
	return hInstance;
}

///////////////////////////////////////////////////////////////
// Set cropping rectangle
void setCropRect( HANDLE hMutex, int nDib, int nWidth, int nHeight )
{
	if (( nDib >= 0 ) && nWidth && nHeight && ( lpfnImgSetCrop != NULL ))
	{ // must wait for shared access to Accusoft functions
		WaitForSingleObject( hMutex, 1000L );	// wait our turn
		( *lpfnImgSetCrop )( nDib, 0, 0, nWidth, nHeight );
		ReleaseMutex( hMutex );
	}
}

///////////////////////////////////////////////////////////////
// Load image into memory and return dib
int loadImageToMem( HANDLE hMutex, LPSTR pImageMem )
{
	int nDib = -1;

	if ( lpfnImgLoadMem != NULL )
	{ // must wait for shared access to Accusoft functions
		WaitForSingleObject( hMutex, 1000L );	// wait our turn
		nDib = ( *lpfnImgLoadMem )( pImageMem, 0 );
		ReleaseMutex( hMutex );
	}
	return nDib;
}

///////////////////////////////////////////////////////////////
// Convert from device independent to device dependent bitmap
HBITMAP DIBtoDDB( HANDLE hMutex, int nDib, int nWidth, int nHeight )
{
	HBITMAP hBitmap = NULL;

	if ( lpfnImgDibToDdb != NULL )
	{ // must wait for shared access to Accusoft functions
		WaitForSingleObject( hMutex, 1000L );	// wait our turn
		hBitmap = ( *lpfnImgDibToDdb )( nDib, nWidth, nHeight );
		ReleaseMutex( hMutex );
	}
	return hBitmap;
}

///////////////////////////////////////////////////////////////
// Display device dependent bitmap
void displayDdb( HANDLE hMutex, HBITMAP DDB, HDC hDC, int nLeft, int nTop )
{
	if ( lpfnImgDisplayDdb )
	{ // must wait for shared access to Accusoft functions
		WaitForSingleObject( hMutex, 1000L );	// wait our turn
		( *lpfnImgDisplayDdb )( DDB, hDC, nLeft, nTop );
		ReleaseMutex( hMutex );
	}
}

///////////////////////////////////////////////////////////////
// Print, and do it quick
void printFast( HANDLE hMutex, int nDib, HDC hDC, int nLeft, int nTop, int nWidth, int nHeight )
{
	if ( lpfnImgPrintFast )
	{ // must wait for shared access to Accusoft functions
		WaitForSingleObject( hMutex, 1000L );	// wait our turn
		( *lpfnImgPrintFast )( nDib, hDC, nLeft, nTop, nWidth, nHeight );
		ReleaseMutex( hMutex );
	}
}

///////////////////////////////////////////////////////////////
// Delete image from memory
void deleteImage( HANDLE hMutex, int nDib )
{
	if ( lpfnImgDelete )
	{ // must wait for shared access to Accusoft functions
		WaitForSingleObject( hMutex, 1000L );	// wait our turn
		( *lpfnImgDelete )( nDib );
		ReleaseMutex( hMutex );
	}
}
