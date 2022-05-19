#include "stdafx.h"
#include "cfile64.h"
#include "stdio.h"

void main()
{
  //First check out the 64bit integer support functions
  UINT64 x = CFile64::MakeUnsignedInt64(0x12345678, 0x87654321);
  DWORD dwLow;
  DWORD dwHigh;
  CFile64::SplitUnsignedInt64(x, dwHigh, dwLow);
  VERIFY(dwLow = 0x87654321);
  VERIFY(dwHigh = 0x12345678);
  
  //now try the file class itself
  CFile64 infile;
  CString sFilename = infile.GetFileName();
  infile.SetFileName(_T("A dummy filename"));
  sFilename = infile.GetFileName();
  //DWORD dwType = infile.GetFileType();  //should assert if you uncomment
  //UINT64 nLength = infile.GetLength();  //should throw and exception if you uncomment
  VERIFY(infile.IsClosed());
  VERIFY(!infile.IsOpen());
  CFileException e;
  if (!infile.Open(_T("demo.txt"), GENERIC_READ, 0, OPEN_EXISTING, &e))
  {
    printf("Failed to open the file %s\n", e.m_strFileName);
    return;
  }
  HANDLE hFile = infile;
  VERIFY(infile.IsOpen());
  VERIFY(!infile.IsClosed());
  sFilename = infile.GetFileName();
  CFile64* pDupFile = infile.Duplicate();
  delete pDupFile;
  UINT64 nLength = infile.GetLength();
  UINT64 nPos = infile.GetPosition();
  BYTE* pData = new BYTE[1000];
  infile.Read(pData, 1000);
  infile.Seek(3000000000, CFile64::begin, TRUE);
  nPos = infile.GetPosition();
  infile.SeekToBegin();
  nPos = infile.GetPosition();
  infile.SeekToEnd();
  nPos = infile.GetPosition();
  infile.Seek(10, CFile64::begin, TRUE);
  nPos = infile.GetPosition();
  infile.Seek(10, CFile64::end, TRUE);
  nPos = infile.GetPosition();
  infile.Seek(20, CFile64::end, FALSE);
  nPos = infile.GetPosition();
  infile.Seek(20, CFile64::current, FALSE);
  nPos = infile.GetPosition();
  infile.Seek(20, CFile64::current, TRUE);
  nPos = infile.GetPosition();
  //infile.Flush();  //should assert if you uncomment as we only specified read access
  DWORD dwFileType = infile.GetFileType();
  infile.Close();
  hFile = infile;

  CFile64 outfile;
  if (!outfile.Open(_T("output.txt"), GENERIC_READ | GENERIC_WRITE, 0, OPEN_ALWAYS, &e))
  {
    printf("Failed to open the file %s\n", e.m_strFileName);
    return;
  }
  outfile.SeekToBegin();
  TCHAR c;
  for (int i=0; i<26; i++)
  {
    c = (TCHAR) (i+_T('A'));
    outfile.Write(&c, sizeof(TCHAR));
  }
  outfile.SetLength(100); 
  outfile.Seek(20, CFile64::begin, TRUE);
  outfile.Write(&c, 1);
  outfile.Abort();
}