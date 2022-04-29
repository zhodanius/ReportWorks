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
// Public header file for users of database independence layer
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/VCSMFC/H/DBI.H_V  $
// 
//    Rev 1.7   06 Jun 1996 14:22:10   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.6   30 Aug 1995 16:30:54   mjs
// put contents in #ifdef RSW
// 
//    Rev 1.5   03 Aug 1995 09:39:30   jpb
// Fix part of rsw 1882
// 
//    Rev 1.4   19 Jul 1995 10:25:18   jpb
// move to doc class
// 
//    Rev 1.3   17 Jul 1995 14:43:54   jpb
// Fix RSW 1801
// 
//    Rev 1.2   30 Jun 1995 16:23:08   jpb
// merge rrwin tree rev 1.42
// 
//    Rev 1.1   26 Apr 1995 13:16:40   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.0   16 Mar 1995 16:12:22   sbc
// Initial revision.
// 
//    Rev 1.41   16 Feb 1995 18:00:58   jpb
// add support for DSLikeWithExpression
// 
//    Rev 1.40   08 Feb 1995 13:29:36   sjo
// Checking in a bunch of files for the first wave of datetime support. These
// sources have support for a dFlags that is a long (not an unsigned int) and
// it recognizes date, time and datetime fields.  It only supports dates at
// this time, because we need calcs, picture types, etc if we are to do time and
// datetime.
// 
// 
// 
//    Rev 1.39   02 Feb 1995 10:25:10   jpb
// add DBI timeout routine prototype
// 
//    Rev 1.38   29 Dec 1994 18:28:18   sjo
// Fixed a problem with retrieving multi-datasource reports.  If I had a DS
// connected and then opened a multi-DS report, all related files that were
// not from the master DS, would look like they came from the DS that was 
// connected before the report was open. Problem in DBIgetNADataSourceDatabase()
// we would disconnect any DS that was not connected when we called the routine.
// Files changed: dbi.h, dbi.c, grsql.c, fnexpand.c, ienglog.c and iengmenu.c.
// 
//    Rev 1.37   16 Dec 1994 18:35:38   sjo
// Fix RSW crock 1553. Problem with disconnecting DS that are needed for tasks
//  like report spec and report save.
// 
// 
//    Rev 1.35.1.0   16 Dec 1994 14:21:42   jpb
// some prototypes
// 
//    Rev 1.36   16 Dec 1994 14:16:38   jpb
// add prototypes for ModifySelect, DOSFile, and DirPrefix routines
// 
//    Rev 1.35   02 Dec 1994 09:53:54   dlm
// Add prototype for DBIsetSessionID().
// 
//    Rev 1.34   01 Dec 1994 17:22:22   sjo
// Made some API change.
// 
//    Rev 1.33   28 Nov 1994 15:31:40   jpb
// fix rsw 1122
// 
//    Rev 1.32   18 Nov 1994 11:46:20   sjo
// added a call to DBIconfigureDataSource.
// sorry, I added an arguement, not a call.
// 
//    Rev 1.31   15 Nov 1994 19:20:26   sjo
// Added a free all non-active data source call.
// 
//    Rev 1.30   10 Nov 1994 17:14:42   jpb
// remove a protoype and change a routine name
// 
//    Rev 1.29   09 Nov 1994 15:01:48   sjo
// Fixed a compile problem.
// 
//    Rev 1.28   09 Nov 1994 13:46:30   dlm
// Added some prototypes for routines needed by repio stuff for new
//  ODBC-style search rules.
// 
//    Rev 1.27   04 Nov 1994 18:51:32   sjo
// Added an extern for the DS filter routine.
// 
//    Rev 1.26   03 Nov 1994 09:21:00   sjo
// Making changes to support joining across directories and Data Sources for
// the 'Desktop' platforms.  Most changes are in DBI.C and iengmenu.c.  I also
// had to make changes to the 4 routines which called sql_tables and added 
// support for a new INI file setting.  Also added a new MFFiles structure
// member.
// 
// 
// 
//    Rev 1.25   19 Oct 1994 09:15:44   smh
// DBIsetDatabase now available to the INTERATCIVE.
// 
//    Rev 1.24   11 Oct 1994 11:10:20   jpb
// for DBIgetDBTerm()
// 
//    Rev 1.23   04 Oct 1994 12:18:02   jpb
// add a "cancelled" return from DBIconnectDataSource
// 
// 
//    Rev 1.22   27 Sep 1994 18:10:38   jpb
// add prototype
// 
//    Rev 1.21   26 Sep 1994 09:56:18   jpb
// add prototype for DBIcountDS
// 
//    Rev 1.20   14 Sep 1994 15:35:02   jpb
// remove btrieve VarLen check routine
// 
//    Rev 1.19   14 Sep 1994 14:15:56   jpb
// save connect string used to connect
// 
//    Rev 1.18   09 Sep 1994 17:23:52   jpb
// add externs for owners/databases routines
// 
//    Rev 1.17   08 Sep 1994 12:09:32   sbc
// New functions for getting user/password
// 
//    Rev 1.16   05 Sep 1994 14:43:04   jpb
// add extern for DBUuseSetDB
// 
//    Rev 1.15   02 Sep 1994 16:59:56   jpb
// support RSW logon/magic connect string
// 
//    Rev 1.14   11 Apr 1994 15:51:34   dlm
// Enabled extern of DBIsetPassword() in INTERACTIVE, if SOLOMON.
// Added extern for DBIsetUsername() if SOLOMON.
// 
//    Rev 1.13   17 Jan 1994 18:06:06   say
// Add protos for functions to get data source info
// 
//    Rev 1.12   06 Jan 1994 16:42:14   say
// treat paradox files as file-based
// 
//    Rev 1.11   03 Jan 1994 12:47:32   say
// remove unused arg from DBItables
// 
//    Rev 1.10   27 Dec 1993 14:40:32   say
// Remove 1st arg from DBItables, add DBIisSystemTable proto
// 
//    Rev 1.9   20 Dec 1993 17:56:14   jpb
// externs for DBI ODBC status routines
//  change INITDB_CANCEL value
//  get rid of obsolete platform codes
// 
//    Rev 1.8   09 Dec 1993 16:21:28   sbc
// Add C++ check for extern "C"
// 
//    Rev 1.7   09 Dec 1993 16:09:00   say
// Add protos for Jim
// 
//    Rev 1.6   09 Dec 1993 15:27:54   say
// Add routines to check for Btrieve and Oracle
// 
//    Rev 1.5   09 Dec 1993 14:24:08   say
// Add get*DBMSName routine protos
// 
//    Rev 1.4   08 Dec 1993 16:00:30   say
// Add DBIdataSourceIsSQLServer()
// 
//    Rev 1.3   08 Dec 1993 12:24:02   nwh
// Added prototype for DBIgetInfoLong
// 
//    Rev 1.2   08 Dec 1993 08:48:02   say
// Add DBIsetMaxRows proto for Jim
// 
//    Rev 1.1   07 Dec 1993 16:48:36   say
// Add, delete functions for ODBC
// 
//    Rev 1.0   14 Oct 1993 10:12:48   erp
// Initial revision.
//
// 06/24/93 - ERP - Added function that were not included in this header
//
// 01/05/93 - say - add DBI_TRUNCATION def
//
// ****************************************************************************
//
// Make a definition for this module.
//
#ifndef _DBI_H_
#define _DBI_H_

// mjs 8/30/95 Some sources include this header unconditionally.
#ifdef RSW

#include "qelib.h"

#ifndef RRSQL
#define RRSQL 1
#endif

#define NAMELEN 128
#define PATHLEN 256

// Define max char buffer lengths for data source strings.
// In general, these are likely to be 1 byte strings.
#define MAX_QUOTE_CHAR_LEN 10
#define MAX_SEPARATOR_LEN 10
#define MAX_CONNECT_STRING 255

// Used for sql_tables(), tells us what we are doing
#define CREATE_MASTER	1
#define EDIT_MASTER		2
#define CREATE_RELATED  3
#define EDIT_RELATED		4

#define DBI_NULLFLD	qeNULL_DATA
#define DBI_TRUNCATION qeTRUNCATION

/* DBIinitDB return codes */
#define INITDB_SUCCESS 0
#define INITDB_FAILURE 1
#define INITDB_CANCEL 2

/* Data type definitions - parallel with those in qelib.h */
#define dbiUNSUPPORTED	   -1	// Non-Q+E: indicates a field we'll ignore.
#define dbiCHAR				1	/* Blank padded fixed length string */
#define dbiVARCHAR			2	/* Variable length string */
#define dbiDECIMAL			3	/* BCD number */
#define dbiINTEGER			4	/* 4-byte signed integer */
#define dbiSMALLINT			5	/* 2-byte signed integer */
#define dbiFLOAT			6	/* 4-byte floating point */
#define dbiDOUBLEPRECISION	7	/* 8-byte floating point */
#define dbiDATETIME			8	/* 26-byte date time value */
#define dbiMAXTYPE			8	/* highest type returned by qeColType() */
// Our own additions, converted from underlying database types
#define dbiLOGICAL			9	/* 2-byte, 0 or 1 */
#define dbiMONEY			10	/* BCD number */
					/* YYYY-MM-DD HH:MM:SS.FFFFFF */ 
					
#define QEDATESTART	0 	// If a 0 is returned from qeDateStart, you have a date
#define QETIMESTART  11 // If a 11 comes back from qeDateStart, time 
#define QEDATEEND		9    // End of the date field
#define QETIMENOSECS 18   // Return from qeColDateEnd if there are no seconds
#define QETIMEMILSECS 22  // Return from qeColDateEnd if there are millesecs
#define QETIMEMICSECS 25  // Return from qeColDateEnd if there are microsecs

/* These are macros (as opposed to routines) for execution speed */
#define DBIdecimalToDouble(A,B,C)	qeDecimalToDouble(A,B,C)
#define DBIlongToDouble(A)				qeLongToDouble(A)
#define DBIintToDouble(A)				qeIntToDouble(A)
#define DBIfloatToDouble(A)			qeFloatToDouble(A)

// define DBIdataSourceOuterJoinStyle return values
#define DBI_OJ_ASTERISK		1	// Outer join style uses asterisk, e.g. =*
#define DBI_OJ_PLUS			2	// Outer join style uses plus sign, e.g. (+)
#define DBI_OJ_LEFTONLY		3	// Just LEFT JOIN supported
#define DBI_OJ_RIGHTONLY	4	// Just RIGHT JOIN supported
#define DBI_OJ_LEFTRIGHT	5	// Both LEFT JOIN and RIGHT JOIN supported
#define DBI_OJ_ODBC			6	// Use ODBC outer join extension syntax
#define DBI_OJ_NONE			7	// Platform doesn't support oj ?
#define DBI_OJ_MAX_INI		DBI_OJ_LEFTRIGHT // highest in rswsql.ini

// define DBIidentifierCase return values
#define DBI_NAME_AS_IS		1	// leave name case alone
#define DBI_NAME_TO_LOWER	2	// convert name to lower case
#define DBI_NAME_TO_UPPER	3	// convert name to upper case

#if 0		// remove globals and prototypes
/* Prototypes */
extern	int DBIconnected();
extern	int DBIsqlPlatNeedsEngine(int sqlPlatID);
extern	void DBIsetPlatform(int iPlatID);
extern	long DBIgetInfoLong(int option);
extern	BOOL DBIgetDataSourceDatabase(LPSTR lpszDatabase, int len);
extern	BOOL DBIgetDataSourceDriver(LPSTR lpszDriver, int len);
extern	char *DBIgetDLLversion(void);
extern	PSTR DBIgetUsername(void);
extern	PSTR DBIgetPassword(void);
extern	LPSTR DBIgetConnectString(void);
extern	int DBIinitDB(LPSTR bErrMsgBuf,BOOL bDBAnsi);
extern	void DBIquitDB(void);
extern	void DBIfatalErr(int errnum);
extern	void DBIendSQL(void);
extern	int DBIexecSQL(LPCSTR lpszSQL,LPSTR lpszErrOut);
extern	void DBIrestart(void);
extern	int DBIfetchNextRecord(void);
extern	char FAR *DBIgetRecordText(int firstCol, int lastCol, char separator);
extern	int DBInumCols(void);
extern	int DBIcolType(int iColNum);
extern	int DBIcolNameBuf(char *szColName,int iColNum);
extern	long DBIcolWidth(int iColNum);
extern	int DBIcolPrecision(int iColNum);
extern	int DBIcolScale(int iColNum);
extern	int DBIbindCol(int iColNum,char FAR *lpszBuffer,long iLen,long FAR *piReturnLen);
extern	int DBIcolIsDate(int iColNum);
extern	int DBIcolIsTime(int iColNum);
extern	void DBIgetDate(char FAR *lpszDate,struct ZDate *zdate);
extern 	void DBIgetTime(char far *lpszTime,struct DBITime *dbiTime);
extern   void DBIgetDateTime (char far *lpszTime,struct DBIDateTime *dbidatetime);
extern	BOOL DBItables(LPCSTR szOwner);
extern	LPSTR DBIownerSelect(BOOL bSysTables);
extern	LPSTR DBIownerAltSelect(BOOL bSysTables);
extern	LPSTR DBIdatabaseSelect();
extern	BOOL DBIcurrentDatabase(LPSTR dbname);
extern	BOOL DBIuseSetDB(void);
extern	BOOL DBIuseDatabase(LPSTR dbname);
extern  int DBImemoType(int iColNum);
extern	void DBIsetConvertSelect(BOOL bConvertSelect);
extern	int DBIfetchRandom(long recno);
extern	int DBIsetRandom(void);
extern	int DBIcolType(int iColNum);
extern	int DBIcolDBType(int iColNum);
extern	int DBIsetMaxRows(unsigned long rc);
extern	void DBIsetQueryTimeout(long secs);

// ODBC stuff
extern	int DBIcountDS(void);
extern	BOOL DBIdataSources(void);
extern	LPCSTR DBInextDataSource(void);
extern	BOOL DBIconnectedDataSources(void);
extern	LPCSTR DBInextConnectedDataSource(void);
extern	BOOL DBIdataSourceConnected(LPSTR lpszDS); // answers: is this source connected?
extern	BOOL DBIdataSourceConnectedWithExtra(LPSTR lpszDS,LPSTR lpszExtra);
extern	void DBIfreeConnectStrings(void);
extern	void DBIsetDatabase(LPSTR lpszDatabase);
extern 	BOOL DBIgetNADataSourceDatabase(LPSTR lpszDS, LPSTR lpszDatabase, int len, BOOL leavecon);
extern 	BOOL filterDSdialog(HWND hdlg, BOOL bSelect, LPSTR lpszDataSource, LPSTR returndir, int len);
extern 	int DBIconnectToNewDir (LPSTR lpszDatabase, LPSTR DSName, LPSTR *newSource);
extern 	int DBIjoinAcrossDir(void);
extern	PSTR DBIgetConnectExtra(void);
extern 	void getNADSIndex(LPSTR new_dsname, int *aDSIndex);
extern 	LPSTR DBIgetNADataSource(int NADSIndex);
extern	void DBIgetNADSInfo (int DSIndex, LPSTR lpszDS, int dslen, LPSTR lpszDir, int dirlen);
extern   void DBIfreeAllNADS(void);
extern 	void DBIfreeNADS(LPSTR lpszDS);
extern  BOOL DBIusesSameDLL(LPSTR lpszDS);
extern  	void DBIclearDataSourceInUse(void);
extern	void DBIsetDataSourceInUse(LPSTR lpszDS);
extern  BOOL DBIisDataSourceInUse(LPSTR lpszDS);
#if !defined(INTERACTIVE)
extern	BOOL DBIuseSetDB(void);
#endif
extern	void DBIsetConnectExtra(LPSTR lpszConnectBook);
extern	void DBIsetPassword(LPSTR lpszPassword);
extern	void DBIsetUsername(LPSTR lpszUsername);
extern	void DBIsetSessionID(LPSTR lpszSessionID);
extern	int DBIconnectDataSource(LPSTR lpszDS,BOOL bShowDialog, BOOL bErrMsg);
extern	BOOL DBIdisconnectDataSource(LPSTR lpszDS);
extern	void DBIsetActiveDataSource(LPSTR lpszDS);
extern	LPSTR DBIgetActiveDataSource(void);
extern	BOOL DBIconfigureDataSource(LPSTR lpszDS);
extern	BOOL DBIdataSourceIsDbase(void);
extern	BOOL DBIdataSourceIsSQLServer(void);
extern	BOOL DBIdataSourceIsNetWareSql(void);
extern	BOOL DBIdataSourceIsBtrieve(void);
extern	BOOL DBIdataSourceIsOracle(void);
extern	BOOL DBIdataSourceIsParadox(void);
extern	BOOL DBIdataSourceIsFlatFile(void);
extern	BOOL DBIdataSourceMaxRows(void);
extern	BOOL DBIdataSourceApprox(void);
extern	BOOL DBIdataSourceLikeWithExpression(void);
extern	BOOL DBIdataSourceModifySelect(void);
extern	BOOL DBIdataSourceDirectoryPrefix(void);
extern	BOOL DBIdataSourceDOSFile(void);
extern	char *DBIdataSourceDefExt(void);
extern	int DBIdataSourceExtID();
extern	char *DBIdataSourceIniKey();
extern	int DBIgetNumConnections(void);
extern	void DBIdisconnectAll();
extern	LPSTR DBIgetIniSectionName();
extern	void DBIgetDBTerm(LPSTR s,int bsize);
extern	LPSTR DBIgetDriverDBMSName();
extern	int DBIdataSourceExpressionsInOrderBy(void);
extern	int DBIdataSourceUsesDatabases(void);
extern	int DBIdataSourceUsesOwners(void);
extern	int DBIdataSourceOuterJoinStyle(void);
extern	void DBIdataSourceIdentifierQuoteChar(PSTR quote);
extern	int DBIdataSourceIdentifierCase(void);
extern	int DBIdataSourceQualCols(void);
extern	int DBIdataSourceUseAlias(void);
extern	int DBIdataSourceQualSorts(void);
extern	int DBIdataSourceAddFalse(void);
extern	int DBIdataSourceFileExt(void);
extern	int DBIdataSourceEngEval(void);
extern	int DBIdataSourceQSwitch(void);
extern	int DBIdataSourceSelSort(void);
extern	BOOL DBIisSystemTable (char* szPtr);
extern  LPSTR DBIdataSourceProcVerb(void);
#endif

#endif	// ifdef RSW
// ieng-+dbi;
#endif
