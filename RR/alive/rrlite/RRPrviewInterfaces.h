/* This header file machine-generated by mktyplib.exe */
/* Interface to type library: RepViewObjects */

#ifndef _RepViewObjects_H_
#define _RepViewObjects_H_

DEFINE_GUID(LIBID_RepViewObjects,0x66960E20L,0xDE25,0x11CF,0x87,0x6F,0x44,0x45,0x53,0x54,0x00,0x00);
#ifndef BEGIN_INTERFACE
#define BEGIN_INTERFACE
#endif

DEFINE_GUID(IID_IRepView,0x66960E21L,0xDE25,0x11CF,0x87,0x6F,0x44,0x45,0x53,0x54,0x00,0x00);

/* Definition of interface: IRepView */
#undef INTERFACE
#define INTERFACE IRepView

DECLARE_INTERFACE_(IRepView, IDispatch)
{
BEGIN_INTERFACE
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

    /* IRepView methods */
    STDMETHOD(get_ReportURL)(THIS_ BSTR FAR* path) PURE;
    STDMETHOD(put_ReportURL)(THIS_ BSTR path) PURE;
    STDMETHOD(get_ImagePath)(THIS_ BSTR FAR* path) PURE;
    STDMETHOD(put_ImagePath)(THIS_ BSTR path) PURE;
    STDMETHOD(get_LanguageID)(THIS_ BSTR FAR* path) PURE;
    STDMETHOD(put_LanguageID)(THIS_ BSTR path) PURE;
};

DEFINE_GUID(DIID_DRepViewEvents,0x66960E22L,0xDE25,0x11CF,0x87,0x6F,0x44,0x45,0x53,0x54,0x00,0x00);

/* Definition of dispatch interface: DRepViewEvents */
#undef INTERFACE
#define INTERFACE DRepViewEvents

DECLARE_INTERFACE_(DRepViewEvents, IDispatch)
{
BEGIN_INTERFACE
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif
};

DEFINE_GUID(CLSID_RepView,0x66960E23L,0xDE25,0x11CF,0x87,0x6F,0x44,0x45,0x53,0x54,0x00,0x00);

#ifdef __cplusplus
class RepView;
#endif

#endif