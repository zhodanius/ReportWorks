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
// $Log:   H:/vcsmfc/h/runtime.h_v  $
// 
//    Rev 1.8   05 May 1997 15:13:18   par
// Removed A L I V E (spacing prevents search hits) and PDI _ EXPORT conditionals.
// From this point forward, this code will always be included in build.
// 
// 
//    Rev 1.7   10 Feb 1997 10:02:28   sp
// Arp Live merge to trunk
// 
//    Rev 1.5.1.1   29 Oct 1996 14:18:24   smh
// Fix PDI _ EXPORT conditionals
// 
//    Rev 1.4.1.2   02 Aug 1996 09:23:24   sjo
// Fixed a compile problem.
// 
//    Rev 1.4.1.1   02 Aug 1996 08:30:38   sjo
// Added live Html as a valid Export Option.
// 
//    Rev 1.4.1.0   01 Aug 1996 19:30:02   sjo
// Added support for HTML.
// 
//    Rev 1.4   04 Dec 1995 15:27:40   jpb
// runtime
// 
//    Rev 1.3   17 Nov 1995 15:58:42   jpb
// move vars/funcs to CRrRuntime class
// 
//    Rev 1.2   29 Jun 1995 10:45:04   smh
// Merged R?W 6.5.03 sources w/ R?W7 sources.
// 
//    Rev 1.1   25 Apr 1995 15:11:18   smh
// Merged 6.1.03 and 7.0 headers.
// 
//    Rev 1.0   16 Mar 1995 16:13:26   sbc
// Initial revision.
// 
//    Rev 1.22   12 Jun 1995 16:07:34   sjo
// Added CSV support to runtime.
// 
//    Rev 1.21   30 May 1995 13:54:12   pjm
// Defined RTRTF for RTF export.
// 
//    Rev 1.20   20 Mar 1995 11:09:40   smh
// proto checkAliases
// 
//    Rev 1.19   28 Oct 1994 14:49:48   smh
// Moved large global runtime parameter arrays to RpParam structure
// 
//    Rev 1.18   17 Oct 1994 16:09:22   jpb
// add RpDB GLOBAL
// 
//    Rev 1.17   09 Sep 1994 15:43:40   dlm
// Removed CfgName GLOBAL.  Removed references to it in wrtmain.c, winit.c,
//  rrwini.c.
// 
//    Rev 1.16   06 Sep 1994 15:25:14   pjm
// Added GLOBAL int HArg for /H switch.
// 
//    Rev 1.15   01 Sep 1994 10:48:16   smh
// RI_RepPick: Added RpRepPick.
// 
//    Rev 1.14   02 Aug 1994 17:21:44   dlm
// Added conditional so that RSWRUN looks for rsreport.dll, not rreport.dll!
// 
//    Rev 1.13   05 Jul 1994 13:43:42   dlm
// Added GLOBAL for WxRuntimeDLL.
// 
//    Rev 1.12   20 May 1994 13:58:20   sbc
// New sort/group boolean
// 
//    Rev 1.11   19 May 1994 14:59:02   sbc
// Fix sort/group arrays (int -> char)
// 
//    Rev 1.10   18 May 1994 16:02:24   sbc
// New RI_ fields for VBX
// 
//    Rev 1.9   13 Apr 1994 15:01:22   say
// remove NV typedef; moved it to util.h
// 
//    Rev 1.8   04 Mar 1994 18:06:24   say
// Add a couple of global text strings, moved from global.h
// 
//    Rev 1.7   25 Feb 1994 15:48:04   say
// fix #else
// 
//    Rev 1.6   25 Feb 1994 15:08:16   smh
// Changes for ODBC in runtime:  rpprep.c, wrtmain.c, wnextjob.c, 
// sconnect.c, mfsql.c, runtime.h,_runtime.h, sglobal.h
// 
//    Rev 1.5   25 Feb 1994 14:45:44   say
// Add bReadingRuninDBF
// 
//    Rev 1.4   29 Dec 1993 13:34:40   smh
// Database export:  See Scott for complete list of files.
// 
//    Rev 1.3   04 Dec 1993 10:37:28   say
// #include sql.h, add RpDataSource string
// 
//    Rev 1.2   19 Nov 1993 17:43:00   sbc
// Add extern C for C++
// 
//    Rev 1.1   02 Nov 1993 10:03:44   say
// Move RpAliases[] and RPALIAS from repio.h
// 
//    Rev 1.0   14 Oct 1993 10:11:22   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _RUNTIME_H_
//
// Make a definition for this module.
//
#define _RUNTIME_H_

//
// Includes needed by this header.
//
#include "wmain.h"
/* don't include libio.h - you'll create a circular include loop and
	won't be able to figure out why things aren't being included. - Scott
*/
#include "index.h"		// for MAXKEYSZ
#include "wfield.h"		// for LPFLDHDR

#if defined(RSW)
#include "sql.h" // ODBC header for SQL_MAX_DSN_LENGTH
#endif

// VBX control defines
#define WBORDER_NONE	0	// window w/ no border
#define WBORDER_SINGLE	1	// fixed size/single line border (WS_BORDER)
#define WBORDER_SIZABLE	2	// can be resized (WS_THICKFRAME)
#define WBORDER_DOUBLE	3	// fixed size/double line border (WS_DLGFRAME)

// ********************************************************************
//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
	// special RpPrnNo values from the old runtime.h
#define RTNOCODES	(-1)	// output ascii - no printer codes
#define RTCON		(-2)	// output to console
#define RTDBF		(-3)	// override to dbf export
#define RTWKS		(-4)	// override to wks export
#define RTEXPASK	(-5)	// put up export dialog in runtime please
#define RTRTF		(-6)	// override to rtf export
#define RTWORD		(-7)	// override to word merge file export
#define RTCSV		(-8)	// override to csv file export
#define RTHTML		(-9)	// override to html file export
#define RTLIVEHTML	(-10)	// Live HTML
#define RTPDI		(-11)	// Report Viewer Control (PDI) export

#define MAXPARAMLENGTH  1024		// max length of parameter substitution string
#define EXPDSTSZ 8
#define EXPADDSZ 32



// ********************************************************************
//
// Structure Section:
// Place in this section any structure definitions.
//

typedef struct rpalias
{	char far * alias;		/* file alias */
	char far * filepath;		/* related file pathname */
#ifndef RSW
	char far *indexpath;	/* index file pathname */
	char far *tag;			/*  & tag */
#endif
} RPALIAS;

/* This is a structure of runtime parameters.  It is allocated and freed
	in winit.c with Paths.  All runtime parameters belong in this structure,
	but I moved only the large arrays to it to minimize risk to the product
	at this late date.
*/
typedef struct rpparams
{
	RPALIAS RpAliases[MFMAXFILES-1];	// RI_ALIASn overrides
	char RpMemo[PATHLENGTH+1];			// memo file pathname
	char RpWPort[PPORTSZ];				// Windows Port
	char RpWPtr[PTYPESZ];				// Windows Printer
	char RpWTitle[PTITLESZ];			// Windows Title
	char RpROFile[PATHLENGTH];			// rrunout file
	char CtlName[PATHLENGTH];			// runtime control table
#if defined(RSW)
	char RpDataSource[SQL_MAX_DSN_LENGTH+1];
	char RpReplace[MAXPARAMLENGTH];	// for SELECT-based parameter substitution
	char jfname[WINPATHLEN+1];			// temporary job file
#else
	char RpMIndex[PATHLENGTH+1];		// master index name override
	char RpLoScope[MAXKEYSZ+1];
	char RpHiScope[MAXKEYSZ+1];
#endif
}	RPPARAMS;

#endif // end _RUNTIME_H_

// *************************** End of File ************************************
