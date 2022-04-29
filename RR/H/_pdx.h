// ****************************************************************************
//
//		(C) Copyright 1996 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
// PDI export header
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/_pdx.h_v  $
// 
//    Rev 1.7   21 May 1997 17:36:38   par
// Place chart in PDI stream.
// 
//    Rev 1.6   30 Apr 1997 16:14:22   amh
// No change.
// 
//    Rev 1.5   24 Mar 1997 17:31:56   smh
// Added ROMAN and other font consts.
// 
//    Rev 1.4   20 Mar 1997 11:12:26   smh
// Added OLE object export support.
// 
//    Rev 1.3   20 Feb 1997 10:52:16   dlm
// Add extern for SpaceDot function to fix compile errors in PD modules
//  for PDI export.
// 
//    Rev 1.2   10 Feb 1997 10:02:18   sp
// Arp Live merge to trunk
// 
//    Rev 1.0.1.2   31 Dec 1996 16:01:42   smh
// Moved #defines to pdx.h.
// 
//    Rev 1.0.1.1   31 Dec 1996 12:21:22   SRM
// add getAPIVersion()
// 
//    Rev 1.0.1.0   13 Dec 1996 09:13:36   smh
// Define APIVERSION for PDI export DLL.
// 
//    Rev 1.0   18 Oct 1996 11:50:52   smh
// Report Viewer Control (PDI) Export header
// 
// Initial revision.
// ****************************************************************************
//
#ifndef __PDX_H_
//
// Make a definition for this module.
//
#define __PDX_H_

#include "pd.h"
#include "pdx.h"

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//


// Version 4.0 attribute bits 
#define aBOLD		1		// it's bold 
#define aITALIC		2		// it's italic 
#define aUNDER		4		// and it's also underscored 
#define aSTRIKE		8		// strike three, yur out!
// Family bits included with attribute word
#define	ROMAN		1 << 8;	// FF_ROMAN
#define	SWISS		2 << 8;	// FF_SWISS
#define	MODERN		4 << 8;	// FF_MODERN

#define POINTSIZE	72		// a point is 1/72"
#define ANSI_DOT	183

// page size defaults (720ths)
#define PAGE_WIDTH_DEFAULT		6120
#define PAGE_HEIGHT_DEFAULT		7920

// file location of page count
#define SEEK_PAGECOUNT	2	// file location of dwPages (in FILE_HDR below)

#define WRR_CHARSET		100		// small font value
#define HZRES			720		// use this for horizontal too (PDI export)
#define VTRES			720		// R&R internal vertical resolution 

//
// Structure Section:
// Place in this section any structure definitions.
//

typedef struct	// preview page buffer
{
	DWORD dwPageTextCount;		// text count
	GLOBALHANDLE hPageText;		// looooong string of page data
	WORD wPageBoxes;			// number of boxes
	GLOBALHANDLE hBoxArray;		// array of box structures
	WORD wPageLines;			// number of boxes
	GLOBALHANDLE hLineArray;	// array of box structures
	WORD wPageImages;			// number of images
	GLOBALHANDLE hImgArray;		// array of image structures
	WORD wPageObjects;			// number of OLE objects
	GLOBALHANDLE hObjArray;		// array of objects
	WORD wPageCharts;			// number of charts
	GLOBALHANDLE hChartArray;	// array of charts
} EXP_PAGE;

typedef struct fontCache
{
	HDC		hDC;			// device context
	WORD	nZoom;			// zoom level
	WORD	nFont;			// font number
	char	nAtt;			// attribute value
	WORD	nPts;			// point size
	HFONT	hFont;			// font handle
	WORD	nAvgCharWid;	// average character width
} FONT_CACHE;

//
// Function Prototypes Section:
// Place in this section any function prototypes
//

#ifdef __cplusplus
extern "C" {
#endif

extern  WORD WINAPI pwVertLoc(LPPRT_STRUCT ps) ;
extern  void WINAPI pwClearFontCache(LPPRT_STRUCT ps) ;
extern	void WINAPI pwSetPalette(int hdib);
extern	unsigned short WINAPI pwSpaceDot(struct prt_face *prtFonts, char *lineDraw,int numfaces,int font);
extern	BOOL WINAPI pwFindAtt(struct prtstruct *ps,int font,int *att);
extern	unsigned long WINAPI pwCharWidth(struct prtstruct *ps,char ch,unsigned int font,unsigned int att,unsigned int decipoints);
extern	unsigned long PASCAL pwDotWidth(struct prtstruct *ps,unsigned short inches);
extern	unsigned int PASCAL pwFontHeight(struct prtstruct *ps,int font,int att,int pts, BOOL leading);
extern	unsigned long PASCAL pwLineHeight(struct prtstruct *ps,const char *lbuf,unsigned int size, BOOL leading);
extern	void PASCAL pwResetDriver(struct prtstruct *ps);
extern	int WINAPI pwFF(struct prtstruct *ps, BOOL send);
extern	int WINAPI pwInit(struct prtstruct *ps,struct prt_init *pi,const char *ptype,const char *pdrv,const char *pport);
extern	unsigned int WINAPI pwPageRoom(struct prtstruct *ps,unsigned int bmarg);
extern	BOOL WINAPI pwReset(struct prtstruct *ps,int pstatus);
extern	BOOL WINAPI pwVertical(struct prtstruct *ps,unsigned int units, BOOL send);
extern	BOOL WINAPI pwTopMargin(struct prtstruct *ps,unsigned int units, BOOL send);
extern	BOOL WINAPI pwBOL(struct prtstruct *ps,unsigned int units, BOOL send);
extern	void WINAPI pwEOL(struct prtstruct *ps,unsigned short units, BOOL send);
extern	BOOL WINAPI pwRecordLine( struct prtstruct *ps, char *pl, int sz);
//extern	BOOL WINAPI pwRecordBox(struct prtstruct *ps, LPPRT_BOX);
//extern	BOOL WINAPI pwRecordImage(struct prtstruct *ps,char *pimg);
extern	BOOL WINAPI pwEndBand(struct prtstruct *ps,unsigned int band, BOOL send);
extern	void delMemFonts(struct prtstruct *ps);
extern	int pget1(struct prtstruct *ps, int *rval);
extern	int pget2(struct prtstruct *ps, int *rval);
extern	int seglen(char *s,int fjust,unsigned short spDot);
extern	int setFont(LPPRT_STRUCT ps, HDC dev, int font, int att, int pts);
extern	int sizefld(struct prtstruct *ps,unsigned int *units,unsigned int *spaces,int endcode,unsigned int *pos);
extern	int setBOL(struct prtstruct *ps,unsigned short ascent);
extern	void setEOL(struct prtstruct *ps,unsigned short descent);
extern	void freePageMem(struct prtstruct *ps);
extern	int printLine(struct prtstruct *ps, char *lbuf);
extern	int WINAPI pwPlayBackPage(struct prtstruct *ps, LPRECT updateRegion);
extern  BOOL WINAPI pwNextPrevPage(LPPRT_STRUCT ps, HWND hWnd, int prState) ;
extern	WORD SpaceDot(LPPRT_STRUCT ps, int font);

#ifdef __cplusplus
}
#endif

// PDI export file output routines
extern HANDLE hFile;

extern BOOL wfOpen( LPSTR );
extern BOOL wfWriteByte( char );
extern BOOL wfWriteEsc( char );
extern BOOL wfWriteShort( short );
extern BOOL wfWriteLong( long );
extern BOOL wfWriteString( LPSTR );
extern BOOL wfWriteString( LPSTR, UINT );
extern BOOL wfWriteData( LPVOID, UINT );
extern BOOL wfSeekBegin( long );
extern BOOL wfSeekEnd( long );
extern void wfClose();
extern UINT scaleX( LPPRT_STRUCT, UINT );
extern UINT scaleY( LPPRT_STRUCT, UINT );
extern UINT scaleFromPrtX( LPPRT_STRUCT, UINT );
extern UINT scaleFromPrtY( LPPRT_STRUCT, UINT );
extern UINT leftMargin( LPPRT_STRUCT );

extern int		nCurRed, nCurGreen, nCurBlue, nCurFont, nCurAtt, nCurPts;
extern DWORD	dwBytesWritten, dwReportPages, dwFilePos;
extern WORD		wImages;
extern HGLOBAL	hPagePos;

#undef __PDX_H_

#endif // end __PD_H_

// *************************** End of File ************************************
