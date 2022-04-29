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
// $Log:   H:/vcsmfc/h/_setup.h_v  $
// 
//    Rev 1.0   16 Mar 1995 16:14:56   sbc
// Initial revision.
// 
//    Rev 1.1   08 Sep 1994 08:33:36   smh
// Added support for gathering user name and company in Setup.
// Added some dialog constants, and some key values for WIN.INI
// and SERIALNO.INI. (RRW.INI key values in wmain.h.)
// 
//    Rev 1.0   14 Oct 1993 10:11:42   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __SETUP_H_

//
// Make a definition for this module.
//
#define __SETUP_H_

// No public header file for setup

#if defined(_DLGPROCS_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
	// RSW help ids
#if defined(RSW)
#define 	HI_OVERVIEW		1
#define 	HI_DESTDIR		2
#define 	HI_OPTIONS 		3
#define 	HI_LINKDIR		4
#define		HI_SERIAL	5
#define		HI_WORKSTATION	6
#define		HELPSetup		7

	// RRW help ids
#else
#define 	HI_WELCOME 				1
#define 	HI_OPTIONS 				2
#define 	HI_LINKDIR				3
#define 	HI_OVERVIEW  			4
#endif

#define IDC_STATIC	-1
/*
**	PushButton Control IDs
*/
#define IDC_A        401
#define IDC_B        402
#define IDC_C        403
#define IDC_D        404
#define IDC_E        405
#define IDC_F        406
#define IDC_G        407
#define IDC_H        408
#define IDC_I        409
#define IDC_J        410
#define IDC_K        411
#define IDC_L        412
#define IDC_M        413
#define IDC_N        414
#define IDC_O        415
#define IDC_P        416
#define IDC_Q        417
#define IDC_R        418
#define IDC_S        419
#define IDC_T        420
#define IDC_U        421
#define IDC_V        422
#define IDC_W        423
#define IDC_X        424
#define IDC_Y        425
#define IDC_Z        426

/*
**	Edit Control IDs
*/
#define IDC_EDIT     427
#define IDC_EDIT2    428

/*
**	ListBox Control IDs
*/
#define IDC_LIST1    429
#define IDC_LIST2    430

/*
**	Text Control IDs
*/
#define IDC_TEXT1    431
#define IDC_TEXT2    432
#define IDC_TEXT3    433
#define IDC_TEXT4    434
#define IDC_TEXT5    435
#define IDC_TEXT6    436
#define IDC_TEXT7    437
#define IDC_TEXT8    438
#define IDC_TEXT9    439
#define IDC_TEXT10   440
#define IDC_TEXT11   441

/*
**	Radio and Checkbox Button Control IDs
*/
#define IDC_B0       450
#define IDC_B1       451
#define IDC_B2       452
#define IDC_B3       453
#define IDC_B4       454
#define IDC_B5       455
#define IDC_B6       456
#define IDC_B7       457
#define IDC_B8       458
#define IDC_B9       459
#define IDC_B10      460

/*
**	ICON IDs
*/
#define IDC_ICON0    500
#define IDC_ICON1    501
#define IDC_ICON2    502
#define IDC_ICON3    503
#define IDC_ICON4    504
#define IDC_ICON5    505
#define IDC_ICON6    506
#define IDC_ICON7    507
#define IDC_ICON8    508
#define IDC_ICON9    509
#define IDC_SETUP    202

/*
** Special Pushbotton IDs
*/
#define IDC_SP1    521
#define IDC_SP2    522
#define IDC_SP3    523
#define IDC_SP4    524
#define IDC_SP5    525
#define IDC_SP6    526
#define IDC_SP7    527
#define IDC_SP8    528
#define IDC_SP9    529
#define IDC_SP10   530

/*
** Status Text Field IDs
*/

#define IDC_STATUS1    541
#define IDC_STATUS2    542
#define IDC_STATUS3    543
#define IDC_STATUS4    544
#define IDC_STATUS5    545
#define IDC_STATUS6    546
#define IDC_STATUS7    547
#define IDC_STATUS8    548
#define IDC_STATUS9    549
#define IDC_STATUS10   550


// Conflict dialog controls
#define IDC_MESS 575
#define IDC_OLDER 576
#define IDC_ALWAYS 577
#define IDC_NEVER 578

/*
** Dialog IDs
*/
#define WELCOME                     100
#define ASKQUIT                     200
#define DESTPATH                    300
#define EXITFAILURE                 400
#define EXITQUIT                    600
#define EXITSUCCESS                 700
#define OPTIONS                     800
#define APPHELP                     900
#define SINGLELIST                 1900
#define CHECK                      2500
#define EXTENDEDLIST               3900
#define MODELESS                   5000
#define MULTILIST                  5200
#define CUSTINST                   6200
#define TOOBIG                     6300
#define BADPATH                    6400
#define CDALREADYUSED              7100
#define CDBADFILE                  7200
#define CDCONFIRMINFO              7300
#define CDGETNAME                  7400
#define CDGETNAMEORG               7500
#define CDGETORG                   7600
#define CDBADNAME                  7700
#define CDBADORG                   7800
#define LINKDIR                    7900
#define LANPATH                    8000
#define WSOPTIONS                  8100
#define SYSDIR                     8200
#define EXITWS					        8300

#define CHECKPLATFORM               1100
#define WSAPPHELP                   1000
#define WSDESTPATH                  1200
#define ALLCHOICES                  1400
#define WINDIR                      1500
#define CONFLICT							1300
#define WSDRIVERS							1600
#define IDC_GCOMBO                  1402
#define IDC_UNAME				701
#define IDC_CONAME			702


//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//
GLOBAL char WxMSUInfo[]
#if defined (_DLGPROCS_C_)
 = "MS User Info"
#endif
;
GLOBAL char WxMSUName[]
#if defined (_DLGPROCS_C_)
 = "DefName"
#endif
;
GLOBAL char WxMSComp[] 
#if defined (_DLGPROCS_C_)
 = "DefCompany"
#endif
;
GLOBAL char WxSNIni[]	
#if defined (_DLGPROCS_C_)
 = "SERIALNO.INI"
#endif
;
GLOBAL char WxSNUInfo[]
#if defined (_DLGPROCS_C_)
 = "mswindows"
#endif
;
GLOBAL char WxSNUName[]
#if defined (_DLGPROCS_C_)
 = "username"
#endif
;
GLOBAL char WxSNComp[]
#if defined (_DLGPROCS_C_)
 = "company"
#endif
;
//
// Function Prototypes Section:
// Place in this section any function prototypes
//

#undef GLOBAL

#endif // end __SETUP_H_

// *************************** End of File ************************************
