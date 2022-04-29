// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   rrruntim.h  $
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
// $Log:   D:/R&R Project/archives/H/RRRUNTIM.H_V  $
// 
//    Rev 1.24   Jul 01 2002 15:27:22   Admin
// Pagesize stuff
// 
//    Rev 1.23   16 Apr 1997 09:07:00   pjm
// Add Visual FoxPro DBC override support.
// 
//    Rev 1.22   19 Nov 1996 11:08:38   amh
// Added code for right-click send to printer
// 
//    Rev 1.21   16 Feb 1996 16:21:44   sjo
// Changes made to accept R?W files on the command line as well as .TXT files, 
// .RRS and RSS files from the shortcut maker.
// 
//    Rev 1.20   03 Jan 1996 16:52:48   dlm
// First pass at communication between runtime exe and dll in 32-bitland.
// 
//    Rev 1.19   15 Dec 1995 11:10:34   jpb
// runtime
// 
//    Rev 1.18   14 Dec 1995 13:39:10   sjo
// Added a couple of new calls.
// 
//    Rev 1.17   13 Dec 1995 09:13:40   sbc
// Remove RpWParent
// 
//    Rev 1.16   11 Dec 1995 14:16:40   sjo
// Added leave() and moved two command line switches variables.
// 
//    Rev 1.15   08 Dec 1995 14:58:30   sjo
// Making changes to remove link errors from the runtime.  This mostly involves
// removing functions from runtime version of the Doc or mainframe class.
// 
//    Rev 1.14   04 Dec 1995 15:27:38   jpb
// runtime
// 
//    Rev 1.13   01 Dec 1995 14:28:54   jpb
// 
//    Rev 1.11   30 Nov 1995 17:54:04   sjo
// Changes required for the runtime port to 32 bit MFC.
// 
//    Rev 1.10   30 Nov 1995 11:12:36   jpb
// runTestDialog arg list
// 
//    Rev 1.9   29 Nov 1995 11:46:18   jpb
// more of it
// 
//    Rev 1.8   28 Nov 1995 18:36:56   jpb
// moved stuff from doc to runtime class
// 
//    Rev 1.7   28 Nov 1995 15:54:48   jpb
// moreofthesame
// 
//    Rev 1.6   27 Nov 1995 17:05:22   jpb
// add to class
// 
//    Rev 1.5   22 Nov 1995 16:51:50   jpb
// 
//    Rev 1.4   22 Nov 1995 16:32:00   jpb
// 
//    Rev 1.3   22 Nov 1995 15:32:34   jpb
// 
//    Rev 1.2   20 Nov 1995 14:41:42   jpb
// runtime changes
// 
//    Rev 1.1   17 Nov 1995 15:58:46   jpb
// move vars/funcs to CRrRuntime class
// 
//    Rev 1.0   17 Nov 1995 14:43:56   jpb
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _RRRUNTIME_H_

// Make a definition for this module.
//
#define _RRRUNTIME_H_

// rrruntim.h : interface of the CRrRuntime class
//
/////////////////////////////////////////////////////////////////////////////

#include "dbheader.h"

class CRrDoc;

class CRrRuntime : public CObject
{
public:
	
	DECLARE_DYNAMIC(CRrRuntime) ;
	
			CRrRuntime(void);		// constructor
	virtual	~CRrRuntime();			// destructor

	CRrDoc *m_pDoc;
	
// stuff relating to communication with runtime DLL in calling app
	HANDLE	hStartEvent;
	HANDLE	hNextEvent;
	HANDLE	hMapFile;
	LPVOID	pMapFileMem;
	BOOL	OpenDLLComm( void );
	void	CloseDLLComm( void );
	
// variable from RUNTIME.H
	BOOL bOldDOSRep;
	RPPARAMS *RpParam;				// Runtime parameter structure pointer
	char	RpExpDst[EXPDSTSZ + 1];	// Export destination (F,P,D)
	char	RpExpAdd[EXPADDSZ + 1];	// Add-on export type
	long	RpBegPag;				// starting page (if non-zero)
	char	RpChkOut;				// checkpoint interval R(eport),P(age)
	int		RpCopies;				// number of copies (if non-zero)
	int		RpPageSize ;			// Page size
	long	RpEndPag;				// ending page (if non-zero)
	char	RpErrType;
	int		RpEscape;				// allow user to cancel if TRUE
	int		RpFApp;					// append to disk file if TRUE
	char	RpPreview;				// RI_PREVIEW flag
	int		RpPrnNo;				// ptr # to o/p to; or whose codes to use if rep to disk (0,1,2,A)
	char	RpQuery;				// RI_QUERY flag
	char	RpDBC[MAXDNAME];		// RI_DBC override
	char	RpRepPick;				// Select report
	int		RpStatus;				// display sort (etc) status if TRUE
	int		RpTest;					// do test pattern, if TRUE
	int		RpJobRec;		        // job spec file record number
#if defined(RSW)
	LPSTR RpDB;
	int RpNoID;
#else
	int		RpMIType;				// master index data type override
	char	RpMITag[MAXTAG];		// master index tag override
	char	RpScope;
	BOOL	bReadingRuninDBF;		// indicates that we'd like bigger buffers to
									// allow for reading a large query expression
									// from the runin
#endif
	BOOL	bSortGroupOverride;
	int		RpWBorder;
	BOOL	RpWControl;
	int		RpWHeight;
	int		RpWLeft;
	BOOL	RpWMax;
	int		RpWMin;
//// RpWParent obsolete in MFC version ////
//	HWND RpWParent;
	int		RpWTop;
	int		RpWWidth;
	char	RpSorts[NOSORTFLDS][MAXALIAS + MAXDNAME + 1 + 1];
	char	RpGroups[NOBRKFLDS][MAXALIAS + MAXDNAME + 1];
	int		ZBatch;
	LPFLDHDR CurFld;				// Used in several places by rpinit.c.
	int		RpDispErr;
// function from RUNTIME.H
	void runowrit(char *emsg, char time);
	void checkAliases(void);

	NV *pFirstNv;
// function from _RUNTIME.H
	void asciijob (char far * pFileName);
	BOOL readinAsciiControlFile (void);
	BOOL readinDBFControlFile (void);
	BOOL getCommandLineOverrides(void);
	void checkReportAndLibrary (PSTR RepName, PSTR LibName);
	void getReportPathname (int action, PSTR fileNameBuf, PSTR fileNameBufOut);
	//AMH 11/11/96 Added new method to class for send to printer right click
	BOOL SendToPrinter(void);
#if defined(RSW)
	int nextjob(int jobno);
	int sqljob(void);
#else
	int nextjob(char *filename,int jobno,int repeat);
#endif
	BOOL inAlphaList(char * lpName);
// from wnextjob.cpp
//	LPSTR RpHandle;		// moved to app class
	int DLLWinHandle;
#if defined RSW
	PSTR findConnectSep(PSTR buf);
#endif
	PSTR findRI_ID(void);
	int  doreport(void);
	int  report(void);
private:
	CFile hAtFile;		// for ASCII runin
	long LastJFPos;
	LPMFFIELD dummyfld;
	char nextjob_pb;
	int nextjob_pbfull;
	// From wrtmain.cpp
	BOOL inlist(PSTR string, char *list[]);
	void rpfieldinit(void);
#if defined RSW
	BOOL setRpDB(PSTR dbstr);
#endif
	void findStr (char *name, char *buf, int checkLen);
	long findNum(char *name, long defaultVal);
	int findLog (char *name, BOOL defaultVal);
	char gc (void);
	void pc (char c);
	int nextName (char *buf);
	void trimstr(PSTR hair);
	void skipspaces(PSTR *str);
	BOOL nextAscii (int	 jobNo, PSTR jobFile);
#if defined RSW
	void sqljobclean(void);
	int writeToJobFile(char type, char *p, WORD cnt);
	MFFIELD *findrifld(char *name, int num);
	void swrstr(char *name, int type);
	void swrnum(char *name, int type, int a_long);
	int swrlog(char *name, int type);
	void write_job_rec(void);
	int bail(int ids,char *text, char *buf);
	void wandq_free(BOOL w, BOOL q);
	int addnvname(char *buf, NV **first,NV **last, NV **next);
	int addnvvalue(char *buf, NV **first, NV **next);
#else
	BOOL masterIndexCommon(PSTR lpMaster);
	LPMFFIELD findfield(PSTR name);
	BOOL chkfields(void);
	BOOL nonspace(PSTR start,PSTR end);
	char dbrecd[98];	/* runout record (+ null terminator) */
	int ROreclen;
	int ROheadlgt;
#endif
	PSTR findnext(PSTR name);
	BOOL set_rpAlias(PSTR rpalval, PSTR rpalname, int alindex, PSTR error);
// end of wnextjob.cpp
// from runtime.cpp
public:
	CFile ROFile;
	int rocreate(PSTR dbfname, int nofields, dBFIELD *fields);
	int InitOk;
	void roclose(void);
private:
	int RpJobs;
	int RpPages;
	void remove_linefeed(char * message);
	int rowrite(char *record);
// end of runtime.cpp
// from wrun.cpp
	int askScope(void);
	BOOL canceled(void);
	int askParams(void);
	BOOL anyQuestions(void);
	BOOL checkDupeSortFlds(void);
	BOOL checkSortFields(void);
	BOOL checkGroupFields(void);
	BOOL CRrRuntime::checkPreviewOverrides(void);
static BOOL CALLBACK EXPORT runTestDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	BOOL getRuntimeDriver(LPSTR pPrinter, LPSTR pPort);
	BOOL openLib(void);
// end of wrun.cpp
// From druntime.cpp
	HWND parentWnd(void);
/// Statics from druntime.cpp:
private:
	LPSTR lpParam;
	LPSTR lpQuestion;
	int	 nParam;
	LPSTR  pbuf;
public:
//	void fPrompt(LPFLDHDR f, BOOL doit);
static BOOL CALLBACK EXPORT paramDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
static BOOL CALLBACK EXPORT prtDestDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
//	void statusMessage(LPSTR message);
	int askDestination(void) ;
	int askValue (LPSTR lpPrompt, LPSTR lpValue, int vlen);
// end of druntime.cpp
};
#endif

