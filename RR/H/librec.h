// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   librec.h  $
// ================
//
// Description:
// ============
//
// LIBRec class header
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/librec.h_v  $
// 
//    Rev 1.1   31 Jul 1995 09:14:50   dlm
// Added some member functions to LIBRec.
// 
//    Rev 1.0   26 Jul 1995 13:17:22   dlm
// Initial revision.
// 
// ****************************************************************************

#if !defined(_LIBREC_H_)

	#include "libfile.h"
//
// Make a definition for this module.
//
#define _LIBREC_H_

class LIBRec : public CObject
{
	DECLARE_DYNAMIC( LIBRec )
	
public:

	// member variables
	UINT	m_Size;			// record size
	UINT	m_Type;			// record type
	LPSTR	m_pData;		// pointer to actual record data
	
	// member functions
					LIBRec( );
					LIBRec( UINT RecSize );
	virtual 		~LIBRec( );
			void	TypeSet( UINT Type ) { m_Type = Type; };
			void	SizeSet( UINT Size ) { m_Size = Size; };
			BOOL	RecordRead( PLIBFILE pLibFile );
			BOOL	RecordWrite( PLIBFILE pLibFile );
			void	DeleteContents( void );
#if defined( _DEBUG )
	virtual	void 	AssertValid( void ) const;
#endif

protected:
private:
};

#endif
