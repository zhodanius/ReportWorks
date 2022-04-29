#ifndef _COLINFO_
#define _COLINFO_

#include "ApiDef.h"
#include "ColOpts.h"

class CColumnInfo : public CObject
{               
	DECLARE_SERIAL(CColumnInfo)

// Constructors
public:
	EXPORT_API CColumnInfo();

	CString m_strVersion;				// Version String

// Attributes

	COLOPTS		 m_ColOpts;				// COLOPTS struct contains UserFriendlyName,
										// NullString, NullValue, and Date/Time formatting
										// information.
	
	CStringList	m_ValueList;			// ValueList

	BOOL		m_bShowColumn;

	// Implementation
protected:
	
	void DeleteValueList();

public:
	EXPORT_API virtual void Serialize(CArchive& ar);        // for native data

	EXPORT_API virtual void Init();

	inline EXPORT_API char* GetUserFriendlyName() { return m_ColOpts.UserName; }

	EXPORT_API BOOL UseNulls() { return m_ColOpts.UseNulls; }

	inline EXPORT_API char* GetNullString() { return m_ColOpts.NullString; }
	inline EXPORT_API long GetNullValue() { return m_ColOpts.NullValue; }

	inline EXPORT_API void SetColOpts( COLOPTS *ColOpts ) { memcpy( &m_ColOpts, ColOpts, sizeof(COLOPTS) ); }
	inline EXPORT_API void GetColOpts( COLOPTS *ColOpts ) { memcpy( ColOpts, &m_ColOpts, sizeof(COLOPTS) ); }

	inline EXPORT_API CStringList* GetValueList() { return &m_ValueList; }
	
	inline EXPORT_API void SetShowColumn( BOOL bShowColumn ) { m_bShowColumn = bShowColumn; }
	inline EXPORT_API BOOL GetShowColumn() { return m_bShowColumn; }

	EXPORT_API ~CColumnInfo();
};

#endif
