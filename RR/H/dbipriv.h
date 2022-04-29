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
// Private header file for database independence layer
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/DBIPRIV.H_V  $
// 
//    Rev 1.22   May 03 2004 16:33:06   Nick
// Add Progress DBMS
// 
//    Rev 1.21   30 Nov 1998 10:39:56   wrr
// 
// 
//    Rev 1.20.2.0   13 Oct 1998 15:42:14   jpb
// WRR change for 156383
// 
//    Rev 1.21.1.0   17 Sep 1998 13:03:50   wrr
// No change.
// 
//    Rev 1.21   31 Aug 1998 14:58:00   jpb
// add storage for default DS for fix to WO159630 (modified port of TMP
//  for WR 156383
// 
//    Rev 1.20   16 Jan 1998 15:36:56   JSF
// PTF 20001 merge
// 
//    Rev 1.19.1.0   23 Oct 1997 14:10:12   jsf
// addes sqlext.h for vc50
// 
//    Rev 1.19   24 Jun 1997 16:19:58   jpb
// WO 130059 - AlwaysPreFetch setting
// 
//    Rev 1.18   10 Feb 1997 10:02:18   sp
// Arp Live merge to trunk
// 
//    Rev 1.15.1.0   18 Oct 1996 08:32:04   jpb
//    Rev 1.16   17 Oct 1996 18:24:24   jpb
// Removed auto ds create from AL branch.
// 
//    Rev 1.15   08 Oct 1996 16:49:48   amh
// Arp 1.0 U02 merged to trunk
// 
// 
//      H:\VCSMFC\H\DBIPRIV.H_V  Rev "ARP 1.0 U02" (1.12.1.0)
// 
//    Rev 1.12.1.0   01 Jul 1996 16:20:24   jpb
// fix RSW 1859 (max char literal len)
//     H:\VCSMFC\H\DBIPRIV.H_V  Rev 1.14
// 
//    Rev 1.14   07 Oct 1996 15:14:02   jpb
// change some datasource connect string member names - now do ODBC connect
// 
//    Rev 1.13   03 Jul 1996 15:44:28   jpb
// merge 1.13.1.0 to trunk (rsw 1859)
// 
//    Rev 1.12.1.0   01 Jul 1996 16:20:24   jpb
// fix RSW 1859 (max char literal len)
// 
//    Rev 1.12   03 May 1996 16:26:46   jpb
// support ListSystemTables
// 
//    Rev 1.11   29 Apr 1996 18:25:40   jpb
// add flags etc for PassExec
// 
//    Rev 1.10   23 Apr 1996 16:12:22   jpb
// Get Qualfier-Name-Separator string 
// 
//    Rev 1.9   28 Feb 1996 19:02:02   jpb
// add JetDBFilter support
// 
//    Rev 1.8   21 Feb 1996 18:08:54   jpb
// use c linkage for qeOEMSetLicenseInfo
// 
//    Rev 1.7   28 Nov 1995 09:08:54   jpb
// rename a manifest constant
// 
//    Rev 1.6   22 Sep 1995 15:44:38   jpb
// add qeOEMSetLicenseInfo prototype (missing from QELIB.H 2.0.3)
// 
//    Rev 1.5   03 Aug 1995 09:39:40   jpb
// Fix part of rsw 1882
// 
//    Rev 1.4   19 Jul 1995 10:25:18   jpb
// move to doc class
// 
//    Rev 1.3   17 Jul 1995 14:43:56   jpb
// Fix RSW 1801
// 
//    Rev 1.2   30 Jun 1995 16:23:24   jpb
// merge rrwin tree rev 1.22
// 
//    Rev 1.1   26 Apr 1995 13:16:30   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.0   16 Mar 1995 16:12:24   sbc
// Initial revision.
// 
//    Rev 1.21   12 Apr 1995 11:33:46   jpb
// add member for data source dbms version string
// 
//    Rev 1.20   22 Feb 1995 14:22:06   jpb
// add flag bits and handlers for DBAnsi
// 
//    Rev 1.19   16 Feb 1995 18:00:36   jpb
// add support for DSLikeWithExpresssion
// 
//    Rev 1.18   16 Dec 1994 18:35:44   sjo
// Fix RSW crock 1553. Problem with disconnecting DS that are needed for tasks
//  like report spec and report save.
// 
// 
//    Rev 1.15.1.1   16 Dec 1994 14:22:52   jpb
// add bits/macros for ModifySelect, DOSFile, DirPrefix
// 
//    Rev 1.17   16 Dec 1994 14:17:12   jpb
// add flag bits and macros for ModifySelect, DOSFile, and DirPrefix state
// 
//    Rev 1.16   16 Dec 1994 09:18:10   sjo
// Fixes RSW crock #1532. Added Excel, Text and Access to the list file types
// that we support when selecting a directory. See also dbi.c and rrw.str.
// 
//    Rev 1.15   28 Nov 1994 15:31:48   jpb
// fix rsw 1122
// 
//    Rev 1.14   17 Nov 1994 17:13:42   jpb
// add stuff for MaxRows support (for Notes)
// 
//    Rev 1.13   10 Nov 1994 17:15:02   jpb
// get rid of separator string member
// 
//    Rev 1.12   03 Nov 1994 09:21:08   sjo
// Making changes to support joining across directories and Data Sources for
// the 'Desktop' platforms.  Most changes are in DBI.C and iengmenu.c.  I also
// had to make changes to the 4 routines which called sql_tables and added 
// support for a new INI file setting.  Also added a new MFFiles structure
// member.
// 
// 
// 
//    Rev 1.11   02 Nov 1994 09:56:38   jpb
// changed DATASOURCE structure for new way of connecting to driver/dbms-
// specific section of RSWSQL.INI.  Also changed dbi.c and rswsql.ini
// 
//    Rev 1.10   27 Sep 1994 18:10:46   jpb
// add definitions for FileExt stuff (to control removal of extensions)
// 
//    Rev 1.9   14 Sep 1994 14:16:16   jpb
// save connect string used to connect
// 
//    Rev 1.8   13 Sep 1994 17:14:20   jpb
// add connect string member to data source structure
// 
//    Rev 1.7   09 Sep 1994 17:23:26   jpb
// add datasource flag bits for uses "owners" and "databases"
// 
//    Rev 1.6   06 Jan 1994 16:41:34   say
// treat paradox files as file-based
// 
//    Rev 1.5   20 Dec 1993 17:57:08   jpb
// add other ODBC status to DS structure and make macros to manipulate
// 
//    Rev 1.4   09 Dec 1993 15:28:28   say
// Add stuff to store DBMS names in DATASOURCE structure
// 
//    Rev 1.3   07 Dec 1993 16:49:46   say
// Massive changes for ODBC
// 
//    Rev 1.2   23 Nov 1993 13:43:50   jpb
// Fix unmatched #ifdef/#endif
// 
//    Rev 1.1   19 Nov 1993 17:43:38   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:12:52   erp
// Initial revision.
//
// 05/25/93 ERP - Fixed case on dBase to dBASE.
//
// ****************************************************************************
//
// Make a definition for this module.
//
#ifndef _DBIPRIV_H_
#define _DBIPRIV_H_

#include "qelib.h"

#include "sql.h"	// for SQL_MAX_DSN_LENGTH
#include "sqlext.h"	// for SQL_MAX_DSN_LENGTH, now here with VC 5.0
#include "dbi.h"	// for MAX_QUOTE_CHAR_LEN and MAX_SEPARATOR_LEN and

// following prototype was left out of QELIB.H from version 2.0.3:
extern "C" {
qeAPI(qeSTATUS) qeOEMSetLicenseInfo (
    qeLPSTR         filename,
    qeLPSTR         password);
}


/**************************** Dialog IDs *********************************/
// Table List Dialog ID
#define IDD_LISTBOX                 901

// Platform List Dialog ID
#define IDD_PLATLISTBOX            1001

/**************************** Data Source "Class" ***************************/
#define MAX_INI_DBMS_LENGTH		80
#define MAX_DRIVER_LENGTH		20
#define MAX_DATABASE_NAME_LENGTH WINPATHLEN
#define MAX_DBMS_VERSION_LENGTH	20
#define MAX_PROC_VERB_LENGTH	20
#define MAX_DRIVER_DESCRIPTION_LENGTH 80
#define DSARRAYSIZE				100

typedef struct DataSource {
	char szName[SQL_MAX_DSN_LENGTH+1];
	char szDriverDBMSName[SQL_MAX_DSN_LENGTH+1];
	char szDriverDBMSVersion[MAX_DBMS_VERSION_LENGTH+1];
	char szIniDBMSName[MAX_INI_DBMS_LENGTH+1];
	char szDriverName[MAX_DRIVER_LENGTH+1];
	char szDefaultDatabase[MAX_DATABASE_NAME_LENGTH+1];
	
	// sp 2/5/97 merge was qeConnectString and qeConnectExtraString
	char szConnectString[MAX_CONNECT_STRING+1]; // string for qeConnect()
	char szConnectExtraString[MAX_CONNECT_STRING+1]; // connect string addendum

	char szProcVerb[MAX_PROC_VERB_LENGTH+1];        // stored procedure verb
	char szDriverDescription[MAX_DRIVER_DESCRIPTION_LENGTH+1];
	qeHANDLE qeHdbc;		// Q+E connection handle
	qeHANDLE qeHstmt;		// Q+E statement handle
	HDBC odbcHdbc;			// ODBC connection handle
	HENV odbcHenv;			// ODBC environment handle
	HSTMT odbcHstmt;		// ODBC statement handle
	LONG lFlags;			// see lFlags definitions, below
	LONG lFlags2;			// see lFlags2 definitions, below
	LONG lMaxCharLiteralLen;	// for xeval translation of string literals
	char szQuoteCharString[MAX_QUOTE_CHAR_LEN+1];	// name quote delimiter
	char szSeparatorString[MAX_SEPARATOR_LEN+1];	// like "\" or "."
} DATASOURCE;

typedef struct NotActiveDataSource {
	char szName[SQL_MAX_DSN_LENGTH+1];
	char szDirectory[WINPATHLEN+1];	//
} NADATASOURCE; 

// lFlags definitions
#define DBMS_TYPEFLAGS	0x600000FFL	// mask for data source flags
#define DBMS_DBASE		0x0001
#define DBMS_NETWARESQL	0x0002
#define DBMS_SQLSERVER	0x0004
#define DBMS_BTRIEVE	0x0008
#define DBMS_ORACLE		0x0010
#define DBMS_PARADOX	0x0020
#define DBMS_EXCEL		0x0040
#define DBMS_ACCESS		0x0080
#define DBMS_TEXT		0x20000000L
#define DBMS_PROGRESS	0x40000000L

// values store in DBMS_OJMASK bits are defined in DBI (DBI_OJ_xxx)
#define DBMS_OJMASK		0x0700	// 3 bits for oj style in rswsql.ini setting
#define DBMS_OJSHIFT	8		// # of trailing OJMASK 0 bits (for shift)

#define DBMS_ODBCOJ		0x0800	// source supports ODBC outer join syntax

#define DBMS_NAMECASEMASK	0x3000	// 2 bits for id case code
#define DBMS_NAMECASESHIFT	12		// # of trailing NAMECASE 0 bits (for shift)

// these are the values stored in the DBMS_NAMECASEMASK bits
// note they are the ODBC/QE case values minus 1, to start with 0
#define DBMS_NAMEUPPER		0	// names must be upper case
#define DBMS_NAMELOWER		1	// must be lower case
#define DBMS_NAMESENSE		2	// case sensitive
#define DBMS_NAMEINSENSE	3	// case insensitive

#define DBMS_EXPRORDER	0x4000	// expressions allowed in ORDER BY
#define DBMS_QUALCOLS	0x8000	// always qualify column list
#define DBMS_USEALIAS	0x00010000L	// always use table alias
#define DBMS_QUALSORTS	0x00020000L	// always qualify sort list
#define DBMS_ADDFALSE	0x00040000L	// add where false
#define DBMS_ENGEVAL	0x00080000L	// always engine eval
#define DBMS_QSWITCH	0x00100000L	// old RN/RX style q switch for NULLs
#define DBMS_OWNERS		0x00200000L	// source uses owners
#define DBMS_DATABASES	0x00400000L	// source uses databases
#define DBMS_USEFILEEXT	0x00800000L	// keep desktop file extension
#define DBMS_MAXROWS	0x01000000L	// DS supports SetStmtOpt for MaxRows
#define DBMS_APPROX		0x02000000L	// DS supports R&R x join subquery
#define DBMS_MODIFYSEL	0x04000000L	// DS needs ModifySelect set for case
#define DBMS_DIRPREFIX	0x08000000L	// DS table names have pathname prefix
#define DBMS_DOSFILE	0x10000000L	// DS table names are DOS filenames 
#define DBMS_EXPRLIKE	0x20000000L	// DS can use LIKE with expressions
#define DBMS_INUSE		0x40000000L // DS is being used in the report-dont allow disconnect
#define DBMS_DBANSI		0x80000000L // DS returns character data in ANSI

// lFlags2 definitions
#define DBMS_SELSORT	0x01L		// DS requires sort fields be in select list
#define DBMS_JETFILTER	0x02L		// DS needs excel/access jet32 db filter workaround
#define DBMS_PASSEXEC	0x04L		// Pass initial EXEC for stored procs thru
#define DBMS_LISTSYSTABS 0x08L		// List system tables
#define DBMS_PREFETCH	0x10L		// Always prefetch (WO130059 kludge)


#define szDBASE			"dBASE"
#define szNetWareSQL	"NetWare SQL"
#define szSQLServer		"SQL Server"
#define szBtrieve		"Btrieve"
#define szOracle		"Oracle"
#define szParadox		"Paradox"
#define szExcel			"Excel"
#define szTheTextWord	"Text"
#define szAccess		"Access"
#define szProgress		"Progress"

// These macros use lFlags flags
#define DSPTR_IS_DBASE(DS)		((DS)->lFlags & DBMS_DBASE)
#define DSPTR_IS_NETWARESQL(DS) ((DS)->lFlags & DBMS_NETWARESQL)
#define DSPTR_IS_SQLSERVER(DS)	((DS)->lFlags & DBMS_SQLSERVER)
#define DSPTR_IS_BTRIEVE(DS)	((DS)->lFlags & DBMS_BTRIEVE)
#define DSPTR_IS_ORACLE(DS)		((DS)->lFlags & DBMS_ORACLE)
#define DSPTR_IS_PARADOX(DS)	((DS)->lFlags & DBMS_PARADOX)
#define DSPTR_IS_EXCEL(DS)		((DS)->lFlags & DBMS_EXCEL)
#define DSPTR_IS_TEXT(DS)		((DS)->lFlags & DBMS_TEXT)
#define DSPTR_IS_ACCESS(DS)		((DS)->lFlags & DBMS_ACCESS)
#define DSPTR_IS_PROGRESS(DS)	((DS)->lFlags & DBMS_PROGRESS)

#define DSPTR_SET_DBASE(DS)		{(DS)->lFlags &= ~(long)DBMS_TYPEFLAGS;(DS)->lFlags |= DBMS_DBASE;}
#define DSPTR_SET_NETWARESQL(DS) {(DS)->lFlags &= ~(long)DBMS_TYPEFLAGS;(DS)->lFlags |= DBMS_NETWARESQL;}
#define DSPTR_SET_SQLSERVER(DS)	{(DS)->lFlags &= ~(long)DBMS_TYPEFLAGS;(DS)->lFlags |= DBMS_SQLSERVER;}
#define DSPTR_SET_BTRIEVE(DS)	{(DS)->lFlags &= ~(long)DBMS_TYPEFLAGS;(DS)->lFlags |= DBMS_BTRIEVE;}
#define DSPTR_SET_ORACLE(DS)	{(DS)->lFlags &= ~(long)DBMS_TYPEFLAGS;(DS)->lFlags |= DBMS_ORACLE;}
#define DSPTR_SET_PARADOX(DS)	{(DS)->lFlags &= ~(long)DBMS_TYPEFLAGS;(DS)->lFlags |= DBMS_PARADOX;}
#define DSPTR_SET_EXCEL(DS)		{(DS)->lFlags &= ~(long)DBMS_TYPEFLAGS;(DS)->lFlags |= DBMS_EXCEL;}
#define DSPTR_SET_TEXT(DS)		{(DS)->lFlags &= ~(long)DBMS_TYPEFLAGS;(DS)->lFlags |= DBMS_TEXT;}
#define DSPTR_SET_ACCESS(DS)	{(DS)->lFlags &= ~(long)DBMS_TYPEFLAGS;(DS)->lFlags |= DBMS_ACCESS;}
#define DSPTR_SET_PROGRESS(DS)	{(DS)->lFlags &= ~(long)DBMS_TYPEFLAGS;(DS)->lFlags |= DBMS_PROGRESS;}

#define DSPTR_SET_OJ(DS,OJ)		{(DS)->lFlags &= ~(long)DBMS_OJMASK;\
									(DS)->lFlags |= (OJ << DBMS_OJSHIFT);}
#define DSPTR_OJ(DS)			(int)(((DS)->lFlags & DBMS_OJMASK) >> DBMS_OJSHIFT)

#define DSPTR_CLR_ODBCOJ(DS)	(DS)->lFlags &= ~(long)DBMS_ODBCOJ;
#define DSPTR_SET_ODBCOJ(DS)	{(DS)->lFlags &= ~(long)DBMS_ODBCOJ;\
									(DS)->lFlags |= DBMS_ODBCOJ;}
#define DSPTR_ODBCOJ(DS)		((DS)->lFlags & DBMS_ODBCOJ)

#define DSPTR_SET_NAMECASE(DS,C) {(DS)->lFlags &= ~(long)DBMS_NAMECASEMASK;\
									(DS)->lFlags |= (C << DBMS_NAMECASESHIFT);}
#define DSPTR_NAMECASE(DS)		(int)(((DS)->lFlags & DBMS_NAMECASEMASK) >> DBMS_NAMECASESHIFT)

#define DSPTR_CLR_EXPRORDER(DS) (DS)->lFlags &= ~(long)DBMS_EXPRORDER;
#define DSPTR_SET_EXPRORDER(DS)	{(DS)->lFlags &= ~(long)DBMS_EXPRORDER;\
										(DS)->lFlags |= DBMS_EXPRORDER;}
#define DSPTR_EXPRORDER(DS)			(((DS)->lFlags & DBMS_EXPRORDER)!=0L)

#define DSPTR_CLR_OWNERS(DS)	(DS)->lFlags &= ~(long)DBMS_OWNERS;
#define DSPTR_SET_OWNERS(DS)	{(DS)->lFlags &= ~(long)DBMS_OWNERS;\
									(DS)->lFlags |= DBMS_OWNERS;}
#define DSPTR_OWNERS(DS)		(((DS)->lFlags & DBMS_OWNERS)!=0L)

#define DSPTR_CLR_DATABASES(DS)	(DS)->lFlags &= ~(long)DBMS_DATABASES;
#define DSPTR_SET_DATABASES(DS)	{(DS)->lFlags &= ~(long)DBMS_DATABASES;\
									(DS)->lFlags |= DBMS_DATABASES;}
#define DSPTR_DATABASES(DS)		(((DS)->lFlags & DBMS_DATABASES)!=0L)

#define DSPTR_CLR_USEFILEEXT(DS) (DS)->lFlags &= ~(long)DBMS_USEFILEEXT;
#define DSPTR_SET_USEFILEEXT(DS) {(DS)->lFlags &= ~(long)DBMS_USEFILEEXT;\
									(DS)->lFlags |= DBMS_USEFILEEXT;}
#define DSPTR_USEFILEEXT(DS)	(((DS)->lFlags & DBMS_USEFILEEXT)!=0L)

#define DSPTR_CLR_QUALCOLS(DS)	(DS)->lFlags &= ~(long)DBMS_QUALCOLS;
#define DSPTR_SET_QUALCOLS(DS)	{(DS)->lFlags &= ~(long)DBMS_QUALCOLS;\
									(DS)->lFlags |= DBMS_QUALCOLS;}
#define DSPTR_QUALCOLS(DS)		(((DS)->lFlags & DBMS_QUALCOLS)!=0L)

#define DSPTR_CLR_USEALIAS(DS) (DS)->lFlags &= ~(long)DBMS_USEALIAS;
#define DSPTR_SET_USEALIAS(DS) {(DS)->lFlags &= ~(long)DBMS_USEALIAS;\
									(DS)->lFlags |= DBMS_USEALIAS;}
#define DSPTR_USEALIAS(DS)		(((DS)->lFlags & DBMS_USEALIAS)!=0L)

#define DSPTR_CLR_QUALSORTS(DS) (DS)->lFlags &= ~(long)DBMS_QUALSORTS;
#define DSPTR_SET_QUALSORTS(DS) {(DS)->lFlags &= ~(long)DBMS_QUALSORTS;\
									(DS)->lFlags |= DBMS_QUALSORTS;}
#define DSPTR_QUALSORTS(DS)		(((DS)->lFlags & DBMS_QUALSORTS)!=0L)

#define DSPTR_CLR_ADDFALSE(DS)	(DS)->lFlags &= ~(long)DBMS_ADDFALSE;
#define DSPTR_SET_ADDFALSE(DS)	{(DS)->lFlags &= ~(long)DBMS_ADDFALSE;\
									(DS)->lFlags |= DBMS_ADDFALSE;}
#define DSPTR_ADDFALSE(DS)		(((DS)->lFlags & DBMS_ADDFALSE)!=0L)

#define DSPTR_CLR_ENGEVAL(DS) (DS)->lFlags &= ~(long)DBMS_ENGEVAL;
#define DSPTR_SET_ENGEVAL(DS) {(DS)->lFlags &= ~(long)DBMS_ENGEVAL;\
							(DS)->lFlags |= DBMS_ENGEVAL;}
#define DSPTR_ENGEVAL(DS) (((DS)->lFlags & DBMS_ENGEVAL)!=0L)

#define DSPTR_CLR_QSWITCH(DS) (DS)->lFlags &= ~(long)DBMS_QSWITCH;
#define DSPTR_SET_QSWITCH(DS) {(DS)->lFlags &= ~(long)DBMS_QSWITCH;\
							(DS)->lFlags |= DBMS_QSWITCH;}
#define DSPTR_QSWITCH(DS) (((DS)->lFlags & DBMS_QSWITCH)!=0L)

#define DSPTR_CLR_MAXROWS(DS) (DS)->lFlags &= ~(long)DBMS_MAXROWS;
#define DSPTR_SET_MAXROWS(DS) {(DS)->lFlags &= ~(long)DBMS_MAXROWS;\
							(DS)->lFlags |= DBMS_MAXROWS;}
#define DSPTR_MAXROWS(DS) (((DS)->lFlags & DBMS_MAXROWS)!=0L)

#define DSPTR_CLR_APPROX(DS) (DS)->lFlags &= ~(long)DBMS_APPROX;
#define DSPTR_SET_APPROX(DS) {(DS)->lFlags &= ~(long)DBMS_APPROX;\
							(DS)->lFlags |= DBMS_APPROX;}
#define DSPTR_APPROX(DS) (((DS)->lFlags & DBMS_APPROX)!=0L)

#define DSPTR_CLR_DOSFILE(DS) (DS)->lFlags &= ~(long)DBMS_DOSFILE;
#define DSPTR_SET_DOSFILE(DS) {(DS)->lFlags &= ~(long)DBMS_DOSFILE;\
							(DS)->lFlags |= DBMS_DOSFILE;}
#define DSPTR_DOSFILE(DS) (((DS)->lFlags & DBMS_DOSFILE)!=0L)

#define DSPTR_CLR_DIRPREFIX(DS) (DS)->lFlags &= ~(long)DBMS_DIRPREFIX;
#define DSPTR_SET_DIRPREFIX(DS) {(DS)->lFlags &= ~(long)DBMS_DIRPREFIX;\
							(DS)->lFlags |= DBMS_DIRPREFIX;}
#define DSPTR_DIRPREFIX(DS) (((DS)->lFlags & DBMS_DIRPREFIX)!=0L)

#define DSPTR_CLR_MODIFYSEL(DS) (DS)->lFlags &= ~(long)DBMS_MODIFYSEL;
#define DSPTR_SET_MODIFYSEL(DS) {(DS)->lFlags &= ~(long)DBMS_MODIFYSEL;\
							(DS)->lFlags |= DBMS_MODIFYSEL;}
#define DSPTR_MODIFYSEL(DS) (((DS)->lFlags & DBMS_MODIFYSEL)!=0L)

#define DSPTR_CLR_EXPRLIKE(DS) (DS)->lFlags &= ~(long)DBMS_EXPRLIKE;
#define DSPTR_SET_EXPRLIKE(DS) {(DS)->lFlags &= ~(long)DBMS_EXPRLIKE;\
							(DS)->lFlags |= DBMS_EXPRLIKE;}
#define DSPTR_EXPRLIKE(DS) (((DS)->lFlags & DBMS_EXPRLIKE)!=0L)

#define DSPTR_CLR_DBANSI(DS) (DS)->lFlags &= ~(long)DBMS_DBANSI;
#define DSPTR_SET_DBANSI(DS) {(DS)->lFlags &= ~(long)DBMS_DBANSI;\
							(DS)->lFlags |= DBMS_DBANSI;}
#define DSPTR_DBANSI(DS) (((DS)->lFlags & DBMS_DBANSI)!=0L)

#define DSPTR_CLR_INUSE(DS) ((DS)->lFlags &= ~(long)DBMS_INUSE);
#define DSPTR_SET_INUSE(DS) ((DS)->lFlags |= DBMS_INUSE);

// These macros use lFlags2 flags
#define DSPTR_CLR_SELSORT(DS) (DS)->lFlags2 &= ~(long)DBMS_SELSORT;
#define DSPTR_SET_SELSORT(DS) {(DS)->lFlags2 &= ~(long)DBMS_SELSORT;\
							(DS)->lFlags2 |= DBMS_SELSORT;}
#define DSPTR_SELSORT(DS) (((DS)->lFlags2 & DBMS_SELSORT)!=0L)

#define DSPTR_CLR_JETFILTER(DS) (DS)->lFlags2 &= ~(long)DBMS_JETFILTER;
#define DSPTR_SET_JETFILTER(DS) {(DS)->lFlags2 &= ~(long)DBMS_JETFILTER;\
							(DS)->lFlags2 |= DBMS_JETFILTER;}
#define DSPTR_JETFILTER(DS) (((DS)->lFlags2 & DBMS_JETFILTER)!=0L)

#define DSPTR_CLR_PASSEXEC(DS) (DS)->lFlags2 &= ~(long)DBMS_PASSEXEC;
#define DSPTR_SET_PASSEXEC(DS) {(DS)->lFlags2 &= ~(long)DBMS_PASSEXEC;\
							(DS)->lFlags2 |= DBMS_PASSEXEC;}
#define DSPTR_PASSEXEC(DS) (((DS)->lFlags2 & DBMS_PASSEXEC)!=0L)

#define DSPTR_CLR_LISTSYSTABS(DS) (DS)->lFlags2 &= ~(long)DBMS_LISTSYSTABS;
#define DSPTR_SET_LISTSYSTABS(DS) {(DS)->lFlags2 &= ~(long)DBMS_LISTSYSTABS;\
							(DS)->lFlags2 |= DBMS_LISTSYSTABS;}
#define DSPTR_LISTSYSTABS(DS) (((DS)->lFlags2 & DBMS_LISTSYSTABS)!=0L)

#define DSPTR_CLR_PREFETCH(DS) (DS)->lFlags2 &= ~(long)DBMS_PREFETCH;
#define DSPTR_SET_PREFETCH(DS) {(DS)->lFlags2 &= ~(long)DBMS_PREFETCH;\
							(DS)->lFlags2 |= DBMS_PREFETCH;}
#define DSPTR_PREFETCH(DS) (((DS)->lFlags2 & DBMS_PREFETCH)!=0L)

#endif
