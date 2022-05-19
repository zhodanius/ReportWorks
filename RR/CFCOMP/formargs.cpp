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
// formargs.c	generate formal argument fields for user function
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/cfcomp/formargs.cpv  $
// 
//    Rev 1.11   17 Nov 1995 10:12:20   jpb
// define FreeUdfs
// 
//    Rev 1.10   22 Sep 1995 17:02:08   sjo
// Second round of FLDID changes.
// 
//    Rev 1.9   19 Sep 1995 17:56:42   sjo
// Changes made by looking at references to sizeof(int) in all sources for 32
// bit support.
// 
//    Rev 1.8   19 Sep 1995 10:47:32   jpb
// error cleanup
// 
//    Rev 1.7   18 Sep 1995 15:00:26   jpb
// move funcs to CRrComposite
// 
//    Rev 1.6   14 Sep 1995 14:55:30   sjo
// Changes for 32 bit support, mostly for pawing thru compiled code.
// 
//    Rev 1.5   02 Aug 1995 11:24:22   sjo
// Fixed a link error - lckargs was not declared as part of the doc class.
// 
//    Rev 1.4   02 Aug 1995 10:01:28   sjo
// I needed to move the include of the class headers from just after the include
// of product.h, to just after the #define of the module name.
// 
//    Rev 1.3   31 Jul 1995 13:51:02   sjo
// Another round of recompiling.
// 
//    Rev 1.2   20 Jul 1995 16:41:50   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.1   27 Apr 1995 12:35:40   sjo
// Merge of 6.1.03+.  I say + because I have added some of the time functions
// to this merge, which will be a part of 6.1.04.  I merged the CF directories
// and some H files (for the time function changes).
// 
//    Rev 1.0   16 Mar 1995 16:22:14   sbc
// Initial revision.
// 
//    Rev 1.6   06 Apr 1995 19:15:02   sjo
// Fixes as a result of date investigation of the cf directories.
// 
//    Rev 1.5   29 Mar 1995 17:23:10   jpb
// datetime changes
// 
//    Rev 1.4   28 Mar 1995 17:47:12   jpb
// add a_time case as required
// 
//    Rev 1.3   23 Mar 1995 17:01:26   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
//    Rev 1.2   08 Feb 1995 13:27:58   sjo
// Checking in a bunch of files for the first wave of datetime support. These
// sources have support for a dFlags that is a long (not an unsigned int) and
// it recognizes date, time and datetime fields.  It only supports dates at
// this time, because we need calcs, picture types, etc if we are to do time and
// datetime.
// 
// ** First merge of RRW7 took place here.
//
//    Rev 1.1   26 Jul 1994 12:38:42   jpb
// Conditional totals support
// 
//    Rev 1.0   14 Oct 1993 10:16:16   sjo
// Initial revision.
//
// 06/30/93 - ERP - Made allocation and free of ArgList global
//
// ****************************************************************************
#include "product.h"
//
// Make a definition for this module.
//
#define _FORMARGS_C_

#include "rrdoc.h"
#include "rr.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "_cfcomp.h"
#include "cfedit.h"
#include "mffield.h"
#include "mfmisc.h"
#include "util.h"
#include "wutil.h"


/* MAXCNAME includes term, so subtract 1, udf has 2 char prefix, so add 2 */
/* So far, that's 12.  But in 3b it was 11, so we subtract 1 for 3B */
/* compatibility.  Arg name length (excluding prefix), then is 9 */
#define MAXUNAME (MAXCNAME-1+2-1)

LPUDF CRrComposite::lugetudf(void)
{
	LPUDF l=UDFS;
	LPUDF u=(LPUDF)m_pDoc->globalAlloc(GMEM_MOVEABLE,sizeof(UDF));
	LPSTR name=m_pDoc->globalAlloc(GMEM_MOVEABLE,UDFNAMELEN+1);
	LPSTR decl=m_pDoc->globalAlloc(GMEM_MOVEABLE,DECLEN+1);
	int hifunc = 0;

	while (l)
	{
		if (l->uFuncNo>hifunc) hifunc = l->uFuncNo;
		if (l->uNext) l = l->uNext;
		else break;
	}

	if (!(u && name && decl))
	{
		if (u) m_pDoc->globalFree((LPSTR )u);
		if (name) m_pDoc->globalFree(name);
		if (decl) m_pDoc->globalFree(decl);
		return FALSE;
	}
	*name=*decl = '\0';

	u->uNext = NULL;
	u->uFuncNo = hifunc+1;
	u->uArgCnt = 0;
	u->uName = name;
	u->uDecl = decl;
	u->uHelp = -1;
	u->uArgList = NULL;
	u->uExpD = NULL;
	u->uExpE = NULL;
	if (l) l->uNext = u;
	else UDFS = u;

	return u;
}

void CRrComposite::lurlsexp(LPUDF u)
{
	if (u->uExpD) m_pDoc->globalFree(u->uExpD);
	if (u->uExpE) m_pDoc->globalFree(u->uExpE);
}

void CRrComposite::lurlsudf(LPUDF u)
{
	LPUDF l=UDFS;

	for (l=UDFS; l; l=l->uNext) if (l->uNext==u) break;
	if (l) l->uNext = u->uNext;
	else UDFS = u->uNext;
	m_pDoc->globalFree(u->uName);
	m_pDoc->globalFree(u->uDecl);
	if (u->uArgList) m_pDoc->globalFree((u->uArgList));
	lurlsexp(u);
	m_pDoc->globalFree((LPSTR )u);
}

void CRrComposite::uFreeUdfs()
{
	LPUDF uptr;
	LPUDF next;

	for (uptr=UDFS; uptr; uptr=next)
	{
		next = uptr->uNext;
		lurlsudf(uptr);
	}
}

void CRrComposite::lufixrefs(LPUDF u)
{
	LPSTR x=u->uExpE;

	if (x==NULL) return;

	while (TRUE)
	{
		switch (*(x++))
		{
			case a_num:
				// Number of decimal places followed by the number.
				x+=(1+sizeof(double));
				break;

			case a_datetime:
				x+=sizeof(ZDATETIME);
				break;
				
			case a_time:
				x+=sizeof(double);
				break;
				
			case a_date:
				x+=sizeof(long);
				break;

			case a_keyword:
				// a_keyword is followed by two entries.
				x+=2;
				break;
				
			case a_str:
				x += (*(int *)x)+sizeof(int);  		// OK for 32 bits
				break;

			case a_ret:
				return;
				break;

			case a_func:
			case a_ufunc:
				x++;
				x+=sizeof(int);							// OK for 32 bits
				break;

			case a_file:
				x+=sizeof(int);						   	// OK for 32 bits
				break;

			case a_pfld:
				*(x-1) = a_ufparg;	/* prev field ref is really prev arg ref */
				u->uArgList[(*(FLDID *)x)+1] |= PARG; /* show prev used */
				x+=sizeof(FLDID);					
				break;

			case a_fld:
				*(x-1) = a_ufarg;	/* field ref is really arg ref */
				x+=sizeof(FLDID);					
				break;
			case a_bfalse:
			case a_branch:
				x += sizeof(long);
				break;
		}
	}
}

int CRrComposite::lckargname(LPSTR n)
{
	if ((lstrlen(n)<3) || (!lstrchr("LNCDMTA",n[0])) || (n[1]!='_') ||
			!wisalpha(n[2])) return TRUE;
	while (*n)
	{
		if ((*n=='_') || wisalnum(*n)) n++;
		else return TRUE;
	}
	return FALSE;
}

void CRrComposite::freeargs(void)
{
	LPMFFIELD nxtfld;

	if (chainsaved)
	{
		while (MFFields)
		{
			nxtfld = MFFields->dNxtFld; /* get next before freeing current */
			mfrlsfld(MFFields,MFOCNAME|MFONOUPD); /* free current */
			MFFields = nxtfld;	/* prepare for next */
		}
		MFFields = savchain;
		MFNoFiles = savfilcnt;
		MFNoFlds = savfldcnt;
		chainsaved = FALSE;
	}
}

int CRrComposite::lformargs(
		LPSTR inp,		/* user function declaration string */
		LPSTR fnamep,	/* place to put function name */
		int *argcntp,	/* place to put argument count */
		int *erroffp,	/* returned offset to bad char */
		int okayfno,	/* okay to duplicate this udf number (-1 means any) */
		LPSTR  *alistp) /* address of pointer to argument list */
{
	CRrApp *pApp = (CRrApp *)AfxGetApp();
	char decl[DECLEN+1];
	char shortdec[5];
	LPSTR p;
	LPSTR curp;
	int i, acnt, comma;
	unsigned long flags, type;
	TOKVAL tval;
	LPMFFIELD fld;

	*erroffp = -1;
	AllFields = TRUE; /* for lafield() in toktests.c */

	lstrcpy(decl,inp);

	if (!(curp=lstrchr(decl,'('))) return ue_nop;   /* no open paren */
	*curp = '\0';       /* terminate function name */
	curp++; 		/* now pointing past open paren */
	pApp->lzcutoff(decl,' ');     /* remove trailing spaces */
	if (p=lstrchr(pApp->lstpblk(decl),' '))
	{ /* imbedded spaces in function name */
		*erroffp = p-(LPSTR )decl;
		return ue_bfn;
	}
	p = pApp->lstpblk(decl);

	if (*p=='\0')
	{ // no udf name!
		*erroffp = 0;
		return ue_bfn;	// bad function name, to be sure
	}

	while (*p)
	{
		if ((*p=='_') ||
				(wisalnum(*p))) p++;
		else
		{ /* bad character in udf name */
			*erroffp = p-(LPSTR )decl;
			return ue_bfn;
		}
	}
	lstrcpy(decl,p=(pApp->lstpblk(decl)));	/* remove leading spaces */
	if (strlen(decl)>UDFNAMELEN) decl[UDFNAMELEN] = '\0';
	if ((okayfno!=-1) && (lafunc(decl,&tval) && (tval.tInteger!=(-okayfno))))
	{
		*erroffp = p-(LPSTR )decl;
		return ue_niu;
	}
	pApp->lzmemcpy(shortdec,decl,4);
	shortdec[4] = '\0';
	if ((okayfno!=-1) &&
			(lafunc(shortdec,&tval) && (tval.tInteger!=(-okayfno))))
	{ /* name not unique in first four characters */
		*erroffp = p-(LPSTR )decl;
		return ue_anu;		/* not unique in first four chars */
	}
	lstrcpy(fnamep,decl);
	for (p=curp; *p; p++) *p = wtoupper(*p);/* to upper case */
	acnt = 0;
	if (!(i=(pApp->lzcutoff(curp,' ')))) return ue_ncp;
	if (curp[i-1]==')') curp[i-1] = '\0';
	else return ue_ncp;

	savchain = MFFields;
	chainsaved = TRUE;
	savfilcnt = MFNoFiles;
	savfldcnt = MFNoFlds;
	MFNoFiles = 1;
	MFFields = NULL;
	comma = FALSE;

	while (TRUE)
	{ /* process the formal arguments */
		curp = pApp->lstpblk(curp);				/* skip leading white space */
		if (p=lstrchr(curp,','))
		{
			*p = '\0';  /* change arg sep to null */
			p++;		/* will be start of next arg */
			comma = TRUE;
		}
		i = pApp->lzcutoff(curp,' ');             /* remove trailing spaces */
		if (!i)
		{
			if (comma)
			{ /* null arg name, and comma seen */
				*erroffp = curp-(LPSTR )decl;	/* sounds like missing argument */
				freeargs();
				return ue_mar;
			}
			else break;   /* no arguments */
		}
		if (i>MAXUNAME) curp[MAXUNAME] = '\0';
		if (lckargname(curp))
		{
			*erroffp = curp-(LPSTR )decl;
			freeargs();
			return ue_ban;		/* bad argument name */
		}
		if (lafield(&curp[2],&tval,TRUE))
		{
			*erroffp = curp-(LPSTR )decl;
			freeargs();
			return ue_aiu;
		}
		if (fld=mfgetfld(MFOCNAME))
		{
			acnt++;
			lstrcpy(fld->dCNameP,&curp[2]); /* move in the argument name */
			switch (*curp)
			{
				case 'N': type = zfNUMERIC;
					break;
				case 'D': type = zfDATE;
					break;
				case 'M': type = zfMEMO;
					break;
				case 'L': type = zfLOGICAL;
					break;
				case 'T': type = zfTIME;
					break;
				case 'A': type = zfDATETIME;
					break;
				default:  type = 0;
					break;
			}
			fld->dFlags = type|zfNOTinREC;
			fld->dFileNo = 0;
		}
		else
		{
			freeargs();
			return ue_mem;
		}
		if (!(curp=p)) break;
	}
	if (!acnt) acnt++;
	*argcntp = acnt;

	if (!(*alistp=m_pDoc->globalAlloc(GMEM_MOVEABLE,acnt+1)))
	{
		freeargs();
		return ue_mem;
	}

	for (acnt=1, fld=MFFields; fld; acnt++, fld=fld->dNxtFld)
	{
		flags = fld->dFlags;
		(*alistp)[acnt] = (flags&zfNUMERIC) ? sv_dbl :
			(flags&zfDATE) ? sv_date :
				(flags&zfMEMO) ? sv_memo :
					(flags&zfLOGICAL) ? sv_dbl|LOGICAL :
						(flags&zfDATETIME) ? sv_datetime :
							(flags&zfTIME) ? sv_time :
								sv_str;
	}
	if (acnt==1)
	{ /* function takes no arguments */
		(*alistp)[1] = sv_none;
	}
	else acnt--;	  /* undo extra increment */
	(*alistp)[0] = acnt;
	return FALSE;
}


