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
// Calculation compiler - the only non-static routine is lcfcomp which takes
//	as input "t_box", a global pointer to the Beginning Of Xpression
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/CFCOMP/CFCOMP.CPV  $
// 
//    Rev 1.19   Oct 24 2002 08:53:34   Admin
// Prettify
// 
//    Rev 1.18   21 Jan 1998 12:11:44   smh
// OEM20001 merge
// 
//    Rev 1.17.1.0   15 Jan 1998 15:22:00   smh
// RRW 8.0 Abra OEM
// 
//    Rev 1.17   24 Feb 1997 15:55:34   jpb
// fix rsw 2993 (clean up changing of a_fld to a_pfld for prev field ref)
// 
//    Rev 1.16   29 Jan 1996 16:14:18   jpb
// fix compilation of "push empty memo"
// 
//    Rev 1.15   11 Oct 1995 08:56:48   smh
// In rule3 need to cast syntax stack to int ptr b4 take ufunc no.
// 
//    Rev 1.14   25 Sep 1995 14:34:40   jpb
// fix parenthesization problem in string literal compilation
// 
//    Rev 1.13   22 Sep 1995 17:01:48   sjo
// Second round of FLDID changes.
// 
//    Rev 1.12   19 Sep 1995 17:56:38   sjo
// Changes made by looking at references to sizeof(int) in all sources for 32
// bit support.
// 
//    Rev 1.11   18 Sep 1995 15:00:18   jpb
// move funcs to CRrComposite
// 
//    Rev 1.10   14 Sep 1995 18:08:58   sjo
// Had to fix the return type stack.  It's a char stack, not a UTWO stack.
// 
//    Rev 1.9   14 Sep 1995 14:55:44   sjo
// Changes for 32 bit support, mostly for pawing thru compiled code.
// 
//    Rev 1.8   12 Sep 1995 10:09:20   sjo
// Variable name changes.
// 
//    Rev 1.7   11 Sep 1995 11:12:46   sjo
// 32-bit changes.
// 
//    Rev 1.6   02 Aug 1995 10:01:44   sjo
// I needed to move the include of the class headers from just after the include
// of product.h, to just after the #define of the module name.
// 
//    Rev 1.5   31 Jul 1995 13:50:42   sjo
// Another round of recompiling.
// 
//    Rev 1.4   28 Jul 1995 16:52:30   sjo
// Fix for RRW 2436.  See also eval.cpp.
// 
//    Rev 1.3   20 Jul 1995 16:42:02   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.2   30 Jun 1995 17:11:30   sjo
// Problem with calcs that take optional arguements.  
// 
//    Rev 1.1   27 Apr 1995 12:35:52   sjo
// Merge of 6.1.03+.  I say + because I have added some of the time functions
// to this merge, which will be a part of 6.1.04.  I merged the CF directories
// and some H files (for the time function changes).
// 
//    Rev 1.0   16 Mar 1995 16:22:06   sbc
// Initial revision.
// 
//    Rev 1.8   10 Apr 1995 17:04:10   sjo
// Fixed a problem with figuring out the return type of a dteadd() function.
// 
//    Rev 1.7   06 Apr 1995 19:15:28   sjo
// Fixes as a result of date investigation of the cf directories.
// 
//    Rev 1.6   28 Mar 1995 17:47:08   jpb
// add a_time case as required
// 
//    Rev 1.5   27 Mar 1995 19:38:02   sjo
// Fixed a problem with reading UDFS.
// 
//    Rev 1.4   23 Mar 1995 17:01:12   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
// ** First merge of RRW7 took place here.
//
//    Rev 1.3   18 Jan 1995 17:47:40   sjo
// Made changes to remove compiler warnings.
// 
//    Rev 1.2   14 Nov 1994 16:08:50   jpb
// detect and report ee_ivnudf
// 
//    Rev 1.1   09 Mar 1994 16:55:10   dlm
// From Abra branch, added code, conditional on PASSWORD_REQD, that
//  restricts some of the ?LOOKUP-function arguments to literal
//  strings, so that we can check security level of field being
//  looked up.
// 
//    Rev 1.0.1.1   28 Feb 1994 09:55:28   dlm
// Added or improved conditionals.
// 
//    Rev 1.0.1.0   11 Jan 1994 10:29:02   dlm
// LOOKUP function argument restrictions: don't allow anything but literal
//  strings for FIELD and FILE arguments, so security can be checked.
// 
//    Rev 1.0   14 Oct 1993 10:16:10   sjo
// Initial revision.
// ****************************************************************************
#include "product.h"

//
// Make a definition for this module.
//
#define _CFCOMP_C_

#include "rrdoc.h"
#include "rr.h"
#include "stdio.h"
#include "_cfcomp.h"
#include "cfeval.h"     // only needed for ZERRDATE 
#if defined(PASSWORD_REQD)
#include "datadict.h"
#endif
#include "mffield.h"
#include "mfmisc.h"
#include "util.h"

// The following typedef defines the size of a function number entry in the 
//  syntax stack.  This is used because all other syntax stack entries are 
//  of size CHAR.  This typedef is used to determine offsets into the syntax
//  stack when a function number entry occurs.   The function number can be
//  negative.
typedef	int	SSFUNCNUM;	

#define CKCPOFLO cf_cpoflo |= pCompileBuf>cfrpnend
#define CKSYNOFLO cf_synoflo |= pSyntaxStack>cfsynend

void CRrComposite::copyn(char *ip,int len)
{
	while (len--)
		*(pCompileBuf++) = *(ip++);
	CKCPOFLO;	/* check for rpn buffer overflow */
}

int CRrComposite::relact(char action)
{
	switch (action)
	{
	case a_eq:
	case a_neq:
	case a_le:
	case a_ge:
	case a_lt:
	case a_gt:
	case a_subst:
		return TRUE;

	default:
		return FALSE;
	}
}

int CRrComposite::logact(char action)
{
	switch (action)
	{
	case a_or:
	case a_not:
	case a_and:
		return TRUE;

	default:
		return FALSE;
	}
}

int CRrComposite::operand(char token)
{
	switch (token&TOKMASK)
	{
	case t_num:
	case t_memo:
	case t_str:
	case t_date:
	case t_datetime:
	case t_ztime:
	case t_noarg:
	case t_file:
	case t_query: 
	case t_dateinterval:
	case t_datetimeinterval:
	case t_timeinterval:
	case t_timepicture:
		return TRUE;

	default:
		return FALSE;
	}
}

/* returns TRUE iff type mismatch for str, dbl, date, file only */
int CRrComposite::mistype(char svtype,char ttype)
{
	int result;

	ttype &= TOKMASK;
	switch (svtype)
	{
	case sv_str:
		result = ttype!=t_str;
		break;

	case sv_dbl:
		result = ttype!=t_num;
		break;

	case sv_date:
		result = ((ttype!=t_date) && (ttype!=t_datetime));
		break;
			
	case sv_dateinterval:
		result = ((ttype!=t_dateinterval) && (ttype!=t_datetimeinterval));
		break;
			
	case sv_timeinterval:
	   result = ((ttype!=t_timeinterval) && (ttype!=t_datetimeinterval));
		
	case sv_datetimeinterval:
		result = ((ttype!=t_datetimeinterval) && (ttype!=t_dateinterval) && (ttype!=t_timeinterval));
		break;
			
	case sv_timepicture:
		result = ttype!=t_timepicture;
		break;

	case sv_datetime:
		result = ((ttype!=t_datetime) && (ttype!=t_date) && (ttype!=t_ztime));
		break;
			
	case sv_time:
		result = ((ttype!=t_ztime) && (ttype!=t_datetime));
		break;

	case sv_file:
		result = ttype!=t_file;
		break;

	case sv_query:
		result = ttype!=t_query;
		break;

	default:
		result = FALSE;
		break;
	}
	return result;
}

void CRrComposite::getRetType(int *funcNumber, int argCnt)
{
	if (*funcNumber == f_dateadd)
	{
		// Figure out the return type 
		// If we have a datetime field, then we have a datetime
		//  return type.  If we have a date or time field, and 
		//  the keyword indicates that we are doing something of
		//  the 'other type' (date keyword on a time field or 
		//	 time keyword on a date field), we need to return a datetime
		//  type.
		char	keyword, num, field;
				
		// The return type stack is a char pointer.  Function numbers, arg cnts and
		//  keywords will all fit in a char.  ASSERT before putting stuff on the 
		//  stack.
		cf_retTypeStack -= 1;
		field = *cf_retTypeStack;
		cf_retTypeStack -= 1;
		num = *cf_retTypeStack;
		cf_retTypeStack -= 1;
		keyword = *cf_retTypeStack;
		
		if (field==t_datetime)
			*funcNumber=f_dateadddt;
		else
		{
			if (( (field==t_ztime) && (keyword==t_dateinterval) ) ||
			     ((field==t_date) && (keyword==t_timeinterval)) )
			{	// we have a time field, and a date keyword, the return type
				//  datetime or a date field and a time keyword.
				*funcNumber=f_dateadddt;
			}
			else
			{
				if (field==t_ztime)
					*funcNumber=f_dateaddt;
				else
					*funcNumber=f_dateadd;
			}
		}
	}
	else
		cf_retTypeStack-=argCnt;

	return;
}


int CRrComposite::prevokay(char prvtok)
{
/* TOKMASK also masked out TLOG.  Now we preserve TLOG
			for iif(cond,.t.,0) error detection */
	char thisone=(*(pSyntaxStack-1))&(~TNULLSTR);
	char prev=prvtok&(~TNULLSTR);

	if (thisone==prev)
	{
		*(pSyntaxStack-1) &= ~TNULLSTR;
		return TRUE;
	}
	if (prev==t_memo && ((*(pSyntaxStack-1))&TNULLSTR))
	{
		*(pSyntaxStack-1) = t_memo; /* for reference in rule2/rule3 */
		*cf_lastcp = a_mtmemo; /* change "push null string" to push */

		// we've replaced the "push string" opcode with a "push empty memo" opcode
		// but the "push string" was followed by an empty string, so - 
		// back up compiled code pointer by size of pushed null string 
		// which is a length int followed by a null string (a string terminating null byte)
		pCompileBuf -= (sizeof(int) + sizeof(char));			/* empty memo */
		return TRUE;
	}
	return FALSE;
}

int CRrComposite::rule1(void) /* termination */
{
	char t;

	if ((pSyntaxStack-pSyntaxStackHead>=2) &&
			(*pSyntaxStack == t_eox) &&
			(((t=(*(pSyntaxStack-1))&TOKMASK)==t_num) || (t==t_memo) || (t==t_str) || (t==t_date) || 
			  (t==t_query) || (t==t_ztime) || (t==t_datetime)) &&
			(*(pSyntaxStack-2) == t_box))
	{
		*(cf_nextlast=pCompileBuf++) = a_ret;
		CKCPOFLO;	/* check for rpn buffer overflow */
		pSyntaxStack -= 3; 	/* is this necessary? */
		return TRUE;
	}
	return FALSE;
}

int CRrComposite::rule2(void) /* function argument processing */
{
	char cnt;
	int cycle, ent;
	LPSTR argp;
	LPSTR np;
	char atype;
	char opt;
	char t;
	LPUDF u;

	if ((pSyntaxStack-pSyntaxStackHead>=3) &&
			(*pSyntaxStack == t_comma) &&
			operand((t=(*(pSyntaxStack-1))&TOKMASK)) &&
			(*(pSyntaxStack-2) == t_lp) &&
			(*(pSyntaxStack-3) == t_func))
	{
		// Bump by size of 4 entries plus sizeof function number entry
		(*(pSyntaxStack-(4+sizeof(SSFUNCNUM))))++; 	/* bump the argument count */

		// Get the function number entry (minus sizeof 3 entries plus size of function number entry)
		cfefunc = *(SSFUNCNUM *)(pSyntaxStack-(3+sizeof(SSFUNCNUM)));
		cnt = *(pSyntaxStack-(4+sizeof(SSFUNCNUM)));
		if (cfefunc < 0)
		{ /* user function */
			for (u=UDFS; u; u=u->uNext)
			{
				if (cfefunc==-(u->uFuncNo))
				{
					argp = u->uArgList;
					if (!argp)
					{
						cf_ecode = ee_invudf;
						return(FALSE);
					}
					break;
				}
			}
		}
		else argp = functab[cfefunc].fArgs; /* R&R function */

		atype = argp[cnt] & ~(PARG|OPTARG|LOGICAL); /* isolate argument type */
		opt = argp[cnt] & OPTARG;	/* isolate optional flag*/

		if (argp[0]==0)
		{ /* special case for CASE() function */
			if (t==t_fld || t==t_file)
			{
				cf_ecode = ee_argt;
				return FALSE;
			}
			if (t==t_noarg)
			{
				cf_ecode = ee_argr;
				return FALSE;
			}
			if ((cnt==1 || cnt%2==0) && t==t_memo)
			{
				cf_ecode = ee_argt;
				return FALSE;
			}
			if (cnt==1)
				cf_elements[0] = *(pSyntaxStack-1);
			else if (cnt==3)
				cf_elements[1] = *(pSyntaxStack-1);
			else if (!prevokay(cf_elements[(cnt-2)%2]))
			{
				cf_ecode = ee_argt;
				return FALSE;
			}
		}
		else if (argp[0]&0x80)
		{
			cycle = 256-argp[0];	/* items in a cycle */
			ent = (cnt-1) % cycle;	/* current args offset into cycle */
			if (cnt<=cycle) 		/* in first cycle? */
			{
				cf_elements[ent] = *(pSyntaxStack-1);
			}
			if (t==t_noarg)
			{
				cf_ecode = ee_argr;
				return FALSE;
			}
			if (mistype((char)(argp[ent+1]&~PARG),t) ||
					((argp[ent+1]&~PARG)==sv_any &&
						((cnt<=cycle && (t==t_memo || t==t_fld || t==t_file)) ||
							(cnt>cycle && t!=(cf_elements[ent]&TOKMASK))
						)))
			{
				cf_ecode = ee_argt;
				return FALSE;
			}
		}
		else if (cnt > argp[0])
		{
			cf_ecode=ee_argc;
			return FALSE;
		}
		else if (!opt && t==t_noarg)
		{
			cf_ecode = ee_argr;
			return FALSE;
		}
		else if (t!=t_noarg &&
				(mistype(atype,t) ||
					(atype==sv_any && (t==t_memo||t==t_fld||t==t_file)) ||
					(atype==sv_many && (t==t_fld||t==t_file)) ||
#ifdef RSW
					 (atype==sv_char && t!=t_str && t!=t_memo) ||
#endif
					(atype==sv_prev && !prevokay(*(pSyntaxStack-(5+sizeof(SSFUNCNUM)))))))
		{
			cf_ecode = ee_argt;
			return FALSE;
		}
		else if (atype==sv_none && t!=t_noarg)
		{ /* arg supplied to routine that takes none */
			cf_ecode = ee_argc;
			return FALSE;
		}
#if defined(PASSWORD_REQD)
		else if (((cfefunc == f_clookup) || (cfefunc == f_dlookup)
			   || (cfefunc == f_llookup) || (cfefunc == f_nlookup))	
			  && ((cnt == 2) || (cnt == 3)))
		{	// field and table args to ?lookup() functions must be literal strings
			if (*cf_lastcp != a_str)
			{
				cf_ecode = ee_argt;	// wrong arg type
				return FALSE;
			}
			if (cnt == 2)
				cf_LookupFieldArg = cf_lastcp+3;	// remember where field string is
			else
			{	// see if it's a restricted field
				// 7/22/97 MFC - ABRAFIX: COnversion to RRW 8.0
				if (FirstErr || theApp.ddlookup(cf_LookupFieldArg,cf_lastcp+3))
				{
					FirstErr = TRUE;	// so we don't bother with this again
					cf_ecode = ee_argt;
					return FALSE;
				}
			}
		}
#endif
		else if (argp[cnt]&PARG)
		{
			if (*cf_lastcp==a_fld) 	/* was last action "push field"? */
			{
				np = cf_lastcp+1;		/* char ptr to fld number FLDID */
				mfbyndx(*(FLDID *)np)->dFlags |= zfPREVARG;
			}
			else
			{
				cf_ecode = ee_argf;
				return FALSE;
			}
		}

		// prevtype is 5 entries away plus size of function number entry
		*(pSyntaxStack-(5+sizeof(SSFUNCNUM))) = *(pSyntaxStack-1);	/* "prevtype"; not "t" - we want TLOG state */

		// While we are reducing the syntax stack, push the token type
		//  onto the return type stack.
		ASSERT(t<255);
		*cf_retTypeStack = t;
		cf_retTypeStack++;
		pSyntaxStack -= 2;
		if (cfefunc==f_inlst ||
				cfefunc==f_case) *(cf_nextlast=pCompileBuf++) = a_argsep;
		if (cfefunc==f_if)
		{
			if (cnt==1)
			{
				if (++cf_ifno > IIFDEPTH)
				{
					cf_ecode = ee_ifdepth;
					return FALSE;
				}
				*(cf_nextlast=pCompileBuf++) = a_bfalse;
				cf_branch[cf_ifno] = pCompileBuf-cfrpn;
				pCompileBuf += sizeof(long);
			}
			else
			{
				*(long *)(cfrpn+cf_branch[cf_ifno]) =
					pCompileBuf+1+sizeof(long)-cfrpn-cf_branch[cf_ifno];
				*(cf_nextlast=pCompileBuf++) = a_branch;
				cf_branch[cf_ifno] = pCompileBuf-cfrpn;
				pCompileBuf += sizeof(long);
			}
		}
		CKCPOFLO;	/* check for rpn buffer overflow */
		return TRUE;
	}
	return FALSE;	   
}

int CRrComposite::rule3(void) /* final function argument */
{
	int i, cycle, ent;
	char cnt;
	LPSTR argp;
	LPSTR np;
	char atype;
	char opt;
	char t;
	LPUDF u;
	int		newfunc;
	int		myfunc;

	if ((pSyntaxStack-pSyntaxStackHead>=3) &&
			(*pSyntaxStack == t_rp) &&
			operand((t=(*(pSyntaxStack-1))&TOKMASK)) &&
			(*(pSyntaxStack-2) == t_lp) &&
			(*(pSyntaxStack-3) == t_func))
	{ /* final function argument, check arg types/count/etc */
		cnt = ++(*(pSyntaxStack-(4+sizeof(SSFUNCNUM))));		/* count of args supplied */
		cfefunc = *(SSFUNCNUM *)(pSyntaxStack-(3+sizeof(SSFUNCNUM)));
		if (cfefunc<0)
		{ /* user function */
			for (u=UDFS; u; u=u->uNext)
			{
				if (cfefunc==-(u->uFuncNo))
				{
					argp = u->uArgList;
					if (!argp)
					{
						cf_ecode = ee_invudf;
						return(FALSE);
					}
					break;
				}
			}
		}
		else argp = functab[cfefunc].fArgs; /* R&R function */
		atype = argp[cnt] & ~(PARG|OPTARG|LOGICAL); /* isolate arg type */
		opt = argp[cnt] & OPTARG;	/* isolate optional flag*/

		if (argp[0]==0)
		{ /* special case for CASE() function */
			if ((cnt<4) || (cnt%2))
			{
				cf_ecode = ee_argc2;
				return FALSE;
			}
			if (t==t_fld || t==t_file)
			{
				cf_ecode = ee_argt;
				return FALSE;
			}
			if (t==t_noarg)
			{
				cf_ecode = ee_argr;
				return FALSE;
			}
			if (!prevokay(cf_elements[1]))
			{
				cf_ecode = ee_argt;
				return FALSE;
			}
		}
		else if (argp[0]&0x80)
		{ /* variable number of arguments */
			cycle = 256-argp[0];	/* items in a cyle */
			ent = (cnt-1) % cycle;	/* current args offset into cycle */
			if ((!cnt) || (ent!=(cycle-1)) || (t==t_noarg))
			{
				cf_ecode=ee_argr;
				return FALSE;
			}
			if (mistype((char)(argp[ent+1]&~PARG),t) ||
					((argp[ent+1]&~PARG)==sv_any &&
						((cnt<=cycle && (t==t_memo || t==t_fld || t==t_file)) ||
							(cnt>cycle && t!=(cf_elements[ent]&TOKMASK))
						)))
			{
				cf_ecode = ee_argt;
				return FALSE;
			}
		}
		else
		{
			if (cnt != argp[0])
			{ /* incorrect number of arguments supplied */
				if (cnt<argp[0])
				{ /* too few, see if unsupplied are optionial */
					for (i=0; i<(argp[0]-cnt); i++)
					{
						if (argp[cnt+i+1]&OPTARG)
						{
							*(cf_nextlast=pCompileBuf++) = a_noarg; /* opt */
					 		*(cf_retTypeStack) = t_noarg;
							cf_retTypeStack++;
						}
						else
						{ /* missing arg not optional */
							cf_ecode=ee_argr;
							return FALSE;
						}
					}
					/* all missing are optional, fix arg count and procede */
					*(pSyntaxStack-(4+sizeof(SSFUNCNUM))) = argp[0];
				}
				else
				{ /* too many arguments */
					cf_ecode=ee_argc;
					return FALSE;
				}
			}
			if (atype!=sv_none && !opt && t==t_noarg)
			{
				cf_ecode = ee_argr;
				return FALSE;
			}
			else if (t!=t_noarg &&
					(mistype(atype,t) ||
						(atype==sv_any && (t==t_memo||t==t_fld||t==t_file))||
						(atype==sv_many && (t==t_fld||t==t_file))||
#ifdef RSW
						 (atype==sv_char && t!=t_str && t!=t_memo) ||
#endif
						(atype==sv_prev && !prevokay(*(pSyntaxStack-(5+sizeof(SSFUNCNUM)))))))
			{
				cf_ecode = ee_argt;
				return FALSE;
			}
			else if (atype==sv_none && t!=t_noarg)
			{ /* arg supplied to routine that takes none */
				cf_ecode = ee_argc;
				return FALSE;
			}
			else if (atype==sv_fld)
			{
				if (*cf_lastcp==a_fld) 	/* was last action "push field"? */
				{
					if ((cfefunc==f_prev) || (argp[cnt]&PARG))
					{ /* from PREV() function */
						*cf_lastcp = a_pfld;	/* yes, make it prev */
						np = cf_lastcp+1;		/* char ptr to fld number int */
						mfbyndx(*(FLDID *)np)->dFlags |= zfPREVARG;
					}
				}
				else
				{
					cf_ecode = ee_argf;
					return FALSE;
				}
			}
		}

		if (cfefunc==f_inlst ||	cfefunc==f_case)
			*(cf_nextlast=pCompileBuf++) = a_argsep;
		*(pSyntaxStack-(5+sizeof(SSFUNCNUM))) = *(pSyntaxStack-1);	/* "prevtype"; not "t" - we want TLOG state */
		if (cfefunc==f_if)
		{
			*(long *)(cfrpn+cf_branch[cf_ifno--]) = pCompileBuf-cfrpn-cf_branch[cf_ifno];
		}

		// While we are reducing the syntax stack, push the token type
		//  onto the return type stack.
		ASSERT(t<255);
 		*cf_retTypeStack = t;
		cf_retTypeStack++;

		/* get function output type */
		if (cfefunc<0)
		{ /* user function */
			newfunc=cfefunc;
			atype = u->uType;
			*(cf_nextlast=pCompileBuf++) = a_ufunc; /* compile "user function" */
			*(SSFUNCNUM *)(pSyntaxStack-(3+sizeof(SSFUNCNUM))) *= -1;	/* make function number positive */
		}
		else
		{
			newfunc=cfefunc;
			getRetType(&newfunc, *(pSyntaxStack-(4+sizeof(SSFUNCNUM))));
			atype = functab[newfunc].fType;
			*(cf_nextlast=pCompileBuf++) = a_func;	/* compile "function" */
		}
		// Before we finish compiling the function, we need to know what
		//  function it is.  For datetime functions, we need to go thru
		//  the cf_retTypeStack to see what the return type will be, so we
		//  know what the function number is.
		
		functype = atype==sv_str ? t_str :
			atype==sv_date ? t_date :
			atype==sv_time ? t_ztime :
			atype==sv_datetime ? t_datetime:
			atype==sv_query ? t_query :
			atype==sv_prev ? *(pSyntaxStack-(5+sizeof(SSFUNCNUM))) :
			atype&LOGICAL ? t_num|TLOG : t_num;

		if (newfunc!=cfefunc)
			// Function was changed by getRetType
			myfunc=newfunc;
		else	
			myfunc=(*(SSFUNCNUM *)(pSyntaxStack-(3+sizeof(SSFUNCNUM))));
			
		if (functype&TLOG)
			myfunc |= 0x8000; /* => logical result */

		(*(int *)pCompileBuf) = myfunc;
		pCompileBuf+=sizeof(int);									// OK for 32 bits
		*(pCompileBuf++) = *(pSyntaxStack-(4+sizeof(SSFUNCNUM)));	/* compile the argument count */

		CKCPOFLO;	/* check for rpn buffer overflow */
		pSyntaxStack -= (5+sizeof(SSFUNCNUM)); 			/* pop syn stack */
		*pSyntaxStack = functype;

		return TRUE;
	}
	return FALSE;
}

int CRrComposite::rule4(void) /* parenthesis removal */
{
	char t;

	if ((pSyntaxStack-pSyntaxStackHead>=3) &&
			(*pSyntaxStack==t_rp) &&
			(((t=(*(pSyntaxStack-1))&TOKMASK)==t_num) || (t==t_date) || (t==t_str) || 
			  (t==t_query) || (t==t_ztime) || (t==t_datetime)) &&
			(*(pSyntaxStack-2)==t_lp) &&
			(*(pSyntaxStack-3)!=t_num))
	{
		*(pSyntaxStack-2) = *(pSyntaxStack-1);	/* not "t" to preserve token flag bits */
		pSyntaxStack -= 2;
		return TRUE;
	}
	return FALSE;
}

int CRrComposite::rule5(void) /* binary operators */
{
	char t1,tok1;
	char t2,tok2;

	if ((pSyntaxStack-pSyntaxStackHead>=3) &&
			(!operand(*pSyntaxStack)) &&
			(!operand(*(pSyntaxStack-2))) &&
			operand((t1=(*(pSyntaxStack-1))&TOKMASK)) && operand((t2=(*(pSyntaxStack-3))&TOKMASK)) &&
			(optable[*(pSyntaxStack-2)-1].oBinary >= optable[*pSyntaxStack-1].oBinary) &&
			optable[*(pSyntaxStack-2)-1].oBinary)
	{
		if ((t1==t2 && (t1==t_num || t1==t_date || t1==t_datetime || t1==t_str || t1==t_ztime)) ||
				((t1==t_num) && ((t2==t_date) || (t2==t_datetime))) ||
				((t1==t_date) && ((t2==t_datetime) || (t2==t_num))) ||
				((t1==t_datetime) && ((t2==t_date) || (t2=t_num))) ||
				(t1==t_str) && (t2==t_memo))
		{
			char act =optable[*(pSyntaxStack-2)-1].oBAction;

			if (act==a_subst && t2!=t_str)
			{
				cf_ecode = ee_op;
				return FALSE;
			}

			tok1=(t1==t_date ? t_date : t1==t_datetime ? t_date : t1);
			tok2=(t2==t_date ? t_date : t2==t_datetime ? t_date : t2);
			
			// ADD DATETIME ARITHMETIC...
			if (tok1==t_date || tok2==t_date)
			{ /* check date operation */
				if (tok1==tok2 && act==a_minus)
				{ /* date-date=number */
					act = a_datedif;
					*(pSyntaxStack-3) = t_num; /* result type */
				}
				else if (tok1!=tok2)
				{ /* date/number combination */
					if (act==a_plus)
					{ /* date+num=num+date=date */
						act = a_plusdays;
						*(pSyntaxStack-3) = t_date; /* result type */
					}
					else if (act==a_minus && tok2==t_date)
					{ /* date-num=date */
						act = a_subdays; /* *(s-3) already t_date */
					}
					else
					{ /* illegal date operation */
						cf_ecode = ee_op;
						return FALSE;
					}
				}
				else if (tok1==tok2 && (!relact(act)))
				{ /* not date/date relational either */
					cf_ecode = ee_op;
					return FALSE;
				}
			}
			else if (t1==t_str && t2==t_str)
			{
				switch (act)
				{
				case a_plus:
					act = a_cat;
					break;
				case a_minus:
					act = a_tcat;
					break;

				case a_eq:
				case a_neq:
				case a_le:
				case a_ge:
				case a_lt:
				case a_gt:
				case a_subst:
					break; /* ok string ops */

				default: /* illegal string operation */
					cf_ecode = ee_op;
					return FALSE;
				}
			}
			else if (t1==t_str && t2==t_memo)
			{
				switch (act)
				{
				case a_eq:
				case a_neq:
					break; /* memo search */

				default: /* illegal operation */
					cf_ecode = ee_op;
					return FALSE;
				}
			}

			*(cf_nextlast=pCompileBuf++) = act;
			CKCPOFLO;	/* check for rpn buffer overflow */
			if (relact(act) || logact(act))
				*(pSyntaxStack-3) = (char)(t_num|TLOG);/* logical/relational makes logical */
			else *(pSyntaxStack-3) &= ~TLOG;	/* not relational, result not logical */
			*(pSyntaxStack-2) = *pSyntaxStack;
			pSyntaxStack-= 2;
			return TRUE;
		}
		else
		{
			cf_ecode = ee_op;
			return FALSE;
		}
	}
	return FALSE;
}

int CRrComposite::rule6(void) /* unary operators */
{
	if ((pSyntaxStack-pSyntaxStackHead>=3) &&
			(!operand(*pSyntaxStack)) && (((*(pSyntaxStack-1))&TOKMASK)==t_num) &&
			(!operand(*(pSyntaxStack-2))) && (!operand(*(pSyntaxStack-3))) &&
			(optable[*(pSyntaxStack-2)-1].oUnary >= optable[*pSyntaxStack-1].oBinary) &&
			optable[*(pSyntaxStack-2)-1].oUnary)
	{
		*(cf_nextlast=pCompileBuf++) = optable[*(pSyntaxStack-2)-1].oUAction;
		CKCPOFLO;	/* check for rpn buffer overflow */
		*(pSyntaxStack-2) = *(pSyntaxStack-1);
		*(pSyntaxStack-1) = *pSyntaxStack;
		pSyntaxStack--;
		return TRUE;
	}
	return FALSE;
}

int CRrComposite::rule7(void) /* error detection */
{
	LPSTR p=pSyntaxStack;
	int lp=0;
	int rp=0;

	if (*pSyntaxStack==t_eox)
	{
		while (p>pSyntaxStackHead)
		{
			if (*p==t_func)
			{
				p-=4;
				continue;
			}
			if (*p==t_lp)
				lp++;
			else if (*p==t_rp)
				rp++;
			p--;
		}
		cf_ecode = rp!=lp ? ee_paren : ee_unk;
		return TRUE;
	}
	return FALSE;
}


int CRrComposite::lcfcomp(int *erroffP)
{
	CRrApp *pApp = (CRrApp *)AfxGetApp();
	LPSTR inp=(pApp->lstpblk(cflex));
	LPSTR curtok=inp;
	LPSTR prevtok=inp;
	char tcode;
	TOKVAL val;
	int vallen;
	char tok=t_box; 	/* start with beginning of expression */
	int done;
	int bad = FALSE;
	LPMFFIELD fld;
	LPMFFILE file;
	long 	branchtab[IIFDEPTH];
	UTWO	rets[50];         	// return stack is 100 bytes.
	cf_branch = branchtab;
	cf_ifno = -1;

	cf_retTypeStack = (char *)&rets;
	filefirst=cf_cpoflo=cf_synoflo=cf_retTypeoflo = FALSE;
	pSyntaxStackHead = cfsyn;
	pSyntaxStack = cfsyn-1;	/* init pointers */
	pCompileBuf = cfrpn;
	udfslop=tokslop = 0;
	cf_nextlast=cf_lastcp = pCompileBuf;

	while (TRUE)
	{
		switch (tok)
		{ /* no t_date case, as all dates are results of functions */
		case t_eox:
			done = TRUE;
			*(++pSyntaxStack) = t_eox;
			break;

		case t_err:
			*erroffP = curtok - cflex;
			udfslop=tokslop = 0;
			return ee_token;
			break;


/*		  case t_pgerr:
			*erroffP = prevtok - cflex;
			udfslop=tokslop = 0;
			return ee_pgerr;
		  break;

		  case t_memo:
			*erroffP = prevtok - cflex;
			udfslop=tokslop = 0;
			return ee_memo;
		  break;
*/
		case t_qualify:
			*erroffP = curtok - cflex;
			udfslop=tokslop = 0;
			return ee_qual;
			break;

		case t_num:
			*(++pSyntaxStack) = t_num;
			*(cf_nextlast=pCompileBuf++) = a_num;	/* compile "push number" */
			*(pCompileBuf++) = val.tNumber.dec; /* the number of dec places in input */
			*(double *)pCompileBuf = val.tNumber.val; /* and the number */
			pCompileBuf += sizeof(double);
			break;

		case t_str:
			tcode = t_str;

			// SJO - looks like tString has an int length at the front, followed by
			// the string.  This needs to change.
			if (*(int *)&(val.tString[0])==1)
				tcode |= TNULLSTR;
			*(++pSyntaxStack) = tcode;
			*(cf_nextlast=pCompileBuf++) = a_str;	/* compile "push string"and the string */ 
			copyn(val.tString,(*(int *)(val.tString))+sizeof(int));		// OK for 32 bits
			break;

		case t_datetime:
			if (val.tDateTime.tokDate==ZERRDATE || pApp->zERRdbl(val.tDateTime.tokTime))
			{
				*erroffP = curtok - cflex;
				udfslop=tokslop = 0;
				return ee_baddate;
			}
			*(++pSyntaxStack) = t_datetime;
			*(cf_nextlast=pCompileBuf++) = a_datetime;			/* compile "push datetime" */

			// NOTE:  We put datetimes in the compile buffer as DTVALs, but when we are going
			//  thru the compiled code, we use ZDATETIME. These structs are equivalent today.
			*(DTVAL *)pCompileBuf = val.tDateTime;		 /* and the datetime */
			pCompileBuf += sizeof(DTVAL);
			break;

		case t_ztime:
			if (pApp->zERRdbl(val.tNumber.val))
			{
				*erroffP = curtok - cflex;
				udfslop=tokslop = 0;
				return ee_baddate;
			}
			*(++pSyntaxStack) = t_ztime;
			*(cf_nextlast=pCompileBuf++) = a_time;			/* compile "push time" */
			*(double *)pCompileBuf = val.tNumber.val; /* and the number representing time */
			pCompileBuf += sizeof(double);
			break;

		case t_date:
			if (val.tDate==ZERRDATE)
			{
				*erroffP = curtok - cflex;
				udfslop=tokslop = 0;
				return ee_baddate;
			}
			*(++pSyntaxStack) = t_date;
			*(cf_nextlast=pCompileBuf++) = a_date;			/* compile "push date" */
			*(long *)pCompileBuf = val.tDate;	/* and the date */
			pCompileBuf += sizeof(long);
			break;

		case t_fld:
			fld=mfbyndx(val.tFldId);
			/* prevent indirect use of query(), ex: foo=query(); bar=len(foo) */
			if (fld->dFlags2 & f2FRMQRY)
			{
				*erroffP = curtok - cflex;
				return ee_qindirect;
			}
			if (fld->dFlags2 & f2DUMMY)
			{
				*erroffP = curtok - cflex;
				return ee_dummy;
			}
			*(++pSyntaxStack) = fld->dFlags&zfNUMERIC ? t_num :
				fld->dFlags&zfLOGICAL ? t_num|TLOG :
				fld->dFlags&zfTEXT ? t_memo :
				fld->dFlags&zfDATE ? t_date :
				fld->dFlags&zfTIME ? t_ztime :
				fld->dFlags&zfDATETIME ? t_datetime :
				fld->dFlags2&f2FRMQRY ? t_query : t_str;
			*(cf_nextlast=pCompileBuf++) = a_fld;	/* compile "push field" */
			*(FLDID *)pCompileBuf = val.tFldId; /* and the field number */
			pCompileBuf += sizeof(FLDID);			
			break;

		case t_file:
			file=MFFiles[val.tInteger];
			*(++pSyntaxStack) = t_file;
			*(cf_nextlast=pCompileBuf++) = a_file;	/* compile "push file" */
			*(int *)pCompileBuf = val.tInteger; /* and the file number */
			pCompileBuf += sizeof(int);				// OK for 32 bits
			break;

		case t_func:
			*(++pSyntaxStack) = 0; 		/* push initial "prevtype" to syn stack */
			*(++pSyntaxStack) = 0; 		/* push initial arg count to syn stack */
			*(SSFUNCNUM *)(++pSyntaxStack) = val.tInteger; /* function number */
			pSyntaxStack+=sizeof(SSFUNCNUM);
			*(pSyntaxStack) = t_func;	/* push function token to syn stk */
			/* if find query(), save position for restrict() */
			if (val.tInteger == f_query)
				querypos = curtok - cflex;
			break;

		case t_true:
			*(++pSyntaxStack) = (char)(t_num|TLOG);
			*(cf_nextlast=pCompileBuf++) = a_true;	/* compile "push TRUE" */
			break;

		case t_false:
			*(++pSyntaxStack) = (char)(t_num|TLOG);
			*(cf_nextlast=pCompileBuf++) = a_false; /* compile "push FALSE" */
			break;

		case t_keyword:
			ASSERT(val.tKeyword.skeytype<256);
			ASSERT(val.tKeyword.ckeytype<256);
			ASSERT(val.tKeyword.numericVal<256);

			*(++pSyntaxStack) = (char)val.tKeyword.skeytype;
			*(cf_nextlast=pCompileBuf++) = a_keyword;    // Push the keyword action
			*(pCompileBuf++) = val.tKeyword.ckeytype;	// Followed by the keyword type
			*pCompileBuf = val.tKeyword.numericVal; /* push the numeric value of the keyword */
			pCompileBuf++;
            break;
            
		default:
			if ((tok==t_comma || tok==t_rp) &&
					(*pSyntaxStack==t_lp || *pSyntaxStack==t_comma))
			{ /* argument missing */
				*(++pSyntaxStack) = t_noarg;
				*(cf_nextlast=pCompileBuf++) = a_noarg;
			}
			*(++pSyntaxStack) = tok;
			break;
		}
		CKSYNOFLO;		/* check for syntax stack overflow */
		done = FALSE;
		while (!(done || cf_cpoflo || cf_synoflo))
		{
			cf_lastcp = cf_nextlast;
			cf_ecode = FALSE;
			if (rule1())
			{
				done = TRUE;
				continue;
			}
			if (rule2())
				continue;
			if (cf_ecode)
			{
				bad = done = cf_ecode;
				continue;
			}
			if (rule3())
				continue;
			if (cf_ecode)
			{
				bad = done = cf_ecode;
				continue;
			}
			if (rule4())
				continue;
			if (cf_ecode)
			{
				bad = done = cf_ecode;
				continue;
			}
			if (rule5())
				continue;
			if (cf_ecode)
			{
				bad = done = cf_ecode;
				continue;
			}
			if (rule6())
				continue;
			if (rule7())
			{
				bad = done = cf_ecode;
				continue;
			}
			break;
		}
		if (done)
			break;
		prevtok = curtok;
		cf_lastcp = cf_nextlast;
		curtok = inp; /* token() updates inp to point to start of next */
		tok=ltoken(&inp, &val, &vallen,TRUE);
	}
	*erroffP = (bad==ee_argc2 || bad==ee_argc ||
		bad==ee_argt || bad==ee_argf ?
			prevtok : curtok)-cflex;

	done = cf_cpoflo ? ee_rpnoflo : cf_synoflo ? ee_synoflo : bad;
	if (done)
		udfslop=tokslop = 0;	/* no slop if compile error */
	return done;
}

