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
// Handles rendering of Charts
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/alive/rrlite/VIEWCHRT.CPV  $
// 
//    Rev 1.3   Feb 07 2000 15:04:40   nhubacker
// Syntax errors for C++ 6.0
// 
//    Rev 1.2   11 Jul 1997 16:29:18   smh
// Adjust chart width too when adjust left side for scrolling.
// 
//    Rev 1.1   10 Jul 1997 12:30:22   smh
// Chart wasn't scrolling horizontally b/c not adjusting left edge
// by scroll pos.
// 
//    Rev 1.0   22 May 1997 16:31:38   par
// Charts are now being displayed in the viewer control.
// 
// Initial revision.
// 

#include <windows.h>
#include "rrvwctrl.h"
#include "reppage.h"
#include "viewobj.h"

///////////////////////////////////////////////////////////////
// Constructor
ViewChart::ViewChart( ViewCtrl *pViewCtrl, HDC hDC, BOOL bPreview, LPRECT pRect, UINT nCount, CHART *pChart ) :
	ViewRep( pViewCtrl, hDC, bPreview, pRect, nCount )
{
	m_pChart = pChart;	// pointer to object array
}

///////////////////////////////////////////////////////////////
// Destructor
ViewChart::~ViewChart()
{
}

///////////////////////////////////////////////////////////////
// Ask object to render itself
void ViewChart::renderChart( CHART *pChart )
{
	int imgX, imgRight, imgY, imgWid, imgHite;
	RECT rectChart ;

	if ( m_bPreview )
	{ // preview, scale and show
		imgX    = scalePrevX ( pChart->x ) - m_pViewCtrl->m_nScrollPosX + m_pRectWnd->left;
		imgRight = imgX + scalePrevX( pChart->wWidth );
		imgWid  = imgRight - imgX;
		imgY    = scalePrevY ( pChart->y - pChart->wHeight ) + m_pRectWnd->top - m_pViewCtrl->m_nScrollPosY;
		imgHite = scalePrevY ( pChart->y ) + m_pRectWnd->top - m_pViewCtrl->m_nScrollPosY - imgY;
		
		::SetRect  ( &rectChart, imgX, imgY, imgX + imgWid, imgY + imgHite );
		if (( rectChart.left <= m_pRectWnd->right ) && ( rectChart.right  >= m_pRectWnd->left ) && ( rectChart.top  <= m_pRectWnd->bottom ) && ( rectChart.bottom >= m_pRectWnd->top ))
		{ // gotta show it
			PlayEnhMetaFile ( m_hDC, (HENHMETAFILE)pChart->hmf, &rectChart ) ;
		}
	}
	else
	{ // printing
		imgX = pChart->x;
		imgY = pChart->y;
		// adjust for unprintable region
		if ( imgX > m_pViewCtrl->m_sizeUnprint.cx )
			imgX -= m_pViewCtrl->m_sizeUnprint.cx;
		if ( imgY > m_pViewCtrl->m_sizeUnprint.cy )
			imgY -= m_pViewCtrl->m_sizeUnprint.cy;
		// now scale to printer units
		imgX    = scalePrtX ( imgX );
		imgWid  = scalePrtX ( pChart->wWidth  );
		imgHite = scalePrtY ( pChart->wHeight );
		imgY    = scalePrtY ( imgY ) - imgHite;
		::SetRect  ( &rectChart, imgX, imgY, imgX + imgWid, imgY + imgHite );
		PlayEnhMetaFile ( m_hDC, (HENHMETAFILE)pChart->hmf, &rectChart ) ;
	}
}

///////////////////////////////////////////////////////////////
// Render objects on page
void ViewChart::showPage( void )
{
	CHART *pChart = m_pChart;

	for ( UINT ii = 0; ii < m_nCount; ii++, pChart++ )
	{ // render objects, loading them if necessary
		if ( pChart->hmf )
			renderChart( pChart );	// display CHART
	}
}
