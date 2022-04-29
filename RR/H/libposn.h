// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   libposn.h  $
// ================
//
// Description:
// ============
//
// LIBPosition class header
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/libposn.h_v  $
// 
//    Rev 1.1   16 Aug 1995 10:15:44   dlm
// Minor changes.
// 
//    Rev 1.0   26 Jul 1995 13:17:02   dlm
// Initial revision.
// 
// ****************************************************************************

#if !defined(_LIBPOSN_H_)
//
// Make a definition for this module.
//
#define _LIBPOSN_H_

// The LIBPosition class exists solely as a mechanism for hiding the concept of
//  chunks, upon which LIBFile is currently built.
class LIBPosition
{
	friend class LIBFile;		// let LIBFile's member functions get at our data
	friend class LIBFileDir;	// let LIBFileDir's member functions get at our data
	friend class LIBChunk;		// let LIBChunk's member functions get at our data
	
public:
	LIBPosition( DWORD ChunkNumber = 0 )  { m_ChunkNumber = ChunkNumber; }
protected:
private:
	DWORD m_ChunkNumber;		// position in a LIBFile
};

typedef LIBPosition  * PLIBPOSITION;

#endif
