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
// Utility functions
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/rrutil.cpv  $
// 
//    Rev 1.11   09 May 1997 11:46:34   amh
// More merges to sync-up with Steve C's latest code
// 
//    Rev 1.10   30 Apr 1997 16:46:08   amh
// Merged with Steve C's latest source on 4-30-97
// 
//    Rev 1.9   26 Apr 1997 12:41:24   smh
// Merged Live1.0 Loc changes.
// 
//    Rev 1.8   01 Apr 1997 15:52:10   smh
// latest sources on 4/1/97
// 
//    Rev 1.7   22 Mar 1997 19:54:28   smh
// Sources from 1/24/97
// 
//    Rev 1.6.1.0   25 Apr 1997 14:13:38   smh
// Live 1.0 localization change.
//
//    Rev 1.6   31 Dec 1996 11:38:34   smh
// Add function to dump bytes to message box (debug only)
// 
//    Rev 1.5   19 Dec 1996 16:25:56   smh
// Added auto-comment header.
// 

#include <windows.h>
#include <tchar.h>
#include <wininet.h>
#include "util.h"
#include "globals.h"
#include "rrutil.h"
#include "resource.h"
#include "rrlangid.h"

// static TCHAR szLoadStr[WINSTRLEN + 1];

////////////////////////////////////////////////////////////////////////
// Convert decipoints to millimeters/10
DWORD ptsToMM( DWORD dwPts )
{
	return (((( dwPts * 10L ) / 72 ) * 10000L )) / 3937;
}

//////////////////////////////////////////////////////////
// Load string from resource
//
//  nStrID: String ID
//
//LPSTR loadString( int nStrID )
//{
//	LoadString( g_hInstance, nStrID, szLoadStr, WINSTRLEN );
//	return ( szLoadStr );
//}


//////////////////////////////////////////////////////////
// Display error message from string ID
//
//  nStrID: String ID
//
//void errorMessage( int nStrID )
//{
//	TCHAR szCaption[256];
//
//	lstrcpy( szCaption, loadString( IDS_CTRL_CAPTION ));
//	::MessageBox( NULL, loadString( nStrID ), szCaption, MB_ICONSTOP | MB_TASKMODAL );
//}


//////////////////////////////////////////////////////////
// Return rectangle width
//
//  pRect: pointer to rectangle
//
int rectWidth( LPRECT pRect )
{
	return pRect->right - pRect->left;
}

//////////////////////////////////////////////////////////
//
// Return rectangle width
//
//  pRect: pointer to rectangle
//
int rectHeight( LPRECT pRect )
{
	return pRect->bottom - pRect->top;
}

// coordinates within print button
//#define IMAGE_WIDTH		24
//#define IMAGE_INDENT_X	4
//#define IMAGE_INDENT_Y	2
//#define IMAGE_RIGHT		( IMAGE_WIDTH + IMAGE_INDENT_X )
//#define TEXT_TOP		6
//#define TEXT_LEFT		( IMAGE_WIDTH + IMAGE_INDENT_X + 8 )

//////////////////////////////////////////////////////////
// Display bitmap & text in (button) window
//void displayPrintStatus( HWND hWnd, int nBitmapID, LPTSTR pText )
//{
//	HDC hDC = GetDC( hWnd );
//	BITMAP bitmap;
//	HBITMAP hBitmap = LoadBitmap( g_hInstance, MAKEINTRESOURCE( nBitmapID ));
//	HDC hBitmapDC = CreateCompatibleDC( hDC );
//	int nBytes = GetObject( hBitmap, sizeof( BITMAP ), &bitmap );
//	if ( hBitmap && hBitmapDC && ( nBytes == sizeof( BITMAP )))
//	{ // bitmap loaded from resource file...
//		SelectObject( hBitmapDC, hBitmap );
//		SetMapMode( hDC, MM_TEXT );
//		SetMapMode( hBitmapDC, GetMapMode( hDC ));
//		InvalidateRect( hWnd, NULL, TRUE );
//		UpdateWindow( hWnd );
//		BitBlt( hDC, IMAGE_INDENT_X, IMAGE_INDENT_Y,
//			bitmap.bmWidth, bitmap.bmHeight, hBitmapDC, 0, 0, SRCCOPY );
//		RECT rect;
//		GetClientRect( hWnd, &rect );
//		SetBkMode( hDC, TRANSPARENT );
//		SetTextColor( hDC, RGB( 0, 0, 128 ));
//		SelectObject( hDC, GetStockObject( DEFAULT_GUI_FONT ));
//		SetTextAlign( hDC, TA_CENTER | TA_TOP | TA_NOUPDATECP );
// 		// center page number to right of image
//		ExtTextOut( hDC, IMAGE_RIGHT + (( rect.right - IMAGE_RIGHT ) / 2 ),
//			TEXT_TOP, ETO_CLIPPED, &rect, pText, lstrlen( pText ), NULL );
//	}
//	ReleaseDC( hWnd, hDC );
//}

//////////////////////////////////////////////////////////
// Substitute for costly runtime routines
int strCompareN( LPTSTR pStr1, LPTSTR pStr2, int nLen )
{
	LPTSTR pTemp = new TCHAR[nLen + 1];
	lstrcpyn( pTemp, pStr1, nLen + 1 );
	int nResult = lstrcmpi( pTemp, pStr2 );
	delete [] pTemp;
	return nResult;
}

//////////////////////////////////////////////////////////
// Substitute for costly runtime routines
BOOL strCompareWideN( LPWSTR pwStr1, LPWSTR pwStr2, int nLen )
{
	// convert
	MAKE_ANSIPTR_FROMWIDE( pStr1, pwStr1 );
	MAKE_ANSIPTR_FROMWIDE( pStr2, pwStr2 );
	// call ANSI version
	return strCompareN( pStr1, pStr2, nLen );
}

#ifdef _DEBUG
//////////////////////////////////////////////////////////
// Get & display system error code
void displayDebugError( LPTSTR pFunction )
{
	char szTemp[200];
	wsprintf( szTemp, _T( "%s failed. Error: %ld" ), pFunction, ::GetLastError());
	::MessageBox( ::GetActiveWindow(), szTemp, _T( "RRPrView"), MB_ICONINFORMATION | MB_TASKMODAL );
}

#define BYTES_PER_LINE	8

//////////////////////////////////////////////////////////
// Dump bytes to message box
void dumpBytes( HWND hWnd, LPSTR pBytes, int nCount )
{
	if ( nCount > 0 )
	{
		TCHAR szFmt[10];
		TCHAR szHex[50] = "";
		TCHAR szChar[20] = "";
		TCHAR szLine[100];
		TCHAR *pBuf = new TCHAR[nCount * 6];
		ZeroMemory( pBuf, nCount * 6 );
		int nOutput = 0;
		while ( nCount-- )
		{
			wsprintf( szFmt, "%02x ", (unsigned char)pBytes[nOutput] );
			lstrcat( szHex, szFmt );
			wsprintf( szFmt, "%c", pBytes[nOutput] ? pBytes[nOutput] : ' ' );
			lstrcat( szChar, szFmt );
			nOutput++;
			if (( nOutput % BYTES_PER_LINE ) == 0 )
			{
				wsprintf( szLine, "%s  %s\r\n", szHex, szChar );
				lstrcat( pBuf, szLine );
				szHex[0] = szChar[0] = '\0';
			}
		}
		if ( nOutput % BYTES_PER_LINE )
		{
			wsprintf( szLine, "%s  %s\n", szHex, szChar );
			lstrcat( pBuf, szLine );
		}
		::MessageBox( hWnd, pBuf, "File Dump", MB_OK );
		delete [] pBuf;
	}
}
#endif

//////////////////////////////////////////////////////////
// Hex conversion helper
BOOL GetHexDigit( TCHAR cChar, int *pVal )
{
	if (( cChar >= '0' ) && ( cChar <= '9' ))
	{ // number
		*pVal = cChar - '0';
		return TRUE;
	}
	TCHAR cHex = (( cChar >= 'a' ) && ( cChar <= 'f' )) ? cChar - 32  : cChar;
	if (( cHex >= 'A' ) && ( cHex <= 'F' ))
	{ // hex letter
		*pVal = ( cHex - 'A' ) + 10;
		return TRUE;
	}
	return FALSE;
}

//////////////////////////////////////////////////////////
// Convert string to hex number (to avoid linking runtime library)
int convertLangStr( LPTSTR pHex )
{
	for ( int nHex = 0; *pHex; pHex++ )
	{
		int nDig;
		if ( !GetHexDigit( *pHex, &nDig ))
			return LANG_ENG;	// just return English
		nHex = ( nHex * 16 ) + nDig;
	}
	return nHex;
}

