// ****************************************************************************
//
//		(C) Copyright 1996 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
// Local & Internet File Read Functions
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/alive/rrlite/FILEREAD.CPV  $
// 
//    Rev 1.9   Feb 28 2001 09:23:58   nhubacker
// Fix for file read
// 
//    Rev 1.8   30 Nov 1998 11:36:48   wrr
// 
//    Rev 1.7.1.1   24 Mar 1998 14:38:02   smh
// Try INTERNET_OPEN_TYPE_DIRECT.
// 
//    Rev 1.7.1.0   19 Mar 1998 12:00:30   smh
// 155719 - Send NULL instead of "" for proxy name
// arg to InternetOpen so works in proxy server environments.
// 
//    Rev 1.7   30 Apr 1997 16:26:54   amh
// Merged with Steve C's latest source on 4-30-97
// 

#include <windows.h>
#include <wininet.h>
#include <tchar.h>
#include "fileread.h"
#include "rrutil.h"

///////////////////////////////////////////////////////////////////////
// Constructor
FileRead::FileRead( void )
{
	m_bLocalFile = FALSE;
	m_hFile = INVALID_HANDLE_VALUE;
	m_hInternetSession = NULL;
	m_hInternetURL = NULL;
}

///////////////////////////////////////////////////////////////////////
// Destructor
FileRead::~FileRead( void )
{
	frClose();	// check if file closed
}

///////////////////////////////////////////////////////////////////////
//
// File Open function
//
//  Opens local ("file://") or remote ("http://") PDI file
//  using standard or WinINet Win32 file I/O functions
//
BOOL FileRead::frOpen( LPTSTR pFile )
{
	BOOL bResult = FALSE;

	// first check if local file - using Win32 string calls
	if ( !strCompareN( pFile, _T( "file:" ), 5))
	{ // local, handle it with normal file functions
		SECURITY_ATTRIBUTES security;
		security.nLength = sizeof( SECURITY_ATTRIBUTES );
		security.lpSecurityDescriptor = NULL;
		security.bInheritHandle = FALSE;

		pFile += 5;	// skip the prefix
//		while ( *pFile && (( *pFile == _T( '/' )) || ( *pFile == _T( '\\' ))))
		while ( *pFile == _T( '/' ) )
			pFile++;	// skip forward slashes
//::MessageBox( NULL, pFile, "weed", MB_ICONSTOP | MB_TASKMODAL );
		// open for reading
		m_hFile = ::CreateFile( pFile, GENERIC_READ, FILE_SHARE_READ,
			&security, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
		m_bLocalFile = TRUE; // flag as local file
#ifdef _DEBUG
		if ( m_hFile == INVALID_HANDLE_VALUE )
			displayDebugError( _T( "CreateFile" ));
#endif
		return ( m_hFile != INVALID_HANDLE_VALUE );
	}
	else
	{ // retrieve file from web server

		// wo 155719 - Changing proxy name arg from "" to NULL.
		//	In InternetOpen doc, found "Address of a string 
		//	that contains the name of the proxy server (or servers) 
		//	to use if proxy access was specified. If this parameter 
		//	is NULL, the function reads proxy information from the 
		//	registry. Do not use an empty string, because InternetOpen 
		//	will use it as the proxy name."
		m_hInternetSession = ::InternetOpen(
			_T( "RRPrView" ),				// app name
			INTERNET_OPEN_TYPE_DIRECT ,	// access type
			NULL,							// proxy name
			INTERNET_INVALID_PORT_NUMBER,	// proxy server addresses
			0 );							// flags
		if ( m_hInternetSession == NULL )
		{ // can't open session
#ifdef _DEBUG
			displayDebugError( _T( "InternetOpen" ));
#endif
			return FALSE;
		}
		TCHAR szHead[] = "Accept: */*\r\n\r\n"; // we'll take anything
		m_hInternetURL = ::InternetOpenUrl(
			m_hInternetSession,	// session handle
			pFile,				// Full URL
			szHead,				// HTTP headers
			lstrlen( szHead ),	// Headers length
			0,					// Flags
			0 );				// Context
		if ( m_hInternetURL == NULL )
		{ // can't open URL
			InternetCloseHandle( m_hInternetSession );
#ifdef _DEBUG
			displayDebugError( _T( "InternetOpenURL" ));
#endif
		}
		return ( m_hInternetURL != NULL );
	}
}

///////////////////////////////////////////////////////////////////////
// Read a block of bytes
BOOL FileRead::frReadBlock( LPVOID pBlock, UINT nCnt )
{
	BOOL bResult;
	DWORD dwRead;

	if ( m_bLocalFile )
		bResult = ReadFile( m_hFile, pBlock, nCnt, &dwRead, NULL );
	else
		bResult = InternetReadFile( m_hInternetURL, pBlock, nCnt, &dwRead );
	return bResult && ( dwRead == nCnt );
}

///////////////////////////////////////////////////////////////////////
// Seek from beginning/end of file
BOOL FileRead::frSeek( BOOL bFront, long lPos )
{
	if ( m_bLocalFile )
		return SetFilePointer( m_hFile, lPos, NULL,
			bFront ? FILE_BEGIN : FILE_END ) != 0xFFFFFFFF;
	else
		return InternetSetFilePointer( m_hInternetURL, lPos, NULL,
			bFront ? FILE_BEGIN : FILE_END, 0 ) != 0xFFFFFFFF;
}

///////////////////////////////////////////////////////////////////////
// Close up file-related stuff
void FileRead::frClose()
{
	if ( m_bLocalFile )
	{ // close local file
		if ( m_hFile != INVALID_HANDLE_VALUE )
		{
			CloseHandle( m_hFile );
			m_hFile = INVALID_HANDLE_VALUE;
		}	
	}
	else
	{ // close internet handles
		if ( m_hInternetURL != NULL )
		{
			InternetCloseHandle( m_hInternetURL );
			m_hInternetURL = NULL;
		}
		if ( m_hInternetSession != NULL )
		{
			InternetCloseHandle( m_hInternetSession );
			m_hInternetSession = NULL;
		}
	}
}
