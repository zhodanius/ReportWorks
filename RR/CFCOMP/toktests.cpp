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
// toktests.c	tests for special tokens
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/cfcomp/toktests.cpv  $
// 
//    Rev 1.7   21 Jan 1998 12:11:52   smh
// OEM20001 merge
// 
//    Rev 1.6.1.0   15 Jan 1998 15:41:04   smh
// RRW 8.0 Abra OEM
// 
//    Rev 1.6   22 Sep 1995 17:02:30   sjo
// Second round of FLDID changes.
// 
//    Rev 1.5   18 Sep 1995 15:00:42   jpb
// move funcs to CRrComposite
// 
//    Rev 1.4   15 Aug 1995 16:34:52   sjo
// Changes for RSW compiles.
// 
//    Rev 1.3   02 Aug 1995 10:01:38   sjo
// I needed to move the include of the class headers from just after the include
// of product.h, to just after the #define of the module name.
// 
//    Rev 1.2   31 Jul 1995 13:51:38   sjo
// Another round of recompiling.
// 
//    Rev 1.1   20 Jul 1995 16:41:58   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.0   16 Mar 1995 16:22:26   sbc
// Initial revision.
// 
//    Rev 1.2   04 Nov 1994 17:47:32   jpb
// Slight change to compiled code for push number to remember if user
// entered a decimal point
// 
//    Rev 1.1   09 Mar 1994 14:23:28   dlm
// Added code, conditional on RECORD_FILTER, to allow ambiguous field
//  references in calc-field formulas when compile an Abra-style record
//  filter.
// 
//    Rev 1.0.1.0   28 Feb 1994 09:56:24   dlm
// Added code to disambiguate field-name tokens when MFQDisambiguate is
//  TRUE.  This is used to allow the presence of a "filter" field of the
//  same name in every file of a collection of files and to use the name
//  of that filter field in a record-level filter expression.  This code
//  will select the master-file's copy of the field if more than one file
//  contains the field.  Ambiguity is still an error if the master file
//  doesn't contain the ambiguous field reference.
// 
//    Rev 1.0   14 Oct 1993 10:16:22   sjo
// Initial revision.
// 10/16/92 - say - merge RRW1 1.0.29
// ****************************************************************************
#include "product.h" 
//
// Make a definition for this module.
//
#define _TOKTESTS_C_

#include "rrdoc.h"
#include "rr.h"
#include "string.h"
#include "math.h"
#include "_cfcomp.h"
#include "_cfmisc.h"
#include "mfmisc.h"
#include "util.h"

// extern unsigned int MFQDisambiguate;		// temp - move to some header *************************

int CRrComposite::lanumber(LPSTR tok,TOKVAL *valP)
{
	int i;
	int dots=0;
	char c;
	char buf[100];

	valP->tNumber.dec = 0;
	for (i=0; c=tok[i]; i++)
	{ /* check for digit and at most one decimal point */
		if (c==CDOT)
		{
			if (dots++) return FALSE;
			// We will count the decimal place, too, to keep track
			// of what is entered as int vs. real.  It is passed along
			// in the compiled code (after the a_num opcode), and is only
			// used by peval, which wants to know how many decimal places
			// were entered for a numeric literal in order to default the
			// number of decimal places in the result picture.
			valP->tNumber.dec++;
		}
		else
		{
			if (c<'0' || c>'9') return FALSE;
			if (dots) valP->tNumber.dec++;
		}
	}
	lstrncpy(buf,tok,100);
	buf[99] = 0;
	valP->tNumber.val = atof(buf);
	return TRUE;
}

#ifdef RSW
int CRrComposite::ckfld(LPSTR tok,TOKVAL *valP,int qualcheck,int unqualified)
{
	CRrApp *pApp = (CRrApp *)AfxGetApp();
	char filpart[TOKLEN+1];
	char fldpart[TOKLEN+1];
	LPSTR p;
	int fnum=-1;
	LPMFFIELD fld, tfld;
	LPMFFILE f;
	int lenqual=0;

	filpart[0] = '\0';      /* init to no qualifier */

	if ((!unqualified) && (p=lstrchr(tok,'.')))
	{ /* imbedded . in string */
		pApp->lzmemcpy(filpart,tok,p-tok);	/* move file part */
		filpart[lenqual=(p-tok)] = '\0';        /* terminate file part */
		filpart[MAXALIAS-1] = '\0';/* look at max of 8 chars of file part */

		for (fnum=0; fnum<MFMAXFILES; fnum++)
		{
			if (!(f=MFFiles[fnum])) continue;
			if (!lstrcmpi(filpart,f->mAlias)) break;
		}
		if (fnum==MFMAXFILES)
		{
			if (MFAName && !lstrcmpi(filpart,MFAAlias)) fnum = fnMEMO;
			else return FALSE;
		}

		lstrcpy(fldpart,&tok[p-tok+1]); /* move field part */
	} else lstrcpy(fldpart,tok);		/* check whole token */

	for (fld=MFFields, valP->tFldId=0; fld;
		 fld=fld->dNxtFld, valP->tFldId++)
	{
		if ((fld->dFlags&zfDUPFLD) || (!fld->dCNameP) ||
			((!AllFields) && (fld->dTemp.tempI==-1))) continue;
		if ((fnum==-1 || fnum==fld->dFileNo) &&
			!lstrcmpi(fldpart,fld->dCNameP))
		{
			if ((fnum==-1) && qualcheck)
			{ /* see if name is unique */
				for (tfld=fld->dNxtFld; tfld; tfld=tfld->dNxtFld)
				{
					if ((tfld->dFlags&zfDUPFLD) || (!tfld->dCNameP) ||
						((!AllFields) && (tfld->dTemp.tempI==-1))) continue;
					if (!lstrcmpi(fldpart,tfld->dCNameP)) valP->tFldId=NOID;
				}
			}
			if (lenqual<(MAXALIAS-1))
			{
				tokslop += (MAXALIAS-1-lenqual); /* alias part of tokslop */
				if (!lenqual) tokslop += 1; /* 1 char connector (.) */
			}
			if (fld->dFlags&zfNOTinREC) /* in recs can't grow */
				tokslop += (MAXCNAME-1-strlen(fldpart)); /* field part */
			return TRUE;
		}
	}

	return FALSE;
}

int CRrComposite::lafield(LPSTR tok,TOKVAL *valP,int qualcheck)
{ /* first, try assuming not alias-qualified, then assuming so */
	return ckfld(tok,valP,qualcheck,TRUE) || ckfld(tok,valP,qualcheck,FALSE);
}
#else
int CRrComposite::lafield(LPSTR tok,TOKVAL *valP,int qualcheck)
{
	CRrApp *pApp = (CRrApp *)AfxGetApp();
	char filpart[TOKLEN+1];
	char fldpart[TOKLEN+1];
	LPSTR p;
	int fnum=-1;
	LPMFFIELD fld, tfld;
	LPMFFILE f;
	int lenqual=0;
 #if defined(RECORD_FILTER)
	int ambiguous = FALSE;
	int oldtFldId;
 #endif
 
	filpart[0] = '\0';      /* init to no qualifier */

	if ((p=lstrchr(tok,':')) && *(p+1)==':')
	{ /* imbedded :: in string */
		pApp->lzmemcpy(filpart,tok,p-tok);	/* move file part */
		filpart[lenqual=(p-tok)] = '\0';        /* terminate file part */
		filpart[MAXALIAS-1] = '\0';/* look at max of 8 chars of file part */

		for (fnum=0; fnum<MFMAXFILES; fnum++)
		{
			if (!(f=MFFiles[fnum])) continue;
			if (!lstrcmpi(filpart,f->mAlias)) break;
		}
		if (fnum==MFMAXFILES)
		{
			if (MFAName && !lstrcmpi(filpart,MFAAlias)) fnum = fnMEMO;
			else return FALSE;
		}

		lstrcpy(fldpart,&tok[p-tok+2]); /* move field part */
	}
	else lstrcpy(fldpart,tok);		  /* check whole token */

	for (fld=MFFields, valP->tFldId=0; fld;
			fld=fld->dNxtFld, valP->tFldId++)
	{
		if ((fld->dFlags&zfDUPFLD) || (!fld->dCNameP) ||
			((!AllFields) && (fld->dTemp.tempI==-1))) continue;
		if ((fnum==-1 || fnum==fld->dFileNo) &&
				!lstrcmpi(fldpart,fld->dCNameP))
		{
			if ((fnum==-1) && qualcheck)
			{ /* see if name is unique */
 #if defined(RECORD_FILTER)
				if (!MFQDisambiguate			// if we're not doing record filter
				 || (fld->dFileNo != 0))		// or match is not from master file, keep looking
				{
					oldtFldId = valP->tFldId;	// remember first match in case we need it
					valP->tFldId++;		// we'll be resuming our search from next field
					for (tfld=fld->dNxtFld; tfld;
							tfld=tfld->dNxtFld, valP->tFldId++)	// keep counting fields
 #else
 				{
					for (tfld=fld->dNxtFld; tfld; tfld=tfld->dNxtFld)
 #endif
					{
						if ((tfld->dFlags&zfDUPFLD) || (!tfld->dCNameP) ||
							((!AllFields) && (tfld->dTemp.tempI==-1))) continue;
						if (!lstrcmpi(fldpart,tfld->dCNameP))	// if we find a second match
						{
 #if defined(RECORD_FILTER)
							if (MFQDisambiguate)				// but we're doing record filter
							{
								if (tfld->dFileNo == 0)
								{
									ambiguous = FALSE;			// pretend un-ambiguity
									// 7/22/97 MFC - ABRAFIX: COnversion to RRW 8.0
									// oldtInteger = valP->tFldId;
									oldtFldId = valP->tFldId;	// and use master-file match
									break;						// and stop looking further
								}
								else							// not from master
								{
									ambiguous = TRUE;			// remember that there was a 2nd match
									continue;					// and keep looking for a master file match
								}
							}
							else								// not doing record filter
 							{
								ambiguous = TRUE;				// remember ambiguity
								break;							// and stop looking
							}
 #else
							valP->tFldId=NOID;				// signal ambiguity
							break;							// and stop looking
 #endif
						}
					}
 #if defined(RECORD_FILTER)
					if (ambiguous) valP->tFldId = NOID;		// ambiguous, no match in master
					else valP->tFldId = oldtFldId;		// unambiguous, return first match
 #endif
				}
			}
			if (lenqual<(MAXALIAS-1))
			{
				tokslop += (MAXALIAS-1-lenqual); /* alias part of tokslop */
				if (!lenqual) tokslop += 2; /* 2 char connector (->) */
			}
			if (fld->dFlags&zfNOTinREC) /* in recs can't grow */
				tokslop += (MAXCNAME-1-strlen(fldpart)); /* field part */
			return TRUE;
		}
	}

	return FALSE;
}
#endif

int CRrComposite::lafile(LPSTR tok,TOKVAL *valP)
{
	char nbuf[TOKLEN+1];

	filefirst = FALSE;
#ifdef RSW
	if (lstrchr(tok,'.')) return FALSE; /* . is file/fieldname separator */
#else
	if (lstrchr(tok,':')) return FALSE; /* :: is file/fieldname separator */
#endif
	lstrcpy(nbuf,tok);
	nbuf[8] = '\0';
	for (valP->tInteger = 0; valP->tInteger < MFMAXFILES; valP->tInteger++)
	{
		LPMFFILE filp;

		if ((filp = MFFiles[valP->tInteger])
				&& !lstrcmpi(nbuf, filp->mAlias))
		{
			tokslop += (MAXFILE-strlen(nbuf));	/* room to grow */
			return TRUE;
		}
	}

	return FALSE;
}

int CRrComposite::lafunc(LPSTR tok,TOKVAL *valP)
{
	CRrApp *pApp = (CRrApp *)AfxGetApp();	
	int toklength;
	LPUDF u;
	int slop;

	for (valP->tInteger=0; functab[valP->tInteger].fName; valP->tInteger++)
	{
		if (!lstrcmpi(tok,functab[valP->tInteger].fName))
		{
			filefirst=((functab[valP->tInteger].fArgs[1]&~OPTARG)==sv_file);
			return TRUE;
		}
	}
	for (u=UDFS; u; u=u->uNext)
	{
		if (!lstrcmpi(tok,u->uName))
		{
			valP->tInteger = -(u->uFuncNo);
			filefirst= (u->uArgList) && ((u->uArgList[0]&~OPTARG)==sv_file);
			slop = (UDFNAMELEN-lstrlen(tok)); /* room to grow */
			udfslop += slop;
			tokslop += slop;
			return TRUE;
		}
	}

	if ((toklength=lstrlen(tok)) <= 3) return FALSE;


	for (valP->tInteger = 0; functab[valP->tInteger].fName; valP->tInteger++)
	{
		if (!pApp->zfncmp(tok,functab[valP->tInteger].fName,toklength,TRUE,TRUE))
		{
			filefirst=((functab[valP->tInteger].fArgs[1]&~OPTARG)==sv_file);
			return TRUE;
		}
	}
	for (u=UDFS; u; u=u->uNext)
	{
#if defined (RSW)
		if (!lstrncmp(tok,u->uName,toklength))
#else
		if (!pApp->zfncmp(tok,u->uName,toklength,TRUE,TRUE))
#endif
		{
			valP->tInteger = -(u->uFuncNo);
			filefirst= (u->uArgList) && ((u->uArgList[0]&~OPTARG)==sv_file);
			slop = (UDFNAMELEN-lstrlen(tok)); /* room to grow */
			udfslop += slop;
			tokslop += slop;
			return TRUE;
		}
	}
	return FALSE;
}


