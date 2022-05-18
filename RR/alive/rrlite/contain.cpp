// ****************************************************************************
//
//		(C) Copyright 1996 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
// Container object
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/alive/rrlite/contain.cpv  $
// 
//    Rev 1.0   20 Mar 1997 12:10:24   smh
// Initial revision.
// 

#include <windows.h>
#include "contain.h"

//////////////////////////////////////////////////
// Constructor
COleClientSite::COleClientSite( void )
{
	m_cRef = 0;
}

//////////////////////////////////////////////////
// Destructor
COleClientSite::~COleClientSite( void )
{
}

//////////////////////////////////////////////////
// IUnknown members for COleClientSite object
STDMETHODIMP COleClientSite::QueryInterface( REFIID riid, void** ppv )
{
	if ( IsEqualIID( riid, IID_IUnknown ) || IsEqualIID( riid, IID_IOleClientSite ))
	{
		*ppv = this;
		AddRef();
		return NOERROR;
	}
	return E_NOINTERFACE;
}

//////////////////////////////////////////////////
// Keep track
STDMETHODIMP_(ULONG) COleClientSite::AddRef( void )
{
	return ++m_cRef;
}

//////////////////////////////////////////////////
// Free it up
STDMETHODIMP_(ULONG) COleClientSite::Release( void )
{
	--m_cRef;
	if ( !m_cRef )
		delete this;
	return m_cRef;
}

//////////////////////////////////////////////////
// Object wants to be saved
STDMETHODIMP COleClientSite::SaveObject(void)
{
    return NOERROR;
}

//////////////////////////////////////////////////
// Object wants a moniker of some sort - sorry
STDMETHODIMP COleClientSite::GetMoniker( DWORD dwAssign, DWORD dwWhich, LPMONIKER *ppmk )
{
    *ppmk = NULL;

	return ResultFromScode( E_NOTIMPL );
}

//////////////////////////////////////////////////
// Object wants poitner to IOleContainer interface
STDMETHODIMP COleClientSite::GetContainer( LPOLECONTAINER *ppContainer )
{
    // only necessary if you allow linking to embeddings
    *ppContainer = NULL;
    return ResultFromScode( E_NOTIMPL );
}

//////////////////////////////////////////////////
// Object wants to be seen
STDMETHODIMP COleClientSite::ShowObject( void )
{
	return NOERROR;	// trust me
}

//////////////////////////////////////////////////
// object is showing or hiding
STDMETHODIMP COleClientSite::OnShowWindow( BOOL bShow )
{
	return NOERROR;
}

//////////////////////////////////////////////////
// Called when the object needs more room in the container
STDMETHODIMP COleClientSite::RequestNewObjectLayout( void )
{
	return ResultFromScode( E_NOTIMPL );
}
