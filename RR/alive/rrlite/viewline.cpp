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
// Handles rendering of line segments
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/viewline.cpv  $
// 
//    Rev 1.4   01 Apr 1997 15:52:04   smh
// latest sources on 4/1/97
// 
//    Rev 1.3   22 Mar 1997 19:34:54   smh
// Sources from 1/24/97
// 
//    Rev 1.2   19 Dec 1996 16:26:44   smh
// Added auto-comment header.
// 

#include <windows.h>
#include "rrvwctrl.h"
#include "reppage.h"

///////////////////////////////////////////////////////////////
// Constructor
ViewLine::ViewLine( ViewCtrl *pViewCtrl, HDC hDC, BOOL bPreview, LPRECT pRect,
	UINT nCount, LINE_BOX *pData ) :	ViewLBox( pViewCtrl, hDC, bPreview, pRect, nCount, pData )
{
	m_pData = pData;	// pointer to line/box array
}

///////////////////////////////////////////////////////////////
// Destructor
ViewLine::~ViewLine()
{
}

///////////////////////////////////////////////////////////////
// Render lines by calling common line/box code
void ViewLine::showPage( void )
{
	UINT ii;
	LINE_BOX *pLine;

	for ( ii = 0, pLine = m_pData; ii < m_nCount; ii++, pLine++ )
		renderLineBox( pLine, FM_BOTH );		// fill mode is BOTH
}
