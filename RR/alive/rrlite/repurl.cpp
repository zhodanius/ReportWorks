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
// Get full URL to report data file
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/alive/rrlite/REPURL.CPV  $
// 
//    Rev 1.2   Feb 28 2001 09:24:38   nhubacker
// Debug
// 
//    Rev 1.1   30 Apr 1997 16:36:26   amh
// Merged with Steve C's latest source on 4-30-97
// 
//    Rev 1.0   28 Mar 1997 17:17:00   smh
// Initial revision.
//

#include <tchar.h>
#include "RrvwCtrl.h"
#include "LocalObj.H"
#include "Util.H"
#include "Globals.H"
#include "rrutil.h"
#include <wininet.h>

/*///////////////////////////////////////////////////////////////////////
    ViewCtrl::getFullURL(): Request absolute URL from container.

    This used to be a nice, simple routine, but has grown significantly
    in order to support the nCompass ScriptActive Netscape plug-in and
    its required workarounds.

    First, we try to create a moniker from the report URL passed, then
    call IMoniker->GetDisplayName() to get the full URL.  IE 3.0.1
    supports this technique; however the nCompass Netscape ActiveX
    plug-in (oleplug.dll version 2,5,0,9) does not.  Therefore we check
    to see if the result of the GetDisplayName call returns a full URL
    (by testing for "http:" or "file:").  If not, then the workaround is
    to call IOleClientSite->GetMoniker() to get the URL of the HTML
    document containing the control.  The report file URL is then set to
    the location of the document.

    Running under IE 3.0.1, GetDisplayName() encodes any spaces (%20)
    contained in the URL.  nCompass however, does not.  So any "http:"
    URL that is obtained via the workaround must be checked for spaces
    and encoded if necessary.
*/
BOOL ViewCtrl::getFullURL( LPSTR pReportURL )
{
	CHECK_POINTER( pReportURL );
	IMoniker *pmkr;
	IBindCtx *pBindCtx = 0;
	BOOL bResult = FALSE;

#if 1
//::MessageBox( NULL, pReportURL, "Incoming URL", MB_ICONSTOP | MB_TASKMODAL );
	// first, create the moniker
	HRESULT hr = GetAMoniker( OLESTRFROMANSI( pReportURL ), &pmkr );
	if ( SUCCEEDED( hr ) && pmkr )
    { // now create bind context
		hr = ::CreateBindCtx( 0, &pBindCtx );
		if ( SUCCEEDED( hr ) && pBindCtx )
		{ // now allocate some memory for full URL name
			LPOLESTR pwFullURL = NULL;
			LPWSTR pwFromContainer = NULL;
			// retrieve full URL from ReportURL parameter
			hr = pmkr->GetDisplayName( pBindCtx, pmkr, &pwFullURL );
			if ( SUCCEEDED( hr ) && pwFullURL )
			{ // we should have a valid, full name, but better check
				if ( strCompareWideN( pwFullURL, L"http:", 5 ) &&
					strCompareWideN( pwFullURL, L"file:", 5 ))
				{ // did not get full URL, try looking in HTML file location
					CoTaskMemFree( pwFullURL );
					// get container moniker
					hr = m_pClientSite->GetMoniker( OLEGETMONIKER_FORCEASSIGN,
						OLEWHICHMK_CONTAINER, &pmkr );
					pwFullURL = NULL;	// try again
					if ( SUCCEEDED( hr ) && pmkr )
						hr = pmkr->GetDisplayName( pBindCtx, pmkr, &pwFullURL );
					if ( SUCCEEDED( hr ) && pwFullURL )
					{ // find trailing slash
						LPWSTR pEnd = wcsrchr( pwFullURL, '/' );
						if ( !pEnd )
							pEnd = wcsrchr( pwFullURL, '\\' );
						if ( pEnd )
							*( pEnd + 1 ) = 0;
						// get memory for concatenation
						pwFromContainer = new WCHAR[wcslen( pwFullURL ) + lstrlen( pReportURL ) + 1];
					}
					if ( FAILED( hr ) || !pwFullURL || !pwFromContainer)
					{ // can't get a full URL
						if ( pwFullURL )
							CoTaskMemFree( pwFullURL );
						pBindCtx->Release();
						return FALSE;
					}
					// move to larger buffer
					wcscpy( pwFromContainer, pwFullURL );
					// now append report URL value
					MAKE_WIDEPTR_FROMANSI( pwReportURL, pReportURL );
					wcscat( pwFromContainer, pwReportURL );
				}
				MAKE_ANSIPTR_FROMWIDE( pFullURL, pwFromContainer ?
					pwFromContainer : pwFullURL );
				// free memory allocated by GetDisplayName()
				if ( pwFullURL )
					CoTaskMemFree( pwFullURL );
				// free wide temp URL buffer
				if ( pwFromContainer )
					delete [] pwFromContainer;
				DWORD dwLen = lstrlen( pFullURL ) + 1;
				m_pReportURL = new TCHAR[dwLen];
				if ( !strCompareN( pFullURL, _T( "file:" ), 5 ))
				{ // remove HTML escape sequences for local files
					if (!( bResult = InternetCanonicalizeUrl( pFullURL, m_pReportURL,
						&dwLen, ICU_DECODE | ICU_NO_ENCODE )))
					{ // failed, check buffer length
						if ( ::GetLastError() == ERROR_INSUFFICIENT_BUFFER )
						{ // need more buffer space (expected)
							delete [] m_pReportURL;
							// new dwLen set by function call
							m_pReportURL = new TCHAR[dwLen];	// we'll try again
							bResult = InternetCanonicalizeUrl( pFullURL, m_pReportURL,
								&dwLen, ICU_DECODE | ICU_NO_ENCODE );
						}
					}

				}
				else
				{ // if using Netscape workaround, first check for spaces
					if ( pwFromContainer && strchr( pFullURL, ' ' ))
					{ // yup, need to encode them
						if (!( bResult = InternetCanonicalizeUrl( pFullURL, m_pReportURL,
							&dwLen, ICU_DECODE | ICU_BROWSER_MODE )))
						{ // failed, see why
							if ( ::GetLastError() == ERROR_INSUFFICIENT_BUFFER )
							{ // need more buffer space (expected)
								delete [] m_pReportURL;
								// new dwLen set by function call
								m_pReportURL = new TCHAR[dwLen];	// we'll try again
								bResult = InternetCanonicalizeUrl( pFullURL, m_pReportURL,
									&dwLen, ICU_DECODE | ICU_BROWSER_MODE );
							}
						}
					}
					else
					{ // no conversion, just copy
						lstrcpy( m_pReportURL, pFullURL );
						bResult = TRUE;
					}
				}
			}
			pBindCtx->Release();
		}
    }
	return bResult;

#else	// suggested use of GetMoniker & ComposeWith - which still doesn't work for nCompass

	if ( !strCompareN( pReportURL, _T( "file:" ), 5 ))
	{ // full local file path
		m_pReportURL = new TCHAR[lstrlen( pReportURL ) + 1];
		lstrcpy( m_pReportURL, pReportURL );
		return TRUE;
	}
	if ( !strCompareN( pReportURL, _T( "http:" ), 5 ))
	{ // full Internet URL
		m_pReportURL = new TCHAR[lstrlen( pReportURL ) + 1];
		if ( strchr( pReportURL, ' ' ))
		{ // yup, need to encode them
			DWORD dwLen;
			if (!( bResult = InternetCanonicalizeUrl( pReportURL, m_pReportURL,
				&dwLen, ICU_DECODE | ICU_BROWSER_MODE )))
			{ // failed, see why
				if ( ::GetLastError() == ERROR_INSUFFICIENT_BUFFER )
				{ // need more buffer space (expected)
					delete [] m_pReportURL;
					// new dwLen set by function call
					m_pReportURL = new TCHAR[dwLen];	// we'll try again
					bResult = InternetCanonicalizeUrl( pReportURL, m_pReportURL,
						&dwLen, ICU_DECODE | ICU_BROWSER_MODE );
				}
			}
		}
		else
			lstrcpy( m_pReportURL, pReportURL );
		return TRUE;
	}
	// relative URL
	HRESULT hr = GetAMoniker( OLESTRFROMANSI( pReportURL ), &pmkr );
	if ( SUCCEEDED( hr ) && pmkr )
	{
		IMoniker *pHostMkr;
		hr = m_pClientSite->GetMoniker( OLEGETMONIKER_FORCEASSIGN,
			OLEWHICHMK_CONTAINER, &pHostMkr );
		if ( SUCCEEDED( hr ) && pHostMkr )
		{ // got host moniker - combine
			IMoniker *pFullMkr;
			hr = pHostMkr->ComposeWith( pmkr, FALSE, &pFullMkr );
			if ( SUCCEEDED( hr ))
			{
				hr = ::CreateBindCtx( 0, &pBindCtx );
				if ( SUCCEEDED( hr ) && pBindCtx )
				{ // now allocate some memory for full URL name
					LPOLESTR pwFullURL = NULL;
					// retrieve full URL from ReportURL parameter
					hr = pmkr->GetDisplayName( pBindCtx, pmkr, &pwFullURL );
					if ( SUCCEEDED( hr ) && pwFullURL )
					{
						MAKE_ANSIPTR_FROMWIDE( pFullURL, pwFullURL );
						// free memory allocated by GetDisplayName()
						if ( pwFullURL )
							CoTaskMemFree( pwFullURL );
						DWORD dwLen = lstrlen( pFullURL ) + 1;
						m_pReportURL = new TCHAR[dwLen];
						lstrcpy( m_pReportURL, pFullURL );
						bResult = TRUE;
					}
				}
				pBindCtx->Release();
			}
		}
    }
	return bResult;
#endif
}
