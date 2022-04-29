// srvritem.h : interface of the CRrSrvrItem class
//

class CRrSrvrItem : public COleServerItem
{
	DECLARE_DYNAMIC(CRrSrvrItem)

// Constructors
public:
	CRrSrvrItem(CRrDoc* pContainerDoc);

// Attributes
	CRrDoc* GetDocument() const
		{ return (CRrDoc*)COleServerItem::GetDocument(); }

// Implementation
public:
	~CRrSrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);

protected:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
};

/////////////////////////////////////////////////////////////////////////////
