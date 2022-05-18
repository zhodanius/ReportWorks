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
// Display control/report properties dialog
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/alive/rrlite/DISPPROP.CPV  $
// 
//    Rev 1.6   Jul 18 2000 13:40:32   nhubacker
// Attribution
// 
//    Rev 1.5   24 Jun 1997 09:14:44   amh
// Added code to initial about box with the SnowBound copyright text
// 
//    Rev 1.4   20 May 1997 16:00:24   amh
// Added code for the About box to display correct attribution information
// 
//    Rev 1.0   20 Mar 1997 12:10:54   smh
// Initial revision.
// 

#include <windows.h>
#include <tchar.h>
#include "rrvwctrl.h"
#include "rrutil.h"
#include "util.h"
#include "resource.h"
#include "rrlangid.h"

////////////////////////////////////////////////////////////////////////
// Dialog callback function
BOOL CALLBACK propDialog( HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	static HBITMAP hBit = NULL;

	switch ( uMsg )
	{
		case WM_INITDIALOG:
		{
			RECT rc;
			// center on display
			::GetWindowRect( hDlg, &rc );
			::OffsetRect( &rc, -rc.left, -rc.top );
			::MoveWindow( hDlg, (( ::GetSystemMetrics( SM_CXSCREEN) - rc.right ) / 2 + 4 ) & ~7,
				( ::GetSystemMetrics( SM_CYSCREEN) - rc.bottom ) / 2, rc.right, rc.bottom, 1 );

			ViewCtrl *pViewCtrl = (ViewCtrl *)lParam;
			::SetWindowText( hDlg, pViewCtrl->loadString( IDS_ABOUT ));
			// get version # and strings from resources
			TCHAR szVer[100];
			lstrcpyn( szVer, pViewCtrl->loadString( IDS_VERTEXT ), 20 );
			lstrcat( szVer, _T( " " ));
			lstrcat( szVer, pViewCtrl->loadString( IDS_VERSION ));
			::SetDlgItemText( hDlg, IDC_ABOUTTEXT, pViewCtrl->loadString( IDS_ABOUTTEXT ));
			::SetDlgItemText( hDlg, IDC_VERTEXT, szVer);

			//AMH 5/16/97 added code
			TCHAR	szHolder[512];

			lstrcpy(szHolder, pViewCtrl->loadString(IDS_INCORPTEXT));
			lstrcat(szHolder,	pViewCtrl->loadString(IDS_INCORPTEXT_2));
			lstrcat(szHolder,'\0');

			::SetDlgItemText( hDlg, IDC_INCORPTEXT, szHolder);

		
			lstrcpy(szHolder, pViewCtrl->loadString(IDS_WARNING_1));
			lstrcat(szHolder,	pViewCtrl->loadString(IDS_WARNING_2));
			lstrcat(szHolder,'\0');

					
			::SetDlgItemText( hDlg, IDC_WARNING,szHolder );

			::SetDlgItemText( hDlg, IDC_REPLABEL, pViewCtrl->loadString( IDS_REPLABEL ));
			::SetDlgItemText( hDlg, IDC_DATELABEL, pViewCtrl->loadString( IDS_DATELABEL ));
			// set report name and export date
			if ( pViewCtrl->m_pRepName )
				::SetDlgItemText( hDlg, IDC_REPNAME, pViewCtrl->m_pRepName );
			if ( pViewCtrl->m_pRepDate )
				::SetDlgItemText( hDlg, IDC_DATEEXPORT, pViewCtrl->m_pRepDate );

			//AMH 5/19/97 load the bitmap
			hBit = LoadBitmap(g_hInstance, // handle of application instance 
							  MAKEINTRESOURCE(IDB_BITMAP1)); 	// address of bitmap resource name 
		   		
			return TRUE;
		}

		case WM_DESTROY:
			{

			if(hBit)
				DeleteObject(hBit);
			return TRUE;

			}
	case WM_DRAWITEM:
			{
				UINT idCtl = (UINT) wParam;                           // control identifier 
				LPDRAWITEMSTRUCT lpDraw = (LPDRAWITEMSTRUCT) lParam; // item-drawing information 

				int nControlWidth = lpDraw->rcItem.right;   //width of control
				int nControlHeight = lpDraw->rcItem.bottom;	// height of control
				
				   
				BITMAP bmInfo ;

				GetObject( hBit,sizeof(bmInfo), &bmInfo);

				long	lBitmapWidth  = bmInfo.bmWidth;  // bitmap width
				long	lBitmapHeight = bmInfo.bmHeight; // bitmap height

				long	lStretchWidth  = nControlWidth;  //default control stretch width to control's predefined width
				long	lStretchHeight = nControlHeight;  //default control stretch height to control's predefined height


				lStretchWidth = (lBitmapWidth * nControlHeight) / lBitmapHeight; 

				if( !(lStretchWidth <=  nControlWidth))
					{
					
						lStretchHeight = (lBitmapHeight * nControlWidth) / lBitmapWidth;
				   
					}

				SetWindowPos(lpDraw->hwndItem,	// handle of window
							   HWND_TOP,	// placement-order handle
								0,	// horizontal position
								0,	// vertical position
								(int)lStretchWidth,	// width
								(int) lStretchHeight,	// height
								SWP_SHOWWINDOW | SWP_NOMOVE );	// window-positioning flags
				


									
				HDC dcMem = CreateCompatibleDC(lpDraw->hDC);

				if ( dcMem == NULL )
					return FALSE ;

				HGDIOBJ pBitmapOld = SelectObject (dcMem, hBit ) ;

				//if ( pBitmapOld == NULL )
				//	return FALSE;
		
				// draw the icon contents
				StretchBlt ( lpDraw->hDC,	 	// handle of destination device context
							0,// x-coordinate of upper-left corner of dest. rect.
							0, // y-coordinate of upper-left corner of dest. rect.
							lStretchWidth,// width of destination rectangle 
							lStretchHeight,	// height of destination rectangle 
							dcMem, // handle of source device context
							0,// x-coordinate of upper-left corner of source rectangle 
							0,// y-coordinate of upper-left corner of source rectangle  
							lBitmapWidth,// width of source rectangle 
							lBitmapHeight,// height of source rectangle
							SRCCOPY); // raster operation code

				DeleteDC(dcMem);

				return TRUE;
			}

		case WM_COMMAND:
			::EndDialog( hDlg, TRUE );
			return TRUE;
	}
	return FALSE;
} 

////////////////////////////////////////////////////////////////////////
// Display control properties dialog
void ViewCtrl::displayProperties( void )
{
	ModalDialog( TRUE );
	::DialogBoxParam( g_hInstance, MAKEINTRESOURCE( IDD_PROPERTIES ), m_hwnd,
		(DLGPROC)propDialog, (LPARAM)this );
	ModalDialog( FALSE );
}
