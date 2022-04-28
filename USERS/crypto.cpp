// ****************************************************************************
//
//      (C) Copyright 1996 Concentric Data Systems, Inc.
//                      All Rights Reserved.
//
//
// Module $Workfile:   crypto.cpp  $
// ================
//
// Description:
// ============
//	Serial number encryption and validation routines.
//
// Modification History
// ====================
//
// Revision    Date        Time       Who
// ========    =========== ========   ===
// $Log:   H:/vcsmfc/users/crypto.cpv  $
// 
//    Rev 1.0   04 Apr 1996 14:20:34   smh
// Initial revision.
// 


// ****************************************************************************
// Define TESTMAIN to build stand-alone DOS test program from this source.  When including
// this source in an MFC program we want to include stdafx.h.  In a non-MFC program, we
// want to include windows.h.
#if defined(TESTMAIN)
	#include "windows.h"
#else
	#include "stdafx.h"		// just guessing this is for MFC program
#endif
	#include "stdio.h"		// for sprintf

/////////////////////////////////
// This code assumes serial numbers of the form WWWW-XXXX-YYYY-ZZZZ where:
//		WWWWXXXX is the 8-digit starting serial number
//		YYYY	 is the encrypted number of serial numbers
//		ZZZZ	 is the "check" string used to validate a user-entered serial number
// The API is:
	int EncodeNumber( int Serial, int Count, char* pResult );
//		to generate a valid serial number string from a starting serial
//		number and serial-number count.  The supplied serial number must be at most
//		8 decimal digits and the count at most 4 decimal digits.  The result buffer
//		must be at least 20 bytes long to allow for the 16 digits, 3 hyphens, and a null.
	int ComputeCount( char* pSerialNumberString );
//		to validate a supplied serial number of the form WWWW-XXXX-YYYY-ZZZZ
//		and to return the number of serial numbers implied by the supplied string.  A
//		return value of zero implies an invalid serial number string.

// The following prime numbers are used by both Encrypt() and ComputeCheck().
// The choice of these particular primes has no known signficance.
static int pPrimes[12] = { 1847, 1787, 1867, 1987,
						   1879, 1319, 1153, 1283,
						   1427, 1439, 1459, 1613 };

// Encrypt 4-character count string.
// This is called by EncodeNumber() to obscure the serial-number count.
void Encrypt(
 char* pCount,
 int Count,
 int Serial
)
{
	// Randomize count by mulitplying top 4 digits and bottom 4 digits of serial
	//  number each by a different prime and taking the bottom 4 digits of the result.
	Count += ( ( Serial % 10000 ) * pPrimes[1] ) + ( ( Serial / 10000 ) * pPrimes[0] );
	Count %= 10000;						// turn into 4 digits
	sprintf( pCount, "%04d", Count );	// convert to string
	return;
}

// Compute "check" string from 12-char serial number + count string
// This is called by both EncodeNumber() to create a "check" string
//  and by ComputeCount() to validate it.
void ComputeCheck(
 char* pNumber,		// input: serial number + count string
 char* pCheck		// output: check string
)
{
	int Sum = 0, ii;
	for ( ii = 0; ii < 12; ii++ )
	{
		Sum += ( pNumber[ii] - '0' ) * pPrimes[ii];
	}
	sprintf( pCheck, "%04d", Sum % 10000 );
}

// Encode serial number and count into 20-byte string of 4 4-byte segments,
//  separated by hyphens and terminated with a null byte.
// This is called by ComputeCount() and is also to be called directly when
//  generating valid serial numbers.
int EncodeNumber(
 int Serial,
 int Count,
 char* pResult		// must be at least 20 bytes long
)
{
	char pSnum[9];
	char pCount[5];
	char pNumber[13];
	char pCheck[5];
	if ( Serial > 99999999 || Count > 9999 )
	{
		return FALSE;
	}
	// Prepare string versions of serial number and count.
	sprintf( pSnum, "%08d", Serial );
	sprintf( pCount, "%04d", Count );
	// Encrypt count from count and serial number strings.  Leave result in count string.
	Encrypt( pCount, Count, Serial );
	// Prepare 12-digit string of serial number followed by encrypted count.
	strcpy( pNumber, pSnum );
	strcat( pNumber, pCount );
	// Compute last 4 digits, so-called "check" string
	ComputeCheck( pNumber, pCheck );
	// Add check string to 12-digit Serial+Count to make final 19-byte string with embedded hyphens.
	strcpy( pResult, pNumber );
	memmove( pResult + 5, pResult + 4, 8 );
	memmove( pResult + 10, pResult + 9, 4 );
	pResult[4] = pResult[9] = pResult[14] = '-';
	pResult[15] = 0;
	strcat( pResult, pCheck );
	return TRUE;
}

// Performs validity checks on serial number and decrypts and returns serial-number count.
// A return value of zero implies an invalid serial number.
int ComputeCount(
 char* pNumString	// 20-byte serial number string to validate.
)
{
	// First validate form of numeric string.
	int ii;
	if ( strlen( pNumString ) != 19 )	// String must be of the form WWWW-XXXX-YYYY-ZZZZ.
	{
		return 0;
	}
	char pNumCopy[20];
	strcpy( pNumCopy, pNumString );
	for ( ii = 0; ii < 19; ii++ )
	{
		char Chr = pNumCopy[ii];
		if ( ( ii % 5 ) != 4 )
		{
			if ( !isdigit( Chr ) )
			{
				return 0;
			}
		}
		else	// every 5th digit should be a hyphen
		{
			if ( Chr != '-' )
			{
				return 0;
			}
			pNumCopy[ii] = 0;	// split number into 4-digit parts in copy
		}
	}
	char pSnum[13];
	strcpy( pSnum, pNumCopy );				// copy WWWW
	strcpy( pSnum + 4, pNumCopy + 5 );		// append XXXX
	int SerialNumber = atoi( pSnum );		// convert to integer
	strcpy( pSnum + 8, pNumCopy + 10 );		// append YYYY
	char pResult[20];
	ComputeCheck( pSnum, pResult );			// compute ZZZZ
	if ( strcmp( pResult, pNumCopy + 15 ) )	// compare computed ZZZZ to passed ZZZZ
	{
		return 0;							// different "check" string
	}
	EncodeNumber( SerialNumber, 0, pResult );	// Encode serial number with 0 count. (WWWW-XXXX-yyyy-zzzz)
	pResult[14] = 0;
	int Count = atoi( pResult + 10 );			// Convert yyyy to integer.
	int PassedCount = atoi( pNumCopy + 10 );	// Convert YYYY to integer.
	Count = 10000 + PassedCount - Count;
	Count %= 10000;
	return Count;
}

#if defined(TESTMAIN)
//////////////////
// From here down is test program.
// Everything else is required both in product and in serial number generator.

int ElementCompare( const void* elem1, const void* elem2 )
{
	const char* p1 = (*(const char**)elem1) + 15;
	const char* p2 = (*(const char**)elem2) + 15;
	int res = strcmp( p1, p2 );
	if ( !res )		// if duplicate "check" string, sort on whole string
	{
		res = strcmp( *(const char**)elem1, *(const char**)elem2 );
	}
	return res;
}

int main( int argc, char** argv )
{

	if ( argc > 1 )
	{
		if ( argc > 4 )
		{
			printf( "usage: <starting number> [ <count> [ <N-pack size> ] ]\n" );
			return 1;
		}
		char FileName[20];
		sprintf( FileName, "%s.lst", argv[1] );	// generate output file name
		OFSTRUCT ofs;
		HFILE hFile = OpenFile( FileName, &ofs, OF_CREATE | OF_WRITE | OF_SHARE_EXCLUSIVE );
		if ( hFile == HFILE_ERROR )
		{
			printf( "Error creating %s", FileName );
			return 1;
		}
		int StartNumber = atoi( argv[1] );
		int Count = 1;
		int NPackSize = 1;
		if ( argc > 2 )
		{
			Count = atoi( argv[2] );
			if ( Count == 0 || Count > 100000 )
			{
				printf( "Maximum count is 100000\n" );
				printf( "usage: <starting number> [ <count> [ <N-pack size> ] ]\n" );
				return 1;
			}
		}
		if ( argc > 3 )
		{
			NPackSize = atoi( argv[3] );
			if ( NPackSize == 0 || NPackSize > 9999 )
			{
				printf( "Maximum N-Pack size is 9999\n" );
				printf( "usage: <starting number> [ <count> [ <N-pack size> ] ]\n" );
				return 1;
			}
		}
		int ii, jj;
		int Number = StartNumber;
		char Buffer[20];
		for ( ii = 0; ii < Count; ii++ )
		{
			EncodeNumber( Number, NPackSize, Buffer );
			if ( ( jj = ComputeCount( Buffer ) ) != NPackSize )
			{
				printf( "Error generating code for %d, %d\n", Number, NPackSize );
				return 1;
			}
	//		printf( "%s\n", Buffer );
			unsigned long Written;
			if ( !WriteFile( (HANDLE)hFile, Buffer, strlen( Buffer ), &Written, NULL )
			  || !WriteFile( (HANDLE)hFile, "\r\n", 2, &Written, NULL ) )
			{
				printf( "Error writing to output file\n" );
				return 1;
			}
			Number += NPackSize;
		}
		printf( "Wrote %d serial numbers starting at %d to %s\n", Count, StartNumber, FileName );
		printf( "Next available serial number in this sequence is %d\n", Number );
		_lclose( hFile );
		return 0;
	}
	else
	{
		printf( "usage: <starting number> [ <count> [ <N-pack size> ] ]\n" );
		
	  return 1;
		
		const int ARRAYSIZE = 100000;
		
		#define COUNT 1
		//#define COUNT 5
		//#define COUNT (ii % 10000)
		
		int ii;
		char* Array[ARRAYSIZE];
		for ( ii = 0; ii < ARRAYSIZE; ii++ )
		{
			char* pResult = (char*)HeapAlloc( GetProcessHeap(), 0, 20 );
			EncodeNumber( ii+543210, COUNT, pResult );
			Array[ii] = pResult;
			int Count = ComputeCount( pResult );
			if ( Count != COUNT )
			{
				printf( "Validation error on %s\n", pResult );
			}
	//		printf( "%s\n", Array[ii] );
		}
		qsort( Array, ARRAYSIZE, sizeof(char*), ElementCompare );
		int jj = 0;
		char pLastCheck[5];
		strcpy( pLastCheck, "" );
		for ( ii = 0; ii < ARRAYSIZE; ii++ )
		{
			if ( strcmp( pLastCheck, Array[ii] + 15 ) )		// did check string change?
			{
				int CmpRes = atoi( pLastCheck );
				if ( CmpRes % 20 )
				{
					printf( " %2d", jj );
				}
				else
				{
					printf( "\n%s: %2d", pLastCheck, jj );
				}
				jj = 1;
				strcpy( pLastCheck, Array[ii] + 15 );
			}
			else
			{
				jj++;
			}
			//printf( "%s\n", Array[ii] );
			HeapFree( GetProcessHeap(), 0, Array[ii] );
		}
		printf( " %2d", jj );		// print last count!
		return 0;
	}
}
#endif
