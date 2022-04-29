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
//	Global variables for R&R for Windows (Xbase and SQL)
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/GLOBAL.H_V  $
// Rev 1.51    09 Dec 2014 10:23:19   CAS
// Added definitions of named colors based on Microsoft list of colors for use on the 
// web
//
// Rev 1.50    18 Nov 2014 10:40:22   CAS
// Added "Config" key value to the mix for new R?W.INI items
// Added "DisableHTMLBrowser" variable as new R?W.INI item
// Added "HTMLBrowserPopup" variable as new R?W.INI item
// 
//    Rev 1.49   01 Sep 2004 08:04:16   Nick
// No Records Found
// 
//    Rev 1.48   02 Jul 2004 13:26:34   Nick
// New rulers
// 
//    Rev 1.47   Aug 12 2002 10:35:52   Admin
// WKS to XLS
// 
//    Rev 1.46   Jul 01 2002 15:21:06   Admin
// Printer
// 
//    Rev 1.45   Feb 28 2002 11:00:06   Admin
// Add ini setting SortFieldNames
// 
//    Rev 1.44   Nov 02 2000 09:50:58   nhubacker
// Color
// 
//    Rev 1.43   Apr 05 2000 13:41:34   nhubacker
// New
// 
//    Rev 1.42   Feb 04 2000 09:08:12   nhubacker
// Colored bands (KS)
// 
//    Rev 1.41   30 Nov 1998 10:38:34   wrr
// 
//    Rev 1.40.1.2.1.0   17 Sep 1998 13:02:12   wrr
// No change.
// 
//    Rev 1.40.1.2   31 Aug 1998 14:58:48   jpb
// add string for UseDefaultDatabase INI setting for fix to
//  WO 159630 (port of modified version of TMP for WO 156383)
// 
//    Rev 1.40.1.1   15 Apr 1998 09:46:22   jpb
// change WxRR from Cyberprise Report Designe to Cyberprise in case
// used in viewer
// 
//    Rev 1.40.1.0   14 Apr 1998 19:04:42   smh
// Changed ARPEGGIO to Cyberprise.
// 
//    Rev 1.40   16 Jan 1998 15:40:36   JSF
// PTF20001 merge
// 
//    Rev 1.39.1.0   23 Oct 1997 14:40:02   jsf
// charting PTF 1
// 
//    Rev 1.39   30 May 1997 17:25:12   hxc
// Added Viewer Control size variables to the INI file.
// 
//    Rev 1.38   28 May 1997 17:23:44   par
// Save and restore chart defaults.
// 
//    Rev 1.37   15 May 1997 09:57:44   hxc
// Added ActiveX Viewer file export INI variables.
// 
//    Rev 1.36   05 May 1997 15:13:12   par
// Removed A L I V E (spacing prevents search hits) and PDI _ EXPORT conditionals.
// From this point forward, this code will always be included in build.
// 
// 
//    Rev 1.35   03 Apr 1997 21:02:46   pjm
// Add text for DBC file extension.
// 
//    Rev 1.34   10 Mar 1997 14:44:14   dlm
// Part of "fix" to RRW bug 2936 / RSW bug 2305.  Involves a change to the
//  way we decide whether two floating point values are "close enough" to
//  call them equal.  Modules are SXCOMPV.CPP, RRCOMPOS.CPP, WINIT.CPP,
//  GLOBAL.H, RRCOMPOS.H.  The significant changes are in SXCOMPV.CPP.  The
//  others relate to a new INI-file setting (FloatCompTolerance in Defaults
//  section).
// 
//    Rev 1.33   19 Feb 1997 14:57:00   dlm
// Part of fix to RRW 2991/RSW 2386 to allow specification via SPACEDOT
//  setting in .SRT file of override for hard-space character.  Changed much
//  code to use new SpaceDot variable instead of zdSPC or ANSI_DOT.  Changed
//  most export/printer DLLs to use a new internal SpaceDot function instead
//  of exported pwSpaceDot.  Change EXEs to use new CRrDoc::SpaceDot function
//  instead of using exported pwSpaceDot functions of DLLs.  Modules changed
//  are: explt.cpp, token.cpp, fstr.cpp, trim.cpp, pksx.cpp, sxmisc.cpp,
//  mfgetmch.cpp, mfsql.cpp, htmlexp.cpp, pwint.cpp, pxdriver.cpp, pxint.cpp,
//  rtfexp.cpp, wexpdriv.cpp, wexpint.cpp, pwdriver.cpp, picdata.cpp,
//  picshape.cpp, prec.cpp, rpwrap.cpp, rprint.cpp, gropts.cpp, grfield.cpp,
//  rpwritex.cpp, grmisc.cpp, rrcompos.cpp, rrdoc.cpp, rrrepio.cpp,
//  specfld1.cpp, specfld2.cpp, specquer.cpp, wedtx.cpp, edittext.cpp,
//  wfont.cpp, readsrt.cpp, wprint.cpp, wtxtexp.cpp, winst.cpp, wstring.cpp,
//  global.h, pd.h, rrcompos.h, rrdoc.h, rrrepio.h, _pd.h, _rtexp.h
// 
//    Rev 1.32   10 Feb 1997 10:02:20   sp
// Arp Live merge to trunk
// 
//    Rev 1.30.1.1   29 Oct 1996 14:21:24   smh
// Fix PDI _ EXPORT conditional
// 
//    Rev 1.28.1.1   30 Jul 1996 16:50:42   sjo
// This is the first round of HTML export changes.  On the U02 branch I am
// putting the code in A L I V E conditionals so that we develop the code on the
// U02 branch but not effect the build of that product.
// 
//    Rev 1.28   05 Mar 1996 16:48:54   pjm
// Remove "R&R" text for ARPEGGIO.
// 
//    Rev 1.27   28 Feb 1996 18:26:58   dlm
// Changed WxLastLib and WxLastRep to Library32 and Report32, respectively.
// 
//    Rev 1.26   20 Feb 1996 15:35:36   jpb
// add WxReportWriterQuery clipformat name
// 
//    Rev 1.25   16 Feb 1996 17:35:10   jpb
// add RWQ extension
// 
//    Rev 1.24   16 Feb 1996 16:21:02   sjo
// Changes made to accept R?W files on the command line as well as .TXT files, 
// .RRS and RSS files from the shortcut maker.
// 
//    Rev 1.23   15 Jan 1996 10:46:30   par
// Scott requested the change from Template Lib to Template Dir.
// 
//    Rev 1.22   05 Jan 1996 16:31:14   par
// All explicitly linked modules and external initialization files are located
// with the explicit file manager.  This will provide a central location where
// file paths can be adjusted.
// 
//    Rev 1.21   12 Dec 1995 15:01:38   sbc
// Remove WxMaximize
// 
//    Rev 1.20   30 Nov 1995 15:04:50   sbc
// Move WxPrintDLL here now that DLL is common (RRPD.DLL)
// 
//    Rev 1.19   27 Nov 1995 13:44:36   smh
// R?WEXP.DLL -> RRTXTX.DLL
// 
//    Rev 1.18   25 Sep 1995 10:17:54   mjs
// Comment out print.h
// 
//    Rev 1.17   29 Aug 1995 13:27:36   mjs
// win32
// 
//    Rev 1.16   18 Aug 1995 14:46:28   mjs
// Moved strings into here from headers included in rrdoc.h.
// 
//    Rev 1.15   26 Jul 1995 16:34:24   sbc
// Fix arrays that weren't changed to near
// 
//    Rev 1.14   26 Jul 1995 10:45:46   mjs
// Compiler didn't like unsized ColorTable array.
// 
//    Rev 1.13   25 Jul 1995 15:29:14   smh
// typedef for DIRRTN.
// 
//    Rev 1.12   25 Jul 1995 08:41:48   pjm
// More near character arrays.
// 
//    Rev 1.11   24 Jul 1995 14:30:46   pjm
// CHange all initialized GLOBAL character arrays to near addresses.
// 
//    Rev 1.10   19 Jul 1995 14:24:20   pjm
// Removed the stuff I'd #if 0'd out in previous version.
// 
//    Rev 1.8   28 Jun 1995 15:38:36   smh
// Merged some CSV/RTF export changes from 6.5 (and some others)
// 
//    Rev 1.7   14 Jun 1995 14:18:04   mjs
// 6.5 changes (handles for new mouse cursors)
// 
//    Rev 1.6   26 Apr 1995 15:38:58   pjm
// Final? merge fix.
// 
//    Rev 1.5   26 Apr 1995 14:53:30   pjm
// More corrections.
// 
//    Rev 1.4   26 Apr 1995 14:48:54   pjm
// Removed duplicate cursor list.
// 
//    Rev 1.3   26 Apr 1995 14:07:08   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.2   03 Apr 1995 15:55:58   mjs
// Added hImageLib
// 
//    Rev 1.1   23 Mar 1995 07:53:04   sbc
// Convert text editing
// 
//    Rev 1.0   16 Mar 1995 16:12:40   sbc
// Initial revision.
// 
//    Rev 1.46   12 Jun 1995 13:48:12   smh
// CSV export
// 
//    Rev 1.45   26 May 1995 16:22:12   pjm
// Add text for RTF extension and RRRTFX.DLL name.
// 
//    Rev 1.44   11 May 1995 15:46:46   mjs
// Handles for new cursors.
// 
//    Rev 1.43   09 May 1995 10:08:32   mjs
// Added hImgLib
// 
//    Rev 1.42   13 Apr 1995 18:42:20   dlm
// Added initializer for EditQuery, since I just removed a duplicate GLOBAL
//  for EditQuery from _filter.h, where it was declared near.
// 
//    Rev 1.41   12 Apr 1995 17:45:50   jpb
// remove WxLongCharCutoff
//
//    Rev 1.40   09 Mar 1995 13:23:52   jpb
// Add some keys for the Database preferences section
//
//    Rev 1.39   01 Feb 1995 17:12:02   jpb
// add Database section name
//
//    Rev 1.38   10 Jan 1995 14:40:00   sbc
// Remove unused "WxLineHite[]"
// 
//    Rev 1.37   01 Dec 1994 12:43:38   dlm
// Part of fix to RRW bug 2108, RSW bug 1443, supporting Ansi chars in
//  the SRT file itself.
// 
//    Rev 1.36   03 Nov 1994 08:56:12   sjo
// Making changes to support joining across directories and Data Sources for
// the 'Desktop' platforms.  Most changes are in DBI.C and iengmenu.c.  I also
// had to make changes to the 4 routines which called sql_tables and added 
// support for a new INI file setting.  Also added a new MFFiles structure
// member.
// 
//    Rev 1.35   28 Sep 1994 15:46:40   sbc
// FileOpenName -> Paths
// 
//    Rev 1.34   27 Sep 1994 18:11:44   jpb
// define QERevComp variable
// 
//    Rev 1.33   27 Sep 1994 10:42:46   sbc
// Add text string for INI file (script saver)
// 
//    Rev 1.32   15 Sep 1994 15:09:10   jpb
// get rid of magic connect / logon stuff - add AllowDoubleConnect
// 
//    Rev 1.32   15 Sep 1994 15:06:20   jpb
// get rid of magic connect/logon; add AllowDoubleConnect
// 
//    Rev 1.31   05 Sep 1994 14:43:22   jpb
// make logon dislog stuff visible to runtime
// 
//    Rev 1.30   02 Sep 1994 16:59:52   jpb
// support RSW logon/magic connect string
// 
//    Rev 1.29   19 Aug 1994 09:22:38   erp
// added check for multiple include
// 
//    Rev 1.28   05 Aug 1994 15:03:18   sbc
// New user & password pointers
// 
//    Rev 1.27   04 Aug 1994 15:48:52   sbc
// RSW connection/login strings, global
// 
//    Rev 1.26   04 Aug 1994 12:49:10   sbc
// Add comment status bar stuff
// 
//    Rev 1.25   01 Aug 1994 14:57:06   sbc
// Remove "ThreeOne" Boolean
// 
//    Rev 1.24   28 Jul 1994 11:00:44   smh
// Added INI file string "TemplateLib"
// 
//    Rev 1.23   13 Jul 1994 15:40:02   erp
// moved hInsDlg out of INTERACTIVE section so dinsfld.c could compile
// 
//    Rev 1.22   08 Jul 1994 13:46:52   mjs
// Added rects for caps and num lock panes.
// 
//    Rev 1.21   28 Jun 1994 10:10:00   dlm
// Added GLOBAL for hRuntimeDLL.
// 
//    Rev 1.20   15 Jun 1994 08:20:44   smh
// Define LPLABNAME
// 
//    Rev 1.19   14 Jun 1994 15:47:46   smh
// Added definitions for RRLABELS.INI and PrOptLabel for Avery Labels support.
// 
//    Rev 1.18   13 Jun 1994 08:57:10   sbc
// New string for INI file (Wizard EXE)
// 
//    Rev 1.17   08 Jun 1994 14:13:02   sbc
// Change instant report preference text for new File New UI
// 
//    Rev 1.16   09 May 1994 15:58:28   sbc
// New stuff for drag/drop
// 
//    Rev 1.15   28 Apr 1994 15:51:44   sbc
// Add separate band type variables for dbf/wks
// 
//    Rev 1.14   26 Apr 1994 09:35:02   dlm
// Added GLOBALs relating to new Preference setting allowing user to
//  choose among displaying fieldnames, data-dictionary descriptions, or
//  both in field lists.
// 
//    Rev 1.13   09 Mar 1994 15:33:42   sbc
// Some client rectangles are now conditional on RRMFC
// 
//    Rev 1.12   04 Mar 1994 16:54:40   say
// move all the runtime global strings to _runtime.h. They're only used
// by the runtime.
// 
//    Rev 1.11   01 Mar 1994 11:28:46   sbc
// 
//    Rev 1.10   01 Mar 1994 11:13:32   sbc
// Rename cursor handles
// 
//    Rev 1.9   01 Mar 1994 09:38:22   sbc
// Make old cursor handles conditional on RRMFC
// 
//    Rev 1.8   29 Dec 1993 13:34:24   smh
// Database export:  Added ExpBandType (for one)
// See Scott for complete list of files.
// 
//    Rev 1.7   09 Dec 1993 08:56:52   sbc
// Remove PrtChan & PrtCodes - obsolete
// 
//    Rev 1.6   09 Dec 1993 08:52:18   sbc
// Remove (PrRtn *)() - obsolete
// 
//    Rev 1.5   09 Dec 1993 08:49:48   sbc
// Remove PrintBuf - obsolete
// 
//    Rev 1.4   08 Dec 1993 17:12:22   sbc
// Remove MultSize - obsolete
// 
//    Rev 1.3   08 Dec 1993 16:57:50   sbc
// Remove LeftCol/OLeftCol - they're obsolete
// 
//    Rev 1.2   19 Nov 1993 17:38:28   sbc
// Add extern C for C++
// 
//    Rev 1.1   03 Nov 1993 14:20:40   say
// Remove a few header #includes by defining struct ptrs in terms of
// keywords (e.g. struct mffield far*   vs. LPMFFIELD)
// 
//    Rev 1.0   14 Oct 1993 10:12:44   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _GLOBAL_H_
//
// Make a definition for this module.
//
#define _GLOBAL_H_

//
// Turn extern on or off. When off, wglobal.c will instantiate them.
//
#ifdef WIN32
#include <wingdi.h>	// DEVMODE is in here now.
#else
// mjs  Had to comment this out due to brain-dead dependancy scan by MSVC 2.2.
// #include <print.h>	// for the DEVMODE structure
#endif

#include "wmain.h"			// for MESS_LEN and PDRVSZ
#include "print_.h"			// needed for BRKFLD
//#include "mfdata.h"
#include "wutil.h"			// needed for COLORS, also for (avoidable) LPOPENFILE
//#include "wband.h"


#if defined RSW
#include "sglobal.h"
#else
#include "xglobal.h"
#endif

#if defined _GLOBAL_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

// The following definitions are included here to avoid unnecessary
// header file dependencies.
typedef struct mffield far * LPMFFIELD;	// to avoid mffield.h
typedef struct mffile far * LPMFFILE;		// to avoid mffile.h
typedef struct rrbox far *LPRRBOX;			// to avoid wfield.h
typedef struct fieldhdr far * LPFLDHDR;		// to avoid wfield.h
typedef struct txfield far * LPTXFLD;		// to avoid wfield.h
typedef struct prtstruct far *LPPRT_STRUCT;	// to avoid pd.h
typedef struct prt_face far *LPPRT_FACE;	// to avoid wlayout.h
#if defined (INTERACTIVE)
typedef struct label_name far *LPLABNAME;	// to avoid dfile.h
#endif


// Initialized global variables.

GLOBAL COLORS near ColorTable[140] 	// compiler warns about unsized arrays
#if defined _GLOBAL_C_
 = {		// 140 RRW colors (added a bunch of new named colors from Microsoft list); note that original colors kept at top of list
	IDS_0270,RGB(0,0,0),
 	IDS_0271,RGB(128,0,0),
 	IDS_0272,RGB(0,128,0),
 	IDS_0273,RGB(128,128,0),
 	IDS_0274,RGB(0,0,128),
 	IDS_0275,RGB(128,0,128),
 	IDS_0276,RGB(0,128,128),
 	IDS_0277,RGB(128,128,128),
 	IDS_0278,RGB(192,192,192),
 	IDS_0279,RGB(255,0,0),
 	IDS_0280,RGB(0,255,0),
 	IDS_0281,RGB(255,255,0),
 	IDS_0282,RGB(0,0,255),
 	IDS_0283,RGB(255,0,255),
 	IDS_0284,RGB(0,255,255),
 	IDS_0285,RGB(255,255,255),
	IDS_5504,RGB(240, 248, 255),
	IDS_5505,RGB(250, 235, 215),
	IDS_5506,RGB(127, 255, 212),
	IDS_5507,RGB(240, 255, 255),
	IDS_5508,RGB(245, 245, 220),
	IDS_5509,RGB(255, 228, 196),
	IDS_5510,RGB(255, 235, 205),
	IDS_5511,RGB(138, 43, 226),
	IDS_5501,RGB(165, 42, 42),
	IDS_5512,RGB(222, 184, 135),
	IDS_5513,RGB(95, 158, 160),
	IDS_5514,RGB(127, 255, 0),
	IDS_5515,RGB(210, 105, 30),
	IDS_5516,RGB(255, 127, 80),
	IDS_5503,RGB(100, 149, 237),
	IDS_5517,RGB(255, 248, 220),
	IDS_5518,RGB(220, 20, 60),
	IDS_5519,RGB(0, 255, 255),
	IDS_5520,RGB(0, 0, 139),
	IDS_5521,RGB(0, 139, 139),
	IDS_5522,RGB(184, 134, 11),
	IDS_5523,RGB(169, 169, 169),
	IDS_5502,RGB(0, 100, 0),
	IDS_5524,RGB(189, 183, 107),
	IDS_5525,RGB(139, 0, 139),
	IDS_5526,RGB(85, 107, 47),
	IDS_5527,RGB(255, 140, 0),
	IDS_5528,RGB(153, 50, 204),
	IDS_5529,RGB(139, 0, 0),
	IDS_5530,RGB(233, 150, 122),
	IDS_5531,RGB(143, 188, 143),
	IDS_5532,RGB(72, 61, 139),
	IDS_5533,RGB(47, 79, 79),
	IDS_5534,RGB(0, 206, 209),
	IDS_5535,RGB(148, 0, 211),
	IDS_5536,RGB(255, 20, 147),
	IDS_5537,RGB(0, 191, 255),
	IDS_5538,RGB(105, 105, 105),
	IDS_5539,RGB(30, 144, 255),
	IDS_5540,RGB(178, 34, 34),
	IDS_5541,RGB(255, 250, 240),
	IDS_5542,RGB(34, 139, 34),
	IDS_5543,RGB(220, 220, 220),
	IDS_5544,RGB(248, 248, 255),
	IDS_5545,RGB(255, 215, 0),
	IDS_5546,RGB(218, 165, 32),
	IDS_5547,RGB(173, 255, 47),
	IDS_5548,RGB(240, 255, 240),
	IDS_5549,RGB(255, 105, 180),
	IDS_5550,RGB(205, 92, 92),
	IDS_5551,RGB(75, 0, 130),
	IDS_5552,RGB(255, 255, 240),
	IDS_5553,RGB(240, 230, 140),
	IDS_5554,RGB(230, 230, 250),
	IDS_5555,RGB(255, 240, 245),
	IDS_5556,RGB(124, 252, 0),
	IDS_5557,RGB(255, 250, 205),
	IDS_5558,RGB(173, 216, 230),
	IDS_5559,RGB(240, 128, 128),
	IDS_5560,RGB(224, 255, 255),
	IDS_5561,RGB(250, 250, 210),
	IDS_5562,RGB(144, 238, 144),
	IDS_5563,RGB(211, 211, 211),
	IDS_5564,RGB(255, 182, 193),
	IDS_5565,RGB(255, 160, 122),
	IDS_5566,RGB(32, 178, 170),
	IDS_5567,RGB(135, 206, 250),
	IDS_5568,RGB(119, 136, 153),
	IDS_5569,RGB(176, 196, 222),
	IDS_5570,RGB(255, 255, 224),
	IDS_5571,RGB(50, 205, 50),
	IDS_5572,RGB(250, 240, 230),
	IDS_5573,RGB(255, 0, 255),
	IDS_5574,RGB(102, 205, 170),
	IDS_5575,RGB(0, 0, 205),
	IDS_5576,RGB(186, 85, 211),
	IDS_5577,RGB(147, 112, 219),
	IDS_5578,RGB(60, 179, 113),
	IDS_5579,RGB(123, 104, 238),
	IDS_5580,RGB(0, 250, 154),
	IDS_5581,RGB(72, 209, 204),
	IDS_5582,RGB(199, 21, 133),
	IDS_5583,RGB(25, 25, 112),
	IDS_5584,RGB(245, 255, 250),
	IDS_5585,RGB(255, 228, 225),
	IDS_5586,RGB(255, 228, 181),
	IDS_5587,RGB(255, 222, 173),
	IDS_5588,RGB(253, 245, 230),
	IDS_5589,RGB(107, 142, 35),
	IDS_5590,RGB(255, 165, 0),
	IDS_5591,RGB(255, 69, 0),
	IDS_5592,RGB(218, 112, 214),
	IDS_5593,RGB(238, 232, 170),
	IDS_5594,RGB(152, 251, 152),
	IDS_5595,RGB(175, 238, 238),
	IDS_5596,RGB(219, 112, 147),
	IDS_5597,RGB(255, 239, 213),
	IDS_5598,RGB(255, 218, 185),
	IDS_5599,RGB(205, 133, 63),
	IDS_5600,RGB(255, 192, 203),
	IDS_5601,RGB(221, 160, 221),
	IDS_5602,RGB(176, 224, 230),
	IDS_5603,RGB(188, 143, 143),
	IDS_5604,RGB(65, 105, 225),
	IDS_5605,RGB(139, 69, 19),
	IDS_5606,RGB(250, 128, 114),
	IDS_5607,RGB(244, 164, 96),
	IDS_5608,RGB(46, 139, 87),
	IDS_5609,RGB(255, 245, 238),
	IDS_5610,RGB(160, 82, 45),
	IDS_5611,RGB(135, 206, 235),
	IDS_5612,RGB(106, 90, 205),
	IDS_5613,RGB(112, 128, 144),
	IDS_5614,RGB(255, 250, 250),
	IDS_5615,RGB(0, 255, 127),
	IDS_5616,RGB(70, 130, 180),
	IDS_5617,RGB(210, 180, 140),
	IDS_5618,RGB(216, 191, 216),
	IDS_5619,RGB(255, 99, 71),
	IDS_5620,RGB(64, 224, 208),
	IDS_5621,RGB(238, 130, 238),
	IDS_5622,RGB(245, 222, 179),
	IDS_5624,RGB(245, 245, 245),
	IDS_5625,RGB(154, 205, 50)
 }
#endif
;

GLOBAL WORD near Hatches[] 
#if defined _GLOBAL_C_
 = { HS_BDIAGONAL,HS_CROSS,HS_DIAGCROSS,
 			  	HS_FDIAGONAL,HS_HORIZONTAL,HS_VERTICAL }
#endif
;

GLOBAL char near ps[] 						// format string
#if defined _GLOBAL_C_
 = "%s"
#endif
;

// Initialized global strings (from the old wrtext.c).

// ReadSrt stuff
GLOBAL char near Tcompar[] 
#if defined _GLOBAL_C_
 =	"COMPARISONS"
#endif
;
GLOBAL char near Tapprox[] 
#if defined _GLOBAL_C_
 =	"APPROXIMATE"
#endif
;
GLOBAL char near Tident[] 
#if defined _GLOBAL_C_
 =	"IDENTICAL"
#endif
;
GLOBAL char near Txcase[] 
#if defined _GLOBAL_C_
 =	"CASE"
#endif
;
GLOBAL char near Tcmpcase[] 
#if defined _GLOBAL_C_
 =	"COMPARECASE"
#endif
;
GLOBAL char near Tdstnct[] 
#if defined _GLOBAL_C_
 =	"DISTINCT"
#endif
;
GLOBAL char near Tcombnd[] 
#if defined _GLOBAL_C_
 =	"COMBINED"
#endif
;
GLOBAL char near Tdbchars[] 
#if defined _GLOBAL_C_
 =	"DBCHARS"
#endif
;
GLOBAL char near Tsrtchars[] 
#if defined _GLOBAL_C_
 =	"SRTCHARS"
#endif
;
GLOBAL char near Tansi[] 
#if defined _GLOBAL_C_
 =		"ANSI"
#endif
;
GLOBAL char near Toem[] 
#if defined _GLOBAL_C_
 =		"OEM"
#endif
;
GLOBAL char near Tibmpc[] 
#if defined _GLOBAL_C_
 =	"IBMPC"
#endif
;
GLOBAL char near Tsrtcase[] 
#if defined _GLOBAL_C_
 =	"SORTCASE"
#endif
;
GLOBAL char near Tspacedot[] 
#if defined _GLOBAL_C_
 =	"SPACEDOT"
#endif
;

// special, low memory error text (must not be in resource file)
GLOBAL char near WxNoPrtMem[] 
#if defined _GLOBAL_C_
 = "Insufficient memory for print/preview"
#endif
;
GLOBAL char near WxNoDlgMem[] 
#if defined _GLOBAL_C_
 = "Cannot display dialog box. Check available memory."
#endif
;
GLOBAL char near WxRR[] 
#if defined _GLOBAL_C_
 #ifdef RSW
 = "Cyberprise"
 #else
 = "R&R for Windows"
 #endif
#endif
;

// old text labels
GLOBAL char near Mx284[] 
#if defined _GLOBAL_C_
 = "GrSum"
#endif
;
GLOBAL char near Mx287[] 
#if defined _GLOBAL_C_
 = "DBF_rr"
#endif
;
GLOBAL char near Mx288[] 
#if defined _GLOBAL_C_
 = "Date_rr"
#endif
;
GLOBAL char near Mx289[] 
#if defined _GLOBAL_C_
 = "Time_rr"
#endif
;
GLOBAL char near Mx290[] 
#if defined _GLOBAL_C_
 = "Page_rr"
#endif
;
GLOBAL char near Mx291[] 
#if defined _GLOBAL_C_
 = "Recno_rr"
#endif
;
GLOBAL char near Mx292[] 
#if defined _GLOBAL_C_
 = "Query_rr"
#endif
;
GLOBAL char near Mx293[] 
#if defined _GLOBAL_C_
 = "Repname_rr"
#endif
;
GLOBAL char near Mx299[] 
#if defined _GLOBAL_C_
 = "DBF()"
#endif
;
GLOBAL char near Mx300[] 
#if defined _GLOBAL_C_
 = "DATE()"
#endif
;
GLOBAL char near Mx301[] 
#if defined _GLOBAL_C_
 = "TIME()"
#endif
;
GLOBAL char near Mx302[] 
#if defined _GLOBAL_C_
 = "PAGENO()"
#endif
;
GLOBAL char near Mx303[] 
#if defined _GLOBAL_C_
 = "RECNO()"
#endif
;
GLOBAL char near Mx304[] 
#if defined _GLOBAL_C_
 = "QUERY()"
#endif
;
GLOBAL char near Mx305[] 
#if defined _GLOBAL_C_
 = "REPNAME()"
#endif
;
//   screen columns for Print Specification FIELD information
GLOBAL BYTE near RpSpFC[] 
#if defined _GLOBAL_C_
 = {3,12,16,20,29,50,55,68,72,78,40,55,8}
#endif
;
//   screen columns for Print Specification CONDITIONAL LINE information
GLOBAL BYTE near RpSpLC[] 
#if defined _GLOBAL_C_
 = {8,18,24,46}
#endif
;
//   screen columns for Print Specification WHEN SCANNING information
GLOBAL BYTE near RpSpLS[] 
#if defined _GLOBAL_C_
 = {8,18,24}
#endif
;
//   screen columns for Print Specification LINE HEIGHT information
GLOBAL BYTE near RpSpLH[] 
#if defined _GLOBAL_C_
 = {8,18,24}
#endif
;
//   screen columns for Print Specification SORT/GROUP information
GLOBAL BYTE near RpSpSC[] 
#if defined _GLOBAL_C_
 = {5,28,30,53,61,65,69,73}
#endif
;

// The rest of this is alphabetical.
GLOBAL char near WxActionBar[] 
#if defined _GLOBAL_C_
 = "ActionBar"
#endif
;

#if defined(RSW)

#if defined INTERACTIVE
GLOBAL char near WxRWQExt[] 
#if defined _GLOBAL_C_
 = "RWQ"
#endif
;
GLOBAL char near WxReportWriterQuery[] 
#if defined _GLOBAL_C_
 = "ReportWriterQuery"
#endif
;
#endif	// INTERACTIVE

GLOBAL char near WxDoubleConnect[] 
#if defined _GLOBAL_C_
 = "DoubleConnect"
#endif
;
#endif

GLOBAL char near WxDBFExt[] 
#if defined _GLOBAL_C_
 = "DBF"
#endif
;
GLOBAL char near WxDBCExt[] 
#if defined _GLOBAL_C_
 = "DBC"
#endif
;
GLOBAL char near WxDefBM[] 
#if defined _GLOBAL_C_
 = "BotM"
#endif
;
GLOBAL char near WxDefFDoW[] 
#if defined _GLOBAL_C_
 =	"FirstDayOfWeek"
#endif
;
// Rev 1.52

GLOBAL char near WxDefBrowPop[] 
#if defined _GLOBAL_C_
 = "HTMLBrowserPopup"
#endif
; // Rev 1.50
GLOBAL char near WxDefColorInd[] 
#if defined _GLOBAL_C_
 = "Color"
#endif
;
GLOBAL char near WxDefDataDir[] 
#if defined _GLOBAL_C_
 = "DataDir"
#endif
;
GLOBAL char near WxDefDiB[] 
#if defined _GLOBAL_C_
 = "DisableHTMLBrowser"
#endif
; // Rev 1.50
GLOBAL char near WxDefFace[] 
#if defined _GLOBAL_C_
 = "FaceName"
#endif
;
GLOBAL char near WxDefImgDir[] 
#if defined _GLOBAL_C_
 = "ImgDir"
#endif
;
GLOBAL char near WxDefImgExt[] 
#if defined _GLOBAL_C_
 = "ImgExt"
#endif
;
GLOBAL char near WxDefLookupDir[] 
#if defined _GLOBAL_C_
 = "LookupDir"
#endif
;
GLOBAL char near WxDefKey[] 
#if defined _GLOBAL_C_
 = "Defaults"
#endif
;
GLOBAL char near WxDefFloatComp[] 
#if defined _GLOBAL_C_
 = "FloatCompTolerance"
#endif
;
GLOBAL char near WxDefLibDir[] 
#if defined _GLOBAL_C_
 = "LibDir"
#endif
;
GLOBAL char near WxDefLM[] 
#if defined _GLOBAL_C_
 = "LeftM"
#endif
;
GLOBAL char near WxDefLogF[] 
#if defined _GLOBAL_C_
 = "LogF"
#endif
;
GLOBAL char near WxDefLogT[] 
#if defined _GLOBAL_C_
 = "LogT"
#endif
;
GLOBAL char near WxDefMeasure[] 
#if defined _GLOBAL_C_
 = "DefMeas"
#endif
;
GLOBAL char near WxDefMemExt[] 
#if defined _GLOBAL_C_
 = "MemExt"
#endif
;
GLOBAL char near WxDefPgLM[] 
#if defined _GLOBAL_C_
 = "PgLM"
#endif
;
GLOBAL char near WxDefPts[] 
#if defined _GLOBAL_C_
 = "Pts"
#endif
;
GLOBAL char near WxDefPrinter[] 
#if defined _GLOBAL_C_
 = "Printer"
#endif
;
GLOBAL char near WxDefChartFontBase[] 
#if defined _GLOBAL_C_
 = "ChartFontBase"
#endif
;
GLOBAL char near WxDefChartFontTitle[] 
#if defined _GLOBAL_C_
 = "ChartFontTitle"
#endif
;
GLOBAL char near WxDefChartFontAxis[] 
#if defined _GLOBAL_C_
 = "ChartFontAxis"
#endif
;
GLOBAL char near WxDefChartFontLabel[] 
#if defined _GLOBAL_C_
 = "ChartFontLabel"
#endif
;
GLOBAL char near WxDefChartFontLegend[] 
#if defined _GLOBAL_C_
 = "ChartFontLegend"
#endif
;
GLOBAL char near WxDefChartPalette[] 
#if defined _GLOBAL_C_
 = "ChartPalette"
#endif
;
GLOBAL char near WxDefChartFontTitleSize[] 
#if defined _GLOBAL_C_
 = "ChartFontTitleSize"
#endif
;
GLOBAL char near WxDefChartFontAxisSize[] 
#if defined _GLOBAL_C_
 = "ChartFontAxisSize"
#endif
;
GLOBAL char near WxDefChartFontLabelSize[] 
#if defined _GLOBAL_C_
 = "ChartFontLabelSize"
#endif
;
GLOBAL char near WxDefChartFontLegendSize[] 
#if defined _GLOBAL_C_
 = "ChartFontLegendSize"
#endif
;
GLOBAL char near WxDefRM[] 
#if defined _GLOBAL_C_
 = "RightM"
#endif
;
GLOBAL char near WxDefRulPitch[] 
#if defined _GLOBAL_C_
 = "RulPit"
#endif
;
GLOBAL char near WxDefSnapTo[] 
#if defined _GLOBAL_C_
 = "SnapTo"
#endif
;
GLOBAL char near WxDefTemplate[] 
#if defined _GLOBAL_C_
 = "TemplateDir"
#endif
;
GLOBAL char near WxDefTM[] 
#if defined _GLOBAL_C_
 = "TopM"
#endif
;
GLOBAL char near WxDefVRulSp[] 
#if defined _GLOBAL_C_
 = "VRulPit"
#endif
;
GLOBAL char near WxFieldNames[] 
#if defined _GLOBAL_C_
 = "FieldNames"
#endif
;
GLOBAL char near WxFormatBar[] 
#if defined _GLOBAL_C_
 = "FormatBar"
#endif
;
GLOBAL char near WxCloseInsDlg[] 
#if defined _GLOBAL_C_
 = "CloseInsDlg"
#endif
;
GLOBAL char near WxDBKey[] 
#if defined _GLOBAL_C_
 = "Database"
#endif
;
GLOBAL char near WxFIF10[] 
#if defined _GLOBAL_C_
 = "10"
#endif
;
GLOBAL char near WxFIF12[] 
#if defined _GLOBAL_C_
 = "12"
#endif
;
GLOBAL char near WxFIFComp[] 
#if defined _GLOBAL_C_
 = "Compressed"
#endif
;
GLOBAL char near WxFIFCompPitch[] 
#if defined _GLOBAL_C_
 = "CompPitch"
#endif
;
GLOBAL char near WxFIFNone[] 
#if defined _GLOBAL_C_
 = "None"
#endif
;
GLOBAL char near WxIniExt[] 
#if defined _GLOBAL_C_
 = "INI"
#endif
;
GLOBAL char near WxLastLib[] 
#if defined _GLOBAL_C_
 = "Library32"
#endif
;
GLOBAL char near WxLastRep[] 
#if defined _GLOBAL_C_
 = "Report32"
#endif
;
GLOBAL char near WxLineDraw[] 
#if defined _GLOBAL_C_
 = "Courier-LD"
#endif
;
GLOBAL char near WxLongCharLimit[] 
#if defined _GLOBAL_C_
 = "LongCharLimit"
#endif
;
GLOBAL char near WxLongCharWrap[] 
#if defined _GLOBAL_C_
 = "LongCharWrap"
#endif
;
GLOBAL char near WxMemoLimit[] 
#if defined _GLOBAL_C_
 = "MemoLimit"
#endif
;
GLOBAL char near WxMemoWrap[] 
#if defined _GLOBAL_C_
 = "MemoWrap"
#endif
;
GLOBAL char near WxTestJoin[] 
#if defined _GLOBAL_C_
 = "TestJoin"
#endif
;
GLOBAL char near WxUseDefaultDB[] 
#if defined _GLOBAL_C_
 = "UseDefaultDatabase"
#endif
;

// apparently now obsolete
//GLOBAL char near WxMaximize[] 
//#if defined _GLOBAL_C_
// = "Maximize"
//#endif
;
GLOBAL char near WxPasteArgs[] 
#if defined _GLOBAL_C_
 = "PasteArgs"
#endif
;
GLOBAL char near WxPic1[] 
#if defined _GLOBAL_C_
 = "dd-mmm-yy"
#endif
;
GLOBAL char near WxPic2[] 
#if defined _GLOBAL_C_
 = "dd-mmm-yyyy"
#endif
;
GLOBAL char near WxPic3[] 
#if defined _GLOBAL_C_
 = "dd-mmm"
#endif
;
GLOBAL char near WxPic4[] 
#if defined _GLOBAL_C_
 = "mmm-yy"
#endif
;
GLOBAL char near WxPic5[] 
#if defined _GLOBAL_C_
 = "mmm-yyyy"
#endif
;
GLOBAL char near WxPic6[] 
#if defined _GLOBAL_C_
 = "mmmm d, yyyy"
#endif
;
GLOBAL char near WxPic7[] 
#if defined _GLOBAL_C_
 = "d mmmm yyyy"
#endif
;
GLOBAL char near WxPic8[] 
#if defined _GLOBAL_C_
 = "mmmm yyyy"
#endif
;
GLOBAL char near WxPic9[] 
#if defined _GLOBAL_C_
 = "mmmm d"
#endif
;
GLOBAL char near WxPic10[] 
#if defined _GLOBAL_C_
 = "d mmmm"
#endif
;
GLOBAL char near WxPic11[] 
#if defined _GLOBAL_C_
 = "mm/dd/yy"
#endif
;
GLOBAL char near WxPic12[] 
#if defined _GLOBAL_C_
 = "mm/dd/yyyy"
#endif
;
GLOBAL char near WxPic13[] 
#if defined _GLOBAL_C_
 = "dd/mm/yy"
#endif
;
GLOBAL char near WxPic14[] 
#if defined _GLOBAL_C_
 = "dd/mm/yyyy"
#endif
;
GLOBAL char near WxPic15[] 
#if defined _GLOBAL_C_
 = "dd.mm.yy"
#endif
;
GLOBAL char near WxPic16[] 
#if defined _GLOBAL_C_
 = "dd.mm.yyyy"
#endif
;
GLOBAL char near WxPic17[] 
#if defined _GLOBAL_C_
 = "yy-mm-dd"
#endif
;
GLOBAL char near WxPic18[] 
#if defined _GLOBAL_C_
 = "yyyy-mm-dd"
#endif
;
GLOBAL char near WxPic19[] 
#if defined _GLOBAL_C_
 = "mm/dd"
#endif
;
GLOBAL char near WxPic20[] 
#if defined _GLOBAL_C_
 = "dd/mm"
#endif
;
GLOBAL char near WxPic21[] 
#if defined _GLOBAL_C_
 = "dd.mm"
#endif
;
GLOBAL char near WxPic22[] 
#if defined _GLOBAL_C_
 = "mm-dd"
#endif
;
GLOBAL char near WxPrefInsRep[] 
#if defined _GLOBAL_C_
 = "FileNew"
#endif
;
GLOBAL char near WxPrefAutoSave[] 
#if defined _GLOBAL_C_
 = "AutoSave"
#endif
;
GLOBAL char near WxAutoSaved[] 
#if defined _GLOBAL_C_
 = "AutoSavedFile"
#endif
;
GLOBAL char near WxPrefFldLst[] 
#if defined _GLOBAL_C_
 = "FieldLists"
#endif
;
GLOBAL char near WxPrefKey[] 
#if defined _GLOBAL_C_
 = "Preferences"
#endif
;
GLOBAL char near WxCnfgKey[] 
#if defined _GLOBAL_C_
 = "Config"
#endif
; // Rev 1.50
GLOBAL char near WxPrefWinClr[] 
#if defined _GLOBAL_C_
 = "PrevWinClr"
#endif
;
GLOBAL char near WxPrtFormat[] 
#if defined _GLOBAL_C_
 = "%s on %s"
#endif
;
GLOBAL char near WxSaveKey[] 
#if defined _GLOBAL_C_
 = "Save List"
#endif
;
GLOBAL char near WxSaveVer[] 
#if defined _GLOBAL_C_
 = "IVer"
#endif
;
GLOBAL char near WxScrollHorz[] 
#if defined _GLOBAL_C_
 = "ScrBarHz"
#endif
;
GLOBAL char near WxScrollVert[] 
#if defined _GLOBAL_C_
 = "ScrBarVt"
#endif
;
GLOBAL char near WxBandClr[] 
#if defined _GLOBAL_C_
 = "BandClr"
#endif
;
GLOBAL char near WxBandClr1[] 
#if defined _GLOBAL_C_
 = "BandClr1"
#endif
;
GLOBAL char near WxSortFieldNames[] 
#if defined _GLOBAL_C_
 = "SortFieldNames"
#endif
;
GLOBAL char near WxShowGrid[] 
#if defined _GLOBAL_C_
 = "ShGrd"
#endif
;
//GLOBAL char near WxShowHRul[] 
//#if defined _GLOBAL_C_
// = "ShHzRul"
//#endif
//;
//GLOBAL char near WxShowVRul[] 
//#if defined _GLOBAL_C_
// = "ShVtRul"
//#endif
//;
GLOBAL char near WxShowTHRul[] 
#if defined _GLOBAL_C_
 = "ShTopHzRul"
#endif
;
GLOBAL char near WxShowBHRul[] 
#if defined _GLOBAL_C_
 = "ShBotHzRul"
#endif
;
GLOBAL char near WxShowLVRul[] 
#if defined _GLOBAL_C_
 = "ShLfVtRul"
#endif
;
GLOBAL char near WxShowRVRul[] 
#if defined _GLOBAL_C_
 = "ShRtVtRul"
#endif
;

GLOBAL char near WxSpcKey[] 
#if defined _GLOBAL_C_
 = "Special"
#endif
;
GLOBAL char near WxTXTExt[] 
#if defined _GLOBAL_C_
 = "TXT"
#endif
;
GLOBAL char near WxWKSExt[] 
#if defined _GLOBAL_C_
 = "XLS"
#endif
;

GLOBAL char near WxRTFExt[] 
#if defined _GLOBAL_C_
 = "RTF"
#endif
;

GLOBAL char near WxHTMLExt[] 
 #if defined _GLOBAL_C_
 = "HTM"
 #endif
;
GLOBAL char WxPDIExt[]
  #if defined _GLOBAL_C_
 = "pdi"
  #endif
;

//AMH 5/13/97 added 5 new keys for R?w.ini files
//new key #1
GLOBAL char WxPDIDir[]
  #if defined _GLOBAL_C_
 = "PdiDir"
  #endif
;

//new key #2
GLOBAL char WxInputLoc[]
  #if defined _GLOBAL_C_
 = "InputLoc"
  #endif
;

//new key #3
GLOBAL char WxControlLoc[]
  #if defined _GLOBAL_C_
 = "ControlLoc"
  #endif
;

//new key #4
GLOBAL char WxImageLoc[]
  #if defined _GLOBAL_C_
 = "ImageLoc"
  #endif
;

//new key #5
GLOBAL char WxHTMLDir[]
  #if defined _GLOBAL_C_
 = "HTMLPageDir"
  #endif
;

//new key #6
GLOBAL char WxViewerCtlWidth[]
  #if defined _GLOBAL_C_
 = "ViewerCtrlWidth"
  #endif
;

//new key #7
GLOBAL char WxViewerCtlHeight[]
  #if defined _GLOBAL_C_
 = "ViewerCtrlHeight"
  #endif
;
//AMH 5/13/97 end of new code

#ifdef INTERACTIVE
GLOBAL char near WxWizEXE[] 
#if defined _GLOBAL_C_
 = "WizardEXE"
#endif
;

GLOBAL char near WxSaveWizScript[] 
#if defined _GLOBAL_C_
 = "SaveWizScript"
#endif
;
#endif

#if defined INTERACTIVE
GLOBAL char near WxShowCalcComment[] 
#if defined _GLOBAL_C_
 = "ShowCalcComment"
#endif
;
#endif

//
// Moved out of INTERACTIVE section for dinsfld.c
//
#if defined INTERACTIVE

GLOBAL int near prRecText[]
 #if defined _GLOBAL_C_
 = { MxNonDel,MxDeletd,MxAllFor,NULL }
 #endif
 ;

#endif

// Moved out of mffile.h

GLOBAL char NEAR TDBFX []
 // #if defined (_MFGETFTB_C_)
 #if defined _GLOBAL_C_
	= ".DBF";	// extension of data file name
 #else
	;
 #endif

 GLOBAL char NEAR TDBFY []
 // #if defined (_MFGETFTB_C_)
 #if defined _GLOBAL_C_
	= "DBF";	// extension of data file name
 #else
	;
 #endif

GLOBAL char NEAR TDBTX []
 //#if defined (_MFGETFTB_C_)
 #if defined _GLOBAL_C_
	= ".DBT";	// extension of memo file name
 #else
	;
 #endif

GLOBAL char NEAR TFPTX []
 // #if defined (_MFGETFTB_C_)
 #if defined _GLOBAL_C_
	= ".FPT";	// extension of FoxPro memo file name
 #else
	;
 #endif

#if !defined RSW
GLOBAL char NEAR TFDBV []
 // #if defined (_MFGETFTB_C_)
 #if defined _GLOBAL_C_
	= ".DBV";	// extension of FlexFile II memo file name
 #else
	;
 #endif                                   
 
GLOBAL char NEAR TSSMT []
 // #if defined (_MFGETFTB_C_)
 #if defined _GLOBAL_C_
	= ".SMT";	// extension of Successware memo file name
 #else
	;
 #endif 
#endif

GLOBAL char NEAR TMFPAT []
 // #if defined (_MFGETFTB_C_)
 #if defined _GLOBAL_C_
	= "*.DBF"; // filename pattern for dBASE files
 #else
	;
 #endif

GLOBAL char NEAR TNTXY []
 // #if defined (_MFGETFTB_C_)
 #if defined _GLOBAL_C_
	= "NTX";	// extension (w/o dot) of index file name (Clipper)
 #else
	;
 #endif

// Moved out of wmain.h

// these were changed to near for class stuff
#if !defined(RSW)
GLOBAL char near WxCharFldWidthSize[]
 // #if defined _WINIT_C_
 #if defined _GLOBAL_C_
 = "CharFldWidthSize"
 #endif
;

GLOBAL char near WxSoftenDBFields[]
 // #if defined _WINIT_C_
 #if defined _GLOBAL_C_
 = "SoftenDBFields"
 #endif
;
#endif

GLOBAL char near WxExportKey[]
 // #if defined(_WINIT_C_)
 #if defined _GLOBAL_C_
 = "Export"
 #endif
;
GLOBAL char near WxCSVKeepNums[]
 // #if defined(_WINIT_C_)
 #if defined _GLOBAL_C_
 = "CSVKeepNumFormats"
 #endif
;
GLOBAL char near WxCSVKeepDates[]
 // #if defined(_WINIT_C_)
 #if defined _GLOBAL_C_
 = "CSVKeepDateFormats"
 #endif
;

GLOBAL char near WxUInfo[]			// R?W.INI user info section set by Setup
 // #if defined(_RRINIT_C_)
 #if defined _GLOBAL_C_
 = "User Info"
 #endif
;
GLOBAL char near WxUName[]
 // #if defined(_RRINIT_C_)
 #if defined _GLOBAL_C_
 = "UserName"
 #endif
;
GLOBAL char near WxCompany[]
 // #if defined(_RRINIT_C_)
 #if defined _GLOBAL_C_
 = "Company"
 #endif
;
GLOBAL char near WxNoRecHDR[]
 #if defined _GLOBAL_C_
 = "NoRecHDR"
 #endif
;

// Moved out of dfile.h

// I got these band names from dlplace.c (no page breaks in this list)
GLOBAL char near								ExpBandNames[]
// #if defined(_WEXPORT_C_)
 #if defined _GLOBAL_C_
 = {	INTITLE,INSUMMARY,INBODY,
		INBREAKH,INBREAKF,INBREAKH+1,
		INBREAKF+1,INBREAKH+2,INBREAKF+2,
		INBREAKH+3,INBREAKF+3,INBREAKH+4,
		INBREAKF+4,INBREAKH+5,INBREAKF+5,
		INBREAKH+6,INBREAKF+6,INBREAKH+7,
		INBREAKF+7,0
	}
#endif
;


// Moved out of pic.h
	// from wrepfix.c
GLOBAL int newD4[4]	// C++ doesn't like unsized and uninitialized arrays.
	// #if defined(_PICDATA_C_)
 #if defined _GLOBAL_C_
 = { picD41,picD42,picD43,picD44 }
 #endif
;

// Moved out of cfmisc.h

// These are single-character tokens for R&R calculated field expressions.
// They are organized here into a NULL-terminated table.  Some are also
// individually labeled for direct reference.
//
// NOTES: The order of the following list is crucial to the proper
//	 functioning of the formula compiler. It matches the order of
//	 a table of token codes in TOKEN.C
//
//	 The strings in the following list are duplicated in tcfchoic.asm.
//	 If you change one copy you must change the other as well.
//
//  Previously, TokCh2 referenced just the space character. It was
// tacked onto the front of TokCh and used in certain places where we
// needed to be concerned about spaces and TokCh2 was used when we did
// not need to be concerned about spaces.  We had problems with byte
// alignment so I created two tables.  The only difference between 
// TokCh and TokCh2 is that TokCh2 includes space.
// If you are adding an entry  to TokCh2 or TokCh, please make sure 
// that you add the entry to both tables.
//

GLOBAL char NEAR TokCh2	[] 
 // #if defined _COMPDATA_C_
 #if defined _GLOBAL_C_
			 = {
			' ',	// space - special entry, do not move (see token.c)
			'+',	// addition
			'-',	// subtraction
			'/',	// division
			'*',	// multiplication (two in a row are exponentiation)
			'^',	// exponentiation
			'%',	// percent of
			'(',	// left paren
			')',	// right paren
			',', 	// comma (argument separator)
			'=',	// equality test
	        '#',	// inequality test
			'<', 	// less than - used in   <    <=    and    <>
        	'>',	// greater than - used in    >     >=     and <>
			'$',	// substring
			'!',	// used internally by compiler after pre-pass
			'"',	// double quote string delimiter
			'\'',	// single quote string delimiter
			'[',	// left bracket string delimiter
			'{',	// left curly brace date delimiter
			'\0'}	// end of table
#endif
;

// If you are going to modify this, 
// please see the note above regarding TokCh2

GLOBAL char NEAR TokCh	[] 
 // #if defined _COMPDATA_C_
 #if defined _GLOBAL_C_
   			= {
			'+',	// addition
			'-',	// subtraction
			'/',	// division
			'*',	// multiplication (two in a row are exponentiation)
			'^',	// exponentiation
			'%',	// percent of
			'(',	// left paren
			')',	// right paren
			',',	// comma (argument separator)
			'=',	// equality test
			'#',	// inequality test
			'<', 	// less than - used in   <    <=    and    <>
        	'>',	// greater than - used in    >     >=     and <>
			'$',	// substring
			'!',	// used internally by compiler after pre-pass
          	'"',	// double quote string delimiter
           	'\'',	// single quote string delimiter
           	'[',	// left bracket string delimiter
			'{',	// left curly brace date delimiter
			'\0'}	// end of table
#endif 
;

// Moved from wband.h

GLOBAL char NEAR WxBandWidth[]
// #ifdef _WLEDIT_C_
 #if defined _GLOBAL_C_
 = "BandWidth"
#endif
;

GLOBAL char CmdLine[200];

#undef GLOBAL
#endif
