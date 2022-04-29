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
// $Log:   D:/R&R Project/archives/H/PD.H_V  $
// 
//    Rev 1.39   Oct 03 2003 14:11:08   Admin
// Add crop rectangle to image structure
// 
//    Rev 1.38   Apr 25 2002 10:13:20   Admin
// Add style to box structure
// 
//    Rev 1.37   Feb 27 2001 15:35:36   nhubacker
// Bursting changes
// 
//    Rev 1.35   16 Jan 1998 15:38:44   JSF
// PTF20001 merge
// 
//    Rev 1.34.1.0   23 Oct 1997 14:29:38   jsf
// charting PTF 1
// 
//    Rev 1.34   14 May 1997 14:04:24   SRM
// remove unused chart function passing from exe to dll
// 
//    Rev 1.33   07 May 1997 17:56:38   SRM
// include rrchart.h
// 
//    Rev 1.32   06 May 1997 11:33:14   SRM
// define slot for chart metafile in prt_chart
// 
//    Rev 1.31   05 May 1997 15:13:10   par
// Removed A L I V E (spacing prevents search hits) and PDI _ EXPORT conditionals.
// From this point forward, this code will always be included in build.
// 
// 
//    Rev 1.30   30 Apr 1997 16:14:38   SRM
// change pointer in prt_chart to chart, not ole item
// 
//    Rev 1.29   14 Mar 1997 15:53:42   SRM
// chart support initial checkin
// 
//    Rev 1.28   24 Feb 1997 16:58:04   hxc
// Change pageByteCount to DWORD to fix RRW 2892 "Insufficient Memory
// for print/preview" problem. Got some mistakes in rev 1.25, 1.26, 1.27
// so removed them.
// 
//    Rev 1.24   19 Feb 1997 14:57:02   dlm
// Part of fix to RRW 2991/RSW 2386 to allow specification via SPACEDOT
//  setting in .SRT file of override for hard-space character.  Changed much
//  code to use new SpaceDot variable instead of zdSPC or ANSI_DOT.  Changed
//  most export/printer DLLs to use a new internal SpaceDot function instead
//  of exported pwSpaceDot.  Change EXEs to use new CRrDoc::SpaceDot function
//  instead of using exported pwSpaceDot functions of DLLs.  Modules changed
//  are: explt.cpp, token.cpp, fstr.cpp, trim.cpp, pksx.cpp, sxmisc.cpp,
//  mfgetmch.cpp, mfsql.cpp, htmlexp.cpp, pwint.cpp, pxdriver.cpp, pxint.cpp,
//  rtfexp.cpp, wexpdriv.cpp, wexpint.cpp, pwdriver.cpp, picdata.cpp,
//  picshape.cpp, prec.cpp, rpwrap.cpp, rprint.cpp, gropts.cpp, grfield.cpp,
//  rpwritex.cpp, grmisc.cpp, rrcompos.cpp, rrdoc.cpp, rrrepio.cpp,
//  specfld1.cpp, specfld2.cpp, specquer.cpp, wedtx.cpp, edittext.cpp,
//  wfont.cpp, readsrt.cpp, wprint.cpp, wtxtexp.cpp, winst.cpp, wstring.cpp,
//  global.h, pd.h, rrcompos.h, rrdoc.h, rrrepio.h, _pd.h, _rtexp.h
// 
//    Rev 1.23   10 Feb 1997 10:02:20   sp
// Arp Live merge to trunk
// 
//    Rev 1.21.1.6   02 Jan 1997 15:54:12   smh
// Removed conditionals in image structure so we don't have
// 
// different size structures floating around.
// 
//    Rev 1.21.1.5   13 Dec 1996 09:10:48   smh
// Added getAPIVersion prototype
// 
//    Rev 1.21.1.4   12 Dec 1996 18:06:20   smh
// moved pTypeFaces to end of structure to not break API.
// 
//    Rev 1.21.1.3   03 Dec 1996 11:20:28   smh
// Add typeface structure and pointer for PDI export
// 
//    Rev 1.21.1.2   30 Nov 1996 16:11:34   smh
// No longer have pd structure within html structure
// Also no longer require a printer for html export
// 
//    Rev 1.21.1.1   04 Nov 1996 15:48:22   smh
// Records across.
// 
//    Rev 1.21.1.0   18 Oct 1996 12:33:08   smh
// PDI export implementation
// 
//    Rev 1.20.1.2   26 Sep 1996 12:00:06   sjo
// Added html export structure pointer.
// 
//    Rev 1.20.1.1   31 Jul 1996 08:49:36   sjo
// Fixed a compile problem.
// 
//    Rev 1.20.1.0   30 Jul 1996 16:50:52   sjo
// This is the first round of HTML export changes.  On the U02 branch I am
// putting the code in A L I V E conditionals so that we develop the code on the
// U02 branch but not effect the build of that product.
// 
//    Rev 1.20   28 May 1996 13:45:54   pjm
// Define rtfNS for "new section" flag for RTF export.
// 
//    Rev 1.19   08 Apr 1996 10:50:54   pjm
// Define RTF status bits in pStat flags word.
// 
//    Rev 1.18   31 Jan 1996 11:22:42   par
// Fix OLE printing problem.  Cropping was fixed and text align was fixed.
// 
//    Rev 1.17   30 Nov 1995 15:05:24   sbc
// Add bFastPrint and nMinMemKB to printer driver structure and set them
// in EXE.  This change replaces conditional code in printer driver.
// 
//    Rev 1.16   14 Nov 1995 07:33:50   smh
// HFILE->HANDLE for new Win32 file i/o.
// 
//    Rev 1.15   06 Nov 1995 10:13:30   par
// Ifdef out the printOleObject stuff so that the Text Export DLL can be kept
// as a "C" DLL.
// 
//    Rev 1.14   31 Oct 1995 12:00:40   par
// Add the support functions for creating ole object print records.  Also added
// the support to print the ole object records inside the printer driver.
// 
//    Rev 1.13   06 Oct 1995 09:56:56   sbc
// Add define for paper name size, which s/b in some windows header
// 
//    Rev 1.12   04 Oct 1995 12:31:04   sbc
// Change WORDs to ints in PRTSTRUCT
// 
//    Rev 1.11   21 Sep 1995 11:22:52   smh
// 32-bit export DLLs.
// 
//    Rev 1.10   29 Aug 1995 13:23:38   mjs
// Win32 fixes.
// 
//    Rev 1.9   22 Aug 1995 14:48:18   sbc
// Fix API ordinal
// 
//    Rev 1.8   22 Aug 1995 12:20:14   mjs
// Sync'd up DLL function ordinals with DEF file.
// 
//    Rev 1.7   31 Jul 1995 10:58:28   sbc
// Add includes now required by rtf structure
// 
//    Rev 1.6   19 Jul 1995 11:49:42   sbc
// Restore PWPLAYBACKPAGE
// 
//    Rev 1.5   18 Jul 1995 13:47:28   sbc
// Change BOOL to int in typedef.
// 
//    Rev 1.4   18 Jul 1995 11:45:48   smh
// Merged some RTF and other changes from 6.5 that I ran across.
// 
//    Rev 1.3   11 Jul 1995 13:31:04   sbc
// Changing typedef of BOOL to int fixes weird compile errors.
// 
//    Rev 1.2   25 Apr 1995 13:36:18   sbc
// 6.1.03 -> 7.0.01 merge
// 
//    Rev 1.1   27 Mar 1995 13:25:48   mjs
// Replaced include of wlayout.h with prtinit.h
// 
//    Rev 1.0   16 Mar 1995 16:13:06   sbc
// Initial revision.
// 
//    Rev 1.15   21 Feb 1995 12:42:44   sbc
// Add New pwRecordLineSeg routine
// 
//    Rev 1.14   15 Nov 1994 15:52:24   sbc
// New member of printer structure (overprint boolean)
// 
//    Rev 1.13   02 Nov 1994 11:56:06   sbc
// Rename structure member
// 
//    Rev 1.12   25 Oct 1994 12:52:38   smh
// Added members to text export structure for better friends-of-
// word-wrapped memo support (RRW 1319).
// 
//    Rev 1.11   14 Sep 1994 10:01:06   sbc
// Change for Cancel in Print Current Page dialog (preview)
// 
//    Rev 1.10   13 Sep 1994 11:22:26   sbc
// Arg changes
// 
//    Rev 1.9   12 Sep 1994 15:14:28   mjs
// Save both screen and printer rgb values in PRT_BOX struct.
// 
//    Rev 1.8   01 Aug 1994 14:42:20   sbc
// Remove threeOne structure member
// 
//    Rev 1.7   20 Jul 1994 11:47:26   sbc
// New API call
// 
//    Rev 1.6   08 Jun 1994 14:57:06   erp
// changed __far to far, so it will build for 32-bits
// 
//    Rev 1.5   17 May 1994 11:27:38   sbc
// Preview window restore changes
// 
//    Rev 1.4   29 Dec 1993 13:34:38   smh
// Database export:  See Scott for complete list of files.
// 
//    Rev 1.3   14 Dec 1993 09:12:50   sbc
// Change pwDotWidth() arguments for inches
// 
//    Rev 1.2   19 Nov 1993 17:44:38   sbc
// Add extern C for C++
// 
//    Rev 1.1   21 Oct 1993 17:09:56   smh
// Add argument to pwEndBand() prototype.
// 
//    Rev 1.0   14 Oct 1993 10:11:16   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _PD_H_

//
// Make a definition for this module.
//
#define _PD_H_

#include "prtinit.h"
#include "dbexport.h"	/* The windows database export header.
							This is the only place it's included. */
// these are required for RTF stuff
#include "mffield.h"
#include "wfield.h"
#include "rrchart.h"	// for prt_chart stuff

class  CGenerateReportHTML;

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
#define WRR_CHARSET			100		// small font value
#define VTRES			720		/* R&R internal vertical resolution */

/*** imbedded code definitions ***/
#define PDI_START		27		/* generic start value */
#define PDI_STARTSZ		4		/* 4 bytes long */
#define PDI_ENDSZ		2		/* 2 bytes long */
#define PDI_FONTSZ		8		/* font code with attr & points is 8 bytes */
#define PDI_ENDCENTSZ	6		/* center end size */
#define PDI_ENDRITESZ	4		/* right-align end size */
#define PDI_COLORSZ		8		/* color value is 8 bytes */
#define PDI_BOLSZ		12		// two-byte BOL
#define PDI_EOLSZ		4		// two-byte band # + two-byte EOL

	/* secondary codes */
#define PDI_POS			1			/* column position */
#define PDI_FONT		3			/* start print font */
#define PDI_FULLJUST	4			/* start full justify */
#define PDI_RITEJUST	5			/* start right justify */
#define PDI_CENTER		6			/* start center */
#define PDI_ENDCENT		7			/* end center */
#define PDI_ENDRITE		8			/* end right justify */
#define PDI_IMAGE		9			/* a bitmap image */
#define PDI_YPOS		10			/* free-form field delta */
#define PDI_BOX			11			/* a box */
#define PDI_COLOR		12			// rgb value
#define PDI_BOL			13			// ascender value
#define PDI_EOL			14			// descender value
#define PDI_BAND		15			// current band level
#define PDI_SNAKE		16			// paint both edges (1 col), left or right edge (2 cols), or not at all (> 2 cols)
// export ordinals (keep in synch with RRWPD.DEF and RRRTFX.DEF)
// mjs 8/22/95  Sync up with R?WPD.DEF

#define PWFINDATT			1
#define PWFONTHEIGHT		2
#define PWCHARWIDTH			3
#define PWDOTWIDTH			4
#define PWBOL				5
#define PWEOL				6
#define PWFF				7
#define PWLINEHEIGHT		8
#define PWINIT				9
#define PWPAGEROOM			10
#define PWRESET				11
#define PWTOPMARGIN			12
#define PWVERTICAL			13
#define PWRECORDLINE		14
#define PWRESETDRIVER		15
#define PWSPACEDOT			16
#define PWSETPALETTE		17
#define PWENDBAND			18
#define PWRECORDBOX			19
#define PWRECORDIMAGE		20
#define PWCLEARFONTCACHE	21
#define PWVERTLOC			22
#define PWRECORDLINESEG		23
#define PWPLAYBACKPAGE		24
#define PWNEXTPREVPAGE		25
#define PWIMGFUNCS			26
#define PWRECORDOLEOBJECT	27
#define GETAPIVERSION		28
#define PWRECORDCHART		29

// Export flags  :from wexport.h
#define CSANSI		0x01		// set = character set ANSI (as opposed to OEM)
#define CRONCE		0x02		// set = carriage rets 1 per band (not every line)

#define zdSPC	183		/* space dot */

// define this value, which is nowhere to be found in Windows headers
#define CCHPAPERNAME	64	// 64 in Win32 documentation

//
// Structure Section:
// Place in this section any structure definitions.
//
typedef struct printBox		// print-time box structure
{
	WORD printXL;	// left edge for printer
	WORD printXR;	// right edge
	WORD printYT;	// top edge
	WORD printYB;	// bottom edge
	WORD thickness;
	WORD hatch;
	WORD sides;
	WORD style ;
	COLORREF rgbBord;	// border color
	COLORREF rgbFore;	// foreground
	COLORREF rgbBack;	// background
	COLORREF rgbPrevBord;	// border color for Preview
	COLORREF rgbPrevFore;	// foreground for Preview
	COLORREF rgbPrevBack;	// background for Preview
	WORD	align;		// alignment (for thick vertical lines)
	DWORD	filler[6];		// MAKE SURE STRUCTURE SIZE IS POWER OF 2
								// see Steve or Dave for explanation of above comment.
} PRT_BOX;

typedef PRT_BOX far *LPPRT_BOX;

typedef struct printImage	// print-time image structure
{
	int		hDib;			// handle
	WORD	x;				// horizontal position
	WORD	y;				// vertical position
	WORD	wid;			// width
	WORD	hite;			// height
	WORD	wCropWidth;		// cropping width
	WORD	wCropHeight;	// cropping height
	LPSTR	pFilename;		// image filename (for PDI Export)
	RECT	CropRectangle;	// the friggin' crop rectangle
} PRT_IMG;

typedef PRT_IMG far *LPPRT_IMG;

typedef struct	// preview page buffer
{
	// WORD pageByteCount;		// number of bytes in line buffer
	// Change to DWORD to solve "insufficient memory for print/preview"
	// problem (RRW 2892). HXC 2/18/97
	DWORD pageByteCount;		// number of bytes in line buffer
	GLOBALHANDLE hLineData; // long string of page data
	int pageBoxes;			// number of boxes
	GLOBALHANDLE hBoxArray;	// array of box structures
	int pageLines;			// number of boxes
	GLOBALHANDLE hLineArray;	// array of box structures
	int pageImages;			// number of images
	GLOBALHANDLE hImgArray;	// array of image structures
	int pageOleObjects;		// number of objects
	GLOBALHANDLE hOleObjectArray;	// array of object structures
	int pageCharts;			// number of charts
	GLOBALHANDLE hChartArray;	// array of chart structures
} PRT_PAGE;

typedef struct memfont
{
	HDC fdc;		// device context
	WORD zoom;		// zoom level
	WORD font;		// font number
	char att;		// attribute value
	WORD pts;		// point size
	HFONT handle;	// font handle
	WORD avgChWid;	// average character width
} MFONT;

typedef struct zoomSize
{
	int pvBottom;		// bottom of "screen page"
	int pvRight;		// right edge of "screen page"
	int pvX;			// current x location on screen page
	int pvY;			// current y location on screen page
} PREV_ZOOM;

// Typeface storage for PDI export w/o printer
typedef struct faces
{
	TCHAR FaceName[LF_FACESIZE + 1];
} TYPEFACE;

typedef struct expstruct
{
	int			AnsiSpaceDot;		// user-settable ANSI space dot char
	int			CharSet;			// character set: ANSI_DOT or OEM_DOT
	int			ExpType;			// export type (txt/dbf/wks/rtf)
	int 			numPrtFaces;	// # typefaces for current printer
	int 			rulpitch; 		// ruler pitch
	int			SDChar;			// current space dot character
	int			insert;			// inserting into line/page buffer
	UINT			inspos;			// insert position
	UINT			lastPos;			// last horizontal positioning column
	UINT			horizPos;		// current column (DOS PD_HzColumn)
	UINT			leftMarg;		// left margin col # (DOS PD_LeftCols)
	UINT			lineCnt;			// line buffer count (DOS PD_LBufCt)
	UINT			pageCnt;			// page buffer count (DOS VPCnt++)
	HGLOBAL		lineBuf;			// line buffer (DOS PD_LBuf)
	HGLOBAL		pageBuf;			// page buffer (DOS PrintBuf)
	HANDLE		prtFileHandle;	// print-to-file handle
	LPPRT_FACE	prtFonts;		// pointer to printer font array
	BOOL			CarRetOnce;		// carriage rets: TRUE=1/band, FALSE=every line
	WORD 			curFont;			// current font
	WORD 			inchX;			// display resolution: x
	WORD			pageLen;			// page length
	WORD			pgVPos;			// current line (DOS PD_VtLoc) (Win yPos)
	// char huge *		pline; 			// line pointer	// huge is obsolete
	char 			lineDraw[LF_FACESIZE+1];// our line draw typeface
	char 			*pline; 			// line pointer
	int				when;			// current band
	int				bBurstReport;
} EXP_STRUCT;

// values for placecolor member in wpdstruct, below
#define BANDCOLOR_LEFT_RIGHT	1 // 1 col - paint both edges
#define BANDCOLOR_NONE			2 // too many cols - don't paint at all
#define BANDCOLOR_LEFT			3 // first of 2 cols - left edge
#define BANDCOLOR_RIGHT			4 // second of 2 cols - right edge

typedef struct wpdstruct
{
	int			AnsiSpaceDot;		// user-settable ANSI space dot char
	BOOL bCancelled;		// TRUE -> preview print-this-page aborted
	BOOL bFastPrint;		// lets printer driver do scaling, dithering, etc.
	BOOL bOverPrint;		// controls overprinting of data/text fields
	BOOL bNoPageOutput;		// size of fixed-pitch font at full page view
	BOOL bTryingToPause;	// flag to indicate that we are trying to pause
	int courier;			// index of raster Courier font
	int courierNew;			// index of TrueType Courier font
	int curAtt;			// current attribute
	HDC curDev;				// current device
	int curFont;			// current font
	int curPage;			// current page (zero-based)
	int curPts;			// current point size
	BOOL findLastPage;		// we're chuggin' toward last page
	int firstPage;			// real first page if pages are freed
	int graphicsInchX;		// graphics x resolution of printer	(e.g. 150 dpi)
	int graphicsInchY;		// graphics y resolution of printer
	HWND hCancelDialog;		// handle of cancel dialog for image peek
	GLOBALHANDLE hMemFont;	// handle to preview font cache
	LOCALHANDLE hPageBuf;	// page buffer handle
	HINSTANCE hResource;	// R&R resource DLL
	int inchX;				// display resolution: x
	int inchY;				// display resolution: y
	int leftMar;			// left margin
	char lineDraw[LF_FACESIZE+1];	// our line draw typeface
	int memPages;			// number of pages buffered
	int mFonts;				// number of memory fonts
	int nMinMemKB;			// 
	int numPrtFaces;		// number of typefaces for current printer
	int pageLen;			// page length
	// char huge *pline;		// line pointer  // huge is obsolete
	char *pline;		// line pointer
	POINT pOffset;			// page offsets
	HDC prevDC;				// preview display context
	BOOL preview;			// previewing
	int prevLeftMar;		// left indent (including prevRect.left)
	RECT prevRect;			// current preview "page" rectangle
	int prevRightMar;		// right unprintable
	HWND prevWnd;			// preview window handle
	int printerInchX;		// printer resolution: x
	int printerInchY;		// printer resolution: y
	HDC printDC;			// printer device context
	LPPRT_FACE prtFonts;	// pointer to printer font array
	POINT pSize;			// page size
	RECT pvPageRect;		// the maximum area to invalidate
	BOOL pvRecord;			// in record mode
	BOOL pvWait;			// waiting @ end of page
	int pvZoom;			// zoom mode
	int rulpitch;			// ruler pitch
	int unTop;				// unprintable top
	HBRUSH winBrush;		// Windows background color
	int yPos;				// current vertical position on page
	struct zoomSize zoomDeep;	// zoom structures (defined above)
	struct zoomSize zoomFit;
	struct zoomSize zoomFull;	// full page
	struct zoomSize far *zoomS;	// active zoom level
	TYPEFACE * pTypeFaces;		// typeface list (PDI export)
	int when;                   // current band
	int placecolor;
} WPD_STRUCT;

typedef struct rtfstruct	// RTF needs WPD and RTF stuff
{
	UINT		StructureVersion;	// Keeping (and checking) the structure version allows us 
									// to maintain backward compatibility in the DLL.  
									//
									// Used to have wpd in here.  Now just wpd members that
									// need in RTF export are duplicated in rtfstruct.
									// This way don't have strange organization where
									// wpd is both a union choice and a member of other
									// union choices.  Also, don't have to worry about
									// wpd structure changes changing the RTF export API.

// put the RTF export structure stuff after the wpd structure
//	WPD_STRUCT wpd;		// Now including specific members in rtf struct instead
	// now RTF stuff
	int			AnsiSpaceDot;		// user-settable ANSI space dot char
	UINT 		band;			 	// current report band
	BOOL		bFirstHeader;	// TRUE if first page header
	int			botMarg;
		int courier;			// index of raster Courier font
		int courierNew;			// index of TrueType Courier font
		int curAtt;			// current attribute
		HDC curDev;				// current device
		int curFont;			// current font
		int curPage;			// current page (zero-based)
		int curPts;			// current point size
	char 		defFontName[LF_FACESIZE + 1];	// default font typeface
	WORD		defPointSize;		// default point size
	int			ExpType;			// export type (txt/dbf/wks/rtf)
	char 		filename[WINPATHLEN+1];	// export file name
	LPMFFIELD 	FirstFld;		// our copy of MFFields
	LPTXFLD		FirstTxFld;		// our copy of TXFields
	UINT		horizPos;		// current column (DOS PD_HzColumn)
		GLOBALHANDLE hMemFont;	// handle to preview font cache
		LOCALHANDLE hPageBuf;	// page buffer handle
	BOOL		hStat;			// TRUE if RTF header has been written
		int inchX;				// display resolution: x
		int leftMar;			// left margin
	int			leftMarg;		// left margin setting
	HGLOBAL		lineBuf;			// line buffer (DOS PD_LBuf)
	UINT		lineCnt;			// line buffer count (DOS PD_LBufCt)
		int memPages;			// number of pages buffered
		int mFonts;				// number of memory fonts
		int numPrtFaces;		// number of typefaces for current printer
	UINT		oband;  			// previous report band
	int 		orient;			// orientation
	HGLOBAL		pageBuf;			// page buffer (DOS PrintBuf)
	UINT 		pageCnt;			// page buffer count (DOS VPCnt++)
		int pageLen;			// page length
		char *pline;		// line pointer
		POINT pOffset;			// page offsets
		HDC prevDC;				// preview display context
		BOOL preview;			// previewing
		RECT prevRect;			// current preview "page" rectangle
		HDC printDC;			// printer device context
		int printerInchX;		// printer resolution: x
		int printerInchY;		// printer resolution: y
	HANDLE		prtFileHandle;	// print-to-file handle
		LPPRT_FACE prtFonts;	// pointer to printer font array
		POINT pSize;			// page size
	WORD		pStat;			// flags word
		BOOL pvRecord;			// in record mode
		int pvZoom;			// zoom mode
	int			rightMarg;
		int rulpitch;			// ruler pitch
	int			topMarg;	
		int unTop;				// unprintable top
		int yPos;				// current vertical position on page
		struct zoomSize zoomDeep;	// zoom structures (defined above)
		struct zoomSize zoomFit;
		struct zoomSize zoomFull;	// full page
		struct zoomSize far *zoomS;	// active zoom level
	int				when;			// current band
	int				bBurstReport;
} RTF_STRUCT;

		// IF ADD NEW STRUCTURE MEMBERS, PUT THEM AT THE END SO CAN MAINTAIN 
		// BACKWARD COMPATIBILITY IN THE DLL

typedef struct htmlstruct
{ 
	UINT			StructureVersion;	// Keeping (and checking) the structure version allows us 
										// to maintain backward compatibility in the DLL.  
										//
										// Used to have wpd in here.  Now just wpd members that
										// need in HTML export are duplicated in htmlstruct.
										// This way don't have strange organization where
										// wpd is both a union choice and a member of other
										// union choices.  Also, don't have to worry about
										// wpd structure changes changing the HTML export API.

	int			AnsiSpaceDot;		// user-settable ANSI space dot char
	GLOBALHANDLE	hMemFont;		// handle to preview font cache
	int 			mFonts;				// number of memory fonts
	int 			numPrtFaces;		// number of typefaces for current printer
	int 			pageLen;				// page length
	char 			*pline;				// line pointer
	int 			printerInchX;		// printer resolution: x
	int 			printerInchY;		// printer resolution: y
	HDC 			printDC;				// printer device context
	LPPRT_FACE 	prtFonts;			// pointer to printer font array
	int 			unTop;				// unprintable top
	int 			yPos;					// current vertical position on page
	HINSTANCE 	hResource;			// resource DLL
	UINT 			band;					// current report band
	BOOL			bFirstHeader;		// TRUE if first page header
	int			botMarg;
	char 			defFontName[LF_FACESIZE + 1];	// default font typeface
	WORD 			defPointSize;		// default point size
	int			ExpType;				// export type (txt/dbf/wks/rtf)
	char 			filename[WINPATHLEN+1];	// export file name
	LPMFFIELD 	FirstFld;			// our copy of MFFields
	LPTXFLD		FirstTxFld;			// our copy of TXFields
	UINT			horizPos;			// current column (DOS PD_HzColumn)
	BOOL			hStat;				// TRUE if HTML/RTF header has been written
	int			leftMarg;			// left margin setting
	HGLOBAL		lineBuf;				// line buffer (DOS PD_LBuf)
	UINT			lineCnt;				// line buffer count (DOS PD_LBufCt)
	UINT			oband;  				// previous report band
	int 			orient;				// orientation
	HGLOBAL		pageBuf;				// page buffer (DOS PrintBuf)
	UINT 			pageCnt;				// page buffer count (DOS VPCnt++)
	HANDLE		prtFileHandle;		// print-to-file handle
	WORD			pStat;				// flags word
	int			rightMarg;
	int			topMarg;
	int			recsacross;			// records across
	int			recwidth;			// record width (in pix)
	LPCTSTR		lpszTitle;			// The title of the HTML page.	
	CGenerateReportHTML	*pReportHTMLgenerator ;
	int			iNumberOfTableCells;
	CObList		*pBodyBandTableList ;
	int			iBandNumber ;
	HTML_EXPORT	*pHtmlExport;
	int				when;			// current band
	int				bBurstReport;
} HTML_STRUCT;

#define htmlINIT	1		// indicates "real" printer init for html
#define htmlNS		2		// start new section if more data comes

#define rtfINIT	1		// indicates "real" printer init
#define rtfNS		2		// start new section if more data comes

typedef struct prtstruct
{	union
	{	WPD_STRUCT  wpd;
		EXP_STRUCT  exp;
		RTF_STRUCT  rtf;
		HTML_STRUCT html;
	} pDest;	
} PRT_STRUCT;

typedef PRT_STRUCT far *LPPRT_STRUCT;

#ifdef __cplusplus
typedef struct printOleObject	// print-time ole object structure
{
	COleClientItem* pItem ;  // (4)handle
	WORD  x                ;  // (2)horizontal position
	WORD  y                ;  // (2)vertical position
	WORD  wWidth           ;  // (2)width
	WORD  wHeight          ;  // (2)height
	WORD  wScaling         ;  // (2)Scaling
	SIZE  sizeActual       ;  // (8)Actual size
	SIZE  sizeCrop         ;  // (8)Crop size
	short nAspect          ;  // (2)Aspect
} PRT_OBJECT ;  // MAKE SURE STRUCTURE SIZE IF POWER OF 2

typedef PRT_OBJECT far *LPPRT_OBJECT;


typedef struct printChart	// print-time chart structure
{
	LPRRCHART pItem ;  // (4)handle
	WORD  x                ;  // (2)horizontal position
	WORD  y                ;  // (2)vertical position
	WORD  wWidth           ;  // (2)width
	WORD  wHeight          ;  // (2)height
	SIZE  sizeActual       ;  // (8)Actual size
	SIZE  sizeCrop         ;  // (8)Crop size
	HENHMETAFILE hmf	   ;  // (4)handle for chart's metafile
} PRT_CHART ;  // MAKE SURE STRUCTURE SIZE IS POWER OF 2 (copied from object code --
				// unsure of importance)

typedef PRT_CHART far *LPPRT_CHART;
#endif

//
// Global Data Section:
// Place in this section any global data.
//




//
// Function Prototypes Section:
// Place in this section any function prototypes
//


// declare as C routines
#ifdef __cplusplus
extern "C"
{
#endif


/***  routine typedefs ***/

typedef int (WINAPI * LPFNGETAPIVERSION)();
typedef	int (WINAPI* LPFNPWBOL)(LPPRT_STRUCT,UINT,int);
typedef	unsigned long (WINAPI* LPFNPWCHARWIDTH)(LPPRT_STRUCT,char,UINT,UINT,UINT);
typedef	unsigned long (WINAPI* LPFNPWDOTWIDTH)(LPPRT_STRUCT,WORD);
typedef	void (WINAPI* LPFNPWDRAWBOX)(LPPRT_STRUCT,UINT,int,int,int,int);
typedef	int (WINAPI* LPFNPWENDBAND)(LPPRT_STRUCT,UINT,int);
typedef	void (WINAPI* LPFNPWEOL)(LPPRT_STRUCT,WORD,int);
typedef	int (WINAPI* LPFNPWFF)(LPPRT_STRUCT,int);
typedef	int (WINAPI* LPFNPWFINDATT)(LPPRT_STRUCT,unsigned int,int far *);
typedef	UINT (WINAPI* LPFNPWFONTHEIGHT)(LPPRT_STRUCT,int,int,int,int);
typedef	int (WINAPI* LPFNPWINIT)(LPPRT_STRUCT,struct prt_init far *,const char far *,const char far *,const char far *);
typedef	unsigned long (WINAPI* LPFNPWLINEHEIGHT)(LPPRT_STRUCT,const char far *,int,int);
typedef	int (WINAPI* LPFNPWNEXTPREVPAGE)(LPPRT_STRUCT, HWND, int);
typedef UINT (WINAPI* LPFNPWPAGEROOM)(LPPRT_STRUCT,UINT /*WORD*/);
typedef	int (WINAPI* LPFNPWPAINTPREV)(LPPRT_STRUCT,unsigned int, LPRECT updateRegion);
typedef	void (WINAPI* LPFNPWPREVPAGENO)(LPPRT_STRUCT,unsigned int,unsigned char far *,unsigned int);
typedef	int (WINAPI* LPFNPWPRINTPAGE)(LPPRT_STRUCT,unsigned char far *);
typedef	int (WINAPI* LPFNPWRECORDBOX)(LPPRT_STRUCT,LPPRT_BOX);
typedef	int (WINAPI* LPFNPWRECORDIMAGE)(LPPRT_STRUCT,LPPRT_IMG);
#ifdef __cplusplus
typedef	int (WINAPI* LPFNPWRECORDOLEOBJECT)(LPPRT_STRUCT,LPPRT_OBJECT);
typedef	int (WINAPI* LPFNPWRECORDCHART)(LPPRT_STRUCT,LPPRT_CHART);
#endif
typedef	int (WINAPI* LPFNPWRECORDLINE)(LPPRT_STRUCT,char far *,int);
typedef	void (WINAPI* LPFNPWRECTLINE)(UINT,int,int,int,int);
typedef	int (WINAPI* LPFNPWRESET)(LPPRT_STRUCT,int);
typedef	void (WINAPI* LPFNPWRESETDRIVER)(LPPRT_STRUCT);
typedef	void (WINAPI* LPFNPWSCROLLPREV)(LPPRT_STRUCT,unsigned int,unsigned int,int,int);
typedef	void (WINAPI* LPFNPWSETPALETTE)(int);
typedef	WORD (WINAPI* LPFNPWSPACEDOT)(struct prt_face far *,char far *,int,int);
typedef	int (WINAPI* LPFNPWTOPMARGIN)(LPPRT_STRUCT,UINT,int);
typedef	int (WINAPI* LPFNPWVERTICAL)(LPPRT_STRUCT,UINT,int);
typedef	void (WINAPI* LPFNPWCLEARFONTCACHE)(LPPRT_STRUCT);
typedef	WORD (WINAPI* LPFNPWVERTLOC)(LPPRT_STRUCT);
typedef	int (WINAPI* LPFNPWRECORDLINESEG)(LPPRT_STRUCT, LPPRT_BOX);
typedef	int (WINAPI* LPFNRTFINIT)(LPPRT_STRUCT);
typedef int (WINAPI* LPFNPWPLAYBACKPAGE)(LPPRT_STRUCT, LPRECT);
#ifdef __cplusplus
}
#endif


#endif // end _PD_H_

// *************************** End of File ************************************

