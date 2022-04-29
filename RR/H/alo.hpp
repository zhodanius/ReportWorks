//--------------------------------------------------------------------------//
//	   Copyright (c) 1995 Wall Data Incorporated.  All Rights Reserved. 	//
//--------------------------------------------------------------------------//
// This file contains proprietary trade secrets of Wall Data, Incorporated. //
// No part of this file may be reproduced or transmitted in any form or by 	//
// any means, electronic or mechanical, including photocopying and			//
// recording, for any purpose without the expressed written permission		//
// of Wall Data Incorporated.												//
//--------------------------------------------------------------------------//
// Purpose:		AbstratLicenseObject class declaration.						//
//--------------------------------------------------------------------------//
// Authors:		John P. Lemire								11/28/95		//
//--------------------------------------------------------------------------//
// Abstract:		This is the class definition of the "Abstract Licensing	//
//				object", which serves to provide a layer of abstraction		//
//				between its clients (all other WallData component objects)	//
//				and the real licensing technology which is assumed to be	//
//				changing over time as it improves.							//
//--------------------------------------------------------------------------//
// $Revision:   3.1  
//--------------------------------------------------------------------------//

#if defined( LOADER_TYPEDEFS_ONLY ) && !defined( _ALO_TYPEDEFS_ ) && !defined( Alo_Hpp )
#define _ALO_TYPEDEFS_

/*--------------------------------------------------------------------------*/
/* Forward declarations.													*/
/*--------------------------------------------------------------------------*/
class	Alo;
class	WdEventSink;


/*--------------------------------------------------------------------------*/
/* Type declarations.														*/
/*--------------------------------------------------------------------------*/

typedef HRESULT (CALLBACK * CreateAloProc)
(
	REFIID					AloIID,
	Alo 		**	const	ppAlo,
	WdEventSink *	const	Sink	= NULL
);


#elif !defined( Alo_Hpp )
#define Alo_Hpp

#undef DllApi

#if defined( ALO )
	#define DllApi __declspec( dllexport )
#else
	#define DllApi __declspec( dllimport )
#endif	// defined( ALO )


//--------------------------------------------------------------------------//
// Common Header Files.														//
//--------------------------------------------------------------------------//
#pragma warning( disable: 4201 )	// nonstandard extension used : nameless struct/union
#pragma warning( disable: 4514 )	// unreferenced inline function has been removed
#include	<ObjBase.H>
#pragma warning( default: 4201 )


//--------------------------------------------------------------------------//
//	TypeDef/Struct/Enum Declarations.										//
//--------------------------------------------------------------------------//
enum ALOType
{
	ALO_Expired			= 0x00,		// License has expired.
	ALO_Evaluation		= 0x01,		// Licensed only for software evaluation.
	ALO_Design			= 0x03,		// Licensed for application design, and evaluation.
	ALO_User			= 0x05,		// Licensed for normal user interaction, and evaluation.
	ALO_Administrator	= 0x0D,		// Licensed for administration, user, and evaluation.
	ALO_Mask			= 0xFF		// Abstract License Object license value mask.
};

//--------------------------------------------------------------------------//
//	Class forward referenceing.												//
//--------------------------------------------------------------------------//
class	Alo;					
class	WdEventSink;			

//--------------------------------------------------------------------------//
//	License Object Creation Function Prototype / TypeDef.					//
//--------------------------------------------------------------------------//
extern "C"
{
	DllApi
	HRESULT
	CreateAlo
	(
		REFIID					AloIID,
		Alo 		**	const	ppAlo,
		WdEventSink *	const	Sink	= NULL
	);
}


#if !defined( _ALO_TYPEDEFS_ )

typedef HRESULT (CALLBACK * CreateAloProc)
(
	REFIID					AloIID,
	Alo 		**	const	ppAlo,
	WdEventSink *	const	Sink	= NULL
);

#endif

//--------------------------------------------------------------------------//
// Abstract License Class.													//
//--------------------------------------------------------------------------//
class Alo
{
	friend
	DllApi
	HRESULT
	CreateAlo
	(
		REFIID					AloIID,
		Alo 		**	const	ppAlo,
		WdEventSink *	const	Sink
	);

	public:		// Public methods. -------------------------------------------

		virtual
		~Alo();

		inline
		int
		Validate
		(
			REFIID	ComponentIID
		){
			long	TickCount	= (long) GetTickCount();
			DWORD	Bits		= (DWORD) TickCount;
			long	ShiftTick	= TickCount;
			long	Result		= ObfuscatedValidate( ComponentIID, TickCount );

			Bits &= 0xFFFFFF;

			while( Bits != 0 )
			{
				Bits		&= Bits - 1;
				TickCount	>>= 1;
				ShiftTick	>>= 2;
				Result		>>= 1;
			}

			Result ^= TickCount;
			Result ^= ShiftTick;
			
			return( Result & ALO_Mask );
		};


	private:	// Private methods. ------------------------------------------

		Alo();

		virtual
		long
		ObfuscatedValidate
		(
			REFIID		ComponentIID,
			const long	TickCount
		);

		inline
		long
		ValidateEx
		(
			REFIID	ComponentIID
		);


	private:	// Private static properties. --------------------------------

		static IID	m_IID;

};	// End of Abstract License class.

//--------------------------------------------------------------------------//
#endif	// !defined( Alo_Hpp )
