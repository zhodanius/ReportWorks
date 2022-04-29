// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   libchunk.h  $
// ================
//
// Description:
// ============
//
// LIBChunk class header
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/libchunk.h_v  $
// 
//    Rev 1.3   16 Aug 1995 10:15:14   dlm
// Minor changes.
// 
//    Rev 1.2   10 Aug 1995 10:03:08   dlm
// Added a second ChunkWrite() function to LIBChunk class.
// 
//    Rev 1.1   31 Jul 1995 09:13:12   dlm
// Added some members to LIBChunk class. Modified some prototypes.
// 
//    Rev 1.0   26 Jul 1995 13:15:32   dlm
// Initial revision.
// 
// ****************************************************************************

#if !defined(_LIBCHUNK_H_)
//
// Make a definition for this module.
//
#define _LIBCHUNK_H_

#include "libfile.h"

class LIBChunk : public CObject
{
	DECLARE_DYNAMIC( LIBChunk )
	
public:

	// member variables
	DWORD		m_Link;				// chunk number of next chunk in chain
	UINT		m_ChunkSize;		// chunk size
	DWORD		m_ChunkNumber;		// chunk number of this chunk
	PLIBFILE	m_pLibFile;			// LIBFile we belong to
	char*		m_pData;			// pointer to actual chunk data
	
	// member functions
					LIBChunk( );
					LIBChunk( UINT ChunkSize );
	virtual 		~LIBChunk( );
	virtual BOOL	ChunkRead( DWORD ChunkNo, LIBFile* pLibFile );
	virtual BOOL	ChunkWrite( void );
	virtual	BOOL	ChunkWrite( DWORD ChunkNumber, LIBFile *pLibFile );
	virtual DWORD	ChunkLinkGet( void );
	virtual void	ChunkLinkSet( LIBPosition Position );
#if defined( _DEBUG )
	virtual	void 	AssertValid( void ) const;
#endif

protected:
private:
			void	DeleteContents( void );
};

// Structure used by LIBChunk0 to obtain data from chunk 0 so it can
//  set member variables.
typedef struct Chunk0
{
	BYTE	Link0;	// 3-byte link
	BYTE	Link1;
	BYTE	Link2;
	BYTE	Major;	// major rev number of nosam file format
	BYTE	Minor;	// minor rev number of nosam file format
	DWORD	Free;	// chunk number of 1st chunk in free chain or NULL
	DWORD	App;	// 1st chunk num of main application chain or NULL
	DWORD	Next;	// chunk number of next unallocated chunk
	WORD	Size;	// file size in blocks
	WORD	ChkSz;	// chunk size in bytes
	WORD	Type;	// type code identifying library contents
} CHUNK0;
	
class LIBChunk0 : public LIBChunk
{
	DECLARE_DYNAMIC( LIBChunk0 )
	
public:

	// member variables
	UINT	m_RevMajor;
	UINT	m_RevMinor;
	DWORD	m_FreeChain;
	DWORD	m_AppChain;
	DWORD	m_NextUnallocatedChunk;		// number of next available chunk
//	UINT	m_Size;						// file size in blocks (obsolete?)
	UINT	m_ChunkSize;				// chunk size in bytes
	UINT	m_Type;						// type code identifying library contents
	
	// member functions
					LIBChunk0( UINT ChunkSize );
			void	InitializeMembers( BOOL bGet );	// TRUE -> data FROM chunk0 copied to LIBFile members
protected:
private:
};
#endif
