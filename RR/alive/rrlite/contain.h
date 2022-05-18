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
// Header for page data object
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/contain.h_v  $
// 
//    Rev 1.0   20 Mar 1997 12:12:30   smh
// Initial revision.
// 

#ifndef _CONTAIN_H_
#define _CONTAIN_H_

class COleClientSite : public IOleClientSite
    {
    protected:
        ULONG               m_cRef;

    public:
        COleClientSite();
        ~COleClientSite();

        STDMETHODIMP QueryInterface( REFIID, void** );
        STDMETHODIMP_(ULONG) AddRef();
        STDMETHODIMP_(ULONG) Release();

        STDMETHODIMP SaveObject();
        STDMETHODIMP GetMoniker( DWORD, DWORD, LPMONIKER * );
        STDMETHODIMP GetContainer( LPOLECONTAINER * );
        STDMETHODIMP ShowObject();
        STDMETHODIMP OnShowWindow( BOOL );
        STDMETHODIMP RequestNewObjectLayout( void );
    };

typedef COleClientSite *PCOleClientSite;

#endif //_CONTAIN_H_
