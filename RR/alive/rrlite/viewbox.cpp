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
// Handles rendering of boxes
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/viewbox.cpv  $
// 
//    Rev 1.5   30 Apr 1997 16:50:42   amh
// No change.
// 
//    Rev 1.4   01 Apr 1997 15:52:08   smh
// latest sources on 4/1/97
// 
//    Rev 1.3   22 Mar 1997 19:42:28   smh
// Sources from 1/24/97
// 
//    Rev 1.2   19 Dec 1996 16:26:16   smh
// Added auto-comment header.
// 

#include <windows.h>
#include "rrvwctrl.h"
#include "reppage.h"

///////////////////////////////////////////////////////////////
// Constructor
ViewBox::ViewBox( ViewCtrl *pViewCtrl, HDC hDC, BOOL bPreview, LPRECT pRect,
	UINT nCount, LINE_BOX *pData ) : ViewLBox( pViewCtrl, hDC, bPreview, pRect, nCount, pData )
{
	m_pData = pData;	// pointer to line/box array
}

///////////////////////////////////////////////////////////////
// Destructor
ViewBox::~ViewBox()
{
}

///////////////////////////////////////////////////////////////
// Render boxes by calling common line/box code
void ViewBox::showPage( void )
{
	UINT ii;
	LINE_BOX *pBox;

	if ( m_bPreview )
	{ // to screen
		for ( ii = 0, pBox = m_pData; ii < m_nCount; ii++, pBox++ )
			renderLineBox( pBox, FM_INTERIOR );	// fill mode is FILL
		for ( ii = 0, pBox = m_pData; ii < m_nCount; ii++, pBox++ )
			renderLineBox( pBox, FM_OUTLINE );	// fill mode is OUTLINE
	}
	else
	{ // to printer
		for ( ii = 0, pBox = m_pData; ii < m_nCount; ii++, pBox++ )
			renderLineBox( pBox, FM_BOTH );		// fill mode is BOTH
	}
}
