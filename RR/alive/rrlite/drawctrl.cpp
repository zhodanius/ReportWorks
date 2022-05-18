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
// Report Viewer Control - Code to draw into client area of control
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/drawctrl.cpv  $
// 
//    Rev 1.7.1.1   01 Dec 1998 07:53:16   wrr
// No change.
// 
//    Rev 1.7.1.0   30 Dec 1997 08:31:46   smh
// Aram's change for 133962 - window can become wider than toolbar.
// 
//    Rev 1.7   09 May 1997 11:32:08   amh
// More merging with Steve C's latest code
// 
//    Rev 1.6   30 Apr 1997 16:25:58   amh
// Merged with Steve C's latest source on 4-30-97
// 

#include <windows.h>
#include "rrvwctrl.h"
#include "reppage.h"
#include "rrutil.h"
#include "resource.h"
#include "rrlangid.h"

////////////////////////////////////////////////////////////////////////
// Draw control here
HRESULT ViewCtrl::OnDraw( DWORD, HDC hdcDraw, LPCRECTL prcBounds, LPCRECTL prcWBounds, HDC, BOOL )
{
	RECT rectPage;

	int nSaveDC = SaveDC( hdcDraw );	// be nice and save state
	::CopyRect( &rectPage, (LPRECT)prcBounds );
	// clear the control window
	::SelectObject( hdcDraw, (HBRUSH)GetStockObject( WHITE_BRUSH ));
	::SelectObject( hdcDraw, (HPEN)GetStockObject( BLACK_PEN ));
	::Rectangle( hdcDraw, rectPage.left, rectPage.top, rectPage.right, rectPage.bottom );
	// render page, if any
	if ( m_nPageCount && ( m_nCurPage >= 0 ) && !DesignMode())
	{ // we've got a page and we're in user mode
		HDC hDC = GetDC( m_hWndToolbar );
		::SelectObject( hDC, GetStockObject( DEFAULT_GUI_FONT ));
		::SetTextAlign( hDC, TA_TOP | TA_LEFT | TA_NOUPDATECP );
		TCHAR szPage[WINSTRLEN + 1];

		::SetBkMode( hDC, OPAQUE );
		::SetBkColor( hDC, ::GetSysColor( COLOR_3DFACE ));

		//AMH 9/26/97 added code
		//AMH 9/26/97 clean the slate
		memset(szPage,' ',WINSTRLEN + 1);
		::TextOut( hDC, 80, 6, szPage, WINSTRLEN + 1);
		//AMH 9/26/97 end of new code
		
		wsprintf( szPage, loadString( IDS_PAGE_N_OF_N ), m_nCurPage + 1, m_nPageCount );
		
		::TextOut( hDC, 80, 6, szPage, lstrlen( szPage ));
		::ReleaseDC( m_hWndToolbar, hDC );
		// locate page object & request printing
		RepPage *pRepPage = m_pPageArray ? m_pPageArray[m_nCurPage].pRepPage : NULL;
		if ( pRepPage && pRepPage->m_bPageReady )
		{
			// offset by toolbar height
			rectPage.top += m_nToolbarHeight - 1;
			::InflateRect( &rectPage, -1, -1 );
			// need to clip inside
			HRGN hRgn = CreateRectRgn( rectPage.left, rectPage.top,	rectPage.right, rectPage.bottom );
			if ( hRgn != NULL )
				SelectClipRgn( hdcDraw, hRgn );
			pRepPage->printPage( hdcDraw, &rectPage, TRUE );
			if ( hRgn != NULL )
			{ // clean up
				SelectClipRgn( hdcDraw, NULL );
				DeleteObject( hRgn );
			}
		}
	}
	if ( nSaveDC )
		::RestoreDC( hdcDraw, nSaveDC );	// be good and restore DC
	return S_OK;
}

///////////////////////////////////////////////////////////////////
// Handle horizontal & vertical page scrolling
void ViewCtrl::pageScroll( UINT nSBCode, BOOL bVert )
{
	BOOL bPositionTop = TRUE;
	BOOL bDown = TRUE;
	BOOL bSmallPage = bVert && ( m_sizeScrPage.cy <= rectHeight( &m_rectDataWnd ));
	int nLineScroll = bVert ? m_nVertLineScroll : m_nHorzLineScroll;
	int nPageScroll = bVert ? m_nVertPageScroll : m_nHorzPageScroll;
	SCROLLINFO scrollInfo;
	scrollInfo.cbSize = sizeof( SCROLLINFO );
	scrollInfo.fMask = SIF_ALL;
	GetScrollInfo( m_hwnd, bVert ? SB_VERT : SB_HORZ, &scrollInfo );
	int nReportPos = scrollInfo.nPos;
	int nMax = scrollInfo.nMax - max( scrollInfo.nPage - 1, 0 );

	switch ( nSBCode )
	{
		case SB_TOP:
			nReportPos = 0;
			bDown = FALSE;
			break;
		case SB_BOTTOM:
			nReportPos = nMax;
			bPositionTop = bDown = FALSE;
			break;
		case SB_LINEUP:
			if ( bSmallPage )
			{ // page smaller than control window page area
				toAdjacentPage( FALSE );
				return; // done
			}
			nReportPos = ( nReportPos - nLineScroll >= 0) ? nReportPos - nLineScroll : 0;
			bPositionTop = bDown = FALSE;
			break;
		case SB_LINEDOWN:
			if ( bSmallPage )
			{ // page smaller than control window page area
				toAdjacentPage( TRUE );
				return;	// that's it
			}
			nReportPos = ( nReportPos + nLineScroll > nMax ) ? nMax : nReportPos + nLineScroll;
			break;
		case SB_PAGEUP:
			if ( bSmallPage )
			{ // page smaller than control window page area
				toAdjacentPage( FALSE );
				return;	// we're done
			}
			nReportPos = ( nReportPos - nPageScroll >= 0 ) ? nReportPos - nPageScroll : 0;
			bPositionTop = bDown = FALSE;
			break;
		case SB_PAGEDOWN:
			if ( bSmallPage )
			{ // page smaller than control window page area
				toAdjacentPage( TRUE );
				return;	// finished
			}
			nReportPos = ( nReportPos + nPageScroll > nMax ) ? nMax : nReportPos + nPageScroll;
			break;
		case SB_THUMBPOSITION:
			nReportPos = min( scrollInfo.nTrackPos, nMax );
			bDown = FALSE;
			clearPageTip();	// remove last tooltip (if any)
			m_nTrackPage = -1;
			break;
		case SB_THUMBTRACK:
			if ( bVert )
			{ // show page number tooltip while tracking
				nReportPos = min( scrollInfo.nTrackPos, nMax );
				// compute current page
				int nPage = nReportPos ? ( nReportPos / m_sizeScrPage.cy ) : 0;
				if ( nPage != m_nTrackPage )
				{ // show tooltip
					showPageTip( nPage + 1 );
					m_nTrackPage = nPage;
				}
			}
			return;	// done - just tracking vertical here
		default:
			return;	// don't want anything else
	}
	BOOL bShow = FALSE;
	BOOL bPageChange = FALSE;
	if ( bVert )
	{ // vertical is special - it paginates through report
		int nPageHeight = m_sizeScrPage.cy;
		int nPage = nReportPos ? ( nReportPos / nPageHeight ) : 0;
		if ( m_nScrollPosY && ( nSBCode == SB_PAGEUP ) && ( nPage < m_nCurPage ))
		{ // just position to top of current page
			nReportPos = m_nCurPage * nPageHeight;
			m_nScrollPosY = 0;
			bShow = TRUE;
		}
		else
		{ // compute new location
			int nPageScrollHeight = nPageHeight - rectHeight( &m_rectDataWnd ) + nLineScroll;
			int nPosY = nReportPos ? ( nReportPos % nPageHeight ) : 0;
			if ( bDown && ( (int)m_nScrollPosY >= ( nPageScrollHeight - nLineScroll )) &&
				( nPage == m_nCurPage ) && ( nPage < m_nPageCount - 1 ))
			{ // bump to next page if end of current page is in view
				nPage++;
			}
			if ( nPage != m_nCurPage )
			{ // page change
				m_nScrollPosY = bPositionTop ? 0 : nPageScrollHeight;
				m_nCurPage = min( nPage, m_nPageCount - 1 );
				bShow = bPageChange = TRUE;
			}
			else
			{ // same page
				bShow = ( m_nScrollPosY != (UINT)nPosY );
				m_nScrollPosY = min( nPageScrollHeight, nPosY );
			}
			// recompute here to catch changes
			nReportPos = ( m_nCurPage * nPageHeight ) + m_nScrollPosY;
		}
	}
	else
	{ // horizontal
		bShow = (UINT)nReportPos != m_nScrollPosX;
		m_nScrollPosX = nReportPos;
	}
	setScrollPos( bVert, nReportPos );
	if ( bShow )
		InvalidateControl( bPageChange ? NULL : &m_rectDataWnd );
}

///////////////////////////////////////////////////////////////////
// Set the horizontal scroll range
void ViewCtrl::setHorzScrollRange( void )
{
	SCROLLINFO scrollInfo;
	ZeroMemory( &scrollInfo, sizeof( SCROLLINFO ));
	scrollInfo.cbSize = sizeof( SCROLLINFO );
	scrollInfo.fMask = SIF_PAGE | SIF_RANGE;
	// set range
	scrollInfo.nMin = 0;
	scrollInfo.nMax = m_sizeScrPage.cx;
	// set page size for proportional thumb
	scrollInfo.nPage = rectWidth( &m_rectDataWnd );
	SetScrollInfo( m_hwnd, SB_HORZ, &scrollInfo, TRUE );
}

///////////////////////////////////////////////////////////////////
// Set the vertical scroll range
void ViewCtrl::setVertScrollRange( int nPages )
{
	SCROLLINFO scrollInfo;
	ZeroMemory( &scrollInfo, sizeof( SCROLLINFO ));
	scrollInfo.cbSize = sizeof( SCROLLINFO );
	scrollInfo.fMask = SIF_PAGE | SIF_RANGE;
	// set range
	scrollInfo.nMin = 0;
	scrollInfo.nMax = ( nPages * m_sizeScrPage.cy ) + m_nVertLineScroll;
	// set page size for proportional thumb
	scrollInfo.nPage = min( m_sizeScrPage.cy, rectHeight( &m_rectDataWnd ));
	SetScrollInfo( m_hwnd, SB_VERT, &scrollInfo, TRUE );
}

///////////////////////////////////////////////////////////////////
// Set the scroll position
void ViewCtrl::setScrollPos( BOOL bVert, int nPos )
{
	if ( bVert || m_bLandscape )
	{ // horizontal okay if landscape
		SCROLLINFO scrollInfo;
		ZeroMemory( &scrollInfo, sizeof( SCROLLINFO ));
		scrollInfo.cbSize = sizeof( SCROLLINFO );
		scrollInfo.fMask = SIF_POS;
		scrollInfo.nPos = nPos;
		SetScrollInfo( m_hwnd, bVert ? SB_VERT : SB_HORZ, &scrollInfo, TRUE );
	}
}

///////////////////////////////////////////////////////////////////
// Handle PgUp & PgDn keys
void ViewCtrl::toAdjacentPage( BOOL bNext )
{
	UINT nOldScrollPos = m_nScrollPosY;
	int nOldPage = m_nCurPage;

	if ( bNext )
	{ // page down
		if ( m_nCurPage < m_nPageCount - 1 )
		{ // on to next page
			m_nCurPage++;
			m_nScrollPosY = 0;
		}
	}
	else
	{ // page up
		if ( m_nCurPage )
			m_nCurPage--;
		m_nScrollPosY = 0;
	}
	// don't redraw unless we moved
	if (( m_nCurPage != nOldPage ) || ( m_nScrollPosY != nOldScrollPos ))
	{
		setScrollPos( TRUE, m_nCurPage * m_sizeScrPage.cy );
		InvalidateControl( NULL );
	}
}
