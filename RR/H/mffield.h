// ****************************************************************************
//
//      (C) Copyright 1992-1993 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $Workfile:   mffield.h  $
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
// $Log:   D:/R&R Project/archives/H/MFFIELD.H_V  $
// 
//    Rev 1.22   09 Sep 2004 08:04:22   Nick
// Max size 30 chars for name
// 
//    Rev 1.21   02 Jul 2004 13:27:16   Nick
// Lengthen names to 30 characters
// 
//    Rev 1.20   Oct 03 2003 14:12:38   Admin
// Rename structure for some reason
// 
//    Rev 1.19   Oct 31 2002 16:02:50   Admin
// Prettify and add parameter bit
// 
//    Rev 1.18   Sep 05 2002 12:20:48   Admin
// Add a chunk for dictionary attributes
// 
//    Rev 1.17   Jul 11 2001 14:20:50   nhubacker
// Add dMaxLenP
// 
//    Rev 1.16   Feb 27 2001 15:35:00   nhubacker
// Parameter additions
// 
//    Rev 1.15   Dec 12 2000 15:53:46   nhubacker
// Define f3GRPAGE flag bit
// 
//    Rev 1.14   Aug 30 1999 15:43:24   BUILD
// ARP20001
// 
//    Rev 1.13   09 Jun 1997 18:24:58   dlm
// Part of change necessary to allow us to chart cumulative and record
//  data in single chart.  Added ChartBreakLevel to totals part of MFFIELD
//  structure.
// 
//    Rev 1.12   26 May 1997 16:55:48   dlm
// Part of fix to WO 130460.  Added BreakLevel to calcInfo structure so
//  that fromtots have a nominal break level.
// 
//    Rev 1.11   29 Apr 1997 16:58:36   par
// First pass at filtering angle brackets from HTML stream.
// 
//    Rev 1.10   21 Mar 1997 17:13:58   dlm
// Added f2INCHART flag to indicate that a field is needed by a chart.
// 
//    Rev 1.9   14 Mar 1997 15:38:52   SRM
// chart support initial checkin
// 
//    Rev 1.8   06 Jun 1996 14:21:26   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.7   21 Mar 1996 16:45:12   jpb
// VFP3 nulls
// 
//    Rev 1.6   20 Oct 1995 13:33:58   par
// The OLE objects are now connected to the R&R lists. More work needs to be done but this is a good 
// start.
// 
//    Rev 1.5   22 Sep 1995 10:22:52   jpb
// sindex now FLDID
// 
//    Rev 1.4   19 Sep 1995 11:50:08   par
// MFBYINDEX macro needed to be adjusted for composite pointer.
// 
//    Rev 1.3   07 Jul 1995 18:11:40   jpb
// First pass at moving all data and functions to CRrDoc class
// 
//    Rev 1.2   25 Apr 1995 08:56:10   sbc
// Merge 6.1.03 -> 7.0.01
// 
//    Rev 1.1   27 Mar 1995 13:33:12   mjs
// Moved alignment literals into align.h, so pd does not have to bring in
// all this MF stuff.
// 
//    Rev 1.0   16 Mar 1995 16:12:56   sbc
// Initial revision.
// 
//    Rev 1.16   28 Mar 1995 14:11:38   dlm
// Added dFldPic2 MFFIELD structure member for time picture formats.
// 
//    Rev 1.15   08 Feb 1995 13:29:42   sjo
// Checking in a bunch of files for the first wave of datetime support. These
// sources have support for a dFlags that is a long (not an unsigned int) and
// it recognizes date, time and datetime fields.  It only supports dates at
// this time, because we need calcs, picture types, etc if we are to do time and
// datetime.
// 
//    Rev 1.14   20 Jan 1995 16:02:44   mjs
// Added typedef names so C++ doesn't complain about them.
// 
//    Rev 1.13   31 Aug 1994 16:00:00   dlm
// Defined f2QNEED for use by mfeord.c to facilitate early application
//  of query.
// 
//    Rev 1.12   18 Jul 1994 16:47:26   jpb
// Add field specifier members for conditional totals
// 
//    Rev 1.11   08 Jun 1994 12:29:04   erp
// changed FAR to far, so it will build for 32-bits
// 
//    Rev 1.10   11 May 1994 11:19:00   dlm
// Changed arguments to mfcalc() so it can behave appropriately whether it
//  was called from winst.c or datadict.c.
// 
//    Rev 1.9   03 May 1994 12:53:02   dlm
// Merge from Abra branch:  mfcalc() now takes three arguments.
// 
//    Rev 1.8   05 Apr 1994 12:25:34   dlm
// Added #defines for f3HIDEFILT and f3HIDEINST flags for new data
//  dictionary features.
// 
//    Rev 1.7   21 Mar 1994 13:37:48   dlm
// Added GLOBAL for MFQDisambiguate - used to disambiguate field references
//  in record-level filter.
// 
//    Rev 1.6   21 Mar 1994 11:52:20   dlm
// Merge of Abra branch:
//  Added dTmpLnk, dShowType, dSecurity, conditional on DATADICT to MFFIELD
//   structure.
//  Added dFlags3 and definition of f3PREDEFINED.
// 
//    Rev 1.5   27 Jan 1994 15:06:28   nwh
// Added efNULL for sort
// 
//    Rev 1.4   21 Jan 1994 14:21:16   nwh
// Added f2QEVAL for early query eval
// 
//    Rev 1.3   19 Nov 1993 17:44:26   sbc
// Add extern C for C++
// 
//    Rev 1.2   08 Nov 1993 11:09:46   smh
// Added f2NOTONCE (don't let this calc into MFEvalOnce chain because it's one
// the engine will evaluate) flag for fix to rsw bug 575.
// 
//    Rev 1.1   29 Oct 1993 16:33:52   jpb
// Clean up sources to remove compiler warnings
// 
//    Rev 1.0.1.2   03 May 1994 11:04:56   dlm
// Adjusted prototype of mfcalc() to define new arg that tells it whether
//  or not to call mfeord().  Also changed mfcalc.c, datadict.c, winst.c.
// 
//    Rev 1.0.1.1   28 Feb 1994 11:08:20   dlm
// Added conditionals around data-dictionary-related field structure
//  members.
// 
//    Rev 1.0.1.0   11 Jan 1994 10:43:04   dlm
// Add definition of dTmpLnk for use by mfchgfil() with predefined calcs.
// Add definitions of dShowType and dSecurity for data dictionary info.
// 
//    Rev 1.0   14 Oct 1993 10:12:18   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _MFFIELD_H_

//
// Make a definition for this module.
//
#define _MFFIELD_H_

#include "wfield.h"
#include "align.h"	// for txRIGHT, etc.
#include "afxtempl.h"

#if defined (_MFGETFLD_C_)
 #define GLOBAL
#else
 #define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

#define MAXFLDBUF 512		// max field data buffer size (DIALOG)
#define DBMAXFLDBUF 254		// max field data buffer size (non-DIALOG)
#define MAXMEMOBUF 254		// max memo data buffer size
//#define MAXCNAME 11			// max length create name
#define MAXCNAME 31			// max length create name (including terminator)

#if 0	// now in align.h
// alignment
#define txLEFT		0x10	// left
#define txCENTER	0x20	// center
#define txRIGHT		0x30	// right
#endif

// dError flags
// efERR, efNA, efCNV are also used in sort packets.
// efNULL is only used in sort packets and must not be included in ERRORS.

#define efERR		0x01		// set=> ERR value
#define efNA		0x02		// set=> NA value
#define efCNV		0x04		// set=> conversion error
#define efNULL		0x08		// set=> null numeric/date (used in sort)
#define efPREVERR	0x10		// prev(efERR)
#define efPREVNA	0x20		// prev(efNA)
#define efPREVCNV	0x40		// prev(efCNV)

#define ERRORS (efERR|efNA|efCNV)				  // composite error bits
#define PREVERRORS (efPREVERR|efPREVNA|efPREVCNV) // and prev error bits

// dRFlags - "report writer" flags

#define rfDELETED	0x01		// field is "deleted"
#define rfTOTALFLD	0x02		// field is a total
#define rfPRONCE	0x04		// printed once for group
#define rfNULL		0x08		// null data flag
#define rfFINALTOT	0x10		// what the heck, make two passes...
#define rfPREVMEM	0x20		// signals prev of a memo field
#define rfSELFREF	0x40		// signals self-referencing calc

#ifdef RSW
#define rfNOQUERY	0x80		// don't pass this sucker to SQL engine
#else
#define rfLOOKUP	0x80		// uses xlookup()
#endif

// dRecU.insS.totfreq settings
// totfreq values are either break levels (0-7) or these special values

#define tfEOR	0xFF		// accumulate at end of report
#define tfPAGE	0xFE		// accumulate at end of page
#define tfCOMP	0xFD		// accumulate for every composite
#define tfAUTO	0xFC		// totals: when new record at scan level
							// total of total: at source total reset freq

#define tfMAGIC tfAUTO		// lowest non-break accumulate frequency

// mfgetfld() & mfrlsfld() option word bits
#define MFOCNAME	0x0001		// attach name buffer
#define MFONOUPD	0x0002		// don't update saved internal indices
#define MFONONDX	0x0004		// update everything but DUP indexes

/* flag bits in hflags byte of header structure */

#define MARKED		   0x0001	// field is marked for move/copy/delete
#define NOTRIM		   0x0002	// please DON'T trim the field to my right
#define DEL_FLD		   0x0004	// field is "Edit Deleted"
#define DEL_FONT	   0x0008	// mark single field for font delete
#define IMAGEFLD	   0x0010	// a bitmap image
#define CLIP_FLD	   0x0020	// field has been cut/copied, ready to paste
#define LINEFLD		   0x0040	// line-type field
#define DATAFLD		   0x0080	// it's a data field
// 04/29/97 PAR.  Dave and I just noticed that only one byte is saved to a 
// report library.  This means that the upper byte will get lost, including the HTML angle flag. 
#define BOXFLD		   0x0100	// box-type field
#define OBJECTFLD      0x0200   // OLE object field
#define CHARTFLD       0x0400   // chart field
#define HTMLALLOWANGLE 0x0800   // 04/29/97 PAR. Don't convert angle brackes < and > to &lt; and &gt; in HTML output. 

// macro to form pointer to field specifier
#define MFBYINDEX(i) (m_pComposite->mfbyndx(i))

/*	 magic dFileNo values
NOTE:	all magic file numbers should have bit 0x80 set, as they are
		sometimes test for that way
*/
#define fnNONE		0xFF	// no file, field is in MFEvalOnce chain
#define fnCOMPOSITE	0xFE	// "bottom scanner" file
#define fnUNKNOWN	0xFD	// used in readrep
#define fnMEMO		0xFC	// memo file (SQL version only)
#define fnLIMBO		0xF0	// puts file in limbo when changing files

/* dFlags2 bit definitions */

#define f2INCHES	0x0001	// truncate to inches
#define f2FROMDB	0x0002	// set for calc if dependant on database field
#define f2CENT		0x0004	// truncate to centimeters
#define f2FRMQRY	0x0008	// query() or derived from query()
#define f2GOTFIN	0x0010	// this final total gotten in last buildfinals
#define f2RESMIX	0x0020	// this fromtots from mix of resets levels
#define f2FROMPT	0x0040	// this fromtots from a page total
#define f2OLDNDX	0x0080	// used by readrep() to signal old sindex
#define f2DUMMY		0x0100	// used to flag a dummy linking (or locate) field
#define f2DSPLEN	0x0200	// display data length in status bar
#define f2QEVAL		0x0400	// evaluate query after evaluating this field
#define f2QNEED		0x0800	// used in mfeord.c to track fields used in query

/* 0x0400 was RR5 flag that are not currently being used.
	FLFMT indicates if a #ic fld's dFldP data has been converted to float, 
		or is just in string form.  Performance improvement so may use again.
		Talk to Phil about it.
*/


/*	this is defined so that explt can set it in the 2 byte flags (dFlags)
	for UDFs derived from lookup.  Calc derived from lookup still signalled
	by rfLOOKUP of dRFlags.  (What a kludge!)
*/
#define f2LOOKUP  0x1000	// field involves a lookup function
#if defined(RSW)
#define f2INworkFILE	0x2000	/* This field's data was fetched into QE work
								   file in last read next pass */
#define f2SQLENG  0x4000  // This calc field is an engine evaluatable string

 #if !defined(INTERACTIVE)
/* Means f2SQLENG, derived from f2SQLENG, or fld has translation. Used to 
	xclude flds frm MFEvalOnce chain fr printing titl & sum bands when no recs 
	found in runtime.
*/
#define f2NOTONCE 0x8000
 #endif
#endif
#define f2INCHART	0x10000		// field used in one or more charts - tested in clrTot()

// dFlags3 bit definitions
#define f3PREDEFINED	 0x0001	// predefined calculation from data dictionary
#define f3HIDEFILT		 0x0002	// RUNTIME only - hide this field from interactive query field lists
#define f3HIDEINST		 0x0004	// don't use this field in instant reports
#define f3LASTPAGE		 0x0008 // Lastpage function
#define f3PARAM			 0x0010 // It's a parameter(R)
#define f3PARAMLIST		 0x0020 // It's a parameter(R) static list

// DIALOG field data types
#define DC 1	// DIALOG character type
#define DD 2	// DIALOG date type
#define DI 3	// DIALOG integer type
#define DL 4	// DIALOG logical type
#define DN 5	// DIALOG numeric type
#define DM 6	// DIALOG memo type
#define DLO 1	// lowest supported DIALOG field type
#define DHI 6	// highest supported DIALOG field type

// VFP3 field flags
#define VFPSYSFLD	0x01
#define VFPNULLABLE	0x02
#define VFPBINARY	0x04

// action types for sql_expinfo and mf_expinfo.
#ifdef RSW
#define SETTYPE 1
#define GETTYPE 2
#endif

// macros to set/get dMaxLen int from component bytes
#define GETML(f)	((f)->dMaxLen + ((f)->dRecU.calcS.dMaxL2<<8))
#define SETML(f,l)	f->dMaxLen=(UONE)l; f->dRecU.calcS.dMaxL2=(l>>8);


//	field flag bit definitions
//	used by read field, isam, cip


#define zfPREV			0x000001	// calculated PREV() derivative
#define zfDUPFLD		0x000002	// a duplicate field
#define zfNUMERIC		0x000004
#define zfCALCULATED	0x000008
#define zfTEMP1			0x000010	// available as short-term temp
#define zfTEMP2			0x000020	// available as short-term temp
#define zfFROMTOT		0x000040	// calc'd fld derived from a total
#define zfNOTinREC		0x000080
#define zfLOGICAL		0x000100	// for DBASE files
#define zfDATE			0x000200
#define zfRECNO			0x000400	// composite record number-related
#define zfPAGENO		0x000800	// field is pageno() function
#define zfLINK			0x001000	// for multi-file

#define zfTEXT			0x002000
#define zfMEMO			zfTEXT

#define zfPREVARG		0x004000
#define zfTWOD			0x004000	// for dalign.c 

#define zfNEEDED		0x008000
#define zfDATETIME		0x010000
#define zfTIME			0x020000

// zfERROR is used only by yeval, yrecalc, and dispfld
// bit is in yRFlags
#define zfERROR			0x000008

// Parameter flags (dPFlags)
#define pPROMPT			0x01		// prompt at runtime
#define pREPLACE		0x02		// replace default value
#define pCHANGE			0x04		// parameter has changed

//
// Structure Section:
// Place in this section any structure definitions.
//
//
// The ascii structure should stay with the mffield structure.
//
typedef struct ascii
{
	long	dStart;		// start of memo data
	long	dEnd;		// end to memo data
} ASCII;

// definition of the parameter list element
typedef struct	{
	CString	value ;
	CString	desc ;
	bool	def ;
	bool	dynamic;
	CString	dynamicPath ;
	CString	dynamicField ;
	CString	dynamicLen;
} ParamListElement ;

#define PLArray CArray<ParamListElement, ParamListElement>

// engInfo and fileInfo should stay with mffield, since they are only used
// to define mffield.
//
#ifdef RSW
typedef struct engInfo
{
	char	fType;		// field type
	int		fDBType;	// underlying database field type
	void	*recBuf;	// initial buffer for record data (pre-conversion)
	unsigned int precision; 	// for decimal type only
	unsigned int scale;	// for decimal type only
	long	dDataLen; 	// internal data length (All)
	long	fetchLen; 	// fetched data length indicator
	CString *pColName;	// for value list support
	CString *pTblName;	// for value list support
	CString *pTblAlias;	// for value list support
} ENGINFO;
#else
typedef struct fileInfo
{
	// file-related information
	unsigned int dOffset;		// offset in internal record
	unsigned int dDataLen;		// length in data rec (wks width or memo endrow)
	unsigned int dNullFldNo;	// ist nullable in file is 1, next 2, etc.
	char	dDecimals;			// number of dec places in dBASE file, if numeric
	char	dFTemp;				// used by MFRENDX()
	char	dDataType;			// platform data type (for DIALOG support)
	// end of file-related information
} RRFILEINFO;
#endif

//
// calcInfo should stay with mffield since it is only used to define mffield.
//
typedef struct calcInfo
{
	// calculated field information
	char	*dExpD;		// displayable expression (NULL terminated)
	char	*dExpDP;	// original parameter expression
	char	*dExpE;		// evaluatable expression
	int		dExpELen;	// length of executable expression
	char	*dExpEP;	// original parameter evaluatable expression
	int		dExpEPLen;	// original parameter length of executable expression
	char	dMaxLenP;	// original dMaxLen
	char	dMaxL2;		// high order of dMaxLen
#ifdef RSW
	char	*dExpX;		// translated, engine evaluatable form
#endif
#if defined(DATADICT)
	char	*dTmpLnk;	// temp link used by mfchgfil() with PREDEFINED calcs
#endif
	int		BreakLevel;	// for charting, calcs have a nominal break level that
						//  indicates when values should be captured, where
						//		0 -> grand
						//		1..NOBRKFLDS -> break level
						//		NOBRKFLDS+1 -> every record
	char	*pExpD;		// displayable parameter validate expression
	char	*pExpE;		// evaluatable parameter validate expression
	int		pExpELen;	// length of executable expression
	unsigned long pExpT;// parameter validate expression result type
	void	*pList ;
	// end of calculated field information
} CALCINFO;

//
// noRecInfo should stay with mffield since it is only used to define mffield.
//
typedef struct noRecInfo	// not-in-record information
{
	char	ttype;			// Count, Sum, Avg, Min or Max
	char	brklevel;		// break level if subtotal, flag if page/grand
	char	totfreq;		// total accumulation frequency
	long	count;			// count value for Average
	double	sum;			// sum value for Average
	double	sumx;			// sum value for STD/VAR
	char	*tExpD;			// displayable conditional expression
	char	*tExpE;			// evaluatable conditional expression
	int tExpELen;			// length of executable expression
	unsigned long tExpT;	// condition expression result type
	int		ChartBreakLevel;// nominal break level for charting value capturing
} NORECINFO;

typedef struct mffield
{
	struct fieldhdr fhdr;		// field header structure
	struct mffield	*dNxtFld;	// next field in linked list
	struct mffield	*dNxtEval;	// next fld in eval/lookup order sequence
	unsigned long	dFlags;		// field flags
	unsigned int	dFlags2;	// more field flags for Guido
	unsigned int	dFlags3;	// yet more flags; Guido can't have 'em
	char			dRFlags;	// report writer flags
	char			dMaxLen;	// calculated field buffer size
	char			dCNameP[MFFIELDNAMESIZE];	// name string
	char			*dFldP;		// pointer to record data (not needed til go time)
	char			*comment;	// pointer to description (not needed at go time)
	char			*prompt ;	// prompt instructions for parameter fields
	char			*promptName ;// prompt name for parameter fields
	char			*error ;	// prompt error for parameter fields
	int				porder ;	// prompt order for parameter fields
	char			dPFlags ;	// for parameter fields
#if defined(DATADICT)
	char			dShowType;	// show data type and length if non-zero
	int				dSecurity;	// security level
	struct {
	 unsigned int	dLength ;
	 unsigned int	dFldPic ;
	 char			dDecPl ;
	 char			align ;
	} dict ;
#endif
	struct fieldsnap *dSS;		// attached snapshot structure pointer
	char			dFileNo;	// file number of field's source file
	char			dLinkCnt;	// number of files linked to via this field
	FLDID			sindex;		// source field MFBYINDEX value
	struct temp					// different kinds of temps
	{
	  int			tempI;		// an int
	  char			*tempP;		// a pointer
	} dTemp;
#ifdef RSW
	struct engInfo	engS;		// engine-related
	CStringList*	dValList;
#endif
	union recordU				// file/totals record union
	{
#ifndef RSW
		struct fileInfo fileS;	// file-related (in rec)
#endif
		struct noRecInfo insS;	// inserted field (not in rec)
		struct calcInfo calcS;	// calculated field (not in rec)
		struct ascii asciiS;	// ASCII memo file field
	} dRecU;
	unsigned int	dLength;	// field length
	char			dDecPl;		// decimal places
	unsigned int	dFldPic;	// field picture
	unsigned int	dFldPic2;	// more picture bits (times/datetimes only for now)
	char			dError;		// ERR/NA/conversion-error flags (see below)
	char			dTpError;	// ERR/NA/conversion-error flags for dTemp data
	unsigned int	wrapInd;	// index into wrapped data when printing
} MFFIELD;
typedef MFFIELD far * LPMFFIELD;

//
// Global Data Section:
// Place in this section any global data.
//

#if 0

GLOBAL LPMFFIELD DFBadFld;
#if 0	// MFC conversion - this isn't referenced
GLOBAL unsigned int MFQDisambiguate
 #if defined (_MFINIT_C_)
	= FALSE
 #endif
	;
#endif
GLOBAL char * near mflimbonm;  // moved from _mffield.h

#endif


//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#if 0
extern	int bf(unsigned int ndx);
extern	int df(unsigned int ndx);
extern	void fixdupnames(void );
extern	int lmfgetndx(struct mffield far *fld);
extern	struct mffield far *mfbyndx(int i);
extern	struct mffield far *mfcalc(char *name,char *expr,BOOL fromdd, struct mffield far *firstfld);
extern	int mfdelcnt(void);
extern	void mfdelfld(void );
extern	struct mffield far *mfdupfld(struct mffield far *fld);
extern	struct mffield far *mfeord(void );
extern	int mfflagall(int links);
extern	int mfflagcalc(void );
extern	int mfflagem(void );
extern	void mffreecb(struct mffield far *f);
extern	struct mffield far *mfgetfld(int o);
extern	int mfhifinal(void );
extern	int MFQInit(void);
extern	void MFQRelease(void);
extern	int sf(unsigned int ndx);
extern	int tf(unsigned int ndx);
extern	int totOkay(int level,struct mffield far *fld);

#endif

#undef GLOBAL

#endif // end _MFFIELD_H_

// *************************** End of File ************************************

