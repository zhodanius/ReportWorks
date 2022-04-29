// ****************************************************************************
//
//      (C) Copyright 2001 Liveware Publishing Inc.
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
// $Log:   D:/R&R Project/archives/H/PRODUCT.H_V  $
// 
//    Rev 1.49   01 Sep 2004 08:09:14   Nick
// No Records found
// 
//    Rev 1.48   02 Jul 2004 13:28:40   Nick
// Lengthen data names to 30
// 
//    Rev 1.47   Sep 05 2002 12:21:54   Admin
// Increase query capacity
// 
//    Rev 1.46   Apr 25 2002 10:15:16   Admin
// Add bxImageField
// 
//    Rev 1.45   Feb 27 2001 15:36:36   nhubacker
// Parameter prompt and burst
// 
//    Rev 1.44   Aug 31 2000 13:50:38   nhubacker
// Support for (long) tags in dbase 7.5 MDX
// 
//    Rev 1.43   Jun 01 2000 11:29:18   nhubacker
// No more CUSTOM_TITLE for Abra
// 
//    Rev 1.42   Apr 13 2000 16:41:10   nhubacker
// Little ABRA change
// 
//    Rev 1.41   Aug 30 1999 15:43:24   BUILD
// ARP20001
// 
//    Rev 1.40   21 Jan 1998 12:14:02   smh
// OEM20001 merge
// 
//    Rev 1.39.2.0   15 Jan 1998 16:07:10   smh
// RRW 8.0 Abra OEM
// 
//    Rev 1.39   08 May 1997 11:30:30   pjm
// Increase YXBUFMAX size to account for long table and field names
// from Visual FoxPro.
// 
//    Rev 1.38   02 May 1997 16:55:08   dlm
// Removed CHARTING conditionals.
// 
//    Rev 1.37   29 Apr 1997 09:13:42   dlm
// Moved addition of CHART_PASS to CHARTING conditional.
// 
//    Rev 1.36   29 Apr 1997 09:10:06   dlm
// Added CHART_PASS definition to support charting in headers/title.
// 
//    Rev 1.35   19 Mar 1997 15:04:58   pjm
// Fix MAXDSNAME for RSW.
// 
//    Rev 1.34   19 Mar 1997 10:25:12   pjm
// Change values for RRW field names (now we have long and short)
// for Visual FoxPro DBC support.
// 
//    Rev 1.33   14 Mar 1997 15:59:56   SRM
// chart support initial checkin
// 
//    Rev 1.32   20 Feb 1997 13:12:04   amh
// Added #include tchar.h for DBCS enablement
// 
//    Rev 1.31   10 Feb 1997 10:02:20   sp
// Arp Live merge to trunk
// 
//    Rev 1.29.1.1   14 Nov 1996 10:33:44   sp
// moved the declaration of BANDINTABLE from GENREP~1.H and WPIX.CPP
// to Product.H and replaced p==INBREAKH || p==INBREAK with
// BRKFOOT(p) || BRKHEAD(p) for checking all footers and headers
// 
//    Rev 1.29   06 Jun 1996 14:21:56   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.28   18 Jan 1996 10:54:42   pjm
// Exclude some runtime DLL stuff from RRCNVRT.
// 
//    Rev 1.27   15 Jan 1996 18:19:50   par
// So that I can debug CRrCntrItem stuff.
// 
//    Rev 1.26   11 Jan 1996 14:37:42   dlm
// Added some includes to get rid of "OMF type info" problems in debugger.,
// 
//    Rev 1.25   11 Jan 1996 12:53:46   par
// New MFC read error number.  
// 
//    Rev 1.24   20 Nov 1995 14:41:46   jpb
// runtime changes
// 
//    Rev 1.23   10 Nov 1995 17:13:50   par
// Major potential bug just fixed.  TEXT_FLD was not excluding OLE Objects.
// 
//    Rev 1.22   08 Nov 1995 16:17:14   smh
// Created REPNAMELENGTH for compound doc rep names,
// and TITLESTRMAX for title bar buffers.
// 
//    Rev 1.21   07 Nov 1995 18:42:54   dlm
// Changed CIPnameLENGTH to WINPATHLEN from 30.  Scott'll be changing
//  this name, I think.
// 
//    Rev 1.20   20 Oct 1995 13:33:54   par
// The OLE objects are now connected to the R&R lists. More work needs to be done but this is a good 
// start.
// 
//    Rev 1.19   22 Sep 1995 16:36:38   sbc
// Fix FLD_SIZE macro
// 
//    Rev 1.18   22 Sep 1995 10:58:08   sbc
// Make the field id stuff conditional on C++; add defines for compiling C code.
// 
//    Rev 1.17   22 Sep 1995 08:19:26   pjm
// FIxed const definition of SELECTNOID.
// 
//    Rev 1.16   21 Sep 1995 17:14:04   dlm
// FLDID-related edits.
// 
//    Rev 1.15   21 Sep 1995 13:32:08   dlm
// Define MAGIC_ID_LIMIT to reserve some "magic" field ID values.
// 
//    Rev 1.14   21 Sep 1995 10:38:08   mjs
// Added SELECTNOID.
// 
//    Rev 1.13   20 Sep 1995 16:57:50   dlm
// Added typedef for FLDID and definition of NOID to facilitate conversion of
//  field IDs from 16 bits to 32.
// 
//    Rev 1.12   20 Sep 1995 16:42:08   par
// Included new advanced assert module.
// 
//    Rev 1.11   19 Sep 1995 13:59:54   sbc
// Fix FLD_DATA define - now sizeof(short)
// 
//    Rev 1.10   18 Sep 1995 14:38:00   jpb
// first pass, rrcomposite class
// 
//    Rev 1.9   08 Sep 1995 11:53:56   jpb
// change UONE back to char, not unsigned char, to avoid compiler
// warnings (assigning char * to unsigned char * got bogus warning)
// 
//    Rev 1.8   05 Sep 1995 14:17:26   dlm
// Changed definitions of UONE, UTWO, and TWO from char, unsigned int, and
//  int to unsigned char, unsigned short, and short.
// 
//    Rev 1.7   29 Aug 1995 13:26:16   mjs
// Bring in windowsx.h to translate _fstrchr, etc for win32
// 
//    Rev 1.6   22 Aug 1995 11:45:50   mjs
// Put include of rrdoc.h in ifdef __cplusplus conditionals.
// 
//    Rev 1.5   18 Aug 1995 14:52:14   mjs
// Add rrdoc.h, which speeds up compiles.
// 
//    Rev 1.4   30 Jun 1995 12:06:48   dlm
// See 1.15, 1.16, below.
// 
//    Rev 1.3   09 Jun 1995 11:51:54   pjm
// Changed size of MAXDNAME and related stuff.
// 
//    Rev 1.2   25 Apr 1995 10:10:30   sbc
// 6.1.03 -> 7.0.01 merge
// 
//    Rev 1.1   27 Mar 1995 13:25:08   mjs
// Added #pragma to ignore C4039 warnings.
// 
//    Rev 1.0   16 Mar 1995 16:13:10   sbc
// Initial revision.
// 
//    Rev 1.16   07 Jun 1995 16:32:18   dlm
// Moved definition of YXBUFMAX to vicinity of MAXDNAME and added comments
//  about possible dependencies.  Changed YXBUFMAX to 700 for RSW.
// 
//    Rev 1.15   07 Jun 1995 11:52:52   pjm
// Changed MAXDNAME to 129.  Defined MAXLABSZ (has been in dbexport.h).
// 
//    Rev 1.13   30 Jan 1995 12:33:58   sbc
// Add bsPRINTHD to check if group header is currently printing
// 
//    Rev 1.12   14 Jun 1994 15:36:22   smh
// Added SNKCOLS and ORDER PrOpt array indexes for snaked columns support.
// 
//    Rev 1.11   09 Jun 1994 09:35:24   sbc
// Change PAUSE to COLLATE (PrOpt)
// 
//    Rev 1.10   08 Jun 1994 12:27:40   erp
// changed FAR to far, so it will build for 32-bits
// 
//    Rev 1.9   28 Apr 1994 09:48:24   dlm
// Made definition of DATADICT unconditional.
// 
//    Rev 1.8   05 Apr 1994 12:34:08   dlm
// Added a conditional block defining feature-related symbols for
//  SOLOMON version.
// 
//    Rev 1.7   21 Mar 1994 12:04:12   dlm
// Merge of Abra branch.  Conditional on ABRA, defines 5 new symbols
//  controlling conditional code.  Some of these symbols will be turned
//  on in the generic product.
// 
//    Rev 1.6   18 Feb 1994 15:41:42   sjo
// I am merging the RRWINNSX branch back onto the RRWIN tree. This branch was
// setup to allow me to port my RR 5.1 NSX, SMT and DBV changes to RRW and
// RSW.
// 
//    Rev 1.5.1.0   24 Jan 1994 10:13:44   sjo
// I am merging RR 5.1 changes into the windows products.  I increased MAXTAG
// from 11 to 13, because the new NSX indexes allow for 13 character tagnames.
// 
//    Rev 1.5   28 Dec 1993 10:50:10   erp
// added new macro for data fields DATA_FLD
// 
//    Rev 1.4   24 Nov 1993 09:07:32   sbc
// Add externs to prototypes
// 
//    Rev 1.2   29 Oct 1993 08:50:10   sbc
// Include define for READAHEAD in RRW-specific define section
// 
//    Rev 1.1.1.0   28 Feb 1994 11:06:36   dlm
// Added Abra-related feature switch definitions.  ABRA must be defined
//  in build procedure to get these features.
// 
//    Rev 1.1   25 Oct 1993 15:54:28   sbc
// Remove FLD_COL() macro and change FLD_SIZE() for new code using LinePtr.
// 
//    Rev 1.0   14 Oct 1993 10:11:46   erp
// Initial revision.
//
// winsql.h	(win.h <- this text for c.bat header check)
// 08/17/92 - say - added Jim's wxxx macros from win.h
// 08/20/92 - say - added lstrlwr for use in sxvalue.c
// 08/21/92 - say - added far decl to ZFCmpP char args
// 01/18/93 - say - make MAXDNAME 39 for PACE
//
// 06/24/93 - ERP - Added include of <string.h> to get prototype
//                  of _fmemmove.
//
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _PRODUCT_H_

//
// Make a definition for this module.
//
#define _PRODUCT_H_
//
// Old warning pragma list
//
//#pragma warning (error: 4005 4010 4027 4087 4102 4136 4013 4098)
//
// Use the following at least for now.
//
#pragma warning (error: 4005 4013)

// mjs 3/37/95  Disable warnings about truncation of constants.  All chars are unsigned.
#pragma warning (disable: 4309)

// Note stdafx.h replaces windows.h.
#ifdef __cplusplus
#include <stdafx.h>
#else
#include <windows.h>
#endif
#include <stdlib.h>

#include <string.h>
#ifdef 	WIN32
#include <windowsx.h>	// this maps _fstrchr, etc. to strchr, etc.
#endif

//AMH 2/19/97 Added include for DBCS enablement
#include  <tchar.h>

// Advanced version of ASSERT. 
// The new version will display the asserted condition along with 
// displaying the application, file and line number of the assertion. 
#include "rrassert.h"

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

// Define a 'type' for field ID and a valued meaning none.
// Additional 'local' magic IDs are defined in FILTER.H as RFLD_<name>.
typedef unsigned int FLDID;

#ifdef __cplusplus	//// C++ versions: ////

const FLDID NOID =		 	0xFFFFFFFF;
const FLDID SELECTNOID = 	0xFFFFFFFE;	// Tells initFldList() to select no field in the listbox.

const FLDID MAGIC_ID_LIMIT = 0xFFFFFF00;// Reserve 256 IDs for magic values, like NOID, for example

#else				//// C versions below: ////

#define NOID 			0xFFFFFFFF;
#define SELECTNOID 		0xFFFFFFFE; // Tells initFldList() to select no field in the listbox.

#define MAGIC_ID_LIMIT	0xFFFFFF00;	// Reserve 256 IDs for magic values, like NOID, for example

#endif	// #ifdef __cplusplus

//
// from cds.h
//
#define	BYTEMASK	(0xFF)	/* mask for a single byte */
#define	BITSperBYTE	8
#define	NOTHING		(-1)	/* ends of lists, empty results... */

#define	NOPTR	((char *)(-1))

typedef char UONE;
typedef unsigned short UTWO;
typedef short TWO;
typedef long FOUR;
typedef unsigned int uint;

#undef max2
#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif
#ifndef min
#define min(a,b) ((a)<=(b)?(a):(b))
#endif

//
//	to configure product libraries for WINDOWS multi-file DBR product,
//	copy this file to product.h
//
#define FREAD(f,b,l)		_lread(f,b,l)
#define FWRITE(f,b,l)		_lwrite(f,b,l)
#define FSEEK(f,o,m)		_llseek(f,o,m)
#define FCLOSE(f)			_lclose(f)
#define lmemcmp(p1,p2,s)	_fmemcmp(p1,p2,s)
#define lmemcpy(p1,p2,s)	_fmemcpy(p1,p2,s)
#define lmemmove(d,s,c)		_fmemmove(d,s,c)
#define lmemset(p,i,s)		_fmemset(p,i,s)
#define lsprintf			wsprintf
#define lstrchr(p,i)		_fstrchr(p,i)
#define lstrlwr(s)			_fstrlwr(s)
#define lstrncat(p1,p2,s)	_fstrncat(p1,p2,s)
#define lstrncmp(p1,p2,s)	_fstrncmp(p1,p2,s)
#define lstrnicmp(p1,p2,s)	_fstrnicmp(p1,p2,s)
#define lstrrchr(p,i)		_fstrrchr(p,i)
#define lstrncpy(p1,p2,s)	_fstrncpy(p1,p2,s)
#define wtoupper(c)			(char)(long)AnsiUpper((LPSTR)(long)(c))
#define wtolower(c)			(char)(long)AnsiLower((LPSTR)(long)(c))
#define wisalpha(c)			IsCharAlpha(c)
#define wisalnum(c)			IsCharAlphaNumeric(c)
#define wisupper(c)			IsCharUpper(c)
#define wislower(c)			IsCharLower(c)

//
// Common product-specific #defines
//

// Feature-control switches

#define DATADICT 1			// enable data-dictionary support

#if defined(SOLOMON)
	#define NOSERIALNUM 1		// disable serial-number support
#endif

#if defined(OEM_ABRA)
	#define ABRA 1				// just for a few cases...
	#define NOSERIALNUM 1		// disable serial-number support
	#define RECORD_FILTER 1		// enable record-level filter support
//	#define CUSTOM_TITLE 1		// enable custom title-screen support - Not!
	#define PASSWORD_REQD 1		// require password command-line argument
#endif

#define MAXSTR 512		// max length of intermediate calc string result
						// MAXSTR was 254 until DIALOG support added

#define DBMAXSTR 254	// dBASE MAXSTR value

#define FLMAX 254		// maximum length of an alpha field
						// by the time the product stuff gets it
#define NUMFLMAX 20		// numeric field
//
// Windows path length
//
#define WINPATHLEN		_MAX_PATH	// it's big

#define MAXTAG		33		/* max len tag (with null) */

#define FNLEN		WINPATHLEN	/* maximum length of file name */

//  What if we make the MAXALIAS bigger?  Why is there this arbitrary length except that DOS
//  had an 8.3 file scheme and there was the issue with longer table names at export?
//  redefining to 127 to see the impact on the various additional locations where it's mentioned
//  Changed by CAS on 5/16/2017
//#define MAXALIAS	15
#define MAXALIAS	9		/* max len alias (with null) */

#define MFMAXFILES	100		/* maximum number of files */
#define MAXLEVELS	32		/* max(kl,db) (kl = 15) */
							/* max levels in B-tree (4**15 = 4 billion) */
							/* order = 4 = min number of keys per node? */
							/* 4 = (((NODESIZE-2)/(MAXKEYSZ+2)) / 2) - 1*/
#define FONT_SIZES		20 	// this is all we're gonna keep
#define MAXFILESIZE		WINPATHLEN+1
#define MAXTITLESIZE	WINPATHLEN+1
#define MAXFILTERSIZE	255  // up from 200 for AccuSoft filters
#define YYBLKSZ			512
// Worst case of a record that must be readable into a YXBUF structure seems
//  to be yxLINK2, which in RRW includes a fieldname, 2 paths, a tag, and an alias.
//  Since fieldnames and table names in RRW can be 127 bytes (Visual FoxPro),
//  800 seems big enough.
//  In RSW there's only one path, though, so even though fieldnames are potentially
//  long, with only one path, 600 seems big enough.
// Worst case in RSW seems to be yxCALC2, which includes a fieldname and a formula.
//  MAXFORMULA is 1024 and MAXDNAME is 129 in both products (at the moment),
//  so we better make YXBUFMAX 700 in RSW.
#if defined RSW
#define YXBUFMAX 700
#else
#define YXBUFMAX 800
#endif

// max size of right query comparand
#define MAX_EDIT	(50+3)*25	// list of 25 literals of length 50

// max size of prompt string for parameter prompting
#define MAX_PROMPT_STRING 256

/* cipconst.h */

/* field data lengths */
#define	DEFLEN	10	/* default field length */

#define	FLWDS	((FLMAX+1)/2)	/* max field length in words */
/**	NFWDS	was another name for FLWDS; let's use only one name, ok? **/

/* field name lengths */
#define	PLMAX	30	/* max report length (can't be > YMAX_NAME) */
#define	NLBYS	24	/* max create length (can't be > YMAX_NAME) */
#define	NLWDS	(PLMAX+1)/2	/* max field name length in words */

/* file name lengths */
#define	REPNAMELENGTH	WINPATHLEN	// max characters in a report name
#define	CIPnameLENGTH	30		// max characters in an old report name
#define	OSnameLENGTH	8	/* max characters in a DOS filename stem */
#define PATHLENGTH	WINPATHLEN	/*max len typed in path/filename (excl. NULL)*/

/* screen-oriented parameters */
#define	FIELDSPERSCR	20	/* rows per screen window */
#define	FIELDROW	0	/* top row of window */
#define	FIELDCOL	0	/* left column of window */

/* cip misc */
#define NOFLDS	40	/* max number of fields (can't be > YMAX_FLDS) */
#define SELMAX	10	/* max number of selection fields */
#define	SELEXBUF 512	/* size of selection expression buffer */

/* values of the yesno() family */
#define	ynYES	0
#define	ynNO	1
#define	ynABORT	2

//
// from DEFAULT.H
//
#define CUR_STR_MAX 15	/* max length of currency sign string, excl null */
#define LOG_STR_MAX 15	/* max length of logical string, excl null */
#define DATE_PIC_MAX	80
#define TIME_SUFFIX_MAX	8

#define wack(w,s)	wack1(w,s)
#define zack(s)		zack1(s)

/* report type values (RepType) */
#define REPNORM		0		/* normal report */
#define TESTPAT		1		/* test pattern */
#define PRSPEC		2		/* print specification */

/* Miscellaneous	*/
#define ACENT		1	/* center-align */
#define ALEFT		0	/* left-align */
#define ARIGHT		2	/* right-align */
#define ATTRMASK	(aBOLD|aITALIC|aUNDER|aSTRIKE)
#define CNTLENGTH	3	/* default length of Count field */
#define FONTMASK	0xF8	/* just the font value, please */
#define MAXPAGELINES	256	/* (was 14 inches x 8 lpi = 112) */
#define MAXRPITCH	30	/* maximum ruler pitch */
#define MINRPITCH	4	/* minimum ruler pitch   mjs 12/31/92 (was 5) */
#define NCOL		255	/* number of columns per line in screen buffer */
#define POINTSIZE	72	/* a point is 1/72 inches */
#define PGNOLENGTH	2	/* default length of page number field */
#define RPMISCNO	0	/* miscellany number for reports */
#define RPRANGEERR	5	/* invalid range in saved report */
#define RPREVERR	4	/* invalid report revision */
#define RPREADERR	3	/* error reading report */
#define RPMFCERR	6	/* MFC reported an error reading report */
#define NEARGRID  0	/* Align to nearest grid */
#define LEFTGRID  1	/* Align to left grid */
#define TOPGRID   2	/* Align to top grid */
#define RIGHTGRID  3	/* Align to right grid */
#define BOTTOMGRID 4	/* Align to bottom grid */
#define ANSI_DOT	183	/* space dot (Windows ANSI char set) */
#define OEM_DOT		250	/* space dot (OEM and special char sets) */

/* title string size */
	// <rep name> [+ " (template)"] + " - " [+ <data source> + " - "] + <prod name>
	// (rep name length has null already)
#if defined (RSW)
#define TITLESTRMAX	REPNAMELENGTH + 11 + 3 + SQL_MAX_DSN_LENGTH + 3 + 20
#else
#define TITLESTRMAX	REPNAMELENGTH + 11 + 3 + 20
#endif

/* text field alignment */
#define TXALIGN(f) (((LPTXFLD)(f))->txflags & 0x00F0)

/* 2D field alignment (use same values at text fields) */
#define TWODALIGN(f) (((LPRRBOX)(f))->thdr.align)

/* TOTALS PARAMETERS */
#define PAGETOT		0xFE		/* break level value for page total */
#define GRANDTOT	0xFF		/* break level value for grand total */

/* macros for totals flags and accumulators */
#define MINMAX(t)	(((t) == TMIN) || ((t) == TMAX))
#define GRAND(f)	((f)->dRecU.insS.brklevel == GRANDTOT)
#define PAGE(f)		((f)->dRecU.insS.brklevel == PAGETOT)
#define ORIGTOT(f)	(((f)->dRFlags & rfTOTALFLD) && !((f)->dFlags & zfDUPFLD))

/* Break Field Option Flags (brkFlags) */
							/* if bit is set:  */
#define bfRESPAGE	0x2		/* reset page number after this break */
#define bfPRBREAK	0x4		/* print break field data once per "group" */
#define bfSWAPFOOT	0x8		/* print break footer in place of page footer */
#define bfSWAPHEAD	0x10	/* print break header in place of page header */
#define bfREPRINT	0x20	/* reprint group header at top of page */
#define bfBURSTRPT	0x40	/* burst report at this break field */

/* Break Field Status (status) */
#define bsBROKEN	0x1		/* new group has started */
#define bsPRINTHD	0x2		// currently printing this group header
#define bsREPRINT	0x4		/* group header reprinted */
#define bsFLAGS		(bsBROKEN | bsPRINTHD | bsREPRINT)		/* all of 'em */

/* page band parameters */
#define	INTITLE		5			/* in report title  0x05 */
#define INHEAD		10			/* in page header   0x0A */
#define INBREAKH	20			/* in break header	0x14 */
#define INBODY		60			/* in body          0x3A */
#define INBREAKF	70			/* in break footer  0x46 */
#define INFILLER	90			/* in filler area   0x5A */
#define INSUMMARY	110			/* in summary area  0x6E */
#define INFOOT		120			/* in page footer   0x78 */

#define BRKHEAD(w)	(((w) >= INBREAKH) && ((w) < INBREAKH+NOBRKFLDS))
#define BRKFOOT(w)	(((w) >= INBREAKF) && ((w) < INBREAKF+NOBRKFLDS))
#define PAGEHF(w)	(((w) == INHEAD) || ((w) == INFOOT))
#define WRAP(w)		(((w) != INHEAD) && ((w) != INFOOT) && ((w) != INSUMMARY) && ((w) != INTITLE))

// sp 11/13/96 this macro used to be defined in 
// GENREP~1.H and WPIX.CPP as -> BANDINTABLE(p) (p==INBODY || p==INHEAD|| p==INTITLE || p==INBREAKH || p==INBREAKF || p==INFOOT || p==INSUMMARY)
// now check for all band headers and footers by calling BRKFOOT and BRKHEAD respecively
#define BANDINTABLE(p) (p==INBODY || p==INHEAD|| p==INTITLE || BRKFOOT(p) || BRKHEAD(p) || p==INFOOT || p==INSUMMARY)

#define SPOS(a,b)	zpos((int)(a),(int)(b))

/* group header print flavors (passed to prGrpHead()) */
#define PGH_YES		0		/* always print */
#define PGH_BREAK	1		/* print on break */
#define PGH_REPEAT	2		/* print repeat headers */

#define FIXROW(l)	((l)-(Line-Row))

/* buffered field data macros */

#define FLD_DATA(p)	(((char *)(p)) + sizeof(short))
#define FLD_SIZE(p)	(*((short *)((char *)(p))))

/* move or copy after marking or function key - stored in "Moving" */

#define MARKMOVE	1
#define MARKCOPY	2

/* horizontal/vertical dimension parameters */

/* horizontal */
#define HCL		0		/* columns */
#define HIN		1		/* inches */
#define HCM		2		/* centimeters */

/* vertical */
#define VIN		0		/* inches */
#define VLN		1		/* lines */
#define VCM		2		/* centimeters */
#define VLET	3		/* letter */
#define VLEG	4		/* legal */
#define VEXE	5		/* executive */
#define VA4		6		/* a4 */
#define VPT		10		/* points */

/* paper lengths - inches */
/* portrait */
#define PSIP_LETTER	1100	/* 11.00" */
#define PSIP_LEGAL	1400	/* 14.00" */
#define PSIP_EXEC	1050	/* 10.50" */
#define PSIP_A4		1170	/* 11.70" */
/* landscape */
#define PSIL_LETTER	850		/* 8.50" */
#define PSIL_LEGAL	850		/* 8.50" */
#define PSIL_EXEC	725		/* 7.25" */
#define PSIL_A4		830		/* 8.30" */

/* paper widths - inches */
/* portrait */
#define PWIP_LETTER	850		/* 8.50" */
#define PWIP_LEGAL	850		/* 8.50" */
#define PWIP_EXEC	725		/* 7.25" */
#define PWIP_A4		830		/* 8.30" */
/* landscape */
#define PWIL_LETTER	1100	/* 11.00" */
#define PWIL_LEGAL	1400	/* 14.00" */
#define PWIL_EXEC	1050	/* 10.50" */
#define PWIL_A4		1170	/* 11.70" */

/* paper lengths - centimeters */
/* portrait */
#define PSCP_LETTER	2794	/* 27.94 cm */
#define PSCP_LEGAL	3556	/* 35.56 cm */
#define PSCP_EXEC	2670	/* 26.70 cm */
#define PSCP_A4		2970	/* 29.70 cm */
/* landscape */
#define PSCL_LETTER	2159	/* 21.59 cm */
#define PSCL_LEGAL	2129	/* 21.59 cm */
#define PSCL_EXEC	1840	/* 18.40 cm */
#define PSCL_A4		2100	/* 21.00 cm */

#define MLEN_EXEC	2670	// tenths of a millimeter (Executive)
#define MWID_EXEC	1840
#define MLEN_LET	2794	// Letter
#define MWID_LET	2159
#define MLEN_LEG	3556	// Legal
#define MWID_LEG	2159
#define MLEN_A4		2970	// A4
#define MWID_A4		2100

/* multiple records across parameters */

#define MULTPTR(c,l)	((MultTab+((MultLines*c)+l))->data)
#define MULTLEN(c,l)	((MultTab+((MultLines*c)+l))->len)
#define MULTSTAT(l)		((MultTab+l)->status)
#define MULTHITE(l)		((MultTab+l)->hite)

// flags
#define MULT_DONE	0x1		// segment printed
#define MULT_PAGE	0x2		// page break

/********** Windows ***********/
/* misc parameters */
#define CARET_WIDTH		2		/* width of caret in field/band area */

/* field area scroll parameters */
#define VERTBANDJUMP	10		/* number of bands in page up/down */
#define MAXHORZINCHES	30		/* total inches to scroll horizontally */
#define HORZCOLJUMP		5		/* number of columns ctrl right/left */
#define HORZSCROLLJUMP	20		/* number of columns ctrl right/left */

#define IMAGE_FLD(f)	((((LPFLDHDR)(f))->hflags & IMAGEFLD) != 0)
#define CHART_FLD(f)	((((LPFLDHDR)(f))->hflags & CHARTFLD) != 0)
#define TEXT_FLD(f) 	((((LPFLDHDR)(f))->hflags & (DATAFLD|IMAGEFLD|CHARTFLD|BOXFLD|LINEFLD|OBJECTFLD)) == 0)
#define BOX_FLD(f)		((((LPFLDHDR)(f))->hflags & BOXFLD) != 0)
#define LINE_FLD(f)		((((LPFLDHDR)(f))->hflags & LINEFLD) != 0)
#define LINEBOX_FLD(f)	((((LPFLDHDR)(f))->hflags & (LINEFLD|BOXFLD)) != 0)
#define OBJECT_FLD(f)	((((LPFLDHDR)(f))->hflags & OBJECTFLD) != 0)
#define TWOD_FLD(f)		((((LPFLDHDR)(f))->hflags & (IMAGEFLD|CHARTFLD|BOXFLD|LINEFLD|OBJECTFLD)) != 0)
//
// Added DATA_FLD to help with sizing with mouse implementation.
//
#define DATA_FLD(f) 	((((LPFLDHDR)(f))->hflags & DATAFLD) != 0)

/* Bit settings for line/box sides and outlining modes */
#define bxLine		0x80		// its a line
#define bxLeft		0x01		// left side of box
#define bxRight		0x02		// right side of box
#define bxTop		0x04		// top side of box
#define bxBottom	0x08		// bottom side of box
#define bxAll		0x0F		// all sides
#define bxVert		0x40		// its a vertical line.
#define bxImage		0x20		// outlining an image
#define bxChart		0x10		// outlining a chart
#define bxImageField 0x100		// outline Image (from field)

#define BOX_TRANSPARENT	0xFF   	// box background is transparent
#define DEFAULT_HATCH	0xFF	// no hatch is good hatch
#define IMAGE_CLIPBOARD	0x1		// it's from clipboard

/* misc */
#define NOSORTFLDS		8			// max number of sort fields
#define NOBRKFLDS		NOSORTFLDS	// number of group fields

/* line flags */
#define WHENEJECT		0x01	// when-print eject-page bit
#define WHENPRINTING	0x02	// line will print
#define WHENMARKED		0x04	// line is marked
#define WHEN_IF_FALSE	0x08	// line logical s/b FALSE
#define WHEN_NORF		0x10	// no records found

/* line height values */
#define lnHtAUTO	0		/* automatic mode (default) */
#define lnHtPTS		1		/* value in points */
#define lnHtINCH	2		/* value in inches */
#define lnHtCENT	3		/* value in centimeters */

#define AUTOLINE(l)	(When[(l)].whenhtmode == lnHtAUTO)
#define FREELINE(l)	(When[(l)].whenhtmode != lnHtAUTO)

/* outputting report to printer, display or disk file?  (PrOpt[RPOUT]) */
#define PRINT		0	/* print report */
#define VIEW		1	/* view report */
#define DISK		2	/* report to disk */

/* "PrOpt" and "PrOptM" (non-windows) array offsets */
#define PLEN	0	/* page length */
#define TMARG	1	/* top margin */
#define BMARG	2	/* bottom margin */
#define MARG	3	/* right margin */
#define LMARG	4	/* left margin */
#define RECWID	5	/* record width */
#define BODLEN	6	/* body length - for laser labels */

/* below are "PrOpt" array offsets only */
#define CMPBL	7	/* compress body lines */
#define LPI		8	/* lines per inch */
#define NOCOP	9	/* number of copies */
#define NOBOD	10	/* suppress printing of body lines */
#define PAGEO	11	/* page orientation: portrait/landscape */
#define PRTR	12	/* printer */
//#define PAUSE	13	/* pause between pages */
#define COLLATE	13	// collate printed copies
#define RECUP	14	/* records across */
#define RPOUT	15	/* report destination */
#define COMP	16	/* pitch (10,12,Compressed) */
#define PRREC	17	/* Print which records? {Deleted,Non-Deleted,All} */
#define	NLSEMI	18	/* Begin new-line on semicolon? */
#define LEADING	19	/* Windows extra leading */
#define PGWID	20	/* page width */
#define XEPAGE	21	/* */
#define RECCOP	22	/* record copies */
#define SUMHF	23	/* page header/footer in summary area */
#define BRKBOD	24	/* break body across page? */
#define PTRAY	25	/* paper tray */
#define SNKCOLS	26	/* number of columns to snake */
#define ORDER	27	/* ACROSS then down, or DOWN then across */

#define PROPTSIZE (ORDER+1)	/* size of print options array */

/* memo field font/attribute indicators for wrapping routine */

#define MEMOAF		1		/* imbedded memo field font/attribute code */
#define MEMOEND		2		/* it's over */
#define MEMOAFSZ	3		/* memo on string size */
#define MEMOMF		0xFF	/* back to master font value, please */

/* ReportPass Values */
#define SORT_PASS	0		/* we're sorting */
#define ACCUM_PASS	1		/* we're accumulating */
#define CHART_PASS	2		// charting pass, precedes PRINT_PASS
#define PRINT_PASS	3		/* and finally, we're printing */

/* Version 4.0 attribute bits */
#define aBOLD		1		/* it's bold */
#define aITALIC		2		/* it's italic */
#define aUNDER		4		/* and it's also underscored */
#define aSTRIKE		8		// strike three, yur out!

/* maximum buffer size for picdata() & wrapper() output */
#define MXFPBUF		(FLMAX*2)

/* font status bits */
#define fntNEEDED	1		/* needed for this report */
#define fntLOADED	2		/* downloaded this session */

/* download types */
#define DOWN_ALL	0
#define DOWN_NEW	1
#define DOWN_SKIP	2

/****************************/
/* Common Internet Browsers */
/*                          */
/* added by CAS 11/14/2014  */
/* to address issues in     */
/* wexport.cpp when launch- */
/* ing browsers             */
#define LPI_INETEX "iexplore"
#define LPI_CHROME "chrome"
#define LPI_FIREFX "mozilla"
#define LPI_SAFARI "safari"
#define LPI_OPERA  "opera"

/* total types */
#define TCNT	0	/* count */
#define TSUM	1	/* sum */
#define TAVG	2	/* average */
#define TMIN	3	/* min */
#define TMAX	4	/* max */
#define TSTD	5	/* standard deviation */
#define TVAR	6	/* variance */

#define MEMTOT(t)	(((t) == TAVG) || ((t) == TVAR) || ((t) == TSTD))
//
// RSW Specific #defines
//
#if defined RSW
	//
	// MAXDNAME is the maximum field name length (from source file)
	//
	// XDB & Novell are 20, Oracle & Microsoft 30
	// PACE needs 39
	// 42 for Novell x 2 + dot + terminating null
	// Rumba needs 129

	// Define RSW6. This is used for code that is being added to RSW6.0 for
	// FCS, which should not be include in RRW6.0.
	#define RSW6	1
	// if you change MAXDNAME, change the line below defining MAXLABSZ
	//  and think about YXBUFMAX, too
	#define MAXDNAME 129
	//#define MAXSDNAME 11	// Short name length for DBF fields
	#define MAXSDNAME 31	// Short name length for DBF fields

#else	// end RSW
	//
	// RRW Specific #defines
	//
	//
	// maximum field name length (from source file)
	//
	// if you change MAXDNAME, change the line below defining MAXLABSZ
	//  and think about YXBUFMAX, too
	#define MAXDNAME 129
	#define MAXSDNAME 11	// Short name length for DBF fields

	// turn on read-ahead for RRW
	//
	#define READAHEAD	1

#endif

#define MAXLABSZ 129	// must be greater of the 2 MAXDNAMES (used in
							// worksheet export)
//
// MFFIELDNAMESIZE should be the larger for MAXCNAME+1 and MAXDNAME+1
//
#if defined RSW
	#define MFFIELDNAMESIZE MAXDNAME+1
#else	// end RSW
	#define MFFIELDNAMESIZE 32
#endif

#define DB4 1			// enable dBASE IV support


//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//

// put globals here:


//
// Function Prototypes Section:
// Place in this section any function prototypes
//

//extern int (*ZFCmpP)(char far *left,char far *right,int exact,int flat);
extern int (*ZFCmpP)(char *left,char *right,int exact,int flat);
//extern int (*ZFCmpP1)(char far * far *left,char far * far *right);
extern int (*ZFCmpP1)(char * *left,char * *right);
//extern int (*ZFCmpPsort)(char far *left,char far *right);
extern int (*ZFCmpPsort)(char *left,char *right);
//extern int (*ZFKlCmpP)(char far *left,char far *right,int lgt,int exact,int flat);
extern int (*ZFKlCmpP)(char *left,char *right,int lgt,int exact,int flat);

// This cuts C++ compile times in half.  Thanks for the idea, Dave.
 #ifdef __cplusplus

  #ifdef RSW
#define QE_WIN32 1	// for QELIB.H
  #endif

#include "rrdoc.h"
#include "rrcompos.h"
#include "rrrepio.h"
#include "cntritem.h"  // CRrCntrItem

  #if (defined(RUNDLL) && !defined(RRCONVERT))
#include "rrdll.h"
#include "printdlg.h"
  #endif
  
  #if !defined INTERACTIVE
#include "rrruntim.h"
  #endif

 #endif

#endif // end _PRODUCT_H_

// *************************** End of File ************************************
