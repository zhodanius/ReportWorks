// rsreport.h



// API functions for rsreport.dll

extern BOOL FAR PASCAL chooseDataSource(int hReport, LPSTR dataSource, int size);
extern BOOL FAR PASCAL choosePrinter(int hReport, LPSTR printer, int prSize,
	LPSTR port, int poSize);
extern int  FAR PASCAL chooseReport(LPSTR appName, LPSTR lib, LPSTR rep, int size);
extern BOOL FAR PASCAL chooseTable(int hReport, LPSTR lpszTable, int tSize,
	LPSTR lpszDataSource, int dsSize, LPSTR lpszDatabase, int dbSize);
extern BOOL FAR PASCAL endReport(int hReport);
extern BOOL FAR PASCAL endRuntimeInstance (void);
extern BOOL FAR PASCAL execRuntime (int hReport, BOOL bWait, int fsCmdShow,
	LPINT ecode, LPLONG pageCount, LPSTR emsg, int emsgSize);
extern BOOL FAR PASCAL getBeginPage (int hReport, LPLONG lplPage);
extern BOOL FAR PASCAL getCopies (int hReport, LPINT lpiCopies);
extern BOOL FAR PASCAL getDatabase (int hReport, LPSTR lpszDatabase, int size);
extern BOOL FAR PASCAL getDataSource (int hReport, LPSTR lpszDataSource, int size);
extern BOOL FAR PASCAL getDisplayErrors (int hReport, BOOL FAR * lpbDisperr);
extern BOOL FAR PASCAL getDisplayStatus (int hReport, BOOL FAR * bDispStatus);
extern BOOL FAR PASCAL getEndPage (int hReport, LPLONG lplPage);
extern BOOL FAR PASCAL getErrorInfo (LPSTR lpszMsg, int size, LPINT lpiCode);
extern BOOL FAR PASCAL getExportDest (int hReport, LPSTR lpszVal);
extern BOOL FAR PASCAL getFilter (int hReport, LPSTR lpszFilter, int size);
extern BOOL FAR PASCAL getFilterUsage (int hReport, LPSTR lpszVal);
extern BOOL FAR PASCAL getFirstFieldName (int hReport, LPSTR lpszFieldName, int size);
extern BOOL FAR PASCAL getFirstGroupField (int hReport, LPSTR lpszName, int size);
extern BOOL FAR PASCAL getFirstJoinInfo (int hReport, LPSTR lpszTable, int tSize,
	LPSTR lpszAlias, int aSize);
extern BOOL FAR PASCAL getFirstUserParam (int hReport, LPSTR lpszName, int nSize,
	LPSTR lpszValue, int vSize);
extern BOOL FAR PASCAL getFirstReplace (int hReport, LPSTR lpszReplace, int size);
extern BOOL FAR PASCAL getFirstSortField (int hReport, LPSTR lpszName, int size);
extern BOOL FAR PASCAL getLibrary (int hReport, LPSTR lpszName, int size);
extern BOOL FAR PASCAL getMasterTableName (int hReport, LPSTR lpszPath, int size);
extern BOOL FAR PASCAL getMemoName (int hReport, LPSTR lpszPath, int size);
extern int  FAR PASCAL getNewReportHandle (LPSTR lpszAppName);
extern BOOL FAR PASCAL getNextFieldName (int hReport, LPSTR lpszFieldName, int size);
extern BOOL FAR PASCAL getNextGroupField (int hReport, LPSTR lpszName, int size);
extern BOOL FAR PASCAL getNextJoinInfo (int hReport, LPSTR lpszTable, int tSize,
	LPSTR lpszAlias, int aSize);
extern BOOL FAR PASCAL getNextReplace (int hReport, LPSTR lpszReplace, int size);
extern BOOL FAR PASCAL getNextSortField (int hReport, LPSTR lpszName, int size);
extern BOOL FAR PASCAL getNextUserParam (int hReport, LPSTR lpszName, int nSize,
	LPSTR lpszValue, int vSize);
extern BOOL FAR PASCAL getOutputDest (int hReport, LPSTR lpszDest);
extern BOOL FAR PASCAL getOutputFile (int hReport, LPSTR lpszPath, int size);
extern BOOL FAR PASCAL getPreventEscape (int hReport, BOOL FAR * lpbNoEsc);
extern BOOL FAR PASCAL getPrinter (int hReport, LPSTR lpszPrinter, int size);
extern BOOL FAR PASCAL getPrinterPort (int hReport, LPSTR lpszPort, int size);
extern BOOL FAR PASCAL getReportPick (int hReport, LPSTR lpszPickFlag);
extern int  FAR PASCAL getRuntimeRecord (LPSTR lpszAppName, LPSTR lpszControlFile);
extern BOOL FAR PASCAL getStatusEveryPage (int hReport, BOOL FAR * lpbStatus);
extern BOOL FAR PASCAL getTestPattern (int hReport, BOOL FAR * lpbTest);
extern BOOL FAR PASCAL getWinTitle (int hReport, LPSTR lpszTitle, int size);
extern BOOL FAR PASCAL initRuntimeInstance (void);
extern BOOL FAR PASCAL resetErrorInfo (void);
extern BOOL FAR PASCAL setBeginPage (int hReport, LONG lPage);
extern BOOL FAR PASCAL setCopies (int hReport, int copies);
extern BOOL FAR PASCAL setDataDir (int hReport, LPSTR lpszDir);
extern BOOL FAR PASCAL setDatabase (int hReport, LPSTR lpszDatabase);
extern BOOL FAR PASCAL setDataSource (int hReport, LPSTR lpszDataSource);
extern BOOL FAR PASCAL setDisplayErrors (int hReport, BOOL bDisperr);
extern BOOL FAR PASCAL setDisplayStatus (int hReport, BOOL bDispStatus);
extern BOOL FAR PASCAL setEndPage (int hReport, LONG lPage);
extern BOOL FAR PASCAL setExportDest (int hReport, char cVal);
extern BOOL FAR PASCAL setFilter (int hReport, LPSTR lpszFilter);
extern BOOL FAR PASCAL setFilterUsage (int hReport, char cVal);
extern BOOL FAR PASCAL setGroupField (int hReport, LPSTR lpszName, int groupNum);
extern BOOL FAR PASCAL setImageDir (int hReport, LPSTR lpszDir);
extern BOOL FAR PASCAL setJoinInfo (int hReport, LPSTR lpszTable,
	LPSTR lpszAlias, int aliasNum);
extern BOOL FAR PASCAL setLibrary (int hReport, LPSTR lpszName);
extern BOOL FAR PASCAL setLibraryDir (int hReport, LPSTR lpszDir);
extern BOOL FAR PASCAL setMasterTableName (int hReport, LPSTR lpszPath);
extern BOOL FAR PASCAL setMemoName (int hReport, LPSTR lpszPath);
extern BOOL FAR PASCAL setOutputDest (int hReport, char cDest);
extern BOOL FAR PASCAL setOutputFile (int hReport, LPSTR lpszPath);
extern BOOL FAR PASCAL setPassword (int hReport, LPSTR lpszPassword);
extern BOOL FAR PASCAL setPreventEscape (int hReport, BOOL bNoEsc);
extern BOOL FAR PASCAL setPrinter (int hReport, LPSTR lpszPrinter);
extern BOOL FAR PASCAL setPrinterPort (int hReport, LPSTR lpszPort);
extern BOOL FAR PASCAL setReplace (int hReport, LPSTR lpszReplace);
extern BOOL FAR PASCAL setReportPick (int hReport, char cPickFlag);
extern BOOL FAR PASCAL setSortField (int hReport, LPSTR lpszName, int sortNum);
extern BOOL FAR PASCAL setStatusEveryPage (int hReport, BOOL bStatus);
extern BOOL FAR PASCAL setStatusFileName (int hRepstf, LPSTR lpszFilename);
extern BOOL FAR PASCAL setSuppressTitle (int hReport, BOOL bValue);
extern BOOL FAR PASCAL setTestPattern (int hReport, BOOL bTest);
extern BOOL FAR PASCAL setUserName (int hReport, LPSTR lpszName);
extern BOOL FAR PASCAL setUserParam (int hReport, LPSTR lpszName, LPSTR lpszValue);
extern BOOL FAR PASCAL setWhere (int hReport, LPSTR lpszWhere);
extern BOOL FAR PASCAL setWinBorderStyle (int hReport, int style);
extern BOOL FAR PASCAL setWinControlBox (int hReport, BOOL bControlBox);
extern BOOL FAR PASCAL setWinHeight (int hReport, int height);
extern BOOL FAR PASCAL setWinLeft (int hReport, int left);
extern BOOL FAR PASCAL setWinMaxButton (int hReport, BOOL bMax);
extern BOOL FAR PASCAL setWinMinButton (int hReport, BOOL bMin);
extern BOOL FAR PASCAL setWinParentHandle (int hReport, int hParent);
extern BOOL FAR PASCAL setWinTitle (int hReport, LPSTR lpszTitle);
extern BOOL FAR PASCAL setWinTop (int hReport, int top);
extern BOOL FAR PASCAL setWinWidth (int hReport, int width);
extern BOOL FAR PASCAL writeRuntimeRecord (int hReport, LPSTR lpszControlFile);

// for rswrun.exe
// getSpecificParam() takes a name and returns a value if a parameter with that name exists
// getFirstParam() & getNextParam() cycle through all parameters, including RIPARAMs
// message type codes for DLLsendMessage()
#define DM_HWND		1
#define DM_ECODE	2
#define DM_EMSG		3
#define DM_REPORTS	4
#define DM_PAGES	5
#define DM_RIRECNO	6
#define DM_DONE		7
#define DM_NVDONE	8
typedef	int (WINAPI* LPFNRDGETPARAM)(int,LPSTR,int,LPSTR,int,BOOL,WORD);
typedef	int (WINAPI* LPFNRDGETSPECIFICPARAM)(int,LPSTR,LPSTR,int,WORD);
typedef	int (WINAPI* LPFNRDDLLSENDMESSAGE)(int,int,LPSTR,WORD);


