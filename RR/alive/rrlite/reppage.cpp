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
// Report page object handler
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/alive/rrlite/REPPAGE.CPV  $
// 
//    Rev 1.5   Feb 07 2000 14:58:04   nhubacker
// Syntax error for C++ 6.0
// 
//    Rev 1.4   22 May 1997 16:30:34   par
// Charts are now being displayed in the viewer control.
// 
//    Rev 1.3   01 Apr 1997 15:52:12   smh
// latest sources on 4/1/97
// 
//    Rev 1.2   22 Mar 1997 20:06:16   smh
// Sources from 1/24/97
// 
//    Rev 1.1   19 Dec 1996 16:19:34   smh
// Added auto-comment header.
// 

#include <windows.h>
#include "rrvwctrl.h"
#include "reppage.h"
#include "rrutil.h"
#include "contain.h"
#include "accusoft.h"

///////////////////////////////////////////////////////////////
// Constructor
RepPage::RepPage( ViewCtrl *pViewCtrl )
{
	m_pViewCtrl       = pViewCtrl;
	m_bPageReady      = FALSE;
	m_nLineCount      = 0 ;
	m_nBoxCount       = 0 ;
	m_nImageCount     = 0 ;
	m_nObjectCount    = 0 ;
	m_nChartCount     = 0 ;
	m_dwTextByteCount = 0 ;
	// no objects (yet)
	m_pText    = NULL;
	m_pLines   = NULL;
	m_pBoxes   = NULL;
	m_pImages  = NULL;
	m_pObjects = NULL;
	m_pCharts  = NULL;
}

///////////////////////////////////////////////////////////////
// Destructor
RepPage::~RepPage()
{
	if ( m_pText != NULL )
	{ // delete any text data
		HeapFree( GetProcessHeap(), 0, m_pText );
	}
	if ( m_nLineCount && ( m_pLines != NULL ))
	{ // delete any lines
		HeapFree( GetProcessHeap(), 0, m_pLines );
	}
	if ( m_nBoxCount && ( m_pBoxes != NULL ))
	{ // delete any boxes
		HeapFree( GetProcessHeap(), 0, m_pBoxes );
	}
	if ( m_pImages != NULL )
	{ // delete any images
		IMAGE *pImg = m_pImages;
		for ( UINT ii = 0; ii < m_nImageCount; ii++, pImg++ )
		{ // delete images from memory first
			if ( pImg->nDib >= 0 )
				deleteImage( m_pViewCtrl->m_hMutex, pImg->nDib );
		}
		// now the whole enchilada
		HeapFree( GetProcessHeap(), 0, m_pImages );
	}
	if ( m_nObjectCount && ( m_pObjects != NULL ))
	{ // clean up OLE objects
		for ( UINT ii = 0; ii < m_nObjectCount; ii++ )
		{ // release object and free associated memory
			OBJECT *pObject = &m_pObjects[ii];
			if ( pObject->wStatus == OBJECT_STATUS_LOADED )
			{ // free objects & storage
				if ( pObject->pUnknown )
					pObject->pUnknown->Release();
				if ( pObject->pStorage )
					pObject->pStorage->Release();
				if ( pObject->pLockBytes )
					pObject->pLockBytes->Release();
				::GlobalFree( pObject->hStorage );
				if ( pObject->pClientSite != NULL )
					delete pObject->pClientSite;
			}
		}
		// free object structure array
		HeapFree( GetProcessHeap(), 0, m_pObjects );
	}
	if ( m_nChartCount && ( m_pCharts != NULL ))
	{ // clean up charts
		for ( UINT ii = 0; ii < m_nChartCount; ii++ )
		{ // release Chart and free associated memory
			CHART *pChart = &m_pCharts[ii];
			if ( pChart->hmf )
				::DeleteEnhMetaFile ( (HENHMETAFILE)pChart->hmf ) ;
		}
		// free object structure array
		HeapFree( GetProcessHeap(), 0, m_pCharts );
	}
}

///////////////////////////////////////////////////////////////////////
// Load OLE object to byte array storage
BOOL RepPage::loadObject( int nObject )
{
	BOOL bResult = FALSE;
	// create pointer from index into object structure array
	OBJECT *pObject = &m_pObjects[nObject];

	// open storage on byte array
	if ( SUCCEEDED( ::CreateILockBytesOnHGlobal( pObject->hStorage, TRUE, &pObject->pLockBytes )) &&
		 SUCCEEDED( ::StgOpenStorageOnILockBytes( pObject->pLockBytes, NULL, STGM_SHARE_EXCLUSIVE | STGM_READWRITE, NULL, 0, &pObject->pStorage )))
	{ // got the storage, make a (lazy) client site
		pObject->pClientSite = new COleClientSite();
		if ( pObject->pClientSite )
		{ // load the object and retrieve base interface pointer
			SCODE sc = ::OleLoad( pObject->pStorage, IID_IUnknown, pObject->pClientSite, (LPVOID *)&pObject->pUnknown );
			// that's it - how'd we do?
			bResult = SUCCEEDED( sc ) && pObject->pUnknown;
		}
	}
	if ( bResult )
	{ // flag as loaded if successful
		pObject->wStatus = OBJECT_STATUS_LOADED;
	}
	else
	{ // failed to load - free up some stuff
		if ( pObject->pStorage )
			pObject->pStorage->Release();
		if ( pObject->pLockBytes )
			pObject->pLockBytes->Release();
		::GlobalFree( pObject->hStorage );
		if ( pObject->pClientSite != NULL )
			delete pObject->pClientSite;
		// mark object as inaccessible
		pObject->wStatus = OBJECT_STATUS_ERROR;
	}
	return bResult;
}

///////////////////////////////////////////////////////////////
// Output text and 2D objects in proper order (s/b same as R&R)
BOOL RepPage::printPage( HDC hDC, LPRECT pWndRect, BOOL bPreview )
{
	if ( m_nBoxCount && ( m_pBoxes != NULL ))
	{ // boxes first
		ViewBox viewBox( m_pViewCtrl, hDC, bPreview, pWndRect, m_nBoxCount, m_pBoxes );
		viewBox.showPage();
	}
	if ( m_nLineCount && ( m_pLines != NULL ))
	{ // then lines
		ViewLine viewLine( m_pViewCtrl, hDC, bPreview, pWndRect, m_nLineCount, m_pLines );
		viewLine.showPage();
	}
	if ( m_nImageCount && ( m_pImages != NULL ))
	{ // then images
		ViewImage viewImage( m_pViewCtrl, hDC, bPreview, pWndRect, m_nImageCount, m_pImages );
		viewImage.showPage();
	}
	if ( m_nObjectCount && ( m_pObjects != NULL ))
	{ // then OLE objects
		ViewObject viewObject( m_pViewCtrl, hDC, bPreview, pWndRect, m_nObjectCount, m_pObjects );
		viewObject.showPage();
	}
	if ( m_nChartCount && ( m_pCharts != NULL ))
	{ // then OLE Charts
		ViewChart viewChart( m_pViewCtrl, hDC, bPreview, pWndRect, m_nChartCount, m_pCharts );
		viewChart.showPage();
	}
	if ( m_dwTextByteCount && ( m_pText != NULL ))
	{ // and finally text
		ViewText viewText( m_pViewCtrl, hDC, bPreview, pWndRect, m_dwTextByteCount, m_pText );
		viewText.showPage();
	}
	return TRUE; // what could go wrong?
}
