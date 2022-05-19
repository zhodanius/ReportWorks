Attribute VB_Name = "Module2"
' RRDECL32.BAS - VB Function declarations for RRRPT32.DLL.
' Version 8.0 05/27/97

Declare Function choosePrinter Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal printer As String, ByVal prSize As Long, ByVal port As String, ByVal poSize As Long) As Long
Declare Function chooseReport Lib "rrrpt32.dll" (ByVal appName As String, ByVal library As String, ByVal lsize As Long, ByVal rep As String, ByVal size As Long) As Long
Declare Function endReport Lib "rrrpt32.dll" (ByVal hReport As Long) As Long
Declare Function endRuntimeInstance Lib "rrrpt32.dll" () As Long
Declare Function execRuntime Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal bWait As Long, ByVal fsCmdShow As Long, lpCode As Long, lpPageCount As Long, ByVal emsg As String, ByVal emsgsize As Long) As Long
Declare Function getAPIVersion Lib "rrrpt32.dll" (lpVersion As Long) As Long
Declare Function getBeginPage Lib "rrrpt32.dll" (ByVal hReport As Long, lpPage As Long) As Long
Declare Function getCopies Lib "rrrpt32.dll" (ByVal hReport As Long, lpCopies As Long) As Long
Declare Function getDBContainer Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal dbContainerPath As String, ByVal size As Long) As Long
Declare Function getDisplayErrors Lib "rrrpt32.dll" (ByVal hReport As Long, lpDisperr As Long) As Long
Declare Function getDisplayStatus Lib "rrrpt32.dll" (ByVal hReport As Long, lpDispStatus As Long) As Long
Declare Function getEndPage Lib "rrrpt32.dll" (ByVal hReport As Long, lpPage As Long) As Long
Declare Function getErrorInfo Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal msg As String, ByVal size As Long, lpCode As Long) As Long
Declare Function getExportDest Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal charval As String) As Long
Declare Function getFilter Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal charval As String, ByVal size As Long) As Long
Declare Function getFilterUsage Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal charval As String) As Long
Declare Function getFirstFieldName Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal fieldName As String, ByVal size As Long) As Long
Declare Function getFirstFilteredFieldName Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal fieldName As String, ByVal size As Long, ByVal filter As Long) As Long
Declare Function getFirstGroupField Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal groupFieldName As String, ByVal mSize As Long) As Long
Declare Function getFirstRelationInfo Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal relFilePath As String, ByVal relFilePathSize As Long, ByVal relIndexfilePath As String, ByVal relIndexfilePathSizer As Long, ByVal relIndexTag As String, ByVal relIndexTagSize As Long, ByVal relAlias As String, ByVal relAliasSize As Long) As Long
Declare Function getFirstSortField Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal sortFieldName As String, ByVal size As Long) As Long
Declare Function getFirstUserParam Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal parmname As String, ByVal nSize As Long, ByVal value As String, ByVal vSize As Long) As Long
Declare Function getHighScope Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal charval As String, ByVal size As Long) As Long
Declare Function getLibrary Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal libname As String, ByVal size As Long) As Long
Declare Function getLowScope Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal charval As String, ByVal size As Long) As Long
Declare Function getMasterIndexInfo Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal masterIndexPath As String, ByVal pathSize As Long, ByVal masterIndexType As String, ByVal masterIndexTag As String, ByVal tagSize As Long) As Long
Declare Function getMasterTableName Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal masterTablePath As String, ByVal size As Long) As Long
Declare Function getMemoName Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal memoTablePath As String, ByVal size As Long) As Long
Declare Function getNewReportHandle Lib "rrrpt32.dll" (ByVal appName As String) As Long
Declare Function getNextFieldName Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal fieldName As String, ByVal size As Long) As Long
Declare Function getNextFilteredFieldName Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal fieldName As String, ByVal size As Long, ByVal filter As Long) As Long
Declare Function getNextGroupField Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal groupFieldName As String, ByVal mSize As Long) As Long
Declare Function getNextRelationInfo Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal relFilePath As String, ByVal relFilePathSize As Long, ByVal relIndexfilePath As String, ByVal relIndexfilePathSize As Long, ByVal relIndexTag As String, ByVal relIndexTagSize As Long, ByVal relAlias As String, ByVal relAliasSize As Long) As Long
Declare Function getNextSortField Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal sortFieldName As String, ByVal size As Long) As Long
Declare Function getNextUserParam Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal parmname As String, ByVal nSize As Long, ByVal value As String, ByVal vSize As Long) As Long
Declare Function getOutputDest Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal charval As String) As Long
Declare Function getOutputFile Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal outputFilePath As String, ByVal eSize As Long) As Long
Declare Function getPreventEscape Lib "rrrpt32.dll" (ByVal hReport As Long, lpNoEsc As Long) As Long
Declare Function getPrinter Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal printer As String, ByVal pSize As Long) As Long
Declare Function getPrinterPort Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal port As String, ByVal pSize As Long) As Long
Declare Function getReportPick Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal charval As String) As Long
Declare Function getRuntimeRecord Lib "rrrpt32.dll" (ByVal appName As String, ByVal inFile As String) As Long
Declare Function getScopeUsage Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal charval As String) As Long
Declare Function getStatusEveryPage Lib "rrrpt32.dll" (ByVal hReport As Long, lpEveryPage As Long) As Long
Declare Function getTestPattern Lib "rrrpt32.dll" (ByVal hReport As Long, lpTest As Long) As Long
Declare Function getWinTitle Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal title As String, ByVal tSize As Long) As Long
Declare Function initRuntimeInstance Lib "rrrpt32.dll" () As Long
Declare Function resetErrorInfo Lib "rrrpt32.dll" (ByVal hReport As Long) As Long
Declare Function setBeginPage Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal Page As Long) As Long
Declare Function setCopies Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal Copies As Long) As Long
Declare Function setDataDir Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal directory As String) As Long
Declare Function setDBContainer Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal dbContainerPath As String) As Long
Declare Function setDisplayErrors Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal bDisperr As Long) As Long
Declare Function setDisplayStatus Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal bDispStatus As Long) As Long
Declare Function setEndPage Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal Page As Long) As Long
Declare Function setExportDest Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal charval As Long) As Long
Declare Function setFilter Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal charval As String) As Long
Declare Function setFilterUsage Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal charval As Long) As Long
Declare Function setGroupField Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal groupFieldName As String, ByVal groupNum As Long) As Long
Declare Function setHighScope Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal charval As String) As Long
Declare Function setImageDir Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal directory As String) As Long
Declare Function setIndexExtension Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal ExtNum As Long) As Long
Declare Function setLibrary Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal libname As String) As Long
Declare Function setLibraryDir Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal directory As String) As Long
Declare Function setLowScope Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal charval As String) As Long
Declare Function setMasterIndexInfo Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal masterIndexPath As String, ByVal masterIndexType As Long, ByVal masterIndexTag As String) As Long
Declare Function setMasterTableName Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal masterTablePath As String) As Long
Declare Function setMemoName Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal memoTablePath As String) As Long
Declare Function setOutputDest Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal charval As String) As Long
Declare Function setOutputFile Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal outputFilePath As String) As Long
Declare Function setPreventEscape Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal bNoEsc As Long) As Long
Declare Function setPrinter Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal printer As String) As Long
Declare Function setPrinterPort Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal port As String) As Long
Declare Function setRelationInfo Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal relFilePath As String, ByVal relIndexfilePath As String, ByVal relIndexTag As String, ByVal relAlias As String, ByVal aliasNum As Long) As Long
Declare Function setReportPick Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal charval As Long) As Long
Declare Function setScopeUsage Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal charval As Long) As Long
Declare Function setSortField Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal sortFieldName As String, ByVal sortNum As Long) As Long
Declare Function setStatusEveryPage Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal bEveryPage As Long) As Long
Declare Function setStatusFileName Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal FileName As String) As Long
Declare Function setSuppressTitle Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal bValue As Long) As Long
Declare Function setTestPattern Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal bTest As Long) As Long
Declare Function setUserParam Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal parmname As String, ByVal charval As String) As Long
Declare Function setWinBorderStyle Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal eStyle As Long) As Long
Declare Function setWinControlBox Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal bControlBox As Long) As Long
Declare Function setWinHeight Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal iHeight As Long) As Long
Declare Function setWinLeft Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal iLeft As Long) As Long
Declare Function setWinMaxButton Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal bMax As Long) As Long
Declare Function setWinMinButton Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal bMin As Long) As Long
Declare Function setWinParentHandle Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal hParent As Long) As Long
Declare Function setWinTitle Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal title As String) As Long
Declare Function setWinTop Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal iTop As Long) As Long
Declare Function setWinWidth Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal iWidth As Long) As Long
Declare Function setWriteAllow Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal bWrite As Long) As Long
Declare Function setXbaseEditor Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal bXbase As Long) As Long
Declare Function writeRuntimeRecord Lib "rrrpt32.dll" (ByVal hReport As Long, ByVal recordFile As String) As Long
