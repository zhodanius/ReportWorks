// ****************************************************************************
//
//      (C) Copyright 1992-1993 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $Workfile:   cfmisc.h  $
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
// $Log:   D:/R&R Project/archives/H/CFMISC.H_V  $
//
// Rev 1.16    08 Mar 2017 10:01:25   CAS
// Test adding a FieldValue() function which returns the value of the
// field in the argument (which can be a calculated field)
// so, if a field P_LNAME contains the value "STRASSER" then 
// FieldVal("P_L" + "NAME") returns "STRASSER"
// 
//    Rev 1.15   Jul 01 2002 15:20:10   Admin
// Add a flag for system udf
// 
//    Rev 1.14   Jun 05 2002 11:50:42   Admin
// Add new error code
// 
//    Rev 1.13   Jan 19 2001 14:05:56   nhubacker
// Functions for lastpage(0) and reportpage()
// 
//    Rev 1.12   Dec 12 2000 15:52:56   nhubacker
// Add HGRPAGE entry
// 
//    Rev 1.11   Dec 05 2000 11:54:32   nhubacker
// Add memeber to struct functb for index expressions
// 
//    Rev 1.10   Aug 30 1999 15:43:24   BUILD
// ARP20001
// 
//    Rev 1.9   30 Nov 1998 13:31:30   wrr
// WO134154 added
// 
//    Rev 1.8.2.0   15 Jul 1998 11:36:14   wrr
// Code ported from 16bit to 32bit
// Jim added the percomp()
// WO157195
// 
//    Rev 1.18.1.0   18 May 1998 18:20:58   jpb     // WRR 7/1/98 Merge WO157195
// Add percomp function								
// 
//    Rev 1.18.1.0   18 May 1998 17:44:48   jpb
// Add percomp function
// 
//    Rev 1.8   17 Nov 1995 11:42:02   jpb
// runtime build cleanup
// 
//    Rev 1.7   22 Sep 1995 17:09:56   sjo
// First round of FLDID changes.
// 
//    Rev 1.6   18 Aug 1995 14:51:30   mjs
// Moved strings to global.h
// 
//    Rev 1.5   17 Aug 1995 12:49:10   sbc
// Restore functab extern
// 
//    Rev 1.4   20 Jul 1995 16:39:14   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.3   27 Apr 1995 12:37:02   sjo
// Merge of 6.1.03+.  I say + because I have added some of the time functions
// to this merge, which will be a part of 6.1.04.  I merged the CF directories
// and some H files (for the time function changes).
// 
//    Rev 1.2   26 Apr 1995 11:18:10   pjm
// Fixed merge error.
// 
//    Rev 1.1   26 Apr 1995 10:38:44   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.0   16 Mar 1995 16:15:38   sbc
// Initial revision.
// 
//    Rev 1.17   03 Apr 1995 15:45:14   pjm
// Added help code and bumped MAX_FUNC to 0x80.
// 
//    Rev 1.16   28 Mar 1995 17:52:10   jpb
// support datetime/time literals
// 
//    Rev 1.15   27 Mar 1995 19:31:08   sjo
// Added support for new DT functions.
// 
//    Rev 1.14   23 Mar 1995 17:09:26   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
// 
//    Rev 1.13   08 Feb 1995 13:38:48   sjo
// Checking in a bunch of files for the first wave of datetime support. These
// sources have support for a dFlags that is a long (not an unsigned int) and
// it recognizes date, time and datetime fields.  It only supports dates at
// this time, because we need calcs, picture types, etc if we are to do time and
// datetime.
// 
// 
// 
//    Rev 1.12   06 Feb 1995 09:27:40   sbc
// Add context help ID to FUNCTB structure.
// 
//    Rev 1.11   18 Jan 1995 17:50:54   sjo
// Made changes to remove compiler warnings.
// 
//    Rev 1.10   15 Sep 1994 13:27:26   vff
// Added function help text
// 
//    Rev 1.9   20 Jul 1994 17:31:48   vff
// Added ISNULL() for Runtime DLL/VBX
// 
//    Rev 1.7   16 Jun 1994 10:48:36   vff
// Merged RR6 functions into R?W 6.0
// 
//    Rev 1.6   08 Jun 1994 12:33:42   erp
// changed __near to near, so it will built for 32-bits
// 
//    Rev 1.4   29 Apr 1994 12:10:46   say
// change runtime.h to util.h after NV struct was moved
// 
//    Rev 1.3   10 Mar 1994 14:46:12   nwh
// (dlm) Added or fixed a few externs.  Mostly some minor reformatting.
// 
//    Rev 1.2   13 Jan 1994 10:03:04   jpb
// Minimize SELECT field list - changed modules: cfmisc.h, mferror.h,
//  cfneeded.c, mfcheck.c, mfrdmore.c, rpsort.c, sxselect.c, wprint.c
// 
//    Rev 1.1   19 Nov 1993 17:45:26   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:12:08   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _CFMISC_H_

//
// Make a definition for this module.
//
#define _CFMISC_H_

#if !defined(INTERACTIVE)
#include "UTIL.H"				// For NV struct
#endif
#include "RESOURCE.H"
#include "MFFIELD.H"

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
// error codes for uferror() messages
#define uerr_invalid	1	// invalid udf file
#define uerr_old		2	// udfs out of date
#define uerr_read		3	// IRP error reading udfs
#define uerr_create		4	// IRP error creating udf lib
#define uerr_open		5	// IRP error opening udf lib
#define uerr_write		6	// IRP error writing udf 
#define uerr_delete		7	// IRP error deleting udf 
#define uerr_access		8	// uopen EACCESS error (sharing violation)
#define uerr_nofile		9	// file does not exist

#define H_CONV1 -1
#define H_CONV2 -1
#define H_CONV3 -1
#define HLKUP -1

#define HABS		IDF_00
#define HADDDAYS	IDF_01
#define HADDMONS	IDF_02
#define HADDWKS		IDF_03
#define HADDYRS		IDF_04
#define HASC		IDF_05
#define HAT			IDF_06
#define HBLNKNUM	IDF_07
#define HCAPS		IDF_08
#define HCASE		IDF_09
#define HCDOW		IDF_10
#define HCHR		IDF_11
#define HCLOOKUP	IDF_12
#define HCMONTH		IDF_13
#define HCOPY		IDF_14
#define HCTOD		IDF_15
#define HDATE		IDF_16
#define HDAY		IDF_17
#define HDAYSBTWN	IDF_18
#define HDBF		IDF_19
#define HDELETED	IDF_20
#define HDLOOKUP	IDF_21
#define HDOW		IDF_22
#define HDQTR		IDF_23
#define HDTOC		IDF_24
#define HERROR		IDF_25
#define HEXP		IDF_26
#define HFLIP		IDF_27
#define HHISCOPE	IDF_28
#define HIIF		IDF_29
#define HINLST		IDF_30
#define HINRNG		IDF_31
#define HINT		IDF_32
#define HISALPHA	IDF_33
#define HISBLANK	IDF_34
#define HISLOWER	IDF_35
#define HISUPPER	IDF_36
#define HLEFT		IDF_37
#define HLEN		IDF_38
#define HLLOOKUP	IDF_39
#define HLOG		IDF_40
#define HLOSCOPE	IDF_41
#define HLOWER		IDF_42
#define HLTRIM		IDF_43
#define HLUPDATE	IDF_44
#define HMAX		IDF_45
#define HMIN		IDF_46
#define HMOD		IDF_47
#define HMONSBTWN	IDF_48
#define HMONTH		IDF_49
#define HNLOOKUP	IDF_50
#define HPAGENO		IDF_51
#define HPREV		IDF_52
#define HQTR		IDF_53
#define HQUERY		IDF_54
#define HRECCNT		IDF_55
#define HRECNO		IDF_56
#define HREPLICATE	IDF_57
#define HRIGHT		IDF_58
#define HRIPARAM	IDF_59
#define HRND		IDF_60
#define HRRUNIN		IDF_61
#define HRTRIM		IDF_62
#define HSCAN		IDF_63
#define HSNDX		IDF_64
#define HSPACE		IDF_65
#define HSPELLN		IDF_66
#define HSQRT		IDF_67
#define HSTR		IDF_68
#define HSTRCOUNT	IDF_69
#define HSTRREP		IDF_70
#define HSTRSEARCH	IDF_71
#define HSTUFF		IDF_72
#define HSUBDAYS	IDF_73
#define HSUBMONS	IDF_74
#define HSUBSTR		IDF_75
#define HSUBWKS		IDF_76
#define HSUBYRS		IDF_77
#define HTIME		IDF_78
#define HTRANSFORM	IDF_79
#define HTRIM		IDF_80
#define HUPPER		IDF_81
#define HVAL		IDF_82
#define HWDCNT		IDF_83
#define HWEEK		IDF_84
#define HWKSBTWN	IDF_85
#define HWORD		IDF_86
#define HYEAR		IDF_87
#define HYRSBTWN	IDF_88
#define HSQLEXP   IDS_S1079
#define HREPN		IDF_89
#define HLIBN		IDF_90
#define HLIKE		IDF_91
#define HRR			IDF_92
#define HCDLL		IDF_93
#define HUDFN		IDF_94
#define HAGED		IDF_95
#define HHALF		IDF_96
#define HISNULL	IDF_97
#define HMONL     IDF_98
#define HPAST     IDF_99
#define HFUTU     IDF_100
#define HOVER     IDF_101
#define HNDOW     IDF_102
#define HPDOW     IDF_103
#define HDTADD   	IDF_104
#define HDTDIF    IDF_105
#define HDTPRT    IDF_106
#define HTODATE   IDF_107
#define HTOTIME   IDF_108
#define HDTTOC   	IDF_109
#define HTTOC     IDF_110
#define HDTLOOKUP IDF_111
#define HTTOS		IDF_112
#define HCTDT     IDF_113
#define HCTOS     IDF_114
#define HCTOT     IDF_115
#define HSTOC     IDF_116
#define HPERCOMP  IDF_117
#define HNOW	  IDF_118
#define HLASTPAGE	  IDF_119
#define HREPORTPAGE	  IDF_120
//  New function being added to test the process by CAS 3/8/2017
//  noticed that all of them have the actual function name after
//  the 'H'
//  See Rev 1.16 above
#define HFLDVAL	IDF_121

#define MAX_FUNC  0x8B	/* This must be incremented with the addition of 
									each function (was 0x89 before Rev 1.16)
							To test FieldVal(), it was incremented from 8A */

/* return codes for parseDateTime: */
#define PDT_ERROR		-1
#define PDT_DATEONLY	1
#define PDT_DATETIME	2
#define PDT_TIMEONLY	3

#define _CFFIELD	1
#define _CFFILE		0
#define _CFFLDSFILE	-1

//
// Structure Section:
// Place in this section any structure definitions.
//
typedef struct udf
{
	struct	udf far *uNext;	// pointer to next udf in chain
	int		uFuncNo;		// user function number
	unsigned long uFlags;	// user function result type flags
	char	uType;			// result type
	int		uArgCnt;		// number of arguments
	int		uHelp;			// help code
	bool	uSystem;		// true if a system udf
	char	*uName;			// pointer to udf name
	char	*uDecl;			// pointer to udf declaration
	char	*uArgList;		// pointer to argument specifier list
	char	*uExpD;			// pointer to displayable definition
	char	*uExpE;			// pointer to evaluatable definition
	int		uExpELen;		// length of evaluatable definition
} UDF;

typedef UDF far * LPUDF;

typedef struct functb
{
	char	*fName;			// name of function
	int		fMiniHelp;		// help code for help string under function listbox
	int		nContextHelp;	// context-sensitive help code
	char	fType;			// type of value returned
	char	*fArgs;			// pointer to args string (see NOTE below)
	int		(*function)(void); // pointer to the function routine
	void	(*pfunc)(void); // pointer to the picture routine
	bool	index;			// true if allowed in an index expression
} FUNCTB;

extern FUNCTB near functab[];	// this is still static in FUNCTAB.CPP

//
// Global Data Section:
// Place in this section any global data.
//

//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#undef GLOBAL
#endif // end _CFMISC_H_

// *************************** End of File ************************************
