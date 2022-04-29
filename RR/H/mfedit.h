// ****************************************************************************
//
//      (C) Copyright 2001 Liveware Publishing Inc.
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
// $Log:   D:/R&R Project/archives/H/MFEDIT.H_V  $
// 
//    Rev 1.6   Apr 25 2002 10:10:48   Admin
// Scope fields
// 
//    Rev 1.5   Dec 05 2000 13:01:00   nhubacker
// Add members to pkrel structure for user indexes
// 
//    Rev 1.4   Aug 31 2000 13:48:42   nhubacker
// Support for non-DBC files in relation
// 
//    Rev 1.3   06 Jun 1996 14:21:22   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.2   07 Jul 1995 18:11:44   jpb
// First pass at moving all data and functions to CRrDoc class
// 
//    Rev 1.1   26 Apr 1995 10:53:18   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.0   16 Mar 1995 16:12:54   sbc
// Initial revision.
// 
//    Rev 1.5   04 Apr 1995 15:42:40   jpb
// add some externs
// 
//    Rev 1.4   02 Nov 1994 20:51:04   sjo
// Making changes to support joining across directories and Data Sources for
// the 'Desktop' platforms.  Most changes are in DBI.C and iengmenu.c.  I also
// had to make changes to the 4 routines which called sql_tables and added 
// support for a new INI file setting.  Also added a new MFFiles structure
// member.
// 
// 
// 
//    Rev 1.3   28 Sep 1994 15:46:50   sbc
// FileOpenName -> Paths
// 
//    Rev 1.2   19 Nov 1993 17:44:34   sbc
// Add extern C for C++
// 
//    Rev 1.1   29 Oct 1993 16:33:46   jpb
// Clean up sources to remove compiler warnings
// 
//    Rev 1.0   14 Oct 1993 10:12:16   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _MFEDIT_H_

//
// Make a definition for this module.
//
#define _MFEDIT_H_

#include "mffield.h"
#include "util.h"		/* for ZDATETIME */

#if defined (_EDITMAST_C_)
 #define GLOBAL
#else
 #define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

//
// Structure Section:
// Place in this section any structure definitions.
//
#ifdef RSW
typedef struct joinpair
{
	MFFIELD		far *lfld;
	char		*rfld;
	char		flags;
} JOINPAIR;

// bits in JOINPAIR.flags
#define jfDUMMY 0x1
#endif

typedef struct pkrel			// setrel packet
{
#ifdef RSW
	JOINPAIR	*joinspec;
#else
	MFFIELD		far *lfld;	// linking field
#endif
	char		*relfile;	// related file pathname
#ifndef RSW
	unsigned int	partlen; // 0=>full, else partial match len
#endif
	char		reltype;	// xBase: 0=>exact, 1=>approx, 2=>scan
							// SQL:	  0=>join,  1=>himatch,2=>lomatch
#ifdef RSW
	int			relatedDSIndex;
#endif

#ifndef RSW
	char		*ndxname;	// NULL=>recno link, else ndx file pathname
	char		*tag;		// ptr to tag name (or null str)
	int			userIndex;	// true if a user index
	char		*indexExpression ; // if user index
#else
	char		*ndxname;	// NULL=>recno link, else ndx file pathname
	char		*indexExpression ; // if user index
#endif

	char		failcode;	// xBase:	0=>blank, 1=>skip, 2=>terminate
							// SQL:		0=>blank initial, 1=>skip, 2=>blank related
	char		*alias;		// related file alias
	int			status;		// to identify bad packet info (see below)
	int			bDBCMode ;	// true if from a Visual FoxPro DBC
	int			fileno ;
	LPMFFILE	efile ;
} PKREL;

typedef struct pkgroup		// setgroup packet
{
	int			terminate;	// FALSE=>continue; else=>terminate
	char		alias[MFMAXFILES-1][MAXALIAS];	// related file aliases
} PKGROUP;

typedef struct pkmast		// master db info packet
{
	int			status;		// see status description below
	char		*data;		// ptr to master db file pathname
	char		*alias;		// ptr to master db file alias
#ifdef RSW
	LPSTR		select;		// user select statement
#else
	char		*index;		// ptr to master index file pathname (or null str)
	char		*loscope;	// ptr to starting scope string
	char		*hiscope;	// ptr to ending scope string
	LPMFFIELD	loscopefld;
	LPMFFIELD   hiscopefld;
	char		*tag;		// ptr to tag name (or null str)
	int			ndxtype;	// see flag bits below
	int			typechoice;	// see flag bits below
#endif
} PKMAST;

typedef struct pkascii		// ascii memo file info packet
{
	char		*name;		// ptr to ascii file pathname
	char		*alias;		// ptr to ascii file alias
	int			status;		// on TRUE ret from editasciiprep, tells error piece
	char		charset;	// character set: 0 -> DOS (PC), 1 -> ANSI (Windows)
} PKASCII;


//
// Global Data Section:
// Place in this section any global data.
//




//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#if 0
extern	void delgo(void );
extern	int delprep(int flnum,int *cntP);
extern	void editasciigo(struct pkascii *asciip);
extern	int editasciiprep(struct pkascii *asciip,int *cntP);
extern	void editasciiquit(void);
extern	int editgo(struct pkrel *relp);
extern	int editmastgo(struct pkmast *mastp);
extern	int editmastprep(struct pkmast *mastp);
extern	void editmastquit(void );
extern	int editprep(struct pkrel *relp,int flnum,int *cntP);
extern	void editquit(void );
extern	int fileline(int flnum,char *st);
extern	int filetext(int flnum,char *st);
extern	void getascii(struct pkascii *asciip);
extern	BOOL getDateTimeValue(LPSTR in, ZDATETIME *dt, BOOL lo);
extern	int getjoincount(int flnum);
extern	void getmast(struct pkmast *mastp);
extern	int getrel(struct pkrel *relp,int flnum);
extern	int indexinfo(LPSTR name, char *tag, int *typeP, int *needtagP);
extern	void initscopes(void);
extern	int laliasline(char FAR *alias);
extern	struct mffile FAR *lfilen(int n);
extern	void lmfdelcan(struct udf FAR *xudf);
extern	int lmfedcon(char FAR *partial,struct mffield FAR *xcf,struct udf FAR *xudf);
extern	int mfdelcon(char *partial);
extern	void putdatetime(int hi, ZDATETIME *dt);
#if !defined RSW
extern char *scopestr(int hisc);
#endif
extern	int select_mode(void );
extern	int setrel(struct pkrel *relp);
extern	int setscstr(char *buf,int hisc);
extern	int getgroup(int flnum,PKGROUP far *groupp);
extern	int ingroup(int flnum);
extern	int setgroup(int *flnump,PKGROUP far *groupp);
#endif


#undef GLOBAL

#endif // end _MFEDIT_H_

// *************************** End of File ************************************

