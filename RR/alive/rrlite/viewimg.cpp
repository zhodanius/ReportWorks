// ****************************************************************************
//
//              (C) Copyright 1996 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
// Handles rendering of images
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/viewimg.cpv  $
// 
//    Rev 1.6   30 Apr 1997 16:52:22   amh
// Merged with Steve C's latest source on 4-30-97
//
//    Rev 1.5   01 Apr 1997 15:52:06   smh
// latest sources on 4/1/97
// 
//    Rev 1.4   22 Mar 1997 19:40:20   smh
// Sources from 1/24/97
// 
//    Rev 1.3   19 Dec 1996 16:26:24   smh
// Added auto-comment header.
// 

#include <windows.h>
#include "rrvwctrl.h"
#include "viewimg.h"
#include "accusoft.h"

///////////////////////////////////////////////////////////////
// Constructor
ViewImage::ViewImage( ViewCtrl *pViewCtrl, HDC hDC, BOOL bPreview, LPRECT pRect,
	UINT nCount, IMAGE *pImage ) : ViewRep( pViewCtrl, hDC, bPreview, pRect, nCount )
{
	m_pImage = pImage;		// pointer to image array
}

///////////////////////////////////////////////////////////////
// Destructor
ViewImage::~ViewImage()
{
}

///////////////////////////////////////////////////////////////
// Speed up image preview by caching the last image as a DDB
void ViewImage::displayDDB( int nDib, HDC hDC, int nLeft, int nTop, int nWidth, int nHeight )
{
	if ( nDib != m_nLastDIB )
	{ // if changing to a new image, remove cached bitmap
		if ( m_hLastDDB != (HANDLE)-1 )
			DeleteObject( m_hLastDDB );
		m_hLastDDB = DIBtoDDB( m_pViewCtrl->m_hMutex, nDib, nWidth, nHeight );
		m_nLastDIB = nDib;
	}
	displayDdb( m_pViewCtrl->m_hMutex, m_hLastDDB, hDC, nLeft, nTop );
}

///////////////////////////////////////////////////////////////
// Output image to display or printer
void ViewImage::renderImage( IMAGE *pImg )
{
	int nRight, nTop, nWid, nHeight;
	int nLeft = pImg->wLeft;
	int nBottom = pImg->wBottom;
	
	if ( pImg->nDib >= 0 )
	{ // okay to render
		if ( m_bPreview )
		{ // preview, scale and show
			nLeft  = scalePrevX( nLeft ) - m_pViewCtrl->m_nScrollPosX + m_pRectWnd->left;
			nRight = nLeft + scalePrevX( pImg->wWidth );
			nWid   = nRight - nLeft;
			nBottom = scalePrevY ( nBottom );
			nTop   = nBottom - scalePrevY( pImg->wHeight );
			nHeight = nBottom - nTop;
			// set cropping rectangle, if any
			if ( !pImg->bCropped && ( pImg->wCropWidth || pImg->wCropHeight ))
			{ // cropped image
				setCropRect( m_pViewCtrl->m_hMutex, pImg->nDib,
					MulDiv( ::GetDeviceCaps( m_hDC, LOGPIXELSX ), pImg->wCropWidth, HZRES ),
					MulDiv( ::GetDeviceCaps( m_hDC, LOGPIXELSY ), pImg->wCropHeight, VTRES ));
				pImg->bCropped = TRUE;	// crop once
			}
			// now adjust for scroll position and window rectangle
			nTop = nTop - m_pViewCtrl->m_nScrollPosY + m_pRectWnd->top;
	  		displayDDB( pImg->nDib, m_hDC, nLeft, nTop, nWid, nHeight );
		}
		else
		{ // printing, adjust for unprintable regions
			if ( nLeft > m_pViewCtrl->m_sizeUnprint.cx )
				nLeft -= m_pViewCtrl->m_sizeUnprint.cx;
			if ( nBottom > m_pViewCtrl->m_sizeUnprint.cy )
				nBottom -= m_pViewCtrl->m_sizeUnprint.cy;
			// now scale to printer units
			nLeft = scalePrtX( nLeft );
			nWid  = scalePrtX( pImg->wWidth );
			nHeight = scalePrtY( pImg->wHeight );
			nTop = scalePrtY( nBottom ) - nHeight;
			if ( !pImg->bCropped && ( pImg->wCropWidth || pImg->wCropHeight ))
			{ // cropped image
				setCropRect( m_pViewCtrl->m_hMutex, pImg->nDib,
					scalePrtX( pImg->wCropWidth ), scalePrtY( pImg->wCropHeight ));
				pImg->bCropped = TRUE;
			}
			printFast( m_pViewCtrl->m_hMutex, pImg->nDib, m_hDC, nLeft, nTop, nWid, nHeight );
		}
	}
}

///////////////////////////////////////////////////////////////
// Scan PDI data & output page to screen or printer - maintain R&R code
void ViewImage::showPage( void )
{
	if ( loadImageLib())
	{ // Accusoft DLL loaded
		m_nLastDIB = -1;
		m_hLastDDB = (HBITMAP)-1;
		IMAGE *pImg = m_pImage;

		// show each image on page
		for ( UINT ii = 0; ii < m_nCount; ii++, pImg++ )
			renderImage( pImg );

		if ( m_hLastDDB != (HANDLE)-1 )
			DeleteObject( m_hLastDDB );	
	}
}
