// ****************************************************************************
//
//              (C) Copyright 2001 Liveware Publishing Inc.
//                            All Rights Reserved.
//
//
// Module $Workfile:   rrview.h  $
// ================
//
// Description:
// ============
//
// 
//
// Modification History
// ====================
//
// Revision    Date        Time           Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/RRVIEW.H_V  $
// 
//    Rev 1.92   25 Aug 2004 07:54:00   Nick
// Version 10.5
// 
//    Rev 1.91   02 Jul 2004 13:31:24   Nick
// Undo, prettify, etc.
// 
//    Rev 1.90   Apr 25 2002 10:22:30   Admin
// Protos for Insert Image, new popups, etc.
// 
//    Rev 1.89   Feb 27 2001 15:43:14   nhubacker
// Entry for OnParams() from toolbar
// 
//    Rev 1.88   Sep 14 2000 10:02:38   nhubacker
// Add variables for printStats
// 
//    Rev 1.87   Mar 13 2000 16:10:26   ksinkel
// No change.
// 
//    Rev 1.86   Feb 15 2000 15:01:48   ksinkel
// Slowed down scrolling during up, down, right drag operations
// 
//    Rev 1.85   18 Jun 1997 18:52:18   dlm
// Added functions for charting section of report spec.
// 
//    Rev 1.84   11 Jun 1997 15:42:46   jsf
// Added the variable bCanChart to the doc class and code to set it 
// by using bChartFields(). 
// The view now uses OnUpdateGotRepCanChart() to enable the chart button
// and menu choice.
// 
//    Rev 1.83   28 May 1997 17:23:44   par
// Save and restore chart defaults.
// 
//    Rev 1.82   17 Apr 1997 10:08:14   pjm
// Add prototype for dispCharts().
// 
//    Rev 1.81   03 Apr 1997 13:41:28   jsf
// disable charting menu/button for beta release
// 
//    Rev 1.80   14 Mar 1997 16:23:46   SRM
// chart support initial checkin
// 
//    Rev 1.79   06 Mar 1997 11:07:12   par
// Prepare to convert OLE objects to images.
// 
//    Rev 1.78   21 Mar 1996 16:38:04   mjs
// Made shadeFldBand() public, so I can call it in dfmod.cpp
// 
//    Rev 1.77   21 Mar 1996 10:17:18   mjs
// Added new function in wmove.cpp to get width of a character RRW #2503
// 
//    Rev 1.76   27 Feb 1996 15:15:56   mjs
// Moved splash function to CMainFrame class.
// 
//    Rev 1.75   21 Feb 1996 17:00:58   par
// Drop files is no longer used.  OnDrop handles files now.
// 
//    Rev 1.74   21 Feb 1996 12:43:14   jpb
// Don't have ReportWriterQuery clipformat in RRW
// 
//    Rev 1.73   20 Feb 1996 15:35:08   jpb
// add clipformat variable for RWQ
// 
//    Rev 1.72   09 Feb 1996 08:31:12   sbc
// Changes for undo of last field move
// 
//    Rev 1.71   31 Jan 1996 14:18:48   sbc
// Add two message handlers for format bar CR/Esc accelerators
// 
//    Rev 1.70   25 Jan 1996 19:33:02   sbc
// Add function GetTopLineGridPixel
// 
//    Rev 1.69   25 Jan 1996 13:28:30   par
// Tweaked the snapping of OLE objects.
// 
//    Rev 1.68   12 Jan 1996 16:10:56   sbc
// New message map function for 2D alignment
// 
//    Rev 1.67   11 Jan 1996 16:00:30   par
// New file format for OLE objects to fix bugs.  The extent of the object needed
// to be maintained for the life of the object.
// 
//    Rev 1.66   10 Jan 1996 12:52:30   par
// Instead of maintaining a separate selection pointer that is used to determine if
// an OLE object is selected, the OLE code now uses the R&R CurFld to determine
// if an OLE object is currently selected.
// 
//    Rev 1.65   10 Jan 1996 11:46:44   mjs
// Added debugMove().
// 
//    Rev 1.64   11 Dec 1995 11:07:58   par
// Replaced report summary with file properties dialog.
// 
//    Rev 1.63   07 Dec 1995 10:29:16   par
// Removed all references to Field Rect in favor of Get Client Rect.  The goal was
// to reduce the number of variables used for the runtime.  Besides, with the 
// rulers now being windows, the field rect is always the client rect.
// 
//    Rev 1.62   06 Dec 1995 11:10:34   par
// Remove region code.
// 
//    Rev 1.61   05 Dec 1995 18:50:16   jpb
// move export stuff to CRrExport class
// 
//    Rev 1.60   05 Dec 1995 18:05:48   par
// Removed unused Horz and Vert rectangles.
// 
//    Rev 1.59   01 Dec 1995 13:39:30   par
// Rulers are now derived from CToolBar so that they don't get overwritten by OLE
// objects.
// 
//    Rev 1.58   27 Nov 1995 12:04:14   smh
// Export win32 file i/o.
// 
//    Rev 1.57   22 Nov 1995 18:59:00   par
// Disabled Insert Object unless report is open.  Added OLE Object to report
// spec.
// 
//    Rev 1.56   22 Nov 1995 14:27:08   sbc
// For convert of insert field dialog to MFC
// 
//    Rev 1.55   21 Nov 1995 15:47:02   sbc
// Move main accelerator handle to mainframe class
// 
//    Rev 1.54   21 Nov 1995 13:37:40   sbc
// Remove several function overrides
// 
//    Rev 1.53   15 Nov 1995 16:48:56   sbc
// Remove keyboard functions
// 
//    Rev 1.52   15 Nov 1995 07:52:26   sbc
// Restore some functions
// 
//    Rev 1.51   14 Nov 1995 15:30:32   smh
// Removed export to MAPI routines, now do all in one place.
// 
//    Rev 1.50   09 Nov 1995 16:49:36   sbc
// Comment out band line properties functions
// 
//    Rev 1.49   06 Nov 1995 11:56:18   sbc
// Add message handler
// 
//    Rev 1.47   01 Nov 1995 15:50:06   par
// Add drop target support.
// 
//    Rev 1.46   01 Nov 1995 09:53:28   pjm
// Add prototypes for routines to disable sort/join for user SQL etc.
// 
//    Rev 1.45   26 Oct 1995 17:36:38   par
// The scrolling messages are now passed along to the OLE active objects so that they will also scrol
// l.
// 
//    Rev 1.44   26 Oct 1995 15:11:50   sbc
// New OnKeyDown() function
// 
//    Rev 1.43   19 Oct 1995 10:26:06   sbc
// Comment out OnActivateView(), which had no code in RRVIEW.CPP
// 
//    Rev 1.42   13 Oct 1995 15:27:04   par
// Added and enabled the basic OLE container stuff.  It works but it cannot save
// or print.
// 
//    Rev 1.41   09 Oct 1995 19:21:20   par
// Fixed the cursor flickering problem with the addition of OnSetCursor.
// 
//    Rev 1.40   28 Sep 1995 08:15:02   sbc
// Move Wizard terminate message hander to CMainFrame
// 
//    Rev 1.39   26 Sep 1995 14:20:42   smh
// Changed psIntOut argument type for Win32.
// 
//    Rev 1.38   13 Sep 1995 17:32:42   smh
// Updated exportDialog proto
// 
//    Rev 1.37   13 Sep 1995 14:16:34   smh
// scott's 32-bit changes
// 
//    Rev 1.36   06 Sep 1995 16:18:20   sbc
// 
//    Rev 1.35   29 Aug 1995 16:05:40   dlm
// Make CompNames NOT a member function.  It's really analogous to strcmp.
// 
//    Rev 1.34   07 Aug 1995 10:08:24   mjs
// Fix GPF (Init function).
// 
//    Rev 1.33   02 Aug 1995 13:32:00   pjm
// Added RTF export dislog stuff.
// 
//    Rev 1.32   02 Aug 1995 12:48:20   sbc
// Remove GetPromptText (it's in RrStatBar)
// 
//    Rev 1.31   02 Aug 1995 12:15:54   mjs
// Removed fPrompt.
// 
//    Rev 1.30   02 Aug 1995 09:47:32   sbc
// setFldMetrics() is in CRrDoc
// 
//    Rev 1.29   02 Aug 1995 09:41:16   sbc
// screenColor() is in CRrDoc
// 
//    Rev 1.28   01 Aug 1995 14:10:42   sbc
// Move stuff to rrdoc.h
// 
//    Rev 1.27   01 Aug 1995 11:38:06   sbc
// Moved in function prototypes from _wprint.h
// 
//    Rev 1.26   01 Aug 1995 09:20:22   pjm
// #included rrdoc.h.
// 
//    Rev 1.25   31 Jul 1995 13:34:26   mjs
// Changed some GDI handles to object.
// 
//    Rev 1.24   31 Jul 1995 11:52:02   sbc
// Remove functions now in RrStatBar class
// 
//    Rev 1.23   31 Jul 1995 11:34:10   mjs
// Use CDC instaed of hDC.
// 
//    Rev 1.22   26 Jul 1995 17:57:56   smh
// DILE classification
// 
//    Rev 1.21   26 Jul 1995 14:55:18   mjs
// Move create/delete edit end fns
// 
//    Rev 1.20   26 Jul 1995 11:02:52   mjs
// No change.
// 
//    Rev 1.19   26 Jul 1995 09:14:36   pjm
// Made _wmain.h functions public.
// 
//    Rev 1.18   25 Jul 1995 09:49:46   mjs
// Added wfield.h
// 
//    Rev 1.17   24 Jul 1995 15:35:30   smh
// Made setExpDefs public for rpinit.cpp
// 
//    Rev 1.16   24 Jul 1995 14:43:56   mjs
// Added wbox and wbitmap
// 
//    Rev 1.15   24 Jul 1995 11:15:46   smh
// Removed showLibrary, it's in rstatbar.h.
// 
//    Rev 1.14   24 Jul 1995 10:38:14   mjs
// Added drawFldHandles
// 
//    Rev 1.13   19 Jul 1995 08:10:32   pjm
// Picked up stuff from global.h.
// 
//    Rev 1.12   18 Jul 1995 16:37:50   smh
// added globals from dbexport.h.
// 
//    Rev 1.11   18 Jul 1995 16:26:30   mjs
// Moved box drawing functions from wfield.h.
// 
//    Rev 1.10   18 Jul 1995 15:38:14   smh
// Classified export stuff from print\rpexport.cpp & wprintui
// 
//    Rev 1.9   17 Jul 1995 15:29:10   sbc
// Move stuff in/out
// 
//    Rev 1.8   17 Jul 1995 11:24:16   sbc
// Added stuff from wmove.cpp
// 
//    Rev 1.7   14 Jul 1995 14:12:10   sbc
// Started on WLAYOUT
// 
//    Rev 1.6   13 Jul 1995 11:32:18   sbc
// Move invalidateView routines to rrdoc.h
// 
//    Rev 1.5   12 Jul 1995 17:33:38   smh
// Added stuff from SPEC directory to CRrView class.
// 
//    Rev 1.4   12 Jul 1995 16:13:44   sbc
// Cram in the WDISPLAY stuff
// 
// Initial revision.
// 
// ****************************************************************************

//
// Make a definition for this module.
//
#ifndef _RRVIEW_H_

#define _RRVIEW_H_

// rrview.h : interface of the CRrView class
//
/////////////////////////////////////////////////////////////////////////////

#include "_spec.h"
#include "dbexport.h"
// #include "rrdoc.h"  // this worries me
#include "pd.h"         // for LPFNPWINIT
#include "dfile.h"      // for EXPORTINFO
#include "wlayout.h"    // for MOVEUNDO

#define BIG_MOVE_TIMER	100
#define AUTOSAVE_TIMER	101

class CRrDoc;
class CEditText;
class CRrCntrItem;
class CMainFrame;               // for m_pFrame

class CRrView : public CView
{
protected: // create from serialization only
	CRrView();
	DECLARE_DYNCREATE(CRrView)

// Attributes
public:
	CRrDoc* GetDocument();
	void Init(void);

// OLE Operations
public:
	CRrCntrItem* HitTestItems(CPoint point) ;
	void UpdateActiveItem() ;
	virtual BOOL IsSelected(const CObject* pDocItem) const ;

// From _wdispla.h - variables:
public:
	int curHzLoc;
	int curVtLoc;

// From wdisplay.h - functions:
public:
	BOOL alignHorizontal(int xpos, BOOL end);
	void onHScroll(UINT nSBCode, UINT nPos);
	void onVScroll(UINT nSBCode, UINT nPos);
	void invalidateVert(void);
	void invalidateLine(int line);
	BOOL cursorInRuler(POINT point);
	void invalidateHorz(void);
	void setScrollRanges(void);
	void horizontalRuler(void);
	void vertInWindow(int line, LPFLDHDR f);
	void verticalRuler(void);
	void drawLine(HDC hDC, int topx, int topy, int botx, int boty);
	void drawLine(CDC *, int, int, int, int);
	void sizeStatusBar(void);
//      void statusCaps(void);
//      void statusNum(void);
	void showHorzScrollBar(BOOL show);
	void showVertScrollBar(BOOL show);
	void setScrollPosVert(int pos, BOOL redraw);
	void setScrollPosHorz(int pos, BOOL redraw);
	virtual BOOL OnScrollBy(CSize sizeScroll, BOOL bDoScroll=TRUE) ;

/// Static routines from wdsp.cpp:
	BOOL shouldUpdate(LPFLDHDR f, CRect &rectClip);

/// Statics from wcaret.cpp:
private:
	int caretHite;
	int rulerCaretWidth;

	void horzCaret();
	LPFLDHDR lookLeft();
	LPFLDHDR lookRight();

private:
// From wbox.cpp
CBrush	LineBrush;
CPen	DotPen;
CPen	DashDotPen;
/// From wbitmap.cpp
CPen	GrayPen;

	// These are now in wdsp.cpp
public:
void    DotPensCreate(void);
void    DotPensDelete(void);
void    penLine(CDC *pDC, CPen *pPen,int x,int y);
void	HorizontalLine(CDC *pDC, int x0, int y0, int xsize, int thick) ;
void	VerticalLine(CDC *pDC, int x0, int y0, int ysize, int thick) ;
void    drawBoxOutline(void);
void    rectLine(CDC *pDC, int x,int y,int xe,int ye);
void    drawBox(CDC *pDC, LPFLDHDR f, int draw);
void    drawLinePoint(POINT org, POINT newpt);

	// These are now in wdsp.cpp
public:
void drawFldHandles(CDC *pDC, LPFLDHDR f);
void drawGrayBox(CDC *pDC, PRECT r);
void drawImageOutline(void);
void displayBitmap(CDC *pDC, int i, int left, int top, int width, int height);

// screenColor is in CRrDoc
// COLORREF screenColor(int index);

// From wfield.h
	BOOL	createTextWnd(CFont *, int, LPCSTR, char);
	void	deleteTextWnd(void);

// From wlayout.h - variables:
public:
	int			xMvLeft;
	long		yMvTop;
	int			hzdelta;
	int			vtdelta;
	LPFLDHDR	tfmove;
	LPFLDHDR	bfmove;
	LPFLDHDR	lfmove;
	LPFLDHDR	rfmove;
	int			rulerCaretLoc;
	int			m_nMoveRedoFlds;
	int			m_nMoveUndoFlds;
	MOVE_FIELD_UNDO	*m_pUndo;
	MOVE_FIELD_REDO	*m_pRedo;
	int			UndoCount ;
	int			RedoCount ;
	ALLUNDO		*UndoStack ;
	ALLREDO		*RedoStack ;
	void		AlignUndo(void) ;

// From _wlayout.h - functions:
public:
	int		getyMove(POINT point,int grid);
	void	posFldVert(LPFLDHDR f);
	void	nonClientMarkRect(POINT point,int hzjmp,int vtjmp);
	void	getDeltas(POINT point);
	BOOL	selectData(LPFLDHDR f, POINT point, BOOL bMouseDown);

// From wlayout.h - functions:
public:
	void    bigEndCaret(int row);
	void    endCaret(void);
	void    posCaret(BOOL offFld);
	void    leftBigMove(int x,BOOL scroll);
	void    homeCaret(void);
	void    centerMove(void);
	BOOL    linePropDlg();
	BOOL    fieldPropDlg(void);
	void    downCaret(BOOL toggle);
	void    rulerCaret(int x,int width);
	void    inflateObject(LPFLDHDR f,LPRECT lprc,BOOL bHandles);
	void    rightCaret(WPARAM wParam);
	void    endMove(void);
	BOOL    clrMark(void);
	void    moveMarkRect(POINT point);
	void    mouseMove(POINT point);
	void    posFirstMarked(void);
	void    upMove(int y);
	void    rightBigMove(int x,BOOL scroll);
	void    invalidateFld(LPFLDHDR f);
	BOOL    markRect(POINT point,BOOL clear);
	void    makeFldCurrent(LPFLDHDR f);
	int     GetTopLineGridPixel( int nLine );
	BOOL    endMarkRect(POINT point);
	void    bigHomeCaret(void);
	void    nonClientMove(POINT point,BOOL move);
	void    dec2DCount(LPFLDHDR f);
	void    shadePixBand(int pix,BOOL scroll);
	int     prevPitchFont(void);
	BOOL    startMove(BOOL mouse,POINT point,BOOL copy);
	void    RedoMoveFields(int count, void *data);
	void    UndoMoveFields(int count, void *data);
	void    RedoResizeField(int count, void *data);
	void    UndoResizeField(int count, void *data);
	void    inc2DCount(LPFLDHDR f);
	void    mouseCaret(POINT point,BOOL clr,BOOL doit);
	void    upCaret(BOOL toggle);
	void    fieldEdit(POINT point);
	void    downMove(int y);
	void    homeMove(void);
	void    doneMove(void);
	void    leftCaret(WPARAM wParam);
	BOOL    markFieldKey(POINT point,BOOL clear);
	BOOL    fieldModify(POINT point);
// setFldMetrics() is in CRrDoc
//      void    setFldMetrics(LPFLDHDR f);
	void    pageUpCaret(void);
	void    nextField(int right);
	void    fieldFormat(void);
	void    pageDownCaret(void);
	LPFLDHDR onField(POINT point);
	void    showEditCursor(void);
	BOOL    overObject(POINT point);
	BOOL    dataStretch(void);
	void    drawDataOutline(void);
	BOOL    moveDataRect(POINT point);
	BOOL    setDataCursor(void);
	BOOL    formatCharField(LPMFFIELD);
	BOOL    formatDateField(LPMFFIELD);
	BOOL    formatDateTimeField(LPMFFIELD);
	BOOL    formatTimeField(LPMFFIELD);
	BOOL    formatNumericField(LPMFFIELD);

// Statics from wmark.cpp:
private:        
	POINT markPoint;                // Starting point of marking rect.
	RECT mRect;
	POINT lPoint;           // For line drawing.
	int markGridRow;                // For computing vertical grid.
private:
	BOOL clickedBox(LPFLDHDR f);
	void drawMarkRect(int bandPix);
	void drawOutline(LPRECT rc);
	BOOL fieldHit(LPFLDHDR f, POINT point);
	void fixMarkRect(int x, int y);
	BOOL insideBox(LPFLDHDR f,POINT pt);
	BOOL nearBox(LPFLDHDR f, POINT p);
	BOOL rectInRect(LPRECT a, LPRECT b);

/// Statics from wmove.cpp:
private:
	// mouse move
	int mouseX,mouseY;
	// Distances from mouse cursor to left and top of first field.
	int xdMove;
	int ydMove;
	int moveGridRow;
	POINT nopoint;
	POINT movePoint;
	BOOL oldStart;
	BOOL cTrack;
	RECT dataRect;
	LPFLDHDR curData;
public:
	// controls timing of moves that require horiz scrolling -- to slow them down
	BOOL m_bBigmoveTimer; 
	void OnTimer( UINT nIDEvent );

	void shadeFldBand(LPFLDHDR f, BOOL scroll);     // used in dfmod.cpp
private:
	int getBestFlip(int xmove);
	int getxMove(POINT point);
	int getyKey(int key);
	BOOL keySnapText(LPFLDHDR f);
	BOOL markData(POINT point);
	void markField(LPFLDHDR f);
	void moveFld(LPFLDHDR f, BOOL scroll);
	void nonClientDataRect(POINT point, int xmove, int ymove);
	BOOL oldMove(void);
	BOOL onHandle(POINT point, BOOL bMouseDown);
	int getCharWidth(char x, HFONT font);
	void resizeData(LPFLDHDR f, RECT rc);
	void scrollMove(POINT point, int xmove, int ymove);
	BOOL slowSystem(void);
	int tickFactor(void);
	void update(BOOL bDoit);
#ifdef DEBUG_MOVE_ON
	void debugMove(LPSTR s, int val);
#endif

// keyboard move

// either move
BOOL copied;

// From _wmain.h - functions:
public:
#if defined(CUSTOM_TITLE)
	void customTitleScreen(LPSTR customTitleScreenName);
#endif
// From global.h - variables
public:
// rectangles in client area
	BOOL ActionBar;                 // show/hide action bar
	// end of stuff from global.h

// Overrides
//
public:
	//// CRrView client rectangles ////
	CRect m_RectTemp;
	CMainFrame* m_pFrame;   // So we only do (CMainFrame*)AfxGetMainWnd() once in constructor.
	CRrDoc *m_pDoc;                 // Same for related document
	///////////////////////////////////
	CEditText *m_pTextWnd;
	BOOL	m_bFldPropMenuActive;      
	BOOL	m_bLinePropMenuActive;     
	UINT	m_nFldFormatPage;
	UINT	m_nPrefPage ;
	UINT	m_nExportPage ;
protected:
	POINT m_CurrentMousePos;
	BOOL m_LeftMouseDown;
	BOOL m_RightMouseDown;
	
//      virtual BOOL OnCmdMsg(UINT nID, int nCode, void *pExtra, AFX_CMDHANDLERINFO * pHandlerInfo);
//      virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

// Implementation
protected:
	void dispBoxes(CDC *pDC, CRect &rectClip);
	void dispCharts(CDC *pDC, CRect &rectClip);
	void dispFields(CDC *pDC, CRect &rectClip);
	void dispHandles(CDC *pDC, CRect &rectClip);
	void dispImages(CDC *pDC, CRect &rectClip);
	void displayFields(CDC *pDC, BOOL bMarked, CRect &rectClip);
	void dispNewPage(CDC *pDC);
	void dispReadyText(CDC *pDC, LPFLDHDR f, BOOL bMarked);
	void dispSnapGrid(CDC *pDC, CRect &rectClip);
	void drawRuler(CDC *pDC, CRect &rectClip);
	void drawVRuler(CDC *pDC, CRect &rectClip);
	void paintView(CDC *pDC, CRect &rectClip);
	void showScaryStuff(CDC *pDC);

public:
	virtual ~CRrView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
//      virtual void OnActivateView(BOOL bActivate, CView*, CView*);
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual void OnInitialUpdate(); // called first time after construct
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	
	// drag drop implementation
	CPoint SnapOleObject(CPoint point) ;
	BOOL   GetObjectInfo(COleDataObject* pDataObject, CSize* pSize, CSize* pOffset) ;
	virtual BOOL       OnDrop     (COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point) ;
	virtual DROPEFFECT OnDragEnter(COleDataObject* pDataObject, DWORD grfKeyState,     CPoint point) ;
	virtual DROPEFFECT OnDragOver (COleDataObject* pDataObject, DWORD grfKeyState,     CPoint point) ;
	virtual void       OnDragLeave() ;
	
	COleDropTarget m_dropTarget     ;
	DROPEFFECT     m_prevDropEffect ;
	BOOL           m_bInDrag        ;
	CPoint         m_dragPoint      ;
	CSize          m_dragSize       ;
	CSize          m_dragOffset     ;
#if defined RSW && defined INTERACTIVE
	CLIPFORMAT      m_cfReportWriterQuery;
	BOOL            m_bDraggingQuery;               // set when dragging Arpeggio query
#endif
#ifdef INTERACTIVE
	BOOL            m_bDraggingFile ;               // set when dragging a file.  Drop files is not used in interactive. 
#endif


	// Printing support
//      virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
//      virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
//      virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Generated message map functions
public:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	// common update handlers
	afx_msg void OnDisable(CCmdUI* pCmdUI); //disabled charting for rrw beta 4/3/97 JSF
	afx_msg void OnUpdateGotRep(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGotRepCanChart(CCmdUI* pCmdUI);
	afx_msg void OnUpdateNoActiveState(CCmdUI* pCmdUI);
	afx_msg void OnUpdateNoMouseActive(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTrue(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePropCalcTot(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePropTotal(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePropDictionary(CCmdUI* pCmdUI);
	//{{AFX_MSG(CRrView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnUpdateInsertObject(CCmdUI* pCmdUI) ;
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEdit();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnClose();
	afx_msg void OnExit();
	afx_msg void OnSecurity() ;
	afx_msg void OnPrintReport();
	afx_msg void OnButtonPrintReport();
	afx_msg void OnUpdatePrintReport(CCmdUI* pCmdUI);
	afx_msg void OnPreviewReport();
	afx_msg void OnUpdatePreviewReport(CCmdUI* pCmdUI);
	afx_msg void OnRedo();
	afx_msg void OnUndo();
	afx_msg void OnUndoList();
	afx_msg void OnUpdateUndo(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRedo(CCmdUI* pCmdUI);
	afx_msg void OnUpdateUndoList(CCmdUI* pCmdUI);
	afx_msg void OnCut();
	afx_msg void OnUpdateCut(CCmdUI* pCmdUI);
	afx_msg void OnCopy();
	afx_msg void OnUpdateCopy(CCmdUI* pCmdUI);
	afx_msg void OnPaste();
	afx_msg void OnUpdatePaste(CCmdUI* pCmdUI);
	afx_msg void OnClear();
	afx_msg void OnUpdateClear(CCmdUI* pCmdUI);
	afx_msg void OnPasteClipImage();
	afx_msg void OnUpdatePasteClipImage(CCmdUI* pCmdUI);
	afx_msg void OnPasteSpecial();
	afx_msg void OnPasteLink();
	afx_msg void OnMoveFlds();
	afx_msg void OnUpdateMoveFlds(CCmdUI* pCmdUI);
	afx_msg void OnCopyFlds();
	afx_msg void OnUpdateCopyFlds(CCmdUI* pCmdUI);
	afx_msg void OnToolbar();
//	afx_msg void OnViewHruler();
//	afx_msg void OnViewVruler();
	afx_msg void OnViewRuler();
	afx_msg void OnViewSnap();
	afx_msg void OnFldNames();
	afx_msg void OnFieldInsert();
	afx_msg void OnInsBandLine();
	afx_msg void OnUpdateInsBandLine(CCmdUI* pCmdUI);
	afx_msg void OnCreateBandLine();
	afx_msg void OnUpdateCreateBandLine(CCmdUI* pCmdUI);
	afx_msg void OnTextFile();
	afx_msg void OnInsLineSegment();
	afx_msg void OnInsertBox();
	afx_msg void OnInsertImage();
	afx_msg void OnInsertImageField();
	afx_msg void OnInsertChart();
	afx_msg void OnFldFont();
	afx_msg void OnUpdateFldFont(CCmdUI* pCmdUI);
	afx_msg void OnFldFormat();
	afx_msg void OnUpdateFldFormat(CCmdUI* pCmdUI);

	afx_msg void OnUpdateAlignLeft(CCmdUI* pCmdUI);
	afx_msg void OnAlignLeft();

	afx_msg void OnUpdateAlignCenter(CCmdUI* pCmdUI);
	afx_msg void OnAlignCenter();
	afx_msg void OnUpdateAlignRight(CCmdUI* pCmdUI);
	afx_msg void OnAlignRight();
	afx_msg void OnUpdateAlignTop(CCmdUI* pCmdUI);
	afx_msg void OnAlignTop();
	afx_msg void OnUpdateAlignMiddle(CCmdUI* pCmdUI);
	afx_msg void OnAlignMiddle();
	afx_msg void OnUpdateAlignBottom(CCmdUI* pCmdUI);
	afx_msg void OnAlignBottom();

	afx_msg void OnOleSaveAsPicture();
	afx_msg void OnUpdateOleSaveAsPicture(CCmdUI* pCmdUI);
	afx_msg void OnBandLineProp();
	afx_msg void OnUpdateBandLineProp(CCmdUI* pCmdUI);
	afx_msg void OnBandLineJust();
	afx_msg void OnUpdateBandLineJust(CCmdUI* pCmdUI);
	afx_msg void OnRecordOptions();
	afx_msg void OnRulerSpacing();
	afx_msg void OnSnapToGrid();
	afx_msg void OnPreferences();
	afx_msg void OnUpdateOptions(CCmdUI* pCmdUI);
	afx_msg void OnDefaultSettings();
	afx_msg void OnChartDefaults() ;
	afx_msg void OnDefaultDirs();
	afx_msg void OnDatabaseMaster();
	afx_msg void OnUpdateDatabaseMaster(CCmdUI* pCmdUI);
	afx_msg void OnDatabaseJoin();
	afx_msg void OnUpdateDatabaseJoin(CCmdUI* pCmdUI);
	afx_msg void OnSort();
	afx_msg void OnUpdateSort(CCmdUI* pCmdUI);
	afx_msg void OnGroup();
	afx_msg void OnQuery();
	afx_msg void OnCalcs();
	afx_msg void OnTotals();
	afx_msg void OnParams();
	afx_msg void OnUdfs();
	afx_msg void OnAutoTotal();
	afx_msg void OnUpdateAutoTotal(CCmdUI* pCmdUI);
	afx_msg void OnPurge();
	afx_msg void OnUpdatePurge(CCmdUI* pCmdUI);
	afx_msg void OnPasteText();
	afx_msg void OnUpdatePasteText(CCmdUI* pCmdUI);
	afx_msg void OnCursorLeft();
	afx_msg void OnAltCursorLeft();
	afx_msg void OnBigCursorLeft();
	afx_msg void OnCursorRight();
	afx_msg void OnAltCursorRight();
	afx_msg void OnBigCursorRight();
	afx_msg void OnCursorUp();
	afx_msg void OnCursorDown();
	afx_msg void OnHome();
	afx_msg void OnEnd();
	afx_msg void OnReturn();
	afx_msg void OnEscape();
	afx_msg void OnAltCursorUp();
	afx_msg void OnAltCursorDown();
	afx_msg void OnPageDown();
	afx_msg void OnPageUp();
	afx_msg void OnBigHome();
	afx_msg void OnBigEnd();
	afx_msg void OnScrollPageDown();
	afx_msg void OnScrollPageUp();
	afx_msg void OnScrollRight();
	afx_msg void OnScrollUp();
	afx_msg void OnScrollBigLeft();
	afx_msg void OnScrollBigRight();
	afx_msg void OnScrollDown();
	afx_msg void OnScrollEnd();
	afx_msg void OnScrollHome();
	afx_msg void OnScrollLeft();
	afx_msg void OnMarkBand();
	afx_msg void OnTabNextFld();
	afx_msg void OnTabPrevFld();
	afx_msg void OnFuncFieldEdit();
	afx_msg void OnKeyMarkAdd();
	afx_msg void OnKeyMarkNew();
	afx_msg void OnInsertSpace();
	afx_msg void OnDelSpace();
	afx_msg void OnCenterFld();
	afx_msg void OnPopupFieldExpression();
	afx_msg void OnPopupFieldTotal();
	afx_msg void OnPopupFieldDictionary();
	afx_msg void OnUpdateSnapToGrid(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFldNames(CCmdUI* pCmdUI);
//	afx_msg void OnUpdateViewHruler(CCmdUI* pCmdUI);
//	afx_msg void OnUpdateViewVruler(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewRuler(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewSnap(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMarkedLines(CCmdUI* pCmdUI);
	afx_msg void OnEditText();
	afx_msg void OnUpdateEditText(CCmdUI* pCmdUI);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnShortCutKey();
	afx_msg void OnTwoDAlign();
	afx_msg void OnFormBarPtsCR();
	afx_msg void OnFormBarPtsEsc();
	//}}AFX_MSG

	//// WM_USER Messages ////
	afx_msg LRESULT OnEditTextFocus(WPARAM wParam, LPARAM lParam);
//      afx_msg LRESULT OnInsDlgClose(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()


	//// Report Specification ////
public:
	BOOL	printStats( BOOL bPrint );
	void	addUndo(int type, int count, void *data) ;
	void	clearUndo(void) ;
	void	addRedo(int type, int count, void *data) ;
	void	clearRedo(void) ;
private:

	// these routines and data all local to spec modules

	////// data

	// statics from specmain.cpp
	LPSTR	linePtr;
	LPSTR	LineBeg;
	int		LineCt;
	int		RepStatFont;
	BOOL	bPrintLibrarian ;
	HANDLE	hPrintFile ;

	// statics from specfld2.cpp
	int		LastLgt;

	//// end of data
	
	////// routines
#if defined RSW
	void	PrFldTypes( void );
	void	PrFile( LPSTR head, LPSTR name, int newline, LPSTR alias, int bFileSys );
	void	PrMemo( LPSTR head, LPSTR file );
	void	PrtPlatform( LPSTR alias );
	void	PrtSelect( void );
#else
	void	PrFile( LPSTR head, LPSTR name, int shrink, LPSTR alias );
	void	PrMemo( LPSTR head, LPMFFILE file );
	void	PrSGroup( LPMFFILE file );
	void	PrSibs( LPMFFILE file );
	void	PrtAlias( void );
	void	PrtMaster( LPSTR alias );
	void	PrtMisc( void );
	void	PrtRelated( int i, LPMFFILE file, LPSTR alias );
#endif

	int     intascii( UINT val, LPSTR str, int ints, int dec );
	int     newL( void );
	int     pindnt( int col );
	void    PrAlFld( LPMFFIELD fld );
	void    PrAMemo( LPSTR head, LPSTR file );
	void    PrBlankLine( int n );
	void    PrCFld( LPMFFIELD fld );
	void	PrChartData( LPRRCHART* plist, int ii );
	void	PrChartFont( LPRRCHART* plist, int ii );
	void	PrChartOptions( LPRRCHART* plist, int ii );
	void	PrChartText( LPRRCHART* plist, int ii );
	void	PrChartTypeAndStyle( LPRRCHART* plist, int ii );
	void    PrCLines( void );
	void    PrFld( LPFLDHDR fh, FONTINFO *fontlist, int *flistnum, LPRRBOX *lflist, int *line_field, LPRRBOX *bflist, int *box_field, LPRRIMAGE *iflist, int *image_field, LPRRCHART* cflist, int* chart_field, CObList& listOleObjects );
	void    PrFldName( LPFLDHDR fh );
	void    PrFontKey( FONTINFO *fontlist, int flistnum );
	void    PrLBIFields( LPRRBOX *lflist, int line_field, LPRRBOX *bflist, int box_field, LPRRIMAGE *iflist, int image_field, LPRRCHART *cflist, int chart_field, CObList& listOleObjects);
	void    PrNewPage( int n );
	void    PrtFields( void );
	void    PrtFiles( void );
	int     PrtOptions( void );
	void    PrtQuery( void );
	void    PrtSortBreak( void );
	void    PrWrap( LPSTR head, LPSTR str, int indent, int startnew, int ind2, BOOL smart );
	void    psBigHead( LPSTR head );
	void    psCharOut( char ch );
	void	psLineOut( LPCSTR str );
	void    WhenP( int i, LPSTR buf );
	LPSTR   wordWrap( LPSTR str, int len, LPSTR chr );
	void    zpprintf( LPSTR fmt, ... );

	// statics from specmain.cpp
	int     ckprst( void );
	void    picd4( int m, int d, int y, LPSTR out );
	int     println( LPSTR *fbufs );
	void    prffd( int end );
	void    PrSetFont( void );
	void    PrtDefs( void );
	void    PrtTitle( void );
	void    psIntOut( WORD intgr );
	void    psRepChr( char ch, int ct );
	// end specmain statics

	// statics from specdb.cpp
	LPSTR   zgetname( LPSTR name, LPSTR newname, int ext );
	// end specdb statics

	// statics from specfld.cpp
	//int   CompNames( void far * fld1, void far * fld2 );
	// end of specfld statics

	// statics from specfld1.cpp
	int     check_new_font( UINT font, UINT points, FONTINFO * fontlist, int * flistnum );
	char    FldAbbr( unsigned long flags );
	void    Pr2DFldName( LPFLDHDR fh, LPRRBOX *lflist, int *line_field, LPRRBOX *bflist, int *box_field, LPRRIMAGE *iflist, int *image_field, LPRRCHART *cflist, int *chart_field, CObList& listOleObjects);
	void    PrBand( int row );
	void    PrFldWid( LPMFFIELD fld );
	void    PrFormat( LPMFFIELD fld );
	// end of specfld1 statics

	// statics from specfld2.cpp
	void    PrCalc( LPMFFIELD fld );
	void    PrFldComment( LPMFFIELD fh );
	void    PrFldTyp( unsigned long flags );
	void    PrFromTot( unsigned long flags, unsigned int flags3, int rflags );
	void    PrTotal( LPMFFIELD fld );
	// end of specfld2 statics

	// statics from specsrt.cpp
	void    pyn( int ss, int lgt, int yes );
	void    PrSortBrk( int n );
	// end of specsrt statics

	// statics from specopt.cpp
	int     BigHead( LPSTR str, int val );
	int     Prchit( LPSTR str, int val );
	BOOL    PrCollate( LPSTR pszLabel, int ind );
	int     PrDrv( LPSTR str, int n );
	void    PrExpBand( int band );
	void    PrExports( void );
	int     PrLabel( LPSTR str, int n );
	int     PrLNOpt( LPSTR str, int n );
	int     PrMOpt( LPSTR str, int n );
	int     PrNOpt( LPSTR str, int n );
	int     PrNOptP( LPSTR str, int n );
	int     PrOOpt( LPSTR str, int n );
	BOOL    PrPaperSource( LPSTR pszLabel, int ind );
	int     PrPLen( LPSTR str, int n );
	BOOL    PrPrintToFile( LPSTR pszLabel, int ind );
	int     PrPtOpt( LPSTR str, int n );
	int     PrRCOpt( LPSTR str, int n );
	int     PrVPtOpt( LPSTR str, int n );
	int     PrYNOpt( LPSTR str, int n );
	int     RecDir( LPSTR str, int val );
#if !defined RSW
	int     PrSOpt( LPSTR str, int n );
#endif
	// end of specopt statics

#if defined (RSW)
	// statics from sspec.cpp
	void    FldType( unsigned long flags );
	void    PrMemo( LPSTR head, LPMFFILE file );
	void    PrWWrap( LPSTR head, LPSTR str, int indent, int startnew, int ind2 );
	// end of sspec statics
#else
	// statics from xspec.cpp
	void    PrKeyExp( LPMFFILE file );
	void    PrNdxTyp( char type );
	void    PrRecCt( LPMFFILE file );
	// end of xspec statics
#endif
	//// end of Report Specification routines ////
};

#ifndef _DEBUG  // debug version in rrview.cpp
inline CRrDoc* CRrView::GetDocument()
   { return (CRrDoc*)m_pDocument; }
#endif

#undef _RRVIEW_H_

#endif  // #ifndef _RRVIEW_H_

