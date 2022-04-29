// rrver.h : version number routine class
//
#if !defined(_RRVER_H_)

#define _RRVER_H_

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

// Class for file version info manipulation.
// So far, just parses a version string into its high and low dwords
//	If version string is a.b.c.d, a=hiword of most significant dword,
//											b=loword of most significant dword,
//											c=hiword of least significant dword,
//											d=loword of least significant dword
//	If version string is a.b.c, c still = hiword of least significant dword and
//											0 = loword of least significant dword

class CRrVer
{
public:

	// Constructor
	CRrVer( ) { dwVersionMS = 0;  dwVersionLS = 0; };

public:
	DWORD dwVersionMS;		// Most significant dword of version info - hold two version parts
	DWORD dwVersionLS;		// Least significant dword of version info - hold two version parts

	BOOL CRrVer::parseExpectedVersionString( LPSTR lpszVersion );

private:

	enum	{	VERSIZE = 20 };		// size of version info buffer

	BOOL CRrVer::advanceVerptr( LPSTR * verptr, BOOL lookfordigit, int * numchars );
};


/////////////////////////////////////////////////////////////////////////////

#endif
