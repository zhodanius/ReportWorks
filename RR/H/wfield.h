// ****************************************************************************
//
//      (C) Copyright 2001 Liveware Publishing Inc.
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
// $Log:   D:/R&R Project/archives/H/WFIELD.H_V  $
// 
//    Rev 1.15   Oct 03 2003 10:09:32   Admin
// Add cropping rectangle to image structure
// 
//    Rev 1.14   Apr 25 2002 11:40:14   Admin
// Add members to rrimage structure
// 
//    Rev 1.13   07 May 1997 17:55:44   SRM
// move rrchart struct to rrchart.h
// 
//    Rev 1.12   07 May 1997 16:51:46   SRM
// add chain of metafile handles to rrchart structure
// 
//    Rev 1.11   05 May 1997 15:33:48   jsf
// removed CHARTING conditional in RRCHART struct
// 
//    Rev 1.10   24 Apr 1997 16:16:22   SRM
// rrchart structure improvements
// 
//    Rev 1.9   27 Mar 1997 10:22:36   dlm
// Another round of charting code with stuff conditional on CHARTING.
// 
//    Rev 1.8   14 Mar 1997 16:27:12   SRM
// chart support initial checkin
// 
//    Rev 1.7   20 Oct 1995 14:30:16   sbc
// Change WRECT to RECT in field header
// 
//    Rev 1.6   04 Oct 1995 13:23:48   pjm
// Kept hlint members as ints.
// 
//    Rev 1.5   04 Oct 1995 13:02:36   pjm
// Make htI1 and 2 shorts so they fit in the union.  Move hprev out
// of the union.
// 
//    Rev 1.4   25 Jul 1995 09:50:32   mjs
// Moved vars and fns to rrdoc/rrview.
// 
//    Rev 1.3   14 Jun 1995 14:16:42   mjs
// 6.5 changes (moved some protos from _wfield.h)
// 
//    Rev 1.2   03 Apr 1995 15:50:56   mjs
// New prototypes for image library fucntions.
// 
//    Rev 1.1   23 Mar 1995 07:53:04   sbc
// Convert text editing
// 
//    Rev 1.0   16 Mar 1995 16:13:58   sbc
// Initial revision.
// 
//    Rev 1.2   20 Jan 1995 16:02:08   mjs
// Added names to typedefs so C++ doesn't warn about them.
// 
//    Rev 1.1   19 Nov 1993 17:40:42   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:10:50   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _WFIELD_H_

//
// Make a definition for this module.
//
#define _WFIELD_H_

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

//
// from wbitbap.h - bitmap parameters
//
/* bitmap scaling values */
#define PARTSCALE	0
#define NOSCALE		1
#define FULLSCALE	2

// Stretch handle locations.
#define H_LEFT		0x1
#define H_RIGHT		0x2
#define H_TOP		0x4
#define H_BOTTOM	0x8
#define H_ALL		0x10

#define XMIN		9	  // minimum width of image
#define YMIN		9	  // minimum height of image
#define HSZ			6	  // size of handles.

#define IMG_SUCCESS 0	// Image library currently returns 0 for success.

// Colors for gray box indicating a selected field.
#define RGB_LIGHTGRAY RGB(192,192,192)
#define RGB_DARKGRAY  RGB(128,128,128)

//
// Structure Section:
// Place in this section any structure definitions.
//
//
// hlchar should stay wiht fieldhdr since it is only used to
// define fieldhdr.
//
typedef struct hlchar	// break down htempI in union
{
	char	htL;	 			// low char
	char	htH;	 			// high char
	char	htL1;	 			// low char
	char	htH1;	 			// high char
} HLCHAR;
 
//
// hlint should stay with fieldhdr since it is only used to define fieldhdr.
//
typedef struct hlint	// break down htempI in union
{
	int		htI1;	 			// low int
	int		htI2;	 			// high int
} HLINT;

typedef struct fieldhdr		/* text and data field header info */
{
	char	hrow;			/* field row */
	unsigned hcol;			/* field column */	
	char	hlen;			/* field length (with picture applied) */
	char	hatt;			/* field attribute */
	unsigned hflags;			/* data/text flags */
	unsigned int hpoints;	/* point size for scalable font */
	unsigned int hin_cm;	/* width in inches/centimeters */
	unsigned int descent;	/* descender height */
	unsigned int hfont;		/* new font number location */
	RECT	fr;				/* field rectangle */
	unsigned int hite;		/* field height (screen resolution) */
	HFONT fldFont;			/* field font handle */
	char colorInd;			// index into color table (16 colors)
	ATOM faceAtom;			// no more htempI for me, thanks...
	struct fieldhdr *hnext;	/* next field in screen order */
	struct fieldhdr *hprev;	/* previous field in screen order */
	union ht				/* use for temp, too */
	{
	  int htempI;			/* an int */
	  long htempL;			// a long
	  struct hlint hli;		/* two ints */
	  struct hlchar hl;		/* four chars */
	} hTemp;
} FLDHDR;

typedef FLDHDR * LPFLDHDR;

typedef struct txfield	// text field information
{
	struct	fieldhdr fhdr;		// field header structure
	struct	txfield *tnxf;		// point to next one
	char	txflags;			// text field flags
	LPSTR	tstr;				// pointer to text
} TXFLD;

typedef TXFLD * LPTXFLD;

typedef struct twodhdr	// report writer bitmap structure
{
	char	align;				// alignment
	char	source;				// 1 = from clipboard
	UINT	xinch;				// width in inches
	UINT	yinch;				// height in inches
} TWODHDR;

typedef TWODHDR *LPTWODHDR;


typedef struct rrimage	// report writer bitmap structure
{
	struct	fieldhdr fhdr;			// field header structure
	struct	twodhdr thdr;			// 2D field common stuff
	FLDID	fid;					// field id, if from field
	int		hDib;					// handle to DIB (zero-based)
	RECT	cropRect;				// cropping rectangle 
	char	filename[WINPATHLEN+1];	// pathname
	WORD	scaling;				// scaling (0, 1, or 2)	
	HBITMAP	hDdb;					// handle to DDB (zero-based)
	int		hDibX;					// handle to blank DIB
	RECT	cropRectX ;				// another one for fields
} RRIMAGE;

typedef RRIMAGE *LPRRIMAGE;

typedef struct rrbox	// report writer line/box structure
{
	struct	fieldhdr fhdr;			// field header structure
	struct	twodhdr thdr;		 	// 2D field common stuff
	WORD	sides;					// sides to display
	char	thickness;				// line thickness (1,2,4,6, or 8 pixels)
	char	hatch;					// shading (hatch brush value or 0xFF if no hatch)
									// color values are indexes into ColorTable
	char	style ;					// pen style (lines)
	char	bordColor;				// border color
	char	foreColor;				// hatch color
	char	backColor;				// box background color
	char	endrow;					// ending row of line/box
	WORD	startY;					// starting print position
} RRBOX;

typedef RRBOX *LPRRBOX;


//
// Global Data Section:
// Place in this section any global data.
//

#ifdef _WBITMAP_C_
#define GLOBAL
#else
#define GLOBAL extern
#endif






#undef GLOBAL
//
// Function Prototypes Section:
// Place in this section any function prototypes
//

// image functions


// Utility routines.
extern BOOL isHorzLine(POINT org, POINT newp);

#endif // end _WFIELD_H_

// *************************** End of File ************************************
