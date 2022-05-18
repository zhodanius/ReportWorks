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
// Handles rendering of OLE objects
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/viewobj.cpv  $
// 
//    Rev 1.3   11 Jul 1997 16:29:38   smh
// Adjust object width too when adjust left side for scrolling.
// 
//    Rev 1.2   10 Jul 1997 12:31:00   smh
// OLE objects weren't scrolling horizontally b/c wasn't adjusting
// left edge by scroll pos.
// 
//    Rev 1.1   01 Apr 1997 15:52:04   smh
// latest sources on 4/1/97
// 
//    Rev 1.0   20 Mar 1997 12:12:08   smh
// Initial revision.
// 

#include <windows.h>
#include "rrvwctrl.h"
#include "reppage.h"
#include "viewobj.h"

///////////////////////////////////////////////////////////////
// Constructor
ViewObject::ViewObject( ViewCtrl *pViewCtrl, HDC hDC, BOOL bPreview, LPRECT pRect,
	UINT nCount, OBJECT *pObject ) : ViewRep( pViewCtrl, hDC, bPreview, pRect, nCount )
{
	m_pObject = pObject;	// pointer to object array
}

///////////////////////////////////////////////////////////////
// Destructor
ViewObject::~ViewObject()
{
}

///////////////////////////////////////////////////////////////
// Ask object to render itself
void ViewObject::renderObject( OBJECT *pObject )
{
	int imgX, imgRight, imgY, imgWid, imgHite;
	RECT rclBounds;
	RECT rectObject;

	if ( m_bPreview )
	{ // preview, scale and show
		imgX = scalePrevX( pObject->x ) - m_pViewCtrl->m_nScrollPosX + m_pRectWnd->left;
		imgRight = imgX + scalePrevX( pObject->wWidth );
		imgWid = imgRight - imgX;
		imgY = scalePrevY( pObject->y - pObject->wHeight ) +
			m_pRectWnd->top - m_pViewCtrl->m_nScrollPosY;
		imgHite = scalePrevY( pObject->y ) + m_pRectWnd->top - m_pViewCtrl->m_nScrollPosY - imgY;
		::SetRect( &rectObject, imgX, imgY, imgX + imgWid, imgY + imgHite );
		::CopyRect( &rclBounds, &rectObject );
		if ( pObject->wScaling == NOSCALE )
		{ // crop to fit
			int nFullWidth  = MulDiv ( imgWid,  pObject->sizeActual.cx, pObject->sizeCrop.cx );
			int nFullHeight = MulDiv ( imgHite, pObject->sizeActual.cy, pObject->sizeCrop.cy );
			rclBounds.right  = rclBounds.left + nFullWidth ;
			rclBounds.bottom = rclBounds.top  + nFullHeight;
		}
		if (( rclBounds.left <= m_pRectWnd->right ) && ( rclBounds.right  >= m_pRectWnd->left ) &&
			 ( rclBounds.top  <= m_pRectWnd->bottom ) && ( rclBounds.bottom >= m_pRectWnd->top ))
		{ // gotta show it
			if ( pObject->wScaling == NOSCALE )
				::IntersectClipRect ( m_hDC, rectObject.left, rectObject.top,
					rectObject.right, rectObject.bottom );
			::OleDraw( pObject->pUnknown, pObject->nAspect, m_hDC, &rclBounds );
			if ( pObject->wScaling == NOSCALE )
				::SelectClipRgn ( m_hDC, NULL );  // revert back to client rect
		}
	}
	else
	{ // printing
		imgX = pObject->x;
		imgY = pObject->y;
		// adjust for unprintable region
		if ( imgX > m_pViewCtrl->m_sizeUnprint.cx )
			imgX -= m_pViewCtrl->m_sizeUnprint.cx;
		if ( imgY > m_pViewCtrl->m_sizeUnprint.cy )
			imgY -= m_pViewCtrl->m_sizeUnprint.cy;
		// now scale to printer units
		imgX = scalePrtX( imgX );
		imgWid = scalePrtX( pObject->wWidth );
		imgHite = scalePrtY( pObject->wHeight );
		imgY = scalePrtY( imgY ) - imgHite;
		::SetRect( &rectObject, imgX, imgY, imgX + imgWid, imgY + imgHite );
		::CopyRect( &rclBounds, &rectObject );
		if ( pObject->wScaling == NOSCALE )
		{ // crop to fit
			RECT rectFull;
			CopyRect( &rectFull, &rectObject );
			int nFullWidth  = MulDiv ( imgWid,  pObject->sizeActual.cx, pObject->sizeCrop.cx );
			int nFullHeight = MulDiv ( imgHite, pObject->sizeActual.cy, pObject->sizeCrop.cy );
			rectFull.right  = rclBounds.left + nFullWidth ;
			rectFull.bottom = rclBounds.top  + nFullHeight;
			::IntersectClipRect ( m_hDC, rectObject.left, rectObject.top,
				rectObject.right, rectObject.bottom );
			::OleDraw( pObject->pUnknown, pObject->nAspect, m_hDC, &rectFull );
			::SelectClipRgn ( m_hDC, NULL );  // revert back to client rect
		}
		else
			::OleDraw( pObject->pUnknown, pObject->nAspect, m_hDC, &rclBounds );
	}
}

///////////////////////////////////////////////////////////////
// Render objects on page
void ViewObject::showPage( void )
{
	OBJECT *pObject = m_pObject;

	for ( UINT ii = 0; ii < m_nCount; ii++, pObject++ )
	{ // render objects, loading them if necessary
		if ( pObject->wStatus == OBJECT_STATUS_UNLOADED )
		{ // must load after processing this draw request
			PostMessage( m_pViewCtrl->getCtrlHwnd(), WM_USER_LOADOLE, ii, 0 );
		}
		else if ( pObject->wStatus == OBJECT_STATUS_LOADED )
			renderObject( pObject );	// display object
	}
}
