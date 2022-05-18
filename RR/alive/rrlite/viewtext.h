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
// Header for PDI parser/renderer class
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/viewtext.h_v  $
// 
//    Rev 1.2   22 Mar 1997 18:47:50   smh
// Chaged showPage and ViewText prototypes.
// 
//    Rev 1.1   19 Dec 1996 16:29:06   smh
// Added auto-comment header.
//

#ifndef _VIEWTEXT_H_
#define _VIEWTEXT_H_

#include "viewrep.h"

class ViewText : public ViewRep
{   
public:
	// constructor
	ViewText( ViewCtrl *, HDC, BOOL, LPRECT, UINT, LPSTR );
	// destructor
	~ViewText();

protected:
// Attributes
public:
	LPSTR		m_pData;
private:
	int			m_yPos;
	LPSTR		m_pCurData;
	HFONT		m_hCurFont;
public:
	void		showPage();
private:
	BOOL		getByte( int * );
	BOOL		getWord( UINT * );
	BOOL		getString( LPSTR, int );
	int			textLength( LPCSTR, BOOL );
	void		setFont( LPSTR, int, int );
	int			sizeText( UINT *, UINT *, int, UINT * );
};

#define BOLD	1		// it's bold
#define ITALIC	2		// it's italic
#define UNDER	4		// and it's also underscored
#define STRIKE	8		// strike three, yur out!

#endif // end _VIEWTEXT_H_
