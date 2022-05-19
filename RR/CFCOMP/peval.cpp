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
// peval.c	"evaluate" the picture for a calculated field
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/CFCOMP/PEVAL.CPV  $
// 
//    Rev 1.20   Oct 24 2002 08:54:02   Admin
// Prettify
// 
//    Rev 1.19   24 Feb 1997 15:54:48   jsf
// fixes RRW 2963, dFldPic2 was being set to the default, regional settings
// on file open when a calc field is compiled.  The bug was masked in 6.5
// when the field type yxHFLAGS was read, which reset dFldPic2 from the file,
// effectively overwriting the default data.  A new calc field is also ok
// as the setting is already in the field structure when a_ret is called.
// The change made tests if dFldPic2 is out of range and only then uses
// the default. BTW, yxHFLAGS is not in a 7.x report file. Phew!
// 
//    Rev 1.18   10 Feb 1997 10:02:08   sp
// Arp Live merge to trunk
// 
//    Rev 1.13.2.0   25 Oct 1996 18:11:00   jpb
//    Rev 1.14   25 Oct 1996 18:10:10   jpb
// force buffer realloc when resized and already have some (RSW only)
// 
//    Rev 1.13   01 Mar 1996 16:08:04   jpb
// fix 2104 (max integer+decimal places is 19)
// 
//    Rev 1.12   04 Oct 1995 17:04:14   smh
// Init pPic2 to zero where not otherwise initialized so that
// dFldPic2 not assigned to garbage for non datetime fields.
// 
//    Rev 1.11   22 Sep 1995 17:02:14   sjo
// Second round of FLDID changes.
// 
//    Rev 1.10   19 Sep 1995 17:56:44   sjo
// Changes made by looking at references to sizeof(int) in all sources for 32
// bit support.
// 
//    Rev 1.9   19 Sep 1995 10:47:36   jpb
// error cleanup
// 
//    Rev 1.8   18 Sep 1995 15:00:32   jpb
// move funcs to CRrComposite
// 
//    Rev 1.7   14 Sep 1995 14:55:26   sjo
// Changes for 32 bit support, mostly for pawing thru compiled code.
// 
//    Rev 1.6   15 Aug 1995 16:35:22   sjo
// Changes made for RSW compiles.
// 
//    Rev 1.5   02 Aug 1995 10:01:30   sjo
// I needed to move the include of the class headers from just after the include
// of product.h, to just after the #define of the module name.
// 
//    Rev 1.4   31 Jul 1995 13:51:16   sjo
// Another round of recompiling.
// 
//    Rev 1.3   24 Jul 1995 17:37:36   sjo
// Second round of arch changes. Fixed compile problems because of classifying
// 
//    Rev 1.2   20 Jul 1995 16:41:52   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.1   27 Apr 1995 12:35:42   sjo
// Merge of 6.1.03+.  I say + because I have added some of the time functions
// to this merge, which will be a part of 6.1.04.  I merged the CF directories
// and some H files (for the time function changes).
// 
//    Rev 1.0   16 Mar 1995 16:22:16   sbc
// Initial revision.
// 
//    Rev 1.11   06 Apr 1995 19:15:16   sjo
// Fixes as a result of date investigation of the cf directories.
// 
//    Rev 1.10   31 Mar 1995 10:04:50   sjo
// cleaned up some datetime stuff. Added datetime and time to bagit and 
// returned dFldPic2.
// 
//    Rev 1.9   28 Mar 1995 14:19:50   dlm
// Added initializers for pPic2 structure member of PIC.
// 
//    Rev 1.8   27 Mar 1995 19:38:50   sjo
// Added support for zfDATETIME and zfTIME fields.
// 
//    Rev 1.7   23 Mar 1995 17:08:18   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
//    Rev 1.6   21 Mar 1995 10:05:16   jpb
// Fix RSW 997
// 
//    Rev 1.5   08 Mar 1995 12:06:18   jpb
// Fixes RSW 1717
// 
//    Rev 1.4   07 Mar 1995 11:42:34   jpb
// RSW 1720
// 
//    Rev 1.3   08 Feb 1995 13:28:04   sjo
// Checking in a bunch of files for the first wave of datetime support. These
// sources have support for a dFlags that is a long (not an unsigned int) and
// it recognizes date, time and datetime fields.  It only supports dates at
// this time, because we need calcs, picture types, etc if we are to do time and
// datetime.
// 
// ** First merge of RRW7 took place here.
//
//    Rev 1.2   18 Jan 1995 17:48:02   sjo
// Made changes to remove compiler warnings.
// 
//    Rev 1.1   04 Nov 1994 17:48:02   jpb
// Slight change to comiled code for push number
// 
//    Rev 1.0   14 Oct 1993 10:16:18   sjo
// Initial revision.
// ****************************************************************************
#include "product.h"
//
// Make a definition for this module.
//
#define _PEVAL_C_

#include "rrdoc.h"
#include "mainfrm.h"
#include "rr.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "_cfcomp.h"
#include "_cfeval.h"
#include "_cfmisc.h"
#include "mffield.h"
#if !defined (RSW)
#include "mfdata.h"         // For MFDialog
#endif
#include "pic.h"
#include "util.h"

#define CKOFLO cf_PStkOflo |= xs>CfEvalStackEnd

int CRrComposite::setpargs(int acnt)
{
	int i;
	int frames=0;

	if (UFrame>=(UMAXDEPTH-1))
		return(TRUE);		/* not enough room */

	UCnts[++UFrame] = acnt; /* save argument count */
	for (i=0; i<UFrame; i++)
		frames += UCnts[i];

	if ((frames+acnt) > UMAXARGS)
	{
		UFrame--;		/* undo above increment */
		return TRUE;	/* not enough room */
	}

	for (i=acnt-1; i>=0; i--)
	{
		if (i==acnt-1)
		{ /* setting for last argument (from top of eval stack) */
			UArgs[frames+i] = xs;
		}
		else
		{ /* not last argument */
			UArgs[frames+i] = UArgs[frames+i+1]-sizeof(CFPIC);
		}
	}
	UFirstArg = &UArgs[frames];
	return FALSE;
}

void CRrComposite::pushparg(int n) /* n is argument number to push */
{
	CRrApp *pApp = (CRrApp *)AfxGetApp();
	pApp->lzmemcpy(xs,UFirstArg[n]-sizeof(CFPIC),sizeof(CFPIC));	/* "push" the entry */
	xs += sizeof(CFPIC);		/* bump ptr by pushed arg len */
}

void CRrComposite::poppargs(void)
{
	CRrApp *pApp = (CRrApp *)AfxGetApp();
	int i;
	int frames=0;
	LPSTR resdest = UFirstArg[0]-sizeof(CFPIC);

	pApp->lzmemcpy(resdest,xs-sizeof(CFPIC),sizeof(CFPIC));
	xs = resdest+sizeof(CFPIC);
	UFrame--;
	for (i=0; i<UFrame; i++)
		frames += UCnts[i];
	UFirstArg = &UArgs[frames];
}

void CRrComposite::pushpic(CFPIC *p)		/* push picture packet */
{
	CRrApp *pApp = (CRrApp *)AfxGetApp();
	if (cf_PStkOflo)
		return;
	pApp->lzmemcpy(xs,(char *)p,sizeof(CFPIC));
	xs += sizeof(CFPIC);			/* bump stack ptr */
	CKOFLO; 	/* check for stack overflow */
}

void CRrComposite::poppic(CFPIC *p) 	/* pop picture packet of pickled peppers */
{
	CRrApp *pApp = (CRrApp *)AfxGetApp();
	if (cf_PStkOflo)
		return;
	xs -= sizeof(CFPIC);			/* decrement stack ptr */
	pApp->lzmemcpy((char *)p,xs,sizeof(CFPIC));
}

void CRrComposite::pnoop(void)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	p1.pType &= ~pCONST;
	pDoc->m_pComposite->pushpic(&p1);
}

void CRrComposite::pushdpic(int y4)	/* y4 TRUE iff 4-digit year */
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p;

	p.pType = pDATE;
	p.pPic = (DPICDFLT&~(picY4|picY2))|(y4 ? picY4 : picY2);
	p.pPic2 = 0;
	p.pLen = 8;
	p.pDec=p.pInt = 0;
	p.pVal = 0.0;
	pDoc->m_pComposite->pushpic(&p);
}

void CRrComposite::pushdtpic()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p;
	
	p.pType = pDATETIME;
	p.pPic = DTPICDFLT;
	p.pPic2 = DTPIC2DFLT;
	p.pLen = 24;
	p.pDec=p.pInt = 0;
	p.pVal = 0.0;
	pDoc->m_pComposite->pushpic(&p);
}

void CRrComposite::pushtpic()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p;
	
	p.pType = pTIME;
	p.pPic = TPICDFLT;
	p.pPic2 = TPIC2DFLT;
	p.pLen = 13;
	p.pDec=p.pInt = 0;
	p.pVal = 0.0;
	pDoc->m_pComposite->pushpic(&p);
}

void CRrComposite::pushkeypic(char keyword, int keytype)
{
	CFPIC p;
	
	p.pType = pKEYWORD;
	p.pPic = 0;				// Doesnt have a picture associated with it.
	p.pPic2 = 0;
	p.pLen = p.pDec= 0;
	p.pInt=keyword;          	// keyword goes in pInt
	p.pVal = (double) keytype; // keytype goes into pVal 
	pushpic(&p);
}

void CRrComposite::pushpspic(
	int l,		// string length
	int ml,		// max length (0 if not exact)
	int pic)	// picture code
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p;
#if defined(RSW)
	int maxstr = pDoc->m_pComposite->cfmaxstrlen;
#else
	int maxstr = pDoc->m_pComposite->MFDialog ? MAXSTR : DBMAXSTR;
#endif

	p.pType = pSTR;
	p.pPic = pic;
	p.pPic2 = 0;
	p.pLen = min(maxstr,l);
	p.pMaxLen = min(maxstr,ml);
	p.pDec=p.pInt = 0;
	p.pVal = 0.0;
	pDoc->m_pComposite->pushpic(&p);
}

void CRrComposite::pushspic(
	int l,		// string length
	int ml)		// max length (0 if not exact)
{
	pushpspic(l,ml,APICDFLT);
}

void CRrComposite::pushwwspic(
	int l,		// string length
	int ml)		// max length (0 if not exact)
{
	pushpspic(l,ml,WPICDFLT);
}

void CRrComposite::pushpnpic(
		 int i,  /* integer places */
		 int d,  /* decimal places */
		 int pic)	 /* picture code */
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();	
	CFPIC p;

	p.pType = pNUM;
	p.pPic = pic;
	p.pPic2 = 0;
	if (i==0 && d==0) i=1;
	if (i+d > 19)
	{
		if (d>2) d=2;
		if (i+d > 19) i = 19-d;
	}
	p.pDec = d;
	p.pInt = i;
	p.pLen = i+d;
	p.pVal = 0.0;
	pDoc->m_pComposite->pushpic(&p);
}

void CRrComposite::pushnpic(
		 int i,  /* integer places */
		 int d)  /* decimal places */
{
	pushpnpic(i,d,NPICDFLT);
}

void CRrComposite::pushlpic(void)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();	
	CFPIC p1;

	p1.pType = pLOG;
	p1.pLen = pDoc->LogStrLen;
	p1.pPic = LPICDFLT;
	p1.pPic2 = 0;
	p1.pDec = 0;
	p1.pInt = 1;
	p1.pVal = 0.0;
	pDoc->m_pComposite->pushpic(&p1);
}

void CRrComposite::numpic(CFPIC *p)
{
	int type = p->pType&~pCONST;
	int constnt = p->pType&pCONST;

	if (type==pLOG)
	{
		p->pType = pNUM|constnt;
		p->pPic = NPICDFLT;
		p->pPic2 = 0;
		p->pLen = 1;
		p->pDec = 0;
		p->pInt = 1;
		if (p->pVal)
			p->pVal = 1.0;
	}
}

int CRrComposite::picpref(int action,int pic1,int pic2)
{
	pic1 &= 0x000F;
	pic2 &= 0x000F;
	switch (action)
	{
	case a_plus:
	case a_minus:
		if (pic1==pic2)
			break;
		if (pic1==picCURRENCY || pic2==picCURRENCY)
			pic1=picCURRENCY;
		else
			pic1 = picFIXED;
		break;

	case a_mul:
	case a_pct:
		if (pic1==pic2)
		{
			if (pic1!=picCOMMA)
				pic1 = picFIXED;
		}
		else if (pic1==picCURRENCY || pic2==picCURRENCY)
			pic1=picCURRENCY;
		else if (pic1==picCOMMA || pic2==picCOMMA)
			pic1 = picCOMMA;
		else pic1 = picFIXED;
		break;

	case a_div:
	case a_exp:
		if (pic1==pic2)
		{
			if (pic1==picCURRENCY)
				pic1 = picCOMMA;
			else
				pic1 = picFIXED;
		}
		break;

		default:
			pic1 = picFIXED;
			break;
	}
	return pic1|picNRIGHT;
}

int CRrComposite::bagit(void)
{
	switch (cf_rf->dFlags&(zfNUMERIC|zfDATE|zfLOGICAL|zfMEMO|zfDATETIME|zfTIME))
	{
	case zfNUMERIC:
		cf_rf->dFldPic = NPICDFLT;
		cf_rf->dLength = 1;
		break;

	case zfDATE:
		cf_rf->dFldPic = DPICDFLT;
		cf_rf->dLength = 8;
		break;
			
	case zfDATETIME:
		cf_rf->dFldPic = DTPICDFLT;
		cf_rf->dFldPic2= DTPIC2DFLT;
		cf_rf->dLength = 24;
		break;
			
	case zfTIME:
		cf_rf->dFldPic = TPICDFLT;
		cf_rf->dFldPic2= TPIC2DFLT;
		cf_rf->dLength = 13;
		break;

	case zfLOGICAL:
		cf_rf->dFldPic = LPICDFLT;
		cf_rf->dLength = m_pDoc->LogStrLen;
		break;

	case zfMEMO:
		cf_rf->dFldPic = WPICDFLT;
		cf_rf->dLength = FLMAX;
		break;

	default:
		cf_rf->dFldPic = APICDFLT;
		cf_rf->dLength = FLMAX;
		break;
	}

	cf_rf->dDecPl = 0;
	SETML(cf_rf,0);
	return FALSE;
}

int CRrComposite::lpeval(LPSTR in, LPMFFIELD resfld)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1,p2;
	LPMFFIELD fld;
	char fmt[20];
	char num[40];
	unsigned long f;
	LPSTR p;
	LPSTR s;
	int dots,i,d,action;
	int udepth = 0;
	LPUDF u;
	int bUnwinding = FALSE;
#if defined(RSW)
	int maxfld = cfmaxstrlen;
#else
	unsigned int maxfld = MFDialog ? MAXFLDBUF : DBMAXFLDBUF;
#endif

	cf_rf = resfld;					/* for bagit() */
	if (in==NULL)
		return FALSE; 	/* need compiled code! */
#ifndef RSW
	if (getstack())
		return bagit();
#endif
#if defined(RSW)
	if (resfld->dFlags2&f2SQLENG)
		return FALSE;
#endif
	xcp = in;
	xs = CfEvalStack;
	cf_PStkOflo=Boolean = FALSE;

	while (TRUE)
	{
		NextBoole = FALSE;	/* assume operation will be arithmetic */
		switch (action=*(xcp++))
		{
		case a_plus:
		case a_minus:
			poppic(&p2);
			numpic(&p2);
			poppic(&p1);
			numpic(&p1);
			i = max(p1.pInt,p2.pInt)+(action==a_plus ? 1 : 0);
			d = max(p1.pDec,p2.pDec);
			pushpnpic(i,d,picpref(action,p1.pPic,p2.pPic));
			break;

		case a_exp:
		case a_div:
			poppic(&p2);
			numpic(&p2);
			poppic(&p1);
			numpic(&p1);
			pushpnpic(p1.pInt,p1.pDec,picpref(action,p1.pPic,p2.pPic));
			break;

		case a_mul:
		case a_pct:
			poppic(&p2);
			numpic(&p2);
			poppic(&p1);
			numpic(&p1);
			i = p1.pInt+p2.pInt;
			if (p1.pDec==2 || p2.pDec==2)
				d = 2;
			else
				d = max(p1.pDec,p2.pDec);
			pushpnpic(i,d,picpref(a_mul,p1.pPic,p2.pPic));
			break;

		case a_uminus:
		case a_uplus:
			poppic(&p1);
			numpic(&p1);
			if ((action==a_uminus) && (p1.pType&pCONST))
			{
				p1.pVal = -p1.pVal;
				if (p1.pVal<0.0)
				{
					p1.pInt++;
					p1.pLen++;
				}
			}
			pushpic(&p1);
			break;

		case a_ret:
			if (udepth)
			{
				xcp = UStack[--udepth];
				if (!bUnwinding)
					poppargs();
				break;
			}
			bUnwinding = FALSE;
			poppic(&p1);
			resfld->dFldPic = p1.pPic;
			// The next line's check fixes RRW 2963, don't set to default unless out of range.
			// fixes the reset to default values on compile at file open and is ok for new calc fields
			// because resfld->dFldPic2 is already set with a good value.
			if(resfld->dFldPic2 < 0 || resfld->dFldPic2 > pic2WTI)
				resfld->dFldPic2= p1.pPic2;
#if defined (PACE) // for calcfld=pacefld
			switch (resfld->dFlags&(zfNUMERIC|zfDATE|zfLOGICAL|zfMEMO))
			{
			 case zfNUMERIC:
				if (NUMPIC(resfld)==picNPACE)
					resfld->dFldPic = NPICDFLT;
			 break;

			 case zfDATE:
				if (DATEPIC(resfld)==picDPACE)
					resfld->dFldPic = DPICDFLT;
			 break;

			 case 0:
				if (CHARPIC(resfld)==picAPACE)
					resfld->dFldPic = APICDFLT;
			 break;
			}
#endif
			resfld->dDecPl = p1.pDec;
			resfld->dLength = p1.pLen==0 ? 1 :
				p1.pLen>FLMAX ? FLMAX : p1.pLen;
#if defined RSW
		if (((resfld->dFldP != NULL) || (resfld->dTemp.tempP != NULL)) &&
			(p1.pMaxLen != GETML(resfld)))
		{ // we've got buffers from a prior print
		  // and buffer size has changed - force realloc
			if (resfld->dFldP != NULL)
				m_pDoc->globalFree(resfld->dFldP);
			if (resfld->dTemp.tempP != NULL)
				m_pDoc->globalFree(resfld->dTemp.tempP);
			resfld->dFldP = NULL;
			resfld->dTemp.tempP = NULL;
		}
#endif
			SETML(resfld,p1.pMaxLen);
#ifndef RSW
			rlsstack();
#endif
			return cf_PStkOflo ? bagit() : FALSE;
			break;

		case a_num:
			p1.pType = pNUM|pCONST;
			p1.pPic = NPICDFLT;
			p1.pPic2 = 0;
			// following the a_num opcode is the number of decimal
			// digits plus 1 for the decimal point.  This will be
			// used by xeval to decide whether to include decimal point
			// in translated formula.  For p1.p.Dec, we just want the
			// number of decimal digits, so if it is nonzero, we
			// subtract 1.
			p1.pDec = *(xcp++);
			if (p1.pDec)
				p1.pDec--;
			p1.pVal = *(double *)xcp;
			xcp += sizeof(double);
			sprintf(fmt,"%%0.%dlf",p1.pDec);
			if (p1.pVal >= 1.0e20)
				p1.pInt = 20;
			else
			{
				sprintf(num,fmt,p1.pVal);
				s = num;
				if (*s=='-')
					s++;   /* start looking at first digit after sign */
				while (*s=='0')
					s++;    /* skip leading zeros */
				p = lstrchr(s,CDOT);		/* look for dec pt */
				p1.pInt = p==NULL ? lstrlen(s) : p-s;	/* integer places */
				if (p1.pInt==0 && p1.pDec==0)
					p1.pInt = 1;
				if (*num=='-') p1.pInt++;   /* count position for sign */
			}
			if (p1.pInt+p1.pDec > 19)
			{
				if (p1.pDec>2)
					p1.pDec=2;
				if (p1.pInt+p1.pDec > 19)
					p1.pInt = 19-p1.pDec;
			}
			p1.pLen = p1.pInt+p1.pDec;
			pushpic(&p1);
			break;

		case a_date:
			pushdpic(FALSE); /* 2 digit year */
			xcp += sizeof(long);
			break;

		case a_datetime:
			pushdtpic();
			xcp += sizeof(ZDATETIME);
			break;
				
		case a_time:
           pushtpic();
           xcp += sizeof(double);
           break;
            
        case a_keyword:
		// The keyword entry is made up of two things in the compile buffer.
       	pushkeypic(*xcp, *(xcp+1));
       	xcp += 2;
       	break;
         	
		case a_ufparg:
		case a_ufarg:
			if (cf_PStkOflo)
				break;
			pushparg(*(FLDID *)xcp);
			xcp+=sizeof(FLDID);				// Looks OK for 32 bits
			CKOFLO;
			break;

		case a_pfld:
		case a_fld:
			if (cf_PStkOflo) break;
			fld=mfbyndx(*(FLDID *)xcp);
			/* add len of field num */
			xcp += sizeof(FLDID); 	  		// Looks OK for 32 bits
			f = fld->dFlags&(zfNUMERIC|zfDATE|zfLOGICAL|zfDATETIME|zfTIME);
			p1.pType = f==zfNUMERIC ? pNUM :
					f==zfDATE ? pDATE :
					f==zfLOGICAL ? pLOG : 
				 	f==zfDATETIME ? pDATETIME :
			 		f==zfTIME ? pTIME : pSTR;

			if ((p1.pType==pSTR) && (fld->dFlags&zfCALCULATED))
				p1.pMaxLen = GETML(fld);
			else if (!(fld->dFlags&zfNOTinREC))
			{
#ifdef RSW
				p1.pMaxLen = (unsigned int)min((long)fld->engS.dDataLen,cfmaxstrlen);
#else
				int len = fld->dRecU.fileS.dDataLen>maxfld ?
							maxfld : fld->dRecU.fileS.dDataLen;
				p1.pMaxLen = len;
#endif
			}
			else p1.pMaxLen = 0;

			p1.pPic = fld->dFldPic;
			p1.pPic2= fld->dFldPic2;
			p1.pLen = fld->dLength;
			p1.pDec = fld->dDecPl;
			p1.pInt = f==zfNUMERIC ? fld->dLength - fld->dDecPl : 0;
			if (p1.pInt==0 && p1.pDec==0)
				p1.pInt = 1;
			p1.pVal = 0.0;
			pushpic(&p1);
			CKOFLO; 	/* check for stack overflow */
			break;

		case a_file:
			if (cf_PStkOflo)
				break;
			p1.pVal = (double)(*(int *)xcp);    // Looks OK for 32 bits
			/* add len of file num */
			xcp += sizeof(int); 	 			// Looks OK for 32 bits
			p1.pType = pFILE;
			p1.pLen = 8;
			p1.pPic = 0;
			p1.pPic2 = 0;
			p1.pDec=p1.pInt = 0;
			pushpic(&p1);
			CKOFLO; 	/* check for stack overflow */
			break;

		case a_argsep:	  /* a no-op */
			break;

		case a_func:
		case a_ufunc:
			i = *(int *)xcp;		// OK for 32 bits
			NextBoole = i&0x8000;	/* hi bit flags some logical results */
			i &= 0x7FFF;			/* = ~0x8000 */
			/* add len of func num */
			xcp += sizeof(int); 	 		// Looks OK for 32 bits
			args = (int)*(xcp++);	/* the number of arguments */
			if (action==a_func)
			{
				NextBoole = functab[i].fType&LOGICAL;
				if ((i > maxfunc) || (functab[i].pfunc==NULL))
				{
#ifndef RSW
					rlsstack();
#endif
					return bagit(); /* out of range */
				}
				(*functab[i].pfunc)();
			}
			else
			{
				for (u=UDFS; u; u=u->uNext)
					if (i==u->uFuncNo)
						break;
					if (!u) 				/* no such udf number */
					{
#ifndef RSW
						rlsstack();
#endif
						return bagit(); /* out of range */
					}
				if ((udepth<UMAXDEPTH) && !setpargs(args) && !bUnwinding)
				{ /* room in UStack and UArgs */
					if (u->uExpE)
					{
						UStack[udepth++] = xcp;
						xcp = u->uExpE;
					}
					else
					{	/* if no compiled code, just push result */
						switch (u->uType)
						{
						case sv_date:
							pushdpic(FALSE); /* 2 digit year */
							break;
						case sv_datetime:
							pushdtpic();
							break;
						case sv_time:
							pushtpic();
							break;
						case sv_dbl:
							pushnpic(6,0);
							break;
						case sv_dbl|LOGICAL:
							p1.pType = pLOG|pCONST;
							p1.pLen = m_pDoc->LogStrLen;
							p1.pPic = LPICDFLT;
							p1.pPic2 = 0;
							p1.pDec = 0;
							p1.pInt = 1;
							p1.pVal = action==a_true ? 1.0 : 0.0;
							pushpic(&p1);
							NextBoole = TRUE;
							break;
						default:
							pushspic(10,0);
							break;
						}
					}
				}
				else
				{
					bUnwinding = TRUE;
					UFrame = -1;
					xs -= args*sizeof(CFPIC); /* bag arguments */
					switch (u->uType&(~LOGICAL))
					{
					case sv_dbl:
						pushnpic(1,0);
						break;

					case sv_str:
						pushspic(1,0);
						break;

					case sv_date:
						pushdpic(FALSE);
						break;

					case sv_datetime:
						pushdtpic();
						break;

					case sv_time:
						pushtpic();
						break;
					}
				}
			}
			break;

		case a_eq:
		case a_neq:
		case a_le:
		case a_ge:
		case a_lt:
		case a_gt:
		case a_and:
		case a_or:
		case a_subst:
			poppic(&p2);
		case a_not:
			poppic(&p1);
			pushlpic();
			NextBoole = TRUE;
			break;

		case a_true:
		case a_false:
			p1.pType = pLOG|pCONST;
			p1.pLen = m_pDoc->LogStrLen;
			p1.pPic = LPICDFLT;
			p1.pPic2 = 0;
			p1.pDec = 0;
			p1.pInt = 1;
			p1.pVal = action==a_true ? 1.0 : 0.0;
			pushpic(&p1);
			NextBoole = TRUE;
			break;

		case a_cat:
		case a_tcat:
			poppic(&p2);
			poppic(&p1);
			pushspic(p1.pLen+p2.pLen,
				p1.pMaxLen && p2.pMaxLen ? p1.pMaxLen+p2.pMaxLen : 0);
			break;

		case a_str:
			p1.pType = pSTR|pCONST;
			p1.pMaxLen=p1.pLen = max((*(int *)xcp)-1,1);
			p1.pPic = APICDFLT;
			p1.pPic2 = 0;
			p1.pDec=p1.pInt = 0;
			p=ltrimleft(xcp+sizeof(int)); 		// OK for 32 bits
			if (*p=='-')
			{
				p++;
				p1.pInt++;
			}
			dots = 0;
			if (p)
			{
				char cbuf[100];

				while (*p)
				{
					if (*p==CDOT)
					{
						if (dots++)
							break;	/* second dec pt, end of number scan */
					}
					else if (*p<'0' || *p>'9')
						break; /* non digit ends it too */
					else if (dots)
						p1.pDec++; /* counting decimal places */
					else p1.pInt++; /* counting integer places */
					p++;
				}
				lstrncpy(cbuf,xcp+sizeof(int),100);			// OK for 32 bits
				cbuf[99] = 0;
				p1.pVal = atof(cbuf);
				if (!p1.pInt)
					p1.pInt++;
			}
			else p1.pVal = 0.0;
			pushpic(&p1);
			xcp += (*(int *)xcp)+sizeof(int); 			// OK for 32 bits
			break;

		case a_noarg:
			p1.pType = pNONE;
			p1.pLen = 0;
			p1.pPic = 0;
			p1.pPic2= 0;
			p1.pDec=p1.pInt = 0;
			p1.pVal = 0.0;
			pushpic(&p1);
			break;

		case a_datedif:
			poppic(&p2);
			poppic(&p1);
			pushnpic(3,0);
			break;

		case a_plusdays:
		case a_subdays:
			poppic(&p2);
			poppic(&p1);
			pushpic(p1.pType==pDATE ? &p1 : p1.pType==pDATETIME ? &p1 : &p2);
			break;

		case a_mtmemo:
			if (cf_PStkOflo)
				break;
			p1.pType = pSTR;
			p1.pMaxLen = 1;
			p1.pPic = WPICDFLT;
			p1.pPic2 = 0;
			p1.pLen = 1;
			p1.pDec = 0;
			p1.pInt = 1;
			p1.pVal = 0.0;
			pushpic(&p1);
			CKOFLO; 	/* check for stack overflow */
			break;

		case a_bfalse:
		case a_branch:
			xcp += sizeof(long);
			break;
		default:
#ifndef RSW
			rlsstack();
#endif
			return bagit(); /* unrecognized opcode */
			break;
		}
		Boolean = NextBoole;
	}
}

int CRrComposite::lbufeval(LPSTR in, LPMFFIELD resfld)
{
	int savpic = resfld->dFldPic;
	UONE savdec = resfld->dDecPl;
	UONE savlen = resfld->dLength;
	int ret = lpeval(in,resfld);

	resfld->dFldPic = savpic;
	resfld->dDecPl = savdec;
	resfld->dLength = savlen;
	return ret;
}


