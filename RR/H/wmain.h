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
// $Log:   D:/R&R Project/archives/H/WMAIN.H_V  $
// 
// Rev 1.65    08 Mar 2017 10:07:52   CAS
// Test adding a FieldValue() function which returns the value of the
// field in the argument (which can be a calculated field)
// so, if a field P_LNAME contains the value "STRASSER" then 
// FieldVal("P_L" + "NAME") returns "STRASSER"
//
//    Rev 1.64   20 Oct 2004 07:21:12   Nick
// V 11. Bugs
// 
//    Rev 1.63   12 Oct 2004 09:28:44   Nick
// Tom Le changes
// 
//    Rev 1.62   11 Oct 2004 10:18:26   Nick
// V 11
// 
//    Rev 1.61   20 Sep 2004 13:41:38   Nick
// IDM_REDO
// 
//    Rev 1.60   02 Jul 2004 13:33:54   Nick
// Another hack of control id's
// 
//    Rev 1.59   Feb 06 2003 19:08:46   Admin
// Size for printer variable
// 
//    Rev 1.58   Aug 12 2002 10:46:10   Admin
// Define a timer id for parameters
// 
//    Rev 1.57   Jul 01 2002 15:28:40   Admin
// Printer
// 
//    Rev 1.56   Apr 25 2002 11:40:56   Admin
// New id's for popups
// 
//    Rev 1.55   Mar 08 2001 16:21:44   nhubacker
// Field Names button
// 
//    Rev 1.54   Mar 08 2001 11:32:14   nhubacker
// Changed WH_DMAPIOPTIONS
// 
//    Rev 1.53   Feb 27 2001 15:44:06   nhubacker
// MAPI help
// 
//    Rev 1.52   Feb 23 2001 15:12:00   nhubacker
// Help codes
// 
//    Rev 1.51   Jan 19 2001 14:08:12   nhubacker
// Functions for lastpage(0) and reportpage()
// 
//    Rev 1.50   Dec 12 2000 15:56:56   nhubacker
// Define Help entry for GRPAGE()
// 
//    Rev 1.49   Dec 05 2000 13:18:24   nhubacker
// Add Q_INDEX type
// 
//    Rev 1.48   Jul 06 2000 08:50:02   nhubacker
// Help id for Properyt/Export dialog
// 
//    Rev 1.47   Feb 02 2000 13:58:20   nhubacker
// Added IDC_* for 2 new toolbar buttons (KS)
// 
//    Rev 8.2    20 Jan 2000 14:50      ks
// Added IDC_SUPPRESSRECORD & IDC_COMPRESRECGROUP for new buttons
// 
//    Rev 1.46   Aug 30 1999 15:43:28   BUILD
// ARP20001
// 
//    Rev 1.45   30 Nov 1998 15:09:46   wrr
// Added 134154
// 
//    Rev 1.43.2.0   15 Jul 1998 11:47:12   wrr
// Code ported from 16bit ot 32bit
// Jim added percomp()
// WO157195
// 
// 
//    Rev 1.77.1.0   18 May 1998 18:20:30   jpb				//WRR 7/1/98 WO157195
// Add percomp function
// 
//    Rev 1.43   16 Jan 1998 15:38:02   JSF
// PTF20001 merge
// 
//    Rev 1.42.1.0   23 Oct 1997 14:27:16   jsf
// added sqlext.h for vc50
// 
//    Rev 1.42   28 May 1997 17:23:46   par
// Save and restore chart defaults.
// 
//    Rev 1.41   20 May 1997 15:50:48   hxc
// Added help IDs  for the Viewer Control dialog pages. 
// 
//    Rev 1.40   14 May 1997 13:25:14   par
// New help definitions for HTML and Viewer Control.
// 
//    Rev 1.39   05 May 1997 15:13:18   par
// Removed A L I V E (spacing prevents search hits) and PDI _ EXPORT conditionals.
// From this point forward, this code will always be included in build.
// 
// 
//    Rev 1.38   14 Mar 1997 16:29:22   SRM
// chart support initial checkin
// 
//    Rev 1.37   26 Feb 1997 16:31:54   jsf
// fixes RSW 2392, variable PrintType in RRDoc class
// was 41 bytes via constant PTYPESZ, now it is 81. 
// 
//    Rev 1.36   10 Feb 1997 10:18:02   sp
// Arp Live merge to trunk
// 
//    Rev 1.35.1.1   29 Oct 1996 14:16:08   smh
// Fix PDI _ EXPORT conditionals
// 
//    Rev 1.34.1.0   30 Jul 1996 16:51:02   sjo
// This is the first round of HTML export changes.  On the U02 branch I am
// putting the code in A L I V E conditionals so that we develop the code on the
// U02 branch but not effect the build of that product.
// 
//    Rev 1.34   28 Mar 1996 12:04:20   par
// Add wizard timer definitions.
// 
//    Rev 1.33   07 Mar 1996 13:31:26   sbc
// Add RTF export help code
// 
//    Rev 1.32   01 Mar 1996 15:49:08   sbc
// New help codes for export dialogs
// 
//    Rev 1.31   07 Feb 1996 17:51:02   dlm
// Modified some conditionals for the RSW runtime DLL.
// 
//    Rev 1.30   31 Jan 1996 14:19:34   sbc
// Remove obsolete IDA_TOOL* stuff and add two defines for format bar points
// combo CR/Esc messages
// 
//    Rev 1.29   22 Jan 1996 18:03:32   par
// The template library has changed to a template directory.  Removed references
// to the last library.
// 
//    Rev 1.28   12 Jan 1996 16:11:10   sbc
// Help code changes and new 2D align message id
// 
//    Rev 1.27   03 Jan 1996 16:52:42   dlm
// First pass at communication between runtime exe and dll in 32-bitland.
// 
//    Rev 1.26   02 Jan 1996 14:29:02   smh
// SH_DFILESAVEAS for new common File SaveAs dialog.
// 
//    Rev 1.25   29 Dec 1995 16:02:44   dlm
// Removed duplicate copy of tempPathBuf from DOCPATHSTRUCT.
// 
//    Rev 1.24   29 Dec 1995 13:58:00   dlm
// Added conditionals to allow use in runtime DLLs.
// 
//    Rev 1.23   17 Dec 1995 16:10:58   smh
// Added IDH_DSOVERRIDE, id for datasource override control help.
// 
//    Rev 1.22   12 Dec 1995 16:39:12   par
// Add help button support to object properties dialog.
// 
//    Rev 1.21   06 Dec 1995 15:48:06   sbc
// Add help code for saving reports w/ objects to library
// 
//    Rev 1.20   30 Nov 1995 15:07:22   sbc
// Move obsolete hlp codes
// 
//    Rev 1.19   29 Nov 1995 10:40:40   sbc
// Comment out obsolete help codes (and build to be sure)
// 
//    Rev 1.18   17 Nov 1995 08:15:30   sbc
// Change help code for text prop page
// 
//    Rev 1.17   14 Nov 1995 10:41:12   sbc
// Add preview help code
// 
//    Rev 1.16   09 Nov 1995 11:50:24   sbc
// Add popup help define
// 
//    Rev 1.15   08 Nov 1995 16:18:18   smh
// Added tempPathBuf for tempory path storage when
// finding Win95 displayable path names.
// 
//    Rev 1.14   06 Nov 1995 11:56:52   sbc
// Add shortcut ID and remove obsolete stuff
// 
//    Rev 1.13   03 Nov 1995 10:58:52   smh
// Help ids for popup help for common dlg custom ctrls.
// 
//    Rev 1.12   12 Oct 1995 10:57:26   par
// Replaced internal MRU code with MFC code.
// 
//    Rev 1.11   29 Aug 1995 13:24:14   mjs
// Win32 fixes.
// 
//    Rev 1.10   18 Aug 1995 14:47:12   mjs
// Moved strings to global.h
// 
//    Rev 1.9   31 Jul 1995 11:52:04   dlm
// Added FontLib back to DOCPATHSTRUCT (for old DOS reports).
// 
//    Rev 1.8   26 Jul 1995 09:04:44   pjm
// MOved stuff to class headers.
// 
//    Rev 1.7   19 Jul 1995 11:07:04   smh
// PATHSTRUCT -> DOCPATHSTRUCT & APPPATHSTRUCT.
// 
//    Rev 1.6   06 Jul 1995 15:27:24   smh
// Left CSVKeep/Nums/Dates behind when merged.
// 
//    Rev 1.5   28 Jun 1995 16:30:56   smh
// Merged CSV/RTF export changes from 6.5.  Didn't merge other changes
// just comments.
// 
//    Rev 1.4   14 Jun 1995 14:17:08   mjs
// New state:  DATA_MOVE
// 
//    Rev 1.3   27 Apr 1995 12:37:14   sjo
// Merge of 6.1.03+.  I say + because I have added some of the time functions
// to this merge, which will be a part of 6.1.04.  I merged the CF directories
// and some H files (for the time function changes).
// 
//    Rev 1.2   25 Apr 1995 10:09:42   sbc
// Forgot MESS_YNH for merge
// 
//    Rev 1.1   25 Apr 1995 09:47:50   sbc
// Merge 6.1.03 -> 7.0.01
// 
//    Rev 1.0   16 Mar 1995 16:14:00   sbc
// Initial revision.
// 
//    Rev 1.76   15 Jun 1995 10:27:48   smh
// Same
// 
//    Rev 1.75   15 Jun 1995 09:39:28   smh
// Changed symbol CSVKeeps defined on so defined in the runtime.
// 
//    Rev 1.74   14 Jun 1995 19:43:12   smh
// Added INI settings to keep numeric and date formats in CSV export.
// 
//    Rev 1.73   12 Jun 1995 16:08:12   sjo
// No longer need 'Grey' globals.
// 
//    Rev 1.72   08 Jun 1995 11:44:50   sjo
// Checking in changes for CSV (both Word Merge and Text Data) export 
// support. Changed dfile\dexport.c, dtxtopt.c, repio\grmisc.c, rpwritex.c,
// spec\specopt.c, h\dfile.h, dbexport.h, repio.h, resource.h, wmain.h,
// _dfile.h and wdialog.h.  Also resource\rrw.str,export.dlg.
// 
//    Rev 1.71   30 May 1995 13:53:46   pjm
// Added DisableRtfX for RTF export.
// 
//    Rev 1.70   26 May 1995 16:21:24   pjm
// Add RpFXName to Paths structure for RTF export.
// 
//    Rev 1.69   17 May 1995 12:00:36   mjs
// Changes for stretching fields.
// 
//    Rev 1.68   28 Apr 1995 17:52:00   sjo
// Added support for new time interval calcs, CTOT, CTOS, STOC, CTDT, TTOS.
// 
//    Rev 1.67   13 Apr 1995 18:45:48   dlm
// Added condtionals on RUNDLL to DEFSTRUCT definition, since the runtime
//  DLL now needs a few of the Defs members and it makes no sense to make
//  a full-blown Defs for it.
// 
//    Rev 1.66   10 Apr 1995 15:44:54   dlm
// Added MESS_YNH, a new messageBox() type, that has yes/no/help buttons.
// 
//    Rev 1.65   04 Apr 1995 07:51:18   pjm
// Changed WH_DDATETIME and WH_WH_DTIME.
// 
//    Rev 1.64   03 Apr 1995 15:46:12   pjm
// Added DTLOOKUP help code.
// 
//    Rev 1.63   29 Mar 1995 19:41:10   sjo
// changes for international time support.
// 
//    Rev 1.62   27 Mar 1995 19:30:22   sjo
// Added support for new DT functions.
// 
//    Rev 1.61   27 Mar 1995 12:23:40   sbc
// New help codes
// 
//    Rev 1.60   23 Mar 1995 17:09:44   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
// 
//    Rev 1.59   08 Feb 1995 17:16:14   dlm
// Part of rework of MRU List in File menu. MRU list is now read from
//  INI file at startup, maintained in memory (in the Paths structure),
//  and written on Exit; instead of constant reading and writing of the
//  INI file during the use of R&R.  Affected modules are: wreport.h,
//  wmain.h, wglobal.c, wrmain.c, winit.c, wreport.c, and mru.cpp which
//  was largely rewritten.
// 
//    Rev 1.58   06 Feb 1995 11:40:58   sbc
// Fix typo in RSW functab help.
// 
//    Rev 1.57   03 Feb 1995 16:09:10   sbc
// Remap dialog help codes for John S.
// 
//    Rev 1.56   03 Feb 1995 16:03:28   sbc
// Added calc function context help values
// 
//    Rev 1.55   09 Jan 1995 16:22:10   smh
// Moved prevSelBasedRep to wrmain.c, it's only used there. RSW 1617
// 
//    Rev 1.54   01 Dec 1994 13:27:36   sbc
// Add new dialog help ID's
// 
//    Rev 1.53   17 Nov 1994 15:27:48   sbc
// Change Defs.dfPrPgLM from UONE to UTWO for shitty printer drivers that have
// paper sizes (invalid) greater than 8 bits.   RRW #2043
// 
//    Rev 1.52   10 Nov 1994 17:44:40   dlm
// Part of fix to RRW bug 2064 to allow runtime window title to be up to
//  200 characters, not 30.
// 
//    Rev 1.51   20 Oct 1994 11:36:18   dlm
// Adapted Paths structure for use by runtime DLL with conditionals
//  on new build symbol RUNDLL.
// 
//    Rev 1.50   04 Oct 1994 16:36:38   dlm
// Added DDFName and DDIName to Paths structure.
// 
//    Rev 1.49   04 Oct 1994 11:34:56   dlm
// Remove CustomTitleScreenName global.
// 
//    Rev 1.48   28 Sep 1994 15:46:44   sbc
// FileOpenName -> Paths
// 
//    Rev 1.47   20 Sep 1994 14:03:12   pjm
// Added IgnoreU to RRW version of Defs.
// 
//    Rev 1.46   14 Sep 1994 16:20:56   smh
// Added TemplLast to Defs.  It's the last, or current template lib.
// It's used only when Defs.TemplLib is empty.
// 
//    Rev 1.0   14 Sep 1994 16:20:38   smh
// Initial revision.
// 
//    Rev 1.45   14 Sep 1994 09:36:06   dlm
// Part of fix to RRW bug 1540.  Allow optional non-softening of hard spaces
//  in database fields (only) via new INI file setting of SoftenDBFields, 
//  with default of 1 (meaning DO soften 'em, as before).  Fix involves
//  winit.c, mfdbc.c, mfdata.h, lookup.c.
// 
//    Rev 1.44   08 Sep 1994 08:38:38   sbc
// New help code
// 
//    Rev 1.43   08 Sep 1994 08:32:24   smh
// Added a section and keys for putting user name and company into
// R?W.INI in Setup.
// 
//    Rev 1.42   06 Sep 1994 14:33:34   sbc
// Change report type (RT_) values again
// 
//    Rev 1.41   30 Aug 1994 14:20:48   sbc
// New error message dialog type
// 
//    Rev 1.40   15 Aug 1994 10:17:46   sbc
// Rearrange RT_ defines (again)
// 
//    Rev 1.39   05 Aug 1994 15:02:48   sbc
// Help code for new logon dialog
// 
//    Rev 1.38   02 Aug 1994 14:01:44   sbc
// Remove newD4 array
// 
//    Rev 1.37   02 Aug 1994 13:32:38   smh
// Added a constant for the File "Summary Info" menu item.
// 
//    Rev 1.36   02 Aug 1994 08:31:04   sbc
// 
//    Rev 1.35   02 Aug 1994 08:26:26   sbc
// New arg for doClArgs()
// 
//    Rev 1.34   01 Aug 1994 14:04:36   sbc
// Fix MM_ menu bar values (MS Office)
// 
//    Rev 1.33   28 Jul 1994 10:54:48   smh
// Added TemplLib, the default template library to Defs.
// Also moved newD4 from here to wreport.c for Steve.
// 
//    Rev 1.32   26 Jul 1994 14:49:36   sbc
// Change RT_OPEN to 5
// 
//    Rev 1.31   26 Jul 1994 14:47:34   jpb
// add some auto total params
// 
//    Rev 1.30   26 Jul 1994 13:46:06   sbc
// Add RT_OPEN
// 
//    Rev 1.29   25 Jul 1994 11:12:32   dlm
// Changed extern for getFilter() to getCLFilter() to avoid a conflict with
//  another routine called getFilter().
// 
//    Rev 1.28   25 Jul 1994 10:23:04   dlm
// Added extern for getFilter().
// 
//    Rev 1.27   22 Jul 1994 18:28:52   jpb
// add mode Q_TOT for total condition processing by calc/udf dialog
// 
//    Rev 1.26   07 Jul 1994 14:37:04   erp
// changes for popup menus 
// 
//    Rev 1.25   05 Jul 1994 13:03:36   sbc
// New dialog help code
// 
//    Rev 1.24   28 Jun 1994 13:12:32   erp
// reserved menu IDs for MRU List support
// 
//    Rev 1.23   20 Jun 1994 09:02:08   sbc
// Rearrange RT_ defines
// 
//    Rev 1.22   14 Jun 1994 11:46:40   sbc
// Script stuff
// 
//    Rev 1.21   13 Jun 1994 16:31:52   sbc
// Change instant report defines to file new
// 
//    Rev 1.20   08 Jun 1994 10:43:48   sbc
// New help code
// 
//    Rev 1.19   28 Apr 1994 16:20:54   sbc
// Add DBF pathname
// 
//    Rev 1.18   28 Apr 1994 16:15:56   dlm
// Moved some Arg definitions here from cmdline.c because wrmain.c
//  needs 'em too.
// 
//    Rev 1.17   28 Apr 1994 15:21:42   sbc
// Add ExpWksPath to Paths structure
// 
//    Rev 1.16   18 Apr 1994 12:24:16   sbc
// Add externs for routines moved from WRMAIN.C to new CMDLINE.C
// 
//    Rev 1.15   23 Mar 1994 15:14:44   dlm
// Okay, okay.  Changed WxCharFldWidthSize so it gets defined in
//  winit.c, where it's used, instead of in wrmain.c where it isn't
//  used and which isn't present in the runtime.
// 
//    Rev 1.14   23 Mar 1994 14:32:36   dlm
// Moved GLOBAL for WxCharFldWidthSize here from datadict.h.
// 
//    Rev 1.13   21 Mar 1994 14:38:12   say
// replace WH_BTRIEVE (unused) with WH_DATASOURCE
// 
//    Rev 1.12   21 Mar 1994 12:02:20   dlm
// Merge of Abra branch:
//  Added GLOBAL for DArg, which relates to DLL-name command-line arg.
//  Added GLOBAL for QArg, which relates to record-level filtering and
//   is conditional on RECORD_FILTER.
//  Added GLOBAL for CustomTitleScreenName, which is conditional on 
//   CUSTOM_TITLE.
// 
//    Rev 1.11   09 Mar 1994 15:34:04   sbc
// Change FFAREA (freeform area width) to 12 (10 in R?W 2.?)
// 
//    Rev 1.10   17 Jan 1994 18:06:46   say
// add WH_NOTABLES
// 
//    Rev 1.9   12 Jan 1994 14:34:40   say
// add IDM_NEWICON
// 
//    Rev 1.8   29 Dec 1993 13:34:48   smh
// Database export:  See Scott for complete list of files.
// 
//    Rev 1.7   08 Dec 1993 15:26:24   say
// Remove old SQL logon stuff add a few lines for ODBC
// 
//    Rev 1.6   06 Dec 1993 16:41:12   jpb
// Add WH_DLIMITRESULT and IDM_LIMIT for Limit Result dialog
// 
//    Rev 1.5   23 Nov 1993 10:34:16   say
// Add WH_LOGONPREFS help code for Options->Auto Logon dialog for RSW
// 
//    Rev 1.4   19 Nov 1993 17:38:36   sbc
// Add extern C for C++
// 
//    Rev 1.3   18 Nov 1993 15:10:58   say
// Add IDM_LOGONPREFS for RSW Options menu
// 
//    Rev 1.2   02 Nov 1993 14:27:38   say
// #include sglobal.h for LEN #defs that were in eng.h
// 
//    Rev 1.1   02 Nov 1993 11:12:14   say
// remove #include eng.h after moving LEN defs from eng.h to global.h
//
//    Rev 1.0.1.1   28 Feb 1994 11:05:24   dlm
// Cleaned up some ABRA conditionals.
// 
//    Rev 1.0.1.0   11 Jan 1994 10:45:48   dlm
// Define QArg for record-filter command line argument.
// Define CustomTitleScreenName.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _WMAIN_H_

//
// Make a definition for this module.
//
#define _WMAIN_H_

#if defined (RSW)

   //	The following are being removed from here, because they contain GLOBALs, which
	// will not get defined when rrdoc.h is in the precompiled header.
	// We can put any needed typedefs and macros in globals.h.

	// #include "sglobal.h" // for LEN #defs that were in eng.h

#include "sql.h"	 // ODBC header; for SQL_MAX_DSN_LENGTH
#include "sqlext.h"	 // ODBC header; for SQL_MAX_DSN_LENGTH, now here in VC 5.0
#endif

#if defined(_RRINIT_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
	// All the stuff from wstatic.h
// WSTATIC.H - externs for wstatic.c

// custom message box types
#define MESS_EX			0
#define MESS_YNY		1
#define MESS_YNN		2
#define MESS_YNC		3
#define MESS_INFO		4
#define MESS_STOP		5
#define MESS_OKCAN		6
#define MESS_OKIGNORE	7
#define MESS_YNH		8

////// Timer ID and delay for startup bitmap  ////////
#define SPLASH_TIMER_ID		100		// SetTimer/KillTimer ID
#define SPLASH_TIMER_WAIT	3000	// 3 seconds
#define WIZARD_TIMER_ID		101		// SetTimer/KillTimer ID
#define WIZARD_TIMER_WAIT	2000	// 2 seconds
#define PARAMETER_TIMER_ID	102
#define PARAMETER_TIMER_WAIT 120000 // 120 seconds, 2 minutes


// some caret parameters
#define MIN_CARET	1
#define MAX_CARET	32

// Windows advertised string table length
#define WINSTRLEN	255

// maximum number of program args
#define MAXARGS 53	//	Enough for progname, /C /O, and 50 reports.

// maximum decimal places
#define MAXDECPL	15

// font/pitch stuff
#define TIC_WIDTH		10			// pitch for ruler tic width
#define PLACE_PITCH		TIC_WIDTH	// place fields in "columns" using this
#define MINPTS			40			// minimum point size (4.0 pts)
#define MAXPTS			5000		// maximum point size (500.0 pts)
#define CANNED_PTS		14			// number of canned point sizes

// keyboard/mouse activities (ActiveState values)
#define MOUSE_MOVE	0x1		// moving fields with mouse
#define MOUSE_BAND	0x2		// marking band lines with mouse
#define	MOUSE_RECT	0x4		// marking fields with rectangle (mouse)
#define IMAGE_EDIT	0x8		// editing image
#define KEY_MOVE	0x10	// moving fields with keyboard
#define IMAGE_MOVE	0x20	// moving/scrolling image (outline)
#define KEY_BAND	0x40	// marking band lines with keyboard
#define BOX_EDIT	0x80	// editing box
#define BOX_MOVE	0x100	// moving/scrolling box (outline)
#define LINE_SIZE	0x200	// sizing freeform line
#define BAR_FONT	0x400	// font combo
#define BAR_PTS		0x800	// points combo
#define DATA_MOVE	0x1000	// moving/scrolling data field (outline)
#define IN_DIALOG	0x8000	// in dialog box

#define MOUSE_ACTIVE	(MOUSE_MOVE|MOUSE_BAND|MOUSE_RECT|IMAGE_MOVE|BOX_MOVE|LINE_SIZE|DATA_MOVE)
#define KEY_ACTIVE		(KEY_MOVE | KEY_BAND)
#define FORMAT_BAR		(BAR_FONT | BAR_PTS)

#define PDRVSZ		81		// printer driver array
#define PPORTSZ		81		// printer port array
#define PTITLESZ	201		// printer title array
#define PTYPESZ		221		// printer type array

// calc/udf/totcond types
#define Q_CALC		1
#define Q_UDF		2
#define Q_TOT		3
#define Q_INDEX		4
#define Q_PARAM		5

// total types
#define T_SINGLETOT	1
#define T_BATCHTOT	2

// PRT_FACE flags
#define PRINTER_FONT	0x1		// font is a device font
#define TRUETYPE_FONT	0x2		// TrueType font

// define for 3.1
// #define TRUETYPE_FONTTYPE   0x0004	// fix when we include 3.1 stuff

// report types from File New dialog
#define RT_WIZARDS		1	// the wizards
#define RT_INSTANT		2	// old fashioned instant report
#define RT_BLANK		3	// blank report
#define RT_TEMPLATE		4	// report template
#define RT_OPEN			5	// open a report instead
#define RT_SCRIPT		10	// script file passed on command line

// editing types for common edit/delete confirmation dialog
#define EDIT_TOTAL		0		// editing a total
#define	EDIT_CALC		1		// a calculation
#define EDIT_RELATION	2		// change a relation
#define DEL_RELATION    3		// wipe a relation
#define DEL_MASTER		4		// wipe master file
#define DEL_TEXTFILE	5		// wipe ASCII memo
#define DEL_CALC		6		// wipe calc field
#define DEL_UDF			7		// wipe UDF
#define EDIT_UDF		8		// change one
#define PURGE_CALCS		9		// purge calcs and/or totals
#define EDIT_PARAM		10		// editing a parameter
#define DEL_PARAM		11		// wipe parameter field

// fonts made during session
#define FORMBAR_FONT	0x1		// format bar labels
#define STATUS_FONT		0x2		// status bar
#define DEFNORM_FONT	0x4		// default normal font
#define DEFUNDER_FONT	0x8		// default underscore font

#define DEFAULTPOINTS	120		// the fallback

#define FREEFORMBORDER	1		// pixels for free-form border
#define FFAREA			12		// wifth of freeform channel in band area

#define RRWCOLORS	140			// we do 140 ?

	// HELP CONSTANTS from wrhelp.h
#define WH_DIMAGE		1001	// Image properties
#define WH_DALIGN		1002	// Format Alignment (character field)
#define WH_DATABASE		1003	// Database Master
#define WH_DCALCNEW		1004	// create calculated field
#define WH_DCALCINS		1005	// Calculations New/Edit Calc Expression
#define WH_DCHRFORM		1006	// Format Picture (character field)
#define WH_FOPENTAG		1007	// Getting a missing index tag on File Open
#define WH_DDATFORM		1008	// Format Picture (date field)
#define WH_DDELCON		1009	// common confirm delete/edit dialog
#define WH_DEDCALC		1010	// Calculations Calculated Field (list of calcs)
#define WH_DEDTOTAL		1011	// Calculations Total Field (list of totals)
#define WH_DEDUDF		1012	// Calculations User Function (list of udfs)
#define WH_DTOTNEW		1013	// new total field
#define WH_SAVEOBJECTS	1014	// save report w/ objects warning dialog
#define WH_DGETTAG		1015	// Calculations New/Edit Key Expression Tag
#define WH_DGLOBDEF		1016	// Options Default Settings
#define WH_DGROUP		1017	// Database Group
// Spelled wrong so stop using. 
//#define WH_HTLMEXP		1018	// HTML 2.0 Export
#define WH_MEMOHTML		1018	// Properties/Export/Char or Memo
#define WH_DINSFLD		1019	// Edit Insert Field
#define WH_DLCREATE		1020	// Edit Create Line
#define WH_DLEDIT		1021	// Format Line
#define WH_DNUMFORM		1022	// Format Picture (numeric field)
#define WH_DPRINT		1023	// File Print
#define WH_DPROPT		1024	// Options Page Layout
#define WH_2DALIGN		1025	// 2D alignment dialog
#define WH_DPURGE		1026	// Edit Purge Fields
#define WH_DQUERY		1027	// Database Query
#define WH_DRECOPTS		1028	// Options Record Layout
#define WH_DREL			1029	// Database Relations (list of relations)
#define WH_DRELNEW		1030	// new relation
#define WH_DREPREAD		1031	// File Open Report
#define WH_DREPSAVE		1032	// File Save As
#define WH_DRRPREF		1033	// Options Preferences
#define WH_DRULER		1034	// modify ruler spacing
#define WH_DSCANORD		1035	// Database Relation Group
#define WH_DSORT		1036	// Database Sort
#define WH_DSTYLE		1037	// Format Font
#define WH_DTXATT		1038	// Database Text File
#define WH_DCOMMENT		1039	// calc comment via calc list dialog
#define WH_DUDFNEW		1040	// new udf
#define WH_DUDFINS		1041	// Calculations New/Edit User Function Formula
#define WH_DJLCR		1042	// Line Justify
#define WH_DMINDFILE	1043	// master index file
#define WH_DMASTFILE	1044	// master table file
#define WH_DQUERYED		1045	// edit query term
#define WH_DCALCED		1046	// edit calculated field
#define WH_DUDFED		1047	// edit udf
#define WH_DPASTE		1048	// paste lines
#define WH_DRELED		1049	// edit relation
#define WH_DEDQFLD		1050	// field dialog in query edit
#define WH_DTOTED		1051	// edit total field
#define WH_DKEYFILE		1052	// index key file dialog
#define WH_PRODSUP		1053	// Product Support
#define WH_DNEWLIB		1054	// new report library (save dialog)
#define WH_DOPENLIB		1055	// open report library (open dialog)
#define WH_DRINDFILE	1056	// related index file open dialog
#define WH_DRTABFILE	1057	// related table file open dialog
#define WH_DTXFILE			1058	// text file open dialog
#define WH_DTXTEDIT			1059	// text field properties page
#define WH_DDEFDIRS			1060	// default directories dialog 
#define WH_DCLIPIMG			1061	// get name to store clipboard image on save
#define WH_ERRMESS			1062	// error message help
#define WH_DLINE			1063	// line properties
#define WH_DBOX				1064	// box properties
#define WH_DEXPORT			1065	// export dialog
#define WH_DOPENTRANS		1066	// open file dialog for report copy
#define WH_DCOPYNAME		1067	// dialog to request report copy name
// #define WH_DCOPYTYPE	1068	// dialog to change database type in copy
#define WH_DCONNECT			1070	// database logon help
#define WH_PREVIEW			1071	// print preview window
#define WH_DOPENIMG			1072	// dialog to open image file
#define WH_DBTRIEVE			1073	// Help for Btrieve dlg box
#define WH_DATASOURCE		1074	// Help for Connected Data Source dialog
#define WH_SQL_SELECT		1075	// Help for SQL Select dlg box
#define WH_RRWCNVRT			1076	// report conversion program
#define WH_LOGONPREFS		1077	// Options->Auto Logon dialog box for RSW
#define WH_DLIMITRESULT		1078	// Database->LimitResult dialog
#define WH_NOTABLES			1079	// No tables dialog
#define WH_DFILENEW			1080	// File New choices
#define WH_DVIEWTOOLS		1081	// View Toolbars
#define WH_DLOGON			1082	// Our logon dialog
#define WH_PICKDATASOURCE	1083	// Data Source Connection dialog
#define WH_DFILESUMMARY		1084	// File Summary Info
#define WH_DCALCCOMMENT		1085	// Calc Comment in tabbed dialog
#define WH_DAUTOTOTAL		1086	// Auto Total
#define WH_DEDITRESET		1087	// Total Edit Reset

//	Note: 1090 through 1101 in use by Wizards

// 	Note: 1102 & 1103 in use by RRDICT & RRICON

#define WH_DDATETIME		1104	// Format Date/Time field dialog
#define WH_DTIME			1105	// Format Time Field dialog
#define WH_RTFEXP			1106	// RTF Export dialog
#define WH_CSVEXP			1107	// Text Data File / Word Merge

//	  IDH_ screens are just like WH_ screens, the prefix indicates pop-up (for a control) help
#define IDH_NOMASTER		1108	// Create Report without Master Table checkbox
#define IDH_PRINTWHAT		1109	// "Print What" control on common print dialog
#define IDH_PRINTFILE		1110	// "Print file" control on common print dialog
#define IDH_PRINTPREV		1111	// Preview button on common print dialog
#if defined (RSW)
#define IDH_DSOVERRIDE		1113	// data source override dropdown on RSW file open
#endif

#define WH_DOBJECTPROPERTIES 1112  // OLE Object Properties dialog
#define WH_DFILESAVEAS		1114	// File Save As dialog
#define WH_DEXP_XBASE_WKS	1115	// Xbase/Worksheet export dialog
#define WH_DEXP_TEXT		1116	// Text export dialog
#define WH_HTMLEXP			1117    // HTML 2.0 Export
#define WH_VIEWEREXP_INPUTFILE    1118    // Viewer Control Export Input File Page.
#define WH_VIEWEREXP_OBJ_TAGS     1119    // Viewer Control Export Object Tags Page.
#define WH_DPROMPTTEXT		1121	// prompt text dialog
#define WH_DVALUELISTS		1122	// Value Lists dialog
#define WH_PARAMS			1123	// List Parameters
#define WH_EDITPARAMS		1124	// Edit Parameter
#define WH_GETPARAMS		1125	// Input Parameters
#define WH_DATEPARAM		1126	// Edit Date Parameter
#define WH_DATETIMEPARAM	1127	// Edit datetime Parameter
#define WH_NUMPARAM			1128	// Edit numeric Parameter
#define WH_CHARPARAM		1129	// Edit character Parameter
#define WH_LOGPARAM			1130	// Edit logical Parameter
#define WH_DMAPIOPTIONS		1131	// export MAPI options dialog
// new Version 11.0
#define	WH_CONDITIONAL		1132	// edit or new total conditional
#define	WH_EDITPARAMVALID	1133	// edit parameter validation
#define	WH_NEWPARAMVALID	1134	// new parameter validation
#define	WH_PREFS_DISPLAY	1135	// Preferences - Display
#define	WH_PREFS_FILENEW	1136	// Preferences - File New
#define	WH_PREFS_DATASOURCE	1137	// Preferences - Data Source
#define	WH_PREFS_MEMOEDIT	1138	// Preferences - Memo Editor
#define	WH_PREFS_FIELDLIST	1139	// Preferences - Field Lists
#define	WH_PREFS_AUTOSAVE	1140	// Preferences - Autosave
#define	WH_EXPORT_TYPE		1141	// Export - type page
#define	WH_EXPORT_MAPI		1142	// Export - mapi page
#define	WH_EXPORT_OPTIONS	1143	// Export - options page
#define	WH_EXPORT_HTML		1144	// Export - HTML options
#define	WH_EXPORT_ACTIVEX	1145	// Export - ActiveX options
#define	WH_SECURITY			1146	// Security
#define	WH_TOTAL_NAME		1147	// Edit Total - name page
#define	WH_TOTAL_TYPE		1148	// Edit Total - type page
#define	WH_TOTAL_TARGET		1149	// Edit Total - target page
#define	WH_TOTAL_RESET		1150	// Edit Total - reset page
#define	WH_TOTAL_ACCUM		1151	// Edit Total - accum page
#define	WH_TOTAL_PROCESS	1152	// Edit Total - process page
#define	WH_TOTAL_CONDITION	1153	// Edit Total - condition page
#define	WH_MTOTAL_SELECT	1154	// Edit Multi Total - select page
#define	WH_MTOTAL_TYPE		1155	// Edit Multi Total - type page
#define	WH_MTOTAL_TARGET	1156	// Edit Multi Total - target page
#define	WH_MTOTAL_RESET		1157	// Edit Multi Total - reset page
#define	WH_MTOTAL_ACCUM		1158	// Edit Multi Total - accum page
#define	WH_MTOTAL_PROCESS	1159	// Edit Multi Total - process page
#define	WH_MTOTAL_CONDITION	1160	// Edit Multi Total - condition page
#define	WH_MTOTAL_OK		1161	// Edit Multi Total - OK dialog
#define	WH_TOTAL_NAME_AUTO	1162	// Edit Total - name page (single auto)
#define	WH_REPLACE			1163	// Replace
#define WH_VIEW_RULER		1164	// View Rulers
#define WH_INSERT_DB_FIELD	1165	// Insert DB Field (Flex link index)
#define WH_DUP_DBF_EXPORT	1166	// Duplicate field on DBF export
#define	WH_SELECT_SORT_FIELD	1167	// Select field (sort)
#define	WH_SELECT_GROUP_FIELD	1168	// Select field (group)
#define	WH_SELECT_TOTAL_FIELD	1169	// Select field (total)
#define	WH_SELECT_CALC_FIELD	1170	// Select field (edit calc)
#define	WH_SELECT_LINE_FIELD	1171	// Select field (line conditional)
#define	WH_SELECT_SENDTO_FIELD	1172	// Select field (Export SendTo)
#define	WH_SELECT_SUBJECT_FIELD	1173	// Select field (Export Subject)
#define	WH_SELECT_MESSAGE_FIELD	1174	// Select field (Export Message)
#define	WH_SELECT_LINK_FIELD	1175	// Select field (Relate link)
#define	WH_PARAM_NAME			1176	// Edit param (name page)
#define	WH_PARAM_VALUE			1177	// Edit param (value page)
#define	WH_PARAM_PRESENT		1178	// Edit param (present page)
#define	WH_PARAM_VALIDATE		1179	// Edit param (validate no-list page)
#define	WH_PARAM_STATIC_LIST	1180	// Edit param (validate static-list page)
#define	WH_PARAM_DYNAMIC_LIST	1181	// Edit param (validate dynamic-list page)
#define	WH_BAND_TYPE			1182	// Band line properties: type
#define	WH_BAND_HEIGHT			1183	// Band line properties: height
#define	WH_BAND_CONDITION		1184	// Band line properties: conditon
#define	WH_SELECT_RECORDCOPY_FIELD	1185	// Select field (Record Layout, #copies)
#define	WH_SELECT_IMAGE_FIELD	1186	// Select field (for image)
#define WH_SELECT_SCOPE_FIELD	1187	// Select parameter field for scope
#define WH_EDIT_FLEXLINK		1188	// Edit/create Flex Link Index expression
#define WH_SELECT_FROM_FIELD	1189	// Join From Field
#define WH_SELECT_TO_FIELD		1190	// Join To Field
#define WH_SELECT_DB_DYN_FIELD	1191	// Insert DB dynamic Field 
#define WH_SELECT_DB_DYN_VALUE	1192	// Insert DB dynamic Value 

//Relation
#define WH_RELATION_LINKING_FIELD	1200	//  
#define WH_RELATION_RELATED_TABLE	1201	//  
#define WH_RELATION_RELATED_INDEX	1202	//  
#define WH_RELATION_RELATED_TYPE	1203	//  
#define WH_RELATION_CHARACTER_MATCH	1204	//  
#define WH_RELATION_FAILURE_ACTION	1205	//  

// Calc Function Context Help Values
#define WH_FUNC_ABS         2000    // ABS
#define WH_FUNC_ADDDAYS     2005    // ADDDAYS
#define WH_FUNC_ADDMONS     2010    // ADDMONS
#define WH_FUNC_ADDWKS      2015    // ADDWKS
#define WH_FUNC_ADDYRS      2020    // ADDYRS
#define WH_FUNC_AGED        2025    // AGED
#define WH_FUNC_ASC         2030    // ASC
#define WH_FUNC_AT          2035    // AT
#define WH_FUNC_BLANKNUM    2040    // BLANKNUM      (RRW only)
#define WH_FUNC_CAPFIRST    2045    // CAPFIRST
#define WH_FUNC_CASE        2050    // CASE
#define WH_FUNC_CDLL        2055    // CDLL
#define WH_FUNC_CDOW        2060    // CDOW
#define WH_FUNC_CHR         2065    // CHR
#define WH_FUNC_CLOOKUP     2070    // CLOOKUP       (RRW only)
#define WH_FUNC_CMONTH      2075    // CMONTH
#define WH_FUNC_COPY        2080    // COPY
#define WH_FUNC_CTDT        2082	// CTDT
#define WH_FUNC_CTOD        2085    // CTOD
#define WH_FUNC_CTOS        2087	// CTOS                
#define WH_FUNC_CTOT        2088    // CTOT
#define WH_FUNC_DATE        2090    // DATE
#define WH_FUNC_DAY         2095    // DAY
#define WH_FUNC_DAYSBTWN    2100    // DAYSBTWN
#define WH_FUNC_DBF         2105    // DBF           (RRW only)
#define WH_FUNC_DELETED     2110    // DELETED       (RRW only)
#define WH_FUNC_DLOOKUP     2115    // DLOOKUP       (RRW only)
#define WH_FUNC_DOW         2120    // DOW
#define WH_FUNC_DQTR        2125    // DQTR
#define WH_FUNC_DATEADD		2126	// DTEADD
#define WH_FUNC_DATEDIFF	2127	// DTEDIFF
#define WH_FUNC_DATEPART	2128	// DTEPART
#define WH_FUNC_DTLOOKUP	2129	// DTLOOKUP
#define WH_FUNC_DTOC        2130    // DTOC
#define WH_FUNC_DTTOC		2131	// DTTOC
#define WH_FUNC_ERROR       2135    // ERROR
#define WH_FUNC_EXP         2140    // EXP
#define WH_FUNC_FLIP        2145    // FLIP
#define WH_FUNC_FUTURE      2150    // FUTURE
#define WH_FUNC_HALF        2155    // HALF
#define WH_FUNC_HISCOPE     2160    // HISCOPE       (RRW only)
#define WH_FUNC_IIF         2165    // IIF
#define WH_FUNC_INLIST      2170    // INLIST
#define WH_FUNC_INRANGE     2175    // INRANGE
#define WH_FUNC_INT         2180    // INT
#define WH_FUNC_ISALPHA     2185    // ISALPHA
#define WH_FUNC_ISBLANK     2190    // ISBLANK       (RRW only)
#define WH_FUNC_ISLOWER     2195    // ISLOWER
#define WH_FUNC_ISNULL      2200    // ISNULL        (RSW only)
#define WH_FUNC_ISUPPER     2205    // ISUPPER
#define WH_FUNC_LEFT        2210    // LEFT
#define WH_FUNC_LEN         2215    // LEN
#define WH_FUNC_LIBNAME     2220    // LIBNAME
#define WH_FUNC_LIKE        2225    // LIKE          (RSW only)
#define WH_FUNC_LLOOKUP     2230    // LLOOKUP       (RRW only)
#define WH_FUNC_LOG         2235    // LOG
#define WH_FUNC_LOSCOPE     2240    // LOSCOPE       (RRW only)
#define WH_FUNC_LOWER       2245    // LOWER
#define WH_FUNC_LTRIM       2250    // LTRIM
#define WH_FUNC_LUPDATE     2255    // LUPDATE       (RRW only)
#define WH_FUNC_MAX         2260    // MAX
#define WH_FUNC_MIN         2265    // MIN
#define WH_FUNC_MOD         2270    // MOD
#define WH_FUNC_MONLEN      2275    // MONLEN
#define WH_FUNC_MONSBTWN    2280    // MONSBTWN
#define WH_FUNC_MONTH       2285    // MONTH
#define WH_FUNC_NDOW        2290    // NDOW
#define WH_FUNC_NLOOKUP     2295    // NLOOKUP       (RRW only)
#define WH_FUNC_OVER        2300    // OVER
#define WH_FUNC_PAGENO      2305    // PAGENO
#define WH_FUNC_PAST        2310    // PAST
#define WH_FUNC_PDOW        2315    // PDOW
#define WH_FUNC_PREVIOUS    2320    // PREVIOUS
#define WH_FUNC_QTR         2325    // QTR
#define WH_FUNC_QUERY       2330    // QUERY
#define WH_FUNC_RECCOUNT    2335    // RECCOUNT      (RRW only)
#define WH_FUNC_RECNO       2340    // RECNO
#define WH_FUNC_REPLICATE   2345    // REPLICATE
#define WH_FUNC_REPNAME     2350    // REPNAME
#define WH_FUNC_RIGHT       2355    // RIGHT
#define WH_FUNC_RIPARAM     2360    // RIPARAM
#define WH_FUNC_ROUND       2365    // ROUND
#define WH_FUNC_RR          2370    // RR            (RSW only)
#define WH_FUNC_RRUNIN      2375    // RRUNIN
#define WH_FUNC_RTRIM       2380    // RTRIM
#define WH_FUNC_SCANNING    2385    // SCANNING      (RRW only)
#define WH_FUNC_SOUNDEX     2390    // SOUNDEX
#define WH_FUNC_SPACE       2395    // SPACE
#define WH_FUNC_SPELLNUM    2400    // SPELLNUM
#define WH_FUNC_SQLEXP      2405    // SQLEXP        (RSW only)
#define WH_FUNC_SQRT        2410    // SQRT
#define WH_FUNC_STOC		2412	// STOC
#define WH_FUNC_PERCOMP     2413    // PERCOMP  // WRR 7/1/98 WO157195
#define WH_FUNC_STR         2415    // STR
#define WH_FUNC_STRCOUNT    2420    // STRCOUNT
#define WH_FUNC_STRREP      2425    // STRREP
#define WH_FUNC_STRSEARCH   2430    // STRSEARCH
#define WH_FUNC_STUFF       2435    // STUFF
#define WH_FUNC_SUBDAYS     2440    // SUBDAYS
#define WH_FUNC_SUBMONS     2445    // SUBMONS
#define WH_FUNC_SUBSTR      2450    // SUBSTR
#define WH_FUNC_SUBWKS      2455    // SUBWKS
#define WH_FUNC_SUBYRS      2460    // SUBYRS
#define WH_FUNC_TIME        2465    // TIME
#define WH_FUNC_TODATE      2466    // TODATE
#define WH_FUNC_TOTIME      2467    // TOTIME
#define WH_FUNC_TRANSFORM   2470    // TRANSFORM
#define WH_FUNC_TRIM        2475    // TRIM
#define WH_FUNC_TTOC	    2476    // TTOC
#define WH_FUNC_TTOS		2478	// TTOS
#define WH_FUNC_UDFNAME     2480    // UDFNAME
#define WH_FUNC_UPPER       2485    // UPPER
#define WH_FUNC_VAL         2490    // VAL
#define WH_FUNC_WDCOUNT     2495    // WDCOUNT
#define WH_FUNC_WEEK        2500    // WEEK
#define WH_FUNC_WKSBTWN     2505    // WKSBTWN
#define WH_FUNC_WORD        2510    // WORD
#define WH_FUNC_YEAR        2515    // YEAR
#define WH_FUNC_YRSBTWN     2520    // YRSBTWN
#define WH_FUNC_NOW			2525    // NOW
#define WH_FUNC_LASTPAGE	2530    // LASTPAGE
#define WH_FUNC_REPORTPAGE	2535    // REPORTPAGE
//  There isn't a help topic for the new function fieldval yet
//  this is added as a place holder by CAS on 3/8/2017
//  See Rev 1.65 above
#define WH_FUNC_FIELDVAL	2540	// FIELDVAL


	// from wmenu.h - header for main R&R for Windows module

// Defines for menu items

#define MAIN_MENU_ITEMS		9	// choices on main menu bar

// relative position values for main menu bar
#define MM_FILE		0		// File
#define MM_EDIT		1		// Edit
#define MM_VIEW		2		// View
#define MM_INSERT	3		// Insert
#define MM_FORMAT	4		// Format
#define MM_OPTIONS	5		// Options
#define MM_DATABASE 6		// Database
#define MM_CALCS	7		// Calculations
#define MM_HELP		8		// Help

// text field edit window
#define IDC_EDITTX		1000
#define IDC_EDITCR		1001
#define IDC_EDITESC		1002

// defines for Accelerator keys

// keep IDA_UP through IDA_PAGEDN together
#define IDA_UP			20000
#define IDA_DOWN		20001
#define IDA_PAGEUP		20002
#define IDA_PAGEDN		20003
// keep IDA_UP through IDA_PAGEDN together
#define IDA_HOME		20004
#define IDA_END			20005
#define IDA_LEFT		20006
#define IDA_RIGHT		20007
#define IDA_BIGLEFT		20008
#define IDA_BIGRIGHT	20009
#define IDA_MOVEFLDS	20010
#define IDA_RULER		20011
#define IDA_NEXTFLD		20014
#define IDA_PREVFLD		20015
#define IDA_KEYMARK		20016
#define IDA_KEYMARKNEW	20017
#define IDA_SCRPAGEDN	20020
#define IDA_SCRPAGEUP	20021
#define IDA_SCRLEFT		20022
#define IDA_SCRRIGHT	20023
#define IDA_SCRBIGLEFT	20024
#define IDA_SCRBIGRIGHT	20025
#define IDA_SCRUP		20026
#define IDA_SCRDOWN		20027
#define IDA_SCRHOME		20028
#define IDA_SCREND		20029
#define IDA_BIGHOME		20030
#define IDA_BIGEND		20031
#define	IDA_INS			20032
#define	IDA_DEL			20033
#define	IDA_RUB			20034
#define	IDA_INSONE		20035
#define	IDA_DELONE		20036
#define	IDA_RUBONE		20037
#define IDA_LEFTONE		20040
#define IDA_RIGHTONE	20041
#define IDA_CENTER		20044
#define IDA_ESCAPE		20045
#define IDA_RETURN		20046
#define IDA_UPONE		20047
#define IDA_DOWNONE		20048
#define IDA_BANDNEW		20050
#define IDA_FORMBAR_PTS_CR  20060
#define IDA_FORMBAR_PTS_ESC 20062
// New values created by CAS on 2/20/2014 to handle messaging for
// font combo bar changes
#define IDA_FORMBAR_FNT_CR  20061
#define IDA_FORMBAR_FNT_ESC 20063
#define IDA_FMOD		20066
#define IDA_PVLEFT		20068
#define IDA_PVRIGHT		20069
#define IDA_PVUP		20070
#define IDA_PVDOWN		20071
#define IDA_PVPGDN		20072
#define IDA_PVPGUP		20073
#define IDA_PVHOME		20074
#define IDA_PVEND		20075
#define IDA_PVBIGLEFT	20076
#define IDA_PVBIGRIGHT	20077
#define IDA_FEDIT		20078
#define IDA_PASTETEXT	20100
#define IDA_UPTOGGLE	20104
#define IDA_DOWNTOGGLE	20108
#define IDA_LEFTTOGGLE	20112
#define IDA_RIGHTTOGGLE	20116
#define IDA_SHORTCUT	20118

// Put button ids here so help text does not conflict with error strings.
#define IDC_BARSTART	IDC_BARFONT		// first button id
#define IDC_BARFONT				20200
#define IDC_BARPTS				20201

#define IDC_BARBOLD				20202
#define IDC_BARITALIC			20203
#define IDC_BARUNDER			20204

#define IDC_BARLEFT				20205
#define IDC_BARCENTER			20206
#define IDC_BARRIGHT			20207
#define IDC_BARFULL				20208

#define IDC_BARTRIM				20209
#define IDC_BARTRASH			20210
#define IDC_AUTOLINE			20211
#define IDC_SNAPTO				20212
#define IDC_SUPPRESSRECORD		20213
#define IDC_COMPRESSRECGROUP	20214
#define IDC_FIELDNAMES			20215
#define IDC_UNDO				20216
#define IDC_UNDOLIST			20217

// keyboard codes for Format Bar
#define IDC_FOCUSFONT			20218
#define IDC_FOCUSPTS			20219
#define IDC_BAREND				IDC_FOCUSPTS


//
// Field Popup Menu IDs
//
//  These POPUP IDs are special since they have
//  no corresponding menu command.
#define IDM_POPUP_FIELD_EXPRESSION	25018
#define IDM_POPUP_FIELD_TOTAL		25019
#define IDM_POPUP_FIELD_DICTIONARY	25020

////
// Menu String ID's
#define IDM_FIELD_CUT			25510
#define IDM_FIELD_COPY 			25511
#define IDM_FIELD_PASTE 		25512
#define IDM_FIELD_DELETE		25513
#define IDM_FIELD_FONT			25516
#define IDM_FIELD_PROPERTIES	25517
#define IDM_FIELD_EXPRESSION	25518
#define IDM_FIELD_2DALIGN		25519
#define IDM_FIELD_TOTAL			25520
#define IDM_FIELD_DICTIONARY	25521
//
// Band Popup Menu String ID's                                   
#define IDM_BAND_CUT			25540
#define IDM_BAND_COPY			25541
#define IDM_BAND_PASTE			25542
#define IDM_BAND_DELETE			25543
#define IDM_BAND_INSERT			25544
#define IDM_BAND_CREATE			25545
#define IDM_BAND_JUSTIFY		25546
#define IDM_BAND_PROPERTIES		25547

#define IDM_POPUP_MENU_START IDM_POPUP_FIELD_CUT
#define IDM_POPUP_MENU_END IDM_POPUP_BAND_PROPERTIES

#define IDM_MENU_START		30000
#define IDM_MENU_END		35000

// File menu
#define IDM_NEWSELECT		32002
#define IDM_NEWICON			32003	// "New" toolbar icon selected vs. menu pick
#define IDM_NEW				32000
#define	IDM_OPEN			32001
#define IDM_DBCONNECT		32005
#define IDM_CLOSE			30000
#define IDM_COPYREP			32010
#define IDM_SAVE			30010
#define	IDM_SAVEAS			30020
#define IDM_REPSUM		30028
#define	IDM_PRINT			30030
// print direct from Action Bar
#define IDC_PRINT			30031

#define IDM_PREVIEW			30040
// special window id's for preview toolbar (MFC version)
#define IDC_PVFIRST		30041
#define IDC_PVBACK		30042
#define IDC_PVSTOP		30043
#define IDC_PVNEXT		30044
#define IDC_PVLAST		30045
#define IDC_PVZOOMIN	30046
#define IDC_PVZOOMOUT	30047
#define IDC_PVPRINT		30048
#define IDC_PVPAUSE		30049
#define IDC_PVPPAGE		30050
#define IDC_PVHELP		30051
#define IDC_PVRESTART   30052

//#define IDM_PRINTSET		32014
#define IDM_EXPORT			30060
#define IDM_EXIT			32016

// Edit menu
#define IDM_UNDO			30100
#define IDM_UNDOLIST		30101
#define IDM_CUT				30110
#define IDM_COPY			30120
#define IDM_PASTE			30130
#define IDM_DELETE			30140
#define IDM_MOVEFLDS		30150
#define IDM_COPYFLDS		30160
#define IDM_PASTECLIPIMAGE	30170
#define IDM_REDO			30180	//tl

// View menu
#define IDM_ACTIONBAR		30200
#define	IDM_TOOLBAR			30202
#define	IDM_FLDNAMES		30204
#define IDM_RULER			30206
#define IDM_VIEWHITE		30208
#define IDM_VIEWHRULER		30210
#define IDM_VIEWVRULER		30212
#define IDM_VIEWSNAP		30214
#define IDM_VIEWPOSITION	30216

// Options menu
#define IDM_DEFAULTS	    32018
#define	IDM_RRPREFS		    32020
#define IDM_DEFDIRS		    32022
#define IDM_LOGONPREFS	    32023
#define IDM_CHARTDEFAULTS   32025

// Insert menu
#define IDM_FINS		30400
#define IDM_INSLINE		30410
#define IDM_CRLINE		30420
#define IDM_TEXTFILE	30430
#define IDM_INSLN		30440
#define IDM_INSBOX		30450
#define IDM_INSIMAGE	30460
#define IDM_INSCHART	30470

// Format menu
#define IDM_2DALIGN		30500
#define IDM_FSTYLE		30502
#define IDM_FFORMAT		30504
// #define IDM_FTRIM		30506
#define IDM_LEDIT		30508
#define IDM_LJUST		30510
#define IDM_PROPT		30512
#define	IDM_RECOPT		30514
// #define IDM_SNAPTO		30516  // Use button id

// Database menu
#define IDM_DBMASTER	30600
#define IDM_DBSQL		30601  // help text for toolbar button in SQL mode
#define IDM_DBREL		30610
#define IDM_SEDIT		30620
#define IDM_GROUP		30630
#define IDM_QEDIT		30640
#define IDM_SELECT		30650  // show select statement
#define IDM_LIMIT		30660  // limit result table

// Calculations
#define IDM_CALCS 		30700
#define IDM_TOTALS		30710
#define	IDM_UDFS		30720
#define	IDM_GPURGE		30730
#define	IDM_AUTOTOT		30740

// Help menu
#define IDM_HINDEX		32024
#define IDM_HKEYS		32026
#define IDM_HCOM		32028
#define	IDM_HHELP		32030
#define IDM_HABOUT		32032
#define IDM_HERRMESS	32034
#define IDM_HPRODSUP	32036

//***** Valid menu items when no report active ******/
#define IDM_NO_REP_BEG		32000
#define IDM_NO_REP_END		32999
//***************************************************/



	// from winter.h - international settings, measurement - WIN.INI settings
#define METRIC		0				// cm
#define ENGLISH		1				// in


//
// Structure Section:
// Place in this section any structure definitions.
//
typedef struct defrrbox				// report writer default line/box structure
{
	WORD sides;						// sides to display
	char thickness;					// line thickness (1,2,4,6, or 8 pixels)
	char hatch;						// shading (hatch brush value or 0xFF if no hatch)
									// color values are indexes into ColorTable
	char bordColor;					// border color
	char foreColor;					// hatch color
	char backColor;					// box background color
} DEFRRBOX;

typedef struct docpathnames			// a bunch of (big) pathnames
{
	char CIPName[WINPATHLEN+1];		// what!?!
	char RpEName[WINPATHLEN+1];		// export pathname
	char RpFName[WINPATHLEN+1];		// print-to-file name
	char RpFXName[WINPATHLEN+1];	// RTF export pathname
	char LibName[WINPATHLEN+1];		// report library pathname
	char FileOpenName[WINPATHLEN+1];// storage for common dialog use
#if !defined(RUNDLL)
	char FontLib[WINPATHLEN+1];		// font library (for old DOS reports)
	char RpSortFile[WINPATHLEN+1];	// sort file too
	char MFPtrFile[WINPATHLEN+1];	// group file pointer file name
	char ExpDbfPath[WINPATHLEN+1];	// DBF export pathname
	char ExpWksPath[WINPATHLEN+1];	// WKS export pathname
	char ExpWordPath[WINPATHLEN+1];	// Word merge file export path
	char ExpCSVPath[WINPATHLEN+1];	// Comma Separated Value export path
	char ExpHTML2Path[WINPATHLEN+1];// HTML 2.0 export path
	char ExpPDIPath[WINPATHLEN+1];	// PDI Export
	char ScriptPath[WINPATHLEN+1];	// script file pathname
	char AutoSavePath[WINPATHLEN+1];// where to auto save
	char AutoSavePathOld[WINPATHLEN+1];// save for removing autosave file.
#endif
	char tempPathBuf[WINPATHLEN];	// for temporary path storage (WINPATHLEN includes final NULL)
} DOCPATHSTRUCT;


typedef struct DefStruct
{
#if !defined(RUNDLL)
	UTWO	dfPrPgLen;					// page length
	UTWO	dfPrPgLM;					// page length measurement
	UTWO	dfPrPgWid;					// page width
	UTWO	dfPrRM;						// right margin
	UTWO	dfPrTM;						// top margin
	UTWO	dfPrBM;						// bottom margin
	UTWO	dfPrLM;						// left margin
	char	DecSep;						// "Decimal Point" character
	char	DigSep;						// Digit separator character
	char	CurStr[CUR_STR_MAX+1];		// currency sign string
	int		CurPrefix;					// FALSE=>currency string is suffix, else prefix
	char	LogTStr[LOG_STR_MAX+1];		// logical TRUE string
	char	LogFStr[LOG_STR_MAX+1];		// logical FALSE string
	char	IndExt[6];					// default index file name pattern (e.g.,"*.NDX")
	char	MemExt[6];					// default ascii memo file pattern (e.g.,"*.MEM")
	char	ImgExt[6];					// default image file pattern (e.g.,"*.PCX")
	char	AllowWrites;				// Allow write file sharing
	UONE	dfRulPitch;					// ruler pitch
	UONE	dfPrFont[LF_FACESIZE+1];	// print font
	UTWO	dfPoints;					// point size (decipoints)
	char	Printer[PATHLENGTH+1];		// Printer
#endif // !RUNDLL
	char	StartingDir[PATHLENGTH+1];	// initial directory
	char	ImageDir[PATHLENGTH+1];		// bitmap directory
	char	LookupDir[PATHLENGTH+1];	// dynamic lookup directory
	char	LibDir[PATHLENGTH+1];		// library directory
	char	LongDate[DATE_PIC_MAX+1];	// Windows long date picture
	char	ShortDate[DATE_PIC_MAX+1];	// Windows short date picture
#if !defined(RUNDLL)
	char	TemplDir[PATHLENGTH+1];		// default template directory
	char	dfMeasure;					// English/Metric
	char	iNegCurr;					// same as Windows
	char	dfVRulPitch;				// vertical ruler gradient
	char	dfSnapToGrid;				// snap default
	char	dfFldColor;					// field color index
	DEFRRBOX defLineBox;				// line/box defaults
#endif	// !RUNDLL
 #ifdef RSW
  #if !defined(RUNDLL)
	char	szDefDataSource[SQL_MAX_DSN_LENGTH+1]; // defined in ODBC.H
	BOOL	bNewReportAutoLogon;
  #endif // !RUNDLL
	BOOL	bReadReportAutoLogon;
 #endif // RSW
#if !defined(RUNDLL)
 #if !defined(RSW)
	char	IgnoreU;					// Ignore Unrecognized data types
 #endif // !RSW
#endif	// !RUNDLL
	char	TimeSep;					// Time separator character
	char	AMStr[TIME_SUFFIX_MAX];		// Before noon suffix
	char	PMStr[TIME_SUFFIX_MAX];		// After noon suffix
	unsigned int  TimePic;				// Combination of international time settings for the picture.
	TCHAR   szChartFontBase[LF_FACESIZE] ;  //WRR 7/2/98 WO157195
	TCHAR   szChartFontTitle[LF_FACESIZE] ;
	TCHAR   szChartFontAxis[LF_FACESIZE] ;
	TCHAR   szChartFontLabel[LF_FACESIZE] ;
	TCHAR   szChartFontLegend[LF_FACESIZE] ;
	int     nChartPalette   ;
	int		nFontTitleSize	;
	int		nFontAxisSize	;
	int		nFontLabelSize	;
	int		nFontLegendSize	;
	int		Dictionary ;				// Dictionary functions, please
} DEFSTRUCT;

#define DEFSIZE sizeof(DEFSTRUCT)

#undef GLOBAL

#endif // end _WMAIN_H_

// *************************** End of File ************************************
