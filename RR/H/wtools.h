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
// $Log:   D:/R&R Project/archives/H/WTOOLS.H_V  $
// 
//    Rev 1.14   02 Jul 2004 13:35:36   Nick
// Cut deadwood
// 
//    Rev 1.13   Mar 08 2001 16:21:10   nhubacker
// Field Names button
// 
//    Rev 1.12   Feb 02 2000 13:54:30   nhubacker
// Added #defines for 2 new toolbar buttons (KS)
// 
//    Rev 1.11   31 Jan 1996 14:20:22   sbc
// Put back BOOL arg for PointSizeCheck
// 
//    Rev 1.10   29 Jan 1996 20:53:24   sbc
// Remove argument from function
// 
//    Rev 1.9   13 Oct 1995 10:37:02   par
// Replace internal tooltips code with MFC code.
// 
//    Rev 1.8   27 Jul 1995 10:01:06   sbc
// Make char array near
// 
//    Rev 1.7   26 Jul 1995 14:21:12   mjs
// PSTR -> LPSTR.
// 
//    Rev 1.6   24 Jul 1995 09:39:20   smh
// Added declaration of CRrDoc.
// 
//    Rev 1.5   17 Jul 1995 14:14:06   mjs
// Tooltips stuff.
// 
//    Rev 1.4   06 Jul 1995 16:29:30   mjs
// Forward declaration of CMainFrame.
// 
//    Rev 1.3   06 Jul 1995 15:26:06   mjs
// Put toolbar and formbar classes here, made member fns and vars.
// 
//    Rev 1.2   26 Apr 1995 14:40:10   pjm
// Fixed merge error.
// 
//    Rev 1.1   26 Apr 1995 13:29:36   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.0   16 Mar 1995 16:14:06   sbc
// Initial revision.
// 
//    Rev 1.21   31 Jan 1995 12:34:22   sbc
// Changes to make tooltips available in runtime
// 
//    Rev 1.20   15 Jul 1994 09:42:42   sbc
// Change some args
// 
//    Rev 1.19   08 Jul 1994 14:40:52   sbc
// Remove arg to setToolHelp()
// 
//    Rev 1.18   07 Jul 1994 10:22:26   sbc
// Change args
// 
//    Rev 1.17   20 Jun 1994 16:25:00   sbc
// MS Office changes
// 
//    Rev 1.16   15 Jun 1994 11:44:24   sbc
// Move action bar help here
// 
//    Rev 1.15   13 Jun 1994 15:06:10   sbc
// New routine for tool help
// 
//    Rev 1.14   02 Jun 1994 04:28:52   sbc
// Change args to tool help routine
// 
//    Rev 1.13   09 May 1994 13:53:40   sbc
// Changes/additions for tool help delay
// 
//    Rev 1.12   25 Apr 1994 09:30:14   sbc
// Swap line auto/freeform and snap buttons
// 
//    Rev 1.11   22 Apr 1994 16:04:18   sbc
// Make TOOLSEP = ACTIONSEP
// 
//    Rev 1.10   22 Apr 1994 10:46:58   sbc
// Enlarge format bar
// 
//    Rev 1.9   22 Apr 1994 09:11:56   sbc
// New function for tool help
// 
//    Rev 1.8   21 Apr 1994 11:49:08   sbc
// Changes for format bar size, etc.
// 
//    Rev 1.7   21 Apr 1994 09:41:58   sbc
// Tool help changes
// 
//    Rev 1.6   20 Apr 1994 16:34:46   sbc
// Tool help
// 
//    Rev 1.5   20 Apr 1994 11:18:40   sbc
// Changes for new MS look.  Also, drop format bar controls down a pixel.
// 
//    Rev 1.4   08 Apr 1994 11:32:48   mjs
// Changed proto for showToolBar.
// 
//    Rev 1.3   05 Apr 1994 14:17:26   mjs
// Added globals for tool help.
// 
//    Rev 1.2   02 Mar 1994 11:04:28   mjs
// Add prototypes for MFC versions of showTool/FormBar.
// 
//    Rev 1.1   19 Nov 1993 17:41:30   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:11:12   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _WTOOLS_H_

//
// Make a definition for this module.
//
#define _WTOOLS_H_

#if defined(_TOOLTIPS_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif

class CMainFrame;	// Pointer to this stored in classes below.
class CRrDoc;

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.

#if 0
// Obsolete in v7.
// Action Bar parameters
#define TOOLBUTTONS				18
#define ACTIONSEP				7
#define ACTION_TOP				3
#define ACTION_HEIGHT			22
#define ACTION_WIDTH			23
#define COMBO_BUTTON_SEP		12
#define COMBO_COMBO_SEP			9
#define BUTTON_HEIGHT			22
#define BUTTON_WIDTH			23
#define COMBO_TOP				4	
#define COMBO_DEPTH				150
#define FONT_COMBO_WIDTH		140
#define PTS_COMBO_WIDTH			70
#endif

#define ACTION_BAR_DEPTH		28
// index of SQL Select button
#define ACTION_BAR_SQL_INDEX	11

// Format Bar  parameters
#define FORMAT_BAR_DEPTH		28
#define ATTS					3
#define BUTT_TOP				3
#define JLEFT					ATTS
#define JCENTER					JLEFT+1
#define JRIGHT					JCENTER+1
#define JFULL					JRIGHT+1
#define JUSTS					4
#define NUMTOOLS				14
#define TOOLLEFT				6
#define TOOLSEP					7

#define TOOL_BOLD				0
#define TOOL_ITALIC				1
#define TOOL_UNDER				2
#define TOOL_JLEFT				3
#define TOOL_JCENTER			4
#define TOOL_JRIGHT				5
#define TOOL_JFULL				6
#define TOOL_TRIM				7
#define TOOL_TRASH				8
#define TOOL_AUTO				9
#define TOOL_SNAP				10
#define TOOL_SUPPRESSRECORD		11
#define TOOL_COMPRESSRECGROUP	12
#define TOOL_FIELDNAMES			13
#define TOOL_UNDO				14

// button states
#define BUTT_NORMAL				0
#define BUTT_ON					1
#define BUTT_MIX				2
#define BUTT_DEPRESSED			3

#define TIMER_ID				100

// Timer delays (as per MS Office spec)
#define HELP_LONG_DELAY			700	// 700 ms
#define HELP_SHORT_DELAY		100	// 100 ms

// MS Office placement values
#define BUTTON_LEFT_BIAS		-2	// left of hot spot
#define BUTTON_TOP_BIAS			18	// below hot spot

//
// Structure Section:
// Place in this section any structure definitions.
//

#if 0
// Obsolete in v7.  All others moved to mainfrm.h.
typedef struct actionBar
{
	HICON	hIcon[2];
	WORD	id;
	WORD	x,y;
} A_BAR;
#endif

typedef struct formatBar
{
//	HICON	hIcon[4];
//	WORD	id;
	BOOL	enabled;
	int		state;
//	WORD	x,y;
} F_BAR;

//
// Global Data Section:
// Place in this section any global data.
//

#if 0
// Obsolete in v7.  All others moved to mainfrm.h.
GLOBAL A_BAR Actions[TOOLBUTTONS];			/* action bar buttons */
#endif

//  mjs 7/5/95  Move all Wx's into non-translatable string table later.
GLOBAL char near WxToolHelp[] 
#if defined _TOOLBARS_C_
 = "ToolHelp"
#endif
;

//
// Function Prototypes Section:
// Place in this section any function prototypes
//


// Instead of using a class here we could have just put these controls
// directly into CMainFrame.  As it is they are sending messages to the
// main frame just like they were part of it instead of part of a control
// bar.
class CFormBar : public CToolBar
{
public:
	UINT nButtons;

	CComboBox   	m_comboFont;
	CComboBox   	m_comboPoint;
	CFont       	m_font;
	CMainFrame* 	m_pFrame;	// So we only do (CMainFrame*)AfxGetMainWnd() once in constructor.

	// Former globals from wtools.h
private:
	F_BAR Tools[NUMTOOLS];	 	// format bar buttons 
	int bstate;
	int istate;
	int tstate;
	int ustate;

	// From formbar.cpp
private:
	int font;
	int points;
	int scalable;
	int allwrap;

	// From formbar.cpp
public:
	void 		Enable();
	void		BarFontChange();
	BOOL		Check(WPARAM wParam, LPARAM lParam);
private:
	CRrDoc* 	GetDocument(void);
	int 		FieldCount();
	void 		SameStuff();
   int  		PointStrAdd(LPSTR buf,int pts);
	void  		PointSizeSet();
	void  		PointSizeCheck( BOOL );
	void  		CurFontSet();


public:
	// Access functions now that bstate, Tools, etc. are private.
	int BoldStateGet() {return bstate;}
	int ItalicStateGet() {return istate;}
	int UnderStateGet() {return ustate;}
	void ToolStateSet(int tool, int state) {Tools[tool].state = state;}
	int ToolStateGet(int tool) {return Tools[tool].state;}
	int ToolEnabledGet(int tool) {return Tools[tool].enabled;}	

	//{{AFX_MSG(CFormBar)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#undef GLOBAL

#endif // end _WTOOLS_H_

// *************************** End of File ************************************
