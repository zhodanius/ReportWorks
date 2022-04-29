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
// $Log:   H:/vcsmfc/h/wreport.h_v  $
// 
//    Rev 1.3   24 Jan 1996 11:06:40   par
// Add the real support for templates.  The te mplLibOpen flag was removed because it is no longer ne
// eded.  A new flag was created
// to prevent OnNewDocument() from being called when a template is created from a
// compound document.  The objects were getting deleted and the original storage
// was getting destoryed.  We can't have that and still keep the objects.
// 
//    Rev 1.2   25 Jul 1995 10:05:46   smh
// Classification.
// 
//    Rev 1.1   25 Apr 1995 15:10:48   smh
// Merged 6.1.03 and 7.0 headers.
// 
//    Rev 1.0   16 Mar 1995 16:14:04   sbc
// Initial revision.
// 
//    Rev 1.41   12 Apr 1995 17:45:34   jpb
// Change fileNew prototype
// 
//    Rev 1.40   15 Mar 1995 16:16:48   smh
// Moved connectAndChooseTable here so can call from dreport.c
// 
//    Rev 1.39   08 Feb 1995 17:14:36   dlm
// Part of rework of MRU List in File menu. MRU list is now read from
//  INI file at startup, maintained in memory (in the Paths structure),
//  and written on Exit; instead of constant reading and writing of the
//  INI file during the use of R&R.  Affected modules are: wreport.h,
//  wmain.h, wglobal.c, wrmain.c, winit.c, wreport.c, and mru.cpp which
//  was largely rewritten.
// 
//    Rev 1.38   18 Nov 1994 16:19:50   dlm
// Part of fix to localAlloc mess induced by YZNAME changes.  See also,
//  tstamp.c, dreport.c, wlib.c.
// Declare first three args of timestamp() to be far.
// 
//    Rev 1.37   11 Oct 1994 15:18:28   sbc
// Wizards: add some defines and change a function prototype
// 
//    Rev 1.36   28 Sep 1994 15:46:46   sbc
// FileOpenName -> Paths
// 
//    Rev 1.35   19 Sep 1994 12:28:10   sbc
// Change fileNewDlg argument
// 
//    Rev 1.34   16 Sep 1994 16:58:46   smh
// Added prototype for setLastTempl(), in wreport.c.
// 
//    Rev 1.33   15 Sep 1994 17:25:48   smh
// Added te mplLibOpen, flag to tell code last opened an RT5/6.
// 
//    Rev 1.32   15 Sep 1994 15:09:36   jpb
// get rid of a couple of unused externs
// 
//    Rev 1.31   14 Sep 1994 16:29:30   smh
// Prototype for hasRTExt, returns TRUE if passed file is .RT5/6.
// 
//    Rev 1.30   09 Sep 1994 16:08:32   mjs
// Moved adjustImages proto from wreport.c
// 
//    Rev 1.29   07 Sep 1994 13:45:38   sbc
// New function
// 
//    Rev 1.28   06 Sep 1994 14:51:24   sbc
// fileNewDlg() prototype
// 
//    Rev 1.27   02 Sep 1994 16:59:46   jpb
// support RSW logon/magic connect string
// 
//    Rev 1.26   31 Aug 1994 19:26:18   smh
// RI_RepPick: Moved repno & rname to dfile.h because wreport.c
// is not compiled in the runtime.
// 
//    Rev 1.25   04 Aug 1994 18:13:22   smh
// Changed timestamp() proto - no longer pass datasource control.
// 
//    Rev 1.24   03 Aug 1994 12:40:14   smh
// Report annotate - changed proto for timestamp
// 
//    Rev 1.23   02 Aug 1994 17:10:12   smh
// Report annotate - COMMENTLEN & RepNote.
// 
//    Rev 1.22   28 Jul 1994 10:58:58   smh
// Returned to original fileOpen prototype - had to use a global instead.
// Declared templLibRead global to indicate template lib read
// Moved newD4 here from wmain.h for Steve.
// 
//    Rev 1.21   27 Jul 1994 09:19:00   smh
// Changed "template" to "template_lib."  I guess it's a C++ keyword.
// 
//    Rev 1.20   26 Jul 1994 14:00:12   sbc
// New arg to fileNew()
// 
//    Rev 1.19   26 Jul 1994 12:45:30   smh
// Added "template" argument to fileOpen for template support.
// 
//    Rev 1.18   20 Jul 1994 07:40:54   sbc
// New global for File New dialog
// 
//    Rev 1.17   13 Jul 1994 09:51:48   erp
// cleaned up MRU API
// 
//    Rev 1.16   28 Jun 1994 15:03:50   erp
// Added MRU List Support
// 
//    Rev 1.15   20 Jun 1994 09:01:40   sbc
// New function prototype
// 
//    Rev 1.14   14 Jun 1994 11:46:54   sbc
// Script stuff
// 
//    Rev 1.13   09 Jun 1994 16:19:44   sbc
// Wizard changes
// 
//    Rev 1.12   09 Jun 1994 10:00:24   sbc
// Change arg
// 
//    Rev 1.11   08 Jun 1994 10:44:30   sbc
// New prototypes
// 
//    Rev 1.10   28 Apr 1994 10:16:30   sbc
// rname[] s/b CIPnameLENGTH bytes, not WINPATHLEN
// 
//    Rev 1.9   13 Apr 1994 10:57:28   dlm
// Added extern for setMenus().
// Added table-name argument to fileNew().
// 
//    Rev 1.8   28 Feb 1994 08:51:16   sbc
// Change fileOpen() to return BOOL
// 
//    Rev 1.7   25 Feb 1994 12:55:40   sbc
// Change fileNew from void to BOOL
// 
//    Rev 1.6   31 Jan 1994 09:53:38   say
// Add showPlatform, change timestamp args
// 
//    Rev 1.5   12 Jan 1994 14:34:10   say
// add arg to fileNew for RSW
// 
//    Rev 1.4   17 Dec 1993 16:55:56   say
// change name of connectDataSource to dataSourceDlgs for clarity
// 
//    Rev 1.3   10 Dec 1993 16:10:00   say
// Add arg to connectDataSource
// 
//    Rev 1.2   07 Dec 1993 16:54:48   say
// Add two, remove one func prototype for ODBC
// 
//    Rev 1.1   19 Nov 1993 17:41:18   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:11:10   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _WREPORT_H_

//
// Make a definition for this module.
//
#define _WREPORT_H_

#include "libio.h"			// for YYFILETAB
#include "pic.h"				// for picD4?

#if defined(_WREPORT_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif
//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
#define COMMENTLEN	100
// Wizard messages
#define WIZ_MESSAGE	0	// Sent from Wizards
#define WIZ_NOTIFY	1	// Sent by Notify code
#define WIZ_POST	2	// Sent to ourselves after receiving WIZ_MESSAGE

//
// QIDIGITS comes from the pacedefs.h file. It is only used in winst.c.
//
#define QIDIGITS        0x07    /* Number used as identifier    */

//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//



// *********************************************************************
//
// Function Prototypes Section:
// Place in this section any function prototypes
//

			// fileNewDlg prototype is in the wrong place, routine is defined in dfile\dfilenew.cpp
extern int fileNewDlg(BOOL bStartUp);
#if defined(INTERACTIVE)
			// openFileMaster prototype is in the wrong place, routine defined in wutil\wfile.cpp
//extern BOOL openFileMaster(HWND hWnd,PSTR file,PSTR stdir,int filter_id,PSTR defext,int title_id,WORD help);
extern BOOL readScriptFile(void);
#endif



#undef GLOBAL

#endif // end _WREPORT_H_

// *************************** End of File ************************************
