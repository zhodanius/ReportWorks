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
// $Log:   H:/vcsmfc/h/dformat.h_v  $
// 
//    Rev 1.5   07 Mar 1997 17:09:20   jpb
// equitrac runtime scripting support
// 
//    Rev 1.4   26 Jul 1995 17:16:50   sbc
// Arrays s/b near
// 
//    Rev 1.3   19 Jul 1995 13:07:14   sbc
// Move stuff to rrdoc.h
// 
//    Rev 1.2   25 Apr 1995 13:12:20   sbc
// Fix control define
// 
//    Rev 1.1   25 Apr 1995 09:55:26   sbc
// 6.1.03 -> 7.0.01 merge
// 
//    Rev 1.0   16 Mar 1995 16:12:30   sbc
// Initial revision.
// 
//    Rev 1.4   10 Apr 1995 16:19:34   sbc
// Remove arg to fieldAlign()
// 
//    Rev 1.3   04 Apr 1995 17:09:06   sjo
// changed the order of the timeformat array so that 24 hour times show in
// the list first.
// 
//    Rev 1.2   28 Mar 1995 14:59:38   sbc
// Date/time changes
// 
//    Rev 1.1   19 Nov 1993 17:39:26   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:10:32   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _DFORMAT_H_

#if defined _PICUTIL_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

//
// Make a definition for this module.
//
#define _DFORMAT_H_

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//

GLOBAL unsigned near dateFormats[]
#if defined _PICUTIL_C_
 =
{
	picDMY|picY2,				// dd-mmm-yy
	picDMY|picY4,				// dd-mmm-yyyy
	picDM,						// dd-mmm
	picMY|picY2,				// mmm-yy
	picMY|picY4,				// mmm-yyyy
	picFMDY|picY4|picDLEFT, 	// mmmm d, yyyy
	picFDMY|picY4|picDLEFT, 	// d mmmm yyyy
	picFMY|picY4|picDLEFT,		// mmmm yyyy
	picFMD|picDLEFT,			// mmmm d
	picFDM|picDLEFT,			// d mmmm
	picD41|picY2,				// mm/dd/yy
	picD41|picY4,				// mm/dd/yyyy
	picD42|picY2,				// dd/mm/yy
	picD42|picY4,				// dd/mm/yyyy
	picD43|picY2,				// dd.mm.yy
	picD43|picY4,				// dd.mm.yyyy
	picD44|picY2,				// yy-mm-dd
	picD44|picY4,				// yyyy-mm-dd
	picD51, 					// mm/dd
	picD52, 					// dd/mm
	picD53, 					// dd.mm
	picD54, 					// mm-dd
	picDLI, 					// Long International
	picDSI						// Short International
}
#endif
;

GLOBAL unsigned near timeFormats[]
#if defined _PICUTIL_C_
 =
{
	pic2HM24,		// h:mm			(24 hr)
	pic2HHM24,		// hh:mm		(24 hr, lead 0)
	pic2HMS24,		// h:mm:ss		(24 hr)
	pic2HHMS24,		// hh:mm:ss		(24 hr, lead 0)
	pic2HM12,		// h:mm xM		(12 hr)
	pic2HHM12,		// hh:mm xM		(12 hr, lead 0)
	pic2HMS12,		// h:mm:ss xM	(12 hr)
	pic2HHMS12,		// hh:mm:ss xM	(12 hr, lead 0)
	pic2WTI			// International
}
#endif
;

GLOBAL char near numFormats[]
#if defined _PICUTIL_C_
 =
{
	picFIXED, picEXP, picCURRENCY, picCOMMA,
	picGENERAL, picPERCENT
}
#endif
;

// Internal field alignments and pictures
GLOBAL int near charFldAlign[]
#if defined _PICUTIL_C_
 = { picLEFT, picCENTER, picRIGHT }
#endif
;

GLOBAL int near textAlign[]
#if defined _PICUTIL_C_
 = { txLEFT, txCENTER, txRIGHT }
#endif
;

GLOBAL int near dateAlign[]
#if defined _PICUTIL_C_
 = { picDLEFT, picDCENTER, picDRIGHT }
#endif
;

GLOBAL int near numAlign[]
#if defined _PICUTIL_C_
= { picNLEFT, picNCENTER, picNRIGHT }
#endif
;

GLOBAL int near wrapAlign[]
#if defined _PICUTIL_C_
= { picWLEFT, picWRIGHT, picWFULL }
#endif
;

//
// Function Prototypes Section:
// Place in this section any function prototypes
//

#undef GLOBAL

#endif // end _DFORMAT__

// *************************** End of File ************************************
