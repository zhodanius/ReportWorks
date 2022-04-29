// ****************************************************************************
//
//      (C) Copyright 1996 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
// PDI Export Header
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/pdx.h_v  $
// 
//    Rev 1.6   22 May 1997 16:29:16   par
// Charts are now being displayed in the viewer control.
// 
//    Rev 1.5   21 May 1997 17:36:28   par
// Place chart in PDI stream.
// 
//    Rev 1.4   30 Apr 1997 16:12:54   amh
// No change.
// 
//    Rev 1.3   20 Mar 1997 11:06:26   smh
// Added OLE object support.
// 
//    Rev 1.2   10 Feb 1997 10:02:20   sp
// Arp Live merge to trunk
// 
//    Rev 1.0.1.0   31 Dec 1996 15:56:24   smh
// Defines moved from _pdx.h.  Add new defines for size count packets.
// 
//    Rev 1.0   18 Oct 1996 11:51:08   smh
// Report Viewer Control (PDI) Export header
// 
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _PDX_H_

// define stuff we absolutely need
#define FONT_SIZES		20 	// from product.h

//
// Make a definition for this module.
//
#define _PDX_H_

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

#define HZRES			720		// horizontal resolution
#define VTRES			720		// vertical resolution

#define PDI_START		27		// generic start value
// secondary codes 
#define PDI_POS			1		// column position 
#define PDI_FONT		3		// start print font 
#define PDI_FULLJUST	4		// start full justify 
#define PDI_RITEJUST	5		// start right justify 
#define PDI_CENTER		6		// start center 
#define PDI_ENDCENT		7		// end center 
#define PDI_ENDRITE		8		// end right justify 
#define PDI_IMAGE		9		// a bitmap image 
#define PDI_YPOS		10		// free-form field delta 
#define PDI_BOX			11		// a box 
#define PDI_COLOR		12		// rgb value
#define PDI_BOL			13		// ascender value
#define PDI_EOL			14		// descender value
// PDI export only
#define PDI_TEXT_CNT	50		// DWORD text count (bytes) follows
#define PDI_BOX_CNT		51		// DWORD box data count (bytes) follows
#define PDI_LINE_CNT	52		// DWORD line data count (bytes) follows
#define PDI_IMAGE_CNT	53		// DWORD image data count (bytes) follows
#define PDI_OBJ_CNT		54		// DWORD object data count (bytes) follows
#define PDI_CHART_CNT	55		// DWORD chart data count (bytes) follows

#define PDI_EOP			127		// end of page (new for PDI export)

// ** PDI Output File Header values
#define PDI_FILE_ID		126		// first byte of PDI file
#define PDI_VERSION		3		// version number

//
// Structure Section:
// Place in this section any structure definitions.
//

// PDI File Header - Note: structure member alignment must be set to one
typedef struct header
{
	char	cID;			// file identifier
	char	cVer;			// version #
	DWORD	dwPages;		// # pages
	WORD	wYear;			// current year
	char	cMonth;			//   "     month
	char	cDay;			//   "     day
	char	cHour;			//   "     hour
	char	cMinute;		//   "     minute
	WORD	wPaperWidth;	// paper width (inches * 720)
	WORD	wPaperHeight;	// paper height (inches * 720)
} FILE_HDR;

// page index appended to PDI export file
typedef struct exportPageIndexVer2
{
	DWORD	dwPagePos;			// file position
	DWORD	dwTextByteCount;	// text byte count
	WORD	wBoxCount;			// box count
	WORD	wLineCount;			// line count
	WORD	wImageCount;		// image count
} PAGE_POS2;

// page index appended to PDI export file
typedef struct exportPageIndex
{
	DWORD	dwPagePos;			// file position
	WORD	wBoxCount;			// box count
	WORD	wLineCount;			// line count
	WORD	wImageCount;		// image count
	WORD	wObjectCount;		// object count
	DWORD	dwTextByteCount;	// text byte count
	WORD	wChartCount;		// chart count
} PAGE_POS;

// line/box data structure
typedef struct exportLineBox
{
	WORD		wLeft;		// left edge
	WORD		wRight;		// right edge
	WORD		wTop;		// top edge
	WORD		wBottom;	// bottom edge
	WORD		wThick;		// thickness
	WORD		wHatch;		// hatch pattern
	WORD		wSides;		// sides to render
	WORD		wAlign;		// alignment
	COLORREF	rgbBord;	// border color
	COLORREF	rgbFore;	// foreground
	COLORREF	rgbBack;	// background
} LINE_BOX;

typedef struct exportImage	// pdi export image structure
{
	WORD wLeft;			// horizontal position
	WORD wBottom;		// vertical position
	WORD wWidth;		// image width
	WORD wHeight;		// image height
	WORD wCropWidth;	// cropping width
	WORD wCropHeight;	// cropping height
} EXPORT_IMAGE;

typedef struct exportObject	// pdi export object structure
{
	WORD  x;                // horizontal position
	WORD  y;                // vertical position
	WORD  wWidth;           // width
	WORD  wHeight;          // height
	WORD  wScaling;         // Scaling
	SIZE  sizeActual;       // Actual size
	SIZE  sizeCrop;         // Crop size
	short nAspect;          // Aspect
} EXPORT_OBJECT;

typedef struct exportChart	// pdi export chart structure
{
	WORD  x;                // horizontal position
	WORD  y;                // vertical position
	WORD  wWidth;           // width
	WORD  wHeight;          // height
	SIZE  sizeActual;       // Actual size
	SIZE  sizeCrop;         // Crop size
} EXPORT_CHART;

//
// Global Data Section:
// Place in this section any global data.
//

//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#endif // end _PDX_H_

// *************************** End of File ************************************
