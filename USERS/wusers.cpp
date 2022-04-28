// ****************************************************************************
//
//		(C) Copyright 1992-1994 Concentric Data Systems, Inc.
//						All Rights Reserved.
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
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   D:/R&R Project/archives/USERS/WUSERS.CPV  $
//
// Rev 1.13    16 Jun 2015 16:47:39   CAS
// Added another button to dialog:  Unlock ALL (IDOK2) that would allow
// the administrator to unlock all of the license keys that were
// currently locked.  Required adding an integer parameter to the 
// unlock() function so that it would know which button was pressed and
// whether to unlock 1 or ALL entries
// 
//    Rev 1.12   Oct 07 2002 11:14:24   Admin
// Only serial > 1,000,000
// 
//    Rev 1.11   Apr 25 2002 14:07:36   Admin
// Bug when both rrrw & rsw versions working
// 
//    Rev 1.10   Apr 23 2002 10:22:44   Admin
// Problem with ProductMode confusion
// 
//    Rev 1.9   Apr 19 2001 14:32:44   nhubacker
// No serial # < 900000
// 
//    Rev 1.8   17 Apr 1996 14:10:36   sjo
// I fixed a problem with unlock serial numbers.  We did not show the username
// properly.
// 
//    Rev 1.7   12 Apr 1996 11:39:44   pjm
// Pass parent handle to addSerial and deleteSerial for use in DialogBox
// call (so child dlg will be modal).
// 
//    Rev 1.6   11 Apr 1996 17:29:58   sjo
// Fixed a problem with trying to delete a serial number multiple times. The
// count came back from a Read call as bad.
// 
//    Rev 1.5   11 Apr 1996 11:38:26   sjo
// Changed the Unlock code due to a compiler warning.
// 
//    Rev 1.4   09 Apr 1996 13:02:26   sjo
// Fixed a problem with deleting bad serail numbers.
// 
//    Rev 1.2   06 Sep 1995 17:20:42   sjo
// 32 bit changes.
// 
//    Rev 1.1   11 Jul 1995 15:36:52   smh
// NOFILE -> NO_FILE b/c conflicted w/ NOFILE in product.
// 
//    Rev 1.0   16 Mar 1995 16:19:52   sbc
// Initial revision.
// 
//    Rev 1.7   18 Jan 1995 15:17:24   smh
// Allocate count+1 serial numbers because we store a zero in the
// last+1 array member.  Caused a GPF (after shipped).
// 
//    Rev 1.6   16 Dec 1994 15:32:54   smh
// Cast _frealloc return to a (STAT far *) to fix GPF.
// 
//    Rev 1.5   19 Oct 1994 11:37:26   smh
// Added space between serial number and user id in list box.
// 
//    Rev 1.4   28 Sep 1994 16:30:48   dlm
// Make include of product.h first include.
// 
//    Rev 1.3   22 Aug 1994 19:49:10   smh
// Combined the R?W User Management programs into one, and
// added support for DAT file upgrades for RSW.
// 
//    Rev 1.2   09 Jun 1994 14:31:12   smh
// Changed array of serial numbers from a global array to malloced memory.
// This is so increasing max number of serial numbers wouln't increase the
// EXE size.
// 
//    Rev 1.1   18 Oct 1993 17:33:00   smh
// Moved data definitions to _users.h.
// 
//    Rev 1.0   14 Oct 1993 10:49:52   smh
// Initial revision.
//				mjs 	8/3/92	No more RRWMULTI.DAT
//				smh 1/7/93	Edited for RSW
// ****************************************************************************
//
// Make a definition for this module.
//
#define _WUSERS_C_
#define WINVER 0x0400
#include "product.h"

#if defined (WIN32)
#include "windowsx.h"
#endif

#include <stdio.h>		// for sprintf
#include "_users.h"
#include <malloc.h>


// local statics
extern BOOL realloc_ulist(unsigned int count);
extern void report_error(LPSTR path);


int PASCAL WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
				LPSTR lpszCmdLine, int nCmdShow)
{
	int nResult;

   // Don't let another instance of this application execute.
   // TEMP if (hPrevInstance != NULL) return(0);

	_hInstance = hInstance;

	init();
	// Might as well end it right here if DAT file not found
	if (!ProductMode)
	{
		char justpath[WINPATHLEN+1], *ch;
		strcpy(justpath,DatPath);
		if ((ch = strrchr(justpath,'\\')) || (ch = strrchr(justpath,':')))
			*ch = 0;
		zack2(getIdString(ID_NOTFOUND,0),justpath);
		return(0);
	}

//	if (!(UserList = (STAT far *)_fmalloc(sizeof(STAT) * (MAXENTRIES+1))))
//		zack(getIdString(ID_NOMEM,0));
//	else 
//	{
		do
		{
		// Create the main dialog box.
#if defined (WIN32)
			nResult = DialogBox(hInstance, MAKEINTRESOURCE(DLG_MAIN),
				(HWND)NULL, (DLGPROC)MainDlgProc);
#else
			FARPROC fpProc;
		
			fpProc = MakeProcInstance((FARPROC)MainDlgProc, hInstance);

			nResult = DialogBox(hInstance, MAKEINTRESOURCE(DLG_MAIN),
				(HWND)NULL, (DLGPROC)fpProc);
			FreeProcInstance(fpProc);
#endif
		
		}
		while (nResult != IDCANCEL);
		
		if (UserList)
			_ffree (UserList);	// Release memory
//	}

	return(0);
}

int checkSerialNumber ( char *pUserSerialNumber )
{
	int 	u, iActualSize;
	char	szLocalSerialNumber[MAX_SERIAL_LEN+1] ;
	char	*pszSerialNumber ;
	// We need to check the serial number and make it our own....

	szLocalSerialNumber[0] = '\0' ;

	iActualSize = 0;
	for (u=0, pszSerialNumber=pUserSerialNumber ; 
	     iActualSize < MAX_SERIAL_LEN && *pszSerialNumber ; 
	     pszSerialNumber++, u++)
	{
		int		iNotDivByFour, iIsDash ;

		iNotDivByFour = u%4 ;
		iIsDash = *(char *)pszSerialNumber=='-' ;

		if ( u== 0 || iNotDivByFour  )
		{
			// iActualSize keeps track of how long szLocalSerialNumber is.
			// We could do this a number of ways, I just feel like counting...
			iActualSize++;
			strncat ( szLocalSerialNumber, pszSerialNumber , 1 ) ;
		}
		else
		{
			// If we are divisible by four, its time to stick a dash in.
			//  If we have one (a dash), bumb past it and get the next num.

			strcat  ( szLocalSerialNumber, "-" ) ;
			iActualSize++;

			if ( iIsDash )
				pszSerialNumber ++;

			if (*pszSerialNumber)
			{	// I think this check is unnecessary, but I think its a good idea
				// to look
				strncat ( szLocalSerialNumber, pszSerialNumber , 1 ) ;
			 	iActualSize++;
			}
		}
	}

	strncpy (_szGoldSerialNumber, szLocalSerialNumber, sizeof(_szGoldSerialNumber));
	return FALSE ;
}

BOOL CALLBACK MainDlgProc (HWND hDlg, UINT wMsg, WPARAM wParam, LPARAM lParam)
{

	BOOL fProcessed = TRUE;
	RECT rc;
	WORD nIndex;	// sjo - nIndex will remain WORD (ie 16bits)

	switch (LOWORD(wMsg))	// Should work in 16bit...
	{
		case WM_INITDIALOG:
			// Fill list box with serial numbers and user ids.
			_hDlgMain = hDlg;
			SetWindowText(hDlg,ProductMode==MODE_RRW ? _szAppNameX : _szAppNameS);
			SendDlgItemMessage(_hDlgMain, ID_LIST, LB_SETTABSTOPS, 1, (LONG)(LPSTR)_TabStops);
			// fillListBox(0);	mjs 4/22/93  Bug #672
			if (!fillListBox(0))
//#if defined(RSW)
//			{	EndDialog(hDlg, IDCANCEL);	break;	}
//#else

				SendMessage (hDlg, WM_COMMAND, IDCANCEL, 0L);
//#endif
			// Center the dialog box.
			GetWindowRect(hDlg, &rc);
			SetWindowPos(hDlg, (HWND)NULL,
				(GetSystemMetrics(SM_CXSCREEN) - (rc.right - rc.left)) / 2,
				(GetSystemMetrics(SM_CYSCREEN) - (rc.bottom - rc.top)) / 3,
				0, 0, SWP_NOSIZE | SWP_NOZORDER);

			// Set up a timer to check the dat file every 5 seconds.
			fileTime();
			SetTimer(hDlg, 1, 5000, NULL);
			break;

		case WM_TIMER:
			if (!fileTime())	//	Has the dat file changed?
				break;

			nIndex = (WORD)SendDlgItemMessage(hDlg, ID_LIST, LB_GETCURSEL, 0, 0L);
			fillListBox(nIndex);
			break;

		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
				case IDOK:
					// Rev 1.13
					unlock(0);
					break;

				case IDOK2:
					// Rev 1.13
					unlock(1);
					break;

				case ID_ADD:
					serialAdd(hDlg);
					break;

				case ID_DELETE:
					serialDelete(hDlg);
					break;

				case IDCANCEL:
					KillTimer(hDlg, 1);
					EndDialog(hDlg, wParam);
					break;

				case ID_LIST:

#if defined (WIN32)
					switch (HIWORD (wParam))
#else
					switch (HIWORD (lParam))
#endif
					{
						case LBN_DBLCLK:
							// Same as pressing Unlock button.

							SendMessage (hDlg, WM_COMMAND, IDOK, 0L);
							break;

						default:
							break;
					}
					break;
			}
			break;

		default:
			fProcessed = FALSE;
			break;
	}
	return(fProcessed);
}

BOOL CALLBACK SerialNumDlgProc (HWND hDlg, UINT wMsg, WPARAM wParam, LPARAM lParam)
{
	BOOL fProcessed = TRUE;
	RECT rc;

	switch (wMsg)
	{
		case WM_INITDIALOG:
			//	Set up the title with "Add" or "Delete".
			SetWindowText(hDlg, getIdString(_wTitle,0));
			// Center the dialog box.
			GetWindowRect(hDlg, &rc);
			SetWindowPos(hDlg, (HWND)NULL,
				(GetSystemMetrics(SM_CXSCREEN) - (rc.right - rc.left)) / 2,
				(GetSystemMetrics(SM_CYSCREEN) - (rc.bottom - rc.top)) / 3,
				0, 0, SWP_NOSIZE | SWP_NOZORDER);

			break;
		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
				case IDOK:
			
					SendDlgItemMessage(hDlg, ID_SERIALNUMBER, WM_GETTEXT, sizeof(_szSerialNumber), 
									   (LPARAM)((LPCSTR) _szSerialNumber));


					EndDialog(hDlg, wParam);
					break;

				case IDCANCEL:
					EndDialog(hDlg, wParam);
					break;
			}
			break;

		default:
			fProcessed = FALSE;
			break;
	}
	return(fProcessed);
}

#if !defined (WIN32)
BOOL CALLBACK DiskDlgProc (HWND hDlg, UINT wMsg, WPARAM wParam, LPARAM lParam)
{

	BOOL fProcessed = TRUE;
	RECT rc;
	WORD nIndex;

	switch (wMsg)
	{
		case WM_INITDIALOG:
			//	Set up the title with "Add" or "Delete".
			SetWindowText(hDlg, getIdString(_wTitle,0));

			// Fill list box with list of disks; select first one.
			SendDlgItemMessage(hDlg, ID_DISK, LB_DIR,  0x4000|0x8000, (LPARAM)((LPCSTR)"*"));
			SendDlgItemMessage(hDlg, ID_DISK, LB_SETCURSEL,    0, 0L);

			// Center the dialog box.
			GetWindowRect(hDlg, &rc);
			SetWindowPos(hDlg, (HWND)NULL,
				(GetSystemMetrics(SM_CXSCREEN) - (rc.right - rc.left)) / 2,
				(GetSystemMetrics(SM_CYSCREEN) - (rc.bottom - rc.top)) / 3,
				0, 0, SWP_NOSIZE | SWP_NOZORDER);

			break;

		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
				case IDOK:
					nIndex = (WORD)SendDlgItemMessage(hDlg, ID_DISK, LB_GETCURSEL, 0, 0L);
					if (nIndex == -1) nIndex = 0;
					SendDlgItemMessage(hDlg, ID_DISK, LB_GETTEXT, nIndex, (LPARAM)((LPCSTR)_szDisk));
					EndDialog(hDlg, wParam);
					break;

				case IDCANCEL:
					EndDialog(hDlg, wParam);
					break;
			}
			break;

		default:
			fProcessed = FALSE;
			break;
	}
	return(fProcessed);
}

#endif

static void serialAdd(HWND hParent)
{
#if 0
	register int dr;
	register int res;
	int		handle /*,lanpak*/;
	char 	serno[SER_BYTES];
	char 	path1[100]  /*,path2[100]*/ ;
	BOOL 	trip = FALSE;
#endif
	BOOL 	trip = FALSE;
	BOOL	res;
	char 	serno[9];

	int		nResult;
	int		count;


	_wTitle = ID_ADDWINTITLE ;

	nResult = DialogBox(_hInstance, MAKEINTRESOURCE(DLG_SERIALNUMBER),
		hParent, (DLGPROC)SerialNumDlgProc);

	if (nResult != IDCANCEL && _szSerialNumber[0] )
	{
		// Verify the serial number.  checkSerialNumber will verify that the user typed in a good
		//   serial number and convert it to a form that we like (NNNN-NNNN-NNNN-NNNN)

		if ( checkSerialNumber ( &_szSerialNumber[0] ))
		{
			zack(getIdString(ID_INVALIDSERNO,0));
		} 

		if ((count = ComputeCount ( _szGoldSerialNumber )) == 0 ) 
		{
			// We have a bad serial number
			zack(getIdString(ID_INVALIDSERNO,0));
		}

		strncpy( serno  , _szGoldSerialNumber,   4 );		// copy WWWW
		strncpy( serno+4, _szGoldSerialNumber+5, 4 );		// append XXXX 

		int 	iserno ;
		iserno = atoi( serno );		// convert to integer
		if (iserno < 1100000)
		{
			zack(getIdString(ID_INVALIDSERNO,0));
			return ;
		}


#if 0
	if (dr = getdrive())
	{
		sprintf(path1,"%c:\\%s",dr,ProductMode==MODE_RRW ? dat_fileX : dat_fileS);
		AnsiUpper(path1);
		// sprintf(path2,"%c:\\%s",dr,dat_file_2);
		// AnsiUpper(path2);
		// if ((lanpak = readser(path1,serno)) && readser(path2,serno))
		if (readser((LPSTR)path1,(LPSTR)serno))
			report_error((LPSTR)path1);
//			zack2(getIdString(ID_READERR,0),path1);
		else
		{ /* check users file */
			// if ((!lanpak && (SerCount == 1)) || (lanpak &&
			//	((~SerCount << 3) == (CheckWord & 0xFFF8))))
			if ((DatFile.count == 1) || 
				(((~(DatFile.count) << 3) & 0xFFFF) == (CheckWord & 0xFFF8)) )
			{
				// count = lanpak ? SerCount : 1;
				count = DatFile.count;
#endif
				while (count--)
				{ /* loop for lan pack */
					if ((res = findser((LPSTR)DatPath, iserno)) == 0)
					{ /* not already there */
						if (!(writeser((LPSTR)DatPath, iserno)))
						{
							zack(getIdString(ID_WRITEERR,0));
							break;
						}
					}
					else
					{  	//	The serial number we are trying to add was found!  
						// if (res > 0)	Always stop here.
						if (res > 0)
						{	
							// found
							if (!trip)
							{
								char	tempChar[SER_BYTES+1];
								wsprintf(tempChar, "%d", iserno);
								zack2(getIdString(ID_GOTUSER,0),tempChar);
								trip = TRUE;
							}
							
						}
						else
						{
							// error (file closed in findser())
							zack2(getIdString(ID_READERR,0),DatPath);
							break;		  /* just forget it */
						}
					} // end else

					iserno++;
				} // end while

		// Set focus on the first one we added.
		count = (int)SendDlgItemMessage(_hDlgMain, ID_LIST, LB_GETCOUNT, 0, 0L);
		fillListBox(count);
		} // end if not cancel
}

static void serialDelete(HWND hParent)
{
#if 0
	register int dr;
	int count,handle /*,lanpak*/ ;
	char path1[100] /*,path2[100]*/ ;
	int ret;
#endif
	int nResult;
	int count, oneNum;
	unsigned long 	numread ;

	char full[USE_BYTES];
	char serno[9];

	_wTitle = ID_DELWINTITLE ;

	nResult = DialogBox(_hInstance, MAKEINTRESOURCE(DLG_SERIALNUMBER),
		hParent, (DLGPROC)SerialNumDlgProc);
	if (nResult != IDCANCEL && _szSerialNumber[0] )
	{
		// Verify the serial number.  checkSerialNumber will verify that the user typed in a good
		//   serial number and convert it to a form that we like (NNNN-NNNN-NNNN-NNNN)

		if ( checkSerialNumber ( &_szSerialNumber[0] ))
		{
			zack(getIdString(ID_INVALIDSERNO,0));
			return;
		} 

		if ((count = ComputeCount ( _szGoldSerialNumber )) == 0 ) 
		{
			// We have a bad serial number
			zack(getIdString(ID_INVALIDSERNO,0));
			return;
		}

		strncpy( serno  , _szGoldSerialNumber,   4 );		// copy WWWW
		strncpy( serno+4, _szGoldSerialNumber+5, 4 );		// append XXXX 

		int 	iserno ;
		iserno = atoi( serno );		// convert to integer

		HANDLE 	hFile ;

		if (!opendat( DatPath, &hFile))
		{
			zack(getIdString(ID_DELERR,0));
			return;
		}

		int NumLeft = count;

		// get count and set file pointer to first record
		if ( (SetFilePointer( hFile, SER_COUNT, NULL, FILE_BEGIN ) == 0xFFFFFFFF ) ||
			  (!ReadFile( hFile, &count, 2, &numread, NULL )) ||
			  (numread != 2 ) ||
			  (SetFilePointer( hFile, START_REC, NULL, FILE_BEGIN ) == 0xFFFFFFFF ))
		{
			CloseHandle( hFile );
			zack(getIdString(ID_DELERR,0));
			return;
		}

		while (count-- && (NumLeft > 0))
		{ /* loop for lan pack */
			if ( (SetFilePointer( hFile, SERIAL, NULL, FILE_CURRENT ) == 0xFFFFFFFF ) ||
				  (!ReadFile( hFile, &oneNum, 4, &numread, NULL )) ||
				  (numread != 4 ))
			{
				CloseHandle( hFile );
				zack(getIdString(ID_DELERR,0));
				return;
			}
			
			if (oneNum == iserno)
			{	// Found it 
			 	unsigned long 	rwcount;

			 	if ( (SetFilePointer( hFile, -SZ_PER_SER, NULL, FILE_CURRENT ) == 0xFFFFFFFF ) ||
					 (!WriteFile( hFile, &full, USE_BYTES, &rwcount, NULL )) ||
	 			  	 ( rwcount != USE_BYTES ) ||
					 (!WriteFile( hFile, &Empty, SER_BYTES, &rwcount, NULL )) ||
					 ( rwcount != SER_BYTES ) )
				{
					zack(getIdString(ID_WRITEERR,0));
					break;
				}
				iserno++;
				NumLeft--;
			}

		} // end while
		
		CloseHandle( hFile );
		if (NumLeft != 0)
		{
			// Not there
			zack(getIdString(ID_DELERR,0));
		}
 
	}
	fillListBox (0) ;

#if 0

	memset(full,0xFF,USE_BYTES);
	if (dr = getdrive())
	{
		sprintf(path1,"%c:\\%s",dr,ProductMode==MODE_RRW ? dat_fileX : dat_fileS);
		AnsiUpper(path1);
		// sprintf(path2,"%c:\\%s",dr,dat_file_2);
		// AnsiUpper(path2);
		// if ((lanpak = readser(path1,serno)) && readser(path2,serno))
		if (readser((LPSTR)path1,(LPSTR)serno))
			report_error((LPSTR)path1);
		else
		{ /* open and check user file */
			if ( (DatFile.count == 1) || 
				 (((~(DatFile.count) << 3) & 0xFFFF) == (CheckWord & 0xFFF8)))
			{
				count = DatFile.count;
				while (count--)
				{ /* loop for lan pack */
					if ((ret = findser((LPSTR)DatPath,(LPSTR)serno,(HFILE far *)&handle)) != -1)
					{
						if (!ret)  _lclose(handle);

						zack(getIdString(ID_DELERR,0));
						break;
					}	// mjs 10/21/92  Bug #535
					else
					{ /* found, mark as deleted */
						if ((_llseek(handle,(long)-SZ_PER_SER,SEEK_CUR) == -1L) ||
								(_lwrite(handle,full,USE_BYTES) != USE_BYTES) ||
								(_lwrite(handle,Empty,SER_BYTES) != SER_BYTES))
							zack(getIdString(ID_WRITEERR,0));
					}
					_lclose(handle);
					flipinc(serno);
				}
			}
			else
				zack2(getIdString(ID_READERR,0),/*lanpak ? path2 :*/ path1);
		}
		fillListBox(0);
	}
#endif
}

//static void unlock(void)
static void unlock(int iAction)
{
	// Since we already know which one the user wants to unlock,
	// we need only seek to it and overwrite it.

	int i;
	WORD 	nIndex;
	int		iSerialNumber;

	if (iAction == 0)
	{
		nIndex = (WORD)SendDlgItemMessage(_hDlgMain, ID_LIST, LB_GETCURSEL, 0, 0L);
		if (nIndex == -1)
			return;

		// Is this serial number already unlocked?
		if (!*((UserList+nIndex)->id)) return;

		iSerialNumber=(int)(UserList+nIndex)->sno.sn;

		unlockser((LPSTR)DatPath, iSerialNumber );
	}
	if (iAction == 1)
	{
		for (i = 0; i < DatFile.count; i++)
			if (*((UserList + i)->id))
			{
				iSerialNumber = (int)(UserList + i)->sno.sn;
				unlockser((LPSTR)DatPath, iSerialNumber);
			}
	}
	fillListBox(0);
}


static void dispusers(STAT far * users, int cnt)
{
	register int i;
	char szBuffer[SERIAL+USE_BYTES+10];		// need room for space between
	int usecnt = 0;

	for (i = 0; i < cnt; i++)
	{
		if ((users+i)->sno.sn)
		{
		  //  Tab between serial number and user.
			wsprintf(szBuffer, "%-20ld%-15s", (LPSTR)(users+i)->sno.sn,
				*((users+i)->id) ? (LPSTR)(users+i)->id : (LPSTR)getIdString(ID_INACTIVE,0));
			SendDlgItemMessage(_hDlgMain, ID_LIST, LB_ADDSTRING, 0, (LONG)(LPSTR)szBuffer);
			if (*((users+i)->id)) usecnt++;
		}
		else
			break;		  /* done */
	}

	// Display the total users and those in use.
	wsprintf(szBuffer, "%d", (LONG)cnt);
	SetDlgItemText(_hDlgMain, ID_TOTAL, szBuffer);
	wsprintf(szBuffer, "%d", (LONG)usecnt);
	SetDlgItemText(_hDlgMain, ID_INUSE, szBuffer);
}


static BOOL fillListBox(WORD wSelect)
{
	int i;
	HANDLE	fhandle;
//	char rec[SZ_PER_SER];
	WORD wTop;
	int		oneNum;
	unsigned long 	numread ;
	DATHEAD 	DatFile ;
	
	wTop = (WORD)SendDlgItemMessage(_hDlgMain, ID_LIST, LB_GETTOPINDEX, 0, 0L);
	SendDlgItemMessage(_hDlgMain, ID_LIST, LB_RESETCONTENT, 0, 0L);

	if (!opendat( DatPath, &fhandle))
	{
		return(FALSE);
	}

	// get count and set file pointer to first record

	if ( (SetFilePointer( fhandle, 0, NULL, FILE_BEGIN ) == 0xFFFFFFFF ) ||
		  (!ReadFile( fhandle, &DatFile, 4, &numread, NULL )) ||
		  (numread != 4 ) ||
		  (SetFilePointer( fhandle, START_REC, NULL, FILE_BEGIN ) == 0xFFFFFFFF ))

	{
		CloseHandle( fhandle );
		return(FALSE);
	}


	if (!realloc_ulist(DatFile.count))
	{
		CloseHandle ( fhandle );
		return( zack(getIdString(ID_NOMEM,0)) );
	}

	int 	cnt = 0;

	for (i = 0; i < DatFile.count; i++)
	{
		char rec [USE_BYTES+1];
		if ( !ReadFile ( fhandle, &rec, USE_BYTES, &numread, NULL) ||
			numread != USE_BYTES)
		{
			CloseHandle( fhandle );
			return(FALSE);
		}

		if (  (!ReadFile( fhandle, &oneNum, 4, &numread, NULL )) ||
			  (numread != 4 ))
		{
			CloseHandle( fhandle );
			return(FALSE);
		}
		if ( oneNum )
		{	// If not deleted
			UserList[cnt].sno.sn = oneNum;
			memmove(UserList[cnt].id,(char *)rec,USE_BYTES);
			cnt++;

		}
	}

	CloseHandle( fhandle );
	dispusers(UserList,cnt);
	SendDlgItemMessage(_hDlgMain, ID_LIST, LB_SETTOPINDEX, wTop, 0L);
	if (wSelect != -1)
		SendDlgItemMessage(_hDlgMain, ID_LIST, LB_SETCURSEL, wSelect, 0);

	// Sync file time.
	memset(_lasttime, 0, 4);
	fileTime();

	return TRUE;

#if 0

	for (i = 0; i < (WORD) (DatFile.count); i++)
		{
			if (!ReadFile (fhandle,SZ_PER_SER) != SZ_PER_SER)
			{	// unexpanded DAT file
				_lclose(fhandle);
				return(zack2(getIdString(ID_NOTEXP,0),DatPath));
			}
			if (*(long *)(&rec[SERIAL]))
			{ /* if not deleted */
// not swapped in Ver 7.0
				UserList[cnt].sno.snc[0] = rec[SERIAL];
				UserList[cnt].sno.snc[1] = rec[SERIAL + 1];
				UserList[cnt].sno.snc[2] = rec[SERIAL + 2];
				UserList[cnt].sno.snc[3] = rec[SERIAL + 3];
				_fmemmove(UserList[cnt++].id,(char far *)rec,USE_BYTES);
			}
		}
		_lclose(fhandle);
		UserList[cnt].sno.sn = 0;
	}
#endif

	dispusers(UserList,DatFile.count);
	SendDlgItemMessage(_hDlgMain, ID_LIST, LB_SETTOPINDEX, wTop, 0L);
	if (wSelect != -1)
		SendDlgItemMessage(_hDlgMain, ID_LIST, LB_SETCURSEL, wSelect, 0);

	// Sync file time.
	memset(_lasttime, 0, 4);
	fileTime();
	return TRUE;
}

static void init(void)
{
	int i;
	OFSTRUCT of;
	char linkpath[WINPATHLEN+1];

#if defined(RSW)
	ProductMode = MODE_RSW ;
#else
	ProductMode = MODE_RRW ;
#endif

	// strcpy(DatPath,argv[0]); /* get execution path and remove file name */
	GetModuleFileName(_hInstance, (LPSTR)DatPath, WINPATHLEN+1);

	for (i = strlen(DatPath); i > 0; i--)
	{
		if (DatPath[i] == '\\')
			break;
	}
	DatPath[i+1] = 0;

	strcpy(linkpath,DatPath);
	if (linkpath[strlen(linkpath)-1] != '\\')
		strcat(linkpath,"\\");
	/* handle link file, if any */

#if !defined(RSW)
	// look for rrwlink.ini
	strcat(linkpath,link_fileX);
	if (OpenFile(linkpath, &of, OF_EXIST) != -1)  // there's an rrwlink.ini
	{
		GetPrivateProfileString((LPSTR)_LinkDirX,(LPSTR)_LinkDirX,(LPSTR)DatPath,
			(LPSTR)DatPath,WINPATHLEN,(LPSTR)linkpath);
		AnsiUpper(DatPath);
	}
#else
	// look for rswlink.ini
	strcat(linkpath,link_fileS);
	if (OpenFile(linkpath, &of, OF_EXIST) != -1)  // there's an rrwlink.ini
	{
		GetPrivateProfileString((LPSTR)_LinkDirS,(LPSTR)_LinkDirS,(LPSTR)DatPath,
			(LPSTR)DatPath,WINPATHLEN,(LPSTR)linkpath);
		AnsiUpper(DatPath);
	}
#endif

	if (DatPath[strlen(DatPath)-1] != '\\')
		strcat(DatPath,"\\");

	// path to the license file
#if !defined(RSW)
	strcat(DatPath,dat_fileX);
#else
	strcat(DatPath,dat_fileS);
#endif

	memset(Empty,'\0',USE_BYTES);
}


static BOOL zack(LPSTR format)
{
	HWND hWnd = _hDlgMain;
	char s[200];
	LPSTR title = ProductMode == MODE_RRW ? _szAppNameX : 
						ProductMode == MODE_RSW ? _szAppNameS : _szAppName;

	MessageBeep(MB_ICONHAND);
	wsprintf((LPSTR)s,(LPSTR)format);
	MessageBox(hWnd,s,title,MB_OK|MB_ICONSTOP);

	return FALSE;
}


static BOOL zack2(LPSTR format,LPSTR a)
{
	HWND hWnd = _hDlgMain;
	char s[200];
	LPSTR title = ProductMode == MODE_RRW ? _szAppNameX : 
						ProductMode == MODE_RSW ? _szAppNameS : _szAppName;

	MessageBeep(MB_ICONHAND);
	wsprintf((LPSTR)s,(LPSTR)format,(LPSTR)a);
	MessageBox(hWnd,s,title,MB_OK|MB_ICONSTOP);

	return FALSE;
}


static LPSTR getIdString(WORD id,int buf)			// read a string
{
	static char strbuf[2][WINSTRLEN+1]; 	// must be static

	if ((buf >= 0) && (buf <= 1))
		LoadString(_hInstance,id,(LPSTR)strbuf[buf],WINSTRLEN);
	return (strbuf[buf]);
}


static BOOL fileTime(void)
{
	static OFSTRUCT ofDat;

	//	This should return an error if date in ofDat.reserved is not current.
	if (OpenFile(DatPath, &ofDat, OF_EXIST|OF_READ|OF_VERIFY) == HFILE_ERROR)
		return TRUE;

	// Time change?
#if defined (WIN32)
	// Reserved OFS members are labelled 'do not use' - we need to find
	//  another way to get the time.
	if (memcmp(&ofDat.Reserved1, _lasttime, 4) == 0)
#else
	if (memcmp(&ofDat.reserved, _lasttime, 4) == 0)
#endif
		return FALSE;

	// Time changed.  Remember it.
#if defined (WIN32)
	memcpy(_lasttime, &ofDat.Reserved1, 4);
#else
	memcpy(_lasttime, &ofDat.reserved, 4);
#endif
	return TRUE;
}

static BOOL realloc_ulist(unsigned int count)
{
	// alloc or realloc
	if (UserList)
	{
		if (!(UserList = (STAT far *)_frealloc ((void far *)UserList,sizeof(STAT) * (count+1))))
			return(FALSE);	// bad
	}
	else if (!(UserList = (STAT far *)_fmalloc(sizeof(STAT) * (count+1))))
		return(FALSE);	// bad
	return(TRUE);
}

static void report_error(LPSTR path)
{
	LPSTR text = path ? path : DatPath;

	// Strip the file off the path. 
	// If not found, DatPath will be RSW and may be looking for RRW.
	char justpath[WINPATHLEN+1], *ch;

	lstrcpy((LPSTR)justpath,text);
	if ((ch = strrchr(justpath,'\\')) || (ch = strrchr(justpath,':')))
		*ch = 0;

	switch (Status)
	{
		case NO_FILE:
			zack2(getIdString(ID_NOTFOUND,0),justpath);
			break;
		case BADREV:	
		case LOCKED:
			zack2(getIdString(ID_BADVER,0),text);
			break;
		case BADPROD:	
			zack2(getIdString((WORD)(ProductMode==MODE_RRW ? ID_BADXREV : ID_BADSREV),(int) 0),	text);
			break;
		case BADREAD:
		default:
			zack2(getIdString(ID_READERR,0),text);
			break;
	}
}
