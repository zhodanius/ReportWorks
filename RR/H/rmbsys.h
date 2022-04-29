/* $Header:   H:/vcsmfc/h/rmbsys.h_v   1.1   08 Oct 1996 16:50:02   amh  $ */
/*************************************/
/* (c) 1989, Wall Data, Incorporated */
/*************************************/

#ifndef _RMBSYS_H_
#define _RMBSYS_H_

/*---------------------------------------------------------------------------*/



/*--------------------------------------------------------------------------*/
/* Pragmas.                                                   */
/*--------------------------------------------------------------------------*/
/*
  ALL nonstandard extension warnings suppressed.
  The primary motivation for this is to allow new style comments at
   warning level 4. Note that the resource compiler doesn't accept pragmas.
*/

#if !defined( RC_INVOKED )
#if !defined( __cplusplus )
#pragma warning( disable : 4001 )
#endif
#pragma warning( disable : 4201 )
#pragma warning( disable : 4214 )
#pragma warning( disable : 4209 )
#pragma warning( disable : 4699 )	// Using precompiled header
#pragma warning( disable : 4514 )	// Unreferenced inline functions.
#if defined( WIN32 ) || defined( W32 )
#pragma warning( disable : 4226 )
#endif /* WIN32 || W32 */
#endif /* RC_INVOKED */



/*---------------------------------------------------------------------------*/
/* Includes                                                                  */
/*---------------------------------------------------------------------------*/

#if !defined( STRICT )
#define STRICT
#endif

#if defined( INC_OLE2 )   // scj
  // 'IsEqualGUID' & '!=': unreferenced inline functions
#if defined( W32 )
  #pragma warning (disable: 4514)
#else
  #pragma warning (disable: 4505)
#endif
#else
  #define INC_OLE1
#endif

//dwhanger,24.1.95,mfc-ing
#if defined( USING_MFC ) || ( _AFXDLL )
  #if defined( W16 )
    #define     PVOID
    #include    <stdafx.h>
    #undef      PVOID
  #elif defined( W32 )
    #include    <stdafx.h>
    #include    <ddeml.h>
    #include    <mmsystem.h>
  #endif
#else
  #include      <windows.h>
#endif

#if !defined( LVM_FIRST )
  // this can go away when everyone is using 2.1/1.51
  #include <WDWin95.h>
#endif

#include    <windowsX.h>
#if defined( W16 )
#include   <W16Extra.H>
#endif
#include   <Dde.H>
#include   <stdlib.h>


/*---------------------------------------------------------------------------*/
/* Misc
/*---------------------------------------------------------------------------*/
#if defined( W16 )
#if !defined( __int16 )
#define	__int16	short
#endif // __int16
#endif // W32

// These have been defined here so that NTG code will work properly when the headers
// are included ( and process.hpp is not ).
#if !defined( MFPRV )
#if defined( WIN32 )
#define MFPRV
#else
#define MFPRV	NEAR PASCAL
#endif
#endif

#if !defined( MFPRO )
#if defined( WIN32 )
#define MFPRO	
#else
#define MFPRO	FAR PASCAL
#endif
#endif

#if !defined( MFPUB )
#if defined( WIN32 )
#define MFPUB	
#else
#define MFPUB	FAR PASCAL
#endif
#endif

#if !defined( MFEXPORT )
#if defined( WIN32 )
#define MFEXPORT	__declspec( dllexport )
#else
#define	MFEXPORT	__export FAR PASCAL
#endif
#endif

#if !defined( MFIMPORT )
#if defined( WIN32 )
#define MFIMPORT	__declspec( dllimport )
#else
#define MFEXPORT	__export FAR PASCAL
#endif
#endif

#if !defined( DEBUG_CLASS )
#define DEBUG_CLASS( x )
#endif



/*---------------------------------------------------------------------------*/
/* DLL export macros - use to export funcs from a DLL (avoids name-mangling) */
/*---------------------------------------------------------------------------*/
#if !defined( WDPUB )
#if defined( WIN32 )
#define WDPUB	
#else
#define WDPUB	FAR PASCAL
#endif
#endif

#if !defined( WD_DLLEXPORT )
#if defined( WIN32 )
#define WD_DLLEXPORT	__declspec( dllexport )
#else
#define	WD_DLLEXPORT	__export FAR PASCAL
#endif
#endif

/*---------------------------------------------------------------------------*/
/* This section contains some items which formerly were found in WDWINDOWS.h.
/*---------------------------------------------------------------------------*/

/* INT is defined as a replacement for WORD.
  WORD is defined in windows.h to be a 16 bit unsigned value.
  It had been used extensively in arithmetic expressions, causing
  compiler warnings, so (mostly) all instances of WORD have been
  replaced with INT. The usage of INT rather than int was motivated
  by a desire to have a way to identify these changes if a need to back out
  was discovered.
*/

#define INT   int

#if defined( W16 )
  #ifndef LPUINT
    typedef UINT far *LPUINT;
  #endif

  #ifndef LPBOOL
    typedef BOOL far *LPBOOL;
  #endif
#endif

#define REGISTER register

#if !defined( WIN32 ) && !defined( W32 )
#if !defined( MAKEWORD )
#define MAKEWORD( LByte, HByte ) ((((WORD) HByte) << 8) | LByte)
#endif
#endif

//  MAKEINT is an artifact of the change from WORD to INT
#define MAKEINT( LByte, HByte ) ((((INT) HByte) << 8) | LByte)

// define macro ENABLEMENUITEM for with/without Tool Bar
#define WDENABLEMENUITEM( hwnd, hm, id, flag ) \
	tbEnableMenuItem( hwnd, hm, id, flag )


// used in Capture.Dlg
#define _34_37_           34
#define _41_44_           41
#define _104_101_         104

// used in hotspot.dlg
#define _168_172_         168
#define _90_98_           90

// used in macro.dlg
#define _107_104_         107


#if !defined( UNUSED )
#define UNUSED(p)               (p = p)
#endif

// Casts used for differences between W32 and W16.  These casts are necessary in certain
// cases when compiling for the PPC because the PPC compiler does not support
// internal int to long casting.
#if defined( W32 )
#define PLATFORMCAST( x )       \
		(long)( x )
#else
#define PLATFORMCAST( x )       \
		(int)( x )
#endif

#define PALETTERGB_COLOR( x )	\
		PALETTERGB( GetRValue( x ), GetGValue( x ), GetBValue( x ) )

/*--------------------------------------------------------------------------*/
/* Portable KERNEL for WIN32                                                */
/*--------------------------------------------------------------------------*/
//dwhanger,15.12.94, allow these macros to be def'd for WIN16 too!
#define LockMemory( m )         ((VOID FAR *) GlobalLock( (HGLOBAL) (m) ))
#define UnlockMemory( m )       (GlobalUnlock( (HGLOBAL) (m) ))

#if defined( WIN32 ) || defined( W32 )

#define LockData( Dummy )
#define UnlockData( Dummy )

/* These two function prototypes are used by the dialog editor */
#ifdef STRICT
typedef DWORD   (CALLBACK* LPFNSTRTOID)(LPCSTR);
#else
typedef DWORD   (CALLBACK* LPFNSTRTOID)(LPSTR);
#endif
typedef UINT    (CALLBACK* LPFNIDTOSTR)(UINT, LPSTR, UINT);

#endif  // defined( win32 ) || defined( w32 )

#if defined( WIN32 ) || defined( W32 )
#define PACKDDEACK(wStatus, aItem)                      \
	  (LPARAM)PackDDElParam(WM_DDE_ACK, wStatus, (UINT)aItem)
#define UNPACKDDEACK(lPackedVal, wStatus, aItem)        \
	{ UINT uStatus, uAtom;                                                  \
	  UnpackDDElParam(WM_DDE_ACK, lPackedVal, &uStatus, &uAtom);            \
	  wStatus = uStatus; aItem = (ATOM)uAtom;                               \
	  FreeDDElParam(WM_DDE_ACK, lPackedVal);                         }
#define PACKDDEADVISE(hOptions, aItem)                  \
	  (LPARAM)PackDDElParam(WM_DDE_ADVISE, (UINT)hOptions, (UINT)aItem)
#define UNPACKDDEADVISE(lPackedVal, hOptions, aItem)    \
	{ UINT uAtom;                                                           \
	  UnpackDDElParam(WM_DDE_ADVISE, lPackedVal, (PUINT)&hOptions, &uAtom); \
	  aItem = (ATOM)uAtom;                                                  \
	  FreeDDElParam(WM_DDE_ADVISE, lPackedVal);                      }
#define PACKDDEDATA(hData, aItem)                       \
	  (LPARAM)PackDDElParam(WM_DDE_DATA, (UINT)hData, (UINT)aItem)
#define UNPACKDDEDATA(lPackedVal, hData, aItem)         \
	{ UINT uAtom;                                                           \
	  UnpackDDElParam(WM_DDE_DATA, lPackedVal, (PUINT)&hData, &uAtom);      \
	  aItem = (ATOM)uAtom;                                                  \
	  FreeDDElParam(WM_DDE_DATA, lPackedVal);                        }
#define PACKDDEEXECUTE(hCommands)                       \
	  (LPARAM)hCommands
#define UNPACKDDEEXECUTE(lPackedVal, hCommands)         \
	{ UnpackDDElParam(WM_DDE_EXECUTE, lPackedVal, NULL, (PUINT)&hCommands); \
	  FreeDDElParam(WM_DDE_EXECUTE, lPackedVal);                     }
#define PACKDDEPOKE(hData, aItem)                       \
	  (LPARAM)PackDDElParam(WM_DDE_POKE, (UINT)hData, (UINT)aItem)
#define UNPACKDDEPOKE(lPackedVal, hData, aItem)         \
	{ UINT uAtom;                                                           \
	  UnpackDDElParam(WM_DDE_POKE, lPackedVal, (PUINT)&hData, &uAtom);      \
	  aItem = (ATOM)uAtom;                                                  \
	  FreeDDElParam(WM_DDE_POKE, lPackedVal);                        }
#else
#define PACKDDEACK(wStatus, aItem)                      \
	  MAKELPARAM(wStatus, aItem)
#define UNPACKDDEACK(lPackedVal, wStatus, aItem)        \
	{ wStatus    = LOWORD(lPackedVal);                               \
	  aItem      = HIWORD(lPackedVal);                               }
#define PACKDDEADVISE(hOptions, aItem)                  \
	  MAKELPARAM(hOptions, aItem)
#define UNPACKDDEADVISE(lPackedVal, hOptions, aItem)    \
	{ hOptions   = (HGLOBAL)LOWORD(lPackedVal);                      \
	  aItem      = (ATOM)HIWORD(lPackedVal);                         }
#define PACKDDEDATA(hData, aItem)                       \
	  MAKELPARAM(hData, aItem)
#define UNPACKDDEDATA(lPackedVal, hData, aItem)         \
	{ hData      = (HGLOBAL)LOWORD(lPackedVal);                      \
	  aItem      = (ATOM)HIWORD(lPackedVal);                         }
#define PACKDDEEXECUTE(hCommands)                       \
	  MAKELPARAM(NULL, hCommands)
#define UNPACKDDEEXECUTE(lPackedVal, hCommands)         \
	{ hCommands  = (HGLOBAL)HIWORD(lPackedVal);                      }
#define PACKDDEPOKE(hData, aItem)                       \
	  MAKELPARAM(hData, aItem)
#define UNPACKDDEPOKE(lPackedVal, hData, aItem)         \
	{ hData      = (HGLOBAL)LOWORD(lPackedVal);                      \
	  aItem      = (ATOM)HIWORD(lPackedVal);                         }

#if !defined( APIENTRY )
#define APIENTRY
#endif

#if !defined( DLL_PROCESS_ATTACH )
#define DLL_PROCESS_ATTACH   1
#endif

#if !defined( DLL_THREAD_ATTACH )
#define DLL_THREAD_ATTACH 2
#endif

#if !defined( DLL_THREAD_DETACH )
#define DLL_THREAD_DETACH 3
#endif

#if !defined( DLL_PROCESS_DETACH )
#define DLL_PROCESS_DETACH   0
#endif

#endif


/*--------------------------------------------------------------------------*/
/* Portable USER for WIN32                                                  */
/*--------------------------------------------------------------------------*/

#if defined( WIN32 ) || defined( W32 )

#define GetClassBrush( Window ) \
	((HBRUSH)GetClassLong( Window, GCL_HBRBACKGROUND ))

#define GetClassCursor( Window ) \
	((HCURSOR)GetClassLong( Window, GCL_HCURSOR ))

#define GetClassIcon( Window ) \
	((HICON)GetClassLong( Window, GCL_HICON ))

#define GetClassModule( Window ) \
	((HMODULE)GetClassLong( Window, GCL_HMODULE ))

#define GetClassStyle( Window ) \
	((UINT)GetClassLong( Window, GCL_STYLE ))

#define GetClassUserData( Window, Index ) \
	((UINT)GetClassLong( Window, Index ))

#define GetWindowId( Window ) \
	((UINT)GetWindowLong( Window, GWL_ID ))

#define GetWindowUserData( Window, Index ) \
	((UINT)GetWindowLong( Window, Index ))

#define SetClassBrush( Window, Brush ) \
	((HBRUSH)SetClassLong( Window, GCL_HBRBACKGROUND, (long)(Brush) ))

#define SetClassCursor( Window, Cursor ) \
	((HCURSOR)SetClassLong( Window, GCL_HCURSOR, (long)(Cursor) ))

#define SetClassIcon( Window, Icon ) \
	((HICON)SetClassLong( Window, GCL_HICON, (long)(Icon) ))

#define SetClassStyle( Window, Style ) \
	((UINT)SetClassLong( Window, GCL_STYLE, (UINT)(Style) ))

#define SetClassUserData( Window, Index, Data ) \
	((UINT)SetClassLong( Window, Index, (long)(Data) ))

#define SetWindowId( Window, Id ) \
	((UINT)SetWindowLong( Window, GWL_ID, (UINT)(Id) ))

#define SetWindowUserData( Window, Index, Data ) \
	((UINT)SetWindowLong( Window, Index, (long)(UINT)(Data) ))

#else

#define GetClassBrush( Window ) \
	((HBRUSH)GetClassWord( Window, GCW_HBRBACKGROUND ))

#define GetClassCursor( Window ) \
	((HCURSOR)GetClassWord( Window, GCW_HCURSOR ))

#define GetClassIcon( Window ) \
	((HICON)GetClassWord( Window, GCW_HICON ))

#define GetClassModule( Window ) \
	((HMODULE)GetClassWord( Window, GCW_HMODULE ))

#define GetClassStyle( Window ) \
	((UINT)GetClassWord( Window, GCW_STYLE ))

#define GetClassUserData( Window, Index ) \
	((UINT)GetClassWord( Window, Index ))

#define GetWindowId( Window ) \
	((UINT)GetWindowWord( Window, GWW_ID ))

#define GetWindowUserData( Window, Index ) \
	((UINT)GetWindowWord( Window, Index ))

#define SetClassBrush( Window, Brush ) \
	((HBRUSH)SetClassWord( Window, GCW_HBRBACKGROUND, (WORD)(Brush) ))

#define SetClassCursor( Window, Cursor ) \
	((HCURSOR)SetClassWord( Window, GCW_HCURSOR, (WORD)(Cursor) ))

#define SetClassIcon( Window, Icon ) \
	((HICON)SetClassWord( Window, GCW_HICON, (WORD)(Icon) ))

#define SetClassStyle( Window, Style ) \
	((UINT)SetClassWord( Window, GCW_STYLE, (WORD)(Style) ))

#define SetClassUserData( Window, Index, Data ) \
	((UINT)SetClassWord( Window, Index, (WORD)(Data) ))

#define SetWindowId( Window, Id ) \
	((UINT)SetWindowWord( Window, GWW_ID, (WORD)(Id) ))

#define SetWindowUserData( Window, Index, Data ) \
	((UINT)SetWindowWord( Window, Index, (WORD)(Data) ))

#endif /* WIN32 */


#if defined( WIN32 ) || defined( W32 )
#define SETCAPTURE( hWnd )
#define RELEASECAPTURE()
#else
#define SETCAPTURE( hWnd )  SetCapture( hWnd )
#define RELEASECAPTURE()    ReleaseCapture()

#if !defined( RC_INVOKED )
#pragma warning( disable : 4127 )
#endif

// Reply Comment.  These functions DO BELONG here.  WinExApi is nologer needed or should
// be used for Windows.  PDJ.
#define GetDCOrgEx( Hdc, LPPoint )                      \
  {                                            \
     DWORD __GetDCOrgExTempDword;                    \
			  \
     __GetDCOrgExTempDword = GetDCOrg( (Hdc) );            \
     if( (LPPoint) != NULL )                         \
     {                                         \
    (LPPoint)->x   = LOWORD( __GetDCOrgExTempDword );  \
    (LPPoint)->y   = HIWORD( __GetDCOrgExTempDword );  \
     }                                         \
  }


#define SetBrushOrgEx( Hdc, Xorg, Yorg, LPPoint )          \
  {                                            \
     DWORD __SetBrushOrgExTempDword;                 \
			  \
     __SetBrushOrgExTempDword = SetBrushOrg( (Hdc), (Xorg), (Yorg) );  \
     if( (LPPoint) != NULL )                         \
     {                                         \
    (LPPoint)->x   = LOWORD( __SetBrushOrgExTempDword );  \
    (LPPoint)->y   = HIWORD( __SetBrushOrgExTempDword );  \
     }                                         \
  }

#if !defined( RC_INVOKED )
#pragma warning( default: 4127 )
#endif

#endif


/*--------------------------------------------------------------------------*/
/* Portable GDI for WIN32                                                   */
/*--------------------------------------------------------------------------*/
#if !defined ( _RECT16_ )
#define _RECT16_
typedef struct tagRECT16
{
    short left;
    short top;
    short right;
    short bottom;
} RECT16;
#endif
typedef RECT16*      PRECT16;
typedef RECT16 NEAR* NPRECT16;
typedef RECT16 FAR*  LPRECT16;

typedef struct tagPOINT16
{
    short x;
  short y;
} POINT16;
typedef POINT16*       PPOINT16;
typedef POINT16 NEAR* NPPOINT16;
typedef POINT16 FAR*  LPPOINT16;

typedef struct tagSIZE16
{
    short cx;
    short cy;
} SIZE16;
typedef SIZE16*       PSIZE16;
typedef SIZE16 NEAR* NPSIZE16;
typedef SIZE16 FAR*  LPSIZE16;

#if defined( WIN32 ) || defined( W32 )
#define COPYRECT(  lprcSrc, lprcDst ) { (lprcDst)->left   = (lprcSrc)->left;     \
		    (lprcDst)->right  = (lprcSrc)->right;    \
		    (lprcDst)->top    = (lprcSrc)->top;      \
		    (lprcDst)->bottom = (lprcSrc)->bottom; }
#define COPYPOINT( lpptSrc, lpptDst ) { (lpptDst)->x      = (short)(lpptSrc)->x;        \
		    (lpptDst)->y      = (short)(lpptSrc)->y; }
#define COPYSIZE(  lpszSrc, lpszDst ) { (lpszDst)->cx     = (int)(lpszSrc)->cx;       \
		    (lpszDst)->cy     = (int)(lpszSrc)->cy; }
#else
#define COPYRECT(  lprcSrc, lprcDst ) { *(LPRECT) lprcDst = *(LPRECT) lprcSrc; }
#define COPYPOINT( lpptSrc, lpptDst ) { *(LPPOINT)lpptDst = *(LPPOINT)lpptSrc; }
#define COPYSIZE(  lpszSrc, lpszDst ) { *(LPSIZE) lpszDst = *(LPSIZE) lpszSrc; }
#endif


/*---------------------------------------------------------------------------*/
/* Initialization                                                            */
/*---------------------------------------------------------------------------*/
#if defined( __cplusplus )
extern "C" {
#endif
BOOL CALLBACK InitializeRumbaDll( void );
void CALLBACK TerminateRumbaDll( void );
#if defined( __cplusplus )
}
#endif

/*---------------------------------------------------------------------------*/
/* RumbaSys                                                                  */
/*---------------------------------------------------------------------------*/

// defines

#define NOFILE               -1

#define SEEK_SET          0
#define SEEK_CUR          1
#define SEEK_END          2

//1.12.94,dwhanger, allow MAXFILENAME to adjust appropriately for the target OS
#if defined(WIN16) || defined(W16)
  #define MAXFILENAME          120
#elif defined(WIN32) || defined(W32)
  #define MAXFILENAME          _MAX_FNAME
#endif

#define MAXFILESPEC          16
#define MAXBLKSIZE           16384

#define MAXSTRING16          16
#define MAXSTRING32          32
#define MAXSTRING64          64
#define MAXSTRING128         128
#define MAXSTRING256         256

#define FILEATTR          0x4010
#define ATTRIB_FILELIST         0x0001
#define ATTRIB_DIRECTORYLIST 0xC010

#define SERIALNUMBERLENGTH      8

// MAX_PATH needs to be defined to allow for UNC/LFN.
//1.12.94,dwhanger, use _MAX_PATH instead of hardcoding the value in
//_MAX_PATH is in STDLIB.H for MSVC 1.5 and 2.0
//MAX_PATH should be defined here and no where else!
#if defined( MAX_PATH )
 #undef MAX_PATH
#endif
#define MAX_PATH          _MAX_PATH


/*---------------------------------------------------------------------------*/
/* WDPath Defintions.                                                        */
/*---------------------------------------------------------------------------*/
#define WC_WDPATH            "WDPath"
#define WD_WS_USINGCTL3D     0x0001L

//#if defined( WIN32 ) || defined( W32 )
#define lsprintf                wsprintf
//#else
//#define lsprintf                LSPRINTF
//#endif

// function prototypes

#if defined( __cplusplus )
extern "C" {
#endif
extern WORD CALLBACK              SEGMENT( VOID FAR *Ptr );
extern WORD CALLBACK              OFFSET( VOID FAR *Prt );
extern LPSTR CALLBACK             StringChr( LPSTR String, BYTE Char );
#if defined( __cplusplus )
}
#endif

#define IsStringNull( s )			(0 == (s))
#define IsStringEmpty( s )			(IsStringNull(s) || ((s)[0] == TEXT('\0')))
#define StringEmpty( s )			((s)[0] = TEXT('\0') )
#define StringNull( s, i )			((s)[(i)] = TEXT('\0') )
#define StringCat( s1, s2 )			lstrcat( (s1), (s2) )
#define StringCompare( s1, s2 )		lstrcmpi( (s1), (s2) )
#define StringsMatch( s1, s2 )		(0 == lstrcmpi( (s1), (s2) ))
#define StringCopy( s1, s2 )		lstrcpy( (s1), (s2) )
#define StringLength( s ) 			lstrlen( (s) )

/* AllocMemory is defined in EM3279/SOURCE/SYSCALLS.C */
#if defined( __cplusplus )
extern "C" {
#endif
//1.12.94,dwhanger, declared already in syscalls.h! Use it from there.
//extern HANDLE CALLBACK            AllocMemory( WORD Size );

/* CopyMem and SetMem are defined in RUMBADLL/SOURCE/RMBFUNCS.ASM */
extern LPSTR CALLBACK         CopyMem( LPVOID Dest, LPVOID Source, WORD Count );
extern LPSTR CALLBACK         SetMem( LPSTR Dest, BYTE Value, WORD Count );

/* FreeMemory is defined in RUMBADLL/SOURCE/RMBSYS.C */
extern VOID CALLBACK          FreeMemory( HANDLE MemoryHandle );


/* IsPMVersion is defined in RUMBADLL/SOURCE/RMBSYS.C */
extern BOOL CALLBACK          IsPMVersion( VOID );
#if defined( __cplusplus )
} // extern "C"
#endif
#define MemoryReAlloc( m, s )   GlobalReAlloc( (m), (DWORD)(s), GHND )
#define MemoryUnlock( m )    GlobalUnlock( (m) )
#define MemoryLock( m )      ((VOID FAR *) GlobalLock( (m) ))


/* Do not define thesse functions if using NTG Process.H. */
#if !defined( _PROCESS_H_ )
#if defined( __cplusplus )
extern "C" {
#endif
#ifdef WIN5250
extern UINT CALLBACK          FileRead( HFILE FileHandle, LPSTR Stream,
		UINT Length );
extern UINT CALLBACK          FileWrite( HFILE FileHandle, LPSTR Stream,
		UINT Length );
#else
extern WORD CALLBACK          FileRead( HFILE FileHandle, LPSTR Stream,
		WORD Length );
extern WORD CALLBACK          FileWrite( HFILE FileHandle, LPSTR Stream,
		WORD Length );
#endif
#if defined( __cplusplus )
} // extern "C"
#endif
#endif  // _PROCESS_H_

#define FileClose( f )          _lclose( (f) )
#define FileSeek( f, off, ori )    _llseek( (f), (off), (ori) )


#if defined( __cplusplus )
extern "C" {
#endif
extern VOID CALLBACK          WordToAscii( WORD Value, LPSTR String );

extern BOOL CALLBACK          WDExec( LPSTR ProgramName, WORD CmdShow, LPSTR CommandLine);

extern LPSTR CALLBACK         lultoa( LONG Value, LPSTR Buffer, int Radix );
//extern int FAR _cdecl        lsprintf( LPSTR Buffer, LPCSTR Format, ... );
extern int CALLBACK           lvsprintf( LPSTR Buffer, LPSTR Format, LPSTR Arguments);

extern WORD CALLBACK          convert_to_selector( WORD Segment );

extern void CALLBACK          CenterWindow( HWND Window );

#if defined( WIN32 ) || defined( W32 )
extern int FAR _cdecl       auxmsg( LPSTR Format, int nFirstArg, ... );
extern int FAR _cdecl       auxline( LPSTR Format, int nFirstArg, ... );
extern int CALLBACK           auxout( LPSTR Format, va_list marker, BOOL NewLine );
#else
extern int FAR _cdecl       auxmsg( LPSTR Format, ... );
extern int FAR _cdecl       auxline( LPSTR Format, ... );
extern int CALLBACK           auxout( LPSTR Format, LPSTR Args, BOOL NewLine );
#endif

extern void CALLBACK          auxreset( void );
extern UINT CALLBACK         FileCopy( LPSTR DestFile, LPSTR SourceFile );

extern DWORD  CALLBACK WDGetVersion( HINSTANCE hInstance );
extern BOOL   CALLBACK VersionsMatch( HINSTANCE hInstance1, HINSTANCE hInstance2 );
extern HANDLE CALLBACK RumbaDLLInstance(void);


/***************************************************************************/
/* DOS/BIOS                                                                */
/***************************************************************************/

/* nDriveNumber is always zero based.  0 == A, 1 == B, 2 == C, etc. */

int WINAPI DOSGetFloppyType( int nDriveNumber );
BOOL WINAPI DOSIsCdRomDrive( int nDriveNumber );
BOOL WINAPI DOSIsRamDrive( int nDriveNumber );

#if defined( __cplusplus )
} // extern "C"
#endif

/***************************************************************************/
/* Drive Types                                                             */
/***************************************************************************/

#define WDDRIVE_UNKNOWN       0x00000001L
#define WDDRIVE_REMOVEABLE    0x00000002L
#define WDDRIVE_FIXED         0x00000004L
#define WDDRIVE_REMOTE        0x00000008L
#define WDDRIVE_CDROM         0x00000010L
#define WDDRIVE_RAM           0x00000020L
#define WDDRIVE_525IN         0x00000040L
#define WDDRIVE_350IN         0x00000080L
#define WDDRIVE_360K          0x00000100L
#define WDDRIVE_1200K         0x00000200L
#define WDDRIVE_720K          0x00000400L
#define WDDRIVE_1440K         0x00000800L

#define IsDriveDefined(d)     (WDGetDriveType(d) != 0L)
#define IsDriveUnknown(d)     ((WDGetDriveType(d) & WDDRIVE_UNKNOWN) != 0L)
#define IsDriveRemoveable(d)  ((WDGetDriveType(d) & WDDRIVE_REMOVEABLE) != 0L)
#define IsDriveFixed(d)       ((WDGetDriveType(d) & WDDRIVE_FIXED) != 0L)
#define IsDriveRemote(d)      ((WDGetDriveType(d) & WDDRIVE_REMOTE) != 0L)
#define IsDriveCdRom(d)       ((WDGetDriveType(d) & WDDRIVE_CDROM) != 0L)
#define IsDriveRam(d)         ((WDGetDriveType(d) & WDDRIVE_RAM) != 0L)
#define IsDrive525Inch(d)     ((WDGetDriveType(d) & WDDRIVE_525IN) != 0L)
#define IsDrive350Inch(d)     ((WDGetDriveType(d) & WDDRIVE_350IN) != 0L)
#define IsDrive360K(d)        ((WDGetDriveType(d) & WDDRIVE_360K) != 0L)
#define IsDrive1200K(d)       ((WDGetDriveType(d) & WDDRIVE_1200K) != 0L)
#define IsDrive720K(d)        ((WDGetDriveType(d) & WDDRIVE_720K) != 0L)
#define IsDrive1440K(d)       ((WDGetDriveType(d) & WDDRIVE_1440K) != 0L)

#if defined( __cplusplus )
extern "C"
#endif
DWORD CALLBACK WDGetDriveType( int nDriveNumber );



/*----------------------------------------------------------------------------*/
/* WDOpenFile                                                                 */
/*----------------------------------------------------------------------------*/

#define WDOF_USEINIPATH      0x0001   //useful only with OF_CREATE

#if defined( __cplusplus )
extern "C"
#endif
int CALLBACK WDOpenFile(
  LPSTR       PathName,
  LPOFSTRUCT  OfStruct,
  INT      OfStyle,
  INT      WDOfStyle );



/*----------------------------------------------------------------------------*/
/* GetModulePath                                                              */
/*----------------------------------------------------------------------------*/

#if defined( __cplusplus )
extern "C"
#endif
extern int CALLBACK GetModulePath(
  HANDLE   ModuleInstance,
  LPSTR FileName,
  LPSTR Path,
  int   SizeOfPath );
/* Gets the fully qualified path for FileName. For example, if Instance is
 * the instance handle of c:\rumba\rumbadsp.exe and FileName == "rumba.ini",
 * c:\rumba\rumba.ini is copied to Path and 18 is returned.
 *
 * If Instance == 0, uses the instance handle of rumbadll.dll.
 *
 * If FileName == NULL, the filename of Instance, including the last
 * backslash, is stripped.   For example, c:\rumba\rumbadsp.exe is returned
 * as c:\rumba.
 *
 * Copies the result to Path.
 *
 * SizeOfPath should be equal to the size of the Path buffer including room
 * for the nul terminator.   If the result is longer than SizeOfPath, it is
 * truncated.  For example, if SizeOfPath == 3, c:\rumba is returned as c:.
 *
 * The return value equals the string length of Path.
 */



/*----------------------------------------------------------------------------*/
/* rumba private profile                                                      */
/*----------------------------------------------------------------------------*/

#define DEFAULTPROFILEFILENAME     "Rumba.Ini"
#define DEFAULTPROFILEAPPLICATION  "Rumba"

#define PROFILESERIALNUMBERKEY     "Serial Number"
#define PROFILECOPYRIGHTKEY     "Copyright"
#define PROFILEVERSIONKEY       "Version"

#if defined( __cplusplus )
extern "C" {
#endif

extern INT CALLBACK GetRumbaProfileString(
  LPSTR Application,
  LPSTR Key,
  LPSTR Default,
  LPSTR String,
  int      SizeOfString,
  LPSTR FileName );

extern int CALLBACK GetRumbaProfileInt(
  LPSTR Application,
  LPSTR Key,
  int   Default,
  LPSTR FileName );

extern BOOL CALLBACK WriteRumbaProfileString(
  LPSTR Application,
  LPSTR Key,
  LPSTR String,
  LPSTR FileName );

extern BOOL CALLBACK WriteRumbaProfileInt(
  LPSTR Application,
  LPSTR Key,
  int   Value,
  LPSTR FileName );

/* If Application == NULL, DEFAULTPROFILEAPPLICATION is used.
 *
 * If FileName == NULL, DEFAULTPROFILEFILENAME is used.
 *
 * A fully qualified path of FileName is created via GetModulePath() using
 * RumbaDLL's instance handle.  See GetModulePath() above.
 *
 * See also Windows SDK's GetPrivateProfileString(), GetPrivateProfileInt(),
 * and WritePrivateProfileString().  Note that there is no Windows equivalent
 * to WriteRumbaProfileInt().
 */



/*----------------------------------------------------------------------------*/
/* Function Entry and Exit Tracing                                            */
/*----------------------------------------------------------------------------*/

extern void CALLBACK TrcOutputEnter( LPSTR Text );
extern void CALLBACK TrcOutputExit( LPSTR Text );

//dwhanger,26.1.95, mfc-ing
#if RUMBA_TRACE
  #define TrcEnter(FuncName)   static char TrcFuncName[]=(FuncName); TrcOutputEnter(TrcFuncName);
  #define TrcExit()         {TrcOutputExit(TrcFuncName);return;}
  #define TrcReturn(Value)  {TrcOutputExit(TrcFuncName);return(Value);}
#else  /* if TRACE */
  #define TrcEnter(FuncName)   ;
  #define TrcExit()         return;
  #define TrcReturn(Value)  return(Value);
#endif /* if TRACE */
//#else /* ifdef cplusplus */
//#define TrcEnter(FuncName) ;
//#define TrcExit()       return;
//#define TrcReturn(Value)   return(Value);
//#endif   /* ifdef cplusplus */

/*----------------------------------------------------------------------------*/
/* rumbadll string resources                                                  */
/*----------------------------------------------------------------------------*/

#define IDS_SERIALNUMBERFILENAME      1
#define IDS_DEFAULTPROFILEFILENAME    2
#define IDS_DEFAULTPROFILEAPPLICATION 3
#define IDS_PROFILESERIALNUMBERKEY    4
#define IDS_PROFILECOPYRIGHTKEY       5
#define IDS_PROFILEVERSIONKEY         6

extern INT CALLBACK LoadRumbaString(
  INT   Id,
  LPSTR Buffer,
  INT   SizeOfBuffer );

/* If unable to load Id, displays an error message, sets Buffer to "", and
 * returns 0.
 *
 * See also Windows SDK's LoadString().
 */



/*----------------------------------------------------------------------------*/
/* Type Indirections.                                           */
/*----------------------------------------------------------------------------*/
#ifndef VOID
#define VOID  void
#endif

#ifndef NEAR
#define NEAR  near
#endif

#ifndef FAR
#define FAR      far
#endif

#ifndef SHORT
#define SHORT short
#endif

#ifndef LONG
#define LONG  long
#endif

#ifndef CDECL
#define CDECL cdecl
#endif

#ifndef PASCAL
#define PASCAL   pascal
#endif

#if !defined( EXPORT )
#if defined( W16 )
#define EXPORT   _export
#else
#define EXPORT
#endif  // !defined( W16 )
#endif  // !defined( EXPORT )

#ifndef EXPENTRY
#define EXPENTRY    WINAPI
#endif

#ifndef COLORREF
#define COLORREF DWORD
#endif

#ifndef LPLPSTR
#define LPLPSTR  char FAR * FAR *
#endif



/*----------------------------------------------------------------------------*/
/* Type Declarations.                                           */
/*----------------------------------------------------------------------------*/
#if !defined( _LPWNDDATA_ )
#define _LPWNDDATA_
typedef VOID FAR       *LPWNDDATA;
#endif

/* Do not define thesse types if using NTG Process.H. */
#if !defined( _PROCESS_H_ )
//typedef VOID FAR       *LPWNDDATA;
typedef VOID FAR       *LPCLSDATA;
typedef SHORT FAR      *LPSHORT;

#if !defined( WIN5250 ) || defined( PRNTR )
typedef VOID NEAR      *PVOID;
#else
typedef VOID           *PVOID;
#endif

typedef HWND FAR       *LPHWND;

#if !defined( USHORT )
typedef unsigned short    USHORT;
#endif

#if !defined( PUSHORT )
typedef USHORT NEAR *  PUSHORT;
#endif

#if !defined( LPUSHORT )
typedef USHORT FAR *   LPUSHORT;
#endif

#if !defined( PBYTE )
//M.B!030195: Added 'NEAR'.  This choked when building W16 MFC Large model.
typedef BYTE NEAR * PBYTE;
#endif

#if !defined( PINT )
//M.B!030195: Added 'NEAR'.  This choked when building W16 MFC Large model.
typedef INT NEAR * PINT;
#endif

#if !defined( PWORD )
//M.B!030195: Added 'NEAR'.  This choked when building W16 MFC Large model.
typedef WORD NEAR * PWORD;
#endif

#endif  //_PROCESS_H_

/*----------------------------------------------------------------------------*/
/* Data Transfer Flags Structure.                                  */
/*----------------------------------------------------------------------------*/
typedef union
{
  struct
  {
    short Lic     :1;
    short Fic     :1;
    short Ack     :1;
    short Eot     :1;
    short Sscp    :1;

  } Bits;

    short Flag;

} FLAG;

/*----------------------------------------------------------------------------*/
/* Constant Definitions.                                        */
/*----------------------------------------------------------------------------*/
#define WD_TERMINATE   0x1000
#define WD_DISPLAYCHART 0x1001  // Parm1 == 205 or 305
#define WD_DISPLAYSHEET 0x1002  // Parm1 == 205 or 305

#define WD_ENTERMENULOOP  0x0211
#define WD_EXITMENULOOP      0x0212

#define GWW_DBFONT  0x1A

#ifndef IDTEXT
#define IDTEXT   -1
#endif

#ifndef IDSTATIC
#define IDSTATIC -1
#endif

//This could be replaced by a function later, detecting at runtime whether
//Win32 or not! 8.12.94,dwhanger
#if defined(WIN32) || defined(W32)
 #define ValidLibraryhInst(theInst)    ((theInst) != NULL)
#elif defined(WIN16) || defined(W16)
 #define ValidLibraryhInst(theInst)    ((theInst) >= HINSTANCE_ERROR)
#endif

#if defined( WIN32 ) || defined( W32 )
#define WD_HINSTANCE_ERROR ((HINSTANCE)1)
#else
#define WD_HINSTANCE_ERROR HINSTANCE_ERROR
#endif

/*----------------------------------------------------------------------------*/
/* Macro Declarations.                                          */
/*----------------------------------------------------------------------------*/
#define SEGMENT( x )   (WORD) (((DWORD) (VOID FAR *) (x)) >> 16)
#define OFFSET( x )    (WORD) ((DWORD) (VOID FAR *) (x))

#define TOGGLE( Flag ) (Flag = !Flag)
#define CLEAR( Flag )  (Flag = 0)
#define SET( Flag )    (Flag = 1)

#define HANDLEFROMLRESULT( lresult ) ((void *)(WPARAM)(lresult))

#define GetControlFont( CtlHandle ) ((HFONT)GetWindowUserData( \
		     GetParent( CtlHandle ), GWW_DBFONT ))

#define HELPINDEXMAP(HelpIndex)     (HelpIndex)

#define InitLocalHeap( DataSegment, HeapSize ) \
    ((BOOL) LocalInit( DataSegment, 0, HeapSize ))

#define SetWindowStyle( WindowHandle, Style ) \
    (SetWindowLong( (WindowHandle), GWL_STYLE, (DWORD) (Style) ))

#define IsWindowStyle( WindowHandle, Attribute ) \
    (((GetWindowLong( (WindowHandle), GWL_STYLE )) & (Attribute)) \
    == (Attribute))

#define IsFlag( Flag, Mask ) (((Flag) & (Mask)) == (Mask))

#define IsHandle( Handle )               ((Handle) != NULL)

#define IsSystemCloseCommand( Command ) \
    (((Command) & 0xFFF0) == SC_CLOSE)

#define IsControlWndStyle( ControlStyle, Style ) \
    ((BOOL) ((LOINT( (ControlStyle)->dwStyle ) & (Style)) == (Style)))

#define abs( n ) (((n) >= 0)? (n): (-(n)))
#define Even( x )   ((BOOL) (((x) & 0x0001) == 0))

//dwhanger,1.12.94, Some useful macros from rmbsys.h in the AS400 tree
//BEGIN insertion

#define IsStringNull( s )			(0 == (s))
#define IsStringEmpty( s )			(IsStringNull(s) || ((s)[0] == TEXT('\0')))
#define StringEmpty( s )			((s)[0] = TEXT('\0') )
#define NullString( s, i )          ((s)[(i)] = TEXT('\0') )
#define StringNull( s, i )			((s)[(i)] = TEXT('\0') )
#define StringCat( s1, s2 )         lstrcat( (s1), (s2) )
#define StringCompare( s1, s2 )     lstrcmpi( (s1), (s2) )
#define StringCopy( s1, s2 )        lstrcpy( (s1), (s2) )
#define StringLength( s )           lstrlen( (s) )

#define CloseFile( f )              _lclose( (f) )
#define SeekFile( f, off, ori )     _llseek( (f), (off), (ori) )

#define ReAllocMemory( m, s )       GlobalReAlloc( (m), (DWORD)(s), GHND )

#if !defined( sizeof_array )
#define sizeof_array( a )  \
     (sizeof( (a) ) / sizeof( (a)[ 0 ] ))
#endif

//1.12.94,dwhanger, def'd in winbase.h, redef'd here to remove compiler msgs at /W4
#if defined(WIN32) || defined(W32)
  #undef FreeProcInstance
  #define FreeProcInstance( lpProc)
#endif
//END insertion

#define Exit( w )               DestroyWindow( (w) )

#define WinExec( ProgramName, CmdShow, CommandLine ) \
  WDExec( ProgramName, CmdShow, CommandLine )

/****************************************************************************/
/* assertions                                                               */
/****************************************************************************/

#if !defined( _PROCESS_H_ )		// Process.H has its own, more comprehensive
								//	assertion macros

#if defined( ASSERT )

/* Example Usage:
 *
 * DWORD Example1( char *p, int t )
 * {
 *      Function( "Example1" );
 *      Assert( p != NULL, -1L );
 *      Assert( strlen(p) < 128, -1L );
 *      Assert( t >= 10 && t <= 100, -1L );
 * }
 *
 * void Example2( char *p, int t )
 * {
 *      Function( "Example2" );
 *      Assert( p != NULL, VRET );
 *      Assert( strlen(p) < 128, VRET );
 *      Assert( t >= 10 && t <= 100, VRET );
 * }
 */

#define VRET ((void)0)

#define Function( name )  \
  static char FuncName[] = (name);

#define Assert( exp, retval ) \
  if( !(exp) ) \
  { \
     AssertMsg( #exp, FuncName, __FILE__, __LINE__ ); \
     return( (retval) ); \
  }

extern void CALLBACK AssertMsg( LPSTR exp, LPSTR func, LPSTR file, int line );

#else

#define Function( name )
#define Assert( exp, retval )
#endif //ASSERT


#endif /* !_PROCESS_H_ */


/*
 * When compiling for 16-bit, there are no defines for the various Unicode-enabling
 * features such as TCHAR and related types. So, they have been included here.  Note
 * that these things are taken from the tchar.h file included with MSVC 2.0...
 */
#if defined( W16 )

#include <string.h>

#define _TEOF    EOF


/* Program */

#define _tmain      main
#define _tWinMain   WinMain
#ifdef  _POSIX_
#define _tenviron   environ
#else
#define _tenviron  _environ
#endif


/* Formatted i/o */

#define _tprintf    printf
#define _ftprintf   fprintf
#define _stprintf   sprintf
#define _sntprintf  _snprintf
#define _vtprintf   vprintf
#define _vftprintf  vfprintf
#define _vstprintf  vsprintf
#define _vsntprintf _vsnprintf
#define _tscanf     scanf
#define _ftscanf    fscanf
#define _stscanf    sscanf


/* Unformatted i/o */

#define _fgettc     fgetc
#define _fgettchar  _fgetchar
#define _fgetts     fgets
#define _fputtc     fputc
#define _fputtchar  _fputchar
#define _fputts     fputs
#define _gettc      getc
#define _gettchar   getchar
#define _getts      gets
#define _puttc      putc
#define _puttchar   putchar
#define _putts      puts
#define _ungettc    ungetc


/* String conversion functions */

#define _tcstod     strtod
#define _tcstol     strtol
#define _tcstoul    strtoul

#define _itot       _itoa
#define _ltot       _ltoa
#define _ultot      _ultoa
#define _ttoi       atoi
#define _ttol       atol


/* String functions */

#define _tcscat     strcat
#define _tcscpy     strcpy
#define _tcslen     strlen
#define _tcsxfrm    strxfrm
#define _tcsdup     _strdup


/* Execute functions */

#define _texecl     _execl
#define _texecle    _execle
#define _texeclp    _execlp
#define _texeclpe   _execlpe
#define _texecv     _execv
#define _texecve    _execve
#define _texecvp    _execvp
#define _texecvpe   _execvpe

#define _tspawnl    _spawnl
#define _tspawnle   _spawnle
#define _tspawnlp   _spawnlp
#define _tspawnlpe  _spawnlpe
#define _tspawnv    _spawnv
#define _tspawnve   _spawnve
#define _tspawnvp   _spawnvp
#define _tspawnvpe  _spawnvpe

#define _tsystem    system


/* Time functions */

#define _tasctime   asctime
#define _tctime     ctime
#define _tstrdate   _strdate
#define _tstrtime   _strtime
#define _tutime     _utime
#define _tcsftime   strftime


/* Directory functions */

#define _tchdir     _chdir
#define _tgetcwd    _getcwd
#define _tgetdcwd   _getdcwd
#define _tmkdir     _mkdir
#define _trmdir     _rmdir


/* Environment/Path functions */

#define _tfullpath  _fullpath
#define _tgetenv    getenv
#define _tmakepath  _makepath
#define _tputenv    _putenv
#define _tsearchenv _searchenv
#define _tsplitpath _splitpath


/* Stdio functions */

#ifdef  _POSIX_
#define _tfdopen    fdopen
#else
#define _tfdopen    _fdopen
#endif
#define _tfsopen    _fsopen
#define _tfopen     fopen
#define _tfreopen   freopen
#define _tperror    perror
#define _tpopen     _popen
#define _ttempnam   _tempnam
#define _ttmpnam    tmpnam


/* Io functions */

#define _taccess    _access
#define _tchmod     _chmod
#define _tcreat     _creat
#define _tfindfirst _findfirst
#define _tfindnext  _findnext
#define _tmktemp    _mktemp
#define _topen      _open
#define _tremove    remove
#define _trename    rename
#define _tsopen     _sopen
#define _tunlink    _unlink

#define _tfinddata_t    _finddata_t


/* ctype functions */

#define _istascii   isascii
#define _istcntrl   iscntrl
#define _istxdigit  isxdigit


/* Stat functions */

#define _tstat      _stat


/* Setlocale functions */

#define _tsetlocale setlocale

#ifndef _TCHAR_DEFINED
typedef char TCHAR, *PTCHAR;
typedef unsigned char TBYTE , *PTBYTE ;
#define _TCHAR_DEFINED
#endif /* !_TCHAR_DEFINED */

typedef LPSTR LPTCH, PTCH;
typedef LPSTR PTSTR, LPTSTR;
typedef LPCSTR LPCTSTR;

#define __T(x)      x
#define _T(x)    __T(x)
#define _TEXT(x) __T(x)
#define __TEXT(quote) quote
#define TEXT(quote)	__TEXT(quote)

#define CharPrev(x,y)	AnsiPrev(x,y)
#define CharNext(x)		AnsiNext(x)

#endif // W16

#if defined( __cplusplus )
}
#endif

#endif //_RMBSYS_H_

