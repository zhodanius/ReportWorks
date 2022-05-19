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
// pstr.c		string function picture routines
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/cfcomp/pstr.cpv  $
// 
//    Rev 1.5   26 Sep 1995 15:21:50   pjm
// RSW composite class changes.
// 
//    Rev 1.4   19 Sep 1995 10:47:40   jpb
// error cleanup
// 
//    Rev 1.3   18 Sep 1995 15:00:36   jpb
// move funcs to CRrComposite
// 
//    Rev 1.2   02 Aug 1995 10:01:26   sjo
// I needed to move the include of the class headers from just after the include
// of product.h, to just after the #define of the module name.
// 
//    Rev 1.1   20 Jul 1995 16:41:48   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.0   16 Mar 1995 16:22:20   sbc
// Initial revision.
// 
//    Rev 1.1   18 Jan 1995 17:47:50   sjo
// Made changes to remove compiler warnings.
// 
//    Rev 1.0   14 Oct 1993 10:16:18   sjo
// Initial revision.
// ****************************************************************************
#include "product.h"

//
// Make a definition for this module.
//
#define _PSTR_C_

#include "rrdoc.h"
#include "mainfrm.h"
#include "ctype.h"
#include "_cfcomp.h"

#define LENDATE 8 /* dd/mm/yy (also defined in pdate.c) */


void CRrComposite::pat()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1,p2,p3;

	pDoc->m_pComposite->poppic(&p3);
	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(p2.pLen<10 ? 1 :p2.pLen<100 ? 2 : 3, 0);
}

void CRrComposite::plen()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(p1.pLen<10 ? 1 :p1.pLen<100 ? 2 : 3, 0);
}

void CRrComposite::pspc()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	if (p1.pType&pCONST && (p1.pVal<0)) p1.pVal = 0; /* no neg literal arg */
	pDoc->m_pComposite->pushspic(p1.pType&pCONST ? (int)p1.pVal : p1.pInt==1 ? 9 : 20,
		p1.pType&pCONST ? (int)p1.pVal : 0);
}

void CRrComposite::psubst()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1,p2,p3;
	int sub, len, mlen, maxlen, p2const, p3const;

	pDoc->m_pComposite->poppic(&p3);
	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->poppic(&p1);
	p2const = p2.pType&pCONST;
	p3const = p3.pType&pCONST;
	sub = p2const ? ((int)p2.pVal)-1 : 0;
	len = p3const ? (int)p3.pVal : p1.pLen-sub;
	mlen = p3const ? (int)p3.pVal : p1.pMaxLen ? p1.pMaxLen-sub : 0;
	maxlen = p3const ? mlen : (p2const && p1.pMaxLen) ? mlen : 0;
	pDoc->m_pComposite->pushspic(len <= 0 ? 1 : len, maxlen < 0 ? 1 : maxlen);
}

void CRrComposite::pasc()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(3,0);
}

void CRrComposite::pchr()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushspic(1,1);
}

void CRrComposite::pstr()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;
	int len=10;
	int maxlen=0;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p1);
	if (p1.pType&pCONST && ((int)p1.pVal > 0)) maxlen=len = (int)p1.pVal;
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushspic(len,maxlen);
}

/* is alpha, upper, lower - also used for ferrval() */
void CRrComposite::pisx()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushlpic();
}

/* left / right */
void CRrComposite::plr()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1,p2;
	int p2const, len, maxlen;

	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->poppic(&p1);
	if (p2const=p2.pType&pCONST)
	{
		len = (int)(p2.pVal+0.5);	/* fleft/fright round up */
		if (len<=0) len = 1;
		maxlen = len;
	}
	else
	{
		maxlen = 0; 	/* not exact */
		len = p1.pLen;
	}
	pDoc->m_pComposite->pushspic(len, maxlen);
}

void CRrComposite::prepl()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1,p2;
	int len;
	int maxlen=0;

	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->poppic(&p1);
	if (p2.pType&pCONST)
	{
		len = (int)((p2.pVal*p1.pLen)+0.5);
		if (p1.pMaxLen) maxlen = len;
	}
	else
	{
		len = 20;
	}
	pDoc->m_pComposite->pushspic(len, maxlen);
}

void CRrComposite::pstuff()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1,p2,p3,p4;
	int len;

	pDoc->m_pComposite->poppic(&p4);
	pDoc->m_pComposite->poppic(&p3);
	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->poppic(&p1);
	len = p4.pLen+p1.pLen;
	pDoc->m_pComposite->pushspic(len,(p1.pType&p4.pType&pCONST) ? len : 0);
}

void CRrComposite::pstrrep()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1,p2,p3,p4;

	pDoc->m_pComposite->poppic(&p4);
	pDoc->m_pComposite->poppic(&p3);
	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushspic(p1.pLen+1,0);
}

void CRrComposite::pstrsearch()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1,p2,p3,p4;

	pDoc->m_pComposite->poppic(&p4);
	pDoc->m_pComposite->poppic(&p3);
	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(p2.pLen<10 ? 1 :p2.pLen<100 ? 2 : 3, 0);
}

void CRrComposite::pstrcount()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1,p2,p3;

	pDoc->m_pComposite->poppic(&p3);
	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(p2.pLen<10 ? 1 :p2.pLen<100 ? 2 : 3, 0);
}

void CRrComposite::pcaps()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pnoop();
}

void CRrComposite::psndx()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushspic(4,4);
}

void CRrComposite::pwdcnt()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;
	int maxwds;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p1);
	maxwds = (p1.pLen+1)/2;
	pDoc->m_pComposite->pushnpic(maxwds<10 ? 1 :maxwds<100 ? 2 : 3, 0);
}

void CRrComposite::pword()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushspic(p1.pLen, p1.pMaxLen);
}

#ifdef RSW
void CRrComposite::plike()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1,p2;

	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->poppic(&p1);
	pushlpic();
}
#endif

void CRrComposite::priparam()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushspic(15,0);
}

void CRrComposite::pclookup()
{ /* pDoc->pop the 5 arguments */
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);	/* optional tag */
	pDoc->m_pComposite->poppic(&p1);	/* optional index */
	pDoc->m_pComposite->poppic(&p1);	/* related database */
	pDoc->m_pComposite->poppic(&p1);	/* target field */
	pDoc->m_pComposite->poppic(&p1);	/* lookup value */
	pDoc->m_pComposite->pushspic(10, 0);	/* set length of target field arbitrarily */
}


