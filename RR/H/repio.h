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
// $Log:   D:/R&R Project/archives/H/REPIO.H_V  $
// 
//    Rev 1.28   25 Aug 2004 07:54:00   Nick
// Version 10.5
// 
//    Rev 1.27   Oct 07 2002 09:26:00   Admin
// Add yxLOFIELD and yxHIFIELD
// 
//    Rev 1.26   Apr 25 2002 10:16:02   Admin
// Add yxIMAGEY
// 
//    Rev 1.25   Nov 29 2001 11:37:12   Administrator
// Add MAPI record type
// 
//    Rev 1.24   Feb 27 2001 15:37:10   nhubacker
// New record type yxPARAMETER
// 
//    Rev 1.23   Dec 05 2000 13:03:50   nhubacker
// Add yxUSERINDEX record type
// 
//    Rev 1.22   Sep 14 2000 10:00:52   nhubacker
// Add yxSERIAL
// 
//    Rev 1.21   Aug 30 1999 15:43:24   BUILD
// ARP20001
// 
//    Rev 1.20   08 May 1997 19:22:46   dlm
// Added record type for charts (yxCHART).
// 
//    Rev 1.19   17 Apr 1997 15:04:36   par
// Needed to increase MAXrecTYPE to account for a new record type.
// 
//    Rev 1.18   10 Apr 1997 15:30:56   par
// Preparing to read and write the HTML_EXPORT structure. 
// 
//    Rev 1.17   06 Apr 1997 13:06:04   pjm
// New record types for DBC-related info.
// 
//    Rev 1.16   24 Mar 1997 10:14:38   smh
// Changed record type for PDI export so can leave old one behind.
// 
//    Rev 1.15   19 Feb 1997 17:10:34   smh
// Last checkin was premature - wait until actually have the repio changes.
// 
//    Rev 1.14   19 Feb 1997 14:57:12   smh
// Added (again) yxEXPORTPDI & yxEXPORTHTML
// 
//    Rev 1.13   10 Feb 1997 10:02:22   sp
// Arp Live merge to trunk
// 
//    Rev 1.8.1.1   24 Oct 1996 09:40:30   smh
// Changed last checkin - someone had already grabbed that id on trunk.
// 
//    Rev 1.8.1.0   24 Oct 1996 09:30:36   smh
//    Rev 1.11   24 Oct 1996 09:36:56   smh
// Added a yxEXPORTPDI record type.
//
//    Rev 1.10   17 Oct 1996 18:24:26   jpb
// fix VarFileInfo charset
// 
//    Rev 1.9   10 Oct 1996 10:16:42   jpb
// for autoDS creation
// 
//    Rev 1.8   08 Oct 1996 16:49:58   amh
// Arp 1.0 U02 merged to trunk
// 
// 
// 
//    Rev 1.7.1.0   01 Aug 1996 19:31:14   sjo
// Second round of HTML export support. Added the ability to save the HTML
// pathname and retrieve it from a file.  Also added runtime support via
// and HTML value in the RI_PRINTER field.
// 
//    Rev 1.7   06 Jun 1996 14:21:58   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.6   09 Jan 1996 19:20:00   dlm
// Added support for new yxQUERYX record, which is identical to yxQUERY record
//  except that it has 4-byte field IDs.
// 
//    Rev 1.5   03 Nov 1995 13:53:20   dlm
// First pass at compound file report storage.
// 
//    Rev 1.4   22 Sep 1995 14:25:36   dlm
// 32-bit-related edits.
// 
//    Rev 1.3   11 Jul 1995 17:13:18   dlm
// Changed functions to CRrDoc member functions and variables to CRrDoc
//  member variables.
// 
//    Rev 1.2   05 Jul 1995 09:50:40   sjo
// Merged in CSV support from 6.5
// 
//    Rev 1.1   26 Apr 1995 11:07:30   pjm
// 6.1.03 -> 7.0 merge.
// 
//    Rev 1.0   16 Mar 1995 16:13:16   sbc
// Initial revision.
// 
//    Rev 1.34   10 Apr 1995 15:43:26   dlm
// Part of datetime support.  Added a couple of globals and a new
//  record type.
// 
//    Rev 1.33   28 Mar 1995 17:26:02   dlm
// Just cleaned up some formatting.  No functional changes.
// 
//    Rev 1.32   13 Feb 1995 16:25:00   sjo
// Fixed a problem with the MAXrecTYPE.
// 
//    Rev 1.31   08 Feb 1995 13:29:38   sjo
// Checking in a bunch of files for the first wave of datetime support. These
// sources have support for a dFlags that is a long (not an unsigned int) and
// it recognizes date, time and datetime fields.  It only supports dates at
// this time, because we need calcs, picture types, etc if we are to do time and
// datetime.
// 
// 
// 
//    Rev 1.30   09 Dec 1994 17:39:28   dlm
// Part of fix to RSW "bug" 1526, which says we need to save the
//  data-source quote character with saved reports.
// 
//    Rev 1.29   17 Nov 1994 10:17:22   dlm
// Changed prototypes of stamps() and db_info() to indicate far pointers
//  to YZNAME structures.
// 
//    Rev 1.28   16 Nov 1994 11:48:38   dlm
// Added tMASTDS2 for improved search rules.  tMASTDS2 means to try master
//  DS directory, followed by tORIG2.  It is used when related file came
//  from master DS, to allow DS override to apply to such related files, too.
// 
//    Rev 1.27   09 Nov 1994 13:35:28   dlm
// Added argument to readRep() prototype.
// 
//    Rev 1.26   08 Nov 1994 16:58:20   dlm
// Has some new stuff relating to ODBC-style search rules and yxDOSID
//  that Phil added for dos->win report conversions.
// 
//    Rev 1.25   28 Oct 1994 17:39:56   dlm
// Added new yxFILEFLAGS record to allow for search rule involving
//  Data-source directory.
// 
//    Rev 1.24   29 Sep 1994 17:46:38   dlm
// Define new yxDATABASE2 record instead of reusing yxDATABASE record.
//  Also, rpwritex.c, grsql.c.
// 
//    Rev 1.23   20 Sep 1994 14:34:06   dlm
// Fixes RRW bug 1741 by redefining yxEXPORTADD as 0x67 instead of 0x5C, which
//  is used in RR6 for yxMEMOTYPE.  Also defined yxMEMOTYPE as 0x5C here.  This
//  invalidates in-house and beta reports containing the old yxEXPORTADD record.
// 
//    Rev 1.22   19 Sep 1994 11:38:24   dlm
// Part of fix in RRW/RSW of RR bug 1968.  The bug was a GPF due to calls
//  to mfeord() and mfflagcalc() in ddsetup() from readRep().  It is unsafe
//  to call those routines in the middle of a report retrieval because of
//  "unfixed" sindex values.  Also modified grmain.c, grmisc.c, datadict.c.
// 
//    Rev 1.21   14 Sep 1994 14:03:32   pjm
// Added new record type (yxRPPAGE1) to identify the yxPAGES1 record
// from converted RP reports.
// 
//    Rev 1.20   31 Aug 1994 15:56:22   mjs
// Added literals needed to handle images in old DOS reports.
// 
//    Rev 1.19   19 Aug 1994 09:19:40   erp
// fixed section for multiple includes
// 
//    Rev 1.18   09 Aug 1994 14:00:38   sbc
// bOldDOSRep moved here from dfile.h
// 
//    Rev 1.17   03 Aug 1994 21:54:54   smh
// Calc/tot comment - added yxCOMMENT.
// 
//    Rev 1.16   02 Aug 1994 17:00:20   smh
// Report Annotate - Added yxREPNOTE for RepNote.
// 
//    Rev 1.15   18 Jul 1994 16:47:48   jpb
// Add record type for total condition
// 
//    Rev 1.14   19 Jun 1994 14:51:34   smh
// Added yxLABELS2, Avery Label name record.
// 
//    Rev 1.13   08 Jun 1994 14:37:28   erp
// changed FAR to far, so it will build for 32-bits
// 
//    Rev 1.12   28 Apr 1994 15:56:58   sbc
// New record types for export dbf & wks
// 
//    Rev 1.11   22 Apr 1994 16:39:16   dlm
// Changed value of yxMISC to 61 from 60 because some other bozo used 60
//  in the RR6 project after I'd already claimed it, but I'm changing mine
//  because I'm a really, really nice guy.
// 
//    Rev 1.10   11 Apr 1994 15:53:14   dlm
// 
// Added yxMISC and related #defines.
// 
//    Rev 1.9   02 Mar 1994 17:11:20   say
// add yxEXPORTADD record
// 
//    Rev 1.8   16 Feb 1994 16:49:12   say
// remove unused LOGONDATA structure
// 
//    Rev 1.7   28 Jan 1994 17:37:12   say
// data source selection
// 
//    Rev 1.6   17 Dec 1993 16:59:40   say
// Bump up major rev to 8, add yxDATASRC record
// 
//    Rev 1.5   07 Dec 1993 16:51:12   say
// Remove obsolete def_logon_data prototype
// 
//    Rev 1.4   22 Nov 1993 13:29:22   say
// Put back LOGONDATA structure so can still read old reports.
// 
//    Rev 1.3   19 Nov 1993 17:38:26   sbc
// Add extern C for C++
// 
//    Rev 1.2   19 Nov 1993 13:17:34   say
// remove LOGONDATA structure definition
// 
//    Rev 1.1   04 Nov 1993 16:37:04   smh
// Removed RPALIAS structure, it's in runtime.h
// 
//    Rev 1.0   14 Oct 1993 10:11:56   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _REPIO_H_
//
// Make a definition for this module.
//
#define _REPIO_H_

//
// Includes needed by this header.
//
	#include "libio.h"

#if defined _GRMAIN_C_
#define GLOBAL 
#else
#define GLOBAL extern
#endif

// ********************************************************************
//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
	// from yx.h
#define REP_MAJ		8	/* major rev */
#define REP_MIN		2	/* minor rev RRW Version 2.0 */
// size buffer required for biggest record
#define TWOBYTE(x) (*(UTWO *)(&(x)))
#define yxfRESET	0x8000	/* flag indicating "reset" evaluate chain record */
					 /* Used to distinguish between CALC, TOTAL, DUPE, LINK
						records from "reset" chains and regular ones.  For
						possible downward compatility */
#define yxMASK		0x7FFF	/* mask for yxget() validity check */

#define yxfNEW_STRING 0x4000	// flag indicating string stored with null terminator

#define yxBOR		0x1
#define yxEOR		0x2
#define yxMINDEX	0x3
#define yxMALIAS	0x4
#define yxDUPE		0x5
#define yxCALC		0x6
#define yxTOTAL		0x7
#define yxLINK		0x8
#define yxFIELD		0x9
#define yxWHEN		0xA
#define yxSORT		0xB
#define yxBREAK		0xC
#define yxPAGES		0xD			/* OLD REPORTS ONLY */
#define yxPSIZE		0xE			/* OLD REPORTS ONLY */
#define yxMARGINS	0xF			/* OLD REPORTS ONLY */
#define yxLABELS	0x10		/* OLD REPORTS ONLY */
#define yxOPTS1		0x11
#define yxQUERY		0x12
#define yxTEXT		0x13		/* OLD REPORTS ONLY */
#define yxFRGN1		0x14
#define yxFRGN2		0x15
#define yxFRGN3		0x16
#define yxFRGN4		0x17
#define yxLOKEY		0x18		/* scope - date & alpha (not SQL) */
#define yxHIKEY		0x19		/* scope - date & alpha (not SQL) */
#define yxLOREC		0x1A		/* scope - record number (not SQL) */
#define yxHIREC		0x1B		/* scope - record number (not SQL) */
#define yxNLOKEY	0x1C		/* scope - numeric (not SQL) */
#define yxNHIKEY	0x1D		/* scope - numeric (not SQL) */
#define yxMASTER	0x1E
#define yxOPTS2		0x1F
#define yxOPTS3		0x20		/* OLD REPORTS ONLY */
#define yxMERGE		0x21
#define yxOPTS4		0x22
#define yxWHENIF	0x23
#define yxGFACT		0x24
#define yxWHENFL	0x25
#define yxRECOPS	0x26		/* OLD REPORTS ONLY */
#define yxOPTUNITS	0x27
#define yxPSIZE1	0x28		/* OLD REPORTS ONLY */
#define yxMARGS1	0x29		/* OLD REPORTS ONLY */
#define yxLOCATE1	0x2A		/* "locate" relations */
#define yxMEMOFILE	0x2B
#define yxAUTOSAVE	0x2C		/* R&R for Worksheets only */
#define yxAUTODEF	0x2D		/* R&R for Worksheets only */
#define yxLINKTAG	0x2E		/* dBASE IV only */
#define yxMNDXTAG	0x2F		/* dBASE IV only */
#define yxRECOP1	0x30		/* OLD REPORTS ONLY */
#define yxNOCOP		0x31
#define yxUDATE		0x32
#define yxWHENSC	0x33
#define yxDIFFDIR	0x34		/* alternate form of yxMASTER */
#define yxRANGE		0x35		/* R&R for Worksheets 1A only */
#define yxLOCATE	0x36		/* obsolete - fatal if encountered */
#define yxSCOPEF	0x37		/* RSW scope field */
#define yxLOSCOPE	0x38		/* RSW lo scope string */
#define yxHISCOPE	0x39		/* RSW high scope string */
#define yxDATABASE	0x3A		/* RSW database  */
#define yxASCII		0x3B		/* RSW,RRDBF ASCII Attach file */
#define yxASCIII	0x3C		/* RSW,RRDBF - finished with memo fields */
#define yxTOTAL2	0x3D		/* frequency-set total */
#define yxHFLAGS	0x3E		/* flags from field specifier header */
#define yxPAGES1	0x3F
#define yxFONTLIB	0x40
#define yxTEXT1		0x41
#define yxWHENSH	0x42
#define yxWHENHT	0x43		/* through 4.0.14 only */
#define yxOPTS31	0x44		/* replacement for yxOPTS3 */
#define yxMARGS2	0x45		/* replacement for yxMARGS1 */
#define yxWHENHT1	0x46		/* replacement for yxWHENHT */
#define yxPARTIAL	0x47		/* partial link compare length */
#define yxPQUEUE	0x48		/* print queue name (XENIX only) */
#define yxMORDER	0x49		/* master table order field (Paradox only) */
#define yxRANGESHT	0x4A		/* Range/Sheet Letter (RW only) */
#define yxPRINTER	0x4B		// printer info (Windows)
#define yxTYPEFACE	0x4C		// current printer font (Windows)
#define yxIMAGE		0x4D		// image info
#define yxLINEBOX	0x4E		// line or box record
#define yxWFRGN		0x4F		// RRW international
#define yxUDFFILE	0x50		/* UDF file */
#define yxCHARSET	0x51		/* ASCII memo charset */
#define yxOLDDBDIRS	0x3F		/* old value of yxDBDIRS - RSW for DOS */
#define yxDBDIRS	0x52		/* RRDBI value of yxDBDIRS */
#define yxPLATFORM	0x53		/* Sql_Platform code for RRDBI */
#define yxSCHEMA	0x54		/* Sql_Schema for RRDBI */
#define yxJOINPAIR	0x55		/* mcj join pair record for RRDBI */
#define yxUSERSEL	0x56		/* user's select statement */
#define yxNEWHEAD	0x57		// new (RRW2) field header info
#define yxGRID		0x58		// display resolution/misc grid info
#define yxEXPORT	0x59		// text export
#define yxWINPGSIZE 0x5A		// Windows page length value
#define yxDATASRC	0x5B		// ODBC Data Source name
#define yxMEMOTYPE	0x5C		// Memo type (for code generator)
#define yxLABELS2	0x5D		// Avery Label name
// gap
#define yxTOTCOND	0x5F		// condition for following total
#define yxDOSIMG	0x60		// DOS style image
#define yxMISC		0x61		// Miscellaneous global report parameters
#define yxREPNOTE	0x62		/* Report Annotation */
#define yxCOMMENT	0x63		// Calc/tot comment
#define yxEXPORTDBF	0x64		// DBF export
#define yxEXPORTWKS	0x65		// WKS export
#define yxRPPAGE1	0x66		// converted RP yxPAGE1
#define yxEXPORTADD	0x67		// Add-on export
#define yxDATABASE2	0x68		// ODBC database name (SQL Server only for now)
#define yxFILEFLAGS	0x69		// info about upcoming yxMASTER/yxDIFFDIR or yxLINK/yxLINKTAG (RSW only right now)
#define yxDOSID		0x6A		// indicates DOS report in Win library (still needs DOS->Win conversions)
#define yxDATASRC1	0x6B		// ODBC data source name & default dir
#define yxQUOTECHR	0x6C		// ODBC data source quote character

#define yxCALC2		0x6D		// New calc record with a long dFlags
#define yxTOTAL3	0x6E        // New tot record with a long dFlags
#define yxLINK2		0x6F		// New link record with a long dFlags 
#define yxLINKTAG2	0x70		// Net tagged link file record with a long dFlags
#define yxFIELD2	0x71        // New field record with a long dFlags 
#define yxLOCATE2	0x72		// New locate rec with long dFlags
#define yxJOINPAIR2 0x73		// New JoinPair rec with long dFlags
#define yxDUPE2		0x74        // New dupe record with a long dFlags
#define yxTOTCOND2	0x75		// New total condition rec with long dFlags
#define yxDTCONVERT	0x76		// Indicates whether DATETIME fields should become DATE fields
#define yxEXPORTRTF	0x77		// RTF export filename 
#define yxEXPORTWORD 0x78		// Word Merge export File record
#define yxEXPORTCSV	0x79		// Csv export file record

// New in version 7 - compound files only
// Include 32-bit values for some items

#define yxFIELDX	0x7A		// combines yxFIELD2, yxHFLAGS, yxNEWHEAD data
#define yxDUPEX		0x7B		// combines yxDUPE2, yxHFLAGS, yxNEWHEAD data
#define yxCALCX		0x7C		// combines yxCALC2, yxHFLAGS, yxNEWHEAD data
#define yxTOTALX	0x7D		// combines yxTOTAL3, yxHFLAGS, yxNEWHEAD data
#define yxTEXTX		0x7E		// combines yxTEXT1, yxHFLAGS, yxNEWHEAD data
#define yxLINEBOXX	0x7F		// replaces yxLINEBOX
#define yxIMAGEX	0x80		// replaces yxIMAGE
#define yxWFRGNX	0x81		// replaces yxWFRGN
#define yxWHENIFX	0x82		// replaces yxWHENIF
#define yxWHENHTX	0x83		// replaces yxWHENHT
#define yxBREAKX	0x84		// replaces yxBREAK
#define yxSORTX		0x85		// replaces yxSORT
#define yxOPTS4X	0x86		// replaces yxOPTS4
#define yxWINPGSIZEX 0x87		// replaces yxWINPGSIZE
#define yxQUERYX	0x88		// replaces yxQUERY
#define yxEXPHTMLOLD 0x89		// Export to HTML - replaced by yxEXPORTHTML below
#define yxCONNECT	0x8A		// ARPEGGIO Connect String (auto DS creation)
#define yxDRIVER	0x8B		// ARPEGGIO Driver DLL name (auto DS creation)
#define yxEXPPDIOLD	0x8C		// export to PDI - replaced by yxEXPORTPDI below
#define yxEXPORTHTML 0x8D		// export to HTML
#define yxEXPORTPDI	0x8E		// export to PDI
#define yxDBCNAME	0x8F		// DBC file name (and DBC report indicator)
#define yxDBCTABLE	0x90		// long/short DBC table name
#define yxEXPORTHTML3 0x91		// export to HTML
#define yxCHART		0x92		// chart info

// new record types added after Liveware Publishing began maintenance of the product
#define yxSERIAL	0x93		// serial number
#define yxUSERINDEX	0x94		// related file has a "user index"
#define yxPARAMETER 0x95		// parameter field extras
#define yxMAPI		0x96		// mapi stuff
#define yxIMAGEY	0x97		// Image from field
#define yxLOFIELD	0x98		// low scope field id
#define yxHIFIELD	0x99		// high scope field id
#define yxPASSWORD  0x9a		// passwords (shhhhh...)
#define yxPARAMLIST 0x9b		// parameter list element

#define yxACTIVEDS	0x9c		// RSW ActiveDS stuff for offline mode

#define yxDDBF		0x9D		// dynamic DBF

// If you add a new one, update MAXrecTYPE below

	/* keep in synch with last record type */
#define MAXrecTYPE	(yxPARAMLIST)

// FLAVORs specified in bytes 0/1 of yxMISC
#define FLAVOR_GENERIC	0x0		// generic; anybody can read this report
#define FLAVOR_SOLOMON	0x1		// SOLOMON flavor; only SOLOMON RSW can read this report
#define JIMMY_PASSWORD  0x10	// add to flavor to say "password protected"

// PRODUCTs specified in bytes 2/3 of yxMISC
#define PRODUCT_RRW		0		// good old RRW
#define PRODUCT_RSW		1		// good old RSW/ARPEGGIO


// FILEFLAGS specified in bytes 0-1 of yxFILEFLAGS
#if defined(RSW)
#define FILEFLAGS_DSDIR	0x0001	// file is in data-source directory
#define FILEFLAGS_CFDLG	0x0002	// uses common file dialog for table selection
#define FILEFLAGS_JADIR	0x0004	// allows joins across directories
#define FILEFLAGS_MASDS	0x0008	// related file is from master data source
#endif

	// from sql.h
// IDs for getting default logon data via sql_def_logon()
#define DEF_DATABASE 0x03 // Database also gets datadir for Novell
#define DEF_DATADIR	 0x02
#define DEF_SCHEMA	 0x04
#define DEF_LOGID	 0x08
#define DEF_PASSWD	 0x10
#define DEF_ALL		 0x1F

/* DOS image field flags */
#define imgINCH	0x01				/* width/height is inches */
#define imgCM		0x02				/* width/height is centimeters */
#define imgPRINT	0x04				/* "print me" flag */
#define imgROT		0x08				/* image has been rotated */
#define imgDIFF	0x10				/* image and lib dirs are different */

// ********************************************************************
//
// Structure Section:
// Place in this section any structure definitions.
//
typedef struct yxbuf
{	unsigned short yxType;
	unsigned short yxCount;
	char yxRec[YXBUFMAX];
} YXBUF;

// must match RECT definition for downward compatibility with 16-bit libraries
typedef struct tagRECT16
{
    WORD left;
    WORD top;
    WORD right;
    WORD bottom;
} RECT16;
//
// Global Data Section:
// Place in this section any global data.
//


#if 0
GLOBAL BOOL bOldDOSRep; 
GLOBAL int InReadRep
 #if defined(_GRMAIN_C_)
	 = FALSE;
 #else
	 ;
 #endif
GLOBAL int BadRep;
GLOBAL int intDate;			// this is for converting picD4/picD5
 #if defined(RSW)
GLOBAL LPSTR lpszSQLstmt;
GLOBAL int DTCAnswer;
GLOBAL int DTCRev;
 #endif
GLOBAL int near RpMajVer;
GLOBAL int near RpMinVer;
 #if defined (RSW)
GLOBAL char szDataSource[SQL_MAX_DSN_LENGTH]; 	// shared among grsql.c, grfile.c and dreport.c
GLOBAL char szDSDir[WINPATHLEN];
 #endif
#endif


// New HTML Export uses dynamic memory allocation 
// to generate its record data. 
class CRrMemFile : public CMemFile
	{
	public:
		BYTE FAR* GetBuffer() { return m_lpBuffer ; }
	} ;

//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#if 0
 #if defined(RSW)
extern int readRep(BOOL bUseszDataSource);
 #else
extern int readRep(void);
 #endif
extern	int writeRep(long recno);
extern	int saveRep(int (*routine)(long ),char near *rname);
extern  BOOL stamps(YYFILETAB *ftab,LPYZNAME yzn);
extern	unsigned int yxfarget(struct yxbuf *buf,int *ct);
 #ifdef RSW
extern	int db_info(struct YYFiletab *ftab, LPYZNAME yzn); // dbinfo.c
 #else
	extern int scopeCases(int *status,int type,YXBUF *buf,int count,
		 int setscope,int clip);
 #endif
extern	char far *fnshrink2(char far *ptr,char far *mname);
extern	char far *fnshrink(char far *ptr);
 #if !defined(INTERACTIVE)
extern chkscope(int lo);
 #endif
#endif



#undef GLOBAL
#endif // end _REPIO_H_

// *************************** End of File ************************************
