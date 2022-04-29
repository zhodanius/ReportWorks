// ****************************************************************************
//
//      (C) Copyright 1997 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $Workfile:   rrchart.h  $
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
// $Log:   H:/VCSMFC/H/RRCHART.H_V  $
// 
//    Rev 1.47   14 Jan 1998 14:53:18   jsf
// PTF20001 changes
// 
//    Rev 1.46.2.0.1.0   11 Dec 1997 15:24:40   JSF
// WO152082, WO152084, WO152103
// 
//    Rev 1.46.2.0   05 Nov 1997 14:39:34   jsf
// merge 8.0/2.0 base with charting PTF
// 
//    Rev 1.46.1.0   23 Oct 1997 14:32:16   jsf
// charting PTF 1
// 
//    Rev 1.46   18 Jun 1997 19:56:32   dlm
// Fix description of y-axis rotation member variable to reflect reality.
// 
//    Rev 1.45   13 Jun 1997 17:10:10   dlm
// Added code to "delete confirmation" dialog to explain which if any charts
//  will be affected.
// Added code to verify that all value fields are zfNUMERIC in
//  PrepareForPrinting.
// Modules are: rrchart.cpp, rrchlist.cpp, ddelcon.cpp, mfdelcon.cpp,
//  mfrepfld.cpp, wprint.cpp, rrw.str, common.rc, resource.h, rrdoc.h,
//  wdialog.h, rrcompos.h, rrchart.h
// 
//    Rev 1.44   12 Jun 1997 14:16:34   dlm
// Added m_eRangeType and support for it in Get/SetLimits().
// Added SetValueGroupLevel function as part of support for mixing values
//  from different group levels in a single chart.
// 
//    Rev 1.43   09 Jun 1997 18:28:00   dlm
// Added support to SetLabelType and SetSortType functions to allow file-open
//  code to remember field IDs but not yet try to determine field types, since
//  field IDs still need to be "fixed up" before they can be relied upon.
//  Field IDs are set again in code called from readend, at which time data
//  types are also set.
// 
//    Rev 1.42   02 Jun 1997 20:22:12   dlm
// Added support for deletion of ChartLists that have "gone bad" by adding
//  CRrChart::DeleteList(), ChartList::SetNext(), ChartListItem::SetNext().
// 
// 
//    Rev 1.41   29 May 1997 17:22:38   jsf
// Changed PrepareforPrinting()'s parameter to RRCHART structure
// 
//    Rev 1.40   27 May 1997 20:43:12   dlm
// Added new validity checks and a new CRrDoc function called 
//  ChartErrorMessage to convert an error enum value to a displayed message.
// Changed return type of both PrepareForPrinting functions to be a new
//  CHARTERR enum value, instead of a BOOL.
// Changed sort comparison routines to add a "flat" argument so that string
//  comparisons for combining values follow COMPFLAT rules.
// Modules changed:
//  RRDOC.H, RRCHART.H, RRESOURCE.H
//  RRCHART.CPP, RRCHLIST.CPP, WPRINT.CPP
//  RRW.STR
// 
//    Rev 1.39   26 May 1997 16:55:10   dlm
// Added ComputeFieldGroupLevel to ChartList class as part of fix to
//  WO 130460.
// 
//    Rev 1.38   20 May 1997 15:21:38   dlm
// Changed return type of CombineValues from void to BOOL.
// 
//    Rev 1.37   19 May 1997 19:09:08   dlm
// Added new CRrChart members m_bCombineSubDups, m_bDataLabels, m_RotYTitle,
//  m_Min, m_Max to support option for combining duplicate sub-category
//  values, display numeric data labels, rotate the y-axis title by +/- 90
//  degrees, and specify y-axis limits.
// Modified
//  Get/SetCombineDups() to take second argument for m_bCombineSubDups,
//  Get/SetOptions() to take new last argument for m_bDataLabels,
//  Get/SetText() to take new last argument for m_RotYTitle.
// Added
//  Get/SetLimits() for m_Min, m_Max.
// Added serialization support for the 5 new members.
// Affected modules are RRCHART.H, RRCHART.CPP, RRCHLIST.CPP, GRFIELD.CPP,
//  RPWRITEX.CPP.
// 
//    Rev 1.36   16 May 1997 13:35:02   par
// HTML export of charts requires a temporary string.
// 
//    Rev 1.35   15 May 1997 21:14:30   dlm
// Added support for data labels of date, time, datetime, and logical types.
// 
//    Rev 1.34   15 May 1997 15:16:26   dlm
// Changed Get/SetBandLine() to Get/SetBand() to more accurately 
//  represent their purpose.
// Added Get/SetCombineDups().
// 
//    Rev 1.33   15 May 1997 10:53:34   dlm
// Got rid of cropRect in RRCHART structure and removed references to it
//  elsewhere - replacing them with fhdr.fr.
// 
//    Rev 1.32   14 May 1997 11:03:46   dlm
// Part of fix for charting of record data in headers.  In total.cpp we
//  now remember the most recent break level when we're capturing a non-total
//  value.  In rrdoc.h, added m_LastBreakLevel.  In rrchart.h, added
//  m_LastBreakLevel and functions to set/get it.  In rrchlist.cpp, added code
//  to set last break level when adding items to list and code to ItemCount to
//  decide when we've reached the end of a group of values.  In rrchitem.cpp,
//  added get/set functions for last break level.
// 
//    Rev 1.31   13 May 1997 15:17:14   dlm
// Added code to prepare charts for printing and do last-minute validity
//  checks.
// 
//    Rev 1.30   12 May 1997 19:43:44   dlm
// Added to ChartList:
//  MakeValue and MakeLabel to get data from current record when no
//   data is captured because we're either doing record-band charts
//   or data for totals at a shallower level.
//  Assignment operator for benefit of chart copying.
//  New constructor for benefit of chart copying.
// Added to CRrChart:
//  Assignment operator for benefit of chart copying.
//  Copy constructor for benefit of chart copying.
//  m_bHorizontal for remembering bar orientation.
//  Modified Get/SetOptions to support m_bHorizontal.
// 
//    Rev 1.29   12 May 1997 13:44:36   dlm
// Added declarations of SetNeeded() in both CRrChart and ChartList classes.
// 
//    Rev 1.28   10 May 1997 16:57:40   dlm
// Fixed following bugs:
//  Added CRrChart::DeleteLists so editing charts works.
//  Pass break level to ChartList::ItemCount so charts of data more than
//   one break level down relative to band line get all appropriate data.
//  Fixed data manipulation for charts with sublists so right data shows
//   for a given label after internal sorts shuffle the labels.
// 
//    Rev 1.27   09 May 1997 14:15:48   dlm
// Added numerous function declarations in CRrChart and ChartList related
//  to updating field IDs at end of report retrieve and upon field deletion.
// 
//    Rev 1.26   08 May 1997 19:25:08   dlm
// Added Serialize functions to CRrChart and ChartList classes.
// Added an AddList overload for use in serialization.
// Replaced GetListPair with GetListInfo.
// 
//    Rev 1.25   07 May 1997 17:56:08   SRM
// move rrchart struct from wfield.h
// 
//    Rev 1.24   07 May 1997 15:13:46   dlm
// Changed how label and value arrays are allocated and freed to hide it
//  within CRrChart class.
// 
//    Rev 1.23   02 May 1997 15:41:06   jsf
// More support for CChartSheet as a right-click property dialog
// 
//    Rev 1.22   30 Apr 1997 17:10:42   dlm
// Added charting pass status stuff.
// Added get/set functions for chart style (as opposed to type) and 
//  changed argument type for get/set type functions to use enum instead
//  of int.
// 
//    Rev 1.21   29 Apr 1997 13:12:40   dlm
// Added support for ascending/descending flag to AddList, etc.
// 
//    Rev 1.20   29 Apr 1997 09:12:00   dlm
// Added support for charts in headers/title.
// 
//    Rev 1.19   25 Apr 1997 10:34:46   dlm
// Added z-axis label support.
// 
//    Rev 1.18   15 Apr 1997 13:02:34   dlm
// Added SameSortValues and InList to ChartList class.
// 
//    Rev 1.17   14 Apr 1997 15:05:18   dlm
// Added GetSubList to ChartListItem and PopulateArrays to ChartList.
// 
//    Rev 1.16   11 Apr 1997 18:10:50   dlm
// Changed arguments to AllocateArrays.
// Added DeAllocateArrays.
// 
//    Rev 1.15   11 Apr 1997 16:21:44   dlm
// Enhanced ARRAYS structure so that it can package up everything needed
//  by CombineValues and SortLists to make them general enough to use for
//  sublists.
// 
//    Rev 1.14   11 Apr 1997 13:04:12   dlm
// Added pValues and pLabels to Arrays and changed SortLists and
//  CombineValues to use them.
// 
//    Rev 1.13   11 Apr 1997 12:39:28   dlm
// Added DEBTRACE macro.
// Changed arguments to SortLists, CombineValues.
// 
//    Rev 1.12   10 Apr 1997 17:57:14   dlm
// Added definition of ARRAYS structure and tidied up a bit.
// 
//    Rev 1.11   09 Apr 1997 17:48:36   dlm
// Fixed some function declarations.
// 
//    Rev 1.10   09 Apr 1997 16:59:38   dlm
// Added SubListItemCount() function declaration to ChartListItem class.
// 
//    Rev 1.9   09 Apr 1997 12:03:10   dlm
// Started implementing changes required for chart types requiring "sublists"
//  such as stacked bar charts.
// 
//    Rev 1.8   07 Apr 1997 09:55:20   dlm
// Add forward declaration of CRrChart.
// 
//    Rev 1.7   05 Apr 1997 19:19:38   dlm
// Added declaration of ListCount function to CRrChart class.
// 
//    Rev 1.6   04 Apr 1997 18:51:44   dlm
// See rrchart.cpp 1.8 for source of some of these changes.
// Also removed various #if 0-ed blocks of code.
// 
//    Rev 1.5   03 Apr 1997 19:21:12   dlm
// More changes relating to combining values for duplicate labels.
// 
//    Rev 1.4   03 Apr 1997 10:54:18   dlm
// Added stuff to support sorting chart entries on a field other than the
//  "label" field.
// Did more work towards combining values with same value of "sort" field
//  when charting from more than one level down.
// 
//    Rev 1.3   27 Mar 1997 15:04:40   dlm
// More charting changes.
// 
//    Rev 1.2   27 Mar 1997 10:22:36   dlm
// Another round of charting code with stuff conditional on CHARTING.
// 
//    Rev 1.1   20 Mar 1997 19:54:20   dlm
// Another round of implementation of charting classes.
// 
//    Rev 1.0   19 Mar 1997 09:14:38   dlm
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _RRCHART_H_

//
// Includes needed by this header.
//
	#include "util.h"
	#include "mffield.h"
	#include "gsw.h"
	#include "chartdat.h"	// for enums for chart type and style

// Make a definition for this module.
//
#define _RRCHART_H_

// ***************
// Issues and questions:
// Does clrTot get called when printing for preprocessed totals?  If not
//	what is the corresponding place at which to remember totals?
// When should db field data from non-terminal scanner get accumulated?
//	( order total from orders file when scanning items, e.g. )
// prev buffers?  Look at mfcpy*() and mfcopy*() (all implemented in mfrdflds)
// Where do calc data buffers get written?
// Where do db field data buffers get written?
// Avg, StdDev, Var data?
// Where does CRrChart object get created? (after drawing rectangle for chart?)
// Data from Data tab causes ChartList object(s) to be added.
// Only numeric "values" make sense, but labels could be any data type and need to
//  be converted to text.
// ***************

//#define TRACEM
#if defined(TRACEM)
#define DEBTRACE	TRACE
#else
#define DEBTRACE	TRACENOT
#endif

#define TRACENOT	//

// Current Schema number for serialization of charts
const int CHART_SCHEMA = 6;

// helper structures and related info
enum DATATYPE { tCHAR, tNUMERIC, tDATE, tDATETIME, tTIME, tLOGICAL };
#define MAPDATATYPE(x) ( (x)->dFlags & zfNUMERIC	? tNUMERIC : \
						 (x)->dFlags & zfDATE		? tDATE : \
						 (x)->dFlags & zfDATETIME	? tDATETIME : \
						 (x)->dFlags & zfTIME		? tTIME : \
						 (x)->dFlags & zfLOGICAL	? tLOGICAL : tCHAR )
enum TOTALTYPE { tCOUNT=TCNT, tSUM=TSUM, tAVG=TAVG, tMIN=TMIN, tMAX=TMAX, tDEV=TSTD, tVAR=TVAR, tNONE };

enum CHARTERR { errNONE,					// No errors
				errINCOMPLETE_MAIN,			// Incompletely specified value/sort/label set
				errINCOMPLETE_SUB_CAT,		// Incompletely specified value/sort/label sub-category set
				errSUB_CAT_CONFLICT,		// Can't have multiple fields AND a sub-category field
				errSUB_CAT_IN_RECORD_BAND,	// Can't have sub-category in record-band chart
				errSUB_CAT_LEVEL,			// Sub-category must be deeper level than main value field
				errSUB_CAT_SAME,			// Sub-category can't be same as selected field
				errGROUP_LEVEL_CONFLICT,	// All values being charted must be from same group level
				errFIELDS_DELETED,			// Fields delete so chart is now incomplete
				errNEW1,					// Available for expansion without full rebuild!!
				errNEW2,
				errNEW3,
				errNEW4,
				errNEW5
			  };

class CRrChart;
class ChartList;
class CRrComposite;

// A single chart field may have many charts associated with it in print/preview.
// For instance, a chart in a record band would have a chart per record.  The
// metafile handle chain keeps track of all the open metafiles associated with a
// field.
struct mfhandlelink
{
	struct mfhandlelink *next;	// pointer to next link
	HENHMETAFILE	handle;		// memory metafile handle
};

typedef struct rrchart	// report writer chart structure
{
	struct fieldhdr fhdr;			// field header structure
	struct twodhdr thdr;				// 2D field common stuff
//	RECT cropRect;						// cropping rectangle 
	struct mfhandlelink *mfchain;	// root of metafile handle chain
	CRrChart* pCRrChart;
} RRCHART;

typedef RRCHART *LPRRCHART;

// Should m_pSubList be ChartListItem* instead of ChartList* ?
// Should we build a sublist under ChartList and then attach it
//  to ChartListItem when we create that?

class ChartListItem : public CObject
{
public:
					ChartListItem( void );
private:
	ChartListItem*	m_pLink;	// link to next of these structures
	ChartListItem*	m_pEnd;		// link to last of these structures
	ChartListItem*	m_pSubList;	// pointer to linked list of next-deeper names/values
	int				m_BreakLevel;		// group level corresponding to this value
	int				m_LastBreakLevel;	// group level of most recently occuring break
	double			m_Value;	// value of this item
	double			m_Sum;		// sum for computing average, std dev, var
	double			m_Square;	// square for computing variance, std deviation
	unsigned long	m_Count;	// count for computing average
	union	// label for this item
	{
		LPTSTR		m_pLabel;	// pointer to buffer containing label
		double		m_dLabel;	// place for numeric or time label
		long		m_zdLabel;	// place for date label
		ZDATETIME	m_zdtLabel;	// place for date-time label
		int			m_lLabel;	// place for logical label
	}; 
	union	// sort field value for this item
	{
		LPTSTR		m_pSValue;		// string
		double		m_dSValue;		// numeric or time
		long		m_zdSValue;		// date
		ZDATETIME	m_zdtSValue;	// date-time
		int			m_lSValue;		// logical
	}; 

	// public member functions
public:
	void			DeleteContents( DATATYPE LabelType, DATATYPE SortType,
									DATATYPE Label2Type, DATATYPE Sort2Type, BOOL bSimple );	// Clean up entire item list
	void			DeleteContents( DATATYPE Label2Type, DATATYPE Sort2Type, BOOL bSimple );	// Clean up sublist
	void			Append( ChartListItem* pItem );		// Add an item to this list of items
	void			SetEnd( ChartListItem* pItem );		// Set pointer to end of list
	void			SetNext( ChartListItem* pItem );	// Set "link" to specified item.
	void			SetSubList( ChartListItem* pItem );	// Set pointer to sublist for this ChartListItem
	BOOL			SetValue( double Value );			// Set this item's value (must be numeric)
	BOOL			SetBreakLevel( int BreakLevel );	// Remember break level for this item
	BOOL			SetCount( long Value );
	BOOL			SetSum( double Value );
	BOOL			SetSquare( double Value );
	BOOL			SetLabel( LPCTSTR pLabel );			// Set this item's label 
	BOOL			SetLabel( double Label );
	BOOL			SetLabel( long Label );
	BOOL			SetLabel( ZDATETIME Label );
	BOOL			SetLabel( int Label );
	BOOL			SetSortValue( LPCTSTR pSortValue );	// Set this item's sort value
	BOOL			SetSortValue( double SortValue );
	BOOL			SetSortValue( long SortValue );
	BOOL			SetSortValue( ZDATETIME SortValue );
	BOOL			SetSortValue( int SortValue );
	BOOL			SetLastBreakLevel( int BreakLevel );
	ChartListItem*	Next( void );
	int				SubListItemCount( void );
	ChartListItem*	GetSubList( void );
	double			GetValue( void );
	int				GetBreakLevel( void );
	long			GetCount( void );
	double			GetSum( void );
	double			GetSquare( void );
	LPTSTR			GetLabel( DATATYPE Type, ChartList* pList, FLDID ID );
	BOOL			GetSortValue( LPTSTR* pValue );
	BOOL			GetSortValue( double* pValue );
	BOOL			GetSortValue( long* pValue );
	BOOL			GetSortValue( ZDATETIME* pValue );
	BOOL			GetSortValue( int* pValue );
	int				GetLastBreakLevel( void );
};

typedef int (*COMP_ROUTINE)( void*, void*, BOOL );

typedef struct Arrays
{
	DATATYPE		tType;		// data type for selecting from following union
	union						// sort values (of various data types)
	{
		LPTSTR*		pStrings;	// string
		double*		pNumbers;	// numeric or time
		long*		pDates;		// date
		ZDATETIME*	pDateTimes;	// datetime
		int*		pLogicals;	// logical
	};
	void**			ppSortz;	// pointers to sort values (in one of arrays in union)
	COMP_ROUTINE	pSortFunc;	// routine to use for sorting (corresponds to tType)
	LPTSTR*			pLabels;	// labels
	double*			pValues;	// values
	long*			pCounts;	// counts (for computing avg, stdev, var)
	double*			pSums;		// sums (for computing avg, stdev, var)
	double*			pSquares;	// sum of squares (for computing stdev, var)
	int				Count;		// number of elements in each array
	TOTALTYPE		tTotalType;	// total type of values
	struct Arrays**	ppArrays;	// array of pointers to sublist arrays, if any
} ARRAYS;

class ChartList : public CObject
{
	DECLARE_DYNAMIC( ChartList );
			ChartList( CRrChart* pChart, CRrComposite* pCompos );	// constructor
			//ChartList( const ChartList& src );							// copy constructor (not implemented)
			ChartList( const ChartList& src, CRrChart* pChart );	// special "copy" constructor
	void	operator=( const ChartList& src );						// assignment operator
private:
	ChartList*		m_pLink;			// link to next of these structures
	ChartList*		m_pEnd;				// link to last of these structures
	ChartListItem*	m_pFirstItem;		// pointer to first ChartListItem
	ChartListItem*	m_pSubList;			// pointer to temporary linked list of next-deeper names/values
	ChartListItem*	m_pNextGroupItem;	// pointer to first item of next section of item list (charts in headers, only)
	CRrChart*		m_pChart;			// CRrChart object we're part of
public:
	CRrComposite*	m_pComposite;		// pointer to CRrComposite we're part of
private:
	DATATYPE		m_LabelDataType;	// data type of labels in ChartListItems
	DATATYPE		m_SortDataType;		// data type of sort values in ChartListItems
	FLDID			m_ValueFieldID;		// field ID of field for values
	FLDID			m_LabelFieldID;		// field ID of field for labels
	FLDID			m_SortFieldID;		// field ID of field by which to sort values
	BOOL			m_bAscending;		// sort ascending if true
	// following only apply to stacked bars, e.g., order total within customer total
	//  where primary values, labels, sorts are customer-related, secondary are order-related
	DATATYPE		m_Label2DataType;	// secondary label data type - stacked bars
	DATATYPE		m_Sort2DataType;	// secondary sort data type - stacked bars
	FLDID			m_Value2FieldID;	// field ID of field for secondary values
	FLDID			m_Label2FieldID;	// field ID of field for secondary labels
	FLDID			m_Sort2FieldID;		// field ID of field for secondary sorts
	BOOL			m_bAscending2;		// sort ascending if true

	// No serialization necessary for stuff below here:
	int				m_ValueGroupLevel;	// group level of m_ValueFieldID field
	ARRAYS			m_Arrays;			// arrays of values, labels, etc.

public:
	void		Serialize( CArchive& arChartArchive );
	int			ComputeFieldGroupLevel( MFFIELD* pFld );
	void		SetValueGroupLevel( int MaxGroupLevel );
	CHARTERR	PrepareForPrinting( void );
	void		DeleteContents( BOOL bSimple );		// Clean up entire ChartList
	void		DeleteItemList( void );
	void		Append( ChartList* pList );			// Add to end of list of lists
	void		SetNext( ChartList* pList );		// Set "link" to specified list.
	BOOL		AddToItemList( FLDID ID, int BreakLevel );			// Add to item list
	int			ItemCount( int BreakLevel );
	void		SortLists( ARRAYS* pArrays );
	BOOL		CombineValues( ARRAYS* pArrays, DATATYPE SortDataType, int LevelDelta, BOOL bSubList );
	BOOL		AllocateArrays( ARRAYS* pArrays, DATATYPE SortDataType );
	void		DeAllocateArrays( ARRAYS* pArrays, BOOL bComplete );
	BOOL		PopulateArrays( ARRAYS* pArrays, ChartListItem* pChartListItem,
						DATATYPE LabelDataType, BOOL bSubList );
	double		MakeValue( FLDID ID );
	LPTSTR		MakeLabel( FLDID ID );
	BOOL		InList( ARRAYS* pArrays, void* pSortVal );
	BOOL		SameSortValues( ARRAYS* pArrays1, ARRAYS* pArrays2 );
	BOOL		MakeArrays( int* pPointCount, int* pSetCount, double** ppValues,
						LPTSTR** ppPointLabels, LPTSTR** ppSetLabels );
	void		SetEnd( ChartList* pList );
	void		SetFirstItem( ChartListItem* pItem );
	ChartList*	Next( void );				// Return m_pLink.
	BOOL		IsListValue( FLDID ID );	// See if field is ValueFieldID or Value2FieldID.
	BOOL		IsListLabel( FLDID ID );	// See if field is LabelFieldID or Label2FieldID.
	BOOL		IsListSort( FLDID ID );		// See if field is SortFieldID  or Sort2FieldID.
	BOOL		IsListAny( FLDID ID );		// See if field is used in any way in this list.
	FLDID		FindNewID( FLDID OldID );
	BOOL		UpdateListFieldID( FLDID* pFieldID );
	BOOL		UpdateListFieldIDs( void );
	BOOL		UpdateListFieldIDs( FLDID OldID, FLDID NewID );
	BOOL		UpdateFieldIDForDeletedField( FLDID DeletedID, FLDID* pFieldID );
	BOOL		UpdateListForDeletedField( FLDID ID );
	void		SetNeeded( void );
	void		SetValueFieldID( FLDID ID );
	void		SetLabelFieldID( FLDID ID, BOOL bSetType = TRUE );
	void		SetSortFieldID( FLDID ID, BOOL bSetType = TRUE );
	void		SetSortAscending( BOOL bAsc );
	void		SetValue2FieldID( FLDID ID );
	void		SetLabel2FieldID( FLDID ID, BOOL bSetType = TRUE );
	void		SetSort2FieldID( FLDID ID, BOOL bSetType = TRUE );
	void		SetSort2Ascending( BOOL bAsc );
	FLDID		GetValueFieldID( void );
	FLDID		GetLabelFieldID( void );
	FLDID		GetSortFieldID( void );
	BOOL		GetSortAscending( void );
	FLDID		GetValue2FieldID( void );
	FLDID		GetLabel2FieldID( void );
	FLDID		GetSort2FieldID( void );
	BOOL		GetSort2Ascending( void );
	int			GetValueGroupLevel( void );
};

class CRrChart : public CObject
{
	DECLARE_DYNAMIC( CRrChart );
public:
				CRrChart( CRrComposite* pCompos );		// constructor
				CRrChart( const CRrChart& src );		// copy constructor
	virtual		~CRrChart( void );						// destructor
	void		operator=( const CRrChart& src );		// assignment operator

	// data members
private:
	ChartList*		m_pChartList;		// pointer to first ChartList structure
	CRrComposite*	m_pComposite;
	int				m_GroupLevel;		// group level at which chart prints
	int				m_Band;				// band in which chart anchor resides (when array index?)
	ANCHOR			m_Anchor;			// enum value indicating anchor-top or anchor-bottom

		// data related to "Graphics Server" 
	CString			m_strTitle;			// chart title
	CString			m_strXAxis;			// x-axis label
	CString			m_strYAxis;			// y-axis label
	CString			m_strZAxis;			// z-axis label
	CString			m_strFont;			// base font name
	CString			m_strTitleFont;		// title font name
	CString			m_strAxisFont;		// axis font name
	CString			m_strLabelFont;		// label font name
	CString			m_strLegendFont;	// legend font name
	BOOL			m_bLegend;			// show legend?
	BOOL			m_bXGrid;			// show x-axis grid lines?
	BOOL			m_bYGrid;			// show x-axis grid lines?
	BOOL			m_bHorizontal;		// horizontal bars? (bar charts only)
	int				m_Palette;			// palette ID
	eGSWChartType	m_Type;				// chart type ID (bar, line, area, etc.)
	eChartStyle		m_Style;			// chart style ID (simple, stacked, etc.)
	ePieStyle		m_PieStyle;			// pie chart specific styles (no labels,no lines, color labels, percent labels)
	int				m_AttrTitle;		// text attributes for title (bold, italic, underlined)
	int				m_AttrXAxis;		// ... for x-axis text
	int				m_AttrYAxis;		// ... for y-axis text
	int				m_AttrZAxis;		// ... for z-axis text
	int				m_AttrLegend;		// ... for legend text
	int				m_AttrLabels;		// ... for data labels
	int				m_SizeTitle;		// percentage of system font size for title (100=system font size)
	int				m_SizeXAxis;		// ... for x-axis text
	int				m_SizeYAxis;		// ... for y-axis text
	int				m_SizeZAxis;		// ... for z-axis text
	int				m_SizeLegend;		// ... for legend text
	int				m_SizeLabels;		// ... for data labels
	BOOL			m_bCombineDups;		// combine values with duplicate "sort field" values?
	BOOL			m_bCombineSubDups;	// combine values with duplicate "sort field" values in sub-category?
	BOOL			m_bDataLabels;		// show numeric data labels?
	double			m_Min;				// lower amplitude limit
	double			m_Max;				// upper amplitude limit
	eRangeType		m_eRangeType;		// enumeration value of ranget type: Automatic, Normalized, User-defined
	int				m_RotYTitle;		// rotation of y-axis title: 0->none, AGTTLUP->bottom-to-top, AGTTLDOWN->top-to-bottom

public:
	// PAR. A temporary string is need by HTML export.  The current export code must insert this 
	// pathname into the output text stream before the metafile is actually converted to 
	// a real bitmap.  This variable does not need to be copied in the assignment operator 
	// and it does not need to be serialized.
	CString			m_csTempNextPathname ;

public:
	// member functions
		// interesting functions
	void		Serialize( CArchive& arChartArchive );
	CHARTERR	PrepareForPrinting( RRCHART* pChart );
//	CHARTERR	PrepareForPrinting( void );
	int			FindIndex( void );
	ChartList*	AddList( void );		// for use by serialization only!!
	ChartList*	AddList( FLDID LabelID, FLDID ValueID, FLDID SortID, BOOL bAsc = TRUE,
						 FLDID Label2ID = NOID, FLDID Value2ID = NOID, FLDID Sort2ID = NOID, BOOL bAsc2 = TRUE );	// Add a ChartList (i.e., something to chart).
	ChartList*	GetListPointer( int Index );
	BOOL		InChart( FLDID ID );						// "Is field 'ID' used in this chart?"
	BOOL		InChartAsValue( FLDID ID );
	BOOL		InChartAsLabel( FLDID ID );
	BOOL		InChartAsSort( FLDID ID );
	int			ComputeBreakLevel( void );
	BOOL		AddToItemLists( FLDID ID );					// Add field value to appropriate ChartItemLists
	int			ItemCount( int ListIndex );
	int			ListCount( void );
	BOOL		GetArrays( int ListIndex, int* pPointCount, int* pSetCount, double** ppValues,
						LPTSTR** ppPointLabels, LPTSTR** ppSetLabels );
	BOOL		MakeArrays( int* pPointCount, int* pSetCount, double** ppValues,
						LPTSTR** ppPointLabels, LPTSTR** ppSetLabels );
	BOOL		CleanUpArrays( int PointCount, int SetLabelCount, double* pValues,
						LPTSTR* pPointLabels, LPTSTR* pSetLabels );
	BOOL		ClearItemList( int ListIndex );
	void		ClearAllItemLists( void );
	void		DeleteLists( void );
	BOOL		DeleteList( ChartList* pList );
	BOOL		UpdateChartFieldIDs( void );
	BOOL		UpdateChartFieldIDs( FLDID OldID, FLDID NewID );
	BOOL		UpdateChartForDeletedField( FLDID ID );
	BOOL		UpdateChartsForDeletedField( FLDID ID );
	void		SetNeeded( void );
private:
	ChartList*	FirstListUsingAsValue( FLDID ID );
	ChartList*	NextListUsingAsValue( FLDID ID, ChartList* pPrevList );
public:
		// boring set functions
	BOOL		SetBand( int Band );
	BOOL		SetGroupLevel( int Level );
	BOOL		SetAnchor( ANCHOR Anch );
	BOOL		SetType( eGSWChartType Type );
	BOOL		SetStyle( eChartStyle Style );
	BOOL		SetPieStyle( ePieStyle Style );
	BOOL		SetText( LPCTSTR pTitle = NULL, LPCTSTR pXAxis = NULL, LPCTSTR pYAxis = NULL, LPCTSTR pZAxis = NULL, int RotYTitle = 0 );
	BOOL		SetFont( LPCTSTR pBaseFont = NULL, LPCTSTR pTitleFont = NULL, LPCTSTR pAxisFont = NULL, LPCTSTR pLabelFont = NULL, LPCTSTR pLegendFont = NULL );
	BOOL		SetFontSize( int iTitleSize = iNormal, int iAxisSize = iNormal, int iLabelSize = iNormal, int iLegendSize = iNormal);
	BOOL		SetOptions( BOOL bLeg = FALSE, BOOL bGridX = FALSE, BOOL bGridY = FALSE,
					 BOOL bHorizontal = FALSE, BOOL bDataLabels = TRUE );
	BOOL		SetPalette( int Pal = PALRAINBOW );
	BOOL		SetAttributes( int AtTitle = 0, int AtX = 0, int AtY = 0, int AtZ = 0, int AtLeg = 0, int AtLab = 0 );
	BOOL		SetSizes( int SzTitle = 100, int SzX = 100, int SzY = 100, int SzZ = 100, int SzLeg = 100, int SzLab = 100 );
	BOOL		SetCombineDups( BOOL bCombine, BOOL bCombineSub = TRUE );
	BOOL		SetLimits( double Min, double Max, eRangeType eType = eAutomatic );
		// boring get functions
	BOOL		GetListInfo( int Index,
					 FLDID* pLabelID,  FLDID* pValueID,  FLDID* pSortID,  BOOL* pbAsc,
					 FLDID* pLabel2ID, FLDID* pValue2ID, FLDID* pSort2ID, BOOL* pbAsc2 );
	BOOL		GetBand( LPINT pBand );
	BOOL		GetGroupLevel( LPINT pLevel );
	BOOL		GetAnchor( ANCHOR* pAnch );
	BOOL		GetType( eGSWChartType* pType );
	BOOL		GetStyle( eChartStyle* pStyle );
	BOOL		GetPieStyle( ePieStyle* pStyle );
	BOOL		GetText( LPTSTR pTitle, LPTSTR pX = NULL, LPTSTR pY = NULL, LPTSTR pZ = NULL, int* pRotYTitle = NULL );
	BOOL		GetFont( LPTSTR pBaseFont, LPTSTR pTitleFont, LPTSTR pAxisFont, LPTSTR pLabelFont, LPTSTR pLegendFont );
	BOOL		GetFontSize(LPINT piTitleSize,LPINT piAxisSize,LPINT piLabelSize,LPINT piLegendSize);
	BOOL		GetOptions( BOOL* pbLeg, BOOL* pbGridX = NULL, BOOL* pbGridY = NULL,
					 BOOL* pbHorizontal = NULL, BOOL* pbDataLabels = NULL );
	BOOL		GetPalette( LPINT pPal );
	BOOL		GetAttributes( LPINT pAtTitle, LPINT pAtX, LPINT pAtY, LPINT pAtZ, LPINT pAtLeg, LPINT pAtLab );
	BOOL		GetSizes( LPINT pSzTitle, LPINT pSzX, LPINT pSzY, LPINT pSzZ, LPINT pSzLeg, LPINT pSzLab );
	BOOL		GetCombineDups( BOOL* pbCombine, BOOL* pbCombineSub = NULL );
	BOOL		GetLimits( double* pMin, double* pMax = NULL, eRangeType* peType = NULL );
	// helper functions
	int			SafeFontSize(int iSize);
};

#endif // end _RRCHART_H_
// *************************** End of File ************************************
