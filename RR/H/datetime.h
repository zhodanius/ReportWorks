/* $Header:   H:/vcsmfc/h/datetime.h_v   1.0   18 Apr 1998 17:54:14   jpb  $ */
/* $Log:   H:/vcsmfc/h/datetime.h_v  $
// 
//    Rev 1.0   18 Apr 1998 17:54:14   jpb
// Initial revision.
 * 
 *    Rev 1.0   11 Dec 1997 11:30:14   shenders
 * Initial revision.
 * 
 *    Rev 3.0.1.1   20 Dec 1996 11:02:50   BUILD
 * Moved Floating Label
 * 
 *    Rev 3.0.1.0.2.0   22 Nov 1996 16:43:50   ANICHOLE
 */
// DateTime.h
//
// Purpose:
//
//      Utility classes and functions to provide SQL_DATE, SQL_TIME and
//		SQL_TIMESTAMP struct conversions to or from '\0' terminated character
//		arrays in memory using '\0' terminated picture format strings 
//		with single quote delimited	separators.  Time stamps are handled
//		by a mix of time stamp specific functions its date and time objects.
//
//		The picture strings supported are restricted to the
//		subset of picture strings in the Separator and Formats types below
//		corresponding to a super set of the numeric formats supported by RUMBA
//		Access/400 File Transfer.  The restriction is due to a lack of Win32
//		API or MFC 3.0 functions to read text using arbitrary picture strings,
//		combined with a lack of time to do it ourselves in OFFICE95 ver. 1.
//
//		Two overloaded versions of functions provided, one using IDs below
//		which will construct picture strings, and the faster version which 
//		takes a picture string as an argument.  The ID using functions support
//		support presettable separators, DBA ISO '-' date and ':' time
//		separators by default, the picture string is built even if no output
//		is desired and can be obtained via GetPictureString prior to using
//		another picture string for the same type.
//
//		Most functions returning SDWORD lengths will return buffer length
//		required without filling input buffer if input buffer size arg = 0.
//
//      Intended to be used by CFtx* text oriented classes, but may be used
//		by other DBA classes such as grid too.
//
//	Assumes:
//	
//		Sql.h (ours which includes SqlTypes.h), and Afx.h or StdAfx.h included.
//
//		Caller provides valid buffer pointers and sizes, and/or catches any 
//		thrown memory exceptions as transfer does.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _DBADATETIME_H_
#define _DBADATETIME_H_

#include "apidef.h"			// EXPORT_API

//  windowsx.h screws up things
#ifndef GlobalFreePtrX
#define GlobalFreePtrX(lp) \
	GlobalUnlock((HGLOBAL)GlobalHandle(lp)), (BOOL)GlobalFree((HGLOBAL)GlobalHandle(lp))
#endif

#ifndef GlobalAllocPtrX
#define     GlobalAllocPtrX(flags, cb)        \
                (GlobalLock(GlobalAlloc((flags), (cb))))
#endif

///////////////////////////////////////////////////////////////////////////////
// Constants    			                                                 //
///////////////////////////////////////////////////////////////////////////////

// These take advantage of the current restriction to numeric values 
// with single char separators

#define MAXDATETEXT 	(10 + 1) * sizeof(TCHAR)		// "1995-01-01" +1 for '\0'
#define MAXDATEPIC		MAXDATETEXT + 4 * sizeof(TCHAR)	// + 4 single quotes

#define MAXTIMETEXT		(11 + 1) * sizeof(TCHAR)		// "12:12:12 AM" +1 for '\0'
#define MAXTIMEPIC		MAXTIMETEXT + 4 * sizeof(TCHAR)	// + 4 single quotes

#define MAXFRACDIGITS	9								// 0 to 999,999,999 without commas
#define MAXFRACTEXT		(MAXFRACDIGITS + 2) * sizeof(TCHAR)	// max second's fraction text length in billionths
															// including '.' and '\0' for ".999999999"
#define MAXFRACPIC		MAXFRACTEXT						// separator + max scale + '\0'

#define MAXSTAMPTEXT	MAXDATETEXT + MAXTIMETEXT - 1 + MAXFRACTEXT
#define MAXSTAMPPIC		MAXDATEPIC + MAXTIMEPIC - 1 + MAXFRACPIC


///////////////////////////////////////////////////////////////////////////////
// Class Type and Related Definitions:                                       //
///////////////////////////////////////////////////////////////////////////////

// Date text format picture strings, separators and class

enum DateSepChoices			// Changes here must be reflected in corresponding array below
{
	DateSepDash =		0,	// "DBA ISO" date separator
	DateSepSlash =		1,
	DateSepPeriod =		2,	// true ISO
	DateSepComma =		3,
	DateSepBlank =		4,
	DateSepNull =		5,	// must not omit any leading zeros
	DateSepIso =		DateSepDash,
	DateSepDefault =	DateSepIso,
	DateSepOff =		-1 	// cue to CDateTimePage to disable corresponding control
};

static const				// Changes here must be reflected in corresponding enum above
LPCTSTR DateSep[] =
{
	"-",	// Dash =	0	// default "DBA ISO" date separator
	"/",	// Slash =	1
	".",	// Period =	2	// true ISO
	",",	// Comma =	3
	" ",	// Blank =	4
	""		// Null =	5	// must not omit any leading zeros
};

static						// Changes here must be reflected in corresponding enum above
LPCTSTR DateSep1[] =
{
	" (-)",	// Dash =	0	// default "DBA ISO" date separator
	" (/)",	// Slash =	1
	" (.)",	// Period =	2	// true ISO
	" (,)",	// Comma =	3
};

enum DateFormatChoices		// Changes here must be reflected in DateFormat[] below
{
	yyyyMMdd =		0,		// ISO, Japanese Industrial Standard
	yyyyMd =		1,	    // and others
	yyMMdd =		2,
	yyMd =			3,
	MMddyyyy =		4,		// USA
	Mdyyyy =		5,
	MMddyy =		6,
	Mdyy =			7,
	ddMMyyyy =		8,		// Europe
	dMyyyy =		9,
	ddMMyy =		10,
	dMyy =			11,
	Julian =		12,		// Julian got left out of pict strings since ddd means abbreviation
	DateIso =		yyyyMMdd,
	DateDefault =	DateIso,
	DateFormatOff =	-1 		// cue to CDateTimePage to disable corresponding control
};

// Supported format picture strings; non-default separators to be applied during I/O.
// Order of DateFormat[] initializers must correspond to DateFormatChoices above.

static
LPCTSTR DateFormat[] =
{
	"yyyy'-'MM'-'dd", "yyyy'-'M'-'d", "yy'-'MM'-'dd", "yy'-'M'-'d",
	"MM'-'dd'-'yyyy", "M'-'d'-'yyyy", "MM'-'dd'-'yy", "M'-'d'-'yy",
	"dd'-'MM'-'yyyy", "d'-'M'-'yyyy", "dd'-'MM'-'yy", "d'-'M'-'yy",
	"Julian"
};

class CDbaDate
{
public:

	// Gets separator used on last I/O call.
	// Returns size for storage; will copy if input buffer is large enough.

	SDWORD EXPORT_API GetDateSeparator(LPTSTR pBufOut, SDWORD cbBuf = 0) {
				if (cbBuf >= m_cbSep && NULL != pBufOut) strcpy(pBufOut, m_pSep);
				return(m_cbSep); }

	// Sets separators used in subsequent functions with picture string IDs.
	//   If NULL, reverts to default separator.

	SDWORD	EXPORT_API SetDateSeparator(DateSepChoices sep = DateSepDefault) {
				m_iSep = sep;
				m_pSep = (LPTSTR)DateSep[m_iSep]; 
				m_cbSep = (m_iSep != DateSepNull) ? (SDWORD)strlen(m_pSep) + 1 : 0;
				return(m_cbSep); }

	// For potential use with col def for serialization of picture string by class user
	// when TimeFormatChoices form of function last used, i.e. get picture string used for ID.
	// Returns storage size for string including '\0' terminator; won't access input buf if input size is 0

	SDWORD	EXPORT_API GetPictureString(LPTSTR pszPictureString, SDWORD cbPictureString);	 

	// Conversion functions

	SDWORD	EXPORT_API DateToText (	// returns length of text plus '\0', or 0 if error
				const	DATE_STRUCT *		pSysDateIn,		// if NULL, uses current date; time members ignored
						LPTSTR				pTextOut,		// pointer to output buffer
						SDWORD				cbTextIn,		// max output buffer size with '\0' terminator
															// if 0, returns size of buffer needed without using buffer
						LPCTSTR				pszPictureIn	// pointer to '\0' terminated picture string
				);


	SDWORD	EXPORT_API DateToText(		// returns length of text plus '\0', or 0 if error
				const	DATE_STRUCT *		pSqlDateIn,		// if NULL, uses current date
						LPTSTR				pTextOut,		// pointer to output buffer
						SDWORD				cbTextIn,		// max output buffer size with '\0' terminator
															// if 0, returns size of buffer needed without using buffer
						DateFormatChoices 	DateForm = DateDefault
				);											

	SDWORD	EXPORT_API TextToDate (	// returns length of text processed without '\0', or 0 if error
						LPCTSTR				pTextIn,		// pointer to input buffer
						SDWORD				cbTextIn,		// max input buffer size without '\0' terminator
						DATE_STRUCT *		pSqlDateOut,	// pointer to result
						LPCTSTR				pszPictureIn	// pointer to '\0' terminated picture string
				);
				
	SDWORD	EXPORT_API TextToDate (	// returns length of text processed without '\0', or 0 if error
						LPCTSTR				pTextIn,		// pointer to input buffer
						SDWORD				cbTextIn,		// max input buffer size without '\0' terminator
						DATE_STRUCT *		pSqlDateOut,	// pointer to result
						DateFormatChoices 	DateForm = DateDefault
				);

	// Constructor and destructor

	EXPORT_API CDbaDate()	{
					m_rText[0] =	'\0';
					m_pText =		m_rText;
					m_cbText =		0;
					m_iSep =		DateSepDefault;
					m_pSep =		(LPTSTR)DateSep[m_iSep];
					m_cbSep =		(SDWORD)strlen(m_pSep) + 1;
					m_iFormat =		DateDefault;
					m_pFormat =		(LPTSTR)DateFormat[m_iFormat];
					m_cbFormat =	(SDWORD)strlen(m_pFormat) + 1;
					m_pPic =		(LPTSTR)m_rPic;
					strcpy(m_pPic, m_pFormat);
					m_cbPic =		sizeof(m_rPic);
				};

	EXPORT_API ~CDbaDate() {
					if (m_rText != m_pText && NULL != m_pText)
						GlobalFreePtrX(m_pText);

					if (m_rPic != m_pPic && NULL != m_pPic)
						GlobalFreePtrX(m_pPic);
				};

	// Needed by Time Stamp

	DateFormatChoices	m_iFormat;				// last used enum format ID and character string
	LPTSTR				m_pFormat;
	SDWORD				m_cbFormat;				// length of format string + '\0' terminator

private:

	DateSepChoices		m_iSep;					// date separator ID character string
	LPTSTR				m_pSep;
	SDWORD				m_cbSep;				// for non-NULL, includes '\0' terminator

	TCHAR				m_rPic[MAXDATEPIC];		// last enum format ID composed picture string
	LPTSTR				m_pPic;
	SDWORD				m_cbPic;				// length of picture string + '\0' terminator

	TCHAR				m_rText[MAXDATETEXT];	// formatted text representation of date
	LPTSTR				m_pText;				// may point to global buffer if rText too small
	SDWORD				m_cbText;				// sizeof rText or dynamic text buffer

	void	ReplaceDefaultSep (					// create picture string with choice of separators
				LPCTSTR		pDateFormatIn,		// pointer to picture with default separator
				LPCTSTR		pDateSepIn,			// pointer to desired separator
				LPTSTR		pDatePicOut );		// pointer to desired result; assumed to be big enough

	SDWORD DateToJulianText (					// returns length of text including '\0'
		const	DATE_STRUCT *	pDateIn,		// pointer to desired or current system date
				LPTSTR			pTextOut,		// pointer to output buffer
				SDWORD			cbTextIn );		// max output buffer size with '\0' terminator
												// if 0, returns size of buffer needed without using buffer

	UWORD DateToJulianDays(const DATE_STRUCT * pSqlDateIn); // returns # of days into year for date

	SDWORD JulianTextToDate (					// returns # chars processed without '\0'
				LPCTSTR			pTextIn,		// pointer to input buffer
				SDWORD			cbTextIn,		// max input buffer size without '\0' terminator
				DATE_STRUCT *	pSqlDateOut	);	// pointer to result
				
	void JulianDaysToDate (
				DATE_STRUCT *	pSqlDateInOut,	// year in, full date out
				UWORD			cDaysIn );		// days for this year
};


// Time text format picture strings, separators and class text format class

enum TimeSepChoices	// Changes here must be reflected in corresponding array below
{
	TimeSepColon =		0,
	TimeSepPeriod =		1,
	TimeSepComma =		2,
	TimeSepBlank =		3,
	TimeSepNull =		4,	// must not omit any leading zeros
	TimeSepIso =		TimeSepColon,
	TimeSepDefault =	TimeSepIso,
	TimeSepOff =		-1,	// cue to CDateTimePage to disable corresponding control
};

static const				// Changes here must be reflected in corresponding enum above
LPCTSTR TimeSep[] =
{
	":",	// Colon =	0	// Default DBA ISO separator
	".",	// Period =	1
	",",	// Comma =	2
	" ",	// Blank =	3
	""		// Null =	4	// must not omit any leading zeros in time format
};

static						// Changes here must be reflected in corresponding enum above
LPCTSTR TimeSep1[] =
{
	" (:)",	// Colon =	0	// Default DBA ISO separator
	" (.)",	// Period =	1
	" (,)"	// Comma =	2
};

enum TimeFormatChoices		// Changes here must be reflected in corresponding array below
{
	HHmmss =		0,		// 24 hour time; ISO
	Hmmss =			1,
	hhmmsstt =		2,		// 12 hour time with NLS'd AM or PM primarily for USA
	hmmsstt =		3,
	hhmmtt =		4,		// 12 hour time without seconds for RumbaFil compatibility
	hmmtt =			5,
	TimeIso =		HHmmss,	
	TimeDefault =	TimeIso,
	TimeFormatOff =	-1,		// cue to CDateTimePage to disable corresponding control
};

// Supported format picture strings.  Separators will be parsed for and replaced as needed.

static						// Changes here must be reflected in corresponding enum above
LPCTSTR TimeFormat[] =
{
	"HH':'mm':'ss", "H':'mm':'ss", "hh':'mm':'ss tt", "h':'mm':'ss tt",
	"hh':'mm tt", "h':'mm tt"
};

class CDbaTime
{
public:

	// Gets separator used on last I/O call.
	// Returns size for storage; will copy if input buffer is large enough.

	SDWORD	EXPORT_API GetTimeSeparator(LPTSTR pBufOut, SDWORD cbBuf = 0) {
					if (cbBuf >= m_cbSep && NULL != pBufOut) strcpy(pBufOut, m_pSep);
					return(m_cbSep);	}

	// Sets separators used in subsequent functions with picture string IDs.
	//   If NULL, reverts to default separator.

	SDWORD	EXPORT_API SetTimeSeparator(TimeSepChoices sep = TimeSepDefault) {
				m_iSep = sep;
				m_pSep = (LPTSTR)TimeSep[m_iSep]; 
				m_cbSep = (m_iSep != TimeSepNull) ? (SDWORD)strlen(m_pSep) + 1 : 0;
				return(m_cbSep); }

	// For potential use with col def for serialization of picture string by class user
	// when TimeFormatChoices form of function last used, i.e. get picture string used for ID.
	// Returns storage size for string including '\0' terminator; won't access input buf if input size is 0

	SDWORD	EXPORT_API GetPictureString(LPTSTR	pszPictureString, SDWORD cbPictureString);	 

	// Conversion functions

	SDWORD	EXPORT_API TimeToText (	// returns length of text with '\0', or 0 if error
				const	TIME_STRUCT *		pSqlTimeIn,		// if NULL, uses current time
						LPTSTR				pTextOut,		// pointer to output buffer
						SDWORD				cbTextIn,		// max output buffer size with '\0' terminator
															// 0 returns size of buffer needed without using buffer
						LPTSTR				pszPictureIn 	// pointer to '\0' picture string
				);											// may be modified for separators

	SDWORD	EXPORT_API TimeToText (		// returns length of text with '\0', or 0 if error
				const	TIME_STRUCT *		pSqlTimeIn,		// if NULL, uses current time
						LPTSTR				pTextOut,		// pointer to output buffer
						SDWORD				cbTextIn,		// max output buffer size with '\0' terminator
															// if 0, returns size of buffer needed without using buffer
						TimeFormatChoices	TimeForm = TimeDefault
				);											

	SDWORD	EXPORT_API TextToTime (	// returns length of text processed without '\0', or 0 if error
						LPCTSTR				pTextIn,		// pointer to input buffer
						SDWORD				cbTextIn,		// max input buffer size without '\0' terminator
						TIME_STRUCT *		pSqlTimeOut,	// pointer to result
						LPCTSTR				pszPictureIn
				);

	SDWORD	EXPORT_API TextToTime (		// returns length of text processed without '\0', or 0 if error
						LPCTSTR				pTextIn,		// pointer to input buffer
						SDWORD				cbTextIn,		// max input buffer size without '\0' terminator
						TIME_STRUCT *		pSqlTimeOut,	// pointer to result
						TimeFormatChoices 	TimeForm = TimeDefault
				);
				
	// Constructor and destructor

	EXPORT_API CDbaTime()	{
					m_rText[0] =	'\0';
					m_pText =		m_rText;
					m_cbText =		0;
					m_iSep =		TimeSepDefault;
					m_pSep =		(LPTSTR)TimeSep[m_iSep];
					m_cbSep =		(SDWORD)strlen(m_pSep) + 1;
					m_iFormat =		TimeDefault;
					m_pFormat =		(LPTSTR)TimeFormat[m_iFormat];
					m_cbFormat =	(SDWORD)strlen(m_pFormat) + 1;
					m_pPic =		(LPTSTR)m_rPic;
					strcpy(m_pPic, m_pFormat);
					m_cbPic =		sizeof(m_rPic);
				};

	EXPORT_API ~CDbaTime() {
					if (m_rText != m_pText && NULL != m_pText)
						GlobalFreePtrX(m_pText);

					if (m_rPic != m_pPic && NULL != m_pPic)
						GlobalFreePtrX(m_pPic);
				};

	// Needed by Time Stamp

	TimeFormatChoices	m_iFormat;				// last enum format ID and character string
	TCHAR *				m_pFormat;
	SDWORD				m_cbFormat;				// length of format string + '\0' terminator

private:

	TCHAR				m_rText[MAXTIMETEXT];	// output buffer for anticipated formats
	TCHAR *				m_pText;				// may point to global buffer if rText too small
	SDWORD				m_cbText;

	TimeSepChoices		m_iSep;					// separator between date and time
	TCHAR *				m_pSep;
	SDWORD				m_cbSep;				// non-NULL length includes '\0' terminator

	TCHAR				m_rPic[MAXTIMEPIC];		// last enum format ID composed picture string
	LPTSTR				m_pPic;			  
	SDWORD				m_cbPic;				// length of picture string + '\0' terminator

	void ReplaceDefaultSep (					// create picture string with choice of separators
				LPCTSTR		pTimeFormatIn,		// pointer to picture with default separator
				LPCTSTR		pTimeSepIn,			// pointer to desired separator
				LPTSTR		pTimePicOut );		// pointer to desired result; assumed to be big enough
};


// TimeStamp text format separators and class text format class

enum StampSepChoices		// Changes here must be reflected in corresponding array below
{
	StampSepBlank =		0,
	StampSepTab =		1,
	StampSepNull =		2,	// must not omit any leading zeros
	StampSepDash =		3,
	StampSepIso =		StampSepBlank,
	StampSepDefault =	StampSepIso,
	StampSepOff =		-1,	// cue to CDateTimePage to disable corresponding control
};

static const				// Timestamp's time separator from date
LPCTSTR StampSep[] =		// Changes here must be reflected in corresponding enum above
{
	" ",	// Blank =	0	// default DBA (not ISO) separator
	"\t",	// Tab =	1
	"",		// Null =	2	// must not omit any leading zeros
	"-"		// Dash =	3	// Host ISO and Win16 AS/400 file transfer separator
};

enum StampDecSepChoices		// Changes here must be reflected in corresponding array below
{
	StampDecSepPeriod =		0,
	StampDecSepComma =		1,
	StampDecSepIso =		StampDecSepPeriod,
	StampDecSepDefault =	StampDecSepIso,
	StampDecSepOff =		-1,	// cue to CDateTimePage to disable corresponding control
};

static const				// Second's decimal fraction separator
LPCTSTR StampDecSep[] =		// Changes here must be reflected in corresponding enum below	
{
	".",	// DecimalPeriod =	0	// default DBA ISO separator
	"," 	// DecimalComma =	1
};

static						// Second's decimal fraction separator
LPCTSTR StampDecSep1[] =		// Changes here must be reflected in corresponding enum below	
{
	" (.)",	// DecimalPeriod =	0	// default DBA ISO separator
	" (,)" 	// DecimalComma =	1
};

enum StampFormatChoices
{
	StampFormIso =			0,				// DBA ISO format
	StampFormComposite =	1,				// Build your own from date and time formats
	StampFormDefault =		StampFormIso
};

class CDbaTimeStamp
{
public:

	// Sets separator between date and time, vs. within them.
	// If NULL, default DBA ISO blank separator used between date and time.

	SDWORD	EXPORT_API SetStampSeparator(StampSepChoices sep = StampSepDefault) {
				m_iSep = sep;
				m_pSep = (LPTSTR)StampSep[m_iSep];
				m_cbSep = (m_iSep != StampSepNull) ? (SDWORD)strlen(m_pSep) + 1 : 0;
				return( m_cbSep ); }

	// Sets Second's decimal "point" separator; assumed to be 1 character.
	// If NULL, default DBA ISO '.' separator used.

	SDWORD	EXPORT_API SetStampDecimalSeparator(StampDecSepChoices sep = StampDecSepDefault) {
				m_iDecSep = sep; 
				return( sizeof(TCHAR) ); }

	// Set Date or Time Separators

	void SetDateSeparator(DateSepChoices ds = DateSepDefault)
			{ m_DbaDate.SetDateSeparator(ds); }

	void SetTimeSeparator(TimeSepChoices ts = TimeSepDefault)
			{ m_DbaTime.SetTimeSeparator(ts); }

	// For potential use with col def for serialization of picture string by class user
	// when TimeFormatChoices form of function last used, i.e. get picture string used for ID.
	// Returns storage size for string including '\0' terminator; won't access input buf if input size is 0

	SDWORD	EXPORT_API GetPictureString(LPTSTR	pszPictureString, SDWORD cbPictureString);	 

	// Conversion functions

	// suitable for 1 picture string per column interface

	SDWORD EXPORT_API StampToText (						// returns length of text with '\0'
		const	TIMESTAMP_STRUCT *	pStampIn,		// if NULL, uses current time; date members ignored
				LPTSTR				pTextOut,		// pointer to output buffer
				SDWORD				cbTextIn,		// max output buffer size with '\0' terminator
													// if 0, returns size of buffer needed without using buffer
				LPCTSTR				pszPicDateTimeIn,	// '\0' terminated date + time format picture strings
				SWORD				cFractionScale = MAXFRACDIGITS	// desired scale for fraction; defaults to max of MAXFRACDIGITS
				);

	SDWORD	EXPORT_API StampToText	(							// returns length of text with '\0'
		const	TIMESTAMP_STRUCT *	pSqlStampIn,	// if NULL, uses current time; date members ignored
				LPTSTR				pTextOut,		// pointer to output buffer
				SDWORD				cbTextIn,		// max output buffer size with '\0' terminator
													// if 0, returns size of buffer needed without using buffer
				LPCTSTR				pszPicDateIn,	// '\0' terminated date + time format picture strings
				LPCTSTR				pszPicTimeIn,
				SWORD				cFractionScale = MAXFRACDIGITS	// desired scale for fraction
				);

	SDWORD	EXPORT_API StampToText (							// returns length of text with '\0'
		const	TIMESTAMP_STRUCT *	pSqlStampIn,	// if NULL, uses current date
				LPTSTR				pTextOut,		// pointer to output buffer
				SDWORD				cbTextIn,		// max output buffer size with '\0' terminator
													// if 0, returns size of buffer needed without using buffer
				DateFormatChoices	DateFormIn,		// composite from date + time formats
				TimeFormatChoices	TimeFormIn,
				SWORD				cFractionScale = MAXFRACDIGITS	// desired scale for fraction
				);									
		 	
	SDWORD	EXPORT_API StampToText (							// returns length of text with '\0'
		const	TIMESTAMP_STRUCT *	pSqlStampIn,	// if NULL, uses current date
				LPTSTR				pTextOut,		// pointer to output buffer
				SDWORD				cbTextIn,		// max output buffer size with '\0' terminator
													// if 0, returns size of buffer needed without using buffer
				SWORD				cFractionScale = MAXFRACDIGITS,			// desired scale for fraction
				StampFormatChoices	StampForm = StampFormDefault	// use ISO or date/time composition

				);
				
	// suitable for 1 picture string per column interface

	SDWORD EXPORT_API TextToStamp (							// returns length of text processed without '\0'
				LPCTSTR				pTextIn,		// pointer to input buffer
				SDWORD				cbTextIn,		// max input buffer size without '\0' terminator
				TIMESTAMP_STRUCT *	pSqlStampOut,	// pointer to result
				LPCTSTR				pszPicDateTimeIn,	// pointer to '\0' terminated picture strings
				SWORD				cFractionScale = MAXFRACDIGITS // desired scale for fraction; defaults to max of MAXFRACDIGITS
				);
		 	
	SDWORD	EXPORT_API TextToStamp	(	// returns length of text with '\0'
				LPCTSTR				pTextIn,		// pointer to input buffer
				SDWORD				cbTextIn,		// max input buffer size with '\0' terminator
				TIMESTAMP_STRUCT *	pSqlStampOut,	// pointer to result
				LPCTSTR				pszPicDateIn,	// pointer to '\0' terminated picture strings
				LPCTSTR				pszPicTimeIn,
				SWORD				cFractionScale = MAXFRACDIGITS	// desired scale for fraction; defaults to max of MAXFRACDIGITS
				);

	SDWORD	EXPORT_API TextToStamp (	// returns length of text with '\0'
				LPCTSTR				pTextIn,		// pointer to input buffer
				SDWORD				cbTextIn,		// max input buffer size with '\0' terminator
				TIMESTAMP_STRUCT *	pSqlStampOut,	// pointer to result
				DateFormatChoices	DateForm,		// enum IDs for picture strings
				TimeFormatChoices	TimeForm,
				SWORD				cFractionScale = MAXFRACDIGITS	// desired scale for fraction; defaults to max of MAXFRACDIGITS
				); 

	SDWORD	EXPORT_API TextToStamp (	// returns length of text with '\0'
				LPCTSTR				pTextIn,		// pointer to input buffer
				SDWORD				cbTextIn,		// max input buffer size with '\0' terminator
				TIMESTAMP_STRUCT *	pSqlStampOut,	// pointer to result
				SWORD				cFractionScale = MAXFRACDIGITS,			// desired scale for fraction; defaults to max of MAXFRACDIGITS
				StampFormatChoices 	StampFormIn	= StampFormDefault	// if NULL, use DBA ISO format
				);

	// Constructor and destructor

	EXPORT_API CDbaTimeStamp()	{
						m_uFraction =		0;
						m_pFractionBuf[0] =	'\0';
						m_iSep =			StampSepDefault;
						m_pSep =			(LPTSTR)StampSep[m_iSep];
						m_cbSep =			(m_pSep[0]) ? (SDWORD)strlen(m_pSep) + 1 : 0;
						m_iDecSep =			StampDecSepDefault;
						m_pDecSep =			(LPTSTR)StampDecSep[m_iSep];
						m_iFormat =			StampFormDefault;
					}

	EXPORT_API ~CDbaTimeStamp(){}

private:

	SQLUINTEGER			m_uFraction;					// SQL ulong fractional second
	UCHAR				m_pFractionBuf[MAXFRACTEXT];	//   SYSTEMTIME's is ushort, so handle overflow here

	StampSepChoices		m_iSep;							// separator between date and time
	LPTSTR				m_pSep;
	SDWORD				m_cbSep;						// includes any '\0' terminator

	StampDecSepChoices	m_iDecSep;						// second fraction's decimal point; assumes 1 char
	LPTSTR				m_pDecSep;

	StampFormatChoices	m_iFormat;						// last enum format ID

	CDbaDate			m_DbaDate;			// these objects do most of the work including making
	CDbaTime			m_DbaTime;			// pic strings and setting their internal separators

	// Write any fractional second beyond ushort capacity
	// Returns length of fraction's text + '.' and '\0', without writing if cbBufOut is 0, or
	// Returns 0 if error

	SDWORD	WriteFraction(	SQLUINTEGER		uFractionIn,
							LPTSTR			pBufOut,
							SDWORD			cbBufOut,
							SWORD			nMaxScale = MAXFRACDIGITS);	// max scale of fraction

	// Read any fractional second
	// Returns fraction which could be 0, or 0 if error or no fraction requested

	SDWORD ReadFraction (	LPCTSTR			pTextIn,		// pointer to non-'\0' terminated buffer
							SDWORD			cbTextIn,		// and its size
							SQLUINTEGER *	pFractionOut );	// pointer to fraction value to return

};

#endif //_DBADATETIME_H_
