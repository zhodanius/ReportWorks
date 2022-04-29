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
// $Log:   D:/R&R Project/archives/H/GLOBDEFS.H_V  $
// 
//    Rev 1.3   Oct 03 2003 14:14:12   Admin
// Add RI_PSIZE as synonym for RI_PAGESIZE
// 
//    Rev 1.2   Jul 01 2002 15:21:42   Admin
// RI_PAGESIZE
// 
//    Rev 1.1   16 Apr 1997 09:05:48   pjm
// Add string for RI_DBC.
// 
//    Rev 1.0   04 Dec 1995 15:28:38   jpb
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _GLOBDEFS_H_
//
// Make a definition for this module.
//
#define _GLOBDEFS_H_

//
// Includes needed by this header.
//

#if defined(_MAINFRM_CPP_)
#define GLOBAL
#else
#define GLOBAL extern
#endif


#if !defined INTERACTIVE

GLOBAL char prevClass[]
#if defined(_MAINFRM_CPP_)
 = "PreviewClass"
#endif
;

GLOBAL char WxRuntimeDLL[]
#if defined(_MAINFRM_CPP_)
 #if defined(RSW)
 = "RSREPORT.DLL"
 #else
 = "RREPORT.DLL"
 #endif
#endif
;

GLOBAL char T1ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_MASTER"
#endif
;

GLOBAL char T11ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_MINDEX"
#endif
;

GLOBAL char T15ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_MEMO"
#endif
;

GLOBAL char T18ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_ALIAS%d"
#endif
;

GLOBAL char T0RunOF[] 
#if defined _MAINFRM_CPP_
 = "RO_ECODE"
#endif
;
GLOBAL char T1RunOF[] 
#if defined _MAINFRM_CPP_
 = "RO_EMSG"
#endif
;
GLOBAL char T2RunOF[] 
#if defined _MAINFRM_CPP_
 = "RO_REPORTS"
#endif
;
GLOBAL char T3RunOF[] 
#if defined _MAINFRM_CPP_
 = "RO_PAGES"
#endif
;
GLOBAL char T4RunOF[] 
#if defined _MAINFRM_CPP_
 = "RO_RIRECNO"
#endif
;
GLOBAL char T1LRun[] 
#if defined _MAINFRM_CPP_
 = "RI_OUTAPPN"
#endif
;
GLOBAL char T2LRun[] 
#if defined _MAINFRM_CPP_
 = "RI_PEQUIT"
#endif
;
GLOBAL char T3LRun[] 
#if defined _MAINFRM_CPP_
 = "RI_NOESC"
#endif
;
GLOBAL char T4LRun[] 
#if defined _MAINFRM_CPP_
 = "RI_TEST"
#endif
;
GLOBAL char T5LRun[] 
#if defined _MAINFRM_CPP_
 = "RI_DISPERR"
#endif
;
GLOBAL char T6LRun[] 
#if defined _MAINFRM_CPP_
 = "RI_STATUS"
#endif
;
GLOBAL char T1NRun[] 
#if defined _MAINFRM_CPP_
 = "RI_BEGPAGE"
#endif
;
GLOBAL char T2NRun[] 
#if defined _MAINFRM_CPP_
 = "RI_ENDPAGE"
#endif
;
GLOBAL char T3NRun[] 
#if defined _MAINFRM_CPP_
 = "RI_COPIES"
#endif
;
// T1ARun is in runtime.h because grfile.c needs it
GLOBAL char T2ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_LIBRARY"
#endif
;
GLOBAL char T3ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_REPORT"
#endif
;
GLOBAL char T4ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_OUTFILE"
#endif
;
GLOBAL char T5ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_CHKTIME"
#endif
;
GLOBAL char T6ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_PRINTER"
#endif
;
GLOBAL char T61ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_PAGESIZE"
#endif
;
GLOBAL char T62ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_PSIZE"
#endif
;
GLOBAL char T7ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_LOSCOPE"
#endif
;
GLOBAL char T8ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_HISCOPE"
#endif
;
GLOBAL char T9ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_SCOPE"
#endif
;
// T11ARun is in runtime.h because grfile.c needs it
GLOBAL char T12ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_FILTER"
#endif
;
// T15ARun is in runtime.h because grfile.c needs it
GLOBAL char T17ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_FONTFIL"
#endif
;
// T18ARun is in runtime.h because grjoin.c needs it
GLOBAL char T19ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_PREVIEW"
#endif
;
GLOBAL char T20ARun[] 
#if defined _MAINFRM_CPP_
 = "RI_UDF"
#endif
;
GLOBAL char WxWPtr[]  
#if defined _MAINFRM_CPP_
 = "RI_WPTR"
#endif
;
GLOBAL char WxWPort[] 
#if defined _MAINFRM_CPP_
 = "RI_WPORT"
#endif
;
GLOBAL char WxWTitle[]  
#if defined _MAINFRM_CPP_
 = "RI_WTITLE"
#endif
;
GLOBAL char WxExpDst[]
#if defined _MAINFRM_CPP_
 = "RI_EXPDST"
#endif
;
GLOBAL char WxRepPick[]
#if defined _MAINFRM_CPP_
 = "RI_REPPICK"
#endif
;
#if defined RSW
GLOBAL char WxDatabase[]
#if defined _MAINFRM_CPP_
 = "RI_DB"
#endif
;
#endif
#if !defined(RSW)
GLOBAL char WxDBCName[]
#if defined _MAINFRM_CPP_
 = "RI_DBC"
#endif
;
#endif
//////////////////////////////////////////////////////////////////////////////////////
// New fields for VBX control (preview/sort/group)
GLOBAL char WxWBorder[]
#if defined _MAINFRM_CPP_
 = "RI_WBORDER"
#endif
;

GLOBAL char WxWControl[]
#if defined _MAINFRM_CPP_
 = "RI_WCTRL"
#endif
;

GLOBAL char WxWHeight[]
#if defined _MAINFRM_CPP_
 = "RI_WHEIGHT"
#endif
;

GLOBAL char WxWLeft[]
#if defined _MAINFRM_CPP_
 = "RI_WLEFT"
#endif
;

GLOBAL char WxWMax[]
#if defined _MAINFRM_CPP_
 = "RI_WMAX"
#endif
;

GLOBAL char WxWMin[]
#if defined _MAINFRM_CPP_
 = "RI_WMIN"
#endif
;

GLOBAL char WxWParent[]
#if defined _MAINFRM_CPP_
 = "RI_WPARENT"
#endif
;

GLOBAL char WxWTop[]
#if defined _MAINFRM_CPP_
 = "RI_WTOP"
#endif
;

GLOBAL char WxWWidth[]
#if defined _MAINFRM_CPP_
 = "RI_WWIDTH"
#endif
;

GLOBAL char WxGroup[]
#if defined _MAINFRM_CPP_
 = "RI_GROUP%d"
#endif
;

GLOBAL char WxSort[]
#if defined _MAINFRM_CPP_
 = "RI_SORT%d"
#endif
;

#endif	// !INTERACTIVE

#undef GLOBAL

#endif // end _GLOBDEFS_H_

// *************************** End of File ************************************
