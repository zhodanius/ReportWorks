// This class is used to support tables in ARPEGGIO Report Writer.
// This table entry class basically identifies a particular cell
//  of an HTML table.

#define EMPTYTABLEENTRY	-1

#define BOLD		0x0001
#define ITALIC		0x0002
// sp 1/2/97 add strike tru 
#define STRIKE		0x0004
#define UNDER		0x0008
#define WORDWRAP	0x0010
#define ALLOWANGLE  0x0020

#define ALIGNLEFT		1
#define ALIGNCENTER	2
#define ALIGNRIGHT	3


class CTableEntry : public CObject
{
	DECLARE_DYNCREATE(CTableEntry)

	CTableEntry ();
	
	// sp 1/2/96 removed bUnderlined
	// sp 12/12/96 used the HEX string (csHEXcolor) as the color param instead of the index (iColorIndex)
	// sp 11/06/96 added csFontName as Last parameter
	// sp 11/05/96 added bUnderline as Last parameter
	// sp 10/15/96 added additional ColorIndex for font color
	// sp 10/25/96 added iFontSize as Last parameter
	CTableEntry (long lBandLineNumber, long lYPos, long lStartingPosition, LPCTSTR pszCellName,  long lSize, ULONG flags, long lAlign, CString csHEXColor, int iFontSize, LPCTSTR pszFontName, LPCTSTR pszImagePathname=NULL); 
	virtual ~CTableEntry();

public:
	virtual void SetStartingPosition ( long lStartPos );
	virtual long GetStartingPosition ();
	virtual void GetStartingPosition ( long *lStartPos );
	
	virtual void SetBandLineNumber ( long lBandNumber );
	virtual long GetBandLineNumber ();
	virtual void GetBandLineNumber ( long *lBandNumber );

	virtual void SetYPos ( long lYPos );
	virtual long GetYPos ();
	virtual void GetYPos ( long *lYPos );

	virtual void SetName ( LPCTSTR pszName );
	virtual CString GetName ();
	virtual void GetName  ( CString *pstrName );

	virtual void SetWidth ( long lWidth  );
	virtual long GetWidth  ();
	virtual void GetWidth  ( long *lWidth  );

	virtual void SetColSpan( long lColSpan );
	virtual long GetColSpan();
	virtual void GetColSpan( long *lColSpan );

	virtual void SetPrevCols ( long lCols );
	virtual long GetPrevCols ();
	virtual void GetPrevCols ( long *lCols );

	virtual void  SetPDIString ( LPSTR pPDIString, long lSize );
	virtual void  GetPDIString ( LPSTR *PDIString, long *lSize);

	virtual ULONG GetFlags  ();
	virtual void  SetFlags  (ULONG lFlags);
	virtual void  SetAngelBrackets(BOOL bAllowAngleBrackets) ;
	virtual BOOL  AllowAngelBrackets() ;

	// sp 3/13/97 set and get whether or not this is an image field
	virtual BOOL GetIsImage  ();
	// sp 3/13/97 set the image location
	virtual void SetImagePath  (CString csImagePath);
	virtual CString GetImagePath  ();

	// sp 10/25/96 functions set and get the font size for an entry
	virtual void SetFontSize   (int iFontSize);
	virtual void GetFontSize   (int *iFontSize);
	virtual int GetFontSize   ();

	// sp 10/25/96 this function convert the stored size to a valid HTML font size
	virtual int ConvertToHtmlSize   (int iFontSize);

	virtual void SetColor   (COLORREF lColor);
	virtual void GetHEXColor   (CString *csColor);
	virtual CString GetHEXColor	();

	// sp 1/2/97 added to save the strike tru property
	virtual void SetStrike   ( BOOL bStrike   );
	virtual void GetStrike   ( BOOL *bStrike );
	virtual BOOL GetStrike   ();

	// sp 11/04/96 added to save the underline property
	virtual void SetUnderline   ( BOOL bUnderlined   );
	virtual void GetUnderline   ( BOOL *bUnderlined );
	virtual BOOL GetUnderline   ();

	// sp 11/06/96 set and get the font name
	virtual void SetFontName   (CString csFontName);
	virtual void GetFontName   (CString *csFontName);
	virtual CString GetFontName   ();

	virtual void SetBold   ( BOOL bBold   );
	virtual void GetBold   ( BOOL *bWidth );
	virtual BOOL GetBold   ();
	virtual void CheckBold ( BOOL bBold   );

	virtual void SetItalic   ( BOOL bItalic  );
	virtual void GetItalic   ( BOOL *bItalic );
	virtual BOOL GetItalic   ();
	virtual void CheckItalic ( BOOL bItalic  );

	virtual void SetWordWrap   ( BOOL bWordWrap  );
	virtual void GetWordWrap   ( BOOL *bWordWrap );
	virtual BOOL GetWordWrap   ();
	virtual void CheckWordWrap ( BOOL bWordWrap ) ;

	virtual void 	WriteData	( LPSTR pData );
	virtual void 	GetData		( CString *pcsData);
	virtual CString GetData 	();

	virtual void ResetData 		();
	virtual BOOL IsData();

	virtual void SetAlign ( long lAlignment  );
	virtual void GetAlign ( long *plAlignment );
	virtual long GetAlign ();
	virtual void FreePDIString ();


protected:
	long  	m_lBandLineNumber; // This tells us what band line (number) this cell is from
	long  	m_lYPos;				// This is the Y Pos that identifies the entry
	long		m_lStartingPos;	// Starting pixel pos of the entry
	long		m_lSize;				// Size of the table entry
	ULONG		m_ulFlags;			// For now, I dont have any flags but I may in the future.
	CString 	m_strFieldName;	// The field name of the entry.
	long		m_lColSpan;
	long 		m_lPreviousCols;	// The number of columns prior to this cell.
	LPSTR		m_pPDIString;	// This the PDI that makes up the data for the table entry.
	long		m_lPDISize;
	ULONG		m_flags;				// Contains info about the object entry
	long		m_lAlign;
	CString		m_csData;				// This is the data for this entry.

	// sp 10/25/96 new var for storing the color of the field
	int	m_iFontSize;

	// sp 12/12/96 relaced m_RGBcolor with m_csHEXcolor that holds the HEX color
	// sp 10/15/96 new var for storing the color of the field
	CString	m_csHEXcolor;

	// sp 11/06/96 saves the font name of the entry
	CString m_csFontName;

	// sp 3/13/97 save image location for the export
	CString m_csImagePath;

public:
	virtual void Serialize(CArchive& ar);
#ifdef _DEBUG
	virtual void Dump (CDumpContext& dc) const;
#endif
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTableEntry)
	//}}AFX_MSG
};




