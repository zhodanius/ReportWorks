// ****************************************************************************
//
//      (C) Copyright 1995 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $WorkFile$   rrassert.h $
// ================
//
// Description:
// ============
// An advanced version of assert that displays the failed condition 
// along with the file and line number. 
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/rrassert.h_v  $
// 
//    Rev 1.3   15 Dec 1995 12:30:26   par
// Needed to define THIS_FILE during a release build.
// 
//    Rev 1.2   07 Dec 1995 16:44:04   par
// Prepare to use _RRDEBUG to create a release build with ASSERT code.
// 
//    Rev 1.1   16 Oct 1995 09:44:48   par
// Only replace assert for debug compiles.  
// 
//    Rev 1.0   20 Sep 1995 16:41:58   par
// Initial revision.
// 
// Initial revision.
// 
// ****************************************************************************
//
// Make a definition for this module.
//
#ifndef _RRASSERT_H_
#define _RRASSERT_H_


/////////////////////////////////////////////////////////////////////////////
// R&R Advanced Diagnostic support

#if defined(_DEBUG) || defined(_RRDEBUG)
#ifdef ASSERT
#undef ASSERT

#ifdef _WIN32
// Note: file names are still ANSI strings (filenames rarely need UNICODE)
BOOL AFXAPI AdvancedAssertFailedLine(LPCSTR lpszCondition, LPCSTR lpszFileName, int nLine) ;

// Undefining THIS_FILE is the same technique MFC uses. 
// This way, CPP modules can still undefine THIS_FILE and 
// then define it as a static character string. Sounds efficient. 
#ifdef _DEBUG
#undef THIS_FILE
#endif
#define THIS_FILE __FILE__

#define ASSERT(f) \
	do \
	{ \
	if ( !(f) && AdvancedAssertFailedLine(_T(#f), THIS_FILE, __LINE__) ) \
		AfxDebugBreak(); \
	} while (0) \


#else // !_WIN32 

extern "C" void AFXAPI AdvancedAssertFailedLine(LPCSTR lpszCondition, LPCSTR lpszFileName, int nLine) ;
#define ASSERT(f)  ((f) ? (void)0 : ::AdvancedAssertFailedLine(#f, THIS_FILE, __LINE__))

#endif // _WIN32
#endif // !ASSERT
#endif // !_DEBUG
#endif // !_RRASSERT_H_
