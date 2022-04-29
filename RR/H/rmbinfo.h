/* $Header:   H:/vcsmfc/h/rmbinfo.h_v   1.2   08 Oct 1996 16:50:00   amh  $ */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*	   Copyright (c) 1995 Wall Data Incorporated.  All Rights Reserved. 	*/
/*--------------------------------------------------------------------------*/
/* This file contains proprietary trade secrets of Wall Data, Incorporated.	*/
/* No part of this file may be reproduced or transmitted in any form or by 	*/
/* any means, electronic or mechanical, including photocopying and			*/
/* recording, for any purpose without the expressed written permission		*/
/* of Wall Data Incorporated.												*/
/*--------------------------------------------------------------------------*/
/* Purpose:		RumbaUIInfo class declaration.								*/
/*--------------------------------------------------------------------------*/
/* Authors:		Patrick D. Jenny								11/30/95	*/
/*--------------------------------------------------------------------------*/
/* Abstract:																*/
/*																			*/
/*--------------------------------------------------------------------------*/
/* $Revision:   1.2  $														*/
/* $Author:   amh  $													*/
/*--------------------------------------------------------------------------*/

#if defined( LOADER_TYPEDEFS_ONLY ) && !defined( _RMBINFO_TYPEDEFS_ ) && !defined( _RUMBA_INFO_H_ )
#define _RMBINFO_TYPEDEFS_

/*--------------------------------------------------------------------------*/
/* Type declarations.														*/
/*--------------------------------------------------------------------------*/

typedef UINT (CALLBACK * CREATERUMBAINFOPROC)
(
	LPVOID			*	ReturnedObject,
	HWND				ParentWindow,
	LPCTSTR				ApplicationName	= NULL
);


#elif !defined( _RUMBA_INFO_H_ )
#define _RUMBA_INFO_H_

#if !defined( DEBUG_CLASS )
#define DEBUG_CLASS( x )
#define MFPUB
#define MFPRV
#define	TRACE_CENTRY( x )
#define	TRACE_CEXIT
#define TRACE_DENTRY( x )
#define TRACE_DEXIT
#define	TRACE_ENTRY( x,y )
#define TRACE_EXIT
#endif

#if defined( _RINFO_INTERNAL_ )
#define	DLLIMPORT	_declspec( dllimport )
#else
#define	DLLIMPORT
#endif

/*--------------------------------------------------------------------------*/
/* Creation Function. 														*/
/*--------------------------------------------------------------------------*/
extern "C"
DLLIMPORT
UINT
CreateRumbaUIInfoObject
(
	LPVOID			*	ReturnedObject,
	HWND				ParentWindow,
	LPCTSTR				ApplicationName	= NULL
);


/*--------------------------------------------------------------------------*/
/* Type declarations.														*/
/*--------------------------------------------------------------------------*/
#if !defined( _RMBINFO_TYPEDEFS_ )

typedef UINT (CALLBACK * CREATERUMBAINFOPROC)
(
	LPVOID			*	ReturnedObject,
	HWND				ParentWindow,
	LPCTSTR				ApplicationName	= NULL
);

#endif


/*----------------------------------------------------------------------------*/
/* Constant Definitions.                                                      */
/*----------------------------------------------------------------------------*/
const	int	MAXLENABOUTBOXTEXT		=	128;
const	int	POINTSPERINCH			=	72;

const	int	MAXLENSTARTUPTEXT		=	256;
const	int	SUDIALOGBOXWIDTH		=	520;
const	int	SUDIALOGBOXHEIGHT		=	315;

const	int	INNER_SHIELD_WIDTH		=	351;
const	int	INNER_SHIELD_HEIGHT		=	85;
const	int	INNER_SHIELD_HILITE_WIDTH=	3;

/*----------------------------------------------------------------------------*/
/* Forward references.			                                              */
/*----------------------------------------------------------------------------*/
class	WdString;
class	AttributionLoader;
class	Attribution;
class	PopupHelpLoader;
class	PaletteManager;

enum	ACTION_ENUM;

/*--------------------------------------------------------------------------*/
/* RumbaUIInfo Class. 														*/
/*--------------------------------------------------------------------------*/
DEBUG_CLASS( RumbaUIInfo );
class RumbaUIInfo
{
	public: 	// Public Member Functions. **********************************


		MFPUB
		RumbaUIInfo
		(
			HWND		_ParentWindow,
			LPCTSTR		ApplicationName	= NULL
		);

		virtual
		MFPUB
		~RumbaUIInfo();

		virtual
		BOOL
		MFPUB
		ShowAboutBox
		(
			const	CLSID 	ClassID
		);

		virtual
		BOOL
		MFPUB
		StdControlAboutBox
		(
			const	CLSID	ClassID
		);

		virtual
		BOOL
		MFPUB
		ShowStartup
		(
			const	CLSID 	ClassID
		);

		virtual
		BOOL
		MFPUB
		EndStartup
		(
			BOOL	WaitUntilScreenEnds	= FALSE
		);

		virtual
		HANDLE
		MFPUB
		QuerySplashEventHandle();	

		inline
		void
		MFPUB
		SetParentWindow
		(
			HWND	ParentWindow
		)
		{
            m_ParentWindow = ParentWindow;
		}


	public:	// Public static Member Functions. **************************

		static
		void
		MFPUB
		PaletteCallBack
		(
			ACTION_ENUM			Action,
			long				UserData
		);

	private:	// Private static Member Functions. **************************

		static
		BOOL
		CALLBACK
		AboutBoxProc
		(
			HWND    AboutBoxHandle,
			UINT    Message,
			WPARAM  wParam,
			LPARAM  lParam
		);

		static
		BOOL
		CALLBACK
		StartUpProc
		(
			HWND    StartUpHandle,
			UINT    Message,
			WPARAM  wParam,
			LPARAM  lParam
		);

		static
		void
		CALLBACK
		StartupTimerProc
		(
			HWND	WindowHandle,
			UINT	Msg,
			UINT	Event,
			DWORD	Time
		);

		static
		MFPRV
		DWORD
		WINAPI
		SplashThreadProc
		(
			LPVOID		ThreadParameter
		);

		static
		void
		MFPRV
		DrawLogo
		(
			HWND			DlgWnd,
			RumbaUIInfo	*	This
		);

		static
		void
		MFPRV
		DrawObjectXLogo
		(
			HWND			DlgWnd,
			RumbaUIInfo	*	This
		);

	private:	// Private Member Functions. *********************************

		void
		MFPRV
		SetAboutStrings
		(
			BOOL		UseOemStrings		= TRUE,
			LPCTSTR		ApplicationName		= NULL,
			LPCTSTR		FeatureString		= NULL,
			LPCTSTR		SecondCopyrightLine	= NULL,
			LPCTSTR		TradeMarkLine		= NULL
		);

		void
		MFPRV
		SetStartupStrings
		(
			BOOL		UseOemStrings	= TRUE,
			LPCTSTR		ShieldString1	= NULL,
			LPCTSTR		ShieldString2	= NULL,
			LPCTSTR		ShieldString3	= NULL,
			LPCTSTR		CopyrightLine	= NULL
		);

		void
		MFPRV
		CenterWindow( void );

		int
		MFPRV
		GetVersionNumbers
		(
			LPTSTR				VersionString,
			UINT				SizeofVerString,
			BOOL				BothMajorAndMinor
		);


		void
		MFPRV
		LoadOemLibrary( void );

		void
		MFPRV
		DrawBeveledFrame
		(
			HDC				FrameDC,
			const LPRECT	prectWindow
		);

		void
		MFPRV
		DrawTextOnAboutBox( void );

		void
		MFPRV
		DrawTextOnObjectXAboutBox
		(
			HDC hdc
		);

		BOOL
		MFPRV
		ShowObjectXAboutBox
		(
			const	CLSID	ClassID
		);

		BOOL
		MFPRV
		QueryUserName
		(
			LPTSTR	UserName,
			int		UserNameLen
		);

		BOOL
		MFPRV
		QueryOrganizationName
		(
			LPSTR	OrganizationName,
			int		OrgNameLen
		);

		BOOL
		MFPRV
		QueryUserRegData
		(
			LPTSTR	DataField,
			LPTSTR	UserName,
			int		UserNameLen
		);

		void
		MFPRV
		DrawTextOnShield( void );

		void
		DrawStartupWindow
		(
			HDC WindowDC
		);

		void
		MFPRV
		DrawBackground
		(
			HDC DeviceContext
		);

		HBITMAP
		MFPRV
		LoadDIB
		(
			LPCTSTR	ResourceID,
			BOOL	MapToSystemColors
		);

		void
		MFPRV
		ShowSystemInformation( void );

		void
		MFPRV
		OnLeftButtonDoubleClick
		(
			const POINT	&	ClickPoint
		);

		void
		MFPRV
		QueryExtendedRUMBAInfo( void );

		BOOL
		MFPRV
		QuerySystemColors( void );

		BOOL
		MFPRV
		ContextHelp
		(
			HWND    DlgHandle,
			UINT    Message,
			WPARAM  Param1,
			LPARAM  Param2
		);


	private:	// Private Static Member Data. *******************************

		static	HINSTANCE				m_AttribInstance;
		static	int						m_InstanceCount;
		static	WORD					m_WinVersion;
		static	BOOL					m_Windows95;
		static	HINSTANCE				m_DLLInstance;
		static	AttributionLoader *		m_AttributionLoader;
		static	PopupHelpLoader	*		m_PopupHelpLoader;

	private:	// Private Member Data. **************************************

		enum{ DataBufferSize	= 1024 };
		CLSID				m_ClientClassID;
		Attribution *		m_AboutAttribution;
		Attribution *		m_StartAttribution;
		
		HWND				m_InformationWindow;
		HWND				m_ParentWindow;

		WdString	*		m_ApplicationExe;

		HOST_TYPE_ENUM		m_HostType;
		PRODUCT_APP_ENUM	m_ProductType;

		BOOL				m_InDialog;

		HBITMAP				m_MainBitmap;
		HBITMAP				m_SecondaryBitmap;

		// Startup timer info;
		UINT				m_TimerID;
		UINT				m_StartTime;
		BOOL				m_KillWindow;

		DWORD				m_ThreadID;				// ID of the thread we create to actually
													//	show the window & play the movie
		HANDLE				m_ThreadHandle;			// Handle of our thread

		HANDLE				m_EventHandle;			// Handle of event that get signaled when
													// Splash screen goes away.
		
		int					m_NameShieldX;
		int					m_NameShieldY;

		// Information Strings.
		LPTSTR				m_DataBuffer;
		LPTSTR				m_String1;			//pRUMBAName;			pShieldString1;
		LPTSTR				m_String2;			//pVersionString;		pShieldString2;
		LPTSTR				m_String3;			//pFeatureString;		pShieldString3;
		LPTSTR				m_String4;			//pProductNum;			pVersionString;
		LPTSTR				m_String5;			//pCopyright1;			pCopyright;
		LPTSTR				m_String6;			//pCopyright2;
		LPTSTR				m_String7;			//pTradeMark;
		LPTSTR				m_String8;			//pSerialNum;

		LPCTSTR				m_ApplicationName;
		LPCTSTR				m_FeatureString;
		LPCTSTR				m_SecondCopyrightLine;
		LPCTSTR				m_TradeMarkLine;

		enum SYS_COLORS
		{
			SYS_COLORS_0,
			SYS_COLORS_16,
			SYS_COLORS_256,
			SYS_COLORS_HIGH_COLOR
		};

		SYS_COLORS				m_SystemColors;
		PaletteManager *		m_PaletteManager;

		BOOL				m_IsObjectX;
};	// End Of RumbaUIInfo Class.

/*--------------------------------------------------------------------------*/
#endif	// ! _RUMBA_INFO_H_
