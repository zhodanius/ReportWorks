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
// $Log:   H:/vcsmfc/h/_users.h_v  $
// Rev 1.5     16 Jun 2015 16:45:10   CAS
// changed prototype for unlock() to take an argument so that
// the dialog will unlock 1 or ALL of the serial numbers shown
// 
//    Rev 1.4   12 Apr 1996 11:38:28   pjm
// Change prototypes for add serialAdd and serialDelete.
// 
//    Rev 1.3   09 Apr 1996 12:42:12   sjo
// For the 32 bit users.
// 
//    Rev 1.2   13 Feb 1996 08:02:52   sbc
// Change DAT file names
// 
//    Rev 1.1   06 Sep 1995 17:25:20   sjo
// 32 bit changes.
// 
//    Rev 1.0   16 Mar 1995 16:15:02   sbc
// Initial revision.
// 
//    Rev 1.5   23 Aug 1994 12:54:30   sjo
// Fixed a problem where GLOBAL was not #UNDEF'd at the end.
// 
//    Rev 1.4   22 Aug 1994 19:47:46   smh
// Combined the R?W user management programs into one.
// 
//    Rev 1.3   09 Jun 1994 14:25:14   smh
// Changed max # of serial numbers from 256 to 2000.  Now alloc the array
// so change doesn't increase the EXE size.
// 
//    Rev 1.2   19 Nov 1993 17:41:12   sbc
// Add extern C for C++
// 
//    Rev 1.1   18 Oct 1993 17:33:48   smh
// Added data definitions from wusers.c and twusers.c (latter now obsolete).
// 
//    Rev 1.0   14 Oct 1993 10:11:44   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __USERS_H_

//
// Make a definition for this module.
//
#define __USERS_H_

#include "users.h"

#if defined (_WUSERS_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif

// ********************************************************************
//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//


	// from wusers.h
#define DLG_MAIN  	100
#define DLG_DISK  	200
#define DLG_SERIALNUMBER                101

#define ID_LIST   		101
#define ID_UNLOCK 		102
#define ID_ADD    		103
#define ID_DELETE 		104
#define ID_INACTIVE		105
#define ID_READERR		106
#define ID_WRITEERR		107
#define ID_DELERR		108
#define ID_GOTUSER		109
#define ID_ADDSERNO		110
#define ID_DELSERNO		111
#define ID_INVALIDSERNO	112
#define ID_TOTAL		112
#define ID_ADDWINTITLE 	113
#define ID_DELWINTITLE 	114

#define ID_INUSE     115
#define ID_NOTFOUND	116
#define ID_BADXREV	117
#define ID_BADVER		118
#define ID_NOMEM		119
#define ID_DISK	   309
#define ID_NOTEXP		310
#define ID_BADSREV	311
#define ID_SERIALNUMBER                1001

// Use WINPATHLEN definition in product.h - SMH 10/4/93
// #define WINPATHLEN   144
#define WINSTRLEN    255
#define READTIMEOUT	3		/* seconds between reads in Status */


// ********************************************************************
//
// Structure Section:
// Place in this section any structure definitions.
//
	// from wusers.h
typedef struct
{
	union ser
	  {
		long sn;			/* serial number */
		char snc[4];		/* 4 bytes */
	  } sno;
	char id[USE_BYTES];	/* user id */
} STAT;

// ********************************************************************
//
// Global Data Section:
// Place in this section any global data.
//



GLOBAL char DatPath[WINPATHLEN+1];
GLOBAL char near Empty[USE_BYTES];
GLOBAL HWND	_hDlgMain;
GLOBAL HINSTANCE _hInstance;
GLOBAL BYTE	_lasttime[4];
GLOBAL char	_szDisk[6];
GLOBAL char _szSerialNumber [MAX_SERIAL_LEN+1] ;
GLOBAL char _szGoldSerialNumber [MAX_SERIAL_LEN+1] ;	/* this is the serial number with dashes */

// GLOBAL STAT users[MAXENTRIES+1];
GLOBAL WORD	_wTitle;


GLOBAL char near dat_fileX[]
 #if defined(_WUSERS_C_)
 = "RRW.LIC"
 #endif
;
GLOBAL char near dat_fileS[]
 #if defined(_WUSERS_C_)
 = "RSW.LIC"
 #endif
;

GLOBAL char _LinkDirX[]
 #if defined(_WUSERS_C_)
 = "RRWLink"
 #endif
;
GLOBAL char _LinkDirS[]
 #if defined(_WUSERS_C_)
 = "RSWLink"
 #endif
;

GLOBAL char near link_fileX[]
 #if defined(_WUSERS_C_)
 = "RRWLINK.INI"
 #endif
;
GLOBAL char near link_fileS[]
 #if defined(_WUSERS_C_)
 = "RSWLINK.INI"
 #endif
;

GLOBAL char _szAppName[]
 #if defined(_WUSERS_C_)
 = "R&R User Management"
 #endif
;
GLOBAL char _szAppNameX[]
 #if defined(_WUSERS_C_)
 = "R&R Xbase User Management"
 #endif
;
GLOBAL char _szAppNameS[]
 #if defined(_WUSERS_C_)
 = "R&R SQL User Management"
 #endif
;

GLOBAL int _TabStops[2]
#if defined(_WGLOBAL_C_)
 = { 52, 0 }		// 60-8 (x values of headings in .dlg)
#endif
;	
GLOBAL STAT far * UserList
#if defined(_WUSERS_C_)
 = NULL
#endif
;

//if defined RSW
//GLOBAL unsigned SerCount;



// ********************************************************************
//
// Function Prototypes Section:
// Place in this section any function prototypes
//


	// These are all static routines (re)defined in wusers.c
void init(void);	 
BOOL FAR PASCAL MainDlgProc (HWND hDlg, UINT wMsg, WPARAM wParam, LPARAM lParam);
// Rev 1.5
void unlock(int);
//void unlock(void);
void serialAdd(HWND hParent);
void serialDelete(HWND hParent);
BOOL fillListBox(WORD wSelect);
void dispusers(STAT far * users, int cnt);
BOOL opendat(LPSTR szPath, HANDLE * handle);
BOOL readser(LPSTR szPath, LPSTR szSerNo);
int findser( LPSTR szLicFile, int findNum )  ;
BOOL writeser( LPSTR szLicFile, int serNum ) ;
BOOL unlockser( LPSTR szLicFile, int serNum );

VOID flipinc(LPSTR sno);
LONG flipit(LPSTR sno);
PSTR getIdString(WORD id,int buf);
BOOL zack(LPSTR format);
BOOL zack2(LPSTR format,LPSTR a);
BOOL fileTime(void);

int ComputeCount( char* pSerialNumberString );




#undef GLOBAL

#endif // end __USERS_H_

// *************************** End of File ************************************
