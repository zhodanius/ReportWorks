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
// $Log:   D:/R&R Project/archives/H/WLAYOUT.H_V  $
// 
//    Rev 1.8   02 Jul 2004 13:32:58   Nick
// Undo
// 
//    Rev 1.7   09 Feb 1996 08:31:24   sbc
// Changes for undo of last field move
// 
//    Rev 1.6   14 Jul 1995 10:34:20   sbc
// Move stuff to CRrView class
// 
//    Rev 1.5   14 Jun 1995 14:17:32   mjs
// 6.5 changes (prototypes for new data stretching fns)
// 
//    Rev 1.4   25 Apr 1995 15:30:46   sbc
// RSW #1823 - keyboard move of fields problem - call routine in WINSDEL.CPP
// 
//    Rev 1.3   25 Apr 1995 10:15:44   sbc
// 6.1.03 -> 7.0.01 merge
// 
//    Rev 1.8   15 Sep 1994 12:43:34   sbc
// Change RecWidth to pixels
// 
//    Rev 1.7   02 Aug 1994 12:33:52   sbc
// Fix typeo (_WMMOVE_C_)
// 
//    Rev 1.6   01 Aug 1994 11:07:16   sbc
// Change function name/args (WPIX.C)
// 
//    Rev 1.5   07 Jul 1994 14:37:40   erp
// changes for popup menus
// 
//    Rev 1.4   24 Jun 1994 10:26:04   sbc
// New function
// 
//    Rev 1.3   23 May 1994 10:55:46   sbc
// New routine to show caret
//
//    Rev 1.2   27 Mar 1995 13:32:02   mjs
// Moved prt_face into prtinit.h
// 
//    Rev 1.1   23 Mar 1995 07:53:08   sbc
// Convert text editing
// 
//    Rev 1.0   16 Mar 1995 16:13:58   sbc
// Initial revision.
// 
//    Rev 1.8   15 Sep 1994 12:43:34   sbc
// Change RecWidth to pixels
// 
//    Rev 1.7   02 Aug 1994 12:33:52   sbc
// Fix typeo (_WMMOVE_C_)
// 
//    Rev 1.6   01 Aug 1994 11:07:16   sbc
// Change function name/args (WPIX.C)
// 
//    Rev 1.5   07 Jul 1994 14:37:40   erp
// changes for popup menus
// 
//    Rev 1.4   24 Jun 1994 10:26:04   sbc
// New function
// 
//    Rev 1.3   23 May 1994 10:55:46   sbc
// New routine to show caret
// 
//    Rev 1.2   14 Jan 1994 13:22:02   mjs
// findYGrid should return long.
// 
//    Rev 1.1   19 Nov 1993 17:38:30   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:11:04   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _WLAYOUT_H_

//
// Make a definition for this module.
//
#define _WLAYOUT_H_
#include "wfield.h"
#include "mffield.h"
#include "prtinit.h"	// for prt_face
//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

//
// Structure Section:
// Place in this section any structure definitions.
//

// Undo field move structure
//
typedef struct moveFieldRedo
{
	LPFLDHDR	pFld;
	int			fldRow;
	RECT		rectFld;
} MOVE_FIELD_REDO;

typedef struct moveFieldUndo
{
	LPFLDHDR	pFld;
	int			fldRow;
	RECT		rectFld;
} MOVE_FIELD_UNDO;

typedef struct resizeFieldRedo	//tl
{
	LPFLDHDR	pFld;
	int			fldRow;
	RECT		rectFld;
} RESIZE_FIELD_REDO;

typedef struct resizeFieldUndo	//tl
{
	LPFLDHDR	pFld;
	int			fldRow;
	RECT		rectFld;
} RESIZE_FIELD_UNDO;

typedef struct lineInsertRedo	//tl 
{
	LPFLDHDR	pFld;
	int			fldRow;
	RECT		rectFld;
} LINE_INSERT_REDO;

typedef struct lineInsertUndo	//tl 
{
	LPFLDHDR	pFld;
	int			fldRow;
	RECT		rectFld;
} LINE_INSERT_UNDO;

typedef struct boxInsertUndo	//tl 
{
	LPFLDHDR	pFld;
	int			fldRow;
	RECT		rectFld;
} BOX_INSERT_UNDO;

// Undo field delete structure
//
typedef struct deleteFieldUndo
{
	LPFLDHDR	pFld;
} DELETE_FIELD_UNDO;

typedef struct deleteFieldRedo	//tl
{
	LPFLDHDR	pFld;
} DELETE_FIELD_REDO;

typedef struct deleteLineUndo
{
	int			fields ;
	DELETE_FIELD_UNDO	*df ;
	WHENP		*dl ;
} DELETE_LINE_UNDO ;

typedef struct deleteLineRedo	//tl
{
	int			fields ;
	DELETE_FIELD_REDO	*df ;
	WHENP		*dl ;
} DELETE_LINE_REDO ;

typedef struct insertFieldRedo
{
	LPFLDHDR	pFld;
} INSERT_FIELD_REDO ;

typedef struct insertFieldUndo
{
	LPFLDHDR	pFld;
} INSERT_FIELD_UNDO ;

typedef struct formatUndo
{
	LPFLDHDR	pFld;
	char		hatt ;
	uint		hfont ;
	uint		hpoints ;
	HFONT		fldfont ;
} FORMAT_UNDO ;

typedef struct insertLineUndo
{
	int			line ;
} INSERT_LINE_UNDO ;

// Array of all undo actions
typedef struct allUndo
{
	int		type ;
	int		count ;
	char	*reference ;
	void	*data ;
} ALLUNDO ;

// Array of all redo actions
typedef struct allRedo	//tl
{
	int		type ;
	int		count ;
	char	*reference ;
	void	*data ;
} ALLREDO ;

// the Undo types:
#define	UNDO_MOVE_FIELD		0	//tl currently using 9/21/04
#define	UNDO_DELETE_FIELD	1	//tl currently using 9/21/04
#define	UNDO_DELETE_LINE	2
#define UNDO_INSERT_FIELD	3
#define UNDO_LINE_INSERT	4	//tl
#define UNDO_BOX_INSERT		12	//tl
#define UNDO_FORMAT			5	//tl currently using 9/21/04
#define	UNDO_INSERT_LINE	6
#define	UNDO_ALIGN_FIELD	7
#define	UNDO_RESIZE_FIELD	8	//tl
#define	REDO_DELETE_LINE	9	//tl
#define	REDO_RESIZE_FIELD	10	//tl
#define	REDO_DELETE_FIELD	11	//tl currently using 9/21/04

//
// Global Data Section:
// Place in this section any global data.
//
#ifdef _WMOVE_C_
#define GLOBAL
#else
#define GLOBAL extern
#endif

#undef GLOBAL
//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#endif // end _WLAYOUT_H_

// *************************** End of File ************************************
