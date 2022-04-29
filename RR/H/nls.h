/* $Header:   D:/R&R Project/archives/H/NLS.H_V   1.1   Oct 07 2002 09:25:18   Admin  $ */
#if !defined( _NLS_H_ )
#define _NLS_H_
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
/* Purpose:		National Language Support class declaration.				*/
/*--------------------------------------------------------------------------*/
/* Authors:		Patrick D. Jenny								12/16/95	*/
/*--------------------------------------------------------------------------*/
/* Abstract:																*/
/*																			*/
/*--------------------------------------------------------------------------*/
/* $Revision:   1.1  $														*/
/* $Author:   Admin  $													*/
/*--------------------------------------------------------------------------*/

//--------------------------------------------------------------------------//
//	Constant value declarations.											//
//--------------------------------------------------------------------------//

//	IBM MRI Values
const	UINT NLS_PORTUGUESE      = 2922;
const	UINT NLS_NETHERLANDS     = 2923;
const	UINT NLS_ENGLISH         = 2924;
const	UINT NLS_FINNISH         = 2925;
const	UINT NLS_DANISH          = 2926;
const	UINT NLS_FRENCH          = 2928;
const	UINT NLS_GERMAN          = 2929;
const	UINT NLS_SPANISH         = 2931;
const	UINT NLS_ITALIAN         = 2932;
const	UINT NLS_NORWEGIAN       = 2933;
const	UINT NLS_SWEDISH         = 2937;
const	UINT NLS_ENGUPDBCS       = 2938;
const	UINT NLS_GERMANMNCS      = 2939;
const	UINT NLS_FRENCHMNCS      = 2940;
const	UINT NLS_ITALIANMNCS     = 2942;
const	UINT NLS_ENGUPCASE       = 2950;
const	UINT NLS_TURKISH         = 2956;
const	UINT NLS_GREEK           = 2957;
const	UINT NLS_ICELANDIC       = 2958;
const	UINT NLS_JAPANESE        = 2962;
const	UINT NLS_BGMDUTCHMNCS    = 2963;
const	UINT NLS_BGMFRENCHMNCS   = 2966;
const	UINT NLS_BRAZPORTUGUESE  = 2980;
const	UINT NLS_CNDFRENCHMNCS   = 2981;
const	UINT NLS_ENGMIXDBCS      = 2984;
const	UINT NLS_KOREANDBCS      = 2986;
const	UINT NLS_TAIWANDBCS      = 2987;
const	UINT NLS_CHINADBCS       = 2989;
const	UINT NLS_PORTFRENCHMNCS  = 2996;

//	Flags for MessageBoxEx
#define MB_NOFLASH         	0x80000000L		// NLS_MessageBoxEx

//	Buffer Sizes
const	UINT RING_BUFFER_SIZE	= 1024;
const	UINT TEXTLENMAX			= 255;
const	UINT PATHMAX			= 128;

// Creation Success Codes.
const	UINT	NLS_SUCCEEDED			= 0;
const	UINT	NLS_E_NOT_ENOUGH_MEM	= 0x80000001;
const 	UINT	NLS_E_LIBRARY_NOT_FOUND	= 0x80000002;


//--------------------------------------------------------------------------//
//	Link specification macros.												//
//--------------------------------------------------------------------------//
#if defined( NLS_INTERNAL )
	#define DllApi __declspec( dllexport )
#else
	#if !defined (DllApi)
		#define DllApi __declspec( dllimport )
	#endif
#endif	// defined( NLS_INTERNAL )


//--------------------------------------------------------------------------//
//	Class forward referenceing.												//
//--------------------------------------------------------------------------//
class	NLS {};					
class	TempNlsString {};

//--------------------------------------------------------------------------//
//	NLS Object Creation Function Prototype / TypeDef.						//
//--------------------------------------------------------------------------//
extern "C"
{
	DllApi
	UINT
	CALLBACK
	CreateNLS
	(
		NLS 		**	const	ppNLS,
		const	HINSTANCE		CallingInstance,
		LPCTSTR			const	NlsDllName
	);
}

// Creation function pointer typedef
typedef UINT (CALLBACK * CreateNLSProc)
(
	NLS 		**	const	ppNLS,
	const	HINSTANCE		CallingInstance,
	LPCTSTR			const	NlsDllName
);

//--------------------------------------------------------------------------//
//	NLS Class specification.												//
//--------------------------------------------------------------------------//
class NLS
{
	friend
	DllApi
	UINT
	CALLBACK
	CreateNLS
	(
		NLS 		**	const	ppNLS,
		const	HINSTANCE		CallingInstance,
		LPCTSTR			const	NlsDllName
	);

	public:		// Public methods. -------------------------------------------

		virtual
		~NLS( void );

		virtual
		BOOL
		NLS_IsRestrict( void );

		virtual
		BOOL
		NLS_SetLang
		(
			const LCID	NewLocaleIdentifier
		);

		virtual
		int
		NLS_InitWindow
		(
			const HWND		WindowHandle,
			const UINT		CaptionId,
			LPCTSTR	const	MenuName
		);

		virtual
		HMENU
		NLS_LoadMenu
		(
			LPCTSTR	const	MenuName
		);

		virtual
		HBITMAP
		NLS_LoadBitmap
		(
			LPCTSTR	const	BitmapResName
		);

		virtual
		HCURSOR
		NLS_LoadCursor
		(
			LPCTSTR	const	CursorResName
		);

		virtual
		HICON
		NLS_LoadIcon
		(
			LPCTSTR	const	IconResName
		);


		virtual
		int
		NLS_LoadString
		(
			const	UINT	StringId,
			LPTSTR	const	StringBuffer,
			const	int		BufferLength
		);

		virtual
		int
		NLS_MessageBoxEx
		(
			const	HWND	ParentWindow,
			LPCTSTR	const	MessageString,
			LPCTSTR	const	TitleString,
			const	UINT	MessageBoxFlags
		);

		virtual
		int
		NLS_Language
		(
			LPTSTR	const	BufferToHoldLangID,
			const	int		BufferLength
		);

		virtual
		HINSTANCE
		NLS_QueryInstance( void );

		virtual
		HWND
		NLS_CreateDialog
		(
			LPCTSTR	const	DialogResName,
			const HWND		ParentWindow,
			const DLGPROC	DialogProcedure
		);

		virtual
		HWND
		NLS_CreateDialogIndirect
		(
			LPCDLGTEMPLATE	const	TemplatePointer,
			const HWND				ParentWindow,
			const DLGPROC			DialogProcedure
		);

		virtual
		HWND
		NLS_CreateDialogParam
		(
			LPCTSTR	const 	DialogResName,
			const	HWND	ParentWindow,
			const	DLGPROC	DialogProcedure,
			const	LPARAM	InitParam
		);

		virtual
		HWND
		NLS_CreateDialogIndirectParam
		(
			LPCDLGTEMPLATE	const	TemplatePointer,
			const HWND				ParentWindow,
			const DLGPROC			DialogProcedure,
			const LPARAM			InitParam
		);

		virtual
		int
		NLS_DialogBox
		(
			LPCSTR	const	DialogResName,
			const HWND		ParentWindow,
			const DLGPROC	DialogProcedure
		);


		virtual
		int
		NLS_DialogBoxIndirect
		(
			LPCDLGTEMPLATE	const	TemplatePointer,
			const HWND				ParentWindow,
			const DLGPROC			DialogProcedure
		);


		virtual
		int
		NLS_DialogBoxParam
		(
			LPCTSTR	const	DialogResName,
			const HWND		ParentWindow,
			const DLGPROC	DialogProcedure,
			const LPARAM	InitParam
		);

		virtual
		int
		NLS_DialogBoxIndirectParam
		(
			LPCDLGTEMPLATE	const	TemplatePointer,
			const HWND				ParentWindow,
			const DLGPROC			DialogProcedure,
			const LPARAM			InitParam
		);

		virtual
		HRSRC
		NLS_FindResource
		(
			LPCTSTR	const 		ResourceName,
			LPCTSTR	const 		ResourceType,
			HINSTANCE *	const	ResourceInstance
		);

		virtual
		HANDLE
		NLS_LoadImage
		(
			LPCSTR	const	ImageResName,
			const	UINT	ImageType,
			const	int		ImageWidth,
			const	int		ImageHeight,
			const	UINT	ColorTyping
		);

		virtual
		LCID
		NLS_GetRUMBADefaultLCID( void );

		virtual
		LPCTSTR
		tmpstr
		(
			UINT	StringID
		);

		virtual
		BOOL
		NLS_LoadLibExp
		(
			LPCTSTR const lpPath
		);

		virtual
		BOOL
		MapLCIDToMriDir
		(
			LPTSTR	const	DirName,
			const	int		DirNameLength
		);

	public:	// Public Static Member Functions. *********************************

		static
		LCID
		GetNLS_RUMBADefaultLCID( void );



	private:	// Private Member Functions. *********************************

		NLS
		(
			const HINSTANCE	CallingInstance,
			LPCTSTR			NLsDllName
		);

		BOOL
		IsCurrentWindow
		(
			const HWND	Window
		);

		inline
		BOOL
		DoesFileExist
		(
			LPCTSTR const lpFile
		);

		HINSTANCE
		LoadNlsLibrary
		(
			const	HINSTANCE	CallingInstance,
			LPCTSTR	const		NlsLibName,
			LPTSTR	const		FullyQualifiedNlsLibName
		);

		void
		LoadNlsOfficeResource( void );

	private:	// Private Static Member Data. *******************************

		static int			m_InstanceCount;
		static HINSTANCE	m_OfficeResInstance;
		static LCID			m_CurrentLCID;

	private:	// Private Member Data. **************************************

		HINSTANCE	m_CallingInstanceHandle;
		HINSTANCE	m_NLSResourceInstance;
		TCHAR		m_NlsResName[ _MAX_PATH ];
		LPTSTR		m_pRingBuffer;
		LPTSTR		m_pRingPointer;

};	// End Of NLS Class.


/*--------------------------------------------------------------------------*/
#endif	// ! _NLS_H_

