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
//		get expression length and result type - takes as input an RPN expression
//
//	Propagation of LOOKUP status done differently that in DOS version,
//	as dFlags2 is a byte for WIN, a word for non-WIN.
//	Eventually, WIN and non-WIN should do this the same way - make dFlags2
//	a word for both versions.
//	6/02/93 sjo - I added an argument to lexplt(). This argument indicates
//			who is calling explt(). If compile is calling, we need to call
//			mfexpinfo() to determine the size and type of the engine calc.
//			If mfeord() is calling, we do not need to call mfexpinfo, because
//			the type and size will not have changed.
//	7/07/93 sjo - Upon calling this routine, we now clear the SQLENG flag.
//			This would cause edited SQLEXP calcs to still have the flag set.
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/CFCOMP/EXPLT.CPV  $
// 
//    Rev 1.17   Jan 19 2001 14:00:58   nhubacker
// Functions for lastpage(0) and reportpage()
// 
//    Rev 1.16   Dec 12 2000 15:45:20   nhubacker
// Set f3GRPAGE flag if GRPAGE function
// 
//    Rev 1.15   Aug 30 1999 15:41:50   BUILD
// ARP20001
// 
//    Rev 1.14.1.0   15 Jul 1998 11:19:00   wrr
// code ported form 16bit to 32 bit
// percomp() added by Jim
// 
//    Rev 1.14   19 Feb 1997 14:40:08   dlm
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
//    Rev 1.13   01 Mar 1996 12:21:50   dlm
// Fix (? avoid?) RRW bug 2742 by dealing with the possibility that mfbyndx
//  might return NULL and assuming that it is because we're retrieving an
//  old report where a PREV of a FROMTOT or TOTALFLD was also a FROMTOT.
// 
//    Rev 1.12   26 Sep 1995 16:21:50   jpb
// 32 bit cleanup
// 
//    Rev 1.11   26 Sep 1995 15:22:08   pjm
// RSW composite class changes.
// 
//    Rev 1.10   22 Sep 1995 17:02:02   sjo
// Second round of FLDID changes.
// 
//    Rev 1.9   22 Sep 1995 11:26:44   sjo
// First round of FLDID changes.
// 
//    Rev 1.8   19 Sep 1995 17:56:40   sjo
// Changes made by looking at references to sizeof(int) in all sources for 32
// bit support.
// 
//    Rev 1.7   18 Sep 1995 15:00:26   jpb
// move funcs to CRrComposite
// 
//    Rev 1.6   14 Sep 1995 14:55:36   sjo
// Changes for 32 bit support, mostly for pawing thru compiled code.
// 
//    Rev 1.5   11 Sep 1995 11:12:28   sjo
// 32-bit changes.
// 
//    Rev 1.4   15 Aug 1995 16:35:10   sjo
// Changes made for RSW compiles.
// 
//    Rev 1.3   02 Aug 1995 10:01:18   sjo
// I needed to move the include of the class headers from just after the include
// of product.h, to just after the #define of the module name.
// 
//    Rev 1.2   20 Jul 1995 16:41:40   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.1   27 Apr 1995 12:35:46   sjo
// Merge of 6.1.03+.  I say + because I have added some of the time functions
// to this merge, which will be a part of 6.1.04.  I merged the CF directories
// and some H files (for the time function changes).
// 
//    Rev 1.0   16 Mar 1995 16:22:12   sbc
// Initial revision.
// 
//    Rev 1.14   07 Apr 1995 09:55:02   sjo
// Fixed a compile problem in RSW.
// 
//    Rev 1.13   06 Apr 1995 19:14:56   sjo
// Fixes as a result of date investigation of the cf directories.
// 
//    Rev 1.12   03 Apr 1995 15:50:34   pjm
// Set f2LOOKUP bit on datetime lookups.
// 
//    Rev 1.11   29 Mar 1995 10:26:54   jpb
// bump code pointer by correct amount for a_datetime
// 
//    Rev 1.10   28 Mar 1995 17:47:10   jpb
// add a_time case as required
// 
//    Rev 1.9   23 Mar 1995 17:08:26   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
//    Rev 1.8   13 Mar 1995 16:32:42   jpb
// Fix RRW 2324
// 
//    Rev 1.7   08 Feb 1995 13:28:02   sjo
// Checking in a bunch of files for the first wave of datetime support. These
// sources have support for a dFlags that is a long (not an unsigned int) and
// it recognizes date, time and datetime fields.  It only supports dates at
// this time, because we need calcs, picture types, etc if we are to do time and
// datetime.
// 
// ** First merge of RRW7 took place here.
//
//    Rev 1.6   18 Jan 1995 17:48:06   sjo
// Made changes to remove compiler warnings.
// 
//    Rev 1.5   14 Oct 1994 18:05:38   sjo
// Made a supress error messages when evaluating a sqlexp() during readrep. See
// also compile.c.
// 
//    Rev 1.4   08 Sep 1994 17:34:48   sjo
// Made a fix to not allow SQLEXPs in a UDF.  RSW crock #1069.
// 
//    Rev 1.3   10 Aug 1994 19:52:26   smh
// When we're remembering the file number of a_fld, if it's fnLIMBO, use
//  oldfilno, instead.
// 
//    Rev 1.2   26 Jul 1994 12:38:30   jpb
// Conditional totals support
// 
//    Rev 1.1   08 Nov 1993 11:07:08   smh
// Set and propagate the f2NOTONCE flag.  This flag is set for SQLEXP and
// translatable (unless constant) calcs so mfeord knows not to put them in 
// the eval-once chain.  Fixes RSW bug 575.
// 
//    Rev 1.0   14 Oct 1993 10:16:14   sjo
// Initial revision.
// ****************************************************************************
#include "product.h"
//
// Make a definition for this module.
//
#define _EXPLT_C_

#include "rrdoc.h"
#if defined (RSW)
#include "string.h"
#endif
#include "stdio.h"
#include "_cfcomp.h"
#include "mfdata.h"
#include "mffield.h"
#include "mffile.h"
#include "wutil.h"
#include "pd.h"         // for defn of zdSPC
#include "mfmisc.h"

#ifndef RSW
int CRrComposite::lfno(LPMFFILE file)
{
	int i;

	for (i=0; i<MFMAXFILES; i++) if (MFFiles[i]==file) break;
	return i;
}

int CRrComposite::owner(int fn)	/* returns file number of "owner" file */
{
	LPMFFILE file = MFFiles[fn];
	int level = file->mLevel;

	if (level==0 || (level&0x80)) return level; /* master or magic file */

	while ((file->mLinkFlags&MFLOOKUP)!=MFSCAN)
		file = MFFiles[mfbyndx(file->mLinkFld)->dFileNo];

	return lfno(file);
}          

int CRrComposite::grpowner(int fn)	/* file number of scan group "owner" file */
{
	LPMFFILE file = MFFiles[fn];
	LPMFFILE tfile;
	int level = file->mLevel;
	unsigned int lfld;

	if (level==0 || (level&0x80)) return level; /* master or magic file */

	while ((file->mLinkFlags&MFLOOKUP)!=MFSCAN)
		file = MFFiles[mfbyndx(file->mLinkFld)->dFileNo];

	if (file->mNextSame!=file->mPrevSame)
	{ /* in a scan group - find first scanner with same linking field */
		lfld = file->mLinkFld;
		for (tfile=file->mPrevSame; tfile; tfile=tfile->mPrevSame)
			if (tfile->mLinkFld==lfld) file = tfile;
	}
	return lfno(file);
}
#endif

#if defined (RSW)
int CRrComposite::lexplt(
 LPSTR 			in,		/* RPN expression */
 int 			*lenP,	/* length of RPN expression will be returned */
 unsigned long  *typeP, /* data type (dFlags) of result will be returned */
 LPSTR 			filnoP,	/* file number of file to associate with calculation */
 FLDID 			*ndxP,	/* pointer to source index for fromtots */
 LPMFFIELD 		resfld,	/* result field (self ref detection) */
 LPUDF 			resudf,	/* result udf */			
 int 			action	/* indicates why explt is being called - this is for */
)	
#else
void CRrComposite::lexplt(
 LPSTR 			in,	 	/* RPN expression */
 int  			*lenP,  /* length of RPN expression will be returned */
 unsigned long  *typeP, /* data type (dFlags) of result will be returned */
 LPSTR 			filnoP,	/* file number of file to associate with calculation */
 FLDID  		*ndxP,  /*pointer to source index for fromtots */
 LPMFFIELD 		resfld,	/* result field (self ref detection) */
 LPUDF 			resudf	/* result udf */
)		
#endif
{
	int tf;
	FLDID	 index;
	int percomp = FALSE;
#ifndef RSW
	int deepest = -1;
	int ownerfile = -1;
	int slevel;
#endif
	int direct, blvl;
	int hilvl = -2;
	FLDID sndx = NOID;	// This was setting sndx=0, but NOID is more accurate.
	FLDID LastField = NOID;
	int	  LastFunc;
	int   LastFile;
	char lastact;
	unsigned long type = zfNUMERIC;
	LPSTR xcp = in;
	int manyfiles=-1;
	int filnum=-1;
	unsigned int totpage = 0;
	int fromdb = 0;
	LPMFFIELD tfld;
	FLDID selfndx = resfld ? lmfgetndx(resfld) : NOID;
	int final = FALSE;
	int running = FALSE;
	int selfref = FALSE;
	LPUDF u;
	int multitot = FALSE;
#ifdef RSW
	char	*s, *s1;
	int msize;
	int experr;
	ASSERT( m_pDoc );
	ASSERT( m_pDoc->IsKindOf(RUNTIME_CLASS(CRrDoc)) );
#endif
	LPMFFIELD lastfptr;
	int condtot = resfld ? resfld->dRFlags&rfTOTALFLD : FALSE;
	int extrapass = condtot;
	char opcode;

	if (in==NULL)
#if defined (RSW)
	return (FALSE);
#else
		return;
#endif
#ifdef RSW
	// clear the SQLENG flag.
	if (resfld)
		resfld->dFlags2 &= ~f2SQLENG;
#else
	if (resfld) resfld->dRFlags &= ~rfLOOKUP;
	if (resudf) resudf->uFlags &= ~f2LOOKUP;
#endif // RSW
	while (TRUE)
	{
		if (extrapass) opcode = a_fld;
		else opcode = *(xcp++);

		if (opcode!=a_ret) lastact=opcode;

		switch (opcode)
		{
			case a_num:
				xcp+=(1+sizeof(double));	/* followed by double val */
			case a_plus:
			case a_minus:
			case a_div:
			case a_mul:
			case a_exp:
			case a_uplus:
			case a_uminus:
			case a_pct:
			case a_datedif:
				type =zfNUMERIC;
				break;

			case a_str:
				 /* followed by len, str */
				xcp += (*(int *)xcp)+sizeof(int);	// OK for 32 bits
			case a_cat:
			case a_tcat:
				type = 0;
				break;

			case a_argsep:
			case a_noarg:
			case a_mtmemo:
				break;
			case a_datetime:
				xcp += sizeof(ZDATETIME);
				type=zfDATETIME;
				break;

			case a_time:
				xcp += sizeof(double);
				type=zfTIME;
				break;

			case a_keyword:			// Keyword is followed by a char indicating the 
				xcp++;				// class of keyword, followed by a char indicating the value of the keyword
				xcp++;      
				break;
										
			case a_date:
				xcp += sizeof(long);
			case a_plusdays:
			case a_subdays:
				type = zfDATE;
				break;

			case a_ret:
				if (lastact==a_fld)
					type = mfbyndx(LastField)->dFlags&
					(zfNUMERIC|zfDATE|zfLOGICAL|zfMEMO|zfDATETIME|zfTIME);
				else if (lastact==a_func || lastact==a_ufunc)
				{
					char svtype;

					if (lastact==a_func) svtype = functab[LastFunc].fType;
					else
					{
						for (u=UDFS; u; u=u->uNext) if (LastFunc==u->uFuncNo) break;
						svtype = u->uType;
					}

					if (svtype==sv_prev) switch(functype)
						{
							case t_num: svtype=sv_dbl;
								break;
							case t_num|TLOG: svtype=sv_dbl|LOGICAL;
								break;
							case t_str: svtype=sv_str;
								break;
							case t_memo: svtype=sv_memo;
								break;
							case t_ztime: svtype=sv_time;
								break;
							case t_datetime: svtype=sv_datetime;
								break;
							default:	svtype=sv_date;
								break;
						}
#if defined (RSW)
				if (LastFunc != f_ixsql)
				   /* IXSQL sets type correctly, we can not rely on
						functab.
					*/
#endif
					type = svtype&LOGICAL ? zfLOGICAL :
						svtype==sv_dbl ? zfNUMERIC :
							svtype==sv_memo ? zfMEMO :
								svtype==sv_date ? zfDATE : 
									svtype==sv_datetime ? zfDATETIME :
										svtype==sv_time ? zfTIME : 0;
				}

#ifdef RSW
			*filnoP = percomp ? -2 : manyfiles==-1 ? -1 :
					  manyfiles ? 0 : filnum;
#else
				*filnoP = percomp ? -2 : manyfiles ? ownerfile : filnum;
#endif

				*typeP = type|totpage;
				*ndxP = sndx;
				*lenP = xcp-in;
				if (selfref)
				{
					if ((*filnoP&0xFF)==fnNONE) *filnoP = (char)fnCOMPOSITE;
					if (resfld) resfld->dRFlags |= rfSELFREF;
				}
				else if (resfld) resfld->dRFlags &= ~rfSELFREF;

#if defined(RSW) && !defined(INTERACTIVE)
	// if fld has translation & ! constant, flag so dont putn MFEvalOnce chain.
				if (resfld && !((*filnoP & 0xFF) == fnNONE) && 
						(resfld->dRecU.calcS.dExpX))
					fromdb |= f2NOTONCE;
#endif

				if (final && !running)
				{
					if (resfld) resfld->dRFlags |= rfFINALTOT;
				}
				else if (resfld) resfld->dRFlags &= ~rfFINALTOT;
				if (resfld)
				{
					resfld->dFlags2 &= ~(f2RESMIX|f2FROMDB|f2FROMPT|f2FRMQRY
#if defined(RSW) && !defined(INTERACTIVE)
																					|f2NOTONCE
#endif
																									);
					resfld->dFlags2 |= fromdb;
				}
#if defined (RSW)
			return (FALSE);
#else
				return;
#endif
				break;

			case a_func:
				/* remove logical result bit */
				LastFunc = (*(int *)xcp)&0x7FFF;	// OK for 32 bits
				if ((LastFunc==f_page) || (LastFunc==f_reportpage))
					totpage |= zfPAGENO;
				else if (LastFunc==f_recn && *(xcp-2)==a_noarg)
					totpage |= zfRECNO; 	// xcp-2 backs up to byte before a_func
				else if (LastFunc==f_query)
					fromdb |= f2FRMQRY;
				else if (LastFunc==f_lastpage)
					resfld->dFlags3 |= f3LASTPAGE ;
#ifdef RSW		/* If the function is ixsql, set the sql engine bit */
				else if (LastFunc==f_ixsql)
					{
					/* I am putting the call to mfexpinfo here.  This call
						determines the type of engine calc we have (int, char,)
						and it sets the length, etc.
					*/
					if (UserSelect) return (ee_sqlsel); 
					if (!resfld && resudf) return (ee_nosqlexpudf);
					fromdb |= f2SQLENG;
 #if !defined(INTERACTIVE)
					// if fld uses SQLEXP, flag so dont putn MFEvalOnce chain.
					// Different from f2SQLENG cuz propagated & depends on dExpX
					fromdb |= f2NOTONCE;
 #endif
					percomp = TRUE;
					if (!chksqleng(in))
						{
						/* error in compiled code.
						*/
						return (TRUE);
						}
               // action is either 0x00, 0x01, 0x10 or 0x11. This first
               //  bit is compile or not and the second is disp error or
   				//  not
   				
					if (action&COMPILE)
						{
						int serror;
						/* Copy the user string and have the engine evaluate
							it. We know the string is 1+sizeof(int) from the
							beginning of the compiled code.  So just copy it.
							The string is also null terminated.
						*/
						msize = *(in+1);
						s1 = m_pDoc->globalAlloc(LMEM_MOVEABLE, msize);
						lstrcpy(s1, (in+1+sizeof(int)));				// Looks OK for 32 bits

						for (s=s1; *s; s++)
							{
							/* remove any hard spaces from the string. These
							  get added when the string is read in.
							*/
							if (*s==(char)SpaceDot) *s = ' ';
							}

						serror=(action&SHOW_ERROR);
						if (experr = mfexpinfo(s1,resfld,SETTYPE,serror))
							{
							/* If we get an error, return it.
							*/
							m_pDoc->globalFree(s1);
							return(experr);
							}
						/* set the flag bits in typeP
						*/
						m_pDoc->globalFree(s1);
						type = resfld->dFlags&(zfDATE|zfNUMERIC|zfLOGICAL|zfMEMO|zfTIME|zfDATETIME);
						}
					else
						{
						/* if we arent compiling, make sure to set the flags
						  so everything works
						*/
						type = resfld->dFlags&(zfDATE|zfNUMERIC|zfLOGICAL|zfMEMO|zfTIME|zfDATETIME);						}
					} /* end if f_ixsql */
#endif
#ifndef RSW
				else if ((LastFunc==f_clookup) ||
						(LastFunc==f_dlookup) ||
						(LastFunc==f_llookup) ||
						(LastFunc==f_dtlookup) ||
						(LastFunc==f_nlookup))
				{
					if (resfld) resfld->dRFlags |= rfLOOKUP;
					if (resudf) resudf->uFlags |= f2LOOKUP;
				}
#endif
				percomp |= (LastFunc==f_page || LastFunc==f_reportpage || LastFunc==f_percomp ||   //WRR 7/1/98. replace lastf with LastFunc
					(LastFunc==f_recn && *(xcp-2)==a_noarg)); // xcp-2 backs up to byte before a_func
				/* followed by func num (an int), argct (a char) */
				xcp+=sizeof(int)+1; 							   // Looks OK for 32 bits
				break;

			case a_ufunc:
				/* remove logical result bit */
				LastFunc = (*(int *)xcp)&0x7FFF;	// Ok for 32 bits
				/* followed by func num, argct */
				xcp+=sizeof(int)+1; 				// Looks OK for 32 bits
				for (u=UDFS; u; u=u->uNext) if (LastFunc==u->uFuncNo) break;
				totpage |= u->uFlags&(zfFROMTOT|zfPREV|zfRECNO|zfPAGENO);
				percomp |= (int) u->uFlags&(zfRECNO|zfPAGENO);
#ifndef RSW
				if (u->uFlags & f2LOOKUP) /* propagate lookup */
				{
					if (resfld) resfld->dRFlags |= rfLOOKUP;
					if (resudf) resudf->uFlags |= f2LOOKUP;
				}
#endif // RSW
				break;

			case a_pfld:
				totpage |= zfPREV;
			case a_fld:
				if (extrapass)
				{ // must be total condition expression
					LastField = lmfgetndx(resfld);	// act like total referenced
					lastfptr = resfld;			// in expression
					xcp = in;					// next pass will use expression
				} else
				{
					LastField = *(FLDID *)xcp;
					lastfptr = mfbyndx(LastField);
					xcp+= sizeof(FLDID);				// OK for 32 bits
				}
				tf = lastfptr->dFileNo == fnLIMBO ? oldfilno : lastfptr->dFileNo;
				tfld = lastfptr;
				if (!extrapass)
				{
					if ((!condtot) && (LastField==selfndx))
					{ // ignore self ref for cond expr - catch fromtot instead
						selfref = TRUE;
						break;		/* no further analysis for self ref */
					}
					if ((opcode==a_fld)
					 && ((direct=(tfld->dRFlags&rfTOTALFLD)) || tfld->dFlags&zfFROMTOT))
					{
						if (direct)
						{
							index = LastField;
						}
						else
						{
							index = tfld->sindex;
						}
						LPMFFIELD tsfld = mfbyndx(index);
						// Fix (?) for RRW bug 2742.
						// In version 6.0 and before, this block was not in an a_fld test
						//  so FROMTOT got set on prev(FROMTOT or TOTALFLD), yet it didn't
						//  have an sindex.  Reading such an old report with version 7 results
						//  in a NULL from mfbyndx.  We now consider prev(FROMTOT or TOTALFLD)
						//  not to be a FROMTOT, so just skip the rest of this code if we
						//  get a NULL.
						ASSERT( tsfld );
						if ( tsfld )
						{
							blvl = mfbyndx(index)->dRecU.insS.brklevel;
							if (totpage&zfFROMTOT) multitot = TRUE;
							totpage |= zfFROMTOT;
							if (!(tfld->dRFlags&rfFINALTOT)) running = TRUE;
							if (blvl==fnNONE) blvl = -2;	/* grand */
							else if (blvl==fnCOMPOSITE)
							{
								fromdb |= f2FROMPT;
								blvl = -1;	/* page */
							}
							if (multitot && (blvl!=hilvl)) fromdb |= f2RESMIX;
							if (blvl >= hilvl) /* need "=" to set sndx on blvl -2 */
							{
								hilvl = blvl;
								sndx = index;
							}
						}
					}
				}
				extrapass = FALSE;	// at most one extra
				if (tfld->dFlags&zfPREV) totpage |= zfPREV;
				if ((tfld->dFlags&zfPAGENO)) totpage |= zfPAGENO;
				if ((tfld->dFlags&zfRECNO)) totpage |= zfRECNO;
				if (tfld->dFlags2&f2FRMQRY) fromdb|= f2FRMQRY;
				if (tfld->dRFlags&rfFINALTOT) final = TRUE;
				if (tfld->dRFlags&rfSELFREF) selfref = TRUE;
				if (tfld->dFlags2&f2FROMPT) fromdb |= f2FROMPT;
#if defined (RSW) && !defined(INTERACTIVE)
				if (tfld->dFlags2&f2NOTONCE) fromdb|= f2NOTONCE;
#endif
				if ((!condtot) && ((!(tfld->dFlags&zfNOTinREC)) || /* in rec is from db */
						(tfld->dFlags2&f2FROMDB))) fromdb |= f2FROMDB;

				percomp |= (tfld->dFileNo==fnCOMPOSITE);

				if (filnum != tf)
				{
					filnum = tf;
					manyfiles++;
				}

#ifndef RSW
			/* next block of code not executed if there is no master file
			   This is only true when UDFs are read in, before any
			   data files have been opened.  This code is irrelevant
			   for UDFs.
			*/
				if ((MFFiles[0]) && (!(tf&0x80)))
				{ /* don't bother if field not from a file */
					slevel = MFFiles[tf]->mLevel;
					if (slevel==deepest && ownerfile!=owner(tf))
					{
						ownerfile = grpowner(tf);
					}
					else if (slevel>deepest)
					{
						deepest=slevel;
						ownerfile = owner(tf);
					}
				}
#endif
				break;

			case a_file:
				LastFile = *(int *)xcp;				// OK for 32 bits
				/* followed by file number */
				xcp+=sizeof(int);			 		// OK for 32 bits
#ifndef RSW // no total-related link fields in RSW
				if (LastFile)
				{ /* a related file */
					tfld = mfbyndx(MFFiles[LastFile]->mLinkFld); /* link field */
					if ((tfld->dRFlags&rfTOTALFLD) || (tfld->dFlags&zfFROMTOT))
					{ /* link field is total-related */
						totpage |= zfFROMTOT;
					}
				}
#endif
				if (filnum != LastFile)
				{
					filnum = LastFile;
					manyfiles++;
				}
#ifndef RSW
				slevel = MFFiles[LastFile]->mLevel;
				if (slevel==deepest && ownerfile!=owner(LastFile))
				{
					ownerfile = grpowner(LastFile);
				}
				else if (slevel>deepest)
				{
					deepest=slevel;
					ownerfile = owner(LastFile);
				}
#endif
				break;

			case a_bfalse:
			case a_branch:
				xcp += sizeof(long);
				break;

			default:
				type = zfLOGICAL;
				break;
		}
	}
}

