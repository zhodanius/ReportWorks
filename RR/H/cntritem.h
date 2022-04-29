// ****************************************************************************
//
//		(C) Copyright 1995 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $Workfile:   cntritem.h  $
// ================
//
// Description:
// ============
//
// 
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/h/cntritem.h_v  $
// 
//    Rev 1.23   14 May 1997 13:29:54   par
// Separated picture generation into its own function.
// 
//    Rev 1.22   23 Apr 1997 15:03:44   par
// Functions to generate an image from an object.  Mostly directory parsing.
// 
//    Rev 1.21   05 Mar 1997 17:15:10   par
// Add Save As Picture string in preparation for saving OLE objects as pictures.
// 
//    Rev 1.20   29 Feb 1996 15:56:04   par
// Add On Command Help support so that F1 would work in dialogs.  OnHelp() in the 
// main frame must call the CWnd version in order for F1 to work in MFC style 
// dialogs.
// 
//    Rev 1.19   31 Jan 1996 11:22:44   par
// Fix OLE printing problem.  Cropping was fixed and text align was fixed.
// 
//    Rev 1.18   17 Jan 1996 17:20:54   par
// Removed unused functions.
// 
//    Rev 1.17   12 Jan 1996 17:36:00   par
// Fix cropping implementation.  Cropping rect should scale as extent grows.
// 
//    Rev 1.16   11 Jan 1996 16:00:40   par
// New file format for OLE objects to fix bugs.  The extent of the object needed
// to be maintained for the life of the object.
// 
//    Rev 1.15   10 Jan 1996 12:52:34   par
// Instead of maintaining a separate selection pointer that is used to determine if
// an OLE object is selected, the OLE code now uses the R&R CurFld to determine
// if an OLE object is currently selected.
// 
//    Rev 1.14   14 Dec 1995 18:03:08   par
// Add support for object cropping.
// 
//    Rev 1.13   12 Dec 1995 16:42:10   par
// Add help button support to object properties dialog.
// 
//    Rev 1.12   11 Dec 1995 12:04:48   par
// Minimize runtime size by placing ifdefs around interactive only code.
// 
//    Rev 1.11   01 Dec 1995 09:53:16   jpb
// fix a runtime conditional problem
// 
//    Rev 1.10   30 Nov 1995 17:53:42   sjo
// Changes required for the runtime port to 32 bit MFC.
// 
//    Rev 1.9   22 Nov 1995 19:00:20   par
// Add OLE Object info to report spec.
// 
//    Rev 1.8   10 Nov 1995 18:17:00   par
// Fixing major problems with properties.
// 
//    Rev 1.7   10 Nov 1995 11:59:06   par
// Since some of the definitions were moved from resource.h to wdialog.h, now 
// wdialog.h needs to be included in this header.
// 
//    Rev 1.6   10 Nov 1995 11:13:02   par
// Added functionality to the object properties dialog.
// 
//    Rev 1.5   08 Nov 1995 16:44:22   par
// Adding features to the object properties dialog.
// 
//    Rev 1.4   08 Nov 1995 14:54:48   par
// An object has properties that can be edited.
// 
//    Rev 1.3   26 Oct 1995 17:36:36   par
// The scrolling messages are now passed along to the OLE active objects so that they will also scrol
// l.
// 
//    Rev 1.2   20 Oct 1995 13:33:56   par
// The OLE objects are now connected to the R&R lists. More work needs to be done but this is a good 
// start.
// 
// Initial revision.
// 
// ****************************************************************************

#ifndef _CNTRITEM_H_
#define _CNTRITEM_H_
#include "wdialog.h"

class CRrDoc ;
class CRrView ;

class CRrCntrItem : public COleClientItem
{
	DECLARE_SERIAL(CRrCntrItem)

// Constructors
public:
	CRrCntrItem(CRrDoc* pContainer = NULL) ;
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CSize    m_extentHimetric ;  // last extent from server -- in device.  (in hi-metric for speed).
	fieldhdr m_fhdr           ;
protected:
	twodhdr  m_thdr           ;
	CSize    m_sizeActual     ;
	CSize    m_sizeCrop       ;
	WORD     m_wScaling       ;

public:
	fieldhdr* GetFieldHeader()       { return &m_fhdr      ; }
	twodhdr*  Get2dHeader()          { return &m_thdr      ; }
	WORD      GetScaling()     const { return m_wScaling   ; }
	CSize     GetActualSize()  const { return m_sizeActual ; }
	CSize     GetCropSize()    const { return m_sizeCrop   ; }
	CRect     GetRect()        const ;
	// The hite is returned Plus 1 because legacy code computes the bottom 
	// but subtracting 1 from the height. Don't know why, but I must deal with it. 
	int       GetHite()        const { return m_fhdr.fr.bottom - m_fhdr.fr.top  + 1 ; }
	int       GetRectWidth()   const { return m_fhdr.fr.right  - m_fhdr.fr.left ; }
	int       GetRectHeight()  const { return m_fhdr.fr.bottom - m_fhdr.fr.top  ; }
	CSize     GetRectSize()    const { return CSize(m_fhdr.fr.right - m_fhdr.fr.left, m_fhdr.fr.bottom - m_fhdr.fr.top); }
	void      SetRect(CRect r) ;
	void      SetRect(int left, int top, int right, int bottom) ;
	void      OnEditProperties() ;
	void      OnOleSaveAsPicture() ;
	BOOL      SaveAsPicture(const CString& csImagePathname) ;
	void      SetObjectCrop() { SetObjectCrop(GetRectWidth(), GetRectHeight()) ; }
	void      SetObjectCrop(int nNewWidth, int nNewHeight) ;
	void      SetInches() ;
	
// Operations
public:
	CRrDoc*   GetDocument()    { return (CRrDoc* )COleClientItem::GetDocument()   ; }
	CRrView*  GetActiveView()  ;
	void      InvalidateItem() ;
	void      UpdateFromServerExtent() ;
	void      CopyIconRepresentation(COleDataObject* pDataObject) ;
	BOOL      CreateCloneFrom(const CRrCntrItem* pSrcItem) ;
protected:
	void      BuildScreenOrder(BOOL bFillBackwards) ;

// Implementation
public:
	~CRrCntrItem() ;
	// Drawing
	BOOL Draw(CDC* pDC, LPCRECT lpBounds, DVASPECT nDrawAspect=(DVASPECT)-1) ;   // defaults to m_nDrawAspect
#ifdef _DEBUG
	virtual void AssertValid() const ;
	virtual void Dump(CDumpContext& dc) const ;
#endif
	virtual void Serialize(CArchive& ar) ;
	virtual void OnActivate() ;
	virtual void OnDeactivateUI(BOOL bUndoable) ;
	//virtual COleDataSource* OnGetClipboardData(BOOL bIncludeLink, LPPOINT lpOffset, LPSIZE lpSize) ;
	
protected:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam) ;
	virtual BOOL OnChangeItemPosition(const CRect& rectPos  ) ;
	virtual void OnGetItemPosition   (      CRect& rPosition) ;
	virtual BOOL OnScrollBy(CSize sizeExtent) ;
} ;

extern CLIPFORMAT g_cfObjectDescriptor ;
BOOL SaveEnhancedMetafileAsPicture(CRrDoc* pDoc, HENHMETAFILE hEnhMetafile, int nPictureWidth, int nPictureHeight, const CString& csImagePathname) ;


#ifdef INTERACTIVE
/////////////////////////////////////////////////////////////////////////////
// CNumEdit control

class CNumEdit : public CEdit
{
// Construction
public:
	CNumEdit(CRrDoc* pDoc) : m_pDoc(pDoc) {}

	CRrDoc* m_pDoc ;  // Need to access doc decimal separator & winBeep. 
	
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNumEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) ;
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
} ;

/////////////////////////////////////////////////////////////////////////////
// COleObjectDialog dialog

class COleObjectDialog : public CDialog
{
// Construction
public:
	COleObjectDialog(CRrDoc* pDoc, CWnd* pParent=NULL) ;   // standard constructor

// Dialog Data
public:
	//{{AFX_DATA(COleObjectDialog)
	enum { IDD = IDD_OBJECT_PROPERTIES };
	BOOL            m_bModified      ;
	int             m_nCurrentScale  ;
	int             m_nCurrentWidth  ;
	int             m_nCurrentHeight ;
	int             m_nActualWidth   ;
	int             m_nActualHeight  ;
	int             m_nOleType       ;
	CString         m_csTypeName     ;
	CString         m_csAppName      ;
	
protected:
	int             m_nNewScale      ;
	int             m_nNewWidth      ;
	int             m_nNewHeight     ;
	
	CString         m_csType         ;
	CString         m_csWidthInches  ;
	CString         m_csHeightInches ;
	CSpinButtonCtrl m_spinWidth      ;
	CSpinButtonCtrl m_spinHeight     ;
	CNumEdit        m_numWidth       ;
	CNumEdit        m_numHeight      ;
	//}}AFX_DATA
	CRrDoc*         m_pDoc           ;
protected:
	void SetSize() ;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleObjectDialog)
protected:
	virtual BOOL OnInitDialog() ;
	virtual void DoDataExchange(CDataExchange* pDX) ;    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) ;
	virtual void OnOK() ;
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COleObjectDialog)
	afx_msg void OnCurrentSize() ;
	afx_msg void OnOriginalSize() ;
	afx_msg void OnHelp() ;
	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam) ;
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
} ;
#endif // INTERACTIVE

#endif  // _CNTRITEM_H_
/////////////////////////////////////////////////////////////////////////////
