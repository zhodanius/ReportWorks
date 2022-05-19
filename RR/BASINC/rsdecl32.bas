Attribute VB_Name = "Module1"
' RSDECL32.BAS - VB Function declarations for RSRPT32.DLL
' Version 7.0  2/20/96

Declare Function chooseDataSource Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal libname As String, ByVal size As Long) As Long
Declare Function choosePrinter Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal printer As String, ByVal prSize As Long, ByVal port As String, ByVal poSize As Long) As Long
Declare Function chooseReport Lib "rsrpt32.dll" (ByVal appName As String, ByVal library As String, ByVal lsize As Long, ByVal rep As String, ByVal size As Long, ByVal username As String, ByVal password As String, ByVal dsource As String, ByVal dsize As Long) As Long
Declare Function chooseTable Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal tname As String, ByVal tsize As Long, ByVal dsname As String, ByVal dsize As Long, ByVal dbname As String, ByVal dbsize As Long) As Long
Declare Function endReport Lib "rsrpt32.dll" (ByVal hReport As Long) As Long
Declare Function endRuntimeInstance Lib "rsrpt32.dll" () As Long
Declare Function execRuntime Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal bWait As Long, ByVal fsCmdShow As Long, lpCode As Long, lpPageCount As Long, ByVal emsg As String, ByVal emsgsize As Long) As Long
Declare Function getAPIVersion Lib "rsrpt32.dll" (lpVersion As Long) As Long
Declare Function getBeginPage Lib "rsrpt32.dll" (ByVal hReport As Long, lpPage As Long) As Long
Declare Function getCopies Lib "rsrpt32.dll" (ByVal hReport As Long, lpCopies As Long) As Long
Declare Function getDatabase Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal dbname As String, ByVal dbsize As Long) As Long
Declare Function getDataSource Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal dsname As String, ByVal size As Long) As Long
Declare Function getDisplayErrors Lib "rsrpt32.dll" (ByVal hReport As Long, lpDisperr As Long) As Long
Declare Function getDisplayStatus Lib "rsrpt32.dll" (ByVal hReport As Long, lpDispStatus As Long) As Long
Declare Function getEndPage Lib "rsrpt32.dll" (ByVal hReport As Long, lpPage As Long) As Long
Declare Function getErrorInfo Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal msg As String, ByVal size As Long, lpCode As Long) As Long
Declare Function getExportDest Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal charval As String) As Long
Declare Function getFilter Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal charval As String, ByVal size As Long) As Long
Declare Function getFilterUsage Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal charval As String) As Long
Declare Function getFirstFieldName Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal fieldName As String, ByVal size As Long) As Long
Declare Function getFirstFilteredFieldName Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal fieldName As String, ByVal size As Long, ByVal filter As Long) As Long
Declare Function getFirstGroupField Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal groupFieldName As String, ByVal mSize As Long) As Long
Declare Function getFirstJoinInfo Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal table As String, ByVal tsize As Long, ByVal tAlias As String, ByVal AliasSize As Long) As Long
Declare Function getFirstReplace Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal replace As String, ByVal size As Long) As Long
Declare Function getFirstSortField Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal sortFieldName As String, ByVal size As Long) As Long
Declare Function getFirstUserParam Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal parmname As String, ByVal nSize As Long, ByVal value As String, ByVal vSize As Long) As Long
Declare Function getLibrary Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal libname As String, ByVal size As Long) As Long
Declare Function getMasterTableName Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal masterTablePath As String, ByVal size As Long) As Long
Declare Function getMemoName Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal memoTablePath As String, ByVal size As Long) As Long
Declare Function getNewReportHandle Lib "rsrpt32.dll" (ByVal appName As String) As Long
Declare Function getNextFieldName Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal fieldName As String, ByVal size As Long) As Long
Declare Function getNextFilteredFieldName Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal fieldName As String, ByVal size As Long, ByVal filter As Long) As Long
Declare Function getNextGroupField Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal groupFieldName As String, ByVal mSize As Long) As Long
Declare Function getNextJoinInfo Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal table As String, ByVal tsize As Long, ByVal tAlias As String, ByVal AliasSize As Long) As Long
Declare Function getNextReplace Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal replace As String, ByVal size As Long) As Long
Declare Function getNextSortField Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal sortFieldName As String, ByVal size As Long) As Long
Declare Function getNextUserParam Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal parmname As String, ByVal nSize As Long, ByVal value As String, ByVal vSize As Long) As Long
Declare Function getOutputDest Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal charval As String) As Long
Declare Function getOutputFile Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal outputFilePath As String, ByVal eSize As Long) As Long
Declare Function getPreventEscape Lib "rsrpt32.dll" (ByVal hReport As Long, lpNoEsc As Long) As Long
Declare Function getPrinter Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal printer As String, ByVal pSize As Long) As Long
Declare Function getPrinterPort Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal port As String, ByVal pSize As Long) As Long
Declare Function getReportPick Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal charval As String) As Long
Declare Function getRuntimeRecord Lib "rsrpt32.dll" (ByVal appName As String, ByVal inFile As String, ByVal username As String, ByVal password As String, ByVal dsource As String, ByVal dsize As Long) As Long
Declare Function getStatusEveryPage Lib "rsrpt32.dll" (ByVal hReport As Long, lpEveryPage As Long) As Long
Declare Function getTestPattern Lib "rsrpt32.dll" (ByVal hReport As Long, lpTest As Long) As Long
Declare Function getWinTitle Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal title As String, ByVal tsize As Long) As Long
Declare Function initRuntimeInstance Lib "rsrpt32.dll" () As Long
Declare Function resetErrorInfo Lib "rsrpt32.dll" () As Long
Declare Function setBeginPage Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal Page As Long) As Long
Declare Function setCopies Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal Copies As Long) As Long
Declare Function setDataDir Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal directory As String) As Long
Declare Function setDatabase Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal dbname As String) As Long
Declare Function setDataSource Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal dsname As String) As Long
Declare Function setDisplayErrors Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal bDisperr As Long) As Long
Declare Function setDisplayStatus Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal bDispStatus As Long) As Long
Declare Function setEndPage Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal Page As Long) As Long
Declare Function setExportDest Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal charval As Long) As Long
Declare Function setFilter Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal charval As String) As Long
Declare Function setFilterUsage Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal charval As Long) As Long
Declare Function setGroupField Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal groupFieldName As String, ByVal groupNum As Long) As Long
Declare Function setImageDir Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal directory As String) As Long
Declare Function setJoinInfo Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal table As String, ByVal tAlias As String, ByVal aliasNum As Long) As Long
Declare Function setLibrary Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal libname As String) As Long
Declare Function setLibraryDir Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal directory As String) As Long
Declare Function setMasterTableName Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal masterTablePath As String) As Long
Declare Function setMemoName Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal memoTablePath As String) As Long
Declare Function setOutputDest Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal ochar As String) As Long
Declare Function setOutputFile Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal outputFilePath As String) As Long
Declare Function setPassword Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal pw As String) As Long
Declare Function setPreventEscape Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal bNoEsc As Long) As Long
Declare Function setPrinter Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal printer As String) As Long
Declare Function setPrinterPort Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal port As String) As Long
Declare Function setReplace Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal replace As String) As Long
Declare Function setReportPick Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal charval As Long) As Long
Declare Function setSortField Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal sortFieldName As String, ByVal sortNum As Long) As Long
Declare Function setStatusEveryPage Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal bEveryPage As Long) As Long
Declare Function setStatusFileName Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal FileName As String) As Long
Declare Function setSuppressTitle Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal bValue As Long) As Long
Declare Function setTestPattern Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal bTest As Long) As Long
Declare Function setUserName Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal username As String) As Long
Declare Function setUserParam Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal parmname As String, ByVal charval As String) As Long
Declare Function setWhere Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal where As String) As Long
Declare Function setWinBorderStyle Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal eStyle As Long) As Long
Declare Function setWinControlBox Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal bControlBox As Long) As Long
Declare Function setWinHeight Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal iHeight As Long) As Long
Declare Function setWinLeft Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal iLeft As Long) As Long
Declare Function setWinMaxButton Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal bMax As Long) As Long
Declare Function setWinMinButton Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal bMin As Long) As Long
Declare Function setWinParentHandle Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal hParent As Long) As Long
Declare Function setWinTitle Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal title As String) As Long
Declare Function setWinTop Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal iTop As Long) As Long
Declare Function setWinWidth Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal iWidth As Long) As Long
Declare Function tabChooseTable Lib "rsrpt32.dll" (ByVal table As String, ByVal tsize As Long, ByVal qtable As String, ByVal qtsize As Long, ByVal user As String, ByVal pass As String, ByVal dsrc As String, ByVal dsize As Long) As Long
Declare Function tabGetErrorInfo Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal tmsg As String, ByVal size As Long, lpiecode As Long) As Long
Declare Function tabFreeHandle Lib "rsrpt32.dll" (ByVal hTable As Long) As Long
Declare Function tabGetFirstFieldInfo Lib "rsrpt32.dll" (ByVal hTabstf As Long, ByVal lpszFieldname As String, ByVal isize As Long, ByVal lpszType As String, lpiLength As Long, lpiDecPlaces As Long) As Long
Declare Function tabGetNextFieldInfo Lib "rsrpt32.dll" (ByVal hTabstf As Long, ByVal name As String, ByVal isize As Long, ByVal dtype As String, lpiLength As Long, lpiDecPlaces As Long) As Long
Declare Function tabResetErrorInfo Lib "rsrpt32.dll" (ByVal hReport As Long) As Long
Declare Function writeRuntimeRecord Lib "rsrpt32.dll" (ByVal hReport As Long, ByVal recordFile As String) As Long
