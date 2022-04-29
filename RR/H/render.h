///////////////////////////////////////////////////////////////////////////////
//
// Render.h
//
// Class Definition
//      
//      CRender
//      CReportWriterFormat
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _RENDER_H_
#define _RENDER_H_

// supplied by Kirkland's Joe Pruitt for DA RW integration

#define EXPORT_API

#if 0	// stuff we don't need from Kirkland's render.h:
//#include <apidef.h>	// had to comment out
//#include <windowsx.h>	// had to comment out
//#include <xfer.h>		// had to comment out
//#include <ddfmts.h>	// had to comment out
//#include <shlobj.h>	// had to comment out

//#include <database.h>
//#include <filexfer.h>

class CDbaNode;
class CResultSet;
class CWDDatabase;

#define SAFEREGISTERCF(x, fmt) if (x==NULL) x=(CLIPFORMAT)::RegisterClipboardFormat(fmt);

class CRender : public CObject
{
	public:
		CRender();
		~CRender();

	private:
		CXfer        m_xfer;					// xfer object
		CResultSet  *m_pResultSet;				// Result Set
		CWDDatabase *m_pDatabase;				// database pointer for ODBC source
		CString      m_strQuery;				// access statement for ODBC source
		CFile       *m_pFile;					// CFile pointer for rendering data
		LPFORMATETC  m_pFormatEtc;				// FORMATETC for rendering
		FileType     m_fileType;				// Pc File Type for destination
		CString      m_strFileType;				// Text string for Pc File Type

		BOOL         m_bTempFileStatic;			// Regen Pc FQ File Name
		CString      m_strTempFile;				// FQ Destination File Name
		BOOL         m_bDeleteFile;				// Delete File after xfer???
		BOOL         m_bUseHDropFmt;			// Use HDROP format in rendering
		UINT         m_uiHDropCount;			// Drop count for dragging over desktop
		BOOL         m_bOkToXfer;				// Is it OK to xfer??
		DWORD        m_dwLastProcessID;			// Last process ID dragged over.

		CString      m_strDescription;			// Description of ODBC source
		CString      m_strOwner;				// Owner of table for ODBC source
		CString      m_strTable;				// Table name for ODBC source

		// private clipboard format
		static CLIPFORMAT NEAR m_cfPrivate;
		static CLIPFORMAT NEAR m_cfQueryBuilder;
		static CLIPFORMAT NEAR m_cfTransferBuilder;
		static CLIPFORMAT NEAR m_cfConnectionInfo;

		// Data Exchange Notebook
		static CLIPFORMAT NEAR m_cfExchangeNotebook;

		// Win95 Extensions
		static CLIPFORMAT NEAR m_cfIDList;
		static CLIPFORMAT NEAR m_cfObjectPositions;
		static CLIPFORMAT NEAR m_cfFileGroupDescriptor;
		static CLIPFORMAT NEAR m_cfFileContents;
		static CLIPFORMAT NEAR m_cfFileName;
		static CLIPFORMAT NEAR m_cfFileNameMap;

		static CLIPFORMAT NEAR m_cfDbaFtxText;
		static CLIPFORMAT NEAR m_cfDbaFtxText_Tab;
		static CLIPFORMAT NEAR m_cfDbaFtxText_CSV;
		static CLIPFORMAT NEAR m_cfDbaFtxText_DOSRandom;
		static CLIPFORMAT NEAR m_cfDbaFtxDif;
		static CLIPFORMAT NEAR m_cfDbaFtxDif5;
		static CLIPFORMAT NEAR m_cfDbaFtxBiff3;
		static CLIPFORMAT NEAR m_cfDbaFtxBiff4;
		static CLIPFORMAT NEAR m_cfDbaFtxBiff5;
		static CLIPFORMAT NEAR m_cfDbaFtxBiff7;
		static CLIPFORMAT NEAR m_cfDbaFtxNotes;
		static CLIPFORMAT NEAR m_cfDbaFtxBinary;
		static CLIPFORMAT NEAR m_cfDbaFtxdBase;

		// Implementation
	public:
		       int          ValidateObject             (void);
		       void         Reset                      (void);
		       BOOL         RenderFileData             (void);

		// Data Rendering
	private:
	       // Private Formats
		       BOOL         RenderQueryBuilder         (void);
		       BOOL         RenderTransferBuilder      (void);
		       BOOL         RenderExchangeNotebook     (void);
		       BOOL         RenderDataExchangeNotebook (void);
		       BOOL         RenderConnectionInfo       (void);
	       // Shell Formats
		       BOOL         RenderShellFormats         (void);
		       BOOL         RenderIDList               (void);
		       BOOL         RenderObjectPositions      (void);
		       BOOL         RenderFileGroupDescriptor  (void);
		       BOOL         RenderFileContents         (void);
		       BOOL         RenderFileName             (void);
		       BOOL         RenderFileNameMap          (void);

		       BOOL         RenderXferFormats          (void);
		       BOOL         RenderXfer                 (void);
		       BOOL         RenderHDrop                (void);
		       BOOL         RenderCfText               (void);

		// Helpers
	private:
		inline BOOL         IsFormat           (CLIPFORMAT fmt) \
		                    { return (IsValidPointerX(GetFormatEtc()) ? GetFormatEtc()->cfFormat == (CLIPFORMAT)fmt : FALSE); }
		       long         RunTransfer        (void);
		       BOOL         IsExplorerProcess  (void);
		

		// Access Functions
	public:
			// Set Functions
		inline void         SetResultSet       (CResultSet *pRes) { m_pResultSet = pRes; }
		inline void         SetDatabase        (CWDDatabase *pDB) { m_pDatabase = pDB; }
		inline void         SetQuery           (CString str)      { m_strQuery = str; }
		inline void         SetCFile           (CFile *pFile)     { m_pFile = pFile; }
		inline void         SetFormatEtc       (LPFORMATETC pFme) { m_pFormatEtc = pFme; }
		inline void         SetFileType        (FileType type)    { m_fileType = type; }
		       void         SetFileType        (CString strType);
		inline void         SetTempFileStatic  (BOOL bStatic)     { m_bTempFileStatic = bStatic; }
		inline void         SetTempFileName    (CString str)      { m_strTempFile = str; }
		inline void         SetDeleteFile      (BOOL bDelete)     { m_bDeleteFile = bDelete; }
		inline void         SetUseHDropFormat  (BOOL bUse)        { m_bUseHDropFmt = bUse; }
		inline void         SetHDropCount      (int iCount)       { m_uiHDropCount = iCount; }
		inline void         SetOKToXfer        (BOOL bOK)         { m_bOkToXfer = bOK; }
		inline void         SetLastProcessID   (DWORD dwID)       { m_dwLastProcessID = dwID; }
		inline void         SetDescription     (CString str)      { m_strDescription = str; }
		inline void         SetOwnerName       (CString str)      { m_strOwner    = str; }
		inline void         SetTableName       (CString str)      { m_strTable    = str; }
			// GetFunctions
		inline CResultSet  *GetResultSet       (void)             { return m_pResultSet; }
		inline CWDDatabase *GetDatabase        (void)             { return m_pDatabase; }
		inline CString      GetQuery           (void)             { return m_strQuery; }
		inline CFile       *GetCFile           (void)             { return m_pFile; }
		inline LPFORMATETC  GetFormatEtc       (void)             { return m_pFormatEtc; }
		inline FileType     GetFileType        (void)             { return m_fileType; }
		inline BOOL         GetTempFileStatic  (void)             { return m_bTempFileStatic; }
		inline CString      GetTempFileName    (void)             { return m_strTempFile; }
		inline BOOL         GetDeleteFile      (void)             { return m_bDeleteFile; }
		inline BOOL         GetUseHDropFormat  (void)             { return m_bUseHDropFmt; }
		inline int          GetHDropCount      (void)             { return m_uiHDropCount; }
		inline BOOL         GetOKToXfer        (void)             { return m_bOkToXfer; }
		inline DWORD        GetLastProcessID   (void)             { return m_dwLastProcessID; }
		inline CString      GetDescription     (void)             { return m_strDescription; }
		inline CString      GetOwnerName       (void)             { return m_strOwner; }
		inline CString      GetTableName       (void)             { return m_strTable; }
		
};
#endif	// we need the rest

class CReportWriterFormat
{
	public:
		CReportWriterFormat();
		~CReportWriterFormat();

		CString      m_strQueryName;
		CString      m_strDSN;
		CString      m_strQuery;
		CString      m_strConnect;

		BOOL EXPORT_API Reset();
		BOOL EXPORT_API Validate();
		UINT EXPORT_API GetMemoryNeeded(void);

			// Write data to 

		BOOL EXPORT_API WriteToFile(CFile *pFile);
		BOOL EXPORT_API WriteToMemory(void *pMem);

		BOOL EXPORT_API ReadFromFile(CFile *pFile);
		BOOL EXPORT_API ReadFromMemory(void *pMem, UINT cbMemLen);

	private:
		BOOL CryptMemory(void *pMem, UINT cbMemLen);
};



#endif /* ifndef _RENDER_H_ */
