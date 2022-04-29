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
// $Log:   D:/R&R Project/archives/H/_RUNTIME.H_V  $
// 
//    Rev 1.10   May 13 2003 14:14:54   Admin
// Version 10.1
// 
//    Rev 1.9   25 Feb 1997 17:40:32   amh
// Added code for Send To Fax
// 
//    Rev 1.8   19 Nov 1996 11:06:36   amh
// Added new code for right-click send to printer
// 
//    Rev 1.7   22 Feb 1996 12:40:50   sjo
// Fixes problem with RSW /TS files.
// 
//    Rev 1.6   16 Feb 1996 16:21:14   sjo
// Changes made to accept R?W files on the command line as well as .TXT files, 
// .RRS and RSS files from the shortcut maker.
// 
//    Rev 1.5   04 Dec 1995 15:27:42   jpb
// runtime
// 
//    Rev 1.4   30 Nov 1995 17:53:36   sjo
// Changes required for the runtime port to 32 bit MFC.
// 
//    Rev 1.3   29 Nov 1995 11:46:26   jpb
// get rid of dbheader dupes
// 
//    Rev 1.2   17 Nov 1995 15:58:44   jpb
// move vars/funcs to CRrRuntime class
// 
//    Rev 1.1   25 Apr 1995 15:11:22   smh
// Merged 6.1.03 and 7.0 headers.
// 
//    Rev 1.0   16 Mar 1995 16:14:54   sbc
// Initial revision.
// 
//    Rev 1.12   15 Feb 1995 15:52:22   smh
// Added max ri_alias value define.
// 
//    Rev 1.11   28 Oct 1994 14:49:54   smh
// Moved large global runtime parameter arrays to RpParam structure
// 
//    Rev 1.10   06 Sep 1994 13:45:20   smh
// Added RI_DB.
// 
//    Rev 1.9   01 Sep 1994 12:30:54   smh
// RI_REPPICK: Added JF_REPPICK & WxRepPick.
// 
//    Rev 1.8   19 May 1994 14:59:30   sbc
// Fix RI_WWIDTH (case)
// 
//    Rev 1.7   18 May 1994 16:02:42   sbc
// New RI_ fields for VBX
// 
//    Rev 1.6   09 May 1994 09:13:56   sbc
// Unleash ASCII runin/runout for RRW
// 
//    Rev 1.5   29 Apr 1994 12:12:44   say
// Add util.h after moving NV struct
// 
//    Rev 1.4   04 Mar 1994 18:05:22   say
// add JF_EXPDST, move text string globals from global.h
// 
//    Rev 1.3   04 Mar 1994 11:32:44   erp
// made RINONE available for RRW RUNTIME build
// 
//    Rev 1.2   25 Feb 1994 15:06:40   smh
// Changes for ODBC in runtime:  rpprep.c, wrtmain.c, wnextjob.c, 
// sconnect.c, mfsql.c, runtime.h,_runtime.h, sglobal.h
// 
//    Rev 1.1   19 Nov 1993 17:40:04   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:11:34   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __RUNTIME_H_

//
// Make a definition for this module.
//
#define __RUNTIME_H_

#include "util.h"			// for NV structure
#include "runtime.h"

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

// max for an ri_alias value =
// 		RSW: alias + new alias path + indexpath + 10 for equals, commas, whitespace
//			RRW: above + indexpath + tag
#if defined (RSW)
#define ALIASSTRMAX MAXALIAS + WINPATHLEN + 10
#else
#define ALIASSTRMAX MAXALIAS + WINPATHLEN + WINPATHLEN + MAXTAG + 10
#endif

	// from old runtime.h
// Since Windows zacks return false rather than exiting, use different
// returns from wnextjob.c.
#define NJOK		1			// OK to proceed
#define NJERR		0			// zack returned false
#define NJEOF		-1			// end of file
#define NJDEL		-2			// deleted record number

#define	RINONE		0			// RIType constants

#define	RIASCII		1			// ascii runin
#define	RICONTROL	2			// @ file 
#define	RIREPORT	4			// report name passed on command line or nothing.
#define RINOTHING	5			// Nothing passed on the command line.

#define RIPRINT		66
#define RIFAX		67			// Send to Fax
#define RIMAPI		68			// Export MAPI

#define	JOBBLOCK	10			// allocate job # space in blocks of 10
#ifdef RSW
#define	RIDBTABLE	3			// some database platform runin

// parameters for SQL runtime jobfile contents
#define JF_START	0x01
#define JF_END		0x02
#define JF_ID		0x03
#define JF_MASTER	0x04
#define JF_LIBRARY	0x05
#define JF_REPORT	0x06
#define JF_OUTFILE	0x07
#define JF_CHKTIME	0x08
#define JF_PRINTER	0x09
#define JF_QUERY	0x0A
#define JF_FILTER	0x0B
#define JF_WHERE	0x0C
#define JF_DATABASE	0x0D
#define JF_MEMO		0x0E
#define JF_OUTAPPN	0x0F
#define JF_NOESC	0x10
#define JF_TEST		0x11
#define JF_DISPERR	0x12
#define JF_BEGPAGE	0x13
#define JF_ENDPAGE	0x14
#define JF_COPIES	0x15
#define JF_UNAME	0x16
#define JF_UVALUE	0x17
#define JF_DICT		0x18
#define JF_DATA		0x19
#define JF_VIEW		0x1A
#define JF_FONTLIB	0x1B
#define JF_STATUS	0x1C
#define JF_WPTR		0x1D
#define JF_WPORT	0x1E
#define JF_WTITLE	0x1F
#define JF_ALIAS	0x20
#define JF_REPLACE	0x21
#define JF_DATASOURCE 0x22
#define JF_EXPDST 	0x23
/// VBX support ///
#define JF_WBORDER	0x24
#define JF_WCONTROL	0x25
#define	JF_WHEIGHT	0x26
#define	JF_WLEFT	0x27
#define JF_WMAX		0x28
#define JF_WMIN		0x29
#define JF_WPARENT	0x2A
#define JF_WTOP		0x2B
#define JF_WWIDTH	0x2C
#define JF_SORT		0x2D
#define JF_GROUP	0x2E
///////////////////
#define JF_REPPICK	0x2F

#else // !RSW

	// from dbheader.h
#define SUCCESS   0			// successful function return code
#define d_ERROR   1			// general error code

#define BEGINDATA ((dbfptr)->_begdata)
#define DBF1		0x03	// .DBF file type 1
#define DECPLACE	0x11	// decimal point offset: added to field offset
#define EOFIELD  	0x0d	// end of field marker in data file
#define FILETYPE	0		// file type
#define FREC0 		8		// address of first record
#define FSTFIELD 	0x20	// first field offset
#define FZ12     	0x12	// field zero byte BEGIN
#define FZ1F     	0x1f	// field zero byte END
#define NXTFIELD 	0x20	// add NXTFIELD to get next field offset
#define RLEN0 		0x0a	// record length < 1st byte >
#define RNUM0 		4		// number of records allocated < 1st byte >
#define TYPE  		0xb		// type offset ('C', 'N', 'L', 'M' or 'D'):
#define WIDTH    	0x10	// width offset: added to field offset
#define YEAR  		1		// year

#endif // !RSW

//////////////////////////////////////////////////////////////////////////////////////
#endif // end __RUNTIME_H_

// *************************** End of File ************************************
