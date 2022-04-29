// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   rstatbar.h  $
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
// $Log:   H:/vcsmfc/h/rstatbar.h_v  $
// 
//    Rev 1.9   04 Oct 1995 10:00:50   smh
// Use PANE1_LEN constant for m_Pane1Text
// 
//    Rev 1.8   18 Aug 1995 14:49:54   mjs
// Removed global.h
// 
//    Rev 1.7   03 Aug 1995 11:51:48   sbc
// Change argument
// 
//    Rev 1.6   02 Aug 1995 09:43:44   sbc
// Stick a public: at top of class declaration
// 
//    Rev 1.5   02 Aug 1995 09:30:10   sbc
// Remove DECLARE_DYNAMIC
// 
//    Rev 1.4   28 Jul 1995 13:23:50   mjs
// Made m_Pane1Text public for now so mainfrm.cpp can compile.
// 
//    Rev 1.3   28 Jul 1995 09:05:24   sbc
// Add routine to get status text
// 
//    Rev 1.2   27 Jul 1995 14:54:08   sbc
// Add doc pointer
// 
//    Rev 1.1   27 Jul 1995 11:24:56   mjs
// Needs wmain.h
// 
//    Rev 1.0   17 Jul 1995 17:19:48   sbc
// Initial revision.
// 
// Initial revision.
// 
// ****************************************************************************
//
// Make a definition for this module.
//
#define _RSTATBAR_H_

#include "globals.h"	// For MESS_LEN

// RSTATBAR.H - R&R Status bar class definition
//

class RrStatusBar : public CStatusBar
{
//	DECLARE_DYNCREATE(RrStatusBar)
//protected:
public:
	RrStatusBar();			// protected constructor used by dynamic creation
	virtual ~RrStatusBar();

// Attributes
public:
	char 	m_Pane1Text[PANE1_LEN + 1];	// Line/inch pane.  (public for mainfrm.cpp; should be changed.)
private:
	BOOL	m_bMessageBar;		// are we in MessageBar mode, with no panes?
	LPSTR	m_pHelpMessage;		// current string in MessageBar.
	char	m_StatusMess[MESS_LEN + 1];		// message buffer
	CRrDoc *m_pDoc;			// set doc pointer from the get go...

// Operations
private:
	void 	checkMessageMode(void);
	void 	CopyStatusMessage (LPSTR lpszText, int iTextLength, LPSTR lpszMessage);
	BOOL 	logicalLines();
	void 	statMess(LPSTR message,BOOL alert);
public:
	void 	alertMessage(LPSTR message);
	void 	cleanupStatusBar(void);
	BOOL 	cursorInStatusBar(POINT point);
	void 	dispStatus(void);
	void 	fPrompt (LPFLDHDR f, BOOL doit);
	LPSTR	GetPane0Text(LPSTR pText);
	BOOL 	GetPromptText(LPFLDHDR f, LPSTR lpszText, int iTextLength);
	void 	initStatusBar(CRrDoc *);
	void 	SetPane0Text(LPSTR text);
	void 	SetStatusMode(BOOL bHelp);
	void 	showLibrary(void);
	void 	statusHelp(LPSTR str);
	void 	statusInfo(BOOL bDraw);
	void 	statusMessage(LPSTR message);
	void 	setStatusPaneText(int pane, LPSTR text, BOOL alert);
};

