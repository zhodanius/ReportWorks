/*
 $Header:   H:/vcsmfc/h/genhtml.h_v   1.1   08 Oct 1996 16:49:50   amh  $
 */
/*--------------------------------------------------------------------------*/
/*	 Copyright (c) 1994 Wall Data Incorporated.  All Rights Reserved.	 	*/
/*--------------------------------------------------------------------------*/
/* This file contains proprietary trade secrets of Wall Data, Incorporated.	*/
/* No part of this file may be reproduced or transmitted in any form or by	*/
/* any means, electronic or mechanical, including photocopying and			*/
/* recording, for any purpose without the expressed written permission		*/
/* of Wall Data Incorporated.  	   	   	  									*/
/*--------------------------------------------------------------------------*/
/* Purpose:	Definition file for Generating HTML code from Host OCX			*/
/*--------------------------------------------------------------------------*/
/* Abstract:                                                                */
/*																			*/
/*--------------------------------------------------------------------------*/

#ifndef _GENHTML_H_
#define _GENHTML_H_

// These came from HELPERS.H
// MACROS FOR HTML TAGS
#define SZ_SCRIPTNAME	TEXT("<!ScriptName>")
#define SZ_UNIQUEID		TEXT("<!UniqueID>")
#define SZ_SESSIONID	TEXT("<!SessionID>")
#define SZ_HEADER		TEXT("<!Header>")
#define SZ_FOOTER		TEXT("<!Footer>")
#define SZ_RAWSTART		TEXT("<!Raw>")
#define SZ_RAWEND		TEXT("<!/Raw>")


#define FONTSIZERADIO	TEXT("FONTSIZERADIO")
#define TIMEOUTCOMBO	TEXT("TimeOut")


/////////////////////////////////////////////////////////////////////////////
// CGenerateHTML command target
class CGenerateHTML : public CCmdTarget
{
	DECLARE_DYNCREATE(CGenerateHTML)

	CGenerateHTML();           // protected constructor used by dynamic creation
	virtual ~CGenerateHTML();

// Attributes
public:
    long	m_lCurrentOutputLine;
    long	m_lCurrentOffset;

// Setting Holders
	long	m_lFontSize;
	DWORD	m_dwTimeOut;

// Operations
public:

// Output file commands
    virtual BOOL HTMLOutput				(CString * pstrOutput, LPCTSTR String);
    virtual BOOL HTMLOutput				(CString * pstrOutput, _TCHAR ch);
								
	virtual void WriteHeader			(CString * pstrOutput);
	virtual void WriteFooter			(CString * pstrOutput);
    virtual void WriteFormStart			(CString * pstrOutput, CString *strScrID);
    virtual void WriteFormEnd			(CString * pstrOutput);
	virtual void WritePreStart			(CString * pstrOutput);
	virtual void WritePreEnd			(CString * pstrOutput);
	virtual void WriteCenterStart		(CString * pstrOutput);
	virtual void WriteCenterEnd			(CString * pstrOutput);
	virtual void WriteFontSize			(CString * pstrOutput);
	virtual void WriteFontEnd			(CString * pstrOutput);
	virtual void WriteLogoff			(CString * pstrOutput);
    virtual void WriteLogoffFormStart	(CString * pstrOutput, CString *strScrID);
	virtual void WriteSettingBtn		(CString * pstrOutput);

	virtual void WriteSettingsFormStart	(CString * pstrOutput, CString * pstrScrID);
	virtual void WriteTableStart		(CString * pstrOutput, CString * pstrAlign=NULL);
	virtual void WriteTableEnd			(CString * pstrOutput);
	virtual void WriteTableCellStart	(CString * pstrOutput, CString * pstrAlign=NULL);
	virtual void WriteTableCellEnd		(CString * pstrOutput);
	virtual void WriteTableRowStart		(CString * pstrOutput, CString * pstrAlign=NULL);
	virtual void WriteTableRowEnd		(CString * pstrOutput);

	virtual void WriteFontSettings		(CString * pstrOutput);
	virtual void WriteFontSize			(CString * pstrOutput, long size, LPCTSTR txt,BOOL sel);
	virtual void WriteTimeOutSettings	(CString * pstrOutput);
	virtual void WriteTimeOutOption		(CString * pstrOutput, long time, BOOL sel);

// helper functions
	virtual BOOL FixText			(CString * strFix);
	virtual int  HexDigitToInt		(_TCHAR tc);

    
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGenerateHTML)
	public:
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGenerateHTML)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
#endif

