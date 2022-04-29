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
// This is the header for items private to export.  The R?WPD.DLL private 
// header file is _pd.h.  The two share a public header file, pd.h.
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/_exp.h_v  $
// 
//    Rev 1.1   21 Sep 1995 11:23:00   smh
// 32-bit export DLLS.
// 
//    Rev 1.0   16 Mar 1995 16:14:28   sbc
// Initial revision.
// 
//    Rev 1.3   25 Oct 1994 12:54:06   smh
// Added insert mode constants for text export word-wrap support.
// 
//    Rev 1.2   20 Oct 1994 17:16:38   smh
// "printLine" -> "sendLine" so doesn't conflict w/ RRWPD.DLL routine proto.
// 
//    Rev 1.1   19 Nov 1993 17:41:58   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:12:02   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __EXP_H_

//
// Make a definition for this module.
//
#define __EXP_H_

#include "pd.h"
//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
// Windows export header file

	// from wexport.h
#define RRWVTRES	720
#define PD_LPI		6			/* assume 6 lines per inch */
#define FACTOR		120		/* RRWVTRES / PD_LPI */
#define EXP_CPI	10			/* characters per inch */

#define EXPPS 		ps->pDest.exp
									/* next two from rpparm.h */
#define NCOL		255		/* number of columns per line in screen buffer */
#define PBUFSIZE	(NCOL*4)	/* page buffer size (bytes) */
#define LBUFSIZE  200		/* line buffer size from pdriver.h */

							// Portrait sizes
#define VPLETSZ	66			// letter ->    11 inches  * 6 LPI
#define VPLEGSZ	84			// legal ->     14         * 6   
#define VPEXESZ	63			// executive -> 10.5       * 6
#define VPA4SZ		70			// A4 ->			 11.7       * 6
							// Landscape sizes
#define VLLETSZ	51			// letter ->    8.5 inches * 6 LPI
#define VLLEGSZ	51			// legal ->     8.5        * 6   
#define VLEXESZ	43			// executive -> 7.25       * 6
#define VLA4SZ		49			// A4 ->			 8.3        * 6

// insert modes - line or page
#define INSLINE	1
#define INSPAGE	2

//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//




//
// Function Prototypes Section:
// Place in this section any function prototypes
//


	// from wexport.h
extern BOOL hz_position(LPPRT_STRUCT ps,UINT column);	/* position horizontally */
extern BOOL sendchar(LPPRT_STRUCT ps, int ch);
extern int expsizefld(LPPRT_STRUCT ps,UINT far *units,UINT far *spaces,int endcode,UINT far *pos);
extern UINT pixToCols(LPPRT_STRUCT ps,UINT x);
extern BOOL flushEBufs(LPPRT_STRUCT ps);
extern BOOL sendLine(LPPRT_STRUCT ps,char * lbuf,int size);



#endif // end __EXP_H_

// *************************** End of File ************************************
