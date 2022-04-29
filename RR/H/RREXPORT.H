// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   RREXPORT.H  $
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
// $Log:   D:/R&R Project/archives/H/RREXPORT.H_V  $
// 
//    Rev 1.25   25 Aug 2004 07:54:00   Nick
// Version 10.5
// 
//    Rev 1.24   02 Jul 2004 13:30:28   Nick
// ExportChart, etc.
// 
//    Rev 1.23   Oct 03 2003 10:11:50   Admin
// Globalize bIgnoreMargins
// 
//    Rev 1.22   May 13 2003 14:14:58   Admin
// Version 10.1
// 
//    Rev 1.21   Mar 22 2001 11:09:48   nhubacker
// Bursting
// 
//    Rev 1.20   Mar 22 2001 10:59:52   nhubacker
// Bursting
// 
//    Rev 1.19   Feb 27 2001 15:41:00   nhubacker
// Bursting
// 
//    Rev 1.17   May 17 2000 14:16:06   ksinkel
// Disabled ViewResultSet in the runtime version. It will now only be compiled into the RRW or RSW report designer versions.
// 
//    Rev 1.16   May 15 2000 14:12:20   ksinkel
// Modified to implement extended ViewResultSet feature.
// 
//    Rev 1.15   Apr 12 2000 17:18:40   ksinkel
// Final result set changes
// 
//    Rev 1.14   Apr 11 2000 16:52:40   ksinkel
// Added new result set  export type.
// 
//    Rev 1.13   Mar 30 2000 11:55:14   ksinkel
// More result set changes
// 
//    Rev 1.12   Mar 23 2000 15:57:02   ksinkel
// added View result set feature
// 
//    Rev 1.11   Mar 13 2000 16:07:34   ksinkel
// Export result set as DBF file
// 
//    Rev 1.10   05 May 1997 15:13:18   par
// Removed A L I V E (spacing prevents search hits) and PDI _ EXPORT conditionals.
// From this point forward, this code will always be included in build.
// 
// 
//    Rev 1.9   24 Mar 1997 09:53:20   smh
// PDI export flags.
// 
//    Rev 1.8   05 Mar 1997 13:13:40   sp
// removed conditional so that the runtime can use the browser view of an 
// exported HTML file as in the designer
// 
//    Rev 1.7   04 Mar 1997 16:03:04   sp
// added support for browser display of an html export file
// 
//    Rev 1.6   27 Feb 1997 15:22:04   jsf
// changed expSendMAPI() to use LPTSTR instead of LPCTSTR so that
// we can use the correct mapi.h
// 
//    Rev 1.5   10 Feb 1997 10:02:28   sp
// Arp Live merge to trunk
// 
//    Rev 1.3.1.1   07 Jan 1997 13:31:38   smh
// SteveC: Write image names to INI for PDI export and Live
// 
//    Rev 1.3.1.0   18 Oct 1996 12:33:10   smh
// PDI export implementation
// 
//    Rev 1.1.1.2   26 Sep 1996 11:51:36   sjo
// Added HTML structure to the export structure union (smh for sjo).
// 
//    Rev 1.1.1.1   24 Aug 1996 10:33:32   smh
// Added dbx_memoRead.
// 
//    Rev 1.1.1.0   30 Jul 1996 16:51:22   sjo
// This is the first round of HTML export changes.  On the U02 branch I am
// putting the code in A L I V E conditionals so that we develop the code on the
// U02 branch but not effect the build of that product.
// 
//    Rev 1.1   05 Jan 1996 16:31:22   par
// All explicitly linked modules and external initialization files are located
// with the explicit file manager.  This will provide a central location where
// file paths can be adjusted.
// 
//    Rev 1.0   05 Dec 1995 18:50:32   jpb
// Initial revision.
// 
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _RREXPORT_H_

// Make a definition for this module.
//
#define _RREXPORT_H_

// rrexport.h : interface of the CRrExport class
//
/////////////////////////////////////////////////////////////////////////////

#include "smapi.h"

class CRrExport : public CObject
{
	DECLARE_DYNAMIC(CRrExport) ;
	
			CRrExport(CRrDoc* pDoc);	// constructor
	virtual	~CRrExport();			// destructor
	
	CRrDoc*	m_pDoc ;

public:
	HANDLE	m_hPDIFile;			// output file handle
	int		m_nPDIExpFlags;		// flags
 #if !defined(INTERACTIVE)
	// temporary image pathname list file (for Alive)
	TCHAR	szImageIniPath[WINPATHLEN];
	// number of images actually exported
	int		nImagesExported;
 #endif
	//// From PRINT\rpexport.cpp - functions:
public:
	int	dbx_rprint( void );

	//// Static functions from PRINT\rpexport.cpp:
private:
	int		dbx_fillLine( int crow, int when, int printline );
	int		dbx_lasttotals( void );
	int		dbx_prSection( int when, int pgroom );
	int		dbx_prtrep( void );
	BOOL	dbx_rpSetup( int type );
	int		dbx_setup( void );
	BOOL	dbx_memoRead( LPMFFIELD mf, LPSTR * databuf, LPSTR dataloc );

	// result set functions and variables
	int		resultset_rprint( void ); // sets up printing, 
	int		resultset_prtrep( void ); // gets records and prints calls prSection for ea section of report
	int		resultset_prSection( int when, int pgroom ); // originally prints a section of bands at a time
	int		resultset_fillLine( int crow, int when, int printline );
	static BOOL	isSortField(FLDID fld, CRrDoc *pDoc);
	static BOOL CRrExport::isLinkField(FLDID fld, CRrDoc* pDoc);
	BOOL	 CRrExport::isQueryField(FLDID fld);

	PKSX*	m_pksxarray;
	int		m_pksxcnt;
	fieldhdr* m_lastfield;

	fieldhdr* m_insertedfields[100];
	int		m_insertedfieldsindx;

	//// Public data from dbexport.h
public:
	CSV_EXPORT CsvWordExport;
	CSV_EXPORT CsvExport;
	HTML_EXPORT	HtmlExport;
	//// Public data from _wprintu.h
public:
	LPDBEXP			DbfXStr;

	//// Public data from wprintui.h
public:
#if !defined INTERACTIVE
	int		RpEscape;
#endif
	//// Public functions from _wprintui.h
public:
	static BOOL CALLBACK exp_GoodField(LPSTR field);
	static BOOL CALLBACK exp_GoodFieldAnyBand(LPSTR field);

	static BOOL CALLBACK exp_NoValue(LPSTR fld, LPSTR data);
	static BOOL CALLBACK dbfx_GetFieldInfo(LPSTR field, LPDBXFLD fs);
	static BOOL CALLBACK txtx_expInitPrt(LPFNPWINIT lpfnInit);
	static BOOL CALLBACK wksx_GetFieldInfo(LPSTR field, LPDBXFLD fs);
	static BOOL CALLBACK csvx_GetFieldInfo(LPSTR field, LPDBXFLD fs);
// below appears unused:
//	int expInitPrt(int (__far __pascal *lpfnInit)(struct prtstruct __far *,struct prt_init __far *,const char __far *,const char __far *,const char __far *));
	
	//// Private data from _wprintui.h
private:
	LPFNDBXSTORE	lpfnStore;
	FARPROC			lpfnGoodField;
	FARPROC			lpfnNoValue;
	LPFNDBXCREATE	lpfnCreate;
	LHANDLE			lhSession;
	enum { piecesize = 1000 };					// a memo piece

	//// Public data from wexport.cpp (both were statics)
public:
	BOOL			bCalldbClose;

	//// WPRINTUI

	// Public routines from WPRINTUI
public:
	BOOL	createExportFile( void );
	int	    ExportFileCreation(void);
	BOOL	m_bUseBandFilter; // TRUE by default -- FALSE only for special dbx all-band export - k.s.
	BOOL	exportChart( BOOL dialog, BOOL bUseBandFilter = TRUE);
	BOOL	exportPivotTable( BOOL dialog, BOOL bUseBandFilter = TRUE);
	BOOL	exportReport( BOOL dialog, BOOL bUseBandFilter = TRUE);
	BOOL	BurstingExportReport( BOOL dialog, BOOL bUseBandFilter = TRUE);
	void	setMapiAddress(void) ;
	void	setMapiSubject(void) ;
#if defined (INTERACTIVE)
	BOOL	viewResultSet(BOOL bOverwriteFile);
#endif
	void	setExpDefs( void );

// sp 3/4/97 added for viewing exported HTML in browser after export
	void	PreviewHtml(CString csExportFilename);

	// Private routines from WPRINTUI
private:
	BOOL	exp_fill_field_list( LPFLDHDR** field_list );
	BOOL	exp_fill_field_list_anyband( LPMFFIELD** field_list ); 
	BOOL	exp_check_file_name( LPSTR filename );
	BOOL	checkDuplicateDBFFields() ;
static BOOL CALLBACK duplicateDBFDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam ) ;

	// statics from wexport.cpp
	void	init_csv_struct( void );
//	#if defined (INTERACTIVE)
	BOOL	expSendMAPI( LPSTR lpszPath );
	BOOL	MAPILogon();
//	#endif

	// from dfile.h
public:
	EXPORTINFO	ExportTypes[NUMEXPTYPES];
	// from global.h
	TCHAR  ExportType;				// report export type
	TCHAR  ExpDbfBand;
	TCHAR  ExpWksBand;
	TCHAR  ExportFlags; 			// init report export flags to ANSI & Every

public:
static BOOL CALLBACK DbfDlgProc  ( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
static BOOL CALLBACK WksDlgProc  ( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
static BOOL CALLBACK TextDlgProc ( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
static BOOL CALLBACK RtfDlgProc  ( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
static BOOL CALLBACK Html2DlgProc( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
static BOOL CALLBACK CSVDlgProc  ( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
static BOOL CALLBACK WordDlgProc ( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );

private:
	BOOL	dbfOnExport ( HWND hDlg, WPARAM wParam, BOOL bDoExport );
	BOOL	wksOnExport ( HWND hDlg, WPARAM wParam, BOOL bDoExport );
	BOOL	txtOnExport ( HWND hDlg, WPARAM wParam, BOOL bDoExport );
	BOOL	rtfOnExport ( HWND hDlg, WPARAM wParam, BOOL bDoExport );
	BOOL	htmlOnExport( HWND hDlg, WPARAM wParam, BOOL bDoExport );
	BOOL	csvOnExport ( HWND hDlg, WPARAM wParam, int ExpType, BOOL bDoExport );
	BOOL	dbfWM_Command ( HWND hDlg, WPARAM wParam );
	BOOL	wksWM_Command ( HWND hDlg, WPARAM wParam );
	BOOL	txtWM_Command ( HWND hDlg, WPARAM wParam );
	BOOL	rtfWM_Command (HWND hDlg, WPARAM wParam);
	BOOL	htmlWM_Command(HWND hDlg, WPARAM wParam);
	BOOL	csvWM_Command ( HWND hDlg, WPARAM wParam );
	BOOL	wordWM_Command( HWND hDlg, WPARAM wParam );
	BOOL	dbfWM_Init ( HWND hDlg, WPARAM wParam, LPARAM lParam );
	BOOL	wksWM_Init ( HWND hDlg, WPARAM wParam, LPARAM lParam );
	BOOL	txtWM_Init ( HWND hDlg, WPARAM wParam, LPARAM lParam );
	BOOL	rtfWM_Init (HWND hDlg, WPARAM wParam, LPARAM lParam);
	BOOL	htmlWM_Init(HWND hDlg, WPARAM wParam, LPARAM lParam);
	BOOL	csvWM_Init ( HWND hDlg, WPARAM wParam, LPARAM lParam );
	BOOL	wordWM_Init( HWND hDlg, WPARAM wParam, LPARAM lParam );

	// static data from dexport.cpp
private:
	int		iNumberOfReportExportTypes;
	int		iNumberOfINIExportTypes;
	int		iLastExportHandle;
	char	m_sTextExpFile[MAX_PATH + 1];
	char	m_sDBFExpFile[MAX_PATH + 1];

	// static routines from dexport.cpp
private:
	BOOL	WM_InitExport( HWND hDlg );
	BOOL	WM_ExportCommand( HWND hDlg, WPARAM wParam, LPARAM lParam );
	BOOL	OnButtonExportMessage( HWND hDlg );
	BOOL	OnListBoxMessage( HWND hDlg, WPARAM wParam, LPARAM lParam );
	BOOL	Button_ExportOptions( HWND hDlg );
	void	show_MAPI( HWND hDlg );
	BOOL	SupportsMAPI( HWND hDlg );
		// The following set of functions set up the export list.
	BOOL	AddPredefinedExports( HWND hDlg, int idListBox );
	BOOL	AppendReportExports( HWND hDlg, int idListBox );


	BOOL	WM_InitMapiOptions( HWND hDlg );
	BOOL	WM_MapiOptionsCommand( HWND hDlg, WPARAM wParam, LPARAM lParam );
	int		initFldList(HWND hDlg, int id, FLDID fldid, int (*ck)(LPMFFIELD), BOOL combo);


	// dialog & other public routines from dexport.cpp
public:
static	BOOL CALLBACK exportDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
		BOOL	AppendINIExports( HWND hDlg, int idListBox );
static	BOOL CALLBACK mapiOptions( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );


// burst report functions
	int burstReport(char* exportFilename);
	int burstReportByQuery(char* exportFilename, int fldid, char* values, int nValues);
	int addQueryField(int fldid, char* value);
	int modQueryField(int fldid, char* value);
	int delQueryField(int fldid, char* value);

};
#endif

