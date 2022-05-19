// ****************************************************************************
//
//		(C) Copyright 1992-1993 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
//			see if all needed udfs are compiled
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/cfcomp/ckufcomp.cpv  $
// 
//    Rev 1.4   19 Sep 1995 10:47:30   jpb
// error cleanup
// 
//    Rev 1.3   18 Sep 1995 15:00:22   jpb
// move funcs to CRrComposite
// 
//    Rev 1.2   02 Aug 1995 10:01:16   sjo
// I needed to move the include of the class headers from just after the include
// of product.h, to just after the #define of the module name.
// 
//    Rev 1.1   20 Jul 1995 16:41:38   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.0   16 Mar 1995 16:22:10   sbc
// Initial revision.
// 
//    Rev 1.0   14 Oct 1993 10:16:12   sjo
// Initial revision.
// ****************************************************************************
#include "product.h"
//
// Make a definition for this module.
//
#define _CKUFCOMP_C_
#include "rrdoc.h"
//#include "stdio.h"
//#include "_cfcomp.h"
#include "_cfmisc.h"        // for ufneeded proto
#include "print_.h"

LPUDF CRrComposite::lckufcomp()
{
	LPUDF u;

#ifdef RSW
	m_pDoc->saveneeded(TRUE,FALSE); /* set all zfNEEDED bits (in fields) */
#else
	m_pDoc->saveneeded(TRUE);	/* set all zfNEEDED bits (in fields) */
#endif
	ufneeded(); 		/* no set them in udfs */
	for (u=UDFS; u; u=u->uNext)
	{
		if ((u->uFlags&zfNEEDED) && (u->uExpE==NULL))
			return u; /* uncompiled! */
	}
	return NULL;
}



