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
// Base object view class
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/viewrep.cpv  $
// 
//    Rev 1.3   01 Apr 1997 15:52:02   smh
// latest sources on 4/1/97
// 
//    Rev 1.2   22 Mar 1997 19:32:12   smh
// Sources from 1/24/97
// 
//    Rev 1.1   19 Dec 1996 16:26:56   smh
// Added auto-comment header.
// 

#include <windows.h>
#include "rrvwctrl.h"
#include "viewrep.h"
#include "rrutil.h"

///////////////////////////////////////////////////////////////
// Constructor
ViewRep::ViewRep( ViewCtrl *pViewCtrl, HDC hDC, BOOL bPreview, LPRECT pRect, UINT nCount )
{
	// set up common properties
	m_pViewCtrl = pViewCtrl;
	m_hDC = hDC;
	m_bPreview = bPreview;
	m_pRectWnd = pRect;
	m_nCount = nCount;
}

///////////////////////////////////////////////////////////////
// Destructor
ViewRep::~ViewRep()
{
}

///////////////////////////////////////////////////////////////
// Scale from page width (HZRES) to screen pixels
int ViewRep::scalePrevX( int x )
{
	return MulDiv( x, m_pViewCtrl->m_sizeScrPage.cx, m_pViewCtrl->m_sizePage.cx );
}

///////////////////////////////////////////////////////////////
// Scale from page height (VTRES) to screen pixels
int ViewRep::scalePrevY( int y )
{
	return MulDiv( y, m_pViewCtrl->m_sizeScrPage.cy, m_pViewCtrl->m_sizePage.cy );
}

///////////////////////////////////////////////////////////////
// Horizontal screen resolution -> horizontal printer resolution
int ViewRep::scalePrtX( int x )
{
	return MulDiv( m_pViewCtrl->m_nPrtInchX, x, HZRES );
}

///////////////////////////////////////////////////////////////
// Vertical screen resolution -> vertical printer resolution
int ViewRep::scalePrtY( int y )
{
	return MulDiv( m_pViewCtrl->m_nPrtInchY, y, VTRES );
}

///////////////////////////////////////////////////////////////
// Scale to display or printer
int ViewRep::scalePosition( int nPos, BOOL bVertical )
{
	if ( bVertical )
		return m_bPreview ? scalePrevY( nPos ) : scalePrtY( nPos );
	else
		return m_bPreview ? scalePrevX( nPos ) : scalePrtX( nPos );
}

///////////////////////////////////////////////////////////////
// Output shaded end of page - assumes valid device context
void ViewRep::showEndOfPage( void )
{
	RECT rectFill;

	CopyRect( &rectFill, m_pRectWnd );
	rectFill.top = m_pViewCtrl->m_sizeScrPage.cy - m_pViewCtrl->m_nScrollPosY + rectFill.top;
	if ( rectFill.top < rectFill.bottom )
	{
		SelectObject( m_hDC, (HPEN)GetStockObject( BLACK_PEN ));
		SelectObject( m_hDC, (HBRUSH)GetStockObject( GRAY_BRUSH ));
		Rectangle( m_hDC, rectFill.left, rectFill.top, rectFill.right, rectFill.bottom );
	}
}
