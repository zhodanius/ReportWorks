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
// pdate.c		date function picture routines
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/cfcomp/pdate.cpv  $
// 
//    Rev 1.9   30 Nov 1998 13:54:30   wrr
// Added 134154
// 
//    Rev 1.8   20 Mar 1996 10:42:38   sjo
// Fix for RRW 2739.  Also happens in RSW.
// 
//    Rev 1.7   19 Sep 1995 10:47:34   jpb
// error cleanup
// 
//    Rev 1.6   18 Sep 1995 15:00:30   jpb
// move funcs to CRrComposite
// 
//    Rev 1.5   02 Aug 1995 10:01:22   sjo
// I needed to move the include of the class headers from just after the include
// of product.h, to just after the #define of the module name.
// 
//    Rev 1.4   31 Jul 1995 15:45:16   pjm
// Change zMaxDow and zMaxMon to u_ versions to fix conflict.
// 
//    Rev 1.3   20 Jul 1995 16:41:44   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.2   03 May 1995 09:44:42   sjo
// Fixed some problems with new time calcs.
// 
//    Rev 1.1   27 Apr 1995 12:35:48   sjo
// Merge of 6.1.03+.  I say + because I have added some of the time functions
// to this merge, which will be a part of 6.1.04.  I merged the CF directories
// and some H files (for the time function changes).
// 
//    Rev 1.0   16 Mar 1995 16:22:16   sbc
// Initial revision.
// 
//    Rev 1.6   06 Apr 1995 19:15:20   sjo
// Fixes as a result of date investigation of the cf directories.
// 
//    Rev 1.5   03 Apr 1995 15:36:46   pjm
// Added support for dtlookup().
// 
//    Rev 1.4   27 Mar 1995 19:38:24   sjo
// Added support for DTEADD and other DT functions.
// 
//    Rev 1.3   23 Mar 1995 17:01:28   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
// ** First merge of RRW7 took place here.
//
//    Rev 1.2   18 Jan 1995 17:47:46   sjo
// Made changes to remove compiler warnings.
// 
//    Rev 1.1   16 Jun 1994 10:02:54   vff
// Merged RR6 functions into R?W 6.0
// 
//    Rev 1.0   14 Oct 1993 10:16:16   sjo
// Initial revision.
// ****************************************************************************
#include "product.h"

//
// Make a definition for this module.
//
#define _PDATE_C_

#include "rr.h"
#include "rrdoc.h"
#include "mainfrm.h"
#include "ctype.h"
#include "_cfcomp.h"
#include "wutil.h"

/* some maximum string lengths */
#define LENDATE 10 /* dd/mm/yyyy */

#define LENTIME 8 /* mm:hh:ss */

/* pdate() used for DATE and CTOD */
void CRrComposite::pdate()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushdpic(FALSE); /* 2 digit year */
}

/* CDOW */
void CRrComposite::pcdow()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CRrApp *pApp = (CRrApp *)AfxGetApp();
	CFPIC p1;
	char c;

	pDoc->m_pComposite->poppic(&p1);
	c = *(getString(pApp->u_zMaxDow,0));
	pDoc->m_pComposite->pushspic(c,c);
}

/* CMON */
void CRrComposite::pcmon()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CRrApp *pApp = (CRrApp *)AfxGetApp();
	CFPIC p1;
	char c;

	pDoc->m_pComposite->poppic(&p1);
	c = *(getString(pApp->u_zMaxMon,0));
	pDoc->m_pComposite->pushspic(c,c);
}

/* for DAY and MONTH */
void CRrComposite::pday()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(2,0); /* 2 digit day of month */
}

/* for DOW, WEEK, and QTR */
void CRrComposite::pdow()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(1,0); /* 1 digit day of week */
}

/* DTOC */
void CRrComposite::pdtoc()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushspic(LENDATE,LENDATE);
}

/* YEAR */
void CRrComposite::pyear()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(4,0); /* 4 digit year number */
}

/* TIME */
void CRrComposite::ptime()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushspic(LENTIME,LENTIME);
}

/* All date aritmetic yielding date result (add/sub days,mons,...) */
void CRrComposite::pdarith()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);	/* leave the date argument */
}

/* PAST, FUTURE, OVER */
void CRrComposite::ppast()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1, p2;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->pushlpic();
}

/* AGED */
void CRrComposite::paged()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1, p2, p3;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->poppic(&p3);
	pDoc->m_pComposite->pushlpic();
}

/* HDOW, PDOW */
void CRrComposite::pndow()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1, p2;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->pushdpic(FALSE); /* 2 digit year */
}

/* all date differences (days, weeks, ..., between) */
void CRrComposite::pddiff()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1,p2;

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->pushnpic(3,0);	/* our standard counter */
//  pushnpic(3,0);	/* our standard counter */
}

void CRrComposite::pdatediff()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1, p2,p3;  
	int keytype, keyvalue;
		
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p2);
	pDoc->m_pComposite->poppic(&p3);
	keyvalue=(int)p3.pVal;
	keytype=(int)p3.pInt; 
	
	pDoc->m_pComposite->pushnpic(3,0);	/* our standard counter */
	return;
}

void CRrComposite::pdateadd()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1, p2, p3;  
	int keytype, keyvalue;
		
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p2);   
	pDoc->m_pComposite->poppic(&p3);
	keyvalue=(int)p3.pVal;
	keytype=(int)p3.pInt;
	
	switch (keyvalue)
	{
		case KYEAR:		// A dteadd of a date interval results in either a date or a datetime,
		case KQUARTER:	//  depending on the picture type of the p1.
		case KMONTH:
		case KDAYOFYEAR:
		case KDAY:
		case KWEEKDAY:
		case KWEEK:
			// If are adding a 'date-type interval' and we have a time,
			//  push the default dt pic.  Otherwise, push the pic.
			if (p1.pType==pTIME)
         		pDoc->m_pComposite->pushdtpic();
         else
				pDoc->m_pComposite->pushpic(&p1);
         break;

		case KHOUR:
		case KMINUTE:
		case KSECOND:
 			if (p1.pType==pDATE)
 				pDoc->m_pComposite->pushdtpic();
 			else
 				pDoc->m_pComposite->pushpic(&p1);
			break;
		
	} // end switch
	return;
} 

void CRrComposite::pdatepart()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1, p2;  
	int keytype, keyvalue,places;
		
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->poppic(&p2);
	keyvalue=(int)p2.pVal;
	keytype=(int)p2.pInt;
	switch (keyvalue)
	{
		case KYEAR:
         places=4;	/* 4 digits for year */
			break;
			
		case KQUARTER:
			places=1;
			break;
			
		case KMONTH:
         places=2;	/* 2 places for month */
			break;
		
		case KDAYOFYEAR:
			places=3;
			break;
		
		case KDAY:
         places=2;
			break;
			
		case KWEEKDAY:
         places=1;
			break;
		
		case KWEEK:
			places=2;
			break;
			
		case KHOUR:
         places=2;
			break;
			
		case KMINUTE:
			places=2;
			break;
			
		case KSECOND:
         places=2;
			break;
		
	} // end switch	
	
	pDoc->m_pComposite->pushnpic(places,0);
	return;
} 

void CRrComposite::ptodate()
{ 
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;  
		
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushdpic(FALSE); /* 2 digit year */
	return;
}
void CRrComposite::ptotime()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;  

	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushtpic();
	return;
}
void CRrComposite::pdttoc()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;  
		
	pDoc->m_pComposite->poppic(&p1);		// Add in separator,  AM
  	pDoc->m_pComposite->pushspic(LENDATE+LENTIME+5, LENDATE+LENTIME+5);
  	return;
}
void CRrComposite::pttoc()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;  
		
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushspic(LENTIME+4,LENTIME+4);
	return;
}

void CRrComposite::pdtlookup()	// for datetime flavor of lookup()
{ /* pop the 5 arguments */
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;

	pDoc->m_pComposite->poppic(&p1);	// optional tag 
	pDoc->m_pComposite->poppic(&p1);	// optional index
	pDoc->m_pComposite->poppic(&p1);	// related database
	pDoc->m_pComposite->poppic(&p1);	// target field
	pDoc->m_pComposite->poppic(&p1);	// lookup value
  	pDoc->m_pComposite->pushdtpic();
	return;
}

void CRrComposite::pttos()		// TTOS 	- time to seconds (dbl)
{ 
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;
	
	// pop time string
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(6,0);
	return;	
}
// Also used for NOW function
void CRrComposite::pctdt()		// CTDT	- character to datetime
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;
	
	// pop datetime string
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushdtpic();
	return;
}

void CRrComposite::pctos()		// CTOS	- character to seconds (dbl)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;
	
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushnpic(6,0);
	return;
}

void CRrComposite::pctot()		// CTOT 	- character to time
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;
	
	pDoc->m_pComposite->poppic(&p1);
	pDoc->m_pComposite->pushtpic();
	return;
}

void CRrComposite::pstoc()		// STOC	- seconds (dbl) to character string
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CRrDoc *pDoc = (CRrDoc *)pFrame->GetActiveDocument();
	CFPIC p1;
	int keyvalue, keytype;
	int LengthOfResult;
	
	pDoc->m_pComposite->poppic(&p1);
	keyvalue=(int)p1.pVal;
	keytype=(int)p1.pInt;
	
	switch (keyvalue)
	{
		case KHH:
         LengthOfResult=2;		// 0-99 for hours.
			break;			
		case KMM:
			LengthOfResult=4;
			break;
		case KSS:
			LengthOfResult=6;
			break;
		case KHHMM:
         LengthOfResult=5;		// 0-99 for hours.
         break;
		case KHHMMSS:
         LengthOfResult=8;		// 0-99 for hours.
			break;
		case KMMSS:
         LengthOfResult=5;		// 0-99 for hours.
			break;
	}
  	pDoc->m_pComposite->pushspic(LengthOfResult,16);
  	return;	
}

