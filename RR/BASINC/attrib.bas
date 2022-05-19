Attribute VB_Name = "Module2"
' ATTRIB.BAS - VB Function declarations for ATTRIB.DLL
' Version 7.0  2/20/96

Option Explicit

Declare Function ValidateLicenseInfo Lib "rrattrib.dll" (ByVal nFlagExe As Integer) As Long
Declare Function ShowAboutBox Lib "rrattrib.dll" (ByVal nFlagExe As Integer, ByVal hWnd As Long) As Long
Declare Function ShowStartup Lib "rrattrib.dll" (ByVal nFlagExe As Integer) As Long
Declare Sub GetAttrInfo Lib "rrattrib.dll" (ByVal nFlagExe As Integer, ByVal szTitle As String, ByVal szHelpAbout As String, ByVal szHelpTopic As String)
Declare Function CloseStartup Lib "rrattrib.dll" () As Long

Public Const nDESIGNER As Integer = 1
Public Const nVIEWER  As Integer = 2
Public Const nSHORTCUT As Integer = 3
Public Const nRRDICTIONARY As Integer = 4
Public Const nSCHEDULER As Integer = 5
