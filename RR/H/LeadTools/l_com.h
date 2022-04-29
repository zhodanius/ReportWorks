#ifndef _L_COM_H
#define _L_COM_H

// Lead definition constants
// enumeration constants
#include "ltkey.h"

#define UNLOCKSUPPORT(leadraster) \
{ \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_DOCUMENT, L_KEY_DOCUMENT); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_GIFLZW, L_KEY_GIFLZW); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_TIFLZW, L_KEY_TIFLZW); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_FPXEXTENSIONS, L_KEY_FPXEXTENSIONS); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_OCR, L_KEY_OCR); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_MULTIMEDIA, L_KEY_MULTIMEDIA); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_MEDICAL, L_KEY_MEDICAL); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_VECTOR, L_KEY_VECTOR); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_MEDICAL_NET, L_KEY_MEDICAL_NET); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_BARCODES_1D       , L_KEY_BARCODES_1D       ); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_BARCODES_2D_READ  , L_KEY_BARCODES_2D_READ  ); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_BARCODES_2D_WRITE , L_KEY_BARCODES_2D_WRITE ); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_BARCODES_PDF_READ , L_KEY_BARCODES_PDF_READ ); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_BARCODES_PDF_WRITE, L_KEY_BARCODES_PDF_WRITE); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_INTERNET, L_KEY_INTERNET); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_VECTOR, L_KEY_VECTOR); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_VECTOR_DWG, L_KEY_VECTOR_DWG); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_VECTOR_DXF, L_KEY_VECTOR_DXF); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_VECTOR_MISC, L_KEY_VECTOR_MISC); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_VECTOR_ALL, L_KEY_VECTOR_ALL); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_MRC, L_KEY_MRC); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_PDF, L_KEY_PDF); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_VECTOR_VIEW, L_KEY_VECTOR_VIEW); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_DIGITALPAINT, L_KEY_DIGITALPAINT); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_J2K, L_KEY_J2K); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_CMW, L_KEY_CMW); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_DICOM,   L_KEY_DICOM); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_EXTGRAY, L_KEY_EXTGRAY); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_BITONAL, L_KEY_BITONAL); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_MEDICAL_SECURITY, L_KEY_MEDICAL_SECURITY); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_PDF_SAVE, L_KEY_PDF_SAVE); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_OCR_PDF_OUTPUT, L_KEY_OCR_PDF_OUTPUT); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_BARCODES_DATAMATRIX_READ  , L_KEY_BARCODES_DATAMATRIX_READ  ); \
   (leadraster).UnlockSupport((RasterSupportLockConstants)L_SUPPORT_BARCODES_DATAMATRIX_WRITE , L_KEY_BARCODES_DATAMATRIX_WRITE ); \
}

#endif _L_COM_H