// ****************************************************************************
//
//      (C) Copyright 1996 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
// Base class for viewing report data
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/viewrep.h_v  $
// 
//    Rev 1.3   22 Mar 1997 18:50:10   smh
// Changes from 1/24 sources.
// 
//    Rev 1.2   31 Dec 1996 11:08:10   smh
// New define for object size packet.
// 
//    Rev 1.1   19 Dec 1996 16:29:00   smh
// Added auto-comment header.
// 

#ifndef _VIEWREP_H_
#define _VIEWREP_H_

#include "pdx.h"

class ViewRep
{   
public:
	// constructor
			ViewRep( ViewCtrl *, HDC, BOOL, LPRECT, UINT );
	// destructor
			~ViewRep();
protected:
			ViewCtrl*	m_pViewCtrl;
			BOOL		m_bPreview;
			HDC			m_hDC;
			RECT		*m_pRectWnd;
			UINT		m_nCount;

			int			scalePrevX( int );
			int			scalePrevY( int );
			int			scalePrtX( int );
			int			scalePrtY( int );
			int			scalePosition( int, BOOL );
			void		showEndOfPage();
public:
	virtual	void		showPage() = 0;
};

// size of object count packets
#define SIZE_OBJECT_PACKET	sizeof( char ) + sizeof( char ) + sizeof( long )

#endif // end _VIEWREP_H_
