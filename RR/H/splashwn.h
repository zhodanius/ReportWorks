// ..\..\h\splashwn.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSplashWnd window

class CSplashWnd : public CWnd
{
// Construction
public:
	CSplashWnd();

// Attributes
public:

// Operations
public:

// Implementation
public:
	virtual ~CSplashWnd();

protected:
	// Generated message map functions
	//{{AFX_MSG(CSplashWnd)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
