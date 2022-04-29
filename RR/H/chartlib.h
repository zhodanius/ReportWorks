/**************************************************************************
;
;	MODULE:	CHARTLIB.H
;
;	USE:		Callable Library function prototypes, typedefs and #defines
;
;	DATE:		04/16/97
;
;
;	DESCRIPTION:	Function prototypes for graphics server dlls
;
;
***************************************************************************/
// include once only
#if !defined(_CHARTLIB_H_)
#define _CHARTLIB_H_

#if defined(_CHARTLIB_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define SZ_CHARTLIB			"GSWDLL32.DLL"
#define SZ_AGCHARTLIB		"GSWAG32.DLL"


// typedefs for GS and AG functions we need for charting
typedef int (WINAPI* LPFNGSOPENSERVER)(char*, char*);
typedef int (WINAPI* LPFNGSCLOSESERVER)(void);
typedef double (WINAPI* LPFNGSGETAXEXT)(HWND);
typedef double (WINAPI* LPFNGSGETAYEXT)(HWND);
typedef int (WINAPI* LPFNGSOPENCHILDWIN)(HWND, double, double, double, double, double, int, int, char*);
typedef int (WINAPI* LPFNGSCLOSEWIN)(int);
//typedef HMETAFILE (WINAPI * LPFNGSGETMF)(INT);
typedef int (WINAPI* LPFNGSPICWRITE)(double, double, double, double, int, int, char*);
typedef int (WINAPI* LPFNGSPICREAD)(double, double, double, double, int, int, char*);
typedef int (WINAPI* LPFNGSDATAAMP)(int , int , double* );
typedef int (WINAPI* LPFNGSDATACLR)( int, int*);
typedef int (WINAPI* LPFNGSDATADIM)(int, int );
typedef int (WINAPI* LPFNGSDATADIST)(int, double*);
typedef int (WINAPI* LPFNGSDATAPATT)(int, int*);
typedef int (WINAPI* LPFNGSDATATRANS)(int, int*, double*,double*, int*, int*,int*, int*);
typedef int (WINAPI* LPFNGSBUBBLECHART)( double, double, int);
typedef int (WINAPI* LPFNGSHLC)( double, double, double, int, int);
typedef int (WINAPI* LPFNGSSCATTER)(double, double, int,int);
typedef int (WINAPI* LPFNGSSELECTPALETTE)( int );
typedef int (WINAPI* LPFNGSSETRFONTFACE)(int, char*);
typedef int (WINAPI* LPFNGSLOADRFONT)(int, int, int, int);
typedef int (WINAPI* LPFNGSSETBG)(int);
typedef int (WINAPI* LPFNGSCLEARVIEW)(int);

//AG functions use a different hInstance for LoadLibrary
typedef int (WINAPI* LPFNAGOPEN)(void);
typedef int (WINAPI* LPFNAGCLOSE)(void);
typedef int (WINAPI* LPFNAGAMP)(int, int, double*);
typedef int (WINAPI* LPFNAGSHOW)(int, int, int);
typedef int (WINAPI* LPFNAGTITLEBG)(int, int);
typedef int (WINAPI* LPFNAGTITLEG)(char*);
typedef int (WINAPI* LPFNAGTITLEX)(char*);
typedef int (WINAPI* LPFNAGTITLEY)(char*);
typedef int (WINAPI* LPFNAGTITLEYR)(char*);
typedef int (WINAPI* LPFNAGYAXISSTYLE)(int, int, int, double, double);
typedef int (WINAPI* LPFNAGLEGEND)(int, char*);
typedef int (WINAPI* LPFNAGDATALABELS)(int, int, char**);
typedef int (WINAPI* LPFNAGFONTSTYLE)(int, int, int, int);
typedef int (WINAPI* LPFNAGINFO)(int);
typedef int (WINAPI* LPFNAGLABELS)(int, char*);
typedef int (WINAPI* LPFNAGLABELY)(int, int, char*);
typedef int (WINAPI* LPFNAGLABELZ)(int, int, char*);
typedef int (WINAPI* LPFNAGLABELFORMAT)(int, char*);
typedef int (WINAPI* LPFNAGLEGENDSTYLE)(int, int, int, int, int);
typedef int (WINAPI* LPFNAGCLR)(int, int*);
typedef int (WINAPI* LPFNAGAUX)(int, int*);

// pointers to functions that various files need
GLOBAL LPFNGSOPENSERVER		lpfnGSOpenServer;
GLOBAL LPFNGSCLOSESERVER	lpfnGSCloseServer;
GLOBAL LPFNGSGETAXEXT		lpfnGSGetAXExt;
GLOBAL LPFNGSGETAYEXT		lpfnGSGetAYExt;
GLOBAL LPFNGSOPENCHILDWIN	lpfnGSOpenChildWin;
GLOBAL LPFNGSPICWRITE		lpfnGSPicWrite;
GLOBAL LPFNGSPICREAD		lpfnGSPicRead;
GLOBAL LPFNGSCLOSEWIN		lpfnGSCloseWin;
//GLOBAL LPFNGSGETMF			lpfnGSGetMF;
GLOBAL LPFNGSDATAAMP		lpfnGSDataAmp;
GLOBAL LPFNGSDATACLR		lpfnGSDataClr;
GLOBAL LPFNGSDATADIM		lpfnGSDataDim;
GLOBAL LPFNGSDATADIST		lpfnGSDataDist;
GLOBAL LPFNGSDATAPATT		lpfnGSDataPatt;
GLOBAL LPFNGSDATATRANS		lpfnGSDataTrans;

GLOBAL LPFNGSBUBBLECHART	lpfnGSBubbleChart;
GLOBAL LPFNGSHLC			lpfnGSHLC;
GLOBAL LPFNGSSCATTER		lpfnGSScatter;
GLOBAL LPFNGSSETRFONTFACE	lpfnGSSetRFontFace;
GLOBAL LPFNGSLOADRFONT		lpfnGSLoadRFont;
GLOBAL LPFNGSSELECTPALETTE	lpfnGSSelectPalette;
GLOBAL LPFNGSSETBG			lpfnGSSetBG;
GLOBAL LPFNGSCLEARVIEW		lpfnGSClearView;

//AG functions
GLOBAL LPFNAGOPEN			lpfnAGOpen;
GLOBAL LPFNAGCLOSE			lpfnAGClose;
GLOBAL LPFNAGAMP			lpfnAGAmp;
GLOBAL LPFNAGSHOW			lpfnAGShow;
GLOBAL LPFNAGTITLEBG		lpfnAGTitleBG;
GLOBAL LPFNAGTITLEG 		lpfnAGTitleG;
GLOBAL LPFNAGTITLEX 		lpfnAGTitleX;
GLOBAL LPFNAGTITLEY 		lpfnAGTitleY;
GLOBAL LPFNAGTITLEYR		lpfnAGTitleYR;
GLOBAL LPFNAGYAXISSTYLE		lpfnAGYAxisStyle;
GLOBAL LPFNAGLEGEND 		lpfnAGLegend;
GLOBAL LPFNAGDATALABELS		lpfnAGDataLabels;
GLOBAL LPFNAGFONTSTYLE		lpfnAGFontStyle;
GLOBAL LPFNAGINFO			lpfnAGInfo;
GLOBAL LPFNAGLABELS			lpfnAGLabels;
GLOBAL LPFNAGLABELY			lpfnAGLabelY;
GLOBAL LPFNAGLABELZ			lpfnAGLabelZ;
GLOBAL LPFNAGLABELFORMAT	lpfnAGLabelFormat;
GLOBAL LPFNAGLEGENDSTYLE	lpfnAGLegendStyle;
GLOBAL LPFNAGCLR			lpfnAGClr;
GLOBAL LPFNAGAUX			lpfnAGAux;

								 
#ifdef __cplusplus
}
#endif

#undef GLOBAL
#endif //_CHARTLIB_H_
