// ****************************************************************************
//
//		(C) Copyright 2001 Liveware Publishing Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   rrrepio.h  $
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
// $Log:   D:/R&R Project/archives/H/RRREPIO.H_V  $
// 
//    Rev 1.32   25 Aug 2004 07:54:00   Nick
// Version 10.5
// 
//    Rev 1.31   Oct 07 2002 09:29:44   Admin
// setfieldkey()
// 
//    Rev 1.30   Apr 25 2002 10:19:52   Admin
// Proto for writing new image record
// 
//    Rev 1.29   Nov 29 2001 11:37:56   Administrator
// Add wmapi()
// 
//    Rev 1.28   Feb 27 2001 15:42:14   nhubacker
// compileValidate()
// 
//    Rev 1.27   Dec 05 2000 13:15:32   nhubacker
// Add user index variables
// 
//    Rev 1.26   20 Jun 1997 16:34:32   dlm
// Part of fix to WO 129707.  Add places to remember master DS name and
//  override DS, if any.
// 
//    Rev 1.25   13 May 1997 18:21:18   unknown
// add m _bOverflow  for lib save rec field overflow test
// 
//    Rev 1.24   13 May 1997 10:39:14   dlm
// Added m_schema to allow charts to deserialize properly with or without
//  latest additions.
// 
//    Rev 1.23   08 May 1997 19:23:30   dlm
// Added putCharts() function.
// 
//    Rev 1.22   22 Apr 1997 11:10:44   pjm
// Add m_bModifiedOnRetrieve to repio class.
// 
//    Rev 1.21   19 Feb 1997 14:57:04   dlm
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
//    Rev 1.20   17 Oct 1996 18:24:28   jpb
// fix VarFileInfo charset
// 
//    Rev 1.19   08 Oct 1996 16:50:16   amh
// Arp 1.0 U02 merged to trunk
// 
// 
//
// 
//    Rev 1.17.1.2   10 Sep 1996 17:36:04   smh
// Don't define unknown record type reporting stuff in runtime dll.
// 
//    Rev 1.17.1.1   09 Sep 1996 13:47:46   jpb
// fix typo on reportUnknownTypes
// 
//    Rev 1.17.1.0   06 Sep 1996 15:40:46   jpb
// unkown record types warning
//
// 
//    Rev 1.18   30 Sep 1996 14:13:52   jpb
// add U02 changes for unknown record types
// 
//    Rev 1.17   28 Feb 1996 18:26:32   dlm
// Added member function EliminateDupPredefinedCalc.
// 
//    Rev 1.16   23 Feb 1996 20:20:40   dlm
// Fix to RSW bug 2087.  GetReportDS() was doing bad things, like wiping out
//  the included OLE objects in a current report when finding the data
//  sources for reports presented in open-file dialog.  Rewrote mechanism
//  for getting this info.  Modules are: grmain.cpp, dbinfo.cpp, rrrepio.cpp,
//  rrdoc.cpp, rrrepio.h.
// 
//    Rev 1.15   16 Feb 1996 14:16:04   dlm
// Part of fix to RSW bug 2073 which was about problems retrieving a .RSW
//  report from the MRU list.  This was because we didn't make the data
//  source saved with the report active during the retrieve.  Affected
//  modules were: GRSQL.CPP, RRDOC.CPP, RRREPIO.CPP, RRREPIO.H.
// 
//    Rev 1.14   18 Dec 1995 12:46:12   dlm
// Added a couple of new member variables.
// 
//    Rev 1.13   15 Dec 1995 18:18:02   dlm
// Added stuff for getting the data source info out of a compound file
//  report.
// 
//    Rev 1.12   15 Dec 1995 16:06:42   dlm
// Added support for new report properties and "init" routine for all
//  init-able properties.
// 
//    Rev 1.11   14 Dec 1995 11:53:52   par
// Corrected the useage of ReportName and Title.  The Title in this instance is a
// user specified title and is not related to the Title variable in the MFC document.
// 
//    Rev 1.10   13 Dec 1995 17:32:52   par
// Added new CSummaryInfo class to repio as a way of grouping the file properties.
// Moved Rep Note into that class an called it m_cs Comment.
// 
//    Rev 1.9   07 Dec 1995 10:38:14   smh
// Added IsDrive which returns TRUE if passed path is a drive (only).
// 
//    Rev 1.8   05 Dec 1995 11:51:50   dlm
// Added member functions relating to UNC support in fnshrink/fnexpand.
// 
//    Rev 1.7   01 Dec 1995 12:56:12   dlm
// Added declarations of some stuff stolen from MFC/OLE code source.
// 
//    Rev 1.6   28 Nov 1995 09:09:22   dlm
// Added declarations for functions related to reading summary info stream.
// 
//    Rev 1.5   22 Nov 1995 17:16:24   dlm
// Added flag to let summary-info code know whether it's a resave or a
//  new file.
// 
//    Rev 1.4   21 Nov 1995 11:52:48   dlm
// First pass at Summary Info stream support.
// 
//    Rev 1.3   14 Nov 1995 17:12:02   dlm
// Added m_bSavedReport so SaveReportToStorage can tell OnFileSave that
//  the report was saved or not.
// 
//    Rev 1.2   03 Nov 1995 13:53:22   dlm
// First pass at compound file report storage.
// 
//    Rev 1.1   20 Oct 1995 11:17:28   dlm
// Added destructor delcaration/definition.
// 
//    Rev 1.0   18 Oct 1995 14:22:42   dlm
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _RRREPIO_H_

// Make a definition for this module.
//
#define _RRREPIO_H_

// rrrepio.h : interface of the CRrRepIO class
//
	#include "_repio.h"
	
// Stuff relating to code stolen from MFC source that is uncallable by us?
DWORD AFXAPI _AfxRelease(LPUNKNOWN* plpUnknown);
#define RELEASE(lpUnk) _AfxRelease((LPUNKNOWN*)&lpUnk)


// Beginning of stuff related to Summary Information stream	
const UINT RR_PROPERTY_COUNT = 10;	// number of properties we write to our info stream

const UINT PID_TITLE = 2;
const UINT PID_SUBJECT = 3;
const UINT PID_AUTHOR = 4;
const UINT PID_KEYWORDS = 5;
const UINT PID_COMMENTS = 6;
const UINT PID_LASTAUTHOR = 8;
const UINT PID_REVNUMBER = 9;
const UINT PID_CREATE_DTM = 0xC;
const UINT PID_LASTSAVE_DTM = 0xD;
const UINT PID_APPNAME = 0x12;

const UINT MAX_UNKNOWNS = 50;
	
typedef struct tagSUMMARY_INFO_HEADERS
{
	struct tagPROPERTYSETHEADER
	{
		WORD	ByteOrder;		// Always 0xFFFE
		WORD	Format;			// Always 0
		DWORD	OSVer;			// Operating System Version (from GetVersion)
		char	ClassID[16];	// Class ID ??
		DWORD	reserved;		// Should be 1, for now
	} PSetHeader;
	struct tagFORMATIDOFFSET
	{
		char	FormatID[16];	// format ID
		DWORD	Offset;			// offset from start of stream to property section header
	} IDOffset;
} SUMMARY_INFO_HEADERS;

typedef struct tagPROPERTYSECTION
{
	struct tagPROPERTYSECTIONHEADER
	{
		DWORD	SectionSize;	// size of entire "section"
		DWORD	PropertyCount;	// number of properties in "section"
	} PSectHeader;
	struct tagPROPERTYIDOFFSET
	{
		DWORD	PropertyID;		// "name" of property
		DWORD	Offset;			// offset from start of "section"
	} PIDOffset[RR_PROPERTY_COUNT];
} PROPERTY_SECTION;

#define ROUND_UP( x )	(( x + 3 ) >> 2 << 2 )
// End of stuff related to Summary Information stream	
	
class CRrDoc;


class CRrSummaryInfo : public CObject
{
	CRrDoc* m_pDoc ;
public:
	// stuff for "Summary Info" stream
	// other summary stuff is computed at File-Save time
	CString& csReportName ;  // Reference the one in the document. 
	                      ;  // This will keep report name up to data, always. 
	CString  csAuthor     ;  // original author of report
	CString  csLastAuthor ;  // most recent updater
	CString  csKeywords   ;
	CString  csUserTitle  ;  // 
	CString  csSubject    ;
	CString  csComment    ;
	UINT     uRevNumber   ;  // number of times written
	FILETIME ftCreateDTM  ;  // creation date/time

	CRrSummaryInfo(CRrDoc* pDoc) : m_pDoc(pDoc), csReportName(pDoc->GetTitleReference())
	{
		ASSERT( m_pDoc );
		uRevNumber                 = 0 ;
		ftCreateDTM.dwLowDateTime  = 0L ;
		ftCreateDTM.dwHighDateTime = 0L ;
	}
	BOOL	OnEditProperties() ;
	void	InitProperties() ;
} ;


class CRrRepIO : public CObject
{
	DECLARE_DYNAMIC( CRrRepIO );
public:
				CRrRepIO( CRrDoc* pDoc );		// constructor
	virtual		~CRrRepIO( void ) { };				// destructor
	
	CRrDoc*         m_pDoc          ;
	LPSTORAGE       m_pStorage      ;  // pointer to root storage for compound document
	COleStreamFile* m_pStream       ;  // pointer to current stream in root storage
	
	// stuff for "Summary Info" stream
	// other summary stuff is computed at File-Save time
	CRrSummaryInfo  m_siSummaryInfo ;
	BOOL            m_bResave       ;		// TRUE => resave as opposed to new file
	int				m_bReadRepResult;		// for use in compound file case, since Serialize has no result
	BOOL			m_bModifiedOnRetrieve;	// user changed report while retrieving
	BOOL			m_bFromMRUList;			// TRUE => reading report from MRU list
	int				m_Schema;				// version of serialization code for some object (currently charts only)
	
	BOOL		SaveReportToStorage( LPSTORAGE pStorage, COleStreamFile* pFile );
	int			ReadReportFromStorage( LPSTORAGE pStorage, COleStreamFile* pFile );
	char*		FillCommonFieldInfo( LPMFFIELD fld, char *buf );
	char*		FillDBFieldInfo( LPMFFIELD fld, char* buf );
	void		GetDBFieldInfo( LPMFFIELD fld, UONE* buf );
	void		GetCommonFieldInfo( LPMFFIELD fld, UONE* buf );
	void		WriteSummaryInfo( LPSTORAGE pStorage );
	void		ReadSummaryInfo( LPSTORAGE pStorage );
	BOOL		GetPropertyString( LPSTR Temp, UINT Size, CFile* File, DWORD Position );
	BOOL		GetPropertyDTM( FILETIME* CreateTime, CFile* File, DWORD Position );
	BOOL		setfieldx( YXBUF *buf, LPSTR fname );
	BOOL		settextfldx( YXBUF *buf, int type );
	BOOL		setboxfldx( YXBUF *buf );
	BOOL		setimagefldx( YXBUF *buf );
	BOOL		setimagefldy( YXBUF *buf );
	BOOL		EliminateDupPredefinedCalc( LPMFFIELD fld );
	BOOL		setcalcfldx( YXBUF *buf );
	BOOL		settotfldx( YXBUF *buf );
	BOOL		IsUNCPath( LPSTR ptr );
	LPSTR		SkipDrivePart( LPSTR ptr );
	BOOL		IsDrive( LPSTR ptr );
	
	BOOL		m_bSavedReport;		// TRUE -> writeRep succeeded
	int			SavedSpaceDot;

#if defined(INTERACTIVE)
#if !defined(RUNDLL)
	unsigned int m_Unknowns[MAX_UNKNOWNS];		// for unknown record type reporting
	int			m_UnknownCnt;		// number of unkown types saved
	void		addUnknownToList( unsigned short );	// add an unknown type to the list
	void		reportUnknownTypes( void );	// tell the user about unknown types

private:
	BOOL	m_bOverflow;
#endif
#endif

	
	// ***** begin repio.h
public:
	BOOL		bOldDOSRep; 
	int			InReadRep;
	int			BadRep;
	int			intDate;			// this is for converting picD4/picD5
	int			RpMajVer;
	int			RpMinVer;
 #if defined(RSW)
	LPSTR		lpszSQLstmt;
	int			DTCAnswer;
	int			DTCRev;
	char		szDataSource[SQL_MAX_DSN_LENGTH]; 	// shared among grsql.c, grfile.c and dreport.c
	char		szDSDir[WINPATHLEN];
	char		szDriverDescription[MAX_DRIVER_DESCRIPTION_LENGTH+1];
	char		szConnect[MAX_CONNECT_STRING+1];
	BOOL		m_bUse_szDataSource;	// TRUE => szDataSource contains data source override
	char		szDataSourceOverride[SQL_MAX_DSN_LENGTH];	// used to hold override DS, if any - used in grsql.cpp
	char		szDataSourceMaster[SQL_MAX_DSN_LENGTH];		// used to hold master DS, pre-override - used in grsql.cpp
 #endif
 
 #if defined(RSW)
	int		db_info( YYFILETAB* ftab, LPYZNAME yzn );
	UTWO	getRepRecord( COleStreamFile* pStream,  YXBUF* buf );
	void	FindDSRecord( COleStreamFile* pStream, LPSTR pDSBuffer, char* pDSConnect, char* pDSDriver);
	BOOL	OpenCompoundFileRep( LPSTR lpszPathName, LPSTORAGE* pStorage, COleStreamFile** ppStream );
	void	CloseCompoundFileRep( LPSTORAGE pStorage, COleStreamFile* pStream );
	BOOL	FindDSRecord( void );
	BOOL	GetReportDS( char* szLibrary, char* szDSBuffer, char* szDSConnect, char* szDSDriver);
	
	int		readRep( BOOL bUseszDataSource );
 #else
	int		readRep( void );
 #endif
	BOOL	writeRep( long recno );
	BOOL	saveRep( int (CRrRepIO::*routine)(long ), LPSTR rname );
	BOOL	stamps( YYFILETAB *ftab, LPYZNAME yzn );
	BOOL	yxfarget( struct yxbuf *buf, LPINT ct );
	LPSTR	fnshrink2( LPSTR ptr, LPSTR mname );
	LPSTR	fnshrink( LPSTR ptr );
 #if !defined(INTERACTIVE) && !defined(RSW)
	BOOL	chkscope( int lo );
 #endif
	// ***** end repio.h
	
	// ***** begin _repio.h
private:
 #if defined(INTERACTIVE)
	int			CFlds;
	ZDATE		RpDate;
	ZTIME		RpTime;
	char		RpUser[USE_BYTES];
 #else
	LPMFFIELD	fldtogo;
  #if defined(RSW)
	LPSTR		OrigDB;
  #endif
 #endif
	int			cfn;
	int			fonts;
 #if defined(RSW)
	JOINPAIRCHAIN *joinpairhead;
	JOINPAIRCHAIN *joinpairtail;
	char		LocName[MAXDNAME];
	DWORD		LocT;
 #else
	UINT		PartLen;
	bool		userindex ;
	char		indexExpression[SELEXBUF + 1] ;
 #endif
	LPMFFIELD	LastFld;
	int			OldRep;
	int			ToHunds;
	int			TrimBit;
	int			WasLabels;
 
 #ifdef RSW
	LPMFFIELD findfld( DWORD type, LPSTR name, int fn, int dummyok, LPINT convert);
 #else
	LPMFFIELD findfld( DWORD type, LPSTR name, int fn);
 #endif
	void	initCond( void );
	void	setdels( UINT fn );
	int		lwhatnext( int time, LPSTR orig, int dbf );
	int		lfnexpand( LPSTR ptr, int dbf );
	void	makepname( LPSTR namebuf, LPSTR dir );
 #ifdef RSW
	BOOL	ltrynext( int time, int dbf, LPMFFILE ftb, int master, LPSTR orig, int ret, int recno, LPSTR ebuf );
	BOOL	lnewtable( LPMFFILE f, int ecode, LPSTR ebuf );
	BOOL	newDataSource( void );
 #else
	BOOL	ltrynext( int time, int dbf, LPMFFILE ftb, int master, LPSTR orig, int ret, int recno );
 #endif
	LPSTR	lmakename( LPSTR orig, LPSTR fname );
	int		newascii( LPSTR f, int ecode );
	int		findImageFile( LPSTR path );
	int		fixsindex( LPMFFIELD fld );
	int		getnewfn( int old );
 #ifdef INTERACTIVE
	void	fillfld( LPMFFIELD fld, LPSTR buf, int longDflags );
 #else
	int		fillfld( LPMFFIELD fld, LPSTR buf, char nomerge, int longDflags );
 #endif
	LPSTR	typestring( DWORD type );
	int		explain( void );
	int		deplain( void );
 #ifdef INTERACTIVE
	int		losefield( LPSTR ermsg, LPMFFIELD fld, int loseit );
 #else
	void	losefield( LPSTR ermsg, LPMFFIELD fld );
 #endif
	int		yxfarput( int type, int lgt, LPSTR buf );
	void	postit( LPSTR name, int ecode );
	int		endit( int bad, int zak, int mem );
	int		compilecalc( LPMFFIELD fld, int warn );
	int		compileValidate( LPMFFIELD fld, int warn) ;
	int		finishtotal( LPMFFIELD fld, int warn, LPINT lostit );

	LPSTR	filename( int fn, LPSTR fname );
 #if defined(RSW)
	void	freejoinpairs( void );
 #endif
	void	invValue(  LPSTR msg );
 #if defined(RSW)
	int		override( LPSTR dest, LPSTR source, LPSTR inp, LPSTR ext, BOOL path );
	BOOL	setlinkfld( YXBUF *buf, int count, LPSTR orig, LPSTR fname, int dsdir, char quote, int longDflags );
	BOOL	fixQuotes( LPSTR name, char quote );
 #else
	int		override( LPSTR dest, LPSTR source, LPSTR inp, LPSTR ext );
	BOOL	setlinkfld( YXBUF *buf, int count, LPSTR orig, LPSTR fname, int tag, int longDflags );
 #endif
	int		driveit( LPSTR dest );

	BOOL	fieldCases( LPINT status, int type, YXBUF *buf, int count, LPINT nomerge, LPSTR fname );
 #if defined(RSW)
	BOOL	fileCases( LPINT status, int type, YXBUF *buf, int count, LPSTR fname, LPSTR samedir,
						LPINT goodver, LPSTR dpath, LPINT fileflags, char quote );
	BOOL	joinCases( LPINT status, int type, YXBUF *buf, int count, LPINT fileflags, char quote );
	BOOL	sqlCases( LPINT status, int type, YXBUF *buf, int count, LPSTR fname, LPSTR dpath,
						LPINT master, LPSTR quote, LPINT nomerge );
  #if !defined(INTERACTIVE)
	BOOL	set_ridb_override( LPSTR file, BOOL master );
  #endif
 #else
	BOOL	fileCases( LPINT status, int type, YXBUF *buf, int count, LPSTR fname, LPSTR samedir,
						LPINT goodver, LPINT clip, LPINT setscope );
	BOOL	joinCases( LPINT status, int type, YXBUF *buf, int count );
 #endif
	BOOL	miscCases( LPINT status, int type, YXBUF *buf, int count, ATOM *faces, LPINT nomerge );
	BOOL	optsCases( LPINT status, int type, YXBUF *buf, int count, LPSTR oldops, LPINT repInchX, LPINT repInchY );
	BOOL	scopeCases( LPINT status, int type, YXBUF *buf, int count, int setscope, int clip );
	// ***** end _repio.h

	// ***** begin former "statics" from repio directory modules
public:
	char		NoMerge;
	DWORD		CondType;
	LPSTR		CondExp;
	int 		oldMeasure;
 #if defined(RSW)
	int 		Pic2Kludge;
 #endif

	BOOL	yxput( int type, int lgt, LPSTR buf );
	BOOL	yxMultiPut( int type, YXMULTI *multi );
	LPSTR	putstr( LPSTR ptr, LPSTR str );
	LPSTR	putlstr( LPSTR ptr, LPSTR str );
	BOOL	wstring( int type, LPSTR string );
	BOOL	wfontlib( void );
	BOOL	walias( void );
	BOOL	wpasswords(void) ;
	BOOL	wmapi( void ) ;
	void	filldbfld( LPMFFIELD fld, UONE buf[] );
	BOOL	fillhflags( LPMFFIELD fld, UONE buf[] );
	BOOL	fillnewhead( LPMFFIELD fld, UONE buf[] );
	BOOL	wascii( LPSTR buf );
	BOOL	wddbf( LPSTR buf );
	BOOL	wlink( char fn, UONE *buf, int flag );
	BOOL	wfields( int fn, UONE *buf );
	BOOL	doit( int fn, LPMFFIELD fld );
	BOOL	weval(LPMFFIELD fld, UONE buf[], int flag, int fn );
	BOOL	parameterList(LPMFFIELD fld, UONE buf[]) ;
	BOOL	putText( LPSTR data );
	BOOL	putBoxes( LPSTR data );
	BOOL	putCharts( void );
	int		lgetfn( LPMFFILE file );
	void	invneeded( void );
	BOOL	face_used( int font );
	BOOL	putTypefaces( void );
	BOOL	putWindowsRecs( LPSTR data );
	BOOL	putExportAddOns( void );
	void	fixFont( LPFLDHDR f, ATOM *ftab );
	void	fixUpFldFonts( ATOM *ftab );
	FLDID	newfndx( FLDID ndx );
	int		readend( char oldops[], int repInchX, int repInchY );
	UINT	yxget( YXBUF *buf, int *ct );
	UINT	yxgethead( YXBUF *buf, int *ct );
	UINT	yxgettail( YXBUF *buf, LPSTR tail );
	BOOL	setfield( YXBUF *buf, int nomerge, int count, LPSTR fname, int rectype );
	BOOL	settextfld( YXBUF *buf, int type );
	BOOL	setboxfld( YXBUF *buf );
	BOOL	openimgfile( LPSTR filename, BOOL diffdir, LPINT pChanged );
	BOOL	setimagefld( YXBUF *buf );
	BOOL	setdosimgfld( YXBUF *buf );
	BOOL	setcalcfld( YXBUF *buf, int nomerge, int count, int type );
	BOOL	compilecond( LPMFFIELD fld, int warn );
	BOOL	settotfld( YXBUF *buf, int nomerge, int count, int type );
 #if defined(RSW)
	BOOL	wdtc( LPSTR buf );
	BOOL	wdatasource( LPSTR buf, int fix );
	BOOL	inMasterDS( int fn );
	BOOL	inDSDir( LPSTR lpszName, int fn );
	BOOL	wmaster( LPSTR buf );
	int		readRpt( BOOL bUseszDataSource );
	BOOL	openMaster( LPINT err1, LPSTR orig, int next, int samedir, int fileflags, char quote );
	int		convertOrWhat( void );
	BOOL	loveralias( LPMFFILE ftb );
	LPMFFIELD makedummyfld( DWORD lft, LPSTR lfname, char newlfn, int related );
 #else
 	BOOL	windex( char buf[] );
	BOOL	wrange( int lo );
	BOOL	wmaster( void );
	BOOL	loadscopes( void );
	int		readRpt( void );
	BOOL	decidescope( char stype, LPINT clip );
	BOOL	openMaster( LPINT err1, LPSTR orig, int next, int samedir );
	int		lnewname( LPMFFILE f, int dbf, int master, int ecode, int recno );
	void	loveralias( LPMFFILE ftb );
	void	setkey( int setscope, int count, YXBUF *buf, int lo );
	void	setnkey( int setscope, int clip, int count, YXBUF *buf, int lo );
	void	setrecno( int setscope, int count, YXBUF *buf, int lo );
	void	setfieldkey( int setscope, int count, YXBUF *buf, int lo );
 #endif
	// ***** end former "statics" from repio directory modules
};
#endif
