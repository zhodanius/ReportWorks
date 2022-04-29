// RrRpt32.h : main header file for the RRRPT32 DLL
//

#if !defined(_RRRPT32_H_)
#define _RRRPT32_H_

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "rr.h"		// for definition of CRrApp
/////////////////////////////////////////////////////////////////////////////
// CRrRptApp
// See RrRpt32.cpp for the implementation of this class
//

class CRrRptApp : public CRrApp
{
public:
			CRrRptApp();
	BOOL	InitInstance( void );
	int		ExitInstance( void );
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRrRptApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CRrRptApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

extern CRrRptApp NEAR theApp;	// defined in rrrpt32.cpp

#endif	// !defined(_RRRPT32_H_)