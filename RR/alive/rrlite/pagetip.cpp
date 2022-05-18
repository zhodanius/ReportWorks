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
// Show page number tooltip while tracking
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/pagetip.cpv  $
// 
//    Rev 1.9   30 Apr 1997 16:32:30   amh
// Merged with Steve C's latest source on 4-30-97
// 
//    Rev 1.8   26 Apr 1997 12:10:40   smh
// Merged Live1.0 Loc changes.
// 
//    Rev 1.7   01 Apr 1997 15:52:16   smh
// latest sources on 4/1/97
// 
//    Rev 1.6   22 Mar 1997 20:39:56   smh
// Removed garbage char.
// 
//    Rev 1.5   22 Mar 1997 18:45:26   smh
// Removed displayReportInfo.
// 
//    Rev 1.4.1.0   25 Apr 1997 13:26:44   smh
// Added rrlangid header for Live 1.0 localization.
// 
//    Rev 1.4   02 Jan 1997 15:32:36   smh
// Chage file date/time strings to pointers.
// 
//    Rev 1.3   31 Dec 1996 10:59:58   smh
// Add function to display report name & date/time created in tooltip
// 
//    Rev 1.2   19 Dec 1996 16:15:16   smh
// Added auto-comment header.
// 

#include <windows.h>
#include "rrvwctrl.h"
#include "rrutil.h"
#include "resource.h"
#include "rrlangid.h"

////////////////////////////////////////////////////////////////////////
// Show the page number tooltip
void ViewCtrl::showPageTip( int nPage )
{
	HDC hDC = ::GetDC( m_hwnd );
	TCHAR szPage[WINSTRLEN + 1];

	wsprintf( szPage, loadString( IDS_PAGENUMBER ), nPage );
	// clear any existing tip
	clearPageTip();
	RECT rectClient;
	::GetClientRect( m_hwnd, &rectClient );
	// set tip location
	int nXPos = rectClient.right - 80;
	int nYPos = m_nToolbarHeight + MulDiv( rectHeight( &rectClient ) - m_nToolbarHeight,
		nPage - 1, m_nPageCount );

	// set the font and rectangle border
	::SelectObject( hDC, (HFONT)::GetStockObject( ANSI_VAR_FONT ));
	::SelectObject( hDC, (HPEN)::GetStockObject( BLACK_PEN ));
	// size the string and then rectangle
	SIZE sizeText;
	int nStrLen = lstrlen( szPage );
	::GetTextExtentPoint32( hDC, szPage, nStrLen, &sizeText );
	RECT rect;	// tip rectangle
	rect.left = nXPos;
	rect.top = nYPos;
	rect.right = rect.left + sizeText.cx + 12;
	rect.bottom = rect.top + sizeText.cy + 6;

	// make sure we stay within our client area
	if ( rect.bottom > rectClient.bottom )
		::OffsetRect( &rect, 0, -( rect.bottom - rectClient.bottom + 3 ));
	::CopyRect( &m_rectPageTip, &rect );
	::Rectangle( hDC, rect.left, rect.top, rect.right, rect.bottom );
	::InflateRect( &rect, -1, -1 );
	int nColors = ::GetDeviceCaps( hDC, NUMCOLORS );
	// check colors available for yellows
	::SetBkColor( hDC, ( nColors < 0 ) || ( nColors > 20 ) ? RGB( 255, 255, 192 ) : RGB( 255, 255, 0 ));
	::SetTextAlign( hDC, TA_TOP | TA_CENTER | TA_NOUPDATECP );
	::ExtTextOut( hDC, ( rect.left + ( rect.right - rect.left ) / 2 ),
		rect.top + 2, ETO_CLIPPED | ETO_OPAQUE, &rect, szPage, nStrLen, NULL );
	// clean up
	::ReleaseDC( m_hwnd, hDC );
}

////////////////////////////////////////////////////////////////////////
// Clear the page number tooltip
void ViewCtrl::clearPageTip( void )
{
	if ( !::IsRectEmpty( &m_rectPageTip ) )
	{
		InvalidateControl( &m_rectPageTip );
		::UpdateWindow( m_hwnd );
		::SetRectEmpty( &m_rectPageTip );
	}
}
