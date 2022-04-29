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
// $Log:   H:/VCSMFC/H/_INDEX.H_V  $
// 
//    Rev 1.2   06 Jun 1996 14:12:46   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.1   17 Jul 1995 09:27:32   dlm
// Changed functions to CRrDoc member functions and variables to CRrDoc
//  member variables.
// 
//    Rev 1.0   16 Mar 1995 16:14:32   sbc
// Initial revision.
// 
//    Rev 1.2   18 Feb 1994 15:26:32   sjo
// I am merging the RRWINNSX branch back onto the RRWIN tree. This branch was
// setup to allow me to port my RR 5.1 NSX, SMT and DBV changes to RRW and
// RSW.
// 
//    Rev 1.1.1.0   21 Jan 1994 16:49:38   sjo
// I added an extern for the NSX decompression routine.
// 
//    Rev 1.1   19 Nov 1993 17:42:46   sbc
// Add extern C for C++
// 
//    Rev 1.0   14 Oct 1993 10:12:42   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef __INDEX_H_

//
// Make a definition for this module.
//
#define __INDEX_H_

#include "index.h"

#if defined (_KLINIT_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif


//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//

//
// Structure Section:
// Place in this section any structure definitions.
//

//
// Global Data Section:
// Place in this section any global data.
//


#if 0
GLOBAL 	LPKLNTXFILE near NTX;	/* global pointer to current file descriptor*/
GLOBAL 	KLNODE	far * near NodePath;/* pointer to array of KLNODE strucs */
GLOBAL 	int	near NPIndex;	/* level index in node path array */
GLOBAL 	int	near KlBufs[MAXNTXS]; /* which kl buffers are in use (file pos of
													node if using small memory model) */
GLOBAL 	int	near IndexType;	/* dbase, clipper, or foxbase? */
#endif


//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#if 0
extern	int lklcurrent(char FAR *ntxfd,int tkey);
extern	void lextractkey(char FAR *key,long FAR *recno);
extern	void lklbcdtof(char FAR *nP,char FAR *fP);
extern	void lkldecomp(char FAR *key,long FAR *recP,int keypos);
extern	int lkldecode(char FAR *key,struct klntxfile FAR *ntx,int itype);
extern	void lklxdecomp(char FAR *node,int keylen,char type,char FAR *key,long FAR *recP,int keypos,char FAR *FAR *v ,char FAR *FAR *e );
extern	int extractnkeys(void );
extern	int readnode(long nodePos,int init,int priority);
extern	int lprevkey(char FAR *key,long FAR *recno);
extern	int lnextkey(char FAR *key,long FAR *recno);
extern	int leafnode(void );
extern	void extractpos(long *pos);
extern	int ltravup(int FAR *index,long FAR *nPos);
extern	int ltravdown(long nPos,char FAR *key,long FAR *recno);
extern	int lklcmpbcd(char FAR *left,char FAR *right);
extern	void lklidecomp(char FAR *key,long FAR *recP,int keypos,char FAR *FAR *v ,char FAR *FAR *e );
extern	void lklencode(char FAR *key,struct klntxfile FAR *ntx,int itype);
extern	int lklftobcd(char FAR *fP,char FAR *nP);
extern   void lklnsxdecomp(char FAR *key,long FAR *recP,int keypos);
#endif


#undef GLOBAL
#endif // end __INDEX_H_

// *************************** End of File ************************************

