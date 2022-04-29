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
// $Log:   H:/VCSMFC/H/ENG.H_V  $
// 
//    Rev 1.3   06 Jun 1996 14:21:14   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.2   19 Jul 1995 10:25:14   jpb
// move to doc class
// 
//    Rev 1.1   26 Apr 1995 13:16:54   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.0   16 Mar 1995 16:12:34   sbc
// Initial revision.
// 
//    Rev 1.19   03 Apr 1995 15:56:08   dlm
// Added prototypes for sql_datetime_str and sql_time_str.
// 
//    Rev 1.18   01 Feb 1995 17:38:46   jpb
// Fix bad edit
// 
//    Rev 1.17   01 Feb 1995 17:29:42   jpb
// fix a typo
// 
//    Rev 1.16   01 Feb 1995 17:17:30   jpb
// add vars for new [Database] section settings
// 
//    Rev 1.15   29 Dec 1994 08:56:02   dlm
// Part of fix to RSW bug 1598.  Q+E seems to write a null beyond 512 bytes
//  into supplied error message buffer, so we're allowing 600 bytes instead.
//  Changes to eng.h, dbi.c, editrel.c, grfile.c, iengflds.c, sgrjoin.c,
//  wnextjob.c.
// 
//    Rev 1.14   16 Dec 1994 15:26:36   dlm
// Added prototype for sql_prep_tablename_for_dict().
// 
//    Rev 1.13   02 Dec 1994 15:10:26   smh
// Added argument to sql_tables so can pass on file new type status
// so know when to put no master check box on dialog.
// 
//    Rev 1.12   02 Nov 1994 20:51:28   sjo
// Making changes to support joining across directories and Data Sources for
// the 'Desktop' platforms.  Most changes are in DBI.C and iengmenu.c.  I also
// had to make changes to the 4 routines which called sql_tables and added 
// support for a new INI file setting.  Also added a new MFFiles structure
// member.
// 
// 
// 
//    Rev 1.11   03 Feb 1994 11:22:10   say
// add arg to sql_data_source_dialog
// 
//    Rev 1.10   17 Jan 1994 18:07:20   say
// change TABLE_ return values to match old true/false return values
// 
//    Rev 1.9   17 Dec 1993 16:58:48   say
// Add arge to sql_data_source_dialog to determine whether to set active source
// on success
// 
//    Rev 1.8   10 Dec 1993 16:06:20   say
// Add arg to sql_current_connection_dialog
// 
//    Rev 1.7   08 Dec 1993 10:29:08   say
// fix typo
// 
//    Rev 1.6   08 Dec 1993 08:47:06   say
// Add sql_set/get_max_rows prototypes for Jim
// 
//    Rev 1.5   07 Dec 1993 16:54:14   say
// Remove a bunch of obsolete functions, add a couple for ODBC
// 
//    Rev 1.4   19 Nov 1993 17:39:02   sbc
// Add extern C for C++
// 
//    Rev 1.3   02 Nov 1993 11:14:18   say
// move length #defines to global.h to remove unnecessary dependencies
// in wmain.h
// 
//    Rev 1.2   02 Nov 1993 09:08:54   say
// Remove comman from end of sql_replace_params parameter list
// 
//    Rev 1.1   26 Oct 1993 14:36:02   smh
// Always #undef GLOBAL.
// 
//    Rev 1.0   14 Oct 1993 10:11:20   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _ENG_H_

//
// Make a definition for this module.
//
#define _ENG_H_

#include "mffield.h"

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
	// from sql.h
#define vNONE		255		// max char
#define vXDB		0		/* XDB */
#define vNOVELL		1		/* Novell */
#define vORACLE		2		/* Oracle */
#define vGUPTA		3		/* Gupta */
#define vDBASE		4		/* dBASE */
#define vPACE		5		/* Wang's Pace */
#define vSQLSERVER	6		/* MicroSoft SQL Server */
#define vBTRIEVE		7
#define vASCII			8

// WARNING - I didn't bring WINPATHLEN from sql.h cuz defined in product.h
// & I didn't #ifndef PATHLENGTH cuz only found it in sql.h
#define USERSQLSIZE 10240 // max length of user-entered select statement
/* misc parameters */
#define SQL_MAX_ERR	600	+ 12	/* max lgt of vendor err txt (was 512+12 but QE overflowed buffer!) */
							/* (does not include trailing null) */
						// 12 needed for strlen(WxDBmsgIntro)

// The following are from the old PACEDEFS.H header
// and only pertain to the PACE Report Builder version of RSW

/* the max. length of a name (for a field or table, etc.) */
#define  MAX_NAME_LEN      32
/* an entity has a name with given max length */
typedef  char    PACE_NAME[MAX_NAME_LEN+1];

#define QIDIGITS        0x07    /* Number used as identifier    */
#define QICODED         0x12    /*                              */
// End of definitions from the old PACEDEFS.H header


//
// Structure Section:
// Place in this section any structure definitions.
//


// results for sql_tables

#define TABLE_FAILURE	0
#define TABLE_SUCCESS	1 // NOTE: some old code relies on this being 1
#define TABLE_NONEFOUND	2



#if 0	// remove globals and prototypes.
//
// Global Data Section:
// Place in this section any global data.
//
#ifdef _IENGFLDS_C_
    #define GLOBAL
#else
    #define GLOBAL extern
#endif

GLOBAL	BOOL AlwaysSelect;
GLOBAL	BOOL AlwaysLocalLog;
GLOBAL	int AsciiEditor;
GLOBAL	int CharRaw;
GLOBAL	char near Sql_Blank
#ifdef _IENGFLDS_C_
= '^'           	                // space substitution - default for Novell
#endif
;
GLOBAL	long QueryTimeout;

GLOBAL    int ModifySelect       	// should be TRUE if we modify the select statement
#ifdef _IENGFLDS_C_         		// to achieve case-insensitivity.  TRUE for Novell,
 = TRUE                             // Oracle, and SQL Server.  Was FALSE for DOS-based
#endif                              // XDB product.	Defined here because it's platform-
;                                   //  dependent.
        							//  Used in mfsql.c, sxselect.c and sxvalue.c */

#undef GLOBAL


//
// Function Prototypes Section:
// Place in this section any function prototypes
//



extern	int sql_check(char FAR *select,char FAR *msg);
extern	void sql_date_str(long date,char FAR *s);
extern	void sql_datetime_str(long date, double time, unsigned char FAR *s);
extern	void sql_time_str(double time,unsigned char FAR *s);
extern  PSTR sql_dbtypename(LPMFFIELD fld);
extern	int sql_exec(char FAR *query,char FAR *outmsgbuf,int iIgnoreFlds,int iRandom);
extern	void sql_exit(void);
extern int sql_expinfo(LPSTR exp,LPMFFIELD fld,int action,int disperr);
extern void sql_finish(LPMFFIELD f);
extern BOOL sql_fld_data(void);
extern	void sql_fld_header(struct mffield FAR *f,char FAR *s);
extern	char *sql_get_DLL_version(void);
extern  int sql_random_rec(long recno);
extern  char *sql_get_schema(void);
extern  int sql_tables (HWND hParent, LPSTR lpszTable, int whereFrom, LPSTR lpszDS,int *DSIndex,int bCustomDlg);
extern  int sql_no_tables();
extern  BOOL sql_set_current_schema(LPSTR lpszSchema);
extern int sql_next_rec(void);
extern LPSTR sql_prep_tablename_for_dict (LPSTR lpszNameIn, LPSTR lpszNameOut);
extern LPSTR sql_replace_params (LPSTR lpszSelect,LPSTR lpszParamList);
extern int sql_start(char fileno,LPSTR lpszSelect,LPSTR lpszParamString,LPSTR FAR *names,BOOL bFromReadrep,LPSTR lpszEBuf);
extern void sql_reset(void);
extern void sql_restart(void);
extern void sql_set_max_rows(unsigned long rc);
extern unsigned long sql_get_max_rows(void);

// ODBC stuff
extern BOOL sql_data_source_dialog(BOOL bSelect, int FAR *iDataSources);
extern BOOL sql_current_connection_dialog(BOOL bSelect);


#if !defined (INTERACTIVE) // all DBI routines should really be private to the SQL layer
extern	char *DBIgetDatabase(void);
extern	char *DBIgetPassword(void);
extern	char *DBIgetUserID(void);
extern	char *DBIgetDataDir(void);
#endif
#endif	// remove globals and prototypes



#endif // end _ENG_H_

// *************************** End of File ************************************
