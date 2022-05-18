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
// Handles parsing and rendering of text data (PDI)
//
//    Note: All text-parsing of PDI data assumes single byte character set.
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/viewtext.cpv  $
// 
//    Rev 1.7   01 Apr 1997 15:52:00   smh
// latest sources on 4/1/97
// 
//    Rev 1.6   22 Mar 1997 19:29:00   smh
// Sources from 1/24/97
// 
//    Rev 1.5   02 Jan 1997 15:42:36   smh
// Apply strikeout attribute when creating font (RSW 2373).
// 
//    Rev 1.4   19 Dec 1996 16:27:08   smh
// Added auto-comment header.
// 

#include <windows.h>
#include <tchar.h>
#include "rrvwctrl.h"
#include "viewtext.h"

///////////////////////////////////////////////////////////////
// Constructor
ViewText::ViewText( ViewCtrl *pViewCtrl, HDC hDC, BOOL bPreview, LPRECT pRect,
	UINT nCount, LPSTR pData ) : ViewRep( pViewCtrl, hDC, bPreview, pRect, nCount )
{
	m_pData = pData;		// permanent data pointer
	m_hCurFont = NULL;		// current font handle
}

///////////////////////////////////////////////////////////////
// Destructor
ViewText::~ViewText()
{
	if ( m_hDC && ( m_hCurFont != NULL ))
	{ // clean up font
		SelectObject( m_hDC, GetStockObject( ANSI_VAR_FONT ));
		DeleteObject( m_hCurFont );
	}
}

///////////////////////////////////////////////////////////////
// Get a byte from line buffer
BOOL ViewText::getByte( int *pByteVal )
{
	*pByteVal = *m_pCurData;		// return next byte
	m_pCurData += sizeof( char );	// adjust pointer
	// check for null or end of page
	return (( *pByteVal != 0 ) && ( *pByteVal != PDI_EOP ));
}

///////////////////////////////////////////////////////////////
// Get two bytes from line buffer
BOOL ViewText::getWord( UINT *pWordVal )
{
	*pWordVal = *(WORD *)m_pCurData;	// return next word
	m_pCurData += sizeof( WORD );		// adjust pointer
	return TRUE;
}

///////////////////////////////////////////////////////////////
// Get length-prefixed string
BOOL ViewText::getString( LPSTR pStr, int nMaxLen )
{
	int nCnt = *m_pCurData++;	// count
	if ( nCnt > nMaxLen )
		return FALSE;		// safety check
	MoveMemory( pStr, m_pCurData, nCnt );
	m_pCurData += nCnt;
	return TRUE;
}

///////////////////////////////////////////////////////////////
// Scan text and check for space dots; return length
int ViewText::textLength( LPCSTR pData, BOOL bFullJust )
{
	if ( bFullJust && ( *pData == _T( ' ' )))
		return 1;
	int nLen = 0;
	while ( *pData && ( *pData != PDI_START ) && ( *pData != PDI_EOP )
		&& ( !bFullJust || ( *pData != _T( ' ' ))))
	{ // count 'em
		nLen++;
		pData++;
	}
	return nLen;
}

/////////////////////////////////////////////////////////////////////////////
// Create and select a font
void ViewText::setFont( LPSTR pFace, int nAtt, int nPoints )
{
	LOGFONT lf;

	ZeroMemory( &lf, sizeof( lf ));
	lf.lfWeight = ( nAtt & BOLD ) ? FW_BOLD : FW_NORMAL;
	lf.lfUnderline = ( nAtt & UNDER ) ? 1 : 0;
	lf.lfItalic = ( nAtt & ITALIC ) ? 1 : 0;
	lf.lfStrikeOut = ( nAtt & STRIKE ) ? 1 : 0;
	lf.lfCharSet = DEFAULT_CHARSET;
	lf.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	lf.lfQuality = DRAFT_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	lstrcpyn( lf.lfFaceName, pFace, LF_FACESIZE + 1 );
	// scale points to printer or screen resolution
	lf.lfHeight = m_bPreview ? -scalePrevY( nPoints ) :
		-MulDiv( nPoints, m_pViewCtrl->m_nPrtInchY, POINTSIZE * 10 );
	if ( !lf.lfHeight )		// safety check...
		lf.lfHeight = -1;
	HFONT hNewFont = ::CreateFontIndirect( &lf );
	if ( hNewFont != NULL )
	{ // select it in
		SelectObject( m_hDC, hNewFont );
		// remove the old
		if ( m_hCurFont != NULL )
			DeleteObject( m_hCurFont );
		m_hCurFont = hNewFont;
	}
}

/////////////////////////////////////////////////////////////////////////////
// Compute the length of text for justification purposes
int ViewText::sizeText( UINT *pUnits, UINT *pSpaces, int nEndCode, UINT *pPos )
{
	int nDataChar, nHzWidth = 0, nAtt, nLen, nPoints;
	BOOL bData = FALSE;
	LPSTR pSave = m_pCurData;
	LPSTR pTemp;

	while ( getByte( &nDataChar ))
	{
		if ( nDataChar == PDI_START )
		{
			getByte( &nDataChar );
			if ( nDataChar == nEndCode )
			{
				if ( pPos )				// for RIGHTJUST, CENTER
					getWord( pPos );	// position
				break;
			}
			switch ( nDataChar )
			{
				case PDI_FONT:		// font change
					char szFont[LF_FACESIZE + 1];
					ZeroMemory( szFont, sizeof( szFont ));
					if ( !getString( szFont, LF_FACESIZE ))
						return 0;	// something amiss!
					getWord( (UINT *) &nAtt );	// prospective attribute
					getWord( (UINT *) &nPoints );	// prospective decipoints
					setFont( szFont, nAtt, nPoints );
					break;
				case PDI_START:
				{
					SIZE sizeText;
					char szChar[] = { _T( "A" ) };
					GetTextExtentPoint32( m_hDC, szChar, 1, &sizeText );
					nHzWidth += sizeText.cx;
					bData = TRUE;		// non-space
					break;
				}
				case PDI_COLOR:
					m_pCurData += ( 3 * sizeof( WORD ));
					break;
				case PDI_YPOS:
					m_pCurData += sizeof( WORD );
					break;
				default:			// unknown PDI code
					break;
			}
		}
		else
		{
			pTemp = m_pCurData - 1;
			nLen = textLength( pTemp, FALSE );
			for ( int ii = 0; ii < nLen; ii++ )
			{
				if ( pTemp[ii] == _T( ' ' ))
					( *pSpaces )++;	  // count spaces
				else
					bData = TRUE;	  // non-space
			}
			SIZE sizeText;
			GetTextExtentPoint32( m_hDC, pTemp, nLen, &sizeText );
			nHzWidth += sizeText.cx;
			m_pCurData += nLen - 1;
		}
	}
	*pUnits = nHzWidth;
	m_pCurData = pSave;	// restore
	return bData;
}

///////////////////////////////////////////////////////////////
// Scan PDI data & output page to screen or printer
void ViewText::showPage( void )
{
	int nDataChar, nYAdjust = 0, nAtt = 0, nPoints;
	int nHzSpaceLeft = 0, nHzWidth, nSpaces = 0, nJustExtra = 0, nXPos = 0;
	int r = 0, g = 0, b = 0;
	int nLeft = 0, nTop = 0;
	BOOL bJustify = FALSE, bGotStart = FALSE;
	UINT nLength, nValue;
	RECT rectPage;
	LPSTR pTemp;

	m_pCurData = m_pData;	// take it from the top
	SetMapMode( m_hDC, MM_TEXT );
	SetTextAlign( m_hDC, TA_LEFT | TA_BASELINE | TA_NOUPDATECP );
	SetBkMode( m_hDC, TRANSPARENT );
	if ( m_bPreview )
	{ // previewing
		nLeft = m_pRectWnd->left;
		nTop = m_pRectWnd->top;
		SetMapperFlags( m_hDC, 1L );
		CopyRect( &rectPage, m_pRectWnd );
		m_yPos = 0;		// top of page
	}
	else
	{ // printing, compensate for current unprintable top
		m_yPos = -m_pViewCtrl->m_sizeUnprint.cy;
	}
	while ( getByte( &nDataChar ))
	{
		if ( nDataChar == PDI_START )
			bGotStart = !bGotStart;
		else
		{
			if ( bGotStart )
			{ // got some PDI
				switch ( nDataChar )
				{
					case PDI_POS:			// position
						getWord( &nValue );
						nXPos = scalePosition( nValue, FALSE );
						break;
					case PDI_YPOS:				// y field delta
						getWord( &nValue );
						nYAdjust = scalePosition( nValue, TRUE );
						break;
					case PDI_FONT:				// typeface, size, style
						char szFont[LF_FACESIZE + 1];
						ZeroMemory( szFont, sizeof( szFont ));
						if ( !getString( szFont, LF_FACESIZE ))
							return;	// something amiss!
						getWord( (UINT *) &nAtt );	// style
						getWord( (UINT *) &nValue );	// points
						if (!( nPoints = nValue ))	// got any?
							nPoints = 120;			// nope, use 12 point
						setFont( szFont, nAtt, nPoints );
						break;
					case PDI_COLOR:
						getWord( (UINT *) &r );	// red triplet
						getWord( (UINT *) &g );	// and green
						getWord( (UINT *) &b );	// and finally, blue
						break;
					case PDI_FULLJUST:	// full justify on/off
						if ( bJustify )
						{ // off
							bJustify = FALSE;
							nSpaces = nHzSpaceLeft = nJustExtra = 0;
							break;
						}
						bJustify = TRUE;
						getWord( &nValue );	// get width
						if ( sizeText( (UINT *)&nHzWidth, (UINT *)&nSpaces,
							PDI_FULLJUST, (UINT *)NULL ))
						{ // more than just spaces
							nLength = scalePosition( nValue, FALSE ) - nHzWidth;
							if (( (int)nLength > 0) && nSpaces )
							{
								nHzSpaceLeft = nLength % nSpaces; 	// left over
								nJustExtra = nLength / nSpaces;		// amount per space
							}
							else
								nSpaces = nJustExtra = 0;
						}
						else	// just spaces
							nSpaces = nJustExtra = nHzSpaceLeft = 0;
						break;
					case PDI_ENDCENT:
					case PDI_ENDRITE:
						getWord( &nValue );	// swallow position
						if ( nDataChar == PDI_ENDCENT )
							getWord( &nValue );  // and mode
						break;
					case PDI_CENTER:
					case PDI_RITEJUST:	// right justify
						sizeText( (UINT *)&nHzWidth, (UINT *)&nSpaces,
							( nDataChar == PDI_CENTER ) ? PDI_ENDCENT : PDI_ENDRITE,
							(UINT *)&nValue );
						nXPos = scalePosition( nValue, FALSE );
						if ( nDataChar == PDI_RITEJUST )
							nXPos -= nHzWidth;			// start = pos - width
						else
							nXPos -= ( nHzWidth / 2 );	// start = pos - width / 2
						nSpaces = nJustExtra = nHzSpaceLeft = 0; // don't mistake it for fulljust
						break;
					case PDI_BOL:		// ascender
					case PDI_EOL:		// descender
						getWord( &nValue );
						m_yPos += (short)nValue;	// could be negative!
						nYAdjust = 0; 	// reset vertical delta
						nXPos = 0;		// force a CR
						break;
					default:			// unknown PDI code
						break;
				}
				bGotStart = FALSE;
			}
			else
			{ // not PDI escape, so must be text (we hope)
				pTemp = m_pCurData - 1;
				nLength = textLength( pTemp, ( nJustExtra || nHzSpaceLeft ));
				SetTextColor( m_hDC, RGB( r, g, b ));
				int x = max( 0, nXPos );
				int nYLoc = scalePosition( m_yPos, TRUE );
				if ( m_bPreview )
				{ // previewing...
					ExtTextOut( m_hDC, x - m_pViewCtrl->m_nScrollPosX + nLeft,
						nYLoc - nYAdjust - m_pViewCtrl->m_nScrollPosY + nTop,
						ETO_CLIPPED, &rectPage, pTemp, nLength, (LPINT)NULL );
				}
				else
				{ // printing, subtract unprintable left edge
					TextOut( m_hDC, x - scalePosition( m_pViewCtrl->m_sizeUnprint.cx, FALSE ),
						nYLoc - nYAdjust, pTemp, nLength );
				}
				SIZE sizeText;
				GetTextExtentPoint32( m_hDC, pTemp, nLength, &sizeText );
				nXPos += sizeText.cx ;
				m_pCurData += nLength - 1;
				if (( nDataChar == _T( ' ' )) && ( nJustExtra || nHzSpaceLeft ))
				{ // full justifying
					nXPos += nJustExtra;
					if ( nHzSpaceLeft )
					{ // leftovers
						nXPos++;
						nHzSpaceLeft--;
					}
				}
			}			
		}
	}
	if ( m_bPreview )
		showEndOfPage();	// indicate end of page
}
