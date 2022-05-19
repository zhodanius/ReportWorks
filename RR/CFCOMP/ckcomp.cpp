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
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/cfcomp/ckcomp.cpv  $
// 
//    Rev 1.4   19 Sep 1995 10:47:28   jpb
// error cleanup
// 
//    Rev 1.3   18 Sep 1995 15:00:22   jpb
// move funcs to CRrComposite
// 
//    Rev 1.2   02 Aug 1995 10:01:24   sjo
// I needed to move the include of the class headers from just after the include
// of product.h, to just after the #define of the module name.
// 
//    Rev 1.1   20 Jul 1995 16:41:46   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.0   16 Mar 1995 16:22:08   sbc
// Initial revision.
// 
//    Rev 1.1   26 Jul 1994 12:38:38   jpb
// Conditional totals support
// 
//    Rev 1.0   14 Oct 1993 10:16:12   sjo
// Initial revision.
// ****************************************************************************
#include "product.h"

//
// Make a definition for this module.
//
#define _CKCOMP_C_
#include "rrdoc.h"
//#include "stdio.h"
//#include "_cfcomp.h"
#include "print_.h"
#include "mfmisc.h"

LPMFFIELD CRrComposite::ckcomp()
{
	LPMFFIELD fld;
	LPSTR exp;

#ifdef RSW
	m_pDoc->saveneeded(TRUE,FALSE); /* set all zfNEEDED bits */
#else
	m_pDoc->saveneeded(TRUE);	/* set all zfNEEDED bits */
#endif
	for (fld=MFFields; fld; fld=fld->dNxtFld)
	{
		if (fld->dFlags&zfDUPFLD) continue;

		if (fld->dFlags&zfCALCULATED)		// calc?
			exp = fld->dRecU.calcS.dExpE;	// yes, use it's code
		else if (fld->dRFlags&rfTOTALFLD && fld->dRecU.insS.tExpD)// condtot?
			exp = fld->dRecU.insS.tExpE;	// yes, use it's code
		else continue;						// neither, skip it

		if ((fld->dFlags&zfNEEDED) && (exp==NULL))
			return fld; /* uncompiled! */
	}
	return NULL;
}

