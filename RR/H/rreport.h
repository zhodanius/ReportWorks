// rreport.h

	#include "windows.h"	// for BOOL, etc.

#if !defined(RUNDLL_API)	
 #if defined(RREPORT)
 #define RUNDLL_API __declspec(dllexport)
 #else
 #define RUNDLL_API __declspec(dllimport)
 #endif
#endif
	
#ifdef __cplusplus
extern "C"
{
#endif

// C-language API functions for rreport.dll

RUNDLL_API BOOL  choosePrinter(int hReport, LPSTR printer, int prSize,
	LPSTR port, int poSize);
RUNDLL_API int   chooseReport(LPSTR appName, LPSTR lib, LPSTR rep, int size);
RUNDLL_API BOOL  chooseTable(int hReport, LPSTR lpszTable, int tSize);
RUNDLL_API BOOL  endReport(int hReport);
RUNDLL_API BOOL  endRuntimeInstance (void);
RUNDLL_API BOOL  execRuntime (int hReport, BOOL bWait, int fsCmdShow,
	LPINT ecode, LPLONG pageCount, LPSTR emsg, int emsgSize);
RUNDLL_API BOOL  getBeginPage (int hReport, LPLONG lplPage);
RUNDLL_API BOOL  getCopies (int hReport, LPINT lpiCopies);
RUNDLL_API BOOL  getDisplayErrors (int hReport, BOOL * lpbDisperr);
RUNDLL_API BOOL  getDisplayStatus (int hReport, BOOL * bDispStatus);
RUNDLL_API BOOL  getEndPage (int hReport, LPLONG lplPage);
RUNDLL_API BOOL  getErrorInfo (int hReport, LPSTR lpszMsg, int size, LPINT lpiCode);
RUNDLL_API BOOL  getExportDest (int hReport, LPSTR lpszVal);
RUNDLL_API BOOL  getFilter (int hReport, LPSTR lpszFilter, int size);
RUNDLL_API BOOL  getFilterUsage (int hReport, LPSTR lpszVal);
RUNDLL_API BOOL  getFirstFieldName (int hReport, LPSTR lpszFieldName, int size);
RUNDLL_API BOOL  getFirstFilteredFieldName (int hReport, LPSTR fieldName, int size, int filter);
RUNDLL_API BOOL  getFirstGroupField (int hReport, LPSTR lpszName, int size);
RUNDLL_API BOOL  getFirstRelationInfo (int hReport, LPSTR lpszFilePath, int fSize,
	LPSTR lpszIndexPath, int iSize,	LPSTR lpszTag, int tSize, LPSTR lpszAlias, int aSize);
RUNDLL_API BOOL  getFirstSortField (int hReport, LPSTR lpszName, int size);
RUNDLL_API BOOL  getFirstUserParam (int hReport, LPSTR lpszName, int nSize,
	LPSTR lpszValue, int vSize);
RUNDLL_API BOOL  getHighScope (int hReport, LPSTR lpszScope, int size);
RUNDLL_API BOOL  getLibrary (int hReport, LPSTR lpszName, int size);
RUNDLL_API BOOL  getLowScope (int hReport, LPSTR lpszScope, int size);
RUNDLL_API BOOL  getMasterIndexInfo (int hReport, LPSTR lpszPath, int pSize,
	LPSTR lpszType, LPSTR lpszTag, int tagSize);
RUNDLL_API BOOL  getMasterTableName (int hReport, LPSTR lpszPath, int size);
RUNDLL_API BOOL  getMemoName (int hReport, LPSTR lpszPath, int size);
RUNDLL_API int   getNewReportHandle (LPSTR lpszAppName);
RUNDLL_API BOOL  getNextFieldName (int hReport, LPSTR lpszFieldName, int size);
RUNDLL_API BOOL  getNextFilteredFieldName (int hRepstf, LPSTR fieldName, int size, int filter);
RUNDLL_API BOOL  getNextGroupField (int hReport, LPSTR lpszName, int size);
RUNDLL_API BOOL  getNextRelationInfo (int hReport, LPSTR lpszFilePath, int fSize,
	LPSTR lpszIndexPath, int iSize,	LPSTR lpszTag, int tSize, LPSTR lpszAlias, int aSize);
RUNDLL_API BOOL  getNextSortField (int hReport, LPSTR lpszName, int size);
RUNDLL_API BOOL  getNextUserParam (int hReport, LPSTR lpszName, int nSize,
	LPSTR lpszValue, int vSize);
RUNDLL_API BOOL  getOutputDest (int hReport, LPSTR lpszDest);
RUNDLL_API BOOL  getOutputFile (int hReport, LPSTR lpszPath, int size);
RUNDLL_API BOOL  getPreventEscape (int hReport, BOOL * lpbNoEsc);
RUNDLL_API BOOL  getPrinter (int hReport, LPSTR lpszPrinter, int size);
RUNDLL_API BOOL  getPrinterPort (int hReport, LPSTR lpszPort, int size);
RUNDLL_API BOOL  getReportPick (int hReport, LPSTR lpszPickFlag);
RUNDLL_API int   getRuntimeRecord (LPSTR lpszAppName, LPSTR lpszControlFile);
RUNDLL_API BOOL  getScopeUsage (int hReport, LPSTR lpszScopeFlag);
RUNDLL_API BOOL  getStatusEveryPage (int hReport, BOOL * lpbStatus);
RUNDLL_API BOOL  getTestPattern (int hReport, BOOL * lpbTest);
RUNDLL_API BOOL  getWinTitle (int hReport, LPSTR lpszTitle, int size);
RUNDLL_API BOOL  initRuntimeInstance (void);
RUNDLL_API BOOL  resetErrorInfo (int hReport);
RUNDLL_API BOOL  setBeginPage (int hReport, LONG lPage);
RUNDLL_API BOOL  setCopies (int hReport, int copies);
RUNDLL_API BOOL  setDataDir (int hReport, LPSTR lpszDir);
RUNDLL_API BOOL  setDisplayErrors (int hReport, BOOL bDisperr);
RUNDLL_API BOOL  setDisplayStatus (int hReport, BOOL bDispStatus);
RUNDLL_API BOOL  setEndPage (int hReport, LONG lPage);
RUNDLL_API BOOL  setExportDest (int hReport, char cVal);
RUNDLL_API BOOL  setFilter (int hReport, LPSTR lpszFilter);
RUNDLL_API BOOL  setFilterUsage (int hReport, char cVal);
RUNDLL_API BOOL  setGroupField (int hReport, LPSTR lpszName, int groupNum);
RUNDLL_API BOOL  setHighScope (int hReport, LPSTR lpszScope);
RUNDLL_API BOOL  setImageDir (int hReport, LPSTR lpszDir);
RUNDLL_API BOOL  setIndexExtension (int hRepstf, int ExtNumber);
RUNDLL_API BOOL  setLibrary (int hReport, LPSTR lpszName);
RUNDLL_API BOOL  setLibraryDir (int hReport, LPSTR lpszDir);
RUNDLL_API BOOL  setLowScope (int hReport, LPSTR lpszScope);
RUNDLL_API BOOL  setMasterIndexInfo (int hReport, LPSTR lpszPath,
	char cType, LPSTR lpszTag);
RUNDLL_API BOOL  setMasterTableName (int hReport, LPSTR lpszPath);
RUNDLL_API BOOL  setMemoName (int hReport, LPSTR lpszPath);
RUNDLL_API BOOL  setOutputDest (int hReport, char cDest);
RUNDLL_API BOOL  setOutputFile (int hReport, LPSTR lpszPath);
RUNDLL_API BOOL  setPreventEscape (int hReport, BOOL bNoEsc);
RUNDLL_API BOOL  setPrinter (int hReport, LPSTR lpszPrinter);
RUNDLL_API BOOL  setPrinterPort (int hReport, LPSTR lpszPort);
RUNDLL_API BOOL  setRelationInfo (int hReport, LPSTR lpszFilePath,
	LPSTR lpszIndexPath, LPSTR lpszTag, LPSTR lpszAlias, int aliasNum);
RUNDLL_API BOOL  setReportPick (int hReport, char cPickFlag);
RUNDLL_API BOOL  setScopeUsage (int hReport, char cScopeFlag);
RUNDLL_API BOOL  setSortField (int hReport, LPSTR lpszName, int sortNum);
RUNDLL_API BOOL  setStatusEveryPage (int hReport, BOOL bStatus);
RUNDLL_API BOOL  setStatusFileName (int hRepstf, LPSTR lpszFilename);
RUNDLL_API BOOL  setSuppressTitle (int hReport, BOOL bValue);
RUNDLL_API BOOL  setTestPattern (int hReport, BOOL bTest);
RUNDLL_API BOOL  setUserParam (int hReport, LPSTR lpszName, LPSTR lpszValue);
RUNDLL_API BOOL  setWinBorderStyle (int hReport, int style);
RUNDLL_API BOOL  setWinControlBox (int hReport, BOOL bControlBox);
RUNDLL_API BOOL  setWinHeight (int hReport, int height);
RUNDLL_API BOOL  setWinLeft (int hReport, int left);
RUNDLL_API BOOL  setWinMaxButton (int hReport, BOOL bMax);
RUNDLL_API BOOL  setWinMinButton (int hReport, BOOL bMin);
RUNDLL_API BOOL  setWinParentHandle (int hReport, int hParent);
RUNDLL_API BOOL  setWinTitle (int hReport, LPSTR lpszTitle);
RUNDLL_API BOOL  setWinTop (int hReport, int top);
RUNDLL_API BOOL  setWinWidth (int hReport, int width);
RUNDLL_API BOOL  setWriteAllow (int hRepstf, BOOL bAllow);
RUNDLL_API BOOL  setXbaseEditor (int hRepstf, BOOL bXbase);
RUNDLL_API BOOL  writeRuntimeRecord (int hReport, LPSTR lpszControlFile);

#ifdef __cplusplus
}		//  "C"
#endif

// filter IDs for getFirstFilteredFieldName() / getNextFilteredFieldName()
#define FILTER_ID_SORT 1		// return only valid sort fields
#define FILTER_ID_GROUP 2		// return only valid group fields

