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
// $Log:   G:/User Files/Nick/Projects/rrw8/archives/H/CFCOMP.H_V  $
// 
//    Rev 1.12   Jan 19 2001 14:05:22   nhubacker
// Functions for lastpage(0) and reportpage()
// 
//    Rev 1.11   Dec 12 2000 15:52:16   nhubacker
// Add f_grpage definition
// 
//    Rev 1.10   Aug 30 1999 15:43:22   BUILD
// ARP20001
// 
//    Rev 1.9   30 Nov 1998 13:41:42   wrr
// Added WO134154
// 
//    Rev 1.8.2.0   15 Jul 1998 11:33:26   wrr
// Code ported from 16bit to 32 bit
// Jim added the percomp()
// WO157195
// 
//    Rev 1.8   08 May 1997 11:29:48   pjm
// Increase MAXFORMULA size and related calcs for Visual FoxPro.
// 
//    Rev 1.7   06 Jun 1996 14:22:08   mjs
// Changes to compile under MSVC 4.1 (FAR, etc.)
// 
//    Rev 1.6   22 Sep 1995 11:31:06   sjo
// First round of FLDID changes.
// 
//    Rev 1.5   20 Jul 1995 16:39:26   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.4   30 Jun 1995 11:56:08   dlm
// See 1.21, below.
// 
//    Rev 1.3   27 Apr 1995 12:37:20   sjo
// Merge of 6.1.03+.  I say + because I have added some of the time functions
// to this merge, which will be a part of 6.1.04.  I merged the CF directories
// and some H files (for the time function changes).
// 
//    Rev 1.2   26 Apr 1995 11:28:30   pjm
// Fixed merge errors.
// 
//    Rev 1.0   16 Mar 1995 16:12:10   sbc
// Initial revision.
// 
//    Rev 1.21.1.0   18	May 1998 17:44:40   jpb   WRR7/1/98 merge from 6.5.08 to 8.0
// Add percomp function 
// 
//    Rev 1.21   07 Jun 1995 16:24:48   dlm
// Just added a comment directing changers of MAXFORMULA to YXBUFMAX in
//  product.h
// 
//    Rev 1.19   10 Apr 1995 18:23:02   jpb
// datetime/time literal cleanup
// 
//    Rev 1.18   06 Apr 1995 19:06:24   sjo
// part of fixes when looking for 'date' in cf modules.
// 
//    Rev 1.17   03 Apr 1995 15:49:22   pjm
// Assign numbers to functions, including dtlookup.
// 
//    Rev 1.16   28 Mar 1995 14:18:10   dlm
// Add pPic2 structure member to PIC structure.
// 
//    Rev 1.15   23 Mar 1995 17:10:00   sjo
// Second round of datetime support.  I changed the formula compiler and
// added some new datetime functions.  I made some changes to the picture 
// routines to handle datetime.
// 
// 
//    Rev 1.14   21 Feb 1995 17:49:50   jpb
// extern for xlower
// 
//    Rev 1.13   08 Feb 1995 13:29:14   sjo
// Checking in a bunch of files for the first wave of datetime support. These
// sources have support for a dFlags that is a long (not an unsigned int) and
// it recognizes date, time and datetime fields.  It only supports dates at
// this time, because we need calcs, picture types, etc if we are to do time and
// datetime.
// 
// 
// 
//    Rev 1.12   18 Jan 1995 17:50:32   sjo
// Made changes to remove compiler warnings.
// 
//    Rev 1.11   14 Nov 1994 16:09:54   jpb
// add ee_invudf
// 
//    Rev 1.10   14 Oct 1994 18:04:16   sjo
// Added a new flag/mask that indicates when we should display error messages
// during explt() of a sqlexp().  We should now supress error messages during 
// readrep and display them during edit and create.
// 
//    Rev 1.9   08 Sep 1994 17:35:48   sjo
// Added an error message for users trying to use a SQLEXP in a UDF. See crock
// #1069.
// 
//    Rev 1.8   25 Jul 1994 17:15:56   jpb
// add error codes for total conditions
// 
//    Rev 1.7   20 Jul 1994 17:29:12   vff
// Added ISNULL() for Runtime DLL/VBX
// 
//    Rev 1.6   16 Jun 1994 10:49:02   vff
// Merged RR6 functions into R?W 6.0
// 
//    Rev 1.5   08 Jun 1994 12:32:02   erp
//  changed FAR to far, so it will build for 32-bits
// 
//    Rev 1.4   03 May 1994 12:37:10   dlm
// Added prototype of lcfqualifyall(), used by data dictionary code.
// 
//    Rev 1.3   14 Mar 1994 15:12:16   dlm
// Added definition/declaration of FirstErr from Abra branch, conditional on
//  DATADICT.
// Moved declaration of lcfreplace() from _cfcomp.h to cfcomp.h.
// 
//    Rev 1.2   07 Dec 1993 13:35:42   nwh
// Added external function getDateFormat
// 
//    Rev 1.1   19 Nov 1993 17:43:30   sbc
// Add extern C for C++
// 
//    Rev 1.0.1.2   02 May 1994 15:14:00   dlm
// Added prototype for lcfqualifyall() in cfrepnm.c.
// 
//    Rev 1.0.1.1   28 Feb 1994 11:05:56   dlm
// Added some conditionals relating to data dictionary support.
// 
//    Rev 1.0.1.0   11 Jan 1994 10:52:46   dlm
// Added definition of FirstErr, used for efficiency in testing validity
//  of LOOKUP function arguments.
// Moved lcfreplace() extern here from _cfcomp.h.
// 
//    Rev 1.0   14 Oct 1993 10:12:04   erp
// Initial revision.
// ****************************************************************************
//
// Check to make sure this is not included more than once.
//
#ifndef _CFCOMP_H_

//
// Make a definition for this module.
//
#define _CFCOMP_H_

#if defined(_CFCOMP_C_)
#define GLOBAL
#else
#define GLOBAL extern
#endif

// **********************************************************************
//
// Defines Section:
// Place in this section any #define statements that are needed by this
// include file.
//
	// from udf.h
#define UDFNAMELEN 20	/* maximum udf name length (excl NULL) */
#define DECLEN 256		/* buffer length for formal declaration */
#define UMAXDEPTH 128	/* limits nesting of user functions */
#define UMAXARGS 128	/* max number of args to a user function */

	// from token.h
/* token.h */


#define MAXFORMULA 2048	// max length of calc field formula 
						// See YXBUFMAX in product.h if this grows !!!

#define TOKLEN 520		/* max token length (max str literal + a pinch) */

/* token number definitions
N.B.	must match entry order of characters in special
		character array in token.c
*/

/* arithmetic operators */
#define t_plus				0x01		/* + */
#define t_minus				0x02		/* - */
#define t_div				0x03		/* / */
#define t_mul				0x04		/* * */
#define t_exp				0x05		/* ** or ^ */
#define t_pct				0x06		/* ** or ^ */

/* special tokens */
#define t_lp				0x07		/* ( */
#define t_rp				0x08		/* ) */
#define t_comma				0x09		/* , */
#define t_box				0x0A		/* beginning of expression */
#define t_eox				0x0B		/* end of expression */
#define t_err				0x0C		/* bad token */
#define t_num				0x0D		/* number */
#define t_func				0x0E		/* function */
#define t_fld				0x0F		/* field */
#define t_file				0x10		/* file */

/* relational operators */
#define t_eq				0x11		/* = */
#define t_neq				0x12		/* # or <> */
#define t_le				0x13		/* <= */
#define t_ge				0x14		/* >= */
#define t_lt				0x15		/* < */
#define t_gt				0x16		/* > */

/* logical operators */
#define t_and				0x17		/* .and. */
#define t_or				0x18		/* .or. */
#define t_not				0x19		/* .not. */

/* logical values */
#define t_true				0x1A		/* .t. */
#define t_false				0x1B		/* .f. */

/* string stuff */
#define t_cat				0x1C		/* + (normal concatenation) */
#define t_tcat				0x1D		/* - (trimmed concatenation) */
#define t_subst				0x1E		/* $ (substring) */
#define t_str				0x1F		/* string token */

#define t_noarg				0x20		/* missing argument */
#define t_date				0x21		/* date */

#define t_pgerr				0x22		/* pageno() error flag */
#define t_memo				0x23		/* memo error flag */
#define t_qualify 			0x24		/* fieldname qualification error flag */

#define t_now				0x25		/* lotus type @now */

#define t_query 			0x26
#define t_datetime 			0x27	/* datetime */
#define t_ztime				0x28	/* Time - couldnt use t_time because */
									/*        it conflicts with functab  */ 
#define t_keyword  			0x29	// KEYWORD, like yyyy for year, n for minutes
#define t_dateinterval 		0x2A
#define t_timeinterval 		0x2B
#define t_datetimeinterval	0x2C
#define t_timepicture		0x2D

#define TOKEN_COUNT			0x2D		/* number of tokens (start with 1) */

	// from token.h   TLOG could be private, if weren't used in explt.c
#define TLOG     0x80		/* set in operand token code => logical value */

/* define NEXTTEST to include read-ahead test function NEXT
   in modules pnum, fnum, functab, tfunctab.asm, and action.h */

/* #define NEXTTEST 1	*/

#define IIFDEPTH 100		/* max depth, nested iif() */

/* action codes */

/* arithmetic */
#define a_plus		0x00	/* addition */
#define a_minus		0x01	/* subtraction */
#define a_div		0x02	/* division */
#define a_mul		0x03	/* multiplication */
#define a_exp		0x04	/* exponentiation */
#define a_uplus		0x05	/* unary plus */
#define a_uminus	0x06	/* unary negative */
#define a_pct		0x07	/* percentage */

/* interpreter directives */
#define a_ret		0x08	/* return */
#define a_num		0x09	/* push number */
#define a_fld		0x0A	/* push field reference */
#define a_file		0x0B	/* push file reference */
#define a_func		0x0C	/* execute funtion */
#define a_true		0x0D	/* push TRUE */
#define a_false		0x0E	/* push FALSE */

/* relational */
#define a_eq		0x0F	/* test for equality */
#define a_neq		0x10	/* test for inequality */
#define a_le		0x11	/* test for less than or equal to */
#define a_ge		0x12	/* test for greater than or equal to */
#define a_lt		0x13	/* test for less than */
#define a_gt		0x14	/* test for greater than */

/* logical */
#define a_and		0x15	/* AND */
#define a_or		0x16	/* OR */
#define a_not		0x17	/* NOT */

/* string stuff */
#define a_cat		0x18	/* + (normal concatenation) */
#define a_tcat		0x19	/* - (trimmed concatenation) */
#define a_subst		0x1A	/* $ (substring) */
#define a_str		0x1B	/* push string */
#define a_noarg		0x1C	/* push "no argument" */

/* date arithmetic operators */
#define a_datedif	0x1D	/* subtract two dates */
#define a_plusdays	0x1E	/* add date and number of days */
#define a_subdays	0x1F	/* subtract number of days from date */

/* function argument separators - used for iif, inlist, case functions */
#define a_argsep	0x20	/* argument separator */

/* special "push previous value of field" operator, for PREV() */
#define a_pfld		0x21	/* push prev-field reference */

/* special "push empty memo" operator */
#define a_mtmemo	0x22	/* push empty memo */

#define a_ufarg		0x23	/* push user function argument */
#define a_ufunc		0x24	/* execute user function */
#define a_ufparg	0x25	/* push user function argument (prev) */

#define a_now		0x26	/* push @now value */
#define a_bfalse	0x27	/* branch on false */
#define a_branch	0x28	/* branch */

#define a_date		0x29	/* date literal */
#define a_datetime	0x2A	/* datetime literal */
#define a_time		0x2B	/* time literal */
#define a_keyword	0x2C	/* keyword */

#define MAX_ACTION	0x2C	/* highest action code value */

/* function codes corresponding to placement in functab[] list in functab.c */
#define f_min		0x00 
#define f_max		0x01 
#define f_exp		0x02 
#define f_int		0x03 
#define f_log		0x04 
#define f_rnd		0x05 
#define f_sqrt		0x06 
#define f_at		0x07 
#define f_len		0x08
#define f_lower		0x09 
#define f_upper		0x0A 
#define f_space		0x0B 
#define f_substr	0x0C 
#define f_ftrim		0x0D 
#define f_asc		0x0E 
#define f_chr		0x0F 
#define f_str		0x10 
#define f_val		0x11 
#define f_date		0x12 
#define f_cdow		0x13 
#define f_cmonth	0x14 
#define f_ctod		0x15 
#define f_day		0x16 
#define f_dow		0x17 
#define f_dtoc		0x18 
#define f_month		0x19 
#define f_year		0x1A 
#define f_time		0x1B 
#define f_page		0x1C 
#define f_recn		0x1D 
#define f_isalpha	0x1E 
#define f_islower	0x1F 
#define f_isupper	0x20 
#define f_ltrim		0x21 
#define f_rtrim		0x22 
#define f_left		0x23 
#define f_right		0x24 
#define f_replica	0x25 
#define f_stuff		0x26 
#define f_abs		0x27 
#define f_mod		0x28 
#define f_adddays	0x29 
#define f_addwks	0x2A 
#define f_addmons	0x2B 
#define f_addyrs	0x2C 
#define f_subdays	0x2D 
#define f_subwks	0x2E 
#define f_submons	0x2F 
#define f_subyrs	0x30 
#define f_daysbtw	0x31 
#define f_wksbtwn	0x32 
#define f_monsbtw	0x33 
#define f_yrsbtwn	0x34 
#define f_week		0x35 
#define f_dqtr		0x36 
#define f_qtr		0x37 
#define f_if		0x38 
#define f_inrng		0x39 
#define f_inlst		0x3A 
#define f_flip		0x3B 
#define f_transform	0x3C 
#define f_caps		0x3D 
#define f_case		0x3E 
#define f_error		0x3F 
#define f_sndx		0x40 
#define f_wdcnt		0x41 
#define f_word		0x42 
#define f_spelln	0x43 
#define f_prev		0x44 
#define f_copy		0x45 
#define f_query		0x46
#define f_strsearch	0x47
#define f_strcount	0x48
#define f_strrep	0x49
#define f_deleted	0x4A 
#define f_blnknum	0x4B
#define f_isblank	0x4C
#define f_hiscope	0x4D
#define f_loscope	0x4E
#define f_dbf		0x4F
#define f_reccnt	0x50
#define f_scan		0x51
#define f_update	0x52 
#define f_like		0x53
#define f_rrunin	0x54 
#define f_isna		0x55 
#define f_choose	0x56 
#define f_exact		0x57 
#define f_atif		0x58 
#define f_rows		0x59 
#define f_riparam	0x5A 
#define f_ln		0x5B
#define f_moy		0x5C
#define f_nrecs		0x5D
#define f_numval	0x5E
#define f_search	0x5F
#define f_strval	0x60
#define f_table		0x61
#define f_today		0x62
#define f_fill		0x63
#define f_clookup	0x64
#define f_dlookup	0x65 
#define f_llookup	0x66
#define f_nlookup	0x67 
#define f_dll 	 	0x68
#define f_ixsql 	0x69
#define f_rr 		0x6A
#define f_libn		0x6B
#define f_repn		0x6C	
#define f_udfn		0x6D	
#define f_half		0x6E	
#define f_monl		0x6F	
#define f_aged		0x70	
#define f_past		0x71	
#define f_futu		0x72	
#define f_over		0x73	
#define f_ndow		0x74	
#define f_pdow		0x75  
#define f_isnull	0x76
#define f_dateadd 	0x77		// DATEADD, RETURN TYPE DATE
#define f_datediff	0x78
#define f_todate	0x79
#define f_datepart	0x7A 
#define f_dateadddt	0x7B	// DATEADD, RETURN TYPE DATETIME	
#define f_dateaddt	0x7C	// DATEADD, RETURN TYPE TIME
#define f_tottime	0x7D
#define f_dttoc		0x7E
#define f_ttoc		0x7F
#define f_dtlookup	0x80
#define f_ttos			0x81
#define f_ctdt			0x82
#define f_ctos			0x83	// character to seconds
#define f_ctot       0x84
#define f_stoc       0x85	// seconds to character
#define f_percomp    0x86	// eval once per composite (!)   //WRR 7/1/98 form 6.5.08 to 8.0
#define f_now		 0x87
#define f_lastpage	0x88
#define f_reportpage	0x89
	// NOTE: IF YOU ADD FUNCTIONS, UPDATE MAX_FUNC
   //       IN CFMISC.H....... ALSO UPDATE THE TABLE IN
	//    	XEVAL.C


/* NOTE:
	Args string has following format :
	1st byte 	= n, the number of arguments for function. If n = 0xFF,
					the function takes a variable number of arguments, and
					the next byte is the type of all arguments, otherwise
	bytes 2 - n+1 list the argument types in sequence
*/

/* argument types */
#define sv_dbl    			0x01		/* a double precision number */
#define sv_int    			0x02		/* an int */
#define sv_lng    			0x03		/* a long int */
#define sv_str    			0x04		/* string */
#define sv_fld    			0x05		/* a field reference (MFFIELD *) */
#define sv_none   			0x06		/* no argument */
#define sv_date   			0x07		/* a date */
#define sv_file   			0x08		/* a file reference (MFFILE *) */
#define sv_memo   			0x09		/* a memo field */
#define sv_any    			0x10		/* any of date, dbl, str */
#define sv_many   			0x11		/* sv_any plus memo */
#define sv_prev   			0x12		/* same as last type */
#define sv_pfld   			0x13		/* a prev field reference (MFFIELD *) */
#define sv_mtmemo 			0x14		/* an empty memo reference */
#define sv_char   			0x14		/* a memo or char field */
#define sv_query  			0x15		/* query return type */ 
#define sv_datetime 		0x16		/* a date/time/datetime type */
#define sv_time				0x17		/* a time type */
#define sv_dateinterval		0x18	// Used to identify a date interval (day,year)
#define sv_timeinterval		0x19  // Used to identify a time interval (hour,min)
#define sv_datetimeinterval	0x1A	// Either a date or time interval
#define sv_timepicture		0x1B		// timepicture keyword for CTOS,STOC

#define OPTARG				0x80		/* optional arg bit in arg type byte */
#define LOGICAL 			0x40		/* type is logical, really */
#define PARG				0x20		/* signals prev of arg in udf (compile) */



#define pNUM   		0x0001
#define pDATE  		0x0002
#define pSTR   		0x0003
#define pLOG   		0x0004
#define pFILE  		0x0005
#define pNONE  		0x0006
#define pDATETIME	0x0007
#define pTIME		0x0008
#define pKEYWORD 	0x0009
#define pCONST 		0x8000	/* mask for "it's a constant" bit */

/* cferr.h	calc error codes */

#define ee_unk		0x01	/* unkown action code */
#define ee_argc		0x02	/* bad argument count */
#define ee_funcn	0x03	/* function number out of range */
#define ee_argt		0x04	/* wrong argument type */
#define ee_argr		0x05	/* required argument */
#define ee_op		0x06	/* illegal operation */
#define ee_data		0x07	/* badly formatted data */
#define ee_oflo		0x08	/* evaluate stack overflow */
#define ee_rpnoflo	0x09	/* rpn buffer overflow */
#define ee_synoflo	0x0A	/* syntax stack overflow */
#define ee_paren	0x0B	/* unbalanced parentheses */
#define ee_token	0x0C	/* bum token */
#define ee_badstr	0x0D	/* unterminated string */
#define ee_memo		0x0E	/* memo field referenced */
#define ee_qual		0x0F	/* fieldname needs qualification */
#define ee_bufoflo	0x10	/* string result buffer overflow */
#define ee_argc2	0x11	/* improper number of arguments (CASE()) */
#define ee_argf		0x12	/* function argument must be field ref */
#define ee_udepth	0x13	/* user function stack overflow */
#define ee_ifdepth	0x14	/* nested iif compile stack overflow */

#define ee_invudf	0x15	/* use of invalid user function */
#define ee_qrun		0x16	/* cannot query on running total */
#define ee_qfin		0x17	/* can query only on highest level fintot */
#define ee_imem 	0x18	/* insufficient memory */
#define ee_toolong 	0x19	/* formula too long */
#define ee_rtq		0x1A	/* Type cannot be changed. Field used in query */
#define ee_ptl		0x1B	/* Cannot use page total field to control line printing */
#define ee_uts		0x1C	/* Unsupported totals sort */
#define ee_sgr		0x1D	/* Cannot sort or group on running-total-related field */
#define ee_tsf		0x1E	/* Cannot skip if linking field is total-related */
#define ee_sgp		0x1F	/* Cannot sort or group on page number field */
#define ee_pnl		0x20	/* Cannot link with page number field */
#define ee_pnq		0x21	/* Cannot query on page number field */
#define ee_rnl		0x22	/* Cannot link with composite record number field */
#define ee_rnq		0x23	/* Cannot query on composite record number field */
#define ee_rns		0x24	/* Cannot sort on composite record number field */
#define ee_sgm		0x25	/* Cannot sort or group on memo field */
#define ee_mfl		0x26	/* Cannot link with memo field */
#define ee_sgv		0x27	/* Cannot sort or group on PREVIOUS()-related field */
#define ee_srs		0x28	/* Cannot sort on self-referencing field */
#define ee_tcl		0x29	/* Type cannot be changed. Field is linking field */
#define ee_tct		0x2A	/* Type cannot be changed. Field is totaled */
#define ee_cef		0x2B	/* Circular calculations. Cannot evaluate %s */
#define ee_bnm		0x2C	/* Bad name */
#define ee_dnm		0x2D	/* Dup name */
#define ee_niu		0x2E	/* Name in use */
#define ee_nop		0x2F	/* No opening parenthesis */
#define ee_ban		0x30	/* Invalid argument name */
#define ee_ncp		0x31	/* No closing parenthesis */
#define ee_bfn		0x32	/* Invalid function name */
#define ee_aiu		0x33	/* Argument name in use */
#define ee_mar		0x34	/* Missing argument */
#define ee_anu		0x35	/* First four characters of name not unique */
#define ee_luse		0x36	/* cannot delete - used in linking field */
#define	ee_baddate	0x37	/* invalid date constant */
/* start of section added to for RR5 funcs */
#define ee_query	0x38	/* illegal use of QUERY() */
#define ee_qinuser	0x39 	/* Cannot use QUERY() in a user defined function */
#define ee_qindirect	0x3A /* QUERY() used indirectly */
#define ee_qused	0x3B 	/* Function used in another function cannot contain QUERY() */
#define ee_qinquery	0x3C	/* Function used in the query cannot contain QUERY() */
/* end of section added to for RR5 funcs */
#define ee_invrun	0x3D	/* invalid running total query */
#define ee_dummy	0x3E	/* Formula uses missing field */
#ifdef RSW
#define ee_invjoin	0x3F	/* calc'd join fld would be made unxlatable */
#define ee_sqlsel   0x40
#endif
#define ee_cttot	0x41	/* total condition cannot depend on total */
#define ee_ctmem	0x42	/* total condition cannot be a memo */
#ifdef RSW
#define ee_nosqlexpudf	0x43	/* no SQLEXP in UDFs */
#endif
#define ee_const	0x44	// parameter value is not a constant
#define ee_max		0x44	/* highest code */

	// from cfbuf.h
/* Added the following defines to support picture handling for SQLEXP()
   functions, this is used in lcompile and any routine which calls it.
*/

#define CF_CREATE	 0x001		/* we are creating the calc */
#define CF_EDIT  	 0x002		/* we are editing the calc */
#define CF_FROMREP 0x004	 	/* we are getting the calc from the rep lib */

/* Added the following defines to support SQLEXP() in explt. The calling 
 routine tells lexplt() whether or not to call the engine to evaluate the
 expression or not.  Also whether or not to show the error (if there is one
 from the select statement). We do not show the error on read rep.
*/
#define COMPILE		0x001
#define REEVAL		   0x002  
#define SHOW_ERROR	0x004

// size of MFSQLcontrol buffer used by mfsqlsel() in mfsql.c
#define CONTROL_SIZE 2000

// The following define the various date time interval keywords.
//  If you are going to be adding new keywords (for other functions,
//	 or for the existing datetime functions), the keywords should be
//  unique and identified by an sv_<keywordtype>interval. This is 
//  used in eval, to identify the type of the argument on the eval
//  stack.
// There is a routine in token.c, which identifies the argument as
//  a keyword, and it returns a t_<keywordtype>interval value, along
//  with the appropriate value below.  We need both the <kewordtype>
//  interval and the number below, so we can identify the return type
//  of the function at compile time.

#define KYEAR 			0x01
#define KQUARTER		0x02
#define KMONTH			0x03
#define KDAYOFYEAR	0x04
#define KDAY			0x05
#define KWEEKDAY		0x06
#define KWEEK			0x07
#define KHOUR			0x08
#define KMINUTE		0x09
#define KSECOND		0x0A

// Time picture keywords
#define KHH  		0x01
#define KMM       0x02
#define KSS       0x03
#define KHHMM     0x04
#define KHHMMSS   0x05
#define KMMSS     0x06

// **********************************************************************
//
// Structure Section:
// Place in this section any structure definitions.
//
	// from token.h - (TOKVAL could be private if weren't used in cfrepnm.c)

typedef struct nval
{
	char dec;
	double val;
} NVAL;

// I put in this for datetime tokens, but I may not need
//  it
typedef struct dtval
{
	long 		tokDate;
	double	tokTime;
} DTVAL;

// This is used for keyword tokens.  Keywords are being used for 
typedef struct keyval
{
	int	skeytype;			// syntax version of the keyword
	int   ckeytype;         // compiled version of the keyword
	int	numericVal;
	char	tString[TOKLEN];
} KEYVAL;

typedef union tokval
{
	NVAL	tNumber;
	int	tInteger;
	long	tDate;
	DTVAL	tDateTime;
	char	tString[TOKLEN];
	KEYVAL tKeyword;
	FLDID	tFldId;
} TOKVAL;

typedef struct pic
{
	unsigned int pType;			/* data type */
	unsigned int pPic;			/* data picture code (dFldPic) */
	unsigned int pPic2;			/* data picture code 2 (dFldPic2) */
	unsigned int pMaxLen;		/* max string data length (excluding terminator) */
	unsigned int pLen;			/* data length */
	char pDec;			/* data decimal places */
	char pInt;			/* data integer places */
	double pVal;		/* value (if numeric constant) */
} CFPIC;


// **********************************************************************
//
// Global Data Section:
// Place in this section any global data.
//

#undef GLOBAL

#endif // end _CFCOMP_H_

// *************************** End of File ************************************
