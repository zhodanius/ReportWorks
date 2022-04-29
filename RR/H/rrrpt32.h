// rrrpt32.h

	#include "windows.h"	// for BOOL, etc.

#if 1
  #define RUNDLL_API WINAPI PASCAL
#else
 #if !defined(RUNDLL_API)	
  #if defined(RREPORT)
  #define RUNDLL_API __declspec(dllexport) PASCAL
  #else
  #define RUNDLL_API __declspec(dllimport) PASCAL
  #endif
 #endif
#endif

#ifdef __cplusplus
extern "C"
{
#endif

// C-language API functions for rrrpt32.dll

BOOL RUNDLL_API  choosePrinter(int hReport, LPSTR printer, int prSize,
	LPSTR port, int poSize);
int RUNDLL_API chooseReport(LPSTR appName, LPSTR lib, int lSize, LPSTR rep, int rSize);
BOOL RUNDLL_API chooseTable(int hReport, LPSTR lpszTable, int tSize);
BOOL RUNDLL_API endReport(int hReport);
BOOL RUNDLL_API endRuntimeInstance (void);
BOOL RUNDLL_API execRuntime (int hReport, BOOL bWait, int fsCmdShow,
	LPINT ecode, LPLONG pageCount, LPSTR emsg, int emsgSize);
BOOL RUNDLL_API getAPIVersion (LPLONG lplAPIVersion);
BOOL RUNDLL_API getBeginPage (int hReport, LPLONG lplPage);
BOOL RUNDLL_API getCopies (int hReport, LPINT lpiCopies);
BOOL RUNDLL_API getDBContainer (int hReport, LPSTR lpszPath, int size);
BOOL RUNDLL_API getDisplayErrors (int hReport, BOOL * lpbDisperr);
BOOL RUNDLL_API getDisplayStatus (int hReport, BOOL * bDispStatus);
BOOL RUNDLL_API getEndPage (int hReport, LPLONG lplPage);
BOOL RUNDLL_API getErrorInfo (int hReport, LPSTR lpszMsg, int size, LPINT lpiCode);
BOOL RUNDLL_API getExportDest (int hReport, LPSTR lpszVal);
BOOL RUNDLL_API getFilter (int hReport, LPSTR lpszFilter, int size);
BOOL RUNDLL_API getFilterUsage (int hReport, LPSTR lpszVal);
BOOL RUNDLL_API getFirstFieldName (int hReport, LPSTR lpszFieldName, int size);
BOOL RUNDLL_API getFirstFilteredFieldName (int hReport, LPSTR fieldName, int size, int filter);
BOOL RUNDLL_API getFirstGroupField (int hReport, LPSTR lpszName, int size);
BOOL RUNDLL_API getFirstRelationInfo (int hReport, LPSTR lpszFilePath, int fSize,
	LPSTR lpszIndexPath, int iSize,	LPSTR lpszTag, int tSize, LPSTR lpszAlias, int aSize);
BOOL RUNDLL_API getFirstSortField (int hReport, LPSTR lpszName, int size);
BOOL RUNDLL_API getFirstUserParam (int hReport, LPSTR lpszName, int nSize,
	LPSTR lpszValue, int vSize);
BOOL RUNDLL_API getHighScope (int hReport, LPSTR lpszScope, int size);
BOOL RUNDLL_API getLibrary (int hReport, LPSTR lpszName, int size);
BOOL RUNDLL_API getLowScope (int hReport, LPSTR lpszScope, int size);
BOOL RUNDLL_API getMasterIndexInfo (int hReport, LPSTR lpszPath, int pSize,
	LPSTR lpszType, LPSTR lpszTag, int tagSize);
BOOL RUNDLL_API getMasterTableName (int hReport, LPSTR lpszPath, int size);
BOOL RUNDLL_API getMemoName (int hReport, LPSTR lpszPath, int size);
int  RUNDLL_API getNewReportHandle (LPSTR lpszAppName);
BOOL RUNDLL_API getNextFieldName (int hReport, LPSTR lpszFieldName, int size);
BOOL RUNDLL_API getNextFilteredFieldName (int hRepstf, LPSTR fieldName, int size, int filter);
BOOL RUNDLL_API getNextGroupField (int hReport, LPSTR lpszName, int size);
BOOL RUNDLL_API getNextRelationInfo (int hReport, LPSTR lpszFilePath, int fSize,
	LPSTR lpszIndexPath, int iSize,	LPSTR lpszTag, int tSize, LPSTR lpszAlias, int aSize);
BOOL RUNDLL_API getNextSortField (int hReport, LPSTR lpszName, int size);
BOOL RUNDLL_API getNextUserParam (int hReport, LPSTR lpszName, int nSize,
	LPSTR lpszValue, int vSize);
BOOL RUNDLL_API getOutputDest (int hReport, LPSTR lpszDest, int dSize);
BOOL RUNDLL_API getOutputFile (int hReport, LPSTR lpszPath, int size);
BOOL RUNDLL_API getPreventEscape (int hReport, BOOL * lpbNoEsc);
BOOL RUNDLL_API getPrinter (int hReport, LPSTR lpszPrinter, int size);
BOOL RUNDLL_API getPageSize (int hReport, LPSTR lpszPageSize, int size);
BOOL RUNDLL_API getPrinterPort (int hReport, LPSTR lpszPort, int size);
BOOL RUNDLL_API getReportPick (int hReport, LPSTR lpszPickFlag);
int  RUNDLL_API getRuntimeRecord (LPSTR lpszAppName, LPSTR lpszControlFile);
BOOL RUNDLL_API getScopeUsage (int hReport, LPSTR lpszScopeFlag);
BOOL RUNDLL_API getStatusEveryPage (int hReport, BOOL * lpbStatus);
BOOL RUNDLL_API getTestPattern (int hReport, BOOL * lpbTest);
BOOL RUNDLL_API getWinTitle (int hReport, LPSTR lpszTitle, int size);
BOOL RUNDLL_API initRuntimeInstance (void);
BOOL RUNDLL_API resetErrorInfo (int hReport);
BOOL RUNDLL_API setBeginPage (int hReport, LONG lPage);
BOOL RUNDLL_API setCopies (int hReport, int copies);
BOOL RUNDLL_API setDataDir (int hReport, LPCSTR lpszDir);
BOOL RUNDLL_API setDBContainer (int hReport, LPCSTR lpszPath);
BOOL RUNDLL_API setDisplayErrors (int hReport, BOOL bDisperr);
BOOL RUNDLL_API setDisplayStatus (int hReport, BOOL bDispStatus);
BOOL RUNDLL_API setEndPage (int hReport, LONG lPage);
BOOL RUNDLL_API setExportDest (int hReport, char cVal);
BOOL RUNDLL_API setFilter (int hReport, LPCSTR lpszFilter);
BOOL RUNDLL_API setFilterUsage (int hReport, char cVal);
BOOL RUNDLL_API setGroupField (int hReport, LPCSTR lpszName, int groupNum);
BOOL RUNDLL_API setHighScope (int hReport, LPCSTR lpszScope);
BOOL RUNDLL_API setImageDir (int hReport, LPCSTR lpszDir);
BOOL RUNDLL_API setIndexExtension (int hRepstf, int ExtNumber);
BOOL RUNDLL_API setLibrary (int hReport, LPCSTR lpszName);
BOOL RUNDLL_API setLibraryDir (int hReport, LPCSTR lpszDir);
BOOL RUNDLL_API setLowScope (int hReport, LPCSTR lpszScope);
BOOL RUNDLL_API setMasterIndexInfo (int hReport, LPCSTR lpszPath,
	char cType, LPCSTR lpszTag);
BOOL RUNDLL_API setMasterTableName (int hReport, LPCSTR lpszPath);
BOOL RUNDLL_API setMemoName (int hReport, LPCSTR lpszPath);
BOOL RUNDLL_API setOutputDest (int hReport, LPCSTR lpszDest);
BOOL RUNDLL_API setOutputFile (int hReport, LPCSTR lpszPath);
BOOL RUNDLL_API setPreventEscape (int hReport, BOOL bNoEsc);
BOOL RUNDLL_API setPrinter (int hReport, LPCSTR lpszPrinter);
BOOL RUNDLL_API setPageSize (int hReport, LPCSTR lpszPageSize);
BOOL RUNDLL_API setPrinterPort (int hReport, LPCSTR lpszPort);
BOOL RUNDLL_API setRelationInfo (int hReport, LPCSTR lpszFilePath,
	LPCSTR lpszIndexPath, LPCSTR lpszTag, LPCSTR lpszAlias, int aliasNum);
BOOL RUNDLL_API setReportPick (int hReport, char cPickFlag);
BOOL RUNDLL_API setScopeUsage (int hReport, char cScopeFlag);
BOOL RUNDLL_API setSortField (int hReport, LPCSTR lpszName, int sortNum);
BOOL RUNDLL_API setStatusEveryPage (int hReport, BOOL bStatus);
BOOL RUNDLL_API setStatusFileName (int hRepstf, LPCSTR lpszFilename);
BOOL RUNDLL_API setSuppressTitle (int hReport, BOOL bValue);
BOOL RUNDLL_API setTestPattern (int hReport, BOOL bTest);
BOOL RUNDLL_API setUserParam (int hReport, LPCSTR lpszName, LPCSTR lpszValue);
BOOL RUNDLL_API setWinBorderStyle (int hReport, int style);
BOOL RUNDLL_API setWinControlBox (int hReport, BOOL bControlBox);
BOOL RUNDLL_API setWinHeight (int hReport, int height);
BOOL RUNDLL_API setWinLeft (int hReport, int left);
BOOL RUNDLL_API setWinMaxButton (int hReport, BOOL bMax);
BOOL RUNDLL_API setWinMinButton (int hReport, BOOL bMin);
BOOL RUNDLL_API setWinParentHandle (int hReport, int hParent);
BOOL RUNDLL_API setWinTitle (int hReport, LPCSTR lpszTitle);
BOOL RUNDLL_API setWinTop (int hReport, int top);
BOOL RUNDLL_API setWinWidth (int hReport, int width);
BOOL RUNDLL_API setWriteAllow (int hRepstf, BOOL bAllow);
BOOL RUNDLL_API setXbaseEditor (int hRepstf, BOOL bXbase);
BOOL RUNDLL_API writeRuntimeRecord (int hReport, LPSTR lpszControlFile);

int RUNDLL_API tabChooseTable (LPSTR table, int tSize);
BOOL RUNDLL_API tabFreeHandle (int hTable);
BOOL RUNDLL_API tabGetErrorInfo (int hReport, LPSTR lpszMsg, int size, LPINT lpiCode);
BOOL RUNDLL_API tabGetFirstFieldInfo (int hTable, LPSTR lpszFieldName, int iSize,
	LPSTR lpszType, LPINT lpiLgt, LPINT lpiDecPl);
BOOL RUNDLL_API tabGetNextFieldInfo (int hTable, LPSTR lpszFieldName, int iSize,
	LPSTR lpszType, LPINT lpiLgt, LPINT lpiDecPl);
BOOL RUNDLL_API tabResetErrorInfo (int hReport);
BOOL RUNDLL_API setRunningAsNonInteractiveUser(int hReport); // U2I:

#ifdef __cplusplus
}		//  "C"
#endif

// filter IDs for getFirstFilteredFieldName() / getNextFilteredFieldName()
#define FILTER_ID_SORT 1		// return only valid sort fields
#define FILTER_ID_GROUP 2		// return only valid group fields

