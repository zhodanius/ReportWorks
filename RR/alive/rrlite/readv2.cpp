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
// Read PDI Version 2 files
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/readv2.cpv  $
// 
//    Rev 1.0   19 May 1997 11:00:06   smh
// Initial revision.
// 

#include <windows.h>
#include <wininet.h>
#include <tchar.h>
#include "fileread.h"
#include "rrvwctrl.h"
#include "reppage.h"
#include "rrutil.h"
#include "accusoft.h"

///////////////////////////////////////////////////////////////////////
// Read PDI page data via page index, creating a page object for each page
UINT createVer2PageObjects( FileRead *pFileRead, ViewCtrl *pViewCtrl )
{
	int nPages = 0;
	// allocate page object array
	pViewCtrl->m_pPageArray = (PAGE_ARRAY *)HeapAlloc( GetProcessHeap(),
		HEAP_ZERO_MEMORY, pViewCtrl->m_nPageCount * sizeof( PAGE_ARRAY ));
	// position to beginning of page index
	if ( !g_bStopThreads && pViewCtrl->m_pPageArray && pFileRead->frSeek( FALSE,
		-( pViewCtrl->m_nPageCount * (int)sizeof( PAGE_POS2 ))))
	{ // got page array and file positioned
		for ( int ii = 0; ii < pViewCtrl->m_nPageCount; ii++ )
		{ // first read sequentially thru the index packets
			PAGE_POS2 pagePos;
			if ( g_bStopThreads )
				ExitThread( FALSE );	// emergency shutdown
			if ( pFileRead->frReadBlock( (LPSTR)&pagePos, sizeof( PAGE_POS2 )))
			{ // got a page index block, create a page object
				RepPage *pRepPage = new RepPage( pViewCtrl );
				if ( pRepPage )
				{ // save file position for later data reads
					pRepPage->m_dwFilePos = pagePos.dwPagePos;
					pViewCtrl->m_pPageArray[ii].pRepPage = pRepPage;
					// check for text
					if ( pagePos.dwTextByteCount )
					{ // got some text - get some space
						LPTSTR pData = (LPTSTR)HeapAlloc( GetProcessHeap(),
							HEAP_ZERO_MEMORY, pagePos.dwTextByteCount );
						if ( pData )
						{ // store in page object
							pRepPage->m_pText = pData;
							// save count for later data reads
							pRepPage->m_dwTextByteCount = pagePos.dwTextByteCount;
						}
					}
					// check for boxes
					if ( pagePos.wBoxCount )
					{ // got some box(es)
						LINE_BOX *pData = (LINE_BOX *)HeapAlloc( GetProcessHeap(),
							HEAP_ZERO_MEMORY, pagePos.wBoxCount * sizeof( LINE_BOX ));
						if ( pData )
						{ // store in page object
							pRepPage->m_pBoxes = pData;
							// store object count
							pRepPage->m_nBoxCount =	pagePos.wBoxCount;
						}
					}
					// check for lines
					if ( pagePos.wLineCount )
					{ // got some line(s)
						LINE_BOX *pData = (LINE_BOX *)HeapAlloc( GetProcessHeap(),
							HEAP_ZERO_MEMORY, pagePos.wLineCount * sizeof( LINE_BOX ));
						if ( pData )
						{ // store in page object
							pRepPage->m_pLines = pData;
							// store object count
							pRepPage->m_nLineCount = pagePos.wLineCount;
						}
					}
					// and finally images
					if ( pagePos.wImageCount )
					{ // got some image(s)
						IMAGE *pData = (IMAGE *)HeapAlloc( GetProcessHeap(),
							HEAP_ZERO_MEMORY, pagePos.wImageCount * sizeof( IMAGE ));
						if ( pData )
						{ // store in page object
							pRepPage->m_pImages = pData;
							// store object count (based on incoming structure)
							pRepPage->m_nImageCount = pagePos.wImageCount;
						}
					}
				}
			}
			else
				return nPages;
		}
		for ( ii = 0; ii < pViewCtrl->m_nPageCount; ii++ )
		{ // now read data into page object buffers
			if ( g_bStopThreads )
				ExitThread( FALSE );	// emergency shutdown
			RepPage *pRepPage = pViewCtrl->m_pPageArray[ii].pRepPage;
			if ( !g_bStopThreads && pRepPage &&
				pFileRead->frSeek( TRUE, pRepPage->m_dwFilePos + SIZE_OBJECT_PACKET ))
			{ // now @ start of page data
				if ( !g_bStopThreads && (pRepPage->m_pText != NULL ))
				{ // got text, start with that
					if ( !pFileRead->frReadBlock( pRepPage->m_pText,
							pRepPage->m_dwTextByteCount ))
						return nPages;
				}
				char sizePacket[ SIZE_OBJECT_PACKET ];
				if ( !pFileRead->frReadBlock( sizePacket, sizeof( sizePacket )))
					return nPages;
				if ( !g_bStopThreads && ( pRepPage->m_pBoxes != NULL ))
				{ // now read boxes
					if ( !pFileRead->frReadBlock( (LPSTR)pRepPage->m_pBoxes,
							pRepPage->m_nBoxCount * sizeof( LINE_BOX )))
						return nPages;
				}
				if ( !pFileRead->frReadBlock( sizePacket, sizeof( sizePacket )))
					return nPages;
				if ( !g_bStopThreads && ( pRepPage->m_pLines != NULL ))
				{ // and lines
					if ( !pFileRead->frReadBlock( (LPSTR)pRepPage->m_pLines,
							pRepPage->m_nLineCount * sizeof( LINE_BOX )))
						return nPages;
				}
				if ( !pFileRead->frReadBlock( sizePacket, sizeof( sizePacket )))
					return nPages;
				if ( !g_bStopThreads && ( pRepPage->m_pImages != NULL ))
				{ // and finally, images
					if ( !pViewCtrl->m_bImageDLLError && ( pViewCtrl->m_hImageLib == NULL ))
					{ // check if Accusoft DLL loaded
						pViewCtrl->m_hImageLib = loadImageLib();
						if ( pViewCtrl->m_hImageLib == NULL )
							pViewCtrl->m_bImageDLLError = TRUE;	// flag error
					}
					if ( !readImages( pFileRead, pRepPage, pViewCtrl ))
						return nPages;
				}
				pRepPage->m_bPageReady = TRUE;	// flag page as ready
				if ( !g_bStopThreads )
				{ // notify main thread - we've got another page
					SendMessage( pViewCtrl->getCtrlHwnd(), WM_USER_PAGEDONE, ii, 0 );
				}
				nPages++;
			}
			else
				return nPages;
		}
	}
	// return pages processed
	return nPages;
}
