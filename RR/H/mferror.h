// ****************************************************************************
//
//      (C) Copyright 1992-1993 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
//
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/H/MFERROR.H_V  $
// 
//    Rev 1.5   Dec 05 2000 13:01:58   nhubacker
// Add error code for missing user index
// 
//    Rev 1.4   13 Jan 1999 17:00:36   jpb
// for work offline mode
// 
//    Rev 1.3   06 Jun 1996 14:21:22   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.2   18 Mar 1996 17:18:14   jpb
// add MFLKNULLTAG
// 
//    Rev 1.1   07 Jul 1995 18:11:42   jpb
// First pass at moving all data and functions to CRrDoc class
// 
//    Rev 1.0   16 Mar 1995 16:12:54   sbc
// Initial revision.
// 
//    Rev 1.2   13 Jan 1994 10:03:06   jpb
// Minimize SELECT field list - changed modules: cfmisc.h, mferror.h,
//  cfneeded.c, mfcheck.c, mfrdmore.c, rpsort.c, sxselect.c, wprint.c
// 
//    Rev 1.1   19 Nov 1993 17:43:58   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:12:20   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _MFERROR_H_

//
// Make a definition for this module.
//
#define _MFERROR_H_

#if defined (_MFERROR_C_)
 #define GLOBAL
#else
 #define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
/* mferr.h	multifile error codes */

#define MFFATAL 0x0B00
#define MFNONFATAL 0x0C00

/* fatal multifile error codes */
#define MFRLSFTB (MFFATAL+0x01)
#define MFRLSFLD (MFFATAL+0x02)
#define MFRLSORD (MFFATAL+0x03)
#define MFRLSBUF (MFFATAL+0x04)


/* non-fatal multifile errors */
/* from mfrdnext() */
#define MFLKUP (MFNONFATAL+0x01)	/* lookup failure */
#define MFPRABORT (MFNONFATAL+0x02)	/* post read abort */
#define MFEOF (MFNONFATAL+0x03)	/* normal end of file */
#define MFSCANERR (MFNONFATAL+0x04)	/* scanner initial lookup failure */
#define MFREJECT (MFNONFATAL+0x05)	/* no record returned (sxrejected) */
#define MFRECNERR (MFNONFATAL+0x06)	/* record number out of range */
#define MFDACCESS (MFNONFATAL+0x07)	/* error accessing dbf file */
#define MFCHANERR (MFNONFATAL+0x08)	/* can't get a database channel */
#define MFEVALERR (MFNONFATAL+0x09)	/* error return from eval() */
#define MFGRPERR (MFNONFATAL+0x0A)	/* group scan failure */

/* from mfopen() */
#define MFOPMEM (MFNONFATAL+0x11)	/* not enough memory for structures */
#define MFOPBAD (MFNONFATAL+0x12)	/* not a dBASE III file */
#define MFOPNFL (MFNONFATAL+0x13)	/* no such file */
#define MFOPUNK (MFNONFATAL+0x14)	/* unknown field type */
#define MFOPDBT (MFNONFATAL+0x15)	/* can't open dbt file */
#define MFOPCHAN (MFNONFATAL+0x16)	/* not enough "channels" */
#define MFOPDATA (MFNONFATAL+0x17)	/* no data in worksheet range  */
#define MFOPCRYPT (MFNONFATAL+0x18)	/* encrypted worksheet */
#define MFOPESC (MFNONFATAL+0x19)	/* user escape - wks rangecheck() */
#define MFOPNOF (MFNONFATAL+0x1A)	/* no supported fields */
#define MFOPNOOI (MFNONFATAL+0x1B)	/* no offline information avalilable */

/* from mflink() */
#define MFLKNOFLD (MFNONFATAL+0x21)	/* link field not found */
#define MFLKNOFIL (MFNONFATAL+0x22)	/* index file not found */
#define MFLKBADFIL (MFNONFATAL+0x23)/* bad dbase index file */
#define MFLKTYPE (MFNONFATAL+0x24)	/* link/key fields different types */
#define MFLKREC (MFNONFATAL+0x25)	/* key field not in record */
#define MFRDERR (MFNONFATAL+0x26)	/* error reading index file */
#define MFLKCLIP (MFNONFATAL+0x27)	/* no clipper module */
#define MFLKESC (MFNONFATAL+0x28)	/* user esc from tag select, kliopen */
#define MFLKDUPAL (MFNONFATAL+0x29)	/* setrel duplicate alias error (WIN) */
#define MFLKMATLEN (MFNONFATAL+0x2A) /* setrel match len error (WIN) */
#define MFIXBSZ (MFNONFATAL+0x2B)	/* index block size not supported */
#define MFBADTAG (MFNONFATAL+0x2C)	/* bad tag name */
#define MFTOTSCAN (MFNONFATAL+0x2D)	/* Cannot scan thru total related link */
#define MFLKNULLTAG (MFNONFATAL+0x2E)/* Cannot link thru NULLable tag (VFP) TEMP */
#define MFUSERINDEX (MFNONFATAL+0x2F)	// User index file not found

/* general */
#define MFDBCMEM (MFNONFATAL+0x31)		/* dbc getmem() failure */
#define MFQCOMPILE (MFNONFATAL+0x32)	/* MFQInit compile error */
#define MFQTYPE (MFNONFATAL+0x33)		/* MFQuery not a logical */
#define MFBADALIAS (MFNONFATAL+0x34)	/* bad chars in alias */
#define MFRUNQUER (MFNONFATAL+0x35)		/* query on running total */
#define MFDELFL (MFNONFATAL+0x36)		/* can't delete link field */

/* building locate indexes */
#define MFXDISK (MFNONFATAL+0x41)	/* disk error bulding index */
#define MFXFULL (MFNONFATAL+0x42)	/* disk full bulding index */
#define MFXERR	(MFNONFATAL+0x43)	/* other error building index */

/* opening memo worksheet */
#define MFMEMPTY (MFNONFATAL+0x51)	/* no ranges in memo worksheet */

/* accessing SQL memo file */
#define MFMACCESS (MFNONFATAL+0x61)	/* file io error */
#define MFMEMNFL (MFNONFATAL+0x62)	/* no such memo file */

/* mfgetrec-related */
#define MFSORTNFL (MFNONFATAL+0x63)	/* can't open sort file */

/* mfsnap-related */
#define MFSNAP2 (MFNONFATAL+0x64)	/* can't save twice */
#define MFCRESNAP (MFNONFATAL+0x65)	/* can't create cache file */
#define MFSNAP0 (MFNONFATAL+0x66)	/* can't restore from nothing */
#define MFWCACHE (MFNONFATAL+0x67)	/* error writing cache file */
#define MFRCACHE (MFNONFATAL+0x68)	/* error reading cache file */

#define MFCRECOMP (MFNONFATAL+0x69)	/* can't create comp recno file */
#define MFWCOMP (MFNONFATAL+0x6A)	/* can't write to comp recno file */

/* buildfinal errors */
#define MFFTOFILE (MFNONFATAL+0x71)		/* error open final total file */
#define MFFTRNDX  (MFNONFATAL+0x72)		/* error read final total index */
#define MFFTCOMP (MFNONFATAL+0x73)		/* error access component file */
#define MFFTSORT (MFNONFATAL+0x74)		/* error in (and reported by) sort */
#define MFPTRNFL (MFNONFATAL+0x75)		/* really a getstart error */
#define MFFTSYNC (MFNONFATAL+0x76)		/* sort/group lists out of synch */
#define MFFTGRP  (MFNONFATAL+0x77)		/* final on unassigned group level */
#define MFFTOHOH (MFNONFATAL+0x78)		/* ohoh, unsupported final sort */
#define MFFTCRTF (MFNONFATAL+0x79)		/* can't create final total file */
#define MFFTBDGP (MFNONFATAL+0x7A)		/* fintot depends on fintot group */
#define MFFTQUER (MFNONFATAL+0x7B)		/* query on processing mode mix */
#define MFFTQLVL (MFNONFATAL+0x7C)		/* query on bad final level */
#define MFFTCOMBO (MFNONFATAL+0x7D)		/* bad combination of finals */
#define MFFTSORTF (MFNONFATAL+0x7E)		/* cant sort on running total */
#define MFFTGROUP (MFNONFATAL+0x7F)		/* cant group on running total */
#define MFFTRFILE (MFNONFATAL+0x80)		/* error read final total file */
#define MFFTWFILE (MFNONFATAL+0x81)		/* error write final total file */
#define MFFTWNDX  (MFNONFATAL+0x82)		/* error write final total index */

/* scope-related */
#define MFBADLO (MFNONFATAL+0x91)	/* bad lo scope value */
#define MFBADHI (MFNONFATAL+0x92)	/* bad hi scope value */
#define MFBADLOHI (MFNONFATAL+0x93)	/* bad hi scope value */
#define MFBADREC (MFNONFATAL+0x94)	/* bad recno scope value */\

/*	select-based report error codes */
#define MFSELNAMELIST (MFNONFATAL+0xA1)		/* bad parenthesized name list */
#define MFSELEMPTY (MFNONFATAL+0xA2)		/* empty statement */
#define MFSELBADSTART (MFNONFATAL+0xA3)		/* not select/exec/definereportview */
#define MFSELRVNAME (MFNONFATAL+0xA4)		/* missing reportview name */
#define MFSELNOAS (MFNONFATAL+0xA5)			/* missing "as" */
#define MFSELNOSEL (MFNONFATAL+0xA6)		/* missing "select" */
#define MFSELNONAME (MFNONFATAL+0xA7)		/* missing column name */
#define MFSELDUPNAME (MFNONFATAL+0xA8)		/* dup column name */
#define MFSELSPNAME (MFNONFATAL+0xA9)		/* missing stored procedure name */

/* interr.h		internal error code header */

#define IEEORD		0x0001	/* evaluate chain error (mfeord) */
#define IEEVAL		0x0002	/* bad error evaluating calculated field */
#define IEBUFSET	0x0003	/* buffer setup error */
#define IEBUFSYN	0x0004	/* buffer synchronization error */
#define IELEVELS	0x0005	/* mfarray error */
#define IEBUFMEM	0x0006	/* can't get enough of your buffer, baby */
#define IEFREETX	0x0007	/* can't find text field to free */
#define IECHAN		0x0008	/* multifile channel management error */
#define IEBUFO		0x0009	/* calculated string result buffer overflow */

#define IEIXBASE	0x0010	/* codes 10 through 1F reserved for IXMAKER
							   IX??? error code values are added to IEIXBASE 
							   for interr display
							*/

#define IEFLOAT		0x0020	/* floating point error outside of eval() */
#define IESKIP		0x0021	/* can't skip on "inactive arm" lookup failure */
#define	IEUNK		0x0022	/* old "unknown multifile error" code */
#define	IELKB		0x0023	/* buffer wasn't allocated for lookup() */


//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//


#if 0
 #if defined INTERACTIVE
GLOBAL char near RpQuery		/* used by mfdbsize INTERACTIVE or not */
  #if defined (_MFERROR_C_)
 		= 0;
  #else
 		;
  #endif
 #endif
#endif



//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#if 0
extern	int chgfinals(struct mffield FAR *fld);
extern	int ckfinals(HWND handy,int warn);
extern	void mfack(int err);
extern	int mfbagit(int ecode);
extern	char *mferror(int ecode);
extern	int mflocalsort(void);
extern	void mfpstat(int mode,int row,int col);
extern	void mfqerr(int n);
extern	void mfreperr(int ecode);
extern	int mfrunerr(int fnum);
extern	void mfwack(HWND w,int err);
#endif


#undef GLOBAL

#endif // end _MFERROR_H_

// *************************** End of File ************************************

