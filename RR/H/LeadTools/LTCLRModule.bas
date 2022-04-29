Attribute VB_Name = "Module1"
'  +----------------------------------------------------+
'  |   LTCLR.H - color conversion module header file    |
'  |   Copyright (c) 1991-2001 LEAD Technologies, Inc.  |
'  |   All Rights Reserved.                             |
'  +----------------------------------------------------+

'   white points constants
Public Const CIELAB_D50 = 50
Public Const CIELAB_D55 = 55
Public Const CIELAB_D65 = 65
Public Const CIELAB_D75 = 75
Public Const CIELAB_D93 = 93
Public Const CIELAB_CUSTOM = 0
Public Const CIELAB_DEFAULT = CIELAB_D50

'nMethod values for CONVERSION_PARAMS
Public Const USE_BUILTIN = 1
Public Const USE_ICC = 2
Public Const USE_CUSTOM_ICC = 4
Public Const USE_ET = 8
Public Const USE_CUSTOM_ET = 16
Public Const USE_AUTO = 32
Public Const USE_ALL = 63

'nMask values for SET_CONVERSION_PARAMS
Public Const CHANGE_ACTIVE_METHOD = 1
Public Const CHANGE_CUSTOM_PROFILES = 2
Public Const CHANGE_WHITE_POINT = 4
Public Const CHANGE_ET = 8
Public Const CHANGE_CMYK = 16
Public Const CHANGE_YUV = 32
Public Const CHANGE_LAB = 64
Public Const CHANGE_ALL = 127

'nMask values for CMYK_PARAMS
Public Const CMYK_GCR = 1

'nDlg values for L_ClrDlg
Public Const DLG_CMYK = 1
Public Const DLG_LAB = 2

'nMask values for LAB_PARAMS
Public Const LAB_L_OFFSET = 1
Public Const LAB_L_RANGE = 2
Public Const LAB_a_OFFSET = 4
Public Const LAB_a_RANGE = 8
Public Const LAB_b_OFFSET = 16
Public Const LAB_b_RANGE = 32

'nMask values for YUV_PARAMS
Public Const YUV_UH = 1
Public Const YUV_UV = 2
Public Const YUV_VH = 4
Public Const YUV_VV = 8
Public Const YUV_OFFSETS = 16
Public Const YUV_ELEMENTS = 32
Public Const YUV_RANGE = 64

'nRange values for YUV_PARAMS
Public Const YUVRANGE_FULL = 0
Public Const YUVRANGE_16_240 = 1

Public Const PLANAR_YUV = 0
Public Const PLANAR_YVU = 1
Public Const PLANAR_UYV = 2
Public Const PLANAR_UVY = 3
Public Const PLANAR_VYU = 4
Public Const PLANAR_VUY = 5

'nGamma constants
Public Const GAMMA_STANDARD = 45

'user types

Type WHITEPOINT
   nWhitePoint As Long
   xWhite As Double
   yWhite As Double
End Type

Type LPCMYK_PARAMS
 nSize As Long
 nGcr_level As Long 'value between 0.0 and 1.0
 nMask As Long
End Type

Type LPYUV_PARAMS
 nSize As Long
 nMask As Long
 nUh  As Long 'horizontal subsampling period of U.
 nUv  As Long 'vertical subsampling period of U.
 nVh  As Long 'horizontal subsampling period of V.
 nVv  As Long 'vertical subsampling period of V.
 pOffsets As Long 'offsets of the byte ordering for the proposed YUV format.
 nMacroPixel As Long 'Macropixel size (number of pixels in the unit pixels qroup).
 nRange As Long 'the range of values in the input buffer; full
                'range or 16-240 (YUVRANGE_FULL and YUVRANGE_16_240).
 bPlanar As Long 'the buffer consists of planes; Y plane, V plane and U plane.
End Type

Type LPLAB_PARAMS
   nSize As Long
   nMask As Long
   L_offset As Long
   L_range As Long
   a_offset As Long
   a_range As Long
   b_offset As Long
   b_range As Long
End Type

Type CONVERSION_PARAMS
   nSize As Long
   nActiveMethod As Long
   pWpoint As Long 'pointer to LPWHITEPOINT
   
   sInputProfile(259) As Byte 'sInputProfile As String * 260 'sInputProfile(259) As Byte
   sOutputProfile(259) As Byte 'sOutputProfile As String * 260 'sOutputProfile(259) As Byte
   sDstInputTable(259) As Byte 'sDstInputTable As String * 260 'sDstInputTable(259) As Byte
   
   pCmykParams As Long 'pointer to CMYK_PARAMS
   pYuvParams As Long  'pointer to CMYK_PARAMS
   pLabParams As Long  'pointer to CMYK_PARAMS
   nMethod As Long
   nQuantization As Long '/* Reserved,  must be 8*/
End Type

'user functions:

Declare Function L_ClrInit Lib "ltclr13n.dll" (ClrHandle As Long, ByVal nSrcFormat As Long, ByVal nDstFormat As Long, ByRef pParams As CONVERSION_PARAMS) As Long
Declare Function L_ClrSetConversionParams Lib "ltclr13n.dll" (ClrHandle As Long, ByRef pParams As CONVERSION_PARAMS) As Long
Declare Function L_ClrConvertDirect Lib "ltclr13n.dll" (ByVal nSrcFormat As Long, ByVal nDstFormat As Long, ByRef pIn As Byte, ByRef pOut As Byte, ByVal sWidth As Long, ByVal sHeight As Long, ByVal nInAlign As Integer, ByVal nOutAlign As Integer) As Integer
Declare Function L_ClrConvertDirectToBitmap Lib "ltclr13n.dll" (ByVal nSrcFormat As Long, ByVal nDstFormat As Long, ByRef pIn As Byte, bitmap_handle As LEADBitmapHandle, ByVal sWidth As Long, ByVal sHeight As Long, ByVal nInAlign As Integer, ByVal nOutAlign As Integer) As Integer
Declare Function L_ClrConvert Lib "ltclr13n.dll" (ByVal ClrHandle As Long, ByRef pSrc As Byte, ByRef pDst As Byte, ByVal nWidth As Long, ByVal nHeight As Long, ByVal nInAlign As Long, ByVal nOutAlign As Long) As Long
Declare Function L_ClrConvertToBitmap Lib "ltclr13n.dll" (ByVal ClrHandle As Long, ByRef pIn As Byte, bitmap_handle As LEADBitmapHandle, ByVal sWidth As Long, ByVal sHeight As Long, ByVal nInAlign As Integer, ByVal nOutAlign As Integer) As Integer
Declare Function L_ClrFree Lib "ltclr13n.dll" (ByVal ClrHandle As Long) As Long
Declare Function L_ClrIsValid Lib "ltclr13n.dll" (ByVal ClrHandle As Long) As Long
Declare Function L_ClrDlg Lib "ltclr13n.dll" (ByVal nDlg As Long, ByVal hWnd As Long, ByRef ClrHandle As Long, ByRef pParams As CONVERSION_PARAMS) As Long

Public Const SUCCESS = 1

Public Const CCS_RGB = H00 'Color space is RGB
Public Const CCS_YUV = H01 'Color space is YUV
Public Const CCS_CMYK = H02 'Color space is CMYK
Public Const CCS_HSV = H03 'Color space is HSV
Public Const CCS_HLS = H04 'Color space is HLS
Public Const CCS_YIQ = H05 'Color space is YIQ
Public Const CCS_CMY = H06 'Color space is CMY
Public Const CCS_LAB = H07 'Color space is CIELAB
Public Const CCS_XYZ = H08 'Color space is XYZ
Public Const CCS_YCCK = H0B 'Color space is YCCK
Public Const CCS_BGR = H0C 'Color space is BGR

Public Const CCS_Y41P = H0D 'Color space is Y41P
Public Const CCS_UYVY = H0E 'Color space is UYVY
Public Const CCS_YUY2 = H09 'Color space is YUY2
Public Const CCS_YVU9 = H0A 'Color space is YVU9
Public Const CCS_YCC = H0F 'Color space is YCC
Public Const CCS_RGB16 = H10 'Color space is RGB
Public Const CCS_YUV16 = H20 'Color space is YUV
Public Const CCS_YIQ16 = H30 'Color space is YIQ
Public Const CCS_HSV16 = H40 'Color space is HSV
Public Const CCS_HLS16 = H50 'Color space is HLS
Public Const CCS_CMY16 = H60 'Color space is CMY
Public Const CCS_CMYK16 = H70 'Color space is CMYK
Public Const CCS_IHS = H80 'Color space is IHS


' LEAD BitmapHandle structure
Type LEADBitmapHandle
 Reserved1 As Long
 Reserved2 As Long
 
 Width As Long
 Height As Long
 BitsPerPixel As Long
 BytesPerLine As Long
 CurrentPos As Long
 CurrentRow As Long

 Flags As Long

 nColors As Long

 hPalette As Long
 
 ViewPerspective As Long
 Order As Long
 Size As Long
 pDitherData As Long
 DitheringMethod As Long
 pRgnInfo As Long             ' Internal use
 XResolution As Long
 YResolution As Long
 left As Long                 ' Left playback offset
 top As Long                  ' Top playback offset
 Delay As Long                ' Playback delay (ms)
 Background As Long           ' Playback background color (COLORREF)
 Transparency As Long         ' Playback transparent color (COLORREF)
 DisposalMethod As Long       ' Playback disposal method
 LowBit As Long               ' low bit set by L_WindowLevel
 HighBit As Long              ' high bit set by L_WindowLeve
 pLUT As Long                 ' LUT set by L_WindowLevel
 LUTLength As Long            ' no of entries pointed by LUT
 DataOffset As Long           ' Internal use
 MinVal As Long               ' min val for a grayscale bitmap
 MaxVal As Long               ' max val for a grayscale bitmap
 PaintLowBit As Long          ' low bit set by L_WindowLevelBitmap
 PaintHighBit As Long         ' high bit set by L_WindowLevelBitmap
 PaintGamma As Long
 PaintContrast As Long
 PaintIntensity As Long
 pPaintLUT As Long
 Reserved As Long
End Type

Public LBH As LEADBitmapHandle
