// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   script.h  $
// ================
//
// Description:
// ============
//
// Script reader class header
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/script.h_v  $
// 
//    Rev 1.13   14 Mar 1997 14:38:34   jpb
// equitrac runtime scripting support
// 
//    Rev 1.12   12 Mar 1997 14:25:52   jpb
// equitrac runtime scripting support
// 
//    Rev 1.11   08 Oct 1996 16:50:22   amh
// Arp 1.0 U02 merged to trunk
// 
// 
// 
//    Rev 1.9.1.0   05 Sep 1996 17:55:26   jpb
// script changes
// $Log$
// 
//    Rev 1.10   29 Sep 1996 15:17:32   jpb
// merge U02 changes
// 
//    Rev 1.9   17 Nov 1995 10:36:56   mjs
// Changed file i/o
// 
//    Rev 1.8   08 Nov 1995 13:54:32   sbc
// Change COMMONFLD->location from WORD to int
// 
//    Rev 1.7   02 Aug 1995 12:40:18   sbc
// Remove creation macros
// 
//    Rev 1.6   02 Aug 1995 09:11:58   sbc
// Remove message map
// 
//    Rev 1.5   28 Jul 1995 09:56:26   sbc
// Add a (ridiculous) app pointer
// 
//    Rev 1.4   20 Jul 1995 13:48:58   sbc
// Classify the script reader
// 
// Initial revision.
// 
// ****************************************************************************

//
// Make a definition for this module.
//
#ifndef _SCRIPT_H_
//
// Make a definition for this module.
//
#define _SCRIPT_H_

/////////////////////////////////////////////////////////////////////////////
// line terminators
#define CR			13
#define LF			10
#define MAX_LINE	300	// max line length

// define some misc parameter values
#define PAGE_LENGTH_MAX			3
#define NUM_FLD_PIC_MAX			5
#define DATE_FLD_PIC_MAX		23
#define TIME_FLD_PIC_MAX		8
#define MAX_TOTAL_FULL			6

// parameter handlers and their IDs
//BOOL masterHandler(PSTR pParam);
#define MASTERHANDLER		0
//BOOL menuHandler(PSTR pParam);
#define MENUHANDLER			1
//BOOL pageLengthHandler(PSTR pParam);
#define PAGELENGTHHANDLER	2
//BOOL topMarginHandler(PSTR pParam);
#define TOPMARGINHANDLER	3
//BOOL bottomMarginHandler(PSTR pParam);
#define BOTTOMMARGINHANDLER	4
//BOOL leftMarginHandler(PSTR pParam);
#define LEFTMARGINHANDLER	5
//BOOL rightMarginHandler(PSTR pParam);
#define RIGHTMARGINHANDLER	6
//BOOL landscapeHandler(PSTR pParam);
#define LANDSCAPEHANDLER	7
//BOOL interlineHandler(PSTR pParam);
#define INTERLINEHANDLER	8
//BOOL averyLabelHandler(PSTR pParam);
#define AVERYLABELHANDLER	9
//BOOL recordsAcrossHandler(PSTR pParam);
#define RECORDSACROSSHANDLER	10
//BOOL recordWidthHandler(PSTR pParam);
#define RECORDWIDTHHANDLER	11
//BOOL recordHeightHandler(PSTR pParam);
#define RECORDHEIGHTHANDLER	12
//BOOL compressBodyGroupHandler(PSTR pParam);
#define COMPRESSRECGRPHANDLER	13
//BOOL suppressRecordHandler(PSTR pParam);
#define SUPPRESSRECORDHANDLER	14
//BOOL beginSemiHandler(PSTR pParam);
#define BEGINSEMIHANDLER	15
//BOOL hfSummaryHandler(PSTR pParam);
#define HFSUMMARYHANDLER	16
//BOOL breakRecordHandler(PSTR pParam);
#define BREAKRECORDHANDLER	17
//BOOL charFieldHandler(PSTR pParam);
#define CHARFIELDHANDLER	18
//BOOL numFieldHandler(PSTR pParam);
#define NUMFIELDHANDLER		19
//BOOL textFieldHandler(PSTR pParam);
#define TEXTFIELDHANDLER	20
//BOOL calcCharHandler(PSTR pParam);
#define CALCCHARHANDLER		21
//BOOL calcNumHandler(PSTR pParam);
#define CALCNUMHANDLER		22
//BOOL dateFieldHandler(PSTR pParam);
#define DATEFIELDHANDLER	23
//BOOL calcDateHandler(PSTR pParam);
#define CALCDATEHANDLER		24
//BOOL previewZoomHandler(PSTR pParam);
#define PREVIEWZOOMHANDLER	25
//BOOL printColsHandler(PSTR pParam);
#define PRINTCOLSHANDLER	26
//BOOL dateTimeFldHandler(PSTR pParam);
#define DATETIMEFLDHANDLER	27
//BOOL timeFldHandler(PSTR pParam);
#define TIMEFLDHANDLER		28
//BOOL calcDateTimeHandler(PSTR pParam);
#define CALCDATETIMEHANDLER	29
//BOOL calcTimeHandler(PSTR pParam);
#define CALCTIMEHANDLER		30
//BOOL pointSizeHandler(PSTR pParam);
#define POINTSIZEHANDLER	31
//BOOL textFileHandler( PSTR pParam );
#define TEXTFILEHANDLER		32
#if 0	// don't support ReportLibrary in 32 bit versions
//BOOL repLibHandler( PSTR pParam );
#define REPLIBHANDLER		33
#endif
//BOOL repNameHandler( PSTR pParam );
#define REPNAMEHANDLER		34
//BOOL newPageHandler(PSTR pParam);
#define NEWPAGEHANDLER		35
#define DATASOURCEHANDLER	36
#define USERNAMEHANDLER		37
#define PASSWORDHANDLER		38
///////////////////////////////////////////////
//
// Action Flag Values
//
#define ACTION_PREVIEW	0x1
#define ACTION_PRINT	0x2
#define ACTION_EXIT		0x4

typedef struct parameters
{
	WORD txID;			// resource text ID
	int paramHandler;	// handler routine index
} PARAMS;

typedef struct sections
{
	WORD txID;			// resource text ID
	int band;			// band id when appropriate
	PARAMS *params;		// valid section parameters
} SECTIONS;

// use the larger of these...
#if (FLMAX > MAXDNAME)
#define MAX_SCRIPT_FLD_NAME	FLMAX
#else
#define MAX_SCRIPT_FLD_NAME	MAXDNAME
#endif

typedef struct commonFieldStuff
{
	LPMFFIELD f;		// database pointer
	char name[MAX_SCRIPT_FLD_NAME + 1];
	char trim;
	int location;
	char alignment;
	char style;
} COMMONFLD;

// generic alignment values
#define LEFT		0
#define CENTER		1      
#define RIGHT		2
#define WRAP_LEFT	3
#define WRAP_RIGHT	4
#define WRAP_JUST	5
// maximums from DPROPT.C
#define MAXACROSS	999 		// 999
#define MAXMAR		9999		// 99.99
#define MAXRECHITE	9999		// 99.99
#define MAXRECWIDTH 9999		// 99.99
// wfReadLine() return values
#define READ_OK		0
#define READ_EOF	1
#define READ_ERROR	2

#define COLUMN_PITCH	10	// canned at 10-pitch
#if defined(RSW)
#define DEF_NUM_LEN		6	// default length assigned to numeric fields in RSW
#endif

/////////////////////////////////////////////////////////////////////////////
// ScriptRead command target

class ScriptRead : public CObject
{   
//	DECLARE_DYNCREATE(ScriptRead)
//protected:
//	ScriptRead();	// protected constructor used by dynamic creation
public:
	ScriptRead(CRrDoc *);

// Attributes
public:
	int m_actionCommand;	// action to take when done
private:
	int m_lastFldCol;		// current band line column
	int m_lastPointSize;	// last point size override
	int m_scriptLineNo;		// current script line number
	int m_bandLine;			// current band line
	BOOL m_bGroupSeen;		// group field specified
	BOOL m_bNewPageLine;		// new page line in current band
	BOOL m_bFieldLine;		// fields in current band
	SECTIONS *m_currentSection;	// our current section
	LPSTR m_pToken;			// for local strtoken() routine
	CRrDoc *m_pDoc;			// current document
	CRrApp *m_pApp;			// this is ridiculous
	CFile	scriptFile;			// file i/o
		
// Operations
public:

// Implementation
public:
	virtual ~ScriptRead();
// Static routines
public:
	static BOOL averyLabelHandler(ScriptRead *, LPSTR);
	static BOOL beginSemiHandler(ScriptRead *, LPSTR);
	static BOOL bottomMarginHandler(ScriptRead *, LPSTR);
	static BOOL breakRecordHandler(ScriptRead *, LPSTR);
	static BOOL calcCharHandler(ScriptRead *, LPSTR);
	static BOOL calcDateHandler(ScriptRead *, LPSTR);
	BOOL calcDateTimeCommon(LPSTR pParam, long nFlags);
	static BOOL calcDateTimeHandler(ScriptRead *, LPSTR);
	static BOOL calcNumHandler(ScriptRead *, LPSTR);
	static BOOL calcTimeHandler(ScriptRead *, LPSTR);
	static BOOL charFieldHandler(ScriptRead *, LPSTR);
	int colFromPix(int pix);
	BOOL commonBoolHandler(LPSTR, int index);
	BOOL commonFieldCheck(COMMONFLD *cf, LPSTR pFieldStr, BOOL bDataFld, BOOL bCharFld);
	BOOL commonMeasureHandler(LPSTR, int index, int maxVal);
	static BOOL compressBodyGroupHandler(ScriptRead *, LPSTR);
	static BOOL dateFieldHandler(ScriptRead *, LPSTR);
	static BOOL dateTimeFldHandler(ScriptRead *, LPSTR);
	LPMFFIELD findDatabaseField(LPSTR name);
	static BOOL groupFieldHandler(ScriptRead *, LPSTR);
	static BOOL hfSummaryHandler(ScriptRead *, LPSTR);
	static BOOL interlineHandler(ScriptRead *, LPSTR);
	BOOL isValidParameter(LPSTR pLine, PARAMS *pParam);
	SECTIONS * isValidSection(LPSTR pSection);
	static BOOL landscapeHandler(ScriptRead *, LPSTR);
	static BOOL leftMarginHandler(ScriptRead *, LPSTR);
	LPMFFIELD makeTotal(LPSTR pParam, BOOL bLimited);
	static BOOL masterHandler(ScriptRead *, LPSTR);
	static BOOL dataSourceHandler(ScriptRead *, LPSTR);
	static BOOL userNameHandler(ScriptRead *, LPSTR);
	static BOOL passwordHandler(ScriptRead *, LPSTR);
	static BOOL menuHandler(ScriptRead *, LPSTR);
	static BOOL numFieldHandler(ScriptRead *, LPSTR);
	static BOOL pageLengthHandler(ScriptRead *, LPSTR);
	static BOOL pointSizeHandler(ScriptRead *, LPSTR);
	static BOOL textFileHandler(ScriptRead *, LPSTR);
#if 0	// don't support ReportLibrary in 32 bit version
	static BOOL repLibHandler(ScriptRead *, LPSTR);
#endif
	static BOOL repNameHandler(ScriptRead *, LPSTR);
	static BOOL newPageHandler(ScriptRead *, LPSTR);
	static BOOL previewZoomHandler(ScriptRead *, LPSTR);
	static BOOL printColsHandler(ScriptRead *, LPSTR);
	static BOOL recordsAcrossHandler(ScriptRead *, LPSTR);
	static BOOL recordHeightHandler(ScriptRead *, LPSTR);
	static BOOL recordWidthHandler(ScriptRead *, LPSTR);
	static BOOL rightMarginHandler(ScriptRead *, LPSTR);
	BOOL scriptError(LPSTR pParam);
	void setCommonFieldValues(LPMFFIELD f, int fldLen, int align, BOOL trim, int style);
	BOOL setFieldLocation(int col, LPFLDHDR f);
	int sgCommon(LPSTR pParam, WORD txID);
	static BOOL sortFieldHandler(ScriptRead *, LPSTR);
	static BOOL sortOrderHandler(ScriptRead *, LPSTR);
	LPSTR strtoken(LPSTR pStr);
	static BOOL suppressRecordHandler(ScriptRead *, LPSTR);
	static BOOL textFieldHandler(ScriptRead *, LPSTR);
	static BOOL timeFldHandler(ScriptRead *, LPSTR);
	static BOOL topMarginHandler(ScriptRead *, LPSTR);
	BOOL verifyBool(LPSTR pParam, BOOL *bTrueFalse);
	BOOL verifyMeasure(LPSTR pParam, int *nMeasure, int decimals);
	BOOL verifyNumeric(LPSTR pParam, int *nParam, BOOL *bNull);
// File I/O routines:
	void wfClose();
	BOOL wfOpen(LPSTR path, UINT maxLength);
	BYTE wfReadByte();
	int wfReadLine(LPSTR pLine);

protected:
	// Generated message map functions
	//{{AFX_MSG(ScriptRead)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
};


#endif // end _SCRIPT_H_

// *************************** End of File ************************************
