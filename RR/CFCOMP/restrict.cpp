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
// RESTRICT.C - Check for the illegal use of restricted functions.

//	restrict() - Check compiled code of cf or udf for illegal (or legal)
//					use of a given function.
//	ckquery() - Call restrict() with f_query and evaluate result.
//					Called from compile().
//	cksqleng() - Checks for illegal use of SQLENG function.  This only
//					gets called for SQLENG functions (IE we dont have to check
//					the compiled code to see if it is used, we know it is).
//					Called from lexplt().
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/cfcomp/restrict.cpv  $
// 
//    Rev 1.8   22 Sep 1995 17:25:28   sjo
// Changed parameter to inquery().
// 
//    Rev 1.6   19 Sep 1995 17:56:46   sjo
// Changes made by looking at references to sizeof(int) in all sources for 32
// bit support.
// 
//    Rev 1.5   18 Sep 1995 15:00:38   jpb
// move funcs to CRrComposite
// 
//    Rev 1.4   14 Sep 1995 14:55:48   sjo
// Changes for 32 bit support, mostly for pawing thru compiled code.
// 
//    Rev 1.3   02 Aug 1995 10:01:50   sjo
// I needed to move the include of the class headers from just after the include
// of product.h, to just after the #define of the module name.
// 
//    Rev 1.2   20 Jul 1995 16:42:08   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.1   27 Apr 1995 12:35:36   sjo
// Merge of 6.1.03+.  I say + because I have added some of the time functions
// to this merge, which will be a part of 6.1.04.  I merged the CF directories
// and some H files (for the time function changes).
// 
//    Rev 1.0   16 Mar 1995 16:22:22   sbc
// Initial revision.
// 
//    Rev 1.1   23 Mar 1995 17:01:32   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
// ** First merge of RRW7 took place here.
//
//    Rev 1.0   14 Oct 1993 10:16:20   sjo
// Initial revision.
// ****************************************************************************
#include "product.h"

//
// Make a definition for this module.
//
#define _RESTRICT_C_

#include "rrdoc.h"
#include "stdio.h"
#include "string.h"
#include "_cfcomp.h"
#include "filter.h"
#include "mffield.h"
#include "mfmisc.h"
#include "global.h"

	/* querypos set in cfcomp() - position of query() in function definition */

int CRrComposite::inquery(FLDID fno)
{
	LPSTR x;

	if (MFQFld && (x=MFQFld->dRecU.calcS.dExpE))
	{
		switch (*(x++))
		{
			case a_num:
				x+=(1+sizeof(double));
				break;

			case a_date:
				x+=sizeof(long);
				break;

			case a_datetime:
				x+=sizeof(long);
				x+=sizeof(double);
				break;
				
			case a_time:
				x+=sizeof(double);
				break;
		
			case a_keyword:
				// We have two keyword entries.
				x+=2;
				break;

			case a_str:
				x += (*(int *)x)+sizeof(int);	// OK for 32 bits
				break;

			case a_ret:
				return FALSE;
				break;

			case a_func:
			case a_ufunc:
				x++;
				x+=sizeof(int);						// OK for 32 bits
				break;

			case a_file:
				x+=sizeof(int);						// OK for 32 bits
				break;

			case a_pfld:
			case a_fld:
				if (*(FLDID *)x == fno) return TRUE;
				x+=sizeof(FLDID);						
				break;
			case a_bfalse:
			case a_branch:
				x += sizeof(long);
				break;
		}
	}
	return FALSE;
}


/* Check compiled cf/udf code to see if a function was used illegally. */
/* returns TRUE if function found */
/* currently only used for query() */
int CRrComposite::restrict(
 LPSTR exp,		/* pointer to compiled code */
 int func,		/* function looking for (ex. f_query) */
 int *pos,		/* used to returned error position */
 int *errors	/* used to return any errors */
)	
{
	LPSTR place = exp;		/* use temp so don't change what passed */
	int checking = TRUE;
	int qflag = FALSE;		/* found query()? */

	*pos = 0;
	*errors = FALSE;
							/* read each token 'till end or find what looking for */
	while (checking)
	{
		switch (*(place++))
		{
			case a_num:
				place+=(1+sizeof(double));
				break;

			case a_date:
				place+=sizeof(long);
				break;

			case a_datetime:
				place+=sizeof(long);
				place+=sizeof(double);
				break;
				
			case a_time:
				place+=sizeof(double);
				break;
		
			case a_keyword:
				place+=2;
				break;

			case a_str:
				place += (*(int *)place)+sizeof(int);	// OK for 32 bits
				break;

			case a_ret:
				checking = FALSE;
				break;

			case a_func:
			/* if looking for query(), and found it, set flag and set position */
				if ((func == f_query) && (*(int *)(place) == f_query))
				{
					qflag = TRUE;
					*pos = querypos;
				}
			case a_ufunc:
				place++;
				place+=sizeof(int);					// OK for 32 bits
				break;

			case a_file:
				place+=sizeof(int);					// OK for 32 bits
				break;

			case a_ufarg:
			case a_ufparg:
			case a_pfld:
			case a_fld:								// Looks OK for 32 bits
				place+= sizeof(FLDID);
				break;
			case a_bfalse:
			case a_branch:
				place += sizeof(long);
				break;
		/* There are some cases (ex. a_noarg) that are legal but don't
			require action so they are skipped.  Possibly should put those
			cases in followed by a break; so can put a default: case here
		*/
		}	/* end of switch */

		/* if query() used (and looking for it) */
		if ((qflag) && (func==f_query))
		{
			/* one legal use of query() - make sure compiled code shows it */
			if ((*(exp) != a_noarg) || (*(exp+1) != a_func) ||
					(*(int *)(exp+2) != f_query) || (*(exp+(3+sizeof(int))) != a_ret)) 		// Looks OK for 32 bits
				*errors = ee_query;
			return TRUE;				/* found what looking for */
		}
	}	/* end of while */
	return FALSE;				/* function not found */
}



/* check to see if query() used illegally - the error or FALSE */
int CRrComposite::ckquery(
 MFFIELD *cf,	   /* calculated field editing or creating (or NULL if UDF) */
 UDF *udf,		   /* UDF creating or editing (or NULL) */
 int *pos				/* return error's position in function definition */
)		   
{
	int errors;
					/* check cf direct and back door use of query() */
					/* indirect use checked in cfcomp() */
	if ((cf) && (cf->dFlags2 & f2FRMQRY))
	{
		restrict(cfrpn, f_query, pos, &errors); /* see if query() used */
		if (errors)  return errors;
			/* can't edit a cf to use query() if cf used in another cf */
		else if (fldused(lmfgetndx(cf)))
			return ee_qused;	/* pos set in restrict() */
		else if (MFQFld && inquery(lmfgetndx(cf)))
			return ee_qinquery;
		else if ((!MFQFld) && sxinuse(RpSelEd,RpSelLen,lmfgetndx(cf)))
			return ee_qinquery;
		else return FALSE;	/* query() used legally */
	}
	else if (udf)
	{					/* can't use query() in a udf */
		if (restrict(cfrpn, f_query, pos, &errors))
			return ee_qinuser;
	}
	return FALSE;
}

#if defined (RSW)
/* *******************************************************************
   The following routine takes in a pointer to compiled code and makes
sure the IXSQL function is being used legally.	Legally means ONLY
		IXSQL('string')
 ******************************************************************* */

int CRrComposite::chksqleng (LPSTR exp)
{
	LPSTR place=exp;		/* use place holder in compiled code */

	/* First we expect a string
	*/
	if (*place != a_str)
		return FALSE;
	place++;

	/* Followed by the length of the string and then the string
		itself
	*/
	place += (*(int *)place)+sizeof(int);			// OK for 32 bits

	if (*place != a_func) return FALSE;
	place++;

	/* Next is the ixsql function code.
	*/
	if (*(int *)place != f_ixsql) return FALSE;
	place+=sizeof(int);									// OK for 32 bits

	/* Followed by the number of arguements
	*/
	place++;

	/* Followed by a return code
	*/
	if (*place != a_ret) return FALSE;

	return TRUE;
} /* end of chksqleng() */
#endif
