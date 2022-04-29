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
// $Log:   H:/VCSMFC/H/WBAND.H_V  $
// 
//    Rev 1.2   18 Aug 1995 14:52:48   mjs
// Moved string to global.h
// 
//    Rev 1.1   11 Jul 1995 07:47:38   sbc
// Moved globals and prototypes to bandview.h for "C++ migration"
// 
//    Rev 1.0   16 Mar 1995 16:13:52   sbc
// Initial revision.
// 
//    Rev 1.6   11 Aug 1994 14:16:44   sbc
// Global for freeform line sizing
// 
//    Rev 1.5   02 Aug 1994 17:28:46   jpb
// change findBandLine prototype
// 
//    Rev 1.4   02 Jun 1994 11:05:46   sbc
// "Unstatic" routine from wledit.c
// 
//    Rev 1.3   08 Mar 1994 14:08:58   sbc
// Include (conditionally) BandWnd for MFC version
// 
//    Rev 1.2   08 Mar 1994 11:33:04   sbc
// New function to invalidate the band area
// 
//    Rev 1.1   19 Nov 1993 17:42:18   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:10:52   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _WBAND_H_

//
// Make a definition for this module.
//
#define _WBAND_H_

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

// Freeform line size states
#define DRAGTOP 	1
#define DRAGBOT 	2
#define DRAGHIT 	4

//
// Structure Section:
// Place in this section any structure definitions.
//
typedef struct whenprint	/* line information */
{
	char whenprt;			/* line type (Body, Summary, etc.) */
	unsigned int whenif;			/* field index value or -1 (/LPL) */
	char whenflags;			/* when-print flags */
	char whenscan;			/* scanning file number */
	char whenrow;			/* line number (0-255) */
	char whenhtmode;		/* height mode (auto/inches/centimeters/points) */
	unsigned int whenhite;			/* height if override */
	int hite;				/* line height */
	long baseline;			/* screen baseline */
	long y;					/* screen bottom */
} WHENP;


//
// Global Data Section:
// Place in this section any global data.
//
#ifdef _WLEDIT_C_
    #define GLOBAL
#else
    #define GLOBAL extern
#endif

#undef GLOBAL
//
// Function Prototypes Section:
// Place in this section any function prototypes
//

#endif // end _WBAND_H_

// *************************** End of File ************************************
