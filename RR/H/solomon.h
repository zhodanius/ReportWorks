// ****************************************************************************
//
//      (C) Copyright 1994 Concentric Data Systems, Inc.
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
// $Log:   H:/vcsmfc/h/solomon.h_v  $
// 
//    Rev 1.0   16 Mar 1995 16:13:30   sbc
// Initial revision.
// 
//    Rev 1.1   14 Nov 1994 10:16:18   dlm
// Cleaned up SolomonInit structure definition.
// 
//    Rev 1.0   11 Apr 1994 17:29:48   dlm
// Initial revision.
// 
// ****************************************************************************

#if defined(SOLOMON)		// only relevant to Solomon version

//
// Check to make sure this is not included more than once.
//
#ifndef _SOLOMON_H_

//
// Includes needed by this header.
//

#if defined _WINIT_C_	// The only GLOBAL is used in winit.c
#define GLOBAL 
#else
#define GLOBAL extern
#endif

//
// Make a definition for this module.
//
#define _SOLOMON_H_

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

//
// Structure Section:
// Place in this section any structure definitions.
//
// The contents of the SOLOMONINIT structure are obtained by a call
//  to a Solomon-provided DLL, whose name is RRSOL.DLL.
typedef struct SolomonInit
{
	LPSTR lpDataSource;	// required
	LPSTR lpUserName;	// required unless lpSessionID is provided
	LPSTR lpPassword;	// required unless lpSessionID is provided
	LPSTR lpSessionID;	// required unless lpUserName and lpPassword are provided
} SOLOMONINIT;

typedef SOLOMONINIT FAR* LPSOLOMONINIT;

//
// Global Data Section:
// Place in this section any global data.
//
GLOBAL SOLOMONINIT InitialValues;
GLOBAL BOOL SolomonCrippled;

//
// Function Prototypes Section:
// Place in this section any function prototypes
//

#undef GLOBAL
#endif // end _SOLOMON_H_

#endif	// end #if defined(SOLOMON)
// *************************** End of File ************************************

