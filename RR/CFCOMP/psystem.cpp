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
// psystem.c		"system" function picture routines
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/cfcomp/psystem.cpv  $
// 
//    Rev 1.9   08 Apr 1997 10:29:24   pjm
// Use long tablename for Visual FoxPro DBC tables in DBF() function.
// 
//    Rev 1.8   06 Mar 1996 13:46:08   jpb
// libname() returns nothing if current report not from lib (default shape to
// size 30)
// 
//    Rev 1.7   22 Dec 1995 14:04:38   jpb
// fix prepn() maxlength arg problem
// 
//    Rev 1.6   26 Sep 1995 15:22:26   pjm
// RSW composite class changes.
// 
//    Rev 1.5   19 Sep 1995 10:47:42   jpb
// error cleanup
// 
//    Rev 1.4   18 Sep 1995 15:00:36   jpb
// move funcs to CRrComposite
// 
//    Rev 1.3   02 Aug 1995 10:01:42   sjo
// I needed to move the include of the class headers from just after the include
// of product.h, to just after the #define of the module name.
// 
//    Rev 1.2   24 Jul 1995 17:38:20   sjo
// Second round of arch changes. Fixed compile problems due to classification.
// 
//    Rev 1.1   20 Jul 1995 16:42:00   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.0   16 Mar 1995 16:22:20   sbc
// Initial revision.
// 
//    Rev 1.4   18 Jan 1995 17:47:58   sjo
// Made changes to remove compiler warnings.
// 
//    Rev 1.3   28 Sep 1994 09:25:38   vff
// Corrected typo in pudfn()
// 
//    Rev 1.2   27 Sep 1994 13:13:18   vff
// Fix bugs # 1736, 1788, 1803
// 
//    Rev 1.1   16 Jun 1994 10:03:18   vff
// Put debug code for UDFN() into R?W. Will need to be changed 
// 
//    Rev 1.0   14 Oct 1993 10:16:20   sjo
// Initial revision.
// ****************************************************************************
#include "product.h"


//
// Make a definition for this module.
//
#define _PSYSTEM_C_

#include "rrdoc.h"
#include "rr.h"
#include "mainfrm.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "_cfcomp.h"
#include "_cfeval.h"
#include "wutil.h"
#if !defined (RSW)
#include "mfmisc.h"
#endif
#include "global.h"

#define RANGELEN 15 	/* max len range name */

#ifndef RSW
void CRrComposite::pdbf()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;
	int fn;

	pDoc->m_pComposite->poppic(&p1);
	fn = p1.pType==pNONE ? 0 : (int)p1.pVal;
	if (pDoc->bDBCMode)
	{ // DBC long tablename, please
		char szLongName[MAXDNAME];
		strcpy (szLongName, pDoc->getLongTbl ((pDoc->m_pComposite->MFFiles[fn])->mDbfName));
		pDoc->m_pComposite->pushspic (lstrlen (szLongName), FNLEN);
	}
	else
		pDoc->m_pComposite->pushspic(lstrlen((pDoc->m_pComposite->MFFiles[fn])->mDbfName),FNLEN);
}

void CRrComposite::pscope()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushspic(10,0);
}
#endif

void CRrComposite::pflip()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1,p2;

	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushspic(p1.pLen, p1.pMaxLen);
}

void CRrComposite::ptransform()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1,p2;
	int len, maxlen;

	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->poppic(&p1);
	if ((p1.pType&~pCONST)==pSTR)
	{
		len = max(p1.pLen,p2.pLen);
		if (p1.pMaxLen==0 || p2.pMaxLen==0) maxlen = 0;
		else maxlen = max(p1.pMaxLen,p2.pMaxLen);
	}
	else if ((p1.pType&~pCONST)==pNUM)
	{
		if (p2.pLen<=3) len = 16;
		else len = max(25,p2.pLen);
		maxlen = len;
	}
	else
	{
		maxlen = len = p2.pLen;
	}
	pDoc->m_pComposite->pushspic(len,maxlen);
}

void CRrComposite::pquery()		/* QUERY() */
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);		/* no argument */
	pDoc->m_pComposite->pushwwspic(50,0);	/* picture length, unknown max length */
}

void CRrComposite::pcdll()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushspic(10,0);
}

void CRrComposite::plibn ()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	if (pDoc->m_bHaveLibrary)
	{
		pDoc->m_pComposite->pushspic(_fstrlen((pDoc->Paths)->LibName), WINPATHLEN);
	}
	else
	{
		pDoc->m_pComposite->pushspic(30, WINPATHLEN);
	}
}

void CRrComposite::pudfn()		/* VFF - UDFNAME() */
{
	CRrApp *pApp = (CRrApp *)AfxGetApp();
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;
/* This will need to be changed when R?W supports multiple UDF's */
/*	if (*UDFFile)				*//* VFF - do we have a defined UDF name? */
/*		pDoc->pushspic(strlen(UDFFile), PATHLENGTH);  *//* VFF - length of current path, max length of any lib path */
/*	else							*//* VFF - no, so get set to tell them "None" */
/*		pDoc->pushspic(strlen(MxNone), PATHLENGTH); */
	pDoc->m_pComposite->poppic(&p1);				/* VFF - no argument */
	pDoc->m_pComposite->pushspic(_fstrlen((pApp->Paths)->LinkPath)+7, WINPATHLEN);
}

void CRrComposite::prepn ()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;


	pDoc->m_pComposite->poppic(&p1);
	if (*(pDoc->RepName))
	{
		if (p1.pVal)
		{	// want full pathname
			pDoc->m_pComposite->pushspic(strlen(pDoc->RepName), WINPATHLEN); 
		}
		else
		{	// just filename
			char simpleName[WINPATHLEN];
			LPSTR ext;

			pDoc->getReportDisplayName( simpleName );
			ext = strrchr(simpleName,'.');
			if (ext && (strcmpi(ext+1,WxRepExt)==0))
				*ext = 0;	// chop off default ext of .rrw or .rsw

			pDoc->m_pComposite->pushspic(strlen(simpleName), WINPATHLEN); 
		}
	}
	else
	{
		pDoc->m_pComposite->pushspic(strlen(getString(IDS_0120,0)), WINPATHLEN);
	}
}

#if defined (RSW)

/* This is the IXSQL picture routine.  We are treating it a lot like
	(exactly like) len().  Apparently, someone figures out the length
	before we get here.  We would have to call the Q&E engine before we
	could figure out the length for the engine evaluatable expression.
  -sjo
	While merging it occurs to me that we can probably get rid of this
	routine.  I am not sure if an entry point isnt required for building
	functab. But perhaps a NULL pointer in the picture routine is OK.
*/

void CRrComposite::pixsql()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(p1.pLen<10 ? 1 :p1.pLen<100 ? 2 : 3, 0);
}

#endif
