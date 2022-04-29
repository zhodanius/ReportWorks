/* dbheader.h  - stuff common to runtime.c and dbexport.c */

// Check to make sure this is not included more than once.
//
#ifndef _DBHEADER_H_

//
// Make a definition for this module.
//
#define _DBHEADER_H_

/*** dBC New Types ***/
typedef long     RECNUM;   /* record number */
typedef char     FLDNUM;   /* number of fields per record */
//typedef unsigned RECLEN;   /* record length */
typedef char     FLDWIDTH; /* field width in bytes or characters */
typedef char     FLDDEC;   /* decimal places in field */

/******************************************/
/* .DBF record field definition structure */
/******************************************/
// DON'T CHANGE THE ORDER OF THIS STRUCTURE, IT IS WRITTEN TO DBF FILES DIRECTLY
// ALSO MEANS THAT MUST COMPILE WITH BYTE STRUCTURE ALIGNMENT
	typedef struct
	{	char fieldnm[11]; /* field name terminating with NULL(0) */
		char type;        /* type of data */
					/*  'C' - character
						'N' - numeric
						'D' - date
						'L' - logical
						'M' - memo    */
		FLDWIDTH width;   /* field width */
		FLDDEC   dec;     /* length of decimal places */
	} dBFIELD;

#define SUCCESS   0    /** successful function return code **/
#define d_ERROR   1    /** general error code **/

/* .DBF file offset definitions */
#define FILETYPE 0 /* file type */
#define  DBF1 0x03 /* .DBF file type 1 */
#define  DBFM 0x83 /* .DBF file type 2 */
#define YEAR  1  /* year */
#define MONTH 2  /* month */
#define DAY   3  /* day */
#define RNUM0 4  /* number of records allocated < 1st byte > */
#define RNUM1 5  /* number of records allocated < 2nd byte > */
#define RNUM2 6  /* number of records allocated < 3rd byte > */
#define RNUM3 7  /* number of records allocated < 4th byte > */
#define FREC0 8  /* address of first record */
#define FREC1 9  /* address of second record */
#define RLEN0 0x0a /* record length < 1st byte > */
#define RLEN1 0x0b /* record length < 2nd byte > */
#define Z0C   0x0c /* zero byte BEGIN */
#define Z1F   0x1f /* zero byte END   */
#define FSTFIELD 0x20 /* first field offset */
#define TYPE  0xb /* type offset ('C', 'N', 'L', 'M' or 'D'): */
		  /* added to field offset */
#define  UU0C     0xc  /* unused byte BEGIN */
#define  UU0F     0xf  /* unused byte END */
#define  WIDTH    0x10 /* width offset: added to field offset */
#define  DECPLACE 0x11 /* decimal point offset: added to field offset */
#define   FZ12     0x12 /* field zero byte BEGIN */
#define   FZ1F     0x1f /* field zero byte END */
#define NXTFIELD 0x20 /* add NXTFIELD to get next field offset */
#define BEGINDATA ((dbfptr)->_begdata)

/* special character definitions in data file */
#define EOFIELD  0x0d  /* end of field marker in data file */
#define EODATA	 0x1a  /* end of data marker in data file */
#define EOBLKID  (-1)    /* end of block-id marker in seq. vector */

/****************** End of stuff from DBC headers *********************/
#endif

