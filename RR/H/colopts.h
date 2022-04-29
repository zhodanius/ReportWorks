// ColOpts.h
//
// Purpose:
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _COLOPTS_H_
#define _COLOPTS_H_

#include "datetime.h"

///////////////////////////////////////////////////////////////////////////////
// Type Definitions:                                                         //
///////////////////////////////////////////////////////////////////////////////

// DbaDict column options used by it and CFtxFile low-level transfer classes

#define MAXUSRNAMELEN	32
#define MAXNULLLEN		32	// keep these in sync with size strings in DbaDict\include\DbaDict.h
#define MAXPICTURELEN	34	
#define MAXDECSEPLEN	2
#define MAXMONEYLEN		4

///////////////////////////////////////////////////////////////////////////////
// Type Definitions:                                                         //
///////////////////////////////////////////////////////////////////////////////

typedef struct ColOpts	// All DataDict nodes '\0' terminated options' format strings; used by CFtxFile too
{									
	char UserName[MAXUSRNAMELEN];	// user friendly name
	BOOL UseNulls;					// TRUE => use NullString or NullValue
	char NullString[MAXNULLLEN];	// substitute string or numeric value for NULLable columns
	long NullValue;
	char Picture[MAXPICTURELEN];	// format picture string for date, time, timestamp
	char DecSep[MAXDECSEPLEN];		// decimal separator character
	char MoneySym[MAXMONEYLEN];		// monetary symbol character(s) -- not implemented in version 1

	// Date/Time enum IDs for date/time page users benefit used if Picture[0]=='\0' or DecSep[0]=='\0'

	DateFormatChoices	DateFormat;
	DateSepChoices		DateSep;
	TimeFormatChoices	TimeFormat;
	TimeSepChoices		TimeSep;
	StampDecSepChoices	StampDecSep;
} COLOPTS, FAR *LPCOLOPTS;

#endif //_COLOPTS_H_
