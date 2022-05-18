// ****************************************************************************
//
//      (C) Copyright 1996 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
// Header for Accusoft wrapper functions
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/accusoft.h_v  $
// 
//    Rev 1.1   19 Dec 1996 16:27:20   smh
// Added auto-comment header.
// 

#ifndef _ACCUSOFT_H_
#define _ACCUSOFT_H_

#include "imglib.h"

///////////////////////////////////////////////////////////////
// Wrapper functions

HBITMAP DIBtoDDB( HANDLE, int, int, int );
void deleteImage( HANDLE, int );
void displayDdb( HANDLE, HBITMAP, HDC, int, int );
HINSTANCE loadImageLib( void );
int loadImageToMem( HANDLE, LPSTR );
void printFast( HANDLE, int, HDC, int, int, int, int );
void setCropRect( HANDLE, int, int, int );


#endif	// #ifndef _ACCUSOFT_H_