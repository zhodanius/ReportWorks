// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   libfile.h  $
// ================
//
// Description:
// ============
//
// LIBFile class header
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/libfile.h_v  $
// 
//    Rev 1.8   23 Feb 1996 10:53:56   dlm
// Added ExtensionFind member function.
// 
//    Rev 1.7   21 Aug 1995 12:38:46   dlm
// 
//    Rev 1.6   16 Aug 1995 10:16:46   dlm
// Minor changes.
// 
//    Rev 1.5   10 Aug 1995 10:01:44   dlm
// Added "creating library" flag to LIBFile class.
// 
//    Rev 1.4   31 Jul 1995 09:11:48   dlm
// Changed BytesWriteNext prototype to have a default third argument value.
// 
//    Rev 1.3   26 Jul 1995 13:14:40   dlm
// Added or updated a bunch of stuff.  Split some stuff out.
// 
//    Rev 1.2   23 Jun 1995 11:32:18   dlm
// Removed include of product.h.
// 
//    Rev 1.1   23 Jun 1995 09:50:26   dlm
// Added comment for ChunkWrite().
// 
//    Rev 1.0   23 Jun 1995 09:36:48   dlm
// Initial revision.
// 
// ****************************************************************************

#if !defined(_LIBFILE_H_)
//
// Make a definition for this module.
//
#define _LIBFILE_H_

#include "libdir.h"
#include "libposn.h"

	// Needs exception handling work.

//const UINT DOS_SHARING_VIOLATION =	32;	/* (0x20) int 21 share error code */

const UINT LIB_MAJ_REV =	1;
const UINT LIB_MIN_REV =	3;	// so RR v3 can't read version 4 libraries
const UINT LIB_MIN_V3 =		2;	// old R&R for dBASE version (yyopen uses this)

const UINT LIB_DEFAULT_CHUNK_SIZE = 512;
const UINT LIB_OLD_CHUNK_SIZE = 32;
const UINT LIB_LINK_SIZE = 3;
const DWORD LIB_CHUNK_NUMBER_MAX = ( ( 1L << 24 ) - 1 );

const int LIB_EBADCHUNK =		0x100;		// bad chunk number
const int LIB_ENOCURPOS	=		0x101;		// no current position
const int LIB_ENOMEMORY	=		0x102;		// insufficient memory
const int LIB_EBADBLOCK	=		0x103;		// invalid block number
const int LIB_EDISK	=			0x104;		// disk error
const int LIB_EDISKFULL	=		0x105;		// disk full
const int LIB_ECANTOPEN	=		0x106;		// can't open file
const int LIB_EFILEFULL	=		0x107;		// file full
const int LIB_EBADREV =			0x108;		// invalid file revision
const int LIB_EFEXCEPT =		0x109;		// file exception generated

const int LIB_EBADAPP =			0x200;		// invalid application chain
const int LIB_ENAMEUSED	=		0x201;		// name in use
const int LIB_ENONAME =			0x202;		// no such name
const int LIB_ERROR_TEXT_MAX = 80;

const UINT LibMajRev = 1;	// major revision level of report libraries for current product
const UINT LibMinRev = 3;	// minor revision level of report libraries for current product

// Library file (derived from MFC CFile - unbuffered, binary disk i/o)
class LIBFile : public CFile
{
	friend class LIBFileDir;
	
	DECLARE_DYNAMIC( LIBFile )
	
public:
	// member variables
	int			m_Error;				// error code
	LIBFileDir	m_Directory;			// library directory
	
	// member functions
							LIBFile( );
	virtual 				~LIBFile( );
	virtual BOOL			Open( const char* FileName, UINT OpenFlags,
								UINT* Type, UINT ChunkSize = LIB_DEFAULT_CHUNK_SIZE );
	virtual BOOL			Create( const char* FileName, UINT OpenFlags,
								UINT Type, UINT ChunkSize = LIB_DEFAULT_CHUNK_SIZE );
	virtual void			Close( void );
	virtual BOOL			BytesReadNext( UINT Count, LPSTR lpBuffer );
	virtual BOOL			BytesWriteNext( UINT Count, LPSTR lpBuffer, BOOL RewriteFlag = FALSE );
	virtual DWORD			GetAppChain( );
	virtual BOOL			PositionFree( LIBPosition* pPosition );
	virtual BOOL			PositionGetFree( LIBPosition* Position );
	virtual void			PositionSet( LIBPosition* Position );
	virtual void			ExtensionDefaultAppend( CString& Filename );
	virtual void			ExtensionDefaultSet( const CString& Extension );
	virtual const CString&	ErrorToText( void );
	virtual	DWORD			GetNextUnallocatedChunk( ) { return m_NextUnallocatedChunk; }
	virtual BOOL			HeaderUpdate( void );			// yywrhdr.cpp
	virtual int				ExtensionFind( CString& path );

#if defined( _DEBUG )
	virtual	void 			AssertValid( void ) const;
#endif
	
protected:
private:
	// member variables
	BOOL	m_bCreate;					// flag indicating we're creating this library
	BOOL	m_HeaderChanged;			// flag indicating need to rewrite file header
	DWORD	m_FreeChain;				// chunk number of start of free chunk chain
	DWORD	m_AppChain;					// chunk number of start of main application chain
	DWORD	m_NextUnallocatedChunk;		// number of next available chunk
	DWORD	m_Chunk;					// chunk number of current file position
	UINT	m_ChunkOffset;				// offset in m_Chunk of current file position
//	UINT	m_Size;						// file size in blocks (obsolete?)
	UINT	m_Type;						// type code identifying library contents
	UINT	m_ChunkSize;				// chunk size in bytes
	UINT	m_ChunksPerBlock;			// corresponding number of chunks per block
	CString m_DefaultExtension;
	CString m_ErrorText;

	// member functions
	virtual void	CreateInit( UINT Type, UINT ChunkSize );
	virtual void	PositionSet( DWORD ChunkNumber );
	virtual BOOL	PositionFree( DWORD ChunkNumber );
};

typedef LIBFile  * PLIBFILE;

// Report-library derived class
class LIBFileRep : public LIBFile
{
public:
protected:
private:
};

// UDF-library derived class
class LIBFileUDF : public LIBFile
{
public:
protected:
private:
};

#endif
