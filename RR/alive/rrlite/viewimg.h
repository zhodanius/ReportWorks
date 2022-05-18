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
// Header for image display object
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/viewimg.h_v  $
// 
//    Rev 1.2   22 Mar 1997 18:55:00   smh
// Sources from 1/24/97
// 
//    Rev 1.1   19 Dec 1996 16:28:46   smh
// Added auto-comment header.
// 

#ifndef _VIEWIMG_H_
#define _VIEWIMG_H_

#include "viewrep.h"

typedef struct pdiImage	// pdi export image structure
{
	WORD wLeft;			// horizontal position
	WORD wBottom;		// vertical position
	WORD wWidth;		// image width
	WORD wHeight;		// image height
	WORD wCropWidth;	// cropping width
	WORD wCropHeight;	// cropping height
	int  nDib;			// Accusoft handle
	BOOL bCropped;		// crop flag
} IMAGE;

class ViewImage : public ViewRep
{   
public:
	// constructor
	ViewImage( ViewCtrl *, HDC, BOOL, LPRECT, UINT, IMAGE * );
	// destructor
	~ViewImage();

protected:
// Attributes
public:
	IMAGE		*m_pImage;
private:
	HBITMAP		m_hLastDDB;		// last DDB used
	int			m_nLastDIB;		// last DIB used
public:
	void		displayDDB( int, HDC, int, int, int, int );
	BOOL		readImageFile( LPCTSTR );
	void		renderImage( IMAGE * );
	void		showPage();
};

#endif // end _VIEWIMG_H_
