/* $Header:   H:/vcsmfc/h/qryobj.h_v   1.13.1.2   25 Nov 1998 11:15:54   jpb  $ */
/* $Log:   H:/vcsmfc/h/qryobj.h_v  $
// 
//    Rev 1.13.1.2   25 Nov 1998 11:15:54   jpb
// supress duplicate prompts (WO161189)
// 
//    Rev 1.13.1.1   21 Sep 1998 15:22:58   smh
// Changed InitParamsDll declaration.
// 
//    Rev 1.13.1.0   21 Sep 1998 14:56:32   smh
// Prototype for InitParamsDll.
// 
//    Rev 1.13   29 Jun 1998 16:55:36   jpb
// fix memory leak on CParameter object
// 
//    Rev 1.12   06 Jun 1998 15:24:08   jpb
// help filename
// 
//    Rev 1.11   19 May 1998 17:51:12   jpb
// for date prompt values
// 
//    Rev 1.10   14 May 1998 13:52:44   jpb
// add constructor for quote char and method for removing from string
// 
//    Rev 1.9   11 May 1998 13:01:24   jpb
// string resource IDs
// 
//    Rev 1.8   08 May 1998 20:27:56   jpb
// 
//    Rev 1.7   07 May 1998 16:49:04   jpb
// add setParameterType
// 
//    Rev 1.6   29 Apr 1998 18:59:00   jpb
// get ready for RI_VALUESTR
// 
//    Rev 1.5   28 Apr 1998 21:34:08   jpb
// param string changes
// 
//    Rev 1.4   27 Apr 1998 20:04:14   jpb
// for runtime dll calls
// 
//    Rev 1.3   21 Apr 1998 21:22:54   jpb
// add Edit2 method
// 
//    Rev 1.2   20 Apr 1998 15:57:18   jpb
// 
//    Rev 1.1   19 Apr 1998 17:38:12   jpb
// add CParameter method to get edited value
// 
//    Rev 1.0   18 Apr 1998 16:26:20   jpb
// Initial revision.
 * 
 *    Rev 1.0   11 Dec 1997 11:33:16   shenders
 * Initial revision.
 * 
 *    Rev 3.4.1.1   13 Jun 1997 13:31:08   BUILD
 * Moved Floating Label
 * 
 *    Rev 3.4.1.0.4.0   29 May 1997 10:45:06   ANICHOLE
 * 
 *    Rev 3.4.1.0.3.0   22 Apr 1997 13:24:48   ywang
 * wo129132: add duplicated tables to qrybld
 * qryobj.h -> Q:\ARCHIVE\DBA\SHARED\INCLUDE\QRYOBJ.H_V
 * Enter description of changes made.
 * 
 *    Rev 3.4.1.0.2.0   19 Apr 1997 14:36:00   ywang
 * wo129132: add dup tables to qrybld
 * qryobj.h -> Q:\ARCHIVE\DBA\SHARED\INCLUDE\QRYOBJ.H_V
 * Enter description of changes made.
 * 
 *    Rev 3.4.1.0   12 Nov 1996 12:18:28   BUILD
 * Starting Rev 4.0 after U02 release.
 * 
 *    Rev 3.4   16 Sep 1996 17:23:06   ywang
 * CleanUp memory
 * 
 *    Rev 3.3   19 Aug 1996 13:51:42   ywang
 * Change Dropdown list font for CQueryParameter class
 * 
 *    Rev 3.2   12 Jul 1996 15:41:34   ywang
 * 
 *    Rev 3.1   10 Jun 1996 09:39:48   ywang
 * 
 *    Rev 3.0   23 May 1996 22:45:00   BUILD
 * Starting Rev 3.0 after U01 release.
 * 
 *    Rev 3.0.1.0   22 May 1996 13:36:18   BUILD
 * No change.
 * 
 *    Rev 3.0   22 May 1996 13:36:16   BUILD
 * Starting Rev 3.0 after U01 release.
 * 
 *    Rev 2.3   01 May 1996 17:22:08   ywang
 * 
 *    Rev 2.2   30 Apr 1996 17:56:08   ywang
 * 
 *    Rev 2.1   22 Apr 1996 16:35:26   ywang
 * 
 *    Rev 1.23   04 Mar 1996 11:26:46   ANICHOLE
 * 
 *    Rev 1.22   02 Mar 1996 23:18:32   ANICHOLE
 * 
 *    Rev 1.21   02 Mar 1996 11:26:52   ANICHOLE
 * Added #include ..\\..\\dbalib\\include\\dialodid.h
 * 
 *    Rev 1.20   27 Feb 1996 13:26:44   ywang
 * 
 *    Rev 1.19   07 Feb 1996 16:50:32   ywang
 * 
 *    Rev 1.18   10 Jan 1996 11:53:56   ywang
 * 
 *    Rev 1.17   01 Dec 1995 09:04:04   JPruitt
 * ADDED VERSION SERIALIZATION
 * 
 *    Rev 1.16   15 Nov 1995 08:27:58   ywang
 * 
 *    Rev 1.15   02 Nov 1995 17:39:10   ywang
 * 
 *    Rev 1.14   01 Nov 1995 18:22:28   ANICHOLE
 * 
 *    Rev 1.13   31 Oct 1995 09:32:00   ywang
 * Change column index to column name in the CRelation class
 * 
 *    Rev 1.12   30 Oct 1995 09:13:10   ywang
 * change column width to 128
 * 
 *    Rev 1.11   10 Oct 1995 18:04:28   ywang
 * 
 *    Rev 1.10   25 Sep 1995 16:46:54   ywang
 * 
 *    Rev 1.9   19 Sep 1995 10:19:40   ywang
 * Add in Version String
 * Add in HAVING Clause to SQL Stmt
 * Change Relation Table Index to Table Name
 * 
 *    Rev 1.8   05 Sep 1995 09:57:20   ywang
 * 
 *    Rev 1.7   31 Aug 1995 09:13:56   ywang
 * 
 *    Rev 1.6   30 Aug 1995 09:53:32   ywang
 * 
 *    Rev 1.5   10 Aug 1995 17:20:14   ywang
 * 
 *    Rev 1.4   09 Aug 1995 16:21:08   ywang
 * dir
 * 
 *    Rev 1.3   07 Aug 1995 17:23:28   ywang
 * 
 */

#ifndef QRYOBJ_H
#define QRYOBJ_H

#define EXPORT_API
#include "sqltypes.h"
#define IDD_QUERYPARAMETER              5101
#define IDS_BTWN				10001
#define IDS_NOTBTWN				10002
#define IDS_INLIST				10003
#define IDS_NOTINLIST			10004
#define IDS_LIKE				10005
#define IDS_NOTLIKE				10006

// CONSTANT
//#define DATALEN 254

#define DEFAULT    0
#define EXPRESSION 1
//#define DEFAULT    0
#define SIMPLE		0
#define BETWEEN		1
#define LIKEOP		2
#define INLIST		3

#define EDITWIDTH		150
#define EDITHEIGHT		18
#define CONTROLOFFSET	10

#define TABLEVIEW		0
#define WORKSTATIONVIEW	1

#define CRITERIA_GRID_MODE		0
#define CRITERIA_BUILDER_MODE	1

// WDDateFunc
#define LASTXDAY		0
#define FIRSTQUARTER	1
#define SECONDQUARTER	2
#define THIRDQUARTER	3
#define FOURTHQUARTER	4

#define QUERYGRIDMAXCOL	   208

// Resource ID
#define STARTCTRLID						1000

//#include "database
#include "baseprop.h"
//#include "..\\..\\dbalib\\include\\dialogid.h"

//#include <objvers.h>

typedef CObList FAR *LPCObList;
typedef CObArray FAR *LPCObArray;
typedef CStringArray FAR *LPCStringArray;
typedef CStringList FAR *LPCStringList;
 
class CTable ;
class CColumn ;
class CRelation ;
class CAggreg ;
class CWhere ;
class CHave ;
class COrderBy ;
class CDataDict ;
class CQueryObject ;
class CColumnInfo;
class CParameter;

typedef CQueryObject FAR *LPCQueryObject;

void __declspec( dllexport ) InitParamsDll() ;

#if 0
class CQueryObject : public CObject
#else
class AFX_EXT_CLASS CQueryObject : public CObject
#endif
{
/*
    DECLARE_SERIAL(CQueryObject)

	CDataDict*	 	m_pDataDict ;

protected:
	CString		 	m_strVersion ;
	LPCWDDatabase 	m_pDatabase ;

	// qrybldvw
	CObArray	 m_TableArray ;
	CObArray	 m_RelationArray ;
	// ordervw
	CStringArray m_DTColumnArray ;
	CStringArray m_DTTableArray ;
	int*		 m_pDTAlias ;
	int			 m_DTAliasSize ;
	CStringArray m_DTShowArray ;
	CStringArray m_DTSortArray ;
	CStringArray m_DTOrderByArray ;
	int          m_DTSortNumber ;
	CStringArray m_DTGroupByArray ;
	CObList      m_DTCriteriaList ;
	BOOL*		 m_pDTExpr ;
	int			 m_DTExprSize ;

	int			 m_CriteriaMode ;
	CString		 m_CriteriaText ;

	// query property
	BOOL		 m_Distinct ;
	BOOL		 m_GroupBy ;

	char		 m_Quote ;
*/
public:

	EXPORT_API CQueryObject() ;
	EXPORT_API CQueryObject(char cQuoteChar,char cDate1, char cDate2, char cDate3, char cDateSep);
	EXPORT_API ~CQueryObject() ;
/*
	void SetDataDict(CDataDict* pDataDict) { m_pDataDict = pDataDict ; } ;
	void SetDatabase(LPCWDDatabase pDatabase) { m_pDatabase = pDatabase ; } ;

	void EXPORT_API SetQuoteChar(const char Quote) ;

	void EXPORT_API SetTableSize(const int Size) ;
	void EXPORT_API SetTable(const int Position, CTable* const pTable) ;
	void EXPORT_API SetRelationSize(const int Size) ;
	void EXPORT_API SetRelation(const int Position, CRelation* const pRelation) ;

	void EXPORT_API AddDTColumn(const CStringArray* pColumnArray) ;
	void EXPORT_API AddDTTable(const CStringArray* pTableArray) ;
	void EXPORT_API AddDTAlias(const int* pAliasArray, const int Size) ;
	void EXPORT_API AddDTShow(const CStringArray* pShowArray) ;
	void EXPORT_API AddDTSort(const CStringArray* pSortArray) ;
	void EXPORT_API AddDTOrderBy(const CStringArray* pOrderByArray) ;
	void EXPORT_API AddDTSortNumber(const int SortNumber) ;
	void EXPORT_API AddDTGroupBy(const CStringArray* pGroupByArray) ;
	void EXPORT_API AddDTCriteria(const CObList* pCriteriaList) ;
	void EXPORT_API AddDTExpr(const BOOL* pExprArray, const int Size) ;

	void EXPORT_API SetQueryProperty(const BOOL Distinct, const BOOL GroupBy) ;
	void EXPORT_API SetCriteriaMode(const int CriteriaMode, const CString& CriteriaText)	;
	
	LPCObArray EXPORT_API GetTableArray() ;
	LPCObArray EXPORT_API GetRelationArray() ;

	LPCStringArray EXPORT_API GetDTColumnArray() ;
	LPCStringArray EXPORT_API GetDTTableArray() ;
	LPINT EXPORT_API GetDTAliasArray() ;
	int EXPORT_API GetDTAliasSize() ;
	LPCStringArray EXPORT_API GetDTShowArray() ;
	LPCStringArray EXPORT_API GetDTSortArray() ;
	LPCStringArray EXPORT_API GetDTOrderByArray() ;
	int EXPORT_API GetDTSortNumber() ;
	LPCStringArray EXPORT_API GetDTGroupByArray() ;
	LPCObList EXPORT_API GetDTCriteriaList() ;
	LPBOOL EXPORT_API GetDTExprArray() ;
	int EXPORT_API GetDTExprSize() ;
	void EXPORT_API GetQueryProperty(BOOL* pDistinct, BOOL* pGroupBy) ;
	void EXPORT_API GetCriteriaMode(int* pCriteriaMode, CString* CriteriaText) ;

	BOOL EXPORT_API GetWSVList(CObList* pTableList) ;
	CString EXPORT_API GetTableNameByCol(const CString& ColumnName) ; // return "LibName.TableName"
	CString EXPORT_API GetTableNames() ;// return "LibName1.TableName1, ... LibName3.TableName3"

	BOOL EXPORT_API IsAggregOrOrderBy() ;
	CString EXPORT_API ParsingForExec() ;
	CString EXPORT_API ParsingForExec(const CObList*) ;
*/

	void EXPORT_API ParsingForExec(const CString*) ;
	BOOL DoesPrompting(const CString*) ;
	BOOL PromptUser(const char *pHelpFile) ;
	CString ReplaceParams(void) ;
	void ClearParamList(void) ;
	int FlagDuplicateParameters(void) ;
	int CheckForOperator(const char* pFowardOpStr, const CString* pReversedTargetStr) ;
	void ClearParameterValueLists(void);
	BOOL InitParameterValueList(const CString strTblName, const CString strColName, const BOOL bRepFilterParam);
	BOOL NextParameterValueList(const CString strTblName, const CString strColName, const BOOL bRepFilterParam);
	void AddParameterValue(const CString strParamStr);
	void AddReportParameter(const int Row, const int Col, const CString& TableName, const CString& ColumnName,
						  const SWORD DataType, const CString& Prompt1, const CString& Prompt2, const int OpType,
						  CDataDict* pDataDict) ;
	void SetParameterType(SWORD swType);
	CString GetPromptString(void);
	int GetPromptStringLength(void);
	BOOL GetPromptStringBuf(char *pBuf, int iBufLen);
	void SetProperties(	LPCTSTR Options );
	long ParseProperties(LPCTSTR szBuf,LPCTSTR szTag,CString &strProp,LPCTSTR lpszSep);
	CString RemoveQuoteChars(CString strIn);
	CString SQLValueString(CParameter *pParameter, LPCTSTR szValue);
	CString DatePart(CString strDateIn);
/*
	CString EXPORT_API FindOp(char** const ptr) ;
	CString EXPORT_API FindPrompt(char** const ptr) ;
	CString EXPORT_API GetSQLStmt() ;
	CString EXPORT_API GetCriteriaStmt() ;
	CTable* FindTable(const CString& TableName, int nAlias) ;
	CString SetQuote(const CString& Source) ;
	int		GetDBType() { return m_pDatabase->nDBMS() ; } ;

	CString ValueRedeem(const CString& Table, const CString& Column, CString Value, const SWORD DataType, BOOL* bResetColumn) ;
	int IsWDDateFunc(const SWORD DataType, const CString& Func) ;

    virtual void EXPORT_API Serialize(CArchive& ar);
	
	EXPORT_API CQueryObject& operator =(const CQueryObject& QueryObject) ;
*/
public:
	CObList		 m_ParameterList ;
	CString		 m_strQuery ;
	const CString* m_pInputSelectString ;
	CParameter*	 m_CurrentParam;
	POSITION	 m_CurrentParamPosition;
	CString		 m_HelpFile;
	char		 m_cQuoteChar;
	char		 m_cDate1;
	char		 m_cDate2;
	char		 m_cDate3;
	char		 m_cDateSep;
/*
protected:
	CObList      m_AggregList ;		  // CAggreg
	CStringList  m_FromList ;
	int			 m_FromAlias[QUERYGRIDMAXCOL] ;
	CObList      m_WhereList ;			  // CWhere
	CObList      m_HaveList ;			  // CHave
	CObArray     m_OrderByArray ;		  // COrder
	CStringList  m_GroupByList ;

	CString BuildQuery(const BOOL bExecFlag) ;
	CTable* GetSingleWSV() ;
	void FromList(const CTable* pWSV = NULL) ;
	void SelectList(BOOL& bStmt, BOOL& bAggreg, CTable* pWSV = NULL) ;
	void GroupByList(BOOL& bAggreg, CTable* pWSV = NULL)	;
	void JoinList(BOOL& bJoin, const CTable* pWSV = NULL) ;
	void WhereList(BOOL bJoin, BOOL bExecFlag, CTable* pWSV = NULL) ;
	void WhereParenthesis() ;
	void UpdateWhereList(const CTable* pWSV, const BOOL bExecFlag) ;
	CString ConCatSQLString(const BOOL bAggreg) ;
	void CleanupTempBuffer() ;
	CString SELECT() ;
	CString AGGREG() ;
	CString FROM() ;
	CString WHERE() ;
	CString ORDERBY() ;
	CString GROUPBY() ;
	CString HAVING() ;
*/

};

/*
class CTable : public CObject
{
    DECLARE_SERIAL(CTable)

public:
	// should be ordered by table name
	CString		m_strVersion ;		 // add in for Version 1.0.1

	CString     m_strOwner ;
	CString     m_strTable ;
	int			m_nAlias ;
	CRect       m_Rect ;
	CObArray    m_ColumnArray ;

	int				m_TableType ;
	CQueryObject*	m_pQueryObject ;

public:		    
	EXPORT_API CTable() ;
	CTable(CString Owner, CString Table, int nAlias) ;
	EXPORT_API CTable(const CTable& CTable) ;
	EXPORT_API CTable(const CString& Owner, const CString& Table, const int nAlias, const CRect& Rect) ;
	EXPORT_API CTable(const CString& Owner, const CString& Table, const int nAlias, const CRect& Rect, const int TableType, const CQueryObject* pQueryObject) ;
	EXPORT_API ~CTable() ;
	void EXPORT_API AddColumn(CColumn* const pColumn) ;
	LPCObArray EXPORT_API GetColumnArray() ;
	CString EXPORT_API GetTableName(BOOL bNoLib = FALSE) ;	// return "LibName.TableName"
	CString GetTblName() ;
	CString GetTableName(const CString& ColumnName) ;
	CString GetTblTitle(BOOL bNoLib = FALSE) ;
	int GetTableType() { return m_TableType ; } ;
	CColumn* FindColumn(const CString& ColumnName) ;
	virtual void EXPORT_API Serialize(CArchive& ar) ;

} ;

class CColumn : public CObject
{
    DECLARE_SERIAL(CColumn)

public:
	// should be ordered by table name
	CString	m_strVersion ;		 // add in for Version 1.0.1

	CString m_strColumnName;		// m_ColumnName
	SWORD  	m_nDataType;			// m_DataType
	int		m_nColumnType ;			// Column or Expression
	CString m_strColUsrName;		// m_ColUsrName

public:		    
	EXPORT_API CColumn() ;
	EXPORT_API CColumn(const CColumn& Column) ;
	EXPORT_API CColumn(const CString& ColumnName, const SWORD DataType, const int ColumnType, const CString& ColUsrName) ;
	EXPORT_API ~CColumn() ;
	CString EXPORT_API GetColumnName() ;
	SWORD EXPORT_API GetDataType() ;
	int EXPORT_API GetColumnType() ;
	CString EXPORT_API GetColUsrName() ;

	virtual void EXPORT_API Serialize(CArchive& ar) ;

} ;


enum { EQUAL, LESS, GREAT, LESSEQUAL, GREATEQUAL } ;

class CRelation : public CObject
{
    DECLARE_SERIAL(CRelation)

public:
	// should be ordered by table name
	CString	 m_strVersion ;		 // add in for Version 1.0.1

	CString  m_TableName1 ;
	CString  m_ColumnName1 ;
	CString  m_TableName2 ;
	CString  m_ColumnName2 ;
	int      m_ID ;


public:		    
	EXPORT_API CRelation() ;
	EXPORT_API CRelation(const CRelation& Relation) ;
	EXPORT_API CRelation(const CString& TableName1, const CString& ColumnName1, const CString& TableName2, const CString& ColumnName2, const int ID = EQUAL) ;
	EXPORT_API ~CRelation() ;
	CString EXPORT_API GetOp(const int ID) ;
	virtual void EXPORT_API Serialize(CArchive& ar) ;

public:
	BOOL EXPORT_API operator == (const CRelation& Relation) const ;
	BOOL EXPORT_API operator <= (const CRelation& Relation) const ;
} ;

class CAggreg : public CObject
{
    DECLARE_SERIAL(CAggreg)

protected:
	CString m_strFunc ;
	CString m_strColumn ;

public:
    EXPORT_API CAggreg() ;
    EXPORT_API CAggreg(const CString& Func, const CString& Column) ;
    EXPORT_API CAggreg(const CString& Column) ;
    EXPORT_API ~CAggreg() ;
	EXPORT_API CString AGGREG() ;

	BOOL IsExist() { return ( !m_strFunc.IsEmpty() && !m_strColumn.IsEmpty() ) ; } ;
    virtual void Serialize(CArchive& ar);
} ;

class CWhere : public CObject
{
    DECLARE_SERIAL(CWhere)

protected:
	INT m_nType ;				// 0: NONE, 1: Value, 2: SubQuery
	CString m_strConnOperator ;	// AND, OR
	CString m_strColumn ;
	CString m_strOperator ;		// <, =, LIKE, BETWEEN, ...
    CString m_strValue ;

public:
	EXPORT_API CWhere() ;
	EXPORT_API CWhere(const int Type, const CString& ConnOp, const CString& Column, const CString& Op, const CString& Value) ;
	EXPORT_API CWhere(const CWhere* pWhere) ;
	EXPORT_API ~CWhere() ;
	CString EXPORT_API WHERE() ;

	void SetValue(CString Value) { m_strValue = Value ; } ;
	CString GetValue() { return m_strValue ; } ;
	void SetConnOp(CString Op) { m_strConnOperator = Op ; } ;
	CString GetConnOp() { return m_strConnOperator ; } ;
	BOOL IsExist() { return m_nType ; } ;
	virtual void Serialize(CArchive& ar) ;
} ;

class CHave : public CObject
{
    DECLARE_SERIAL(CHave)

protected:
	INT m_nType ;				// 0: NONE, 1: Value, 2: SubQuery
	CString m_strConnOperator ;	// AND, OR
	CString m_strColumn ;
	CString m_strOperator ;		// <, =, LIKE, BETWEEN, ...
    CString m_strValue ;

public:
	EXPORT_API CHave() ;
	EXPORT_API CHave(const int Type, const CString& ConnOp, const CString& Column, const CString& Op, const CString& Value) ;
	EXPORT_API ~CHave() ;
	CString EXPORT_API HAVING() ;

	void SetValue(CString& Value) { m_strValue = Value ; } ;
	CString GetValue() { return m_strValue ; } ;
	BOOL IsExist() { return m_nType ; } ;
	virtual void Serialize(CArchive& ar) ;
} ;

class COrderBy : public CObject
{
    DECLARE_SERIAL(COrderBy)

protected:
	CString m_strColumn ;
	CString m_strDescend ;					// Ascending or Descending

public:
	EXPORT_API COrderBy() ;
	EXPORT_API COrderBy(const CString& Column, const CString& Descend) ;
	EXPORT_API ~COrderBy() ;
	CString EXPORT_API ORDERBY() ;

	BOOL IsExist() { return ( !m_strColumn.IsEmpty() ); } ;
	virtual void Serialize(CArchive& ar) ;
} ;
*/
class AFX_EXT_CLASS CParameter : public CObject
{
    DECLARE_SERIAL(CParameter)

public:
	int			m_nRow ;
	int			m_nCol ;
	CString		m_TableName ;
	CString		m_ColumnName ;
	SWORD		m_nDataType ;
	CString		m_strPrompt1 ;
	CString		m_strEdit1 ;
	CString		m_strPrompt2 ;
	CString		m_strEdit2 ;
	int			m_OpType ;
	CDataDict*	m_pDataDict ;
	BOOL		m_bValueArray ;
	CStringArray m_ValueArray;
	CColumnInfo*	m_pColInfo ;
	BOOL		m_ReportFilterParam ; // from report filter or from SQL select?
	int			m_DuplicateIndex;

public:
	EXPORT_API CParameter() ;
//	EXPORT_API CParameter(const BOOL RepFilter, const int Row, const int Col, const CString& TableName, const CString& ColumnName,
//						  const SWORD DataType, const CString& Prompt1, const CString& Prompt2, const int OpType,
//						  CDataDict* pDataDict) ;
	EXPORT_API CParameter(const BOOL RepFilter, const int Row, const int Col, LPCTSTR lpTableName, LPCTSTR lpColumnName,
						  const SWORD DataType, LPCTSTR lpPrompt1, LPCTSTR lpPrompt2, const int OpType,
						  CDataDict* pDataDict) ;
	EXPORT_API CParameter(const BOOL RepFilter, const int Row, const int Col, const CString& TableName, const CString& ColumnName,
						  const SWORD DataType, const CString& Prompt1, const CString& Prompt2, const int OpType,
						  CColumnInfo* const pColInfo) ;
	EXPORT_API ~CParameter() ;
	EXPORT_API CString Edit1() ;
	EXPORT_API CString Edit2() ;
} ;


CString DataTypeConvert(CString Value, const SWORD DataType, int OpType) ;

/////////////////////////////////////////////////////////////////////////////
// CQueryParameter CDialog

class CQueryParameter : public CBaseDialog
{
// Construction
public:
	EXPORT_API CQueryParameter(CWnd* pParent = NULL, CQueryObject* pQueryObject = NULL);

// Dialog Data
	//{{AFX_DATA(CQueryParameter)
	enum { IDD = IDD_QUERYPARAMETER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
public:
	CQueryObject* m_pQueryObject ;
	int		 	  m_CtrlID ;
	CFont		  m_Font ;

public:
	void InitDataDictControls() ;
//	void InitResultSetControls() ;
//	CString DataTypeConvert(CString Value, const SWORD DataType) ;
	void AddWDFunc(CComboBox* pComboBox, SWORD DataType) ;
	void CleanUp() ;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQueryParameter)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQueryParameter)
	virtual void OnCancel();
	virtual void OnOK();
	virtual void OnHelp();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif

