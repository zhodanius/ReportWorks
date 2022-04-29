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
// $Log:   H:/vcsmfc/h/pic.h_v  $
// 
//    Rev 1.6   28 Sep 1995 11:10:42   smh
// Added some 32-bit field picture masks.
// 
//    Rev 1.5   18 Aug 1995 14:51:04   mjs
// Moved strings to global.h
// 
//    Rev 1.4   01 Aug 1995 11:39:38   mjs
// Gave newD4 a size.
// 
//    Rev 1.3   24 Jul 1995 14:26:52   pjm
// R&R class changes.
// 
//    Rev 1.2   25 Apr 1995 12:28:56   sbc
// Forgot include file (merge)
// 
//    Rev 1.1   25 Apr 1995 12:21:02   sbc
// 6.1.03 -> 7.0.01 merge
// 
//    Rev 1.0   16 Mar 1995 16:13:06   sbc
// Initial revision.
// 
//    Rev 1.13   07 Apr 1995 17:56:52   sjo
// Support for picDateToDatetime for 6.0 to 6.1 compatibility.
// 
//    Rev 1.12   06 Apr 1995 19:04:26   sjo
// Part of fix for space dots in times and dates.
// 
//    Rev 1.11   05 Apr 1995 13:49:04   sbc
// New date/time bits to control display of date or time portion
// 
//    Rev 1.10   03 Apr 1995 17:46:36   dlm
// Added argument to bldIntTime() prototype that says whether or not to
//  put a space before AM/PM.
// 
//    Rev 1.9   31 Mar 1995 09:58:14   sjo
// Added an arg to the time pic routines.
// 
//    Rev 1.8   29 Mar 1995 19:40:44   sjo
// Changes for international time support.
// 
//    Rev 1.7   28 Mar 1995 14:16:50   dlm
// Added new time-format bits (pic2...) and removed old time-format bits
//  (pic...).  Added DTPIC2DFLT and TPIC2DFLT.
// 
//    Rev 1.6   27 Mar 1995 19:31:28   sjo
// Changed some interfaces for long string support.
// 
//    Rev 1.5   24 Mar 1995 17:07:42   sjo
// Changed some pic flags for datetime support.
// 
//    Rev 1.4   23 Mar 1995 17:09:30   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
//
//    Rev 1.3   02 Aug 1994 14:01:32   sbc
// Add newD4 array
// 
//    Rev 1.2   29 Nov 1993 13:07:40   erp
// use Windows short international format for default date.
// 
//    Rev 1.1   19 Nov 1993 17:41:48   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:10:40   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _PIC_H_

//
// Make a definition for this module.
//

#define _PIC_H_

#include "mffield.h"	// for LPMFFIELD

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

/* string pictures */
#define picASIS		0x0001

#define picLEFT		0x0010
#define picCENTER	0x0020
#define picRIGHT	0x0030
#define picWRAP		0x0040

#define picWLEFT 	0x0100
#define picWFULL	0x0200
#define picWRIGHT	0x0300

#define picEXP		0x0001
#define picGENERAL	0x0002

#define picPERCENT	0x0004
#define picFIXED	0x0005
#define picCURRENCY	0x0006
#define picCOMMA	0x0007
#define picTELEPHONE	0x0008

#if defined(RRPACE)
#define picNPACE	0x0009
#endif

#define picLEAD0	0x0100
#define picBLANK0	0x0200
#define	picNLEFT	0x1000
#define	picNCENTER	0x2000
#define	picNRIGHT	0x3000

/* numeric pictures */
#define NUMALIGN(f) (((LPMFFIELD)(f))->dFldPic & 0xF000)
#define DATEALIGN(f) (((LPMFFIELD)(f))->dFldPic & 0x0F00)
#define TIMEALIGN(f) (((LPMFFIELD)(f))->dFldPic & 0x0F00)

#define NUMPIC(f) (((LPMFFIELD)(f))->dFldPic & 0x000F)

#define picCLEARNUM(f)	f->dFldPic &= 0xFFFFFFF0
#define picCLEARDATE(f)	f->dFldPic &= 0xFFFF0FF0;

// Datetime pictures are a combo of date and time pictures, there
//	 arent any that are specific to the datetime type.

/* Time pictures - dFldPic2 */
#define pic2WTI	0x8000	// Windows time international - ignore other time bits

#define pic2SS	0x0001	// Display seconds
#define pic2H24	0x0002	// 24 hour format - if off, show AM & PM
#define pic2HH	0x0004	// show leading 0 for hours (always show 2 hour digits)
#define pic2SHOWDATE	0x0010	// Show date portion of DATETIME field
#define pic2SHOWTIME	0x0020	// Show time portion of DATETIME field

// Named combinations of pic2 time-format bits
#define pic2TMASK	0x8007		// dFldPic2 mask for named time formats
// dFldPic2 mask for show date/time portions of DATETIME:
#define pic2SHOWDTMASK	(pic2SHOWDATE | pic2SHOWTIME)

#define pic2HM12	(0)								// h:mm xM		(12 hr)
#define pic2HHM12	(pic2HH)						// hh:mm xM		(12 hr, lead 0)
#define pic2HMS12	(pic2SS)						// h:mm:ss xM	(12 hr)
#define pic2HHMS12	(pic2SS | pic2HH)				// hh:mm:ss xM	(12 hr, lead 0)
#define pic2HM24	(pic2H24)						// h:mm			(24 hr)
#define pic2HHM24	(pic2H24 | pic2HH)				// hh:mm		(24 hr, lead 0)
#define pic2HMS24	(pic2H24 | pic2SS)				// h:mm:ss		(24 hr)
#define pic2HHMS24	(pic2H24 | pic2SS | pic2HH)		// hh:mm:ss		(24 hr, lead 0)

// Time alignments still in dFldPic (not dFldPic2)
#define picTLEFT   0x0100	// Same as the date alignment. You can not have a
#define picTCENTER 0x0200	//  datetime with a date left and time right alignment.
#define picTRIGHT  0x0300

#define MAX24TIME	5	// 12:45
#define MAXAMTIME	8	// 12:45 AM
#define MAX24TIMES 8  // 12:45:00
#define MAXAMTIMES 11 // 12:45:00 AM
#define MILLESIZE	4		// MILLESECONDS add four places
#define MICROSIZE 7		// Microseconds add 7 places

/* date pictures */
#define picDMY	0x0001
#define picD4	0x0002	/* not set by RRW */
#define picD5	0x0003	/* not set by RRW */
#define picDM	0x0004
#define picMY	0x0005
#define picFMDY	0x0006
#define picFDMY	0x0007
#define picFMY	0x0008
#define picFMD	0x0009
#define picFDM	0x000A

#if defined(RRPACE)
#define picDPACE	0x000B
#define DATEPIC(f) (((LPMFFIELD)(f))->dFldPic & 0x000F)
#endif

#define picD41	0x1000
#define picD42	0x2000
#define picD43	0x3000
#define picD44	0x4000
#define picD51	0x5000
#define picD52	0x6000
#define picD53	0x7000
#define picD54	0x8000
#define picDLI	0x9000
#define picDSI	0xA000
#define picY2	0x0000
#define picY4	0x0010
#define picDLEFT   0x0100
#define picDCENTER 0x0200
#define picDRIGHT  0x0300

#define MAXFMDY 18	/* length of "September 10, 1987", for example */
#define MAXFDMY 17	/* length of "10 September 1987", for example */
#define MAXFMY  14	/* length of "September 1987", for example */
#define MAXFMD  12	/* length of "September 10", for example */
#define MAXFDM  12	/* length of "10 September", for example */

#define CHARPIC(f) (((LPMFFIELD)(f))->dFldPic & 0x000F)

#if defined(RRPACE)
#define picAPACE	0x0002
#endif

#define ALIGNED(f) (((LPMFFIELD)(f))->dFldPic & 0x00F0)
#define JUSTIFIED(f) (((LPMFFIELD)(f))->dFldPic & 0x0F00)

/* defaults */
#ifdef RRPACE
#define NPACEDFLT (picNPACE | picNRIGHT)
#define DPACEDFLT (picDPACE | picDLEFT)
#define APACEDFLT (picAPACE | picLEFT)
#endif
#define NPICDFLT (picFIXED|picNRIGHT)
//
// Here is where we define the default date layout. We now use here the
// Windows short international format
//
#define DPICDFLT (picDSI|picDLEFT)

// Here is where we define the default time layout. We will use the
// Windows international time format
#define TPICDFLT (picDLEFT)
#define TPIC2DFLT (pic2WTI) 

// Default date time layout.  Use international time format
//  and the short international date format.
// Also, show both date and time portions.
#define DTPICDFLT (picDSI | picDLEFT)
#define DTPIC2DFLT (pic2WTI | pic2SHOWDATE | pic2SHOWTIME) 


#define APICDFLT (picASIS|picLEFT)
#define LPICDFLT (picASIS|picLEFT)
#define MPICDFLT (picASIS|picWRAP)
#define WPICDFLT (picWRAP|picWLEFT)

//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//
#ifdef _PICDATA_C_
 #define GLOBAL
#else
 #define GLOBAL extern
#endif

#if 0 // moved for class stuff
GLOBAL int near LogStrLen
#ifdef _PICDATA_C_
 = 1
#endif
;

GLOBAL int near CurStrLen
#ifdef _PICDATA_C_
 = 1
#endif
;

GLOBAL int near PicAllowOflo;	/* TRUE=> don't *-fill on col width overflo */
#endif // end of class stuff

#undef GLOBAL

//
// Function Prototypes Section:
// Place in this section any function prototypes
//

#if 0	// moved to class header
extern void         zcomposedate(char *month, char *day, char *year, char *out, unsigned int picture);
extern void 		  zcomposetime(int dispErr,char hours, char minutes, char seconds, long mSeconds,unsigned int picstyle, LPSTR out);
extern void			  zcomposetimeshape(unsigned int picstyle, char *out,int font);
extern void 		  bldIntTime(int dispErr, char hours, char minutes, char seconds, long mSeconds, LPSTR out, BOOL space);
extern int          picshape(LPMFFIELD fld, char *out);
extern int          pictest(LPMFFIELD fld, char *out, char *suffix);
extern int          picdata(LPMFFIELD fld, char *out, char far *data, int col, int mode, char *endbuf);

#ifdef RSW
extern void 		  picDateToDatetime(LPMFFIELD fld, unsigned int oldpics);
#endif


#endif // end _PIC_H_
#endif // end class header stuff
// *************************** End of File ************************************


