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
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/H/_CFMISC.H_V  $
//
// Rev 1.81    08 Mar 2017 09:47:09   CAS
// Test adding a FieldValue() function which returns the value of the
// field in the argument (which can be a calculated field)
// so, if a field P_LNAME contains the value "STRASSER" then 
// FieldVal("P_L" + "NAME") returns "STRASSER"
// 
//    Rev 1.8   Jan 19 2001 14:03:08   nhubacker
// Functions for lastpage(0) and reportpage()
// 
//    Rev 1.7   Dec 12 2000 15:51:34   nhubacker
// Add TGRPAGE
// 
//    Rev 1.6   Aug 30 1999 15:43:30   BUILD
// ARP20001
// 
//    Rev 1.5   30 Nov 1998 14:35:40   wrr
// Added 134154
// 
//    Rev 1.4.2.1   30 Nov 1998 14:34:48   wrr
// Added 134154
// 
//    Rev 1.4.2.0   15 Jul 1998 11:41:52   wrr
// Code ported from 16bit to 32bit
// Jim added percomp()
// WO157195
// 
//    Rev 1.4   06 Jun 1996 14:12:42   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.3   20 Jul 1995 16:39:18   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.2   27 Apr 1995 12:37:28   sjo
// Merge of 6.1.03+.  I say + because I have added some of the time functions
// to this merge, which will be a part of 6.1.04.  I merged the CF directories
// and some H files (for the time function changes).
// 
//    Rev 1.1   26 Apr 1995 10:38:56   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.10.1.0   18 May 1998 17:44:50   jpb	//WRR 7/1/98 WO157195
// Add percomp function
// 
//    Rev 1.0   16 Mar 1995 16:14:14   sbc
// Initial revision.
// 
//    Rev 1.9   03 Apr 1995 15:48:06   pjm
// Add DTLOOKUP reference.
// 
//    Rev 1.8   29 Mar 1995 16:57:58   jpb
// add UFLAGS2
// 
//    Rev 1.7   27 Mar 1995 19:33:42   sjo
// Added support for new DT functions.
// 
//    Rev 1.6   23 Mar 1995 17:09:52   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
// 
//    Rev 1.5   18 Jan 1995 17:50:50   sjo
// Made changes to remove compiler warnings.
// 
//    Rev 1.4   21 Jul 1994 08:58:32   vff
// Updated to add TISNULL for isnull() function
// 
//    Rev 1.3   16 Jun 1994 10:48:16   vff
// Merged RR6 functions into R?W
// 
//    Rev 1.2   08 Jun 1994 14:43:00   erp
// changed FAR to far, so it will build for 32-bits
// 
//    Rev 1.1   19 Nov 1993 17:43:46   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:12:14   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __CFMISC_H_

//
// Make a definition for this module.
//
#define __CFMISC_H_

#include "cfmisc.h"
#include "libio.h"
#include "time.h"

#if defined(_COMPDATA_C_)
 #define GLOBAL
#else
 #define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
	// from udf.h
/* udf library record types */
#define UBEG 1		/* beginning marker */
#define UEND 2		/* end marker */
#define UFUNC 3		/* function number */
#define UFLAGS 4 	/* udf "output" flags */
#define UDECL 5		/* declaration string */
#define UFORM 6		/* formula string */
#define UHELP 7		/* help code */
#define UFLAGS2 8 	/* long (added with datetime support) udf "output" flags */

/* udf version number */
#define UREV 1

//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//

GLOBAL char NEAR CLPAREN  
#if defined (_COMPDATA_C_)
= '('	// left paren
#endif
;

GLOBAL char CEQ	     
#if defined (_COMPDATA_C_)
= '='	// equality test
#endif
;

GLOBAL char CGT	     
#if defined (_COMPDATA_C_)
= '>'	// greater than - used in    >     >=     and <>
#endif
;

GLOBAL char CDOTREP  
#if defined (_COMPDATA_C_)
= '!'	// used internally by compiler after pre-pass
#endif
;

GLOBAL char CDBLQ	  
#if defined (_COMPDATA_C_)
= '"'	// double quote string delimiter
#endif
;

GLOBAL char CSNGLQ	  
#if defined (_COMPDATA_C_)
= '\''	// single quote string delimiter
#endif
;

GLOBAL char CLBRAK	  
#if defined (_COMPDATA_C_)
= '['	// left bracket string delimiter
#endif
;

GLOBAL char CLBRACE  
#if defined (_COMPDATA_C_)
= '{'	// left curly brace date delimiter
#endif
;

/* ************************************************************ */

GLOBAL char CRBRAK	    
#if defined (_COMPDATA_C_)
 = ']'	// right bracket string delimiter (not part of above table)
#endif
;

GLOBAL char CRBRACE    
#if defined (_COMPDATA_C_)
 = '}'	// right curly brace date delim (not part of above table)
#endif
;

GLOBAL char CDOT	    
#if defined (_COMPDATA_C_)
 = '.'	// decimal point character (not part of above table)
#endif
;

//
// These are date separator characters used by the CTOD function
//
GLOBAL char near DSEPS	[]
#if defined (_COMPDATA_C_)
 =    {' ',	// mm dd yy
	                '-',	// mm-dd-yy
	                '/',	// mm/dd/yy
	                '.',	// mm.dd.yy
	                '\0'}	// end of table
#endif
;

//
// These are the full names of R&R calculated field functions.
// They must be unique in their first four characters.
//
GLOBAL 	char NEAR TABS	  [] 
#if defined (_COMPDATA_C_)
= "ABS"
#endif
;

GLOBAL 	char NEAR TADDDAYS [] 
#if defined (_COMPDATA_C_)
= "ADDDAYS"
#endif
;

GLOBAL 	char NEAR TADDMONS [] 
#if defined (_COMPDATA_C_)
= "ADDMONS"
#endif
;

GLOBAL 	char NEAR TADDWKS  [] 
#if defined (_COMPDATA_C_)
= "ADDWKS"
#endif
;

GLOBAL 	char NEAR TADDYRS  [] 
#if defined (_COMPDATA_C_)
= "ADDYRS"
#endif
;

GLOBAL 	char NEAR TASC	  [] 
#if defined (_COMPDATA_C_)
= "ASC"
#endif
;

GLOBAL 	char NEAR TAT	  [] 
#if defined (_COMPDATA_C_)
= "AT"
#endif
;

GLOBAL 	char NEAR TBLNKNUM [] 
#if defined (_COMPDATA_C_)
= "BLANKNUM"
#endif
;

GLOBAL 	char NEAR TCAPS	  [] 
#if defined (_COMPDATA_C_)
= "CAPFIRST"
#endif
;

GLOBAL 	char NEAR TCASE	  [] 
#if defined (_COMPDATA_C_)
= "CASE"
#endif
;

GLOBAL 	char NEAR TCDOW	  [] 
#if defined (_COMPDATA_C_)
= "CDOW"
#endif
;

GLOBAL 	char NEAR TCHR	  [] 
#if defined (_COMPDATA_C_)
= "CHR"
#endif
;

GLOBAL 	char NEAR TCMONTH  [] 
#if defined (_COMPDATA_C_)
= "CMONTH"
#endif
;

GLOBAL 	char NEAR TCTOD	  [] 
#if defined (_COMPDATA_C_)
= "CTOD"
#endif
;

GLOBAL 	char NEAR TDATE	  [] 
#if defined (_COMPDATA_C_)
= "DATE"
#endif
;

GLOBAL 	char NEAR TDAY	  [] 
#if defined (_COMPDATA_C_)
= "DAY"
#endif
;

GLOBAL 	char NEAR TDAYSBTW [] 
#if defined (_COMPDATA_C_)
= "DAYSBTWN"
#endif
;

#ifndef RSW
GLOBAL 	    char NEAR TDBF	  [] 
#if defined (_COMPDATA_C_)
= "DBF"
#endif
;
#endif

#ifndef RSW
GLOBAL 	    char NEAR TDELETED [] 
#if defined (_COMPDATA_C_)
= "DELETED"
#endif
;
#endif

GLOBAL 	char NEAR TCDLL	  [] 
#if defined (_COMPDATA_C_)
= "CDLL"
#endif
;

GLOBAL 	char NEAR TDOW	  [] 
#if defined (_COMPDATA_C_)
= "DOW"
#endif
;

GLOBAL 	char NEAR TDQTR	  [] 
#if defined (_COMPDATA_C_)
= "DQTR"
#endif
;

GLOBAL 	char NEAR TDTOC	  [] 
#if defined (_COMPDATA_C_)
= "DTOC"
#endif
;

GLOBAL 	char NEAR TERROR	  [] 
#if defined (_COMPDATA_C_)
= "ERROR"
#endif
;

GLOBAL 	char NEAR TEXP	  [] 
#if defined (_COMPDATA_C_)
= "EXP"
#endif
;

GLOBAL 	char NEAR TFLIP	  [] 
#if defined (_COMPDATA_C_)
= "FLIP"
#endif
;

#ifndef RSW
GLOBAL 	    char NEAR THISCOPE [] 
#if defined (_COMPDATA_C_)
= "HISCOPE"
#endif
;
#endif

GLOBAL 	char NEAR TIIF	  [] 
#if defined (_COMPDATA_C_)
= "IIF"
#endif
;

GLOBAL 	char NEAR TINLST	  [] 
#if defined (_COMPDATA_C_)
= "INLIST"
#endif
;

GLOBAL 	char NEAR TINRNG	  [] 
#if defined (_COMPDATA_C_)
= "INRANGE"
#endif
;

GLOBAL 	char NEAR TINT	  [] 
#if defined (_COMPDATA_C_)
= "INT"
#endif
;

GLOBAL 	char NEAR TISALPHA [] 
#if defined (_COMPDATA_C_)
= "ISALPHA"
#endif
;

GLOBAL 	char NEAR TISBLANK  [] 
#if defined (_COMPDATA_C_)
= "ISBLANK"
#endif
;

GLOBAL 	char NEAR TISLOWER [] 
#if defined (_COMPDATA_C_)
= "ISLOWER"
#endif
;

GLOBAL 	char NEAR TISUPPER [] 
#if defined (_COMPDATA_C_)
= "ISUPPER"
#endif
;

GLOBAL 	char NEAR TLEFT	  [] 
#if defined (_COMPDATA_C_)
= "LEFT"
#endif
;

GLOBAL 	char NEAR TLEN	  [] 
#if defined (_COMPDATA_C_)
= "LEN"
#endif
;

#ifdef RSW
GLOBAL 	    char NEAR TLIKE	  [] 
#if defined (_COMPDATA_C_)
= "LIKE"
#endif
;

GLOBAL 	char NEAR TISNULL  [] 
#if defined (_COMPDATA_C_)
= "ISNULL"
#endif
;
#endif

GLOBAL 	char NEAR TLOGSTR	  [] 
#if defined (_COMPDATA_C_)
= "LOG"
#endif
;

#ifndef RSW
GLOBAL 	    char NEAR TLOSCOPE [] 
#if defined (_COMPDATA_C_)
= "LOSCOPE"
#endif
;
#endif

GLOBAL 	char NEAR TLOWER	  [] 
#if defined (_COMPDATA_C_)
= "LOWER"
#endif
;

GLOBAL 	char NEAR TLTRIM	  [] 
#if defined (_COMPDATA_C_)
= "LTRIM"
#endif
;


#ifndef RSW
GLOBAL 	    char NEAR TLUPDATE [] 
#if defined (_COMPDATA_C_)
= "LUPDATE"
#endif
;
#endif

GLOBAL 	char NEAR TMAXSTR	  [] 
#if defined (_COMPDATA_C_)
= "MAX"
#endif
;

GLOBAL 	char NEAR TMINSTR	  [] 
#if defined (_COMPDATA_C_)
= "MIN"
#endif
;

GLOBAL 	char NEAR TMOD	  [] 
#if defined (_COMPDATA_C_)
= "MOD"
#endif
;

GLOBAL 	char NEAR TMONSBTW [] 
#if defined (_COMPDATA_C_)
= "MONSBTWN"
#endif
;

GLOBAL 	char NEAR TMONTH	  [] 
#if defined (_COMPDATA_C_)
= "MONTH"
#endif
;

#ifndef RSW
GLOBAL 	    char NEAR TNEXT	  [] 
#if defined (_COMPDATA_C_)
= "NEXT"		// should be on NEXTTEST
#endif
;

#endif

GLOBAL 	char NEAR TPAGENO  [] 
#if defined (_COMPDATA_C_)
= "PAGENO"
#endif
;

GLOBAL 	char NEAR TPREV	  [] 
#if defined (_COMPDATA_C_)
= "PREVIOUS"
#endif
;

GLOBAL 	char NEAR TQTR	  [] 
#if defined (_COMPDATA_C_)
= "QTR"
#endif
;


#ifndef RSW
GLOBAL 	    char NEAR TRECCNT  [] 
#if defined (_COMPDATA_C_)
= "RECCOUNT"
#endif
;
#endif

GLOBAL 	char NEAR TRECNO	  [] 
#if defined (_COMPDATA_C_)
= "RECNO"
#endif
;

GLOBAL 	char NEAR TREPLICA [] 
#if defined (_COMPDATA_C_)
= "REPLICATE"
#endif
;

GLOBAL 	char NEAR TRIGHT	  [] 
#if defined (_COMPDATA_C_)
= "RIGHT"
#endif
;


#ifdef RSW
GLOBAL 	    char NEAR TRIPARAM [] 
#if defined (_COMPDATA_C_)
= "RIPARAM"
#endif
;
#endif

#ifndef RSW
GLOBAL 	    char NEAR TRIPARAM [] 
#if defined (_COMPDATA_C_)
= "RIPARAM"
#endif
;
#endif

GLOBAL 	char NEAR TRND	  [] 
#if defined (_COMPDATA_C_)
= "ROUND"
#endif
;

GLOBAL 	char NEAR TRTRIM	  [] 
#if defined (_COMPDATA_C_)
= "RTRIM"
#endif
;


#ifdef RSW
GLOBAL 	    char NEAR TRR	  [] 
#if defined (_COMPDATA_C_)
= "RR"
#endif
;
#endif

GLOBAL 	char NEAR TRRUNIN  [] 
#if defined (_COMPDATA_C_)
= "RRUNIN"
#endif
;


#ifndef RSW
GLOBAL 	    char NEAR TSCAN	  [] 
#if defined (_COMPDATA_C_)
= "SCANNING"
#endif
;

#endif
GLOBAL 	char NEAR TSNDX	  [] 
#if defined (_COMPDATA_C_)
= "SOUNDEX"
#endif
;

GLOBAL 	char NEAR TSPACE	  [] 
#if defined (_COMPDATA_C_)
= "SPACE"
#endif
;

GLOBAL 	char NEAR TSPELLN  [] 
#if defined (_COMPDATA_C_)
= "SPELLNUM"
#endif
;

GLOBAL 	char NEAR TSQRT	  [] 
#if defined (_COMPDATA_C_)
= "SQRT"
#endif
;

GLOBAL 	char NEAR TSTR	  [] 
#if defined (_COMPDATA_C_)
= "STR"
#endif
;

GLOBAL 	char NEAR TSTUFF	  [] 
#if defined (_COMPDATA_C_)
= "STUFF"
#endif
;

GLOBAL 	char NEAR TSUBDAYS [] 
#if defined (_COMPDATA_C_)
= "SUBDAYS"
#endif
;

GLOBAL 	char NEAR TSUBMONS [] 
#if defined (_COMPDATA_C_)
= "SUBMONS"
#endif
;

GLOBAL 	char NEAR TSUBSTR  [] 
#if defined (_COMPDATA_C_)
= "SUBSTR"
#endif
;

GLOBAL 	char NEAR TSUBWKS  [] 
#if defined (_COMPDATA_C_)
= "SUBWKS"
#endif
;

GLOBAL 	char NEAR TSUBYRS  [] 
#if defined (_COMPDATA_C_)
= "SUBYRS"
#endif
;

GLOBAL 	char NEAR TTIME	  [] 
#if defined (_COMPDATA_C_)
= "TIME"
#endif
;

GLOBAL 	char NEAR TTRANSFORM [] 
#if defined (_COMPDATA_C_)
= "TRANSFORM"
#endif
;

GLOBAL 	char NEAR TFTRIM	  [] 
#if defined (_COMPDATA_C_)
= "TRIM"
#endif
;

GLOBAL 	char NEAR TUPPER	  [] 
#if defined (_COMPDATA_C_)
= "UPPER"
#endif
;

GLOBAL 	char NEAR TVAL	  [] 
#if defined (_COMPDATA_C_)
= "VAL"
#endif
;

GLOBAL 	char NEAR TWDCNT   [] 
#if defined (_COMPDATA_C_)
= "WDCOUNT"
#endif
;

/* Creating a dummy calculation that I'll flesh out later
   but using WDCOUNT as the basis 
   CAS - Liveware 04/12/2017  */
GLOBAL 	char NEAR TFLDVAL   [] 
#if defined (_COMPDATA_C_)
= "FIELDVAL"
#endif
;

GLOBAL 	char NEAR TWEEK	  [] 
#if defined (_COMPDATA_C_)
= "WEEK"
#endif
;

GLOBAL 	char NEAR TWKSBTWN [] 
#if defined (_COMPDATA_C_)
= "WKSBTWN"
#endif
;

GLOBAL 	char NEAR TWORD 	  [] 
#if defined (_COMPDATA_C_)
= "WORD"
#endif
;

GLOBAL 	char NEAR TYEAR	  [] 
#if defined (_COMPDATA_C_)
= "YEAR"
#endif
;

GLOBAL 	char NEAR TYRSBTWN [] 
#if defined (_COMPDATA_C_)
= "YRSBTWN"
#endif
;


GLOBAL 	char NEAR TCOPY	  [] 
#if defined (_COMPDATA_C_)
= "COPY"
#endif
;

GLOBAL 	char NEAR TQUERY	  [] 
#if defined (_COMPDATA_C_)
= "QUERY"
#endif
;

GLOBAL 	char NEAR TSTRSEARCH [] 
#if defined (_COMPDATA_C_)
= "STRSEARCH"
#endif
;

GLOBAL 	char NEAR TSTRCOUNT [] 
#if defined (_COMPDATA_C_)
= "STRCOUNT"
#endif
;

GLOBAL 	char NEAR TSTRREP  [] 
#if defined (_COMPDATA_C_)
= "STRREP"
#endif
;

GLOBAL 	char NEAR TCLOOKUP  [] 
#if defined (_COMPDATA_C_)
= "CLOOKUP"
#endif
;

GLOBAL 	char NEAR TDLOOKUP  [] 
#if defined (_COMPDATA_C_)
= "DLOOKUP"
#endif
;

GLOBAL 	char NEAR TLLOOKUP  [] 
#if defined (_COMPDATA_C_)
= "LLOOKUP"
#endif
;

GLOBAL 	char NEAR TNLOOKUP  [] 
#if defined (_COMPDATA_C_)
= "NLOOKUP"
#endif
;

GLOBAL 	char NEAR TLIBN	[] 
#if defined (_COMPDATA_C_)
= "LIBNAME"
#endif
;

GLOBAL 	char NEAR TREPN  [] 
#if defined (_COMPDATA_C_)
= "REPNAME"
#endif
;

GLOBAL 	char NEAR TUDFN  [] 
#if defined (_COMPDATA_C_)
= "UDFNAME"
#endif
;

GLOBAL 	char NEAR THALF  [] 
#if defined (_COMPDATA_C_)
= "HALF"
#endif
;

GLOBAL 	char NEAR TMONL  [] 
#if defined (_COMPDATA_C_)
= "MONLEN"
#endif
;

GLOBAL 	char NEAR TAGED  [] 
#if defined (_COMPDATA_C_)
= "AGED"
#endif
;

GLOBAL 	char NEAR TPAST  [] 
#if defined (_COMPDATA_C_)
= "PAST"
#endif
;

GLOBAL 	char NEAR TFUTU  [] 
#if defined (_COMPDATA_C_)
= "FUTURE"
#endif
;

GLOBAL 	char NEAR TOVER  [] 
#if defined (_COMPDATA_C_)
= "OVER"
#endif
;

GLOBAL 	char NEAR TNDOW  [] 
#if defined (_COMPDATA_C_)
= "NDOW"
#endif
;

GLOBAL 	char NEAR TPDOW  [] 
#if defined (_COMPDATA_C_)
= "PDOW"
#endif
;

GLOBAL 	char NEAR TDTADD  [] 
#if defined (_COMPDATA_C_)
= "DTEADD"
#endif
;

GLOBAL 	char NEAR TDTDIF  [] 
#if defined (_COMPDATA_C_)
= "DTEDIFF"
#endif
;

GLOBAL 	char NEAR TDTPRT  [] 
#if defined (_COMPDATA_C_)
= "DTEPART"
#endif
;

GLOBAL 	char NEAR TTODATE [] 
#if defined (_COMPDATA_C_)
= "TODATE"
#endif
;

GLOBAL 	char NEAR TTOTIME [] 
#if defined (_COMPDATA_C_)
= "TOTIME"
#endif
;

GLOBAL 	char NEAR TDTTOC [] 
#if defined (_COMPDATA_C_)
= "DTTOC"
#endif
;

GLOBAL 	char NEAR TTTOC [] 
#if defined (_COMPDATA_C_)
= "TTOC"
#endif
;

GLOBAL 	char NEAR TDTLOOKUP [] 
#if defined (_COMPDATA_C_)
= "DTLOOKUP"
#endif
;

GLOBAL 	char NEAR TTTOS [] 
#if defined (_COMPDATA_C_)
= "TTOS"
#endif
;

GLOBAL 	char NEAR TCTDT [] 
#if defined (_COMPDATA_C_)
= "CTDT"
#endif
;

GLOBAL 	char NEAR TCTOS [] 
#if defined (_COMPDATA_C_)
= "CTOS"
#endif
;

GLOBAL 	char NEAR TCTOT [] 
#if defined (_COMPDATA_C_)
= "CTOT"
#endif
;

GLOBAL 	char NEAR TSTOC [] 
#if defined (_COMPDATA_C_)
= "STOC"
#endif
;

GLOBAL 	char TPERCOMP []			////WRR 7/1/98 WO157195
#if defined (_COMPDATA_C_)
= "PERCOMP"
#endif
;

GLOBAL 	char NEAR TNOW [] 
#if defined (_COMPDATA_C_)
= "NOW"
#endif
;

GLOBAL 	char NEAR TLASTPAGE [] 
#if defined (_COMPDATA_C_)
= "LASTPAGE"
#endif
;
GLOBAL 	char NEAR TREPORTPAGE [] 
#if defined (_COMPDATA_C_)
= "REPORTPAGE"
#endif
;
//
// These are the Paradox-style logical operators and constants
//
/*
GLOBAL 	char TPTRUE	[] 
#if defined (_COMPDATA_C_)
= "TRUE"
#endif
;

GLOBAL 	char TPYES	[] 
#if defined (_COMPDATA_C_)
= "YES"
#endif
;

GLOBAL 	char TPON	[] 
#if defined (_COMPDATA_C_)
= "ON"
#endif
;

GLOBAL 	char TPFALSE [] 
#if defined (_COMPDATA_C_)
= "FALSE"
#endif
;

GLOBAL 	char TPNO	[] 
#if defined (_COMPDATA_C_)
= "NO"
#endif
;

GLOBAL 	char TPOFF	[] 
#if defined (_COMPDATA_C_)
= "OFF"
#endif
;

GLOBAL 	char TPAND	[] 
#if defined (_COMPDATA_C_)
= "AND"
#endif
;

GLOBAL 	char TPOR	[] 
#if defined (_COMPDATA_C_)
= "OR"
#endif
;

GLOBAL 	char TPNOT	[] 
#if defined (_COMPDATA_C_)
= "NOT"
#endif
;
*/
#ifdef RSW
GLOBAL 	    char NEAR TIXSQL	[] 
 #if defined (_COMPDATA_C_)
= "SQLEXP"
 #endif
;
#endif

#if defined (INTERACTIVE)
#define DORIPARAM 0		// used in riparam()
#else
#define DORIPARAM 1		// used in riparam()
#endif



//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#undef GLOBAL
#endif // end __CFMISC_H_

// *************************** End of File *********************************
