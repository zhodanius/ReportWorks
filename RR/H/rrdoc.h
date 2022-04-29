// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   rrdoc.h  $
// ================
//
// Description:
// ============
//
// 
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/RRDOC.H_V  $
// 
// Rev 1.316   04 Dec 2017 12:59:22   CAS
// Added three new properties to the core CRrDoc class to allow for
// saving the default printer at startup.  Resolves issue with R&R
// hanging on startup if certain network printers saved with the report
// no longer exist on the system.  Also changed prototype for getPrinterDriver()
// to allow for two arguments (the second boolean indicating whether to
// save the default printer)
//
// Rev 1.315   19 JUL 2017 16:06:12   CAS
// Added new variable for Windows INI default to control the first day
// of the week for calculations designed to handle this information
//
// Form is:
//
// FirstDayOfWeek=SU (also MO,TU,WE,TH,FR,SA)
//
// which will control the offset used in date calculations for determining
// the first day of the week.  The default is Sunday, which is day 0 (zero)
//
//    Rev 1.314   20 Oct 2004 07:21:12   Nick
// V 11. Bugs
// 
//    Rev 1.313   12 Oct 2004 09:28:44   Nick
// Tom Le changes
// 
//    Rev 1.312   11 Oct 2004 10:18:26   Nick
// V 11
// 
//    Rev 1.311   04 Oct 2004 10:03:46   Nick
// New routine
// 
//    Rev 1.310   20 Sep 2004 13:42:12   Nick
// List fields in dialog boxes
// 
//    Rev 1.309   09 Sep 2004 08:03:48   Nick
// New list control boxes
// 
//    Rev 1.308   01 Sep 2004 07:55:22   Nick
// New Replace dialog
// 
//    Rev 1.307   25 Aug 2004 07:54:00   Nick
// Version 10.5
// 
//    Rev 1.306   02 Jul 2004 12:11:52   Nick
// Many
// 
//    Rev 1.305   May 03 2004 16:33:58   Nick
// Add img_copy()
// 
//    Rev 1.304   Oct 03 2003 10:13:22   Admin
// Version 1.01.004
// 
//    Rev 1.303   May 13 2003 14:14:58   Admin
// Version 10.1
// 
//    Rev 1.302   Feb 06 2003 19:06:24   Admin
// Add variable for load of rrdd.dll (next version)
// 
//    Rev 1.301   Oct 24 2002 09:18:06   Admin
// Simplify and prettify
// 
//    Rev 1.300   Oct 07 2002 09:29:00   Admin
// Add setfieldkey() and modify InitParamFieldList()
// 
//    Rev 1.299   Sep 05 2002 12:23:46   Admin
// Query and parameter timeout changes
// 
//    Rev 1.298   Aug 12 2002 10:44:14   Admin
// Who knows?
// 
//    Rev 1.297   Jul 01 2002 15:26:02   Admin
// ?
// 
//    Rev 1.296   Apr 25 2002 11:43:52   Admin
// Some protos for CrDoc class
// 
//    Rev 1.295   Nov 29 2001 11:40:00   Administrator
// Save MAPI fields
// 
//    Rev 1.294   Jul 11 2001 14:19:54   nhubacker
// Add SetParamPic() for parameter dialog
// 
//    Rev 1.293   Apr 19 2001 14:59:24   nhubacker
// killRSBrowser()
// 
//    Rev 1.292   Apr 05 2001 12:23:04   nhubacker
// /Q for Abra runtime
// 
//    Rev 1.291   Mar 29 2001 11:44:52   nhubacker
// PDF print driver
// 
//    Rev 1.290   Mar 21 2001 10:02:24   nhubacker
// Bursting
// 
//    Rev 1.289   Mar 20 2001 15:33:50   nhubacker
// FlexLink status
// 
//    Rev 1.288   Feb 27 2001 15:40:32   nhubacker
// Bursting and printReport()
// 
//    Rev 1.287   Feb 23 2001 14:43:54   nhubacker
// New functions
// 
//    Rev 1.286   Dec 12 2000 15:56:04   nhubacker
// Add global GrPgNo
// 
//    Rev 1.285   Dec 05 2000 13:11:56   nhubacker
// Add routines for recreating user index files
// 
//    Rev 1.284   Nov 02 2000 11:39:02   nhubacker
// Color
// 
//    Rev 1.283   Nov 02 2000 10:16:02   nhubacker
// Index on the fly
// 
//    Rev 1.282   Sep 19 2000 11:25:42   nhubacker
// Add a variable for saving a new DBC name
// 
//    Rev 1.281   Sep 14 2000 10:01:44   nhubacker
// Serial number and Owner Id support
// 
//    Rev 1.280   May 10 2000 14:02:16   nhubacker
// Add arg reportType to 2 routines
// 
//    Rev 1.279   Mar 30 2000 11:55:14   ksinkel
// More result set changes
// 
//    Rev 1.278   Mar 13 2000 16:10:16   ksinkel
// Added export result set as a DBF file
// 
//    Rev 1.275   30 Nov 1998 10:25:18   wrr
// Y2K
// Code was edited by Jim Ballard for WO157953
// Copied fix to WO157933
// 
//    Rev 1.274.2.0   24 Aug 1998 16:29:20   wrr
// Y2K
// Code was edited by Jim Ballard for WO157953
// Copied fix to WO157933
// 
//    Rev 1.0   24 Aug 1998 15:51:46   wrr
// Initial revision.
// 
//    Rev 1.274   21 Jan 1998 12:14:10   smh
// OEM20001 merge
// 
//    Rev 1.273.1.0   19 Jan 1998 15:30:40   smh
// Remerged changes - let Jaye in to update PTF.
// 
//    Rev 1.273   19 Jan 1998 08:43:32   JSF
// PTF 20001 merge
// 
//    Rev 1.271.2.0.1.0   17 Dec 1997 12:05:24   JSF
// WO152304
// 
//    Rev 1.271.2.0   05 Nov 1997 14:42:30   jsf
// merge 8.0/2.0 base with charting PTF
// 
//    Rev 1.271.1.0   23 Oct 1997 14:40:50   jsf
// charting PTF 1
// 
//    Rev 1.271   16 Jun 1997 18:17:12   par
// New numbering convention for charts should reduce the number of unique 
// chart names.
// 
//    Rev 1.270   13 Jun 1997 17:10:02   dlm
// Added code to "delete confirmation" dialog to explain which if any charts
//  will be affected.
// Added code to verify that all value fields are zfNUMERIC in
//  PrepareForPrinting.
// Modules are: rrchart.cpp, rrchlist.cpp, ddelcon.cpp, mfdelcon.cpp,
//  mfrepfld.cpp, wprint.cpp, rrw.str, common.rc, resource.h, rrdoc.h,
//  wdialog.h, rrcompos.h, rrchart.h
// 
//    Rev 1.269   11 Jun 1997 15:42:42   jsf
// Added the variable bCanChart to the doc class and code to set it 
// by using bChartFields(). 
// The view now uses OnUpdateGotRepCanChart() to enable the chart button
// and menu choice.
// 
//    Rev 1.268   09 Jun 1997 17:33:24   jsf
// added functions for chart filters
// 
//    Rev 1.267   28 May 1997 17:23:42   par
// Save and restore chart defaults.
// 
//    Rev 1.266   27 May 1997 20:38:46   dlm
// Added new validity checks and a new CRrDoc function called 
//  ChartErrorMessage to convert an error enum value to a displayed message.
// Modules changed:
//  RRDOC.H, RRCHART.H, RRESOURCE.H
//  RRCHART.CPP, RRCHLIST.CPP, WPRINT.CPP
//  RRW.STR
// 
//    Rev 1.265   25 May 1997 17:47:46   jpb
// add some member functions for RRCNVRT
// 
//    Rev 1.264   15 May 1997 14:52:08   SRM
// change argument to chartToMF();  see prec.cpp for explanation
// 
//    Rev 1.263   15 May 1997 14:35:46   dlm
// Added declarations for ComputeChartGroup() and ComputeChartBandLine().
// 
//    Rev 1.262   14 May 1997 17:13:28   SRM
// damn!!  I made the chart-to-metafile function private by mistake
// 
//    Rev 1.261   14 May 1997 16:37:38   SRM
// add "generate metafile for chart" function
// 
//    Rev 1.260   14 May 1997 11:03:42   dlm
// Part of fix for charting of record data in headers.  In total.cpp we
//  now remember the most recent break level when we're capturing a non-total
//  value.  In rrdoc.h, added m_LastBreakLevel.  In rrchart.h, added
//  m_LastBreakLevel and functions to set/get it.  In rrchlist.cpp, added code
//  to set last break level when adding items to list and code to ItemCount to
//  decide when we've reached the end of a group of values.  In rrchitem.cpp,
//  added get/set functions for last break level.
// 
//    Rev 1.259   12 May 1997 13:32:12   SRM
// add argument to setRrChart()
// 
//    Rev 1.258   09 May 1997 18:10:04   par
// Wonderful charting stuff to handle selection, cut, paste, resize.
// 
//    Rev 1.257   09 May 1997 14:14:32   dlm
// Added m_bEditCharts and function declarations relating to updating of
//  field IDs associated with charts after report retrieve and field
//  deletion.
// 
//    Rev 1.256   07 May 1997 17:57:06   SRM
// include rrchart.h
// 
//    Rev 1.255   06 May 1997 10:56:42   jsf
// Added delChart() and zapChart()
// 
//    Rev 1.254   05 May 1997 15:13:16   par
// Removed A L I V E (spacing prevents search hits) and PDI _ EXPORT conditionals.
// From this point forward, this code will always be included in build.
// 
// 
//    Rev 1.253   02 May 1997 16:55:04   dlm
// Removed CHARTING conditionals.
// 
//    Rev 1.252   02 May 1997 16:32:38   par
// New image function to get palette.
// 
//    Rev 1.251   02 May 1997 15:41:02   jsf
// More support for CChartSheet as a right-click property dialog
// 
//    Rev 1.250   30 Apr 1997 15:03:10   jsf
// Added support for CChartSheet as a right-click property dialog
// 
//    Rev 1.249   29 Apr 1997 09:10:38   dlm
// Added NeedChartPass() declaration.
// 
//    Rev 1.248   21 Apr 1997 13:28:20   dlm
// Changed arguments to clrTot if CHARTING is defined, to fix problems
//  with charting of pre-processed totals.
// 
//    Rev 1.247   17 Apr 1997 16:05:18   par
// Removed duplicate variable.
// 
//    Rev 1.246   08 Apr 1997 12:35:08   par
// openDirDialog is needed everywhere.
// 
//    Rev 1.245   06 Apr 1997 13:08:28   pjm
// Add/change some DBC-related stuff.
// 
//    Rev 1.244   03 Apr 1997 21:09:34   pjm
// More DBC-related stuff.
// 
//    Rev 1.243   27 Mar 1997 15:03:36   dlm
// More charting changes.
// 
//    Rev 1.242   27 Mar 1997 10:22:44   dlm
// Another round of charting code with stuff conditional on CHARTING.
// 
//    Rev 1.241   19 Mar 1997 10:02:34   pjm
// Add Visual FOxPro DBC-related stuff.
// 
//    Rev 1.240   14 Mar 1997 16:21:14   SRM
// chart support initial checkin
// 
//    Rev 1.239   14 Mar 1997 14:38:32   jpb
// equitrac runtime scripting support
// 
//    Rev 1.238   12 Mar 1997 13:34:54   jsf
// fix for RSW 2396, copy report when report is locked by another user.
// 
//    Rev 1.237   07 Mar 1997 17:09:22   jpb
// equitrac runtime scripting support
// 
//    Rev 1.236   05 Mar 1997 18:02:58   jpb
// equitrac runtime scripting support
// 
//    Rev 1.235   05 Mar 1997 13:15:06   sp
// removed condtionals so that the runtime can open the browser after an
// HTML export
// 
//    Rev 1.234   04 Mar 1997 16:02:14   sp
// support added for preview after export
// 
//    Rev 1.233   03 Mar 1997 15:02:06   amh
// Added new member variable to CRrdoc class for RRW right-click send to fax
// 
//    Rev 1.232   01 Mar 1997 17:22:06   jpb
// make readScriptFile public
// 
//    Rev 1.231   26 Feb 1997 16:31:56   jsf
// fixes RSW 2392, variable PrintType in RRDoc class
// was 41 bytes via constant PTYPESZ, now it is 81. 
// 
//    Rev 1.230   25 Feb 1997 17:41:38   amh
// Added code for Right-Click Send to Fax
// 
//    Rev 1.229   19 Feb 1997 14:57:04   dlm
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
//    Rev 1.228   10 Feb 1997 10:02:26   sp
// Arp Live merge to trunk
// 
//    Rev 1.223.1.4   08 Jan 1997 16:21:14   sp
// added definition of Load AllFonts to
// used to load fonts if there are no printers installed
// 
//    Rev 1.223.1.3   30 Dec 1996 11:12:14   sp
// added iRecAcross as last parm to definition of AddTableEntry
// 
//    Rev 1.223.1.2   03 Dec 1996 11:26:36   smh
// Add functions for PDI export w/o printer
// 
//    Rev 1.223.1.1   06 Nov 1996 15:14:16   sp
// added new function GetFontName to return a font name from a given HFONT
// 
//    Rev 1.223.1.0   05 Nov 1996 11:29:14   sp
// Added declarations for AddTableEntry And GetPositionPix
// 
//    Rev 1.226   16 Jan 1997 16:02:04   pjm
// Add SArg member to doc class (also changed rrdoc.cpp, wrtmain.cpp
// and wnextjob.cpp).
// 
//    Rev 1.225   29 Oct 1996 18:29:26   jpb
// Stay in RepPick on cancel from DS config: rrdoc.h, rrcompos.h
//  dreport.cpp, dbi.cpp, wrun.cpp, wreport.cpp wfile.cpp
// 
//    Rev 1.224   17 Oct 1996 18:24:36   jpb
// fix VarFileInfo charset
// 
//    Rev 1.223   08 Oct 1996 16:50:12   amh
// Arp 1.0 U02 merged to trunk
// 
// 
//
//    Rev 1.218.1.5   05 Sep 1996 17:55:30   jpb
// script changes
// 
//    Rev 1.218.1.4   01 Aug 1996 09:17:16   sjo
// Fixed compile problems.
// 
//    Rev 1.218.1.2   11 Jul 1996 09:27:06   smh
// Added buffer size argument to TruncatePath.
// 
//    Rev 1.218.1.1   03 Jul 1996 16:28:26   dlm
// Additional work on RRW bug 2887 involving dialog hook routines.  Modules
//  affected are: dfilenew.cpp, rrdoc.cpp, wdialog.cpp, rrdoc.h.  In dfilenew,
//  we now use a new doc member variable named fileNewHookLink instead of
//  hookLink, which is now reserved for use by hookOn/Off in wdialog.cpp.
//  We also now reset hookLink or fileNewHookLink to 0 after unhooking.
// 
//    Rev 1.218.1.0   03 Jul 1996 11:59:20   dlm
// Allowed multiple Viewer's to open same compound-file report by making
//  a copy and opening the copy.  Remember name of temp in CRrDoc->
//  m_TempReportName and clean up in doc destructor.
//    H:\VCSMFC\H\RRDOC.H_V  Rev 1.222
// // 
//    Rev 1.222   29 Sep 1996 15:19:34   jpb
// script change from U02 branch
// 
//    Rev 1.221   11 Jul 1996 09:32:00   smh
// Made 1.218.1.2 change.
// 
//    Rev 1.218.1.2   11 Jul 1996 09:27:06   smh
// Added buffer size argument to TruncatePath.
// 
//    Rev 1.218.1.1   03 Jul 1996 16:28:26   dlm
// Additional work on RRW bug 2887 involving dialog hook routines.  Modules
//  affected are: dfilenew.cpp, rrdoc.cpp, wdialog.cpp, rrdoc.h.  In dfilenew,
//  we now use a new doc member variable named fileNewHookLink instead of
//  hookLink, which is now reserved for use by hookOn/Off in wdialog.cpp.
//  We also now reset hookLink or fileNewHookLink to 0 after unhooking.
// 
//    Rev 1.218.1.0   03 Jul 1996 11:59:20   dlm
// Allowed multiple Viewer's to open same compound-file report by making
//  a copy and opening the copy.  Remember name of temp in CRrDoc->
//  m_TempReportName and clean up in doc destructor.
// 
//    Rev 1.218   06 Jun 1996 14:22:02   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.217   23 Apr 1996 13:57:16   pjm
// Add oAlias member and change args to fixUpReport to allow us to
// update aliases in Excel export field lists (RRW 2477/RSW 1912).
//
//    Rev 1.216   08 Apr 1996 15:47:26   dlm
// Add support for new /DL command-line argument in runtime.
// 
//    Rev 1.215   01 Apr 1996 19:40:28   dlm
// Get rid of createLib() and crLib() and calls to them.  This came as a
//  result of retrieving from an RP1 and trying to save to it.
// 
//    Rev 1.214   28 Mar 1996 12:04:46   par
// Add wizard timer definitions.
// 
//    Rev 1.213   27 Mar 1996 14:16:52   jpb
// add DateTimeCharCount()
// 
//    Rev 1.212   28 Feb 1996 16:57:14   dlm
// Some change that sbc made today.  (h_v file was lost in the process
//  and we've done a week-old restore.)  I'm now checking in header
//  from reference directory.
// 
//    Rev 1.0   28 Feb 1996 14:13:18   sbc
// Initial revision.
// 
//    Rev 1.211   22 Feb 1996 17:45:34   dlm
// Derive CRrDoc from CDocument instead of COleLinkingDoc in RUNDLL mode.
// 
//    Rev 1.210   21 Feb 1996 13:53:38   dlm
// Condtionaled some stuff out in RUNDLL mode.
// 
//    Rev 1.209   20 Feb 1996 10:42:54   jpb
// remove DA RW integration routines, etc, for runtime
// 
//    Rev 1.208   16 Feb 1996 20:15:08   jpb
// DA RW integration
// 
//    Rev 1.206   14 Feb 1996 17:22:22   dlm
// Added pointer to RDTable object to document object when used in
//  runtime DLL.
// 
//    Rev 1.205   07 Feb 1996 16:10:42   sbc
// Changes for serial number support
// 
//    Rev 1.204   24 Jan 1996 11:06:42   par
// Add the real support for templates.  The te mplLibOpen flag was removed because it is no longer ne
// eded.  A new flag was created
// to prevent OnNewDocument() from being called when a template is created from a
// compound document.  The objects were getting deleted and the original storage
// was getting destoryed.  We can't have that and still keep the objects.
// 
//    Rev 1.203   22 Jan 1996 18:03:38   par
// The template library has changed to a template directory.  Removed references
// to the last library.
// 
//    Rev 1.202   18 Jan 1996 12:52:32   sbc
// Add another flavor of errorMessage() for icon control
// 
//    Rev 1.201   12 Jan 1996 16:10:26   sbc
// Add dlgHelpCode and m_lcr for 2D alignment changes
// 
//    Rev 1.200   11 Jan 1996 16:05:52   dlm
// Added some stuff for use by runtime DLL.
// 
//    Rev 1.199   11 Jan 1996 11:55:42   pjm
// Make some libio stuff public for RRCNVRT.
// 
//    Rev 1.198   10 Jan 1996 12:52:42   par
// Instead of maintaining a separate selection pointer that is used to determine if
// an OLE object is selected, the OLE code now uses the R&R CurFld to determine
// if an OLE object is currently selected.
// 
//    Rev 1.197   05 Jan 1996 16:31:28   par
// All explicitly linked modules and external initialization files are located
// with the explicit file manager.  This will provide a central location where
// file paths can be adjusted.
// 
//    Rev 1.196   29 Dec 1995 13:59:24   dlm
// Added conditionals to allow use in runtime DLLs.
// 
//    Rev 1.195   17 Dec 1995 16:06:20   smh
// Added openFileDSOverride & tryDataSource, RSW data source override rtns.
// 
//    Rev 1.194   15 Dec 1995 16:12:44   par
// ..\srvr.txt
// 
//    Rev 1.193   15 Dec 1995 14:19:56   sjo
// Changes for the runtime to get reppick to start working.
// 
//    Rev 1.192   15 Dec 1995 11:10:38   jpb
// runtime
// 
//    Rev 1.191   14 Dec 1995 13:46:14   dlm
// Make yysetext() public for benefit of runtime DLLs.
// 
//    Rev 1.190   14 Dec 1995 13:12:26   sjo
// Moved OnOpenDoc to public so it can be called from the runtime.
// 
//    Rev 1.189   13 Dec 1995 17:28:22   par
// Added new CSummaryInfo class to repio as a way of grouping the file properties.
// Moved Rep Note into that class an called it m_cs Comment.
// 
//    Rev 1.188   13 Dec 1995 11:39:00   par
// When a library is open, make sure the File Send Mail uses the title and not
// the pathname.
// 
//    Rev 1.187   13 Dec 1995 09:16:42   smh
// No longer have OpenDlgCommon, now initOfn & freeOfn surround
// a DoModal instead.
// 
//    Rev 1.186   11 Dec 1995 16:32:56   sbc
// Make message map declaration conditional on INTERACTIVE
// 
//    Rev 1.185   11 Dec 1995 13:24:12   sbc
// Move bandText() here from band class.  Add runtime conditionals.
// 
//    Rev 1.184   11 Dec 1995 11:08:02   par
// Replaced report summary with file properties dialog.
// 
//    Rev 1.183   08 Dec 1995 14:57:58   sjo
// Making changes to remove link errors from the runtime.  This mostly involves
// removing functions from runtime version of the Doc or mainframe class.
// 
//    Rev 1.182   07 Dec 1995 10:38:44   smh
// Call old common dialog code rather than Win95-specific stuff
// when run under Win NT 3.51.
// 
//    Rev 1.181   06 Dec 1995 16:54:12   sjo
// Added some conditionals for the runtime.
// 
//    Rev 1.180   06 Dec 1995 14:13:24   sjo
// Added interactive conditionals for the runtime.
// 
//    Rev 1.179   06 Dec 1995 11:10:44   par
// Remove region code.
// 
//    Rev 1.178   05 Dec 1995 18:50:08   jpb
// move export stuff to CRrExport class
// 
//    Rev 1.177   05 Dec 1995 17:02:10   par
// Copy con use Get Next Ole Object instead of Get Next Item.  This should prevent
// server objects from getting mixed up.
// 
//    Rev 1.176   05 Dec 1995 15:22:34   sbc
// Add new function (wreport.cpp) for open/save report UI
// 
//    Rev 1.175   05 Dec 1995 10:31:30   sjo
// Changes for the runtime.
// 
//    Rev 1.174   01 Dec 1995 12:55:14   dlm
// Added declaration for ForgetCompoundFile().
// 
//    Rev 1.173   30 Nov 1995 17:53:52   sjo
// Changes required for the runtime port to 32 bit MFC.
// 
//    Rev 1.172   29 Nov 1995 15:07:18   sbc
// Remove globalHeapMin()
// 
//    Rev 1.171   28 Nov 1995 18:37:22   jpb
// 
//    Rev 1.170   28 Nov 1995 17:59:18   par
// Use SaveModified() as the central location to prompt to save edits.  This elimints the dual save p
// rompts.
// 
//    Rev 1.169   28 Nov 1995 11:19:16   sbc
// Change hCurrentTask (HTASK) to dwCurrentTaskId (DWORD)
// 
//    Rev 1.168   27 Nov 1995 11:27:02   sbc
// Change ruler spacing calls
// 
//    Rev 1.167   22 Nov 1995 14:23:56   sbc
// Convert insert field dialog to MFC
// 
//    Rev 1.166   17 Nov 1995 11:42:30   jpb
// runtime build cleanup
// 
//    Rev 1.165   17 Nov 1995 10:36:22   mjs
// Changed file i/o for wiz.cpp
// 
//    Rev 1.164   16 Nov 1995 15:24:24   sjo
// Added a couple of routines and moved some around for command line processing.
// 
//    Rev 1.163   15 Nov 1995 17:30:36   par
// Converted the use of Rp Change to the use of Set Rr Modified() and 
// Is Rr Modified().
// 
//    Rev 1.162   14 Nov 1995 15:55:12   par
// Disable FileSendMail unless GotReport.
// 
//    Rev 1.161   10 Nov 1995 15:20:30   smh
// Made CompoundFileDoc routine public.
// 
//    Rev 1.160   10 Nov 1995 15:12:18   dlm
// Added OnFileSave and OnFileSaveAs as member functions to fix bug where
//  doing File-Save after retrieving from a library did mysterious things.
// 
//    Rev 1.159   08 Nov 1995 22:44:34   jpb
// add updateDisplayBits prototype
// 
//    Rev 1.158   08 Nov 1995 16:19:58   smh
// Changed size of CIPnameLENGTH buffers to REPNAMELENGTH,
// Changed setTitleText arguments in hiding file exts,
// And added getDisplayName to get Win95 file names.
// 
//    Rev 1.157   07 Nov 1995 18:39:54   sjo
// Moved setTitleText from a private member to a public member, so it can be
// called from checkArgs in cmdline.cpp.
// 
//    Rev 1.156   07 Nov 1995 18:28:44   dlm
// Added boolean to indicate whether we have a "current" library.
// Added argument to rpinit() to tell it whether we're retrieving or creating.
// 
//    Rev 1.155   06 Nov 1995 11:57:44   sbc
// New functions
// 
//    Rev 1.154   03 Nov 1995 13:52:54   dlm
// First pass at compound file report storage.
// 
//    Rev 1.153   03 Nov 1995 09:04:38   smh
// Moved getHelpPath() to CRrApp.
// 
//    Rev 1.152   01 Nov 1995 16:29:26   sbc
// Add text field properties function
// 
//    Rev 1.151   31 Oct 1995 12:00:34   par
// Add the support functions for creating ole object print records.  Also added
// the support to print the ole object records inside the printer driver.
// 
//    Rev 1.150   30 Oct 1995 16:58:38   par
// Add nPageOleObjects variable.
// 
//    Rev 1.149   30 Oct 1995 10:25:34   smh
// Changes for new common file dialog and SHBrowseForFolder
// 
//    Rev 1.148   27 Oct 1995 11:11:04   sbc
// Add a class pointer and remove some obsolete print dialog stuff
// 
//    Rev 1.147   25 Oct 1995 14:37:04   par
// Override SetModifiedFlag() so that internal MFC flag does not get set.
// R&R currently uses an external flag.
// 
//    Rev 1.146   24 Oct 1995 10:24:26   pjm
// Removed IconWidth and IconHeight (not longer used).
// 
//    Rev 1.145   20 Oct 1995 14:30:28   sbc
// WRECT changed to RECT in field header
// 
//    Rev 1.144   20 Oct 1995 13:33:50   par
// The OLE objects are now connected to the R&R lists. More work needs to be done but this is a good 
// start.
// 
//    Rev 1.143   18 Oct 1995 17:29:20   dlm
// Fixed RSW compile errors resulting from new CRrRepIO class.
// 
//    Rev 1.142   18 Oct 1995 14:22:14   dlm
// Defined new CRrRepIO class and modified necessary sources and headers
//  to use it.
// 
// 
//    Rev 1.141   13 Oct 1995 15:27:00   par
// Added and enabled the basic OLE container stuff.  It works but it cannot save
// or print.
// 
//    Rev 1.140   10 Oct 1995 10:10:34   pjm
// Changed prototypes for copyBox and copyImage.  Part of fix (with
// wglobal, wbitmap and wbox) for dealing with globalReAlloc issues
// when copying lines/boxes/images.
// 
//    Rev 1.139   09 Oct 1995 16:51:22   sbc
// Remove printDialog() and add new function for common print dialog
// 
//    Rev 1.138   05 Oct 1995 09:20:06   sbc
// Another paper size change
// 
//    Rev 1.137   04 Oct 1995 16:51:46   sbc
// Change getPaperInfo arguments
// 
//    Rev 1.136   04 Oct 1995 12:30:22   sbc
// Change paper bin names and types
// 
//    Rev 1.135   29 Sep 1995 16:23:08   sbc
// Remove prOptDialog prototype
// 
//    Rev 1.134   25 Sep 1995 17:29:52   sjo
// Fixed a size problem between UTWO and FLDIDs.
// 
//    Rev 1.133   22 Sep 1995 10:54:04   pjm
// Made rprepfld() public.
// 
//    Rev 1.132   22 Sep 1995 09:21:46   dlm
// FLDID-related edits.
// 
//    Rev 1.131   21 Sep 1995 15:30:46   sbc
// FLDID Changes
// 
//    Rev 1.130   21 Sep 1995 12:35:28   mjs
// Use FLDID in line_log_page
// 
//    Rev 1.129   21 Sep 1995 10:58:40   mjs
// initFldList now takes a FLDID.
// 
//    Rev 1.128   21 Sep 1995 10:02:00   sbc
// Changes to FLDID
// 
//    Rev 1.127   20 Sep 1995 17:32:44   sbc
// Prototype change
// 
//    Rev 1.126   20 Sep 1995 16:37:30   sbc
// Change imbedcode() arguments
// 
//    Rev 1.125   20 Sep 1995 15:01:06   jpb
// move ndxupd to rrcomposite class
// 
//    Rev 1.124   20 Sep 1995 10:52:04   jpb
// zapfield changes
// 
//    Rev 1.123   19 Sep 1995 12:59:26   sbc
// Remove argument to ckAbort()
// 
//    Rev 1.122   18 Sep 1995 14:40:06   jpb
// first pass, rrcomposite class
// 
//    Rev 1.121   17 Sep 1995 18:47:30   par
// libdir and other functions needed to be made static because they were
// being called by other static functions.
// 
//    Rev 1.120   15 Sep 1995 17:59:46   par
// sxvaldel needed a parameter adjustment to be compatible with other functions.
// TWO was used instead of int.  sxlvlerr needed to take a UTWO to be compatible
// 
//    Rev 1.119   14 Sep 1995 16:39:08   mjs
// Changed some WORDs in the fld list stuff.
// 
//    Rev 1.118   14 Sep 1995 08:50:32   sbc
// Commented out local memory functions and changed several globals
// 
//    Rev 1.117   13 Sep 1995 17:33:04   smh
// made sizecnt a DWORD, it holds DeviceCapabilities return.
// 
//    Rev 1.116   13 Sep 1995 14:16:14   smh
// scott's 32-bit changes.
// 
//    Rev 1.115   12 Sep 1995 10:10:54   sjo
// Variable name changes.
// 
//    Rev 1.114   11 Sep 1995 15:57:48   mjs
// Changed prototypes for WUTIL fns that changed for WIN32.
// 
//    Rev 1.113   11 Sep 1995 11:14:50   sjo
// 32-bit changes for the cf directories.
// 
//    Rev 1.112   08 Sep 1995 11:33:14   sbc
// Remove some obsolete handles used in wiz.cpp
// 
//    Rev 1.111   06 Sep 1995 16:18:30   sbc
// 32-bit changes
// 
//    Rev 1.110   06 Sep 1995 15:57:46   jpb
// change bActive arg type in mfxfld.cpp routines
// 
//    Rev 1.109   05 Sep 1995 17:13:54   jpb
// change second arg of tswrite to HFILE
// 
//    Rev 1.108   05 Sep 1995 16:38:40   dlm
// Changes for 32-bit-ification.
// 
//    Rev 1.107   05 Sep 1995 16:29:48   dlm
// Changes for 32-bit-ification.
// 
//    Rev 1.106   30 Aug 1995 17:30:00   dlm
// Fix to save-report code by correcting routine-ptr arg to saveRep.
// 
//    Rev 1.105   29 Aug 1995 16:17:34   sbc
// For Dave: make yzncomp NOT a member function.  Fix several CALLBACKs that
// weren't static
// 
//    Rev 1.104   23 Aug 1995 15:12:46   sbc
// Remove MainDC
// 
//    Rev 1.103   23 Aug 1995 08:30:10   sbc
// Remove hResource (no more resource DLL)
// 
//    Rev 1.102   18 Aug 1995 14:49:02   mjs
// Removed global.h and other headers containing strings.
// 
//    Rev 1.101   17 Aug 1995 14:58:44   mjs
// Removed xtra copies of SortFlat and CompFlat.  They left me flat.
// 
//    Rev 1.100   17 Aug 1995 14:40:18   pjm
// Added stuff I missed the first time.
// 
//    Rev 1.99   17 Aug 1995 12:48:30   sbc
// Remove functab (still in functab.cpp) and some preview stuff
// 
//    Rev 1.98   16 Aug 1995 15:12:50   jpb
// remove defs from swrepcpy - xwrepcpy used in both prods
// 
//    Rev 1.97   16 Aug 1995 10:22:50   sjo
// Problem with RSW conditional & fileNew.
// 
//    Rev 1.96   15 Aug 1995 16:21:30   sjo
// Changes for RSW compiles.
// 
//    Rev 1.95   15 Aug 1995 09:11:38   mjs
// Fixed RSW errors.
// 
//    Rev 1.94   11 Aug 1995 17:11:52   jpb
// Second cleanup pass for RSW
// 
//    Rev 1.93   11 Aug 1995 10:01:22   dlm
// Changed arg list for DBIdataSourceIdentifierQuoteChar() from PSTR to LPSTR.
// 
//    Rev 1.92   07 Aug 1995 15:10:06   sbc
// More fixes for RSW sources
// 
//    Rev 1.91   07 Aug 1995 14:25:14   sbc
// Fix some RSW stuff
// 
//    Rev 1.90   03 Aug 1995 09:39:32   jpb
// Fix part of rsw 1882
// 
//    Rev 1.89   02 Aug 1995 11:07:30   sjo
// Fixed a problem with lpszTP variables, which were moved to cfmisc.h.
// 
//    Rev 1.88   02 Aug 1995 10:22:54   pjm
// Added stuff from util\rrw.
// 
//    Rev 1.87   02 Aug 1995 09:10:58   sbc
// Remove onField() prototype, which is in CRrView.
// 
//    Rev 1.86   01 Aug 1995 14:10:26   sbc
// Move stuff from rrview.h
// 
//    Rev 1.85   01 Aug 1995 13:51:52   sbc
// Uncomment printerSetup() function
// 
//    Rev 1.84   01 Aug 1995 13:28:22   mjs
// Made some dfile\dreport functions public, so they can be called from
// static dialog procs.
// 
//    Rev 1.83   01 Aug 1995 12:29:22   sbc
// Fix callbacks
// 
//    Rev 1.82   31 Jul 1995 17:52:46   dlm
// Pass 2 of classification.  Fixing new compile errors.
// 
//    Rev 1.81   31 Jul 1995 10:05:30   jpb
// add include to define SGDATA
// 
//    Rev 1.80   28 Jul 1995 11:07:06   pjm
// Made changes for exportmg.
// 
//    Rev 1.79   28 Jul 1995 09:40:24   sbc
// Make function public
// 
//    Rev 1.78   27 Jul 1995 15:59:50   sbc
// Change PRECT to LPRECT
// 
//    Rev 1.77   27 Jul 1995 12:48:58   pjm
// Moved manu util routines to App class.
// 
//    Rev 1.76   27 Jul 1995 11:41:04   sbc
// Make function public
// 
//    Rev 1.75   27 Jul 1995 11:24:00   mjs
// Fixed errors in RR dir.
// 
//    Rev 1.74   27 Jul 1995 09:27:06   sbc
// Routine must be static
// 
//    Rev 1.73   26 Jul 1995 17:57:38   smh
// DFILE classification
// 
//    Rev 1.72   26 Jul 1995 15:59:58   pjm
// Add charalign prototype for pic.
// 
//    Rev 1.71   26 Jul 1995 15:44:42   pjm
// Made oldMeasure public.  Added more wmain stuff.
// 
//    Rev 1.70   26 Jul 1995 15:37:24   sjo
// Added RRW and RSW only sources from the CF directories.
// 
//    Rev 1.69   26 Jul 1995 14:54:38   mjs
// Moved create/delete edit wnd fns
// 
//    Rev 1.68   26 Jul 1995 12:32:22   sbc
// Another function to static
// 
//    Rev 1.67   26 Jul 1995 12:13:30   sbc
// Change some routines to static
// 
//    Rev 1.66   26 Jul 1995 11:37:24   pjm
// Added stuff from wmain.h and related files.
// 
//    Rev 1.65   26 Jul 1995 11:03:22   mjs
// Finished (?) wutil stuff.
// 
//    Rev 1.64   25 Jul 1995 15:59:56   smh
// Classified DOPTIONS.
// 
//    Rev 1.63   25 Jul 1995 15:44:16   mjs
// Added more wutil stuff.
// 
//    Rev 1.62   25 Jul 1995 12:26:18   mjs
// Added some wutil modules.
// 
//    Rev 1.61   25 Jul 1995 10:15:10   smh
// Classification of WREPORT dir.
// 
//    Rev 1.60   25 Jul 1995 09:49:18   mjs
// Added wfield.h stuff.
// 
//    Rev 1.59   24 Jul 1995 17:36:06   sjo
// Problems with lcompile prototype not using LPSTR.
// 
//    Rev 1.58   24 Jul 1995 16:49:44   pjm
// Added stuff from pic directory.
// 
//    Rev 1.57   24 Jul 1995 14:44:18   mjs
// Added wbox and wbitmap
// 
//    Rev 1.56   24 Jul 1995 10:38:32   mjs
// Made some box vars public so view fns can use them.
// 
//    Rev 1.55   21 Jul 1995 13:57:14   sbc
// Add stuff from druntime.cpp
// 
//    Rev 1.54   20 Jul 1995 16:33:22   sjo
// Added all the CF related stuff to CRrDoc.
// 
//    Rev 1.53   20 Jul 1995 16:08:00   sbc
// Add callback routine from dtoolbar.cpp
// 
//    Rev 1.52   20 Jul 1995 15:57:24   sbc
// Move in stuff from dmess.cpp & dtoolbar.cpp
// 
//    Rev 1.51   20 Jul 1995 15:50:26   sbc
// Fix a couple of PSTR's
// 
//    Rev 1.50   20 Jul 1995 15:45:20   sbc
// Add prototypes from dmisc.h & doptions.h
// 
//    Rev 1.49   20 Jul 1995 15:37:24   pjm
// More changes for util (static routines, pointers, etc.).
// 
//    Rev 1.48   20 Jul 1995 15:03:12   sbc
// Add statics from dlplace.cpp
// 
//    Rev 1.47   20 Jul 1995 14:46:52   sbc
// Add dlg proc from dinsfld.cpp
// 
//    Rev 1.46   20 Jul 1995 14:35:12   sbc
// Add stuff from dinsfld.cpp
// 
//    Rev 1.45   20 Jul 1995 14:26:50   sbc
// Move stuff from dinsert.h
// 
//    Rev 1.44   20 Jul 1995 13:43:46   pjm
// Make zsflatcomp() static.
// 
//    Rev 1.43   20 Jul 1995 13:33:16   sbc
// Add readScriptFile(), from wreport.h
// 
//    Rev 1.42   20 Jul 1995 11:55:00   pjm
// Make testdbl() public.
// 
//    Rev 1.41   20 Jul 1995 08:08:52   pjm
// Added stuff for UTIL directory.
// 
//    Rev 1.40   19 Jul 1995 16:19:04   sbc
// When in doubt, stick it here...
// 
//    Rev 1.39   19 Jul 1995 15:14:34   sbc
// Add more dformat stuff
// 
//    Rev 1.38   19 Jul 1995 14:16:36   sbc
// Add dledit.cpp
// 
//    Rev 1.37   19 Jul 1995 13:39:06   sbc
// Add dfmod.cpp
// 
//    Rev 1.36   19 Jul 1995 11:06:10   smh
// PATHSTRUCT->DOCPATHSTRUCT and moved some paths to APPPATHSTRUCT.
// 
//    Rev 1.35   19 Jul 1995 10:12:18   jpb
// add ENG modules vars and funcs
// 
//    Rev 1.34   19 Jul 1995 09:44:34   sbc
// Add stuff for wprint.cpp
// 
//    Rev 1.33   19 Jul 1995 08:14:50   pjm
// Added stuff from global.h.
// 
//    Rev 1.32   18 Jul 1995 16:42:56   mjs
// Added m_pFrame so we don't have to keep calling AfxGetMainWnd().
// 
//    Rev 1.31   18 Jul 1995 11:19:48   sbc
// More wprintui
// 
//    Rev 1.30   18 Jul 1995 10:14:10   sbc
// Move in some wprintui stuff
// 
//    Rev 1.29   17 Jul 1995 16:54:08   dlm
// Removed duplicate SXForSelect.
// 
//    Rev 1.28   17 Jul 1995 16:45:20   dlm
// Added member variables and functions from DCALC modules.
// 
//    Rev 1.27   17 Jul 1995 15:42:42   sbc
// 
//    Rev 1.26   17 Jul 1995 14:10:36   sbc
// Add onField()
// 
//    Rev 1.25   17 Jul 1995 11:27:26   sbc
// Make callbacks static
// 
//    Rev 1.24   17 Jul 1995 11:23:58   sbc
// Another wpix.cpp routine
// 
//    Rev 1.23   17 Jul 1995 11:14:58   sbc
// Move stuff
// 
//    Rev 1.22   17 Jul 1995 11:08:44   sbc
// Move some stuff from rrview.h
// 
//    Rev 1.21   17 Jul 1995 09:31:42   dlm
// Added member variables and functions from INDEX directory modules.
// 
//    Rev 1.20   14 Jul 1995 14:11:58   sbc
// Started  on WLAYOUT
// 
//    Rev 1.19   13 Jul 1995 11:37:52   sbc
// Clean up DDATA dialog proc prototypes. Put invalidateView() routines here.
// 
//    Rev 1.18   12 Jul 1995 17:07:12   dlm
// Added 'public' and 'private' keywords in LIBIO areas.
// 
//    Rev 1.17   12 Jul 1995 16:33:22   jpb
// more mf changes
// 
//    Rev 1.16   12 Jul 1995 14:26:02   dlm
// Added member variables and functions from LIBIO modules.
// 
//    Rev 1.15   12 Jul 1995 14:06:38   sbc
// WCLIP stuff moved in
// 
//    Rev 1.14   12 Jul 1995 12:16:50   sbc
// Finish print and remove MFTotal
// 
//    Rev 1.13   11 Jul 1995 17:21:02   dlm
// Added member variables and functions from REPIO modules.
// 
//    Rev 1.12   11 Jul 1995 17:06:22   jpb
// changes for mfedit and mferror directories
// 
//    Rev 1.11   11 Jul 1995 16:20:58   sbc
// More print-related stuff
// 
//    Rev 1.10   11 Jul 1995 14:09:20   jpb
// move some mf things from private to public, and remove some unuseds
// 
//    Rev 1.9   11 Jul 1995 13:59:12   sbc
// Start on print-related classfication
// 
//    Rev 1.8   11 Jul 1995 10:43:08   sbc
// Add module template
//
// Y2K fix done by Jim Ballard in cyberprise for WO157953.
// I copied this fix to R&R 8.0 for WO 157933 (WRR) 8/24/98
//
// 
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _RRDOC_H_

// Make a definition for this module.
//
#define _RRDOC_H_

// rrdoc.h : interface of the CRrDoc class
//
/////////////////////////////////////////////////////////////////////////////
// #includes made necessary by addition of member variables and functions from
//  throughout the product.
	#include "_filter.h"	// needed by FILTER stuff
	#include "qeval.h"		// needed by FILTER stuff
	#include "index.h"		// needed by INDEX stuff
	#include "_libio.h"		// needed by LIBIO stuff
	#include "mfedit.h"		// needed by MF stuff
	#include "rrxfld.h"		// needed by MF stuff
	#include "mffile.h"		// needed by MF stuff
	#include "memo.h"		// needed by MF stuff
	#include "_mffield.h"	// needed by MF stuff
	#include "_mfdata.h"	// needed by MF stuff
	#include "_mfedit.h"	// needed by MF stuff
	#include "cfmisc.h"		// needed by MF stuff
	#include "print_.h"		// needed by misc stuff (defines BRKFLD, et. al.)
	#include "_repio.h"		// needed by REPIO stuff
	#include "_sort.h"		// needed by SORT stuff
	#include "wband.h"		// for WHENP structure
	#include "mfxfld.h"		// needed by MF stuff
#if defined RSW
	#include "render.h"		// for DA RW integration
	#include "qelib.h"		// needed by ENG stuff
	#include "dbipriv.h"	// needed by ENG stuff
	#include "_ddata.h"		// needed by ENG stuff
	#include "_eng.h"		// needed by ENG stuff
#endif
	#include "globals.h"		// for SERVERNAMELEN needed by ENG stuff, also DIRRTN (not just RSW).
	#include "wmain.h"		// needed for UTIL stuff
	#include "pd.h"			// needed for UTIL stuff
	#include "dfile.h"		// needed for UTIL stuff
	#include "cfcomp.h"		// needed for CF stuff
	#include "vfpdbc.h"		// for Visual FoxPro DBC support

   //	The following are being removed from here, because they contain GLOBALs, which
	// will not get defined when rrdoc.h is in the precompiled header.
	// We can put any needed typedefs and macros in globals.h.

	// #include "global.h"		// for SERVERNAMELEN needed by ENG stuff, also DIRRTN (not just RSW).
	// #include "_cfcomp.h"		// needed for CF stuff
	// #include "cfedit.h"		// needed for CF stuff 

	#include "mffield.h"		// needed for CF stuff
	#include "util.h"			// needed for CF stuff
	#include "libio.h"		// needed for CF stuff
	#include "edittext.h"	// for CEditText
	#include "crstabif.h"	// for SGDATA
	#include "dinsfld.h"	// for InsFldDlg
	#include "dgroup.h"
	#include "rrchart.h"
	#include <winsock2.h>

// Band background colors
#define COLOR_TITLE			0xB0B0FF
#define COLOR_PAGEHEADER	0x8080D0	// red
#define COLOR_GROUPHEADER1	0x80B0FF	// orange?
#define COLOR_GROUPHEADER2	0x00D0D0	// darker yellow
#define COLOR_GROUPHEADER3	0x00FFFF	// lighter yellow
#define COLOR_RECORD		0xD0F0E0	// pale green
#define	COLOR_GROUPFOOTER3	0xD0FFD0	// light green
#define COLOR_GROUPFOOTER2	0x80D080	// medium green
#define	COLOR_GROUPFOOTER1	0x80A080	// darker green
#define COLOR_PAGEFOOTER	0xFFD0D0	// blue
#define	COLOR_SUMMARY		0xFFD0FF	// violet

#define HOSTNAMELEN 64

class CRrCntrItem;
class CRrSrvrItem;
class CMainFrame;
class CRrComposite;
class CRrRepIO;
class CRrExport;
class PrintDialog;
class InsFldDlg;
class SelectGFDlg ;
class CChartSheet;
class CRrChart;

#if defined(RUNDLL)
class RDReport;
class RDTable;
#endif

#if defined(RUNDLL)
class CRrDoc : public CDocument
#else
class CRrDoc : public COleLinkingDoc
#endif
{
public:

	BOOL		m_bHaveLibrary;		// TRUE means we have a "current" .RPn library
	BOOL		m_bEditCharts;		// TRUE means we need to edit at least one chart
	int			m_LastBreakLevel;	// group level (0..7) of last group break
	char		ReportSerialNumber[10] ;
	char		OwnerId[100] ;
	BOOL		XFiles ;			// true if want to read report w/o dbfs
	void		ForgetCompoundFile( );	// revoke, release, that kind of stuff
	BOOL		NeedChartPass( void );
	BOOL		UpdateChartFieldIDs( void );
	BOOL		UpdateChartFieldIDs( FLDID OldID, FLDID NewID );
	BOOL		UpdateChartsForDeletedField( FLDID Id );
	int			FindIndexOfChart( LPFLDHDR f );
	void		DeleteChartItems( void );
	int			ComputeChartGroup( RRCHART* pChart );
	int			ComputeChartBandLine( RRCHART* pChart );
	void		ChartErrorMessage( CHARTERR eChart, LPRRCHART pChart );
#if defined(RUNDLL)
	RDReport*	m_pReport;			// so dialogs can get from document to report object
	RDTable*	m_pTable;			// ... or table object
#endif

// autosave additons	
	int			AutoSaveTimer ;
	void		OnTimer(uint id) ;
	void		createAutoSavePath(void) ;
	void		clearAutoSavePath(void) ;

// password additions
#define MAX_PASSWORD	30
	CString		DPassword ;
	CString		RPassword ;
	CString		EncryptedDPassword ;
	CString		EncryptedRPassword ;
	BOOL		DoPassword(BOOL bSet) ;
	void		EncryptPasswords() ;
	void		DecryptPasswords() ;

// To allow multiple copies of Viewer to run same compound-file report, we now attempt
//  to copy the report and open the copy.  This is where we remember the name of the
//  copy, so we can clean up.
// INTERACTIVE now uses if the report is already open. RSW 2396, JSF
	CString		m_TempReportName;	// place to remember temp file name for report copy

	BOOL scriptFilePrep(LPSTR scriptFile, LPSTR master);

// these 2 used to be in bandview.h, but needed for runtime script support
	void adjustBandLines(int top);
	BOOL findBandLine(int wp,int *band,int findLast);
	
	// ***** begin dcalc.h
public:
	LPMFFIELD		insCalcFld;
	LPUDF			udfPicked;
	CMainFrame*		m_pFrame;		// So we only do (CMainFrame*)AfxGetMainWnd() once in constructor.
	CRrComposite*	m_pComposite;
	CRrRepIO*		m_pRepIO;
	CRrExport*		m_pExport;
	PROCESS_INFORMATION m_RRBrowse;	// viewer for result set
	PROCESS_INFORMATION m_Rlcat;	// Report Librarian

	BOOL		m_bFax;			// AMH 2/25/97 Added Fax boolean to class
	FLDID		*XCalcFIDList ;
	FLDID		*EditFIDList ;
	FLDID		CalcFID ;
	int			UdfInsSort ;
	int			EditCalcSort ;
	int			UDFSort ;
	LPUDF		*UDFList ;
	LPUDF		*XUDFList ;

	void		killRSBrowser(void) ;
	void		autoTotal( void );
	int			autototable( void );
	void		calcTotFld( int type );
	void		paramFld(void) ;
	BOOL		getTagForFileOpen( LPSTR index, LPSTR tag );
	void		initTotNm( void );
	void		ckTotNm( LPMFFIELD fld );

static	BOOL CALLBACK	calcUDFDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
static	BOOL CALLBACK	calcInsDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
static	BOOL CALLBACK	udfInsDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
static	BOOL CALLBACK	calcTotDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
static	BOOL CALLBACK	udfDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
static	BOOL CALLBACK	paramDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
		int				checkParamExpression(HWND hDlg) ;
		BOOL			paramValidate(HWND hDlg) ;
		void			reorderParams(void) ;

		BOOL			EditParam(LPMFFIELD f, bool copy) ;
static  BOOL CALLBACK	editParamDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
static  BOOL CALLBACK	editParamNumpic(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
		void			numericSample(HWND hDlg, int nIntegers, int nDecimals, int nFormatIndex) ;
		void			numericSampleCheck(HWND hDlg) ;
		void			setNumericMax(int nFormatIndex,
							int *nIntegersMin, int *nIntegersMax,
							int *nDecimalsMin, int *nDecimalsMax) ;

static	BOOL CALLBACK	editParamCharpic(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) ;

static  BOOL CALLBACK	editParamDatepic(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
		void			dateSample(HWND hDlg) ;

static  BOOL CALLBACK	editParamTimepic(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
		void			timeSample(HWND hDlg) ;

static  BOOL CALLBACK	editParamDateTimepic(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
		void			datetimeSample(HWND hDlg) ;

		int				getParams(void) ;
static	BOOL CALLBACK	getParamDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) ;
static	BOOL CALLBACK	parameterWaitOK(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) ;
		int				initGetParamList(HWND hDlg) ;
		void			setParamNewValue(HWND hDlg, LPMFFIELD f) ;
		bool			changeParameter(HWND hDlg, int pindex) ;
		void			revertParameter(HWND hDlg, bool change) ;
		void			setParamPic(LPMFFIELD f, char *sz) ;
		bool			validateParameter(HWND hDlg, LPMFFIELD f) ;

static	BOOL CALLBACK	indexTagDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
static	BOOL CALLBACK	totalDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
static	BOOL CALLBACK	purgeDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
static	BOOL CALLBACK	fieldCommentDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );

	int			initParamList(HWND hDlg, int id) ;
	void		displayParameterValue(HWND hDlg, int id, LPMFFIELD f) ;
	int			deleteParamFld(HWND hDlg, LPMFFIELD fld) ;
	void		paramErr( HWND hDlg, int qenum, int erroff, LPSTR errstr) ;
	int			paramConstExp(LPMFFIELD f) ;
	bool		calcAddFilter( LPMFFIELD f );

	bool		setExport(void) ;
	bool		dialogEditMultipleTotals(void) ;
	bool		dialogEditTotal(LPMFFIELD f, LPMFFIELD cf, LPMFFIELD tf, BOOL batch) ;
	CString		DBFieldName ;
	CString		DBFieldValue ;
	CString		DBFieldLength;
	CString		DBFieldType;

	// ***** end dcalc.h
	
	// ***** begin _dcalc.h
	LPSTR		totCondP;
	void		compErr( HWND hDlg, int qenum, int erroff, LPSTR errstr );
	LPSTR		DCtagname;
private:
	
	void		batchReset( HWND hDlg );
	void	 	condErr( HWND hDlg, int qenum );
	int 		ExportFileCreation();
	void		ExportFileName(CString strReportFileName);
public:
	LPMFFIELD	getMarkedFld( void );
private:
	// ***** end _dcalc.h
	
	// ***** begin former "statics" from dcalc directory modules
		// from dcalcudf.cpp
	int			DCstart_sel;
	int			DCend_sel;
	WORD		DChelpCode;
	WORD		DCinsFocus;
	int			DClastFld;
	int			DClastFunc;
	BOOL		DCcalctype;
	int			DCtaghelp;
	BOOL		DCbFuncFocus;
		// from dtotal.cpp
	BOOL		DCaccum;
	BOOL		DCcharonly;
	BOOL		DCfinal;
public:
	BOOL		DCbatchTotal;
   bool        miExit;
private:
	BOOL		DCno_page;
   
	int			DCwidth;
	int			DCheight;
	int			DCtottype;
#if defined RSW
public:
	int			DCcurTotAccum;
	BOOL		DCbTotOptsOpen;
	BOOL		DCbFieldChanged;
private:
#endif
	long		DChiTot;
	long		DCloTot;
	long		DCnextTot;
	long		DCsavHT;
	long		DCsavLT;
	long		DCsavNT;
	LPMFFIELD	DCfirsttot;
		// from dcalctot.cpp
	int			DCedType;
	BOOL		DCgetCalcs;

	int			firstArgLen( LPSTR s, int *func );
	int			gotCalcFlds( void );
	void		showCaret( HWND hDlg );
	void		setOKDef( HWND hDlg, WORD id );
	int			findFunction( HWND hDlg, int nIndex );
	int			contextHelp( HWND hDlg );
	void		functionHelp( HWND hDlg, int nListboxIndex );
	BOOL		expOkay( HWND hDlg, BOOL check );
	void		addText( HWND hDlg, LPSTR tx, BOOL func );
	void		addFieldName(HWND hDlg, LPMFFIELD mf) ;
	BOOL		ckTotAcc( LPMFFIELD fld );
	BOOL		preProcOkay( LPMFFIELD fld, int brklevel, int totfreq );
	BOOL		checkPreprocess( HWND hDlg );
//	LPMFFIELD	nextMarked( LPMFFIELD curMarked );
	int			markedCount( void );
	long		nexttotnum( void );
	BOOL		ckItOut( HWND hDlg );
public:
	LPMFFIELD	nextMarked( LPMFFIELD curMarked );
	void		cleanup( void );
	int			checkTotal(HWND hDlg,
						int autocount,
						LPMFFIELD f,
						const char *name,
						const char *comment,
						int type,
						LPMFFIELD targetf,
						int resetLevel,
						int accum,
						int process,
						const char *condition) ;
private:
static BOOL		ckInsTot( LPMFFIELD f );
	BOOL		ckAnyTot( LPMFFIELD f );
	int			countFlds( int ttype );
	int			checkMarkedFlds( int ttype );
	void		listFlds( HWND hDlg, BOOL first, LPMFFIELD DlgFld );
 #if defined(RSW)
public:
	void		selectTotAccum( HWND hDlg, LPMFFIELD DlgFld, BOOL bUseFreqDef );
private:
 #endif
	BOOL		gotEnufTotNums( int cnt );
public:
	int			checkone( HWND hDlg, LPMFFIELD fld, int new_level );
private:
	void		insertSpaces( LPSTR s, LPSTR d );
	BOOL		gotCalcs( BOOL calcs );
	void		enableEditButtons( HWND hDlg, BOOL bUpdate );
static int		calcInsFilter( LPMFFIELD f );
//static int		fldFilter( LPMFFIELD f );
	LPUDF		findUDF( HWND hDlg);
	int			buildUDFList(LPUDF **ulist) ;
	void		sortUDFList(LPUDF *ulist, int sort) ;
	int			searchUDFList(LPUDF *ulist, char *name) ;
	int			dtUDF(LPUDF u) ;
	int			displayUDFList(HWND hDlg, LPUDF *ulist, LPUDF un) ;
//	int			listUDF( HWND hDlg, LPUDF un, WORD id );
	void		showExpression( HWND hDlg, FLDID fid, int eid);
	void		showUDFExpression( HWND hDlg, LPUDF i, int eid);
public:
	int			deleteFld( HWND hDlg, LPMFFIELD fld );
	static BOOL CALLBACK	batResetDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
private:
	void		deleteUDF( HWND hDlg );
	void		setCloseDef( HWND hDlg, WORD id );
	// ***** end former "statics" from dcalc directory modules
	
	// ***** begin libio.h
public:
	int			YYError;
	YYFILETAB*	RepFile;
	
	LPYZNAME	yzread1name( YYFILETAB* ftab, LPSTR name );
	void		yzrlsnames( LPYZNAME yzname );
	BOOL		lyyrdseq( YYFILETAB* ftab, int bct, LPSTR p );
	YYFILETAB*	yycreate( LPSTR name, int share, LPSTR full, int type, int chksz );
	LPSTR		yyetext( void );
	BOOL		yyfreechunks( YYFILETAB* ftab, DWORD c );
	YYFILETAB*	yyopen( LPSTR name, int sharing, int mode, LPINT type, int chksz );
	BOOL		yzaddname( YYFILETAB* ftab, LPYZNAME yzname );
	BOOL		yzdelname( YYFILETAB* ftab, LPYZNAME yzname );
	void		yyclose( YYFILETAB* ftab );
	DWORD		yygetchunkno( YYFILETAB* ftab );
	void		lyysetchunkno( YYFILETAB* ftab, DWORD c );
	LPSTR		yyosname( LPSTR s );
	BOOL		lyywrseq( YYFILETAB* ftab, int bct, LPSTR p, int f, int r );
	void		yyreset( void );
	BOOL		yzupdatename( YYFILETAB* ftab, LPYZNAME yzname );
	LPYZNAME	yzreadnames( YYFILETAB* ftab );
	// ***** end libio.h
	
	// ***** begin _libio.h
private:
	LPYYBUFFER	yy_bufe;				/* end of buffer pool */
	int			yy_time;
	LPYYBUFFER	yy_wrhbufs;
	LPYYBUFFER	yy_bufs;
	LPYYBUFFER	yy_bufx;
	TCHAR		yyfilext[5];
 
	void		yy_binit( void );
	void		yy_crinit( int type, int chksz );
	void		yy_flush( int final );
	BOOL		zlrdblock( int file, int blkno, LPSTR dest );
	BOOL		zlwrblock( int file, int blkno, LPSTR source );
	LPYYBUFFER	yy_getblk( UINT rbn );
	LPYYBUFFER	yy_getbuf( void );
	LPYYBUFFER	yy_getchk( DWORD c, LPYYCHUNK* ppc );
	DWORD		yy_getcn( void );
	DWORD		yy_getlink( LPYYCHUNK pc );
public:
	void		yysetext( LPSTR ext );
	// these next four need to be public for RRCNVRT
	YYFILETAB*	yy_ftab;
	int		yy_headchg;
	void		yy_wrhdr( void );
	BOOL		yyinit( int bufc );
private:
	void		yy_setlink( LPYYCHUNK pc, DWORD c );
	BOOL		yy_wrbuf( LPYYBUFFER pb );
	void		yzcompname( YYFILETAB* ftab );
	BOOL		yz_delname( YYFILETAB* ftab, LPYZNAME yzname, int del );
	BOOL		yzrename( YYFILETAB* ftab, LPYZNAME yzname, LPSTR newone );
	// ***** end _libio.h
	
	// ***** begin former "statics" from libio directory modules
private:
	TCHAR		 yyemsg[81];
	LPYZNAME	yz_name;
	TCHAR 		yz_hdr[5];
	DWORD	 	yz_chk;
	UINT 	 	yz_off;
	UINT 	 	yz_nct;
	int		 	yz_dels;
	
	void	 	flush1( int final, LPYYBUFFER pb );
	LPYYBUFFER	checkbuf( LPYYBUFFER pb, UINT rbn );
	LPYYBUFFER	checktime( LPYYBUFFER pbarg );
	BOOL		yz_findname( LPSTR bp );
 #if (defined(INTERACTIVE) && !defined(RUNDLL)) || defined(RRCONVERT)
	BOOL		yz_add( LPYZNAME yzname );
	BOOL		yz_addname( LPYZNAME yzname,int uncond );
 #endif
	// ***** end former "statics" from libio directory modules


	
	// from global.h - variables
public:
	WORD	Boxes;			// number of boxes in report.
	LPRRBOX	BoxStruct;		// R&R box structure
	int		ClipFlds;		// number of cut fields
	int		ClipLines;	 	// and lines
	BOOL	CloseInsDlg;	// close insert dialog after inserting field
	WORD	ContextHelp;	// help id for context help
	struct	whenprint far * ClipWhen; // last cut/copied lines
	WORD	DefDesc;		// default descender
	HFONT	DefFont;		// default font
	WORD	DefFontNo;		// index into current font list
	WORD	DefLeading;		// default font height
	WORD	DefPts;			// default point size (might be different from Defs.dfPoints)
	DEFSTRUCT Defs;			// global default structure
	WORD	DefThickness;	// default line/box thickness.
	HFONT	DefUnderFont;	// default underscored font
	WORD	DeletedFlds; 	// zapped fields
	int		DeletedLines;   // zapped lines
	LPMFFIELD DlgFld;		// field pointer for dialogs
	LPMFFIELD CopyDlgFld;	// field pointer for copied dialog
	BOOL	Drawing;		//  Drawing a box or line.
	int		EditQuery;
	LPTXFLD	EditTextFld;	// we're editing this field
	HWND	EditTxWnd; 		// text field edit window
	BOOL	Export; 		// we need to know this when printing
	WORD	FontsMade; 		// keep track for cleanup
	BOOL	FormatBar;		// show/hide format bar
	BOOL	GotRep; 		// do we have a report in memory?
	BOOL	bCanChart;		// numeric fields to chart?
//	No more resource DLL
//	HINSTANCE hResource;	// handle to resource DLL
	HINSTANCE HInst;		// our instance
	HINSTANCE hPrinterDriver;	// our current printer driver instance
	HINSTANCE hPDFPrinterDriver;
#if defined(RSW)
	HINSTANCE hDataDirect ;	// rrdd.dll instance
#endif
	HANDLE hPDFPrinter;
	HINSTANCE hImageLib;	// instance handle of image library
	HINSTANCE hChartLib;	// instance handle of chart library
	HINSTANCE hAGChartLib;	// instance handle of chart library
//	HINSTANCE hRuntimeDLL;	// handle to runtime DLL
	WORD	Images; 		// number of bitmaps in report
	WORD	ImageshDib;		// number of generated field images
	WORD	Charts; 		// number of charts in report
	LPRRIMAGE ImgStruct;	// R&R image structure
	int	*ImageshDibArray ;
	LPRRCHART ChartStruct;	// R&R chart structure
	HBRUSH	MainBrush; 		// background brush for main window
//	HDC MainDC;				// our private display context
	HWND	MainWnd; 		// main window handle
	int		MarkedBoxes;	// marked box count
	int		MarkedImages;	// marked image count
	int		MarkedLines;	// marked line count
	int		MarkedLns;		// marked line (2d object) count
	int		MarkedCharts;	// marked chart count
	int		nMarkedOleObjects ; // marked ole object count
	WORD	MaxHorzPix;		// maximum horizontal location
	WORD	MaxInfoStrLen; 	// maximum size of status info string
	TCHAR	Measurement;	// English or Metric
	WORD	NumPrtFaces; 	// number of printer typefaces
	int		PageBoxes;		// boxes waiting to be printed
	int		PageImages;		// images waiting to be printed
	int		PageCharts;		// charts waiting to be printed
	int		PageLength;		// page length type
	int		nPageOleObjects ;   // OLE Objects waiting to be printed
	BOOL	PasteArgs;		// paste arguments into expression box
	DOCPATHSTRUCT far * Paths;	// pathname structure
	LPDEVMODE PDevMode; 	// current printer device mode
	BOOL	PrefInsRep;		// instant report preference
	BOOL	PrefFldLst;		// field-names/descriptions in field lists
	BOOL	PrefPrevWinClr;	// use windows colors in preview?
	BOOL	PrefScrHz;		// show horizontal scroll bar
	BOOL	PrefScrVt;		// show vertical scroll bar
	int		PrefAutoSave;	// auto save (0-120)
	BOOL	PrefBandClr;	// display colored bands (v. grey)
	BOOL	PrefBandClr1;	// display colored bands (v. grey) -- in field dialogs
	int		PrefSortFieldNames;		// sort field names in list boxes
	int		SortFieldNames;
//	HACCEL PrevAcc;			// Preview accelerators
//	HWND PrevWnd;			// preview window itself
	TCHAR	PrevZoomLevel;	// 0, 1 or 2
	WORD	PrintCopies;	// printer copies
	TCHAR	PrintDrv[PDRVSZ];	// current printer driver
	WORD	PrinterInchX;	// horizontal printer resolution
	WORD	PrinterInchY;	// vertical printer resolution
	BOOL	Printing; 		// printing in progress
	TCHAR	PrintPort[PPORTSZ];	// current printer port
	TCHAR	PrintType[PTYPESZ];	// current printer type

	//  new printer control / definition elements created by CAS 12/04/2017 Rev 1.316 
	TCHAR	PrnDrvDefa[PDRVSZ];	// current printer driver
	TCHAR	PrnPortDefa[PPORTSZ];	// current printer port
	TCHAR	PrnTypeDefa[PTYPESZ];	// current printer type

	int		PrState;		// report writer printer status
	LPPRT_FACE PrtFonts; 	// long pointer to font array
	LPPRT_STRUCT PrtStruct; // printer structure
	int		PStatus;		// print Escape status
#if defined (RSW)
	BOOL	QERevComp;		// QELIB Revision setting
	int		Old_Style;		// UseCommDlg flag for dbase and paradox
#endif
	TCHAR	SerialHex[1];
	BOOL	ShowFieldNames;	// show field names
	BOOL	ShowGrid;		// show snap-to grid
	BOOL	ShowHRuler;		// View Horizontal Ruler
	BOOL	ShowVRuler;		// View Vertical Ruler
	BOOL	ShowTHRuler;	// View Top Horizontal Ruler
	BOOL	ShowBHRuler;	// View Bottom Horizontal Ruler
	BOOL	ShowLVRuler;	// View Left Vertical Ruler
	BOOL	ShowRVRuler;	// View Right Vertical Ruler
	TCHAR	Sql_Platform;	// storage for one of above identifiers
	HFONT	StatFont;		// status bar font
	int		StatFontHite; 	// hite of font used in status area
	TCHAR	StatusMess[MESS_LEN+1];	// status message area
	BOOL	Waiting;		// TRUE -> zbusy TRUE
	int		XLeft; 			// current horizontal scroll amount
	int		XPos; 			// field area x position
	int		YLine; 			// current band line
	long	YPix;			// current absolute vertical pixel location
	long	YTop; 			// current vertical scroll amount
	BOOL	SnapToGrid; 	// snap to!
	WORD	VRulerSpacing; 	// vertical ruler gradient
	TCHAR	cFirstDay[3];		// first day of week (Rev 1.315); SU,MO,TU,WE,TH,FR,SA

// Globals from the old rpstatic.c
	int	BodySize;
	int BodyWhite;
	int BodyWrapper;
	BRKFLD BrkFlds[NOBRKFLDS];
	int EndFile;
	int EndRow;
	int HzLines;
	int HzRecord;
	int MultLines;
	MULT far * MultTab;
	int PgFtSpace;
	unsigned * PrOpt;
	LPLABNAME PrOptLabel;
	TCHAR RepName[REPNAMELENGTH];
	FOUR RepNumber;
	int RpGotMem;
	FOUR RpRecCnt;
	UTWO SortAscending[NOSORTFLDS];
	FLDID SortFields[NOSORTFLDS];
	LPTXFLD TXFields;
	int TXNoFlds;
	struct whenprint far * When;
	unsigned BodyDepth;
	unsigned BodyLoc;
	unsigned BotWhite;
	TCHAR * BreakData;
	int BreakInd;
	int DontOrphan;
	FOUR EndingPage;
	int FirstRecord;
	int HoldOver;
	int LPR;
	int Multi_Copies;
	int NewPageLine;
	int m_nChartsInThisReport ;  // 06/16/97 PAR. 
	int PgNo;
	int LastPage;
	FOUR PhysPage;
	int Preview;

	FLDID Rec_Cop_Fld;
	unsigned RecWidth;
	int ReprintHdr;
	int RepType;
	int ResetPage;
	unsigned RM;
	int Something;
	FOUR StartingPage;
	int SwapFoot;
	int SwHdPrt;
	int SwapHead;
	int SwapFootHite;
	int SwapOrReset;
	int TopPage;
	int TopWhite;
	FOUR WontFit;
	int WrapEOP;

//	HWND hInsDlg;	// changed to class pointer below
	InsFldDlg	*m_pInsFldDlg;

// Moved out of INTERACTIVE section for dinsfld.c
#if defined INTERACTIVE && !defined(RUNDLL)
// for status bar display
	BOOL bShowCalcComment;
	LPFLDHDR CurFld;
	FLDID InsInd;
	UTWO LastOrd[NOSORTFLDS];
	FLDID LastSort[NOSORTFLDS];
	int MarkedFlds;
	
	// Encapsulate the dirty flag changes just in case 
	// we need special processing.  It is very likely we will 
	// need to clear the OLE Object dirty flags by hand. 
	BOOL IsRrModified() { return IsModified() ; }
	virtual BOOL SaveModified() ;

#else	// RUNTIME
	int RunStatClr;
#endif
	void SetRrModifiedFlag(BOOL bModified=TRUE) { SetModifiedFlag(bModified) ; }
	int CopyNum;
	unsigned RulerPitch;
	// end global.h

/// From _ddata.h - variables:
/// From _ddata.h - function prototypes:
public:
	void setSGProcs(HWND hDlg);
	void clrSGProcs(HWND hDlg);
	BOOL focusKey(HWND hDlg,int key,int *curKey,BOOL set);
	void fixUpReport(BOOL relate, PSTR alias);
                                     
/// From ddata.h - variables:
public:
	LPMFFIELD delfld;
	int delstrid;

/// From ddata.h - function prototypes:
	static BOOL left_field(LPMFFIELD f);
	static BOOL right_field(LPMFFIELD f);
	BOOL groupMe(void);
 	BOOL sortMe(void);
 	void showDelPrompt(LPSTR pPrompt);		// the prompt in box (from mfdelcon)
 	void addDelList(LPSTR p);			// called from mfdelcon() to add a field
 	void addChartList(LPSTR p);			// called from mfdelcon() to add a field
	static BOOL CALLBACK EXPORT delConDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
	static BOOL CALLBACK EXPORT sortDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT databaseDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT relateDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT queryDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT qEditDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT dbRelDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT groupDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
#if defined RSW
	void limitResult(void);
	void showSqlMe(void);
	static BOOL CALLBACK EXPORT showSqlDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT limitResultDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
#else
	static BOOL CALLBACK EXPORT scanOrdDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
#endif
#if defined INTERACTIVE
	void queryMe(void);
#else
 	int askQuery(void);
#endif
#if !defined RSW
	 void getTagNames(HWND hDlg, WORD id, WORD keyexpid, LPSTR indfile, LPSTR tag);
#endif

/// Statics from ddelcon.cpp:
public:
	HWND hDelDlg;

/// Statics from dgroup.cpp:
public:
	int curGroupKey;		// must be initialized to zero in constructor!
	BRKFLD brks[NOBRKFLDS];
public:
	int		findGroupSlot(int slot);
	BOOL	gotTempBreaks(HWND hDlg);
	void	setGroups(HWND hDlg, BOOL first);
	void	setFocusGroup(HWND bDlg, int k) ;
	void	setFocusSort(HWND bDlg, int k) ;


/// Statics from dquery.cpp:
public:
	int		edit_caption_id;
	int		condition;
	int		hifin;
	BOOL	and_or;
	PKSX	*pkedit;
	int		termCnt;
	int		curTerm;
	LPMFFIELD leftFld;	// must be set to NULL in constructor!
	LPMFFIELD rightFld;
	LPPKSX	pksx;
	BOOL	bEmptyNewTermOK; // Need explicit flag since we can't tell from OK button
					  // because we're enabling OK even if no terms when
					  // bEmptyNewTermOK is TRUE.

public:
	BOOL	checkParen(LPSTR p, TCHAR lr);
	void	deleteTerm(HWND hDlg);
	void	dimFieldButton(HWND hDlg);
	BOOL	editTerm(HWND hDlg, WPARAM wParam);
	BOOL	enableFieldButton(HWND hDlg);
	void	getLeftEditField(HWND hDlg);
	void	getRightEditField(HWND hDlg);
	BOOL	gotDupeFldName(LPMFFIELD lpFld);
	BOOL	lessTermMem(int terms);
	BOOL	moreTermMem(int terms);
	void	setCondBox();
	void	setEditButtons(HWND hDlg, BOOL set);
	void	setEditHelp(HWND hDlg);
	void	setEditLimits(HWND hDlg, int condition);
	bool	setFieldState(HWND hDlg);
	void	setCondState(HWND hDlg);
	void	setHelp(HWND hDlg, int id);
	void	showQueryTerms(HWND hDlg, LPSTR term);
	BOOL	totokay(LPMFFIELD f);
	BOOL	validateTermLength (LPSTR string);
	BOOL	verifyEdit(HWND hDlg);

// From _dformat.h - functions:
public:
	void fModAlign(HWND hWnd);
	void fModStyle(HWND hWnd);

// From dformat.h - variables:
public:
	int topline;
	int m_lcr;	// now used in DLJUST.CPP for multi-purpose alignment dialog

// From dformat.h - functions:
public:
	void recOptions(void);
	BOOL ptsFound(int pts,int font);
	void fieldStyle(void);
	void fieldButtonStyle(int fnt,int pts,int att);
	void fieldAlign(int, int, int, int);
	void AlignTwoDObject( LPFLDHDR pObject );
	void fieldTrim(BOOL bTrim);
	BOOL SetRulerSpacing( BOOL bVertical );
	BOOL SetRulers(int page) ;
//	static BOOL CALLBACK EXPORT rulerDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT lineEditDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT dateFormatDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT imgModDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT imgFieldModDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT numFormatDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static UINT CALLBACK EXPORT chooseFontHook(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	static BOOL CALLBACK EXPORT lineDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT boxDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT lcrDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);

	int	BandLinePropertiesDialog(void) ;

/// Statics from dfmod.cpp:
private:
	int imgNum;
	LPRRIMAGE img;
	WORD scale;
	TCHAR szWidth[6];
	TCHAR szHeight[6];
	int o_xuser;
	int o_yuser;
	HWND hd;
	int measure;
private:
	int getNewFile(void);
	int getNewSize(void);
	void setOrgSize(void);
	void setSizePix(long width, long height);
	void setSizeUser(int xinch, int yinch);

// From dinsert.h - variables:
public:
	FLDID insertInd;

// From dinsert.h - functions:
public:
	void	insertField(void);
	void	insertLayoutCommon(LPMFFIELD f,int l,int x);
 	BOOL	clickInsert(POINT point);
	void	refreshInsertDlg(FLDID index);
	static BOOL CALLBACK EXPORT insLeftFieldDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT insRightFieldDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT insScopeFldDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT insImageFldDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT lineCreateDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT textFileDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL cFldFilter(LPMFFIELD f);
	static BOOL	fldFilter( LPMFFIELD f );
	static BOOL	fldTotalFilter( LPMFFIELD f );

	static BOOL PicFieldFilter(LPMFFIELD f);

/// Statics from dinsfld.cpp:
private:
//	static BOOL CALLBACK EXPORT insFldLayoutDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
public:
	void	insertIntoLayout(HWND hDlg, LPMFFIELD f);
	void	insFldDlgInitCommon(HWND hDlg, WORD fldID);

	void	DoReplace(HWND hDlg, int TextID) ;
	CStringArray	ReplaceTextArray ;
	CStringArray	FindTextArray ;

/// Statics from dledit.cpp:
private:
public:
#if !defined RSW
	int nums[MFMAXFILES];
#endif
private:
	int autohite(int lnht);
	BOOL editOkay(HWND hDlg);
	int inchesPoints(HWND hDlg, WPARAM wParam);
public:
	int maxAutohite(int lnht);

/// Statics from dlinebox.cpp:
private:
	void drawPatternEntry(HWND hDlg, LPDRAWITEMSTRUCT lpdis);
	void drawThicknessEntry(HWND hDlg, LPDRAWITEMSTRUCT lpdis);
	void drawStyleEntry(HWND hDlg, LPDRAWITEMSTRUCT lpdis);
	void selectEntry(LPDRAWITEMSTRUCT lpdis);
	void setBit(HWND hDlg, WORD id, int bit);

/// Statics from dlplace.cpp:
private:
	BOOL bPasting;
	int bandLoc;
public:
	BOOL noEject(int when);

// From dmisc.h - functions:
public:
	int messageBox(HWND hWnd,LPCSTR mess,LPCSTR title,int type);
	static BOOL CALLBACK EXPORT helpDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT messageBoxProc(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT aboutDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT toolsDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK EXPORT rulersDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);

////////////// DOPTIONS /////////////////////

// From doptions.h - functions:
public:
	void	globalDefaults(void);
	void	ChartDefaults(void) ;
	void	defDirs(void);
	void	rrprefs(void);
	void	saveIntPref(int, int *, LPSTR) ;
	static	BOOL CALLBACK prefDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static	BOOL CALLBACK globDefDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
#if defined (RSW)
	void	logonPrefs(void);
	static	BOOL CALLBACK logonPrefsDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
#endif

// from dglobdef.cpp - public data & routines
public:
	int	newmeas;
	void	browse( HWND hDlg, int control, LPSTR path, DIRRTN rtn, BOOL isfile, int extid, int extctrl, LPSTR defext, int titid );
	static LPSTR	mastdir( CRrDoc* pDoc, LPSTR mdir );
	void	writeDefDirs( void );

// from dglobdef.cpp - static routines:
private:
	BOOL	badInt( HWND hDlg, int ctrl, int ckzero, int *val );
	void	writeDefSettings( void );

// from dpref.cpp - public data & routines
public:
	int	fileNewCheck;
	int	fieldList;

// from dpref.cpp - static routines:
private:
	BOOL	setIt( HWND hDlg, int ID, LPSTR key, int *state);

////////// end DOPTIONS


/// Statics from dmess.cpp:
private:
	LPCSTR box_title;
	LPCSTR dm_icon;
	int focus;
private:
	void sizeMessDialog (HWND hDlg, LPSTR lpszMessage);

/// Statics from dsort.cpp:
private:
	int curSortKey;
	BOOL gotbreak;
	UTWO lastAD[NOSORTFLDS];
	FLDID lastSortFlds[NOSORTFLDS];
private:
	int findSortSlot(int slot);

/// Statics from dstyle.cpp:
private:
	LPFLDHDR fld;
	int colorPicked;
	int facePicked;
	int sizePicked;
	int stylePicked;
private:
	int		getFontPixHite(WORD hite);
	HFONT	makeFont(BOOL);
	void	setNewFont(LPFLDHDR f, HFONT hFont, BOOL bColor);
	//  CAS 7/18/2013 changed color from WORD to DWORD as an experiment
	//BOOL	winFontDialog(HWND hWnd,WORD face,WORD pts,WORD att,WORD color);
	BOOL	winFontDialog(HWND hWnd,WORD face,WORD pts,WORD att,DWORD color);

/// Statics from dtoolbar.cpp:
private:
	TCHAR	barStandard;
	TCHAR	barFormat;
	WNDPROC winListProc;
private:
	void	drawToolEntry(LPDRAWITEMSTRUCT lpdis);
	static	LRESULT CALLBACK EXPORT listProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void	setToolbars(HWND hDlg);

/// Statics from fldalign.cpp:
private:
	void setAlignment(LPMFFIELD f, DWORD nFldType, UINT nLCR, BOOL bWrap, UINT nWrapLCR);

// used in both sddata and xddata
public:
	TCHAR oAlias[MAXALIAS];
/// Statics from xddata.cpp:
#ifndef RSW
public:
#if defined INTERACTIVE
	BOOL master_links(void);
#endif
	void getScopeField(HWND hDlg, int control);
static	int scopeParameterField(LPMFFIELD f);

#endif	// #ifndef RSW

#ifndef RSW
/// Statics from xdrelate.cpp:
public:
	TCHAR	alias[MAXALIAS];
	int		relFileNum;
	BOOL	fileNewRelation;
	LPSTR	relPath;
	LPSTR	indPath;
	LPSTR	dynamicPath;
	LPSTR	dynamicField;
	LPSTR	dynamicLen;
	int		relType;
	int		userIndex;
	int		failureAction;
	int		relateDlgWidth;
	int		relateDlgHeight;
	PKGROUP far *pg;
	int		indexFileNum;
	char	indexExpression[SELEXBUF + 1] ;
public:
	BOOL editRelationNew(HWND hDlg, BOOL bNew);
//	BOOL editRelationNew(void);
	BOOL editRelation(HWND hDlg, BOOL bNew);
	void enableButtons(HWND hDlg);
	WORD listRelations(HWND hDlg);
	BOOL createIndexFile(HWND hDlg, CRrDoc *pDoc, PKREL *rs) ;
	void initIndexFieldList(HWND hDlg, int id, BOOL combo) ;
	BOOL rebuildAllIndexFiles(void) ;
	BOOL tryFastIndex(LPMFFILE f) ;
	BOOL recreateIndexFile(LPMFFILE ftb) ;
	void CRrDoc::startIndexSnooze(HWND hDlg, char* alias, char *table) ;
	void CRrDoc::stopIndexSnooze(void) ;
	static BOOL CALLBACK buildIndexSnoozeDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	BOOL UpdateSnooze(int i, int n) ;

	void moveString(HWND hDlg,int delta);
	void setFldState(HWND hDlg);
	void setFldStateNew(HWND hDlg);
	void setFocus(HWND hDlg, int status);
#else
	BOOL createIndexFile(HWND hDlg, CRrDoc *pDoc, PKREL *rs) ;
	char	indexExpression[SELEXBUF + 1] ;
	void CRrDoc::startIndexSnooze(HWND hDlg, char* alias, char *table) ;
	void CRrDoc::stopIndexSnooze(void) ;
	void initIndexFieldList(HWND hDlg, int id, BOOL combo) ;
	LPSTR	relPath;
	BOOL rebuildAllIndexFiles(void) ;
	BOOL tryFastIndex(LPMFFILE f) ;
	BOOL recreateIndexFile(LPMFFILE ftb) ;
	static BOOL CALLBACK buildIndexSnoozeDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	BOOL UpdateSnooze(int i, int n) ;
	LPSTR	dynamicPath;
	LPSTR	dynamicField;
	LPSTR	dynamicLen;
#endif	// #ifndef RSW

// stuff from vfpdata.cpp
public:
	BOOL bFileNew;
	BOOL bDBCMode;		// for Visual FoxPro DBC support
	DBCTBL * DBC_Map;	// DBC table/field map structure
	char szLongName[MAXDNAME];	// holds a long table or field name
	char szDBCMaster[WINPATHLEN];	// master table from DBC
	char szNewDBCMaster[WINPATHLEN];
	PSTR pickFromDBC(LPSTR DBCName);
	int openDBC(LPSTR DBCName, LPSTR errorfile);
	BOOL openDBCWithError(LPSTR DBCName);
	PSTR getTblPath (PSTR szTablename, PSTR szPATHNAME);	// short/long tablename conversion
	PSTR getLongTbl (PSTR szPathname);
	void deleteDBCMap (void);

	static BOOL CALLBACK dbcTableDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static BOOL CALLBACK dbcRelTableDialog(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);

/// Statics from dshowsql.cpp:
#if defined RSW
public:
	unsigned long oldLimit;

/// Statics from sddata.cpp:
private:
	BOOL descending;
	int ndxType;
	LPSTR mastPath;
	BOOL bGotStuff;
	int masterDSOff;	// data source offset for master
private:
	void enableMasterCtrls(HWND hDlg,BOOL enable);
	BOOL master_links(void);
#endif

/// Statics from sdrelate.cpp:
#if defined RSW
private:
	TCHAR alias[MAXALIAS];
	WORD fileNum;	// Line number selected in editRelations
	LPMFFIELD fromFld;
	BOOL OJokDS;
	BOOL OJokFrom;
	BOOL OJokTo;
	BOOL OJAnyCombo;
	BOOL ApproxOK;
	BOOL bMultiMode; 	// TRUE if in multi-column join mode
	LPFIELDNAME ToFlds;
	// from within sdrelate.cpp relateDialog routine:
	PKREL rs;
	int relType;
	int failure;
	int width,height;
	BOOL bToSelected;
	BOOL bNewToTable;	// TRUE if a new related table is chosen
	JOINPAIR *joinpairs; // array of MAXJOINPAIRS join specs
	int iNumJoinPairs;
private:
	void addToToFlds(LPSTR name,LPSTR comment);
	BOOL allocRfld(HWND hDlg, TCHAR **ptr);
	void cleanUpToFlds(void);
	BOOL editRelation(HWND hDlg, BOOL bNew);
	void EnableDelPair (HWND hDlg, JOINPAIR *joins);
	void EnableJoinButtons (HWND hDlg, BOOL bEnableApprox, int relType);
	void EnableOK(HWND hDlg, JOINPAIR *joins);
	void EnableOptions(HWND hDlg, BOOL bEnable, int relType, int failure, int iNumJoinPrs);
	BOOL fillToFields(HWND hDlg, BOOL bNeedOpen, LPSTR relfile, int filenum, LPSTR initSel);
	LPSTR getFieldName(int entry);
	int getFileNum(LPMFFILE lpFile);
	LPMFFIELD getFldFromName (LPSTR alias, LPSTR fldName);
	LPSTR getStringFromName(LPSTR name);
	static BOOL linkFldFilter(LPMFFIELD f);
	WORD listRelations(HWND hDlg);
	LPMFFIELD matchFld(TCHAR *szField, int iFile);
	BOOL noOJoutOf(LPMFFILE relfile);
	BOOL noOtherOJs(LPMFFILE from, LPMFFILE to);
	void NotCartesian(HWND hDlg);
	void PurgeToList (HWND hDlg, int i, JOINPAIR *joinpairs, TCHAR *szTest);
	static BOOL relFldFilter(LPMFFIELD f);
	void setRelFocus(HWND hDlg,int status);
	void showFromTable (HWND hDlg, JOINPAIR *joinpairs, int iNumJoinPairs);
#endif

/// From _print.h - variables
public:
	int		anybreaks;
	LPSTR	LinePtr;		// pointer to line pointer in local heap
	int		Snaking;		// indicates whether or not we are doing snaked cols
	int		SnkCurrCol;		// Current snaked column number (on the page)
	int		SnkNumCols;		// Number of columns requested by the user
	int		SnkTopMargin;	// Vertical location where snaked column should start
#if defined (READAHEAD)
	LPSTR	SnapBreakData;	// if reading ahead for widow/orphan
#endif
	bool	NoRecordsFound;	// true if, like, you know
	int		NoRecordsFoundLines;	// Number of lines with "NORF" property

/// From _print.h - function prototypes:
public:
	void checkPendingImages    (int when, int bandline, WORD y) ;
	void checkPendingCharts    (int when, int bandline, WORD y) ;
	void checkPendingOleObjects(int when, int bandline, WORD y) ;
	void checkPendingBoxes     (int when, int bandline, WORD y, WORD lineHite) ;
	void showchart (LPRRCHART);
	int endOfPage(int reset);
	int endOfPageBursting(int reset);
	void hzinit(void);
	int ckEOP(int lines,int flines);
	int eop_Sum_Tit(int when,int topsumnp);
	int topwhen(int when,int ckprint);
	LPSTR imbedcode(LPSTR buf, WORD code, WORD v1, WORD v2, WORD v3);
	LPSTR databuf(LPMFFIELD f,int when);
	int linehite(int line,int ifauto);
	BOOL brkOnce(LPMFFIELD curf);
	int fld_err_flags(LPMFFIELD f,LPSTR dataloc);
	int wrapper(LPSTR lbuf, LPMFFIELD f, int *wraps, int when, int clen, int crow, int *pushes, int hold);
	void setOnce(LPMFFIELD curf);
	int endwhite(int when,int log);
	BOOL willprint(int line,int when);
	BOOL fldsOnLine(int line);
	int last_grp_eject(int line,int when);
	void hzdump(int line);
	int moredata(int line,int when);
	int moregrps(int when);
	int outline(LPSTR lineBuf,int pgroom,int when,int *trailwhite,int line,int put,unsigned lineAscent, int whenrow);
	int hzflush(int top);
	int vtspace(int units);
	int groupFld(FLDID);
	int getlpr(int when,int blanks);
	int prSection(int when, BOOL bPreProcess);
	void setPage(int num);
	void eopCommon(int reset);
	void clrPgTot(void);
	void clrPOnce(int ind);
	void headfoot(int foot);
	void headfootbursting(int foot);
	int prGrpHead(int type);
	int titpage(void);
	int ckBreak(void);
	int pageFull(void);
	BOOL posBody(void);
	int prGrpFoot(void);
	int prGrpFootBursting(void);
	int printSum(void);
	BOOL ejectlines(int when,int nocheck);
	int totfield(LPMFFIELD fld, int pass);
	int setup(void);
	BOOL rpSetup(int type);
	void prtrep(int restart);
	void BurstingPrtRep(int restart);
	void rpreset(void);
	void resMult(void);
	int mustsort(void);
	int setMult(void);
	int abs_delta(int hi,int lo);
	WORD adjustToGridX(WORD x);
	void saveval(LPMFFIELD fld,TCHAR *dest, int nmax);
	BOOL novalue(LPMFFIELD fld,TCHAR *data);
	void setDone(int when);
	void resetBrk(int brk);
	void inittotals(void);
	int lasttotals(void);
#ifndef INTERACTIVE
    void runcancel(void);
#endif

/// From print_.h - function prototypes:
public:
	int  newatt(int a);
	int  fontstart(LPMFFIELD f, LPSTR s);
	void testPattern(void);
	void rprint(void);
	void BurstingRPrint(void);
	void clearTots(void);
	void CaptureAllTotals( void );
	BOOL selsort(void);
	int  prFF(int wait,int last);
	int  fldAlign(LPMFFIELD f);
	int  cvlhite(int h);
	int  swapping(int hf,int when,int sb);
	void moreneeded(void);
	static int ckAbort(void);
	int getLPS(int when,int eject,int lines);
#if defined RSW
	void setTempI(void);
#endif	
#if !defined(RSW)
    void saveneeded(int alltots);
#else
    void saveneeded(int alltots,int save);
#endif

/// Static functions from pline.cpp:
private:
	void adjust_snake_column (LPSTR lbuf, UINT size, int old_column, int new_column);
	DWORD hzheight(LPSTR linePtr, int line, int lasthite);
	int printline(LPSTR linePtr);

/// Static functions from prec.cpp:
private:
	WORD adjustToGridY(WORD y);
	WORD adjustToGridYB(WORD y);
	WORD adjustToGridYT(WORD y);
	int autoHite(LPRRBOX lpbox, int lineHite, BOOL bTop);
	void endAlign(LPSTR pLinePtr, int trimPix,int trimLen,int trimAlign);
	int fillLine(TCHAR far **pLinePtr, int prep, int crow, int when, int *pushes, int *wraps, int hold, int *lhite);
	void freeFldMem(TCHAR far **pLinePtr);
	int getFirstDib(LPRRIMAGE lpimg);
	LPSTR getFldMem(LPSTR pLinePtr, int flds, int size);
	void imbedBox      (LPRRBOX   lpbox, WORD endY, WORD lineHite);
	void imbedImage    (LPRRIMAGE lpimg, int endY);
	void imbedChart    (LPFLDHDR  f,     int endY);
	void imbedOleObject(LPFLDHDR  f,     int endY);
	BOOL noMoreWrap(LPFLDHDR f, int *wraps);
	LPFLDHDR nxtpfld(LPFLDHDR f, int crow, int when, int *pushes);
	BOOL overlap(LPFLDHDR pFld, int when, int *pushes);
	LPSTR posVertical(LPFLDHDR f, LPSTR fbuf);
	int ritePix(LPMFFIELD mf, int acrossPix);
	WORD screenToPrinterX(WORD x);
	WORD screenToPrinterY(WORD y);
	WORD screenToVert(WORD y);
	WORD screenToVertB(WORD y);
	WORD screenToVertT(WORD y);
	WORD vertToPrinter(WORD y);

/// Static functions from rphf.cpp:
public:
	BOOL printingHigherLevel(int ind);

/// Static functions from rplib.cpp:
private:
	int lnhite(int line);
	
/// Static functions from rpprep.cpp:
public:
	long rec_copies(LPMFFIELD f);

/// Static functions from rprint.cpp:
private:
	int flds(int line,int gotsome,int when);

/// Static functions from rpsetup.cpp:
private:
	int wraplook(int line);
               
/// Static functions from rpsort.cpp:
private:
	int breakfld(FLDID);
	void clrneeded(void);
#if defined(RSW)
	void rpneeded(int forSave);
#else
	void rpneeded(void);
#endif
	int rpSort(void);
	void sortneeded(void);
	int totalfld(int ind);
	void totneeded(int *chgP, int alltots);

/// Static functions from rptest.cpp:
private:
	void testpat(void);

/// Static functions from rpwrap.cpp:
private:
	WORD getFldChar(LPMFFIELD f, LPSTR p, int first, WORD *points, WORD *font, int charlen);
	BOOL pageline(int hi, int lo);
	int pbuffer(LPMFFIELD f, WORD *wbuf, WORD *ptbuf, WORD *ftbuf, TCHAR *lbuf, int len, BOOL nofull);


/// Static variables from totals.cpp:
public:
	int headerLines;

/// Static functions from totals.cpp:
private:
	void addTot(LPMFFIELD tfld);
	int breakChg(void);
	int cantOrphan(void);
	void clrTot(LPMFFIELD fld);
	void CaptureTot( LPMFFIELD fld );
	int countIt(LPMFFIELD f, int ind, int zero);
	int pgEject(int *eject);
	int readrecord(void);

/// Static functions from vputil.cpp:       
private:
	BOOL scandata(int when);

// from util.h - variables:
public:
//	int ZNVError;	// moved to App class
	FOUR DateConstant;
	TCHAR ZWild;		/* assume no secondary multi-wild character */
	TCHAR ZAny;		/* and no secondary single-wild character */
	TCHAR ZEscape;	/* and no escape character */
	int SRTRules;	/* assume no .SRT file */

	// These next (originally) came from zfcmp.c
	TCHAR UCount1;	/* number of lowercase elements in umlaut[] */
	TCHAR ACount1;	/* number of lowercase elements in accent[] */
	TCHAR ICount1;	/* number of lowercase elements in inequal[] */
	TCHAR UCount2;	/* number of elements in umlaut[] */
	TCHAR ACount2;	/* number of elements in accent[] */
	TCHAR ICount2;	/* number of elements in inequal[] */

	/* Added by CAS 08/23/2017 as a test for a global item to store an INI property */
	char ZcFirstDay[3]; /* pDoc->cFirstDay property to be set by the profile string? */

/* relative position in accent array determines which equivalent char
   sorts first */
// These 3 globals are only used by util\zfcmp.c and wmain\readsrt.c, I think. -syost
	ACCENT *accent;
	UMLAUT *umlaut;
	INEQUAL *inequal;
	int ZRFChanged;
	int ZRFCCol;
	int ZRFCPos;
	int ZRFData;
	TCHAR ZRFDec;
	int ZRFIDate;
	int ZRFGraph;

// end of util.h variables

// From util.h - functions
public:
	LPSTR  ldatadir(LPSTR buf) { return ldatadir(this,buf) ; }
	LPSTR  libdir  (LPSTR buf) { return libdir  (this,buf) ; }
	LPSTR  GetTemplateDirectory (LPSTR buf) { return GetTemplateDirectory  (this,buf) ; }
	static LPSTR  ldatadir(CRrDoc* pDoc, LPSTR buf);
	static LPSTR  libdir  (CRrDoc* pDoc, LPSTR buf);
	static LPSTR  GetTemplateDirectory(CRrDoc* pDoc, LPSTR buf);

private:
	static LPSTR dirname(LPSTR deflt, LPSTR resbuf);

// end of util.h functions

// from crstabif.h
public:
#if !defined(RUNDLL)
	LPEXPORTINFO lpEXPORT_Info;
	HINSTANCE XCALL_NewInteractiveExport (int handle, HWND hParentWnd,
		LPSTR lpszExportLine, LPSTR lpszTitle);
	BOOL XCALL_FreeExportInfo (void);
	HINSTANCE XCALL_NewRuntimeExport (LPSTR lpszTitle, int xPrint,
		LPSTR lpszOutputFile);
	SGDATA far *lpSG;
	WHENP far *lpBand;
#endif
// end crstabif.h

// statics from fldlist.cpp
// tried to make these private, but they are used by a static member function (callback).
public:
	int 		fldListUseCount;
	WNDPROC 	rrwFldProc;
	WNDPROC 	fldWinListProc;
	WNDPROC 	winComboProc;
	BOOL 		bCursorKey;
	int 		rulerLoc;
	int 		yLine;
	long 		yPix;

#if defined(INTERACTIVE) && !defined(RUNDLL)
	BOOL 		dragging;		// TRUE -> dragging in progress
	void		checkDrag(HWND hWnd, BOOL comboBox);
	void 		checkDrop(HWND hWnd, POINT point);
	void	 	checkMove(HWND hWnd, LPARAM lParam);
//private:	
	HCURSOR 	hDragCursor;	// okay to drop
	HCURSOR 	hNoDropCursor;	// no can drop

#endif

// statics from labels.cpp
private:
	LPSTR nextchar(LPSTR value);
	void trimend(LPSTR value);
	int validnum(LPSTR numstr);
	int getlabfloat(UTWO *dest,TCHAR **thisone,TCHAR **next,int factor,UTWO maxlen,UTWO maxval,int last);
	int getlabint(UTWO *dest,TCHAR **thisone,TCHAR **next,UTWO maxlen,UTWO maxval,int last);

// statics from wfile.cpp
private:
	void 	listbox_to_path(HWND hdlg, UINT ctrlid, LPSTR dest);
	DWORD getFilterInd(LPSTR ext, int id);
	void 	formatFilterString(int id, LPSTR filterbuf);
	BOOL initOfn( OPENFILENAME *ofn, BOOL bSaveDlg, HWND hWnd, LPSTR pFile, LPSTR stdir, int filter_id, LPSTR defext, int title_id, LPSTR templt );
	void freeOfnBufs( OPENFILENAME *ofn );
	BOOL bSaveDlg;
	WORD helpCode;
public:
	WORD dlgHelpCode;

/// statics from wglobal.cpp
private:
	#if defined INTERACTIVE
	void countFldTypes(int *chr, int *date, int *num, int *dateTime, int *time, int *text, int *total);
	#endif
	void checkGlobMeasure(int oldmeasure,int newmeasure);
	BOOL depressButton(HWND hWnd);

/// statics from wstring.cpp
private:
	void append(LPSTR s,int ch); // append the character
	int  countem(LPSTR p);

/// statics from werror.cpp
	HWND parentWnd(void);


/// From wutil.h
public:
	HHOOK hookLink;			// generic link used by dialogBoxParam/hookOn/hookOff
	HHOOK fileNewHookLink;	// link used by fileNewDlg

#if defined(OEM_ABRA)
	WORD OFUseTemplate
 #if defined(_WDIALOG_C_)
	= FALSE
 #endif
	;
#endif

	static LRESULT CALLBACK EXPORT numEditProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static DWORD FAR PASCAL dlgFilterHook(int nCode,WPARAM wParam,LPMSG msg);
	static LRESULT CALLBACK EXPORT fldListProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static BOOL CALLBACK EXPORT openFileHook(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
	static int CALLBACK EXPORT BrowseCallbackProc( HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData );

private:
	OPENFILENAME * OpenFileNT;
	BOOL	ispatternNT ( LPSTR file, LPSTR origfile );
	BOOL	openDlgCommonNT( HWND hWnd, LPSTR pFile, LPSTR stdir, int filter_id, LPSTR defext, int title_id, WORD help );
	static	BOOL CALLBACK EXPORT openFileHookNT( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );

public:
	void	colorSelectionState(LPDRAWITEMSTRUCT lpdis);
	void	drawColorEntry(LPDRAWITEMSTRUCT lpdis,BOOL none);
	void	measureColor(LPMEASUREITEMSTRUCT lpmis);
	void	spinOne(HWND hDlg,int spinner,int minspin,int maxspin,WORD sbCode);
	void	spinOneLong(HWND hDlg,int spinner,int minspin,long maxspin,WORD sbCode);
	void	spinTen(HWND hDlg,int spinner,int minspin,int maxspin,WORD sbCode);
	void	resetNumEditProc(HWND hWnd,BOOL free);
	void	setNumEditProc(HWND hDlg,UINT id);
	BOOL 	listFld(LPMFFIELD f, int fno, int (*ck)(LPMFFIELD));
	BOOL 	isComboBox(HWND hWnd);
	void	setNeeded(void) ;
	LPSTR	formatFldListEntry(TCHAR *buf, LPSTR fldname, int needed, LPSTR comment, TCHAR qmORs, LPSTR alias);
	int 	initFldList(HWND hDlg, int id, FLDID fldid, int (*ck)(LPMFFIELD), BOOL combo);
	int		getFields(HWND hDlg, int id, FLDID fldid, int (*ck)(LPMFFIELD), BOOL combo, int fieldType, int sortType) ;
	int		buildFIDList(FLDID **pfid, int (*ck)(LPMFFIELD)) ;
	int		cullFIDList(FLDID *sfid, FLDID **dfid, const char *name) ;
	int		searchFIDList(FLDID *PFid, const char *name) ;
	int		findFIDList(FLDID *PFid, FLDID fid) ;
	void	sortFIDList(FLDID *PFid, int sort) ;
	int		ftField(LPMFFIELD f) ;
	int		dtField(LPMFFIELD f) ;
	BOOL	needed(LPMFFIELD f) ;




	int		insertSortedName(HWND hDlg, int id, BOOL combo, LPSTR buf, LPMFFIELD f, int start, int end) ;

	static BOOL paramFldFilter(LPMFFIELD f) ;
	static BOOL indexFldFilter(LPMFFIELD f) ;
	int		initParamFieldList(HWND hDlg, int id, FLDID fldid, int (*ck)(LPMFFIELD), BOOL combo) ;

	LPMFFIELD getFldPtr(HWND hDlg, UINT id, int ind, BOOL combo);
	BOOL 	updateFldList(HWND hDlg, int id, int (*ck)(LPMFFIELD), BOOL combo);
	void	setFldListProc(HWND hDlg, int id);
	void	resetFldListProc(HWND hWnd);
	BOOL	TruncatePath (LPSTR lpszFullName, LPSTR lpszTruncatedName, int bufsize);
	BOOL	appendExt(LPSTR s,LPSTR ext,BOOL replace);
	int		bldIntDate(int m,int d,int y,BOOL longstr,LPSTR s);
	int		bldIntDateYearControl(int m,int d,int y,BOOL longstr,LPSTR s,BOOL bForce4DigitYear);
	void	buildCalcString(TCHAR far *string1, TCHAR far *string2);
	int		buildPic(LPMFFIELD fld,int testpat,int ch,TCHAR *pic);
	void	buildTot(LPMFFIELD fld,LPSTR lpRet,int alias);
	void	centerDialog(HWND hDlg);
	void	checkImages(int oldmeasure,int newmeasure);
	void	checkLineMeasure(int oldmeasure, int newmeasure);
	void	checkPrtOptions(int oldmeasure,int newmeasure);
	TCHAR	chevron(int font,BOOL left);
	//// statics due to access via pointer:
	static int ckLog(LPMFFIELD f);
	static int ckgroup(LPMFFIELD fld);
	static int cksort(LPMFFIELD fld);
	static int ck_cop_fld(LPMFFIELD f);
	////
	BOOL ckTotCalcName(HWND hWnd,LPSTR name,LPMFFIELD f);
#if defined(INTERACTIVE)
	BOOL cols_Snaked(void);
#endif
	int compint(unsigned int *first,unsigned int *second,int cnt);
	void computeRMCol(void);
	WORD convHz(WORD val,WORD newval,WORD old,WORD rp,BOOL orient);
	WORD convVt(WORD val,WORD newval,WORD old,BOOL orient);
	int copyFlds(BOOL unmark_orig,WORD set_bit);
	void defWhen(int line);
	void delSort(void);
	int dialogBox(HWND hWnd,DLGPROC rtn,LPSTR box);
	int dialogBoxX(HWND hWnd,DLGPROC rtn,int box);
	int dialogBoxParam(HWND hWnd,DLGPROC rtn,LPSTR box,LPARAM param);
	int dialogBoxParamX(HWND hWnd,DLGPROC rtn,int box,LPARAM param);
	void dialogHelp(HWND hDlg,WORD code);
	HBRUSH dlgColor(HDC hDC,LONG lParam);
	HFONT dlgHelpFont(HWND hDlg);
	LPSTR dotToSpace(LPTXFLD tf,LPSTR s);
	BOOL enableAlign(void);
	BOOL enableFont(void);
	BOOL enablePicture();
	BOOL errorMessage(UINT nID, CWnd *pWnd = NULL);	// string ID
	BOOL errorMessage(LPCSTR p, CWnd *pWnd = NULL);	// C++ zack1
	BOOL errorMessage( UINT nID, CWnd *pWnd, UINT nType );	// string ID, window, icon type
	BOOL errorMessage(UINT nID1, UINT nID2);	// two string ID's
	BOOL errorMessage(LPCSTR pFmt, LPCSTR p);	// C++ zack2
	BOOL errorMessage(LPCSTR pFmt, LPCSTR p1, LPCSTR p2); // C++ zack3
	BOOL errorMessage(LPCSTR pFmt, LPCSTR p1, LPCSTR p2, LPCSTR p3); // C++ zack4
	BOOL errorMessage(LPCSTR pFmt, LPCSTR p1, LPCSTR p2, LPCSTR p3, LPCSTR p4); // C++ zack5
	BOOL errorMessage(LPCSTR pFmt, LPCSTR p1, LPCSTR p2, LPCSTR p3, LPCSTR p4, LPCSTR p5); // C++ zack6
	BOOL errorMessage(LPCSTR pFmt, long l); // C++ zacknum
	BOOL errorMessage(LPCSTR pFmt, long l1, long l2); // C++ zacknum2
	BOOL errorMessage(LPCSTR pFmt, TCHAR c); // C++ zackchar
	LPSTR fileFromPath(LPSTR path);
	int fldTypeStr(LPMFFIELD f);
	LPSTR bandText(LPSTR bandtx,int when);
	int findBand(long y);
	int getColorIndex(COLORREF rgb);
	BOOL getDirDialog(HWND hWnd,LPSTR file,LPSTR stdir,int filter_id,LPSTR defext,int title_id,WORD help);
	LPMFFIELD getDupFld(LPMFFIELD sfld);
	LPMFFIELD getField(void);
	LPSTR getFifPath(void);
	void getInternational(void);
#if defined(INTERACTIVE)
	void get_Label_Descript(LPSTR statustext,LABDEF * labinfo);
#endif
	int getLen(LPMFFIELD fld);
	BOOL getPaperInfo(WORD paperSize, LPSTR paperName, int *plen, int *pwid);
	void getTempFileName(LPSTR prefix,LPSTR dest);
	LPTXFLD getTxFld(int size);
	void getWindowsTimes(void);
	void getWindowsDates(void);
	int intasc(WORD val,LPSTR str,int dec);
	void interr(int num);
	BOOL isHorzLineFld(LPFLDHDR f);
	BOOL line_log_page(FLDID fldid);
	int logOkay(void);
	void lowMemoryBox(LPSTR errtx);
	BOOL markedFieldsOnly(void);
	LPSTR masterDirectory(LPSTR mdir);
	void menuChoices(WORD wParam);
	BOOL onAlias(HWND hDlg,int id,BOOL combo);
	BOOL openFileDialog(HWND hWnd,LPSTR file,LPSTR stdir,int filter_id,LPSTR defext,int title_id,WORD help);
#if defined(INTERACTIVE)
	BOOL openFileMaster(HWND hWnd, LPSTR file, LPSTR stdir, int filter_id, LPSTR defext, int title_id, WORD help);
#endif
	BOOL openDirDialog(HWND hWnd, LPSTR file, LPSTR stdir, int filter_id, LPSTR defext, int title_id, WORD help);
#if defined(RSW)
	BOOL openFileDSOverride(HWND hWnd, LPSTR file, LPSTR stdir, int filter_id, LPSTR defext, int title_id, WORD help, BOOL *pbNoConnect = NULL);
#endif
	//BOOL openDirDialog(HWND hWnd, LPSTR stdir, int title_id);
	void paintIcon(HWND hDlg,WORD id,LPSTR icon);
	void readCurStr(void);
	int read_Label(LPSTR name, LABDEF *label);
	void rlsAll(void);
#if !defined(INTERACTIVE)
	LPMFFIELD prtFromAliasField(LPSTR alias, LPSTR field);
#endif
	BOOL sameMarkedFlds(BOOL one_text,BOOL nocharmix,BOOL sametype);
	BOOL saveAsDialog(HWND hWnd,LPSTR file,LPSTR stdir,int filter_id,LPSTR defext,int title_id);
	void setCharFldWidth(LPMFFIELD, UINT, BOOL);
	void setDupeFldListProc(HWND hWnd);
	void setDupeNumEditProc(HWND hWnd);
	void setEndRow(void);
	void setFldAlign(LPMFFIELD f,int lcr);
	void setFreeformLine(WORD line,WORD hite);
	void set_Label_Metrics (LABDEF * label);
	BOOL set_Label_PrOpts (LPSTR name, BOOL snaked);
	void setLogStrLen(void);
	void set_Snaked(BOOL snaked,int across);
	int setWhen(int when,int setline);
	void sizeUp(void);
	BOOL snapOverride(void);
	BOOL sortOkay(void);
	int strToInt(LPSTR str,int *val,int dec);  // p2 was a WORD
	void textOEMtoANSI(LPTXFLD tf);
	BOOL wheniffld(int ind);
	void winBeep();
	BOOL writeProfileInt(LPSTR app,LPSTR key,int value);
	BOOL zbusy(BOOL on);
	BOOL rwack1(HWND w,LPCSTR format);
	BOOL rwarn1(HWND hWnd,LPCSTR format);
	BOOL wack1(HWND w,LPCSTR format);
	BOOL wack2(HWND w,LPCSTR format,LPCSTR a);
	BOOL wacktive1(LPCSTR format);
	BOOL wwarn1(HWND hWnd,LPCSTR a);
	BOOL wwarn2(HWND hWnd,LPCSTR a,LPCSTR b);
	BOOL zack1(LPCSTR format);
	BOOL zack2(LPCSTR format,LPCSTR a);
	BOOL zack2run(LPCSTR format,LPCSTR a);
	BOOL zack3(LPCSTR format,LPCSTR a,LPCSTR b);
	BOOL zack4(LPCSTR format,LPCSTR a,LPCSTR b,LPCSTR c);
	BOOL zack5(LPCSTR format,LPCSTR a,LPCSTR b,LPCSTR c,LPCSTR d);
	BOOL zack6(LPCSTR format,LPCSTR a,LPCSTR b,LPCSTR c,LPCSTR d,LPCSTR e);
	BOOL zackchar(LPCSTR format,TCHAR a);
	BOOL zacknum(LPCSTR format,LONG a);
	BOOL zacknum2(LPCSTR format,LONG a,LONG b);
	void zfatalerr(int errorCode,int extraData);
	BOOL zwarn1(LPCSTR format);
	BOOL zwarn2(LPCSTR format,LPCSTR a);
	BOOL zwarn3(LPCSTR format,LPCSTR a,LPCSTR b);
	BOOL zwarn4(LPCSTR format,LPCSTR a,LPCSTR b,LPCSTR c);

	LPSTR globalAlloc(WORD flags,DWORD size);
	BOOL globalFree(LPVOID pMem);

// obsolete w/ new heap functions
//	UINT globalHeapMin(void);

	LPSTR globalReAlloc(LPSTR pMem,DWORD size);
	DWORD globalSize(LPSTR pMem);
//	PSTR localAlloc(WORD flags,WORD size);
//	void localFree(PSTR hMem);
//	PSTR localReAlloc(PSTR pMem,WORD size);
//	WORD localSize(PSTR hMem);

//	#ifdef RSW
//	int 	initSTFldList(HWND hDlg,int id,LPMFFILE lpMffile,LPSTR curFld,int (*ck)(LPMFFIELD),BOOL combo);
	int 	initSTFldList(LPMFFILE lpMffile, LPSTR curFld, int (*ck)(LPMFFIELD));
//static	BOOL	toFldFilter(LPMFFIELD f) ;

//	#endif

// pic.h - variables
public:
	int LogStrLen;
	int CurStrLen;
	int PicAllowOflo;	/* TRUE=> don't *-fill on col width overflo */
// new picshape.cpp function
	unsigned short SpaceDot(LPPRT_FACE fonts,LPSTR lineDraw,int numFaces,int font);

// _pic and _pic.h - functions
	int charalign(LPMFFIELD fld,TCHAR *cp,int col,int alignment,int align,int mode,int head);
	void ictib(int c,int count,TCHAR *s,int before);
	void commas(TCHAR *num);
	void fixed(struct mffield FAR *fld,TCHAR *out);
	void zcomposedate(TCHAR *month, TCHAR *day, TCHAR *year, TCHAR *out, unsigned int picture);
	void zcomposetime(int dispErr,TCHAR hours, TCHAR minutes, TCHAR seconds, long mSeconds,unsigned int picstyle, LPSTR out);
	void zcomposetimeshape(unsigned int picstyle, TCHAR *out,int font);
	void bldIntTime(int dispErr, TCHAR hours, TCHAR minutes, TCHAR seconds, long mSeconds, LPSTR out, BOOL space);
	int	 DateTimeCharCount(LPMFFIELD fld);
	int  picshape(LPMFFIELD fld, TCHAR *out);
	int  pictest(LPMFFIELD fld, TCHAR *out, TCHAR *suffix);
	int  picdata(LPMFFIELD fld, TCHAR *out, TCHAR far *data, int col, int mode, TCHAR *endbuf);
	int  winDateShape(int pic,LPSTR buf,int font); // build string for picshape()
	void winTimeShape(TCHAR *out, int font);
	
#ifdef RSW
	void picDateToDatetime(LPMFFIELD fld, unsigned int oldpics);
#endif
// statics from pic routines
private:
	TCHAR far * datap(LPMFFIELD fld, TCHAR far *data); // where the data is
	void fixexp(TCHAR *s); /* msc E format shows 3 exp digits, we show 2 */
	void append(LPSTR s,int ch,int font); // append the character
	void pic_append(LPSTR s,int ch); // append the character
// end pic.h

// wmain.h
public:
	void	getSQLDefs();
	BOOL	getSQLFlags();
#if defined (INTERACTIVE)
	BOOL	getsnumber(HINSTANCE hPrev);
#endif
	void	loadCursors(void);
//private:  WRR157933
	BOOL	bInit;

// wmain.h - variables
public:
	BOOL	SelBasedRep;	// indicates File->New->Select Based Report
	BOOL	CSVKeepNums;
//	BOOL	CSVKeepDates;  WRR157933
	int		CSVKeepDates;
	HCURSOR	hBandCursor;	// when in band area
	HCURSOR hLineCurDn;		// when on freeform border
	HCURSOR hLineCurUp;		// ditto
	int		GoArg;
	int		DLLArg;			// /D in interactive, /DL in runtime
#if !defined (INTERACTIVE)	// Runtime arguments from wrtmain.cpp
	int		DArg;
	int		EArg;
	int		IArg;
	int		OArg;
	int		RArg;
	int		SArg;
	int		FXArg;		// AMH 3/3/97 added new data member for RRW to have right-click send to fax
	int		MAPIArg;	// Export MAPI
	int		WArg;
	int		XArg;
	int		HIArg;		// repstuff handle for talking directly to runtime DLL for RI_Values
	int		HOArg;		// flag indicating asynchronous call to runtime EXE
	int		HSArg;		// Stack segment value (unsigned decimal integer string)
	int		HArg;		// /H -> suppress title/summary if no recs found
 #if !defined (RSW)  
 	int		TArg;
 #else
 	int		PArg;
  	int		CPArg;
	int		UArg;
	int		CUArg;
	int		CDArg;
	int		CSArg;
	int		RIArg;
 #endif
#endif
	BOOL	DisableTxtX;	// disable text export
	BOOL	DisableDbfX;	// disable dbf export
	BOOL	DisableWksX;	// disable wks export
	BOOL	leftDown;
	BOOL	rightDown;
//#if defined(INTERACTIVE) && defined(RECORD_FILTER)
#if defined(RECORD_FILTER)
	int		QArg;
#endif
#if defined(DATADICT)
	int		LevelArg;
#endif
#if defined(PASSWORD_REQD)
	int		PasswordArg;
#endif

public:

#if 0	// It's no longer appropriate to create a "standard" report
		// library for Version 7.0.
	void	 makeStdLib(LPSTR path);
#endif

	BOOL	minit();
	void	initGlobDefs(void);
	BOOL	wInit(int nCmdShow, HINSTANCE hPrev);
	void	wReset(void);
	BOOL	docInit(void);
	void	initPDFPrinterDriver(void) ;
#if defined(RSW)
	void	initDataDirect(void) ;
#endif

private:
#if defined(SOLOMON)
	BOOL	getSolomonDLL(int *mode);
	void	freeSolomonInit(void);
#endif

	// static variables from readsrt.cpp
private:
	int cntcmp;
	int cntsrt;
	int cntsrtc;
#if !defined RSW
	int cntixc;
	int cntixs;
	int cntixcmp;
#endif
	int cntdbc;
	int cntsrtch;
	int cntcmpc;
	int SRTAnsi;
	int cntspace;

	// prototypes from readsrt.cpp
public:
	void readsrt(void);
private:
	void tokend(ARGS *args);
// end wmain.h

// From wclip.h - variables:
public:
	int		cutCopyBand;
	BOOL	doLineProperties ;		// do line Properties after creating limes

// From wclip.h - functions:
public:
	void	trashIt(void);
	void	wipeDeletes(BOOL bar);
	LPFLDHDR getFirstMarked(void);
	void	delRest(void);
	VOID	pasteText(void);
	void	pasteIt(void);
	void	wipeClips(void);
	void	cutCopy(BOOL cut);
	void	zapDeleted(WORD flag);
	void	undoIt(void);
	void	redoDeleteFields(int count, void *data) ;
	void	undoDeleteFields(int count, void *data) ;
	void	redoDeleteLines(int count, void *data) ;
	void	undoDeleteLines(int count, void *data) ;
	void	redoInsertFields(int count, void *data) ;
	void	undoInsertFields(int count, void *data) ;
	void	redoFormat(int count, void *data) ;
	void	undoFormat(int count, void *data) ;
	void	redoInsertLines(int count, void *data) ;
	void	undoInsertLines(int count, void *data) ;
	void	redoLineInsert(int count, void *data) ;	//tl
	void	undoLineInsert(int count, void *data) ;	//tl
	void	UndoList(void) ;
	static BOOL CALLBACK UndoListDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
	void	delmarked(void);
	void	clearLayout(BOOL invalidate);
	void	UndoFormatLine(char *KStr, int k) ;
	void	RedoFormatLine(char *KStr, int k) ;

/// Static functions from wclip.cpp:
private:
	int find_hrow(int startrow, int oldrow);
	LPFLDHDR firstMarked(void);
	int pasteFlds(BOOL *bChangeToAUTO);
	BOOL pasteLines(int *ytop, BOOL *bChangeToAUTO);
	void setTwoDimBottom(void);
	BOOL storeLines(WHENP far *dest, BOOL zap);
	void unClipFields(BOOL bSetRow, int row);

/// Function prototypes from wdisplay.h:
////  New for Version 7  ////
public:
	void invalidateView(UINT uHint, BOOL bErase);
	void invalidateView(UINT uHint, BOOL bErase, LPRECT lpRect);

/// Function prototypes from wlayout.h:
public:
	void    alignToGrid(LPFLDHDR f);
#if defined INTERACTIVE
    int		centerCol(LPFLDHDR f);
#endif
	HFONT	createHelvFont(int height, WORD weight);
	HFONT   createScreenFont(WORD font,WORD att,WORD pts);
	BOOL 	createScreenFont(CFont *, WORD, WORD, WORD);
	void    deleteFonts(BOOL bSetDef);
	void    deleteLastFonts(int flag);
	void    delKey(void);
	int     fieldCaret(LPMFFIELD f);
	void	fieldEdit(POINT point);
	void	fieldFormat(void);
	BOOL    fieldPropMenu(POINT point);
	void	keyFldProperties(void);
	void	keyLineProperties(void);
	int     findFace(LPSTR pFace, BOOL bDef);
	int     findFixedFont(void);
	WORD	findPts(WORD font, WORD points);
	long    findYGrid(int line,long yPos);
	void    fontChange(BOOL fixflds);
	BOOL	formatCharField(LPMFFIELD);
	BOOL	formatDateField(LPMFFIELD);
	BOOL	formatDateTimeField(LPMFFIELD);
	BOOL	formatTimeField(LPMFFIELD);
	BOOL	formatNumericField(LPMFFIELD);
	void	formatName(LPMFFIELD pField) ;
	BOOL	changePrefs(void) ;

	int     getColFromPix(int pix);
	DWORD   getFldPixWidth(LPFLDHDR f, HFONT font, LPSTR s, int *desc, int *hlen);
	int     getFontPixHiteFromPoints(WORD points);
	int		getHzPixFromInches(int inches);
	LPFLDHDR getNextBandObject (LPFLDHDR f, int iBand);
	void	getBodyBandsTableAttributes ( CObList *pBandTableInfo, int *iNumTableCellsOut);

	// sp 12/30/96 added recacross as last parameter
	// sp 11/04/96 function broken out of getBodyBandAttributes
	void	AddTableEntry (CObList *pBandTableInfo,  int iTrimAlign, long lTrimLen, LPFLDHDR prevF, LPMFFIELD prevField, long lYPositionPix, long *lPositionPix, int iRecAcross);
	long	GetPositionPix(LPFLDHDR f, LPMFFIELD mff, int *iTrimAlign, long lYPositionPix, long *lTrimLen);
	
	// sp 11/06/96 get the font name from the given handle
	CString CRrDoc::GetFontName(HFONT hfont);

	int     getPixFromStr(HFONT hFont,LPSTR s,int len);
	int     getPixCol(int x);
	int     getPixFromCol(int col);
	int     getPixLineHite(WORD hite,WORD measure);
	int		gridMovePix(LPFLDHDR f, BOOL bInsert);
	int     horzGrid(int x, int align);
	void    insKey(void);
	BOOL    linePropMenu(POINT point);
	void    keepInHorzRange(LPFLDHDR f,int width);
	int		pixToInchCm(int pix);
	int		ptsFromPix(int pix);
	void	initFonts(void);
	void	keepInVertRange(LPFLDHDR f);
//	onField() is now in CRrView
//  LPFLDHDR onField(POINT point);
	int     pixToInchCmX(int pix);
	void    resetDefFont(void);
#if !defined(INTERACTIVE)
	int		findTypeFaceInList( LPTSTR pFace );
	void	storeTypeface( LPFLDHDR f );
#endif
	void    resetFont(LPFLDHDR f,BOOL setdef);
	void    setFldMetrics(LPFLDHDR f);
	BOOL    sizeBandsFlds(BOOL bSqueeze, WORD skip_line);
	void    sizeFlds(BOOL bSetDef, BOOL bOldReport, BOOL bUseCol);
	int     snapLineHite(int mode,int pix);
	int     snapVertical(int pix);
	int     vertGrid(int row,int y,int align);
	int     yGridPix(void);

/// Statics from wfont.cpp:
private:
	int firstFont;
	int fontIndex;
	
	WORD autoHite(int line);
	BOOL dupeFace(LPSTR faceName);
	BOOL dupeSize(int size);
	
// SP 1/8/97 used to load fonts if there are no printers installed
#if !defined(INTERACTIVE) 
	void CRrDoc::LoadAllFonts();
#endif

	static int CALLBACK EXPORT enumAllFaces(const ENUMLOGFONT FAR *, const NEWTEXTMETRIC FAR *, int, LPARAM);
	static int CALLBACK EXPORT enumAllFonts(const ENUMLOGFONT FAR *, const NEWTEXTMETRIC FAR *, int, LPARAM);
	WORD findPrtFont();
	HFONT fldFontMade(WORD font, WORD att, WORD pts);
	WORD fldHeight(WORD line, WORD *dhite, BOOL bSqueeze);
	BOOL fontUsed(HFONT hFont, BOOL bCheckDef, int flag);
	void initFldFonts(BOOL bSetDef);
	void setDefFonts();
	void sortByTypeface();
	void updateDefFonts(HFONT hFont);

/// Statics from wformat.cpp:
private:
	TCHAR firstTextChar[2];

/// Statics from winsdel.cpp:
private:
	void insDelFld(BOOL bInsert);
	int insOkay(void);

/// Statics from wpix.cpp:
private:
	long findYTopGrid(int line, long yPos);
	int pixAdjustToGridX(int x);
	void setFldHorzPixFromCol(LPFLDHDR f, int col);

/// From wbox.cpp
public:
	RECT 		boxRect;
	int		boxSides;
private:
	int		curBox;
	int	 	boxTrack;
	int		boxThick;
	int		boxAlign;
	int		xdMove;
	int		ydMove;
	LPFLDHDR boxFld;

public:
	void 		removeBoxes(void);
	int 		boxRow (LONG boxtop);
	COLORREF 	screenColor(int index);

#if defined INTERACTIVE
	void		copyBoxAttrs(LPFLDHDR first);
	void		copyLnAttrs(LPFLDHDR first);
	void		boxFormat(void);
	BOOL		boxStretch(void);
	BOOL		setBoxCursor(void);
	void		setBoxLoc(int box); 	
	UINT		findBox(LPFLDHDR f);
	void		startBoxDrawing(BOOL line);
	void		endBoxDrawing(void);
	void		minLineBox (LPRECT pr);
void nonClientBoxRect(POINT point,int xmove,int ymove);
void insertLine(POINT org, POINT newpt);
BOOL moveBoxRect(POINT point);
BOOL selectLine(POINT point, BOOL bMouseDown);
BOOL selectBox(LPFLDHDR f, POINT point, BOOL bMouseDown); 
BOOL markBox(POINT point);
void zapLineBox(int index,BOOL dsp);
void delBox(void);
LPFLDHDR copyBox(int n);
LPFLDHDR insertBox(LPRECT prect,int type_bit);
void chartFormat(void);
void delChart(void); 					// zap current one
void zapChart(int index,BOOL dsp);		// zap it from index passed
BOOL bFieldsToChart(void);				// helper fn to check if tables have a numeric field to chart
#endif
static BOOL ChartFldFilter(LPMFFIELD f);	//chart filter that only gets numeric fields
static BOOL ChartLabelFilter(LPMFFIELD f);	//chart filter for labels, typically all fields

/// From wbitmap.cpp
public:
	RECT imgRect;
private:
	UINT curImage;
	UINT curChart;
	BOOL imgTrack;
	int display_bits;
	int hClip;
	BOOL bMainPalSet;  // Indicates that a palette was installed for the MainDC.
	    			   // Purpose is to avoid calling RealizePalette if we haven't
		    		   // installed a palette yet.
			    		// Set only in this file, only checked in wrmain.c
    
public:    
// The functions that start with img_ interface directly to the image library.
	BOOL	loadChartLib(void);
	int		chartSetFont(LPTSTR pbaseFont, LPTSTR pnewFont,int iSize, int iFamily);
	HENHMETAFILE chartToMF (LPRRCHART, int, LPSTR *, int, double*, LPTSTR *);

	BOOL	loadImageLib(void);
	int		img_sync_pd(void) ;
	int		img_load(LPSTR lpFile);
	int		img_copy(int hDib, int scale, int width, int height) ;
	int		img_save(int hDib, LPSTR lpFile, int type);
	int		img_display(int hDib, HDC hDC, int left, int top, int width, int height);
	int		img_displayx(int hDib, HDC hDC, int left, int top, int width, int height, RECT *);
	int		img_palette(int hDib, HDC hDC);
	HPALETTE img_get_bitmap_palette(int hDib) ;
	int		img_setcrop(int hDib, int left, int top, int right, int bottom);
	int		img_delete(int hDib);
	int		img_purge(void) ;
	int		img_promote_24(int hDib);
	int		img_display_ddb(HBITMAP hDdb, HDC hDC, int xpos, int ypos);
	HBITMAP	img_dib_to_ddb(int hDib, int xsize, int ysize);
	HGLOBAL	img_info(int hDib, int far *pwidth, int far *pheight, int far *pbits);
	int		img_mediancut(int hDib);
	int		img_diffusion(int hDib);
	int		img_create(LPBITMAPINFOHEADER lpbi);
	int		img_create_ddb(HBITMAP hBitmap, HPALETTE hPalette);
	void	img_showerror(HWND hwnd, int err);

	WORD	adjustXGrid(WORD x);
	WORD	adjustYGrid(DWORD y);
	void	setInches(LPFLDHDR f);
	int		imgRound(int dimension);
	int		getClipboardImage();
	void	setCurImage();
	void	setCurChart();
	BOOL	getImageFile();
	BOOL	getImageField(HWND);
	BOOL	getChartInfo();
	int		onImage(POINT point); 
	int		onChart(POINT point); 
	void	delImage(void); 		// zap current one
	LPFLDHDR noImage(void);
	void	pasteBitmap(void);
	BOOL	moveImageRect(POINT point);
	void	nonClientImageRect(POINT point,int xmove,int ymove);
	BOOL	installPalette (int nImage);
	void	insertBitmap(BOOL clipboard, LPRECT prect);
	void	newBitmapImageField(int when, LPRRIMAGE lpimage);
	void	deleteAllFieldBitmaphDib(void) ;
	void	insertBitmapField(LPRECT prect);
	void	insertChart(BOOL clipboard, LPRECT prect);
	void	createDDB(int image,BOOL bDelete);
	LPFLDHDR copyImage(int n);
	LPFLDHDR copyChart(int n);
	void	setMediancut(int hDib,int bits_pix);
	void	getDisplayBits(void);
	BOOL	updateDisplayBits(void);
	BOOL	markImage(POINT point);
	void	endImageOutline(void);
	void	setImageCrop(int i, int left, int top, int width, int height);
	void	validCropRect(LPRRIMAGE img);
	void	imageFormat(void);
	void	setRrChart(CChartSheet* pChartDlg, CRrChart* pRrChart, LPRRCHART pChart);
	void	removeImages(void);
	void	removeCharts(void);
	void	zapAnImage(int index,BOOL dsp);
	BOOL	imgStretch(void);
	int		findImage(LPFLDHDR f);

// OLE Object stuff. 
CRrCntrItem* findOleObject(LPFLDHDR f) ;
CRrCntrItem* findCurrentOleObject() ;
CRrCntrItem* GetNextOleObject(POSITION& pos) ;
int          GetOleObjectCount() ;

int findChart(LPFLDHDR f) ;

void startImageOutline(void);
void startImageOutlineField(void);
void startChartOutline(void);
DWORD pixToInchX(int pix);
DWORD pixToInchY(DWORD pix);
BOOL setImgCursor(void);
void setImageLoc(int img        );
void setChartLoc(int nChartIndex);
void setOleObjectLoc(CRrCntrItem* pItem);
BOOL selectImage(LPFLDHDR f,POINT point, BOOL bMouseDown);
BOOL selectChart(LPFLDHDR f,POINT point, BOOL bMouseDown);
BOOL selectOleObject(LPFLDHDR f,POINT point, BOOL bMouseDown);
void invalidateImages(void);
void setImagePalette(BOOL bPrint);

LPRECT fixRect(LPRECT rc, LPRECT frc);
void nonClientOutline(LPRECT prect,POINT point,int hzjmp,int vtjmp);
BOOL needToScroll(POINT point);
void keepRectOnScreen(LPRECT prect,int xsize,int ysize);
BOOL stretchableData(LPFLDHDR f);

/// From rptxflds.cpp
void txrlsfld(LPTXFLD f);
LPTXFLD txgetfld(void);

/// From wfield.h
void editText(UINT key);
void textEditDone(BOOL okay);
BOOL checkText(CMainFrame *pMainWnd, CEditText *pWnd, BOOL *bHiteChange);
int  truncateText(CMainFrame *pFrame, CEditText *pWnd, LPSTR szTxt, int nLen);
void textFieldProp(LPTXFLD);

/// From wprintui.h - variables:
public:
#ifdef WIN32
	DWORD dwCurrentTaskId;
#else
	HTASK hCurrentTask;
#endif

/// From wprev.cpp:
private:
	BOOL createPreviewView(CMainFrame *pFrame);
	BOOL destroyPrevView(CMainFrame *pFrame);

/// Statics from wprint.cpp:
private:
	LPDEVMODE pSaveDevMode;
private:
	int prtErrMess(BOOL preview, int id);
	LPSTR fldTypeString(unsigned long type);

/// From wprintui.h - functions:
public:
	void checkForCancel(void);
	void checkPrtChange();
	LPMFFIELD cklinks();
	BOOL createStatDlg(BOOL);
	void destroyStatDlg(void);
	void dspCopies(int);
	void dspPgNo(void);
	void dspRecCnt(BOOL);
	void dspRecsExp(BOOL); 	// display current page number
#if defined RSW
	void finalPrintInfo(int read, int selected, LPSTR rd, LPSTR sel, int limited);
#else
 	void finalPrintInfo(int read, int selected, LPSTR rd, LPSTR sel);
#endif
	BOOL fldsOnNewPage(BOOL err);
	int getDefaultTray(void);

	//  changed original getPrinterDriver to a 2-argument version to signal whether to set the default printer or not
	//  done by CAS 12/04/2017 Rev 1.316 
	// BOOL getPrinterDriver(BOOL bClear);
	BOOL getPrinterDriver(BOOL bClear, BOOL bLPIDefa);

	void prePrintInfo(int, int, int, int, LPSTR, LPSTR, LPSTR);
	void prevPrtPageDlg(HWND);
	BOOL printPreview(BOOL);
	BOOL printReport(BOOL, BOOL);
	void setPrevIndents(void);

/// From _wprintui.h - functions:
public:
	static int CALLBACK EXPORT abortProc(HDC hPr,int code);
#if defined RSW
	LPMFFIELD ckjoinpairs(LPMFFILE file);
#endif
	int initPrinter(int);
	void prePrintDlgClose(void );
	int prePrintDlgOpen(void );
	int printCheck(void);
	void printCleanUp(void);
	int printCommon(void);

/// Statics from wprop.cpp:
private:
	void appendMenuItem(CMenu *pMenu, UINT nID, UINT nStrID);

/// From wreport.h - function prototypes:
public:
	BOOL readScriptFile(void);

/// From wutil.h - function prototypes:
public:
	void buildTermFromPacket(struct pksx far *pk, LPSTR term);

	// ============================= begin WREPORT directory ============		

// public Globals from wreport.h
public:
	BOOL	bNoMaster;
	// Summary info should contain title.  Since the title is 
	// already defined in the document, just keep a reference to 
	// it in the summary info class. 
	CString& GetTitleReference() { return m_strTitle ; }
	// This is tricky stuff.  When the MRU is used to load a report library,
	// We set the title to the correct report name, then the MFC sets it back 
	// to the file name.  The goal by overriding the virtual function is to 
	// prevent the MFC from setting the title when a library is loaded. 
	// We can still set the title with our own private call. 
	#if defined(RUNDLL)
	virtual void SetTitle(LPCTSTR lpszTitle) { if ( !m_bHaveLibrary ) CDocument::SetTitle(lpszTitle) ; }
	void SetRrTitle(LPCTSTR lpszTitle) { CDocument::SetTitle(lpszTitle) ; }
	#else
	virtual void SetTitle(LPCTSTR lpszTitle) { if ( !m_bHaveLibrary ) COleLinkingDoc::SetTitle(lpszTitle) ; }
	void SetRrTitle(LPCTSTR lpszTitle) { COleLinkingDoc::SetTitle(lpszTitle) ; }
	#endif

// private Globals from wreport.h
// private:	// must be public, so static dlgproc can call them.
public:	
	#if defined(RSW)
	TCHAR 	Copy_dpath[PATHLENGTH+2];
	TCHAR 	Copy_path[PATHLENGTH+2];
	int	Copy_platform ;
	TCHAR 	Copy_schema[PATHLENGTH+2];
	#endif
	// No longer using the open lib flag. 
	//BOOL	te mplLibOpen;
	BOOL	templLibRead;

// statics from wreport\wiz.cpp
public:
	#if defined(INTERACTIVE)
	BOOL	bWizardExecuting;
	#endif

// publics from wreport\rpinit.cpp
public:
	void	initRep( void );
	void	rpinit( BOOL Retrieving, int reportType );
	#if defined (INTERACTIVE)
	void	multifix(void);
	#endif

// from wreport\rpinit.cpp
public:
	 #if defined(RSW)
	void	rprepfld( FLDID, FLDID );
	 #endif
	
// statics from wreport\rprepfix.cpp
private:
	#if !defined(RSW)
	static int	nextone(CRrDoc* pDoc, int i, int when );
	static int	nextgroup(CRrDoc* pDoc, int i, int when );
	void	insEject( int look, int (*doit)(CRrDoc* pDoc, int,int), int when );
	#endif
public:
	#if !defined(RSW)
	void	ejectfix( LPSTR opts );
	void	labelfix( void );
	#endif
	void	sumhffix( void );

#if defined (RSW)
// public routines from wreport\sconnect.cpp
public:
	void	showPlatform( void );
	int	dataSourceDlgs( BOOL bSelect );
	BOOL	autoConnect( LPSTR lpszDS );
	#if defined(INTERACTIVE)
	BOOL	connectAndChooseTable( BOOL bSelectTable, BOOL bAlwaysShowDataSourceDialog, BOOL bCustomDlg );
	BOOL	chooseTable( BOOL bCustomDlg );
	#endif

// static data & private routines from wreport\sconnect.cpp
private:
	int	iDataSources;
private:
	void	setUserSelect( void );
#endif


// public routines from swrepcpy.cpp & xwrepcpy.cpp
public:
	void	reportCopy( LPSTR lib, LPSTR oldrep, LPSTR newrep );

// static data from xwrepcpy.cpp (used in both RRW and RSW)
private:
	YYFILETAB	*DestFile ;
	int			overwrite ;
	LPYZNAME		yzn ;

// static routines from xwrepcpy.cpp (used in both RRW and RSW)
private:
	void	rc_cleanup( void );
	int	rc_transfer( long, long );
	int	rc_write_record( int, int, LPSTR );
	UTWO	rc_yxgethead( YXBUF *buf, int *ct );

// static routines from winst.cpp
private:
	int	textWidth( LPSTR s );
	int	dataWidth( LPMFFIELD fld );
	BOOL	makesum( LPMFFIELD sf, int totals );
	int	instantRep( void );
	LPMFFIELD	makecalc( LPSTR name, LPSTR formula, int len, int row, int col, int trim, int commentID );
public:
	LPTXFLD		makeTextField( LPSTR tx, int r, int c, int a, int align, int trim );

// public routines from wiz.cpp
public:
	#if defined (INTERACTIVE)
	BOOL	openWizardEXE( void );
	BOOL	launchVBWizard( void );
	void	readWizardScript( WPARAM wParam );
	#endif

// static data and routines from wiz.cpp
private:
	CFile	wizFile;		// output file

	int	compRMCol( void );
	BOOL	writeCRLF( void );
	BOOL	wiz_writeString( LPSTR lpStr );
	BOOL	writeKeyData( LPSTR lpKey, LPSTR lpData );


// public routines from wlib.cpp
public:
	#if 0
	BOOL	createLib( HWND hWnd, BOOL new_only );
	#endif
	BOOL	openReportLib( HWND hWnd, LPSTR lname, YYFILETAB **ft, int mode, BOOL *oldrep );
	#if defined(RSW)
	void	timestamp( ZDATE *date, ZTIME *time, LPSTR user, HWND hWnd, int saved, int id, LPSTR lpszDS );
	#else
	void	timestamp( ZDATE *date, ZTIME *time, LPSTR user, HWND hWnd, int saved, int id );
	#endif

// static routines from wlib.cpp
private:
	#if 0	// was defined INTERACTIVE
	BOOL	crLib( HWND hWnd, BOOL new_only );
	#endif

// public routines from wrepfix.cpp
public:
	void	adjustImages( void );
	void	adjustObjectY( void );

// static routines from wrepfix.cpp
private:
	BOOL	findTypeFace( LPSTR face );
	void	lookForFace( UINT font, LPSTR ftab, LPSTR face );
	void	fixFont( LPFLDHDR f, LPSTR ftab );
	void	fixTrim( LPFLDHDR f );
	void	fixPic( LPMFFIELD f );
	BOOL	pLenToSize( TCHAR measure, BOOL orient, UINT plen, UINT englen, UINT engwid, UINT metlen, UINT metwid );
public:
	// not static but still private - not any more, CRrRepIO needs 'em
	void	convertPageSize( void );
	void	convertToWindows( LPSTR fifpathname );
	void	fixUpFldLocs( int repInchX, int repInchY );

// static data from wreport.cpp
private:
	HOOKPROC	lpHook;

// public routines from wreport.cpp
public:
#if defined RSW
	BOOL	fileOpen( BOOL *pbNoConnect = NULL );
#else
	BOOL	fileOpen( void );
#endif
	VOID	hookOff( void );
	VOID	hookOn( void );
	void	toLimbo( BOOL reset );
	void	setMenus( void );
#if defined (INTERACTIVE)
	BOOL	saveOrSaveAsDialog( BOOL bSaveAs );
	BOOL	saveReport( BOOL saveAs );
	void	GenerateSerialNumber(void) ;
	void	LaunchLibrarian(void) ;
#endif
	BOOL	hasRTExt( LPSTR lib );
	//void	setLastTempl( LPSTR lib );  // No longer using Templ Last. 
	int		repRetr( LPCTSTR library );
	void 	postReadRepInitialization(	BOOL templLibRead,BOOL templLibOpen);
//  #if defined (INTERACTIVE)
   #if defined(RSW)
	 BOOL fileNew( LPSTR table, BOOL bAlwaysShowDataSourceDialog, BOOL bStartup, BOOL RWQstart );
	 void rswFileNewCommon(BOOL bFromMenu, BOOL bSelect);
   #endif
//  #endif
	BOOL fileNew( LPSTR table, BOOL bStartup );
	void	setTitleText( BOOL bRepTitled, BOOL bTemplate );
	BOOL	getReportDisplayName( LPSTR namebuf );
	LPSTR	getDisplayName( LPSTR filename );
// static & other private routines from wreport.cpp
private:
	void	change_alias( void );
	BOOL	getClipImageNames( void );
	BOOL	newReport( int reportType );
	void	fileNewFinish( void );
	#if defined RSW
	BOOL	dataBase( LPSTR table, BOOL bAlwaysShowDataSourceDialog, BOOL bCustomDlg, BOOL bTemplate, BOOL RWQstart );
	BOOL	reportTemplate( LPSTR table, BOOL bAlwaysShowDataSourceDialog );
	#else
	BOOL	dataBase( LPSTR table, BOOL bCustomDlg );
	BOOL	reportTemplate( LPSTR table );
	#endif

  // ============================= end WREPORT directory ============		

  // ============================= begin DFILE directory ============
	///// begin DFILE directory

	// public data from dfile.h
public:
	DWORD	paperSizeCount;
	POINT	*pSLenWid;
	WORD	*pSizes;

	///// end DFILE directory

public:
	//// public data
	//		from dfile.h
	long	repno;
	TCHAR 	rname[REPNAMELENGTH];	// temp report name storage
	BOOL	userDefined;
	BOOL	bIgnoreMargins;			// used for text exports 
	BOOL	bSendMAPI;				// defined in dexport.c - means send via MAPI
	BOOL	bMapiBurstReport;		// means burst the report when sending via mapi -- else send as whole report	
	BOOL	bMapiAutoSend;			// don't ask for e-mail addr & message; just send using defaults
	FLDID	MapiSendToFLDID;
	FLDID	MapiBurstFLDID;
	FLDID	MapiSubjectFLDID;
	FLDID	MapiMessageFLDID;
	int		MapiBurstBand;
	CString	MapiSubject;
	CString MapiMessage;
	CStringArray MapiEmailAddrs;
#define SENTTOLEN 512
	CString	MapiSendTo ;

private:
	//// static data
	//		from dfilenew.cpp
	BOOL	bStartupDlg;
	int		buttonChoice;

	//		from dpropt.cpp
	BOOL	zackyet;
	int		insorcms;
	#if !defined RSW
	int		prRec;
	int		svPrRec;
	#endif
	//		from dprset.cpp
	BOOL	bFixFonts;
	//		from dreport.cpp
	int		repcnt;
	LPYZNAME	*yzna;
	LPSTR	*repnames;
	LPYZNAME	yzns;
	LPYZNAME	yznt;
	BOOL	bNotAvailState;	// whether current DS is not available
#if defined INTERACTIVE
	int		repind;
	int		clipImage;
	BOOL	makecurrent;
#endif

public:
	//// dialog box routines
	//		from dfilenew.cpp
	static BOOL CALLBACK fileNewDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
	static LRESULT CALLBACK dlgHook( int nCode, WPARAM wParam, LPMSG msg );
	//		from dpropt.cpp
//	static BOOL CALLBACK prOptDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
	static BOOL CALLBACK recOptDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
	//		from dprset.cpp
	static BOOL CALLBACK prSetDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
	//		from dreport.cpp
	static BOOL CALLBACK reportDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
	#if defined (INTERACTIVE)
	static BOOL CALLBACK copyNameDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
	static BOOL CALLBACK saveRepDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
	static BOOL CALLBACK clipImageDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
	#endif
	BOOL tryDataSource( LPSTR szDataSrc, LPSTR szConnect, LPSTR szDriver );

public:
	//// other public routines
	//		from dpropt.cpp
//	void	recOptions( void );
	//		from dprset.cpp
	#if defined INTERACTIVE
	void	printSettings( void );		
	#else
	int	askPrinter( void );
	#endif

	BOOL commonPrintDialog( void );
public:
	PrintDialog *pPrtDlg;		// need pointer for static hook function

private:
	//// private routines
	//		from dfilenew.cpp
	int	fileNewDlg( BOOL bStartUp );
	//		from propt.cpp
	void	setUserSizes( HWND hDlg, int ind, int id );
	int	paperListIndex( int size );
	void	showPaperSizes( HWND hDlg, int id );
	BOOL	prOptions( void );
	int	set_PageSize( int plen,int pwid );

// private:	// called from static dlgprocs
public:
	//// static rtns
	//		from dfilenew.cpp
	void	drawIconButton( HWND hDlg, int nID, LPDRAWITEMSTRUCT lpdis );

	//// from dprint.cpp (changed to use Win95 common print dialog)
//	static BOOL CALLBACK printDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam );
//	int		binListIndex( WORD bin );
//	void	changeCancelToClose( HWND hDlg );
//	BOOL	spinWrap( HWND hWnd, LPSTR szLow, LPSTR szHigh, BOOL bUpDown );
//	BOOL	checkFile( HWND hDlg );
//	void	showBins( HWND hDlg );
//	BOOL	checkPage( HWND hDlg, BOOL start, DWORD *val, BOOL allPages );
//	BOOL	cancelThisThing( HWND hDlg, WPARAM wParam );
//	WORD 	*pBins;
//	DWORD	prtBinCount;
//	BOOL	bClose;
//	BOOL	bInitDone;

	//		from dpropt.cpp
	void	initLabelList( HWND hDlg );
	//		from dprset.cpp
	BOOL	getListBoxSelection( HWND hDlg, LPSTR pName, LPSTR pDriver, LPSTR pPort );
	void	cleanUpNameStorage( HWND hDlg );
	BOOL	getPrinters( HWND hDlg );
	void	showDefPrinter( HWND hDlg );
	int	printerSetup( HWND hDlg, LPSTR pName, LPSTR pDriver, LPSTR pPort );
	//		from dreport.cpp
	void	freeMemory( void );
	//int	yzncomp( void far * first, void far * second );
	void	showTimeStamp( HWND hDlg, BOOL combo );
	BOOL	listReports( HWND hDlg, LPSTR library, BOOL combo );
	#if defined INTERACTIVE
	void	alertLib( void );
	BOOL	confirmOpen( HWND hDlg );
	void	deleteRep( HWND hDlg );
	BOOL	selLib( HWND hDlg, BOOL combo, BOOL get, BOOL check, WORD help );
	void	repCopy( HWND hDlg );
	void	paintImage( HWND hDlg );
	BOOL	imgPath( LPSTR file );
	#endif


  // ============================= end DFILE directory ============


#if defined(RUNDLL)
public:		// kludgery to allow runtime DLL to create a document object
#else
protected: // create from serialization only
#endif
	CRrDoc();
	DECLARE_DYNCREATE(CRrDoc)

// Operations
public:
// Implementation
public:
	virtual ~CRrDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
#if !defined(RUNDLL)
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);	// dlm 10/26/95
#endif

protected:
#if !defined(RUNDLL)
			void LoadFromStorage(void);					// dlm 10/26/95
#endif
#if defined (INTERACTIVE) && !defined(RUNDLL)
			BOOL m_bNewTemplateLoading ;  // Special variable to prevent delete contents when loading a new template. 
			virtual void DeleteContents(); // delete doc items etc
			virtual BOOL OnNewDocument();
			void SaveToStorage(void);					// dlm 10/25/95
			void OnFileSave(void);						// dlm 11/10/95
			void OnFileSaveAs(void);					// dlm 11/10/95
#endif
public:
#if defined(INTERACTIVE) && !defined(RUNDLL)
			virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);	// dlm 10/25/95
			virtual BOOL OnAutoSaveDocument(LPCTSTR lpszPathName);
			void ReleaseFile(LPCTSTR lpszPathName) ;
#endif 
			BOOL CompoundFileDoc(LPCTSTR lpszPathName);	// dlm 10/26/95
			BOOL IsCompoundFileInUse(LPCTSTR lpszPathName);	// jsf 3/11/97
			BOOL IsCompoundFileInUseEx(LPCSTR lpszPathName); //CAS 03/24/2017
#if defined INTERACTIVE
			BOOL LibraryFileDoc(LPCTSTR lpszPathName);	// sjo 11/16/95
#else
			BOOL LibraryFileDoc(PSTR lpszPathName);	// sjo 12/14/95
#endif	
			BOOL TemplateFileDoc(LPCTSTR lpszPathName);	// sjo 11/16/95	
			BOOL DatabaseFileDoc(LPCTSTR lpszPathName);	// sjo 11/16/95
			BOOL TextFileDoc(LPCTSTR lpszPathName);
			BOOL ShortCutFileDoc(LPCTSTR lpszPathName);
#if defined RSW && defined INTERACTIVE && !defined(RUNDLL)
			CReportWriterFormat ReportWriterQuery;
			BOOL ReportWriterQueryFileDoc( LPCTSTR lpszPathName );
			BOOL readRWQFile(LPSTR filename);
			BOOL processRWQSpecification(void);
#endif

			//winsock initialization
//			WSADATA m_wsaData;
//			int m_wsaErr;


#if defined INTERACTIVE && !defined(RUNDLL)
// Generated message map functions
protected:
	//{{AFX_MSG(CRrDoc)
	afx_msg void OnFileNewReport();
	afx_msg void OnFileNewReportIcon();
	afx_msg void OnFileNewReportSelect();
	afx_msg void OnOpenReport();
	afx_msg void OnDBConnect();
	afx_msg void OnShowSQL();
	afx_msg void OnLimitResult();
	afx_msg void OnLogonPrefs();
//	afx_msg void OnSave();			// removed by dlm 10/25/95
//	afx_msg void OnSaveAs();		// removed by dlm 10/25/95
	afx_msg void OnPageSetup();
	afx_msg void OnExport();
	afx_msg void OnExportChart();
	afx_msg void OnExportPivotTable();

	afx_msg void OnViewResultSet();
	afx_msg void OnFileProperties() ;
	afx_msg void OnFileSendMail();
	afx_msg void OnUpdateExport(CCmdUI* pCmdUI);
	afx_msg void OnUpdateExportOLE(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewResultSet(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTrue(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOpen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGotRep(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileSendMail(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
#endif
};
#endif
