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
// $Log:   D:/R&R Project/archives/H/_PD.H_V  $
// 
//    Rev 1.16   Apr 25 2002 10:03:18   Admin
// Prototpes HorizontalLine & VerticalLine
// 
//    Rev 1.15   19 Feb 1997 14:57:04   dlm
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
//    Rev 1.14   30 Nov 1995 15:04:20   sbc
// rrwpdDLL -> rrpdDLL
// 
//    Rev 1.13   27 Nov 1995 12:05:16   smh
// c -> C++ & Win32 file i/o.
// 
//    Rev 1.12   06 Nov 1995 10:36:18   smh
// Put AFX_EXTENSION_MODULE into cplusplus conditionals for text exports.
// 
//    Rev 1.11   06 Nov 1995 10:12:50   par
// Ifdef out the printOleObject stuff so that the Text Export DLL can be kept
// as a "C" DLL.
// 
//    Rev 1.10   02 Nov 1995 17:34:46   par
// The rrwpdDLL variable needs to be global so that the instance handle can
// be accessed.
// 
//    Rev 1.9   31 Oct 1995 12:00:42   par
// Add the support functions for creating ole object print records.  Also added
// the support to print the ole object records inside the printer driver.
// 
//    Rev 1.8   27 Oct 1995 18:26:00   par
// Converted the printer driver to an MFC Extension DLL.
// 
//    Rev 1.7   25 Sep 1995 17:13:48   smh
// Updated some protos.
// 
//    Rev 1.6   22 Sep 1995 11:02:18   sbc
// Fix function args
// 
//    Rev 1.5   19 Sep 1995 16:53:48   sjo
// Changes regarding looking at sizeof(int) in all sources.
// 
//    Rev 1.4   13 Sep 1995 16:06:22   par
// Made changes to support 32-bits.  Asserts could not be added because of "C" based code.
// 
//    Rev 1.3   31 Aug 1995 09:17:26   mjs
// defined EXPORT
// 
//    Rev 1.2   29 Aug 1995 13:25:52   mjs
// win32
// 
//    Rev 1.1   19 Jul 1995 11:50:14   sbc
// #undef DLLENTRY before redefining
// 
//    Rev 1.0   16 Mar 1995 16:14:44   sbc
// Initial revision.
// 
//    Rev 1.11   29 Sep 1994 13:39:00   sbc
// Remove unused function argument
// 
//    Rev 1.10   23 Sep 1994 09:14:04   dlm
// Adjust prototypes of printLineBox() and drawBoxPD() for related
//  change in pwint.c fixing RRW bug 1756.
// 
//    Rev 1.9   15 Sep 1994 10:20:02   mjs
// Added global for toggle of fast/slow printing.
// 
//    Rev 1.8   13 Sep 1994 11:22:18   sbc
// Arg changes
// 
//    Rev 1.7   01 Aug 1994 10:06:40   sbc
// setFont() arg change
// 
//    Rev 1.6   17 May 1994 11:27:58   sbc
// Preview window restore changes
// 
//    Rev 1.5   15 Mar 1994 13:29:54   sbc
// Fix pwDotWidth() prototype
// 
//    Rev 1.4   20 Dec 1993 11:53:30   mjs
// Changed #ifdef PD_MAIN to #ifdef PD_DRIVER so global gets init'd.
// 
//    Rev 1.3   29 Nov 1993 15:03:58   erp
// added extern needed from mem.c source files
// 
//    Rev 1.2   19 Nov 1993 17:41:48   sbc
// Add extern C for C++
// 
//    Rev 1.1   21 Oct 1993 17:10:22   smh
// Added argument to pwEndBand() prototype.
// 
//    Rev 1.0   14 Oct 1993 10:11:18   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __PD_H_

//
// Make a definition for this module.
//
#define __PD_H_

#include "pd.h"
#ifdef PD_DRIVER
#define GLOBAL
#else
#define GLOBAL extern
#endif

#ifdef __cplusplus
extern "C" {
#endif
//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
#define BUTTON_BAR_LEN	(PVBUTTONS*(BUT_WID+BUT_SEP))+BUT_LEFT+BUT_VCR_SEP+BUT_VCR_SEP+BUT_LEFT

//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//



GLOBAL int hDIB
#ifdef PD_DRIVER
 = -1
#endif
; // handle to the DIB whose palette we want to use

GLOBAL int bFastPrint
#ifdef PD_DRIVER
 = 1
	#pragma message ( "bFastPrint = 1" )
#endif
; // Use faster Accusoft image print function



#undef GLOBAL
//
// Function Prototypes Section:
// Place in this section any function prototypes
//


extern  BOOL WINAPI pwRecordLineSeg(LPPRT_STRUCT ps, char *pbox) ;
extern  WORD WINAPI pwVertLoc(LPPRT_STRUCT ps) ;
extern  void WINAPI pwClearFontCache(LPPRT_STRUCT ps) ;

extern	void WINAPI pwSetPalette(int hdib);
extern	unsigned short WINAPI pwSpaceDot(struct prt_face FAR *prtFonts, char *lineDraw,int numfaces,int font);
extern	BOOL WINAPI pwFindAtt(struct prtstruct *ps,int font,int *att);
extern	unsigned long WINAPI pwCharWidth(struct prtstruct *ps,char ch,unsigned int font,unsigned int att,unsigned int decipoints);
extern	unsigned long PASCAL FAR pwDotWidth(struct prtstruct *ps,unsigned short inches);
extern	unsigned int PASCAL FAR pwFontHeight(struct prtstruct *ps,int font,int att,int pts, BOOL leading);
extern	unsigned long PASCAL FAR pwLineHeight(struct prtstruct *ps,const char FAR *lbuf,unsigned int size, BOOL leading);
extern	void PASCAL FAR pwResetDriver(struct prtstruct *ps);
extern	int WINAPI pwFF(struct prtstruct *ps, BOOL send);
extern	int WINAPI pwInit(struct prtstruct *ps,struct prt_init *pi,const char *ptype,const char *pdrv,const char *pport);
extern	unsigned int WINAPI pwPageRoom(struct prtstruct *ps,unsigned int bmarg);
extern	BOOL WINAPI pwReset(struct prtstruct *ps,int pstatus);
extern	BOOL WINAPI pwVertical(struct prtstruct *ps,unsigned int units, BOOL send);
extern	BOOL WINAPI pwTopMargin(struct prtstruct *ps,unsigned int units, BOOL send);
extern	BOOL WINAPI pwBOL(struct prtstruct *ps,unsigned int units, BOOL send);
extern	void WINAPI pwEOL(struct prtstruct *ps,unsigned short units, BOOL send);
extern	BOOL WINAPI pwRecordLine( struct prtstruct *ps, char *pl, int sz);
extern	BOOL WINAPI pwRecordBox(struct prtstruct *ps,char *pbox);
extern	BOOL WINAPI pwRecordImage(struct prtstruct *ps,char *pimg);
extern	BOOL WINAPI pwEndBand(struct prtstruct *ps,unsigned int band, BOOL send);
extern	void delMemFonts(struct prtstruct *ps);
extern	int lenToSize(unsigned int measure,int orient,unsigned int plen,unsigned int englen,unsigned int engwid,unsigned int metlen,unsigned int metwid);
extern	int pget1(struct prtstruct *ps, int *rval);
extern	int pget2(struct prtstruct *ps, int *rval);
extern	int pget4(struct prtstruct *ps, unsigned long *rval);
extern	unsigned int prevX(struct prtstruct *ps,unsigned int x);
extern	unsigned int prevY(struct prtstruct *ps,unsigned int y);
extern	unsigned int screenToPrinterX(struct prtstruct *ps,unsigned int x);
extern	unsigned int screenToPrinterY(struct prtstruct *ps,unsigned int y);
extern	unsigned int screenToGraphicsX(struct prtstruct *ps,unsigned int x);
extern	unsigned int screenToGraphicsY(struct prtstruct *ps,unsigned int y);
extern	int seglen(char *s,int fjust,unsigned short spDot);
extern	int setFont(LPPRT_STRUCT ps, HDC dev, int font, int att, int pts);
extern	int sizefld(struct prtstruct *ps,unsigned int *units,unsigned int *spaces,int endcode,unsigned int *pos);
extern  void rectLinePD(HDC hdc, int x, int y, int xe, int ye);
extern	void HorizontalLinePD(HDC hdc, int x0, int y0, int xsize, int thick);
extern	void VerticalLinePD(HDC hdc, int x0, int y0, int ysize, int thick);
extern  void drawBoxPD(LPPRT_STRUCT ps, HDC hdc, int xpos, int ypos, int xsize, int ysize, int fillMode) ;
extern	int setBOL(struct prtstruct *ps,unsigned short ascent);
extern	void setEOL(struct prtstruct *ps,unsigned short descent);
/* void freePage(struct *pgBuf,int pg); */
extern	void freePageMem(struct prtstruct *ps);
extern	void freePrevPageMem(struct prtstruct *ps);
extern	int printLine(struct prtstruct *ps, char *lbuf);
extern	void printImage(struct prtstruct *ps,struct printImage *pImg, LPRECT updateRegion);
#ifdef __cplusplus
extern  void printOleObject(LPPRT_STRUCT ps, PRT_OBJECT *pObj, LPRECT updateRect);
#endif
extern	void printLineBox(struct prtstruct *ps,struct printBox *pBox,int fillMode);
extern	int WINAPI pwPlayBackPage(struct prtstruct *ps, LPRECT updateRegion);
//extern	void WINAPI pwPrevPageNo(struct prtstruct *ps,unsigned int hWnd,char *page,unsigned int font);
extern  BOOL WINAPI pwNextPrevPage(LPPRT_STRUCT ps, HWND hWnd, int prState) ;
//extern	void WINAPI pwScrollPrev(struct prtstruct *ps,unsigned int pWnd,unsigned int wParam,int thumb,int vert);
//extern	int WINAPI pwPaintPrev(struct prtstruct *ps,unsigned int hWnd, LPRECT updateRegion);
//extern	int WINAPI pwPrintPage(struct prtstruct *ps,char *repname);
extern	int diskchs(struct prtstruct *ps,char *lBuf);
extern	int flushEBufs(struct prtstruct *ps);
extern	int sendchar(struct prtstruct *ps,int ch);
extern	int hz_position(struct prtstruct *ps,unsigned int column);
extern	int expsizefld(struct prtstruct *ps,unsigned int *units,unsigned int *spaces,int endcode,unsigned int *pos);
extern	unsigned int pixToCols(struct prtstruct *ps,unsigned int x);
extern	WORD SpaceDot(LPPRT_STRUCT ps, int font);



//
// ps is a pointer to the printer structure which is used when previous pages
// need to be freed.
//
#ifdef _MEM_C_
#define GLOBAL
	#pragma message ( "GLOBAL" )
#else
#define GLOBAL extern
	#pragma message ( "GLOBAL extern" )
#endif




GLOBAL LPPRT_STRUCT MEM_ps
#ifdef _MEM_C_
 = NULL
	#pragma message ( "MEM_ps = NULL" )
#endif
;



#undef GLOBAL

#undef DLLENTRY
#define DLLENTRY APIENTRY

    void        DLLENTRY MEM_InitMem (LPPRT_STRUCT Passed_ps);
    void        DLLENTRY MEM_InitPage (void);
    void        DLLENTRY MEM_FreePages (void);
    void        DLLENTRY MEM_SetLowMemoryOption (int iLowMemOption);
//
// These should simple map onto the Windows memory API calls.
//
    HGLOBAL     DLLENTRY MEM_GlobalAlloc     (UINT fuAlloc, DWORD cbAlloc);
    HGLOBAL     DLLENTRY MEM_GlobalReAlloc   (HGLOBAL hglb, DWORD cbNewSize, UINT fuAlloc);
    HGLOBAL     DLLENTRY MEM_GlobalFree      (HGLOBAL hglb);
    void *  DLLENTRY MEM_GlobalLock      (HGLOBAL hglb);
    BOOL        DLLENTRY MEM_GlobalUnlock    (HGLOBAL hglb);


#define ID_RADIO_FREE_PAGES         103
#define ID_RADIO_PAUSE_PRINT_PREVIEW 104
#define ID_RADIO_TERMINATE_PREVIEW  105




#ifdef __cplusplus
extern AFX_EXTENSION_MODULE rrpdDLL ;  // This provides the DLL instance handle. 
#endif

BOOL DLLENTRY MEM_LowConditionDlgProc (HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
extern void freePage(PRT_PAGE *pgBuf,int pg);



#ifdef __cplusplus
}
#endif

#endif // end __PD_H_

// *************************** End of File ************************************
