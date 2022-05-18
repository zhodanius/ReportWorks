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
// Header for display chart
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/viewchrt.h_v  $
// 
//    Rev 1.0   22 May 1997 17:21:18   par
// Initial revision.
// 
// 

#ifndef _VIEWCHRT_H_
#define _VIEWCHRT_H_

#include "viewrep.h"

// report OLE object structure
typedef struct PDIChart	// pdi export object structure
{
/*****  This top portion copied from EXPORT_CHART structure  ******/
	WORD    x;                // horizontal position
	WORD    y;                // vertical position
	WORD    wWidth;           // width
	WORD    wHeight;          // height
	SIZE    sizeActual;       // Actual size
	SIZE    sizeCrop;         // Crop size
/*******************************************************************/
	HGLOBAL	hmf;              // global handle to metafile
} CHART;

///////////////////////////////////////////////////////////////
// Transient view object class - renders objects for each page
class ViewChart : public ViewRep
{   
public:
	// constructor
	ViewChart( ViewCtrl *, HDC, BOOL, LPRECT, UINT, CHART * );
	// destructor
	~ViewChart();

// Attributes
private:
	CHART			*m_pChart;
	LPVOID			m_pChartData;

	void			renderChart( CHART * );
public:
	void			showPage();
};

#endif // end _VIEWCHRT_H_
