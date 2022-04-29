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
// This is a header for the public DBF and WKS export #defines, data, and 
// prototypes.  It should only be included in pd.h.  I created a separate 
// header on the off chance that some program besides R&R will want to use
// the database export DLL.
//
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/DBEXPORT.H_V  $
// 
//    Rev 1.22   02 Jul 2004 12:14:52   Nick
// Add Quote delimiter, prettify
// 
//    Rev 1.21   Mar 30 2000 11:55:12   ksinkel
// More result set changes
// 
//    Rev 1.20   05 May 1997 15:13:10   par
// Removed A L I V E (spacing prevents search hits) and PDI _ EXPORT conditionals.
// From this point forward, this code will always be included in build.
// 
// 
//    Rev 1.19   28 Apr 1997 17:43:30   par
// Added comment about use of szImagePathname.
// 
//    Rev 1.18   25 Apr 1997 18:24:14   par
// New HTML options to specify file format and to copy all images.
// 
//    Rev 1.17   23 Apr 1997 15:04:04   par
// Functions to generate an image from an object.  Mostly directory parsing.
// 
//    Rev 1.16   17 Apr 1997 11:31:48   par
// Try and achive U01 backward compatibility
// by keeping the html export structure in tact.
// 
//    Rev 1.15   11 Apr 1997 17:07:38   par
// New HTML structure replaces old HTML references.
// 
//    Rev 1.14   08 Apr 1997 12:34:22   par
// New HTML export parameters.
// 
//    Rev 1.13   24 Mar 1997 09:52:18   smh
// Export OLE objects to PDI.
// 
//    Rev 1.12   10 Feb 1997 10:02:18   sp
// Arp Live merge to trunk
// 
//    Rev 1.10.1.1   29 Oct 1996 14:24:06   smh
// PDI _ EXPORT changes
// 
//    Rev 1.9.1.1   26 Sep 1996 12:06:38   sjo
// Added html export structure (scott for shawn)
// 
//    Rev 1.9.1.0   30 Jul 1996 16:48:14   sjo
// This is the first round of HTML export checkins.
// 
//    Rev 1.9   27 Nov 1995 12:04:46   smh
// C -> C++ & Win32 file i/o.
// 
//    Rev 1.8   21 Sep 1995 11:22:34   smh
// 32-bit export DLLs
// 
//    Rev 1.7   19 Jul 1995 11:15:52   smh
// Moved extern protos to rrview.h.
// 
//    Rev 1.6   18 Jul 1995 09:44:12   smh
// #undef GLOBAL
// 
//    Rev 1.5   11 Jul 1995 13:30:38   sbc
// Changing typedef from BOOL to int fixes weird compile errors.
// 
//    Rev 1.4   06 Jul 1995 15:04:10   mjs
// Added definition of GLOBAL, so I could compile rrview.cpp.
// 
//    Rev 1.3   29 Jun 1995 10:17:18   smh
// Merged R?W 6.5.03 sources w/ R?W7 sources.
// 
//    Rev 1.2   29 Jun 1995 08:25:44   mjs
// Removed MQAXLABSZ, so it would compile.
// 
//    Rev 1.1   25 Apr 1995 15:10:30   smh
// Merged 6.1.03 and 7.0 headers.
// 
//    Rev 1.0   16 Mar 1995 16:12:20   sbc
// Initial revision.
// 
//    Rev 1.9   22 Jun 1995 11:32:06   smh
// Code for ExportType improvements.
// 
//    Rev 1.8   14 Jun 1995 11:10:34   smh
// Fixed size of field name buffer, and added recswrote to CSV struct.
// 
//    Rev 1.7   12 Jun 1995 13:53:00   smh
// CSV Export.
// 
//    Rev 1.6   08 Jun 1995 11:42:34   sjo
// Checking in changes for CSV (both Word Merge and Text Data) export 
// support. Changed dfile\dexport.c, dtxtopt.c, repio\grmisc.c, rpwritex.c,
// spec\specopt.c, h\dfile.h, dbexport.h, repio.h, resource.h, wmain.h,
// _dfile.h and wdialog.h.  Also resource\rrw.str,export.dlg.
// 
//    Rev 1.5   07 Jun 1995 14:31:06   smh
// Moved MAXLABSZ to product.h
// 
//    Rev 1.4   26 May 1995 16:36:12   pjm
// Add new export type for RTF export.
// 
//    Rev 1.3   24 Mar 1995 14:12:28   smh
// Added constants for date/time support.
// 
//    Rev 1.2   25 Feb 1994 09:42:58   erp
// removed Excel from Export list to move to dynamic export list from .INI file
// 
//    Rev 1.1   22 Feb 1994 11:07:50   erp
// 
//    Rev 1.0   29 Dec 1993 13:32:32   smh
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _DBEXPORT_H_

//
// Make a definition for this module.
//
#define _DBEXPORT_H_

#if defined(_DEXPORT_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif


///////////////////////////////////////////////////////////////////////////////
// Remember when you create constants in here that these exports are not built
// differently between products.  Therefore be wary of any constants that
// differ between the products.  For example, you'll see MAXLABSZ below which
// is defined in product.h as the maximum of the RRW and RSW MFFIELDNAMESIZE.


//
// Defines Section:
//

	// export types
#define TXTEXP 0			// text
#define DBFEXP 1			// dbf
#define WKSEXP 2			// wks
#define XLPEXP 3			// excel pivot table
#define XLCEXP 4			// excel chart
#define RTFEXP 5			// rtf
#define CSVEXP 6			// Text data file
#define WRDEXP 7  			// Word merge file
#define HTML2EXP    8
#define PDIEXP      9       // Report Viewer Export
#define DBFRESULTSET	10	// exports all fields used in report, including for sorting, and query
#define EXPTYPEMAX  10

#define INIEXPPOS 100	// offset for export add-ons like excel exports

	// Status from CreateFile
#define NOFIELDS 1		// No valid fields in the list (no file or memory)
#define OPENERR 2			// Error opening file (no memory alloced)
#define ALLOCERR 3		// Memory allocation error
#define WRITEERR 4		// Error writing the header
#define WROTEHEAD 5		// Good return, file created, header written
	// status from StoreField
#define BADSTATUS 6		// Shouldn't be in this routine w/ current status
#define STORING 7			// Good return - stored field data in record buffer
#define BADTYPE 8			// Invalid type set in passed field info routine
#define RECFULL 9			// Set when call write_record
#define WROTEREC 10		// Wrote a record to the file (set in write_record)
#define FILECLOSED 11	// Closed file (and freed memory)

	// export field types
#define dbxNUM 'N'
#define dbxDATE 'D'
#define dbxLOGIC 'L'
#define dbxCHAR 'C'
#define dbxMEMO 'M'
#define dbxTIME 'T'			// according to MS the field type of 'T' in byte 11 is DATETIME
#define dbxDATETIME 1			// flag for WKS only, not written to DBFs which share dbxDATE
#define dbxUNKNOWN '?'

	// export format types
#define dbxNOFORMAT		0		// none
#define dbxN_EXP			1		// numeric formats
#define dbxN_GENERAL		2
#define dbxN_PERCENT		3
#define dbxN_FIXED		4
#define dbxN_CURRENCY	5
#define dbxN_COMMA		6
#define dbxD_DM			7		// date formats (dd-mmm, mmm-yy, dd-mmm-yy)
#define dbxD_MY			8
#define dbxD_DMY			9
#define dbxD_LINTL		10		// long & short international
#define dbxD_SINTL		11
#define dbxT_HMS			12		// time - hh:mm:ss
#define dbxT_HM			13		// time - hh:mm
#define dbxT_INT1			14
#define dbxT_INT2			15


// WKS export error types
#define ERR		1			// regular error
#define NAERR	2			// NA error

// constants needed for the structures below
#define NAMESIZE 10		// Doesn't include NULL
#define UNUSESZ 4			// unused bytes in header
#define ZEROSZ 14			// fourteen bytes of zero
#define HEADZERO 20		// and twenty "zero" bytes in the header's header

/* This is a cheat.
		This value is MAXDNAME (in product.h) for RSW + 1.
		If MAXDNAME changes, so should this.
		I didn't want to use MAXDNAME because this DLL isn't product specific
		
		UPDATE: MAXLABSZ IS NOW DEFINED IN PRODUCT.H TO PUT IT NEAR MAXDNAME
					FOR EASY UPDATING

#define MAXLABSZ 43		// max label size
*/

// export ordinals (keep in synch with RRDBFX.DEF & RRWKSX.DEF)
#define DBXCREATE	1
#define DBXSTORE	2
#define DBXCLOSE	3

// for easy access to export type specific members of export structure
#define DBFXSP xs->type.dbfx
#define WKSXSP xs->type.wksx
#define CSVXSP xs->type.csvx

// Defines needed for CSV Export.
// Valid FileTypes
#define EXPCSVCOMMA	0x01
#define EXPCSVTAB	0x02
#define EXPCSVFIXED	0x03
#define EXPCSVUSER	0x04

// Optional flag settings
#define EXPCSVFIELDNAMES	0x001
#define EXPCSVQUOTE			0x002
#define EXPCSVDOSCHARS		0x010 

#define MAX_CSV_SEP_LEN		10
#define CSVNAMEMAX			MAXLABSZ + MAXLABSZ + 2
							
// MFFIELDNAMESIZE * 2 b/c have to double quote all quotes, and could be
//		all quotes, also add two for delimiting quotes

// PDI export flags
#define	PDI_EXP_OLE		0x1		// Export OLE objects

//
// Structure Section:
//

	/* This is the only structure the user has to do anything with.  
		You fill it in with information that the export DLLs understand
		based on information you understand.
		Use the dbxXXX values above for type, and format
	*/
typedef struct DBXField
{
	LPSTR	name;			// give me a pointer to the field name
	UINT	width;			// Size in the destinaton file. Don't include dec. pt. (R&R doesn't)
	UINT	dp;				// decimal places
	UINT	format;			// field's format (for date & numeric fields)
	char	type;			// The field's type.  Use a dbxXXX type from above
} DBXFLD;
typedef DBXFLD far * LPDBXFLD;

// All user needs to do (w/ rest of these) is pass a DBExportStruct to DLL

// THESE DBF STRUCTURES CANNOT BE REORDERED BECAUSE IT IS WRITTEN DIRECTLY TO A DBF FILE
// THEREFORE THE DBF EXPORT DLL MUST HAVE STRUCTURES ALIGNED ON ONE BYTE BOUNDRIES
// first_rec and reclen changed to unsigned shorts from UINTs to keep them two bytes

	// structure of header of DBF file header
typedef struct HeaderHeader
{
	char	filetype;
	char	year;
	char	month;
	char	day;
	unsigned long numrecs;
	unsigned short first_rec;
	unsigned short reclen;
	char	zerobyte[HEADZERO];
}	HEADHEAD;

// structure of field descriptors in DBF headers
typedef struct DBFFieldDescriptor
{	char	name[NAMESIZE+1];			// ten chars plus a NULL
	char	type;
	char	unused[UNUSESZ];
	char	width;
	char	dp;
	char	zero[ZEROSZ];
} FLDDES;
typedef FLDDES far * LPFLDDES;

// DBF file header-> a header, array of field descriptors, and a footer
typedef struct DBFHeader
{
	HEADHEAD	header;
	FLDDES		* descript;
	char		footer;					// end of header word
}	DBFHEAD;

	// the DBF-specific export structure items (just the file header)
typedef struct DBFXStruct
{
	DBFHEAD header;			// file header
} DBFX_STRUCT;

typedef struct WKSFieldDescriptor
{	
/* I'm cheating.  Since MAX_LAB_LEN is so big, I'm using 
	the R&R max, MFFIELDNAMESIZE, instead
*/
	char	name[MAXLABSZ+1];		// need field descriptor info (in header in DBFs)
	char	type;
	char	width;
	char	dp;
	char	colwidth;
	char	format;
	void	*xformat ;

} WKSFLDDES;
typedef WKSFLDDES far * LPWKSFLDDES;


// the WKS-specific export structure items
typedef struct WKSXStruct
{
	unsigned long	bufsize;
	unsigned long	chars_stored;
	short			column;
	short			maxcol;
	unsigned long	recswrote;
	unsigned long	row;
	LPWKSFLDDES descript;
} WKSX_STRUCT;


// CSV field descriptor
// so can save small list of MFFIELD info in DLL
// just need name, type, and field width for CSV
typedef struct CSVFieldDescriptor
{	
	UINT	width;
	char	name[CSVNAMEMAX];
	char	type;
} CSVFLDDES;
typedef CSVFLDDES far * LPCSVFLDDES;


// the CSV-specific export structure items
typedef struct CSVXStruct
{
	UINT	chars_stored;						// number of chars in output buffer
	UINT	recswrote;							// records exported thus far
	LPCSVFLDDES descript;						// CSV field descriptor array
	BOOL	namerow;							// exporting name row?
	BOOL	doschars;							// converting to DOS chars?
	BOOL	quote;								// quoting fields?
	char	type;								// CSV file type (comma,tab,fixed...)
	char	separator[MAX_CSV_SEP_LEN+1];		// separator ("," "\t", user defined...)
} CSVX_STRUCT;


// The database export structure. Pass one (same) of these to all DLL rtns
// It's used to pass info between DLL routines.
typedef struct DBExportStruct
{	
	UINT	flds_stored;			// The number of fields stored in the record buffer
	UINT	flds_blank;				// number of blank fields stored in record
	CFile	file;
	UINT	numflds;				// number of fields in a record
	LPSTR	record_buf;				// Buffer for a record of data
	UINT	status;					// Keeps status of export
	char	filename[WINPATHLEN+1];
	union
	{	DBFX_STRUCT dbfx;			// export type specific stuff
		WKSX_STRUCT wksx;
		CSVX_STRUCT csvx;
	} type;	
} DBEXP;
typedef DBEXP far * LPDBEXP;

// CSVExport, this defines the info necessary for CSV style
//  exports. This includes the Word Merge File format.
// This is for EXE-side repio & UI info, not just used during export
typedef struct CSV_Export
{
	char	band;							// band exporting
	char	FileType;						// CSV file type
	char	Separator[MAX_CSV_SEP_LEN+1];	// separator character(s) (if user-defined)
	char	Flags;							// flags: name row, convert to DOS chars
} CSV_EXPORT;

// HTMLExport, this defines the info necessary for HTML
//  exports. 
// This is for EXE-side repio & UI info, not just used during export
struct HTML_EXPORT
{
	// ARPEGGIO 1.0 Data structure.  It must be maintained so that 
	// Old EXEs can use the new export DLL. 
	// This information is generally treated as read-only.  The only time 
	// it is written to is when the new structure changes and the synchronize function is called. 
	BOOL	bUseColor;						// NEW - indicates whether color or image is active
	int		iTableBorder;					// table border width
	char	szImagePathname[WINPATHLEN+1];  // Temporary variable used to pass relative image location to RRHTML.DLL. 
	int		iRed;							// Backround Color
	int		iGreen;
	int		iBlue;
	
	// This is the new ARPEGGIO 2.0 Data structure. 
	int		 nTableBorderType          ;
	int      nTableBorderWidth         ;  // table border width
	CString  csBackgroundImagePathname ;  // Backround image file
	COLORREF rgbBackgroundColor        ;  // Backround Color
	CString  csExportPathname          ;
	CString  csExportDirectory         ;
	BOOL     bSameDirectoryAsOutput    ;
	CString  csImageDirectory          ;
	BOOL     bOpenInBrowser            ;
	BOOL     bCopyAllImagesToDirectory ;
	CString  csHtmlImageFileFormat     ;  // Three letter file extension (GIF, JPG, or BMP).

	HTML_EXPORT() ;
	HTML_EXPORT& operator=(const HTML_EXPORT& src) ;
	void SynchronizeU01Data() ;
	BOOL ConvertFilename(const CString& csExistingFilename, CString& csConvertedPathname) ;
	BOOL ConvertPathname(const CString& csExistingPathname, CString& csConvertedPathname) ;
	void CreateImageDirectory() ;

	static int DirectoryDifference(CString csOutputDirectory, CString csImageDirectory, CString& csRelativeDirectory) ;
	static int PathnameDifference (CString csOutputPathname , CString csImagePathname , CString& csRelativePathname ) ;
} ;
BOOL AFXAPI operator==(const HTML_EXPORT& h1, const HTML_EXPORT& h2) ;
BOOL AFXAPI operator!=(const HTML_EXPORT& h1, const HTML_EXPORT& h2) ;

// Routine typedefs - to call DLL routines

typedef int (WINAPI* LPFNDBXCREATE)(LPDBEXP,LPSTR far *,FARPROC,FARPROC);
typedef void (WINAPI* LPFNDBXCLOSE)(LPDBEXP);
typedef int (WINAPI* LPFNDBXSTORE)(LPDBEXP,LPSTR,LPSTR,LPSTR,int,FARPROC,FARPROC);


//
// Function Prototypes Section:
//

#undef GLOBAL
#endif
