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
// Header for line/box display objects
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/viewlbox.h_v  $
// 
//    Rev 1.2   22 Mar 1997 18:52:46   smh
// Sources from 1/24/97
// 
//    Rev 1.1   19 Dec 1996 16:28:52   smh
// Added auto-comment header.
// 

#ifndef _VIEWLBOX_H_
#define _VIEWLBOX_H_

#include "viewrep.h"

class ViewLBox : public ViewRep
{   
public:
	// constructor
	ViewLBox( ViewCtrl *, HDC, BOOL, LPRECT, UINT, LINE_BOX * );
	// destructor
	~ViewLBox();

protected:
// Attributes
public:
	LINE_BOX	*m_pData;
protected:
	HBRUSH		m_hLineBrush;
	COLORREF	m_rgbHatchBack;
	int			m_nThick;
// Methods
	void		rectLinePD( HDC, int, int, int, int );
	void		drawBoxPD( HDC, LINE_BOX *, int, int, int, int, int );
	void		renderLineBox( LINE_BOX *, int );
};

// Line class
class ViewLine : public ViewLBox
{   
public:
	// constructor
	ViewLine( ViewCtrl *, HDC, BOOL, LPRECT, UINT, LINE_BOX * );
	// destructor
	~ViewLine();

protected:
// Attributes
public:
	void showPage();
};

// Box class
class ViewBox : public ViewLBox
{   
public:
	// constructor
	ViewBox( ViewCtrl *, HDC, BOOL, LPRECT, UINT, LINE_BOX * );
	// destructor
	~ViewBox();

protected:
// Attributes
public:
	void showPage();
};

// Bit settings for line/box sides and outlining modes - from product.h
#define bxLine		0x80		// its a line
#define bxLeft		0x01		// left side of box
#define bxRight		0x02		// right side of box
#define bxTop		0x04		// top side of box
#define bxBottom	0x08		// bottom side of box
#define bxAll		0x0F		// all sides
#define bxVert		0x40		// its a vertical line.

// alignment - from align.h
#define txLEFT		0x10	// left
#define txCENTER	0x20	// center
#define txRIGHT		0x30	// right

// Define fill modes for drawBoxPD() - must be separate bits
#define FM_OUTLINE		1
#define FM_INTERIOR		2
#define FM_BOTH			(FM_OUTLINE | FM_INTERIOR)

#endif // end _VIEWLBOX_H_
