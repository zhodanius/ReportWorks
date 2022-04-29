/*
 */
/*--------------------------------------------------------------------------*/
/*	 Copyright (c) 1996 Wall Data Incorporated.  All Rights Reserved.	 	*/
/*--------------------------------------------------------------------------*/
/* This file contains proprietary trade secrets of Wall Data, Incorporated.	*/
/* No part of this file may be reproduced or transmitted in any form or by	*/
/* any means, electronic or mechanical, including photocopying and			*/
/* recording, for any purpose without the expressed written permission		*/
/* of Wall Data Incorporated.  	   	   	  									*/
/*--------------------------------------------------------------------------*/
/* Purpose:	Definition file for Generating HTML code from ARPEGGIO Reports  */
/*--------------------------------------------------------------------------*/
/* Abstract:                                                                */
/*																			*/
/*--------------------------------------------------------------------------*/


#ifndef _GENREPORTHTML_H_
#define _GENREPORTHTML_H_

#include "genhtml.h"
#include "tblentry.h"

#define EMPTYCOLSPANENTRY	-1
#define RESETCELLPOS    	-1

// sp 11/13/96 moved declaration to product.h
//#define BANDINTABLE(p) (p==INBODY || p==INHEAD|| p==INTITLE || p==INBREAKH || p==INBREAKF || p==INFOOT || p==INSUMMARY)

// sp 10/21/96 added external ref to getColorString and removed GetColorStringFromIndex
extern CString getColorString (int iColorIndex, CString csDefaultColor);

/////////////////////////////////////////////////////////////////////////////
// CGenerateReportHTML command target
class CGenerateReportHTML : public CGenerateHTML
{
	DECLARE_DYNCREATE(CGenerateReportHTML)

	CGenerateReportHTML(BOOL bUseColor=TRUE, LPCTSTR strBackImage=NULL, LPCTSTR strBackColor="WHITE");           // protected constructor used by dynamic creation
//	CGenerateReportHTML(BOOL bUseColor, LPCTSTR strBackImage, LPCTSTR strBackColor);

	virtual ~CGenerateReportHTML();

public:
	
	
// Attributes
public:

// Settings

	BOOL				m_bStripBlankLines;
	BOOL				m_bJavaEnabled;
	BOOL				m_bActiveXEnabled;
	long				m_lCurrentCellPos;

	CObArray			m_tblArray;
	CObArray			m_uniqueCellArray;		// Contains unique field locations, no dups

	BOOL				m_bCanContainTable;	// boolean indicating if this table can contain another table.
	BOOL 				m_bInTable;			// This is set when we do a start table and cleared when we do an end table.

	long				m_lNumberOfFields;
	char			   *m_pColSpanArray;	// This is a pointer to the column span array.  It will contain
	BOOL				m_bUseColor;
	CString				m_strBackImage;
	CString				m_strBackColor;
	CString             m_strImagePathname ;

	// sp 12/02/96 used to save the last cell pos
	long				m_lLastCellPosID;

	// sp 12/04/96 save the last band number
	long				m_lLastBandLineNum;

// Operations
public:

// Band line/report 
	virtual void WriteTitle (LPCTSTR pszTitle, CString * pstrOutput);
	virtual void WriteReportStart (LPCTSTR pszTitle, CString * pstrOutput);
	virtual void WriteReportEnd   (CString * pstrOutput);
	virtual void WriteHTMLStart	(CString * pstrOutput); 
	virtual void WriteHTMLEnd	(CString * pstrOutput);
	virtual void WriteBodyStart	(CString * pstrOutput);
	virtual void WriteBodyEnd	(CString * pstrOutput);
	virtual void WriteTableBoldStart 	(CString * pstrOutput);
	virtual void WriteTableBoldEnd 		(CString * pstrOutput);
	virtual void WriteTableItalicStart 	(CString * pstrOutput);
	virtual void WriteTableItalicEnd 	(CString * pstrOutput);

	// sp 1/2/97 write the striketru tags
	virtual void WriteTableStrikeStart 	(CString * pstrOutput);
	virtual void WriteTableStrikeEnd 		(CString * pstrOutput);

	// sp 11/04/96 write the underline property of a field
	virtual void WriteTableUnderlineStart 	(CString * pstrOutput);
	virtual void WriteTableUnderlineEnd 		(CString * pstrOutput);
	
	virtual void WriteBlankLines		(CString * pstrOutput, UINT numlines);		// smh - for vertical positioning

	// sp 11/06/96 added csFontName as the second parameter
	// sp 11/04/96 remove WriteTableFontColor and WriteTableFontSize and Replaced both with the combination function WriteTableFontData
	virtual void WriteTableFontData (CString * pstrOutput, CString csFontName, CString csColor, int iFontSize);

	// sp 10/25/96 added to write the font color
	//virtual void WriteTableFontSize 	(CString * pstrOutput, int iFontSize);
	// sp 10/15/96 added to write the font color
	//virtual void WriteTableFontColor 	(CString * pstrOutput, CString csColor);
	
	virtual void WriteTableFontEnd 		(CString * pstrOutput);

	virtual void WriteBeginningTag ( UINT iBand, CString * pstrOutput );
	virtual void WriteEndingTag	   ( UINT iBand, CString * pstrOutput );

	virtual void WriteNumberHeadingStart( UINT iHeadNum, CString * pstrOutput );
	virtual void WriteNumberHeadingEnd  ( UINT iHeadNum, CString * pstrOutput );

	virtual void WriteComment ( LPCTSTR pszComment, CString * pstrOutput );

	virtual void SetTableNumberOfFields  ( long   NumberOfFields );
	virtual void GetTableNumberOfFields  ( long *pNumberOfFields );
	virtual long GetTableNumberOfFields  ( );

	virtual void GetTableCanContainTable ( BOOL *pCanContainTable ) ;
	virtual void SetTableCanContainTable ( BOOL CanContainTable );
	
	virtual void WriteTableRowData (CString * pstrOutput);

#if 0	
	virtual void WriteTableCellPosStart (CString * pstrOutput, int  iBandNumber, long  lYPos);
#endif
	virtual void WriteTableCellPosEnd   (CString * pstrOutput, long lPrevCellPos, long lCurrentCellPos);

			void WriteTableStart     	(CString * pstrOutput, CString * pstrAlign=NULL, long lBorder=1);
			void WriteTableRowStart		(CString * pstrOutput, CString * pstrAlign=NULL);
			void WriteTableCellStart 	(CString * pstrOutput, long ColSpan, CString * pstrAlign=NULL);
	 		void WriteTableEnd			(CString * pstrOutput);

			// sp 12/03/96 writes a <TD></TD> line to the html export 
			void WriteTableCellStartEndPair(CString * pstrOutput);
			void WriteImageTag             (CString * pstrOutput, LPCSTR pszImagePathname, LPCSTR pszAlign);

	// sp 1/2/97 removed bUnderlined
	// sp 12/12/96 used the HEX string (csHEXcolor) as the color param instead of the index (iColorIndex)
	// sp 11/06/96 added csFontName as Last parameter
	// sp 11/05/96 added bUnderline as Last parameter
	// sp 10/25/96 added iFontSize
	// sp 10/15/96 added iColorIndex
	virtual void AddTableCell  (long lBandNumber, long lYPos, long lStartingPosition, LPCTSTR pszCellName, long lSize, ULONG uFlags, long lAlign, LPCSTR pszHEXcolor, int iFontSize, LPCSTR pszFontName, LPCSTR pszImagePathname);

	// sp 1/2/97 removed bUnderlined
	// sp 12/12/96 used the HEX string (csHEXcolor) as the color param instead of the index (iColorIndex)
	// sp 11/06/96 added csFontName as Last parameter
	// sp 11/05/96 added bUnderline as Last parameter
	// sp 10/25/96 added iFontSize
	// sp 10/15/96 added iColorIndex
	virtual void AddUniqueCell (long lBandNumber, long lYPos, long lStartingPosition, LPCTSTR pszCellName, long lSize, ULONG uFlags, long lAlign, LPCSTR pszHEXcolor, int iFontSize, LPCSTR pszFontName, LPCSTR pszImagePathname);

	virtual void AddToColSpan  (long lColPos);

	// sp 1/2/97 removed bUnderlined
	// sp 12/12/96 used the HEX string (csHEXcolor) as the color param instead of the index (iColorIndex)
	// sp 11/06/96 added csFontName as Last parameter
	// sp 11/05/96 added bUnderline as Last parameter
	// sp 10/25/96 added iFontSize
	// sp 10/15/96 added iColorIndex
	virtual void SetTableCellPosition (long lBandNumber, long lYPos, long lStartingPosition, LPCTSTR pszCellName, long lSize, ULONG uFlags, long lAlign, LPCSTR pszHEXColor, int iFontSize, LPCSTR pszFontName, LPCSTR pszImagePathname);

	virtual void SetTableColSpan ( );

// sp 2/14/97 only print colspan in debug
#if defined _DEBUG
	virtual void DumpTableColSpan ( CString * pstrOutput ) ;
	virtual void DumpUniqueCells  ( CString * pstrOutput ) ;
#endif

	virtual void SetInTable ( BOOL  bInTable );
	virtual void GetInTable ( BOOL *pInTable );
	virtual BOOL GetInTable ( );
	virtual	void GetColId   (long YPos, int *iColId);
	virtual int  GetColId   (long YPos);
	// sp 12/30/96 instead of being void, return TRUE if found FALSE if not
	// sp 12/10/96 removed recsacross and recwidth from arg list
	virtual BOOL GetTableEntry (long lYPos, int iBandNumber, CTableEntry **pTableEntry);

	virtual void freePDIMemory ();


#if 0
	virtual void WriteTableColSpan (CString *pstrOutput, long lColSpan );
	virtual void SetColSpan (int iColId, long lColSpan);
	virtual void GetColSpan (int iColId, long *lColSpan);
#endif
protected:

	// Host Commands
//	virtual	void WriteReportHeading (CString * pstrOutput);
//	virtual  void WriteReportTitle   (CString  * pstrOutput);

// Output file commands

// Settings Screen
//	virtual void WriteSettingButtons	(CString * pstrOutput);

    
// Screen parsing commands
//	virtual BOOL OneSpecialKeyInField	(CString *strText);


// Member variable accessors

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGenerateReportHTML)
	public:
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGenerateReportHTML)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
#endif

