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
// Header for page data object
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/reppage.h_v  $
// 
//    Rev 1.5   22 May 1997 17:50:16   par
// Charting in Viewer control works
// 
//    Rev 1.4   01 Apr 1997 15:52:00   smh
// latest sources on 4/1/97
// 
//    Rev 1.3   22 Mar 1997 19:20:08   smh
// Sources from 1/24/97
// 
//    Rev 1.2   31 Dec 1996 11:04:58   smh
// Move defines to pdx.h.
//
//    Rev 1.1   19 Dec 1996 16:28:12   smh
// Added auto-comment header.
//

#ifndef _REPPAGE_H_
#define _REPPAGE_H_

#include "pdx.h"
#include "viewtext.h"
#include "viewlbox.h"
#include "viewimg.h"
#include "viewobj.h"
#include "viewchrt.h"

class RepPage
{   
public:
	RepPage( ViewCtrl * );

	~RepPage();

	BOOL		m_bPageReady;
	DWORD		m_dwFilePos;
	// text
	DWORD		m_dwTextByteCount;
	LPSTR		m_pText;
	// lines
	UINT		m_nLineCount;
	LINE_BOX	*m_pLines;
	// boxes
	UINT		m_nBoxCount;
	LINE_BOX	*m_pBoxes;
	// images
	UINT		m_nImageCount;
	IMAGE		*m_pImages;
	// OLE objects
	UINT		m_nObjectCount;
	OBJECT		*m_pObjects;
	// Charts
	UINT		m_nChartCount;
	CHART		*m_pCharts;
private:
	ViewCtrl*	m_pViewCtrl;
public:
	BOOL		loadObject( int nObject );
	BOOL		printPage( HDC, LPRECT, BOOL );
};

// page size defaults (720ths)
#define PAGE_WIDTH_DEFAULT		6120
#define PAGE_HEIGHT_DEFAULT		7920

#endif // end _REPPAGE_H_
