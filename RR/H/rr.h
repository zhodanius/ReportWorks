// rr.h : main header file for the RR application
//
#if !defined(_RR_H_)

#define _RR_H_

#ifndef __AFXWIN_H__
   #error include 'stdafx.h' before including this file for PCH
#endif

   #include "resource.h"       // main symbols

   #include "datadict.h"   // needed by DATADICT stuff
   #include "mffield.h"    // needed by DATADICT stuff
   #include "mfxfld.h"     // needed by MF stuff
   #include "wmain.h"      // for MAXARGS
   #include "globals.h"    // for APPPATHSTRUCT
   #include "users.h"      // for USE_BYTES
   #include "wband.h"      // for WHENP
   #include "rrxtab.h"     // for LPXTABINFO
   #include "explmgr.h" // CExplicitLibraryManager

   #include "fax.h"     // AMH 2/25/97 Added Fax header

// Useful Wall Data check to validate a memory address
//                                   NULL                      Undefined                       Not Initialized
#define IsValidPointerX(x) ( ((void*)x!=(void*)NULL) && ((void*)x!=(void*)0xdddddddd) && ((void*)x!=(void*)0xcdcdcdcd) )

// Max size of app name, help, and about from attribution (or string table).
#define MAXAPPINFO 80

/////////////////////////////////////////////////////////////////////////////
// CRrApp:
// See rr.cpp for the implementation of this class
//

class CMainFrame;
#if !defined INTERACTIVE
class CRrRuntime;
#endif

#if defined(RSW)
// Wall Data class reference.
class RumbaUIInfo;
#endif

class CRrApp : public CWinApp
{
public:
   DWORD m_File_Attributes;
#if !defined INTERACTIVE
   // variable from _RUNTIME.H
   CFile jfFile;        // job file
   BOOL  ARPEGGIOLive;
   LANGID   langid;        // language ID
   int      RIType;        // runin file type
   BOOL  firstjob;
   int      *jobNos;    // job number array, allocate space if needed
   CRrRuntime* m_pRuntime;
   VOID  leave(int val);

   BOOL  IsDesignerRegistered( void );
   void  RegisterShortcutExtensions( void );
#endif
   BOOL  m_bDisplaySplashScreen ;   // should the splash screen be displayed?
   bool  m_runningAsNonInteractiveUser; // U2I: set when running as ATL

   CRrFax*  m_pFax;     //AMH Added new Fax member object

#if !defined (INTERACTIVE)
   BOOL  m_bCommentsOnlyAtStartOfLine;
#endif
   void  RegisterAppPath( void );

   APPPATHSTRUCT far * Paths; // pathname structure

   // App name from attribution or our string table.
   char  m_Title[MAXAPPINFO];
   char  m_HelpAbout[MAXAPPINFO];
   char  m_HelpTopic[MAXAPPINFO];
   BOOL  m_CallLibrarian ;

#if defined(RSW) && !defined(RUNDLL)
   // Wall Data utility functions (used in rr.cpp and rrwall.cpp)
   BOOL  ValidateLicenseInfo();
   CString  GetSystemDir();
   BOOL  LoadRmbInfo();
   BOOL  UnLoadRmbInfo();
   BOOL  ShowAboutBox();
   BOOL  ShowStartup();
   BOOL  CloseStartup();
   void  GetAttrInfo();

   // AMH 9/6/96 Added instance handle for attribution dll
   HINSTANCE hAttribLib;      // instance handle of attribution library

   // AMH 9/6/96 Added method to load the attribtion dll
   BOOL  loadAttribLib(void);

   // Wall Data utility variables (used in rrwall.cpp)
   HINSTANCE m_hInstRmbInfo;
   RumbaUIInfo *m_InfoObject;
 #ifdef INTERACTIVE  // RSW Interactive
   CString  m_csRegisteredOwner;
   CString  m_csRegisteredOrganization;
   void  GetWallUserInfo( void );
   inline   CString GetOwnerName( void ) { return m_csRegisteredOwner; }
   inline   CString GetOrganizationName( void ) { return m_csRegisteredOrganization; }
 #endif
#endif

   // Two huge values to match the original RRW "HUGE" from math.h.
   // Changing to 32 bit compiler changed HUGE, so we need invariant values.
   // Huges are inited to bit patterns in App constructor.
   double   m_HugePositive;
   double   m_HugeNegative;

   unsigned long driveBitFromPath(LPSTR path);

#if defined (RSW)
public:
   CString  GetConnectExtra( void );
private:
   void  SetConnectExtra( CString csExtra );
   CString  m_ConnectExtra;
#endif

   // ***** begin datadict.h
public:
   char  DDTableName[MAXDNAME+1];      // "soft" name for TABLE_NAME field
   char  DDFieldName[MAXDNAME+1];      // "soft" name for FIELD_NAME field
   char  DDSecurityName[MAXDNAME+1];      // "soft" name for SECURITY field
   char  DDCommentName[MAXDNAME+1];    // "soft" name for COMMENT field
   char  DDExtendedName[MAXDNAME+1];      // "soft" name for EXTENDED field
   char  DDFormulaName[MAXDNAME+1];    // "soft" name for FORMULA field
   char  DDFilterListName[MAXDNAME+1]; // "soft" name for FILTER_LST field
   char  DDFieldListName[MAXDNAME+1];  // "soft" name for FIELD_LIST field
   char  DDInstantRepName[MAXDNAME+1]; // "soft" name for INSTNT_LST field

#if defined(PASSWORD_REQD)
   UINT  SecurityError;       // used in read report to detect security problems
   UINT  SecurityLevel;
#endif
   UINT  DDChangeFile;
#if defined(RECORD_FILTER)
   UINT  DDRecordSecurity;
#endif
   BOOL  m_bDDSquawked;

   void  ddrelease( void );
   int      ddsetup( LPMFFIELD *firstfld, LPSTR alias, int filno );
   void  ddsetup_nomaster( void );
   int      ddlookup( LPSTR field, LPSTR table );
   void  ddcalccleanup( LPMFFIELD bad );
   BOOL  ddAlias(char *filename, char *alias) ;
#if defined(PASSWORD_REQD)
   void  cleanUpSecurityList( void );
   BOOL  scanSecurityList( LPSTR name );
#endif
   // ***** end datadict.h

   // ***** begin former statics from DATADICT directory modules
private:
   int      DDdoNothing;   // set to TRUE when in nextjob()
   CFile dbfile;        // dictionary file handle
   CFile dbmemo;        // memo file handle
   UINT  memoblksz;     // memo file block size
   DWORD memocurpos;    // current position
   DWORD memobegpos;    // current position
   DWORD memocurblkoff;
   DWORD memocurendoff;
   DWORD memonxtblkoff;
   UINT  memos;
   UINT  mtype;
   UINT  DB4type;
   DBHEADER dictHead;   // database file header structure
#if defined(PASSWORD_REQD)
   PSECLIST SecurityList;
   BOOL  SecurityListError;
#endif

#if defined(PASSWORD_REQD)
   void  addToSecurityList( LPMFFIELD fld );
#endif
   void  myzack( LPSTR text );
   int      ddmemhead( DWORD hpos, DWORD far *nextP, DWORD far *endP );
   int      ddmemchar( LPSTR cP );
   char  ddgetmch( void );
   int      getmemocalc( LPSTR dataP, int coff );
   void  ddmakecalc(LPSTR name, LPMFFIELD firstfld,
               LPSTR alias, UINT evalonceok );
   int      ddopendbf(void);
   int      ddopenindex(LPSTR tagname) ;
   void  ddclose(void) ;
   void  ddclosedbf(void) ;
   void  ddcloseindex(void) ;
   void  ddcalcs(LPMFFIELD *firstfld, LPSTR alias, int filno, int fileno) ;
   void  ddSetProperties(LPMFFIELD fld) ;
   void  upcaseit(LPSTR str, int len );
   void  makeKey(int fileno, LPSTR fldname, LPSTR tablename );
   BOOL  fillit(DWORD recno);
   void  retrycalcs( LPMFFIELD firstfld );
   void  fixFieldIDs( LPMFFIELD start );
   int      ascii_to_int(char* s, int n) ;


   // ***** end former statics from DATADICT directory modules

   // from global.h
public:
#if defined (RSW)
   BOOL  AllowDoubleConnect;     // to get connect string for wizard
#endif
#if !defined (INTERACTIVE)
   LPSTR RunDllProcID;
   LPSTR RpHandle;      // moved from CRrRuntime class
#endif
int AtArg;
   BOOL  ColorTube;        // otherwise mono, I presume
// Ain't no resource DLL
// HINSTANCE hResource;    // handle to resource DLL
   WORD  InchX;               // pixels per inch horizontally (MM_TEXT mode)
   WORD  InchY;               // pixels per inch vertically (MM_TEXT mode)
   BOOL  ZDeny;
   HINSTANCE hRuntimeDLL;     // handle to runtime DLL

   CExplicitLibraryManager m_elmFileManager ;

   // end global.h

   // util.h
   int      ZNVError;

   char  *lstpblk(char far *p);
   char  *stpblk(char *p);
   int      lzcutoff(char far *s, char c);
   int      zcutoff(char *s, char c);
   FOUR  DateToDay(ZDATE *dt);
#ifdef RSW
   BOOL  zdatecheck(ZDATE far *dt);
   BOOL  DateNorm( ZDATE far*idt, ZDATE *odt);
   BOOL  zdatein( ZDATE far *dt, FOUR far *dy);
#else
   BOOL  zdatecheck(ZDATE *dt);
   BOOL  DateNorm(ZDATE *idt, ZDATE *odt);
   BOOL  zdatein(ZDATE *dt, FOUR *dy);
#endif
   void  ztimein(DBITIME *dt, double far *mSeconds);
   int      divmod(FOUR a, FOUR b, FOUR *c);
   void  zdateout(FOUR dy, ZDATE *dt);
   void		zdateout(FOUR dy, ZDATE *dt, char cFDW[3]); // experiment with second prototype form by CAS on 08/24/2017
   void  ztimeout(double mseconds, DBITIME *time_out);
   void  ztimeintervalout(double mseconds, TIMEINTERVAL *time_out,   int TimeInterval);
   char  *zfdaytxt(int d);
   char  *lzfileext(char far *path);
   char  *zfmontxt(int m);
   void  zgetdate(ZDATE *d);
   void  zgettime(ZTIME *t);
   BOOL  lzmatch(LPSTR pattern, LPSTR string);
   void  lzmemcpy(char far *dest,char far *src,unsigned ct);
   int      memblks(unsigned minsz);
   unsigned zmemory(unsigned minsz);
   char  *zmontext(int m);
   int      testdbl(double dbl,int val[]);
   double   zsERRdbl(void);
   int      zERRdbl(double dbl);
   double   zsNAdbl(void);
   int      zNAdbl(double dbl);
   int      ztnullquad(UTWO *data);
   void  zsnullquad(int *data);
   int      ztnullstr(UONE *data);
   void  zsnullstr(UONE *data);
   int      ztnullnum(double dbl);
   void  zsnullnum(double far *dblP);
   void  znvinit(void);
   char  gc(CFile * nvfile);
   void  pc(char c);
   int      getline(CFile *nvfile, char *buf );
   int      trimtail(char *cp);
   int      getpair(CFile *nvfile, char far **npP, char far **vpP, char *pMapFileMem, int first);
   NV    *cmngetnvlist(CFile *nvfile, long startpos, long endpos, char *pMapFileMem);
   NV    *getnvlist( CFile *nvfile, long startpos,long endpos);
   NV    *getdllnvlist(void);
   void  lfreenvlist(NV far *nv);
   NV    *lfindnv(LPSTR name,NV far *first);
   void  lzpad(LPSTR s,char c,int   endLen);
#if !defined INTERACTIVE
   void  zdelay(int nSeconds);
#endif
   //temporary change to test if changing the TYPE of zread has an impact on compilation CAS 8/22/2014
#if !defined(RSW)
	int zread (CFile *file, void *buf, unsigned int length);
#endif
   //BOOL  zread (CFile *file, void *buf, unsigned int length);
   //  *******  Also, moved the CADSFile into the NOT RSW block CAS 8/22/2014
   //int   zread (CADSFile *file, void *buf, unsigned int len);
#if !defined (RSW)
	int   zread (CADSFile *file, void *buf, unsigned int len);
	void  zpsort(char *list[],int cnt);
#else
	// as well as this into the RSW block CAS 8/22/2014
	int zread (CFile *file, void *buf, unsigned int length);
#endif
   void  zppsort(char *list[],int cnt,SORT_ROUTINE rtn);
   void  lzppsort(LPSTR list[],int cnt,LSORT_ROUTINE rtn);
   int      zrdblock(CFile *zfile, int blkno, char *dest);
   int      zwrblock(CFile *zfile, int blkno, char *source);
   BOOL  ztimenumin(char *s, int *anum);
   BOOL  zdatenumin(char *s, int places, int *number, int atstar);
   void  zdatedelta(FOUR d1,FOUR d2,ZDATE *dt);
   int      zstrdint(char *string, FOUR *day);
   int      zstrtint(char *string, double *dtime);
   char  *testdate(char *input);
   static int zfcmp(CHARP left,CHARP right,int exact,int flat);
   static int cmpsort(void *left,void *right);
   static int zsflatcomp(LPSTR left, LPSTR right);
   static int zcmp(CHARP left, CHARP right, int exact, int flat);
   static int zcmp1(CHARPP left,CHARPP right);
   static int zcompOem(LPSTR left,LPSTR right,int len,int exact,int flat);
   static int zcmpsort(CHARP left, CHARP right);
   static int zcompWin(LPSTR left,LPSTR right,int len,int exact,int flat);
   static int zfcmpsort(CHARP left,CHARP right);
   static int zfcmp1(CHARPP left,CHARPP right);
   static int zfncmp(CHARP left,CHARP right,int lgt,int exact,int flat);
   //int (*ZFCmpP)(CHARP,CHARP,int,int);        /* or zfcmp() */
   //int (*ZFCmpP1)(CHARPP,CHARPP);          /* or zfcmp1() */
   //int (*ZFCmpPsort)(CHARP,CHARP);         /* or zfcmpsort() */
   //int (*ZFKlCmpP)(CHARP,CHARP,int,int,int);
   static void magic(int *acc, int *uml, int *ineq, int flat, int chr);
   static int match2(int lc, int rc, int lu, int ru);
   static int matchuml(int chr1, int uml, int acc, int ineq, int chr, CHARPP prt, int flat, int sense);
   static int compEm(LPSTR left,LPSTR right,int len,int flat,int win);
   int      zcompBin(LPSTR left,LPSTR right,int len);

   // end util.h

   // tfmontxt and tfdaytxt
public:
   char  u_zMaxDow;
   char  u_zMaxMon;

   // static variables from znv.cpp
private:
   char  pb;
   int      pbfull;
   long  spos, epos;
   // end of znv.cpp static vars

   // exportmg stuff
public:
   static void XCALL_SetUpCallbacks (void);
   HINSTANCE LoadExportDLL (LPSTR lpszExportLine);
   static void GetModuleString (LPSTR lpszExportLine, LPSTR far* lpszModuleName, BOOL far * bLoadEXE);
   BOOL  xCrosstabBefore(LPEXPFIELD_INFO FIELD_Info);
   void  xCrosstabAfter(LPEXPFIELD_INFO FIELD_Info);
   // end exportmg

   // from wmain.h
public:
   BOOL  checkArgs(void);
   BOOL  checkAutoSaved(void) ;
   void  buildArg();
   int      doCLArgs(LPSTR lpCmd);
   BOOL  bStartReport ;
   void  freeDLL(void);
   int      getCLFilter(void);
   void  getLibName(void);
   void  initGlobDefs(void);
   void  loadDLL(void);
#if defined (INTERACTIVE)
   BOOL  okayToLeave(HWND hWnd, BOOL exit);
#else
   BOOL  report(void);
   void  runoend(void);

   // SJO moved this to the app class, we do this before we have a runtime job
   //
   int runoinit(void);
   int sqljob(void);
   BOOL okayToLeave();
   BOOL isnumstr(char *str);
   BOOL wrtInit(LPSTR lpCommand);
   void  wrtRun(void);
   BOOL  singleFileNamePassedIn(void);
   BOOL  matchInputTypes(void);
   BOOL processCommandLine(void);
   BOOL processCommandLineArgs(void);
#endif
   void showMainWindow(void);
   void wReset(void);
   int badnews(WORD id);
   BOOL appInit(CRrDoc *, CMainFrame *, HINSTANCE, HINSTANCE, LPSTR, int);
   void convertDict(void) ;
   void GetModuleVersionString (LPSTR lpszModuleFileName, LPSTR far * lpszModuleVersionString,
                                 DWORD * dwFileVersionMS, DWORD * dwFileVersionLS );
   HINSTANCE LoadCorrectDLL (LPSTR lpszOriginalModuleFileName,
                  LPSTR lpszCorrectVersion,
                  LPSTR lpszLoadedModuleFileName,
                  HINSTANCE hLoadedDLL);


   PROCESS_INFORMATION m_convert;      // Convert dictionary process

   // end wmain.h

   // wserial.cpp
private:
#if !defined(NOSERIALNUM)
   BOOL  bPrevInstance;
// HWND  hSerialWnd;
   int      IDSlot;
   int      Prod_Num;
// static LRESULT CALLBACK EXPORT BogusWndProc( HWND, UINT, WPARAM, LPARAM );
// BOOL  CreateSerialNumberWnd( void );
   HANDLE   m_hMutex;
   HANDLE   m_hLicenseMapFile;
   LPVOID   m_pLicenseMapFileMem;
public:
   BOOL  GetSerialNumber( void );
   void  ClearSerialNumber( void );
// void  DestroySerialNumberWnd( void );
#endif
public:
   char  SerialNumber[15];
   char  UserID[USE_BYTES];
   BOOL  DemoVersion ;
   BOOL  bRunTimeLicense ;
   char  UserIndexDirectory[50] ;

public:
   int argc;   // we need our own command line stuff for MFC
   LPSTR argv[MAXARGS];

   // end wserial.cpp

   // from cmdline.cpp
private:
   int RepArg;
   int LibArg;
   int TableArg;
   int InstantArg;
   int ScriptArg;
#if defined RSW
   int RWQArg;
#endif
#if defined (RSW) && defined(SESSIONID)
   int SessionArg;
#endif
   HINSTANCE hDLLArgLib;   // pre-loaded command line DLL
   // end cmdline.cpp

   // from winit.cpp
private:
   void makeStdLib(PSTR path);
   BOOL minit();
   // end winit.cpp

   // from WREPORT\MRU.CPP
public:
   // public routines from mru.cpp
   void AddRecentFile(LPCTSTR lpszPathName) ;
   // end WREPORT\MRU.CPP

private:
   BOOL openLib();
   int getArgv(LPSTR lpCommand);
   BOOL isDlgMessage(HWND hDlg, MSG *msg);
#if defined(PASSWORD_REQD)
   unsigned int decodeSecLvl(unsigned int seclvl);
   int getSecLvl(void);
#endif
#if defined(PASSWORD_REQD)
   int decodePassWord(char *password);
   int getPassWord(void);
#endif

public:
   // mjs 8/17/95  These are really in RRDOC.
   // void DBIinitSessionID(void);
   // void DBIsetSessionID(LPSTR);
   // end cmdline.cpp

   // version.h
public:
HINSTANCE LoadAndCheckLibrary (LPCSTR lpszLibFileName, int minapiversion);
   // end version.h

public:
   // function to return screen size (SM_C?MAXIMIZED)
   CSize getScreenSize(void);
   CSize getScreenSize(int);
   BOOL bWin95UI;    // TRUE if Win95-style UI

public:
   // context help for dialog controls routines
   BOOL showDlgCtrlHelp(LPARAM lParam, DWORD ctrlid, WORD helpcode);
   BOOL showDlgCtrlCHelp(HWND hDlg, WPARAM wParam, LPARAM lParam, DWORD ctrlid, WORD helpcode);
   LPSTR getHelpPath(void);

   // routines for opening, creating, deleting files that replace the obsolete OpenFile()
private:
   HANDLE rrOpenFile      (LPCSTR filename, DWORD access, BOOL bCreate, DWORD flags );
public:
   BOOL   DeleteFile      (LPCSTR filename) ;
   BOOL   DoesFileExist   (LPCSTR filename) ;
   HANDLE CreateFile      (LPCSTR filename) ;
   HANDLE OpenFile        (LPCSTR filename) ;
   BOOL   IsValidFileName (LPCSTR file_name, CFileStatus& file_status) ;
   BOOL   IsDirectory     (LPCSTR path) ;

public:
   CRrApp();

public:
#if !defined(RUNDLL)
// Overrides
   virtual BOOL InitInstance();
   virtual BOOL ExitInstance();
   virtual BOOL OnIdle(LONG);

// Implementation

   //{{AFX_MSG(CRrApp)
   afx_msg void OnAppAbout();
      // NOTE - the ClassWizard will add and remove member functions here.
      //    DO NOT EDIT what you see in these blocks of generated code !
   afx_msg void OnHelp();
   //}}AFX_MSG
   DECLARE_MESSAGE_MAP()
#endif
};

#if !defined(RUNDLL)
extern CRrApp NEAR theApp; // defined in rr.cpp
#endif

/////////////////////////////////////////////////////////////////////////////

#endif
