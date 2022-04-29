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
// $Log:   D:/R&R Project/archives/H/DATADICT.H_V  $
// 
//    Rev 1.5   Aug 12 2002 10:35:16   Admin
// New dictionary format
// 
//    Rev 1.4   25 Mar 1997 12:41:28   pjm
// Use MAXSDNAME for name size in DESCRIPTOR structure.
// 
//    Rev 1.3   17 Nov 1995 19:04:46   smh
// Win32 file i/o.
// 
//    Rev 1.2   26 Jul 1995 17:53:54   smh
// some char arrays needed "near" specifier.
// 
//    Rev 1.1   11 Jul 1995 09:34:20   dlm
// Moved stuff to rr.h - application class.
// 
//    Rev 1.0   16 Mar 1995 16:12:18   sbc
// Initial revision.
// 
//    Rev 1.8   28 Sep 1994 14:58:28   smh
// Added ddsetup_nomaster() proto.
// 
//    Rev 1.7   21 Sep 1994 15:05:06   dlm
// More work on RR bug 1968.  Define prototype for ddcalccleanup().
// 
//    Rev 1.6   11 May 1994 11:17:26   dlm
// Added file-number argument to ddsetup().
// Added GLOBAL DDChangeFile that tells ddsetup() whether it is adding
//  a file or replacing one.
// 
//    Rev 1.5   03 May 1994 15:57:10   dlm
// Fixes a compile error after latest Abra merge.
// 
//    Rev 1.4   03 May 1994 12:33:46   dlm
// Merge from Abra branch:  see 1.0.1.0.
// 
//    Rev 1.3   05 Apr 1994 12:28:20   dlm
// Added some stuff to support data dictionary in RSW.  The field descriptor
//  structure field-name array must be 11 bytes since dictionary is a .DBF.
//  Added a dummy-file structure for use with kl routines instead of using
//  full-blown MFFILE structures since some components needed by kl routines
//  are not defined in RSW mode.
// Added some GLOBALS relating to new logical fields now supported by data
//  dictionary: HIDE_FIELD, HIDE_FILTR, and HIDE_INST.
// 
//    Rev 1.2   23 Mar 1994 14:31:48   dlm
// Moved GLOBAL for WxCharFldWidthSize to wmain.h, since it's used in
//  winit.c and nowhere else and is needed even if DATADICT is not "on"
// 
//    Rev 1.1   21 Mar 1994 12:05:58   dlm
// Moved some data-dictionary-related GLOBALS here from xglobal.h (I think).
// 
//    Rev 1.0.1.0   02 May 1994 15:31:52   dlm
// Added data items and externs relating to maintenance of a list of fields
//  deleted for security reasons.
// 
//    Rev 1.0   09 Mar 1994 11:46:06   dlm
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _DATADICT_H_

//
// Includes needed by this header.
//
	#include "mffield.h"	// for LPMFFIELD definition

#if defined _DATADICT_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

//
// Make a definition for this module.
//
#define _DATADICT_H_

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
#define FLDLEN 10
#define TABLEN 8
#define CMNTLEN 80
#define WIDTHLEN 3
#define DECPTLEN 2
#define LONGLEN 1
#define SECLEN 5
#define C 'C'
#define M 'M'
#define N 'N'
#define L 'L'
#define T 'T'
#define DELFLAG '*'
#define REASONABLE 30
//
// Structure Section:
// Place in this section any structure definitions.
//
typedef struct dbheader
{
	UONE version;	// used to determine platform & presence of memo file 
	UONE date[3];
	FOUR numrecs;
	UTWO headlen;
	UTWO reclen;
	UTWO reservd;
	UONE inctrans;
	UONE encrypt;
} DBHEADER;

typedef struct fld_descriptor
{
#if defined(RSW)
	UONE fldname[11];		// needs to be size of name in .DBF header!!
#else
	UONE fldname[MAXSDNAME];
#endif
	UONE type;
	FOUR skip;
	UONE size;
	UONE dec;
} DESCRIPTOR;

// The following structure is a subset of the RRW MFFILE structure, defined for
//  use by datadict.c.  These structure members are not defined in the RSW
//  MFFILE structure, so we need an alternative place to store this info.
typedef struct dummy_file
{
	KLNTXFILE *mDbcFd;			// DBC file descriptor pointer
	char mTag[MAXTAG];			// dBASE IV mdx file tag name
} DUMMY_FILE;

typedef struct seclist
{
	struct seclist* link;	// link to next structure
	char* name;				// pointer to local memory containing field name
} SECLIST;

typedef SECLIST* PSECLIST;

//
// Global Data Section:
// Place in this section any global data.
//


#if defined(DATADICT)
GLOBAL char near WxDataDict[]
 #if defined _DATADICT_C_
 = "DataDict"
 #endif
;
GLOBAL char near WxDataDictIx[]
 #if defined _DATADICT_C_
 = "DataDictIndex"
 #endif
;
GLOBAL char near WxDictKey[]
 #if defined _DATADICT_C_
 = "Data Dictionary"
 #endif
;
GLOBAL char near WxTable_Name[]
 #if defined _DATADICT_C_
 = "TABLE_NAME"
 #endif
;
GLOBAL char near WxField_Name[]
 #if defined _DATADICT_C_
 = "FIELD_NAME"
 #endif
;
GLOBAL char near WxSecurity[]
 #if defined _DATADICT_C_
 = "SECURITY"
 #endif
;
GLOBAL char near WxComment[]
 #if defined _DATADICT_C_
 = "COMMENT"
 #endif
;
GLOBAL char near WxFormula409[]
 #if defined _DATADICT_C_
 = "FORMULA"
 #endif
;
GLOBAL char near WxExtended[]
 #if defined _DATADICT_C_
 = "EXTENDED"
 #endif
;
GLOBAL char near WxFieldList[]
 #if defined _DATADICT_C_
 = "FIELD_HIDE"
 #endif
;
GLOBAL char near WxFilterList[]
 #if defined _DATADICT_C_
 = "FILTR_HIDE"
 #endif
;
GLOBAL char near WxInstantRep[]
 #if defined _DATADICT_C_
 = "INST_HIDE"
 #endif
;
#endif



#undef GLOBAL
#endif // end _DATADICT_H_

// *************************** End of File ************************************
