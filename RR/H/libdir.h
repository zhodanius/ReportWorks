// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   libdir.h  $
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
// $Log:   H:/vcsmfc/h/libdir.h_v  $
// 
//    Rev 1.1   16 Aug 1995 10:16:10   dlm
// Minor changes.
// 
//    Rev 1.0   26 Jul 1995 13:16:00   dlm
// Initial revision.
// 
// ****************************************************************************

#if !defined(_LIBDIR_H_)

//
// Make a definition for this module.
//
#define _LIBDIR_H_

#include "libname.h"		// for LIBName

// for "forward" references
class LIBPosition;
typedef LIBPosition * PLIBPOSITION;
class LIBFile;
typedef LIBFile * PLIBFILE;
class LIBName;
typedef LIBName * PLIBNAME;
typedef CObList * PLIBNAMELIST;


const UINT NAME_LENGTH_SIZE = 1;
const UINT STARTING_CHUNK_SIZE = 4;

class LIBFileDir : public CObject
{
	friend class LIBFile;		// let LIBFile get at our private members
	
	DECLARE_DYNAMIC( LIBFileDir )
	
public:
	// Member functions
							LIBFileDir( );
	virtual					~LIBFileDir( );
	virtual	BOOL 			NameAdd( LPSTR const Name, PLIBPOSITION pContentPosition, BOOL Unconditional = FALSE );
	virtual	BOOL 			NameAdd( PLIBNAME LibName, BOOL Unconditional = FALSE );
	virtual	BOOL			NameDelete( LPCSTR Name, BOOL DeleteContents = TRUE );
	virtual	BOOL			NameRename( LPCSTR OldName, LPCSTR NewName );
	virtual	BOOL			NameReplaceContents( LPCSTR Name, PLIBPOSITION ContentPosition );
	virtual	PLIBNAMELIST 	NameListCreate( void );
	virtual	void			NameListDestroy( PLIBNAMELIST pNameList, BOOL DeleteListItself = TRUE );
	virtual	PLIBNAME		NameSelect( LPCSTR Name );
#if defined( _DEBUG )
	virtual	void 			AssertValid( void ) const;
#endif
	
protected:
private:
	// Member variables
	PLIBFILE m_pLibFile;		// pointer to LIBFile for which this is a directory
	char	m_NameHeader[NAME_LENGTH_SIZE + STARTING_CHUNK_SIZE];	// length of current name, starting chunk number of it's contents
	DWORD	m_NameChunk;		// chunk number of position of current name
	UINT	m_NameOffset;		// byte offset of position of current name
	UINT	m_NameCount;		// number of names in this directory
	UINT	m_DeletedNameCount;	// number of deleted names in this directory
//	PLIBNAMELIST m_pNameList;
	
	// Member functions
	virtual	PLIBNAME		NameFind( LPCSTR Name, LPSTR ActualName = NULL );
	virtual	BOOL			_NameAdd( PLIBNAME pLibName );
	virtual	BOOL			NamesRewrite ( void );
};

#endif
