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
//	The mother of all compile routines - calls lcfprep and lcfcomp, and lexplt,
//	and sets the Picture of resulting calculated fields based on their type.
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/cfcomp/compile.cpv  $
// 
//    Rev 1.6   22 Sep 1995 17:01:54   sjo
// Second round of FLDID changes.
// 
//    Rev 1.5   22 Sep 1995 11:26:26   sjo
// First round of FLDID changes.
// 
//    Rev 1.4   18 Sep 1995 15:00:24   jpb
// move funcs to CRrComposite
// 
//    Rev 1.3   02 Aug 1995 10:01:48   sjo
// I needed to move the include of the class headers from just after the include
// of product.h, to just after the #define of the module name.
// 
//    Rev 1.2   20 Jul 1995 16:42:06   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.1   27 Apr 1995 12:35:34   sjo
// Merge of 6.1.03+.  I say + because I have added some of the time functions
// to this merge, which will be a part of 6.1.04.  I merged the CF directories
// and some H files (for the time function changes).
// 
//    Rev 1.0   16 Mar 1995 16:22:10   sbc
// Initial revision.
// 
//    Rev 1.5   23 Mar 1995 17:01:22   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
//    Rev 1.4   08 Feb 1995 13:28:00   sjo
// Checking in a bunch of files for the first wave of datetime support. These
// sources have support for a dFlags that is a long (not an unsigned int) and
// it recognizes date, time and datetime fields.  It only supports dates at
// this time, because we need calcs, picture types, etc if we are to do time and
// datetime.
// 
// ** First merge of RRW7 took place here.
//
//    Rev 1.3   18 Jan 1995 17:48:10   sjo
// Made changes to remove compiler warnings.
// 
//    Rev 1.2   14 Oct 1994 18:06:24   sjo
// Made a change to suppress error messages when evaluating a sqlexp() during
// readrep. See also explt.c.
// 
//    Rev 1.1   09 Mar 1994 16:57:34   dlm
// Added code related to LOOKUP-function argument checking in secure
//  versions.  See cfcomp.c for details.  Code is conditional on
//  PASSWORD_REQD and comes from Abra branch.
// 
//    Rev 1.0.1.1   25 Jan 1994 15:04:42   dlm
// Conditionalized ABRA modifications for later inclusion on trunk.
// 
//    Rev 1.0.1.0   11 Jan 1994 10:27:32   dlm
// Preparation for LOOKUP function argument restrictions.  See cfcomp.c.
// 
//    Rev 1.0   14 Oct 1993 10:16:14   sjo
// Initial revision.
/*5/28/93		sjo - added support for SQLEXP() pictures.	The problem
							was that lexplt sets the picture. We only want this
							happen when we are creating the calc() or when editing
							and the picture changes.
*/
// ****************************************************************************
#include "product.h"

//
// Make a definition for this module.
//
#define _COMPILE_C_

#include "rrdoc.h"
#include "stdio.h"
#include "string.h"
#include "_cfcomp.h"

#define FLAGS (zfDATE|zfNUMERIC|zfLOGICAL|zfMEMO|zfDATETIME|zfTIME)


#if defined (RSW)
int CRrComposite::lcompile(
LPSTR 	expP,
int *erroffP,
int *rpnlenP,
unsigned long *flagsP,
LPSTR		filnoP,
FLDID *indexP,
LPMFFIELD resfld,
LPUDF resudf,
int mode)
#else
int CRrComposite::lcompile(
		LPSTR		expP,
		int *erroffP,
		int *rpnlenP,
		unsigned long *flagsP,
		LPSTR		filnoP,
		FLDID *indexP,
		LPMFFIELD resfld,
		LPUDF resudf)
#endif
{
  	int ret;
	int ret1 = FALSE;
	int off;
	int curtype;
	int sl, sd;
	unsigned int sf2;
	unsigned long sf;
#if defined (RSW)
	unsigned int spic;
	int comperr=FALSE;
	int exmode;
#endif
	unsigned long pa = 0;
	char st;
	int qerror=FALSE;
	int pos;
	unsigned long flags[7] =
		{
	   	0, zfNUMERIC, zfDATE, zfLOGICAL, zfMEMO, zfDATETIME, zfTIME
		};
	int lengths[7] =
		{
		   FLMAX, 1, 0, 0, FLMAX, 0 , 0
	   };                                                                       
	char types[7] =
		{
			sv_str, sv_dbl, sv_date, sv_dbl|LOGICAL, sv_memo, sv_datetime, sv_time
		};

	stodinit(); 				/* init for date literal compiles */
#if defined(PASSWORD_REQD)
	FirstErr = 0;		// used to prevent Data Dictionary checks after first try
#endif
	if (resfld)
	{
#if defined (RSW)
		spic=resfld->dFldPic;
#endif
		sf = resfld->dFlags;
		sf2 = resfld->dFlags2;
				/* note that dFlags2 is saved but not restored.  If this is
					changed so dFlags2 is restored, you will have to send explt()
					another argument for dFlags2 and set the field's dFlags2
					to this outside of compile() like what is done w/ dFlags.
					Otherwise the f2FRMQRY flag that is propagated in explt()
					will be overwritten.
				*/
		sl = resfld->dLength;
		sd = resfld->dDecPl;
	}
	else if (resudf)
	{
		sf = resudf->uFlags&~f2LOOKUP;
		st = resudf->uType;
	}

	for (curtype=0; curtype<7; curtype++)
	{
		if (resfld)
		{
			resfld->dFlags = flags[curtype];
			resfld->dLength = lengths[curtype];
			resfld->dDecPl = 0;
		}
		else if (resudf)
		{
			resudf->uFlags = flags[curtype];
			resudf->uType = types[curtype];
		}
		if ((ret=lcfprep(expP)) || (ret=lcfcomp(erroffP)))
		{
			if (!curtype)
			{
				ret1 = ret;
				off = *erroffP;
			}
			continue;
		}
		if (resfld) pa = resfld->dFlags&zfPREVARG; /* refs prev(self)? */
#if defined (RSW)
		if (mode==CF_EDIT || mode==CF_CREATE)
			// If we are editing or creating, so the error.
			exmode=(COMPILE | SHOW_ERROR);
		else
			exmode=COMPILE;

		comperr = lexplt(cfrpn,rpnlenP,flagsP,filnoP,indexP,resfld,
							  resudf,exmode);
#else
		lexplt(cfrpn,rpnlenP,flagsP,filnoP,indexP,resfld,resudf);
#endif
		/* check for illegal use of query(), on the offense, first down. */
		qerror = ckquery(resfld, resudf, &pos);
		if (resfld || resudf)
		{
			if (((*flagsP)&FLAGS)==flags[curtype]) break;
		}
		else break;
	}

	if (resfld)
	{
#if defined (RSW)
		/* If we are editing and the user hasnt changed a non-sqlexp calc
			to a new sqlexp calc, then restore the dFldPic.  OR if this calc
			is from a report, the pic has already been set, so restore it.
		*/
		int typechange;

		if ( (resfld->dFlags&FLAGS) == (sf&FLAGS) ) typechange=FALSE;
		else typechange=TRUE;

		if (resfld->dFlags2&f2SQLENG)
			{
			if ( (mode==CF_FROMREP) || ((mode==CF_EDIT) && (!typechange)) )
				resfld->dFldPic=spic;
			else
				{
				if ( ((mode==CF_EDIT) && (typechange)) || (mode==CF_CREATE))
					{
					sl=resfld->dLength;
					sd=resfld->dDecPl;
					}
				}
			}
#endif
		resfld->dFlags = sf|pa;
		resfld->dLength = sl;
		resfld->dDecPl = sd;
	}
	else if (resudf)
	{
		resudf->uFlags &= f2LOOKUP; /* preserve f2LOOKUP from explt */
		resudf->uFlags |= sf;		/* replace flags */
		resudf->uType = st;
	}

	if (qerror)
	{
		*erroffP = pos;
		return qerror;
	}

#if defined (RSW)
	if (comperr) { *erroffP = 1; return (comperr); }
#endif

	if (((resfld==NULL)&&(resudf==NULL)) || (curtype==7))
	{
		if (curtype==7 && ret1==0)
		{ /* foo defined as iif(foo="abc",1,0) type error */
			off = lstrlen(expP);
			ret1 = ee_op;		/* will result in "invalid operation" */
		}
		*erroffP = off;
		return ret1;
	}
	return FALSE;
}


