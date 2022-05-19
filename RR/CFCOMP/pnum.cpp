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
// pnum.c		numeric function picture routines
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/CFCOMP/PNUM.CPV  $
// 
//    Rev 1.7   Jan 19 2001 14:00:24   nhubacker
// Functions for lastpage(0) and reportpage()
// 
//    Rev 1.6   Dec 12 2000 15:48:12   nhubacker
// pgrpage() function
// 
//    Rev 1.5   19 Sep 1995 10:47:38   jpb
// error cleanup
// 
//    Rev 1.4   18 Sep 1995 15:00:34   jpb
// move funcs to CRrComposite
// 
//    Rev 1.3   02 Aug 1995 10:01:36   sjo
// I needed to move the include of the class headers from just after the include
// of product.h, to just after the #define of the module name.
// 
//    Rev 1.2   20 Jul 1995 16:41:56   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.1   27 Apr 1995 12:38:58   sjo
// Merge of 6.1.03+.  I say + because I have added some of the time functions
// to this merge, which will be a part of 6.1.04.  I merged the CF directories
// and some H files (for the time function changes).
// 
//    Rev 1.0   16 Mar 1995 16:22:18   sbc
// Initial revision.
// 
//    Rev 1.2   13 Feb 1995 15:37:44   jpb
// fix problem with pxmod routine when arg2 is boolean
// 
// ** First merge of RRW7 took place here.
//
//    Rev 1.1   18 Jan 1995 17:47:54   sjo
// Made changes to remove compiler warnings.
// 
//    Rev 1.0   14 Oct 1993 10:16:18   sjo
// Initial revision.
// ****************************************************************************
#include "product.h"
//
// Make a definition for this module.
//
#define _PNUM_C_

#include "rrdoc.h"
#include "mainfrm.h"
#include "stdio.h"
#include "ctype.h"
#include "_cfcomp.h"
#include "_cfeval.h"
#include "pic.h"

/* MIN and MAX */
void CRrComposite::pminmax()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1,p2;

	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushpnpic(max(p1.pInt,p2.pInt),max(p1.pDec,p2.pDec),p1.pPic);
}

void CRrComposite::pexp()
{
	CFPIC p1;
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushpnpic(2*p1.pInt,p1.pDec,p1.pPic);
}

void CRrComposite::pint()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	p1.pLen -= p1.pDec;
	p1.pDec = 0;
	pDoc->m_pComposite->pushpic(&p1);
}

void CRrComposite::prnd()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1,p2;
	int newdec;

	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->poppic(&p1);
	if (p2.pType&pCONST) newdec = max(0,(int)p2.pVal);
	else newdec = p1.pDec;
	p1.pLen -= (p1.pDec-newdec);
	p1.pDec = newdec;
	pDoc->m_pComposite->pushpic(&p1);
}

void CRrComposite::pval()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	if (!(p1.pType&pCONST))
	{
		p1.pInt = 5;
		p1.pDec = 2;
	}
	pDoc->m_pComposite->pushnpic(p1.pInt,p1.pDec);
}

void CRrComposite::ppage()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(4,0);
}

void CRrComposite::plastpage()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(4,0);
}

void CRrComposite::preportpage()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(4,0);
}

void CRrComposite::pcopy()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(3,0);
}

void CRrComposite::precn()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(5,0);
}

void CRrComposite::pdel()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushlpic();
	pDoc->m_pComposite->NextBoole = TRUE;
}

void CRrComposite::pxabs()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	if (p1.pType&pCONST && (p1.pVal < 0.0)) p1.pVal = -p1.pVal;
	if ((p1.pType&~pCONST)==pLOG)
	{ /* absolut value of a boolean, convert to numeric */
		p1.pType &= ~pLOG;	/* clear LOGICAL */
		p1.pType |= pNUM;	/* set NUMERIC */
		p1.pPic = picFIXED; /* numeric picture */
		p1.pLen = 1;		/* val is 1 or 0 */
	}
	pDoc->m_pComposite->pushpic(&p1);
}

void CRrComposite::pxmod()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1,p2;

	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->poppic(&p1);
	p2.pType &= ~pCONST;
	if (p2.pType & pLOG)	
	{ // change logical to numeric
		p2.pType = pNUM;
		p2.pPic = NPICDFLT;
	}
	pDoc->m_pComposite->pushpic(&p2);
}

void CRrComposite::piif()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p2,p3;

	pDoc->m_pComposite->poppic(&p3);
	pDoc->m_pComposite->poppic(&p2);
	p2.pType &= ~pCONST;
	if (p2.pType==pNUM)
	{
		p2.pDec = max(p2.pDec,p3.pDec);
		p2.pInt = max(p2.pInt,p3.pInt);
		p2.pLen = p2.pInt+p2.pDec;
	}
	else p2.pLen = max(p2.pLen,p3.pLen);
	if (p2.pMaxLen==0 || p3.pMaxLen==0) p2.pMaxLen = 0;
	else p2.pMaxLen = max(p2.pMaxLen,p3.pMaxLen);
	pDoc->m_pComposite->poppic(&p3);	/* get rid of the condition */
	pDoc->m_pComposite->pushpic(&p2);
}

void CRrComposite::pinrng()
{
/* pop three, push logical */
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushlpic();
}

void CRrComposite::pinlst()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;
	int resmax = pDoc->m_pComposite->args-1;

	while (pDoc->m_pComposite->args--) pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(resmax<10 ? 1 : resmax<100 ? 2 : 3,0);
}

void CRrComposite::pcase()
{
	CFPIC p1, p2;
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	int numeric = FALSE;
	int rescnt = (pDoc->m_pComposite->args/2)-1;
	int decp, intp, pic;
	unsigned int len, maxl;

	pDoc->m_pComposite->poppic(&p1);	/* gets default result */
	if ((p1.pType&~pCONST)==pNUM)
	{
		numeric = TRUE;
		decp = p1.pDec;
		intp = p1.pInt;
	}
	pic = p1.pPic;
	maxl = p1.pMaxLen;
	len = p1.pLen;

	while (rescnt--)
	{
		pDoc->m_pComposite->poppic(&p1);	/* gets next result */
		pDoc->m_pComposite->poppic(&p2);	/* gets corresponding case value */
		if (numeric)
		{
			if (p1.pDec>decp) decp = p1.pDec;
			if (p1.pInt>intp) intp = p1.pInt;
			pic = pDoc->m_pComposite->picpref(a_plus,pic,p1.pPic);
		}
		if (p1.pLen>len) len = p1.pLen;
		if (p1.pMaxLen==0) maxl = 0;
		else if (maxl && (p1.pMaxLen>maxl)) maxl = p1.pMaxLen;
	}
	pDoc->m_pComposite->poppic(&p2);	/* get input value */
	p1.pType &= ~pCONST;
	if (numeric) pDoc->m_pComposite->pushpnpic(intp,decp,pic);
	else
	{
		p1.pLen = len;
		p1.pMaxLen = maxl;
		p1.pPic = pic;
		pDoc->m_pComposite->pushpic(&p1);
	}
}

void CRrComposite::pspelln()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p;

	pDoc->m_pComposite->poppic(&p);
	pDoc->m_pComposite->pushspic(45,0);
}

void CRrComposite::pblnknum()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(1,0);
}


