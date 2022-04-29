
#ifndef _ATTRIB_DLL_

	// Make a definition for this module.

#define _ATTRIB_DLL_


// C-language API functions for Attrib.dll


//extern "C"__declspec( dllexport ) BOOL ValidateLicenseInfo(int nFlagExe);

//extern "C"__declspec( dllexport ) BOOL ShowAboutBox(int nFlagExe);

//extern "C"__declspec( dllexport ) BOOL PASCAL ShowStartup(int nFlagExe);

//extern "C"__declspec( dllexport ) void GetAttrInfo(int nFlagExe, LPSTR szTitle, LPSTR szHelpAbout, LPSTR szHelpTopic);

//extern "C"__declspec( dllexport ) BOOL CloseStartup();


BOOL WINAPI PASCAL ValidateLicenseInfo(int nFlagExe);

BOOL WINAPI PASCAL ShowAboutBox(int nFlagExe,HWND hParentWnd);

BOOL WINAPI PASCAL PASCAL ShowStartup(int nFlagExe);

void WINAPI PASCAL  GetAttrInfo(int nFlagExe, LPSTR szTitle, LPSTR szHelpAbout, LPSTR szHelpTopic);

BOOL WINAPI PASCAL CloseStartup();

// literals

#define nDESIGNER	1	// flag used to specify that the attrib dll function is called from
						// the interactive report designer ( rsw.exe )

#define nVIEWER		2	// flag used to specify that the attrib dll function is called from
						// the report viewer (rswrun.exe )

#define nSHORTCUT	3   // flag used to specify that the attrib dll function is called from
						// the shortcut maker (rswicon.exe )

#define nRRDICTIONARY 4 // flag used to specify that the attrib dll function is called from
						// the dictionary builder (rrdict.exe )

#define nSCHEDULER	5	// flag used to specify that the attrib dll function is called from
						// the Event Scheduler (RRSched.exe & RRBGSch.exe)

#define  SZ_ATTRIBLIB           "RRATTRIB.DLL"

typedef BOOL (FAR PASCAL *LPFNATTRBVALLIC)(int);

typedef BOOL (FAR PASCAL *LPFNATTRBSHOWABX)(int,HWND);

typedef BOOL (FAR PASCAL *LPFNATTRBSHOWST)(int);

typedef void (FAR PASCAL *LPFNATTRBINFO)(int, LPSTR, LPSTR, LPSTR);

typedef BOOL (FAR PASCAL *LPFNATTRBCLOSE)();


#endif // _ATTRIB_DLL_

