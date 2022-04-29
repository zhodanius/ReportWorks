// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   rrdll.h  $
// ================
//
// Description:
// ============
//
//	Class definition of runtime DLL's report-info class.
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/RRDLL.H_V  $
// 
//    Rev 1.21   Jul 01 2002 15:25:22   Admin
// Add getpagesize(), setpagesize()
// 
//    Rev 1.20   Apr 26 2002 15:25:20   Admin
// RRATL change
// 
//    Rev 1.19   25 May 1997 16:03:38   jpb
// set/getDBContainer()
// 
//    Rev 1.18   29 Apr 1997 16:09:32   dlm
// Change size of fieldName in FIELDFIELD structure from MAXFIELDNAME (64)
//  to MAXDNAME (129) and in TABFIELD structure from MAXSDNAME (11) to 
//  MAXDNAME.
// Part of fix to RRW bug 3036.
// 
//    Rev 1.17   25 Mar 1997 11:29:50   pjm
// Use MAXSDNAME for field name length in field structure.
// 
//    Rev 1.16   10 Feb 1997 10:02:24   sp
// Arp Live merge to trunk
// 
//    Rev 1.13.1.2   30 Dec 1996 09:49:04   smh
// Added csLangID and setLanguageID().
// 
//    Rev 1.13.1.1   05 Dec 1996 11:17:36   smh
// Added bLiveMode and setLiveMode().
// 
//    Rev 1.13.1.0   30 Oct 1996 10:18:08   dlm
// Added code, conditional on TIME_IT to time various aspects of the
//  operation of the runtime DLL.  Modules affected are RRDLL.H, RDEXEC.CPP,
//  and RDINIT.CPP.  To enable the code, build with TIME_IT defined.
// 
//    Rev 1.14   26 Nov 1996 11:34:02   jsf
// changes to set routines to allow LPCSTRs.
// This will let callers use CStrings without having to call GetBuffer().
// 
//    Rev 1.13   08 Oct 1996 16:50:08   amh
// Arp 1.0 U02 merged to trunk
// 
//    Rev 1.11.1.0   27 Aug 1996 17:31:04   dlm
// Part of fix to RSW bug 2221.  See 1.12 comments.
// 
//    Rev 1.12   27 Aug 1996 17:29:50   dlm
// Part of fix to RSW bug 2221.  Allow up to 1024 characters in error
//  messages from EXE.  See also rdexec.cpp.
// 
//    Rev 1.11   14 Feb 1996 15:37:30   dlm
// Removed path to rrrpt32x.h since it is now in H directory.  To fix
//  dependencies in product on stuff in rrrpt32 directory, which not
//  everyone has.
// 
//    Rev 1.10   14 Feb 1996 10:09:42   dlm
// First round of changes for RSW runtime DLL.
// 
//    Rev 1.9   01 Feb 1996 11:19:26   dlm
// Changed arguments to getOutputDest and setOutputDest to support multi-
//  character values (CSV, MSWORD, etc.)
// 
//    Rev 1.8   26 Jan 1996 17:36:24   dlm
// Fixed a few runtime DLL bugs.
// 
//    Rev 1.7   26 Jan 1996 09:52:10   dlm
// Added runtime-dll subclass of CFileDialog.
// 
//    Rev 1.6   18 Jan 1996 18:19:00   dlm
// Added RDUtil class for common stuff from RDReport/RDTable classes.
// 
//    Rev 1.5   18 Jan 1996 16:00:10   dlm
// Added "table" functions.
// 
//    Rev 1.4   18 Jan 1996 11:25:28   dlm
// Add RUNDLL conditionals to prevent compile problems with runtime
//  EXE builds.
// 
//    Rev 1.3   18 Jan 1996 09:39:18   dlm
// Miscellany.
// 
//    Rev 1.2   10 Jan 1996 14:34:28   dlm
// Added compound file support.
// 
//    Rev 1.1   04 Jan 1996 10:05:14   dlm
// Fix memory leaks of CRrRepIO, CRrComposite, CRrDoc.
// 
//    Rev 1.0   29 Dec 1995 14:01:30   dlm
// Initial revision.
// 
// ****************************************************************************

#if !defined(_RRDLL_H_)
//
// Make a definition for this module.
//
#define _RRDLL_H_

#if defined(RUNDLL)
// Advanced version of ASSERT. 
// The new version will display the asserted condition along with 
// displaying the application, file and line number of the assertion. 
#include "rrassert.h"
#include "rrrpt32x.h"	// for CRrRptApp definition
#include "rr.h"			// for CRrApp object definition

#if defined(TIME_IT)
// ******** TEMP **********
// For timing of DLL steps:
typedef struct timings
{
	long TimeChooseReport;
	long TimeExecRuntime;
	long TimePreCreateProcess;
	long TimePostCreateProcess;
	long Time2ndMsg;
	long TimeLastMsg;
} TIMINGS;

#define TIMEDIFF( end, begin ) (end) < (begin) ? (end) + 60000 - (begin) : (end) - (begin)
#endif

extern HINSTANCE HInst;
extern HCURSOR HourGlass;
extern HCURSOR ArrowCursor;
extern CRrDoc* gpDoc;

const unsigned int MAXCLIENTHANDLES	= 100;
const unsigned int MAXTABHANDLES	= 100;
const unsigned int FIELDS			= 23;
const unsigned int MAXLEN			= 260;
const unsigned int RECSIZE			= 1014;
const unsigned int ERROR_BUF_SIZE	= 1024;


const unsigned int MAXVALSIZE	= 512;
const unsigned int MAXREPNAME	= 30;
const unsigned int MAXFIELDNAME	= 64;
const unsigned int APPNAMESIZE	= 64;
const unsigned int MAXCALCSIZE	= 1024;

#if 0	// headers are the same in both 16- and 32-bit worlds!
typedef struct yxheader32
{	
	unsigned int yxType;
	unsigned int yxCount;
} YXheader32;
#endif

typedef struct yxheader16
{	
	WORD yxType;
	WORD yxCount;
} YXheader16;

typedef struct _rrdbf
{
	char label[14];
	int offset;
	int len;
	char flags;
	char ext[5];
} RRDBF;

typedef struct _repField
{
	unsigned int maxWidth;				// maximum size allowed by R&R
	BOOL bRiparam;						// it's an RIPARAM field
	BOOL bLimitSize;					// give error if string is longer than maxWidth
	char fieldName[MAXFIELDNAME + 1];
	char *reportVal;
	char *existingOverrideVal;
	char *newOverrideVal;
	struct _repField *next;
} REPFIELD;

typedef struct _fieldField
{
	char fieldName[MAXDNAME + 1];		// fieldname
	int fileNum;						// number of file of which this field is a part
	FLDID fieldID;						// "relative" field number
		// next four entries are just copies of stuff in MFFIELD structure
		// for use in field-list filters
	unsigned long dFlags;			// field flags
	unsigned int dFlags2;			// more field flags for Guido
	unsigned int dFlags3;			// yet more flags; Guido can't have 'em
	char dRFlags;					// report writer flags
	struct _fieldField *next;
} FIELDFIELD;

typedef struct _fileAlias
{
	char fileAlias[11];					// file alias
	int fileNum;						// file number of this file
	struct _fileAlias *next;
} FILEALIAS;

// Stuff needed by both RDReport and RDTable objects
class RDUtil : public CObject
{
public:
			RDUtil( void );
	LPCSTR	ErrorMessage;
	char	ErrorCode;
	char	ErrorBuf[ERROR_BUF_SIZE];
	char	strbuf[3][WINSTRLEN + 1];	// used by getFString()
#if defined(RSW)
	LPSTR	lpszTableName; 			/* name of table (for relational DBs) */
#endif

// Moved these next two from RDReport class so table stuff can use 'em too
	BOOL	chooseDataSource( LPSTR dataSource, int size );
	BOOL	chooseTable( LPSTR lpszTable, int tSize, LPSTR lpszDataSource, int dsSize, LPSTR lpszDatabase, int dbSize );
	
	LPSTR	getFString( UINT id, int buf );
	void	errBox( char code, LPCSTR errStr );
	BOOL	getErrorInfo( LPSTR lpszMsg, int size, LPINT lpiCode );
	BOOL	resetErrorInfo( void );
	void	InitApp( void );
	CRrDoc*	m_pDoc;
};

class RDReport : public CObject
{
public:
			RDReport();		// constructor
	virtual	~RDReport();	// destructor

	bool m_runningAsNonInteractiveUser; // U2I: set when running as ATL

	RDUtil m_Util;			// utility class containing common RDReport/RDTable stuff
	int ReportID;			// relative report number of this report in this instance	
	BOOL m_bLibrary;		// report is from a library (not compound file)
	BOOL m_b2ByteFieldIDs;	// filter expression has two-byte field IDs
	
	HWND HDlg;
	BOOL ColorTube;
	FARPROC hookLink;
	char *dbf,*recdata;

#if defined(TIME_IT)
	TIMINGS m_timings;
#endif

// from _rdrepst.h - REPSTUFF stucture

	// These items are for report library lists
	YYFILETAB *repFileTable;
	char **repnames;				// list of report names
	YZNAME *yznames;				// linked list of corresponding YZNAME structs
	int	iRepcnt;					// number of reports in library

	// These items are for an individual report
	YZNAME yzRepName;				// YZNAME struct for selected report
	char szLibName[WINPATHLEN + 1];
	char szRepName[MAXREPNAME];
	char szRuninName[WINPATHLEN + 1];
	char szAppName[APPNAMESIZE + 1];
#if defined(RSW)
	char *lpszUserName;				// user name (for command line)
	char *lpszPassword;				// password (for command line)
	char *lpszUserSQL;				// user sql statement
	char *lpszCurrentReplace;		// current RI_REPLACE token for Replace iterators
#endif
	FIELDFIELD *fieldNameList;		// list of field names
	FIELDFIELD *currentFieldName;	// for fieldname iterators
	FILEALIAS *fileAliasList;		// list of file aliases from saved report
	REPFIELD *fieldList;			// list of report items (names+values)
	REPFIELD *currentField;			// for iterators
	int errorCode;					// last error code
	int aliasIndex;					// for relation iterators
	int sortIndex;					// for sort iterators
	int groupIndex;					// for group iterators
	int fileNo;						// for field-list builder (current file number)
	char szCalc[MAXCALCSIZE];		// for riparam iterator
	int iCalcSize;					// for riparam iterator
	int iFields;
	BOOL bHSwitch;					// for SuppressTitle function
	BOOL bNew;						// This is a File->New vs. File->Open
	BOOL bCommentFound ;				// comment/section heading was found in INI file
	HWND hExeMainWnd;				// main window handle of runtime EXE
#if defined(RSW)
	BOOL bLiveMode;				// Calling DLL from ARPEGGIO Live code
	CString csLangID;				// Language ID
#endif
//	BOOL DOSRep;	// use bOldDOSRep instead!!
	
	// These items are for status returned form runtime .exe
	char StatusCode;			// RO_ECODE equivalent
	char StatusEmsg[ERROR_BUF_SIZE];		// RO_EMSG
	int StatusReports;			// RO_REPORTS
	long StatusPages;			// RO_PAGES
	int StatusRirecno;			// RO_RIRECNO or RO_RIID
	BOOL StatusDone;			// flag indicating runtime EXE has finished
	BOOL StatusNVDone;			// flag indicating runtime EXE has finished getting job-control info
	
// from rreport.h

#if defined(RSW)
//	BOOL	chooseDataSource( LPSTR dataSource, int size );
#endif
	BOOL	choosePrinter( LPSTR printer, int prSize, LPSTR port, int poSize );
#if defined(RSW)
	int		chooseReport( LPSTR appName, LPSTR lib, int lSize, LPSTR rep, int rSize, LPSTR lpszUsername, LPSTR lpszPassword, LPSTR lpszDataSource, int dSize );
//	BOOL	chooseTable( LPSTR lpszTable, int tSize, LPSTR lpszDataSource, int dsSize, LPSTR lpszDatabase, int dbSize );
#else
	int		chooseReport( LPSTR appName, LPSTR lib, int lSize, LPSTR rep, int rSize );
#endif
	BOOL	endReport( );
	BOOL	execRuntime ( BOOL bWait, int fsCmdShow, LPINT ecode, LPLONG pageCount, LPSTR emsg, int emsgSize );
	BOOL	getBeginPage ( LPLONG lplPage );
	BOOL	getCopies ( LPINT lpiCopies );
#if defined(RSW)
	BOOL	getDatabase( LPSTR pDatabase, int size );
	BOOL	getDataSource( LPSTR pDataSource, int size );
#endif
	BOOL	getDisplayErrors ( BOOL FAR * lpbDisperr );
	BOOL	getDisplayStatus ( BOOL FAR * bDispStatus );
	BOOL	getEndPage ( LPLONG lplPage );
	BOOL	getExportDest ( LPSTR lpszVal );
	BOOL	getFilter ( LPSTR lpszFilter, int size );
	BOOL	getFilterUsage ( LPSTR lpszVal );
	BOOL	getFirstFieldName ( LPSTR lpszFieldName, int size );
	BOOL	getFirstFilteredFieldName( LPSTR fieldName, int size, int filter );
	BOOL	getFirstGroupField ( LPSTR lpszName, int size );
#if defined(RSW)
	BOOL	getFirstJoinInfo( LPSTR lpszTable, int tSize, LPSTR lpszAlias, int aSize );
	BOOL	getFirstReplace( LPSTR lpszReplace, int size );
#else
	BOOL	getFirstRelationInfo ( LPSTR lpszFilePath, int fSize, LPSTR lpszIndexPath, int iSize,	LPSTR lpszTag, int tSize, LPSTR lpszAlias, int aSize );
#endif
	BOOL	getFirstSortField ( LPSTR lpszName, int size );
	BOOL	getFirstUserParam ( LPSTR lpszName, int nSize, LPSTR lpszValue, int vSize );
#if !defined(RSW)
	BOOL	getHighScope ( LPSTR lpszScope, int size );
#endif
	LPSTR	getLibDir( void );
	BOOL	getLibrary ( LPSTR lpszName, int size );
#if !defined(RSW)
	BOOL	getLowScope ( LPSTR lpszScope, int size );
	BOOL	getMasterIndexInfo ( LPSTR lpszPath, int pSize, LPSTR lpszType, LPSTR lpszTag, int tagSize );
	BOOL	getDBContainer ( LPSTR lpszPath, int Size );
#endif
	BOOL	getMasterTableName ( LPSTR lpszPath, int size );
	BOOL	getMemoName ( LPSTR lpszPath, int size );
	int		getNewReportHandle (LPSTR lpszAppName );
	BOOL	getNextFieldName ( LPSTR lpszFieldName, int size );
	BOOL	getNextFilteredFieldName( LPSTR fieldName, int size, int filter );
	BOOL	getNextGroupField ( LPSTR lpszName, int size );
#if defined(RSW)
	BOOL	getNextJoinInfo( LPSTR lpszTable, int tSize, LPSTR lpszAlias, int aSize );
	BOOL	getNextReplace( LPSTR lpszReplace, int size );
#else
	BOOL	getNextRelationInfo ( LPSTR lpszFilePath, int fSize, LPSTR lpszIndexPath, int iSize,	LPSTR lpszTag, int tSize, LPSTR lpszAlias, int aSize );
#endif
	BOOL	getNextSortField ( LPSTR lpszName, int size );
	BOOL	getNextUserParam ( LPSTR lpszName, int nSize, LPSTR lpszValue, int vSize );
	BOOL	getOutputDest ( LPSTR lpszDest, int dSize );
	BOOL	getOutputFile ( LPSTR lpszPath, int size );
	BOOL	getPreventEscape ( BOOL FAR * lpbNoEsc );
	BOOL	getPrinter ( LPSTR lpszPrinter, int size );
	BOOL	getPageSize ( LPSTR lpszPageSize, int size );
	BOOL	getPrinterPort ( LPSTR lpszPort, int size );
	LPSTR	getProgramPath( void );
	BOOL	getReportPick ( LPSTR lpszPickFlag );
#if defined(RSW)
	int		getRuntimeRecord( LPSTR lpszAppName, LPSTR lpszControlFile, LPSTR lpszUsername, LPSTR lpszPassword, LPSTR lpszDataSource, int dSize );
#else
	int		getRuntimeRecord( LPSTR lpszAppName, LPSTR lpszControlFile );
	BOOL	getScopeUsage ( LPSTR lpszScopeFlag );
#endif
	BOOL	getStatusEveryPage ( BOOL FAR * lpbStatus );
	BOOL	getTestPattern ( BOOL FAR * lpbTest );
	BOOL	getWinTitle ( LPSTR lpszTitle, int size );
	BOOL	setBeginPage ( LONG lPage );
	BOOL	setCopies ( int copies );
#if defined(RSW)
	BOOL	setDatabase( LPCSTR lpszDatabase );
#endif
	BOOL	setDataDir ( LPCSTR lpszDir );
#if defined(RSW)
	BOOL	setDataSource( LPCSTR pDataSource );
#endif
	BOOL	setDisplayErrors ( BOOL bDisperr );
	BOOL	setDisplayStatus ( BOOL bDispStatus );
	BOOL	setEndPage ( LONG lPage );
	BOOL	setExportDest ( char cVal );
	BOOL	setFilter ( LPCSTR lpszFilter );
	BOOL	setFilterUsage ( char cVal );
	BOOL	setGroupField ( LPCSTR lpszName, int groupNum );
#if !defined(RSW)
	BOOL	setHighScope ( LPCSTR lpszScope );
#endif
	BOOL	setImageDir ( LPCSTR lpszDir );
#if !defined(RSW)
	BOOL	setIndexExtension ( int ExtNumber );
#else
	BOOL	setJoinInfo( LPCSTR lpszTable, LPCSTR lpszAlias, int aliasNum );
#endif
#if defined(RSW)
	BOOL  setLanguageID( LANGID langid );
#endif
	BOOL	setLibrary ( LPCSTR lpszName );
	BOOL	setLibraryDir ( LPCSTR lpszDir );
#if defined(RSW)
	BOOL  setLiveMode( BOOL bMode );
#endif
#if !defined(RSW)
	BOOL	setLowScope ( LPCSTR lpszScope );
	BOOL	setMasterIndexInfo ( LPCSTR lpszPath, char cType, LPCSTR lpszTag );
	BOOL	setDBContainer ( LPCSTR lpszPath );
#endif
	BOOL	setMasterTableName ( LPCSTR lpszPath );
	BOOL	setMemoName ( LPCSTR lpszPath );
	BOOL	setOutputDest ( LPCSTR lpszDest );
	BOOL	setOutputFile ( LPCSTR lpszPath );
#if defined(RSW)
	BOOL	setPassword( LPCSTR lpszPassword );
#endif
	BOOL	setPreventEscape ( BOOL bNoEsc );
	BOOL	setPrinter ( LPCSTR lpszPrinter );
	BOOL	setPageSize ( LPCSTR lpszPageSize );
	BOOL	setPrinterPort ( LPCSTR lpszPort );
#if !defined(RSW)
	BOOL	setRelationInfo ( LPCSTR lpszFilePath, LPCSTR lpszIndexPath, LPCSTR lpszTag, LPCSTR lpszAlias, int aliasNum );
#else
	BOOL	setReplace( LPCSTR lpszReplace );
#endif
	BOOL	setReportPick ( char cPickFlag );
#if !defined(RSW)
	BOOL	setScopeUsage ( char cScopeFlag );
#endif
	BOOL	setSortField ( LPCSTR lpszName, int sortNum );
	BOOL	setStatusEveryPage ( BOOL bStatus );
	BOOL	setStatusFileName ( LPCSTR lpszFilename );
	BOOL	setSuppressTitle ( BOOL bValue );
	BOOL	setTestPattern ( BOOL bTest );
#if defined(RSW)
	BOOL	setUserName( LPCSTR lpszName );
#endif
	BOOL	setUserParam ( LPCSTR lpszName, LPCSTR lpszValue );
#if defined(RSW)
	BOOL	setWhere( LPCSTR lpszWhere );
#endif
	BOOL	setWinBorderStyle ( int style );
	BOOL	setWinControlBox ( BOOL bControlBox );
	BOOL	setWinHeight ( int height );
	BOOL	setWinLeft ( int left );
	BOOL	setWinMaxButton ( BOOL bMax );
	BOOL	setWinMinButton ( BOOL bMin );
	BOOL	setWinParentHandle ( int hParent );
	BOOL	setWinTitle ( LPCSTR lpszTitle );
	BOOL	setWinTop ( int top );
	BOOL	setWinWidth ( int width );
#if !defined(RSW)
	BOOL	setWriteAllow ( BOOL bAllow );
	BOOL	setXbaseEditor ( BOOL bXbase );
#endif
	BOOL	writeRuntimeRecord ( LPSTR lpszControlFile );
private:

// from rdrepstf.cpp
	BOOL		validate_handle( void );
	REPFIELD*	findField( LPCSTR valName );
	BOOL		addReportField( LPSTR name, int width, BOOL bRiparam, char *data, BOOL bLimitSize, int copySize );
	FIELDFIELD* repstfFindFieldID( FLDID fieldID );
	LPSTR		repstfFindAlias( int fileNum );
	BOOL		fixTotalFileNos( void );
public:
#if defined(RSW)
	BOOL		repstfInit( LPSTR dsrc, int dSize );
#else
	BOOL		repstfInit( void );
#endif
private:
	BOOL		repstfNew( void );
	void		repstfDelete( void );
	BOOL		repstfGetYZName( YZNAME **yzRepName );
	BOOL		repstfAddNewOverride( LPCSTR valName, LPCSTR value );
	BOOL		repstfAddExistingOverride( LPCSTR valName, LPCSTR value );
	BOOL		repstfGetFirstOverride( LPSTR *valName, LPSTR *value );
	BOOL		repstfGetNextOverride( LPSTR *valName, LPSTR *value );
	BOOL		repstfGetRiparam( BOOL bReset, BOOL bRIPOnly, LPSTR *valName, LPSTR *value );
	BOOL		repstfSetCalc( char *calc, int size );
	char*		repstfGetCalc( UINT *size );
	void		repstfResetAliasNum( void );
	int			repstfGetNextAliasNum( void );
	void		repstfResetSortNum( void );
	int			repstfGetNextSortNum( void );
	void		repstfResetGroupNum( void );
	int			repstfGetNextGroupNum( void );
	void		repstfResetFieldPtr( void );
	FIELDFIELD*	repstfGetFieldPtr( void );
	void		repstfResetCurrentFileNo( void );
	int			repstfBumpCurrentFileNo( void );
	int			repstfGetCurrentFileNo( void );
	void		repstfResetReplace( void );
	char*		repstfGetReplace( char *replace, int size );
	void		repstfAddFieldName( FIELDFIELD *fldStr );
	void		repstfAddAlias( FILEALIAS *fileStr );
	BOOL		repstfGetVal( char *name, char **retVal );
	BOOL		repstfGetFtab( YYFILETAB **ftab );
	BOOL		repstfGetCommentStatus( void );
	char* 		repstfGetValFile( void );
//	BOOL		repstfGetRepstuff( REPSTUFF **repStuff );
	BOOL		getVal( char *name, char **valBuf );
//	void		repstfSetActive( void );
	BOOL		repstfSetUserName( LPCSTR lpszUserName );
	BOOL		repstfSetPassword( LPCSTR lpszPassword );
	BOOL		repstfSetSuppressTitle( BOOL bValue );

// from rdinit.cpp
public:
	BOOL		openReportLibrary( char *libName, YYFILETAB **ft );
private:
	BOOL		OpenCompoundFileRep( LPSTR Name );
	void		CloseCompoundFileRep( void );
	BOOL		listReports( HWND hDlg );
	
// from rdreport.cpp
	BOOL		addStringToFilter( char *pStart, char **pCurrent, int size, char *string );
	BOOL		addFieldToFilter( char *pStart, char **pCurrent, int size, FLDID fieldID );
	BOOL		addDateToFilter( char *pStart, char **pCurrent, int size, char *date );
	BOOL		addDateTimeToFilter( char *pStart, char **pCurrent, int size, char *dttm );
	BOOL		addTimeToFilter( char *pStart, char **pCurrent, int size, char *time );
	BOOL		addNumberToFilter( char *pStart, char **pCurrent, int size, double number );
	UTWO		getRepRecord( YYFILETAB *f, YXheader16 *hdr16, LPSTR *lpszBuffer, unsigned int bufsize, unsigned int *size );
	UTWO		getRepRecStr( UTWO *recType, LPSTR pReturn, UINT bufsize, UINT *size, BOOL bReset, LPSTR *ppReturn );
	UTWO		getRepRecordStr( UTWO *recType, LPSTR lpszReturn, UINT bufsize, UINT *size, BOOL bReset );
	UTWO		getRepRecordStrPtr( UTWO *recType, LPSTR *lppReturn, UINT *size, BOOL bReset );
	BOOL		getRelationInfo( LPSTR lpszFile, int lenFile, LPSTR lpszIndexFile, int lenIndexFile, LPSTR lpszIndexTag, int lenIndexTag, LPSTR lpszAlias, int lenAlias, BOOL bReset );
	BOOL		getRiparam( LPSTR lpszParam, int lenParam, BOOL bReset );
	BOOL		getRepSortField( char *repVal, BOOL bReset );
	BOOL		getRepGroupField( char *repVal, BOOL bReset );
public:
	BOOL		getReportAlias( BOOL first );
	BOOL		getReportFieldName( BOOL first );
	BOOL		getReportDataSource( char *repVal );
	BOOL		getReportDatabase( char *repVal );
	BOOL		getReportDBC( char *repVal );
	BOOL		getReportMaster( char *repVal );
	BOOL		getReportMindex( char *repVal );
	BOOL		getReportMemo( char *repVal );
	BOOL		getReportOutfile( char *repVal );
	BOOL		getReportExpOutfile( char *repVal );
	BOOL		getReportPrinter( char *repVal );
	BOOL		getReportWprinter( char *repVal );
	BOOL		getReportWport( char *repVal );
	BOOL		getReportBegpage( char *repVal );
	BOOL		getReportEndpage( char *repVal );
	BOOL		getReportLoscope( char *repVal );
	BOOL		getReportHiscope( char *repVal );
	BOOL		getReportCopies( char *repVal );
	BOOL		getReportFirstRelation( char *repVal );
	BOOL		getReportNextRelation( char *repVal );
	BOOL		getReportFirstRiparam( char *repVal );
	BOOL		getReportNextRiparam( char *repVal );
	BOOL		getReportFirstSortField( char *repVal );
	BOOL		getReportNextSortField( char *repVal );
	BOOL		getReportFirstGroupField( char *repVal );
	BOOL		getReportNextGroupField( char *repVal );
	BOOL		getReportFilter( char *repVal );
	BOOL		getReportUserSQL( char **repVal );
	BOOL		getReportRevision( void );
	void		makeDate( long days, LPSTR lilbuf );
	void		makeTime( double num, LPSTR itbuf );
private:
// from rdrepval.cpp
	BOOL		getCharValue( char *name, char *value, int vSize );
	LPSTR		getCharValPtr( char *name );
	BOOL		setCharValue( LPCSTR name, LPCSTR value );
	BOOL		setSingleCharValue( char *name, char value );
	BOOL		getBoolValue( char *name, BOOL *value );
	BOOL		setBoolValue( char *name, BOOL value );
	BOOL		getIntValue( char *name, int *value );
	BOOL		setIntValue( char *name, int value );
	BOOL		getLongValue( char *name, LONG *value );
	BOOL		setLongValue( char *name, LONG value );
	BOOL 		getJoinInfo( BOOL bReset, char *relFilePath, int rSize, char *relAlias, int aSize );
	BOOL		getRelationInfo( BOOL bReset, char *relFilePath, int rSize, char *relIndexfilePath, int iSize, char *relIndexTag, int tSize, char *relAlias, int aSize );
	BOOL		formatName( char *nameBuf, char *pAlias, char *pField, int size );
	BOOL		getFieldName( BOOL bReset, char *fieldName, int size, int filter );
	BOOL		getSortField( BOOL bReset, char *sortFieldName, int fSize );
	BOOL		getGroupField( BOOL bReset, char *groupFieldName, int fSize );
	BOOL		getReplace( BOOL bReset, char *replace, int size );
	BOOL		getDefaultLibDir( LPSTR buf, int size );
	BOOL		pathName( LPCSTR name );
	void		makeFullPath( LPSTR pathBuf, LPCSTR fileName );

// from rdinit.cpp
	BOOL		initRuntimeDLL( void );
	
// from rdmisc.cpp
private:
	BOOL		zbusy( BOOL on );

// dummy CRrDocument for access to utility functions?
public:
	CRrDoc*		m_pDoc;
};

#define MAXTABNAME	WINPATHLEN		// should this be some other symbol (or size)? 

typedef struct _tabField
{
	char				fieldName[MAXDNAME + 1];	// fieldname
	UINT				fieldLength;				// data length
	UINT				fieldDP;					// decimal places
	char				fieldType;					// data type ('C', 'N', etc.)
	struct _tabField*	next;						// link to next
} TABFIELD;

typedef TABFIELD far * LPTABFIELD;

class RDTable : public CObject
{
public:
				RDTable();		// constructor
	virtual		~RDTable();		// destructor

	RDUtil		m_Util;			// utility class containing common RDReport/RDTable stuff
	
	// API-related functions
#if defined(RSW)
	BOOL		tabChooseTable( LPSTR table, int tSize, LPSTR qtable, int qSize, LPSTR user, LPSTR pass, LPSTR dsrc, int dSize );
#else
	BOOL		tabChooseTable( LPSTR table, int tSize );
#endif
	BOOL		tabFreeHandle( void );
	BOOL		tabGetFirstFieldInfo( LPSTR lpszFieldName, int iSize, LPSTR lpszType, LPINT lpiLgt, LPINT lpiDecPl );
	BOOL		tabGetNextFieldInfo( LPSTR lpszFieldName, int iSize, LPSTR lpszType, LPINT lpiLgt, LPINT lpiDecPl );
	// internal functions
	void		tabstfDelete( void );
	BOOL		tabstfGetFieldInfo( BOOL bReset, char *fieldName, int size, char *type, int *lgt, int *decpl );
	LPTABFIELD	tabstfGetFieldPtr( void );
	BOOL		tabstfGetFields( LPSTR lpszTable );
	BOOL		tabstfInit( void );
	void		tabstfResetFieldPtr( void );
#if defined(RSW)
	BOOL		tabstfSetPassword( char *pszPassword );
	BOOL		tabstfSetUserName( char *pszUserName );
#endif
	
	char		szRepName[MAXTABNAME];
#if defined(RSW)
	char*		lpszUserName;				// user name
	char*		lpszPassword;				// password
	char*		lpszDataSourceName;			// data source name
#endif
	TABFIELD*	fieldNameList;				// list of field names
	TABFIELD*	currentFieldName;			// for fieldname iterators
	int			errorCode;					// last error code
	int			iFields;
	
	BOOL		initRuntimeDLL( void );
	
	CRrDoc*		m_pDoc;
};

// A common file dialog class with OnInitDialog and OnOK overrideables
class RDFileDialog : public CFileDialog
{
public:
	// Constructor
    RDFileDialog( BOOL bOpenFileDialog, LPCSTR lpszDefExt = NULL, LPCSTR lpszFileName = NULL,
			DWORD dwFlags = OFN_HIDEREADONLY, LPCSTR lpszFilter = NULL,
			CWnd* pParentWnd = NULL, RDReport* pReport = NULL );

	RDReport*		m_pReport;
	// Overrides
	protected:
	virtual BOOL	OnInitDialog();
	virtual BOOL	OnFileNameOK();
	virtual void	OnOK();
};

#endif	// defined(RUNDLL)
// for rrwrun.exe
// getSpecificParam() takes a name and returns a value if a parameter with that name exists
// getFirstParam() & getNextParam() cycle through all parameters, including RIPARAMs
// message type codes for DLLsendMessage()
//#define DM_HWND			1
#define DM_ECODE		2
#define DM_EMSG			3
#define DM_REPORTS		4
#define DM_PAGES		5
#define DM_RIRECNO		6
#define DM_DONE			7
#define DM_NVDONE		8
#define DM_NEXT_PARAM	9

 #if 0
typedef	int (WINAPI* LPFNRDGETPARAM)(int,LPSTR,int,LPSTR,int,BOOL,WORD );
typedef	int (WINAPI* LPFNRDGETSPECIFICPARAM)(int,LPSTR,LPSTR,int,WORD );
typedef	int (WINAPI* LPFNRDDLLSENDMESSAGE)(int,int,LPSTR,WORD );

 #endif
#endif
