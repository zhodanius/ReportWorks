#if !defined(AFX_UndoPOPUP_H__15DE730F_73F0_4931_9D30_C1F3901CC68F__INCLUDED_)
#define AFX_UndoPOPUP_H__15DE730F_73F0_4931_9D30_C1F3901CC68F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>

/////////////////////////////////////////////////////////////////////////////
/// CUndoList - Listbox for displaying undo history items

typedef struct tagSYSCOLOR
{
	COLORREF crWINDOW;
	COLORREF crWINDOWTEXT;	
	COLORREF crHIGHLIGHT;
	COLORREF crBTNTEXT;
	COLORREF crBTNFACE;
	COLORREF crBTNHIGHLIGHT;	
	COLORREF crBTNSHADOW;
	COLORREF cr3DDARKSHADOW;
	COLORREF cr3DLIGHT;

	COLORREF crBlendedBtnFace;
	COLORREF crBlendedHIGHLIGHT;
} SYSCOLOR;

class CUndoPopup;
////////////////////////////////////////////////////////////////////////////////////////////////////
class CUndoList : public CWnd
{
// Construction/destruction
public:
	CUndoList();
	~CUndoList();
// Operations
public:
	void SetList (const CStringArray& arUndoNames);
	BOOL Create(const RECT& rc, CUndoPopup* pParentWnd);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUndoList)
	protected:
	//}}AFX_VIRTUAL

// Generated message map functions
protected:
	void EndSelection (bool bSelOK);
	void SelectAndNotifyParent (int last_sel);
	int HitTest(CPoint pt);
	void OnDraw (CDC* pDC);

	//{{AFX_MSG(CUndoList)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove (UINT nFlags, CPoint point);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd (CDC* pDC);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Attributes
protected:
	CStringArray m_arUndoNames;
	int m_nFirstVisibleItem;
	SCROLLINFO m_si;
public:
	int m_nItemHeight;
	int m_nLastSelectedItem;
	SYSCOLOR* pSysClr;
	CFont* m_pFont;
	CUndoPopup* m_pPopup;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// CUndoPopup window

class CUndoPopup : public CWnd
{
// Construction
public:
	CUndoPopup();
	virtual ~CUndoPopup();

// Operations
public:
	BOOL Create(const POINT& llc, const POINT& lrc, CWnd* pParentWnd, UINT uID, bool bUndo);	
	void SetActionNames (const CStringArray& arUndoNames);	
	void SetPtrToItself (CUndoPopup** ppMyself);
	
	static bool m_bDrawXPStyle;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUndoPopup)
	protected:
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	friend CUndoList;

protected:
	void EndSelection ();
	void UpdateNumActions();
	SIZE CalculateWindowSizes (CWnd* pParentWnd);
	void CreateFonts (CWnd* pWnd);
	void GetUpdatedSystemColors();
	COLORREF BlendColor(COLORREF crFrom, COLORREF crTo, int Percent);
	void OnDraw (CDC* pDC);

	// Generated message map functions
protected:
	//{{AFX_MSG(CUndoPopup)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Attributes
protected:
	bool m_bUndo;
	UINT m_ID;
	CStringArray m_arUndoNames;
	CSize m_szList;
	CSize m_szCaption;
	CRect m_rcListWindow;
	CFont m_fntText;
	CUndoList m_lstActions;
	CUndoPopup** m_ppMyself;

	/// Some system colors
	SYSCOLOR SysClr;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UndoPOPUP_H__15DE730F_73F0_4931_9D30_C1F3901CC68F__INCLUDED_)
