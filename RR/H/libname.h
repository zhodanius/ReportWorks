// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   libname.h  $
// ================
//
// Description:
// ============
//
// 
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/libname.h_v  $
// 
//    Rev 1.2   16 Aug 1995 10:16:30   dlm
// Minor changes.
// 
//    Rev 1.1   31 Jul 1995 09:14:04   dlm
// Added declarations for constructor, destructor.  Changed name of a
//  pointer member variable to reflect that it's a pointer.
// 
//    Rev 1.0   26 Jul 1995 13:16:42   dlm
// Initial revision.
// 
// ****************************************************************************

#if !defined(_LIBNAME_H_)

#include "util.h"			// for ZDATE, ZTIME

//
// Make a definition for this module.
//
#define _LIBNAME_H_

// for forward references
class LIBPosition;
typedef LIBPosition  * PLIBPOSITION;


typedef struct stamp
{
	ZDATE yzsDate;			/* date structure */
	ZTIME yzsTime;			/* time structure */
	char yzsUser[1];		/* really strlen(user id string)+1 chars */
} STAMP;

typedef STAMP * PSTAMP;

class LIBName : public CObject
{
	DECLARE_DYNAMIC( LIBName )

public:
	// member functions
					LIBName( );
					~LIBName( );
	LPCSTR			NameGet( void );
	void			NameSet( LPCSTR Name );
	DWORD			ChunkGet( void );
	PLIBPOSITION	PositionGet( void );
	void			ChunkSet( DWORD const Chunk );
	PSTAMP			TimeStampGet( void );
	void			TimeStampSet( PSTAMP const TimeStamp );
	LPCSTR			AnnotationGet( void );
	void			AnnotationSet( LPCSTR Annotation );
#if defined( _DEBUG )
	virtual	void 	AssertValid( void ) const;
#endif
	
protected:
private:
	// member variables
	CString	m_Name;					// name
	DWORD	m_Chunk;				// starting chunk number for contents associated with m_Name
	PSTAMP	m_pTimeStamp;			// pointer to time stamp or NULL
	CString	m_Annotation;			// report annotation
#if defined RSW
	CString	m_DataSource;			// data source name
#endif
};

typedef LIBName * PLIBNAME;
typedef CObList * PLIBNAMELIST;

#endif
