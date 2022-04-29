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
//	Global structures and macros that can go into the precompiled header.
// Global variables will remain in GLOBAL.H for now.
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/H/GLOBALS.H_V  $
// 
//    Rev 1.5   Sep 14 2000 10:00:16   nhubacker
// Add a path for Report Librarian
// 
//    Rev 1.4   08 Feb 1996 17:40:56   dlm
// Moved LinkPath to stop excluding it in runtime DLL.
// 
//    Rev 1.3   29 Dec 1995 13:56:56   dlm
// Added conditionals to allow use in runtime DLLs.
// 
//    Rev 1.2   04 Oct 1995 10:00:12   smh
// Created PANE1_LEN, constant for m_Pane1Text length.
// 
//    Rev 1.1   17 Sep 1995 17:54:40   par
// DIRRTN needed to be modified to point to static functions.
// 
//    Rev 1.0   18 Aug 1995 16:02:50   mjs
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _GLOBALS_H_
//
// Make a definition for this module.
//
#define _GLOBALS_H_


//	From wmain.h, needed in rrdoc.h

// directory routine pointer
class CRrDoc ;
typedef LPSTR (*DIRRTN)(CRrDoc*,LPSTR);
#define SERVERNAMELEN   32 // max length of name of server

// From cfedit.h, needed by rrdoc.h

typedef struct pkcalc	/* calc/udf/query info packet */
{
	char type;		/* see type codes below */
	int	status;		/* on TRUE ret from editcalcprep, tells error piece */ 
	int erroff;		/* offset to error token */
	char far *name;		/* ptr to calc name or udf decl */
	char far *form;		/* ptr to formula */
	UDF far *udf;		/* UDF pointer on UDF edit */
	MFFIELD far *calc;	/* calc fld ptr on calc edit */
	char far *ename;	/* name of error field */
} PKCALC;



// From wmain.h, needed in rr.h
typedef struct apppathnames	// a bunch of (big) pathnames
{
	char ProgramPath[WINPATHLEN+1];	// another old favorite
	char ZOrigPath[WINPATHLEN+1];	// where we started from
	char LinkPath[WINPATHLEN+1]; 	// an old favorite
	char LibrarianPath[WINPATHLEN+1] ; 
	char LibrarianDataPath[WINPATHLEN+1] ;
#if defined(RUNDLL)
	char LibDir[WINPATHLEN+1];		// default library dir (for Runtime DLLs only)
#else
	char DDFName[WINPATHLEN+1];		// data dictionary file name
	char DDIName[WINPATHLEN+1];		// data dictionary index name
	char MRULib1[WINPATHLEN+1];		// MRU Library
	char MRULib2[WINPATHLEN+1];		// MRU Library
	char MRULib3[WINPATHLEN+1];		// MRU Library
	char MRULib4[WINPATHLEN+1];		// MRU Library
	char MRULib5[WINPATHLEN+1];		// MRU Library
	char MRULib6[WINPATHLEN+1];		// MRU Library
	char MRULib7[WINPATHLEN+1];		// MRU Library
	char MRULib8[WINPATHLEN+1];		// MRU Library
	char MRULib9[WINPATHLEN+1];		// MRU Library
#endif
} APPPATHSTRUCT;



// Needed in rstatbar.h

// max status message length
#define MESS_LEN	100
#define PANE1_LEN	31

#endif
