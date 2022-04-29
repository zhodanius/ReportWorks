// ****************************************************************************
//
//      (C) Copyright 1992-1993 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
//
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/memo.h_v  $
// 
//    Rev 1.0   16 Mar 1995 16:12:50   sbc
// Initial revision.
// 
//    Rev 1.2   02 Sep 1994 16:24:28   sjo
// Changed the starting memo offset from an int to a long, because memos can
// be large.
// 
//    Rev 1.1   18 Feb 1994 15:40:16   sjo
// I am merging the RRWINNSX branch back onto the RRWIN tree. This branch was
// setup to allow me to port my RR 5.1 NSX, SMT and DBV changes to RRW and
// RSW.
// 
//    Rev 1.0   20 Jan 1994 17:06:34   sjo
// Initial revision.
// 
// ****************************************************************************
//
///* memo.h - definitions for memo handling */

#ifndef _MEMO_H_

#define _MEMO_H_

// MEMO_ID is what we use to identify a memo.  It contains a file_id,
//  			an offset within the memo where this memo starts, the length
//				and some flags (like if it is an FPT).
typedef struct memo_id
	{
	int				memo_file;
	FOUR				memo_offset;
	long				length;
	unsigned int 	mflags;
	} MEMO_ID;

// MF_DB4_MEMO - this struct contains the info we need to know about a
//					db4 memo.
typedef struct mf_db4_memo
	{
	FOUR				beg_pos;		// starting file position of the db4 mem piece
	long				size;			// the size of this piece
	long				start;		// the starting memo offset of this piece
	} MF_DB4_MEMO;

// MF_MEMO_HDLR_PKT - this is the info packet used when calling
//				mf_memo_hdlr().  The memo_id identifies the memo we want, 
//				memo_position is the byte we want, cp is actual character and
//				the db4 info at the bottom is so we can move around within
//				db4 memos.		
typedef struct mf_memo_hdlr_pkt 
	{
	FOUR				memo_position; // the memo byte you are interested in
	MEMO_ID			memo_id;		// The file and id identify the memo.
	char				*cp;
	MF_DB4_MEMO		current;   	// current, prev and next_block are used to
	MF_DB4_MEMO		prev;			// save DB4 information.  This is need for
	FOUR				next_block;	// repeated calls to mfgetmch.
	} MF_MEMO_HDLR_PKT;	

// MEMO_BUFF_HDR - one of these on each memo buffer. It points to the buffer
//					with the actual memo contents.
typedef struct memo_buff_hdr		
	{
	struct memo_buff_hdr far	*next_ptr;	// ptr to next memo buffer
	FOUR		start_offset;					// starting offset in memo
	int		num_bytes;					   // number of bytes in buffer
	int 		buff_size;						// size of the buffer (this is fixed)
	char far *memo_buff_ptr;				// ptr to the buffer
	} MEMO_BUFF_HDR;
	
typedef MEMO_BUFF_HDR far *LMEMO_BUFF_HDR;
	
// MEMOBUFF_CHAIN_HDR - This header points to all the buffered info about
//		a memo field.  The actual memo contents can be obtained by looking
//		at the MEMO_BUFF_HDR linked list.
typedef struct memobuff_chain_hdr
	{
	struct memobuff_chain_hdr far *next_ptr;	// ptr to next in memobuff chain
	MEMO_ID			memo_id; // identifies the memo (usually pos in memo file)
	MF_DB4_MEMO		current;		// current DB4 Memo block info
	MF_DB4_MEMO		prev;       // previous DB4 Memo block info
	FOUR				next_block;	// For DB4 memos, the next block in the chain
	LMEMO_BUFF_HDR memo_buff_hdr;	// ptr to the first memo buff header
	} MEMOBUFF_CHAIN_HDR;

// ptr to begining of the buffer chain

typedef MEMOBUFF_CHAIN_HDR far *LMEMOBUFF_CHAIN_HDR;

#define NUM_MEMO_CHAINS	3
#define NUM_BUFFERS_PER_CHAIN	2
#define NUM_BYTES_PER_BUFFER	20


#define MEMO_IS_EMPTY	-1

// The following are action codes for mf_memo_hdlr - the memo handler
#define INIT_BUFFERS		1
#define SET_FPOS			2
#define GET_CHAR			3
#define GET_FPOS			4

#define MFFOXMEMO			0x0020

#endif
