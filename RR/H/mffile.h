// ****************************************************************************
//
//      (C) Copyright 1992-1993 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $Workfile:   mffile.h  $
// ================
//
// Description:
// ============
//
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/H/MFFILE.H_V  $
//
//    Rev 1.20   Feb 07 2007 12:53:00   Photon Infotech (Amresh)
// CFileRR class written to make application compatible of reading more than 2 GB database file
//
//    Rev 1.19   Dec 05 2000 13:03:08   nhubacker
// Add members to mffile structure for user indexes
//
//    Rev 1.18   Aug 31 2000 13:49:56   nhubacker
// Support for DBFs relating to DBC
//
//    Rev 1.17   30 Nov 1998 10:37:06   wrr
// May merge multiple files
//
//    Rev 1.16.1.0   17 Apr 1998 11:17:12   spett
// Fix for overriding the database on a report created against a sql server db
//
//    Rev 1.16   06 Apr 1997 13:05:12   pjm
// Add mLongname member to MFFILE structure.
//
//    Rev 1.15   13 Feb 1997 14:24:20   pjm
// Change DBF blocksize in MFFILE structure to a UTWO (RRW bug 2898).
// Also memo.cpp and mfgetmch.cpp.
//
//    Rev 1.14   13 Feb 1997 14:20:02   jpb
// Fix rrw738
//
//    Rev 1.13   06 Jun 1996 14:21:54   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
//
//    Rev 1.12   21 Mar 1996 16:45:14   jpb
// VFP3 nulls
//
//    Rev 1.11   17 Nov 1995 19:44:56   smh
// Win32 file i/o.
//
//    Rev 1.10   17 Nov 1995 15:51:20   mjs
// Use CFile instead of handles.
//
//    Rev 1.9   21 Sep 1995 15:46:48   jpb
// FLDID
//
//    Rev 1.8   20 Sep 1995 15:01:38   jpb
// get rid of obsolete MFILE macro
//
//    Rev 1.7   19 Sep 1995 11:24:08   smh
// commented out MFILE, didn't find it referenced.
//
//    Rev 1.6   18 Aug 1995 14:51:52   mjs
// Moved strings to global.h
//
//    Rev 1.5   08 Aug 1995 17:30:50   dlm
// Fixed an apparent bug in early application of query.  In filesnap
//  structure sFlags2 was only a byte, but should have been a word
//  since it is used to save mFlags2.  This resulted in losing the
//  bits in the high-order byte of mFlags2 when restoring from a
//  snapshot structure.
//
//    Rev 1.4   31 Jul 1995 16:03:16   jpb
// More classification
//
//    Rev 1.3   31 Jul 1995 13:58:08   sjo
// Changed a string array to use NEAR, to avoid a compile problem I was seeing
// in CF.
//
//    Rev 1.2   07 Jul 1995 18:11:44   jpb
// First pass at moving all data and functions to CRrDoc class
//
//    Rev 1.1   25 Apr 1995 09:09:18   sbc
// 6.1.03 -> 7.0.01 merge
//
//    Rev 1.0   16 Mar 1995 16:12:58   sbc
// Initial revision.
//
//    Rev 1.17   07 Apr 1995 14:25:16   jpb
// add prototype
//
//    Rev 1.16   31 Mar 1995 10:18:20   jpb
// add NDXA
//
//    Rev 1.15   04 Nov 1994 19:19:56   sjo
// Removed an unused DS struct that I had put in while developing joinacrossdir
//
//    Rev 1.14   02 Nov 1994 20:47:48   sjo
// Making changes to support joining across directories and Data Sources for
// the 'Desktop' platforms.  Most changes are in DBI.C and iengmenu.c.  I also
// had to make changes to the 4 routines which called sql_tables and added
// support for a new INI file setting.  Also added a new MFFiles structure
// member.
//
//
//
//    Rev 1.13   31 Oct 1994 15:54:26   jpb
// add some prototypes for wizard stuff
//
//    Rev 1.12   10 Aug 1994 19:54:50   smh
// Moved oldfilno here from static definition in mfchgfil.c.  It's needed
// in mfeord.c and explt.c for pre-def calcs in limbo change.
//
//    Rev 1.11   26 Jul 1994 13:39:10   smh
// Updated prototype for fileinit() for Templates support.
//
//    Rev 1.10   08 Jun 1994 12:36:56   erp
//  changed FAR to far, so it will build for 32-bits
//
//    Rev 1.9   05 Apr 1994 12:32:50   dlm
// Moved some #defines needed for data dictionary code out of !RSW conditionals.
// Added "alias" argument to lmfopen() extern.
//
//    Rev 1.8   24 Mar 1994 10:03:30   dlm
// Moved extern for mfnewfil() from mffile.h to _mf.h.
//
//    Rev 1.7   21 Mar 1994 11:54:54   dlm
// Merge of Abra branch:
//  Moved memo file extension strings here from _mffile.h.
//  Added new arguments to lmfopen() and mfnewfil().
//  Added extern for newext() - either was in _mffile.h or was static.
//
//    Rev 1.6   18 Feb 1994 15:26:46   sjo
// I am merging the RRWINNSX branch back onto the RRWIN tree. This branch was
// setup to allow me to port my RR 5.1 NSX, SMT and DBV changes to RRW and
// RSW.
//
//    Rev 1.5   14 Feb 1994 13:43:36   sbc
// Get rid of "new" in function args
//
//    Rev 1.0   14 Feb 1994 13:42:46   sbc
// Initial revision.
//
//    Rev 1.4   07 Feb 1994 12:07:46   say
// Add flag for RSW 2.0 Btrieve reports
//
//    Rev 1.3   21 Jan 1994 17:06:24   nwh
// Added MFQEVAL
//
//    Rev 1.2.1.0   21 Jan 1994 16:36:56   sjo
// I am merging in RR 5.1 changes into the windows products.  I added defines
// for the new memo types.
//
//    Rev 1.2   19 Nov 1993 17:44:14   sbc
// Add extern C for C++
//
//    Rev 1.1   29 Oct 1993 16:33:54   jpb
// Clean up sources to remove compiler warnings
//
//    Rev 1.0.1.0   11 Jan 1994 10:47:28   dlm
// Moved .DBT and .FPT strings here from _mffile.h.
//
//    Rev 1.0   14 Oct 1993 10:12:16   erp
// In/Sitial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _MFFILE_H_

//
// Make a definition for this module.
//
#define _MFFILE_H_

#include "mffield.h"

#if defined (_MFGETFTB_C_)
 #define GLOBAL
#else
 #define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
#define FLD(n) (*(LPMFFIELD *)(mfiflds[n]-sizeof(LPMFFIELD)))


#ifdef RSW
#define JOIN 1    // no lookup/scan distinction for SQL

/* TNLEN must be in synch with the various engine interfaces */
#define TNLEN 75  /* max len table name (excl. NULL) (was 30, made 75 for PACE ) */
#define CRLEN 30  /* max len creator name (excl. NULL) */
/* NOTE: for PACE, the table name is qualified by database name
   and schema name.  This qualified name can be 75 bytes long, so we
   will define DBFNAMELEN as 76 for use below.
   Note that mDbfName at 76 bytes is still larger than its old size
   of CRLEN+1+TNLEN+1, which was 62 (when TNLEN was 30) */

#define DBFNAMELEN 99

#else
#define NEWRECPOS 1        /* to save newrec stat with mfgetpos data.
                        see mfrdrec mfrdnext mfgetpos  */
#endif

// masks for mLinkFlags member
//#ifdef RSW
#define MFAPPROX2 0x02     // if set, link is approximate lo
//#else
#define MFLOOKUP 0x80      // lookup type (see type codes below)
#define MFGTERM  0x08      // set=> terminate on group scan failure
#define MFRECNO  0x02      // if set, link is on recno
//#endif
#define MFLOCATE 0x10      // file related via locate relation
#define MFFAIL 0x60        // failure action (see action codes below)
#define MFAPPROX 0x04      // if set, link is approximate (hi)
#define MFNOLINK 0x01      // if set, link being edited

#ifndef RSW
/* lookup type codes */
#define MFSCAN 0x80        // scan (one-to-many)
#define MFSNGL 0x00        // single lookup (one-to-one)
#endif

// failure action codes
#define MFEMPTY   0x20     // empty related file fields
#define MFSKIP 0x40     // skip composite record
#ifdef RSW
#define MFEMPTY2 0x60      // empty controlling file
#else
#define MFABORT   0x60     // abort report
#endif

// runtime flags (mFlags)
#define MFEDIT   0x0002 // link is being edited
#define MFTEMP   0x0800 // available temporary flag bit

#ifndef RSW
#define MFNOPREV  0x0001   // don't copy to prev buffers
#define MFNOREAD  0x0004   // don't read for mCurRec, data already in
#define MFDELREC  0x0008   // current record is deleted
#define MFNEWREC  0x0010   // new record at this scan level
#define MFMTLINK  0x0020   // to propagate "empty on failure" action
#define MFLKFAIL  0x0040   // signals last lookup failed
#define MFCLIPPER 0x0080   // signals file's index is Clipper
#define MFNEED   0x0100 // a needed file
#define MFFOX    0x0200 // signals file's index is from foxbase
#define MFREINDEX 0x0200   // rebuild locate field index (wks)
#define MFSCANNED 0x0400   // set=> this scan is finished (cur rec)
#define MFPREVSC  0x1000   // set=> this scan is finished (prev rec)
#define MFLKLONG  0x2000   // last lookup failed-char link value too long
#define MFTOT    0x4000 // file is "fromtot"
#define MFPARTIAL 0x8000   // file is object of partial link
#else
#define MFCLIPPER 0x0080   // signals file's index is Clipper
#define MFFOX    0x0200 // signals file's index is from foxbase
#endif

// more flags (mFlags2)
#ifdef RSW
#define MFVIEW 0x0008      // file is a view
#define MFALL  0x0010      // selecting all fields
#define MFMDX  0x0001      // index is db4 MDX file
#define MFNSX  0x0080      /* Successware NSX index files */
#else
#define MFMDX  0x0001      // index is db4 MDX file
#define MFDBT4 0x0002      // DBT file is dBASE IV format
#define MFNOLK 0x0004      // no lookup done yet (used by mflkup)
#define MFFPMEM   0x0008      // has FoxPro memo file
#define MFDIALOG 0x0010    // que DIALOG
#define MFH6MEM 0x0020     /* HiPer SIx/Six Driver memo file (.SMT) */
#define MFFLEXMEM 0x0040   /* FlexFile II memos file (.DBV) */
#define MFNSX  0x0080      /* Successware NSX index files */
#endif

#define MFNOSHOWFLDS 0x0100   // display fields for this file
#define MFQEVAL   0x0200      // evaluate query after reading from this file

#if defined RSW
#define MFOLDFLAT 0x0400   // was a flat file when report was saved,
                     // should now be treated as a table (Btrieve)
#else
#define  MFSCANGRPCHILD 0x0400
#endif

#ifndef RSW
// test for dbase index file
#define DB(n) (!(MFFiles[n]->mFlags&(MFCLIPPER|MFFOX)))
#define DBF(f) (!((f)->mFlags&(MFCLIPPER|MFFOX)))

// test for clipper index file
#define CLP(n) (MFFiles[n]->mFlags&MFCLIPPER)
#define CLPF(f) ((f)->mFlags&MFCLIPPER)

// test for foxbase index file
#define FOX(n) (MFFiles[n]->mFlags&MFFOX)
#define FOXF(f) ((f)->mFlags&MFFOX)

// test for dbase iv mdx file
#define MDX(n) (MFFiles[n]->mFlags2&MFMDX)
#define MDXF(f) ((f)->mFlags2&MFMDX)

/* test for successware NSX index file */
#define NSXF(f) ((f)->mFlags2&MFNSX)
#else
#define CLPF(f) ((f)->mFlags&MFCLIPPER)
#define FOXF(f) ((f)->mFlags&MFFOX)
#endif

// Data-dictionary code (datadict.c) needs these, even in RSW
// dBASE IV DBT file header offsets
#define mhBlkSize 20 // blocksize int at byte offset 21 (decimal)
#define mhDbtName 8  // dbt name at byte offset 8 (decimal)

// FoxPro memo file (FPT) header offsets
#define fpBlkSize 6  // long blocksize (bytes not swapped)

/* SuccssWare (SMT) memo file header offsets */
#define swBlkSize 4  /* blocksize */


// status bits
#define BADRFILE  0x01  // bad related file
#define BADRNDX      0x02  // bad index
#define BADRLINK  0x04  // bad link field
#define BADRPART  0x08  // bat match length
#define BADRALIAS 0x10  // bad alias

// flag bits of ndxtype/typechoice members
// after getmast, ndxtype will have a single bit set for current setting
// and typechoice can have multiple bits set, showing possibilities
#define NDXC 0x01 // Char index
#define NDXD 0x02 // Date index
#define NDXN 0x04 // Numeric index
#define NDXA 0x08 // dAtetime index
#define DESC 0x10 // descending index (in "ndxtype" member only)

/* meaning of "status" member on FALSE return from editmastprep() call:
      0 - aok, just call editmastgo() next
      1 - aok, but need field loss confirmation before editmastgo()

   meaning of "status" member on TRUE return from editmastprep() call:
      "status" bits indicate which PKMAST member is in error
      see the BADxxx bit definitions below
*/
#define BADMASTER 0x01  // master file member
#define BADALIAS  0x02  // alias member error
#define BADINDEX  0x04  // index member error
#define BADLOSCOPE   0x08  // lo scope member error
#define BADHISCOPE   0x10  // hi scope member error

/* status member bits */
#define BADANAME  0x01  // ascii name is bad
#define BADAALIAS 0x02  // ascii alias is bad


//
// Structure Section:
// Place in this section any structure definitions.
//
#ifdef RSW
typedef struct mfjoinpair
{
   FLDID control;
   FLDID related;
} MFJOINPAIR;

#define MFPAIRCOUNT 5

typedef struct mfjoinlist
{
   MFJOINPAIR mfpair[MFPAIRCOUNT];
   struct mfjoinlist far *mfjoinlink;
} MFJOINLIST;
#endif

//class was written because CFile::Seek was not compatible with > 2GB file
class CFileRR : public CFile {
public:
   CFileRR () : CFile () {}
   //  CAS 5/8/2012:  Changed the type definition here from int to long int (error C2664 cannot convert parameter from 'int' to 'HANDLE')
   //CFileRR (int* hFile) : CFile (hFile) {}
   CFileRR (int hFile) : CFile (hFile) {}
   CFileRR (LPCTSTR lpszFileName, UINT nMode) : CFile (lpszFileName, nMode) {}
   ULONGLONG Seek (ULONGLONG lPos, UINT nFrom) {
      LARGE_INTEGER ld;
      ld.QuadPart = lPos;
      DWORD mMethod;
      switch (nFrom) {
         case CFileRR::begin:
            mMethod = SEEK_SET;
            break;
         case CFileRR::current:
            mMethod = SEEK_CUR;
            break;
         case CFileRR::end:
            mMethod = SEEK_END;
            break;
         default:
            mMethod = SEEK_SET;
            break;
      }
      return SetFilePointer ((HANDLE)m_hFile, ld.LowPart, &ld.HighPart, mMethod);
   }
};

//  Class to access the Advantage Database Server, instead of the disk
class CADSFile : public CFileRR {
private:
   CString m_FileName;
   BOOL m_UseAdvantage;
public:

   CADSFile ();
   CADSFile (LPCTSTR lpszFileName, UINT nMode);
   void DoNotUseADS() { m_UseAdvantage = FALSE; }

   BOOL Open(LPCTSTR lpszFileName, UINT nOpenFlags, CFileException* pError = NULL);
   void Close();

   UINT Read(void* lpBuf, UINT nCount);
   CString GetFileName() const;
   ULONG GetPosition() const;
   ULONGLONG Seek (ULONGLONG lPos, UINT nFrom);
   DWORD GetLength();
};

typedef struct mffile
{
   char mLevel;            // 1-many link level number
#ifdef RSW
   MFJOINLIST mJoin;
   FLDID mLinkFld;            // link field MFBYINDEX number
#else
   FLDID mLinkFld;            // link field MFBYINDEX number
#endif
   char mLinkFlags;        // link flags (see masks below)
   FLDID mCalcFld;            // MFBYINDEX num first calc'd fld this level
   unsigned int mFlags;    // runtime flags
   unsigned int mFlags2;      // more flag bits
   char mOldFNo;           // old file number (used by read report)
   char mAlias[MAXALIAS];     // related file alias
   struct filesnap far *mSS;  // attached snapshot structure pointer
#ifdef RSW
   MFFIELD far *mFirstFld;    // first field specifier for this table
   int mFldCnt;            // number of fields for this table
   int mDataSourceOff;           // Offset into Data source array
   char mDbfName[WINPATHLEN]; // possibly qualified table name
   struct KLNTXFILE *mDbcFd;  // DBC file descriptor pointer
   int mUserIndex;            // true if a user index
   char mNdxName[FNLEN+1];    // index file name
   char mIndexExpression[SELEXBUF + 1] ; // user index expression
   unsigned int mKeyLen;      // len mLastKey including NULL for string
#else
   struct mffile far *mNextLo;   // next lower scan
   struct mffile far *mNextHi;   // next higher scan
   struct mffile far *mNextSame;// next scanner at this level
   struct mffile far *mPrevSame;// previous scanner at this level
// char far *mDbcFd;       // DBC file descriptor pointer
   struct KLNTXFILE *mDbcFd;  // DBC file descriptor pointer
   char far *mLastKey;        // ptr to last accessed key (1-many only)
   unsigned int mKeyLen;      // len mLastKey including NULL for string
// int mDbtNo;             // Lattice C file number of dbt file
// int mFileNo;            // file number of dbf file
   CADSFile dbtFile;           // dbt file
   CADSFile dbfFile;          // dbf file
   char mDbfName[FNLEN+1];    // related file name
   char mNdxName[FNLEN+1];    // index file name
   int mUserIndex;            // true if a user index
   char mIndexExpression[SELEXBUF + 1] ; // user index expression
   char mLongname[MAXDNAME];  // Visual FoxPro longname
   long mRec0Pos;          // file position of first record
   unsigned int mRecLen;      // dbf record byte length
   long mRecCnt;           // dbf record count
   long mCurRec;           // dbf current record number
   long mDbtAge;           // last access of dbt file
   long mDbfAge;           // last access of dbf file
   char mTag[MAXTAG];         // dBASE IV mdx file tag name
   UTWO mBlkSize;          // DBT file blocksize
   int mNullFlagByteCount;    // # of bytes for VFP 3 null value flags
   LPSTR mNullFlags;       // Null flag buffer at data fetch time
   unsigned int mNullFlagOffset; // rec pos of start of null flag data
#endif // not RSW
   unsigned int mLinkLen;     // if non-0, partial char link length
   int bDBCMode ;
} MFFILE;

typedef MFFILE far * LPMFFILE;

typedef struct filesnap
{
   unsigned int sFlags;    // saved runtime flags
   unsigned int sFlags2;      // more saved flag bits
   long sCurRec;           // saved dbf current record number
} MFFILESNAP;
typedef MFFILESNAP far * LPMFFILESNAP;



//
// Global Data Section:
// Place in this section any global data.
//


#if 0
GLOBAL int oldfilno;
GLOBAL LPSTR UserSelect;
#endif




//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#if 0

#if defined RSW
extern int fileinit(int leaveftb,int forTemplate, LPSTR lpSelect, int fromReadRep, LPSTR ebuf);
#else
extern   int fileinit(int leaveftb,int forTemplate);
#endif
extern   void linitalias(char far *file,char far *aliasbuf);
extern   void mfchain(void);
#if defined RSW
extern   int lmflink(int rfileno,int scan,int failcode,int *join);
#else
extern   int lmflink(int mfileno,int rfileno,int lnkfldno,char far *indexname,int scan,int failcode,int upper,int newone,char far *tag);
#endif

// SP 04/13/98 DATABASE OVERRIDE
extern bool CheckDBOverride(char *szUpdateString, int iType);

#if defined RSW
extern int lmfopen(char far *filename,int far *filenumP,int getftb,LPSTR select,
                LPSTR far *names,int fromReadRep,LPSTR ebuf,char far *alias);

#else
extern int lmfopen(char far *filename,int far *filenumP,int getftb,char far *alias);
#endif
extern   int lmfscmenu(int scnum,char far *names[],int nums[]);
extern   int mfaopen(char *name,char *alias);
extern   void mfarray(char *cp);
extern   int mfckgrp(void);
extern   void mfclose(int n,int full);
extern   void mfclrndx(void);
extern   int mfclrscope(void);
extern   int mfclosen(int n);
extern   void mfDatetimeToDate(LPMFFIELD fld);
extern   int mfgetftb(int o);
extern   int mfnf(char *s);
extern   LPMFFILE lmfnxtlvl(int level);
extern   void mfnxtinit(void);
extern   void mfondx(void);
extern   void mfrlsftb(int i);
extern   int mfscokay(int fno);
extern   int lmfsetndx(char far *indexname,int newone,char far *tag);
extern   void mfsrange(void);
extern   char *rpAlField(struct mffield far *fld,char *afbuf);
extern   sxgetnext(int (*postRead)(void));
extern   void setmaxnum(double *dp);
extern   void setminnum(double *dp);
extern   void newext(char *name,char *ext);
extern int PrepareToWiz(void);
extern int WizNext(void);
extern int StopWizing(void);

#endif


#undef GLOBAL

#endif // end _MFFILE_H_

// *************************** End of File ************************************

