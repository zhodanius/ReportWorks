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
// Get any image path property and convert to full Internet directory
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/imgpath.cpv  $
// 
//    Rev 1.1   30 Apr 1997 16:29:02   amh
// Merged with Steve C's latest source on 4-30-97
// 

#include <tchar.h>
#include "RrvwCtrl.h"
#include "LocalObj.H"
#include "Util.H"
#include "Globals.H"
#include "rrutil.h"
#include <wininet.h>

// Image path property name
WCHAR wszImagePath [] = L"ImagePath";

////////////////////////////////////////////////////////////////////////
// Build full image URL & convert spaces to http lingo
void ViewCtrl::getImagePath( IPropertyBag *pPropertyBag, IErrorLog *pErrorLog )
{
    VARIANT v;

	VariantInit( &v );
	v.vt = VT_BSTR;
	v.bstrVal = NULL;
	pPropertyBag->Read( wszImagePath, &v, pErrorLog );
	if ( v.bstrVal && ( !strCompareWideN( v.bstrVal, L"http:", 5 ) ||
		!strCompareWideN( v.bstrVal, L"file:", 5 )))
	{ // absolute address
		MAKE_ANSIPTR_FROMWIDE( pImagePath, v.bstrVal );
		DWORD dwLen = lstrlen( pImagePath );
		m_pImagePath = new TCHAR[dwLen + 2]; // allow room to append slash
		lstrcpy( m_pImagePath, pImagePath );
		if ( !strCompareN( pImagePath, _T( "http:" ), 5 ))
		{ // need to encode spaces, etc.
			if ( !InternetCanonicalizeUrl( pImagePath, m_pImagePath,
				&dwLen, ICU_DECODE | ICU_BROWSER_MODE ))
			{ // failed, see why
				delete [] m_pImagePath;
				m_pImagePath = NULL;
				if ( ::GetLastError() == ERROR_INSUFFICIENT_BUFFER )
				{ // Need more buffer space (expected) - dwLen should have size required
					m_pImagePath = new TCHAR[dwLen + 2];
					if ( !InternetCanonicalizeUrl( pImagePath, m_pImagePath,
						&dwLen, ICU_DECODE | ICU_BROWSER_MODE ))
					{ // forget it
						delete [] m_pImagePath;
						m_pImagePath = NULL;
					}
				}
			}
		}
		if ( m_pImagePath )
		{ // check for trailing slash
			dwLen = lstrlen( m_pImagePath );
			if (( m_pImagePath[dwLen - 1] != '\\' ) && ( m_pImagePath[dwLen - 1] != '/' ))
				lstrcat( m_pImagePath, _T( "\\" ) );
		}
	}
	else
	{ // concatenate w/ report url to build full image path
		WCHAR wszTemp[MAX_IMAGE__PATH];
		WCHAR szImagePath[MAX_IMAGE__PATH];
		LPWSTR pwImagePath = szImagePath;
		wcscpy( szImagePath, v.bstrVal ? v.bstrVal : L"" );
		if ( wcschr( szImagePath, ' ' ) && !strCompareN( m_pReportURL, _T( "http:" ), 5 ))
		{ // have to encode image path first
			TCHAR szTemp[MAX_IMAGE__PATH];
			MAKE_ANSIPTR_FROMWIDE( pImagePath, pwImagePath );
			DWORD dwLen = sizeof( szTemp );
			InternetCanonicalizeUrl( pImagePath, szTemp, &dwLen, ICU_DECODE | ICU_BROWSER_MODE );
			MultiByteToWideChar( CP_ACP, 0, szTemp, -1, szImagePath, sizeof ( szImagePath ));
		}
		MultiByteToWideChar( CP_ACP, 0, m_pReportURL, -1, wszTemp, MAX_IMAGE__PATH );
		LPWSTR pwTemp = wcsrchr( wszTemp, '\\' );
		if ( !pwTemp )	// try forward then
			pwTemp = wcsrchr( wszTemp, '/' );
		if ( pwTemp )
		{ // found trailing slash
			WCHAR wszSlash[] = { *pwTemp, 0 };
			*( pwTemp + 1 ) = 0;	// remove filename
			if ( wcslen( pwImagePath ))
			{ // use image path property
				wcscat( wszTemp, ( *pwImagePath != '\\' ) && ( *pwImagePath != '/' ) ?
					pwImagePath : pwImagePath + 1 );
				DWORD dwLen = wcslen( wszTemp );
				if (( wszTemp[dwLen - 1] != '\\' ) && ( wszTemp[dwLen - 1] != '/' ))
					wcscat( wszTemp, wszSlash );
			}
			m_pImagePath = new TCHAR[wcslen( wszTemp ) + 1];
			if ( m_pImagePath )
				WideCharToMultiByte( CP_ACP, 0, wszTemp, -1, m_pImagePath, MAX_IMAGE__PATH, NULL, NULL );
		}
	}
	VariantClear( &v );
}
