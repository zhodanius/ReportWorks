/* $Header:   H:/vcsmfc/h/rumbasys.h_v   1.2   08 Oct 1996 16:50:18   amh  $ */

/*--------------------------------------------------------------------------*/
/*	   Copyright (c) 1996 Wall Data Incorporated.  All Rights Reserved. 	*/
/*--------------------------------------------------------------------------*/
/* This file contains proprietary trade secrets of Wall Data, Incorporated.	*/
/* No part of this file may be reproduced or transmitted in any form or by 	*/
/* any means, electronic or mechanical, including photocopying and			*/
/* recording, for any purpose without the expressed written permission		*/
/* of Wall Data Incorporated.												*/
/*--------------------------------------------------------------------------*/
/* Purpose:
 *
 */
/*--------------------------------------------------------------------------*/
/* Authors:																	*/
/*--------------------------------------------------------------------------*/
/* Abstract:
 *
 */
/*--------------------------------------------------------------------------*/
/* $Revision:   1.2  $														*/
/*--------------------------------------------------------------------------*/

#if defined( LOADER_TYPEDEFS_ONLY ) && !defined( _RUMBASYS_TYPEDEFS_ ) && !defined( _H_RUMBASYS_ )
#define _RUMBASYS_TYPEDEFS_

typedef UINT ( WINAPI * QUERYRUMBACACHEDIR )
(
	TCHAR * const		CacheDirBuffer,
	const UINT			BufferLen
);


typedef UINT ( WINAPI * QUERYRUMBAHOSTDIR )
(
	TCHAR * const			HostDirBuffer,
	const UINT				BufferLen,
	const HOST_TYPE_ENUM	WhichHost,
	const BOOL				WithMacroSubdir		= FALSE
);


typedef UINT ( WINAPI * QUERYRUMBAHOSTPRIVATEDIR )
(
	TCHAR * const			HostDirBuffer,
	const UINT				BufferLen,
	const HOST_TYPE_ENUM	WhichHost,
	const BOOL				WithMacroSubdir		= FALSE
);


typedef UINT ( WINAPI * QUERYRUMBAPRIVATEDIR )
(
	TCHAR * const		PrivateDirBuffer,
	const UINT			BufferLen
);


typedef UINT ( WINAPI * QUERYRUMBASYSTEMDIR )
(
	TCHAR * const		SystemDirBuffer,
	const UINT			BufferLen
);


enum HOST_TYPE_ENUM;
enum PRODUCT_APP_ENUM;


#elif !defined( _H_RUMBASYS_ )
#define _H_RUMBASYS_


/*--------------------------------------------------------------------------*/
/* Common Header Files.														*/
/*--------------------------------------------------------------------------*/
#include	<RmbSys.H>
#include	<CommDlg.H>


/*--------------------------------------------------------------------------*/
/* Macros																	*/
/*--------------------------------------------------------------------------*/

#define MAX_HOST_LEN			10
#define MAX_PATH_LEN			_MAX_PATH
#define PREFERENCES				MULTI


#if !defined( MFPUB )
#define MFPUB
#endif


/*--------------------------------------------------------------------------*/
/* Structures and Type declarations.										*/
/*--------------------------------------------------------------------------*/

#if !defined( _LPWNDDATA_ )
#define _LPWNDDATA_
typedef VOID FAR       *LPWNDDATA;
#endif

#ifndef HOST_TYPE_ENUM_DEFINED
#define HOST_TYPE_ENUM_DEFINED
enum HOST_TYPE_ENUM
{
	MULTI,
	MAINFRAME,
	AS400,
	VAX,
	HP,			
	END_HOST,
	RUMBA_PRINTER_APP,
	GENERIC_APP,
	INTERNET,
	LPD
};
#endif


enum SUBDIR_TYPE_ENUM
{
	NULL_SUBDIR,
	MACRO_SUBDIR,
	PROFILE_SUBDIR,
	DEMO_SUBDIR,
	END_SUBDIR
};

typedef LPSTR	SUBDIRLPSTRARRAY [END_SUBDIR+1];

enum PATH_TYPE_ENUM
{
	NULL_DIR,
	EXECUTABLE_DIR,
	PRIVATE_DIR,
	RUMBA_PRIVATE_DIR,
	WIN_INI_SECT,
	END_PATH_ENUM
};

enum FILE_TYPE_ENUM
{
	PROFILE_TYPE,
	HOTSPOTS_TYPE,
	KEYMAP_TYPE,
	MACRO_TYPE,
	MACROPAD_TYPE
};

// These ENUMS ARE POSITION CRITICAL - ONLY ADD TO END OF LISTS BEFORE THE "END_" ENUM
enum PRODUCT_APP_ENUM
{
	TERMINAL_APP,        	// These Apps are common to all Hosts
	PRINTER_APP,
	FASTPATH_APP,
	FILE_TRANS_APP,
	// Next ENUM goes HERE
	END_HOST_APPS,

	RUMBA_APP,           	// These Apps are shared by all Hosts
	RUMBAMNU_APP,
	OVERVIEW_APP,
	RMAINFP_APP,
	// Next ENUM goes HERE
	END_SYS_APPS,

	IBM_APP,          		// These Apps are Special cases
	OLIVETTI_PC_APP,
	NOTEBOOK_APP,
	// Next ENUM goes HERE
	END_SPECIAL_APPS,
	//
	INTERNET_APP,

	END_APP
};

enum SETUPITEMENUM
{
	HOST_ITEM,
	PATH_ITEM,
	AVAILABLE_ITEM,
	END_SETUP_ITEM
};

typedef LPSTR 			HOSTLPSTRARRAY [END_HOST];
typedef HOSTLPSTRARRAY 	HOSTAPPARRAY [END_HOST_APPS];
typedef LPSTR		 	SYSAPPARRAY [END_SYS_APPS - END_HOST_APPS];
typedef LPSTR			SPECAPPARRAY [END_SPECIAL_APPS - END_SYS_APPS];
typedef LPSTR           PATHLPSTRARRAY [END_PATH_ENUM];
typedef PATHLPSTRARRAY  HOSTPATHLPSTRARRAY [END_HOST];
typedef LPSTR			SETUPITEMSTRARRAY [END_SETUP_ITEM];

struct SETUPSTRUCT
{
    HOSTLPSTRARRAY      Section;
	SETUPITEMSTRARRAY	Item;
};


struct PREFERENCESSTRUCT
{
	HOST_TYPE_ENUM	eHost;
	char			szHost [MAX_HOST_LEN];
};

typedef PREFERENCESSTRUCT	  *PPREFERENCES;
typedef PREFERENCESSTRUCT FAR *LPPREFERENCES;


//|*********************************************************************
//|		Common Dlg Enumerations
//|*********************************************************************
enum COMMFILETYPEENUM
{
    MACROPAD_FILE,
    MACRO_FILE,
    PROFILE_FILE,
    KEYMAP_FILE,
    HOTSPOTS_FILE,
	PRINTER_FILE,
	PRINTOPT_FILE,
	FTX_PROFILE_FILE,
	HISTORY_FILE,
	PRINTPREVIEW_FILE,
	END_FILE_TYPE	
};

#ifndef COMM_ACCESS_MODE_DEFINED
#define COMM_ACCESS_MODE_DEFINED
enum COMM_ACCESS_MODE
{
	COMM_OPEN,
	COMM_SAVE,
	END_ACCESS
};
#endif

enum EXTENSION_TYPE
{
	NONE,
	EXE,
	DLL
};


//|*********************************************************************
//|		Common Dialog Constant definitions
//|*********************************************************************
#define COMM_FILE_BUFFER_LEN 		256
#define COMM_FILE_TITLE_BUFFER_LEN 	14
#define COMM_TITLE_BUFFER_LEN 		80
#define COMM_FILTER_BUFFER_LEN 		256
#define COMM_DIRECTORY_LEN			MAX_PATH_LEN	


//|*********************************************************************
//|		Common Dialog Structure definitions
//|*********************************************************************
struct SAVEASPROCINFO
{
	BOOL			bCreateEntry;
	BOOL			bSaveAsDefault;
	BOOL			bDemo;
	LPSTR			achPrfrence;
	LPSTR			achRumbaAppProfile;
	HINSTANCE		hCurrentInstance;
	HOST_TYPE_ENUM 	eHost;
};

struct OFNMEM
{
	char    szFile [COMM_FILE_BUFFER_LEN];
	char    szFileTitle [COMM_FILE_TITLE_BUFFER_LEN];
	char    szDirectory [MAX_PATH_LEN];
};

typedef OFNMEM      *POFNMEM;
typedef OFNMEM  FAR *LPOFNMEM;

struct OFN_EX
{
	LPOFNMEM        lpMem;
	OPENFILENAME    OFN;
};

typedef OFN_EX      *POFN_EX;
typedef OFN_EX  FAR *LPOFN_EX;


//|*********************************************************************
//|		Multi - Host Utility Constant definitions
//|*********************************************************************
#define RUMBA_szOpen	 			"Open"
#define RUMBA_szSave				"Save"

#define RUMBA_szMultiIniFile		"Setup.Ini"
#define RUMBA_szRumbaIniFileName	"Rumba.Ini"
#define	RUMBA_szSharedDir			"SharedDir"
#define RUMBA_szRUMBASYS_DLL		"RUMBASYS.DLL"
#define RUMBA_szRumbaFont			"RUMBAFNT.FON"

#define RumbaIconName				RumbaIcon
#define RumbaIconNameForAboutBox	"RumbaIcon"
#define RumbaIconNameForStartUp  	"RumbaIcon"
#define RumbaIconNameForLoadIcon  	"RumbaIcon"

#define MAINFRAME_EXE_NAME		"RumbaDsp.Exe"
#define AS400_EXE_NAME			"RumbaWsf.Exe"
#define VAX_EXE_NAME			"RumbaVt.Exe"
#define HP_EXE_NAME				"RumbaHp.Exe"	// 44497
#define MAINFRAME_PRT_EXE_NAME	"RumbaPrt.Exe"
#define AS400_PRT_EXE_NAME		"RumbaPrn.Exe"
#define AS400_FTX_EXE_NAME		"RumbaFil.Exe"


#define bMULTI					0x0000
#define bMAINFRAME				0x0001
#define bAS400					0x0002
#define bVAX					0x0004
#define bHP						0x0008

// Defines used for "bEndSlash" Parameters for "RUMBA_" calls

#define NO_SLASH	FALSE
#define ADD_SLASH	TRUE

//|*********************************************************************
//|		Multi - Host Utility Structure definitions
//|*********************************************************************
struct HOSTAVAILABLE
{
	WORD	bAvailable:		1,
			unassigned:		15;
	char	szPath [MAX_PATH_LEN];
};

typedef HOSTAVAILABLE *				PHOSTAVAILABLE;
typedef HOSTAVAILABLE FAR *			LPHOSTAVAILABLE;
typedef HOSTAVAILABLE				HOSTAVAILABLEARRAY[ END_HOST ];
typedef HOSTAVAILABLEARRAY FAR *	LPHOSTAVAILABLEARRAY;



/*
 * Make sure we don't try to pick up these typedef's again...
 */
#if !defined( _RUMBASYS_TYPEDEFS_ )

typedef UINT ( WINAPI * QUERYRUMBACACHEDIR )
(
	TCHAR * const		CacheDirBuffer,
	const UINT			BufferLen
);


typedef UINT ( WINAPI * QUERYRUMBAHOSTDIR )
(
	TCHAR * const			HostDirBuffer,
	const UINT				BufferLen,
	const HOST_TYPE_ENUM	WhichHost,
	const BOOL				WithMacroSubdir		= FALSE
);


typedef UINT ( WINAPI * QUERYRUMBAHOSTPRIVATEDIR )
(
	TCHAR * const			HostDirBuffer,
	const UINT				BufferLen,
	const HOST_TYPE_ENUM	WhichHost,
	const BOOL				WithMacroSubdir		= FALSE
);


typedef UINT ( WINAPI * QUERYRUMBAPRIVATEDIR )
(
	TCHAR * const		PrivateDirBuffer,
	const UINT			BufferLen
);


typedef UINT ( WINAPI * QUERYRUMBASYSTEMDIR )
(
	TCHAR * const		SystemDirBuffer,
	const UINT			BufferLen
);


#endif // _RUMBASYS_TYPEDEFS_


/*--------------------------------------------------------------------------*/
/* 'C' Function declarations.												*/
/*--------------------------------------------------------------------------*/

MFPUB
UINT
QueryRumbaCacheDir
(
	TCHAR * const		CacheDirBuffer,
	const UINT			BufferLen
);


MFPUB
UINT
QueryRumbaHostDir
(
	TCHAR * const			HostDirBuffer,
	const UINT				BufferLen,
	const HOST_TYPE_ENUM	WhichHost,
	const BOOL				WithMacroSubdir		= FALSE
);


MFPUB
UINT
QueryRumbaHostPrivateDir
(
	TCHAR * const			HostDirBuffer,
	const UINT				BufferLen,
	const HOST_TYPE_ENUM	WhichHost,
	const BOOL				WithMacroSubdir		= FALSE
);


MFPUB
UINT
QueryRumbaPrivateDir
(
	TCHAR * const		PrivateDirBuffer,
	const UINT			BufferLen
);


MFPUB
UINT
QueryRumbaSystemDir
(
	TCHAR * const		SystemDirBuffer,
	const UINT			BufferLen
);



#endif	/* _H_RUMBASYS_ */

