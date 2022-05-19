// ****************************************************************************
//
//		(C) Copyright 1992-1993 Concentric Data Systems, Inc.
//						All Rights Reserved.
//
//
// Module $WorkFile$
// ================
//
// Description:
// ============
//		prepare expression for tokenization and compilation
//
//
// Modification History
// ====================
//
// Revision    Date 	   Time 	  Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/cfcomp/cfprep.cpv  $
//
// Rev 1.50    17 Jul 2015 15:21:19   CAS
//
// R&R SQL would crash if a field used in a join was no longer in the target table.
// This revision immediately checks the value of the parameter "input" in lcfprep
// and if it's NULL, returns FALSE right away.  This generates a "join must be edited"
// message instead of a total access violation crash.
// 
//    Rev 1.4   18 Sep 1995 15:00:20   jpb
// move funcs to CRrComposite
// 
//    Rev 1.3   02 Aug 1995 12:05:34   sjo
// Fixed a link error.
// 
//    Rev 1.2   02 Aug 1995 10:01:54   sjo
// I needed to move the include of the class headers from just after the include
// of product.h, to just after the #define of the module name.
// 
//    Rev 1.1   20 Jul 1995 16:42:08   sjo
// Changes required for first wave of architecture work in the CF directories.
// 
//    Rev 1.0   16 Mar 1995 16:22:06   sbc
// Initial revision.
// 
//    Rev 1.0   14 Oct 1993 10:16:12   sjo
// Initial revision.
// ****************************************************************************
#include "product.h"
//
// Make a definition for this module.
//
#define _CFPREP_C_

#include "rrdoc.h"
#include "ctype.h"
#include "string.h"
#include "stdio.h"
#include "_cfcomp.h"
#include "_cfmisc.h"

int CRrComposite::lcontains(
					LPSTR	s,	/* string to scan */
					LPSTR	p,	/* substring to scan for */
					LPSTR   *qP) /* where to put ptr to found substring */
{
	int slen = lstrlen(s);
	int plen = lstrlen(p);
	int i, j;

	for (i=0; i<=(slen-plen); i++)
	{
		for (j=0; j<plen; j++)
		{
			if (s[i+j] != p[j]) break;
		}
		if (j==plen)
		{
			*qP = &s[i];
			return TRUE;
		}
	}
	return FALSE;
}

static int near outofstr(
					int off,
					int *offlist) /* list of string start/stop offsets */
{
	while (*offlist)
	{
		if (off>=*offlist && off<=*(offlist+1)) return FALSE; /* in string */
		offlist += 2;
	}
	return TRUE;
}

int CRrComposite::lcfprep(LPSTR input)
{
	// Rev 1.50
	if (input=='\0')
	{
		return FALSE;
	}
	LPSTR inp=cflex;
	LPSTR p=input;
	int i;
	char c,delimiter;
	int instring = FALSE;
	int skipone = FALSE;
	int slist[400];
	int cursent=0;

	while (c=*p)
	{ /* convert input string to upper case */
		if (instring)
		{
			if (c==delimiter)
			{
				instring = FALSE;
				slist[cursent++] = p-1-input; /* offset to last str char */
			}
		}
		else if (skipone)	  /* if preceded by exscape character */
		{
			skipone = FALSE;	/* just copy it to output */
		}
		else if (c=='\\')     /* if exscape character */
		{
			skipone = TRUE; 	/* copy it and next "as is" */
		}
		else if ((c==CSNGLQ) || (c==CDBLQ))
		{
			delimiter = c;
			instring = TRUE;
			slist[cursent++] = p+1-input; /* offset to first str char */
		}
		else if (c==CLBRAK)
		{
			delimiter = CRBRAK;
			instring = TRUE;
			slist[cursent++] = p+1-input; /* offset to first str char */
		}
		*inp = instring||skipone ? c : wtoupper(c);
		inp++;
		p++;
	}
	*inp = *p;	/* terminate upper case copy */
	slist[cursent] = 0; /* terminate offset list */

	if (instring) return ee_badstr; /* unterminated string */

	// Declare logicals here. There were static, but only used in this loop
	//
	LPSTR *logicals[] =
	{
		&lpszTAND, &lpszTOR, &lpszTNOT,
		&lpszTTRUE, &lpszTFALSE, NULL
	};

	for (i=0; logicals[i]; i++)
	{
		int off = lstrlen(*logicals[i])-1;

		p = cflex;
		while (lcontains(p,*logicals[i],&p))
		{
			if (::outofstr(p-cflex,slist)) *p = *(p+off) = CDOTREP;
			p += off+1;
		}
	}

#ifndef RSW
	/* replace -> with :: for token analyzer */
	p = cflex;
	while (lcontains(p,"->",&p))
	{
		if (::outofstr(p-cflex,slist)) *p = *(p+1) = ':';
		p += 2;
	}
#endif

	return FALSE;
}

