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
// xeval.c		translation "evaluation" module - to decompile
//				engine-evaluatable expressions for R&R calcs
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/CFCOMP/RSW/XEVAL.CPV  $
// 
//    Rev 1.15   May 13 2003 11:28:00   Admin
// Some bug, plus cosmetics
// 
//    Rev 1.14   Jun 05 2001 10:30:54   nhubacker
// Look fo AlwaysRR flag
// 
//    Rev 1.13   30 Nov 1998 13:49:32   wrr
// Added WO134154
// 
//    Rev 1.12   08 Oct 1996 16:45:14   amh
// Arp 1.0 U02 merged to trunk
// 
// 
// 
//    Rev 1.9.1.1   19 Sep 1996 16:54:40   jpb
// fix getFormat - return NULL format pointer if name pointer is NULL
// 
//    Rev 1.9.1.0   01 Jul 1996 16:23:26   jpb
// fix RSW 1859 (max char literal len)
// 
//    Rev 1.11   19 Sep 1996 16:56:22   jpb
// fix getFormat - return NULL format pointer if name pointer is NULL
// 
//    Rev 1.10   03 Jul 1996 15:45:26   jpb
// merge 1.9.1.0 to trunk (rsw 1859)
// 
//    Rev 1.9.1.0   01 Jul 1996 16:23:26   jpb
// fix RSW 1859 (max char literal len)
// 
//    Rev 1.9   06 Mar 1996 13:46:52   jpb
// add some omitted functions to the trans table
// 
//    Rev 1.8   04 Mar 1996 15:09:12   pjm
// Carried 6.5 DT changes into 7.0.
// 
//    Rev 1.7   01 Mar 1996 14:57:44   jpb
// fix rsw 2121
// 
//    Rev 1.6   05 Jan 1996 16:35:22   par
// All explicitly linked modules and external initialization files are located
// with the explicit file manager.  This will provide a central location where
// file paths can be adjusted.
// 
//    Rev 1.5   26 Sep 1995 15:21:04   pjm
// RSW composite class changes.
// 
//    Rev 1.4   18 Sep 1995 15:00:44   jpb
// move funcs to CRrComposite
// 
//    Rev 1.3   17 Aug 1995 15:18:08   mjs
// Restored xlower().
// 
//    Rev 1.2   15 Aug 1995 16:32:44   sjo
// Changes for RSW compiles.
// 
//    Rev 1.1   25 Jul 1995 16:30:36   sjo
// First wave of architecture changes.
// 
//    Rev 1.0   16 Mar 1995 16:22:36   sbc
// Initial revision.
// 
//    Rev 1.11   19 Dec 1994 11:46:08   dlm
// Fixes RSW bug reported on 12/19/94 by dlm.  Change xevalall() to follow
//  dNxtEval links (not dNxtFld)!
// 
//    Rev 1.10   10 Nov 1994 17:15:34   jpb
// call changed routine for INI section name
// 
//    Rev 1.9   04 Nov 1994 17:49:22   jpb
// Use decimal indicator in format numeric literals
// 
//    Rev 1.8   03 Oct 1994 09:50:32   smh
// Don't attempt translations if there's no active data source.
// That's true when Create Report Using (masterless) Template.
// 
//    Rev 1.7   27 Sep 1994 15:33:30   sjo
// This fixes a problem with translated calcs.  The problem was that an int
// divided by an int would return an int.  Users who would type in 'field/2.0'
// would get 'field/2' and an int result. I added some code to always add .00
// onto the end of a numeric. Fixes RSW crock 891.
// 
//    Rev 1.6   31 Jul 1994 17:17:46   smh
// Masterless reports can have no active data source, so check for NULL
// before accessing ActiveDS or using DBIgetActiveDataSource() return.
// 
//    Rev 1.5   17 Jan 1994 15:37:54   jpb
// Add support for translation of UDFs
// 
//    Rev 1.4   13 Jan 1994 15:11:28   jpb
// support translation of IIF by ignoring branch instructions in compiled code
// 
//    Rev 1.3   28 Dec 1993 15:40:56   nwh
// Removed temporary extern declaration
// 
//    Rev 1.2   09 Dec 1993 15:46:06   say
// Revamp for ODBC
// 
//    Rev 1.1   08 Dec 1993 12:27:34   nwh
// Changes for ODBC section of RSWSQL.INI file
// 
//    Rev 1.0   14 Oct 1993 10:16:36   sjo
// Initial revision.
// ****************************************************************************
#include "product.h"

//
// Make a definition for this module.
//
#define _XEVAL_C_
#include "rrdoc.h"
#include "rr.h"
#include "ctype.h"
#include "stdio.h"		// for sprintf
#include "_cfcomp.h"
#include "cfeval.h"
#include "_cfmisc.h"
#include "mfmisc.h"
#include "mffile.h"
#include "mffield.h"
#include "mfdata.h"
#include "util.h"
#include "wutil.h"
#include "eng.h"
#include "dbi.h"
#include "sql.h"		// ODBC header for SQL_MAX_DSN_LENGTH
#include "global.h"
#include "qelib.h"
#include "explmgr.h"	// CExplicitLibraryManager


typedef struct xlate
{
	LPSTR name;	 	// opcode or function name
	LPSTR format;	// translation format string
} XLATE;

// xlate table for operators, indexed by action code
static XLATE  xOp[MAX_ACTION+1] =
			  {
				  Txplus,NULL,		// addition
				  Txminus,NULL, 	// subtraction
				  Txdiv,NULL,		// division
				  Txmul,NULL,		// multiplication
				  Txexp,NULL,		// exponentiation
				  Txuplus,NULL, 	// unary plus
				  Txuminus,NULL,	// unary negative
				  Txpct,NULL,		// percentage
				  NULL,NULL,		// return
				  NULL,NULL,		// push number
				  NULL,NULL,		// push field reference
				  NULL,NULL,		// push file reference
				  NULL,NULL,		// execute funtion
				  NULL,NULL,		// push TRUE
				  NULL,NULL,		// push FALSE
				  Txeq,NULL,		// test for equality
				  Txneq,NULL,		// test for inequality
				  Txle,NULL,		// test for less than or equal to
				  Txge,NULL,		// test for greater than or equal to
				  Txlt,NULL,		// test for less than
				  Txgt,NULL,		// test for greater than
				  Txand,NULL,		// AND
				  Txor,NULL,		// OR
				  Txnot,NULL,		// NOT
				  Txcat,NULL,		// + (normal concatenation)
				  Txtcat,NULL,		// - (trimmed concatenation)
				  Txsubstr,NULL,	// $ (substring)
				  NULL,NULL,		// push string
				  NULL,NULL,		// push "no argument"
				  Txdatedif,NULL,	// subtract two dates
				  Txplusdays,NULL,	// add date and number of days
				  Txsubdays,NULL,	// subtract number of days from date
				  NULL,NULL,		// argument separator
				  NULL,NULL,		// push prev-field reference
				  NULL,NULL,		// push empty memo
				  NULL,NULL,		// push user function argument
				  NULL,NULL,		// execute user function
				  NULL,NULL,		// push user function argument (prev)
				  NULL,NULL,		// push @now value
				  NULL,NULL,		// branch on false
				  NULL,NULL,		// branch
				  Txdateformat,NULL,	// date literal
				  Txdatetimeformat,NULL,	// a_datetime
				  Txtimeformat,NULL,		// a_time
				  NULL,NULL,		// a_keyword
			  };

// xlate table for functions, indexed by function code
static XLATE  xFunc[MAX_FUNC+1] =
			  {
				  TMINSTR,NULL,
				  TMAXSTR,NULL,
				  TEXP,NULL,
				  TINT,NULL,
				  TLOGSTR,NULL,
				  TRND,NULL,
				  TSQRT,NULL,
				  TAT,NULL,
				  TLEN,NULL,
				  TLOWER,NULL,
				  TUPPER,NULL,
				  TSPACE,NULL,
				  TSUBSTR,NULL,
				  TFTRIM,NULL,
				  TASC,NULL,
				  TCHR,NULL,
				  TSTR,NULL,
				  TVAL,NULL,
				  TDATE,NULL,
				  TCDOW,NULL,
				  TCMONTH,NULL,
				  TCTOD,NULL,
				  TDAY,NULL,
				  TDOW,NULL,
				  TDTOC,NULL,
				  TMONTH,NULL,
				  TYEAR,NULL,
				  TTIME,NULL,
				  TPAGENO,NULL,
				  TRECNO,NULL,
				  TISALPHA,NULL,
				  TISLOWER,NULL,
				  TISUPPER,NULL,
				  TLTRIM,NULL,
				  TRTRIM,NULL,
				  TLEFT,NULL,
				  TRIGHT,NULL,
				  TREPLICA,NULL,
				  TSTUFF,NULL,
				  TABS,NULL,
				  TMOD,NULL,
				  TADDDAYS,NULL,
				  TADDWKS,NULL,
				  TADDMONS,NULL,
				  TADDYRS,NULL,
				  TSUBDAYS,NULL,
				  TSUBWKS,NULL,
				  TSUBMONS,NULL,
				  TSUBYRS,NULL,
				  TDAYSBTW,NULL,
				  TWKSBTWN,NULL,
				  TMONSBTW,NULL,
				  TYRSBTWN,NULL,
				  TWEEK,NULL,
				  TDQTR,NULL,
				  TQTR,NULL,
				  TIIF,NULL,
				  TINRNG,NULL,
				  TINLST,NULL,
				  TFLIP,NULL,
				  TTRANSFORM,NULL,
				  TCAPS,NULL,
				  TCASE,NULL,
				  TERROR,NULL,
				  TSNDX,NULL,
				  TWDCNT,NULL,
				  TWORD,NULL,
				  TSPELLN,NULL,
				  TPREV,NULL,
				  TCOPY,NULL,
				  TQUERY,NULL,
				  TSTRSEARCH,NULL,
				  TSTRCOUNT,NULL,
				  TSTRREP,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  TLIKE,NULL,
				  TRRUNIN,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  TRIPARAM,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  NULL,NULL,
				  TCDLL,NULL,
				  NULL,NULL,		  // SQLEXP not translatable
				  NULL,NULL,	// rr
				  NULL,NULL,	// libn
				  NULL,NULL,	// repn
				  NULL,NULL,	// udfn
				  NULL,NULL,	// half
				  NULL,NULL,	// monl
				  NULL,NULL,	// aged
				  NULL,NULL,	// past
				  NULL,NULL,	// futu
				  NULL,NULL,	// over
				  NULL,NULL,	// ndow
				  NULL,NULL,	// pdow
				  NULL,NULL,	// isnull
				  NULL,NULL,	// dateadd
				  NULL,NULL,	// datediff
				  NULL,NULL,	// datename
				  NULL,NULL,	// datepart
				  NULL,NULL,	// dateadddt
				  NULL,NULL,	// dateaddt
				  NULL,NULL,	// tottime
				  NULL,NULL,	// dttoc
				  NULL,NULL,	// ttoc
				  NULL,NULL,	// dtlookup
				  NULL,NULL,	// ttos
				  NULL,NULL,	// ctdt
				  NULL,NULL,	// ctos
				  NULL,NULL,	// ctot
				  NULL,NULL,	// stoc
				  TNOW,NULL		// now
			  };


typedef struct
{
	LPSTR	name ; 	// ODBC function name
	int		type ;	// ODBC function type
	long	mask ;	// ODBC function bit
	BOOL	ok ;	// TRUE if supported
} SUPPORT ;

// list of ODBC functions, their type, bit, and 'supported?' boolean
static SUPPORT ODBC_list[] =
	{
	{"ABS",		qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_ABS,		FALSE},
	{"ACOS",	qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_ACOS,		FALSE},
	{"ASIN",	qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_ASIN,		FALSE},
	{"ATAN",	qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_ATAN,		FALSE},
	{"ATAN2",	qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_ATAN2,		FALSE},
	{"CEILING",	qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_CEILING,	FALSE},
	{"COS",		qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_COS,		FALSE},
	{"COT",		qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_COT,		FALSE},
	{"EXP",		qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_EXP,		FALSE},
	{"FLOOR",	qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_FLOOR,		FALSE},
	{"LOG",		qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_LOG,		FALSE},
	{"MOD",		qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_MOD,		FALSE},
	{"SIGN",	qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_SIGN,  	FALSE},
	{"SIN",		qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_SIN,		FALSE},
	{"SQRT",	qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_SQRT,  	FALSE},
	{"TAN",		qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_TAN,		FALSE},
	{"PI",		qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_PI,		FALSE},
	{"RAND",	qeINFO_NUMERIC_FUNCTIONS,	qeSQL_FN_NUM_RAND,  	FALSE},

	{"CONCAT",	qeINFO_STRING_FUNCTIONS,	qeSQL_FN_STR_CONCAT,	FALSE},
	{"INSERT",	qeINFO_STRING_FUNCTIONS,	qeSQL_FN_STR_INSERT,	FALSE},
	{"LEFT",	qeINFO_STRING_FUNCTIONS,	qeSQL_FN_STR_LEFT,		FALSE},
	{"LTRIM",	qeINFO_STRING_FUNCTIONS,	qeSQL_FN_STR_LTRIM,		FALSE},
	{"LENGTH",	qeINFO_STRING_FUNCTIONS,	qeSQL_FN_STR_LENGTH,	FALSE},
	{"LOCATE",	qeINFO_STRING_FUNCTIONS,	qeSQL_FN_STR_LOCATE,	FALSE},
	{"LCASE",	qeINFO_STRING_FUNCTIONS,	qeSQL_FN_STR_LCASE,		FALSE},
	{"REPEAT",	qeINFO_STRING_FUNCTIONS,	qeSQL_FN_STR_REPEAT,	FALSE},
	{"REPLACE",	qeINFO_STRING_FUNCTIONS,	qeSQL_FN_STR_REPLACE,	FALSE},
	{"RIGHT",	qeINFO_STRING_FUNCTIONS,	qeSQL_FN_STR_RIGHT,		FALSE},
	{"RTRIM",	qeINFO_STRING_FUNCTIONS,	qeSQL_FN_STR_RTRIM,		FALSE},
	{"SUBSTRING", qeINFO_STRING_FUNCTIONS,	qeSQL_FN_STR_SUBSTRING,	FALSE},
	{"UCASE",	qeINFO_STRING_FUNCTIONS,	qeSQL_FN_STR_UCASE,		FALSE},
	{"ASCII",	qeINFO_STRING_FUNCTIONS,	qeSQL_FN_STR_ASCII,		FALSE},
	{"CHAR",	qeINFO_STRING_FUNCTIONS,	qeSQL_FN_STR_CHAR,		FALSE},

	{"CONVERT",	qeINFO_CONVERT_FUNCTIONS,	qeSQL_FN_CVT_CONVERT,	FALSE},

	{"NOW",		qeINFO_TIMEDATE_FUNCTIONS,	qeSQL_FN_TD_NOW,		FALSE},
	{"CURDATE",	qeINFO_TIMEDATE_FUNCTIONS,	qeSQL_FN_TD_CURDATE,	FALSE},
	{"DAYOFMONTH", qeINFO_TIMEDATE_FUNCTIONS, qeSQL_FN_TD_DAYOFMONTH,	FALSE},
	{"DAYOFWEEK", qeINFO_TIMEDATE_FUNCTIONS, qeSQL_FN_TD_DAYOFWEEK,	FALSE},
	{"DAYOFYEAR", qeINFO_TIMEDATE_FUNCTIONS, qeSQL_FN_TD_DAYOFYEAR,	FALSE},
	{"MONTH",	qeINFO_TIMEDATE_FUNCTIONS,	qeSQL_FN_TD_MONTH,		FALSE},
	{"QUARTER",	qeINFO_TIMEDATE_FUNCTIONS,	qeSQL_FN_TD_QUARTER,	FALSE},
	{"WEEK",	qeINFO_TIMEDATE_FUNCTIONS,	qeSQL_FN_TD_WEEK,		FALSE},
	{"YEAR",	qeINFO_TIMEDATE_FUNCTIONS,	qeSQL_FN_TD_YEAR,		FALSE},
	{"CURTIME",	qeINFO_TIMEDATE_FUNCTIONS,	qeSQL_FN_TD_CURTIME,	FALSE},
	{"HOUR",	qeINFO_TIMEDATE_FUNCTIONS,	qeSQL_FN_TD_HOUR,		FALSE},
	{"MINUTE",	qeINFO_TIMEDATE_FUNCTIONS,	qeSQL_FN_TD_MINUTE,		FALSE},
	{"SECOND",	qeINFO_TIMEDATE_FUNCTIONS,	qeSQL_FN_TD_SECOND,		FALSE},

	{"USERNAME", qeINFO_SYSTEM_FUNCTIONS,	qeSQL_FN_SYS_USERNAME,	FALSE},
	{"DBNAME",	qeINFO_SYSTEM_FUNCTIONS,	qeSQL_FN_SYS_DBNAME,	FALSE},
	{"IFNULL",	qeINFO_SYSTEM_FUNCTIONS,	qeSQL_FN_SYS_IFNULL,	FALSE},

	{ NULL, 0, 0, FALSE},
	}  ;


void CRrComposite::cleardexp(int doit, LPMFFIELD fld)
{
	ASSERT( m_pDoc );
	ASSERT( m_pDoc->IsKindOf(RUNTIME_CLASS(CRrDoc)) );

	if (doit)
	{
		if (fld->dRecU.calcS.dExpX)
			m_pDoc->globalFree(fld->dRecU.calcS.dExpX);
		fld->dRecU.calcS.dExpX = NULL;
	}
}

void CRrComposite::clearstack(void)
{ // clean up eval stack string memory
	ASSERT( m_pDoc );
	ASSERT( m_pDoc->IsKindOf(RUNTIME_CLASS(CRrDoc)) );

	while (stackPtr > (LPSTR *)CfEvalStack)
		m_pDoc->globalFree(*(--stackPtr));
}

int CRrComposite::pushstr(LPSTR s)
{
	ASSERT( m_pDoc );
	ASSERT( m_pDoc->IsKindOf(RUNTIME_CLASS(CRrDoc)) );

	LPSTR t = m_pDoc->globalAlloc(GMEM_MOVEABLE,lstrlen(s)+1);
	if (t)
	{
		lstrcpy(t,s);
		*(stackPtr++) = t;		// push result
		return (LPSTR)stackPtr > CfEvalStackEnd; // TRUE iff stack overflow
	}
	else
		return TRUE;	  // mem failure
}

int CRrComposite::nextpiece(LPSTR result, LPSTR *fp)
{
	LPSTR r = &result[lstrlen(result)];
	LPSTR f = *fp;
	char c;

	while (c=*f++)
	{
		if (c=='%')
		{ // escape sequence
			c = *f++;	// second char of sequence
			if (c=='%')
				*r++ = c;	// pass % thru
			else
			{ // interpret escape sequence
				if (isdigit(c))
				{
					*fp = f;
					*r = '\0';  // terminate extended string
					return c-'0';
				}
			}
		}
		else
			*r++ = c;
	}
	*r = '\0';
	*fp = f;
	return 0;
}

//***************************************************************************
//	fillODBC()
//	fill the ok element of each element of ODBC_list table with
//	TRUE if this element is supported by ODBC and FALSE otherwise
//***************************************************************************

void CRrComposite::fillODBC()
{
	int k ;
	long mask ;

	for (k = 0 ; ODBC_list[k].name != NULL ; k++)
	{
		mask = DBIgetInfoLong(ODBC_list[k].type) ;
		if (mask & ODBC_list[k].mask)
			ODBC_list[k].ok = TRUE ;
		else
			ODBC_list[k].ok = FALSE ;
	}
}

//***************************************************************************
//	parseODBC()
//  parse the ODBC rule in cfstr4 and modify it to put {fn X()} around
//	each function call X.  Also check with ODBC to see if X is supported;
//	If not, clear the rule in cfstr4.
//	Note: X is considered a function call if it is all alphabetic characters
//	followed immediately by a left parenthesis.
//***************************************************************************

void CRrComposite::parseODBC()
{
	LPSTR p = cfstr4 ;
	LPSTR p1 ;
	char c ;
	LPSTR f ;
	int n, k ;
	static char open[] = "{fn " ;
	static char close[] = "}" ;

	while (c = *p++)
	{
		if (isalpha(c))
		{ // possibly start of function
			f = p-1 ;
			while (isalpha(c = *p++)) ;
			n = p - f - 1 ;
			if (c == '(')
			{ // function if followed by (
				for (k = 0 ; ODBC_list[k].name != NULL ; k++)
				{  // check this function is supported
					if (lstrnicmp(f, ODBC_list[k].name, n) == 0)
						break ;
				}
				if (ODBC_list[k].ok)
				{ // insert {fn ... } around function call
					lmemmove(f + strlen(open), f, lstrlen(f)+1) ;
					lmemmove(f, open, strlen(open)) ;
					p += strlen(open) ;
					p1 = p ;
					// find matching )
					k = 1 ;
					while (c = *p1++)
					{
						if (c == ')')
						{
							if (--k == 0)
							{
								lmemmove(p1 + strlen(close), p1, lstrlen(p1)+1) ;
								lmemmove(p1, close, strlen(close)) ;
								break ;
							}
						}
						else if (c == '(')
							k++ ;
					}
				}
				else
				{  // not supported (or not in list)
					*cfstr4 = 0 ;
					return ;
				}
			}
		}
	}
}

LPSTR CRrComposite::getFormat(LPSTR name)
{
	LPSTR	 p;
	char	szDBMS[32];
	ASSERT( m_pDoc );
	ASSERT( m_pDoc->IsKindOf(RUNTIME_CLASS(CRrDoc)) );

	if ( name == NULL )
		return NULL ;		// no name, no format!

	CString csSqlInitFile = theApp.m_elmFileManager.GetSqlInitFile() ;

	// Base section name on DBMS name
	_fstrcpy (szDBMS, DBIgetIniSectionName());

	if (szDBMS[0])
		GetPrivateProfileString( szDBMS, name, "", cfstr4,4000,csSqlInitFile);

	if (!szDBMS[0] || !cfstr4[0])
	{ // no platform specific entry - try common
		GetPrivateProfileString ( Txcomn, name, "", cfstr4,4000,csSqlInitFile);

		if (*cfstr4 == '\0')
		{ // no common entry - try ODBC
			GetPrivateProfileString(Txodbc,name, "", cfstr4,4000,csSqlInitFile);

			if (*cfstr4 != '\0')
				parseODBC() ;		//  check ODBC rule
			if (*cfstr4 == '\0')
				return NULL;		// translation string not present
		}
	}
	p = m_pDoc->globalAlloc(GMEM_MOVEABLE,lstrlen(cfstr4)+1);
	if (p)
		lstrcpy(p,cfstr4);
	else
		iMemFault = TRUE;
	return p;
}

void CRrComposite::freextab(void)
{
	int i;
	XLATE *p;
	ASSERT( m_pDoc );
	ASSERT( m_pDoc->IsKindOf(RUNTIME_CLASS(CRrDoc)) );

	for (i=0, p=xFunc; i<MAX_FUNC+1; i++, p++)
	{
		if (p->format)
			m_pDoc->globalFree(p->format);
		p->format = NULL;
	}
	for (i=0, p=xOp; i<MAX_ACTION+1; i++, p++)
	{
		if (p->format)
			m_pDoc->globalFree(p->format);
		p->format = NULL;
	}
}

// load the translation table for a given platform
void CRrComposite::loadxtab()
{
	int		i;
	XLATE	*p;
	static	char szDS[SQL_MAX_DSN_LENGTH];
	static	BOOL bSeenMemMessage;
	LPSTR	ads;
	ASSERT( m_pDoc );
	ASSERT( m_pDoc->IsKindOf(RUNTIME_CLASS(CRrDoc)) );

	// return if already loaded for this platform
	if ((ads = DBIgetActiveDataSource()) && !_fstrcmp(szDS, ads))
		return;

	iMemFault = FALSE;
	if (szDS[0])
		freextab(); // free current XLATE tables format strings
	fillODBC() ;	// fill ODBC 'supported' table
	for (i=0, p=xFunc; i<MAX_FUNC+1; i++, p++)
		p->format = getFormat(p->name);
	for (i=0, p=xOp; i<MAX_ACTION+1; i++, p++)
		p->format = getFormat(p->name);
	if (iMemFault)
	{ // table mem allocation failure
		if (bSeenMemMessage)	// avoid repetition of error message
//			zwarn1("Insufficient memory for formula translation strings");
			m_pDoc->zwarn1(getString(IDS_0777,0)) ;
		freextab();
		bSeenMemMessage = TRUE;
		szDS[0] = '\0';
	}
	else 
		_fstrcpy(szDS, ads ? ads : ""); // inited for platform
}

int CRrComposite::xsetargs(int acnt)
{
	int		i;
	int		frames=0;

	UCnts[++UFrame] = acnt; // save argument count
	for (i=0; i<UFrame; i++)
		frames += UCnts[i];

	if ((frames+acnt) > UMAXARGS)
	{
		UFrame--;		// undo above increment
		return TRUE;	// not enough room
	}

	for (i=acnt-1; i>=0; i--)
	{
		if (i==acnt-1)
		{ // setting for last argument (from top of eval stack)
			UArgs[frames+i] = (LPSTR)stackPtr;
		}
		else
		{ // not last argument
			UArgs[frames+i] = UArgs[frames+i+1]-sizeof(void *);
		}
	}
	UFirstArg = &UArgs[frames];
	return FALSE;
}

int CRrComposite::xpusharg(int n) 	// n is argument number to push
{
	return pushstr(*(LPSTR *)(UFirstArg[n]-sizeof(void *))); // "push" the pointed to string
}

void CRrComposite::xpopargs(void)
{
	int		i;
	int		frames=0;
	LPSTR	*resdest;
	ASSERT( m_pDoc );
	ASSERT( m_pDoc->IsKindOf(RUNTIME_CLASS(CRrDoc)) );

	for (i=UCnts[UFrame]-1; i>=0; i--)
	{ //free the args pushed for the a_ufunc
		m_pDoc->globalFree(*(LPSTR *)(UFirstArg[i]-sizeof(void *)));
	}
	resdest = (LPSTR *)(UFirstArg[0]-sizeof(void *));
	*resdest = *(stackPtr-1);
	stackPtr = resdest+1;

	UFrame--;
	for (i=0; i<UFrame; i++) frames += UCnts[i];
	UFirstArg = &UArgs[frames];
}

int CRrComposite::xlower(LPSTR pOutPrefix, LPSTR pOutPostfix)
{
	LPSTR fp;

	*pOutPrefix = *pOutPostfix = 0;	// init to empty strings

	loadxtab();
	if (fp=xFunc[f_lower].format)
	{
		if (nextpiece(pOutPrefix,&fp))
		{
			nextpiece(pOutPostfix,&fp);
		}
		return(FALSE);		
	} else
	{
		return(TRUE);	
	}
}

int CRrComposite::xeval(LPSTR in, LPMFFIELD resfld, int doit, LPSTR *xp)
{
	int		action;
	int		argno;
	int		n;
	LPSTR	arg1;
	LPSTR	arg2;
	LPSTR	result;
	LPSTR	fp;
	LPSTR	xcp;
	LPMFFIELD fld;
	LPUDF	u;
	int		udepth = 0;
	char	nbuf[60];
	long	lMaxCharLitLen;
	ASSERT( m_pDoc );
	ASSERT( m_pDoc->IsKindOf(RUNTIME_CLASS(CRrDoc)) );

	if (UserSelect || !DBIgetActiveDataSource())
		return TRUE;	// nothing translatable in select-based report

	result = cfstr4;	// 8000 byte string temp
	if (in==NULL || AlwaysRR)
	{
		cleardexp(doit, resfld);
		return TRUE;	// nonxlatable - need compiled code and udf stack
	}

	xcp = in;
	stackPtr = (LPSTR *)CfEvalStack;
	loadxtab();

	while (TRUE)
	{
		*result = '\0';     // init result
		switch (action=*(xcp++))
		{
		case a_ret: 	  // return
			if (udepth)
			{
				xcp = UStack[--udepth];
				xpopargs();
				break;
			}
			arg1 = *(--stackPtr);
			if ((lstrlen(arg1) > CONTROL_SIZE) ||
					mfexpinfo(arg1,resfld,GETTYPE,FALSE))
			{
				m_pDoc->globalFree(arg1);
				cleardexp(doit, resfld);
				return TRUE;
			}
			if (doit)
			{
				if (resfld->dRecU.calcS.dExpX==NULL)
					resfld->dRecU.calcS.dExpX = arg1;
				else if ((size_t)m_pDoc->globalSize(resfld->dRecU.calcS.dExpX) > _fstrlen(arg1))
				{ // ">" test leaves room for null terminator
					lstrcpy(resfld->dRecU.calcS.dExpX,arg1); // room to reuse
					m_pDoc->globalFree(arg1);
				}
				else
				{ // no room to reuse - free old, save new
					m_pDoc->globalFree(resfld->dRecU.calcS.dExpX);
					resfld->dRecU.calcS.dExpX = arg1;
				}
			}
			else if (xp)
				*xp = arg1;
			return FALSE;
			break;

		  // binary operators
		case a_plus:	  // addition
		case a_minus:	  // subtraction
		case a_div: 	  // division
		case a_mul: 	  // multiplication
		case a_exp: 	  // exponentiation
		case a_pct: 	  // percentage
		case a_eq:		  // test for equality
		case a_neq: 	  // test for inequality
		case a_le:		  // test for less than or equal to
		case a_ge:		  // test for greater than or equal to
		case a_lt:		  // test for less than
		case a_gt:		  // test for greater than
		case a_and: 	  // AND
		case a_or:		  // OR
		case a_cat: 	  // + (normal concatenation)
		case a_tcat:	  // - (trimmed concatenation)
		case a_subst:	  // $ (substring)
		case a_datedif:   // subtract two dates
		case a_plusdays:  // add date and number of days
		case a_subdays:   // subtract number of days from date
			if ((fp=xOp[action].format)==NULL)
			{ // this action not translatable
				clearstack();
				*result = '\0';
				cleardexp(doit, resfld);
				return TRUE;
			}
			arg2 = *(--stackPtr);
			arg1 = *(--stackPtr);
			lstrcat(result, "(");   // avoid precedence problems
			while (argno=nextpiece(result,&fp))
				lstrcat(result,argno==1 ? arg1 : arg2);
			lstrcat(result, ")");
			m_pDoc->globalFree(arg1);
			m_pDoc->globalFree(arg2);
			if (pushstr(result))
			{ // stack oflo or mem fault
				clearstack();
				*result = '\0';
				cleardexp(doit, resfld);
				return TRUE;
			}
			break;

	  // unary operators
		case a_uplus:	  // unary plus
		case a_uminus:	  // unary negative
		case a_not: 	  // NOT
			if ((fp=xOp[action].format)==NULL)
			{ // this action not translatable
				clearstack();
				*result = '\0';
				cleardexp(doit, resfld);
				return TRUE;
			}
			arg1 = *(--stackPtr);
			while (argno=nextpiece(result,&fp))
				lstrcat(result,arg1);
			m_pDoc->globalFree(arg1);
			if (pushstr(result))
			{ // stack oflo or mem fault
				clearstack();
				*result = '\0';
				cleardexp(doit, resfld);
				return TRUE;
			}
			break;

		case a_num: 	  // push number
		{
			char	dig;
			int	is_decimal=((*xcp)>0);
			int i=0;
					
			sprintf(nbuf,"%lG",*(double *)(++xcp));
			// Check to see if nbuf contains only numbers (no decimal places
			//  or exponents), if it does, then add a '.00' on the end.
			//
				
			if (nbuf[0]=='-')
				i=1;					// skip the negative sign
				
			while ((dig=nbuf[i++]) != NULL)
			{
				if (!isdigit(dig))
					is_decimal=FALSE;
			}
				
			if (is_decimal)
			{
				strcat(nbuf,".00");
			}
					
			lstrcpy(result,nbuf);
			xcp += sizeof(double);
			if (pushstr(result))
			{ // stack oflo or mem fault
				clearstack();
				*result = '\0';
				cleardexp(doit, resfld);
				return TRUE;
			}
			break;
		}

		case a_fld: 	  // push field reference
			fld = mfbyndx(*(int *)xcp);
			xcp += sizeof(int);
			if (fld->dFlags&zfCALCULATED)
			{
				if (fld->dRecU.calcS.dExpX)
					lstrcpy(result,fld->dRecU.calcS.dExpX);
				else
				{
					clearstack();
					*result = '\0';
					cleardexp(doit, resfld);
					return TRUE;
				}
			}
			else if ((fld->dRFlags&rfTOTALFLD) || (fld->dFlags&zfMEMO))
			{
				clearstack();
				*result = '\0';
				cleardexp(doit, resfld);
				return TRUE;
			}
			else
			{
				lstrcpy(result,colref(fld,MFFiles[fld->dFileNo],0));
			}
			if (pushstr(result))
			{ // stack oflo or mem fault
				clearstack();
				*result = '\0';
				cleardexp(doit, resfld);
				return TRUE;
			}
			break;

		case a_true:	  // push TRUE
		case a_false:	  // push FALSE
			if (pushstr(action==a_true ? "1" : "0"))
			{ // stack oflo or mem fault
				clearstack();
				*result = '\0';
				cleardexp(doit, resfld);
				return TRUE;
			}
			break;

		case a_str: 	  // push string
			lstrcat(result,"'");
			lmemcpy(result+1, xcp+sizeof(int), n=*(int *)xcp); // 32bit ready
			result[n+1] = '\0';
			xcp += (*(int *)xcp) + sizeof(int);		// 32bit ready
			lstrcat(result,"'");
			lsoft(result);	// soften hard spaces

			lMaxCharLitLen = DBIgetDataSourceMaxCharLiteralLen();

			if ((lMaxCharLitLen && ((n-1)>lMaxCharLitLen)) ||	// string too long
				(pushstr(result)))
			{ // stack oflo or mem fault
				clearstack();
				*result = '\0';
				cleardexp(doit, resfld);
				return TRUE;
			}
			break;

		case a_date:	  // date literal
			sql_date_str(*(long *)xcp,result);
			xcp += sizeof(long);
			if (pushstr(result))
			{ // stack oflo or mem fault
				clearstack();
				*result = '\0';
				cleardexp(doit, resfld);
				return TRUE;
			}
			break;

		case a_datetime:	// not translating datetime literals yet?
			sql_datetime_str(*(long *)xcp, *(double *)(xcp + sizeof(long)), result);
			xcp += sizeof(long) + sizeof(double) ;
			if (pushstr(result))
			{ // stack oflo or mem fault
				clearstack();
				*result = '\0';
				cleardexp(doit, resfld);
				return TRUE;
			}
			break;

		case a_noarg:	  // push "no argument"
			if (pushstr(" ")) // ??
			{ // stack oflo or mem fault
				clearstack();
				*result = '\0';
				cleardexp(doit, resfld);
				return TRUE;
			}
			break;

		case a_argsep:	  // argument separator
			break;			  // no action needed

	  // TBD
		case a_time:		// nor time literals
		case a_keyword:		// not keywords neither
		case a_file:		// push file reference
		case a_pfld:		// push prev-field reference
		case a_mtmemo:		// push empty memo
		case a_ufparg:		// push user function argument (prev)
			clearstack();
			*result = '\0';
			cleardexp(doit, resfld);
			return TRUE;
			break;

		case a_ufarg:	  // push user function argument
			if (xpusharg(*(int *)xcp))
			{ // stack oflo or mem fault
				clearstack();
				*result = '\0';
				cleardexp(doit, resfld);
				return TRUE;
			}
			xcp += sizeof(int);
			break;

		case a_ufunc:	  // execute user function
			n = *(int *)xcp;		// get function number
			n &= 0x7FFF;			// = ~0x8000
			xcp += sizeof(int); 	// add len of func num
			for (u=UDFS; u; u=u->uNext)
				if (n==u->uFuncNo)
					break;
			n = (int)*(xcp++);		// the number of arguments
			if ((!u) || (!u->uExpE) ||	// no udf or udf uncompiled
				!((udepth<UMAXDEPTH) && !xsetargs(n))) // or out of schlitz
			{
				clearstack();
				*result = '\0';
				cleardexp(doit, resfld);
				return TRUE;
			}
			UStack[udepth++] = xcp;
			xcp = u->uExpE;
			break;

		case a_bfalse:	  // branch on false
		case a_branch:	  // branch
			xcp += sizeof(long); // just skip over long branch offset
			break;

		case a_func:	  // execute funtion
			n = *(int *)xcp;		// get function number
			n &= 0x7FFF;			// = ~0x8000
			xcp += sizeof(int); 	// add len of func num
			if ((n > MAX_FUNC) || ((fp=xFunc[n].format)==NULL))
			{
				clearstack();
				*result = '\0';
				cleardexp(doit, resfld);
				return TRUE;	// bag it
			}
			n = (int)*(xcp++);	// the number of arguments
			while (argno=nextpiece(result,&fp))
				lstrcat(result,stackPtr[argno-n-1]);
			for (argno=0; argno<n; argno++)
				m_pDoc->globalFree(*(--stackPtr));
			while (TRUE)
			{ // trim missing trailing argument separators
			  // i.e. turn "substr(s,1,)" into "substr(s,1)"
				n = theApp.lzcutoff(result,' ')-1; // offset to last char in result
				if (result[n--] != ')')
					break;	// can't trim
				while (n>0)
				{
					if (isspace(result[n]))
						n--;
					else
						break;
				}
				if (result[n]==',')
				{
					result[n] = ')';
					result[n+1] = '\0';
				}
				else
					break;
			}
			if (pushstr(result))
			{ // stack oflo or mem fault
				clearstack();
				*result = '\0';
				cleardexp(doit, resfld);
				return TRUE;
			}
			break;
		}
	}
}

void CRrComposite::xevalall(void)
{
	LPMFFIELD fld;

	// only need to do EvalOnce and PerComp
	// as all other chains are page()- or total-related
	for (fld=MFEvalOnce; fld; fld=fld->dNxtEval)
	{
		if ((fld->dFlags&(zfCALCULATED|zfDUPFLD))==zfCALCULATED)
			xeval(fld->dRecU.calcS.dExpE,fld,TRUE,NULL);
	}
	for (fld=MFPerComp; fld; fld=fld->dNxtEval)
	{
		if ((fld->dFlags&(zfCALCULATED|zfDUPFLD))==zfCALCULATED)
			xeval(fld->dRecU.calcS.dExpE,fld,TRUE,NULL);
	}
}


LPSTR CRrComposite::getDateFormat()
{
	return xOp[a_date].format ;
}

LPSTR CRrComposite::getDatetimeFormat()
{
	return xOp[a_datetime].format ;
}

LPSTR CRrComposite::getTimeFormat()
{
	return xOp[a_time].format ;
}
