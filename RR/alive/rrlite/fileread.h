// ****************************************************************************
//
//      (C) Copyright 1996 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
// File read class
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/fileread.h_v  $
// 
//    Rev 1.5   30 Apr 1997 16:28:08   amh
// Merged with Steve C's latest source on 4-30-97
// 

#include "resource.h"       // main symbols

class ViewCtrl;

/////////////////////////////////////////////////////////////////////////////
// Class to handle local & Internet file open/read

class FileRead
{
public:
	FileRead();

	~FileRead();

private:
		BOOL		m_bLocalFile;
		HANDLE		m_hFile;
		HINTERNET	m_hInternetSession;
		HINTERNET	m_hInternetURL;
public:
		void	frClose();
		BOOL	frOpen( LPTSTR );
		BOOL	frReadBlock( LPVOID, UINT );
		BOOL	frSeek( BOOL, long );
};

