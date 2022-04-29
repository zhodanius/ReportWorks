// ****************************************************************************
//
//      (C) Copyright 1992-1993 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $WorkFile$
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
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/H/INDEX.H_V  $
//
//    Rev 1.7   Aug 31 2000 13:47:18   nhubacker
// Support for dbase 7.5 MDX files
//
//    Rev 1.6   06 Jun 1996 14:21:16   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
//
//    Rev 1.5   19 Mar 1996 11:10:58   jpb
// change fUNIQUE to fFLAGS, now that we know more bits are used
//
//    Rev 1.4   23 Jan 1996 19:06:14   jpb
// fox integer type
//
//    Rev 1.3   17 Nov 1995 19:04:24   smh
// Win32 file i/o.
//
//    Rev 1.2   17 Jul 1995 09:27:18   dlm
// Changed functions to CRrDoc member functions and variables to CRrDoc
//  member variables.
//
//    Rev 1.1   26 Apr 1995 13:17:14   pjm
// 6.1.03 -> 7.0 merge.
//
//    Rev 1.0   16 Mar 1995 16:12:44   sbc
// Initial revision.
//
//    Rev 1.7   31 Mar 1995 18:00:46   jpb
// datetime changes
//
//    Rev 1.6   18 Jan 1995 17:50:36   sjo
// Made changes to remove compiler warnings.
//
//    Rev 1.5   14 Oct 1994 18:03:34   sjo
// Added some stuff to the klnode struct.  This was needed for NSX performance
// improvements I made (see kldecomp, klfiles and klinit).
//
//    Rev 1.4   28 Sep 1994 15:46:56   sbc
// FileOpenName -> Paths
//
//    Rev 1.3   19 Aug 1994 09:29:16   erp
// fixed multiple include check section
//
//    Rev 1.2   18 Feb 1994 15:26:36   sjo
// I am merging the RRWINNSX branch back onto the RRWIN tree. This branch was
// setup to allow me to port my RR 5.1 NSX, SMT and DBV changes to RRW and
// RSW.
//
//    Rev 1.1.1.0   21 Jan 1994 16:46:54   sjo
// I am merging RR 5.1 changes into the windows products.  I added a number of
// offsets to support NSX index types.
//
//    Rev 1.1   19 Nov 1993 17:45:00   sbc
// Add extern C for C++
//
//    Rev 1.0   14 Oct 1993 10:12:42   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _INDEX_H_
//
// Make a definition for this module.
//
#define _INDEX_H_


#if defined(_KLINIT_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif

//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
#define KEYTYPE(n) ((n)->klKeyType&0xFF)
#define DIALTYPE(n) (((unsigned)((n)->klKeyType))>>8)
#define SETKEYTYPE(n,t) (n)->klKeyType = (((n)->klKeyType)&0xFF00) + (t=='A'? 'D' : t)

#define  DBTYPE      0  /* dbase type index */
#define  CLIPTYPE 1  /* clipper type index */
#define  FOXTYPE     2  /* foxbase type index */
#define  MDXTYPE     3  /* dBASE IV MDX type index */
#define DLTYPE    4  /* DIALOG type index */
#define CIDXTYPE  5  /* compact FOX IDX type index */
#define CCDXTYPE  6  /* compact FOX CDX type index */
#define WDXTYPE      7  /* ARAGO WDX type index */
#define NSXTYPE      8  /* SuccessWare NSX type index */

#define DIALID    0x20da   /* DIALOG index signature */

#define  KLNODESIZE  0x400 /* 1024;  max(kl,db,...) */
#define  DBNODESIZE  0x200 /* 512 */
#define DLNODESIZE   0x400 /* 1024 */
#define  MDNODESIZE  0x400 /* 1024 */
#define  MDBLKSIZE   0x200 /* 512 (pointers are 512-byte block numbers) */
#define  SXBLKSIZE   0x200 /* 512 */
#define  SXNODESIZE  0x400 /* 1024 */
#define  MAXEXPRSZ   254
#define  MAXKEYSZ 250      /* changed from 100 for RR 4.0 */
#define  MAXNTXS     100   /* max number of indexes open at one time */
#define  MAXTAGS     47 /* max number of tags per MDX file */

/* index header info positions */
#define kKEYEXPR  22
#define kTOPNODE  4
#define kKEYLEN      14
#define kDECPL    16

#define dUNIQUE      23
#define dKEYEXPR  24
#define dTOPNODE  0
#define dKEYLEN      12
#define dPTRLEN      18
#define dKEYTYPE  16

#define fFLAGS    14
#define fKEYEXPR  16
#define fTOPNODE  0
#define fKEYLEN      12

/* compressed FOX IDX files */
#define xFLAGS    14
#define xTOPNODE  0
#define xKEYLEN      12
#define xKEYEXPR  512
#define xDESCEND  502      /* (apparently only for CDX)  */

/* xFLAGS bits */
#define xfUNIQUE  0x01
#define xfNULL    0x02
#define xfCOMPACT 0x20

/* xDESCEND bits */
#define xdDOWN    0x01

/* DIALOG index header offsets */
#define  iKEYEXPR 112
#define  iKEYXLEN 60
#define  iKEYLEN     52
#define  iUNIQUE     65
#define  iKEYTYPE 64
#define  iTOPNODE 2
#define iPTRLEN      56

/* MDX file offsets */
/* file header */
#define mIXBSZ    22    /* index block size */
#define mTAGCNT      28    /* number of tags in mdx file */
#define mTAG1     0x220 /* offset to 1st tag specifier in header */
#define mTAG1_7      0x22b
#define mTAGLEN      0x20  /* len of tag specifier in header */
#define mTAGLEN_7 0x2b

/* NSX file offsets */
#define sSXBSZ       0x0200   /* Node block size */
#define sSXTAGCNT    2        /* Offset of the tag count */
#define sSXTAGST     14       /* Start of the tag chain */
// Once you are pointing at the beginning of the tag references, then
// tsSXTNAME is the offset of the tag name, sTAGLEN is the length of the
// name and tsSXTAGHDR is the offset of the file offset for this tag.
//

#define tsSXTNAME    0
#define tsSXTAGHDR   12       /* tag specifier offset of tag name */
#define sTAGLEN      12

/* tag specifier */
#define tsHDR     0     /* tag specifier offset of tag header block */
#define tsNAME    4     /* tag specifier offset of tag name */

/* tag header */
#define mTOPNODE  0
#define mUDFLAGS  8     /* bit layout below */
#define mKEYTYPE  9
#define mKEYLEN      12
#define mPTRLEN      18
#define mKEYEXPR  24

/* NSX tag header offsets */
#define sSXTSIG   0     /* Index Tag Signature */
#define sSXTROOT  2     /* Offset of root block */
#define sSXTTYPE  6     /* Index key type */
#define sSXTLEN   8     /* Index key length */
#define sSXTUFLAG 10    /* Unique index flag */
#define sSXTDESC  12    /* Descending index flag */
#define sSXTKEXP  14    /* Index key expression */
#define sSXTCEXP  270   /* conditional expression */

/* NSX specific defines */
#define sREGINDEX       0x0069
#define sPARINDEX       0x0169
#define sTEMPINDEX      0x0269
#define sCHANGESINDEX   0x0469
#define sNOUPDATEINDEX  0x0869
#define sSHADOWINDEX    0x1069

#define sNUM      0x0008   /* Numeric key type */
#define sDATE     0x0020   /* Date key type */
#define sLOGICAL  0x0080   /* Logical key type */
#define sCHAR     0x0400   /* Character key type */

/* WDX file offsets */
#define wdxID     0     /* id byte contains hex 33 */
#define wdxCNT    3     /* count byte - number of tags */
#define wdxNM     4     /* 8 byte filename root (no extension) */
#define wdxTG     14    /* offset to first tag name */

#define WDXTGLN      10    /* length of tag name */

#define TGBUFSIZE mTAGLEN_7   /* max of mTAGLEN, WDXTGLN */

/* mUDFLAGS bit layout */
#define mfUNIQUE  0x40
#define mfDESCEND    0x08


/* return codes */
#define  x_SUCCESS   0
#define  x_ERROR     1
#define  x_NOKEY     7
#define  x_MAYBE     8
#define  x_ENDKEY 9
#define  x_TOPKEY 11


/* _klerr codes */
#define KLOKAY    0
#define KLMEMERR  1
#define KLBADFILE 2
#define KLRDERR      3
#define KLMAXFILES   4
#define KLNOCLIP  5
#define KLBADPTR  6
#define KLNOFILE  7
#define KLESCAPE  8  /* user escape from tag name entry */
#define KLBADTAG  9
#define KLIXBSZ      10 /* index file block size not supported */


#define KEYLEN char



//
// Structure Section:
// Place in this section any structure definitions.
//
typedef struct klnode
{
   long  klNodePos;  /* file (block num if db) position of node */
   int   klNKeys; /* # of keys within node (#-of-ptrs - 1) */
   int   klKeyPos;   /* current key position within node */
   char far *klNodeBuf; /* pointer to external buffer (or NULL)*/
   char far *klPrevKey; /* previous key,used for NSX indexes only */
   long  klPrevNodePos; /* keep track of the prev node pos as well */
   int   klPrevPos;     /* previous key position within the node */
} KLNODE;

struct KLNTXFILE
{
   int   klFileType; /* DBTYPE = 0, CLIPTYPE = 1, FOXTYPE = 2, MDXTYPE = 3 */
   int   klNodeSz;   /* size of node (512 or 1024) */
//another update with pre-compiler directives to try and clear up differences
//between the ADS file type and the standard one CAS 8/22/2014
#if !defined(RSW)
   CADSFile klCFile;    /* file handle */
#else
   CFile klCFile;
#endif
   int   klKeyLen;   /* key length */
   int   klMisc;     /* kl-># of dec. pl.'s;db->key+ptr+recno len*/
   int   klKeyType;  /* character or numeric ('C' or 'N')*/
   long  klTopNode;  /* file (block num if db) pos. of root node */
   KLNODE   klNodePath[MAXLEVELS];  /* current descending node path */
   int   klNPIndex;  /* node path index (current level in tree) */
   int   klBufIndx;  /* index of klipper buffer outside data seg */
   int   klBufCnt;   /* number of assigned external buffers */
   long klTagHead;   /* tag header block if mdx file */
   int klDescend; /* non-zero=>descending index */
   int klFoxNULL; /* true if indexed on Fox NULLable field */
   int klDepth;   /* index tag depth */
   long klFilePos;   /* file position (for close/reopen) */
} ;

typedef struct TName    /* tag name structure */
{
   struct   TName *tnLk;      /* link */
   long  tnHdr;            /* header block */
   char  tnName[1];  /* this is actually up to ?? including NULL */
} TNAME;

#define  TNSize sizeof(TNAME) /* size excluding tnName, but incl. NULL
                           at end of tnName string */


typedef KLNODE far * LPKLNODE;
typedef KLNTXFILE far * LPKLNTXFILE;

//
// Global Data Section:
// Place in this section any global data.
//


#if 0
GLOBAL   char far * near NodeBuf;   /* ptr to node read buffer */
GLOBAL   int   near _klerr;   /* error code */
#endif


//
// Function Prototypes Section:
// Place in this section any function prototypes
//


#if 0
extern   int kltagchain(LPSTR ntxname,struct TName **chainP );
extern   void klfreetag(void);

extern   int lklckey(char FAR *ntxfd,char FAR *key,long FAR *recno);
extern   int lklcleanup(struct klntxfile FAR **ntxs ,int stop);
extern   int lkliopen(char FAR *ntxname,char FAR *FAR *ntxfd ,int newone,char FAR *tag);
extern   int lkliclose(char FAR *ntxfd);
extern   int lklinit(struct klntxfile FAR **ntxs ,int stop);
extern   int lklnkey(char FAR *ntxfd,char FAR *key,long FAR *recno);
extern   int lklpkey(char FAR *ntxfd,char FAR *key,long FAR *recno);
extern   int lkltkey(char FAR *ntxfd,char FAR *key,long FAR *recno);
extern   int lklkexpr(char FAR *ntxfd,char FAR *keytype,char FAR *keyexpr,int FAR *kexprlen,char FAR *keylen,int FAR *unique,int FAR *descend);
extern   int lkltkeyext(char FAR *ntxfd,char FAR *key,long FAR *recno,int len);
#endif


#undef GLOBAL
#endif // end _INDEX_H_

// *************************** End of File ************************************

