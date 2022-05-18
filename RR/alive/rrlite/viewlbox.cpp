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
// Base class for lines/boxes - contains common rendering code
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/viewlbox.cpv  $
// 
//    Rev 1.4   01 Apr 1997 15:52:06   smh
// latest sources on 4/1/97
// 
//    Rev 1.3   22 Mar 1997 19:37:22   smh
// Sources from 1/24/97
// 
//    Rev 1.2   19 Dec 1996 16:26:34   smh
// Added auto-comment header.
// 

#include <windows.h>
#include "rrvwctrl.h"
#include "reppage.h"
#include "rrutil.h"

///////////////////////////////////////////////////////////////
// Constructor
ViewLBox::ViewLBox( ViewCtrl *pViewCtrl, HDC hDC, BOOL bPreview, LPRECT pRect,
	UINT nCount, LINE_BOX *pData ) : ViewRep( pViewCtrl, hDC, bPreview, pRect, nCount )
{
	m_pData = pData;		// pointer to line/box array
}

///////////////////////////////////////////////////////////////
// Destructor
ViewLBox::~ViewLBox()
{
}

///////////////////////////////////////////////////////////////
// Draw a solid line with square ends using global line brush - from PWINT.CPP
void ViewLBox::rectLinePD( HDC hDC, int nLeft, int nTop, int nWidth, int nHeight )
{
	if ( m_hLineBrush )
	{ // got a brush to use
		RECT rect;
		rect.left = nLeft;
		rect.top = nTop;
		rect.right = nLeft + nWidth;
		rect.bottom = nTop + nHeight;
		FillRect( hDC, &rect, m_hLineBrush );
	}
}

///////////////////////////////////////////////////////////////
// Main line/box rendering code - copied from PWINT.CPP
void ViewLBox::drawBoxPD( HDC hDC, LINE_BOX *pData, int nXPos, int nYPos, int nXSize, int nYSize, int nFillMode )
{
	HBRUSH hOldBrush;

	m_hLineBrush = CreateSolidBrush( pData->rgbBord );
	if ( m_hLineBrush )
		hOldBrush = (HBRUSH)::SelectObject( hDC, m_hLineBrush );
	// set foreground mix mode
	int nOldROP = ::SetROP2( hDC, R2_COPYPEN );
	// set background mix mode
	int nOldBackMode = ::SetBkMode( hDC, TRANSPARENT );
	if ( pData->wSides & bxLine )
	{
		if ( nXSize > nYSize )
		{ // horizontal
			nYPos -= m_nThick - 1;
			rectLinePD( hDC, nXPos, nYPos, nXSize, m_nThick );
		}
		else
		{ // vertical
			if ( pData->wAlign == txRIGHT )
				nXPos -= ( m_nThick - 1 );
			else if ( pData->wAlign == txCENTER )
				nXPos -= ( m_nThick / 2 );
			rectLinePD( hDC, nXPos, nYPos, m_nThick, nYSize );
		}
	}
	else
	{ // Draw box sides and adjust fill area
		if ( nFillMode & FM_OUTLINE )
		{ // doing outlines now
			if ( pData->wSides & bxTop )
			{
				rectLinePD( hDC, nXPos, nYPos, nXSize, m_nThick );
				nYPos += m_nThick;
				nYSize -= m_nThick;
			}
			if ( pData->wSides & bxLeft )
			{
				rectLinePD( hDC, nXPos, nYPos, m_nThick, nYSize );
				nXPos += m_nThick;
				nXSize -= m_nThick;
			}
			if ( pData->wSides & bxRight )
			{
				rectLinePD( hDC, nXPos + nXSize - m_nThick, nYPos, m_nThick, nYSize );
				nXSize -= m_nThick;
			}
			if ( pData->wSides & bxBottom )
			{
				rectLinePD( hDC, nXPos, nYPos + nYSize - m_nThick, nXSize, m_nThick );
				nYSize -= m_nThick;
			}
		}
	}
	if ( m_hLineBrush )
	{ // remove brush
		SelectObject( hDC, hOldBrush );
		DeleteObject( m_hLineBrush );
	}
	if ( !( pData->wSides & bxLine ))
	{
		if ( nFillMode & FM_INTERIOR )
		{ // Now draw the fill, if any
			if ( pData->wHatch != 0xff )
			{
				m_hLineBrush = CreateHatchBrush( pData->wHatch, pData->rgbFore );
				if ( m_hLineBrush )
				{ // handle new transaparent value.
					COLORREF rgbOldBkColor = SetBkColor( hDC,
						pData->rgbBack == 0xff000000 ? m_rgbHatchBack : pData->rgbBack );
					hOldBrush = (HBRUSH)SelectObject( hDC, m_hLineBrush );
					rectLinePD( hDC, nXPos, nYPos, nXSize, nYSize );
					::SelectObject( hDC, hOldBrush );
					::DeleteObject( m_hLineBrush );
					SetBkColor( hDC, rgbOldBkColor );
				}
			}
			else if ( pData->rgbBack != 0xff000000 )	// transparent?
			{ // solid background
				m_hLineBrush = CreateSolidBrush( pData->rgbBack );
				if ( m_hLineBrush )
				{
					hOldBrush = (HBRUSH)SelectObject( hDC, m_hLineBrush );
					rectLinePD( hDC, nXPos, nYPos, nXSize, nYSize );
					SelectObject( hDC, hOldBrush );
					DeleteObject( m_hLineBrush );
				}
			}
		}
	}
	// restore DC
	SetROP2( hDC, nOldROP );
	SetBkMode( hDC, nOldBackMode );
}

///////////////////////////////////////////////////////////////
// Output lines/boxes to display or printer - from PWINT.CPP
void ViewLBox::renderLineBox( LINE_BOX *pData, int nFillMode )
{
	int nLeft = pData->wLeft;
	int nRight = pData->wRight;
	int nTop = pData->wTop;
	int nBottom = pData->wBottom;

	// white hatch background at the printer
	m_rgbHatchBack = 0x00ffffff;
	if ( m_bPreview )	// preview, scale and show
	{
		m_rgbHatchBack = pData->rgbBack != 0xff000000 ? pData->rgbBack : 0x00ffffff;
		nLeft = scalePrevX( nLeft ) - m_pViewCtrl->m_nScrollPosX + m_pRectWnd->left;
		nRight = scalePrevX( nRight ) - m_pViewCtrl->m_nScrollPosX + m_pRectWnd->left;
		nTop = scalePrevY( nTop ) - m_pViewCtrl->m_nScrollPosY + m_pRectWnd->top;
		nBottom = scalePrevY( nBottom ) - m_pViewCtrl->m_nScrollPosY + m_pRectWnd->top;
		if (!( m_nThick = scalePrevY( pData->wThick )))
			m_nThick = 1;
		drawBoxPD( m_hDC, pData, nLeft, nTop, nRight - nLeft + 1,
			nBottom - nTop + 1, nFillMode );
	}
	else
	{ // printing, scale and print
		// adjust for unprintable region
		if ( nLeft > m_pViewCtrl->m_sizeUnprint.cx )
			nLeft -= m_pViewCtrl->m_sizeUnprint.cx;
		if ( nRight > m_pViewCtrl->m_sizeUnprint.cx )
			nRight -= m_pViewCtrl->m_sizeUnprint.cx;
		if ( nTop > m_pViewCtrl->m_sizeUnprint.cy )
			nTop -= m_pViewCtrl->m_sizeUnprint.cy;
		if ( nBottom > m_pViewCtrl->m_sizeUnprint.cy )
			nBottom -= m_pViewCtrl->m_sizeUnprint.cy;
		// now scale to printer units
		nLeft = scalePrtX( nLeft );
		nRight = scalePrtX( nRight );
		nTop = scalePrtY( nTop );
		nBottom = scalePrtY( nBottom );
		if (!( m_nThick = scalePrtY( pData->wThick )))
			m_nThick = 1;
		drawBoxPD( m_hDC, pData, nLeft, nTop, nRight - nLeft + 1,
			nBottom - nTop + 1, FM_BOTH );
	}
}
