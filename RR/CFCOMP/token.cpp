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
// Tokenizer for input calc expression string. Called by lcfcomp()(, others?)
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/cfcomp/token.cpv  $
// 
//    Rev 1.13   19 Feb 1997 14:40:08   dlm
// Part of fix to RRW 2991/RSW 2386 to allow specification via SPACEDOT
//  setting in .SRT file of override for hard-space character.  Changed much
//  code to use new SpaceDot variable instead of zdSPC or ANSI_DOT.  Changed
//  most export/printer DLLs to use a new internal SpaceDot function instead
//  of exported pwSpaceDot.  Change EXEs to use new CRrDoc::SpaceDot function
//  instead of using exported pwSpaceDot functions of DLLs.  Modules changed
//  are: explt.cpp, token.cpp, fstr.cpp, trim.cpp, pksx.cpp, sxmisc.cpp,
//  mfgetmch.cpp, mfsql.cpp, htmlexp.cpp, pwint.cpp, pxdriver.cpp, pxint.cpp,
//  rtfexp.cpp, wexpdriv.cpp, wexpint.cpp, pwdriver.cpp, picdata.cpp,
//  picshape.cpp, prec.cpp, rpwrap.cpp, rprint.cpp, gropts.cpp, grfield.cpp,
//  rpwritex.cpp, grmisc.cpp, rrcompos.cpp, rrdoc.cpp, rrrepio.cpp,
//  specfld1.cpp, specfld2.cpp, specquer.cpp, wedtx.cpp, edittext.cpp,
//  wfont.cpp, readsrt.cpp, wprint.cpp, wtxtexp.cpp, winst.cpp, wstring.cpp,
//  global.h, pd.h, rrcompos.h, rrdoc.h, rrrepio.h, _pd.h, _rtexp.h
// 
//    Rev 1.12   26 Sep 1995 13:57:52   jpb
// fix tokenizing of string literals
// 
//    Rev 1.11   22 Sep 1995 17:02:24   sjo
// Second round of FLDID changes.
// 
//    Rev 1.10   19 Sep 1995 17:56:48   sjo
// Changes made by looking at references to sizeof(int) in all sources for 32
// bit support.
// 
//    Rev 1.9   18 Sep 1995 15:00:40   jpb
// move funcs to CRrComposite
// 
//    Rev 1.8   14 Sep 1995 14:55:54   sjo
// Changes for 32 bit support, mostly for pawing thru compiled code.
// 
//    Rev 1.7   11 Sep 1995 11:12:40   sjo
// 32-bit changes.
// 
//    Rev 1.6   29 Aug 1995 16:01:52   sjo
// Fixed GPF in paralogic.
// 
//    Rev 1.5   18 Aug 1995 14:54:16   mjs
// Added global.h
// 
//    Rev 1.4   02 Aug 1995 10:01:32   sjo
// I needed to move the include of the class headers from just after the include
// of product.h, to just after the #define of the module name.
// 
//    Rev 1.3   31 Jul 1995 13:51:28   sjo
// Another round of recompiling.
// 
//    Rev 1.2   20 Jul 1995 16:41:54   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.1   27 Apr 1995 12:35:54   sjo
// Merge of 6.1.03+.  I say + because I have added some of the time functions
// to this merge, which will be a part of 6.1.04.  I merged the CF directories
// and some H files (for the time function changes).
// 
//    Rev 1.0   16 Mar 1995 16:22:24   sbc
// Initial revision.
// 
//    Rev 1.3   06 Apr 1995 19:15:08   sjo
// Fixes as a result of date investigation of the cf directories.
// 
//    Rev 1.2   29 Mar 1995 12:10:40   jpb
// support datetime/time literals
// 
//    Rev 1.1   23 Mar 1995 17:01:36   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
// ** First merge to 7.0 took place here
// 
//    Rev 1.0   14 Oct 1993 10:16:22   sjo
// Initial revision.
// ****************************************************************************
#include "product.h"
//
// Make a definition for this module.
//
#define _TOKEN_C_

#include "rrdoc.h"
#include "rr.h"
#include "global.h"	// For TokCh, TokCh2

#include "cfedit.h"	// for lpszTPTRUE, etc.
#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "util.h"
#include "_cfcomp.h"
#include "_cfmisc.h"
#if !defined (RSW)
#include "mfdata.h"         // for MFDialog
#endif
#include "pd.h"         // for zdSPC

#define TANDSTR lpszTAND
#define TORSTR lpszTOR
#define TNOTSTR lpszTNOT
#define TTRUESTR lpszTTRUE
#define TFALSESTR lpszTFALSE

#define NULLCH 0

typedef struct keyWord
{
	char 		  *tokstr;  	// The string values that are the keywords
	int			kval;		// The value of those keywords (1, 2, etc.)
} KEYWORD;

typedef struct logies
{
	LPSTR 	*lstr;
	int 	lval;
} LOGIES;

int CRrComposite::paralogic(char *s)
{
	int i;
//	LPSTR lp;
	LOGIES plog[] =
	{
		&lpszTPTRUE,	  t_true,
		&lpszTPYES, t_true,
		&lpszTPON,  t_true,
		&lpszTPFALSE,t_false,
		&lpszTPNO,  t_false,
		&lpszTPOFF, t_false,
		&lpszTPAND, t_and,
		&lpszTPOR,  t_or,
		&lpszTPNOT, t_not,
		NULL
	};

	for (i=0;
			plog[i].lstr;
			i++)
	{
		if (!lstrcmp(s,*plog[i].lstr)) return plog[i].lval;
	}
	return 0;
}

/* For now, this routine will check for datetime interval
	keywords.  It could be expanded to look for any of a list
	of keywords. The valP structure could return the integer value
	that we substitute for the keyword, as well as a flag indicating
	which class of keyword was found.
*/
int CRrComposite::keywords(char *s, int *kstype, int *kctype)
{
   int i;
   char *lp;
	KEYWORD timePictures[] =
	{
		"HH",   		KHH,
		"MM",       KMM,
		"SS",       KSS,
		"HH:MM",    KHHMM,
		"HH:MM:SS", KHHMMSS,
		"MM:SS",    KMMSS,
		NULL, 		0
	};

	KEYWORD dateIntervals[] =
	{
		"YYYY", 		KYEAR,
		"Q",			KQUARTER,
		"M",			KMONTH,
		"Y",			KDAYOFYEAR,
		"D",			KDAY,
		"W",			KWEEKDAY,
		"WW",			KWEEK,
		"YEAR",		KYEAR,
		"QUARTER",	KQUARTER,
		"MONTH",		KMONTH,
		"DAYOFYEAR",KDAYOFYEAR,
		"DAY",		KDAY,
		"WEEKDAY",	KWEEKDAY,
		"WEEK",		KWEEK,
		NULL,		0
	};

	KEYWORD timeIntervals[] =
	{
		"H",			KHOUR,
		"N",			KMINUTE,
		"S",			KSECOND,
		"HOURS",		KHOUR,
		"MINUTES",	KMINUTE,
		"SECONDS",	KSECOND,
		NULL, 	0
	};
   
   for (i=0; lp=dateIntervals[i].tokstr;i++)
	{
		if (!lstrcmp(s,lp)) 
		{
			*kstype=t_dateinterval;
			*kctype=sv_dateinterval;			
			return dateIntervals[i].kval;
		}
	}
   for (i=0; lp=timeIntervals[i].tokstr;i++)
	{
		if (!lstrcmp(s,lp)) 
		{
			*kstype=t_timeinterval;
			*kctype=sv_timeinterval;			
			return timeIntervals[i].kval;
		}
	}                             
   for (i=0; lp=timePictures[i].tokstr;i++)
	{
		if (!lstrcmp(s,lp)) 
		{
			*kstype=t_timepicture;
			*kctype=sv_timepicture;			
			return timePictures[i].kval;
		}
	}     
	
	return 0;
}

LPSTR CRrComposite::lnexttok(LPSTR cp,LPSTR tok)
{
	char c;

	while (c=*cp)
	{
		if (c=='\\')
		{ /* the escape character */
			*(tok++) = (c=*(++cp)); 	/* pass next one through */
			if (!c) return cp;			/* next was NULL */
			cp++;						/* bump past passed one */
		}
		else if (strchr(TokCh2,c))
		{ /* matches token delimiter */
			break;
		}
		else
		{ /* not escape, not delimiter */
			*(tok++) = c;				/* just pass it through */
			cp++;
		}
	}
	*tok = '\0';
	return cp;
}

int CRrComposite::badudf(int n)
{
	LPUDF u;

	for (u=UDFS; u; u=u->uNext) if (u->uFuncNo==n) break;
	return (u->uExpE==NULL);
}

int CRrComposite::ltoken(
		LPSTR  *sP, 	/* address of pointer to string */
		TOKVAL *valP,		/* value if token is num, func, fld, or str */
		int *lenP,			/* length of passed *valP data */
		int qfn)			/* TRUE => qualify fieldnames as required, and
							   bump *sP past bad token when returning t_err
					*/
{
	CRrApp *pApp = (CRrApp *)AfxGetApp();
	LPSTR cp = *sP;
	LPSTR p;
	char *p2;
	char ch;
	int code,funcfirst;
	char tok[TOKLEN];
	int keytype,ckeytype;
#if defined(RSW)
	int maxstr = cfmaxstrlen;
#else
	int maxstr = MFDialog ? MAXSTR : DBMAXSTR;
#endif
	/* token array (in synch with TokCh[], in TFUNCTAB.ASM) */
	char tk[] =
	{
		t_plus,t_minus,t_div,t_mul,t_exp,t_pct,t_lp,t_rp,
		t_comma,t_eq,t_neq,t_lt,t_gt,t_subst,0,0,0,0,0,NULLCH
	};


	if (*cp == '\0') return t_eox;

	*lenP = 0;			/* no value with most tokens */
	if (p=lstrchr(TokCh,*cp))
	{ /* string starts with character from TokCh[] */
		cp++;	/* bump running pointer for update on return */
		if (((code=tk[p-(LPSTR )TokCh]) == t_mul) && (*cp == *p))
		{ /* string starts with "**" */
			cp++;	/* bump again */
			code = t_exp;	/* turn ** into ^ */
		}
		else if (code==t_lt)
		{ /* string starts with "<" */
			if (*cp==CGT)
			{ /* <> */
				cp++;
				code = t_neq;
			}
			else if (*cp==CEQ)
			{ /* <= */
				cp++;
				code = t_le;
			}
		}
		else if (code==t_gt)
		{ /* string starts with ">" */
			if (*cp==CEQ)
			{ /* >= */
				cp++;
				code = t_ge;
			}
		}
		else if (*p==CDOTREP)
		{ /* string starts with "!" */
			if ((!pApp->zfncmp(cp,&TANDSTR[1],LAND,TRUE,FALSE)) && (cp[LAND]=='!'))
			{
				cp += LAND+1;
				code = t_and;
			}
			else if ((!pApp->zfncmp(cp,&TORSTR[1],LOR,TRUE,FALSE)) && (cp[LOR]=='!'))
			{
				cp += LOR+1;
				code = t_or;
			}
			else if ((!pApp->zfncmp(cp,&TNOTSTR[1],LNOT,TRUE,FALSE)) && (cp[LNOT]=='!'))
			{
				cp += LNOT+1;
				code = t_not;
			}
			else if ((!pApp->zfncmp(cp,&TTRUESTR[1],LTRUE,TRUE,FALSE)) && (cp[LTRUE]=='!'))
			{
				cp += LTRUE+1;
				code = t_true;
			}
			else if ((!pApp->zfncmp(cp,&TFALSESTR[1],LFALSE,TRUE,FALSE)) && (cp[LFALSE]=='!'))
			{
				cp += LFALSE+1;
				code = t_false;
			}
			else
			{
				*sP = --cp;
				return t_err;
			}
		}
		else if (*p==CLBRACE)
		{ /* string starts with "{" */
			if (p=lstrchr(cp,CRBRACE))
			{ /* found matching "}" */
				int slen = p-cp;
				int trunclen = slen;
				double time;
				long date;

				// Need to identify date/time/datetime constants here.
				if (trunclen>maxstr) trunclen = maxstr;

				pApp->lzmemcpy(tok,cp,trunclen);	/* move the date string */
				tok[trunclen] = '\0';       /* terminate it */
				cp += slen+1;	/* use slen, not trunclen! */

				switch (parseDateTime(tok, &time, &date))
				{
				  case PDT_DATEONLY:
					valP->tDate = date;
					*lenP = sizeof(valP->tDate);
					code = t_date;
			  	  break;

				  case PDT_DATETIME:
					valP->tDateTime.tokDate = date;
					valP->tDateTime.tokTime = time;
					*lenP = sizeof(valP->tDateTime);
					code = t_datetime;
			  	  break;

				  case PDT_TIMEONLY:
					valP->tNumber.val = time;
					*lenP = sizeof(valP->tNumber);
					code = t_ztime;
			  	  break;

				  case PDT_ERROR:
					*sP = --cp;
					return t_err;
				}
			}
			else
			{
				*sP = --cp;
				return t_err;
			}
		}
		else if (!code)
		{ /* string starts with " ' or [ */
			ch = (*p==CLBRAK) ? CRBRAK : *p;
			if (p=lstrchr(cp,ch))
			{ /* found matching delimiter */
				int slen = p-cp;
				int trunclen = slen;

				if (trunclen>maxstr) trunclen = maxstr;
				*(int *)&(valP->tString[0]) = trunclen+1; /* include NULL */
				/* move the string */
				pApp->lzmemcpy(valP->tString+sizeof(int),cp,trunclen); 		// Looks ok for 32 bits
				valP->tString[trunclen+sizeof(int)] = '\0';   /* terminate it */
				cp += slen+1;	/* use slen, not trunclen! */
				*lenP = trunclen+sizeof(int)+1; /* len and terminated str is val */
				code = t_str;
				for (p=(valP->tString+sizeof(int)); *p; p++)
					if (*p==' ') *p = (char)SpaceDot;
			}
			else
			{
				*sP = --cp;
				return t_err;
			}
		}
	}
	else
	{ /* string doesn't start with character from TokCh[] */
		if ((p=lnexttok(cp,tok)) == cp) return t_eox; /* at end */
		lcftrim(tok);	/* trim trailing white space */
		p2 = tok;	/* start at beginning of token */

		/* if '(' follows token, try function name before field name */
		funcfirst = ((*pApp->lstpblk(p))==CLPAREN);
		if (lanumber(tok,valP))
		{
			code = t_num;
			*lenP = sizeof(valP->tNumber);
		}
		else if (funcfirst && lafunc(tok,valP))
		{
			{
				code = t_func;
				*lenP = sizeof(valP->tInteger);
			}
		}
		else if (filefirst && lafile(tok,valP))
		{
			code = t_file;
			*lenP = sizeof(valP->tInteger);
		}
		else if (lafield(tok,valP,qfn))
		{
			if (valP->tFldId == NOID)
			{
				code = t_qualify;	/* name must be qualified */
				p = cp;
			}
			else
			{
				code = t_fld;
				*lenP = sizeof(valP->tFldId);
			}
		}
		else if ((!filefirst) && lafile(tok,valP))
		{
			code = t_file;
			*lenP = sizeof(valP->tInteger);
		}
		else if (code=paralogic(tok))
		{ /* nothing to be done in this block */

		}
		else if (code=keywords(tok,&keytype,&ckeytype))
		{ 
			valP->tKeyword.numericVal=code;
			
			// We need to representations of the keyword. One is the
			//  representation that will go on the syntax stack and the
			//  other that will go on the compile stack.
			
			valP->tKeyword.skeytype=keytype; 	
			valP->tKeyword.ckeytype=ckeytype;
			code=t_keyword;
		}
		else if ((!funcfirst) && lafunc(tok,valP))
		{
			{
				code = t_func;
				*lenP = sizeof(valP->tInteger);
			}
		}
		else
		{
			if (qfn) p = cp;	/* to point to start of bad piece */
			code = t_err;
		}
		cp = p; 	/* update for return */
	}
	*sP = pApp->lstpblk(cp);	/* skip leading white space */
	return code;
}


