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
//
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/uprompt.h_v  $
// 
//    Rev 1.9   27 Apr 1998 20:04:30   jpb
// for runtime dll usage
// 
//    Rev 1.8   25 Apr 1998 17:19:40   jpb
// for runtime dll support
// 
//    Rev 1.7   25 Apr 1998 14:09:56   jpb
// change InitUserPromptItems args
// 
//    Rev 1.6   22 Apr 1998 20:37:12   jpb
// IN LIST
// 
//    Rev 1.5   22 Apr 1998 16:39:18   jpb
// BETWEEN
// 
//    Rev 1.4   21 Apr 1998 21:22:26   jpb
// add value count member
// 
//    Rev 1.3   21 Apr 1998 17:18:14   jpb
// ReplaceParameters now returns a BOOL
// 
//    Rev 1.2   20 Apr 1998 15:56:52   jpb
// 
//    Rev 1.1   19 Apr 1998 17:40:38   jpb
// add ReplaceParams method and member for param number
// 
//    Rev 1.0   18 Apr 1998 16:27:20   jpb
// Initial revision.
// 
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _UPROMPT_H_

//
// Make a definition for this module.
//
#define _UPROMPT_H_

#define MAXITEMS	20

#define IDC_BASE	1100

class CUserPromptItem
{
public:
	FLDID			m_fldId;		// field number
	CString			m_strPrompt;	// user prompt text
	CString			m_strDefault;	// default value
	char			m_cType;		// KCHAR, etc
	int				m_iDuplicate;	// 0=>not a dup; else a dup of item (iDuplicate-1)
	int				m_ParamNum;		// index into QueryObject paramlist
	int				m_ValueCount;	// max # of expected values
	LPSTR			m_pValueStorage;// points into tokenized filter storage for vals
};

class CUserPromptTemplate
{
public:
	int 			m_iPromptCount;
	int 			m_iDuplicateCount;
	CRrDoc*			m_pDoc;
	CUserPromptItem	m_PromptItem[MAXITEMS];	// the prompt items

	CUserPromptTemplate(CRrDoc *pDoc);
	BOOL InitUserPromptItems(char *pSelEd, int iSelEdLen);
#if defined (RUNDLL)
	void MakeParameters( CQueryObject *pQObj, RDReport* pRdRep );
	void AddValueLists(CQueryObject* pQObj, RDReport* pRdRep, BOOL bUserSQL);
	void AddSingleValueList(CQueryObject* pQObj, CString sTbl, CString sCol, BOOL ReportFilterParam, FIELDFIELD *pF);
#else
	void MakeParameters( CQueryObject *pQObj );
	void AddValueLists(CQueryObject* pQObj);
	void AddSingleValueList(CQueryObject* pQObj, CString sTbl, CString sCol, BOOL ReportFilterParam, LPMFFIELD pF);
#endif
	BOOL ReplaceParameters(CQueryObject* pQObj);
	void ClearParameterList(CQueryObject* pQObj);
	BOOL ReplaceSingleParameter(CUserPromptItem* pUPItem,int iType,	CString strEdit,LPSTR pValStor,int iStorLen);
};

#endif

