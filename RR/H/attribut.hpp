/*--------------------------------------------------------------------------*/
/*	   Copyright (c) 1996 Wall Data Incorporated.  All Rights Reserved. 	*/
/*--------------------------------------------------------------------------*/
/* This file contains proprietary trade secrets of Wall Data, Incorporated. */
/* No part of this file may be reproduced or transmitted in any form or by 	*/
/* any means, electronic or mechanical, including photocopying and			*/
/* recording, for any purpose without the expressed written permission		*/
/* of Wall Data Incorporated.												*/
/*--------------------------------------------------------------------------*/
/* Purpose:		Attribution class Definition.								*/
/*--------------------------------------------------------------------------*/
/* Authors:		Gary D. Bissiri							01/23/96			*/
/*--------------------------------------------------------------------------*/
/* Abstract:																*/
/*																			*/
/*--------------------------------------------------------------------------*/
// $Revision:   1.1  $
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* Common Header Files.														*/
/*--------------------------------------------------------------------------*/
#include "AttrDefs.H"

/*--------------------------------------------------------------------------*/
/* Loader Defines.														*/
/*--------------------------------------------------------------------------*/
#if defined( LOADER_TYPEDEFS_ONLY ) && !defined( _ATTRIBUT_TYPEDEFS_ ) && !defined( _ATTRIBUT_H_ )
#define _ATTRIBUT_TYPEDEFS_

class	Attribution;

typedef
Attribution *
(
WINAPI *
CREATEATTRIBUTIONOBJECT
)(
	const CLSID &		ClassID
);

#endif



#if !defined( _ATTRIBUT_H_ )
#define _ATTRIBUT_H_

/*--------------------------------------------------------------------------*/
/* Forward refrences.														*/
/*--------------------------------------------------------------------------*/
class	Attribution;
class	NLS;

extern "C"
{

	MFEXPORT
	Attribution *
	CreateAttributionObject
	(
		const CLSID &		ClassID
	);

}  // End of extern "C"


#if !defined( _ATTRIBUT_TYPEDEFS_ )
#define _ATTRIBUT_TYPEDEFS_

typedef
Attribution *
(
WINAPI *
CREATEATTRIBUTIONOBJECT
)(
	const CLSID &		ClassID
);

#endif  // _ATTRIBUT_TYPEDEFS_


/*--------------------------------------------------------------------------*/
/* InterfaceManager Class Declaration.										*/
/*--------------------------------------------------------------------------*/
class Attribution
{

	friend
	MFEXPORT
	Attribution *
	CreateAttributionObject
	(
		const CLSID &		ClassID
	);


	public: 	// Public Member Functions. *********************************

		virtual
		MFPUB
		~Attribution
		(
			void
		);

		inline
		int
		MFPUB
		GetBrandName
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		){
			return GetString( IDS_ATRB_BRAND_NAME, Buffer, MaxLengthBuffer );
		}

		inline
		int
		MFPUB
		GetTitle
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		){
			return GetString( IDS_ATRB_TITLE, Buffer, MaxLengthBuffer );
		}

		inline
		int
		MFPUB
		GetProductName
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		){
			return GetString( IDS_ATRB_PRODUCT_NAME, Buffer, MaxLengthBuffer );
		}

		inline
		int
		MFPUB
		GetComponentName
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		){
			return GetString( IDS_ATRB_COMPONENT, Buffer, MaxLengthBuffer );
		}

		inline
		int
		MFPUB
		GetAbout
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		){
			return GetString( IDS_ATRB_ABOUT, Buffer, MaxLengthBuffer );
		}

		inline
		int
		MFPUB
		GetHelpTopic
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		){
			return GetString( IDS_ATRB_HELP_TOPIC, Buffer, MaxLengthBuffer );
		}

		inline
		int
		MFPUB
		GetInfoButton
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		){
			return GetString( IDS_ATRB_INFO_BUTTON, Buffer, MaxLengthBuffer );
		}

		inline
		int
		MFPUB
		GetSupportButton
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		){
			return GetString( IDS_ATRB_SUPPORT_BUTTON, Buffer, MaxLengthBuffer );
		}

		inline
		int
		MFPUB
		GetSplashCopyright
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		){
			return GetString( IDS_ATRB_SPLASH_COPYRIGHT, Buffer, MaxLengthBuffer );
		}

		// Caller must call DeleteObject() on returned HBITMAP
		inline
		HBITMAP
		MFPUB
		GetAboutLogo
		(
			HWND	ParentWindow,
			BOOL	MapToSystemColors
		){

			return LoadDIBitMap( ParentWindow, MapToSystemColors,
									IDBM_ATRB_ABOUT_LOGO, m_AboutResource );
		}

		// Caller must call DeleteObject() on returned HBITMAP
		inline
		HBITMAP
		MFPUB
		Get256AboutLogo
		(
			HWND	ParentWindow,
			BOOL	MapToSystemColors
		){

			return LoadDIBitMap( ParentWindow, MapToSystemColors,
									IDBM_ATRB_ABOUT_LOGO_256, m_AboutResource );
		}

		// Caller must call DeleteObject() on returned HBITMAP
		inline
		HBITMAP
		MFPUB
		GetHCAboutLogo
		(
			HWND	ParentWindow,
			BOOL	MapToSystemColors
		){

			return LoadDIBitMap( ParentWindow, MapToSystemColors,
									IDBM_ATRB_ABOUT_LOGO_HIGH_COLOR, m_AboutResource );
		}

		// Caller must call DeleteObject() on returned HBITMAP
		inline
		int
		MFPUB
		GetAboutAnimation
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer
		){
			return QueryAnimation( Buffer, MaxLengthBuffer ); 
		}

		// Caller must call DeleteObject() on returned HBITMAP
		inline
		HBITMAP
		MFPUB
		GetSplashDIBitMap
		(
			HWND	ParentWindow,
			BOOL	MapToSystemColors
		){

			return LoadDIBitMap( ParentWindow, MapToSystemColors,
							IDBM_ATRB_SPLASH, m_SplashResource );
		}

		// Caller must call DeleteObject() on returned HBITMAP
		inline
		HBITMAP
		MFPUB
		Get256SplashDIBitMap
		(
			HWND	ParentWindow,
			BOOL	MapToSystemColors
		){

			return LoadDIBitMap( ParentWindow, MapToSystemColors,
							IDBM_ATRB_SPLASH_256, m_SplashResource );
		}

		// Caller must call DeleteObject() on returned HBITMAP
		inline
		HBITMAP
		MFPUB
		GetHCSplashDIBitMap
		(
			HWND	ParentWindow,
			BOOL	MapToSystemColors
		){

			return LoadDIBitMap( ParentWindow, MapToSystemColors,
							IDBM_ATRB_SPLASH_HIGH_COLOR, m_SplashResource );
		}

		inline
		HICON
		MFPUB
		GetSmallIcon
		(
			void
		){

			return LoadAttrbIcon( IDICON_ATRB_SMALL_ICON );
		}

		inline
		HICON
		MFPUB
		GetMediumIcon
		(
			void
		){

			return LoadAttrbIcon( IDICON_ATRB_MEDIUM_ICON );
		}

		inline
		HICON
		MFPUB
		GetLargeIcon
		(
			void
		){

			return LoadAttrbIcon( IDICON_ATRB_LARGE_ICON );
		}

/*
		// Caller must call DeleteObject() on returned HBITMAP
		inline
		HBITMAP
		MFPUB
		GetComponentNameDIBitMap
		(
			HWND	ParentWindow,
			BOOL	MapToSystemColors
		){

			return LoadDIBitMap( ParentWindow, MapToSystemColors,
									IDBM_ATRB_COMPONENT_SPLASH, NULL, m_AttribLibInstance );
		}
*/
		inline
		int
		MFPUB
		GetCopyright1
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		){
			return GetString( IDS_ATRB_COPYRIGHT_TM_FIELD_1, Buffer, MaxLengthBuffer );
		}

		inline
		int
		MFPUB
		GetCopyright2
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		){
			return GetString( IDS_ATRB_COPYRIGHT_TM_FIELD_2, Buffer, MaxLengthBuffer );
		}

		inline
		int
		MFPUB
		GetCopyright3
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		){
			return GetString( IDS_ATRB_COPYRIGHT_TM_FIELD_3, Buffer, MaxLengthBuffer );
		}

		inline
		int
		MFPUB
		GetCopyright4
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		){
			return GetString( IDS_ATRB_COPYRIGHT_TM_FIELD_4, Buffer, MaxLengthBuffer );
		}

		inline
		int
		MFPUB
		GetCopyright5
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		){
			return GetString( IDS_ATRB_COPYRIGHT_TM_FIELD_5, Buffer, MaxLengthBuffer );
		}

		inline
		int
		MFPUB
		GetCopyright6
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		){
			return GetString( IDS_ATRB_COPYRIGHT_TM_FIELD_6, Buffer, MaxLengthBuffer );
		}

		inline
		int
		MFPUB
		GetCopyright7
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		){
			return GetString( IDS_ATRB_COPYRIGHT_TM_FIELD_7, Buffer, MaxLengthBuffer );
		}

		virtual
		int
		QuerySerialNumber
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer
		);

	private: 	// Private Member Functions. *********************************

		Attribution
		(
			const	CLSID &		ClassID
		);

		void
		MFPRV
		QueryResourceDLLName
		(
			const	CLSID &		ClassID,
			LPTSTR				ResourceName
		);

		void
		MFPRV
		QueryRegValues
		(
			LPTSTR				ResourceName,
			HKEY				SubKey
		);

		BOOL
		MFPRV
		QuerySystemMriDir
		(
			LPTSTR	DirPath,
			int		Length

		);

		int
		MFPRV
		GetErrorString
		(
			const	int		StringID,
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		);

	private: 	// Private Virtual Member Functions. *********************************

				// These must be virtual so that the inline functions can
				// find them in the v-table at compile time when the calling
				// module not statically linking to this module.

		virtual
		int
		GetString
		(
			const	int		StringID,
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer

		);

		virtual
		HBITMAP
		LoadDIBitMap
		(
			HWND		ParentWindow,
			BOOL		MapToSystemColors,
			int			BitMapID,
			LPTSTR		ResourcePath,
			HINSTANCE	ResurceInstance = NULL
		);

		virtual
		int
		MFPRV
		QueryAnimation
		(
			TCHAR * const	Buffer,
			const	int		MaxLengthBuffer
		);
	
		virtual
		HICON
		MFPRV
		LoadAttrbIcon
		(
			int		IconID
		);
	
	public:	 // More Public Member Functions. *********************************
			 // Placed here to be at end of V-Table

		virtual
		void
		GetHelpFile
		(
			LPTSTR		HelpFile,
			const int	MaxLength,
			DWORD &		TopicID,
			BOOL &		UseMVHelp
		);


	private: 	// Private Static Member Data. ******************************

		static	int			InstanceCount;

	private: 	// Private Member Data. *************************************


		NLS*			m_NLS;
		HINSTANCE		m_AttribLibInstance;
		LPTSTR			m_SerialNumber;
		LPTSTR			m_SplashResource;
		LPTSTR			m_AboutResource;
		int				m_IDSOffset;
		int				m_IDBMSplashOffset;
		int				m_IDBMAboutOffset;
		TCHAR			m_RegSubKey[ _MAX_PATH ];
};


#endif // _ATTRIBUT_H_
