// ChartDat.h : header file
// Copyright (C) 1997 Concentric Data Systems, Inc.  All rights reserved. 
/////////////////////////////////////////////////////////////////////////////
// Module $Workfile:   chartdat.h  $
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
// $Log:   H:/VCSMFC/H/CHARTDAT.H_V  $
// 
//    Rev 1.19   14 Jan 1998 14:57:14   jsf
// PTF20001 merge
// 
//    Rev 1.18.2.0.1.0.1.0   12 Dec 1997 09:43:08   JSF
// yet another fix to WO152082
// 
//    Rev 1.18.2.0.1.0   11 Dec 1997 15:25:50   JSF
// WO152082, WO152084, WO152103
// 
//    Rev 1.18.2.0   05 Nov 1997 14:37:12   jsf
// merge 8.0/2.0 base with charting PTF
// 
//    Rev 1.18.1.0   23 Oct 1997 14:31:54   jsf
// charting PTF 1
// 
//    Rev 1.18   27 Jun 1997 14:11:26   SRM
// remove normalize as an option for the valuerange variable
// 
//    Rev 1.17   17 Jun 1997 13:40:56   jsf
// Fixed WO131419. Chart size was inadvertently changing. 
// The problem only occurred if the horizontal or vertical spacing for 
// the ruler was set to a value other than 10. The calculations used to 
// determine height and width used the values.  The calc's where moved to
// a new function, SetChartSizes(). This function should only be called in the 
// constructor. Multiple calls might result in the failure.
// 
//    Rev 1.16   12 Jun 1997 11:58:58   jsf
// added eRangeType to ChartData
// 
//    Rev 1.15   10 Jun 1997 18:27:36   par
// New Chart pages for High/Low/Close, Scatter and Bubble types.
// 
//    Rev 1.14   09 Jun 1997 17:36:54   jsf
// Added code expand/collapse for the list boxes/combo boxes and other
// misc. changes for controls. The min/max controls now accept negative numbers.
// 
// 
//    Rev 1.13   28 May 1997 11:28:10   par
// Connected the Chart Font dialog to real data.
// 
// 
//    Rev 1.12   27 May 1997 16:32:12   jsf
// changed the anchor enum order
// 
//    Rev 1.11   20 May 1997 12:17:10   jsf
// checkin.txt
// 
//    Rev 1.10   19 May 1997 16:59:58   jsf
// changes to the test data
// 
//    Rev 1.9   19 May 1997 09:48:56   jsf
// checkin.txt
// 
//    Rev 1.8   13 May 1997 16:44:08   jsf
// Moved the bool for horizontal bar to ChartData
// 
//    Rev 1.7   09 May 1997 14:01:38   jsf
// Added code to update the data page with fields 
// from an existing chart
// 
//    Rev 1.6   02 May 1997 15:41:06   jsf
// More support for CChartSheet as a right-click property dialog
// 
//    Rev 1.5   30 Apr 1997 15:03:14   jsf
// Added support for CChartSheet as a right-click property dialog
// 
//
//
// ****************************************************************************
#ifndef __ChartDat_h__
#define __ChartDat_h__

#include "gsw.h"
//2D Bar & Pie
static double adBarPieData[] = {80,60,40,20};
static const int nBarPieData = sizeof(adBarPieData) / sizeof(double);
static const int nBarPieGroupData = 1;
static TCHAR* aszLegend4Data[] = { "North", "South", "East", "West"};

static int anPattern[nBarPieData] = {
	BRSOLID,
	BRSOLID,
	BRSOLID,
	BRSOLID
	};
static int anColor[nBarPieData] = {
	LIGHT + BLUE,
	LIGHT + GREEN,
	LIGHT + CYAN,
	LIGHT + RED
	};

//3D Bar 
static const int nBarStackedData = 4;
static const int nBarStackedGroup = 4;	//gives us four colors, red,blue,green, cyan 
static double adBarStackedData [nBarStackedData] [nBarStackedGroup] = {
	12, 6,  4,  8,
	10, 12, 8,  4,
	30, 25, 5, 15,
	5,  18, 12, 3
	};

// Area & Line
static const int nAreaLineData = 4;
static const int nAreaLineGroupData = 4;
static double adAreaLineData[nAreaLineData] [nAreaLineGroupData] = {
//	L1, L2, L3, L4
	20, 30, 40, 25,
	40, 30, 35,	15,
	50, 60, 55,	45,
	55, 40, 65, 35
	};

//Scatter

/*static double adStaticScatterPoints[14] [2] = {
	3,2,
	7,6,
	5,4,
	9,8,
	7,6,
	11,10,
	9,8,
	13,12,
	11,10,
	15,14,
	13,12,
	17,16,
	15,14,
	19,18
	};
*/
static const int nScatterPoints = 14;
static const int nScatterGroup = 2;
static double adScatterPoints[nScatterPoints][nScatterGroup] = {
	 1,12,
	 2, 6,
	 3, 4,
	 4, 8,
	 5, 6,
	 6,10,
	 7, 8,
	 8,12,
	 9,10,
	10, 4,
	11,12,
	12, 6,
	13,14,
	14,18
	};

//static int nScatterPoints = sizeof(adScatterPoints) / sizeof(double);

//HLC
static double adHLCData[10][4] = {
	14, 15.5, 13.25, 15.25,
	15.25, 15.75, 13.50, 14.25,
	15, 17.0, 13.50, 16.25,
	16.25, 16.25, 14.75, 15.25,
	15.25, 16.75, 12.25, 16.0,
	14, 15.5, 13.25, 15.25,
	15.25, 15.75, 13.50, 15.0,
	15, 17.0, 13.50, 16.25,
	16.25, 16.25, 14.75, 15.25,
	15.25, 16.75, 13.75, 16.0
	};

//bubble
static const int nBubblePoints = 4;
/* one-dimensional array of bubble radii */
static double fAmp [nBubblePoints] = { 100.0, 125.0, 175.0, 105.0 };
/* two-dimensional array of bubble centers */
static double fDist [nBubblePoints] [2] = {
   /* X      Y */ 
				50.0,  100.0,
				200.0, 300.0,
				450.0, 550.0,
				600.0, 200.0
				};
static int nPatt [nBubblePoints] = {   BRSOLID, BRSOLID, BRSOLID, BRSOLID};
static int nClr [nBubblePoints] = { LIGHT + BLUE, LIGHT + GREEN, LIGHT + CYAN	, LIGHT + RED };

static const int nMaxTitle = 100;
static const int nMaxAxisTitle = 50;

	//GSW api choices
	enum eGSWChartType 
		{			// match graphic server defines for AGShow iType
		eNAType,						//0
		ePIE2D=AGPIE2D,					//1
		ePIE3D=AGPIE3D,					//2
		eBAR2D=AGBAR2D,					//3
		eBAR3D=AGBAR3D,					//4
		eLINE=AGLINE,					//6
		eAREA=AGAREA,					//8
		eSCATTER=AGSCATTER,				//9
		eOHLC=AGHLC,					//11
		eBUBBLE=AGBUBBLE,				//12
		eLINE3D=AGTAPE,					//13
		eAREA3D=AGAREA3D				//14
		};

	// Dialog choices
	enum eRRChartType 
	{
		eBar,
		ePie,
		eLine,
		eArea,
		eScatter,
		eOhlc,
		eBubble
	};


enum eChartStyle
		{
		eNAStyle,			//default for pie,bubble,scatter??
		eSimple,			//bar
		eStacked,			//bar,line,area
		eStackedPercent,	//bar,line,area
		eStackedFloating,	//bar
		eAbsolute,			//line,area
		eHLC,				//hi-low-close
		eRROHLC,			//hi-low-close, 
		eOHLCStick,			//hi-low-close
		eHL					//hi-low-close
		};

enum ePieStyle
		{//only effect labels
		ePieNone		=0,
		ePieNoLabel		=AGPIENOLABELS,
		ePieNoLines		=AGPIENOLINES,
		ePieColorLabel  =AGPIESEGCLR,
		ePiePercent		=AGPIEPERCENT | AGPIEPCCHAR,
		ePieNLCL		=AGPIENOLINES | AGPIESEGCLR,
		ePieNLPC		=AGPIENOLINES | AGPIEPERCENT | AGPIEPCCHAR,
		ePieCLPC	    =AGPIESEGCLR  | AGPIEPERCENT | AGPIEPCCHAR,
		ePieAll			=AGPIENOLINES | AGPIESEGCLR  | AGPIEPERCENT | AGPIEPCCHAR,
		//no labels but save the checkbox states
		ePieNoAll		=AGPIENOLABELS| AGPIENOLINES | AGPIESEGCLR  | AGPIEPERCENT | AGPIEPCCHAR,
		ePieNoCLPC	    =AGPIENOLABELS| AGPIESEGCLR  | AGPIEPERCENT | AGPIEPCCHAR,
		ePieNoNLPC		=AGPIENOLABELS| AGPIENOLINES | AGPIEPERCENT | AGPIEPCCHAR,
		ePieNoNLCL		=AGPIENOLABELS| AGPIENOLINES | AGPIESEGCLR,
		ePieNoPercent	=AGPIENOLABELS| AGPIEPERCENT | AGPIEPCCHAR,
		ePieNoColorLabel  =AGPIENOLABELS| AGPIESEGCLR,
		ePieNoLinesLabel  =AGPIENOLABELS| AGPIENOLINES
		};

enum ANCHOR { aTOP, aBOTTOM }; //the order {0,1} maps to the radio buttons on the chart dialog Options page, reordering will break the dialog.

enum eRangeType {eAutomatic, /* eNormalize ,*/ eUserDefined} ;

static TCHAR*	tchFontSize[] = {"Smallest","Smaller","Small","Normal","Large","Larger","Largest"};
static int		aiFontSize[]  = { 25,50,75,100,150,200,300};
static int		iNormal = 3; //if tchFontSize changes, update the index
static int		iLarge  = 4; //if tchFontSize changes, update the index

static int g_nFontStrArraySize = sizeof(tchFontSize) / sizeof(TCHAR*);
static int g_nFontArraySize = sizeof(aiFontSize) / sizeof(int);

/////////////////////////////////////////////////////////////////////////////
// CChartData

class CChartData : public CObject
	{
		DECLARE_DYNAMIC(CChartData)
	// Construction
	public:
		CChartData() ;
		~CChartData();

	// Attributes
	public:
		HENHMETAFILE	m_hEnhMF;
		BOOL			m_bModified;
		BOOL			m_bSkipDrawing;		//prevents drawing when the dialog closes
		BOOL			m_bSizeModified;	//did the client change width/height on options page
		//type page
		eGSWChartType	m_eGSWChartType;	//GSW api 
		eRRChartType	m_eRRChartType;		//UI choices
		BOOL			m_bVerticalGrid;	//vertical lines
		BOOL			m_bHorizontalGrid;	//horizontal lines
		BOOL			m_b3D;
		//style page
		eChartStyle		m_eChartStyle;
		ePieStyle		m_ePieStyle;
		BOOL			m_bBarOrientation;
		BOOL			m_bPieNoLabels;
		BOOL			m_bPieConnectLines;
		BOOL			m_bPieColorLabels;
		BOOL			m_bPiePercentLabels;

		//data page
		int				m_nValueFields;					//count of fields to chart
		CDWordArray		m_dwaValueFieldIDs;				//array of field id's
		DWORD			m_dwLabelFieldID;				//field id for label on x axis
		DWORD			m_dwSortFieldID;				//field id for sort on x axis
		DWORD			m_dwSubFieldID;
		DWORD			m_dwSubLabelID;
		DWORD			m_dwSubSortID;
		BOOL			m_bExistingChart;
		BOOL			m_bAsc;
		BOOL			m_bSubAsc;
		BOOL			m_bCombineDups;
		BOOL			m_bSubCombineDups;

		DWORD			m_dwOhlcOpenFieldID ;
		DWORD			m_dwOhlcHighFieldID ;
		DWORD			m_dwOhlcLowFieldID  ;
		DWORD			m_dwOhlcCloseFieldID;
		DWORD			m_dwOhlcLabelID     ;
		DWORD			m_dwScatterXFieldID ;
		DWORD			m_dwScatterYFieldID ;
		DWORD			m_dwBubbleXFieldID  ;
		DWORD			m_dwBubbleYFieldID  ;
		DWORD			m_dwBubbleDiameterFieldID;
			 			
		//text page
		BOOL	m_bLegend;
		CString	m_csChartTitle;
		CString m_csValueYTitle;
		CString m_csCategoryXTitle;
		CString m_csDepthYRTitle;
		int		m_iRotateYAxis;
		int		m_iRotatePointLabels;
		BOOL	m_bDataLabels;

		//options page
		ANCHOR		m_eAnchor;
		double		m_dOriginalHeight;
		double		m_dOriginalWidth;
		double		m_dNewHeight;
		double		m_dNewWidth;
		int			m_iBGColor;
		double		m_dMinRange;
		double		m_dMaxRange;
		eRangeType	m_eValueRange;

		// font page
		CString m_csFontBase  ;  // Base font for title
		CString m_csFontTitle ;
		CString m_csFontAxis  ;   
		CString m_csFontLabel ;   
		CString m_csFontLegend;  
		int     m_nPalette   ;
		int		m_iLastFont	 ;
		int		m_iTitleSize ;
		int		m_iAxisSize ;
		int		m_iLabelSize ;
		int		m_iLegendSize ;


	// Operations
	public:
		void SetChartType(eGSWChartType e);

		BOOL IsNAType               () const { return (m_eGSWChartType == eNAType ) ; }
		BOOL IsPie2D                () const { return (m_eGSWChartType == ePIE2D  ) ; }
		BOOL IsPie3D                () const { return (m_eGSWChartType == ePIE3D  ) ; }
		BOOL IsBar2D                () const { return (m_eGSWChartType == eBAR2D  ) ; }
		BOOL IsBar3D                () const { return (m_eGSWChartType == eBAR3D  ) ; }
		BOOL IsLine                 () const { return (m_eGSWChartType == eLINE   ) ; }
		BOOL IsArea                 () const { return (m_eGSWChartType == eAREA   ) ; }
		BOOL IsScatter              () const { return (m_eGSWChartType == eSCATTER) ; }
		BOOL IsHLC                  () const { return (m_eGSWChartType == eOHLC   ) ; }
		BOOL IsBubble               () const { return (m_eGSWChartType == eBUBBLE ) ; }
		BOOL IsArea3D               () const { return (m_eGSWChartType == eAREA3D ) ; }

	} ;

#endif // __ChartDat_h__
/////////////////////////////////////////////////////////////////////////////
