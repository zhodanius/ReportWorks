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
// Implements LoadLibrary, but checks the version number in the DLL to make sure
// it matches the R&R version number.
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// Log:   H:/vcsmfc/h/version.h_v  
// 
// sp 2/25/97 removed logging from this file by removing the "$" from the begining and end
// of the  line above.  Logging with this file is unnessisary because the changes are usually
// just updating the version number.
// Removed log info for version number changes
// ANY LOG INFO WANTED NOW MUST BE ENTERED BY HAND
//
//    Rev 1.24   19 Feb 1997 15:49:12   dlm
// Part of fix to RRW 2979.  Added "conversation version" check to runtime
//  DLL and EXE to replace build number check.  Build number doesn't matter.
//  What matters is whether the mechanism used to pass info between DLL and
//  EXE has changed.
// 
//    Rev 1.22   10 Feb 1997 10:02:28   sp
// Arp Live merge to trunk
// 
//    Rev 1.19.1.15   31 Dec 1996 12:20:30   SRM
// add getAPIVersion()
// 
//    Rev 1.19.1.0   15 Oct 1996 16:24:54   smh
// Took versioning changes from trunk.
// 
//    Rev 1.16.1.8   09 Oct 1996 17:17:32   jpb
// switch to new buildno version number scheme
// 
//    Rev 1.18   30 Sep 1996 17:41:24   jpb
// synch with U02
// 
//    Rev 1.17   17 Jun 1996 08:55:52   smh
// Internal release 7/1.0.14, & U02 change.
// 
//    Rev 1.16   09 May 1996 15:55:18   smh
// Fixed VERSION_NUMBER so it will "attribute" into U01.
// 
// If RSW, use 1.0 in About and File Properties.  DLL checking is still 7.0.06.
// 
//    Rev 1.2   27 Jul 1995 09:35:30   sbc
// Make char string near
// 
//    Rev 1.1   26 Jul 1995 10:22:46   pjm
// Moved LoadAndCheckLibrary to rr.h.
// 
//    Rev 1.0   16 Mar 1995 16:13:50   sbc
// Initial revision.
// 
//    Rev 1.0   23 Mar 1994 15:00:16   erp
// Initial revision.
// ****************************************************************************
//

#ifndef _VERSION_H_
#define _VERSION_H_

//#define VERSION_NUMBER_BINARY 1011,0,0
//#define VERSION_NUMBER_STRING "1011.0.0\0"

// lets us have different version numbers for RSW and RRW
#if defined (RSW)
   #define VERSION_NUMBER_BINARY	12,6,165
   #define VERSION_NUMBER_STRING	"12.6.165\0"
#else
   #define VERSION_NUMBER_BINARY	12,6,165
   #define VERSION_NUMBER_STRING	"12.6.165\0"
#endif

// this temporary to avoid having to edit all .RV files
#define VERSION_NUMBER                  VERSION_NUMBER_BINARY
#define RESOURCE_VERSION_NUMBER         VERSION_NUMBER_STRING
// Remember the Alamo!

// API versions for dlls - One of these should change only when a new function is
//  added to its API.  Old functions should never be removed from any of these APIs
//  so that old versions of the EXE will still work with newer versions of the DLLs.
#define CSV_API_VERSION		1
#define DBF_API_VERSION		1
#define HTML_API_VERSION	2
#define RTF_API_VERSION		1
#define WKS_API_VERSION		1
#define PV_API_VERSION		1		// print/preview
#define TXT_API_VERSION		1		// text export
#define PDI_API_VERSION		1

#define RRPRVIEW_VERSION	"2,0,0,5"

// The following version number relates to the NATURE of the conversation between
//  the runtime DLL and the runtime EXE.  It should only be changed when something
//  fundamental about this conversation changes.  Just adding a new command line
//  switch to the runtime EXE or adding a new name/value pair to the conversation
//  does NOT require a change to this number!!  However, using "events" that are named
//  differently is an example of a fundamental change to the conversation.
// Also, note that the mechanism for beginning the conversation (i.e., passing the
//  conversation version number to the EXE) should only change for extremely good
//  reasons, since otherwise the conversation will fail - even to the extent of
//  both sides not necessarily realizing it has failed!
#define DLL_EXE_CONVERSATION_VERSION 1

#if defined _VERSION_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

#undef GLOBAL

#endif

