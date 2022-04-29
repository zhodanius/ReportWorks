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
// $Log:   H:/vcsmfc/h/users.h_v  $
// 
//    Rev 1.6   10 Jun 1997 13:25:12   mfc
// Updated version number for RRW.LIC and associated files.
// 
//    Rev 1.5   18 Apr 1996 10:58:14   smh
// Added some prototypes for setup.
// 
//    Rev 1.4   09 Apr 1996 12:42:00   sjo
// For the 32 bit users.
// 
//    Rev 1.3   06 Dec 1995 15:59:04   dlm
// Allow 64-character user name instead of 16.
// 
//    Rev 1.2   06 Sep 1995 17:25:10   sjo
// 32 bit changes.
// 
//    Rev 1.1   11 Jul 1995 15:37:14   smh
// NOFILE->NO_FILE b/c conflicted w/ NOFILE in product.
// 
//    Rev 1.0   16 Mar 1995 16:13:42   sbc
// Initial revision.
// 
//    Rev 1.4   23 Aug 1994 12:54:56   sjo
// Fixed a problem where global was undef'd and it didnt need to be.
// 
//    Rev 1.3   22 Aug 1994 19:48:26   smh
// Combined the R?W User Management programs into one.
// 
//    Rev 1.2   09 Jun 1994 14:23:30   smh
// Moved MAXENTRIES here so can share it between users and setup, and increased
// it from 256 to 2000 so can support large DAT files.
// 
//    Rev 1.1   19 Nov 1993 17:40:54   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:11:44   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _USERS_H_

//
// Make a definition for this module.
//
#define _USERS_H_

/* Yes, I know this is in setup, but wrrdat.c is compiled for both
	rrwusers.exe and mscuistf.dll, and wusers.c is only compiled for
	rrwusers.exe
*/
#if defined (_WRRDAT_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif

//**********************************************************************
//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

	// current revision levels - from serial.h
	// see bottom of file for pictoral view of a .DAT file
#define MAJOR_SERIAL_X 8		// Version 8, RRW
#define MAJOR_SERIAL_S 8		//			  RSW

//#define MAXENTRIES	2000

/*** offsets to various info ***/

	/* once per file */

#define MAJ_VER		0		/* offset to major rev */
#define PROD_NO 	1		/* and product number */
#define SER_COUNT	2		/* up to 65536 serial numbers */
#define START_REC	4		/* offset to start of per-serial-number info */
#define START_SER	68		/* offset to first serial number */

	/* serial number packet */

#define IN_USE 	0	/* 64 bytes of in-use flag/workstation id (text) */
#define SERIAL	64	/* 4 bytes of serial number (long) */

#define MAX_SERIAL_LEN 19

/*** misc parameters ***/

#define HEAD_BYTES	4		/* number of "header" bytes */
#define CNT_BYTES	2		/* # bytes in serial number count */

#define SZ_PER_SER	68		/* size of per-serial-number info (68 bytes) */
#define USE_BYTES	64		/* # bytes of in-use flag/workstation id */
#define SER_BYTES	4		/* # bytes in serial number */

#define	SER_OVL		-512	/* location of serial number in RR.OVL */

/*** product numbers ***/

#define PROD_NUM_X	20		// the dBASE flavor
#define PROD_NUM_S	30		// RSW

// Modes for what product we're using
#define MODE_NOT	0
#define MODE_RRW	1
#define MODE_RSW	2

/*** status codes for destination file ***/
#define GOODFILE 1
#define NO_FILE 2
#define BADREAD 3
#define LOCKED 4
#define BADREV 5
#define BADPROD 6


//**********************************************************************

//
// Structure Section:
// Place in this section any structure definitions.
//
	// from serial.h
typedef struct dathead		// Dat file header structure
{	char version;				// one byte version number
	char product;				// one byte product number
	short count;			// two byte count
} DATHEAD;

//**********************************************************************
//
// Global Data Section:
// Place in this section any global data.
//



#if defined (WIN32)
GLOBAL short CheckWord;
#else
GLOBAL unsigned CheckWord;
#endif
GLOBAL DATHEAD DatFile;
GLOBAL int Status;						// destination file open status

GLOBAL WORD ProductMode
 #if defined(_WRRDAT_C_)
 = MODE_NOT
 #endif
;	// from serial.h
/* extern int near Prod_Num;	 product type code */




//**********************************************************************
//
// Function Prototypes Section:
//
extern BOOL CALLBACK MakeSingle( LPSTR szLicFile, int serNum );
extern BOOL CALLBACK AddSerialNumbers( LPSTR szLicFile, int serNum, int serCount );
extern BOOL opendat( LPSTR szLicFile, HANDLE * hFile);
extern int findser( LPSTR szLicFile, int findNum );




#undef GLOBAL

#endif // end _USERS_H_

/* from serial.h - R?USERS.DAT & R?LANPAK.DAT file formats

 Decimal
  Byte
 Offset		  R?USERS.DAT FILE FORMAT
		  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
	0	  ³  MAJOR REV   ³  PRODUCT #   ³
		  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
	2	  ³  SERIAL NUMBER COUNT WORD   ³
		  ÆÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍµ
	4	  ³       WORKSTATION ID        ³    First Entry
		  ³         (64 bytes)          ³
		  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
	68	  ³        SERIAL NUMBER        ³
		  ³          (4 bytes)          ³
		  ÆÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍµ
	72	  ³       WORKSTATION ID        ³    Second Entry
		  ³         (64 bytes)          ³
		  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
   136	  ³        SERIAL NUMBER        ³
		  ³          (4 bytes)          ³
		  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
						 ù
						 ù
						 ù


 Decimal
  Byte
 Offset		  R?LANPAK.DAT FILE FORMAT
		  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
	0	  ³  MAJOR REV   ³  PRODUCT #   ³
		  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
	2	  ³  SERIAL NUMBER COUNT WORD   ³
		  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
	4	  ³  ENCRYPTED SERIAL # COUNT   ³
		  ÆÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍµ
	6	  ³         (62 bytes)          ³
		  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
	68	  ³        SERIAL NUMBER        ³
		  ³          (4 bytes)          ³
		  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
*/



// *************************** End of File ************************************
