// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   bandview.h  $
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
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/bandview.h_v  $
// 
//    Rev 1.14   05 Mar 1997 17:31:54   jpb
// equitrac runtime scripting support
// 
//    Rev 1.13   12 Jan 1996 16:10:04   sbc
// Remove some variables
// 
//    Rev 1.12   11 Dec 1995 13:24:50   sbc
// Move bandText() to CRrDoc
// 
//    Rev 1.11   05 Dec 1995 11:17:14   par
// All point interfaces to the band view need to be adjusted for the presence
// of the horizontal ruler.
// 
//    Rev 1.10   29 Aug 1995 12:23:54   sbc
// Get rid of BandRgn
// 
//    Rev 1.9   07 Aug 1995 10:08:08   mjs
// Fix GPF (Init function).
// 
//    Rev 1.8   02 Aug 1995 09:10:38   sbc
// Remove globally defined functions
// 
//    Rev 1.7   27 Jul 1995 14:23:50   sbc
// New stuff
// 
//    Rev 1.6   27 Jul 1995 11:35:20   sbc
// Add some member functions
// 
//    Rev 1.5   26 Jul 1995 15:47:00   pjm
// Added BandRect and BandRgn.
// 
//    Rev 1.4   24 Jul 1995 16:39:54   smh
// Declared CRrDoc.
// 
//    Rev 1.3   24 Jul 1995 10:36:26   smh
// protect against multiple includes of this header.
// 
//    Rev 1.2   20 Jul 1995 14:58:38   sbc
// Fix PSTR
// 
//    Rev 1.1   11 Jul 1995 12:53:18   sbc
// Changes for classification of globals and functions
// 
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _BANDVIEW_H_

//
// Make a definition for this module.
//
#define _BANDVIEW_H_

// bandview.h : header file
//

class CRrDoc;

/////////////////////////////////////////////////////////////////////////////
// CBandView view

#define DEFAULT_BAND_WIDTH	80

class CBandView : public CView
{
	DECLARE_DYNCREATE(CBandView)
protected:
	CBandView();	// protected constructor used by dynamic creation

// Operations
public:
	int m_nBandWidth;
	//// from WBAND.H:
	char createNewPage;
	BOOL bDragTop;
	////
private:
	BOOL m_leftMouseDown;
	BOOL m_rightMouseDown;
	int m_bottomLine;
	int m_topLine;
	CRrDoc *m_pDoc;		// set at creation

	// statics from dljust.cpp:
public:
//	int m_lcr;	// moved to CRrDoc so can share with 2D alignment
//	int m_helpCode;
private:
	int endPix(int line);
	void shift(int line, int val, int lcr);
	int startPix(int line);

	// statics from wledit.cpp:
	int lastY;
	int minY;
	BOOL scrolled;
	int sizeLine;
	// static functions from wledit.cpp:
	void checkEndRow();
	void checkFreeformMin(BOOL doit, int line, long hite, BOOL top);
	int countLineTypes(int *autos, int *frees);
	int findTopmostLine(void);
	BOOL twoDimOnLine(int line);
	BOOL twoDimOnMarkedLine(void);
	CRect GetHorzRulerRect() ;
public:
	CRrDoc* GetDocument();

	void Init(void);
	void cntMarkedBands(void);
	void dispBands(CDC *pDC);
	void dispFreeformBorders(CDC *pDC);
	void drawArrow(CDC *pDC, int y, BOOL top);
	int  getIniBandWidth(void);
	void nonClientBandMove(POINT point);
	void bandMove(int line);
	void endBandMark(void);
	void endKeyBand(BOOL bMouseClear);
	void saveBandWidth(void);
	void setBandWidth(int width);
	void setIniBandWidth(int width);
	void startKeyBand(BOOL bClear);
	BOOL startMouseBand(POINT point, BOOL bClear);
	void updateBandView(void);
	
	virtual ~CBandView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

//// Function prototypes from WBAND.H:
	void moveFreeformLine(POINT point);
	void scrollFreeformLine(POINT point);
	void toggleLineType(void);
	void lineFormat(void);
	void showAutoButton(void);
	BOOL clrBandMark(void);
	int onFreeformBorder(POINT point);
	void lineInsert(void);
	int sizeFreeformLine(POINT point);
	void lineJustify(void);
	void frameBand(void);
	void bandLineCreate(void);
	void bandMouseMove(POINT point);
	int autoLineHite(int line);
	void endFreeformSize(void);
////

	BOOL markBandLineFlds(int line, BOOL bMark);

	virtual void OnActivateView(BOOL bActivate, CView*, CView*);
	virtual	void OnDraw(CDC* pDC);		// overridden to draw this view
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);

	// Generated message map functions
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//{{AFX_MSG(CBandView)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#ifndef _DEBUG  // debug version in rrview.cpp
inline CRrDoc* CBandView::GetDocument()
   { return (CRrDoc*)m_pDocument; }
#endif

#endif
