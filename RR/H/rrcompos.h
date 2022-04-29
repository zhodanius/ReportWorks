// ****************************************************************************
//
//    (C) Copyright 2001 Liveware Publishing Inc.
//                All Rights Reserved.
//
//
// Module $Workfile:   rrcompos.h  $
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
// Revision    Date     Time    Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/RRCOMPOS.H_V  $
//
//    Rev 1.103   May 03 2004 16:34:58   Nick
// Minor changes
//
//    Rev 1.102   Feb 06 2003 19:05:16   Admin
// Prettify
//
//    Rev 1.101   Oct 31 2002 16:04:14   Admin
// Prettify and publicize clrtemps()
//
//    Rev 1.100   Oct 24 2002 09:18:26   Admin
// Prettify
//
//    Rev 1.99   Oct 07 2002 09:27:46   Admin
// Prettify and add some parameter scope things
//
//    Rev 1.98   Aug 12 2002 10:41:36   Admin
// Join Help launch; cosmetic
//
//    Rev 1.97   Jul 01 2002 15:24:32   Admin
// Add parameter to urddef()
//
//    Rev 1.96   Jun 05 2002 11:53:46   Admin
// Make szSourceName publis; add udf lib prototype
//
//    Rev 1.95   Apr 25 2002 10:18:44   Admin
// Prototypes for update dictionary calls
//
//    Rev 1.94   Dec 14 2001 11:49:10   Administrator
// make some var's public
//
//    Rev 1.93   Jun 05 2001 10:34:04   nhubacker
// Flag: AlwaysRR
//
//    Rev 1.92   Mar 15 2001 14:56:58   nhubacker
// expupdScan()
//
//    Rev 1.91   Feb 27 2001 15:39:44   nhubacker
// Support for lastpage() and reportpage()
//
//    Rev 1.90   Dec 12 2000 15:55:26   nhubacker
// Add functions for grpage()
//
//    Rev 1.89   Dec 05 2000 13:11:02   nhubacker
// Add CheckAlias()
//
//    Rev 1.88   Aug 31 2000 13:51:20   nhubacker
// Support for dbase 7.5 MDX files
//
//    Rev 1.87   Aug 30 1999 15:58:14   BUILD
//
//    Rev 1.84   09 Dec 1998 10:52:46   wrr
// Added WO134154 and Jim Ballard's fix for
// QE-Trace
//
//    Rev 1.83   30 Nov 1998 15:51:42   wrr
// Added 134154
//
//    Rev 1.82   30 Nov 1998 10:34:04   wrr
// May merge multiple fixes
//  Edited file with fix from 159630
//  Jim Ballard fix for Cube
//  User SQL
//
//    Rev 1.81.3.0   21 Sep 1998 14:54:04   wrr
// Edited file with fix from 159630
// Jim Ballard fix for Cube
// User SQL
//
//    Rev 1.81   21 Jan 1998 12:14:06   smh
// OEM20001 merge
//
//    Rev 1.80.3.0   15 Jan 1998 16:08:14   smh
// RRW 8.0 Abra OEM
//
//    Rev 1.80   24 Jun 1997 16:19:52   jpb
// WO 130059 - AlwaysPreFetch setting
//
//    Rev 1.79   20 Jun 1997 15:48:28   jpb
// fix WO129924 via UseQeConnect workaround
//
//    Rev 1.78   20 Jun 1997 11:43:18   jpb
// make routine public for WO 129695 fix
//
//    Rev 1.77   19 Jun 1997 19:08:56   jpb
// declare some rsw-specific ASCII memo needed routines
//
//    Rev 1.76   19 Jun 1997 10:05:22   hxc
// Added function DBIgetActiveDSDriverInfo to get DS Driver Info for printing
// the report spec.
//
//    Rev 1.75   17 Jun 1997 16:23:50   jpb
// improve situation of WO 129686 - give more helpful error message
//
//    Rev 1.74   13 Jun 1997 17:10:06   dlm
// Added code to "delete confirmation" dialog to explain which if any charts
//  will be affected.
// Added code to verify that all value fields are zfNUMERIC in
//  PrepareForPrinting.
// Modules are: rrchart.cpp, rrchlist.cpp, ddelcon.cpp, mfdelcon.cpp,
//  mfrepfld.cpp, wprint.cpp, rrw.str, common.rc, resource.h, rrdoc.h,
//  wdialog.h, rrcompos.h, rrchart.h
//
//    Rev 1.73   23 May 1997 15:36:20   SRM
// new field-position function, replacing unreadable macro
//
//    Rev 1.72   12 May 1997 13:43:30   dlm
// Replaced ChartNeeded() with ChartPassChartNeeded() and
//  PrintPassChartNeeded() declarations.
//
//    Rev 1.71   12 May 1997 09:04:48   hxc
// Additional Year 2000 change - adding one more parameter to CHECK2DY and argument
//
//    Rev 1.70   07 May 1997 11:19:24   pjm
// Change getLongName() prototype.
//
//    Rev 1.69   02 May 1997 16:55:06   dlm
// Removed CHARTING conditionals.
//
//    Rev 1.68   30 Apr 1997 17:09:52   dlm
// Added ChartCountBox declaration for charting pass status.
//
//    Rev 1.67   29 Apr 1997 09:11:06   dlm
// Added ChartNeeded(), ChartPass(), bChartCapture delcarations.
//
//    Rev 1.66   06 Apr 1997 13:07:50   pjm
// Modify declaration of getLongName function.
//
//    Rev 1.65   03 Apr 1997 21:07:16   pjm
// Add new function for long DBC tablenames.
//
//    Rev 1.64   27 Mar 1997 10:22:34   dlm
// Another round of charting code with stuff conditional on CHARTING.
//
//    Rev 1.63   14 Mar 1997 14:38:30   jpb
// equitrac runtime scripting support
//
//    Rev 1.62   10 Mar 1997 14:44:14   dlm
// Part of "fix" to RRW bug 2936 / RSW bug 2305.  Involves a change to the
//  way we decide whether two floating point values are "close enough" to
//  call them equal.  Modules are SXCOMPV.CPP, RRCOMPOS.CPP, WINIT.CPP,
//  GLOBAL.H, RRCOMPOS.H.  The significant changes are in SXCOMPV.CPP.  The
//  others relate to a new INI-file setting (FloatCompTolerance in Defaults
//  section).
//
//    Rev 1.61   10 Mar 1997 11:07:32   hxc
// Added check2DYDate to fix year 2000 problem.
//
//    Rev 1.60   01 Mar 1997 17:25:12   jpb
// fix rrw 2527
//
//    Rev 1.59   19 Feb 1997 14:57:02   dlm
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
//    Rev 1.58   10 Feb 1997 10:02:24   sp
// Arp Live merge to trunk
//
//    Rev 1.54.1.1   16 Dec 1996 16:14:02   pjm
// Move prototype for DBIgetDSConnectString into RSW conditionals.
//
//    Rev 1.54.1.0   24 Oct 1996 15:20:30   sp
// Added missing prototype.
//
//    Rev 1.56   17 Oct 1996 18:24:30   jpb
// fix VarFileInfo charset
//
//    Rev 1.55   10 Oct 1996 10:16:44   jpb
// for autoDS creation
//
//    Rev 1.0   24 Oct 1996 14:46:52   dlm
// Initial revision.
//
//    Rev 1.54   08 Oct 1996 16:50:06   amh
// Arp 1.0 U02 merged to trunk
//
//
//
//    H:\VCSMFC\H\RRCOMPOS.H_V  Rev "ARP 1.0 U02" (1.48.1.4)
//
//    Rev 1.48.1.4   10 Jul 1996 12:01:38   jpb
// put duplicate name in error message (helps RSW 2252)
//
//    Rev 1.48.1.3   08 Jul 1996 12:02:22   jpb
// add TestJoin
//
//    Rev 1.48.1.2   03 Jul 1996 10:00:30   jpb
// OdbcAdm - OdbcInstaller
//
//    Rev 1.48.1.1   01 Jul 1996 16:21:40   jpb
// fix RSW 1859 (max char literal len)
//
//    Rev 1.48.1.0   28 Jun 1996 18:36:46   jpb
// rsw 2202
//      H:\VCSMFC\H\RRCOMPOS.H_V  Rev 1.53
// $Log$
//
//    Rev 1.53   07 Oct 1996 17:43:06   jpb
// Add DBIgetConnectStringWithoutUidPwd()
//
//    Rev 1.52   07 Oct 1996 16:11:30   jpb
// remove DBIgetDSconnectString
//
//    Rev 1.51   10 Jul 1996 16:33:34   jpb
// add MFDupSelName (merge from U02 branch)
//
//    Rev 1.48.1.4   10 Jul 1996 12:01:38   jpb
// put duplicate name in error message (helps RSW 2252)
//
//    Rev 1.48.1.3   08 Jul 1996 12:02:22   jpb
// add TestJoin
//
//    Rev 1.48.1.2   03 Jul 1996 10:00:30   jpb
// OdbcAdm - OdbcInstaller
//
//    Rev 1.48.1.1   01 Jul 1996 16:21:40   jpb
// fix RSW 1859 (max char literal len)
//
//    Rev 1.48.1.0   28 Jun 1996 18:36:46   jpb
// rsw 2202
//
//
//    Rev 1.48   06 Jun 1996 14:09:54   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
//
//    Rev 1.47   29 Apr 1996 18:25:56   jpb
// add DBIdataSourcePassExec
//
//    Rev 1.46   23 Apr 1996 14:09:38   pjm
// Add prototype for MFXFLD_ResetAlias().
//
//    Rev 1.45   22 Apr 1996 17:28:18   jpb
// Add DBIfixTableName to quote delimit qualifier and tablename portions
// of a qualified tablename on a platform supporting joins across dirs.
// This is to deal with spaces imbedded in such names.
//
//    Rev 1.44   29 Feb 1996 16:06:12   pjm
// Make some stuff public so it can be deleted on exit.
//
//    Rev 1.43   29 Feb 1996 16:00:06   jpb
// make MFSQLCIPName public for RWQ processing in wreport.cpp
//
//    Rev 1.42   16 Feb 1996 11:38:40   pjm
// Make freextab() public so we can call on exit.
//
//    Rev 1.41   14 Feb 1996 10:06:22   dlm
// Made dataSourceDialog public when RUNDLL is defined.
//
//    Rev 1.40   08 Feb 1996 17:41:58   jpb
// add arg to dbiconnectdatasource
//
//    Rev 1.39   08 Feb 1996 17:32:40   dlm
// Added some RSW runtime DLL stuff.
//
//    Rev 1.38   23 Jan 1996 19:06:18   jpb
// fox integer type
//
//    Rev 1.37   29 Dec 1995 13:59:18   dlm
// Added conditionals to allow use in runtime DLLs.
//
//    Rev 1.36   14 Dec 1995 16:49:38   jpb
// runtime
//
//    Rev 1.35   13 Dec 1995 17:38:56   dlm
// Made keytod() public for the benefit of the runtime DLL.
//
//    Rev 1.34   21 Nov 1995 09:21:48   smh
// Win32 file i/o for sort.
//
//    Rev 1.33   20 Nov 1995 15:49:52   smh
// Win32 file i/o.
//
//    Rev 1.32   17 Nov 1995 19:04:10   smh
// Win32 file i/o.
//
//    Rev 1.31   17 Nov 1995 10:12:48   jpb
// declare uFreeUdfs
//
//    Rev 1.30   17 Nov 1995 10:02:24   pjm
// Change the p and lp variables to evalx1 and evalx2.
//
//    Rev 1.29   16 Nov 1995 15:23:12   sjo
// Added prototype for routine to release memory needed for memo handling.
//
//    Rev 1.28   16 Nov 1995 12:12:14   dlm
// Added destructor declaration.
//
//    Rev 1.27   07 Nov 1995 17:52:16   jpb
// add RSW routine prototypes for plug and play
//
//    Rev 1.26   03 Nov 1995 17:50:58   jpb
// move doc member routine to app
//
//    Rev 1.25   24 Oct 1995 17:43:58   jpb
// add getDrives member function and support
//
//    Rev 1.24   11 Oct 1995 09:03:00   smh
// luwrec now takes a short instead of an integer.
//
//    Rev 1.23   29 Sep 1995 17:08:10   jpb
// make eng dialog callbacks static
//
//    Rev 1.22   27 Sep 1995 17:19:10   jpb
// add prototypes for sx convert routines
//
//    Rev 1.21   26 Sep 1995 14:07:58   pjm
// RSW composite class changes (de-static some routines).
//
//    Rev 1.20   25 Sep 1995 16:57:46   jpb
// change erf prototype
//
//    Rev 1.19   25 Sep 1995 10:12:52   mjs
// Change utime, fltime().
//
//    Rev 1.18   22 Sep 1995 17:26:20   sjo
// Fixed a compiler problem.
//
//    Rev 1.17   22 Sep 1995 17:13:36   sjo
// Second round of FLDID changes.
//
//    Rev 1.16   22 Sep 1995 10:58:02   pjm
// RSW composite class stuff.
//
//    Rev 1.15   21 Sep 1995 17:14:22   dlm
// FLDID-related edits.
//
//    Rev 1.14   21 Sep 1995 16:33:22   sbc
// Fix MFFldDel argument - now FLDID
//
//    Rev 1.13   21 Sep 1995 15:46:52   jpb
// FLDID
//
//    Rev 1.12   20 Sep 1995 15:01:28   jpb
// move ndxupd to rrcomposite class
//
//    Rev 1.11   20 Sep 1995 10:52:12   jpb
// zapfield changes
//
//    Rev 1.10   19 Sep 1995 15:26:54   par
// sxvaldel needs to be declared the same as the functions being passed it.
//
//    Rev 1.9   19 Sep 1995 14:36:10   par
// SRPack should take a UINT.
//
//    Rev 1.8   19 Sep 1995 14:31:52   jpb
// keepcount/sxgetnext args
//
//    Rev 1.7   19 Sep 1995 13:06:34   jpb
// change mfpostread arglist
//
//    Rev 1.6   19 Sep 1995 11:22:14   par
// Constructor should take a doc object as a parameter for initialization.
// Added runtime type info through DECLARE_DYNAMIC.
//
//    Rev 1.5   19 Sep 1995 09:38:22   jpb
// make constructor public
//
//    Rev 1.4   18 Sep 1995 19:02:38   jpb
// merge some changes I missed
//
//    Rev 1.3   18 Sep 1995 17:51:16   jpb
// change pDoc to pComposite
//
//    Rev 1.2   18 Sep 1995 17:45:20   jpb
// change CRrDoc* args to CRrComposite* args
//
//    Rev 1.1   18 Sep 1995 16:35:32   jpb
// declare constructor
//
//    Rev 1.0   18 Sep 1995 15:02:56   jpb
// Initial revision.
//
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _RRCOMPOSITE_H_

// Make a definition for this module.
//
#define _RRCOMPOSITE_H_

// rrcompos.h : interface of the CRrComposite class
//
/////////////////////////////////////////////////////////////////////////////
   #include "mfedit.h"     // needed by MF stuff
   #include "rrxfld.h"     // needed by MF stuff
   #include "mffile.h"     // needed by MF stuff
   #include "memo.h"    // needed by MF stuff
   #include "_mffield.h"   // needed by MF stuff
   #include "_mfdata.h" // needed by MF stuff
   #include "_mfedit.h" // needed by MF stuff
   #include "cfmisc.h"     // needed by MF stuff
   #include "print_.h"     // needed by misc stuff (defines BRKFLD, et. al.)
   #include "mfxfld.h"     // needed by MF stuff
#if defined RSW
   #include "qelib.h"      // needed by ENG stuff
   #include "dbipriv.h" // needed by ENG stuff
   #include "_ddata.h"     // needed by ENG stuff
   #include "_eng.h"    // needed by ENG stuff
#endif

class CRrDoc;

class CRrComposite : public CObject
{
public:
   DECLARE_DYNAMIC(CRrComposite) ;

         CRrComposite(CRrDoc* pDoc);   // constructor
   virtual  ~CRrComposite();        // destructor

   CRrDoc*  m_pDoc ;

   void  ChartPassChartNeeded( void);
   void  PrintPassChartNeeded( void);
   int      ChartPass( void);
   void  ChartCountBox( void);
   bool  parameterNeeded(LPMFFIELD fld) ;

   BOOL  bChartCapture;

   // misc stuff from doc:
   BOOL  m_bChangedDataBaseName; // jjou, add one flag to verify the status for whether switching DB name.
   int      DBAnsi;     // assume OEM character set in databases
   int      ExactComp;  // assume approximate comparisons
   BOOL  CompFlat;   // for case sensitivity
   int      IndexFlat;  // assume case-dependent indexes
   int      IndexSRT;   // assume not using SRT rules with indexes
   int      IndexWin;   // assume not using Windows routines with indexes
   int      ReportPass;
   BOOL  SortFlat;   // for case sensitivity
   int      SpaceDot;   // space-dot character - replaces zdSPC and ANSI_DOT parameters - from SRT file
   char  *RpSelEd;
   UTWO  RpSelLen;
   int      mightmerge; // just to be safe
   CString m_strAliasOfDBFileName;  // WO182719 Jou for temporary file flag checking purpose.
   int      gotmemo(void);

   BOOL  lastPage(void) ;

   // from wreport\rpinit.cpp:
   #if defined(INTERACTIVE)
   void  zapfield( FLDID n );
   #endif

   // from repio\grmisc.cpp
   void  ndxupd( FLDID i );

   // ***** begin filter.h
public:
   int         SXTot;
   int         SXSortComp;
   LPSTR    SXCurPtr;
   int         InMMatch;
   int         m_FloatComp;      // A small signed number.  See sxcompv.cpp.
   double      m_fCompTolerance; // If m_FloatComp is negative, this is that power of 10.
 #if defined(RSW)
   int         QueryChanged;
   int         SXForSelect;

   // sp 2/5/97 merge
   // sp 10/24/96 added DBIgetDSConnectString function declaration
   //virtual int DBIgetDSConnectString(LPSTR lpszDS, LPSTR lpszConnect, int iConnectLen);
 #endif

   int      sxbadfinal( LPSTR expr, UINT elgt );
   LPSTR sxcktot( LPMFFIELD fld, LPSTR expr, UINT elgt );
   int      sxcompvalue( LPSTR left, LPSTR right, DWORD type );
// int      sxcompvalue( char near *left, char near *right, DWORD type );
   int      sxdelfld( LPSTR expr, UINT elgt, FLDID ix );
   int      sxdoit( int termcnt, LPPKSX termarray, LPINT errcode, LPINT changed );
   int      sxfintot( LPSTR expr, UINT elgt );
   int      sxinuse( LPSTR expr, UINT elgt, FLDID ix );
   void  sxinvalue( LPSTR in, LPSTR out, int type );
   int      sxlen( void);
   int      sxload( int termcnt, LPPKSX termarray );
   void  sxneeded( LPSTR expr, UINT elgt );
   int      sxparse( void);
   void  sxprint( LPSTR buf, int maxsize );
   int      sxreject( LPSTR eval, int nottot );
   int      sxruntot( LPSTR expr, UINT elgt );
   int      sxterms( void);
   void  sxunparse( void);
   int      sxvalidate( LPSTR expr, UINT elgt );
   int      sxvalquery( int termcnt, LPPKSX termarray, LPINT errcode, LPINT badterm );
   int      sxvalterm( LPPKSX term, LPINT errcode, LPINT erroffP );
   LPSTR testwdate( LPSTR input );
#ifdef RSW
   void  sxrepfld( LPSTR expr, UINT elgt, FLDID old, FLDID newsx );
   int      sxselect( LPSTR outSpace, LPSTR prefix );
   int      lsxmmatch( LPSTR pat, LPMFFIELD fld, int wilds );
#else
   int      lsxmmatch( LPSTR pat, LPMFFIELD fld );
#endif
   UINT  sxconvertsize( LPSTR in, UINT inlgt, BOOL to32bit);
   BOOL  sxconvert( LPSTR in, UINT inlgt, LPSTR out, UINT outlgt, BOOL to32bit);
   void  sxsoften( LPSTR expr, UINT elgt );
   // ***** end filter.h

   // ***** begin qeval.h
   LPQTSTR  QTFirst;    // pointer to first QTStr
   LPQQSTR  QQFirst;    // pointer to root QQStr node of query
   LPSTR EvalStart;
   int      QQError;
   UINT  SXCurTime;
   int      SXMultiScan;

   void  freeqqstr( LPQQSTR qq );
   void  sxclearval( LPQQSTR qq );
   int      sxeeval( LPSTR eval, LPVOID ptr );
   int      sxeord( void);
   int      sxeprep( void);
   // ***** end qeval.h

   // ***** begin _filter.h
public:
   int      sxbytes( LPSTR item );
private:
   FLDID    SXIx;
   int         SXUsed;
#if defined(RSW)
   LPSTR    SXOpPtr;
   LPSTR    SXSelOut;
   char     SXSelOp;
#endif

   FOUR  pos (LPFLDHDR f);
   int      bscount( LPSTR p, int lgt );
// int      sxbytes( LPSTR item );
   int      sxcompfield( LPMFFIELD f, LPSTR v );
   int      sxgetnum( LPSTR *eval  );
   int      sxlvlerr( UINT fno );
   int      sxokay( LPSTR expr, UINT elgt );
   int      sxtotal( LPSTR expr, UINT elgt );
   char  sxtype( int typeBits );
   int      sxvaldel( LPSTR expr, UINT elgt, FLDID (*func)( CRrComposite*, FLDID ) );
 #ifdef RSW
   void  fixLower( void);
   void  sxoutdate( LPSTR dt, LPSTR string );
   void  sxoutdatetime( LPSTR dt, LPSTR string);
   void  sxouttime( LPSTR dt, LPSTR string);
   void  sxoutnum( LPSTR num, LPSTR string );
   void  sxoutstring( LPSTR in, LPSTR out );
   void  sxoutval( char type, LPSTR in, LPSTR out, int mn, int mx );
 #endif
   // ***** end _filter.h

   // ***** begin former "statics" from filter directory modules
public:
static   int      pop( CRrComposite* pComposite, LPSTR *item, int size, int type );
static   int      push( CRrComposite* pComposite, LPSTR *item, int size, int type );
static   int      err( CRrComposite* pComposite, LPSTR *item, int size, int type );
static   int      cancel( CRrComposite* pComposite, LPSTR *item, int size, int type );
static   int      done( CRrComposite* pComposite, LPSTR *item, int size, int type );
private:
   int         _SX_hilvl;
   int         _SX_NotTot;
   int         _SX_tsTop;
   TEMPITEM*   _SX_tempStack;
   int         _SX_osTop;
   OUTITEM  ** _SX_outStack;
   OUTITEM  *  _SX_outFree;
   int         _SX_outCount;
   LPSTR    _SX_out;
   int         _SX_parseError;
 #if defined(INTERACTIVE) && defined(RSW)
   FLDID    _SX_New;
 #endif
   int         _SX_toterr;
   int         _SX_hifin;
 #if defined(RSW)
   LPSTR    _SX_LPtr;
   LPSTR    _SX_LEndPtr;
   int         _SX_LenPre;
   int         _SX_LenPost;
   int         _SX_CallReject;
 #endif


   int      value( LPSTR *expr );
   OUTITEM* makeout( TEMPITEM *t );
   void  addsibling( OUTITEM *base, OUTITEM *newKid );
   void  pushout( OUTITEM *o );
   void  fudgerelop( OUTITEM *o );
   int      getclass( char x );
   void  serialize( OUTITEM *head, int reallyDoIt );
   int      cleanup( int val );
 #if defined(RSW)
   int      lmatch( LPSTR s, LPSTR p, int t, int w );
 #else
   int      lmatch( LPSTR s, LPSTR p, int t );
 #endif
   int      comp( double lft, double rght );
   int      notfpe( void);
   int      toterror( LPMFFIELD fld );
   int      uniquename( LPMFFIELD fld );
   int      errortype( DWORD type );
   LPSTR sxgetdelim( LPPKSX termarray );
   int      emptyval( LPSTR p, LPMFFIELD f );
   int      emptylen( LPMFFIELD f );
   int      sxbufsize( int termcnt, LPPKSX termarray );
   LPQQSTR  make1qqstr( LPSTR *eval, FLDID fld1, FLDID fld2, LPSTR tokp );
   FLDID fconvert( FLDID fld );
   LPQQSTR  makeqqstr( LPSTR *eval );
   int      sxscanq( FLDID fid, LPVOID ptr );
   int      sxfileno(  int fno );
   int      sxgetfn( LPMFFILE file );
   int      sxchain( LPMFFIELD fld );
   int      eeval( LPSTR *expr );
   int      early( LPQQSTR qq );
 #if defined(RSW)
   BOOL  wackydate( LPSTR item );
   BOOL  examine( LPSTR *expr );
   void  append( LPSTR buf );
   void  appendconst( LPSTR con, char op );
   void  appendfield( FLDID fnum );
   BOOL  wildcard( LPSTR ptr, char card );
   BOOL  wildconst( LPSTR ptr );
   void  appendlistval( LPSTR item, char op, int first, FLDID fnum );
   BOOL  stilllist( LPSTR item, LPSTR itemEnd );
   BOOL  uncomp( LPSTR *eval );
 #endif
      // routines called by sxvaldel()
static   FLDID    badfin( CRrComposite* pComposite, FLDID ix );
static   FLDID    chkix( CRrComposite* pComposite, FLDID ix );
static   FLDID    delix( CRrComposite* pComposite, FLDID ix );
static   FLDID    final( CRrComposite* pComposite, FLDID ix );
static   FLDID    isokay( CRrComposite* pComposite, FLDID ix );
static   FLDID    needs( CRrComposite* pComposite, FLDID ix );
static   FLDID    newix( CRrComposite* pComposite, FLDID ix );
static   FLDID    repfld(  CRrComposite* pComposite, FLDID ix );
static   FLDID    running( CRrComposite* pComposite, FLDID ix );
static   FLDID    total( CRrComposite* pComposite, FLDID ix );
static   FLDID    softener( CRrComposite* pComposite, FLDID ix );

   // ***** end former "statics" from filter directory modules

   // ***** begin index.h
public:
   LPSTR    NodeBuf; /* ptr to node read buffer */
   int         _klerr;  /* error code */

   int      kltagchain( LPSTR ntxname, TNAME **chainP );
   void  klfreetag( void);

   int      lklckey( KLNTXFILE * ntxfd, LPSTR key, LPLONG recno );
   int      lklcleanup( LPKLNTXFILE* ntxs, int stop );
   int      lkliopen( LPSTR ntxname, KLNTXFILE ** ntxfd, int newone, LPSTR tag );
   int      lkliclose( KLNTXFILE * ntxfd );
   int      lklinit( LPKLNTXFILE* ntxs, int stop );
   int      lklnkey( KLNTXFILE * ntxfd, LPSTR key, LPLONG recno );
   int      lklpkey( KLNTXFILE * ntxfd, LPSTR key, LPLONG recno );
   int      lkltkey( KLNTXFILE * ntxfd, LPSTR key, LPLONG recno );
   int      lklkexpr( KLNTXFILE *ntxfd, LPSTR keytype, LPSTR keyexpr, LPINT kexprlen, LPSTR keylen, LPINT unique, LPINT descend );
   int      lkltkeyext( KLNTXFILE * ntxfd, LPSTR key, LPLONG recno, int len );
   // ***** end index.h

   // ***** begin _index.h
private:
   LPKLNTXFILE NTX;     /* global pointer to current file descriptor*/
   LPKLNODE NodePath;   /* pointer to array of KLNODE strucs */
   int         NPIndex; /* level index in node path array */
   int         KlBufs[MAXNTXS]; /* which kl buffers are in use (file pos of node if using small memory model) */
   int         IndexType;  /* dbase, clipper, or foxbase? */

   int      lklcurrent( KLNTXFILE * ntxfd, int tkey );
   void  lextractkey( LPSTR key, LPLONG recno );
   void  lklbcdtof( LPSTR nP, LPSTR fP );
   void  lkldecomp( LPSTR key, LPLONG recP, int keypos );
   int      lkldecode( LPSTR key, LPKLNTXFILE ntx, int itype );
   void  lklxdecomp( LPSTR node, int keylen, char type, LPSTR key, LPLONG recP, int keypos, LPLPSTR v , LPLPSTR e );
   int      extractnkeys( void);
   int      readnode( long nodePos, int init, int priority );
   int      lprevkey( LPSTR key, LPLONG recno );
   int      lnextkey( LPSTR key, LPLONG recno );
   int      leafnode( void);
   void  extractpos( LPLONG pos );
   int      ltravup( LPINT index, LPLONG nPos );
   int      ltravdown( long nPos, LPSTR key, LPLONG recno );
   int      lklcmpbcd( LPSTR left, LPSTR right );
   void  lklidecomp( LPSTR key, LPLONG recP, int keypos, LPLPSTR v , LPLPSTR e );
   void  lklencode( LPSTR key, LPKLNTXFILE ntx, int itype, int *truncated );
   int      lklftobcd( LPSTR fP, LPSTR nP );
   void  lklnsxdecomp( LPSTR key, LPLONG recP, int keypos );
   // ***** end _index.h

   // ***** begin former "statics" from index directory modules
private:
   BOOL  wdx;
   int      tagcount;
   BOOL  mdx7;
   TNAME*   tagchain;
   LPSTR ndxname;

   int      lklncomp( double far *left, double far *right );
   int      lklicomp( LPLONG left, LPLONG right );
   int      lcompkey( LPSTR entry, LPSTR sought, int len, int type );
   int      lscannode( long nPos, LPSTR key, LPLONG recno, int keylen, int truncated );
   void  freetchain( void);
/*  
   Added this bit of compiler directives so that we can have the old way of dealing with things for RSW
   and the new ADS way of doing stuff for RRW  [CAS 2/6/2013]
*/
#if !defined(RSW) //&& !defined(CAS_INTERACTIVE)
   int      gettchain( CADSFile& fdCFile, long tagblock, int tlen ); //removed & by CAS 1/29/2013
#else
	int		gettchain( CFile& fdCFile, long tagblock, int tlen );
#endif
   //int      gettchain( CADSFile fdCFile, long tagblock, int tlen );
   LPSTR fname( void);
   int      lmatchtag( LPSTR tag, LPKLNTXFILE ntx );
   int      lgettname( LPSTR tag, LPKLNTXFILE ntx );
   int      lkliop( LPSTR ntxname, KLNTXFILE ** ntxfd, LPSTR tag, int fortags );
   BOOL  giveback( LPKLNTXFILE ntx, LPKLNODE np );
   BOOL  klputmem( LPKLNTXFILE ntxs[] );
   void  get_startkey( LPSTR key, int keylen );
   void  lklnsxxdecomp( LPSTR node, int keylen, char type, LPSTR key, LPLONG recP, int keypos );
   void  lflipflop( LPSTR key, int len );
   void  lcomplement( LPSTR key );
   // ***** end former "statics" from index directory modules

   // ***** begin sort.h
public:
   LPMFFIELD *    SRFields;         // list of fields to sort; ends with NULL
   UINT        SRMxRcSz;
   int            SRNoPtrs;
   UINT        SREmptyOrder;     // flag for how to sort empty values for platform compatibility
   UINT        SREmptyNumsZero;  // if TRUE, treat empty NUMs as zeros
   UINT        SRPoolSize;
 #if !defined(INTERACTIVE)
   int            SRHiTemp;
 #endif
   BOOL  sort( LPMFFIELD *fields, LPINT ascend, LPSTR sortFile );
   BOOL  gsort( LPMFFIELD *fields, LPINT ascend, LPSTR sortFile, int (*init)( CRrComposite* ),
            void  (*end)( CRrComposite* ), int (*rd)( CRrComposite* ), int (*wr)( CRrComposite*, CFile*, LPSTR ),
            int (*pack)( CRrComposite*, LPSTR, UINT ), int noptrs, LPSTR outext, int mergemode );
   void  srdeltemps( int lastTemp );
   // ***** end sort.h

   // ***** begin _sort.h
private:
   LPINT SRAscend;      // for each SRFields item: sort ascending?
   int      SRMergeMode;   // mfpstat() mode for merge phase display
   int      SRPktSize;     // size of sort packet
   DWORD SRRecNo;
   LPSTR SRBuffer;      // for merge file buffering
   UINT  SRBufCt;    // number of chars in buffer, so far
   UINT  SRBufSize;     // buffer size
   int   SRTypes[MAX_SORT_FIELDS];  // stXXXX data types of SRFields[]

   // maximum of MAX_MERGE_FILES input files + one output file
   // last entry is used for output file
   CFile SRHandles[MAX_MERGE_FILES+1];

   // routine pointer prototypes
   int      (* SRRead)( CRrComposite* );
   int      (* SRWrite)( CRrComposite*, CFile*, LPSTR );
   int      (* SRPack)( CRrComposite*, LPSTR, UINT );

   BOOL  srmerge( UINT high, LPSTR resultFile );
   BOOL  srinsertsort( LPLPSTR memory, int ff, int jj );
   BOOL  srsortmemory( LPLPSTR memory, /* int firstRecord,*/ int lastRecord );
   BOOL  srsortfile( LPINT lastTemp, LPSTR sortFile );
   void  srexchange( LPLPSTR one, LPLPSTR two );
   BOOL  srinorder( LPSTR earlier, LPSTR later );
   void  srbase36( LPSTR string, UINT num );
   void  srtempname( LPSTR name, int num );
   BOOL  srmaketemp( CFile* sortfile, int fileNum );
   BOOL  srflushbuf( CFile* outFile );
   BOOL  srrdrecord( CFile* inFile, LPSTR record );
static   BOOL  srwrrecord( CRrComposite*, CFile* outFile, LPSTR record );
   // ***** end _sort.h

   // ***** begin former "statics" from sort directory modules
private:
      // former static variables (without _SR_ prefix)
 #if defined(RSW)
   long   _SR_currec;
 #endif
   UINT  _SR_maxFiles;        // computed by srmerge() at runtime
   int      (* _SR_writer)( CRrComposite*, CFile*, LPSTR );    // routine to write a sort record
   int      _SR_tempNum;   // number of last temporary file created

      // former static routines
      // These are static member functions so that they can be called through
      //  pointers.  Note that they all take a pointer to a document, explicitly
      //  so that they can get at member variables.
   static   BOOL  oinit( CRrComposite* pComposite );
   static   int      oread( CRrComposite* pComposite );
   static   BOOL  opack( CRrComposite* pComposite, LPSTR rec, UINT bytesLeft );
   static   BOOL  owrite( CRrComposite* pComposite, CFile* outFile, LPSTR record );
   static   void  oend( CRrComposite* pComposite );

   BOOL  opengroup( int first, int last );
   void  closegroup( );
   void  removegroup( int first, int last );
   void  reheap( LPLPSTR memory, int numFiles, int first );
   BOOL  mergegroup( int numFiles, LPSTR  srbuffer, UINT srbufsize );
   BOOL  savememory( LPLPSTR memory,   int lastRecord, int fileNum );
   // ***** end former "statics" from sort directory modules

// BEGIN block from the various mf* and _mf* headers:
// From mfdata.h - variables:
public:
#if !defined(RSW)
   int      CharFldSize;
   int      SoftenDBFields;
#endif
#if RSW
LPSTR MFSQLcontrol;
#endif
   int      bMidGo;
   int      bRandomMode;
   int      bSeqPass;
   int     groupmap[NOBRKFLDS];
   long  LKAge;            /* lookup buffer LRU pseudo-time */
   int     MFDbaseEd;         /* TRUE if using dBASE III editor's memos */
   char  *mfexttab[6];     /* default index file extensions for zfilmenu calls */
   int     MFCurOpen;         /* cur number of files mf has open */
   int     MFDels;            /* if TRUE, read deleted records */
   int     MFNonDels;         /* if TRUE, read non-deleted records */
   int     MFDialog;       /* "master file is DIALOG" flag */
   LPMFFILE MFErrFile;        /* file being processed when lookup failed */
   char  *MFHiKey;         /* pointer to high end of range (or NULL) */
   char  *MFLoKey;         /* pointer to low end of range (or NULL) */
   FLDID MFLoField;        // Low scope field id
   FLDID MFHiField;        // Hi scope field id
   char  MFNdxType;        /* master index type ('C', 'N', 'D', or '\0') */
   long  MFLoRecNo;        /* starting record number (or 0xFFFFFFFF) */
   long  MFHiRecNo;        /* ending record number (or 0) */
   int     MFMaxOpen;         /* max files allowed open by mf */
   int     MFShMode;       /* shared mode for DBF/DBT opens */
   char  *MFWhere;         /* additional where text for runtime */
   void  (CRrComposite::*MFFldDel)(FLDID);   /* address of routine to adjust for field deletion */
   int     MFNeedSnap;        /* will we need read ahead? */
   int     MFSnap;            /* have we a snapshot? */
   BOOL  bTotaling;        // Okay to total (replacement for MFTotal function pointer)

// From mfdata.h - functions:
public:
   int     buildfinals(int row,int col);
   int     clpnseq(char *x,char *y);
   char  *colref(struct mffield far *fld,struct mffile far *file,int bufno);
   void  emptyfield(struct mffield far *cfld);
   int     getfinal(void);
   void  mfclrbufs(void);     // was in both _mfdata.h and mfdata.h
   void  mfcopyflds(void);
   void  mfcpyscn(void);
   int     mfdbsize(struct mffield far *fld);
   void  mfeval(LPMFFIELD fld);
   int     mfexpinfo(char far *exp,struct mffield far *fld, int action,int disperr);
#if defined RSW
   int     mfgetbuf(void);
#else
   int     mfgetbuf(int unsorted);
#endif
   int     mfgetmch(struct mffield far *fld,char far *dataP,int coff,int applyFont);
   void  mfgetpos(long *pos);
   int     mfgetrec(int (*postRead)( void));
   int     mfgetstart(char far *sortfile);
   int     mfgetstop(void);
   int     mfgstop(int fins);
   int     mfgo(void);
   LPSTR mfjobsel(void);
   void  mflgetpos(long far *pos);
   void  mfmemcpy(char far *src,char far *dest);
   void  mfmeminit(void);
#if defined RSW
   void  mfneeded(int forsave);
   void  getColAndTableNames(LPMFFIELD pFld);
#else
   void  mfneeded(void);
#endif
   int     mfonebuf(struct mffield far *fld);
   void  mfoptbuf(void);
   void  mfoptrls(void);
   void  mfpgeval(void);
   long  *mfptbuf(char far *p);
   int     mfrdnext(int (*postRead)( void),int lastret);    // was in both _mfdata.h and mfdata.h
   int     mfrdnxrec(int (*postRead)( void),long recno,int lastret);
   int     mfrdrec(FOUR pos[], int lastret);
   int     mfreal(LPMFFIELD fld);
   void  mfReleaseMemoMemory();
   void  mfrlsbuf(void);
   void  mfrlsfld(struct mffield far *f,int o); // was defined in both mfdata.h and _mffield.h
   int     mfrestore(void);
   int     mfsave(void);
   int     mfsctest(int fno,int cur);
   void  mfsetsqlneeds(void);
   int     lmfskprec(LPMFFILE fileP);
   int     mfsortlist(LPMFFIELD sfa[],int saa[],int row,int col);
   int     mfsqlsel(int mode);
   void  mfstop(void);
   int     mftottot(int level);

// From mfedit.h - functions:
public:
   void  delgo(void);
   int delprep(int flnum,int *cntP);
   void  editasciigo(struct pkascii *asciip);
   int editasciiprep(struct pkascii *asciip,int *cntP);
   void  editasciiquit(void);
   int editgo(struct pkrel *relp);
   int editmastgo(struct pkmast *mastp);
   int editmastprep(struct pkmast *mastp);
   void  editmastquit(void);
   int editprep(struct pkrel *relp,int flnum,int *cntP);
   void  editquit(void);
   int fileline(int flnum,char *st);
   int filetext(int flnum,char *st);
   void  getascii(struct pkascii *asciip);
   BOOL getDateTimeValue(LPSTR in, ZDATETIME *dt, BOOL lo);
   int getjoincount(int flnum);
   void  getmast(struct pkmast *mastp);
   int getrel(struct pkrel *relp,int flnum);
   int indexinfo(LPSTR name, char *tag, int *typeP, int *needtagP);
   void  initscopes(void);
   int laliasline(char FAR *alias);
   struct mffile FAR *lfilen(int n);   // was defined in both mfedit.h and _mfedit.h
   void  lmfdelcan(struct udf FAR *xudf);
   int lmfedcon(char FAR *partial,struct mffield FAR *xcf,struct udf FAR *xudf);
   int mfdelcon(char *partial);
   void  putdatetime(int hi, ZDATETIME *dt);
#if !defined RSW
   char *scopestr(int hisc);
#endif
   int select_mode(void);
   int CheckAlias(struct pkrel *relp) ;
   int setrel(struct pkrel *relp);
   int setscstr(char *buf,int hisc);
   int getgroup(int flnum,PKGROUP far *groupp);
   int ingroup(int flnum);
   int setgroup(int *flnump,PKGROUP far *groupp);

// From mferror.h - variables:
public:
#if defined INTERACTIVE
   char RpQuery;
#endif
   int qenum;

// From mferror.h - functions:
public:
   int chgfinals(struct mffield FAR *fld);
   int ckfinals(HWND handy,int warn);
   void  mfack(int err);
   int mfbagit(int ecode);
   char *mferror(int ecode);
   int mflocalsort(void);
   void  mfpstat(int mode,int row,int col);
   void  mfqerr(int n);
   void  mfreperr(int ecode);
   int mfrunerr(FLDID fnum);
   void  mfwack(HWND w,int err);

// From mffield.h - variables:
#if defined RSW
private:
   char MFDupSelName[MFFIELDNAMESIZE];
#endif
public:
   LPMFFIELD DFBadFld;
   // 7/22/97 MFC - ABRAFIX: COnversion to RRW 8.0
#if defined(RECORD_FILTER)
   unsigned int MFQDisambiguate;
#endif
#if 0 // MFC conversion - this isn't referenced
   unsigned int MFQDisambiguate;
#endif
//#if defined INTERACTIVE
   MFF_FILENO_HEADER far *fileno_header;
//#endif

// From mffield.h - functions:
public:
   int bf(FLDID ndx);
   int df(FLDID ndx);
   void  fixdupnames(void);
   FLDID lmfgetndx(struct mffield far *fld);
   struct mffield far *mfbyndx(FLDID i);
   struct mffield far *mfcalc(char *name,char *expr,BOOL fromdd, struct mffield far *firstfld);
   int mfdelcnt(void);
   void  mfdelfld(void);
   struct mffield far *mfdupfld(struct mffield far *fld);
   struct mffield far *mfeord(void);
   int mfflagall(int links);
   int mfflagcalc(void);
   int mfflagem(void);
   void  mffreecb(struct mffield far *f);
   struct mffield far *mfgetfld(int o);
   int mfhifinal(void);
   int MFQInit(void);
   void  MFQRelease(void);
   int sf(FLDID ndx);
   int tf(FLDID ndx);
   int totOkay(int level,struct mffield far *fld);
   void  eordPanicMessage(LPMFFIELD fld);


   // from rrxfld.h
public:
   static rrAPI(rrSTATUS) RREXP_SetFieldOptions(int handle, LONG lFieldOptions);
   static rrAPI(rrSTATUS) RREXP_SetExportOptions(int handle, LONG lFieldOptions);
   static rrAPI(rrSTATUS) RREXP_SetState(int handle, BOOL bSave, BOOL bActive);
   static rrAPI(rrSTATUS) RREXP_GetFirstField(LPSTR lpszAliasBuf, LPSTR lpszFieldBuf, LPSTR lpszFieldAndCommentBuf, LONG far *lData);
   static rrAPI(rrSTATUS) RREXP_GetNextField(LPSTR lpszAliasBuf, LPSTR lpszFieldBuf, LPSTR lpszFieldAndCommentBuf, LONG far *lData);
   static rrAPI(rrSTATUS) RREXP_SetFirstField(int handle, LPSTR lpszAliasBuf, LPSTR lpszFieldBuf, LPSTR lpszFieldAndCommentBuf, LONG lData, LONG lType);
   static rrAPI(rrSTATUS) RREXP_SetNextField(int handle, LPSTR lpszAliasBuf, LPSTR lpszFieldBuf, LPSTR lpszFieldAndCommentBuf, LONG lData, LONG lType);
   static rrAPI(rrSTATUS) RREXP_SetOutputFile(int handle, LPSTR lpszFileName);
   static rrAPI(rrSTATUS) RREXP_SetCommand(int handle, LPSTR lpszCommandLine, BOOL bVisible);
   static rrAPI(rrSTATUS) RREXP_SetOpaqueData(int handle, WORD wSize, char far *data);
   static rrAPI(rrSTATUS) RREXP_GetOpaqueData(int handle, WORD far *wSize, char far * far *data);
   static rrAPI(rrSTATUS) RREXP_DoExport(int handle);
   static rrAPI(rrSTATUS) RREXP_GetFieldInfo(LPSTR lpszAlias, LPSTR lpszField, LPSTR lpszFieldAndComment, LONG lData, LPSTR lpszInfoBuffer, int iInfoBufferSize);

// From mffile.h - variables:
public:
   int oldfilno;
   LPSTR UserSelect;

// From mffile.h - functions:
public:
   long getDrives(void);
#if defined RSW
   int fileinit(int leaveftb,int forTemplate, LPSTR lpSelect, int fromReadRep, LPSTR ebuf);
#else
   int fileinit(int leaveftb,int forTemplate);
#endif
   void  UpdateDictionaryFile(int fno, char *indexExp) ;
   void  UpdateDictionaryCalcField(LPMFFIELD f) ;
   bool UpdateDictionaryInit() ;
   void  UpdateDictionaryWriteLine(char *line) ;
   void  UpdateDictionaryLaunch(char *program) ;
   void  FieldViewLaunch(LPMFFIELD fld) ;
   void  JoinHelpLaunch(char* table1, char* table2) ;
   PROCESS_INFORMATION m_update;    // Update Librarian
   PROCESS_INFORMATION m_fieldview; // Field View
   PROCESS_INFORMATION m_tablelinks;   // Table Links

#if defined RSW
   int lmflink(int rfileno,int scan,int failcode,FLDID *join);
#else
   int lmflink(int mfileno,int rfileno,FLDID lnkfldno,char far *indexname,int scan,int failcode,int upper,int newone,char far *tag);
#endif

// SP 04/13/98 DATABASE OVERRIDE
BOOLEAN CheckDBOverride(char *szUpdateString);

#if defined RSW
   int lmfopen(char far *filename,int far *filenumP,int getftb,LPSTR select,
                LPSTR far *names,int fromReadRep,LPSTR ebuf,char far *alias);
#else
   int lmfopen(char far *filename,int far *filenumP,int getftb,char far *alias);
#endif
   void  linitalias(char far *file,char far *aliasbuf);
   void  mfchain(void);
#if defined RSW
   BOOL UseQeConnect;
   BOOL AlwaysRR ;
   CString qeTraceFile;
   short int qeTraceOptions;
#else
   LPMFFILE lmfnxtfil(void);  // was declared in _mf.h and _mffile.h
   BOOL BlankThruDBFieldsOnly;
#endif
   int lmfscmenu(int scnum,char far *names[],int nums[]);
   int mfaopen(char *name,char *alias);
   void  mfarray(char *cp);
   int mfckgrp(void);
   void  mfclrndx(void);
   int mfclrscope(void);
   void  mfclose(int n,int full);
   int mfclosen(int n);
   void  mfDatetimeToDate(LPMFFIELD fld);
   int mfgetftb(int o);
   int mfnf(char *s);
   LPMFFILE lmfnxtlvl(int level);
   void  mfnxtinit(void);
   void  mfondx(void);
   void  mfrlsftb(int i);
   int mfscokay(int fno);
   int lmfsetndx(char far *indexname,int newone,char far *tag);
   void  mfsrange(void);
   char *rpAlField(struct mffield far *fld,char *afbuf);
   sxgetnext(int (*postRead)(void));
   void  setmaxnum(double *dp);
   void  setminnum(double *dp);
   void  newext(char *name,char *ext); // was declared in mffile.h and _mffile.h
   int PrepareToWiz(void);
   int WizNext(void);
   int StopWizing(void);

// From mfmisc.h - variables:
public:
   MFLKBUF  *LChain;       // start of buffer chain
   char  MFAAlias[MAXALIAS];  // alias for ASCII file
   int      MFACharSet;       // 0=>OEM, 1=>ANSI
   char  *MFAName;         // attached ASCII filename ptr
   char  *MFDBFName;       // Dynamic DBF filename ptr
   char  MFDBFAlias[MAXALIAS];   // alias for DBF file
   long  MFCompRec;        // composite record number
   LPMFFIELD MFEvalOnce;      // chain for "evaluate once"
   LPMFFIELD MFFields;        // start of linked list of fields
   LPMFFILE MFFiles[MFMAXFILES+1]; // array of file pointers
   LPMFFILE MFFromOrd[MFMAXFILES+1]; // FROM clause file ptrs
   LPMFFIELD MFGrpEval[NOBRKFLDS];  // Group level reset chains
   LPFLDHDR MFHiPos;       // last field in screen order
   unsigned int MFLongCharLimit; // init dLength to this if field longer
   int      MFLongCharWrap;      // TRUE=> default wordwrap limited "long" char fields
   unsigned int MFMemoLimit;  // what to init dLength to for memo fields
   int      MFMemoWrap;       // TRUE=> default wordwrap memo fields
   LPFLDHDR MFLoPos;       // first field in screen order
   unsigned long MFNdMask;    // "current" zfNEEDED/zfLINK mask, set by mfgetbuf
   int      MFNewFinal;       // TRUE=> must evaluate finals
   int      MFNoFiles;        // current number of files open
   FLDID MFNoFlds;         // current number of fields in list
   LPMFFIELD MFPagEval;    // page break eval chain
   LPMFFIELD MFPerComp;    // chain for "per composite"
   LPMFFIELD MFQFld;       // MFQuery field
   int      MFQFldFin;        // "MFQFld is final-related" flag
   char  *MFQuery;         // address of runtime query expression
   int      MFRdErr;       // TRUE if bad read error
   char  *MFSelect;        // address of selection expression
   LPMFFIELD MFSumEval;    // Summary ("eof break") eval chain
   int      SRCtNow;       // flag for unconditional display of counts
   int      userQuit;         // halt flag if user decided to get out

// From mfmisc.h - functions:
public:
   void  cntinit(void);
   void  cntnext(void);
   int      dtokey(char *ascii,char *numkey);
   // This is a static member functions so that it can be called through a pointer.
   static   int      keepcount( void);
   char  *lmffname(char far *name,char far *nbuf);
   void  mfaddord(struct fieldhdr far *fld);
   void  mfbackord(void);
   char  *mfdecpt(char *p);
   void  mfdelord(struct fieldhdr far *fld);
   void  mfdeltmp(void);
   int      mfgetkey(char *ebuf, LPSTR ndxname, LPSTR tagname);
   void  mfgetord(int doprev);
   void  mfinit(void);
   void  mfinitcnt(void);
   void  mfpart(void);
   void  mfreset(void);
#if defined RSW
   int      mfrewind(int sqlrestart);
#else
   int      mfrewind(void);
#endif
   void  mfscopefield(FLDID fid, bool lo) ;
   int      mfscan(int n);
   char  *mfscopes(char *txt,int hi,int mtcode);
   void  sortcts(void);

// From mfmisc.h - functions:
public:
   // These three used by readRep
   int MFXFLD_ResetExport(void);
   int MFXFLD_InitExport(LPSTR lpszExpTag, LPSTR lpszDLLName); // also used by export dialog
   rrSTATUS MFXFLD_SetExportState (int handle, BOOL bActive, BOOL bSave);
   // This used only by rpwritex.c (writeRep)
   BOOL MFXFLD_ExistsExportAddon();
   // This internal version of rrexpSetOpaqueData created because prolog for rrAPI caused crash.
   int MFXFLD_SetExportOpaqueData (int handle, WORD wSize, char far *data);
   int MFXFLD_ResetAlias(PSTR oldAlias, PSTR newAlias);

   BOOL MFXFLD_WasExported (void);

   BOOL MFXFLD_GetFirstExportRecord(int far *handle, BOOL far *bActive, LPSTR far* lpszExpName, // used by writeRep
                  LPSTR far *lpszDLLName,
                  char far* far *opaqueData,
                  WORD* opaqueSize,
                  BOOL bUnfiltered); // TRUE means "give me the whole list"
                                           // FALSE means "give me only the items marked 'save'"
   BOOL MFXFLD_GetNextExportRecord(int far *handle, BOOL far *bActive, LPSTR far* lpszExpName, // used by writeRep
                  LPSTR far *lpszDLLName,
                  char far* far *opaqueData,
                  WORD* opaqueSize,
                  BOOL bUnfiltered);
   LPSTR MFXFLD_GetDLLName(int index);
   LPSTR MFXFLD_GetExpText(int index);
   int MFXFLD_findINIExportIndex(LPSTR typestring);
   LPSTR MFXFLD_findINIExportType(void);
   void  MFXFLD_SetActiveFlag(void);

// From _mf.h - variables:
public:
   char MFSQLCIPName[WINPATHLEN+1];
private:
   //  CFile MFAFile;  commented out as recommended by ADS (CAS 2/5/2013)
   //  also added the pre-compile directive to test for RSW (CAS 8/19/2014)
#if !defined(RSW) //&& defined(INTERACTIVE)
   CADSFile MFAFile;   //  and replaced by this line
#else
   CFile MFAFile;
#endif
   long MFAge;
   int MFDelCAC;
   int MFDelGFP;
   int MFDelTOT;
   int MFDoQuery;
   LPMFFIELD MFErrFld;
   int MFEvalCode;
   CFile MFGroupChan;
   long MFMastRecCnt;
   unsigned int MFMaxMatch;
   LPMFFIELD far * MFNdxTab;
   int (*MFPostRead)( void);
   char far * MFRecBuf;
   long MFRecCnt;
   CFile MFSort;
   LPSTR MFSortFile;
   int MFSortFinal;
   int MFSQLSelectOffset;
   int qeoff;
   LPSTR far * saveMFSQLNames;
   int saveMFSQLSelectOffset;
public:
   LPSTR far * MFSQLNames;

// From _mf.h - functions:
private:
   int AreWeWizing(void);
   int cktotcond(LPMFFIELD fld);
   void  countbox(void);
   void  grpclear(void);
   void  grpinit(void);
   void  grpnext(void);
   void  lmfffilss(LPMFFILE file);
#if defined(RSW)
   int mfnewfil(int fn,char *name,LPSTR select,LPSTR far *names,LPSTR alias);
#else
   int mfnewfil(int fn,char *name,char *alias);
#endif
   void  mfffldss(LPMFFIELD fld);
   int mfmemdbc(void);
   void  mfrepfld(LPMFFIELD ofld,LPMFFIELD nfld);
   int mfslist(LPMFFIELD sf[], int sa[]);
   int parseSelect(LPSTR lpSelect, LPINT offP);
   void  rcinit(void);
   void  set_current_db(LPSTR lpszTableName);

// From _mfdata.h - variables:
private:
   BOOL MFInClrBuf;           // flag that mfmove can check to tell whether there's real data to move
   LPMFFILE csf;              // current scanning-link file
   long MFGfpPos;
   long MFTotPos;
   long MFSortPos;
   long MFSaveIn;
   long MFSaveCnt;
   long MFSaveComp;
   int MFInitialSort;
   MFGROUP far *groups;
   int deepest;
   long finreccnt;
   CFile MFPtrChan;              /* pointer file channel */
   int MFQueryFinal;          /* query on finals flag */
   CFile MFCache;             /* cache file channel */
   int MFFromCache;           /* "reading from the cache" flag */
   long MFCacheCnt;           /* number of records read ahead */
   int MFNextSnap;               /* next rec in snap bufs flag */
   long MFCacheIn;               /* where we are reading from */
   long MFCacheOut;           /* and writing to */
   long MFCompCnt;               /* used by mfgetrec */
   int MFLastRet;             /* last rdnext/rec return code inside mfgetrec */
   int  MFPrevRej;               /* previous record rejected flag */
   int MFAbort;               /* signals abort thru post-read routine */
//  modification to pre-compile structure to place the definition of dbtno with CFile when
//  compiling for RSW and with CADSFile when compiling otherwise; Attempt to address issue
//  with ADS consistency and definitions by CAS 8/22/2014
#ifdef RSW
   long MFSQLRecNo;
   CFile *dbtno;                 // was static in mfgetmch.cpp
#else
   unsigned int MFMaxRec;        /* maximum length record, this composite */
   CADSFile *dbtno;                 // was static in mfgetmch.cpp
#endif
   FOUR MEMOOff;              // was static in mfgetmch.cpp
   char *buf;                 // was static in mfgetmch.cpp
   char far *dP;              // was static in mfgetmch.cpp
   int state;                 // was static in mfgetmch.cpp
   int savestate;             // was static in mfgetmch.cpp
   int bufo;                  // was static in mfgetmch.cpp
   int forcing;               // was static in mfgetmch.cpp
   int preview;               // was static in mfgetmch.cpp
   int firstbuf;              // was static in mfgetmch.cpp
   int prevdata;              // was static in mfgetmch.cpp
   int doFonts;               // was static in mfgetmch.cpp
   long fpos;                 // was static in mfgetmch.cpp
   long curfpt;               // was static in mfgetmch.cpp
   char curat;                // was static in mfgetmch.cpp
   char ma;                // was static in mfgetmch.cpp
   int mf;                    // was static in mfgetmch.cpp
   int mp;                    // was static in mfgetmch.cpp
   MF_MEMO_HDLR_PKT memo_pkt;    // was static in mfgetmch.cpp
   char the_char;             // was static in mfgetmch.cpp
   LMEMOBUFF_CHAIN_HDR memobuff_chain_hdr_ptr; // from memo.cpp, included in mfgetmch.cpp - sort of static?
   LMEMOBUFF_CHAIN_HDR memobuff_chain_tail_ptr;// from memo.cpp, included in mfgetmch.cpp - sort of static?
   CFile sffn;                // was static in mfgetrec.cpp
   int eeof;                  // was static in mfwrfin.cpp
   int MFCounted;             // was static in mfwrfin.cpp
   int fh;
   __int64 fileSize;

#if defined RSW
   char colrefbuf0[80];       // was static in mfsql.cpp
   char colrefbuf1[80];       // was static in mfsql.cpp
   char LowerOpen[100];       // was static in mfsql.cpp
   char LowerClose[50];       // was static in mfsql.cpp
#endif

// From _mfdata.h - functions:
private:
   int mfgstart(char far *sortfile, int rdo);
   int compfont(void);
   int rdmc(char *cP);
   int mfpreview(void);
   void  mfcopyfins(void);
   void  mfmove(LPMFFIELD fld);
public:
   void  CaptureAllValues( void);
private:
   void  CaptureValue( LPMFFIELD fld );
   int mfnxtgrp(long *rec, long *cnt);
   int mfrdmore(LPMFFIELD field);
   int getfinbrk(void);
   int totsort(void);
   void  freefins(void);
   int mfwrfin(int row, int col, int *dosort);
   int mfrlsmbs(LPMFFIELD fld);
   int mfgetmbs(LPMFFIELD fld);
#if defined(RSW)
   int mfread(int (*postRead)( void), int lastret, long recno);
   char far *mfselname(LPMFFILE file);
#else
   void  mfnoprev(void);
   int lbadnum(char far *s);
   void  lmfrdflds(LPMFFILE cfile);
   void  clrlkfail(void);
   int fmtkey(unsigned int len,int dec,LPMFFIELD fld,char far *buf);
   int lmfgfilss(LPMFFILE file);
   int lmflkup(LPMFFILE fileP);
   int lmfnd(LPMFFILE fileP,int checkkey);
   int lmfnxtdup(LPMFFILE fileP);
   int lmfrdata(LPMFFILE fileP,char far *buf,unsigned int len);
   int mfgetlb(LPMFFIELD fld);
   int mfgfldss(LPMFFIELD fld);
   int mfrlslb(LPMFFIELD fld);
#endif
   int lfree(char far *p);       // was static routine in mfgetbuf.cpp
   void  freebufs(int tcount);      // was static routine in mfgetbuf.cpp
   void  clrbuf(LPMFFIELD fld);     // was static routine in mfgetbuf.cpp
   char far * soften(char far *s);  // was static routine in mfgetmch.cpp
   int notinfld(void);           // was static routine in mfgetmch.cpp
   int notinfont(void);       // was static routine in mfgetmch.cpp
   int ckfont(void);          // was static routine in mfgetmch.cpp
   int ckfname(char ch);         // was static routine in mfgetmch.cpp
   char getmch(void);            // was static routine in mfgetmch.cpp
   // following routines were local to memo.cpp, included in mfgetmch.cpp, and thus sort of static
   int mf_read_memo(LMEMOBUFF_CHAIN_HDR a_chain_in,FOUR starting_pos,
               char far *buffer_ptr,int *num_bytes);
#if !defined(RSW)
   int mf_read_memhdr(long mem_hdr, long *next_mem_hdr, long *mem_size);
   int mf_forward_db4memo(LMEMOBUFF_CHAIN_HDR a_chain_in, FOUR memo_pos);
   int mf_find_db4memo(LMEMOBUFF_CHAIN_HDR a_chain_in, FOUR memo_pos);
   int mf_backup_db4memo(LMEMOBUFF_CHAIN_HDR a_chain_in,FOUR memo_pos);
#endif
   int   setup_buffer_chain (FOUR memo_pos, LMEMOBUFF_CHAIN_HDR a_chain_in,
                          LMEMO_BUFF_HDR  *current_buffer_ptr);
   int   memo_in_memory(FOUR memo_pos, LMEMOBUFF_CHAIN_HDR a_chain_in,
                    LMEMO_BUFF_HDR *a_return_buff);
   int position_memobuff (FOUR memo_pos, LMEMOBUFF_CHAIN_HDR a_chain_in,
                       LMEMO_BUFF_HDR  *current_buffer_ptr);
   int get_memo_char (FOUR memo_pos, char *char_out,
                   LMEMOBUFF_CHAIN_HDR a_chain_in);
   void  setup_memobuff_chain (MEMO_ID memo_id_in,
                           LMEMOBUFF_CHAIN_HDR *a_return_chain);
   int find_memofield (MEMO_ID memo_id_in, LMEMOBUFF_CHAIN_HDR *a_return_chain);
   int   mf_memo_hdlr (int action, MF_MEMO_HDLR_PKT *a_mf_memo_hdlr_pkt);
   // preceding routines were local to memo.cpp, included in mfgetmch.cpp, and thus sort of static
   void  doch(LPMFFIELD fld);       // was static routine in mfrdfin.cpp
   int rdtots(int lvl);          // was static routine in mfrdfin.cpp
   void  mfcpyfil(int fno);            // was static routine in mfrdflds.cpp
   void  mfcpychn(LPMFFIELD fld);      // was static routine in mfrdflds.cpp
   LPMFFILE lgetscan(LPMFFILE file);   // was static routine in mfrdflds.cpp
   int mfepage(void);               // was static routine in mfrdflds.cpp
   void  dochain(LPMFFIELD fld);    // was static in mfsrtfin.cpp
   void  fteval(void);              // was static in mfsrtfin.cpp

   // These are static member functions so that they can be called through
   //  pointers.  Note that they all take a pointer to a document, explicitly
   //  so that they can get at member variables.
   static   int      tsinit( CRrComposite* pComposite );                      // was static in mfsrtfin.cpp
   static   int      tsread( CRrComposite* pComposite );                      // was static in mfsrtfin.cpp
   static   int      tspack( CRrComposite* pComposite ,LPSTR  rec,UINT bytesLeft);  // was static in mfsrtfin.cpp
   static   int      tswrite( CRrComposite* pComposite ,CFile* outFile,LPSTR record);  // was static in mfsrtfin.cpp
   static   void  tsend( CRrComposite* pComposite );                       // was static in mfsrtfin.cpp

   void  swapbufs(int level);       // was static in mftottot.cpp
   void  clrbks(void);              // was static in mfwrfin.cpp
   int wrtots(int lvl);          // was static in mfwrfin.cpp
   int marklevel(int level);        // was static in mfwrfin.cpp
   int savenext(void);              // was static in mfwrfin.cpp
// below is duplicate:
// void  resetBrk(int brk);      // was static in mfwrfin.cpp
   int dbsz(LPMFFIELD fld);         // was static in mfwrfin.cpp
   void  rlstbufs(void);            // was static in mfwrfin.cpp
   int lfkey(LPMFFILE fileP,LPMFFIELD fld,char far *buf);   // was static in mfdbc.cpp
   void  savefld(LPMFFIELD fld);    // was static in rdahead.cpp
   void  lsavefile(LPMFFILE file);     // was static in rdahead.cpp
   void  restfld(LPMFFIELD fld);    // was static in rdahead.cpp
   void  lrestfile(LPMFFILE file);     // was static in rdahead.cpp
#if defined RSW
   int joinedTables(void);                                     // was static in mfsql.cpp
   void  remove_eols(char far * select);                          // was static in mfsql.cpp
   void  mfford(void);                                         // was static in mfsql.cpp
   char far *tname(LPMFFILE file,char far *nmbuf,BOOL bCol);            // was static in mfsql.cpp
   int badname(LPMFFILE file);                                    // was static in mfsql.cpp
   int dupfile(LPMFFILE file);                                    // was static in mfsql.cpp
   void  append_sortfields (MF_SELECT_BUILDER_PKT * select_builder_pkt);   // was static in mfsql.cpp
   void  append_needed_fields (MF_SELECT_BUILDER_PKT *select_builder_pkt); // was static in mfsql.cpp
   void  append_needed_calcs (MF_SELECT_BUILDER_PKT *select_builder_pkt);  // was static in mfsql.cpp
   void  append_join_conditions(MF_SELECT_BUILDER_PKT *select_builder_pkt);   // was static in mfsql.cpp
   void  append_from_clause (MF_SELECT_BUILDER_PKT *select_builder_pkt);   // was static in mfsql.cpp
   void  build_field_list (MF_SELECT_BUILDER_PKT *select_builder_pkt);     // was static in mfsql.cpp
   void  append_approx_join(MF_SELECT_BUILDER_PKT *select_builder_pkt);    // was static in mfsql.cpp
   void  append_exact_join(MF_SELECT_BUILDER_PKT *select_builder_pkt);     // was static in mfsql.cpp
   void  append_where_clause (MF_SELECT_BUILDER_PKT *select_builder_pkt);  // was static in mfsql.cpp
   void  append_orderby_clause (MF_SELECT_BUILDER_PKT *select_builder_pkt);   // was static in mfsql.cpp
   int init_sel_pkt(MF_SELECT_BUILDER_PKT *pkt,LPSTR sel,int *ad,       // was static in mfsql.cpp
         LPMFFIELD *sfields,int mode);
#endif
   char *dbname(LPMFFILE file,char far *nmbuf);

// From _mfedit.h - variables:
   int editmode;           // was static in editascii.cpp
   char savalias[MAXALIAS];   // was static in editascii.cpp
   char *savname;          // was static in editascii.cpp
   BOOL  bSimpleNameChange;   // was static in editascii.cpp
#if defined RSW
   LPSTR newUserSelect;    // was static in editmast.cpp
#else
   KLNTXFILE *ndxfd;    // was static in editmast.cpp
   char  *loScope;      // was static in editmast.cpp
   char  *hiScope;      // was static in editmast.cpp
   char  *newloScope;   // was static in editmast.cpp
   char  *newhiScope;   // was static in editmast.cpp
   FLDID loScopeFID ;
   FLDID hiScopeFID ;
#endif                  // was static in editmast.cpp
   LPMFFILE oldftb;     // was static in editmast.cpp
   int      mastchg;    // was static in editmast.cpp
   int      anychange;     // was static in editmast.cpp
#if defined RSW
   FLDID *linkpairs;    // was static in editrel.cpp
   void  (CRrComposite::*SaveMFFldDel)(FLDID);  /* address of routine to adjust for field deletion */
#endif
   LPMFFILE efile;         // was static in editrel.cpp
   int      efn;        // was static in editrel.cpp
   int      changing;      // was static in editrel.cpp
   OX    *list;         // was static in mfdelcon.cpp
   int      mfdccnt;    // was static in mfdelcon.cpp
   int      topent;        // was static in mfdelcon.cpp
   int      lines;         // was static in mfdelcon.cpp


// From _mfedit.h - functions:
private:
   int mfckalias(char *name);
#if defined RSW
   void  selectcleanup(void);
#endif
   LPMFFIELD match(LPMFFIELD oldf); // was static in editascii.cpp
   long lgetrecno(char far *s,int far *errp);      // was static in editmast.cpp
   double lgetdbl(char far *s,int far *ep,int hi); // was static in editmast.cpp
   void  putdate(int hi,long dint);             // was static in editmast.cpp
   void  lcopyftb(LPMFFILE o,LPMFFILE n);    // was static in editmast.cpp
   int achange(PKMAST *mastp);                  // was static in editmast.cpp
   void  selcheck(void);               // was static in editrel.cpp
   int achange(PKREL *relp,int flnum);    // was static in editrel.cpp
   void  lfixgscan(LPMFFILE file);        // was static in editrel.cpp
   void  myflddel(FLDID i);               // was static in editrel.cpp
   void  namecat(char *st,LPMFFIELD fld);       // was static in fileline.cpp
#if !defined RSW
   char far *lnxtg(LPMFFILE file,char far *nbuf);  // was static in fileline.cpp
   LPMFFILE lfl(char far *alias);               // was static in fileline.cpp
   void  lgrpline(char far *st,LPMFFILE file,int prev); // was static in filetext.cpp
#endif
   namelen(FLDID n);             // was static in mfdelcon.cpp
   typelen(FLDID n);             // was static in mfdelcon.cpp
   void  sortem();               // was static in mfdelcon.cpp
   void  linen(FLDID n,char *buf);  // was static in mfdelcon.cpp
   void  fillbox( MFFIELD* pFieldChain );    // was static in mfdelcon.cpp
   int ldelcommon(char *prompt,LPMFFIELD xcf,LPUDF xudf,int proceed); // was static in mfdelcon.cpp



// From _mferror.h - variables:
private:
   char ebuf[MAXDNAME+80];    // from mferror.cpp

// From _mferror.h - functions:
private:
   int ckfins(HWND handy,int warn,char far *expr,UTWO lgt); // from mfcheck.cpp
   int cktots(void);                               // from mfcheck.cpp
   int finals(void);                               // from mfcheck.cpp
   int badcombo(void);                                // from mfcheck.cpp
   void  clrt(void);                // from mfchgfin.cpp

// From _mffield.h - variables:
private:
   char * mflimbonm;
   LPFIELD_INFO lpFieldList;                    // was static in mfxfld.cpp
   LPFIELD_INFO lpCurrentField;                 // was static in mfxfld.cpp
   LPEXPFIELD_INFO lpExpFieldList;                 // was static in mfxfld.cpp
   LPEXPFIELD_INFO lpCurrentExpField;              // was static in mfxfld.cpp
   int iGetExportArrayIndex;                    // was static in mfxfld.cpp
   EXPORTSTUFF far* ExStuffArray[MAXEXENTRIES + 1];   // was static in mfxfld.cpp
   BOOL bWantChar;                              // was static in mfxfld.cpp
   long wFldFlags;                              // was static in mfxfld.cpp
   BOOL bWasExported;                           // was static in mfxfld.cpp

// From _mffield.h - functions:
private:
   int mfflagx(int links,int msg);        // was static in mfdelfld.cpp
   LPMFFIELD nexteval(int level,int tottot,int bklvl);   // was static in mfeord.cpp
   LPMFFIELD grpchain(int group);                  // was static in mfeord.cpp
   void  mff2prop(int f2bit);                   // local to mfeord.cpp
   rrSTATUS SetField(int handle, LPSTR AliasBuf, LPSTR FieldBuf,  LPSTR lpszFieldAndCommentBuf, LONG lData, LONG lType, BOOL bReset); // was static in mfsfld.cpp
   BOOL ExportChanged(void);           // was static in mfsfld.cpp
   BOOL GetExportRecord(int far *handle, BOOL far *bActive,LPSTR far* lpszExpName,LPSTR far* lpszDLLName,
                        char far* far *opaqueData,WORD* opaqueSize,BOOL bUnfiltered,BOOL bReset); // was static in mfsfld.cpp
   LPFIELD_INFO AddFieldEntry (LPFIELD_INFO lpFieldList); // was static in mfsfld.cpp
   BOOL FreeFieldList (void);                   // was static in mfsfld.cpp
   rrSTATUS BuildFieldList (void);           // was static in mfsfld.cpp
   LPEXPFIELD_INFO AddExpField (void);             // was static in mfsfld.cpp
   BOOL DuplicateExport (LPEXPFIELD_INFO lpComp);  // was static in mfsfld.cpp
   BOOL FreeExpFieldList (void);                // was static in mfsfld.cpp
   rrSTATUS CopyThisField (LPSTR AliasBuf, LPSTR FieldBuf, LPSTR lpszFieldAndCommentBuf, LONG far * lData); // was static in mfsfld.cpp
   BOOL BuildExpFields(int far* iGCount);          // was static in mfsfld.cpp
   void  BuildDupeFields(void);                    // was static in mfsfld.cpp
   void  DeleteTempFields(BOOL bDelGroups);        // was static in mfsfld.cpp
   LPMFFIELD NewGrpTotalField(int tottype, int grpLevel, LPMFFIELD sFld); // local to mfxfld.cpp
   LPMFFIELD GetGroupField(BOOL bReset);        // local to mfxfld.cpp

// From _mffile.h - variables:
private:
   char *oldname;       // was static in mfchgfil.cpp
   char *oldalias;         // was static in mfchgfil.cpp
   BOOL limbofull;         // was static in mfchgfil.cpp
#if defined(RSW)
   int SQLSelectOffset; // was static in mfchgfil.cpp
   LPSTR far *SQLNames; // was static in mfchgfil.cpp
#endif
   int WeAreWizing;     // was static in mfdbf.cpp
   LPMFFIELD _mf_first; // was static in mfmemfld.cpp
   LPMFFIELD mffirstfld;   // was static in mfopen.cpp
   int filno;           // was static in mfopen.cpp
   int mfent;              // was static in mfnxtfil.cpp
   LPMFFILE mff[MFMAXFILES];  // was static in mfnxtfil.cpp

// From _mffile.h - functions:
private:
   int colnames(LPSTR lpSelect, LPINT curoffP);
   void  lmfalias(char far *name);
   LPMFFIELD matchfld(LPMFFIELD fld);
   int mfainit(void);
   void  mfcfabt(void); // was declared in _mf.h and _mffile.h
   int mfcfinit(void);  // was declared in _mf.h and _mffile.h
   int mfchgfil(int doit, int *askedP);   // was declared in _mf.h and _mffile.h
   int mfmemfld(char *name,long start,long end);
   int mfsetlvl(void);  // was declared in _mf.h and _mffile.h
   void  mfunlink(int rfileno);  // was declared in _mf.h and _mffile.h
   int nextcolname(LPSTR *names, LPSTR *nextname, LPINT namelen);
   int nexttok(LPSTR lpSelect, LPINT curoffP, LPSTR token);
#if defined RSW
   char mfrdmc(int endpos);
   void  mfafldneeds(LPMFFIELD fld);
public:
   void  mfaneeds(void);
private:
#endif
#if !defined RSW
   int lmfnewrec(LPMFFILE file); // was declared in _mf.h and _mffile.h
   int lmfodbf(LPMFFILE fil); // was declared in _mf.h and _mffile.h
   int      lmfodbt(LPMFFILE fil);  // was declared in _mf.h and _mffile.h
   LPMFFILE lnextchild(LPMFFILE prevchild,LPMFFILE curparent);
   LPMFFILE lparent(LPMFFILE file);
   int      mfclose1(void);
#endif
   void  fixbufs(void);       // was static in mfchgfil.cpp
   void  mffrflds(int fn,int full); // was static in mfclose.cpp
#if !defined(RSW)
   void  lundo(LPMFFILE rfile,char far *ndxname,int lflags,int flags);  // was static in mflink.cpp
#endif
   char nextch();       // was static in mfmemfld.cpp
   void  freemems();    // was static in mfmemfld.cpp
   void  mfcleanup(int ftb);                    // was static in mfopen.cpp
   int      checkVFP3(UONE hdr);                   // was static in mfopen.cpp
   BOOL memoFileExists(LPSTR nameRoot,LPSTR extension);  // was static in mfopen.cpp
   int      mfscleanup(void);    // was static in mfsetndx.cpp

// From _mfmisc.h - variables:
private:
   long SRReadCt;
   long SRSelCt;
   long SRGrpCt;
   int      MFANamedMemos;          /* FALSE=> ascii file has no named memos; TRUE=>named memos */
   BOOL MFHiGroupAcceptAny;         /* TRUE if any recs of current hi fintot group accepted by filter */
   int      SelDel;        // was static in counts.cpp
   char ReadCt[11];  // was static in counts.cpp
   char SelCt[11];      // was static in counts.cpp
   char GrpCt[11];      // was static in counts.cpp

// From _mfmisc.h - functions:
private:
   void  mffixord(LPFLDHDR fld);
#if !defined RSW
   void  getdate(int hi,char *buf);
public:     // for runtime DLL
   int      keytod(char *key,char *ascii);
private:
#endif
   void  dtimetokey(ZDATETIME *,char *);
   void  keytodtime(char *,ZDATETIME *);
   int      MFXFLD_GetFirstField(LPSTR AliasBuf, LPSTR FieldBuf,LPSTR lpszFieldAndCommentBuf, LONG far * lData);
   int      MFXFLD_GetNextField(LPSTR AliasBuf, LPSTR FieldBuf, LPSTR lpszFieldAndCommentBuf, LONG far * lData);
   int      MFXFLD_SetFieldOptions (int handle, LONG fieldOptions);
   int      MFXFLD_GetFieldInfo (LPSTR lpszAlias, LPSTR lpszField, LPSTR lpszFieldAndCommentBuf, LONG lData, LPSTR lpszInfoBuffer, int iInfoBufferSize);
   int      MFXFLD_SetExportOptions (int handle, LONG lExportOptions);
   int      MFXFLD_SetFirstField(int handle, LPSTR lpszAliasBuf, LPSTR lpszFieldBuf, LPSTR lpszFieldAndCommentBuf, LONG lData, LONG lType);
   int      MFXFLD_SetNextField(int handle, LPSTR lpszAliasBuf, LPSTR lpszFieldBuf, LPSTR lpszFieldAndCommentBuf,LONG lData, LONG lType);
   int      MFXFLD_SetOutputFile(int handle, LPSTR lpszFile); // mandatory
   int      MFXFLD_SetCommand (int handle, LPSTR lpszCommandLine, BOOL bVisible);
   int      MFXFLD_DoExport (int handle);
   int      MFXFLD_SetData (int handle, WORD wSize, char far *data);
   int      MFXFLD_GetData (int handle, WORD far *wSize, char far* far*data);
   int      MFXFLD_SetState (int handle, BOOL bSave, BOOL bActive);
   int      lapart(LPMFFILE file,int fno);   // was static in mfpart.cpp
   int      ckmaxnum(double d);              // was static in mfscopes.cpp
   int      ckminnum(double d);              // was static in mfscopes.cpp
public:     // for RUNDLL, sorry
   void  roundDBITimeToSecs(DBITIME *t);  // was static in mfscopes.cpp
private:
   void  getdatetime(int hi,char *buf);      // was local to mfscopes.cpp
// END block from the various mf* and _mf* headers:

// BEGIN block from ENG modules
#if defined RSW
// from eng.h - variables:
public:
   BOOL AlwaysSelect;
   BOOL AlwaysLocalLog;
   BOOL TestJoin;
   BOOL UseDefaultDB;
   int      AsciiEditor;
   int      CharRaw;
   char Sql_Blank;
   long QueryTimeout;
   int      ModifySelect;

// from eng.h - functions:
public:
   unsigned long sql_used_drives(void);
   int      sql_check(char FAR *select,char FAR *msg);
   void  sql_date_str(long date,char FAR *s);
   void  sql_datetime_str(long date, double time, char FAR *s);
   void  sql_time_str(double time,char FAR *s);
   LPSTR sql_dbtypename(LPMFFIELD fld);
   int      sql_exec(char FAR *query,char FAR *outmsgbuf,int iIgnoreFlds,int iRandom);
   void  sql_exit(void);
   int      sql_expinfo(LPSTR exp,LPMFFIELD fld,int action,int disperr);
   void  sql_finish(LPMFFIELD f);
   BOOL  sql_fld_data(void);
   void  sql_fld_header(struct mffield FAR *f,char FAR *s);
   char  *sql_get_DLL_version(void);
   int      sql_random_rec(long recno);
   char  *sql_get_schema(void);
   int      sql_tables (HWND hParent, LPSTR lpszTable, int whereFrom, LPSTR lpszDS,int *DSIndex,int bCustomDlg);
   int      sql_no_tables(HWND hDlg);
   BOOL  sql_set_current_schema(LPSTR lpszSchema);
   int      sql_next_rec(void);
   LPSTR sql_prep_tablename_for_dict (LPSTR lpszNameIn, LPSTR lpszNameOut);
   LPSTR sql_replace_params (LPSTR lpszSelect,LPSTR lpszParamList);
   int      sql_start(char fileno,LPSTR lpszSelect,LPSTR lpszParamString,LPSTR *names,BOOL bFromReadrep,LPSTR lpszEBuf);
   void  sql_reset(void);
   void  sql_restart(void);
   void  sql_set_max_rows(unsigned long rc);
   unsigned long sql_get_max_rows(void);
   BOOL  sql_data_source_dialog(BOOL bSelect, int FAR *iDataSources);
   BOOL sql_current_connection_dialog(BOOL bSelect);
   char *DBIgetDatabase(void);
   char *DBIgetPassword(void);
   char *DBIgetUserID(void);
   char *DBIgetDataDir(void);
   BOOL DBIdataSourcePreFetch(void);

// from _eng.h - variables:
public:
   GLOBALHANDLE ghndSavedTableList;
   GLOBALHANDLE ghndSavedOwnerList;
   GLOBALHANDLE ghndSavedDatabaseList;
public:
   DATASOURCE * ActiveDS;              // was static in dbi.cpp
   char  szSourceName[SQL_MAX_DSN_LENGTH+1]; // was static in ienglog.cpp
   bool  DirectToODBC ;
private:
   BOOL  bShowOwner;
   char  szSaveOwner[128];
   qeHANDLE qeAuxHstmt;             // was static in dbi.cpp
   BOOL  bDBIconvertSelect;            // was static in dbi.cpp
   BOOL  bDBIcharsetIsAnsi;            // was static in dbi.cpp
   DATASOURCE * DSarray[DSARRAYSIZE];     // was static in dbi.cpp
   NADATASOURCE * NADSarray[DSARRAYSIZE]; // was static in dbi.cpp
   int      iDScount;                  // was static in dbi.cpp
   int      iDSmarker;                 // was static in dbi.cpp
   char  *pszConnectExtra;          // was static in dbi.cpp
   char *pszPassword;                     // was static in dbi.cpp
   char *pszUsername;                     // was static in dbi.cpp
   char *pszDataSource;
   char *pszDatabase;                     // was static in dbi.cpp
   LPSTR sessionidstr;                    // was static in dbi.cpp
   char unkown[50];           // was static in iengflds.cpp
   int iIgnoreFldsGlobal;     // was static in iengine.cpp
   unsigned long lSqlMaxRows; // was static in iengine.cpp
   int englog_iDScount;                // was static in ienglog.cpp
   int DSFilter;                       // was static in ienglog.cpp
   LPSTR lpszTableName; // was static in iengmenu.cpp
   int noMasterBox;     // was static in iengmenu.cpp
   int callingFrom; // 1 = master, 2 = edit master, 3 = related, 4 = edit related
   char *szDatabase;    // was static in iengmenu.cpp
   char *szTable;       // was static in iengmenu.cpp
   char *szFilePath;    // was static in iengmenu.cpp
   LPSTR lpszOwnerDotTable;// was static in iengmenu.cpp
   BOOL bSysTables;     // was static in iengmenu.cpp
   BOOL bHaveSysTables; // was static in iengmenu.cpp
   char saveDB[SERVERNAMELEN];   // was static in iengmenu.cpp
   int iengmenu_width;        // was static in iengmenu.cpp
   int iengmenu_height;       // was static in iengmenu.cpp
   POINT newComboPoint; // was static in iengmenu.cpp
   POINT newTextPoint;     // was static in iengmenu.cpp
   RECT fullDialogRect; // was static in iengmenu.cpp
   RECT textBoxRect;    // was static in iengmenu.cpp
   RECT ownerComboRect; // was static in iengmenu.cpp
   RECT cancelButtonRect;// was static in iengmenu.cpp
   RECT pasteRect;            // was static in iengmenu.cpp
   RECT helpRect;          // was static in iengmenu.cpp
   char far *lpszAdsName;     // was static in iengmenu.cpp
   char far *lpszNODS;        // was static in iengmenu.cpp
   char far *lpszDataSource;  // was static in iengmenu.cpp
   int *aDSIndex;          // was static in iengmenu.cpp
 #if defined(RUNDLL)
public:
   char NewDSName[SQL_MAX_DSN_LENGTH+1];
   char NewDBName[SERVERNAMELEN];
   int DbaseExclude;       // used by RRDICT-related code to exclude Dbase sources
private:
 #endif  // RUNDLL

// from _eng.h - functions:
private:
   int sql_fld_bufB(BOOL bAlloc,int iIgnoreFlds);
   void  sql_addwhere(LPSTR destP, LPSTR sourceP);
   void  handleODBCerr(LPSTR lpszErrOut, UCHAR errType);    // was static in dbi.cpp
   void  handleQeErr(LPSTR lpszErrOut, LPSTR lpszDSname);      // was static in dbi.cpp
   void  handleODBCConnectErr(LPSTR lpszErrOut, HDBC Handle);  // was static in dbi.cpp
   void  AddDataSource (DATASOURCE far* lpDS);              // was static in dbi.cpp
   void  AddNADataSource (NADATASOURCE far *newSource);        // was static in dbi.cpp
   void  ConnectedDataSources();                      // was static in dbi.cpp
   BOOL GetDBMSInfo (DATASOURCE far* newSource);            // was static in dbi.cpp
   void  DeleteDataSource (DATASOURCE far *lpDS);           // was static in dbi.cpp
   DATASOURCE far *GetDataSource (LPSTR lpszDS);            // was static in dbi.cpp
   NADATASOURCE far *getNADataSource(LPSTR lpszDS);         // was static in dbi.cpp
   void  fld_data_body(LPMFFIELD fld);          // was static in iengflds.cpp
   int eiquit(void);                      // was static in iengflds.cpp
   int dbTypeString(TYPESTRING *tbl,int type);     // was static in iengflds.cpp
   void  platchange_followup();        // was static in ienglog.cpp
#if defined(RUNDLL)
public:
#endif
static BOOL CALLBACK EXPORT dataSourceDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
private:
static BOOL CALLBACK EXPORT currentConnectionDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
   void  SetSelToActive (HWND hDlg);   // was local to ienglog.cpp
   BOOL odbcInstaller(BOOL bRun, HWND hDlg);       // was local to ienglog.cpp
   BOOL resizeDialog (HWND hDlg, BOOL bUserSQL, BOOL bOwnerCombo);      // was static in iengmenu.cpp
   void  endDialog(HWND hDlg, BOOL how);                       // was static in iengmenu.cpp
   void  HideCopyPaste (HWND hDlg);                            // was static in iengmenu.cpp
   void  parseTableName (LPCSTR lpszName);                        // was static in iengmenu.cpp
   void  setCaption(HWND hDlg, int action, LPSTR addText);           // was static in iengmenu.cpp
   BOOL changeDatabase(HWND hDlg, LPSTR lpszNewDatabase);            // was static in iengmenu.cpp
   BOOL  initSQLServerDatabaseList(HWND hDlg);                 // was static in iengmenu.cpp
   BOOL databaseList (HWND hItem);                             // was static in iengmenu.cpp
   BOOL ownerList (HWND hItem, HWND hListBox);                    // was static in iengmenu.cpp
   BOOL databaseTableList (HWND hDlg, HWND hItem, BOOL bWithOwners); // was static in iengmenu.cpp
static BOOL CALLBACK listDSTablesDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
static BOOL CALLBACK listTablesDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
static BOOL CALLBACK EXPORT noTablesDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
static BOOL CALLBACK noDSTablesDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
   int sqlnoDStables(HWND hDlg,LPSTR pDataSource);          // was local to iengmenu.cpp
   BOOL getToken (char cLeftDelim, char cRightDelim, int nNumRepeat, LPSTR lpszString, tokenStruct *retToken); // was static in iengparm.cpp
   int countTokens (char cLeftDelim, char cRightDelim, int nNumRepeat, LPSTR lpszString); // was static in iengparm.cpp
   LPSTR tokenReplace (char cLeftDelim, char cRightDelim, int nNumRepeat,
              LPSTR lpszString, tokenStruct *params, int nNumParams,
              BOOL bReplace); // was static in iengparm.cpp
   LPSTR findWord(LPSTR lpszInput, LPSTR lpszWord);                  // was static in iengwher.cpp
   LPSTR findTwoWords(LPSTR lpszInput, LPSTR lpszWord1, LPSTR lpszWord2);  // was static in iengwher.cpp
   void  doSelect(LPSTR destBuf, LPSTR lpszStmt, LPSTR *nextpartP);        // was static in iengwher.cpp

// from dbi.h
public:
   int DBIconnected();
   int DBIsqlPlatNeedsEngine(int sqlPlatID);
   void  DBIsetPlatform(int iPlatID);
   long DBIgetInfoLong(int option);
   BOOL DBIgetDataSourceDatabase(LPSTR lpszDatabase, int len);
   BOOL DBIgetDataSourceDriver(LPSTR lpszDriver, int len);
   LONG DBIgetDataSourceMaxCharLiteralLen(void);
   char *DBIgetDLLversion(void);
   LPSTR DBIgetUsername(void);
   LPSTR DBIgetDataSource(void);
   LPSTR DBIgetConnectString(void);
   CString DBInextAttrib ( CString & sInput );
   int DBIgetConnectStringWithoutUidPwd(LPSTR lpszStringBuf);
   int DBIinitDB(LPSTR bErrMsgBuf,BOOL bDBAnsi);
   void  DBIquitDB(void);
   void  DBIfatalErr(int errnum);
   void  DBIendSQL(void);
   int DBIexecSQL(LPCSTR lpszSQL,LPSTR lpszErrOut);
   void  DBIrestart(void);
   int DBIfetchNextRecord(void);
   char FAR *DBIgetRecordText(int firstCol, int lastCol, char separator);
   int DBInumCols(void);
   int DBIcolType(int iColNum);
   int DBIcolNameBuf(char *szColName,int iColNum);
   long DBIcolWidth(int iColNum);
   int DBIcolPrecision(int iColNum);
   int DBIcolScale(int iColNum);
   int DBIbindCol(int iColNum,char FAR *lpszBuffer,long iLen,long FAR *piReturnLen);
   int DBIcolIsDate(int iColNum);
   int DBIcolIsTime(int iColNum);
   void  DBIgetDate(char FAR *lpszDate,struct ZDate *zdate);
   void  DBIgetTime(char far *lpszTime,struct DBITime *dbiTime);
   void  DBIgetDateTime (char far *lpszTime,struct DBIDateTime *dbidatetime);
   BOOL DBItables(LPCSTR szOwner);
   LPSTR DBIownerSelect(BOOL bSysTables);
   LPSTR DBIownerAltSelect(BOOL bSysTables);
   LPSTR DBIdatabaseSelect();
   BOOL DBIcurrentDatabase(LPSTR dbname);
   BOOL DBIuseSetDB(void);
   BOOL DBIuseDatabase(LPSTR dbname);
   BOOL DBIverifyDataSource(LPSTR szDataSourceName, LPSTR szConnectString, LPSTR szDriverDescription ) ;
   int DBImemoType(int iColNum);
   void  DBIsetConvertSelect(BOOL bConvertSelect);
   int DBIfetchRandom(long recno);
   int DBIsetRandom(void);
   int DBIcolDBType(int iColNum);
   int DBIsetMaxRows(unsigned long rc);
   void  DBIsetQueryTimeout(long secs);
   int DBIcountDS(void);
   BOOL DBIdataSources(void);
   LPCSTR DBInextDataSource(void);
   BOOL DBIconnectedDataSources(void);
   LPCSTR DBInextConnectedDataSource(void);
   BOOL DBIdataSourceConnected(LPSTR lpszDS); // answers: is this source connected?
   BOOL DBIdataSourceConnectedWithExtra(LPSTR lpszDS,LPSTR lpszExtra);
   void  DBIfreeConnectStrings(void);
   void  DBIsetDatabase(LPSTR lpszDatabase);
   BOOL DBIgetNADataSourceDatabase(LPSTR lpszDS, LPSTR lpszDatabase, int len, BOOL leavecon);
   BOOL filterDSdialog(HWND hdlg, BOOL bSelect, LPSTR lpszDataSource, LPSTR returndir, int len);
   int DBIconnectToNewDir (LPSTR lpszDatabase, LPSTR DSName, LPSTR *newSource);
   void  DBIchangeDatabaseNameNow(LPSTR lpszDatabase);
   int DBIjoinAcrossDir(void);
   LPSTR DBIgetConnectExtra(void);
   void  getNADSIndex(LPSTR new_dsname, int *aDSIndex);
   LPSTR DBIgetNADataSource(int NADSIndex);
   void  DBIgetNADSInfo (int DSIndex, LPSTR lpszDS, int dslen, LPSTR lpszDir, int dirlen);
   void  DBIfreeAllNADS(void);
   void  DBIfreeNADS(LPSTR lpszDS);
   BOOL DBIusesSameDLL(LPSTR lpszDS);
   void  DBIclearDataSourceInUse(void);
   void  DBIsetDataSourceInUse(LPSTR lpszDS);
   BOOL DBIisDataSourceInUse(LPSTR lpszDS);
   void  DBIsetConnectExtra(LPSTR lpszConnectBook);
   void  DBIsetDataSource(LPSTR lpszDataSource);
   void  DBIsetPassword(LPSTR lpszPassword);
   void  DBIsetUsername(LPSTR lpszUsername);
   void  DBIsetSessionID(LPSTR lpszSessionID);
   int DBIconnectDataSource(LPSTR lpszDS,BOOL bShowDialog, BOOL bErrMsg, LPSTR lpszCS);
   BOOL DBIdisconnectDataSource(LPSTR lpszDS);
   void  DBIsetActiveDataSource(LPSTR lpszDS);
   LPSTR DBIgetActiveDataSource(void);
   LPSTR DBIgetActiveDSDriverInfo(int idx);
   BOOL DBIconfigureDataSource(LPSTR lpszDS);
   BOOL DBIdataSourceIsDbase(void);
   BOOL DBIdataSourceIsFileBased(void);
   BOOL DBIdataSourceIsSQLServer(void);
   BOOL DBIdataSourceIsNetWareSql(void);
   BOOL DBIdataSourceIsBtrieve(void);
   BOOL DBIdataSourceIsOracle(void);
   BOOL DBIdataSourceIsParadox(void);
   BOOL DBIdataSourceIsProgress(void);
   BOOL DBIdataSourceIsFlatFile(void);
   BOOL DBIdataSourceMaxRows(void);
   BOOL DBIdataSourceApprox(void);
   BOOL DBIdataSourceLikeWithExpression(void);
   BOOL DBIdataSourceModifySelect(void);
   BOOL DBIdataSourcePassExec(void);
   BOOL DBIdataSourceDirectoryPrefix(void);
   BOOL DBIdataSourceDOSFile(void);
   char *DBIdataSourceDefExt(void);
   int DBIdataSourceExtID();
   char *DBIdataSourceIniKey();
   int DBIgetNumConnections(void);
   void  DBIdisconnectAll();
   LPSTR DBIgetIniSectionName();
   void  DBIgetDBTerm(LPSTR s,int bsize);
   LPSTR DBIgetDriverDBMSName();
   unsigned long DBIdataSourceDrive(void);
   int DBIdataSourceExpressionsInOrderBy(void);
   int DBIdataSourceUsesDatabases(void);
   int DBIdataSourceUsesOwners(void);
   int DBIdataSourceOuterJoinStyle(void);
   void  DBIdataSourceIdentifierQuoteChar(LPSTR quote);
   void  DBIunquote(char *newfile, char *oldfile) ;
   int DBIdataSourceIdentifierCase(void);
   int DBIdataSourceQualCols(void);
   int DBIdataSourceUseAlias(void);
   int DBIdataSourceQualSorts(void);
   int DBIdataSourceAddFalse(void);
   int DBIdataSourceFileExt(void);
   int DBIdataSourceEngEval(void);
   int DBIdataSourceQSwitch(void);
   int DBIdataSourceSelSort(void);
   BOOL DBIisSystemTable (char* szPtr);
   LPSTR DBIdataSourceProcVerb(void);
   BOOL FindInSeparatedString (LPSTR lpszToken, LPSTR lpszSearched);
   LPCSTR NextDataSource(void);
   void  MakeTempActiveDataSource (LPSTR lpszDS);
   void  DBIinitSessionID(void);
   BOOL DBIdataSourceIsExcel(void);
   BOOL DBIdataSourceIsText(void);
   BOOL DBIdataSourceIsAccess(void);
   LPSTR DBIgetActiveDSDriver(void);
   LPSTR DBIgetActiveDSDriverDescription(void);
   void  DBIfixTableName(LPSTR lpszName);
   LPSTR DBIgetDefaultDatabase(void);
 #if defined(RUNDLL)
   BOOL DBIreplaceConnectedDataSource (LPSTR lpszDS);
   BOOL DBIrememberDataSource (LPSTR lpszDS);
   BOOL DBIgetRememberedDataSource (LPSTR lpszDS, int size);
   BOOL DBIuseRememberedDataSource (void);
   BOOL DBIrememberDatabase (LPSTR lpszDB);
   BOOL DBIuseRememberedDataBase (void);
 #endif
#endif
// END block from ENG modules

  // =================== BEGIN CFEVAL directory ======================
   // =================== CFEVAL.H ===================================
public:
   // global data
   LPSTR CfEvalStack;   // eval stack
   LPSTR CfEvalStackEnd;// end of eval stack
   // global functions
   int eval(LPSTR in,LPSTR valP,int csize,int *errP,int *prevmemP);
   int fldtrue(LPMFFIELD fld,LPSTR buf);
   // =================== end CFEVAL.H ===============================

   // =================== _CFEVAL.H ==================================
public:
   // was defined in eval.c
   int args;
   int Boolean;
   int NextBoole;
   LPSTR xcp;  /* compile buffer pointer */
   LPSTR xs;   /* evaluate stack pointer */
   int StkOflo;

   // global functions from _cfeval.h
   // eval.c
   char erf(LPMFFIELD fld, int cur);
   int cknoarg();
   int cknum();
   int ckdate();
   int ckstr();
   int ckdatetime();
   int lstelen(LPSTR stp);
   void  stshuffle(int n);
   void  pushd(long d);
   void  pushdt(ZDATETIME dt);
   void  pusht(double ztime);
   void  pushm(LPMFFIELD f);
   void  lpushs(LPSTR s, int l);
   void  pushq(void);
   void  pushn(double val);
   double poprawn(void);
   double popn(void);
   int popi(void);
   long popd(void);
   long popda(void);
   ZDATETIME far *popdt(ZDATETIME far *val);
   double popt();
   char popkey(LPSTR returnType);
   LPSTR lpops(LPSTR s);
   struct mffile far *lpopf(void);
   struct mffield far *popfld(void);
   int compeq(void);
   int topfalse(void);
   // fdate.c
   static int fdate(void);
   static int fcdow(void);
   static int fcmon(void);
   static int fctod(void);
   static int fday(void);
   static int fdow(void);
   static int fdtoc(void);
   static int fmonth(void);
   static int fyear(void);
   static int ftime(void);
   static int faday(void);
   static int faweek(void);
   static int famon(void);
   static int fayear(void);
   static int fsday(void);
   static int fsweek(void);
   static int fsmon(void);
   static int fsyear(void);
   static int fdaybt(void);
   static int fwksbt(void);
   static int fmonbt(void);
   static int fyrsbt(void);
   static int fweek(void);
   static int fdqtr(void);
   static int fqtr(void);
   static int fhalf(void);
   static int fmonl(void);
   static int faged(void);
   static int fpast(void);
   static int ffutu(void);
   static int fover(void);
   static int fndow(void);
   static int fpdow(void);
   static int fdateadd(void);
   static int fdatediff(void);
   static int fdatename(void);
   static int fdatepart(void);
   static int ftodate(void);
   static int ftotime(void);
   static int fdttoc(void);
   static int fttoc(void);
   static int fttos(void);
   static int fctdt(void);
   static int fctos(void);
   static int fctot(void);
   static int fstoc(void);
   static int fnow(void);

   // soundex.c
   void  lsoundex(LPSTR in, LPSTR out, LPSTR breaks);
   // ftrans.c
   static int fflip(void);
   static int ftransform(void);
   // fnum.c
   static int fmin(void);
   static int fmax(void);
   static int fexp(void);
   static int fint(void);
   static int flog(void);
   static int frnd(void);
   static int fsqrt(void);
   static int fval(void);
   static int fpage(void);
   static int flastpage(void);
   static int freportpage(void);
   static int fcopy(void);
   static int frecn(void);
   static int fxabs(void);
   static int fxmod(void);
   static int fiif(void);
   static int finrng(void);
   static int finlst(void);
   static int ferrval(void);
   static int fcase(void);
   static int frrunin(void);
   static int fspelln(void);
   static int fprev(void);
   static int fblnknum(void);
   static int fisblank(void);
   // fstr.c
   static int fat(void);
   static int flen(void);
   static int flowc(void);
   static int fupc(void);
   static int fspc(void);
   static int fsubst(void);
   static int ftrim(void);
   static int fasc(void);
   static int fchr(void);
   static int fstr(void);
   static int fisa(void);
   static int fisl(void);
   static int fisu(void);
   static int fltrim(void);
   static int frtrim(void);
   static int fleft(void);
   static int fright(void);
   static int frepl(void);
   static int fstuff(void);
   static int fstrsearch(void);
   static int fstrcount(void);
   static int fstrrep(void);
   static int fcaps(void);
   static int fsndx(void);
   static int fwdcnt(void);
   static int fword(void);
   static int friparam(void);
   static int flibn(void);
   static int frepn(void);
   static int fudfn(void);
#ifdef RSW
   static int flike(void);
   static int frr(void);
   static int fisnull(void);
#else
   static int fclookup(void);
   static int fllookup(void);
   static int fdlookup(void);
   static int fdtlookup(void);
   static int fnlookup(void);
   static int flupdate(void);
   static int fdbf(void);
   static int fdel(void);
   static int freccnt(void);
   static int fscan(void);
#endif
   // fsystem.c
   static int fquery(void);
   static int floscope(void);
   static int fhiscope(void);
   static int fcdll(void);
   static int fixsql(void);

   // from lookup.c
#if !defined (RSW)
   void  fixlunames(struct mffile far *file);
   int lookup(struct mffile *rfile,char *tfld,int ixtype,LPSTR value,LPSTR res);
#endif
   // ================== end _CFEVAL.H ===============================
   // ================== EVAL.C ======================================
private:
   MFFIELD cf_MTMemFld;
   int compne();
   int cktime();
   void  pushkey(LPSTR cStack);
   // ================== end EVAL.CPP =================================

   // ================== FDATE.CPP ====================================
private:
   int dm(int mo, int yr);
   // ================== end FDATE.CPP ================================

   // ================== FNUM.CPP =====================================
private:
   int ltriplet(LPSTR in, LPSTR out);
   // ================== end FNUM.CPP =================================

   // ================== FSTR.CPP =====================================
private:
   int lwordcnt (LPSTR s, LPSTR b);
   // ================== end FSTR.CPP =================================

   // ================== FTRANS.CPP ===================================
private:
   char  cf_Fill;
   int   cf_Credit, cf_Debit, cf_Parens;
   LPSTR cf_Negative;
   int   cf_DidTrailers;
   // static Functions
   void  trailers(LPSTR p);
   int isdig(char ch,int *count);
   // ================== end FSTR.CPP =================================

   // ================== SOUNDEX.CPP ==================================
private:
   // static functions
   char sound(char ich);
   // ================== end SOUNDEX.CPP ==============================
  // =================== END CFEVAL directory =========================

  // =================== BEGIN CFMISC directory =======================
   // ================== CFMISC.H =====================================
public:
   int CFErrVal;        // signal to return error value
#if !defined(INTERACTIVE)
   NV far *cfnv;              // for riparam()
#endif
   LPSTR  cfrpn;     // output of compile
   LPSTR  cfrpnend;  // end of rpn buffer
#ifdef RSW
   int cfmaxstrlen;
#endif
   LPSTR  cfstr1; // used by eval
   LPSTR  cfstr2; // used by eval
   LPSTR  cfstr3; // used by eval and by CDLL
#ifdef RSW
   LPSTR  cfstr4; // used by eval
#endif
   LPSTR  cfsyn;     // syntax stack (used by compile)
   LPSTR  cfsynend;  // end of syntax stack
   LPSTR  cfueb;     // user expression buffer
   int cfuesz;          // size of cfueb, cflex buffers
   char LAND;
   char LFALSE;
   char LNOT;
   char LOR;
   char LTRUE;
   LPSTR lpszTAND;
   LPSTR lpszTOR;
   LPSTR lpszTNOT;
   LPSTR lpszTTRUE;
   LPSTR lpszTFALSE;
   LPSTR lpszTVTRUE;
   LPSTR lpszTVFALSE;

   int InCompare;
   int FPError;
   int maxfunc;
   int prevmem;

// Leave this baby in source module (FUNCTAB.CPP)
// FUNCTB functab[MAX_FUNC];
   LPSTR cflex;      /* converted user expression (used by lex) */
   LPUDF UDFS;

   int copyused(void);
   void  winDateOrder(char *date);
#ifdef RSW
   int compdata(unsigned int evalbufsize,unsigned int maxstrlen);
#else
   int compdata(void);
#endif
   void  compbuf(LPSTR *, int *);
   void  expupd(FLDID ndx);
   void  expupdScan(int type, LPMFFIELD fld, FLDID index, FLDID ndx) ;

   struct mffield far *fileused(int fn);
#ifdef RSW
   void  cfrepfld(FLDID old,FLDID new_int);
#endif
#if defined RSW
   void  cfneeded(int *chgP,int fullProp);
#else
   void  cfneeded(int *chgP);
#endif
   char *uferror(int ecode);
   int compable(struct mffield far *fld);
   void  qualify(int filno);
   int ltrimlen(char far *s);
   void  freecompdata(void);
   void  cfsource(void);
   char far *lsoft(char far *s);
   void  cfpmemo(void);
   int urdall(void);
   int lcftrim(char far *s);
   void  rlsstack(void);
   int getstack(void);
#ifdef RSW
   int freqdef(FLDID sindex);
#else
   int freqdef(FLDID sindex,int count);
#endif
   void  lcfrepnm(int field,FLDID FieldIndex,int FileIndex, char far *oldname,char far *newname);
   struct mffield far *fldused(FLDID fn);
   // strtod.c
   long lcfstrtod(char far *str);
   double lcfstrtot(char far *str,int TimeInterval);
   int parseDateTime(LPSTR lpszDTString, double *time, long *date);
   // check2DY.cpp   for year-2000 fixes. 2/28/1997 HXC
   BOOL check2DYDate(LPSTR str, BOOL bEditFlag);
   BOOL date2Yto4Y(LPSTR str, BOOL bEditF);

   // ========================= end CFMISC.H =========================

   // ========================= _CFMISC.H ============================
public:
   int InEval;
   // was from cfustack.c
   char far * far *UStack;

   char far * far *UArgs;
   char far *UCnts;
   int UFrame;             /* entry number of next UArgs frame */
   // was from cfustack.c
   char far * far *UFirstArg;       /* pointer to first arg ptr, current call */

   // from strtod.c
   char ShortDateSep;
   LPUDF ErrorUDF;

   YYFILETAB * udftb;

#ifdef WIN32
   DWORD utime;
#else
   time_t utime;
#endif
   // from compdata.c

   // global functions
   // funcused.c
   int funcused(int fn);
   int flgfuncs(int fn);
   // ulibr.c
   int uopen(int forWrite);
   int usysopen(void) ;
   void  uclose(void);
   // ulibw.c
   int luwrdef(struct udf far *u,char far *oldname);
   int ludeldef(struct udf far *u);
   // cfustack.c
   int setargs(int acnt);
   void  pusharg(int n);
   void  pushprevarg(int n);
   void  popargs(void);
   // ufneeded.c
   void  ufneeded(void);
   // trim.c
   char far *ltrimleft(char far *s);
   // ========================= end _CFMISC.H ========================

   // ========================= CFNEEDED.CPP ===========================
private:
   // static functions
#if defined RSW
   void  xcfsource(int fullProp);
#else
   void  cfmcfsource();
#endif
   void  cfmdochain(LPMFFIELD fld);
   // ========================= end CFNEEDED.CPP =======================

   // ========================= CFREPNM.CPP ============================
private:
   int cf_file_index;
#if defined (RSW)
   void  fixname(LPSTR in, LPSTR out);
#endif
   // ========================= end CFREPNM.CPP =======================

   // ========================= COMPDATA.CPP ==========================
   /* NOTE: after eval stack are two string buffers, each big enough for
       the maximum length string.  This allows testing for stack overflow
       after values are pushed onto stack, as long as the string buffer
       contents are not relied upon after overflow.
   */
private:
   LPSTR evalx1;     // static for later free
   LPSTR evalx2;     // static for later free
   int cfsize ;         // size of eval buffer
   // static functions
   int initlogstrs(void);
   int getcontrol(void);
   void  rlscontrol(void);
   // ========================= end COMPDATA.CPP ======================

   // ========================= FPERROR.CPP ===========================
private:
   static void fperr(int sig);
   int fperrinit();
   // ========================= end FPERROR.CPP =======================

   // ========================= FUNCUSED.CPP ==========================
private:
   int ckfunc(char far *x,int fn,int internal);
   // ========================= end FUNCUSED.CPP =======================

   // ========================= STRTOD.CPP ============================
private:
   // static data
public:
   char cf_mfirst, cf_msecond, cf_mthird;
private:
   // static functions
   int dcheck(char   *in, ZDATE  *dt);
   FOUR dconstant(ZDATE *dt);
   BOOL bTimeish(LPSTR lpszString);
   BOOL checkTimeSuffix(LPSTR p,BOOL *pm);
   BOOL badval(LPSTR p);
   void  dateme (char   *in, char   *out);
// below is defined elsewhere in here
// char * testwdate(char   *input);
   // ========================= end STRTOD.CPP ========================

   // ========================= UFERROR.CPP ===========================
private:
   // static data
   char cf_ebuf[80];
   // ========================= end UFERROR.CPP =======================

   // ========================= UFERROR.CPP ===========================
private:
   LPUDF lgetu(int n);
   int   ldoform(char far *p);
   // ========================= end UFERROR.CPP =======================

   // ========================= ULIBR.CPP ===========================
private:
#ifdef WIN32
   DWORD fltime(HANDLE handle);
#else
   time_t fltime(int handle);
#endif
   int    urddef(LPYZNAME yzn, bool system, int final);
   // ========================= end ULIBR.CPP =======================

   // ========================= ULIBW.CPP ===========================
private:
   char cf_uver;

   int luwrec(char type,unsigned short len,char far *ptr);
   // ========================= end ULIBW.CPP =======================


  // =================== BEGIN CFEDIT directory ======================
   // ================== CFEDIT.H ====================================
public:
   LPMFFIELD savchain;

//#if defined INTERACTIVE
   int edcalcprep(PKCALC *calcp,int *cntp);
   void  edcalcquit(PKCALC *calcp);
   void  edcalcgo(HWND handy,PKCALC *calcp);
   int purgeable(void);
   void  purgeprep(int which);
   void  purgequit(void);
   void  purgego(void);
   int verifycalc(PKCALC *calcp);
   int lockudfs(void);
   void  unlockudfs(void);
//#endif
   int ckcalcname(LPSTR name,LPMFFIELD okayfld);
   LPSTR lcallform(LPSTR name,LPSTR buf);
   int crecomp(LPMFFIELD cf,int doIt);
   // ================== end CFEDIT.H ================================

private:
   // ================== EDITCALC.CPP ================================
   // static data
   int   cf_edits;
   int   cf_udflkup;
   LPMFFIELD cf_calcfld;
   LPUDF cf_theudf;
   int   cf_inlink;
   int   cf_newtype;
   int   cf_newfile;
   FLDID cf_calcndx;
   int   cf_inexp;
   LPSTR    cf_cevalbuf;
   LPSTR    cf_uevalbuf;
   LPSTR    cf_cexpbuf;
   LPSTR    cf_uexpbuf;
   int   cf_evalbuflen;
   int   cf_oldlen;
   char far *cf_uoldexp;
   char far *cf_coldexp;
   unsigned long cf_savflags;
   FLDID cf_savndx;
   char  cf_savfno;
   char     cf_origname[MAXDNAME];
   LPSTR    cf_oldlist;
   int      cf_uInUse;
   int      cf_uCallDif;
   unsigned long cf_oldflags;
   char     cf_olddecl[DECLEN+1];
   char     cf_oldname[UDFNAMELEN+1];
   int      cf_oldtype;
   unsigned long cf_flags;
   char     cf_ufname[UDFNAMELEN+1];
   int      cf_mode;    // 0=>create; 1=>edit; 2->delete (udfs only)
#if defined (RSW)
   LPSTR    cf_xltP;
#endif
   // static functions
   int mapflagerr(int ecode);
   int remap(int ecode);
   int chkCircularLink(LPMFFIELD fld,FLDID ndx);
   int linksOkay(void);
public:
   void  clrtemps(void);
private:
   void  cfedochain(LPMFFIELD fld);
   int lurecomp (LPUDF u, int doIt);
//#if defined(INTERACTIVE)
   void  restore(LPMFFIELD calcfld,FLDID calcndx);
//#endif
   // ================== end EDITCALC.CPP ============================

private:
   // ================== CALLFORM.CPP ================================
   void  lcat80(LPSTR s1,LPSTR s2);
   LPSTR  ltype(char t,LPSTR abuf);
   // ================== end CALLFORM.CPP ============================
  // =================== END CFEDIT directory ========================


  // =================== BEGIN CFCOMP directory ======================
   //=================== _CFCOMP.H ===================================
public:

   int  savfilcnt;
   FLDID  savfldcnt;
   int  filefirst;

   char  *pSyntaxStack, *pCompileBuf;  /* syntax stack and compile buffer pointers */
   char  *pSyntaxStackHead;      /* start of syntax stack */
   char     functype;
   int   cfefunc;
   int   querypos;   /* query() pos - used if restrict() finds an error */

   // Function prototypes
   // formargs.c
   struct udf *lugetudf(void);
   void  lurlsexp(struct udf *u);
   void  lurlsudf(struct udf *u);
   void  uFreeUdfs(void);
   void  lufixrefs(struct udf *u);
   void  freeargs(void);
   int lformargs(char *inp,char *fnamep,int *argcntp,int *erroffp,int okayfno,LPSTR far *alistp );
   // restrict.c
   int chksqleng (char *exp);
   int ckquery( MFFIELD *cf, UDF *udf, int *pos);
   int lcfcomp(int *erroffP);
   // toktests.c
   int lafunc(char *tok,TOKVAL *valP);
   // peval.c
   void  pushpic(struct pic *p);
   void  poppic(struct pic *p);
#if defined (RSW)
   static void pnoop(void);
#else
   static void pnoop(void);
#endif
   static void pushdpic(int y4);
   static void pushdtpic(void);
   static void pushtpic(void);
   static void pushpspic(int l,int ml,int pic);
   static void pushspic(int l,int ml);
   static void pushwwspic(int l,int ml);
   static void pushpnpic(int i,int d,int pic);
   static void pushnpic(int i,int d);
   static void pushlpic(void);
   int picpref(int action,int pic1,int pic2);
   // pdate.c
   static void pdate(void);
   static void pcdow(void);
   static void pcmon(void);
   static void pday(void);
   static void paged(void);
   static void ppast(void);
   static void pndow(void);
   static void pdateadd(void);
   static void pdatediff(void);
   static void pdatepart(void);
   static void pdatename(void);
   static void ptodate(void);
   static void ptotime(void);
   static void pdttoc(void);
   static void pttoc(void);
   static void pdtlookup(void);
   static void pttos(void);
   static void pctdt(void);
   static void pctos(void);
   static void pctot(void);
   static void pstoc(void);

#ifndef RSW
   static void pdbf(void);
#endif
   static void pdow(void);
   static void pdtoc(void);
   static void pyear(void);
   static void ptime(void);
   static void pdarith(void);
   static void pddiff(void);
   // pnum.c
   static void pminmax(void);
   static void pexp(void);
   static void pint(void);
   static void prnd(void);
   static void pval(void);
   static void ppage(void);
   static void plastpage(void);
   static void preportpage(void);
   static void pcopy(void);
   static void precn(void);
   static void pdel(void);
   static void pxabs(void);
   static void pxmod(void);
   static void piif(void);
   static void pinrng(void);
   static void pinlst(void);
   static void pcase(void);
   static void pspelln(void);
   static void pblnknum(void);
   // pstr.c
   static void pat(void);
   static void plen(void);
   static void pspc(void);
   static void psubst(void);
   static void pasc(void);
   static void pchr(void);
   static void pstr(void);
   static void pisx(void);
   static void plr(void);
   static void prepl(void);
   static void prepn(void);
   static void pstuff(void);
   static void pstrrep(void);
   static void pstrsearch(void);
   static void pstrcount(void);
   static void pcaps(void);
#ifndef RSW
   static void pscope(void);
#endif
   static void psndx(void);
   static void pwdcnt(void);
   static void pword(void);
#ifdef RSW
   static void plike(void);
#endif
   static void plibn(void);
   static void pudfn(void);
   static void priparam(void);
   static void pclookup(void);
   // psystem.c
   static void pflip(void);
   static void ptransform(void);
   static void pquery(void);
   static void pcdll(void);
#ifdef RSW
   static void pixsql(void);
#endif
   // toktests.c
   int lanumber(LPSTR tok,union tokval far *valP);
   int lafile(LPSTR tok,union tokval far *valP);
   // ============================= end _CFCOMP.H ==================

   // ============================= Begin CFCOMP.H =================
public:
   int   chainsaved;
   int   tokslop;
   int      udfslop;

#if defined(DATADICT)
   int   FirstErr;
#endif

   int      AllFields;

   // **********************************************************************
   //
   // Function Prototypes Section:
   //
   // from udf.h
   LPUDF ugetudf();     /* "get a new udf specifier" routine */
   int lpeval(LPSTR in,struct mffield far *resfld);
#ifdef RSW
   int lexplt(LPSTR in,int far *lenP,unsigned long far *typeP,LPSTR filnoP,FLDID *ndxP, LPMFFIELD resfld,struct udf far *resudf,int action);
   int lcompile(LPSTR expP,int far *erroffP,int far *rpnlenP,unsigned long far *flagsP,LPSTR filnoP,FLDID *indexP,struct mffield far *resfld,struct udf far *resudf, int mode);
   int xeval(LPSTR in,struct mffield far *resfld,int doit,LPSTR *xp );
   int xlower(LPSTR pre, LPSTR post);
   void  xevalall(void);
   LPSTR getDateFormat(void) ;
   LPSTR getDatetimeFormat(void) ;
   LPSTR getTimeFormat(void) ;
#else
   void  lexplt(LPSTR in, int far *lenP, unsigned long far *typeP, LPSTR filnoP, FLDID *ndxP, LPMFFIELD resfld, LPUDF resudf);
   int lcompile(LPSTR expP,int far *erroffP,int far *rpnlenP,unsigned long far *flagsP,LPSTR filnoP,FLDID far *indexP,struct mffield far *resfld,struct udf far *resudf);
#endif
   int lbufeval(LPSTR in,struct mffield far *resfld);
   struct udf far *lckufcomp(void);
   void  stodinit(void);
   int ltoken(LPSTR far *sP ,union tokval far *valP,int far *lenP,int qfn);
   int lafield(LPSTR tok,union tokval far *valP,int qualcheck);
   int lcfprep(LPSTR input);
   struct mffield far *ckcomp(void);
   // cfrepnm.c
   void  lcfqualifyall(LPSTR expr,LPSTR alias);
   void  lcfreplace(LPSTR expr,int field,int file,int udf,FLDID fieldindex,int ufindex,int qualifying,LPSTR newnm,LPSTR oldname);
   // ============================= end CFCOMP.H ===================
   // ============================= Begin CFCOMP.CPP ===============
private:
   // static data from cfcomp.cpp
   //
   LPSTR cf_LookupFieldArg;
   long *cf_branch;
   int   cf_ifno;
   LPSTR cf_nextlast;
   LPSTR cf_lastcp;
   int cf_ecode;
   int cf_cpoflo;
   int cf_synoflo;
   int cf_retTypeoflo;
   char *cf_retTypeStack;  // Does not need to be initialized - its initialized in lcfcomp()
   char cf_elements[5];

   // static functions from cfcomp.cpp
   //
   void  copyn(char *ip,int len);
   int  relact(char action);
   int  logact(char action);
   int  operand(char token);
   int  mistype(char svtype,char ttype);
   void  getRetType(int *funcNumber, int argCnt);
   int  prevokay(char prvtok);
   int  rule1(void); /* termination */
   int  rule2(void); /* function argument processing */
   int  rule3(void); /* final function argument */
   int  rule4(void); /* parenthesis removal */
   int  rule5(void); /* binary operators */
   int  rule6(void); /* unary operators */
   int  rule7(void); /* error detection */
   // ============================= end CFCOMP.H ===================
private:
   // ============================= CFPREP.CPP =====================
   // static functions from cfprep.cpp
   int lcontains(LPSTR s, LPSTR p, LPSTR *qP);
   int outofstr(int off, int *offlist); /* list of string start/stop offsets */
   // =========================  end CFPREP.CPP =====================
private:
   // ============================= EXPLT.CPP =======================
   // static functions from explt.cpp
#ifndef RSW
   int owner (int fn);     /* returns file number of "owner" file */
   int grpowner (int fn);  /* file number of scan group "owner" file */
   int lfno (LPMFFILE file);
#endif
   // ============================= end EXPLT.CPP ===================
private:
   // =========================== FORMARGS.CPP ======================
   int lckargname (LPSTR n);
    // ========================== end FORMARGS.CPP ===================
private:
   // =========================== PEVAL.CPP =========================
   // static data
   int      cf_PStkOflo;
   LPMFFIELD   cf_rf;
   // static functions
   int  setpargs (int acnt);
   void  pushparg(int n);   /* n is argument number to push */
   void  poppargs(void);
   void  pushkeypic(char keyword, int keytype);
   void  numpic(CFPIC *p);
   int bagit(void);
    // ========================== end PEVAL.CPP ======================
private:
   // =========================== RESTRICT.CPP ======================
   // static functions
   int inquery(FLDID fno);
   int restrict(LPSTR exp, int func, int *pos, int *errors);
    // ========================== end RESTRICT.CPP ================
private:
   // =========================== TOKEN.CPP =======================
   // static functions
   int paralogic(char *s);
   int keywords(char *s, int *kstype, int *kctype);
   LPSTR lnexttok(LPSTR cp,LPSTR tok);
   int badudf(int n);
   // ========================== end TOKEN.CPP ====================
#ifdef RSW
private:
   // =========================== TOKTESTS.CPP ====================
   // static functions
   int ckfld(LPSTR tok,TOKVAL far *valP,int qualcheck,int unqualified);
#endif
   // ============================ end TOKTESTS.CPP ===============
  // ============================= end CFCOMP directory ============
  // ============================= begin RSW\xeval.cpp =============
private:
   // static data
   int   iMemFault;
   LPSTR *stackPtr;
   // static functions
   void  cleardexp(int doit, LPMFFIELD fld);
   void  clearstack(void);
   int pushstr(LPSTR s);
   int nextpiece(LPSTR result, LPSTR *fp);
   void  fillODBC();
   void  parseODBC();
   LPSTR getFormat(LPSTR name);
   void  loadxtab();
   int xsetargs(int acnt);
   int xpusharg(int n);
   void  xpopargs(void);
public:
   void  freextab(void);
  // ============================= end RSW\xeval.cpp ================

  // ============================= begin RRW\LOOKUP.CPP =============
private:
   int fixkey(int len,int dec,int ixtype, char *val, char *buf);
   void  fnm(char far *nm);
  // ============================= end RRW\LOOKUP.CPP ===============
   // stuff for Visual FoxPro DBC support
public:
   PSTR getLongName (PSTR lpszTablename, PSTR lpszFieldName, PSTR lpszLongname);

};
#endif
