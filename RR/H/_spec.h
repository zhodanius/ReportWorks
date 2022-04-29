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
// $Log:   D:/R&R Project/archives/H/_SPEC.H_V  $
// 
//    Rev 1.4   Jun 05 2001 10:33:24   nhubacker
// Longer name size for RSW
// 
//    Rev 1.3   13 Sep 1995 14:16:54   smh
// Port to 32-bits.
// 
//    Rev 1.2   12 Jul 1995 17:34:36   smh
// Moved all prototypes and data to CRrView class.
// 
//    Rev 1.1   05 Jul 1995 09:54:32   sjo
// Added TAB5 for CSV support.
// 
//    Rev 1.0   16 Mar 1995 16:15:00   sbc
// Initial revision.
// 
//    Rev 1.3   26 Sep 1994 16:37:46   smh
// Made wordWrap public and added argument to PrWrap.
// 
//    Rev 1.2   28 Apr 1994 15:52:08   sbc
// Another tab increment
// 
//    Rev 1.1   19 Nov 1993 17:40:10   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:11:06   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __SPEC_H_

//
// Make a definition for this module.
//
#define __SPEC_H_

#include "spec.h"
#if !defined(RSW)
#include "mffile.h"			// for MFFILE
#endif

// *** 
// Note: I didn't include the headers from h:\merge\h\spec.h.
// ***

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
// NUMFONTS wasn't being used, and defined (differently) in windows.h
// #define NUMFONTS	32		/* number of fonts per set */
#define ATTRIBUTES	4		/* Normal, Bold, Italic, Bold/Italic */
#define FONTNAMELEN	40		/* user-specified name length */
#define SEQLEN		128		/* begin control sequence length */
#define MAXWIDTHS	255		/* widths from 1 to 255 */
#define TRANSLATES	17*2	/* number of items per translation table */
#define TRANSTRING	20		/* 20-character translation string */


/***** R&R font library parameters *****/

/* file revision */
#define	RRF_MAJREV		0
#define RRF_MINREV		0

/* font flag bits */
#define FF_PROP		0x1		/* proportional */
#define FF_SCALE	0x2		/* scalable */

/* record types */
#define yfBOF		1		/* major rev (1 byte) */
							/* minor rev (1 byte) */
							/* flags (1 byte) */
							/* point size (2 bytes) */
							/* user-specified name string */
#define yfEOF		2		/* end of data */

#define yfNBEG		3		/* NORMAL begin sequence string */
#define yfNEND		4		/*        end      "       "    */
#define yfNWIDTH	5		/*        font width */

#define yfBBEG		6		/* BOLD begin sequence string */
#define yfBEND		7		/*      end      "       "    */
#define yfBWIDTH	8		/*      font width */

#define yfIBEG		9		/* ITALIC begin sequence string */
#define yfIEND		10		/*        end      "       "    */
#define yfIWIDTH	11		/*        font width */

#define yfBIBEG		12		/* BOLD/ITALIC begin sequence string */
#define yfBIEND		13		/*             end      "       "    */
#define yfBIWIDTH	14		/*             font width */

#define yfTRANSLATE	15		/* translation string */

#define yfNDOWN		16		/* download info */
#define yfBDOWN		17
#define yfIDOWN		18
#define yfBIDOWN	19

#define yfMAXTYPE	yfBIDOWN		/* max is max */

#define TAB0 3
#define TAB1 5
#define TAB2 8
#define TAB3 10
#define TAB4 12
#define TAB5 14
#define FTAB1 5
#define FTAB2 8
#define FTAB3 10
#define FTAB4 12
#define STAB1 5
#define STAB2 32

#define HDCHR 'v'
#define FTCHR '^'

#define SELBUF 800
#define ALIASSTR 21			/* buffer for (Alias: <aliasname>) */

#define FONTMAX 100			// maximum number of font/point size combos
#define LBIMAX   50			// no one would have more than 50 l,b,i, right?
#if defined(RSW)
#define LINELEN  90			// max length of a print spec line
#else
#define LINELEN  80			// max length of a print spec line
#endif

#define HUNDRED 100.00		// division factor 100ths of inch to inch fraction
#define TENS     10.0		// division factor for point size
									// Widths
#define MARGN		3			// left margin indent
#if defined(RSW)
#define NAME		30
#else
#define NAME		20
#endif
#define IFILE		25
#define INCM		3
#define THICK		4

//
// Structure Section:
// Place in this section any structure definitions.
//
/* R&R font structures */

// I couldn't find these two structures referenced, 
// so I'm going to comment them out and see what happens - scott
//typedef struct rf_attr		/* R&R font attribute structure */
//{
//	UINT	fixwid;		/* width of fixed-spaced font */
//	UINT *widths;		/* array of proportional font widths */
//	LPSTR begin;			/* turn it on */
//	LPSTR end;				/* turn it off */
//	char firstwid;			/* first character width stored */
//	char lastwid;			/* last one */
//} RFATTR;

//typedef struct		/* R&R font header structure */
//{
//	UINT points; 		/* point size * 10 */
//	LPSTR *trans;			/* pointer to array of translation strings */
//	RFATTR *at[ATTRIBUTES];	/* normal, bold, italic, bold/italic */
//	char spacing;	 		/* 0 => fixed, non-zero => proportional */
//	char scalable;			/* 0 => fixed, non-zero => scalable */
//} RFFONT;

// Made these UINTs b/c that's what hfont and hpoints have been turned to in wfield.h
typedef struct fontinfo							// structure for font info
{	UINT font;
	UINT points;
} FONTINFO;

//
// Global Data Section:
// Place in this section any global data.
//


	// No ext decs for LinePtr, LineBeg, LineCt cuz only used in specmain.c.



//
// Function Prototypes Section:
// Place in this section any function prototypes
//



// Prototypes for Report Spec modules.


#endif // end __SPEC_H_

// *************************** End of File ************************************
