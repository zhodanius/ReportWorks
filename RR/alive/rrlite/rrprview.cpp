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
// Tweaked Microsoft base control framework source
//
//    Various routines that aren't in a file for a particular automation
//    object, and don't need to be in the generic ole automation code.
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/rrprview.cpv  $
// 
//    Rev 1.5   23 Feb 1998 14:59:18   smh
// Pushed VCL20001
// 
//    Rev 1.4.1.0   15 Jan 1998 11:53:24   smh
// Uncomment SafeForScripting for 151702.
// 
//    Rev 1.4   01 Apr 1997 15:52:10   smh
// latest sources on 4/1/97
// 
//    Rev 1.3   22 Mar 1997 19:56:26   smh
// Sources from 1/24/97
// 
//    Rev 1.2   19 Dec 1996 16:22:40   smh
// Added auto-comment header.
// 

#define INITOBJECTS		// define the descriptions for our objects

#include <tchar.h>
#include "IPServer.H"
#include "LocalSrv.H"
#include "LocalObj.H"
#include "CtrlObj.H"
#include "Globals.H"
#include "Util.H"
#include "Resource.H"
#include "rrvwctrl.H"
#include "cathelp.H"
#include <commctrl.h>

const IID IID_ICatRegister = {0x0002E012,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
const CATID CATID_SafeForScripting		= {0x7dd95801,0x9882,0x11cf,{0x9f,0xa9,0x00,0xaa,0x00,0x6c,0x42,0xc4}};
const CATID CATID_SafeForInitializing	= {0x7dd95802,0x9882,0x11cf,{0x9f,0xa9,0x00,0xaa,0x00,0x6c,0x42,0xc4}};

//=--------------------------------------------------------------------------=
// our Libid.  This should be the LIBID from the Type library, or NULL if you
// don't have one.
//
const CLSID *g_pLibid = &LIBID_RepViewObjects;


//=--------------------------------------------------------------------------=
// Localization Information
//
// We need the following two pieces of information:
//    a. whether or not this DLL uses satellite DLLs for localization.  if
//       not, then the lcidLocale is ignored, and we just always get resources
//       from the server module file.
//    b. the ambient LocaleID for this in-proc server.  Controls calling
//       GetResourceHandle() will set this up automatically, but anybody
//       else will need to be sure that it's set up properly.
//
const VARIANT_BOOL    g_fSatelliteLocalization =  FALSE;
LCID            g_lcidLocale = MAKELCID(LANG_USER_DEFAULT, SORT_DEFAULT);


//=--------------------------------------------------------------------------=
// your license key and where under HKEY_CLASSES_ROOT_LICENSES it's sitting
//
const WCHAR g_wszLicenseKey [] = L"";
const WCHAR g_wszLicenseLocation [] = L"";


WNDPROC g_ParkingWindowProc = NULL;

//=--------------------------------------------------------------------------=
// This Table describes all the automatible objects in your automation server.
// See AutomationObject.H for a description of what goes in this structure
// and what it's used for.
//
OBJECTINFO g_ObjectInfo[] = {
    CONTROLOBJECT(RepView),
    EMPTYOBJECT,
	EMPTYOBJECT
};

const char g_szLibName[] = _T( "RepView" );

//=--------------------------------------------------------------------------=
// IntializeLibrary
//=--------------------------------------------------------------------------=
// called from DllMain:DLL_PROCESS_ATTACH.  allows the user to do any sort of
// initialization they want to.
//
// Notes:
//
void WINAPI InitializeLibrary( void )
{
    // TODO: initialization here.  control window class should be set up in
    // RegisterClassData.
	::OleInitialize( NULL );	// kick off OLE for embedded objects
	::InitCommonControls();		// for toolbar at least
}

//=--------------------------------------------------------------------------=
// UninitializeLibrary
//=--------------------------------------------------------------------------=
// called from DllMain:DLL_PROCESS_DETACH.  allows the user to clean up anything
// they want.
//
// Notes:
//
void WINAPI UninitializeLibrary( void )
{
    // TODO: uninitialization here.  control window class will be unregistered
    // for you, but anything else needs to be cleaned up manually.
    // Please Note that the Window 95 DLL_PROCESS_DETACH isn't quite as stable
    // as NT's, and you might crash doing certain things here ...
	OleUninitialize();	//  free up OLE
}


//=--------------------------------------------------------------------------=
// CheckForLicense
//=--------------------------------------------------------------------------=
// users can implement this if they wish to support Licensing.  otherwise,
// they can just return TRUE all the time.
//
// Parameters:
//    none
//
// Output:
//    BOOL            - TRUE means the license exists, and we can proceed
//                      FALSE means we're not licensed and cannot proceed
//
// Notes:
//    - implementers should use g_wszLicenseKey and g_wszLicenseLocation
//      from the top of this file to define their licensing [the former
//      is necessary, the latter is recommended]
//
BOOL WINAPI CheckForLicense( void )
{
    // TODO: decide whether or not your server is licensed in this function.
    // people who don't want to bother with licensing should just return
    // true here always.  g_wszLicenseKey and g_wszLicenseLocation are
    // used by IClassFactory2 to do some of the licensing work.
    //
    return TRUE;
}

//=--------------------------------------------------------------------------=
// RegisterData
//=--------------------------------------------------------------------------=
// lets the inproc server writer register any data in addition to that in
// any other objects.
//
// Output:
//    BOOL            - false means failure.
//
// Notes:
//
BOOL WINAPI RegisterData( void )
{
	HRESULT hr;

	hr = CreateComponentCategory(CATID_SafeForScripting, L"Controls that are safely scriptable");
	hr = CreateComponentCategory(CATID_SafeForInitializing, L"Controls safely initializable from persistent data");
	hr = RegisterCLSIDInCategory(CLSID_RepView, CATID_SafeForScripting);
	hr = RegisterCLSIDInCategory(CLSID_RepView, CATID_SafeForInitializing);
    return TRUE;
}

//=--------------------------------------------------------------------------=
// UnregisterData
//=--------------------------------------------------------------------------=
// inproc server writers should unregister anything they registered in
// RegisterData() here.
//
// Output:
//    BOOL            - false means failure.
//
// Notes:
//
BOOL WINAPI UnregisterData( void )
{
	HRESULT hr;

	hr = UnRegisterCLSIDInCategory(CLSID_RepView, CATID_SafeForScripting);
	hr = UnRegisterCLSIDInCategory(CLSID_RepView, CATID_SafeForInitializing);
    return TRUE;
}

BOOL    WINAPI  CheckLicenseKey( LPWSTR wszCheckme )
{
	return TRUE;
}

BSTR    WINAPI  GetLicenseKey( void )
{
	return NULL;
}

#if 1
#pragma warning(disable:4229)  // anachronism used
//=--------------------------------------------------------------------------=
// CRT stubs
//=--------------------------------------------------------------------------=
// these two things are here so the CRTs aren't needed. this is good.
//
// basically, the CRTs define this to suck in a bunch of stuff.  we'll just
// define them here so we don't get an unresolved external.
//
// TODO: if you are going to use the CRTs, then remove this line.
//
extern "C" int __cdecl _fltused = 1;

extern "C" int _cdecl _purecall(void)
{
  FAIL("Pure virtual function called.");
  return 0;
}
#pragma warning(default:4229)  // anachronism used
#endif
