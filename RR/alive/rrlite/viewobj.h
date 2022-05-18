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
// Header for OLE display object
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/viewobj.h_v  $
// 
//    Rev 1.0   20 Mar 1997 12:12:54   smh
// Initial revision.
// 

#ifndef _VIEWOBJ_H_
#define _VIEWOBJ_H_

#include "viewrep.h"

// report OLE object structure
typedef struct OLEObject	// pdi export object structure
{
/*****  This top portion copied from EXPORT_OBJECT structure  ******/
	WORD			x;				// horizontal position
	WORD			y;				// vertical position
	WORD			wWidth;			// width
	WORD			wHeight;		// height
	WORD			wScaling;		// Scaling
	SIZE			sizeActual;		// Actual size
	SIZE			sizeCrop;		// Crop size
	short			nAspect;		// Aspect
/*******************************************************************/
	WORD			wStatus;		// object flags
	HGLOBAL			hStorage;		// global handle to storage
	LPOLECLIENTSITE pClientSite;	// client site
	LPUNKNOWN		pUnknown;		// IUnknown interface
	LPLOCKBYTES		pLockBytes;		// byte array to hold storage
	LPSTORAGE		pStorage;		// pointer to storage
} OBJECT;

///////////////////////////////////////////////////////////////
// Transient view object class - renders objects for each page
class ViewObject : public ViewRep
{   
public:
	// constructor
	ViewObject( ViewCtrl *, HDC, BOOL, LPRECT, UINT, OBJECT * );
	// destructor
	~ViewObject();

// Attributes
private:
	OBJECT			*m_pObject;
	LPVOID			m_pObjectData;

	void			renderObject( OBJECT * );
public:
	void			showPage();
};

// object scaling values
#define PARTSCALE	0
#define NOSCALE		1
#define FULLSCALE	2

// object status bits (OBJECT.wStatus)
#define OBJECT_STATUS_UNLOADED	0	// object ready for loading
#define OBJECT_STATUS_LOADED	1	// object has been (OLE) loaded
#define OBJECT_STATUS_ERROR		2	// tried, but could not load

#endif // end _VIEWOBJ_H_
