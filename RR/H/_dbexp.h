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
// Private header for DBF and WKS export
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/H/_DBEXP.H_V  $
// 
//    Rev 1.11   02 Jul 2004 12:13:42   Nick
// Change for Quote delimiter
// 
//    Rev 1.10   10 Feb 1997 10:02:16   sp
// Arp Live merge to trunk
// 
//    Rev 1.8.1.0   31 Dec 1996 12:21:46   SRM
// undef GLOBAL at end of file
// 
//    Rev 1.8   08 Oct 1996 16:49:34   amh
// Arp 1.0 U02 merged to trunk
// 
// 
// 
//    Rev 1.6.1.0   28 Jun 1996 11:20:38   smh
// Define wks export formatting constants in hex so can't be
// misinterpreted as binary (as was happening to my dec 10).
// 
//    Rev 1.7   28 Jun 1996 11:23:36   smh
// Make wks export constants hex so won't be interpereted as binary.
// 
//    Rev 1.6.1.0   28 Jun 1996 11:20:38   smh
// Define wks export formatting constants in hex so can't be
// misinterpreted as binary (as was happening to my dec 10).
// 
//    Rev 1.6   27 Nov 1995 12:02:42   smh
// Win32 file i/o & C->C++.
// 
//    Rev 1.5   21 Sep 1995 11:22:20   smh
// 32-bit export DLLs
// 
//    Rev 1.4   29 Aug 1995 13:25:40   mjs
// win32
// 
//    Rev 1.3   03 Aug 1995 18:40:14   smh
// made columnlen() take a pointer rather than a giant structure.
// 
//    Rev 1.2   28 Jun 1995 15:18:56   smh
// Merged CSV/RTF changes from 6.5.
// 
//    Rev 1.1   25 Apr 1995 15:11:44   smh
// Merged 6.1.03 and 7.0 headers.
// 
//    Rev 1.0   16 Mar 1995 16:14:16   sbc
// Initial revision.
// 
//    Rev 1.7   13 Jun 1995 16:56:56   smh
// Proto to strip line feed chars from data in csv export.
// 
//    Rev 1.6   12 Jun 1995 13:47:56   smh
// CSV export.
// 
//    Rev 1.5   05 Apr 1995 16:23:40   smh
// Support blank 1-2-3 data.
// 
//    Rev 1.4   24 Mar 1995 14:14:12   smh
// Added time info for date/time support.
// 
//    Rev 1.3   16 Feb 1995 14:57:18   smh
// Updated the LICS char table to translate ANSI chars to LICS 
// chars rather than OEM to LICS.  (extension of RRW bug 2249)
// 
//    Rev 1.2   15 Feb 1995 17:03:28   smh
// proto for licschar()
// 
//    Rev 1.1   26 Oct 1994 11:17:50   smh
// Proto for make_goodname - rtn to make valid DBF field names.  RSW 1020.
// 
//    Rev 1.0   29 Dec 1993 13:32:36   smh
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _DBEXP_H_

//
// Make a definition for this module.
//
#define _DBEXP_H_
#include "dbexport.h"		// the public header

// defines section *****************************************************


#define BASEYEAR 1900
#define DBF1 0x03			// location of file type byte in .DBF header
#define DBFDATESZ 8		// size of a date
#define dbxTRUE 'T'			
#define dbxFALSE 'F'
#define DESCRIPTSZ NXTFIELD	// I like that name better
#define EOFIELD  0x0d	// end of field marker in dbf
#define FOOTSZ 1			// size of the DBF header footer
#define HEADHEADSZ NXTFIELD
#define LOGICSZ 1			// size of a logic field
#define MAXDP 15			// max # of decimal places in a dbf
#define MAXNUMWID 19		// max field width in a dbf
#define NXTFIELD 0x20	// size of a dbf field descriptor (in header)
#define RNUM0 4			// pos in header of # of records dbf word
#define WKSDATESZ 11		// size of a date in wks files


// CSV export constants
#define CSVBUFSZ		1000			// size of data buffer

// worksheet export constants
#define rtBOF			0		// beginning of file
#define rtCOLW1		8		// column-width record (required after WINDOW1)
#define rtEOF			1		// end of file
#define rtDIMEN		6		// dimensions
#define rtHIDCOL1		100	// hidden columns record (required after WINDOW1)
#define rtLABEL		15		// label cell
#define rtNUMBER		14		// floating point number cell
#define rtWINDOW1		7		// window one record
#define rtBLANK		12		// blank value

#define BLANKSIZE		5
#define fREVISION		1028	// 1-2-3 Version 1, 1A
#define COLSZINFO		7		// size of bytes indicating column size
#define DIMENLOC		6		/* file offset for dimension record */
#define DIMENSIZE		8		// dimensions record body size
#define HIDBYTES 		32		// number of bytes in hidden column record
#define LABBYTES		10		// number of bytes that preface a label
#define MAX_LAB_LEN	240	// maximum label length
#define WIND1SIZE		32		// number of bytes in record body
#define WKSHEADSZ		90		// bytes of (constant) header info in WKS file
#define DAILYuSECS	86400000000.0		// number of microseconds in one day

/* display format: bits 6,5,4:  -XXX ---- */
#define	fGENERAL		1
#define	fFIXED		0
#define	fSCIENTIFIC	1
#define	fCURRENCY	2
#define	fPERCENT		3
#define	fCOMMA		4
/* 5,6 unused */
#define	fSPECIAL		7
#define	fBLANK		0xff

/* dealing with format inside a cell type */
#define	FORMAT1(f)	(((f) & 7) << 4) | 0x80
#define	FORMAT2(d)	((d) & 0xF)

/* decimal field is bits 3,2,1,0: ---- XXXX */
/* interpretations when format is fSPECIAL */
//	SMH 6/28/96 -	made these hex so compiler can't interperet the radix incorrectly,
//						saw bug where fD5 = 10 was treated as binary 10
#define fDAYMONYEAR	0x02
#define fDM			0x03
#define fMY			0x04
#define fTHMS		0x07				// time - hh:mm:ss
#define fTHM		0x08				// time - hh:mm
#define fD4			0x09
#define fD5			0x0a
//#define fTINT1		11			// there's just one Windows international time format, so go with long Lotus international format
#define fTINT2		0x0c				// time - international
#define fDEFAULT	0x0f

/* label leading characters */
#define	LJUST	'\''
#define	RJUST	'"'
#define	CENTER	'^'

#define CHARRECSZ 10		// space needed (besides data) when write char data
#define RECSZ 17			// space needed (w/ data) when write non-char data

// moved this below
//#define WIN1INIT { 0,0,0x8F,0,9,8,20,0,0,0,0,0,0,4,4,256,0 }

// from wks.h
#define	LOTUS_BIAS	109512
#define	LOTUS_ERR	60L
#define	DATE_123(x)	((x)-((x)>LOTUS_ERR+LOTUS_BIAS ? LOTUS_BIAS-1 : LOTUS_BIAS))
#define LICS_CBEG	0			/* first LICS control character to convert */
#define LICS_CEND	31			/* last    "     "     "     "  "    "  */
#define LICS_BEG	128			/* first LICS character to convert */
#define LICS_END	254			/* last    "      "     "     "    */
#define LICS_CTRL(c) (((c) >= LICS_CBEG) && ((c) <= LICS_CEND))
#define TIME_123(x)	(x / DAILYuSECS)


// from util.h
//typedef struct ZDate
//{	int zYear;
//	char zMonth;
//	char zDay;
//	char zDayOfWeek;
//} ZDATE;


// __stdcall necessary to indicate callee will clean up the stack
typedef BOOL (__stdcall *GOODFLD)(LPSTR);
typedef BOOL (__stdcall *FLDINFO)(LPSTR, LPDBXFLD);
typedef BOOL (__stdcall *NOVALUE)(LPSTR, LPSTR);


// wks export typedefs

/* 1-2-3 Version 2 WINDOW1 record format */
typedef struct window1
{
	short cur_col;		/* cursor column */
	short cur_row;		/* cursor row */
	BYTE	format;		/* format */
	BYTE	unused1;		/* unused */
	short def_col_wid;	/* default column width */
	short cols_on_scr;	/* number of columns on screen */
	short rows_on_scr;	/* number of rows on screen */
	short left_col;		/* left column */
	short top_row;		/* top row */
	short title_cols;		/* number of title columns */
	short title_rows;		/* number of title rows */
	short left_tit_col;	/* left title column */
	short top_tit_row;	/* top title row */
	short top_left_col;	/* top-left column */
	short top_left_row;	/* top-left row */
	short wind_cols;		/* number of columns in window */
	short unused2;		/* unused */
} WIND1;

typedef struct wkshead
{
	short bof;
	short boflen;
	short rev;
	short dimen;
	short dimensz;
	short dimenval1;
	short dimenval2;
	short dimenval3;
	short dimenval4;
	short win1;
	short win1sz;
	WIND1 win1val;
} WKSHD;


// Data section

// worksheet export data

#if defined(_WKSEXP_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif

GLOBAL WIND1 win1					// 1-2-3 default window record
#if defined(_WKSEXP_C_)
 = {	0,		/* cursor column */
		0,		/* cursor row */
		143,	/* format  (0x8F)*/
		0,		/* unused */
		9,		/* default column width */
		8,		/* number of columns on screen */
		20,		/* number of rows on screen */
		0,		/* left column */
		0,		/* top row */
		0,		/* number of title columns */
		0,		/* number of title rows */
		0,		/* left title column */
		0,		/* top title row */
		4,		/* top-left column */
		4,		/* top-left row */
		256,	/* number of columns in window */
		0		/* unused */
	}
#endif
;

// forget it, just  initialize in wks_header
//GLOBAL WIND1 WIN1INIT
//#if defined (_WKSEXP_C_)
//	= { 0,0,0x8F,0,9,8,20,0,0,0,0,0,0,4,4,256,0 }
//#endif
//;

GLOBAL WKSHD wks_header					// 1-2-3 default window record
#if defined(_WKSEXP_C_)
 = {	rtBOF,
		2,
		fREVISION,
		rtDIMEN,
		DIMENSIZE,
		0,
		0,
		0,
		0,
		rtWINDOW1,
		WIND1SIZE,
//		WIN1INIT
		{ 0,0,0x8F,0,9,8,20,0,0,0,0,0,0,4,4,256,0 }
	}
#endif
;

// from txlics.asm
GLOBAL BYTE LICSctrl[32]
#if defined(_WKSEXP_C_)
 = {	' ',		//      0
		' ',		// Ú    1 Top, left corner (single)
		' ',		// Ä    2 Single middle line
		' ',		// ¿    3 Top, right corner (single)
		' ',		// ³    4 Single vertical
		' ',		// Ù    5 Bottom right corner (single)
		' ',		// Ä    6 Single middle line (same as 2!)
		' ',		// À    7 Bottom left corner (single)
		' ',		// ³    8 Single vertical (save as 4!)
		' ',		// É    9 Top left corner (double)
		' ',		// Í   10 Double middle
		' ',		// »   11 Top, right corner (double)
		' ',		// º   12 Double vertical
		' ',		// ¼   13 Bottom right corner (double)
		' ',		// Í   14 Double middle (same as 10!)
		' ',		// È   15 Bottom left corner (double)
		' ',		// º   16 Double verical (same as 12!)
		' ',		//    17 Right-pointing solid triangle
		171,		// ®   18 Angle quotation mark left
		187,		// ¯   19 Angle quotation mark right
		' ',		//    20 Left-pointing solid triangle
		183,		// ú   21 Single-pixel middle dot
		' ',		//    22 Left pointing arrow
		' ',		// Ô   23 Bottom right corner (single/double)
		' ',		// ¾   24 Bottom left corner (single/double)
		' ',		//     25 Right-pointing arrow
		' ',		//    26 Up-pointing arrow
		' ',		//    27 Down-pointing arrow
		' ',		//     28 Right-pointing arrow
		' ',		//    29 Left-pointing arrow
		' ',		// ´   30 -|
		' '		// Ã   31 |-
	}
#endif
;

GLOBAL BYTE LICStab[127]
#if defined(_WKSEXP_C_)
 = {   ' ',          // `  128 Uppercase grave
		' ',		// '  129 Uppercase acute
		' ',		// ^  130 Uppercase circumflex
		' ',		//    131 Uppercase umlaut
		' ',		// ~  132 Uppercase tilde
		' ',		//    133
		' ',		//    134
		' ',		//    135
		' ',		//    136
		' ',		//    137
		' ',		//    138
		' ',		//    139
		' ',		//    140
		' ',		//    141
		' ',		//    142
		' ',		//    143
		' ',		// `  144 Lowercase grave
		' ',		// '  145 Lowercase acute
		' ',		// ^  146 Lowercase circumflex
		' ',		//    147 Lowercase umlaut
		' ',		// ~  148 Lowercase tilde
		'i',		//    149 Lowercase i without dot
		' ',		// _  150 Ordinal indicator
		' ',		//   151 Begin attribute
		' ',		//   152 End attribute
		' ',		// þ  153 Unknown character
		183,		// ù  154 Hard space
		' ',		//   155 Merge character
		' ',		//    156
		' ',		//    157
		' ',		//    158
		' ',		//    159
		131,		// Ÿ  160 Dutch gilder
		161,		// ­  161 Inverted exclamation mark
		162,		// ›  162 Cent sign
		163,		// œ  163 Pound sign
		147,		//    164 Low opening double quotes
		165,		//   165 Yen sign
		' ',		// ž  166 Pesetas sign
		167,		//   167 Section sign
		164,		//    168 General currency sign
		169,		//    169 Copyright sign
		170,		// ¦  170 Feminine ordinal
		171,		// ®  171 Angle quotation mark left
		' ',		//    172 Delta
		' ',		//    173 Pi
		' ',		// ò  174 Greater-than-or-equal
		247,		// ö  175 Divide sign
		176,		// ø  176 Degree sign
		177,		// ñ  177 Plus/minus sign
		178,		// ý  178 Superscript 2
		179,		//    179 Superscript 3
		148,		//    180 Low closing double quotes
		181,		// æ  181 Micro sign
		182,		//   182 Paragraph sign
		183,		//   183 Middle dot
		153,		//    184 Trademark sign
		185,		//    185 Superscript 1
		186,		// §  186 Masculine ordinal
		187,		// ¯  187 Angle quotation mark right
		188,		// ¬  188 Fraction one quarter
		189,		// «  189 Fraction one half
		' ',		// ó  190 Less-than-or-equal
		191,		// ¨  191 Inverted question mark
		192,		// A` 192 Uppercase A with grave
		193,		// A' 193 Uppercase A with acute
		194,		// A^ 194 Uppercase A with circumflex
		195,		// A~ 195 Uppercase A with tilde
		196,		// Ž  196 Uppercase A with umlaut
		197,		//   197 Uppercase A with ring
		198,		// ’  198 Uppercase A with ligature
		199,		// €  199 Uppercase C with cedilla
		200,		// E` 200 Uppercase E with grave
		201,		//   201 Uppercase E with acute
		202,		// E^ 202 Uppercase E with circumflex
		203,		//    203 Uppercase E with umlaut
		204,		// I` 204 Uppercase I with grave
		205,		// I' 205 Uppercase I with acute
		206,		// I^ 206 Uppercase I with circumflex
		207,		//    207 Uppercase I with umlaut
		208,		// D- 208 Uppercase eth (Icelandic)
		209,		// ¥  209 Uppercase N with tilde
		210,		// O` 210 Uppercase O with grave
		211,		// O' 211 Uppercase O with acute
		212,		// O^ 212 Uppercase O with circumflex
		213,		// O~ 213 Uppercase O with tilde
		214,		// ™  214 Uppercase O with umlaut
		140,		// OE 215 Uppercase OE diphthong
		216,		// O/ 216 Uppercase O with slash
		217,		// U` 217 Uppercase U with grave
		218,		// U' 218 Uppercase U with acute
		219,		// U^ 219 Uppercase U with circumflex
		220,		// š  220 Uppercase U with umlaut
		159,		//    221 Uppercase Y with umlaut
		222,		// P- 222 Uppercase thorn (Icelandic)
		223,		// á  223 Lowercase German sharp s
		224,		// …  224 Lowercase a with grave
		225,		//    225 Lowercase a with acute
		226,		// ƒ  226 Lowercase a with circumflex
		227,		// a~ 227 Lowercase a with tilde
		228,		// „  228 Lowercase a with umlaut
		229,		// †  229 Lowercase a with ring
		230,		// ‘  230 Lowercase a with ligature
		231,		// ‡  231 Lowercase c with cedilla
		232,		// Š  232 Lowercase e with grave
		233,		// ‚  233 Lowercase e with acute
		234,		// ˆ  234 Lowercase e with circumflex
		235,		// ‰  235 Lowercase e with umlaut
		236,		//   236 Lowercase i with grave
		237,		// ¡  237 Lowercase i with acute
		238,		// Œ  238 Lowercase i with circumflex
		239,		// ‹  239 Lowercase i with umlaut
		240,		// d- 240 Lowercase eth (Icelandic)
		241,		// ¤  241 Lowercase n with tilde
		242,		// •  242 Lowercase o with grave
		243,		// ¢  243 Lowercase o with acute
		244,		// “  244 Lowercase o with circumflex
		245,		// o~ 245 Lowercase o with tilde
		246,		// ”  246 Lowercase o with umlaut
		156,		// oe 247 Lowercase oe with diphthong
		248,		// í  248 Lowercase o with slash
		249,		// —  249 Lowercase u with grave
		250,		// £  250 Lowercase u with acute
		251,		// –  251 Lowercase u with circumflex
		252,		//   252 Lowercase u with umlaut
		255,		// ˜  253 Lowercase y with umlaut
		254		// p- 254 Lowercase thorn (Icelandic)
	}
#endif
;

// prototypes section

//extern BOOL WINAPI pd_dbfx_CreateFile(LPDBEXP xs, LPSTR far * fld_lst, FARPROC chk_rtn, FARPROC info_rtn);
extern BOOL WINAPI pd_dbfx_CreateFile(LPDBEXP xs, LPSTR fld_lst, GOODFLD chk_rtn, FLDINFO info_rtn);
//extern BOOL WINAPI pd_dbfx_StoreField(LPDBEXP xs, LPSTR field, LPSTR data, LPSTR name, int error, FARPROC goodfld_rtn, FARPROC noval_rtn);
extern BOOL WINAPI pd_dbfx_StoreField(LPDBEXP xs, LPSTR field, LPSTR data, LPSTR name, GOODFLD goodfld_rtn, NOVALUE noval_rtn);
extern void WINAPI pd_dbfx_CloseFile(LPDBEXP xs);

// private prototypes (from dbfxint.c)
extern void numformat(LPSTR data, LPSTR out, UINT width, UINT dp);
extern int write_record(LPDBEXP xs);
extern void padnum(int c, int count, LPSTR s, int before);
extern char far *lsoft(char far *s);
//extern void getdate(ZDATE far *d);
extern void zdateout(FOUR dy,	SYSTEMTIME * dt);
extern BOOL dupefld(LPDBEXP xs, UINT numtocheck, LPSTR fldname);
extern LPSTR make_goodname(LPSTR source, LPSTR dest);

// from dllmem.c
LPSTR dll_globalAlloc(UINT flags,DWORD size);
void dll_globalFree(LPSTR pMem);

// WKS
extern int licschar(int c);
extern int wks_write_record(LPDBEXP xs, long seekoff, BOOL frombegin );
extern BOOL wrfile(LPDBEXP xs, LPSTR buf, UINT cnt);
extern BOOL writehead(LPDBEXP xs, short type, short length);
extern BOOL writeword(LPDBEXP xs, short value);
extern BOOL writebyte(LPDBEXP xs, short value);
extern BOOL writecell(LPDBEXP xs);
extern BOOL writedimen(LPDBEXP xs, short ecol, short erow);
extern BOOL writelabel(LPDBEXP xs, LPSTR label, short just, UINT len);
extern BOOL write_error(LPDBEXP xs, int error);
extern BOOL write_number(LPDBEXP xs, LPSTR number);
extern BOOL write_date(LPDBEXP xs, LPSTR number);
extern BOOL write_blank(LPDBEXP xs);
extern void checklen(LPDBXFLD fld);
extern void checklabel(LPDBXFLD fld, LPSTR destname);
extern BYTE columnlen(WKSFLDDES * flddes);
extern void free_member(void far * member);
extern BOOL wks_dupefld(LPDBEXP xs, UINT numtocheck, LPSTR fldname);

// CSV
extern LPSTR disambiguate(LPSTR source, LPSTR dest, int destsz, LPSTR separator, BOOL always);
extern BOOL flushbuffer(LPDBEXP xs);
extern BOOL writeblank(LPDBEXP xs);
extern BOOL writeerror(LPDBEXP xs);
extern BOOL writefield(LPSTR data, LPDBEXP xs, int fieldno);
extern LPSTR lfstrip(LPSTR data);
#undef GLOBAL
#endif
