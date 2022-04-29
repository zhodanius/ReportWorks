// Added conditionals to allow this header to be multiply included.
// 
//    Rev 1.0   27 Oct 1995 11:12:16   sbc
// Initial revision.
// 
// Initial revision.
// 
// ****************************************************************************

#if !defined(_FAX_H_)
//
// Make a definition for this module.
//
#define _FAX_H_

#include "winspool.h"
#include "tapi.h"

// Telephony API function typedefs

// lineInitialize TAPI function
typedef LONG (FAR PASCAL *LPFNLINEINITIALIZE) (LPHLINEAPP,HINSTANCE,LINECALLBACK,LPCSTR,LPDWORD);

//lineNegotiateAPIVersion

typedef LONG (FAR PASCAL *LPFNLINENEGOTIATE) (HLINEAPP,DWORD,DWORD,DWORD,LPDWORD,LPLINEEXTENSIONID);

//lineGetDevCaps

typedef LONG (FAR PASCAL *LPFNLINEGETDEVCAPS) (HLINEAPP,DWORD,DWORD,DWORD,LPLINEDEVCAPS);

//lineOpen
typedef LONG (FAR PASCAL *LPFNLINEOPEN) (HLINEAPP,DWORD,LPHLINE,DWORD,DWORD,DWORD,DWORD,DWORD,LPLINECALLPARAMS const);   

//lineGetID
typedef LONG (FAR PASCAL *LPFNLINEGETID) (HLINE,DWORD,HCALL,DWORD,LPVARSTRING,LPCSTR);   

//lineClose
typedef LONG (FAR PASCAL *LPFNLINECLOSE) (HLINE);

//lineShutdown
typedef LONG (FAR PASCAL *LPFNLINESHUTDOWN) (HLINEAPP);
     


/////////////////////////////////////////////////////////////////////////////
// CRrFax command target

class CRrFax : public CObject
{   
//	DECLARE_DYNCREATE(CRrFax)
//protected:
public:
	void SetDocument(CRrDoc * pDoc);
	BOOL IsFaxInstalled(void);
	void SendReport(void);
	//CRrFax(CRrDoc *pDoc );
	CRrFax();

	
// Attributes
private:
	CRrDoc * m_pDoc;
	
		
	CString m_csFaxDevice;
	CString m_csFaxPort;
	CString m_csFaxDeviceName;
	HINSTANCE	m_hTapiLib;
	BOOL m_bFaxInstalled;
	//CRrDoc *m_pDoc; // current document

	void freeTapiLib(void);
	BOOL loadTapiLib(void);
	BOOL GetFaxDevice(void);
	BOOL DoesFaxExist(void);

		// This is the TAPI callback function, it is 
	// declared static because TAPI won't give us a "this" pointer
	static void CALLBACK lineCallback(	HANDLE 	hDevice,
										DWORD	dwMsg,
										DWORD	dwCallBackInstance,
										DWORD	dwParam1,
										DWORD	dwParam2,
										DWORD	dwParam3 );
protected:
		 	
// Operations
public:

private:
	

// Implementation
public:
	virtual ~CRrFax();
// Static routines
public:
protected:
	// Generated message map functions
	//{{AFX_MSG(CRrFax)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
};

#endif	// !defined(_FAX_H_)